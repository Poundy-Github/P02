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
**  Name:               SWC_Fuel_Pkg_Math.c
**
**  Description:        Implentation module for linear interpolation software.
**                     See comments below for more details.
**
** Organization:       
**
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef FUEL_API_ADAPT_H
#define FUEL_API_ADAPT_H

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "logger.h"
#include "Rte_Common_Normal.h"
#ifdef GWM_V35_PROJECT_TYPE_B02
    #define SWC_FUEL_ADAPT_B02
#elif defined GWM_V35_PROJECT_TYPE_B03
    #define SWC_FUEL_ADAPT_B03
#elif defined GWM_V35_PROJECT_TYPE_B06
    #define SWC_FUEL_ADAPT_B06    
#elif defined GWM_V35_PROJECT_TYPE_P03
    #define SWC_FUEL_ADAPT_P03
#elif defined GWM_V35_PROJECT_TYPE_P05
    #define SWC_FUEL_ADAPT_P05
#elif defined GWM_V35_PROJECT_TYPE_A07
    #define SWC_FUEL_ADAPT_A07    
#elif defined GWM_V35_PROJECT_TYPE_D01
    #define SWC_FUEL_ADAPT_D01
#elif defined GWM_V35_PROJECT_TYPE_D02
    #define SWC_FUEL_ADAPT_D02   
#elif defined GWM_V35_PROJECT_TYPE_D03
    #define SWC_FUEL_ADAPT_D03
#elif defined GWM_V35_PROJECT_TYPE_P02
    #define SWC_FUEL_ADAPT_P02
#elif defined GWM_V35_PROJECT_TYPE_P01
    #define SWC_FUEL_ADAPT_P01
#else
    #define SWC_FUEL_ADAPT_NULL
#endif 




