/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Common_Normal.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <Common_Normal>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_COMMON_NORMAL_H
# define RTE_COMMON_NORMAL_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Os.h"
# include "Rte_Common_Normal_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_CheckSum_IP2;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_ABMWarnLmpFailrSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_ACCErr;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_BattChrgLmpSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_DrvSeatBeltWarnLmpFailSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_EngOilPressLowLmpSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_Err;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_FuelLvlInfo;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_FuelLvlLowLmpSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_PassSeatBeltWarnLmpFailSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VINcompr;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VehSpdUnit;
extern VAR(uint32, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VehTotDistance;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VehTotDistanceValid;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_RollingCounter_IP2;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_SafetyCanOutputViaNormal_dummy_HUT_IP2_0;
extern VAR(boolean, RTE_VAR_INIT) Rte_Power_Sd_BswM_Warm_Reset_Element;
extern VAR(uint32, RTE_VAR_INIT) Rte_SocDtcProcess_pPSR_DiagMonitorReInitFlag_ChangeCounter;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_tiSR_SWC_TT_SelfCheck_Element;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_NonTrust_OsCore0_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_CheckSum_IP2;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_ABMWarnLmpFailrSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_ACCErr;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_AvgFuelCons;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_BattChrgLmpSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_CurrTheme;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_DrvSeatBeltWarnLmpFailSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_EngOilPressLowLmpSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_Err;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelAuxTankR;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelLvlInfo;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelMainTankR;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_InstFuelCons;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_InstFuelConsUnit;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_LagueSet;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_PassSeatBeltWarnLmpFailSts;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_RemainDistance;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VINcompr;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehSpdDisp;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehSpdUnit;
extern VAR(uint32, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehTotDistance;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehTotDistanceValid;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VelSpdDisp_Mile;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_RollingCounter_IP2;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_CanOutputViaGateway_dummy_HUT_IP2_0;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_Odo_RunCounter_RunCounter;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_SpeedoInfo_IndicateSpeed;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_SpeedoInfo_OverSpdWrnFlg;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_SpeedoInfo_RealSpeed;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_SpeedoInfo_VehRunSts;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_Sd_TachoInfo_EngRunSts;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_Sd_TachoInfo_EngSpd;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_ppSR_SWCNormal_ChimeID_Element;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Normal_ppSR_SWCNormal_MenuSet_OverSpeedEnable_Element;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_Normal_ppSR_SWCNormal_MenuSet_OverSpeedLimit_Element;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_GateWay_SocReadyFlag_Element;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_GateWay_ppSR_SWCGateWay_S2M_Information_SpeedValue;
extern VAR(uint16, RTE_VAR_INIT) Rte_Common_GateWay_ppSR_SWCGateWay_S2M_Information_TachoValue;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrust_OsCore0_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */

# ifndef RTE_CORE

#  define RTE_START_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* RTE Helper-Functions */
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);

#  define RTE_STOP_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ACAmbTemp_ACAmbTemp (0U)
#  define Rte_InitValue_APS_FLSideSnsrFailSts_APS_FLSideSnsrFailSts (0U)
#  define Rte_InitValue_APS_FRSideSnsrFailSts_APS_FRSideSnsrFailSts (0U)
#  define Rte_InitValue_APS_RLSideSnsrFailSts_APS_RLSideSnsrFailSts (0U)
#  define Rte_InitValue_APS_RRSideSnsrFailSts_APS_RRSideSnsrFailSts (0U)
#  define Rte_InitValue_APS_SysSoundIndcn_APS_SysSoundIndcn (0U)
#  define Rte_InitValue_APS_WorkSts_APS_WorkSts (0U)
#  define Rte_InitValue_AccelPedalPosnVldty_AccelPedalPosnVldty (0U)
#  define Rte_InitValue_AccelPedlPosnDiagc_AccelPedlPosnDiagc (0U)
#  define Rte_InitValue_AutoLmpSwtSts_AutoLmpSwtSts (0U)
#  define Rte_InitValue_BMS_BattHeatRunaway_BMS_BattHeatRunaway (0U)
#  define Rte_InitValue_BMS_BattKeepTempSts_BMS_BattKeepTempSts (0U)
#  define Rte_InitValue_BMS_BattSOC_BMS_BattSOC (0U)
#  define Rte_InitValue_BMS_ChrgDurationTime_BMS_ChrgDurationTime (0U)
#  define Rte_InitValue_BMS_IntelEngIdlChrgnSts_BMS_IntelEngIdlChrgnSts (0U)
#  define Rte_InitValue_BMS_SOCLowWarn_BMS_SOCLowWarn (0U)
#  define Rte_InitValue_BSD_LCA_warningReqRight_BSD_LCA_warningReqRight (0U)
#  define Rte_InitValue_BSD_LCA_warningReqleft_BSD_LCA_warningReqleft (0U)
#  define Rte_InitValue_BrkPedalSts_BCM_BrkPedalSts_BCM (0U)
#  define Rte_InitValue_CCO_Active_CCO_Active (0U)
#  define Rte_InitValue_CCO_TgtVel_CCO_TgtVel (0U)
#  define Rte_InitValue_CCO_Warn_CCO_Warn (0U)
#  define Rte_InitValue_CR_BliSts_CR_BliSts (0U)
#  define Rte_InitValue_CouplingThermWarning_CouplingThermWarning (0U)
#  define Rte_InitValue_CruiseCtrlSts_CruiseCtrlSts (0U)
#  define Rte_InitValue_CruiseCtrlSts_PHEV_CruiseCtrlSts_PHEV (0U)
#  define Rte_InitValue_DCT3_TgtEngSpdIP_TgtEngSpdIP (0U)
#  define Rte_InitValue_DCT3_TgtEngSpdIPValid_TgtEngSpdIPValid (0U)
#  define Rte_InitValue_DMSProc_DMSProc (0U)
#  define Rte_InitValue_DMSProcResult_DMSProcResult (0U)
#  define Rte_InitValue_DMSProcSts_DMSProcSts (0U)
#  define Rte_InitValue_DOW_warningReqRight_DOW_warningReqRight (0U)
#  define Rte_InitValue_DOW_warningReqleft_DOW_warningReqleft (0U)
#  define Rte_InitValue_DiagLmpReq_DiagLmpReq (0U)
#  define Rte_InitValue_DistrctnLvl_DistrctnLvl (0U)
#  define Rte_InitValue_DrowsnsLvl_DrowsnsLvl (0U)
#  define Rte_InitValue_DrowsyDrvDetWarn_DrowsyDrvDetWarn (0U)
#  define Rte_InitValue_DrvDoorSts_DrvDoorSts (0U)
#  define Rte_InitValue_Dyn_PwrSv_Lvl_Dyn_PwrSv_Lvl (0U)
#  define Rte_InitValue_ECM11_EngSpd_ForIP_EngSpd_ForIP (0U)
#  define Rte_InitValue_ECM1_EngSpdVldty_EngSpdVldty (0U)
#  define Rte_InitValue_ECM_VehDstBackup_ECM_VehDstBackup (0U)
#  define Rte_InitValue_EMS_AuthenResult_EMS_AuthenResult (0U)
#  define Rte_InitValue_ESP_HMI_WarningOn_ESP_HMI_WarningOn (0U)
#  define Rte_InitValue_EWP_Err_EWP_Err (0U)
#  define Rte_InitValue_EngClntTempVldty_EngClntTempVldty (0U)
#  define Rte_InitValue_EngClntTempWarn_EngClntTempWarn (0U)
#  define Rte_InitValue_EngCoolantTemp_EngCoolantTemp (0U)
#  define Rte_InitValue_EngSVSSig_EngSVSSig (0U)
#  define Rte_InitValue_EngSpdVldty_EngSpdVldty (0U)
#  define Rte_InitValue_EngSpd_ForIP_EngSpd_ForIP (0U)
#  define Rte_InitValue_EspFuncOffSts_mode_EspFuncOffSts_mode (0U)
#  define Rte_InitValue_FCTA_B_FuncSts_FCTA_B_FuncSts (0U)
#  define Rte_InitValue_FCTA_Warn_FCTA_Warn (0U)
#  define Rte_InitValue_FCTBTrig_FCTBTrig (0U)
#  define Rte_InitValue_FFogLmpSts_F_Pbox_FFogLmpSts_F_Pbox (0U)
#  define Rte_InitValue_FLTirePress_FLTirePress (0U)
#  define Rte_InitValue_FLTirePressIndSts_FLTirePressIndSts (0U)
#  define Rte_InitValue_FLTireTemp_FLTireTemp (0U)
#  define Rte_InitValue_FLTireTempSts_FLTireTempSts (0U)
#  define Rte_InitValue_FPAS_SoundIndcn_FPAS_SoundIndcn (0U)
#  define Rte_InitValue_FPAS_SoundIndcn_FD_FPAS_SoundIndcn_FD (0U)
#  define Rte_InitValue_FPAS_WorkSts_FPAS_WorkSts (0U)
#  define Rte_InitValue_FPAS_WorkSts_FD_FPAS_WorkSts_FD (0U)
#  define Rte_InitValue_FRTirePress_FRTirePress (0U)
#  define Rte_InitValue_FRTirePressIndSts_FRTirePressIndSts (0U)
#  define Rte_InitValue_FRTireTemp_FRTireTemp (0U)
#  define Rte_InitValue_FRTireTempSts_FRTireTempSts (0U)
#  define Rte_InitValue_FTIVFault_FTIVFault (0U)
#  define Rte_InitValue_FuelConsumption_FuelConsumption (0U)
#  define Rte_InitValue_FuelTankCapWarning_FuelTankCapWarning (0U)
#  define Rte_InitValue_GPF_Warning_GPF_Warning (0U)
#  define Rte_InitValue_GentrWarnLmpSts_GentrWarnLmpSts (0U)
#  define Rte_InitValue_HCUImmoAuthRes_HCUImmoAuthRes (0U)
#  define Rte_InitValue_HCU_ACLineDisconnect_HCU_ACLineDisconnect (0U)
#  define Rte_InitValue_HCU_AccelPedalPosn_Diag_HCU_AccelPedalPosn_Diag (0U)
#  define Rte_InitValue_HCU_AccelPedalPosn_DiagValid_HCU_AccelPedalPosn_DiagValid (0U)
#  define Rte_InitValue_HCU_AvailPower_TM_HCU_AvailPower_TM (0U)
#  define Rte_InitValue_HCU_BattLowHeatSts_HCU_BattLowHeatSts (0U)
#  define Rte_InitValue_HCU_BattLowTemWarn_HCU_BattLowTemWarn (0U)
#  define Rte_InitValue_HCU_ChargSts_HCU_ChargSts (0U)
#  define Rte_InitValue_HCU_ChrgSysErr_1_HCU_ChrgSysErr_1 (0U)
#  define Rte_InitValue_HCU_ChrgSysErr_2_HCU_ChrgSysErr_2 (0U)
#  define Rte_InitValue_HCU_ChrgSysErr_3_HCU_ChrgSysErr_3 (0U)
#  define Rte_InitValue_HCU_ChrgSysErr_4_HCU_ChrgSysErr_4 (0U)
#  define Rte_InitValue_HCU_ChrgSysErr_5_HCU_ChrgSysErr_5 (0U)
#  define Rte_InitValue_HCU_ChrgSysErr_6_HCU_ChrgSysErr_6 (0U)
#  define Rte_InitValue_HCU_ChrgSysErr_7_HCU_ChrgSysErr_7 (0U)
#  define Rte_InitValue_HCU_ChrgSysErr_8_HCU_ChrgSysErr_8 (0U)
#  define Rte_InitValue_HCU_ChrgSysLmpSts_HCU_ChrgSysLmpSts (0U)
#  define Rte_InitValue_HCU_DrvMod_HCU_DrvMod (0U)
#  define Rte_InitValue_HCU_ECODrvHabit_Indcn_HCU_ECODrvHabit_Indcn (100U)
#  define Rte_InitValue_HCU_EVContnsDistance_HCU_EVContnsDistance (0U)
#  define Rte_InitValue_HCU_EVContnsDistanceVld_HCU_EVContnsDistanceVld (0U)
#  define Rte_InitValue_HCU_EVLmpSts_HCU_EVLmpSts (0U)
#  define Rte_InitValue_HCU_EgyUsed_HCU_EgyUsed (0U)
#  define Rte_InitValue_HCU_IntelBattTempMagSts_HCU_IntelBattTempMagSts (0U)
#  define Rte_InitValue_HCU_RaceLaunchAvail_HCU_RaceLaunchAvail (0U)
#  define Rte_InitValue_HCU_RaceLaunchSts_HCU_RaceLaunchSts (0U)
#  define Rte_InitValue_HCU_RecupPwr_HCU_RecupPwr (0U)
#  define Rte_InitValue_HCU_TotDrvReqPower_HCU_TotDrvReqPower (0U)
#  define Rte_InitValue_HCU_WorkshopMode_HCU_WorkshopMode (0U)
#  define Rte_InitValue_HiBeamSts_F_Pbox_HiBeamSts_F_Pbox (0U)
#  define Rte_InitValue_HiLowBeamSts_HiLowBeamSts (0U)
#  define Rte_InitValue_HiPosnBrkLmpFailSts_HiPosnBrkLmpFailSts (0U)
#  define Rte_InitValue_HoodSts_F_Pbox_HoodSts_F_Pbox (0U)
#  define Rte_InitValue_IB_Warn_IB_Warn (0U)
#  define Rte_InitValue_KL30BRelaySts_KL30BRelaySts (0U)
#  define Rte_InitValue_LADBstatus_LADBstatus (0U)
#  define Rte_InitValue_LBrkLmpFailSts_LBrkLmpFailSts (0U)
#  define Rte_InitValue_LHeadLmpFailSts_LHeadLmpFailSts (0U)
#  define Rte_InitValue_LHiBeamFailSts_LHiBeamFailSts (0U)
#  define Rte_InitValue_LHiBeamSts_LHiBeamSts (FALSE)
#  define Rte_InitValue_LLasHdLmpDiagSig_LLasHdLmpDiagSig (0U)
#  define Rte_InitValue_LLowBeamFailSts_LLowBeamFailSts (0U)
#  define Rte_InitValue_LRDoorSts_LRDoorSts (0U)
#  define Rte_InitValue_LRPosnLmpFailSts_LRPosnLmpFailSts (0U)
#  define Rte_InitValue_LTurnLmpSts_R_Pbox_LTurnLmpSts_R_Pbox (0U)
#  define Rte_InitValue_LasHdLmpSts_F_Pbox_LasHdLmpSts_F_Pbox (0U)
#  define Rte_InitValue_LicPlateLmpFailSts_LicPlateLmpFailSts (0U)
#  define Rte_InitValue_LvPwrSysErr_LvPwrSysErr (0U)
#  define Rte_InitValue_MILSts_MILSts (0U)
#  define Rte_InitValue_OBC_ConnectSts_OBC_ConnectSts (0U)
#  define Rte_InitValue_PASWorkCmd_PASWorkCmd (0U)
#  define Rte_InitValue_ParkLmpSts_R_Pbox_ParkLmpSts_R_Pbox (0U)
#  define Rte_InitValue_PassengerDoorSts_PassengerDoorSts (0U)
#  define Rte_InitValue_PosnLmpOutpSts_R_Pbox_PosnLmpOutpSts_R_Pbox (0U)
#  define Rte_InitValue_PowerRlyFault_PowerRlyFault (0U)
#  define Rte_InitValue_PressReliProgs_PressReliProgs (0U)
#  define Rte_InitValue_RADBstatus_RADBstatus (0U)
#  define Rte_InitValue_RBrkLmpFailSts_RBrkLmpFailSts (0U)
#  define Rte_InitValue_RCTA_warningReqLeft_RCTA_warningReqLeft (FALSE)
#  define Rte_InitValue_RCTA_warningReqRight_RCTA_warningReqRight (FALSE)
#  define Rte_InitValue_RFogLmpFailSts_R_Pbox_RFogLmpFailSts_R_Pbox (0U)
#  define Rte_InitValue_RFogLmpSts_R_Pbox_RFogLmpSts_R_Pbox (0U)
#  define Rte_InitValue_RHeadLmpFailSts_RHeadLmpFailSts (0U)
#  define Rte_InitValue_RHiBeamFailSts_RHiBeamFailSts (0U)
#  define Rte_InitValue_RHiBeamSts_RHiBeamSts (FALSE)
#  define Rte_InitValue_RLSFailSts_RLSFailSts (0U)
#  define Rte_InitValue_RLTirePress_RLTirePress (0U)
#  define Rte_InitValue_RLTirePressIndSts_RLTirePressIndSts (0U)
#  define Rte_InitValue_RLTireTemp_RLTireTemp (0U)
#  define Rte_InitValue_RLTireTempSts_RLTireTempSts (0U)
#  define Rte_InitValue_RLasHdLmpDiagSig_RLasHdLmpDiagSig (0U)
#  define Rte_InitValue_RLowBeamFailSts_RLowBeamFailSts (0U)
#  define Rte_InitValue_RPAS_SoundIndcn_RPAS_SoundIndcn (0U)
#  define Rte_InitValue_RPAS_SoundIndcn_FD_RPAS_SoundIndcn_FD (0U)
#  define Rte_InitValue_RPAS_WorkSts_RPAS_WorkSts (0U)
#  define Rte_InitValue_RPAS_WorkSts_FD_RPAS_WorkSts_FD (0U)
#  define Rte_InitValue_RRDoorSts_RRDoorSts (0U)
#  define Rte_InitValue_RRPosnLmpFailSts_RRPosnLmpFailSts (0U)
#  define Rte_InitValue_RRTirePress_RRTirePress (0U)
#  define Rte_InitValue_RRTirePressIndSts_RRTirePressIndSts (0U)
#  define Rte_InitValue_RRTireTemp_RRTireTemp (0U)
#  define Rte_InitValue_RRTireTempSts_RRTireTempSts (0U)
#  define Rte_InitValue_RSDS_BliSts_RSDS_BliSts (0U)
#  define Rte_InitValue_RSDS_BrkgTrig_RSDS_BrkgTrig (0U)
#  define Rte_InitValue_RSDS_CTA_Actv_RSDS_CTA_Actv (0U)
#  define Rte_InitValue_RSDS_ErrSts_RSDS_ErrSts (0U)
#  define Rte_InitValue_RSDS_IPSoundReq_RSDS_IPSoundReq (0U)
#  define Rte_InitValue_RSDS_LCAResp_RSDS_LCAResp (0U)
#  define Rte_InitValue_RSDS_RCW_Trigger_RSDS_RCW_Trigger (0U)
#  define Rte_InitValue_RSDS_TrailerSts_RSDS_TrailerSts (0U)
#  define Rte_InitValue_RTurnLmpSts_R_Pbox_RTurnLmpSts_R_Pbox (0U)
#  define Rte_InitValue_Rc_Cluster_Shutdown_Status_Element (0U)
#  define Rte_InitValue_Rc_Fuel_Status_Fuel_Status (0U)
#  define Rte_InitValue_Rc_Odo_RunCounter_RunCounter (0U)
#  define Rte_InitValue_Rc_SpeedoInfo_IndicateSpeed (0U)
#  define Rte_InitValue_Rc_SpeedoInfo_OverSpdWrnFlg (0U)
#  define Rte_InitValue_Rc_SpeedoInfo_RealSpeed (0U)
#  define Rte_InitValue_Rc_SpeedoInfo_VehRunSts (0U)
#  define Rte_InitValue_Rc_TachoInfo_EngRunSts (0U)
#  define Rte_InitValue_Rc_TachoInfo_EngSpd (0U)
#  define Rte_InitValue_RearELDLckSts_RearELDLckSts (0U)
#  define Rte_InitValue_RemoteModSts_RemoteModSts (0U)
#  define Rte_InitValue_RotSteerWheel_RotSteerWheel (0U)
#  define Rte_InitValue_RvsLmpFailSts_RvsLmpFailSts (0U)
#  define Rte_InitValue_SDWActiveSts_SDWActiveSts (0U)
#  define Rte_InitValue_SDW_SoundIndcn_SDW_SoundIndcn (0U)
#  define Rte_InitValue_SS_Enable_Lamp_SS_Enable_Lamp (0U)
#  define Rte_InitValue_SS_Fault_Lamp_SS_Fault_Lamp (0U)
#  define Rte_InitValue_SS_Screen_tip_SS_Screen_tip (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_CheckSum_IP2 (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_ABMWarnLmpFailrSts (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_ACCErr (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_AvgFuelCons (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_BattChrgLmpSts (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_CurrTheme (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_DrvSeatBeltWarnLmpFailSts (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_EngOilPressLowLmpSts (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_Err (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_FuelAuxTankR (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_FuelLvlInfo (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_FuelLvlLowLmpSts (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_FuelMainTankR (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_InstFuelCons (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_InstFuelConsUnit (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_LagueSet (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_PassSeatBeltWarnLmpFailSts (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_RemainDistance (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_VINcompr (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_VehSpdDisp (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_VehSpdUnit (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_VehTotDistance (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_VehTotDistanceValid (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_IP_VelSpdDisp_Mile (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_RollingCounter_IP2 (0U)
#  define Rte_InitValue_SafetyCanOutputViaNormal_dummy_HUT_IP2_0 (0U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_CheckSum_IP2 (0U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_ABMWarnLmpFailrSts (0U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_ACCErr (0U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_AvgFuelCons (4095U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_BattChrgLmpSts (0U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_CurrTheme (4U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_DrvSeatBeltWarnLmpFailSts (0U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_EBDFailSts (0U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_EngOilPressLowLmpSts (0U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_Err (0U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_FuelAuxTankR (10U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_FuelLvlInfo (255U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts (0U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_FuelMainTankR (10U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_InstFuelCons (16383U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_InstFuelConsUnit (0U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_LagueSet (15U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_PassSeatBeltWarnLmpFailSts (0U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_RemainDistance (4095U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_VINcompr (0U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_VehSpdDisp (0U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_VehSpdUnit (0U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_VehTotDistance (16777215U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_VehTotDistanceValid (0U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_IP_VelSpdDisp_Mile (0U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_RollingCounter_IP2 (0U)
#  define Rte_InitValue_Sd_CanOutputViaGateway_dummy_HUT_IP2_0 (0U)
#  define Rte_InitValue_Sd_Fuel_Status_Fuel_Status (0U)
#  define Rte_InitValue_Sd_Odo_RunCounter_RunCounter (0U)
#  define Rte_InitValue_Sd_SpeedoInfo_IndicateSpeed (0U)
#  define Rte_InitValue_Sd_SpeedoInfo_OverSpdWrnFlg (0U)
#  define Rte_InitValue_Sd_SpeedoInfo_RealSpeed (0U)
#  define Rte_InitValue_Sd_SpeedoInfo_VehRunSts (0U)
#  define Rte_InitValue_Sd_TachoInfo_EngRunSts (0U)
#  define Rte_InitValue_Sd_TachoInfo_EngSpd (0U)
#  define Rte_InitValue_Stat_PwrSv_Lvl_Stat_PwrSv_Lvl (0U)
#  define Rte_InitValue_SysPowerMod_SysPowerMod (0U)
#  define Rte_InitValue_TGS_LEVER_TGS_LEVER (0U)
#  define Rte_InitValue_TSRSpdLim_TSRSpdLim (0U)
#  define Rte_InitValue_TSRSpdLimCfdc_TSRSpdLimCfdc (0U)
#  define Rte_InitValue_TSRSpdLimSts_TSRSpdLimSts (0U)
#  define Rte_InitValue_TSRSpdLimWarn_TSRSpdLimWarn (0U)
#  define Rte_InitValue_TSRSts_TSRSts (0U)
#  define Rte_InitValue_TSRTrfcSignVal_TSRTrfcSignVal (0U)
#  define Rte_InitValue_T_Box_SysErrSts_T_Box_SysErrSts (0U)
#  define Rte_InitValue_TgtCrsVehSpd_TgtCrsVehSpd (0U)
#  define Rte_InitValue_TgtRcprtnTrqSts_TgtRcprtnTrqSts (0U)
#  define Rte_InitValue_TirePressSysFailrIndcn_TirePressSysFailrIndcn (0U)
#  define Rte_InitValue_TrailerSts_TrailerSts (0U)
#  define Rte_InitValue_TranPMode_Sts_TranPMode_Sts (0U)
#  define Rte_InitValue_TrunkSts_TrunkSts (0U)
#  define Rte_InitValue_VSG_HUTSoundResp_VSG_HUTSoundResp (0U)
#  define Rte_InitValue_VSG_Sts_VSG_Sts (0U)
#  define Rte_InitValue_WPC_FaultSts_WPC_FaultSts (0U)
#  define Rte_InitValue_WPC_PhoneReminder_WPC_PhoneReminder (0U)
#  define Rte_InitValue_WarnEngStrtNotMeet_WarnEngStrtNotMeet (0U)
#  define Rte_InitValue_WarnKeyInCarWhenExit_WarnKeyInCarWhenExit (0U)
#  define Rte_InitValue_WarnPowerNotInOffPosn_WarnPowerNotInOffPosn (0U)
#  define Rte_InitValue_WarnVldKeyNotFound_WarnVldKeyNotFound (0U)
#  define Rte_InitValue_ppSR_SWCNormal_ChimeID_Element (0U)
#  define Rte_InitValue_ppSR_SWCNormal_MenuSet_OverSpeedEnable_Element (0U)
#  define Rte_InitValue_ppSR_SWCNormal_MenuSet_OverSpeedLimit_Element (0U)
#  define Rte_InitValue_rcSR_SWCNormal_BswM_Warm_Reset_Element (FALSE)
#  define Rte_InitValue_rpSR_SWCNormal_ChimeID_Element (0U)
#  define Rte_InitValue_rpSR_SWCNormal_DiagMonitorReInitFlag_ChangeCounter (0U)
#  define Rte_InitValue_rpSR_SWCNormal_MenuSet_OverSpeedEnable_Element (0U)
#  define Rte_InitValue_rpSR_SWCNormal_MenuSet_OverSpeedLimit_Element (0U)
#  define Rte_InitValue_rpSR_SWCNormal_S2M_Information_SpeedValue (0U)
#  define Rte_InitValue_rpSR_SWCNormal_S2M_Information_TachoValue (0U)
#  define Rte_InitValue_tiSR_Rte_Read_Sd_RTC_Data_SleepDateTime (-1LL)
#  define Rte_InitValue_tiSR_Rte_Read_Sd_RTC_Data_UtcTime (-1LL)
#  define Rte_InitValue_tiSR_SWC_TT_SelfCheck_Element (1U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_OsApplication_NonTrust_OsCore0_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Rte_tsFUEL_TC_ODO, RTE_VAR_NOINIT) Rte_FUEL_TC_ODO; /* PRQA S 0759 */ /* MD_MSR_Union */

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrust_OsCore0_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_AVASDTCResults_AVASDTC(P2VAR(AVASDTCRet, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(P2VAR(CconfigKind_400Bytes, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_Rc_Cluster_Shutdown_Status_Element(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_Rc_Fuel_Status_Fuel_Status(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_Vconfig_GetKindBuffers_AllKinds(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_Vconfig_GetKindBuffers_AllKinds(P2VAR(VconfigKind_Allbuffers, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_DrvModStatusRecord_Element(P2VAR(DM_tstDrvModStatusRecord, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_EnergyInfoId_Data(P2VAR(EnergyInfoIdDataType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(P2VAR(FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_MenuSetData_Element(P2VAR(MenuSetData_t, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_OdoParament_Element(P2VAR(s_OdoRteGetParament_t, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_SpeedoInfo_Element(P2VAR(s_SpeedoInfo_t, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_TC_Module_Output_Data_Element(P2VAR(TC_MODULE_OUTPUT_DATA_STRUCT_RTE, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_TC_NE_ChargStsOutput_Element(P2VAR(TC_NE_ChargStsOutput, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_TachoInfo_Element(P2VAR(s_TachoInfo_t, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_rpSR_SWCNormal_WarningStsOutput_Element(P2VAR(WN_WarningStsOutput, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_tiSR_Rte_Read_Sd_RTC_Data_SleepDateTime(P2VAR(sint64, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_tiSR_Rte_Read_Sd_RTC_Data_UtcTime(P2VAR(sint64, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_tiSR_VIN_Element(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Common_Normal_tiSR_VIN_Element(P2VAR(A_17Bytes, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_Sd_Cluster_Shutdown_Status_Element(uint8 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_Sd_Fuel_Status_Fuel_Status(uint8 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_ppSR_SWCNormal_DrvModStatusRecord_Element(P2CONST(DM_tstDrvModStatusRecord, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_ppSR_SWCNormal_Fuel_Set_Module_Data_Element(P2CONST(FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_ppSR_SWCNormal_MenuSetData_Element(P2CONST(MenuSetData_t, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_ppSR_SWCNormal_OdoParament_Element(P2CONST(s_OdoRteGetParament_t, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_ppSR_SWCNormal_SpeedoInfo_Element(P2CONST(s_SpeedoInfo_t, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_ppSR_SWCNormal_TC_Module_Output_Data_Element(P2CONST(TC_MODULE_OUTPUT_DATA_STRUCT_RTE, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_ppSR_SWCNormal_TC_NE_ChargStsOutput_Element(P2CONST(TC_NE_ChargStsOutput, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_ppSR_SWCNormal_TachoInfo_Element(P2CONST(s_TachoInfo_t, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Common_Normal_ppSR_SWCNormal_WarningStsOutput_Element(P2CONST(WN_WarningStsOutput, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_CanFrameCounter_Can_ABS3_Counter(P2VAR(CanFrameCounterType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) counter); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_CanFrameCounter_Can_ECM2_Counter(P2VAR(CanFrameCounterType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) counter); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter(P2VAR(CanFrameCounterType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) counter); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus(Dem_EventStatusType EventStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus(Dem_EventStatusType EventStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus(Dem_EventStatusType EventStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus(Dem_EventStatusType EventStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_HsmKeyM_GetAes128Key(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) IV, P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) KEY, P2VAR(uint32, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_HsmKeyM_GetAes128Key(P2VAR(A_17Bytes, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) IV, P2VAR(A_16Bytes, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) KEY, P2VAR(uint32, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_HsmKeyM_SetAes128Key(P2CONST(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) IV, P2CONST(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) KEY, uint32 key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_HsmKeyM_SetAes128Key(P2CONST(A_16Bytes, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) IV, P2CONST(A_16Bytes, AUTOMATIC, RTE_COMMON_NORMAL_APPL_DATA) KEY, uint32 key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_Hsm_Port_TrngGenerate(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Trng, P2VAR(uint32, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_Hsm_Port_TrngGenerate(P2VAR(A_16Bytes, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Trng, P2VAR(uint32, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_IRTC_Service_GetUTCTimeInMillis(P2VAR(uint64, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_IRTC_Service_UTC2PerpetualCalendar(sint64 utc, P2VAR(DateTimeType_t, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) date); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_IoHwAb_Interface_GetPin(uint8 Id, P2VAR(boolean, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Pin); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_IoHwAb_Interface_GetVoltage(uint8 Id, P2VAR(uint32, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_Os_Service_GetCounterValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_Os_Service_GetElapsedValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) ElapsedValue); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) kindConfig); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) updateTick); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) E2eStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_EraseBlock(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_InvalidateNvBlock(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_ReadBlock(dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_RestoreBlockDefaults(dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_EraseBlock(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_InvalidateNvBlock(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_ReadBlock(dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_RestoreBlockDefaults(dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_EraseBlock(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_InvalidateNvBlock(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_ReadBlock(dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_RestoreBlockDefaults(dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_EraseBlock(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_InvalidateNvBlock(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_ReadBlock(dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_RestoreBlockDefaults(dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_EraseBlock(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_InvalidateNvBlock(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_ReadBlock(dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_RestoreBlockDefaults(dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_EraseBlock(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_InvalidateNvBlock(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_ReadBlock(dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_RestoreBlockDefaults(dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_EraseBlock(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_InvalidateNvBlock(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_ReadBlock(dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_RestoreBlockDefaults(dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */


# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IRead_Common_Normal_100msMainFunction_tiSR_Power_Out_SystemStateOut() \
  (&Rte_FUEL_TC_ODO.Rte_RB.Rte_Common_Normal_Common_Normal_100msMainFunction.Rte_tiSR_Power_Out_SystemStateOut.value)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IStatus_Common_Normal_100msMainFunction_tiSR_Power_Out_SystemStateOut() \
  (Rte_FUEL_TC_ODO.Rte_RB.Rte_Common_Normal_Common_Normal_100msMainFunction.Rte_tiSR_Power_Out_SystemStateOut.status)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut() \
  (&Rte_FUEL_TC_ODO.Rte_RB.Rte_Common_Normal_Common_Normal_10msMainFunction.Rte_tiSR_Power_Out_SystemStateOut.value)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IStatus_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut() \
  (Rte_FUEL_TC_ODO.Rte_RB.Rte_Common_Normal_Common_Normal_10msMainFunction.Rte_tiSR_Power_Out_SystemStateOut.status)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IRead_Common_Normal_20msMainFunction_tiSR_Power_Out_SystemStateOut() \
  (&Rte_FUEL_TC_ODO.Rte_RB.Rte_Common_Normal_Common_Normal_20msMainFunction.Rte_tiSR_Power_Out_SystemStateOut.value)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IStatus_Common_Normal_20msMainFunction_tiSR_Power_Out_SystemStateOut() \
  (Rte_FUEL_TC_ODO.Rte_RB.Rte_Common_Normal_Common_Normal_20msMainFunction.Rte_tiSR_Power_Out_SystemStateOut.status)
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_ACAmbTemp_ACAmbTemp Rte_Read_Common_Normal_ACAmbTemp_ACAmbTemp
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_ACAmbTemp_ACAmbTemp(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_APS_FLSideSnsrFailSts_APS_FLSideSnsrFailSts Rte_Read_Common_Normal_APS_FLSideSnsrFailSts_APS_FLSideSnsrFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_APS_FLSideSnsrFailSts_APS_FLSideSnsrFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_APS_FRSideSnsrFailSts_APS_FRSideSnsrFailSts Rte_Read_Common_Normal_APS_FRSideSnsrFailSts_APS_FRSideSnsrFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_APS_FRSideSnsrFailSts_APS_FRSideSnsrFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_APS_RLSideSnsrFailSts_APS_RLSideSnsrFailSts Rte_Read_Common_Normal_APS_RLSideSnsrFailSts_APS_RLSideSnsrFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_APS_RLSideSnsrFailSts_APS_RLSideSnsrFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_APS_RRSideSnsrFailSts_APS_RRSideSnsrFailSts Rte_Read_Common_Normal_APS_RRSideSnsrFailSts_APS_RRSideSnsrFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_APS_RRSideSnsrFailSts_APS_RRSideSnsrFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_APS_SysSoundIndcn_APS_SysSoundIndcn Rte_Read_Common_Normal_APS_SysSoundIndcn_APS_SysSoundIndcn
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_APS_SysSoundIndcn_APS_SysSoundIndcn(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_APS_WorkSts_APS_WorkSts Rte_Read_Common_Normal_APS_WorkSts_APS_WorkSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_APS_WorkSts_APS_WorkSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_AVASDTCResults_AVASDTC Rte_Read_Common_Normal_AVASDTCResults_AVASDTC
#  define Rte_Read_AccelPedalPosnVldty_AccelPedalPosnVldty Rte_Read_Common_Normal_AccelPedalPosnVldty_AccelPedalPosnVldty
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_AccelPedalPosnVldty_AccelPedalPosnVldty(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_AccelPedlPosnDiagc_AccelPedlPosnDiagc Rte_Read_Common_Normal_AccelPedlPosnDiagc_AccelPedlPosnDiagc
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_AccelPedlPosnDiagc_AccelPedlPosnDiagc(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_AutoLmpSwtSts_AutoLmpSwtSts Rte_Read_Common_Normal_AutoLmpSwtSts_AutoLmpSwtSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_AutoLmpSwtSts_AutoLmpSwtSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_BMS_BattHeatRunaway_BMS_BattHeatRunaway Rte_Read_Common_Normal_BMS_BattHeatRunaway_BMS_BattHeatRunaway
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_BMS_BattHeatRunaway_BMS_BattHeatRunaway(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_BMS_BattKeepTempSts_BMS_BattKeepTempSts Rte_Read_Common_Normal_BMS_BattKeepTempSts_BMS_BattKeepTempSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_BMS_BattKeepTempSts_BMS_BattKeepTempSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_BMS_BattSOC_BMS_BattSOC Rte_Read_Common_Normal_BMS_BattSOC_BMS_BattSOC
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_BMS_BattSOC_BMS_BattSOC(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_BMS_ChrgDurationTime_BMS_ChrgDurationTime Rte_Read_Common_Normal_BMS_ChrgDurationTime_BMS_ChrgDurationTime
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_BMS_ChrgDurationTime_BMS_ChrgDurationTime(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_BMS_IntelEngIdlChrgnSts_BMS_IntelEngIdlChrgnSts Rte_Read_Common_Normal_BMS_IntelEngIdlChrgnSts_BMS_IntelEngIdlChrgnSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_BMS_IntelEngIdlChrgnSts_BMS_IntelEngIdlChrgnSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_BMS_SOCLowWarn_BMS_SOCLowWarn Rte_Read_Common_Normal_BMS_SOCLowWarn_BMS_SOCLowWarn
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_BMS_SOCLowWarn_BMS_SOCLowWarn(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_BSD_LCA_warningReqRight_BSD_LCA_warningReqRight Rte_Read_Common_Normal_BSD_LCA_warningReqRight_BSD_LCA_warningReqRight
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_BSD_LCA_warningReqRight_BSD_LCA_warningReqRight(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_BSD_LCA_warningReqleft_BSD_LCA_warningReqleft Rte_Read_Common_Normal_BSD_LCA_warningReqleft_BSD_LCA_warningReqleft
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_BSD_LCA_warningReqleft_BSD_LCA_warningReqleft(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_BrkPedalSts_BCM_BrkPedalSts_BCM Rte_Read_Common_Normal_BrkPedalSts_BCM_BrkPedalSts_BCM
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_BrkPedalSts_BCM_BrkPedalSts_BCM(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_CCO_Active_CCO_Active Rte_Read_Common_Normal_CCO_Active_CCO_Active
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_CCO_Active_CCO_Active(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_CCO_TgtVel_CCO_TgtVel Rte_Read_Common_Normal_CCO_TgtVel_CCO_TgtVel
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_CCO_TgtVel_CCO_TgtVel(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_CCO_Warn_CCO_Warn Rte_Read_Common_Normal_CCO_Warn_CCO_Warn
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_CCO_Warn_CCO_Warn(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_CR_BliSts_CR_BliSts Rte_Read_Common_Normal_CR_BliSts_CR_BliSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_CR_BliSts_CR_BliSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes Rte_Read_Common_Normal_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes
#  define Rte_Read_CouplingThermWarning_CouplingThermWarning Rte_Read_Common_Normal_CouplingThermWarning_CouplingThermWarning
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_CouplingThermWarning_CouplingThermWarning(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_CruiseCtrlSts_CruiseCtrlSts Rte_Read_Common_Normal_CruiseCtrlSts_CruiseCtrlSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_CruiseCtrlSts_CruiseCtrlSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_CruiseCtrlSts_PHEV_CruiseCtrlSts_PHEV Rte_Read_Common_Normal_CruiseCtrlSts_PHEV_CruiseCtrlSts_PHEV
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_CruiseCtrlSts_PHEV_CruiseCtrlSts_PHEV(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_DCT3_TgtEngSpdIP_TgtEngSpdIP Rte_Read_Common_Normal_DCT3_TgtEngSpdIP_TgtEngSpdIP
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_DCT3_TgtEngSpdIP_TgtEngSpdIP(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_DCT3_TgtEngSpdIPValid_TgtEngSpdIPValid Rte_Read_Common_Normal_DCT3_TgtEngSpdIPValid_TgtEngSpdIPValid
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_DCT3_TgtEngSpdIPValid_TgtEngSpdIPValid(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_DMSProc_DMSProc Rte_Read_Common_Normal_DMSProc_DMSProc
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_DMSProc_DMSProc(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_DMSProcResult_DMSProcResult Rte_Read_Common_Normal_DMSProcResult_DMSProcResult
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_DMSProcResult_DMSProcResult(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_DMSProcSts_DMSProcSts Rte_Read_Common_Normal_DMSProcSts_DMSProcSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_DMSProcSts_DMSProcSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_DOW_warningReqRight_DOW_warningReqRight Rte_Read_Common_Normal_DOW_warningReqRight_DOW_warningReqRight
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_DOW_warningReqRight_DOW_warningReqRight(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_DOW_warningReqleft_DOW_warningReqleft Rte_Read_Common_Normal_DOW_warningReqleft_DOW_warningReqleft
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_DOW_warningReqleft_DOW_warningReqleft(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_DiagLmpReq_DiagLmpReq Rte_Read_Common_Normal_DiagLmpReq_DiagLmpReq
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_DiagLmpReq_DiagLmpReq(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_DistrctnLvl_DistrctnLvl Rte_Read_Common_Normal_DistrctnLvl_DistrctnLvl
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_DistrctnLvl_DistrctnLvl(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_DrowsnsLvl_DrowsnsLvl Rte_Read_Common_Normal_DrowsnsLvl_DrowsnsLvl
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_DrowsnsLvl_DrowsnsLvl(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_DrowsyDrvDetWarn_DrowsyDrvDetWarn Rte_Read_Common_Normal_DrowsyDrvDetWarn_DrowsyDrvDetWarn
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_DrowsyDrvDetWarn_DrowsyDrvDetWarn(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_DrvDoorSts_DrvDoorSts Rte_Read_Common_Normal_DrvDoorSts_DrvDoorSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_DrvDoorSts_DrvDoorSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_Dyn_PwrSv_Lvl_Dyn_PwrSv_Lvl Rte_Read_Common_Normal_Dyn_PwrSv_Lvl_Dyn_PwrSv_Lvl
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_Dyn_PwrSv_Lvl_Dyn_PwrSv_Lvl(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_ECM11_EngSpd_ForIP_EngSpd_ForIP Rte_Read_Common_Normal_ECM11_EngSpd_ForIP_EngSpd_ForIP
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_ECM11_EngSpd_ForIP_EngSpd_ForIP(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_ECM1_EngSpdVldty_EngSpdVldty Rte_Read_Common_Normal_ECM1_EngSpdVldty_EngSpdVldty
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_ECM1_EngSpdVldty_EngSpdVldty(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_ECM_VIN_ECM19_0x3B5 Rte_Read_Common_Normal_ECM_VIN_ECM19_0x3B5
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_ECM_VIN_ECM19_0x3B5(data) ( \
    Rte_MemCpy(data, Rte_C_ECM_VIN_0, sizeof(ECM_VIN)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_ECM_VehDstBackup_ECM_VehDstBackup Rte_Read_Common_Normal_ECM_VehDstBackup_ECM_VehDstBackup
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_ECM_VehDstBackup_ECM_VehDstBackup(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_EMS_AuthenResult_EMS_AuthenResult Rte_Read_Common_Normal_EMS_AuthenResult_EMS_AuthenResult
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_EMS_AuthenResult_EMS_AuthenResult(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_ESP_HMI_WarningOn_ESP_HMI_WarningOn Rte_Read_Common_Normal_ESP_HMI_WarningOn_ESP_HMI_WarningOn
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_ESP_HMI_WarningOn_ESP_HMI_WarningOn(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_EWP_Err_EWP_Err Rte_Read_Common_Normal_EWP_Err_EWP_Err
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_EWP_Err_EWP_Err(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_EngClntTempVldty_EngClntTempVldty Rte_Read_Common_Normal_EngClntTempVldty_EngClntTempVldty
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_EngClntTempVldty_EngClntTempVldty(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_EngClntTempWarn_EngClntTempWarn Rte_Read_Common_Normal_EngClntTempWarn_EngClntTempWarn
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_EngClntTempWarn_EngClntTempWarn(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_EngCoolantTemp_EngCoolantTemp Rte_Read_Common_Normal_EngCoolantTemp_EngCoolantTemp
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_EngCoolantTemp_EngCoolantTemp(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_EngSVSSig_EngSVSSig Rte_Read_Common_Normal_EngSVSSig_EngSVSSig
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_EngSVSSig_EngSVSSig(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_EngSpdVldty_EngSpdVldty Rte_Read_Common_Normal_EngSpdVldty_EngSpdVldty
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_EngSpdVldty_EngSpdVldty(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_EngSpd_ForIP_EngSpd_ForIP Rte_Read_Common_Normal_EngSpd_ForIP_EngSpd_ForIP
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_EngSpd_ForIP_EngSpd_ForIP(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_EspFuncOffSts_mode_EspFuncOffSts_mode Rte_Read_Common_Normal_EspFuncOffSts_mode_EspFuncOffSts_mode
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_EspFuncOffSts_mode_EspFuncOffSts_mode(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FCTA_B_FuncSts_FCTA_B_FuncSts Rte_Read_Common_Normal_FCTA_B_FuncSts_FCTA_B_FuncSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FCTA_B_FuncSts_FCTA_B_FuncSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FCTA_Warn_FCTA_Warn Rte_Read_Common_Normal_FCTA_Warn_FCTA_Warn
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FCTA_Warn_FCTA_Warn(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FCTBTrig_FCTBTrig Rte_Read_Common_Normal_FCTBTrig_FCTBTrig
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FCTBTrig_FCTBTrig(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FFogLmpSts_F_Pbox_FFogLmpSts_F_Pbox Rte_Read_Common_Normal_FFogLmpSts_F_Pbox_FFogLmpSts_F_Pbox
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FFogLmpSts_F_Pbox_FFogLmpSts_F_Pbox(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FLTirePress_FLTirePress Rte_Read_Common_Normal_FLTirePress_FLTirePress
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FLTirePress_FLTirePress(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FLTirePressIndSts_FLTirePressIndSts Rte_Read_Common_Normal_FLTirePressIndSts_FLTirePressIndSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FLTirePressIndSts_FLTirePressIndSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FLTireTemp_FLTireTemp Rte_Read_Common_Normal_FLTireTemp_FLTireTemp
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FLTireTemp_FLTireTemp(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FLTireTempSts_FLTireTempSts Rte_Read_Common_Normal_FLTireTempSts_FLTireTempSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FLTireTempSts_FLTireTempSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FPAS_SoundIndcn_FPAS_SoundIndcn Rte_Read_Common_Normal_FPAS_SoundIndcn_FPAS_SoundIndcn
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FPAS_SoundIndcn_FPAS_SoundIndcn(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FPAS_SoundIndcn_FD_FPAS_SoundIndcn_FD Rte_Read_Common_Normal_FPAS_SoundIndcn_FD_FPAS_SoundIndcn_FD
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FPAS_SoundIndcn_FD_FPAS_SoundIndcn_FD(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FPAS_WorkSts_FPAS_WorkSts Rte_Read_Common_Normal_FPAS_WorkSts_FPAS_WorkSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FPAS_WorkSts_FPAS_WorkSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FPAS_WorkSts_FD_FPAS_WorkSts_FD Rte_Read_Common_Normal_FPAS_WorkSts_FD_FPAS_WorkSts_FD
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FPAS_WorkSts_FD_FPAS_WorkSts_FD(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FRTirePress_FRTirePress Rte_Read_Common_Normal_FRTirePress_FRTirePress
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FRTirePress_FRTirePress(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FRTirePressIndSts_FRTirePressIndSts Rte_Read_Common_Normal_FRTirePressIndSts_FRTirePressIndSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FRTirePressIndSts_FRTirePressIndSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FRTireTemp_FRTireTemp Rte_Read_Common_Normal_FRTireTemp_FRTireTemp
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FRTireTemp_FRTireTemp(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FRTireTempSts_FRTireTempSts Rte_Read_Common_Normal_FRTireTempSts_FRTireTempSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FRTireTempSts_FRTireTempSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FTIVFault_FTIVFault Rte_Read_Common_Normal_FTIVFault_FTIVFault
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FTIVFault_FTIVFault(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FuelConsumption_FuelConsumption Rte_Read_Common_Normal_FuelConsumption_FuelConsumption
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FuelConsumption_FuelConsumption(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_FuelTankCapWarning_FuelTankCapWarning Rte_Read_Common_Normal_FuelTankCapWarning_FuelTankCapWarning
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_FuelTankCapWarning_FuelTankCapWarning(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_GPF_Warning_GPF_Warning Rte_Read_Common_Normal_GPF_Warning_GPF_Warning
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_GPF_Warning_GPF_Warning(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_GentrWarnLmpSts_GentrWarnLmpSts Rte_Read_Common_Normal_GentrWarnLmpSts_GentrWarnLmpSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_GentrWarnLmpSts_GentrWarnLmpSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCUImmoAuthRes_HCUImmoAuthRes Rte_Read_Common_Normal_HCUImmoAuthRes_HCUImmoAuthRes
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCUImmoAuthRes_HCUImmoAuthRes(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_ACLineDisconnect_HCU_ACLineDisconnect Rte_Read_Common_Normal_HCU_ACLineDisconnect_HCU_ACLineDisconnect
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_ACLineDisconnect_HCU_ACLineDisconnect(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_AccelPedalPosn_Diag_HCU_AccelPedalPosn_Diag Rte_Read_Common_Normal_HCU_AccelPedalPosn_Diag_HCU_AccelPedalPosn_Diag
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_AccelPedalPosn_Diag_HCU_AccelPedalPosn_Diag(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_AccelPedalPosn_DiagValid_HCU_AccelPedalPosn_DiagValid Rte_Read_Common_Normal_HCU_AccelPedalPosn_DiagValid_HCU_AccelPedalPosn_DiagValid
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_AccelPedalPosn_DiagValid_HCU_AccelPedalPosn_DiagValid(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_AvailPower_TM_HCU_AvailPower_TM Rte_Read_Common_Normal_HCU_AvailPower_TM_HCU_AvailPower_TM
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_AvailPower_TM_HCU_AvailPower_TM(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_BattLowHeatSts_HCU_BattLowHeatSts Rte_Read_Common_Normal_HCU_BattLowHeatSts_HCU_BattLowHeatSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_BattLowHeatSts_HCU_BattLowHeatSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_BattLowTemWarn_HCU_BattLowTemWarn Rte_Read_Common_Normal_HCU_BattLowTemWarn_HCU_BattLowTemWarn
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_BattLowTemWarn_HCU_BattLowTemWarn(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_ChargSts_HCU_ChargSts Rte_Read_Common_Normal_HCU_ChargSts_HCU_ChargSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_ChargSts_HCU_ChargSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_ChrgSysErr_1_HCU_ChrgSysErr_1 Rte_Read_Common_Normal_HCU_ChrgSysErr_1_HCU_ChrgSysErr_1
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_ChrgSysErr_1_HCU_ChrgSysErr_1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_ChrgSysErr_2_HCU_ChrgSysErr_2 Rte_Read_Common_Normal_HCU_ChrgSysErr_2_HCU_ChrgSysErr_2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_ChrgSysErr_2_HCU_ChrgSysErr_2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_ChrgSysErr_3_HCU_ChrgSysErr_3 Rte_Read_Common_Normal_HCU_ChrgSysErr_3_HCU_ChrgSysErr_3
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_ChrgSysErr_3_HCU_ChrgSysErr_3(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_ChrgSysErr_4_HCU_ChrgSysErr_4 Rte_Read_Common_Normal_HCU_ChrgSysErr_4_HCU_ChrgSysErr_4
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_ChrgSysErr_4_HCU_ChrgSysErr_4(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_ChrgSysErr_5_HCU_ChrgSysErr_5 Rte_Read_Common_Normal_HCU_ChrgSysErr_5_HCU_ChrgSysErr_5
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_ChrgSysErr_5_HCU_ChrgSysErr_5(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_ChrgSysErr_6_HCU_ChrgSysErr_6 Rte_Read_Common_Normal_HCU_ChrgSysErr_6_HCU_ChrgSysErr_6
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_ChrgSysErr_6_HCU_ChrgSysErr_6(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_ChrgSysErr_7_HCU_ChrgSysErr_7 Rte_Read_Common_Normal_HCU_ChrgSysErr_7_HCU_ChrgSysErr_7
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_ChrgSysErr_7_HCU_ChrgSysErr_7(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_ChrgSysErr_8_HCU_ChrgSysErr_8 Rte_Read_Common_Normal_HCU_ChrgSysErr_8_HCU_ChrgSysErr_8
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_ChrgSysErr_8_HCU_ChrgSysErr_8(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_ChrgSysLmpSts_HCU_ChrgSysLmpSts Rte_Read_Common_Normal_HCU_ChrgSysLmpSts_HCU_ChrgSysLmpSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_ChrgSysLmpSts_HCU_ChrgSysLmpSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_DrvMod_HCU_DrvMod Rte_Read_Common_Normal_HCU_DrvMod_HCU_DrvMod
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_DrvMod_HCU_DrvMod(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_ECODrvHabit_Indcn_HCU_ECODrvHabit_Indcn Rte_Read_Common_Normal_HCU_ECODrvHabit_Indcn_HCU_ECODrvHabit_Indcn
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_ECODrvHabit_Indcn_HCU_ECODrvHabit_Indcn(data) (*(data) = 100U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_EVContnsDistance_HCU_EVContnsDistance Rte_Read_Common_Normal_HCU_EVContnsDistance_HCU_EVContnsDistance
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_EVContnsDistance_HCU_EVContnsDistance(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_EVContnsDistanceVld_HCU_EVContnsDistanceVld Rte_Read_Common_Normal_HCU_EVContnsDistanceVld_HCU_EVContnsDistanceVld
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_EVContnsDistanceVld_HCU_EVContnsDistanceVld(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_EVLmpSts_HCU_EVLmpSts Rte_Read_Common_Normal_HCU_EVLmpSts_HCU_EVLmpSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_EVLmpSts_HCU_EVLmpSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_EgyUsed_HCU_EgyUsed Rte_Read_Common_Normal_HCU_EgyUsed_HCU_EgyUsed
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_EgyUsed_HCU_EgyUsed(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_IntelBattTempMagSts_HCU_IntelBattTempMagSts Rte_Read_Common_Normal_HCU_IntelBattTempMagSts_HCU_IntelBattTempMagSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_IntelBattTempMagSts_HCU_IntelBattTempMagSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_RaceLaunchAvail_HCU_RaceLaunchAvail Rte_Read_Common_Normal_HCU_RaceLaunchAvail_HCU_RaceLaunchAvail
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_RaceLaunchAvail_HCU_RaceLaunchAvail(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_RaceLaunchSts_HCU_RaceLaunchSts Rte_Read_Common_Normal_HCU_RaceLaunchSts_HCU_RaceLaunchSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_RaceLaunchSts_HCU_RaceLaunchSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_RecupPwr_HCU_RecupPwr Rte_Read_Common_Normal_HCU_RecupPwr_HCU_RecupPwr
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_RecupPwr_HCU_RecupPwr(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_TotDrvReqPower_HCU_TotDrvReqPower Rte_Read_Common_Normal_HCU_TotDrvReqPower_HCU_TotDrvReqPower
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_TotDrvReqPower_HCU_TotDrvReqPower(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HCU_WorkshopMode_HCU_WorkshopMode Rte_Read_Common_Normal_HCU_WorkshopMode_HCU_WorkshopMode
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HCU_WorkshopMode_HCU_WorkshopMode(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HiBeamSts_F_Pbox_HiBeamSts_F_Pbox Rte_Read_Common_Normal_HiBeamSts_F_Pbox_HiBeamSts_F_Pbox
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HiBeamSts_F_Pbox_HiBeamSts_F_Pbox(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HiLowBeamSts_HiLowBeamSts Rte_Read_Common_Normal_HiLowBeamSts_HiLowBeamSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HiLowBeamSts_HiLowBeamSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HiPosnBrkLmpFailSts_HiPosnBrkLmpFailSts Rte_Read_Common_Normal_HiPosnBrkLmpFailSts_HiPosnBrkLmpFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HiPosnBrkLmpFailSts_HiPosnBrkLmpFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_HoodSts_F_Pbox_HoodSts_F_Pbox Rte_Read_Common_Normal_HoodSts_F_Pbox_HoodSts_F_Pbox
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_HoodSts_F_Pbox_HoodSts_F_Pbox(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_IB_Warn_IB_Warn Rte_Read_Common_Normal_IB_Warn_IB_Warn
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_IB_Warn_IB_Warn(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_KL30BRelaySts_KL30BRelaySts Rte_Read_Common_Normal_KL30BRelaySts_KL30BRelaySts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_KL30BRelaySts_KL30BRelaySts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_LADBstatus_LADBstatus Rte_Read_Common_Normal_LADBstatus_LADBstatus
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_LADBstatus_LADBstatus(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_LBrkLmpFailSts_LBrkLmpFailSts Rte_Read_Common_Normal_LBrkLmpFailSts_LBrkLmpFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_LBrkLmpFailSts_LBrkLmpFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_LHeadLmpFailSts_LHeadLmpFailSts Rte_Read_Common_Normal_LHeadLmpFailSts_LHeadLmpFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_LHeadLmpFailSts_LHeadLmpFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_LHiBeamFailSts_LHiBeamFailSts Rte_Read_Common_Normal_LHiBeamFailSts_LHiBeamFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_LHiBeamFailSts_LHiBeamFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_LHiBeamSts_LHiBeamSts Rte_Read_Common_Normal_LHiBeamSts_LHiBeamSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_LHiBeamSts_LHiBeamSts(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_LLasHdLmpDiagSig_LLasHdLmpDiagSig Rte_Read_Common_Normal_LLasHdLmpDiagSig_LLasHdLmpDiagSig
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_LLasHdLmpDiagSig_LLasHdLmpDiagSig(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_LLowBeamFailSts_LLowBeamFailSts Rte_Read_Common_Normal_LLowBeamFailSts_LLowBeamFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_LLowBeamFailSts_LLowBeamFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_LRDoorSts_LRDoorSts Rte_Read_Common_Normal_LRDoorSts_LRDoorSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_LRDoorSts_LRDoorSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_LRPosnLmpFailSts_LRPosnLmpFailSts Rte_Read_Common_Normal_LRPosnLmpFailSts_LRPosnLmpFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_LRPosnLmpFailSts_LRPosnLmpFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_LTurnLmpSts_R_Pbox_LTurnLmpSts_R_Pbox Rte_Read_Common_Normal_LTurnLmpSts_R_Pbox_LTurnLmpSts_R_Pbox
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_LTurnLmpSts_R_Pbox_LTurnLmpSts_R_Pbox(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_LasHdLmpSts_F_Pbox_LasHdLmpSts_F_Pbox Rte_Read_Common_Normal_LasHdLmpSts_F_Pbox_LasHdLmpSts_F_Pbox
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_LasHdLmpSts_F_Pbox_LasHdLmpSts_F_Pbox(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_LicPlateLmpFailSts_LicPlateLmpFailSts Rte_Read_Common_Normal_LicPlateLmpFailSts_LicPlateLmpFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_LicPlateLmpFailSts_LicPlateLmpFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_LvPwrSysErr_LvPwrSysErr Rte_Read_Common_Normal_LvPwrSysErr_LvPwrSysErr
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_LvPwrSysErr_LvPwrSysErr(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_MILSts_MILSts Rte_Read_Common_Normal_MILSts_MILSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_MILSts_MILSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_OBC_ConnectSts_OBC_ConnectSts Rte_Read_Common_Normal_OBC_ConnectSts_OBC_ConnectSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_OBC_ConnectSts_OBC_ConnectSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_PASWorkCmd_PASWorkCmd Rte_Read_Common_Normal_PASWorkCmd_PASWorkCmd
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_PASWorkCmd_PASWorkCmd(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_ParkLmpSts_R_Pbox_ParkLmpSts_R_Pbox Rte_Read_Common_Normal_ParkLmpSts_R_Pbox_ParkLmpSts_R_Pbox
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_ParkLmpSts_R_Pbox_ParkLmpSts_R_Pbox(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_PassengerDoorSts_PassengerDoorSts Rte_Read_Common_Normal_PassengerDoorSts_PassengerDoorSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_PassengerDoorSts_PassengerDoorSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_PosnLmpOutpSts_R_Pbox_PosnLmpOutpSts_R_Pbox Rte_Read_Common_Normal_PosnLmpOutpSts_R_Pbox_PosnLmpOutpSts_R_Pbox
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_PosnLmpOutpSts_R_Pbox_PosnLmpOutpSts_R_Pbox(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_PowerRlyFault_PowerRlyFault Rte_Read_Common_Normal_PowerRlyFault_PowerRlyFault
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_PowerRlyFault_PowerRlyFault(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_PressReliProgs_PressReliProgs Rte_Read_Common_Normal_PressReliProgs_PressReliProgs
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_PressReliProgs_PressReliProgs(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RADBstatus_RADBstatus Rte_Read_Common_Normal_RADBstatus_RADBstatus
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RADBstatus_RADBstatus(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RBrkLmpFailSts_RBrkLmpFailSts Rte_Read_Common_Normal_RBrkLmpFailSts_RBrkLmpFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RBrkLmpFailSts_RBrkLmpFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RCTA_warningReqLeft_RCTA_warningReqLeft Rte_Read_Common_Normal_RCTA_warningReqLeft_RCTA_warningReqLeft
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RCTA_warningReqLeft_RCTA_warningReqLeft(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RCTA_warningReqRight_RCTA_warningReqRight Rte_Read_Common_Normal_RCTA_warningReqRight_RCTA_warningReqRight
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RCTA_warningReqRight_RCTA_warningReqRight(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RFogLmpFailSts_R_Pbox_RFogLmpFailSts_R_Pbox Rte_Read_Common_Normal_RFogLmpFailSts_R_Pbox_RFogLmpFailSts_R_Pbox
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RFogLmpFailSts_R_Pbox_RFogLmpFailSts_R_Pbox(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RFogLmpSts_R_Pbox_RFogLmpSts_R_Pbox Rte_Read_Common_Normal_RFogLmpSts_R_Pbox_RFogLmpSts_R_Pbox
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RFogLmpSts_R_Pbox_RFogLmpSts_R_Pbox(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RHeadLmpFailSts_RHeadLmpFailSts Rte_Read_Common_Normal_RHeadLmpFailSts_RHeadLmpFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RHeadLmpFailSts_RHeadLmpFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RHiBeamFailSts_RHiBeamFailSts Rte_Read_Common_Normal_RHiBeamFailSts_RHiBeamFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RHiBeamFailSts_RHiBeamFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RHiBeamSts_RHiBeamSts Rte_Read_Common_Normal_RHiBeamSts_RHiBeamSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RHiBeamSts_RHiBeamSts(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RLSFailSts_RLSFailSts Rte_Read_Common_Normal_RLSFailSts_RLSFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RLSFailSts_RLSFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RLTirePress_RLTirePress Rte_Read_Common_Normal_RLTirePress_RLTirePress
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RLTirePress_RLTirePress(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RLTirePressIndSts_RLTirePressIndSts Rte_Read_Common_Normal_RLTirePressIndSts_RLTirePressIndSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RLTirePressIndSts_RLTirePressIndSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RLTireTemp_RLTireTemp Rte_Read_Common_Normal_RLTireTemp_RLTireTemp
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RLTireTemp_RLTireTemp(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RLTireTempSts_RLTireTempSts Rte_Read_Common_Normal_RLTireTempSts_RLTireTempSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RLTireTempSts_RLTireTempSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RLasHdLmpDiagSig_RLasHdLmpDiagSig Rte_Read_Common_Normal_RLasHdLmpDiagSig_RLasHdLmpDiagSig
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RLasHdLmpDiagSig_RLasHdLmpDiagSig(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RLowBeamFailSts_RLowBeamFailSts Rte_Read_Common_Normal_RLowBeamFailSts_RLowBeamFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RLowBeamFailSts_RLowBeamFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RPAS_SoundIndcn_RPAS_SoundIndcn Rte_Read_Common_Normal_RPAS_SoundIndcn_RPAS_SoundIndcn
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RPAS_SoundIndcn_RPAS_SoundIndcn(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RPAS_SoundIndcn_FD_RPAS_SoundIndcn_FD Rte_Read_Common_Normal_RPAS_SoundIndcn_FD_RPAS_SoundIndcn_FD
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RPAS_SoundIndcn_FD_RPAS_SoundIndcn_FD(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RPAS_WorkSts_RPAS_WorkSts Rte_Read_Common_Normal_RPAS_WorkSts_RPAS_WorkSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RPAS_WorkSts_RPAS_WorkSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RPAS_WorkSts_FD_RPAS_WorkSts_FD Rte_Read_Common_Normal_RPAS_WorkSts_FD_RPAS_WorkSts_FD
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RPAS_WorkSts_FD_RPAS_WorkSts_FD(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RRDoorSts_RRDoorSts Rte_Read_Common_Normal_RRDoorSts_RRDoorSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RRDoorSts_RRDoorSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RRPosnLmpFailSts_RRPosnLmpFailSts Rte_Read_Common_Normal_RRPosnLmpFailSts_RRPosnLmpFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RRPosnLmpFailSts_RRPosnLmpFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RRTirePress_RRTirePress Rte_Read_Common_Normal_RRTirePress_RRTirePress
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RRTirePress_RRTirePress(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RRTirePressIndSts_RRTirePressIndSts Rte_Read_Common_Normal_RRTirePressIndSts_RRTirePressIndSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RRTirePressIndSts_RRTirePressIndSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RRTireTemp_RRTireTemp Rte_Read_Common_Normal_RRTireTemp_RRTireTemp
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RRTireTemp_RRTireTemp(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RRTireTempSts_RRTireTempSts Rte_Read_Common_Normal_RRTireTempSts_RRTireTempSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RRTireTempSts_RRTireTempSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RSDS_BliSts_RSDS_BliSts Rte_Read_Common_Normal_RSDS_BliSts_RSDS_BliSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RSDS_BliSts_RSDS_BliSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RSDS_BrkgTrig_RSDS_BrkgTrig Rte_Read_Common_Normal_RSDS_BrkgTrig_RSDS_BrkgTrig
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RSDS_BrkgTrig_RSDS_BrkgTrig(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RSDS_CTA_Actv_RSDS_CTA_Actv Rte_Read_Common_Normal_RSDS_CTA_Actv_RSDS_CTA_Actv
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RSDS_CTA_Actv_RSDS_CTA_Actv(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RSDS_ErrSts_RSDS_ErrSts Rte_Read_Common_Normal_RSDS_ErrSts_RSDS_ErrSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RSDS_ErrSts_RSDS_ErrSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RSDS_IPSoundReq_RSDS_IPSoundReq Rte_Read_Common_Normal_RSDS_IPSoundReq_RSDS_IPSoundReq
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RSDS_IPSoundReq_RSDS_IPSoundReq(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RSDS_LCAResp_RSDS_LCAResp Rte_Read_Common_Normal_RSDS_LCAResp_RSDS_LCAResp
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RSDS_LCAResp_RSDS_LCAResp(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RSDS_RCW_Trigger_RSDS_RCW_Trigger Rte_Read_Common_Normal_RSDS_RCW_Trigger_RSDS_RCW_Trigger
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RSDS_RCW_Trigger_RSDS_RCW_Trigger(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RSDS_TrailerSts_RSDS_TrailerSts Rte_Read_Common_Normal_RSDS_TrailerSts_RSDS_TrailerSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RSDS_TrailerSts_RSDS_TrailerSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RTurnLmpSts_R_Pbox_RTurnLmpSts_R_Pbox Rte_Read_Common_Normal_RTurnLmpSts_R_Pbox_RTurnLmpSts_R_Pbox
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RTurnLmpSts_R_Pbox_RTurnLmpSts_R_Pbox(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_Rc_Cluster_Shutdown_Status_Element Rte_Read_Common_Normal_Rc_Cluster_Shutdown_Status_Element
#  define Rte_Read_Rc_Fuel_Status_Fuel_Status Rte_Read_Common_Normal_Rc_Fuel_Status_Fuel_Status
#  define Rte_Read_Rc_Odo_RunCounter_RunCounter Rte_Read_Common_Normal_Rc_Odo_RunCounter_RunCounter
#  define Rte_Read_Common_Normal_Rc_Odo_RunCounter_RunCounter(data) (*(data) = Rte_Common_Normal_Sd_Odo_RunCounter_RunCounter, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_SpeedoInfo_IndicateSpeed Rte_Read_Common_Normal_Rc_SpeedoInfo_IndicateSpeed
#  define Rte_Read_Common_Normal_Rc_SpeedoInfo_IndicateSpeed(data) (*(data) = Rte_Common_Normal_Sd_SpeedoInfo_IndicateSpeed, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_SpeedoInfo_OverSpdWrnFlg Rte_Read_Common_Normal_Rc_SpeedoInfo_OverSpdWrnFlg
#  define Rte_Read_Common_Normal_Rc_SpeedoInfo_OverSpdWrnFlg(data) (*(data) = Rte_Common_Normal_Sd_SpeedoInfo_OverSpdWrnFlg, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_SpeedoInfo_RealSpeed Rte_Read_Common_Normal_Rc_SpeedoInfo_RealSpeed
#  define Rte_Read_Common_Normal_Rc_SpeedoInfo_RealSpeed(data) (*(data) = Rte_Common_Normal_Sd_SpeedoInfo_RealSpeed, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_SpeedoInfo_VehRunSts Rte_Read_Common_Normal_Rc_SpeedoInfo_VehRunSts
#  define Rte_Read_Common_Normal_Rc_SpeedoInfo_VehRunSts(data) (*(data) = Rte_Common_Normal_Sd_SpeedoInfo_VehRunSts, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_TachoInfo_EngRunSts Rte_Read_Common_Normal_Rc_TachoInfo_EngRunSts
#  define Rte_Read_Common_Normal_Rc_TachoInfo_EngRunSts(data) (*(data) = Rte_Common_Normal_Sd_TachoInfo_EngRunSts, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_TachoInfo_EngSpd Rte_Read_Common_Normal_Rc_TachoInfo_EngSpd
#  define Rte_Read_Common_Normal_Rc_TachoInfo_EngSpd(data) (*(data) = Rte_Common_Normal_Sd_TachoInfo_EngSpd, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_RearELDLckSts_RearELDLckSts Rte_Read_Common_Normal_RearELDLckSts_RearELDLckSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RearELDLckSts_RearELDLckSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RemoteModSts_RemoteModSts Rte_Read_Common_Normal_RemoteModSts_RemoteModSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RemoteModSts_RemoteModSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RotSteerWheel_RotSteerWheel Rte_Read_Common_Normal_RotSteerWheel_RotSteerWheel
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RotSteerWheel_RotSteerWheel(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_RvsLmpFailSts_RvsLmpFailSts Rte_Read_Common_Normal_RvsLmpFailSts_RvsLmpFailSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_RvsLmpFailSts_RvsLmpFailSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SDWActiveSts_SDWActiveSts Rte_Read_Common_Normal_SDWActiveSts_SDWActiveSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SDWActiveSts_SDWActiveSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SDW_SoundIndcn_SDW_SoundIndcn Rte_Read_Common_Normal_SDW_SoundIndcn_SDW_SoundIndcn
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SDW_SoundIndcn_SDW_SoundIndcn(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ABM1_SG_ABM1 Rte_Read_Common_Normal_SG_ABM1_SG_ABM1
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_ABM1_SG_ABM1(data) (*(data) = Rte_C_SG_ABM1_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ABS3_SG_ABS3 Rte_Read_Common_Normal_SG_ABS3_SG_ABS3
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_ABS3_SG_ABS3(data) (*(data) = Rte_C_SG_ABS3_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2 Rte_Read_Common_Normal_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2(data) (*(data) = Rte_C_SG_ABS3_ESP_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2 Rte_Read_Common_Normal_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2(data) (*(data) = Rte_C_SG_ACC3_ACC_FD2_1, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2 Rte_Read_Common_Normal_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2(data) (*(data) = Rte_C_SG_ACC4_ACC_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2 Rte_Read_Common_Normal_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2(data) (*(data) = Rte_C_SG_ACC7_ACC_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2 Rte_Read_Common_Normal_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2(data) (*(data) = Rte_C_SG_ACC8_ACC_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2 Rte_Read_Common_Normal_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2(data) (*(data) = Rte_C_SG_AEB2_AEB_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2 Rte_Read_Common_Normal_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2(data) (*(data) = Rte_C_SG_AEB3_AEB_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_BMS4_SG_BMS4 Rte_Read_Common_Normal_SG_BMS4_SG_BMS4
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_BMS4_SG_BMS4(data) (*(data) = Rte_C_SG_BMS4_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_DCT7_SG_DCT7 Rte_Read_Common_Normal_SG_DCT7_SG_DCT7
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_DCT7_SG_DCT7(data) (*(data) = Rte_C_SG_DCT7_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_DHT_FD1_SG_DHT_FD1 Rte_Read_Common_Normal_SG_DHT_FD1_SG_DHT_FD1
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_DHT_FD1_SG_DHT_FD1(data) (*(data) = Rte_C_SG_DHT_FD1_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_EPB1_SG_EPB1 Rte_Read_Common_Normal_SG_EPB1_SG_EPB1
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_EPB1_SG_EPB1(data) (*(data) = Rte_C_SG_EPB1_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_EPS1_SG_EPS1 Rte_Read_Common_Normal_SG_EPS1_SG_EPS1
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_EPS1_SG_EPS1(data) (*(data) = Rte_C_SG_EPS1_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_EPS1_FD1_SG_EPS1_FD1 Rte_Read_Common_Normal_SG_EPS1_FD1_SG_EPS1_FD1
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_EPS1_FD1_SG_EPS1_FD1(data) (*(data) = Rte_C_SG_EPS1_FD1_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ESP2_SG_ESP2 Rte_Read_Common_Normal_SG_ESP2_SG_ESP2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_ESP2_SG_ESP2(data) (*(data) = Rte_C_SG_ESP2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2 Rte_Read_Common_Normal_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2(data) (*(data) = Rte_C_SG_ESP2_ESP_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_HC1_SG_HC1 Rte_Read_Common_Normal_SG_HC1_SG_HC1
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_HC1_SG_HC1(data) (*(data) = Rte_C_SG_HC1_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_HCU_HP5_SG_HCU_HP5 Rte_Read_Common_Normal_SG_HCU_HP5_SG_HCU_HP5
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_HCU_HP5_SG_HCU_HP5(data) (*(data) = Rte_C_SG_HCU_HP5_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_HCU_PT4_SG_HCU_PT4 Rte_Read_Common_Normal_SG_HCU_PT4_SG_HCU_PT4
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_HCU_PT4_SG_HCU_PT4(data) (*(data) = Rte_C_SG_HCU_PT4_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_HCU_PT7_SG_HCU_PT7 Rte_Read_Common_Normal_SG_HCU_PT7_SG_HCU_PT7
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_HCU_PT7_SG_HCU_PT7(data) (*(data) = Rte_C_SG_HCU_PT7_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_IFC3_IFC_FD2_SG_IFC3_IFC_FD2 Rte_Read_Common_Normal_SG_IFC3_IFC_FD2_SG_IFC3_IFC_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_IFC3_IFC_FD2_SG_IFC3_IFC_FD2(data) (*(data) = Rte_C_SG_IFC3_IFC_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2 Rte_Read_Common_Normal_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(data) (*(data) = Rte_C_SG_IFC4_IFC_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_IFC5_IFC_FD2_SG_IFC5_IFC_FD2 Rte_Read_Common_Normal_SG_IFC5_IFC_FD2_SG_IFC5_IFC_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_IFC5_IFC_FD2_SG_IFC5_IFC_FD2(data) (*(data) = Rte_C_SG_IFC5_IFC_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SG_IFC6_IFC_FD2_SG_IFC6_IFC_FD2 Rte_Read_Common_Normal_SG_IFC6_IFC_FD2_SG_IFC6_IFC_FD2
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SG_IFC6_IFC_FD2_SG_IFC6_IFC_FD2(data) (*(data) = Rte_C_SG_IFC6_IFC_FD2_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SS_Enable_Lamp_SS_Enable_Lamp Rte_Read_Common_Normal_SS_Enable_Lamp_SS_Enable_Lamp
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SS_Enable_Lamp_SS_Enable_Lamp(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SS_Fault_Lamp_SS_Fault_Lamp Rte_Read_Common_Normal_SS_Fault_Lamp_SS_Fault_Lamp
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SS_Fault_Lamp_SS_Fault_Lamp(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SS_Screen_tip_SS_Screen_tip Rte_Read_Common_Normal_SS_Screen_tip_SS_Screen_tip
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SS_Screen_tip_SS_Screen_tip(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SafetyCanOutputViaNormal_CheckSum_IP2 Rte_Read_Common_Normal_SafetyCanOutputViaNormal_CheckSum_IP2
#  define Rte_Read_Common_Normal_SafetyCanOutputViaNormal_CheckSum_IP2(data) (*(data) = Rte_Common_Safety_SafetyCanOutputViaNormal_CheckSum_IP2, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SafetyCanOutputViaNormal_IP_ABMWarnLmpFailrSts Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_ABMWarnLmpFailrSts
#  define Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_ABMWarnLmpFailrSts(data) (*(data) = Rte_Common_Safety_SafetyCanOutputViaNormal_IP_ABMWarnLmpFailrSts, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SafetyCanOutputViaNormal_IP_ACCErr Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_ACCErr
#  define Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_ACCErr(data) (*(data) = Rte_Common_Safety_SafetyCanOutputViaNormal_IP_ACCErr, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SafetyCanOutputViaNormal_IP_BattChrgLmpSts Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_BattChrgLmpSts
#  define Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_BattChrgLmpSts(data) (*(data) = Rte_Common_Safety_SafetyCanOutputViaNormal_IP_BattChrgLmpSts, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SafetyCanOutputViaNormal_IP_DrvSeatBeltWarnLmpFailSts Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_DrvSeatBeltWarnLmpFailSts
#  define Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_DrvSeatBeltWarnLmpFailSts(data) (*(data) = Rte_Common_Safety_SafetyCanOutputViaNormal_IP_DrvSeatBeltWarnLmpFailSts, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SafetyCanOutputViaNormal_IP_EngOilPressLowLmpSts Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_EngOilPressLowLmpSts
#  define Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_EngOilPressLowLmpSts(data) (*(data) = Rte_Common_Safety_SafetyCanOutputViaNormal_IP_EngOilPressLowLmpSts, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SafetyCanOutputViaNormal_IP_Err Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_Err
#  define Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_Err(data) (*(data) = Rte_Common_Safety_SafetyCanOutputViaNormal_IP_Err, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SafetyCanOutputViaNormal_IP_FuelLvlInfo Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_FuelLvlInfo
#  define Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_FuelLvlInfo(data) (*(data) = Rte_Common_Safety_SafetyCanOutputViaNormal_IP_FuelLvlInfo, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SafetyCanOutputViaNormal_IP_FuelLvlLowLmpSts Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_FuelLvlLowLmpSts
#  define Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_FuelLvlLowLmpSts(data) (*(data) = Rte_Common_Safety_SafetyCanOutputViaNormal_IP_FuelLvlLowLmpSts, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SafetyCanOutputViaNormal_IP_PassSeatBeltWarnLmpFailSts Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_PassSeatBeltWarnLmpFailSts
#  define Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_PassSeatBeltWarnLmpFailSts(data) (*(data) = Rte_Common_Safety_SafetyCanOutputViaNormal_IP_PassSeatBeltWarnLmpFailSts, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SafetyCanOutputViaNormal_IP_VINcompr Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_VINcompr
#  define Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_VINcompr(data) (*(data) = Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VINcompr, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SafetyCanOutputViaNormal_IP_VehSpdUnit Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_VehSpdUnit
#  define Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_VehSpdUnit(data) (*(data) = Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VehSpdUnit, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SafetyCanOutputViaNormal_IP_VehTotDistance Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_VehTotDistance
#  define Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_VehTotDistance(data) (*(data) = Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VehTotDistance, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SafetyCanOutputViaNormal_IP_VehTotDistanceValid Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_VehTotDistanceValid
#  define Rte_Read_Common_Normal_SafetyCanOutputViaNormal_IP_VehTotDistanceValid(data) (*(data) = Rte_Common_Safety_SafetyCanOutputViaNormal_IP_VehTotDistanceValid, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SafetyCanOutputViaNormal_RollingCounter_IP2 Rte_Read_Common_Normal_SafetyCanOutputViaNormal_RollingCounter_IP2
#  define Rte_Read_Common_Normal_SafetyCanOutputViaNormal_RollingCounter_IP2(data) (*(data) = Rte_Common_Safety_SafetyCanOutputViaNormal_RollingCounter_IP2, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SafetyCanOutputViaNormal_dummy_HUT_IP2_0 Rte_Read_Common_Normal_SafetyCanOutputViaNormal_dummy_HUT_IP2_0
#  define Rte_Read_Common_Normal_SafetyCanOutputViaNormal_dummy_HUT_IP2_0(data) (*(data) = Rte_Common_Safety_SafetyCanOutputViaNormal_dummy_HUT_IP2_0, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_SocReadyFlag_Element Rte_Read_Common_Normal_SocReadyFlag_Element
#  define Rte_Read_Common_Normal_SocReadyFlag_Element(data) (*(data) = Rte_Common_GateWay_SocReadyFlag_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Stat_PwrSv_Lvl_Stat_PwrSv_Lvl Rte_Read_Common_Normal_Stat_PwrSv_Lvl_Stat_PwrSv_Lvl
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_Stat_PwrSv_Lvl_Stat_PwrSv_Lvl(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_SysPowerMod_SysPowerMod Rte_Read_Common_Normal_SysPowerMod_SysPowerMod
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_SysPowerMod_SysPowerMod(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_TGS_LEVER_TGS_LEVER Rte_Read_Common_Normal_TGS_LEVER_TGS_LEVER
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_TGS_LEVER_TGS_LEVER(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_TSRSpdLim_TSRSpdLim Rte_Read_Common_Normal_TSRSpdLim_TSRSpdLim
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_TSRSpdLim_TSRSpdLim(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_TSRSpdLimCfdc_TSRSpdLimCfdc Rte_Read_Common_Normal_TSRSpdLimCfdc_TSRSpdLimCfdc
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_TSRSpdLimCfdc_TSRSpdLimCfdc(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_TSRSpdLimSts_TSRSpdLimSts Rte_Read_Common_Normal_TSRSpdLimSts_TSRSpdLimSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_TSRSpdLimSts_TSRSpdLimSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_TSRSpdLimWarn_TSRSpdLimWarn Rte_Read_Common_Normal_TSRSpdLimWarn_TSRSpdLimWarn
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_TSRSpdLimWarn_TSRSpdLimWarn(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_TSRSts_TSRSts Rte_Read_Common_Normal_TSRSts_TSRSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_TSRSts_TSRSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_TSRTrfcSignVal_TSRTrfcSignVal Rte_Read_Common_Normal_TSRTrfcSignVal_TSRTrfcSignVal
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_TSRTrfcSignVal_TSRTrfcSignVal(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_T_Box_SysErrSts_T_Box_SysErrSts Rte_Read_Common_Normal_T_Box_SysErrSts_T_Box_SysErrSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_T_Box_SysErrSts_T_Box_SysErrSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_TgtCrsVehSpd_TgtCrsVehSpd Rte_Read_Common_Normal_TgtCrsVehSpd_TgtCrsVehSpd
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_TgtCrsVehSpd_TgtCrsVehSpd(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_TgtRcprtnTrqSts_TgtRcprtnTrqSts Rte_Read_Common_Normal_TgtRcprtnTrqSts_TgtRcprtnTrqSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_TgtRcprtnTrqSts_TgtRcprtnTrqSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_TirePressSysFailrIndcn_TirePressSysFailrIndcn Rte_Read_Common_Normal_TirePressSysFailrIndcn_TirePressSysFailrIndcn
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_TirePressSysFailrIndcn_TirePressSysFailrIndcn(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_TrailerSts_TrailerSts Rte_Read_Common_Normal_TrailerSts_TrailerSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_TrailerSts_TrailerSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_TranPMode_Sts_TranPMode_Sts Rte_Read_Common_Normal_TranPMode_Sts_TranPMode_Sts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_TranPMode_Sts_TranPMode_Sts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_TrunkSts_TrunkSts Rte_Read_Common_Normal_TrunkSts_TrunkSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_TrunkSts_TrunkSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_VSG_HUTSoundResp_VSG_HUTSoundResp Rte_Read_Common_Normal_VSG_HUTSoundResp_VSG_HUTSoundResp
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_VSG_HUTSoundResp_VSG_HUTSoundResp(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_VSG_Sts_VSG_Sts Rte_Read_Common_Normal_VSG_Sts_VSG_Sts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_VSG_Sts_VSG_Sts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_Vconfig_GetKindBuffers_AllKinds Rte_Read_Common_Normal_Vconfig_GetKindBuffers_AllKinds
#  define Rte_Read_WPC_FaultSts_WPC_FaultSts Rte_Read_Common_Normal_WPC_FaultSts_WPC_FaultSts
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_WPC_FaultSts_WPC_FaultSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_WPC_PhoneReminder_WPC_PhoneReminder Rte_Read_Common_Normal_WPC_PhoneReminder_WPC_PhoneReminder
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_WPC_PhoneReminder_WPC_PhoneReminder(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_WarnEngStrtNotMeet_WarnEngStrtNotMeet Rte_Read_Common_Normal_WarnEngStrtNotMeet_WarnEngStrtNotMeet
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_WarnEngStrtNotMeet_WarnEngStrtNotMeet(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_WarnKeyInCarWhenExit_WarnKeyInCarWhenExit Rte_Read_Common_Normal_WarnKeyInCarWhenExit_WarnKeyInCarWhenExit
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_WarnKeyInCarWhenExit_WarnKeyInCarWhenExit(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_WarnPowerNotInOffPosn_WarnPowerNotInOffPosn Rte_Read_Common_Normal_WarnPowerNotInOffPosn_WarnPowerNotInOffPosn
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_WarnPowerNotInOffPosn_WarnPowerNotInOffPosn(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_WarnVldKeyNotFound_WarnVldKeyNotFound Rte_Read_Common_Normal_WarnVldKeyNotFound_WarnVldKeyNotFound
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Common_Normal_WarnVldKeyNotFound_WarnVldKeyNotFound(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element Rte_Read_Common_Normal_rcSR_SWCNormal_BswM_Warm_Reset_Element
#  define Rte_Read_Common_Normal_rcSR_SWCNormal_BswM_Warm_Reset_Element(data) (*(data) = Rte_Power_Sd_BswM_Warm_Reset_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_SWCNormal_ChimeID_Element Rte_Read_Common_Normal_rpSR_SWCNormal_ChimeID_Element
#  define Rte_Read_Common_Normal_rpSR_SWCNormal_ChimeID_Element(data) (*(data) = Rte_Common_Normal_ppSR_SWCNormal_ChimeID_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_SWCNormal_DiagMonitorReInitFlag_ChangeCounter Rte_Read_Common_Normal_rpSR_SWCNormal_DiagMonitorReInitFlag_ChangeCounter
#  define Rte_Read_Common_Normal_rpSR_SWCNormal_DiagMonitorReInitFlag_ChangeCounter(data) (*(data) = Rte_SocDtcProcess_pPSR_DiagMonitorReInitFlag_ChangeCounter, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_SWCNormal_DrvModStatusRecord_Element Rte_Read_Common_Normal_rpSR_SWCNormal_DrvModStatusRecord_Element
#  define Rte_Read_rpSR_SWCNormal_EnergyInfoId_Data Rte_Read_Common_Normal_rpSR_SWCNormal_EnergyInfoId_Data
#  define Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element Rte_Read_Common_Normal_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
#  define Rte_Read_rpSR_SWCNormal_MenuSetData_Element Rte_Read_Common_Normal_rpSR_SWCNormal_MenuSetData_Element
#  define Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedEnable_Element Rte_Read_Common_Normal_rpSR_SWCNormal_MenuSet_OverSpeedEnable_Element
#  define Rte_Read_Common_Normal_rpSR_SWCNormal_MenuSet_OverSpeedEnable_Element(data) (*(data) = Rte_Common_Normal_ppSR_SWCNormal_MenuSet_OverSpeedEnable_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedLimit_Element Rte_Read_Common_Normal_rpSR_SWCNormal_MenuSet_OverSpeedLimit_Element
#  define Rte_Read_Common_Normal_rpSR_SWCNormal_MenuSet_OverSpeedLimit_Element(data) (*(data) = Rte_Common_Normal_ppSR_SWCNormal_MenuSet_OverSpeedLimit_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_SWCNormal_OdoParament_Element Rte_Read_Common_Normal_rpSR_SWCNormal_OdoParament_Element
#  define Rte_Read_rpSR_SWCNormal_S2M_Information_SpeedValue Rte_Read_Common_Normal_rpSR_SWCNormal_S2M_Information_SpeedValue
#  define Rte_Read_Common_Normal_rpSR_SWCNormal_S2M_Information_SpeedValue(data) (*(data) = Rte_Common_GateWay_ppSR_SWCGateWay_S2M_Information_SpeedValue, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_SWCNormal_S2M_Information_TachoValue Rte_Read_Common_Normal_rpSR_SWCNormal_S2M_Information_TachoValue
#  define Rte_Read_Common_Normal_rpSR_SWCNormal_S2M_Information_TachoValue(data) (*(data) = Rte_Common_GateWay_ppSR_SWCGateWay_S2M_Information_TachoValue, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element Rte_Read_Common_Normal_rpSR_SWCNormal_SpeedoInfo_Element
#  define Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element Rte_Read_Common_Normal_rpSR_SWCNormal_TC_Module_Output_Data_Element
#  define Rte_Read_rpSR_SWCNormal_TC_NE_ChargStsOutput_Element Rte_Read_Common_Normal_rpSR_SWCNormal_TC_NE_ChargStsOutput_Element
#  define Rte_Read_rpSR_SWCNormal_TachoInfo_Element Rte_Read_Common_Normal_rpSR_SWCNormal_TachoInfo_Element
#  define Rte_Read_rpSR_SWCNormal_WarningStsOutput_Element Rte_Read_Common_Normal_rpSR_SWCNormal_WarningStsOutput_Element
#  define Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_SleepDateTime Rte_Read_Common_Normal_tiSR_Rte_Read_Sd_RTC_Data_SleepDateTime
#  define Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_UtcTime Rte_Read_Common_Normal_tiSR_Rte_Read_Sd_RTC_Data_UtcTime
#  define Rte_Read_tiSR_SWC_TT_SelfCheck_Element Rte_Read_Common_Normal_tiSR_SWC_TT_SelfCheck_Element
#  define Rte_Read_Common_Normal_tiSR_SWC_TT_SelfCheck_Element(data) (*(data) = Rte_Common_Safety_tiSR_SWC_TT_SelfCheck_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_tiSR_VIN_Element Rte_Read_Common_Normal_tiSR_VIN_Element


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_APS_FLSideSnsrFailSts_APS_FLSideSnsrFailSts Rte_IsUpdated_Common_Normal_APS_FLSideSnsrFailSts_APS_FLSideSnsrFailSts
#  define Rte_IsUpdated_Common_Normal_APS_FLSideSnsrFailSts_APS_FLSideSnsrFailSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_APS_FRSideSnsrFailSts_APS_FRSideSnsrFailSts Rte_IsUpdated_Common_Normal_APS_FRSideSnsrFailSts_APS_FRSideSnsrFailSts
#  define Rte_IsUpdated_Common_Normal_APS_FRSideSnsrFailSts_APS_FRSideSnsrFailSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_APS_RLSideSnsrFailSts_APS_RLSideSnsrFailSts Rte_IsUpdated_Common_Normal_APS_RLSideSnsrFailSts_APS_RLSideSnsrFailSts
#  define Rte_IsUpdated_Common_Normal_APS_RLSideSnsrFailSts_APS_RLSideSnsrFailSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_APS_RRSideSnsrFailSts_APS_RRSideSnsrFailSts Rte_IsUpdated_Common_Normal_APS_RRSideSnsrFailSts_APS_RRSideSnsrFailSts
#  define Rte_IsUpdated_Common_Normal_APS_RRSideSnsrFailSts_APS_RRSideSnsrFailSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_APS_SysSoundIndcn_APS_SysSoundIndcn Rte_IsUpdated_Common_Normal_APS_SysSoundIndcn_APS_SysSoundIndcn
#  define Rte_IsUpdated_Common_Normal_APS_SysSoundIndcn_APS_SysSoundIndcn() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_APS_WorkSts_APS_WorkSts Rte_IsUpdated_Common_Normal_APS_WorkSts_APS_WorkSts
#  define Rte_IsUpdated_Common_Normal_APS_WorkSts_APS_WorkSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_BMS_BattKeepTempSts_BMS_BattKeepTempSts Rte_IsUpdated_Common_Normal_BMS_BattKeepTempSts_BMS_BattKeepTempSts
#  define Rte_IsUpdated_Common_Normal_BMS_BattKeepTempSts_BMS_BattKeepTempSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_BMS_IntelEngIdlChrgnSts_BMS_IntelEngIdlChrgnSts Rte_IsUpdated_Common_Normal_BMS_IntelEngIdlChrgnSts_BMS_IntelEngIdlChrgnSts
#  define Rte_IsUpdated_Common_Normal_BMS_IntelEngIdlChrgnSts_BMS_IntelEngIdlChrgnSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_BMS_SOCLowWarn_BMS_SOCLowWarn Rte_IsUpdated_Common_Normal_BMS_SOCLowWarn_BMS_SOCLowWarn
#  define Rte_IsUpdated_Common_Normal_BMS_SOCLowWarn_BMS_SOCLowWarn() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_BSD_LCA_warningReqRight_BSD_LCA_warningReqRight Rte_IsUpdated_Common_Normal_BSD_LCA_warningReqRight_BSD_LCA_warningReqRight
#  define Rte_IsUpdated_Common_Normal_BSD_LCA_warningReqRight_BSD_LCA_warningReqRight() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_BSD_LCA_warningReqleft_BSD_LCA_warningReqleft Rte_IsUpdated_Common_Normal_BSD_LCA_warningReqleft_BSD_LCA_warningReqleft
#  define Rte_IsUpdated_Common_Normal_BSD_LCA_warningReqleft_BSD_LCA_warningReqleft() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_CCO_Active_CCO_Active Rte_IsUpdated_Common_Normal_CCO_Active_CCO_Active
#  define Rte_IsUpdated_Common_Normal_CCO_Active_CCO_Active() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_CR_BliSts_CR_BliSts Rte_IsUpdated_Common_Normal_CR_BliSts_CR_BliSts
#  define Rte_IsUpdated_Common_Normal_CR_BliSts_CR_BliSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_CruiseCtrlSts_CruiseCtrlSts Rte_IsUpdated_Common_Normal_CruiseCtrlSts_CruiseCtrlSts
#  define Rte_IsUpdated_Common_Normal_CruiseCtrlSts_CruiseCtrlSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_CruiseCtrlSts_PHEV_CruiseCtrlSts_PHEV Rte_IsUpdated_Common_Normal_CruiseCtrlSts_PHEV_CruiseCtrlSts_PHEV
#  define Rte_IsUpdated_Common_Normal_CruiseCtrlSts_PHEV_CruiseCtrlSts_PHEV() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_DCT3_TgtEngSpdIP_TgtEngSpdIP Rte_IsUpdated_Common_Normal_DCT3_TgtEngSpdIP_TgtEngSpdIP
#  define Rte_IsUpdated_Common_Normal_DCT3_TgtEngSpdIP_TgtEngSpdIP() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_DCT3_TgtEngSpdIPValid_TgtEngSpdIPValid Rte_IsUpdated_Common_Normal_DCT3_TgtEngSpdIPValid_TgtEngSpdIPValid
#  define Rte_IsUpdated_Common_Normal_DCT3_TgtEngSpdIPValid_TgtEngSpdIPValid() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_DOW_warningReqRight_DOW_warningReqRight Rte_IsUpdated_Common_Normal_DOW_warningReqRight_DOW_warningReqRight
#  define Rte_IsUpdated_Common_Normal_DOW_warningReqRight_DOW_warningReqRight() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_DOW_warningReqleft_DOW_warningReqleft Rte_IsUpdated_Common_Normal_DOW_warningReqleft_DOW_warningReqleft
#  define Rte_IsUpdated_Common_Normal_DOW_warningReqleft_DOW_warningReqleft() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ECM_VIN_ECM19_0x3B5 Rte_IsUpdated_Common_Normal_ECM_VIN_ECM19_0x3B5
#  define Rte_IsUpdated_Common_Normal_ECM_VIN_ECM19_0x3B5() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ECM_VehDstBackup_ECM_VehDstBackup Rte_IsUpdated_Common_Normal_ECM_VehDstBackup_ECM_VehDstBackup
#  define Rte_IsUpdated_Common_Normal_ECM_VehDstBackup_ECM_VehDstBackup() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ESP_HMI_WarningOn_ESP_HMI_WarningOn Rte_IsUpdated_Common_Normal_ESP_HMI_WarningOn_ESP_HMI_WarningOn
#  define Rte_IsUpdated_Common_Normal_ESP_HMI_WarningOn_ESP_HMI_WarningOn() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_EngClntTempVldty_EngClntTempVldty Rte_IsUpdated_Common_Normal_EngClntTempVldty_EngClntTempVldty
#  define Rte_IsUpdated_Common_Normal_EngClntTempVldty_EngClntTempVldty() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_EngClntTempWarn_EngClntTempWarn Rte_IsUpdated_Common_Normal_EngClntTempWarn_EngClntTempWarn
#  define Rte_IsUpdated_Common_Normal_EngClntTempWarn_EngClntTempWarn() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_EngCoolantTemp_EngCoolantTemp Rte_IsUpdated_Common_Normal_EngCoolantTemp_EngCoolantTemp
#  define Rte_IsUpdated_Common_Normal_EngCoolantTemp_EngCoolantTemp() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_EngSVSSig_EngSVSSig Rte_IsUpdated_Common_Normal_EngSVSSig_EngSVSSig
#  define Rte_IsUpdated_Common_Normal_EngSVSSig_EngSVSSig() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_FCTA_B_FuncSts_FCTA_B_FuncSts Rte_IsUpdated_Common_Normal_FCTA_B_FuncSts_FCTA_B_FuncSts
#  define Rte_IsUpdated_Common_Normal_FCTA_B_FuncSts_FCTA_B_FuncSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_FCTA_Warn_FCTA_Warn Rte_IsUpdated_Common_Normal_FCTA_Warn_FCTA_Warn
#  define Rte_IsUpdated_Common_Normal_FCTA_Warn_FCTA_Warn() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_FCTBTrig_FCTBTrig Rte_IsUpdated_Common_Normal_FCTBTrig_FCTBTrig
#  define Rte_IsUpdated_Common_Normal_FCTBTrig_FCTBTrig() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_FFogLmpSts_F_Pbox_FFogLmpSts_F_Pbox Rte_IsUpdated_Common_Normal_FFogLmpSts_F_Pbox_FFogLmpSts_F_Pbox
#  define Rte_IsUpdated_Common_Normal_FFogLmpSts_F_Pbox_FFogLmpSts_F_Pbox() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_FLTirePress_FLTirePress Rte_IsUpdated_Common_Normal_FLTirePress_FLTirePress
#  define Rte_IsUpdated_Common_Normal_FLTirePress_FLTirePress() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_FLTirePressIndSts_FLTirePressIndSts Rte_IsUpdated_Common_Normal_FLTirePressIndSts_FLTirePressIndSts
#  define Rte_IsUpdated_Common_Normal_FLTirePressIndSts_FLTirePressIndSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_FLTireTemp_FLTireTemp Rte_IsUpdated_Common_Normal_FLTireTemp_FLTireTemp
#  define Rte_IsUpdated_Common_Normal_FLTireTemp_FLTireTemp() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_FLTireTempSts_FLTireTempSts Rte_IsUpdated_Common_Normal_FLTireTempSts_FLTireTempSts
#  define Rte_IsUpdated_Common_Normal_FLTireTempSts_FLTireTempSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_FPAS_SoundIndcn_FPAS_SoundIndcn Rte_IsUpdated_Common_Normal_FPAS_SoundIndcn_FPAS_SoundIndcn
#  define Rte_IsUpdated_Common_Normal_FPAS_SoundIndcn_FPAS_SoundIndcn() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_FPAS_SoundIndcn_FD_FPAS_SoundIndcn_FD Rte_IsUpdated_Common_Normal_FPAS_SoundIndcn_FD_FPAS_SoundIndcn_FD
#  define Rte_IsUpdated_Common_Normal_FPAS_SoundIndcn_FD_FPAS_SoundIndcn_FD() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_FPAS_WorkSts_FPAS_WorkSts Rte_IsUpdated_Common_Normal_FPAS_WorkSts_FPAS_WorkSts
#  define Rte_IsUpdated_Common_Normal_FPAS_WorkSts_FPAS_WorkSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_FPAS_WorkSts_FD_FPAS_WorkSts_FD Rte_IsUpdated_Common_Normal_FPAS_WorkSts_FD_FPAS_WorkSts_FD
#  define Rte_IsUpdated_Common_Normal_FPAS_WorkSts_FD_FPAS_WorkSts_FD() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_FRTirePress_FRTirePress Rte_IsUpdated_Common_Normal_FRTirePress_FRTirePress
#  define Rte_IsUpdated_Common_Normal_FRTirePress_FRTirePress() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_FRTirePressIndSts_FRTirePressIndSts Rte_IsUpdated_Common_Normal_FRTirePressIndSts_FRTirePressIndSts
#  define Rte_IsUpdated_Common_Normal_FRTirePressIndSts_FRTirePressIndSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_FRTireTemp_FRTireTemp Rte_IsUpdated_Common_Normal_FRTireTemp_FRTireTemp
#  define Rte_IsUpdated_Common_Normal_FRTireTemp_FRTireTemp() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_FRTireTempSts_FRTireTempSts Rte_IsUpdated_Common_Normal_FRTireTempSts_FRTireTempSts
#  define Rte_IsUpdated_Common_Normal_FRTireTempSts_FRTireTempSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_FuelConsumption_FuelConsumption Rte_IsUpdated_Common_Normal_FuelConsumption_FuelConsumption
#  define Rte_IsUpdated_Common_Normal_FuelConsumption_FuelConsumption() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_GentrWarnLmpSts_GentrWarnLmpSts Rte_IsUpdated_Common_Normal_GentrWarnLmpSts_GentrWarnLmpSts
#  define Rte_IsUpdated_Common_Normal_GentrWarnLmpSts_GentrWarnLmpSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HCU_ChrgSysLmpSts_HCU_ChrgSysLmpSts Rte_IsUpdated_Common_Normal_HCU_ChrgSysLmpSts_HCU_ChrgSysLmpSts
#  define Rte_IsUpdated_Common_Normal_HCU_ChrgSysLmpSts_HCU_ChrgSysLmpSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HCU_EVLmpSts_HCU_EVLmpSts Rte_IsUpdated_Common_Normal_HCU_EVLmpSts_HCU_EVLmpSts
#  define Rte_IsUpdated_Common_Normal_HCU_EVLmpSts_HCU_EVLmpSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HiLowBeamSts_HiLowBeamSts Rte_IsUpdated_Common_Normal_HiLowBeamSts_HiLowBeamSts
#  define Rte_IsUpdated_Common_Normal_HiLowBeamSts_HiLowBeamSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_IB_Warn_IB_Warn Rte_IsUpdated_Common_Normal_IB_Warn_IB_Warn
#  define Rte_IsUpdated_Common_Normal_IB_Warn_IB_Warn() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_KL30BRelaySts_KL30BRelaySts Rte_IsUpdated_Common_Normal_KL30BRelaySts_KL30BRelaySts
#  define Rte_IsUpdated_Common_Normal_KL30BRelaySts_KL30BRelaySts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_LADBstatus_LADBstatus Rte_IsUpdated_Common_Normal_LADBstatus_LADBstatus
#  define Rte_IsUpdated_Common_Normal_LADBstatus_LADBstatus() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_LHiBeamSts_LHiBeamSts Rte_IsUpdated_Common_Normal_LHiBeamSts_LHiBeamSts
#  define Rte_IsUpdated_Common_Normal_LHiBeamSts_LHiBeamSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_LTurnLmpSts_R_Pbox_LTurnLmpSts_R_Pbox Rte_IsUpdated_Common_Normal_LTurnLmpSts_R_Pbox_LTurnLmpSts_R_Pbox
#  define Rte_IsUpdated_Common_Normal_LTurnLmpSts_R_Pbox_LTurnLmpSts_R_Pbox() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_MILSts_MILSts Rte_IsUpdated_Common_Normal_MILSts_MILSts
#  define Rte_IsUpdated_Common_Normal_MILSts_MILSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_PASWorkCmd_PASWorkCmd Rte_IsUpdated_Common_Normal_PASWorkCmd_PASWorkCmd
#  define Rte_IsUpdated_Common_Normal_PASWorkCmd_PASWorkCmd() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ParkLmpSts_R_Pbox_ParkLmpSts_R_Pbox Rte_IsUpdated_Common_Normal_ParkLmpSts_R_Pbox_ParkLmpSts_R_Pbox
#  define Rte_IsUpdated_Common_Normal_ParkLmpSts_R_Pbox_ParkLmpSts_R_Pbox() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_PosnLmpOutpSts_R_Pbox_PosnLmpOutpSts_R_Pbox Rte_IsUpdated_Common_Normal_PosnLmpOutpSts_R_Pbox_PosnLmpOutpSts_R_Pbox
#  define Rte_IsUpdated_Common_Normal_PosnLmpOutpSts_R_Pbox_PosnLmpOutpSts_R_Pbox() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RADBstatus_RADBstatus Rte_IsUpdated_Common_Normal_RADBstatus_RADBstatus
#  define Rte_IsUpdated_Common_Normal_RADBstatus_RADBstatus() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RCTA_warningReqLeft_RCTA_warningReqLeft Rte_IsUpdated_Common_Normal_RCTA_warningReqLeft_RCTA_warningReqLeft
#  define Rte_IsUpdated_Common_Normal_RCTA_warningReqLeft_RCTA_warningReqLeft() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RCTA_warningReqRight_RCTA_warningReqRight Rte_IsUpdated_Common_Normal_RCTA_warningReqRight_RCTA_warningReqRight
#  define Rte_IsUpdated_Common_Normal_RCTA_warningReqRight_RCTA_warningReqRight() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RFogLmpFailSts_R_Pbox_RFogLmpFailSts_R_Pbox Rte_IsUpdated_Common_Normal_RFogLmpFailSts_R_Pbox_RFogLmpFailSts_R_Pbox
#  define Rte_IsUpdated_Common_Normal_RFogLmpFailSts_R_Pbox_RFogLmpFailSts_R_Pbox() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RHiBeamSts_RHiBeamSts Rte_IsUpdated_Common_Normal_RHiBeamSts_RHiBeamSts
#  define Rte_IsUpdated_Common_Normal_RHiBeamSts_RHiBeamSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RLTirePress_RLTirePress Rte_IsUpdated_Common_Normal_RLTirePress_RLTirePress
#  define Rte_IsUpdated_Common_Normal_RLTirePress_RLTirePress() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RLTirePressIndSts_RLTirePressIndSts Rte_IsUpdated_Common_Normal_RLTirePressIndSts_RLTirePressIndSts
#  define Rte_IsUpdated_Common_Normal_RLTirePressIndSts_RLTirePressIndSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RLTireTemp_RLTireTemp Rte_IsUpdated_Common_Normal_RLTireTemp_RLTireTemp
#  define Rte_IsUpdated_Common_Normal_RLTireTemp_RLTireTemp() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RLTireTempSts_RLTireTempSts Rte_IsUpdated_Common_Normal_RLTireTempSts_RLTireTempSts
#  define Rte_IsUpdated_Common_Normal_RLTireTempSts_RLTireTempSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RPAS_SoundIndcn_RPAS_SoundIndcn Rte_IsUpdated_Common_Normal_RPAS_SoundIndcn_RPAS_SoundIndcn
#  define Rte_IsUpdated_Common_Normal_RPAS_SoundIndcn_RPAS_SoundIndcn() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RPAS_SoundIndcn_FD_RPAS_SoundIndcn_FD Rte_IsUpdated_Common_Normal_RPAS_SoundIndcn_FD_RPAS_SoundIndcn_FD
#  define Rte_IsUpdated_Common_Normal_RPAS_SoundIndcn_FD_RPAS_SoundIndcn_FD() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RPAS_WorkSts_RPAS_WorkSts Rte_IsUpdated_Common_Normal_RPAS_WorkSts_RPAS_WorkSts
#  define Rte_IsUpdated_Common_Normal_RPAS_WorkSts_RPAS_WorkSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RPAS_WorkSts_FD_RPAS_WorkSts_FD Rte_IsUpdated_Common_Normal_RPAS_WorkSts_FD_RPAS_WorkSts_FD
#  define Rte_IsUpdated_Common_Normal_RPAS_WorkSts_FD_RPAS_WorkSts_FD() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RRTirePress_RRTirePress Rte_IsUpdated_Common_Normal_RRTirePress_RRTirePress
#  define Rte_IsUpdated_Common_Normal_RRTirePress_RRTirePress() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RRTirePressIndSts_RRTirePressIndSts Rte_IsUpdated_Common_Normal_RRTirePressIndSts_RRTirePressIndSts
#  define Rte_IsUpdated_Common_Normal_RRTirePressIndSts_RRTirePressIndSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RRTireTemp_RRTireTemp Rte_IsUpdated_Common_Normal_RRTireTemp_RRTireTemp
#  define Rte_IsUpdated_Common_Normal_RRTireTemp_RRTireTemp() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RRTireTempSts_RRTireTempSts Rte_IsUpdated_Common_Normal_RRTireTempSts_RRTireTempSts
#  define Rte_IsUpdated_Common_Normal_RRTireTempSts_RRTireTempSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RSDS_CTA_Actv_RSDS_CTA_Actv Rte_IsUpdated_Common_Normal_RSDS_CTA_Actv_RSDS_CTA_Actv
#  define Rte_IsUpdated_Common_Normal_RSDS_CTA_Actv_RSDS_CTA_Actv() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RSDS_ErrSts_RSDS_ErrSts Rte_IsUpdated_Common_Normal_RSDS_ErrSts_RSDS_ErrSts
#  define Rte_IsUpdated_Common_Normal_RSDS_ErrSts_RSDS_ErrSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RSDS_IPSoundReq_RSDS_IPSoundReq Rte_IsUpdated_Common_Normal_RSDS_IPSoundReq_RSDS_IPSoundReq
#  define Rte_IsUpdated_Common_Normal_RSDS_IPSoundReq_RSDS_IPSoundReq() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RTurnLmpSts_R_Pbox_RTurnLmpSts_R_Pbox Rte_IsUpdated_Common_Normal_RTurnLmpSts_R_Pbox_RTurnLmpSts_R_Pbox
#  define Rte_IsUpdated_Common_Normal_RTurnLmpSts_R_Pbox_RTurnLmpSts_R_Pbox() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_Rc_Fuel_Status_Fuel_Status Rte_IsUpdated_Common_Normal_Rc_Fuel_Status_Fuel_Status
#  define Rte_IsUpdated_Common_Normal_Rc_Fuel_Status_Fuel_Status() (Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_Normal_Rc_Fuel_Status_Fuel_Status != Rte_OsApplication_NonTrust_OsCore0_RxUpdateFlags.Rte_RxUpdate_Common_Normal_Rc_Fuel_Status_Fuel_Status_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_RemoteModSts_RemoteModSts Rte_IsUpdated_Common_Normal_RemoteModSts_RemoteModSts
#  define Rte_IsUpdated_Common_Normal_RemoteModSts_RemoteModSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SDWActiveSts_SDWActiveSts Rte_IsUpdated_Common_Normal_SDWActiveSts_SDWActiveSts
#  define Rte_IsUpdated_Common_Normal_SDWActiveSts_SDWActiveSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SDW_SoundIndcn_SDW_SoundIndcn Rte_IsUpdated_Common_Normal_SDW_SoundIndcn_SDW_SoundIndcn
#  define Rte_IsUpdated_Common_Normal_SDW_SoundIndcn_SDW_SoundIndcn() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ABM1_SG_ABM1 Rte_IsUpdated_Common_Normal_SG_ABM1_SG_ABM1
#  define Rte_IsUpdated_Common_Normal_SG_ABM1_SG_ABM1() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ABS3_SG_ABS3 Rte_IsUpdated_Common_Normal_SG_ABS3_SG_ABS3
#  define Rte_IsUpdated_Common_Normal_SG_ABS3_SG_ABS3() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2 Rte_IsUpdated_Common_Normal_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2
#  define Rte_IsUpdated_Common_Normal_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2 Rte_IsUpdated_Common_Normal_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2
#  define Rte_IsUpdated_Common_Normal_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2 Rte_IsUpdated_Common_Normal_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2
#  define Rte_IsUpdated_Common_Normal_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2 Rte_IsUpdated_Common_Normal_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2
#  define Rte_IsUpdated_Common_Normal_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2 Rte_IsUpdated_Common_Normal_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2
#  define Rte_IsUpdated_Common_Normal_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2 Rte_IsUpdated_Common_Normal_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2
#  define Rte_IsUpdated_Common_Normal_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2 Rte_IsUpdated_Common_Normal_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2
#  define Rte_IsUpdated_Common_Normal_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_BMS4_SG_BMS4 Rte_IsUpdated_Common_Normal_SG_BMS4_SG_BMS4
#  define Rte_IsUpdated_Common_Normal_SG_BMS4_SG_BMS4() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_DCT7_SG_DCT7 Rte_IsUpdated_Common_Normal_SG_DCT7_SG_DCT7
#  define Rte_IsUpdated_Common_Normal_SG_DCT7_SG_DCT7() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_DHT_FD1_SG_DHT_FD1 Rte_IsUpdated_Common_Normal_SG_DHT_FD1_SG_DHT_FD1
#  define Rte_IsUpdated_Common_Normal_SG_DHT_FD1_SG_DHT_FD1() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_EPB1_SG_EPB1 Rte_IsUpdated_Common_Normal_SG_EPB1_SG_EPB1
#  define Rte_IsUpdated_Common_Normal_SG_EPB1_SG_EPB1() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_EPS1_SG_EPS1 Rte_IsUpdated_Common_Normal_SG_EPS1_SG_EPS1
#  define Rte_IsUpdated_Common_Normal_SG_EPS1_SG_EPS1() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_EPS1_FD1_SG_EPS1_FD1 Rte_IsUpdated_Common_Normal_SG_EPS1_FD1_SG_EPS1_FD1
#  define Rte_IsUpdated_Common_Normal_SG_EPS1_FD1_SG_EPS1_FD1() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ESP2_SG_ESP2 Rte_IsUpdated_Common_Normal_SG_ESP2_SG_ESP2
#  define Rte_IsUpdated_Common_Normal_SG_ESP2_SG_ESP2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2 Rte_IsUpdated_Common_Normal_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2
#  define Rte_IsUpdated_Common_Normal_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_HC1_SG_HC1 Rte_IsUpdated_Common_Normal_SG_HC1_SG_HC1
#  define Rte_IsUpdated_Common_Normal_SG_HC1_SG_HC1() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_HCU_HP5_SG_HCU_HP5 Rte_IsUpdated_Common_Normal_SG_HCU_HP5_SG_HCU_HP5
#  define Rte_IsUpdated_Common_Normal_SG_HCU_HP5_SG_HCU_HP5() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_HCU_PT4_SG_HCU_PT4 Rte_IsUpdated_Common_Normal_SG_HCU_PT4_SG_HCU_PT4
#  define Rte_IsUpdated_Common_Normal_SG_HCU_PT4_SG_HCU_PT4() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_HCU_PT7_SG_HCU_PT7 Rte_IsUpdated_Common_Normal_SG_HCU_PT7_SG_HCU_PT7
#  define Rte_IsUpdated_Common_Normal_SG_HCU_PT7_SG_HCU_PT7() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_IFC3_IFC_FD2_SG_IFC3_IFC_FD2 Rte_IsUpdated_Common_Normal_SG_IFC3_IFC_FD2_SG_IFC3_IFC_FD2
#  define Rte_IsUpdated_Common_Normal_SG_IFC3_IFC_FD2_SG_IFC3_IFC_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2 Rte_IsUpdated_Common_Normal_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2
#  define Rte_IsUpdated_Common_Normal_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_IFC5_IFC_FD2_SG_IFC5_IFC_FD2 Rte_IsUpdated_Common_Normal_SG_IFC5_IFC_FD2_SG_IFC5_IFC_FD2
#  define Rte_IsUpdated_Common_Normal_SG_IFC5_IFC_FD2_SG_IFC5_IFC_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SG_IFC6_IFC_FD2_SG_IFC6_IFC_FD2 Rte_IsUpdated_Common_Normal_SG_IFC6_IFC_FD2_SG_IFC6_IFC_FD2
#  define Rte_IsUpdated_Common_Normal_SG_IFC6_IFC_FD2_SG_IFC6_IFC_FD2() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SS_Enable_Lamp_SS_Enable_Lamp Rte_IsUpdated_Common_Normal_SS_Enable_Lamp_SS_Enable_Lamp
#  define Rte_IsUpdated_Common_Normal_SS_Enable_Lamp_SS_Enable_Lamp() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_SS_Fault_Lamp_SS_Fault_Lamp Rte_IsUpdated_Common_Normal_SS_Fault_Lamp_SS_Fault_Lamp
#  define Rte_IsUpdated_Common_Normal_SS_Fault_Lamp_SS_Fault_Lamp() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_TGS_LEVER_TGS_LEVER Rte_IsUpdated_Common_Normal_TGS_LEVER_TGS_LEVER
#  define Rte_IsUpdated_Common_Normal_TGS_LEVER_TGS_LEVER() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_TSRSpdLim_TSRSpdLim Rte_IsUpdated_Common_Normal_TSRSpdLim_TSRSpdLim
#  define Rte_IsUpdated_Common_Normal_TSRSpdLim_TSRSpdLim() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_TSRSpdLimCfdc_TSRSpdLimCfdc Rte_IsUpdated_Common_Normal_TSRSpdLimCfdc_TSRSpdLimCfdc
#  define Rte_IsUpdated_Common_Normal_TSRSpdLimCfdc_TSRSpdLimCfdc() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_TSRSpdLimSts_TSRSpdLimSts Rte_IsUpdated_Common_Normal_TSRSpdLimSts_TSRSpdLimSts
#  define Rte_IsUpdated_Common_Normal_TSRSpdLimSts_TSRSpdLimSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_TSRSpdLimWarn_TSRSpdLimWarn Rte_IsUpdated_Common_Normal_TSRSpdLimWarn_TSRSpdLimWarn
#  define Rte_IsUpdated_Common_Normal_TSRSpdLimWarn_TSRSpdLimWarn() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_TSRSts_TSRSts Rte_IsUpdated_Common_Normal_TSRSts_TSRSts
#  define Rte_IsUpdated_Common_Normal_TSRSts_TSRSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_TSRTrfcSignVal_TSRTrfcSignVal Rte_IsUpdated_Common_Normal_TSRTrfcSignVal_TSRTrfcSignVal
#  define Rte_IsUpdated_Common_Normal_TSRTrfcSignVal_TSRTrfcSignVal() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_T_Box_SysErrSts_T_Box_SysErrSts Rte_IsUpdated_Common_Normal_T_Box_SysErrSts_T_Box_SysErrSts
#  define Rte_IsUpdated_Common_Normal_T_Box_SysErrSts_T_Box_SysErrSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_TgtRcprtnTrqSts_TgtRcprtnTrqSts Rte_IsUpdated_Common_Normal_TgtRcprtnTrqSts_TgtRcprtnTrqSts
#  define Rte_IsUpdated_Common_Normal_TgtRcprtnTrqSts_TgtRcprtnTrqSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_TirePressSysFailrIndcn_TirePressSysFailrIndcn Rte_IsUpdated_Common_Normal_TirePressSysFailrIndcn_TirePressSysFailrIndcn
#  define Rte_IsUpdated_Common_Normal_TirePressSysFailrIndcn_TirePressSysFailrIndcn() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_TrailerSts_TrailerSts Rte_IsUpdated_Common_Normal_TrailerSts_TrailerSts
#  define Rte_IsUpdated_Common_Normal_TrailerSts_TrailerSts() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Sd_CanOutputViaGateway_CheckSum_IP2 Rte_Write_Common_Normal_Sd_CanOutputViaGateway_CheckSum_IP2
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_CheckSum_IP2(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_CheckSum_IP2 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_ABMWarnLmpFailrSts Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_ABMWarnLmpFailrSts
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_ABMWarnLmpFailrSts(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_ABMWarnLmpFailrSts = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_ACCErr Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_ACCErr
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_ACCErr(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_ACCErr = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_AvgFuelCons
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_AvgFuelCons(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_AvgFuelCons = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_BattChrgLmpSts Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_BattChrgLmpSts
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_BattChrgLmpSts(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_BattChrgLmpSts = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_CurrTheme Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_CurrTheme
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_CurrTheme(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_CurrTheme = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_DrvSeatBeltWarnLmpFailSts Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_DrvSeatBeltWarnLmpFailSts
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_DrvSeatBeltWarnLmpFailSts(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_DrvSeatBeltWarnLmpFailSts = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_EngOilPressLowLmpSts Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_EngOilPressLowLmpSts
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_EngOilPressLowLmpSts(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_EngOilPressLowLmpSts = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_Err Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_Err
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_Err(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_Err = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_FuelAuxTankR
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_FuelAuxTankR(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelAuxTankR = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_FuelLvlInfo
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_FuelLvlInfo(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelLvlInfo = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_FuelMainTankR
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_FuelMainTankR(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_FuelMainTankR = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_InstFuelCons
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_InstFuelCons(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_InstFuelCons = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_InstFuelConsUnit
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_InstFuelConsUnit(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_InstFuelConsUnit = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_LagueSet Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_LagueSet
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_LagueSet(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_LagueSet = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_PassSeatBeltWarnLmpFailSts Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_PassSeatBeltWarnLmpFailSts
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_PassSeatBeltWarnLmpFailSts(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_PassSeatBeltWarnLmpFailSts = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_RemainDistance
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_RemainDistance(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_RemainDistance = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_VINcompr Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_VINcompr
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_VINcompr(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VINcompr = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_VehSpdDisp Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_VehSpdDisp
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_VehSpdDisp(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehSpdDisp = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_VehSpdUnit Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_VehSpdUnit
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_VehSpdUnit(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehSpdUnit = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_VehTotDistance Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_VehTotDistance
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_VehTotDistance(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehTotDistance = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_VehTotDistanceValid Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_VehTotDistanceValid
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_VehTotDistanceValid(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VehTotDistanceValid = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_IP_VelSpdDisp_Mile Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_VelSpdDisp_Mile
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_IP_VelSpdDisp_Mile(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_IP_VelSpdDisp_Mile = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_RollingCounter_IP2 Rte_Write_Common_Normal_Sd_CanOutputViaGateway_RollingCounter_IP2
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_RollingCounter_IP2(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_RollingCounter_IP2 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_CanOutputViaGateway_dummy_HUT_IP2_0 Rte_Write_Common_Normal_Sd_CanOutputViaGateway_dummy_HUT_IP2_0
#  define Rte_Write_Common_Normal_Sd_CanOutputViaGateway_dummy_HUT_IP2_0(data) (Rte_Common_Normal_Sd_CanOutputViaGateway_dummy_HUT_IP2_0 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_Cluster_Shutdown_Status_Element Rte_Write_Common_Normal_Sd_Cluster_Shutdown_Status_Element
#  define Rte_Write_Sd_Fuel_Status_Fuel_Status Rte_Write_Common_Normal_Sd_Fuel_Status_Fuel_Status
#  define Rte_Write_Sd_Odo_RunCounter_RunCounter Rte_Write_Common_Normal_Sd_Odo_RunCounter_RunCounter
#  define Rte_Write_Common_Normal_Sd_Odo_RunCounter_RunCounter(data) (Rte_Common_Normal_Sd_Odo_RunCounter_RunCounter = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_SpeedoInfo_IndicateSpeed Rte_Write_Common_Normal_Sd_SpeedoInfo_IndicateSpeed
#  define Rte_Write_Common_Normal_Sd_SpeedoInfo_IndicateSpeed(data) (Rte_Common_Normal_Sd_SpeedoInfo_IndicateSpeed = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_SpeedoInfo_OverSpdWrnFlg Rte_Write_Common_Normal_Sd_SpeedoInfo_OverSpdWrnFlg
#  define Rte_Write_Common_Normal_Sd_SpeedoInfo_OverSpdWrnFlg(data) (Rte_Common_Normal_Sd_SpeedoInfo_OverSpdWrnFlg = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_SpeedoInfo_RealSpeed Rte_Write_Common_Normal_Sd_SpeedoInfo_RealSpeed
#  define Rte_Write_Common_Normal_Sd_SpeedoInfo_RealSpeed(data) (Rte_Common_Normal_Sd_SpeedoInfo_RealSpeed = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_SpeedoInfo_VehRunSts Rte_Write_Common_Normal_Sd_SpeedoInfo_VehRunSts
#  define Rte_Write_Common_Normal_Sd_SpeedoInfo_VehRunSts(data) (Rte_Common_Normal_Sd_SpeedoInfo_VehRunSts = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_TachoInfo_EngRunSts Rte_Write_Common_Normal_Sd_TachoInfo_EngRunSts
#  define Rte_Write_Common_Normal_Sd_TachoInfo_EngRunSts(data) (Rte_Common_Normal_Sd_TachoInfo_EngRunSts = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Sd_TachoInfo_EngSpd Rte_Write_Common_Normal_Sd_TachoInfo_EngSpd
#  define Rte_Write_Common_Normal_Sd_TachoInfo_EngSpd(data) (Rte_Common_Normal_Sd_TachoInfo_EngSpd = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_ppSR_SWCNormal_ChimeID_Element Rte_Write_Common_Normal_ppSR_SWCNormal_ChimeID_Element
#  define Rte_Write_Common_Normal_ppSR_SWCNormal_ChimeID_Element(data) (Rte_Common_Normal_ppSR_SWCNormal_ChimeID_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_ppSR_SWCNormal_DrvModStatusRecord_Element Rte_Write_Common_Normal_ppSR_SWCNormal_DrvModStatusRecord_Element
#  define Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element Rte_Write_Common_Normal_ppSR_SWCNormal_Fuel_Set_Module_Data_Element
#  define Rte_Write_ppSR_SWCNormal_MenuSetData_Element Rte_Write_Common_Normal_ppSR_SWCNormal_MenuSetData_Element
#  define Rte_Write_ppSR_SWCNormal_MenuSet_OverSpeedEnable_Element Rte_Write_Common_Normal_ppSR_SWCNormal_MenuSet_OverSpeedEnable_Element
#  define Rte_Write_Common_Normal_ppSR_SWCNormal_MenuSet_OverSpeedEnable_Element(data) (Rte_Common_Normal_ppSR_SWCNormal_MenuSet_OverSpeedEnable_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_ppSR_SWCNormal_MenuSet_OverSpeedLimit_Element Rte_Write_Common_Normal_ppSR_SWCNormal_MenuSet_OverSpeedLimit_Element
#  define Rte_Write_Common_Normal_ppSR_SWCNormal_MenuSet_OverSpeedLimit_Element(data) (Rte_Common_Normal_ppSR_SWCNormal_MenuSet_OverSpeedLimit_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_ppSR_SWCNormal_OdoParament_Element Rte_Write_Common_Normal_ppSR_SWCNormal_OdoParament_Element
#  define Rte_Write_ppSR_SWCNormal_SpeedoInfo_Element Rte_Write_Common_Normal_ppSR_SWCNormal_SpeedoInfo_Element
#  define Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element Rte_Write_Common_Normal_ppSR_SWCNormal_TC_Module_Output_Data_Element
#  define Rte_Write_ppSR_SWCNormal_TC_NE_ChargStsOutput_Element Rte_Write_Common_Normal_ppSR_SWCNormal_TC_NE_ChargStsOutput_Element
#  define Rte_Write_ppSR_SWCNormal_TachoInfo_Element Rte_Write_Common_Normal_ppSR_SWCNormal_TachoInfo_Element
#  define Rte_Write_ppSR_SWCNormal_WarningStsOutput_Element Rte_Write_Common_Normal_ppSR_SWCNormal_WarningStsOutput_Element


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (mapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_CanFrameCounter_Can_ABS3_Counter Rte_Call_Common_Normal_CanFrameCounter_Can_ABS3_Counter
#  define Rte_Call_CanFrameCounter_Can_ECM2_Counter Rte_Call_Common_Normal_CanFrameCounter_Can_ECM2_Counter
#  define Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter Rte_Call_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter
#  define Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus Rte_Call_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
#  define Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus Rte_Call_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
#  define Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus Rte_Call_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
#  define Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus Rte_Call_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
#  define Rte_Call_HsmKeyM_GetAes128Key Rte_Call_Common_Normal_HsmKeyM_GetAes128Key
#  define Rte_Call_HsmKeyM_SetAes128Key Rte_Call_Common_Normal_HsmKeyM_SetAes128Key
#  define Rte_Call_Hsm_Port_TrngGenerate Rte_Call_Common_Normal_Hsm_Port_TrngGenerate
#  define Rte_Call_IRTC_Service_GetUTCTimeInMillis Rte_Call_Common_Normal_IRTC_Service_GetUTCTimeInMillis
#  define Rte_Call_IRTC_Service_UTC2PerpetualCalendar Rte_Call_Common_Normal_IRTC_Service_UTC2PerpetualCalendar
#  define Rte_Call_IoHwAb_Interface_GetPin Rte_Call_Common_Normal_IoHwAb_Interface_GetPin
#  define Rte_Call_IoHwAb_Interface_GetVoltage Rte_Call_Common_Normal_IoHwAb_Interface_GetVoltage
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock
#  define Rte_Call_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock
#  define Rte_Call_Os_Service_GetCounterValue Rte_Call_Common_Normal_Os_Service_GetCounterValue
#  define Rte_Call_Os_Service_GetElapsedValue Rte_Call_Common_Normal_Os_Service_GetElapsedValue
#  define Rte_Call_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig Rte_Call_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
#  define Rte_Call_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick Rte_Call_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick
#  define Rte_Call_rpCS_SWCNormal_ComEx_GetRxE2EStatus Rte_Call_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus
#  define Rte_Call_rpCS_SWCNormal_ComEx_SendSignal Rte_Call_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CSM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_CancelJob(uint32 parg0, Crypto_OperationModeType parg1); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_CSM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CancelJob() (Csm_CancelJob((uint32)0, (Crypto_OperationModeType)7)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_CSM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_Decrypt(uint32 parg0, Crypto_OperationModeType parg1, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) dataBuffer, uint32 dataLength, P2VAR(uint8, AUTOMATIC, RTE_CSM_APPL_VAR) resultBuffer, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) resultLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_Decrypt(uint32 parg0, Crypto_OperationModeType parg1, P2CONST(Csm_DecryptDataType_CsmPrimitives_AES128_Decrypt, AUTOMATIC, RTE_CSM_APPL_DATA) dataBuffer, uint32 dataLength, P2VAR(Csm_DecryptResultType_CsmPrimitives_AES128_Decrypt, AUTOMATIC, RTE_CSM_APPL_VAR) resultBuffer, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) resultLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_CSM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CsmDecrypt_CsmPrimitives_AES128_Decrypt_Decrypt(arg1, arg2, arg3, arg4) (Csm_Decrypt((uint32)0, (Crypto_OperationModeType)7, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CancelJob() (Csm_CancelJob((uint32)1, (Crypto_OperationModeType)7)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_CSM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_Encrypt(uint32 parg0, Crypto_OperationModeType parg1, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) dataBuffer, uint32 dataLength, P2VAR(uint8, AUTOMATIC, RTE_CSM_APPL_VAR) resultBuffer, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) resultLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_Encrypt(uint32 parg0, Crypto_OperationModeType parg1, P2CONST(Csm_EncryptDataType_CsmPrimitives_AES128_Encrypt, AUTOMATIC, RTE_CSM_APPL_DATA) dataBuffer, uint32 dataLength, P2VAR(Csm_EncryptResultType_CsmPrimitives_AES128_Encrypt, AUTOMATIC, RTE_CSM_APPL_VAR) resultBuffer, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) resultLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_CSM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CsmEncrypt_CsmPrimitives_AES128_Encrypt_Encrypt(arg1, arg2, arg3, arg4) (Csm_Encrypt((uint32)1, (Crypto_OperationModeType)7, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_HSM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_HSM_APPL_CODE) HsmGetCmacKey(P2VAR(uint8, AUTOMATIC, RTE_HSM_APPL_VAR) key, P2VAR(uint32, AUTOMATIC, RTE_HSM_APPL_VAR) key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(void, RTE_HSM_APPL_CODE) HsmGetCmacKey(P2VAR(IdtHsmKeyArray, AUTOMATIC, RTE_HSM_APPL_VAR) key, P2VAR(uint32, AUTOMATIC, RTE_HSM_APPL_VAR) key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_HSM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_HsmKeyM_GetCmacKey(arg1, arg2) (HsmGetCmacKey(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_HSM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_HSM_APPL_CODE) HsmGetCmacKeyState(P2VAR(HSM_KeyStateEnum, AUTOMATIC, RTE_HSM_APPL_VAR) state); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_HSM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_HsmKeyM_GetCmacKeyState(arg1) (HsmGetCmacKeyState(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_HSM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_HSM_APPL_CODE) HsmSetCmacKey(P2CONST(uint8, AUTOMATIC, RTE_HSM_APPL_DATA) vin, uint32 vin_len, P2CONST(uint8, AUTOMATIC, RTE_HSM_APPL_DATA) key, uint32 key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(void, RTE_HSM_APPL_CODE) HsmSetCmacKey(P2CONST(IdtHsmVinArray, AUTOMATIC, RTE_HSM_APPL_DATA) vin, uint32 vin_len, P2CONST(IdtHsmKeyArray, AUTOMATIC, RTE_HSM_APPL_DATA) key, uint32 key_len); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_HSM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_HsmKeyM_SetCmacKey(arg1, arg2, arg3, arg4) (HsmSetCmacKey(arg1, arg2, arg3, arg4), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMMON_GATEWAY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_COMMON_GATEWAY_APPL_CODE) IPC_Send_IPC_Send(uint8 Id_u8, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data_s, uint16 len_u16, boolean Imm_bool); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_GATEWAY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_IPC_Send_IPC_Send IPC_Send_IPC_Send
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_EraseBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_EraseBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_GetErrorStatus Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_GetErrorStatus
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_InvalidateNvBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_InvalidateNvBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_ReadBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_ReadBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_RestoreBlockDefaults Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_RestoreBlockDefaults
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_SetRamBlockStatus Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_SetRamBlockStatus
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_EraseBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_EraseBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_GetErrorStatus Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_GetErrorStatus
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_InvalidateNvBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_InvalidateNvBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_ReadBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_ReadBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_RestoreBlockDefaults Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_RestoreBlockDefaults
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_SetRamBlockStatus Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_SetRamBlockStatus
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_EraseBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_EraseBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_GetErrorStatus Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_GetErrorStatus
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_InvalidateNvBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_InvalidateNvBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_ReadBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_ReadBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_RestoreBlockDefaults Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_RestoreBlockDefaults
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_SetRamBlockStatus Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_SetRamBlockStatus
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_EraseBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_EraseBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_GetErrorStatus Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_GetErrorStatus
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_InvalidateNvBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_InvalidateNvBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_ReadBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_ReadBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_RestoreBlockDefaults Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_RestoreBlockDefaults
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_SetRamBlockStatus Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_SetRamBlockStatus
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_EraseBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_EraseBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_GetErrorStatus Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_GetErrorStatus
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_InvalidateNvBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_InvalidateNvBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_ReadBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_ReadBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_RestoreBlockDefaults Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_RestoreBlockDefaults
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_SetRamBlockStatus Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_SetRamBlockStatus
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_EraseBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_EraseBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_GetErrorStatus Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_GetErrorStatus
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_InvalidateNvBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_InvalidateNvBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_ReadBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_ReadBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_RestoreBlockDefaults Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_RestoreBlockDefaults
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_SetRamBlockStatus Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_SetRamBlockStatus
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Config_Data_EraseBlock() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Config_Data_GetErrorStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Config_Data_InvalidateNvBlock() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Config_Data_ReadBlock(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Config_Data_RestoreBlockDefaults(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Config_Data_SetRamBlockStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Config_Data_WriteBlock(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Data_EraseBlock() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Data_GetErrorStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Data_InvalidateNvBlock() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Data_ReadBlock(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Data_RestoreBlockDefaults(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Data_SetRamBlockStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Data_WriteBlock(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_EraseBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_EraseBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_GetErrorStatus Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_GetErrorStatus
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_InvalidateNvBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_InvalidateNvBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_ReadBlock Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_ReadBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_RestoreBlockDefaults Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_RestoreBlockDefaults
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_SetRamBlockStatus Rte_Call_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_SetRamBlockStatus
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_EraseNvBlock(NvM_BlockIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_NvBlockNeed_Menu_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)58)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_NvBlockNeed_Menu_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)58, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_InvalidateNvBlock(NvM_BlockIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_NvBlockNeed_Menu_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)58)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_NvBlockNeed_Menu_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)58, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_NvBlockNeed_Menu_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)58, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMMON_GATEWAY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_GATEWAY_APPL_CODE) ppCS_SWCNormal_Callback_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_GATEWAY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ppCS_SWCNormal_ChimeCallback_Operation(arg1) (ppCS_SWCNormal_Callback_Operation(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_ppCS_SWCNormal_TTCallback_Operation(arg1) (ppCS_SWCNormal_Callback_Operation(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_ppCS_SWCNormal_WrnCallback_Operation(arg1) (ppCS_SWCNormal_Callback_Operation(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMEX_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_COMEX_APPL_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(uint8, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_COMEX_APPL_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(ComEx_SignalDataType, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_COMEX_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal ComEx_ReceiveSignal
#  define RTE_START_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_COMMON_NORMAL_APPL_CODE) DM_API_vGetDrvModTTStatus(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_SWCNormal_DM_API_vGetDrvModTTStatus_Operation DM_API_vGetDrvModTTStatus
#  define RTE_START_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_COMMON_NORMAL_APPL_CODE) DM_API_vGetDrvModWarningStatus(uint8 enWarningID, P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_SWCNormal_DM_API_vGetDrvModWarningStatus_Operation DM_API_vGetDrvModWarningStatus
#  define RTE_START_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_COMMON_NORMAL_APPL_CODE) RTE_TC_API_Set_TC_Module_Reset_Data(uint8 tc_reset_index); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_SWCNormal_Reset_TC_Module_Data_WriteData RTE_TC_API_Set_TC_Module_Reset_Data
#  define RTE_START_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_COMMON_NORMAL_APPL_CODE) SWCNormal_SensorAorB_Status_Operation(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation SWCNormal_SensorAorB_Status_Operation


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_ExclusiveArea_Normal() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#  define Rte_Exit_ExclusiveArea_Normal() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(NVMBlockMaintain_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_Block_MaintainOdo_DefaultValue;
extern CONST(A_ODO_data_u8_16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_1_DefaultValue;
extern CONST(A_ODO_data_u8_16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_2_DefaultValue;
extern CONST(A_ODO_data_u8_16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_3_DefaultValue;
extern CONST(A_ODO_data_u8_16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_4_DefaultValue;
extern CONST(A_ODO_data_u8_16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_5_DefaultValue;
extern CONST(NVMBlockTCConfig_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_Block_TC_Config_Data_DefaultValue;
extern CONST(NVMBlockTC_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_Block_TC_Data_DefaultValue;
extern CONST(NVMBlockTrip, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_Block_Trip_DefaultValue;
extern CONST(NVMMenuData_A20, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Common_Normal_NvBlockNeed_MENU_Data_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_Block_MaintainOdo_DefaultValue() (&(Rte_Common_Normal_NvBlockNeed_Block_MaintainOdo_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_Block_MaintainOdo_DefaultValue() (&Rte_Common_Normal_NvBlockNeed_Block_MaintainOdo_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_Block_ODO_1_DefaultValue() (&(Rte_Common_Normal_NvBlockNeed_Block_ODO_1_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_Block_ODO_1_DefaultValue() (&Rte_Common_Normal_NvBlockNeed_Block_ODO_1_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_Block_ODO_2_DefaultValue() (&(Rte_Common_Normal_NvBlockNeed_Block_ODO_2_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_Block_ODO_2_DefaultValue() (&Rte_Common_Normal_NvBlockNeed_Block_ODO_2_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_Block_ODO_3_DefaultValue() (&(Rte_Common_Normal_NvBlockNeed_Block_ODO_3_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_Block_ODO_3_DefaultValue() (&Rte_Common_Normal_NvBlockNeed_Block_ODO_3_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_Block_ODO_4_DefaultValue() (&(Rte_Common_Normal_NvBlockNeed_Block_ODO_4_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_Block_ODO_4_DefaultValue() (&Rte_Common_Normal_NvBlockNeed_Block_ODO_4_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_Block_ODO_5_DefaultValue() (&(Rte_Common_Normal_NvBlockNeed_Block_ODO_5_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_Block_ODO_5_DefaultValue() (&Rte_Common_Normal_NvBlockNeed_Block_ODO_5_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_Block_TC_Config_Data_DefaultValue() (&(Rte_Common_Normal_NvBlockNeed_Block_TC_Config_Data_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_Block_TC_Config_Data_DefaultValue() (&Rte_Common_Normal_NvBlockNeed_Block_TC_Config_Data_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_Block_TC_Data_DefaultValue() (&(Rte_Common_Normal_NvBlockNeed_Block_TC_Data_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_Block_TC_Data_DefaultValue() (&Rte_Common_Normal_NvBlockNeed_Block_TC_Data_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_Block_Trip_DefaultValue() (&(Rte_Common_Normal_NvBlockNeed_Block_Trip_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_Block_Trip_DefaultValue() (&Rte_Common_Normal_NvBlockNeed_Block_Trip_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_MENU_Data_DefaultValue() (&(Rte_Common_Normal_NvBlockNeed_MENU_Data_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_MENU_Data_DefaultValue() (&Rte_Common_Normal_NvBlockNeed_MENU_Data_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(NVMBlockMaintain_Type, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_Normal_NvBlockNeed_Block_MaintainOdo_MirrorBlock;
extern VAR(A_ODO_data_u8_16, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_1_MirrorBlock;
extern VAR(A_ODO_data_u8_16, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_2_MirrorBlock;
extern VAR(A_ODO_data_u8_16, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_3_MirrorBlock;
extern VAR(A_ODO_data_u8_16, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_4_MirrorBlock;
extern VAR(A_ODO_data_u8_16, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_Normal_NvBlockNeed_Block_ODO_5_MirrorBlock;
extern VAR(NVMBlockTrip, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_Normal_NvBlockNeed_Block_Trip_MirrorBlock;
extern VAR(NVMMenuData_A20, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_Normal_NvBlockNeed_MENU_Data_MirrorBlock;
extern VAR(NVMMenuData_A20, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_Common_Normal_NvBlockNeed_Menu_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_Block_MaintainOdo_MirrorBlock() (&((*RtePim_NvBlockNeed_Block_MaintainOdo_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_Block_MaintainOdo_MirrorBlock() RtePim_NvBlockNeed_Block_MaintainOdo_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_Block_MaintainOdo_MirrorBlock() \
  (&Rte_Common_Normal_NvBlockNeed_Block_MaintainOdo_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_Block_ODO_1_MirrorBlock() (&((*RtePim_NvBlockNeed_Block_ODO_1_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_Block_ODO_1_MirrorBlock() RtePim_NvBlockNeed_Block_ODO_1_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_Block_ODO_1_MirrorBlock() \
  (&Rte_Common_Normal_NvBlockNeed_Block_ODO_1_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_Block_ODO_2_MirrorBlock() (&((*RtePim_NvBlockNeed_Block_ODO_2_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_Block_ODO_2_MirrorBlock() RtePim_NvBlockNeed_Block_ODO_2_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_Block_ODO_2_MirrorBlock() \
  (&Rte_Common_Normal_NvBlockNeed_Block_ODO_2_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_Block_ODO_3_MirrorBlock() (&((*RtePim_NvBlockNeed_Block_ODO_3_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_Block_ODO_3_MirrorBlock() RtePim_NvBlockNeed_Block_ODO_3_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_Block_ODO_3_MirrorBlock() \
  (&Rte_Common_Normal_NvBlockNeed_Block_ODO_3_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_Block_ODO_4_MirrorBlock() (&((*RtePim_NvBlockNeed_Block_ODO_4_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_Block_ODO_4_MirrorBlock() RtePim_NvBlockNeed_Block_ODO_4_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_Block_ODO_4_MirrorBlock() \
  (&Rte_Common_Normal_NvBlockNeed_Block_ODO_4_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_Block_ODO_5_MirrorBlock() (&((*RtePim_NvBlockNeed_Block_ODO_5_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_Block_ODO_5_MirrorBlock() RtePim_NvBlockNeed_Block_ODO_5_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_Block_ODO_5_MirrorBlock() \
  (&Rte_Common_Normal_NvBlockNeed_Block_ODO_5_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_Block_Trip_MirrorBlock() (&((*RtePim_NvBlockNeed_Block_Trip_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_Block_Trip_MirrorBlock() RtePim_NvBlockNeed_Block_Trip_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_Block_Trip_MirrorBlock() \
  (&Rte_Common_Normal_NvBlockNeed_Block_Trip_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_MENU_Data_MirrorBlock() (&((*RtePim_NvBlockNeed_MENU_Data_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_MENU_Data_MirrorBlock() RtePim_NvBlockNeed_MENU_Data_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_MENU_Data_MirrorBlock() \
  (&Rte_Common_Normal_NvBlockNeed_MENU_Data_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_Menu_MirrorBlock() (&((*RtePim_NvBlockNeed_Menu_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_Menu_MirrorBlock() RtePim_NvBlockNeed_Menu_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_Menu_MirrorBlock() \
  (&Rte_Common_Normal_NvBlockNeed_Menu_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define Common_Normal_START_SEC_CODE
# include "Common_Normal_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Common_Normal_100msMainFunction Common_Normal_100msMainFunction
#  define RTE_RUNNABLE_Common_Normal_100msMainFunction_ Common_Normal_100msMainFunction_
#  define RTE_RUNNABLE_Common_Normal_10msMainFunction Common_Normal_10msMainFunction
#  define RTE_RUNNABLE_Common_Normal_10msMainFunction_ Common_Normal_10msMainFunction_
#  define RTE_RUNNABLE_Common_Normal_20msMainFunction Common_Normal_20msMainFunction
#  define RTE_RUNNABLE_Common_Normal_20msMainFunction_ Common_Normal_20msMainFunction_
#  define RTE_RUNNABLE_Common_Normal_20msMainFunction_A Common_Normal_20msMainFunction_A
#  define RTE_RUNNABLE_Common_Normal_20msMainFunction_B Common_Normal_20msMainFunction_B
#  define RTE_RUNNABLE_Common_Normal_5msMainFunction Common_Normal_5msMainFunction
#  define RTE_RUNNABLE_Common_Normal_Init Common_Normal_Init
#  define RTE_RUNNABLE_Common_Normal_List_Deinit Common_Normal_List_Deinit
#  define RTE_RUNNABLE_Common_Normal_List_Int Common_Normal_List_Int
#  define RTE_RUNNABLE_Common_Normal_Nomal2Standby_Callbcak Common_Normal_Nomal2Standby_Callbcak
#  define RTE_RUNNABLE_Common_Normal_Standby2Nomal_Callbcak Common_Normal_Standby2Nomal_Callbcak
#  define RTE_RUNNABLE_CsmJob_Aes128_Decrypt_Cbk_Callback_CallbackNotification CsmJob_Aes128_Decrypt_Cbk_Callback_CallbackNotification
#  define RTE_RUNNABLE_CsmJob_Aes128_Encrypt_Cbk_Callback_CallbackNotification CsmJob_Aes128_Encrypt_Cbk_Callback_CallbackNotification
#  define RTE_RUNNABLE_DM_API_vGetDrvModTTStatus DM_API_vGetDrvModTTStatus
#  define RTE_RUNNABLE_DM_API_vGetDrvModWarningStatus DM_API_vGetDrvModWarningStatus
#  define RTE_RUNNABLE_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster
#  define RTE_RUNNABLE_Fuel_Api_ParamentGetCsPort_Operation Fuel_Api_ParamentGetCsPort_Operation
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Block_MaintainOdo_JobFinished NvMNotifyJobFinished_NvBlockNeed_Block_MaintainOdo_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Block_ODO_1_JobFinished NvMNotifyJobFinished_NvBlockNeed_Block_ODO_1_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Block_ODO_2_JobFinished NvMNotifyJobFinished_NvBlockNeed_Block_ODO_2_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Block_ODO_3_JobFinished NvMNotifyJobFinished_NvBlockNeed_Block_ODO_3_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Block_ODO_4_JobFinished NvMNotifyJobFinished_NvBlockNeed_Block_ODO_4_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Block_ODO_5_JobFinished NvMNotifyJobFinished_NvBlockNeed_Block_ODO_5_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Block_TC_Config_Data_JobFinished NvMNotifyJobFinished_NvBlockNeed_Block_TC_Config_Data_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Block_TC_Data_JobFinished NvMNotifyJobFinished_NvBlockNeed_Block_TC_Data_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Block_Trip_JobFinished NvMNotifyJobFinished_NvBlockNeed_Block_Trip_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Menu_JobFinished NvMNotifyJobFinished_NvBlockNeed_Menu_JobFinished
#  define RTE_RUNNABLE_Odo_Api_ParamentGetCsPortGetData Odo_Api_ParamentGetCsPortGetData
#  define RTE_RUNNABLE_RTE_Odo_Api_ParamentSetFunction RTE_Odo_Api_ParamentSetFunction
#  define RTE_RUNNABLE_RTE_TC_API_Set_TC_Module_Reset_Data RTE_TC_API_Set_TC_Module_Reset_Data
#  define RTE_RUNNABLE_SWCNormal_SensorAorB_Status_Operation SWCNormal_SensorAorB_Status_Operation
#  define RTE_RUNNABLE_TC_Api_ParamentGetCsPort_1_Operation TC_Api_ParamentGetCsPort_1_Operation
#  define RTE_RUNNABLE_TC_EnergyInfo TC_EnergyInfo
#  define RTE_RUNNABLE_TC_EnergyInfoResp TC_EnergyInfoResp
#  define RTE_RUNNABLE_ppCS_SWCNormal_OdoTimeSync_CallBack ppCS_SWCNormal_OdoTimeSync_CallBack
#  define RTE_RUNNABLE_ppCS_SWCNormal_ReceiveMenuTheme_Callback ppCS_SWCNormal_ReceiveMenuTheme_Callback
#  define RTE_RUNNABLE_ppCS_TtToChime ppCS_TtToChime
#  define RTE_RUNNABLE_svCS_GetTankResistanceValue_Operation svCS_GetTankResistanceValue_Operation
#  define RTE_RUNNABLE_svCS_SWCNormal_ChimeCallback_Operation svCS_SWCNormal_ChimeCallback_Operation
#  define RTE_RUNNABLE_svCS_SWCNormal_HMIResetTC_Callback svCS_SWCNormal_HMIResetTC_Callback
#  define RTE_RUNNABLE_svCS_SWCNormal_ReceiveAdasStatus_Callback svCS_SWCNormal_ReceiveAdasStatus_Callback
#  define RTE_RUNNABLE_svCS_SWCNormal_ReceiveHMIPowerMode_Callback svCS_SWCNormal_ReceiveHMIPowerMode_Callback
#  define RTE_RUNNABLE_svCS_SWCNormal_ReceiveMenuSetting_Callback svCS_SWCNormal_ReceiveMenuSetting_Callback
#  define RTE_RUNNABLE_svCS_SWCNormal_ReceiveOffroadInfo_Callback svCS_SWCNormal_ReceiveOffroadInfo_Callback
#  define RTE_RUNNABLE_svCS_SWCNormal_ReceiveSafetyGearCRCCallback svCS_SWCNormal_ReceiveSafetyGearCRCCallback
#  define RTE_RUNNABLE_svCS_SWCNormal_ReceiveSafetyTTCRCCallback svCS_SWCNormal_ReceiveSafetyTTCRCCallback
#  define RTE_RUNNABLE_svCS_SWCNormal_TTCallback_Operation svCS_SWCNormal_TTCallback_Operation
#  define RTE_RUNNABLE_svCS_SWCNormal_WrnCallback_Operation svCS_SWCNormal_WrnCallback_Operation
# endif

FUNC(void, Common_Normal_CODE) Common_Normal_100msMainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Common_Normal_CODE) Common_Normal_100msMainFunction_(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Common_Normal_CODE) Common_Normal_10msMainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Common_Normal_CODE) Common_Normal_10msMainFunction_(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Common_Normal_CODE) Common_Normal_20msMainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Common_Normal_CODE) Common_Normal_20msMainFunction_(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Common_Normal_CODE) Common_Normal_20msMainFunction_A(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Common_Normal_CODE) Common_Normal_20msMainFunction_B(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Common_Normal_CODE) Common_Normal_5msMainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Common_Normal_CODE) Common_Normal_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Common_Normal_CODE) Common_Normal_List_Deinit(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) Common_Normal_List_Int(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) Common_Normal_Nomal2Standby_Callbcak(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) Common_Normal_Standby2Nomal_Callbcak(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) CsmJob_Aes128_Decrypt_Cbk_Callback_CallbackNotification(Csm_ResultType result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) CsmJob_Aes128_Encrypt_Cbk_Callback_CallbackNotification(Csm_ResultType result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Common_Normal_CODE) DM_API_vGetDrvModTTStatus(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Common_Normal_CODE) DM_API_vGetDrvModWarningStatus(uint8 enWarningID, P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, Common_Normal_CODE) EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster(P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(void, Common_Normal_CODE) EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster(P2VAR(EOL_6Bytes, AUTOMATIC, RTE_VAR_NOINIT) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, Common_Normal_CODE) Fuel_Api_ParamentGetCsPort_Operation(P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(void, Common_Normal_CODE) Fuel_Api_ParamentGetCsPort_Operation(P2VAR(Diag_9Bytes, AUTOMATIC, RTE_VAR_NOINIT) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_MaintainOdo_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_ODO_1_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_ODO_2_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_ODO_3_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_ODO_4_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_ODO_5_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_TC_Config_Data_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_TC_Data_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_Trip_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Menu_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) Odo_Api_ParamentGetCsPortGetData(uint8 Id, P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Common_Normal_CODE) RTE_Odo_Api_ParamentSetFunction(uint8 SetId, P2VAR(uint32, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Common_Normal_CODE) RTE_TC_API_Set_TC_Module_Reset_Data(uint8 tc_reset_index); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Common_Normal_CODE) SWCNormal_SensorAorB_Status_Operation(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) TC_Api_ParamentGetCsPort_1_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) TC_EnergyInfo(EnergyInfoDataType Id, P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) TC_EnergyInfoResp(EnergyInfoDataType Id, boolean Resp); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) ppCS_SWCNormal_OdoTimeSync_CallBack(sint64 pre_time, sint64 now_time); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) ppCS_SWCNormal_ReceiveMenuTheme_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) ppCS_TtToChime(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) svCS_GetTankResistanceValue_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) TankResistanceValue); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) svCS_SWCNormal_ChimeCallback_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) svCS_SWCNormal_HMIResetTC_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) svCS_SWCNormal_ReceiveAdasStatus_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) svCS_SWCNormal_ReceiveHMIPowerMode_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) svCS_SWCNormal_ReceiveMenuSetting_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) svCS_SWCNormal_ReceiveOffroadInfo_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) svCS_SWCNormal_ReceiveSafetyGearCRCCallback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) svCS_SWCNormal_ReceiveSafetyTTCRCCallback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) svCS_SWCNormal_TTCallback_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Common_Normal_CODE) svCS_SWCNormal_WrnCallback_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define Common_Normal_STOP_SEC_CODE
# include "Common_Normal_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComEx_COMEX_ERROR_PARAM (1U)

#  define RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED (2U)

#  define RTE_E_ComEx_COMEX_NEVER_RECEIVED (4U)

#  define RTE_E_ComEx_COMEX_UPDATE_RECEIVED (8U)

#  define RTE_E_ComEx_E_OK (0U)

#  define RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CSM_E_BUSY (2U)

#  define RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CSM_E_JOB_CANCELED (12U)

#  define RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CSM_E_KEY_NOT_VALID (9U)

#  define RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_E_NOT_OK (1U)

#  define RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CSM_E_BUSY (2U)

#  define RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CSM_E_JOB_CANCELED (12U)

#  define RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CSM_E_KEY_NOT_VALID (9U)

#  define RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_E_NOT_OK (1U)

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_IPC_Send_Std_ReturnType (1U)

#  define RTE_E_IRTC_Service_E_NOT_OK (1U)

#  define RTE_E_IoHwAb_Interface_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)

#  define RTE_E_Os_Service_E_OK (0U)

#  define RTE_E_Os_Service_E_OS_ID (3U)

#  define RTE_E_Os_Service_E_OS_VALUE (8U)

#  define RTE_E_VConfig_GetKindConfig_Std_ReturnType (1U)

#  define RTE_E_VConfig_GetUpdateTick_Std_ReturnType (1U)

#  define RTE_E_tiCS_DM_API_vGetDrvModTTStatus_E_NOT_OK (1U)

#  define RTE_E_tiCS_DM_API_vGetDrvModWarningStatus_E_NOT_OK (1U)

#  define RTE_E_tiCS_OdoSetParament_Std_ReturnType (1U)

#  define RTE_E_tiCS_Reset_TC_Module_Data_E_NOT_OK (1U)

#  define RTE_E_tiSR_SensorAorB_Status_E_OK (0U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_COMMON_NORMAL_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
