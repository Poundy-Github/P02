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
**  Name:               SWC_CHIME_PROCESS.c
**
**  Description:        Chime process file
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
#include "string.h"
#include "Rte_Common_Normal.h"
#include "Rte_type.h"
#include "SWC_WN_Config.h"
#include "logger.h"

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Chime_Process.h"
#include "SWC_Chime_App.h"
#include "SWC_Chime_Adapt.h"
#include "SWC_Chime_Queue.h"
#include "Vconfig_Cfg.h"
#include "IPC_ClusterApp.h"


/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/
/**********************************************************************************************************
* Parament                                                                                                *
**********************************************************************************************************/
//#define CHIME_PROCESS_TEST
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_CHIME_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Chime_MemMap.h"
//static uint8 ChimeAppConfigFlag_u8;

#define SWC_CHIME_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Chime_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_CHIME_START_SEC_CODE
#include "SWC_Chime_MemMap.h"
static void SWC_ChimeWarningCancelCheck(void);

static void SWC_ChimePasCheck(void);
static void SWC_ChimePasCancel(void);
static void SWC_ChimePasCase1Check(uint8 *msg_u8,uint8 *sts_u8);
static void SWC_ChimePasCase1Cancel(void);
static void SWC_ChimePasCase2Check(uint8 *msg_u8,uint8 *sts_u8);
static void SWC_ChimePasCase2Cancel(void);
static void SWC_ChimePasCase3Check(uint8 *msg_u8,uint8 *sts_u8);
static void SWC_ChimePasCase3Cancel(void);
static void SWC_ChimePasCase4Check(uint8 *msg_u8,uint8 *sts_u8);
static void SWC_ChimePasCase4Cancel(void);
static void SWC_ChimePasCase5Check(uint8 *msg_u8,uint8 *sts_u8);
static void SWC_ChimePasCase5Cancel(void);
static void SWC_ChimePasCase1FDCheck(uint8 *msg_u8,uint8 *sts_u8);
static void SWC_ChimePasCase1FDCancel(void);
static void SWC_ChimePasCase2FDCheck(uint8 *msg_u8,uint8 *sts_u8);
static void SWC_ChimePasCase2FDCancel(void);
static void SWC_ChimePasCase3FDCheck(uint8 *msg_u8,uint8 *sts_u8);
static void SWC_ChimePasCase3FDCancel(void);
static void SWC_ChimeRSDSCheck(void);
static void SWC_ChimeRSDSCancel(void);
static void SWC_ChimeLWD_LKACheck(void);
static void SWC_ChimeLWD_LKACancel(void);
static void SWC_ChimeCDPCheck(void);
static void SWC_ChimeCDPCancel(void);
static void SWC_ChimeTSRCheck(void);
static void SWC_ChimeTSRCancel(void);
static void SWC_ChimeFELDCheck(void);
static void SWC_ChimeFELDCancel(void);
static void SWC_ChimeRELDCheck(void);
static void SWC_ChimeRELDCancel(void);
static void SWC_ChimeHVolDoorEVCheck(void);
static void SWC_ChimeHVolDoorEVCancel(void);
static void SWC_ChimeHVolDoorPHEVCheck(void);
static void SWC_ChimeHVolDoorPHEVCancel(void);
static void SWC_ChimeHVolDoorRE300Check(void);
static void SWC_ChimeHVolDoorRE300Cancel(void);

static void SWC_ChimePandCheckD7DCTCheck(void);
static void SWC_ChimePandCheckD7DCTCancel(void);
static void SWC_ChimePandCheckD9DCTCheck(void);
static void SWC_ChimePandCheckD9DCTCancel(void);
static void SWC_ChimePandCheckD8ATCheck(void);
static void SWC_ChimePandCheckD8ATCancel(void);
static void SWC_ChimePandCheckDPHEVCheck(void);
static void SWC_ChimePandCheckDPHEVCancel(void);
static void SWC_ChimePandCheckDEVCheck(void);
static void SWC_ChimePandCheckDEVCancel(void);
static void SWC_ChimeACC_TJA_ICACheck(void);
static void SWC_ChimeACC_TJA_ICACancel(void);
static void SWC_ChimePowerBatWarmCheck(void);
static void SWC_ChimePowerBatWarmCancel(void);
static void SWC_ChimeLDWLKAELKLCKCheck(void);
static void SWC_ChimeLDWLKAELKLCKCancel(void);
static void SWC_ChimeSleepCheck(void);
static void SWC_ChimeSleepCancel(void);

//add by xu 2021/6/2 R10 new Requirements 
static void SWC_ChimeDWDCheck(void);
static void SWC_ChimeDWDCancel(void);

//add by R14 new Requirements
static void SWC_ChimeChargeFaultCheck(void);
static void SWC_ChimeChargeFaultCancel(void);

//add by wuyaoyao 2022/2/14
static void SWC_ChimeCELDCheck(void);
static void SWC_ChimeCELDCancel(void);


//LED process
static void SWC_ChimeTPMSLEDCheck(uint8 Ledsts);
static void SWC_ChimeHybridPowerSystemLEDCheck(uint8 Ledsts);
static void SWC_ChimeHybridPowerSystemRedLEDCheck(uint8 Ledsts);
static void SWC_ChimeSeltbeltLEDCheck(uint8 Ledsts);
static void SWC_ChimeTickTockLEDCheck(void);
static void SWC_ChimeTickTockLEDCancel(void);
static void SWC_ChimeOverspeedLEDCheck(uint8 Ledsts);
static void SWC_ChimeCCOLEDCheck(uint8 Ledsts);
static void SWC_ChimeTABLEDCheck(uint8 Ledsts);
static void SWC_ChimeREADYLEDCheck(uint8 Ledsts);

/**warning change ****************************************************************************************/
static void SWC_ChimeDoorOpenCheck(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeRainDoorOpenCheck(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeOverspeedIndia80Check(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeOverspeedIndia120Check(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeOverspeedCheck(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_LeaveCar4Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_StopCar4Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_SteeringActRe(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_AutoSteeringActRe(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_AutoBrakePersonRe(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_AutoBrakeCarRe(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_AuxiliaryBrakeRe(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_CrossSideBrakeRe(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_RSideBrakeRe(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_TakeBrakeAcc4Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_TakeBrakeFCWRe(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_TakeBrakeFCrossRe(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_TakeSteering1Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_TakeSteering2Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_TakeSteering3Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_TakeSteering4Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_KeepDistance(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_TakeCar1Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_TakeCar2Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_TakeCar4Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_AssistExit4Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_KeepPoint1Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_KeepPoint2Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_KeepPoint4Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_CheckP0_5Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_LcdAlarmOnce(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_LcdAlarmThree(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_LcdAlarmTenTimes(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_LightOn0_5Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_TunnelTakeCarOnce(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_RoadTakeCarOnce(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_ModeFailOnce(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_RCarSpeedHigh1Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_4LModeOnce(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_PowerOnOnce(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_PleaseRestOnce(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_PleaseRest1Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_VehicleDevRepeate(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_AccCruiseFailOnce(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_AccCruiseQuitOnce(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_SmartCruiseFailOnce(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_SmartCruisQuitOnce(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_AccCruiseOkkeepAtOnce(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_SmartCruiseOkhwOnce(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_FCOKOnce(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_FCOKAttRoadEnvOnce(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_FCOKKeepAtOnce(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_FCOKTakeCarOnce(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_HcExitTakeDirOnce(uint8 flag,uint8 enable,uint16 bit);

//add by xu wei cheng 2021/6/21
static void SWC_ChimeReq_CarDistance(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_PeopleRight(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_PeopleMid(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_PeopleLeft(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_FaceCar(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_SideCarTwoSide(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_SideCarRight(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_SideCarLeft(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_FrontCarAEB(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_FrontCarUnContron(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_BackCarUnContron(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_AroundCarUnContron(uint8 flag,uint8 enable,uint16 bit);

//add by Wangtingting 2021/7/14

static void SWC_ChimeReq_PlsTakeOver_4Hz(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_PlsTakeOver_2Hz(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_PlsTakeOver(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_CarAutoBrakePlsTake(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_CarParkingPlsTake(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_CarUrgeBrakePlsTake(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_MoveRampFailPlsTake(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_MoveMainFailPlsTake_4Hz(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_MoveMainFailPlsTake_2Hz(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_MoveMainFailPlsTake(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_TurnFailPlsTake_4Hz(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_TurnFailPlsTake_2Hz(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_TurnFailPlsTake(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_TollGateFailPlsTake_4Hz(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_TollGateFailPlsTake_2Hz(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_TollGateFailPlsTake(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_RoundaboutFailPlsTake_4Hz(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_RoundaboutFailPlsTake_2Hz(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_RoundaboutFailPlsTake(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_UrgeTurnPlsHoldWhee(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_MoveRampFailHandWheel_2Hz(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_MoveRampFailHandWheel(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_MoveMainFailHandWheel(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_TurnFailPlsHandWheel(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_TollGateFailPlsHandWheel(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_RoundaboutFailPlsHandWheel(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_NOHExitPlsTake(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_NOGIsActivated(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_EnvNotSup(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_KeepFocusTryAgain(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_PlsHandWheelTryAgain(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_Plsfastenseatbelt(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_PlsShutTheDoor(uint8 flag,uint8 enable,uint16 bit);
static void ChimeReq_fsatenPassSeatbelt(uint8 flag,uint8 enable,uint16 bit);

//add by Wuyaoyao 2022/2/17
static void SWC_ChimeReq_PowerOffAfterThreeMinute(uint8 flag,uint8 enable,uint16 bit);
static void SWC_ChimeReq_StatBattLowComfortOff(uint8 flag,uint8 enable,uint16 bit);

//add bg xu  2022/3/26 R19
static void SWC_ChimeReq_SmartCruiseExit(uint8 flag,uint8 enable,uint16 bit);


//Tab request process
static void Chime_RequestFlag(uint16 Idx_u16);
static void Chime_RequestFlagRepeat(uint16 Idx_u16);
static void Chime_CancelFlag(uint16 Idx_u16);
//static void Chime_CancelWithField(uint16 Idx_u16);
static void Chime_ClearField(uint16 Idx_u16);
static uint16 Chime_CheckFlag(uint16 Idx_u16);
static void Chime_RequestChimeProcess(void);
#define SWC_CHIME_STOP_SEC_CODE
#include "SWC_Chime_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_CHIME_START_SEC_CONST_UNSPECIFIED
#include "SWC_Chime_MemMap.h"
static const s_ChimeWarningReqTbl_t ChimeWrningCancelTbl[e_WarnReq_MaxNumber]=
{
	e_WarnReq_LeaveCar4Hz,					WN_enDrvAwayCar,					ChimeReq_LeaveCar4Hz,
	e_WarnReq_StopCar4Hz,					WN_enDrvAwayCarStop,				ChimeReq_StopCar4Hz,
	e_WarnReq_SteeringActRe,				WN_enIFCESSTrig,					ChimeReq_SteeringActRe,
	e_WarnReq_AutoSteeringActRe,			WN_enIFCAESTrig,					ChimeReq_AutoSteeringActRe,
	e_WarnReq_AutoBrakePersonRe,			WN_enAEBTrigP,						ChimeReq_AutoBrakePersonRe,
	e_WarnReq_AutoBrakeCarRe,				WN_enAEBTrigV,						ChimeReq_AutoBrakeCarRe,
	e_WarnReq_AuxiliaryBrakeRe,				WN_enIASTrigV,						ChimeReq_AuxiliaryBrakeRe,
	e_WarnReq_CrossSideBrakeRe,				WN_enFCTABrakeActive,				ChimeReq_CrossSideBrakeRe,
	e_WarnReq_RSideBrakeRe,					WN_enRSDSRLBStart,					ChimeReq_RSideBrakeRe,
	e_WarnReq_TakeBrakeAcc4Hz,				WN_enACCTakeOverBrake,				ChimeReq_TakeBrakeAcc4Hz,
	e_WarnReq_TakeBrakeFCWRe,				WN_enAEBFCWWarning,					ChimeReq_TakeBrakeFCWRe,
	e_WarnReq_TakeBrakeFCrossRe,			WN_enFCTABrakePlease,				ChimeReq_TakeBrakeFCrossRe,
	e_WarnReq_TakeSteering2Hz,				WN_enIFCHoldWheel_2Hz,				ChimeReq_TakeSteering2Hz,
	e_WarnReq_TakeSteering3Hz,				WN_enIFCHoldWheel_3Hz,				ChimeReq_TakeSteering3Hz,
	e_WarnReq_TakeSteering4Hz,				WN_enIFCHoldWheel_4Hz,				ChimeReq_TakeSteering4Hz,
	e_WarnReq_TakeCar2Hz,					WN_enACCHWATakeOver_2Hz,			ChimeReq_TakeCar2Hz,
	e_WarnReq_TakeCar4Hz,					WN_enACCHWATakeOver_4Hz,			ChimeReq_TakeCar4Hz,
	e_WarnReq_AssistExit4Hz,				WN_enIFCTakeOver,					ChimeReq_AssistExit4Hz,
	e_WarnReq_KeepPoint2Hz,					WN_enACCHWATakeAtte_2Hz,			ChimeReq_KeepPoint2Hz,
	e_WarnReq_KeepPoint4Hz,					WN_enACCHWATakeAtte_4Hz,			ChimeReq_KeepPoint4Hz,
	e_WarnReq_CheckP0_5Hz,					WN_enGearPSelect,					ChimeReq_CheckP0_5Hz,
	//Importantalarm		
	e_WarnReq_ChimeDoorOpenCheck,			WN_enLFDoorOpen,					SWC_ChimeDoorOpenCheck,
	e_WarnReq_LightOn0_5Hz,					WN_enPositionLampOn,				ChimeReq_LightOn0_5Hz,
	e_WarnReq_ChimeOverspeedIndia80Check,	WN_enOverSpeedLevel_1,				SWC_ChimeOverspeedIndia80Check,
	e_WarnReq_ChimeOverspeedIndia120Check,	WN_enOverSpeedLevel_2,				SWC_ChimeOverspeedIndia120Check,
	e_WarnReq_VehicleDevRepeate,			WN_enPlsCtrlWheel,					ChimeReq_VehicleDevRepeate,
	e_WarnReq_UrgeTurnPlsHoldWheel,			WN_enUrgeTurnPlsHoldWheel,			ChimeReq_UrgeTurnPlsHoldWhee,
	e_WarnReq_MoveRampFailHandWheel_2Hz,	WN_enMoveRampFailHandWheel_2Hz,		ChimeReq_MoveRampFailHandWheel_2Hz,
	e_WarnReq_MoveRampFailHandWheel,		WN_enMoveRampFailHandWheel,			ChimeReq_MoveRampFailHandWheel,
	e_WarnReq_MoveMainFailHandWheel,		WN_enMoveMainFailHandWheel,			ChimeReq_MoveMainFailHandWheel,
	e_WarnReq_TurnFailPlsHandWheel,			WN_enTurnFailPlsHandWheel,			ChimeReq_TurnFailPlsHandWheel,
	e_WarnReq_TollGateFailPlsHandWheel,		WN_enTollGateFailPlsHandWheel,		ChimeReq_TollGateFailPlsHandWheel,
	e_WarnReq_RoundaboutFailPlsHandWheel,	WN_enRoundaboutFailPlsHandWheel,	ChimeReq_RoundaboutFailPlsHandWheel,	
	e_WarnReq_LcdAlarmTenTimes, 			WN_enElecSteerUnlockFail,			ChimeReq_LcdAlarmTenTimes,
	e_WarnReq_ChimeRainDoorOverspeedCheck,	WN_enRainDoorOpen,					SWC_ChimeRainDoorOpenCheck,
	e_WarnReq_ChimeCarDistance,				WN_enV2XCarDistance,				SWC_ChimeReq_CarDistance,
	e_WarnReq_ChimePeopleRight,				WN_enV2XPeopleRight,				SWC_ChimeReq_PeopleRight,
	e_WarnReq_ChimePeopleMid,				WN_enV2XPeopleMid,					SWC_ChimeReq_PeopleMid,
	e_WarnReq_ChimePeopleLeft,				WN_enV2XPeopleLeft,					SWC_ChimeReq_PeopleLeft,
	e_WarnReq_ChimeFaceCar,					WN_enV2XFaceCar,					SWC_ChimeReq_FaceCar,
	e_WarnReq_ChimeSideCarTwoSide,			WN_enV2XSideCarTwoSide,				SWC_ChimeReq_SideCarTwoSide,
	e_WarnReq_ChimeSideCarRight,			WN_enV2XSideCarRight,				SWC_ChimeReq_SideCarRight,
	e_WarnReq_ChimeSideCarLeft,				WN_enV2XSideCarLeft,				SWC_ChimeReq_SideCarLeft,
	e_WarnReq_ChimeFrontCarAEB,				WN_enV2XFrontCarAEB,				SWC_ChimeReq_FrontCarAEB,
	e_WarnReq_ChimeFrontCarUnContron,		WN_enV2XFrontCarUnContron,			SWC_ChimeReq_FrontCarUnContron,
	e_WarnReq_ChimeBackCarUnContron,		WN_enV2XBackCarUnContron,			SWC_ChimeReq_BackCarUnContron,
	e_WarnReq_ChimeAroundCarUnContron,		WN_enV2XAroundCarUnContron,			SWC_ChimeReq_AroundCarUnContron,
	e_WarnReq_ChimePlsTakeOver4Hz,			WN_enPlsTakeOver_4Hz,				SWC_ChimeReq_PlsTakeOver_4Hz,
	e_WarnReq_ChimePlsTakeOver2Hz,			WN_enPlsTakeOver_2Hz,				SWC_ChimeReq_PlsTakeOver_2Hz,
	e_WarnReq_ChimePlsTakeOver1Hz,			WN_enPlsTakeOver,					SWC_ChimeReq_PlsTakeOver,
	e_WarnReq_ChimeCarAutoBrakePlsTake,		WN_enCarAutoBrakePlsTake,			SWC_ChimeReq_CarAutoBrakePlsTake,
	e_WarnReq_ChimeCarParkingPlsTake,		WN_enCarParkingPlsTake,				SWC_ChimeReq_CarParkingPlsTake,
	e_WarnReq_ChimeCarUrgeBrakePlsTake,		WN_enCarUrgeBrakePlsTake,			SWC_ChimeReq_CarUrgeBrakePlsTake,
	e_WarnReq_ChimeMoveRampFailPlsTake,		WN_enMoveRampFailPlsTake,			SWC_ChimeReq_MoveRampFailPlsTake,
	e_WarnReq_ChimeMoveMainFailPlsTake4Hz,	WN_enMoveMainFailPlsTake_4Hz,		SWC_ChimeReq_MoveMainFailPlsTake_4Hz,
	e_WarnReq_ChimeMoveMainFailPlsTake2Hz,	WN_enMoveMainFailPlsTake_2Hz,		SWC_ChimeReq_MoveMainFailPlsTake_2Hz,
	e_WarnReq_ChimeMoveMainFailPlsTake1Hz,	WN_enMoveMainFailPlsTake,			SWC_ChimeReq_MoveMainFailPlsTake,
	e_WarnReq_ChimeTurnFailPlsTake4Hz,		WN_enTurnFailPlsTake_4Hz,			SWC_ChimeReq_TurnFailPlsTake_4Hz,
	e_WarnReq_ChimeTurnFailPlsTake2Hz,		WN_enTurnFailPlsTake_2Hz,			SWC_ChimeReq_TurnFailPlsTake_2Hz,
	e_WarnReq_ChimeTurnFailPlsTake1Hz,		WN_enTurnFailPlsTake,				SWC_ChimeReq_TurnFailPlsTake,
	e_WarnReq_ChimeTollGateFailPlsTake4Hz,	WN_enTollGateFailPlsTake_4Hz,		SWC_ChimeReq_TollGateFailPlsTake_4Hz,
	e_WarnReq_ChimeTollGateFailPlsTake2Hz,	WN_enTollGateFailPlsTake_2Hz,		SWC_ChimeReq_TollGateFailPlsTake_2Hz,
	e_WarnReq_ChimeTollGateFailPlsTake1Hz,	WN_enTollGateFailPlsTake,			SWC_ChimeReq_TollGateFailPlsTake,
	e_WarnReq_ChimeRoundaboutFailPlsTake4Hz,WN_enRoundaboutFailPlsTake_4Hz,		SWC_ChimeReq_RoundaboutFailPlsTake_4Hz,
	e_WarnReq_ChimeRoundaboutFailPlsTake2Hz,WN_enRoundaboutFailPlsTake_2Hz,		SWC_ChimeReq_RoundaboutFailPlsTake_2Hz,
	e_WarnReq_ChimeRoundaboutFailPlsTake1Hz,WN_enRoundaboutFailPlsTake,			SWC_ChimeReq_RoundaboutFailPlsTake,
	e_WarnReq_ChimePowerOffAfterThreeMinute,WN_enPowerOffAfterThreeMinute,		SWC_ChimeReq_PowerOffAfterThreeMinute,
	e_WarnReq_ChimeStatBattLowComfortOff,	WN_enStatBattLowComfortOff,			SWC_ChimeReq_StatBattLowComfortOff,
	e_WarnReq_ChimeSmartCruiseExit,			WN_enSmartCruiseouteEmergencyBrake, SWC_ChimeReq_SmartCruiseExit,

	e_WarnReq_ChimeOverspeedCheck,			WN_enWARNING_TOTAL_NUMBER,			SWC_ChimeOverspeedCheck,
	e_WarnReq_RCarSpeedHigh1Hz, 			WN_enWARNING_TOTAL_NUMBER,			ChimeReq_RCarSpeedHigh1Hz,
	e_WarnReq_PleaseRest1Hz,				WN_enWARNING_TOTAL_NUMBER,			ChimeReq_PleaseRest1Hz,
	e_WarnReq_TakeSteering1Hz,				WN_enWARNING_TOTAL_NUMBER,			ChimeReq_TakeSteering1Hz,
	e_WarnReq_TakeCar1Hz,					WN_enWARNING_TOTAL_NUMBER,			ChimeReq_TakeCar1Hz,
	e_WarnReq_KeepPoint1Hz,					WN_enWARNING_TOTAL_NUMBER,			ChimeReq_KeepPoint1Hz,
	e_WarnReq_KeepDistance,					WN_enWARNING_TOTAL_NUMBER,			ChimeReq_KeepDistance,
	e_WarnReq_LcdAlarmThree,				WN_enWARNING_TOTAL_NUMBER,			ChimeReq_LcdAlarmThree,
	e_WarnReq_LcdAlarmOnce,					WN_enWARNING_TOTAL_NUMBER,			ChimeReq_LcdAlarmOnce,
	e_WarnReq_TunnelTakeCarOnce,			WN_enWARNING_TOTAL_NUMBER,			ChimeReq_TunnelTakeCarOnce,
	e_WarnReq_RoadTakeCarOnce,				WN_enWARNING_TOTAL_NUMBER,			ChimeReq_RoadTakeCarOnce,
	e_WarnReq_ModeFailOnce,					WN_enWARNING_TOTAL_NUMBER,			ChimeReq_ModeFailOnce,
	e_WarnReq_HcExitTakeDirOnce,			WN_enWARNING_TOTAL_NUMBER,			ChimeReq_HcExitTakeDirOnce,
	e_WarnReq_ChimeNOHExitPlsTake,			WN_enWARNING_TOTAL_NUMBER,			ChimeReq_NOHExitPlsTake,
	e_WarnReq_PowerOnOnce,					WN_enWARNING_TOTAL_NUMBER,			ChimeReq_PowerOnOnce,
	e_WarnReq_4LModeOnce,					WN_enWARNING_TOTAL_NUMBER,			ChimeReq_4LModeOnce,
	e_WarnReq_PleaseRestOnce,				WN_enWARNING_TOTAL_NUMBER,			ChimeReq_PleaseRestOnce,
	
	
	//Adas warning,display middle
	e_WarnReq_AccCruiseFailOnce,			WN_enWARNING_TOTAL_NUMBER,			ChimeReq_AccCruiseFailOnce,
	e_WarnReq_AccCruiseQuitOnce,			WN_enWARNING_TOTAL_NUMBER,			ChimeReq_AccCruiseQuitOnce,
	e_WarnReq_SmartCruiseFailOnce,			WN_enWARNING_TOTAL_NUMBER,			ChimeReq_SmartCruiseFailOnce,
	e_WarnReq_SmartCruisQuitOnce,			WN_enWARNING_TOTAL_NUMBER,			ChimeReq_SmartCruisQuitOnce,
	e_WarnReq_AccCruiseOkkeepAtOnce,		WN_enWARNING_TOTAL_NUMBER,			ChimeReq_AccCruiseOkkeepAtOnce,
	e_WarnReq_SmartCruiseOkhwOnce,			WN_enWARNING_TOTAL_NUMBER,			ChimeReq_SmartCruiseOkhwOnce,
	e_WarnReq_FCOKOnce,						WN_enWARNING_TOTAL_NUMBER,			ChimeReq_FCOKOnce,
	e_WarnReq_FCOKAttRoadEnvOnce,			WN_enWARNING_TOTAL_NUMBER,			ChimeReq_FCOKAttRoadEnvOnce,
	e_WarnReq_FCOKKeepAtOnce,				WN_enWARNING_TOTAL_NUMBER,			ChimeReq_FCOKKeepAtOnce,
	e_WarnReq_FCOKTakeCarOnce,				WN_enWARNING_TOTAL_NUMBER,			ChimeReq_FCOKTakeCarOnce,
	e_WarnReq_NOHIsActivated,				WN_enWARNING_TOTAL_NUMBER,			ChimeReq_NOGIsActivated,
	e_WarnReq_EnvNotSup,					WN_enWARNING_TOTAL_NUMBER,			ChimeReq_EnvNotSup,
	e_WarnReq_KeepFocusTryAgain,			WN_enWARNING_TOTAL_NUMBER,			ChimeReq_KeepFocusTryAgain,
	e_WarnReq_PlsHandsWheelTryAgain,		WN_enWARNING_TOTAL_NUMBER,			ChimeReq_PlsHandWheelTryAgain,
	e_WarnReq_Plsfastenseatbelt,			WN_enWARNING_TOTAL_NUMBER,			ChimeReq_Plsfastenseatbelt,
	e_WarnReq_PlsShutTheDoor,				WN_enWARNING_TOTAL_NUMBER,			ChimeReq_PlsShutTheDoor,
	e_WarnReq_PlsfastenPassSeatbelt,		WN_enWARNING_TOTAL_NUMBER,			ChimeReq_fsatenPassSeatbelt,
	
};

static const s_ChimeWrnProcess_t ChimeWrn2ChimeTbl[] =
{
#if 1
	/*WN_socDrvAwayCar,                    1.147 危险！请立即远离车辆！                                          */e_WarnReq_LeaveCar4Hz,
	/*WN_socDrvAwayCarStop,                1.147 危险！请安全停车并立即远离车辆！                                     */e_WarnReq_StopCar4Hz,
	/*WN_socIFCESSTrig,                    1.213 ESS紧急转向避让辅助功能激活    No signal                         */e_WarnReq_SteeringActRe,	
	/*WN_socIFCAESTrig,                    1.212 AES自动紧急转向避让辅助功能激活   No signal                     	*/e_WarnReq_AutoSteeringActRe,
	/*WN_socAEBTrigP,                      1.187 针对行人的自动紧急制动启动                                        */e_WarnReq_AutoBrakePersonRe,
	/*WN_socAEBTrigV,                      1.186 针对车辆的自动紧急制动启动                                        */e_WarnReq_AutoBrakeCarRe,	
	/*WN_socIASTrigV,                      1.188 交叉路口辅助制动启动(针对车辆)                                     */e_WarnReq_AuxiliaryBrakeRe,	
	/*WN_socFCTABrakeActive,               1.190 前横穿侧向制动启动    No signal                               */e_WarnReq_CrossSideBrakeRe,	
	/*WN_socRSDSRLBStart,                  1.196 倒车侧向制动启动                                             */e_WarnReq_RSideBrakeRe,		
	/*WN_socACCTakeOverBrake,              1.198 触发ACC接管请求---请制动                                      */e_WarnReq_TakeBrakeAcc4Hz,	
	/*WN_socAEBFCWWarning,                 1.184 前碰撞预警---请制动                                          */e_WarnReq_TakeBrakeFCWRe,	
	/*WN_socFCTABrakePlease,               1.189 前横穿侧向警告功能-请制动   No signal                            */e_WarnReq_TakeBrakeFCrossRe,
	/*WN_socIFCHoldWheel_1Hz,              1.210 请手握方向盘1hz                                            */e_WarnReq_TakeSteering1Hz,
	/*WN_socIFCHoldWheel_2Hz,              1.210 请手握方向盘2hz                                            */e_WarnReq_TakeSteering2Hz,
	/*WN_socIFCHoldWheel_3Hz,              1.210 请手握方向盘3hz                                            */e_WarnReq_TakeSteering3Hz,
	/*WN_socIFCHoldWheel_4Hz,              1.210 请手握方向盘4hz                                            */e_WarnReq_TakeSteering4Hz,
	/*WN_socAEBSafeDistance,               1.185 请保持安全距离                                              */e_WarnReq_KeepDistance,
	/*WN_socACCHWATakeOver,                1.205 高速公路辅助系统-请接管车辆     No signal                         */e_WarnReq_TakeCar1Hz,
	/*WN_socACCHWATakeOver_2Hz,            1.205 高速公路辅助系统-请接管车辆2Hz提示音     No signal   	            */e_WarnReq_TakeCar2Hz,
	/*WN_socACCHWATakeOver_4Hz,            1.205 高速公路辅助系统-请接管车辆4Hz提示音     No signal       	        */e_WarnReq_TakeCar4Hz,
	/*WN_socIFCTakeOver,                   1.210 车道辅助系统退出，请接管车辆                         	            */e_WarnReq_AssistExit4Hz,
	/*WN_socACCHWATakeAtte,                1.205 高速公路辅助系统-请保持注意力    No signal          		        */e_WarnReq_KeepPoint1Hz,
	/*WN_socACCHWATakeAtte_2Hz,            1.205 高速公路辅助系统-请保持注意力2hz   No signal            			*/e_WarnReq_KeepPoint2Hz,
	/*WN_socACCHWATakeAtte_4Hz,            1.205 高速公路辅助系统-请保持注意力4hz   No signal            	        */e_WarnReq_KeepPoint4Hz,
	/*WN_socGearPSelect,                   1.71  请选择P挡(8AT)   No signal                               */e_WarnReq_CheckP0_5Hz,
	/*                                                                                                  */
	/*Important alarm                                                                                 */
	/*WN_socLFDoorOpen,                    1.17/1.18  左前门开报警                                          */e_WarnReq_ChimeDoorOpenCheck,
	/*WN_socRFDoorOpen,                    1.17/1.18  右前门开报警                                          */e_WarnReq_ChimeDoorOpenCheck,
	/*WN_socLRDoorOpen,                    1.17/1.18  左后门开报警                                          */e_WarnReq_ChimeDoorOpenCheck,
	/*WN_socRRDoorOpen,                    1.17 1.18  右后门开报警                                          */e_WarnReq_ChimeDoorOpenCheck,
	/*WN_socTrunkOpen,                     1.17 1.18  后备箱开报警                                          */e_WarnReq_ChimeDoorOpenCheck,
	/*WN_socHoodOpen,                      1.17 1.18  发动机盖开报警                                         */e_WarnReq_ChimeDoorOpenCheck,
	/*WN_socFirRowLSeatBelt,               1.44  第一排左安全带报警提示                                          */e_WarnReq_ChimeDoorOpenCheck,
	/*WN_socFirRowRSeatBelt,               1.44  第一排右安全带报警提示                                          */e_WarnReq_ChimeDoorOpenCheck,
	/*WN_socSecRowLSeatBelt,               1.44  第二排左安全带报警提示                                          */e_WarnReq_ChimeDoorOpenCheck,
	/*WN_socSecRowMSeatBelt,               1.44  第二排中安全带报警提示                                          */e_WarnReq_ChimeDoorOpenCheck,
	/*WN_socSecRowRSeatBelt,               1.44  第二排右安全带报警提示                                          */e_WarnReq_ChimeDoorOpenCheck,
	/*WN_socBrakeSysFault,                 1.12/1.13/1.14    制动系统故障                                   */e_WarnReq_LcdAlarmOnce,
	/*WN_socDynSysFault,                   1.160 动力系统严重故障     No signal                               */e_WarnReq_LcdAlarmOnce,
	/*WN_socCCOTargetSpeed0,               1.145 CCO目标车速2.6km/h                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socCCOTargetSpeed1,               1.145 CCO目标车速3.6km/h                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socCCOTargetSpeed2,               1.145 CCO目标车速4.6km/h                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socCCOTargetSpeed3,               1.145 CCO目标车速5.6km/h                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socCCOTargetSpeed4,               1.145 CCO目标车速6.6km/h                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socCCOTargetSpeed5,               1.145 CCO目标车速7.6km/h                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socCCOTargetSpeed6,               1.145 CCO目标车速8.6km/h                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socCCOTargetSpeed7,               1.145 CCO目标车速9.6km/h                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socCCOTargetSpeed8,               1.145 CCO目标车速10.6km/h                                      */e_WarnReq_LcdAlarmOnce,
	/*WN_socSlowTargetSpeed0,              1.216 蠕行目标车速一段                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socSlowTargetSpeed1,              1.216 蠕行目标车速二段                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socSlowTargetSpeed2,              1.216 蠕行目标车速三段                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socSlowTargetSpeed3,              1.216 蠕行目标车速四段                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socSlowTargetSpeed4,              1.216 蠕行目标车速五段                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socSlowTargetSpeed5,              1.216 蠕行目标车速六段                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socSlowTargetSpeed6,              1.216 蠕行目标车速七段                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socSlowTargetSpeed7,              1.216 蠕行目标车速八段                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socSlowTargetSpeed8,              1.216 蠕行目标车速九段                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socIFCESSFault,                   1.213 紧急转向避让辅助功能故障     No signal                           */e_WarnReq_LcdAlarmOnce,
	/*WN_socFLTirePressWarning,            1.33  左前胎压过低报警                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socFRTirePressWarning,            1.33  右前胎压过低报警                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socRLTirePressWarning,            1.33  左后胎压过低报警                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socRRTirePressWarning,            1.33  右后胎压过低报警                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socFLTireTempWarning,             1.34  左前胎温过高报警                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socFRTireTempWarning,             1.34  右前胎温过高报警                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socRLTireTempWarning,             1.34  左后胎温过高报警                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socRRTireTempWarning,             1.34  右后胎温过高报警                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_soc4WDSystemFault,                1.72  四驱系统故障                                               */e_WarnReq_LcdAlarmOnce,
	/*WN_soc4WDSystemHeat,                 1.73  四驱系统过热                                               */e_WarnReq_LcdAlarmOnce,
	/*WN_socHybSysFault_Stop,              1.100 混合动力系统故障，请安全停车                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socHybSysUnavailable,             1.101 车辆发生碰撞，混合动力系统不可用                                     */e_WarnReq_LcdAlarmOnce,
	/*WN_socCharging,                      1.186 充电中 TBD 已删除                                          */e_WarnReq_MaxNumber,
	/*WN_socChargeWait,                    1.186 待充电 TBD 已删除                                          */e_WarnReq_MaxNumber,
	/*WN_socChargeComplete,                1.186 充电完成 TBD 已删除                                         */e_WarnReq_MaxNumber,
	/*WN_socChargeStop,                    1.186 充电停止 TBD 已删除                                         */e_WarnReq_MaxNumber,
	/*WN_socDynBattSysFault_Stop,          1.102 动力电池系统故障，请安全停车                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socDynBattSysFault_Repair,        1.102 动力电池系统故障，请及时到4S店维修                                   */e_WarnReq_LcdAlarmOnce,
	/*WN_socIFCAESFault,                   1.212 自动紧急转向避让功能不可用    No signal                           */e_WarnReq_LcdAlarmOnce,
	/*WN_socTransWarnStopCar,              1.45  变速器过热,请安全停车                                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socPowerSysFault,                 1.68  动力系统故障  (8AT)   No signal                            */e_WarnReq_LcdAlarmOnce,
	/*WN_socTransFault,                    1.48/1.49/1.50/1.51  变速器故障                                 */e_WarnReq_LcdAlarmOnce,
	/*WN_socTransPutInPFailed,             1.52/1.53  变速器未能成功挂入P挡                                     */e_WarnReq_LcdAlarmOnce,
	/*WN_socLowOilPressure,                1.7   机油压力不足                                               */e_WarnReq_LcdAlarmOnce,
	/*WN_socEngWaterTempHigh,              1.2   发动机水温过高                                              */e_WarnReq_LcdAlarmOnce,
	/*WN_socTransWarning,                  1.45/1.46/1.47    变速器过热                                    */e_WarnReq_LcdAlarmOnce,
	/*WN_socDrvSysFault_Repair,            1.99  驱动系统故障 请及时到4S店维修                                     */e_WarnReq_LcdAlarmOnce,
	/*WN_socHybSysFault_Repair,            1.96  混合动力系统故障，请及时到4S店维修                                   */e_WarnReq_LcdAlarmOnce,
	/*WN_socStartingSysFault,              1.93  起动系统故障，请及时到4S店维修                                     */e_WarnReq_LcdAlarmOnce,
	/*WN_socHybSysLimited,                 1.97  混合动力系统功率暂时受限，请小心驾驶                                   */e_WarnReq_LcdAlarmOnce,
	/*WN_socRecoverySysFault,              1.98  能量回收系统故障，请及时到4S店维修                                   */e_WarnReq_LcdAlarmOnce,
	/*WN_socChargerFault,                  1.91  充电机故障，请及时到4S店维修                                      */e_WarnReq_LcdAlarmOnce,
	/*WN_socChargeSysFault,                1.92  充电系统故障，充电停止                                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socChargerTempHigh,               1.86  充电机温度过高，充电停止                                         */e_WarnReq_LcdAlarmOnce,
	/*WN_socDynBattTempHigh,               1.87  动力电池温度过高，充电停止                                        */e_WarnReq_LcdAlarmOnce,
	/*WN_socChargerPWReduced,              1.89  充电机输出功率降低                                            */e_WarnReq_LcdAlarmOnce,
	/*WN_socFCTAUnavai,                    1.194 前向横穿辅助功能不可用                                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socLockFailureN,                  1.63  变速器在N档，车辆无法锁止                                        */e_WarnReq_LcdAlarmOnce,
	/*WN_socNoticeGearN,                   1.66  请注意变速器在N挡(8AT)                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socPositionLampOn,                1.21 1.22  灯光未关提示                                          */e_WarnReq_LightOn0_5Hz,
	/*WN_socRSDSTrailer,                   1.195 拖车模式 侧后辅助系统停用                                        */e_WarnReq_LcdAlarmOnce,
	/*WN_socAEBFCWTrailer,                 1.192 拖车模式 前向辅助系统停用                                        */e_WarnReq_LcdAlarmOnce,
	/*WN_socACCHWACrossTunnel,             1.204 高速公路辅助系统-前方即将穿过隧道，请及时接管车辆   No s         */e_WarnReq_TunnelTakeCarOnce,
	/*WN_socACCHWABranchRoad,              1.204 高速公路辅助系统-前方存在分岔路口，请求及时接管车辆     No       */e_WarnReq_RoadTakeCarOnce,
	/*WN_socChargeDevConnectErr,           1.90  充电装置连接不正确，充电停止                                      */e_WarnReq_LcdAlarmOnce,
	/*WN_socDynBattTempLow,                1.88  动力电池温度过低，充电停止                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socChargePortWarning,             1.85  充电口输入功率不足，充电停止                                      */e_WarnReq_LcdAlarmOnce,
	/*WN_socIFCSCalibrating,               1.209 智能前视系统传感器标定中                                        */e_WarnReq_LcdAlarmOnce,
	/*WN_socTransAuthenFailed,             1.48 1.108 防盗认证失败                                         */e_WarnReq_LcdAlarmOnce,
	/*WN_socTransLimited,                  1.48 1.49 1.50    变速器功能受限                                 */e_WarnReq_LcdAlarmOnce,
	/*WN_socTransReleasePFailed,           1.52  变速器无法解除P挡                                           */e_WarnReq_LcdAlarmOnce,
	/*WN_socElecSteerUnlockFail,           1.43  电子转向锁解锁失败，请转动方向盘                                    */e_WarnReq_LcdAlarmTenTimes,
	/*WN_socEngPumpFault,                  1.148 发动机主水泵故障，请尽快维修                                      */e_WarnReq_LcdAlarmOnce,
	/*WN_socAGSFault,                      1.165 主动格栅故障   No signal                                  */e_WarnReq_LcdAlarmOnce,
	/*WN_socChargeDevDisconnect,           1.81  请断开充电装置                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socChargeDevConnect,              1.90  请连接充电装置                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socDynBattLow,                    1.78/1.79  动力电池电量低，请及时充电                                  */e_WarnReq_LcdAlarmOnce,
	/*WN_socGearChngP,                     1.82  请将挡位置于P挡                                            */e_WarnReq_LcdAlarmOnce,
	/*WN_socGearPNeedStop,                 1.69  P挡时车辆需静止 (8AT)                                      */e_WarnReq_LcdAlarmOnce,
	/*WN_socHighBeamSysFault,              1.131/1.132/1.133 前照灯故障                                   */e_WarnReq_LcdAlarmOnce,
	/*WN_socGearPNotSuitable,              1.70  车速较高不适合挂入P挡(8AT)                                    */e_WarnReq_LcdAlarmOnce,
	/*WN_socLimpModeGearD,                 1.64  变速器D挡跛行模式(8AT)   No signal                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socLimpModeGearP,                 1.65  变速器P挡跛行模式(8AT)   No signal                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socReadyNoRefuel,                 1.149 车辆已上上电，禁止加油   No signal                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socFuelPrepare,                   1.178 加油准备中                                               */e_WarnReq_LcdAlarmOnce,
	/*WN_socRaceLaunchActive,              1.111 弹射起步激活                                              */e_WarnReq_LcdAlarmOnce,
	/*WN_socRaceModeActive,                1.112 弹射模式激活                                              */e_WarnReq_LcdAlarmOnce,
	/*WN_socRaceLaunchTimeout,             1.111 超时保护                                                */e_WarnReq_LcdAlarmOnce,
	/*WN_socChargingNoRefuel,              1.149 充电装置已连接，禁止加油     No signal                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socFuelTankSysFault,              1.110 油箱系统故障，请维修                                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socFuelTankCapOn,                 1.141 油箱盖未关闭                                              */e_WarnReq_LcdAlarmOnce,
	/*WN_socGPFRegenerating,               1.118 颗粒捕集器正在再生                                           */e_WarnReq_LcdAlarmOnce,
	/*WN_socGPFRegenerate,                 1.118 颗粒捕集器需要再生                                           */e_WarnReq_LcdAlarmOnce,
	/*WN_socRearAxleSysFault,              1.99  后桥系统故障，请及时到4S店维修                                    */e_WarnReq_LcdAlarmOnce,
	/*WN_socFrontAxleSysFault,             1.94  前桥系统故障，请及时到4S店维修                                    */e_WarnReq_LcdAlarmOnce,
	/*WN_socDoNotStepAcAndBr,              1.107 请勿同时踩下加速与刹车踏板                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socElecShifterFault,              1.67  电子换挡器故障 (8AT)    No signal                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socStatBattLowTranMode,           1.8   运输模式                                                */e_WarnReq_LcdAlarmOnce,
	/*WN_socStatBattLowComfortOff,         1.8   12V电源系统故障，舒适功能关闭                                    */e_WarnReq_ChimeStatBattLowComfortOff,
	/*WN_soc12VFaultStop,                  1.151 12V电源系统故障，请安全停车                                     */e_WarnReq_LcdAlarmOnce,
	/*WN_soc12VFaultRepair,                1.151 12V电源系统故障，请及时到4S店维修                                 */e_WarnReq_LcdAlarmOnce,
	/*WN_socStatBattLowSavingMode,         1.8   电量消耗过多，进入省电模式                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socStatBattLowStartUp,            1.8   12V蓄电池电量低，请启动车辆                                     */e_WarnReq_LcdAlarmOnce,
	/*WN_socModeSwitchFailed,              1.139 模式切换失败，请熄火重试                                        */e_WarnReq_ModeFailOnce,
	/*WN_socRefuelingNoCharge,             1.150 正在加油，禁止充电                                           */e_WarnReq_LcdAlarmOnce,
	/*WN_socShiftGearBrakeAndKey,          1.56  换挡请踩刹车并按下解锁键                                        */e_WarnReq_LcdAlarmOnce,
	/*WN_socShiftGearStepBrake,            1.59  换挡请踩刹车                                              */e_WarnReq_LcdAlarmOnce,
	/*WN_socShiftGearPressKey,             1.56  换挡请按下解锁键     No signal                              */e_WarnReq_LcdAlarmOnce,
	/*WN_socShiftNotAllowed,               1.60/1.61 车速过高无法切换挡位                                      */e_WarnReq_LcdAlarmOnce,
	/*WN_socShiftPStop,                    1.60  请在车辆静止时挂入P档                                         */e_WarnReq_LcdAlarmOnce,
	/*WN_socDMSTakeRest_1,                 TBD   请注意休息，取自DMS模块                                       */e_WarnReq_MaxNumber,
	/*WN_socDMSTakeRest_2,                 TBD   请注意休息，取自DMS模块                                       */e_WarnReq_MaxNumber,
	/*WN_socDMSTakeRest_3,                 TBD   请注意休息，取自DMS模块                                       */e_WarnReq_MaxNumber,
	/*WN_socDMSTakeAttention,              TBD   请专心驾驶                                               */e_WarnReq_MaxNumber,
	/*WN_socPPMIFault,                     1.166 主动式安全带故障     No signal                              */e_WarnReq_LcdAlarmOnce,
	/*WN_socSidePPMIErr,                   1.238 副驾主动式安全带故障                                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socBSGSysFault,                   1.95  BSG系统故障，请及时到4S店维修                                   */e_WarnReq_LcdAlarmOnce,
    /*WN_socPlsStartSelfClean,             1.234 请原地开启排气自洁                                           */e_WarnReq_LcdAlarmOnce,
    /*WN_socPlsStartCarSlowly,             1.234 请启动车辆并怠速                                            */e_WarnReq_LcdAlarmOnce,
    /*WN_socDPFCleaning,                   1.234 颗粒捕集器正在自洁                                           */e_WarnReq_LcdAlarmOnce,
    /*WN_socSelfCleanComplete,             1.234 自洁完成感谢等待                                            */e_WarnReq_LcdAlarmOnce,
	/*WN_socGearChngPN,                    1.83  请将挡位置于P挡或N挡   No signal                             */e_WarnReq_LcdAlarmOnce,
    /*WN_socRainDoorOpen,                  1.241 防雨篷车门未关闭                                            */e_WarnReq_ChimeRainDoorOverspeedCheck,
	/*WN_socHeatingPlugIn,                 1.152 动力电池温度低，请插枪加热                                       */e_WarnReq_LcdAlarmOnce,
    /*WN_socUreaLow,                       1.241 尿素液位低，请加注                                           */e_WarnReq_LcdAlarmOnce,
    /*WN_socUreaVeryLow,                   1.241 尿素液位极低，请加注                                          */e_WarnReq_LcdAlarmOnce,
    /*WN_socUreaTankEmpty,                 1.241 尿素罐空，禁止下次启动                                         */e_WarnReq_LcdAlarmOnce,
    /*WN_socUreaUnqualifyPlsCheck,         1.241 尿素不合格，请检查                                           */e_WarnReq_LcdAlarmOnce,
    /*WN_socUreaUnqualifyOver50km,         1.241 尿素不合格 行驶超过50km                                      */e_WarnReq_LcdAlarmOnce,
    /*WN_socUreaFillStopPlsReFill,         1.241 尿素加注中止 请重新加注                                        */e_WarnReq_LcdAlarmOnce,
    /*WN_socUreaFillStopOver50km,          1.241 尿素加注中止 行驶超过50km                                     */e_WarnReq_LcdAlarmOnce,
    /*WN_socUreaSysDisableEng,             1.241 尿素系统禁止发动机启动                                         */e_WarnReq_LcdAlarmOnce,
    /*WN_socUreaSysErrPlsCheck,            1.241 尿素系统故障，请入站检查                                        */e_WarnReq_LcdAlarmOnce,
    /*WN_socUreaSysErrOver50km,            1.241 尿素系统故障，行驶超过50km                                     */e_WarnReq_LcdAlarmOnce,
    /*WN_socUreaSysErrRestartErr,          1.241 尿素系统故障，禁止下次启动                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socDM_ENS_EV,                     1.109 发动机需要启动, EV模式                                       */e_WarnReq_LcdAlarmOnce,
    /*WN_socFrontTireAlignFinish,          1.235 前轮回正完成                                              */e_WarnReq_MaxNumber,
    /*WN_socFrontTireTurnRight,            1.235 前轮未回正 请右打方向盘                                        */e_WarnReq_MaxNumber,
    /*WN_socFrontTireTurnLeft,             1.235 前轮未回正 请左打方向盘                                        */e_WarnReq_MaxNumber,
    /*WN_socRayAntiVirusWarn,              1.243 请在车内无人状态下开启紫外线消毒杀菌功能                                */e_WarnReq_LcdAlarmOnce,
	/*WN_socDrvConcentrate,                1.169 危险 请专心驾驶                                            */e_WarnReq_MaxNumber,
	/*WN_socDrvDrowsy,                     1.170 危险 请勿疲劳驾驶                                           */e_WarnReq_MaxNumber,
	/*WN_socCantDriveBatt,                 1.152 电池温度低，车辆无法行驶                                        */e_WarnReq_LcdAlarmOnce,
	/*WN_socDischargingV2L,                1.167 连接成功，正在放电中+V2L   No signal                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socDischargingV2V,                1.167 连接成功，正在放电中+V2V   No signal                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socEngVinMismatch,                1.182 发动机与仪表VIN未匹配                                        */e_WarnReq_LcdAlarmOnce,
	/*WN_socORExperMode,                   1.140 越野专家模式                                              */e_WarnReq_MaxNumber,
	/*WN_socChargeHeating,                 1.214 1.214 动力电池预热中                                       */e_WarnReq_MaxNumber,
	/*WN_socHSMLimitPlsSwiEV,              1.228 储氢系统受限，请切换为电动模式                                     */e_WarnReq_LcdAlarmOnce,
	/*WN_socHSMErrPlsSwiEVAndStop,         1.228 储氢系统故障，请切换为电动模式并安全停车                                */e_WarnReq_LcdAlarmOnce,
	/*WN_socHSMErrStop,                    1.228 储氢系统故障，请安全停车                                        */e_WarnReq_LcdAlarmThree,
	/*WN_socBattSysErrPlsFix,              1.229 燃料电池系统故障，请到4S店维修                                    */e_WarnReq_LcdAlarmThree,
	/*WN_socBattSysErrPlsFix_1,            1.229 燃料电池系统故障，请到4S店维修                                    */e_WarnReq_LcdAlarmOnce,
	/*WN_socHSErrPlsFix,                   1.230 氢气系统故障，请到4S店维修                                      */e_WarnReq_LcdAlarmOnce,
	/*WN_socHSLeakPlsFix,                  1.230 氢气泄漏，请到4S店维修                                        */e_WarnReq_LcdAlarmOnce,
	/*WN_socHSLeakPlsSwiEV,                1.231 氢气泄漏，请切换为电动模式                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socHSLeakPlsSwiEVStop,            1.231 氢气泄漏，请切换为电动模式并安全停车                                  */e_WarnReq_LcdAlarmOnce,
	/*WN_socHSLeakStop,                    1.231 氢气泄漏，请安全停车，并远离车辆                                    */e_WarnReq_LcdAlarmThree,
	/*WN_socDeionizerErrPlsFix,            1.232 冷却液离子浓度过高，请到4S店维修                                   */e_WarnReq_LcdAlarmOnce,
	/*WN_socWPCTakePhone,                  1.144 请带好手机                                               */e_WarnReq_LcdAlarmOnce,
	/*WN_socARHUDFault,                    1.217 抬头显示故障                                              */e_WarnReq_LcdAlarmOnce,
	/*WN_socARHUDOverheat,                 1.217 抬头显示过温保护无法显示                                        */e_WarnReq_LcdAlarmOnce,
	/*WN_socSRaceLaunchActive,             1.111 超级弹射起步激活                                            */e_WarnReq_LcdAlarmOnce,
    /*WN_socBattLowSRaceLaunUnAvail,       1.111 动力电池可用功率低，超级弹射不可用； 普通弹射激活                    	   */e_WarnReq_LcdAlarmOnce,
    /*WN_socTransHeatSLaunchUnAvail,       1.111 变速器温度高，超级弹射不可用；普通弹射激活                               */e_WarnReq_LcdAlarmOnce,
    /*WN_socSRaceLaunchOverLimit,          1.111 超级弹射使用次数达到上限，普通弹射激活                                 */e_WarnReq_LcdAlarmOnce,
    /*WN_socBattTempLowCantStart,          1.152 动力电池温度过低，车辆无法启动                                     */e_WarnReq_LcdAlarmOnce,
    /*WN_socBattTempLowPowerDown,          1.221 动力电池温度低，动力降低                                        */e_WarnReq_LcdAlarmOnce,
    /*WN_socBattTempHighPowerDown,         1.221 动力电池温度高，动力降低                                        */e_WarnReq_LcdAlarmOnce,
    /*WN_socPlsPrsBrktoWait,               1.52 请踩下制动踏板，待P挡自学习完成后松开                                  */e_WarnReq_LcdAlarmOnce,
    /*WN_socSelfLearnNotComplete,          1.52 自学习未完成，待自学习完成后换挡                                     */e_WarnReq_LcdAlarmOnce,
    /*WN_socLearnSuccessPlsRelBrk,         1.52 P挡自学习完成，请松开制动踏板                                      */e_WarnReq_LcdAlarmOnce,
	/*WN_socPowerLowEVUnvil,               1.109 动力电池可用功率低，EV模式不可用                                   */e_WarnReq_LcdAlarmOnce,
	/*WN_socPlsCtrlWheel,                  1.210 车辆偏离，请控制方向盘                                         */e_WarnReq_VehicleDevRepeate,
	/*WN_socRearAxSysErr4WDUnvil,          1.109 后桥系统故障，四驱模式不可用                                      */e_WarnReq_LcdAlarmOnce,

	/*                                                                                                 */
	/*//Secondary alarm                                                                                */
	/*WN_socPEPSPowerFault,                1.41  PEPS电源继电器故障                                         */e_WarnReq_LcdAlarmOnce,
	/*WN_socOverSpeedLevel_1,              1.16  车速一级警报                                              */e_WarnReq_ChimeOverspeedIndia80Check,
	/*WN_socOverSpeedLevel_2,              1.16  车速二级警报                                              */e_WarnReq_ChimeOverspeedIndia120Check,
	/*WN_socOverSpeedSetting,              1.62  车速警报手动可调                                            */e_WarnReq_ChimeOverspeedCheck,
	/*WN_socLicPlateLampFault,             1.25 1.26  牌照灯故障                                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socRvsLampFault,                  1.27 1.28  倒车灯故障                                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socRearPosnLampFault,             1.29  后位灯故障                                               */e_WarnReq_LcdAlarmOnce,
	/*WN_socLasHdLightFault,               1.120 激光辅助远光光源故障                                		   */e_WarnReq_LcdAlarmOnce,
	/*WN_socIFCSDectectLimited,            1.208 智能前视系统传感器探测受限                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socACCSensorDetectLimited,        1.191 前向辅助系统传感器探测受限                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socFCTSDectectLimit,              1.193 前角雷达传感器探测受限                                         */e_WarnReq_LcdAlarmOnce,
	/*WN_socIFCLKAFunLimited,              1.207 紧急车道保持功能受限                                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socCommunicationFault,            1.104 通信故障，请小心驾驶                                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socACCHWAFuncFault,               1.206 变道辅助功能故障                                            */e_WarnReq_LcdAlarmOnce,
	/*WN_socRSDSRCWWarning,                1.197 后方车辆车速过高                                            */e_WarnReq_RCarSpeedHigh1Hz,
	/*WN_socBeepSysFault,                  1.103 声音提示系统错误                                            */e_WarnReq_LcdAlarmOnce,
	/*WN_socBrakeLampFault,                1.23/1.24  制动灯故障                                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socRearFogLampFault,              1.19/1.20  后雾灯故障                                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socRainLightFault,                1.31  雨量光线传感器故障                                           */e_WarnReq_LcdAlarmOnce,
	/*WN_socAFSSystemFault,                1.129  AFS系统故障                                            */e_WarnReq_LcdAlarmOnce,
	/*WN_socACCUnavailable,                1.201 智能巡航辅助不可用                                           */e_WarnReq_LcdAlarmOnce,
	/*WN_socACCCruiseFunFault,             1.199 自适应巡航功能不可用                                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socAEBESPOff,                     1.183 ESP关闭 前向辅助系统已停用                                     */e_WarnReq_LcdAlarmOnce,
	/*WN_socTrafficSignFault,              1.211 交通标志信息功能故障                                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socStatBattLowPwrReduce,          1.8   12V蓄电池电量低，舒适功能降功率                                   */e_WarnReq_MaxNumber,
	/*WN_socALSSysFault,                   1.127 ALS系统故障                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socORCruiseLimited,               TBD   越野巡航功能受限                                            */e_WarnReq_MaxNumber,
    /*WN_socTurnAssistLimited,             TBD   转向辅助功能受限                                            */e_WarnReq_LcdAlarmOnce,
	/*WN_socHDCLimited,                    1.9  陡坡缓降功能受限                                     		   */e_WarnReq_MaxNumber,
	/*WN_socAutoholdLimited,               1.10  自动驻车功能受限                                            */e_WarnReq_MaxNumber,
	/*WN_socWPCChargeZone,                 1.143 请确认手机充电区域是否有异物或者偏离                                  */e_WarnReq_LcdAlarmOnce,
	/*WN_socPHLFault,                      1.124 像素大灯故障   No signal                                  */e_WarnReq_LcdAlarmOnce,
	/*WN_socPHLCameraFault,                1.125 像素大灯摄像头故障    No signal                              */e_WarnReq_LcdAlarmOnce,
	/*WN_soc4LModeSlow,                    1.136 4L模式请减速慢行  No signal                                */e_WarnReq_4LModeOnce,
	/*WN_soc4WDSystemDemotion,             1.146 四驱系统功能降级    No signal                               */e_WarnReq_LcdAlarmOnce,
	/*WN_soc4HModeSlow,                    1.136 4L模式请减速慢行  No signal                                */e_WarnReq_LcdAlarmOnce,
	/*WN_socVSGFault,                      1.154 VSG故障  No signal                                    */e_WarnReq_LcdAlarmOnce,
	/*WN_socDynBattCutOff,                 1.155 动力蓄电池已切断    No signal                               */e_WarnReq_LcdAlarmOnce,
	/*WN_socElecMachiFault,                1.156 电机故障    No signal                                   */e_WarnReq_LcdAlarmOnce,
	/*WN_socDCDCFault,                     1.157 DC/DC故障  No signal                                  */e_WarnReq_LcdAlarmOnce,
	/*WN_socEParkFault,                    1.159 E-Park故障    No signal                               */e_WarnReq_LcdAlarmOnce,
	/*WN_socRemoveChargeGun,               1.160 请移除充电枪                                              */e_WarnReq_LcdAlarmOnce,
	/*WN_socRemoveDischrgGun,              1.160 请移除充放电枪                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socShifterFault,                  1.160 换挡器故障                                               */e_WarnReq_LcdAlarmOnce,
	/*WN_socShiftNotAllowEV,               1.62  车速过高无法切换挡位（EV）                                      */e_WarnReq_LcdAlarmOnce,
	/*WN_socShiftPFault,                   1.160 P挡故障                                                */e_WarnReq_LcdAlarmOnce,
	/*WN_socShiftPStopEV,                  1.160 请在车辆静止时挂入P挡（EV）  No signal                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socChargingShift,                 1.160 车辆充电中无法换挡  No signal                                */e_WarnReq_LcdAlarmOnce,
	/*WN_socStepBrakeOutP,                 1.160 请踩制动切出P挡  No signal                                 */e_WarnReq_LcdAlarmOnce,
	/*WN_socStepBrakeOutN,                 1.160 请踩制动切出N挡  No signal                                 */e_WarnReq_LcdAlarmOnce,
	/*WN_socLVBattFault,                   1.160 小蓄电池故障  No signal                                   */e_WarnReq_LcdAlarmOnce,
	/*WN_socHVBattSport,                   1.160 动力电池电量低，运动模式不可用  No signal                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socHVBattAir,                     1.160 动力电池电量低，空调功能受限  No signal                           */e_WarnReq_LcdAlarmOnce,
	/*WN_socECOValue,                      1.160 已到ECO模式极限值    No signal                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socPedalLimit,                    1.160 电量高，单踏板功能受限  No signal                              */e_WarnReq_LcdAlarmOnce,
	/*WN_socUnidentifyBatt,                1.160 无法识别电池包，请检查  No signal                              */e_WarnReq_LcdAlarmOnce,
	/*WN_socHeatManagerFault,              1.161 电池包温控系统，请尽快检修  No signal                            */e_WarnReq_LcdAlarmOnce,
	/*WN_socFarBeamFault,                  1.122 超远辅助远光故障    No signal                               */e_WarnReq_LcdAlarmOnce,
	/*WN_socDynBattFault,                  1.158 动力电池故障  No signal                                   */e_WarnReq_LcdAlarmOnce,
	/*WN_socTboxErr,                       1.179 请更换紧急呼叫系统备用电池  No signal                            */e_WarnReq_LcdAlarmOnce,
    /*WN_socDynBattLowEV,                  1.78  动力电池电量低                                             */e_WarnReq_LcdAlarmOnce,
    /*WN_socSuspensionLimit,               1.237 悬架阻尼功能受限                                            */e_WarnReq_MaxNumber,
	/*Tips                                                                                             */
	/*WN_socPowerOnGearDrive,              1.105 1.106 已上电可挂挡行驶  No signal                           */e_WarnReq_PowerOnOnce,
	/*WN_socFuelStart,                     1.178 可以开始加油                                              */e_WarnReq_MaxNumber,
	/*WN_socKeyInCarOrNot,                 1.36  请确认钥匙是否在车内                                          */e_WarnReq_MaxNumber,
	/*WN_socACCISLCruiseSpeed,             1.203 按cruise键确认自动调整车速                                    */e_WarnReq_LcdAlarmOnce,
	/*WN_socStepBrakeStartGearPN,          1.37 踩下刹车+一键启动 请挂P挡或N挡                                    */e_WarnReq_MaxNumber,
	/*WN_socStepClutchStartGearNull,       1.38 踩下离合+ 一键启动 请挂空档                                      */e_WarnReq_MaxNumber,
	/*WN_socStepBrakeStartGearNull,        1.40 踩下刹车+一键启动 请挂空挡                                       */e_WarnReq_MaxNumber,
	/*WN_socACCISLSlowDown,                1.203 速度过高请主动减速                                           */e_WarnReq_LcdAlarmOnce,
	/*WN_socTargetCruiseSpeed,             1.3 1.4 1.5   定速巡航                                        */e_WarnReq_MaxNumber,
	/*WN_socLasHdLightOn,                  1.121 激光辅助远光开启                                            */e_WarnReq_MaxNumber,
	/*WN_socLasHdLightOff,                 1.121 激光辅助远光关闭                                            */e_WarnReq_MaxNumber,
	/*WN_socParkLampOn,                    1.30  驻车灯已开启                                              */e_WarnReq_LcdAlarmOnce,
	/*WN_socDrowsyDrvWarning,              1.32  疲劳驾驶预警                                              */e_WarnReq_PleaseRestOnce,
	/*WN_socDrowsyDrvWarning_1Hz,          1.32  疲劳驾驶预警1hz                                           */e_WarnReq_PleaseRest1Hz,
	/*WN_socTakeTheKeyTip,                 1.35  请带好钥匙提示                                       	   */e_WarnReq_LcdAlarmOnce,
	/*WN_socFuelLowWarn,                   1.74  请添加燃油                                               */e_WarnReq_LcdAlarmOnce,
	/*WN_socAFSDrivingMode,                1.130 AFS临时行驶模式  No signal                                */e_WarnReq_LcdAlarmOnce,
	/*WN_socALSDrivingSide,                1.128 ALS临时行驶模式  No signal                                */e_WarnReq_LcdAlarmOnce,
	/*WN_socMaintainPlease,                TBD   请保养汽车 已删除                                           */e_WarnReq_LcdAlarmOnce,
	/*WN_socMaintainNext,                  TBD   距下次保养XXkm 已删除                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socReleaseElecParkCCO,            1.77  请释放电子驻车                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socPleaseSlowDown,                1.77  请减速                                                 */e_WarnReq_LcdAlarmOnce,
	/*WN_soc4LModeStop,                    1.173 为完成4L模式切换，请停车  No signal                            */e_WarnReq_LcdAlarmOnce,
	/*WN_socPleaseGearN,                   1.174 请挂N挡  No signal                                     */e_WarnReq_LcdAlarmOnce,
	/*WN_soc4LModeEx,                      1.175 请退出4L模式  No signal                                  */e_WarnReq_LcdAlarmOnce,
	/*WN_soc4LModeSelect,                  1.177 请选择4L  No signal                                    */e_WarnReq_LcdAlarmOnce,
	/*WN_soc4HModeSelect,                  1.177 请选择4H  No signal                                    */e_WarnReq_LcdAlarmOnce,
	/*WN_soc4LModeEn,                      1.176 请进入4L模式  No signal                                  */e_WarnReq_LcdAlarmOnce,
	/*WN_socORCruiseActive,                1.75 请激活越野巡航功能  No signal                                 */e_WarnReq_LcdAlarmOnce,
	/*WN_socDM_B30_Standard,               1.113 标准模式                                                */e_WarnReq_MaxNumber,
	/*WN_socDM_B30_Sport,                  1.113 运动模式                                                */e_WarnReq_MaxNumber,
	/*WN_socDM_B30_Snow,                   1.113 雪地模式                                                */e_WarnReq_MaxNumber,
	/*WN_socDM_B30_Muddy,                  1.113 泥地模式                                                */e_WarnReq_MaxNumber,
	/*WN_socDM_B30_Sand,                   1.113 沙地模式                                                */e_WarnReq_MaxNumber,
	/*WN_socDM_B30_4L,                     1.113 4L模式                                                */e_WarnReq_MaxNumber,
	/*WN_socDM_B30_ECO,                    1.113 经济模式                                                */e_WarnReq_MaxNumber,
	/*WN_socDM_B30_IMC,                    1.113 智能模式                                                */e_WarnReq_MaxNumber,
	/*WN_socDM_B30_SportPlus,              1.113 超级运动模式                                              */e_WarnReq_MaxNumber,
	/*WN_socDM_B30_OffRoad,                1.113 越野模式                                                */e_WarnReq_MaxNumber,
	/*WN_socDM_B30_Expert,                 1.113 专家模式                                                */e_WarnReq_MaxNumber,
	/*WN_socDM_B30_Rock,                   1.113 岩石模式                                                */e_WarnReq_MaxNumber,
	/*WN_socDM_B30_Pothole,                1.113 凹凸路模式                                               */e_WarnReq_MaxNumber,
	/*WN_socDM_B30_MuddySand,              1.113 泥砂模式                                                */e_WarnReq_MaxNumber,
	/*WN_socDM_B30_Mountain,               1.113 山地模式                                                */e_WarnReq_MaxNumber,
    /*WN_socDM_StandardSelect,             1.113 标准模式已选择                                             */e_WarnReq_MaxNumber,
    /*WN_socDM_SportSelect,                1.113 运动模式已选择                                             */e_WarnReq_MaxNumber,
    /*WN_socDM_SportPlusSelect,            1.113 超级运动模式已选择                                           */e_WarnReq_MaxNumber,
    /*WN_socDM_SnowSelect,                 1.113 雪地模式已选择                                             */e_WarnReq_MaxNumber,
    /*WN_socDM_MuddySelect,                1.113 泥地模式已选择                                             */e_WarnReq_MaxNumber,
    /*WN_socDM_SandSelect,                 1.113 沙地模式已选择                                             */e_WarnReq_MaxNumber,
    /*WN_socDM_EcoSelect,                  1.113 经济模式已选择                                             */e_WarnReq_MaxNumber,
    /*WN_socDM_RockSelect,                 1.113 岩石模式已选择                                             */e_WarnReq_MaxNumber,
    /*WN_socDM_PotholeSelect,              1.113 凹凸路模式已选择                                            */e_WarnReq_MaxNumber,
    /*WN_socDM_MuddySandSelect,            1.113 泥沙模式已选择                                       	   */e_WarnReq_MaxNumber,
    /*WN_socDM_MountainSelect,             1.113 山地模式已选择                                       	   */e_WarnReq_MaxNumber,
    /*WN_socDM_ExpertSelect,               1.113 专家模式已选择                                             */e_WarnReq_MaxNumber,
    /*WN_socDM_OffRoadSelect,              1.113 越野模式已选择                                             */e_WarnReq_MaxNumber,
    /*WN_socDM_4LSelect,                   1.113 4L模式已选择                                             */e_WarnReq_MaxNumber,
    /*WN_socDM_IMCSelect,                  1.113 智能模式已选择                                      	   */e_WarnReq_MaxNumber,
    /*WN_socDM_StandardDPR,                1.113 标准模式切换中，无法进入D/P/R档3                                 */e_WarnReq_MaxNumber,
    /*WN_socDM_SportDPR,                   1.113 运动模式切换中，无法进入D/P/R档                                  */e_WarnReq_MaxNumber,
    /*WN_socDM_EcoDPR,                     1.113 经济模式切换中，无法进入D/P/R档                                  */e_WarnReq_MaxNumber,
    /*WN_socDM_SnowDPR,                    1.113 雪地模式切换中，无法进入D/P/R档                                  */e_WarnReq_MaxNumber,
    /*WN_socDM_MuddyDPR,                   1.113 泥地模式切换中，无法进入D/P/R档                                  */e_WarnReq_MaxNumber,
    /*WN_socDM_SandDPR,                    1.113 沙地模式切换中，无法进入D/P/R档                                  */e_WarnReq_MaxNumber,
    /*WN_socDM_PotholeDPR,                 1.113 凹凸路模式切换中，无法进入D/P/R档                                 */e_WarnReq_MaxNumber,
    /*WN_socDM_MountainDPR,                1.113 山地模式切换中，无法进入D/P/R档                                  */e_WarnReq_MaxNumber,
    /*WN_socDM_RockDPR,                    1.113 岩石模式切换中，无法进入D/P/R档                                  */e_WarnReq_MaxNumber,
    /*WN_socDM_OffRoadDPR,                 1.113 越野模式切换中，无法进入D/P/R档                                  */e_WarnReq_MaxNumber,
    /*WN_socDM_SportPlusDPR,               1.113 超级运动模式切换中，无法进入D/P/R档                                */e_WarnReq_MaxNumber,
    /*WN_socDM_ExpertDPR,                  1.113 专家模式切换中，无法进入D/P/R档                                  */e_WarnReq_MaxNumber,
    /*WN_socDM_MuddySandDPR,               1.113 泥沙模式切换中，无法进入D/P/R档                                  */e_WarnReq_MaxNumber,
    /*WN_socDM_IMCDPR,                     1.113 智能模式切换中，无法进入D/P/R档                                  */e_WarnReq_MaxNumber,
    /*WN_socDM_4LDPR,                      1.113 4L模式切换中，无法进入D/P/R档                                    */e_WarnReq_MaxNumber,
	/*WN_soc4LEnGearN,                     1.134/1.135 ESOF 驱动模式 要进入4L模式，请停车挂N 挡  No signa         */e_WarnReq_MaxNumber,
	/*WN_soc4LEnGearDRP,                   1.134/1.135 ESOF 驱动模式 进入4L模式中，无法挂入D/R/P 挡  No s         */e_WarnReq_MaxNumber,
	/*WN_soc4LExGearN,                     1.134/1.135 ESOF 驱动模式 要退出4L模式，请停车挂N 挡  No signa         */e_WarnReq_MaxNumber,
	/*WN_soc4LExGearDRP,                   1.134/1.135 ESOF 驱动模式 退出4L模式中，无法挂入D/R/P 挡  No s         */e_WarnReq_MaxNumber,
	/*WN_soc4LEnClutchStep,                1.134/1.135 ESOF 驱动模式 要进入4L模式，请停车并踩下离合    No s       */e_WarnReq_MaxNumber,
	/*WN_soc4LEnClutchRele,                1.134/1.135 ESOF 驱动模式 进入4L模式中，请勿松开离合踏板    No s       */e_WarnReq_MaxNumber,
	/*WN_soc4LExClutchStep,                1.134/1.135 ESOF 驱动模式 要退出4L模式，请停车并踩下离合    No s       */e_WarnReq_MaxNumber,
	/*WN_soc4LExClutchRele,                1.134/1.135 ESOF 驱动模式 退出4L模式中，请勿松开离合踏板    No s       */e_WarnReq_MaxNumber,
    /*WN_socDM_StandardSecond,             1.113 标准模式                                                 */e_WarnReq_MaxNumber,
    /*WN_socDM_SportSecond,                1.113 运动模式                                                 */e_WarnReq_MaxNumber,
    /*WN_socDM_SportPlusSecond,            1.113 超级运动模式                                               */e_WarnReq_MaxNumber,
    /*WN_socDM_SnowSecond,                 1.113 雪地模式                                                 */e_WarnReq_MaxNumber,
    /*WN_socDM_MuddySecond,                1.113 泥地模式                                                 */e_WarnReq_MaxNumber,
    /*WN_socDM_SandSecond,                 1.113 沙地模式                                                 */e_WarnReq_MaxNumber,
    /*WN_socDM_ECOSecond,                  1.113 经济模式                                                 */e_WarnReq_MaxNumber,
    /*WN_socDM_4LSecond,                   1.113 4L模式                                                 */e_WarnReq_MaxNumber,
    /*WN_socDM_PotholeSecond,              1.113 凹凸路模式                                                */e_WarnReq_MaxNumber,
    /*WN_socDM_MountainSecond,             1.113 山地模式                                                 */e_WarnReq_MaxNumber,
    /*WN_socDM_RockSecond,                 1.113 岩石模式                                                 */e_WarnReq_MaxNumber,
    /*WN_socDM_OffRoadSecond,              1.113 越野模式                                                 */e_WarnReq_MaxNumber,
    /*WN_socDM_ExpertSecond,               1.113 专家模式                                                 */e_WarnReq_MaxNumber,
    /*WN_socDM_IMCSecond,                  1.113 智能模式                                                 */e_WarnReq_MaxNumber,
    /*WN_socDM_MuddySandSecond,            1.113 泥砂模式                                                 */e_WarnReq_MaxNumber,
    /*WN_socDM_EV_StandardStart,           1.115 标准模式已启动                                              */e_WarnReq_MaxNumber,
    /*WN_socDM_EV_SportStart,              1.115 运动模式已启动                                              */e_WarnReq_MaxNumber,
    /*WN_socDM_EV_EcoStart,                1.115 经济模式已启动                                        		*/e_WarnReq_MaxNumber,
    /*WN_socDM_EV_SnowStart,               1.115 雪地模式已启动                                              */e_WarnReq_MaxNumber,
    /*WN_socDM_EV_AutoStart,               1.115 AUTO模式已启动                                            */e_WarnReq_MaxNumber,
	/*WN_socDM_V51EV_SinPedalStart,        1.117 单踏板功能已启动                                             */e_WarnReq_MaxNumber,
	/*WN_socDM_V51EV_SinPedalQuit,         1.117 单踏板功能退出                                              */e_WarnReq_MaxNumber,
	/*WN_socStopBrakeGearN,                1.162 长时间停车，请踩下刹车/挂入P挡                                     */e_WarnReq_LcdAlarmOnce,
	/*WN_socPowerNotInOff,                 1.42  电源未关                                                 */e_WarnReq_LcdAlarmOnce,
	/*WN_socAutoStartStop,                 1.6   智能启停                                                 */e_WarnReq_LcdAlarmOnce,
	/*WN_socChargeDevRemoved,              1.80 充电装置已移除    No signal                                  */e_WarnReq_LcdAlarmOnce,
	/*WN_socDM_DBL_EV_Err,                 1.109 动力电池电量低，EV模式不可用                                      */e_WarnReq_LcdAlarmOnce,
	/*WN_socDM_HSL_AWD,                    1.109 混合动力系统暂时受限，AWD模式不可用                                  */e_WarnReq_LcdAlarmOnce,
	/*WN_socDM_HSL_EV,                     1.109 混合动力系统暂时受限，EV模式不可用                                   */e_WarnReq_LcdAlarmOnce,
	/*WN_socDM_HSL_SAVE,                   1.109 混合动力系统暂时受限，SAVE模式不可用                                 */e_WarnReq_LcdAlarmOnce,
	/*WN_socDM_HSL_SPORT,                  1.109 混合动力系统暂时受限，SPORT模式不可用                                */e_WarnReq_LcdAlarmOnce,
	/*WN_socDM_HSL_SAND,                   1.109 混合动力系统暂时受限，沙地模式不可用                                   */e_WarnReq_LcdAlarmOnce,
	/*WN_socDM_HSL_MUDDY,                  1.109 混合动力系统暂时受限，泥地模式不可用                                   */e_WarnReq_LcdAlarmOnce,
	/*WN_socDM_HSL_SNOW,                   1.109 混合动力系统暂时受限，雪地模式不可用                                   */e_WarnReq_LcdAlarmOnce,
	/*WN_socDM_PHEV_AutoStart,             1.114 自动模式已启动                                              */e_WarnReq_MaxNumber,
	/*WN_socDM_PHEV_EvStart,               1.114 纯电模式已启动                                              */e_WarnReq_MaxNumber,
	/*WN_socDM_PHEV_SaveStart,             1.114 节能模式已启动                                              */e_WarnReq_MaxNumber,
	/*WN_socDM_PHEV_SportStart,            1.114 运动模式已启动                                              */e_WarnReq_MaxNumber,
	/*WN_socDM_PHEV_AWDStart,              1.114 全驱模式已启动                                              */e_WarnReq_MaxNumber,
	/*WN_socDM_PHEV_SnowStart,             1.114 雪地模式已启动                                              */e_WarnReq_MaxNumber,
	/*WN_socDM_PHEV_MuddyStart,            1.114 泥地模式已启动                                              */e_WarnReq_MaxNumber,
	/*WN_socDM_PHEV_SandStart,             1.114 沙地模式已启动                                              */e_WarnReq_MaxNumber,
	/*WN_socDM_PHEV_EcoStart,              1.114 经济模式已启动                                              */e_WarnReq_MaxNumber,
	/*WN_socDM_PHEV_SportPlusStart,        1.114 超级运动模式已启动                                            */e_WarnReq_MaxNumber,
	/*WN_socDM_MS_SPORT,                   1.109 已使用手动换挡，车辆切换至SPORT模式                                 */e_WarnReq_LcdAlarmOnce,
	/*WN_socDM_MS_SPORT_Only,              1.109 已使用手动换挡，仅SPORT模式可用                                   */e_WarnReq_LcdAlarmOnce,
	/*WN_socDM_HSR_EV,                     1.109 混合动力系统限制解除，EV模式可用                                    */e_WarnReq_LcdAlarmOnce,
	/*WN_socRLUnavaiESPAVH,                1.111 ESP/AVH功能未关闭，弹射起步不可用                                 */e_WarnReq_LcdAlarmOnce,
	/*WN_socRLUnavaiHYB,                   1.111 混合动力系统暂时受限，弹射起步不可用                                   */e_WarnReq_LcdAlarmOnce,
	/*WN_socDM_HSL_SPORT_P,                1.109 混合动力系统暂时受限，SPORT+模式不可用            					*/e_WarnReq_LcdAlarmOnce,
	/*WN_socDM_HSL_ECO,                    1.109 混合动力系统暂时受限, ECO模式不可用                                 */e_WarnReq_LcdAlarmOnce,
    /*WN_socTurnAssistOn,                  TBD   转向辅助功能已开启                                            */e_WarnReq_MaxNumber,
    /*WN_socTurnAssistWork,                TBD   转向辅助功能工作中                                            */e_WarnReq_MaxNumber,
    /*WN_socTurnAssistClose,               TBD   转向辅助功能已关闭                                            */e_WarnReq_MaxNumber,
    /*WN_socORCruiseClose,                 TBD   越野巡航功能已关闭                                            */e_WarnReq_MaxNumber,
    /*WN_socORCruiseWait,                  TBD   越野巡航功能已进入待机状态                                        */e_WarnReq_MaxNumber,
    /*WN_socORCruiseOn,                    TBD   越野巡航功能已开启                                    		*/e_WarnReq_MaxNumber,
	/*WN_socFastenSeatbelt,                1.11  EPB报警1 请系安全带                                         */e_WarnReq_MaxNumber,
	/*WN_socGradientHighWarning,           1.11  EPB报警1 坡度过大                                     		*/e_WarnReq_MaxNumber,
	/*WN_socParkSysWarning,                1.11  EPB报警1 驻车制动过热                                        */e_WarnReq_MaxNumber,
	/*WN_socClampForceWarning,             1.11  EPB报警1 夹紧力不足                                  		*/e_WarnReq_MaxNumber,
	/*WN_socStepBrakePedal,                1.15  请踩制动踏板                                               */e_WarnReq_MaxNumber,
	/*WN_socSettingVehilce,                TBD   请停车进行设置 已删除                                          */e_WarnReq_MaxNumber,
	/*WN_socOutTempLow,                    1.119 室外温度低，请减速慢行                                          */e_WarnReq_MaxNumber,
	/*WN_socAFSOff,                        1.129 AFS关闭  No signal                                     */e_WarnReq_LcdAlarmOnce,
	/*WN_socAFSOn,                         1.129 AFS开启  No signal                                     */e_WarnReq_LcdAlarmOnce,
	/*WN_socSwitchMudSand,                 1.142 请先切换至泥地或沙地模式                                         */e_WarnReq_LcdAlarmOnce,
	/*WN_socRaceModeExit,                  1.112 弹射模式退出                                               */e_WarnReq_LcdAlarmOnce,
	/*WN_socRaceModeFault,                 1.112 无法进入弹射模式                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socPHLWideFunOff,                 1.123 像素大灯示宽功能未开启，请在中控中设置开启  No signal                 	*/e_WarnReq_MaxNumber,
	/*WN_socPHLWideOn,                     1.123 像素大灯示宽功能开启  No signal                                */e_WarnReq_MaxNumber,
	/*WN_socPHLWideOff,                    1.123 像素大灯示宽功能关闭  No signal                                */e_WarnReq_MaxNumber,
	/*WN_socPHLFunOff,                     1.136 像素大灯功能关闭    No signal                                */e_WarnReq_MaxNumber,
	/*WN_socPHLFunOn,                      1.136 像素大灯功能开启    No signal                                */e_WarnReq_MaxNumber,
	/*WN_socQuitCompactMode,               TBD   请退出简洁模式                                              */e_WarnReq_MaxNumber,
	/*WN_socWashModeActive,                1.163 拖车/洗车模式已激活                                           */e_WarnReq_LcdAlarmOnce,
	/*WN_socWashModeSpeed,                 1.163 车速过高，拖车/洗车模式不可用                                      */e_WarnReq_LcdAlarmOnce,
	/*WN_socWashModeBatt,                  1.163 蓄电池电量低，拖车/洗车模式不可用                                    */e_WarnReq_LcdAlarmOnce,
	/*WN_socChargeDisGunConnect,           1.164 充/放电枪已连接                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socChargeGunConnect,              1.164 充电枪已连接                                               */e_WarnReq_LcdAlarmOnce,
	/*WN_socReleaseElecPark,               1.76  请释放电子驻车                                              */e_WarnReq_MaxNumber,
	/*WN_socReleaseRearELD,                1.76 请释放后桥差速锁                                              */e_WarnReq_MaxNumber,
	/*WN_socRLUnavaiESP,                   1.111 ESP功能未关闭，弹射起步不可用                                     */e_WarnReq_LcdAlarmOnce,
	/*WN_socHeatingComplete,               1.152 动力电池预热完成                                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socFaceCancelled,                 1.172 人脸识别已取消                                              */e_WarnReq_MaxNumber,
	/*WN_socFaceNoMatch,                   1.172 未找到匹配的人脸                                             */e_WarnReq_MaxNumber,
	/*WN_socFaceSuccess,                   1.172 人脸识别成功                                               */e_WarnReq_MaxNumber,
	/*WN_socPedalDynBatt,                  1.168 混合动力系统暂时受限，单踏板不可用  No signal                    		*/e_WarnReq_LcdAlarmOnce,
	/*WN_socPedalDynSnow,                  1.168 雪地模式开启，单踏板不可用  No signal                             */e_WarnReq_LcdAlarmOnce,
	/*WN_socFarBeamOn,                     1.122 超远辅助远光故障    No signal                                */e_WarnReq_LcdAlarmOnce,
	/*WN_socFarBeamOff,                    1.122 超远辅助远光故障    No signal                                */e_WarnReq_LcdAlarmOnce,
	/*WN_socTmsTrailerOn,                  1.180 拖车防摆功能已开启                                            */e_WarnReq_MaxNumber,
	/*WN_socTmsTrailerOff,                 1.180 拖车防摆功能已关闭                                            */e_WarnReq_MaxNumber,
	/*WN_soc4WDGearDelayPlsSlow,           1.138 四驱换挡直行 请尝试低速直行 TBD                                   */e_WarnReq_MaxNumber,
	/*WN_socARHUDLightLimit,               1.217 抬头显示亮度限制中                                            */e_WarnReq_LcdAlarmOnce,
	/*WN_socBattLowLaunchUnavil,           1.111 动力电池电量/温度低，弹射起步不可用             	                    */e_WarnReq_LcdAlarmOnce,
	/*WN_socIFCExitPlsControl,             1.218 横向控制已退出 请控制方向                                        */e_WarnReq_HcExitTakeDirOnce,
	
	//Important alarm
	/*WN_socERCSysErr                      1.242 ERC系统故障 请立即维修										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socIFCLKAFuncOn               	   1.269 紧急车道保持功能开启											*/e_WarnReq_LcdAlarmOnce,

		//Secondary alarm
	/*WN_socTurnAssistFuncLimit            1.248 转向助力功能受限 请小心驾驶										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socERCSysLimit                    1.242 ERC系统受限												*/e_WarnReq_MaxNumber,

		//Tips
	/*WN_socMainTankLow                    1.239 显示主油箱油量低，请添加燃油										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socMainTankLowPlsSwitch           1.239 主油箱油量低，请及时熄火并切换到副油箱									*/e_WarnReq_LcdAlarmOnce,
	/*WN_socAuxTankLow                     1.239 副油箱油量低，请添加燃油											*/e_WarnReq_LcdAlarmOnce,
	/*WN_socAuxTankLowPlsSwitch            1.239 副油箱油量低，请及时熄火并切换到主油箱									*/e_WarnReq_LcdAlarmOnce,
	/*WN_socDM_B30_Turbo                   1.113 狂暴模式													*/e_WarnReq_MaxNumber,
	/*WN_socDM_B30_Race                    1.113 赛道模式													*/e_WarnReq_MaxNumber,
	/*WN_socDM_B30_GrassGravel             1.113 草地/碎石模式												*/e_WarnReq_MaxNumber,
	/*WN_socDM_B30_Uneven                  1.113 凹凸路模式												*/e_WarnReq_MaxNumber,
	/*WN_socDM_B30_Wade4H                  1.113 涉水模式													*/e_WarnReq_MaxNumber,
	/*WN_socDM_B30_Wade4L                  1.113 低速涉水模式												*/e_WarnReq_MaxNumber,
	/*WN_socDM_B30_2H                      1.113 2H模式													*/e_WarnReq_MaxNumber,
	/*WN_socDM_B30_4H                      1.113 4H模式													*/e_WarnReq_MaxNumber,
	/*WN_socDM_TurboSelect                 1.113 狂暴模式已选择												*/e_WarnReq_MaxNumber,
	/*WN_socDM_RaceSelect                  1.113 赛道模式已选择												*/e_WarnReq_MaxNumber,
	/*WN_socDM_GrassGravelSelect           1.113 草地/碎石模式已选择											*/e_WarnReq_MaxNumber,
	/*WN_socDM_UnevenSelect                1.113 凹凸路模式已选择												*/e_WarnReq_MaxNumber,
	/*WN_socDM_Wade4HSelect                1.113 涉水模式已选择												*/e_WarnReq_MaxNumber,
	/*WN_socDM_Wade4LSelect                1.113 低速涉水模式已选择											*/e_WarnReq_MaxNumber,
	/*WN_socDM_2HSelect                    1.113 2H模式已选择												*/e_WarnReq_MaxNumber,
	/*WN_socDM_4HSelect                    1.113 4H模式已选择												*/e_WarnReq_MaxNumber,
	/*WN_socDM_TurboDPR                    1.113 狂暴模式切换中，无法进入D/P/R档									*/e_WarnReq_MaxNumber,
	/*WN_socDM_RaceDPR                     1.113 赛道模式切换中，无法进入D/P/R档									*/e_WarnReq_MaxNumber,
	/*WN_socDM_GrassGravelDPR              1.113 草地/碎石模式切换中，无法进入D/P/R档								*/e_WarnReq_MaxNumber,
	/*WN_socDM_UnevenDPR                   1.113 凹凸路模式切换中，无法进入D/P/R档									*/e_WarnReq_MaxNumber,
	/*WN_socDM_Wade4HDPR                   1.113 涉水模式切换中，无法进入D/P/R档									*/e_WarnReq_MaxNumber,
	/*WN_socDM_Wade4LDPR                   1.113 低速涉水模式切换中，无法进入D/P/R档									*/e_WarnReq_MaxNumber,
	/*WN_socDM_2HDPR                       1.113 2H模式切换中，无法进入D/P/R档									*/e_WarnReq_MaxNumber,
	/*WN_socDM_4HDPR                       1.113 4H模式切换中，无法进入D/P/R档									*/e_WarnReq_MaxNumber,
	/*WN_socDM_TurboSecond                 1.113 狂暴模式													*/e_WarnReq_MaxNumber,
	/*WN_socDM_RaceSecond                  1.113 赛道模式													*/e_WarnReq_MaxNumber,
	/*WN_socDM_GrassGravelSecond           1.113 草地/碎石模式												*/e_WarnReq_MaxNumber,
	/*WN_socDM_UnevenSecond                1.113 凹凸路模式												*/e_WarnReq_MaxNumber,
	/*WN_socDM_Wade4HSecond                1.113 涉水模式													*/e_WarnReq_MaxNumber,
	/*WN_socDM_Wade4LSecond                1.113 低速涉水模式												*/e_WarnReq_MaxNumber,
	/*WN_socDM_2HSecond                    1.113 2H模式													*/e_WarnReq_MaxNumber,
	/*WN_socDM_4HSecond                    1.113 4H模式													*/e_WarnReq_MaxNumber,
	/*WN_socDM_PHEV_P2HEVStart             1.114 混动模式已启动												*/e_WarnReq_MaxNumber,
	/*WN_socDM_PHEV_P2EVStart              1.114 纯电模式已启动												*/e_WarnReq_MaxNumber,
	/*WN_socDM_PHEV_P2SaveStart            1.114 能量储备模式已启动											*/e_WarnReq_MaxNumber,
	/*WN_socAutoNaviStart                  TBD 已进入自动辅助导航可用区域，欢迎使用自动辅助导航								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socAutoNaviExitPlsTake            TBD XX 米后退出自动辅助导航，请准备接管									*/e_WarnReq_MaxNumber,
	/*WN_socAutoNaviEnd                    TBD 自动辅助导航结束												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socOverSpeedERCSysOn              1.242 车速过高 ERC系统自动连接										*/e_WarnReq_MaxNumber,
	/*WN_socERCSysDisable                  1.242 当前驾驶模式 ERC系统断开禁用										*/e_WarnReq_MaxNumber,
	/*WN_socOffroadThmSts                  1.265 越野散热模式已开启											*/e_WarnReq_MaxNumber,
	/*WN_socAntennaLostErr                 1.245 低频天线异常												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socAutoLmpStsOn                   1.268 自动大灯开启												*/e_WarnReq_MaxNumber,	
	/*WN_socAutoLmpStsOff                  1.268 自动大灯关闭												*/e_WarnReq_MaxNumber,
	/*WN_socPlsExitWadeMode                1.267 请退出涉水模式												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socWadeModePlsSlow                1.267 请减速													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socWadeModePlsSlow                1.267 请确认周边工况 如已涉水，谨慎点火									*/e_WarnReq_LcdAlarmOnce,

	//Important alarm
    /*WN_enCarPowerShutDown,              1.249 长按紧急下电开关，整车下电！                                        */e_WarnReq_MaxNumber,
    /*WN_enLifeDetectFault,               TBD 生命探测功能故障												*/e_WarnReq_LcdAlarmOnce,
    /*WN_enClutchOverheat,                1.270 离合器过热													*/e_WarnReq_LcdAlarmOnce,
    /*WN_enQuickStartOvertime,            TBD 弹射起步超时													*/e_WarnReq_LcdAlarmOnce,

    //Secondary alarm

    //Tips
    /*WN_enLifeDetectClose,               TBD 生命探测功能关闭												*/e_WarnReq_LcdAlarmOnce,
    /*WN_enStopGearNSeatbelt,             TBD 踩下刹车+请挂N挡+驾驶侧有人或安全带系上									*/e_WarnReq_MaxNumber,
    /*WN_enStopGearPNSeatbelt,            TBD 踩下刹车+请挂P挡或N挡+驾驶侧有人或安全带系上								*/e_WarnReq_MaxNumber,
    /*WN_enSwitchSnowSand,                1.142 请先切换至雪地、泥地、沙地或凹凸路模式									*/e_WarnReq_LcdAlarmOnce,
    /*WN_enIndividual,                    1.116 个性化模式已启动												*/e_WarnReq_MaxNumber,
    /*WN_enPowerSysLimitLaunchFail,       TBD 动力系统暂时受限，弹射起步不可用 										*/e_WarnReq_LcdAlarmOnce,
    /*WN_enForwardChargeMode,             1.274 当前为预约充电模式												*/e_WarnReq_LcdAlarmOnce,
    /*WN_en4WDEVSaveDisable,              1.109 四驱模式，纯电和能量储备模式不可用										*/e_WarnReq_LcdAlarmOnce,

	//Update for Warning table v0.64
	//Special alarm
	/*WN_socV2XCarDistance				  请注意前车距离+图片													*/e_WarnReq_ChimeCarDistance,
	/*WN_socV2XPeopleRight				  意避让行人+右图片													*/e_WarnReq_ChimePeopleRight,
	/*WN_socV2XPeopleMid				  注意避让行人+中图片													*/e_WarnReq_ChimePeopleMid,
	/*WN_socV2XPeopleLeft 				  注意避让行人+左图片													*/e_WarnReq_ChimePeopleLeft,
	/*WN_socV2XFaceCar				      注意对向来车+图片													*/e_WarnReq_ChimeFaceCar,
	/*WN_socV2XSideCarTwoSide 		      注意横向来车+两侧图片													*/e_WarnReq_ChimeSideCarTwoSide,
	/*WN_socV2XSideCarRight				  注意横向来车+右侧图片													*/e_WarnReq_ChimeSideCarRight,
	/*WN_socV2XSideCarLeft				  注意横向来车+左侧图片													*/e_WarnReq_ChimeSideCarLeft,
	/*WN_socV2XFrontCarAEB				  前方车辆紧急制动+图片													*/e_WarnReq_ChimeFrontCarAEB,
	/*WN_socV2XFrontCarUnContron		  注意前方失控车辆+图片													*/e_WarnReq_ChimeFrontCarUnContron,
	/*WN_socV2XBackCarUnContron			  注意后方失控车辆+图片													*/e_WarnReq_ChimeBackCarUnContron,
	/*WN_socV2XAroundCarUnContron 		  注意周围失控车辆+图片													*/e_WarnReq_ChimeAroundCarUnContron,
	
	//Important alarm
	/*WN_socHookFaultPlsCheck 			  拖车钩故障 请检查													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socSuspensionFuncLimit			  空气悬架功能受限！请尽快维修												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socSuspensionFuncFault			  空气悬架故障！请立即维修												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socCatalystSuHigh				  催化器硫含量较高													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socSuClearing					  正在除硫														*/e_WarnReq_LcdAlarmOnce,
	/*WN_socOilLeverLow					  机油液位过低														*/e_WarnReq_LcdAlarmOnce,
	/*WN_socOilLeverHigh				  机油液位过高														*/e_WarnReq_LcdAlarmOnce,
	/*WN_socOilLeverFault 				  机油液位检测故障													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socV2XLeftLine					  请勿左侧变道+图片													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socV2XRightLine				  请勿右侧变道+图片													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socV2XReverseLine				  请勿逆向超车+图片													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socV2XFrontRoad				  请注意前方路况+图片													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socV2XFrontCarAttention		  请注意前方异常车辆+图片												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socV2XLeaveCar					  注意避让紧急车辆													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socV2XLeaveFireCar				  注意避让消防车														*/e_WarnReq_LcdAlarmOnce,
	/*WN_socV2XLeaveAmbulance 			  注意避让救护车														*/e_WarnReq_LcdAlarmOnce,
	/*WN_socV2XLeavePolice				  注意避让警车														*/e_WarnReq_LcdAlarmOnce,
	/*WN_socV2XLeaveEngCar				  注意避让工程救援车													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socV2XBackCarLeft				  注意后方盲区车辆+左后盲区图片												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socV2XBackCarRight				  注意后方盲区车辆+右后盲区图片												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socV2XBackCarTwoSide 			  注意后方盲区车辆+左右后方盲区图片											*/e_WarnReq_LcdAlarmOnce,
	
	//Secondary alarm
	/*WN_socSavePlusPowerLimit			  超级省电模式下动力性和舒适性受限											*/e_WarnReq_LcdAlarmOnce,
	/*WN_socOverSpeedSavePlusFail 		  车速过高,无法切换超级省电模式												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socWormFuncActive				  蠕行功能已激活														*/e_WarnReq_LcdAlarmOnce,
	/*WN_socWormFuncOff					  蠕行功能关闭														*/e_WarnReq_LcdAlarmOnce,
	/*WN_socBattLowStartEng				  蓄电池电量低\n启动发动机更改车辆高度											*/e_WarnReq_LcdAlarmOnce,
	/*WN_socSuspensionCoolDown			  空气悬架系统正在冷却，请等待												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socHeightModeDisable 			  所选高度模式不允许													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socPlsCloseDoorRise			  请关闭车门\n以完成高度升降												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socRiseModeSusLimit			  进入举升模式\n空气悬架临时禁用											*/e_WarnReq_LcdAlarmOnce,
	/*WN_socSuspensionTimeLimit			  空气悬架临时禁用													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socOverSpeedHeightDisable		  车速高\n无法完成高度切换												*/e_WarnReq_LcdAlarmOnce,
	
	//Tips
	/*WN_socOverDefaultPower			  当前电量高于预设SOC值，无法充电											*/e_WarnReq_LcdAlarmOnce,
	/*WN_socHookLock					  拖车钩已上锁														*/e_WarnReq_LcdAlarmOnce,
	/*WN_socHookUnlock					  拖车钩已解锁														*/e_WarnReq_LcdAlarmOnce,
	/*WN_socHookPowerOn					  拖车钩电气连接完成													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socSwitchParkSts 				  请先切换为驻车状态													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socPlsCloseHook				  请先关闭拖车钩														*/e_WarnReq_LcdAlarmOnce,
	/*WN_socPlsCheckHookSts				  请检查拖车钩连接状态													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socNormalHeightSelect			  已选择标准高度														*/e_WarnReq_MaxNumber,
	/*WN_socSuitHeightSelect			  已选择便捷进出高度													*/e_WarnReq_MaxNumber,
	/*WN_socORHeight1Select				  已选择越野高度1													*/e_WarnReq_MaxNumber,
	/*WN_socORHeight2Select				  已选择越野高度2													*/e_WarnReq_MaxNumber,
	/*WN_socSuspensionExtend			  悬架进入扩展模式													*/e_WarnReq_MaxNumber,
	/*WN_socSuspensionLockHeight		  悬架锁定在便捷进出高度													*/e_WarnReq_MaxNumber,
	/*WN_socBackShaftHeightSelect 		  已选择后轴装载高度													*/e_WarnReq_MaxNumber,
	/*WN_socSuitHeightModeSelect		  已选择自动便捷进出模式													*/e_WarnReq_MaxNumber,
	/*WN_socSuspensionTrailer 			  空气悬架启用拖车模式													*/e_WarnReq_MaxNumber,
	/*WN_socSuspensionLimitRise			  空气悬架临时禁用\n以进行换胎、举升											*/e_WarnReq_MaxNumber,
	/*WN_socKickBackShaft 				  已选择脚踢开启后轴装载模式												*/e_WarnReq_MaxNumber,
	/*WN_socSuspensionLimitTrans		  空气悬架临时禁用\n用于车辆运输											*/e_WarnReq_MaxNumber,
	/*WN_socSuspensionRise				  悬架即将升高\n退出当前低水平高度											*/e_WarnReq_LcdAlarmOnce,
	/*WN_socCarHighPlsSlow				  当前车辆处于高位\n请减速慢行												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socSuClearDown					  除硫结束														*/e_WarnReq_LcdAlarmOnce,
	/*WN_socSysFailACCDisable 			  系统故障，自适应能量回收不可用												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socACCPowerDisable				  传感器故障，自适应能量回收不可用											*/e_WarnReq_LcdAlarmOnce,
	/*WN_socHWAACCPowerDisable			  智能驾驶功能激活，自适应能量回收 不可用										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socESPACCPowerDisable			  ESP功能激活，自适应能量 回收不可用											*/e_WarnReq_LcdAlarmOnce,
	/*WN_socACCPowerExit				  自适应能量回收退出													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socBattPowerLowEVDisable 		  动力电池功率低，纯电模式不可用												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socBattTempLowEVDisable		  动力电池温度低，纯电模式不可用												*/e_WarnReq_LcdAlarmOnce,
	/*WN_soc4LModeEVSaveDisable			  当前为4L模式，纯电和能量储备模式不可用										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socCalibreHeatTabLimit			  卡钳过热，转向辅助功能受限												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socSavePlusModeStart 			  超级省电模式已启动													*/e_WarnReq_MaxNumber,
	/*WN_socV2XRoadBlockLever1			  道路轻度拥堵+图片													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socV2XRoadBlockLever2			  道路中度拥堵+图片													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socV2XRoadBlockLever3			  道路严重拥堵+图片													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socV2XRoadBlock				  道路拥堵+图片														*/e_WarnReq_LcdAlarmOnce,
	/*WN_socStepBrakeStartGearBlank		  1.40 踩下刹车+一键启动 请挂空挡									        */e_WarnReq_MaxNumber,
	/*WN_socStopGearBlankSeatbelt 		  1.37 踩下刹车+请挂空挡+驾驶侧有人或安全带系上				 			        */e_WarnReq_MaxNumber,
	/*WN_socPlsTakeOver,                     1.205 请立即接管                                              */e_WarnReq_ChimePlsTakeOver1Hz,
    /*WN_socPlsTakeOver_2Hz,                 1.205 请立即接管2Hz提示音										*/e_WarnReq_ChimePlsTakeOver2Hz,
    /*WN_socPlsTakeOver_4Hz,                 1.205 请立即接管4Hz提示音										*/e_WarnReq_ChimePlsTakeOver4Hz,
    /*WN_socCarAutoBrakePlsTake,             1.272 车辆正在自动刹停，请立即接管										*/e_WarnReq_ChimeCarAutoBrakePlsTake,
    /*WN_socCarParkingPlsTake,               1.272 车辆正在靠边停车，请立即接管										*/e_WarnReq_ChimeCarParkingPlsTake,
    /*WN_socCarUrgeBrakePlsTake,             1.272 车辆正在紧急刹停，请立即接管										*/e_WarnReq_ChimeCarUrgeBrakePlsTake,
    /*WN_socMoveRampFailPlsTake,             1.297 驶入匝道失败，请立即接管										*/e_WarnReq_ChimeMoveRampFailPlsTake,
    /*WN_socMoveMainFailPlsTake,             1.297 汇入主路失败，请立即接管										*/e_WarnReq_ChimeMoveMainFailPlsTake1Hz,
    /*WN_socMoveMainFailPlsTake_2Hz,         1.297 汇入主路失败，请立即接管2Hz提示音									*/e_WarnReq_ChimeMoveMainFailPlsTake2Hz,
    /*WN_socMoveMainFailPlsTake_4Hz,         1.297 汇入主路失败，请立即接管4Hz提示音									*/e_WarnReq_ChimeMoveMainFailPlsTake4Hz,
    /*WN_socTurnFailPlsTake,                 1.297 转弯失败，请立即接管											*/e_WarnReq_ChimeTurnFailPlsTake1Hz,
    /*WN_socTurnFailPlsTake_2Hz,             1.297 转弯失败，请立即接管2Hz提示音									*/e_WarnReq_ChimeTurnFailPlsTake2Hz,
    /*WN_socTurnFailPlsTake_4Hz,             1.297 转弯失败，请立即接管4Hz提示音									*/e_WarnReq_ChimeTurnFailPlsTake4Hz,
    /*WN_socTollGateFailPlsTake,             1.297 无法成功通过收费站，请立即接管									*/e_WarnReq_ChimeTollGateFailPlsTake1Hz,
    /*WN_socTollGateFailPlsTake_2Hz,         1.297 无法成功通过收费站，请立即接管2Hz提示音								*/e_WarnReq_ChimeTollGateFailPlsTake2Hz,
    /*WN_socTollGateFailPlsTake_4Hz,         1.297 无法成功通过收费站，请立即接管4Hz提示音								*/e_WarnReq_ChimeTollGateFailPlsTake4Hz,
    /*WN_socRoundaboutFailPlsTake,           1.297 无法成功通过环岛，请立即接管										*/e_WarnReq_ChimeRoundaboutFailPlsTake1Hz,
    /*WN_socRoundaboutFailPlsTake_2Hz,       1.297 无法成功通过环岛，请立即接管2Hz提示音								*/e_WarnReq_ChimeRoundaboutFailPlsTake2Hz,
    /*WN_socRoundaboutFailPlsTake_4Hz,       1.297 无法成功通过环岛，请立即接管4Hz提示音								*/e_WarnReq_ChimeRoundaboutFailPlsTake4Hz,


	  //mportant alarm
    /*WN_enV2XFrontCarAttentionLeft,        1.256 请注意前方异常车辆+左前方图片										*/e_WarnReq_LcdAlarmOnce,
    /*WN_enV2XFrontCarAttentionRight,       1.256 请注意前方异常车辆+右前方图片										*/e_WarnReq_LcdAlarmOnce,
    /*WN_enUrgeTurnPlsHoldWheel,            1.204 前方急转弯，请手扶方向盘										*/e_WarnReq_UrgeTurnPlsHoldWheel,
    /*WN_enFastChrgFault,                   1.294 快充桩故障，充电停止											*/e_WarnReq_MaxNumber,
    /*WN_enNOHFailPlsFix,                   1.273 无法开启自动导航辅助，请前往4S 店修理								*/e_WarnReq_LcdAlarmOnce,
    /*WN_enNOHFailPlsGearP,                 1.273 无法开启自动导航辅助，请挂P 挡重新尝试								*/e_WarnReq_LcdAlarmOnce,
    /*WN_enMoveRampFailPlsHand,             1.273 驶入匝道失败，请手动尝试										*/e_WarnReq_LcdAlarmOnce,
    /*WN_enMoveMainFailPlsHand,             1.273 汇入主路失败，请手动尝试										*/e_WarnReq_LcdAlarmOnce,
    /*WN_enTurnFailPlsHand,                 1.273 转弯失败，请手动尝试											*/e_WarnReq_LcdAlarmOnce,
    /*WN_enTollGateFailPlsHand,             1.273 无法成功通过收费站，请手动尝试										*/e_WarnReq_LcdAlarmOnce,
    /*WN_enRoundaboutFailPlsHand,           1.273 无法成功通过环岛，请手动尝试										*/e_WarnReq_LcdAlarmOnce,
    /*WN_enRePlanLanes,                     1.273 已重新规划路径												*/e_WarnReq_LcdAlarmOnce,
    /*WN_enPlsHandChangeLanes,              1.273 路况复杂，建议手动变道											*/e_WarnReq_LcdAlarmOnce,
    /*WN_enMoveRampFailHandWheel,           1.297 驶入匝道失败，请控制方向盘										*/e_WarnReq_MoveRampFailHandWheel,
    /*WN_enMoveRampFailHandWheel_2Hz,       1.297 驶入匝道失败，请控制方向盘2Hz提示音									*/e_WarnReq_MoveRampFailHandWheel_2Hz,
    /*WN_enMoveMainFailHandWheel,           1.297 汇入主路失败，请控制方向盘										*/e_WarnReq_MoveMainFailHandWheel,
    /*WN_enTurnFailPlsHandWheel,            1.297 转弯失败，请控制方向盘											*/e_WarnReq_TurnFailPlsHandWheel,
    /*WN_enTollGateFailPlsHandWheel,        1.297 无法成功通过收费站，请控制方向盘									*/e_WarnReq_TollGateFailPlsHandWheel,
    /*WN_enRoundaboutFailPlsHandWheel,      1.297 无法成功通过环岛，请控制方向盘										*/e_WarnReq_RoundaboutFailPlsHandWheel,

	//Secondary alarm
	/*WN_socTJAICADisable, 				  	1.201 智慧巡航不可用												*/e_WarnReq_MaxNumber,
	/*WN_socLowSpeedLaneAssistDisable, 	    1.204 车速过低，变道辅助不可用										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socOverSpeedLaneAssistDisable,	    1.204 车速过高，变道辅助不可用										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socTJAICAFaultPlsFixCamera,	   	1.297 当前无法开启智慧巡航 系统，请擦拭摄像头								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socTJAICAFaultPlsFix, 			  	1.297 当前无法开启智慧巡航系统，请前往4S 店修理								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socWPCChargeZoneFront,			  	1.143 请确认前排手机充电区域是否有异物或者偏离								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socWPCChargeZoneRear, 			  	1.143 请确认后排手机充电区域是否有异物或者偏离								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socWPCChargeZoneRR,				1.143 请确认后排右侧手机充电区域是否有异物或者偏离								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socWPCChargeZoneRL,				1.143 请确认后排左侧手机充电区域是否有异物或者偏离								*/e_WarnReq_LcdAlarmOnce,

	//Tips
	/*WN_socAutoNaviExit,					1.247 xx公里/xx米后，将退出自动跟随导航驾驶								*/e_WarnReq_MaxNumber,
	/*WN_socAcceleratorPowen,				1.282 建议松开油门，进行能量回收										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socTurnSafeSlow,					1.203 过弯安全降速												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socNOHExit,						1.247 前方XX米，即将退出自动导航辅助									*/e_WarnReq_LcdAlarmOnce,
	/*WN_socNOHExitPlsTake,				  	1.247 前方XX米，即将退出自动导航辅助，请准备接管								*/e_WarnReq_ChimeNOHExitPlsTake,
	/*WN_socNOHFinishExit, 				  	1.247 自动导航辅助已完成，退出										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socOverSpeedNOHExit,			    1.247 若车速大于125km/h，自动导航辅助将退出								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socDriveIntoHighSpeed,			  	1.247 即将进入快速车道											*/e_WarnReq_LcdAlarmOnce,
	/*WN_socDriveIntoRamp, 				  	1.247 即将进入匝道												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socNOHSetAccSpeed,				  	1.247 自动导航辅助已自动调整巡航车速为XXkm/h								*/e_WarnReq_MaxNumber,
	/*WN_socLockNGearDisable,			    1.290 N挡已锁止\n无法换挡											*/e_WarnReq_LcdAlarmOnce,
	/*WN_socPlsPressBrakeTest, 			  	1.267 请轻踩制动，测试制动性能										*/e_WarnReq_LcdAlarmOnce,
	/*WN_soc4Aor4HModeSelect,				1.177 请选择4A/4H											*/e_WarnReq_LcdAlarmOnce,

   	/* WN_socBrakeSwitchFault,                1.12 1.13 1.14 制动液位开关故障									*/e_WarnReq_MaxNumber,
    //Secondary alarm
    //Tips0.68
    /*WN_socSafeBackStart,                   安全备用系统已启动												*/e_WarnReq_LcdAlarmOnce,
    /*WN_socSafeBackStopCar,                 安全备用系统即将靠边停车												*/e_WarnReq_LcdAlarmOnce,
    /*WN_socSwitchGearReleaseBrake,          1.11 请切换到非P挡释放驻车											*/e_WarnReq_MaxNumber,
    /*WN_socDM_EV_MuddyStart,                1.116 泥地模式已启动											*/e_WarnReq_MaxNumber,
    /*WN_socDM_EV_SandStart,                 1.116 沙地模式已启动											*/e_WarnReq_MaxNumber,
    /*WN_socDM_EV_SportPlusStart,            1.116 超级动力模式已启动											*/e_WarnReq_MaxNumber,
	/*WN_socOneTrunkBoardOpen 				  1.17/1.18  一体式车箱后板开报警							*/e_WarnReq_ChimeDoorOpenCheck,						
	/*WN_socSplitTrunkBoardOpen				  1.17/1.18  分体式车箱后板开报警							*/e_WarnReq_ChimeDoorOpenCheck,
	//Update for Warning table v0.71
			
	//Important alarm
	/*WN_socSlowFillingFlapOpenPicture	  	1.17/1.18 慢充充电口盖打开的效果示意图片							*/e_WarnReq_LcdAlarmOnce,
	/*WN_socQuickChargeFlapOpenPicture	  	1.17/1.18 快充充电口盖打开的效果示意图片							*/e_WarnReq_LcdAlarmOnce,
	/*WN_socSlowFillingFlapNotClosed		1.17/1.18 慢充口盖未关									*/e_WarnReq_LcdAlarmOnce,
	/*WN_socQuickChargeFlapNotClosed		1.17/1.18 快充口盖未关									*/e_WarnReq_LcdAlarmOnce,
	/*WN_socAttentionWaterRoad			  	1.262 请注意前方过水路面										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socAttentionLowlyingRoad 		  	1.262 请注意前方低洼路面										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socAttentionWetRoad				1.262 请注意前方湿滑路面										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socAttentionSharpTurn			  	1.262 请注意前方急转弯										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socNoteRoadFailure				  	1.262 请注意前方道路障碍										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socNoteUnevenRoad				  	1.262 请注意前方不平路面										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socAttentionDangerousRoad		  	1.262 请注意前方傍山险路										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socAwareDebrisFlow				  	1.262 请注意前方泥石流										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socNoteBridge					  	1.262 请注意前方桥梁										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socAttentionTunnel				  	1.262 请注意前方隧道										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socAwareFire 					 	1.262 请注意前方火灾										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socNoteFallingRock				  	1.262 请注意前方落石										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socNoteIcyRoad					  	1.262 请注意前方结冰路面										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socNoteCrosswindRoad 			  	1.262 请注意前方横风路段										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socEmbankmentRoad				  	1.262 请注意前方堤坝路段										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socNoteContinuousSharpTurn		  	1.262 请注意前方连续急转弯									*/e_WarnReq_LcdAlarmOnce,
	/*WN_socNoteRoadNarrows				  	1.262 请注意前方道路变窄										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socNoteIncomingTraffic			  	1.262 请注意前方车辆汇入										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socNotedamgeRoadFacities 		  	1.262 请注意前方道路设施损坏									*/e_WarnReq_LcdAlarmOnce,
	/*WN_socAwareScatteredObject			1.262 请注意前方散落物体										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socNOHIsResumed					1.273 NOH已恢复										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socMargeWatchOutFOrCarsComing	  	1.273 前方汇入，小心侧方来车									*/e_WarnReq_LcdAlarmOnce,
	/*WN_socSlowingDownForDischarge		  	1.273 正在减速，准备汇出										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socNOExitedTakeSteeringWheel 	  	1.273 NOH已退出，请接管方向盘									*/e_WarnReq_LcdAlarmOnce,
	/*WN_socLaneLineNotClearDriveCarefully  1.273 车道线不清晰，请小心驾驶									*/e_WarnReq_LcdAlarmOnce,
	/*WN_socFourWheelDriveSystem			1.301 四驱系统暂时锁定										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socCatcherSeriouslyBlocked		  	1.234 颗粒捕集器严重堵塞，请入站检查								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socChargingStatusDisplay 		  	充电状态显示（延时充电）										*/e_WarnReq_MaxNumber,
	//Secondary alarm
	/*WN_socExcessiveSpeedFourWheelDrive	  	1.301 车速过高四驱系统暂时解除锁定							*/e_WarnReq_LcdAlarmOnce,
	//Info
	/*WN_socNavigationSlowDownActive		  	1.302 导航降速已激活，请注意车速								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socPlsPayAttentionToSlowDown 	  		1.302 请注意减速										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socSpeedLimitForward60kmPerHour	  	1.302 前方导航限速60km/h，请注意减速						*/e_WarnReq_LcdAlarmOnce,
	/*WN_socSpeedLimitForward70kmPerHour	  	1.302 前方导航限速70km/h，请注意减速						*/e_WarnReq_LcdAlarmOnce,
	/*WN_socSPeedLimitForward80kmPerHour	  	1.302 前方导航限速80km/h，请注意减80						*/e_WarnReq_LcdAlarmOnce,
	/*WN_socSpeedLimitForward90kmPerHour	  	1.302 前方导航限速90km/h，请注意减速						*/e_WarnReq_LcdAlarmOnce,
	/*WN_socSpeedLimitForward100kmPerHour   	1.302 前方导航限速100km/h，请注意减速						*/e_WarnReq_LcdAlarmOnce,
	/*WN_socSpeedLimitForward110kmPerHour   	1.302 前方导航限速110km/h，请注意减速						*/e_WarnReq_LcdAlarmOnce,
	/*WN_socSpeedLimitForward120kmPerHour   	1.302 前方导航限速120km/h，请注意减速						*/e_WarnReq_LcdAlarmOnce,
	/*WN_socCurrentlyExceedNavigationLimit  	1.302 请注意当前设置车速超过导航限速							*/e_WarnReq_LcdAlarmOnce,
	/*WN_socTurnGearDownConfirmSpeedAdjustment  1.203 向下拨动怀挡，确认调整车速								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socPressCruiseConfirmAdjustment	  	1.203 按cruise键，确认调整车速							*/e_WarnReq_LcdAlarmOnce,
	/*WN_socComingOutMainRoad 			  	 	1.247 即将从主路汇出									*/e_WarnReq_LcdAlarmOnce,
	/*WN_socGoddessModeActivated			  	1.116 女神模式已启动									*/e_WarnReq_MaxNumber,

    //v0.71           
    
	/*WN_socWshngLiquidNotEnough			 1.306 洗涤液不足 请及时加注            						*/e_WarnReq_LcdAlarmOnce,
	/*WN_socUreaInsCantStartAfter 		 	 1.233 尿素不足，XXXkm后无法启动，请加注							*/e_WarnReq_LcdAlarmOnce,
	/*WN_socUreaInsSeriouslyCantStartAfter 	 1.233 尿素严重不足，xxxkm后无法启动，请加注						*/e_WarnReq_LcdAlarmOnce,
	/*WN_socUreaEmptyCantStartNext		  	 1.233 尿素罐空，下次无法启动，请加注								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socUreaEmptyCantStart			  	 1.233 尿素罐空，无法启动，请加注								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socUreaUnqualifyCantStartAfter	  	 1.233 尿素不合格，xxxkm后无法启动，请维修							*/e_WarnReq_LcdAlarmOnce,
	/*WN_socUreaUnqualifyCantStartNext	 	 1.233 尿素不合格，下次无法启动，请维修								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socUreaUnqualifyCantStart		  	 1.233 尿素不合格，无法启动，请维修								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socUreaFillStopCantStartAfter	  	 1.233 尿素喷射中断，xxxkm后无法启动，请维修						*/e_WarnReq_LcdAlarmOnce,
	/*WN_socUreaFillStopCantStartNext 	 	 1.233 尿素喷射中断，下次无法启动，请维修							*/e_WarnReq_LcdAlarmOnce,
	/*WN_socUreaFillStopCantStart 		 	 1.233 尿素喷射中断，无法启动，请维修								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socConsumDeviatCantStartAfter	  	 1.233 尿素消耗偏差，xxxkm后无法启动，请维修						*/e_WarnReq_LcdAlarmOnce,
	/*WN_socConsumDeviatCantStartNext 	 	 1.233 尿素消耗偏差，下次无法启动，请维修							*/e_WarnReq_LcdAlarmOnce,
	/*WN_socConsumDeviatCantStart 		 	 1.233 尿素消耗偏差，无法启动，请维修                              */e_WarnReq_LcdAlarmOnce,
	/*WN_socHoodClosedRestart 			 	 1.309 请关闭机舱盖后，重新启动车辆								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socOilTankClosedRestart			 1.310 请关闭油箱盖后，重新启动车辆								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socFaceFail						 TBD 人脸识别失败    		        						*/e_WarnReq_MaxNumber,							
	/*WN_socFaceInforNotEntered			  	 TBD 人脸信息未录入，请尝试其它方式登录     				            */e_WarnReq_MaxNumber,
	/*WN_socCSTActive 					 	 1.307 舒适制动功能已开启                     				*/e_WarnReq_MaxNumber,
	/*WN_socCSTClosed 					  	 1.307 舒适制动功能已关闭									*/e_WarnReq_MaxNumber,
	/*WN_socEVModeBattPowerLow			  	 1.109 车辆处于强制纯电模式，动力电池可用功率低          				*/e_WarnReq_LcdAlarmOnce,
	/*WN_socConnectedDischarging			 1.308 连接成功，正在放电      								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socConnectedNoDischarge			 1.308 连接成功，未放电										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socFrontTireAutoBack             	 TBD 前轮自动回正中										*/e_WarnReq_MaxNumber,	
	/*WN_socSteeringAutomaFuncsExits         TBD 方向盘自动回正功能退出									*/e_WarnReq_MaxNumber,
	/*WN_socEmergencyCallLimited             1.179 紧急呼叫功能受限 									*/e_WarnReq_LcdAlarmOnce,
    /*WN_socPowerLowStartEngine            	 1.314 动力电池电量低，请启动发动机用于放电							*/e_WarnReq_LcdAlarmOnce,
	/*WN_socFailedActivateDischarge        	 1.314 放电功能激活失败										*/e_WarnReq_LcdAlarmOnce,	
	/*WN_socPowerSystemLimited               1.102 动力电池系统受限										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socRearWheelSteeringFailure       	 1.312 后轮转向故障,请小心驾驶									*/e_WarnReq_LcdAlarmOnce,
	/*WN_socRearWheelSteeringLimited         1.312 后轮转向功能受限										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socETCSystemFault                   TBD ETC系统故障										*/e_WarnReq_MaxNumber,
	/*WN_socDischargeDeviceRemoved           1.80 放电装置已移除										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socETCNormal                        TBD ETC通行正常										*/e_WarnReq_MaxNumber,
	/*WN_socETCAbnormal                      TBD ETC通行异常										*/e_WarnReq_MaxNumber,
	/*WN_socExpresswayNormal                 TBD 您本次高速通行正常，预计消费 XX.XX元							*/e_WarnReq_MaxNumber,

	/*WN_socCurrentTerrainCannotUnlocked	 1.380 当前地形模式下不可解锁									*/e_WarnReq_LcdAlarmOnce,
	/*WN_socPowerBattWarmup				  	 1.382 动力电池预热中										*/e_WarnReq_MaxNumber,
	/*WN_socChargerFailure				 	 1.382 充电机故障										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socDisconnectChargingDischarging    1.81 请断开充/放电装置										*/e_WarnReq_LcdAlarmOnce,
	/*WN_socPowerOffAfterThreeMinute		 TBD 蓄电池电量过低，系统3分钟后关闭电源,请启动车辆	*/e_WarnReq_ChimePowerOffAfterThreeMinute,
	/*WN_socACCCCActive						 TBD ACC/CC激活：上下左右按键描述								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socACCCCCancel					 	 TBD ACC/CC取消：上下左右按键描述								*/e_WarnReq_LcdAlarmOnce,
	/*WN_socPleaseReadUserManual			 1.315 车门锁:行车过程中只能通过紧急开关开启,请参见用户手册 */e_WarnReq_LcdAlarmOnce,
	/*WN_socNoviceModel					     1.113 新手模式											*/e_WarnReq_MaxNumber,
	/*WN_socNoviceModelSelect 			     1.113 新手模式已选择										*/e_WarnReq_MaxNumber,
	/*WN_socNoviceModelSwitch 			     1.113 新手模式切换中，无法进入D/R/P挡	   						*/e_WarnReq_MaxNumber,

	//0.74 R18
	/*WN_socCrabModeFailure                    	 TBD 螃蟹模式故障														*/e_WarnReq_LcdAlarmOnce,
    /*WN_socFrontTireAlignFinishGEEP40           1.235 前轮回正完成(应用项目：GEEP4.0)										*/e_WarnReq_MaxNumber,
    /*WN_socFactoryPatternGEEP40                 TBD 工厂模式														*/e_WarnReq_LcdAlarmOnce,
    /*WN_socGalleryMode                          TBD 展厅模式														*/e_WarnReq_LcdAlarmOnce,
    /*WN_socStatBattLowTranModeGEEP40            1.8 运输模式(应用项目：GEEP4.0)											*/e_WarnReq_MaxNumber,
    /*WN_socStatBattLowComfortOffGEEP40          1.8 12V电源系统故障，舒适功能关闭，请联系4S店维修(应用项目：GEEP4.0)*/e_WarnReq_MaxNumber,
    /*WN_socStatBattLowSavingModeGEEP40          1.8 电量消耗过多，进入省电模式(应用项目：GEEP4.0)									*/e_WarnReq_MaxNumber,
    /*WN_socPowerOffAfterThreeMinuteGEEP40       1.8 蓄电池电量过低，系统3分钟后关闭电源，请启动车辆(应用项目：GEEP4.0)*/e_WarnReq_MaxNumber,
    /*WN_socChargingCoverOpen                    TBD 充电口盖已开启															*/e_WarnReq_LcdAlarmOnce,
    /*WN_socStatBattLowPwrReduceGEEP40           1.8 12V蓄电池电量低，舒适功能降功率(应用项目：GEEP4.0)									*/e_WarnReq_MaxNumber,
    /*WN_socInboundFailedContinueCruise          1.273 汇入失败，继续巡航														*/e_WarnReq_LcdAlarmOnce,
    /*WN_socApproachingRamp                      TBD xx公里/xx米后即将进入匝道													*/e_WarnReq_LcdAlarmOnce,
    /*WN_socCrabModeExitedGEEP40                 TBD 螃蟹模式已退出(应用项目：GEEP4.0)												*/e_WarnReq_MaxNumber,
    /*WN_socCrabModeEnabledGEEP40                TBD 螃蟹模式已开启(应用项目：GEEP4.0)												*/e_WarnReq_MaxNumber,
    /*WN_socCrabModeStandbyGEEP40                TBD 螃蟹模式已待机(应用项目：GEEP4.0)												*/e_WarnReq_MaxNumber,
    /*WN_socLowBatteryStartVehicle               1.311 动力电池电量较低，请及时启动车辆													*/e_WarnReq_LcdAlarmOnce,
    /*WN_socLowBatteryPlugGunCharge              1.311 动力电池电量较低，请及时启动车辆或插枪充电											*/e_WarnReq_LcdAlarmOnce,
    /*WN_socAuxiliaryOpenSingPedalUnable         1.168 驾驶辅助功能开启，单踏板不可用													*/e_WarnReq_LcdAlarmOnce,

	//0.75 R19
	
	//0.75 R19
	/*WN_socSmartCruiseouteEmergencyBrake,   	 1.210 智慧巡航已退出，紧急刹车辅助启动                                		    */e_WarnReq_ChimeSmartCruiseExit,
	/*WN_socSteerFailDrivelowSpeed    			 1.411 转向功能故障，请低速行驶(应用项目：GEEP4.0)                               */e_WarnReq_LcdAlarmOnce,
	/*WN_socSteerFailDriveCarefully				 1.411 转向功能受限，请小心驾驶(应用项目：GEEP4.0)				                */e_WarnReq_LcdAlarmOnce,
	/*WN_socSteeringAutoNotTouchWheel			 1.412 方向盘正在自动对齐，请勿触摸方向盘(应用项目：GEEP4.0)                          */e_WarnReq_LcdAlarmOnce,
	/*WN_socsteeringWheelAutoaLigned			 1.412 方向盘自动对齐完成(应用项目：GEEP4.0)				                    */e_WarnReq_MaxNumber,
	/*WN_socDM_B30_Novice						 1.113 新手模式												        */e_WarnReq_MaxNumber,
	/*WN_socFuelPrepare_Sound					 1.178 加油准备中(有声音)												*/e_WarnReq_LcdAlarmOnce,

	/*WN_socDrvConcentrate_inner = 900,    危险 请专心驾驶 ---内置DMS                                          */e_WarnReq_MaxNumber,
	/*WN_socDrvDrowsy_inner,               危险 请勿疲劳驾驶 ---内置DMS                                         */e_WarnReq_MaxNumber,
	/*WN_socFaceCancelled_inner,           人脸识别已取消 ---内置DMS                                           */e_WarnReq_MaxNumber,
	/*WN_socFaceNoMatch_inner,             未找到匹配人脸 ---内置DMS                                           */e_WarnReq_MaxNumber,
	/*WN_socFaceSuccess_inner,             人脸识别成功 ---内置DMS                                            */e_WarnReq_MaxNumber,
	//Popup                                                                                             */
	/*                                                                                                  */
	/*WN_socAdasInfoBegin = 1000,           adas 初始值                                                  */e_WarnReq_MaxNumber,
	/*WN_socStillTargetNotRecognized,      无法识别静止目标                                                   */e_WarnReq_MaxNumber,
	/*WN_socLaneChangeAssistTimeout,       变道辅助超时，请关闭转向灯                                         		*/e_WarnReq_MaxNumber,
	/*WN_socLaneChangeAssistCancelled,     变道辅助已取消                                                    */e_WarnReq_LcdAlarmOnce,
	/*WN_socLaneChangeAssistcompleted,     变道辅助已完成，请关闭转向灯                                       		*/e_WarnReq_MaxNumber,
	/*WN_socLaneChangeAssistIsNotSupported,车速太低 不支持变道辅助                                 	            */e_WarnReq_MaxNumber,
	/*WN_socACCCannotBeActivated,          自适应巡航无法激活                                                  */e_WarnReq_AccCruiseFailOnce,
	/*WN_socACCFunctionCanceled,           自适应巡航功能取消                                                  */e_WarnReq_AccCruiseQuitOnce,
	/*WN_socACCIsActivated,                自适应巡航已激活 请保持注意力                       		                */e_WarnReq_AccCruiseOkkeepAtOnce,
	/*WN_socTJAICACannotBeActivated,       智能巡航辅助无法激活                                                 */e_WarnReq_SmartCruiseFailOnce,
	/*WN_socTJAICAFunctionCanceled,        智能巡航辅助功能取消                                                 */e_WarnReq_SmartCruisQuitOnce,
	/*WN_socTJAICAIsActivated,             智能巡航已激活 请保持注意力并手握方向盘                                       */e_WarnReq_SmartCruiseOkhwOnce,
	/*WN_socTJAICANeedsToVehicleRestart,   智能巡航辅助需车辆重新启动后使用                                           */e_WarnReq_LcdAlarmOnce,
	/*WN_socFrontVehicleHasStarted,        前车已起步                                                      */e_WarnReq_FCOKOnce,
	/*WN_socPlsPayAttentionToTheRoadAhead, 前车已起步,请注意前方道路环境                                            */e_WarnReq_FCOKAttRoadEnvOnce,
	/*WN_socPlsKeepYourAttention,          前车已起步,请保持注意力                                               */e_WarnReq_FCOKKeepAtOnce,
	/*WN_socPlsTakeOverTheVehicle,         前车已起步,请接管车辆                                                */e_WarnReq_FCOKTakeCarOnce,
	/*WN_socTheTimeGap,                    车间时距                                                       */e_WarnReq_MaxNumber,
	/*WN_socLeftLaneChangeNotSupported     左侧不支持变道													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socRightLaneChangeNotSupported    右侧不支持变道													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socLeftLaneChangeIsAboutToPerformed  即将向左变道，请手扶方向盘											*/e_WarnReq_MaxNumber,
	/*WN_socRightLaneChangeIsAboutToPerformed 即将向右变道，请手扶方向盘											*/e_WarnReq_MaxNumber,
	/*WN_socNOHIsActivated                   自动跟随导航驾驶已启动												*/e_WarnReq_NOHIsActivated,
	/*WN_socPleaseConfirmLeftLaneChange      请拨杆确认左变道													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socPleaseConfirmRightLaneChange     请拨杆确认右变道													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socToOvertakeFromLeft               即将向左变道													*/e_WarnReq_MaxNumber,
	/*WN_socToOvertakeFromRight              即将向右变道													*/e_WarnReq_MaxNumber,
	/*WN_socLaneChangeWaiting                等待后方车辆通过													*/e_WarnReq_MaxNumber,
	/*WN_socToMergeInMainroad                即将汇入主路													*/e_WarnReq_MaxNumber,
	/*WN_socPayAttentionToTheRedLightAhead,  注意前方红灯													*/e_WarnReq_LcdAlarmOnce,
    /*WN_socSpeedIsTooLowToSupportLaneChange,车速过低，变道辅助不可用												*/e_WarnReq_MaxNumber,
    /*WN_socSpeedIsTooHighToSupportLaneChange, 				车速过高，变道辅助不可用								*/e_WarnReq_MaxNumber,
    /*WN_socPlsRestartOrShiftToPGearToActiveTheFunction,    智慧巡航辅助需车辆重新启动或挂P挡后使用						*/e_WarnReq_LcdAlarmOnce,
    /*WN_socSafetyAvoidance,                                安全避让										*/e_WarnReq_MaxNumber,
    /*WN_socLeftOvertaking,                                 即将向左超车									*/e_WarnReq_MaxNumber,
    /*WN_socRightOvertaking,                                即将向右超车									*/e_WarnReq_MaxNumber,
	/*WN_socConstructionSiteShead         前方施工路段，请注意安全												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socLargeVehiclesWarn            大车较多，请小心一点													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socNightWarning                  好黑啊，请小心驾驶													*/e_WarnReq_MaxNumber,
	/*WN_socAdverseWeatherWarning         雨天路滑，请小心驾驶												*/e_WarnReq_MaxNumber,
	/*WN_socPlsTryALCLater                当前无法开启变道功能，请稍后尝试											*/e_WarnReq_LcdAlarmOnce,
	/*WN_socLaneChangeIsCannelled         当前持续无法变道，稍后尝试												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socLaneChangeAborted             太危险，先不变道了													*/e_WarnReq_LcdAlarmOnce,

	/*WN_socEnvironmentNotSupported       环境条件不满足，请稍后尝试												*/e_WarnReq_EnvNotSup,
	/*WN_socPlsKeepFocusTryAgain          请保持专注驾驶，再次尝试开启											*/e_WarnReq_KeepFocusTryAgain,
	/*WN_socPlsHandsOnthewheelTryAgain    请保持手握方向盘，再次尝试开启											*/e_WarnReq_PlsHandsWheelTryAgain,
	/*WN_socPlsfastenseatbelt             请系紧安全带													*/e_WarnReq_Plsfastenseatbelt,													
	/*WN_socPlsShutTheDoor                请关闭车门														*/e_WarnReq_PlsShutTheDoor,
	/*WN_socRainyIsActivated              雨天模式已激活													*/e_WarnReq_MaxNumber,
	/*WN_socRainyFunctionCanceled         雨天模式已退出													*/e_WarnReq_MaxNumber,
	/*WN_socPlsfastenPassengerseatbelt    请副驾驶系紧安全带													*/e_WarnReq_PlsfastenPassSeatbelt,
	/*WN_socACCForbiddenduetoASLActive    1.199 主动限速开启，巡航不可用                                       */e_WarnReq_LcdAlarmOnce,
	/*WN_socPlsGentlyStepOnTheAccelerator       1.202 请轻踩油门确认起步										*/e_WarnReq_LcdAlarmOnce,										
	/*WN_socRestartAndTryAgain           		1.304 重新启动后再次尝试									TBD	*/e_WarnReq_MaxNumber,
	/*WN_socPlsEpairLaneChangeFunctionIsNotAvailable 1.304 变道功能不可用，请前往修理						TBD	 */e_WarnReq_MaxNumber,
	/*WN_socCancelForLongOverride         1.304 时间踩油门，智慧巡航已退出									TBD	*/e_WarnReq_MaxNumber,
	/*WN_socCancelForLatOverride          1.304 长时间控制方向盘，智慧巡航已退出							TBD	*/e_WarnReq_MaxNumber,
	/*WN_socAvoidObstacle                 1.304 躲避障碍物中													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socIntelligentSpeedControlHasBeenStarted 智慧控速已启动，车辆将按照道路限速行驶						  */e_WarnReq_LcdAlarmOnce,
	/*WN_socFollowConfirm                 1.304 请自行控制车辆													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socOverSpeed                     1.304 超过道路限速，请谨慎驾驶										 */e_WarnReq_LcdAlarmOnce,
	/*WN_socLCNotCancel                   1.304 当前变道不可取消												*/e_WarnReq_LcdAlarmOnce,
	/*WN_socAdverseWeather                1.304 天气恶劣，变道功能禁用											 */e_WarnReq_LcdAlarmOnce,
	/*WN_socSystemFault                   1.304 系统故障，退出智慧巡航										TBD	 */e_WarnReq_MaxNumber,
	/*WN_socNOHFault                      1.304 故障无法激活											   TBD	*/e_WarnReq_MaxNumber,
	/*WN_socNOHStandby                    1.304 NOH可开启														*/e_WarnReq_LcdAlarmOnce,
	/*WN_socNOHDegrade                    1.304 已切换智慧巡航功能												 */e_WarnReq_LcdAlarmOnce,
	/*WN_socAdverseWeatherLater           1.304 天气恶劣，稍后尝试变道											 */e_WarnReq_LcdAlarmOnce,
	/*WN_socFunctionInhibit               1.304 变道功能禁用													*/e_WarnReq_LcdAlarmOnce,
	/*WN_socAutoSpd                       1.304 智能控速已开启，车辆将按照道路限速行驶							  */e_WarnReq_LcdAlarmOnce,
	/*WN_socNOHInhibit                    1.304 NOH功能禁用                                                     */e_WarnReq_LcdAlarmOnce,
#endif
};

static const s_ChimeProcessFunParameter_t ChimeProcessFunParameter_t[] =
{
	{SWC_ChimePasCheck,					SWC_ChimePasCancel,					(CHIME_FUN_RUN_POWER_ON),	0},
	{SWC_ChimeCDPCheck,					SWC_ChimeCDPCancel,					(CHIME_FUN_RUN_POWER_ON),	0},
	{SWC_ChimeRSDSCheck,				SWC_ChimeRSDSCancel,				(CHIME_FUN_RUN_POWER_ON | CHIME_FUN_RUN_POWER_OFF),	3000},
	{SWC_ChimeLWD_LKACheck,				SWC_ChimeLWD_LKACancel,				(CHIME_FUN_RUN_POWER_ON ),	3000},
	{SWC_ChimeTSRCheck,					SWC_ChimeTSRCancel,					(CHIME_FUN_RUN_POWER_ON),	3000},
	{SWC_ChimeFELDCheck,				SWC_ChimeFELDCancel,				(CHIME_FUN_RUN_POWER_ON),	0},
	{SWC_ChimeRELDCheck,				SWC_ChimeRELDCancel,				(CHIME_FUN_RUN_POWER_ON),	0},
	{SWC_ChimeHVolDoorEVCheck,			SWC_ChimeHVolDoorEVCancel,			(CHIME_FUN_RUN_POWER_ON),	0},
	{SWC_ChimeHVolDoorPHEVCheck,		SWC_ChimeHVolDoorPHEVCancel,		(CHIME_FUN_RUN_POWER_ON),	0},
	{SWC_ChimeHVolDoorRE300Check,		SWC_ChimeHVolDoorRE300Cancel,		(CHIME_FUN_RUN_POWER_ON),	0},
	{SWC_ChimePandCheckD7DCTCheck,		SWC_ChimePandCheckD7DCTCancel,		(CHIME_FUN_RUN_POWER_ON),	0},
	{SWC_ChimePandCheckD9DCTCheck,		SWC_ChimePandCheckD9DCTCancel,		(CHIME_FUN_RUN_POWER_ON),	0},
	{SWC_ChimePandCheckD8ATCheck,		SWC_ChimePandCheckD8ATCancel,		(CHIME_FUN_RUN_POWER_ON),	0},
	{SWC_ChimePandCheckDPHEVCheck,		SWC_ChimePandCheckDPHEVCancel,		(CHIME_FUN_RUN_POWER_ON),	0},
	{SWC_ChimePandCheckDEVCheck,		SWC_ChimePandCheckDEVCancel,		(CHIME_FUN_RUN_POWER_ON),	0},
	{SWC_ChimeACC_TJA_ICACheck,			SWC_ChimeACC_TJA_ICACancel,			(CHIME_FUN_RUN_POWER_ON),	3000},
	{SWC_ChimePowerBatWarmCheck,		SWC_ChimePowerBatWarmCancel,		(CHIME_FUN_RUN_POWER_ON | CHIME_FUN_RUN_POWER_OFF),	3000},
	{SWC_ChimeLDWLKAELKLCKCheck,		SWC_ChimeLDWLKAELKLCKCancel,		(CHIME_FUN_RUN_POWER_ON),	3000},
	{SWC_ChimeTickTockLEDCheck,			SWC_ChimeTickTockLEDCancel,			(CHIME_FUN_RUN_POWER_ON | CHIME_FUN_RUN_POWER_OFF),	0},
	{SWC_ChimeDWDCheck,					SWC_ChimeDWDCancel,					(CHIME_FUN_RUN_POWER_ON),	0},
	{SWC_ChimeChargeFaultCheck,			SWC_ChimeChargeFaultCancel,			(CHIME_FUN_RUN_POWER_ON | CHIME_FUN_RUN_POWER_OFF),	0},
	{SWC_ChimeSleepCheck,				SWC_ChimeSleepCancel,				(CHIME_FUN_RUN_POWER_SLEEP | CHIME_FUN_RUN_POWER_ABNORMAL),	0	},
	{SWC_ChimeCELDCheck,				SWC_ChimeCELDCancel,				(CHIME_FUN_RUN_POWER_ON),	3000},
	{CHIME_PROCESS_FUN_NULL,			CHIME_PROCESS_FUN_NULL,				0x00,						0},
};

static const s_CHimeReqBit2Chime_t CHimeReqBit2ChimeTbl[e_SoundBuffer_NumberOfChimes] =
{
	{CHIME_RSDS_POSITION_ALL,                                                                             e_SoundType_IdleMode,           CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_RadarRFail3Times,                                                   后倒车雷达故障-3次*/
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarRFail3Times,     CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarRFail3Times,     CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarRFail3Times,     CHIME_SOUND_REQUEST_BIT02    },
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarRFail3Times,     CHIME_SOUND_REQUEST_BIT03    },
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarRFail3Times,     CHIME_SOUND_REQUEST_BIT04    },
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarRFail3Times,     CHIME_SOUND_REQUEST_BIT05    },
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarRFail3Times,     CHIME_SOUND_REQUEST_BIT06    },
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarRFail3Times,     CHIME_SOUND_REQUEST_BIT07    },

/*	e_SoundType_RadarFFail3Times,                                                   前车雷达故障-3次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarFFail3Times,     CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarFFail3Times,     CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarFFail3Times,     CHIME_SOUND_REQUEST_BIT02    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarFFail3Times,     CHIME_SOUND_REQUEST_BIT03    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarFFail3Times,     CHIME_SOUND_REQUEST_BIT04    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarFFail3Times,     CHIME_SOUND_REQUEST_BIT05    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarFFail3Times,     CHIME_SOUND_REQUEST_BIT06    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarFFail3Times,     CHIME_SOUND_REQUEST_BIT07    },

/*	e_SoundType_RadarSDWFail3Times,                                                 SDW雷达故障-3次*/
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarSDWFail3Times,   CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarSDWFail3Times,   CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarSDWFail3Times,   CHIME_SOUND_REQUEST_BIT02    },
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarSDWFail3Times,   CHIME_SOUND_REQUEST_BIT03    },
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarSDWFail3Times,   CHIME_SOUND_REQUEST_BIT04    },

/*	e_SoundType_APAOnce,                                                            APA声音提示-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_APAOnce,              CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_APAOnce,              CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_APAOnce,              CHIME_SOUND_REQUEST_BIT02    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_APAOnce,              CHIME_SOUND_REQUEST_BIT03    },
/*	e_SoundType_RadarRLongRe,                                                       后倒车雷达Long-重复*/
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarRLongRe,         CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarRLongRe,         CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarRLongRe,         CHIME_SOUND_REQUEST_BIT02    },
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarRLongRe,         CHIME_SOUND_REQUEST_BIT03    },
/*	e_SoundType_RadarFLongRe,                                                       前车雷达Long-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarFLongRe,         CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarFLongRe,         CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarFLongRe,         CHIME_SOUND_REQUEST_BIT02    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarFLongRe,         CHIME_SOUND_REQUEST_BIT03    },
/*	e_SoundType_RadarSDWLongRe,                                                     SDW雷达Long-重复*/
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarSDWLongRe,       CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_RadarDWDLongRe,                                                     涉水深度DWDLong-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarDWDLongRe,       CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_RadarRSDS4Hz,														RSDS侧后辅助系统声音-4HZ_重复*/
	{CHIME_RSDS_POSITION_VFR,                                                                             e_SoundType_RadarRSDS4Hz,         CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL,                                                                             e_SoundType_RadarRSDS4Hz,         CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VRR,                                                                             e_SoundType_RadarRSDS4Hz,         CHIME_SOUND_REQUEST_BIT02    },
	{CHIME_RSDS_POSITION_VFL,                                                                             e_SoundType_RadarRSDS4Hz,         CHIME_SOUND_REQUEST_BIT03    },
	{CHIME_RSDS_POSITION_VFR,                                                                             e_SoundType_RadarRSDS4Hz,         CHIME_SOUND_REQUEST_BIT04    },
	{CHIME_RSDS_POSITION_VRL,                                                                             e_SoundType_RadarRSDS4Hz,         CHIME_SOUND_REQUEST_BIT05    },
	{CHIME_RSDS_POSITION_ALL,																			  e_SoundType_RadarRSDS4Hz, 		CHIME_SOUND_REQUEST_BIT06	 },
	{CHIME_RSDS_POSITION_NULL,																			  e_SoundType_RadarRSDS4Hz, 		CHIME_SOUND_REQUEST_BIT07	 },
/*	e_SoundType_RadarRSDS3Hz,                                                       RSDS侧后辅助系统声音-3HZ_重复*/
	{CHIME_RSDS_POSITION_VRR,                                                   						  e_SoundType_RadarRSDS3Hz,         CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VRL,                                                  							  e_SoundType_RadarRSDS3Hz,         CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VRR,                                                   						  e_SoundType_RadarRSDS3Hz,         CHIME_SOUND_REQUEST_BIT02    },
	{CHIME_RSDS_POSITION_VRL,                                                   						  e_SoundType_RadarRSDS3Hz,         CHIME_SOUND_REQUEST_BIT03    },
	{CHIME_RSDS_POSITION_ALL,                                                                             e_SoundType_RadarRSDS3Hz,         CHIME_SOUND_REQUEST_BIT04    },
	{CHIME_RSDS_POSITION_NULL,                                                                            e_SoundType_RadarRSDS3Hz,         CHIME_SOUND_REQUEST_BIT05    },
/*	e_SoundType_RadarF4HZ,                                                          前雷达4Hz-4HZ_重复*/
/*	e_SoundType_RadarR3HZ,                                                          后倒车雷达3Hz-3HZ_重复*/
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarR3HZ,            CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarR3HZ,            CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarR3HZ,            CHIME_SOUND_REQUEST_BIT02    },
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarR3HZ,            CHIME_SOUND_REQUEST_BIT03    },
/*	e_SoundType_RadarF3Hz,                                                          前车雷达3Hz-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarF3Hz,            CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarF3Hz,            CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarF3Hz,            CHIME_SOUND_REQUEST_BIT02    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarF3Hz,            CHIME_SOUND_REQUEST_BIT03    },
/*	e_SoundType_RadarSDW3Hz,                                                        SDW3Hz-重复*/
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarSDW3Hz,          CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_RadarDWD3HZRe,                                                     涉水深度DWD 3HZ-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarDWD3Hz,          CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_RadarR2Hz,                                                          后雷达2Hz-重复*/
/*	e_SoundType_LDW_LKAOnce,                                                        LDW&LKA声音提示-重复*/
	{CHIME_RSDS_POSITION_VFL,                                                                             e_SoundType_LDW_LKAOnce,          CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFR,                                                                             e_SoundType_LDW_LKAOnce,          CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LDW_LKAOnce,          CHIME_SOUND_REQUEST_BIT02    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LDW_LKAOnce,          CHIME_SOUND_REQUEST_BIT03    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LDW_LKAOnce,          CHIME_SOUND_REQUEST_BIT04    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LDW_LKAOnce,          CHIME_SOUND_REQUEST_BIT05    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LDW_LKAOnce,          CHIME_SOUND_REQUEST_BIT06    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LDW_LKAOnce,          CHIME_SOUND_REQUEST_BIT07    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LDW_LKAOnce,          CHIME_SOUND_REQUEST_BIT08    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LDW_LKAOnce,          CHIME_SOUND_REQUEST_BIT09    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LDW_LKAOnce,          CHIME_SOUND_REQUEST_BIT10    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LDW_LKAOnce,          CHIME_SOUND_REQUEST_BIT11    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LDW_LKAOnce,          CHIME_SOUND_REQUEST_BIT12    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LDW_LKAOnce,          CHIME_SOUND_REQUEST_BIT13    },
	{CHIME_RSDS_POSITION_NULL,                                                                            e_SoundType_LDW_LKAOnce,          CHIME_SOUND_REQUEST_BIT14    },
/*	e_SoundType_RadarR1_5Hz,                                                        后倒车雷达1.5Hz-重复*/
	{CHIME_RSDS_POSITION_VRL | CHIME_RSDS_POSITION_VRR,                                                   e_SoundType_RadarR1_5Hz,          CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VRL | CHIME_RSDS_POSITION_VRR,                                                   e_SoundType_RadarR1_5Hz,          CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VRL | CHIME_RSDS_POSITION_VRR,                                                   e_SoundType_RadarR1_5Hz,          CHIME_SOUND_REQUEST_BIT02    },
	{CHIME_RSDS_POSITION_VRL | CHIME_RSDS_POSITION_VRR,                                                   e_SoundType_RadarR1_5Hz,          CHIME_SOUND_REQUEST_BIT03    },
/*	e_SoundType_RadarF1_5Hz,                                                        前车雷达1.5Hz-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarF1_5Hz,          CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarF1_5Hz,          CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarF1_5Hz,          CHIME_SOUND_REQUEST_BIT02    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarF1_5Hz,          CHIME_SOUND_REQUEST_BIT03    },
/*	e_SoundType_RadarSDW1_5Hz,                                                      SDW1.5Hz-重复*/
	{CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_VRL,                                                   e_SoundType_RadarSDW1_5Hz,        CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_RadarDWD1_5HZRe,                                                    涉水深度DWD 1.5HZ-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RadarDWD1_5Hz,        CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_RadarR1Hz,                                                          后雷达-1Hz-3次*/
/*	e_SoundType_RadarF1Hz,                                                          前雷达-1Hz-3次*/
/*	e_SoundType_LeaveCar4Hz,                                                        危险！请立即远离车辆！-4HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LeaveCar4Hz,          CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_StopCar4Hz,                                                         危险！请安全停车并立即远离车辆-4HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_StopCar4Hz,           CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_SteeringActRe,                                                      紧急转向避让辅助激活-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_SteeringActRe,        CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_AutoSteeringActRe,                                                  自动紧急转向避让辅助激活-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_AutoSteeringActRe,    CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_AutoBrakePersonRe,                                                  自动紧急制动启动+行人图片-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_AutoBrakePersonRe,    CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_AutoBrakeCarRe,                                                     自动紧急制动启动+车辆图片-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_AutoBrakeCarRe,       CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_AuxiliaryBrakeRe,                                                   交叉路口辅助制动启动+车辆图片-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_AuxiliaryBrakeRe,     CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_CrossSideBrakeRe,                                                   前横穿侧向制动启动+车辆图片-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CrossSideBrakeRe,     CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_RSideBrakeRe,                                                       倒车侧向制动启动+车辆图片-重复*/
	{CHIME_RSDS_POSITION_ALL | CHIME_RSDS_POSITION_CENTER,                                                e_SoundType_RSideBrakeRe,         CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_TakeBrakeAcc4Hz,                                                    请踩刹车（自适应巡航）-4HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TakeBrakeAcc4Hz,      CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_TakeBrakeFCWRe,                                                     请踩刹车（FCW）-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TakeBrakeFCWRe,       CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_TakeBrakeFCrossRe,                                                  请踩刹车（前横穿侧向警告）-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TakeBrakeFCrossRe,    CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_TakeSteering4Hz,                                                    请手握方向盘-4HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TakeSteering4Hz,      CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TakeSteering4Hz,      CHIME_SOUND_REQUEST_BIT01    },
/*	e_SoundType_TakeSteering2Hz,                                                    请手握方向盘-2HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TakeSteering2Hz,      CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_TakeSteering1Hz,                                                    请手握方向盘-1HZ_3次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TakeSteering1Hz,      CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_KeepDistance,                                                       请保持安全距离-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_KeepDistance,         CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_TakeCar4Hz,                                                         请接管车辆-4HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TakeCar4Hz,           CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_TakeCar2Hz,                                                         请接管车辆-2HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TakeCar2Hz,           CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_TakeCar1Hz,                                                         请接管车辆-1HZ_3次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TakeCar1Hz,           CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_AssistExit4Hz,                                                      车道辅助系统退出请接管车辆-4HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_AssistExit4Hz,        CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_AssistExit4Hz,                                                      智慧巡航已退出，紧急刹车辅助启动-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_SmartCruiseExit,      CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_KeepPoint4Hz,                                                       请保持注意力-4HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_KeepPoint4Hz,         CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_KeepPoint2Hz,                                                       请保持注意力-2HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_KeepPoint2Hz,         CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_KeepPointOnce,                                                      请保持注意力-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_KeepPointOnce,        CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_CheckP0_5Hz,                                                        请选择P挡-0.5HZ_60S*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CheckP0_5Hz,          CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_CarDistancce,                                                       请注意前车距离-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CarDistancce,         CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_Pedestrian                                                          请注意避让行人-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_Pedestrian,           CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_Pedestrian,           CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_Pedestrian,           CHIME_SOUND_REQUEST_BIT02    },
/*  e_SoundType_FaceCar,                                                            注意对向来车-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_FaceCar,           	CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_CrosswiseCar,                                                       注意横向来车-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CrosswiseCar,         CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CrosswiseCar,         CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CrosswiseCar,         CHIME_SOUND_REQUEST_BIT02    },
/*  e_SoundType_FrontCarAEB,                                                        前方车辆紧急制动-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_FrontCarAEB,         	CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_FrontCarUnContron,                                                  注意前方失控车辆-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_FrontCarUnContron,    CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_BackCarUnContron,                                                   注意后方失控车辆-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_BackCarUnContron,    	CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_AroundCarUnContron,                                                 注意周围失控车辆-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_AroundCarUnContron,   CHIME_SOUND_REQUEST_BIT00    },	
/*  e_SoundType_PlsTakeOver4Hz,                                                     请立即接管-4HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_PlsTakeOver4Hz,   	CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_PlsTakeOver2Hz                                                      请立即接管-2HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_PlsTakeOver2Hz,   	CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_PlsTakeOver1Hz                                                      请立即接管-1hz_3次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_PlsTakeOver1Hz,   	CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_CarAutoBrakePlsTake                                                 车辆正在自动刹停，请立即接管-重复*/	
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CarAutoBrakePlsTake,  CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_CarParkingPlsTake                                                   车辆正在靠边停车，请立即接管-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CarParkingPlsTake,   	CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_CarUrgeBrakePlsTake                                                 车辆正在紧急刹停，请立即接管-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CarUrgeBrakePlsTake,  CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_MoveRampFailPlsTake                                                  驶入匝道失败，请立即接管-重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_MoveRampFailPlsTake,  CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_MoveMainFailPlsTake4Hz                                               汇入主路失败，请立即接管-4HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_MoveMainFailPlsTake4Hz,CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_MoveMainFailPlsTake2Hz                                               汇入主路失败，请立即接管-2HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_MoveMainFailPlsTake2Hz,CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_MoveMainFailPlsTake1Hz                                               汇入主路失败，请立即接管-1HZ_3次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_MoveMainFailPlsTake1Hz,CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_TurnFailPlsTake4Hz                                                   转弯失败，请立即接管-4HZ_重复*/	
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TurnFailPlsTake4Hz,	CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_TurnFailPlsTake2Hz                                                   转弯失败，请立即接管-2HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TurnFailPlsTake2Hz,	CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_TurnFailPlsTake1Hz                                                   转弯失败，请立即接管-1HZ_3次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TurnFailPlsTake1Hz,	CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_TollGateFailPlsTake4Hz                                               无法成功通过收费站，请立即接管-4HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TollGateFailPlsTake4Hz,CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_TollGateFailPlsTake2Hz                                               无法成功通过收费站，请立即接管-2HZ_重复*/	
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TollGateFailPlsTake2Hz,CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_TollGateFailPlsTake1Hz                                               无法成功通过收费站，请立即接管-1HZ_3次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TollGateFailPlsTake1Hz,CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_RoundaboutFailPlsTake4Hz                                             无法成功通过环岛，请立即接管-4HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RoundaboutFailPlsTake4Hz,CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_RoundaboutFailPlsTake2Hz                                             无法成功通过环岛，请立即接管-2HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RoundaboutFailPlsTake2Hz,CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_RoundaboutFailPlsTake1Hz                                             无法成功通过环岛，请立即接管-1HZ_3次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RoundaboutFailPlsTake1Hz,CHIME_SOUND_REQUEST_BIT00    },	
/*  e_SoundType_MoveRampFailHandWheel_2Hz,                                          驶入匝道失败，请控制方向盘-2Hz_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_MoveRampFailHandWheel_2Hz, CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_MoveRampFailHandWheel,												驶入匝道失败，请控制方向盘-1Hz_3次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_MoveRampFailHandWheel, CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_MoveMainFailHandWheel,												汇入主路失败，请控制方向盘-1Hz_3次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_MoveMainFailHandWheel, CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_TurnFailPlsHandWheel,												转弯失败，请控制方向盘-1Hz_3次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TurnFailPlsHandWheel, CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_TollGateFailPlsHandWheel,											无法成功通过收费站，请控制方向盘-1Hz_3次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TollGateFailPlsHandWheel, CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_RoundaboutFailPlsHandWheel											无法成功通过环岛，请控制方向盘-1Hz_3次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RoundaboutFailPlsHandWheel, CHIME_SOUND_REQUEST_BIT00    },	
/*	e_SoundType_Tpms1Hz,                                                            胎压报警声音提示-1HZ_3次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_Tpms1Hz,              CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_HybridFail1Hz,                                                      混合动力系统故障报警音-1HZ_3次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_HybridFail1Hz,        CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_HybridFail1Hz,        CHIME_SOUND_REQUEST_BIT01    },
/*	e_SoundType_Seatbelt0_5Hz,                                                      安全带未系-0.5HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_Seatbelt0_5Hz,        CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_battery_low0_5Hz,                                                     蓄电池电量过低，系统3分钟后关闭电源，请启动车辆-0.5HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_battery_low0_5Hz,        CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_DoorOpen1_5Hz,                                                      车门打开声音提示-1.5HZ_60S*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_DoorOpen1_5Hz,        CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_DoorOpen1_5Hz,        CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_DoorOpen1_5Hz,        CHIME_SOUND_REQUEST_BIT02    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_DoorOpen1_5Hz,        CHIME_SOUND_REQUEST_BIT03    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_DoorOpen1_5Hz,        CHIME_SOUND_REQUEST_BIT04    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_DoorOpen1_5Hz,        CHIME_SOUND_REQUEST_BIT05    },
/*   e_SoundType_DoorOpen1_Once,													车门打开声音提示-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_DoorOpen1_Once,       CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_DynamicBrake0_5Hz,                                                  动态制动报警提示-0.5HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_DynamicBrake0_5Hz,    CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_DynamicBrake0_5Hz,    CHIME_SOUND_REQUEST_BIT01    },
/*	e_SoundType_HandBrake0_5Hz,                                                     手刹未松报警提示-0.5HZ_重复*/
/*	e_SoundType_PositionTickOnce,                                                   双闪提示音Click-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_PositionTickOnce,     CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_PositionTockOnce,                                                   双闪提示音Clack-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_PositionTockOnce,     CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_TurnLeftTickOnce,                                                   左转向声音提示Click-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TurnLeftTickOnce,     CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_TurnLeftTockOnce,                                                   左转向声音提示Clalk-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TurnLeftTockOnce,     CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_TurnRightTickOnce,                                                  右转向声音提示Click-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TurnRightTickOnce,    CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_TurnRightTockOnce,                                                  右转向声音提示Clalk-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TurnRightTockOnce,    CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_OverSpeed1Hz,                                                       120km/h超速报警声音提示-1HZ_10S*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_OverSpeed1Hz,         CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_India120Speed1Hz,                                                   印度超速报警（二级：120km/h）-1HZ_重复*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_India120Speed1Hz,     CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_India80Speed1Hz,                                                    印度超速报警（一级：80km/h）-1HZ_10S*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_India80Speed1Hz,      CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_OverSpeedAlarm1Hz,                                                  超速提醒报警声音提示-1HZ_3S*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_OverSpeedAlarm1Hz,    CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_TsrOnce,                                                            限速报警标志提示声音-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TsrOnce,              CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_FLockOnce,                                                          前桥差速锁声音报警-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_FLockOnce,            CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_FLockOnce,            CHIME_SOUND_REQUEST_BIT01    },
/*	e_SoundType_RLockOnce,                                                          后桥差速锁声音报警-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RLockOnce,            CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RLockOnce,            CHIME_SOUND_REQUEST_BIT01    },
/*	e_SoundType_CLockOnce,                                                          中央差速锁声音报警-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CLockOnce,            CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CLockOnce,            CHIME_SOUND_REQUEST_BIT01    },
/*	e_SoundType_LightOn0_5Hz,                                                       灯光未关-0.5HZ_60S*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LightOn0_5Hz,         CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_TunnelTakeCarOnce,                                                  前方即将穿过隧道,请及时接管车辆-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TunnelTakeCarOnce,    CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_RoadTakeCarOnce,                                                    前方存在分叉路口，请及时接管车辆-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RoadTakeCarOnce,      CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_ModeFailOnce,                                                       模式切换失败，请熄火重试-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_ModeFailOnce,         CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_HcExitTakeDirOnce,                                                  横向控制已退出，请控制方向-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_HcExitTakeDirOnce,    CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_NOHExitPlsTake,                                                  	前方XX米，即将退出自动导航辅助，请准备接管*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_NOHExitPlsTake,    	CHIME_SOUND_REQUEST_BIT00    },	
/*	e_SoundType_RCarSpeedHigh1Hz,                                                   后方车辆车速过高-1HZ_3S*/
	{CHIME_RSDS_POSITION_VRL | CHIME_RSDS_POSITION_VRR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_RCarSpeedHigh1Hz,     CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_4LModeOnce,                                                         4L模式请减速慢行-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_4LModeOnce,           CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_PowerOnOnce,                                                        已上电可挂挡行驶-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_PowerOnOnce,          CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_PleaseRestOnce,                                                     请注意休息-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_PleaseRestOnce,       CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_PleaseRest1Hz,                                                      请注意休息-1HZ_3S*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_PleaseRest1Hz,        CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_CruiseActOnce,                                                      巡航类功能激活-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CruiseActOnce,        CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CruiseActOnce,        CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CruiseActOnce,        CHIME_SOUND_REQUEST_BIT02    },
/*	e_SoundType_LckActOnce,                                                         LCK功能激活-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LckActOnce,           CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_CruiseDownOnce,                                                     巡航类功能降级-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CruiseDownOnce,       CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CruiseDownOnce,       CHIME_SOUND_REQUEST_BIT01    },
/*	e_SoundType_CruiseStartOnce,                                                    巡航类功能启动-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CruiseStartOnce,      CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CruiseStartOnce,      CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CruiseStartOnce,      CHIME_SOUND_REQUEST_BIT02    },
/*	e_SoundType_LeftSmartdodgeOnce,                                                 左侧智慧躲闪-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_CENTER,                                                e_SoundType_LeftSmartdodgeOnce,   CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_RightSmartdodgeOnce,                                                右侧智慧躲闪-单次*/
	{CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                                                e_SoundType_RightSmartdodgeOnce,  CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_VehicleDevRepeate,													车辆偏离请控制方向盘-持续*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_VehicleDevRepeate,    CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_UrgeTurnPlsHoldWheel,												 前方急转弯，请手扶方向盘*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_UrgeTurnPlsHoldWheel, CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_SafeDrivRepeat, 													车道辅助系统持续控制中请安全驾驶-持续*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_CENTER, 					 							 e_SoundType_SafeDrivRepeat,        CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER, 					 							 e_SoundType_SafeDrivRepeat,        CHIME_SOUND_REQUEST_BIT01    },
/*	e_SoundType_LcdAlarmTen,                                                       通用报警-10次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LcdAlarmTen,          CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_12VPowerSysFail,                                                    12V电源系统故障，舒适功能关闭，请联系4S店维修！通用报警-10次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_12VPowerSysFail,          CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_LcdAlarmThree,                                                       通用报警-3次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LcdAlarmThree,        CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_LcdAlarmOnce,                                                       通用报警-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LcdAlarmOnce,         CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LcdAlarmOnce,         CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_LcdAlarmOnce,         CHIME_SOUND_REQUEST_BIT02    },
/*	e_SoundType_PowerBatWarmOnce,                                                   动力电池预热中-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_PowerBatWarmOnce,     CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_ChargeFaultOnce,													充电故障声音提示(PHEV)*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_ChargeFaultOnce,     CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_AccCruiseFailOnce,                                                  自适应巡航无法激活-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_AccCruiseFailOnce,    CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_AccCruiseQuitOnce,                                                  自适应巡航功能取消-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_AccCruiseQuitOnce,    CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_SmartCruiseFailOnce,                                                智能巡航辅助无法激活-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_SmartCruiseFailOnce,  CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_SmartCruisQuitOnce,                                                 智能巡航辅助功能取消-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_SmartCruisQuitOnce,   CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_FCOKOnce,                                                           前车已起步-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_FCOKOnce,             CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_FCOKAttRoadEnvOnce,                                                 前车已起步，请注意前方道路环境-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_FCOKAttRoadEnvOnce,   CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_FCOKKeepAtOnce,                                                     前车已起步，请保持注意力-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_FCOKKeepAtOnce,       CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_FCOKTakeCarOnce,                                                    前车已起步，请接管车辆-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_FCOKTakeCarOnce,      CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_AccCruiseOkkeepAtOnce,                                              自适应巡航已激活，请保持注意力-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_AccCruiseOkkeepAtOnce,CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_SmartCruiseOkhwOnce,                                                智慧巡航已激活，请保持注意力并手握方向盘-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_SmartCruiseOkhwOnce,  CHIME_SOUND_REQUEST_BIT00    },
/* 	e_SoundType_NOHIsActivated														自动导航辅助已启动*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_NOHIsActivated,  		CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_ConditionNotMet														环境条件不满足，请稍后尝试*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_ConditionNotMet,  	CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_StayFocusedTryAgain													请保持专注驾驶，再次开启尝试*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_StayFocusedTryAgain,  CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_HandsOnthewheelTryAgain												请保持手握方向盘，再次尝试开启*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_HandsOnthewheelTryAgain,CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_FastenSeatBelt														请系紧安全带*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_FastenSeatBelt,  		CHIME_SOUND_REQUEST_BIT00    },
/*  e_SoundType_CloseTheDoor														请关闭车门*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CloseTheDoor,  		CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_FastenPassengerSeat													请副驾驶系紧安全带*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_FastenPassengerSeat,  CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_CCOOnce,                                                            CCO(越野巡航)故障指示-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_CCOOnce,              CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_TABFailOnce,                                                        TAB（转向辅助）失效指示-单次*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_TABFailOnce,          CHIME_SOUND_REQUEST_BIT00    },
/*	e_SoundType_HighVol0_5Hz,                                                       上高压后司机离开车门-0.5HZ_12S*/
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_HighVol0_5Hz,         CHIME_SOUND_REQUEST_BIT00    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_HighVol0_5Hz,         CHIME_SOUND_REQUEST_BIT01    },
	{CHIME_RSDS_POSITION_VFL | CHIME_RSDS_POSITION_VFR | CHIME_RSDS_POSITION_CENTER,                      e_SoundType_HighVol0_5Hz,         CHIME_SOUND_REQUEST_BIT02    },

};
static const uint16 ChimeConstMaxWrn2ChimeTbl = sizeof(ChimeWrn2ChimeTbl)/sizeof(s_ChimeWrnProcess_t);

#define SWC_CHIME_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_Chime_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_CHIME_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_Chime_MemMap.h"

#define SWC_CHIME_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_Chime_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_CHIME_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Chime_MemMap.h"

static uint16 ChimeRequirementBitTbl[e_ChimeTable_All][e_SoundType_NumberOfChimes];
static s_ChimeGlobalData_t ChimeGlobalData_s;
static s_ChimeGlobalIPCWarnData_t ChimeGlobalIPCWarn_s[2];
static s_IPCAdasCallback_t  ChimeGlobalIPCAdas_s[2];
static uint8 Chime_FirstSoundFlag_u8;

static ChimeTTFlashCallback_t ChimeTTFlashstatus;
static uint32 ChimeLastTTFlashstatus ;

static uint8 TTFlash_Flag ;

//IPC_M2S_ClusterAppAPPWN_Module_t ChimeLocalWarning;
//IPC_M2S_ClusterAppAPPWN_Module_t ChimeLocalTelltale;
#define SWC_CHIME_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Chime_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/


/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_CHIME_START_SEC_CODE
#include "SWC_Chime_MemMap.h"

/**********************************************************************************************************
*Function   : Chime_ProcessColdInit                                                                       *
*                                                                                                         *
*Description: Chime process function cold init, for init data                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
void Chime_ProcessColdInit(void)
{
	Chime_ProcessWarmInit();
}

/**********************************************************************************************************
*Function   : Chime_ProcessWarmInit                                                                       *
*                                                                                                         *
*Description: Chime process function warm init, for init data                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
void Chime_ProcessWarmInit(void)
{
	(void)memset(ChimeRequirementBitTbl[0],0,sizeof(ChimeRequirementBitTbl));
	(void)memset(&ChimeGlobalData_s,0,sizeof(ChimeGlobalData_s));
	(void)memset(&ChimeGlobalIPCWarn_s,0,sizeof(ChimeGlobalIPCWarn_s));
	(void)memset(&ChimeGlobalIPCAdas_s,0,sizeof(ChimeGlobalIPCAdas_s));
	Chime_FirstSoundFlag_u8 = 0u;
	
	(void)memset(&ChimeTTFlashstatus,0,sizeof(ChimeTTFlashstatus));
	ChimeLastTTFlashstatus = 0u;
	TTFlash_Flag = 0;
}

/**********************************************************************************************************
*Function   : SWC_ChimeMainProcess                                                                        *
*                                                                                                         *
*Description: Chime process task function, for judge sound requirement                                    *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
void SWC_ChimeMainProcess(void)
{
	uint32 pass_u32;
	uint16 power_u16 = 0;
	uint8 power_temp = 0;
	const s_ChimeProcessFunParameter_t *ptr;
#ifdef CHIME_RUNABLE_TIME_TEST
	Chime_RteAdaptRunableOstmStart(ChimeOstmTimer2);

#endif
	Chime_RteAdaptGetAllConfig();
	power_u16 = Chime_RteAdaptGetPower();
	power_u16 |=Chime_RteAdaptGetVoltage();
	power_temp = CHIME_FUN_RUN_POWER_OFF | CHIME_FUN_RUN_POWER_ABNORMAL | CHIME_FUN_RUN_POWER_SLEEP | CHIME_FUN_RUN_POWER_PRESLEEP;
	if(FALSE != (power_u16 & power_temp)) 
	{
		Chime_RteAdaptOstmStop((uint8)ChimeOstmTimer1);
		ChimeGlobalData_s.PowerFlg_u8 = FALSE;
	}
	else
	{
		if(FALSE == ChimeGlobalData_s.PowerFlg_u8)
		{
			Chime_RteAdaptOstmStart((uint8)ChimeOstmTimer1);
			ChimeGlobalData_s.PowerFlg_u8 = TRUE;
		}
	}
	pass_u32 = Chime_RteAdaptOstmCheck((uint8)ChimeOstmTimer1);
	ptr = ChimeProcessFunParameter_t;
	while(ptr->Process != CHIME_PROCESS_FUN_NULL)
	{
		if((FALSE != (power_u16 & ptr->BitSts_u16)) && (pass_u32 >= ptr->OnDelayTime))
		{
			ptr->Process();
		}
		else
		{
			ptr->Cancel();
		}
		ptr ++;
	}
	SWC_ChimeWarningCancelCheck();
	Chime_RequestChimeProcess();
	Chime_OStmCheck();
#ifdef CHIME_RUNABLE_TIME_TEST
	
	Chime_RteAdaptRunableOstmCheck((uint8)ChimeOstmTimer2);
#endif

}
/**********************************************************************************************************
*Function   : SWC_ChimeWarningCancelCheck                                                                 *
*                                                                                                         *
*Description: Chime process task function, for judge sound requirement                                    *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeWarningCancelCheck(void)
{
	uint8 WarningSts;
	uint16 index,WrnId;
	uint16 Temp_divide,Temp_remainder;
	s_SWCWrnModule_t WarningData;
	Rte_Enter_ExclusiveArea_Normal();
	(void)memcpy((uint8 *)(&ChimeGlobalIPCWarn_s[1]),(uint8 *)(&ChimeGlobalIPCWarn_s[0]),sizeof(s_ChimeGlobalIPCWarnData_t));
	(void)memset((uint8 *)(ChimeGlobalIPCWarn_s[0].ReqWarning),0,sizeof(ChimeGlobalIPCWarn_s[0].ReqWarning));
	
	(void)memcpy((uint8 *)(&ChimeGlobalIPCAdas_s[1]),(uint8 *)(&ChimeGlobalIPCAdas_s[0]),sizeof(s_IPCAdasCallback_t));
	Rte_Exit_ExclusiveArea_Normal();

	for(index = 0;(index < e_WarnReq_MaxNumber);index ++)
	{
		WarningSts = ChimeGlobalIPCWarn_s[1].ReqWarning[index];
		WrnId = ChimeWrningCancelTbl[index].WarningId_u16;
		if(FALSE != WarningSts)
		{
			if(CHIME_WARNING_SOUND_REQ == WarningSts)
			{
				ChimeWrningCancelTbl[index].Process(TRUE,TRUE,WarningSts);
			}
			else if(CHIME_WARNING_SOUND_CEL == WarningSts)
			{
				ChimeWrningCancelTbl[index].Process(TRUE,FALSE,0xffff);
			}
			else
			{
			
			}
		}
		if(WN_enWARNING_TOTAL_NUMBER == WrnId)
		{
			continue;
		}
		Temp_divide = WrnId / CHIME_BUFFER_BIT_TYPE;
		Temp_remainder = WrnId % CHIME_BUFFER_BIT_TYPE;
		
		if(index < e_WarnReq_AdasStart)
		{
			if(E_OK == Rte_Read_rpSR_SWCNormal_WarningStsOutput_Element(&WarningData))
			{
				if(WrnId ==  WN_enLFDoorOpen)
				{
					ChimeWrningCancelTbl[index].Process(TRUE,FALSE,WrnId);
				}
				else if(WrnId ==  WN_enRainDoorOpen)
				{
					ChimeWrningCancelTbl[index].Process(TRUE,FALSE,WrnId);
				}
				else if((FALSE == (WarningData.WarningStatus[Temp_divide] & (0x01 << Temp_remainder)))
					&& (ChimeGlobalIPCWarn_s[1].CurDisplayWrn_u16 != WrnId))
				{
					ChimeWrningCancelTbl[index].Process(TRUE,FALSE,WrnId);
				}
				else
				{}
			}
		}
		else
		{
			if((FALSE == (ChimeGlobalIPCAdas_s[1].u_AdasStatusAdasWarn_t.AdasWarn[Temp_divide] & (0x01 << Temp_remainder)))
				&& (ChimeGlobalIPCWarn_s[1].CurDisplayAdas_u16 != WrnId))
			{
				ChimeWrningCancelTbl[index].Process(TRUE,FALSE,WrnId);
			}
		}
	}
}

/**********************************************************************************************************
*Function   : CHIME_vCancelAllSound                                                                       *
*                                                                                                         *
*Description: Chime for clear requirement table                                                           *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
void CHIME_vCancelAllSound(void)
{
	(void)memset(ChimeRequirementBitTbl[0],0,sizeof(ChimeRequirementBitTbl));
}

/**********************************************************************************************************
*Function   : SWC_ChimePasCheck                                                                           *
*                                                                                                         *
*Description: Pas main process                                                                            *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePasCheck(void)
{
/*START RTE interface*************************************************************************************/
	uint8 configFRadar_u8 = Chime_RteAdaptGetVconfig(VCONFIG_KIND_FRT_OUTER_SENSOR);
	uint8 configRadarPas_u8 = Chime_RteAdaptGetVconfig(VCONFIG_KIND_PAS_CTA);
	uint8 configApa_u8 = Chime_RteAdaptGetVconfig(VCONFIG_KIND_AUTO_PARKING_SYSTEM);
/*END RTE interface***************************************************************************************/
	uint8 msgSts_buffer[4];
	uint8 msg_buffer[6];

	if((0x00 == configFRadar_u8) && ((0x01 == configRadarPas_u8) || (0x03 == configRadarPas_u8) || (0x04 == configRadarPas_u8) || (0x05 == configRadarPas_u8)))
	{
		if(ChimeGlobalData_s.PasLastConfig != 0x01)
		{
			ChimeGlobalData_s.PasLastConfig = 0x01;
			SWC_ChimePasCase1Cancel();
			SWC_ChimePasCase2Cancel();
			SWC_ChimePasCase3Cancel();
			SWC_ChimePasCase1FDCancel();
			SWC_ChimePasCase2FDCancel();
			SWC_ChimePasCase3FDCancel();
		}
		else
		{
			SWC_ChimePasCase1Cancel();
			SWC_ChimePasCase1FDCancel();
		}
/*START RTE interface*************************************************************************************/
		msgSts_buffer[0] = Chime_GetMessage_PASWorkCmd(&msg_buffer[0]);
		//DBC missing signal
		msgSts_buffer[1] = Chime_GetMessage_RPAS_SoundIndcn(&msg_buffer[1]);
		msgSts_buffer[1] = Chime_GetMessage_RPAS_WorkSts(&msg_buffer[2]);
		//for judge other can missing
		msgSts_buffer[2] = Chime_GetMessage_RPAS_SoundIndcn_FD(&msg_buffer[3]);
/*END RTE interface***************************************************************************************/
		SWC_ChimePasCase1Check(msg_buffer,msgSts_buffer);
/*START RTE interface*************************************************************************************/
		msgSts_buffer[0] = Chime_GetMessage_PASWorkCmd(&msg_buffer[0]);
		msgSts_buffer[1] = Chime_GetMessage_RPAS_SoundIndcn_FD(&msg_buffer[1]);
		msgSts_buffer[1] = Chime_GetMessage_RPAS_WorkSts_FD(&msg_buffer[2]);
		//for judge other can missing
		msgSts_buffer[2] = Chime_GetMessage_RPAS_SoundIndcn(&msg_buffer[3]);
/*END RTE interface***************************************************************************************/
		SWC_ChimePasCase1FDCheck(msg_buffer,msgSts_buffer);
	}
	else if((0x01 == configFRadar_u8) && ((0x02 == configRadarPas_u8) || (0x00 == configRadarPas_u8) || (0x05 == configRadarPas_u8)))
	{
		if(ChimeGlobalData_s.PasLastConfig != 0x02)
		{
			ChimeGlobalData_s.PasLastConfig = 0x02;
			SWC_ChimePasCase1Cancel();
			SWC_ChimePasCase2Cancel();
			SWC_ChimePasCase3Cancel();
			SWC_ChimePasCase1FDCancel();
			SWC_ChimePasCase2FDCancel();
			SWC_ChimePasCase3FDCancel();
		}
		else
		{
			SWC_ChimePasCase2Cancel();
			SWC_ChimePasCase2FDCancel();
		}
/*START RTE interface*************************************************************************************/
		msgSts_buffer[0] = Chime_GetMessage_PASWorkCmd(&msg_buffer[0]);
		msgSts_buffer[1] = Chime_GetMessage_FPAS_SoundIndcn(&msg_buffer[1]);
		msgSts_buffer[1] = Chime_GetMessage_FPAS_WorkSts(&msg_buffer[2]);
		//for judge other can missing
		msgSts_buffer[2] = Chime_GetMessage_FPAS_SoundIndcn_FD(&msg_buffer[3]);
/*END RTE interface***************************************************************************************/
		SWC_ChimePasCase2Check(msg_buffer,msgSts_buffer);
/*START RTE interface*************************************************************************************/
		msgSts_buffer[0] = Chime_GetMessage_PASWorkCmd(&msg_buffer[0]);
		msgSts_buffer[1] = Chime_GetMessage_FPAS_SoundIndcn_FD(&msg_buffer[1]);
		msgSts_buffer[1] = Chime_GetMessage_FPAS_WorkSts_FD(&msg_buffer[2]);
		//for judge other can missing
		msgSts_buffer[2] = Chime_GetMessage_FPAS_SoundIndcn(&msg_buffer[3]);
/*END RTE interface***************************************************************************************/
		SWC_ChimePasCase2FDCheck(msg_buffer,msgSts_buffer);
	}
	else if((0x01 == configFRadar_u8) && ((0x01 == configRadarPas_u8) || (0x03 == configRadarPas_u8) || (0x04 == configRadarPas_u8) || (0x05 == configRadarPas_u8)))
	{
		if(ChimeGlobalData_s.PasLastConfig != 0x03)
		{
			ChimeGlobalData_s.PasLastConfig = 0x03;
			SWC_ChimePasCase1Cancel();
			SWC_ChimePasCase2Cancel();
			SWC_ChimePasCase3Cancel();
			SWC_ChimePasCase1FDCancel();
			SWC_ChimePasCase2FDCancel();
			SWC_ChimePasCase3FDCancel();
		}
		else
		{
			SWC_ChimePasCase3Cancel();
			SWC_ChimePasCase3FDCancel();
		}
		/**********************************************************************************************************
		*START RTE interface
		**********************************************************************************************************/
		msgSts_buffer[0] = Chime_GetMessage_PASWorkCmd(&msg_buffer[0]);
		msgSts_buffer[1] = Chime_GetMessage_FPAS_SoundIndcn(&msg_buffer[1]);
		msgSts_buffer[2] = Chime_GetMessage_RPAS_SoundIndcn(&msg_buffer[2]);
		msgSts_buffer[1] = Chime_GetMessage_FPAS_WorkSts(&msg_buffer[3]);
		msgSts_buffer[2] = Chime_GetMessage_RPAS_WorkSts(&msg_buffer[4]);
		//for judge other can missing
		msgSts_buffer[3] = Chime_GetMessage_FPAS_SoundIndcn_FD(&msg_buffer[5]);
		/**********************************************************************************************************
		*END RTE interface
		**********************************************************************************************************/
		SWC_ChimePasCase3Check(msg_buffer,msgSts_buffer);
		/**********************************************************************************************************
		*START RTE interface
		**********************************************************************************************************/
		msgSts_buffer[0] = Chime_GetMessage_PASWorkCmd(&msg_buffer[0]);
		msgSts_buffer[1] = Chime_GetMessage_FPAS_SoundIndcn_FD(&msg_buffer[1]);
		msgSts_buffer[1] = Chime_GetMessage_RPAS_SoundIndcn_FD(&msg_buffer[2]);
		msgSts_buffer[1] = Chime_GetMessage_FPAS_WorkSts_FD(&msg_buffer[3]);
		msgSts_buffer[1] = Chime_GetMessage_RPAS_WorkSts_FD(&msg_buffer[4]);
		//for judge other can missing
		msgSts_buffer[2] = Chime_GetMessage_FPAS_SoundIndcn(&msg_buffer[5]);
		msgSts_buffer[3] = Chime_GetMessage_RPAS_SoundIndcn(&msg_buffer[5]);
		/**********************************************************************************************************
		*END RTE interface
		**********************************************************************************************************/
		SWC_ChimePasCase3FDCheck(msg_buffer, msgSts_buffer);
	}
	else
	{
		SWC_ChimePasCase1Cancel();
		SWC_ChimePasCase2Cancel();
		SWC_ChimePasCase3Cancel();
		SWC_ChimePasCase1FDCancel();
		SWC_ChimePasCase2FDCancel();
		SWC_ChimePasCase3FDCancel();
	}

	if((0x01 <= configApa_u8) && (0x07 >= configApa_u8))
	{
/**********************************************************************************************************
*START RTE interface
**********************************************************************************************************/
		msgSts_buffer[0] = Chime_GetMessage_SDWActiveSts(&msg_buffer[0]);
		msgSts_buffer[0] = Chime_GetMessage_APS_FRSideSnsrFailSts(&msg_buffer[1]);
		msgSts_buffer[0] = Chime_GetMessage_APS_FLSideSnsrFailSts(&msg_buffer[2]);
		msgSts_buffer[0] = Chime_GetMessage_APS_RLSideSnsrFailSts(&msg_buffer[3]);
		msgSts_buffer[0] = Chime_GetMessage_APS_RRSideSnsrFailSts(&msg_buffer[4]);
		msgSts_buffer[0] = Chime_GetMessage_SDW_SoundIndcn(&msg_buffer[5]);
/**********************************************************************************************************
*END RTE interface
**********************************************************************************************************/
		SWC_ChimePasCase4Cancel();
		SWC_ChimePasCase4Check(msg_buffer,msgSts_buffer);
	}
	else
	{
		SWC_ChimePasCase4Cancel();
	}

	if((0x02 <= configApa_u8) && (0x07 >= configApa_u8))
	{
/**********************************************************************************************************
*START RTE interface
**********************************************************************************************************/
		msgSts_buffer[0] = Chime_GetMessage_APS_SysSoundIndcn(msg_buffer);
/**********************************************************************************************************
*END RTE interface
**********************************************************************************************************/
		SWC_ChimePasCase5Cancel();
		SWC_ChimePasCase5Check(msg_buffer,msgSts_buffer);
	}
	else
	{
		SWC_ChimePasCase5Cancel();
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimePasCancel                                                                          *
*                                                                                                         *
*Description: Pas Cancel all chime requirement                                                            *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePasCancel(void)
{
	SWC_ChimePasCase1Cancel();
	SWC_ChimePasCase2Cancel();
	SWC_ChimePasCase3Cancel();
	SWC_ChimePasCase4Cancel();
	SWC_ChimePasCase5Cancel();
	SWC_ChimePasCase1FDCancel();
	SWC_ChimePasCase2FDCancel();
	SWC_ChimePasCase3FDCancel();
}
/**********************************************************************************************************
*Function   : SWC_ChimePasCase1Check                                                                      *
*                                                                                                         *
*Description: Chime Pas case1 judge,function just jedge sound requirement, no clear ,so need to clear     *
*             sound requirement before request                                                            *
*Parameter  : msg_u8 :SRD case1 message buffer,buffer[0] is first can message....                         *
*             sts_u8 :CAN message status for case1....                                                    *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePasCase1Check(uint8 *msg_u8,uint8 *sts_u8)
{
	if((FALSE != CHIME_CAN_STATUS(sts_u8[0])) && (0x01 == msg_u8[0]))
	{
		if(FALSE != CHIME_CAN_STATUS(sts_u8[1]))
		{
			if((0x01 == msg_u8[2]) || (0x02 == msg_u8[2]))
			{
				if(0x01 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarRLongRe_PasCase1_1);
				}
				else if(0x02 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarR1_5Hz_PasCase1_1);
				}
				else if(0x03 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarR3HZ_PasCase1_1);
				}
				else
				{
				}
			}
			else if((0x00 == msg_u8[2]) || (0x03 == msg_u8[2]))
			{
				Chime_RequestFlag((uint16)e_SoundType_RadarRFail3Times_PasCase1_1);
			}
			else
			{
			}
		}
		else
		{
			if(FALSE == CHIME_CAN_STATUS(sts_u8[2]))
			{
				Chime_RequestFlag((uint16)e_SoundType_RadarRFail3Times_PasCase1_2);
			}
		}
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimePasCase1Cancel                                                                     *
*                                                                                                         *
*Description: Pas Cancel case1  chime requirement                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePasCase1Cancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_RadarRLongRe_PasCase1_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarR1_5Hz_PasCase1_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarR3HZ_PasCase1_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarRFail3Times_PasCase1_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarRFail3Times_PasCase1_2);
}

/**********************************************************************************************************
*Function   : SWC_ChimePasCase2Check                                                                      *
*                                                                                                         *
*Description: Chime Pas case2 judge,function just jedge sound requirement, no clear ,so need to clear     *
*             sound requirement before request                                                            *
*Parameter  : msg_u8 :SRD case2 message buffer,buffer[0] is first can message....                         *
*             sts_u8 :CAN message status buffer for case2....                                             *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePasCase2Check(uint8 *msg_u8,uint8 *sts_u8)
{
	if((FALSE != CHIME_CAN_STATUS(sts_u8[0])) && (0x01 == msg_u8[0]))
	{
		if(FALSE != CHIME_CAN_STATUS(sts_u8[1]))
		{
			if((0x01 == msg_u8[2]) || (0x02 == msg_u8[2]))
			{
				if(0x01 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarFLongRe_PasCase2_1);
				}
				else if(0x02 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarF1_5Hz_PasCase2_1);
				}
				else if(0x03 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarF3Hz_PasCase2_1);
				}
				else
				{

				}
			}
			else if((0x00 == msg_u8[2]) || (0x03 == msg_u8[2]))
			{
				Chime_RequestFlag((uint16)e_SoundType_RadarFFail3Times_PasCase2_1);
			}
			else
			{
			}
		}
		else
		{
			if(FALSE == CHIME_CAN_STATUS(sts_u8[2]))
			{
				Chime_RequestFlag((uint16)e_SoundType_RadarFFail3Times_PasCase2_2);
			}
		}
	}
}
/**********************************************************************************************************
*Function   : SWC_ChimePasCase2Cancel                                                                     *
*                                                                                                         *
*Description: Pas Cancel case2  chime requirement                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePasCase2Cancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_RadarFLongRe_PasCase2_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarF1_5Hz_PasCase2_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarF3Hz_PasCase2_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarFFail3Times_PasCase2_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarFFail3Times_PasCase2_2);
}

/**********************************************************************************************************
*Function   : SWC_ChimePasCase3Check                                                                      *
*                                                                                                         *
*Description: Chime Pas case3 judge,function just jedge sound requirement, no clear ,so need to clear     *
*             sound requirement before request                                                            *
*Parameter  : msg_u8 :SRD case3 message buffer,buffer[0] is first can message....                         *
*             sts_u8 :CAN message status buffer for case3....                                             *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePasCase3Check(uint8 *msg_u8,uint8 *sts_u8)
{
	if((FALSE != CHIME_CAN_STATUS(sts_u8[0])) && (0x01 == msg_u8[0]))
	{
		if(FALSE != CHIME_CAN_STATUS(sts_u8[1]))
		{
			if((0x01 == msg_u8[3]) || (0x02 == msg_u8[3]))
			{
				if(0x01 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarFLongRe_PasCase3_1);
				}
				else if(0x02 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarF1_5Hz_PasCase3_1);
				}
				else if(0x03 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarF3Hz_PasCase3_1);
				}
				else
				{
				}
			}
			else if((0x00 == msg_u8[3]) || (0x03 == msg_u8[3]))
			{
				Chime_RequestFlag((uint16)e_SoundType_RadarFFail3Times_PasCase3_1);
			}
			else
			{
			}
		}
		else
		{
			if(FALSE == CHIME_CAN_STATUS(sts_u8[3]))
			{
				Chime_RequestFlag((uint16)e_SoundType_RadarFFail3Times_PasCase3_2);
			}
		}
		if(FALSE != CHIME_CAN_STATUS(sts_u8[2]))
		{
			if((0x01 == msg_u8[4]) || (0x02 == msg_u8[4]))
			{
				if(0x01 == msg_u8[2])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarRLongRe_PasCase3_1);
				}
				else if(0x02 == msg_u8[2])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarR1_5Hz_PasCase3_1);
				}
				else if(0x03 == msg_u8[2])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarR3HZ_PasCase3_1);
				}
				else
				{
				}
			}
			else if((0x00 == msg_u8[4]) || (0x03 == msg_u8[4]))
			{
				Chime_RequestFlag((uint16)e_SoundType_RadarRFail3Times_PasCase3_1);
			}
			else
			{
			
			}
		}
		else
		{
			if(FALSE == CHIME_CAN_STATUS(sts_u8[3]))
			{
				Chime_RequestFlag((uint16)e_SoundType_RadarRFail3Times_PasCase3_2);
			}
		}
	}
}
/**********************************************************************************************************
*Function   : SWC_ChimePasCase3Cancel                                                                     *
*                                                                                                         *
*Description: Pas Cancel case3  chime requirement                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePasCase3Cancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_RadarFLongRe_PasCase3_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarRLongRe_PasCase3_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarF1_5Hz_PasCase3_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarR1_5Hz_PasCase3_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarF3Hz_PasCase3_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarR3HZ_PasCase3_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarFFail3Times_PasCase3_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarFFail3Times_PasCase3_2);
	Chime_CancelFlag((uint16)e_SoundType_RadarRFail3Times_PasCase3_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarRFail3Times_PasCase3_2);
}


/**********************************************************************************************************
*Function   : SWC_ChimePasCase4Check                                                                      *
*                                                                                                         *
*Description: Chime Pas case4 judge,function just jedge sound requirement, no clear ,so need to clear     *
*             sound requirement before request                                                            *
*Parameter  : msg_u8 :SRD case4 message buffer,buffer[0] is first can message....                         *
*             sts_u8 :CAN message status buffer for case4....                                             *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePasCase4Check(uint8 *msg_u8,uint8 *sts_u8)
{
	if(FALSE != CHIME_CAN_STATUS(sts_u8[0]))
	{
		if(0x01 == msg_u8[0])
		{
			if((0x01 == msg_u8[1]) || (0x01 == msg_u8[2]) || (0x01 == msg_u8[3]) || (0x01 == msg_u8[4]))
			{
				if(0x01 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarSDWFail3Times_PasCase4_1);
				}
				if(0x01 == msg_u8[2])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarSDWFail3Times_PasCase4_2);
				}
				if(0x01 == msg_u8[3])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarSDWFail3Times_PasCase4_3);
				}
				if(0x01 == msg_u8[4])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarSDWFail3Times_PasCase4_4);
				}
			}
			else
			{
				if(0x01 == msg_u8[5])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarSDWLongRe_PasCase4_1);
				}
				else if(0x02 == msg_u8[5])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarSDW1_5Hz_PasCase4_1);
				}
				else if(0x03 == msg_u8[5])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarSDW3Hz_PasCase4_1);
				}
				else
				{
				}
			}
		}
	}
	else
	{
		Chime_RequestFlag((uint16)e_SoundType_RadarSDWFail3Times_PasCase4_5);
	}
}
/**********************************************************************************************************
*Function   : SWC_ChimePasCase4Cancel                                                                     *
*                                                                                                         *
*Description: Pas Cancel case4  chime requirement                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePasCase4Cancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_RadarSDWFail3Times_PasCase4_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarSDWFail3Times_PasCase4_2);
	Chime_CancelFlag((uint16)e_SoundType_RadarSDWFail3Times_PasCase4_3);
	Chime_CancelFlag((uint16)e_SoundType_RadarSDWFail3Times_PasCase4_4);
	Chime_CancelFlag((uint16)e_SoundType_RadarSDWLongRe_PasCase4_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarSDW1_5Hz_PasCase4_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarSDW3Hz_PasCase4_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarSDWFail3Times_PasCase4_5);
}

/**********************************************************************************************************
*Function   : SWC_ChimePasCase5Check                                                                      *
*                                                                                                         *
*Description: Chime Pas case5 judge,function just jedge sound requirement, no clear ,so need to clear     *
*             sound requirement before request                                                            *
*Parameter  : msg_u8 :SRD case5 message buffer,buffer[0] is first can message....                         *
*             sts_u8 :CAN message status buffer for case5....                                             *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePasCase5Check(uint8 *msg_u8,uint8 *sts_u8)
{
	if(0x01 == msg_u8[0])
	{
		Chime_RequestFlag((uint16)e_SoundType_APAOnce_PasCase5_1);
	}
	if(0x02 == msg_u8[0])
	{
		Chime_RequestFlag((uint16)e_SoundType_APAOnce_PasCase5_2);
	}
	if(0x03 == msg_u8[0])
	{
		Chime_RequestFlag((uint16)e_SoundType_APAOnce_PasCase5_3);
	}
	if(0x04 == msg_u8[0])
	{
		Chime_RequestFlag((uint16)e_SoundType_APAOnce_PasCase5_4);
	}
	else
	{
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimePasCase5Cancel                                                                     *
*                                                                                                         *
*Description: Pas Cancel case5  chime requirement                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePasCase5Cancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_APAOnce_PasCase5_1);
	Chime_CancelFlag((uint16)e_SoundType_APAOnce_PasCase5_2);
	Chime_CancelFlag((uint16)e_SoundType_APAOnce_PasCase5_3);
	Chime_CancelFlag((uint16)e_SoundType_APAOnce_PasCase5_4);
}
/**********************************************************************************************************
*Function   : SWC_ChimePasCase1FDCheck                                                                    *
*                                                                                                         *
*Description: Chime Pas case1(CAN meessage use CANFD) judge,function just jedge sound requirement, no     *
*              clear ,so need to clear sound requirement before request                                   *
*Parameter  : msg_u8 :SRD case1 message buffer,buffer[0] is first can message....                         *
*             sts_u8 :CANFD message status buffer for case1....                                           *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePasCase1FDCheck(uint8 *msg_u8,uint8 *sts_u8)
{
	if((FALSE != CHIME_CAN_STATUS(sts_u8[0])) && (0x01 == msg_u8[0]))
	{
		if(FALSE != CHIME_CAN_STATUS(sts_u8[1]))
		{
			if((0x01 == msg_u8[2]) || (0x02 == msg_u8[2]))
			{
				if(0x01 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarRLongRe_FDPasCase1_1);
				}
				else if(0x02 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarR1_5Hz_FDPasCase1_1);
				}
				else if(0x03 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarR3HZ_FDPasCase1_1);
				}
				else
				{
				}
			}
			else if((0x00 == msg_u8[2]) || (0x03 == msg_u8[2]))
			{
				Chime_RequestFlag((uint16)e_SoundType_RadarRFail3Times_FDPasCase1_1);
			}
			else
			{
			}
		}
		else
		{
			if(FALSE == CHIME_CAN_STATUS(sts_u8[2]))
			{
				Chime_RequestFlag((uint16)e_SoundType_RadarRFail3Times_FDPasCase1_2);
			}
		}
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimePasCase1FDCancel                                                                   *
*                                                                                                         *
*Description: Pas Cancel case1  chime requirement                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePasCase1FDCancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_RadarRLongRe_FDPasCase1_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarR1_5Hz_FDPasCase1_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarR3HZ_FDPasCase1_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarRFail3Times_FDPasCase1_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarRFail3Times_FDPasCase1_2);
}
/**********************************************************************************************************
*Function   : SWC_ChimePasCase2FDCheck                                                                      *
*                                                                                                         *
*Description: Chime Pas case2 judge,function just jedge sound requirement, no clear ,so need to clear     *
*             sound requirement before request                                                            *
*Parameter  : msg_u8 :SRD case2 message buffer,buffer[0] is first can message....                         *
*             sts_u8 :CAN message status buffer for case2....                                             *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePasCase2FDCheck(uint8 *msg_u8,uint8 *sts_u8)
{
	if((FALSE != CHIME_CAN_STATUS(sts_u8[0])) && (0x01 == msg_u8[0]))
	{
		if(FALSE != CHIME_CAN_STATUS(sts_u8[1]))
		{
			if((0x01 == msg_u8[2]) || (0x02 == msg_u8[2]))
			{
				if(0x01 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarFLongRe_FDPasCase2_1);
				}
				else if(0x02 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarF1_5Hz_FDPasCase2_1);
				}
				else if(0x03 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarF3Hz_FDPasCase2_1);
				}
				else
				{

				}
			}
			else if((0x00 == msg_u8[2]) || (0x03 == msg_u8[2]))
			{
				Chime_RequestFlag((uint16)e_SoundType_RadarFFail3Times_FDPasCase2_1);
			}
			else
			{
			}
		}
		else
		{
			if(FALSE == CHIME_CAN_STATUS(sts_u8[2]))
			{
				Chime_RequestFlag((uint16)e_SoundType_RadarFFail3Times_FDPasCase2_2);
			}
		}
	}
}
/**********************************************************************************************************
*Function   : SWC_ChimePasCase2Cancel                                                                     *
*                                                                                                         *
*Description: Pas Cancel case2  chime requirement                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePasCase2FDCancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_RadarFLongRe_FDPasCase2_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarF1_5Hz_FDPasCase2_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarF3Hz_FDPasCase2_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarFFail3Times_FDPasCase2_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarFFail3Times_FDPasCase2_2);
}

/**********************************************************************************************************
*Function   : SWC_ChimePasCase3FDCheck                                                                    *
*                                                                                                         *
*Description: Chime Pas case3(CAN meessage use CANFD) judge,function just jedge sound requirement, no     *
*              clear ,so need to clear sound requirement before request                                   *
*Parameter  : msg_u8 :SRD case3 message buffer,buffer[0] is first can message....                         *
*             sts_u8 :CANFD message status buffer for case3....                                           *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePasCase3FDCheck(uint8 *msg_u8,uint8 *sts_u8)
{
	if((FALSE != CHIME_CAN_STATUS(sts_u8[0])) && (0x01 == msg_u8[0]))
	{
		if(FALSE != CHIME_CAN_STATUS(sts_u8[1]))
		{
			if((0x01 == msg_u8[3]) || (0x02 == msg_u8[3]))
			{
				if(0x01 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarFLongRe_FDPasCase3_1);
				}
				else if(0x02 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarF1_5Hz_FDPasCase3_1);
				}
				else if(0x03 == msg_u8[1])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarF3Hz_FDPasCase3_1);
				}
				else
				{
				}
			}
			else if((0x00 == msg_u8[3]) || (0x03 == msg_u8[3]))
			{
				Chime_RequestFlag((uint16)e_SoundType_RadarFFail3Times_FDPasCase3_1);
			}
			else
			{
			}
		}
		else
		{
			if(FALSE == CHIME_CAN_STATUS(sts_u8[2]))
			{
				Chime_RequestFlag((uint16)e_SoundType_RadarFFail3Times_FDPasCase3_2);
			}
		}
		if(FALSE != CHIME_CAN_STATUS(sts_u8[1]))
		{
			if((0x01 == msg_u8[4]) || (0x02 == msg_u8[4]))
			{
				if(0x01 == msg_u8[2])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarRLongRe_FDPasCase3_1);
				}
				else if(0x02 == msg_u8[2])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarR1_5Hz_FDPasCase3_1);
				}
				else if(0x03 == msg_u8[2])
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarR3HZ_FDPasCase3_1);
				}
				else
				{
				}
			}
			else if((0x00 == msg_u8[4]) || (0x03 == msg_u8[4]))
			{
				Chime_RequestFlag((uint16)e_SoundType_RadarRFail3Times_FDPasCase3_1);
			}
			else
			{
			}
		}
		else
		{
			if(FALSE == CHIME_CAN_STATUS(sts_u8[3]))
			{
				Chime_RequestFlag((uint16)e_SoundType_RadarRFail3Times_FDPasCase3_2);
			}
		}
	}
}
/**********************************************************************************************************
*Function   : SWC_ChimePasCase3FDCancel                                                                   *
*                                                                                                         *
*Description: Pas Cancel case3  chime requirement                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePasCase3FDCancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_RadarFLongRe_FDPasCase3_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarRLongRe_FDPasCase3_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarF1_5Hz_FDPasCase3_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarR1_5Hz_FDPasCase3_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarF3Hz_FDPasCase3_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarR3HZ_FDPasCase3_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarFFail3Times_FDPasCase3_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarFFail3Times_FDPasCase3_2);
	Chime_CancelFlag((uint16)e_SoundType_RadarRFail3Times_FDPasCase3_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarRFail3Times_FDPasCase3_2);
}

/**********************************************************************************************************
*Function   : SWC_ChimeRSDSCheck                                                                          *
*                                                                                                         *
*Description: Chime RDS sound request judge                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeRSDSCheck(void)
{
	uint8 configlane_u8 = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_LANE_CHANGE_ASSIST);
	uint8 configDrive_u8 = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_DRIVE_HANDLE_TYPE);//左右舵配置
	uint8 configAmp_u8 = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_AMPLIFIER);//独立功放配置
	uint8 configRSDS_u8 = Chime_RteAdaptGetLconfig((uint8)ChimeLconfigADASsoundfieldEnable);//本地声场配置
	uint8 RSDS_IPSoundReq_u8;
	uint8 CanSts_16F_u8;

	uint8 CanSts_319_u8;
	uint8 DrvDoorSts_u8;
	uint8 PassengerDoorSts_u8;
	uint8 LRDoorSts_u8;
	uint8 RRDoorSts_u8;
	uint8 BSD_LCA_warningReqRight_u8 = 0;
	uint8 BSD_LCA_warningReqleft_u8 = 0;
	uint8 RCTA_warningReqRight_u8 = 0;
	uint8 RCTA_warningReqLeft_u8 = 0;
	uint8 DOW_warningReqRight_u8 = 0;
	uint8 DOW_warningReqleft_u8 = 0;

	SWC_ChimeRSDSCancel();
	if(0x01 == configlane_u8)
	{
/*START RTE interface*************************************************************************************/
		CanSts_16F_u8 = Chime_GetMessage_RSDS_IPSoundReq(&RSDS_IPSoundReq_u8);
		CanSts_16F_u8 = Chime_GetMessage_BSD_LCA_warningReqRight(&BSD_LCA_warningReqRight_u8);
		CanSts_16F_u8 = Chime_GetMessage_BSD_LCA_warningReqleft(&BSD_LCA_warningReqleft_u8);
		CanSts_16F_u8 = Chime_GetMessage_RCTA_warningReqRight(&RCTA_warningReqRight_u8);
		CanSts_16F_u8 = Chime_GetMessage_RCTA_warningReqLeft(&RCTA_warningReqLeft_u8);
		CanSts_16F_u8 = Chime_GetMessage_DOW_warningReqRight(&DOW_warningReqRight_u8);
		CanSts_16F_u8 = Chime_GetMessage_DOW_warningReqleft(&DOW_warningReqleft_u8);
/*END RTE interface***************************************************************************************/
		if(FALSE != CHIME_CAN_STATUS(CanSts_16F_u8))
		{
			if(0x02 == RSDS_IPSoundReq_u8)
			{
				if((0x02 > configAmp_u8) && (FALSE != configRSDS_u8))
				{
					CanSts_319_u8 = Chime_GetMessage_DrvDoorSts(&DrvDoorSts_u8);
					CanSts_319_u8 = Chime_GetMessage_PassengerDoorSts(&PassengerDoorSts_u8);
					CanSts_319_u8 = Chime_GetMessage_LRDoorSts(&LRDoorSts_u8);
					CanSts_319_u8 = Chime_GetMessage_RRDoorSts(&RRDoorSts_u8);
					if(FALSE != CHIME_CAN_STATUS(CanSts_319_u8))
					{
						if(0x00 == configDrive_u8)
						{
							if((0x02 == DOW_warningReqRight_u8) && (0x01 == PassengerDoorSts_u8))
							{
								Chime_RequestFlag((uint16)e_SoundType_RadarRSDS4Hz_RSDS_1);//右前（左舵车型）
							}
							if((0x02 == DOW_warningReqleft_u8) && (0x01 == DrvDoorSts_u8))
							{
								Chime_RequestFlag((uint16)e_SoundType_RadarRSDS4Hz_RSDS_4);//左前（左舵车型）
							}
						}
						if(0x01 == configDrive_u8)
						{
							if((0x02 == DOW_warningReqleft_u8) && (0x01 == PassengerDoorSts_u8))
							{
								Chime_RequestFlag((uint16)e_SoundType_RadarRSDS4Hz_RSDS_2);//左前（右舵车型）
							}
							if((0x02 == DOW_warningReqRight_u8) && (0x01 == DrvDoorSts_u8))
							{
								Chime_RequestFlag((uint16)e_SoundType_RadarRSDS4Hz_RSDS_5);//右前（右舵车型）
							}
						}
						if((0x02 == DOW_warningReqRight_u8) && (0x01 == RRDoorSts_u8))
						{
							Chime_RequestFlag((uint16)e_SoundType_RadarRSDS4Hz_RSDS_3);//右后
						}
						if((0x02 == DOW_warningReqleft_u8) && (0x01 == LRDoorSts_u8))
						{
							Chime_RequestFlag((uint16)e_SoundType_RadarRSDS4Hz_RSDS_6);//左后
						}
					}
					
					if(0x02 == BSD_LCA_warningReqRight_u8)
					{
						Chime_RequestFlag((uint16)e_SoundType_RadarRSDS3Hz_RSDS_1);//驾驶员右侧
					}
					if(0x02 == BSD_LCA_warningReqleft_u8)
					{
						Chime_RequestFlag((uint16)e_SoundType_RadarRSDS3Hz_RSDS_2);//驾驶员左侧
					}
					if(0x01 == RCTA_warningReqRight_u8)
					{
						Chime_RequestFlag((uint16)e_SoundType_RadarRSDS3Hz_RSDS_3);//驾驶员右侧
					}
					if(0x01 == RCTA_warningReqLeft_u8)
					{
						Chime_RequestFlag((uint16)e_SoundType_RadarRSDS3Hz_RSDS_4);//驾驶员左侧
					}
					
					if(ChimeGlobalData_s.LastRSDS3HZField_u16 != Chime_GetCurrentSoundField((uint8)e_SoundType_RadarRSDS3Hz))
					{
						if(CHIME_RSDS_POSITION_NULL != Chime_GetCurrentSoundField((uint8)e_SoundType_RadarRSDS3Hz))
						{
							Chime_RequestFlagRepeat((uint16)e_SoundType_RadarRSDS3Hz_RSDS_6);//重新请求 不带声场
						}
						ChimeGlobalData_s.LastRSDS3HZField_u16 = Chime_GetCurrentSoundField((uint8)e_SoundType_RadarRSDS3Hz);
					}

					if(ChimeGlobalData_s.LastRSDS4HZField_u16 != Chime_GetCurrentSoundField((uint8)e_SoundType_RadarRSDS4Hz))
					{
						if(CHIME_RSDS_POSITION_NULL != Chime_GetCurrentSoundField((uint8)e_SoundType_RadarRSDS4Hz))
						{
							Chime_RequestFlagRepeat((uint16)e_SoundType_RadarRSDS4Hz_RSDS_8);//重新请求 不带声场
						}
						ChimeGlobalData_s.LastRSDS4HZField_u16 = Chime_GetCurrentSoundField((uint8)e_SoundType_RadarRSDS4Hz);
					}

				}
				else
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarRSDS3Hz_RSDS_6);//不带声场
				}
			}
		}
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimeRSDSCheck                                                                          *
*                                                                                                         *
*Description: Chime RDS sound request cancel                                                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeRSDSCancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_RadarRSDS3Hz_RSDS_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarRSDS3Hz_RSDS_2);
	Chime_CancelFlag((uint16)e_SoundType_RadarRSDS3Hz_RSDS_3);
	Chime_CancelFlag((uint16)e_SoundType_RadarRSDS3Hz_RSDS_4);
	Chime_CancelFlag((uint16)e_SoundType_RadarRSDS3Hz_RSDS_5);
	Chime_CancelFlag((uint16)e_SoundType_RadarRSDS3Hz_RSDS_6);
	Chime_CancelFlag((uint16)e_SoundType_RadarRSDS4Hz_RSDS_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarRSDS4Hz_RSDS_2);
	Chime_CancelFlag((uint16)e_SoundType_RadarRSDS4Hz_RSDS_3);
	Chime_CancelFlag((uint16)e_SoundType_RadarRSDS4Hz_RSDS_4);
	Chime_CancelFlag((uint16)e_SoundType_RadarRSDS4Hz_RSDS_5);
	Chime_CancelFlag((uint16)e_SoundType_RadarRSDS4Hz_RSDS_6);
	Chime_CancelFlag((uint16)e_SoundType_RadarRSDS4Hz_RSDS_7);
	Chime_CancelFlag((uint16)e_SoundType_RadarRSDS4Hz_RSDS_8);
	Chime_ClearField((uint16)e_SoundType_RadarRSDS3Hz_RSDS_1);
	Chime_ClearField((uint16)e_SoundType_RadarRSDS4Hz_RSDS_1);
}

/**********************************************************************************************************
*Function   : SWC_ChimeGearP8ATCheck                                                                      *
*                                                                                                         *
*Description: Chime GEAR 8AT sound request judge                                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeLWD_LKACheck(void)
{
	uint8 config_u8 = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_LDW_LKA);
	uint8 LSSIntervention_u8;
	uint8 CanSts23D_u8 = 0;

	SWC_ChimeLWD_LKACancel();
	if((0x01 <= config_u8) && (0x0D >= config_u8))
	{
/*START RTE interface*************************************************************************************/
		CanSts23D_u8 = Chime_GetMessage_LSSIntervention(&LSSIntervention_u8);
/*END RTE interface***************************************************************************************/
		if(FALSE != CHIME_CAN_STATUS(CanSts23D_u8))
		{
			if(0x01 == LSSIntervention_u8)
			{
				Chime_RequestFlag((uint16)e_SoundType_LDW_LKAOnce_LDWLKA_1);
			}
			if(0x02 == LSSIntervention_u8)
			{
				Chime_RequestFlag((uint16)e_SoundType_LDW_LKAOnce_LDWLKA_2);
			}
			if(ChimeGlobalData_s.LastLDW_LKAField_u16 != Chime_GetCurrentSoundField((uint8)e_SoundType_LDW_LKAOnce))
			{
				if(CHIME_RSDS_POSITION_NULL != Chime_GetCurrentSoundField((uint8)e_SoundType_LDW_LKAOnce))
				{
					Chime_RequestFlagRepeat((uint16)e_SoundType_LDW_LKAOnce_LDWLKA_15);//重新请求
				}
				ChimeGlobalData_s.LastLDW_LKAField_u16 = Chime_GetCurrentSoundField((uint8)e_SoundType_LDW_LKAOnce);
			}
		}
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimeGearP8ATCancel                                                                     *
*                                                                                                         *
*Description: Chime GEAR 8AT sound request cancel                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeLWD_LKACancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_LDW_LKAOnce_LDWLKA_1);
	Chime_CancelFlag((uint16)e_SoundType_LDW_LKAOnce_LDWLKA_2);
	Chime_CancelFlag((uint16)e_SoundType_LDW_LKAOnce_LDWLKA_15);
	Chime_ClearField((uint16)e_SoundType_LDW_LKAOnce_LDWLKA_15);
}

/**********************************************************************************************************
*Function   : SWC_ChimeTPMSLEDCheck                                                                          *
*                                                                                                         *
*Description: Chime TPMS sound request judge                                                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeTPMSLEDCheck(uint8 Ledsts)
{
	//跟随报警灯，所以不需要判断配置字条件
	if((ChimeGlobalData_s.TpmsLastSts_u8 != Ledsts) && (0x02 == Ledsts))
	{
		Chime_RequestFlag((uint16)e_SoundType_Tpms1Hz_TPMS_1);
	}
	else
	{
		if(0x02 != Ledsts)
		{
			Chime_CancelFlag((uint16)e_SoundType_Tpms1Hz_TPMS_1);
		}
	}
	ChimeGlobalData_s.TpmsLastSts_u8 = Ledsts;
}

/**********************************************************************************************************
*Function   : SWC_ChimeHybridPowerSystemLEDCheck                                                             *
*                                                                                                         *
*Description: Chime Hybrid failure sound request judge                                                    *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeHybridPowerSystemLEDCheck(uint8 Ledsts)
{
	//跟随报警灯，所以不需要判断配置字条件
	if((ChimeGlobalData_s.HybridPowerLastSts_u8 != Ledsts) && (0x01 == Ledsts))
	{
			Chime_RequestFlag((uint16)e_SoundType_HybridFail1Hz_HCU_1);
	}
	else
	{
		if(0x01 != Ledsts)
		{
			Chime_CancelFlag((uint16)e_SoundType_HybridFail1Hz_HCU_1);
		}
	}
	ChimeGlobalData_s.HybridPowerLastSts_u8 = Ledsts;

}

/**********************************************************************************************************
*Function   : SWC_ChimeHybridPowerSystemRedLEDCheck                                                       *
*                                                                                                         *
*Description: Chime Hybrid failure sound request judge                                                    *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeHybridPowerSystemRedLEDCheck(uint8 Ledsts)
{
	//跟随报警灯，所以不需要判断配置字条件
	if((ChimeGlobalData_s.HybridPowerLastSts_u8 != Ledsts) && (0x01 == Ledsts))
	{
		Chime_RequestFlag((uint16)e_SoundType_HybridFail1Hz_HCU_2);
	}
	else
	{
		if(0x01 != Ledsts)
		{
			Chime_CancelFlag((uint16)e_SoundType_HybridFail1Hz_HCU_2);
		}
	}
	ChimeGlobalData_s.HybridPowerLastSts_u8 = Ledsts;

}

/**********************************************************************************************************
*Function   : SWC_ChimeSeltbeltLEDCheck                                                                   *
*                                                                                                         *
*Description: Chime seltbelt sound request judge                                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeSeltbeltLEDCheck(uint8 Ledsts)
{

	//跟随报警灯，所以不需要判断配置字条件
	if((ChimeGlobalData_s.SeatbeltLastSts_u8 != Ledsts) && (0x02 == Ledsts))
	{
		Chime_RequestFlag((uint16)e_SoundType_Seatbelt0_5Hz_SEATBELT_1);
	}
	else
	{
		if(0x02 != Ledsts)
		{
			Chime_CancelFlag((uint16)e_SoundType_Seatbelt0_5Hz_SEATBELT_1);
		}
	}
	ChimeGlobalData_s.SeatbeltLastSts_u8 = Ledsts;

}


/**********************************************************************************************************
*Function   : SWC_ChimeDoorOpenCheck                                                                      *
*                                                                                                         *
*Description: Chime door open sound request judge                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeDoorOpenCheck(uint8 flag,uint8 enable,uint16 bit)
{
	uint16 temp;
	uint16 doorbit;
	uint16 speed;
	uint16 door_data;
	uint16 speed_flag;
	uint16 SpeedLim = (uint16)Chime_RteAdaptGetLconfig((uint8)ChimeLconfigDoortoRed_speedthreshold);
	//跟随warning，所以不需要判断配置字条件
	if(FALSE == flag)
	{
		/*Door Warning only check Shied flag*/
		doorbit = (bit & 0x0FFFU);
		if((0x00 == doorbit) && (FALSE == enable))
		{
			/*Set shied flag*/
			ChimeGlobalData_s.DoorOpenShiedFlag_u8 = 1;//TRUE;
		}
	}
	else
	{
		//follow warning Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
		if(E_OK == Chime_GetInterface_WarningStsDoor(&door_data,bit))
		{
			(void)Chime_GetInterface_SpeedoInfo_Element(&speed);

			/*Get door open index*/
			ChimeGlobalData_s.DoorOpenIndex_u16 = door_data;

			if(FALSE != ChimeGlobalData_s.DoorOpenShiedFlag_u8)
			{
				/*Clear all door open requirement*/
				ChimeGlobalData_s.DoorReqIndex_u16 = 0;
				/*Set shied index*/
				ChimeGlobalData_s.DoorShiedIndex_u16 = ChimeGlobalData_s.DoorOpenIndex_u16;
				/*Clear shied flag*/
				ChimeGlobalData_s.DoorOpenShiedFlag_u8 = 0;//FALSE;
			}
			ChimeGlobalData_s.DoorShiedIndex_u16 &= ChimeGlobalData_s.DoorOpenIndex_u16;
			if(speed > SpeedLim)
			{
				ChimeGlobalData_s.DoorReqIndex_u16 = ChimeGlobalData_s.DoorOpenIndex_u16 & (~ChimeGlobalData_s.DoorShiedIndex_u16);
			}
			else
			{
				ChimeGlobalData_s.DoorShiedIndex_u16 = 0;
				if(0x00 == speed)
				{
					ChimeGlobalData_s.DoorReqIndex_u16 = 0;
				}
				else
				{
					/*Clear door closed index*/
					ChimeGlobalData_s.DoorReqIndex_u16 &= ChimeGlobalData_s.DoorOpenIndex_u16;
				}
			}
			if(WN_enSecRowRSeatBelt == ChimeGlobalIPCWarn_s[1].CurDisplayWrn_u16)
			{
				for(temp = 0;temp < 11;temp ++)
				{
					/*when warning display,requirement chime flag*/
					if(temp > 9)
					{
						if(FALSE != (ChimeGlobalData_s.DoorReqIndex_u16 & (0x03 << temp)))
						{
							Chime_RequestFlag((uint16)e_SoundType_DoorOpen1_Once_DOOR_1 );
						}
					}
					else if((temp > 5) && (temp <= 9))
					{
						// do nothing 
					}
					else
					{
						if(FALSE != (ChimeGlobalData_s.DoorReqIndex_u16 & (0x01 << temp)))
						{
							Chime_RequestFlag((uint16)e_SoundType_DoorOpen1_5Hz_DOOR_1 + temp);
						}
					}
				}
				
			}
			/*Clear not requirement chime flag*/
			for(temp = 0;temp < 11;temp ++)
			{
				if(temp > 9)
				{
					if(FALSE == (ChimeGlobalData_s.DoorReqIndex_u16 & (0x03 << temp)))
					{
						Chime_CancelFlag((uint16)e_SoundType_DoorOpen1_Once_DOOR_1 );
					}
				}
				else if((temp > 5) && (temp <= 9 ))
				{

				}
				else
				{
					if(FALSE == (ChimeGlobalData_s.DoorReqIndex_u16 & (0x01 << temp)))
					{
						Chime_CancelFlag((uint16)e_SoundType_DoorOpen1_5Hz_DOOR_1 + temp);
					}
				}
				SWC_ChimeDoorOpenTimerStart(FALSE,ChimeGlobalData_s.DoorReqIndex_u16,0);
			}
			
		}
	}
}


/**********************************************************************************************************
*Function   : SWC_ChimeRainDoorOpenCheck                                                                  *
*                                                                                                         *
*Description: Chime door open sound request judge                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2021-05-26                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeRainDoorOpenCheck(uint8 flag,uint8 enable,uint16 bit)
{
	uint16 speed;
	uint16 SpeedLim = (uint16)Chime_RteAdaptGetLconfig((uint8)ChimeLconfigDoortoRed_speedthreshold);
	
	(void)Chime_GetInterface_SpeedoInfo_Element(&speed);

	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeRainDoorOverspeedCheck] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeRainDoorOverspeedCheck] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if((FALSE != enable) && (speed > SpeedLim))
		{
			Chime_RequestFlag((uint16)e_SoundType_LcdAlarmOnce_Wrn_2);
		}
		else
		{
			if((WN_enRainDoorOpen == ChimeGlobalIPCWarn_s[1].CurDisplayWrn_u16) && (speed > SpeedLim))
			{
				Chime_RequestFlag((uint16)e_SoundType_LcdAlarmOnce_Wrn_2);
			}
			else
			{
				Chime_CancelFlag((uint16)e_SoundType_LcdAlarmOnce_Wrn_2);
			}			
		}
	}

}

/**********************************************************************************************************
*Function   : SWC_ChimeReq_LKAANDLDWRE                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Xu wei cheng                                                                                *
*                                                                                                         *
*Date       : 2021-06-21                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_CarDistance(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeCarDistance] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeCarDistance] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_CarDistancce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_CarDistancce_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimeReq_PeopleRight                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Xu wei cheng                                                                                *
*                                                                                                         *
*Date       : 2021-06-21                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_PeopleRight(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimePeopleRight] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimePeopleRight] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_Pedestrian_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_Pedestrian_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimeReq_PeopleMid                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Xu wei cheng                                                                                *
*                                                                                                         *
*Date       : 2021-06-21                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_PeopleMid(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimePeopleMid] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimePeopleMid] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_Pedestrian_Wrn_2);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_Pedestrian_Wrn_2);
		}
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimeReq_PeopleLeft                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Xu wei cheng                                                                                *
*                                                                                                         *
*Date       : 2021-06-21                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_PeopleLeft(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimePeopleLeft] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimePeopleLeft] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_Pedestrian_Wrn_3);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_Pedestrian_Wrn_3);
		}
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimeReq_FaceCar                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Xu wei cheng                                                                                *
*                                                                                                         *
*Date       : 2021-06-21                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_FaceCar(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeFaceCar] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeFaceCar] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_FaceCar_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_FaceCar_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimeReq_SideCarTwoSide                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Xu wei cheng                                                                                *
*                                                                                                         *
*Date       : 2021-06-21                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_SideCarTwoSide(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeSideCarTwoSide] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeSideCarTwoSide] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_CrosswiseCar_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_CrosswiseCar_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimeReq_SideCarRight                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Xu wei cheng                                                                                *
*                                                                                                         *
*Date       : 2021-06-21                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_SideCarRight(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeSideCarRight] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeSideCarRight] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_CrosswiseCar_Wrn_2);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_CrosswiseCar_Wrn_2);
		}
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimeReq_SideCarLeft                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Xu wei cheng                                                                                *
*                                                                                                         *
*Date       : 2021-06-21                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_SideCarLeft(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeSideCarLeft] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeSideCarLeft] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_CrosswiseCar_Wrn_3);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_CrosswiseCar_Wrn_3);
		}
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimeReq_FrontCarAEB                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Xu wei cheng                                                                                *
*                                                                                                         *
*Date       : 2021-06-21                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_FrontCarAEB(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeFrontCarAEB] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeFrontCarAEB] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_FrontCarAEB_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_FrontCarAEB_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimeReq_FrontCarUnContron                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Xu wei cheng                                                                                *
*                                                                                                         *
*Date       : 2021-06-21                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_FrontCarUnContron(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeFrontCarUnContron] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeFrontCarUnContron] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_FrontCarUnContron_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_FrontCarUnContron_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimeReq_BackCarUnContron                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Xu wei cheng                                                                                *
*                                                                                                         *
*Date       : 2021-06-21                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_BackCarUnContron(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeBackCarUnContron] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeBackCarUnContron] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_BackCarUnContron_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_BackCarUnContron_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimeReq_AroundCarUnContron                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Xu wei cheng                                                                                *
*                                                                                                         *
*Date       : 2021-06-21                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_AroundCarUnContron(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeAroundCarUnContron] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeAroundCarUnContron] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_AroundCarUnContron_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_AroundCarUnContron_Wrn_1);
		}
	}

}

/**********************************************************************************************************
*Function   : SWC_ChimeReq_PlsTakeOver_4Hz                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                               *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_PlsTakeOver_4Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimePlsTakeOver4Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimePlsTakeOver4Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_PlsTakeOver4Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_PlsTakeOver4Hz_Wrn_1);
		}
	}

}


/**********************************************************************************************************
*Function   : SWC_ChimeReq_PlsTakeOver_2Hz                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                               *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_PlsTakeOver_2Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimePlsTakeOver2Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimePlsTakeOver2Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_PlsTakeOver2Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_PlsTakeOver2Hz_Wrn_1);
		}
	}

}


/**********************************************************************************************************
*Function   : SWC_ChimeReq_PlsTakeOver                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                               *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_PlsTakeOver(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimePlsTakeOver1Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimePlsTakeOver1Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_PlsTakeOver1Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_PlsTakeOver1Hz_Wrn_1);
		}
	}

}


/**********************************************************************************************************
*Function   : SWC_ChimeReq_CarAutoBrakePlsTake                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                               *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_CarAutoBrakePlsTake(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeCarAutoBrakePlsTake] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeCarAutoBrakePlsTake] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_CarAutoBrakePlsTake_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_CarAutoBrakePlsTake_Wrn_1);
		}
	}

}




/**********************************************************************************************************
*Function   : SWC_ChimeReq_CarParkingPlsTake                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                               *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_CarParkingPlsTake(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeCarParkingPlsTake] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeCarParkingPlsTake] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_CarParkingPlsTake_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_CarParkingPlsTake_Wrn_1);
		}
	}

}


/**********************************************************************************************************
*Function   : SWC_ChimeReq_CarUrgeBrakePlsTake                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                               *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_CarUrgeBrakePlsTake(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeCarUrgeBrakePlsTake] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeCarUrgeBrakePlsTake] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_CarUrgeBrakePlsTake_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_CarUrgeBrakePlsTake_Wrn_1);
		}
	}

}





/**********************************************************************************************************
*Function   : SWC_ChimeReq_MoveRampFailPlsTake                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                               *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_MoveRampFailPlsTake(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeMoveRampFailPlsTake] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeMoveRampFailPlsTake] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_MoveRampFailPlsTake_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_MoveRampFailPlsTake_Wrn_1);
		}
	}

}

/**********************************************************************************************************
*Function   : SWC_ChimeReq_MoveMainFailPlsTake_4Hz                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                               *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_MoveMainFailPlsTake_4Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeMoveMainFailPlsTake4Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeMoveMainFailPlsTake4Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_MoveMainFailPlsTake4Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_MoveMainFailPlsTake4Hz_Wrn_1);
		}
	}

}


/**********************************************************************************************************
*Function   : SWC_ChimeReq_MoveMainFailPlsTake_2Hz                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                               *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_MoveMainFailPlsTake_2Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeMoveMainFailPlsTake2Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeMoveMainFailPlsTake2Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_MoveMainFailPlsTake2Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_MoveMainFailPlsTake2Hz_Wrn_1);
		}
	}

}



/**********************************************************************************************************
*Function   : SWC_ChimeReq_MoveMainFailPlsTake                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                               *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_MoveMainFailPlsTake(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeMoveMainFailPlsTake1Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeMoveMainFailPlsTake1Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_MoveMainFailPlsTake1Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_MoveMainFailPlsTake1Hz_Wrn_1);
		}
	}

}

/**********************************************************************************************************
*Function   : SWC_ChimeReq_TurnFailPlsTake_4Hz                                                                    *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                               *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_TurnFailPlsTake_4Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeTurnFailPlsTake4Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeTurnFailPlsTake4Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_TurnFailPlsTake4Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_TurnFailPlsTake4Hz_Wrn_1);
		}
	}

}



/**********************************************************************************************************
*Function   : SWC_ChimeReq_TurnFailPlsTake_2Hz                                                            *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                                 *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_TurnFailPlsTake_2Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeTurnFailPlsTake2Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeTurnFailPlsTake2Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_TurnFailPlsTake2Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_TurnFailPlsTake2Hz_Wrn_1);
		}
	}

}


/**********************************************************************************************************
*Function   : SWC_ChimeReq_TurnFailPlsTake                                                                *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                                 *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_TurnFailPlsTake(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeTurnFailPlsTake1Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeTurnFailPlsTake1Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_TurnFailPlsTake1Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_TurnFailPlsTake1Hz_Wrn_1);
		}
	}

}





/**********************************************************************************************************
*Function   : SWC_ChimeReq_TollGateFailPlsTake_4Hz                                                                *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                                 *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_TollGateFailPlsTake_4Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeTollGateFailPlsTake4Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeTollGateFailPlsTake4Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_TollGateFailPlsTake4Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_TollGateFailPlsTake4Hz_Wrn_1);
		}
	}

}





/**********************************************************************************************************
*Function   : SWC_ChimeReq_TollGateFailPlsTake_2Hz                                                                *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                                 *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_TollGateFailPlsTake_2Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeTollGateFailPlsTake2Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeTollGateFailPlsTake2Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_TollGateFailPlsTake2Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_TollGateFailPlsTake2Hz_Wrn_1);
		}
	}

}




/**********************************************************************************************************
*Function   : SWC_ChimeReq_TollGateFailPlsTake                                                                *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                                 *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_TollGateFailPlsTake(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeTollGateFailPlsTake1Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeTollGateFailPlsTake1Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_TollGateFailPlsTake1Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_TollGateFailPlsTake1Hz_Wrn_1);
		}
	}

}



/**********************************************************************************************************
*Function   : SWC_ChimeReq_RoundaboutFailPlsTake_4Hz                                                                *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                                 *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_RoundaboutFailPlsTake_4Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeRoundaboutFailPlsTake4Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeRoundaboutFailPlsTake4Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_RoundaboutFailPlsTake4Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_RoundaboutFailPlsTake4Hz_Wrn_1);
		}
	}

}


/**********************************************************************************************************
*Function   : SWC_ChimeReq_RoundaboutFailPlsTake_2Hz                                                                *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                                 *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_RoundaboutFailPlsTake_2Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeRoundaboutFailPlsTake2Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeRoundaboutFailPlsTake2Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_RoundaboutFailPlsTake2Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_RoundaboutFailPlsTake2Hz_Wrn_1);
		}
	}

}


/**********************************************************************************************************
*Function   : SWC_ChimeReq_RoundaboutFailPlsTake                                                               *
*                                                                                                         *
*Description: Chime LKA and Ldw sound request judge                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Wangtingting                                                                                 *
*                                                                                                         *
*Date       : 2021-07-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_RoundaboutFailPlsTake(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeRoundaboutFailPlsTake1Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeRoundaboutFailPlsTake1Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_RoundaboutFailPlsTake1Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_RoundaboutFailPlsTake1Hz_Wrn_1);
		}
	}

}




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
void SWC_ChimeDoorOpenTimerStart(uint8 flag,uint16 bit,uint32 time)
{
	uint8 temp;
	uint16 door_change_u16;
	uint16 door_temp;
	if(TRUE == flag)
	{
		door_temp = ChimeGlobalData_s.DoorOpenTimerIndex_u16 ^ ChimeGlobalData_s.DoorReqIndex_u16;
		door_change_u16 = (door_temp & ChimeGlobalData_s.DoorReqIndex_u16);
		for(temp = 0;temp < 6;temp ++)
		{
			if(FALSE != (door_change_u16 & (0x01 << temp)))
			{
				Chime_RteAdaptTimerSet(&ChimeGlobalData_s.DoorOpenTab_s[temp], time);
			}
		}
		ChimeGlobalData_s.DoorOpenTimerIndex_u16 = ChimeGlobalData_s.DoorReqIndex_u16;
	}
	else
	{
		door_temp = ChimeGlobalData_s.DoorOpenTimerIndex_u16 ^ bit;
		door_change_u16 = ( door_temp & ChimeGlobalData_s.DoorOpenTimerIndex_u16);
		for(temp = 0;temp < 6;temp ++)
		{
			if(FALSE != (door_change_u16 & (0x01 << temp)))
			{
				Chime_RteAdaptTimerClr(&ChimeGlobalData_s.DoorOpenTab_s[temp]);
				ChimeGlobalData_s.DoorOpenTimerIndex_u16 &= ~((uint16)0x01 << temp);
			}
		}
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimeCDPCheck                                                                           *
*                                                                                                         *
*Description: Chime CDP sound request judge                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeCDPCheck(void)
{
	uint8 config_u8_B = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_PARKING_BRAKE);
	uint8 message_use = Chime_RteAdaptGetLconfig((uint8)ChimeVconfigCANFD_USE_FLAG);
	uint8 CDPActv_0x145_u8;
	uint8 CDPActv_0x137_u8;
	uint8 CanSts_u8 = 0;
	uint8 Check_flag;

	Chime_CancelFlag((uint16)e_SoundType_DynamicBrake0_5Hz_1);
	Chime_CancelFlag((uint16)e_SoundType_DynamicBrake0_5Hz_2);
	if(0x02 != ChimeGlobalData_s.TT_SelfCheck_u8)
	{
		(void)Chime_GetInterface_SelfCheck_Element(&Check_flag);
		if(FALSE != Check_flag)
		{
			ChimeGlobalData_s.TT_SelfCheck_u8 = 0x01;
		}
		else
		{
			ChimeGlobalData_s.TT_CheckTimerOutCounter_u8 ++;
			if((0x01 == ChimeGlobalData_s.TT_SelfCheck_u8) || (ChimeGlobalData_s.TT_CheckTimerOutCounter_u8 >= 150))
			{
				ChimeGlobalData_s.TT_SelfCheck_u8 = 0x02;//check over
			}
		}
	}

	if((0x02 == config_u8_B) && (0x02 == ChimeGlobalData_s.TT_SelfCheck_u8))
	{
		if(0x01 == message_use)
		{
			CanSts_u8 = Chime_GetMessage_CDPActv_0x137(&CDPActv_0x137_u8);
			if((FALSE != CHIME_CAN_STATUS(CanSts_u8)) && (0x01 == CDPActv_0x137_u8))
			{
				Chime_RequestFlag((uint16)e_SoundType_DynamicBrake0_5Hz_1);
			}
		}
		else if(0x00 == message_use)
		{
			CanSts_u8 = Chime_GetMessage_CDPActv_0x145(&CDPActv_0x145_u8);
			if((FALSE != CHIME_CAN_STATUS(CanSts_u8)) && (0x01 == CDPActv_0x145_u8))
			{
				Chime_RequestFlag((uint16)e_SoundType_DynamicBrake0_5Hz_2);
			}
		}
	}
}
/**********************************************************************************************************
*Function   : SWC_ChimeCDPCancel                                                                          *
*                                                                                                         *
*Description:  Chime CDP sound request cancel                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeCDPCancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_DynamicBrake0_5Hz_1);
	Chime_CancelFlag((uint16)e_SoundType_DynamicBrake0_5Hz_2);
	ChimeGlobalData_s.TT_CheckTimerOutCounter_u8 = 0;
	ChimeGlobalData_s.TT_SelfCheck_u8 = 0;
}
/**********************************************************************************************************
*Function   : SWC_ChimeTickTockLEDCheck                                                                      *
*                                                                                                         *
*Description: Chime Left/Right turn sound request judge                                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeTickTockLEDCheck(void)
{
	uint8 LTurnLmpSts_R_u8,RTurnLmpSts_R_u8,leftLED,rightLED;
	uint8 leftSts = 0;
	uint8 rightSts = 0;
	uint8 msgSts;
	uint8 u8TurnRight_Config_Byte38;
	uint8 u8TurnRight_Config_Byte80;
	
	u8TurnRight_Config_Byte38 = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_SMART_JUNCTION_BOX);
	u8TurnRight_Config_Byte80 = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE);
	
	msgSts = Chime_GetMessage_LTurnLmpSts_R_Pbox(&LTurnLmpSts_R_u8);
	msgSts = Chime_GetMessage_RTurnLmpSts_R_Pbox(&RTurnLmpSts_R_u8);

	if(((0x01 == u8TurnRight_Config_Byte38) || (0x01 == u8TurnRight_Config_Byte80)) && (FALSE != CHIME_CAN_STATUS(msgSts)))
	{
		if(0x01 == LTurnLmpSts_R_u8)
		{
			leftLED = 1;
		}
		else
		{
			leftLED = 0;
		}
		if(0x01 == RTurnLmpSts_R_u8)
		{
			rightLED = 1;
		}
		else
		{
			rightLED = 0;
		}
	}
	else
	{
		leftLED = 0;
		rightLED = 0;
	}
	//Wait for hmi alive[wcao/20210509]
	if(0x02 == Chime_RteChimeSocReady())
	{
		if (Chime_FirstSoundFlag_u8 == 0x0u)
		{
			ChimeGlobalData_s.TickLastSts_u8 = leftLED;
			ChimeGlobalData_s.TockLastSts_u8 = rightLED;
			Chime_FirstSoundFlag_u8 = 1u;
			
		}
		else
		{
			
			if((ChimeGlobalData_s.TickLastSts_u8 != leftLED))
			{
				if(0x01 == leftLED)
				{
					leftSts = 0x1;
				}
				else
				{
					leftSts = 0x2;
				}
			}
			if((ChimeGlobalData_s.TockLastSts_u8 != rightLED))
			{
				if(0x01 == rightLED)
				{
					rightSts = 0x1;
				}
				else
				{
					rightSts = 0x2;
				}
			}
		}
		
		if((0x01 == leftSts) && (0x01 == rightSts))
		{
			Chime_RequestFlag((uint16)e_SoundType_PositionTickOnce_1);
			Chime_CancelFlag((uint16)e_SoundType_PositionTockOnce_1);
			Chime_CancelFlag((uint16)e_SoundType_TurnLeftTickOnce_1);
			Chime_CancelFlag((uint16)e_SoundType_TurnLeftTockOnce_1);
			Chime_CancelFlag((uint16)e_SoundType_TurnRightTickOnce_1);
			Chime_CancelFlag((uint16)e_SoundType_TurnRightTockOnce_1);
		}
		else if((0x02 == leftSts) && (0x02 == rightSts))
		{
			Chime_CancelFlag((uint16)e_SoundType_PositionTickOnce_1);
			Chime_RequestFlag((uint16)e_SoundType_PositionTockOnce_1);
			Chime_CancelFlag((uint16)e_SoundType_TurnLeftTickOnce_1);
			Chime_CancelFlag((uint16)e_SoundType_TurnLeftTockOnce_1);
			Chime_CancelFlag((uint16)e_SoundType_TurnRightTickOnce_1);
			Chime_CancelFlag((uint16)e_SoundType_TurnRightTockOnce_1);
		}
		else
		{

			if(0x01 == leftSts)
			{
				Chime_RequestFlag((uint16)e_SoundType_TurnLeftTickOnce_1);
				Chime_CancelFlag((uint16)e_SoundType_TurnLeftTockOnce_1);
				Chime_CancelFlag((uint16)e_SoundType_PositionTickOnce_1);
				Chime_CancelFlag((uint16)e_SoundType_PositionTockOnce_1);
			}
			else if(0x02 == leftSts)
			{
				 Chime_CancelFlag((uint16)e_SoundType_TurnLeftTickOnce_1);
				Chime_RequestFlag((uint16)e_SoundType_TurnLeftTockOnce_1);
				Chime_CancelFlag((uint16)e_SoundType_PositionTickOnce_1);
				Chime_CancelFlag((uint16)e_SoundType_PositionTockOnce_1);
			}
			else
			{
			}
			if(0x01 == rightSts)
			{
				Chime_RequestFlag((uint16)e_SoundType_TurnRightTickOnce_1);
				Chime_CancelFlag((uint16)e_SoundType_TurnRightTockOnce_1);
				Chime_CancelFlag((uint16)e_SoundType_PositionTickOnce_1);
				Chime_CancelFlag((uint16)e_SoundType_PositionTockOnce_1);
			}
			else if(0x02 == rightSts)
			{
				Chime_CancelFlag((uint16)e_SoundType_TurnRightTickOnce_1);
				Chime_RequestFlag((uint16)e_SoundType_TurnRightTockOnce_1);
				Chime_CancelFlag((uint16)e_SoundType_PositionTickOnce_1);
				Chime_CancelFlag((uint16)e_SoundType_PositionTockOnce_1);
			}
			else
			{
			}
		}
	
		ChimeGlobalData_s.TickLastSts_u8 = leftLED;
		ChimeGlobalData_s.TockLastSts_u8 = rightLED;
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimeTickTockLEDCheck                                                                   *
*                                                                                                         *
*Description: Chime Left/Right turn sound request judge                                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeTickTockLEDCancel(void)
{
	ChimeGlobalData_s.TickLastSts_u8 = 0;
	ChimeGlobalData_s.TockLastSts_u8 = 0;
	Chime_CancelFlag((uint16)e_SoundType_PositionTickOnce_1);
	Chime_CancelFlag((uint16)e_SoundType_PositionTockOnce_1);
	Chime_CancelFlag((uint16)e_SoundType_TurnLeftTickOnce_1);
	Chime_CancelFlag((uint16)e_SoundType_TurnLeftTockOnce_1);
	Chime_CancelFlag((uint16)e_SoundType_TurnRightTickOnce_1);
	Chime_CancelFlag((uint16)e_SoundType_TurnRightTockOnce_1);
}

/**********************************************************************************************************
*Function   : SWC_ChimeOverspeedLEDCheck                                                                     *
*                                                                                                         *
*Description: Chime overspeed sound request judge                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeOverspeedLEDCheck(uint8 Ledsts)
{
	//跟随报警灯，所以不需要判断配置字条件
	
	if((ChimeGlobalData_s.OverspeedLastSts_u8 != Ledsts) && (0x02 == Ledsts))
	{
		Chime_RequestFlag((uint16)e_SoundType_OverSpeed1Hz_SPEED_1);
		ChimeGlobalData_s.OverspeedLEDSts_u8 = 1;//TRUE;
	}
	else
	{
		if(0x02 != Ledsts)
		{
			Chime_CancelFlag((uint16)e_SoundType_OverSpeed1Hz_SPEED_1);
			ChimeGlobalData_s.OverspeedLEDSts_u8 = 0;//FALSE;
		}
	}
	ChimeGlobalData_s.OverspeedLastSts_u8 = Ledsts;

}

/**********************************************************************************************************
*Function   : SWC_ChimeOverspeedLEDCheck                                                                     *
*                                                                                                         *
*Description: Chime overspeed sound request judge                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeOverspeedIndia80Check(uint8 flag,uint8 enable,uint16 bit)
{
	//跟随warning，所以不需要判断配置字条件
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeOverspeedIndia80Check] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeOverspeedIndia80Check] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_India80Speed1Hz_SPEED_1);
			ChimeGlobalData_s.Overspeed80kmT_s.WrnSts_u8 = 1;//TRUE;
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_India80Speed1Hz_SPEED_1);
			ChimeGlobalData_s.Overspeed80kmT_s.WrnSts_u8 = 0;//FALSE;
			SWC_ChimeOverspeedIndia80Timer(0);
		}
	}


}
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
void SWC_ChimeOverspeedIndia80Timer(uint8 sts)
{
	if((FALSE != sts) && (FALSE != ChimeGlobalData_s.Overspeed80kmT_s.WrnSts_u8))
	{
		ChimeGlobalData_s.Overspeed80kmT_s.TimerSts_u8 = (uint8)e_OstmStatus_Runing;
		ChimeGlobalData_s.Overspeed80kmT_s.TimerCnt_u32 = (uint32)CHIME_80KM_OVERSPEED_TIMER;
	}
	else
	{
		ChimeGlobalData_s.Overspeed80kmT_s.TimerSts_u8 = (uint8)e_OstmStatus_Clear;
	}
}
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
void SWC_ChimeProcessTimerCheck(uint32 passtime)
{
	uint8 temp;
	uint8 release_falg_u8 = 1;//TRUE;
	s_ChimeOstmData_t *timer_ptr;
	if(e_OstmStatus_Runing == ChimeGlobalData_s.Overspeed80kmT_s.TimerSts_u8)
	{
		if(ChimeGlobalData_s.Overspeed80kmT_s.TimerCnt_u32 > passtime)
		{
			ChimeGlobalData_s.Overspeed80kmT_s.TimerCnt_u32 -= passtime;
		}
		else
		{
			ChimeGlobalData_s.Overspeed80kmT_s.TimerSts_u8 = (uint8)e_OstmStatus_TimeOver;
			Chime_RequestFlagRepeat((uint16)e_SoundType_India80Speed1Hz_SPEED_1);
		}
	}
	Chime_RteAdaptTimerPass(&ChimeGlobalData_s.CruiseStartT_s,passtime);
	Chime_RteAdaptTimerPass(&ChimeGlobalData_s.CruiseActiveT_s,passtime);
	Chime_RteAdaptTimerPass(&ChimeGlobalData_s.CruiseDownT_s,passtime);
	for(temp = 0;temp < 6;temp ++)
	{
		Chime_RteAdaptTimerPass(&ChimeGlobalData_s.DoorOpenTab_s[temp],passtime);
		if((CHIME_OSTM_TIMER_RUNING == ChimeGlobalData_s.DoorOpenTab_s[temp].Status_u8) && (0 < ChimeGlobalData_s.DoorOpenTab_s[temp].TimerTick_u32))
		{
			release_falg_u8 = 0;//FALSE;
		}
	}
	if(TRUE == release_falg_u8)
	{
		timer_ptr = Chime_OStmGetTimer((uint8)e_SoundType_DoorOpen1_5Hz);
		timer_ptr->TimerTick_u32 = 0;
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimeOverspeedLEDCheck                                                                  *
*                                                                                                         *
*Description: Chime overspeed sound request judge                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeOverspeedIndia120Check(uint8 flag,uint8 enable,uint16 bit)
{
	//跟随warning，所以不需要判断配置字条件
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeOverspeedIndia120Check] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeOverspeedIndia120Check] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_India120Speed1Hz_SPEED_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_India120Speed1Hz_SPEED_1);
		}
	}

}

/**********************************************************************************************************
*Function   : SWC_ChimeOverspeedCheck                                                                     *
*                                                                                                         *
*Description: Chime Warning with SWC_ChimeOverspeedCheck  sound request                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeOverspeedCheck(uint8 flag,uint8 enable,uint16 bit)
{
	//跟随warning，所以不需要判断配置字条件
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeOverspeedCheck] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeOverspeedCheck] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_OverSpeedAlarm1Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_OverSpeedAlarm1Hz_Wrn_1);
		}
	}

}

/**********************************************************************************************************
*Function   : SWC_ChimeTSRCheck                                                                           *
*                                                                                                         *
*Description: Chime TSR sound request judge                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeTSRCheck(void)
{
	uint8 config_u8 = Chime_RteAdaptGetVconfig(VCONFIG_KIND_TRAFFIC_SIGN_WARNING);
	uint8 Can0x2CFSts_u8;
	uint8 TSRSts_u8;
	uint8 TSRSpdLimSts_u8;
	uint8 TSRSpdLim_u8;
	uint8 TSRSpdLimWarn_u8;

#ifdef CHIME_PROCESS_TEST
	config_u8 = 0x01;
#endif
	if((01 <= config_u8) && (04 >= config_u8)/* && (0 == ChimeGlobalData_s.LEDTSR120KMHData_u8)*//* && (0 == ChimeGlobalData_s.OverspeedLEDSts_u8) cancel by caowenping,Sys cancel connect to oversped*/)
	{
/*START RTE interface*/
		Can0x2CFSts_u8 = Chime_GetMessage_TSRSts(&TSRSts_u8);
		Can0x2CFSts_u8 = Chime_GetMessage_TSRSpdLimSts(&TSRSpdLimSts_u8);
		Can0x2CFSts_u8 = Chime_GetMessage_TSRSpdLim(&TSRSpdLim_u8);
		Can0x2CFSts_u8 = Chime_GetMessage_TSRSpdLimWarn(&TSRSpdLimWarn_u8);
		//Can0x2CFSts_u8 = Rte_Read_TSRConSpdLim_TSRConSpdLim(&TSRConSpdLim_u8);
		//Can0x2CFSts_u8 = Rte_Read_TSRConSpdLimWarn_TSRConSpdLimWarn(&TSRConSpdLimWarn_u8);
/*END RTE interface*/
		if((FALSE!= CHIME_CAN_STATUS(Can0x2CFSts_u8)) && ((0x01 == TSRSts_u8) || (0x02 == TSRSts_u8) || (0x03 == TSRSts_u8)))
		{
			if((0x01 == TSRSpdLimSts_u8) && (0x01 == TSRSpdLimWarn_u8))
			{
				if((0x00 < TSRSpdLim_u8) && (0x1E >= TSRSpdLim_u8))
				{
					if(ChimeGlobalData_s.TSRSpdLimLValue_u8 != TSRSpdLim_u8)
					{
						if(0 == ChimeGlobalData_s.LEDTSR120KMHData_u8)
						{
							Chime_RequestFlagRepeat((uint16)e_SoundType_TsrOnce_TSR_1);
							ChimeGlobalData_s.TSRSpdLimLValue_u8 = TSRSpdLim_u8;
						}
					}
				}
				else
				{
					ChimeGlobalData_s.TSRSpdLimLValue_u8 = 0xff;
				}
			}
			else
			{
				ChimeGlobalData_s.TSRSpdLimLValue_u8 = 0xff;
			}
		}
		else
		{
			ChimeGlobalData_s.TSRSpdLimLValue_u8 = 0xff;
		}
	}
	else
	{
		ChimeGlobalData_s.TSRSpdLimLValue_u8 = 0xff;
	}

}
/**********************************************************************************************************
*Function   : SWC_ChimeTSRCancel                                                                          *
*                                                                                                         *
*Description: Chime TSR sound request cancel                                                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeTSRCancel(void)
{
	ChimeGlobalData_s.TSRSpdLimLValue_u8 = 0xff;
}


/**********************************************************************************************************
*Function   : SWC_ChimeFELDCheck                                                                          *
*                                                                                                         *
*Description: Chime Front axle differential lock sound request judge                                      *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeFELDCheck(void)
{
	uint8 config_u8 = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_LIMITED_SLIP_DIFFERRENTIAL);
	uint8 CanSts_u8 = 0;
	uint8 FrntELDLckSts_u8 = 0;
	Chime_CancelFlag((uint16)e_SoundType_FLockOnce_FLOCK_1);
	Chime_CancelFlag((uint16)e_SoundType_FLockOnce_FLOCK_2);


	if((0x02 == config_u8) || (0x04 == config_u8))
	{
/*START RTE interface*************************************************************************************/
		CanSts_u8 = Chime_GetMessage_FrntELDLckSts(&FrntELDLckSts_u8);
/*END RTE interface  *************************************************************************************/
		if(FALSE != CHIME_CAN_STATUS(CanSts_u8))
		{
			if(0x0E == FrntELDLckSts_u8)
			{
				ChimeGlobalData_s.FELDLastSts_u8 = 1;//TRUE;
				Chime_RequestFlag((uint16)e_SoundType_FLockOnce_FLOCK_1);
			}
			else
			{
				ChimeGlobalData_s.FELDLastSts_u8 = 0;//FALSE;
			}
		}
		else
		{
			if((FALSE == ChimeGlobalData_s.FELDLastSts_u8) && (RTE_E_INVALID_SIGNAL_DIFPROJET != CHIME_CAN_STATUS(CanSts_u8)))
			{
				Chime_RequestFlag((uint16)e_SoundType_FLockOnce_FLOCK_2);
			}
		}
	}
	else
	{
		ChimeGlobalData_s.FELDLastSts_u8 = 0;//FALSE;
	}
	
}
/**********************************************************************************************************
*Function   : SWC_ChimeFELDCancel                                                                         *
*                                                                                                         *
*Description: Chime Front axle differential lock sound request cancel                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeFELDCancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_FLockOnce_FLOCK_1);
	Chime_CancelFlag((uint16)e_SoundType_FLockOnce_FLOCK_2);
	ChimeGlobalData_s.FELDLastSts_u8 = 0;//FALSE;
}

/**********************************************************************************************************
*Function   : SWC_ChimeRELDCheck                                                                          *
*                                                                                                         *
*Description: Chime rear  axle differential lock sound request judge                                      *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeRELDCheck(void)
{
	uint8 config_u8 = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_LIMITED_SLIP_DIFFERRENTIAL);
	uint8 CanSts_u8;
	uint8 RearELDLckSts_u8;

	Chime_CancelFlag((uint16)e_SoundType_RLockOnce_RLOCK_1);
	Chime_CancelFlag((uint16)e_SoundType_RLockOnce_RLOCK_2);
	if((0x03 == config_u8) || (0x04 == config_u8))
	{
/*START RTE interface*************************************************************************************/
		CanSts_u8 = Chime_GetMessage_RearELDLckSts(&RearELDLckSts_u8);
/*END RTE interface  *************************************************************************************/
		if(FALSE != CHIME_CAN_STATUS(CanSts_u8))
		{
			if(0x0E == RearELDLckSts_u8)
			{
				ChimeGlobalData_s.RELDLastSts_u8 = 1;//TRUE;
				Chime_RequestFlag((uint16)e_SoundType_RLockOnce_RLOCK_1);
			}
			else
			{
				ChimeGlobalData_s.RELDLastSts_u8 = 0;//FALSE;
			}
		}
		else
		{
			if((FALSE == ChimeGlobalData_s.RELDLastSts_u8) && (RTE_E_INVALID_SIGNAL_DIFPROJET != CHIME_CAN_STATUS(CanSts_u8)))
			{
				Chime_RequestFlag((uint16)e_SoundType_RLockOnce_RLOCK_2);
			}
		}
	}
	else
	{
		ChimeGlobalData_s.RELDLastSts_u8 = FALSE;
	}

}
/**********************************************************************************************************
*Function   : SWC_ChimeRELDCancel                                                                         *
*                                                                                                         *
*Description: Chime rear  axle differential lock sound request cancel                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeRELDCancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_RLockOnce_RLOCK_1);
	Chime_CancelFlag((uint16)e_SoundType_RLockOnce_RLOCK_2);
	ChimeGlobalData_s.RELDLastSts_u8 = FALSE;
}

/**********************************************************************************************************
*Function   : SWC_ChimeCCOLEDCheck                                                                           *
*                                                                                                         *
*Description: Chime CCO sound request judge                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeCCOLEDCheck(uint8 Ledsts)
{
	//跟随报警灯，所以不需要判断配置字条件
	if((ChimeGlobalData_s.CCOLEDLastSts_u8 != Ledsts) && (0x01 == Ledsts))
	{
		Chime_RequestFlag((uint16)e_SoundType_CCOOnce_COO_1);
	}
	else
	{
		if(0x01 != Ledsts)
		{
			Chime_CancelFlag((uint16)e_SoundType_CCOOnce_COO_1);
		}
	}
	ChimeGlobalData_s.CCOLEDLastSts_u8 = Ledsts;

}

/**********************************************************************************************************
*Function   : SWC_ChimeTABLEDCheck                                                                        *
*                                                                                                         *
*Description: Chime TAB sound request judge                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeTABLEDCheck(uint8 Ledsts)
{
	//跟随报警灯，所以不需要判断配置字条件
	if((ChimeGlobalData_s.TabLEDLastSts_u8 != Ledsts) && (0x01 == Ledsts))
	{
		Chime_RequestFlag((uint16)e_SoundType_TABFailOnce_TAB_1);
	}
	else
	{
		if(0x01 != Ledsts)
		{
			Chime_CancelFlag((uint16)e_SoundType_TABFailOnce_TAB_1);
		}
	}
	ChimeGlobalData_s.TabLEDLastSts_u8 = 0;

}

/**********************************************************************************************************
*Function   : SWC_ChimeTABLEDCheck                                                                        *
*                                                                                                         *
*Description: Chime TAB sound request judge                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeREADYLEDCheck(uint8 Ledsts)
{
	//跟随报警灯，但Ready灯有两个，需要判断配置字
	uint8 ReadyLEDEngable_u8 = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_FUEL);
	if(5U == ReadyLEDEngable_u8)
	{	
		// modify by Xu,2021/08/17  Unbond TT  when the value is 1
		/*if((ChimeGlobalData_s.READYLEDLastSts_u8 != Ledsts) && (0x01 == Ledsts))
		{
			Chime_RequestFlag(e_SoundType_PowerOnOnce);
		}
		else
		{
			if(0x01 != Ledsts)
			{
				Chime_CancelFlag(e_SoundType_PowerOnOnce);
			}
		}*/

		if((ChimeGlobalData_s.READYLEDLastSts_u8 != Ledsts) && (0x02 == Ledsts))
		{
			Chime_RequestFlag((uint16)e_SoundType_Reserved);
		}
		else
		{
			if(0x02 != Ledsts)
			{
				Chime_CancelFlag((uint16)e_SoundType_Reserved);
			}
		}		
		ChimeGlobalData_s.READYLEDLastSts_u8 = 0;
	}
}


/**********************************************************************************************************
*Function   : SWC_ChimeHVolDoorEVCheck                                                                    *
*                                                                                                         *
*Description: Chime The driver leaves the car door after applying high voltage sound request judge        *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeHVolDoorEVCheck(void)
{
#if 0
	uint8 config_u8 = Chime_RteAdaptGetVconfig(VCONFIG_KIND_FUEL);
	uint8 CanSts_u8[3] = {0};
	uint8 DrvDoorSts_u8 = 0;
	uint8 VCU_RdyLEDSts_u8 = 0;
	uint8 VCU_GearStsIP_u8 = 0;

	SWC_ChimeHVolDoorEVCancel();

	//CHIME_PROJECT_TYPE_B02 and CHIME_PROJECT_TYPE_B03 cancel
	if(0x05 == config_u8)
	{
/*START RTE interface*************************************************************************************/
		CanSts_u8[0] = Rte_Read_DrvDoorSts_DrvDoorSts(&DrvDoorSts_u8);
		//DBC missing signal
		//CanSts_u8[1] = Rte_Read_VCU_RdyLEDSts_VCU_RdyLEDSts(&VCU_RdyLEDSts_u8);
		//CanSts_u8[2] = Rte_Read_VCU_GearStsIP_VCU_GearStsIP(&VCU_GearStsIP_u8);
/*END	RTE interface*************************************************************************************/
		if((FALSE != CHIME_CAN_STATUS(CanSts_u8[0]))
		&& (FALSE != CHIME_CAN_STATUS(CanSts_u8[1])) && (FALSE != CHIME_CAN_STATUS(CanSts_u8[2])))
		{
			if((0x01 == DrvDoorSts_u8) && (0x01 == VCU_RdyLEDSts_u8) && ((0x02 == VCU_GearStsIP_u8) || (0x04 == VCU_GearStsIP_u8)))
			{
				Chime_RequestFlag(e_SoundType_HighVol0_5Hz_EV_1);
			}
		}
	}
#else
	Chime_CancelFlag((uint16)e_SoundType_HighVol0_5Hz_EV_1);
#endif
}
/**********************************************************************************************************
*Function   : SWC_ChimeHVolDoorEVCancel                                                                   *
*                                                                                                         *
*Description: Chime The driver leaves the car door after applying high voltage sound request judge        *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeHVolDoorEVCancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_HighVol0_5Hz_EV_1);
}

/**********************************************************************************************************
*Function   : SWC_ChimeHVolDoorPHEVCheck                                                                  *
*                                                                                                         *
*Description: Chime The driver leaves the car door after applying high voltage sound request judge        *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeHVolDoorPHEVCheck(void)
{
	uint8 configF_u8 = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_FUEL);
	uint8 configE_u8 = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_ELECTROMOTOR_POSITION);
	uint8 CanSts_u8[3] = {0};
	uint8 DrvDoorSts_u8 = 0;
	uint8 TGS_LEVER_u8 = 0;
	uint8 HCU_RdyLmpSts_u8 = 0;

	SWC_ChimeHVolDoorPHEVCancel();

	//CHIME_PROJECT_TYPE_B02 and CHIME_PROJECT_TYPE_B03 cancel
	if(((0x03 == configF_u8) || (0x04 == configF_u8)) && ((0x02 == configE_u8) || (0x04 == configE_u8) || (0x08 == configE_u8)))
	{
/*START RTE interface*************************************************************************************/
		CanSts_u8[0] = Chime_GetMessage_DrvDoorSts(&DrvDoorSts_u8);
		CanSts_u8[1] = Chime_GetMessage_HCU_RdyLmpSts(&HCU_RdyLmpSts_u8);
		CanSts_u8[2] = Chime_GetMessage_TGS_LEVER(&TGS_LEVER_u8);
/*END	RTE interface*************************************************************************************/
		if((FALSE != CHIME_CAN_STATUS(CanSts_u8[0])) && (FALSE != CHIME_CAN_STATUS(CanSts_u8[1])) 
		&& (FALSE != CHIME_CAN_STATUS(CanSts_u8[2]))) 
		{
			if((0x01 == DrvDoorSts_u8) && (0x01 == HCU_RdyLmpSts_u8) 
			&& ((0x05 == TGS_LEVER_u8) || (0x07 == TGS_LEVER_u8) || (0x08 == TGS_LEVER_u8)))
			{
				Chime_RequestFlag((uint16)e_SoundType_HighVol0_5Hz_PHEV_2);
			}
		}
	}

}

/**********************************************************************************************************
*Function   : SWC_ChimeHVolDoorPHEVCancel                                                                 *
*                                                                                                         *
*Description: Chime The driver leaves the car door after applying high voltage sound request judge        *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeHVolDoorPHEVCancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_HighVol0_5Hz_PHEV_2);
}
/**********************************************************************************************************
*Function   : SWC_ChimeHVolDoorRE300Check                                                                 *
*                                                                                                         *
*Description: Chime The driver leaves the car door after applying high voltage sound request judge        *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2021-01-20                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeHVolDoorRE300Check(void)
{
	uint8 configF_u8 = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_FUEL);
	uint8 configE_u8 = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_ELECTROMOTOR_POSITION);
	uint8 CanSts_u8[3] = {0};
	uint8 DrvDoorSts_u8 = 0;
	uint8 DrvModDisp_0x201_u8 = 0;
	uint8 HCU_RdyLmpSts_u8 = 0;

	SWC_ChimeHVolDoorRE300Cancel();
	
	//CHIME_PROJECT_TYPE_B02 and CHIME_PROJECT_TYPE_B03 cancel
	if(((0x04 == configF_u8) || (0x03 == configF_u8)) && ((0x05 == configE_u8) || (0x06 == configE_u8)))
	{
/*START RTE interface*************************************************************************************/
		CanSts_u8[0] = Chime_GetMessage_DrvDoorSts(&DrvDoorSts_u8);
		CanSts_u8[1] = Chime_GetMessage_DrvModDisp_0x201(&DrvModDisp_0x201_u8);
		CanSts_u8[2] = Chime_GetMessage_HCU_RdyLmpSts(&HCU_RdyLmpSts_u8);
/*END	RTE interface*************************************************************************************/
		if((FALSE != CHIME_CAN_STATUS(CanSts_u8[0])) && (FALSE != CHIME_CAN_STATUS(CanSts_u8[1])) 
		&& (FALSE != CHIME_CAN_STATUS(CanSts_u8[2]))) 
		{
			if((0x01 == DrvDoorSts_u8) && (0x01 == HCU_RdyLmpSts_u8) 
			&& ((0x01 == DrvModDisp_0x201_u8) || (0x03 == DrvModDisp_0x201_u8) || (0x04 == DrvModDisp_0x201_u8)))
			{
				Chime_RequestFlag((uint16)e_SoundType_HighVol0_5Hz_RE300_3);
			}
		}
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimeHVolDoorRE300Cancel                                                                *
*                                                                                                         *
*Description: Chime The driver leaves the car door after applying high voltage sound request judge        *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2021-01-20                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeHVolDoorRE300Cancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_HighVol0_5Hz_RE300_3);
}

/**********************************************************************************************************
*Function   : SWC_ChimePandCheckD7DCTCheck                                                                *
*                                                                                                         *
*Description: Chime The first time check to D 7DCT config sound request judge                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePandCheckD7DCTCheck(void)
{
#if 0
	uint8 kindConfig = Chime_RteAdaptGetVconfig(VCONFIG_KIND_TRANSMISSION);
	uint8 localDisConfig = Chime_RteAdaptGetLconfig(ChimeLconfigFIXDISPLAY_1_GEAR_ENABLE);
	uint8 localShiftConfig = Chime_RteAdaptGetLconfig(ChimeLconfigFIXDISPLALY_2_SHIFT_GEAR_RECOMMEND_ENABLE);
	uint8 CanSts_u8 = 0;
	SG_DCT7 dctMsg;
	if(((0x06 == kindConfig) || (0x07 == kindConfig)) && (FALSE != localDisConfig) && (FALSE != localShiftConfig))
	{
/*START RTE interface*************************************************************************************/
		CanSts_u8 = Rte_Read_SG_DCT7_SG_DCT7(&dctMsg);
/*END	RTE interface*************************************************************************************/
		/*First wakeup*/
		if(FALSE != CHIME_CAN_STATUS(CanSts_u8))
		{
			if(((0x01 == dctMsg.DrvModDispSts_0x235) || (0x02 == dctMsg.DrvModDispSts_0x235))
			&& (0x00 == dctMsg.DrvModDispSts_0x235) && (0x03 == dctMsg.DrvModDisp_0x235) && (0x07 >= dctMsg.DrvAutoGearDisp))
			{
				if((FALSE != ChimeGlobalData_s.Gear7DCTFirstSigFlag_u8) && (FALSE == ChimeGlobalData_s.GearFirstFlag_u8))
				{
					ChimeGlobalData_s.GearFirstFlag_u8 = TRUE;//Set chime had palyed
					Chime_RequestFlag(e_SoundType_GearChangeOnce_D_1);
				}
			}
			else
			{
				ChimeGlobalData_s.Gear7DCTFirstSigFlag_u8 = TRUE;//7DCT config receive message flag
			}
		}
	}
#endif
}

/**********************************************************************************************************
*Function   : SWC_ChimePandCheckD7DCTCancel                                                               *
*                                                                                                         *
*Description: Chime The first time check to D 7DCT sound cancel judge                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePandCheckD7DCTCancel(void)
{
	//Chime_CancelFlag(e_SoundType_GearChangeOnce_D_1);
}

/**********************************************************************************************************
*Function   : SWC_ChimePandCheckD9DCTCheck                                                                *
*                                                                                                         *
*Description: Chime The first time check to D 9DCT config sound request judge                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePandCheckD9DCTCheck(void)
{
#if 0
	uint8 kindConfig = Chime_RteAdaptGetVconfig(VCONFIG_KIND_TRANSMISSION);
	uint8 CanStsFD_u8 = FALSE;
	uint8 DrvModDispSt_0x236_u8 = 0;
	uint8 DrvGearDispSts_0x236_u8 = 0;
	uint8 DrvModDisp_0x236_u8 = 0;
	uint8 DrvAutoGearDisp_0x236_u8 = 0;

	if((0x0F == kindConfig) || (0x10 == kindConfig))
	{
		
/*START RTE interface*************************************************************************************/
		//CanStsFD_u8 = Rte_Read_DrvModDispSt_DrvModDispSt(&DrvModDispSt_0x236_u8);
		//CanStsFD_u8 = Rte_Read_DrvGearDispSts_DrvGearDispSts(&DrvGearDispSts_0x236_u8);
		//CanStsFD_u8 = Rte_Read_DrvModDisp_0x236_DrvModDisp_0x236(&DrvModDisp_0x236_u8);
		//CanStsFD_u8 = Rte_Read_DrvAutoGearDisp_DrvAutoGearDisp(&DrvAutoGearDisp_0x236_u8);
/*END	RTE interface*************************************************************************************/
		if(FALSE != CHIME_CAN_STATUS(CanStsFD_u8))
		{
			if(((0x01 == DrvModDispSt_0x236_u8) || (0x02 == DrvModDispSt_0x236_u8))
			&& (0x00 == DrvGearDispSts_0x236_u8) && (0x03 == DrvModDisp_0x236_u8) && (0x07 >= DrvAutoGearDisp_0x236_u8))
			{
				if((FALSE != ChimeGlobalData_s.Gear9DCTFirstSigFlag_u8) && (FALSE == ChimeGlobalData_s.GearFirstFlag_u8))
				{
					ChimeGlobalData_s.GearFirstFlag_u8 = TRUE;//Set chime had palyed
					Chime_RequestFlag(e_SoundType_GearChangeOnce_D_1);
				}
			}
			else
			{
				ChimeGlobalData_s.Gear9DCTFirstSigFlag_u8 = TRUE;//9DCT config receive message flag
			}
		}
	}
#endif
}

/**********************************************************************************************************
*Function   : SWC_ChimePandCheckDCancel                                                                   *
*                                                                                                         *
*Description: Chime The first time check to D 9DCT config sound cancel judge                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePandCheckD9DCTCancel(void)
{
	//Chime_CancelFlag(e_SoundType_GearChangeOnce_D_1);
}

/**********************************************************************************************************
*Function   : SWC_ChimePandCheckD8ATCheck                                                                 *
*                                                                                                         *
*Description: Chime The first time check to D 8AT config sound request judge                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePandCheckD8ATCheck(void)
{
#if 0
	uint8 kindConfig = Chime_RteAdaptGetVconfig(VCONFIG_KIND_TRANSMISSION);
	uint8 localDisConfig = Chime_RteAdaptGetLconfig(ChimeLconfigFIXDISPLAY_1_GEAR_ENABLE);
	uint8 localShiftConfig = Chime_RteAdaptGetLconfig(ChimeLconfigFIXDISPLALY_2_SHIFT_GEAR_RECOMMEND_ENABLE);
	uint8 CanSts_u8 = FALSE;
	uint8 DrvModDisp_0x0C6_u8 = 0;
	uint8 DisplayGear_0x0C6_u8 = 0;
	uint8 TCU_Gear_flashing_0x0C6_u8 = 0;

	if((0x08 == kindConfig) && (FALSE != localDisConfig) && (FALSE != localShiftConfig))
	{
/*START RTE interface*************************************************************************************/
		//CanSts_u8 = Rte_Read_DrvModDisp_DrvModDisp(&DrvModDisp_0x0C6_u8);
		//CanSts_u8 = Rte_Read_DisplayGear_DisplayGear(&DisplayGear_0x0C6_u8);
		//CanSts_u8 = Rte_Read_TCU_Gear_flashing_TCU_Gear_flashing(&TCU_Gear_flashing_0x0C6_u8);
/*END   RTE interface*************************************************************************************/
		/*First wakeup*/
		if(FALSE != CHIME_CAN_STATUS(CanSts_u8))
		{
			if((0x03 == DrvModDisp_0x0C6_u8) && ((0x01 <= DisplayGear_0x0C6_u8) 
			&& (0x08 >= DisplayGear_0x0C6_u8)) && (0x01 >= TCU_Gear_flashing_0x0C6_u8))
			{
				if((FALSE != ChimeGlobalData_s.Gear8ATFirstSigFlag_u8) && (FALSE == ChimeGlobalData_s.GearFirstFlag_u8))
				{
					ChimeGlobalData_s.GearFirstFlag_u8 = TRUE;//Set chime had palyed
					Chime_RequestFlag(e_SoundType_GearChangeOnce_D_1);
				}
			}
			else
			{
				ChimeGlobalData_s.Gear8ATFirstSigFlag_u8 = TRUE;//7DCT config receive message flag
			}
		}
	}
#endif
}

/**********************************************************************************************************
*Function   : SWC_ChimePandCheckDCancel                                                                   *
*                                                                                                         *
*Description: Chime The first time check to D  8AT config sound cancel judge                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePandCheckD8ATCancel(void)
{
	//Chime_RequestFlag(e_SoundType_GearChangeOnce_D_1);
}
/**********************************************************************************************************
*Function   : SWC_ChimePandCheckDPHEVCheck                                                                *
*                                                                                                         *
*Description: Chime The first time check to D PHEV config sound request judge                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePandCheckDPHEVCheck(void)
{
#if 0
	uint8 fuelConfig = Chime_RteAdaptGetVconfig(VCONFIG_KIND_FUEL);
	uint8 elecConfig = Chime_RteAdaptGetVconfig(VCONFIG_KIND_ELECTROMOTOR_POSITION);
	uint8 localDisConfig = Chime_RteAdaptGetLconfig(ChimeLconfigDISPLAY_6_GEAR_ENABLE);
	uint8 localShiftConfig = Chime_RteAdaptGetLconfig(ChimeLconfigDISPLALY_6_SHIFT_GEAR_RECOMMEND_ENABLE);
	uint8 CanSts_u8 = 0;
	uint8 DrvModDisp_u8 = 0;
	uint8 DrvModDispSts_u8 = 0;
	if(((0x03 == fuelConfig) || (0x04 == fuelConfig)) && (0x05 == elecConfig) && (FALSE != localDisConfig) && (FALSE != localShiftConfig))
	{
/*START RTE interface*************************************************************************************/
		//CanSts_u8 = Rte_Read_DrvModDisp_DrvModDisp(&DrvModDisp_u8);
		//CanSts_u8 = Rte_Read_DrvModDispSts_DrvModDispSts(&DrvModDispSts_u8);
/*END	RTE interface*************************************************************************************/
		if(FALSE != CHIME_CAN_STATUS(CanSts_u8))
		{
			if(((0x01 == DrvModDispSts_u8) || (0x02 == DrvModDispSts_u8)) && (0x03 == DrvModDisp_u8))
			{
				if((FALSE != ChimeGlobalData_s.GearPHEVFirstSigFlag_u8) && (FALSE == ChimeGlobalData_s.GearFirstFlag_u8))
				{
					ChimeGlobalData_s.GearFirstFlag_u8 = TRUE;//Set chime had palyed
					Chime_RequestFlag(e_SoundType_GearChangeOnce_D_1);
				}
			}
			else
			{
				ChimeGlobalData_s.GearPHEVFirstSigFlag_u8 = TRUE;//PHEV config receive message flag
			}
		}
	}
#endif
}

/**********************************************************************************************************
*Function   : SWC_ChimePandCheckDPHEVCancel                                                               *
*                                                                                                         *
*Description: Chime The first time check to D PHEV config sound cancel judge                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePandCheckDPHEVCancel(void)
{
	
}
/**********************************************************************************************************
*Function   : SWC_ChimePandCheckDEVCheck                                                                  *
*                                                                                                         *
*Description: Chime The first time check to D EV config sound request judge                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePandCheckDEVCheck(void)
{
#if 0
	uint8 fuelConfig = Chime_RteAdaptGetVconfig(VCONFIG_KIND_FUEL);
	uint8 localDisConfig = Chime_RteAdaptGetLconfig(ChimeLconfigDISPLAY_6_GEAR_ENABLE);
	uint8 localShiftConfig = Chime_RteAdaptGetLconfig(ChimeLconfigDISPLALY_6_SHIFT_GEAR_RECOMMEND_ENABLE);
	uint8 CanSts_u8 = 0;
	uint8 VCU_GearStsIP_u8 = 0;
	
	if((0x05 == fuelConfig) && (FALSE != localDisConfig) && (FALSE != localShiftConfig))
	{
/*START RTE interface*************************************************************************************/
		//CanSts_u8 = Rte_Read_VCU_GearStsIP_VCU_GearStsIP(&VCU_GearStsIP_u8);
/*END	RTE interface*************************************************************************************/
		if(FALSE != CHIME_CAN_STATUS(CanSts_u8))
		{
			if(0x04 == VCU_GearStsIP_u8)
			{
				if((FALSE != ChimeGlobalData_s.GearEVFirstSigFlag_u8) && (FALSE == ChimeGlobalData_s.GearFirstFlag_u8))
				{
					ChimeGlobalData_s.GearFirstFlag_u8 = TRUE;//Set chime had palyed
					Chime_RequestFlag(e_SoundType_GearChangeOnce_D_1);
				}
			}
			else
			{
				ChimeGlobalData_s.GearEVFirstSigFlag_u8 = TRUE;//PHEV config receive message flag
			}
		}
	}
#endif
}

/**********************************************************************************************************
*Function   : SWC_ChimePandCheckDPHEVCancel                                                               *
*                                                                                                         *
*Description: Chime The first time check to D EV config sound cancel judge                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePandCheckDEVCancel(void)
{
	
}

/**********************************************************************************************************
*Function   : SWC_ChimeACCCruiseCheck                                                                     *
*                                                                                                         *
*Description: Chime The Acc curise sound request judge                                                    *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeACC_TJA_ICACheck(void)
{
#if 0

#if ((CHIME_PROJECT_TYPE_B03 == 1) || (CHIME_PROJECT_TYPE_B02 == 1) || (CHIME_PROJECT_TYPE_B06 == 1) || (CHIME_PROJECT_TYPE_P05 == 1) || (CHIME_PROJECT_TYPE_P03 == 1) || (CHIME_PROJECT_TYPE_A07 == 1))

	uint8 cruiseConfig = Chime_RteAdaptGetVconfig(VCONFIG_KIND_CRUISE_CONTROL);
	uint8 highWayConfig = Chime_RteAdaptGetVconfig(VCONFIG_KIND_HIGHWAY_ASSIST);
	uint8 CanSts_u8;
	uint8 HWA_ModDisp_u8;


	if((0x02 <= cruiseConfig) && (0x0B >= cruiseConfig) && (0x01 == highWayConfig))
	{
/*START RTE interface*************************************************************************************/
		CanSts_u8 = Chime_GetMessage_HWA_ModDisp(&HWA_ModDisp_u8);
/*END	RTE interface*************************************************************************************/
		if(FALSE != CHIME_CAN_STATUS(CanSts_u8))
		{
/*-------------------------------------------------------------------------------------------------------*/
			if((0x01 == HWA_ModDisp_u8) || (0x04 == HWA_ModDisp_u8) || (0x06 == HWA_ModDisp_u8) || (0x07 == HWA_ModDisp_u8))
			{
				Chime_RequestFlag(e_SoundType_CruiseActOnce_ACC_3);
			}
			else
			{
				Chime_CancelFlag(e_SoundType_CruiseActOnce_ACC_3);
			}
/*-------------------------------------------------------------------------------------------------------*/
		}
		else
		{
			SWC_ChimeACC_TJA_ICACancel();
		}
	}
	else
	{
		SWC_ChimeACC_TJA_ICACancel();
	}
#else
	SWC_ChimeACC_TJA_ICACancel();
#endif

#endif 
}

/**********************************************************************************************************
*Function   : SWC_ChimeACC_TJA_ICACancel                                                                  *
*                                                                                                         *
*Description: Chime The Acc curise sound cancel judge                                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeACC_TJA_ICACancel(void)
{
#if 0
	Chime_CancelFlag(e_SoundType_CruiseStartOnce_ACC_1);
	Chime_CancelFlag(e_SoundType_CruiseStartOnce_ACC_2);
	Chime_CancelFlag(e_SoundType_CruiseStartOnce_ACC_3);
	Chime_CancelFlag(e_SoundType_CruiseActOnce_ACC_1);
	Chime_CancelFlag(e_SoundType_CruiseActOnce_ACC_2);
	Chime_CancelFlag(e_SoundType_CruiseActOnce_ACC_3);
	Chime_CancelFlag(e_SoundType_CruiseDownOnce_ACC_1);
	Chime_CancelFlag(e_SoundType_CruiseDownOnce_ACC_2);
	ChimeGlobalData_s.ACC_CruiseStart_TJAFlag_u8 = FALSE;
	ChimeGlobalData_s.ACC_CruiseStart_ACCFlag_u8 = FALSE;
	ChimeGlobalData_s.ACC_CruiseStart_HWAFlag_u8 = FALSE;
	ChimeGlobalData_s.ACC_CruiseAct_TJAFlag_u8 = FALSE;
	ChimeGlobalData_s.ACC_CruiseAct_ACCFlag_u8 = FALSE;
	ChimeGlobalData_s.ACC_CruiseAct_HWAFlag_u8 = FALSE;
	ChimeGlobalData_s.ACC_CruiseLast_HWA_u8 = FALSE;
	ChimeGlobalData_s.ACC_CruiseLast_TJA_u8 = FALSE;
#endif
}

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
void SWC_ChimeACC_TJA_ICA_StartTimer(uint8 sts)
{
	uint32 Start_timer;
	if(FALSE != sts)
	{
		Start_timer = Chime_RteAdaptGetLconfig((uint8)ChimeLconfigChimedelaytime);
		Chime_RteAdaptTimerSet(&ChimeGlobalData_s.CruiseStartT_s,Start_timer);
	}
	else
	{
		Chime_RteAdaptTimerClr(&ChimeGlobalData_s.CruiseStartT_s);
	}
}

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
void SWC_ChimeACC_TJA_ICA_ActiveTimer(uint8 sts)
{
	uint32 Active_timer;
	if(FALSE != sts)
	{
		Active_timer = Chime_RteAdaptGetLconfig((uint8)ChimeLconfigChimedelaytime);
		Chime_RteAdaptTimerSet(&ChimeGlobalData_s.CruiseActiveT_s,Active_timer);
	}
	else
	{
		Chime_RteAdaptTimerClr(&ChimeGlobalData_s.CruiseActiveT_s);
	}
}
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
void SWC_ChimeACC_TJA_ICA_DownTimer(uint8 sts)
{
	uint32 Down_timer;
	if(FALSE != sts)
	{
		Down_timer = Chime_RteAdaptGetLconfig((uint8)ChimeLconfigChimedelaytime);
		Chime_RteAdaptTimerSet(&ChimeGlobalData_s.CruiseDownT_s,Down_timer);
	}
	else
	{
		Chime_RteAdaptTimerClr(&ChimeGlobalData_s.CruiseDownT_s);
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimePowerBatWarmCheck                                                                  *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_PowerBatWarm  sound request                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePowerBatWarmCheck(void)
{
#if ((CHIME_PROJECT_TYPE_B03 == 1) || (CHIME_PROJECT_TYPE_B02 == 1) || (CHIME_PROJECT_TYPE_P03 == 1) || \
	(CHIME_PROJECT_TYPE_D03 == 1) || (CHIME_PROJECT_TYPE_D02 == 1) || (CHIME_PROJECT_TYPE_D01 == 1) || (CHIME_PROJECT_TYPE_P02 == 1))
	uint8 EngineConfig = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_FUEL);
	uint8 ElecConfig = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_ELECTROMOTOR_POSITION);
	uint8 CanSts_u8[2] = {0};
	uint8 OBC_ConnectSts_u8;
	uint8 HCU_ChargSts_u8;
	SWC_ChimePowerBatWarmCancel();
	if((0x04 == EngineConfig) && ((0x02 == ElecConfig) || (0x04 == ElecConfig) || (0x05 == ElecConfig) || (0x06 == ElecConfig) || (0x08 == ElecConfig)))
	{
		CanSts_u8[0] = Chime_GetMessage_OBC_ConnectSts(&OBC_ConnectSts_u8);
		CanSts_u8[1] = Chime_GetMessage_HCU_ChargSts(&HCU_ChargSts_u8);
		if((FALSE != CHIME_CAN_STATUS(CanSts_u8[0])) && (FALSE != CHIME_CAN_STATUS(CanSts_u8[1])))
		{
			if((0x01 == OBC_ConnectSts_u8) && (0x06 == HCU_ChargSts_u8))
			{
				Chime_RequestFlag((uint16)e_SoundType_PowerBatWarmOnce_Wrn_1);
			}
		}
	}
#else
	SWC_ChimePowerBatWarmCancel();
#endif
}

/**********************************************************************************************************
*Function   : SWC_ChimePowerBatWarmCancel                                                                 *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_PowerBatWarm  sound cancel                                      *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimePowerBatWarmCancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_PowerBatWarmOnce_Wrn_1);
}

/**********************************************************************************************************
*Function   : SWC_ChimeLDWLKAELKLCKCheck                                                                  *
*                                                                                                         *
*Description: Chime Warning with SWC_ChimeLDWLKAELKLCKCheck  sound request                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2021-01-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeLDWLKAELKLCKCheck(void)
{
	uint8 VehicleCfg = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_LDW_LKA);
	uint8 LCKStsIndcr_u8;
	uint8 IntelligentEvaActSts_u8;
	uint8 LDW_LKAWarn_u8;
	uint8 MsgSts_23D[3];
	SWC_ChimeLDWLKAELKLCKCancel();
	if((0x00 != VehicleCfg) && (0x0D >= VehicleCfg))
	{
		MsgSts_23D[0] = Chime_GetMessage_LCKStsIndcr(&LCKStsIndcr_u8);
		MsgSts_23D[1] = Chime_GetMessage_IntelligentEvaActSts(&IntelligentEvaActSts_u8);
		MsgSts_23D[2] = Chime_GetMessage_LDW_LKAWarn(&LDW_LKAWarn_u8);
		if(FALSE != CHIME_CAN_STATUS(MsgSts_23D[0]))
		{
			if(0x01 == LCKStsIndcr_u8)
			{
				Chime_RequestFlag((uint16)e_SoundType_LckActOnce_Wrn_1);
			}
		}	
		if(FALSE != CHIME_CAN_STATUS(MsgSts_23D[1]))
		{
			if(0x01 == IntelligentEvaActSts_u8)
			{
				Chime_RequestFlag((uint16)e_SoundType_LeftSmartdodgeOnce_C1);
			}
			else if(0x02 == IntelligentEvaActSts_u8)
			{
				Chime_RequestFlag((uint16)e_SoundType_RightSmartdodgeOnce_C1);
			}
			else
			{
			}
		}
		if(FALSE != CHIME_CAN_STATUS(MsgSts_23D[2]))
		{
			if(0x01 == LDW_LKAWarn_u8)
			{
				Chime_RequestFlag((uint16)e_SoundType_SafeDrivRepeat_Wrn_1);
			}
			else if(0x02 == LDW_LKAWarn_u8)
			{
				Chime_RequestFlag((uint16)e_SoundType_SafeDrivRepeat_Wrn_2);
			}
			else
			{}
		}
	}

}

/**********************************************************************************************************
*Function   : SWC_ChimeLDWLKAELKLCKCancel                                                                 *
*                                                                                                         *
*Description: Chime Warning with SWC_ChimeLDWLKAELKLCKCancel  sound cancel                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2021-01-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeLDWLKAELKLCKCancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_LckActOnce_Wrn_1);
	Chime_CancelFlag((uint16)e_SoundType_LeftSmartdodgeOnce_C1);
	Chime_CancelFlag((uint16)e_SoundType_RightSmartdodgeOnce_C1);
	Chime_CancelFlag((uint16)e_SoundType_SafeDrivRepeat_Wrn_1);
	Chime_CancelFlag((uint16)e_SoundType_SafeDrivRepeat_Wrn_2);
	Chime_ClearField((uint16)e_SoundType_SafeDrivRepeat_Wrn_1);
}

/**********************************************************************************************************
*Function   : SWC_ChimeSleepCheck                                                                         *
*                                                                                                         *
*Description: Chime sleep or pre sleep or abnormal process                                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeSleepCheck(void)
{
	Chime_ProcessWarmInit();
}

/**********************************************************************************************************
*Function   : SWC_ChimeSleepCancel                                                                        *
*                                                                                                         *
*Description: Chime Not sleep or pre sleep or abnormal process                                            *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeSleepCancel(void)
{
	
}

/**********************************************************************************************************
*Function   : SWC_ChimeDWDCheck                                                                           *
*                                                                                                         *
*Description: Chime with SWC_ChimeDWDCheck  sound request                                                 *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : xu wei cheng                                                                                *
*                                                                                                         *
*Date       : 2021-06-02                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeDWDCheck(void)
{
		uint8 VehicleCfg = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_WATER_DEPTH_DETECTION);
		uint8 MsgSts_2B98;
		uint8 DWD_SoundIndcn_u8 = 0;
		
		SWC_ChimeDWDCancel();
		
		if(0x01 == VehicleCfg)
		{
			MsgSts_2B98 = Chime_GetMessage_DWD_SoundIndcn(&DWD_SoundIndcn_u8);

			if(FALSE != CHIME_CAN_STATUS(MsgSts_2B98))
			{
				if(0x01 == DWD_SoundIndcn_u8)
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarDWDLongRe_1);
				}
				else if(0x02 == DWD_SoundIndcn_u8)
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarDWD3Hz_1);
				}
				else if(0x03 == DWD_SoundIndcn_u8)
				{
					Chime_RequestFlag((uint16)e_SoundType_RadarDWD1_5Hz_1);
				}
				else
				{
					//do nothing 
				}
					
			}
		}

}

/**********************************************************************************************************
*Function   : SWC_ChimeDWDCancel                                                                          *
*                                                                                                         *
*Description: Chime  with SWC_ChimeDWDCancel  sound cancel                                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : xu wei cheng                                                                                *
*                                                                                                         *
*Date       : 2021-06-02                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeDWDCancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_RadarDWDLongRe_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarDWD3Hz_1);
	Chime_CancelFlag((uint16)e_SoundType_RadarDWD1_5Hz_1);

}


/**********************************************************************************************************
*Function   : SWC_ChimeChargeFaultCheck                                                                           *
*                                                                                                         *
*Description: Chime with SWC_ChimeChargeFaultCheck  sound request                                                 *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wangtingting                                                                                *
*                                                                                                         *
*Date       : 2021-10-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeChargeFaultCheck(void)
{
#if ((CHIME_PROJECT_TYPE_B03 == 1) || (CHIME_PROJECT_TYPE_B02 == 1) || (CHIME_PROJECT_TYPE_P03 == 1) || \
		(CHIME_PROJECT_TYPE_D03 == 1) || (CHIME_PROJECT_TYPE_D02 == 1) || (CHIME_PROJECT_TYPE_D01 == 1) || (CHIME_PROJECT_TYPE_P02 == 1))
	uint8 VehicleCfg = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_FUEL);
	uint8 EleMotorCfg = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_ELECTROMOTOR_POSITION);
	TC_NE_ChargStsOutput sTC_NE_ChargStsOut;

	SWC_ChimeChargeFaultCancel();
	if((4u == VehicleCfg) && ((5u == EleMotorCfg) || (6u == EleMotorCfg)))
	{
		
		(void)Chime_GetInterface_TC_NE_ChargStsOutput_Element(&sTC_NE_ChargStsOut);
		
		if(0x01 == sTC_NE_ChargStsOut.ChargFaultSts)
		{
			Chime_RequestFlag((uint16)e_SoundType_ChargeFaultOnce_1);
		}
		else
		{
			//do nothing 
		}
	}
#else
	SWC_ChimeChargeFaultCancel();
#endif
}

/**********************************************************************************************************
*Function   : SWC_ChimeDWDCancel                                                                          *
*                                                                                                         *
*Description: Chime  with SWC_ChimeChargeFaultCancel  sound cancel                                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wangtingting                                                                                *
*                                                                                                         *
*Date       : 2021-10-08                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeChargeFaultCancel(void)
{
	Chime_CancelFlag((uint16)e_SoundType_ChargeFaultOnce_1);
}
/**********************************************************************************************************
*Function   : SWC_ChimeCELDCheck                                                                           *
*                                                                                                         *
*Description: Chime with SWC_ChimeCELDCheck  sound request                                                 *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wuyaoyao                                                                                *
*                                                                                                         *
*Date       : 2022-02-14                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeCELDCheck(void)
{
	uint8 config_u8 = Chime_RteAdaptGetVconfig((uint8)VCONFIG_KIND_TRANSFER_CASE);
	uint8 CanSts_u8 = 0;
	uint8 CenterELDLckSts_u8 = 0;
	Chime_CancelFlag((uint16)e_SoundType_CLockOnce_CLOCK_1);
	Chime_CancelFlag((uint16)e_SoundType_CLockOnce_CLOCK_2);


	if(0x05 == config_u8) 
	{
/*START RTE interface*************************************************************************************/
		CanSts_u8 = Chime_GetMessage_TOD1_SystemOperMod(&CenterELDLckSts_u8);
/*END RTE interface  *************************************************************************************/

		if(RTE_E_INVALID == CanSts_u8)
		{
			//do nothing 
		}
		else
		{
			if(FALSE != CHIME_CAN_STATUS(CanSts_u8))
			{
				if(0x01 == CenterELDLckSts_u8)
				{
					ChimeGlobalData_s.CELDLastSts_u8 = 1;//TRUE;
					Chime_RequestFlag((uint16)e_SoundType_CLockOnce_CLOCK_1);
				}
				else
				{
					ChimeGlobalData_s.CELDLastSts_u8 = 0;//FALSE;
				}
			}
			else
			{
				if((FALSE == ChimeGlobalData_s.CELDLastSts_u8) && (RTE_E_INVALID_SIGNAL_DIFPROJET != CHIME_CAN_STATUS(CanSts_u8)))
				{
					Chime_RequestFlag((uint16)e_SoundType_CLockOnce_CLOCK_2);
				}
			}
		}
	}
	else
	{
		ChimeGlobalData_s.CELDLastSts_u8 = 0;//FALSE;
	}
	
}
/**********************************************************************************************************
*Function   : SWC_ChimeCELDCancel                                                                          *
*                                                                                                         *
*Description: Chime  with SWC_ChimeCELDCancel  sound cancel                                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wuyaoyao                                                                                *
*                                                                                                         *
*Date       : 2022-02-14                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeCELDCancel(void)

{
	Chime_CancelFlag((uint16)e_SoundType_CLockOnce_CLOCK_1);
	Chime_CancelFlag((uint16)e_SoundType_CLockOnce_CLOCK_2);
	ChimeGlobalData_s.CELDLastSts_u8 = FALSE;
}


/**********************************************************************************************************
*Function   : ChimeReq_LeaveCar4Hz                                                                        *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_LeaveCar4Hz sound request                                    *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_LeaveCar4Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_LeaveCar4Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_LeaveCar4Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_LeaveCar4Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_LeaveCar4Hz_Wrn_1);
		}
	}
}
/**********************************************************************************************************
*Function   : ChimeReq_StopCar4Hz                                                                         *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_StopCar4Hz sound request                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_StopCar4Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_StopCar4Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_StopCar4Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_StopCar4Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_StopCar4Hz_Wrn_1);
		}
	}
}
/**********************************************************************************************************
*Function   : ChimeReq_SteeringActRe                                                                      *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_SteeringActRe sound request                                  *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_SteeringActRe(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_SteeringActRe] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_SteeringActRe] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_SteeringActRe_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_SteeringActRe_Wrn_1);
		}
	}
}
/**********************************************************************************************************
*Function   : ChimeReq_AutoSteeringActRe                                                                  *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_AutoSteeringActRe sound request                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_AutoSteeringActRe(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_AutoSteeringActRe] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_AutoSteeringActRe] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_AutoSteeringActRe_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_AutoSteeringActRe_Wrn_1);
		}
	}
}
/**********************************************************************************************************
*Function   : ChimeReq_AutoBrakePersonRe                                                                  *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_AutoBrakePersonRe sound request                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_AutoBrakePersonRe(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_AutoBrakePersonRe] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_AutoBrakePersonRe] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_AutoBrakePersonRe_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_AutoBrakePersonRe_Wrn_1);
		}
	}
}
/**********************************************************************************************************
*Function   : ChimeReq_AutoBrakeCarRe                                                                     *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_AutoBrakeCarRe sound request                                 *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_AutoBrakeCarRe(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_AutoBrakeCarRe] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_AutoBrakeCarRe] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_AutoBrakeCarRe_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_AutoBrakeCarRe_Wrn_1);
		}
	}
}
/**********************************************************************************************************
*Function   : ChimeReq_AuxiliaryBrakeRe                                                                   *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_AuxiliaryBrakeRe sound request                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_AuxiliaryBrakeRe(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_AuxiliaryBrakeRe] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_AuxiliaryBrakeRe] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_AuxiliaryBrakeRe_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_AuxiliaryBrakeRe_Wrn_1);
		}
	}
}
/**********************************************************************************************************
*Function   : ChimeReq_CrossSideBrakeRe                                                                   *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_CrossSideBrakeRe sound request                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_CrossSideBrakeRe(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_CrossSideBrakeRe] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_CrossSideBrakeRe] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_CrossSideBrakeRe_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_CrossSideBrakeRe_Wrn_1);
		}
	}
}
/**********************************************************************************************************
*Function   : ChimeReq_RSideBrakeRe                                                                       *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_RSideBrakeRe sound request                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_RSideBrakeRe(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_RSideBrakeRe] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_RSideBrakeRe] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_RSideBrakeRe_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_RSideBrakeRe_Wrn_1);
		}
	}
}
/**********************************************************************************************************
*Function   : ChimeReq_TakeBrakeAcc4Hz                                                                    *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_TakeBrakeAcc4Hz sound request                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_TakeBrakeAcc4Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeBrakeAcc4Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeBrakeAcc4Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_TakeBrakeAcc4Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_TakeBrakeAcc4Hz_Wrn_1);
		}
	}
}
/**********************************************************************************************************
*Function   : ChimeReq_TakeBrakeFCWRe                                                                     *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_TakeBrakeFCWRe sound request                                 *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_TakeBrakeFCWRe(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeBrakeFCWRe] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeBrakeFCWRe] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_TakeBrakeFCWRe_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_TakeBrakeFCWRe_Wrn_1);
		}
	}
}
/**********************************************************************************************************
*Function   : ChimeReq_TakeBrakeFCrossRe                                                                  *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_TakeBrakeFCrossRe sound request                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_TakeBrakeFCrossRe(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeBrakeFCrossRe] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeBrakeFCrossRe] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_TakeBrakeFCrossRe_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_TakeBrakeFCrossRe_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_TakeSteering1Hz                                                                    *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_TakeSteering1Hz sound request                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_TakeSteering1Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeSteering1Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeSteering1Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_TakeSteering1Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_TakeSteering1Hz_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_TakeSteering2Hz                                                                    *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_TakeSteering2Hz sound request                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_TakeSteering2Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeSteering2Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeSteering2Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_TakeSteering2Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_TakeSteering2Hz_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_TakeSteering3Hz                                                                    *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_TakeSteering3Hz sound request                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_TakeSteering3Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeSteering3Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeSteering3Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_TakeSteering4Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_TakeSteering4Hz_Wrn_1);
		}
	}
}


/**********************************************************************************************************
*Function   : ChimeReq_TakeSteering4Hz                                                                    *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_TakeSteering4Hz sound request                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_TakeSteering4Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeSteering4Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeSteering4Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
		Chime_RequestFlag((uint16)e_SoundType_TakeSteering4Hz_Wrn_2);
	}
	else
	{
		Chime_CancelFlag((uint16)e_SoundType_TakeSteering4Hz_Wrn_2);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_KeepDistance                                                                       *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_KeepDistance sound request                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_KeepDistance(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_KeepDistance] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_KeepDistance] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_KeepDistance_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_KeepDistance_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_TakeCar1Hz                                                                         *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_TakeCar1Hz sound request                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_TakeCar1Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeCar1Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeCar1Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_TakeCar1Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_TakeCar1Hz_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_TakeCar2Hz                                                                         *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_TakeCar2Hz sound request                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_TakeCar2Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeCar2Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeCar2Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_TakeCar2Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_TakeCar2Hz_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_TakeCar4Hz                                                                         *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_TakeCar2Hz sound request                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_TakeCar4Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeCar4Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TakeCar4Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_TakeCar4Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_TakeCar4Hz_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_AssistExit4Hz                                                                      *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_AssistExit4Hz sound request                                  *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_AssistExit4Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_AssistExit4Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_AssistExit4Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_AssistExit4Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_AssistExit4Hz_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_KeepPoint1Hz                                                                       *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_KeepPoint1Hz sound request                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_KeepPoint1Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_KeepPoint1Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_KeepPoint1Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_KeepPoint1Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_KeepPoint1Hz_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_KeepPoint2Hz                                                                       *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_KeepPoint2Hz sound request                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_KeepPoint2Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_KeepPoint2Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_KeepPoint2Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_KeepPoint2Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_KeepPoint2Hz_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_KeepPoint4Hz                                                                       *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_KeepPoint4Hz sound request                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_KeepPoint4Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_KeepPoint4Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_KeepPoint4Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_KeepPoint4Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_KeepPoint4Hz_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_CheckP0_5Hz                                                                        *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_CheckP0_5Hz sound request                                    *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_CheckP0_5Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_CheckP0_5Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_CheckP0_5Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_CheckP0_5Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_CheckP0_5Hz_Wrn_1);
		}
	}
}
/**********************************************************************************************************
*Function   : ChimeReq_LcdAlarmOnce                                                                       *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_LcdAlarmOnce sound request                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_LcdAlarmOnce(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_LcdAlarmOnce] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_LcdAlarmOnce] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_LcdAlarmOnce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_LcdAlarmOnce_Wrn_1);
		}
	}
}
/**********************************************************************************************************
*Function   : ChimeReq_LcdAlarmOnce                                                                       *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_LcdAlarmThree sound request                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_LcdAlarmThree(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_LcdAlarmThree] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_LcdAlarmThree] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_LcdAlarmThree_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_LcdAlarmThree_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_LcdAlarmTenTimes                                                                   *
*                                                                                                         *
*Description: Chime adas warning with ChimeReq_LcdAlarmTenTimes sound request                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2021-03-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_LcdAlarmTenTimes(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_LcdAlarmTenTimes] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_LcdAlarmTenTimes] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_LcdAlarmTen_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_LcdAlarmTen_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_LightOn0_5Hz                                                                       *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_LightOn0_5Hz sound request                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_LightOn0_5Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_LightOn0_5Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_LightOn0_5Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_LightOn0_5Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_LightOn0_5Hz_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_TunnelTakeCarOnce                                                                  *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_TunnelTakeCarOnce sound request                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_TunnelTakeCarOnce(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TunnelTakeCarOnce] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TunnelTakeCarOnce] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_TunnelTakeCarOnce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_TunnelTakeCarOnce_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_RoadTakeCarOnce                                                                    *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_RoadTakeCarOnce sound request                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_RoadTakeCarOnce(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_RoadTakeCarOnce] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_RoadTakeCarOnce] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_RoadTakeCarOnce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_RoadTakeCarOnce_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_ModeFailOnce                                                                       *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_ModeFailOnce sound request                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_ModeFailOnce(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ModeFailOnce] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ModeFailOnce] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_ModeFailOnce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_ModeFailOnce_Wrn_1);
		}
	}
}


/**********************************************************************************************************
*Function   : ChimeReq_RCarSpeedHigh1Hz                                                                   *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_RCarSpeedHigh1Hz sound request                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_RCarSpeedHigh1Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_RCarSpeedHigh1Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_RCarSpeedHigh1Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_RCarSpeedHigh1Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_RCarSpeedHigh1Hz_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_4LModeOnce                                                                         *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_4LModeOnce sound request                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_4LModeOnce(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_4LModeOnce] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_4LModeOnce] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_4LModeOnce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_4LModeOnce_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_PowerOnOnce                                                                        *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_PowerOnOnce sound request                                    *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_PowerOnOnce(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_PowerOnOnce] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_PowerOnOnce] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_PowerOnOnce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_PowerOnOnce_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_PleaseRestOnce                                                                     *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_PleaseRestOnce sound request                                 *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_PleaseRestOnce(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_PleaseRestOnce] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_PleaseRestOnce] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_PleaseRestOnce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_PleaseRestOnce_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_PleaseRest1Hz                                                                      *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_PleaseRest1Hz sound request                                  *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_PleaseRest1Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_PleaseRest1Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_PleaseRest1Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_PleaseRest1Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_PleaseRest1Hz_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_VehicleDevRepeate                                                                  *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_VehicleDevRepeate sound request                                 *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2021-01-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_VehicleDevRepeate(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_VehicleDevRepeate] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_VehicleDevRepeate] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_VehicleDevRepeate_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_VehicleDevRepeate_Wrn_1);
		}
	}
}


/**********************************************************************************************************
*Function   : ChimeReq_UrgeTurnPlsHoldWhee                                                                  *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_UrgeTurnPlsHoldWhee sound request                                 *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wangtingting                                                                                *
*                                                                                                         *
*Date       : 2021-07-14                                                                                  *
**********************************************************************************************************/
static void ChimeReq_UrgeTurnPlsHoldWhee(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_UrgeTurnPlsHoldWheel] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_UrgeTurnPlsHoldWheel] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_UrgeTurnPlsHoldWheel_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_UrgeTurnPlsHoldWheel_Wrn_1);
		}
	}
}


/**********************************************************************************************************
*Function   : ChimeReq_MoveRampFailHandWheel_2Hz                                                                  *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_MoveRampFailHandWheel_2Hz sound request                                 *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wangtingting                                                                                *
*                                                                                                         *
*Date       : 2021-07-14                                                                                  *
**********************************************************************************************************/
static void ChimeReq_MoveRampFailHandWheel_2Hz(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_MoveRampFailHandWheel_2Hz] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_MoveRampFailHandWheel_2Hz] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_MoveRampFailHandWheel_2Hz_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_MoveRampFailHandWheel_2Hz_Wrn_1);
		}
	}
}


/**********************************************************************************************************
*Function   : ChimeReq_MoveRampFailHandWheel                                                                  *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_MoveRampFailHandWheel sound request                                 *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wangtingting                                                                                *
*                                                                                                         *
*Date       : 2021-07-14                                                                                  *
**********************************************************************************************************/
static void ChimeReq_MoveRampFailHandWheel(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_MoveRampFailHandWheel] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_MoveRampFailHandWheel] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_MoveRampFailHandWheel_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_MoveRampFailHandWheel_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_MoveMainFailHandWheel                                                                  *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_MoveMainFailHandWheel sound request                                 *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wangtingting                                                                                *
*                                                                                                         *
*Date       : 2021-07-14                                                                                  *
**********************************************************************************************************/
static void ChimeReq_MoveMainFailHandWheel(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_MoveMainFailHandWheel] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_MoveMainFailHandWheel] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_MoveMainFailHandWheel_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_MoveMainFailHandWheel_Wrn_1);
		}
	}
}



/**********************************************************************************************************
*Function   : ChimeReq_TurnFailPlsHandWheel                                                                  *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_TurnFailPlsHandWheel sound request                                 *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wangtingting                                                                                *
*                                                                                                         *
*Date       : 2021-07-14                                                                                  *
**********************************************************************************************************/
static void ChimeReq_TurnFailPlsHandWheel(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TurnFailPlsHandWheel] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TurnFailPlsHandWheel] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_TurnFailPlsHandWheel_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_TurnFailPlsHandWheel_Wrn_1);
		}
	}
}


/**********************************************************************************************************
*Function   : ChimeReq_TollGateFailPlsHandWheel                                                                  *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_TollGateFailPlsHandWheel sound request                                 *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wangtingting                                                                                *
*                                                                                                         *
*Date       : 2021-07-14                                                                                  *
**********************************************************************************************************/
static void ChimeReq_TollGateFailPlsHandWheel(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TollGateFailPlsHandWheel] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_TollGateFailPlsHandWheel] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_TollGateFailPlsHandWheel_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_TollGateFailPlsHandWheel_Wrn_1);
		}
	}
}


/**********************************************************************************************************
*Function   : ChimeReq_RoundaboutFailPlsHandWheel                                                                  *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_RoundaboutFailPlsHandWheel sound request                                 *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wangtingting                                                                                *
*                                                                                                         *
*Date       : 2021-07-14                                                                                  *
**********************************************************************************************************/
static void ChimeReq_RoundaboutFailPlsHandWheel(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_RoundaboutFailPlsHandWheel] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_RoundaboutFailPlsHandWheel] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_RoundaboutFailPlsHandWheel_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_RoundaboutFailPlsHandWheel_Wrn_1);
		}
	}
}



/**********************************************************************************************************
*Function   : ChimeReq_AccCruiseFailOnce                                                                  *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_AccCruiseFailOnce sound request                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_AccCruiseFailOnce(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_AccCruiseFailOnce] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_AccCruiseFailOnce] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_AccCruiseFailOnce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_OverSpeedAlarm1Hz_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_AccCruiseQuitOnce                                                                  *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_AccCruiseQuitOnce sound request                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_AccCruiseQuitOnce(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_AccCruiseQuitOnce] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_AccCruiseQuitOnce] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_AccCruiseQuitOnce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_AccCruiseQuitOnce_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_SmartCruiseFailOnce                                                                *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_SmartCruiseFailOnce sound request                            *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_SmartCruiseFailOnce(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_SmartCruiseFailOnce] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_SmartCruiseFailOnce] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_SmartCruiseFailOnce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_SmartCruiseFailOnce_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_SmartCruisQuitOnce                                                                 *
*                                                                                                         *
*Description: Chime Warning with e_SoundType_SmartCruisQuitOnce sound request                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_SmartCruisQuitOnce(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_SmartCruisQuitOnce] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_SmartCruisQuitOnce] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_SmartCruisQuitOnce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_SmartCruisQuitOnce_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : ChimeReq_AccCruiseOkkeepAtOnce                                                              *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_AccCruiseOkkeepAtOnce sound request                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-30                                                                                  *
**********************************************************************************************************/
static void ChimeReq_AccCruiseOkkeepAtOnce(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_AccCruiseOkkeepAtOnce] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_AccCruiseOkkeepAtOnce] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_AccCruiseOkkeepAtOnce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_AccCruiseOkkeepAtOnce_Wrn_1);
		}
	}
}
/**********************************************************************************************************
*Function   : ChimeReq_AccCruiseOkkeepAtOnce                                                              *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_AccCruiseOkkeepAtOnce sound request                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-30                                                                                  *
**********************************************************************************************************/
static void ChimeReq_SmartCruiseOkhwOnce(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_SmartCruiseOkhwOnce] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_SmartCruiseOkhwOnce] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_SmartCruiseOkhwOnce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_SmartCruiseOkhwOnce_Wrn_1);
		}
	}
}
/**********************************************************************************************************
*Function   : ChimeReq_FCOKOnce                                                                           *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_FCOKOnce sound request                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2021-03-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_FCOKOnce(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_FCOKOnce] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_FCOKOnce] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_FCOKOnce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_FCOKOnce_Wrn_1);
		}
	}
}
/**********************************************************************************************************
*Function   : ChimeReq_FCOKAttRoadEnvOnce                                                                 *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_FCOKAttRoadEnvOnce sound request                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2021-03-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_FCOKAttRoadEnvOnce(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_FCOKAttRoadEnvOnce] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_FCOKAttRoadEnvOnce] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_FCOKAttRoadEnvOnce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_FCOKAttRoadEnvOnce_Wrn_1);
		}
	}
}
/**********************************************************************************************************
*Function   : ChimeReq_FCOKKeepAtOnce                                                                     *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_FCOKKeepAtOnce sound request                                    *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2021-03-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_FCOKKeepAtOnce(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_FCOKKeepAtOnce] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_FCOKKeepAtOnce] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_FCOKKeepAtOnce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_FCOKKeepAtOnce_Wrn_1);
		}
	}
}
/**********************************************************************************************************
*Function   : ChimeReq_FCOKTakeCarOnce                                                                    *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_FCOKTakeCarOnce sound request                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2021-03-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_FCOKTakeCarOnce(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_FCOKTakeCarOnce] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_FCOKTakeCarOnce] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_FCOKTakeCarOnce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_FCOKTakeCarOnce_Wrn_1);
		}
	}
}



/**********************************************************************************************************
*Function   : ChimeReq_NOGIsActivated                                                                    *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_NOGIsActivated sound request                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wangtingting                                                                               *
*                                                                                                         *
*Date       : 2021-03-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_NOGIsActivated(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_NOHIsActivated] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_NOHIsActivated] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_NOHIsActivated_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_NOHIsActivated_Wrn_1);
		}
	}
}


/**********************************************************************************************************
*Function   : ChimeReq_EnvNotSup                                                                    *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_EnvNotSup sound request                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wangtingting                                                                               *
*                                                                                                         *
*Date       : 2021-10-14                                                                                  *
**********************************************************************************************************/
static void ChimeReq_EnvNotSup(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_EnvNotSup] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_EnvNotSup] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_ConditionNotMet_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_ConditionNotMet_Wrn_1);
		}
	}
}


/**********************************************************************************************************
*Function   : ChimeReq_KeepFocusTryAgain                                                                    *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_KeepFocusTryAgain sound request                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wangtingting                                                                               *
*                                                                                                         *
*Date       : 2021-10-14                                                                                  *
**********************************************************************************************************/
static void ChimeReq_KeepFocusTryAgain(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_KeepFocusTryAgain] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_KeepFocusTryAgain] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_StayFocusedTryAgain_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_StayFocusedTryAgain_Wrn_1);
		}
	}
}



/**********************************************************************************************************
*Function   : ChimeReq_PlsHandWheelTryAgain                                                                    *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_PlsHandWheelTryAgain sound request                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wangtingting                                                                               *
*                                                                                                         *
*Date       : 2021-10-14                                                                                  *
**********************************************************************************************************/
static void ChimeReq_PlsHandWheelTryAgain(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_PlsHandsWheelTryAgain] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_PlsHandsWheelTryAgain] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_HandsOnthewheelTryAgain_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_HandsOnthewheelTryAgain_Wrn_1);
		}
	}
}


/**********************************************************************************************************
*Function   : ChimeReq_Plsfastenseatbelt                                                                    *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_Plsfastenseatbelt sound request                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wangtingting                                                                               *
*                                                                                                         *
*Date       : 2021-10-14                                                                                  *
**********************************************************************************************************/
static void ChimeReq_Plsfastenseatbelt(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_Plsfastenseatbelt] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_Plsfastenseatbelt] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_FastenSeatBelt_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_FastenSeatBelt_Wrn_1);
		}
	}
}


/**********************************************************************************************************
*Function   : ChimeReq_PlsShutTheDoor                                                                    *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_PlsShutTheDoor sound request                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wangtingting                                                                               *
*                                                                                                         *
*Date       : 2021-10-14                                                                                  *
**********************************************************************************************************/
static void ChimeReq_PlsShutTheDoor(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_PlsShutTheDoor] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_PlsShutTheDoor] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_CloseTheDoor_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_CloseTheDoor_Wrn_1);
		}
	}
}


/**********************************************************************************************************
*Function   : ChimeReq_fsatenPassSeatbelt                                                                    *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_fsatenPassSeatbelt sound request                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wangtingting                                                                               *
*                                                                                                         *
*Date       : 2021-10-14                                                                                  *
**********************************************************************************************************/
static void ChimeReq_fsatenPassSeatbelt(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_PlsfastenPassSeatbelt] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_PlsfastenPassSeatbelt] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_FastenPassengerSeat_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_FastenPassengerSeat_Wrn_1);
		}
	}
}


/**********************************************************************************************************
*Function   : ChimeReq_HcExitTakeDirOnce                                                                  *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_HcExitTakeDirOnce  sound request                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_HcExitTakeDirOnce(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_HcExitTakeDirOnce] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_HcExitTakeDirOnce] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_HcExitTakeDirOnce_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_HcExitTakeDirOnce_Wrn_1);
		}
	}
}


/**********************************************************************************************************
*Function   : ChimeReq_NOHExitPlsTake                                                                  *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_NOHExitPlsTake  sound request                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-10                                                                                  *
**********************************************************************************************************/
static void ChimeReq_NOHExitPlsTake(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeNOHExitPlsTake] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeNOHExitPlsTake] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_NOHExitPlsTake_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_NOHExitPlsTake_Wrn_1);
		}
	}
}


/**********************************************************************************************************
*Function   : SWC_ChimeReq_PowerOffAfterThreeMinute                                                                  *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_PowerOffAfterThreeMinute  sound request                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wu Yaoyao                                                                                *
*                                                                                                         *
*Date       : 2022-2-17                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_PowerOffAfterThreeMinute(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimePowerOffAfterThreeMinute] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimePowerOffAfterThreeMinute] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_battery_low0_5Hz_1_Wrn_1);
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_battery_low0_5Hz_1_Wrn_1);
		}
	}
}

/**********************************************************************************************************
*Function   : SWC_ChimeReq_StatBattLowComfortOff                                                                  *
*                                                                                                         *
*Description: Chime Warning with ChimeReq_StatBattLowComfortOff  sound request                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wu Yaoyao                                                                                *
*                                                                                                         *
*Date       : 2022-2-17                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_StatBattLowComfortOff(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeStatBattLowComfortOff] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeStatBattLowComfortOff] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlagRepeat((uint16)e_SoundType_12VPowerSysFailWrn_1  );
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_12VPowerSysFailWrn_1  );
		}
	}
}


/**********************************************************************************************************
*Function   : SWC_ChimeReq_SmartCruiseExit                                                                *
*                                                                                                         *
*Description: Chime Warning with SWC_ChimeReq_SmartCruiseExit  sound request                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : xu                                                                                          *
*                                                                                                         *
*Date       : 2022-03-26                                                                                  *
**********************************************************************************************************/
static void SWC_ChimeReq_SmartCruiseExit(uint8 flag,uint8 enable,uint16 bit)
{
	if(FALSE == flag)
	{
		if(FALSE != enable)
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeSmartCruiseExit] = CHIME_WARNING_SOUND_REQ;
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].ReqWarning[e_WarnReq_ChimeSmartCruiseExit] = CHIME_WARNING_SOUND_CEL;
		}
	}
	else
	{
		if(FALSE != enable)
		{
			Chime_RequestFlag((uint16)e_SoundType_SmartCruiseExit_Wrn_1  );
		}
		else
		{
			Chime_CancelFlag((uint16)e_SoundType_SmartCruiseExit_Wrn_1  );
		}
	}
}




/**********************************************************************************************************
*Function   : ChimeWarningCheck                                                                           *
*                                                                                                         *
*Description: Chime Warning with  sound request                                                           *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
void ChimeWarningCheck(s_IPCWrnCallback_t back)
{
	uint16 lastWrn;
	if(FALSE == back.AdasFault)
	{
		lastWrn = ChimeGlobalIPCWarn_s[0].CurDisplayAdas_u16;
		if((lastWrn != back.General) && (lastWrn < ChimeConstMaxWrn2ChimeTbl))
		{
			if(WN_enWARNING_TOTAL_NUMBER == ChimeWrningCancelTbl[ChimeWrn2ChimeTbl[lastWrn].WarnReqNum].WarningId_u16)
			{
				if(ChimeWrn2ChimeTbl[lastWrn].WarnReqNum != e_WarnReq_MaxNumber)
				{
					ChimeWrningCancelTbl[ChimeWrn2ChimeTbl[lastWrn].WarnReqNum].Process(FALSE,FALSE,FALSE);
				}
			}
		}
		if((back.General >= CHIME_WARNING_ADAS_BEGIN) && (back.General < 0xffff))
		{
			back.General = back.General - (uint16)CHIME_WARNING_ADAS_BEGIN +(uint16) WN_enWARNING_TOTAL_NUMBER + (uint16)CHIME_WARNING_DMS_NUMBER;
			
			if(back.General < ChimeConstMaxWrn2ChimeTbl)
			{
				if(ShowPeriod_First == back.GeneralShied)
				{
					if(ChimeWrn2ChimeTbl[back.General].WarnReqNum != e_WarnReq_MaxNumber)
					{
						ChimeWrningCancelTbl[ChimeWrn2ChimeTbl[back.General].WarnReqNum].Process(FALSE,TRUE,back.GeneralBit);
						(void)SWC_CHIME_INFO_LOG("Adas first request id = %d",ChimeWrn2ChimeTbl[back.General].WarnReqNum);
					}
				}
				else if(ShowPeriod_Sheild == back.GeneralShied)
				{
					if(ChimeWrn2ChimeTbl[back.General].WarnReqNum != e_WarnReq_MaxNumber)
					{
						ChimeWrningCancelTbl[ChimeWrn2ChimeTbl[back.General].WarnReqNum].Process(FALSE,FALSE,FALSE);
						//SWC_CHIME_INFO_LOG("Adas shied id = %d",ChimeWrn2ChimeTbl[back.General].WarnReqNum);
					}
				}
				else 
				{
					(void)SWC_CHIME_WARN_LOG("Adas status overload");
				}
				ChimeGlobalIPCWarn_s[0].CurDisplayAdas_u16 = back.General;
			}
			else
			{
				ChimeGlobalIPCWarn_s[0].CurDisplayAdas_u16 = 0xffff;
			}
		}
		else
		{
			ChimeGlobalIPCWarn_s[0].CurDisplayAdas_u16 = 0xffff;
		}
	}
	else
	{
		lastWrn = ChimeGlobalIPCWarn_s[0].CurDisplayWrn_u16;
		if((lastWrn != back.General) && (lastWrn < ChimeConstMaxWrn2ChimeTbl))
		{
			if(WN_enWARNING_TOTAL_NUMBER == ChimeWrningCancelTbl[ChimeWrn2ChimeTbl[lastWrn].WarnReqNum].WarningId_u16)
			{
				if(ChimeWrn2ChimeTbl[lastWrn].WarnReqNum != e_WarnReq_MaxNumber)
				{
					ChimeWrningCancelTbl[ChimeWrn2ChimeTbl[lastWrn].WarnReqNum].Process(FALSE,FALSE,FALSE);
				}
			}
		}
		if((back.General < ChimeConstMaxWrn2ChimeTbl) && (back.General <= CHIME_WARNING_MAX_ID))
		{
			if(ShowPeriod_First == back.GeneralShied)
			{
				if(ChimeWrn2ChimeTbl[back.General].WarnReqNum != e_WarnReq_MaxNumber)
				{
					ChimeWrningCancelTbl[ChimeWrn2ChimeTbl[back.General].WarnReqNum].Process(FALSE,TRUE,back.GeneralBit);
					(void)SWC_CHIME_WARN_LOG("Wrn first request id = %d",ChimeWrn2ChimeTbl[back.General].WarnReqNum);
				}
			}
			else if(ShowPeriod_Cycle == back.GeneralShied)
			{
				if(((back.General <= WN_enGearPSelect)||((back.General >= WN_enPlsTakeOver)&&(back.General <= WN_enV2XFrontCarAttentionRight))\
				||((back.General >= WN_enV2XCarDistance)&&(back.General <= WN_enV2XAroundCarUnContron)) \
				|| (back.General == WN_enSmartCruiseouteEmergencyBrake)) && (lastWrn != back.General))
				{
					if(ChimeWrn2ChimeTbl[back.General].WarnReqNum != e_WarnReq_MaxNumber)
					{
						ChimeWrningCancelTbl[ChimeWrn2ChimeTbl[back.General].WarnReqNum].Process(FALSE,TRUE,back.GeneralBit);
						(void)SWC_CHIME_WARN_LOG("Wrn cycle request id = %d",ChimeWrn2ChimeTbl[back.General].WarnReqNum);
					}
				}
			}
			else if(ShowPeriod_Sheild == back.GeneralShied)
			{
				if(ChimeWrn2ChimeTbl[back.General].WarnReqNum != e_WarnReq_MaxNumber)
				{
					ChimeWrningCancelTbl[ChimeWrn2ChimeTbl[back.General].WarnReqNum].Process(FALSE,FALSE,FALSE);
					//SWC_CHIME_INFO_LOG("Wrn shied id = %d",ChimeWrn2ChimeTbl[back.General].WarnReqNum);
				}
			}
			else 
			{
				(void)SWC_CHIME_WARN_LOG("Wrn status overload");
			}
			ChimeGlobalIPCWarn_s[0].CurDisplayWrn_u16 = back.General;
		}
		else 
		{
			ChimeGlobalIPCWarn_s[0].CurDisplayWrn_u16 = 0xffff;
		}
	}
}

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
void Chime_Api_TTFlashCallback(uint8 *data)
{
	uint32 ChimeCurTTFlashstatus;
	IPC_S2M_ClusterAppClusterSocTtToChime_Receive(data,&ChimeTTFlashstatus,IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTTOCHIME_LENGTH);

	ChimeCurTTFlashstatus = ChimeTTFlashstatus.TtFlashTick;

	// tt 1HZ 亮灭
	if((1u != ChimeLastTTFlashstatus) && (ChimeCurTTFlashstatus == 1u) )
	{
		TTFlash_Flag = 1u;
	}
	else
	{
		TTFlash_Flag = 0U;
	}

	ChimeLastTTFlashstatus =  ChimeCurTTFlashstatus;

}

/**********************************************************************************************************
*Function   : ChimeWarningCheck                                                                           *
*                                                                                                         *
*Description: Chime Warning with  sound request                                                           *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
void ChimeTelltaleCheck(s_IPCTTCallback_t led)
{
	SWC_ChimeTPMSLEDCheck(led.u_TTStatusu32Telltales_status_t.s_u32Telltales_status_t.TPMS_Data);
	SWC_ChimeHybridPowerSystemLEDCheck(led.u_TTStatusu32Telltales_status_t.s_u32Telltales_status_t.HEV_Red_Data);
	SWC_ChimeSeltbeltLEDCheck(led.u_TTStatusu32Telltales_status_t.s_u32Telltales_status_t.Seat_Belt_Data);
	/*SWC_ChimeTickTockLEDCheck(led.u_TTStatusu32Telltales_status_t.s_u32Telltales_status_t.Turn_Left_Data,
							  led.u_TTStatusu32Telltales_status_t.s_u32Telltales_status_t.Turn_Right_Data);*/
	SWC_ChimeOverspeedLEDCheck(led.u_TTStatusu32Telltales_status_t.s_u32Telltales_status_t.TSR_120KMH_Data);
	ChimeGlobalData_s.LEDTSR120KMHData_u8 = led.u_TTStatusu32Telltales_status_t.s_u32Telltales_status_t.TSR_120KMH_Data;
	SWC_ChimeCCOLEDCheck(led.u_TTStatusu32Telltales_status_t.s_u32Telltales_status_t.CCO_Inactive_Data);
	SWC_ChimeTABLEDCheck(led.u_TTStatusu32Telltales_status_t.s_u32Telltales_status_t.Steer_Assit_Error_Data);
	SWC_ChimeREADYLEDCheck(led.u_TTStatusu32Telltales_status_t.s_u32Telltales_status_t.Ready_Light_Data);
	(void)SWC_CHIME_WARN_LOG("TT request data %d,%d,%d,%d,%d",led.u_TTStatusu32Telltales_status_t.u32Telltales_status[0],
						led.u_TTStatusu32Telltales_status_t.u32Telltales_status[1],
						led.u_TTStatusu32Telltales_status_t.u32Telltales_status[2],
						led.u_TTStatusu32Telltales_status_t.u32Telltales_status[3],
						led.u_TTStatusu32Telltales_status_t.u32Telltales_status[4]);
}

uint8 chime_api_TTFuc(void)
{
	return TTFlash_Flag ;
}


/**********************************************************************************************************
*Function   : ChimeAdasCheck                                                                              *
*                                                                                                         *
*Description: Chime Adas    with  sound request                                                           *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2021-1-5                                                                                    *
**********************************************************************************************************/
void ChimeAdasCheck(s_IPCAdasCallback_t adas)
{
	(void)memcpy((uint8 *)(&ChimeGlobalIPCAdas_s[0]),(uint8 *)(&adas),sizeof(s_IPCAdasCallback_t));
}

/**********************************************************************************************************
*Function   : Chime_RequestFlag                                                                           *
*                                                                                                         *
*Description: Set Chime request flag                                                                      *
*                                                                                                         *
*Parameter  : Idx_u16: request id                                                                         *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void Chime_RequestFlag(uint16 Idx_u16)
{
	ChimeRequirementBitTbl[e_ChimeTable_ReqSound][CHimeReqBit2ChimeTbl[Idx_u16].SoundId] |= CHimeReqBit2ChimeTbl[Idx_u16].SoundBit;
	Chime_Api_RequestField_Set(CHimeReqBit2ChimeTbl[Idx_u16].SoundId,CHimeReqBit2ChimeTbl[Idx_u16].Field);
}

/**********************************************************************************************************
*Function   : Chime_RequestFlagRepeat                                                                     *
*                                                                                                         *
*Description: Set Chime request flag                                                                      *
*                                                                                                         *
*Parameter  : Idx_u16: request id                                                                         *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void Chime_RequestFlagRepeat(uint16 Idx_u16)
{
	ChimeRequirementBitTbl[e_ChimeTable_ReqSound][CHimeReqBit2ChimeTbl[Idx_u16].SoundId] |= CHimeReqBit2ChimeTbl[Idx_u16].SoundBit;
	ChimeRequirementBitTbl[e_ChimeTable_ActSound][CHimeReqBit2ChimeTbl[Idx_u16].SoundId] &= ~CHimeReqBit2ChimeTbl[Idx_u16].SoundBit;
	Chime_Api_RequestField_Set(CHimeReqBit2ChimeTbl[Idx_u16].SoundId,CHimeReqBit2ChimeTbl[Idx_u16].Field);
	Chime_CoreRlsRequestSound(CHimeReqBit2ChimeTbl[Idx_u16].SoundId,CHimeReqBit2ChimeTbl[Idx_u16].SoundBit);
}

/**********************************************************************************************************
*Function   : Chime_CancelFlag                                                                            *
*                                                                                                         *
*Description: Cancel Chime request flag                                                                   *
*                                                                                                         *
*Parameter  : Idx_u16: request id                                                                         *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void Chime_CancelFlag(uint16 Idx_u16)
{
	ChimeRequirementBitTbl[e_ChimeTable_ReqSound][CHimeReqBit2ChimeTbl[Idx_u16].SoundId] &= ~CHimeReqBit2ChimeTbl[Idx_u16].SoundBit;
	//Chime_Api_CancelField_Set(req_ptr.SoundId,req_ptr.Field);
}

/**********************************************************************************************************
*Function   : Chime_CancelWithField                                                                       *
*                                                                                                         *
*Description: Cancel Chime request flag                                                                   *
*                                                                                                         *
*Parameter  : Idx_u16: request id                                                                         *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
#if 0
static void Chime_CancelWithField(uint16 Idx_u16)
{
	ChimeRequirementBitTbl[e_ChimeTable_ReqSound][CHimeReqBit2ChimeTbl[Idx_u16].SoundId] &= ~CHimeReqBit2ChimeTbl[Idx_u16].SoundBit;
	Chime_Api_CancelField_Set(CHimeReqBit2ChimeTbl[Idx_u16].SoundId,CHimeReqBit2ChimeTbl[Idx_u16].Field);
}
#endif
/**********************************************************************************************************
*Function   : Chime_ClearField                                                                            *
*                                                                                                         *
*Description: Clear Chime request flag                                                                    *
*                                                                                                         *
*Parameter  : Idx_u16: request id                                                                         *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void Chime_ClearField(uint16 Idx_u16)
{
	Chime_Api_CancelField_Set(CHimeReqBit2ChimeTbl[Idx_u16].SoundId,CHIME_RSDS_POSITION_ALL);
}

/**********************************************************************************************************
*Function   : Chime_RequestFlag                                                                           *
*                                                                                                         *
*Description: Chime warm init interface ,need to call by runable                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static uint16 Chime_CheckFlag(uint16 Idx_u16)
{
	uint16 flag;
	flag = ChimeRequirementBitTbl[e_ChimeTable_ReqSound][CHimeReqBit2ChimeTbl[Idx_u16].SoundId];
	return flag;
}

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
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
static void Chime_RequestChimeProcess(void)
{
	uint8 chimeId;
	uint16 bit_change;
	/*Cancel no request sound----------------------------------------------------------------------------*/
	for(chimeId = (uint8)e_SoundBuffer_IdleMode;chimeId < e_SoundType_NumberOfChimes;chimeId ++)
	{
		if(0x00 == (ChimeRequirementBitTbl[e_ChimeTable_ReqSound][chimeId] & Chime_CoreCheckSound(chimeId,e_ChimeQueue_Request)))
		{
			Chime_Api_Cancel_Set(chimeId);
		}
	}
	Chime_SlowRateTask();
	/*Request new sound----------------------------------------------------------------------------------*/
	for(chimeId = e_SoundBuffer_IdleMode;chimeId < e_SoundType_NumberOfChimes;chimeId ++)
	{
		bit_change = ((ChimeRequirementBitTbl[e_ChimeTable_ReqSound][chimeId] ^ ChimeRequirementBitTbl[e_ChimeTable_ActSound][chimeId])
			         & ChimeRequirementBitTbl[e_ChimeTable_ReqSound][chimeId]);
		if(FALSE != bit_change)
		{
			(void)Chime_Api_RequestProcess_Set(chimeId,bit_change);
		}
	}
	memcpy((uint8 *)ChimeRequirementBitTbl[e_ChimeTable_ActSound],(uint8 *)ChimeRequirementBitTbl[e_ChimeTable_ReqSound],sizeof(ChimeRequirementBitTbl)/2);
}

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
**  Date    :      2020/07/10     Original Version
**
**********************************************************************************************************/

/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/


