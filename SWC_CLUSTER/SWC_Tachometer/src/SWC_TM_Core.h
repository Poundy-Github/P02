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
*File Name   : TM_Core.h                                                                                  *
*                                                                                                         *
*Description : Tachometer module core function head file.                                     		      *
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
#ifndef TM_CORE_H
#define TM_CORE_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_TM_Config.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Tachometer Module Operation Structure																  *
*																								          *
*																								          *
**********************************************************************************************************/
typedef struct 
{
	boolean    (*boProcessPtr)(void);
	TM_CFG_enSYSTEM_STATUS  u32SucceedEnableStatus;
	TM_CFG_enSYSTEM_STATUS  u32FaildEnableStatus;
	void    (*AfterSucceedOperationPtr)(void);
	void    (*AfterFaildOperationPtr)(void);
	boolean    boContinueWhenFaild;
}TM_tstPROCESS;

#define TM_DO_NOTHING       (void *)0
#define TM_NOT_CONCERNED    ((boolean)1)//(TRUE)

typedef struct 
{
	boolean    boStepUpIncludeEqualValue;
	uint16     u32StepUpLimitValue;
	boolean    boStepDownIncludeEqualValue;
	uint16     u32StepDownLimitValue;
}TM_tstBAR_TBL;

/**********************************************************************************************************
*																								          *
*																								          *
*	Tachometer Module Core Function							    									      *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*Function   : TM_CORE_vProcessControl                                                                     *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#define SWC_TM_START_SEC_CODE
#include "SWC_TM_MemMap.h" 

void TM_CORE_vProcessControl(void* stProcessTable,TM_CFG_tstMAIN_OBJECT *stMainObject);

/**********************************************************************************************************
*Function   : TM_CORE_vFlagControl                                                                        *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
void TM_CORE_vFlagControl(TM_CFG_enFLAG_PROCESS_STAGE enFlagOperationOrder,TM_CFG_tstMAIN_OBJECT* stMainObject);

/**********************************************************************************************************
*Function   : TM_CORE_vSetSystemErrorStatus                                                               *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
void TM_CORE_vSetSystemErrorStatus(TM_CFG_enSYSTEM_STATUS enStatus,TM_CFG_tstMAIN_OBJECT* stMainObject);

/**********************************************************************************************************
*Function   : TM_CORE_vClearSystemErrorStatus                                                             *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
void TM_CORE_vClearSystemErrorStatus(TM_CFG_enSYSTEM_STATUS enStatus,TM_CFG_tstMAIN_OBJECT* stMainObject);

/**********************************************************************************************************
*Function   : TM_CORE_boCheckSystemErrorStatus                                                            *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
boolean TM_CORE_boCheckSystemErrorStatus(TM_CFG_enSYSTEM_STATUS enStatus,TM_CFG_tstMAIN_OBJECT* stMainObject);

/**********************************************************************************************************
*Function   : TM_CORE_u16CalulauteGaugeTableStepCounts                                                    *
*                                                                                                         *
*Description: TBD		                                                                                  *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: UINT16                                                                                      *
*                                                                                                         *
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
uint16 TM_CORE_u16CalulauteGaugeTableStepCounts(uint16 *u16GaugeTable, uint16 u16LookUpValue);

#endif // ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : TM_CORE_boCheckGaugeTableProcess                                                            *
*                                                                                                         *
*Description: TBD		                                                                                  *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
boolean TM_CORE_boCheckGaugeTableProcess(uint16* u16GaugeTable);

#endif // ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : TM_CORE_u16CalulauteBarTableStepCounts                                                      *
*                                                                                                         *
*Description: TBD		                                                                                  *
*                                                                                                         *
*Parameter	: boUpDown : up is TRUE,down is FALSE                                                         *
*                                                                                                         *
*Return 	: UINT16                                                                                      *
*                                                                                                         *
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)

uint16 TM_CORE_u16CalulauteBarTableStepCounts(void* u16BarTable, boolean boUpDown,uint16 u16LastBarValue,uint16 u16LookUpValue);

#endif // ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)
/**********************************************************************************************************
*Function   : TM_CORE_boCheckBarTableProcess                                                              *
*                                                                                                         *
*Description: TBD		                                                                                  *
*                                                                                                         *
*Parameter	: void* u16BarTable		                                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)

boolean TM_CORE_boCheckBarTableProcess(void* u16BarTable);

#endif // ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : TM_CORE_vCheckModuleConfigration                                                            *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if(TM_CFG_DEBUG == TRUE) 

void TM_CORE_vCheckModuleConfigration(void);

#endif
/**********************************************************************************************************
*Function   : TM_CORE__u16DampingModel_Thread                                                             *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((TM_CFG_DAMPING_MODEL == TM_CFG_THREAD_DAMPING_MODEL)||(TM_CFG_ANTI_DITHER_MODE != TM_CFG_NO_ANTI_DITHER_MODE))

void TM_CORE__u16DampingModel_Thread(uint16 *target, uint16 *current, uint16 u16Parameter);

#endif
/**********************************************************************************************************
*Function   : TM_CORE__u16DampingModel_kX_Plus_b                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: TBD		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if (TM_CFG_DAMPING_MODEL == TM_CFG_KX_PLUS_B_DAMPING_MODEL)
	
void TM_CORE__u16DampingModel_kX_Plus_b(uint16 *u16Target, uint16 *u16Current,TM_CFG_tstDAMPING_MODEL_KXPB_PARAMETER stParameter);

#endif
/**********************************************************************************************************
*Function   : TM_CORE__u16DampingModel_PID                                                                *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if (TM_CFG_DAMPING_MODEL == TM_CFG_PID_DAMPING_MODEL)

void TM_CORE__u16DampingModel_PID(uint16 *u16Target, uint16 *u16Current,TM_CFG_tstDAMPING_MODEL_PID_PARAMETER stParameter);

#endif
/**********************************************************************************************************
*Function   : TM_CORE__u16DampingModel_kX_Plus_b                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: TBD                                                                                         *
*                                                                                                         *
*Return 	: UINT16                                                                                      *
*                                                                                                         *
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if (TM_CFG_LOW_ACCURACY_OUTPUT_USE_ROUND_HYSTERESIS == TRUE)

uint16 TM_CORE__u16LowAccuaryOutputHysteresis(uint16 u16RawValue,uint16 u16Accuary);

#endif
/**********************************************************************************************************
*Function   : TM_CORE__u16FormatDataAccuracy                                                              *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: TBD		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
uint16 TM_CORE__u16FormatDataAccuracy(uint16 u16RawMaximum, uint16 u16RawMinimum,uint16 u16Factor, sint16 s16Offset, boolean boRound , uint16 u16RawValue);

#define SWC_TM_STOP_SEC_CODE
#include "SWC_TM_MemMap.h" 

/*********************************************************************************************************/
#endif //TM_CORE_H
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
