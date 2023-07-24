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
*//**********************************************************************************************************
*File Name   : SWC_TC_Process.h                                                                             *
*                                                                                                         *
*Description : TripComputer module application interface head file.                                        *
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

#ifndef FTRIP_H
#define FTRIP_H

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "Com.h"
#include "VConfig.h"
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_TC_Pkg_Cfg.h"
#include "SWC_TC_Rte_Adapt.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	              Type Definition																		  *
*																								          *
*																								          *
**********************************************************************************************************/
#define TC_GET_VEH_CFG_STATUS(x,y)                                  //VConfig_GetKindConfig(x,y)

#define TC_ODO_INPUT_CAN_MESSAGE_MISSING_STATUS(x)                  //Com_GetRxPduStatus(x)
#define TC_ODO_INPUT_CAN_SIGNAL_STATUS(x,y)                         //Com_ReceiveSignal(x,y)

#define TC_FUEL_CONSUM_INPUT_CAN_MESSAGE_MISSING_STATUS(x)          //Com_GetRxPduStatus(x)
#define TC_FUEL_CONSUM_INPUT_CAN_SIGNAL_STATUS(x,y)                 //Com_ReceiveSignal(x,y)

#define TC_IPC_NOTIFICATION_AFE_BIT             ((uint8)0x80)
#define TC_IPC_NOTIFICATION_IFE_BIT             ((uint8)0x40)
#define TC_IPC_NOTIFICATION_AVS_BIT             ((uint8)0x20)
#define TC_IPC_NOTIFICATION_DTE_BIT             ((uint8)0x10)
#define TC_IPC_NOTIFICATION_TRIVE_BIT           ((uint8)0x08)
#define TC_IPC_NOTIFICATION_PHEV_DTE_BIT        ((uint8)0x04)
#define TC_IPC_NOTIFICATION_RESERVE1_BIT        ((uint8)0x02)
#define TC_IPC_NOTIFICATION_RESERVE2_BIT        ((uint8)0x01)
#define TC_VEHICLE_LOG_OUTPUT //TC LOG FLAG
#define TC_DTE_KEYON_LOG_DELAY                  125u
#define TC_LOG_INIT_BIT         ((uint8)0x01)
#define TC_LOG_EVENT_BIT        ((uint8)0x02)
#define TC_LOG_PERIOD_BIT       ((uint8)0x04)
#define TC_LOG_EVENT_DTE_BIT    ((uint8)0x08)
#define TC_EVENT_INIT           0u
#define TC_EVENT_DTE_CAL        1u
#define TC_EVENT_FIXATION       2u
#define TC_EVENT_DTE            3u
#define TC_EVENT_INIT_LENGTH    21u

/**********************************************************************************************************
* Struct Definition                                                                               *
**********************************************************************************************************/

#if 1
typedef enum
{
    TC_TIMER_CLEAR,
    TC_TIMER_RUNNING,
    TC_TIMER_EXPIRED,
}TC_SW_TIMER_STATE;

typedef enum
{
    TC_EMERGY_WAIT_RESPONSE,
    TC_EMERGY_WAIT_5S,
}TC_SW_TIMER_ID;

typedef enum
{   TC_ENERGY_NONE_UPDATE,
    TC_ENERGY_IVI_ALIVE_UPDATE,
    TC_ENERGY_1KM_UPDATE,
    TC_ENERGY_5S_UPDATE,
}TC_ENERGY_UPDATE_MODE;

typedef struct 
{
	uint32  FuelConsumptionPer1km;
	uint16  EgyUsedPer1km;
	uint16  RecupPwrPer1km;
	//uint16  AveEnergyRec;
	sint64  CalendarPer1km;
    uint8   NewChargeCyclePer1km;
    uint16  TripNotSentPer1km;
    uint32  VehDistance;
}TC_ENERGY_PER_1KM_STRUCT;


typedef struct
{	
	//TC_ENERGY_ODO_INFO_STRUCT  Tc_Energy_Info_Odo_trip;
	uint16  Tc_Energy_Info_FuelDte;
    uint16  Tc_Energy_Info_PhevDte;
}TC_ENERGY_INFO_STRUCT;

