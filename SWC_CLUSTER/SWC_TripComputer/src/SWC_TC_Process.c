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
*File Name   : SWC_TC_Process.h                                                                             *
*                                                                                                         *
*Description : TripComputer module application source file.                                        *
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

#define FTRIP_C

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include <time.h>
#include <string.h>
#include "Compiler.h"
#include "Platform_Types.h"
#include "Rte_Common_Normal.h"
#include "IPC_ClusterApp.h"
#include "IPC_IVIApp.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_TC_Process.h"
#include "SWC_TC_Pkg_Cfg.h"
#include "SWC_TC_Pkg.h"
#include "SWC_Fuel_Api_Process.h"
#include "SWC_TC_Rte_Adapt.h"
#include "SWC_IPC_Config.h"
#include "SWC_Odo_Adapt.h"
#include "CConfig_Cfg.h" /*add it for cconfig v1.9 */
#include "SWC_TC_NE_Process.h"

/**********************************************************************************************************
*																										  *
*																										  *
*				  Type Definition																		  *
*																										  *
*																										  *
**********************************************************************************************************/
#if 1
#define          TC_DTE_KEYON_DELAY             5u 
#define          IVI_RESP_SUCCESS               TC_Energy_data.TC_Energy_Ivi_Respone 
#define          VIP_2_IVI_CALLBACK             1u 
#define          TC_SW_TMR_CFG_MAX              2u
#define          TC_EMERGY_DATA_NUM             10u
#define          TC_EMERGY_WAIT_5S_TIMER_NUM    50u
#define          TC_EMERGY_WAIT_RESPONSE_TIMER_NUM    3u
#define          TC_EMERGY_DATA_UPADTE_KM       (1000UL)/*uint 0.1m*/
#define          TC_DTE_UPADTE_S       (10UL)/*1S=100MS*10*/
#define TC_DTE_MENU_RESET_ENABLE
//#define TC_DTE_NEW_STRATEGY_0413
#define TC_DTE_ERR_DETECTION_TIME  (2uL*600) /*2min*/
#define TC_DTE_ERR_DETECTION_SPEED (20uL*100)/*20km/h*/


#define TC_IPC_GET_BYTE(data, index)        ((uint8 *)(&(data)))[index]

#pragma ghs section bss=".buram"   /*@20200929 define data to specified BURAM area*/

static TC_ENERGY_PER_1KM_STRUCT  TC_Energy_data_current;
static TC_Energy_data_t          TC_Energy_data;
static uint16 TC_Prev_EgyUsed_count;
static uint16 TC_Prev_EgyRecupPwr_count;
static uint16 TC_SW_Timers[TC_SW_TMR_CFG_MAX];



#pragma ghs section bss=default
#endif 
/*add it for Project(B03¡¢B02¡¢B06) Vehicle type PHEV*/
#define TC_PHEV_DTE_DISPLAY_DASHES          (0xFFFF)
#define TC_PHEV_DTE_DISPLAY_HMI_DASHES      (0xFFFE)
#define TC_PHEV_DTE_DISPLAY_LOW_DASHES      (0xFFFF)
#define TC_Hev_Phev_VehStartingSts          TC_RTE_API_Get_Hev_Phev_VehStartingSts()  /*TBD need to Add can signal */
#define TC_MinDisplayPHEVRange             ((uint8)5)
#define TC_MaxDisplayPHEVRange             ((uint8)TC_Ftrip_T.tTC_Config_NVM.Phev_sMaxDisplayPHEVRange)
#define TC_PHEVRange_DISP_ENABLE_INTERNAL  ((uint8)(TC_Ftrip_T.tTC_Config_NVM.Phev_Dte_DisplayEnable_NvmInit))
#define TC_PHEVRange_DISP_ENABLE_EOL        (TC_Ftrip_T.tPhev.Eol_configuration) 


#define TC_DTE_DISPLAY_DASHES              	(0xFFFFFFFFuL)
#define TC_DTE_DISPLAY_HMI_DASHES       	(0xFFFFuL)
#define TC_DTE_DISPLAY_LOW_DASHES           (0xFFFFFFFEuL)

#define TC_AVS_AFTER_RESET_DASHES       	(0xFFFFFFFFuL)
#define TC_AVS_DISPLAY_OFF_DASHES       	(0xFFFFFFFEuL)
#define TC_AVS_AFTER_RESET_HMI_DASHES       (0xFFFFuL)
#define TC_AVS_DISPLAY_OFF_HMI_DASHES      	(0xFFFEuL)

#define TC_AFE_AFTER_RESET_DASHES			(0xFFFFFFFFuL)
#define TC_AFE_DISPLAY_OFF_DASHES       	(0xFFFFFFFEuL)
#define TC_AFE_AFTER_RESET_HMI_DASHES       (0xFFFFuL)
#define TC_AFE_DISPLAY_OFF_HMI_DASHES      	(0xFFFEuL)

#define TC_IFE_AFTER_RESET_DASHES			(0xFFFFFFFFuL)
#define TC_IFE_DISPLAY_OFF_DASHES       	(0xFFFFFFFEuL)
#define TC_IFE_AFTER_RESET_HMI_DASHES       (0xFFFFuL)
#define TC_IFE_DISPLAY_OFF_HMI_DASHES      	(0xFFFEuL)

#define TC_TDT_AFTER_RESET_DASHES			(0xFFuL)
#define TC_TDT_DISPLAY_OFF_DASHES       	(0xFEuL) 


#define TC_ODO_SIG_INVLD_MIS_NVR_RCVD      	((uint8)0x01)
#define TC_FUEL_SIG_INVLD_MIS_NVR_RCVD     	((uint8)0x02)
#define TC_EGYUSED_SIG_INVLD_MIS_NVR_RCVD   ((uint8)0x04)
#define TC_FUEL_INIT_OPENSHT               	((uint8)0x08)
#define TC_FUEL_INIT_OVER                  	((uint8)0x10)
#define TC_AVG_FIRE_FUEL_RESET				((uint8)0x20)

#define TC_DATA_ACCUMULATED_ONCE_AFE       	((uint8)0x01)
#define TC_THIRTY_METER_OR_ONE_SEC         	((uint8)0x02)
#define TC_AVS_RESET_KEY                   	((uint8)0x04)
#define TC_AFE_RESET_KEY                   	((uint8)0x08)
#define TC_TRIP_FUEL_PULSE_CHANGE          	((uint8)0x10)
#define TC_TRIP_ODO_COUNT_CHANGE           	((uint8)0x20)
#define TC_BATTERY_CONNECT_OR_RESET        	((uint8)0x40)
#define TC_DATA_ACCUMULATED_ONCE_AVS       	((uint8)0x80)
	
#define TC_FUEL_LEVEL_IN_LITERS           	(TC_API_Get_Fuel_volume()/100u)//60// modify by fchao in 20200615//ga_fuel_get_fuel_volume()/100	//(uint16)(((uint32) ga_fuel_get_fuel_level() * TC_MAX_FUEL_TANK_SIZE ) / (uint32)(1000) )
#define TC_FUEL_LEVEL_IN_LITERS_OLD       	0// modify by fchao in 20200615//ga_fuel_get_fuel_volume()/100	//(uint16)(((uint32) ga_fuel_get_fuel_level() * TC_MAX_FUEL_TANK_SIZE_OLD) / (uint32)(1000) )
	
#define TC_MAX_AVS_OR_AFE                  	((uint32)999 * 1000uL) // modify for bug V35-36326
#define TC_MAX_AVS_DISP_KM_VALUE            (TC_AVS_Get_MAXValue(0)) // modify for bug V35-36326
#define TC_MAX_AVS_DISP_MILE_VALUE          (TC_AVS_Get_MAXValue(1)) // modify for bug V35-36326

#define TC_MAX_DTE                         	((uint32)999 * 1000UL)
#define TC_MIN_DTE_DOWN						((uint32)40 * 1000uL)
#define TC_MIN_DTE_UP						((uint32)50 * 1000uL)

#define TC_MAX_FUEL_COSUME_COUNT            ((uint16)0xffff)

#define TC_MAX_ODO_COUNT                     ((uint16)254)
#define TC_MAX_FUEL_COUNT                  	((uint32)0x1FFFE)
#define TC_MAX_TIME_COUNT                  	(0xFFFFuL)
#define TC_MAX_ENERGY_COUNT                     ((uint16)0x3ff)

#define TC_SPEED_THRESHOLD_MUL_FACTOR 	  	((uint16)10)

#define TC_IFE_MAX_DISPLAY_VALUE_METRIC_L_NVM  (999u) /* display max =99.9*/
/*@20200924 fix ife display max value Defect V35-14521*/
#define TC_IFE_MAX_DISPLAY_VALUE_METRIC_H_NVM  (299u)

/*fix afe display max value Defect V35-14501*/
#define TC_AFE_MAX_DISPLAY_VALUE_METRIC_H_NVM  (299UL)//550;

#define TC_MIN_MILEAGE_TIME_NVM   (20u) /* 0-60 seconds, unit is 1 second */
#define TC_MIN_MILEAGE_NVM   (3u)

#define TC_MAX_IFE_LPHKM                 	(uint32)(TC_IFE_MAX_DISPLAY_VALUE_METRIC_H_NVM * 100)
#define TC_MAX_IFE_LPH                   	(uint32)(((TC_IFE_MAX_DISPLAY_VALUE_METRIC_L_NVM)+1)*10u)   /* TC_MAX_IFE_LPH=200 mean 20.0 L/h */
	
#define TC_MAX_AFE_LPHKM                 	(uint32)(TC_AFE_MAX_DISPLAY_VALUE_METRIC_H_NVM * 100u)

#define TC_COLD_FINISH_INIT_MASK            ((uint32)0xa5a5a5a5)

//#define TC_TIME_CAL
#ifdef TC_TIME_CAL
typedef struct
{
    uint32 time_stamp[2];                  /* execution start/stop time stamps */
    uint32 min_exec_time;                  /* minimum execution time in counts */
    uint32 max_exec_time;                  /* maximum execution time in counts */
    uint32 avg_exec_time;                  /* average execution time in counts */
    uint32 tot_exec_time;                  /* scratch for average calculation */
    uint32 num_samples;                    /* number of executions accounted */
	uint32 exeTime;
    boolean reset_buffer;                  /* reset buffer flag */
} TC_EM_BUFFER;

typedef enum
{		
	TC_task_input = 0,	
	TC_task_cal,	
	TC_task_uptae,  
	TC_Takk_max,
} TC_TASK_TYPE;

#define SWC_TC_START_SEC_CODE
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern void TM_TimerElapsed(uint32 * StartStamp, uint32 * TimeElapsed);
extern void TM_TimerStartStamp(uint32 * StartStamp);

#define SWC_TC_STOP_SEC_CODE
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define TC_TEST_TIME  0xffff 
#define TC_TASK_END_CALCULATE(current_task_id)\
{    \
\
	TM_TimerElapsed(&TC_Task_em_buffer[current_task_id].time_stamp[0],&TC_Task_em_buffer[current_task_id].time_stamp[1]);\
\
	TC_Task_em_buffer[current_task_id].exeTime = TC_Task_em_buffer[current_task_id].time_stamp[1]/10;/*uint : 1us*/\
\
	if(TC_Task_em_buffer[current_task_id].max_exec_time < TC_Task_em_buffer[current_task_id].exeTime)\
	{\
		TC_Task_em_buffer[current_task_id].max_exec_time = TC_Task_em_buffer[current_task_id].exeTime;\
	}\
\
	if(TC_Task_em_buffer[current_task_id].min_exec_time > TC_Task_em_buffer[current_task_id].exeTime)\
	{\
		TC_Task_em_buffer[current_task_id].min_exec_time = TC_Task_em_buffer[current_task_id].exeTime;\
	}\
\
	if((TC_Task_em_buffer[current_task_id].tot_exec_time < (TC_TEST_TIME))&&(FALSE == TC_Task_em_buffer[current_task_id].reset_buffer))\
	{\
		TC_Task_em_buffer[current_task_id].tot_exec_time+= TC_Task_em_buffer[current_task_id].exeTime;\
		TC_Task_em_buffer[current_task_id].num_samples++;\
	}\
	else\
	{\
		TC_Task_em_buffer[current_task_id].avg_exec_time = TC_Task_em_buffer[current_task_id].tot_exec_time/TC_Task_em_buffer[current_task_id].num_samples;\
		TC_Task_em_buffer[current_task_id].tot_exec_time = TC_Task_em_buffer[current_task_id].exeTime;\
		TC_Task_em_buffer[current_task_id].num_samples = 1;\
		TC_Task_em_buffer[current_task_id].reset_buffer = FALSE;\
	}\
	Rte_Exit_ExclusiveArea_Normal(); \
	}\

	
#define TC_TASK_BEGIN_CALCULATE(current_task_id)	\
{  Rte_Enter_ExclusiveArea_Normal();\
   TM_TimerStartStamp(&TC_Task_em_buffer[current_task_id].time_stamp[0]);\
}\


typedef struct
{
	uint32			 		TimerTick_u32;
	uint8					Status_u8;
}s_tcOstmData_t;   

typedef struct 
{
	uint32 tcRunableTimerTest_MAX;
	uint32 tcRunableTimerTest_MIN;
	uint32 tcRunableTimerTest_AVG;
	uint32 tcRunableTimerTest_Index;
	uint64 tcRunableTimerTest_Alltime;
	uint32 tcRunableTimerTest_MAXRunTime;
	uint32 tcRunableTimerTest_AVGRunTime;
	uint32 tcRunableTimerTest_IndexRunTime;
	uint32 tcRunableTimerTest_OverTimeTick;
	uint64 tcRunableTimerTest_AlltimeRunTime;
}s_tcRunableTimerTest_t;

#define SWC_TC_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

static TC_EM_BUFFER TC_Task_em_buffer[3];

TC_TASK_TYPE tc_task_chek;

s_tcRunableTimerTest_t tcRunableTimerTest[TC_Takk_max];

s_tcOstmData_t  tcOstmTickCounter_s[TC_Takk_max];

#define SWC_TC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define SWC_TC_START_SEC_CODE
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

static void tc_RteAdaptRunableOstmStart(TC_TASK_TYPE index)
{
	uint32 passtime;
	TM_TimerElapsed(&tcOstmTickCounter_s[index].TimerTick_u32,&passtime);
	TM_TimerStartStamp(&tcOstmTickCounter_s[index].TimerTick_u32);
	if(passtime > tcRunableTimerTest[index].tcRunableTimerTest_MAXRunTime)
	{
		tcRunableTimerTest[index].tcRunableTimerTest_MAXRunTime = passtime;
	}
	if((index == 1 && passtime > 200000) || (index == 2 && passtime > 100000))
	{
		tcRunableTimerTest[index].tcRunableTimerTest_OverTimeTick ++;
	}
	tcRunableTimerTest[index].tcRunableTimerTest_IndexRunTime++;
	tcRunableTimerTest[index].tcRunableTimerTest_AlltimeRunTime += passtime;
	tcRunableTimerTest[index].tcRunableTimerTest_AVGRunTime = (uint32)(tcRunableTimerTest[index].tcRunableTimerTest_AlltimeRunTime/tcRunableTimerTest[index].tcRunableTimerTest_Index);
	Rte_Enter_ExclusiveArea_Normal();

}


static tc_RteAdaptRunableOstmCheck(TC_TASK_TYPE index)
{
	uint32 passtime;
	TM_TimerElapsed(&tcOstmTickCounter_s[index].TimerTick_u32,&passtime);
	TM_TimerStartStamp(&tcOstmTickCounter_s[index].TimerTick_u32);
	if(passtime > 15000)
	{
		passtime ++;
	}
	if(passtime > tcRunableTimerTest[index].tcRunableTimerTest_MAX)
	{
		tcRunableTimerTest[index].tcRunableTimerTest_MAX = passtime;
	}
	if(passtime < tcRunableTimerTest[index].tcRunableTimerTest_MIN)
	{
		tcRunableTimerTest[index].tcRunableTimerTest_MIN = passtime;
	}
	tcRunableTimerTest[index].tcRunableTimerTest_Index++;
	tcRunableTimerTest[index].tcRunableTimerTest_Alltime += passtime;
	tcRunableTimerTest[index].tcRunableTimerTest_AVG = (uint32)(tcRunableTimerTest[index].tcRunableTimerTest_Alltime/tcRunableTimerTest[index].tcRunableTimerTest_Index);
	Rte_Exit_ExclusiveArea_Normal();
}

#define SWC_TC_STOP_SEC_CODE
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif 


/**********************************************************************************************************
*																										  *
*																										  *
*				              Macro																		  *
*																										  *
*																										  *
**********************************************************************************************************/

#define SWC_TC_START_SEC_CONST_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#if 0
static const uint16 TC_IFE_MAX_DISPLAY_VALUE_METRIC_L_NVM = 999u; /* display max =99.9*/

/*@20200924 fix ife display max value Defect V35-14521*/
static const uint16 TC_IFE_MAX_DISPLAY_VALUE_METRIC_H_NVM = 299u;

/*fix afe display max value Defect V35-14501*/
static const uint16 TC_AFE_MAX_DISPLAY_VALUE_METRIC_H_NVM = 299u;//550;

static const uint8  TC_MIN_MILEAGE_TIME_NVM  = 20u; /* 0-60 seconds, unit is 1 second */
static const uint8  TC_MIN_MILEAGE_NVM  = 3u;
#endif
#define SWC_TC_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define SWC_TC_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

static uint8 TC_Trip_Input_Data_Status;

static uint8 TC_Prev_Odo_Count;

static uint16 TC_Prev_Fuel_Consume_Count;

static uint16 TC_Prev_Odo_rcCount;

static uint32 TC_RCan_Get_Fuel_Samples_Times_Old;

static uint8 TC_VehRunningSts;

/*****************************************************************************
*                                 Extern Global Variable                     *
******************************************************************************/
boolean TC_Module_Init_Flag;

uint8 TC_Trip_Singal_Status;

TC_DEBUG_STRUCT TC_Ftrip_Info;  //only use for debug

#define SWC_TC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define SWC_TC_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#ifdef TC_VEHICLE_LOG_OUTPUT
static boolean TC_counter = FALSE;
static uint16 TC_period_counter = 0;
static uint8 TC_EVENT3_Flag = 0;
static uint8 TC_LOG_BYTE0 = 0;
static uint8 TC_LOG_BYTE1 = 0;
static uint8 TC_LOG_BYTE2 = 0;
static uint8 TC_LOG_POWER_MODE_FLAG = 2u;
static uint8 TC_Dte_Delay_Log_Count_ON = 0;
static uint8 TC_Dte_Delay_Log_Count_OFF = 0;
static uint8 DTE_ERROR_EVENT_FLAG = 0;
static uint8 TC_log_message_type = 0;

#define TC_LOG_CFG_INFORMATION_ENABLE           TC_LOG_BYTE0 
#define TC_LOG_CFG_INFORMATION_LIMIT_VALUE      TC_LOG_BYTE1 
#define TC_LOG_CAL_INFORMATION                  TC_LOG_BYTE2 
#endif


static boolean TC_Odo_Fuel_MIssing_Status = FALSE;
static uint8 TC_Dte_Delay_Count = 0;
#ifdef TC_DTE_NEW_STRATEGY_0413
static uint16 TC_Dte_Error_Count = 0;
static uint32 TC_Dte_Slow_K=0;             
static boolean TC_Dte_idle_update = FALSE;
#endif 

#ifdef TC_DTE_MENU_RESET_ENABLE
static boolean TC_Dte_Reset_update = FALSE;
#endif 
#define TC_FUEL_IFC_QUEUE_L   10u
#define TC_FUEL_IFC_INIT_DATA 100u /*10.0 L/KM */

static uint32  TC_TDT_Time_Init_Status = 0;
static uint32  TC_Collect_Time_Init_Status = 0;

#define SWC_TC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#pragma ghs section bss=".buram"   /*@20200929 define data to specified BURAM area*/
/*****************************************************************************
*                                 Static Global Variable                     *
******************************************************************************/
static uint32  TC_Cold_Init_Finish;
static uint16  TC_FUEL_IFC_QUEUE[TC_FUEL_IFC_QUEUE_L];
static uint8   TC_FUEL_IFC_QUEUE_PT;
static uint32  TC_FUEL_IFC_QUEUE_SUM;
static uint8   TC_FUEL_Singal_Status;

static uint8  TC_Reset_Index;

static boolean TC_Travel_Time_Calculate_Flag_Enable; /*used for begine calculate driver time*/

static TC_MODULE_OUTPUT_DATA_STRUCT TC_Module_Output_Data_Value;


#ifdef TC_VEHICLE_LOG_OUTPUT

static TC_Log_Period RFP_TC_2;
static TC_LOG_RFP RFP_TC_3;

#endif


/*****************************************************************************
*                                 Extern Global Variable                     *
******************************************************************************/
TC_TOTAL_STRUCT TC_Ftrip_T;

TC_VEHICLE_TYPE_ENUM  TC_Module_Vehicle_Type_Data;
TC_VEHICLE_MOTOR_TYPE_ENUM TC_Module_Motor_Type_Data;

#pragma ghs section bss=default

#define SWC_TC_START_SEC_CODE
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
static void TC_Api_Update_Phev_Dte(void);
uint16 TC_Api_Get_DTE_Phev_Value_For_Hmi(uint8 speed_uint);
uint16 TC_Api_Get_DTE_Phev_Value(void);
TC_Energy_data_t * TC_Api_Emergy_get_data(void);
TC_SW_TIMER_STATE TC_Api_Sw_Timer_Check(TC_SW_TIMER_ID id);
void TC_Api_Sw_timer_start(TC_SW_TIMER_ID id, uint16 time);
void TC_Api_Sw_timer_set_state(TC_SW_TIMER_ID id, TC_SW_TIMER_STATE state);
void TC_Api_Sw_timer_clear(TC_SW_TIMER_ID id);
void TC_Api_Emergy_update_mode_set(TC_ENERGY_UPDATE_MODE mode);
TC_ENERGY_UPDATE_MODE TC_Api_Emergy_update_mode_get(void);
void TC_Api_Update_trip(void);
TC_XFE_UNIT_ENUM TC_Api_Get_IFE_Display_Unit(void);
//uint32 Tc_api_abs(sint32 c);
uint32 TC_Api_u32_abs(uint32 a, uint32 b);
void TC_Api_Reset_AFE_For_Hmi(uint8 type);
static boolean TC_Api_AFE_Accum_Enable(void);
static boolean TC_Api_IFE_Accum_Enable(void);
static boolean TC_Api_DTE_Accum_Enable(void);
static boolean TC_Api_DTE_cal_Enable(void);
static boolean TC_Api_AVS_Display_Condition(void);
static boolean TC_Api_AFE_Display_Condition(void);

#if 1 
static void TC_Api_Emergy_Cold_Init(void);
static void TC_Api_Emergy_Warm_Init(void);
#ifdef TC_VEHICLE_LOG_OUTPUT
static void TC_LOG_RECORD(uint8 number);
static void TC_log_Task(void);
static void TC_Log_Conditional_Judgment(void);
//static void TC_log_trace_snapshot(uint8 *type);
static void TC_LOG_BIT_MANAGE(uint8 *sum_value, uint8 one_value, uint8 constant0);

#endif

/**********************************************************************************************************
*Function   : TC_Api_Accum_EgyUsed_Count                                                                  *
*                                                                                                         *
*Description:  Calculate power consumption and recovery power consumption                                 *
*
*Parameter	: void      																	              *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: shu junhua                                                                                   *
*                                                                                                         *
*Date       : 2020-2-7                                                                                    *
**********************************************************************************************************/
static void TC_Api_Accum_EgyUsed_Count(void);

/**********************************************************************************************************
*Function   : TC_Api_Emergy_Get_TripNotSentPer1km                                                         *
*                                                                                                         *
*Description: Obtain the data within 1km before the completion of charging                                *                                                                                                         *
*
*Parameter	: void     s 																	              *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: shu junhua                                                                                   *
*                                                                                                         *
*Date       : 2020-1-4                                                                                    *
**********************************************************************************************************/
static void  TC_Api_Emergy_Get_TripNotSentPer1km(uint16 value );


#endif 

/**********************************************************************************************************
*Function   : TC_Api_Computer_AFE                                                             	     	  *
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
static void  TC_Api_Computer_AFE(void);
/**********************************************************************************************************
*Function   : TC_Api_Computer_DTE                                                                    	  *
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

static void  TC_Api_Computer_DTE(void);
/**********************************************************************************************************
*Function   : TC_Api_Computer_AVS                                                                    	  *
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

static void  TC_Api_Computer_AVS(void);
/**********************************************************************************************************
*Function   : TC_Api_Computer_IFE                                                                    	  *
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

static void  TC_Api_Computer_IFE(void);
/**********************************************************************************************************
*Function   : TC_Api_Computer_Uint_IFE                                                                 	  *
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

static void  TC_Api_Computer_Uint_IFE(void);
/**********************************************************************************************************
*Function   : TC_Api_Computer_Low_Threshold_IFE                                                       	  *
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

static void  TC_Api_Computer_Low_Threshold_IFE(void);
/**********************************************************************************************************
*Function   : TC_Api_Computer_High_Threshold_IFE                                                      	  *
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

static void  TC_Api_Computer_High_Threshold_IFE(void);
/**********************************************************************************************************
*Function   : TC_Api_Clear_Fuel_Samples_TimeTrigger                                                    	  *
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

static void TC_Api_Clear_Fuel_Samples_TimeTrigger(void);
/**********************************************************************************************************
*Function   : TC_Api_Eol_Get_Fuel_State                                                                	  *
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
void TC_Api_Eol_Get_Fuel_State(void);
/**********************************************************************************************************
*Function   : TC_APi_Travel_Time_Calculate_Enable                                                     	  *
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
void TC_APi_Travel_Time_Calculate_Enable(void);

void TC_ipc_m2s_upadte(void);
void TC_Api_Reset_AVS_For_Hmi(uint8 type);

static void TC_Api_Update_TC_FUEL_IFC_10S_init(void)
{  
  uint8 i;
  uint32 temp;
  TC_FUEL_IFC_QUEUE_PT=0u;
  for(i=0;i<TC_FUEL_IFC_QUEUE_L;i++)	{TC_FUEL_IFC_QUEUE[i]=TC_FUEL_IFC_INIT_DATA;}
  TC_FUEL_IFC_QUEUE_SUM=TC_FUEL_IFC_QUEUE_L*TC_FUEL_IFC_INIT_DATA;
  temp=TC_FUEL_IFC_QUEUE_SUM;
  temp*=100u;
  temp/=TC_IFE_MAX_DISPLAY_VALUE_METRIC_H_NVM;
  TC_Ftrip_T.tIFC_10S=(uint16)temp;
}
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
void TC_Api_KSColdInit(void)
{
	uint8 i;
    TC_Module_Vehicle_Type_Data = TC_Rte_Api_Get_Vehicle_Type_Cfg(); 
    TC_Module_Motor_Type_Data =  TC_Rte_Api_Get_Motor_Cfg();
    TC_RTE_GetAllConfiguration();
	if ((FALSE != TC_Module_Rte_Coldinit_Warminit_Flag())&&(TC_Cold_Init_Finish == TC_COLD_FINISH_INIT_MASK)) // warm start
	{
		TC_Api_Config_Data_NVM_Init();/*2020 11 06 fix */
		TC_Api_KSWarmInit();
       // TC_Module_Init_Flag = FALSE;
	   
	}
	else
	{  
        TC_Module_Init_Flag = TRUE;
		TC_Trip_Singal_Status        = ((uint8)0);
		TC_Trip_Input_Data_Status    = ((uint8)0);
		
		TC_Trip_Input_Data_Status    = (TC_Trip_Input_Data_Status | TC_BATTERY_CONNECT_OR_RESET);
		TC_Prev_Odo_Count             = ((uint8)0);
		TC_RCan_Get_Fuel_Samples_Times_Old=((uint8)0);
		TC_Odo_Fuel_MIssing_Status    = FALSE;	
		
	  	(void)memset((char *)&TC_Ftrip_T,0,sizeof(TC_Ftrip_T));
		(void)memset((char *)&TC_Module_Output_Data_Value,0,sizeof(TC_Module_Output_Data_Value));
		
		for(i=0u;i<TC_MAX_NUM_OF_AVS;i++)
		{
			TC_Ftrip_T.tAVS.u32CurrentAVS[i] = TC_AVS_AFTER_RESET_DASHES;
			TC_Ftrip_T.tAVS.u32DisplayAVS[i] = TC_AVS_AFTER_RESET_DASHES;	
		}
		
		for(i=0u;i<TC_MAX_NUM_OF_AFE;i++)
		{		
			TC_Ftrip_T.tAFE.u32CurrentAFE[i] = TC_AFE_AFTER_RESET_DASHES;
			TC_Ftrip_T.tAFE.u32DisplayAFE[i] = TC_AFE_AFTER_RESET_DASHES;	
            TC_Ftrip_T.tAFE.u32DisplayAFE_bu[i] = TC_AFE_AFTER_RESET_DASHES;
		}

		TC_Ftrip_T.tIFE.u32CurrentIFE = TC_IFE_AFTER_RESET_DASHES;
		TC_Ftrip_T.tIFE.u32DisplayIFE = TC_IFE_AFTER_RESET_DASHES;	
		
	 	TC_Ftrip_T.tOff_Time.u16IgnOffTimeScale = 0xFFFF;

		TC_Ftrip_T.tDTE.u32CalculationDTE = TC_DTE_DISPLAY_DASHES;
	 	TC_Ftrip_T.tDTE.u32CurrentDTE     = TC_DTE_DISPLAY_DASHES;
		TC_Ftrip_T.tDTE.u32DisplayDTE     = TC_DTE_DISPLAY_DASHES;

		TC_Ftrip_T.tFuel.u8FuelAccumEnable = 1;
		TC_Ftrip_T.tFuel.u32FuelPulseAccum = 0;

		TC_Api_Config_Data_NVM_Init();
		
	  	TC_Pkg_ColdInit();

		TC_Api_Travel_Time_Reset_All();

		TC_Api_trip_Reset_All();

		TC_Collect_Time_Init_Status = 0;
		TC_TDT_Time_Init_Status = 0;
		TC_Api_Update_TC_FUEL_IFC_10S_init();
        TC_Ftrip_T.tDTE.u32DisplayTimeTick = TC_Ftrip_T.tTC_Config_NVM.RefreshRateDTEReFuel_NvmInit;
        #ifdef TC_VEHICLE_LOG_OUTPUT
        TC_Dte_Delay_Log_Count_ON = 0;
        TC_Dte_Delay_Log_Count_OFF = 0;
		#endif
	}
    #if 1
	//TC_Api_Emergy_Cold_Warm_Init();
        TC_Api_Emergy_Cold_Init();
    #endif 
    TC_Cold_Init_Finish = TC_COLD_FINISH_INIT_MASK;
}

