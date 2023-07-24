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
**  Name:               SWC_Chime_App.c
**
**  Description:        Chime logical migration file
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
#include "logger.h"
#include "Vconfig_Cfg.h"
#include "CConfig_Cfg.h"
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Chime_Process.h"
#include "SWC_Chime_Adapt.h"

#include "SWC_Chime_App.h"
#include "SWC_Chime_Test.h"
#include "SWC_IPC_Config.h"
#include "SWC_Odo_Adapt.h"
#include "SWC_WN_Config.h"

/**********************************************************************************************************
* Parament                                                                                                *
**********************************************************************************************************/
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_CHIME_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Chime_MemMap.h"

static s_ChimeOstmData_t ChimeOstmTickCounter_s[ChimeOstmTimerAll];

static s_ChimeChimeCallback_t ChimeRteChimeCallback_t[2];
//static s_ChimeWrnCallback_t ChimeRteWrnCallback_t[2];
static s_ChimeTTCallback_t ChimeRteTTCallback_t[2];
//static s_ChimeAadsCallback_t ChimeRteAdasCallback_t[2];
static s_ChimeConfigData_t ChimeConfigData_s;

//static uint16 ChimeSOCReadyDelay_Counter;

static uint8 ChimeHmiPowerStatus_u8;
#ifdef CHIME_RUNABLE_TIME_TEST

s_ChimeRunableTimerTest_t ChimeRunableTimerTest[ChimeOstmTimerAll];
extern void TM_TimerElapsed(uint32 * StartStamp, uint32 * TimeElapsed);
extern void  TM_TimerStartStamp(uint32 * StartStamp);

#endif

#define SWC_CHIME_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
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



#define SWC_CHIME_STOP_SEC_CONST_UNSPECIFIED
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
*Function   : Chime_RteAdaptInit                                                                          *
*                                                                                                         *
*Description: Chime adapt init function,always for init paramenter                                        *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_RteAdaptInit(void)
{
	#ifdef CHIME_RUNABLE_TIME_TEST
	uint8 temp;
	for(temp = 0;temp < ChimeOstmTimerAll;temp ++)
	{
		ChimeRunableTimerTest[temp].ChimeRunableTimerTest_MIN = 0xffffffff;
	}
	#endif
	(void)memset(ChimeOstmTickCounter_s,0,sizeof(ChimeOstmTickCounter_s));
	ChimeHmiPowerStatus_u8 = 0;
}
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
uint16 Chime_RteAdaptGetPower(void)
{
	SystemState_RecordType *power_u8;
	uint32 power_time;
	uint8 hmi_power = ChimeHmiPowerStatus_u8;
	power_u8 = Rte_IRead_Common_Normal_100msMainFunction_tiSR_Power_Out_SystemStateOut();
	
	if(0x00 == hmi_power)
	{
		if(CHIME_OSTM_TIMER_RUNING != (ChimeOstmTickCounter_s[ChimeOstmTimer5].Status_u8))
		{
			Chime_RteAdaptOstmStart((uint8)ChimeOstmTimer5);
		}
		else
		{
			power_time = Chime_RteAdaptOstmCheck((uint8)ChimeOstmTimer5);
			/*wait max time 10s*/
			if((10000 <= power_time) && (CHIME_OSTM_TIMER_MAX_COUNTER != power_time))
			{
				/*Timer over,set hmi power mode to normal*/
				ChimeHmiPowerStatus_u8 = 6;
				Chime_RteAdaptOstmStop((uint8)ChimeOstmTimer5);
			}
		}
	}

	if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
	{
		return CHIME_FUN_RUN_POWER_ON;
	}
	if((SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState) || (SYSTEMSTATE_Cluster_SHUTDOWN == power_u8->ClusterState))
	{
		return CHIME_FUN_RUN_POWER_SLEEP;
	}
	else
	{
		if(0x05 == hmi_power)/*Hmi power 5: pre sleep*/
		{
			return CHIME_FUN_RUN_POWER_PRESLEEP;
		}
		else
		{
			if(0x00 == hmi_power)
			{
				/*wait hmi power status*/
				return CHIME_FUN_RUN_POWER_OFF;//CHIME_FUN_RUN_POWER_WAITTING;
			}
			else
			{
				return CHIME_FUN_RUN_POWER_OFF;
			}
		}
	}
}

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
uint16 Chime_RteAdaptGetVoltage(void)
{
	SystemState_RecordType *power_u8;
	
	power_u8 = Rte_IRead_Common_Normal_100msMainFunction_tiSR_Power_Out_SystemStateOut();
	
	if((VOLTAGE_OUT_NORMAL == power_u8->s_PowerVoltage.state) || (VOLTAGE_OUT_LOWALARM == power_u8->s_PowerVoltage.state) || (VOLTAGE_OUT_HIGHALARM == power_u8->s_PowerVoltage.state))
	{
		return 0;
	}
	else
	{
		return CHIME_FUN_RUN_POWER_ABNORMAL;
	}
}

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
uint8 Chime_RteAdaptGetVconfig(uint8 id_u8)
{
	VconfigKind_Allbuffers configAdr;
	(void)Rte_Read_Vconfig_GetKindBuffers_AllKinds(configAdr);
	return configAdr[id_u8];
}

/**********************************************************************************************************
*Function   : Chime_RteAdaptGetAllConfig                                                                  *
*                                                                                                         *
*Description: Chime get location configuration function                                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_RteAdaptGetAllConfig(void)
{
	CconfigKind_400Bytes Lcal_config;
	uint8 configProject_u8 = Chime_RteAdaptGetVconfig(VCONFIG_KIND_PROJECT_CODE);
	uint8 configPower_u8 = Chime_RteAdaptGetVconfig(VCONFIG_KIND_POWER_TRAIN_TYPE);
	uint8 configTrim_u8 = Chime_RteAdaptGetVconfig(VCONFIG_KIND_TRIM__LEVEL);
	uint8 configAmp_u8 = Chime_RteAdaptGetVconfig(VCONFIG_KIND_AMPLIFIER);
	//uint8 configFuel_u8 = Chime_RteAdaptGetVconfig(VCONFIG_KIND_FUEL);
	//uint8 configElec_u8 = Chime_RteAdaptGetVconfig(VCONFIG_KIND_ELECTROMOTOR_POSITION);
	//uint8 configTran_u8 = Chime_RteAdaptGetVconfig(VCONFIG_KIND_TRANSMISSION);
	uint8 canfdUse_u8 = Chime_RteAdaptGetVconfig(VCONFIG_KIND_PT_CAN_BUS_TYPE);
	
	uint8 withCenter_u8 = 0U;
	//uint8 canfdUse_u8 = 0;
	if(0x1A == configProject_u8)
	{
		if(0x0F == configPower_u8)
		{
			if((0x02 == configTrim_u8) || (0x03 == configTrim_u8))
			{
				withCenter_u8 = 1U;
			}
		}
		else if(0x1E == configPower_u8)
		{
			if(0x02 >= configTrim_u8)
			{
				withCenter_u8 = 1U;
			}
		}
		else if(0x3D == configPower_u8)
		{
			if((0x02 == configTrim_u8) || (0x03 == configTrim_u8))
			{
				withCenter_u8 = 1U;
			}
		}
	}
	else if(0x44 == configProject_u8)
	{
		if(((0x05 == configPower_u8) || (0x69 == configPower_u8) || (0x1B == configPower_u8) || (0x1F == configPower_u8) || (0x6E == configPower_u8)) && (0x02 == configTrim_u8))
		{
			withCenter_u8 = 1U;
		}
		else
		{}
	}
	else if(0x45 == configProject_u8)
	{
		if(((0x05 == configPower_u8) || (0x69 == configPower_u8) || (0x1B == configPower_u8) || (0x6E == configPower_u8)) && (0x00 == configTrim_u8) && (0x02 == configAmp_u8))
		{
			withCenter_u8 = 1U;
		}
	}
	else if(0x47 == configProject_u8)
	{
		if(((0x6D == configPower_u8) || (0x70 == configPower_u8)) && ((0x01 == configTrim_u8) || (0x02 == configTrim_u8) || (0x03 == configTrim_u8) || (0x06 == configTrim_u8)))
		{
			withCenter_u8 = 1U;
		}
	}
	else if(0x48 == configProject_u8)
	{
		if((0x8B == configPower_u8) && ((0x01 == configTrim_u8) || (0x06 == configTrim_u8)))
		{
			withCenter_u8 = 1U;
		}
		else if(((0x71 == configPower_u8) || (0x80 == configPower_u8)) && ((0x01 == configTrim_u8) || (0x02 == configTrim_u8)))
		{
			withCenter_u8 = 1U;
		}
		else
		{
		}
	}
	else if(0x49 == configProject_u8)
	{
		if((0x6D == configPower_u8) && (0x02 == configTrim_u8))
		{
			withCenter_u8 = 1U;
		}
		else
		{
		}
	}
	else
	{}
	withCenter_u8 = 0U;

	
#if 0
	if((0x39 == configProject_u8 && 0x00 == configElec_u8)/*B03纯燃油*/
	 || ((0x44 == configProject_u8 || 0x45 == configProject_u8 || 0x46 == configProject_u8) && 0x08 == configTran_u8))/*P05纯燃油-8AT*/
	{
		canfdUse_u8 = 0;
	}
	else if((0x1A == configProject_u8)/*B02~*/
	 || ((0x44 == configProject_u8 || 0x45 == configProject_u8 || 0x46 == configProject_u8) && 0x27 == configTran_u8)/*P05纯燃油-9AT*/
	 || ((0x39 == configProject_u8) && (0x05 == configElec_u8 || 0x06 == configElec_u8) && (0x03 == configFuel_u8 || 0x04 == configFuel_u8))/*B03 HEV+PHEV*/
	 || ((0x47 == configProject_u8) || (0x43 == configProject_u8) || (0x49 == configProject_u8)))/*P03~*/
	{
		canfdUse_u8 = 1;
	}
	else
	{
		canfdUse_u8 = 0xFF;
		//缺少B06,无功能
	}
#endif	
	
	if(E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(Lcal_config))
	{
		ChimeConfigData_s.Chimedelaytime_u8 = (uint8)CConfig_GetConfig(CCONFIG_KIND_Chimedelaytime, Lcal_config);
		ChimeConfigData_s.DoortoRed_speedthreshold_u8 = (uint8)CConfig_GetConfig(CCONFIG_KIND_DoortoRed_speedthreshold, Lcal_config);
		ChimeConfigData_s.ADASsoundfieldEnable_u8 = (uint8)CConfig_GetConfig(CCONFIG_KIND_ADASsoundfieldEnable, Lcal_config);
		ChimeConfigData_s.AllFieldEnable_u8 = 1U;
		ChimeConfigData_s.FIXDISPLAY_1_GEAR_ENABLE_u8 = (uint8)CConfig_GetConfig(CCONFIG_KIND_FIXDISPLAY_1_GEAR_ENABLE, Lcal_config);
		ChimeConfigData_s.FIXDISPLALY_2_SHIFT_GEAR_RECOMMEND_ENABLE_u8 = (uint8)CConfig_GetConfig(CCONFIG_KIND_FIXDISPLALY_2_SHIFT_GEAR_RECOMMEND_ENABLE, Lcal_config);
		ChimeConfigData_s.DISPLAY_6_GEAR_ENABLE_u8 = (uint8)CConfig_GetConfig(CCONFIG_KIND_DISPLAY_6_GEAR_ENABLE, Lcal_config);
		ChimeConfigData_s.DISPLALY_6_SHIFT_GEAR_RECOMMEND_ENABLE_u8 = (uint8)CConfig_GetConfig(CCONFIG_KIND_DISPLALY_6_SHIFT_GEAR_RECOMMEND_ENABLE, Lcal_config);
		ChimeConfigData_s.Center_Speaker = withCenter_u8;
		ChimeConfigData_s.CAN_MESSAGE_USE_FD = canfdUse_u8;
	}
	else
	{
		ChimeConfigData_s.Chimedelaytime_u8 = 5;
		ChimeConfigData_s.DoortoRed_speedthreshold_u8 = 6;
		ChimeConfigData_s.ADASsoundfieldEnable_u8 = 1U;
		ChimeConfigData_s.AllFieldEnable_u8 = 1U;
		ChimeConfigData_s.FIXDISPLAY_1_GEAR_ENABLE_u8 = 1U;
		ChimeConfigData_s.FIXDISPLALY_2_SHIFT_GEAR_RECOMMEND_ENABLE_u8 = 1U;
		ChimeConfigData_s.DISPLAY_6_GEAR_ENABLE_u8 = 1U;
		ChimeConfigData_s.DISPLALY_6_SHIFT_GEAR_RECOMMEND_ENABLE_u8 = 1U;
		ChimeConfigData_s.Center_Speaker = withCenter_u8;
		ChimeConfigData_s.CAN_MESSAGE_USE_FD = canfdUse_u8;
	}
}

