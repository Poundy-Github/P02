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
*File Name   : SWC_CA_Config.h                                                                            *
*                                                                                                         *
*Description : CA module Config head file.                                      		                  *
*                                                                                                         *
*Author      : Chen Tuhe                                                                                  *
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

#ifndef CA_CFG_H
#define CA_CFG_H


/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "Rte_Common_GateWay.h"

#include "Rte_Common_GateWay.h"
#include "VConfig.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
* CAN Adapt Debug Switch                                                                                  *
**********************************************************************************************************/

#define SWC_CA_DEBUG

/*********************************************************************************************************/
#ifdef SWC_CA_DEBUG
/**********************************************************************************************************
* Log Head File Include                                                                                   *
**********************************************************************************************************/
#include "logger.h"
#include <stdio.h>

/**********************************************************************************************************
* Debug Define                                                                                            *
**********************************************************************************************************/

/**********************************************************************************************************
* CA Error Code Definenation                                                                              *
**********************************************************************************************************/

/**********************************************************************************************************
* CA Log Switch Definenation                                                                              *
**********************************************************************************************************/

/**********************************************************************************************************
* CA Log Interface Definenation                                                                           *
**********************************************************************************************************/

#define SWC_CA_PRINT_SIGNAL_STATE_SWITCHON
#ifdef SWC_CA_PRINT_SIGNAL_STATE_SWITCHON
#define SWC_CA_PRINT_SIGNAL_STATE              	tripcomputer_warn // gw_warn
#else
#define SWC_CA_PRINT_SIGNAL_STATE(...)
#endif

#define SWC_CA_PRINT_MSG_STATE_SWITCHON
#ifdef SWC_CA_PRINT_MSG_STATE_SWITCHON
#define SWC_CA_PRINT_MSG_STATE              	tripcomputer_warn // gw_warn
#else
#define SWC_CA_PRINT_MSG_STATE(...)
#endif

//#define SWC_CA_PRINT_SIGNAL_VALUE_SWITCHON
#ifdef SWC_CA_PRINT_SIGNAL_VALUE_SWITCHON
#define SWC_CA_PRINT_SIGNAL_VALUE              	tripcomputer_warn // gw_warn
#else
#define SWC_CA_PRINT_SIGNAL_VALUE(...)
#endif

#else

#define SWC_CA_PRINT_SIGNAL_STATE(...)

#define SWC_CA_PRINT_MSG_STATE(...)

#define SWC_CA_PRINT_SIGNAL_VALUE(...)

#endif

#ifdef GWM_V35_PROJECT_TYPE_B02
#define SWC_CA_ADAPT_B02
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P05
#define SWC_CA_ADAPT_P05
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P03
#define SWC_CA_ADAPT_P03
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_A07
#define SWC_CA_ADAPT_A07
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_D01
#define SWC_CA_ADAPT_D01
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_D02
#define SWC_CA_ADAPT_D02
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_D03
#define SWC_CA_ADAPT_D03
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P02
#define SWC_CA_ADAPT_P02
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P01
#define SWC_CA_ADAPT_P01
#include "ComEx_Cfg.h"
#else
#define SWC_CA_ADAPT_NULL
#endif

#define SignalLengthIsU8Counts_1		1
#define SignalLengthIsU8Counts_2		2
#define SignalLengthIsU8Counts_4		4
#define SignalLengthIsU8Counts_8		8

#define     SWC_CA_SWC_TASK_CYCLE               10u
#define     SWC_CA_10MS_Cycle                   (10/SWC_CA_SWC_TASK_CYCLE)
#define     SWC_CA_20MS_Cycle                   (20/SWC_CA_SWC_TASK_CYCLE)
#define     SWC_CA_50MS_Cycle                   (50/SWC_CA_SWC_TASK_CYCLE)
#define     SWC_CA_100MS_Cycle                  (100/SWC_CA_SWC_TASK_CYCLE)
#define     SWC_CA_200MS_Cycle                  (200/SWC_CA_SWC_TASK_CYCLE)
#define     SWC_CA_500MS_Cycle                  (500/SWC_CA_SWC_TASK_CYCLE)

#define     SWC_MsgPriority_0                   0
#define     SWC_MsgPriority_1                   1
#define     SWC_MsgPriority_2                   2
#define     SWC_MsgPriority_3                   3
#define     SWC_MsgPriority_4                   4

#define CACANSignalRTENUM_ProDBCIsNotIncluded            		0xFFFFu
#define CA_CFG_SignalLengthIsU8Counts_Table	\
{\
SignalLengthIsU8Counts_1,    /* DrivingModDis_0x145 */\
SignalLengthIsU8Counts_1,    /* DrivingModDis_0x137 */\
SignalLengthIsU8Counts_1,    /* ESPBrkLmpCtrl_0x137 */\
SignalLengthIsU8Counts_1,    /* BSD_LCA_warningReqRight */\
SignalLengthIsU8Counts_1,    /* BSD_LCA_warningReqleft */\
SignalLengthIsU8Counts_1,    /* DOW_warningReqRight */\
SignalLengthIsU8Counts_1,    /* DOW_warningReqleft */\
SignalLengthIsU8Counts_1,    /* IFC_Line01_Type */\
SignalLengthIsU8Counts_2,    /* IFC_Line01_Dy */\
SignalLengthIsU8Counts_2,    /* IFC_Line01_Curv */\
SignalLengthIsU8Counts_4,    /* IFC_Line01_CurvChange */\
SignalLengthIsU8Counts_1,    /* IFC_Line02_Type */\
SignalLengthIsU8Counts_2,    /* IFC_Line02_Dy */\
SignalLengthIsU8Counts_2,    /* IFC_Line02_Curv */\
SignalLengthIsU8Counts_4,    /* IFC_Line02_CurvChange */\
SignalLengthIsU8Counts_1,    /* IFC_Line03_Type */\
SignalLengthIsU8Counts_2,    /* IFC_Line03_Dy */\
SignalLengthIsU8Counts_2,    /* IFC_Line03_Curv */\
SignalLengthIsU8Counts_4,    /* IFC_Line03_CurvChange */\
SignalLengthIsU8Counts_1,    /* IFC_Line04_Type */\
SignalLengthIsU8Counts_2,    /* IFC_Line04_Dy */\
SignalLengthIsU8Counts_2,    /* IFC_Line04_Curv */\
SignalLengthIsU8Counts_4,    /* IFC_Line04_CurvChange */\
SignalLengthIsU8Counts_1,    /* IFC_Roadedge01_Type */\
SignalLengthIsU8Counts_2,    /* IFC_Roadedge01_Dy */\
SignalLengthIsU8Counts_2,    /* IFC_Roadedge01_Curv */\
SignalLengthIsU8Counts_4,    /* IFC_Roadedge01_CurvChange */\
SignalLengthIsU8Counts_1,    /* IFC_Roadedge02_Type */\
SignalLengthIsU8Counts_2,    /* IFC_Roadedge02_Dy */\
SignalLengthIsU8Counts_2,    /* IFC_Roadedge02_Curv */\
SignalLengthIsU8Counts_4,    /* IFC_Roadedge02_CurvChange */\
SignalLengthIsU8Counts_2,    /* IFC_Line01_HeadingAngle */\
SignalLengthIsU8Counts_2,    /* IFC_Line02_HeadingAngle */\
SignalLengthIsU8Counts_2,    /* IFC_Line03_HeadingAngle */\
SignalLengthIsU8Counts_2,    /* IFC_Line04_HeadingAngle */\
SignalLengthIsU8Counts_2,    /* IFC_Roadedge01_HeadingAngle */\
SignalLengthIsU8Counts_2,    /* IFC_Roadedge02_HeadingAngle */\
SignalLengthIsU8Counts_1,    /* ACC_PotentialTgtTyp */\
SignalLengthIsU8Counts_1,    /* ACC_PotentialTgtDy */\
SignalLengthIsU8Counts_2,    /* ACC_PotentialTgtDx */\
SignalLengthIsU8Counts_1,    /* ACC_PotentialTgtHeading */\
SignalLengthIsU8Counts_1,    /* ACC_PotentialTgtDetn */\
SignalLengthIsU8Counts_1,    /* ACC_RlvTgtTyp */\
SignalLengthIsU8Counts_1,    /* ACC_RlvTgtDy */\
SignalLengthIsU8Counts_2,    /* ACC_RlvTgtDx */\
SignalLengthIsU8Counts_1,    /* ACC_RlvTgtHeading */\
SignalLengthIsU8Counts_1,    /* ACC_RlvTgtDetn */\
SignalLengthIsU8Counts_1,    /* ACC_LeTgtTyp */\
SignalLengthIsU8Counts_1,    /* ACC_LeTgtDy */\
SignalLengthIsU8Counts_2,    /* ACC_LeTgtDx */\
SignalLengthIsU8Counts_1,    /* ACC_LeTgtHeading */\
SignalLengthIsU8Counts_1,    /* ACC_LeTargrtDection */\
SignalLengthIsU8Counts_1,    /* ACC_RiTgtTyp */\
SignalLengthIsU8Counts_1,    /* ACC_RiTgtDy */\
SignalLengthIsU8Counts_2,    /* ACC_RiTgtDx */\
SignalLengthIsU8Counts_1,    /* ACC_RiTgtHeading */\
SignalLengthIsU8Counts_1,    /* ACC_RiTargrtDetn */\
SignalLengthIsU8Counts_1,    /* ACC_LeTgt_02_Typ */\
SignalLengthIsU8Counts_1,    /* ACC_LeTgt_02_Dy */\
SignalLengthIsU8Counts_2,    /* ACC_LeTgt_02_Dx */\
SignalLengthIsU8Counts_1,    /* ACC_LeTargrt_02_Detn */\
SignalLengthIsU8Counts_1,    /* ACC_RiTgt_02_Typ */\
SignalLengthIsU8Counts_1,    /* ACC_RiTgt_02_Dy */\
SignalLengthIsU8Counts_2,    /* ACC_RiTgt_02_Dx */\
SignalLengthIsU8Counts_1,    /* ACC_RiTargrt_02_Detn */\
SignalLengthIsU8Counts_1,    /* ACC_ModDisp */\
SignalLengthIsU8Counts_1,    /* TJA_ICA_ModDisp */\
SignalLengthIsU8Counts_1,    /* ACC_TgtObjBarDisp */\
SignalLengthIsU8Counts_1,    /* ACC_FctSts */\
SignalLengthIsU8Counts_1,    /* HWA_InterSysInfoDisp */\
SignalLengthIsU8Counts_1,    /* ACC_InterSysInfoDisp */\
SignalLengthIsU8Counts_1,    /* TJA_ICA_InterSysInfoDisp */\
SignalLengthIsU8Counts_1,    /* Request_driveoff */\
SignalLengthIsU8Counts_1,    /* HWA_ModDisp */\
SignalLengthIsU8Counts_1,    /* HWA_LaneChange */\
SignalLengthIsU8Counts_1,    /* HWA_LaneChangeReq */\
SignalLengthIsU8Counts_1,    /* HWA_Resp */\
SignalLengthIsU8Counts_1,    /* ALC_Resp */\
SignalLengthIsU8Counts_1,    /* ACC_EgoStatus */\
SignalLengthIsU8Counts_1,    /* ACC_SpdSetValue */\
SignalLengthIsU8Counts_1,    /* ACC_TimeGapSet */\
SignalLengthIsU8Counts_1,    /* ISL_InterSysInfoDisp */\
SignalLengthIsU8Counts_1,    /* LSSIntervention */\
SignalLengthIsU8Counts_1,    /* TJA_FollowSts */\
SignalLengthIsU8Counts_1,    /* IntelligentEvaActSts */\
SignalLengthIsU8Counts_1,    /* LaneAvailability */\
SignalLengthIsU8Counts_1,    /* FCW_Warn */\
SignalLengthIsU8Counts_1,    /* AEB_VehTrig */\
SignalLengthIsU8Counts_1,    /* AEB_PedTrig */\
SignalLengthIsU8Counts_1,    /* AEB_JABrkTrig */\
SignalLengthIsU8Counts_1,    /* ACC_RiTgt_03_Typ */\
SignalLengthIsU8Counts_1,    /* ACC_RiTargrt_03_Detn */\
SignalLengthIsU8Counts_2,    /* ACC_RiTgt_03_Dx */\
SignalLengthIsU8Counts_1,    /* ACC_RiTgt_03_Dy */\
SignalLengthIsU8Counts_1,    /* ACC_LeTgt_03_Typ */\
SignalLengthIsU8Counts_1,    /* ACC_LeTargrt_03_Detn */\
SignalLengthIsU8Counts_2,    /* ACC_LeTgt_03_Dx */\
SignalLengthIsU8Counts_1,    /* ACC_LeTgt_03_Dy */\
SignalLengthIsU8Counts_1,    /* ACC_PotentialTgt_02_Heading */\
SignalLengthIsU8Counts_1,    /* ACC_PotentialTgt_02_Typ */\
SignalLengthIsU8Counts_1,    /* ACC_PotentialTgt_02_Detn */\
SignalLengthIsU8Counts_2,    /* ACC_PotentialTgt_02_Dx */\
SignalLengthIsU8Counts_1,    /* ACC_PotentialTgt_02_Dy */\
SignalLengthIsU8Counts_1,    /* FCTA_Warn */\
SignalLengthIsU8Counts_1,    /* FCTBTrig */\
SignalLengthIsU8Counts_1,    /* SAS_Sts */\
SignalLengthIsU8Counts_2,    /* SteerWheelAng */\
SignalLengthIsU8Counts_1,    /* SteerWheelAngSign */\
SignalLengthIsU8Counts_1,    /* IDC_L2_TurnLightReq */\
SignalLengthIsU8Counts_1,    /* HWA_InhibitWarn */\
SignalLengthIsU8Counts_1,    /* HWA_WarnInfoDisp */\
SignalLengthIsU8Counts_1,    /* MRC_InterSysInfoDisp */\
SignalLengthIsU8Counts_1,    /* HWA_ALC_Trig */\
SignalLengthIsU8Counts_1,    /* Stop_Mark_Detn */\
SignalLengthIsU8Counts_2,    /* Stop_Mark_Dx */\
SignalLengthIsU8Counts_1,    /* Zebra_Mark_Detn */\
SignalLengthIsU8Counts_2,    /* Zebra_Mark_Dx */\
SignalLengthIsU8Counts_1,    /* Grid_Mark_Detn */\
SignalLengthIsU8Counts_2,    /* Grid_Mark_Dx */\
SignalLengthIsU8Counts_1,    /* IFC_Line01_Source */\
SignalLengthIsU8Counts_1,    /* IFC_Line02_Source */\
SignalLengthIsU8Counts_1,    /* TSRSpdLim */\
SignalLengthIsU8Counts_1,    /* HWA_TakOver_Req */\
SignalLengthIsU8Counts_1,    /* AutoSpdSetSwt_Resp */\
SignalLengthIsU8Counts_1,    /* NOH_Sts */\
SignalLengthIsU8Counts_1,    /* NOH_SysInfoDisplay */\
SignalLengthIsU8Counts_1,    /* V2X_RLVW */\
SignalLengthIsU8Counts_1,    /* DrvDoorSts */\
SignalLengthIsU8Counts_1,    /* BrkPedalSts_BCM */\
SignalLengthIsU8Counts_1,    /* DrvDoorLockSts */\
SignalLengthIsU8Counts_1,    /* SrPosn_VR_APP */\
SignalLengthIsU8Counts_1,    /* PageUpSwtSts */\
SignalLengthIsU8Counts_1,    /* PageDwnSwtSts */\
SignalLengthIsU8Counts_1,    /* PageLSwtSts */\
SignalLengthIsU8Counts_1,    /* PageRSwtSts */\
SignalLengthIsU8Counts_1,    /* EnterSwtSts */\
SignalLengthIsU8Counts_1,    /* HomeSwtSts */\
SignalLengthIsU8Counts_1,    /* MenuReturnSwtSts */\
SignalLengthIsU8Counts_1,    /* CustomSwtSts */\
SignalLengthIsU8Counts_1,    /* IpMenuSwtSts */\
SignalLengthIsU8Counts_1,    /* AdjVolDwnSwtSts */\
SignalLengthIsU8Counts_1,    /* AdjVolUpSwtSts */\
SignalLengthIsU8Counts_1,    /* SeekDwnSwtSts */\
SignalLengthIsU8Counts_1,    /* SeekUpSwtSts */\
SignalLengthIsU8Counts_1,    /* EnterSwtSts_Mmed */\
SignalLengthIsU8Counts_1,    /* VRSwtSts */\
SignalLengthIsU8Counts_1,    /* MuteSwtSts */\
SignalLengthIsU8Counts_1,    /* CustomSwtSts_Mmed */\
SignalLengthIsU8Counts_1,    /* Stat_PwrSv_Lvl */\
SignalLengthIsU8Counts_1,    /* HUD_BrightnessLvl */\
SignalLengthIsU8Counts_1,    /* HUD_HeightLvl */\
SignalLengthIsU8Counts_1,    /* HUD_UIMod */\
SignalLengthIsU8Counts_1,    /* HUD_UIModVld */\
SignalLengthIsU8Counts_1,    /* HUD_SwtSts */\
SignalLengthIsU8Counts_1,    /* BaroPressure */\
SignalLengthIsU8Counts_1,    /* Urea_Level */\
SignalLengthIsU8Counts_2,    /* UreaRemainDist */\
SignalLengthIsU8Counts_1,    /* SCRSysWarnDisplay */\
SignalLengthIsU8Counts_1,    /* SCRSysWarnDisplay_B2 */\
SignalLengthIsU8Counts_1,    /* ACAmbTemp */\
SignalLengthIsU8Counts_1,    /* TrqPrct */\
SignalLengthIsU8Counts_1,    /* PowerPrct */\
SignalLengthIsU8Counts_2,    /* VehLgtAccel */\
SignalLengthIsU8Counts_2,    /* VehLatAccel */\
SignalLengthIsU8Counts_1,    /* VehLgtAccelVld */\
SignalLengthIsU8Counts_1,    /* VehLatAccelVld */\
SignalLengthIsU8Counts_1,    /* EngOilPres */\
SignalLengthIsU8Counts_1,    /* EngOilTemp */\
SignalLengthIsU8Counts_1,    /* LowBeamSts_F_PBOX */\
SignalLengthIsU8Counts_1,    /* LeftLightShowSts */\
}

/*Project Adapt index*/
typedef enum
{
    CA_CFG_Pro_B02 = 0u,
    CA_CFG_Pro_P05 = 1u,
    CA_CFG_Pro_P03 = 2u,
    CA_CFG_Pro_A07 = 3u,
    CA_CFG_Pro_D01 = 4u,
    CA_CFG_Pro_D02 = 5u,
    CA_CFG_Pro_D03 = 6u,
    CA_CFG_Pro_P02 = 7u,
    CA_CFG_Pro_P01 = 8u,
    CA_CFG_Pro_MAXNUM = 9u,
}CA_CFG_u8ProAdaptIndex;

typedef enum
{
    enCASignalInd_DrivingModDis_0x145 = 0u,
    enCASignalInd_DrivingModDis_0x137 = 1u,
    enCASignalInd_ESPBrkLmpCtrl_0x137 = 2u,
    enCASignalInd_BSD_LCA_warningReqRight = 3u,
    enCASignalInd_BSD_LCA_warningReqleft = 4u,
    enCASignalInd_DOW_warningReqRight = 5u,
    enCASignalInd_DOW_warningReqleft = 6u,
    enCASignalInd_IFC_Line01_Type = 7u,
    enCASignalInd_IFC_Line01_Dy = 8u,
    enCASignalInd_IFC_Line01_Curv = 9u,
    enCASignalInd_IFC_Line01_CurvChange = 10u,
    enCASignalInd_IFC_Line02_Type = 11u,
    enCASignalInd_IFC_Line02_Dy = 12u,
    enCASignalInd_IFC_Line02_Curv = 13u,
    enCASignalInd_IFC_Line02_CurvChange = 14u,
    enCASignalInd_IFC_Line03_Type = 15u,
    enCASignalInd_IFC_Line03_Dy = 16u,
    enCASignalInd_IFC_Line03_Curv = 17u,
    enCASignalInd_IFC_Line03_CurvChange = 18u,
    enCASignalInd_IFC_Line04_Type = 19u,
    enCASignalInd_IFC_Line04_Dy = 20u,
    enCASignalInd_IFC_Line04_Curv = 21u,
    enCASignalInd_IFC_Line04_CurvChange = 22u,
    enCASignalInd_IFC_Roadedge01_Type = 23u,
    enCASignalInd_IFC_Roadedge01_Dy = 24u,
    enCASignalInd_IFC_Roadedge01_Curv = 25u,
    enCASignalInd_IFC_Roadedge01_CurvChange = 26u,
    enCASignalInd_IFC_Roadedge02_Type = 27u,
    enCASignalInd_IFC_Roadedge02_Dy = 28u,
    enCASignalInd_IFC_Roadedge02_Curv = 29u,
    enCASignalInd_IFC_Roadedge02_CurvChange = 30u,
    enCASignalInd_IFC_Line01_HeadingAngle = 31u,
    enCASignalInd_IFC_Line02_HeadingAngle = 32u,
    enCASignalInd_IFC_Line03_HeadingAngle = 33u,
    enCASignalInd_IFC_Line04_HeadingAngle = 34u,
    enCASignalInd_IFC_Roadedge01_HeadingAngle = 35u,
    enCASignalInd_IFC_Roadedge02_HeadingAngle = 36u,
    enCASignalInd_ACC_PotentialTgtTyp = 37u,
    enCASignalInd_ACC_PotentialTgtDy = 38u,
    enCASignalInd_ACC_PotentialTgtDx = 39u,
    enCASignalInd_ACC_PotentialTgtHeading = 40u,
    enCASignalInd_ACC_PotentialTgtDetn = 41u,
    enCASignalInd_ACC_RlvTgtTyp = 42u,
    enCASignalInd_ACC_RlvTgtDy = 43u,
    enCASignalInd_ACC_RlvTgtDx = 44u,
    enCASignalInd_ACC_RlvTgtHeading = 45u,
    enCASignalInd_ACC_RlvTgtDetn = 46u,
    enCASignalInd_ACC_LeTgtTyp = 47u,
    enCASignalInd_ACC_LeTgtDy = 48u,
    enCASignalInd_ACC_LeTgtDx = 49u,
    enCASignalInd_ACC_LeTgtHeading = 50u,
    enCASignalInd_ACC_LeTargrtDection = 51u,
    enCASignalInd_ACC_RiTgtTyp = 52u,
    enCASignalInd_ACC_RiTgtDy = 53u,
    enCASignalInd_ACC_RiTgtDx = 54u,
    enCASignalInd_ACC_RiTgtHeading = 55u,
    enCASignalInd_ACC_RiTargrtDetn = 56u,
    enCASignalInd_ACC_LeTgt_02_Typ = 57u,
    enCASignalInd_ACC_LeTgt_02_Dy = 58u,
    enCASignalInd_ACC_LeTgt_02_Dx = 59u,
    enCASignalInd_ACC_LeTargrt_02_Detn = 60u,
    enCASignalInd_ACC_RiTgt_02_Typ = 61u,
    enCASignalInd_ACC_RiTgt_02_Dy = 62u,
    enCASignalInd_ACC_RiTgt_02_Dx = 63u,
    enCASignalInd_ACC_RiTargrt_02_Detn = 64u,
    enCASignalInd_ACC_ModDisp = 65u,
    enCASignalInd_TJA_ICA_ModDisp = 66u,
    enCASignalInd_ACC_TgtObjBarDisp = 67u,
    enCASignalInd_ACC_FctSts = 68u,
    enCASignalInd_HWA_InterSysInfoDisp = 69u,
    enCASignalInd_ACC_InterSysInfoDisp = 70u,
    enCASignalInd_TJA_ICA_InterSysInfoDisp = 71u,
    enCASignalInd_Request_driveoff = 72u,
    enCASignalInd_HWA_ModDisp = 73u,
    enCASignalInd_HWA_LaneChange = 74u,
    enCASignalInd_HWA_LaneChangeReq = 75u,
    enCASignalInd_HWA_Resp = 76u,
    enCASignalInd_ALC_Resp = 77u,
    enCASignalInd_ACC_EgoStatus = 78u,
    enCASignalInd_ACC_SpdSetValue = 79u,
    enCASignalInd_ACC_TimeGapSet = 80u,
    enCASignalInd_ISL_InterSysInfoDisp = 81u,
    enCASignalInd_LSSIntervention = 82u,
    enCASignalInd_TJA_FollowSts = 83u,
    enCASignalInd_IntelligentEvaActSts = 84u,
    enCASignalInd_LaneAvailability = 85u,
    enCASignalInd_FCW_Warn = 86u,
    enCASignalInd_AEB_VehTrig = 87u,
    enCASignalInd_AEB_PedTrig = 88u,
    enCASignalInd_AEB_JABrkTrig = 89u,
    enCASignalInd_ACC_RiTgt_03_Typ = 90u,
    enCASignalInd_ACC_RiTargrt_03_Detn = 91u,
    enCASignalInd_ACC_RiTgt_03_Dx = 92u,
    enCASignalInd_ACC_RiTgt_03_Dy = 93u,
    enCASignalInd_ACC_LeTgt_03_Typ = 94u,
    enCASignalInd_ACC_LeTargrt_03_Detn = 95u,
    enCASignalInd_ACC_LeTgt_03_Dx = 96u,
    enCASignalInd_ACC_LeTgt_03_Dy = 97u,
    enCASignalInd_ACC_PotentialTgt_02_Heading = 98u,
    enCASignalInd_ACC_PotentialTgt_02_Typ = 99u,
    enCASignalInd_ACC_PotentialTgt_02_Detn = 100u,
    enCASignalInd_ACC_PotentialTgt_02_Dx = 101u,
    enCASignalInd_ACC_PotentialTgt_02_Dy = 102u,
    enCASignalInd_FCTA_Warn = 103u,
    enCASignalInd_FCTBTrig = 104u,
    enCASignalInd_SAS_Sts = 105u,
    enCASignalInd_SteerWheelAng = 106u,
    enCASignalInd_SteerWheelAngSign = 107u,
    enCASignalInd_IDC_L2_TurnLightReq = 108u,
    enCASignalInd_HWA_InhibitWarn = 109u,
    enCASignalInd_HWA_WarnInfoDisp = 110u,
    enCASignalInd_MRC_InterSysInfoDisp = 111u,
    enCASignalInd_HWA_ALC_Trig = 112u,
    enCASignalInd_Stop_Mark_Detn = 113u,
    enCASignalInd_Stop_Mark_Dx = 114u,
    enCASignalInd_Zebra_Mark_Detn = 115u,
    enCASignalInd_Zebra_Mark_Dx = 116u,
    enCASignalInd_Grid_Mark_Detn = 117u,
    enCASignalInd_Grid_Mark_Dx = 118u,
    enCASignalInd_IFC_Line01_Source = 119u,
    enCASignalInd_IFC_Line02_Source = 120u,
    enCASignalInd_TSRSpdLim = 121u,
    enCASignalInd_HWA_TakOver_Req = 122u,
    enCASignalInd_AutoSpdSetSwt_Resp = 123u,
    enCASignalInd_NOH_Sts = 124u,
    enCASignalInd_NOH_SysInfoDisplay = 125u,
    enCASignalInd_V2X_RLVW = 126u,
    enCASignalInd_DrvDoorSts = 127u,
    enCASignalInd_BrkPedalSts_BCM = 128u,
    enCASignalInd_DrvDoorLockSts = 129u,
    enCASignalInd_SrPosn_VR_APP = 130u,
    enCASignalInd_PageUpSwtSts = 131u,
    enCASignalInd_PageDwnSwtSts = 132u,
    enCASignalInd_PageLSwtSts = 133u,
    enCASignalInd_PageRSwtSts = 134u,
    enCASignalInd_EnterSwtSts = 135u,
    enCASignalInd_HomeSwtSts = 136u,
    enCASignalInd_MenuReturnSwtSts = 137u,
    enCASignalInd_CustomSwtSts = 138u,
    enCASignalInd_IpMenuSwtSts = 139u,
    enCASignalInd_AdjVolDwnSwtSts = 140u,
    enCASignalInd_AdjVolUpSwtSts = 141u,
    enCASignalInd_SeekDwnSwtSts = 142u,
    enCASignalInd_SeekUpSwtSts = 143u,
    enCASignalInd_EnterSwtSts_Mmed = 144u,
    enCASignalInd_VRSwtSts = 145u,
    enCASignalInd_MuteSwtSts = 146u,
    enCASignalInd_CustomSwtSts_Mmed = 147u,
    enCASignalInd_Stat_PwrSv_Lvl = 148u,
    enCASignalInd_HUD_BrightnessLvl = 149u,
    enCASignalInd_HUD_HeightLvl = 150u,
    enCASignalInd_HUD_UIMod = 151u,
    enCASignalInd_HUD_UIModVld = 152u,
    enCASignalInd_HUD_SwtSts = 153u,
    enCASignalInd_BaroPressure = 154u,
    enCASignalInd_Urea_Level = 155u,
    enCASignalInd_UreaRemainDist = 156u,
    enCASignalInd_SCRSysWarnDisplay = 157u,
    enCASignalInd_SCRSysWarnDisplay_B2 = 158u,
    enCASignalInd_ACAmbTemp = 159u,
    enCASignalInd_TrqPrct = 160u,
    enCASignalInd_PowerPrct = 161u,
    enCASignalInd_VehLgtAccel = 162u,
    enCASignalInd_VehLatAccel = 163u,
    enCASignalInd_VehLgtAccelVld = 164u,
    enCASignalInd_VehLatAccelVld = 165u,
    enCASignalInd_EngOilPres = 166u,
    enCASignalInd_EngOilTemp = 167u,
    enCASignalInd_LowBeamSts_F_PBOX = 168u,
    enCASignalInd_LeftLightShowSts = 169u,
    enCASignalInd_MAXNUM = 170u,
}enCACFGSIGNALINDEX;

typedef enum
{
    enCAMsgInd_ESP2_145 = 0u,
    enCAMsgInd_ESP_FD2_137 = 1u,
    enCAMsgInd_RSDS_FD1_16F = 2u,
    enCAMsgInd_IFC_FD5_19F = 3u,
    enCAMsgInd_IFC_FD6_222 = 4u,
    enCAMsgInd_ACC_FD2_2AB = 5u,
    enCAMsgInd_IFC_FD2_23D = 6u,
    enCAMsgInd_AEB_FD2_227 = 7u,
    enCAMsgInd_CR_FD1_15E = 8u,
    enCAMsgInd_CSA2_A1 = 9u,
    enCAMsgInd_IFC_FD3_2CF = 10u,
    enCAMsgInd_ACC_FD3_2B4 = 11u,
    enCAMsgInd_T_BOX_FD10_2F0 = 12u,
    enCAMsgInd_BCM1_319 = 13u,
    enCAMsgInd_BCM3_345 = 14u,
    enCAMsgInd_BCM12_238 = 15u,
    enCAMsgInd_CSA3_244 = 16u,
    enCAMsgInd_EEM1_2A8 = 17u,
    enCAMsgInd_HUD1_325 = 18u,
    enCAMsgInd_ECM3_371 = 19u,
    enCAMsgInd_ECM16_2D4 = 20u,
    enCAMsgInd_AC2_385 = 21u,
    enCAMsgInd_ECM_PT6_290 = 22u,
    enCAMsgInd_ABM2_245 = 23u,
    enCAMsgInd_ECM24_350 = 24u,
    enCAMsgInd_F_PBOX1_19B = 25u,
    enCAMsgInd_HCM_L2_304 = 26u,
    enCAMsgInd_VCU_FD4_2D6 = 27u,
    enCAMsgInd_ESP1_149 = 28u,
    enCAMsgInd_BMS_FD10_2F6 = 29u,
    enCAMsgInd_OBC_FD2_31F = 30u,
    enCAMsgInd_EVCC1_310 = 31u,
    enCAMsgInd_MAXNUM = 32u,
}enCACFGMSGINDEX;


