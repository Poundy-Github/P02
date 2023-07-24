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
*File Name   : CL_Interface.h                                                                             *
*                                                                                                         *
*Description : Coolant module application interface head file.                                        	  *
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
#ifndef CL_API_H
#define CL_API_H
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
*	Output Application Interface Accuary            													  *
**********************************************************************************************************/
typedef enum
{
  	ACCUACY_1C = 100,			//1C  0C - 143C
	ACCUACY_0_01C = 1			//0.01C  0C - 143C
}CL_API_enOUTPUT_ACCUACY;
	
/**********************************************************************************************************
*	Diagnostic Application Interface Status            													  *
**********************************************************************************************************/
typedef enum
{
	CL_ZERO_DIAL ,
	CL_HALF_DIAL ,
	CL_FULL_DIAL 
}CL_CFG_enDIAG_SET_GAUGE_STATUS;

/**********************************************************************************************************
*Function   : CL_API_vKSSlowRate_Task                                                                     *
*                                                                                                         *
*Description: The functions is called by DI-kernel at slow rate task list at cycle 40ms.                  *
*			  which is the main handling task of coolant module at different working mode                 *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/

#define SWC_CL_START_SEC_CODE
#include "SWC_CL_MemMap.h" 

void CL_API_vKSTimeTask(void);

/**********************************************************************************************************
*Function   : CL_API_vKSRoundRobin_Task                                                                   *
*                                                                                                         *
*Description: The function is called by DI-kernel at round-robin task list. if it used,can fill  it with  *
*             code.                                                                                       *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
void CL_API_vKSRoundRobinTask(void);

/**********************************************************************************************************
*Function   : CL_API_vKSColdInit                                                                          *
*                                                                                                         *
*Description: The function is called by DI-kernel at cold init task list,which do global variables        *
*			  initialization and flags clearing                                                           *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
void CL_API_vKSColdInit(void);

/**********************************************************************************************************
*Function   : CL_API_vKSWarmInit                                                                          *
*                                                                                                         *
*Description: The function is called by DI-kernel at warm init task list,which do global variables        *
*			  initialization and flags clearing                                                           *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
void CL_API_vKSWarmInit(void);

/**********************************************************************************************************
*Function   : CL_API_vKSWakeUp                                                                            *
*                                                                                                         *
*Description: The function is called by DI-kernel at wake up task list,which do global variables          *
*			  initialization and flags clearing                                                           *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if 0
void CL_API_vKSWakeUp(void);
#endif
/**********************************************************************************************************
*Function   : CL_API_vKSSleep                                                                             *
*                                                                                                         *
*Description: The function is called by DI-kernel at sleep task list,which do global variables            *
*			  initialization and flags clearing                                                           *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if 0
void CL_API_vKSSleep(void);
#endif
/**********************************************************************************************************
*Function   : CL_API_vKSEnterAbnormalOperation                                                            *
*                                                                                                         *
*Description: The function is called by Power management module to do operation when trans into abnormal  *
*             state from normal/limited mode                                                              *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
void CL_API_vKSEnterAbnormalOperation(void);

/**********************************************************************************************************
*Function   : CL_API_vKSExitAbnormalOperation                                                             *
*                                                                                                         *
*Description: The function is called by Power management module to do operation when MCU exits the        *
*             abnormal mode                                                                               *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
void CL_API_vKSExitAbnormalOperation(void);
/**********************************************************************************************************
*Function   : CL_API_u16GetRealEngineTemperature                                                          *
*                                                                                                         *
*Description: The function to get real engine temperature by other application modules                    *
*			                                                                                              *
*Parameter	: accuacy selection of output		                                                          *
*                                                                                                         *
*Return 	: SINT16                                                                                      *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
sint16 CL_API_s16GetRealEngineTemperature(CL_API_enOUTPUT_ACCUACY enAccuacy);

/**********************************************************************************************************
*Function   : CL_API_u16GetCurrentIndicateEngineTemperature                                               *
*                                                                                                         *
*Description: The function to get current indicate engine temperature by other application modules        *
*			                                                                                              *
*Parameter	: accuacy selection of output		                                                          *
*                                                                                                         *
*Return 	: UINT16                                                                                      *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
uint16 CL_API_u16GetCurrentIndicateEngineTemperature(CL_API_enOUTPUT_ACCUACY enAccuacy);

/**********************************************************************************************************
*Function   : CL_API_u16GetGaugeParkCounts                                                                *
*                                                                                                         *
*Description: The function is get park counts for stepper motor driver                                    *
*			                                                                                              *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)

uint16 CL_API_u16GetGaugeParkCounts(void);

#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : CL_API_u16GetGaugeMaxCounts                                                                 *
*                                                                                                         *
*Description: The function get max counts for stepper motor driver                                        *
*			                                                                                              *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
uint16 CL_API_u16GetGaugeMaxCounts(void);

#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : CL_API_u16GetGaugeTargetStepCounts                                                          *
*                                                                                                         *
*Description: The function get max counts for stepper motor driver                                        *
*			                                                                                              *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
uint16 CL_API_u16GetGaugeTargetStepCounts(void);

#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : CL_API_u16GetGaugeCurrentStepCounts                                                         *
*                                                                                                         *
*Description: The function get max counts for stepper motor driver                                        *
*			                                                                                              *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
uint16 CL_API_u16GetGaugeCurrentStepCounts(void);

#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : CL_API_vDiagSetGaugeStatus                                                                  *
*                                                                                                         *
*Description: The function is used to set gauge status from diagnostic module		                      *
*                                                                                                         *
*Parameter	: (CL_CFG_enDIAG_SET_GAUGE_STATUS)enStatus			                  						  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
void CL_API_vDiagSetGaugeStatus(CL_CFG_enDIAG_SET_GAUGE_STATUS enStatus);

#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : CL_API_vEOLSetGaugeStepCounts                                                               *
*                                                                                                         *
*Description: The function is used to set gauge step counts from EOL module		                          *
*                                                                                                         *
*Parameter	: (UINT16) u16TargetStepCounts		                                                          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
void CL_API_vEOLSetGaugeStepCounts(uint16 u16TargetStepCounts);

#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : CL_API_u16GetBarTargetStepCounts                                                            *
*                                                                                                         *
*Description: The function is get bar target step count by other application modules                      *
*			                                                                                              *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)
	
uint16 CL_API_u16GetBarTargetStepCounts(void);

#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)
/**********************************************************************************************************
*Function   : CL_API_u16GetBarCurrenttStepCounts                                                          *
*                                                                                                         *
*Description: The function is get bar current step count by other application modules                     *
*			                                                                                              *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)
	
uint16 CL_API_u16GetBarCurrentStepCounts(void);

#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)	
/**********************************************************************************************************
*																								          *
*																								          *
*	Coolant Custom Application Interface													          *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*Function   : CL_API_boGetCoolantCANMessageInvalidStatus                                                  *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void                                                                                        *
*                                                                                                         *
*Return 	: BOOL 0 is invalid,1 is valid                                                                *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
boolean CL_API_boGetCoolantCANMessageInvalidStatus(void);


#define SWC_CL_STOP_SEC_CODE
#include "SWC_CL_MemMap.h" 

/*********************************************************************************************************/
#endif //CL_API_H
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