/**********************************************************************************************************
*Function   : Chime_RteAdaptGetLconfig                                                                    *
*                                                                                                         *
*Description: Chime get location configuration function                                                   *
*                                                                                                         *
*Parameter  : id_u8 : configuration id                                                                    *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
uint32 Chime_RteAdaptGetLconfig(uint8 id_u8)
{
	uint32 Lconfig = 0xffffffff;
	switch(id_u8)
	{
		case (uint8)ChimeLconfigChimedelaytime:
		{
			Lconfig = (uint32)ChimeConfigData_s.Chimedelaytime_u8 * 100;
			break;
		}
		case (uint8)ChimeLconfigDoortoRed_speedthreshold:
		{
			Lconfig = ChimeConfigData_s.DoortoRed_speedthreshold_u8;
			break;
		}
		case (uint8)ChimeLconfigADASsoundfieldEnable:
		{
			Lconfig = ChimeConfigData_s.ADASsoundfieldEnable_u8;
			break;
		}
		case (uint8)ChimeLconfigAllFieldEnable:
		{
			Lconfig = ChimeConfigData_s.AllFieldEnable_u8;
			break;
		}
		case (uint8)ChimeLconfigFIXDISPLAY_1_GEAR_ENABLE:
		{
			Lconfig = ChimeConfigData_s.FIXDISPLAY_1_GEAR_ENABLE_u8;
			break;
		}
		case (uint8)ChimeLconfigFIXDISPLALY_2_SHIFT_GEAR_RECOMMEND_ENABLE:
		{
			Lconfig = ChimeConfigData_s.FIXDISPLALY_2_SHIFT_GEAR_RECOMMEND_ENABLE_u8;
			break;
		}
		case (uint8)ChimeLconfigDISPLAY_6_GEAR_ENABLE:
		{
			Lconfig = ChimeConfigData_s.DISPLAY_6_GEAR_ENABLE_u8;
			break;
		}
		case (uint8)ChimeLconfigDISPLALY_6_SHIFT_GEAR_RECOMMEND_ENABLE:
		{
			Lconfig = ChimeConfigData_s.DISPLALY_6_SHIFT_GEAR_RECOMMEND_ENABLE_u8;
			break;
		}
		case (uint8)ChimeVconfigCENTER_SPEAKKER:
		{
			Lconfig = ChimeConfigData_s.Center_Speaker;
			break;
		}
		case (uint8)ChimeVconfigCANFD_USE_FLAG:
		{
			Lconfig = ChimeConfigData_s.CAN_MESSAGE_USE_FD;
			break;
		}
		default:
		{
			Lconfig = 0x00;
			break;
		}
	}
	return Lconfig;
}

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
void Chime_RteAdaptOstmStart(uint8 index)
{
	uint8 status;
	status = Rte_Call_Os_Service_GetCounterValue(&ChimeOstmTickCounter_s[index].TimerTick_u32);
	if(RTE_E_Os_Service_E_OK == status)
	{
		ChimeOstmTickCounter_s[index].Status_u8 = CHIME_OSTM_TIMER_RUNING;
	}
	else
	{
		ChimeOstmTickCounter_s[index].Status_u8 = CHIME_OSTM_TIMER_START_ERROR;
	}
}

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
uint32 Chime_RteAdaptOstmCheck(uint8 index)
{
	uint8 sts_u8;
	uint32 pasTime_u32;
	uint32 OldTime_u32;
	OldTime_u32 = ChimeOstmTickCounter_s[index].TimerTick_u32;
	if(CHIME_OSTM_TIMER_CLEAR == ChimeOstmTickCounter_s[index].Status_u8)
	{
		pasTime_u32 = CHIME_OSTM_TIMER_MAX_COUNTER;
	}
	else if(CHIME_OSTM_TIMER_START_ERROR == ChimeOstmTickCounter_s[index].Status_u8)
	{
		Chime_RteAdaptOstmStart(index);
		pasTime_u32 = CHIME_OSTM_TIMER_MAX_COUNTER;
	}
	else
	{
		sts_u8 = Rte_Call_Os_Service_GetElapsedValue(&OldTime_u32,&pasTime_u32);
		if(RTE_E_Os_Service_E_OK != sts_u8)
		{
			pasTime_u32 = CHIME_OSTM_TIMER_MAX_COUNTER;
		}
	}
	return pasTime_u32;
}

/**********************************************************************************************************
*Function   : Chime_SpeakSound                                                                            *
*                                                                                                         *
*Description: Chime requirement interface call by app                                                     *
*                                                                                                         *
*Parameter  : index : ostm timer stop                                                                     *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_RteAdaptOstmStop(uint8 index)
{
	ChimeOstmTickCounter_s[index].Status_u8 = CHIME_OSTM_TIMER_CLEAR;
}

/**********************************************************************************************************
*Function   : Chime_RteAdaptTimerPass                                                                     *
*                                                                                                         *
*Description: Chime app timer check function                                                              *
*                                                                                                         *
*Parameter  : timer : timer ptr, pass: passtime                                                           *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
uint8 Chime_RteAdaptTimerPass(s_ChimeOstmData_t *timer,uint32 pass)
{
	if((CHIME_OSTM_TIMER_RUNING == timer->Status_u8) && (CHIME_OSTM_TIMER_MAX_COUNTER != timer->TimerTick_u32))
	{
		if(timer->TimerTick_u32 > pass)
		{
			timer->TimerTick_u32 -= pass;
		}
		else 
		{
			timer->Status_u8 = CHIME_OSTM_TIMER_OVER;
		}
	}
	return timer->Status_u8;
}

/**********************************************************************************************************
*Function   : Chime_RteAdaptTimerSet                                                                      *
*                                                                                                         *
*Description: app timer start function                                                                    *
*                                                                                                         *
*Parameter  : timer : timer ptr ,overTime : over timer                                                    *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_RteAdaptTimerSet(s_ChimeOstmData_t *timer,uint32 overTime)
{
	if(0x00 < overTime)
	{
		timer->TimerTick_u32 = overTime;
		timer->Status_u8 = CHIME_OSTM_TIMER_RUNING;
	}
	else
	{
		timer->TimerTick_u32 = overTime;
		timer->Status_u8 = CHIME_OSTM_TIMER_CLEAR;
	}
}
/**********************************************************************************************************
*Function   : Chime_RteAdaptTimerClr                                                                      *
*                                                                                                         *
*Description: app timer clear  function                                                                   *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_RteAdaptTimerClr(s_ChimeOstmData_t *timer)
{
	timer->Status_u8 = CHIME_OSTM_TIMER_CLEAR;
}

/**********************************************************************************************************
*Function   : Chime_RteAdaptTimerClr                                                                      *
*                                                                                                         *
*Description: app timer clear  function                                                                   *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_RteAdaptTimerPending(s_ChimeOstmData_t *timer)
{
	timer->Status_u8 = CHIME_OSTM_TIMER_PENNDING;
}

/**********************************************************************************************************
*Function   : NW_SIL_TX_Chime_DATA                                                                        *
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
void NW_SIL_TX_Chime_DATA(e_ChimeIPCCommand_t data)
{
	if((data.SoundId_u8 > e_SoundType_IdleMode) && (data.SoundId_u8 < e_SoundType_NumberOfChimes))
	{
		data.SoundId_u8 --;
	}
	(void)Rte_Call_IPC_Send_IPC_Send(((uint8)M2S_CHIME),(uint8 *)&data,(uint16)(sizeof(e_ChimeIPCCommand_t)),TRUE);
	(void)SWC_CHIME_WARN_LOG("request chime id%d,status%d,time%d,track%d",data.SoundId_u8,data.Operation_u8,data.RepeatTime_u32,data.Soundtrack);
}
/**********************************************************************************************************
*Function   : Chime_RteChimeSocReady                                                                      *
*                                                                                                         *
*Description: Chime soc ready flag，After this chime will request chime                                    *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
uint8 Chime_RteChimeSocReady(void)
{
	uint8 ready = 0U;
	if(RTE_E_OK != Rte_Read_SocReadyFlag_Element(&ready))
	{
		ready = 0;
	}
	/*The judgment condition is switched from CLST to CChimeClient[wcao/20210509]*/
	if(0x20U == (ready & 0x20U))
	{
		//wait HMI power status,use as hmi alive
		if(0x60 == (ready & 0x60U))
		{
			ready = 0x02;//Wait for hmi alive
		}
		else
		{
			ready = 0x01;//CChimeClient alive
		}
	}
	else
	{
		ready = 0;
	}
#ifdef CHIME_SOUND_REQUEST_TEST
	return 0;
#else
	return ready;
#endif
}
/**********************************************************************************************************
*Function   : Chime_Api_HMIPowerCallback                                                                  *
*                                                                                                         *
*Description: HMIPower callback get data                                                                  *
*                                                                                                         *
*Parameter  : data : Power Status                                                                         *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2021-03-27                                                                                  *
**********************************************************************************************************/
void Chime_Api_HMIPowerCallback(uint8 *data)
{
	ChimeHmiPowerStatus_u8 = *data;
	(void)SWC_CHIME_INFO_LOG("HMI power status = %d",ChimeHmiPowerStatus_u8);
}

/**********************************************************************************************************
*Function   : Chime_Api_ChimeCallback                                                                     *
*                                                                                                         *
*Description: Chime callback get data                                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_ChimeCallback(uint8 *data)
{
	(void)Rte_Enter_ExclusiveArea_Normal();
	
	(void)memcpy((uint8 *)&ChimeRteChimeCallback_t[0].data[ChimeRteChimeCallback_t[0].listNumber % IPC_CHIME_AUDIO_MESSAGE_LIST_NUMBER],data,sizeof(s_IPCChimeCallback_t));

	if(ChimeRteChimeCallback_t[0].listNumber < IPC_CHIME_AUDIO_MESSAGE_LIST_NUMBER)
	{
		ChimeRteChimeCallback_t[0].listNumber ++;
	}
	else
	{
		//error handle
		ChimeRteChimeCallback_t[0].listNumber ++;
		(void)SWC_CHIME_WARN_LOG("Chime callback overload");
	}
	//Chime_Api_Callback_Set(ChimeRteChimeCallback_t.data);
	
	(void)Rte_Exit_ExclusiveArea_Normal();
}
/**********************************************************************************************************
*Function   : Chime_Api_WrCallback                                                                        *
*                                                                                                         *
*Description: Chime callback get data                                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_WrCallback(uint8 *data)
{
	(void)Rte_Enter_ExclusiveArea_Normal();
#if 0
	if(ChimeRteWrnCallback_t[0].listNumber < IPC_CHIME_WRN_MESSAGE_LIST_NUMBER)
	{
		ChimeRteWrnCallback_t[0].listNumber ++;
	}
	else
	{
		//error handle
		ChimeRteWrnCallback_t[0].listNumber ++;
	}
	(void)memcpy((uint8 *)&ChimeRteWrnCallback_t[0].data[ChimeRteWrnCallback_t[0].listNumber],data,sizeof(s_IPCWrnCallback_t));
#endif
	ChimeWarningCheck(*((s_IPCWrnCallback_t *)data));

	(void)Rte_Exit_ExclusiveArea_Normal();
}
/**********************************************************************************************************
*Function   : Chime_Api_TTCallback                                                                        *
*                                                                                                         *
*Description: Chime callback get data                                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_TTCallback(uint8 *data)
{
	(void)Rte_Enter_ExclusiveArea_Normal();
	
	(void)memcpy((uint8 *)&ChimeRteTTCallback_t[0].data[ChimeRteTTCallback_t[0].listNumber % IPC_CHIME_TT_MESSAGE_LIST_NUMBER],data,sizeof(s_IPCTTCallback_t));
	
	if(ChimeRteTTCallback_t[0].listNumber < IPC_CHIME_TT_MESSAGE_LIST_NUMBER)
	{
		ChimeRteTTCallback_t[0].listNumber ++;
	}
	else
	{
		//error handle
		ChimeRteTTCallback_t[0].listNumber ++;
		(void)SWC_CHIME_WARN_LOG("TT callback overload");
	}
	(void)Rte_Exit_ExclusiveArea_Normal();
}

/**********************************************************************************************************
*Function   : Chime_Api_AdasCallback                                                                        *
*                                                                                                         *
*Description: Chime callback get data                                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
#if 0

void Chime_Api_AdasCallback(uint8 *data)
{
	Rte_Enter_ExclusiveArea_Normal();
	(void)memcpy((uint8 *)&ChimeRteAdasCallback_t[0].data[ChimeRteAdasCallback_t[0].listNumber],data,sizeof(s_IPCAdasCallback_t));

	if(ChimeRteAdasCallback_t[0].listNumber < IPC_CHIME_ADAS_MESSAGE_LIST_NUMBER)
	{
		ChimeRteAdasCallback_t[0].listNumber ++;
	}
	else
	{
		//error handle
		ChimeRteAdasCallback_t[0].listNumber ++;
	}

	ChimeAdasCheck(*((s_IPCAdasCallback_t *)data));

	Rte_Exit_ExclusiveArea_Normal();
}
#endif


/**********************************************************************************************************
*Function   : ChimeCopyCallbackData                                                                       *
*                                                                                                         *
*Description: Chime callback get data                                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void ChimeCopyCallbackData(void)
{
	uint16 temp,start,len;
	(void)Rte_Enter_ExclusiveArea_Normal();
	/*copy list data*/
	if(ChimeRteChimeCallback_t[0].listNumber > 0)
	{
		if(ChimeRteChimeCallback_t[0].listNumber > IPC_CHIME_AUDIO_MESSAGE_LIST_NUMBER)
		{
			start = ChimeRteChimeCallback_t[0].listNumber % IPC_CHIME_AUDIO_MESSAGE_LIST_NUMBER;
			len = IPC_CHIME_AUDIO_MESSAGE_LIST_NUMBER;
		}
		else
		{
			start = 0;
			len = ChimeRteChimeCallback_t[0].listNumber;
		}
		for(temp = 0;temp < len;temp ++)
		{
			(void)memcpy((uint8 *)&ChimeRteChimeCallback_t[1].data[temp],(uint8 *)&ChimeRteChimeCallback_t[0].data[start],sizeof(s_IPCChimeCallback_t));
			start = (start + 1u) % IPC_CHIME_AUDIO_MESSAGE_LIST_NUMBER;
		}
		ChimeRteChimeCallback_t[1].listNumber = len;
		ChimeRteChimeCallback_t[0].listNumber = 0;
	}
	/*copy wrn list data*/
#if 0
	if(ChimeRteWrnCallback_t[0].listNumber > 0)
	{
		if(ChimeRteWrnCallback_t[0].listNumber > IPC_CHIME_WRN_MESSAGE_LIST_NUMBER)
		{
			start = ChimeRteWrnCallback_t[0].listNumber % IPC_CHIME_WRN_MESSAGE_LIST_NUMBER;
			len = IPC_CHIME_WRN_MESSAGE_LIST_NUMBER;
		}
		else
		{
			start = 0;
			len = ChimeRteWrnCallback_t[0].listNumber;
		}
		for(temp = 0;temp < len;temp ++)
		{
			(void)memcpy((uint8 *)&ChimeRteWrnCallback_t[1].data[temp],(uint8 *)&ChimeRteWrnCallback_t[0].data[start],sizeof(s_IPCWrnCallback_t));
			start = (start + 1) % IPC_CHIME_WRN_MESSAGE_LIST_NUMBER;
		}
		ChimeRteWrnCallback_t[1].listNumber = len;
		ChimeRteWrnCallback_t[0].listNumber = 0;
	}
#endif
	/*copy TT list data*/
	if(ChimeRteTTCallback_t[0].listNumber > 0)
	{
		if(ChimeRteTTCallback_t[0].listNumber > IPC_CHIME_TT_MESSAGE_LIST_NUMBER)
		{
			start = ChimeRteTTCallback_t[0].listNumber % IPC_CHIME_TT_MESSAGE_LIST_NUMBER;
			len = IPC_CHIME_TT_MESSAGE_LIST_NUMBER;
		}
		else
		{
			start = 0;
			len = ChimeRteTTCallback_t[0].listNumber;
		}
		for(temp = 0;temp < len;temp ++)
		{
			(void)memcpy((uint8 *)&ChimeRteTTCallback_t[1].data[temp],(uint8 *)&ChimeRteTTCallback_t[0].data[start],sizeof(s_IPCTTCallback_t));
			start = (start + 1u) % IPC_CHIME_TT_MESSAGE_LIST_NUMBER;
		}
		ChimeRteTTCallback_t[1].listNumber = len;
		ChimeRteTTCallback_t[0].listNumber = 0;
	}
#if 0
	/*copy Adas list data*/
	if(ChimeRteAdasCallback_t[0].listNumber > 0)
	{
		if(ChimeRteAdasCallback_t[0].listNumber > IPC_CHIME_ADAS_MESSAGE_LIST_NUMBER)
		{
			start = ChimeRteAdasCallback_t[0].listNumber % IPC_CHIME_ADAS_MESSAGE_LIST_NUMBER;
			len = IPC_CHIME_ADAS_MESSAGE_LIST_NUMBER;
		}
		else
		{
			start = 0;
			len = ChimeRteAdasCallback_t[0].listNumber;
		}
		for(temp = 0;temp < len;temp ++)
		{
			(void)memcpy((uint8 *)&ChimeRteAdasCallback_t[1].data[temp],(uint8 *)&ChimeRteAdasCallback_t[0].data[start],sizeof(s_IPCAdasCallback_t));
			start = (start + 1) % IPC_CHIME_ADAS_MESSAGE_LIST_NUMBER;
		}
		ChimeRteAdasCallback_t[1].listNumber = len;
		ChimeRteAdasCallback_t[0].listNumber = 0;
	}
#endif
	(void)Rte_Exit_ExclusiveArea_Normal();
}