/**********************************************************************************************************
*Function   : TC_Api_KSWarmInit                                                                     	  *
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
void TC_Api_KSWarmInit(void)
{
	//uint16 i = 0;

	TC_Trip_Singal_Status		= ((uint8)0);
	TC_Trip_Input_Data_Status	= ((uint8)0);

	TC_Trip_Input_Data_Status	= (TC_Trip_Input_Data_Status | TC_BATTERY_CONNECT_OR_RESET);
	TC_Prev_Odo_Count 			= ((uint8)0);
	TC_RCan_Get_Fuel_Samples_Times_Old=((uint8)0);
	TC_Reset_Index = 0;

	TC_Ftrip_T.tAVS.u32DisplayTimeTick = 0;
	TC_Ftrip_T.tAFE.u32DisplayTimeTick = 0;
	TC_Ftrip_T.tIFE.u32DisplayTimeTick = 0;
	TC_Ftrip_T.tDTE.u32DisplayTimeTick = 0;

	TC_Ftrip_T.tAVS.u32CalcTimeCount = 0;
	TC_Ftrip_T.tAFE.u32CalcTimeCount = 0;
	TC_Ftrip_T.tIFE.u32CalcTimeCount = 0;
	TC_Ftrip_T.tDTE.u32CalcTimeCount = 0;	
	TC_Pkg_WarmInit();
    TC_Api_Emergy_Warm_Init();
	
}
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
void TC_Api_KSWakeup(void)
{
	uint16 i;

	TC_Trip_Singal_Status = ((uint8)0);
	
	TC_Trip_Input_Data_Status = (TC_Trip_Input_Data_Status & ( TC_DATA_ACCUMULATED_ONCE_AFE |TC_DATA_ACCUMULATED_ONCE_AVS | TC_TRIP_FUEL_PULSE_CHANGE | TC_TRIP_ODO_COUNT_CHANGE | TC_BATTERY_CONNECT_OR_RESET) );
	TC_Prev_Odo_Count = ((uint8)0);
	TC_RCan_Get_Fuel_Samples_Times_Old = ((uint8)0);

	#if 1 /* cwang23 add */
	//modify by fchao in 20200615
	//KernelClear13BitTimer(ftrip_afe_display_KSWTIMER1);
	//KernelStart13BitTimer(TIMER_13BIT_BASE_512MS,((uint16)40),ftrip_afe_display_KSWTIMER2);
	for(i=0;i<TC_MAX_NUM_OF_AFE;i++)
	{
		TC_Ftrip_T.tAFE.u8NormalDisplay[i] = FALSE;
	}

	//KernelClear13BitTimer(ftrip_avs_display_KSWTIMER);
	//KernelStart13BitTimer(TIMER_13BIT_BASE_512MS,((uint16)40),ftrip_dte_display_KSWTIMER);
	#endif
}
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
void TC_Api_KSSleep(void)
{
  /*
  ** Disable Timer intrupt
  */
  //TC_CLEARBIT(FTRIP_TMSK_REG, FTRIP_OC_BIT);//wangran 20151226
  /*
  ** Clear the  channel flag
  */
  //TC_CLEARBIT(FTRIP_TFLG_REG,(~FTRIP_FLG_BIT));//wangran 20151226
  //FTRIP_TOC_REG = 0x00;//wangran 20151226
  /*
  ** Pakage function updates the stucture with accumalated data
  */
}
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
void TC_Api_Trans_Outof_Normal(void)
{
	
	/* modify by fchao in 20200615
	struct tm tm_time;
	RTCA_tstTime CurTime;
	RTCA_tstCalendar CurCalendar;

	RTCA_vReadTimeBufferRegister(&CurTime);
	RTCA_vReadCalendarBufferRegister(&CurCalendar);
	
	memset((char *)&tm_time,0,sizeof(tm_time));
	
	tm_time.tm_sec = CurTime.u8Second;
	tm_time.tm_min = CurTime.u8Minute;
	tm_time.tm_hour= CurTime.u8Hours;
	tm_time.tm_year= CurCalendar.u8Year;
	tm_time.tm_year= tm_time.tm_year + 10;
	tm_time.tm_mon = CurCalendar.u8Month-1;
	tm_time.tm_mday= CurCalendar.u8Day;
	TC_Ftrip_T.tOff_Time.u16IgnOffTimeScale = mktime(&tm_time);	
	*/

}
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
void TC_Api_Trans_Into_Normal(void)
{
// 	modify by fchao in 20200615
// 	time_t u32tc_time_scale;	
// 	struct tm tm_time;
// 	RTCA_tstTime CurTime;
// 	RTCA_tstCalendar CurCalendar;

// 	RTCA_vReadTimeBufferRegister(&CurTime);
// 	RTCA_vReadCalendarBufferRegister(&CurCalendar);
// 	memset((char *)&tm_time,0,sizeof(tm_time));
	
// 	tm_time.tm_sec = CurTime.u8Second;
// 	tm_time.tm_min = CurTime.u8Minute;
// 	tm_time.tm_hour= CurTime.u8Hours;
// 	tm_time.tm_year= CurCalendar.u8Year;
// 	tm_time.tm_year= tm_time.tm_year + 10;
// 	tm_time.tm_mon = CurCalendar.u8Month-1;
// 	tm_time.tm_mday= CurCalendar.u8Day;
// 	u32tc_time_scale = mktime(&tm_time);
// 	if(TC_Ftrip_T.tOff_Time.u16IgnOffTimeScale==0xffffffff)	//init u32TCLimitTimeScale
// 	{
// 		TC_Ftrip_T.tOff_Time.u16IgnOffTimeScale = u32tc_time_scale;
// 	}
// //for bat voltage low down to 6V,the backup ram data is reset, and core will call the function		
// 	else if((u32tc_time_scale>=TC_Ftrip_T.tOff_Time.u16IgnOffTimeScale)&&(TC_Ftrip_T.tOff_Time.u16IgnOffTimeScale>0))
// 	{
// 		u32tc_time_scale = u32tc_time_scale - TC_Ftrip_T.tOff_Time.u16IgnOffTimeScale;
// 		if(u32tc_time_scale>=7200)	//2h (unit: sec)
// 		{
// 			fodo_reset_trip(0);
// 			TC_Api_AFE_Reset(0);
// 			TC_Api_AVS_Reset(0);
// 			TC_Api_Travel_Time_Reset_Value(0);
// 		}
// 	}
// 	else
// 	{
// 		TC_Ftrip_T.tOff_Time.u16IgnOffTimeScale = u32tc_time_scale;
// 	}
	

}
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
void TC_Api_Config_Data_NVM_Init(void)
{
	CconfigKind_400Bytes Lcal_config_data;
	boolean Lcal_config_status = FALSE;
	uint64 calc_temp;
    stTC_RTE_DteSfcInit DteSfcInit = {0,0,0,0};
	Lcal_config_status = TC_Rte_Api_Get_Cconfig_Cfg(Lcal_config_data);

	if(FALSE != Lcal_config_status)
	{
	//	TC_Ftrip_T.tTC_Config_NVM.IFC_Fuel_Damp_Upate_NvmInit = ((uint16)Lcal_config_data[55] << 8) + (uint16)Lcal_config_data[54];
        TC_Ftrip_T.tTC_Config_NVM.IgnOffTimeScale_NvmInit = 24 * 10 * 60;
        TC_Ftrip_T.tTC_Config_NVM.TankReserveVol_NvmInit = 30 / 10;
        /*AFE :20210304 for cconfig v1.5 update*****************************************************/
        TC_Ftrip_T.tTC_Config_NVM.RefreshRateAFC_NvmInit =(uint16)CConfig_GetConfig(CCONFIG_KIND_RefreshRateAFC,Lcal_config_data);
        TC_Ftrip_T.tTC_Config_NVM.Max_fuelConPerCycle_NvmInit = (uint16)CConfig_GetConfig(CCONFIG_KIND_Max_fuelConPerCycle,Lcal_config_data);
        TC_Ftrip_T.tTC_Config_NVM.AFCMinDistanceThresh_NvmInit =(uint16)((CConfig_GetConfig(CCONFIG_KIND_AFCMinDistanceThresh,Lcal_config_data)*1000uL/10u)*10u); 
       
        //((uint16)Lcal_config_data[119] * 1000 / 10) * 10;
        TC_Ftrip_T.tTC_Config_NVM.AFCADisplayEnable_NvmInit = (uint16)CConfig_GetConfig(CCONFIG_KIND_AFCADisplayEnable,Lcal_config_data);//(uint16)Lcal_config_data[120];
        TC_Ftrip_T.tTC_Config_NVM.AFCBDisplayEnable_NvmInit = (uint16)CConfig_GetConfig(CCONFIG_KIND_AFCBDisplayEnable,Lcal_config_data);//(uint16)Lcal_config_data[121];
        
        /*TravelTime**20210304 for cconfig v1.5 update***********************************************/
        calc_temp = CConfig_GetConfig(CCONFIG_KIND_TravelTimeDisplayLimited,Lcal_config_data);
        TC_Ftrip_T.tTC_Config_NVM.TravelTimeADisplayEnable_NvmInit =(uint16)CConfig_GetConfig(CCONFIG_KIND_TravelTimeADisplayEnable,Lcal_config_data); 
        TC_Ftrip_T.tTC_Config_NVM.TravelTimeBDisplayEnable_NvmInit =(uint16)CConfig_GetConfig(CCONFIG_KIND_TravelTimeBDisplayEnable,Lcal_config_data);
        TC_Ftrip_T.tTC_Config_NVM.TravelTimeDisplayLimited_Minute_NvmInit = (uint16)(((calc_temp / 10u) % 3600uL) / 60u);
        TC_Ftrip_T.tTC_Config_NVM.TravelTimeDisplayLimited_Hour_NvmInit = (uint16)(calc_temp / 10u / 3600uL);
        
        /*IFE**20210304 for cconfig v1.5 update***********************************************/
        TC_Ftrip_T.tTC_Config_NVM.RefreshRateIFC_NvmInit =(uint16)CConfig_GetConfig(CCONFIG_KIND_RefreshRateIFC,Lcal_config_data);
        TC_Ftrip_T.tTC_Config_NVM.IFC_POC_Update_NvmInit = 100;/*@20200924 fix ife refresh time 1s*/	
        TC_Ftrip_T.tTC_Config_NVM.IFCDisplayEnable_NvmInit =(uint16)CConfig_GetConfig(CCONFIG_KIND_IFCDisplayEnable,Lcal_config_data);
        
        /*AVS**20210304 for cconfig v1.5 update***********************************************/
        TC_Ftrip_T.tTC_Config_NVM.RefreshRateAVS_NvmInit =(uint16)CConfig_GetConfig(CCONFIG_KIND_RefreshRateAVS,Lcal_config_data);
        calc_temp = CConfig_GetConfig(CCONFIG_KIND_AVSMinDistanceThresh,Lcal_config_data);
        TC_Ftrip_T.tTC_Config_NVM.AVSMinDistanceThresh_NvmInit = (uint16)((calc_temp * 1000uL / 10u) * 10u);
        TC_Ftrip_T.tTC_Config_NVM.AVSBDisplayEnable_NvmInit =(uint16)CConfig_GetConfig(CCONFIG_KIND_AVSBDisplayEnable,Lcal_config_data);
        TC_Ftrip_T.tTC_Config_NVM.AVSADisplayEnable_NvmInit =(uint16)CConfig_GetConfig(CCONFIG_KIND_AVSADisplayEnable,Lcal_config_data);

        /*DTE **20210304 for cconfig v1.5 update***********************************************/
        TC_Ftrip_T.tTC_Config_NVM.RefreshRateDTE_NvmInit =(uint16)CConfig_GetConfig(CCONFIG_KIND_RefreshRateDTE,Lcal_config_data); 
        /* this is invaild*/
        TC_Ftrip_T.tTC_Config_NVM.RefreshRateDTEReFuel_NvmInit =(uint16)CConfig_GetConfig(CCONFIG_KIND_RefreshRateDTEReFuel,Lcal_config_data);


        TC_Ftrip_T.tTC_Config_NVM.SFCMin_NvmInit =(uint16)CConfig_GetConfig(CCONFIG_KIND_SFCMin,Lcal_config_data);
        TC_Ftrip_T.tTC_Config_NVM.SFCMax_NvmInit = (uint16)CConfig_GetConfig(CCONFIG_KIND_SFCMax,Lcal_config_data);
        TC_Ftrip_T.tTC_Config_NVM.RangeIncThreshold_NvmInit = (uint16)CConfig_GetConfig(CCONFIG_KIND_RangeIncThreshold,Lcal_config_data);
        TC_Ftrip_T.tTC_Config_NVM.RangeDecThreshold_NvmInit =(uint16)CConfig_GetConfig(CCONFIG_KIND_RangeDecThreshold,Lcal_config_data);
        calc_temp = CConfig_GetConfig(CCONFIG_KIND_FastUpdateTime,Lcal_config_data);
        TC_Ftrip_T.tTC_Config_NVM.FastUpdateTime_NvmInit =(uint32)(calc_temp *10u);
        calc_temp = CConfig_GetConfig(CCONFIG_KIND_SlowUpdateTime,Lcal_config_data);
        TC_Ftrip_T.tTC_Config_NVM.SlowUpdateTime_NvmInit = (uint32)(calc_temp *10u);
        calc_temp = CConfig_GetConfig(CCONFIG_KIND_IdleUpdateTime,Lcal_config_data);
        TC_Ftrip_T.tTC_Config_NVM.IdleUpdateTime_NvmInit = (uint32)(calc_temp *10u);
        calc_temp = CConfig_GetConfig(CCONFIG_KIND_UnNormalUpdateTime,Lcal_config_data);
        TC_Ftrip_T.tTC_Config_NVM.UnNormalUpdateTime_NvmInit = (uint32)(calc_temp *10u);

        /*PHEV DTE **20210304 for cconfig v1.5 update***********************************************/
        TC_Ftrip_T.tTC_Config_NVM.Phev_sMaxDisplayPHEVRange=(uint8)CConfig_GetConfig(CCONFIG_KIND_MaxDisplayPHEVRange,Lcal_config_data);
        TC_Ftrip_T.tTC_Config_NVM.Phev_Dte_DisplayEnable_NvmInit=(uint8)CConfig_GetConfig(CCONFIG_KIND_PHEV_HEVDTEDisplayEnable,Lcal_config_data);
        TC_Ftrip_T.tTC_Config_NVM.Phev_Dte_RefreshRatePHEVDTE =(uint16)CConfig_GetConfig(CCONFIG_KIND_RefreshRatePHEVDTE,Lcal_config_data);
        /*10; 1S=10*100MS*/

	}
	else
	{
		TC_Ftrip_T.tTC_Config_NVM.Max_fuelConPerCycle_NvmInit = 1950;

		TC_Ftrip_T.tTC_Config_NVM.IgnOffTimeScale_NvmInit = 24 * 10 * 60;
		
		TC_Ftrip_T.tTC_Config_NVM.TravelTimeDisplayLimited_Hour_NvmInit = 99;
		TC_Ftrip_T.tTC_Config_NVM.TravelTimeDisplayLimited_Minute_NvmInit = 59;
		TC_Ftrip_T.tTC_Config_NVM.TravelTimeADisplayEnable_NvmInit = 1;
		TC_Ftrip_T.tTC_Config_NVM.TravelTimeBDisplayEnable_NvmInit = 1;
		
		TC_Ftrip_T.tTC_Config_NVM.RefreshRateIFC_NvmInit = 10;
		TC_Ftrip_T.tTC_Config_NVM.IFC_POC_Update_NvmInit = 100;/*@20200924 fix ife refresh time 1s*/
		TC_Ftrip_T.tTC_Config_NVM.IFCDisplayEnable_NvmInit = 1;
		
		TC_Ftrip_T.tTC_Config_NVM.RefreshRateAFC_NvmInit = 100;
		TC_Ftrip_T.tTC_Config_NVM.AFCMinDistanceThresh_NvmInit = (3 * 1000 / 10) * 10;
		TC_Ftrip_T.tTC_Config_NVM.AFCADisplayEnable_NvmInit = 1;
		TC_Ftrip_T.tTC_Config_NVM.AFCBDisplayEnable_NvmInit = 1;
		
		TC_Ftrip_T.tTC_Config_NVM.RefreshRateAVS_NvmInit = 100;
		TC_Ftrip_T.tTC_Config_NVM.AVSMinDistanceThresh_NvmInit = (3 * 1000 / 10) * 10;
		TC_Ftrip_T.tTC_Config_NVM.AVSADisplayEnable_NvmInit = 1;
		TC_Ftrip_T.tTC_Config_NVM.AVSBDisplayEnable_NvmInit = 1;
		
		TC_Ftrip_T.tTC_Config_NVM.RefreshRateDTE_NvmInit = 100;
		TC_Ftrip_T.tTC_Config_NVM.RefreshRateDTEReFuel_NvmInit = 10;
		TC_Ftrip_T.tTC_Config_NVM.TankReserveVol_NvmInit = 30 / 10;

		TC_Ftrip_T.tTC_Config_NVM.SFCMin_NvmInit = 50;
		TC_Ftrip_T.tTC_Config_NVM.SFCMax_NvmInit = 299;
		TC_Ftrip_T.tTC_Config_NVM.RangeIncThreshold_NvmInit = 20;
		TC_Ftrip_T.tTC_Config_NVM.RangeDecThreshold_NvmInit = 10;
		TC_Ftrip_T.tTC_Config_NVM.FastUpdateTime_NvmInit = 1 * 10;
		TC_Ftrip_T.tTC_Config_NVM.SlowUpdateTime_NvmInit = 3 * 10;
		TC_Ftrip_T.tTC_Config_NVM.IdleUpdateTime_NvmInit = 10 * 10;
		TC_Ftrip_T.tTC_Config_NVM.UnNormalUpdateTime_NvmInit = 40 * 10;

        TC_Ftrip_T.tTC_Config_NVM.Phev_sMaxDisplayPHEVRange=254;
        TC_Ftrip_T.tTC_Config_NVM.Phev_Dte_DisplayEnable_NvmInit=1;
        TC_Ftrip_T.tTC_Config_NVM.Phev_Dte_RefreshRatePHEVDTE =10; /*1S=10*100MS*/
	}

    // SFC Config
    DteSfcInit = TC_Adapt_Api_Get_DteSfcInit();
    TC_Ftrip_T.tTC_Config_NVM.STripAgeInitTripBileage = DteSfcInit.STripAgeInitTripBileage;  /* init trip =75km  */
    TC_Ftrip_T.tTC_Config_NVM.StripAgeFuelInitFuelCon = DteSfcInit.StripAgeFuelInitFuelCon;
    TC_Ftrip_T.tTC_Config_NVM.SFCDefault_NvmInit      = DteSfcInit.SFCDefault_NvmInit;
    TC_Ftrip_T.tTC_Config_NVM.STripAgeTolTripBileage  = DteSfcInit.STripAgeTolTripBileage;
    
}

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
uint8 TC_Api_Accum_Enable(void)
{
	/* modify by fchao in 20200615
	uint8   car_fdiag_mode_U8 = 0;
	car_fdiag_mode_U8 = (System_Conf_F100->u8ModeConf & 0x03);

	if((0x01==car_fdiag_mode_U8)||(0x02==car_fdiag_mode_U8))
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
	*/
	return ((uint8)1);
}
/**********************************************************************************************************
*Function   : TC_Api_AVS_Accum_Enable                                                                 	  *
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
static boolean TC_Api_AVS_Accum_Enable(void)
{	
/*make a distinction by fuel type*/
    boolean result=FALSE;
	if((TC_VEHICLE_FUEL == TC_Module_Vehicle_Type_Data) || (TC_VEHICLE_FUEL_DIESEL == TC_Module_Vehicle_Type_Data))
	{
        if(FALSE != TC_API_Get_EngSpd_State()) /*TBD */
        {
            result=TRUE;
        }
        else
        {
            result=FALSE; // return FALSE;
        }
       
	}
	else if ((TC_VEHICLE_PHEV==TC_Module_Vehicle_Type_Data)||(TC_VEHICLE_HEV==TC_Module_Vehicle_Type_Data))
    {
        if (FALSE !=TC_Hev_Phev_VehStartingSts)
        {
            result=TRUE;
        }
        else
        {
            result=FALSE; // return FALSE;
        }       
    }	
    else
    {
        result=FALSE; // return FALSE;
    }
    return result;
}
/**********************************************************************************************************
*Function   : TC_Api_AFE_Accum_Enable                                                                 	  *
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
static boolean TC_Api_AFE_Accum_Enable(void)
{	
/*make a distinction by fuel type*/
    boolean result = FALSE;
    boolean odoErr = FALSE;
    boolean ecmErr = FALSE;
    boolean fuelresult = FALSE;
    odoErr = TC_RTE_API_Get_ODO_err();
    ecmErr = TC_RTE_API_Get_ECM2_err();
    fuelresult = TC_RTE_API_Get_AFE_Fuel_Condition();
    if((TC_VEHICLE_FUEL == TC_Module_Vehicle_Type_Data) || (TC_VEHICLE_FUEL_DIESEL == TC_Module_Vehicle_Type_Data))
    {
       result = fuelresult;
    }
    else if ((TC_VEHICLE_PHEV==TC_Module_Vehicle_Type_Data)||(TC_VEHICLE_HEV==TC_Module_Vehicle_Type_Data))
    {
        if ((FALSE !=TC_Hev_Phev_VehStartingSts)&&(FALSE == odoErr)\
            &&(FALSE== ecmErr))
        {
            result=TRUE;
        }
        else
        {
            result=FALSE; // return FALSE;
        }
    }
    else
    {
        result=FALSE; // return FALSE;
    }
    return result;
}
/**********************************************************************************************************
*Function   : TC_Api_IFE_Accum_Enable                                                                  	  *
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
static boolean TC_Api_IFE_Accum_Enable(void)
{  
    boolean result = FALSE;
	
	if((TC_VEHICLE_FUEL == TC_Module_Vehicle_Type_Data)||\
       (TC_VEHICLE_FUEL_DIESEL == TC_Module_Vehicle_Type_Data)||\
       (TC_VEHICLE_HEV == TC_Module_Vehicle_Type_Data)||\
       (TC_VEHICLE_PHEV == TC_Module_Vehicle_Type_Data))
	{
       #if 0 
		if(FALSE != TC_API_Get_EngSpd_State()) /*TBD */
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
		#endif 
		result = TRUE;
	}
	else
	{
		result = FALSE;
	}  

	return result;
    
}
/**********************************************************************************************************
*Function   : TC_Api_DTE_Accum_Enable                                                                  	  *
*                                                                                                         *
*Description: DTE  Fuel consumption calculation conditions                                                *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Shujunhua                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
*Date		: 2020-04-24  adapt to HEV Vehicle                                                            *

**********************************************************************************************************/
static boolean TC_Api_DTE_Accum_Enable(void)
{  
    boolean result = FALSE;
    boolean vehRunningSts = FALSE;
    boolean odoErr = FALSE;
    boolean ecmErr = FALSE;
    uint8 hcu_cdcsflag = TC_Rte_Get_HCU_CDCSFlag();
    vehRunningSts = TC_API_Get_VehRunning_State();
    odoErr = TC_RTE_API_Get_ODO_err();
    ecmErr = TC_RTE_API_Get_ECM2_err();
    if((TC_VEHICLE_FUEL == TC_Module_Vehicle_Type_Data) || (TC_VEHICLE_FUEL_DIESEL == TC_Module_Vehicle_Type_Data)\
    || (TC_VEHICLE_PHEV==TC_Module_Vehicle_Type_Data) || (TC_VEHICLE_HEV==TC_Module_Vehicle_Type_Data))
    {
        if((FALSE == odoErr) && (FALSE== ecmErr))
        {
            if((TC_VEHICLE_FUEL == TC_Module_Vehicle_Type_Data)||(TC_VEHICLE_FUEL_DIESEL == TC_Module_Vehicle_Type_Data)\
            ||((TC_VEHICLE_PHEV == TC_Module_Vehicle_Type_Data) && (TC_Module_Motor_Type_Data!=TC_VEHICLE_MOTOR_PS)&&(TC_Module_Motor_Type_Data!=TC_VEHICLE_MOTOR_PS_P4) ))
            {
                if((FALSE != TC_API_Get_EngSpd_State()) && (FALSE != vehRunningSts))
                {
                    result = TRUE;
                }
                else
                {
                    result = FALSE;
                }
            }
            else if ((TC_VEHICLE_HEV == TC_Module_Vehicle_Type_Data) && \
            ((TC_Module_Motor_Type_Data==TC_VEHICLE_MOTOR_P2)||(TC_Module_Motor_Type_Data==TC_VEHICLE_MOTOR_PS)\
            || (TC_Module_Motor_Type_Data==TC_VEHICLE_MOTOR_PS_P4)))
            {
                if(FALSE != vehRunningSts)
                {
                    result = TRUE;
                }
                else
                {
                    result = FALSE;
                }
            }
            // 0100 PHEV+=PS/PS+P4HCU_CDCSFlag =0x0  VehRunningSts=1
            else if ((TC_VEHICLE_PHEV == TC_Module_Vehicle_Type_Data) && (0u == hcu_cdcsflag)&&\
            ((TC_Module_Motor_Type_Data == TC_VEHICLE_MOTOR_PS)||(TC_Module_Motor_Type_Data == TC_VEHICLE_MOTOR_PS_P4)))
            {
                if(FALSE != vehRunningSts)
                {
                    result = TRUE;
                }
                else
                {
                    result = FALSE;
                }
            }
            else
            {
                result = FALSE;
            }
        }
        else
        {
            result = FALSE;
        }
    }
    else
    {
        result = FALSE;
    }
    return result;
}
/**********************************************************************************************************
*Function   : TC_Api_DTE_cal_Enable                                                                  	  *
*                                                                                                         *
*Description: DTE  Range calculation conditions                                                           *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Shujunhua                                                                                   *
*                                                                                                         *
*Date		: 2020-04-24  adapt to HEV Vehicle                                                            *
**********************************************************************************************************/
static boolean TC_Api_DTE_cal_Enable(void)
{
    boolean result = FALSE;
    boolean vehStartingSts = FALSE;
    uint8 hcu_cdcsflag = TC_Rte_Get_HCU_CDCSFlag();
    vehStartingSts = TC_Hev_Phev_VehStartingSts;
    
    if((TC_VEHICLE_FUEL == TC_Module_Vehicle_Type_Data)||(TC_VEHICLE_FUEL_DIESEL == TC_Module_Vehicle_Type_Data))
    {
        if(FALSE != TC_API_Get_EngSpd_State())
        {
            result = TRUE;
        }
        else
        {
            result = FALSE;
        }
    }
    else if (TC_VEHICLE_HEV == TC_Module_Vehicle_Type_Data) 
    {
        if(FALSE != TC_API_Get_EngSpd_State())
        {
            result = TRUE;
        }
        else
        {
            if(((TC_Module_Motor_Type_Data==TC_VEHICLE_MOTOR_P2) || (TC_Module_Motor_Type_Data==TC_VEHICLE_MOTOR_PS) || (TC_Module_Motor_Type_Data==TC_VEHICLE_MOTOR_PS_P4)\
            || (TC_Module_Motor_Type_Data==TC_VEHICLE_MOTOR_PARA_P2)) && (FALSE != vehStartingSts))
            {
                result = TRUE;
            }
            else
            {
                result = FALSE;
            }
        }
    }
    else if (TC_VEHICLE_PHEV == TC_Module_Vehicle_Type_Data)
    {
        if(FALSE != TC_API_Get_EngSpd_State())
        {
            result = TRUE;
        }
        else
        {
            if(((TC_Module_Motor_Type_Data == TC_VEHICLE_MOTOR_PS) || (TC_Module_Motor_Type_Data==TC_VEHICLE_MOTOR_PS_P4))\
            && (0u == hcu_cdcsflag) && (FALSE != vehStartingSts))
            {
                result = TRUE;
            }
            else
            {
                result = FALSE;
            }
        }
    }
    else
    {
        result = FALSE;
    }  
    return result;
}

/**********************************************************************************************************
*Function   : TC_Api_AVS_Accum_Enable                                                                 	  *
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
static boolean TC_Api_AVS_Display_Condition(void)
{
    boolean result = FALSE;
    
	if(FALSE != TC_RTE_API_Get_ODO_Condition())
	{
		result = TRUE;
	}
	else
	{
		result = FALSE;
	}

    return result;
}
/**********************************************************************************************************
*Function   : TC_Api_AFE_Accum_Enable                                                                 	  *
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
static boolean TC_Api_AFE_Display_Condition(void)
{
    boolean result = FALSE;
    boolean ecmErr = FALSE;
    ecmErr = TC_RTE_API_Get_ECM2_err();
	if((FALSE != TC_RTE_API_Get_ODO_Condition() ) &&(FALSE == ecmErr))
	{
		result = TRUE;
	}
	else
	{
		result = FALSE;
	}

    return result;
}
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
void TC_Api_Process_fuel_update_Task(void)
{   
	uint8 i;
	if(FALSE == TC_RTE_API_Get_Power_Mode_State_Is_Sleep())
	{
		if(FALSE != TC_API_Get_Power_Mode_State())
		{	
			if(FALSE != TC_API_Get_Fuel_Finished_Init_State()) 
			{		
			    /*Two tanks represent both ways of failure*/
				if(FALSE != TC_API_Get_Fuel_Error_State())
				{
					TC_SETBIT(TC_Trip_Singal_Status, TC_FUEL_INIT_OPENSHT);
					TC_Pkg_Out_Set_Fuel_Level(0);
					TC_Pkg_Out_Set_Dte_Calc_Enable(0);
				}
                #if 0
                else if (FALSE != TC_API_Get_Fuel_ONE_Error_State())
                {
                  TC_Pkg_Out_Set_Dte_Calc_Enable(0);
                  TC_API_Get_Fuel_ONE_Error_State_Clear();
                }
                #endif 
				else
				{
					TC_CLEARBIT(TC_Trip_Singal_Status,TC_FUEL_INIT_OPENSHT);
					TC_Pkg_Out_Set_Fuel_Level((uint32)TC_FUEL_LEVEL_IN_LITERS);
				}

				if(FALSE == TC_TESTBIT(TC_Trip_Singal_Status,TC_ODO_SIG_INVLD_MIS_NVR_RCVD))
			  	{
			    	TC_Odo_Fuel_MIssing_Status = FALSE;
			  	}
			  	else
			  	{		    	
			    	TC_Odo_Fuel_MIssing_Status = TRUE;
					
					for(i=0;i<TC_MAX_NUM_OF_AFE;i++)
					{
					    TC_Ftrip_T.tAFE.u32CurrentAFE[i] = TC_AFE_AFTER_RESET_DASHES;
					}

			    	//TC_Api_Computer_Uint_IFE();			
			  	}
			}
			else
			{
				//TC_Odo_Fuel_MIssing_Status = TRUE;
			}

		}
		else 
			{
			    TC_Odo_Fuel_MIssing_Status = TRUE;
		//	TC_Api_Computer_Uint_IFE();
			}

		/*20201102 ADD FUEL FASTFILL STATUS */	
        	if(FALSE != TC_API_Get_Power_Mode_State())
            {   
        		if(FALSE != TC_API_Get_Fuel_Finished_Init_State())
        		{
        			TC_Api_Computer_DTE();
        		}
            }
	}
}

void TC_Api_Process_Task(void)
{	
	//uint8 fl_save_interrupt_status_U8;
	//uint16 i;
	if(FALSE == TC_RTE_API_Get_Power_Mode_State_Is_Sleep())
	{
		#ifdef TC_TIME_CAL	
		tc_RteAdaptRunableOstmStart(TC_task_cal);
		#endif
        #if 1
		TC_App_Emergy_cal_task();
		#endif 
		#if 0
		if((FALSE != TC_API_Get_Power_Mode_State()) && (FALSE != TC_API_Get_Voltage_Mode_State()))
		{	
			if(FALSE != TC_API_Get_Fuel_Finished_Init_State()) 
			{		
				if(FALSE != TC_API_Get_Fuel_Error_State())
				{
					TC_SETBIT(TC_Trip_Singal_Status, TC_FUEL_INIT_OPENSHT);
					TC_Pkg_Out_Set_Fuel_Level(0);
					TC_Pkg_Out_Set_Dte_Calc_Enable(0);
				}
				else
				{
					TC_CLEARBIT(TC_Trip_Singal_Status,TC_FUEL_INIT_OPENSHT);
					TC_Pkg_Out_Set_Fuel_Level(TC_FUEL_LEVEL_IN_LITERS);
				}

				if(FALSE == TC_TESTBIT(TC_Trip_Singal_Status,TC_ODO_SIG_INVLD_MIS_NVR_RCVD))
			  	{
			    	TC_Odo_Fuel_MIssing_Status = FALSE;
			  	}
			  	else
			  	{		    	
			    	TC_Odo_Fuel_MIssing_Status = TRUE;
					
					for(i=0;i<TC_MAX_NUM_OF_AFE;i++)
					{
					    TC_Ftrip_T.tAFE.u32CurrentAFE[i] = TC_AFE_AFTER_RESET_DASHES;
					}

			    	TC_Api_Computer_Uint_IFE();			
			  	}
			}
			else
			{
				TC_Odo_Fuel_MIssing_Status = TRUE;
			}

		}
		else
		{
			TC_Odo_Fuel_MIssing_Status = TRUE;
			TC_Api_Computer_Uint_IFE();
		}
		#endif 
		if(FALSE != TC_API_Get_Power_Mode_State())

		{
			TC_Pkg_Input_Collect_Task(&TC_Ftrip_T);
			
			if(FALSE != TC_Api_AFE_Accum_Enable())
			{
				TC_Api_Computer_AFE();
			}
			
			if(FALSE != TC_Api_AVS_Accum_Enable())
			{
				TC_Api_Computer_AVS();
			}

			if(FALSE != TC_Api_IFE_Accum_Enable())
			{
				TC_Api_Computer_IFE();
			}
			
			/*********** for debug ************/
			TC_Api_Eol_Get_Fuel_State();
			/*********** for debug ************/

		}
        else
        {

        }
        #ifdef TC_VEHICLE_LOG_OUTPUT
        TC_log_Task();
        #endif
		#ifdef TC_TIME_CAL	
		//TC_TASK_END_CALCULATE(TC_task_cal);
		tc_RteAdaptRunableOstmCheck(TC_task_cal);
		#endif
	}
}
/**********************************************************************************************************
*Function   :GDC V3.5 The TC log print                                                                    *
*                                                                                                         *
*Description: v0.1 	                                                                                      *
*                                                                                                         *
*Parameter  : NONE                                                                                        *
*                                                                                                         *
*Return     : NONE                                                                                        *
*                                                                                                         *
*Author     : renfnegpo                                                                                   *
*                                                                                                         *
*Date       : 2021-11-11                                                                                  *
**********************************************************************************************************/
#ifdef TC_VEHICLE_LOG_OUTPUT

typedef uint8* (*TClogcheck)(void);

