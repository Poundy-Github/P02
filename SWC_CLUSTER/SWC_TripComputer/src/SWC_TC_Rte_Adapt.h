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
*File Name   : SWC_TC_Rte_Adapt.h                                                                             *
*                                                                                                         *
*Description : TripComputer module adaptation interface head file.                                        *
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

#ifndef TC_ADAPT_H
#define TC_ADAPT_H

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "logger.h"

#ifdef GWM_V35_PROJECT_TYPE_B02
    #define SWC_TC_ADAPT_B02
#elif defined GWM_V35_PROJECT_TYPE_B03
    #define SWC_TC_ADAPT_B03
#elif defined GWM_V35_PROJECT_TYPE_B06
    #define SWC_TC_ADAPT_B06
#elif defined GWM_V35_PROJECT_TYPE_P03
    #define SWC_TC_ADAPT_P03
#elif defined GWM_V35_PROJECT_TYPE_P05
    #define SWC_TC_ADAPT_P05
#elif defined GWM_V35_PROJECT_TYPE_A07
    #define SWC_TC_ADAPT_A07
#elif defined GWM_V35_PROJECT_TYPE_D01
    #define SWC_TC_ADAPT_D01
#elif defined GWM_V35_PROJECT_TYPE_D02
    #define SWC_TC_ADAPT_D02
#elif defined GWM_V35_PROJECT_TYPE_D03
    #define SWC_TC_ADAPT_D03
#elif defined GWM_V35_PROJECT_TYPE_P02
    #define SWC_TC_ADAPT_P02
#elif defined GWM_V35_PROJECT_TYPE_P01
    #define SWC_TC_ADAPT_P01
#else
    #define SWC_TC_ADAPT_NULL
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
#if 0
typedef struct
{
	/* AFE */
	uint16 u16AFE_1st_Display_Output_Data;	
	uint16 u16AFE_2st_Display_Output_Data;
	uint32 u32AFE_1st_Fuel_Trip_Value;
	uint32 u32AFE_1st_Fuel_Consumption_Value;
	uint32 u32AFE_2st_Fuel_Trip_Value;
	uint32 u32AFE_2st_Fuel_Consumption_Value;
	/* IFE */
	uint16 u16IFE_Calculate_Output_Data;	
	uint16 u16IFE_Display_Output_Data;
	uint32 u32IFE_Fuel_Trip_Value;
	uint32 u32IFE_Fuel_Consumption_Value;
	/*@20200923Inconsistency with the data structure defined by RTE 
	  causes the underlying data memory to be overwritten.
	  update RTE_ConfigurationV1.4.xlsx*/
	uint32 u32IFE_Fuel_Consumption_Can_Signal; 
	/* AVS */
	uint16 u16AVS_1st_Display_Output_Data;
	uint16 u16AVS_2st_Display_Output_Data;
	uint32 u32AVS_1st_Driving_Time_Value;
	uint32 u32AVS_2st_Driving_Time_Value;
	uint32 u32AVS_1st_Fuel_Trip_Value;
	uint32 u32AVS_2st_Fuel_Trip_Value;
	/* Drive Time */
	uint8  u8DrivingTime_1st_Display_Hour;
	uint8  u8DrivingTime_2st_Display_Hour;
	uint8  u8DrivingTime_1st_Display_Minute;
	uint8  u8DrivingTime_2st_Display_Minute;
	/* DTE */
	uint16 u16DTE_Fuel_Tank_Volume;	
	uint8  u8DTE_Fuel_Stage_Consumption;	
	uint16 u16DTE_Display_Output_Data;	
	uint16 u16DTE_Calculate_Output_Data;	
	uint16 u16SFC_Output_Data;	
	uint16 u16SFC_For_Fuel_Output_Data;	
	/* other used */
	uint8  u8IFC_Poc_Update;
	uint16 u16IFC_Poc_Calculate_Value;
	/* 1: 1/65535  ifc_10s/ifc_max */
	uint16 u16IFC_Poc_For_Fuel_Calculate_Rate;
}TC_MODULE_OUTPUT_DATA_STRUCT;
#endif 
typedef TC_MODULE_OUTPUT_DATA_STRUCT_RTE TC_MODULE_OUTPUT_DATA_STRUCT;