/**********************************************************************************************************
*Function   : Chime_Api_TTCallback                                                                        *
*                                                                                                         *
*Description: Chime callback get data                                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_CallbackTask(void)
{
	uint8 temp;
#ifdef CHIME_SOUND_REQUEST_TEST
	Chime_RequestTestFun();
#else
	ChimeCopyCallbackData();
	for(temp = 0;temp < ChimeRteChimeCallback_t[1].listNumber;temp ++)
	{
		if(ChimeRteChimeCallback_t[1].data[temp].CurId != 0xff)
		{
			ChimeRteChimeCallback_t[1].data[temp].CurId ++;
		}
		Chime_Api_Callback_Set(ChimeRteChimeCallback_t[1].data[temp]);
		(void)SWC_CHIME_WARN_LOG("Audio back id = %d,re = %d",ChimeRteChimeCallback_t[1].data[temp].CurId,ChimeRteChimeCallback_t[1].data[temp].LastRepeat);
	}
	ChimeRteChimeCallback_t[1].listNumber = 0;
#if 0
	ChimeRteChimeCallback_t[1].listNumber = 0;
	for(temp = 0;temp < ChimeRteWrnCallback_t[1].listNumber;temp ++)
	{
		ChimeWarningCheck(ChimeRteWrnCallback_t[1].data[temp]);
	}
	ChimeRteWrnCallback_t[1].listNumber = 0;
#endif
	for(temp = 0;temp < ChimeRteTTCallback_t[1].listNumber;temp ++)
	{
		ChimeTelltaleCheck(ChimeRteTTCallback_t[1].data[temp]);
	}
	ChimeRteTTCallback_t[1].listNumber = 0;
#if 0

	for(temp = 0;temp < ChimeRteAdasCallback_t[1].listNumber;temp ++)
	{
		ChimeAdasCheck(ChimeRteAdasCallback_t[1].data[temp]);
	}
	ChimeRteAdasCallback_t[1].listNumber = 0;
#endif

#endif
}
/**********************************************************************************************************
*Function   : Na                                                                                          *
*                                                                                                         *
*Description: RTE Message adapt                                                                           *
*                                                                                                         *
*Parameter  :                                                                                             *
*                                                                                                         *
*Return     :                                                                                             *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2021-01-30                                                                                  *
**********************************************************************************************************/
ChimeMessageType Chime_GetMessage_PASWorkCmd(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 pasworcmd_value = 0;

#if (CHIME_PROJECT_TYPE_B03 == 1)
	
#ifdef Rte_Read_PASWorkCmd_PASWorkCmd
	ret = Rte_Read_PASWorkCmd_PASWorkCmd(&pasworcmd_value);
	(*data) = pasworcmd_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASWORKCMD,&pasworcmd_value,(uint8)sizeof(pasworcmd_value));
	(*data) = pasworcmd_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASWORKCMD,&pasworcmd_value,(uint8)sizeof(pasworcmd_value));
	(*data) = pasworcmd_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASWORKCMD,&pasworcmd_value,(uint8)sizeof(pasworcmd_value));
	(*data) = pasworcmd_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASWORKCMD,&pasworcmd_value,(uint8)sizeof(pasworcmd_value));
	(*data) = pasworcmd_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASWORKCMD,&pasworcmd_value,(uint8)sizeof(pasworcmd_value));
	(*data) = pasworcmd_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASWORKCMD,&pasworcmd_value,(uint8)sizeof(pasworcmd_value));
	(*data) = pasworcmd_value;
	return ret;
		
#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASWORKCMD,&pasworcmd_value,(uint8)sizeof(pasworcmd_value));
	(*data) = pasworcmd_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASWORKCMD,&pasworcmd_value,(uint8)sizeof(pasworcmd_value));
	(*data) = pasworcmd_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASWORKCMD,&pasworcmd_value,(uint8)sizeof(pasworcmd_value));
	(*data) = pasworcmd_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}
ChimeMessageType Chime_GetMessage_RPAS_SoundIndcn(uint8 *data)
{
	

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_RPAS_SoundIndcn_RPAS_SoundIndcn
	ChimeMessageType ret = 0U;
	uint8 RPAS_SoundIndcn_value = 0;
	ret = Rte_Read_RPAS_SoundIndcn_RPAS_SoundIndcn(&RPAS_SoundIndcn_value);
	(*data) = RPAS_SoundIndcn_value;
	return ret;
#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	(*data) = 0;
	return RTE_E_INVALID;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1)
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P03 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ChimeMessageType ret = 0U;
	uint8 RPAS_SoundIndcn_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_SOUNDINDCN_0X26E,&RPAS_SoundIndcn_value,(uint8)sizeof(RPAS_SoundIndcn_value));
	(*data) = RPAS_SoundIndcn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D01 == 1)
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;	

#elif (CHIME_PROJECT_TYPE_P02 == 1)
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	ChimeMessageType ret = 0U;
	uint8 RPAS_SoundIndcn_value = 0;
	//ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_SOUNDINDCN_0X26E,&RPAS_SoundIndcn_value,(uint8)sizeof(RPAS_SoundIndcn_value));
	(*data) = RPAS_SoundIndcn_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_RPAS_WorkSts(uint8 *data)
{
	

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_RPAS_WorkSts_RPAS_WorkSts
	ChimeMessageType ret = 0U;
	uint8 RPAS_WorkSts_value = 0;
	ret = Rte_Read_RPAS_WorkSts_RPAS_WorkSts(&RPAS_WorkSts_value);
	(*data) = RPAS_WorkSts_value;
	return ret;
#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	(*data) = 0;
	return RTE_E_INVALID;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1)
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P03 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ChimeMessageType ret = 0U;
	uint8 RPAS_WorkSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_WORKSTS_0X26E,&RPAS_WorkSts_value,(uint8)sizeof(RPAS_WorkSts_value));
	(*data) = RPAS_WorkSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;
	
#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;
	
#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;	

#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	ChimeMessageType ret = 0U;
	uint8 RPAS_WorkSts_value = 0;
	//ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_WORKSTS_0X26E,&RPAS_WorkSts_value,(uint8)sizeof(RPAS_WorkSts_value));
	(*data) = RPAS_WorkSts_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_RPAS_SoundIndcn_FD(uint8 *data)
{	
	ChimeMessageType ret = 0U;
	uint8 Rpas_SoundIndcn_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_RPAS_SoundIndcn_FD_RPAS_SoundIndcn_FD
	ret = Rte_Read_RPAS_SoundIndcn_FD_RPAS_SoundIndcn_FD(&Rpas_SoundIndcn_value);
	(*data) = Rpas_SoundIndcn_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_SOUNDINDCN,&Rpas_SoundIndcn_value,(uint8)sizeof(Rpas_SoundIndcn_value));
	(*data) = Rpas_SoundIndcn_value;
	return ret;
	
	
#elif (CHIME_PROJECT_TYPE_P05 == 1)
	
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_SOUNDINDCN,&Rpas_SoundIndcn_value,(uint8)sizeof(Rpas_SoundIndcn_value));
	(*data) = Rpas_SoundIndcn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P03 == 1)
	
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_SOUNDINDCN,&Rpas_SoundIndcn_value,(uint8)sizeof(Rpas_SoundIndcn_value));
	(*data) = Rpas_SoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1)
	
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_SOUNDINDCN_0X298,&Rpas_SoundIndcn_value,(uint8)sizeof(Rpas_SoundIndcn_value));
	(*data) = Rpas_SoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_SOUNDINDCN,&Rpas_SoundIndcn_value,(uint8)sizeof(Rpas_SoundIndcn_value));
	(*data) = Rpas_SoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1)
	
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_SOUNDINDCN,&Rpas_SoundIndcn_value,(uint8)sizeof(Rpas_SoundIndcn_value));
	(*data) = Rpas_SoundIndcn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D03 == 1)
	
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_SOUNDINDCN,&Rpas_SoundIndcn_value,(uint8)sizeof(Rpas_SoundIndcn_value));
	(*data) = Rpas_SoundIndcn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_SOUNDINDCN,&Rpas_SoundIndcn_value,(uint8)sizeof(Rpas_SoundIndcn_value));
	(*data) = Rpas_SoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_SOUNDINDCN,&Rpas_SoundIndcn_value,(uint8)sizeof(Rpas_SoundIndcn_value));
	(*data) = Rpas_SoundIndcn_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_RPAS_WorkSts_FD(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 RPAS_WorkSts_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1) 

#ifdef Rte_Read_RPAS_WorkSts_FD_RPAS_WorkSts_FD
	ret = Rte_Read_RPAS_WorkSts_FD_RPAS_WorkSts_FD(&RPAS_WorkSts_value);
	(*data) = RPAS_WorkSts_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_WORKSTS,&RPAS_WorkSts_value,(uint8)sizeof(RPAS_WorkSts_value));
	(*data) = RPAS_WorkSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1)
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_WORKSTS,&RPAS_WorkSts_value,(uint8)sizeof(RPAS_WorkSts_value));
	(*data) = RPAS_WorkSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1) 
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_WORKSTS,&RPAS_WorkSts_value,(uint8)sizeof(RPAS_WorkSts_value));
	(*data) = RPAS_WorkSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1)
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_WORKSTS_0X298,&RPAS_WorkSts_value,(uint8)sizeof(RPAS_WorkSts_value));
	(*data) = RPAS_WorkSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1)
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_WORKSTS,&RPAS_WorkSts_value,(uint8)sizeof(RPAS_WorkSts_value));
	(*data) = RPAS_WorkSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1)
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_WORKSTS,&RPAS_WorkSts_value,(uint8)sizeof(RPAS_WorkSts_value));
	(*data) = RPAS_WorkSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1)
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_WORKSTS,&RPAS_WorkSts_value,(uint8)sizeof(RPAS_WorkSts_value));
	(*data) = RPAS_WorkSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P02 == 1)
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_WORKSTS,&RPAS_WorkSts_value,(uint8)sizeof(RPAS_WorkSts_value));
	(*data) = RPAS_WorkSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RPAS_WORKSTS,&RPAS_WorkSts_value,(uint8)sizeof(RPAS_WorkSts_value));
	(*data) = RPAS_WorkSts_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_FPAS_SoundIndcn(uint8 *data)
{	

	
#if(CHIME_PROJECT_TYPE_B03 == 1) 

#ifdef Rte_Read_FPAS_SoundIndcn_FPAS_SoundIndcn
	ChimeMessageType ret = 0U;
	uint8 FPAS_SoundIndcn_value = 0;
	ret = Rte_Read_FPAS_SoundIndcn_FPAS_SoundIndcn(&FPAS_SoundIndcn_value);
	(*data) = FPAS_SoundIndcn_value;
	return ret;
#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	(*data) = 0;
	return RTE_E_INVALID;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ChimeMessageType ret = 0U;
	uint8 FPAS_SoundIndcn_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_SOUNDINDCN_0X26D,&FPAS_SoundIndcn_value,(uint8)sizeof(FPAS_SoundIndcn_value));
	(*data) = FPAS_SoundIndcn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	ChimeMessageType ret = 0U;
	uint8 FPAS_SoundIndcn_value = 0;
	//ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_SOUNDINDCN_0X26D,&FPAS_SoundIndcn_value,(uint8)sizeof(FPAS_SoundIndcn_value));
	(*data) = FPAS_SoundIndcn_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_FPAS_WorkSts(uint8 *data)
{
	

#if(CHIME_PROJECT_TYPE_B03 == 1) 

#ifdef Rte_Read_FPAS_WorkSts_FPAS_WorkSts
	ChimeMessageType ret = 0U;
	uint8 FPAS_WorkSts_value = 0;
	ret = Rte_Read_FPAS_WorkSts_FPAS_WorkSts(&FPAS_WorkSts_value);
	(*data) = FPAS_WorkSts_value;
	return ret; 
#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	(*data) = 0;
	return RTE_E_INVALID;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P03 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ChimeMessageType ret = 0U;
	uint8 FPAS_WorkSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_WORKSTS_0X26D,&FPAS_WorkSts_value,(uint8)sizeof(FPAS_WorkSts_value));
	(*data) = FPAS_WorkSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;
	
#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;
	
#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	ChimeMessageType ret = 0U;
	uint8 FPAS_WorkSts_value = 0;
	//ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_WORKSTS_0X26D,&FPAS_WorkSts_value,(uint8)sizeof(FPAS_WorkSts_value));
	(*data) = FPAS_WorkSts_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_FPAS_SoundIndcn_FD(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 FPAS_SoundIndcn_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_FPAS_SoundIndcn_FD_FPAS_SoundIndcn_FD
	ret = Rte_Read_FPAS_SoundIndcn_FD_FPAS_SoundIndcn_FD(&FPAS_SoundIndcn_value);
	(*data) = FPAS_SoundIndcn_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_SOUNDINDCN,&FPAS_SoundIndcn_value,(uint8)sizeof(FPAS_SoundIndcn_value));
	(*data) = FPAS_SoundIndcn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_SOUNDINDCN,&FPAS_SoundIndcn_value,(uint8)sizeof(FPAS_SoundIndcn_value));
	(*data) = FPAS_SoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1) 
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_SOUNDINDCN,&FPAS_SoundIndcn_value,(uint8)sizeof(FPAS_SoundIndcn_value));
	(*data) = FPAS_SoundIndcn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_A07 == 1)
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_SOUNDINDCN_0X298,&FPAS_SoundIndcn_value,(uint8)sizeof(FPAS_SoundIndcn_value));
	(*data) = FPAS_SoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1)
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_SOUNDINDCN,&FPAS_SoundIndcn_value,(uint8)sizeof(FPAS_SoundIndcn_value));
	(*data) = FPAS_SoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_SOUNDINDCN,&FPAS_SoundIndcn_value,(uint8)sizeof(FPAS_SoundIndcn_value));
	(*data) = FPAS_SoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_SOUNDINDCN,&FPAS_SoundIndcn_value,(uint8)sizeof(FPAS_SoundIndcn_value));
	(*data) = FPAS_SoundIndcn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_SOUNDINDCN,&FPAS_SoundIndcn_value,(uint8)sizeof(FPAS_SoundIndcn_value));
	(*data) = FPAS_SoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_SOUNDINDCN,&FPAS_SoundIndcn_value,(uint8)sizeof(FPAS_SoundIndcn_value));
	(*data) = FPAS_SoundIndcn_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_FPAS_WorkSts_FD(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 FPAS_WorkSts_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_FPAS_WorkSts_FD_FPAS_WorkSts_FD
	ret = Rte_Read_FPAS_WorkSts_FD_FPAS_WorkSts_FD(&FPAS_WorkSts_value);
	(*data) = FPAS_WorkSts_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_WORKSTS,&FPAS_WorkSts_value,(uint8)sizeof(FPAS_WorkSts_value));
	(*data) = FPAS_WorkSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_WORKSTS,&FPAS_WorkSts_value,(uint8)sizeof(FPAS_WorkSts_value));
	(*data) = FPAS_WorkSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1) 
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_WORKSTS,&FPAS_WorkSts_value,(uint8)sizeof(FPAS_WorkSts_value));
	(*data) = FPAS_WorkSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_WORKSTS_0X298,&FPAS_WorkSts_value,(uint8)sizeof(FPAS_WorkSts_value));
	(*data) = FPAS_WorkSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_WORKSTS,&FPAS_WorkSts_value,(uint8)sizeof(FPAS_WorkSts_value));
	(*data) = FPAS_WorkSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_WORKSTS,&FPAS_WorkSts_value,(uint8)sizeof(FPAS_WorkSts_value));
	(*data) = FPAS_WorkSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_WORKSTS,&FPAS_WorkSts_value,(uint8)sizeof(FPAS_WorkSts_value));
	(*data) = FPAS_WorkSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_WORKSTS,&FPAS_WorkSts_value,(uint8)sizeof(FPAS_WorkSts_value));
	(*data) = FPAS_WorkSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FPAS_WORKSTS,&FPAS_WorkSts_value,(uint8)sizeof(FPAS_WorkSts_value));
	(*data) = FPAS_WorkSts_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_SDWActiveSts(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 SDWACTIVESTS_value =0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_SDWActiveSts_SDWActiveSts
	ret = Rte_Read_SDWActiveSts_SDWActiveSts(&SDWACTIVESTS_value);
	(*data) = SDWACTIVESTS_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SDWACTIVESTS,&SDWACTIVESTS_value,(uint8)sizeof(SDWACTIVESTS_value));
	(*data) = SDWACTIVESTS_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1)
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SDWACTIVESTS,&SDWACTIVESTS_value,(uint8)sizeof(SDWACTIVESTS_value));
	(*data) = SDWACTIVESTS_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P03 == 1) 
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SDWACTIVESTS,&SDWACTIVESTS_value,(uint8)sizeof(SDWACTIVESTS_value));
	(*data) = SDWACTIVESTS_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1)

	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SDWACTIVESTS_0X298,&SDWACTIVESTS_value,(uint8)sizeof(SDWACTIVESTS_value));
	(*data) = SDWACTIVESTS_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1)
		
		ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SDWACTIVESTS,&SDWACTIVESTS_value,(uint8)sizeof(SDWACTIVESTS_value));
		(*data) = SDWACTIVESTS_value;
		return ret;
		