#if defined SWC_CA_ADAPT_B02
#define CACANSignalRTENUM_DrivingModDis_0x145                    CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_DrivingModDis_0x137                    COMEX_SIGNAL_RX_DRIVINGMODDIS
#define CACANSignalRTENUM_ESPBrkLmpCtrl_0x137                    COMEX_SIGNAL_RX_ESPBRKLMPCTRL
#define CACANSignalRTENUM_BSD_LCA_warningReqRight                COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT
#define CACANSignalRTENUM_BSD_LCA_warningReqleft                 COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT
#define CACANSignalRTENUM_DOW_warningReqRight                    COMEX_SIGNAL_RX_DOW_WARNINGREQRIGHT
#define CACANSignalRTENUM_DOW_warningReqleft                     COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT
#define CACANSignalRTENUM_IFC_Line01_Type                        COMEX_SIGNAL_RX_IFC_LINE01_TYPE
#define CACANSignalRTENUM_IFC_Line01_Dy                          COMEX_SIGNAL_RX_IFC_LINE01_DY
#define CACANSignalRTENUM_IFC_Line01_Curv                        COMEX_SIGNAL_RX_IFC_LINE01_CURV
#define CACANSignalRTENUM_IFC_Line01_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE01_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line02_Type                        COMEX_SIGNAL_RX_IFC_LINE02_TYPE
#define CACANSignalRTENUM_IFC_Line02_Dy                          COMEX_SIGNAL_RX_IFC_LINE02_DY
#define CACANSignalRTENUM_IFC_Line02_Curv                        COMEX_SIGNAL_RX_IFC_LINE02_CURV
#define CACANSignalRTENUM_IFC_Line02_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE02_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line03_Type                        COMEX_SIGNAL_RX_IFC_LINE03_TYPE
#define CACANSignalRTENUM_IFC_Line03_Dy                          COMEX_SIGNAL_RX_IFC_LINE03_DY
#define CACANSignalRTENUM_IFC_Line03_Curv                        COMEX_SIGNAL_RX_IFC_LINE03_CURV
#define CACANSignalRTENUM_IFC_Line03_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE03_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line04_Type                        COMEX_SIGNAL_RX_IFC_LINE04_TYPE
#define CACANSignalRTENUM_IFC_Line04_Dy                          COMEX_SIGNAL_RX_IFC_LINE04_DY
#define CACANSignalRTENUM_IFC_Line04_Curv                        COMEX_SIGNAL_RX_IFC_LINE04_CURV
#define CACANSignalRTENUM_IFC_Line04_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE04_CURVCHANGE
#define CACANSignalRTENUM_IFC_Roadedge01_Type                    COMEX_SIGNAL_RX_IFC_ROADEDGE01_TYPE
#define CACANSignalRTENUM_IFC_Roadedge01_Dy                      COMEX_SIGNAL_RX_IFC_ROADEDGE01_DY
#define CACANSignalRTENUM_IFC_Roadedge01_Curv                    COMEX_SIGNAL_RX_IFC_ROADEDGE01_CURV
#define CACANSignalRTENUM_IFC_Roadedge01_CurvChange              COMEX_SIGNAL_RX_IFC_ROADEDGE01_CURVCHANGE
#define CACANSignalRTENUM_IFC_Roadedge02_Type                    COMEX_SIGNAL_RX_IFC_ROADEDGE02_TYPE
#define CACANSignalRTENUM_IFC_Roadedge02_Dy                      COMEX_SIGNAL_RX_IFC_ROADEDGE02_DY
#define CACANSignalRTENUM_IFC_Roadedge02_Curv                    COMEX_SIGNAL_RX_IFC_ROADEDGE02_CURV
#define CACANSignalRTENUM_IFC_Roadedge02_CurvChange              COMEX_SIGNAL_RX_IFC_ROADEDGE02_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line01_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE01_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line02_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE02_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line03_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE03_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line04_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE04_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Roadedge01_HeadingAngle            COMEX_SIGNAL_RX_IFC_ROADEDGE01_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Roadedge02_HeadingAngle            COMEX_SIGNAL_RX_IFC_ROADEDGE02_HEADINGANGLE
#define CACANSignalRTENUM_ACC_PotentialTgtTyp                    COMEX_SIGNAL_RX_ACC_POTENTIALTGTTYP
#define CACANSignalRTENUM_ACC_PotentialTgtDy                     COMEX_SIGNAL_RX_ACC_POTENTIALTGTDY
#define CACANSignalRTENUM_ACC_PotentialTgtDx                     COMEX_SIGNAL_RX_ACC_POTENTIALTGTDX
#define CACANSignalRTENUM_ACC_PotentialTgtHeading                COMEX_SIGNAL_RX_ACC_POTENTIALTGTHEADING
#define CACANSignalRTENUM_ACC_PotentialTgtDetn                   COMEX_SIGNAL_RX_ACC_POTENTIALTGTDETN
#define CACANSignalRTENUM_ACC_RlvTgtTyp                          COMEX_SIGNAL_RX_ACC_RLVTGTTYP
#define CACANSignalRTENUM_ACC_RlvTgtDy                           COMEX_SIGNAL_RX_ACC_RLVTGTDY
#define CACANSignalRTENUM_ACC_RlvTgtDx                           COMEX_SIGNAL_RX_ACC_RLVTGTDX
#define CACANSignalRTENUM_ACC_RlvTgtHeading                      COMEX_SIGNAL_RX_ACC_RLVTGTHEADING
#define CACANSignalRTENUM_ACC_RlvTgtDetn                         COMEX_SIGNAL_RX_ACC_RLVTGTDETN
#define CACANSignalRTENUM_ACC_LeTgtTyp                           COMEX_SIGNAL_RX_ACC_LETGTTYP
#define CACANSignalRTENUM_ACC_LeTgtDy                            COMEX_SIGNAL_RX_ACC_LETGTDY
#define CACANSignalRTENUM_ACC_LeTgtDx                            COMEX_SIGNAL_RX_ACC_LETGTDX
#define CACANSignalRTENUM_ACC_LeTgtHeading                       COMEX_SIGNAL_RX_ACC_LETGTHEADING
#define CACANSignalRTENUM_ACC_LeTargrtDection                    COMEX_SIGNAL_RX_ACC_LETARGRTDECTION
#define CACANSignalRTENUM_ACC_RiTgtTyp                           COMEX_SIGNAL_RX_ACC_RITGTTYP
#define CACANSignalRTENUM_ACC_RiTgtDy                            COMEX_SIGNAL_RX_ACC_RITGTDY
#define CACANSignalRTENUM_ACC_RiTgtDx                            COMEX_SIGNAL_RX_ACC_RITGTDX
#define CACANSignalRTENUM_ACC_RiTgtHeading                       COMEX_SIGNAL_RX_ACC_RITGTHEADING
#define CACANSignalRTENUM_ACC_RiTargrtDetn                       COMEX_SIGNAL_RX_ACC_RITARGRTDETN
#define CACANSignalRTENUM_ACC_LeTgt_02_Typ                       COMEX_SIGNAL_RX_ACC_LETGT_02_TYP
#define CACANSignalRTENUM_ACC_LeTgt_02_Dy                        COMEX_SIGNAL_RX_ACC_LETGT_02_DY
#define CACANSignalRTENUM_ACC_LeTgt_02_Dx                        COMEX_SIGNAL_RX_ACC_LETGT_02_DX
#define CACANSignalRTENUM_ACC_LeTargrt_02_Detn                   COMEX_SIGNAL_RX_ACC_LETARGRT_02_DETN
#define CACANSignalRTENUM_ACC_RiTgt_02_Typ                       COMEX_SIGNAL_RX_ACC_RITGT_02_TYP
#define CACANSignalRTENUM_ACC_RiTgt_02_Dy                        COMEX_SIGNAL_RX_ACC_RITGT_02_DY
#define CACANSignalRTENUM_ACC_RiTgt_02_Dx                        COMEX_SIGNAL_RX_ACC_RITGT_02_DX
#define CACANSignalRTENUM_ACC_RiTargrt_02_Detn                   COMEX_SIGNAL_RX_ACC_RITARGRT_02_DETN
#define CACANSignalRTENUM_ACC_ModDisp                            COMEX_SIGNAL_RX_ACC_MODDISP
#define CACANSignalRTENUM_TJA_ICA_ModDisp                        COMEX_SIGNAL_RX_TJA_ICA_MODDISP
#define CACANSignalRTENUM_ACC_TgtObjBarDisp                      COMEX_SIGNAL_RX_ACC_TGTOBJBARDISP
#define CACANSignalRTENUM_ACC_FctSts                             COMEX_SIGNAL_RX_ACC_FCTSTS
#define CACANSignalRTENUM_HWA_InterSysInfoDisp                   COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP
#define CACANSignalRTENUM_ACC_InterSysInfoDisp                   COMEX_SIGNAL_RX_ACC_INTERSYSINFODISP
#define CACANSignalRTENUM_TJA_ICA_InterSysInfoDisp               COMEX_SIGNAL_RX_TJA_ICA_INTERSYSINFODISP
#define CACANSignalRTENUM_Request_driveoff                       COMEX_SIGNAL_RX_REQUEST_DRIVEOFF
#define CACANSignalRTENUM_HWA_ModDisp                            COMEX_SIGNAL_RX_HWA_MODDISP
#define CACANSignalRTENUM_HWA_LaneChange                         COMEX_SIGNAL_RX_HWA_LANECHANGE
#define CACANSignalRTENUM_HWA_LaneChangeReq                      COMEX_SIGNAL_RX_HWA_LANECHANGEREQ
#define CACANSignalRTENUM_HWA_Resp                               COMEX_SIGNAL_RX_HWA_RESP
#define CACANSignalRTENUM_ALC_Resp                               COMEX_SIGNAL_RX_ALC_RESP
#define CACANSignalRTENUM_ACC_EgoStatus                          COMEX_SIGNAL_RX_ACC_EGOSTATUS
#define CACANSignalRTENUM_ACC_SpdSetValue                        COMEX_SIGNAL_RX_ACC_SPDSETVALUE
#define CACANSignalRTENUM_ACC_TimeGapSet                         COMEX_SIGNAL_RX_ACC_TIMEGAPSET
#define CACANSignalRTENUM_ISL_InterSysInfoDisp                   COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP
#define CACANSignalRTENUM_LSSIntervention                        COMEX_SIGNAL_RX_LSSINTERVENTION
#define CACANSignalRTENUM_TJA_FollowSts                          COMEX_SIGNAL_RX_TJA_FOLLOWSTS
#define CACANSignalRTENUM_IntelligentEvaActSts                   COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS
#define CACANSignalRTENUM_LaneAvailability                       COMEX_SIGNAL_RX_LANEAVAILABILITY
#define CACANSignalRTENUM_FCW_Warn                               COMEX_SIGNAL_RX_FCW_WARN
#define CACANSignalRTENUM_AEB_VehTrig                            COMEX_SIGNAL_RX_AEB_VEHTRIG
#define CACANSignalRTENUM_AEB_PedTrig                            COMEX_SIGNAL_RX_AEB_PEDTRIG
#define CACANSignalRTENUM_AEB_JABrkTrig                          COMEX_SIGNAL_RX_AEB_JABRKTRIG
#define CACANSignalRTENUM_ACC_RiTgt_03_Typ                       CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_RiTargrt_03_Detn                   CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_RiTgt_03_Dx                        CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_RiTgt_03_Dy                        CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_LeTgt_03_Typ                       CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_LeTargrt_03_Detn                   CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_LeTgt_03_Dx                        CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_LeTgt_03_Dy                        CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Heading            CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Typ                CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Detn               CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Dx                 CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Dy                 CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_FCTA_Warn                              COMEX_SIGNAL_RX_FCTA_WARN
#define CACANSignalRTENUM_FCTBTrig                               COMEX_SIGNAL_RX_FCTBTRIG
#define CACANSignalRTENUM_SAS_Sts                                COMEX_SIGNAL_RX_SAS_STS
#define CACANSignalRTENUM_SteerWheelAng                          COMEX_SIGNAL_RX_STEERWHEELANG
#define CACANSignalRTENUM_SteerWheelAngSign                      COMEX_SIGNAL_RX_STEERWHEELANGSIGN
#define CACANSignalRTENUM_IDC_L2_TurnLightReq                    COMEX_SIGNAL_RX_IDC_L2_TURNLIGHTREQ
#define CACANSignalRTENUM_HWA_InhibitWarn                        CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_HWA_WarnInfoDisp                       CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_MRC_InterSysInfoDisp                   CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_HWA_ALC_Trig                           CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Stop_Mark_Detn                         CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Stop_Mark_Dx                           CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Zebra_Mark_Detn                        CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Zebra_Mark_Dx                          CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Grid_Mark_Detn                         CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Grid_Mark_Dx                           CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_IFC_Line01_Source                      CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_IFC_Line02_Source                      CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_TSRSpdLim                              COMEX_SIGNAL_RX_TSRSPDLIM
#define CACANSignalRTENUM_HWA_TakOver_Req                        CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_AutoSpdSetSwt_Resp                     CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_NOH_Sts                                CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_NOH_SysInfoDisplay                     CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_V2X_RLVW                               CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_DrvDoorSts                             COMEX_SIGNAL_RX_DRVDOORSTS
#define CACANSignalRTENUM_BrkPedalSts_BCM                        COMEX_SIGNAL_RX_BRKPEDALSTS_BCM
#define CACANSignalRTENUM_DrvDoorLockSts                         COMEX_SIGNAL_RX_DRVDOORLOCKSTS
#define CACANSignalRTENUM_SrPosn_VR_APP                          COMEX_SIGNAL_RX_SRPOSN_VR_APP
#define CACANSignalRTENUM_PageUpSwtSts                           COMEX_SIGNAL_RX_PAGEUPSWTSTS
#define CACANSignalRTENUM_PageDwnSwtSts                          COMEX_SIGNAL_RX_PAGEDWNSWTSTS
#define CACANSignalRTENUM_PageLSwtSts                            COMEX_SIGNAL_RX_PAGELSWTSTS
#define CACANSignalRTENUM_PageRSwtSts                            COMEX_SIGNAL_RX_PAGERSWTSTS
#define CACANSignalRTENUM_EnterSwtSts                            COMEX_SIGNAL_RX_ENTERSWTSTS
#define CACANSignalRTENUM_HomeSwtSts                             COMEX_SIGNAL_RX_HOMESWTSTS
#define CACANSignalRTENUM_MenuReturnSwtSts                       COMEX_SIGNAL_RX_MENURETURNSWTSTS
#define CACANSignalRTENUM_CustomSwtSts                           COMEX_SIGNAL_RX_CUSTOMSWTSTS
#define CACANSignalRTENUM_IpMenuSwtSts                           CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_AdjVolDwnSwtSts                        COMEX_SIGNAL_RX_ADJVOLDWNSWTSTS
#define CACANSignalRTENUM_AdjVolUpSwtSts                         COMEX_SIGNAL_RX_ADJVOLUPSWTSTS
#define CACANSignalRTENUM_SeekDwnSwtSts                          COMEX_SIGNAL_RX_SEEKDWNSWTSTS
#define CACANSignalRTENUM_SeekUpSwtSts                           COMEX_SIGNAL_RX_SEEKUPSWTSTS
#define CACANSignalRTENUM_EnterSwtSts_Mmed                       COMEX_SIGNAL_RX_ENTERSWTSTS_MMED
#define CACANSignalRTENUM_VRSwtSts                               COMEX_SIGNAL_RX_VRSWTSTS
#define CACANSignalRTENUM_MuteSwtSts                             COMEX_SIGNAL_RX_MUTESWTSTS
#define CACANSignalRTENUM_CustomSwtSts_Mmed                      COMEX_SIGNAL_RX_CUSTOMSWTSTS_MMED
#define CACANSignalRTENUM_Stat_PwrSv_Lvl                         COMEX_SIGNAL_RX_STAT_PWRSV_LVL
#define CACANSignalRTENUM_HUD_BrightnessLvl                      COMEX_SIGNAL_RX_HUD_BRIGHTNESSLVL
#define CACANSignalRTENUM_HUD_HeightLvl                          COMEX_SIGNAL_RX_HUD_HEIGHTLVL
#define CACANSignalRTENUM_HUD_UIMod                              COMEX_SIGNAL_RX_HUD_UIMOD
#define CACANSignalRTENUM_HUD_UIModVld                           COMEX_SIGNAL_RX_HUD_UIMODVLD
#define CACANSignalRTENUM_HUD_SwtSts                             COMEX_SIGNAL_RX_HUD_SWTSTS
#define CACANSignalRTENUM_BaroPressure                           COMEX_SIGNAL_RX_BAROPRESSURE
#define CACANSignalRTENUM_Urea_Level                             CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_UreaRemainDist                         CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_SCRSysWarnDisplay                      CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_SCRSysWarnDisplay_B2                   CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACAmbTemp                              COMEX_SIGNAL_RX_ACAMBTEMP
#define CACANSignalRTENUM_TrqPrct                                COMEX_SIGNAL_RX_TRQPRCT
#define CACANSignalRTENUM_PowerPrct                              COMEX_SIGNAL_RX_POWERPRCT
#define CACANSignalRTENUM_VehLgtAccel                            COMEX_SIGNAL_RX_VEHLGTACCEL
#define CACANSignalRTENUM_VehLatAccel                            COMEX_SIGNAL_RX_VEHLATACCEL
#define CACANSignalRTENUM_VehLgtAccelVld                         COMEX_SIGNAL_RX_VEHLGTACCELVLD
#define CACANSignalRTENUM_VehLatAccelVld                         COMEX_SIGNAL_RX_VEHLATACCELVLD
#define CACANSignalRTENUM_EngOilPres                             CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_EngOilTemp                             CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_LowBeamSts_F_PBOX                      CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_LeftLightShowSts                       COMEX_SIGNAL_RX_LEFTLIGHTSHOWSTS

#elif defined SWC_CA_ADAPT_P05
#define CACANSignalRTENUM_DrivingModDis_0x145                    COMEX_SIGNAL_RX_DRIVINGMODDIS_0X145
#define CACANSignalRTENUM_DrivingModDis_0x137                    COMEX_SIGNAL_RX_DRIVINGMODDIS_0X137
#define CACANSignalRTENUM_ESPBrkLmpCtrl_0x137                    CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_BSD_LCA_warningReqRight                COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT
#define CACANSignalRTENUM_BSD_LCA_warningReqleft                 COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT
#define CACANSignalRTENUM_DOW_warningReqRight                    COMEX_SIGNAL_RX_DOW_WARNINGREQRIGHT
#define CACANSignalRTENUM_DOW_warningReqleft                     COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT
#define CACANSignalRTENUM_IFC_Line01_Type                        COMEX_SIGNAL_RX_IFC_LINE01_TYPE
#define CACANSignalRTENUM_IFC_Line01_Dy                          COMEX_SIGNAL_RX_IFC_LINE01_DY
#define CACANSignalRTENUM_IFC_Line01_Curv                        COMEX_SIGNAL_RX_IFC_LINE01_CURV
#define CACANSignalRTENUM_IFC_Line01_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE01_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line02_Type                        COMEX_SIGNAL_RX_IFC_LINE02_TYPE
#define CACANSignalRTENUM_IFC_Line02_Dy                          COMEX_SIGNAL_RX_IFC_LINE02_DY
#define CACANSignalRTENUM_IFC_Line02_Curv                        COMEX_SIGNAL_RX_IFC_LINE02_CURV
#define CACANSignalRTENUM_IFC_Line02_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE02_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line03_Type                        COMEX_SIGNAL_RX_IFC_LINE03_TYPE
#define CACANSignalRTENUM_IFC_Line03_Dy                          COMEX_SIGNAL_RX_IFC_LINE03_DY
#define CACANSignalRTENUM_IFC_Line03_Curv                        COMEX_SIGNAL_RX_IFC_LINE03_CURV
#define CACANSignalRTENUM_IFC_Line03_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE03_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line04_Type                        COMEX_SIGNAL_RX_IFC_LINE04_TYPE
#define CACANSignalRTENUM_IFC_Line04_Dy                          COMEX_SIGNAL_RX_IFC_LINE04_DY
#define CACANSignalRTENUM_IFC_Line04_Curv                        COMEX_SIGNAL_RX_IFC_LINE04_CURV
#define CACANSignalRTENUM_IFC_Line04_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE04_CURVCHANGE
#define CACANSignalRTENUM_IFC_Roadedge01_Type                    COMEX_SIGNAL_RX_IFC_ROADEDGE01_TYPE
#define CACANSignalRTENUM_IFC_Roadedge01_Dy                      COMEX_SIGNAL_RX_IFC_ROADEDGE01_DY
#define CACANSignalRTENUM_IFC_Roadedge01_Curv                    COMEX_SIGNAL_RX_IFC_ROADEDGE01_CURV
#define CACANSignalRTENUM_IFC_Roadedge01_CurvChange              COMEX_SIGNAL_RX_IFC_ROADEDGE01_CURVCHANGE
#define CACANSignalRTENUM_IFC_Roadedge02_Type                    COMEX_SIGNAL_RX_IFC_ROADEDGE02_TYPE
#define CACANSignalRTENUM_IFC_Roadedge02_Dy                      COMEX_SIGNAL_RX_IFC_ROADEDGE02_DY
#define CACANSignalRTENUM_IFC_Roadedge02_Curv                    COMEX_SIGNAL_RX_IFC_ROADEDGE02_CURV
#define CACANSignalRTENUM_IFC_Roadedge02_CurvChange              COMEX_SIGNAL_RX_IFC_ROADEDGE02_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line01_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE01_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line02_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE02_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line03_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE03_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line04_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE04_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Roadedge01_HeadingAngle            COMEX_SIGNAL_RX_IFC_ROADEDGE01_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Roadedge02_HeadingAngle            COMEX_SIGNAL_RX_IFC_ROADEDGE02_HEADINGANGLE
#define CACANSignalRTENUM_ACC_PotentialTgtTyp                    COMEX_SIGNAL_RX_ACC_POTENTIALTGTTYP
#define CACANSignalRTENUM_ACC_PotentialTgtDy                     COMEX_SIGNAL_RX_ACC_POTENTIALTGTDY
#define CACANSignalRTENUM_ACC_PotentialTgtDx                     COMEX_SIGNAL_RX_ACC_POTENTIALTGTDX
#define CACANSignalRTENUM_ACC_PotentialTgtHeading                COMEX_SIGNAL_RX_ACC_POTENTIALTGTHEADING
#define CACANSignalRTENUM_ACC_PotentialTgtDetn                   COMEX_SIGNAL_RX_ACC_POTENTIALTGTDETN
#define CACANSignalRTENUM_ACC_RlvTgtTyp                          COMEX_SIGNAL_RX_ACC_RLVTGTTYP
#define CACANSignalRTENUM_ACC_RlvTgtDy                           COMEX_SIGNAL_RX_ACC_RLVTGTDY
#define CACANSignalRTENUM_ACC_RlvTgtDx                           COMEX_SIGNAL_RX_ACC_RLVTGTDX
#define CACANSignalRTENUM_ACC_RlvTgtHeading                      COMEX_SIGNAL_RX_ACC_RLVTGTHEADING
#define CACANSignalRTENUM_ACC_RlvTgtDetn                         COMEX_SIGNAL_RX_ACC_RLVTGTDETN
#define CACANSignalRTENUM_ACC_LeTgtTyp                           COMEX_SIGNAL_RX_ACC_LETGTTYP
#define CACANSignalRTENUM_ACC_LeTgtDy                            COMEX_SIGNAL_RX_ACC_LETGTDY
#define CACANSignalRTENUM_ACC_LeTgtDx                            COMEX_SIGNAL_RX_ACC_LETGTDX
#define CACANSignalRTENUM_ACC_LeTgtHeading                       COMEX_SIGNAL_RX_ACC_LETGTHEADING
#define CACANSignalRTENUM_ACC_LeTargrtDection                    COMEX_SIGNAL_RX_ACC_LETARGRTDECTION
#define CACANSignalRTENUM_ACC_RiTgtTyp                           COMEX_SIGNAL_RX_ACC_RITGTTYP
#define CACANSignalRTENUM_ACC_RiTgtDy                            COMEX_SIGNAL_RX_ACC_RITGTDY
#define CACANSignalRTENUM_ACC_RiTgtDx                            COMEX_SIGNAL_RX_ACC_RITGTDX
#define CACANSignalRTENUM_ACC_RiTgtHeading                       COMEX_SIGNAL_RX_ACC_RITGTHEADING
#define CACANSignalRTENUM_ACC_RiTargrtDetn                       COMEX_SIGNAL_RX_ACC_RITARGRTDETN
#define CACANSignalRTENUM_ACC_LeTgt_02_Typ                       COMEX_SIGNAL_RX_ACC_LETGT_02_TYP
#define CACANSignalRTENUM_ACC_LeTgt_02_Dy                        COMEX_SIGNAL_RX_ACC_LETGT_02_DY
#define CACANSignalRTENUM_ACC_LeTgt_02_Dx                        COMEX_SIGNAL_RX_ACC_LETGT_02_DX
#define CACANSignalRTENUM_ACC_LeTargrt_02_Detn                   COMEX_SIGNAL_RX_ACC_LETARGRT_02_DETN
#define CACANSignalRTENUM_ACC_RiTgt_02_Typ                       COMEX_SIGNAL_RX_ACC_RITGT_02_TYP
#define CACANSignalRTENUM_ACC_RiTgt_02_Dy                        COMEX_SIGNAL_RX_ACC_RITGT_02_DY
#define CACANSignalRTENUM_ACC_RiTgt_02_Dx                        COMEX_SIGNAL_RX_ACC_RITGT_02_DX
#define CACANSignalRTENUM_ACC_RiTargrt_02_Detn                   COMEX_SIGNAL_RX_ACC_RITARGRT_02_DETN
#define CACANSignalRTENUM_ACC_ModDisp                            COMEX_SIGNAL_RX_ACC_MODDISP
#define CACANSignalRTENUM_TJA_ICA_ModDisp                        COMEX_SIGNAL_RX_TJA_ICA_MODDISP
#define CACANSignalRTENUM_ACC_TgtObjBarDisp                      COMEX_SIGNAL_RX_ACC_TGTOBJBARDISP
#define CACANSignalRTENUM_ACC_FctSts                             COMEX_SIGNAL_RX_ACC_FCTSTS
#define CACANSignalRTENUM_HWA_InterSysInfoDisp                   COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP
#define CACANSignalRTENUM_ACC_InterSysInfoDisp                   COMEX_SIGNAL_RX_ACC_INTERSYSINFODISP
#define CACANSignalRTENUM_TJA_ICA_InterSysInfoDisp               COMEX_SIGNAL_RX_TJA_ICA_INTERSYSINFODISP
#define CACANSignalRTENUM_Request_driveoff                       COMEX_SIGNAL_RX_REQUEST_DRIVEOFF
#define CACANSignalRTENUM_HWA_ModDisp                            COMEX_SIGNAL_RX_HWA_MODDISP
#define CACANSignalRTENUM_HWA_LaneChange                         COMEX_SIGNAL_RX_HWA_LANECHANGE
#define CACANSignalRTENUM_HWA_LaneChangeReq                      COMEX_SIGNAL_RX_HWA_LANECHANGEREQ
#define CACANSignalRTENUM_HWA_Resp                               COMEX_SIGNAL_RX_HWA_RESP
#define CACANSignalRTENUM_ALC_Resp                               COMEX_SIGNAL_RX_ALC_RESP
#define CACANSignalRTENUM_ACC_EgoStatus                          COMEX_SIGNAL_RX_ACC_EGOSTATUS
#define CACANSignalRTENUM_ACC_SpdSetValue                        COMEX_SIGNAL_RX_ACC_SPDSETVALUE
#define CACANSignalRTENUM_ACC_TimeGapSet                         COMEX_SIGNAL_RX_ACC_TIMEGAPSET
#define CACANSignalRTENUM_ISL_InterSysInfoDisp                   COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP
#define CACANSignalRTENUM_LSSIntervention                        COMEX_SIGNAL_RX_LSSINTERVENTION
#define CACANSignalRTENUM_TJA_FollowSts                          COMEX_SIGNAL_RX_TJA_FOLLOWSTS
#define CACANSignalRTENUM_IntelligentEvaActSts                   COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS
#define CACANSignalRTENUM_LaneAvailability                       COMEX_SIGNAL_RX_LANEAVAILABILITY
#define CACANSignalRTENUM_FCW_Warn                               COMEX_SIGNAL_RX_FCW_WARN
#define CACANSignalRTENUM_AEB_VehTrig                            COMEX_SIGNAL_RX_AEB_VEHTRIG
#define CACANSignalRTENUM_AEB_PedTrig                            COMEX_SIGNAL_RX_AEB_PEDTRIG
#define CACANSignalRTENUM_AEB_JABrkTrig                          COMEX_SIGNAL_RX_AEB_JABRKTRIG
#define CACANSignalRTENUM_ACC_RiTgt_03_Typ                       CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_RiTargrt_03_Detn                   CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_RiTgt_03_Dx                        CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_RiTgt_03_Dy                        CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_LeTgt_03_Typ                       CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_LeTargrt_03_Detn                   CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_LeTgt_03_Dx                        CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_LeTgt_03_Dy                        CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Heading            CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Typ                CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Detn               CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Dx                 CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Dy                 CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_FCTA_Warn                              COMEX_SIGNAL_RX_FCTA_WARN
#define CACANSignalRTENUM_FCTBTrig                               COMEX_SIGNAL_RX_FCTBTRIG
#define CACANSignalRTENUM_SAS_Sts                                COMEX_SIGNAL_RX_SAS_STS
#define CACANSignalRTENUM_SteerWheelAng                          COMEX_SIGNAL_RX_STEERWHEELANG
#define CACANSignalRTENUM_SteerWheelAngSign                      COMEX_SIGNAL_RX_STEERWHEELANGSIGN
#define CACANSignalRTENUM_IDC_L2_TurnLightReq                    COMEX_SIGNAL_RX_IDC_L2_TURNLIGHTREQ
#define CACANSignalRTENUM_HWA_InhibitWarn                        COMEX_SIGNAL_RX_HWA_INHIBITWARN
#define CACANSignalRTENUM_HWA_WarnInfoDisp                       COMEX_SIGNAL_RX_HWA_WARNINFODISP
#define CACANSignalRTENUM_MRC_InterSysInfoDisp                   CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_HWA_ALC_Trig                           CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Stop_Mark_Detn                         CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Stop_Mark_Dx                           CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Zebra_Mark_Detn                        CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Zebra_Mark_Dx                          CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Grid_Mark_Detn                         CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Grid_Mark_Dx                           CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_IFC_Line01_Source                      COMEX_SIGNAL_RX_IFC_LINE01_SOURCE
#define CACANSignalRTENUM_IFC_Line02_Source                      COMEX_SIGNAL_RX_IFC_LINE02_SOURCE
#define CACANSignalRTENUM_TSRSpdLim                              COMEX_SIGNAL_RX_TSRSPDLIM
#define CACANSignalRTENUM_HWA_TakOver_Req                        COMEX_SIGNAL_RX_HWA_TAKOVER_REQ
#define CACANSignalRTENUM_AutoSpdSetSwt_Resp                     CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_NOH_Sts                                CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_NOH_SysInfoDisplay                     CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_V2X_RLVW                               CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_DrvDoorSts                             COMEX_SIGNAL_RX_DRVDOORSTS
#define CACANSignalRTENUM_BrkPedalSts_BCM                        COMEX_SIGNAL_RX_BRKPEDALSTS_BCM
#define CACANSignalRTENUM_DrvDoorLockSts                         COMEX_SIGNAL_RX_DRVDOORLOCKSTS
#define CACANSignalRTENUM_SrPosn_VR_APP                          COMEX_SIGNAL_RX_SRPOSN_VR_APP
#define CACANSignalRTENUM_PageUpSwtSts                           COMEX_SIGNAL_RX_PAGEUPSWTSTS
#define CACANSignalRTENUM_PageDwnSwtSts                          COMEX_SIGNAL_RX_PAGEDWNSWTSTS
#define CACANSignalRTENUM_PageLSwtSts                            COMEX_SIGNAL_RX_PAGELSWTSTS
#define CACANSignalRTENUM_PageRSwtSts                            COMEX_SIGNAL_RX_PAGERSWTSTS
#define CACANSignalRTENUM_EnterSwtSts                            COMEX_SIGNAL_RX_ENTERSWTSTS
#define CACANSignalRTENUM_HomeSwtSts                             COMEX_SIGNAL_RX_HOMESWTSTS
#define CACANSignalRTENUM_MenuReturnSwtSts                       COMEX_SIGNAL_RX_MENURETURNSWTSTS
#define CACANSignalRTENUM_CustomSwtSts                           COMEX_SIGNAL_RX_CUSTOMSWTSTS
#define CACANSignalRTENUM_IpMenuSwtSts                           CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_AdjVolDwnSwtSts                        COMEX_SIGNAL_RX_ADJVOLDWNSWTSTS
#define CACANSignalRTENUM_AdjVolUpSwtSts                         COMEX_SIGNAL_RX_ADJVOLUPSWTSTS
#define CACANSignalRTENUM_SeekDwnSwtSts                          COMEX_SIGNAL_RX_SEEKDWNSWTSTS
#define CACANSignalRTENUM_SeekUpSwtSts                           COMEX_SIGNAL_RX_SEEKUPSWTSTS
#define CACANSignalRTENUM_EnterSwtSts_Mmed                       COMEX_SIGNAL_RX_ENTERSWTSTS_MMED
#define CACANSignalRTENUM_VRSwtSts                               COMEX_SIGNAL_RX_VRSWTSTS
#define CACANSignalRTENUM_MuteSwtSts                             COMEX_SIGNAL_RX_MUTESWTSTS
#define CACANSignalRTENUM_CustomSwtSts_Mmed                      COMEX_SIGNAL_RX_CUSTOMSWTSTS_MMED
#define CACANSignalRTENUM_Stat_PwrSv_Lvl                         COMEX_SIGNAL_RX_STAT_PWRSV_LVL
#define CACANSignalRTENUM_HUD_BrightnessLvl                      COMEX_SIGNAL_RX_HUD_BRIGHTNESSLVL
#define CACANSignalRTENUM_HUD_HeightLvl                          COMEX_SIGNAL_RX_HUD_HEIGHTLVL
#define CACANSignalRTENUM_HUD_UIMod                              COMEX_SIGNAL_RX_HUD_UIMOD
#define CACANSignalRTENUM_HUD_UIModVld                           COMEX_SIGNAL_RX_HUD_UIMODVLD
#define CACANSignalRTENUM_HUD_SwtSts                             COMEX_SIGNAL_RX_HUD_SWTSTS
#define CACANSignalRTENUM_BaroPressure                           COMEX_SIGNAL_RX_BAROPRESSURE
#define CACANSignalRTENUM_Urea_Level                             COMEX_SIGNAL_RX_UREA_LEVEL
#define CACANSignalRTENUM_UreaRemainDist                         COMEX_SIGNAL_RX_UREAREMAINDIST
#define CACANSignalRTENUM_SCRSysWarnDisplay                      COMEX_SIGNAL_RX_SCRSYSWARNDISPLAY
#define CACANSignalRTENUM_SCRSysWarnDisplay_B2                   COMEX_SIGNAL_RX_SCRSYSWARNDISPLAY_B2
#define CACANSignalRTENUM_ACAmbTemp                              COMEX_SIGNAL_RX_ACAMBTEMP
#define CACANSignalRTENUM_TrqPrct                                CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_PowerPrct                              CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_VehLgtAccel                            COMEX_SIGNAL_RX_VEHLGTACCEL
#define CACANSignalRTENUM_VehLatAccel                            COMEX_SIGNAL_RX_VEHLATACCEL
#define CACANSignalRTENUM_VehLgtAccelVld                         COMEX_SIGNAL_RX_VEHLGTACCELVLD
#define CACANSignalRTENUM_VehLatAccelVld                         COMEX_SIGNAL_RX_VEHLATACCELVLD
#define CACANSignalRTENUM_EngOilPres                             COMEX_SIGNAL_RX_ENGOILPRES
#define CACANSignalRTENUM_EngOilTemp                             COMEX_SIGNAL_RX_ENGOILTEMP
#define CACANSignalRTENUM_LowBeamSts_F_PBOX                      COMEX_SIGNAL_RX_LOWBEAMSTS_F_PBOX
#define CACANSignalRTENUM_LeftLightShowSts                       CACANSignalRTENUM_ProDBCIsNotIncluded