typedef struct
{
	uint32  u32_fuel_consume_value;
	uint16  u16_fuel_consume_rc;
}TC_FUEL_COMSUME_DATA_STRUCT;

typedef struct
{
	uint32 u32TC_StartTime;
	uint8  u8TC_TimeStatus;
}TC_OSTIMER_DATA_STRUCT;

typedef enum
{
	TC_RESET_ALL_DATA = 0,
	TC_RESET_1ST_DATA,
	TC_RESET_2ST_DATA
}TC_MODULE_RESET_DATA_INDEX;
typedef enum
{
	TC_Collect_Timer1 = 0,
	TC_TDT_Calculate_Timer2,
	TC_IFE_Calculate_Timer3,
	TC_AFE_Calculate_Timer4,
	TC_AVS_Calculate_Timer5,	
	TC_DTE_Calculate_Timer6,
	TC_DTE_Refresh_Timer7,
	TC_OS_TimerMax,
}TC_OSTIMER_NUMBER_ENUM;

typedef enum
{
	
	TC_IP_AvgFuelCons_A	=0,
	TC_IP_AvgFuelCons_B	 ,
	TC_IP_InstFuelConsUnit,
	TC_IP_InstFuelCons,	
	TC_IP_RemainDistance,
	TC_IP_AuxRemainDistance,
	TC_IP_CANOUT_Max,
}TC_IP_PUBLISH_ENUM;

typedef enum
{	
	TC_VEHICLE_NONE	=0,
    TC_VEHICLE_FUEL	 ,
    TC_VEHICLE_FUEL_DIESEL	 ,
    TC_VEHICLE_HEV	 ,
	TC_VEHICLE_PHEV	 ,
	TC_VEHICLE_EV,
}TC_VEHICLE_TYPE_ENUM;

typedef enum
{	
	TC_UINT_KM	=0,
	TC_UINT_KM_JP,
	TC_UINT_KM_UK,
	TC_UINT_KM_US,
}TC_UINT_TYPE_ENUM;
    
typedef enum
{	
	TC_VEHICLE_CHARGE_DEFAULT	=0,
	TC_VEHICLE_CHARGE_CHARGING,
	TC_VEHICLE_CHARGE_DELAYING,
	TC_VEHICLE_CHARGE_COMPLETE,
    TC_VEHICLE_CHARGE_STOPED,
    TC_VEHICLE_CHARGE_INIT,
    TC_VEHICLE_CHARGE_HEATING,
    TC_VEHICLE_CHARGE_CHARGE_HEATING,
}TC_VEHICLE_CHARGE_TYPE_ENUM;

typedef enum
{	TC_VEHICLE_MOTOR_NONE=0,
	TC_VEHICLE_MOTOR_P0	,
    TC_VEHICLE_MOTOR_P2	 ,
	TC_VEHICLE_MOTOR_P4  ,
	TC_VEHICLE_MOTOR_P2_P4  ,	 
	TC_VEHICLE_MOTOR_PS  ,	
	TC_VEHICLE_MOTOR_PS_P4  ,
	TC_VEHICLE_MOTOR_EV  ,
	TC_VEHICLE_MOTOR_PARA_P2  ,
}TC_VEHICLE_MOTOR_TYPE_ENUM;
    
typedef struct
{
	boolean       tc_phev_dte_node_status;
    Std_ReturnType       tc_phev_dte_node_valid;
	uint8 tc_phev_dte_value;
}TC_DTE_PHEV_DATA_STRUCT;
typedef struct
{
  uint16 tc_Egyued;
  uint16 tc_RecupPwr;
} TC_Phev_Egy_DATA_t;


#if 1

typedef struct 
{	
	uint32  Tc_Energy_Info_Odo;
	uint32  Tc_Energy_Info_TripA;
	uint32  Tc_Energy_Info_TripB;	
    sint32  Tc_Energy_Info_FsrvKmValue;
}TC_ENERGY_ODO_INFO_STRUCT;

typedef struct
{
    uint16 u16Year;
    uint8 u8Month;
    uint8 u8Day;
    uint8 u8Hour;
    uint8 u8Minutes;
    uint8 u8Seconds;
} TC_DateTimeType_t;


