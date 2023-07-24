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
#ifndef FUEL_API_PROCESS_H
#define FUEL_API_PROCESS_H

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Fuel_Api_Rte_Adapt.h"
#include "DevConfig.h"

#ifdef SWC_FUEL_ADAPT_B02
    #define FUEL_TANK_SINGLE_TYPE_EN
    #define FUEL_TANK_MULTIPLE_TYPE_EN
#elif defined SWC_FUEL_ADAPT_B03
    #define FUEL_TANK_SINGLE_TYPE_EN
    #define FUEL_TANK_MULTIPLE_TYPE_EN
#elif defined SWC_FUEL_ADAPT_B06

#elif defined SWC_FUEL_ADAPT_P03
   #define FUEL_TANK_SINGLE_TYPE_EN
  // #define FUEL_TANK_DUAL_TYPE_EN
#elif defined SWC_FUEL_ADAPT_P05
    #define FUEL_TANK_SINGLE_TYPE_EN
   // #define FUEL_TANK_MULTIPLE_TYPE_EN
   // #define FUEL_TANK_DUAL_TYPE_EN
#elif defined SWC_FUEL_ADAPT_A07
    #define FUEL_TANK_SINGLE_TYPE_EN

#elif defined SWC_FUEL_ADAPT_D01
    #define FUEL_TANK_SINGLE_TYPE_EN
#elif defined SWC_FUEL_ADAPT_D02
    #define FUEL_TANK_SINGLE_TYPE_EN
#elif defined SWC_FUEL_ADAPT_D03
    #define FUEL_TANK_SINGLE_TYPE_EN
    #define FUEL_TANK_MULTIPLE_TYPE_EN
#elif defined SWC_FUEL_ADAPT_P02
    #define FUEL_TANK_SINGLE_TYPE_EN
#elif defined SWC_FUEL_ADAPT_P01
    #define FUEL_TANK_SINGLE_TYPE_EN
#else

#endif

#ifdef FUEL_TANK_MULTIPLE_TYPE_EN
#include "SWC_Fuel_Multiple_Process.h"
#include "SWC_Fuel_Pkg_Multiple.h"
#endif

#ifdef FUEL_TANK_SINGLE_TYPE_EN
#include "SWC_Fuel_Single_Process.h"
#include "SWC_Fuel_Pkg_Single.h"
#endif 

#ifdef FUEL_TANK_DUAL_TYPE_EN
#include "SWC_Fuel_Dual_Process.h"
#include "SWC_Fuel_Pkg_Dual.h"
#endif 


/**********************************************************************************************************
*																								          *
*																								          *
*	              Type Definition																		  *
*																								          *
*																								          *
**********************************************************************************************************/
#define FUEL_LOG_INIT_BIT        	((uint8)0x01)
#define FUEL_LOG_EVENT_BIT  	    ((uint8)0x02)
#define FUEL_LOG_PERIOD_BIT  	    ((uint8)0x04)
#define FUEL_LOG_ERROR_BIT  	    ((uint8)0x08)
#define FUEL_LOG_EVENT_FAST_BIT     ((uint8)0x10)
#define FUEL_LOG_EVENT_SLOW_BIT     ((uint8)0x20)
#define FUEL_LOG_CODE_INIT_BIT      ((uint8)0x40)


#define FUEL_LOG_ERROR_TOLERANT_FAULT         ((uint8)0X01)
#define FUEL_LOG_ERROR_SAMPLE_KEYON           ((uint8)0X02)
#define FUEL_LOG_ERROR_IGN_OFF_FASTFILL       ((uint8)0X04)
#define FUEL_LOG_ERROR_IGN_ON_FASTFILL        ((uint8)0X08)

#define FUEL_TANK_A  		(0u) /* main fuel tank  */
#define FUEL_TANK_B  	    (FUEL_TANK_A+1u) /* auxiliary fuel tank */
#define FUEL_TANK_SUM    	(FUEL_TANK_B+1) /* auxiliary fuel tank */

/** 
 * [FUEL_RESISTOR_TBL_SIZE : All fuel systems, platform hardware and resistance lookup are unified]
 * @Author   shujunhua
 * @DateTime 2021/9/20-9:26:42
 * @param    48u                      [description]
 */
