/**********************************************************************************************************
*                                                                                                         *
*                          CONFIDENTIAL NOBO CORPORATION                              					  *
*                                                                                                         *
* This is an unpublished work of authership, which contains trade secrets, created in 2020.               *
*                                                                                                         *
* NOBO Corporation owns all rights to this work and intends to maintain it in         					  *
* confidence to preserve its trade secret status.                                                         *
*                                                                                                         *
* NOBO Corporation reserves the right, under the copyright laws of China or those of  					  *
* any other country that may have jurisdiction, to protect this work as an unpublished work, in the event *
* of and inadvertent or deliberate unauthorized publication.                                              *
*                                                                                                         *
* NOBO Coporation also reserves its rights under all copyright laws to protect this   					  *
* work as a published work,when appropriate.                                                              *
*                                                                                                         *
* Those having access to this work may not copy it, use it, modify it or disclose the information         *
* contained in it without the written authorization of NOBO Corporation.             					  *
*                                                                                                         *
**********************************************************************************************************/

/**********************************************************************************************************
*File Name   : SWC_Config.c                                                                              *
*                                                                                                         *
*Description : Cconfig transmit to soc source file.                                                 *
*                                                                                                         *
*Author      : li yafei                                                                                 *
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



/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "SWC_IPC_Application.h"
#include "CConfig_Cfg.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Config.h"
#include "Com.h"
#include "VConfig.h"
#include <string.h> /* memset */
#include "IPC_ClusterApp.h"
#include "Rte_Common_Normal.h"



#define Common_Normal_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Common_Normal_MemMap.h"

static IPC_M2S_ClusterAppAPPConfigData_t ToSBUS_Config_Data;
static uint8 CconfigKind_400Bytes_data[sizeof(CconfigKind_400Bytes)];

#define Common_Normal_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Common_Normal_MemMap.h"
/**********************************************************************************************************
* Process Function Configuration 																		  *
**********************************************************************************************************/

#define Common_Normal_START_SEC_CODE
#include "Common_Normal_MemMap.h"

void SWC_Config_Entrance_Task(void);
void SWC_Config_Init_Task(void);
void SWC_Config_Send_IPC_Task(void);

/**********************************************************************************************************
*																										  *
*																										  *
*	Config Process Function  Definition																  *
*																										  *
*																										  *
**********************************************************************************************************/

void SWC_Config_Entrance_Task(void)
{
	// uint8 PowerVoltageSts = 0;
	SystemState_RecordType Power_State;
	uint8 u8PowerMode = 0;
	
	memcpy(&Power_State,Rte_IRead_Common_Normal_100msMainFunction_tiSR_Power_Out_SystemStateOut(),sizeof(SystemState_RecordType));
	//PowerVoltageSts = Power_State.s_PowerVoltage.state;
	u8PowerMode = Power_State.ClusterState;
		
    if ((SYSTEMSTATE_Cluster_ON == u8PowerMode) || (SYSTEMSTATE_Cluster_STANDBY == u8PowerMode))
    {			
        SWC_Config_Send_IPC_Task();
    }
    else
    {
        //do nothing  
    }
    
}

void SWC_Config_Init_Task(void)
{
	
}