typedef struct
{
	sint64 time;
	uint32 Curodo;
}TC_EMERGY_SYS_LOG_t;

#endif

typedef struct 
{
    uint16 STripAgeInitTripBileage;
    uint16 StripAgeFuelInitFuelCon;
    uint16 SFCDefault_NvmInit;
    uint16 STripAgeTolTripBileage;
}stTC_RTE_DteSfcInit;




typedef struct
{
    // V_config
    uint8 Vconfig_KIND_PT_CAN_BUS_TYPE;

    //C_config


}st_TcConfiguration;

typedef enum
{
    TC_PowerTrainType_NONE = 0,
	TC_PowerTrainType_AAEA7,
	TC_PowerTrainType_AAED2,
	TC_PowerTrainType_AAEB5,
}TC_RTE_POWER_TRAIN_TYPE_ENUM;


#define TC_OSTM_TIMER_CLEAR 				(0u)
#define TC_OSTM_TIMER_OVER					(1u)
#define TC_OSTM_TIMER_RUNING				(2u)

#define TC_MODULE_LOG_ENABLE  1
#if (TC_MODULE_LOG_ENABLE == 1) 
#define TC_MODULE_DEBUG(...)                //tripcomputer_info(__VA_ARGS__);
#define TC_MODULE_DEBUG_INFO(...)           tripcomputer_info(__VA_ARGS__);
#define TC_MODULE_err(...)                  tripcomputer_err(__VA_ARGS__);
#define TC_MODULE_DEBUG_INFO_warn(...)      tripcomputer_warn(__VA_ARGS__);
#define TC_MODULE_DEBUG_INFO_err(...)       tripcomputer_err(__VA_ARGS__);
#else
#define TC_MODULE_DEBUG(...)                
#define TC_MODULE_DEBUG_INFO(...)          
#define TC_MODULE_err(...)                  
#define TC_MODULE_DEBUG_INFO_warn(...)     
#define TC_MODULE_DEBUG_INFO_err(...)      
#endif 


/**********************************************************************************************************
*																										  *
*																										  *
*				              Macro																		  *
*																										  *
*																										  *
**********************************************************************************************************/

#define SWC_TC_START_SEC_CODE
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/**********************************************************************************************************
*Function   : TC_Rte_Api_Get_Vehicle_Type_Cfg                                                             *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-19                                                                                  *
**********************************************************************************************************/
TC_VEHICLE_TYPE_ENUM TC_Rte_Api_Get_Vehicle_Type_Cfg(void);
boolean TC_Rte_Api_Get_Cconfig_Cfg(CconfigKind_400Bytes Lcal_config);

/**********************************************************************************************************
*Function   : TC_Rte_Api_Get_Uint_Cfg                                                                     *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-19                                                                                  *
**********************************************************************************************************/
TC_UINT_TYPE_ENUM TC_Rte_Api_Get_Uint_Cfg(void);

/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Power_Mode_State                                                       	  *
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
boolean TC_RTE_API_Get_Power_Mode_State (void);
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Power_Mode_State_Is_Sleep                                                 	  *
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
boolean TC_RTE_API_Get_Power_Mode_State_Is_Sleep(void);
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
uint8 TC_RTE_API_Get_Voltage_Mode_State (void);
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Fuel_Error_State                                                       	  *
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
boolean TC_RTE_API_Get_Fuel_Error_State (void);
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Fuel_Finished_Init_State                                                  	  *
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
boolean TC_RTE_API_Get_Fuel_Finished_Init_State (void);
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Fuel_volume                                                  	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: shujunhua                                                                                   *
*                                                                                                         *
*Date		: 2020-09-15                                                                                  *
**********************************************************************************************************/
uint32 TC_RTE_API_Get_Fuel_volume (void);

