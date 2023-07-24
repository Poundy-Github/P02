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
*File Name   : SM_Interface.h                                                                             *
*                                                                                                         *
*Description : Speedometer module application interface head file.                                        *
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
#ifndef SM_API_H
#define SM_API_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
//#include "system.h"
#include "Std_Types.h"
#include "Platform_Types.h"
#include "IPC_ClusterApp.h"
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_SM_Config.h"

/**********************************************************************************************************
*	Output Application Interface Accuary            													  *
**********************************************************************************************************/
#define SM_MENUSET_METRIC_UNIT		(0)
#define SM_MENUSET_IMPERIAL_UNIT	(1)

/* Over Speed Warning */
#define SM_OVER_SPEED_ON	(120u)
#define SM_OVER_SPEED_OFF	(115u)

/* Minimum displayed speed signal 0km/h */
#define SM_MIN_DISPLAY_SPEED        (0u)
typedef enum
{	
	ACCUACY_1KM_B = 10000,		//1km factor=0.0001
  	ACCUACY_1KM = 100,		//1km factor=0.01
  	ACCUACY_0_5KM = 50,		//0.5km
  	ACCUACY_0_1KM = 10,		//0.1km
	ACCUACY_0_01KM = 1		//0.01km
}SM_API_enOUTPUT_ACCUACY;
	
typedef enum
{				
  	VALID_INPUT,		/*CAN > PWM*/
  	CAN_INPUT,
	PWM_INPUT
}SM_API_enINPUT;

typedef enum
{
    eVehSpdKMH = 0,     /*unit is km/h  	0 */
    eVehSpdMPH,   		/*unit is mph		1 */
    eVehSpdInvaild 		/*unit is invaild	2 */
}SM_API_enUNIT;

typedef enum
{
   SM_CLUSTER_SLEEP    = 1,
   SM_CLUSTER_OFF      = 2,
   SM_CLUSTER_NORMAL   = 4,
   SM_CLUSTER_ABNORMAL = 8,
   SM_CLUSTER_MAX      = 16
}SM_POWER_MODE;

/**********************************************************************************************************
*	Diagnostic Application Interface Status            													  *
**********************************************************************************************************/
typedef enum
{
	SM_ZERO_DIAL ,
	SM_HALF_DIAL ,
	SM_FULL_DIAL 
}SM_CFG_enDIAG_SET_GAUGE_STATUS;

