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
*File Name   : CL_Core.h                                                                                  *
*                                                                                                         *
*Description : Coolant module core function head file.                                  		      	  *
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
#ifndef CL_CORE_H
#define CL_CORE_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_CL_Config.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Coolant Module Operation Structure																  *
*																								          *
*																								          *
**********************************************************************************************************/
typedef struct 
{
	boolean    (*boProcessPtr)(void);
	CL_CFG_enSYSTEM_STATUS  u32SucceedEnableStatus;
	CL_CFG_enSYSTEM_STATUS  u32FaildEnableStatus;
	void    (*AfterSucceedOperationPtr)(void);
	void    (*AfterFaildOperationPtr)(void);
	boolean    boContinueWhenFaild;
}CL_tstPROCESS;

#define CL_DO_NOTHING       (void *)0
#define CL_NOT_CONCERNED    (TRUE)

typedef struct 
{
	boolean    boStepUpIncludeEqualValue;
	uint16     u32StepUpLimitValue;
	boolean    boStepDownIncludeEqualValue;
	uint16     u32StepDownLimitValue;
}CL_tstBAR_TBL;

/**********************************************************************************************************
*																								          *
*																								          *
*	Coolant Module Core Function							    									  *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*Function   : CL_CORE_vProcessControl                                                                     *
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
#define SWC_CL_START_SEC_CODE
#include "SWC_CL_MemMap.h" 

void CL_CORE_vProcessControl(void* stProcessTable,CL_CFG_tstMAIN_OBJECT *stMainObject);

/**********************************************************************************************************
*Function   : CL_CORE_vFlagControl                                                                        *
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
void CL_CORE_vFlagControl(CL_CFG_enFLAG_PROCESS_STAGE enFlagOperationOrder,CL_CFG_tstMAIN_OBJECT* stMainObject);

/**********************************************************************************************************
*Function   : CL_CORE_vSetSystemErrorStatus                                                               *
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
void CL_CORE_vSetSystemErrorStatus(CL_CFG_enSYSTEM_STATUS enStatus,CL_CFG_tstMAIN_OBJECT* stMainObject);

/**********************************************************************************************************
*Function   : CL_CORE_vClearSystemErrorStatus                                                             *
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
void CL_CORE_vClearSystemErrorStatus(CL_CFG_enSYSTEM_STATUS enStatus,CL_CFG_tstMAIN_OBJECT* stMainObject);

/**********************************************************************************************************
*Function   : CL_CORE_boCheckSystemErrorStatus                                                            *
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
boolean CL_CORE_boCheckSystemErrorStatus(CL_CFG_enSYSTEM_STATUS enStatus,CL_CFG_tstMAIN_OBJECT* stMainObject);

/**********************************************************************************************************
*Function   : CL_CORE_u16CalulauteGaugeTableStepCounts                                                    *
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
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
uint16 CL_CORE_u16CalulauteGaugeTableStepCounts(uint16 *u16GaugeTable, uint16 u16LookUpValue);

#endif // ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : CL_CORE_boCheckGaugeTableProcess                                                            *
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
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
boolean CL_CORE_boCheckGaugeTableProcess(uint16* u16GaugeTable);

#endif // ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : CL_CORE_u16CalulauteBarTableStepCounts                                                      *
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
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)

uint16 CL_CORE_u16CalulauteBarTableStepCounts(void* u16BarTable, boolean boUpDown,uint16 u16LastBarValue,uint16 u16LookUpValue);

#endif // ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)
/**********************************************************************************************************
*Function   : CL_CORE_boCheckBarTableProcess                                                              *
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
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)

boolean CL_CORE_boCheckBarTableProcess(void* u16BarTable);

#endif // ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : CL_CORE_vCheckModuleConfigration                                                            *
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
#if(CL_CFG_DEBUG == TRUE) 

void CL_CORE_vCheckModuleConfigration(void);

#endif
/**********************************************************************************************************
*Function   : CL_CORE__u16DampingModel_Thread                                                             *
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
#if (CL_CFG_DAMPING_MODEL == CL_CFG_THREAD_DAMPING_MODEL)

void CL_CORE__u16DampingModel_Thread(uint16 *target, uint16 *current, uint16 u16Parameter);

#endif
/**********************************************************************************************************
*Function   : CL_CORE__u16DampingModel_kX_Plus_b                                                          *
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
#if (CL_CFG_DAMPING_MODEL == CL_CFG_KX_PLUS_B_DAMPING_MODEL)
	
void CL_CORE__u16DampingModel_kX_Plus_b(uint16 *target, uint16 *current,uint16 u16ParameterK1, uint16 u16ParameterK2, uint16 u16ParameterB);

#endif
/**********************************************************************************************************
*Function   : CL_CORE__s16FormatDataAccuracy                                                              *
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
sint16 CL_CORE__s16FormatDataAccuracy(sint16 s16RawMaximum, sint16 s16RawMinimum,uint16 u16Factor, sint16 s16Offset, boolean boRound , sint16 s16RawValue);

#define SWC_CL_STOP_SEC_CODE
#include "SWC_CL_MemMap.h" 

/*********************************************************************************************************/
#endif //CL_CORE_H
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
