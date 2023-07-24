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
*File Name   : TM_Interface.h                                                                             *
*                                                                                                         *
*Description : Tachometer module application interface source file.                                       *
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
#ifndef TM_API_H
#define TM_API_H
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
*	Output Application Interface Accuary            													  *
**********************************************************************************************************/
typedef enum
{				
  	ACCUACY_1RPM = 1,		//1RPM
  	ACCUACY_100RPM = 100,	//100RPM
}TM_API_enOUTPUT_ACCUACY;

typedef enum
{
	ENGINE_STOP = 0,
	ENGINE_RUNNING
}TM_API_enENGINE_RUNNING_STATUS;

typedef enum
{
   TM_CLUSTER_SLEEP    = 1,
   TM_CLUSTER_OFF      = 2,
   TM_CLUSTER_NORMAL   = 4,
   TM_CLUSTER_ABNORMAL = 8,
   TM_CLUSTER_MAX      = 16
}TM_POWER_MODE;

/**********************************************************************************************************
*	Diagnostic Application Interface Status            													  *
**********************************************************************************************************/
typedef enum
{
	TM_ZERO_DIAL ,
	TM_HALF_DIAL ,
	TM_FULL_DIAL 
}TM_CFG_enDIAG_SET_GAUGE_STATUS;

/**********************************************************************************************************
*Function   : TM_API_vKSTimeTask                                                                          *
*                                                                                                         *
*Description: The functions is called by DI-kernel at time task list at cycle 40ms.                       *
*			  which is the main handling task of speedometer module at different working mode             *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#define SWC_TM_START_SEC_CODE
#include "SWC_TM_MemMap.h" 

void TM_API_vKSTimeTask(void);

/**********************************************************************************************************
*Function   : TM_API_vKSRoundRobin_Task                                                                   *
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
void TM_API_vKSRoundRobinTask(void);

/**********************************************************************************************************
*Function   : TM_API_vKSColdInit                                                                          *
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
void TM_API_vKSColdInit(void);

/**********************************************************************************************************
*Function   : TM_API_vKSWarmInit                                                                          *
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
void TM_API_vKSWarmInit(void);

/**********************************************************************************************************
*Function   : TM_API_vKSWakeUp                                                                            *
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
void TM_API_vKSWakeUp(void);
#endif
/**********************************************************************************************************
*Function   : TM_API_vKSSleep                                                                             *
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
void TM_API_vKSSleep(void);
#endif
/**********************************************************************************************************
*Function   : TM_API_vKSEnterAbnormalOperation                                                            *
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
void TM_API_vKSEnterAbnormalOperation(void);

/**********************************************************************************************************
*Function   : TM_API_vKSExitAbnormalOperation                                                             *
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
void TM_API_vKSExitAbnormalOperation(void);
/**********************************************************************************************************
*Function	: TM_API_vCANMessageCountProcess 														  *
*																										  *
*Description: TBD																						  *
*																										  *
*Parameter	: void																						  *
*																										  *
*Return 	: void																						  *
*																										  *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)

void TM_API_vCANMessageCountProcess(void);

#endif
/**********************************************************************************************************
*Function   : TM_API_u16GetTargetEngineSpeed                                                              *
*                                                                                                         *
*Description: The function to get target engine speed by other application modules                        *
*			                                                                                              *
*Parameter	: void                       		                                                          *
*                                                                                                         *
*Return 	: Target engine speed                                                                         *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
uint16 TM_API_u16GetTargetEngineSpeed(TM_API_enOUTPUT_ACCUACY enAccuacy);

/**********************************************************************************************************
*Function   : TM_API_u16GetCurrentEngineSpeed                                                             *
*                                                                                                         *
*Description: The function to get current engine speed by other application modules                       *
*			                                                                                              *
*Parameter	: void                        			                                                      *
*                                                                                                         *
*Return 	: Current engine speed                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
uint16 TM_API_u16GetCurrentEngineSpeed(TM_API_enOUTPUT_ACCUACY enAccuacy);

/**********************************************************************************************************
*Function   : TM_API_u16GetValidEngineSpeed                                                               *
*                                                                                                         *
*Description: The function to get Valid engine speed by other application modules                         *
*			                                                                                              *
*Parameter	: void                       		                                                          *
*                                                                                                         *
*Return 	: Target engine speed                                                                         *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
uint16 TM_API_u16GetValidEngineSpeed(TM_API_enOUTPUT_ACCUACY enAccuacy);

/**********************************************************************************************************
*Function   : TM_API_u16GetGaugeParkCounts                                                                *
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
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)

uint16 TM_API_u16GetGaugeParkCounts(void);

#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : TM_API_u16GetGaugeMaxCounts                                                                 *
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
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
uint16 TM_API_u16GetGaugeMaxCounts(void);

#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : TM_API_u16GetGaugeTargetStepCounts                                                          *
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
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
uint16 TM_API_u16GetGaugeTargetStepCounts(void);

#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : TM_API_u16GetGaugeCurrentStepCounts                                                         *
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
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
uint16 TM_API_u16GetGaugeCurrentStepCounts(void);

#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : TM_API_vDiagSetGaugeStatus                                                                  *
*                                                                                                         *
*Description: The function is used to set gauge status from diagnostic module		                      *
*                                                                                                         *
*Parameter	: (TM_CFG_enDIAG_SET_GAUGE_STATUS)enStatus			                  						  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
void TM_API_vDiagSetGaugeStatus(TM_CFG_enDIAG_SET_GAUGE_STATUS enStatus);

#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : TM_API_vEOLSetGaugeStepCounts                                                               *
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
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
void TM_API_vEOLSetGaugeStepCounts(uint16 u16TargetStepCounts);

#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : TM_API_u16GetBarTargetStepCounts                                                            *
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
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)
	
uint16 TM_API_u16GetBarTargetStepCounts(void);

#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)
/**********************************************************************************************************
*Function   : TM_API_u16GetBarCurrenttStepCounts                                                          *
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
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)
	
uint16 TM_API_u16GetBarCurrentStepCounts(void);

#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)	
/**********************************************************************************************************
*																								          *
*																								          *
*	Tachometer Custom Application Interface														          *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*Function   : TM_API_boGetEMSCANMessageInvalidStatus                                                      *
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
//boolean TM_API_boGetEMSCANMessageInvalidStatus(void);

uint8 TM_API_u8GetECMMsgStatus(void);
uint16 TM_API_u16GetTachoMaxValue(void);
uint16 TM_API_u16GetTachoRedZoneThreshold(void);
uint8 TM_API_u16GetTachoRedZone(void);
#define SWC_TM_STOP_SEC_CODE
#include "SWC_TM_MemMap.h" 

/*********************************************************************************************************/
#endif //TM_API_CFG_H
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