#elif defined SWC_CA_ADAPT_P03
#define CACANSignalRTENUM_DrivingModDis_0x145                    CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_DrivingModDis_0x137                    COMEX_SIGNAL_RX_DRIVINGMODDIS
#define CACANSignalRTENUM_ESPBrkLmpCtrl_0x137                    CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_BSD_LCA_warningReqRight                COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT
#define CACANSignalRTENUM_BSD_LCA_warningReqleft                 COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT
#define CACANSignalRTENUM_DOW_warningReqRight                    COMEX_SIGNAL_RX_DOW_WARNINGREQRIGHT
#define CACANSignalRTENUM_DOW_warningReqleft                     COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT
#define CACANSignalRTENUM_IFC_Line01_Type                        COMEX_SIGNAL_RX_IFC_LINE01_TYPE
#define CACANSignalRTENUM_IFC_Line01_Dy                          COMEX_SIGNAL_RX_IFC_LINE01_DY
#define CACANSignalRTENUM_IFC_Line01_Curv                        COMEX_SIGNAL_RX_IFC_LINE01_CURV
#define CACANSignalRTENUM_IFC_Line01_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE01_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line02_Type                        COMEX_SIGNAL_RX_IFC_LINE02_TYPE
#define CACANSignalRTENUM_IFC_Line02_Dy                          COMEX_SIGNAL_RX_IFC_LINE02_DY
#define CACANSignalRTENUM_IFC_Line02_Curv                        COMEX_SIGNAL_RX_IFC_LINE02_CURV
#define CACANSignalRTENUM_IFC_Line02_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE02_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line03_Type                        COMEX_SIGNAL_RX_IFC_LINE03_TYPE
#define CACANSignalRTENUM_IFC_Line03_Dy                          COMEX_SIGNAL_RX_IFC_LINE03_DY
#define CACANSignalRTENUM_IFC_Line03_Curv                        COMEX_SIGNAL_RX_IFC_LINE03_CURV
#define CACANSignalRTENUM_IFC_Line03_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE03_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line04_Type                        COMEX_SIGNAL_RX_IFC_LINE04_TYPE
#define CACANSignalRTENUM_IFC_Line04_Dy                          COMEX_SIGNAL_RX_IFC_LINE04_DY
#define CACANSignalRTENUM_IFC_Line04_Curv                        COMEX_SIGNAL_RX_IFC_LINE04_CURV
#define CACANSignalRTENUM_IFC_Line04_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE04_CURVCHANGE
#define CACANSignalRTENUM_IFC_Roadedge01_Type                    COMEX_SIGNAL_RX_IFC_ROADEDGE01_TYPE
#define CACANSignalRTENUM_IFC_Roadedge01_Dy                      COMEX_SIGNAL_RX_IFC_ROADEDGE01_DY
#define CACANSignalRTENUM_IFC_Roadedge01_Curv                    COMEX_SIGNAL_RX_IFC_ROADEDGE01_CURV
#define CACANSignalRTENUM_IFC_Roadedge01_CurvChange              COMEX_SIGNAL_RX_IFC_ROADEDGE01_CURVCHANGE
#define CACANSignalRTENUM_IFC_Roadedge02_Type                    COMEX_SIGNAL_RX_IFC_ROADEDGE02_TYPE
#define CACANSignalRTENUM_IFC_Roadedge02_Dy                      COMEX_SIGNAL_RX_IFC_ROADEDGE02_DY
#define CACANSignalRTENUM_IFC_Roadedge02_Curv                    COMEX_SIGNAL_RX_IFC_ROADEDGE02_CURV
#define CACANSignalRTENUM_IFC_Roadedge02_CurvChange              COMEX_SIGNAL_RX_IFC_ROADEDGE02_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line01_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE01_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line02_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE02_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line03_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE03_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line04_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE04_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Roadedge01_HeadingAngle            COMEX_SIGNAL_RX_IFC_ROADEDGE01_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Roadedge02_HeadingAngle            COMEX_SIGNAL_RX_IFC_ROADEDGE02_HEADINGANGLE
#define CACANSignalRTENUM_ACC_PotentialTgtTyp                    COMEX_SIGNAL_RX_ACC_POTENTIALTGTTYP
#define CACANSignalRTENUM_ACC_PotentialTgtDy                     COMEX_SIGNAL_RX_ACC_POTENTIALTGTDY
#define CACANSignalRTENUM_ACC_PotentialTgtDx                     COMEX_SIGNAL_RX_ACC_POTENTIALTGTDX
#define CACANSignalRTENUM_ACC_PotentialTgtHeading                COMEX_SIGNAL_RX_ACC_POTENTIALTGTHEADING
#define CACANSignalRTENUM_ACC_PotentialTgtDetn                   COMEX_SIGNAL_RX_ACC_POTENTIALTGTDETN
#define CACANSignalRTENUM_ACC_RlvTgtTyp                          COMEX_SIGNAL_RX_ACC_RLVTGTTYP
#define CACANSignalRTENUM_ACC_RlvTgtDy                           COMEX_SIGNAL_RX_ACC_RLVTGTDY
#define CACANSignalRTENUM_ACC_RlvTgtDx                           COMEX_SIGNAL_RX_ACC_RLVTGTDX
#define CACANSignalRTENUM_ACC_RlvTgtHeading                      COMEX_SIGNAL_RX_ACC_RLVTGTHEADING
#define CACANSignalRTENUM_ACC_RlvTgtDetn                         COMEX_SIGNAL_RX_ACC_RLVTGTDETN
#define CACANSignalRTENUM_ACC_LeTgtTyp                           COMEX_SIGNAL_RX_ACC_LETGTTYP
#define CACANSignalRTENUM_ACC_LeTgtDy                            COMEX_SIGNAL_RX_ACC_LETGTDY
#define CACANSignalRTENUM_ACC_LeTgtDx                            COMEX_SIGNAL_RX_ACC_LETGTDX
#define CACANSignalRTENUM_ACC_LeTgtHeading                       COMEX_SIGNAL_RX_ACC_LETGTHEADING
#define CACANSignalRTENUM_ACC_LeTargrtDection                    COMEX_SIGNAL_RX_ACC_LETARGRTDECTION
#define CACANSignalRTENUM_ACC_RiTgtTyp                           COMEX_SIGNAL_RX_ACC_RITGTTYP
#define CACANSignalRTENUM_ACC_RiTgtDy                            COMEX_SIGNAL_RX_ACC_RITGTDY
#define CACANSignalRTENUM_ACC_RiTgtDx                            COMEX_SIGNAL_RX_ACC_RITGTDX
#define CACANSignalRTENUM_ACC_RiTgtHeading                       COMEX_SIGNAL_RX_ACC_RITGTHEADING
#define CACANSignalRTENUM_ACC_RiTargrtDetn                       COMEX_SIGNAL_RX_ACC_RITARGRTDETN
#define CACANSignalRTENUM_ACC_LeTgt_02_Typ                       COMEX_SIGNAL_RX_ACC_LETGT_02_TYP
#define CACANSignalRTENUM_ACC_LeTgt_02_Dy                        COMEX_SIGNAL_RX_ACC_LETGT_02_DY
#define CACANSignalRTENUM_ACC_LeTgt_02_Dx                        COMEX_SIGNAL_RX_ACC_LETGT_02_DX
#define CACANSignalRTENUM_ACC_LeTargrt_02_Detn                   COMEX_SIGNAL_RX_ACC_LETARGRT_02_DETN
#define CACANSignalRTENUM_ACC_RiTgt_02_Typ                       COMEX_SIGNAL_RX_ACC_RITGT_02_TYP
#define CACANSignalRTENUM_ACC_RiTgt_02_Dy                        COMEX_SIGNAL_RX_ACC_RITGT_02_DY
#define CACANSignalRTENUM_ACC_RiTgt_02_Dx                        COMEX_SIGNAL_RX_ACC_RITGT_02_DX
#define CACANSignalRTENUM_ACC_RiTargrt_02_Detn                   COMEX_SIGNAL_RX_ACC_RITARGRT_02_DETN
#define CACANSignalRTENUM_ACC_ModDisp                            COMEX_SIGNAL_RX_ACC_MODDISP
#define CACANSignalRTENUM_TJA_ICA_ModDisp                        COMEX_SIGNAL_RX_TJA_ICA_MODDISP
#define CACANSignalRTENUM_ACC_TgtObjBarDisp                      COMEX_SIGNAL_RX_ACC_TGTOBJBARDISP
#define CACANSignalRTENUM_ACC_FctSts                             COMEX_SIGNAL_RX_ACC_FCTSTS
#define CACANSignalRTENUM_HWA_InterSysInfoDisp                   COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP
#define CACANSignalRTENUM_ACC_InterSysInfoDisp                   COMEX_SIGNAL_RX_ACC_INTERSYSINFODISP
#define CACANSignalRTENUM_TJA_ICA_InterSysInfoDisp               COMEX_SIGNAL_RX_TJA_ICA_INTERSYSINFODISP
#define CACANSignalRTENUM_Request_driveoff                       COMEX_SIGNAL_RX_REQUEST_DRIVEOFF
#define CACANSignalRTENUM_HWA_ModDisp                            COMEX_SIGNAL_RX_HWA_MODDISP
#define CACANSignalRTENUM_HWA_LaneChange                         COMEX_SIGNAL_RX_HWA_LANECHANGE
#define CACANSignalRTENUM_HWA_LaneChangeReq                      COMEX_SIGNAL_RX_HWA_LANECHANGEREQ
#define CACANSignalRTENUM_HWA_Resp                               COMEX_SIGNAL_RX_HWA_RESP
#define CACANSignalRTENUM_ALC_Resp                               COMEX_SIGNAL_RX_ALC_RESP
#define CACANSignalRTENUM_ACC_EgoStatus                          COMEX_SIGNAL_RX_ACC_EGOSTATUS
#define CACANSignalRTENUM_ACC_SpdSetValue                        COMEX_SIGNAL_RX_ACC_SPDSETVALUE
#define CACANSignalRTENUM_ACC_TimeGapSet                         COMEX_SIGNAL_RX_ACC_TIMEGAPSET
#define CACANSignalRTENUM_ISL_InterSysInfoDisp                   COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP
#define CACANSignalRTENUM_LSSIntervention                        COMEX_SIGNAL_RX_LSSINTERVENTION
#define CACANSignalRTENUM_TJA_FollowSts                          COMEX_SIGNAL_RX_TJA_FOLLOWSTS
#define CACANSignalRTENUM_IntelligentEvaActSts                   COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS
#define CACANSignalRTENUM_LaneAvailability                       COMEX_SIGNAL_RX_LANEAVAILABILITY
#define CACANSignalRTENUM_FCW_Warn                               COMEX_SIGNAL_RX_FCW_WARN
#define CACANSignalRTENUM_AEB_VehTrig                            COMEX_SIGNAL_RX_AEB_VEHTRIG
#define CACANSignalRTENUM_AEB_PedTrig                            COMEX_SIGNAL_RX_AEB_PEDTRIG
#define CACANSignalRTENUM_AEB_JABrkTrig                          COMEX_SIGNAL_RX_AEB_JABRKTRIG
#define CACANSignalRTENUM_ACC_RiTgt_03_Typ                       COMEX_SIGNAL_RX_ACC_RITGT_03_TYP
#define CACANSignalRTENUM_ACC_RiTargrt_03_Detn                   COMEX_SIGNAL_RX_ACC_RITARGRT_03_DETN
#define CACANSignalRTENUM_ACC_RiTgt_03_Dx                        COMEX_SIGNAL_RX_ACC_RITGT_03_DX
#define CACANSignalRTENUM_ACC_RiTgt_03_Dy                        COMEX_SIGNAL_RX_ACC_RITGT_03_DY
#define CACANSignalRTENUM_ACC_LeTgt_03_Typ                       COMEX_SIGNAL_RX_ACC_LETGT_03_TYP
#define CACANSignalRTENUM_ACC_LeTargrt_03_Detn                   COMEX_SIGNAL_RX_ACC_LETARGRT_03_DETN
#define CACANSignalRTENUM_ACC_LeTgt_03_Dx                        COMEX_SIGNAL_RX_ACC_LETGT_03_DX
#define CACANSignalRTENUM_ACC_LeTgt_03_Dy                        COMEX_SIGNAL_RX_ACC_LETGT_03_DY
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Heading            COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_HEADING
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Typ                COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_TYP
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Detn               COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_DETN
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Dx                 COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_DX
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Dy                 COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_DY
#define CACANSignalRTENUM_FCTA_Warn                              COMEX_SIGNAL_RX_FCTA_WARN
#define CACANSignalRTENUM_FCTBTrig                               COMEX_SIGNAL_RX_FCTBTRIG
#define CACANSignalRTENUM_SAS_Sts                                COMEX_SIGNAL_RX_SAS_STS
#define CACANSignalRTENUM_SteerWheelAng                          COMEX_SIGNAL_RX_STEERWHEELANG
#define CACANSignalRTENUM_SteerWheelAngSign                      COMEX_SIGNAL_RX_STEERWHEELANGSIGN
#define CACANSignalRTENUM_IDC_L2_TurnLightReq                    COMEX_SIGNAL_RX_IDC_L2_TURNLIGHTREQ
#define CACANSignalRTENUM_HWA_InhibitWarn                        COMEX_SIGNAL_RX_HWA_INHIBITWARN
#define CACANSignalRTENUM_HWA_WarnInfoDisp                       COMEX_SIGNAL_RX_HWA_WARNINFODISP
#define CACANSignalRTENUM_MRC_InterSysInfoDisp                   COMEX_SIGNAL_RX_MRC_INTERSYSINFODISP
#define CACANSignalRTENUM_HWA_ALC_Trig                           COMEX_SIGNAL_RX_HWA_ALC_TRIG
#define CACANSignalRTENUM_Stop_Mark_Detn                         COMEX_SIGNAL_RX_STOP_MARK_DETN
#define CACANSignalRTENUM_Stop_Mark_Dx                           COMEX_SIGNAL_RX_STOP_MARK_DX
#define CACANSignalRTENUM_Zebra_Mark_Detn                        COMEX_SIGNAL_RX_ZEBRA_MARK_DETN
#define CACANSignalRTENUM_Zebra_Mark_Dx                          COMEX_SIGNAL_RX_ZEBRA_MARK_DX
#define CACANSignalRTENUM_Grid_Mark_Detn                         COMEX_SIGNAL_RX_GRID_MARK_DETN
#define CACANSignalRTENUM_Grid_Mark_Dx                           COMEX_SIGNAL_RX_GRID_MARK_DX
#define CACANSignalRTENUM_IFC_Line01_Source                      COMEX_SIGNAL_RX_IFC_LINE01_SOURCE
#define CACANSignalRTENUM_IFC_Line02_Source                      COMEX_SIGNAL_RX_IFC_LINE02_SOURCE
#define CACANSignalRTENUM_TSRSpdLim                              COMEX_SIGNAL_RX_TSRSPDLIM
#define CACANSignalRTENUM_HWA_TakOver_Req                        COMEX_SIGNAL_RX_HWA_TAKOVER_REQ
#define CACANSignalRTENUM_AutoSpdSetSwt_Resp                     COMEX_SIGNAL_RX_AUTOSPDSETSWT_RESP
#define CACANSignalRTENUM_NOH_Sts                                COMEX_SIGNAL_RX_NOH_STS
#define CACANSignalRTENUM_NOH_SysInfoDisplay                     COMEX_SIGNAL_RX_NOH_SYSINFODISPLAY
#define CACANSignalRTENUM_V2X_RLVW                               COMEX_SIGNAL_RX_V2X_RLVW
#define CACANSignalRTENUM_DrvDoorSts                             COMEX_SIGNAL_RX_DRVDOORSTS
#define CACANSignalRTENUM_BrkPedalSts_BCM                        COMEX_SIGNAL_RX_BRKPEDALSTS_BCM
#define CACANSignalRTENUM_DrvDoorLockSts                         COMEX_SIGNAL_RX_DRVDOORLOCKSTS
#define CACANSignalRTENUM_SrPosn_VR_APP                          COMEX_SIGNAL_RX_SRPOSN_VR_APP
#define CACANSignalRTENUM_PageUpSwtSts                           COMEX_SIGNAL_RX_PAGEUPSWTSTS
#define CACANSignalRTENUM_PageDwnSwtSts                          COMEX_SIGNAL_RX_PAGEDWNSWTSTS
#define CACANSignalRTENUM_PageLSwtSts                            COMEX_SIGNAL_RX_PAGELSWTSTS
#define CACANSignalRTENUM_PageRSwtSts                            COMEX_SIGNAL_RX_PAGERSWTSTS
#define CACANSignalRTENUM_EnterSwtSts                            COMEX_SIGNAL_RX_ENTERSWTSTS
#define CACANSignalRTENUM_HomeSwtSts                             COMEX_SIGNAL_RX_HOMESWTSTS
#define CACANSignalRTENUM_MenuReturnSwtSts                       COMEX_SIGNAL_RX_MENURETURNSWTSTS
#define CACANSignalRTENUM_CustomSwtSts                           COMEX_SIGNAL_RX_CUSTOMSWTSTS
#define CACANSignalRTENUM_IpMenuSwtSts                           CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_AdjVolDwnSwtSts                        COMEX_SIGNAL_RX_ADJVOLDWNSWTSTS
#define CACANSignalRTENUM_AdjVolUpSwtSts                         COMEX_SIGNAL_RX_ADJVOLUPSWTSTS
#define CACANSignalRTENUM_SeekDwnSwtSts                          COMEX_SIGNAL_RX_SEEKDWNSWTSTS
#define CACANSignalRTENUM_SeekUpSwtSts                           COMEX_SIGNAL_RX_SEEKUPSWTSTS
#define CACANSignalRTENUM_EnterSwtSts_Mmed                       COMEX_SIGNAL_RX_ENTERSWTSTS_MMED
#define CACANSignalRTENUM_VRSwtSts                               COMEX_SIGNAL_RX_VRSWTSTS
#define CACANSignalRTENUM_MuteSwtSts                             COMEX_SIGNAL_RX_MUTESWTSTS
#define CACANSignalRTENUM_CustomSwtSts_Mmed                      COMEX_SIGNAL_RX_CUSTOMSWTSTS_MMED
#define CACANSignalRTENUM_Stat_PwrSv_Lvl                         COMEX_SIGNAL_RX_STAT_PWRSV_LVL
#define CACANSignalRTENUM_HUD_BrightnessLvl                      COMEX_SIGNAL_RX_HUD_BRIGHTNESSLVL
#define CACANSignalRTENUM_HUD_HeightLvl                          COMEX_SIGNAL_RX_HUD_HEIGHTLVL
#define CACANSignalRTENUM_HUD_UIMod                              COMEX_SIGNAL_RX_HUD_UIMOD
#define CACANSignalRTENUM_HUD_UIModVld                           COMEX_SIGNAL_RX_HUD_UIMODVLD
#define CACANSignalRTENUM_HUD_SwtSts                             COMEX_SIGNAL_RX_HUD_SWTSTS
#define CACANSignalRTENUM_BaroPressure                           COMEX_SIGNAL_RX_BAROPRESSURE
#define CACANSignalRTENUM_Urea_Level                             COMEX_SIGNAL_RX_UREA_LEVEL
#define CACANSignalRTENUM_UreaRemainDist                         COMEX_SIGNAL_RX_UREAREMAINDIST
#define CACANSignalRTENUM_SCRSysWarnDisplay                      COMEX_SIGNAL_RX_SCRSYSWARNDISPLAY
#define CACANSignalRTENUM_SCRSysWarnDisplay_B2                   COMEX_SIGNAL_RX_SCRSYSWARNDISPLAY_B2
#define CACANSignalRTENUM_ACAmbTemp                              COMEX_SIGNAL_RX_ACAMBTEMP
#define CACANSignalRTENUM_TrqPrct                                CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_PowerPrct                              CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_VehLgtAccel                            COMEX_SIGNAL_RX_VEHLGTACCEL
#define CACANSignalRTENUM_VehLatAccel                            COMEX_SIGNAL_RX_VEHLATACCEL
#define CACANSignalRTENUM_VehLgtAccelVld                         COMEX_SIGNAL_RX_VEHLGTACCELVLD
#define CACANSignalRTENUM_VehLatAccelVld                         COMEX_SIGNAL_RX_VEHLATACCELVLD
#define CACANSignalRTENUM_EngOilPres                             COMEX_SIGNAL_RX_ENGOILPRES
#define CACANSignalRTENUM_EngOilTemp                             COMEX_SIGNAL_RX_ENGOILTEMP
#define CACANSignalRTENUM_LowBeamSts_F_PBOX                      COMEX_SIGNAL_RX_LOWBEAMSTS_F_PBOX
#define CACANSignalRTENUM_LeftLightShowSts                       CACANSignalRTENUM_ProDBCIsNotIncluded

