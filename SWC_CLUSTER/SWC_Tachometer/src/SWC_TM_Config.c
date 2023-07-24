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
*File Name   : TM_Config.c                                                                                *
*                                                                                                         *
*Description : Tachometer module source code file.                                                   	  *
*                                                                                                         *
*Author      : Chao Feng                                                                                  *
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

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_TM_Config.h"
#include "SWC_TM_Core.h"
#include "CConfig_Cfg.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Formula Configuration																				  *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*Function   : TM_CFG_vFormulaOfGetEngineSpeedFromCANRawValue                                              *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: TM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#define SWC_TM_START_SEC_CODE
#include "SWC_TM_MemMap.h" 

extern boolean l_TMDebugLogFlag;
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
void TM_CFG_vFormulaOfGetEngineSpeedFromCANRawValue(TM_CFG_tstMAIN_OBJECT* stMainObject)
{
	uint16 u16EngSpdVal = 0;
	uint16 u16TgtEngSpdVal = 0;
	uint8 u8TgtEngSpdValid = 0;
	uint8 u8DCT3StatusRet = 0;
	uint16 u16EngSpd_ECM1 = 0;
	uint8 u8ECM1StatusRet = 0;
	uint8 u8ECM11StatusRet = 0;
	uint8 u8EngSpdValid = 0;
	
#ifdef GWM_V35_PROJECT_TYPE_B02_TM
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u16EngSpdVal, (uint8)sizeof(u16EngSpdVal));
	u8DCT3StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIP, (uint8 *)&u16TgtEngSpdVal, (uint8)sizeof(u16TgtEngSpdVal));
	u8DCT3StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD, (uint8 *)&u16EngSpd_ECM1, (uint8)sizeof(u16EngSpd_ECM1));
#elif defined GWM_V35_PROJECT_TYPE_B03_TM
	Rte_Read_EngSpd_ForIP_EngSpd_ForIP(&u16EngSpdVal);
	u8DCT3StatusRet |= Rte_Read_DCT3_TgtEngSpdIP_TgtEngSpdIP(&u16TgtEngSpdVal);
	u8DCT3StatusRet |= Rte_Read_DCT3_TgtEngSpdIPValid_TgtEngSpdIPValid(&u8TgtEngSpdValid);
	Rte_Read_EngSpd_EngSpd(&u16EngSpd_ECM1);
#elif defined GWM_V35_PROJECT_TYPE_P03_TM
	u8ECM11StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u16EngSpdVal, (uint8)sizeof(u16EngSpdVal));
	u8DCT3StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIP, (uint8 *)&u16TgtEngSpdVal, (uint8)sizeof(u16TgtEngSpdVal));
	u8DCT3StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
	u8ECM1StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD, (uint8 *)&u16EngSpd_ECM1, (uint8)sizeof(u16EngSpd_ECM1));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_P05_TM
	u8ECM11StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u16EngSpdVal, (uint8)sizeof(u16EngSpdVal));
	u8DCT3StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIP, (uint8 *)&u16TgtEngSpdVal, (uint8)sizeof(u16TgtEngSpdVal));
	u8DCT3StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
	u8ECM1StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD, (uint8 *)&u16EngSpd_ECM1, (uint8)sizeof(u16EngSpd_ECM1));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_A07_TM
	u8ECM11StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u16EngSpdVal, (uint8)sizeof(u16EngSpdVal));
	u8DCT3StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIP, (uint8 *)&u16TgtEngSpdVal, (uint8)sizeof(u16TgtEngSpdVal));
	u8DCT3StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
	u8ECM1StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD, (uint8 *)&u16EngSpd_ECM1, (uint8)sizeof(u16EngSpd_ECM1));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_D01_TM
	u8ECM11StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u16EngSpdVal, (uint8)sizeof(u16EngSpdVal));
	u8DCT3StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIP, (uint8 *)&u16TgtEngSpdVal, (uint8)sizeof(u16TgtEngSpdVal));
	u8DCT3StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
	u8ECM1StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD, (uint8 *)&u16EngSpd_ECM1, (uint8)sizeof(u16EngSpd_ECM1));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_D02_TM
	u8ECM11StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u16EngSpdVal, (uint8)sizeof(u16EngSpdVal));
	u8DCT3StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIP, (uint8 *)&u16TgtEngSpdVal, (uint8)sizeof(u16TgtEngSpdVal));
	u8DCT3StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
	u8ECM1StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD, (uint8 *)&u16EngSpd_ECM1, (uint8)sizeof(u16EngSpd_ECM1));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_D03_TM
	u8ECM11StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u16EngSpdVal, (uint8)sizeof(u16EngSpdVal));
	u8DCT3StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIP, (uint8 *)&u16TgtEngSpdVal, (uint8)sizeof(u16TgtEngSpdVal));
	u8DCT3StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
	u8ECM1StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD, (uint8 *)&u16EngSpd_ECM1, (uint8)sizeof(u16EngSpd_ECM1));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_P02_TM
	u8ECM11StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u16EngSpdVal, (uint8)sizeof(u16EngSpdVal));
	u8DCT3StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIP, (uint8 *)&u16TgtEngSpdVal, (uint8)sizeof(u16TgtEngSpdVal));
	u8DCT3StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
	u8ECM1StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD, (uint8 *)&u16EngSpd_ECM1, (uint8)sizeof(u16EngSpd_ECM1));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_P01_TM
	u8ECM11StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u16EngSpdVal, (uint8)sizeof(u16EngSpdVal));
	u8DCT3StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIP, (uint8 *)&u16TgtEngSpdVal, (uint8)sizeof(u16TgtEngSpdVal));
	u8DCT3StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
	u8ECM1StatusRet |= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD, (uint8 *)&u16EngSpd_ECM1, (uint8)sizeof(u16EngSpd_ECM1));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));

