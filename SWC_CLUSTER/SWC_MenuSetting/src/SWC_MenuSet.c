/**********************************************************************************************************
*                                                                                                         *
*                          CONFIDENTIAL NOBO CORPORATION                              					  *
*                                                                                                         *
* Copyright @ 2019 - 2021 Nobo Automotive Technologies Co.,Ltd.                                           *
* All Rights Reserved.                                                                                    *
*                                                                                                         *
* Redistribution and use in source and binary forms, with or without                                      *
* modification, are NOT permitted except as agreed by                                                     *
* Nobo Automotive Technologies Co.,Ltd.                                                                   *
*                                                                                                         *
* Unless required by applicable law or agreed to in writing, software                                     *
* distributed under the License is distributed on an "AS IS" BASIS,                                       *
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.                                *
*                                                                                                         *
**********************************************************************************************************/

/**********************************************************************************************************
*File Name   : SWC_MenuSet.c                                                                           *
*                                                                                                         *
*Description : MenuSet module application source file.                                      *
*                                                                                                         *
*Author      : hai hu                                                                       *
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
* External Function Include                                                                               *
**********************************************************************************************************/

/*****************************************************************************
*                                 System Includes                            *
******************************************************************************/
#include "Rte_Common_Normal.h"

/*****************************************************************************
*                                 Project Includes                           *
******************************************************************************/
#include "string.h"
#include "SWC_MenuSet.h"
#include "SWC_IPC_Manager.h"
#include "Vconfig.h"
#include "IPC_ClusterApp.h"
#include "SWC_IPC_Config.h"
#include "SWC_Fuel_Api_Process.h"
#include "logger_Cfg.h"
#include "logger.h"
#include "Rte_Type.h"

/*****************************************************************************
*                                 Globally  accessed Variable Declarations   *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
******************************************************************************/
/*****************************************************************************
*                               No Init Variable                             *
******************************************************************************/
#define Common_Normal_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Common_Normal_MemMap.h"
static boolean boIgnOnSyncDataFlg;
static boolean Menu_Nvm_write_flg = FALSE;
static boolean Menu_M2S_print_flg = FALSE;
static boolean Menu_CanOutput_print_flg = FALSE;
static MenuSetData_t RcMenuSetDataPre;
static MenuSetData_t SdMenuSetDataPre;
static IPC_S2M_ClusterAppClusterSocMenuTheme_t RcMenuThemePre;
static IPC_S2M_ClusterAppClusterSocMenuTheme_t SdMenuThemePre;
static IPC_M2S_ClusterAppAPPMenuSetting_t IPC_MenuSetData; 
static IPC_S2M_ClusterAppClusterSocMenuTheme_t IPC_MenuTheme;
static IPC_M2S_ClusterAppAPPOffroadInfo_t IPC_MenuOffroadInfo;

static MenuSet_Vconfig_t MenuSet_Vconfig;
#define Common_Normal_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Common_Normal_MemMap.h"

#pragma ghs section bss=".buram"
//static MenuSet_str RcMenuSetData_arr;
//static MenuSet_str SdMenuSetData_arr;
static MenuSetData_t RcMenuSetData;
static MenuSetData_t SdMenuSetData;
static IPC_S2M_ClusterAppClusterSocMenuTheme_t RcMenuTheme;
static IPC_S2M_ClusterAppClusterSocMenuTheme_t SdMenuTheme;
static uint32 Menu_ColdInitFinish_u32;
static uint8 Menu_Count_ColdInit_3S;
static uint8 Menu_NVM_Write_fail_count;
static MenuCanOutput_t MenuCanOutputDataPre;
static MenuCanOutput_t MenuCanOutputData;
static uint8 u8TirePressureUnitPre;
static uint16 l_Sd_BaroPressure_u16;
static uint16 l_Sd_Heilvl_u16;
static uint8 l_Sd_HeilvlSign_u8;
static uint8 l_Sd_PitchAngle_u8;
static uint8 l_Sd_PitchAngleSign_u8;
static uint8 l_Sd_GeoGraphic_u8;
static uint8 l_Sd_SteerWheel_u8;
static uint8 l_Sd_SteerWheelSign_u8;
static IPC_M2S_ClusterAppAPPOffroadInfo_t SdMenuSetOffroad;
#pragma ghs section bss=default

/*****************************************************************************
*                                 Init Variable                             *
******************************************************************************/
#define Common_Normal_START_SEC_VAR_INIT_UNSPECIFIED
#include "Common_Normal_MemMap.h"
static MenuSetData_t Rte_Common_Normal_ppSR_SWCNormal_MenuSet_Element = {
	0U, 0U, 0U, 0U
};
#define Common_Normal_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Common_Normal_MemMap.h"

/*****************************************************************************
*                                 Const Variable                             *
******************************************************************************/
#define Common_Normal_START_SEC_CONST_UNSPECIFIED
#include "Common_Normal_MemMap.h"

#define Common_Normal_STOP_SEC_CONST_UNSPECIFIED
#include "Common_Normal_MemMap.h"

/*****************************************************************************
*                                 Functions                                  *
******************************************************************************/
#define Common_Normal_START_SEC_CODE
#include "Common_Normal_MemMap.h" 