typedef struct
{
    TC_ENERGY_PER_1KM_STRUCT  *Tx_table;
    TC_ENERGY_PER_1KM_STRUCT   Tx_buffer[10];
    TC_ENERGY_UPDATE_MODE      TC_Energy_update_mode;
    uint32                     TC_Energy_Cal_Odo;
    uint8                      Tx_index;
    uint8                      TC_Energy_Ivi_Alive;
    uint8                      TC_Energy_Ivi_Respone;
}TC_Energy_data_t;




#endif 

typedef enum
{
	L_PER_100KM=0,
	L_PER_HOUR,
	KM_PER_L,
	US_GPH,
	UK_GPH,
	US_MPG,
	UK_MPG,
}TC_XFE_UNIT_ENUM;

typedef enum {
	MEMORY_ALL_RESET = 0,
	MEMORY_1ST_RESET,
	MEMORY_2ST_RESET,
} TC_RESET_TYPE;

typedef enum {
	DTE_REFRESH_ERROR_MODE = 0,
	DTE_REFRESH_LOW_MODE,
	DTE_REFRESH_KEEP_MODE,
	DTE_REFRESH_UPDATE_IMMED_MODE,
	DTE_REFRESH_UPDATE_10S_MODE,
	DTE_REFRESH_UPDATE_30S_MODE,
	DTE_REFRESH_UPDATE_100S_MODE,
	DTE_REFRESH_UPDATE_400S_MODE,
} TC_DTE_REFRESH_MODE_ENUM;

typedef enum {
    DTE_K_None_Update=0,
    DTE_K_SlowUpdate,
    DTE_K_NormalUpdate,
	DTE_K_FastUpdate,
	DTE_K_Fuel_FastUpdate,
	DTE_K_Idle_Update,
	DTE_K_Error_Update,
} TC_DTE_K_UPDATE_ENUM;


typedef struct
{
	uint32 u32AccumOdoPulse;
	uint32 u32AccumFuelPulse;
	uint32 u32AccumTime;
}TC_ACC_STURCT;

typedef struct
{
	TC_ACC_STURCT tAccDat;
	uint32 u32CalcTimeCount;        /*unit: ms*/
	uint32 u32CalculationIFE;
	uint32 u32CurrentIFE;
	uint32 u32DisplayIFE;
	uint32 u32DisplayTimeTick;      /*unit: 100ms*/
	TC_XFE_UNIT_ENUM  u8DisplayUnit;
    TC_XFE_UNIT_ENUM  u8CalcUnit;
}TC_IFE_STRUCT;

typedef struct
{
	TC_ACC_STURCT tAccDat;
	uint32 u32CalcTimeCount;        /*unit:	ms*/
	uint32 u32CurrentAFE[TC_MAX_NUM_OF_AFE];
    uint32 u32DisplayAFE_bu[TC_MAX_NUM_OF_AFE];
	uint32 u32DisplayAFE[TC_MAX_NUM_OF_AFE];
	uint32 u32DisplayTimeTick;      /*unit:	100ms*/
	boolean  u8NormalDisplay[TC_MAX_NUM_OF_AFE];
}TC_AFE_STRUCT;

typedef struct
{
	TC_ACC_STURCT tAccDat;
	uint32 u32CalcTimeCount;        /*unit:	ms*/
	uint32 u32CurrentAVS[TC_MAX_NUM_OF_AVS];
	uint32 u32DisplayAVS[TC_MAX_NUM_OF_AVS];
	uint32 u32DisplayTimeTick;      /*unit: 100ms*/
	boolean  u8NormalDisplay[TC_MAX_NUM_OF_AVS];
}TC_AVS_STRUCT;

typedef struct
{
	TC_ACC_STURCT tAccDat;
	uint32 u32CalculationDTE;
	uint32 u32CurrentDTE;
	uint32 u32DisplayDTE;
	uint32 u32CalcTimeCount;        /*unit:	ms*/
	uint32 u32DisplayTimeTick;      /*unit:	100ms*/
	uint32 u32RefreshTimeTick;      /*unit:	100ms*/
    uint32 NorDiff_1L_dte;
    uint32 UnNorDiff_15L_dte;
    uint32 DTE_Trip1S;
    uint32 Idle_Fuelconsump;
    uint16 Fuel_Consump100m;
    uint32 SFC;
    uint16 DTE_Trip1S_k;
    uint16 Dte_Task_tick;
    TC_DTE_K_UPDATE_ENUM  DTE_Trip1S_k_Mode;
	TC_DTE_REFRESH_MODE_ENUM  u8Refresh_Mode;
	TC_DTE_REFRESH_MODE_ENUM  u8Refresh_Last_Mode;
}TC_DTE_STRUCT;