#else
#endif
	//SG_ABS3_StatusRet  = Rte_Read_SG_ABS3_SG_ABS3(&SM_SG_ABS3);
	/************************************************************************************
	*
	* EngineSpeed = CAN_RAW_Value * 0.125	[+0.5]
	*
	* Note:+0.5 for round operation to improve the accuracy
	*************************************************************************************/
	//if(0xFFFE == TM_CFG_CAN_EMS_ENGINE_SPEED)
	if(TRUE == TM_CFG_CAN_ECM11_MSG_MISSING(u8ECM11StatusRet))
	{
		u16EngSpdVal = 0u;
		stMainObject->u16EngSpdForEngSts = 0u;
	}
	if(TRUE == TM_CFG_CAN_ECM1_MSG_MISSING(u8ECM1StatusRet))
	{
		u16EngSpd_ECM1 = 0u;
		u8EngSpdValid = 0u;
		stMainObject->u16EngSpdForEngSts = 0u;
	}
	if(TM_CFG_GASOLINE_TYPE == stMainObject->stVConfig.u8FuelType)
	{
		if(1 == u8EngSpdValid)
		{
			stMainObject->u16EngineSpeedFromCANBak = (u16EngSpdVal * 125u) / 1000u;
			stMainObject->u16EngSpdForEngSts = (u16EngSpdVal * 125u) / 1000u;
		}
		else
		{
			stMainObject->u16EngineSpeedFromCANBak = 0;
			stMainObject->u16EngSpdForEngSts = 0;
		}
		
		if((stMainObject->stVConfig.boFastRespondFlg == TM_CFG_FAST_RESPOND) \
			&& (TRUE == u8TgtEngSpdValid) && (TRUE != TM_CFG_CAN_DCT3_MSG_MISSING(u8DCT3StatusRet)))
		{
			if(u16TgtEngSpdVal > 0xFFF)
			{
				stMainObject->u16EngineSpeedFromCAN = 0;
			}else{
				stMainObject->u16EngineSpeedFromCAN = u16TgtEngSpdVal * 2u;
			}
		}else{
			//stMainObject->u16EngineSpeedFromCAN = (TM_CFG_CAN_EMS_ENGINE_SPEED*0.25);
			stMainObject->u16EngineSpeedFromCAN = (u16EngSpdVal * 125u) / 1000u;
		}
	}
	else if(TM_CFG_DIESEL_TYPE == stMainObject->stVConfig.u8FuelType)
	{
		if(1 == u8EngSpdValid)
		{
			stMainObject->u16EngineSpeedFromCANBak = (u16EngSpd_ECM1 * 125u) / 1000u;
			stMainObject->u16EngSpdForEngSts = (u16EngSpd_ECM1 * 125u) / 1000u;
		}
		else
		{
			stMainObject->u16EngineSpeedFromCANBak = 0;
			stMainObject->u16EngSpdForEngSts = 0;
		}
		
		if((stMainObject->stVConfig.boFastRespondFlg == TM_CFG_FAST_RESPOND) \
			&& (TRUE == u8TgtEngSpdValid) && (TRUE != TM_CFG_CAN_DCT3_MSG_MISSING(u8DCT3StatusRet)))
		{
			if(u16TgtEngSpdVal > 0xFFF)
			{
				stMainObject->u16EngineSpeedFromCAN = 0;
			}else{
				stMainObject->u16EngineSpeedFromCAN = u16TgtEngSpdVal * 2u;
			}
		}else{
			//stMainObject->u16EngineSpeedFromCAN = (TM_CFG_CAN_EMS_ENGINE_SPEED*0.25);
			stMainObject->u16EngineSpeedFromCAN = (u16EngSpd_ECM1 * 125u) / 1000u;
		}
	}
	
}
#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/**********************************************************************************************************
*Function   : TM_CFG_vFormulaOfGetEngineSpeedFromPWMRawValue                                              *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: TM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
void TM_CFG_vFormulaOfGetEngineSpeedFromPWMRawValue(TM_CFG_tstMAIN_OBJECT* stMainObject)
{

	stMainObject->u16EngineSpeedFromCAN = TM_CFG_PWM_ENGINE_SPEED;
	
}
#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
/**********************************************************************************************************
*Function   : TM_CFG_vFormulaOfGetTargetIndicateSpeedFromRealSpeed                                        *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: TM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TM_CFG_vFormulaOfGetTargetIndicateEngineSpeedFromRealEngineSpeed(TM_CFG_tstMAIN_OBJECT* stMainObject)
{	
	stMainObject->u16TargetEngineSpeed = stMainObject->u16VaildEngineSpeed;
	if(stMainObject->stVConfig.u16TachoValueMax < stMainObject->u16TargetEngineSpeed)
	{
		stMainObject->u16TargetEngineSpeed = stMainObject->stVConfig.u16TachoValueMax;
	}else
	{
	}

}
/**********************************************************************************************************
*Function   : TM_CFG_vFormulaOfUserDefinedDampingOperation                                                *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: TM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if (TM_CFG_DAMPING_MODEL == TM_CFG_MODEL_FROM_CONFIG_CODE)
void TM_CFG_vFormulaOfUserDefinedDampingOperation(TM_CFG_tstMAIN_OBJECT* stMainObject)
{

	stMainObject->u16CurrentEngineSpeed = stMainObject->u16TargetEngineSpeed;

}
#endif //(TM_CFG_DAMPING_MODEL == TM_CFG_MODEL_FROM_CONFIG_CODE)
/**********************************************************************************************************
*Function   : TM_CFG_vEnterOrExitAntiDitherMode                                                           *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: TM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if (TM_CFG_ANTI_DITHER_MODE != TM_CFG_NO_ANTI_DITHER_MODE)
void TM_CFG_vEnterOrExitAntiDitherMode(TM_CFG_tstMAIN_OBJECT* stMainObject)
{
	stMainObject->u16AntiDitherModeEnterTime = \
	TM_CORE__u16FormatDataAccuracy(TM_CFG_ENTER_ANTI_DITHER_MODE_ENTER_TIME_MAXIMUM,\
								   TM_CFG_ENTER_ANTI_DITHER_MODE_ENTER_TIME_MINIMUM,\
								   TM_CFG_TIME_TASK_CYCLE,0,FALSE,\
								   TM_CFG_ENTER_ANTI_DITHER_MODE_ENTER_TIME);

	stMainObject->u16AntiDitherModeDampingTime = \
	TM_CORE__u16FormatDataAccuracy(TM_CFG_ENTER_ANTI_DITHER_MODE_DAMPING_TIME_MAXIMUM,\
								   TM_CFG_ENTER_ANTI_DITHER_MODE_DAMPING_TIME_MINIMUM,\
								   TM_CFG_TIME_TASK_CYCLE,0,FALSE,\
								   TM_CFG_ENTER_ANTI_DITHER_MODE_DAMPING_TIME);

	stMainObject->u16AntiDitherModeLowLimit = \
	TM_CORE__u16FormatDataAccuracy(TM_CFG_VALUE_ANTI_DITHER_LIMIT_MAXIMUM,\
								   TM_CFG_VALUE_ANTI_DITHER_LIMIT_MINIMUM,\
								   1,0,FALSE,\
								   TM_CFG_VALUE_ANTI_DITHER_LOW_LIMIT);

								   
	stMainObject->u16AntiDitherModeHighLimit = \
	TM_CORE__u16FormatDataAccuracy(TM_CFG_VALUE_ANTI_DITHER_LIMIT_MAXIMUM,\
								   TM_CFG_VALUE_ANTI_DITHER_LIMIT_MINIMUM,\
								   1,0,FALSE,\
								   TM_CFG_VALUE_ANTI_DITHER_HIGH_LIMIT);
	
	//Anti-dither mode count plus
	if((stMainObject->u16TargetEngineSpeed >= stMainObject->u16AntiDitherModeLowLimit ) && \
	   (stMainObject->u16TargetEngineSpeed <= stMainObject->u16AntiDitherModeHighLimit )&& \
	   (stMainObject->u16CurrentEngineSpeed >= stMainObject->u16AntiDitherModeLowLimit )&& \
	   (stMainObject->u16CurrentEngineSpeed <= stMainObject->u16AntiDitherModeHighLimit )&& \
	   (stMainObject->u16AntiDitherModeLowLimit != stMainObject->u16AntiDitherModeHighLimit ))
	{
		stMainObject->stTimer.u8AntiDitherModeTick ++;
	}
	else
	{
		stMainObject->stTimer.u8AntiDitherModeTick = 0 ;
	}

	//Anti-dither mode
	if(stMainObject->stTimer.u8AntiDitherModeTick > stMainObject->u16AntiDitherModeEnterTime)
	{
		stMainObject->stTimer.u8AntiDitherModeTick = (uint16)(stMainObject->u16AntiDitherModeEnterTime+1u);
		stMainObject->unFunctionFlag.stFuncFlag.AntiDither = 1u; //1u means anti-dither enabled
	}
	else
	{
		stMainObject->unFunctionFlag.stFuncFlag.AntiDither = 0u; //0u means anti-dither disabled
	}

#if 0 /*E315 Project special requirement*/

	if(TM_CFG_CONDITION_OF_VEHIALE_IS_RUNNING)
	{
		stMainObject->unFunctionFlag.stFuncFlag.AntiDither = 0u;
		stMainObject->stTimer.u8AntiDitherModeTick = 0 ;
	}
	else
	{
		/*Do nothing because vechicle is stop*/
	}