static void MenuSet_get_vehicle_config(void);
static void MenuSet_CanOutput(void);
static void MenuSet_NvmWrite(void);
static void MenuSet_vSystemUnitCheck(void);
static void MenuSet_language_mapping(void);
static void MenuSet_buramVal_Get(void);

/*******************************************************************************
*
*   Function:           MenuSetMdl_MenuSet_cold_init
*
*   Description:        This function performs a Cold reset Initialization
*                       of the MenuSet.
*
*   Input Arguments:    None
*
*   Return Value:       None
*
*   Modified:           6/24/2020 HH
*******************************************************************************/
void MenuSetMdl_MenuSet_cold_init(void)
{
	boolean cold_flag = FALSE;
	uint8 *p_MenuSetNvm_Init = Rte_Pim_NvBlockNeed_Menu_MirrorBlock();	
	Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&cold_flag);

	if((FALSE == cold_flag) || (0x5A5A5A5A != Menu_ColdInitFinish_u32))
	{
		/* clear ram of menu setting */
		(void)memset(&RcMenuSetData, 0, sizeof(MenuSetData_t));
		(void)memset(&SdMenuSetData, 0, sizeof(MenuSetData_t));
		(void)memset(&RcMenuTheme, 0, sizeof(IPC_M2S_ClusterAppAPPMenuTheme_t));
		(void)memset(&SdMenuTheme, 0, sizeof(IPC_M2S_ClusterAppAPPMenuTheme_t));
		(void)memset(&SdMenuSetOffroad, 0, sizeof(IPC_M2S_ClusterAppAPPOffroadInfo_t));
		
		MenuSet_get_vehicle_config();
		RcMenuSetData.OverSpeedEnable = 1u;
		
		if((MenuSet_Vconfig.UnitSystem == 2u) || (MenuSet_Vconfig.UnitSystem == 3u))
		{
			RcMenuSetData.NaviLimitSpeed = 75u;
		}
		else
		{
			RcMenuSetData.NaviLimitSpeed = 120u;
		}

		RcMenuSetData.TemperatureUnit = MenuSet_Vconfig.Outside_Temperature_Unit;
		RcMenuSetData.OdometerUnit = MenuSet_Vconfig.UnitSystem;
		/*Default value:ClusterTheme is 4 ,Cluster_Auto_Mode is 1,Cluster_Sunrise_Sunset_Mode is 0,TirePressureUnit is 0(kPa)*/
		RcMenuSetData.Cluster_Sunrise_Sunset_Mode = *(p_MenuSetNvm_Init+1u);
		RcMenuSetData.Cluster_Auto_Mode = *(p_MenuSetNvm_Init+2u);
		RcMenuSetData.DrivingModeMemorySwitch = *(p_MenuSetNvm_Init+3u);
		RcMenuSetData.DrvingModReq_HUT = *(p_MenuSetNvm_Init+4u);
		/*show topic*/
		RcMenuSetData.DrvgModeMemReq = *(p_MenuSetNvm_Init+5u);
		(void)memcpy((uint8 *)(&RcMenuTheme.Rc_ThemeID),(p_MenuSetNvm_Init+6u),sizeof(RcMenuTheme.Rc_ThemeID));
		(void)memcpy((uint8 *)(&RcMenuTheme.Rc_SkinID),(p_MenuSetNvm_Init+10u),sizeof(RcMenuTheme.Rc_SkinID));
		RcMenuSetData.TirePressureUnit = *(p_MenuSetNvm_Init+14u);
		#ifdef Menu_PROJECT_TYPE_D03
		{
			RcMenuSetData.ClusterTheme = *(p_MenuSetNvm_Init+15u);
		}
		#else
		{
			RcMenuSetData.ClusterTheme = *p_MenuSetNvm_Init;
		}
		#endif
		Menu_ColdInitFinish_u32 = 0x5A5A5A5A;
		l_Sd_BaroPressure_u16 = 1205u;
		l_Sd_SteerWheel_u8 = 0xFFU;
	}
	else
	{
		/* keep previous status */
		(void)MenuSet_debug("MenuSet warm init [%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d]",
		RcMenuSetData.TemperatureUnit, RcMenuSetData.TirePressureUnit, RcMenuSetData.OdometerUnit, 		
		RcMenuSetData.ClusterTheme, RcMenuSetData.Cluster_Sunrise_Sunset_Mode, RcMenuSetData.Cluster_Auto_Mode, 
		RcMenuSetData.DrivingModeMemorySwitch, RcMenuSetData.DrvingModReq_HUT, RcMenuSetData.DrvgModeMemReq,
		RcMenuTheme.Rc_ThemeID, RcMenuTheme.Rc_SkinID);
	}	
	
	boIgnOnSyncDataFlg = TRUE;
	
	(void)memcpy(&RcMenuSetDataPre, &RcMenuSetData, sizeof(MenuSetData_t));
	(void)memcpy(&SdMenuSetDataPre, &SdMenuSetData, sizeof(MenuSetData_t));
}

/*******************************************************************************
*
*   Function:           MenuSetMdl_MenuSet_warm_init
*
*   Description:        This function performs a warm reset Initialization
*                       of the MenuSet.
*
*   Input Arguments:    None
*
*   Return Value:       None
*
*   Modified:           6/24/2020 HH
*******************************************************************************/
void MenuSetMdl_MenuSet_warm_init(void)
{	
	boIgnOnSyncDataFlg = TRUE;
}