typedef struct
{
	uint32 u32FuelPulseAccum;
	uint32 u32FuelLevel;        /*unit:ml*/
	uint32 u32OilTankMax;       /*unit:ml*/
	uint8  u8FuelAccumEnable;
	uint8  u8FuelSensorState;
}TC_FUEL_STRUCT;

typedef struct
{
	uint32 u16IgnOffTimeScale;
}TC_IGNOFF_TIME_STRUCT;

typedef struct
{
	uint8  u8TravelTime_Hour[TC_MAX_NUM_OF_TDT];
	uint8  u8TravelTime_Minute[TC_MAX_NUM_OF_TDT];
	uint8  u8TravelTime_Second[TC_MAX_NUM_OF_TDT];
	uint8  u8TravelTime_Tick;
}TC_TRAVEL_TIME_STRUCT;

typedef struct
{  
   TC_ACC_STURCT  tAccDat;  /*add it for 1km is calculated separately*/
   uint32 u32DisplayTimeTick;       /*unit:	100ms*/
   uint32 u32AccumEgyUsed ;
   uint32 u32AccumEgyRecupPwr;
   uint16 u16DisplayDTE; 
   TC_VEHICLE_CHARGE_TYPE_ENUM chargests;
   uint8  u8NewChargeCycle;
   uint16 u16NewChargeCycle_Count; /*For SRS V1.9 Version changes*/
   uint8 Eol_configuration;
}TC_PHEV_STRUCT;

typedef struct
{
	/* 1¡¢fuel max counter  2¡¢off   time */
	uint16 Max_fuelConPerCycle_NvmInit;
	uint16 IgnOffTimeScale_NvmInit;

	/* travel time datda nvm */
	uint16 TravelTimeDisplayLimited_Hour_NvmInit;
	uint16 TravelTimeDisplayLimited_Minute_NvmInit;
	uint16 TravelTimeADisplayEnable_NvmInit;
	uint16 TravelTimeBDisplayEnable_NvmInit;

	/* IFE datda nvm */
	uint16 RefreshRateIFC_NvmInit;
	uint16 IFC_POC_Update_NvmInit;
	uint16 IFCDisplayEnable_NvmInit;
	uint16 IFC_Fuel_Damp_Upate_NvmInit;

	/* AFE datda nvm */
	uint16 RefreshRateAFC_NvmInit;
	uint16 AFCMinDistanceThresh_NvmInit;
	uint16 AFCADisplayEnable_NvmInit;
	uint16 AFCBDisplayEnable_NvmInit;

	/* AVS datda nvm */
	uint16 RefreshRateAVS_NvmInit;
	uint16 AVSMinDistanceThresh_NvmInit;
	uint16 AVSADisplayEnable_NvmInit;
	uint16 AVSBDisplayEnable_NvmInit;

	/* DTE datda nvm */
	uint16 RefreshRateDTE_NvmInit;
	uint16 RefreshRateDTEReFuel_NvmInit;
	uint16 TankReserveVol_NvmInit;
	uint16 SFCDefault_NvmInit;
	uint16 SFCMin_NvmInit;
	uint16 SFCMax_NvmInit;
	uint16 RangeIncThreshold_NvmInit;
	uint16 RangeDecThreshold_NvmInit;
	uint32 FastUpdateTime_NvmInit;
	uint32 SlowUpdateTime_NvmInit;
	uint32 IdleUpdateTime_NvmInit;
	uint32 UnNormalUpdateTime_NvmInit;
//   #ifdef GWM_V35_PROJECT_TYPE_B02
    uint8  Phev_sMaxDisplayPHEVRange;
    uint8  Phev_Dte_DisplayEnable_NvmInit;
    uint16  Phev_Dte_RefreshRatePHEVDTE;
    uint16 StripAgeFuelInitFuelCon;
    uint16 STripAgeInitTripBileage;
    uint16 STripAgeFuelFactor;
    uint16 STripAgeTolTripBileage;

//   #endif
}TC_CONFIG_DATA_NVM;