#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SDWACTIVESTS,&SDWACTIVESTS_value,(uint8)sizeof(SDWACTIVESTS_value));
	(*data) = SDWACTIVESTS_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SDWACTIVESTS,&SDWACTIVESTS_value,(uint8)sizeof(SDWACTIVESTS_value));
	(*data) = SDWACTIVESTS_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SDWACTIVESTS,&SDWACTIVESTS_value,(uint8)sizeof(SDWACTIVESTS_value));
	(*data) = SDWACTIVESTS_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SDWACTIVESTS,&SDWACTIVESTS_value,(uint8)sizeof(SDWACTIVESTS_value));
	(*data) = SDWACTIVESTS_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_APS_FRSideSnsrFailSts(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 APS_FRSideSnsrFailSts_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_APS_FRSideSnsrFailSts_APS_FRSideSnsrFailSts
	ret = Rte_Read_APS_FRSideSnsrFailSts_APS_FRSideSnsrFailSts(&APS_FRSideSnsrFailSts_value);
	(*data) = APS_FRSideSnsrFailSts_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_FRSIDESNSRFAILSTS,&APS_FRSideSnsrFailSts_value,(uint8)sizeof(APS_FRSideSnsrFailSts_value));
	(*data) = APS_FRSideSnsrFailSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_FRSIDESNSRFAILSTS,&APS_FRSideSnsrFailSts_value,(uint8)sizeof(APS_FRSideSnsrFailSts_value));
	(*data) = APS_FRSideSnsrFailSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_FRSIDESNSRFAILSTS,&APS_FRSideSnsrFailSts_value,(uint8)sizeof(APS_FRSideSnsrFailSts_value));
	(*data) = APS_FRSideSnsrFailSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_FRSIDESNSRFAILSTS_0X298,&APS_FRSideSnsrFailSts_value,(uint8)sizeof(APS_FRSideSnsrFailSts_value));
	(*data) = APS_FRSideSnsrFailSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1) 
		ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_FRSIDESNSRFAILSTS,&APS_FRSideSnsrFailSts_value,(uint8)sizeof(APS_FRSideSnsrFailSts_value));
		(*data) = APS_FRSideSnsrFailSts_value;
		return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_FRSIDESNSRFAILSTS,&APS_FRSideSnsrFailSts_value,(uint8)sizeof(APS_FRSideSnsrFailSts_value));
	(*data) = APS_FRSideSnsrFailSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_FRSIDESNSRFAILSTS,&APS_FRSideSnsrFailSts_value,(uint8)sizeof(APS_FRSideSnsrFailSts_value));
	(*data) = APS_FRSideSnsrFailSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_FRSIDESNSRFAILSTS,&APS_FRSideSnsrFailSts_value,(uint8)sizeof(APS_FRSideSnsrFailSts_value));
	(*data) = APS_FRSideSnsrFailSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_FRSIDESNSRFAILSTS,&APS_FRSideSnsrFailSts_value,(uint8)sizeof(APS_FRSideSnsrFailSts_value));
	(*data) = APS_FRSideSnsrFailSts_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_APS_FLSideSnsrFailSts(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 APS_FLSideSnsrFailSts_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_APS_FLSideSnsrFailSts_APS_FLSideSnsrFailSts
	ret = Rte_Read_APS_FLSideSnsrFailSts_APS_FLSideSnsrFailSts(&APS_FLSideSnsrFailSts_value);
	(*data) = APS_FLSideSnsrFailSts_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_FLSIDESNSRFAILSTS,&APS_FLSideSnsrFailSts_value,(uint8)sizeof(APS_FLSideSnsrFailSts_value));
	(*data) = APS_FLSideSnsrFailSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_FLSIDESNSRFAILSTS,&APS_FLSideSnsrFailSts_value,(uint8)sizeof(APS_FLSideSnsrFailSts_value));
	(*data) = APS_FLSideSnsrFailSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_FLSIDESNSRFAILSTS,&APS_FLSideSnsrFailSts_value,(uint8)sizeof(APS_FLSideSnsrFailSts_value));
	(*data) = APS_FLSideSnsrFailSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_FLSIDESNSRFAILSTS_0X298,&APS_FLSideSnsrFailSts_value,(uint8)sizeof(APS_FLSideSnsrFailSts_value));
	(*data) = APS_FLSideSnsrFailSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1) 
		ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_FLSIDESNSRFAILSTS,&APS_FLSideSnsrFailSts_value,(uint8)sizeof(APS_FLSideSnsrFailSts_value));
		(*data) = APS_FLSideSnsrFailSts_value;
		return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_FLSIDESNSRFAILSTS,&APS_FLSideSnsrFailSts_value,(uint8)sizeof(APS_FLSideSnsrFailSts_value));
	(*data) = APS_FLSideSnsrFailSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_FLSIDESNSRFAILSTS,&APS_FLSideSnsrFailSts_value,(uint8)sizeof(APS_FLSideSnsrFailSts_value));
	(*data) = APS_FLSideSnsrFailSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_FLSIDESNSRFAILSTS,&APS_FLSideSnsrFailSts_value,(uint8)sizeof(APS_FLSideSnsrFailSts_value));
	(*data) = APS_FLSideSnsrFailSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_FLSIDESNSRFAILSTS,&APS_FLSideSnsrFailSts_value,(uint8)sizeof(APS_FLSideSnsrFailSts_value));
	(*data) = APS_FLSideSnsrFailSts_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_APS_RLSideSnsrFailSts(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 APS_RLSideSnsrFailSts_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_APS_RLSideSnsrFailSts_APS_RLSideSnsrFailSts
	ret = Rte_Read_APS_RLSideSnsrFailSts_APS_RLSideSnsrFailSts(&APS_RLSideSnsrFailSts_value);
	(*data) = APS_RLSideSnsrFailSts_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_RLSIDESNSRFAILSTS,&APS_RLSideSnsrFailSts_value,(uint8)sizeof(APS_RLSideSnsrFailSts_value));
	(*data) = APS_RLSideSnsrFailSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_RLSIDESNSRFAILSTS,&APS_RLSideSnsrFailSts_value,(uint8)sizeof(APS_RLSideSnsrFailSts_value));
	(*data) = APS_RLSideSnsrFailSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_RLSIDESNSRFAILSTS,&APS_RLSideSnsrFailSts_value,(uint8)sizeof(APS_RLSideSnsrFailSts_value));
	(*data) = APS_RLSideSnsrFailSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_RLSIDESNSRFAILSTS_0X298,&APS_RLSideSnsrFailSts_value,(uint8)sizeof(APS_RLSideSnsrFailSts_value));
	(*data) = APS_RLSideSnsrFailSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_RLSIDESNSRFAILSTS,&APS_RLSideSnsrFailSts_value,(uint8)sizeof(APS_RLSideSnsrFailSts_value));
	(*data) = APS_RLSideSnsrFailSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_RLSIDESNSRFAILSTS,&APS_RLSideSnsrFailSts_value,(uint8)sizeof(APS_RLSideSnsrFailSts_value));
	(*data) = APS_RLSideSnsrFailSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_RLSIDESNSRFAILSTS,&APS_RLSideSnsrFailSts_value,(uint8)sizeof(APS_RLSideSnsrFailSts_value));
	(*data) = APS_RLSideSnsrFailSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_RLSIDESNSRFAILSTS,&APS_RLSideSnsrFailSts_value,(uint8)sizeof(APS_RLSideSnsrFailSts_value));
	(*data) = APS_RLSideSnsrFailSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_RLSIDESNSRFAILSTS,&APS_RLSideSnsrFailSts_value,(uint8)sizeof(APS_RLSideSnsrFailSts_value));
	(*data) = APS_RLSideSnsrFailSts_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_APS_RRSideSnsrFailSts(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 APS_RRSIDESNSRFAILSTS_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_APS_RRSideSnsrFailSts_APS_RRSideSnsrFailSts
	ret = Rte_Read_APS_RRSideSnsrFailSts_APS_RRSideSnsrFailSts(&APS_RRSIDESNSRFAILSTS_value);
	(*data) = APS_RRSIDESNSRFAILSTS_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_RRSIDESNSRFAILSTS,&APS_RRSIDESNSRFAILSTS_value,(uint8)sizeof(APS_RRSIDESNSRFAILSTS_value));
	(*data) = APS_RRSIDESNSRFAILSTS_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_RRSIDESNSRFAILSTS,&APS_RRSIDESNSRFAILSTS_value,(uint8)sizeof(APS_RRSIDESNSRFAILSTS_value));
	(*data) = APS_RRSIDESNSRFAILSTS_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_RRSIDESNSRFAILSTS,&APS_RRSIDESNSRFAILSTS_value,(uint8)sizeof(APS_RRSIDESNSRFAILSTS_value));
	(*data) = APS_RRSIDESNSRFAILSTS_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_RRSIDESNSRFAILSTS_0X298,&APS_RRSIDESNSRFAILSTS_value,(uint8)sizeof(APS_RRSIDESNSRFAILSTS_value));
	(*data) = APS_RRSIDESNSRFAILSTS_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_RRSIDESNSRFAILSTS,&APS_RRSIDESNSRFAILSTS_value,(uint8)sizeof(APS_RRSIDESNSRFAILSTS_value));
	(*data) = APS_RRSIDESNSRFAILSTS_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_RRSIDESNSRFAILSTS,&APS_RRSIDESNSRFAILSTS_value,(uint8)sizeof(APS_RRSIDESNSRFAILSTS_value));
	(*data) = APS_RRSIDESNSRFAILSTS_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_RRSIDESNSRFAILSTS,&APS_RRSIDESNSRFAILSTS_value,(uint8)sizeof(APS_RRSIDESNSRFAILSTS_value));
	(*data) = APS_RRSIDESNSRFAILSTS_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_RRSIDESNSRFAILSTS,&APS_RRSIDESNSRFAILSTS_value,(uint8)sizeof(APS_RRSIDESNSRFAILSTS_value));
	(*data) = APS_RRSIDESNSRFAILSTS_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_RRSIDESNSRFAILSTS,&APS_RRSIDESNSRFAILSTS_value,(uint8)sizeof(APS_RRSIDESNSRFAILSTS_value));
	(*data) = APS_RRSIDESNSRFAILSTS_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_SDW_SoundIndcn(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 SDW_SoundIndcn_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_SDW_SoundIndcn_SDW_SoundIndcn
	ret = Rte_Read_SDW_SoundIndcn_SDW_SoundIndcn(&SDW_SoundIndcn_value);
	(*data) = SDW_SoundIndcn_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SDW_SOUNDINDCN,&SDW_SoundIndcn_value,(uint8)sizeof(SDW_SoundIndcn_value));
	(*data) = SDW_SoundIndcn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SDW_SOUNDINDCN,&SDW_SoundIndcn_value,(uint8)sizeof(SDW_SoundIndcn_value));
	(*data) = SDW_SoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SDW_SOUNDINDCN,&SDW_SoundIndcn_value,sizeof(SDW_SoundIndcn_value));
	(*data) = SDW_SoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SDW_SOUNDINDCN_0X298,&SDW_SoundIndcn_value,(uint8)sizeof(SDW_SoundIndcn_value));
	(*data) = SDW_SoundIndcn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SDW_SOUNDINDCN,&SDW_SoundIndcn_value,(uint8)sizeof(SDW_SoundIndcn_value));
	(*data) = SDW_SoundIndcn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SDW_SOUNDINDCN,&SDW_SoundIndcn_value,(uint8)sizeof(SDW_SoundIndcn_value));
	(*data) = SDW_SoundIndcn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SDW_SOUNDINDCN,&SDW_SoundIndcn_value,(uint8)sizeof(SDW_SoundIndcn_value));
	(*data) = SDW_SoundIndcn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SDW_SOUNDINDCN,&SDW_SoundIndcn_value,(uint8)sizeof(SDW_SoundIndcn_value));
	(*data) = SDW_SoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SDW_SOUNDINDCN,&SDW_SoundIndcn_value,(uint8)sizeof(SDW_SoundIndcn_value));
	(*data) = SDW_SoundIndcn_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_APS_SysSoundIndcn(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 APS_SysSoundIndcn_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_APS_SysSoundIndcn_APS_SysSoundIndcn
	ret = Rte_Read_APS_SysSoundIndcn_APS_SysSoundIndcn(&APS_SysSoundIndcn_value);
	(*data) = APS_SysSoundIndcn_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_SYSSOUNDINDCN,&APS_SysSoundIndcn_value,(uint8)sizeof(APS_SysSoundIndcn_value));
	(*data) = APS_SysSoundIndcn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_SYSSOUNDINDCN,&APS_SysSoundIndcn_value,(uint8)sizeof(APS_SysSoundIndcn_value));
	(*data) = APS_SysSoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_SYSSOUNDINDCN,&APS_SysSoundIndcn_value,(uint8)sizeof(APS_SysSoundIndcn_value));
	(*data) = APS_SysSoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_SYSSOUNDINDCN_0X15B,&APS_SysSoundIndcn_value,(uint8)sizeof(APS_SysSoundIndcn_value));
	(*data) = APS_SysSoundIndcn_value;
	return ret;
#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_SYSSOUNDINDCN,&APS_SysSoundIndcn_value,(uint8)sizeof(APS_SysSoundIndcn_value));
	(*data) = APS_SysSoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_SYSSOUNDINDCN,&APS_SysSoundIndcn_value,(uint8)sizeof(APS_SysSoundIndcn_value));
	(*data) = APS_SysSoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_SYSSOUNDINDCN,&APS_SysSoundIndcn_value,(uint8)sizeof(APS_SysSoundIndcn_value));
	(*data) = APS_SysSoundIndcn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_SYSSOUNDINDCN,&APS_SysSoundIndcn_value,(uint8)sizeof(APS_SysSoundIndcn_value));
	(*data) = APS_SysSoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_APS_SYSSOUNDINDCN,&APS_SysSoundIndcn_value,(uint8)sizeof(APS_SysSoundIndcn_value));
	(*data) = APS_SysSoundIndcn_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_RSDS_IPSoundReq(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 RSDS_IPSoundReq_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_RSDS_IPSoundReq_RSDS_IPSoundReq
	ret = Rte_Read_RSDS_IPSoundReq_RSDS_IPSoundReq(&RSDS_IPSoundReq_value);
	(*data) = RSDS_IPSoundReq_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_IPSOUNDREQ,&RSDS_IPSoundReq_value,(uint8)sizeof(RSDS_IPSoundReq_value));
	(*data) = RSDS_IPSoundReq_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_IPSOUNDREQ,&RSDS_IPSoundReq_value,(uint8)sizeof(RSDS_IPSoundReq_value));
	(*data) = RSDS_IPSoundReq_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_IPSOUNDREQ,&RSDS_IPSoundReq_value,(uint8)sizeof(RSDS_IPSoundReq_value));
	(*data) = RSDS_IPSoundReq_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_IPSOUNDREQ,&RSDS_IPSoundReq_value,(uint8)sizeof(RSDS_IPSoundReq_value));
	(*data) = RSDS_IPSoundReq_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_IPSOUNDREQ,&RSDS_IPSoundReq_value,(uint8)sizeof(RSDS_IPSoundReq_value));
	(*data) = RSDS_IPSoundReq_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_IPSOUNDREQ,&RSDS_IPSoundReq_value,(uint8)sizeof(RSDS_IPSoundReq_value));
	(*data) = RSDS_IPSoundReq_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_IPSOUNDREQ,&RSDS_IPSoundReq_value,(uint8)sizeof(RSDS_IPSoundReq_value));
	(*data) = RSDS_IPSoundReq_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_IPSOUNDREQ,&RSDS_IPSoundReq_value,(uint8)sizeof(RSDS_IPSoundReq_value));
	(*data) = RSDS_IPSoundReq_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_IPSOUNDREQ,&RSDS_IPSoundReq_value,(uint8)sizeof(RSDS_IPSoundReq_value));
	(*data) = RSDS_IPSoundReq_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_BSD_LCA_warningReqRight(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 BSD_LCA_warningReqRight_value  = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1) 