/******************************************Init_Check******************************************/
static uint8* TC_Log_Init_Check(void)
{
    uint8 TC_Byte0_Memory = 0;
    uint8 TC_Byte1_Memory = 0;
    //EVENT0----------------------BYTE0本地配置/BYTE1下线配置出错恢复打印---------------------//
    TC_Byte0_Memory = TC_LOG_CFG_INFORMATION_ENABLE;
    TC_Byte1_Memory = TC_LOG_CFG_INFORMATION_LIMIT_VALUE;
    (void)TC_LOG_RECORD(TC_EVENT_INIT);
    if((TC_Byte0_Memory != TC_LOG_CFG_INFORMATION_ENABLE) || (TC_Byte1_Memory != TC_LOG_CFG_INFORMATION_LIMIT_VALUE))
    {
        TC_SETBIT(TC_log_message_type,TC_LOG_INIT_BIT);
    }
    return &TC_log_message_type;
}
/******************************************Event_Check*****************************************/
static uint8* TC_Log_Event_Check(void)
{
    uint8 TC_Byte2_Memory = 0;
    //EVENT1----------------------BYTE2计算/显示条件出错恢复打印------------------------------//
    TC_Byte2_Memory = TC_LOG_CAL_INFORMATION;
    (void)TC_LOG_RECORD(TC_EVENT_FIXATION);
    if((TC_Byte2_Memory != TC_LOG_CAL_INFORMATION))
    {
        TC_SETBIT(TC_log_message_type,TC_LOG_EVENT_BIT);
    }
    return &TC_log_message_type;
}
/******************************************VENT_DTE_CHECK**************************************/
static uint8* TC_LOG_TASK_EVENT_DTE_CHECK(void)
{
    uint32 tc_odo_current_0 = 0;
    uint16 tc_odo_current_1 = 0;
    uint8  TC_EVENT3_Memory = 0;
    uint8  TC_log_flag = 0;
    uint16 TC_DTE_SFC_PLog_Memory = 0;          //阶段油耗
    uint32 TC_DTE_Calculation_PLog_Memory = 0;  //计算值
    uint32 TC_DTE_Current_PLog_Memory = 0;      //当前值
    uint32 TC_DTE_Display_PLog_Memory = 0;      //显示值
    uint8  TC_DTE_Refresh_Mode_plog_Memory = 0; //续航里程更新模式
    uint8 vehStartingSts_out = 0;
    uint8 hcu_cdcsflag = TC_Rte_Get_HCU_CDCSFlag();
    vehStartingSts_out = TC_RTE_API_Get_Hev_Phev_VehStartingSts_Out();/*0 TIMEOUT*/

    //EVENT2----------------------每2KM打印一次续航信息----------------------------//
    tc_odo_current_0 = TC_Api_Rte_Get_Odo_value();
    if((RFP_TC_2.TC_Pkg_Odo_value_PLog == 0XFFFFFF01)||(tc_odo_current_0 == 0XFFFFFF01))
    {
        if(tc_odo_current_0 != RFP_TC_2.TC_Pkg_Odo_value_PLog)
        {
            TC_log_flag = 1u;
            RFP_TC_2.TC_Pkg_Odo_value_PLog = TC_Api_Rte_Get_Odo_value();
        }
    }
    else
    {
        if(tc_odo_current_0 >= RFP_TC_2.TC_Pkg_Odo_value_PLog)
        {
            tc_odo_current_1 = (uint16)(tc_odo_current_0 - RFP_TC_2.TC_Pkg_Odo_value_PLog);
        }
        else
        {
            tc_odo_current_1 = 0;
            RFP_TC_2.TC_Pkg_Odo_value_PLog=tc_odo_current_0;
        }
        if(tc_odo_current_1 >= (2*TC_EMERGY_DATA_UPADTE_KM))
        {
            TC_log_flag = 1u;
            RFP_TC_2.TC_Pkg_Odo_value_PLog = tc_odo_current_0;
        }
        else
        {
        }
    }
    TC_EVENT3_Memory = TC_EVENT3_Flag;
    (void)TC_LOG_RECORD(TC_EVENT_DTE_CAL);
    (void)TC_LOG_BIT_MANAGE(&TC_EVENT3_Flag, RFP_TC_3.RFP_TC_1.TC_Motor_out,0);
    if((TC_VEHICLE_FUEL == TC_Module_Vehicle_Type_Data) || (TC_VEHICLE_FUEL_DIESEL == TC_Module_Vehicle_Type_Data))
    {
        (void)TC_LOG_BIT_MANAGE(&TC_EVENT3_Flag, 0,1u);
    }
    else if(TC_VEHICLE_HEV == TC_Module_Vehicle_Type_Data)
    {
       if(((TC_Module_Motor_Type_Data==TC_VEHICLE_MOTOR_P2) || (TC_Module_Motor_Type_Data==TC_VEHICLE_MOTOR_PS) || (TC_Module_Motor_Type_Data==TC_VEHICLE_MOTOR_PS_P4)\
        || (TC_Module_Motor_Type_Data==TC_VEHICLE_MOTOR_PARA_P2)) && (1u == vehStartingSts_out))
        {
           (void)TC_LOG_BIT_MANAGE(&TC_EVENT3_Flag, 0,1u);
        }
        else
        {
           (void)TC_LOG_BIT_MANAGE(&TC_EVENT3_Flag, 1u,1u);
        }
    }
    else if(TC_VEHICLE_PHEV == TC_Module_Vehicle_Type_Data)
    {
        if(((TC_Module_Motor_Type_Data == TC_VEHICLE_MOTOR_PS) || (TC_Module_Motor_Type_Data==TC_VEHICLE_MOTOR_PS_P4))\
        && (0u == hcu_cdcsflag) && (1u == vehStartingSts_out))
        {
           (void)TC_LOG_BIT_MANAGE(&TC_EVENT3_Flag, 0,1u);
        }
        else
        {
           (void)TC_LOG_BIT_MANAGE(&TC_EVENT3_Flag, 1u,1u);
        }
    }
    else
    {
       (void)TC_LOG_BIT_MANAGE(&TC_EVENT3_Flag, 0,0u);
       (void)TC_LOG_BIT_MANAGE(&TC_EVENT3_Flag, 0,1u);
       (void)TC_LOG_BIT_MANAGE(&TC_EVENT3_Flag, 1u,2u);
    }
  
    if(TC_EVENT3_Memory != TC_EVENT3_Flag)
    {
        TC_log_flag = 2u;
    }
    //----------------------------------------------------------------------------//
    if((TC_log_flag == 1u) || (TC_log_flag == 2u))
    {
        TC_DTE_SFC_PLog_Memory = RFP_TC_2.TC_DTE_SFC_PLog;//阶段油耗
        TC_DTE_Calculation_PLog_Memory = RFP_TC_2.TC_DTE_Calculation_PLog;//计算值
        TC_DTE_Current_PLog_Memory = RFP_TC_2.TC_DTE_Current_PLog;//当前值
        TC_DTE_Display_PLog_Memory =  RFP_TC_2.TC_DTE_Display_PLog;//显示值
        TC_DTE_Refresh_Mode_plog_Memory = RFP_TC_2.TC_DTE_Refresh_Mode_plog;//续航里程更新模式
        (void)TC_LOG_RECORD(TC_EVENT_DTE);

        if((TC_log_flag == 2u) || (TC_DTE_Refresh_Mode_plog_Memory != RFP_TC_2.TC_DTE_Refresh_Mode_plog) ||\
        (TC_DTE_SFC_PLog_Memory != RFP_TC_2.TC_DTE_SFC_PLog) || (TC_DTE_Calculation_PLog_Memory != RFP_TC_2.TC_DTE_Calculation_PLog) || \
        (TC_DTE_Current_PLog_Memory != RFP_TC_2.TC_DTE_Current_PLog) || (TC_DTE_Display_PLog_Memory != RFP_TC_2.TC_DTE_Display_PLog) )
        {
            TC_SETBIT(TC_log_message_type,TC_LOG_EVENT_DTE_BIT);
        }
    }
    return &TC_log_message_type;
}

/******************************************PERIOD CHECK******************************************/
static uint8* TC_Log_Period_Check(void)
{
    uint8  powermode_flag = 0;
    powermode_flag = TC_API_Get_Power_Mode_State();
    //PERIOD----------------------电源翻转5秒打印两帧----------------------------//
    if(TC_LOG_POWER_MODE_FLAG != powermode_flag)
    {
        TC_period_counter = 0;
        TC_counter = FALSE;
        TC_LOG_POWER_MODE_FLAG = powermode_flag;
    }
    if(TC_counter == FALSE)
    {
        if(TC_period_counter < 251u) 
        {
            TC_period_counter++;
            if((150u == TC_period_counter) || (250u == TC_period_counter))
            {
                //add logic 
                TC_SETBIT(TC_log_message_type,TC_LOG_PERIOD_BIT);
            }
        }
        else 
        {
            TC_counter = TRUE;
        }
    }
    return &TC_log_message_type;
 }
 
 /**************************************************************************
  * [TCLogcheklist : log task check list]                                  *
  * @Author   shujunhua                                                    *
  * @DateTime 2021/11/20-13:03:18                                          *
  **************************************************************************/
static const TClogcheck TCLogcheklist[TC_LOG_TASK_MAX] =
{
    TC_Log_Init_Check,
    TC_Log_Event_Check,
    TC_Log_Period_Check,
    TC_LOG_TASK_EVENT_DTE_CHECK,
};

static void TC_log_trace_snapshot(uint8 *type)
{
    uint8 power_mode = TC_API_Get_Power_Mode_State();
    if(FALSE != power_mode)
    {
        if(TC_Dte_Delay_Log_Count_ON >= TC_DTE_KEYON_LOG_DELAY)
        {
            TC_Dte_Delay_Log_Count_ON = TC_DTE_KEYON_LOG_DELAY;
        }
        else
        {
            TC_Dte_Delay_Log_Count_ON++;
        }
    }
    else
    {
         if(TC_Dte_Delay_Log_Count_OFF >= TC_DTE_KEYON_LOG_DELAY)
        {
            TC_Dte_Delay_Log_Count_OFF = TC_DTE_KEYON_LOG_DELAY;
        }
        else
        {
            TC_Dte_Delay_Log_Count_OFF++;
        }
    }
    if((TC_DTE_KEYON_LOG_DELAY == TC_Dte_Delay_Log_Count_ON) || (TC_DTE_KEYON_LOG_DELAY == TC_Dte_Delay_Log_Count_OFF))
    {
        //-------------------------------------------------------LOG_INIT-----------------------------------------------------//
        if(TC_TESTBIT(*type,TC_LOG_INIT_BIT))
        {
            TC_CLEARBIT(*type,TC_LOG_INIT_BIT);
            (void)TC_MODULE_DEBUG_INFO_warn("EVENTINIT=%d,%d,%d",TC_LOG_CFG_INFORMATION_ENABLE,TC_LOG_CFG_INFORMATION_LIMIT_VALUE,RFP_TC_3.RFP_TC_1.TC_power_state);
        }
        //-------------------------------------------------------LOG_EVENT_ONCE-----------------------------------------------//
        if(TC_TESTBIT(*type,TC_LOG_EVENT_BIT))
        {
            TC_CLEARBIT(*type,TC_LOG_EVENT_BIT);
            (void)TC_MODULE_DEBUG_INFO_warn("EVENTONCE=%d,%d",TC_LOG_CAL_INFORMATION,RFP_TC_3.RFP_TC_1.TC_power_state);
        }
        //-------------------------------------------------------LOG_EVENT_DTE------------------------------------------------//
        if(TC_TESTBIT(*type,TC_LOG_EVENT_DTE_BIT))
        {
            (void)TC_LOG_RECORD(TC_EVENT_DTE);
            // print event DTE log
            (void)TC_MODULE_DEBUG_INFO_warn("DTE2E1=%d,%d,%d,%d",TC_LOG_DTE_EVENT1);
            (void)TC_MODULE_DEBUG_INFO_warn("DTE2E2=%d,%d,%d,%d",TC_LOG_DTE_EVENT2);
          
            if(TC_TESTBIT(TC_EVENT3_Flag,TC_LOG_PERIOD_BIT))
            {
                (void)TC_MODULE_DEBUG_INFO_err("DTE_ERR3=%d",RFP_TC_3.RFP_TC_1.TC_Vehicle_Type);
            }
            else if(TC_TESTBIT(TC_EVENT3_Flag,TC_LOG_EVENT_BIT))
            {
                (void)TC_MODULE_DEBUG_INFO_err("DTE_ERR2=%d,%d,%d,%d",TC_LOG_DTE_EVENT4);
                DTE_ERROR_EVENT_FLAG = 1;
            }
            else if(TC_TESTBIT(TC_EVENT3_Flag,TC_LOG_INIT_BIT))
            {
                (void)TC_MODULE_DEBUG_INFO_err("DTE_ERR1=%d,%d",TC_LOG_DTE_EVENT3);
                DTE_ERROR_EVENT_FLAG = 1;
            }
            else
            {
                if(1 == DTE_ERROR_EVENT_FLAG)
                {
                    (void)TC_MODULE_DEBUG_INFO_err("DTE_ERR123=%d,%d,%d,%d",TC_LOG_DTE_EVENT4);
                    DTE_ERROR_EVENT_FLAG = 0;
                }
            }
            TC_CLEARBIT(*type,TC_LOG_EVENT_DTE_BIT);
        }
        //-------------------------------------------------------LOG_PERIOD--------------------------------------------------//
        if(TC_TESTBIT(*type,TC_LOG_PERIOD_BIT))
        {
            (void)TC_LOG_RECORD(TC_EVENT_DTE);
            // print period log 
            (void)TC_MODULE_DEBUG_INFO_warn("DTEP1=%d,%d,%d,%d",TC_LOG_DTE_EVENT1);
            (void)TC_MODULE_DEBUG_INFO_warn("DTEP2=%d,%d,%d,%d",TC_LOG_DTE_EVENT2);
            TC_CLEARBIT(*type,TC_LOG_PERIOD_BIT);
        }
    }
} 

static void TC_log_Task(void)
{
    uint16 i = (uint16)TC_LOG_TASK_INIT;
    uint16 tc_log_task_max = sizeof(TCLogcheklist)/sizeof(TClogcheck); 
    for(i = (uint16)TC_LOG_TASK_INIT;i < tc_log_task_max;i++)
    {
        (void)TC_log_trace_snapshot(TCLogcheklist[i]());
    }
}

static void TC_LOG_RECORD(uint8 number)
{
    uint8 i = 0;
    uint8 j = 0;
    //EVENT
    switch(number)
    {
        case TC_EVENT_INIT:
        {
            //BYTE0 配置信息使能
            RFP_TC_3.RFP_TC_1.TC_AVSADisplayEnable_Elog = (uint8)((TC_Ftrip_T.tTC_Config_NVM.AVSADisplayEnable_NvmInit == 0)?1u:0u);
            RFP_TC_3.RFP_TC_1.TC_AVSBDisplayEnable_Elog = (uint8)((TC_Ftrip_T.tTC_Config_NVM.AVSBDisplayEnable_NvmInit == 0)?1u:0u);
            RFP_TC_3.RFP_TC_1.TC_TravelTimeADisplayEnable_Elog = (uint8)((TC_Ftrip_T.tTC_Config_NVM.TravelTimeADisplayEnable_NvmInit == 0)?1u:0u);
            RFP_TC_3.RFP_TC_1.TC_TravelTimeBDisplayEnable_Elog = (uint8)((TC_Ftrip_T.tTC_Config_NVM.TravelTimeBDisplayEnable_NvmInit == 0)?1u:0u);
            RFP_TC_3.RFP_TC_1.TC_AFCADisplayEnable_Elog = (uint8)((TC_Ftrip_T.tTC_Config_NVM.AFCADisplayEnable_NvmInit == 0)?1u:0u);
            RFP_TC_3.RFP_TC_1.TC_AFCBDisplayEnable_Elog = (uint8)((TC_Ftrip_T.tTC_Config_NVM.AFCBDisplayEnable_NvmInit == 0)?1u:0u);
            RFP_TC_3.RFP_TC_1.TC_IFCDisplayEnable_Elog = (uint8)((TC_Ftrip_T.tTC_Config_NVM.IFCDisplayEnable_NvmInit == 0)?1u:0u);
            RFP_TC_3.RFP_TC_1.TC_DisplayEnable_Elog = (uint8)((TC_PHEVRange_DISP_ENABLE_INTERNAL == 0)?1u:0u);

            //BYTE1 本地配置使能
            RFP_TC_3.RFP_TC_1.TC_RefreshRateAVS_Elog = (uint8)((TC_Ftrip_T.tTC_Config_NVM.RefreshRateAVS_NvmInit == 0)?1u:0u);
            RFP_TC_3.RFP_TC_1.TC_AVSMinDistanceThresh_Elog = (uint8)((TC_Ftrip_T.tTC_Config_NVM.AVSMinDistanceThresh_NvmInit == 0)?1u:0u);
            RFP_TC_3.RFP_TC_1.TC_RefreshRateAFC_Elog = (uint8)((TC_Ftrip_T.tTC_Config_NVM.RefreshRateAFC_NvmInit == 0)?1u:0u);
            RFP_TC_3.RFP_TC_1.TC_AFCMinDistanceThresh_Elog = (uint8)((TC_Ftrip_T.tTC_Config_NVM.AFCMinDistanceThresh_NvmInit == 0)?1u:0u);
            RFP_TC_3.RFP_TC_1.TC_Max_fuelConPerCycle_Elog = (uint8)((TC_Ftrip_T.tTC_Config_NVM.Max_fuelConPerCycle_NvmInit == 0)?1u:0u);
            RFP_TC_3.RFP_TC_1.TC_RefreshRateIFC_Elog = (uint8)((TC_Ftrip_T.tTC_Config_NVM.RefreshRateIFC_NvmInit == 0)?1u:0u);
            RFP_TC_3.RFP_TC_1.TC_sMaxDisplayPHEVRange_Elog = (uint8)((TC_Ftrip_T.tTC_Config_NVM.Phev_sMaxDisplayPHEVRange == 0)?1u:0u);
            RFP_TC_3.RFP_TC_1.TC_TravelTimeDisplayLimited_Elog = (uint8)(((TC_Ftrip_T.tTC_Config_NVM.TravelTimeDisplayLimited_Minute_NvmInit != 0) && (TC_Ftrip_T.tTC_Config_NVM.TravelTimeDisplayLimited_Hour_NvmInit != 0))?0:1);

            RFP_TC_3.RFP_TC_1.TC_power_state = TC_API_Get_Power_Mode_State();
            for(i=0;i<8u;i++)
            {
                if(i<TC_EVENT_INIT_LENGTH)
                {
                    (void)TC_LOG_BIT_MANAGE(&TC_LOG_BYTE0, RFP_TC_3.TC_RFP_STORAGE_1[i], i);
                }
                j=(uint8)(i+8u);
                if(j<TC_EVENT_INIT_LENGTH)
                {
                    (void)TC_LOG_BIT_MANAGE(&TC_LOG_BYTE1, RFP_TC_3.TC_RFP_STORAGE_1[j], i);
                }
            }
            break;
        }
        case TC_EVENT_DTE_CAL:
        {
            RFP_TC_3.RFP_TC_1.TC_Motor_out = (uint8)((TC_API_Get_EngSpd_OUT_State()==1u)?0u:1u);
            RFP_TC_3.RFP_TC_1.TC_phev_out = (uint8)((TC_RTE_API_Get_Hev_Phev_VehStartingSts_Out()==1u)?0u:1u);
            break;
        }
        case TC_EVENT_FIXATION:
        {
            TC_Log_Conditional_Judgment();

            RFP_TC_3.RFP_TC_1.TC_Vehicle_Type = (uint8)TC_Module_Vehicle_Type_Data;
            RFP_TC_3.RFP_TC_1.TC_Motor_Type = (uint8)TC_Module_Motor_Type_Data;
            RFP_TC_3.RFP_TC_1.TC_power_state = TC_API_Get_Power_Mode_State();
            RFP_TC_3.RFP_TC_1.TC_Motor_out = (uint8)((TC_API_Get_EngSpd_OUT_State()==1u)?0u:1u);
            RFP_TC_3.RFP_TC_1.TC_phev_out = (uint8)((TC_RTE_API_Get_Hev_Phev_VehStartingSts_Out()==1u)?0u:1u);

            //BYTE2 计算条件使能
            RFP_TC_2.TC_Calculate_Enable_Elog = (uint8)((TC_Travel_Time_Calculate_Flag_Enable==1)?0u:1u);
            RFP_TC_2.TC_DTE_Enable_Elog = (uint8)((TC_RTE_API_Get_Fuel_Error_State()==0u)?0u:1u);
            RFP_TC_2.TC_ODO_Err_PLog = (uint8)TC_RTE_API_Get_ODO_err();
            RFP_TC_2.TC_ECM2_Err_PLog = (uint8)TC_RTE_API_Get_ECM2_err();
            RFP_TC_2.TC_Pkg_Odo_value = (uint32)TC_Api_Rte_Get_Odo_value();

            (void)TC_LOG_BIT_MANAGE(&TC_LOG_BYTE2, RFP_TC_2.TC_Calculate_Enable_Elog,0u);
            (void)TC_LOG_BIT_MANAGE(&TC_LOG_BYTE2, RFP_TC_2.TC_DTE_Enable_Elog,1u);
            (void)TC_LOG_BIT_MANAGE(&TC_LOG_BYTE2, RFP_TC_2.TC_AVS300_A_Elog,2u);
            (void)TC_LOG_BIT_MANAGE(&TC_LOG_BYTE2, RFP_TC_2.TC_AVS300_B_Elog,3u);
            (void)TC_LOG_BIT_MANAGE(&TC_LOG_BYTE2, RFP_TC_2.TC_AFC300_A_Elog,4u);
            (void)TC_LOG_BIT_MANAGE(&TC_LOG_BYTE2, RFP_TC_2.TC_AFC300_B_Elog,5u);
            (void)TC_LOG_BIT_MANAGE(&TC_LOG_BYTE2, RFP_TC_2.TC_ODO_Err_PLog,6u);
            (void)TC_LOG_BIT_MANAGE(&TC_LOG_BYTE2, RFP_TC_2.TC_ECM2_Err_PLog,7u);
            break;
        }
        case TC_EVENT_DTE:
        {
            RFP_TC_2.TC_DTE_Refresh_Mode_plog = (uint8)(TC_Ftrip_T.tDTE.u8Refresh_Mode);
            RFP_TC_2.TC_DTE_SFC_PLog = (uint16)(TC_Pkg_Get_DTE_Fuel_Stage_Consumption_Value(0)/100u);
            RFP_TC_2.TC_DTE_Calculation_PLog = (uint32)TC_Ftrip_T.tDTE.u32CalculationDTE;
            RFP_TC_2.TC_DTE_Current_PLog = (uint32)TC_Ftrip_T.tDTE.u32CurrentDTE;
            RFP_TC_2.TC_DTE_Display_PLog = (uint32)TC_Ftrip_T.tDTE.u32DisplayDTE;
            RFP_TC_2.TC_FUEL_Display_PLog = (uint32)TC_API_Get_Fuel_volume();
            RFP_TC_2.TC_Pkg_Odo_value = (uint32)TC_Api_Rte_Get_Odo_value();
            RFP_TC_3.RFP_TC_1.TC_power_state = TC_API_Get_Power_Mode_State();
            break;
        }
        default:
        {
            RFP_TC_3.RFP_TC_1.TC_power_state = TC_API_Get_Power_Mode_State();
            break;
        }
    }
}
static void TC_Log_Conditional_Judgment(void)
{
    uint8 i=0u;
    if(FALSE != TC_API_Get_Power_Mode_State())
    {
        if(FALSE != TC_Api_AVS_Display_Condition())
        {
            for(i = 0u;i<TC_MAX_NUM_OF_AVS;i++)
            {
                /* distance >300m display after reset*/
                if(TC_Pkg_Get_Distance_AVS(i) >= TC_Ftrip_T.tTC_Config_NVM.AVSMinDistanceThresh_NvmInit)
                {
                    if(0u == i)
                    {
                        RFP_TC_2.TC_AVS300_A_Elog = 0u;
                    }
                    else if(1u == i)
                    {
                        RFP_TC_2.TC_AVS300_B_Elog = 0u;
                    }
                    else
                    {}
                }
                else
                {
                    if(0 == i)
                    {
                        RFP_TC_2.TC_AVS300_A_Elog = 1u;
                    }
                    else if(1 == i)
                    {
                        RFP_TC_2.TC_AVS300_B_Elog = 1u;
                    }
                    else
                    {
                    }
                }
            }
        }	
        else
        {
            RFP_TC_2.TC_AVS300_A_Elog = 1u;
            RFP_TC_2.TC_AVS300_B_Elog = 1u;
        }
        if(FALSE != TC_Api_AFE_Display_Condition())
        {
            for(i = 0u;i<TC_MAX_NUM_OF_AFE;i++)
            {
                /* distance >300m display after reset*/
                if(TC_Pkg_Up_Min_Distance_AFE(i) >= TC_Ftrip_T.tTC_Config_NVM.AFCMinDistanceThresh_NvmInit)
                {
                    if(0u == i) 
                    {
                        RFP_TC_2.TC_AFC300_A_Elog = 0u;
                    }
                    else if(1u == i)
                    {
                        RFP_TC_2.TC_AFC300_B_Elog = 0u;
                    }
                    else
                    {
                    }
                }
                else
                {
                    if(0u == i) 
                    {
                        RFP_TC_2.TC_AFC300_A_Elog = 1u;
                    }
                    else if(1u == i)
                    {
                        RFP_TC_2.TC_AFC300_B_Elog = 1u;
                    }
                    else
                    {
                    }
                }
            }
        }
        else
        {
            RFP_TC_2.TC_AFC300_A_Elog = 1u;
            RFP_TC_2.TC_AFC300_B_Elog = 1u;
        }
    }	
}
static void TC_LOG_BIT_MANAGE(uint8 *sum_value,uint8 one_value,uint8 constant0)
{
    uint8 n = 0u;
    uint8 m = 0u;
    uint8 *k;
    m = one_value;
    k = sum_value;
    switch(constant0)
    {
        case 0:{n = 1u;   break;}
        case 1:{n = 2u;   break;}
        case 2:{n = 4u;   break;}
        case 3:{n = 8u;   break;}
        case 4:{n = 16u;  break;}
        case 5:{n = 32u;  break;}
        case 6:{n = 64u;  break;}
        case 7:{n = 128u; break;}
        default:{n = 0u;  break;}
    }
    if(m == 0u)
    {
        TC_CLEARBIT(*k,n);
    }
    else if(m == 1u)
    {
        TC_SETBIT(*k,n);
    } 
}

#endif

/**********************************************************************************************************
*Function   : TC_Api_Accum_Odo_Count                                                                   	  *
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
static void TC_Api_Accum_Odo_Count(void)
{
	uint8 fl_new_odo_count_U8 = 0;
	uint8 odo_pulse_count_num_u8 = 0;
	//uint32 fl_can_content_U32 = 0;
	//uint8  odo_message_received = 0;
	//uint32 outValue;
	//SG_ABS3 signal;

	fl_new_odo_count_U8 = TC_RTE_API_Get_ODO_Count(); /* uint 0.1m 0-254, 255 is error. hardware odo rolling count,*/
	
	if (TRUE ==TC_RTE_API_Get_ODO_err())
	{
		TC_SETBIT(TC_Trip_Singal_Status, TC_ODO_SIG_INVLD_MIS_NVR_RCVD);
		fl_new_odo_count_U8 = 0xFF;
	}
	else
	{
		TC_CLEARBIT(TC_Trip_Singal_Status,TC_ODO_SIG_INVLD_MIS_NVR_RCVD);			
		 
		if( fl_new_odo_count_U8 > TC_Prev_Odo_Count  )
	    {
			odo_pulse_count_num_u8 = ((fl_new_odo_count_U8 - TC_Prev_Odo_Count));
	    }
	    else if(fl_new_odo_count_U8 < TC_Prev_Odo_Count  )
	    {
	        odo_pulse_count_num_u8 = ((uint8)((uint16)fl_new_odo_count_U8 + ( (uint16)TC_MAX_ODO_COUNT - (uint16)TC_Prev_Odo_Count) + (uint16)1u ));
	    }
		else
		{
			odo_pulse_count_num_u8 = 0;
		}

		TC_Prev_Odo_Count = fl_new_odo_count_U8;
	}

	if(fl_new_odo_count_U8 == 0xFF)
	{
		TC_Ftrip_T.tIFE.tAccDat.u32AccumOdoPulse = TC_DATA_INPUT_ERROR;
		TC_Ftrip_T.tAFE.tAccDat.u32AccumOdoPulse = TC_DATA_INPUT_ERROR;
		TC_Ftrip_T.tAVS.tAccDat.u32AccumOdoPulse = TC_DATA_INPUT_ERROR;
		TC_Ftrip_T.tDTE.tAccDat.u32AccumOdoPulse = TC_DATA_INPUT_ERROR;		
	}
	else
	{			
		if(TC_Api_Accum_Enable()==TRUE)
		{   
			if(TC_Api_IFE_Accum_Enable()==TRUE)
			{				
				TC_Ftrip_T.tIFE.tAccDat.u32AccumOdoPulse += odo_pulse_count_num_u8;
			}
			else
			{
				TC_Ftrip_T.tIFE.tAccDat.u32AccumOdoPulse = 0;
			}
			
			if(TC_Api_AFE_Accum_Enable()==TRUE)
			{
				TC_Ftrip_T.tAFE.tAccDat.u32AccumOdoPulse += odo_pulse_count_num_u8;
			}
			else
			{
				TC_Ftrip_T.tAFE.tAccDat.u32AccumOdoPulse = 0;
			}
			
			if(TC_Api_AVS_Accum_Enable()==TRUE)
			{
				TC_Ftrip_T.tAVS.tAccDat.u32AccumOdoPulse += odo_pulse_count_num_u8;
			}
			else
			{
				TC_Ftrip_T.tAVS.tAccDat.u32AccumOdoPulse = 0;
			}
			
			if(TC_Api_DTE_Accum_Enable()==TRUE)
			{			
				TC_Ftrip_T.tDTE.tAccDat.u32AccumOdoPulse += odo_pulse_count_num_u8;	
			}
			else
			{
				TC_Ftrip_T.tDTE.tAccDat.u32AccumOdoPulse = 0;
			}
            
            TC_Ftrip_T.tPhev.tAccDat.u32AccumOdoPulse+= odo_pulse_count_num_u8; /*1KM for energy management and 1KM for energy consumption calculation*/
		}
		else
		{
			TC_Ftrip_T.tIFE.tAccDat.u32AccumOdoPulse = 0;
			TC_Ftrip_T.tAFE.tAccDat.u32AccumOdoPulse = 0;
			TC_Ftrip_T.tAVS.tAccDat.u32AccumOdoPulse = 0;
			TC_Ftrip_T.tDTE.tAccDat.u32AccumOdoPulse = 0;
		}
		
		TC_Prev_Odo_Count = fl_new_odo_count_U8;
	}
	
}
/**********************************************************************************************************
*Function   : TC_Api_Accum_Fuel_Count                                                                 	  *
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
static void TC_Api_Accum_Fuel_Count(void)
{
	//uint32 fuel_pulse_count_num_u16 = 0;
	//uint16 fl_new_fuel_pulse_count_U16 = 0;
	//uint8 fl_rcan_get_fuel_samples_times = 0;
	boolean fuel_consum_message_received = FALSE;
	uint32 fuel_consum_delta = 0;
	TC_FUEL_COMSUME_DATA_STRUCT  fuel_pulse_input;
	uint16 fuel_pulse_input_rc_sum = 0;
  	//fuel_pulse_count_num_u16 = TC_API_Get_FuelConsumption();
     fuel_pulse_input.u32_fuel_consume_value=	TC_RTE_Get_FuelConsMsgValue().u32_fuel_consume_value;
	 fuel_pulse_input.u16_fuel_consume_rc=      TC_RTE_Get_FuelConsMsgValue().u16_fuel_consume_rc; 
	if(0xFFFFFFFF == fuel_pulse_input.u32_fuel_consume_value)
	{
		fuel_consum_message_received = TRUE;
		
	}
	else
	{
		fuel_consum_message_received = FALSE;
	}

  	if(FALSE != fuel_consum_message_received)
  	{
		TC_SETBIT(TC_Trip_Singal_Status, TC_FUEL_SIG_INVLD_MIS_NVR_RCVD);
		TC_Api_Clear_Fuel_Samples_TimeTrigger();

		TC_Ftrip_T.tIFE.tAccDat.u32AccumFuelPulse = (uint32)TC_DATA_INPUT_ERROR;
		TC_Ftrip_T.tAFE.tAccDat.u32AccumFuelPulse = TC_DATA_INPUT_ERROR;
		TC_Ftrip_T.tAVS.tAccDat.u32AccumFuelPulse = TC_DATA_INPUT_ERROR;
		TC_Ftrip_T.tDTE.tAccDat.u32AccumFuelPulse = TC_DATA_INPUT_ERROR;
		TC_Ftrip_T.tFuel.u32FuelPulseAccum = 0;
        TC_Ftrip_T.tPhev.tAccDat.u32AccumFuelPulse= TC_DATA_INPUT_ERROR;
		
  	}
	else
	{	
		if(FALSE != TC_TESTBIT(TC_Trip_Singal_Status, TC_FUEL_SIG_INVLD_MIS_NVR_RCVD))
		{
			TC_RCan_Get_Fuel_Samples_Times_Old = fuel_pulse_input.u32_fuel_consume_value;
			TC_CLEARBIT(TC_Trip_Singal_Status,TC_FUEL_SIG_INVLD_MIS_NVR_RCVD);
			fuel_consum_delta = 0;
			TC_Prev_Fuel_Consume_Count=TC_RTE_Get_FuelConsMsgValue().u16_fuel_consume_rc;
		}
		else
		{   

           
			if( fuel_pulse_input.u16_fuel_consume_rc > TC_Prev_Fuel_Consume_Count  )
			{
				fuel_pulse_input_rc_sum = ( (uint16)(fuel_pulse_input.u16_fuel_consume_rc - TC_Prev_Fuel_Consume_Count) );
			}
			else if(fuel_pulse_input.u16_fuel_consume_rc < TC_Prev_Fuel_Consume_Count  )
			{
				fuel_pulse_input_rc_sum = ((uint16)((uint16)fuel_pulse_input.u16_fuel_consume_rc + ( (uint16)TC_MAX_FUEL_COSUME_COUNT - (uint16)TC_Prev_Fuel_Consume_Count) + (uint16)1u ));
			}
			else
			{
				fuel_pulse_input_rc_sum = 0;
			}
			
			TC_Prev_Fuel_Consume_Count = fuel_pulse_input.u16_fuel_consume_rc;
			
		
			if(TC_RCan_Get_Fuel_Samples_Times_Old != fuel_pulse_input.u32_fuel_consume_value)
			{
				if(TC_RCan_Get_Fuel_Samples_Times_Old < fuel_pulse_input.u32_fuel_consume_value) 
				{
					fuel_consum_delta = fuel_pulse_input.u32_fuel_consume_value - TC_RCan_Get_Fuel_Samples_Times_Old ;
				}
				else
				{
					fuel_consum_delta = fuel_pulse_input.u32_fuel_consume_value + (TC_MAX_FUEL_COUNT + 1u) - TC_RCan_Get_Fuel_Samples_Times_Old;
				}

				if(fuel_consum_delta > ((uint32)TC_Ftrip_T.tTC_Config_NVM.Max_fuelConPerCycle_NvmInit*fuel_pulse_input_rc_sum))
				{
					fuel_consum_delta = 0;
				}

				TC_RCan_Get_Fuel_Samples_Times_Old = fuel_pulse_input.u32_fuel_consume_value;
			}
			else
			{
				fuel_consum_delta = 0;
			}			
		}		
	}


	if(TC_Api_IFE_Accum_Enable()==TRUE)
	{
		TC_Ftrip_T.tIFE.tAccDat.u32AccumTime += fuel_pulse_input_rc_sum*20u;
	}
	else
	{
		TC_Ftrip_T.tIFE.tAccDat.u32AccumTime = 0;
	}

 	if(0 != fuel_consum_delta)
	{		
		if(TC_Api_IFE_Accum_Enable()==TRUE)
		{
			TC_Ftrip_T.tIFE.tAccDat.u32AccumFuelPulse += fuel_consum_delta;
            TC_Ftrip_T.tPhev.tAccDat.u32AccumFuelPulse+= fuel_consum_delta;
		}
		else
		{
			TC_Ftrip_T.tIFE.tAccDat.u32AccumFuelPulse = 0;
            TC_Ftrip_T.tPhev.tAccDat.u32AccumFuelPulse =0;
		}
		if(TC_Api_AFE_Accum_Enable()==TRUE)
		{
			TC_Ftrip_T.tAFE.tAccDat.u32AccumFuelPulse += fuel_consum_delta;
		}
		else
		{
			TC_Ftrip_T.tAFE.tAccDat.u32AccumFuelPulse = 0;
		}
		if(TC_Api_AVS_Accum_Enable()==TRUE)
		{
			TC_Ftrip_T.tAVS.tAccDat.u32AccumFuelPulse += fuel_consum_delta;
		}
		else
		{
			TC_Ftrip_T.tAVS.tAccDat.u32AccumFuelPulse = 0;
		}
		if(TC_Api_DTE_Accum_Enable()==TRUE)
		{			
			TC_Ftrip_T.tDTE.tAccDat.u32AccumFuelPulse += fuel_consum_delta;
		}
		else
		{
			TC_Ftrip_T.tDTE.tAccDat.u32AccumFuelPulse = 0;
		}		
			
		if(TC_Ftrip_T.tFuel.u8FuelAccumEnable == TRUE)
		{
			TC_Ftrip_T.tFuel.u32FuelPulseAccum += fuel_consum_delta;
		}
		else
		{
			TC_Ftrip_T.tFuel.u32FuelPulseAccum = 0;
		}  
	}
}
/**********************************************************************************************************
*Function   : TC_Api_Accum_Time_Count                                                                  	  *
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
static void TC_Api_Accum_Time_Count(void)
{
	boolean os_time_status_u8 = FALSE;
	//uint32 time_count_u32;	
	uint32 os_time_count_u32;
	uint16 fl_new_odo_count_U8,odo_pulse_count_num_u8;
	CanFrameCounterType input=TC_RTE_API_GetSpeedMsgValue();

	/* init first */
	if(0 == TC_Collect_Time_Init_Status)
	{
	//	time_count_u32 = 20;	//unit:ms, the value depents on the time, how long the function is called.	
		os_time_count_u32 = 20;
		os_time_status_u8 = TC_RTE_OstmTimerStart((uint8)TC_Collect_Timer1);
		if(FALSE != os_time_status_u8)
		{
			TC_Collect_Time_Init_Status = 1;
		}
	}
	else
	{
		os_time_status_u8 = TC_RTE_Get_OstmTimerValue((uint8)TC_Collect_Timer1, &os_time_count_u32);
		if(FALSE == os_time_status_u8)
		{
			os_time_count_u32 = 20;
		}
		/* ife is just 1s calculate */
	//	time_count_u32 = 20;
	}	