#elif defined SWC_CA_ADAPT_A07
#define CACANSignalRTENUM_DrivingModDis_0x145                    COMEX_SIGNAL_RX_DRIVINGMODDIS
#define CACANSignalRTENUM_DrivingModDis_0x137                    CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ESPBrkLmpCtrl_0x137                    CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_BSD_LCA_warningReqRight                COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT
#define CACANSignalRTENUM_BSD_LCA_warningReqleft                 COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT
#define CACANSignalRTENUM_DOW_warningReqRight                    COMEX_SIGNAL_RX_DOW_WARNINGREQRIGHT
#define CACANSignalRTENUM_DOW_warningReqleft                     COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT
#define CACANSignalRTENUM_IFC_Line01_Type                        COMEX_SIGNAL_RX_IFC_LINE01_TYPE
#define CACANSignalRTENUM_IFC_Line01_Dy                          COMEX_SIGNAL_RX_IFC_LINE01_DY
#define CACANSignalRTENUM_IFC_Line01_Curv                        COMEX_SIGNAL_RX_IFC_LINE01_CURV
#define CACANSignalRTENUM_IFC_Line01_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE01_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line02_Type                        COMEX_SIGNAL_RX_IFC_LINE02_TYPE
#define CACANSignalRTENUM_IFC_Line02_Dy                          COMEX_SIGNAL_RX_IFC_LINE02_DY
#define CACANSignalRTENUM_IFC_Line02_Curv                        COMEX_SIGNAL_RX_IFC_LINE02_CURV
#define CACANSignalRTENUM_IFC_Line02_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE02_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line03_Type                        COMEX_SIGNAL_RX_IFC_LINE03_TYPE
#define CACANSignalRTENUM_IFC_Line03_Dy                          COMEX_SIGNAL_RX_IFC_LINE03_DY
#define CACANSignalRTENUM_IFC_Line03_Curv                        COMEX_SIGNAL_RX_IFC_LINE03_CURV
#define CACANSignalRTENUM_IFC_Line03_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE03_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line04_Type                        COMEX_SIGNAL_RX_IFC_LINE04_TYPE
#define CACANSignalRTENUM_IFC_Line04_Dy                          COMEX_SIGNAL_RX_IFC_LINE04_DY
#define CACANSignalRTENUM_IFC_Line04_Curv                        COMEX_SIGNAL_RX_IFC_LINE04_CURV
#define CACANSignalRTENUM_IFC_Line04_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE04_CURVCHANGE
#define CACANSignalRTENUM_IFC_Roadedge01_Type                    COMEX_SIGNAL_RX_IFC_ROADEDGE01_TYPE
#define CACANSignalRTENUM_IFC_Roadedge01_Dy                      COMEX_SIGNAL_RX_IFC_ROADEDGE01_DY
#define CACANSignalRTENUM_IFC_Roadedge01_Curv                    COMEX_SIGNAL_RX_IFC_ROADEDGE01_CURV
#define CACANSignalRTENUM_IFC_Roadedge01_CurvChange              COMEX_SIGNAL_RX_IFC_ROADEDGE01_CURVCHANGE
#define CACANSignalRTENUM_IFC_Roadedge02_Type                    COMEX_SIGNAL_RX_IFC_ROADEDGE02_TYPE
#define CACANSignalRTENUM_IFC_Roadedge02_Dy                      COMEX_SIGNAL_RX_IFC_ROADEDGE02_DY
#define CACANSignalRTENUM_IFC_Roadedge02_Curv                    COMEX_SIGNAL_RX_IFC_ROADEDGE02_CURV
#define CACANSignalRTENUM_IFC_Roadedge02_CurvChange              COMEX_SIGNAL_RX_IFC_ROADEDGE02_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line01_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE01_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line02_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE02_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line03_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE03_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line04_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE04_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Roadedge01_HeadingAngle            COMEX_SIGNAL_RX_IFC_ROADEDGE01_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Roadedge02_HeadingAngle            COMEX_SIGNAL_RX_IFC_ROADEDGE02_HEADINGANGLE
#define CACANSignalRTENUM_ACC_PotentialTgtTyp                    COMEX_SIGNAL_RX_ACC_POTENTIALTGTTYP
#define CACANSignalRTENUM_ACC_PotentialTgtDy                     COMEX_SIGNAL_RX_ACC_POTENTIALTGTDY
#define CACANSignalRTENUM_ACC_PotentialTgtDx                     COMEX_SIGNAL_RX_ACC_POTENTIALTGTDX
#define CACANSignalRTENUM_ACC_PotentialTgtHeading                COMEX_SIGNAL_RX_ACC_POTENTIALTGTHEADING
#define CACANSignalRTENUM_ACC_PotentialTgtDetn                   COMEX_SIGNAL_RX_ACC_POTENTIALTGTDETN
#define CACANSignalRTENUM_ACC_RlvTgtTyp                          COMEX_SIGNAL_RX_ACC_RLVTGTTYP
#define CACANSignalRTENUM_ACC_RlvTgtDy                           COMEX_SIGNAL_RX_ACC_RLVTGTDY
#define CACANSignalRTENUM_ACC_RlvTgtDx                           COMEX_SIGNAL_RX_ACC_RLVTGTDX
#define CACANSignalRTENUM_ACC_RlvTgtHeading                      COMEX_SIGNAL_RX_ACC_RLVTGTHEADING
#define CACANSignalRTENUM_ACC_RlvTgtDetn                         COMEX_SIGNAL_RX_ACC_RLVTGTDETN
#define CACANSignalRTENUM_ACC_LeTgtTyp                           COMEX_SIGNAL_RX_ACC_LETGTTYP
#define CACANSignalRTENUM_ACC_LeTgtDy                            COMEX_SIGNAL_RX_ACC_LETGTDY
#define CACANSignalRTENUM_ACC_LeTgtDx                            COMEX_SIGNAL_RX_ACC_LETGTDX
#define CACANSignalRTENUM_ACC_LeTgtHeading                       COMEX_SIGNAL_RX_ACC_LETGTHEADING
#define CACANSignalRTENUM_ACC_LeTargrtDection                    COMEX_SIGNAL_RX_ACC_LETARGRTDECTION
#define CACANSignalRTENUM_ACC_RiTgtTyp                           COMEX_SIGNAL_RX_ACC_RITGTTYP
#define CACANSignalRTENUM_ACC_RiTgtDy                            COMEX_SIGNAL_RX_ACC_RITGTDY
#define CACANSignalRTENUM_ACC_RiTgtDx                            COMEX_SIGNAL_RX_ACC_RITGTDX
#define CACANSignalRTENUM_ACC_RiTgtHeading                       COMEX_SIGNAL_RX_ACC_RITGTHEADING
#define CACANSignalRTENUM_ACC_RiTargrtDetn                       COMEX_SIGNAL_RX_ACC_RITARGRTDETN
#define CACANSignalRTENUM_ACC_LeTgt_02_Typ                       COMEX_SIGNAL_RX_ACC_LETGT_02_TYP
#define CACANSignalRTENUM_ACC_LeTgt_02_Dy                        COMEX_SIGNAL_RX_ACC_LETGT_02_DY
#define CACANSignalRTENUM_ACC_LeTgt_02_Dx                        COMEX_SIGNAL_RX_ACC_LETGT_02_DX
#define CACANSignalRTENUM_ACC_LeTargrt_02_Detn                   COMEX_SIGNAL_RX_ACC_LETARGRT_02_DETN
#define CACANSignalRTENUM_ACC_RiTgt_02_Typ                       COMEX_SIGNAL_RX_ACC_RITGT_02_TYP
#define CACANSignalRTENUM_ACC_RiTgt_02_Dy                        COMEX_SIGNAL_RX_ACC_RITGT_02_DY
#define CACANSignalRTENUM_ACC_RiTgt_02_Dx                        COMEX_SIGNAL_RX_ACC_RITGT_02_DX
#define CACANSignalRTENUM_ACC_RiTargrt_02_Detn                   COMEX_SIGNAL_RX_ACC_RITARGRT_02_DETN
#define CACANSignalRTENUM_ACC_ModDisp                            COMEX_SIGNAL_RX_ACC_MODDISP
#define CACANSignalRTENUM_TJA_ICA_ModDisp                        COMEX_SIGNAL_RX_TJA_ICA_MODDISP
#define CACANSignalRTENUM_ACC_TgtObjBarDisp                      COMEX_SIGNAL_RX_ACC_TGTOBJBARDISP
#define CACANSignalRTENUM_ACC_FctSts                             COMEX_SIGNAL_RX_ACC_FCTSTS
#define CACANSignalRTENUM_HWA_InterSysInfoDisp                   COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP
#define CACANSignalRTENUM_ACC_InterSysInfoDisp                   COMEX_SIGNAL_RX_ACC_INTERSYSINFODISP
#define CACANSignalRTENUM_TJA_ICA_InterSysInfoDisp               COMEX_SIGNAL_RX_TJA_ICA_INTERSYSINFODISP
#define CACANSignalRTENUM_Request_driveoff                       COMEX_SIGNAL_RX_REQUEST_DRIVEOFF
#define CACANSignalRTENUM_HWA_ModDisp                            COMEX_SIGNAL_RX_HWA_MODDISP
#define CACANSignalRTENUM_HWA_LaneChange                         COMEX_SIGNAL_RX_HWA_LANECHANGE
#define CACANSignalRTENUM_HWA_LaneChangeReq                      COMEX_SIGNAL_RX_HWA_LANECHANGEREQ
#define CACANSignalRTENUM_HWA_Resp                               COMEX_SIGNAL_RX_HWA_RESP
#define CACANSignalRTENUM_ALC_Resp                               COMEX_SIGNAL_RX_ALC_RESP
#define CACANSignalRTENUM_ACC_EgoStatus                          COMEX_SIGNAL_RX_ACC_EGOSTATUS
#define CACANSignalRTENUM_ACC_SpdSetValue                        COMEX_SIGNAL_RX_ACC_SPDSETVALUE
#define CACANSignalRTENUM_ACC_TimeGapSet                         COMEX_SIGNAL_RX_ACC_TIMEGAPSET
#define CACANSignalRTENUM_ISL_InterSysInfoDisp                   COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP
#define CACANSignalRTENUM_LSSIntervention                        COMEX_SIGNAL_RX_LSSINTERVENTION
#define CACANSignalRTENUM_TJA_FollowSts                          COMEX_SIGNAL_RX_TJA_FOLLOWSTS
#define CACANSignalRTENUM_IntelligentEvaActSts                   COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS
#define CACANSignalRTENUM_LaneAvailability                       COMEX_SIGNAL_RX_LANEAVAILABILITY
#define CACANSignalRTENUM_FCW_Warn                               COMEX_SIGNAL_RX_FCW_WARN
#define CACANSignalRTENUM_AEB_VehTrig                            COMEX_SIGNAL_RX_AEB_VEHTRIG
#define CACANSignalRTENUM_AEB_PedTrig                            COMEX_SIGNAL_RX_AEB_PEDTRIG
#define CACANSignalRTENUM_AEB_JABrkTrig                          COMEX_SIGNAL_RX_AEB_JABRKTRIG
#define CACANSignalRTENUM_ACC_RiTgt_03_Typ                       CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_RiTargrt_03_Detn                   CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_RiTgt_03_Dx                        CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_RiTgt_03_Dy                        CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_LeTgt_03_Typ                       CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_LeTargrt_03_Detn                   CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_LeTgt_03_Dx                        CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_LeTgt_03_Dy                        CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Heading            CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Typ                CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Detn               CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Dx                 CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Dy                 CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_FCTA_Warn                              COMEX_SIGNAL_RX_FCTA_WARN
#define CACANSignalRTENUM_FCTBTrig                               COMEX_SIGNAL_RX_FCTBTRIG
#define CACANSignalRTENUM_SAS_Sts                                COMEX_SIGNAL_RX_SAS_STS
#define CACANSignalRTENUM_SteerWheelAng                          COMEX_SIGNAL_RX_STEERWHEELANG
#define CACANSignalRTENUM_SteerWheelAngSign                      COMEX_SIGNAL_RX_STEERWHEELANGSIGN
#define CACANSignalRTENUM_IDC_L2_TurnLightReq                    COMEX_SIGNAL_RX_IDC_L2_TURNLIGHTREQ
#define CACANSignalRTENUM_HWA_InhibitWarn                        COMEX_SIGNAL_RX_HWA_INHIBITWARN
#define CACANSignalRTENUM_HWA_WarnInfoDisp                       COMEX_SIGNAL_RX_HWA_WARNINFODISP
#define CACANSignalRTENUM_MRC_InterSysInfoDisp                   CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_HWA_ALC_Trig                           CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Stop_Mark_Detn                         CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Stop_Mark_Dx                           CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Zebra_Mark_Detn                        CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Zebra_Mark_Dx                          CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Grid_Mark_Detn                         CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Grid_Mark_Dx                           CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_IFC_Line01_Source                      COMEX_SIGNAL_RX_IFC_LINE01_SOURCE
#define CACANSignalRTENUM_IFC_Line02_Source                      COMEX_SIGNAL_RX_IFC_LINE02_SOURCE
#define CACANSignalRTENUM_TSRSpdLim                              COMEX_SIGNAL_RX_TSRSPDLIM
#define CACANSignalRTENUM_HWA_TakOver_Req                        COMEX_SIGNAL_RX_HWA_TAKOVER_REQ
#define CACANSignalRTENUM_AutoSpdSetSwt_Resp                     CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_NOH_Sts                                CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_NOH_SysInfoDisplay                     CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_V2X_RLVW                               COMEX_SIGNAL_RX_V2X_RLVW
#define CACANSignalRTENUM_DrvDoorSts                             COMEX_SIGNAL_RX_DRVDOORSTS
#define CACANSignalRTENUM_BrkPedalSts_BCM                        COMEX_SIGNAL_RX_BRKPEDALSTS_BCM
#define CACANSignalRTENUM_DrvDoorLockSts                         COMEX_SIGNAL_RX_DRVDOORLOCKSTS
#define CACANSignalRTENUM_SrPosn_VR_APP                          COMEX_SIGNAL_RX_SRPOSN_VR_APP
#define CACANSignalRTENUM_PageUpSwtSts                           COMEX_SIGNAL_RX_PAGEUPSWTSTS
#define CACANSignalRTENUM_PageDwnSwtSts                          COMEX_SIGNAL_RX_PAGEDWNSWTSTS
#define CACANSignalRTENUM_PageLSwtSts                            COMEX_SIGNAL_RX_PAGELSWTSTS
#define CACANSignalRTENUM_PageRSwtSts                            COMEX_SIGNAL_RX_PAGERSWTSTS
#define CACANSignalRTENUM_EnterSwtSts                            COMEX_SIGNAL_RX_ENTERSWTSTS
#define CACANSignalRTENUM_HomeSwtSts                             COMEX_SIGNAL_RX_HOMESWTSTS
#define CACANSignalRTENUM_MenuReturnSwtSts                       COMEX_SIGNAL_RX_MENURETURNSWTSTS
#define CACANSignalRTENUM_CustomSwtSts                           COMEX_SIGNAL_RX_CUSTOMSWTSTS
#define CACANSignalRTENUM_IpMenuSwtSts                           CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_AdjVolDwnSwtSts                        COMEX_SIGNAL_RX_ADJVOLDWNSWTSTS
#define CACANSignalRTENUM_AdjVolUpSwtSts                         COMEX_SIGNAL_RX_ADJVOLUPSWTSTS
#define CACANSignalRTENUM_SeekDwnSwtSts                          COMEX_SIGNAL_RX_SEEKDWNSWTSTS
#define CACANSignalRTENUM_SeekUpSwtSts                           COMEX_SIGNAL_RX_SEEKUPSWTSTS
#define CACANSignalRTENUM_EnterSwtSts_Mmed                       COMEX_SIGNAL_RX_ENTERSWTSTS_MMED
#define CACANSignalRTENUM_VRSwtSts                               COMEX_SIGNAL_RX_VRSWTSTS
#define CACANSignalRTENUM_MuteSwtSts                             COMEX_SIGNAL_RX_MUTESWTSTS
#define CACANSignalRTENUM_CustomSwtSts_Mmed                      COMEX_SIGNAL_RX_CUSTOMSWTSTS_MMED
#define CACANSignalRTENUM_Stat_PwrSv_Lvl                         COMEX_SIGNAL_RX_STAT_PWRSV_LVL
#define CACANSignalRTENUM_HUD_BrightnessLvl                      COMEX_SIGNAL_RX_HUD_BRIGHTNESSLVL
#define CACANSignalRTENUM_HUD_HeightLvl                          COMEX_SIGNAL_RX_HUD_HEIGHTLVL
#define CACANSignalRTENUM_HUD_UIMod                              COMEX_SIGNAL_RX_HUD_UIMOD
#define CACANSignalRTENUM_HUD_UIModVld                           COMEX_SIGNAL_RX_HUD_UIMODVLD
#define CACANSignalRTENUM_HUD_SwtSts                             COMEX_SIGNAL_RX_HUD_SWTSTS
#define CACANSignalRTENUM_BaroPressure                           COMEX_SIGNAL_RX_BAROPRESSURE
#define CACANSignalRTENUM_Urea_Level                             CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_UreaRemainDist                         CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_SCRSysWarnDisplay                      CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_SCRSysWarnDisplay_B2                   CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACAmbTemp                              COMEX_SIGNAL_RX_ACAMBTEMP
#define CACANSignalRTENUM_TrqPrct                                CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_PowerPrct                              CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_VehLgtAccel                            COMEX_SIGNAL_RX_VEHLGTACCEL
#define CACANSignalRTENUM_VehLatAccel                            COMEX_SIGNAL_RX_VEHLATACCEL
#define CACANSignalRTENUM_VehLgtAccelVld                         COMEX_SIGNAL_RX_VEHLGTACCELVLD
#define CACANSignalRTENUM_VehLatAccelVld                         COMEX_SIGNAL_RX_VEHLATACCELVLD
#define CACANSignalRTENUM_EngOilPres                             CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_EngOilTemp                             CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_LowBeamSts_F_PBOX                      COMEX_SIGNAL_RX_LOWBEAMSTS_F_PBOX
#define CACANSignalRTENUM_LeftLightShowSts                       CACANSignalRTENUM_ProDBCIsNotIncluded

#elif defined SWC_CA_ADAPT_D01
#define CACANSignalRTENUM_DrivingModDis_0x145                    CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_DrivingModDis_0x137                    COMEX_SIGNAL_RX_DRIVINGMODDIS
#define CACANSignalRTENUM_ESPBrkLmpCtrl_0x137                    COMEX_SIGNAL_RX_ESPBRKLMPCTRL
#define CACANSignalRTENUM_BSD_LCA_warningReqRight                COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT
#define CACANSignalRTENUM_BSD_LCA_warningReqleft                 COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT
#define CACANSignalRTENUM_DOW_warningReqRight                    COMEX_SIGNAL_RX_DOW_WARNINGREQRIGHT
#define CACANSignalRTENUM_DOW_warningReqleft                     COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT
#define CACANSignalRTENUM_IFC_Line01_Type                        COMEX_SIGNAL_RX_IFC_LINE01_TYPE
#define CACANSignalRTENUM_IFC_Line01_Dy                          COMEX_SIGNAL_RX_IFC_LINE01_DY
#define CACANSignalRTENUM_IFC_Line01_Curv                        COMEX_SIGNAL_RX_IFC_LINE01_CURV
#define CACANSignalRTENUM_IFC_Line01_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE01_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line02_Type                        COMEX_SIGNAL_RX_IFC_LINE02_TYPE
#define CACANSignalRTENUM_IFC_Line02_Dy                          COMEX_SIGNAL_RX_IFC_LINE02_DY
#define CACANSignalRTENUM_IFC_Line02_Curv                        COMEX_SIGNAL_RX_IFC_LINE02_CURV
#define CACANSignalRTENUM_IFC_Line02_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE02_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line03_Type                        COMEX_SIGNAL_RX_IFC_LINE03_TYPE
#define CACANSignalRTENUM_IFC_Line03_Dy                          COMEX_SIGNAL_RX_IFC_LINE03_DY
#define CACANSignalRTENUM_IFC_Line03_Curv                        COMEX_SIGNAL_RX_IFC_LINE03_CURV
#define CACANSignalRTENUM_IFC_Line03_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE03_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line04_Type                        COMEX_SIGNAL_RX_IFC_LINE04_TYPE
#define CACANSignalRTENUM_IFC_Line04_Dy                          COMEX_SIGNAL_RX_IFC_LINE04_DY
#define CACANSignalRTENUM_IFC_Line04_Curv                        COMEX_SIGNAL_RX_IFC_LINE04_CURV
#define CACANSignalRTENUM_IFC_Line04_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE04_CURVCHANGE
#define CACANSignalRTENUM_IFC_Roadedge01_Type                    COMEX_SIGNAL_RX_IFC_ROADEDGE01_TYPE
#define CACANSignalRTENUM_IFC_Roadedge01_Dy                      COMEX_SIGNAL_RX_IFC_ROADEDGE01_DY
#define CACANSignalRTENUM_IFC_Roadedge01_Curv                    COMEX_SIGNAL_RX_IFC_ROADEDGE01_CURV
#define CACANSignalRTENUM_IFC_Roadedge01_CurvChange              COMEX_SIGNAL_RX_IFC_ROADEDGE01_CURVCHANGE
#define CACANSignalRTENUM_IFC_Roadedge02_Type                    COMEX_SIGNAL_RX_IFC_ROADEDGE02_TYPE
#define CACANSignalRTENUM_IFC_Roadedge02_Dy                      COMEX_SIGNAL_RX_IFC_ROADEDGE02_DY
#define CACANSignalRTENUM_IFC_Roadedge02_Curv                    COMEX_SIGNAL_RX_IFC_ROADEDGE02_CURV
#define CACANSignalRTENUM_IFC_Roadedge02_CurvChange              COMEX_SIGNAL_RX_IFC_ROADEDGE02_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line01_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE01_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line02_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE02_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line03_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE03_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line04_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE04_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Roadedge01_HeadingAngle            COMEX_SIGNAL_RX_IFC_ROADEDGE01_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Roadedge02_HeadingAngle            COMEX_SIGNAL_RX_IFC_ROADEDGE02_HEADINGANGLE
#define CACANSignalRTENUM_ACC_PotentialTgtTyp                    COMEX_SIGNAL_RX_ACC_POTENTIALTGTTYP
#define CACANSignalRTENUM_ACC_PotentialTgtDy                     COMEX_SIGNAL_RX_ACC_POTENTIALTGTDY
#define CACANSignalRTENUM_ACC_PotentialTgtDx                     COMEX_SIGNAL_RX_ACC_POTENTIALTGTDX
#define CACANSignalRTENUM_ACC_PotentialTgtHeading                COMEX_SIGNAL_RX_ACC_POTENTIALTGTHEADING
#define CACANSignalRTENUM_ACC_PotentialTgtDetn                   COMEX_SIGNAL_RX_ACC_POTENTIALTGTDETN
#define CACANSignalRTENUM_ACC_RlvTgtTyp                          COMEX_SIGNAL_RX_ACC_RLVTGTTYP
#define CACANSignalRTENUM_ACC_RlvTgtDy                           COMEX_SIGNAL_RX_ACC_RLVTGTDY
#define CACANSignalRTENUM_ACC_RlvTgtDx                           COMEX_SIGNAL_RX_ACC_RLVTGTDX
#define CACANSignalRTENUM_ACC_RlvTgtHeading                      COMEX_SIGNAL_RX_ACC_RLVTGTHEADING
#define CACANSignalRTENUM_ACC_RlvTgtDetn                         COMEX_SIGNAL_RX_ACC_RLVTGTDETN
#define CACANSignalRTENUM_ACC_LeTgtTyp                           COMEX_SIGNAL_RX_ACC_LETGTTYP
#define CACANSignalRTENUM_ACC_LeTgtDy                            COMEX_SIGNAL_RX_ACC_LETGTDY
#define CACANSignalRTENUM_ACC_LeTgtDx                            COMEX_SIGNAL_RX_ACC_LETGTDX
#define CACANSignalRTENUM_ACC_LeTgtHeading                       COMEX_SIGNAL_RX_ACC_LETGTHEADING
#define CACANSignalRTENUM_ACC_LeTargrtDection                    COMEX_SIGNAL_RX_ACC_LETARGRTDECTION
#define CACANSignalRTENUM_ACC_RiTgtTyp                           COMEX_SIGNAL_RX_ACC_RITGTTYP
#define CACANSignalRTENUM_ACC_RiTgtDy                            COMEX_SIGNAL_RX_ACC_RITGTDY
#define CACANSignalRTENUM_ACC_RiTgtDx                            COMEX_SIGNAL_RX_ACC_RITGTDX
#define CACANSignalRTENUM_ACC_RiTgtHeading                       COMEX_SIGNAL_RX_ACC_RITGTHEADING
#define CACANSignalRTENUM_ACC_RiTargrtDetn                       COMEX_SIGNAL_RX_ACC_RITARGRTDETN
#define CACANSignalRTENUM_ACC_LeTgt_02_Typ                       COMEX_SIGNAL_RX_ACC_LETGT_02_TYP
#define CACANSignalRTENUM_ACC_LeTgt_02_Dy                        COMEX_SIGNAL_RX_ACC_LETGT_02_DY
#define CACANSignalRTENUM_ACC_LeTgt_02_Dx                        COMEX_SIGNAL_RX_ACC_LETGT_02_DX
#define CACANSignalRTENUM_ACC_LeTargrt_02_Detn                   COMEX_SIGNAL_RX_ACC_LETARGRT_02_DETN
#define CACANSignalRTENUM_ACC_RiTgt_02_Typ                       COMEX_SIGNAL_RX_ACC_RITGT_02_TYP
#define CACANSignalRTENUM_ACC_RiTgt_02_Dy                        COMEX_SIGNAL_RX_ACC_RITGT_02_DY
#define CACANSignalRTENUM_ACC_RiTgt_02_Dx                        COMEX_SIGNAL_RX_ACC_RITGT_02_DX
#define CACANSignalRTENUM_ACC_RiTargrt_02_Detn                   COMEX_SIGNAL_RX_ACC_RITARGRT_02_DETN
#define CACANSignalRTENUM_ACC_ModDisp                            COMEX_SIGNAL_RX_ACC_MODDISP
#define CACANSignalRTENUM_TJA_ICA_ModDisp                        COMEX_SIGNAL_RX_TJA_ICA_MODDISP
#define CACANSignalRTENUM_ACC_TgtObjBarDisp                      COMEX_SIGNAL_RX_ACC_TGTOBJBARDISP
#define CACANSignalRTENUM_ACC_FctSts                             COMEX_SIGNAL_RX_ACC_FCTSTS
#define CACANSignalRTENUM_HWA_InterSysInfoDisp                   COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP
#define CACANSignalRTENUM_ACC_InterSysInfoDisp                   COMEX_SIGNAL_RX_ACC_INTERSYSINFODISP
#define CACANSignalRTENUM_TJA_ICA_InterSysInfoDisp               COMEX_SIGNAL_RX_TJA_ICA_INTERSYSINFODISP
#define CACANSignalRTENUM_Request_driveoff                       COMEX_SIGNAL_RX_REQUEST_DRIVEOFF
#define CACANSignalRTENUM_HWA_ModDisp                            COMEX_SIGNAL_RX_HWA_MODDISP
#define CACANSignalRTENUM_HWA_LaneChange                         COMEX_SIGNAL_RX_HWA_LANECHANGE
#define CACANSignalRTENUM_HWA_LaneChangeReq                      COMEX_SIGNAL_RX_HWA_LANECHANGEREQ
#define CACANSignalRTENUM_HWA_Resp                               COMEX_SIGNAL_RX_HWA_RESP
#define CACANSignalRTENUM_ALC_Resp                               COMEX_SIGNAL_RX_ALC_RESP
#define CACANSignalRTENUM_ACC_EgoStatus                          COMEX_SIGNAL_RX_ACC_EGOSTATUS
#define CACANSignalRTENUM_ACC_SpdSetValue                        COMEX_SIGNAL_RX_ACC_SPDSETVALUE
#define CACANSignalRTENUM_ACC_TimeGapSet                         COMEX_SIGNAL_RX_ACC_TIMEGAPSET
#define CACANSignalRTENUM_ISL_InterSysInfoDisp                   COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP
#define CACANSignalRTENUM_LSSIntervention                        COMEX_SIGNAL_RX_LSSINTERVENTION
#define CACANSignalRTENUM_TJA_FollowSts                          COMEX_SIGNAL_RX_TJA_FOLLOWSTS
#define CACANSignalRTENUM_IntelligentEvaActSts                   COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS
#define CACANSignalRTENUM_LaneAvailability                       COMEX_SIGNAL_RX_LANEAVAILABILITY
#define CACANSignalRTENUM_FCW_Warn                               COMEX_SIGNAL_RX_FCW_WARN
#define CACANSignalRTENUM_AEB_VehTrig                            COMEX_SIGNAL_RX_AEB_VEHTRIG
#define CACANSignalRTENUM_AEB_PedTrig                            COMEX_SIGNAL_RX_AEB_PEDTRIG
#define CACANSignalRTENUM_AEB_JABrkTrig                          COMEX_SIGNAL_RX_AEB_JABRKTRIG
#define CACANSignalRTENUM_ACC_RiTgt_03_Typ                       COMEX_SIGNAL_RX_ACC_RITGT_03_TYP
#define CACANSignalRTENUM_ACC_RiTargrt_03_Detn                   COMEX_SIGNAL_RX_ACC_RITARGRT_03_DETN
#define CACANSignalRTENUM_ACC_RiTgt_03_Dx                        COMEX_SIGNAL_RX_ACC_RITGT_03_DX
#define CACANSignalRTENUM_ACC_RiTgt_03_Dy                        COMEX_SIGNAL_RX_ACC_RITGT_03_DY
#define CACANSignalRTENUM_ACC_LeTgt_03_Typ                       COMEX_SIGNAL_RX_ACC_LETGT_03_TYP
#define CACANSignalRTENUM_ACC_LeTargrt_03_Detn                   COMEX_SIGNAL_RX_ACC_LETARGRT_03_DETN
#define CACANSignalRTENUM_ACC_LeTgt_03_Dx                        COMEX_SIGNAL_RX_ACC_LETGT_03_DX
#define CACANSignalRTENUM_ACC_LeTgt_03_Dy                        COMEX_SIGNAL_RX_ACC_LETGT_03_DY
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Heading            COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_HEADING
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Typ                COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_TYP
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Detn               COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_DETN
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Dx                 COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_DX
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Dy                 COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_DY
#define CACANSignalRTENUM_FCTA_Warn                              COMEX_SIGNAL_RX_FCTA_WARN
#define CACANSignalRTENUM_FCTBTrig                               COMEX_SIGNAL_RX_FCTBTRIG
#define CACANSignalRTENUM_SAS_Sts                                COMEX_SIGNAL_RX_SAS_STS
#define CACANSignalRTENUM_SteerWheelAng                          COMEX_SIGNAL_RX_STEERWHEELANG
#define CACANSignalRTENUM_SteerWheelAngSign                      COMEX_SIGNAL_RX_STEERWHEELANGSIGN
#define CACANSignalRTENUM_IDC_L2_TurnLightReq                    COMEX_SIGNAL_RX_IDC_L2_TURNLIGHTREQ
#define CACANSignalRTENUM_HWA_InhibitWarn                        COMEX_SIGNAL_RX_HWA_INHIBITWARN
#define CACANSignalRTENUM_HWA_WarnInfoDisp                       COMEX_SIGNAL_RX_HWA_WARNINFODISP
#define CACANSignalRTENUM_MRC_InterSysInfoDisp                   COMEX_SIGNAL_RX_MRC_INTERSYSINFODISP
#define CACANSignalRTENUM_HWA_ALC_Trig                           COMEX_SIGNAL_RX_HWA_ALC_TRIG
#define CACANSignalRTENUM_Stop_Mark_Detn                         COMEX_SIGNAL_RX_STOP_MARK_DETN
#define CACANSignalRTENUM_Stop_Mark_Dx                           COMEX_SIGNAL_RX_STOP_MARK_DX
#define CACANSignalRTENUM_Zebra_Mark_Detn                        COMEX_SIGNAL_RX_ZEBRA_MARK_DETN
#define CACANSignalRTENUM_Zebra_Mark_Dx                          COMEX_SIGNAL_RX_ZEBRA_MARK_DX
#define CACANSignalRTENUM_Grid_Mark_Detn                         COMEX_SIGNAL_RX_GRID_MARK_DETN
#define CACANSignalRTENUM_Grid_Mark_Dx                           COMEX_SIGNAL_RX_GRID_MARK_DX
#define CACANSignalRTENUM_IFC_Line01_Source                      COMEX_SIGNAL_RX_IFC_LINE01_SOURCE
#define CACANSignalRTENUM_IFC_Line02_Source                      COMEX_SIGNAL_RX_IFC_LINE02_SOURCE
#define CACANSignalRTENUM_TSRSpdLim                              COMEX_SIGNAL_RX_TSRSPDLIM
#define CACANSignalRTENUM_HWA_TakOver_Req                        COMEX_SIGNAL_RX_HWA_TAKOVER_REQ
#define CACANSignalRTENUM_AutoSpdSetSwt_Resp                     COMEX_SIGNAL_RX_AUTOSPDSETSWT_RESP
#define CACANSignalRTENUM_NOH_Sts                                COMEX_SIGNAL_RX_NOH_STS
#define CACANSignalRTENUM_NOH_SysInfoDisplay                     COMEX_SIGNAL_RX_NOH_SYSINFODISPLAY
#define CACANSignalRTENUM_V2X_RLVW                               COMEX_SIGNAL_RX_V2X_RLVW
#define CACANSignalRTENUM_DrvDoorSts                             COMEX_SIGNAL_RX_DRVDOORSTS
#define CACANSignalRTENUM_BrkPedalSts_BCM                        COMEX_SIGNAL_RX_BRKPEDALSTS_BCM
#define CACANSignalRTENUM_DrvDoorLockSts                         COMEX_SIGNAL_RX_DRVDOORLOCKSTS
#define CACANSignalRTENUM_SrPosn_VR_APP                          COMEX_SIGNAL_RX_SRPOSN_VR_APP
#define CACANSignalRTENUM_PageUpSwtSts                           COMEX_SIGNAL_RX_PAGEUPSWTSTS
#define CACANSignalRTENUM_PageDwnSwtSts                          COMEX_SIGNAL_RX_PAGEDWNSWTSTS
#define CACANSignalRTENUM_PageLSwtSts                            COMEX_SIGNAL_RX_PAGELSWTSTS
#define CACANSignalRTENUM_PageRSwtSts                            COMEX_SIGNAL_RX_PAGERSWTSTS
#define CACANSignalRTENUM_EnterSwtSts                            COMEX_SIGNAL_RX_ENTERSWTSTS
#define CACANSignalRTENUM_HomeSwtSts                             COMEX_SIGNAL_RX_HOMESWTSTS
#define CACANSignalRTENUM_MenuReturnSwtSts                       COMEX_SIGNAL_RX_MENURETURNSWTSTS
#define CACANSignalRTENUM_CustomSwtSts                           COMEX_SIGNAL_RX_CUSTOMSWTSTS
#define CACANSignalRTENUM_IpMenuSwtSts                           COMEX_SIGNAL_RX_IPMENUSWTSTS
#define CACANSignalRTENUM_AdjVolDwnSwtSts                        COMEX_SIGNAL_RX_ADJVOLDWNSWTSTS
#define CACANSignalRTENUM_AdjVolUpSwtSts                         COMEX_SIGNAL_RX_ADJVOLUPSWTSTS
#define CACANSignalRTENUM_SeekDwnSwtSts                          COMEX_SIGNAL_RX_SEEKDWNSWTSTS
#define CACANSignalRTENUM_SeekUpSwtSts                           COMEX_SIGNAL_RX_SEEKUPSWTSTS
#define CACANSignalRTENUM_EnterSwtSts_Mmed                       COMEX_SIGNAL_RX_ENTERSWTSTS_MMED
#define CACANSignalRTENUM_VRSwtSts                               COMEX_SIGNAL_RX_VRSWTSTS
#define CACANSignalRTENUM_MuteSwtSts                             COMEX_SIGNAL_RX_MUTESWTSTS
#define CACANSignalRTENUM_CustomSwtSts_Mmed                      COMEX_SIGNAL_RX_CUSTOMSWTSTS_MMED
#define CACANSignalRTENUM_Stat_PwrSv_Lvl                         COMEX_SIGNAL_RX_STAT_PWRSV_LVL
#define CACANSignalRTENUM_HUD_BrightnessLvl                      COMEX_SIGNAL_RX_HUD_BRIGHTNESSLVL
#define CACANSignalRTENUM_HUD_HeightLvl                          COMEX_SIGNAL_RX_HUD_HEIGHTLVL
#define CACANSignalRTENUM_HUD_UIMod                              COMEX_SIGNAL_RX_HUD_UIMOD
#define CACANSignalRTENUM_HUD_UIModVld                           COMEX_SIGNAL_RX_HUD_UIMODVLD
#define CACANSignalRTENUM_HUD_SwtSts                             COMEX_SIGNAL_RX_HUD_SWTSTS
#define CACANSignalRTENUM_BaroPressure                           COMEX_SIGNAL_RX_BAROPRESSURE
#define CACANSignalRTENUM_Urea_Level                             CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_UreaRemainDist                         CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_SCRSysWarnDisplay                      CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_SCRSysWarnDisplay_B2                   CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACAmbTemp                              COMEX_SIGNAL_RX_ACAMBTEMP
#define CACANSignalRTENUM_TrqPrct                                CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_PowerPrct                              CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_VehLgtAccel                            COMEX_SIGNAL_RX_VEHLGTACCEL
#define CACANSignalRTENUM_VehLatAccel                            COMEX_SIGNAL_RX_VEHLATACCEL
#define CACANSignalRTENUM_VehLgtAccelVld                         COMEX_SIGNAL_RX_VEHLGTACCELVLD
#define CACANSignalRTENUM_VehLatAccelVld                         COMEX_SIGNAL_RX_VEHLATACCELVLD
#define CACANSignalRTENUM_EngOilPres                             COMEX_SIGNAL_RX_ENGOILPRES
#define CACANSignalRTENUM_EngOilTemp                             COMEX_SIGNAL_RX_ENGOILTEMP
#define CACANSignalRTENUM_LowBeamSts_F_PBOX                      COMEX_SIGNAL_RX_LOWBEAMSTS_F_PBOX
#define CACANSignalRTENUM_LeftLightShowSts                       CACANSignalRTENUM_ProDBCIsNotIncluded