typedef struct
{   uint32        ttrip[2];
	uint16		  tIFC_10S;
 //   #ifdef  GWM_V35_PROJECT_TYPE_B02
    TC_PHEV_STRUCT	tPhev;
 //   #endif 
	TC_IFE_STRUCT tIFE;
	TC_AFE_STRUCT tAFE;
	TC_AVS_STRUCT tAVS;
	TC_DTE_STRUCT tDTE;
	TC_FUEL_STRUCT tFuel;
	TC_TRAVEL_TIME_STRUCT tTravel_Time;
	TC_IGNOFF_TIME_STRUCT tOff_Time;
	TC_CONFIG_DATA_NVM tTC_Config_NVM;
    uint8  Tc_Ipc_Update;
}TC_TOTAL_STRUCT;

typedef struct 
{
	uint16  ODO_Display;
	uint16  Trip_Display;
	uint16  FUEL_Consuption;
	uint16  IFE_Display;
	uint16  AVS_Display;

	uint16  AFE_Display;
	uint16  AFE_CalculateRAFF;
	uint16  AFE_CalculateAFE;

	uint16  DTE_Diaplay;
	uint16  DTE_Caculate;
	uint16  DTE_Update;
	uint16  DTE_CalculateCFC;
	uint16  DTE_Get_Fuel;
}TC_DEBUG_STRUCT;

#ifdef TC_VEHICLE_LOG_OUTPUT

typedef struct
{
    //BYTE0
    uint8 TC_AVSADisplayEnable_Elog;
    uint8 TC_AVSBDisplayEnable_Elog;
    uint8 TC_TravelTimeADisplayEnable_Elog;
    uint8 TC_TravelTimeBDisplayEnable_Elog;
    uint8 TC_AFCADisplayEnable_Elog;
    uint8 TC_AFCBDisplayEnable_Elog;
    uint8 TC_IFCDisplayEnable_Elog;
    uint8 TC_DisplayEnable_Elog;            //The endurance display is enabled

    //BYTE1
    uint8 TC_RefreshRateAVS_Elog;		    //refresh cycle
    uint8 TC_AVSMinDistanceThresh_Elog;     //Invalid mileage
    uint8 TC_RefreshRateAFC_Elog;	        //refresh cycle
    uint8 TC_AFCMinDistanceThresh_Elog;     //Invalid mileage
    uint8 TC_Max_fuelConPerCycle_Elog;      //Cycle maximum fuel injection
    uint8 TC_RefreshRateIFC_Elog;           //IFE refresh cycle
    uint8 TC_sMaxDisplayPHEVRange_Elog;     //PHEV DTE VALUE
    uint8 TC_TravelTimeDisplayLimited_Elog; //Travel time max value

    uint8 TC_Vehicle_Type;
    uint8 TC_Motor_Type;
    uint8 TC_power_state;
    uint8 TC_Motor_out;/* 1è¶…æ—¶ */
    uint8 TC_phev_out;
}TC_Log_Event;
typedef union
{
    uint8 TC_RFP_STORAGE_1[TC_EVENT_INIT_LENGTH];
    TC_Log_Event RFP_TC_1;
}TC_LOG_RFP;
typedef struct
{
    //BYTE2
    uint8 TC_Calculate_Enable_Elog;         //Travel time is enabled
    uint8 TC_DTE_Enable_Elog;               //DTE is enabled
    uint8 TC_AVS300_A_Elog;
    uint8 TC_AVS300_B_Elog;
    uint8 TC_AFC300_A_Elog;
    uint8 TC_AFC300_B_Elog;
    uint8 TC_ODO_Err_PLog;
    uint8 TC_ECM2_Err_PLog;
    uint8 TC_DTE_Refresh_Mode_plog;
    uint16 TC_DTE_SFC_PLog;                 //Mileage phase fuel consumption
    uint32 TC_DTE_Calculation_PLog;
    uint32 TC_DTE_Current_PLog;
    uint32 TC_DTE_Display_PLog;
    uint32 TC_FUEL_Display_PLog;
    uint32 TC_Pkg_Odo_value_PLog;           //DTE ODO calculated value
    uint32 TC_Pkg_Odo_value;                //ODO
}TC_Log_Period;
typedef enum
{
  TC_LOG_TASK_INIT=0,
  TC_LOG_TASK_EVENT ,
  TC_LOG_TASK_EVENT_DTE ,
  TC_LOG_TASK_PERIOD,
  TC_LOG_TASK_MAX,
}TC_LOG_TASK_ENUM;

