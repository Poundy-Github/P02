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
*File Name   : TT_Adapt.h                                                                                 *
*                                                                                                         *
*Description : Telltale module adaptation head file.                                                      *
*                                                                                                         *
*Author      : Chao Feng                                                                                  *
*                                                                                                         *
*Platform    : Free Rtos System                                                    						  *
*                                                                                                         *
*Compiler    : Green Hills MULTI IDE                                                                      *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family                                                       *
*                                                                                                         *
*Version     : 1.0.0                                                                                      *
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef TT_ADAPT_H
#define TT_ADAPT_H
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_TT_Config.h"
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "Rte_Common_Normal.h"



//请注: 请在这个文件内添加引用外部的头文件
/**********************************************************************************************************
* Work Mode Configuration 																				  *
**********************************************************************************************************/

//#define TT_CFG_POWER_STATE                            NORMAL
#define TT_CFG_POWER_STATE                         TRUE/*(FSM_u8Get_SuperState())The power state from power module*/
#define TT_CFG_HMI_POWER_STATE					   TRUE//(HMI_vGetHmiCallBackPower())

//此宏定义用于表示电源状态
/*********************************************************************************************************/

#define TT_CFG_POWER_STATE_IS_OFF                  FALSE//(LIMITED == TT_CFG_POWER_STATE)
#define TT_CFG_POWER_STATE_IS_RUN                  TRUE//(NORMAL == TT_CFG_POWER_STATE && e_POWER_NORMAL == TT_CFG_HMI_POWER_STATE)
#define TT_CFG_POWER_STATE_IS_ABNORMAL             FALSE//(ABNVOLT == TT_CFG_POWER_STATE)

//此宏定义用于表示电源状态成立的条件,分别用于标定模块工作状态
/**********************************************************************************************************
* External Control Mode Configuration 																	  *
**********************************************************************************************************/
#define TT_CFG_OFF               ((boolean)0)
#define TT_CFG_ON                ((boolean)1)

#define TT_CFG_DIAGNOSIS_MODE_ENABLE               FALSE//(DCM_D363_WorkEnable() == TRUE) //TODO(DCM_D363_WorkEnable() == TRUE)

//此宏定义用于表示诊断控制成立的条件
/*********************************************************************************************************/

#define TT_CFG_EOL_MODE_ENABLE                     FALSE//(EOL_API_boGetTelltaleIndicatorWorkEnableStatus()== TRUE)

//此宏定义用于表示工厂控制成立的条件
/**********************************************************************************************************
* GPIO Ouptput Configuration 																		      *
**********************************************************************************************************/
#if ((TT_CFG_OUTPUT_MODE&TT_CFG_OUTPUT_USE_GPIO) != FALSE)

#define TT_CFG_GPIO_CONTROL_LEVEL_UP(Parameter)			()//GPIO_SetPinLevel((GPIO_tenPin)Parameter,HIGH)

#define TT_CFG_GPIO_CONTROL_LEVEL_DOWN(Parameter)		()//GPIO_SetPinLevel((GPIO_tenPin)Parameter,LOW)

#endif //((TT_CFG_OUTPUT_MODE&TT_CFG_OUTPUT_USE_GPIO) != FALSE)
//此宏定义用于表示GPIO输出方式
/**********************************************************************************************************
* STM Ouptput Configuration 																			  *
**********************************************************************************************************/
#if ((TT_CFG_OUTPUT_MODE&TT_CFG_OUTPUT_USE_STM) != FALSE)

#define TT_CFG_STM_CONTROL_LEVEL_UP(Parameter)			()//TP596_vSetTTLed((TP596_enLED_TYPE)Parameter,HIGH)

#define TT_CFG_STM_CONTROL_LEVEL_DOWN(Parameter)		()//TP596_vSetTTLed((TP596_enLED_TYPE)Parameter,LOW)

#endif //((TT_CFG_OUTPUT_MODE&TT_CFG_OUTPUT_USE_STM) != FALSE)
//此宏定义用于表示串转并输出方式
/**********************************************************************************************************
* CAN Ouptput Configuration 																			  *
**********************************************************************************************************/
#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_CAN) != FALSE)

#define TT_CFG_SEND_TELLTALE_STATUS_CAN_MSG(Message)    ()

#endif //((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_CAN) != FALSE)
//此宏定义用于表示CAN信号输出方式
/**********************************************************************************************************
* SBUS Ouptput Configuration 																			  *
**********************************************************************************************************/
#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_SBUS) != FALSE)

#define TT_CFG_SEND_TELLTALE_STATUS_SBUS_MSG(Message)   \
{\
	();/*NW_SIL_TX_Telltale_1_DATA(Message[0]);*/\
	();/*NW_SIL_TX_Telltale_2_DATA(Message[1]);*/\
	();/*NW_SIL_TX_Telltale_3_DATA(Message[2]);*/\
	();/*NW_SIL_TX_Telltale_4_DATA(Message[3]);*/\
	();/*NW_SIL_TX_Telltale_5_DATA(Message[4]);*/\
}

