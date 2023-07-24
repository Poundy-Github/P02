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
/**
 **********************************************************************************************************************
 * @file:      CPULoadMeasure.c
 * @author:    Nobo
 * @date:      2020-7-31
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-7-31
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#include "os.h"
#include "Rtm.h"
#include "string.h"
#include "logger.h"
#include "os_coreint.h"
#include <stdbool.h>

//#define CPU_CALCULATE_OS_TIME
#define CPU_LOAD_OUTPUT

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
} EM_BUFFER;
typedef struct
{
    uint16 cpu_load;                  
    uint16 task_load[OS_TASKID_COUNT];                 
    uint16 isr_load[OS_ISRID_COUNT];                 
} CPU_LOAD_BUFFER;

typedef struct
{
    uint8 task;                  
    uint16 task_time;                 
} TASK_LOAD_BUFFER;

#define EM_CYCLE_PERIOD  (50U)
#define EM_TIMER_COUNT_10S     	(10000UL/EM_CYCLE_PERIOD)
#define EM_TOTAL_TIME  (10000000UL/1000UL)

const Os_StackConfigRefType Task_StackRefs[OS_TASKID_COUNT] =
{
  (Os_StackConfigRefType) &OsCfg_Stack_BSW_COMM,
  (Os_StackConfigRefType) &OsCfg_Stack_BSW_DIAGNOSE,
  (Os_StackConfigRefType) &OsCfg_Stack_DRIVERS_SAFE,
  (Os_StackConfigRefType) &OsCfg_Stack_Default_BSW,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio50,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio49,
  (Os_StackConfigRefType) &OsCfg_Stack_FUEL_TC_ODO,
  (Os_StackConfigRefType) &OsCfg_Stack_GateWay,
  (Os_StackConfigRefType) &OsCfg_Stack_IPC,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio4294967295,
  (Os_StackConfigRefType) &OsCfg_Stack_SWC_LOW,
  (Os_StackConfigRefType) &OsCfg_Stack_SYS,
  (Os_StackConfigRefType) &OsCfg_Stack_TT_GEAR,
};

#if defined(CPU_LOAD_OUTPUT)
const char *taskNameArray[OS_TASKID_COUNT] =
{
  "BSW_COMM                 ",
  "BSW_DIAGNOSE             ",
  "DRIVERS_SAFE             ",
  "Default_BSW              ",
  "Default_Init_Task        ",
  "Default_Init_Task_Trusted",
  "FUEL_TC_ODO              ",
  "GateWay                  ",
  "IPC                      ",
  "IdleTask_OsCore0         ",
  "SWC_LOW                  ",
  "SYS                      ",
  "TT_GEAR                  "
};
#endif

#define Misc_START_SEC_VAR_INIT_UNSPECIFIED
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#ifdef CPU_CALCULATE_OS_TIME
static uint32 total_time_start, total_time_elapsed;
#endif 

static EM_BUFFER Task_em_buffer[OS_TASKID_COUNT];
static EM_BUFFER Isr_em_buffer[OS_ISRID_COUNT];
TaskType Curren_Task_Id = INVALID_TASK;
static ISRType Curren_Isr_Id = INVALID_ISR;
static uint32 Execute_Time_TaskTick=0;
static uint64 Execute_Time_Total=0;
static CPU_LOAD_BUFFER CPU_Load;
static boolean cpu_load_dbg = false;
extern uint8 Stack_Measure_Flag[OS_TASKID_COUNT+1];
extern uint8 Stack_Percent[OS_TASKID_COUNT+1];
extern VAR(Os_CoreAsrType, OS_VAR_NOINIT) OsCfg_Core_OsCore0_Dyn;

#ifdef TASK_RECORD
static TASK_LOAD_BUFFER task_record[50];
static uint8 task_record_index;
#endif 

#define Misc_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define TASK_END_CALCULATE(current_task_id)\
{\
\
	TM_TimerElapsed(&Task_em_buffer[current_task_id].time_stamp[0],&Task_em_buffer[current_task_id].time_stamp[1]);\
\
	Task_em_buffer[current_task_id].exeTime = Task_em_buffer[current_task_id].time_stamp[1]/10;/*uint : 1us*/\
\
	if(Task_em_buffer[current_task_id].max_exec_time < Task_em_buffer[current_task_id].exeTime)\
	{\
		Task_em_buffer[current_task_id].max_exec_time = Task_em_buffer[current_task_id].exeTime;\
	}\
\
	if(Task_em_buffer[current_task_id].min_exec_time > Task_em_buffer[current_task_id].exeTime)\
	{\
		Task_em_buffer[current_task_id].min_exec_time = Task_em_buffer[current_task_id].exeTime;\
	}\