/*******************************************************************************
*
*   Function:           MenuSetMdl_MenuSet_app_tsk
*
*   Description:        This function performs implementation of the MenuSet.
*
*   Input Arguments:    None
*
*   Return Value:       None
*
*   Modified:           6/24/2020 HH
*******************************************************************************/
void MenuSetMdl_MenuSet_app_tsk(void)
{		
	if (Menu_Count_ColdInit_3S <= 30U) 
	{
		Menu_Count_ColdInit_3S++;
	}
	else 
	{
		if (Menu_Count_ColdInit_3S != 0xFFU) 
		{
			(void)MenuSet_debug("MenuSet cold init [%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d]",
				RcMenuSetData.TemperatureUnit, RcMenuSetData.TirePressureUnit, RcMenuSetData.OdometerUnit, 		
				RcMenuSetData.ClusterTheme, RcMenuSetData.Cluster_Sunrise_Sunset_Mode, RcMenuSetData.Cluster_Auto_Mode, 
				RcMenuSetData.DrivingModeMemorySwitch, RcMenuSetData.DrvingModReq_HUT, RcMenuSetData.DrvgModeMemReq,
				RcMenuTheme.Rc_ThemeID, RcMenuTheme.Rc_SkinID);	
		}
		Menu_Count_ColdInit_3S = 0xFFU;
	}

	/* SystemUnit Setted by MenuSettings prior to by vehicle configuration */
	MenuSet_vSystemUnitCheck();

	if(boIgnOnSyncDataFlg || (0u != memcmp(&RcMenuSetData, &RcMenuSetDataPre, sizeof(MenuSetData_t))) || (0u != memcmp(&RcMenuTheme, &RcMenuThemePre, sizeof(IPC_S2M_ClusterAppClusterSocMenuTheme_t))))
	{
		(void)Rte_Write_ppSR_SWCNormal_MenuSet_Element(&RcMenuSetData);
		(void)Rte_Write_ppSR_SWCNormal_MenuSet_OverSpeedEnable_Element(RcMenuSetData.OverSpeedEnable);
		(void)Rte_Write_ppSR_SWCNormal_MenuSet_OverSpeedLimit_Element(RcMenuSetData.NaviLimitSpeed);
		(void)memcpy(&SdMenuSetData, &RcMenuSetData, sizeof(MenuSetData_t));
		(void)memcpy(&SdMenuTheme, &RcMenuTheme, sizeof(IPC_M2S_ClusterAppAPPMenuTheme_t));
		
		if((RcMenuSetData.ClusterTheme != RcMenuSetDataPre.ClusterTheme) ||\
		   (RcMenuSetData.Cluster_Auto_Mode != RcMenuSetDataPre.Cluster_Auto_Mode) ||\
		   (RcMenuSetData.Cluster_Sunrise_Sunset_Mode != RcMenuSetDataPre.Cluster_Sunrise_Sunset_Mode) ||\
		   (RcMenuSetData.DrvgModeMemReq != RcMenuSetDataPre.DrvgModeMemReq) ||\
		   (RcMenuSetData.TirePressureUnit != RcMenuSetDataPre.TirePressureUnit) ||\
		   (RcMenuTheme.Rc_ThemeID != RcMenuThemePre.Rc_ThemeID) ||\
		   (RcMenuTheme.Rc_SkinID != RcMenuThemePre.Rc_SkinID) ||\
		   (((RcMenuSetData.DrivingModeMemorySwitch != RcMenuSetDataPre.DrivingModeMemorySwitch) || (RcMenuSetData.DrvingModReq_HUT != RcMenuSetDataPre.DrvingModReq_HUT)) &&\
	   	   (RcMenuSetData.DrivingModeMemorySwitch == 0x1) && ((RcMenuSetData.DrvingModReq_HUT == 0xE) || (RcMenuSetData.DrvingModReq_HUT == 0xC))))
		{
			Menu_Nvm_write_flg = TRUE;
		}
		else
		{
			//do nothing
		}
		//modify by P05-4595
		(void)memcpy(&RcMenuSetDataPre, &RcMenuSetData, sizeof(MenuSetData_t));
		(void)memcpy(&RcMenuThemePre, &RcMenuTheme, sizeof(IPC_S2M_ClusterAppClusterSocMenuTheme_t));		
	}

	if (Menu_Nvm_write_flg) 
	{
		MenuSet_NvmWrite();
	}

    MenuSet_buramVal_Get();
	/* Response to SOC by IPC */
	if(boIgnOnSyncDataFlg || (0u != memcmp(&SdMenuSetData, &SdMenuSetDataPre, sizeof(MenuSetData_t))) ||\
		(0u != memcmp(&SdMenuTheme, &SdMenuThemePre, sizeof(IPC_S2M_ClusterAppClusterSocMenuTheme_t))))
	{
		IPC_MenuSetData.Sd_NaviLimitSpeed = SdMenuSetData.NaviLimitSpeed;
		IPC_MenuSetData.Sd_OverSpeedEnable = SdMenuSetData.OverSpeedEnable;
		IPC_MenuSetData.Sd_Language = SdMenuSetData.Language;
		IPC_MenuSetData.Sd_ClusterTheme = SdMenuSetData.ClusterTheme;
		IPC_MenuSetData.Sd_OdometerUnit = SdMenuSetData.OdometerUnit;
		IPC_MenuSetData.Sd_TemperatureUnit = SdMenuSetData.TemperatureUnit;
		IPC_MenuSetData.Sd_TirePressureUnit = SdMenuSetData.TirePressureUnit;
		IPC_MenuSetData.Sd_TripComputerId = SdMenuSetData.TripComputerId;
		IPC_MenuSetData.Sd_InteractiveCarId = SdMenuSetData.InteractiveCarId;
		IPC_MenuSetData.Sd_DrivingModeMemorySwitch = SdMenuSetData.DrivingModeMemorySwitch;
		IPC_MenuSetData.Sd_TimeUnit = SdMenuSetData.TimeUnit;
		IPC_MenuSetData.Sd_HighwayAssistSwitch = SdMenuSetData.HighwayAssistSwitch;
		IPC_MenuSetData.Sd_LaneChangeAssistSwitch = SdMenuSetData.LaneChangeAssistSwitch;
		IPC_MenuSetData.Sd_SunriseSunset_Mode = SdMenuSetData.Cluster_Sunrise_Sunset_Mode;
		IPC_MenuSetData.Sd_Auto_Mode = SdMenuSetData.Cluster_Auto_Mode;
		IPC_MenuSetData.Sd_DrvgModeMemReq = SdMenuSetData.DrvgModeMemReq;
		IPC_MenuSetData.Sd_DrvingModReqHUT = SdMenuSetData.DrvingModReq_HUT;
		IPC_MenuSetData.Sd_DataSyncFlg = SdMenuSetData.DataSyncFlag;
		
		(void)memcpy(&IPC_MenuTheme, &SdMenuTheme, sizeof(IPC_S2M_ClusterAppClusterSocMenuTheme_t));
		(void)Rte_Call_rpCS_MenuSet_IPC_Send(&IPC_MenuSetData);
		(void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_MENU_THEME_RESP, (uint8 *)&IPC_MenuTheme, (uint16)sizeof(IPC_M2S_ClusterAppAPPMenuTheme_t), FALSE);
		
		Menu_M2S_print_flg = TRUE;
		//modify by P05-4595
		(void)memcpy(&SdMenuSetDataPre, &SdMenuSetData, sizeof(MenuSetData_t));
		(void)memcpy(&SdMenuThemePre, &SdMenuTheme, sizeof(IPC_S2M_ClusterAppClusterSocMenuTheme_t));
	}

    (void)memcpy(&IPC_MenuOffroadInfo, &SdMenuSetOffroad, sizeof(IPC_M2S_ClusterAppAPPOffroadInfo_t));
	(void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_SET_OffroadInfo_RESP, (uint8 *)&IPC_MenuOffroadInfo, sizeof(IPC_M2S_ClusterAppAPPOffroadInfo_t), FALSE);
	
	if (Menu_M2S_print_flg && (Menu_Count_ColdInit_3S == 0xFFU)) 
	{
		Menu_M2S_print_flg = FALSE;
		(void)MenuSet_debug("MenuSet M2S [%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d]", 
			IPC_MenuSetData.Sd_NaviLimitSpeed, IPC_MenuSetData.Sd_OverSpeedEnable, IPC_MenuSetData.Sd_Language, IPC_MenuSetData.Sd_ClusterTheme, 	 
			IPC_MenuSetData.Sd_OdometerUnit, IPC_MenuSetData.Sd_TemperatureUnit, IPC_MenuSetData.Sd_TirePressureUnit, IPC_MenuSetData.Sd_TripComputerId, 	 
			IPC_MenuSetData.Sd_InteractiveCarId, IPC_MenuSetData.Sd_DrivingModeMemorySwitch, IPC_MenuSetData.Sd_TimeUnit, IPC_MenuSetData.Sd_HighwayAssistSwitch,  
			IPC_MenuSetData.Sd_LaneChangeAssistSwitch, IPC_MenuSetData.Sd_SunriseSunset_Mode, IPC_MenuSetData.Sd_Auto_Mode, IPC_MenuSetData.Sd_DrvgModeMemReq,  
			IPC_MenuSetData.Sd_DrvingModReqHUT, IPC_MenuSetData.Sd_Switch_ThemeLinkage_Sts, IPC_MenuSetData.Sd_DataSyncFlg, IPC_MenuTheme.Rc_ThemeID,  
			IPC_MenuTheme.Rc_SkinID); 
	}
	
	/* Send MenuSettings to other module */
	(void)Rte_Write_Common_Normal_ppSR_SWCNormal_MenuSetData_Element(&RcMenuSetData);
	/* Send to TX CAN */
	MenuSet_CanOutput();
	boIgnOnSyncDataFlg = FALSE;
}

