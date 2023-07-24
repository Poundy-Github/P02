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
*File Name   : SM_Config.c                                                                                *
*                                                                                                         *
*Description : Speedometer module source code file.                                                 	  *
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
#include "SWC_SM_Config.h"
#include "SWC_SM_MemMap.h"
#include "CConfig_Cfg.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Formula Configuration																				  *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*Function   : SM_CFG_vFormulaOfGetRealSpeedFromCANRawValue                                                *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: SM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#define Common_Normal_START_SEC_CODE
#include "Common_Normal_MemMap.h" 
//static uint16 VehSpdN = 1000;
extern boolean l_SMDebugLogFlag;
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
void SM_CFG_vFormulaOfGetRealSpeedFromCANRawValue(SM_CFG_tstMAIN_OBJECT* stMainObject)
{
	uint16	VehSpdReceived = 0;

#ifdef GWM_V35_PROJECT_TYPE_B02_SM
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD, (uint8 *)&VehSpdReceived, (uint8)sizeof(VehSpdReceived));
#elif defined GWM_V35_PROJECT_TYPE_B03_SM
	SG_ABS3 SM_SG_ABS3;
	SG_ABS3_ESP_FD2 SM_SG_ABS3_ESP_FD2;

	if(stMainObject->u8CANType == 0)//CAN
	{
		Rte_Read_SG_ABS3_SG_ABS3(&SM_SG_ABS3);
		VehSpdReceived = SM_SG_ABS3.VehSpd_0x265;
	}
	else if(stMainObject->u8CANType == 1)//CANFD
	{
		Rte_Read_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2(&SM_SG_ABS3_ESP_FD2);
		VehSpdReceived = SM_SG_ABS3_ESP_FD2.VehSpd_0x137;
	}
#elif defined GWM_V35_PROJECT_TYPE_P03_SM
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD, (uint8 *)&VehSpdReceived, (uint8)sizeof(VehSpdReceived));
#elif defined GWM_V35_PROJECT_TYPE_P05_SM
	if(stMainObject->u8CANType == 0)//CAN
	{
		(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD_0X265, (uint8 *)&VehSpdReceived, (uint8)sizeof(VehSpdReceived));
	}
	else if(stMainObject->u8CANType == 1)//CANFD
	{
		(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD_0X137, (uint8 *)&VehSpdReceived, (uint8)sizeof(VehSpdReceived));
	}
#elif defined GWM_V35_PROJECT_TYPE_A07_SM
	if(stMainObject->u8CANType == 0)//CAN
	{
		(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD, (uint8 *)&VehSpdReceived, (uint8)sizeof(VehSpdReceived));
	}
	else if(stMainObject->u8CANType == 1)//CANFD
	{
		//DBC V4.1 DEL
	}
#elif defined GWM_V35_PROJECT_TYPE_D01_SM
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD, (uint8 *)&VehSpdReceived, (uint8)sizeof(VehSpdReceived));
#elif defined GWM_V35_PROJECT_TYPE_D02_SM
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD, (uint8 *)&VehSpdReceived, (uint8)sizeof(VehSpdReceived));
#elif defined GWM_V35_PROJECT_TYPE_D03_SM
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD, (uint8 *)&VehSpdReceived, (uint8)sizeof(VehSpdReceived));
#elif defined GWM_V35_PROJECT_TYPE_P02_SM
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD, (uint8 *)&VehSpdReceived, (uint8)sizeof(VehSpdReceived));
#elif defined GWM_V35_PROJECT_TYPE_P01_SM
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD, (uint8 *)&VehSpdReceived, (uint8)sizeof(VehSpdReceived));
#else
#endif

	/************************************************************************************
	*
	* RealSpeed = CAN_RAW_Value * 0.05625	[+0.5]		(1km/h)
	*
	* RealSpeed = CAN_RAW_Value * 0.05625 * 100	[+0.5]	(0.01km/h)
	*
	* Note:+0.5 for round operation to improve the accuracy
	*************************************************************************************/
	//if(0x7FFE == SM_CFG_CAN_ABS_VEHICLE_SPEED)
	if((VehSpdReceived >= 0x14D6) /*&& (VehSpdReceived <= 0x1FFF)*/)
	{
		stMainObject->u32RealSpeedFromCAN = 0;
	}else{
		//stMainObject->u32RealSpeedFromCAN = (uint16)(SM_CFG_CAN_ABS_VEHICLE_SPEED);
		//stMainObject->u32RealSpeedFromCAN = ((uint32)(VehSpdReceived * 5625u) / 1000u);//0.01km/h
		stMainObject->u32RealSpeedFromCAN = ((uint32)VehSpdReceived * 5625u) / 10u;//0.01km/h
	}

	stMainObject->u32RealSpeedFromCANBak = stMainObject->u32RealSpeedFromCAN;

}
#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/**********************************************************************************************************
*Function   : SM_CFG_vFormulaOfGetRealSpeedFromPWMRawValue                                                *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: SM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
void SM_CFG_vFormulaOfGetRealSpeedFromPWMRawValue(SM_CFG_tstMAIN_OBJECT* stMainObject)
{

	/************************************************************************************
	*
	* RealSpeed = CAN_RAW_Value                         (0.1km/h)
	*
	* RealSpeed = CAN_RAW_Value * 10                    (0.01km/h)
	*
	*************************************************************************************/
	stMainObject->u16RealSpeedFromPWM = SM_CFG_PWM_VEHICLE_SPEED * 10;
	
}
#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
/**********************************************************************************************************
*Function   : SM_CFG_vFormulaOfGetTargetIndicateSpeedFromRealSpeed                                        *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: SM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
void SM_CFG_vFormulaOfGetTargetIndicateSpeedFromRealSpeed(SM_CFG_tstMAIN_OBJECT* stMainObject)
{
	/************************************************************************************
	*
	*IndicateSpeed = RealSpeed                   ( <= 3km/h)
	*
	*IndicateSpeed = RealSpeed * 1.03 + 1.25 [+0.5] ( > 3km/h)
	*
	*						RealSpeed * 103 + 12500
	*IndicateSpeed = ---------------------------------- [+0.5] ( > 3km/h)
	*							     100
	*
	*Note:+0.5 for round operation to improve the accuracy
	*************************************************************************************/
	if(stMainObject->u32VaildRealSpeed == (0u * SM_CFG_VALUE_FACTOR))
	{
		stMainObject->u16TargetIndicateSpeed = (uint16)(stMainObject->u32VaildRealSpeed/SM_CFG_VALUE_FACTOR);
	}
	else
	{
		//stMainObject->u16TargetIndicateSpeed = (uint16)(((uint32)stMainObject->u32VaildRealSpeed * 103u + 13000)/SM_CFG_VALUE_FACTOR);
		stMainObject->u16TargetIndicateSpeed = ((stMainObject->u32VaildRealSpeed * 103u) + (130u * SM_CFG_VALUE_FACTOR1)) / 100u;
		/*if((SM_CFG_VALUE_MAX)  < stMainObject->u16TargetIndicateSpeed)

		{
			stMainObject->u16TargetIndicateSpeed = (SM_CFG_VALUE_MAX);
		}else
		{
		}*/
	}
}
/**********************************************************************************************************
*Function   : SM_CFG_vFormulaOfUserDefinedDampingOperation                                                *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: SM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if (SM_CFG_DAMPING_MODEL == SM_CFG_MODEL_FROM_CONFIG_CODE)
void SM_CFG_vFormulaOfUserDefinedDampingOperation(SM_CFG_tstMAIN_OBJECT* stMainObject)
{
	//No damping
	stMainObject->u16CurrentIndicateSpeed = stMainObject->u16TargetIndicateSpeed;
}
#endif //(SM_CFG_DAMPING_MODEL == SM_CFG_MODEL_FROM_CONFIG_CODE)
/**********************************************************************************************************
*Function   : SM_CFG_vVehicleConfig                                                *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: SM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: hai hu                                                                                  *
*                                                                                                         *
*Date		: 2020-07-13                                                                                  *
**********************************************************************************************************/
void SM_CFG_vVehicleConfig(SM_CFG_tstMAIN_OBJECT* stMainObject)
{
	VconfigKind_Allbuffers VconfigAddr;
	
	CconfigKind_400Bytes CconfigKind;
	uint16 u16CcfgRefreshRateDigSpd = 0;
//	boolean boCcfgZeroScaleImperialSpeedo = 0;
	
	uint8 u8VcfgPowerType = 0;
	uint8 u8VcfgUnitSystem = 0;
	uint8 u8VcfgPTCanType = 0;
	MenuSetData_t menuSetData;

	(void)Rte_Read_rpSR_SWCNormal_MenuSetData_Element(&menuSetData);
    u8VcfgUnitSystem = menuSetData.OdometerUnit;
	//boCcfgZeroScaleImperialSpeedo = CconfigKind[2];
	if(E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(CconfigKind))
    {
        u16CcfgRefreshRateDigSpd = (uint16)CConfig_GetConfig(CCONFIG_KIND_RefreshRateDigSpd, CconfigKind);
    }
    else
    {
        u16CcfgRefreshRateDigSpd = 200;
    }
	(void)Rte_Read_Vconfig_GetKindBuffers_AllKinds(VconfigAddr);

	if(0 != VconfigAddr[VCONFIG_KIND_INIT_FLAG])
	{
		u8VcfgPowerType = VconfigAddr[VCONFIG_KIND_FUEL];//byte27 bit7-0
        u8VcfgPTCanType = VconfigAddr[VCONFIG_KIND_PT_CAN_BUS_TYPE];
		//u8VcfgUnitSystem = VconfigAddr[VCONFIG_KIND_CLUSTER_UNIT_SYSTEM];//byte35 bit3-0
	}
#ifdef GWM_V35_PROJECT_TYPE_B02_SM
		stMainObject->u8CANType = SM_CFG_ESP_CAN_FD;
#elif defined GWM_V35_PROJECT_TYPE_B03_SM
    if (u8VcfgPTCanType == 1)
    {
		stMainObject->u8CANType = SM_CFG_ESP_CAN_FD;
    }
    else
    {
		stMainObject->u8CANType = SM_CFG_ABS3_CAN;
    }
#elif defined GWM_V35_PROJECT_TYPE_P03_SM
		stMainObject->u8CANType = SM_CFG_ESP_CAN_FD;
#elif defined GWM_V35_PROJECT_TYPE_P05_SM
    if (u8VcfgPTCanType == 1)
    {
		stMainObject->u8CANType = SM_CFG_ESP_CAN_FD;
    }
    else
    {
		stMainObject->u8CANType = SM_CFG_ABS3_CAN;
    }
#elif defined GWM_V35_PROJECT_TYPE_A07_SM
    if (u8VcfgPTCanType == 1)
    {
		stMainObject->u8CANType = SM_CFG_ESP_CAN_FD;
    }
    else
    {
		stMainObject->u8CANType = SM_CFG_ABS3_CAN;
    }
#elif defined GWM_V35_PROJECT_TYPE_D01_SM
		stMainObject->u8CANType = SM_CFG_ESP_CAN_FD;
#elif defined GWM_V35_PROJECT_TYPE_D02_SM
		stMainObject->u8CANType = SM_CFG_ESP_CAN_FD;
#elif defined GWM_V35_PROJECT_TYPE_D03_SM
		stMainObject->u8CANType = SM_CFG_ESP_CAN_FD;
#elif defined GWM_V35_PROJECT_TYPE_P02_SM
		stMainObject->u8CANType = SM_CFG_ESP_CAN_FD;
#elif defined GWM_V35_PROJECT_TYPE_P01_SM
		stMainObject->u8CANType = SM_CFG_ESP_CAN_FD;
#else
#endif

	if(u8VcfgPowerType == 0x4) /* PHEV Speed Max 260km/h */
	{
		stMainObject->u8PowerType = 1;
	}
	else
	{
		stMainObject->u8PowerType = 0;
	}

	if((u8VcfgUnitSystem == 0x2) || (u8VcfgUnitSystem == 0x3))
	{
		stMainObject->u8MenuUnit = SM_CFG_IMPERIAL_UNIT;
		stMainObject->u16VehSpdMax = (uint16)((stMainObject->u8PowerType == 1) ? 180 : 160);
	}
	else
	{
		stMainObject->u8MenuUnit = SM_CFG_METRIC_UNIT;
		
		stMainObject->u16VehSpdMax = (uint16)((stMainObject->u8PowerType == 1) ? 260 : 240);
	}
	stMainObject->u16CcfgRefreshRateDigSpd = u16CcfgRefreshRateDigSpd;
	/* SM DEBUG Log Print*/
	if (TRUE == SWC_SM_LOGOUT_ENBLE)
	{
		/* If PowerMode Status Change Print Log*/
		if(TRUE == l_SMDebugLogFlag)
		{
			SWC_SM_PRINT_WARN("SpeedoMode:FuelType:%d, CANType:%d, Unit:%d, VehSpdMax:%d, RefreshRate:%d", \
			stMainObject->u8PowerType, stMainObject->u8CANType, stMainObject->u8MenuUnit, \
			stMainObject->u16VehSpdMax, stMainObject->u16CcfgRefreshRateDigSpd);
		}
	}
}
#define Common_Normal_STOP_SEC_CODE
#include "Common_Normal_MemMap.h" 
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