\
	if((Task_em_buffer[current_task_id].tot_exec_time < (0xffffffff/2))&&(FALSE == Task_em_buffer[current_task_id].reset_buffer))\
	{\
		Task_em_buffer[current_task_id].tot_exec_time+= Task_em_buffer[current_task_id].exeTime;\
		Task_em_buffer[current_task_id].num_samples++;\
		Execute_Time_Total+= Task_em_buffer[current_task_id].exeTime;\
	}\
	else\
	{\
		Task_em_buffer[current_task_id].avg_exec_time = Task_em_buffer[current_task_id].tot_exec_time/Task_em_buffer[current_task_id].num_samples;\
		Task_em_buffer[current_task_id].tot_exec_time = Task_em_buffer[current_task_id].exeTime;\
		Task_em_buffer[current_task_id].num_samples = 1;\
		Task_em_buffer[current_task_id].reset_buffer = FALSE;\
	}\
\
}\

#define TASK_BEGIN_CALCULATE(current_task_id)	TM_TimerStartStamp(&Task_em_buffer[current_task_id].time_stamp[0]);

#define ISR_END_CALCULATE(current_isr_id)\
{\
\
	TM_TimerElapsed(&Isr_em_buffer[current_isr_id].time_stamp[0],&Isr_em_buffer[current_isr_id].time_stamp[1]);\
\
	Isr_em_buffer[current_isr_id].exeTime = Isr_em_buffer[current_isr_id].time_stamp[1]/10;/*uint : 1us*/\
\
	if(Isr_em_buffer[current_isr_id].max_exec_time < Isr_em_buffer[current_isr_id].exeTime)\
	{\
		Isr_em_buffer[current_isr_id].max_exec_time = Isr_em_buffer[current_isr_id].exeTime;\
	}\
\
	if(Isr_em_buffer[current_isr_id].min_exec_time > Isr_em_buffer[current_isr_id].exeTime)\
	{\
		Isr_em_buffer[current_isr_id].min_exec_time = Isr_em_buffer[current_isr_id].exeTime;\
	}\
\
	if((Isr_em_buffer[current_isr_id].tot_exec_time < (0xffffffff/2))&&(FALSE == Isr_em_buffer[current_isr_id].reset_buffer))\
	{\
		Isr_em_buffer[current_isr_id].tot_exec_time+= Isr_em_buffer[current_isr_id].exeTime;\
		Isr_em_buffer[current_isr_id].num_samples++;\
		Execute_Time_Total+= Isr_em_buffer[current_isr_id].exeTime;\
	}\
	else\
	{\
		Isr_em_buffer[current_isr_id].avg_exec_time = Isr_em_buffer[current_isr_id].tot_exec_time/Isr_em_buffer[current_isr_id].num_samples;\
		Isr_em_buffer[current_isr_id].tot_exec_time = Isr_em_buffer[current_isr_id].exeTime;\
		Isr_em_buffer[current_isr_id].num_samples = 1;\
		Isr_em_buffer[current_isr_id].reset_buffer = FALSE;\
	}\
\
}\

#define ISR_BEGIN_CALCULATE(current_isr_id)	TM_TimerStartStamp(&Isr_em_buffer[current_isr_id].time_stamp[0]);

#define OS_TASK_STACK_CALCULATE(task_id)\
		if((1 == Stack_Measure_Flag[task_id]) && (OsCfg_Core_OsCore0_Dyn.CurrentStack->LowAddress == Task_StackRefs[task_id]->LowAddress) && (OsCfg_Core_OsCore0_Dyn.CurrentStack->HighAddress == Task_StackRefs[task_id]->HighAddress))\
		{\
			Stack_Percent[task_id] = (uint8)(Os_GetTaskStackUsage(task_id) *100/StackMaxSize[task_id]);\
			Stack_Measure_Flag[task_id]=0xaa;\
		}\

#define OS_ISR_STACK_CALCULATE()\
		if(1 == Stack_Measure_Flag[OS_TASKID_COUNT])\
		{\
			Stack_Percent[OS_TASKID_COUNT] = (uint8)(Os_GetISRStackUsage((ISRType)0)*100/OS_CFG_SIZE_OSCORE0_ISR_CORE_STACK);\
			Stack_Measure_Flag[OS_TASKID_COUNT]=0xaa;\
		}\

#define Misc_START_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

void Misc_CPULoad_MainFunction(void);
void MISC_OS_Task_Execution_Init(void);
void MISC_OS_PreTask_Execution(void);
void MISC_OS_PostTask_Execution(void);
void MISC_OS_PreIsr_Execution(void);
void MISC_OS_PostIsr_Execution(void);