/* struct */
typedef struct
{
	uint16 	u16IndicateSpd;
	uint16  u16VehSpdMax;
	uint8 	u8MenuUnit;	/* 0:km/h 1:mph */
	uint8 	u8RedDisplay;/* 0:normal 1:display red */
	uint8 	u8VehRunningSts; /* 0:not run 1:running */
}SM_API_stSpeedo_info;
/**********************************************************************************************************
*Function   : SM_API_vKSTimeTask                                                                          *
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
#define Common_Normal_START_SEC_CODE
#include "Common_Normal_MemMap.h" 

void SM_API_vKSTimeTask(void);

/**********************************************************************************************************
*Function   : SM_API_vKSRoundRobin_Task                                                                   *
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
void SM_API_vKSRoundRobinTask(void);

/**********************************************************************************************************
*Function   : SM_API_vKSColdInit                                                                          *
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
void SM_API_vKSColdInit(void);

/**********************************************************************************************************
*Function   : SM_API_vKSWarmInit                                                                          *
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
void SM_API_vKSWarmInit(void);

/**********************************************************************************************************
*Function   : SM_API_vKSWakeUp                                                                            *
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
void SM_API_vKSWakeUp(void);
#endif
/**********************************************************************************************************
*Function   : SM_API_vKSSleep                                                                             *
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
void SM_API_vKSSleep(void);
#endif
/**********************************************************************************************************
*Function   : SM_API_vKSEnterAbnormalOperation                                                            *
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
void SM_API_vKSEnterAbnormalOperation(void);

/**********************************************************************************************************
*Function   : SM_API_vKSExitAbnormalOperation                                                             *
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
void SM_API_vKSExitAbnormalOperation(void);

/**********************************************************************************************************
*Function	: SM_API_vCANMessageCountProcess 														  *
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
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)

void SM_API_vCANMessageCountProcess(void);

#endif
/**********************************************************************************************************
*Function   : SM_API_u16GetRealVehicleSpeed                                                               *
*                                                                                                         *
*Description: The function to get real vehicle speed by other application modules                         *
*			                                                                                              *
*Parameter	: accuacy selection of output		                                                          *
*                                                                                                         *
*Return 	: real vehicle speed                                                                          *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
uint16 SM_API_u16GetRealVehicleSpeed(SM_API_enINPUT enInput,SM_API_enOUTPUT_ACCUACY enAccuacy);

/**********************************************************************************************************
*Function   : SM_API_u16GetTargetIndicateVehicleSpeed                                                     *
*                                                                                                         *
*Description: The function to get target indicate vehicle speed by other application modules              *
*			                                                                                              *
*Parameter	: Accuacy selection of output			                                                      *
*                                                                                                         *
*Return 	: indicate vehicle speed                                                                      *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
uint16 SM_API_u16GetTargetIndicateVehicleSpeed(SM_API_enOUTPUT_ACCUACY enAccuacy);

/**********************************************************************************************************
*Function   : SM_API_u16GetCurrentIndicateVehicleSpeed                                                    *
*                                                                                                         *
*Description: The function is get current indicate vehicle speed by other application modules             *
*			                                                                                              *
*Parameter	: Accuacy selection of output			                                                      *
*                                                                                                         *
*Return 	: indicate vehicle speed                                                                      *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
//uint16 SM_API_u16GetCurrentIndicateVehicleSpeed(SM_API_enOUTPUT_ACCUACY enAccuacy);

/**********************************************************************************************************
*Function   : SM_API_u16GetGaugeParkCounts                                                                *
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
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)

uint16 SM_API_u16GetGaugeParkCounts(void);

#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : SM_API_u16GetGaugeMaxCounts                                                                 *
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
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
uint16 SM_API_u16GetGaugeMaxCounts(void);

#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : SM_API_u16GetGaugeTargetStepCounts                                                          *
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
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
uint16 SM_API_u16GetGaugeTargetStepCounts(void);

#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : SM_API_u16GetGaugeCurrentStepCounts                                                         *
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
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
uint16 SM_API_u16GetGaugeCurrentStepCounts(void);

#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : SM_API_vDiagSetGaugeStatus                                                                  *
*                                                                                                         *
*Description: The function is used to set gauge status from diagnostic module		                      *
*                                                                                                         *
*Parameter	: (SM_CFG_enDIAG_SET_GAUGE_STATUS)enStatus			                  						  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
void SM_API_vDiagSetGaugeStatus(SM_CFG_enDIAG_SET_GAUGE_STATUS enStatus);

#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : SM_API_vEOLSetGaugeStepCounts                                                               *
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
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
void SM_API_vEOLSetGaugeStepCounts(uint16 u16TargetStepCounts);

#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : SM_API_u16GetBarTargetStepCounts                                                            *
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
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)
	
uint16 SM_API_u16GetBarTargetStepCounts(void);

#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)
/**********************************************************************************************************
*Function   : SM_API_u16GetBarCurrenttStepCounts                                                          *
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
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)
	
uint16 SM_API_u16GetBarCurrentStepCounts(void);

#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)	
/**********************************************************************************************************
*																								          *
*																								          *
*	Speedometer Custom Application Interface													          *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*Function   : SM_API_boGetCANMessageInvalidStatus                                                      *
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
boolean SM_API_boGetCANMessageInvalidStatus(void);

void SM_API_vGetSpeedoInfo(IPC_M2S_ClusterAppAPPSpeedo_t *stSpeedoinfo);

uint8 SM_API_u8AppOverSpeedWarningFlg(void);
uint8 SM_API_u8AppVehRunningStsRead(void);
uint8 SM_API_u8AppVehRunningSts(void);

#define Common_Normal_STOP_SEC_CODE
#include "Common_Normal_MemMap.h" 

/*********************************************************************************************************/
#endif //SM_API_H
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