#ifdef Rte_Read_BSD_LCA_warningReqRight_BSD_LCA_warningReqRight
	ret = Rte_Read_BSD_LCA_warningReqRight_BSD_LCA_warningReqRight(&BSD_LCA_warningReqRight_value);
	(*data) = BSD_LCA_warningReqRight_value;
	return ret;	

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT,&BSD_LCA_warningReqRight_value,(uint8)sizeof(BSD_LCA_warningReqRight_value));
	(*data) = BSD_LCA_warningReqRight_value;
	return ret;	
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT,&BSD_LCA_warningReqRight_value,(uint8)sizeof(BSD_LCA_warningReqRight_value));
	(*data) = BSD_LCA_warningReqRight_value;
	return ret;	

#elif (CHIME_PROJECT_TYPE_P03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT,&BSD_LCA_warningReqRight_value,(uint8)sizeof(BSD_LCA_warningReqRight_value));
	(*data) = BSD_LCA_warningReqRight_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT,&BSD_LCA_warningReqRight_value,(uint8)sizeof(BSD_LCA_warningReqRight_value));
	(*data) = BSD_LCA_warningReqRight_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT,&BSD_LCA_warningReqRight_value,(uint8)sizeof(BSD_LCA_warningReqRight_value));
	(*data) = BSD_LCA_warningReqRight_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT,&BSD_LCA_warningReqRight_value,(uint8)sizeof(BSD_LCA_warningReqRight_value));
	(*data) = BSD_LCA_warningReqRight_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT,&BSD_LCA_warningReqRight_value,(uint8)sizeof(BSD_LCA_warningReqRight_value));
	(*data) = BSD_LCA_warningReqRight_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT,&BSD_LCA_warningReqRight_value,(uint8)sizeof(BSD_LCA_warningReqRight_value));
	(*data) = BSD_LCA_warningReqRight_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT,&BSD_LCA_warningReqRight_value,(uint8)sizeof(BSD_LCA_warningReqRight_value));
	(*data) = BSD_LCA_warningReqRight_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_BSD_LCA_warningReqleft(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 BSD_LCA_warningReqleft_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1) 

#ifdef Rte_Read_BSD_LCA_warningReqleft_BSD_LCA_warningReqleft
	ret = Rte_Read_BSD_LCA_warningReqleft_BSD_LCA_warningReqleft(&BSD_LCA_warningReqleft_value);
	(*data) = BSD_LCA_warningReqleft_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT,&BSD_LCA_warningReqleft_value,(uint8)sizeof(BSD_LCA_warningReqleft_value));
	(*data) = BSD_LCA_warningReqleft_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT,&BSD_LCA_warningReqleft_value,(uint8)sizeof(BSD_LCA_warningReqleft_value));
	(*data) = BSD_LCA_warningReqleft_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT,&BSD_LCA_warningReqleft_value,(uint8)sizeof(BSD_LCA_warningReqleft_value));
	(*data) = BSD_LCA_warningReqleft_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT,&BSD_LCA_warningReqleft_value,(uint8)sizeof(BSD_LCA_warningReqleft_value));
	(*data) = BSD_LCA_warningReqleft_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT,&BSD_LCA_warningReqleft_value,(uint8)sizeof(BSD_LCA_warningReqleft_value));
	(*data) = BSD_LCA_warningReqleft_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT,&BSD_LCA_warningReqleft_value,(uint8)sizeof(BSD_LCA_warningReqleft_value));
	(*data) = BSD_LCA_warningReqleft_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT,&BSD_LCA_warningReqleft_value,(uint8)sizeof(BSD_LCA_warningReqleft_value));
	(*data) = BSD_LCA_warningReqleft_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT,&BSD_LCA_warningReqleft_value,(uint8)sizeof(BSD_LCA_warningReqleft_value));
	(*data) = BSD_LCA_warningReqleft_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT,&BSD_LCA_warningReqleft_value,(uint8)sizeof(BSD_LCA_warningReqleft_value));
	(*data) = BSD_LCA_warningReqleft_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_RCTA_warningReqRight(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 RCTA_warningReqRight_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_RCTA_warningReqRight_RCTA_warningReqRight
	ret = Rte_Read_RCTA_warningReqRight_RCTA_warningReqRight(&RCTA_warningReqRight_value);
	(*data) = RCTA_warningReqRight_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RCTA_WARNINGREQRIGHT,&RCTA_warningReqRight_value,(uint8)sizeof(RCTA_warningReqRight_value));
	(*data) = RCTA_warningReqRight_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RCTA_WARNINGREQRIGHT,&RCTA_warningReqRight_value,(uint8)sizeof(RCTA_warningReqRight_value));
	(*data) = RCTA_warningReqRight_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RCTA_WARNINGREQRIGHT,&RCTA_warningReqRight_value,(uint8)sizeof(RCTA_warningReqRight_value));
	(*data) = RCTA_warningReqRight_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RCTA_WARNINGREQRIGHT,&RCTA_warningReqRight_value,(uint8)sizeof(RCTA_warningReqRight_value));
	(*data) = RCTA_warningReqRight_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RCTA_WARNINGREQRIGHT,&RCTA_warningReqRight_value,(uint8)sizeof(RCTA_warningReqRight_value));
	(*data) = RCTA_warningReqRight_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RCTA_WARNINGREQRIGHT,&RCTA_warningReqRight_value,(uint8)sizeof(RCTA_warningReqRight_value));
	(*data) = RCTA_warningReqRight_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RCTA_WARNINGREQRIGHT,&RCTA_warningReqRight_value,(uint8)sizeof(RCTA_warningReqRight_value));
	(*data) = RCTA_warningReqRight_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RCTA_WARNINGREQRIGHT,&RCTA_warningReqRight_value,(uint8)sizeof(RCTA_warningReqRight_value));
	(*data) = RCTA_warningReqRight_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RCTA_WARNINGREQRIGHT,&RCTA_warningReqRight_value,(uint8)sizeof(RCTA_warningReqRight_value));
	(*data) = RCTA_warningReqRight_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_RCTA_warningReqLeft(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 RCTA_warningReqLeft_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_RCTA_warningReqLeft_RCTA_warningReqLeft
	ret = Rte_Read_RCTA_warningReqLeft_RCTA_warningReqLeft(&RCTA_warningReqLeft_value);
	(*data) = RCTA_warningReqLeft_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RCTA_WARNINGREQLEFT,&RCTA_warningReqLeft_value,(uint8)sizeof(RCTA_warningReqLeft_value));
	(*data) = RCTA_warningReqLeft_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RCTA_WARNINGREQLEFT,&RCTA_warningReqLeft_value,(uint8)sizeof(RCTA_warningReqLeft_value));
	(*data) = RCTA_warningReqLeft_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P03 == 1) 	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RCTA_WARNINGREQLEFT,&RCTA_warningReqLeft_value,(uint8)sizeof(RCTA_warningReqLeft_value));
	(*data) = RCTA_warningReqLeft_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RCTA_WARNINGREQLEFT,&RCTA_warningReqLeft_value,(uint8)sizeof(RCTA_warningReqLeft_value));
	(*data) = RCTA_warningReqLeft_value;
	return ret;
#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RCTA_WARNINGREQLEFT,&RCTA_warningReqLeft_value,(uint8)sizeof(RCTA_warningReqLeft_value));
	(*data) = RCTA_warningReqLeft_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RCTA_WARNINGREQLEFT,&RCTA_warningReqLeft_value,(uint8)sizeof(RCTA_warningReqLeft_value));
	(*data) = RCTA_warningReqLeft_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RCTA_WARNINGREQLEFT,&RCTA_warningReqLeft_value,(uint8)sizeof(RCTA_warningReqLeft_value));
	(*data) = RCTA_warningReqLeft_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RCTA_WARNINGREQLEFT,&RCTA_warningReqLeft_value,(uint8)sizeof(RCTA_warningReqLeft_value));
	(*data) = RCTA_warningReqLeft_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RCTA_WARNINGREQLEFT,&RCTA_warningReqLeft_value,(uint8)sizeof(RCTA_warningReqLeft_value));
	(*data) = RCTA_warningReqLeft_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_DOW_warningReqRight(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 DOW_warningReqRight_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_DOW_warningReqRight_DOW_warningReqRight
	ret = Rte_Read_DOW_warningReqRight_DOW_warningReqRight(&DOW_warningReqRight_value);
	(*data) = DOW_warningReqRight_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQRIGHT,&DOW_warningReqRight_value,(uint8)sizeof(DOW_warningReqRight_value));
	(*data) = DOW_warningReqRight_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQRIGHT,&DOW_warningReqRight_value,(uint8)sizeof(DOW_warningReqRight_value));
	(*data) = DOW_warningReqRight_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQRIGHT,&DOW_warningReqRight_value,(uint8)sizeof(DOW_warningReqRight_value));
	(*data) = DOW_warningReqRight_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQRIGHT,&DOW_warningReqRight_value,(uint8)sizeof(DOW_warningReqRight_value));
	(*data) = DOW_warningReqRight_value;
	return ret;
#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQRIGHT,&DOW_warningReqRight_value,(uint8)sizeof(DOW_warningReqRight_value));
	(*data) = DOW_warningReqRight_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQRIGHT,&DOW_warningReqRight_value,(uint8)sizeof(DOW_warningReqRight_value));
	(*data) = DOW_warningReqRight_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQRIGHT,&DOW_warningReqRight_value,(uint8)sizeof(DOW_warningReqRight_value));
	(*data) = DOW_warningReqRight_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQRIGHT,&DOW_warningReqRight_value,(uint8)sizeof(DOW_warningReqRight_value));
	(*data) = DOW_warningReqRight_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_DOW_warningReqleft(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 DOW_warningReqleft_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_DOW_warningReqleft_DOW_warningReqleft
	ret = Rte_Read_DOW_warningReqleft_DOW_warningReqleft(&DOW_warningReqleft_value);
	(*data) = DOW_warningReqleft_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT,&DOW_warningReqleft_value,(uint8)sizeof(DOW_warningReqleft_value));
	(*data) = DOW_warningReqleft_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT,&DOW_warningReqleft_value,(uint8)sizeof(DOW_warningReqleft_value));
	(*data) = DOW_warningReqleft_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT,&DOW_warningReqleft_value,(uint8)sizeof(DOW_warningReqleft_value));
	(*data) = DOW_warningReqleft_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT,&DOW_warningReqleft_value,(uint8)sizeof(DOW_warningReqleft_value));
	(*data) = DOW_warningReqleft_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT,&DOW_warningReqleft_value,(uint8)sizeof(DOW_warningReqleft_value));
	(*data) = DOW_warningReqleft_value;
	return ret;
		
#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT,&DOW_warningReqleft_value,(uint8)sizeof(DOW_warningReqleft_value));
	(*data) = DOW_warningReqleft_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT,&DOW_warningReqleft_value,(uint8)sizeof(DOW_warningReqleft_value));
	(*data) = DOW_warningReqleft_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT,&DOW_warningReqleft_value,(uint8)sizeof(DOW_warningReqleft_value));
	(*data) = DOW_warningReqleft_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT,&DOW_warningReqleft_value,(uint8)sizeof(DOW_warningReqleft_value));
	(*data) = DOW_warningReqleft_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_DrvDoorSts(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 DrvDoorSts_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_DrvDoorSts_DrvDoorSts
	ret = Rte_Read_DrvDoorSts_DrvDoorSts(&DrvDoorSts_value);
	(*data) = DrvDoorSts_value;
 	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS,&DrvDoorSts_value,(uint8)sizeof(DrvDoorSts_value));
	(*data) = DrvDoorSts_value;
 	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS,&DrvDoorSts_value,(uint8)sizeof(DrvDoorSts_value));
	(*data) = DrvDoorSts_value;
 	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS,&DrvDoorSts_value,(uint8)sizeof(DrvDoorSts_value));
	(*data) = DrvDoorSts_value;
 	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS,&DrvDoorSts_value,(uint8)sizeof(DrvDoorSts_value));
	(*data) = DrvDoorSts_value;
 	return ret;
	
#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS,&DrvDoorSts_value,(uint8)sizeof(DrvDoorSts_value));
	(*data) = DrvDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS,&DrvDoorSts_value,(uint8)sizeof(DrvDoorSts_value));
	(*data) = DrvDoorSts_value;
 	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS,&DrvDoorSts_value,(uint8)sizeof(DrvDoorSts_value));
	(*data) = DrvDoorSts_value;
 	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS,&DrvDoorSts_value,(uint8)sizeof(DrvDoorSts_value));
	(*data) = DrvDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS,&DrvDoorSts_value,(uint8)sizeof(DrvDoorSts_value));
	(*data) = DrvDoorSts_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_PassengerDoorSts(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 PassengerDoorSts_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_PassengerDoorSts_PassengerDoorSts
	ret = Rte_Read_PassengerDoorSts_PassengerDoorSts(&PassengerDoorSts_value);
	(*data) = PassengerDoorSts_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS,&PassengerDoorSts_value,(uint8)sizeof(PassengerDoorSts_value));
	(*data) = PassengerDoorSts_value;
	return ret;
		
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS,&PassengerDoorSts_value,(uint8)sizeof(PassengerDoorSts_value));
	(*data) = PassengerDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS,&PassengerDoorSts_value,(uint8)sizeof(PassengerDoorSts_value));
	(*data) = PassengerDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS,&PassengerDoorSts_value,(uint8)sizeof(PassengerDoorSts_value));
	(*data) = PassengerDoorSts_value;
	return ret;