#elif defined SWC_CA_ADAPT_D02
#define CACANSignalRTENUM_DrivingModDis_0x145                    CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_DrivingModDis_0x137                    COMEX_SIGNAL_RX_DRIVINGMODDIS
#define CACANSignalRTENUM_ESPBrkLmpCtrl_0x137                    COMEX_SIGNAL_RX_ESPBRKLMPCTRL
#define CACANSignalRTENUM_BSD_LCA_warningReqRight                COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT
#define CACANSignalRTENUM_BSD_LCA_warningReqleft                 COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT
#define CACANSignalRTENUM_DOW_warningReqRight                    COMEX_SIGNAL_RX_DOW_WARNINGREQRIGHT
#define CACANSignalRTENUM_DOW_warningReqleft                     COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT
#define CACANSignalRTENUM_IFC_Line01_Type                        COMEX_SIGNAL_RX_IFC_LINE01_TYPE
#define CACANSignalRTENUM_IFC_Line01_Dy                          COMEX_SIGNAL_RX_IFC_LINE01_DY
#define CACANSignalRTENUM_IFC_Line01_Curv                        COMEX_SIGNAL_RX_IFC_LINE01_CURV
#define CACANSignalRTENUM_IFC_Line01_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE01_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line02_Type                        COMEX_SIGNAL_RX_IFC_LINE02_TYPE
#define CACANSignalRTENUM_IFC_Line02_Dy                          COMEX_SIGNAL_RX_IFC_LINE02_DY
#define CACANSignalRTENUM_IFC_Line02_Curv                        COMEX_SIGNAL_RX_IFC_LINE02_CURV
#define CACANSignalRTENUM_IFC_Line02_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE02_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line03_Type                        COMEX_SIGNAL_RX_IFC_LINE03_TYPE
#define CACANSignalRTENUM_IFC_Line03_Dy                          COMEX_SIGNAL_RX_IFC_LINE03_DY
#define CACANSignalRTENUM_IFC_Line03_Curv                        COMEX_SIGNAL_RX_IFC_LINE03_CURV
#define CACANSignalRTENUM_IFC_Line03_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE03_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line04_Type                        COMEX_SIGNAL_RX_IFC_LINE04_TYPE
#define CACANSignalRTENUM_IFC_Line04_Dy                          COMEX_SIGNAL_RX_IFC_LINE04_DY
#define CACANSignalRTENUM_IFC_Line04_Curv                        COMEX_SIGNAL_RX_IFC_LINE04_CURV
#define CACANSignalRTENUM_IFC_Line04_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE04_CURVCHANGE
#define CACANSignalRTENUM_IFC_Roadedge01_Type                    COMEX_SIGNAL_RX_IFC_ROADEDGE01_TYPE
#define CACANSignalRTENUM_IFC_Roadedge01_Dy                      COMEX_SIGNAL_RX_IFC_ROADEDGE01_DY
#define CACANSignalRTENUM_IFC_Roadedge01_Curv                    COMEX_SIGNAL_RX_IFC_ROADEDGE01_CURV
#define CACANSignalRTENUM_IFC_Roadedge01_CurvChange              COMEX_SIGNAL_RX_IFC_ROADEDGE01_CURVCHANGE
#define CACANSignalRTENUM_IFC_Roadedge02_Type                    COMEX_SIGNAL_RX_IFC_ROADEDGE02_TYPE
#define CACANSignalRTENUM_IFC_Roadedge02_Dy                      COMEX_SIGNAL_RX_IFC_ROADEDGE02_DY
#define CACANSignalRTENUM_IFC_Roadedge02_Curv                    COMEX_SIGNAL_RX_IFC_ROADEDGE02_CURV
#define CACANSignalRTENUM_IFC_Roadedge02_CurvChange              COMEX_SIGNAL_RX_IFC_ROADEDGE02_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line01_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE01_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line02_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE02_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line03_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE03_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line04_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE04_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Roadedge01_HeadingAngle            COMEX_SIGNAL_RX_IFC_ROADEDGE01_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Roadedge02_HeadingAngle            COMEX_SIGNAL_RX_IFC_ROADEDGE02_HEADINGANGLE
#define CACANSignalRTENUM_ACC_PotentialTgtTyp                    COMEX_SIGNAL_RX_ACC_POTENTIALTGTTYP
#define CACANSignalRTENUM_ACC_PotentialTgtDy                     COMEX_SIGNAL_RX_ACC_POTENTIALTGTDY
#define CACANSignalRTENUM_ACC_PotentialTgtDx                     COMEX_SIGNAL_RX_ACC_POTENTIALTGTDX
#define CACANSignalRTENUM_ACC_PotentialTgtHeading                COMEX_SIGNAL_RX_ACC_POTENTIALTGTHEADING
#define CACANSignalRTENUM_ACC_PotentialTgtDetn                   COMEX_SIGNAL_RX_ACC_POTENTIALTGTDETN
#define CACANSignalRTENUM_ACC_RlvTgtTyp                          COMEX_SIGNAL_RX_ACC_RLVTGTTYP
#define CACANSignalRTENUM_ACC_RlvTgtDy                           COMEX_SIGNAL_RX_ACC_RLVTGTDY
#define CACANSignalRTENUM_ACC_RlvTgtDx                           COMEX_SIGNAL_RX_ACC_RLVTGTDX
#define CACANSignalRTENUM_ACC_RlvTgtHeading                      COMEX_SIGNAL_RX_ACC_RLVTGTHEADING
#define CACANSignalRTENUM_ACC_RlvTgtDetn                         COMEX_SIGNAL_RX_ACC_RLVTGTDETN
#define CACANSignalRTENUM_ACC_LeTgtTyp                           COMEX_SIGNAL_RX_ACC_LETGTTYP
#define CACANSignalRTENUM_ACC_LeTgtDy                            COMEX_SIGNAL_RX_ACC_LETGTDY
#define CACANSignalRTENUM_ACC_LeTgtDx                            COMEX_SIGNAL_RX_ACC_LETGTDX
#define CACANSignalRTENUM_ACC_LeTgtHeading                       COMEX_SIGNAL_RX_ACC_LETGTHEADING
#define CACANSignalRTENUM_ACC_LeTargrtDection                    COMEX_SIGNAL_RX_ACC_LETARGRTDECTION
#define CACANSignalRTENUM_ACC_RiTgtTyp                           COMEX_SIGNAL_RX_ACC_RITGTTYP
#define CACANSignalRTENUM_ACC_RiTgtDy                            COMEX_SIGNAL_RX_ACC_RITGTDY
#define CACANSignalRTENUM_ACC_RiTgtDx                            COMEX_SIGNAL_RX_ACC_RITGTDX
#define CACANSignalRTENUM_ACC_RiTgtHeading                       COMEX_SIGNAL_RX_ACC_RITGTHEADING
#define CACANSignalRTENUM_ACC_RiTargrtDetn                       COMEX_SIGNAL_RX_ACC_RITARGRTDETN
#define CACANSignalRTENUM_ACC_LeTgt_02_Typ                       COMEX_SIGNAL_RX_ACC_LETGT_02_TYP
#define CACANSignalRTENUM_ACC_LeTgt_02_Dy                        COMEX_SIGNAL_RX_ACC_LETGT_02_DY
#define CACANSignalRTENUM_ACC_LeTgt_02_Dx                        COMEX_SIGNAL_RX_ACC_LETGT_02_DX
#define CACANSignalRTENUM_ACC_LeTargrt_02_Detn                   COMEX_SIGNAL_RX_ACC_LETARGRT_02_DETN
#define CACANSignalRTENUM_ACC_RiTgt_02_Typ                       COMEX_SIGNAL_RX_ACC_RITGT_02_TYP
#define CACANSignalRTENUM_ACC_RiTgt_02_Dy                        COMEX_SIGNAL_RX_ACC_RITGT_02_DY
#define CACANSignalRTENUM_ACC_RiTgt_02_Dx                        COMEX_SIGNAL_RX_ACC_RITGT_02_DX
#define CACANSignalRTENUM_ACC_RiTargrt_02_Detn                   COMEX_SIGNAL_RX_ACC_RITARGRT_02_DETN
#define CACANSignalRTENUM_ACC_ModDisp                            COMEX_SIGNAL_RX_ACC_MODDISP
#define CACANSignalRTENUM_TJA_ICA_ModDisp                        COMEX_SIGNAL_RX_TJA_ICA_MODDISP
#define CACANSignalRTENUM_ACC_TgtObjBarDisp                      COMEX_SIGNAL_RX_ACC_TGTOBJBARDISP
#define CACANSignalRTENUM_ACC_FctSts                             COMEX_SIGNAL_RX_ACC_FCTSTS
#define CACANSignalRTENUM_HWA_InterSysInfoDisp                   COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP
#define CACANSignalRTENUM_ACC_InterSysInfoDisp                   COMEX_SIGNAL_RX_ACC_INTERSYSINFODISP
#define CACANSignalRTENUM_TJA_ICA_InterSysInfoDisp               COMEX_SIGNAL_RX_TJA_ICA_INTERSYSINFODISP
#define CACANSignalRTENUM_Request_driveoff                       COMEX_SIGNAL_RX_REQUEST_DRIVEOFF
#define CACANSignalRTENUM_HWA_ModDisp                            COMEX_SIGNAL_RX_HWA_MODDISP
#define CACANSignalRTENUM_HWA_LaneChange                         COMEX_SIGNAL_RX_HWA_LANECHANGE
#define CACANSignalRTENUM_HWA_LaneChangeReq                      COMEX_SIGNAL_RX_HWA_LANECHANGEREQ
#define CACANSignalRTENUM_HWA_Resp                               COMEX_SIGNAL_RX_HWA_RESP
#define CACANSignalRTENUM_ALC_Resp                               COMEX_SIGNAL_RX_ALC_RESP
#define CACANSignalRTENUM_ACC_EgoStatus                          COMEX_SIGNAL_RX_ACC_EGOSTATUS
#define CACANSignalRTENUM_ACC_SpdSetValue                        COMEX_SIGNAL_RX_ACC_SPDSETVALUE
#define CACANSignalRTENUM_ACC_TimeGapSet                         COMEX_SIGNAL_RX_ACC_TIMEGAPSET
#define CACANSignalRTENUM_ISL_InterSysInfoDisp                   COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP
#define CACANSignalRTENUM_LSSIntervention                        COMEX_SIGNAL_RX_LSSINTERVENTION
#define CACANSignalRTENUM_TJA_FollowSts                          COMEX_SIGNAL_RX_TJA_FOLLOWSTS
#define CACANSignalRTENUM_IntelligentEvaActSts                   COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS
#define CACANSignalRTENUM_LaneAvailability                       COMEX_SIGNAL_RX_LANEAVAILABILITY
#define CACANSignalRTENUM_FCW_Warn                               COMEX_SIGNAL_RX_FCW_WARN
#define CACANSignalRTENUM_AEB_VehTrig                            COMEX_SIGNAL_RX_AEB_VEHTRIG
#define CACANSignalRTENUM_AEB_PedTrig                            COMEX_SIGNAL_RX_AEB_PEDTRIG
#define CACANSignalRTENUM_AEB_JABrkTrig                          COMEX_SIGNAL_RX_AEB_JABRKTRIG
#define CACANSignalRTENUM_ACC_RiTgt_03_Typ                       COMEX_SIGNAL_RX_ACC_RITGT_03_TYP
#define CACANSignalRTENUM_ACC_RiTargrt_03_Detn                   COMEX_SIGNAL_RX_ACC_RITARGRT_03_DETN
#define CACANSignalRTENUM_ACC_RiTgt_03_Dx                        COMEX_SIGNAL_RX_ACC_RITGT_03_DX
#define CACANSignalRTENUM_ACC_RiTgt_03_Dy                        COMEX_SIGNAL_RX_ACC_RITGT_03_DY
#define CACANSignalRTENUM_ACC_LeTgt_03_Typ                       COMEX_SIGNAL_RX_ACC_LETGT_03_TYP
#define CACANSignalRTENUM_ACC_LeTargrt_03_Detn                   COMEX_SIGNAL_RX_ACC_LETARGRT_03_DETN
#define CACANSignalRTENUM_ACC_LeTgt_03_Dx                        COMEX_SIGNAL_RX_ACC_LETGT_03_DX
#define CACANSignalRTENUM_ACC_LeTgt_03_Dy                        COMEX_SIGNAL_RX_ACC_LETGT_03_DY
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Heading            COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_HEADING
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Typ                COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_TYP
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Detn               COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_DETN
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Dx                 COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_DX
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Dy                 COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_DY
#define CACANSignalRTENUM_FCTA_Warn                              COMEX_SIGNAL_RX_FCTA_WARN
#define CACANSignalRTENUM_FCTBTrig                               COMEX_SIGNAL_RX_FCTBTRIG
#define CACANSignalRTENUM_SAS_Sts                                COMEX_SIGNAL_RX_SAS_STS
#define CACANSignalRTENUM_SteerWheelAng                          COMEX_SIGNAL_RX_STEERWHEELANG
#define CACANSignalRTENUM_SteerWheelAngSign                      COMEX_SIGNAL_RX_STEERWHEELANGSIGN
#define CACANSignalRTENUM_IDC_L2_TurnLightReq                    COMEX_SIGNAL_RX_IDC_L2_TURNLIGHTREQ
#define CACANSignalRTENUM_HWA_InhibitWarn                        COMEX_SIGNAL_RX_HWA_INHIBITWARN
#define CACANSignalRTENUM_HWA_WarnInfoDisp                       COMEX_SIGNAL_RX_HWA_WARNINFODISP
#define CACANSignalRTENUM_MRC_InterSysInfoDisp                   COMEX_SIGNAL_RX_MRC_INTERSYSINFODISP
#define CACANSignalRTENUM_HWA_ALC_Trig                           COMEX_SIGNAL_RX_HWA_ALC_TRIG
#define CACANSignalRTENUM_Stop_Mark_Detn                         COMEX_SIGNAL_RX_STOP_MARK_DETN
#define CACANSignalRTENUM_Stop_Mark_Dx                           COMEX_SIGNAL_RX_STOP_MARK_DX
#define CACANSignalRTENUM_Zebra_Mark_Detn                        COMEX_SIGNAL_RX_ZEBRA_MARK_DETN
#define CACANSignalRTENUM_Zebra_Mark_Dx                          COMEX_SIGNAL_RX_ZEBRA_MARK_DX
#define CACANSignalRTENUM_Grid_Mark_Detn                         COMEX_SIGNAL_RX_GRID_MARK_DETN
#define CACANSignalRTENUM_Grid_Mark_Dx                           COMEX_SIGNAL_RX_GRID_MARK_DX
#define CACANSignalRTENUM_IFC_Line01_Source                      COMEX_SIGNAL_RX_IFC_LINE01_SOURCE
#define CACANSignalRTENUM_IFC_Line02_Source                      COMEX_SIGNAL_RX_IFC_LINE02_SOURCE
#define CACANSignalRTENUM_TSRSpdLim                              COMEX_SIGNAL_RX_TSRSPDLIM
#define CACANSignalRTENUM_HWA_TakOver_Req                        COMEX_SIGNAL_RX_HWA_TAKOVER_REQ
#define CACANSignalRTENUM_AutoSpdSetSwt_Resp                     COMEX_SIGNAL_RX_AUTOSPDSETSWT_RESP
#define CACANSignalRTENUM_NOH_Sts                                COMEX_SIGNAL_RX_NOH_STS
#define CACANSignalRTENUM_NOH_SysInfoDisplay                     COMEX_SIGNAL_RX_NOH_SYSINFODISPLAY
#define CACANSignalRTENUM_V2X_RLVW                               COMEX_SIGNAL_RX_V2X_RLVW
#define CACANSignalRTENUM_DrvDoorSts                             COMEX_SIGNAL_RX_DRVDOORSTS
#define CACANSignalRTENUM_BrkPedalSts_BCM                        COMEX_SIGNAL_RX_BRKPEDALSTS_BCM
#define CACANSignalRTENUM_DrvDoorLockSts                         COMEX_SIGNAL_RX_DRVDOORLOCKSTS
#define CACANSignalRTENUM_SrPosn_VR_APP                          COMEX_SIGNAL_RX_SRPOSN_VR_APP
#define CACANSignalRTENUM_PageUpSwtSts                           COMEX_SIGNAL_RX_PAGEUPSWTSTS
#define CACANSignalRTENUM_PageDwnSwtSts                          COMEX_SIGNAL_RX_PAGEDWNSWTSTS
#define CACANSignalRTENUM_PageLSwtSts                            COMEX_SIGNAL_RX_PAGELSWTSTS
#define CACANSignalRTENUM_PageRSwtSts                            COMEX_SIGNAL_RX_PAGERSWTSTS
#define CACANSignalRTENUM_EnterSwtSts                            COMEX_SIGNAL_RX_ENTERSWTSTS
#define CACANSignalRTENUM_HomeSwtSts                             COMEX_SIGNAL_RX_HOMESWTSTS
#define CACANSignalRTENUM_MenuReturnSwtSts                       COMEX_SIGNAL_RX_MENURETURNSWTSTS
#define CACANSignalRTENUM_CustomSwtSts                           COMEX_SIGNAL_RX_CUSTOMSWTSTS
#define CACANSignalRTENUM_IpMenuSwtSts                           COMEX_SIGNAL_RX_IPMENUSWTSTS
#define CACANSignalRTENUM_AdjVolDwnSwtSts                        COMEX_SIGNAL_RX_ADJVOLDWNSWTSTS
#define CACANSignalRTENUM_AdjVolUpSwtSts                         COMEX_SIGNAL_RX_ADJVOLUPSWTSTS
#define CACANSignalRTENUM_SeekDwnSwtSts                          COMEX_SIGNAL_RX_SEEKDWNSWTSTS
#define CACANSignalRTENUM_SeekUpSwtSts                           COMEX_SIGNAL_RX_SEEKUPSWTSTS
#define CACANSignalRTENUM_EnterSwtSts_Mmed                       COMEX_SIGNAL_RX_ENTERSWTSTS_MMED
#define CACANSignalRTENUM_VRSwtSts                               COMEX_SIGNAL_RX_VRSWTSTS
#define CACANSignalRTENUM_MuteSwtSts                             COMEX_SIGNAL_RX_MUTESWTSTS
#define CACANSignalRTENUM_CustomSwtSts_Mmed                      COMEX_SIGNAL_RX_CUSTOMSWTSTS_MMED
#define CACANSignalRTENUM_Stat_PwrSv_Lvl                         COMEX_SIGNAL_RX_STAT_PWRSV_LVL
#define CACANSignalRTENUM_HUD_BrightnessLvl                      COMEX_SIGNAL_RX_HUD_BRIGHTNESSLVL
#define CACANSignalRTENUM_HUD_HeightLvl                          COMEX_SIGNAL_RX_HUD_HEIGHTLVL
#define CACANSignalRTENUM_HUD_UIMod                              COMEX_SIGNAL_RX_HUD_UIMOD
#define CACANSignalRTENUM_HUD_UIModVld                           COMEX_SIGNAL_RX_HUD_UIMODVLD
#define CACANSignalRTENUM_HUD_SwtSts                             COMEX_SIGNAL_RX_HUD_SWTSTS
#define CACANSignalRTENUM_BaroPressure                           COMEX_SIGNAL_RX_BAROPRESSURE
#define CACANSignalRTENUM_Urea_Level                             CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_UreaRemainDist                         CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_SCRSysWarnDisplay                      CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_SCRSysWarnDisplay_B2                   CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACAmbTemp                              COMEX_SIGNAL_RX_ACAMBTEMP
#define CACANSignalRTENUM_TrqPrct                                CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_PowerPrct                              CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_VehLgtAccel                            COMEX_SIGNAL_RX_VEHLGTACCEL
#define CACANSignalRTENUM_VehLatAccel                            COMEX_SIGNAL_RX_VEHLATACCEL
#define CACANSignalRTENUM_VehLgtAccelVld                         COMEX_SIGNAL_RX_VEHLGTACCELVLD
#define CACANSignalRTENUM_VehLatAccelVld                         COMEX_SIGNAL_RX_VEHLATACCELVLD
#define CACANSignalRTENUM_EngOilPres                             COMEX_SIGNAL_RX_ENGOILPRES
#define CACANSignalRTENUM_EngOilTemp                             COMEX_SIGNAL_RX_ENGOILTEMP
#define CACANSignalRTENUM_LowBeamSts_F_PBOX                      COMEX_SIGNAL_RX_LOWBEAMSTS_F_PBOX
#define CACANSignalRTENUM_LeftLightShowSts                       CACANSignalRTENUM_ProDBCIsNotIncluded