/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
/**********************************************************************************************************
*																								          *
*																								          *
*	              Type Definition																		  *
*																								          *
*																								          *
**********************************************************************************************************/
/*
typedef struct
{
	uint8  Fuel_Fast_Fill_Status;
	uint8  Fuel_Init_Complete_Status;
	uint8  Fuel_Level_Display_Percent;
	uint8  Fuel_Level_Display_Segment;
	uint8  Fuel_Warning_Status;
	uint8  Fuel_Sensor_Error_Status;
	uint16 Fuel_Level_Calculate_Value;
	uint16 Fuel_Level_Display_Value;
	uint16 Fuel_Sensor_Raw_Value_A;
	uint16 Fuel_Sensor_Raw_Value_B;
}FUEL_MODULE_OUTPUT_DATA_STRUCT;
*/
// 项目代码
#define FUEL_PROJECTCODE_AC01           141u
#define FUEL_PROJECTCODE_ES21           27u
#define FUEL_PROJECTCODE_A01            28u
#define FUEL_PROJECTCODE_A02            4u
#define FUEL_PROJECTCODE_M81            5u
#define FUEL_PROJECTCODE_M82            113u
#define FUEL_PROJECTCODE_M83            114u
#define FUEL_PROJECTCODE_P01N_YY        0u
#define FUEL_PROJECTCODE_C04            75u
#define FUEL_PROJECTCODE_V61            11u
#define FUEL_PROJECTCODE_V62            12u
#define FUEL_PROJECTCODE_CC02           76u
#define FUEL_PROJECTCODE_V61PHEV        18u
#define FUEL_PROJECTCODE_V61PHEVG       77u
#define FUEL_PROJECTCODE_P01N_ZX        78u
#define FUEL_PROJECTCODE_EC03           79u
#define FUEL_PROJECTCODE_V51PHEV        80u
#define FUEL_PROJECTCODE_V51EVG         81u
#define FUEL_PROJECTCODE_V51EV          60u
#define FUEL_PROJECTCODE_V51            13u
#define FUEL_PROJECTCODE_V51_0          6u
#define FUEL_PROJECTCODE_B01_2          82u
#define FUEL_PROJECTCODE_P05_SY         83u
#define FUEL_PROJECTCODE_ES11G_1        106u
#define FUEL_PROJECTCODE_V71            7u
#define FUEL_PROJECTCODE_V71GT          8u
#define FUEL_PROJECTCODE_V71PHEV        9u
#define FUEL_PROJECTCODE_V71PHEVG       45u
#define FUEL_PROJECTCODE_A01B           14u
#define FUEL_PROJECTCODE_B04            15u
#define FUEL_PROJECTCODE_B06H           10u
#define FUEL_PROJECTCODE_B06            34u
#define FUEL_PROJECTCODE_B05            16u
#define FUEL_PROJECTCODE_P3011E         1u
#define FUEL_PROJECTCODE_P3021          29u
#define FUEL_PROJECTCODE_P3013          30u
#define FUEL_PROJECTCODE_P3011D         31u
#define FUEL_PROJECTCODE_P3011          17u
#define FUEL_PROJECTCODE_P3011T         46u
#define FUEL_PROJECTCODE_P3011G         32u
#define FUEL_PROJECTCODE_P3012          33u
#define FUEL_PROJECTCODE_EC11           20u
#define FUEL_PROJECTCODE_EC12           21u
#define FUEL_PROJECTCODE_MC11           22u
#define FUEL_PROJECTCODE_MS01           23u
#define FUEL_PROJECTCODE_B01            24u
#define FUEL_PROJECTCODE_B30PF          25u
#define FUEL_PROJECTCODE_B02            26u
#define FUEL_PROJECTCODE_EC24           3u
#define FUEL_PROJECTCODE_A30PF          35u
#define FUEL_PROJECTCODE_A01_0          36u
#define FUEL_PROJECTCODE_P3011F         37u
#define FUEL_PROJECTCODE_P3011G_H       19u
#define FUEL_PROJECTCODE_B16            135u
#define FUEL_PROJECTCODE_ES11G_2        121u
#define FUEL_PROJECTCODE_ES11           2u
#define FUEL_PROJECTCODE_CHK141         38u
#define FUEL_PROJECTCODE_P81PF          39u
#define FUEL_PROJECTCODE_P01            40u
#define FUEL_PROJECTCODE_F61            41u
#define FUEL_PROJECTCODE_F71            42u
#define FUEL_PROJECTCODE_P01_ZX         43u
#define FUEL_PROJECTCODE_D03_1G         134u    // D03 海外
#define FUEL_PROJECTCODE_P01_YY         44u
#define FUEL_PROJECTCODE_A01G           47u
#define FUEL_PROJECTCODE_P3011G_A       48u
#define FUEL_PROJECTCODE_A06            49u
#define FUEL_PROJECTCODE_A07            50u
#define FUEL_PROJECTCODE_B01G           51u
#define FUEL_PROJECTCODE_P02            52u
#define FUEL_PROJECTCODE_P3011D_A       53u
#define FUEL_PROJECTCODE_EC24_PHEV      54u
#define FUEL_PROJECTCODE_D01            55u
#define FUEL_PROJECTCODE_P03            56u
#define FUEL_PROJECTCODE_B03            57u
#define FUEL_PROJECTCODE_P01G           126u    // P01 海外
#define FUEL_PROJECTCODE_P04            107u
#define FUEL_PROJECTCODE_C01            62u
#define FUEL_PROJECTCODE_P03_1          71u
#define FUEL_PROJECTCODE_B01G_IND       68u
#define FUEL_PROJECTCODE_P01G_THA       127u
#define FUEL_PROJECTCODE_CHK141_1       111u
#define FUEL_PROJECTCODE_F71HEV         63u
#define FUEL_PROJECTCODE_P71PF          64u
#define FUEL_PROJECTCODE_B01G_THA       65u
#define FUEL_PROJECTCODE_P03_1G         112u
#define FUEL_PROJECTCODE_EC24B_ICE      84u
#define FUEL_PROJECTCODE_EC24B_RE300    85u
#define FUEL_PROJECTCODE_P03_1R         86u
#define FUEL_PROJECTCODE_V61_NA         87u
#define FUEL_PROJECTCODE_P03_YY         73u
#define FUEL_PROJECTCODE_P03_1IND       88u
#define FUEL_PROJECTCODE_B06_1          89u
#define FUEL_PROJECTCODE_P05_CY         74u
#define FUEL_PROJECTCODE_P05_YY         69u
#define FUEL_PROJECTCODE_P05_DP         70u
#define FUEL_PROJECTCODE_EC24_700       90u
#define FUEL_PROJECTCODE_P06            91u
#define FUEL_PROJECTCODE_D02            92u
#define FUEL_PROJECTCODE_V71DHT         93u
#define FUEL_PROJECTCODE_P03_XDL        72u
#define FUEL_PROJECTCODE_D03            94u
#define FUEL_PROJECTCODE_B01_1          58u
#define FUEL_PROJECTCODE_B07            96u
#define FUEL_PROJECTCODE_A08            97u
#define FUEL_PROJECTCODE_EC24_1         98u
#define FUEL_PROJECTCODE_ES11_1         99u
#define FUEL_PROJECTCODE_C02            100u
#define FUEL_PROJECTCODE_ES24           101u
#define FUEL_PROJECTCODE_ES13           102u
#define FUEL_PROJECTCODE_C03            103u
#define FUEL_PROJECTCODE_V72            104u
#define FUEL_PROJECTCODE_DE07           148u
#define FUEL_PROJECTCODE_P02_1          105u
#define FUEL_PROJECTCODE_P05_CY_THA     116u
#define FUEL_PROJECTCODE_P05G_CY        117u
#define FUEL_PROJECTCODE_P05_DP_THA     118u
#define FUEL_PROJECTCODE_P05_YY_THA     119u
#define FUEL_PROJECTCODE_P05G_YY        120u
#define FUEL_PROJECTCODE_V71_1          122u
#define FUEL_PROJECTCODE_V51EVR         125u
#define FUEL_PROJECTCODE_B01G_1         136u
#define FUEL_PROJECTCODE_B03G           115u
#define FUEL_PROJECTCODE_V61_1          124u
#define FUEL_PROJECTCODE_V71_2          123u
#define FUEL_PROJECTCODE_D01G           132u    // D01 海外
#define FUEL_PROJECTCODE_A05            137u
#define FUEL_PROJECTCODE_EC24GL         146u
#define FUEL_PROJECTCODE_EC24GR         147u
#define FUEL_PROJECTCODE_DE04           140u
#define FUEL_PROJECTCODE_P03_THA        129u
#define FUEL_PROJECTCODE_P05_CY_BRA     130u
#define FUEL_PROJECTCODE_P05_YY_BRA     131u
#define FUEL_PROJECTCODE_CC03           142u
#define FUEL_PROJECTCODE_CC04           143u
#define FUEL_PROJECTCODE_M81_1          149u
#define FUEL_PROJECTCODE_D02G           133u    // D02 国外
#define FUEL_PROJECTCODE_AC03           144u
#define FUEL_PROJECTCODE_P02G           128u
#define FUEL_PROJECTCODE_V61PHEV_1      139u
#define FUEL_PROJECTCODE_B16G           138u
#define FUEL_PROJECTCODE_BC04           145u

// 燃油类型
#define FUEL_TYPE_DIESEL              0u   // 柴油
#define FUEL_TYPE_GASOLINE            1u   // 汽油
#define FUEL_TYPE_GASOLINE_NATURAL    2u   // 汽油 + 天然气
#define FUEL_TYPE_HEV                 3u
#define FUEL_TYPE_PHEV                4u
#define FUEL_TYPE_EV                  5u
#define FUEL_TYPE_EV_NATURAL          6u   // EV + 天然气
#define FUEL_TYPE_NATURAL             7u   // 天然气
#define FUEL_TYPE_BATTERYPACK         8u   // 燃料电池
#define FUEL_TYPE_BATTERYPACK_HEV     9u   // 燃料电池 + HEV
#define FUEL_TYPE_BATTERYPACK_PHEV    10u  // 燃料电池 + PHEV

// 发动机控制单元
#define FUEL_ENG_DIESEL_Dr            3u   // 博世-柴油
#define FUEL_ENG_DIESEL_Dr_CB18       4u   // 博世- CB18 -柴油
#define FUEL_ENG_DIESEL_DELPHI        5u   // 德尔福-柴油
#define FUEL_ENG_DIESEL_NEW_TREND     7u   // 新风-柴油
#define FUEL_ENG_NONE                 0u   // NONE
#define FUEL_ENG_GASOLINE_UAES        1u   // 联电-汽油
#define FUEL_ENG_GASOLINE_SIEMENS     2u   // 西门子-汽油
#define FUEL_ENG_GASOLINE_DELPHI      6u   // 德尔福-汽油

typedef FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE  FUEL_MODULE_OUTPUT_DATA_STRUCT;