#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS,&PassengerDoorSts_value,(uint8)sizeof(PassengerDoorSts_value));
	(*data) = PassengerDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS,&PassengerDoorSts_value,(uint8)sizeof(PassengerDoorSts_value));
	(*data) = PassengerDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS,&PassengerDoorSts_value,(uint8)sizeof(PassengerDoorSts_value));
	(*data) = PassengerDoorSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS,&PassengerDoorSts_value,(uint8)sizeof(PassengerDoorSts_value));
	(*data) = PassengerDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS,&PassengerDoorSts_value,(uint8)sizeof(PassengerDoorSts_value));
	(*data) = PassengerDoorSts_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_LRDoorSts(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 LRDoorSts_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_LRDoorSts_LRDoorSts
	ret = Rte_Read_LRDoorSts_LRDoorSts(&LRDoorSts_value);
	(*data) = LRDoorSts_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS,&LRDoorSts_value,(uint8)sizeof(LRDoorSts_value));
	(*data) = LRDoorSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS,&LRDoorSts_value,(uint8)sizeof(LRDoorSts_value));
	(*data) = LRDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS,&LRDoorSts_value,(uint8)sizeof(LRDoorSts_value));
	(*data) = LRDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS,&LRDoorSts_value,(uint8)sizeof(LRDoorSts_value));
	(*data) = LRDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS,&LRDoorSts_value,(uint8)sizeof(LRDoorSts_value));
	(*data) = LRDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS,&LRDoorSts_value,(uint8)sizeof(LRDoorSts_value));
	(*data) = LRDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS,&LRDoorSts_value,(uint8)sizeof(LRDoorSts_value));
	(*data) = LRDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS,&LRDoorSts_value,(uint8)sizeof(LRDoorSts_value));
	(*data) = LRDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS,&LRDoorSts_value,(uint8)sizeof(LRDoorSts_value));
	(*data) = LRDoorSts_value;
	return ret;	

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_RRDoorSts(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 RRDoorSts_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_RRDoorSts_RRDoorSts
	ret = Rte_Read_RRDoorSts_RRDoorSts(&RRDoorSts_value);
	(*data) = RRDoorSts_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS,&RRDoorSts_value,(uint8)sizeof(RRDoorSts_value));
	(*data) = RRDoorSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS,&RRDoorSts_value,(uint8)sizeof(RRDoorSts_value));
	(*data) = RRDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS,&RRDoorSts_value,(uint8)sizeof(RRDoorSts_value));
	(*data) = RRDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS,&RRDoorSts_value,(uint8)sizeof(RRDoorSts_value));
	(*data) = RRDoorSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS,&RRDoorSts_value,(uint8)sizeof(RRDoorSts_value));
	(*data) = RRDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS,&RRDoorSts_value,(uint8)sizeof(RRDoorSts_value));
	(*data) = RRDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS,&RRDoorSts_value,(uint8)sizeof(RRDoorSts_value));
	(*data) = RRDoorSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS,&RRDoorSts_value,(uint8)sizeof(RRDoorSts_value));
	(*data) = RRDoorSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS,&RRDoorSts_value,(uint8)sizeof(RRDoorSts_value));
	(*data) = RRDoorSts_value;
	return ret;	

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_LSSIntervention(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 LSSIntervention_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2
	SG_IFC4_IFC_FD2 msg;
	ret = Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(&msg);
	*data = msg.LSSIntervention;
	return ret;
#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSINTERVENTION,&LSSIntervention_value,(uint8)sizeof(LSSIntervention_value));
	(*data) = LSSIntervention_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSINTERVENTION,&LSSIntervention_value,(uint8)sizeof(LSSIntervention_value));
	(*data) = LSSIntervention_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSINTERVENTION,&LSSIntervention_value,(uint8)sizeof(LSSIntervention_value));
	(*data) = LSSIntervention_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSINTERVENTION,&LSSIntervention_value,(uint8)sizeof(LSSIntervention_value));
	(*data) = LSSIntervention_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSINTERVENTION,&LSSIntervention_value,(uint8)sizeof(LSSIntervention_value));
	(*data) = LSSIntervention_value;
	return ret;
		
#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSINTERVENTION,&LSSIntervention_value,(uint8)sizeof(LSSIntervention_value));
	(*data) = LSSIntervention_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSINTERVENTION,&LSSIntervention_value,(uint8)sizeof(LSSIntervention_value));
	(*data) = LSSIntervention_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSINTERVENTION,&LSSIntervention_value,(uint8)sizeof(LSSIntervention_value));
	(*data) = LSSIntervention_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSINTERVENTION,&LSSIntervention_value,(uint8)sizeof(LSSIntervention_value));
	(*data) = LSSIntervention_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_CDPActv_0x137(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 CDPActv_0x137_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2
	SG_ESP2_ESP_FD2 msg;
	ret = Rte_Read_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2(&msg);
	*data = (uint8)msg.CDPActv_0x137;
	return ret;
#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV,&CDPActv_0x137_value,(uint8)sizeof(CDPActv_0x137_value));
	(*data) = CDPActv_0x137_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV_0X137,&CDPActv_0x137_value,(uint8)sizeof(CDPActv_0x137_value));
	(*data) = CDPActv_0x137_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV,&CDPActv_0x137_value,(uint8)sizeof(CDPActv_0x137_value));
	(*data) = CDPActv_0x137_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1)
	// ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV_0X137,&CDPActv_0x137_value,(uint8)sizeof(CDPActv_0x137_value));
	(*data) = CDPActv_0x137_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV,&CDPActv_0x137_value,(uint8)sizeof(CDPActv_0x137_value));
	(*data) = CDPActv_0x137_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV,&CDPActv_0x137_value,(uint8)sizeof(CDPActv_0x137_value));
	(*data) = CDPActv_0x137_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV,&CDPActv_0x137_value,(uint8)sizeof(CDPActv_0x137_value));
	(*data) = CDPActv_0x137_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV,&CDPActv_0x137_value,(uint8)sizeof(CDPActv_0x137_value));
	(*data) = CDPActv_0x137_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV,&CDPActv_0x137_value,(uint8)sizeof(CDPActv_0x137_value));
	(*data) = CDPActv_0x137_value;
	return ret;	

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_CDPActv_0x145(uint8 *data)
{
	

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_SG_ESP2_SG_ESP2
	ChimeMessageType ret = 0U;	
	uint8 CDPActv_0x145_value = 0;
	SG_ESP2 msg;
	ret = Rte_Read_SG_ESP2_SG_ESP2(&msg);
	*data = (uint8)msg.CDPActv_0x145;
	return ret;
#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	return RTE_E_INVALID;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ChimeMessageType ret = 0U;	
	uint8 CDPActv_0x145_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV_0X145,&CDPActv_0x145_value,(uint8)sizeof(CDPActv_0x145_value));
	(*data) = CDPActv_0x145_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ChimeMessageType ret = 0U;	
	uint8 CDPActv_0x145_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV,&CDPActv_0x145_value,(uint8)sizeof(CDPActv_0x145_value));
	(*data) = CDPActv_0x145_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D01 == 1)
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_D02 == 1)
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_D03 == 1)
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P02 == 1)
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ChimeMessageType ret = 0U;	
	uint8 CDPActv_0x145_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV,&CDPActv_0x145_value,(uint8)sizeof(CDPActv_0x145_value));
	(*data) = CDPActv_0x145_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_LTurnLmpSts_R_Pbox(uint8 *data)
{
	ChimeMessageType ret = 0U;	
	uint8 LTurnLmpSts_R_Pbox_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_LTurnLmpSts_R_Pbox_LTurnLmpSts_R_Pbox
	ret = Rte_Read_LTurnLmpSts_R_Pbox_LTurnLmpSts_R_Pbox(&LTurnLmpSts_R_Pbox_value);
	(*data) = LTurnLmpSts_R_Pbox_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LTURNLMPSTS_R_PBOX,&LTurnLmpSts_R_Pbox_value,(uint8)sizeof(LTurnLmpSts_R_Pbox_value));
	(*data) = LTurnLmpSts_R_Pbox_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LTURNLMPSTS_R_PBOX,&LTurnLmpSts_R_Pbox_value,(uint8)sizeof(LTurnLmpSts_R_Pbox_value));
	(*data) = LTurnLmpSts_R_Pbox_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LTURNLMPSTS_R_PBOX,&LTurnLmpSts_R_Pbox_value,(uint8)sizeof(LTurnLmpSts_R_Pbox_value));
	(*data) = LTurnLmpSts_R_Pbox_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LTURNLMPSTS_R_PBOX,&LTurnLmpSts_R_Pbox_value,(uint8)sizeof(LTurnLmpSts_R_Pbox_value));
	(*data) = LTurnLmpSts_R_Pbox_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LTURNLMPSTS_R_PBOX,&LTurnLmpSts_R_Pbox_value,(uint8)sizeof(LTurnLmpSts_R_Pbox_value));
	(*data) = LTurnLmpSts_R_Pbox_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LTURNLMPSTS_R_PBOX,&LTurnLmpSts_R_Pbox_value,(uint8)sizeof(LTurnLmpSts_R_Pbox_value));
	(*data) = LTurnLmpSts_R_Pbox_value;
	return ret;
		
#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LTURNLMPSTS_R_PBOX,&LTurnLmpSts_R_Pbox_value,(uint8)sizeof(LTurnLmpSts_R_Pbox_value));
	(*data) = LTurnLmpSts_R_Pbox_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LTURNLMPSTS_R_PBOX,&LTurnLmpSts_R_Pbox_value,(uint8)sizeof(LTurnLmpSts_R_Pbox_value));
	(*data) = LTurnLmpSts_R_Pbox_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LTURNLMPSTS_R_PBOX,&LTurnLmpSts_R_Pbox_value,(uint8)sizeof(LTurnLmpSts_R_Pbox_value));
	(*data) = LTurnLmpSts_R_Pbox_value;
	return ret;	

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_RTurnLmpSts_R_Pbox(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 RTurnLmpSts_R_Pbox_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_RTurnLmpSts_R_Pbox_RTurnLmpSts_R_Pbox
	ret = Rte_Read_RTurnLmpSts_R_Pbox_RTurnLmpSts_R_Pbox(&RTurnLmpSts_R_Pbox_value);
	(*data) = RTurnLmpSts_R_Pbox_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RTURNLMPSTS_R_PBOX,&RTurnLmpSts_R_Pbox_value,(uint8)sizeof(RTurnLmpSts_R_Pbox_value));
	(*data) = RTurnLmpSts_R_Pbox_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RTURNLMPSTS_R_PBOX,&RTurnLmpSts_R_Pbox_value,(uint8)sizeof(RTurnLmpSts_R_Pbox_value));
	(*data) = RTurnLmpSts_R_Pbox_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RTURNLMPSTS_R_PBOX,&RTurnLmpSts_R_Pbox_value,(uint8)sizeof(RTurnLmpSts_R_Pbox_value));
	(*data) = RTurnLmpSts_R_Pbox_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RTURNLMPSTS_R_PBOX,&RTurnLmpSts_R_Pbox_value,(uint8)sizeof(RTurnLmpSts_R_Pbox_value));
	(*data) = RTurnLmpSts_R_Pbox_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RTURNLMPSTS_R_PBOX,&RTurnLmpSts_R_Pbox_value,(uint8)sizeof(RTurnLmpSts_R_Pbox_value));
	(*data) = RTurnLmpSts_R_Pbox_value;
	return ret;
		
#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RTURNLMPSTS_R_PBOX,&RTurnLmpSts_R_Pbox_value,(uint8)sizeof(RTurnLmpSts_R_Pbox_value));
	(*data) = RTurnLmpSts_R_Pbox_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RTURNLMPSTS_R_PBOX,&RTurnLmpSts_R_Pbox_value,(uint8)sizeof(RTurnLmpSts_R_Pbox_value));
	(*data) = RTurnLmpSts_R_Pbox_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RTURNLMPSTS_R_PBOX,&RTurnLmpSts_R_Pbox_value,(uint8)sizeof(RTurnLmpSts_R_Pbox_value));
	(*data) = RTurnLmpSts_R_Pbox_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RTURNLMPSTS_R_PBOX,&RTurnLmpSts_R_Pbox_value,(uint8)sizeof(RTurnLmpSts_R_Pbox_value));
	(*data) = RTurnLmpSts_R_Pbox_value;
	return ret;	

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_TSRSts(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 TSRSts_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1) 

#ifdef Rte_Read_TSRSts_TSRSts
	ret = Rte_Read_TSRSts_TSRSts(&TSRSts_value);
	(*data) = TSRSts_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS,&TSRSts_value,(uint8)sizeof(TSRSts_value));
	(*data) = TSRSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS,&TSRSts_value,(uint8)sizeof(TSRSts_value));
	(*data) = TSRSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS,&TSRSts_value,(uint8)sizeof(TSRSts_value));
	(*data) = TSRSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS,&TSRSts_value,(uint8)sizeof(TSRSts_value));
	(*data) = TSRSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS,&TSRSts_value,(uint8)sizeof(TSRSts_value));
	(*data) = TSRSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS,&TSRSts_value,(uint8)sizeof(TSRSts_value));
	(*data) = TSRSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS,&TSRSts_value,(uint8)sizeof(TSRSts_value));
	(*data) = TSRSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS,&TSRSts_value,(uint8)sizeof(TSRSts_value));
	(*data) = TSRSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS,&TSRSts_value,(uint8)sizeof(TSRSts_value));
	(*data) = TSRSts_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_TSRSpdLimSts(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 TSRSpdLimSts_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_TSRSpdLimSts_TSRSpdLimSts
	ret = Rte_Read_TSRSpdLimSts_TSRSpdLimSts(&TSRSpdLimSts_value);
	(*data) = TSRSpdLimSts_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMSTS,&TSRSpdLimSts_value,(uint8)sizeof(TSRSpdLimSts_value));
	(*data) = TSRSpdLimSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMSTS,&TSRSpdLimSts_value,(uint8)sizeof(TSRSpdLimSts_value));
	(*data) = TSRSpdLimSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMSTS,&TSRSpdLimSts_value,(uint8)sizeof(TSRSpdLimSts_value));
	(*data) = TSRSpdLimSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMSTS,&TSRSpdLimSts_value,(uint8)sizeof(TSRSpdLimSts_value));
	(*data) = TSRSpdLimSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMSTS,&TSRSpdLimSts_value,(uint8)sizeof(TSRSpdLimSts_value));
	(*data) = TSRSpdLimSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMSTS,&TSRSpdLimSts_value,(uint8)sizeof(TSRSpdLimSts_value));
	(*data) = TSRSpdLimSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMSTS,&TSRSpdLimSts_value,(uint8)sizeof(TSRSpdLimSts_value));
	(*data) = TSRSpdLimSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMSTS,&TSRSpdLimSts_value,(uint8)sizeof(TSRSpdLimSts_value));
	(*data) = TSRSpdLimSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMSTS,&TSRSpdLimSts_value,(uint8)sizeof(TSRSpdLimSts_value));
	(*data) = TSRSpdLimSts_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_TSRSpdLim(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 TSRSpdLim_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_TSRSpdLim_TSRSpdLim
	ret = Rte_Read_TSRSpdLim_TSRSpdLim(&TSRSpdLim_value);
	(*data) = TSRSpdLim_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIM,&TSRSpdLim_value,(uint8)sizeof(TSRSpdLim_value));
	(*data) = TSRSpdLim_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIM,&TSRSpdLim_value,(uint8)sizeof(TSRSpdLim_value));
	(*data) = TSRSpdLim_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIM,&TSRSpdLim_value,(uint8)sizeof(TSRSpdLim_value));
	(*data) = TSRSpdLim_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIM,&TSRSpdLim_value,(uint8)sizeof(TSRSpdLim_value));
	(*data) = TSRSpdLim_value;
	return ret;