#elif defined SWC_CA_ADAPT_D03
#define CACANSignalRTENUM_DrivingModDis_0x145                    CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_DrivingModDis_0x137                    COMEX_SIGNAL_RX_DRIVINGMODDIS
#define CACANSignalRTENUM_ESPBrkLmpCtrl_0x137                    COMEX_SIGNAL_RX_ESPBRKLMPCTRL
#define CACANSignalRTENUM_BSD_LCA_warningReqRight                COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT
#define CACANSignalRTENUM_BSD_LCA_warningReqleft                 COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT
#define CACANSignalRTENUM_DOW_warningReqRight                    COMEX_SIGNAL_RX_DOW_WARNINGREQRIGHT
#define CACANSignalRTENUM_DOW_warningReqleft                     COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT
#define CACANSignalRTENUM_IFC_Line01_Type                        COMEX_SIGNAL_RX_IFC_LINE01_TYPE
#define CACANSignalRTENUM_IFC_Line01_Dy                          COMEX_SIGNAL_RX_IFC_LINE01_DY
#define CACANSignalRTENUM_IFC_Line01_Curv                        COMEX_SIGNAL_RX_IFC_LINE01_CURV
#define CACANSignalRTENUM_IFC_Line01_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE01_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line02_Type                        COMEX_SIGNAL_RX_IFC_LINE02_TYPE
#define CACANSignalRTENUM_IFC_Line02_Dy                          COMEX_SIGNAL_RX_IFC_LINE02_DY
#define CACANSignalRTENUM_IFC_Line02_Curv                        COMEX_SIGNAL_RX_IFC_LINE02_CURV
#define CACANSignalRTENUM_IFC_Line02_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE02_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line03_Type                        COMEX_SIGNAL_RX_IFC_LINE03_TYPE
#define CACANSignalRTENUM_IFC_Line03_Dy                          COMEX_SIGNAL_RX_IFC_LINE03_DY
#define CACANSignalRTENUM_IFC_Line03_Curv                        COMEX_SIGNAL_RX_IFC_LINE03_CURV
#define CACANSignalRTENUM_IFC_Line03_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE03_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line04_Type                        COMEX_SIGNAL_RX_IFC_LINE04_TYPE
#define CACANSignalRTENUM_IFC_Line04_Dy                          COMEX_SIGNAL_RX_IFC_LINE04_DY
#define CACANSignalRTENUM_IFC_Line04_Curv                        COMEX_SIGNAL_RX_IFC_LINE04_CURV
#define CACANSignalRTENUM_IFC_Line04_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE04_CURVCHANGE
#define CACANSignalRTENUM_IFC_Roadedge01_Type                    COMEX_SIGNAL_RX_IFC_ROADEDGE01_TYPE
#define CACANSignalRTENUM_IFC_Roadedge01_Dy                      COMEX_SIGNAL_RX_IFC_ROADEDGE01_DY
#define CACANSignalRTENUM_IFC_Roadedge01_Curv                    COMEX_SIGNAL_RX_IFC_ROADEDGE01_CURV
#define CACANSignalRTENUM_IFC_Roadedge01_CurvChange              COMEX_SIGNAL_RX_IFC_ROADEDGE01_CURVCHANGE
#define CACANSignalRTENUM_IFC_Roadedge02_Type                    COMEX_SIGNAL_RX_IFC_ROADEDGE02_TYPE
#define CACANSignalRTENUM_IFC_Roadedge02_Dy                      COMEX_SIGNAL_RX_IFC_ROADEDGE02_DY
#define CACANSignalRTENUM_IFC_Roadedge02_Curv                    COMEX_SIGNAL_RX_IFC_ROADEDGE02_CURV
#define CACANSignalRTENUM_IFC_Roadedge02_CurvChange              COMEX_SIGNAL_RX_IFC_ROADEDGE02_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line01_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE01_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line02_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE02_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line03_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE03_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line04_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE04_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Roadedge01_HeadingAngle            COMEX_SIGNAL_RX_IFC_ROADEDGE01_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Roadedge02_HeadingAngle            COMEX_SIGNAL_RX_IFC_ROADEDGE02_HEADINGANGLE
#define CACANSignalRTENUM_ACC_PotentialTgtTyp                    COMEX_SIGNAL_RX_ACC_POTENTIALTGTTYP
#define CACANSignalRTENUM_ACC_PotentialTgtDy                     COMEX_SIGNAL_RX_ACC_POTENTIALTGTDY
#define CACANSignalRTENUM_ACC_PotentialTgtDx                     COMEX_SIGNAL_RX_ACC_POTENTIALTGTDX
#define CACANSignalRTENUM_ACC_PotentialTgtHeading                COMEX_SIGNAL_RX_ACC_POTENTIALTGTHEADING
#define CACANSignalRTENUM_ACC_PotentialTgtDetn                   COMEX_SIGNAL_RX_ACC_POTENTIALTGTDETN
#define CACANSignalRTENUM_ACC_RlvTgtTyp                          COMEX_SIGNAL_RX_ACC_RLVTGTTYP
#define CACANSignalRTENUM_ACC_RlvTgtDy                           COMEX_SIGNAL_RX_ACC_RLVTGTDY
#define CACANSignalRTENUM_ACC_RlvTgtDx                           COMEX_SIGNAL_RX_ACC_RLVTGTDX
#define CACANSignalRTENUM_ACC_RlvTgtHeading                      COMEX_SIGNAL_RX_ACC_RLVTGTHEADING
#define CACANSignalRTENUM_ACC_RlvTgtDetn                         COMEX_SIGNAL_RX_ACC_RLVTGTDETN
#define CACANSignalRTENUM_ACC_LeTgtTyp                           COMEX_SIGNAL_RX_ACC_LETGTTYP
#define CACANSignalRTENUM_ACC_LeTgtDy                            COMEX_SIGNAL_RX_ACC_LETGTDY
#define CACANSignalRTENUM_ACC_LeTgtDx                            COMEX_SIGNAL_RX_ACC_LETGTDX
#define CACANSignalRTENUM_ACC_LeTgtHeading                       COMEX_SIGNAL_RX_ACC_LETGTHEADING
#define CACANSignalRTENUM_ACC_LeTargrtDection                    COMEX_SIGNAL_RX_ACC_LETARGRTDECTION
#define CACANSignalRTENUM_ACC_RiTgtTyp                           COMEX_SIGNAL_RX_ACC_RITGTTYP
#define CACANSignalRTENUM_ACC_RiTgtDy                            COMEX_SIGNAL_RX_ACC_RITGTDY
#define CACANSignalRTENUM_ACC_RiTgtDx                            COMEX_SIGNAL_RX_ACC_RITGTDX
#define CACANSignalRTENUM_ACC_RiTgtHeading                       COMEX_SIGNAL_RX_ACC_RITGTHEADING
#define CACANSignalRTENUM_ACC_RiTargrtDetn                       COMEX_SIGNAL_RX_ACC_RITARGRTDETN
#define CACANSignalRTENUM_ACC_LeTgt_02_Typ                       COMEX_SIGNAL_RX_ACC_LETGT_02_TYP
#define CACANSignalRTENUM_ACC_LeTgt_02_Dy                        COMEX_SIGNAL_RX_ACC_LETGT_02_DY
#define CACANSignalRTENUM_ACC_LeTgt_02_Dx                        COMEX_SIGNAL_RX_ACC_LETGT_02_DX
#define CACANSignalRTENUM_ACC_LeTargrt_02_Detn                   COMEX_SIGNAL_RX_ACC_LETARGRT_02_DETN
#define CACANSignalRTENUM_ACC_RiTgt_02_Typ                       COMEX_SIGNAL_RX_ACC_RITGT_02_TYP
#define CACANSignalRTENUM_ACC_RiTgt_02_Dy                        COMEX_SIGNAL_RX_ACC_RITGT_02_DY
#define CACANSignalRTENUM_ACC_RiTgt_02_Dx                        COMEX_SIGNAL_RX_ACC_RITGT_02_DX
#define CACANSignalRTENUM_ACC_RiTargrt_02_Detn                   COMEX_SIGNAL_RX_ACC_RITARGRT_02_DETN
#define CACANSignalRTENUM_ACC_ModDisp                            COMEX_SIGNAL_RX_ACC_MODDISP
#define CACANSignalRTENUM_TJA_ICA_ModDisp                        COMEX_SIGNAL_RX_TJA_ICA_MODDISP
#define CACANSignalRTENUM_ACC_TgtObjBarDisp                      COMEX_SIGNAL_RX_ACC_TGTOBJBARDISP
#define CACANSignalRTENUM_ACC_FctSts                             COMEX_SIGNAL_RX_ACC_FCTSTS
#define CACANSignalRTENUM_HWA_InterSysInfoDisp                   COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP
#define CACANSignalRTENUM_ACC_InterSysInfoDisp                   COMEX_SIGNAL_RX_ACC_INTERSYSINFODISP
#define CACANSignalRTENUM_TJA_ICA_InterSysInfoDisp               COMEX_SIGNAL_RX_TJA_ICA_INTERSYSINFODISP
#define CACANSignalRTENUM_Request_driveoff                       COMEX_SIGNAL_RX_REQUEST_DRIVEOFF
#define CACANSignalRTENUM_HWA_ModDisp                            COMEX_SIGNAL_RX_HWA_MODDISP
#define CACANSignalRTENUM_HWA_LaneChange                         COMEX_SIGNAL_RX_HWA_LANECHANGE
#define CACANSignalRTENUM_HWA_LaneChangeReq                      COMEX_SIGNAL_RX_HWA_LANECHANGEREQ
#define CACANSignalRTENUM_HWA_Resp                               COMEX_SIGNAL_RX_HWA_RESP
#define CACANSignalRTENUM_ALC_Resp                               COMEX_SIGNAL_RX_ALC_RESP
#define CACANSignalRTENUM_ACC_EgoStatus                          COMEX_SIGNAL_RX_ACC_EGOSTATUS
#define CACANSignalRTENUM_ACC_SpdSetValue                        COMEX_SIGNAL_RX_ACC_SPDSETVALUE
#define CACANSignalRTENUM_ACC_TimeGapSet                         COMEX_SIGNAL_RX_ACC_TIMEGAPSET
#define CACANSignalRTENUM_ISL_InterSysInfoDisp                   COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP
#define CACANSignalRTENUM_LSSIntervention                        COMEX_SIGNAL_RX_LSSINTERVENTION
#define CACANSignalRTENUM_TJA_FollowSts                          COMEX_SIGNAL_RX_TJA_FOLLOWSTS
#define CACANSignalRTENUM_IntelligentEvaActSts                   COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS
#define CACANSignalRTENUM_LaneAvailability                       COMEX_SIGNAL_RX_LANEAVAILABILITY
#define CACANSignalRTENUM_FCW_Warn                               COMEX_SIGNAL_RX_FCW_WARN
#define CACANSignalRTENUM_AEB_VehTrig                            COMEX_SIGNAL_RX_AEB_VEHTRIG
#define CACANSignalRTENUM_AEB_PedTrig                            COMEX_SIGNAL_RX_AEB_PEDTRIG
#define CACANSignalRTENUM_AEB_JABrkTrig                          COMEX_SIGNAL_RX_AEB_JABRKTRIG
#define CACANSignalRTENUM_ACC_RiTgt_03_Typ                       COMEX_SIGNAL_RX_ACC_RITGT_03_TYP
#define CACANSignalRTENUM_ACC_RiTargrt_03_Detn                   COMEX_SIGNAL_RX_ACC_RITARGRT_03_DETN
#define CACANSignalRTENUM_ACC_RiTgt_03_Dx                        COMEX_SIGNAL_RX_ACC_RITGT_03_DX
#define CACANSignalRTENUM_ACC_RiTgt_03_Dy                        COMEX_SIGNAL_RX_ACC_RITGT_03_DY
#define CACANSignalRTENUM_ACC_LeTgt_03_Typ                       COMEX_SIGNAL_RX_ACC_LETGT_03_TYP
#define CACANSignalRTENUM_ACC_LeTargrt_03_Detn                   COMEX_SIGNAL_RX_ACC_LETARGRT_03_DETN
#define CACANSignalRTENUM_ACC_LeTgt_03_Dx                        COMEX_SIGNAL_RX_ACC_LETGT_03_DX
#define CACANSignalRTENUM_ACC_LeTgt_03_Dy                        COMEX_SIGNAL_RX_ACC_LETGT_03_DY
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Heading            COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_HEADING
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Typ                COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_TYP
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Detn               COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_DETN
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Dx                 COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_DX
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Dy                 COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_DY
#define CACANSignalRTENUM_FCTA_Warn                              COMEX_SIGNAL_RX_FCTA_WARN
#define CACANSignalRTENUM_FCTBTrig                               COMEX_SIGNAL_RX_FCTBTRIG
#define CACANSignalRTENUM_SAS_Sts                                COMEX_SIGNAL_RX_SAS_STS
#define CACANSignalRTENUM_SteerWheelAng                          COMEX_SIGNAL_RX_STEERWHEELANG
#define CACANSignalRTENUM_SteerWheelAngSign                      COMEX_SIGNAL_RX_STEERWHEELANGSIGN
#define CACANSignalRTENUM_IDC_L2_TurnLightReq                    COMEX_SIGNAL_RX_IDC_L2_TURNLIGHTREQ
#define CACANSignalRTENUM_HWA_InhibitWarn                        COMEX_SIGNAL_RX_HWA_INHIBITWARN
#define CACANSignalRTENUM_HWA_WarnInfoDisp                       COMEX_SIGNAL_RX_HWA_WARNINFODISP
#define CACANSignalRTENUM_MRC_InterSysInfoDisp                   COMEX_SIGNAL_RX_MRC_INTERSYSINFODISP
#define CACANSignalRTENUM_HWA_ALC_Trig                           COMEX_SIGNAL_RX_HWA_ALC_TRIG
#define CACANSignalRTENUM_Stop_Mark_Detn                         COMEX_SIGNAL_RX_STOP_MARK_DETN
#define CACANSignalRTENUM_Stop_Mark_Dx                           COMEX_SIGNAL_RX_STOP_MARK_DX
#define CACANSignalRTENUM_Zebra_Mark_Detn                        COMEX_SIGNAL_RX_ZEBRA_MARK_DETN
#define CACANSignalRTENUM_Zebra_Mark_Dx                          COMEX_SIGNAL_RX_ZEBRA_MARK_DX
#define CACANSignalRTENUM_Grid_Mark_Detn                         COMEX_SIGNAL_RX_GRID_MARK_DETN
#define CACANSignalRTENUM_Grid_Mark_Dx                           COMEX_SIGNAL_RX_GRID_MARK_DX
#define CACANSignalRTENUM_IFC_Line01_Source                      COMEX_SIGNAL_RX_IFC_LINE01_SOURCE
#define CACANSignalRTENUM_IFC_Line02_Source                      COMEX_SIGNAL_RX_IFC_LINE02_SOURCE
#define CACANSignalRTENUM_TSRSpdLim                              COMEX_SIGNAL_RX_TSRSPDLIM
#define CACANSignalRTENUM_HWA_TakOver_Req                        COMEX_SIGNAL_RX_HWA_TAKOVER_REQ
#define CACANSignalRTENUM_AutoSpdSetSwt_Resp                     COMEX_SIGNAL_RX_AUTOSPDSETSWT_RESP
#define CACANSignalRTENUM_NOH_Sts                                COMEX_SIGNAL_RX_NOH_STS
#define CACANSignalRTENUM_NOH_SysInfoDisplay                     COMEX_SIGNAL_RX_NOH_SYSINFODISPLAY
#define CACANSignalRTENUM_V2X_RLVW                               COMEX_SIGNAL_RX_V2X_RLVW
#define CACANSignalRTENUM_DrvDoorSts                             COMEX_SIGNAL_RX_DRVDOORSTS
#define CACANSignalRTENUM_BrkPedalSts_BCM                        COMEX_SIGNAL_RX_BRKPEDALSTS_BCM
#define CACANSignalRTENUM_DrvDoorLockSts                         COMEX_SIGNAL_RX_DRVDOORLOCKSTS
#define CACANSignalRTENUM_SrPosn_VR_APP                          COMEX_SIGNAL_RX_SRPOSN_VR_APP
#define CACANSignalRTENUM_PageUpSwtSts                           COMEX_SIGNAL_RX_PAGEUPSWTSTS
#define CACANSignalRTENUM_PageDwnSwtSts                          COMEX_SIGNAL_RX_PAGEDWNSWTSTS
#define CACANSignalRTENUM_PageLSwtSts                            COMEX_SIGNAL_RX_PAGELSWTSTS
#define CACANSignalRTENUM_PageRSwtSts                            COMEX_SIGNAL_RX_PAGERSWTSTS
#define CACANSignalRTENUM_EnterSwtSts                            COMEX_SIGNAL_RX_ENTERSWTSTS
#define CACANSignalRTENUM_HomeSwtSts                             COMEX_SIGNAL_RX_HOMESWTSTS
#define CACANSignalRTENUM_MenuReturnSwtSts                       COMEX_SIGNAL_RX_MENURETURNSWTSTS
#define CACANSignalRTENUM_CustomSwtSts                           COMEX_SIGNAL_RX_CUSTOMSWTSTS
#define CACANSignalRTENUM_IpMenuSwtSts                           COMEX_SIGNAL_RX_IPMENUSWTSTS
#define CACANSignalRTENUM_AdjVolDwnSwtSts                        COMEX_SIGNAL_RX_ADJVOLDWNSWTSTS
#define CACANSignalRTENUM_AdjVolUpSwtSts                         COMEX_SIGNAL_RX_ADJVOLUPSWTSTS
#define CACANSignalRTENUM_SeekDwnSwtSts                          COMEX_SIGNAL_RX_SEEKDWNSWTSTS
#define CACANSignalRTENUM_SeekUpSwtSts                           COMEX_SIGNAL_RX_SEEKUPSWTSTS
#define CACANSignalRTENUM_EnterSwtSts_Mmed                       COMEX_SIGNAL_RX_ENTERSWTSTS_MMED
#define CACANSignalRTENUM_VRSwtSts                               COMEX_SIGNAL_RX_VRSWTSTS
#define CACANSignalRTENUM_MuteSwtSts                             COMEX_SIGNAL_RX_MUTESWTSTS
#define CACANSignalRTENUM_CustomSwtSts_Mmed                      COMEX_SIGNAL_RX_CUSTOMSWTSTS_MMED
#define CACANSignalRTENUM_Stat_PwrSv_Lvl                         COMEX_SIGNAL_RX_STAT_PWRSV_LVL
#define CACANSignalRTENUM_HUD_BrightnessLvl                      COMEX_SIGNAL_RX_HUD_BRIGHTNESSLVL
#define CACANSignalRTENUM_HUD_HeightLvl                          COMEX_SIGNAL_RX_HUD_HEIGHTLVL
#define CACANSignalRTENUM_HUD_UIMod                              COMEX_SIGNAL_RX_HUD_UIMOD
#define CACANSignalRTENUM_HUD_UIModVld                           COMEX_SIGNAL_RX_HUD_UIMODVLD
#define CACANSignalRTENUM_HUD_SwtSts                             COMEX_SIGNAL_RX_HUD_SWTSTS
#define CACANSignalRTENUM_BaroPressure                           COMEX_SIGNAL_RX_BAROPRESSURE
#define CACANSignalRTENUM_Urea_Level                             CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_UreaRemainDist                         CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_SCRSysWarnDisplay                      CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_SCRSysWarnDisplay_B2                   CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACAmbTemp                              COMEX_SIGNAL_RX_ACAMBTEMP
#define CACANSignalRTENUM_TrqPrct                                CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_PowerPrct                              CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_VehLgtAccel                            COMEX_SIGNAL_RX_VEHLGTACCEL
#define CACANSignalRTENUM_VehLatAccel                            COMEX_SIGNAL_RX_VEHLATACCEL
#define CACANSignalRTENUM_VehLgtAccelVld                         COMEX_SIGNAL_RX_VEHLGTACCELVLD
#define CACANSignalRTENUM_VehLatAccelVld                         COMEX_SIGNAL_RX_VEHLATACCELVLD
#define CACANSignalRTENUM_EngOilPres                             COMEX_SIGNAL_RX_ENGOILPRES
#define CACANSignalRTENUM_EngOilTemp                             COMEX_SIGNAL_RX_ENGOILTEMP
#define CACANSignalRTENUM_LowBeamSts_F_PBOX                      COMEX_SIGNAL_RX_LOWBEAMSTS_F_PBOX
#define CACANSignalRTENUM_LeftLightShowSts                       CACANSignalRTENUM_ProDBCIsNotIncluded

#elif defined SWC_CA_ADAPT_P02
#define CACANSignalRTENUM_DrivingModDis_0x145                    CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_DrivingModDis_0x137                    COMEX_SIGNAL_RX_DRIVINGMODDIS
#define CACANSignalRTENUM_ESPBrkLmpCtrl_0x137                    CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_BSD_LCA_warningReqRight                COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT
#define CACANSignalRTENUM_BSD_LCA_warningReqleft                 COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT
#define CACANSignalRTENUM_DOW_warningReqRight                    COMEX_SIGNAL_RX_DOW_WARNINGREQRIGHT
#define CACANSignalRTENUM_DOW_warningReqleft                     COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT
#define CACANSignalRTENUM_IFC_Line01_Type                        COMEX_SIGNAL_RX_IFC_LINE01_TYPE
#define CACANSignalRTENUM_IFC_Line01_Dy                          COMEX_SIGNAL_RX_IFC_LINE01_DY
#define CACANSignalRTENUM_IFC_Line01_Curv                        COMEX_SIGNAL_RX_IFC_LINE01_CURV
#define CACANSignalRTENUM_IFC_Line01_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE01_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line02_Type                        COMEX_SIGNAL_RX_IFC_LINE02_TYPE
#define CACANSignalRTENUM_IFC_Line02_Dy                          COMEX_SIGNAL_RX_IFC_LINE02_DY
#define CACANSignalRTENUM_IFC_Line02_Curv                        COMEX_SIGNAL_RX_IFC_LINE02_CURV
#define CACANSignalRTENUM_IFC_Line02_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE02_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line03_Type                        COMEX_SIGNAL_RX_IFC_LINE03_TYPE
#define CACANSignalRTENUM_IFC_Line03_Dy                          COMEX_SIGNAL_RX_IFC_LINE03_DY
#define CACANSignalRTENUM_IFC_Line03_Curv                        COMEX_SIGNAL_RX_IFC_LINE03_CURV
#define CACANSignalRTENUM_IFC_Line03_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE03_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line04_Type                        COMEX_SIGNAL_RX_IFC_LINE04_TYPE
#define CACANSignalRTENUM_IFC_Line04_Dy                          COMEX_SIGNAL_RX_IFC_LINE04_DY
#define CACANSignalRTENUM_IFC_Line04_Curv                        COMEX_SIGNAL_RX_IFC_LINE04_CURV
#define CACANSignalRTENUM_IFC_Line04_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE04_CURVCHANGE
#define CACANSignalRTENUM_IFC_Roadedge01_Type                    COMEX_SIGNAL_RX_IFC_ROADEDGE01_TYPE
#define CACANSignalRTENUM_IFC_Roadedge01_Dy                      COMEX_SIGNAL_RX_IFC_ROADEDGE01_DY
#define CACANSignalRTENUM_IFC_Roadedge01_Curv                    COMEX_SIGNAL_RX_IFC_ROADEDGE01_CURV
#define CACANSignalRTENUM_IFC_Roadedge01_CurvChange              COMEX_SIGNAL_RX_IFC_ROADEDGE01_CURVCHANGE
#define CACANSignalRTENUM_IFC_Roadedge02_Type                    COMEX_SIGNAL_RX_IFC_ROADEDGE02_TYPE
#define CACANSignalRTENUM_IFC_Roadedge02_Dy                      COMEX_SIGNAL_RX_IFC_ROADEDGE02_DY
#define CACANSignalRTENUM_IFC_Roadedge02_Curv                    COMEX_SIGNAL_RX_IFC_ROADEDGE02_CURV
#define CACANSignalRTENUM_IFC_Roadedge02_CurvChange              COMEX_SIGNAL_RX_IFC_ROADEDGE02_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line01_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE01_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line02_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE02_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line03_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE03_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line04_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE04_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Roadedge01_HeadingAngle            COMEX_SIGNAL_RX_IFC_ROADEDGE01_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Roadedge02_HeadingAngle            COMEX_SIGNAL_RX_IFC_ROADEDGE02_HEADINGANGLE
#define CACANSignalRTENUM_ACC_PotentialTgtTyp                    COMEX_SIGNAL_RX_ACC_POTENTIALTGTTYP
#define CACANSignalRTENUM_ACC_PotentialTgtDy                     COMEX_SIGNAL_RX_ACC_POTENTIALTGTDY
#define CACANSignalRTENUM_ACC_PotentialTgtDx                     COMEX_SIGNAL_RX_ACC_POTENTIALTGTDX
#define CACANSignalRTENUM_ACC_PotentialTgtHeading                COMEX_SIGNAL_RX_ACC_POTENTIALTGTHEADING
#define CACANSignalRTENUM_ACC_PotentialTgtDetn                   COMEX_SIGNAL_RX_ACC_POTENTIALTGTDETN
#define CACANSignalRTENUM_ACC_RlvTgtTyp                          COMEX_SIGNAL_RX_ACC_RLVTGTTYP
#define CACANSignalRTENUM_ACC_RlvTgtDy                           COMEX_SIGNAL_RX_ACC_RLVTGTDY
#define CACANSignalRTENUM_ACC_RlvTgtDx                           COMEX_SIGNAL_RX_ACC_RLVTGTDX
#define CACANSignalRTENUM_ACC_RlvTgtHeading                      COMEX_SIGNAL_RX_ACC_RLVTGTHEADING
#define CACANSignalRTENUM_ACC_RlvTgtDetn                         COMEX_SIGNAL_RX_ACC_RLVTGTDETN
#define CACANSignalRTENUM_ACC_LeTgtTyp                           COMEX_SIGNAL_RX_ACC_LETGTTYP
#define CACANSignalRTENUM_ACC_LeTgtDy                            COMEX_SIGNAL_RX_ACC_LETGTDY
#define CACANSignalRTENUM_ACC_LeTgtDx                            COMEX_SIGNAL_RX_ACC_LETGTDX
#define CACANSignalRTENUM_ACC_LeTgtHeading                       COMEX_SIGNAL_RX_ACC_LETGTHEADING
#define CACANSignalRTENUM_ACC_LeTargrtDection                    COMEX_SIGNAL_RX_ACC_LETARGRTDECTION
#define CACANSignalRTENUM_ACC_RiTgtTyp                           COMEX_SIGNAL_RX_ACC_RITGTTYP
#define CACANSignalRTENUM_ACC_RiTgtDy                            COMEX_SIGNAL_RX_ACC_RITGTDY
#define CACANSignalRTENUM_ACC_RiTgtDx                            COMEX_SIGNAL_RX_ACC_RITGTDX
#define CACANSignalRTENUM_ACC_RiTgtHeading                       COMEX_SIGNAL_RX_ACC_RITGTHEADING
#define CACANSignalRTENUM_ACC_RiTargrtDetn                       COMEX_SIGNAL_RX_ACC_RITARGRTDETN
#define CACANSignalRTENUM_ACC_LeTgt_02_Typ                       COMEX_SIGNAL_RX_ACC_LETGT_02_TYP
#define CACANSignalRTENUM_ACC_LeTgt_02_Dy                        COMEX_SIGNAL_RX_ACC_LETGT_02_DY
#define CACANSignalRTENUM_ACC_LeTgt_02_Dx                        COMEX_SIGNAL_RX_ACC_LETGT_02_DX
#define CACANSignalRTENUM_ACC_LeTargrt_02_Detn                   COMEX_SIGNAL_RX_ACC_LETARGRT_02_DETN
#define CACANSignalRTENUM_ACC_RiTgt_02_Typ                       COMEX_SIGNAL_RX_ACC_RITGT_02_TYP
#define CACANSignalRTENUM_ACC_RiTgt_02_Dy                        COMEX_SIGNAL_RX_ACC_RITGT_02_DY
#define CACANSignalRTENUM_ACC_RiTgt_02_Dx                        COMEX_SIGNAL_RX_ACC_RITGT_02_DX
#define CACANSignalRTENUM_ACC_RiTargrt_02_Detn                   COMEX_SIGNAL_RX_ACC_RITARGRT_02_DETN
#define CACANSignalRTENUM_ACC_ModDisp                            COMEX_SIGNAL_RX_ACC_MODDISP
#define CACANSignalRTENUM_TJA_ICA_ModDisp                        COMEX_SIGNAL_RX_TJA_ICA_MODDISP
#define CACANSignalRTENUM_ACC_TgtObjBarDisp                      COMEX_SIGNAL_RX_ACC_TGTOBJBARDISP
#define CACANSignalRTENUM_ACC_FctSts                             COMEX_SIGNAL_RX_ACC_FCTSTS
#define CACANSignalRTENUM_HWA_InterSysInfoDisp                   COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP
#define CACANSignalRTENUM_ACC_InterSysInfoDisp                   COMEX_SIGNAL_RX_ACC_INTERSYSINFODISP
#define CACANSignalRTENUM_TJA_ICA_InterSysInfoDisp               COMEX_SIGNAL_RX_TJA_ICA_INTERSYSINFODISP
#define CACANSignalRTENUM_Request_driveoff                       COMEX_SIGNAL_RX_REQUEST_DRIVEOFF
#define CACANSignalRTENUM_HWA_ModDisp                            COMEX_SIGNAL_RX_HWA_MODDISP
#define CACANSignalRTENUM_HWA_LaneChange                         COMEX_SIGNAL_RX_HWA_LANECHANGE
#define CACANSignalRTENUM_HWA_LaneChangeReq                      COMEX_SIGNAL_RX_HWA_LANECHANGEREQ
#define CACANSignalRTENUM_HWA_Resp                               COMEX_SIGNAL_RX_HWA_RESP
#define CACANSignalRTENUM_ALC_Resp                               COMEX_SIGNAL_RX_ALC_RESP
#define CACANSignalRTENUM_ACC_EgoStatus                          COMEX_SIGNAL_RX_ACC_EGOSTATUS
#define CACANSignalRTENUM_ACC_SpdSetValue                        COMEX_SIGNAL_RX_ACC_SPDSETVALUE
#define CACANSignalRTENUM_ACC_TimeGapSet                         COMEX_SIGNAL_RX_ACC_TIMEGAPSET
#define CACANSignalRTENUM_ISL_InterSysInfoDisp                   COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP
#define CACANSignalRTENUM_LSSIntervention                        COMEX_SIGNAL_RX_LSSINTERVENTION
#define CACANSignalRTENUM_TJA_FollowSts                          COMEX_SIGNAL_RX_TJA_FOLLOWSTS
#define CACANSignalRTENUM_IntelligentEvaActSts                   COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS
#define CACANSignalRTENUM_LaneAvailability                       COMEX_SIGNAL_RX_LANEAVAILABILITY
#define CACANSignalRTENUM_FCW_Warn                               COMEX_SIGNAL_RX_FCW_WARN
#define CACANSignalRTENUM_AEB_VehTrig                            COMEX_SIGNAL_RX_AEB_VEHTRIG
#define CACANSignalRTENUM_AEB_PedTrig                            COMEX_SIGNAL_RX_AEB_PEDTRIG
#define CACANSignalRTENUM_AEB_JABrkTrig                          COMEX_SIGNAL_RX_AEB_JABRKTRIG
#define CACANSignalRTENUM_ACC_RiTgt_03_Typ                       COMEX_SIGNAL_RX_ACC_RITGT_03_TYP
#define CACANSignalRTENUM_ACC_RiTargrt_03_Detn                   COMEX_SIGNAL_RX_ACC_RITARGRT_03_DETN
#define CACANSignalRTENUM_ACC_RiTgt_03_Dx                        COMEX_SIGNAL_RX_ACC_RITGT_03_DX
#define CACANSignalRTENUM_ACC_RiTgt_03_Dy                        COMEX_SIGNAL_RX_ACC_RITGT_03_DY
#define CACANSignalRTENUM_ACC_LeTgt_03_Typ                       COMEX_SIGNAL_RX_ACC_LETGT_03_TYP
#define CACANSignalRTENUM_ACC_LeTargrt_03_Detn                   COMEX_SIGNAL_RX_ACC_LETARGRT_03_DETN
#define CACANSignalRTENUM_ACC_LeTgt_03_Dx                        COMEX_SIGNAL_RX_ACC_LETGT_03_DX
#define CACANSignalRTENUM_ACC_LeTgt_03_Dy                        COMEX_SIGNAL_RX_ACC_LETGT_03_DY
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Heading            COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_HEADING
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Typ                COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_TYP
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Detn               COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_DETN
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Dx                 COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_DX
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Dy                 COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_DY
#define CACANSignalRTENUM_FCTA_Warn                              COMEX_SIGNAL_RX_FCTA_WARN
#define CACANSignalRTENUM_FCTBTrig                               COMEX_SIGNAL_RX_FCTBTRIG
#define CACANSignalRTENUM_SAS_Sts                                COMEX_SIGNAL_RX_SAS_STS
#define CACANSignalRTENUM_SteerWheelAng                          COMEX_SIGNAL_RX_STEERWHEELANG
#define CACANSignalRTENUM_SteerWheelAngSign                      COMEX_SIGNAL_RX_STEERWHEELANGSIGN
#define CACANSignalRTENUM_IDC_L2_TurnLightReq                    COMEX_SIGNAL_RX_IDC_L2_TURNLIGHTREQ
#define CACANSignalRTENUM_HWA_InhibitWarn                        COMEX_SIGNAL_RX_HWA_INHIBITWARN
#define CACANSignalRTENUM_HWA_WarnInfoDisp                       COMEX_SIGNAL_RX_HWA_WARNINFODISP
#define CACANSignalRTENUM_MRC_InterSysInfoDisp                   COMEX_SIGNAL_RX_MRC_INTERSYSINFODISP
#define CACANSignalRTENUM_HWA_ALC_Trig                           COMEX_SIGNAL_RX_HWA_ALC_TRIG
#define CACANSignalRTENUM_Stop_Mark_Detn                         COMEX_SIGNAL_RX_STOP_MARK_DETN
#define CACANSignalRTENUM_Stop_Mark_Dx                           COMEX_SIGNAL_RX_STOP_MARK_DX
#define CACANSignalRTENUM_Zebra_Mark_Detn                        COMEX_SIGNAL_RX_ZEBRA_MARK_DETN
#define CACANSignalRTENUM_Zebra_Mark_Dx                          COMEX_SIGNAL_RX_ZEBRA_MARK_DX
#define CACANSignalRTENUM_Grid_Mark_Detn                         COMEX_SIGNAL_RX_GRID_MARK_DETN
#define CACANSignalRTENUM_Grid_Mark_Dx                           COMEX_SIGNAL_RX_GRID_MARK_DX
#define CACANSignalRTENUM_IFC_Line01_Source                      COMEX_SIGNAL_RX_IFC_LINE01_SOURCE
#define CACANSignalRTENUM_IFC_Line02_Source                      COMEX_SIGNAL_RX_IFC_LINE02_SOURCE
#define CACANSignalRTENUM_TSRSpdLim                              COMEX_SIGNAL_RX_TSRSPDLIM
#define CACANSignalRTENUM_HWA_TakOver_Req                        COMEX_SIGNAL_RX_HWA_TAKOVER_REQ
#define CACANSignalRTENUM_AutoSpdSetSwt_Resp                     COMEX_SIGNAL_RX_AUTOSPDSETSWT_RESP
#define CACANSignalRTENUM_NOH_Sts                                COMEX_SIGNAL_RX_NOH_STS
#define CACANSignalRTENUM_NOH_SysInfoDisplay                     COMEX_SIGNAL_RX_NOH_SYSINFODISPLAY
#define CACANSignalRTENUM_V2X_RLVW                               COMEX_SIGNAL_RX_V2X_RLVW
#define CACANSignalRTENUM_DrvDoorSts                             COMEX_SIGNAL_RX_DRVDOORSTS
#define CACANSignalRTENUM_BrkPedalSts_BCM                        COMEX_SIGNAL_RX_BRKPEDALSTS_BCM
#define CACANSignalRTENUM_DrvDoorLockSts                         COMEX_SIGNAL_RX_DRVDOORLOCKSTS
#define CACANSignalRTENUM_SrPosn_VR_APP                          COMEX_SIGNAL_RX_SRPOSN_VR_APP
#define CACANSignalRTENUM_PageUpSwtSts                           COMEX_SIGNAL_RX_PAGEUPSWTSTS
#define CACANSignalRTENUM_PageDwnSwtSts                          COMEX_SIGNAL_RX_PAGEDWNSWTSTS
#define CACANSignalRTENUM_PageLSwtSts                            COMEX_SIGNAL_RX_PAGELSWTSTS
#define CACANSignalRTENUM_PageRSwtSts                            COMEX_SIGNAL_RX_PAGERSWTSTS
#define CACANSignalRTENUM_EnterSwtSts                            COMEX_SIGNAL_RX_ENTERSWTSTS
#define CACANSignalRTENUM_HomeSwtSts                             COMEX_SIGNAL_RX_HOMESWTSTS
#define CACANSignalRTENUM_MenuReturnSwtSts                       COMEX_SIGNAL_RX_MENURETURNSWTSTS
#define CACANSignalRTENUM_CustomSwtSts                           COMEX_SIGNAL_RX_CUSTOMSWTSTS
#define CACANSignalRTENUM_IpMenuSwtSts                           COMEX_SIGNAL_RX_IPMENUSWTSTS
#define CACANSignalRTENUM_AdjVolDwnSwtSts                        COMEX_SIGNAL_RX_ADJVOLDWNSWTSTS
#define CACANSignalRTENUM_AdjVolUpSwtSts                         COMEX_SIGNAL_RX_ADJVOLUPSWTSTS
#define CACANSignalRTENUM_SeekDwnSwtSts                          COMEX_SIGNAL_RX_SEEKDWNSWTSTS
#define CACANSignalRTENUM_SeekUpSwtSts                           COMEX_SIGNAL_RX_SEEKUPSWTSTS
#define CACANSignalRTENUM_EnterSwtSts_Mmed                       COMEX_SIGNAL_RX_ENTERSWTSTS_MMED
#define CACANSignalRTENUM_VRSwtSts                               COMEX_SIGNAL_RX_VRSWTSTS
#define CACANSignalRTENUM_MuteSwtSts                             COMEX_SIGNAL_RX_MUTESWTSTS
#define CACANSignalRTENUM_CustomSwtSts_Mmed                      COMEX_SIGNAL_RX_CUSTOMSWTSTS_MMED
#define CACANSignalRTENUM_Stat_PwrSv_Lvl                         COMEX_SIGNAL_RX_STAT_PWRSV_LVL
#define CACANSignalRTENUM_HUD_BrightnessLvl                      COMEX_SIGNAL_RX_HUD_BRIGHTNESSLVL
#define CACANSignalRTENUM_HUD_HeightLvl                          COMEX_SIGNAL_RX_HUD_HEIGHTLVL
#define CACANSignalRTENUM_HUD_UIMod                              COMEX_SIGNAL_RX_HUD_UIMOD
#define CACANSignalRTENUM_HUD_UIModVld                           COMEX_SIGNAL_RX_HUD_UIMODVLD
#define CACANSignalRTENUM_HUD_SwtSts                             COMEX_SIGNAL_RX_HUD_SWTSTS
#define CACANSignalRTENUM_BaroPressure                           COMEX_SIGNAL_RX_BAROPRESSURE
#define CACANSignalRTENUM_Urea_Level                             COMEX_SIGNAL_RX_UREA_LEVEL
#define CACANSignalRTENUM_UreaRemainDist                         COMEX_SIGNAL_RX_UREAREMAINDIST
#define CACANSignalRTENUM_SCRSysWarnDisplay                      COMEX_SIGNAL_RX_SCRSYSWARNDISPLAY
#define CACANSignalRTENUM_SCRSysWarnDisplay_B2                   CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_ACAmbTemp                              COMEX_SIGNAL_RX_ACAMBTEMP
#define CACANSignalRTENUM_TrqPrct                                CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_PowerPrct                              CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_VehLgtAccel                            COMEX_SIGNAL_RX_VEHLGTACCEL
#define CACANSignalRTENUM_VehLatAccel                            COMEX_SIGNAL_RX_VEHLATACCEL
#define CACANSignalRTENUM_VehLgtAccelVld                         COMEX_SIGNAL_RX_VEHLGTACCELVLD
#define CACANSignalRTENUM_VehLatAccelVld                         COMEX_SIGNAL_RX_VEHLATACCELVLD
#define CACANSignalRTENUM_EngOilPres                             COMEX_SIGNAL_RX_ENGOILPRES
#define CACANSignalRTENUM_EngOilTemp                             COMEX_SIGNAL_RX_ENGOILTEMP
#define CACANSignalRTENUM_LowBeamSts_F_PBOX                      COMEX_SIGNAL_RX_LOWBEAMSTS_F_PBOX
#define CACANSignalRTENUM_LeftLightShowSts                       COMEX_SIGNAL_RX_LEFTLIGHTSHOWSTS