void SWC_Config_Send_IPC_Task(void)
{
    IPC_M2S_ClusterAppAPPConfigData_t Cconfig_temp = SWC_DEFAULT_CCONFIG_TABLE;
    
#if 1
    
    if (E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(CconfigKind_400Bytes_data))
    {
        ToSBUS_Config_Data.Fast_Resp = (uint8)CConfig_GetConfig(CCONFIG_KIND_Fast_Resp,CconfigKind_400Bytes_data); 
        ToSBUS_Config_Data.DigitalRPM_Hysteresis = (uint16)CConfig_GetConfig(CCONFIG_KIND_DigitalRPM_Hysteresis,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.GasolineCoolant_C_point = (uint8)CConfig_GetConfig(CCONFIG_KIND_GasolineCoolant_C_point,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.GasolineCoolant_14_point = (uint8)CConfig_GetConfig(CCONFIG_KIND_GasolineCoolant_1_4_point,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.GasolineCoolant_12_point1 = (uint8)CConfig_GetConfig(CCONFIG_KIND_GasolineCoolant_1_2_point1,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.GasolineCoolant_12_point2 = (uint8)CConfig_GetConfig(CCONFIG_KIND_GasolineCoolant_1_2_point2,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.GasolineCoolant_4_point = (uint8)CConfig_GetConfig(CCONFIG_KIND_GasolineCoolant__4_point,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.GasolineCoolant_Redline_point = (uint8)CConfig_GetConfig(CCONFIG_KIND_GasolineCoolant_Redline_point,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.GasolineCoolant_H_point = (uint8)CConfig_GetConfig(CCONFIG_KIND_GasolineCoolant_H_point,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.DieselCoolant_C_point = (uint8)CConfig_GetConfig(CCONFIG_KIND_DieselCoolant_C_point,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.DieselCoolant_14_point = (uint8)CConfig_GetConfig(CCONFIG_KIND_DieselCoolant_1_4_point,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.DieselCoolant_12_point1 = (uint8)CConfig_GetConfig(CCONFIG_KIND_DieselCoolant_1_2_point1,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.DieselCoolant_12_point2 = (uint8)CConfig_GetConfig(CCONFIG_KIND_DieselCoolant_1_2_point2,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.DieselCoolant_34_point = (uint8)CConfig_GetConfig(CCONFIG_KIND_DieselCoolant_3_4_point,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.DieselCoolant_Redline_point = (uint8)CConfig_GetConfig(CCONFIG_KIND_DieselCoolant_Redline_point,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.DieselCoolant_H_point = (uint8)CConfig_GetConfig(CCONFIG_KIND_DieselCoolant_H_point,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.Fuel_Distime = (uint8)CConfig_GetConfig(CCONFIG_KIND_Fuel_Distime,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.Horizontal_data = (uint16)CConfig_GetConfig(CCONFIG_KIND_Horizontal_data,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.X = (uint8)CConfig_GetConfig(CCONFIG_KIND_X,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.Y = (uint8)CConfig_GetConfig(CCONFIG_KIND_Y,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.AVSBDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_AVSBDisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.AVSADisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_AVSADisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.TravelTimeADisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_TravelTimeADisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.TravelTimeBDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_TravelTimeBDisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.AFCADisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_AFCADisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.AFCBDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_AFCBDisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.IFCDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_IFCDisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.DigitalSpeedDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_DigitalSpeedDisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.TPMSDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_TPMSDisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.PHEV_HEVDTEDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_PHEV_HEVDTEDisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.MaxDisplayPHEVRange = (uint8)CConfig_GetConfig(CCONFIG_KIND_MaxDisplayPHEVRange,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.PHEVSOCDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_PHEVSOCDisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.RefreshRatePHEVSOC = (uint16)CConfig_GetConfig(CCONFIG_KIND_RefreshRatePHEVSOC,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.AvailablePowerDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_AvailablePowerDisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.MaxAvailablePower = (uint8)CConfig_GetConfig(CCONFIG_KIND_MaxAvailablePower,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.RefreshRateAvrgEgyCns = (uint16)CConfig_GetConfig(CCONFIG_KIND_RefreshRateAvrgEgyCns,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.AvrgEgyCnsDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_AvrgEgyCnsDisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.MaxvalueAvrgEgyCns = (uint16)CConfig_GetConfig(CCONFIG_KIND_MaxvalueAvrgEgyCns,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.RefreshRatemotorpower = (uint16)CConfig_GetConfig(CCONFIG_KIND_RefreshRatemotorpower,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.motorpowerDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_motorpowerDisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.RefreshRateEVSOC = (uint16)CConfig_GetConfig(CCONFIG_KIND_RefreshRateEVSOC,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.EVSOCDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_EVSOCDisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.RefreshRateEVDTE = (uint16)CConfig_GetConfig(CCONFIG_KIND_RefreshRateEVDTE,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.EVDTEDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_EVDTEDisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.MaxvalueEVDTE = (uint16)CConfig_GetConfig(CCONFIG_KIND_MaxvalueEVDTE,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.RefreshRateCurrent = (uint16)CConfig_GetConfig(CCONFIG_KIND_RefreshRateCurrent,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.EVCurrentDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_EVCurrentDisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.EVDrivDataARestTime = (uint8)CConfig_GetConfig(CCONFIG_KIND_EVDrivDataARestTime,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.RefreshRateEVAVS = (uint16)CConfig_GetConfig(CCONFIG_KIND_RefreshRateEVAVS,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.EVAVSMinDistanceThresh = (uint8)CConfig_GetConfig(CCONFIG_KIND_EVAVSMinDistanceThresh,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.EVAVSADisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_EVAVSADisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.EVAVSBDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_EVAVSBDisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.EVTravelTimeDisplayLimited = (uint64)CConfig_GetConfig(CCONFIG_KIND_EVTravelTimeDisplayLimited,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.EVTravelTimeADisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_EVTravelTimeADisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.EVTravelTimeBDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_EVTravelTimeBDisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.FD_003_CLOCK_ENABLE = (uint8)CConfig_GetConfig(CCONFIG_KIND_FD_003_CLOCK_ENABLE,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.FIXEDDISPLAY_1_ODO_ENABLE = (uint8)CConfig_GetConfig(CCONFIG_KIND_FIXEDDISPLAY_1_ODO_ENABLE,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.FD_009_DRIVE_MODE_2WD_ENABLE = (uint8)CConfig_GetConfig(CCONFIG_KIND_FD_009_DRIVE_MODE_2WD_ENABLE,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.DoortoRed_speedthreshold = (uint8)CConfig_GetConfig(CCONFIG_KIND_DoortoRed_speedthreshold,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.Doorallclosed_holdtime = (uint8)CConfig_GetConfig(CCONFIG_KIND_Doorallclosed_holdtime,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.Telltale_interrupt_display_time = (uint8)CConfig_GetConfig(CCONFIG_KIND_Telltaleinterruptdisplaytime,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.Telltale_polling_display_time = (uint8)CConfig_GetConfig(CCONFIG_KIND_Telltalepollingdisplaytime,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.DrivDataADisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_DrivDataADisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.DrivDataBDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_DrivDataBDisplayEnable,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.Adas_V1 = (uint16)CConfig_GetConfig(CCONFIG_KIND_V1,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.Adas_V2 = (uint16)CConfig_GetConfig(CCONFIG_KIND_V2,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.GasolineCoolant_Distime = (uint8)CConfig_GetConfig(CCONFIG_KIND_GasolineCoolant_Distime,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.DieselCoolant_Distime = (uint8)CConfig_GetConfig(CCONFIG_KIND_DieselCoolant_Distime,CconfigKind_400Bytes_data);
        ToSBUS_Config_Data.RefreshRateUrea = (uint16)CConfig_GetConfig(CCONFIG_KIND_RefreshRateUrea,CconfigKind_400Bytes_data);
		ToSBUS_Config_Data.GValue_Hysteresis = (uint8)CConfig_GetConfig(CCONFIG_KIND_GValue_Hysteresis,CconfigKind_400Bytes_data);
		ToSBUS_Config_Data.GValue_update_frequency = (uint16)CConfig_GetConfig(CCONFIG_KIND_GValue_update_frequency,CconfigKind_400Bytes_data);
    }
    else
    {
        //memcpy(&ToSBUS_Config_Data,&fhca_test,sizeof(IPC_M2S_ClusterAppAPPConfigData_t));
        ToSBUS_Config_Data = Cconfig_temp;
    }

#else
    ToSBUS_Config_Data = Cconfig_temp;
#endif

	Rte_Call_IPC_Send_IPC_Send((uint8)M2S_INTERNAL_CONFIG_UPLOAD,(uint8*)&ToSBUS_Config_Data,(uint16)sizeof(IPC_M2S_ClusterAppAPPConfigData_t),FALSE);
    //  if (memcmp(&ToSBUS_TT_Safety_status32,&ToSBUS_TT_Safety_status32_Pre,sizeof(ToSBUS_TT_Safety_status32)) != 0)
    // {
    //     IPC_M2S_ClusterAppAPPTT_Safety_Transmit(&ToSBUS_TT_Safety_status32);
    //     memcpy(&ToSBUS_TT_Safety_status32_Pre,&ToSBUS_TT_Safety_status32,sizeof(ToSBUS_TT_Safety_status32));
    // }


}

#define Common_Normal_STOP_SEC_CODE
#include "Common_Normal_MemMap.h"

