#elif (CHIME_PROJECT_TYPE_D01 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIM,&TSRSpdLim_value,(uint8)sizeof(TSRSpdLim_value));
	(*data) = TSRSpdLim_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIM,&TSRSpdLim_value,(uint8)sizeof(TSRSpdLim_value));
	(*data) = TSRSpdLim_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIM,&TSRSpdLim_value,(uint8)sizeof(TSRSpdLim_value));
	(*data) = TSRSpdLim_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIM,&TSRSpdLim_value,(uint8)sizeof(TSRSpdLim_value));
	(*data) = TSRSpdLim_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P01 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIM,&TSRSpdLim_value,(uint8)sizeof(TSRSpdLim_value));
	(*data) = TSRSpdLim_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_TSRSpdLimWarn(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 TSRSpdLimWarn_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_TSRSpdLimWarn_TSRSpdLimWarn
	ret = Rte_Read_TSRSpdLimWarn_TSRSpdLimWarn(&TSRSpdLimWarn_value);
	(*data) = TSRSpdLimWarn_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMWARN,&TSRSpdLimWarn_value,(uint8)sizeof(TSRSpdLimWarn_value));
	(*data) = TSRSpdLimWarn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMWARN,&TSRSpdLimWarn_value,(uint8)sizeof(TSRSpdLimWarn_value));
	(*data) = TSRSpdLimWarn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMWARN,&TSRSpdLimWarn_value,(uint8)sizeof(TSRSpdLimWarn_value));
	(*data) = TSRSpdLimWarn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMWARN,&TSRSpdLimWarn_value,(uint8)sizeof(TSRSpdLimWarn_value));
	(*data) = TSRSpdLimWarn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMWARN,&TSRSpdLimWarn_value,(uint8)sizeof(TSRSpdLimWarn_value));
	(*data) = TSRSpdLimWarn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMWARN,&TSRSpdLimWarn_value,(uint8)sizeof(TSRSpdLimWarn_value));
	(*data) = TSRSpdLimWarn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMWARN,&TSRSpdLimWarn_value,(uint8)sizeof(TSRSpdLimWarn_value));
	(*data) = TSRSpdLimWarn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMWARN,&TSRSpdLimWarn_value,(uint8)sizeof(TSRSpdLimWarn_value));
	(*data) = TSRSpdLimWarn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMWARN,&TSRSpdLimWarn_value,(uint8)sizeof(TSRSpdLimWarn_value));
	(*data) = TSRSpdLimWarn_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_FrntELDLckSts(uint8 *data)
{
	

#if(CHIME_PROJECT_TYPE_B03 == 1) 

#ifdef Rte_Read_FrntELDLckSts_FrntELDLckSts
	ChimeMessageType ret = 0U;
	uint8 FrntELDLckSts_value = 0;
	ret = Rte_Read_FrntELDLckSts_FrntELDLckSts(&FrntELDLckSts_value);
	(*data) = FrntELDLckSts_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	return RTE_E_INVALID_SIGNAL_DIFPROJET;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ChimeMessageType ret = 0U;
	uint8 FrntELDLckSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRNTELDLCKSTS,&FrntELDLckSts_value,(uint8)sizeof(FrntELDLckSts_value));
	(*data) = FrntELDLckSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ChimeMessageType ret = 0U;
	uint8 FrntELDLckSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRNTELDLCKSTS,&FrntELDLckSts_value,(uint8)sizeof(FrntELDLckSts_value));
	(*data) = FrntELDLckSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	(*data) = 0;
	return RTE_E_INVALID_SIGNAL_DIFPROJET;

#elif (CHIME_PROJECT_TYPE_D01 == 1)
	ChimeMessageType ret = 0U;
	uint8 FrntELDLckSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRNTELDLCKSTS,&FrntELDLckSts_value,(uint8)sizeof(FrntELDLckSts_value));
	(*data) = FrntELDLckSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1)
	ChimeMessageType ret = 0U;
	uint8 FrntELDLckSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRNTELDLCKSTS,&FrntELDLckSts_value,(uint8)sizeof(FrntELDLckSts_value));
	(*data) = FrntELDLckSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1)
	ChimeMessageType ret = 0U;
	uint8 FrntELDLckSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRNTELDLCKSTS,&FrntELDLckSts_value,(uint8)sizeof(FrntELDLckSts_value));
	(*data) = FrntELDLckSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1)
	ChimeMessageType ret = 0U;
	uint8 FrntELDLckSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRNTELDLCKSTS,&FrntELDLckSts_value,(uint8)sizeof(FrntELDLckSts_value));
	(*data) = FrntELDLckSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	ChimeMessageType ret = 0U;
	uint8 FrntELDLckSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRNTELDLCKSTS,&FrntELDLckSts_value,(uint8)sizeof(FrntELDLckSts_value));
	(*data) = FrntELDLckSts_value;
	return ret;

#else
	ret  = RTE_E_INVALID;
	return ret;
#endif
}
ChimeMessageType Chime_GetMessage_RearELDLckSts(uint8 *data)
{
	

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_RearELDLckSts_RearELDLckSts
	ChimeMessageType ret = 0U;
	uint8 RearELDLckSts_value = 0;
	ret = Rte_Read_RearELDLckSts_RearELDLckSts(&RearELDLckSts_value);
	(*data) = RearELDLckSts_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	return RTE_E_INVALID_SIGNAL_DIFPROJET;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ChimeMessageType ret = 0U;
	uint8 RearELDLckSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARELDLCKSTS,&RearELDLckSts_value,(uint8)sizeof(RearELDLckSts_value));
	(*data) = RearELDLckSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ChimeMessageType ret = 0U;
	uint8 RearELDLckSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARELDLCKSTS,&RearELDLckSts_value,(uint8)sizeof(RearELDLckSts_value));
	(*data) = RearELDLckSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	(*data) = 0;
	return RTE_E_INVALID_SIGNAL_DIFPROJET;

//DBC miss signal
#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ChimeMessageType ret = 0U;
	uint8 RearELDLckSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARELDLCKSTS,&RearELDLckSts_value,(uint8)sizeof(RearELDLckSts_value));
	(*data) = RearELDLckSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ChimeMessageType ret = 0U;
	uint8 RearELDLckSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARELDLCKSTS,&RearELDLckSts_value,(uint8)sizeof(RearELDLckSts_value));
	(*data) = RearELDLckSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ChimeMessageType ret = 0U;
	uint8 RearELDLckSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARELDLCKSTS,&RearELDLckSts_value,(uint8)sizeof(RearELDLckSts_value));
	(*data) = RearELDLckSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P02 == 1)
	ChimeMessageType ret = 0U;
	uint8 RearELDLckSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARELDLCKSTS,&RearELDLckSts_value,(uint8)sizeof(RearELDLckSts_value));
	(*data) = RearELDLckSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	ChimeMessageType ret = 0U;
	uint8 RearELDLckSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARELDLCKSTS,&RearELDLckSts_value,(uint8)sizeof(RearELDLckSts_value));
	(*data) = RearELDLckSts_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_TGS_LEVER(uint8 *data)
{
	

#if(CHIME_PROJECT_TYPE_B03 == 1)

	//#ifdef Rte_Read_TGS_LEVER_TGS_LEVER
	//ret = Rte_Read_TGS_LEVER_TGS_LEVER(&TGS_LEVER_value);
	//(*data) = TGS_LEVER_value;
	return RTE_E_INVALID;

	//#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	return RTE_E_INVALID;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ChimeMessageType ret = 0U;
	uint8 TGS_LEVER_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGS_LEVER,&TGS_LEVER_value,(uint8)sizeof(TGS_LEVER_value));
	(*data) = TGS_LEVER_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_D01 == 1)
	ChimeMessageType ret = 0U;
	uint8 TGS_LEVER_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGS_LEVER,&TGS_LEVER_value,(uint8)sizeof(TGS_LEVER_value));
	(*data) = TGS_LEVER_value;
	return ret;
		
#elif (CHIME_PROJECT_TYPE_D02 == 1)
	ChimeMessageType ret = 0U;
	uint8 TGS_LEVER_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGS_LEVER,&TGS_LEVER_value,(uint8)sizeof(TGS_LEVER_value));
	(*data) = TGS_LEVER_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D03 == 1)
	ChimeMessageType ret = 0U;
	uint8 TGS_LEVER_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGS_LEVER,&TGS_LEVER_value,(uint8)sizeof(TGS_LEVER_value));
	(*data) = TGS_LEVER_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1)
	ChimeMessageType ret = 0U;
	uint8 TGS_LEVER_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGS_LEVER,&TGS_LEVER_value,(uint8)sizeof(TGS_LEVER_value));
	(*data) = TGS_LEVER_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	ChimeMessageType ret = 0U;
	uint8 TGS_LEVER_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGS_LEVER,&TGS_LEVER_value,(uint8)sizeof(TGS_LEVER_value));
	(*data) = TGS_LEVER_value;
	return ret;
	
#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_HCU_RdyLmpSts(uint8 *data)
{
	

#if(CHIME_PROJECT_TYPE_B03 == 1) 

#ifdef Rte_Read_SG_HCU_PT7_SG_HCU_PT7
	ChimeMessageType ret = 0U;
	uint8 HCU_RdyLmpSts_value = 0;
	SG_HCU_PT7 msg;
	ret = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&msg);
	*data = (uint8)msg.HCU_RdyLmpSts;
	return ret;
#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ChimeMessageType ret = 0U;
	uint8 HCU_RdyLmpSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_value,(uint8)sizeof(HCU_RdyLmpSts_value));
	(*data) = HCU_RdyLmpSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1)
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ChimeMessageType ret = 0U;
	uint8 HCU_RdyLmpSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_value,(uint8)sizeof(HCU_RdyLmpSts_value));
	(*data) = HCU_RdyLmpSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ChimeMessageType ret = 0U;
	uint8 HCU_RdyLmpSts_value = 0;
	// ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_value,(uint8)sizeof(HCU_RdyLmpSts_value));
	(*data) = HCU_RdyLmpSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ChimeMessageType ret = 0U;
	uint8 HCU_RdyLmpSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_value,(uint8)sizeof(HCU_RdyLmpSts_value));
	(*data) = HCU_RdyLmpSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ChimeMessageType ret = 0U;
	uint8 HCU_RdyLmpSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_value,(uint8)sizeof(HCU_RdyLmpSts_value));
	(*data) = HCU_RdyLmpSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ChimeMessageType ret = 0U;
	uint8 HCU_RdyLmpSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_value,(uint8)sizeof(HCU_RdyLmpSts_value));
	(*data) = HCU_RdyLmpSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ChimeMessageType ret = 0U;
	uint8 HCU_RdyLmpSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_value,(uint8)sizeof(HCU_RdyLmpSts_value));
	(*data) = HCU_RdyLmpSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ChimeMessageType ret = 0U;
	uint8 HCU_RdyLmpSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_value,(uint8)sizeof(HCU_RdyLmpSts_value));
	(*data) = HCU_RdyLmpSts_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_DrvModDisp_0x201(uint8 *data)
{
	

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_SG_HCU_HP5_SG_HCU_HP5
	ChimeMessageType ret = 0U;
	uint8 DrvModDisp_0x201_Value = 0;
	SG_HCU_HP5 msg;
	ret = Rte_Read_SG_HCU_HP5_SG_HCU_HP5(&msg);
	*data = msg.DrvModDisp_0x201;
	return ret;
#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ChimeMessageType ret = 0U;
	uint8 DrvModDisp_0x201_Value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISP_0X201,&DrvModDisp_0x201_Value,(uint8)sizeof(DrvModDisp_0x201_Value));
	(*data) = DrvModDisp_0x201_Value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ChimeMessageType ret = 0U;
	uint8 DrvModDisp_0x201_Value = 0;
    ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISP,&DrvModDisp_0x201_Value,(uint8)sizeof(DrvModDisp_0x201_Value));
    (*data) = DrvModDisp_0x201_Value;
    return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1)
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_D02 == 1)
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_D03 == 1)
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P02 == 1)
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ChimeMessageType ret = 0U;
	uint8 DrvModDisp_0x201_Value = 0;
    ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISP,&DrvModDisp_0x201_Value,(uint8)sizeof(DrvModDisp_0x201_Value));
    (*data) = DrvModDisp_0x201_Value;
    return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_HWA_ModDisp(uint8 *data)
{
	

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2
	ChimeMessageType ret = 0U;
	uint8 HWA_ModDisp_value = 0;
	SG_ACC8_ACC_FD2 msg;
	ret = Rte_Read_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2(&msg);
	*data = msg.HWA_ModDisp;
	return ret;
#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ChimeMessageType ret = 0U;
	uint8 HWA_ModDisp_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_MODDISP,&HWA_ModDisp_value,(uint8)sizeof(HWA_ModDisp_value));
	(*data) = HWA_ModDisp_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ChimeMessageType ret = 0U;
	uint8 HWA_ModDisp_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_MODDISP,&HWA_ModDisp_value,(uint8)sizeof(HWA_ModDisp_value));
	(*data) = HWA_ModDisp_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ChimeMessageType ret = 0U;
	uint8 HWA_ModDisp_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_MODDISP,&HWA_ModDisp_value,(uint8)sizeof(HWA_ModDisp_value));
	(*data) = HWA_ModDisp_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_D01 == 1)
	ChimeMessageType ret = 0U;
	uint8 HWA_ModDisp_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_MODDISP,&HWA_ModDisp_value,(uint8)sizeof(HWA_ModDisp_value));
	(*data) = HWA_ModDisp_value;
	return ret;
		
#elif (CHIME_PROJECT_TYPE_D02 == 1)
	ChimeMessageType ret = 0U;
	uint8 HWA_ModDisp_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_MODDISP,&HWA_ModDisp_value,(uint8)sizeof(HWA_ModDisp_value));
	(*data) = HWA_ModDisp_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D03 == 1)
	ChimeMessageType ret = 0U;
	uint8 HWA_ModDisp_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_MODDISP,&HWA_ModDisp_value,(uint8)sizeof(HWA_ModDisp_value));
	(*data) = HWA_ModDisp_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1)
	ChimeMessageType ret = 0U;
	uint8 HWA_ModDisp_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_MODDISP,&HWA_ModDisp_value,(uint8)sizeof(HWA_ModDisp_value));
	(*data) = HWA_ModDisp_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	ChimeMessageType ret = 0U;
	uint8 HWA_ModDisp_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_MODDISP,&HWA_ModDisp_value,(uint8)sizeof(HWA_ModDisp_value));
	(*data) = HWA_ModDisp_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_OBC_ConnectSts(uint8 *data)
{
	

#if(CHIME_PROJECT_TYPE_B03 == 1) 

#ifdef Rte_Read_OBC_ConnectSts_OBC_ConnectSts
	ChimeMessageType ret = 0U;
	uint8 OBC_ConnectSts_value = 0;
	ret = Rte_Read_OBC_ConnectSts_OBC_ConnectSts(&OBC_ConnectSts_value);
	(*data) = OBC_ConnectSts_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ChimeMessageType ret = 0U;
	uint8 OBC_ConnectSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_CONNECTSTS,&OBC_ConnectSts_value,(uint8)sizeof(OBC_ConnectSts_value));
	(*data) = OBC_ConnectSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ChimeMessageType ret = 0U;
	uint8 OBC_ConnectSts_value = 0;
	//ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_CONNECTSTS,&OBC_ConnectSts_value,(uint8)sizeof(OBC_ConnectSts_value));
	(*data) = OBC_ConnectSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1)
	ChimeMessageType ret = 0U;
	uint8 OBC_ConnectSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_CONNECTSTS,&OBC_ConnectSts_value,(uint8)sizeof(OBC_ConnectSts_value));
	(*data) = OBC_ConnectSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1)
	ChimeMessageType ret = 0U;
	uint8 OBC_ConnectSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_CONNECTSTS,&OBC_ConnectSts_value,(uint8)sizeof(OBC_ConnectSts_value));
	(*data) = OBC_ConnectSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1)
	ChimeMessageType ret = 0U;
	uint8 OBC_ConnectSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_CONNECTSTS,&OBC_ConnectSts_value,(uint8)sizeof(OBC_ConnectSts_value));
	(*data) = OBC_ConnectSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1)
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	ChimeMessageType ret = 0U;
	uint8 OBC_ConnectSts_value = 0;
	//ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_CONNECTSTS,&OBC_ConnectSts_value,(uint8)sizeof(OBC_ConnectSts_value));
	(*data) = OBC_ConnectSts_value;
	return ret;
		