typedef enum
{
	Fuel_IP_FuelLvlLowLmpSts =0u,
	Fuel_IP_FuelLvlInfo,
	Fuel_IP_FuelLvlInfoAux,
	Fuel_IP_FuelMainTankR,
	Fuel_IP_FuelAuxTankR,
	Fuel_TC_IP_CANOUT_Max,
}Fuel_IP_PUBLISH_ENUM;

typedef enum
{
	FUEL_SENSOR1_OPEN = 0u,
	FUEL_SENSOR1_SHORT,
	FUEL_SENSOR2_OPEN,
	FUEL_SENSOR2_SHORT,
}FUEL_SENSOR_ERROR_ENUM;

typedef enum
{
    FUEL_VR_COMMMON_NONE =0u,
	FUEL_VR_COMMMON_SINGLE_NO1,
	FUEL_VR_COMMMON_SINGLE_NO2,
	FUEL_VR_COMMMON_SINGLE_NO3,
	FUEL_VR_COMMMON_SINGLE_NO4,
	FUEL_VR_COMMMON_SINGLE_NO5,
	FUEL_VR_COMMMON_SINGLE_NO7,
	FUEL_VR_COMMMON_SINGLE_NO8,
	FUEL_VR_COMMMON_SINGLE_NO9,
    FUEL_VR_COMMMON_SINGLE_MAX,
	FUEL_VR_COMMMON_DUAL_NO1,           // 常规双浮子油箱一
	FUEL_VR_COMMMON_DUAL_NO2,           // 常规双浮子油箱二
	FUEL_VR_COMMMON_DUAL_NO3,           // 常规双浮子油箱三
	FUEL_VR_COMMMON_DUAL_NO4,           // 常规双浮子油箱四
	FUEL_VR_COMMMON_DUAL_MAX,
	FUEL_VR_COMMMON_DUAL_SINGEL_N01,
	FUEL_VR_COMMMON_DUAL_SINGEL_MAX,
	FUEL_VR_HIGH_VOLT_SINGLE_NO1,       // 高压单浮子油箱一
}FUEL_VR_TYPE_ENUM;

typedef struct
{
	FUEL_VR_TYPE_ENUM Fuel_config_tanktype;
	uint8 Fuel_config_Tankportposition;
    uint8 Fuel_Vehicle_Config_ViceTank;
}Fuel_config_t ;


typedef enum
{
	FUEL_DUAL_SINGLE_INDEX_DEFAULT =0u,
	FUEL_DUAL_SINGLE_INDEX_MAX,
}Fuel_DUAL_SINGLE_INDEX_TYPE_ENUM;



#define FUEL_DEBUG_SWITCH    1u

#if (FUEL_DEBUG_SWITCH==1u)
   #define FUEL_MODULE_DEBUG(...)               fuel_info(__VA_ARGS__);
   #define FUEL_MODULE_WARN(...)                fuel_warn(__VA_ARGS__);
   #define FUEL_MODULE_ERROR(...)               fuel_err(__VA_ARGS__);
#else
   #define FUEL_MODULE_DEBUG(...)
   #define FUEL_MODULE_WARN(...)
   #define FUEL_MODULE_ERROR(...)

#endif




/*************************************************************************  
 * [FUEL_AD_MIN : The Resisitor is less than 10ohm ]
 * [FUEL_AD_MAX : The Resisitor more than 1000ohm ]
 * @Author   zhangbeicheng
 * @DateTime 2021/7/8-9:39:04
 *************************************************************************/
#define FUEL_AD_MIN 218u
#define FUEL_AD_MAX 3455u


/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_FUEL_START_SEC_CODE
#include "SWC_Fuel_MemMap.h"
/**********************************************************************************************************
*Function   : Fuel_Rte_Api_Get_Fuel_Tank_Cfg                                                              *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
Fuel_config_t Fuel_Rte_Api_Get_Fuel_Tank_Cfg(void);
/**********************************************************************************************************
*Function   : Fuel_RTE_Api_Get_Power_Mode_State                                                       	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-23                                                                                  *
**********************************************************************************************************/
boolean Fuel_Rte_Api_Get_Cconfig_Cfg(CconfigKind_400Bytes Lcal_config);
/**********************************************************************************************************
*Function   : Fuel_RTE_Api_Get_Power_Mode_State                                                       	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 Fuel_Rte_Api_Get_Power_Mode_State (void);
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Voltage_Mode_State                                                       	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 Fuel_Rte_Api_Get_Voltage_Mode_State (void);
/**********************************************************************************************************
*Function   : Fuel_Rte_Api_Get_Power_Mode_State_Is_Sleep                                              	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-28                                                                                  *
**********************************************************************************************************/
boolean Fuel_Rte_Api_Get_Power_Mode_State_Is_Sleep(void);