#if 1
	fl_new_odo_count_U8 = input.Counter;//TC_RTE_API_Get_ODO_Count();  uint 0.1m 0-254, 255 is error. hardware odo rolling count,
		
	if ((TRUE !=TC_RTE_API_Get_ODO_err())&&(0xFFFF!=input.Data))
	{
		if( fl_new_odo_count_U8 > TC_Prev_Odo_rcCount  )
		{
			odo_pulse_count_num_u8 = ( (uint16)(fl_new_odo_count_U8 - TC_Prev_Odo_rcCount) );
		}
		else if(fl_new_odo_count_U8 < TC_Prev_Odo_rcCount  )
		{
			odo_pulse_count_num_u8 = ((uint16)((uint16)fl_new_odo_count_U8 + ( (uint16)0XFFFF - (uint16)TC_Prev_Odo_rcCount) + (uint16)1u ));
		}
		else
		{
			odo_pulse_count_num_u8 = 0;
		}

		TC_Prev_Odo_rcCount = fl_new_odo_count_U8;
	}
    else
    {
    	odo_pulse_count_num_u8  =1;
        if(0xFFFF!=input.Data)
        {
	        TC_Prev_Odo_rcCount = fl_new_odo_count_U8;
        }
    }
#endif

	//


	if(TC_Api_AFE_Accum_Enable()==TRUE)
	{
		TC_Ftrip_T.tAFE.tAccDat.u32AccumTime += os_time_count_u32;
	}
	else
	{
		TC_Ftrip_T.tAFE.tAccDat.u32AccumTime = 0;
	}
	if(TC_Api_AVS_Accum_Enable()==TRUE)
	{
		TC_Ftrip_T.tAVS.tAccDat.u32AccumTime += odo_pulse_count_num_u8*20u;
	}
	else
	{
		TC_Ftrip_T.tAVS.tAccDat.u32AccumTime = 0;
	}
	//if(TC_Api_DTE_Accum_Enable()==TRUE) 20201114 
	if(TC_Api_DTE_cal_Enable()==TRUE)
	{			
		TC_Ftrip_T.tDTE.tAccDat.u32AccumTime += os_time_count_u32;	
	}
	else
	{
		TC_Ftrip_T.tDTE.tAccDat.u32AccumTime = 0;
	}	
}

/**********************************************************************************************************
*Function   : TC_Api_Update_TC_FUEL_IFC_10S                                                               *
*                                                                                                         *
*Description: When the vehicle is running, and Volume_In>=Volume_Out
 A Damp_run_fuelup*IFC_Avg/ IFC_Max will be used at this time.	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: shujunhua                                                                                 *
*                                                                                                         *
*Date		: 2020-09-24                                                                                  *
**********************************************************************************************************/
static uint16 TC_Api_Update_TC_FUEL_IFC_10S(uint16 ife)
{   
    uint32 temp;
	if(TC_FUEL_IFC_QUEUE_PT<TC_FUEL_IFC_QUEUE_L)
	{
		TC_FUEL_IFC_QUEUE_SUM-=TC_FUEL_IFC_QUEUE[TC_FUEL_IFC_QUEUE_PT];
		TC_FUEL_IFC_QUEUE[TC_FUEL_IFC_QUEUE_PT]=(uint16)ife;
		TC_FUEL_IFC_QUEUE_SUM+=TC_FUEL_IFC_QUEUE[TC_FUEL_IFC_QUEUE_PT];
	}
	TC_FUEL_IFC_QUEUE_PT++;
	if(TC_FUEL_IFC_QUEUE_PT>=TC_FUEL_IFC_QUEUE_L)  {TC_FUEL_IFC_QUEUE_PT=0;}
	temp=TC_FUEL_IFC_QUEUE_SUM;
	temp/=TC_IFE_MAX_DISPLAY_VALUE_METRIC_H_NVM;
	if(temp>=1000uL) {temp=1000;}
	else if (temp<=100) {temp=100;}
	else {/*do nothing */ }
	return (uint16)temp;
	//TC_Ftrip_T.tIFC_10S=(uint16)temp; Expand 1000 times ge 333=0.333	
}

/**********************************************************************************************************
*Function	 : TC_Api_Computer_IFE																		   *
*																										   *
*Description: TBD																						   *
*																										   *
*Parameter  : NONE 																					   	   *
*																										   *
*Return	 : void 																					   	   *
*																										   *
*Author	 : Chao Feng																				       *
*																										   *
*Date		 : 2020-06-12																				   *
**********************************************************************************************************/
static void TC_Api_Computer_IFE(void)
{
	TC_IFE_STRUCT *pt_ife;
	
	pt_ife = &TC_Ftrip_T.tIFE;
	

	if(pt_ife->u32CalcTimeCount >= (10UL*TC_Ftrip_T.tTC_Config_NVM.IFC_POC_Update_NvmInit))
	{   	
		TC_Api_Computer_Uint_IFE();
		
//         pt_ife->u32CalcTimeCount -=TC_Ftrip_T.tTC_Config_NVM.IFC_POC_Update_NvmInit;  
		pt_ife->u32CalcTimeCount = 0;
		TC_Ftrip_T.tIFE.u32DisplayTimeTick++;
		if(pt_ife->u8CalcUnit == L_PER_100KM)
		{
			TC_Api_Computer_High_Threshold_IFE();
		if(TC_Ftrip_T.tIFE.u32DisplayTimeTick >= (TC_Ftrip_T.tTC_Config_NVM.RefreshRateIFC_NvmInit/10u))	
          {
             TC_Ftrip_T.tIFC_10S=(uint16)TC_Api_Update_TC_FUEL_IFC_10S((uint16)TC_Ftrip_T.tIFE.u32CalculationIFE); 
          }
			/*Expand 1000 times ge 333=0.333*/					
		}
		else if(pt_ife->u8CalcUnit == L_PER_HOUR)
		{
			TC_Api_Computer_Low_Threshold_IFE();
		}
		else
		{
			/* do nothing */
		}
	}
    else
    {
        if( TRUE == TC_RTE_API_Get_ECM2_err() )
        {
            TC_Api_Computer_Uint_IFE();
            TC_Ftrip_T.tIFE.u32DisplayTimeTick++;
        }
    }
}
/**********************************************************************************************************
*Function   : TC_Api_Computer_AVS                                                                     	  *
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
static void TC_Api_Computer_AVS(void)
{
	uint32 fl_ftrip_avs_disp_temp_U16;
	uint8 i;

	TC_AVS_STRUCT *pt_avs;
	
	pt_avs = &TC_Ftrip_T.tAVS;

	/* calc AFE pre 1000ms */
	if(pt_avs->u32CalcTimeCount >= 1000UL)
	{
		pt_avs->u32CalcTimeCount -= 1000UL;

		if(FALSE == TC_TESTBIT(TC_Trip_Input_Data_Status,TC_AFE_RESET_KEY))
		{
			for(i=0;i<TC_MAX_NUM_OF_AVS;i++)
			{
			    fl_ftrip_avs_disp_temp_U16 = TC_Pkg_Output_AVS(i); 

				if(fl_ftrip_avs_disp_temp_U16 == TC_AVS_AFTER_RESET_DASHES)
				{
					pt_avs->u32CurrentAVS[i] = TC_AVS_AFTER_RESET_DASHES;
				}
			    else if ( fl_ftrip_avs_disp_temp_U16 > TC_MAX_AVS_OR_AFE )
			    {
			      	pt_avs->u32CurrentAVS[i] = TC_MAX_AVS_OR_AFE;
			    }
				else
				{
					pt_avs->u32CurrentAVS[i] = fl_ftrip_avs_disp_temp_U16;
				}
			}
		}
		else
		{
			/* do nothing*/
		}
	}  	
}
/**********************************************************************************************************
*Function   : TC_Api_Computer_AFE                                                                     	  *
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
static void TC_Api_Computer_AFE(void)
{
	uint8 i;
	uint32 fl_ftrip_afe_disp_temp_U16;
	
	TC_AFE_STRUCT *pt_afe;
	
	pt_afe = &TC_Ftrip_T.tAFE;

	/* calc AFE pre 1000ms */
	if(pt_afe->u32CalcTimeCount >= 1000UL)
	{
		pt_afe->u32CalcTimeCount -= 1000UL;
		
		if(TC_Odo_Fuel_MIssing_Status != TRUE)
		{
			if(FALSE == TC_TESTBIT(TC_Trip_Input_Data_Status,TC_AFE_RESET_KEY))
			{
				for(i=0;i<TC_MAX_NUM_OF_AFE;i++)
				{
					fl_ftrip_afe_disp_temp_U16 = TC_Pkg_Output_AFE(i); /* XXX disp XX.X L/100KM */
					
					if(fl_ftrip_afe_disp_temp_U16 != TC_AVS_AFTER_RESET_DASHES)
					{ 						
						pt_afe->u32CurrentAFE[i] = fl_ftrip_afe_disp_temp_U16;

//						if ( ( pt_afe->u32CurrentAFE[i] > (uint32)TC_MAX_AFE_LPHKM ) && ( pt_afe->u32CurrentAFE[i] != (uint32_least)TC_AFE_AFTER_RESET_DASHES) )
//						{
//							pt_afe->u32CurrentAFE[i] = (uint32)TC_MAX_AFE_LPHKM;
//						}
					}
					else
					{
						pt_afe->u32CurrentAFE[i] = TC_AVS_AFTER_RESET_DASHES;
					}
				}
			}
			else
			{
			 	/* do nothing */
			}
		}
	}
}

/**********************************************************************************************************
*Function   : TC_Api_Computer_DTE                                                                     	  *
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
static void TC_Api_Computer_DTE(void)
{
	TC_DTE_STRUCT *pt_dte;
	uint8 fuel_error=TC_FUEL_Singal_Status;
	pt_dte = &TC_Ftrip_T.tDTE;	
    
	TC_FUEL_Singal_Status =TC_API_Get_Fuel_Error_State();
	if(fuel_error!=TC_FUEL_Singal_Status)
	{
	  pt_dte->u32CalcTimeCount =1000;
	}
	/* calc AFE when enter fastfill mode */
    #if 0
    /*old code */
    if(0 != TC_API_Get_Fuel_FastFill_State())
	{   
		pt_dte->u32CalcTimeCount = 0;
		pt_dte->u32CalculationDTE = TC_Pkg_Output_DTE(); 
	}
    #endif 
    /*add The addition of two tanks can also be calculated under the condition of only one fault */
	if((FALSE != TC_API_Get_Fuel_FastFill_State())||(TC_Module_Init_Flag==TRUE))
	{   
		pt_dte->u32CalcTimeCount = 0;
		pt_dte->u32CalculationDTE = TC_Pkg_Output_DTE(); 
	}
    else if ((FALSE != TC_Rte_Api_Get_Fuel_ONE_Error_State())||(FALSE == TC_Pkg_Get_Dte_Calc_Enable()))
    {
       // TC_Pkg_Out_Set_Dte_Calc_Enable(0); 
        TC_API_Get_Fuel_ONE_Error_State_Clear(); 
        pt_dte->u32CalcTimeCount = 0;
        pt_dte->u32CalculationDTE = TC_Pkg_Output_DTE(); 
       /* 20210723 :Add menu resets display current calculated value*/
    #ifdef TC_DTE_MENU_RESET_ENABLE
        if(TC_Dte_Reset_update == TRUE)
        {  
            TC_Dte_Reset_update = FALSE;
            pt_dte->u32DisplayDTE=pt_dte->u32CalculationDTE; 
            pt_dte->u32CurrentDTE=pt_dte->u32CalculationDTE;
        }
    #endif 
      //  pt_dte->u32DisplayDTE=pt_dte->u32CalculationDTE; 
      /*Optimized for quick updates after failure recovery*/ 
       // pt_dte->u32CurrentDTE=pt_dte->u32CalculationDTE;
    }
	/* calc AFE pre 1000ms */
	else if((FALSE != TC_Api_DTE_cal_Enable())&&(pt_dte->u32CalcTimeCount >= 1000UL))
	{
		pt_dte->u32CalcTimeCount -= 1000UL;
		pt_dte->u32CalculationDTE = TC_Pkg_Output_DTE(); 
	}
	else
	{
		/* do nothing */
	}
}
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
void TC_Api_AVS_Reset(uint8 tc_key_index)
{
	TC_SETBIT(TC_Trip_Input_Data_Status,TC_AVS_RESET_KEY);
  TC_Pkg_AVS_Reset(tc_key_index);
  TC_Ftrip_T.tAVS.u32DisplayAVS[tc_key_index] = TC_AVS_AFTER_RESET_DASHES;
  TC_Ftrip_T.tAVS.u32CurrentAVS[tc_key_index] = TC_AVS_AFTER_RESET_DASHES;
  TC_Reset_Index = tc_key_index;
  //modify by fchao in 20200615 no uesd 
  //gl_AVS_distance_after_reset = 0;
  TC_Ftrip_T.tAVS.u8NormalDisplay[tc_key_index] = FALSE;
  // modify by fchao in 20200615
  //KernelStart13BitTimer(TIMER_13BIT_BASE_512MS,((uint16)TC_AVS_UPDATE_CONDITION_TIME_NVM),ftrip_avs_display_KSWTIMER);
}
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
void TC_Api_AVS_Reset_All(void)
{
	uint16 i;

  /*
  ** Upon reset for first 1 sec cluster shows 0
  */
  TC_CLEARBIT(TC_Trip_Input_Data_Status,TC_DATA_ACCUMULATED_ONCE_AVS);
  /*
  ** call Package function
  */
  for(i=0;i<TC_MAX_NUM_OF_AVS;i++)
  {
  	TC_Pkg_AVS_Reset((uint8)i);
	TC_Ftrip_T.tAVS.u8NormalDisplay[i] = FALSE;
  }
  /*
  ** Clear the pkg input data
  */
  /*
  **  Clear the pkg accumulator for AVS, AFE, DTE
  */
}


void TC_Api_trip_Reset_All(void)
{
    uint8 i;
    for(i=0;i<TC_MAX_NUM_OF_TRIP;i++)
    {
        TC_Ftrip_T.ttrip[i] = ((uint32)0);
    }

}

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
void TC_Api_AFE_Reset(uint8 afe_index)
{
  /*
  ** Upon RESET set bit 5
  */
  TC_SETBIT(TC_Trip_Input_Data_Status,TC_AFE_RESET_KEY);
  /*
  ** Upon reset for first 1 sec cluster shows dashes
  */
  TC_CLEARBIT(TC_Trip_Input_Data_Status,TC_DATA_ACCUMULATED_ONCE_AFE);
  /*
  ** call Package function
  */
  	TC_Pkg_AFE_Reset(afe_index);
	TC_Ftrip_T.tAFE.u32CurrentAFE[afe_index] = TC_AFE_AFTER_RESET_DASHES;
	/* To Reset the AFE displayable US value */
	TC_Ftrip_T.tAFE.u32DisplayAFE[afe_index]=TC_AFE_AFTER_RESET_DASHES;
	TC_Ftrip_T.tAFE.u8NormalDisplay[afe_index]= FALSE;

  //KernelStart13BitTimer(TIMER_13BIT_BASE_512MS,((uint16)40),ftrip_afe_display_KSWTIMER2);
  
  /*
  ** Set afe reset flag  and clear accumulator status flag
  */
  TC_SETBIT(TC_Trip_Input_Data_Status,TC_BATTERY_CONNECT_OR_RESET);
  TC_CLEARBIT(TC_Trip_Input_Data_Status,TC_TRIP_ODO_COUNT_CHANGE);
  TC_CLEARBIT(TC_Trip_Input_Data_Status,TC_TRIP_FUEL_PULSE_CHANGE);
  /*
  ** Clear the pkg input data
  */
  /*
  **  Clear the pkg accumulator for AVS, AFE, DTE
  */
}
/**********************************************************************************************************
*Function   : TC_Api_AFE_Reset_All                                                                     	  *
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
void TC_Api_AFE_Reset_All(void)
{
	uint16 i;
  /*
  ** Upon RESET set bit 5
  */
  TC_SETBIT(TC_Trip_Input_Data_Status,TC_AFE_RESET_KEY);
  /*
  ** Upon reset for first 1 sec cluster shows dashes
  */
  TC_CLEARBIT(TC_Trip_Input_Data_Status,TC_DATA_ACCUMULATED_ONCE_AFE);
  /*
  ** call Package function
  */
  for(i=0;i<TC_MAX_NUM_OF_AFE;i++)
  {
  	TC_Pkg_AFE_Reset((uint8)i);
	/* To Reset the AFE displayable US value */
	TC_Ftrip_T.tAFE.u32CurrentAFE[i] = TC_AFE_AFTER_RESET_DASHES;
	TC_Ftrip_T.tAFE.u32DisplayAFE[i]=TC_AFE_AFTER_RESET_DASHES;
	TC_Ftrip_T.tAFE.u8NormalDisplay[i]= FALSE;
  }
  
  //KernelStart13BitTimer(TIMER_13BIT_BASE_512MS,((uint16)40),ftrip_afe_display_KSWTIMER2);
  /*
  ** Set afe reset flag  and clear accumulator status flag
  */
  TC_SETBIT(TC_Trip_Input_Data_Status,TC_BATTERY_CONNECT_OR_RESET);
  TC_CLEARBIT(TC_Trip_Input_Data_Status,TC_TRIP_ODO_COUNT_CHANGE);
  TC_CLEARBIT(TC_Trip_Input_Data_Status,TC_TRIP_FUEL_PULSE_CHANGE);
  /*
  ** Clear the pkg input data
  */
  /*
  **  Clear the pkg accumulator for AVS, AFE, DTE
  */
}

void TC_Api_Dte_Reset(void)
{
	
	 /*
     Clear the pkg input data
    */
	TC_Pkg_DTE_Reset(0);
    TC_Dte_Reset_update =TRUE;


}

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
void TC_Api_Reset_TC_All(void)
{
	TC_Api_AFE_Reset_All();
	TC_Api_AVS_Reset_All();
}
/**********************************************************************************************************
*Function   : TC_Api_Update_trip                                                                     	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: shujunhua                                                                                 *
*                                                                                                         *
*Date		: 2020-09-17                                                                                  *
**********************************************************************************************************/
void TC_Api_Update_trip(void)
{ 
	TC_Ftrip_T.ttrip[0] =TC_RTE_API_Get_trip_value(0);
	TC_Ftrip_T.ttrip[1] =TC_RTE_API_Get_trip_value(1);		
}

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
void TC_Api_Update_AVS(void)
{
	uint8 i;
	uint32 s_u16CurrAVSDisp[TC_MAX_NUM_OF_AVS] = {0uL,0uL};

	TC_Ftrip_T.tAVS.u32DisplayTimeTick++;

	if(FALSE != TC_API_Get_Power_Mode_State())
	{
		if((FALSE != TC_TESTBIT(TC_Trip_Input_Data_Status,TC_AVS_RESET_KEY)))
		{
			TC_CLEARBIT(TC_Trip_Input_Data_Status,TC_AVS_RESET_KEY);
			
			for(i=0;i<TC_MAX_NUM_OF_AVS;i++)
			{
				if(i==(TC_Reset_Index))
				{
					TC_Ftrip_T.tAVS.u32CurrentAVS[i] = TC_AVS_AFTER_RESET_DASHES;
				}
			}
		}
		
		if(FALSE != TC_Api_AVS_Display_Condition())
		{
			for(i=0;i<TC_MAX_NUM_OF_AVS;i++)
			{
				if(FALSE == TC_Ftrip_T.tAVS.u8NormalDisplay[i])
				{
					s_u16CurrAVSDisp[i] = TC_AVS_AFTER_RESET_DASHES;

					/* distance >300m display after reset*/
					if(TC_Pkg_Get_Distance_AVS(i) >= TC_Ftrip_T.tTC_Config_NVM.AVSMinDistanceThresh_NvmInit)
					{
						TC_Ftrip_T.tAVS.u8NormalDisplay[i] = TRUE;
					}
				}
				else
				{
					s_u16CurrAVSDisp[i] = TC_Ftrip_T.tAVS.u32CurrentAVS[i];
				}
			}
		}
		else
		{
			for(i=0;i<TC_MAX_NUM_OF_AVS;i++)
			{
				s_u16CurrAVSDisp[i] = TC_AVS_AFTER_RESET_DASHES;
			}
		}		
	}
	else
	{	
		for(i=0;i<TC_MAX_NUM_OF_AVS;i++)
		{
			s_u16CurrAVSDisp[i] = TC_Ftrip_T.tAVS.u32DisplayAVS[i];
		}
	}
	
	for(i=0;i<TC_MAX_NUM_OF_AVS;i++)
	{
		if(((TC_Ftrip_T.tAVS.u32DisplayAVS[i] == TC_AVS_AFTER_RESET_DASHES)&&(s_u16CurrAVSDisp[i] != TC_AVS_AFTER_RESET_DASHES))||
		   ((TC_Ftrip_T.tAVS.u32DisplayAVS[i] != TC_AVS_AFTER_RESET_DASHES)&&(s_u16CurrAVSDisp[i] == TC_AVS_AFTER_RESET_DASHES)))
		{
			TC_Ftrip_T.tAVS.u32DisplayTimeTick = TC_Ftrip_T.tTC_Config_NVM.RefreshRateAVS_NvmInit;
		}
	}
	
	/* display per 10s */
	if(TC_Ftrip_T.tAVS.u32DisplayTimeTick >= TC_Ftrip_T.tTC_Config_NVM.RefreshRateAVS_NvmInit)
  	{
		TC_Ftrip_T.tAVS.u32DisplayTimeTick = 0;
		
		for(i=0;i<TC_MAX_NUM_OF_AVS;i++)
		{
			TC_Ftrip_T.tAVS.u32DisplayAVS[i] = s_u16CurrAVSDisp[i];
		}
        TC_SETBIT(TC_Ftrip_T.Tc_Ipc_Update,(uint8)TC_IPC_NOTIFICATION_AVS_BIT);
	}
	else
	{
		/*do nothing*/
	}

	if(FALSE == TC_Ftrip_T.tTC_Config_NVM.AVSADisplayEnable_NvmInit)
	{
		/* display off */
		TC_Ftrip_T.tAVS.u32DisplayAVS[0] = TC_AVS_DISPLAY_OFF_DASHES;
	}

	if(FALSE == TC_Ftrip_T.tTC_Config_NVM.AVSBDisplayEnable_NvmInit)
	{
		/* display off */
		TC_Ftrip_T.tAVS.u32DisplayAVS[1] = TC_AVS_DISPLAY_OFF_DASHES;
	}	
}

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
void TC_Api_Update_AFE(void)
{	
	uint8 i;
	uint32 s_u16CurrAFEDisp[TC_MAX_NUM_OF_AFE] = {0uL,0uL,0uL};

	TC_Ftrip_T.tAFE.u32DisplayTimeTick++;
	
	if(FALSE != TC_API_Get_Power_Mode_State())
	{		
		if(FALSE != TC_TESTBIT(TC_Trip_Input_Data_Status,TC_AFE_RESET_KEY))
		{
         	TC_CLEARBIT(TC_Trip_Input_Data_Status,TC_AFE_RESET_KEY);

			for(i=0;i<TC_MAX_NUM_OF_AFE;i++)
			{
				if(i==(TC_Reset_Index))
				{
					TC_Ftrip_T.tAFE.u32CurrentAFE[TC_Reset_Index] = TC_AFE_AFTER_RESET_DASHES;
				}
			}			
		}
		
		if(FALSE != TC_Api_AFE_Display_Condition())
		{
			for(i=0;i<TC_MAX_NUM_OF_AFE;i++)
			{			
				if(TC_Ftrip_T.tAFE.u8NormalDisplay[i]==FALSE)
				{					
					s_u16CurrAFEDisp[i] = TC_AFE_AFTER_RESET_DASHES;

					/* distance >300m display after reset*/
					if(TC_Pkg_Up_Min_Distance_AFE(i) >= TC_Ftrip_T.tTC_Config_NVM.AFCMinDistanceThresh_NvmInit)
					{
						TC_Ftrip_T.tAFE.u8NormalDisplay[i]= TRUE;
					}
				}
				else
				{					
					s_u16CurrAFEDisp[i] = TC_Ftrip_T.tAFE.u32CurrentAFE[i];
                    TC_Ftrip_T.tAFE.u32DisplayAFE_bu[i] =TC_Ftrip_T.tAFE.u32CurrentAFE[i]; /*Fix bug 44976*/
				}				
			}
		}
		else
		{			
			for(i=0;i<TC_MAX_NUM_OF_AFE;i++)
			{
				s_u16CurrAFEDisp[i] = TC_AFE_AFTER_RESET_DASHES;
			}
		}
	}
	else
	{	
		for(i=0;i<TC_MAX_NUM_OF_AFE;i++)
		{
			s_u16CurrAFEDisp[i] = TC_Ftrip_T.tAFE.u32DisplayAFE[i];
		}
	}
	
	for(i=0;i<TC_MAX_NUM_OF_AFE;i++)
	{
		if(((TC_Ftrip_T.tAFE.u32DisplayAFE[i] == TC_AFE_AFTER_RESET_DASHES)&&(s_u16CurrAFEDisp[i] != TC_AFE_AFTER_RESET_DASHES))||
		   ((TC_Ftrip_T.tAFE.u32DisplayAFE[i] != TC_AFE_AFTER_RESET_DASHES)&&(s_u16CurrAFEDisp[i] == TC_AFE_AFTER_RESET_DASHES)))
		{
			TC_Ftrip_T.tAFE.u32DisplayTimeTick = TC_Ftrip_T.tTC_Config_NVM.RefreshRateAFC_NvmInit;
		}
         if((TC_Ftrip_T.tAFE.u32DisplayAFE[i] != TC_AFE_AFTER_RESET_DASHES) && (s_u16CurrAFEDisp[i] == TC_AFE_AFTER_RESET_DASHES))  
         {
            TC_Ftrip_T.tAFE.u32DisplayAFE_bu[i] = TC_Ftrip_T.tAFE.u32DisplayAFE[i];
         }
          if((TC_Ftrip_T.tAFE.u32DisplayAFE[i] == TC_AFE_AFTER_RESET_DASHES) && (s_u16CurrAFEDisp[i] != TC_AFE_AFTER_RESET_DASHES))  
         {
            s_u16CurrAFEDisp[i] = TC_Ftrip_T.tAFE.u32DisplayAFE_bu[i];
         }
         
           
	}
	
	/* display per 10s */
	if(TC_Ftrip_T.tAFE.u32DisplayTimeTick >= TC_Ftrip_T.tTC_Config_NVM.RefreshRateAFC_NvmInit)
  	{
		TC_Ftrip_T.tAFE.u32DisplayTimeTick = 0;
		
		for(i=0;i<TC_MAX_NUM_OF_AFE;i++)
		{
			TC_Ftrip_T.tAFE.u32DisplayAFE[i] = s_u16CurrAFEDisp[i];
            
		}
        TC_SETBIT(TC_Ftrip_T.Tc_Ipc_Update,(uint8)TC_IPC_NOTIFICATION_AFE_BIT);
	}

	if(0u == TC_Ftrip_T.tTC_Config_NVM.AFCADisplayEnable_NvmInit)
	{
		/* display off */
		TC_Ftrip_T.tAFE.u32DisplayAFE[0] = TC_AFE_DISPLAY_OFF_DASHES;
	}

	if(0u == TC_Ftrip_T.tTC_Config_NVM.AFCBDisplayEnable_NvmInit)
	{
		/* display off */
		TC_Ftrip_T.tAFE.u32DisplayAFE[1] = TC_AFE_DISPLAY_OFF_DASHES;
	}
}
/**********************************************************************************************************
*Function   : TC_Api_Update_IFE                                                                     	  *
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
static void TC_Api_Update_IFE(void)
{	
	
	if(FALSE != TC_API_Get_Power_Mode_State())
	{
		//if((FALSE == TC_Api_IFE_Accum_Enable()) || (FALSE !=TC_RTE_API_Get_ECM2_err()))
		if(FALSE !=TC_RTE_API_Get_ECM2_err())
		{
			TC_Ftrip_T.tIFE.u32CurrentIFE = TC_IFE_AFTER_RESET_DASHES;
		}
		else
		{
			TC_Ftrip_T.tIFE.u32CurrentIFE = TC_Ftrip_T.tIFE.u32CalculationIFE;
		}
	}
	else
	{  
	   
	   if(FALSE !=TC_RTE_API_Get_ECM2_err())
		{
			TC_Ftrip_T.tIFE.u32CurrentIFE = TC_IFE_AFTER_RESET_DASHES;
		}
		else
		{
			//TC_Ftrip_T.tIFE.u32CurrentIFE = 0;
		}
	}	

	if(((TC_Ftrip_T.tIFE.u32CurrentIFE == TC_IFE_AFTER_RESET_DASHES)&&(TC_Ftrip_T.tIFE.u32DisplayIFE != TC_IFE_AFTER_RESET_DASHES))||
		   ((TC_Ftrip_T.tIFE.u32CurrentIFE != TC_IFE_AFTER_RESET_DASHES)&&(TC_Ftrip_T.tIFE.u32DisplayIFE == TC_IFE_AFTER_RESET_DASHES)))
	{
		TC_Ftrip_T.tIFE.u32DisplayTimeTick = (TC_Ftrip_T.tTC_Config_NVM.RefreshRateIFC_NvmInit/10u);
	}
		   
	/* display per 1s */
	if(TC_Ftrip_T.tIFE.u32DisplayTimeTick >= (TC_Ftrip_T.tTC_Config_NVM.RefreshRateIFC_NvmInit/10u))
  	{
		TC_Ftrip_T.tIFE.u32DisplayTimeTick = 0;	
		TC_Ftrip_T.tIFE.u32DisplayIFE = TC_Ftrip_T.tIFE.u32CurrentIFE;
        TC_Ftrip_T.tIFE.u8DisplayUnit = TC_Ftrip_T.tIFE.u8CalcUnit;
        TC_SETBIT(TC_Ftrip_T.Tc_Ipc_Update,(uint8)TC_IPC_NOTIFICATION_IFE_BIT);
	}

	if(0u == TC_Ftrip_T.tTC_Config_NVM.IFCDisplayEnable_NvmInit)
	{
		/* display off */
		TC_Ftrip_T.tIFE.u32DisplayIFE = TC_IFE_DISPLAY_OFF_DASHES;
	}
}
/**********************************************************************************************************
*Function   : TC_Api_Update_DTE                                                                     	  *
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
#if 0
uint32 Tc_api_abs(sint32 c)
{
    if (c < 0)
    {
        c = ~(c - (sint32)1);
    }

    return ((uint32)c);
}
#endif
/** 
 * [TC_Api_u32_abs : description]
 * @Author   Hai Hu
 * @DateTime 2021/11/08
 * @param    uint32                     [description]
 * @param    uint32                     [description]
 */