#define FUEL_RESISTOR_TBL_SIZE                    (48u)
#define FUEL_AD_RESISTOR_TBL   \
  {{(uint16)(117), (uint16)(3456u)},\
  {(uint16)(117 ) , (uint16)(100)  },\
  {(uint16)(218 ) , (uint16)(100)  },\
  {(uint16)(876u), (uint16)(500u)},/*50ohm   34L*/\
  {(uint16)(956u), (uint16)(560u)},/*56ohm    29L*/\
  {(uint16)(1044u),(uint16)(630u)},/*63ohm    28.5L*/\
  {(uint16)(1128u),(uint16)(700u)},/*70ohm    27.5L*/\
  {(uint16)(1185u),(uint16)(750u)},/*75ohm    27L*/\
  {(uint16)(1282u),(uint16)(840u)},/*84ohm    26L*/\
  {(uint16)(1372u),(uint16)(930u)},/*93ohm    25L*/\
  {(uint16)(1439u),(uint16)(1000u)},/*100ohm    24L*/\
  {(uint16)(1538u),(uint16)(1110u)},/*111ohm    23L*/\
  {(uint16)(1629u),(uint16)(1220u)},/*122ohm    22L*/\
  {(uint16)(1786u),(uint16)(1430u)},/*143ohm    21L*/\
  {(uint16)(1854u),(uint16)(1530u)},/*153ohm    20L*/\
  {(uint16)(1918u),(uint16)(1630u)},/*163ohm    19L*/\
  {(uint16)(1979u),(uint16)(1730u)},/*173ohm    18L*/\
  {(uint16)(2091u),(uint16)(1930u)},/*193ohm    17L*/\
  {(uint16)(2142u),(uint16)(2030u)},/*203ohm    16L*/\
  {(uint16)(2182u),(uint16)(2110u)},/*211ohm    15L*/\
  {(uint16)(2265u),(uint16)(2290u)},/*229ohm    14L*/\
  {(uint16)(2299u),(uint16)(2370u)},/*237ohm    13L*/\
  {(uint16)(2369u),(uint16)(2540u)},/*254ohm    12L*/\
  {(uint16)(2430u),(uint16)(2700u)},/*270ohm    11L*/\
  {(uint16)(2458u),(uint16)(2780u)},/*278ohm    10L*/\
  {(uint16)(2489u),(uint16)(2870u)},/*287ohm    9L*/\
  {(uint16)(2532u),(uint16)(3000u)},/*300ohm    8L*/\
  {(uint16)(2560u),(uint16)(3090u)},/*309ohm    7L*/\
  {(uint16)(2573u),(uint16)(3130u)},/*313ohm    6L*/\
  {(uint16)(2603u),(uint16)(3230u)},/*323ohm    5L*/\
  {(uint16)(2626u),(uint16)(3310u)},/*331ohm    4L*/\
  {(uint16)(2651u),(uint16)(3400u)},/*340ohm    3L*/\
  {(uint16)(2670u),(uint16)(3470u)},/*347ohm    2L*/\
  {(uint16)(2678u),(uint16)(3500u)},/*350ohm    1L*/\
  {(uint16)(2798u),(uint16)(4000u)},/*400ohm    1L*/\
  {(uint16)(2901u),(uint16)(4500u)},/*450ohm    1L*/\
  {(uint16)(2987u),(uint16)(5000u)},/*500ohm    1L*/\
  {(uint16)(3062u),(uint16)(5500u)},/*550ohm    1L*/\
  {(uint16)(3128u),(uint16)(6000u)},/*600ohm    1L*/\
  {(uint16)(3186u),(uint16)(6500u)},/*650ohm    1L*/\
  {(uint16)(3237u),(uint16)(7000u)},/*700ohm    1L*/\
  {(uint16)(3283u),(uint16)(7500u)},/*750ohm    1L*/\
  {(uint16)(3324u),(uint16)(8000u)},/*800ohm    1L*/\
  {(uint16)(3362u),(uint16)(8500u)},/*850ohm    1L*/\
  {(uint16)(3396u),(uint16)(9000u)},/*900ohm    1L*/\
  {(uint16)(3426u),(uint16)(9500u)},/*950ohm    1L*/\
  {(uint16)(3455u),(uint16)(10000)},/*1000ohm  1L*/\
  {(uint16)(3456u),(uint16)(65535u)}}\



typedef enum
{		
	FUEL_LOG_SYS_COLD=0	,
	FUEL_LOG_SYS_WARM ,
	FUEL_LOG_SYS_IGN_OFF,
	FUEL_LOG_SYS_IGN_ON,
	FUEL_LOG_SYS_SLEEP,
}FUEL_LOG_SYS_STATUS;
    