#endif //((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_SBUS) != FALSE)
typedef enum
{
  TT_NO_SIGNAL,
  TT_CAN_SIGNAL,
  TT_CANFD_SIGNAL
}TT_SIGNAL_SOURCE;
/*
  1.TT_NO_SIGNAL
  2.TT_CAN_SIGNAL
  3.TT_CANFD_SIGNAL */

typedef enum
{
  TT_NO_DOMAIN,
  TT_DOMAIN_CH,
  TT_DOMAIN_US
}TT_DOMAIN_INFO;
/*
  1.TT_NO_DOMAIN
  2.TT_DOMAIN_CH
  3.TT_DOMAIN_US */
 typedef enum
{
	TTconfigLowFuelDelayTime = 0,
	TTconfigLowFuelCheckTime,
	TTconfigEPBlightorflashtime,
	TTconfigTpms_flashtime,
}tt_InternalConfig_t;

typedef enum
{
	Engine_Stop = 0,
	Engine_Running
}TT_Engine_Running_Status;

typedef struct
{
	uint8 u8LowFuelDelayTime;
	uint8 u8LowFuelCheckTime;
	uint16 u16EPBlightorflashtime;
	uint16 u16Tpms_flashtime;
}tt_InternalConfigData_t;

#define SWC_TT_START_SEC_CODE
#include "SWC_TT_MemMap.h"

TT_DOMAIN_INFO FTT_vDomain_Logic_Process(void);
TT_SIGNAL_SOURCE TT_Adapt_Signal_Source(void);

uint8 FTT_Adapt_GetVconfig(uint16 id_u8);
uint16 FTT_AdaptGetInternalconfig(tt_InternalConfig_t id_u8);
void FTT_RteAdaptGetAllConfig(void);
uint8 FTT_Adapt_GetPowerMode_State(void);

