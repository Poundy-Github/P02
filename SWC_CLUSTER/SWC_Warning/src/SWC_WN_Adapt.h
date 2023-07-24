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
**  Name:               SWC_WN_Interface.h
**
**  Description:        Odo moudle interface file to other.Include init and get Odo data 
**
**  Organization:       
**
**********************************************************************************************************/
/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef SWC_WN_ADAPT_H
#define SWC_WN_ADAPT_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Rte_type.h"
#include "Platform_Types.h"
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* Type of parament                                                                                        *
**********************************************************************************************************/
typedef enum
{
    //Local Config
	WN_enCfg_LowOilPressure_telltales_DelayTime = 0,
	WN_enCfg_BrakeFault_DelayTime,
	WN_enCfg_AccelBrakeWrnDelayTime,

    //Vehicle Config
	WN_enCfg_Transmission,
	WN_enCfg_EngCtrolUnit,
	WN_enCfg_CruiseControl,
	WN_enCfg_Fuel,
	WN_enCfg_ElecPosition,
	WN_enCfg_IdleStopAndGo,
	WN_enCfg_ElecEnManagement,
	WN_enCfg_UpDownHill,
	WN_enCfg_AVH,
	WN_enCfg_ParkingBrake,
	WN_enCfg_Tab,
	WN_enCfg_SpeedOmeter,
	WN_enCfg_SmartJuncBox,
	WN_enCfg_DriveHandleType,
	WN_enCfg_BodyDomainCtrl,
	WN_enCfg_Regional,
	WN_enCfg_StartSystem,
	WN_enCfg_ParkingLamp,
	WN_enCfg_AutoLightSys,
	WN_enCfg_FrtWiperSys,
	WN_enCfg_DrowWarnSys,
	WN_enCfg_Tpms,
	WN_enCfg_EPark,
	WN_enCfg_ElecSteColumnLock,
	WN_enCfg_SeatBelt,
	WN_enCfg_SpeedReverse,
	WN_enCfg_ShiftedUnlockKey,
	WN_enCfg_TransCase,
	WN_enCfg_ORCruiseControl,
	WN_enCfg_OffRoadExpertMode,
	WN_enCfg_FCWAEB,
	WN_enCfg_HighwayAssist,
	WN_enCfg_TrafficSign,
	WN_enCfg_PedalControlSts,
	WN_enCfg_QuickStart,
	WN_enCfg_OusideTemp,
	WN_enCfg_HeadLighting,
	WN_enCfg_LongAssHiBeam,
	WN_enCfg_HeadLampAdjust,
	WN_enCfg_HeadLampBeamSys,
	WN_enCfg_HeadLampCtrlFunc,
	WN_enCfg_LimitedSlip,
	WN_enCfg_Wireless,
	WN_enCfg_EngWaterPump,
	WN_enCfg_V2VCharge,
	WN_enCfg_DisVChargeConnect,
	WN_enCfg_AirGrille,
	WN_enCfg_VoiceFacial,
	WN_enCfg_DMSType,
	WN_enCfg_DrvModeOptionnal,
	WN_enCfg_DrvMode2,
	WN_enCfg_PPMI,
	WN_enCfg_NetService,
	WN_enCfg_AEBJunctionAssist,
	WN_enCfg_FCWB,
	WN_enCfg_RearCollision,
	WN_enCfg_LaneChangeAssist,
	WN_enCfg_PASCTA,
	WN_enCfg_LDWLKA,
	WN_enCfg_EvasiveSteering,
	WN_enCfg_EmergencySteering,
	WN_enCfg_ARHUD,
	WN_enCfg_FuelTankSys,
	WN_enCfg_Damper,
	WN_enCfg_EMissionLevel,
	WN_enCfg_UltravioletLamp,
	WN_enCfg_PTCanType,
	WN_enCfg_CentralModule,
	WN_enCfg_AuxFuel,
	WN_enCfg_SteeringSys,
	WN_enCfg_DrvMode3,
	WN_enCfg_ABS_EBD,
	WN_enCfg_TSMFunc,
	WN_enCfg_AFS,
	WN_enCfg_FrontWheelBack,
	WN_enCfg_NOH,
	WN_enCfg_Eng_oil_display,
	WN_enCfg_V2X,
	WN_enCfg_ClutOvrHeatd,
	WN_enCfg_DriverBelt,
	WN_encfg_OffroadThm,
	WN_encfg_RainShed,
	WN_encfg_OilLevel,
	WN_encfg_TCY,
	WN_encfg_TFV,
	WN_encfg_TrunkBoard,
	WN_encfg_KAT,
	WN_encfg_TFC,
	WN_encfg_VDH,
	WN_enCfg_EAE,
	WN_enCfg_ChargingFlap,
	WN_encfg_CBW,
	WN_enCfg_GAC,
	WN_enCfg_GAG,
	WN_enCfg_E_Call,
	WN_encfg_WashingLiquidLevelAlarm,
	WN_encfg_ComfortableStop,
	WN_encfg_AutomaticPowerDownControl,
	WN_enCfg_Max,
}WN_enConfigID;
/**********************************************************************************************************
* start of Function                                                                                       *
**********************************************************************************************************/
#define SWC_WN_START_SEC_CODE
#include "SWC_WN_MemMap.h"
//Get Vehicle and Local config
void WN_GetAllConfiguration(void);
uint32 WN_GetSingleConfig(WN_enConfigID ConfigID);
boolean EolConfig_Trans_CANFD(void);
//Get DTC
uint8 WN_Return_u8VSG_Sts_APIGet(AVASDTCRet *strAVASDTCRte);
uint8 WN_Builtin_AVAS_Sts_APIGet(uint8 *SignalValue);
//Get Signal
uint8 WN_EngClntTempWarn_SignalGet(boolean *SignalValue);
uint8 WN_CruiseCtrlSts_SignalGet(uint8 *SignalValue);
uint8 WN_TgtCrsVehSpd_SignalGet(uint8 *SignalValue);
uint8 WN_CruiseCtrlSts_PHEV_SignalGet(uint8 *SignalValue);
uint8 WN_SS_Screen_tip_SignalGet(uint8 *SignalValue);
uint8 WN_TranPMode_Sts_SignalGet(boolean *SignalValue);
uint8 WN_LvPwrSysErr_SignalGet(uint8 *SignalValue);
uint8 WN_Stat_PwrSv_Lvl_SignalGet(uint8 *SignalValue);
uint8 WN_Dyn_PwrSv_Lvl_SignalGet(uint8 *SignalValue);
uint8 WN_HDCFault_SignalGet(uint8 *SignalValue);
uint8 WN_AVHErrSts_SignalGet(uint8 *SignalValue);
uint8 WN_HDCFaultFD_SignalGet(uint8 *SignalValue);
uint8 WN_AVHErrStsFD_SignalGet(uint8 *SignalValue);
uint8 WN_EPBTextDisp_SignalGet(uint8 *SignalValue);
uint8 WN_EPBTextDispTab_SignalGet(uint8 *SignalValue);
uint8 WN_EngSpdVldty_SignalGet(uint8 *SignalValue);
uint8 WN_EngSpd_SignalGet(uint8 *SignalValue);
uint8 WN_EngSpd_ForIP_SignalGet(uint8 *SignalValue);
uint8 WN_BrkFldWarn_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_RdyLmpSts_SignalGet(uint8 *SignalValue);
uint8 WN_PressBrakePedalPointOut_SignalGet(uint8 *SignalValue);
uint8 WN_DrvDoorSts_SignalGet(uint8 *SignalValue);
uint8 WN_PassengerDoorSts_SignalGet(uint8 *SignalValue);
uint8 WN_LRDoorSts_SignalGet(uint8 *SignalValue);
uint8 WN_RRDoorSts_SignalGet(uint8 *SignalValue);
uint8 WN_TrunkSts_SignalGet(uint8 *SignalValue);
uint8 WN_HoodSts_F_Pbox_SignalGet(uint8 *SignalValue);
uint8 WN_RFogLmpFailSts_R_Pbox_SignalGet(uint8 *SignalValue);
uint8 WN_PosnLmpOutpSts_R_Pbox_SignalGet(uint8 *SignalValue);
uint8 WN_AutoLmpSwtSts_SignalGet(uint8 *SignalValue);
uint8 WN_SysPowerMod_SignalGet(uint8 *SignalValue);
uint8 WN_LBrkLmpFailSts_SignalGet(uint8 *SignalValue);
uint8 WN_HiPosnBrkLmpFailSts_SignalGet(uint8 *SignalValue);
uint8 WN_RBrkLmpFailSts_SignalGet(uint8 *SignalValue);
uint8 WN_LicPlateLmpFailSts_SignalGet(uint8 *SignalValue);
uint8 WN_RvsLmpFailSts_SignalGet(uint8 *SignalValue);
uint8 WN_LRPosnLmpFailSts_SignalGet(uint8 *SignalValue);
uint8 WN_RRPosnLmpFailSts_SignalGet(uint8 *SignalValue);
uint8 WN_ParkLmpSts_R_Pbox_SignalGet(uint8 *SignalValue);
uint8 WN_RLSFailSts_SignalGet(uint8 *SignalValue);
uint8 WN_DrowsyDrvDetWarn_SignalGet(uint8 *SignalValue);
uint8 WN_FLTirePressIndSts_SignalGet(uint8 *SignalValue);
uint8 WN_FRTirePressIndSts_SignalGet(uint8 *SignalValue);
uint8 WN_RLTirePressIndSts_SignalGet(uint8 *SignalValue);
uint8 WN_RRTirePressIndSts_SignalGet(uint8 *SignalValue);
uint8 WN_FLTireTempSts_SignalGet(uint8 *SignalValue);
uint8 WN_FRTireTempSts_SignalGet(uint8 *SignalValue);
uint8 WN_RLTireTempSts_SignalGet(uint8 *SignalValue);
uint8 WN_RRTireTempSts_SignalGet(uint8 *SignalValue);
uint8 WN_WarnKeyInCarWhenExit_SignalGet(uint8 *SignalValue);
uint8 WN_WarnVldKeyNotFound_SignalGet(uint8 *SignalValue);
uint8 WN_WarnEngStrtNotMeet_SignalGet(uint8 *SignalValue);
uint8 WN_WarnEngStrtNotMeetMT_SignalGet(uint8 *SignalValue);
uint8 WN_PowerRlyFault_SignalGet(uint8 *SignalValue);
uint8 WN_WarnPowerNotInOffPosn_SignalGet(uint8 *SignalValue);
uint8 WN_RotSteerWheel_SignalGet(uint8 *SignalValue);
uint8 WN_DrvSBR_Visual_SignalGet(uint8 *SignalValue);
uint8 WN_PassSBR_Visual_SignalGet(uint8 *SignalValue);
uint8 WN_SecRowLSBR_Visual_SignalGet(uint8 *SignalValue);
uint8 WN_SecRowMidSBR_Visual_SignalGet(uint8 *SignalValue);
uint8 WN_SecRowRSBR_Visual_SignalGet(uint8 *SignalValue);
uint8 WN_DrvWarnMsg_SignalGet(uint8 *SignalValue);
uint8 WN_DrvWarnMsgFD_SignalGet(uint8 *SignalValue);
uint8 WN_TCU_ClutchHotWarning_SignalGet(uint8 *SignalValue);
uint8 WN_DrvFaiMsg_SignalGet(uint8 *SignalValue);
uint8 WN_DrvFaiMsgFD_SignalGet(uint8 *SignalValue);
uint8 WN_DrvFaiMsgHCU_SignalGet(uint8 *SignalValue);
uint8 WN_TCU_ErrCategory_SignalGet(uint8 *SignalValue);
uint8 WN_DCT_PrsBrk_Warn_SignalGet(uint8 *SignalValue);
uint8 WN_DCT_PrsBrk_WarnFD_SignalGet(uint8 *SignalValue);
uint8 WN_4L_Warn_0x137_SignalGet(uint8 *SignalValue);
uint8 WN_ACC_TimeGapSet_SignalGet(uint8 *SignalValue);
uint8 WN_ACC_FctSts_SignalGet(uint8 *SignalValue);
uint8 WN_Request_driveoff_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_PrsBrkWarn_SignalGet(uint8 *SignalValue);
uint8 WN_DCT_ShftNotAlwd_Warn_SignalGet(uint8 *SignalValue);
uint8 WN_DCT_ShftNotAlwd_WarnFD_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_ShftNotAlwd_Warn_SignalGet(uint8 *SignalValue);
uint8 WN_DiagLmpReq_SignalGet(uint8 *SignalValue);
uint8 WN_CouplingThermWarning_SignalGet(uint8 *SignalValue);
uint8 WN_EspFuncOffSts_mode_SignalGet(uint8 *SignalValue);
uint8 WN_CCO_Active_SignalGet(uint8 *SignalValue);
uint8 WN_CCO_TgtVel_SignalGet(uint8 *SignalValue);
uint8 WN_CCO_Warn_SignalGet(uint8 *SignalValue);
uint8 WN_ACC_InterSysInfoDisp_SignalGet(uint8 *SignalValue);
uint8 WN_ACC_TakeOverReq_SignalGet(uint8 *SignalValue);
uint8 WN_TJA_ICA_InterSysInfoDisp_SignalGet(uint8 *SignalValue);
uint8 WN_ISL_InterSysInfoDisp_SignalGet(uint8 *SignalValue);
uint8 WN_HWA_InterSysInfoDisp_SignalGet(uint8 *SignalValue);
uint8 WN_HWA_warning_SignalGet(uint8 *SignalValue);
uint8 WN_ALC_InterSysInfoDisp_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_SOCLow_Indcn_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_RemoveChrgLine_Indcn_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_Shift_P_Indcn_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_ConnectChrgLine_Indcn_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_RefuReq_Indcn_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_InhbChrgInfo_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_GearChngPorNTXT_SignalGet(uint8 *SignalValue);
uint8 WN_OPDParkWarnReq_SignalGet(uint8 *SignalValue);
uint8 WN_CarWashMode_Sts_SignalGet(uint8 *SignalValue);
uint8 WN_CarWashMode_StsDisp_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_HybSysErr_5_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_HybSysErr_3_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_HybSysErr_6_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_HybSysErr_7_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_HybSysErr_4_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_HybSysErr_1_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_HybSysErr_2_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_12VSysErr_1_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_12VSysErr_2_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_ChrgSysErr_1_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_ChrgSysErr_2_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_ChrgSysErr_3_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_ChrgSysErr_4_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_ChrgSysErr_5_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_ChrgSysErr_6_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_ChrgSysErr_7_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_ChrgSysErr_8_SignalGet(uint8 *SignalValue);
uint8 WN_BMS_ErrCategory_SignalGet(uint8 *SignalValue);
uint8 WN_VSG_Sts_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_BattLowTemWarn_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_ChargSts_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_EVContnsDistance_SignalGet(uint8 *SignalValue);
uint8 WN_BMS_BattHeatRunaway_SignalGet(uint8 *SignalValue);
uint8 WN_BMS_BattKeepTempSts_SignalGet(uint8 *SignalValue);
uint8 WN_BMS_BattSOC_SignalGet(uint16 *SignalValue);
uint8 WN_BMS_SOCLowWarn_SignalGet(uint8 *SignalValue);
uint8 WN_OBC_ConnectSts_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_DrvMod_SignalGet(uint8 *SignalValue);
uint8 WN_BMS_ChrgDurationTime_SignalGet(uint16 *SignalValue);
uint8 WN_HCU_RdyLmpSts_SignalGet(uint8 *SignalValue);
uint8 WN_BrkPedalSts_BCM_SignalGet(uint8 *SignalValue);
uint8 WN_AccelPedlPosnDiagc_SignalGet(uint8 *SignalValue);
uint8 WN_AccelPedalPosnVldty_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_AccelPedalPosn_Diag_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_AccelPedalPosn_DiagValid_SignalGet(uint8 *SignalValue);
uint8 WN_VehSpdVld_SignalGet(uint8 *SignalValue);
uint8 WN_VehSpdVldFD_SignalGet(uint8 *SignalValue);
uint8 WN_EMS_AuthenResult_SignalGet(uint8 *SignalValue);
uint8 WN_HCUImmoAuthRes_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_ModSwtFail_SignalGet(uint8 *SignalValue);
uint8 WN_FTIVFault_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_RaceLaunchSts_0x84_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_RaceLaunchSts_0x60_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_RaceLaunchAvail_0x84_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_RaceLaunchAvail_0x60_SignalGet(uint8 *SignalValue);
uint8 WN_DCT_RaceModeSts_SignalGet(uint8 *SignalValue);
uint8 WN_DCT_RaceModeStsFD_SignalGet(uint8 *SignalValue);
uint8 WN_GPF_Warning_SignalGet(uint8 *SignalValue);
uint8 WN_ACAmbTemp_SignalGet(uint8 *SignalValue);
uint8 WN_LLasHdLmpDiagSig_SignalGet(uint8 *SignalValue);
uint8 WN_RLasHdLmpDiagSig_SignalGet(uint8 *SignalValue);
uint8 WN_LasHdLmpSts_F_PBOX_SignalGet(uint8 *SignalValue);
uint8 WN_ALS_FailSts_SignalGet(uint8 *SignalValue);
uint8 WN_LeftHighBeamFailSts_SignalGet(uint8 *SignalValue);
uint8 WN_RightHighBeamFailSts_SignalGet(uint8 *SignalValue);
uint8 WN_LLowBeamFailSts_SignalGet(uint8 *SignalValue);
uint8 WN_RLowBeamFailSts_SignalGet(uint8 *SignalValue);
uint8 WN_LHiBeamFailSts_SignalGet(uint8 *SignalValue);
uint8 WN_RHiBeamFailSts_SignalGet(uint8 *SignalValue);
uint8 WN_LHeadLmpFailSts_SignalGet(uint8 *SignalValue);
uint8 WN_RHeadLmpFailSts_SignalGet(uint8 *SignalValue);
uint8 WN_FuelTankCapWarning_SignalGet(uint8 *SignalValue);
uint8 WN_RearELDLckSts_SignalGet(uint8 *SignalValue);
uint8 WN_WPC_FaultSts_SignalGet(uint8 *SignalValue);
uint8 WN_WPC_PhoneReminder_SignalGet(uint8 *SignalValue);
uint8 WN_EWP_ERR_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_BattLowHeatSts_SignalGet(uint8 *SignalValue);
uint8 WN_DistrctnLvl_SignalGet(uint8 *SignalValue);
uint8 WN_DrowsnsLvl_SignalGet(uint8 *SignalValue);
uint8 WN_DMSProc_SignalGet(uint8 *SignalValue);
uint8 WN_DMSProcResult_SignalGet(uint8 *SignalValue);
uint8 WN_DMSProcSts_SignalGet(uint8 *SignalValue);
uint8 WN_PressReliProgs_SignalGet(uint8 *SignalValue);
uint8 WN_T_Box_SysErrSts_SignalGet(uint8 *SignalValue);
uint8 WN_FCW_Warn_SignalGet(uint8 *SignalValue);
uint8 WN_AEB_VehTrig_SignalGet(uint8 *SignalValue);
uint8 WN_AEB_PedTrig_SignalGet(uint8 *SignalValue);
uint8 WN_FCW_AEB_VehFctSts_SignalGet(uint8 *SignalValue);
uint8 WN_AEB_JABrkTrig_SignalGet(uint8 *SignalValue);
uint8 WN_FCTA_Warn_SignalGet(uint8 *SignalValue);
uint8 WN_FCTBTrig_SignalGet(uint8 *SignalValue);
uint8 WN_CR_BliSts_SignalGet(uint8 *SignalValue);
uint8 WN_FCTA_B_FuncSts_SignalGet(uint8 *SignalValue);
uint8 WN_RSDS_RCW_Trigger_SignalGet(uint8 *SignalValue);
uint8 WN_RSDS_TrailerSts_SignalGet(uint8 *SignalValue);
uint8 WN_RSDS_BrkgTrig_SignalGet(uint8 *SignalValue);
uint8 WN_TSRSts_SignalGet(uint8 *SignalValue);
uint8 WN_IFCCalibrationSts_SignalGet(uint8 *SignalValue);
uint8 WN_CameraBlockageSts_SignalGet(uint8 *SignalValue);
uint8 WN_LSSErrSts_SignalGet(uint8 *SignalValue);
uint8 WN_IFC_Handsoffwarn_SignalGet(uint8 *SignalValue);
uint8 WN_AESintervention_SignalGet(uint8 *SignalValue);
uint8 WN_ESSintervention_SignalGet(uint8 *SignalValue);
uint8 WN_LCKStsIndcr_SignalGet(uint8 *SignalValue);
uint8 WN_AESSts_SignalGet(uint8 *SignalValue);
uint8 WN_AESErrSts_SignalGet(uint8 *SignalValue);
uint8 WN_ESSSts_SignalGet(uint8 *SignalValue);
uint8 WN_ESSErrSts_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_BattPowerRedWarn_SignalGet(uint8 *SignalValue);
uint8 WN_HCU_OPDFail_SignalGet(uint8 *SignalValue);
uint8 WN_LLowBeamFailSts_HCM_SignalGet(uint8 *SignalValue);
uint8 WN_RLowBeamFailSts_HCM_SignalGet(uint8 *SignalValue);
uint8 WN_LHiBeamFailSts_HCM_SignalGet(uint8 *SignalValue);
uint8 WN_RHiBeamFailSts_HCM_SignalGet(uint8 *SignalValue);
uint8 WN_EPS_FailSts_SignalGet(uint8 *SignalValue);
uint8 WN_EPS_FailSts_FD_SignalGet(uint8 *SignalValue);
uint8 WN_TCU_Warn_high_temp_SignalGet(uint8 *SignalValue);
uint8 WN_TCU_Warn_gearbox_faulty_SignalGet(uint8 *SignalValue);
uint8 WN_TCU_Warn_P_faulty_SignalGet(uint8 *SignalValue);
uint8 WN_TCU_Warn_release_button_SignalGet(uint8 *SignalValue);
uint8 WN_TCU_Warn_step_P_SignalGet(uint8 *SignalValue);
uint8 WN_TCU_Shift_not_allowed_Warn_SignalGet(uint8 *SignalValue);
uint8 WN_TCU_Warn_limphome_D_SignalGet(uint8 *SignalValue);
uint8 WN_TCU_Warn_limphome_P_Warn_SignalGet(uint8 *SignalValue);
uint8 WN_TCU_Warn_gearbox_N_Warn_SignalGet(uint8 *SignalValue);
uint8 WN_TCU_Warn_shifter_faulty_Warn_SignalGet(uint8 *SignalValue);
uint8 WN_TCU_Warn_drive_faulty_Warn_SignalGet(uint8 *SignalValue);
uint8 WN_TCU_Warn_vehicle_P_SignalGet(uint8 *SignalValue);
uint8 WN_TCU_Warn_prohibit_P_SignalGet(uint8 *SignalValue);
uint8 WN_TCU_Warn_driver_leaves_car_SignalGet(uint8 *SignalValue);
uint8 WN_TAB_SwtShift_Warn_SignalGet(uint8 *SignalValue);
uint8 WN_SCRSysWarnDisplay_SignalGet(uint8 *SignalValue);
uint8 WN_DPF_Warning_SignalGet(uint8 *SignalValue);
uint8 WN_SystemOperMod_SignalGet(uint8 *SignalValue);
uint8 WN_ShiftSysStuinLow_SignalGet(uint8 *SignalValue);
uint8 WN_FuncProtnSts_SignalGet(uint8 *SignalValue);
uint8 WN_Over_Spd_Warn_SignalGet(uint8 *SignalValue);
uint8 WN_Over_Spd_Warn_FD_SignalGet(uint8 *SignalValue);
uint8 WN_Shift_N_Warn_SignalGet(uint8 *SignalValue);
uint8 WN_Shift_N_Warn_FD_SignalGet(uint8 *SignalValue);
uint8 WN_TSM_Trailer_SignalGet(uint8 *SignalValue);
uint8 WN_TSM_Trailer_FD_SignalGet(uint8 *SignalValue);
uint8 WN_AutoLmpsts_SignalGet(uint8 *SignalValue);
uint8 WN_RainshedSts_SignalGet(uint8 *SignalValue);
uint8 WN_ELKMainState_SignalGet(uint8 *SignalValue);
uint8 WN_UVCAntiVirusFdbk_SignalGet(uint8 *SignalValue);
uint8 WN_SteerCorrnRmn_SignalGet(uint8 *SignalValue);
uint8 WN_SteerCorrnRmn_FD_SignalGet(uint8 *SignalValue);
uint8 WN_LAFSstatus_SignalGet(uint8 *SignalValue);
uint8 WN_RAFSstatus_SignalGet(uint8 *SignalValue);
uint8 WN_LLasHdLmpfailSts_SignalGet(uint8 *SignalValue);
uint8 WN_RLasHdLmpfailSts_SignalGet(uint8 *SignalValue);
uint8 WN_LLasHdLmpSts_SignalGet(uint8 *SignalValue);
uint8 WN_RLasHdLmpSts_SignalGet(uint8 *SignalValue);
uint8 WN_CCO_SwtShift_Warn_SignalGet(uint8 *SignalValue);
uint8 WN_WarnLmpReq_SignalGet(uint8 *SignalValue);
uint8 WN_FourLWarn_FD_SignalGet(uint8 *SignalValue);
uint8 WN_FourLWarn_SignalGet(uint8 *SignalValue);
uint8 WN_AntLostFlg_SignalGet(uint8 *SignalValue);
uint8 WN_AGS_Failure_SignalGet(uint8 *SignalValue);
uint8 WN_HWA_WarnInfoDisp_SignalGet(uint8 *SignalValue);
uint8 WN_NOH_SysInfoDisplay_SignalGet(uint8 *SignalValue);
uint8 WN_NOH_DistToExit_SignalGet(uint16 *SignalValue);
uint8 WN_V2X_FCW_SignalGet(uint8 *SignalValue);
uint8 WN_V2X_BSW_SignalGet(uint8 *SignalValue);
uint8 WN_V2X_LCW_SignalGet(uint8 *SignalValue);
uint8 WN_PPMIRErrSts_SignalGet(uint8 *SignalValue);
uint8 WN_V2X_EBW_SignalGet(uint8 *SignalValue);
uint8 WN_V2X_ICW_SignalGet(uint8 *SignalValue);
uint8 WN_V2X_LTA_SignalGet(uint8 *SignalValue);
uint8 WN_V2X_AVW_SignalGet(uint8 *SignalValue);
uint8 WN_V2X_EVW_SignalGet(uint8 *SignalValue);
uint8 WN_V2X_CLW_SignalGet(uint8 *SignalValue);
uint8 WN_V2X_VRUCW_SignalGet(uint8 *SignalValue);
uint8 WN_V2X_RLVW_SignalGet(uint8 *SignalValue);
uint8 WN_V2X_DNPW_SignalGet(uint8 *SignalValue);
uint8 WN_V2X_HLW_SignalGet(uint8 *SignalValue);
uint8 WN_V2X_TJW_SignalGet(uint8 *SignalValue);
uint8 WN_ECM_ClutovrheatdSts_SignalGet(uint8 *SignalValue);
uint8 WN_MRC_TakOver_Req_SignalGet(uint8 *SignalValue);
uint8 WN_NOH_WarnInfoDisplay_SignalGet(uint8 *SignalValue);
uint8 WN_PPMIErrSts_SignalGet(uint8 *SignalValue);
uint8 WN_ECM_OffroadThmSts_SignalGet(uint8 *SignalValue);
uint8 WN_Wade_SW_warn_SignalGet(uint8 *SignalValue);
uint8 WN_IDC_L2_TurnLightReq_SignalGet(uint8 *SignalValue);
uint8 WN_WadeModeWarn_SignalGet(uint8 *SignalValue);
uint8 WN_ACC_SpdSetValue_SignalGet(uint8 *SignalValue);
uint8 WN_RWPC_FaultSts_SignalGet(uint8 *SignalValue);//R11
uint8 WN_DrivingModReq_ESP_SignalGet(uint8 *SignalValue);
uint8 WN_DrivingModDis_SignalGet(uint8 *SignalValue);
uint8 WN_ALSDrvSide_FB_SignalGet(uint8 *SignalValue);
uint8 WN_RWPC_L_FaultSts_SignalGet(uint8 *SignalValue);//R11
uint8 WN_HWA_TakOver_Trig_SignalGet_ICU1_5(uint8 *SignalValue);//R11
uint8 WN_HWA_TakOver_Trig_SignalGet(uint8 *SignalValue);
uint8 WN_HWA_TakOver_Req_SignalGet_ICU1_5(uint8 *SignalValue);//R11
uint8 WN_HWA_TakOver_Req_SignalGet(uint8 *SignalValue);
uint8 WN_IntelligentEvaActSts_SignalGet(uint8 *SignalValue);
uint8 WN_AutoShiftSts_SignalGet(uint8 *SignalValue);
uint8 WN_LNT_Warning_SignalGet(uint8 *SignalValue);//R11
uint8 WN_HCU_ModSwtFail_0x204_SignalGet(uint8 *SignalValue);//R11
uint8 WN_ISL_InterSysInfoDisp_ICU1_5_SignalGet(uint8 *SignalValue);//R12
uint8 WN_TarLvlChg_SignalGet(uint8 *SignalValue);//R12
uint8 WN_RearLvlSts_SignalGet(uint8 *SignalValue);//R12
uint8 WN_AutoEasyAcsSts_SignalGet(uint8 *SignalValue);//R12
uint8 WN_TrailerSts_VDC_SignalGet(uint8 *SignalValue);//R12
uint8 WN_JackModeSts_SignalGet(uint8 *SignalValue);//R12
uint8 WN_RearLvlKickModeSts_SignalGet(uint8 *SignalValue);//R12
uint8 WN_LvlCtrlVehMode_SignalGet(uint8 *SignalValue);//R12
uint8 WN_LvlCtrlRmn_SignalGet(uint8 *SignalValue);//R12
uint8 WN_LvlCtrlWarnLmpReq_SignalGet(uint8 *SignalValue);//R12
uint8 WN_EngOilLowPresWrn_SignalGet(uint8 *SignalValue);//R12
uint8 WN_EngOilLvlWrn_SignalGet(uint8 *SignalValue);//R12
uint8 WN_VMDR_FctnSts_SignalGet(uint8 *SignalValue);//R12
uint8 WN_WPC_FaultSts_SignalGet_P03_P05(uint8 *SignalValue);//R12
uint8 WN_WPC_FaultSts_SignalGet_D01(uint8 *SignalValue);//R12
uint8 WN_WPC_FaultSts_SignalGet_D01_D03_P05(uint8 *SignalValue);//R12
uint8 WN_ECM24_EngOilLowPresWrn_SignalGet(uint8 *SignalValue);//P05DBCv4.0 add
uint8 WN_ECM13_RainshedSts_FL_SignalGet(uint8 *SignalValue);//P05DBCv5.0 add
uint8 WN_ECM13_RainshedSts_FR_SignalGet(uint8 *SignalValue);//P05DBCv5.0 add
uint8 WN_ECM13_TrunkSts_Y_SignalGet(uint8 *SignalValue);
uint8 WN_ECM24_BarConnSts_SignalGet(uint8 *SignalValue);//R13
uint8 WN_StartModSts_SignalGet(uint8 *SignalValue);//R13
uint8 WN_TrailerhookSts_SignalGet(uint8 *SignalValue);//R13
uint8 WN_TrailerSts_SignalGet(uint8 *SignalValue);//R13
uint8 WN_TrailerhookFltSt_SignalGet(uint8 *SignalValue);//R13
uint8 WN_VehicleParkRemind_SignalGet(uint8 *SignalValue);//R13
uint8 WN_TrailerhookClsRemind_SignalGet(uint8 *SignalValue);//R13
uint8 WN_TrailerConnectRemind_SignalGet(uint8 *SignalValue);//R13
uint8 WN_HWA_InterSysInfoDisp_SignalGet_ICU1_5(uint8 *SignalValue);//R13
uint8 WN_HWA_InhibitWarn_SignalGet(uint8 *SignalValue);
uint8 WN_HWA_warning_SignalGet_ICU1_5(uint8 *SignalValue);//R13
uint8 WN_HWA_WarnInfoDisp_SignalGet_ICU1_5(uint8 *SignalValue);//R13
uint8 WN_LvlCtrlRestrcn1_SignalGet(uint8 *SignalValue);//R13
uint8 WN_LvlCtrlRestrcn2_SignalGet(uint8 *SignalValue);//R13
uint8 WN_LvlCtrlRestrcn3_SignalGet(uint8 *SignalValue);//R13
uint8 WN_LvlCtrlRestrcn4_SignalGet(uint8 *SignalValue);//R13
uint8 WN_LvlCtrlRestrcn5_SignalGet(uint8 *SignalValue);//R13
uint8 WN_LvlCtrlRestrcn6_SignalGet(uint8 *SignalValue);//R13
uint8 WN_LvlCtrlRestrcn7_SignalGet(uint8 *SignalValue);//R13
uint8 WN_Navigation_Speed_Down_SignalGet(uint8 *SignalValue);//R14
uint8 WN_FastChrgnLidSts_SignalGet(uint8 *SignalValue);//R14
uint8 WN_SlowChrgnLidSts_SignalGet(uint8 *SignalValue);//R14
uint8 WN_FastChrgnLidAlarm_SignalGet(uint8 *SignalValue);//R14
uint8 WN_SlowChrgnLidAlarm_SignalGet(uint8 *SignalValue);//R14
uint8 WN_NavDecActive_SignalGet(uint8 *SignalValue);//R14
uint8 WN_SCRSysWarnDisplay_B2_SignalGet(uint8 *SignalValue);//R15
uint8 WN_UreaRemainDist_SignalGet(uint16 *SignalValue);//R15
uint8 WN_WshngLiquidLvlWarn_SignalGet(uint8 *SignalValue);//R15
uint8 WN_CST_Status_SignalGet(uint8 *SignalValue);//R15
uint8 WN_PDCU_EvSave_disl_SignalGet(uint8 *SignalValue);//R15
uint8 WN_OBC_ModSts_SignalGet(uint8 *SignalValue);//R15
uint8 WN_HCU_HP5_AvailabilityOfARF_SignalGet(uint8 *SignalValue);//P02 DBCv2.0
uint8 WN_HCU_HP5_lossenPedalPrompt_SignalGet(uint8 *SignalValue);//P02 DBCv2.0
uint8 WN_T_Box_SysErrSts_0x56_SignalGet(uint8 *SignalValue);//R17
uint8 WN_OilBoxSplySts_SignalGet(uint8 *SignalValue);//R17
uint8 WN_HWA_Text_Lib_SignalGet(uint8 *SignalValue);//R17
uint8 WN_TJA_FollowSts_SignalGet(uint8 *SignalValue);//R17
uint8 WN_LaneAvailability_SignalGet(uint8 *SignalValue);//R17
uint8 WN_MidELDLckSwtReq_SignalGet(uint8 *SignalValue);//R17
uint8 WN_PowerRelsOverSpdWarn_SignalGet(uint8 *SignalValue);//R17
uint8 WN_OBC_ModSts_EV_SignalGet(uint8 *SignalValue);//R18
uint8 WN_OBC_CCLineConnectSts_SignalGet(uint8 *SignalValue);//R18
uint8 WN_EVCC_PPLineSts_SignalGet(uint8 *SignalValue);//R18
uint8 WN_BMS_StsCC2Line_SignalGet(uint8 *SignalValue);//R18
uint8 WN_VCU_CrsCtrlSts_SignalGet(uint8 *SignalValue);//R18
uint8 WN_VCU_CrsSpd_SignalGet(uint8 *SignalValue);//R18
uint8 WN_VCU_ChrgnSts_SignalGet(uint8 *SignalValue);//R18
uint8 WN_Phone_ChrgnMode(uint8 *SignalValue);//R18
uint8 WN_BMS_SOC(uint16 *SignalValue);//R18



//Get IO PIN input
void WN_PIN_C3_IOGet(uint8 *Data);
void WN_PIN_C4_IOGet(uint8 *Data);
void WN_PIN_C1_IOGet(uint8 *Data);
//Get other module data
void WN_MenuSetData_APIGet(MenuSetData_t *Data);
void WN_TachoInfo_APIGet(s_TachoInfo_t *Data);
void WN_SpeedoInfo_APIGet(s_SpeedoInfo_t *Data);
void WN_OdoRteGetParament_APIGet(s_OdoRteGetParament_t *Data);
void WN_Overspeed_Enable_APIGet(uint8 *Data);
void WN_Set_Overspeed_APIGet(uint16 *Data);
void WN_LowFuel_Active_APIGet(FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE *Data);

#define SWC_WN_STOP_SEC_CODE
#include "SWC_WN_MemMap.h"

/**********************************************************************************************************
**
**  Revision:      1.0  
**  
**  Author  :      Zhang Bin
**
**  Date    :      2021/01/25     Original Version
**
**********************************************************************************************************/

/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/

#endif