/**********************************************************************************************************
*Function   : MenuSet_get_vehicle_config                                                              	 		  *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                		  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HH                                                                                   		  *
*                                                                                                         *
*Date       : 2020-11-23                                                                                  *
**********************************************************************************************************/
static void MenuSet_get_vehicle_config(void)
{
	//uint8 *VConfigAddr;
	VconfigKind_Allbuffers VConfigAddr;
	uint8 u8VcfgSpeedometer = 0u;
	uint8 u8VcfgUnitSystem = 0u;
	uint8 u8VcfgLanguage = 0u;
	(void)Rte_Read_Vconfig_GetKindBuffers_AllKinds(VConfigAddr);

	if(0u != VConfigAddr[VCONFIG_KIND_INIT_FLAG])
	{
		u8VcfgSpeedometer = VConfigAddr[VCONFIG_KIND_SPEEDOMETER];
		u8VcfgUnitSystem = VConfigAddr[VCONFIG_KIND_CLUSTER_UNIT_SYSTEM];
		u8VcfgLanguage = VConfigAddr[VCONFIG_KIND_ELECTRIC_LANGUAGE];
	}

	if((u8VcfgSpeedometer == 0x2u) || (u8VcfgSpeedometer == 0x4u))
	{
		MenuSet_Vconfig.OverSpeedEnable = 1u;
	}
	else
	{
		MenuSet_Vconfig.OverSpeedEnable = 0u;
	}

	if((0x00u == u8VcfgUnitSystem) || (0x01u == u8VcfgUnitSystem))
	{
		/*degree centigrade C*/
		MenuSet_Vconfig.Outside_Temperature_Unit = 0u;
		u8TirePressureUnitPre = 0u;
	}
	else if(0x02u == u8VcfgUnitSystem)
	{
		/*degree centigrade C*/
		MenuSet_Vconfig.Outside_Temperature_Unit = 0u;
		u8TirePressureUnitPre = 1u;
	}
	else if(0x03u == u8VcfgUnitSystem)
	{
		/*fahrenheit degree F*/
		MenuSet_Vconfig.Outside_Temperature_Unit = 0x01u;
		u8TirePressureUnitPre = 1u;
	}
	else
	{
		//do nothing
	}

	MenuSet_Vconfig.UnitSystem = u8VcfgUnitSystem;
	MenuSet_Vconfig.Language = u8VcfgLanguage;
}