/**********************************************************************************************************
*Function   : TC_RTE_API_Get_AFE_Condition                                                  	          *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: uint8                                                                                       *
*                                                                                                         *
*Author 	: renfengpo                                                                                   *
*                                                                                                         *
*Date		: 2022-02-09                                                                                  *
**********************************************************************************************************/
boolean TC_RTE_API_Get_AFE_Fuel_Condition (void);

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
uint8 TC_RTE_API_Get_VehRunning_State (void);
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_VehRunning_State_Ifc                                                      	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	:Shu junhua                                                                                   *
*                                                                                                         *
*Date		: 2021-01-15                                                                                  *
**********************************************************************************************************/
uint16 TC_RTE_API_Get_VehRunning_State_Ifc (void);
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
uint8 TC_RTE_API_Get_EngSpd_State (void);
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_EngSpd_OUT_State                                                           	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Ren Feng Po                                                                                  *
*                                                                                                         *
*Date		: 2021-11-23                                                                                  *
**********************************************************************************************************/
uint8 TC_RTE_API_Get_EngSpd_OUT_State (void);

/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Fuel_FastFill_State                                                          *
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
boolean TC_RTE_API_Get_Fuel_FastFill_State (void);
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_ODO_Count                                                                    *
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
uint8 TC_RTE_API_Get_ODO_Count (void);
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_ODO_Condition                                                                *
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
boolean TC_RTE_API_Get_ODO_Condition (void);
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_TC_Module_Output_Data                                                        *
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
void TC_RTE_API_Get_TC_Module_Output_Data (TC_MODULE_OUTPUT_DATA_STRUCT tc_module_output_data);
/**********************************************************************************************************
*Function   : TC_RTE_API_Set_TC_Module_Reset_Data                                                         *
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
void TC_RTE_API_Set_TC_Module_Reset_Data (uint8 tc_reset_index);
/**********************************************************************************************************
*Function   : TC_RTE_OstmTimerStart                                                                       *
*                                                                                                         *
*Description: system timer start                                                                          *
*                                                                                                         *
*Parameter  : Index_u8:timer index;   Over_u16: Over time                                                 *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean TC_RTE_OstmTimerStart(uint8 Index_u8);

/**********************************************************************************************************
*Function   : TC_RTE_OstmTimerCheck                                                                       *
*                                                                                                         *
*Description: system timer check                                                                          *
*                                                                                                         *
*Parameter  : Index_u8:timer index;                                                                       *
*                                                                                                         *
*Return     : uint8:Timer check status                                                                    *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 TC_RTE_OstmTimerCheck(uint8 Index_u8,uint32 over_time_base);
/**********************************************************************************************************
*Function   : TC_RTE_OstmTimerStop                                                                        *
*                                                                                                         *
*Description: system timer stop                                                                           *
*                                                                                                         *
*Parameter  : Index_u8:timer index;                                                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void TC_RTE_OstmTimerStop(uint8 Index_u8);
/**********************************************************************************************************
*Function   : TC_RTE_Get_OstmTimerValue                                                                   *
*                                                                                                         *
*Description: system timer stop                                                                           *
*                                                                                                         *
*Parameter  : Index_u8:timer index;                                                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean TC_RTE_Get_OstmTimerValue(uint8 Index_u8 , uint32 *TC_ElapseTime);



uint32 TC_RTE_API_Get_trip_value (uint8 index);
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Odo_value                                                                    *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: shujunhua                                                                                *
*                                                                                                         *
*Date		: 2020-12-1                                                                                  *
**********************************************************************************************************/

void TC_Api_Update_can_publish(TC_IP_PUBLISH_ENUM type,uint32 data);
/**********************************************************************************************************
*Function   : TC_API_RTE_Diag_Read_TC_Data                                                                *
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
void TC_API_RTE_Diag_Read_TC_Data(uint8 * data);
boolean TC_RTE_API_Get_ODO_err (void);
boolean TC_RTE_API_Get_ECM2_err (void);
/**********************************************************************************************************
*Function   : TC_Module_Rte_Coldinit_Warminit_Flag                                                  	  *
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
boolean TC_Module_Rte_Coldinit_Warminit_Flag (void);
void    TC_API_Get_Fuel_ONE_Error_State_Clear (void);
TC_FUEL_COMSUME_DATA_STRUCT TC_RTE_Get_FuelConsMsgValue(void);
Std_ReturnType TC_Rte_Api_Get_Fuel_ONE_Error_State (void);
boolean TC_RTE_API_Get_Hev_Phev_VehStartingSts (void);
uint8 TC_RTE_API_Get_Hev_Phev_VehStartingSts_Out (void);
TC_DTE_PHEV_DATA_STRUCT     TC_RTE_API_Get_HCU_Node_Status (void);
TC_VEHICLE_CHARGE_TYPE_ENUM TC_RTE_API_Get_HCU_Charge_Status (void);

static TC_RTE_POWER_TRAIN_TYPE_ENUM TC_Adapt_PowerTrainType_Vconfig(void);
stTC_RTE_DteSfcInit TC_Adapt_Api_Get_DteSfcInit(void);
void TC_RTE_GetAllConfiguration(void);
st_TcConfiguration TC_RTE_ApiGetConfiguration(void);
CanFrameCounterType TC_RTE_API_GetSpeedMsgValue(void);


#if 1
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Odo_Info                                                                     *
*                                                                                                         *
*Description: Add api for energy dte To IVI                                                               *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: TC_ENERGY_ODO_INFO_STRUCT                                                                   *
*                                                                                                         *
*Author 	: shujunhua                                                                                   *
*                                                                                                         *
*Date		: 2021-1-19                                                                                   *
**********************************************************************************************************/