uint32 TC_Api_u32_abs(uint32 a, uint32 b)
{
    return ((a>b)?(a-b):(b-a));
}

#ifdef TC_DTE_NEW_STRATEGY_0413 
/** 
 * [TC_Api_Update_DTE_Damp_Value : description]
 * @Author   shujunhua
 * @DateTime 2021/5/28-16:29:28
 * @param    dte_k_mode               [TC_DTE_K_UPDATE_ENUM]
 * @param    trip1S                   [unit :m]
 */
static uint64 TC_Api_Update_DTE_Damp_Value(TC_DTE_K_UPDATE_ENUM dte_k_mode,uint32 trip1S)
{   
    uint16 k_value=0;
    uint64 dte_damp_value=0;
    k_value = TC_Ftrip_T.tDTE.DTE_Trip1S_k ;
    switch (dte_k_mode)
	{
    	case DTE_K_SlowUpdate :  k_value=5 ;  break ;
        case DTE_K_NormalUpdate: k_value=10 ; break ;
        case DTE_K_FastUpdate :  k_value=20 ; break ;
        default :
        //TC_Ftrip_T.tDTE.NorDiff_1L_dte = 100/afe ;
        //TC_Ftrip_T.tDTE.UnNorDiff_15L_dte = 100/afe ;
           
        break;
	}
    TC_Ftrip_T.tDTE.DTE_Trip1S_k_Mode = dte_k_mode; 
    if(k_value != TC_Ftrip_T.tDTE.DTE_Trip1S_k )
    {
        TC_Ftrip_T.tDTE.DTE_Trip1S_k =  k_value;
        TC_Ftrip_T.tDTE.Dte_Task_tick = 0;
        dte_damp_value = 0 ;    
    }
    else
    {
        dte_damp_value =(uint64)trip1S *k_value/100;
    }
    
   
 return dte_damp_value ;
}

static void TC_Api_DTE_Idle_Update(void)
{
    TC_Dte_Error_Count =0;
    TC_Ftrip_T.tDTE.Dte_Task_tick =0;
    TC_Ftrip_T.tDTE.DTE_Trip1S = 0; /*unit 0.1m*/
    TC_Ftrip_T.tDTE.DTE_Trip1S_k_Mode = DTE_K_Idle_Update; 
    TC_Pkg_Clear_DTE_1s_Distance();
    if(FALSE!=TC_Pkg_Get_DTE_Idle_Update())
    {
        TC_Pkg_Set_DTE_Idle_Update (FALSE);
        TC_Ftrip_T.tDTE.u32CurrentDTE-=100; /* reduce 100m */
    }
    else
    {

    }

}
/** 
 * [TC_Api_Update_DTE_New : 100ms update]
 * @Author   shujunhua
 * @DateTime 2021/5/27-19:59:12
 * @param    void                     [description]
 */
  
static void TC_Api_Update_DTE_New(void)
{
    uint32 su32CurrDTEDispVal;
    uint32 u32dte_delta;
    uint32  delta=10*1000;
    uint32 sfc=0;
    uint32 dte_delta_15L;
    uint64 temp;
    uint16 speed=0;
   
	TC_Ftrip_T.tDTE.u32DisplayTimeTick++;
	TC_Ftrip_T.tDTE.u8Refresh_Last_Mode = TC_Ftrip_T.tDTE.u8Refresh_Mode;   
    TC_Dte_idle_update = TC_Pkg_Get_DTE_Idle_Update();
    /*Periodic fuel consumption*/
    sfc =TC_Pkg_Get_DTE_Fuel_Stage_Consumption_Value(0);
    TC_Ftrip_T.tDTE.SFC = sfc ;
    /*Obtain actual speed*/
    speed =  TC_API_Get_Speed_For_Dte();
     /*
     NorDiff_1L_dte:The mileage you can run on 1 liter of oil ,factor:1000,eg 10000=10km
     UnNorDiff_15L_dte:The mileage you can run on 15 liter of oil ,factor:1000
     Fuel_Consump100m : The amount of fuel required to drive 100 meters ,unit :ml 
    */
    if(sfc!=0)
    {
        TC_Ftrip_T.tDTE.NorDiff_1L_dte = (uint32)(100000000ULL/(sfc)); /*factor :1000,eg 1km =1000*/
        TC_Ftrip_T.tDTE.UnNorDiff_15L_dte = (uint32)(100000000ULL*15/(sfc));/*factor :1000,eg 1km =1000*/
        TC_Ftrip_T.tDTE.Fuel_Consump100m  = sfc ;   /*factor :1000,eg 7.5L =7500ul*/
    }
        
	if((FALSE != TC_API_Get_Power_Mode_State())&&(FALSE != TC_API_Get_Fuel_Finished_Init_State()))
	{  
	    TC_Dte_Delay_Count++;
		if(TC_Dte_Delay_Count>=TC_DTE_KEYON_DELAY)
	    {
		 TC_Dte_Delay_Count =TC_DTE_KEYON_DELAY;

		}
		/* if in fastfill mode, display need update immedately*/
		if((FALSE != TC_API_Get_Fuel_FastFill_State())||(TC_Module_Init_Flag==TRUE))
		{
			/* display --- when 1-ODO error 2-EMC2 missing 3-fuel error*/
			//if((FALSE == TC_Api_DTE_Accum_Enable()) || (FALSE != TC_API_Get_Fuel_Error_State())	)
		//	if((FALSE == TC_Api_DTE_Accum_Enable()))
		TC_Ftrip_T.tDTE.DTE_Trip1S_k_Mode = DTE_K_Fuel_FastUpdate;
		if(((TC_Dte_Delay_Count ==TC_DTE_KEYON_DELAY) && ((TRUE ==TC_RTE_API_Get_ODO_err())||(TRUE ==TC_RTE_API_Get_ECM2_err())))||(FALSE != TC_RTE_API_Get_Fuel_Error_State()))
			{
				TC_Ftrip_T.tDTE.u32CurrentDTE = TC_DTE_DISPLAY_DASHES;

				/*  --- mode  */
				TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_ERROR_MODE;
			}
			else
			{
				/* if just exit from eeror mode,  u32dte_delta =  0xffffffff - u32CalculationDTE */
				/* u32dte_delta is to max. so display u32CalculationDTE value					 */
				if(TC_DTE_DISPLAY_DASHES == TC_Ftrip_T.tDTE.u32CurrentDTE)
				{
					u32dte_delta = (uint32)0;
					TC_Ftrip_T.tDTE.u32CurrentDTE = TC_Ftrip_T.tDTE.u32CalculationDTE;

					/*  refsh display mode  */
					TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_UPDATE_IMMED_MODE;
				}
				else if(TC_DTE_DISPLAY_LOW_DASHES == TC_Ftrip_T.tDTE.u32CurrentDTE)
				{
                    u32dte_delta = TC_Api_u32_abs(TC_Ftrip_T.tDTE.u32CalculationDTE, (50 *1000UL));
				}
				else
				{
					//u32dte_delta = TC_Ftrip_T.tDTE.u32DisplayDTE - TC_Ftrip_T.tDTE.u32CalculationDTE;
                    u32dte_delta=  TC_Api_u32_abs(TC_Ftrip_T.tDTE.u32DisplayDTE, TC_Ftrip_T.tDTE.u32CalculationDTE);                
				}		
                
				if(0 != TC_Pkg_Get_DTE_Fuel_Stage_Consumption_Value(0))
				{
					delta = (uint32)(((uint64)299 *100 * 10 * 1000UL)/TC_Pkg_Get_DTE_Fuel_Stage_Consumption_Value(0));
					delta /= 2;
				}    
				//if((u32dte_delta < (sint32)10 * 1000) && (u32dte_delta > (sint32)(-10) * 1000))
				if((uint32)u32dte_delta < delta)
				{
					/* keep last value mode*/
				}
				else
				{		
					/* if u32CalculationDTE is less than 50km, display need invaild */
					if(TC_Ftrip_T.tDTE.u32CalculationDTE < (uint32)50 * 1000)
					{
						TC_Ftrip_T.tDTE.u32CurrentDTE = TC_DTE_DISPLAY_LOW_DASHES;						
						/*	low mode */
						TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_LOW_MODE;
					}	
					else
					{
						TC_Ftrip_T.tDTE.u32CurrentDTE = TC_Ftrip_T.tDTE.u32CalculationDTE;    
                        TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_UPDATE_IMMED_MODE;

					}					
				}
			}
			
		}
		else
		{  
			 TC_Ftrip_T.tDTE.DTE_Trip1S_k_Mode =DTE_K_None_Update;			
		if ((FALSE != TC_API_Get_Fuel_Error_State())||((TC_Dte_Delay_Count ==TC_DTE_KEYON_DELAY) &&\
            ((TRUE ==TC_RTE_API_Get_ODO_err())||(TRUE ==TC_RTE_API_Get_ECM2_err())))||(FALSE != TC_RTE_API_Get_Fuel_Error_State()))
			 
			{   
                #if 0
    				if(TC_RTE_API_Get_ODO_err())
    			    {
    			    	TC_MODULE_DEBUG_INFO("ODO ERR=%d",TC_RTE_API_Get_ODO_err());
    			    }
    				if(TC_RTE_API_Get_ECM2_err())
    			    {
    			    	TC_MODULE_DEBUG_INFO("ECM ERR=%d",TC_RTE_API_Get_ECM2_err());
    			    }
    				if(TC_API_Get_Fuel_Error_State())
    			    {
    			    	TC_MODULE_DEBUG_INFO("FUEL ERR=%d",TC_API_Get_Fuel_Error_State());
    			    }
    				if(TC_RTE_API_Get_Fuel_Error_State())
    			    {
    			    	TC_MODULE_DEBUG_INFO("FUEL_MUTI_ERR=%d",TC_API_Get_Fuel_Error_State());
    			    }
                #endif 
			  
				TC_Ftrip_T.tDTE.u32CurrentDTE = TC_DTE_DISPLAY_DASHES;

				/*  --- mode  */
				TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_ERROR_MODE;
                TC_Ftrip_T.tDTE.u32DisplayTimeTick = TC_Ftrip_T.tTC_Config_NVM.RefreshRateDTE_NvmInit;
			}
			else
			{	
                
		  	   if(TC_DTE_DISPLAY_DASHES == TC_Ftrip_T.tDTE.u32CurrentDTE)
				{
			
					TC_Ftrip_T.tDTE.u32CurrentDTE = TC_Ftrip_T.tDTE.u32CalculationDTE;
                    TC_Ftrip_T.tDTE.u32DisplayDTE = TC_Ftrip_T.tDTE.u32CalculationDTE;
                    TC_Ftrip_T.tDTE.u32DisplayTimeTick = TC_Ftrip_T.tTC_Config_NVM.RefreshRateDTE_NvmInit;
                    
				}
				else if(DTE_REFRESH_LOW_MODE == TC_Ftrip_T.tDTE.u8Refresh_Mode)
				{
					TC_Ftrip_T.tDTE.u32CurrentDTE = TC_DTE_DISPLAY_LOW_DASHES;
					/*  low mode */
					TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_LOW_MODE;
				}
				//else if(FALSE == TC_API_Get_EngSpd_State())
				else if (FALSE ==TC_Api_DTE_cal_Enable()) /*add it for hev vehicle*/
				{
					/* keep last display value*/
					TC_Ftrip_T.tDTE.u32CurrentDTE = TC_Ftrip_T.tDTE.u32DisplayDTE;

					/*  keep last mode  */
					TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_KEEP_MODE;			

                    
				}
				else
				{
					/* if just exit from eeror mode,  u32dte_delta =  0xffffffff - u32CalculationDTE */
					/* u32dte_delta is to max. so display u32CalculationDTE value					 */
					if(TC_DTE_DISPLAY_DASHES == TC_Ftrip_T.tDTE.u32CurrentDTE)
					{
						u32dte_delta = 0;
						TC_Ftrip_T.tDTE.u32CurrentDTE = TC_Ftrip_T.tDTE.u32CalculationDTE;
						
					}
					else
					{
                        u32dte_delta = TC_Api_u32_abs(TC_Ftrip_T.tDTE.u32DisplayDTE, TC_Ftrip_T.tDTE.u32CalculationDTE);
					}
                    
                   /*Determine whether the vehicle is idling ,TRUE: not idling*/
                   if(FALSE != TC_API_Get_VehRunning_State())
                   {                                                   
                        TC_Ftrip_T.tDTE.Dte_Task_tick++;
                       
                        if(TC_Ftrip_T.tDTE.Dte_Task_tick>=TC_DTE_UPADTE_S)
                        {
                            TC_Ftrip_T.tDTE.Dte_Task_tick = 0;
                            /*DTE_Trip1S :Trip cumulative value in 1s ,unit 0.1m eg 250000=25KM*/
                            TC_Ftrip_T.tDTE.DTE_Trip1S = TC_Pkg_Get_DTE_1s_Distance(); /*unit 0.1m*/
                            TC_Pkg_Clear_DTE_1s_Distance();
                             /*u32DisplayDTE >=u32CalculationDTE */
                            if(TC_Ftrip_T.tDTE.u32DisplayDTE >= TC_Ftrip_T.tDTE.u32CalculationDTE)
                            {   
                            /*The difference is greater than the DTE of 1L */
                                if(u32dte_delta > TC_Ftrip_T.tDTE.NorDiff_1L_dte)
                                {   
                                    if(TC_Ftrip_T.tDTE.NorDiff_1L_dte != 0)
                                    {
                                       temp = 1000uLL*u32dte_delta/TC_Ftrip_T.tDTE.NorDiff_1L_dte ; 
                                       if(temp>=2000) 
                                       {
                                       temp = 2000;
                                       }
                                       temp *= TC_Api_Update_DTE_Damp_Value(DTE_K_FastUpdate,TC_Ftrip_T.tDTE.DTE_Trip1S);
                                       temp /=1000;
                                    }
                                    else
                                    {
                                     temp =0 ;   
                                    }
                                    TC_Ftrip_T.tDTE.u32CurrentDTE-= temp ;                                                                    
                                   // TC_Ftrip_T.tDTE.u32CurrentDTE-= TC_Api_Update_DTE_Damp_Value(DTE_K_FastUpdate,TC_Ftrip_T.tDTE.DTE_Trip1S);                                 
                                }
                                else 
                                {
                                     TC_Ftrip_T.tDTE.u32CurrentDTE-= TC_Api_Update_DTE_Damp_Value(DTE_K_NormalUpdate,TC_Ftrip_T.tDTE.DTE_Trip1S);   
                                }
                            }
                             /*u32DisplayDTE <u32CalculationDTE */
                            else
                            {   //u32dte_delta = -u32dte_delta;
                                /*The difference is greater than the DTE of 1L */
                                if(u32dte_delta > TC_Ftrip_T.tDTE.NorDiff_1L_dte)
                                {
                                    if (TC_Ftrip_T.tDTE.NorDiff_1L_dte !=0 ) 
                                    {
                                        if(u32dte_delta != 0 )  
                                        {
                                            temp = 1000uLL*TC_Ftrip_T.tDTE.NorDiff_1L_dte /u32dte_delta ;
                                            TC_Dte_Slow_K = temp; /*unit % factor :1000, 100% =1000*/
                                            temp *= TC_Api_Update_DTE_Damp_Value(DTE_K_SlowUpdate,TC_Ftrip_T.tDTE.DTE_Trip1S);
                                            temp /=1000;
                                        }
                                        else
                                        {
                                            temp = 0;   
                                        }
                                                                           
                                    } 
                                    else
                                    {
                                        temp = 0 ;   
                                    }
                                    
                                    TC_Ftrip_T.tDTE.u32CurrentDTE-=(uint32) temp ;

                                }
                                else 
                                {                               
                                    TC_Ftrip_T.tDTE.u32CurrentDTE-= TC_Api_Update_DTE_Damp_Value(DTE_K_NormalUpdate,TC_Ftrip_T.tDTE.DTE_Trip1S);   
                                }

                            }

                        }

                       
                        if(TC_Dte_Error_Count >= TC_DTE_ERR_DETECTION_TIME) /* 2 min*/
                        {   
                            TC_Dte_Error_Count =0;
                            TC_Ftrip_T.tDTE.u32CurrentDTE =  TC_Ftrip_T.tDTE.u32CalculationDTE;
                            TC_Ftrip_T.tDTE.DTE_Trip1S_k_Mode = DTE_K_Error_Update; 
                        }
                        else
                        {
                            dte_delta_15L = TC_Api_u32_abs(TC_Ftrip_T.tDTE.u32DisplayDTE, TC_Ftrip_T.tDTE.u32CalculationDTE);  
                            if((dte_delta_15L >=TC_Ftrip_T.tDTE.UnNorDiff_15L_dte) && (speed>=TC_DTE_ERR_DETECTION_SPEED))
                            {
                                TC_Dte_Error_Count ++ ;  
                            }
                            else
                            {
                                TC_Dte_Error_Count =0;  
                            }
                            
                        }
                                  
                   }
                   /*the vehicle is idling */
                   else
                   {    
                      TC_Api_DTE_Idle_Update();                   
                   }

                }
            }
        }


            if(TC_Ftrip_T.tDTE.u32CurrentDTE < (uint32)50 * 1000)
            {
                 TC_Ftrip_T.tDTE.u32CurrentDTE = TC_DTE_DISPLAY_LOW_DASHES;      
                 /*  low mode */
                 TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_LOW_MODE;
            }           

            su32CurrDTEDispVal = TC_Ftrip_T.tDTE.u32CurrentDTE; 
                     
                                  
             if((FALSE != TC_API_Get_Fuel_FastFill_State())||(TC_Module_Init_Flag==TRUE))
             {   
                 if(TC_Ftrip_T.tDTE.u32DisplayTimeTick >= TC_Ftrip_T.tTC_Config_NVM.RefreshRateDTEReFuel_NvmInit)//??????
                 {  
                    TC_Module_Init_Flag =FALSE;
                    TC_Ftrip_T.tDTE.u32DisplayTimeTick = 0;
                    TC_Ftrip_T.tDTE.u32DisplayDTE = su32CurrDTEDispVal;   
               //     TC_MODULE_DEBUG_INFO("DTE_D=%d DTE_C=%d DTE_AFE=%d DTE_K=%d ", TC_Ftrip_T.tDTE.u32DisplayDTE,TC_Ftrip_T.tDTE.u32CalculationDTE,sfc,TC_Ftrip_T.tDTE.DTE_Trip1S_k);
               //     TC_MODULE_DEBUG_INFO(" DTE_Trip1S=%d DTE_Idle_EN=%d DTE_1L=%d DTE_Slow_trip=%d", TC_Ftrip_T.tDTE.DTE_Trip1S,TC_Dte_idle_update,TC_Ftrip_T.tDTE.NorDiff_1L_dte,TC_Dte_Slow_K);                   
               
                 }
                 
             }
             else 
             {    
                if (TC_Ftrip_T.tDTE.u32DisplayTimeTick >= TC_Ftrip_T.tTC_Config_NVM.RefreshRateDTE_NvmInit)
                {
                     TC_Ftrip_T.tDTE.u32DisplayTimeTick = 0;
                     TC_Ftrip_T.tDTE.u32DisplayDTE = su32CurrDTEDispVal;   
               //     TC_MODULE_DEBUG_INFO("DTE_D=%d DTE_C=%d DTE_AFE=%d DTE_K=%d ", TC_Ftrip_T.tDTE.u32DisplayDTE,TC_Ftrip_T.tDTE.u32CalculationDTE,sfc,TC_Ftrip_T.tDTE.DTE_Trip1S_k);
               //     TC_MODULE_DEBUG_INFO(" DTE_Trip1S=%d DTE_Idle_EN=%d DTE_1L=%d DTE_Slow_trip=%d", TC_Ftrip_T.tDTE.DTE_Trip1S,TC_Dte_idle_update,TC_Ftrip_T.tDTE.NorDiff_1L_dte,TC_Dte_Slow_K);
                    
               
                }
                       
             }


        
	}
	else
	{   
	    TC_Dte_Delay_Count =0;
        TC_Ftrip_T.tDTE.u32DisplayTimeTick  =0;
		TC_Ftrip_T.tDTE.u32CurrentDTE = TC_Ftrip_T.tDTE.u32DisplayDTE;
	}
}


#endif 