#define Misc_STOP_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern const uint32 StackMaxSize[OS_TASKID_COUNT];

extern FUNC(void, TM_CODE) TM_TimerElapsed(P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) StartStamp, P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) TimeElapsed);
extern FUNC(void, TM_CODE) TM_TimerStartStamp(P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) StartStamp);

#if defined(CPU_LOAD_OUTPUT)
static const char *getTaskName(TaskType id);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/


#define Misc_START_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

void Misc_CPULoad_MainFunction(void) 
{
	TaskType index;
	
	if(Execute_Time_TaskTick++>EM_TIMER_COUNT_10S)/*the accurate total time shall be get from TM module*/
	{
		SuspendAllInterrupts();
#ifdef CPU_CALCULATE_OS_TIME
		TM_TimerElapsed(&total_time_start,&total_time_elapsed);	
		total_time_elapsed = total_time_elapsed/10;

#endif		

		for( index = (TaskType)0 ; index < OS_TASKID_COUNT ; index++)
		{
			Task_em_buffer[index].reset_buffer = TRUE;
#ifdef CPU_CALCULATE_OS_TIME
			CPU_Load.task_load[index] = Task_em_buffer[index].tot_exec_time/(total_time_elapsed/1000);/*uint 0.1%*/			
#else
			CPU_Load.task_load[index] = Task_em_buffer[index].tot_exec_time/(Execute_Time_Total/1000);/*uint 0.1%*/ 		
#endif		
		}
		
#ifdef ISR_PREEMPTED
		for( index = (TaskType)0 ; index < OS_ISRID_COUNT ; index++)
		{
			Isr_em_buffer[index].reset_buffer = TRUE;			
			CPU_Load.isr_load[index] = Isr_em_buffer[index].tot_exec_time/(Execute_Time_Total/1000);/*uint 0.1%*/
		}
#endif		
		if(0 == Task_em_buffer[IdleTask_OsCore0].tot_exec_time)
		{
			CPU_Load.cpu_load = 1000;/*100%*/
		}
		else
		{
#ifdef CPU_CALCULATE_OS_TIME
			CPU_Load.cpu_load = (total_time_elapsed-Task_em_buffer[IdleTask_OsCore0].tot_exec_time)/(total_time_elapsed/1000);/*uint 0.1%*/
#else

			CPU_Load.cpu_load = (Execute_Time_Total-Task_em_buffer[IdleTask_OsCore0].tot_exec_time)/(Execute_Time_Total/1000);/*uint 0.1%*/
#endif		
			
		}
		Execute_Time_Total = 0;
		Execute_Time_TaskTick = 0;
#ifdef CPU_CALCULATE_OS_TIME
		TM_TimerStartStamp(&total_time_start);
#endif
		ResumeAllInterrupts();

		if (cpu_load_dbg == true)
		{
			for(index = (TaskType)0; index < OS_TASKID_COUNT; index++)
			{
				uint16 percent = (uint16)(CPU_Load.task_load[index] / 10U);
				uint16 fraction = (uint16)(CPU_Load.task_load[index] % 10U);
				misc_info("task %2d(%s) cpu load percent : %d.%d%%", index, getTaskName((TaskType)index), percent, fraction);
			}
			{
				uint16 percent = (uint16)(CPU_Load.cpu_load / 10U);
				uint16 fraction = (uint16)(CPU_Load.task_load[index] % 10U);
				misc_info("total cpu load percent : %d.%d%%", percent, fraction);
			}
		}

	}

}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MISC_OS_Task_Execution_Init(void)
{
		uint8 index;

		memset(&CPU_Load,0,sizeof(CPU_Load));
		for ( index = 0 ; index < OS_TASKID_COUNT ; index++)
		{
			Task_em_buffer[index].min_exec_time   = (uint32) 0xFFFFFFFFu;
			Task_em_buffer[index].max_exec_time   = 0;
			Task_em_buffer[index].avg_exec_time   = 0;
			Task_em_buffer[index].tot_exec_time   = 0;
			Task_em_buffer[index].num_samples	  = 0;
			Task_em_buffer[index].reset_buffer = TRUE;
		}
	
		for( index = 0u; index < OS_ISRID_COUNT; index++)
		{
			Isr_em_buffer[index].min_exec_time   = (uint32) 0xFFFFFFu;
			Isr_em_buffer[index].max_exec_time   = 0;
			Isr_em_buffer[index].avg_exec_time   = 0;
			Isr_em_buffer[index].tot_exec_time   = 0;
			Isr_em_buffer[index].num_samples	   = 0;
			Isr_em_buffer[index].reset_buffer = TRUE;		
		}
		Execute_Time_TaskTick=0;
		Execute_Time_Total=0;
#ifdef CPU_CALCULATE_OS_TIME
		
		TM_TimerStartStamp(&total_time_start);
#endif		
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MISC_OS_PreTask_Execution(void)
{

	TaskType task_id = INVALID_TASK;


	(void)GetTaskID(&task_id);
	TASK_BEGIN_CALCULATE(task_id)
	
	Curren_Task_Id = task_id;

}

/***********************************************************************
 * @brief       : post task hook will be called any time the operating system interrupts or terminates a task
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MISC_OS_PostTask_Execution(void)
{
	TaskType task_id;
	//ISRType isr_id;

	if(INVALID_TASK == Curren_Task_Id)
	{
		/*do nothing*/
	}
	else
	{		
		
		(void)GetTaskID(&task_id);

		if(task_id == Curren_Task_Id)
		{
			TASK_END_CALCULATE(task_id)			
			OS_TASK_STACK_CALCULATE(task_id)
		}
#ifdef TASK_RECORD
		task_record[task_record_index].task=Curren_Task_Id;		
		task_record[task_record_index++].task_time = Task_em_buffer[Curren_Task_Id].exeTime;
		if(task_record_index>=50)task_record_index = 0;
#endif
	}

}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MISC_OS_PreIsr_Execution(void)
{

	ISRType isr_id = INVALID_ISR;

	isr_id = GetISRID();

	if(isr_id == INVALID_ISR)
	{
	}
	else
	{
		ISR_BEGIN_CALCULATE(isr_id)
#ifdef ISR_PREEMPTED
		TASK_END_CALCULATE(Curren_Task_Id)		
#endif
	}
	
	Curren_Isr_Id = isr_id;

}

