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
*File Name   : CL_Config.c                                                                                *
*                                                                                                         *
*Description : Coolant module source code file.                                                 	      *
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

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_CL_Config.h"
#include "Rte_Common_Normal.h"
#include "CConfig_Cfg.h"
/**********************************************************************************************************
*																								          *
*																								          *
*	Formula Configuration																				  *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*Function   : CL_CFG_vFormulaOfGetRealTemperatureFromCANRawValue                                          *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: CL_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#define SWC_CL_START_SEC_CODE
#include "SWC_CL_MemMap.h"
extern uint8 l_CLDebugLogFlag;
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
void CL_CFG_vFormulaOfGetRealTemperatureFromCANRawValue(CL_CFG_tstMAIN_OBJECT* stMainObject)
{
	uint8 u8EngCoolantTemp = 0;
	uint16 u16TempData = 0;
	//uint8 u8ECM3StatusRet = 0;
	
	//u8ECM3StatusRet = Rte_Read_EngCoolantTemp_EngCoolantTemp(&u8EngCoolantTemp);
#ifdef GWM_V35_PROJECT_TYPE_B02_CL
    (void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCOOLANTTEMP, (uint8 *)&u8EngCoolantTemp, (uint8)sizeof(u8EngCoolantTemp));
#elif defined GWM_V35_PROJECT_TYPE_B03_CL
	Rte_Read_EngCoolantTemp_EngCoolantTemp(&u8EngCoolantTemp);
#elif defined GWM_V35_PROJECT_TYPE_P03_CL
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCOOLANTTEMP, (uint8 *)&u8EngCoolantTemp, (uint8)sizeof(u8EngCoolantTemp));
#elif defined GWM_V35_PROJECT_TYPE_P05_CL
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCOOLANTTEMP, (uint8 *)&u8EngCoolantTemp, (uint8)sizeof(u8EngCoolantTemp));
#elif defined GWM_V35_PROJECT_TYPE_A07_CL
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCOOLANTTEMP, (uint8 *)&u8EngCoolantTemp, (uint8)sizeof(u8EngCoolantTemp));
#elif defined GWM_V35_PROJECT_TYPE_D01_CL
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCOOLANTTEMP, (uint8 *)&u8EngCoolantTemp, (uint8)sizeof(u8EngCoolantTemp));
#elif defined GWM_V35_PROJECT_TYPE_D02_CL
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCOOLANTTEMP, (uint8 *)&u8EngCoolantTemp, (uint8)sizeof(u8EngCoolantTemp));
#elif defined GWM_V35_PROJECT_TYPE_D03_CL
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCOOLANTTEMP, (uint8 *)&u8EngCoolantTemp, (uint8)sizeof(u8EngCoolantTemp));
#elif defined GWM_V35_PROJECT_TYPE_P02_CL
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCOOLANTTEMP, (uint8 *)&u8EngCoolantTemp, (uint8)sizeof(u8EngCoolantTemp));
#elif defined GWM_V35_PROJECT_TYPE_P01_CL
		(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCOOLANTTEMP, (uint8 *)&u8EngCoolantTemp, (uint8)sizeof(u8EngCoolantTemp));
#else
#endif
	/************************************************************************************
	*
	* RealEngineTemperature = CAN_RAW_Value * 0.75 - 48  (1C)
	*
	* RealEngineTemperature = CAN_RAW_Value * 75 - 4800  (0.01C)
	*
	*************************************************************************************/

	u16TempData = (uint16)u8EngCoolantTemp;
	u16TempData = (u16TempData * 75u) - 4800u;
	stMainObject->s16RealTemperatureFromCAN = (sint16)u16TempData;

}
#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/**********************************************************************************************************
*Function   : CL_CFG_vFormulaOfGetRealTemperatureFromADCRawValue                                          *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: CL_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
void CL_CFG_vFormulaOfGetRealTemperatureFromADCRawValue(CL_CFG_tstMAIN_OBJECT* stMainObject)
{

	/************************************************************************************
	*
	* RealEngineTemperature = ADC_RAW_Value  (1C)
	*
	* RealEngineTemperature = ADC_RAW_Value  (0.01C)
	*
	*************************************************************************************/
	stMainObject->s16RealTemperatureFromADC = CL_CFG_ADC_TEMPERATURE;
	
}
#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
/**********************************************************************************************************
*Function   : CL_CFG_vFormulaOfGetTargetIndicateTemperatureFromRealTemperature                            *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: CL_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
void CL_CFG_vFormulaOfGetTargetIndicateTemperatureFromRealTemperature(CL_CFG_tstMAIN_OBJECT* stMainObject)
{	
	/************************************************************************************
	*
	*IndicateTemperature = RealTemperature
	*
	*************************************************************************************/

	if(stMainObject->s16ValidRealTemperature <= 0)
	{
		stMainObject->u16TargetIndicateTemperature = 0u;
	}
	else
	{
		stMainObject->u16TargetIndicateTemperature = (uint16)(stMainObject->s16ValidRealTemperature);
	}
}
/**********************************************************************************************************
*Function   : CL_CFG_vFormulaOfUserDefinedDampingOperation                                                *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: CL_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if (CL_CFG_DAMPING_MODEL == CL_CFG_MODEL_FROM_CONFIG_CODE)
void CL_CFG_vFormulaOfUserDefinedDampingOperation(CL_CFG_tstMAIN_OBJECT* stMainObject)
{
	//No damping
	stMainObject->u16CurrentIndicateTemperature = stMainObject->u16TargetIndicateTemperature;
}
#endif //(CL_CFG_DAMPING_MODEL == CL_CFG_MODEL_FROM_CONFIG_CODE)

/**********************************************************************************************************
*Function   : CL_CFG_vVehicleConfig                                                *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: CL_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: hai hu                                                                                  *
*                                                                                                         *
*Date		: 2020-10-15                                                                                  *
**********************************************************************************************************/
void CL_CFG_vVehicleConfig(CL_CFG_tstMAIN_OBJECT* stMainObject)
{
	VconfigKind_Allbuffers VconfigAddr;
	uint8 u8FuelType = 0;
	uint8 u8VcfgFuelType = 0;
	CconfigKind_400Bytes CconfigKind;
    sint16 Coolant_C_Point = 0;
    sint16 Coolant_1_4_point = 0;
    sint16 Coolant_1_2_point1 = 0;
    sint16 Coolant_1_2_point2 = 0;
	sint16 Coolant_5_8_point = 0;
    sint16 Coolant_3_4_point = 0;
    sint16 Coolant_Redline_point = 0;
    sint16 Coolant_H_point = 0;
	uint8 u8VcfgTemperatureType = 0;
	uint8 u8VcfgTemperatureParametersType = 0;

	(void)Rte_Read_Vconfig_GetKindBuffers_AllKinds(VconfigAddr);

	if (0 != VconfigAddr[VCONFIG_KIND_INIT_FLAG])
	{
		u8VcfgFuelType = VconfigAddr[VCONFIG_KIND_ENGINE_CONTROL_UNIT]; /*byte42 bit7-3*/
		u8VcfgTemperatureType = VconfigAddr[VCONFIG_KIND_WATER_TEMPERATURE_DISPLAY_OF_INSTRUMENT]; /*byte104 bit7-6*/
		u8VcfgTemperatureParametersType = VconfigAddr[VCONFIG_KIND_WATER_THERMOMETER_DISPLAY_PARAMETERS]; /*byte118 bit1-0*/
	}

	if (RTE_E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(CconfigKind))
	{
		if ((u8VcfgFuelType == 0x1) || (u8VcfgFuelType == 0x2) || (u8VcfgFuelType == 0x6))
		{
			if(u8VcfgTemperatureType == 0)//Domestic platform
			{
				if(u8VcfgTemperatureParametersType == 0)/* Temperature Parameters 1 */
				{
					Coolant_C_Point = (sint16)CConfig_GetConfig(CCONFIG_KIND_GasolineCoolant_C_point, CconfigKind);
					Coolant_1_4_point = (sint16)CConfig_GetConfig(CCONFIG_KIND_GasolineCoolant_1_4_point, CconfigKind);
					Coolant_1_2_point1 = (sint16)CConfig_GetConfig(CCONFIG_KIND_GasolineCoolant_1_2_point1, CconfigKind);
					Coolant_1_2_point2 = (sint16)CConfig_GetConfig(CCONFIG_KIND_GasolineCoolant_1_2_point2, CconfigKind);
					Coolant_5_8_point = (sint16)164;
					Coolant_3_4_point = (sint16)CConfig_GetConfig(CCONFIG_KIND_GasolineCoolant__4_point, CconfigKind);
					Coolant_Redline_point = (sint16)CConfig_GetConfig(CCONFIG_KIND_GasolineCoolant_Redline_point, CconfigKind);
					Coolant_H_point = (sint16)CConfig_GetConfig(CCONFIG_KIND_GasolineCoolant_H_point, CconfigKind);
				}
				else if(u8VcfgTemperatureParametersType == 1)/* Temperature Parameters 2 */
				{
					Coolant_C_Point = (sint16)90;
					Coolant_1_4_point = (sint16)110;
					Coolant_1_2_point1 = (sint16)125;
					Coolant_1_2_point2 = (sint16)163;
					Coolant_5_8_point = (sint16)166;
					Coolant_3_4_point = (sint16)168;
					Coolant_Redline_point = (sint16)170;
					Coolant_H_point = (sint16)180;
				}
				else if(u8VcfgTemperatureParametersType == 2)/* Temperature Parameters 3 */
				{
					Coolant_C_Point = (sint16)90;
					Coolant_1_4_point = (sint16)110;
					Coolant_1_2_point1 = (sint16)125;
					Coolant_1_2_point2 = (sint16)165;
					Coolant_5_8_point = (sint16)168;
					Coolant_3_4_point = (sint16)169;
					Coolant_Redline_point = (sint16)170;
					Coolant_H_point = (sint16)180;
				}
				else
				{}
				
			}
			else if(u8VcfgTemperatureType == 1)//High temperature strategy
			{
				Coolant_C_Point = (sint16)90;
				Coolant_1_4_point = (sint16)110;
				Coolant_1_2_point1 = (sint16)125;
				Coolant_1_2_point2 = (sint16)166;
				Coolant_5_8_point = (sint16)168;
				Coolant_3_4_point = (sint16)169;
				Coolant_Redline_point = (sint16)170;
				Coolant_H_point = (sint16)180;
			}
			else
			{}
		}
		else if ((u8VcfgFuelType == 0x3) || (u8VcfgFuelType == 0x4) || (u8VcfgFuelType == 0x5) || (u8VcfgFuelType == 0x7))
		{
			if(u8VcfgTemperatureType == 0)//Domestic platform
			{
				Coolant_C_Point = (sint16)CConfig_GetConfig(CCONFIG_KIND_DieselCoolant_C_point, CconfigKind);
				Coolant_1_4_point = (sint16)CConfig_GetConfig(CCONFIG_KIND_DieselCoolant_1_4_point, CconfigKind);
				Coolant_1_2_point1 = (sint16)CConfig_GetConfig(CCONFIG_KIND_DieselCoolant_1_2_point1, CconfigKind);
				Coolant_1_2_point2 = (sint16)CConfig_GetConfig(CCONFIG_KIND_DieselCoolant_1_2_point2, CconfigKind);
				Coolant_5_8_point = (sint16)161;
				Coolant_3_4_point = (sint16)CConfig_GetConfig(CCONFIG_KIND_DieselCoolant_3_4_point, CconfigKind);
				Coolant_Redline_point = (sint16)CConfig_GetConfig(CCONFIG_KIND_DieselCoolant_Redline_point, CconfigKind);
				Coolant_H_point = (sint16)CConfig_GetConfig(CCONFIG_KIND_DieselCoolant_H_point, CconfigKind);
			}
			else if(u8VcfgTemperatureType == 1)//High temperature strategy
			{
				Coolant_C_Point = (sint16)90;
				Coolant_1_4_point = (sint16)110;
				Coolant_1_2_point1 = (sint16)125;
				Coolant_1_2_point2 = (sint16)161;
				Coolant_5_8_point = (sint16)162;
				Coolant_3_4_point = (sint16)163;
				Coolant_Redline_point = (sint16)165;
				Coolant_H_point = (sint16)170;
			}
			else
			{}
		}
		else
		{
			
		}
	}
	else
	{
		Coolant_C_Point = (sint16)90;
		Coolant_1_4_point = (sint16)110;
		Coolant_1_2_point1 = (sint16)125;
		Coolant_1_2_point2 = (sint16)162;
		Coolant_5_8_point = (sint16)164;
		Coolant_3_4_point = (sint16)166;
		Coolant_Redline_point = (sint16)168;
		Coolant_H_point = (sint16)180;
	}

	if((u8VcfgFuelType == 0x1) \
		|| (u8VcfgFuelType == 0x2) \
		|| (u8VcfgFuelType == 0x6))
	{
		u8FuelType = CL_CFG_GASOLINE_TYPE;

		g_coolantPointVal[0] = ((sint16)(Coolant_C_Point - CL_CFG_OFFSET) * 10);
		g_coolantPointVal[1] = ((sint16)(Coolant_1_4_point - CL_CFG_OFFSET) * 10);
		g_coolantPointVal[2] = ((sint16)(Coolant_1_2_point1 - CL_CFG_OFFSET) * 10);
		g_coolantPointVal[3] = ((sint16)(Coolant_1_2_point2 - CL_CFG_OFFSET) * 10);
		g_coolantPointVal[4] = ((sint16)(Coolant_5_8_point - CL_CFG_OFFSET) * 10);
		g_coolantPointVal[5] = ((sint16)(Coolant_3_4_point - CL_CFG_OFFSET) * 10);
		g_coolantPointVal[6] = ((sint16)(Coolant_Redline_point - CL_CFG_OFFSET) * 10);
		g_coolantPointVal[7] = ((sint16)(Coolant_H_point - CL_CFG_OFFSET) * 10);

        if ((g_coolantPointVal[7] < g_coolantPointVal[6]) ||
			(g_coolantPointVal[6] < g_coolantPointVal[5]) ||
            (g_coolantPointVal[5] < g_coolantPointVal[4]) ||
            (g_coolantPointVal[4] < g_coolantPointVal[3]) ||
            (g_coolantPointVal[3] < g_coolantPointVal[2]) ||
            (g_coolantPointVal[2] < g_coolantPointVal[1]) ||
            (g_coolantPointVal[1] < g_coolantPointVal[0]))
        {
            g_coolantPointVal[0] = (sint16)400;
            g_coolantPointVal[1] = (sint16)600;
            g_coolantPointVal[2] = (sint16)750;
            g_coolantPointVal[3] = (sint16)1120;
			g_coolantPointVal[4] = (sint16)1140;
            g_coolantPointVal[5] = (sint16)1160;
            g_coolantPointVal[6] = (sint16)1180;
            g_coolantPointVal[7] = (sint16)1300;
        }
    }
	else if((u8VcfgFuelType == 0x3) \
		|| (u8VcfgFuelType == 0x4) \
		|| (u8VcfgFuelType == 0x5) \
		|| (u8VcfgFuelType == 0x7))
	{
		u8FuelType = CL_CFG_DIESEL_TYPE;

		g_coolantPointVal[0] = ((sint16)(Coolant_C_Point - CL_CFG_OFFSET) * 10);
		g_coolantPointVal[1] = ((sint16)(Coolant_1_4_point - CL_CFG_OFFSET) * 10);
		g_coolantPointVal[2] = ((sint16)(Coolant_1_2_point1 - CL_CFG_OFFSET) * 10);
		g_coolantPointVal[3] = ((sint16)(Coolant_1_2_point2 - CL_CFG_OFFSET) * 10);
		g_coolantPointVal[4] = ((sint16)(Coolant_5_8_point - CL_CFG_OFFSET) * 10);
		g_coolantPointVal[5] = ((sint16)(Coolant_3_4_point - CL_CFG_OFFSET) * 10);
		g_coolantPointVal[6] = ((sint16)(Coolant_Redline_point - CL_CFG_OFFSET) * 10);
		g_coolantPointVal[7] = ((sint16)(Coolant_H_point - CL_CFG_OFFSET) * 10);

        if ((g_coolantPointVal[7] < g_coolantPointVal[6]) ||
			(g_coolantPointVal[6] < g_coolantPointVal[5]) ||
            (g_coolantPointVal[5] < g_coolantPointVal[4]) ||
            (g_coolantPointVal[4] < g_coolantPointVal[3]) ||
            (g_coolantPointVal[3] < g_coolantPointVal[2]) ||
            (g_coolantPointVal[2] < g_coolantPointVal[1]) ||
            (g_coolantPointVal[1] < g_coolantPointVal[0]))
        {
            g_coolantPointVal[0] = (sint16)400;
            g_coolantPointVal[1] = (sint16)600;
            g_coolantPointVal[2] = (sint16)750;
            g_coolantPointVal[3] = (sint16)1080;
			g_coolantPointVal[4] = (sint16)1110;
            g_coolantPointVal[5] = (sint16)1130;
            g_coolantPointVal[6] = (sint16)1150;
            g_coolantPointVal[7] = (sint16)1200;
        }
	}
	else if(u8VcfgFuelType == 0x0)
	{
		u8FuelType = CL_CFG_NO_DISPLAY;
	}
	else
	{}

	stMainObject->stVConfig.u8FuelType = u8FuelType;

	/* Coolant DEBUG Log Print*/
	if (TRUE == SWC_CL_LOGOUT_ENBLE)
	{
		/* If PowerMode Status Change Print Log*/
		if(TRUE == l_CLDebugLogFlag)
		{
			SWC_CL_PRINT_WARN("Coolant: Vcfg:%d, %d, %d Bar0-6:%d, %d, %d, %d, %d, %d, %d", \
			u8VcfgFuelType, u8VcfgTemperatureType, u8VcfgTemperatureParametersType, \
			Coolant_C_Point, Coolant_1_4_point, Coolant_1_2_point1, Coolant_1_2_point2, \
			Coolant_3_4_point, Coolant_Redline_point, Coolant_H_point);
		}
	}
}


#define SWC_CL_STOP_SEC_CODE
#include "SWC_CL_MemMap.h"
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