#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_HCU_ChargSts(uint8 *data)
{
	

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_HCU_ChargSts_HCU_ChargSts
	ChimeMessageType ret = 0U;
	uint8 HCU_ChargSts_value = 0;
	ret = Rte_Read_HCU_ChargSts_HCU_ChargSts(&HCU_ChargSts_value);
	(*data) = HCU_ChargSts_value;
	return ret;

#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ChimeMessageType ret = 0U;
	uint8 HCU_ChargSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS,&HCU_ChargSts_value,(uint8)sizeof(HCU_ChargSts_value));
	(*data) = HCU_ChargSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ChimeMessageType ret = 0U;
	uint8 HCU_ChargSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS,&HCU_ChargSts_value,(uint8)sizeof(HCU_ChargSts_value));
	(*data) = HCU_ChargSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ChimeMessageType ret = 0U;
	uint8 HCU_ChargSts_value = 0;
	//ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS,&HCU_ChargSts_value,(uint8)sizeof(HCU_ChargSts_value));
	(*data) = HCU_ChargSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1)
	ChimeMessageType ret = 0U;
	uint8 HCU_ChargSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS,&HCU_ChargSts_value,(uint8)sizeof(HCU_ChargSts_value));
	(*data) = HCU_ChargSts_value;
	return ret;
		
#elif (CHIME_PROJECT_TYPE_D02 == 1)
	ChimeMessageType ret = 0U;
	uint8 HCU_ChargSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS,&HCU_ChargSts_value,(uint8)sizeof(HCU_ChargSts_value));
	(*data) = HCU_ChargSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D03 == 1)
	ChimeMessageType ret = 0U;
	uint8 HCU_ChargSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS,&HCU_ChargSts_value,(uint8)sizeof(HCU_ChargSts_value));
	(*data) = HCU_ChargSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P01 == 1)
	ChimeMessageType ret = 0U;
	uint8 HCU_ChargSts_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS,&HCU_ChargSts_value,(uint8)sizeof(HCU_ChargSts_value));
	(*data) = HCU_ChargSts_value;
	return ret;
	
#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_LCKStsIndcr(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 lckStsIndcr_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2
	SG_IFC4_IFC_FD2 msg;
	ret = Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(&msg);
	*data = msg.LCKStsIndcr;
	return ret;
#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LCKSTSINDCR,&lckStsIndcr_value,(uint8)sizeof(lckStsIndcr_value));
	(*data) = lckStsIndcr_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LCKSTSINDCR,&lckStsIndcr_value,(uint8)sizeof(lckStsIndcr_value));
	(*data) = lckStsIndcr_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LCKSTSINDCR,&lckStsIndcr_value,(uint8)sizeof(lckStsIndcr_value));
	(*data) = lckStsIndcr_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LCKSTSINDCR,&lckStsIndcr_value,(uint8)sizeof(lckStsIndcr_value));
	(*data) = lckStsIndcr_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1) 
		ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LCKSTSINDCR,&lckStsIndcr_value,(uint8)sizeof(lckStsIndcr_value));
		(*data) = lckStsIndcr_value;
		return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LCKSTSINDCR,&lckStsIndcr_value,(uint8)sizeof(lckStsIndcr_value));
	(*data) = lckStsIndcr_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LCKSTSINDCR,&lckStsIndcr_value,(uint8)sizeof(lckStsIndcr_value));
	(*data) = lckStsIndcr_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LCKSTSINDCR,&lckStsIndcr_value,(uint8)sizeof(lckStsIndcr_value));
	(*data) = lckStsIndcr_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LCKSTSINDCR,&lckStsIndcr_value,(uint8)sizeof(lckStsIndcr_value));
	(*data) = lckStsIndcr_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_IntelligentEvaActSts(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 IntelligentEvaActSts_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2
	SG_IFC4_IFC_FD2 msg;
	ret = Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(&msg);
	*data = msg.IntelligentEvaActSts;
	return ret;
#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS,&IntelligentEvaActSts_value,(uint8)sizeof(IntelligentEvaActSts_value));
	(*data) = IntelligentEvaActSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS,&IntelligentEvaActSts_value,(uint8)sizeof(IntelligentEvaActSts_value));
	(*data) = IntelligentEvaActSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS,&IntelligentEvaActSts_value,(uint8)sizeof(IntelligentEvaActSts_value));
	(*data) = IntelligentEvaActSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS,&IntelligentEvaActSts_value,(uint8)sizeof(IntelligentEvaActSts_value));
	(*data) = IntelligentEvaActSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS,&IntelligentEvaActSts_value,(uint8)sizeof(IntelligentEvaActSts_value));
	(*data) = IntelligentEvaActSts_value;
	return ret;
		
#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS,&IntelligentEvaActSts_value,(uint8)sizeof(IntelligentEvaActSts_value));
	(*data) = IntelligentEvaActSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS,&IntelligentEvaActSts_value,(uint8)sizeof(IntelligentEvaActSts_value));
	(*data) = IntelligentEvaActSts_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS,&IntelligentEvaActSts_value,(uint8)sizeof(IntelligentEvaActSts_value));
	(*data) = IntelligentEvaActSts_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS,&IntelligentEvaActSts_value,(uint8)sizeof(IntelligentEvaActSts_value));
	(*data) = IntelligentEvaActSts_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_LDW_LKAWarn(uint8 *data)
{
	ChimeMessageType ret = 0U;
	uint8 LDW_LKAWarn_value = 0;

#if(CHIME_PROJECT_TYPE_B03 == 1)

#ifdef Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2
	SG_IFC4_IFC_FD2 msg;
	ret = Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(&msg);
	*data = msg.LDW_LKAWarn;
	return ret;
#endif

#elif CHIME_PROJECT_TYPE_B02 == 1
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LDW_LKAWARN,&LDW_LKAWarn_value,(uint8)sizeof(LDW_LKAWarn_value));
	(*data) = LDW_LKAWarn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LDW_LKAWARN,&LDW_LKAWarn_value,(uint8)sizeof(LDW_LKAWarn_value));
	(*data) = LDW_LKAWarn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LDW_LKAWARN,&LDW_LKAWarn_value,(uint8)sizeof(LDW_LKAWarn_value));
	(*data) = LDW_LKAWarn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LDW_LKAWARN,&LDW_LKAWarn_value,(uint8)sizeof(LDW_LKAWarn_value));
	(*data) = LDW_LKAWarn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LDW_LKAWARN,&LDW_LKAWarn_value,(uint8)sizeof(LDW_LKAWarn_value));
	(*data) = LDW_LKAWarn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LDW_LKAWARN,&LDW_LKAWarn_value,(uint8)sizeof(LDW_LKAWarn_value));
	(*data) = LDW_LKAWarn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LDW_LKAWARN,&LDW_LKAWarn_value,(uint8)sizeof(LDW_LKAWarn_value));
	(*data) = LDW_LKAWarn_value;
	return ret;
	
#elif (CHIME_PROJECT_TYPE_P02 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LDW_LKAWARN,&LDW_LKAWarn_value,(uint8)sizeof(LDW_LKAWarn_value));
	(*data) = LDW_LKAWarn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P01 == 1) 
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LDW_LKAWARN,&LDW_LKAWarn_value,(uint8)sizeof(LDW_LKAWarn_value));
	(*data) = LDW_LKAWarn_value;
	return ret;

#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetMessage_DWD_SoundIndcn(uint8 *data)
{
	

#if (CHIME_PROJECT_TYPE_B03 == 1)
	(*data) = 0;
	return RTE_E_INVALID;
	
#elif (CHIME_PROJECT_TYPE_B02 == 1)
	(*data) = 0;
	return RTE_E_INVALID;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	ChimeMessageType ret = 0U;
	uint8 DWD_SoundIndcn_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DWD_SOUNDINDCN,&DWD_SoundIndcn_value,(uint8)sizeof(DWD_SoundIndcn_value));
	(*data) = DWD_SoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	ChimeMessageType ret = 0U;
	uint8 DWD_SoundIndcn_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DWD_SOUNDINDCN,&DWD_SoundIndcn_value,(uint8)sizeof(DWD_SoundIndcn_value));
	(*data) = DWD_SoundIndcn_value;
	return ret;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ChimeMessageType ret = 0U;
	uint8 DWD_SoundIndcn_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DWD_SOUNDINDCN,&DWD_SoundIndcn_value,(uint8)sizeof(DWD_SoundIndcn_value));
	(*data) = DWD_SoundIndcn_value;
	return ret;


#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ChimeMessageType ret = 0U;
	uint8 DWD_SoundIndcn_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DWD_SOUNDINDCN,&DWD_SoundIndcn_value,(uint8)sizeof(DWD_SoundIndcn_value));
	(*data) = DWD_SoundIndcn_value;
	return ret;


#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ChimeMessageType ret = 0U;
	uint8 DWD_SoundIndcn_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DWD_SOUNDINDCN,&DWD_SoundIndcn_value,(uint8)sizeof(DWD_SoundIndcn_value));
	(*data) = DWD_SoundIndcn_value;
	return ret;


#elif (CHIME_PROJECT_TYPE_P02 == 1)
	ChimeMessageType ret = 0U;
	uint8 DWD_SoundIndcn_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DWD_SOUNDINDCN,&DWD_SoundIndcn_value,(uint8)sizeof(DWD_SoundIndcn_value));
	(*data) = DWD_SoundIndcn_value;
	return ret;

#else
	return RTE_E_INVALID;

#endif

}
ChimeMessageType Chime_GetMessage_TOD1_SystemOperMod(uint8 *data)
{

#if (CHIME_PROJECT_TYPE_B03 == 1)
	(*data) = 0;
	return RTE_E_INVALID;
	
#elif (CHIME_PROJECT_TYPE_B02 == 1)
	(*data) = 0;
	return RTE_E_INVALID;
	
#elif (CHIME_PROJECT_TYPE_P05 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_P03 == 1)
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_A07 == 1) 
	(*data) = 0;
	return RTE_E_INVALID;

#elif (CHIME_PROJECT_TYPE_D01 == 1) 
	ChimeMessageType ret = 0U;
	uint8 DWD_SoundIndcn_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD,&DWD_SoundIndcn_value,(uint8)sizeof(DWD_SoundIndcn_value));
	(*data) = DWD_SoundIndcn_value;
	return ret;


#elif (CHIME_PROJECT_TYPE_D02 == 1) 
	ChimeMessageType ret = 0U;
	uint8 DWD_SoundIndcn_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD,&DWD_SoundIndcn_value,(uint8)sizeof(DWD_SoundIndcn_value));
	(*data) = DWD_SoundIndcn_value;
	return ret;


#elif (CHIME_PROJECT_TYPE_D03 == 1) 
	ChimeMessageType ret = 0U;
	uint8 DWD_SoundIndcn_value = 0;
	ret = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD,&DWD_SoundIndcn_value,(uint8)sizeof(DWD_SoundIndcn_value));
	(*data) = DWD_SoundIndcn_value;
	return ret;


#elif (CHIME_PROJECT_TYPE_P02 == 1)
	(*data) = 0;
	return RTE_E_INVALID;
	
#elif (CHIME_PROJECT_TYPE_P01 == 1)
	(*data) = 0;
	return RTE_E_INVALID;

#else
	return RTE_E_INVALID;

#endif

}

	

ChimeMessageType Chime_GetInterface_SpeedoInfo_Element(uint16 *data)
{
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
	ChimeMessageType speed_sts;
	s_SpeedoInfo_t speed;
	speed_sts = Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed);
	*data = speed.IndicateSpeed;
	return speed_sts;
#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetInterface_WarningStsDoor(uint16 *data,uint16 bit)
{
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
	ChimeMessageType warning_sts;
	WN_WarningStsOutput warning;
	uint16 data1 = 0;
	warning_sts = Rte_Read_rpSR_SWCNormal_WarningStsOutput_Element(&warning);
	if(bit < ((uint16)((sizeof(WN_WarningStsOutput) * 8) - 1U)))
	{
		(*data) = ((uint16)(*(uint16 *)&warning.WarningStatus[bit/8]) >> ((uint16)(bit % 8)));
	}
	else
	{
		*data = 0;
	}
	 
	data1 = ((uint16)(*(uint16 *)&warning.WarningStatus[(uint16)(WN_enOneTrunkBoardOpen)/8]) >> ((uint16)(WN_enOneTrunkBoardOpen) % 8));

	(*data ) = ((uint16)((*data) & 0x3FFu) | (uint16)((data1 & 0x03u) << 10u));

	return warning_sts;
#else
	*data = 0;
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetInterface_SelfCheck_Element(uint8 *data)
{
#ifdef Rte_Read_tiSR_SWC_TT_SelfCheck_Element
	return Rte_Read_tiSR_SWC_TT_SelfCheck_Element(data);
#else
	return RTE_E_INVALID;
#endif
}

ChimeMessageType Chime_GetInterface_TC_NE_ChargStsOutput_Element(uint8 *data)
{
#ifdef Rte_Read_rpSR_SWCNormal_TC_NE_ChargStsOutput_Element

		ChimeMessageType u8ChargSts;
		ChimeMessageType u8ChargStsOutput;
		u8ChargSts = Rte_Read_rpSR_SWCNormal_TC_NE_ChargStsOutput_Element(&u8ChargStsOutput);
		*data = u8ChargStsOutput;
		return u8ChargSts;
#else
		return RTE_E_INVALID;
#endif
}

#ifdef CHIME_RUNABLE_TIME_TEST
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
void Chime_RteAdaptRunableOstmStart(uint8 index)
{
	uint32 passtime;
	TM_TimerElapsed(&ChimeOstmTickCounter_s[index].TimerTick_u32,&passtime);
	TM_TimerStartStamp(&ChimeOstmTickCounter_s[index].TimerTick_u32);
	if(passtime > ChimeRunableTimerTest[index].ChimeRunableTimerTest_MAXRunTime)
	{
		ChimeRunableTimerTest[index].ChimeRunableTimerTest_MAXRunTime = passtime;
	}
	if((index == 1 && passtime > 200000) || (index == 2 && passtime > 100000))
	{
		ChimeRunableTimerTest[index].ChimeRunableTimerTest_OverTimeTick ++;
	}
	ChimeRunableTimerTest[index].ChimeRunableTimerTest_IndexRunTime++;
	ChimeRunableTimerTest[index].ChimeRunableTimerTest_AlltimeRunTime += passtime;
	ChimeRunableTimerTest[index].ChimeRunableTimerTest_AVGRunTime = (uint32)(ChimeRunableTimerTest[index].ChimeRunableTimerTest_AlltimeRunTime/ChimeRunableTimerTest[index].ChimeRunableTimerTest_Index);
	Rte_Enter_ExclusiveArea_Normal();

}

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
void Chime_RteAdaptRunableOstmCheck(uint8 index)
{
	uint32 passtime;
	TM_TimerElapsed(&ChimeOstmTickCounter_s[index].TimerTick_u32,&passtime);
	TM_TimerStartStamp(&ChimeOstmTickCounter_s[index].TimerTick_u32);
	if(passtime > 15000)
	{
		passtime ++;
	}
	if(passtime > ChimeRunableTimerTest[index].ChimeRunableTimerTest_MAX)
	{
		ChimeRunableTimerTest[index].ChimeRunableTimerTest_MAX = passtime;
	}
	if(passtime < ChimeRunableTimerTest[index].ChimeRunableTimerTest_MIN)
	{
		ChimeRunableTimerTest[index].ChimeRunableTimerTest_MIN = passtime;
	}
	ChimeRunableTimerTest[index].ChimeRunableTimerTest_Index++;
	ChimeRunableTimerTest[index].ChimeRunableTimerTest_Alltime += passtime;
	ChimeRunableTimerTest[index].ChimeRunableTimerTest_AVG = (uint32)(ChimeRunableTimerTest[index].ChimeRunableTimerTest_Alltime/ChimeRunableTimerTest[index].ChimeRunableTimerTest_Index);
	Rte_Exit_ExclusiveArea_Normal();
}
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

/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/