static void TC_Api_Update_DTE(void)
{
	uint32 su32CurrDTEDispVal;
	uint32 u32dte_delta;
	uint32  delta=10*1000;
    boolean ecmErr = FALSE;
    ecmErr = TC_RTE_API_Get_ECM2_err();
	TC_Ftrip_T.tDTE.u32DisplayTimeTick++;

	TC_Ftrip_T.tDTE.u8Refresh_Last_Mode = TC_Ftrip_T.tDTE.u8Refresh_Mode;

    if(0u != TC_Ftrip_T.tDTE.u32RefreshTimeTick)
    {
        TC_Ftrip_T.tDTE.u32RefreshTimeTick--;
    }
    /****************************************
    *when KL15_OFF->KL15_ON  need to be delayed for 500ms,and then to check
    ****************************************/
	if(FALSE != TC_API_Get_Power_Mode_State())
    {
        TC_Dte_Delay_Count++;
        if(TC_Dte_Delay_Count>=TC_DTE_KEYON_DELAY)
        {
            TC_Dte_Delay_Count =TC_DTE_KEYON_DELAY;
        }
    }
    else{
        TC_Dte_Delay_Count =0;
    }

    if((FALSE != TC_API_Get_Power_Mode_State())&&(FALSE != TC_API_Get_Fuel_Finished_Init_State()))
    {

        /* if in fastfill mode, display need update immedately*/
        if((FALSE != TC_API_Get_Fuel_FastFill_State())||(TC_Module_Init_Flag==TRUE))
        {
            /* display --- when 1-ODO error 2-EMC2 missing 3-fuel error*/
            //if((FALSE == TC_Api_DTE_Accum_Enable()) || (FALSE != TC_API_Get_Fuel_Error_State())	)
            //if((FALSE == TC_Api_DTE_Accum_Enable()))

            if(((TC_Dte_Delay_Count ==TC_DTE_KEYON_DELAY) && ((TRUE ==TC_RTE_API_Get_ODO_err())||(TRUE == ecmErr)))||(FALSE != TC_RTE_API_Get_Fuel_Error_State()))
            {
                TC_Ftrip_T.tDTE.u32CurrentDTE = TC_DTE_DISPLAY_DASHES;

                /*  --- mode  */
                TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_ERROR_MODE;
            }
            else
            {
                /* if just exit from eeror mode,  u32dte_delta =  0xffffffff - u32CalculationDTE */
                /* u32dte_delta is to max. so display u32CalculationDTE value					 */
                if(TC_DTE_DISPLAY_DASHES == TC_Ftrip_T.tDTE.u32CurrentDTE)
                {
                    u32dte_delta = 0;
                    TC_Ftrip_T.tDTE.u32CurrentDTE = TC_Ftrip_T.tDTE.u32CalculationDTE;

                    /*  refsh display mode  */
                    TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_UPDATE_IMMED_MODE;
                }
                else if(TC_DTE_DISPLAY_LOW_DASHES == TC_Ftrip_T.tDTE.u32CurrentDTE)
                {
                    u32dte_delta = TC_Api_u32_abs(TC_Ftrip_T.tDTE.u32CalculationDTE, (50 *1000UL));
                }
                else
                {
                    //u32dte_delta = TC_Ftrip_T.tDTE.u32DisplayDTE - TC_Ftrip_T.tDTE.u32CalculationDTE;
                    u32dte_delta=  TC_Api_u32_abs(TC_Ftrip_T.tDTE.u32DisplayDTE, TC_Ftrip_T.tDTE.u32CalculationDTE);                
                }  
                
                if(0uL != TC_Pkg_Get_DTE_Fuel_Stage_Consumption_Value(0))
                {
                    delta = (uint32)(((uint64)299UL *100u * 10u * 1000UL)/TC_Pkg_Get_DTE_Fuel_Stage_Consumption_Value(0));
                    delta /= 2u;
                }    
                //if((u32dte_delta < (sint32)10 * 1000) && (u32dte_delta > (sint32)(-10) * 1000))
                if((uint32)u32dte_delta < delta)
                {
                    /* keep last value mode*/
                }
                else
                {   
                    /* if u32CalculationDTE is less than 50km, display need invaild */
                    if(TC_Ftrip_T.tDTE.u32CalculationDTE < (uint32)(50u * 1000UL))
                    {
                        TC_Ftrip_T.tDTE.u32CurrentDTE = TC_DTE_DISPLAY_LOW_DASHES;
                        
                        /*	low mode */
                        TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_LOW_MODE;
                    }  
                    else
                    {
                        TC_Ftrip_T.tDTE.u32CurrentDTE = TC_Ftrip_T.tDTE.u32CalculationDTE;

                        /*  refsh display mode  */
                        TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_UPDATE_IMMED_MODE;
                        TC_Ftrip_T.tDTE.u32RefreshTimeTick=TC_Ftrip_T.tTC_Config_NVM.RefreshRateDTEReFuel_NvmInit;

                        //TC_Ftrip_T.tDTE.u32DisplayTimeTick = TC_Ftrip_T.tDTE.u32RefreshTimeTick;
                    }  
                }
            }
            #if 0
/**FIX***less than 50km  ALSO display********************************************************************/
           if(TC_Ftrip_T.tDTE.u32CalculationDTE < (uint32)50 * 1000)
			{
				TC_Ftrip_T.tDTE.u32CurrentDTE = TC_DTE_DISPLAY_LOW_DASHES;
				
				/*	low mode */
				TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_LOW_MODE;
			}	
/*************************************************************************/


			su32CurrDTEDispVal = TC_Ftrip_T.tDTE.u32CurrentDTE;	

			if((TC_Ftrip_T.tDTE.u32DisplayDTE == TC_DTE_DISPLAY_DASHES) || (TC_Ftrip_T.tDTE.u32DisplayDTE == TC_DTE_DISPLAY_LOW_DASHES))
			{
				/* if exit error mode, need display immedately*/
				TC_Ftrip_T.tDTE.u32DisplayTimeTick = TC_Ftrip_T.tTC_Config_NVM.RefreshRateDTEReFuel_NvmInit;
			}
			
			/* display per 1s */
			if(TC_Ftrip_T.tDTE.u32DisplayTimeTick >= TC_Ftrip_T.tTC_Config_NVM.RefreshRateDTEReFuel_NvmInit)
		  	{
				TC_Ftrip_T.tDTE.u32DisplayTimeTick = 0;
				TC_Ftrip_T.tDTE.u32DisplayDTE = su32CurrDTEDispVal;
			}			
           #endif 

        }
        else
        {
            /* display --- when 1-ODO error 2-EMC2 missing 3-fuel error*/
            //if((FALSE == TC_Api_DTE_Accum_Enable()) || (FALSE != TC_API_Get_Fuel_Error_State())	)
            //	if((FALSE == TC_Api_DTE_Accum_Enable()))
            /*fix bug :when speed stop ,will display dash --- */

            if(((TC_Dte_Delay_Count ==TC_DTE_KEYON_DELAY) &&((TRUE ==TC_RTE_API_Get_ODO_err())||(TRUE == ecmErr)))||(FALSE != TC_RTE_API_Get_Fuel_Error_State()))
            {
                TC_Ftrip_T.tDTE.u32CurrentDTE = TC_DTE_DISPLAY_DASHES;

                /*  --- mode  */
                TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_ERROR_MODE;
            }
            else
            {  
                
                if(TC_DTE_DISPLAY_DASHES == TC_Ftrip_T.tDTE.u32CurrentDTE)
                {
                    TC_Ftrip_T.tDTE.u32CurrentDTE = TC_Ftrip_T.tDTE.u32CalculationDTE;
                    //	TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_UPDATE_IMMED_MODE;
                    //	TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_LOW_MODE;
                }
                else if(DTE_REFRESH_LOW_MODE == TC_Ftrip_T.tDTE.u8Refresh_Mode)
                {
                    TC_Ftrip_T.tDTE.u32CurrentDTE = TC_DTE_DISPLAY_LOW_DASHES;
                    /*  low mode */
                    TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_LOW_MODE;
                }
                //else if(FALSE == TC_API_Get_EngSpd_State())
                else if (FALSE ==TC_Api_DTE_cal_Enable()) /*add it for hev vehicle*/
                {
                    /* keep last display value*/
                    TC_Ftrip_T.tDTE.u32CurrentDTE = TC_Ftrip_T.tDTE.u32DisplayDTE;

                    /*  keep last mode  */
                    TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_KEEP_MODE;				
                }
                else
                {
                    /* if just exit from eeror mode,  u32dte_delta =  0xffffffff - u32CalculationDTE */
                    /* u32dte_delta is to max. so display u32CalculationDTE value					 */
                    if(TC_DTE_DISPLAY_DASHES == TC_Ftrip_T.tDTE.u32CurrentDTE)
                    {
                        u32dte_delta = 0;
                        TC_Ftrip_T.tDTE.u32CurrentDTE = TC_Ftrip_T.tDTE.u32CalculationDTE;
                    }
                    else
                    {
                        u32dte_delta = TC_Api_u32_abs(TC_Ftrip_T.tDTE.u32DisplayDTE, TC_Ftrip_T.tDTE.u32CalculationDTE);
                    }

                    if(TC_Ftrip_T.tDTE.u32DisplayDTE >= TC_Ftrip_T.tDTE.u32CalculationDTE)
                    {
                        if(FALSE != TC_API_Get_VehRunning_State())
                        {
                            /* >= 10km need refresh */
                            if(u32dte_delta > ((uint32)TC_Ftrip_T.tTC_Config_NVM.RangeDecThreshold_NvmInit * 1000UL))
                            {
                                /*  10s display mode  */
                                TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_UPDATE_10S_MODE;
                            }
                            /* >= 1km need refresh */
                            else if(u32dte_delta >= (uint32)0)
                            {
                                /*  30s display mode  */
                                TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_UPDATE_30S_MODE;
                            }
                            /* < 1km keep last value */
                            else
                            {
                                /* keep last display value*/
                                //TC_Ftrip_T.tDTE.u32CurrentDTE = TC_Ftrip_T.tDTE.u32CalculationDTE;

                                /*  keep last mode  */
                                TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_KEEP_MODE;
                            }
                        }
                        else
                        {
                            /* >= 1km need refresh */
                            if(u32dte_delta > 0u)
                            {
                                /*  100s display mode  */
                                TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_UPDATE_100S_MODE;
                            }
                            else
                            {
                                /* keep last display value*/
                                //TC_Ftrip_T.tDTE.u32CurrentDTE = TC_Ftrip_T.tDTE.u32CalculationDTE;

                                /*  keep last mode  */
                                TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_KEEP_MODE;
                            }
                        }
                    }
                    else
                    {
                        //u32dte_delta = -u32dte_delta;

                        /* > 20km */
                        if(u32dte_delta > ((uint32)TC_Ftrip_T.tTC_Config_NVM.RangeIncThreshold_NvmInit * 1000))
                        {  
                            if(TC_Ftrip_T.tDTE.u32DisplayDTE >= (uint32)(50u * 1000UL))
                            {
                                TC_Ftrip_T.tDTE.u32CurrentDTE = TC_Ftrip_T.tDTE.u32CalculationDTE;	

                                /*  refsh display mode  */
                                TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_UPDATE_IMMED_MODE;
                            }
                            else
                            {
                                TC_Ftrip_T.tDTE.u32CurrentDTE = TC_DTE_DISPLAY_LOW_DASHES;
                                /*  --- mode */
                                TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_LOW_MODE;
                            }
                        }
                        else
                        {
                            if(FALSE != TC_API_Get_VehRunning_State())
                            {
                                /*  400s display mode  */
                                TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_UPDATE_400S_MODE;
                            }
                            else
                            {
                                /* keep last display value*/
                                TC_Ftrip_T.tDTE.u32CurrentDTE = TC_Ftrip_T.tDTE.u32DisplayDTE;

                                /*  keep last mode  */
                                TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_KEEP_MODE;
                            }
                        }  
                    }
                }
            }

            if(TC_Ftrip_T.tDTE.u8Refresh_Last_Mode != TC_Ftrip_T.tDTE.u8Refresh_Mode)
			{
				if(TC_Ftrip_T.tDTE.u8Refresh_Mode <= DTE_REFRESH_UPDATE_IMMED_MODE)
				{
				    //TC_Ftrip_T.tDTE.u32RefreshTimeTick = 0;	
					TC_Ftrip_T.tDTE.u32RefreshTimeTick=TC_Ftrip_T.tTC_Config_NVM.RefreshRateDTEReFuel_NvmInit;
				}
				else
				{
					if(DTE_REFRESH_UPDATE_10S_MODE == TC_Ftrip_T.tDTE.u8Refresh_Mode)
					{
						/* per 10s reduce 1km */
						TC_Ftrip_T.tDTE.u32RefreshTimeTick = TC_Ftrip_T.tTC_Config_NVM.FastUpdateTime_NvmInit * 10;
					}
					else if(DTE_REFRESH_UPDATE_30S_MODE == TC_Ftrip_T.tDTE.u8Refresh_Mode)
					{				
						/* per 30s reduce 1km */
						TC_Ftrip_T.tDTE.u32RefreshTimeTick = TC_Ftrip_T.tTC_Config_NVM.SlowUpdateTime_NvmInit * 10;
					}
					else if(DTE_REFRESH_UPDATE_100S_MODE == TC_Ftrip_T.tDTE.u8Refresh_Mode)
					{
						/* per 100s reduce 1km */
						TC_Ftrip_T.tDTE.u32RefreshTimeTick = TC_Ftrip_T.tTC_Config_NVM.IdleUpdateTime_NvmInit * 10;
					}
					else if(DTE_REFRESH_UPDATE_400S_MODE == TC_Ftrip_T.tDTE.u8Refresh_Mode)
					{
						/* per 400s reduce 1km */
						TC_Ftrip_T.tDTE.u32RefreshTimeTick = TC_Ftrip_T.tTC_Config_NVM.UnNormalUpdateTime_NvmInit * 10;
					}
				}
			}
			else
			{
				/* keep last refresh mode*/
			}

			if(0 == TC_Ftrip_T.tDTE.u32RefreshTimeTick)
			{		
				if(TC_Ftrip_T.tDTE.u8Refresh_Mode > DTE_REFRESH_UPDATE_IMMED_MODE)
				{
					TC_Ftrip_T.tDTE.u32CurrentDTE = TC_Ftrip_T.tDTE.u32CurrentDTE - 1000UL;
					su32CurrDTEDispVal = TC_Ftrip_T.tDTE.u32CurrentDTE;	

					if(DTE_REFRESH_UPDATE_10S_MODE == TC_Ftrip_T.tDTE.u8Refresh_Mode)
					{
						/* per 10s reduce 1km */
						TC_Ftrip_T.tDTE.u32RefreshTimeTick = TC_Ftrip_T.tTC_Config_NVM.FastUpdateTime_NvmInit * 10;
					}
					else if(DTE_REFRESH_UPDATE_30S_MODE == TC_Ftrip_T.tDTE.u8Refresh_Mode)
					{				
						/* per 30s reduce 1km */
						TC_Ftrip_T.tDTE.u32RefreshTimeTick = TC_Ftrip_T.tTC_Config_NVM.SlowUpdateTime_NvmInit * 10;
					}
					else if(DTE_REFRESH_UPDATE_100S_MODE == TC_Ftrip_T.tDTE.u8Refresh_Mode)
					{
						/* per 100s reduce 1km */
						TC_Ftrip_T.tDTE.u32RefreshTimeTick = TC_Ftrip_T.tTC_Config_NVM.IdleUpdateTime_NvmInit * 10;
					}
					else if(DTE_REFRESH_UPDATE_400S_MODE == TC_Ftrip_T.tDTE.u8Refresh_Mode)
					{
						/* per 400s reduce 1km */
						TC_Ftrip_T.tDTE.u32RefreshTimeTick = TC_Ftrip_T.tTC_Config_NVM.UnNormalUpdateTime_NvmInit * 10;
					}
				}		
			}
           #if 0
			if(TC_Ftrip_T.tDTE.u32CurrentDTE < (uint32)50 * 1000)
			{
				TC_Ftrip_T.tDTE.u32CurrentDTE = TC_DTE_DISPLAY_LOW_DASHES;
				
				/*  low mode */
				TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_LOW_MODE;
			}			

			su32CurrDTEDispVal = TC_Ftrip_T.tDTE.u32CurrentDTE;	
			
			if((su32CurrDTEDispVal == TC_DTE_DISPLAY_DASHES) || (TC_Ftrip_T.tDTE.u32DisplayDTE == TC_DTE_DISPLAY_DASHES))
			{
				TC_Ftrip_T.tDTE.u32DisplayTimeTick = TC_Ftrip_T.tTC_Config_NVM.RefreshRateDTE_NvmInit;
			}
			
			/* display per 10s */
			if(TC_Ftrip_T.tDTE.u32DisplayTimeTick >= TC_Ftrip_T.tTC_Config_NVM.RefreshRateDTE_NvmInit)
		  	{
				TC_Ftrip_T.tDTE.u32DisplayTimeTick = 0;
				TC_Ftrip_T.tDTE.u32DisplayDTE = su32CurrDTEDispVal;
			}
			#endif 
	
		}

        if(TC_Ftrip_T.tDTE.u32CurrentDTE < (uint32)(50u * 1000UL))
        {
            TC_Ftrip_T.tDTE.u32CurrentDTE = TC_DTE_DISPLAY_LOW_DASHES;		
            /*	low mode */
            TC_Ftrip_T.tDTE.u8Refresh_Mode = DTE_REFRESH_LOW_MODE;
        }			

        su32CurrDTEDispVal = TC_Ftrip_T.tDTE.u32CurrentDTE; 

        if((su32CurrDTEDispVal == TC_DTE_DISPLAY_DASHES) || \
            (TC_Ftrip_T.tDTE.u32DisplayDTE ==TC_DTE_DISPLAY_DASHES)||\
            ((su32CurrDTEDispVal == TC_DTE_DISPLAY_LOW_DASHES)))
        {

            if(FALSE != TC_API_Get_Fuel_FastFill_State())
            {
                TC_Ftrip_T.tDTE.u32DisplayTimeTick = TC_Ftrip_T.tTC_Config_NVM.RefreshRateDTEReFuel_NvmInit;
            }
            else
            {
                TC_Ftrip_T.tDTE.u32DisplayTimeTick = TC_Ftrip_T.tDTE.u32RefreshTimeTick ;
            }
            //   su32CurrDTEDispVal = TC_DTE_DISPLAY_DASHES;
            /*Avoidance recovery from the error state can also display data below 50km */
        }

        /* display per 10s */
        if((FALSE != TC_API_Get_Fuel_FastFill_State())||(TC_Module_Init_Flag==TRUE))
        {  
            TC_Module_Init_Flag =FALSE;
            if(TC_Ftrip_T.tDTE.u32DisplayTimeTick >= TC_Ftrip_T.tTC_Config_NVM.RefreshRateDTEReFuel_NvmInit)//??????
            {
                TC_Ftrip_T.tDTE.u32DisplayTimeTick = 0;
                TC_Ftrip_T.tDTE.u32DisplayDTE = su32CurrDTEDispVal;
                TC_SETBIT(TC_Ftrip_T.Tc_Ipc_Update,(uint8)TC_IPC_NOTIFICATION_DTE_BIT);
            }
	    }
		else
		{			
			TC_Ftrip_T.tDTE.u32DisplayDTE = su32CurrDTEDispVal;			
		}
				

		
	}
	else
	{
		TC_Ftrip_T.tDTE.u32CurrentDTE = TC_Ftrip_T.tDTE.u32DisplayDTE;
	}
       #if 0
        err=TC_API_Get_Fuel_FastFill_State();
    	TC_MODULE_DEBUG1("u32CurrentDTE:%d  u32DisplayDTE:%d  u8Refresh_Mode:%d Fuel_FastFill:%d",
			TC_Ftrip_T.tDTE.u32CurrentDTE,
			TC_Ftrip_T.tDTE.u32DisplayDTE,
			TC_Ftrip_T.tDTE.u8Refresh_Mode,
			err);
       #endif  
}
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
uint16 TC_Api_Get_Fuel_Tank_Size(void)
{
#if 0

  uint8	fl_Tank_Size_U8;

  uint16 fl_Tank_Size_Status_U16 ;

  fl_Tank_Size_U8 = fcfg_get_FuelTank_Size();

   if(fl_Tank_Size_U8 == FUEL_TYPE_DIESEL)
  {
    if ((NVM_DIESEL_FUEL_VOL_U8 >= TC_MIN_VALID_RANGE) && (NVM_DIESEL_FUEL_VOL_U8 <= TC_MAX_VALID_RANGE))
    {
      /* Diesel Volume tank is 37 L  */
      fl_Tank_Size_Status_U16= NVM_DIESEL_FUEL_VOL_U8 ;
    }
    else
    {
      fl_Tank_Size_Status_U16= TC_DIESEL_FUEL_VOL;
    }
   }
  else
  {
    if ((NVM_PETROL_FUEL_VOL_U8 >= TC_MIN_VALID_RANGE) && (NVM_PETROL_FUEL_VOL_U8 <= TC_MAX_VALID_RANGE))
    {/* Petrol Volume tank is 39 L  */
      fl_Tank_Size_Status_U16= NVM_PETROL_FUEL_VOL_U8 ;
    }
    else
    {
      fl_Tank_Size_Status_U16= TC_PETROL_FUEL_VOL ;
    }
  }

  fl_Tank_Size_Status_U16= (fl_Tank_Size_Status_U16 * TC_FUEL_INPUT_PER_100_FACTOR);


  return(fl_Tank_Size_Status_U16);
      #endif
	  return(0);
}
/**********************************************************************************************************
*Function   : TC_Api_Computer_Uint_IFE                                                                 	  *
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
static void TC_Api_Computer_Uint_IFE(void)
{
	TC_IFE_STRUCT *pt;
	
	pt = &TC_Ftrip_T.tIFE;

	if(0u != TC_API_Get_VehRunning_State_For_Ifc())
	{
		pt->u8CalcUnit = L_PER_100KM;
	}
	else
	{
		pt->u8CalcUnit = L_PER_HOUR;
	}	
}

/**********************************************************************************************************
*Function   : TC_Api_Computer_Low_Threshold_IFE                                                       	  *
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
static void TC_Api_Computer_Low_Threshold_IFE(void)
{
	uint32 fl_Temp_IFE_U32;
	
	fl_Temp_IFE_U32 = TC_Pkg_Output_IFE_LPH();

	/* delete by fchao in 20201117 for redunce rate
	if(fl_Temp_IFE_U32 > TC_MAX_IFE_LPHKM)
	{
		fl_Temp_IFE_U32 = TC_MAX_IFE_LPHKM;
	}
	*/
	TC_Ftrip_T.tIFE.u32CalculationIFE = fl_Temp_IFE_U32;	
}
/**********************************************************************************************************
*Function   : TC_Api_Computer_High_Threshold_IFE                                                     	  *
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
static void TC_Api_Computer_High_Threshold_IFE (void)
{
    uint32 fl_Temp_IFE_U32 = TC_IFE_FILTER_SIZE;
	fl_Temp_IFE_U32 = TC_Pkg_Output_IFE(); //// l/100km

	/* delete by fchao in 20201117 for redunce rate
	if(fl_Temp_IFE_U32 > TC_MAX_IFE_LPHKM)
	{
		fl_Temp_IFE_U32 = TC_MAX_IFE_LPHKM;
	}
	*/
	TC_Ftrip_T.tIFE.u32CalculationIFE = fl_Temp_IFE_U32;	
}
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
void TC_Api_Accum_Collect_Task(void)
{
    CanFrameCounterType input=TC_RTE_API_GetSpeedMsgValue();
	if(FALSE == TC_RTE_API_Get_Power_Mode_State_Is_Sleep())
	{
		#ifdef TC_TIME_CAL	
		//  TC_TASK_BEGIN_CALCULATE(TC_task_input);
		tc_RteAdaptRunableOstmStart(TC_task_input);
		#endif 
		
		if(FALSE != TC_API_Get_Power_Mode_State())
		{
			TC_Api_Accum_Odo_Count();
	    	TC_Api_Accum_Fuel_Count();
			TC_Api_Accum_Time_Count();
            TC_Api_Accum_EgyUsed_Count(); /*  */
		}
		else
		{
			TC_Prev_Fuel_Consume_Count=TC_RTE_Get_FuelConsMsgValue().u16_fuel_consume_rc;
			TC_RCan_Get_Fuel_Samples_Times_Old =TC_RTE_Get_FuelConsMsgValue().u32_fuel_consume_value;
            if(0xFFFF!=input.Data)
            {
			    TC_Prev_Odo_rcCount = input.Counter;
            }
		}
		#ifdef TC_TIME_CAL	
		// TC_TASK_END_CALCULATE(TC_task_input);
		tc_RteAdaptRunableOstmCheck(TC_task_input);
		#endif 
	}
}
/**********************************************************************************************************
*Function   : TC_ipc_m2s_upadte                                                                  	  *
*                                                                                                         *
*Description: send tc data from vip to soc 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: shujunhua                                                                                    *
*                                                                                                         *
*Date		: 2020-09-16                                                                                 *
**********************************************************************************************************/
void TC_ipc_m2s_upadte(void)
{
    //TC_XFE_UNIT_ENUM ife_unit_temp = TC_Api_Get_IFE_Uint_For_Hmi();
    TC_XFE_UNIT_ENUM IFE_Uint_For_Hm = (TC_XFE_UNIT_ENUM)TC_Api_Get_IFE_Uint_For_Hmi();
	IPC_M2S_ClusterAppAPPTripComputer_t tc_ipc;
	if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
	{
		tc_ipc.AVS[0] = TC_Api_Get_AVS_Value_For_Hmi(0,0);
		tc_ipc.AVS[1] = TC_Api_Get_AVS_Value_For_Hmi(1,0);
		tc_ipc.DTE = TC_Api_Get_DTE_Value_For_Hmi(0);
        tc_ipc.Phev_Dte_Ipc =TC_Api_Get_DTE_Phev_Value_For_Hmi(0);
		/* 0: DTE-KM AVS:KM/H */
		tc_ipc.DTE_AVS_Uint = 0;
	}
	else
	{
		tc_ipc.AVS[0] = TC_Api_Get_AVS_Value_For_Hmi(0,1);
		tc_ipc.AVS[1] = TC_Api_Get_AVS_Value_For_Hmi(1,1);
		tc_ipc.DTE = TC_Api_Get_DTE_Value_For_Hmi(1);
        tc_ipc.Phev_Dte_Ipc =TC_Api_Get_DTE_Phev_Value_For_Hmi(1);
		/* 1:DTE-MILES AVS:MPH */
		tc_ipc.DTE_AVS_Uint = 1;
	}

	if(TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg())
	{
		tc_ipc.AFE[0] = TC_Api_Get_AFE_Value_For_Hmi(0,L_PER_100KM,100);
		tc_ipc.AFE[1] = TC_Api_Get_AFE_Value_For_Hmi(1,L_PER_100KM,100);
		tc_ipc.IFE = TC_Api_Get_IFE_Value_For_Hmi(IFE_Uint_For_Hm,100);
		tc_ipc.IFE_Unit = TC_Api_Get_IFE_Uint_For_Hmi();
		/*0:L/100KM, 1:L/H, 2:KM/L, 3:GPH, 4:MPG*/
	
		/*0:L/100KM, 1:KM/L, 2:MPG*/
		tc_ipc.AFE_Uint = 0;
	}
	else if(TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg())
	{
		tc_ipc.AFE[0] = TC_Api_Get_AFE_Value_For_Hmi(0,KM_PER_L,100);
		tc_ipc.AFE[1] = TC_Api_Get_AFE_Value_For_Hmi(1,KM_PER_L,100);
		if(L_PER_100KM == TC_Api_Get_IFE_Uint_For_Hmi())
		{
			tc_ipc.IFE = TC_Api_Get_IFE_Value_For_Hmi(KM_PER_L,100);
			/*0:L/100KM, 1:L/H, 2:KM/L, 3:GPH, 4:MPG*/
			tc_ipc.IFE_Unit = 2;
		}
		else
		{
			tc_ipc.IFE = TC_Api_Get_IFE_Value_For_Hmi(L_PER_HOUR,100);
			/*0:L/100KM, 1:L/H, 2:KM/L, 3:GPH, 4:MPG*/
			tc_ipc.IFE_Unit = 1;
		}
		/*0:L/100KM, 1:KM/L, 2:MPG*/
		tc_ipc.AFE_Uint = 1;
	}
	else if(TC_UINT_KM_UK == TC_Rte_Api_Get_Uint_Cfg())
	{
		tc_ipc.AFE[0]=TC_Api_Get_AFE_Value_For_Hmi(0,UK_MPG,100);
		tc_ipc.AFE[1]=TC_Api_Get_AFE_Value_For_Hmi(1,UK_MPG,100);
		if(L_PER_100KM == TC_Api_Get_IFE_Uint_For_Hmi())
		{
			tc_ipc.IFE = TC_Api_Get_IFE_Value_For_Hmi(UK_MPG,100);
			/*0:L/100KM, 1:L/H, 2:KM/L, 3:GPH, 4:MPG*/
			tc_ipc.IFE_Unit = 4;
		}
		else
		{
			tc_ipc.IFE = TC_Api_Get_IFE_Value_For_Hmi(UK_GPH,100);
			/*0:L/100KM, 1:L/H, 2:KM/L, 3:GPH, 4:MPG*/
			tc_ipc.IFE_Unit = 3;
		}
		/*0:L/100KM, 1:KM/L, 2:MPG*/
		tc_ipc.AFE_Uint = 2;
	}
	else if(TC_UINT_KM_US == TC_Rte_Api_Get_Uint_Cfg())
	{
		tc_ipc.AFE[0]=TC_Api_Get_AFE_Value_For_Hmi(0,US_MPG,100);
		tc_ipc.AFE[1]=TC_Api_Get_AFE_Value_For_Hmi(1,US_MPG,100);
		if(L_PER_100KM == TC_Api_Get_IFE_Uint_For_Hmi())
		{
			tc_ipc.IFE = TC_Api_Get_IFE_Value_For_Hmi(US_MPG,100);
			/*0:L/100KM, 1:L/H, 2:KM/L, 3:GPH, 4:MPG*/
			tc_ipc.IFE_Unit = 4;
		}
		else
		{
			tc_ipc.IFE = TC_Api_Get_IFE_Value_For_Hmi(US_GPH,100);
			/*0:L/100KM, 1:L/H, 2:KM/L, 3:GPH, 4:MPG*/
			tc_ipc.IFE_Unit = 3;
		}
		/*0:L/100KM, 1:KM/L, 2:MPG*/
		tc_ipc.AFE_Uint = 2;
	}
	else
	{
		/* do nothing */
	}

	tc_ipc.Travel_time_Hour[0] = TC_Ftrip_T.tTravel_Time.u8TravelTime_Hour[0];
	tc_ipc.Travel_time_Hour[1] = TC_Ftrip_T.tTravel_Time.u8TravelTime_Hour[1];
	tc_ipc.Travel_time_MIN[0] = TC_Ftrip_T.tTravel_Time.u8TravelTime_Minute[0];
	tc_ipc.Travel_time_MIN[1] = TC_Ftrip_T.tTravel_Time.u8TravelTime_Minute[1];
	tc_ipc.Trip[1] = TC_Ftrip_T.ttrip[1]; /*@20200923 Add subtotal mileage data to IPC*/
	tc_ipc.Trip[0] = TC_Ftrip_T.ttrip[0];

	(void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_TRIP_COMPUTER,(uint8 *)&tc_ipc,(uint16)sizeof(IPC_M2S_ClusterAppAPPTripComputer_t),FALSE);
}

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