#elif defined SWC_CA_ADAPT_P01
#define CACANSignalRTENUM_DrivingModDis_0x145                    CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_DrivingModDis_0x137                    COMEX_SIGNAL_RX_DRIVINGMODDIS
#define CACANSignalRTENUM_ESPBrkLmpCtrl_0x137                    CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_BSD_LCA_warningReqRight                COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT
#define CACANSignalRTENUM_BSD_LCA_warningReqleft                 COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT
#define CACANSignalRTENUM_DOW_warningReqRight                    COMEX_SIGNAL_RX_DOW_WARNINGREQRIGHT
#define CACANSignalRTENUM_DOW_warningReqleft                     COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT
#define CACANSignalRTENUM_IFC_Line01_Type                        COMEX_SIGNAL_RX_IFC_LINE01_TYPE
#define CACANSignalRTENUM_IFC_Line01_Dy                          COMEX_SIGNAL_RX_IFC_LINE01_DY
#define CACANSignalRTENUM_IFC_Line01_Curv                        COMEX_SIGNAL_RX_IFC_LINE01_CURV
#define CACANSignalRTENUM_IFC_Line01_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE01_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line02_Type                        COMEX_SIGNAL_RX_IFC_LINE02_TYPE
#define CACANSignalRTENUM_IFC_Line02_Dy                          COMEX_SIGNAL_RX_IFC_LINE02_DY
#define CACANSignalRTENUM_IFC_Line02_Curv                        COMEX_SIGNAL_RX_IFC_LINE02_CURV
#define CACANSignalRTENUM_IFC_Line02_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE02_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line03_Type                        COMEX_SIGNAL_RX_IFC_LINE03_TYPE
#define CACANSignalRTENUM_IFC_Line03_Dy                          COMEX_SIGNAL_RX_IFC_LINE03_DY
#define CACANSignalRTENUM_IFC_Line03_Curv                        COMEX_SIGNAL_RX_IFC_LINE03_CURV
#define CACANSignalRTENUM_IFC_Line03_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE03_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line04_Type                        COMEX_SIGNAL_RX_IFC_LINE04_TYPE
#define CACANSignalRTENUM_IFC_Line04_Dy                          COMEX_SIGNAL_RX_IFC_LINE04_DY
#define CACANSignalRTENUM_IFC_Line04_Curv                        COMEX_SIGNAL_RX_IFC_LINE04_CURV
#define CACANSignalRTENUM_IFC_Line04_CurvChange                  COMEX_SIGNAL_RX_IFC_LINE04_CURVCHANGE
#define CACANSignalRTENUM_IFC_Roadedge01_Type                    COMEX_SIGNAL_RX_IFC_ROADEDGE01_TYPE
#define CACANSignalRTENUM_IFC_Roadedge01_Dy                      COMEX_SIGNAL_RX_IFC_ROADEDGE01_DY
#define CACANSignalRTENUM_IFC_Roadedge01_Curv                    COMEX_SIGNAL_RX_IFC_ROADEDGE01_CURV
#define CACANSignalRTENUM_IFC_Roadedge01_CurvChange              COMEX_SIGNAL_RX_IFC_ROADEDGE01_CURVCHANGE
#define CACANSignalRTENUM_IFC_Roadedge02_Type                    COMEX_SIGNAL_RX_IFC_ROADEDGE02_TYPE
#define CACANSignalRTENUM_IFC_Roadedge02_Dy                      COMEX_SIGNAL_RX_IFC_ROADEDGE02_DY
#define CACANSignalRTENUM_IFC_Roadedge02_Curv                    COMEX_SIGNAL_RX_IFC_ROADEDGE02_CURV
#define CACANSignalRTENUM_IFC_Roadedge02_CurvChange              COMEX_SIGNAL_RX_IFC_ROADEDGE02_CURVCHANGE
#define CACANSignalRTENUM_IFC_Line01_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE01_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line02_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE02_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line03_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE03_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Line04_HeadingAngle                COMEX_SIGNAL_RX_IFC_LINE04_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Roadedge01_HeadingAngle            COMEX_SIGNAL_RX_IFC_ROADEDGE01_HEADINGANGLE
#define CACANSignalRTENUM_IFC_Roadedge02_HeadingAngle            COMEX_SIGNAL_RX_IFC_ROADEDGE02_HEADINGANGLE
#define CACANSignalRTENUM_ACC_PotentialTgtTyp                    COMEX_SIGNAL_RX_ACC_POTENTIALTGTTYP
#define CACANSignalRTENUM_ACC_PotentialTgtDy                     COMEX_SIGNAL_RX_ACC_POTENTIALTGTDY
#define CACANSignalRTENUM_ACC_PotentialTgtDx                     COMEX_SIGNAL_RX_ACC_POTENTIALTGTDX
#define CACANSignalRTENUM_ACC_PotentialTgtHeading                COMEX_SIGNAL_RX_ACC_POTENTIALTGTHEADING
#define CACANSignalRTENUM_ACC_PotentialTgtDetn                   COMEX_SIGNAL_RX_ACC_POTENTIALTGTDETN
#define CACANSignalRTENUM_ACC_RlvTgtTyp                          COMEX_SIGNAL_RX_ACC_RLVTGTTYP
#define CACANSignalRTENUM_ACC_RlvTgtDy                           COMEX_SIGNAL_RX_ACC_RLVTGTDY
#define CACANSignalRTENUM_ACC_RlvTgtDx                           COMEX_SIGNAL_RX_ACC_RLVTGTDX
#define CACANSignalRTENUM_ACC_RlvTgtHeading                      COMEX_SIGNAL_RX_ACC_RLVTGTHEADING
#define CACANSignalRTENUM_ACC_RlvTgtDetn                         COMEX_SIGNAL_RX_ACC_RLVTGTDETN
#define CACANSignalRTENUM_ACC_LeTgtTyp                           COMEX_SIGNAL_RX_ACC_LETGTTYP
#define CACANSignalRTENUM_ACC_LeTgtDy                            COMEX_SIGNAL_RX_ACC_LETGTDY
#define CACANSignalRTENUM_ACC_LeTgtDx                            COMEX_SIGNAL_RX_ACC_LETGTDX
#define CACANSignalRTENUM_ACC_LeTgtHeading                       COMEX_SIGNAL_RX_ACC_LETGTHEADING
#define CACANSignalRTENUM_ACC_LeTargrtDection                    COMEX_SIGNAL_RX_ACC_LETARGRTDECTION
#define CACANSignalRTENUM_ACC_RiTgtTyp                           COMEX_SIGNAL_RX_ACC_RITGTTYP
#define CACANSignalRTENUM_ACC_RiTgtDy                            COMEX_SIGNAL_RX_ACC_RITGTDY
#define CACANSignalRTENUM_ACC_RiTgtDx                            COMEX_SIGNAL_RX_ACC_RITGTDX
#define CACANSignalRTENUM_ACC_RiTgtHeading                       COMEX_SIGNAL_RX_ACC_RITGTHEADING
#define CACANSignalRTENUM_ACC_RiTargrtDetn                       COMEX_SIGNAL_RX_ACC_RITARGRTDETN
#define CACANSignalRTENUM_ACC_LeTgt_02_Typ                       COMEX_SIGNAL_RX_ACC_LETGT_02_TYP
#define CACANSignalRTENUM_ACC_LeTgt_02_Dy                        COMEX_SIGNAL_RX_ACC_LETGT_02_DY
#define CACANSignalRTENUM_ACC_LeTgt_02_Dx                        COMEX_SIGNAL_RX_ACC_LETGT_02_DX
#define CACANSignalRTENUM_ACC_LeTargrt_02_Detn                   COMEX_SIGNAL_RX_ACC_LETARGRT_02_DETN
#define CACANSignalRTENUM_ACC_RiTgt_02_Typ                       COMEX_SIGNAL_RX_ACC_RITGT_02_TYP
#define CACANSignalRTENUM_ACC_RiTgt_02_Dy                        COMEX_SIGNAL_RX_ACC_RITGT_02_DY
#define CACANSignalRTENUM_ACC_RiTgt_02_Dx                        COMEX_SIGNAL_RX_ACC_RITGT_02_DX
#define CACANSignalRTENUM_ACC_RiTargrt_02_Detn                   COMEX_SIGNAL_RX_ACC_RITARGRT_02_DETN
#define CACANSignalRTENUM_ACC_ModDisp                            COMEX_SIGNAL_RX_ACC_MODDISP
#define CACANSignalRTENUM_TJA_ICA_ModDisp                        COMEX_SIGNAL_RX_TJA_ICA_MODDISP
#define CACANSignalRTENUM_ACC_TgtObjBarDisp                      COMEX_SIGNAL_RX_ACC_TGTOBJBARDISP
#define CACANSignalRTENUM_ACC_FctSts                             COMEX_SIGNAL_RX_ACC_FCTSTS
#define CACANSignalRTENUM_HWA_InterSysInfoDisp                   COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP
#define CACANSignalRTENUM_ACC_InterSysInfoDisp                   COMEX_SIGNAL_RX_ACC_INTERSYSINFODISP
#define CACANSignalRTENUM_TJA_ICA_InterSysInfoDisp               COMEX_SIGNAL_RX_TJA_ICA_INTERSYSINFODISP
#define CACANSignalRTENUM_Request_driveoff                       COMEX_SIGNAL_RX_REQUEST_DRIVEOFF
#define CACANSignalRTENUM_HWA_ModDisp                            COMEX_SIGNAL_RX_HWA_MODDISP
#define CACANSignalRTENUM_HWA_LaneChange                         COMEX_SIGNAL_RX_HWA_LANECHANGE
#define CACANSignalRTENUM_HWA_LaneChangeReq                      COMEX_SIGNAL_RX_HWA_LANECHANGEREQ
#define CACANSignalRTENUM_HWA_Resp                               COMEX_SIGNAL_RX_HWA_RESP
#define CACANSignalRTENUM_ALC_Resp                               COMEX_SIGNAL_RX_ALC_RESP
#define CACANSignalRTENUM_ACC_EgoStatus                          COMEX_SIGNAL_RX_ACC_EGOSTATUS
#define CACANSignalRTENUM_ACC_SpdSetValue                        COMEX_SIGNAL_RX_ACC_SPDSETVALUE
#define CACANSignalRTENUM_ACC_TimeGapSet                         COMEX_SIGNAL_RX_ACC_TIMEGAPSET
#define CACANSignalRTENUM_ISL_InterSysInfoDisp                   COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP
#define CACANSignalRTENUM_LSSIntervention                        COMEX_SIGNAL_RX_LSSINTERVENTION
#define CACANSignalRTENUM_TJA_FollowSts                          COMEX_SIGNAL_RX_TJA_FOLLOWSTS
#define CACANSignalRTENUM_IntelligentEvaActSts                   COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS
#define CACANSignalRTENUM_LaneAvailability                       COMEX_SIGNAL_RX_LANEAVAILABILITY
#define CACANSignalRTENUM_FCW_Warn                               COMEX_SIGNAL_RX_FCW_WARN
#define CACANSignalRTENUM_AEB_VehTrig                            COMEX_SIGNAL_RX_AEB_VEHTRIG
#define CACANSignalRTENUM_AEB_PedTrig                            COMEX_SIGNAL_RX_AEB_PEDTRIG
#define CACANSignalRTENUM_AEB_JABrkTrig                          COMEX_SIGNAL_RX_AEB_JABRKTRIG
#define CACANSignalRTENUM_ACC_RiTgt_03_Typ                       COMEX_SIGNAL_RX_ACC_RITGT_03_TYP
#define CACANSignalRTENUM_ACC_RiTargrt_03_Detn                   COMEX_SIGNAL_RX_ACC_RITARGRT_03_DETN
#define CACANSignalRTENUM_ACC_RiTgt_03_Dx                        COMEX_SIGNAL_RX_ACC_RITGT_03_DX
#define CACANSignalRTENUM_ACC_RiTgt_03_Dy                        COMEX_SIGNAL_RX_ACC_RITGT_03_DY
#define CACANSignalRTENUM_ACC_LeTgt_03_Typ                       COMEX_SIGNAL_RX_ACC_LETGT_03_TYP
#define CACANSignalRTENUM_ACC_LeTargrt_03_Detn                   COMEX_SIGNAL_RX_ACC_LETARGRT_03_DETN
#define CACANSignalRTENUM_ACC_LeTgt_03_Dx                        COMEX_SIGNAL_RX_ACC_LETGT_03_DX
#define CACANSignalRTENUM_ACC_LeTgt_03_Dy                        COMEX_SIGNAL_RX_ACC_LETGT_03_DY
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Heading            COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_HEADING
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Typ                COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_TYP
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Detn               COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_DETN
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Dx                 COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_DX
#define CACANSignalRTENUM_ACC_PotentialTgt_02_Dy                 COMEX_SIGNAL_RX_ACC_POTENTIALTGT_02_DY
#define CACANSignalRTENUM_FCTA_Warn                              COMEX_SIGNAL_RX_FCTA_WARN
#define CACANSignalRTENUM_FCTBTrig                               COMEX_SIGNAL_RX_FCTBTRIG
#define CACANSignalRTENUM_SAS_Sts                                COMEX_SIGNAL_RX_SAS_STS
#define CACANSignalRTENUM_SteerWheelAng                          COMEX_SIGNAL_RX_STEERWHEELANG
#define CACANSignalRTENUM_SteerWheelAngSign                      COMEX_SIGNAL_RX_STEERWHEELANGSIGN
#define CACANSignalRTENUM_IDC_L2_TurnLightReq                    COMEX_SIGNAL_RX_IDC_L2_TURNLIGHTREQ
#define CACANSignalRTENUM_HWA_InhibitWarn                        COMEX_SIGNAL_RX_HWA_INHIBITWARN
#define CACANSignalRTENUM_HWA_WarnInfoDisp                       COMEX_SIGNAL_RX_HWA_WARNINFODISP
#define CACANSignalRTENUM_MRC_InterSysInfoDisp                   COMEX_SIGNAL_RX_MRC_INTERSYSINFODISP
#define CACANSignalRTENUM_HWA_ALC_Trig                           COMEX_SIGNAL_RX_HWA_ALC_TRIG
#define CACANSignalRTENUM_Stop_Mark_Detn                         CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Stop_Mark_Dx                           CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Zebra_Mark_Detn                        CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Zebra_Mark_Dx                          CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Grid_Mark_Detn                         CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_Grid_Mark_Dx                           CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_IFC_Line01_Source                      COMEX_SIGNAL_RX_IFC_LINE01_SOURCE
#define CACANSignalRTENUM_IFC_Line02_Source                      COMEX_SIGNAL_RX_IFC_LINE02_SOURCE
#define CACANSignalRTENUM_TSRSpdLim                              COMEX_SIGNAL_RX_TSRSPDLIM
#define CACANSignalRTENUM_HWA_TakOver_Req                        COMEX_SIGNAL_RX_HWA_TAKOVER_REQ
#define CACANSignalRTENUM_AutoSpdSetSwt_Resp                     CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_NOH_Sts                                CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_NOH_SysInfoDisplay                     CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_V2X_RLVW                               COMEX_SIGNAL_RX_V2X_RLVW
#define CACANSignalRTENUM_DrvDoorSts                             COMEX_SIGNAL_RX_DRVDOORSTS
#define CACANSignalRTENUM_BrkPedalSts_BCM                        COMEX_SIGNAL_RX_BRKPEDALSTS_BCM
#define CACANSignalRTENUM_DrvDoorLockSts                         COMEX_SIGNAL_RX_DRVDOORLOCKSTS
#define CACANSignalRTENUM_SrPosn_VR_APP                          COMEX_SIGNAL_RX_SRPOSN_VR_APP
#define CACANSignalRTENUM_PageUpSwtSts                           COMEX_SIGNAL_RX_PAGEUPSWTSTS
#define CACANSignalRTENUM_PageDwnSwtSts                          COMEX_SIGNAL_RX_PAGEDWNSWTSTS
#define CACANSignalRTENUM_PageLSwtSts                            COMEX_SIGNAL_RX_PAGELSWTSTS
#define CACANSignalRTENUM_PageRSwtSts                            COMEX_SIGNAL_RX_PAGERSWTSTS
#define CACANSignalRTENUM_EnterSwtSts                            COMEX_SIGNAL_RX_ENTERSWTSTS
#define CACANSignalRTENUM_HomeSwtSts                             COMEX_SIGNAL_RX_HOMESWTSTS
#define CACANSignalRTENUM_MenuReturnSwtSts                       COMEX_SIGNAL_RX_MENURETURNSWTSTS
#define CACANSignalRTENUM_CustomSwtSts                           COMEX_SIGNAL_RX_CUSTOMSWTSTS
#define CACANSignalRTENUM_IpMenuSwtSts                           CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_AdjVolDwnSwtSts                        COMEX_SIGNAL_RX_ADJVOLDWNSWTSTS
#define CACANSignalRTENUM_AdjVolUpSwtSts                         COMEX_SIGNAL_RX_ADJVOLUPSWTSTS
#define CACANSignalRTENUM_SeekDwnSwtSts                          COMEX_SIGNAL_RX_SEEKDWNSWTSTS
#define CACANSignalRTENUM_SeekUpSwtSts                           COMEX_SIGNAL_RX_SEEKUPSWTSTS
#define CACANSignalRTENUM_EnterSwtSts_Mmed                       COMEX_SIGNAL_RX_ENTERSWTSTS_MMED
#define CACANSignalRTENUM_VRSwtSts                               COMEX_SIGNAL_RX_VRSWTSTS
#define CACANSignalRTENUM_MuteSwtSts                             COMEX_SIGNAL_RX_MUTESWTSTS
#define CACANSignalRTENUM_CustomSwtSts_Mmed                      COMEX_SIGNAL_RX_CUSTOMSWTSTS_MMED
#define CACANSignalRTENUM_Stat_PwrSv_Lvl                         COMEX_SIGNAL_RX_STAT_PWRSV_LVL
#define CACANSignalRTENUM_HUD_BrightnessLvl                      CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_HUD_HeightLvl                          CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_HUD_UIMod                              CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_HUD_UIModVld                           CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_HUD_SwtSts                             CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_BaroPressure                           COMEX_SIGNAL_RX_BAROPRESSURE
#define CACANSignalRTENUM_Urea_Level                             COMEX_SIGNAL_RX_UREA_LEVEL
#define CACANSignalRTENUM_UreaRemainDist                         COMEX_SIGNAL_RX_UREAREMAINDIST
#define CACANSignalRTENUM_SCRSysWarnDisplay                      COMEX_SIGNAL_RX_SCRSYSWARNDISPLAY
#define CACANSignalRTENUM_SCRSysWarnDisplay_B2                   COMEX_SIGNAL_RX_SCRSYSWARNDISPLAY_B2
#define CACANSignalRTENUM_ACAmbTemp                              COMEX_SIGNAL_RX_ACAMBTEMP
#define CACANSignalRTENUM_TrqPrct                                CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_PowerPrct                              CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_VehLgtAccel                            COMEX_SIGNAL_RX_VEHLGTACCEL
#define CACANSignalRTENUM_VehLatAccel                            COMEX_SIGNAL_RX_VEHLATACCEL
#define CACANSignalRTENUM_VehLgtAccelVld                         COMEX_SIGNAL_RX_VEHLGTACCELVLD
#define CACANSignalRTENUM_VehLatAccelVld                         COMEX_SIGNAL_RX_VEHLATACCELVLD
#define CACANSignalRTENUM_EngOilPres                             CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_EngOilTemp                             CACANSignalRTENUM_ProDBCIsNotIncluded
#define CACANSignalRTENUM_LowBeamSts_F_PBOX                      COMEX_SIGNAL_RX_LOWBEAMSTS_F_PBOX
#define CACANSignalRTENUM_LeftLightShowSts                       CACANSignalRTENUM_ProDBCIsNotIncluded

#else
    #error " No valid project !!!
#endif



typedef struct
{
	CA_CFG_u8ProAdaptIndex enProIndex;
	VconfigKind_Allbuffers VehicleConfig;
}CA_CANAdaptAttr_t;

typedef enum
{
    CA_Valid = 0x00u,
    CA_Invalid = 0x01u,
}CA_CFG_u8SignalStatus;

typedef enum
{
    PTCANType_CAN = 0x00u,
    PTCANType_CANFD = 0x01u,
    PTCANType_Unknow = 0x02u,
}CA_CFG_u8CANType;

typedef struct
{
    CA_CFG_u8SignalStatus enCASignalStatus;
    uint32 u32CAMsgSignalValue;

}SWC_CA_CanSignalDataAttribute;

typedef struct
{
	uint8 u8MsgIndex;
	uint8 u8Priority;
    uint16 u16Cycle;

}SWC_CA_CanSignalBasisAttribute;

typedef struct
{
    SWC_CA_CanSignalDataAttribute* stCanMsgDataAttribute;

    SWC_CA_CanSignalBasisAttribute* stCanSignalBasisAttribute;

    uint16 u16CASignalTick[enCASignalInd_MAXNUM];

    uint8 u8CAMsgTimeoutStatus[enCAMsgInd_MAXNUM];

    uint8 u8CAMsgTimeoutStatusBK[enCAMsgInd_MAXNUM];
}CA_CFG_tst_MAINOBJECT;


#define CA_CFG_SignalBasisAttr_DrivingModDis_0x145 \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ESP2_145, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_20MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_DrivingModDis_0x137 \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ESP_FD2_137, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_20MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ESPBrkLmpCtrl_0x137 \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ESP_FD2_137, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_20MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_BSD_LCA_warningReqRight \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_RSDS_FD1_16F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_20MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_BSD_LCA_warningReqleft \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_RSDS_FD1_16F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_20MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_DOW_warningReqRight \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_RSDS_FD1_16F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_20MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_DOW_warningReqleft \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_RSDS_FD1_16F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_20MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line01_Type \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line01_Dy \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line01_Curv \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line01_CurvChange \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line02_Type \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line02_Dy \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line02_Curv \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line02_CurvChange \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line03_Type \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line03_Dy \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line03_Curv \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line03_CurvChange \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line04_Type \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line04_Dy \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line04_Curv \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line04_CurvChange \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Roadedge01_Type \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Roadedge01_Dy \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Roadedge01_Curv \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Roadedge01_CurvChange \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Roadedge02_Type \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Roadedge02_Dy \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Roadedge02_Curv \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Roadedge02_CurvChange \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD5_19F, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line01_HeadingAngle \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD6_222, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line02_HeadingAngle \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD6_222, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line03_HeadingAngle \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD6_222, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line04_HeadingAngle \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD6_222, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Roadedge01_HeadingAngle \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD6_222, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Roadedge02_HeadingAngle \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD6_222, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_PotentialTgtTyp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_PotentialTgtDy \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_PotentialTgtDx \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_PotentialTgtHeading \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_PotentialTgtDetn \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_RlvTgtTyp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_RlvTgtDy \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_RlvTgtDx \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_RlvTgtHeading \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_RlvTgtDetn \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_LeTgtTyp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_LeTgtDy \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_LeTgtDx \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_LeTgtHeading \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_LeTargrtDection \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_RiTgtTyp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_RiTgtDy \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_RiTgtDx \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_RiTgtHeading \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_RiTargrtDetn \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_LeTgt_02_Typ \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_LeTgt_02_Dy \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_LeTgt_02_Dx \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_LeTargrt_02_Detn \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_RiTgt_02_Typ \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_RiTgt_02_Dy \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_RiTgt_02_Dx \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_RiTargrt_02_Detn \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_ModDisp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_TJA_ICA_ModDisp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_TgtObjBarDisp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_FctSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_HWA_InterSysInfoDisp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_InterSysInfoDisp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_TJA_ICA_InterSysInfoDisp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_Request_driveoff \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_HWA_ModDisp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_HWA_LaneChange \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_HWA_LaneChangeReq \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_HWA_Resp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ALC_Resp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_EgoStatus \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_SpdSetValue \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_TimeGapSet \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ISL_InterSysInfoDisp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD2_2AB, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_LSSIntervention \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD2_23D, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_TJA_FollowSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD2_23D, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IntelligentEvaActSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD2_23D, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_LaneAvailability \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD2_23D, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_FCW_Warn \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_AEB_FD2_227, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_AEB_VehTrig \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_AEB_FD2_227, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_AEB_PedTrig \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_AEB_FD2_227, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_AEB_JABrkTrig \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_AEB_FD2_227, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_RiTgt_03_Typ \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_AEB_FD2_227, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_RiTargrt_03_Detn \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_AEB_FD2_227, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_RiTgt_03_Dx \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_AEB_FD2_227, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_RiTgt_03_Dy \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_AEB_FD2_227, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_LeTgt_03_Typ \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_AEB_FD2_227, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_LeTargrt_03_Detn \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_AEB_FD2_227, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_LeTgt_03_Dx \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_AEB_FD2_227, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_LeTgt_03_Dy \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_AEB_FD2_227, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_PotentialTgt_02_Heading \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_AEB_FD2_227, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_PotentialTgt_02_Typ \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_AEB_FD2_227, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_PotentialTgt_02_Detn \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_AEB_FD2_227, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_PotentialTgt_02_Dx \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_AEB_FD2_227, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACC_PotentialTgt_02_Dy \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_AEB_FD2_227, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_FCTA_Warn \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CR_FD1_15E, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_20MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_FCTBTrig \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CR_FD1_15E, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_20MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_SAS_Sts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA2_A1, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_SteerWheelAng \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA2_A1, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_SteerWheelAngSign \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA2_A1, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IDC_L2_TurnLightReq \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD3_2CF, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_HWA_InhibitWarn \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD3_2CF, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_HWA_WarnInfoDisp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD3_2CF, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_MRC_InterSysInfoDisp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD3_2CF, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_HWA_ALC_Trig \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD3_2CF, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_Stop_Mark_Detn \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD3_2CF, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_Stop_Mark_Dx \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD3_2CF, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_Zebra_Mark_Detn \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD3_2CF, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_Zebra_Mark_Dx \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD3_2CF, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_Grid_Mark_Detn \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD3_2CF, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_Grid_Mark_Dx \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD3_2CF, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line01_Source \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD3_2CF, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IFC_Line02_Source \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD3_2CF, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_TSRSpdLim \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD3_2CF, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_HWA_TakOver_Req \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD3_2CF, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_AutoSpdSetSwt_Resp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_IFC_FD3_2CF, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_NOH_Sts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD3_2B4, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_NOH_SysInfoDisplay \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ACC_FD3_2B4, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_V2X_RLVW \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_T_BOX_FD10_2F0, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_DrvDoorSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_BCM1_319, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_BrkPedalSts_BCM \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_BCM1_319, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_DrvDoorLockSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_BCM3_345, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_SrPosn_VR_APP \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_BCM12_238, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_PageUpSwtSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA3_244, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_PageDwnSwtSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA3_244, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_PageLSwtSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA3_244, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_PageRSwtSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA3_244, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_EnterSwtSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA3_244, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_HomeSwtSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA3_244, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_MenuReturnSwtSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA3_244, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_CustomSwtSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA3_244, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_IpMenuSwtSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA3_244, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_AdjVolDwnSwtSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA3_244, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_AdjVolUpSwtSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA3_244, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_SeekDwnSwtSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA3_244, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_SeekUpSwtSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA3_244, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_EnterSwtSts_Mmed \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA3_244, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_VRSwtSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA3_244, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_MuteSwtSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA3_244, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_CustomSwtSts_Mmed \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_CSA3_244, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_10MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_Stat_PwrSv_Lvl \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_EEM1_2A8, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_HUD_BrightnessLvl \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_HUD1_325, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_200MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_HUD_HeightLvl \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_HUD1_325, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_200MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_HUD_UIMod \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_HUD1_325, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_200MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_HUD_UIModVld \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_HUD1_325, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_200MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_HUD_SwtSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_HUD1_325, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_200MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_BaroPressure \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ECM3_371, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_Urea_Level \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ECM16_2D4, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_UreaRemainDist \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ECM16_2D4, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_SCRSysWarnDisplay \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ECM16_2D4, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_SCRSysWarnDisplay_B2 \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ECM16_2D4, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_ACAmbTemp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_AC2_385, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_TrqPrct \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ECM_PT6_290, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_PowerPrct \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ECM_PT6_290, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_100MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_VehLgtAccel \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ABM2_245, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_20MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_VehLatAccel \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ABM2_245, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_20MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_VehLgtAccelVld \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ABM2_245, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_20MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_VehLatAccelVld \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ABM2_245, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_20MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_EngOilPres \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ECM24_350, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_500MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_EngOilTemp \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_ECM24_350, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_500MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_LowBeamSts_F_PBOX \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_F_PBOX1_19B, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_50MS_Cycle, \
}, \


#define CA_CFG_SignalBasisAttr_LeftLightShowSts \
{\
    /* u8MsgIndex */    (uint8)  enCAMsgInd_HCM_L2_304, \
    /* u8Priority */    (uint8)  SWC_MsgPriority_0, \
    /* u16Cycle */      (uint16) SWC_CA_200MS_Cycle, \
}, \