#define TC_LOG_DTE_EVENT1      \
RFP_TC_2.TC_FUEL_Display_PLog     ,\
RFP_TC_2.TC_DTE_SFC_PLog          ,\
RFP_TC_2.TC_DTE_Refresh_Mode_plog ,\
RFP_TC_2.TC_DTE_Calculation_PLog


#define TC_LOG_DTE_EVENT2      \
RFP_TC_2.TC_DTE_Display_PLog      ,\
RFP_TC_2.TC_DTE_Current_PLog      ,\
RFP_TC_2.TC_Pkg_Odo_value         ,\
RFP_TC_3.RFP_TC_1.TC_power_state

#define TC_LOG_DTE_EVENT3      \
RFP_TC_3.RFP_TC_1.TC_Vehicle_Type,\
RFP_TC_3.RFP_TC_1.TC_Motor_out

#define TC_LOG_DTE_EVENT4      \
RFP_TC_3.RFP_TC_1.TC_Vehicle_Type ,\
RFP_TC_3.RFP_TC_1.TC_Motor_Type   ,\
RFP_TC_3.RFP_TC_1.TC_Motor_out  ,\
RFP_TC_3.RFP_TC_1.TC_phev_out

#define TC_LOG_DTE_PERIOD1      \
TC_Energy_data_current.NewChargeCyclePer1km,\
TC_Energy_data_current.EgyUsedPer1km   ,\
TC_Energy_data_current.RecupPwrPer1km ,\
TC_Energy_data_current.TripNotSentPer1km

#define TC_LOG_DTE_PERIOD2      \
TC_Energy_data_current.FuelConsumptionPer1km ,\
TC_Energy_data_current.VehDistance

#endif



/**********************************************************************************************************
*																										  *
*																										  *
*				              Macro																		  *
*																										  *
*																										  *
**********************************************************************************************************/
#define SWC_TC_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern TC_DEBUG_STRUCT TC_Ftrip_Info;
extern uint8 TC_Trip_Singal_Status;
extern boolean TC_Module_Init_Flag;

#define SWC_TC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#pragma ghs section bss=".buram"

extern TC_TOTAL_STRUCT TC_Ftrip_T;
extern TC_VEHICLE_TYPE_ENUM  TC_Module_Vehicle_Type_Data;
extern TC_VEHICLE_MOTOR_TYPE_ENUM TC_Module_Motor_Type_Data;

#pragma ghs section bss=default