void TC_Api_Update_Calc_Task(void)
{    
   uint16 Ife_can_temp=0;
//   TC_XFE_UNIT_ENUM ife_unit_temp= TC_Api_Get_IFE_Uint_For_Hmi();
   TC_XFE_UNIT_ENUM Get_IFE_Uint = (TC_XFE_UNIT_ENUM)TC_Api_Get_IFE_Uint_For_Hmi();
	if(FALSE == TC_RTE_API_Get_Power_Mode_State_Is_Sleep())
	{
		#ifdef TC_TIME_CAL
		TC_Task_em_buffer[0].min_exec_time=0XFFFF;
		// TC_TASK_BEGIN_CALCULATE(TC_task_uptae);
		tc_RteAdaptRunableOstmStart(TC_task_uptae);
		#endif
		  
			TC_Api_Update_AVS();
			TC_Api_Update_AFE();
			TC_Api_Update_IFE();
            #ifdef TC_DTE_NEW_STRATEGY_0413
            TC_Api_Update_DTE_New();
            #else 
			TC_Api_Update_DTE();
            #endif 
			TC_Api_Travel_Time_Process_Task();
			TC_Api_Update_trip();
            TC_Api_Update_Phev_Dte(); /*add it for Project(B0/02/B06) Vehicle type PHEV*/
         
       #if 1         
			TC_App_Update_Emergy();
       #endif 
			TC_ipc_m2s_upadte();
  
			

			/* AFE */
			TC_Module_Output_Data_Value.u16AFE_1st_Display_Output_Data = TC_Api_Get_AFE_Value_For_Hmi(0,L_PER_100KM,100);
			TC_Module_Output_Data_Value.u16AFE_2st_Display_Output_Data = TC_Api_Get_AFE_Value_For_Hmi(1,L_PER_100KM,100);
			TC_Module_Output_Data_Value.u32AFE_1st_Fuel_Trip_Value = (uint32)(TC_Pkg_Get_AFE_Fuel_Trip_Value(0)/1000);
			TC_Module_Output_Data_Value.u32AFE_1st_Fuel_Consumption_Value = (uint32)(TC_Pkg_Get_AFE_Fuel_Consumption_Value(0)/1000);
			TC_Module_Output_Data_Value.u32AFE_2st_Fuel_Trip_Value = (uint32)(TC_Pkg_Get_AFE_Fuel_Trip_Value(1)/1000);
			TC_Module_Output_Data_Value.u32AFE_2st_Fuel_Consumption_Value = (uint32)(TC_Pkg_Get_AFE_Fuel_Consumption_Value(0)/1000);
			/* IFE */
			TC_Module_Output_Data_Value.u16IFE_Calculate_Output_Data = (uint16)(TC_Pkg_Output_Round_Up(TC_Ftrip_T.tIFE.u32CurrentIFE, 100));
			TC_Module_Output_Data_Value.u16IFE_Display_Output_Data = TC_Api_Get_IFE_Value_For_Hmi(Get_IFE_Uint,100);
			TC_Module_Output_Data_Value.u32IFE_Fuel_Trip_Value = TC_Pkg_Get_IFE_Fuel_Trip_Value(0);
			TC_Module_Output_Data_Value.u32IFE_Fuel_Consumption_Value = TC_Pkg_Get_IFE_Fuel_Consumption_Value(0);
			TC_Module_Output_Data_Value.u32IFE_Fuel_Consumption_Can_Signal = 0;
			/* AVS */
			TC_Module_Output_Data_Value.u16AVS_1st_Display_Output_Data = TC_Api_Get_AVS_Value_For_Hmi(0,0);
			TC_Module_Output_Data_Value.u16AVS_2st_Display_Output_Data = TC_Api_Get_AVS_Value_For_Hmi(1,0);
			TC_Module_Output_Data_Value.u32AVS_1st_Driving_Time_Value = TC_Pkg_Get_AVS_Driving_Time_Value(0);
			TC_Module_Output_Data_Value.u32AVS_2st_Driving_Time_Value = TC_Pkg_Get_AVS_Driving_Time_Value(1);
			TC_Module_Output_Data_Value.u32AVS_1st_Fuel_Trip_Value = TC_Pkg_Get_AVS_Fuel_Trip_Value(0); /*fix index*/
			TC_Module_Output_Data_Value.u32AVS_2st_Fuel_Trip_Value = TC_Pkg_Get_AVS_Fuel_Trip_Value(1);
			/* Driver Time */
			TC_Module_Output_Data_Value.u8DrivingTime_1st_Display_Hour = TC_Ftrip_T.tTravel_Time.u8TravelTime_Hour[0];
			TC_Module_Output_Data_Value.u8DrivingTime_2st_Display_Hour = TC_Ftrip_T.tTravel_Time.u8TravelTime_Hour[1];
			TC_Module_Output_Data_Value.u8DrivingTime_1st_Display_Minute = TC_Ftrip_T.tTravel_Time.u8TravelTime_Minute[0];
			TC_Module_Output_Data_Value.u8DrivingTime_2st_Display_Minute = TC_Ftrip_T.tTravel_Time.u8TravelTime_Minute[1];
			/* DTE */
			TC_Module_Output_Data_Value.u8DTE_Fuel_Stage_Consumption = (uint16)(TC_Pkg_Get_DTE_Fuel_Stage_Consumption_Value(0)/100);
			TC_Module_Output_Data_Value.u16DTE_Display_Output_Data = TC_Api_Get_DTE_Value_For_Hmi(0);
			TC_Module_Output_Data_Value.u16DTE_Calculate_Output_Data = (uint16)(TC_Ftrip_T.tDTE.u32CalculationDTE/1000);
			TC_Module_Output_Data_Value.u16SFC_Output_Data = (uint16)TC_Ftrip_T.tDTE.u8Refresh_Mode ;/* add dte update mode*/
			TC_Module_Output_Data_Value.u16SFC_For_Fuel_Output_Data = 299;	
			TC_Module_Output_Data_Value.u16DTE_Fuel_Tank_Volume =(uint16)TC_FUEL_LEVEL_IN_LITERS; /*Repair the amount of fuel calculated using the actual fuel pack */	
			/* POC IFC */
			TC_Module_Output_Data_Value.u8IFC_Poc_Update = 10;	
			TC_Module_Output_Data_Value.u16IFC_Poc_Calculate_Value = 299;
			TC_Module_Output_Data_Value.u16IFC_Poc_For_Fuel_Calculate_Rate = TC_Ftrip_T.tIFC_10S; /*add fuel calc rate */
			
			TC_API_Set_Module_Data(TC_Module_Output_Data_Value);

			TC_MODULE_DEBUG("FueConSum_AFC : %d  Calculated_AFC: %d  Trip_AFC: %d",
			TC_Module_Output_Data_Value.u32AFE_1st_Fuel_Consumption_Value,
			TC_Module_Output_Data_Value.u16AFE_1st_Display_Output_Data,
			TC_Module_Output_Data_Value.u32AFE_1st_Fuel_Trip_Value);

			TC_MODULE_DEBUG("DTE_Calculated : %d  DTE_Displayed: %d",
			TC_Module_Output_Data_Value.u16DTE_Calculate_Output_Data,
			TC_Module_Output_Data_Value.u16DTE_Display_Output_Data);

			TC_MODULE_DEBUG("Calculated_AVS : %d  Trip_AVS: %d  DrivingTime_AVS: %d",
			TC_Module_Output_Data_Value.u16AVS_1st_Display_Output_Data,
			TC_Module_Output_Data_Value.u32AVS_1st_Fuel_Trip_Value,
			TC_Module_Output_Data_Value.u32AVS_1st_Driving_Time_Value);

			TC_MODULE_DEBUG("SFC_Calcualted : %d  FuelConSum_SFC: %d  FuelConSum_SFC: %d",
			TC_Module_Output_Data_Value.u8DTE_Fuel_Stage_Consumption,
			0,
			0);

			TC_MODULE_DEBUG("Trip_Auto : %d  Trip_Manual : %d  Warning_ID : %d",
			0,
			0,
			0);
	if(FALSE != TC_API_Get_Power_Mode_State())
		{
		//	 TC_Api_Update_can_publish(TC_IP_AvgFuelCons_A,TC_Api_Get_AFE_Value_For_Hmi(0,(TC_XFE_UNIT_ENUM)0,10));
		if(TC_AFE_AFTER_RESET_HMI_DASHES ==TC_Api_Get_AFE_Value_For_Hmi(0,L_PER_100KM,100))
        {
            TC_Api_Update_can_publish(TC_IP_AvgFuelCons_A,0xfff); 

        }
        else
        {   
            TC_Api_Update_can_publish(TC_IP_AvgFuelCons_A,10*(uint32)TC_Api_Get_AFE_Value_For_Hmi(0,L_PER_100KM,100));
        }
			 TC_Api_Update_can_publish(TC_IP_InstFuelConsUnit,TC_Api_Get_IFE_Uint_For_Hmi()); 

        if(TC_IFE_AFTER_RESET_HMI_DASHES ==TC_Api_Get_IFE_Value_For_Hmi(Get_IFE_Uint,100))
        {
            TC_Api_Update_can_publish(TC_IP_InstFuelCons,0X3FFF); 

        }
        else
        {   
            Ife_can_temp= TC_Api_Get_IFE_Value_For_Hmi(Get_IFE_Uint,100);
            Ife_can_temp*=10;
            TC_Api_Update_can_publish(TC_IP_InstFuelCons,Ife_can_temp);  /*Fix bug 45178*/
        }
             
		     TC_Api_Update_can_publish(TC_IP_RemainDistance,TC_Api_Get_DTE_Value_For_Hmi(0)); 
		}
		else
		{
			TC_Api_Update_can_publish(TC_IP_AvgFuelCons_A,0xfff); 
			TC_Api_Update_can_publish(TC_IP_InstFuelConsUnit,0x0); 
			TC_Api_Update_can_publish(TC_IP_RemainDistance,0xFFF); 
			TC_Api_Update_can_publish(TC_IP_InstFuelCons,0X3FFF); 
		}
		
  		#ifdef TC_TIME_CAL
  		//TC_TASK_END_CALCULATE(TC_task_uptae);
  		tc_RteAdaptRunableOstmCheck(TC_task_uptae);
  		#endif
	}
}
/**********************************************************************************************************
*Function   : TC_Api_Get_IFE_Display_Unit                                                              	  *
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
TC_XFE_UNIT_ENUM TC_Api_Get_IFE_Display_Unit(void)
{
	TC_XFE_UNIT_ENUM ife_disp_uint;
	ife_disp_uint = (TC_XFE_UNIT_ENUM)TC_Ftrip_T.tIFE.u8DisplayUnit;
    return (ife_disp_uint);
}
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
uint8 TC_Api_Get_DTE_Accum_Condition(void)
{
	return ( TC_Api_DTE_Accum_Enable() ); /* Fuel03/FullConsumption is OK */
}
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
uint8 TC_Api_Get_AVS_Accum_Condition(void)
{
#if 0
	return ((VNIM_GWMSG284_RX_FUELCONSUMPTIONINST()>0 )&&
			(FALSE == TC_TESTBIT(TC_Trip_Singal_Status,TC_FUEL_SIG_INVLD_MIS_NVR_RCVD))); /*FuelConsumption is OK*/
#endif
	return 1;
}
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
uint32 TC_Api_Get_AVS_Value(uint8 tc_key_index)
{
	return (TC_Ftrip_T.tAVS.u32DisplayAVS[tc_key_index]);
}
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
uint32 TC_Api_Get_IFE_Value(void)
{		
	return (TC_Ftrip_T.tIFE.u32DisplayIFE);
}
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
uint32 TC_Api_Get_AFE_Value(uint8 afe_index)
{
	return (TC_Ftrip_T.tAFE.u32DisplayAFE[afe_index]);
}
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
uint32 TC_Api_Get_DTE_Value(void)
{	
	return TC_Ftrip_T.tDTE.u32DisplayDTE;	
}
/**********************************************************************************************************
*Function   : TC_Api_KSWarmInit                                                                     	  *
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
static void TC_Api_Clear_Fuel_Samples_TimeTrigger(void)
{
	//VNIM_GWMSG284_RX_CLR_MSG_COUNTER();	yb_debug 2018/01/08
	TC_RCan_Get_Fuel_Samples_Times_Old=0;
}
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
uint16 TC_Api_Get_AFE_Value_For_Hmi(uint8 type, TC_XFE_UNIT_ENUM tc_uint, uint32 Denominator)
{
	uint32 u32afe_temp;
	
	if(0u == type)
	{
		u32afe_temp = TC_Api_Get_AFE_Value(0);
	}
	else if(1u == type)
	{
		u32afe_temp = TC_Api_Get_AFE_Value(1);
	}
	else
	{
		u32afe_temp = TC_Api_Get_AFE_Value(0);
	}

	if(TC_AFE_AFTER_RESET_DASHES == u32afe_temp)
	{
		u32afe_temp = TC_AFE_AFTER_RESET_HMI_DASHES;
	}
	else if(TC_AFE_DISPLAY_OFF_DASHES == u32afe_temp)
	{
		u32afe_temp = TC_AFE_DISPLAY_OFF_HMI_DASHES;
	}
	else
	{		
		if(KM_PER_L == tc_uint)
		{
			if(0u != u32afe_temp)
			{
				/* L/100km ---> km/L */
				u32afe_temp = (uint32)(((uint64)TC_AFE_KMPL_CONST_0 * TC_AFE_L_PER_100KM_CONST_0) / (uint64)(u32afe_temp));
				u32afe_temp = TC_Pkg_Output_Round_Up(u32afe_temp, Denominator);
				/* 0.0 - 99.9 */
				if(u32afe_temp >= (99999UL / 100u)) 
				{
					u32afe_temp = 99999 / 100;
				}
			}
			else
			{
				u32afe_temp = TC_AFE_AFTER_RESET_HMI_DASHES;
			}
		}	
		else if(US_MPG == tc_uint)
		{			
			if(0u != u32afe_temp)
			{
				/* L/100km ---> US MPG */
				u32afe_temp = (uint32)(((uint64)TC_AFE_US_MPG_CONST_0 * TC_AFE_L_PER_100KM_CONST_0) / (uint64)(u32afe_temp));
				/* 100 - 400: round up*/
				if(u32afe_temp > 100000)
				{
					u32afe_temp = TC_Pkg_Output_Round_Up(u32afe_temp, Denominator * 10u) * 10u;
				}
				else
				{
					u32afe_temp = TC_Pkg_Output_Round_Up(u32afe_temp, Denominator);
				}
				/* 0.0 - 400 */
				if(u32afe_temp >= (400000 / 100)) 
				{
					u32afe_temp = 400000 / 100;
				}
			}
			else
			{
				u32afe_temp = TC_AFE_AFTER_RESET_HMI_DASHES;
			}
		}
		else if(UK_MPG == tc_uint)
		{			
			if(0u != u32afe_temp)
			{
				/* L/100km ---> UK MPG */
				u32afe_temp = (uint32)(((uint64)TC_AFE_UK_MPG_CONST_0 * TC_AFE_L_PER_100KM_CONST_0) / (uint64)(u32afe_temp));
				/* 100 - 400: round up*/
				if(u32afe_temp > 100000UL)
				{
					u32afe_temp = TC_Pkg_Output_Round_Up(u32afe_temp, Denominator * 10u) * 10u;
				}
				else
				{
					u32afe_temp = TC_Pkg_Output_Round_Up(u32afe_temp, Denominator);
				}
				/* 0.0 - 400 */
				if(u32afe_temp >= (400000UL / 100u)) 
				{
					u32afe_temp = 400000 / 100;
				}
			}
			else
			{
				u32afe_temp = TC_AFE_AFTER_RESET_HMI_DASHES;
			}
		}
		else
		{
			u32afe_temp = TC_Pkg_Output_Round_Up(u32afe_temp, Denominator);
			/* 0.0 - 29.9 */
			if(u32afe_temp >= (TC_MAX_AFE_LPHKM / 100u)) 
			{
				u32afe_temp = (TC_MAX_AFE_LPHKM / 100);
			}
		}
	}

	return (uint16)(u32afe_temp);
}
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
uint16 TC_Api_Get_IFE_Value_For_Hmi(TC_XFE_UNIT_ENUM tc_uint,uint32 Denominator)
{
	uint32 u32ife_temp;
	
	u32ife_temp = TC_Api_Get_IFE_Value();	

	if(TC_IFE_AFTER_RESET_DASHES == u32ife_temp)
	{
		u32ife_temp = TC_IFE_AFTER_RESET_HMI_DASHES;
	}
	else if(TC_IFE_DISPLAY_OFF_DASHES == u32ife_temp)
	{
		u32ife_temp = TC_IFE_DISPLAY_OFF_HMI_DASHES;
	}
	else
	{		
		if(KM_PER_L == tc_uint)
		{
			if(0u != u32ife_temp)
			{
				/* L/100km ---> km/L */
				u32ife_temp = (uint32)(((uint64)TC_IFE_KMPL_CONST_0 * TC_IFE_L_PER_100KM_CONST_0) / (uint64)(u32ife_temp));
				u32ife_temp = TC_Pkg_Output_Round_Up(u32ife_temp, Denominator);
				/* 0.0 - 99.9 */
				if(u32ife_temp >= (99999UL / 100u)) 
				{
					u32ife_temp = 99999 / 100;
				}
			}
			else
			{
				u32ife_temp = TC_IFE_AFTER_RESET_HMI_DASHES;
			}			
		}	
		else if(US_MPG == tc_uint)
		{			
			if(0 != u32ife_temp)
			{
				/* L/100km ---> US MPG */
				u32ife_temp = (uint32)(((uint64)TC_IFE_US_MPG_CONST_0 * TC_IFE_L_PER_100KM_CONST_0) / (uint64)(u32ife_temp));
				/* 100 - 400: round up*/
				if(u32ife_temp > 100000UL)
				{
					u32ife_temp = TC_Pkg_Output_Round_Up(u32ife_temp, Denominator * 10u) * 10u;
				}
				else
				{
					u32ife_temp = TC_Pkg_Output_Round_Up(u32ife_temp, Denominator);
				}
				/* 0.0 - 400 */
				if(u32ife_temp >= (400000UL / 100u)) 
				{
					u32ife_temp = 400000 / 100;
				}
			}
			else
			{
				u32ife_temp = TC_IFE_AFTER_RESET_HMI_DASHES;
			}			
		}
		else if(UK_MPG == tc_uint)
		{			
			if(0u != u32ife_temp)
			{
				/* L/100km ---> UK MPG */
				u32ife_temp = (uint32)(((uint64)TC_IFE_UK_MPG_CONST_0 * TC_IFE_L_PER_100KM_CONST_0) / (uint64)(u32ife_temp));
				/* 100 - 400: round up*/
				if(u32ife_temp > 100000UL)
				{
					u32ife_temp = TC_Pkg_Output_Round_Up(u32ife_temp, Denominator * 10u) * 10u;
				}
				else
				{
					u32ife_temp = TC_Pkg_Output_Round_Up(u32ife_temp, Denominator);
				}
				/* 0.0 - 400 */
				if(u32ife_temp >= (400000UL / 100u)) 
				{
					u32ife_temp = 400000 / 100;
				}
			}
			else
			{
				u32ife_temp = TC_IFE_AFTER_RESET_HMI_DASHES;
			}			
		}
		else if(US_GPH == tc_uint)
		{
			/* L/H ---> US GPH */
			u32ife_temp = (uint32)(((uint64)(u32ife_temp) * TC_IFF_US_GPH_DENOMINATOR) / (TC_IFF_US_GPH_CONSTANT_0));
			u32ife_temp = TC_Pkg_Output_Round_Up(u32ife_temp, Denominator);
			/* 0.0 - 99.9 */
			if(u32ife_temp >= (99999UL / 100u)) 
			{
				u32ife_temp = 99999 / 100;
			}
		}
		else if(UK_GPH == tc_uint)
		{
			/* L/Hm ---> UK GPH */
			u32ife_temp = (uint32)(((uint64)(u32ife_temp) * TC_IFF_UK_GPH_DENOMINATOR) / (TC_IFF_UK_GPH_CONSTANT_0));
			u32ife_temp = TC_Pkg_Output_Round_Up(u32ife_temp, Denominator);
			/* 0.0 - 99.9 */
			if(u32ife_temp >= (99999UL / 100u)) 
			{
				u32ife_temp = 99999 / 100;
			}
		}
		else if(L_PER_100KM == tc_uint)
		{
			u32ife_temp = TC_Pkg_Output_Round_Up(u32ife_temp, Denominator);
			/* 0.0 - 29.9 */
			if(u32ife_temp >= (29999UL / 100u)) 
			{
				u32ife_temp = 29999 / 100;
			}
		}
		else if(L_PER_HOUR == tc_uint)
		{
			u32ife_temp = TC_Pkg_Output_Round_Up(u32ife_temp, Denominator);
			/* 0.0 - 99.9 */
			if(u32ife_temp >= (99999UL / 100u)) 
			{
				u32ife_temp = 99999 / 100;
			}
		}
	}
	
	return (uint16)(u32ife_temp);
} 
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
uint16 TC_Api_Get_DTE_Value_For_Hmi(uint8 speed_uint)
{
	uint32 u32dte_temp;

	u32dte_temp = TC_Api_Get_DTE_Value();
	
	if((TC_DTE_DISPLAY_DASHES == u32dte_temp)||(TC_DTE_DISPLAY_LOW_DASHES == u32dte_temp)) /*fix Error showing range less than 50KM */
	{
		u32dte_temp = TC_DTE_DISPLAY_HMI_DASHES;
	}
	else
	{	
		if(1u == speed_uint)
		{
			/* km ---> miles */
			u32dte_temp = (uint32)((uint64)(u32dte_temp) * TC_DTE_MILES_CONST_0 / TC_DTE_KILOMETRES_CONST_0);
		}	
		
		u32dte_temp = TC_Pkg_Output_Round_Up(u32dte_temp, 1000UL);
	}
	return (uint16)(u32dte_temp);		
}
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
uint16 TC_Api_Get_AVS_Value_For_Hmi(uint8 type,uint8 speed_uint)
{
	uint32 u32Avg_Speed;
	
	if(0u == type)
	{
		u32Avg_Speed = TC_Api_Get_AVS_Value(0);
	}
	else if(1u == type)
	{
		u32Avg_Speed = TC_Api_Get_AVS_Value(1);
	}
	else
	{
		u32Avg_Speed = TC_Api_Get_AVS_Value(0);
	}

	if(TC_AVS_AFTER_RESET_DASHES == u32Avg_Speed)
	{
		u32Avg_Speed = TC_AVS_AFTER_RESET_HMI_DASHES;
	}
	else if(TC_AVS_DISPLAY_OFF_DASHES == u32Avg_Speed)
	{
		u32Avg_Speed = TC_AVS_DISPLAY_OFF_HMI_DASHES;
	}
	else
	{	
		if(1u == speed_uint)
		{
			/* km/h ---> mph */
			u32Avg_Speed = (uint32)((uint64)(u32Avg_Speed) * TC_AVS_KMPH_CONST_0 / TC_AVS_MPH_CONST_0);
			if(u32Avg_Speed >=TC_MAX_AVS_DISP_MILE_VALUE)
			{
				u32Avg_Speed=TC_MAX_AVS_DISP_MILE_VALUE; 
			}
		}	
		else
		{
		    if(u32Avg_Speed >=TC_MAX_AVS_DISP_KM_VALUE)
			{
				u32Avg_Speed=TC_MAX_AVS_DISP_KM_VALUE;
			}
		}		
		u32Avg_Speed = TC_Pkg_Output_Round_Up(u32Avg_Speed, 1000uL);
	}

	return (uint16)(u32Avg_Speed);		
}


/**********************************************************************************************************
*Function   : TC_Api_Reset_All_TC_For_Hmi                                                            	  *
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
void TC_Api_Reset_All_TC_For_Other_Module(TC_RESET_TYPE e_Reset_Memory)
{
	if(e_Reset_Memory == MEMORY_1ST_RESET)
	{		
		TC_Api_Travel_Time_Reset_Value(0);	
		TC_Api_AVS_Reset(0);
		TC_Api_AFE_Reset(0);
	}
	else if(e_Reset_Memory == MEMORY_2ST_RESET)
	{
		TC_Api_Travel_Time_Reset_Value(1);
		TC_Api_AVS_Reset(1);
		TC_Api_AFE_Reset(1);
	}
	else
	{
		TC_Api_Travel_Time_Reset_All();	
		TC_Api_AVS_Reset_All();
		TC_Api_AFE_Reset_All();
	}
}

/**********************************************************************************************************
*Function   : TC_Api_Travel_Time_Reset_Value                                                         	  *
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
void TC_Api_Travel_Time_Reset_Value(uint8 tdt_index)
{
	TC_Ftrip_T.tTravel_Time.u8TravelTime_Hour[tdt_index] = 0; /* accumulated sec */
	TC_Ftrip_T.tTravel_Time.u8TravelTime_Minute[tdt_index] = 0; /* accumulated min */
	TC_Ftrip_T.tTravel_Time.u8TravelTime_Second[tdt_index] = 0;   /* accumulated hour */
	TC_Ftrip_T.tTravel_Time.u8TravelTime_Tick = 0;   /* counter for 1 sec */

	TC_Travel_Time_Calculate_Flag_Enable = FALSE;
}

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
void TC_Api_Travel_Time_Reset_All(void)
{
	uint8 i;
	
	for(i=0;i<TC_MAX_NUM_OF_TDT;i++)
	{
		TC_Ftrip_T.tTravel_Time.u8TravelTime_Second[i] = 0; /* accumulated sec */
	  	TC_Ftrip_T.tTravel_Time.u8TravelTime_Minute[i] = 0; /* accumulated min */
	  	TC_Ftrip_T.tTravel_Time.u8TravelTime_Hour[i] = 0;   /* accumulated hour */
	}
	
	TC_Ftrip_T.tTravel_Time.u8TravelTime_Tick = 0;  /* counter for 1 sec */

	TC_Travel_Time_Calculate_Flag_Enable = FALSE;
}

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
uint32 TC_Api_Travel_Time_Get_Time(uint8 tdt_index)
{
	uint32 drvtime_min_u32;
	
	drvtime_min_u32 = (uint32)TC_Ftrip_T.tTravel_Time.u8TravelTime_Hour[tdt_index] * 60u; 
	drvtime_min_u32 += TC_Ftrip_T.tTravel_Time.u8TravelTime_Minute[tdt_index];
	
	return (drvtime_min_u32);
}

/**********************************************************************************************************
*Function   : TC_APi_Travel_Time_Calculate_Enable                                                    	  *
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
void TC_APi_Travel_Time_Calculate_Enable(void)
{   
    uint8 engSpdSts = 0;
    boolean vehStartingSts = FALSE;
    vehStartingSts = TC_Hev_Phev_VehStartingSts;
    engSpdSts  = TC_API_Get_EngSpd_State();
	/*shujunhua@2021/1/25 :Make a distinction by fuel type*/
		if((TC_VEHICLE_FUEL == TC_Module_Vehicle_Type_Data)||(TC_VEHICLE_FUEL_DIESEL == TC_Module_Vehicle_Type_Data))
		{
            if((FALSE != TC_API_Get_Power_Mode_State()) && (FALSE != engSpdSts))
            {
            TC_Travel_Time_Calculate_Flag_Enable = TRUE;
            }
            else
            {
            TC_Travel_Time_Calculate_Flag_Enable = FALSE;
            }
		}
		else if ((TC_VEHICLE_PHEV==TC_Module_Vehicle_Type_Data)||(TC_VEHICLE_HEV==TC_Module_Vehicle_Type_Data))
        {
            if ((FALSE != TC_API_Get_Power_Mode_State()) &&(FALSE != vehStartingSts))
            {
            TC_Travel_Time_Calculate_Flag_Enable = TRUE;
            }
            else
            {
            TC_Travel_Time_Calculate_Flag_Enable = FALSE;
            }       
        }		
        else
        {
            TC_Travel_Time_Calculate_Flag_Enable = FALSE;
        }
}
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
void TC_Api_Travel_Time_Process_Task (void)
{
	uint8 i;
	boolean tdt_time_status_u8;
	uint32 tdt_elapse_time = 0;
	boolean tc_travel_time_one_second = FALSE;
	
#define SWC_TC_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

	static uint16 tc_travel_1s_sum=0;

#define SWC_TC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */	

	TC_APi_Travel_Time_Calculate_Enable();
 	
	/*judge driver time over 1 second, counter*/
    if (FALSE != TC_Travel_Time_Calculate_Flag_Enable)
    {
		/* init first */
		if(0u == TC_TDT_Time_Init_Status)
		{
			tdt_time_status_u8 = TC_RTE_OstmTimerStart((uint8)TC_TDT_Calculate_Timer2);
			if(FALSE != tdt_time_status_u8)
			{
				TC_TDT_Time_Init_Status = 1;
			}
		}
		else
		{
			tdt_time_status_u8 = TC_RTE_Get_OstmTimerValue((uint8)TC_TDT_Calculate_Timer2,&tdt_elapse_time);
			
			
			if(FALSE == tdt_time_status_u8)
			{
				tdt_elapse_time = 100;
			}
            tc_travel_1s_sum+=(uint16)tdt_elapse_time;
		}	
		
    	if (tc_travel_1s_sum >= TC_DRV_SECOND_COUNTER)
        {   tc_travel_1s_sum-=TC_DRV_SECOND_COUNTER;
        	tc_travel_time_one_second = TRUE;		
			/*TBD by shujunhua :need to reset tdt_elapse_time */
		}	 
		
		for(i=0;i<TC_MAX_NUM_OF_TDT;i++)
		{
			if (FALSE != tc_travel_time_one_second)
			{
			    TC_Ftrip_T.tTravel_Time.u8TravelTime_Second[i]++; /* increment seconds */
				/* check if accumulated seconds are same or bigger than 60 sec */
				if (TC_Ftrip_T.tTravel_Time.u8TravelTime_Second[i] >= 60u)
				{
				   TC_Ftrip_T.tTravel_Time.u8TravelTime_Second[i] = 0; /* initialize accumulated seconds to 0 */
				   TC_Ftrip_T.tTravel_Time.u8TravelTime_Minute[i]++; /* increment minutes */		   
				   /* check if accumulated minutes are same or bigger than 60 min */
				   if (TC_Ftrip_T.tTravel_Time.u8TravelTime_Minute[i] >= 60u)
				   {
					  TC_Ftrip_T.tTravel_Time.u8TravelTime_Minute[i] = 0; /* initialize accumulated minutes to 0 */
					  TC_Ftrip_T.tTravel_Time.u8TravelTime_Hour[i]++; /* increment hours */				  
					  /* check if accumulated hours are same or bigger than 100 h */
					  if (TC_Ftrip_T.tTravel_Time.u8TravelTime_Hour[i] > TC_Ftrip_T.tTC_Config_NVM.TravelTimeDisplayLimited_Hour_NvmInit)
					  {
						 TC_Ftrip_T.tTravel_Time.u8TravelTime_Hour[i] = 0; /* initizlize accumulated hours to 0 */
					  }
				   } /* minute overflow */
				} /* hour overflow */
			} /* 1s tick */		
		}
	}
	else
	{
		TC_TDT_Time_Init_Status = 0;
	}
	/*drive time over 99:59, reset*/
 	for(i=0;i<TC_MAX_NUM_OF_TDT;i++)
 	{
		
        if ((TC_Ftrip_T.tTravel_Time.u8TravelTime_Second[i] >= 60u)||\
        (TC_Ftrip_T.tTravel_Time.u8TravelTime_Minute[i] >=60u)||\
        ((TC_Ftrip_T.tTC_Config_NVM.TravelTimeDisplayLimited_Hour_NvmInit==0u)&&\
        (TC_Ftrip_T.tTravel_Time.u8TravelTime_Minute[i] > TC_Ftrip_T.tTC_Config_NVM.TravelTimeDisplayLimited_Minute_NvmInit)))
        
        {
            TC_Api_Travel_Time_Reset_Value(i);
        }
        
          
            
 	}
	
	if(FALSE == TC_Ftrip_T.tTC_Config_NVM.TravelTimeADisplayEnable_NvmInit)
	{
		/* display off */
		TC_Ftrip_T.tTravel_Time.u8TravelTime_Hour[0] = (uint8)TC_TDT_DISPLAY_OFF_DASHES;
		TC_Ftrip_T.tTravel_Time.u8TravelTime_Minute[0] = (uint8)TC_TDT_DISPLAY_OFF_DASHES;
		TC_Ftrip_T.tTravel_Time.u8TravelTime_Second[0] = (uint8)TC_TDT_DISPLAY_OFF_DASHES;
	}

	if(FALSE == TC_Ftrip_T.tTC_Config_NVM.TravelTimeBDisplayEnable_NvmInit)
	{
		/* display off */
		TC_Ftrip_T.tTravel_Time.u8TravelTime_Hour[1] = (uint8)TC_TDT_DISPLAY_OFF_DASHES;
		TC_Ftrip_T.tTravel_Time.u8TravelTime_Minute[1] = (uint8)TC_TDT_DISPLAY_OFF_DASHES;
		TC_Ftrip_T.tTravel_Time.u8TravelTime_Second[1] = (uint8)TC_TDT_DISPLAY_OFF_DASHES;
	}	
}

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
uint8 TC_Api_Get_IFE_Uint_For_Hmi(void)
{
	//uint8 uint_flag;
/*
	if(ftrip_get_IFE_disp_Unit())
	{
		uint_flag = 0;
	}
	else
	{
		uint_flag = 1;
	}*/
//	uint_flag = 1;
	

	return TC_Ftrip_T.tIFE.u8DisplayUnit ;
}
/**********************************************************************************************************
*Function   : TC_Api_Eol_Get_Fuel_State                                                              	  *
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
void TC_Api_Eol_Get_Fuel_State(void)
{
	
	TC_Ftrip_Info.AFE_Display = (uint16)TC_Api_Get_AFE_Value(0);
	TC_Ftrip_Info.AFE_CalculateAFE  = (uint16)TC_Api_Get_AFE_Value(1);
	TC_Ftrip_Info.AFE_CalculateRAFF = (uint16)TC_Api_Get_AFE_Value(2);
	
	TC_Ftrip_Info.DTE_Diaplay = (uint16)TC_Api_Get_DTE_Value();
    TC_Ftrip_Info.DTE_Update   = (uint16)TC_Ftrip_T.tDTE.u32CalculationDTE;//TC_Api_Get_AVS_Value(1);
	TC_Ftrip_Info.DTE_CalculateCFC = (uint16)TC_Pkg_Output_RAFE();
	TC_Ftrip_Info.AVS_Display = (uint16)TC_Api_Get_AVS_Value(0);
	TC_Ftrip_Info.IFE_Display = (uint16)TC_Api_Get_IFE_Value();
	// modify by fchao in 20200615
	//TC_Ftrip_Info.Trip_Display = fodo_u32GetTripValue(0);
	//TC_Ftrip_Info.ODO_Display = HMI_Get_Odometer();
	TC_Ftrip_Info.FUEL_Consuption = TC_Pkg_Out_Fuel_Consump();
	
}
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
uint32 TC_Api_Get_Fuel_Accum_Value(void)
{
	return (TC_Ftrip_T.tFuel.u32FuelPulseAccum);
}
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
void TC_Api_Clear_Fuel_Accum_Value(void)
{
	TC_Ftrip_T.tFuel.u32FuelPulseAccum = 0;
}
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
void TC_Api_Set_Fuel_Accum_Enable(uint8 enable_flag)
{
	TC_Ftrip_T.tFuel.u8FuelAccumEnable = enable_flag;
}
/**********************************************************************************************************
*Function   : TC_Api_Reset_AVS_For_Hmi                                                                	  *
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
void TC_Api_Reset_AVS_For_Hmi(uint8 type)
{
    TC_Api_AVS_Reset(type);
}
/**********************************************************************************************************
*Function   : TC_Api_Reset_AFE_For_Hmi                                                                    *
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
void TC_Api_Reset_AFE_For_Hmi(uint8 type)
{
	TC_Api_AFE_Reset(type);
}

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
boolean TC_API_Get_Power_Mode_State (void)
{
	boolean power_state_temp = TRUE;
	power_state_temp = TC_RTE_API_Get_Power_Mode_State();
	return power_state_temp;
}
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
uint8 TC_API_Get_Voltage_Mode_State (void)
{
	uint8 tc_power_mode;
	tc_power_mode = TC_RTE_API_Get_Voltage_Mode_State();
	return (tc_power_mode);
}
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
boolean TC_API_Get_Fuel_Error_State (void)
{
	boolean full_error_state_temp = FALSE;
	full_error_state_temp = TC_RTE_API_Get_Fuel_Error_State();
	return full_error_state_temp;
}



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
uint32 TC_API_Get_Fuel_volume (void)
{
	uint32 Fuel_volume_temp = 0;
	Fuel_volume_temp = TC_RTE_API_Get_Fuel_volume();
	return Fuel_volume_temp;
}

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
boolean TC_API_Get_Fuel_Finished_Init_State (void)
{
	boolean fuel_finished_init_temp = TRUE;
	fuel_finished_init_temp = TC_RTE_API_Get_Fuel_Finished_Init_State();
	return fuel_finished_init_temp;
}
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
boolean TC_API_Get_VehRunning_State (void)
{
	uint8 vehrunning_state_temp = 1;
	vehrunning_state_temp = TC_RTE_API_Get_VehRunning_State();
	return (vehrunning_state_temp==1u)?TRUE:FALSE;
}
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
uint8 TC_API_Get_VehRunning_State_For_Ifc(void)
{
	//uint8 vehrunning_state_temp = (uint8)TRUE;
    uint16 speed_realt_temp=0; 
    speed_realt_temp = TC_RTE_API_Get_VehRunning_State_Ifc();
    if (speed_realt_temp>300uL) /*Synchronous speed module accuracy */ 
    {
        TC_VehRunningSts =1;
    }
    else if (speed_realt_temp==0u) 
    {
        TC_VehRunningSts =0;
    }
    else
    {}
    return TC_VehRunningSts;
}

/** 
 * [TC_API_Get_Speed_For_Dte : get spd value]
 * @Author   shujunhua
 * @DateTime 2021/5/29-11:40:58
 * @param    void                     [description]
 * @return   uint16                   [factor:100 ,eg 20000=20km/h]
 */
 uint16 TC_API_Get_Speed_For_Dte(void)
{
    uint16 speed_realt_temp=0; 
	speed_realt_temp = TC_RTE_API_Get_VehRunning_State_Ifc();   
	return speed_realt_temp;
}


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
boolean TC_API_Get_EngSpd_State (void)
{
	uint8 engspd_state_temp = 1;
	engspd_state_temp = TC_RTE_API_Get_EngSpd_State();
	return (engspd_state_temp==1u)?TRUE:FALSE;
}
/**********************************************************************************************************
*Function   : TC_API_Get_EngSpd_OUT_State                                                                 *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Ren Feng Po                                                                                 *
*                                                                                                         *
*Date		: 2021-11-23                                                                                  *
**********************************************************************************************************/

uint8 TC_API_Get_EngSpd_OUT_State (void)
{
	uint8 engspd_state_out_temp = 1;
	engspd_state_out_temp = TC_RTE_API_Get_EngSpd_OUT_State();
	return engspd_state_out_temp;
}
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
boolean TC_API_Get_Fuel_FastFill_State (void)
{
	boolean fuel_fastfill_state_temp = FALSE;
	fuel_fastfill_state_temp = TC_RTE_API_Get_Fuel_FastFill_State();
	return fuel_fastfill_state_temp;
}


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
void TC_API_Set_TC_Module_Reset_Data (TC_MODULE_RESET_DATA_INDEX tc_reset_index)
{
	if(TC_RESET_ALL_DATA == tc_reset_index)
	{
		TC_Api_Travel_Time_Reset_All();	
		TC_Api_AVS_Reset_All();
		TC_Api_AFE_Reset_All();	
		TC_Api_Dte_Reset();

	}
	else if(TC_RESET_1ST_DATA == tc_reset_index)
	{
		TC_Api_Travel_Time_Reset_Value(0);	
		TC_Api_AVS_Reset(0);
		TC_Api_AFE_Reset(0);
	}
	else if(TC_RESET_2ST_DATA == tc_reset_index)
	{
		TC_Api_Travel_Time_Reset_Value(1);
		TC_Api_AVS_Reset(1);
		TC_Api_AFE_Reset(1);
        TC_Api_Dte_Reset();
	}
	else
	{
		/* error index */
	}	
}
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
void TC_API_Set_Module_Data(TC_MODULE_OUTPUT_DATA_STRUCT tc_module_output_data)
{
	TC_RTE_API_Get_TC_Module_Output_Data(tc_module_output_data);
}
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
void TC_API_Set_Diag_Read_TC_Data(uint8 * data)
{
	uint8 diag_read_data[7] = {0};
	uint16 diag_read_data_temp_1 = 0;	
	uint16 diag_read_data_temp_2 = 0;  
	uint16 diag_read_data_rafe = 0;

	diag_read_data[0] = TC_RTE_API_Get_Fuel_FastFill_State();
	diag_read_data_rafe = (uint16)TC_Pkg_Output_RAFE();
	diag_read_data[1] = (uint8)(diag_read_data_rafe >> 8);
	diag_read_data[2] = (uint8)(diag_read_data_rafe & (uint16)0xFF);
   if(TC_Ftrip_T.tDTE.u32DisplayDTE !=TC_DTE_DISPLAY_DASHES)
    {
        diag_read_data_temp_1 = (uint16)(TC_Ftrip_T.tDTE.u32CalculationDTE/1000uL);
        diag_read_data_temp_2 = (uint16)(TC_Ftrip_T.tDTE.u32DisplayDTE/1000uL);
        diag_read_data[3] = (uint8)(diag_read_data_temp_1 >> 8);
        diag_read_data[4] = (uint8)(diag_read_data_temp_1 & (uint16)0xFF);

        if(diag_read_data_temp_1 > diag_read_data_temp_2)
        {
         diag_read_data_temp_1 = diag_read_data_temp_1 - diag_read_data_temp_2;
        }
        else
        {
         diag_read_data_temp_1 = diag_read_data_temp_2 - diag_read_data_temp_1;
        }       
        diag_read_data[5] = (uint8)(diag_read_data_temp_1 >> 8);
        diag_read_data[6] = (uint8)(diag_read_data_temp_1 & (uint16)0xFF);
    }
   else
    {
        diag_read_data_temp_1 = (uint16)(TC_Ftrip_T.tDTE.u32CalculationDTE/1000uL);
        diag_read_data[3] = (uint8)(diag_read_data_temp_1 >> 8);
        diag_read_data[4] = (uint8)(diag_read_data_temp_1 & (uint16)0xFF);
    }
   
    (void)memcpy(data,diag_read_data,7);
}


uint16 TC_Api_Get_DTE_Phev_Value(void)
{	
	return TC_Ftrip_T.tPhev.u16DisplayDTE;	
}


// static boolean TC_Api_Phev_DTE_cal_Enable(void)
// {
//     boolean result=FALSE;
//     return result;
// }