TC_ENERGY_ODO_INFO_STRUCT TC_Api_Rte_Get_Odo_Info (void);
uint32  TC_Api_Rte_Get_Odo_value (void);
TC_EMERGY_SYS_LOG_t TC_Api_Rte_Get_SYS_Data(void);
TC_Phev_Egy_DATA_t  TC_Api_Rte_Get_Hcu_EgyUsed_MsgValue(void);
uint32 TC_AVS_Get_MAXValue(uint8 unit_type);
#endif 

/**********************************************************************************************************
*Function   : TC_NE_RTE_API_Get_Power_Mode_State                                                          *
*                                                                                                         *
*Description: New energy module use, get power mode                                                       *
*                                                                                                         *
*Parameter	: NONE                                                                                        *
*                                                                                                         *
*Return     : TC_NE_POWER_MODE                                                                                       *
*                                                                                                         *
*Author     : DengJiangbo                                                                                 *
*                                                                                                         *
*Date       : 2021-4-02                                                                                   *
**********************************************************************************************************/
#define CLUSTER_KL15ON    (0u)
#define CLUSTER_KL15OFF   (1u)
#define CLUSTER_OTHER     (2u)
#define CLUSTER_UNKONWN   (3u)

uint8 TC_NE_RTE_API_Get_Power_Mode_State(void);

/**********************************************************************************************************
*Function   : TC_RTE_API_Get_HCU_TotDrvReqPower       				                                      *
*                                                                                                         *
*Description: Get the signal for TC_NE                                                               	  *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: uint8                                                                   					  *
*                                                                                                         *
*Author 	: DengJiangbo                                                                                 *
*                                                                                                         *
*Date		: 2021-4-02                                                                                   *
**********************************************************************************************************/

uint8 TC_RTE_API_Get_HCU_TotDrvReqPower(uint16 *data);
uint8 TC_RTE_API_Get_HCU_TotDrvReqPower_P0(uint16 *data);
uint8 TC_RTE_API_Get_HCU_AvailPower_TM(uint16 *data);
uint8 TC_RTE_API_Get_BMS_DisSOC(uint8 *data);
uint8 TC_RTE_API_Get_HCU_ECODrvHabit(uint16 *data);
uint8 TC_RTE_API_Get_BMS_ChrgDurationTime(uint16 *data);
uint8 TC_RTE_API_Get_OBC_ConnectSts(uint8 *data);
uint8 TC_RTE_API_Get_BMS_StsCC2Line(uint8 *data);
uint8 TC_RTE_API_Get_BMS_PackCurr(uint16 *data);
uint8 TC_RTE_API_Get_HCU_EnrgFlowInd_DHT(uint8 *data);
uint8 TC_RTE_API_Get_HCU_EnrgFlowInd_P2(uint8 *data);
uint8 TC_RTE_API_Get_BarConnSts(uint8 *data);
uint8 TC_Rte_Get_HCU_CDCSFlag(void);


#define SWC_TC_STOP_SEC_CODE
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif

/**********************************************************************************************************
**
**  Revision:      1.0  
**
**  2020/06/02     Original Version
**
**********************************************************************************************************/

/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/