#endif

}
#endif //(TM_CFG_ANTI_DITHER_MODE != TM_CFG_NO_ANTI_DITHER_MODE)
/**********************************************************************************************************
*Function   : TM_CFG_vFormulaOfUserDefinedAntiDitherDampingOperation                                      *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: TM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if (TM_CFG_ANTI_DITHER_MODE == TM_CFG_ANTI_DITHER_MODEL_FROM_CONFIG_CODE)
void TM_CFG_vFormulaOfUserDefinedAntiDitherDampingOperation(TM_CFG_tstMAIN_OBJECT* stMainObject)
{
	if(stMainObject->u16FilterTargetEngineSpeed >= stMainObject->u16TargetEngineSpeed && 0 != stMainObject->u16TargetEngineSpeed)
	{
		if((stMainObject->u16FilterLastTargetEngineSpeed - stMainObject->u16TargetEngineSpeed) > TM_CFG_ANTI_DITHER_NO_DOWN_VALUE)
		{
			stMainObject->u16FilterTargetEngineSpeed = stMainObject->u16TargetEngineSpeed;
		}
		else 
		{
			stMainObject->u16TargetEngineSpeed = stMainObject->u16FilterLastTargetEngineSpeed;
		}
	}
	else 
	{
		stMainObject->u16FilterLastTargetEngineSpeed = stMainObject->u16TargetEngineSpeed;
		stMainObject->u16FilterTargetEngineSpeed = stMainObject->u16TargetEngineSpeed;
	}
	
	TM_CORE__u16DampingModel_Thread(&stMainObject->u16TargetEngineSpeed,&stMainObject->u16CurrentEngineSpeed,\
											TM_CFG_ANTI_DITHER_DAMPING_MODEL_C(stMainObject->u16AntiDitherModeHighLimit,\
																			   stMainObject->u16AntiDitherModeLowLimit,\
																			   stMainObject->u16AntiDitherModeDampingTime));
}
#endif //(TM_CFG_DAMPING_MODEL == TM_CFG_MODEL_FROM_CONFIG_CODE)
/**********************************************************************************************************
*Function   : TM_CFG_vVehicleConfig                                      *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: TM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: hai hu                                                                                   *
*                                                                                                         *
*Date		: 2020-07-7                                                                                  *
**********************************************************************************************************/
void TM_CFG_vVehicleConfig(TM_CFG_tstMAIN_OBJECT* stMainObject)
{
	VconfigKind_Allbuffers VconfigAddr;
	
	CconfigKind_400Bytes CconfigKind;
	uint8 u8CcfgFastResp = 0;//FALSE;
	uint16 u16CcfgDigitalRPMHysteresis = 0;
	uint16 u16CcfgAnalogRPMHysteresis = 0;
	uint16 u16CcfgDiagitalTachoUpdateFrequency = 0;
	
	uint8 u8FuelType= 0;
	uint16 u16RedZoneThreshold = 0xFFFF;
	uint16 u16TachoValueMax = 0;
	boolean boFastRespondFlg = FALSE;

	uint8 u8VcfgFuelType = 0;
	uint8 u8VcfgEngineType = 0;
	uint8 u8VcfgTransmissionType = 0;

    if (E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(CconfigKind))
    {
        u8CcfgFastResp = (uint8)CConfig_GetConfig(CCONFIG_KIND_Fast_Resp, CconfigKind);
        u16CcfgDigitalRPMHysteresis = (uint16)CConfig_GetConfig(CCONFIG_KIND_DigitalRPM_Hysteresis, CconfigKind);
        u16CcfgAnalogRPMHysteresis = (uint16)CConfig_GetConfig(CCONFIG_KIND_AnalogRPM_Hysteresis, CconfigKind);
        u16CcfgDiagitalTachoUpdateFrequency = (uint16)CConfig_GetConfig(CCONFIG_KIND_DiagitalTacho_update_frequency, CconfigKind);
    }
    else
    {
        u8CcfgFastResp = 1;//TRUE;
        u16CcfgDigitalRPMHysteresis = 26;
        u16CcfgAnalogRPMHysteresis = 26;
        u16CcfgDiagitalTachoUpdateFrequency = 10;
    }

    (void)Rte_Read_Vconfig_GetKindBuffers_AllKinds(VconfigAddr);

	if(0 != VconfigAddr[VCONFIG_KIND_INIT_FLAG])
	{
		u8VcfgTransmissionType = VconfigAddr[VCONFIG_KIND_TRANSMISSION];//byte3 bit7-0 7DCT-GW 0x7
		u8VcfgEngineType = VconfigAddr[VCONFIG_KIND_POWER_TRAIN_TYPE];//byte27 bit7-0 GW4B15A 0xD
		u8VcfgFuelType = VconfigAddr[VCONFIG_KIND_ENGINE_CONTROL_UNIT];//byte42 bit7-3
	}
	
	if((u8VcfgFuelType == TM_CFG_VCONFIG_FUEL_TYPE_0x1) \
		|| (u8VcfgFuelType == TM_CFG_VCONFIG_FUEL_TYPE_0x2) \
		|| (u8VcfgFuelType == TM_CFG_VCONFIG_FUEL_TYPE_0x6))
	{
		u8FuelType = TM_CFG_GASOLINE_TYPE;
		
		if((u8VcfgEngineType == TM_CFG_VCONFIG_ENGINE_TYPE_EN01) \
			|| (u8VcfgEngineType == TM_CFG_VCONFIG_ENGINE_TYPE_GW4N20) \
			|| (u8VcfgEngineType == TM_CFG_VCONFIG_ENGINE_TYPE_GW4N20_HEV) \
			|| (u8VcfgEngineType == TM_CFG_VCONFIG_ENGINE_TYPE_GW4N20_PHEV) \
			|| (u8VcfgEngineType == TM_CFG_VCONFIG_ENGINE_TYPE_E20N) \
			|| (u8VcfgEngineType == TM_CFG_VCONFIG_ENGINE_TYPE_E20N_HEV) \
			|| (u8VcfgEngineType == TM_CFG_VCONFIG_ENGINE_TYPE_E20N_PHEV))
		{
			u16RedZoneThreshold = TM_CFG_GASOLINE_TYPE_ENGINE_TYPE_RED_ZONE_LOW_THRESHOLD_VALUE;
		}
		else if (u8VcfgEngineType == TM_CFG_VCONFIG_ENGINE_TYPE_4C20B)//R19
		{
			u16RedZoneThreshold = TM_CFG_GASOLINE_TYPE_ENGINE_TYPE_RED_ZONE_LOW_THRESHOLD_VALUE_4C20B;
		}
		else
		{
			u16RedZoneThreshold = TM_CFG_GASOLINE_TYPE_OTHER_ENGINE_TYPE_RED_ZONE_LOW_THRESHOLD_VALUE;
		}

		u16TachoValueMax = TM_CFG_FUEL_TYPE_GASOLINE_TACHO_VALUE_MAX;
	}
	else if((u8VcfgFuelType == TM_CFG_VCONFIG_FUEL_TYPE_0x3) \
		|| (u8VcfgFuelType == TM_CFG_VCONFIG_FUEL_TYPE_0x4) \
		|| (u8VcfgFuelType == TM_CFG_VCONFIG_FUEL_TYPE_0x5) \
		|| (u8VcfgFuelType == TM_CFG_VCONFIG_FUEL_TYPE_0x7))
	{
		u8FuelType = TM_CFG_DIESEL_TYPE;
		u16RedZoneThreshold = TM_CFG_DIESEL_TYPE_RED_ZONE_LOW_THRESHOLD_VALUE;
		u16TachoValueMax = TM_CFG_FUEL_TYPE_DIESEL_TACHO_VALUE_MAX;
	}
	else
	{
		
	}
	/* identify whether enable function of fast responding based on transmission configuration */
	if(((u8VcfgTransmissionType == 0x7) \
		|| (u8VcfgTransmissionType == 0xF) \
		|| (u8VcfgTransmissionType == 0x10) \
		|| (u8VcfgTransmissionType == 0x26) \
		|| (u8VcfgTransmissionType == 0x29)) \
		&& (u8CcfgFastResp == 1))	
	{
		boFastRespondFlg = TRUE;
	}
	else if(((u8VcfgTransmissionType != 0x7) \
		&& (u8VcfgTransmissionType != 0xF) \
		&& (u8VcfgTransmissionType != 0x10) \
		&& (u8VcfgTransmissionType != 0x26) \
		&& (u8VcfgTransmissionType != 0x29)) \
		|| (u8CcfgFastResp == 0))	
	{
		boFastRespondFlg = FALSE;
	}
	else
	{
		boFastRespondFlg = FALSE;
	}

	stMainObject->stVConfig.u8FuelType = u8FuelType;
	stMainObject->stVConfig.u16RedZoneThreshold = u16RedZoneThreshold;
	stMainObject->stVConfig.u16TachoValueMax = u16TachoValueMax;
	stMainObject->stVConfig.boFastRespondFlg = boFastRespondFlg;
	stMainObject->stCConfig.u16AnalogRPMHysteresis = u16CcfgAnalogRPMHysteresis;
	stMainObject->stCConfig.u16DigitalRPMHysteresis = u16CcfgDigitalRPMHysteresis;		
	stMainObject->stCConfig.u16RefreshRateDiagitalRPM = u16CcfgDiagitalTachoUpdateFrequency;

	/* tachometer DEBUG Log Print*/
	if (TRUE == SWC_TM_LOGOUT_ENBLE)
	{
		/* If PowerMode Status Change Print Log*/
		if(TRUE == l_TMDebugLogFlag)
		{
			SWC_TM_PRINT_WARN("Tachom:FastResp:%d, DigiHysteres:%d, AnalogHysteres:%d", \
			stMainObject->stVConfig.boFastRespondFlg, stMainObject->stCConfig.u16DigitalRPMHysteresis, \
			stMainObject->stCConfig.u16AnalogRPMHysteresis);
			SWC_TM_PRINT_WARN("Tachom:UpdateFre:%d, TransmiType:%d, RedZone:%d", \
			stMainObject->stCConfig.u16RefreshRateDiagitalRPM, u8VcfgTransmissionType, \
			stMainObject->stVConfig.u16RedZoneThreshold);
		}
	}
}
#define SWC_TM_STOP_SEC_CODE
#include "SWC_TM_MemMap.h" 

/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