/**********************************************************************************************************
*Function   : TC_Api_Phev_DTE_Display_Condition                                                           *
*                                                                                                         *
*Description: PHEV DTE Enable condition                                                                   *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: uint8                                                                                       *
*                                                                                                         *
*Author 	: Shu junhua                                                                                  *
*                                                                                                         *
*Date       : 2021-03-06    update for SRS V2.0                                                           *
**********************************************************************************************************/
static boolean TC_Api_Phev_DTE_Display_Condition(void)
{   
    boolean result=FALSE;
    /*Add Offline configuration and internal configuration*/
    if(((TC_Module_Motor_Type_Data==TC_VEHICLE_MOTOR_P2)||\
      (TC_Module_Motor_Type_Data==TC_VEHICLE_MOTOR_P2_P4)||\
      (TC_Module_Motor_Type_Data==TC_VEHICLE_MOTOR_PS)||\
      (TC_Module_Motor_Type_Data==TC_VEHICLE_MOTOR_PARA_P2)||\
      (TC_Module_Motor_Type_Data==TC_VEHICLE_MOTOR_PS_P4))&&\
      (TC_Module_Vehicle_Type_Data==TC_VEHICLE_PHEV)&&(FALSE != TC_PHEVRange_DISP_ENABLE_INTERNAL))
	{
	    result=TRUE;
	}
	else
	{
	    result=FALSE;
	}
     return result;
}
/**********************************************************************************************************
*Function   : TC_Api_Update_Phev_Dte                                                                      *
*                                                                                                         *
*Description: PHEV DTE Display Handle                                                                     *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: uint8                                                                                       *
*                                                                                                         *
*Author 	: Shu junhua                                                                                  *
*                                                                                                         *
*Date       : 2021-03-08    update for SRS V2.0                                                           *
**********************************************************************************************************/
static void TC_Api_Update_Phev_Dte(void)
{   
    uint16 phev_dte_temp=0;
    TC_DTE_PHEV_DATA_STRUCT phev_dte_data=TC_RTE_API_Get_HCU_Node_Status();
    TC_Ftrip_T.tPhev.u32DisplayTimeTick++;
    if (FALSE != TC_Api_Phev_DTE_Display_Condition())
    {
        if(FALSE != phev_dte_data.tc_phev_dte_node_status)
        {
            if ((phev_dte_data.tc_phev_dte_value < TC_MinDisplayPHEVRange) ||\
                (phev_dte_data.tc_phev_dte_value > TC_MaxDisplayPHEVRange))
            {
                phev_dte_temp = TC_PHEV_DTE_DISPLAY_DASHES;
            }
            else
            {
                phev_dte_temp = phev_dte_data.tc_phev_dte_value;
            }
        }
        else 
        {
            phev_dte_temp = TC_PHEV_DTE_DISPLAY_DASHES;
        }
    }
    else
    {
        phev_dte_temp = TC_PHEV_DTE_DISPLAY_HMI_DASHES;
    }
    if(TC_Ftrip_T.tPhev.u32DisplayTimeTick >=TC_Ftrip_T.tTC_Config_NVM.Phev_Dte_RefreshRatePHEVDTE)
    {
        TC_Ftrip_T.tPhev.u32DisplayTimeTick=0;
        TC_Ftrip_T.tPhev.u16DisplayDTE= phev_dte_temp;
    }
  
}
uint16 TC_Api_Get_DTE_Phev_Value_For_Hmi(uint8 speed_uint)
{
	uint32 u32dte_temp;
    /*Adapt the original unit conversion function to increase accuracy by 1000 magnification*/
	u32dte_temp = 1000uL*(uint32)TC_Api_Get_DTE_Phev_Value();
	
	if( (TC_PHEV_DTE_DISPLAY_DASHES*1000uL) == u32dte_temp)
	{
		u32dte_temp = TC_PHEV_DTE_DISPLAY_DASHES;
	}
	else
	{	
		if(1u == speed_uint)
		{
			/* km ---> miles */
			u32dte_temp = (uint32)((uint64)(u32dte_temp) * TC_DTE_MILES_CONST_0 / TC_DTE_KILOMETRES_CONST_0);
		}	
		
		u32dte_temp = TC_Pkg_Output_Round_Up(u32dte_temp, 1000);
	}
	return (uint16)(u32dte_temp);		
}


TC_TOTAL_STRUCT TC_Api_Get_ALL_Date (void)
{
    return TC_Ftrip_T;   
}

TC_VEHICLE_TYPE_ENUM  TC_Api_Get_Vehicle_Type(void)
{
  return   TC_Module_Vehicle_Type_Data;
}



/**********************************************************************************************************
*Function   :    GDC V3.5 SRS energy Management                                                           *
*                                                                                                         *
*Description: v0.1 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: shu junhua                                                                                   *
*                                                                                                         *
*Date       : 2020-12-03                                                                                  *
**********************************************************************************************************/
#if 1 

TC_Energy_data_t * TC_Api_Emergy_get_data(void)
{
    return (&TC_Energy_data);
}



TC_SW_TIMER_STATE TC_Api_Sw_Timer_Check(TC_SW_TIMER_ID id)
{
    TC_SW_TIMER_STATE ret;
	
    if (TC_SW_Timers[id] == 0u)
    {
        ret = TC_TIMER_CLEAR;
    }
    else if (TC_SW_Timers[id] == 0x8000uL)
    {
        ret = TC_TIMER_EXPIRED;
    }
    else
    {
        ret = TC_TIMER_RUNNING;
    }
    return ret;
}
void TC_Api_Sw_timer_start(TC_SW_TIMER_ID id, uint16 time)
{
    TC_SW_Timers[id] = (uint16)(time|0x8000UL);  
}

void TC_Api_Sw_timer_set_state(TC_SW_TIMER_ID id, TC_SW_TIMER_STATE state)
{
    TC_SW_Timers[id] = (uint16)state;  
}
void TC_Api_Sw_timer_clear(TC_SW_TIMER_ID id)
{
    TC_Api_Sw_timer_set_state(id, TC_TIMER_CLEAR);
}

static void TC_Api_sw_timer_update(void)
{
    uint8 id;
    uint16 temp;

    for (id = 0; id <= (TC_SW_TMR_CFG_MAX-1); id++)
    {
        if (0u != (TC_SW_Timers[id]&0x8000UL))
        {
            temp = (uint16)(TC_SW_Timers[id]&0x7fffUL);
            if (temp > 0u)
            {
                temp--;
                TC_SW_Timers[id] = (uint16)(temp|0x8000UL);
            }
        }
    }
}

/*Queue data is aligned to the head of the queue */
static void  TC_Api_Emergy_mq_sort(TC_ENERGY_PER_1KM_STRUCT *new)
{
    uint8 i=0;
    /*Queue is not full ,Insert at the end of the valid queue  
    FIFO :if the first data of the team has been successfully sent*/
    TC_Energy_data_t *p = TC_Api_Emergy_get_data();
    if(p->Tx_index < TC_EMERGY_DATA_NUM)
    {   
        p->Tx_buffer[p->Tx_index] = *new;
        p->Tx_index++;
    }
    else
    {
        
        for (i = 0; i < (TC_EMERGY_DATA_NUM-1u); i++)
        { 
            //  
            (p->Tx_buffer[i]) = (p->Tx_buffer[i+1u]);
        } 
        p->Tx_buffer[TC_EMERGY_DATA_NUM-1u] = *new;

    } 
    p->Tx_table =p->Tx_buffer;
}

static void  TC_Api_Emergy_mq1_sort(void)
{
    uint8 i=0;
    /*Queue is not full ,Insert at the end of the valid queue  
	  FIFO :if the first data of the team has been successfully sent*/
    TC_Energy_data_t *p = TC_Api_Emergy_get_data();
    if(p->Tx_index==1u)
    {  
       p->Tx_index =0; 
       (void)memset(&p->Tx_buffer[p->Tx_index], 0, sizeof(TC_ENERGY_PER_1KM_STRUCT));
       if(p->Tx_table !=  NULL) 
       {
          p->Tx_table =  NULL;
        
       }
    }
    else if(p->Tx_index< TC_EMERGY_DATA_NUM)
	{ 
    	for (i = 0; i < p->Tx_index; i++)
        {
            (p->Tx_buffer[i]) = (p->Tx_buffer[i+1u]);
        }	 
    	
        if(p->Tx_index!=0u)	
        {
             p->Tx_index--;
             p->Tx_table =p->Tx_buffer;
        }
        else
        {
            if(p->Tx_table !=  NULL) 
            {
              p->Tx_table =  NULL;              
            }

        }            

	}
    else
    {
        for (i = 0; i < (TC_EMERGY_DATA_NUM-1u); i++)
           {
                (p->Tx_buffer[i]) = (p->Tx_buffer[i+1u]);
           }     
         (void)memset(&p->Tx_buffer[TC_EMERGY_DATA_NUM-1u], 0, sizeof(TC_ENERGY_PER_1KM_STRUCT));
         if(p->Tx_index!=0u)	
            {
                 p->Tx_index--;
                 p->Tx_table =p->Tx_buffer;
            }
            else
            {
                if(p->Tx_table !=  NULL) 
                   {
                      p->Tx_table =  NULL;              
                   }
            }
    }

}

/*Empty head */
static void TC_Api_Emergy_mq0_clear(void)
{
    TC_Energy_data_t *p = TC_Api_Emergy_get_data();
    if (p->Tx_table != NULL)
    {   p->Tx_table =  NULL;
        TC_Api_Emergy_mq1_sort();
    }
}

static boolean TC_Api_Emergy_Queue_Null_Check(void)
{
    TC_Energy_data_t *p = TC_Api_Emergy_get_data();
    if (p->Tx_table == NULL)
    {  
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void TC_Api_Emergy_Tx_Pro(void)
{
    EnergyInfoIdDataType EnergyInfoIdData = {0};
    IPC_M2S_IVIAppInfoSetSettingSignalResp_t TC_Api_Emergy_Data = {0};
    TC_Energy_data_t *p = TC_Api_Emergy_get_data();
    /*Determines whether the queue header is empty*/

    if (p->Tx_table != NULL)
    {
        (void)Rte_Read_rpSR_SWCNormal_EnergyInfoId_Data(&EnergyInfoIdData);
        TC_Api_Emergy_Data.ClientID = EnergyInfoIdData.ClientId;
        TC_Api_Emergy_Data.InfoID = 0xFB02;
        TC_Api_Emergy_Data.ModuleID = (uint8)EnergyInfoIdData.ModuleId;
        TC_Api_Emergy_Data.DataLength = 23;
        TC_Api_Emergy_Data.Data[0] = IPC_GET_BYTE(p->Tx_buffer[0].FuelConsumptionPer1km, 3);
        TC_Api_Emergy_Data.Data[1] = IPC_GET_BYTE(p->Tx_buffer[0].FuelConsumptionPer1km, 2);
        TC_Api_Emergy_Data.Data[2] = IPC_GET_BYTE(p->Tx_buffer[0].FuelConsumptionPer1km, 1);
        TC_Api_Emergy_Data.Data[3] = IPC_GET_BYTE(p->Tx_buffer[0].FuelConsumptionPer1km, 0);

        TC_Api_Emergy_Data.Data[4] = IPC_GET_BYTE(p->Tx_buffer[0].EgyUsedPer1km, 1);
        TC_Api_Emergy_Data.Data[5] = IPC_GET_BYTE(p->Tx_buffer[0].EgyUsedPer1km, 0);
        
        TC_Api_Emergy_Data.Data[6] = IPC_GET_BYTE(p->Tx_buffer[0].RecupPwrPer1km, 1);
        TC_Api_Emergy_Data.Data[7] = IPC_GET_BYTE(p->Tx_buffer[0].RecupPwrPer1km, 0);

        TC_Api_Emergy_Data.Data[8] = IPC_GET_BYTE(p->Tx_buffer[0].CalendarPer1km, 7);
        TC_Api_Emergy_Data.Data[9] = IPC_GET_BYTE(p->Tx_buffer[0].CalendarPer1km, 6);
        TC_Api_Emergy_Data.Data[10] = IPC_GET_BYTE(p->Tx_buffer[0].CalendarPer1km, 5);
        TC_Api_Emergy_Data.Data[11] = IPC_GET_BYTE(p->Tx_buffer[0].CalendarPer1km, 4);
        TC_Api_Emergy_Data.Data[12] = IPC_GET_BYTE(p->Tx_buffer[0].CalendarPer1km, 3);
        TC_Api_Emergy_Data.Data[13] = IPC_GET_BYTE(p->Tx_buffer[0].CalendarPer1km, 2);
        TC_Api_Emergy_Data.Data[14] = IPC_GET_BYTE(p->Tx_buffer[0].CalendarPer1km, 1);
        TC_Api_Emergy_Data.Data[15] = IPC_GET_BYTE(p->Tx_buffer[0].CalendarPer1km, 0);

        TC_Api_Emergy_Data.Data[16] = IPC_GET_BYTE(p->Tx_buffer[0].NewChargeCyclePer1km, 0);

        TC_Api_Emergy_Data.Data[17] = IPC_GET_BYTE(p->Tx_buffer[0].TripNotSentPer1km, 1);
        TC_Api_Emergy_Data.Data[18] = IPC_GET_BYTE(p->Tx_buffer[0].TripNotSentPer1km, 0);

        TC_Api_Emergy_Data.Data[19] = IPC_GET_BYTE(p->Tx_buffer[0].VehDistance, 3);
        TC_Api_Emergy_Data.Data[20] = IPC_GET_BYTE(p->Tx_buffer[0].VehDistance, 2);
        TC_Api_Emergy_Data.Data[21] = IPC_GET_BYTE(p->Tx_buffer[0].VehDistance, 1);
        TC_Api_Emergy_Data.Data[22] = IPC_GET_BYTE(p->Tx_buffer[0].VehDistance, 0);

        (void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_SET_SETTING_RESP, (uint8 *)&TC_Api_Emergy_Data, (uint16)sizeof(TC_Api_Emergy_Data), TRUE);
        TC_Api_Sw_timer_start(TC_EMERGY_WAIT_RESPONSE, TC_EMERGY_WAIT_RESPONSE_TIMER_NUM); /*1km */
        TC_Api_Sw_timer_start(TC_EMERGY_WAIT_5S, TC_EMERGY_WAIT_5S_TIMER_NUM);             /*1km */
    }
    else
    {
        TC_Api_Sw_timer_clear(TC_EMERGY_WAIT_RESPONSE);
        TC_Api_Sw_timer_clear(TC_EMERGY_WAIT_5S);
    }
}

/*

*/

#define TC_EMERGY_1KM_INFO_ID 0X1AED 



// static void TC_Api_Phev_New_Charge_Status_Set(uint8 value)
// {
//     TC_Ftrip_T.tPhev.u8NewChargeCycle=value;  
// }

static uint16 TC_Api_Phev_New_Charge_Status_get(void)
{
    return TC_Ftrip_T.tPhev.u16NewChargeCycle_Count;
}

// static void TC_Api_Phev_New_Charge_Status_Clear(void)
// {
//     TC_Ftrip_T.tPhev.u16NewChargeCycle_Count = 0 ;
// }


/**********************************************************************************************************
*Function   : TC_Api_Phev_Charge_check                                                                    *
*                                                                                                         *
*Description: when HCU_ChargSts = 1: Charging -- > 0x3: Charge Complete/0x4: change Stopped),             *
Chargecyclecounter is incremented by 1; 	                                                              *
*                                                                                                         *
*Parameter	: Trip_Value :unit 0.1m  															          *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: shu junhua                                                                                  *
*                                                                                                         *
*Date       : 2020-12-03                                                                                  *
*Date       : 2021-03-08  SRS V2.0 update ChargeCycleCounter by                                           *
                          Energy management 1km fuel consumption, power consumption and energy recovery   *
**********************************************************************************************************/

static void TC_Api_Phev_Charge_check(uint16 Trip_Value) 
{
    TC_VEHICLE_CHARGE_TYPE_ENUM charge_temp=TC_VEHICLE_CHARGE_DEFAULT; 
    //uint8 NewChargeCycle=(uint8)FALSE;
    charge_temp=   TC_RTE_API_Get_HCU_Charge_Status();
    if(charge_temp!=TC_Ftrip_T.tPhev.chargests)  
    {
        if((TC_VEHICLE_CHARGE_CHARGING==TC_Ftrip_T.tPhev.chargests)&& \
        ((TC_VEHICLE_CHARGE_COMPLETE==charge_temp)||(TC_VEHICLE_CHARGE_STOPED==charge_temp)))
        {
            //TC_Api_Phev_New_Charge_Status_Set(1);
            TC_Ftrip_T.tPhev.u16NewChargeCycle_Count++; 
            if(TC_Ftrip_T.tPhev.u16NewChargeCycle_Count>999)
            {
                TC_Ftrip_T.tPhev.u16NewChargeCycle_Count =0;
            }
            else
            {
                // do nothing    
            }
            TC_Api_Emergy_Get_TripNotSentPer1km(Trip_Value);
        }
        else
        {
            TC_Api_Emergy_Get_TripNotSentPer1km(0);
        }
        TC_Ftrip_T.tPhev.chargests =charge_temp; 
    }
    else
    {
        // do nothing 
    }

}

static uint8 TC_Api_Emergy_Accum_Enable(void)
{   
    boolean result = FALSE;
    if(((TC_VEHICLE_HEV == TC_Module_Vehicle_Type_Data)||(TC_VEHICLE_PHEV == TC_Module_Vehicle_Type_Data))||\
       (((TC_VEHICLE_FUEL == TC_Module_Vehicle_Type_Data)||(TC_VEHICLE_FUEL_DIESEL == TC_Module_Vehicle_Type_Data))\
       &&(TC_VEHICLE_MOTOR_P0 ==TC_Module_Motor_Type_Data)))
    { 
        result = TRUE;
    }
    else
    {
        result = FALSE;
    } 

    return ((result==TRUE)?1u:0u);
}

static uint8 TC_Api_Emergy_Display_Enable(void)
{  
    boolean result = FALSE;
    if(TRUE ==TC_Api_Emergy_Accum_Enable())
    { 
        result = TRUE;
    }
    else
    {
        result = FALSE;
    } 

    return ((result==TRUE)?1u:0u);
}

static void TC_Api_Accum_EgyUsed_Count(void)
{
    TC_Phev_Egy_DATA_t EgyUsed_new_count={0,0};
    TC_Phev_Egy_DATA_t EgyUsed_count_num={0,0};
    boolean  EgyUsed_message_received = FALSE;
    
    EgyUsed_new_count=  TC_Api_Rte_Get_Hcu_EgyUsed_MsgValue();
    
    if(0XFFFF==EgyUsed_new_count.tc_Egyued)
    {
      EgyUsed_message_received = TRUE;
    }
    else
    {
      EgyUsed_message_received = FALSE;
    }
    if(FALSE != EgyUsed_message_received)
  	{
		TC_SETBIT(TC_Trip_Singal_Status, TC_EGYUSED_SIG_INVLD_MIS_NVR_RCVD);
		TC_Prev_EgyUsed_count =0;
        TC_Ftrip_T.tPhev.u32AccumEgyUsed = TC_DATA_INPUT_ERROR;
  	}
	else
    {
       if(FALSE != TC_TESTBIT(TC_Trip_Singal_Status, TC_EGYUSED_SIG_INVLD_MIS_NVR_RCVD))
		{		
			TC_CLEARBIT(TC_Trip_Singal_Status,TC_EGYUSED_SIG_INVLD_MIS_NVR_RCVD);	
            TC_Prev_EgyUsed_count=  EgyUsed_new_count.tc_Egyued;
		}
		else
		{  
		/***EgyUsed*****CAL************************************************************************/
		  if( EgyUsed_new_count.tc_Egyued > TC_Prev_EgyUsed_count  )
            {
                EgyUsed_count_num.tc_Egyued = ( (uint16)(EgyUsed_new_count.tc_Egyued - TC_Prev_EgyUsed_count) );
            }
            else if(EgyUsed_new_count.tc_Egyued < TC_Prev_EgyUsed_count  )
            {
                EgyUsed_count_num.tc_Egyued = ((uint16)((uint16)EgyUsed_new_count.tc_Egyued + ( (uint16)TC_MAX_ENERGY_COUNT - (uint16)TC_Prev_EgyUsed_count) + (uint16)1u ));
            }
            else
            {
                EgyUsed_count_num.tc_Egyued = 0;
            }
          if (TRUE ==TC_Api_Emergy_Accum_Enable())
            {
                TC_Prev_EgyUsed_count = EgyUsed_new_count.tc_Egyued;
                TC_Ftrip_T.tPhev.u32AccumEgyUsed+=EgyUsed_count_num.tc_Egyued;       
            }
            else 
            {
                TC_Prev_EgyUsed_count = 0;
                TC_Ftrip_T.tPhev.u32AccumEgyUsed=0;     
            }
            
         /***RecupPwr*****CAL************************************************************************/
            if( EgyUsed_new_count.tc_RecupPwr > TC_Prev_EgyRecupPwr_count  )
            {
                EgyUsed_count_num.tc_RecupPwr = ( (uint16)(EgyUsed_new_count.tc_RecupPwr - TC_Prev_EgyRecupPwr_count) );
            }
            else if(EgyUsed_new_count.tc_RecupPwr < TC_Prev_EgyRecupPwr_count  )
            {
                EgyUsed_count_num.tc_RecupPwr = ((uint16)((uint16)EgyUsed_new_count.tc_RecupPwr + ( (uint16)TC_MAX_ENERGY_COUNT - (uint16)TC_Prev_EgyRecupPwr_count) + (uint16)1u ));
            }
            else
            {
                EgyUsed_count_num.tc_RecupPwr = 0;
            }
            if (TRUE ==TC_Api_Emergy_Accum_Enable())
            {
                TC_Prev_EgyRecupPwr_count = EgyUsed_new_count.tc_RecupPwr;
                TC_Ftrip_T.tPhev.u32AccumEgyRecupPwr+=EgyUsed_count_num.tc_RecupPwr;   
            }
            else 
            {
                TC_Prev_EgyRecupPwr_count = 0;
                TC_Ftrip_T.tPhev.u32AccumEgyRecupPwr=0; 
            }
        

        }
    }   
    
}

static void  TC_Api_Emergy_Get_EgyUsedPer1km(void)
{
     TC_Energy_data_current.EgyUsedPer1km=(uint16)TC_Pkg_Get_Phev_Egyued_Value(); 
     
}

static void  TC_Api_Emergy_Get_EgyRecupPwrPer1km(void)
{
     TC_Energy_data_current.RecupPwrPer1km=(uint16)TC_Pkg_Get_Phev_RecupPwr_Value(); 
     //
}

static void  TC_Api_Emergy_Get_FuelConsumptionPer1km(void)
{
     TC_Energy_data_current.FuelConsumptionPer1km=TC_Pkg_Accumulatior_Energy_Fuel_get();
}

/**********************************************************************************************************
*Function   : TC_Api_Emergy_Get_SYS_DATA_Per1km                                                           *
*                                                                                                         *
*Description:  Get UTC And ODO                                                                            *
*Parameter	:  void       																	              *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: shu junhua                                                                                  *
*                                                                                                         *
*Date       : 2020-2-7                                                                                    *
**********************************************************************************************************/
static void  TC_Api_Emergy_Get_SYS_DATA_Per1km(void)
{
    TC_EMERGY_SYS_LOG_t tc_emergy_sys_log_temp=TC_Api_Rte_Get_SYS_Data();
    TC_Energy_data_current.CalendarPer1km=tc_emergy_sys_log_temp.time; 
    TC_Energy_data_current.VehDistance= tc_emergy_sys_log_temp.Curodo; 
}

static void  TC_Api_Emergy_Get_NewchargePer1km(void)
{
    TC_Energy_data_current.NewChargeCyclePer1km=(uint8)TC_Api_Phev_New_Charge_Status_get();   
}


/**********************************************************************************************************
*Function   : TC_Api_Emergy_Get_TripNotSentPer1km                                                         *
*                                                                                                         *
*Description:  Before switching to a new charging cycle Instrument not sent IVI The mileage  	          *
*                                                                                                         *
*Parameter	:  value "unit 1m"        													              *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: shu junhua                                                                                  *
*                                                                                                         *
*Date       : 2020-1-4                                                                                    *
**********************************************************************************************************/

static void  TC_Api_Emergy_Get_TripNotSentPer1km(uint16 value )
{
    /*
    0x0000
    0x3 E8 0 1000 m
    0x3E9 0x3FF Invalid
    Factor: 1
    Offset: 0
    */
    TC_Energy_data_current.TripNotSentPer1km=value;
}

static void TC_Api_Emergy_Reset_All(void)
{
    TC_Pkg_Accumulatior_Energy_Fuel_Reset();
    TC_Pkg_Phev_RecupPwr_Reset();
    TC_Pkg_Phev_Egyued_Reset();
}

static void TC_Api_Emergy_Update_All(void)
{   
   /* The total amount of fuel injection  */
    TC_Api_Emergy_Get_FuelConsumptionPer1km(); 
   /* The total amount of  power consumption*/
    TC_Api_Emergy_Get_EgyUsedPer1km();
   /* The total amount of Energy recovery */
    TC_Api_Emergy_Get_EgyRecupPwrPer1km();     
   /* The total amount of UTC and Odo */
    TC_Api_Emergy_Get_SYS_DATA_Per1km();
   /* The total amount of charging cycles */
    TC_Api_Emergy_Get_NewchargePer1km();
   /* clear current buf data */
    TC_Api_Emergy_Reset_All();
}

static void TC_Api_Emergy_Cold_Init(void)
{
    (void)memset(&TC_Energy_data_current,0,sizeof(TC_Energy_data_current));
    (void)memset(&TC_Energy_data,0,sizeof(TC_Energy_data));
    TC_Energy_data.TC_Energy_Cal_Odo=TC_Api_Rte_Get_Odo_value();//TC_Pkg_Get_Phev_Trip_Value();
}

static void TC_Api_Emergy_Warm_Init(void)
{
	TC_Energy_data.TC_Energy_Cal_Odo=TC_Api_Rte_Get_Odo_value();//TC_Pkg_Get_Phev_Trip_Value();
}

void TC_Api_Emergy_update_mode_set(TC_ENERGY_UPDATE_MODE mode)
{
	TC_Energy_data.TC_Energy_update_mode=mode;
}
TC_ENERGY_UPDATE_MODE TC_Api_Emergy_update_mode_get(void)
{
	return TC_Energy_data.TC_Energy_update_mode;
}
/**********************************************************************************************************
*Function   : TC_Api_Emergy_Get_IVI_Alive_Respone                                                         *
*                                                                                                         *
*Description: IPC_IVI periodically detects the response status of IVI activation and data reception       *
*                                                                                                         *
*Parameter	: EnergyInfoDataTypeId 0:Resp;1:alive											              *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: shu junhua                                                                                  *
*                                                                                                         *
*Date       : 2021-03-08                                                                                  *
**********************************************************************************************************/
void TC_Api_Emergy_Get_IVI_Alive_Respone(uint8 EnergyInfoDataTypeId,uint8 *Ividata)
{

    if(EnergyInfoDataTypeId ==TC_ENERGY_PER_1KM )
    {
        TC_Energy_data.TC_Energy_Ivi_Alive= *Ividata ;
    }
    else if (EnergyInfoDataTypeId ==TC_ENERGY_RESP )
    {
        TC_Energy_data.TC_Energy_Ivi_Respone= *Ividata ;
    }
    else
    {
    // do noting 
    }
}
/**********************************************************************************************************
*Function   : TC_App_Emergy_cal_task                                                                      *
*                                                                                                         *
*Description: Periodically check mileage updates and Insert New data to queue                             *
*                                                                                                         *
*Parameter	: NONE                      													              *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: shu junhua                                                                                  *
*                                                                                                         *
*Date       : 2021-03-08                                                                                  *
**********************************************************************************************************/
void TC_App_Emergy_cal_task(void)
{ 
    //uint32 TripNotSend=0;
    //uint64 tc_phev_trip_current=TC_Pkg_Get_Phev_Trip_Value();
    uint32 tc_odo_current= TC_Api_Rte_Get_Odo_value();
    uint16 tc_emergy_trip_delt=0;
    //TC_EMERGY_SYS_LOG_t emergy_sys_data_temp=TC_Api_Rte_Get_SYS_Data();    
    if(TRUE ==TC_Api_Emergy_Accum_Enable())
    {

       if((TC_Energy_data.TC_Energy_Cal_Odo == 0XFFFFFF01)||(tc_odo_current == 0XFFFFFF01))
       {

            TC_Energy_data.TC_Energy_Cal_Odo =TC_Api_Rte_Get_Odo_value();
            tc_odo_current= TC_Api_Rte_Get_Odo_value();

       }
       else
       {
            tc_odo_current = TC_Api_Rte_Get_Odo_value();
            if(tc_odo_current > TC_Energy_data.TC_Energy_Cal_Odo)
            {
                tc_emergy_trip_delt = (uint16)(tc_odo_current - TC_Energy_data.TC_Energy_Cal_Odo);

            }
            else
            {
                tc_emergy_trip_delt =0;
            }
            TC_Api_Phev_Charge_check(tc_emergy_trip_delt);       
            if(tc_emergy_trip_delt>=TC_EMERGY_DATA_UPADTE_KM)/*1km upadte*/
            {  
               // TC_Energy_data.TC_Energy_Cal_Odo=tc_phev_trip_current;
               TC_Energy_data.TC_Energy_Cal_Odo = tc_odo_current;
                TC_Api_Emergy_update_mode_set(TC_ENERGY_1KM_UPDATE);
                TC_Api_Emergy_Update_All(); 
                TC_Api_Emergy_mq_sort(&TC_Energy_data_current); /*Insert New data to queue*/  
            }
            else
            {   

            }
           
       }
       
    }
    else
    {

    }
}

/*Periodically query if any data needs to be sent*/
void TC_App_Update_Emergy(void)
{  
    uint32 CalendarPer1km_1 = 0u; 
    uint32 CalendarPer1km_2 = 0u;
    TC_ENERGY_UPDATE_MODE emergy_mode_temp=TC_Api_Emergy_update_mode_get();
    if(TRUE==TC_Api_Emergy_Display_Enable())
    {
        if(TRUE==TC_Energy_data.TC_Energy_Ivi_Alive)
        {   
            if (TRUE!=TC_Api_Emergy_Queue_Null_Check())
            {
                switch (emergy_mode_temp)
                {
                    case TC_ENERGY_NONE_UPDATE:
                        break;
                    case TC_ENERGY_1KM_UPDATE:
                    case TC_ENERGY_5S_UPDATE:                
                        TC_Api_Emergy_Tx_Pro();
                        (void)TC_MODULE_DEBUG_INFO_warn("EMERGY1=%d,%d,%d,%d",TC_LOG_DTE_PERIOD1);
                        CalendarPer1km_1 = (uint32)((TC_Energy_data_current.CalendarPer1km&0xFFFFFFFF00000000)>>32); 
                        CalendarPer1km_2 = (uint32)(TC_Energy_data_current.CalendarPer1km&0x00000000FFFFFFFF);
                        (void)TC_MODULE_DEBUG_INFO_warn("EMERGY2=%d,%d",TC_LOG_DTE_PERIOD2);
                        (void)TC_MODULE_DEBUG_INFO_warn("EMERGY3=%d,%d",CalendarPer1km_1,CalendarPer1km_2);
                        (void)TC_MODULE_DEBUG_INFO_warn("tc_energy_mode=%d response=%d",emergy_mode_temp,IVI_RESP_SUCCESS);
                        TC_Api_Emergy_update_mode_set(TC_ENERGY_NONE_UPDATE);
                        break;
                    default:
                        (void)TC_MODULE_DEBUG_INFO_warn("SWITCH ERROR!");
                        break;
                }

                if((TC_Api_Sw_Timer_Check(TC_EMERGY_WAIT_RESPONSE)==TC_TIMER_RUNNING))
                {
                   if(0 == IVI_RESP_SUCCESS) /*negtive reponse */
                    {
                    
                    }
                    else/*active reponse */
                    {   
                        IVI_RESP_SUCCESS =0;
                        TC_Api_Emergy_mq0_clear();
                        TC_Api_Sw_timer_clear(TC_EMERGY_WAIT_5S);
                    }
                }
                else if((TC_Api_Sw_Timer_Check(TC_EMERGY_WAIT_RESPONSE)==TC_TIMER_EXPIRED)) /* transfer to ivi , wait 300ms reponse*/
                {    
                    TC_Api_Sw_timer_clear(TC_EMERGY_WAIT_RESPONSE);
                    // need to add check ivi response TBD 
                    if(0 == IVI_RESP_SUCCESS)  /*negtive reponse */
                    {    
                        if (TC_Api_Sw_Timer_Check(TC_EMERGY_WAIT_5S)==TC_TIMER_CLEAR)
                        {
                            TC_Api_Sw_timer_start(TC_EMERGY_WAIT_5S,TC_EMERGY_WAIT_5S_TIMER_NUM); /*1km */
                        }
                       
                    } 
                    else /*active reponse */
                    {   IVI_RESP_SUCCESS =0;
                        TC_Api_Emergy_mq0_clear();
                        TC_Api_Sw_timer_clear(TC_EMERGY_WAIT_5S);
                    }
                }
                else
                {
                // do nothing 
                }
                
                if (TC_Api_Sw_Timer_Check(TC_EMERGY_WAIT_5S)==TC_TIMER_EXPIRED) /* wait 5s timer is expired */
                {  
                    TC_Api_Sw_timer_clear(TC_EMERGY_WAIT_5S);
                    TC_Api_Emergy_update_mode_set(TC_ENERGY_5S_UPDATE); /* 5s update mode is setting  */
                }
                      
            }
            else
            {

            }
        }
        else
        {
        // do noting 
        }
          
        TC_Api_sw_timer_update();
    }
    else
    {
    }
   
}


#endif 


#define SWC_TC_STOP_SEC_CODE
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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