uint8 FTT_Adapt_GetMessage_GentrWarnLmpSts(uint8 *data);
uint8 FTT_Adapt_GetHW_C2(uint32 *data);
uint8 FTT_Adapt_GetHW_C3(uint8 *data);
uint8 FTT_Adapt_GetMessage_EngSpdVldty(uint8 *data);
uint8 FTT_Adapt_GetMessage_TachoInfo(s_TachoInfo_t *data);
uint8 FTT_Adapt_GetMessage_MILSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_TRANS_Warning_LAMP(uint8 *data);
uint8 FTT_Adapt_GetMessage_EngSVSSig(uint8 *data);
uint8 FTT_Adapt_GetMessage_EngClntTempWarn(uint8 *data);
uint8 FTT_Adapt_GetMessage_CruiseCtrlSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_CruiseCtrlSts_PHEV(uint8 *data);
uint8 FTT_Adapt_GetMessage_SS_Enable_Lamp(uint8 *data);
uint8 FTT_Adapt_GetMessage_SS_Fault_Lamp(uint8 *data);
uint8 FTT_Adapt_GetMessage_TirePressSysFailrIndcn(uint8 *data);
uint8 FTT_Adapt_GetMessage_FLTirePressIndSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_FRTirePressIndSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_RLTirePressIndSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_RRTirePressIndSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_FLTireTempSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_FRTireTempSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_RLTireTempSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_RRTireTempSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_SG_EPS1(uint8 *data);
//uint8 FTT_Adapt_GetMessage_IFC4_IFC_FD2(SG_IFC4_IFC_FD2 *data);
uint8 FTT_Adapt_GetMessage_LSSFuncSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_LSSErrSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_IFCCalibrationSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_CameraBlockageSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_BMS4_PBF(uint8 *data);
uint8 FTT_Adapt_GetMessage_AVHSts(uint8 *data_s,uint8 *data_t);
uint8 FTT_Adapt_GetMessage_HDCSts(uint8 *data_s,uint8 *data_t);
uint8 FTT_Adapt_GetMessage_CDPActv(uint8 *data);
uint8 FTT_Adapt_GetMessage_EPBRedLmpSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_FFogLmpSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_RFogLmpSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_RHiBeamSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_LHiBeamSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_HighBeamSts_HC(uint8 *data);
uint8 FTT_Adapt_GetMessage_HiBeamSts_F_PBOX(uint8 *data);
//uint8 FTT_Adapt_GetMessage_HighBeamSts_FCM(uint8 *data);
uint8 FTT_Adapt_GetMessage_LTurnLmpSts_R_PBOX(uint8 *data);
uint8 FTT_Adapt_GetMessage_RTurnLmpSts_R_PBOX(uint8 *data);
uint8 FTT_Adapt_GetMessage_PosnLmpOutpSts_R_PBOX(uint8 *data);
uint8 FTT_Adapt_GetMessage_TrailerSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_DrvDoorSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_HoodSts_F_Pbox(uint8 *data);
uint8 FTT_Adapt_GetMessage_PassengerDoorSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_LRDoorSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_RRDoorSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_TrunkSts(uint8 *data);
//uint8 FTT_Adapt_GetMessage_SG_ABM1(SG_ABM1 *data);
uint8 FTT_Adapt_GetMessage_DrvSBR_Visual(uint8 *data);
uint8 FTT_Adapt_GetMessage_PassSBR_Visual(uint8 *data);
uint8 FTT_Adapt_GetMessage_SecRowLSBR_Visual(uint8 *data);
uint8 FTT_Adapt_GetMessage_SecRowMidSBR_Visual(uint8 *data);
uint8 FTT_Adapt_GetMessage_SecRowRSBR_Visual(uint8 *data);
uint8 FTT_Adapt_GetMessage_DrvWarnMsg(uint8 *data);
uint8 FTT_Adapt_GetMessage_ClutchHotWarning(uint8 *data);
uint8 FTT_Adapt_GetMessage_Warn_high_temp(uint8 *data);
uint8 FTT_Adapt_GetMessage_HiLowBeamSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_ADBstatus(uint8 *data);
uint8 FTT_Adapt_GetMessage_LADBstatus(uint8 *data);
uint8 FTT_Adapt_GetMessage_RADBstatus(uint8 *data);
uint8 FTT_Adapt_GetFuelModule_Data(FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE *data);
uint8 FTT_Adapt_GetSelfChecksts(uint8 *data);
//uint8 FTT_Adapt_GetMessage_SG_AEB2(SG_AEB2_AEB_FD2 *data);
//uint8 FTT_Adapt_GetMessage_SG_AEB3(SG_AEB3_AEB_FD2 *data);
uint8 FTT_Adapt_GetMessage_RdyLmpSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_EVLmpSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_ChrgSysLmpSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_PowerRedWarnLmpCmd(uint8 *data);
uint8 FTT_Adapt_GetMessage_ParkLmpSts_R_Pbox(uint8 *data);
uint8 FTT_Adapt_GetMessage_ESP_TgtRcprtnTrqSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_HCU_TgtRcprtnTrqSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_EB_TgtRcprtnTrqSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_GlowPlugLmpCmd(uint8 *data);
uint8 FTT_Adapt_GetMessage_CCO_Active(uint8 *data);
uint8 FTT_Adapt_GetMessage_RearELDLckSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_FrntELDLckSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_RSDS_CTA_Actv(uint8 *data);
uint8 FTT_Adapt_GetMessage_RSDS_LCAResp(uint8 *data);
uint8 FTT_Adapt_GetMessage_RSDS_ErrSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_RemoteModSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_RSDS_BliSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_KL30BRelaySts(uint8 *data);
uint8 FTT_Adapt_GetMessage_TAB_Sts(uint8 *data);
uint8 FTT_Adapt_GetMessage_Builtin_VSG_Sts(uint8 *data);
uint8 FTT_Adapt_GetMessage_SOCLowWarn(uint8 *data);
uint8 FTT_Adapt_GetMessage_OPDLmpSts(uint8 *data);
uint8 FTT_Adapt_GetOverSpdWrnFlg(uint8 *data);
uint8 FTT_Adapt_GetMessage_TSRSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_TSRSpdLim(uint8 *data);
uint8 FTT_Adapt_GetMessage_TSRSpdLimSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_TSRSpdLimWarn(uint8 *data);
uint8 FTT_Adapt_GetMessage_TSRTrfcSignVal(uint8 *data);
uint8 FTT_Adapt_GetMessage_WIFSensorFailSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_WIFFullLmpCmd(uint8 *data);
uint8 FTT_Adapt_GetMessage_UreaLampCmd(uint8 *data);
uint8 FTT_Adapt_GetEngRunSts(void);
uint8 FTT_Adapt_GetMessage_ESP_HMI_WarningOn(uint8 *data);
uint8 FTT_Adapt_GetMessage_IB_Warn(uint8 *data);
uint8 FTT_Adapt_GetMessage_V2XGLOSA(uint8 *data);
uint8 FTT_Adapt_GetMessage_V2XSLW(uint8 *data);
uint8 FTT_Adapt_GetMessage_V2XIVSW(uint8 *data);
uint8 FTT_Adapt_GetMessage_V2XSLXL(uint8 u8LaneNum, uint8 *data_type, uint8 *data_color, uint16 *data_time);
uint8 FTT_Adapt_GetMessage_V2XSLV(uint8 *data);
uint8 FTT_Adapt_GetMessage_LvlCtrlWarnLmpReq(uint8 *data);
uint8 FTT_Adapt_GetMessage_RSCAOFFSts(uint8 *data);
uint8 FTT_Adapt_GetMessage_TrunkSts_Y(uint8 *data);
uint8 FTT_Adapt_GetMessage_EngOilLowPresWrn(uint8 *data);
uint8 FTT_Adapt_GetMessage_CentralDiffLockLightSts(uint8 *data);
void FTT_Api_TTCallback(uint8 *data);

#define SWC_TT_STOP_SEC_CODE
#include "SWC_TT_MemMap.h"

/*********************************************************************************************************/
#endif //TT_ADAPT_H
/**********************************************************************************************************
*  End Of File																							  *
**********************************************************************************************************/