/**********************************************************************************************************
*Function   : TC_Api_KSColdInit                                                                     	  *
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
#define SWC_TC_START_SEC_CODE
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
extern void TC_Api_KSColdInit(void);
/**********************************************************************************************************
*Function   : TC_Api_KSColdInit                                                                     	  *
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
extern void TC_Api_KSWarmInit(void);
/**********************************************************************************************************
*Function   : TC_Api_KSSleep                                                                        	  *
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
extern void TC_Api_KSSleep(void);
/**********************************************************************************************************
*Function   : TC_Api_KSWakeup                                                                        	  *
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
extern void TC_Api_KSWakeup(void);
/**********************************************************************************************************
*Function   : TC_Api_Trans_Outof_Normal                                                               	  *
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
extern void TC_Api_Trans_Outof_Normal(void);
/**********************************************************************************************************
*Function   : TC_Api_Trans_Into_Normal                                                                 	  *
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
extern void TC_Api_Trans_Into_Normal(void);
/**********************************************************************************************************
*Function   : TC_Api_Process_Task                                                                     	  *
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
extern void TC_Api_Process_Task(void);
/**********************************************************************************************************
*Function   : TC_Api_Accum_Collect_Task                                                                	  *
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
extern void TC_Api_Accum_Collect_Task(void); 
/**********************************************************************************************************
*Function   : TC_Api_Update_Calc_Task                                                                  	  *
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
extern void TC_Api_Update_Calc_Task(void);
/**********************************************************************************************************
*Function   : TC_Api_Config_Data_NVM_Init                                                           	  *
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
void TC_Api_Config_Data_NVM_Init(void);
/**********************************************************************************************************
*Function   : TC_Api_AFE_Reset                                                                        	  *
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
extern void TC_Api_AFE_Reset(uint8 afe_index);

extern void TC_Api_AFE_Reset_All(void);

/**********************************************************************************************************
*Function   : TC_Api_AVS_Reset                                                                        	  *
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
extern void TC_Api_AVS_Reset(uint8 tc_key_index);
/**********************************************************************************************************
*Function   : TC_Api_AVS_Reset_All                                                                     	  *
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
extern void TC_Api_AVS_Reset_All(void);

extern void TC_Api_trip_Reset_All(void);

/**********************************************************************************************************
*Function   : TC_Api_Reset_TC_All                                                                     	  *
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
extern void TC_Api_Reset_TC_All(void);
/**********************************************************************************************************
*Function   : TC_Api_Update_AVS                                                                     	  *
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
extern void TC_Api_Update_AVS(void); 
/**********************************************************************************************************
*Function   : TC_Api_Get_AVS_Value                                                                     	  *
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
extern uint32 TC_Api_Get_AVS_Value(uint8 tc_key_index);
/**********************************************************************************************************
*Function   : TC_Api_Get_AFE_Value                                                                     	  *
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
extern uint32 TC_Api_Get_AFE_Value(uint8 afe_index); 
/**********************************************************************************************************
*Function   : TC_Api_Update_AFE                                                                     	  *
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
extern void TC_Api_Update_AFE(void);
/**********************************************************************************************************
*Function   : TC_Api_Accum_Enable                                                                     	  *
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
extern uint8 TC_Api_Accum_Enable(void);
/**********************************************************************************************************
*Function   : TC_Api_Get_DTE_Value                                                                     	  *
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
uint32 TC_Api_Get_DTE_Value(void);
/**********************************************************************************************************
*Function   : TC_Api_Get_IFE_Value                                                                     	  *
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
uint32 TC_Api_Get_IFE_Value(void);
/**********************************************************************************************************
*Function   : TC_Api_Get_Fuel_Tank_Size                                                                	  *
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
extern uint16 TC_Api_Get_Fuel_Tank_Size(void);
/**********************************************************************************************************
*Function   : TC_API_Get_Fuel_volume                                                            	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: shujunhua                                                                                 *
*                                                                                                         *
*Date		: 2020-09-15                                                                                  *
**********************************************************************************************************/
uint32 TC_API_Get_Fuel_volume (void);
/**********************************************************************************************************
*Function   : TC_Api_Get_DTE_Accum_Condition                                                          	  *
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
extern uint8 TC_Api_Get_DTE_Accum_Condition(void);
/**********************************************************************************************************
*Function   : TC_Api_Get_AVS_Accum_Condition                                                        	  *
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
extern uint8 TC_Api_Get_AVS_Accum_Condition(void);
/**********************************************************************************************************
*Function   : TC_Api_Get_DTE_Value_For_Hmi                                                            	  *
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
extern uint16 TC_Api_Get_DTE_Value_For_Hmi(uint8 speed_uint);
/**********************************************************************************************************
*Function   : TC_Api_Get_AVS_Value_For_Hmi                                                             	  *
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
extern uint16 TC_Api_Get_AVS_Value_For_Hmi(uint8 type,uint8 speed_uint);
/**********************************************************************************************************
*Function   : TC_Api_Get_AFE_Value_For_Hmi                                                           	  *
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
extern uint16 TC_Api_Get_AFE_Value_For_Hmi(uint8 type, TC_XFE_UNIT_ENUM tc_uint, uint32 Denominator);
/**********************************************************************************************************
*Function   : TC_Api_Get_IFE_Value_For_Hmi                                                          	  *
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
extern uint16 TC_Api_Get_IFE_Value_For_Hmi(TC_XFE_UNIT_ENUM tc_uint,uint32 Denominator);
/**********************************************************************************************************
*Function   : TC_Api_Reset_All_TC_For_Other_Module                                                     	  *
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

extern void TC_Api_Reset_All_TC_For_Other_Module(TC_RESET_TYPE e_Reset_Memory);
/**********************************************************************************************************
*Function   : TC_Api_Get_IFE_Uint_For_Hmi                                                            	  *
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
extern uint8 TC_Api_Get_IFE_Uint_For_Hmi(void);

/**********************************************************************************************************
*Function   : TC_Api_Get_Fuel_Accum_Value                                                             	  *
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
extern uint32 TC_Api_Get_Fuel_Accum_Value(void);
/**********************************************************************************************************
*Function   : TC_Api_Clear_Fuel_Accum_Value                                                         	  *
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
extern void   TC_Api_Clear_Fuel_Accum_Value(void);
/**********************************************************************************************************
*Function   : TC_Api_Set_Fuel_Accum_Enable                                                            	  *
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
extern void   TC_Api_Set_Fuel_Accum_Enable(uint8 enable_flag);
/**********************************************************************************************************
*Function   : TC_Api_Travel_Time_Reset_Value                                                           	  *
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
void TC_Api_Travel_Time_Reset_Value(uint8 tdt_index);
/**********************************************************************************************************
*Function   : TC_Api_Travel_Time_Reset_All                                                            	  *
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
void TC_Api_Travel_Time_Reset_All(void);
/**********************************************************************************************************
*Function   : TC_Api_Travel_Time_Get_Time                                                            	  *
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
uint32 TC_Api_Travel_Time_Get_Time(uint8 tdt_index);
/**********************************************************************************************************
*Function   : TC_Api_Travel_Time_Process_Task                                                          	  *
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
void TC_Api_Travel_Time_Process_Task (void);
/**********************************************************************************************************
*Function   : TC_API_Get_Power_Mode_State                                                            	  *
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
uint8 TC_API_Get_Power_Mode_State (void);
/**********************************************************************************************************
*Function   : TC_API_Get_Voltage_Mode_State                                                            	  *
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
uint8 TC_API_Get_Voltage_Mode_State (void);
/**********************************************************************************************************
*Function   : TC_API_Get_Fuel_Error_State                                                            	  *
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
boolean TC_API_Get_Fuel_Error_State (void);
/**********************************************************************************************************
*Function   : TC_API_Get_Fuel_Finished_Init_State                                                      	  *
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
uint8 TC_API_Get_Fuel_Finished_Init_State (void);
/**********************************************************************************************************
*Function   : TC_API_Get_VehRunning_State                                                           	  *
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
uint8 TC_API_Get_VehRunning_State (void);
/**********************************************************************************************************
*Function   : TC_API_Get_VehRunning_State_For_Ifc                                                           	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Shu junhua                                                                                   *
*                                                                                                         *
*Date		: 2021-1-5                                                                                  *
**********************************************************************************************************/
uint8 TC_API_Get_VehRunning_State_For_Ifc(void);