/**********************************************************************************************************
*Function   : TC_RTE_API_Get_VehRunning_State                                                       	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 Fuel_Rte_Api_Get_VehRunning_State (void);
uint8 Fuel_Rte_Api_Get_VehHalt_State (void);

/**********************************************************************************************************
*Function   : TC_RTE_API_Get_EngSpd_State                                                           	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 Fuel_Rte_Api_Get_EngSpd_State (void);
/**********************************************************************************************************
*Function   : Fuel_Rte_Api_Get_Fuel_AD_Value                                                          	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint16 Fuel_Rte_Api_Get_Fuel_AD_Value (uint8 fuel_ad_channel);
/**********************************************************************************************************
*Function   : Fuel_Rte_Api_Set_Warning_Fuel                                                               *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: 2 - FLASH, 1 - ON, 0 - OFF                                                                  *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
void Fuel_Rte_Api_Set_Warning_Fuel(uint8 fuel_warning_set_status);
/**********************************************************************************************************
*Function   : Fuel_Rte_Api_Set_Module_Data                                                                *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
void Fuel_Rte_Api_Set_Module_Data(FUEL_MODULE_OUTPUT_DATA_STRUCT fuel_set_module_data);
/**********************************************************************************************************
*Function   : SWC_API_RTE_EOL_HardInput_For_Cluster                                                       *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
void SWC_API_RTE_EOL_HardInput_For_Cluster(uint8            * data);
/**********************************************************************************************************
*Function   : Fuel_Rte_Api_Get_IFC_10S_Rate                                                           	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint16 Fuel_Rte_Api_Get_IFC_10S_Rate (void);
/**********************************************************************************************************
*Function   : Fuel_Api_Update_can_publish                                                                 *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-03                                                                                  *
**********************************************************************************************************/
void Fuel_Api_Update_can_publish(Fuel_IP_PUBLISH_ENUM type,uint32 data);
/**********************************************************************************************************
*Function   : Fuel_Api_Open_Or_Short_Dtc_Status                                                           *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-03                                                                                  *
**********************************************************************************************************/
void Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR_ERROR_ENUM index,uint32 status);
/**********************************************************************************************************
*Function   : Fuel_SWC_API_RTE_Diag_Read_Fuel_Data                                                        *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-04                                                                                  *
**********************************************************************************************************/
void Fuel_SWC_API_RTE_Diag_Read_Fuel_Data(uint8 * data);
/**********************************************************************************************************
*Function   : Fuel_Module_Rte_Coldinit_Warminit_Flag                                                  	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-17                                                                                  *
**********************************************************************************************************/
boolean Fuel_Module_Rte_Coldinit_Warminit_Flag (void);

uint16 Fuel_Api_Get_Fuel_Resisitor_Diag(uint8 fuel_ad_channel);
uint32 Fuel_Module_Rte_Diag_Dtc_Counter(void);
uint16 Fuel_Api_Rte_Get_Damp_run_fuelup(void);
uint16 Fuel_Api_Rte_Get_Damp_run_fueldown(void);
uint16 Fuel_Api_Rte_Get_Ref_Delta_A(void);
/** 
 * [Fuel_Dual_Api_Get_Tank_Config : description]
 * @Author   shujunhua
 * @DateTime 2021/9/23-16:27:56
 * @param                             [description]
 * @return   uint8                    [description]
 */
uint8 Fuel_Dual_Api_Get_Tank_Config( void );

uint16 Fuel_Api_Get_Ref_Delta_A(void);
/** 
 * [Fuel_Api_Rte_Get_Oil_Switch : description]
 * @Author   shujunhua
 * @DateTime 2021/10/28-13:10:22
 * @param    void                     [description]
 * @return   uint8                    [description]
 */
uint8 Fuel_Api_Rte_Get_Oil_Switch(void);


#define SWC_FUEL_STOP_SEC_CODE
#include "SWC_Fuel_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
**
**  Revision:      1.0  
**
**  2020/06/02     Original Version
**
**********************************************************************************************************/
#endif
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/