/***********************************************************************
 * @brief       : post task hook will be called any time the operating system interrupts or terminates a task
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MISC_OS_PostIsr_Execution(void)
{
	ISRType isr_id;

	if(INVALID_ISR == Curren_Isr_Id)
	{
		/*do nothing*/
	}
	else
	{		
		isr_id = GetISRID();

		if(isr_id == Curren_Isr_Id)
		{
			ISR_END_CALCULATE(isr_id)
			OS_ISR_STACK_CALCULATE()			
		}
		
	}
#ifdef ISR_PREEMPTED	
	TASK_BEGIN_CALCULATE(Curren_Task_Id)
#endif
	Curren_Isr_Id = INVALID_ISR;

}


void Rtm_Start(uint8 measurement_point)
{
	switch(measurement_point)
	{
		case RtmConf_RtmMeasurementPoint_Can_Init:
			break;
		case RtmConf_RtmMeasurementPoint_Can_SetControllerMode:
			break;
		case RtmConf_RtmMeasurementPoint_Can_Write:
			break;
		case RtmConf_RtmMeasurementPoint_CanInterruptRxFifo:
		case RtmConf_RtmMeasurementPoint_CanInterruptWakeup:
		case RtmConf_RtmMeasurementPoint_CanInterruptStatus:
		case RtmConf_RtmMeasurementPoint_CanInterruptGlobalStatus:
		case RtmConf_RtmMeasurementPoint_Interrupt_Callout:
			MISC_OS_PreIsr_Execution();
			break;
		default:
			/* nothing to do */
			break;
	}


}
void Rtm_Stop(uint8 measurement_point)
{
	switch(measurement_point)
	{
		case RtmConf_RtmMeasurementPoint_Can_Init:
			break;
		case RtmConf_RtmMeasurementPoint_Can_SetControllerMode:
			break;
		case RtmConf_RtmMeasurementPoint_Can_Write:
			break;
		case RtmConf_RtmMeasurementPoint_CanInterruptRxFifo:
		case RtmConf_RtmMeasurementPoint_CanInterruptWakeup:
		case RtmConf_RtmMeasurementPoint_CanInterruptStatus:
		case RtmConf_RtmMeasurementPoint_CanInterruptGlobalStatus:
		case RtmConf_RtmMeasurementPoint_Interrupt_Callout:
			MISC_OS_PostIsr_Execution();
			break;
		default:
			/* nothing to do */
			break;
	}

}

#if defined(CPU_LOAD_OUTPUT)
static const char *getTaskName(TaskType id)
{
	const char *name = NULL;

	if (id < OS_TASKID_COUNT)
	{
		name = taskNameArray[id];
	}

	return name;
}
#endif


void cpu_load_dbg_setting_cb(boolean val)
{
	cpu_load_dbg = val;
}

#define Misc_STOP_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */




