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
*File Name   : SM_Core.h                                                                                  *
*                                                                                                         *
*Description : Speedometer module core function head file.                                  		      *
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
#ifndef SM_CORE_H
#define SM_CORE_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
//#include "system.h"
#include "Compiler.h"
#include "Platform_Types.h"
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_SM_Config.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Speedometer Module Operation Structure																  *
*																								          *
*																								          *
**********************************************************************************************************/
typedef struct 
{
	boolean    (*boProcessPtr)(void);
	SM_CFG_enSYSTEM_STATUS  u32SucceedEnableStatus;
	SM_CFG_enSYSTEM_STATUS  u32FaildEnableStatus;
	void    (*AfterSucceedOperationPtr)(void);
	void    (*AfterFaildOperationPtr)(void);
	boolean    boContinueWhenFaild;
}SM_tstPROCESS;

#define SM_DO_NOTHING       (void *)0
#define SM_NOT_CONCERNED    ((boolean)1)//(TRUE)

typedef struct 
{
	boolean    	boStepUpIncludeEqualValue;
	uint16  	u32StepUpLimitValue;
	boolean    	boStepDownIncludeEqualValue;
	uint16  	u32StepDownLimitValue;
}SM_tstBAR_TBL;

/**********************************************************************************************************
*																								          *
*																								          *
*	Speedometer Module Core Function							    									  *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*Function   : SM_CORE_vProcessControl                                                                     *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#define Common_Normal_START_SEC_CODE
#include "Common_Normal_MemMap.h" 

void SM_CORE_vProcessControl(void* stProcessTable,SM_CFG_tstMAIN_OBJECT *stMainObject);

/**********************************************************************************************************
*Function   : SM_CORE_vFlagControl                                                                        *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
void SM_CORE_vFlagControl(SM_CFG_enFLAG_PROCESS_STAGE enFlagOperationOrder,SM_CFG_tstMAIN_OBJECT* stMainObject);

/**********************************************************************************************************
*Function   : SM_CORE_vSetSystemErrorStatus                                                               *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
void SM_CORE_vSetSystemErrorStatus(SM_CFG_enSYSTEM_STATUS enStatus,SM_CFG_tstMAIN_OBJECT* stMainObject);

/**********************************************************************************************************
*Function   : SM_CORE_vClearSystemErrorStatus                                                             *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
void SM_CORE_vClearSystemErrorStatus(SM_CFG_enSYSTEM_STATUS enStatus,SM_CFG_tstMAIN_OBJECT* stMainObject);

/**********************************************************************************************************
*Function   : SM_CORE_boCheckSystemErrorStatus                                                            *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
boolean SM_CORE_boCheckSystemErrorStatus(SM_CFG_enSYSTEM_STATUS enStatus,SM_CFG_tstMAIN_OBJECT* stMainObject);

/**********************************************************************************************************
*Function   : SM_CORE_u16CalulauteGaugeTableStepCounts                                                    *
*                                                                                                         *
*Description: TBD		                                                                                  *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: UINT16                                                                                      *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
uint16 SM_CORE_u16CalulauteGaugeTableStepCounts(uint16 *u16GaugeTable, uint16 u16LookUpValue);

#endif // ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : SM_CORE_boCheckGaugeTableProcess                                                            *
*                                                                                                         *
*Description: TBD		                                                                                  *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
boolean SM_CORE_boCheckGaugeTableProcess(uint16* u16GaugeTable);

#endif // ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : SM_CORE_u16CalulauteBarTableStepCounts                                                      *
*                                                                                                         *
*Description: TBD		                                                                                  *
*                                                                                                         *
*Parameter	: boUpDown : up is TRUE,down is FALSE                                                         *
*                                                                                                         *
*Return 	: UINT16                                                                                      *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)

uint16 SM_CORE_u16CalulauteBarTableStepCounts(void* u16BarTable, boolean boUpDown,uint16 u16LastBarValue,uint16 u16LookUpValue);

#endif // ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)
/**********************************************************************************************************
*Function   : SM_CORE_boCheckBarTableProcess                                                              *
*                                                                                                         *
*Description: TBD		                                                                                  *
*                                                                                                         *
*Parameter	: void* u16BarTable		                                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)

boolean SM_CORE_boCheckBarTableProcess(void* u16BarTable);

#endif // ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : SM_CORE_vCheckModuleConfigration                                                            *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if(SM_CFG_DEBUG == TRUE) 

void SM_CORE_vCheckModuleConfigration(void);

#endif
/**********************************************************************************************************
*Function   : SM_CORE__u16DampingModel_Thread                                                             *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if (SM_CFG_DAMPING_MODEL == SM_CFG_THREAD_DAMPING_MODEL)

void SM_CORE__u16DampingModel_Thread(uint16 *target, uint16 *current, uint16 u16Parameter);

#endif
/**********************************************************************************************************
*Function   : SM_CORE__u16DampingModel_kX_Plus_b                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: TBD		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if (SM_CFG_DAMPING_MODEL == SM_CFG_KX_PLUS_B_DAMPING_MODEL)
	
void SM_CORE__u16DampingModel_kX_Plus_b(uint16 *target, uint16 *current,SM_CFG_tstDAMPING_MODEL_KXPB_PARAMETER stParameter);

#endif
/**********************************************************************************************************
*Function   : SM_CORE__u16DampingModel_PID                                                                *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if (SM_CFG_DAMPING_MODEL == SM_CFG_PID_DAMPING_MODEL)

void SM_CORE__u16DampingModel_PID(uint16 *u16Target, uint16 *u16Current,SM_CFG_tstDAMPING_MODEL_PID_PARAMETER stParameter);

#endif
/**********************************************************************************************************
*Function   : SM_CORE__u16FormatDataAccuracy                                                              *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: TBD		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
uint16 SM_CORE__u16FormatDataAccuracy(uint16 u16RawMaximum, uint16 u16RawMinimum,uint16 u16Factor, sint16 s16Offset, boolean boRound , uint16 u16RawValue);
uint32 SM_CORE__u32FormatDataAccuracy(uint16 u16RawMaximum, uint16 u16RawMinimum,uint16 u16Factor, sint16 s16Offset, boolean boRound , uint32 u32RawValue);
#define Common_Normal_STOP_SEC_CODE
#include "Common_Normal_MemMap.h" 

/*********************************************************************************************************/
#endif //SM_CORE_H
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