/**********************************************************************************************************
*Function   : TC_API_Get_EngSpd_State                                                               	  *
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
uint8 TC_API_Get_EngSpd_State (void);

/**********************************************************************************************************
*Function   : TC_API_Get_EngSpd_OUT_State                                                               	  *
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
uint8 TC_API_Get_EngSpd_OUT_State (void);

/**********************************************************************************************************
*Function   : TC_API_Get_Fuel_FastFill_State                                                              *
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
boolean TC_API_Get_Fuel_FastFill_State (void);
/**********************************************************************************************************
*Function   : TC_API_Set_TC_Module_Reset_Data                                                             *
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
void TC_API_Set_TC_Module_Reset_Data (TC_MODULE_RESET_DATA_INDEX tc_reset_index);
/**********************************************************************************************************
*Function   : TC_API_Set_Module_Data                                                                      *
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
void TC_API_Set_Module_Data(TC_MODULE_OUTPUT_DATA_STRUCT tc_module_output_data);


void TC_Api_Dte_Reset(void);
/**********************************************************************************************************
*Function   : TC_API_Set_Diag_Read_TC_Data                                                                 *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date       : 2020-11-07                                                                                  *
**********************************************************************************************************/
void TC_API_Set_Diag_Read_TC_Data(uint8 * data);
void TC_Api_Process_fuel_update_Task(void);
/** 
 * [TC_API_Get_Speed_For_Dte : get spd value]
 * @Author   shujunhua
 * @DateTime 2021/5/29-11:40:58
 * @param    void                     [description]
 * @return   uint16                   [factor:100 ,eg 2000=20km/h]
 */
uint16 TC_API_Get_Speed_For_Dte(void);
TC_TOTAL_STRUCT TC_Api_Get_ALL_Date (void);
TC_VEHICLE_TYPE_ENUM  TC_Api_Get_Vehicle_Type(void);

#if 1
void TC_Api_Emergy_Get_IVI_Alive_Respone(uint8 EnergyInfoDataTypeId,uint8 *Ividata);
void TC_App_Emergy_cal_task(void);
void TC_App_Update_Emergy(void);
TC_VEHICLE_MOTOR_TYPE_ENUM TC_Rte_Api_Get_Motor_Cfg(void);

#endif 
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