typedef enum
{		
	Fuel_LOG_TASK_INIT=0	,
	Fuel_LOG_TASK_EVENT	 ,
	Fuel_LOG_TASK_PERIOD,
	Fuel_LOG_TASK_ERROR,
	Fuel_LOG_TASK_MAX,
}FUEL_LOG_TASK_ENUM;
   


typedef enum
{	
	Fuel_TYPE_NONE =0,
	Fuel_SINGE_TYPE	,
	Fuel_MULTI_TYPE	,
	Fuel_DUAL_SINGLE_TYPE	,
}Fuel_TANK_CFG_ENUM;



typedef enum
{	
    Fuel_Error_Gasoline_Low   ,
    Fuel_Error_Gasoline_High  ,
    Fuel_Error_Detect_Time    ,
    Fuel_Error_Recover_Time   ,
    Fuel_Refuel_Delaytime     ,
    Fuel_Ref_Time             ,
    Fuel_Refuel_Speed         ,
    Fuel_Halt_Speed           ,
    Fuel_Damp_lowfuel_a         ,
    Fuel_Damp_lowfuel_b         ,
    Fuel_Damp_run_fuelup_a      ,
    Fuel_Damp_run_fueldown_a    ,
    Fuel_Damp_run_fuelup_b      ,
    Fuel_Damp_run_fueldown_b    ,
    Fuel_Fuel_Distime         ,
    Fuel_Refuel_Conf_Time     ,
    Fuel_RefuelDamping2_a       ,
    Fuel_RefuelDamping2_b       ,
    Fuel_Damp_idle_a            ,
    Fuel_Damp_idle_b            ,
    Fuel_Low_Fueldetecttime   ,
    Fuel_LowFuelReleasetime  ,
    Fuel_IFC_Avg_Conf_Time    ,
    Fuel_Lfw_Trigger_a,
    Fuel_Lfw_Release_a,
    Fuel_Lfw_Trigger_b,
    Fuel_Lfw_Release_b,
    Fuel_Refuel_Trigger_a,
    Fuel_Refuel_Trigger_b,
    Fuel_Exception_Volume_a,
    Fuel_Exception_Volume_b,
}Fuel_TANK_C_CONFIG_ENUM;
    

typedef struct
{	
	uint16 Fuel_lfw_trigger_pecent[FUEL_TANK_SUM];
	uint16 Fuel_lfw_release_pecent[FUEL_TANK_SUM];
}Fuel_Lfw_t ;

typedef struct
{
    uint16 *table;
    uint16  table_size;
}Fuel_Vhr_CFG_table_t;

typedef struct
{
    uint16 *table_a;
    uint16  table_size_a;
    uint16 *table_b;
    uint16  table_size_b;
}Fuel_Muti_Vhr_CFG_table_t;

typedef struct
{
    uint16 *table_a;
    uint16  table_size_a;
    uint16 *table_b;
    uint16  table_size_b;
}Fuel_Duti_Vhr_CFG_table_t;

typedef struct
{
	/* short or open error threshold */
	uint16 Error_Gasoline_Low_NvmInit;     	/* 10oum */
	uint16 Error_Gasoline_High_NvmInit;	   	/* 1000oum */
	uint16 Error_Detect_Time_NvmInit;	   	/* 20S */
	uint16 Error_Recover_Time_NvmInit;     	/* 20S */
	
	uint16 Refuel_Delaytime_NvmInit;	   	/* 2S */
	uint16 Ref_Time_NvmInit;	   			/* 6S */
	uint16 Refuel_Speed_NvmInit;			/* 0.2km/h */
	uint16 Halt_Speed_Time_NvmInit;			/* 1km/h */

	uint16 Damp_lowfuel_NvmInit;			/* 0.04L/S */
	uint16 Damp_run_fuelup_NvmInit;			/* 0.04L/S */
	uint16 Damp_run_fueldown_NvmInit;		/* 0.04L/S */
	uint16 Refuel_Conf_Time_NvmInit; 		/* 3S */	
	uint16 RefuelDamping2_NvmInit;			/* 0.5S/L */
	uint16 Damp_idle_NvmInit; 				/* 0.0025L/S */
	
	uint16 Low_Fuel_detect_time_NvmInit;	/* 20S */
	uint16 Low_Fuel_release_time_NvmInit;	/* 20S */	
	uint16 IFC_Avg_Conf_Time_NvmInit;		/* 10S */

	uint16 Refuel_Trigger_NvmInit;			/* according to fuel tank cfg */
	uint16 Exception_Volume_NvmInit;		/* 40L */
	uint16 LFW_Trigger_NvmInit;				/* according to fuel tank cfg */
	uint16 LFW_Release_NvmInit; 		  	/* according to fuel tank cfg */

    uint16 LFW_Trigger_Dual_NvmInit[2];		/* for dual singel tank */
	uint16 LFW_Release_Dual_NvmInit[2];     /*  for dual singel tank */
    uint16 Refuel_Trigger_Dual_NvmInit[2];  /*  for dual singel tank */
	uint16 Exception_Volume_Dual_NvmInit[2]; /*  for dual singel tank */
}FUEL_MODULE_CCONFIG_DATA_NVM_STRUCT;