/**********************************************************************************************************
*Function   : MenuSet_CanOutput                                                              	 		  *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                		  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HH                                                                                   		  *
*                                                                                                         *
*Date       : 2020-11-30                                                                                  *
**********************************************************************************************************/
static void MenuSet_CanOutput(void)
{	
	SystemState_RecordType *u8PowerMode;
	
	u8PowerMode = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
	
	/* Cluster Language output*/	
	if((SYSTEMSTATE_Cluster_ON == u8PowerMode->ClusterState) \
		&& ((VOLTAGE_OUT_NORMAL == u8PowerMode->s_PowerVoltage.state) || \
		(VOLTAGE_OUT_LOWALARM == u8PowerMode->s_PowerVoltage.state) || \
		(VOLTAGE_OUT_HIGHALARM == u8PowerMode->s_PowerVoltage.state)))
	{
		MenuCanOutputData.Menu_LagueSet = RcMenuSetData.Language;
	}
	else
	{
		MenuCanOutputData.Menu_LagueSet = 0xFU;
	}
	(void)Rte_Write_Sd_CanOutputViaGateway_IP_LagueSet(MenuCanOutputData.Menu_LagueSet);

	/* Cluster Theme Mode output*/	
	if(RcMenuSetData.DrvingModReq_HUT == 0xEU)
	{
		MenuCanOutputData.Menu_CurrTheme = 0x6U;
	}	
	else if(RcMenuSetData.DrvingModReq_HUT == 0xCU)
	{
		MenuCanOutputData.Menu_CurrTheme = 0x7U;
	}	
	else
	{
		MenuCanOutputData.Menu_CurrTheme = RcMenuSetData.ClusterTheme;
	}
	(void)Rte_Write_Sd_CanOutputViaGateway_IP_CurrTheme(MenuCanOutputData.Menu_CurrTheme);

	if (0u != memcmp(&MenuCanOutputData, &MenuCanOutputDataPre, sizeof(MenuCanOutput_t))) 
	{
		Menu_CanOutput_print_flg = TRUE;
		(void)memcpy(&MenuCanOutputDataPre, &MenuCanOutputData, sizeof(MenuCanOutput_t));	
	}

	if (Menu_CanOutput_print_flg && (Menu_Count_ColdInit_3S == 0xFFU)) 
	{
		Menu_CanOutput_print_flg = FALSE;
		(void)MenuSet_debug("MenuSet CanOutput data changes [%d, %d]", MenuCanOutputData.Menu_LagueSet, MenuCanOutputData.Menu_CurrTheme);
	}
}

