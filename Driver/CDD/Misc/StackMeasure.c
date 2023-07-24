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
 * @file:      StackMeasure.c
 * @author:    Nobo
 * @date:      2020-7-23
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-7-23
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


#include "logger.h"
#include "os.h"
#include "os_stack_cfg.h"



#define STACK_CYCLE_PERIOD  (50U)
#define STACK_TIMER_COUNT_100S    (100000UL/STACK_CYCLE_PERIOD)


#define Misc_START_SEC_VAR_INIT_UNSPECIFIED
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static uint32 stack_TaskTick=0;
static boolean Stack_Usage_Enable = FALSE;
static uint32 Stack_Time = STACK_TIMER_COUNT_100S;
uint8 Stack_Measure_Flag[OS_TASKID_COUNT+1];
uint8 Stack_Percent[OS_TASKID_COUNT+1];

#define Misc_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define Misc_START_SEC_CONST_UNSPECIFIED
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

const uint32 StackMaxSize[OS_TASKID_COUNT] =
{
	OS_CFG_SIZE_BSW_COMM_STACK,
	OS_CFG_SIZE_BSW_DIAGNOSE_STACK,
	OS_CFG_SIZE_DRIVERS_SAFE_STACK,     	
	OS_CFG_SIZE_DEFAULT_BSW_STACK,     	
	OS_CFG_SIZE_OSCORE0_TASK_PRIO50_STACK,
	OS_CFG_SIZE_OSCORE0_TASK_PRIO49_STACK,
	OS_CFG_SIZE_FUEL_TC_ODO_STACK,  
	OS_CFG_SIZE_GATEWAY_STACK,     	
	OS_CFG_SIZE_IPC_STACK,  
	OS_CFG_SIZE_OSCORE0_TASK_PRIO4294967295_STACK,
	OS_CFG_SIZE_SWC_LOW_STACK,     	
	OS_CFG_SIZE_SYS_STACK,     	
	OS_CFG_SIZE_TT_GEAR_STACK,    	

};

#define Misc_STOP_SEC_CONST_UNSPECIFIED
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define Misc_START_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

void OS_Task_Stack_Usage(void);
void OS_Stack_Usage_Init(void);

#define Misc_STOP_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

		
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


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void OS_Task_Stack_Usage(void)
{
	uint8 id;
	
	for(id=0;id < OS_TASKID_COUNT;id++)
	{
		if(Stack_Usage_Enable == TRUE)
		{
			if(0xaa == Stack_Measure_Flag[id])
			{	misc_info("task %d stack percent : %d%%" , id , Stack_Percent[id]);}
		}
		Stack_Measure_Flag[id]=1;
	}

	if(Stack_Usage_Enable == TRUE)
	{
		if(0xaa == Stack_Measure_Flag[id])
		{	misc_info("isr stack percent : %d%%" , Stack_Percent[OS_TASKID_COUNT]);}
	}
	Stack_Measure_Flag[OS_TASKID_COUNT]=1;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void OS_Stack_Usage_Init(void)
{
	uint8 id;
	
	for(id=0;id < OS_TASKID_COUNT;id++)
	{	
		Stack_Measure_Flag[id]=0;
	}

	Stack_Measure_Flag[OS_TASKID_COUNT]=0;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MISC_OS_Stack_Usage(void)
{
	if(stack_TaskTick++>Stack_Time)
	{
		OS_Task_Stack_Usage();
		stack_TaskTick = 0;
	}

}

void OS_Stack_Usage_setting_cb(boolean val, uint32 time)
{
	Stack_Usage_Enable = val;
	Stack_Time = time*(1000 / STACK_CYCLE_PERIOD);
}

#define Misc_STOP_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