#define FUEL_EVENT_FAILED_THRSHOLD        (100u)
#define FUEL_EVENT_PASSED_THRSHOLD        (100u)
typedef enum
{	
	FUEL_SENSOR_ERROR_NONE	=0,
	FUEL_SENSOR_ERROR_OPEN	 ,
	FUEL_SENSOR_ERROR_SHORT	 ,
}Fuel_Sensor_Error_Enum;
    

typedef struct EventDebounce{
    Fuel_Sensor_Error_Enum eventStatus;
    uint8 monitorCounter;
    uint8 failedCounter;
	uint8 open_failedCounter;
	uint8 short_failedCounter;
    uint8 passedCounter;
}Fuel_EventDebounce_t;

typedef struct {
	uint8  	fuel_single_vspeed;
	uint16  fuel_display;
	uint16  fuel_percent;
	uint8  	fuel_fastfill;
	uint8  	fuel_shortopen;
	uint16  fuel_volume;
	uint16  fuel_ad;
	uint16  fuel_single_zss_ref;
	uint16  fuel_single_ignoff_ref;
	uint16  fuel_single_ignon_avgflps;
	uint16  fuel_single_rflps;
	uint16  fuel_single_rfuel;
	uint8  	fuel_single_warning;
}GAFUEL_DEBUG;

 typedef struct
 {
     uint16 Fuel_Log_period_res[2];
     uint8 Fuel_Log_period_ignonref[2];
     uint8 Fuel_Log_period_ignoffref[2];
     uint8 Fuel_Log_period_keyon[2];
     uint8 Fuel_Log_period_fips[2];
     uint8 Fuel_Log_period_percent;
 }Fuel_Log_Period_t ;

typedef struct
{
    Fuel_Log_Period_t Fuel_log_event_key_data;
    uint8 Fuel_log_event_Fast;
}Fuel_Log_Event_t ;

typedef struct
{
    uint8 Fuel_Log_Error_Sensor_Err;
    uint8 Fuel_Log_Error_keyonerr;
    uint8 Fuel_Log_Error_referr;
    Fuel_Log_Period_t Fuel_Log_Error_snapshot;
}Fuel_Log_Error_t ;


typedef struct
{
    uint8  Fuel_log_refuel_size[2];
    uint8  Fuel_log_exception_size[2];
    uint8  Fuel_log_trigger[2];
    uint8  Fuel_log_release[2];
    uint8  Fuel_log_tank_type;
    uint8  Fuel_log_version_single;
    uint8  Fuel_log_version_multiple;
    uint8  Fuel_log_version_dual;
}Fuel_Log_CodeInitCfg_t;





#pragma ghs section bss=".buram"
 extern Fuel_config_t Fuel_Tank_Cfg_Diag;
#pragma ghs section bss=default


#define FUEL_TANK_CFG        (Fuel_Tank_Cfg_Diag.Fuel_config_tanktype )        /*get VR Tabe */
#define FUEL_TANK_PORT_CFG   (Fuel_Tank_Cfg_Diag.Fuel_config_Tankportposition) /*get Tank orifice direction */
#define FUEL_TANK_AUX_CFG    (Fuel_Tank_Cfg_Diag.Fuel_Vehicle_Config_ViceTank) /*get Tank Aux cfg */

//FUEL_CCONFIG_DATA_NVM_STRUCT Fuel_Module_CConfig_Data_Nvm;

#define SWC_FUEL_START_SEC_VAR_RETENTION
#include "SWC_Fuel_MemMap.h"

extern GAFUEL_DEBUG Fuel_Single_Api_FuelInfo;


#define SWC_FUEL_STOP_SEC_VAR_RETENTION
#include "SWC_Fuel_MemMap.h"


#define SWC_FUEL_START_SEC_CONST_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"

//extern const uint16 Fuel_Single_Api_Resisitor_Table[FUEL_SINGLE_AD_RESISTOR_TBL_SIZE][2];
extern const uint16 Fuel_Resisitor_Table[FUEL_RESISTOR_TBL_SIZE][2];

//extern const uint16 Fuel_Single_Display_Table_Common_N01[FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N01][2];
//extern const uint16 Fuel_Single_Display_Table_Common_N02[FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N02][2];
//extern const uint16 Fuel_Single_Display_Table_Common_N03[FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N03][2];
//extern const uint16 Fuel_Single_Display_Table_Common_N04[FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N04][2];
//extern const uint16 Fuel_Single_Display_Table_Common_N05[FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N05][2];
//extern const uint16 Fuel_Single_Display_Table_Common_N07[FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N07][2];
//extern const uint16 Fuel_Single_Display_Table_Common_N08[FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N08][2];
//extern const uint16 Fuel_Single_Display_Table_Common_N09[FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N09][2];

//extern const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO1[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N01][2];
//extern const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO2[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N02][2];
//extern const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO3[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N03][2];
//extern const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO4[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N04][2];
//extern const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO5[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N05][2];
//extern const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO7[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N07][2];
//extern const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO8[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N08][2];
//extern const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO9[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N09][2];
// add it for independent double tank 
#ifdef FUEL_TANK_DUAL_TYPE_EN
//extern const uint16 Fuel_Dual_Display_A_Table[FUEL_DUAL_NUM_FUEL_DISPALY_TBL][FUEL_DUAL_DISPALY_TBL_SIZE][2] ;
//extern const uint16 Fuel_Dual_Display_B_Table[FUEL_DUAL_NUM_FUEL_DISPALY_TBL][FUEL_DUAL_DISPALY_TBL_SIZE][2] ;
//extern const uint16 FUEL_DUAL_SENDER_A_TABLE_NVM[FUEL_DUAL_SINGLE_INDEX_MAX-FUEL_DUAL_SINGLE_INDEX_DEFAULT][FUEL_DUAL_SENDER_A_AD_TO_PF_TBL_N0_SIZE][2];
//extern const uint16 FUEL_DUAL_SENDER_B_TABLE_NVM[FUEL_DUAL_SINGLE_INDEX_MAX-FUEL_DUAL_SINGLE_INDEX_DEFAULT][FUEL_DUAL_SENDER_A_AD_TO_PF_TBL_N0_SIZE][2] ;
#endif 

#define SWC_FUEL_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"


/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_FUEL_START_SEC_CODE
#include "SWC_Fuel_MemMap.h"
//#define FUEL_TIME_CAL
/** 
 * [Fuel_Api_ColdInit include fuel module cold and warm init ]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:03:14+0800
 * @param    void                     [description]
 */
void Fuel_Api_ColdInit(void);
/** 
 * [Fuel_Api_WarmInit : fuel module warm init]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:50:07+0800
 * @param    void                     [description]
 */
void Fuel_Api_WarmInit(void);
/** 
 * [Fuel_Api_Trans_Out_Normal : Power is switched off from normal mode]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:50:01+0800
 * @param    void                     [description]
 */
#if 0
void Fuel_Api_Trans_Out_Normal(void);
#endif
/** 
 * [Fuel_Api_Trans_Into_Abnormal : The power supply switches from normal mode to abnormal high and low voltage undervoltage mode]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:49:53+0800
 * @param    void                     [description]
 */
void Fuel_Api_Trans_Into_Abnormal(void);
/** 
 * [Fuel_Api_Get_Warning_Fuel : Provide fuel short circuit and low fuel alarm status]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:49:47+0800
 * @param    void                     [2 - FLASH, 1 - ON, 0 - OFF   ]
 */
uint8 Fuel_Api_Get_Warning_Fuel(void);
/** 
 * [Fuel_Api_Set_Warning_Fuel : SWC-RTE-SR-Update Fuel_Status_Fuel_Status]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:49:35+0800
 * @param    fuel_warning_set_status  [2 - FLASH, 1 - ON, 0 - OFF]
 */
void Fuel_Api_Set_Warning_Fuel(uint8 fuel_warning_set_status);
/** 
 * [Fuel_Api_Get_Sensor_Error_Status : Get fuel for malfunction, open circuit or short circuit]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:49:22+0800
 * @param    void                     [description]
 * @return   boolean                  [True:fault]
 */
boolean Fuel_Api_Get_Sensor_Error_Status(void);
/** 
 * [Fuel_Api_Main_Task : Fuel cycle 100ms main task]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:50:18+0800
 * @param    void                     [description]
 */
void Fuel_Api_Main_Task(void);
/** 
 * [Fuel_Api_Get_Finished_Init : Key ON completion of fuel initialization process]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:50:25+0800
 * @param    void                     [description]
 * @return   boolean                  [True:complete init]
 */
boolean Fuel_Api_Get_Finished_Init(void);
/** 
 * [Fuel_Api_Get_FastFill_Status : Fuel fast mode,eg fill or loss or fault]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:50:31+0800
 * @param    void                     [description]
 * @return   uint8                    [description]
 */
uint8 Fuel_Api_Get_FastFill_Status(void);
/** 
 * [Fuel_Api_Get_VehRunning_State : speed >= 0.2km/h exit fastfill mode]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T14:26:16+0800
 * @param    void                     [description]
 * @return   uint8                    [0ï¼šSPD>0.2 ]
 */
uint8 Fuel_Api_Get_VehRunning_State (void);
/** 
 * [Fuel_Api_Get_VehHalt_State : Check SPD<=1KM/H]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T14:31:26+0800
 * @param    void                     [description]
 * @return   uint8                    [0:SPD<=1KM/H]
 */
uint8 Fuel_Api_Get_VehHalt_State (void);
/** 
 * [Fuel_Api_Get_EngSpd_State : Check EngSpd â‰? 400rpm]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T14:32:11+0800
 * @param    void                     [description]
 * @return   uint8                    [1:EngSpd â‰? 400rpm]
 */
uint8 Fuel_Api_Get_EngSpd_State (void);
/** 
 * [Fuel_Api_Get_Power_Mode_State : Get IGN ON Status]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T14:38:07+0800
 * @param    void                     [description]
 * @return   uint8                    [1:IGN ON ]
 */
uint8 Fuel_Api_Get_Power_Mode_State (void);
/** 
 * [Fuel_Api_Get_Voltage_Mode_State : Check - 6.5 V <=V batt <=19V]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T15:01:07+0800
 * @param    void                     [description]
 * @return   uint8                    [1ï¼?6.5 V <=V batt <=19V]
 */
uint8 Fuel_Api_Get_Voltage_Mode_State (void);
/** 
 * [Fuel_Api_Get_Fuel_AD_Value : Obtain the AD value of two sensors,The accuracy of AD is 12 bits]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:51:24+0800
 * @param    fuel_ad_channel          [0:main sensor;1:aux sensor]
 * @return   uint16                   [Invalid :0XFFFF]
 */
uint16 Fuel_Api_Get_Fuel_AD_Value (uint8 fuel_ad_channel);
/** 
 * [Fuel_Api_Get_Fuel_Resisitor_Value : Obtain the Resisitor value,factot:10 eg100=10Î© ]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:51:35+0800
 * @param    fuel_ad_channel          [0:main sensor;1:aux sensor]
 * @return   uint16                   [Invalid :0XFFFF open or short]
 */
uint16 Fuel_Api_Get_Fuel_Resisitor_Value(uint8 fuel_ad_channel);
/** 
 * [Fuel_Api_Get_Fuel_Tank_Aux_Enable : Gets whether a relief tank configuration is available]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T15:51:44+0800
 * @param    void                     [description]
 * @return   boolean                  [TRUE:Enable]
 */
boolean Fuel_Api_Get_Fuel_Tank_Aux_Enable (void);
/** 
 * [Fuel_Api_Set_Module_Data : Update fuel RTE data]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:52:12+0800
 * @param    fuel_set_module_data     [description]
 */
void Fuel_Api_Set_Module_Data(FUEL_MODULE_OUTPUT_DATA_STRUCT fuel_set_module_data);
/** 
 * [Fuel_Api_Current_Module_Status :  For $22 -DID-FDC5 Current fuel module status]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T16:11:18+0800
 * @param    void                     [description]
 * @return   uint8                    [ 1: First power on
                                        2: Fast mode
                                        3: Slow mode]
 */
uint8 Fuel_Api_Current_Module_Status(void);
/** 
 * [Fuel_Api_Current_Module_Ref_Fuel_Level : For $22 -DID-FDC5 Current fuel reference value]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:52:52+0800
 * @param    void                     [description]
 * @return   uint8                    [Unit:1L]
 */
uint8 Fuel_Api_Current_Module_Ref_Fuel_Level(void);
/** 
 * [Fuel_Api_Module_Flps_Fuel_Level : For $22 -DID-FDC5 Current Main_fuel Real-time sampling value]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:53:06+0800
 * @param    void                     [description]
 * @return   uint8                    [Unit:1L]
 */
uint8 Fuel_Api_Module_Flps_Fuel_Level(void);
/** 
 * [Fuel_Api_Module_Flps_Aux_Fuel_Level : For $22 -DID-FDC5 Current Aux_fuel Real-time sampling value]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:53:17+0800
 * @param    void                     [description]
 * @return   uint8                    [Unit:1L]
 */
uint8 Fuel_Api_Module_Flps_Aux_Fuel_Level(void);
/** 
 * [Fuel_Api_Module_Fuel_Level_Volum_Read : For $22 -DID-FDC5 Current fuel Volum]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:53:31+0800
 * @param    void                     [description]
 * @return   uint8                    [Unit:1L]
 */
uint8 Fuel_Api_Module_Fuel_Level_Volum_Read(void);
/** 
 * [Fuel_Api_Module_Fast_Fill_Loss_Status : For $22 -DID-FDC5 Current fuel Refueling mark]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:53:48+0800
 * @param    void                     [description]
 * @return   uint8                    [0: Non-refueling mode
                                       1: refueling mode
                                       2: Oil spill mode    ]
 */
uint8 Fuel_Api_Module_Fast_Fill_Loss_Status(void);
/** 
 * [Fuel_Api_Config_Data_NVM_Init :Fuel module Cconfig init]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:04:02+0800
 * @param    void                     [description]
 */
void Fuel_Api_Config_Data_NVM_Init(void);

/** 
 * [Fuel_Api_Config_Data_NVM_Pkg_Get_Data : Fuel module Cconfig init for Key policy parameters]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T17:04:48+0800
 * @param    data_index               [See the configuration table for details]
 * @return   uint32                   [description]
 */
uint32 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(uint8 data_index);

/** 
 * [Fuel_Api_Get_SensorAorB_Status_Change When any state of the two sensors changes,the DTE module shall be notified to refresh]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:39:36+0800
 * @param    void                     [description]
 * @return   boolean                  [True:changes]
 */
boolean  Fuel_Api_Get_SensorAorB_Status_Change(void);
/** 
 * [Fuel_Api_tank_cfg_get : Distinguish between single float and double float]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:59:02+0800
 * @param    void                     [ Fuel_TYPE_NONE =0,
                                    	Fuel_SINGE_TYPE	,
                                    	Fuel_MULTI_TYPE	 ,]
 */
Fuel_TANK_CFG_ENUM Fuel_Api_tank_cfg_get(void);
/** 
 * [Fuel_api_u16_memset : Refactoring the memset function to implement 16-bit memory assignment]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:59:06+0800
 * @param    s                        [The object to which a pointer or array is assigned]
 * @param    c                        [The value that we're going to assign]
 * @param    count                    [The byte length of the assignment object]
 */
void *Fuel_api_u16_memset(void *s, uint16 c, uint32 count);
/** 
 * [Fuel_API_Get_Lfw_Percent : Calculate the percentage of trigger and Release points for each type of tank,eg 100=10%]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:59:14+0800
 * @param    void                     [description]
 */
Fuel_Lfw_t  Fuel_API_Get_Lfw_Percent(void);
/** 
 * [Fuel_API_Get_Lfw_Percent_Trigger : description]
 * @Author   shujunhua
 * @DateTime 2021/9/27-16:38:25
 * @param    index                    [description]
 * @return   uint16                   [description]
 */
uint16 Fuel_API_Get_Lfw_Percent_Trigger(uint8 index);

/** 
 * [Fuel_API_Get_Lfw_Percent_Release : description]
 * @Author   shujunhua
 * @DateTime 2021/9/27-16:44:57
 * @param    index                    [description]
 * @return   uint16                   [description]
 */
uint16 Fuel_API_Get_Lfw_Percent_Release(uint8 index);

/** 
 * [Fuel_Api_Tank_Vr_cfg_get : Gets the tank VHR parameters for the current configuration]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:58:42+0800
 * @param    void                     [     FUEL_VR_COMMMON_NONE =0,
                                        	FUEL_VR_COMMMON_SINGLE_NO1,
                                        	FUEL_VR_COMMMON_SINGLE_NO2,
                                        	FUEL_VR_COMMMON_SINGLE_NO3,
                                        	FUEL_VR_COMMMON_SINGLE_NO4,
                                        	FUEL_VR_COMMMON_SINGLE_NO5,
                                            FUEL_VR_COMMMON_SINGLE_MAX,
                                        	FUEL_VR_COMMMON_DUAL_NO1,
                                        	FUEL_VR_COMMMON_DUAL_NO2,
                                        	FUEL_VR_COMMMON_DUAL_NO3,
                                        	FUEL_VR_COMMMON_DUAL_NO4,
                                        	FUEL_VR_HIGH_VOLT_SINGLE_NO1,]
 */
FUEL_VR_TYPE_ENUM Fuel_Api_Tank_Vr_cfg_get(void);
/** 
 * [Fuel_Api_Abs : Reconstructed absolute value function]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:48:33+0800
 * @param    c                        [description]
 * @return   sint32                   [description]
 */
sint32 Fuel_Api_Abs(sint32 c);
/** 
 * [Fuel_API_Get_Tank_Size :Obtain the total volume of a single tank]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:37:33+0800
 * @param    void                     [description]
 * @return   uint8                    [Unit:1L]
 */
uint8 Fuel_API_Single_Get_Tank_Size(void);
/** 
 * [Fuel_API_Get_Tank_Dead : Gets the size of the dead oil zone under a single tank]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:48:58+0800
 * @param    void                     [description]
 * @return   uint16                   [Unit:ml]
 */
uint16 Fuel_API_Single_Get_Tank_Dead(void);

/** 
 * [Fuel_API_Muti_Get_Tank_Size : Obtain the total volume of a muti tank]
 * @Author   shujunhua
 * @DateTime 2021/5/8-16:28:17
 * @param    void                     [description]
 * @return   uint8                    [description]
 */
uint8 Fuel_API_Muti_Get_Tank_Size(void);
/** 
 * [Fuel_API_Muti_Get_Tank_Dead : Gets the size of the dead oil zone under a muti tank]
 * @Author   shujunhua
 * @DateTime 2021/5/8-16:28:21
 * @param    void                     [description]
 * @return   uint16                   [description]
 */
uint16 Fuel_API_Muti_Get_Tank_Dead(void);
/** 
 * [Fuel_API_Muti_Aux_Get_Tank_Size : Gets  the Aux volume of a muti tank]
 * @Author   shujunhua
 * @DateTime 2021/5/9-9:11:42
 * @param    void                     [description]
 * @return   uint8                    [description]
 */
uint8 Fuel_API_Muti_Aux_Get_Tank_Size(void);
/** 
 * [Fuel_Api_Dual_Get_Tank_Size : description]
 * @Author   shujunhua
 * @DateTime 2021/9/29-13:15:58
 * @param    index                    [description]
 * @return   uint8                    [description]
 */
uint8 Fuel_Api_Dual_Get_Tank_Size(uint8 index);
/** 
 * [Fuel_API_Dual_Get_A_Tank_Dead : description]
 * @Author   shujunhua
 * @DateTime 2021/9/27-13:37:43
 * @param    chanel                   [description]
 * @return   uint16                   [description]
 */
uint16 Fuel_API_Dual_Get_Tank_Dead(uint8 index);

/** 
 * [Fuel_API_Single_Get_Lfw_Percent_Trigger : description]
 * @Author   shujunhua
 * @DateTime 2021/9/29-11:27:03
 * @param    void                     [description]
 * @return   uint16                   [description]
 */
uint16 Fuel_API_Single_Get_Lfw_Percent_Trigger(void);
/** 
 * [Fuel_API_Muti_Get_Lfw_Percent_Trigger : description]
 * @Author   shujunhua
 * @DateTime 2021/9/29-11:27:08
 * @param    void                     [description]
 * @return   uint16                   [description]
 */
uint16 Fuel_API_Muti_Get_Lfw_Percent_Trigger(void);
/** 
 * [Fuel_API_Single_Get_Lfw_Percent_Release : description]
 * @Author   shujunhua
 * @DateTime 2021/9/29-11:27:40
 * @param    void                     [description]
 * @return   uint16                   [description]
 */
uint16 Fuel_API_Single_Get_Lfw_Percent_Release(void);
/** 
 * [Fuel_API_Muti_Get_Lfw_Percent_Release : description]
 * @Author   shujunhua
 * @DateTime 2021/9/29-11:27:44
 * @param    void                     [description]
 * @return   uint16                   [description]
 */
uint16 Fuel_API_Muti_Get_Lfw_Percent_Release(void);


/** 
 * [Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual : description]
 * @Author   shujunhua
 * @DateTime 2021/10/8-14:45:55
 * @param    data_index               [description]
 * @return   uint32                   [description]
 */
uint32 Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_TANK_C_CONFIG_ENUM data_index);

/** 
 * [Fuel_Api_Get_Fuel_Volume : description]
 * @Author   shujunhua
 * @DateTime 2021/10/11-14:35:47
 * @param    void                     [description]
 * @return   uint32                   [description]
 */
uint32 Fuel_Api_Get_Fuel_Volume(void);





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