/**********************************************************************************************************
*Function   : MenuSet_NvmWrite                                                              	 		  *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                		  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HH                                                                                   		  *
*                                                                                                         *
*Date       : 2020-11-30                                                                                  *
**********************************************************************************************************/
static void MenuSet_NvmWrite(void)
{
	NvM_RequestResultType Blk_type = NVM_REQ_OK;
	/*The status of NVM?? */
	(void)Rte_Call_NvMService_AC3_SRBS_NvBlockNeed_Menu_GetErrorStatus(&Blk_type);
	/*The condition of start writing NVM*/
	if(NVM_REQ_PENDING != Blk_type)
	{
		*(Rte_Pim_NvBlockNeed_Menu_MirrorBlock()+1u) = RcMenuSetData.Cluster_Sunrise_Sunset_Mode;
		*(Rte_Pim_NvBlockNeed_Menu_MirrorBlock()+2u) = RcMenuSetData.Cluster_Auto_Mode;
		*(Rte_Pim_NvBlockNeed_Menu_MirrorBlock()+3u) = RcMenuSetData.DrivingModeMemorySwitch;
		*(Rte_Pim_NvBlockNeed_Menu_MirrorBlock()+4u) = RcMenuSetData.DrvingModReq_HUT;
		/*show topic*/
		*(Rte_Pim_NvBlockNeed_Menu_MirrorBlock()+5u) = RcMenuSetData.DrvgModeMemReq;
		(void)memcpy(Rte_Pim_NvBlockNeed_Menu_MirrorBlock()+6u,(uint8 *)(&RcMenuTheme.Rc_ThemeID),sizeof(RcMenuTheme.Rc_ThemeID));
		(void)memcpy(Rte_Pim_NvBlockNeed_Menu_MirrorBlock()+10u,(uint8 *)(&RcMenuTheme.Rc_SkinID),sizeof(RcMenuTheme.Rc_SkinID));
		*(Rte_Pim_NvBlockNeed_Menu_MirrorBlock()+14u) = RcMenuSetData.TirePressureUnit;
		#ifdef Menu_PROJECT_TYPE_D03
		{
			*(Rte_Pim_NvBlockNeed_Menu_MirrorBlock()+15u) = RcMenuSetData.ClusterTheme;
		}
		#else
		{
			(*Rte_Pim_NvBlockNeed_Menu_MirrorBlock()) = RcMenuSetData.ClusterTheme;
		}
		#endif
		(void)Rte_Call_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock(NULL_PTR);
		/*Print the log*/
		(void)MenuSet_debug("MenuSet NVM write data [%d, %d, %d, %d, %d, %d, %d, %d, %d]",
							RcMenuSetData.ClusterTheme, RcMenuSetData.Cluster_Sunrise_Sunset_Mode, RcMenuSetData.Cluster_Auto_Mode, 		
							RcMenuSetData.DrivingModeMemorySwitch, RcMenuSetData.DrvingModReq_HUT, RcMenuSetData.DrvgModeMemReq,
							RcMenuTheme.Rc_ThemeID, RcMenuTheme.Rc_SkinID, RcMenuSetData.TirePressureUnit);
		Menu_Nvm_write_flg = FALSE;
		Menu_NVM_Write_fail_count = 0U;
	}	
	else
	{
		if (Menu_NVM_Write_fail_count < NVM_WRITE_FAIL_MAX) 
		{
			Menu_NVM_Write_fail_count++;
			(void)MenuSet_debug("MenuSet NVM write status = %d", Blk_type);
			
		}
		else if (Menu_NVM_Write_fail_count == NVM_WRITE_FAIL_MAX)
		{
			(void)MenuSet_debug("MenuSet NVM status write fail !");
		}
		else
		{
			/*can be empty*/
		}
	}
}
/**********************************************************************************************************
*Function   : MenuSet_vSystemUnitCheck                                                              	  *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                		  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HH                                                                                   		  *
*                                                                                                         *
*Date       : 2020-11-30                                                                                  *
**********************************************************************************************************/
static void MenuSet_vSystemUnitCheck(void)
{
	VconfigKind_Allbuffers VConfigAddr;
	uint8 u8SystemUnit = 0u;	
	uint8 u8VcfgUintFlag = 0u;
	uint8 u8TirePressureUnit = 0u;
#define Common_Normal_START_SEC_VAR_INIT_UNSPECIFIED
#include "Common_Normal_MemMap.h"
	static uint8 u8SystemUnitPre = 0u;
#define Common_Normal_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Common_Normal_MemMap.h"
	(void)Rte_Read_Vconfig_GetKindBuffers_AllKinds(VConfigAddr);
	u8VcfgUintFlag = VConfigAddr[VCONFIG_KIND_INIT_FLAG];
	
	if(u8VcfgUintFlag == TRUE)
	{
		MenuSet_Vconfig.UnitSystem = VConfigAddr[VCONFIG_KIND_CLUSTER_UNIT_SYSTEM];
		MenuSet_Vconfig.Language = VConfigAddr[VCONFIG_KIND_ELECTRIC_LANGUAGE];
	}

	MenuSet_language_mapping();
	u8SystemUnit = MenuSet_Vconfig.UnitSystem;
	RcMenuSetData.Language = MenuSet_Vconfig.Language;

	if ((0x00 == u8SystemUnit) || (0x01 == u8SystemUnit))
	{
	    u8TirePressureUnit = 0u;
	}
	else if ((0x02 == u8SystemUnit) || (0x03 == u8SystemUnit))
	{
	    u8TirePressureUnit = 1u;
	}
	else
	{
	    //do nothing
	}

	if (RcMenuSetData.TirePressureUnit != RcMenuSetDataPre.TirePressureUnit)
	{
	    //do noting
	}
	else
	{
	    if (u8TirePressureUnit != u8TirePressureUnitPre)
	    {
	        RcMenuSetData.TirePressureUnit = u8TirePressureUnit;
			u8TirePressureUnitPre = u8TirePressureUnit;
	    }
		else
		{
		    //do nothing
		}
	}
	
	if(RcMenuSetData.OdometerUnit != RcMenuSetDataPre.OdometerUnit)
	{
		/* do nothing */
	}
	else
	{
		if(u8SystemUnit != u8SystemUnitPre)
		{
			RcMenuSetData.OdometerUnit = u8SystemUnit;
			u8SystemUnitPre = u8SystemUnit;
		}
		else
		{
			/* do nothing */
		}
	}
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MenuSet_ppSR_Element(MenuSetData_t *data)
{
	Std_ReturnType Ret = RTE_E_OK;
	
	Rte_Common_Normal_ppSR_SWCNormal_MenuSet_Element = (*data);
	
	return Ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_IPC_Send(IPC_M2S_ClusterAppAPPMenuSetting_t *data)
{
	Std_ReturnType Ret = RTE_E_OK;
	
	(void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_SET_MENU_RESP, (uint8 *)data, (uint16)sizeof(IPC_M2S_ClusterAppAPPMenuSetting_t), FALSE);
	
	return Ret;
}

/**********************************************************************************************************
*Function   : IPC_API_ReceiveMenuSettingCallback                                                               *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : uint8 *data                                                                                 *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HH                                                                                   *
*                                                                                                         *
*Date       : 2020-10-02                                                                                  *
**********************************************************************************************************/
FUNC(void, RTE_CODE) IPC_API_ReceiveMenuSettingCallback(uint8 *data)
{
	IPC_S2M_ClusterAppClusterSocMenuSetting_t *MenuSetData = (IPC_S2M_ClusterAppClusterSocMenuSetting_t *)data;
	uint8 ID = (*MenuSetData).ID;	
	switch(ID) 
	{
		case SetNaviLimitSpeedValue :
			RcMenuSetData.NaviLimitSpeed = (uint8)(*MenuSetData).Value;
			break;	
		case SetNaviLimitSpeedEnable :
			RcMenuSetData.OverSpeedEnable = (uint8)(*MenuSetData).Value;
			break;		
		case SetLanguage :
			RcMenuSetData.Language = (uint8)(*MenuSetData).Value;
			break;					
		case SetClusterTheme :
			RcMenuSetData.ClusterTheme = (uint8)(*MenuSetData).Value;
			break;			
		case SetOdometerUnits :
			RcMenuSetData.OdometerUnit = (uint8)(*MenuSetData).Value;
			break;			
		case SetTemperatureUnits :
			RcMenuSetData.TemperatureUnit = (uint8)(*MenuSetData).Value;
			break;		
		case SetTirePressureUnits :
			RcMenuSetData.TirePressureUnit = (uint8)(*MenuSetData).Value;
			break;		
		case SetTripComputerId :
			RcMenuSetData.TripComputerId = (uint8)(*MenuSetData).Value;
			break;			
		case SetInteractiveCard :
			RcMenuSetData.InteractiveCarId = (uint8)(*MenuSetData).Value;
			break;		
		case SetDrivingModeMemorySwitch :
			RcMenuSetData.DrivingModeMemorySwitch = (uint8)(*MenuSetData).Value;
			break;
		case SetTimeUnits :
			RcMenuSetData.TimeUnit = (uint8)(*MenuSetData).Value;
			break;				
		case SetHighwayAssistSwitch :
			RcMenuSetData.HighwayAssistSwitch = (uint8)(*MenuSetData).Value;
			break;		
		case SetLaneChangeAssistSwitch :
			RcMenuSetData.LaneChangeAssistSwitch = (uint8)(*MenuSetData).Value;	
			break;
		case SetSunriseSunsetMode :
			RcMenuSetData.Cluster_Sunrise_Sunset_Mode = (uint8)(*MenuSetData).Value;
			break;
		case SetAutoMode :
			RcMenuSetData.Cluster_Auto_Mode = (uint8)(*MenuSetData).Value;
			break;
		case SetClusterDrivingMode :
			RcMenuSetData.DrvingModReq_HUT = (uint8)(*MenuSetData).Value;
			break; 
		case SetClusterDrivingMem:
			RcMenuSetData.DrvgModeMemReq = (uint8)(*MenuSetData).Value;
			break;
		case SetDataSyncFlg :
			RcMenuSetData.DataSyncFlag = (uint8)(*MenuSetData).Value;
			break;
		default :
			//do nothing
			break;
	}

	(void)MenuSet_debug("MenuSet S2M MenuData ID = %d, Value = %d",(*MenuSetData).ID, (*MenuSetData).Value);

}

/**********************************************************************************************************
*Function   : IPC_API_ReceiveMenuThemeCallback                                                               *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : uint8 *data                                                                                 *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : YangHengMing                                                                                   *
*                                                                                                         *
*Date       : 2021-06-08                                                                                  *
**********************************************************************************************************/
FUNC(void, RTE_CODE) IPC_API_ReceiveMenuThemeCallback(uint8 *data)
{
	IPC_M2S_ClusterAppAPPMenuTheme_t *MenuTheme = (IPC_M2S_ClusterAppAPPMenuTheme_t *)data;
	
	(void)memcpy(&RcMenuTheme, MenuTheme, sizeof(IPC_M2S_ClusterAppAPPMenuTheme_t));

	(void)MenuSet_debug("MenuSet S2M ThemeData ThemeID = %d SkinID = %d",RcMenuTheme.Rc_ThemeID,RcMenuTheme.Rc_SkinID);

}

/**********************************************************************************************************
*Function   : IPC_API_ReceiveMenuOffroadInfoCallback                                                               *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : uint8 *data                                                                                 *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HuangShihao                                                                                   *
*                                                                                                         *
*Date       : 2022-01-20                                                                                  *
**********************************************************************************************************/
FUNC(void, RTE_CODE) IPC_API_ReceiveMenuOffroadInfoCallback(uint8 *data)
{
	IPC_S2M_ClusterAppClusterSocOffroadInfo_t *MenuOffroadInfo = (IPC_S2M_ClusterAppClusterSocOffroadInfo_t *)data;
	uint8 ID = (*MenuOffroadInfo).ID;
	switch(ID)
	{
	    case SetBaroPressure :
			l_Sd_BaroPressure_u16 = (uint16)(*MenuOffroadInfo).Value;
			break;
		case SetHeilvl :
			l_Sd_Heilvl_u16 = (uint16)(*MenuOffroadInfo).Value;
			break;
		case SetHeilvlSign :
			l_Sd_HeilvlSign_u8 = (uint8)(*MenuOffroadInfo).Value;
			break;
		case SetPitchAngle :
			l_Sd_PitchAngle_u8 = (uint8)(*MenuOffroadInfo).Value;
			break;
		case SetPitchAngleSign :
			l_Sd_PitchAngleSign_u8 = (uint8)(*MenuOffroadInfo).Value;
			break;
		case setGeoGraphic :
			l_Sd_GeoGraphic_u8 = (uint8)(*MenuOffroadInfo).Value;
			break;
		case setSteerWheel :
			l_Sd_SteerWheel_u8 = (uint8)(*MenuOffroadInfo).Value;
			break;
		case setSteerWheelSign :
			l_Sd_SteerWheelSign_u8 = (uint8)(*MenuOffroadInfo).Value;
			break;
		default :
			//do nothing
			break;
	}
	
	(void)MenuSet_debug("MenuSet S2M OffroadInfo ID = %d, Value = %d",(*MenuOffroadInfo).ID, (*MenuOffroadInfo).Value);

}

static void MenuSet_language_mapping(void)
{
	switch (MenuSet_Vconfig.Language)
	{
		case 0:
			MenuSet_Vconfig.Language = MENUSET_LANGUAGE_CHINESE;
			break;
		case 1:
			MenuSet_Vconfig.Language = MENUSET_LANGUAGE_ENGLISH;
			break;
		case 2:
			MenuSet_Vconfig.Language = MENUSET_LANGUAGE_RUSSIAN;
			break;
		case 3:
			MenuSet_Vconfig.Language = MENUSET_LANGUAGE_ARABIC;
			break;
		case 4:
			MenuSet_Vconfig.Language = MENUSET_LANGUAGE_SPAISH;
			break;
		case 5:
			MenuSet_Vconfig.Language = MENUSET_LANGUAGE_PORTUGUESE;
			break;
		case 6:
			MenuSet_Vconfig.Language = MENUSET_LANGUAGE_GERMAN;
			break;
		case 7:
			MenuSet_Vconfig.Language = MENUSET_LANGUAGE_FRENCH;
			break;
		case 8:
			MenuSet_Vconfig.Language = MENUSET_LANGUAGE_ITALIAN;
			break;
		case 9:
			MenuSet_Vconfig.Language = MENUSET_LANGUAGE_THAI;
			break;
		case 10:
			MenuSet_Vconfig.Language = MENUSET_LANGUAGE_UKRAINIAN;
			break;
		case 11:
			MenuSet_Vconfig.Language = MENUSET_LANGUAGE_INDONESIAN;
			break;
		default:
			MenuSet_Vconfig.Language = MENUSET_LANGUAGE_CHINESE;
			break;
	}
}

static void MenuSet_buramVal_Get(void)
{
    SdMenuSetOffroad.Sd_BaroPressure = l_Sd_BaroPressure_u16;
	SdMenuSetOffroad.Sd_Heilvl = l_Sd_Heilvl_u16;
	SdMenuSetOffroad.Sd_HeilvlSign = l_Sd_HeilvlSign_u8;
	SdMenuSetOffroad.Sd_PitchAngle = l_Sd_PitchAngle_u8;
	SdMenuSetOffroad.Sd_PitchAngleSign = l_Sd_PitchAngleSign_u8;
	SdMenuSetOffroad.Sd_GeoGraphic = l_Sd_GeoGraphic_u8;
	SdMenuSetOffroad.Sd_SteerWheel = l_Sd_SteerWheel_u8;
	SdMenuSetOffroad.Sd_SteerWheelSign = l_Sd_SteerWheelSign_u8;
}
#define Common_Normal_STOP_SEC_CODE
#include "Common_Normal_MemMap.h" 

/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/