#define CA_CFG_SIgnalBasisAttributeTable  \
{\
    CA_CFG_SignalBasisAttr_DrivingModDis_0x145              \
    CA_CFG_SignalBasisAttr_DrivingModDis_0x137              \
    CA_CFG_SignalBasisAttr_ESPBrkLmpCtrl_0x137              \
    CA_CFG_SignalBasisAttr_BSD_LCA_warningReqRight          \
    CA_CFG_SignalBasisAttr_BSD_LCA_warningReqleft           \
    CA_CFG_SignalBasisAttr_DOW_warningReqRight              \
    CA_CFG_SignalBasisAttr_DOW_warningReqleft               \
    CA_CFG_SignalBasisAttr_IFC_Line01_Type                  \
    CA_CFG_SignalBasisAttr_IFC_Line01_Dy                    \
    CA_CFG_SignalBasisAttr_IFC_Line01_Curv                  \
    CA_CFG_SignalBasisAttr_IFC_Line01_CurvChange            \
    CA_CFG_SignalBasisAttr_IFC_Line02_Type                  \
    CA_CFG_SignalBasisAttr_IFC_Line02_Dy                    \
    CA_CFG_SignalBasisAttr_IFC_Line02_Curv                  \
    CA_CFG_SignalBasisAttr_IFC_Line02_CurvChange            \
    CA_CFG_SignalBasisAttr_IFC_Line03_Type                  \
    CA_CFG_SignalBasisAttr_IFC_Line03_Dy                    \
    CA_CFG_SignalBasisAttr_IFC_Line03_Curv                  \
    CA_CFG_SignalBasisAttr_IFC_Line03_CurvChange            \
    CA_CFG_SignalBasisAttr_IFC_Line04_Type                  \
    CA_CFG_SignalBasisAttr_IFC_Line04_Dy                    \
    CA_CFG_SignalBasisAttr_IFC_Line04_Curv                  \
    CA_CFG_SignalBasisAttr_IFC_Line04_CurvChange            \
    CA_CFG_SignalBasisAttr_IFC_Roadedge01_Type              \
    CA_CFG_SignalBasisAttr_IFC_Roadedge01_Dy                \
    CA_CFG_SignalBasisAttr_IFC_Roadedge01_Curv              \
    CA_CFG_SignalBasisAttr_IFC_Roadedge01_CurvChange        \
    CA_CFG_SignalBasisAttr_IFC_Roadedge02_Type              \
    CA_CFG_SignalBasisAttr_IFC_Roadedge02_Dy                \
    CA_CFG_SignalBasisAttr_IFC_Roadedge02_Curv              \
    CA_CFG_SignalBasisAttr_IFC_Roadedge02_CurvChange        \
    CA_CFG_SignalBasisAttr_IFC_Line01_HeadingAngle          \
    CA_CFG_SignalBasisAttr_IFC_Line02_HeadingAngle          \
    CA_CFG_SignalBasisAttr_IFC_Line03_HeadingAngle          \
    CA_CFG_SignalBasisAttr_IFC_Line04_HeadingAngle          \
    CA_CFG_SignalBasisAttr_IFC_Roadedge01_HeadingAngle      \
    CA_CFG_SignalBasisAttr_IFC_Roadedge02_HeadingAngle      \
    CA_CFG_SignalBasisAttr_ACC_PotentialTgtTyp              \
    CA_CFG_SignalBasisAttr_ACC_PotentialTgtDy               \
    CA_CFG_SignalBasisAttr_ACC_PotentialTgtDx               \
    CA_CFG_SignalBasisAttr_ACC_PotentialTgtHeading          \
    CA_CFG_SignalBasisAttr_ACC_PotentialTgtDetn             \
    CA_CFG_SignalBasisAttr_ACC_RlvTgtTyp                    \
    CA_CFG_SignalBasisAttr_ACC_RlvTgtDy                     \
    CA_CFG_SignalBasisAttr_ACC_RlvTgtDx                     \
    CA_CFG_SignalBasisAttr_ACC_RlvTgtHeading                \
    CA_CFG_SignalBasisAttr_ACC_RlvTgtDetn                   \
    CA_CFG_SignalBasisAttr_ACC_LeTgtTyp                     \
    CA_CFG_SignalBasisAttr_ACC_LeTgtDy                      \
    CA_CFG_SignalBasisAttr_ACC_LeTgtDx                      \
    CA_CFG_SignalBasisAttr_ACC_LeTgtHeading                 \
    CA_CFG_SignalBasisAttr_ACC_LeTargrtDection              \
    CA_CFG_SignalBasisAttr_ACC_RiTgtTyp                     \
    CA_CFG_SignalBasisAttr_ACC_RiTgtDy                      \
    CA_CFG_SignalBasisAttr_ACC_RiTgtDx                      \
    CA_CFG_SignalBasisAttr_ACC_RiTgtHeading                 \
    CA_CFG_SignalBasisAttr_ACC_RiTargrtDetn                 \
    CA_CFG_SignalBasisAttr_ACC_LeTgt_02_Typ                 \
    CA_CFG_SignalBasisAttr_ACC_LeTgt_02_Dy                  \
    CA_CFG_SignalBasisAttr_ACC_LeTgt_02_Dx                  \
    CA_CFG_SignalBasisAttr_ACC_LeTargrt_02_Detn             \
    CA_CFG_SignalBasisAttr_ACC_RiTgt_02_Typ                 \
    CA_CFG_SignalBasisAttr_ACC_RiTgt_02_Dy                  \
    CA_CFG_SignalBasisAttr_ACC_RiTgt_02_Dx                  \
    CA_CFG_SignalBasisAttr_ACC_RiTargrt_02_Detn             \
    CA_CFG_SignalBasisAttr_ACC_ModDisp                      \
    CA_CFG_SignalBasisAttr_TJA_ICA_ModDisp                  \
    CA_CFG_SignalBasisAttr_ACC_TgtObjBarDisp                \
    CA_CFG_SignalBasisAttr_ACC_FctSts                       \
    CA_CFG_SignalBasisAttr_HWA_InterSysInfoDisp             \
    CA_CFG_SignalBasisAttr_ACC_InterSysInfoDisp             \
    CA_CFG_SignalBasisAttr_TJA_ICA_InterSysInfoDisp         \
    CA_CFG_SignalBasisAttr_Request_driveoff                 \
    CA_CFG_SignalBasisAttr_HWA_ModDisp                      \
    CA_CFG_SignalBasisAttr_HWA_LaneChange                   \
    CA_CFG_SignalBasisAttr_HWA_LaneChangeReq                \
    CA_CFG_SignalBasisAttr_HWA_Resp                         \
    CA_CFG_SignalBasisAttr_ALC_Resp                         \
    CA_CFG_SignalBasisAttr_ACC_EgoStatus                    \
    CA_CFG_SignalBasisAttr_ACC_SpdSetValue                  \
    CA_CFG_SignalBasisAttr_ACC_TimeGapSet                   \
    CA_CFG_SignalBasisAttr_ISL_InterSysInfoDisp             \
    CA_CFG_SignalBasisAttr_LSSIntervention                  \
    CA_CFG_SignalBasisAttr_TJA_FollowSts                    \
    CA_CFG_SignalBasisAttr_IntelligentEvaActSts             \
    CA_CFG_SignalBasisAttr_LaneAvailability                 \
    CA_CFG_SignalBasisAttr_FCW_Warn                         \
    CA_CFG_SignalBasisAttr_AEB_VehTrig                      \
    CA_CFG_SignalBasisAttr_AEB_PedTrig                      \
    CA_CFG_SignalBasisAttr_AEB_JABrkTrig                    \
    CA_CFG_SignalBasisAttr_ACC_RiTgt_03_Typ                 \
    CA_CFG_SignalBasisAttr_ACC_RiTargrt_03_Detn             \
    CA_CFG_SignalBasisAttr_ACC_RiTgt_03_Dx                  \
    CA_CFG_SignalBasisAttr_ACC_RiTgt_03_Dy                  \
    CA_CFG_SignalBasisAttr_ACC_LeTgt_03_Typ                 \
    CA_CFG_SignalBasisAttr_ACC_LeTargrt_03_Detn             \
    CA_CFG_SignalBasisAttr_ACC_LeTgt_03_Dx                  \
    CA_CFG_SignalBasisAttr_ACC_LeTgt_03_Dy                  \
    CA_CFG_SignalBasisAttr_ACC_PotentialTgt_02_Heading      \
    CA_CFG_SignalBasisAttr_ACC_PotentialTgt_02_Typ          \
    CA_CFG_SignalBasisAttr_ACC_PotentialTgt_02_Detn         \
    CA_CFG_SignalBasisAttr_ACC_PotentialTgt_02_Dx           \
    CA_CFG_SignalBasisAttr_ACC_PotentialTgt_02_Dy           \
    CA_CFG_SignalBasisAttr_FCTA_Warn                        \
    CA_CFG_SignalBasisAttr_FCTBTrig                         \
    CA_CFG_SignalBasisAttr_SAS_Sts                          \
    CA_CFG_SignalBasisAttr_SteerWheelAng                    \
    CA_CFG_SignalBasisAttr_SteerWheelAngSign                \
    CA_CFG_SignalBasisAttr_IDC_L2_TurnLightReq              \
    CA_CFG_SignalBasisAttr_HWA_InhibitWarn                  \
    CA_CFG_SignalBasisAttr_HWA_WarnInfoDisp                 \
    CA_CFG_SignalBasisAttr_MRC_InterSysInfoDisp             \
    CA_CFG_SignalBasisAttr_HWA_ALC_Trig                     \
    CA_CFG_SignalBasisAttr_Stop_Mark_Detn                   \
    CA_CFG_SignalBasisAttr_Stop_Mark_Dx                     \
    CA_CFG_SignalBasisAttr_Zebra_Mark_Detn                  \
    CA_CFG_SignalBasisAttr_Zebra_Mark_Dx                    \
    CA_CFG_SignalBasisAttr_Grid_Mark_Detn                   \
    CA_CFG_SignalBasisAttr_Grid_Mark_Dx                     \
    CA_CFG_SignalBasisAttr_IFC_Line01_Source                \
    CA_CFG_SignalBasisAttr_IFC_Line02_Source                \
    CA_CFG_SignalBasisAttr_TSRSpdLim                        \
    CA_CFG_SignalBasisAttr_HWA_TakOver_Req                  \
    CA_CFG_SignalBasisAttr_AutoSpdSetSwt_Resp               \
    CA_CFG_SignalBasisAttr_NOH_Sts                          \
    CA_CFG_SignalBasisAttr_NOH_SysInfoDisplay               \
    CA_CFG_SignalBasisAttr_V2X_RLVW                         \
    CA_CFG_SignalBasisAttr_DrvDoorSts                       \
    CA_CFG_SignalBasisAttr_BrkPedalSts_BCM                  \
    CA_CFG_SignalBasisAttr_DrvDoorLockSts                   \
    CA_CFG_SignalBasisAttr_SrPosn_VR_APP                    \
    CA_CFG_SignalBasisAttr_PageUpSwtSts                     \
    CA_CFG_SignalBasisAttr_PageDwnSwtSts                    \
    CA_CFG_SignalBasisAttr_PageLSwtSts                      \
    CA_CFG_SignalBasisAttr_PageRSwtSts                      \
    CA_CFG_SignalBasisAttr_EnterSwtSts                      \
    CA_CFG_SignalBasisAttr_HomeSwtSts                       \
    CA_CFG_SignalBasisAttr_MenuReturnSwtSts                 \
    CA_CFG_SignalBasisAttr_CustomSwtSts                     \
    CA_CFG_SignalBasisAttr_IpMenuSwtSts                     \
    CA_CFG_SignalBasisAttr_AdjVolDwnSwtSts                  \
    CA_CFG_SignalBasisAttr_AdjVolUpSwtSts                   \
    CA_CFG_SignalBasisAttr_SeekDwnSwtSts                    \
    CA_CFG_SignalBasisAttr_SeekUpSwtSts                     \
    CA_CFG_SignalBasisAttr_EnterSwtSts_Mmed                 \
    CA_CFG_SignalBasisAttr_VRSwtSts                         \
    CA_CFG_SignalBasisAttr_MuteSwtSts                       \
    CA_CFG_SignalBasisAttr_CustomSwtSts_Mmed                \
    CA_CFG_SignalBasisAttr_Stat_PwrSv_Lvl                   \
    CA_CFG_SignalBasisAttr_HUD_BrightnessLvl                \
    CA_CFG_SignalBasisAttr_HUD_HeightLvl                    \
    CA_CFG_SignalBasisAttr_HUD_UIMod                        \
    CA_CFG_SignalBasisAttr_HUD_UIModVld                     \
    CA_CFG_SignalBasisAttr_HUD_SwtSts                       \
    CA_CFG_SignalBasisAttr_BaroPressure                     \
    CA_CFG_SignalBasisAttr_Urea_Level                       \
    CA_CFG_SignalBasisAttr_UreaRemainDist                   \
    CA_CFG_SignalBasisAttr_SCRSysWarnDisplay                \
    CA_CFG_SignalBasisAttr_SCRSysWarnDisplay_B2             \
    CA_CFG_SignalBasisAttr_ACAmbTemp                        \
    CA_CFG_SignalBasisAttr_TrqPrct                          \
    CA_CFG_SignalBasisAttr_PowerPrct                        \
    CA_CFG_SignalBasisAttr_VehLgtAccel                      \
    CA_CFG_SignalBasisAttr_VehLatAccel                      \
    CA_CFG_SignalBasisAttr_VehLgtAccelVld                   \
    CA_CFG_SignalBasisAttr_VehLatAccelVld                   \
    CA_CFG_SignalBasisAttr_EngOilPres                       \
    CA_CFG_SignalBasisAttr_EngOilTemp                       \
    CA_CFG_SignalBasisAttr_LowBeamSts_F_PBOX                \
    CA_CFG_SignalBasisAttr_LeftLightShowSts                 \
}

#define CA_CFG_Signal_List  \
{\
    CACANSignalRTENUM_DrivingModDis_0x145,                  \
    CACANSignalRTENUM_DrivingModDis_0x137,                  \
    CACANSignalRTENUM_ESPBrkLmpCtrl_0x137,                  \
    CACANSignalRTENUM_BSD_LCA_warningReqRight,              \
    CACANSignalRTENUM_BSD_LCA_warningReqleft,               \
    CACANSignalRTENUM_DOW_warningReqRight,                  \
    CACANSignalRTENUM_DOW_warningReqleft,                   \
    CACANSignalRTENUM_IFC_Line01_Type,                      \
    CACANSignalRTENUM_IFC_Line01_Dy,                        \
    CACANSignalRTENUM_IFC_Line01_Curv,                      \
    CACANSignalRTENUM_IFC_Line01_CurvChange,                \
    CACANSignalRTENUM_IFC_Line02_Type,                      \
    CACANSignalRTENUM_IFC_Line02_Dy,                        \
    CACANSignalRTENUM_IFC_Line02_Curv,                      \
    CACANSignalRTENUM_IFC_Line02_CurvChange,                \
    CACANSignalRTENUM_IFC_Line03_Type,                      \
    CACANSignalRTENUM_IFC_Line03_Dy,                        \
    CACANSignalRTENUM_IFC_Line03_Curv,                      \
    CACANSignalRTENUM_IFC_Line03_CurvChange,                \
    CACANSignalRTENUM_IFC_Line04_Type,                      \
    CACANSignalRTENUM_IFC_Line04_Dy,                        \
    CACANSignalRTENUM_IFC_Line04_Curv,                      \
    CACANSignalRTENUM_IFC_Line04_CurvChange,                \
    CACANSignalRTENUM_IFC_Roadedge01_Type,                  \
    CACANSignalRTENUM_IFC_Roadedge01_Dy,                    \
    CACANSignalRTENUM_IFC_Roadedge01_Curv,                  \
    CACANSignalRTENUM_IFC_Roadedge01_CurvChange,            \
    CACANSignalRTENUM_IFC_Roadedge02_Type,                  \
    CACANSignalRTENUM_IFC_Roadedge02_Dy,                    \
    CACANSignalRTENUM_IFC_Roadedge02_Curv,                  \
    CACANSignalRTENUM_IFC_Roadedge02_CurvChange,            \
    CACANSignalRTENUM_IFC_Line01_HeadingAngle,              \
    CACANSignalRTENUM_IFC_Line02_HeadingAngle,              \
    CACANSignalRTENUM_IFC_Line03_HeadingAngle,              \
    CACANSignalRTENUM_IFC_Line04_HeadingAngle,              \
    CACANSignalRTENUM_IFC_Roadedge01_HeadingAngle,          \
    CACANSignalRTENUM_IFC_Roadedge02_HeadingAngle,          \
    CACANSignalRTENUM_ACC_PotentialTgtTyp,                  \
    CACANSignalRTENUM_ACC_PotentialTgtDy,                   \
    CACANSignalRTENUM_ACC_PotentialTgtDx,                   \
    CACANSignalRTENUM_ACC_PotentialTgtHeading,              \
    CACANSignalRTENUM_ACC_PotentialTgtDetn,                 \
    CACANSignalRTENUM_ACC_RlvTgtTyp,                        \
    CACANSignalRTENUM_ACC_RlvTgtDy,                         \
    CACANSignalRTENUM_ACC_RlvTgtDx,                         \
    CACANSignalRTENUM_ACC_RlvTgtHeading,                    \
    CACANSignalRTENUM_ACC_RlvTgtDetn,                       \
    CACANSignalRTENUM_ACC_LeTgtTyp,                         \
    CACANSignalRTENUM_ACC_LeTgtDy,                          \
    CACANSignalRTENUM_ACC_LeTgtDx,                          \
    CACANSignalRTENUM_ACC_LeTgtHeading,                     \
    CACANSignalRTENUM_ACC_LeTargrtDection,                  \
    CACANSignalRTENUM_ACC_RiTgtTyp,                         \
    CACANSignalRTENUM_ACC_RiTgtDy,                          \
    CACANSignalRTENUM_ACC_RiTgtDx,                          \
    CACANSignalRTENUM_ACC_RiTgtHeading,                     \
    CACANSignalRTENUM_ACC_RiTargrtDetn,                     \
    CACANSignalRTENUM_ACC_LeTgt_02_Typ,                     \
    CACANSignalRTENUM_ACC_LeTgt_02_Dy,                      \
    CACANSignalRTENUM_ACC_LeTgt_02_Dx,                      \
    CACANSignalRTENUM_ACC_LeTargrt_02_Detn,                 \
    CACANSignalRTENUM_ACC_RiTgt_02_Typ,                     \
    CACANSignalRTENUM_ACC_RiTgt_02_Dy,                      \
    CACANSignalRTENUM_ACC_RiTgt_02_Dx,                      \
    CACANSignalRTENUM_ACC_RiTargrt_02_Detn,                 \
    CACANSignalRTENUM_ACC_ModDisp,                          \
    CACANSignalRTENUM_TJA_ICA_ModDisp,                      \
    CACANSignalRTENUM_ACC_TgtObjBarDisp,                    \
    CACANSignalRTENUM_ACC_FctSts,                           \
    CACANSignalRTENUM_HWA_InterSysInfoDisp,                 \
    CACANSignalRTENUM_ACC_InterSysInfoDisp,                 \
    CACANSignalRTENUM_TJA_ICA_InterSysInfoDisp,             \
    CACANSignalRTENUM_Request_driveoff,                     \
    CACANSignalRTENUM_HWA_ModDisp,                          \
    CACANSignalRTENUM_HWA_LaneChange,                       \
    CACANSignalRTENUM_HWA_LaneChangeReq,                    \
    CACANSignalRTENUM_HWA_Resp,                             \
    CACANSignalRTENUM_ALC_Resp,                             \
    CACANSignalRTENUM_ACC_EgoStatus,                        \
    CACANSignalRTENUM_ACC_SpdSetValue,                      \
    CACANSignalRTENUM_ACC_TimeGapSet,                       \
    CACANSignalRTENUM_ISL_InterSysInfoDisp,                 \
    CACANSignalRTENUM_LSSIntervention,                      \
    CACANSignalRTENUM_TJA_FollowSts,                        \
    CACANSignalRTENUM_IntelligentEvaActSts,                 \
    CACANSignalRTENUM_LaneAvailability,                     \
    CACANSignalRTENUM_FCW_Warn,                             \
    CACANSignalRTENUM_AEB_VehTrig,                          \
    CACANSignalRTENUM_AEB_PedTrig,                          \
    CACANSignalRTENUM_AEB_JABrkTrig,                        \
    CACANSignalRTENUM_ACC_RiTgt_03_Typ,                     \
    CACANSignalRTENUM_ACC_RiTargrt_03_Detn,                 \
    CACANSignalRTENUM_ACC_RiTgt_03_Dx,                      \
    CACANSignalRTENUM_ACC_RiTgt_03_Dy,                      \
    CACANSignalRTENUM_ACC_LeTgt_03_Typ,                     \
    CACANSignalRTENUM_ACC_LeTargrt_03_Detn,                 \
    CACANSignalRTENUM_ACC_LeTgt_03_Dx,                      \
    CACANSignalRTENUM_ACC_LeTgt_03_Dy,                      \
    CACANSignalRTENUM_ACC_PotentialTgt_02_Heading,          \
    CACANSignalRTENUM_ACC_PotentialTgt_02_Typ,              \
    CACANSignalRTENUM_ACC_PotentialTgt_02_Detn,             \
    CACANSignalRTENUM_ACC_PotentialTgt_02_Dx,               \
    CACANSignalRTENUM_ACC_PotentialTgt_02_Dy,               \
    CACANSignalRTENUM_FCTA_Warn,                            \
    CACANSignalRTENUM_FCTBTrig,                             \
    CACANSignalRTENUM_SAS_Sts,                              \
    CACANSignalRTENUM_SteerWheelAng,                        \
    CACANSignalRTENUM_SteerWheelAngSign,                    \
    CACANSignalRTENUM_IDC_L2_TurnLightReq,                  \
    CACANSignalRTENUM_HWA_InhibitWarn,                      \
    CACANSignalRTENUM_HWA_WarnInfoDisp,                     \
    CACANSignalRTENUM_MRC_InterSysInfoDisp,                 \
    CACANSignalRTENUM_HWA_ALC_Trig,                         \
    CACANSignalRTENUM_Stop_Mark_Detn,                       \
    CACANSignalRTENUM_Stop_Mark_Dx,                         \
    CACANSignalRTENUM_Zebra_Mark_Detn,                      \
    CACANSignalRTENUM_Zebra_Mark_Dx,                        \
    CACANSignalRTENUM_Grid_Mark_Detn,                       \
    CACANSignalRTENUM_Grid_Mark_Dx,                         \
    CACANSignalRTENUM_IFC_Line01_Source,                    \
    CACANSignalRTENUM_IFC_Line02_Source,                    \
    CACANSignalRTENUM_TSRSpdLim,                            \
    CACANSignalRTENUM_HWA_TakOver_Req,                      \
    CACANSignalRTENUM_AutoSpdSetSwt_Resp,                   \
    CACANSignalRTENUM_NOH_Sts,                              \
    CACANSignalRTENUM_NOH_SysInfoDisplay,                   \
    CACANSignalRTENUM_V2X_RLVW,                             \
    CACANSignalRTENUM_DrvDoorSts,                           \
    CACANSignalRTENUM_BrkPedalSts_BCM,                      \
    CACANSignalRTENUM_DrvDoorLockSts,                       \
    CACANSignalRTENUM_SrPosn_VR_APP,                        \
    CACANSignalRTENUM_PageUpSwtSts,                         \
    CACANSignalRTENUM_PageDwnSwtSts,                        \
    CACANSignalRTENUM_PageLSwtSts,                          \
    CACANSignalRTENUM_PageRSwtSts,                          \
    CACANSignalRTENUM_EnterSwtSts,                          \
    CACANSignalRTENUM_HomeSwtSts,                           \
    CACANSignalRTENUM_MenuReturnSwtSts,                     \
    CACANSignalRTENUM_CustomSwtSts,                         \
    CACANSignalRTENUM_IpMenuSwtSts,                         \
    CACANSignalRTENUM_AdjVolDwnSwtSts,                      \
    CACANSignalRTENUM_AdjVolUpSwtSts,                       \
    CACANSignalRTENUM_SeekDwnSwtSts,                        \
    CACANSignalRTENUM_SeekUpSwtSts,                         \
    CACANSignalRTENUM_EnterSwtSts_Mmed,                     \
    CACANSignalRTENUM_VRSwtSts,                             \
    CACANSignalRTENUM_MuteSwtSts,                           \
    CACANSignalRTENUM_CustomSwtSts_Mmed,                    \
    CACANSignalRTENUM_Stat_PwrSv_Lvl,                       \
    CACANSignalRTENUM_HUD_BrightnessLvl,                    \
    CACANSignalRTENUM_HUD_HeightLvl,                        \
    CACANSignalRTENUM_HUD_UIMod,                            \
    CACANSignalRTENUM_HUD_UIModVld,                         \
    CACANSignalRTENUM_HUD_SwtSts,                           \
    CACANSignalRTENUM_BaroPressure,                         \
    CACANSignalRTENUM_Urea_Level,                           \
    CACANSignalRTENUM_UreaRemainDist,                       \
    CACANSignalRTENUM_SCRSysWarnDisplay,                    \
    CACANSignalRTENUM_SCRSysWarnDisplay_B2,                 \
    CACANSignalRTENUM_ACAmbTemp,                            \
    CACANSignalRTENUM_TrqPrct,                              \
    CACANSignalRTENUM_PowerPrct,                            \
    CACANSignalRTENUM_VehLgtAccel,                          \
    CACANSignalRTENUM_VehLatAccel,                          \
    CACANSignalRTENUM_VehLgtAccelVld,                       \
    CACANSignalRTENUM_VehLatAccelVld,                       \
    CACANSignalRTENUM_EngOilPres,                           \
    CACANSignalRTENUM_EngOilTemp,                           \
    CACANSignalRTENUM_LowBeamSts_F_PBOX,                    \
    CACANSignalRTENUM_LeftLightShowSts,                     \
}

#define CA_CFG_Signal_Status_Table	\
{\
/* Pro_B02,  Pro_P05,     Pro_P03,     Pro_A07,     Pro_D01,     Pro_D02,     Pro_D03,     Pro_P02,     Pro_P01,                                                                                   */\
{CA_Invalid, CA_Valid,    CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  }, /* DrivingModDis_0x145 */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* DrivingModDis_0x137 */\
{CA_Invalid, CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  }, /* ESPBrkLmpCtrl_0x137 */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* BSD_LCA_warningReqRight */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* BSD_LCA_warningReqleft */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* DOW_warningReqRight */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* DOW_warningReqleft */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line01_Type */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line01_Dy */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line01_Curv */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line01_CurvChange */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line02_Type */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line02_Dy */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line02_Curv */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line02_CurvChange */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line03_Type */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line03_Dy */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line03_Curv */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line03_CurvChange */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line04_Type */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line04_Dy */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line04_Curv */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line04_CurvChange */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Roadedge01_Type */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Roadedge01_Dy */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Roadedge01_Curv */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Roadedge01_CurvChange */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Roadedge02_Type */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Roadedge02_Dy */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Roadedge02_Curv */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Roadedge02_CurvChange */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line01_HeadingAngle */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line02_HeadingAngle */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line03_HeadingAngle */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Line04_HeadingAngle */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Roadedge01_HeadingAngle */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IFC_Roadedge02_HeadingAngle */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_PotentialTgtTyp */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_PotentialTgtDy */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_PotentialTgtDx */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_PotentialTgtHeading */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_PotentialTgtDetn */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_RlvTgtTyp */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_RlvTgtDy */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_RlvTgtDx */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_RlvTgtHeading */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_RlvTgtDetn */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_LeTgtTyp */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_LeTgtDy */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_LeTgtDx */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_LeTgtHeading */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_LeTargrtDection */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_RiTgtTyp */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_RiTgtDy */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_RiTgtDx */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_RiTgtHeading */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_RiTargrtDetn */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_LeTgt_02_Typ */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_LeTgt_02_Dy */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_LeTgt_02_Dx */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_LeTargrt_02_Detn */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_RiTgt_02_Typ */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_RiTgt_02_Dy */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_RiTgt_02_Dx */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_RiTargrt_02_Detn */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_ModDisp */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* TJA_ICA_ModDisp */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_TgtObjBarDisp */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_FctSts */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* HWA_InterSysInfoDisp */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_InterSysInfoDisp */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* TJA_ICA_InterSysInfoDisp */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* Request_driveoff */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* HWA_ModDisp */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* HWA_LaneChange */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* HWA_LaneChangeReq */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* HWA_Resp */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ALC_Resp */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_EgoStatus */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_SpdSetValue */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACC_TimeGapSet */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ISL_InterSysInfoDisp */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* LSSIntervention */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* TJA_FollowSts */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IntelligentEvaActSts */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* LaneAvailability */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* FCW_Warn */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* AEB_VehTrig */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* AEB_PedTrig */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* AEB_JABrkTrig */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* ACC_RiTgt_03_Typ */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* ACC_RiTargrt_03_Detn */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* ACC_RiTgt_03_Dx */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* ACC_RiTgt_03_Dy */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* ACC_LeTgt_03_Typ */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* ACC_LeTargrt_03_Detn */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* ACC_LeTgt_03_Dx */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* ACC_LeTgt_03_Dy */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* ACC_PotentialTgt_02_Heading */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* ACC_PotentialTgt_02_Typ */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* ACC_PotentialTgt_02_Detn */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* ACC_PotentialTgt_02_Dx */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* ACC_PotentialTgt_02_Dy */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* FCTA_Warn */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* FCTBTrig */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* SAS_Sts */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* SteerWheelAng */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* SteerWheelAngSign */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* IDC_L2_TurnLightReq */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* HWA_InhibitWarn */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* HWA_WarnInfoDisp */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* MRC_InterSysInfoDisp */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* HWA_ALC_Trig */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* Stop_Mark_Detn */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* Stop_Mark_Dx */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* Zebra_Mark_Detn */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* Zebra_Mark_Dx */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* Grid_Mark_Detn */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* Grid_Mark_Dx */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* IFC_Line01_Source */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* IFC_Line02_Source */\
{CA_Invalid, CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  }, /* TSRSpdLim */\
{CA_Invalid, CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  }, /* HWA_TakOver_Req */\
{CA_Invalid, CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  }, /* AutoSpdSetSwt_Resp */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* NOH_Sts */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* NOH_SysInfoDisplay */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Invalid,  }, /* V2X_RLVW */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* DrvDoorSts */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* BrkPedalSts_BCM */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* DrvDoorLockSts */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* SrPosn_VR_APP */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* PageUpSwtSts */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* PageDwnSwtSts */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* PageLSwtSts */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* PageRSwtSts */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* EnterSwtSts */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* HomeSwtSts */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* MenuReturnSwtSts */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* CustomSwtSts */\
{CA_Invalid, CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* IpMenuSwtSts */\
{CA_Invalid, CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* AdjVolDwnSwtSts */\
{CA_Invalid, CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* AdjVolUpSwtSts */\
{CA_Invalid, CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* SeekDwnSwtSts */\
{CA_Invalid, CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* SeekUpSwtSts */\
{CA_Invalid, CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* EnterSwtSts_Mmed */\
{CA_Invalid, CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* VRSwtSts */\
{CA_Invalid, CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* MuteSwtSts */\
{CA_Invalid, CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* CustomSwtSts_Mmed */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* Stat_PwrSv_Lvl */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* HUD_BrightnessLvl */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* HUD_HeightLvl */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* HUD_UIMod */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* HUD_UIModVld */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* HUD_SwtSts */\
{CA_Invalid, CA_Valid,    CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* BaroPressure */\
{CA_Invalid, CA_Valid,    CA_Valid,    CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    }, /* Urea_Level */\
{CA_Invalid, CA_Valid,    CA_Valid,    CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    }, /* UreaRemainDist */\
{CA_Invalid, CA_Valid,    CA_Valid,    CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    }, /* SCRSysWarnDisplay */\
{CA_Invalid, CA_Valid,    CA_Valid,    CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    }, /* SCRSysWarnDisplay_B2 */\
{CA_Valid,   CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* ACAmbTemp */\
{CA_Valid,   CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Invalid,  }, /* TrqPrct */\
{CA_Valid,   CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Invalid,  }, /* PowerPrct */\
{CA_Valid,   CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    }, /* VehLgtAccel */\
{CA_Valid,   CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    }, /* VehLatAccel */\
{CA_Valid,   CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    }, /* VehLgtAccelVld */\
{CA_Valid,   CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    }, /* VehLatAccelVld */\
{CA_Invalid, CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* EngOilPres */\
{CA_Invalid, CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    }, /* EngOilTemp */\
{CA_Invalid, CA_Invalid,  CA_Valid,    CA_Invalid,  CA_Valid,    CA_Valid,    CA_Valid,    CA_Valid,    CA_Invalid,  }, /* LowBeamSts_F_PBOX */\
{CA_Invalid, CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  CA_Invalid,  }, /* LeftLightShowSts */\
}

#define SWC_CA_START_SEC_CODE
#include "SWC_CA_MemMap.h"

void vCA_Adapt_VconfigInit(void);
uint8 u8CA_Process_GetSignalStatus(enCACFGSIGNALINDEX enSignalID);
uint32 u32CA_Process_GetSignalValue(enCACFGSIGNALINDEX enSignalID);
uint8 u32CA_Process_GetMsgTimeoutStatus(enCACFGMSGINDEX enMsgID);


void vCA_Process_Init(void);
void vCA_Process_msTassk(void);

#define SWC_CA_STOP_SEC_CODE
#include "SWC_CA_MemMap.h"


#endif


/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/

