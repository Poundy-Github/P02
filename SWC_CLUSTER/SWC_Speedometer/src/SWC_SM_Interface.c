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
*File Name   : SM_Interface.c                                                                             *
*                                                                                                         *
*Description : Speedometer module application interface source file.                                      *
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

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
//#include "system.h"
#include <string.h> /* memcpy */

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_SM_Interface.h"
#include "SWC_SM_MemMap.h"

#include "SWC_SM_Core.h"
#include "SWC_IPC_Config.h"
//#include "SWC_SM_MemMap.h"
/**********************************************************************************************************
*																								          *
*																								          *
*	Speedometer Macro Definitions															  *
*																								          *
*																								          *
**********************************************************************************************************/
#define SM_ABS_CAN_MSG_INVALID_FLG		SM__VehSpdVld//SM__stMainObject.unSysErrStatus.stSysErrStatus.ABS_CAN_MSG_Invalid
/**********************************************************************************************************
*																								          *
*																								          *
*	Speedometer Main Object Structure Variable															  *
*																								          *
*																								          *
**********************************************************************************************************/
#define Common_Normal_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Common_Normal_MemMap.h"
static SM_CFG_tstMAIN_OBJECT SM__stMainObject ;
static uint8 Speedo_Msg_missingSts;
static uint8 Speedo_VehSpdVld;
static uint8 SM__VehRunningSts;
static uint8 SM__OverSpdWarningFlg;
static uint8 SM__VehSpdVld;
static uint16 SM__u16TaskCnt;
static uint8 u8PreMenuUnit = SM_CFG_METRIC_UNIT;
//static SM_API_stSpeedo_info SM__SpeedoInfo;
static uint8 l_Speedo_Msg_missingSts_last_U8 = 0;
boolean l_SMDebugLogFlag = FALSE;
static uint8 l_SM_ClusterStateLast_U8 = SYSTEMSTATE_Cluster_OFF;
#define Common_Normal_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Common_Normal_MemMap.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Speedometer Gauge ROM Table Const															          *
*																								          *
*																								          *
**********************************************************************************************************/
#define Common_Normal_START_SEC_CONST_UNSPECIFIED
#include "Common_Normal_MemMap.h"

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)

const uint16 SM__u16GaugeROMTbl[][2] = SM_CFG_GAUGE_ROM_TBL;

#endif 
/**********************************************************************************************************
*																								          *
*																								          *
*	Speedometer Bar ROM Table Const           															  *
*																								          *
*																								          *
**********************************************************************************************************/
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)

const SM_tstBAR_TBL  SM__stBarROMTbl[] = SM_CFG_BAR_ROM_TBL;

#endif 
/**********************************************************************************************************
*																								          *
*																								          *
*	Speedometer Damping Parameter Const           														  *
*																								          *
*																								          *
**********************************************************************************************************/
#if (SM_CFG_DAMPING_MODEL == SM_CFG_THREAD_DAMPING_MODEL)
	
const uint16 SM__u16DampingModel_Thread_Parameter = SM_CFG_THREAD_DAMPING_MODEL_C;

#elif (SM_CFG_DAMPING_MODEL == SM_CFG_KX_PLUS_B_DAMPING_MODEL)

const SM_CFG_tstDAMPING_MODEL_KXPB_PARAMETER SM__stDampingModel_KXPB_Parameter = {SM_CFG_KXPB_DAMPING_MODEL_K1,\
																				  SM_CFG_KXPB_DAMPING_MODEL_K2,\
																				  SM_CFG_KXPB_DAMPING_MODEL_B};

#elif (SM_CFG_DAMPING_MODEL == SM_CFG_PID_DAMPING_MODEL)

const SM_CFG_tstDAMPING_MODEL_PID_PARAMETER SM__stDampingModel_PID_Parameter = {SM_CFG_PID_DAMPING_MODEL_PREFILTER_RATIO_1,\
																				SM_CFG_PID_DAMPING_MODEL_PREFILTER_RATIO_2,\
																		        SM_CFG_PID_DAMPING_MODEL_KP1,\
																			    SM_CFG_PID_DAMPING_MODEL_KP2,\
																			    SM_CFG_PID_DAMPING_MODEL_TI1,\
																			    SM_CFG_PID_DAMPING_MODEL_TI2,\
																			    SM_CFG_PID_DAMPING_MODEL_TD1,\
																			    SM_CFG_PID_DAMPING_MODEL_TD2,\
																			    SM_CFG_PID_DAMPING_MODEL_C};
#else

#endif 

#define Common_Normal_STOP_SEC_CONST_UNSPECIFIED
#include "Common_Normal_MemMap.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Speedometer Common Static Function																      *
*																								          *
*																								          *
**********************************************************************************************************/
#define Common_Normal_START_SEC_CODE
#include "Common_Normal_MemMap.h" 

static boolean SM__boPowerModeCheckProcess(void);

static void SM__vPowerModeIgnitionOffProcess(void);

#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)

static boolean SM__boCANMessageValidCheckProcess(void);

static void SM__vGetRealSpeedFromCAN(void);

static void SM__vCANMessageInvaildProcess(void);

#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)

#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)

static boolean SM__boPWMSignalValidCheckProcess(void);

static void SM__vGetRealSpeedFromPWM(void);

static void SM__vPWMSignalInvaildProcess(void);

#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)

static boolean SM__boCalculateTargetIndicateSpeed(void);

static void SM__vAllInputInvaildProcess(void);

static boolean SM__boDampingHandling(void);

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)

static void SM__vSetGaugeTargetStepCounts(uint16 u16TargetStepCounts);

static void SM__vSetGaugeCurrentStepCounts(uint16 u16CurrentStepCounts);

static boolean SM__boCalculateGaugeStepCounts(void);

static boolean SM__boCalculateGaugeTargetStepCountsLimit(void);

static void SM__vGaugeDoHoming(void);

static boolean SM__vCheckROMGaugeTableProcess(void);

static void SM__vCopyROMGaugeTableProcess(void);

#if (SM_CFG_GAUGE_TBL_SOURCE == SM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
static boolean SM__boCheckEEPROMGaugeTableProcess(void);

static void SM__vCopyEEPROMGaugeTableProcess(void);

#endif //(SM_CFG_GAUGE_TBL_SOURCE == SM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)

static boolean SM__boCalculateBarStepCounts(void);

#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)

static void SM__vSBUSSendMessage(void);

static void SM__vCANOutputMessage(void);

static boolean SM__boSBUSSendOperation(void);

#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)

static void SM__vSystemErrorObjectOperationProcess(void);
static boolean SM__boVehicleConfig(void);
#define Common_Normal_STOP_SEC_CODE
#include "Common_Normal_MemMap.h" 

/**********************************************************************************************************
*																								          *
*																								          *
*	Speedometer Custom Static Function																      *
*																								          *
*																								          *
**********************************************************************************************************/

//None

/**********************************************************************************************************
*																								          *
*																								          *
*	Speedometer Process Map																				  *
*																								          *
*																								          *
**********************************************************************************************************/

/*************************************************************************************************************************************************************************************************************/
/*ProcessName                Process                               SucceedEnable      FaildEnable              AfterSucceed               AfterFaild                         ContinueWhen
                                                                   Status             Status                   Operation                  Operation                          Faild       */
#define Common_Normal_START_SEC_CONST_UNSPECIFIED
#include "Common_Normal_MemMap.h"

static SM_tstPROCESS SM_stTimeTask_ProcessTable[] = {
/*Power Mode */           { SM__boPowerModeCheckProcess ,          SM_KEEP_PREVIOUS , SM_IGN_OFF ,             SM_DO_NOTHING ,            SM__vPowerModeIgnitionOffProcess , (boolean)FALSE            },
/*Vehicle configuration */{ SM__boVehicleConfig ,                  SM_KEEP_PREVIOUS , SM_KEEP_PREVIOUS ,       SM_DO_NOTHING ,              SM_DO_NOTHING ,                    SM_NOT_CONCERNED },
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/*CAN Input  */           { SM__boCANMessageValidCheckProcess ,    SM_KEEP_PREVIOUS , SM_ABS_CAN_MSG_INVALID , SM__vGetRealSpeedFromCAN , SM__vCANMessageInvaildProcess ,    (boolean)TRUE             },
#endif 
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
/*PWM Input */			  { SM__boPWMSignalValidCheckProcess ,     SM_KEEP_PREVIOUS , SM_PWM_SIGNAL_INVALID ,  SM__vGetRealSpeedFromPWM , SM__vPWMSignalInvaildProcess ,     (boolean)TRUE             },
#endif 
/*Calculate indicate */   { SM__boCalculateTargetIndicateSpeed ,   SM_KEEP_PREVIOUS , SM_ALL_INPUT_INVALID ,   SM_DO_NOTHING ,            SM__vAllInputInvaildProcess ,      (boolean)FALSE            },
/*Damping handling */     { SM__boDampingHandling ,                SM_KEEP_PREVIOUS , SM_KEEP_PREVIOUS ,       SM_DO_NOTHING ,            SM_DO_NOTHING ,                    SM_NOT_CONCERNED },
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/*Calculate step counts */{ SM__boCalculateGaugeStepCounts ,       SM_KEEP_PREVIOUS , SM_KEEP_PREVIOUS ,       SM_DO_NOTHING ,            SM_DO_NOTHING ,                    SM_NOT_CONCERNED },
#endif
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)
/*Calculate step counts */{ SM__boCalculateBarStepCounts ,         SM_KEEP_PREVIOUS , SM_KEEP_PREVIOUS ,       SM_DO_NOTHING ,            SM_DO_NOTHING ,                    SM_NOT_CONCERNED },
#endif
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)
/*SBUS send operation */  { SM__boSBUSSendOperation ,              SM_KEEP_PREVIOUS , SM_KEEP_PREVIOUS ,       SM_DO_NOTHING ,            SM_DO_NOTHING ,                    SM_NOT_CONCERNED },
#endif
                          { (void *)0,(SM_CFG_enSYSTEM_STATUS)0,(SM_CFG_enSYSTEM_STATUS)0,(void *)0,(void *)0,(boolean)0},
                          };

#define Common_Normal_STOP_SEC_CONST_UNSPECIFIED
#include "Common_Normal_MemMap.h"

/*************************************************************************************************************************************************************************************************************/

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

void SM_API_vKSTimeTask(void)
{
#if(SM_CFG_SPEEDOMETER_FUNCTION == TRUE)
	if(FALSE == SM_CORE_boCheckSystemErrorStatus(SM_SYS_FAILD,&SM__stMainObject))
	{
		SM_CORE_vProcessControl((void *)SM_stTimeTask_ProcessTable,&SM__stMainObject);
	}
	else
	{
		SM__vSystemErrorObjectOperationProcess();
	}
#endif //(SM_CFG_SPEEDOMETER_FUNCTION == TRUE)
}
/**********************************************************************************************************
*Function   : SM_API_vKSRoundRobinTask                                                                    *
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
void SM_API_vKSRoundRobinTask(void)
{
#if(SM_CFG_SPEEDOMETER_FUNCTION == TRUE)
	
#endif //(SM_CFG_SPEEDOMETER_FUNCTION == TRUE)
}
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
void SM_API_vKSColdInit(void)
{
	//Avoid Warning
	SM_CORE_vSetSystemErrorStatus(SM_SYS_DEFAULT,&SM__stMainObject);

	SM_CORE_vClearSystemErrorStatus(SM_SYS_DEFAULT,&SM__stMainObject);

	(void)SM_CORE_boCheckSystemErrorStatus(SM_SYS_DEFAULT,&SM__stMainObject);
	
#if(SM_CFG_SPEEDOMETER_FUNCTION == TRUE)
#if(SM_CFG_DEBUG == TRUE)
printf("\
------------------------------------------------------------\r\n\
--Speedometer Module Debug Mode Enable----------------------\r\n\
------------------------------------------------------------\r\n");

 	SM_CORE_vCheckModuleConfigration();

#endif

#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) == FALSE)

	SM_CORE_vSetSystemErrorStatus(SM_ABS_CAN_MSG_INVALID,&SM__stMainObject);
		
#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) == FALSE)

#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) == FALSE)

	SM_CORE_vSetSystemErrorStatus(SM_PWM_SIGNAL_INVALID,&SM__stMainObject);
		
#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) == FALSE)

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	if (FALSE == SM__vCheckROMGaugeTableProcess())
	{
		SM_CORE_vSetSystemErrorStatus(SM_SYS_FAILD,&SM__stMainObject);
	}
#if (SM_CFG_GAUGE_TBL_SOURCE == SM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
	else if (TRUE == SM__boCheckEEPROMGaugeTableProcess())
	{	
		SM__vCopyEEPROMGaugeTableProcess();
	}
#endif // (SM_CFG_GAUGE_TBL_SOURCE == SM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
	else
	{
		SM__vCopyROMGaugeTableProcess();
	}
#endif // ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)
	if (FALSE == SM_CORE_boCheckBarTableProcess(&SM__stBarROMTbl))
	{
		SM_CORE_vSetSystemErrorStatus(SM_SYS_FAILD,&SM__stMainObject);
	}
	else
	{
		/*Bar table check ok*/
	}

#endif // ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)

	if(FALSE == SM_CORE_boCheckSystemErrorStatus(SM_SYS_FAILD,&SM__stMainObject))
	{
		//Function flag control
		SM_CORE_vFlagControl(SM_COLD_INIT,&SM__stMainObject);

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
		/*Calculate gauge target step counts limit*/
		(void)SM__boCalculateGaugeTargetStepCountsLimit();
#endif // ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)
		/*Send SBUS message*/
		SM__vSBUSSendMessage();
#endif  // ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)

		/*Clear count*/
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)

		SM__stMainObject.stCount.u8ABSVehicleSpeedValueValidCount = SM_CFG_CAN_MSG_VEHICLE_SPEED_VALID_COUNT_LIMIT;
		SM__stMainObject.stCount.u8ABSVehicleSpeedStatusValidCount = SM_CFG_CAN_MSG_VEHICLE_SPEED_VALID_COUNT_LIMIT;	
		SM__stMainObject.stCount.u8ABSVehicleSpeedValueInvalidCount = 0u;
		SM__stMainObject.stCount.u8ABSVehicleSpeedStatusInvalidCount = 0u;

#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)

#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)

		SM__stMainObject.stCount.u8PWMValueInvalidCount = 0;

#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
		
	}
	else //System Faild,do nothing
	{

	}
#endif //(SM_CFG_SPEEDOMETER_FUNCTION == TRUE)
	SM__VehRunningSts = 0;
}
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
void SM_API_vKSWarmInit(void)
{
#if(SM_CFG_SPEEDOMETER_FUNCTION == TRUE)

#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) == FALSE)

	SM_CORE_vSetSystemErrorStatus(SM_ABS_CAN_MSG_INVALID,&SM__stMainObject);
		
#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) == FALSE)

#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) == FALSE)

	SM_CORE_vSetSystemErrorStatus(SM_PWM_SIGNAL_INVALID,&SM__stMainObject);
		
#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) == FALSE)

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	if (FALSE == SM__vCheckROMGaugeTableProcess())
	{
		SM_CORE_vSetSystemErrorStatus(SM_SYS_FAILD,&SM__stMainObject);
	}
#if (SM_CFG_GAUGE_TBL_SOURCE == SM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
	else if (TRUE == SM__boCheckEEPROMGaugeTableProcess())
	{	
		SM__vCopyEEPROMGaugeTableProcess();
	}
#endif // (SM_CFG_GAUGE_TBL_SOURCE == SM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
	else
	{
		SM__vCopyROMGaugeTableProcess();
	}
#endif // ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)

	if(FALSE == SM_CORE_boCheckSystemErrorStatus(SM_SYS_FAILD,&SM__stMainObject))
	{
		//Function flag control
		SM_CORE_vFlagControl(SM_WARM_INIT,&SM__stMainObject);
		
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
		/*Calculate gauge target step counts limit*/
		(void)SM__boCalculateGaugeTargetStepCountsLimit();
#endif // ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)
		/*Send SBUS message*/
		SM__vSBUSSendMessage();
#endif  // ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)

		/*Clear count*/
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)

		SM__stMainObject.stCount.u8ABSVehicleSpeedValueValidCount = SM_CFG_CAN_MSG_VEHICLE_SPEED_VALID_COUNT_LIMIT;
		SM__stMainObject.stCount.u8ABSVehicleSpeedStatusValidCount = SM_CFG_CAN_MSG_VEHICLE_SPEED_VALID_COUNT_LIMIT;	
		SM__stMainObject.stCount.u8ABSVehicleSpeedValueInvalidCount = 0u;
		SM__stMainObject.stCount.u8ABSVehicleSpeedStatusInvalidCount = 0u;
		
#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)

#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)

		SM__stMainObject.stCount.u8PWMValueInvalidCount = 0;

#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)


	}
	else //System Faild,do nothing
	{

	}
#endif //(SM_CFG_SPEEDOMETER_FUNCTION == TRUE)
	SM__VehRunningSts = 0;
}
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
void SM_API_vKSWakeUp(void)
{
	if(FALSE == SM_CORE_boCheckSystemErrorStatus(SM_SYS_FAILD,&SM__stMainObject))
	{
		//Function flag control
		SM_CORE_vFlagControl(SM_WAKE_UP,&SM__stMainObject);
		
	}
	else //System Faild,do nothing
	{

	}
}
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
void SM_API_vKSSleep(void)
{
	if(FALSE == SM_CORE_boCheckSystemErrorStatus(SM_SYS_FAILD,&SM__stMainObject))
	{
		//Function flag control
		SM_CORE_vFlagControl(SM_SLEEP,&SM__stMainObject);
		
	}
	else //System Faild,do nothing
	{

	}
}
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
void SM_API_vKSEnterAbnormalOperation(void)
{
#if(SM_CFG_SPEEDOMETER_FUNCTION == TRUE)
	if(FALSE == SM_CORE_boCheckSystemErrorStatus(SM_SYS_FAILD,&SM__stMainObject))
	{
		//Function flag control
		SM_CORE_vFlagControl(SM_ENTER_ABNORMAL,&SM__stMainObject);
		
		/*Clear count*/
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		SM__stMainObject.stCount.u8ABSVehicleSpeedValueValidCount = SM_CFG_CAN_MSG_VEHICLE_SPEED_VALID_COUNT_LIMIT;
		SM__stMainObject.stCount.u8ABSVehicleSpeedStatusValidCount = SM_CFG_CAN_MSG_VEHICLE_SPEED_VALID_COUNT_LIMIT;	
		SM__stMainObject.stCount.u8ABSVehicleSpeedValueInvalidCount = 0u;
		SM__stMainObject.stCount.u8ABSVehicleSpeedStatusInvalidCount = 0u;
#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
		
		SM__stMainObject.stCount.u8PWMValueInvalidCount = 0;
		
#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)
		/*Send SBUS message*/
		SM__vSBUSSendMessage();
#endif  // ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)

	}
	else //System Faild,do nothing
	{

	}
#endif //(SM_CFG_SPEEDOMETER_FUNCTION == TRUE)
}
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
void SM_API_vKSExitAbnormalOperation(void)
{
#if(SM_CFG_SPEEDOMETER_FUNCTION == TRUE)

	if(FALSE == SM_CORE_boCheckSystemErrorStatus(SM_SYS_FAILD,&SM__stMainObject))
	{
		//Function flag control
		SM_CORE_vFlagControl(SM_EXIT_ABNORMAL,&SM__stMainObject);
		
		/*Clear count*/
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		SM__stMainObject.stCount.u8ABSVehicleSpeedValueValidCount = SM_CFG_CAN_MSG_VEHICLE_SPEED_VALID_COUNT_LIMIT;
		SM__stMainObject.stCount.u8ABSVehicleSpeedStatusValidCount = SM_CFG_CAN_MSG_VEHICLE_SPEED_VALID_COUNT_LIMIT;	
		SM__stMainObject.stCount.u8ABSVehicleSpeedValueInvalidCount = 0u;
		SM__stMainObject.stCount.u8ABSVehicleSpeedStatusInvalidCount = 0u;
#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
		
		SM__stMainObject.stCount.u8PWMValueInvalidCount = 0;
		
#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)
		/*Send SBUS message*/
		SM__vSBUSSendMessage();
#endif  //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)

	}
	else //System Faild,do nothing
	{

	}
#endif //(SM_CFG_SPEEDOMETER_FUNCTION == TRUE)
}
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
uint16 SM_API_u16GetRealVehicleSpeed(SM_API_enINPUT enInput,SM_API_enOUTPUT_ACCUACY enAccuacy)
{
    uint16 u16RealSpeedTemp = 0;

	if(0)
	{
		/*Always skip this step*/
	}
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
	else if((FALSE == SM_CORE_boCheckSystemErrorStatus(SM_ABS_CAN_MSG_INVALID,&SM__stMainObject))&&\
            ((enInput == VALID_INPUT)||(enInput == CAN_INPUT)))
	{
		u16RealSpeedTemp = (uint16)(SM__stMainObject.u32RealSpeedFromCAN / SM_CFG_VALUE_FACTOR);
	}
#endif	//((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
	else if((FALSE == SM_CORE_boCheckSystemErrorStatus(SM_PWM_SIGNAL_INVALID,&SM__stMainObject))&&\
            ((enInput == VALID_INPUT)||(enInput == PWM_INPUT)))
	{
		u16RealSpeedTemp = SM__stMainObject.u16RealSpeedFromPWM;
	}
#endif	//((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)	
	else
	{
		/*No input valid*/
		u16RealSpeedTemp = 0u;
	}

	return (SM_CORE__u16FormatDataAccuracy(SM_CFG_VALUE_MAX,SM_CFG_VALUE_MIN,\
										  (uint16)enAccuacy,0,\
										  SM_CFG_SPEED_VALUE_INTERFACE_ROUND_CONFIG,\
										  u16RealSpeedTemp));
}
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
uint16 SM_API_u16GetTargetIndicateVehicleSpeed(SM_API_enOUTPUT_ACCUACY enAccuacy)
{
	return (SM_CORE__u16FormatDataAccuracy(SM_CFG_VALUE_MAX,SM_CFG_VALUE_MIN,\
										   (uint16)enAccuacy,0,\
										   SM_CFG_SPEED_VALUE_INTERFACE_ROUND_CONFIG,\
										   (uint16)SM__stMainObject.u16TargetIndicateSpeed));
}
/**********************************************************************************************************
*Function   : SM_API_u16GetCurrentIndicateVehicleSpeed                                                    *
*                                                                                                         *
*Description: The function to get current indicate vehicle speed by other application modules             *
*			                                                                                              *
*Parameter	: Accuacy selection of output			                                                      *
*                                                                                                         *
*Return 	: indicate vehicle speed                                                                      *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if 0
static uint16 SM_API_u16GetCurrentIndicateVehicleSpeed(SM_API_enOUTPUT_ACCUACY enAccuacy)
{
	return (SM_CORE__u16FormatDataAccuracy(SM_CFG_VALUE_MAX,SM_CFG_VALUE_MIN,\
										   (uint16)enAccuacy,0,\
										   SM_CFG_SPEED_VALUE_INTERFACE_ROUND_CONFIG,\
										   (uint16)SM__stMainObject.u16CurrentIndicateSpeed));
}
#endif

static uint32 SM_API_u32GetCurrentIndicateVehicleSpeed(SM_API_enOUTPUT_ACCUACY enAccuacy)
{
	return (SM_CORE__u32FormatDataAccuracy(SM_CFG_VALUE_MAX,SM_CFG_VALUE_MIN,\
										   (uint16)enAccuacy,0,\
										   SM_CFG_SPEED_VALUE_INTERFACE_ROUND_CONFIG,\
										   SM__stMainObject.u16CurrentIndicateSpeed));
}

/**********************************************************************************************************
*Function   : SM_API_u16GetGaugeParkCounts                                                                *
*                                                                                                         *
*Description: The function get park counts for stepper motor driver                                       *
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
uint16 SM_API_u16GetGaugeParkCounts(void)
{
	return (SM__stMainObject.u16GaugeMinMotorStepCounts);
}
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
uint16 SM_API_u16GetGaugeMaxCounts(void)
{
	return (SM__stMainObject.u16GaugeMaxMotorStepCounts);
}
#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : SM_API_u16GetGaugeTargetStepCounts                                                          *
*                                                                                                         *
*Description: The function get target counts for stepper motor driver                                     *
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
uint16 SM_API_u16GetGaugeTargetStepCounts(void)
{
	return (SM__stMainObject.u16GaugeTargetStepCounts);
}
#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : SM_API_u16GetGaugeCurrentStepCounts                                                         *
*                                                                                                         *
*Description: The function get current counts for stepper motor driver                                    *
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
uint16 SM_API_u16GetGaugeCurrentStepCounts(void)
{
	return (SM__stMainObject.u16GaugeCurrentStepCounts);
}
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
void SM_API_vDiagSetGaugeStatus(SM_CFG_enDIAG_SET_GAUGE_STATUS enStatus)
{
	
}
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
void SM_API_vEOLSetGaugeStepCounts(uint16 u16TargetStepCounts)
{
	SM__stMainObject.u16GaugeTargetStepCounts = u16TargetStepCounts;
	SM__stMainObject.u16GaugeCurrentStepCounts = u16TargetStepCounts;
}
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
uint16 SM_API_u16GetBarTargetStepCounts(void)
{
	return (SM__stMainObject.u16BarTargetStepCounts);
}
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
uint16 SM_API_u16GetBarCurrentStepCounts(void)
{
	return (SM__stMainObject.u16BarCurrentStepCounts);
}
#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)	
/**********************************************************************************************************
*Function	: SM_API_vCANMessageCountProcess													          *
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
void SM_API_vCANMessageCountProcess(void)
{

	//if(SM_CFG_CAN_ABS_VEHICLE_SPEED_INVALID)
	if(VEHICLE_SPEED_INVALID == SM_ABS_CAN_MSG_INVALID_FLG)
	{
		SM__stMainObject.stCount.u8ABSVehicleSpeedValueInvalidCount ++;
		
		SM__stMainObject.stCount.u8ABSVehicleSpeedValueValidCount = 0;
	}
	else
	{
		SM__stMainObject.stCount.u8ABSVehicleSpeedValueInvalidCount = 0;
		
		SM__stMainObject.stCount.u8ABSVehicleSpeedValueValidCount ++;
	}

	if(SM__stMainObject.stCount.u8ABSVehicleSpeedValueInvalidCount >= SM_CFG_CAN_MSG_VEHICLE_SPEED_INVALID_COUNT_LIMIT)
	{
		SM__stMainObject.stCount.u8ABSVehicleSpeedValueInvalidCount = SM_CFG_CAN_MSG_VEHICLE_SPEED_INVALID_COUNT_LIMIT;
	}
	else
	{

	}

	if(SM__stMainObject.stCount.u8ABSVehicleSpeedValueValidCount >= SM_CFG_CAN_MSG_VEHICLE_SPEED_VALID_COUNT_LIMIT)
	{
		SM__stMainObject.stCount.u8ABSVehicleSpeedValueValidCount = SM_CFG_CAN_MSG_VEHICLE_SPEED_VALID_COUNT_LIMIT;
	}
	else
	{

	}

	if(SM_CFG_CAN_ABS_VEHICLE_SPEED_STATUS_INVALID)
	{
		SM__stMainObject.stCount.u8ABSVehicleSpeedStatusInvalidCount ++;
		
		SM__stMainObject.stCount.u8ABSVehicleSpeedStatusValidCount = 0;
	}
	else
	{
		SM__stMainObject.stCount.u8ABSVehicleSpeedStatusInvalidCount = 0;
		
		SM__stMainObject.stCount.u8ABSVehicleSpeedStatusValidCount ++;
	}

	if(SM__stMainObject.stCount.u8ABSVehicleSpeedStatusInvalidCount >= SM_CFG_CAN_MSG_VEHICLE_SPEED_INVALID_COUNT_LIMIT)
	{
		SM__stMainObject.stCount.u8ABSVehicleSpeedStatusInvalidCount = SM_CFG_CAN_MSG_VEHICLE_SPEED_INVALID_COUNT_LIMIT;
	}
	else
	{

	}

	if(SM__stMainObject.stCount.u8ABSVehicleSpeedStatusValidCount >= SM_CFG_CAN_MSG_VEHICLE_SPEED_VALID_COUNT_LIMIT)
	{
		SM__stMainObject.stCount.u8ABSVehicleSpeedStatusValidCount = SM_CFG_CAN_MSG_VEHICLE_SPEED_VALID_COUNT_LIMIT;
	}
	else
	{

	}
	
}
#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/**********************************************************************************************************
*Function   : SM_API_boGetCANMessageInvalidStatus                                                         *
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
boolean SM_API_boGetCANMessageInvalidStatus(void)
{
	boolean boReturn ;
	
	if(SM_CORE_boCheckSystemErrorStatus(SM_ABS_CAN_MSG_INVALID,&SM__stMainObject) == TRUE)
	{
		boReturn = FALSE;
	}
	else
	{
		boReturn = TRUE;
	}
	
	return boReturn;
}
/**********************************************************************************************************
*																								          *
*																								          *
*	Speedometer Custom Application Interface													          *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*Function   : SM__boPowerModeCheckProcess                                                                 *
*                                                                                                         *
*Description: The function is used to check power mode is ign on which status can speedometer work        *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
static boolean SM__boPowerModeCheckProcess(void)
{
	boolean boReturn = FALSE;
	SystemState_RecordType *u8PowerMode;
	
	u8PowerMode = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
	
	if((u8PowerMode->s_PowerVoltage.state != VOLTAGE_OUT_NORMAL) \
		&& (u8PowerMode->s_PowerVoltage.state != VOLTAGE_OUT_LOWALARM) \
		&& (u8PowerMode->s_PowerVoltage.state != VOLTAGE_OUT_HIGHALARM))
	{
		boReturn = FALSE;
	}
	else
	{
		if(SYSTEMSTATE_Cluster_OFF == u8PowerMode->ClusterState)			
		{
			boReturn = FALSE;
		}
		else if(SYSTEMSTATE_Cluster_ON == u8PowerMode->ClusterState)
		{
			boReturn = TRUE;
		}		
		else
		{
			boReturn = FALSE;
		}
	}	
	if((SYSTEMSTATE_Cluster_ON == u8PowerMode->ClusterState) && (SYSTEMSTATE_Cluster_ON != l_SM_ClusterStateLast_U8))
	{
		l_SMDebugLogFlag = TRUE;
	}
	else
	{
		l_SMDebugLogFlag = FALSE;
	}
	l_SM_ClusterStateLast_U8 = u8PowerMode->ClusterState;
	
	return boReturn;
}
/**********************************************************************************************************
*Function   : SM__vPowerModeIgnitionOffProcess                                                            *
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
static void SM__vPowerModeIgnitionOffProcess(void)
{
	SM__stMainObject.u16LastTargetIndicateSpeed = 0;
	SM__stMainObject.u16LastCurrentIndicateSpeed = 0;
	SM__stMainObject.unFunctionFlag.stFuncFlag.IncreaseClimate = 1u;
	SM__stMainObject.stTimer.u16ReservedTick = 0;
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)	
	//SM__stMainObject.u32RealSpeedFromCANBak = SM__stMainObject.u32RealSpeedFromCAN;
	SM__stMainObject.u32RealSpeedFromCAN = 0;
#endif

#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)	
	SM__stMainObject.u16RealSpeedFromPWM = 0;
#endif

	SM__stMainObject.u16TargetIndicateSpeed = 0;
	SM__stMainObject.u16CurrentIndicateSpeed = 0;

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
	/*Ignition off is no damping to sweep pointer so homing immediately*/
	SM__vGaugeDoHoming();
#endif 

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)
	SM__stMainObject.u16BarTargetStepCounts = 0;
	SM__stMainObject.u16BarCurrentStepCounts = 0;
#endif

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)
	/*Send SBUS message*/
	SM__vSBUSSendMessage();
#endif 

}
/**********************************************************************************************************
*Function   : SM__boCANMessageValidCheckProcess                                                           *
*                                                                                                         *
*Description: The function is used to check ABS CAN message is received	normally                          *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
static boolean SM__boCANMessageValidCheckProcess(void)
{
	boolean boReturn = (boolean)FALSE;
	uint8 u8VehSpdVld = 0;
	uint8 SG_ABS3_StatusRet = 0;

#ifdef GWM_V35_PROJECT_TYPE_B02_SM
	SG_ABS3_StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, (uint8 *)&u8VehSpdVld, (uint8)sizeof(u8VehSpdVld));
#elif defined GWM_V35_PROJECT_TYPE_B03_SM
	SG_ABS3 SM_SG_ABS3;
	SG_ABS3_ESP_FD2 SM_SG_ABS3_ESP_FD2;

	if(SM__stMainObject.u8CANType == SM_CFG_ABS3_CAN)
	{
		SG_ABS3_StatusRet = Rte_Read_SG_ABS3_SG_ABS3(&SM_SG_ABS3);
		u8VehSpdVld = (uint8)SM_SG_ABS3.VehSpdVld_0x265;
	}
	else if(SM__stMainObject.u8CANType == SM_CFG_ESP_CAN_FD)
	{
		SG_ABS3_StatusRet = Rte_Read_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2(&SM_SG_ABS3_ESP_FD2);
		u8VehSpdVld = (uint8)SM_SG_ABS3_ESP_FD2.VehSpdVld_0x137;
	}
#elif defined GWM_V35_PROJECT_TYPE_P03_SM
	SG_ABS3_StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, (uint8 *)&u8VehSpdVld, (uint8)sizeof(u8VehSpdVld));
#elif defined GWM_V35_PROJECT_TYPE_P05_SM
	if(SM__stMainObject.u8CANType == SM_CFG_ABS3_CAN)
	{
		SG_ABS3_StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD_0X265, (uint8 *)&u8VehSpdVld, (uint8)sizeof(u8VehSpdVld));
	}
	else if(SM__stMainObject.u8CANType == SM_CFG_ESP_CAN_FD)
	{
		SG_ABS3_StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD_0X137, (uint8 *)&u8VehSpdVld, (uint8)sizeof(u8VehSpdVld));
	}
#elif defined GWM_V35_PROJECT_TYPE_A07_SM
	if(SM__stMainObject.u8CANType == SM_CFG_ABS3_CAN)
	{
		SG_ABS3_StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, (uint8 *)&u8VehSpdVld, (uint8)sizeof(u8VehSpdVld));
	}
	else if(SM__stMainObject.u8CANType == SM_CFG_ESP_CAN_FD)
	{
		//DBC V4.1 DEL
	}
#elif defined GWM_V35_PROJECT_TYPE_D01_SM
	SG_ABS3_StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, (uint8 *)&u8VehSpdVld, (uint8)sizeof(u8VehSpdVld));
#elif defined GWM_V35_PROJECT_TYPE_D02_SM
	SG_ABS3_StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, (uint8 *)&u8VehSpdVld, (uint8)sizeof(u8VehSpdVld));
#elif defined GWM_V35_PROJECT_TYPE_D03_SM
	SG_ABS3_StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, (uint8 *)&u8VehSpdVld, (uint8)sizeof(u8VehSpdVld));
#elif defined GWM_V35_PROJECT_TYPE_P02_SM
	SG_ABS3_StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, (uint8 *)&u8VehSpdVld, (uint8)sizeof(u8VehSpdVld));
#elif defined GWM_V35_PROJECT_TYPE_P01_SM
	SG_ABS3_StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, (uint8 *)&u8VehSpdVld, (uint8)sizeof(u8VehSpdVld));
#else
#endif

	SM_ABS_CAN_MSG_INVALID_FLG = u8VehSpdVld; 
	Speedo_VehSpdVld = u8VehSpdVld;

#if (SM_CFG_CAN_MSG_VALID_COUNT_PLUS_IN_TIME_TASK == TRUE)

	SM_API_vCANMessageCountProcess();

#endif //(SM_CFG_CAN_MSG_VALID_COUNT_PLUS_IN_TIME_TASK == TRUE)

	if((FALSE == SM_CFG_CAN_ABS3_MSG_MISSING(SG_ABS3_StatusRet)) \
		&& (FALSE == (SM_CFG_CAN_ESP_FD2_MSG_MISSING(SG_ABS3_StatusRet))))
	{
		if((SM__stMainObject.stCount.u8ABSVehicleSpeedStatusValidCount >= SM_CFG_CAN_MSG_VEHICLE_SPEED_VALID_COUNT_LIMIT)\
		 &&(SM__stMainObject.stCount.u8ABSVehicleSpeedValueValidCount >= SM_CFG_CAN_MSG_VEHICLE_SPEED_VALID_COUNT_LIMIT))
		{


			/*Enable first update flag*/
			if(SM__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate == 0u)
			{
				SM__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 1u;
			}
			else
			{

			}	
		
			SM__stMainObject.unFunctionFlag.stFuncFlag.ABSValueInvalidButKeep = 0u;/*0 is disable*/

			boReturn = TRUE;
		}
		else if(((SM__stMainObject.stCount.u8ABSVehicleSpeedStatusValidCount == 0u)\
			&&(SM__stMainObject.stCount.u8ABSVehicleSpeedStatusInvalidCount < SM_CFG_CAN_MSG_VEHICLE_SPEED_INVALID_COUNT_LIMIT))\
			||((SM__stMainObject.stCount.u8ABSVehicleSpeedValueValidCount == 0u)\
			&&(SM__stMainObject.stCount.u8ABSVehicleSpeedValueInvalidCount < SM_CFG_CAN_MSG_VEHICLE_SPEED_INVALID_COUNT_LIMIT)))
		{
			SM__stMainObject.unFunctionFlag.stFuncFlag.ABSValueInvalidButKeep = 1u;/*1 is enable*/
			boReturn = TRUE;
		}
		else
		{
			SM__stMainObject.unFunctionFlag.stFuncFlag.ABSValueInvalidButKeep = 0u;/*0 is disable*/
			boReturn = FALSE;
		}
		Speedo_Msg_missingSts = 0;
	}
	else
	{
		SM__stMainObject.unFunctionFlag.stFuncFlag.ABSValueInvalidButKeep = 0u;/*0 is disable*/
		Speedo_Msg_missingSts = 1;/* message missing */
		boReturn = FALSE;
		Speedo_VehSpdVld = 0;
	}
	/* SM DEBUG Log Print*/
	if (TRUE == SWC_SM_LOGOUT_ENBLE)
	{
		/* If Msg Receive Status Change Or Power Status Change*/
		if((Speedo_Msg_missingSts != l_Speedo_Msg_missingSts_last_U8) || (TRUE == l_SMDebugLogFlag))
		{
			if(1 == Speedo_Msg_missingSts)/* If MSG missing print 1 */
			{
				SWC_SM_PRINT_WARN("Speedo:MSGMissSts:%d", Speedo_Msg_missingSts);
			}
			else/*If MSG Receive Print 0*/
			{
				SWC_SM_PRINT_WARN("Speedo:MSGMissSts:%d", Speedo_Msg_missingSts);
			}
		}
	}
	else
	{
		/* Do Nothing */
	}
	
	l_Speedo_Msg_missingSts_last_U8 = Speedo_Msg_missingSts;
	return boReturn;
}
#endif // ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/**********************************************************************************************************
*Function   : SM__vGetRealSpeedFromCAN                                                                    *
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
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
static void SM__vGetRealSpeedFromCAN(void)
{
	if(SM__stMainObject.unFunctionFlag.stFuncFlag.ABSValueInvalidButKeep == 0u)
	{
		/*Calculate current real speed from formula*/
		SM_CFG_vFormulaOfGetRealSpeedFromCANRawValue(&SM__stMainObject);
	}
	else
	{
		/*Keep previous status for this time*/
	}
}
#endif // ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/**********************************************************************************************************
*Function   : SM__vCANMessageInvaildProcess                                                               *
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
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
static void SM__vCANMessageInvaildProcess(void)
{
	SM__stMainObject.u32RealSpeedFromCANBak = 0;
	SM__stMainObject.u32RealSpeedFromCAN = 0;
}
#endif // ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/**********************************************************************************************************
*Function   : SM__boPWMInputValidCheckProcess                                                             *
*                                                                                                         *
*Description: The function is used to check PWM input signal is received normally                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
static boolean SM__boPWMSignalValidCheckProcess(void)
{
	boolean boReturn = FALSE;
		
	/*Invalid count*/
	if(!SM_CFG_PWM_SPEED_VALUE_VALID)
	{
		SM__stMainObject.stCount.u8PWMValueInvalidCount ++;
		
		/*Avoid Overflow*/
		if(SM__stMainObject.stCount.u8PWMValueInvalidCount >= SM_CFG_PWM_SIGNAL_VALUE_INVALID_COUNT_LIMIT)
		{
			SM__stMainObject.stCount.u8PWMValueInvalidCount = SM_CFG_PWM_SIGNAL_VALUE_INVALID_COUNT_LIMIT;
		}
		else
		{
			
		}
	}
	else
	{
		SM__stMainObject.stCount.u8PWMValueInvalidCount = 0;
	}

	//Check msg 
	if(SM_CFG_PWM_STATUS_CHECK_OK && SM_CFG_PWM_SPEED_VALUE_VALID)
	{
		/*Enable first update flag*/
		if(SM__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate == 0u)
		{
			SM__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 1u;
		}
		else
		{

		}
		SM__stMainObject.unFunctionFlag.stFuncFlag.PWMValueInvalidButKeep = 0u;/*0 is disable*/
		boReturn = TRUE;
	}
	else if(SM_CFG_PWM_STATUS_CHECK_OK && \
		(!SM_CFG_PWM_SPEED_VALUE_VALID)&& \
		(SM__stMainObject.stCount.u8PWMValueInvalidCount < SM_CFG_PWM_SIGNAL_VALUE_INVALID_COUNT_LIMIT))
	{
		SM__stMainObject.unFunctionFlag.stFuncFlag.PWMValueInvalidButKeep = 1u;/*1 is enable*/	
		boReturn = TRUE;
   	}
	else
	{
		SM__stMainObject.unFunctionFlag.stFuncFlag.PWMValueInvalidButKeep = 0u;/*0 is disable*/
		boReturn = FALSE;
	}

	return boReturn;
}
#endif // ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
/**********************************************************************************************************
*Function   : SM__vGetRealSpeedFromPWM                                                                    *
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
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
static void SM__vGetRealSpeedFromPWM(void)
{
	if(SM__stMainObject.unFunctionFlag.stFuncFlag.PWMValueInvalidButKeep == 0u)
	{
		/*Calculate current real speed from formula*/
		SM_CFG_vFormulaOfGetRealSpeedFromPWMRawValue(&SM__stMainObject);
	}
	else
	{
		/*Keep previous status for this time*/
	}
}
#endif // ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
/**********************************************************************************************************
*Function   : SM__vPWMSignalInvaildProcess                                                                *
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
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
static void SM__vPWMSignalInvaildProcess(void)
{
	SM__stMainObject.u16RealSpeedFromPWM = 0;
}
#endif // ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
/**********************************************************************************************************
*Function   : SM__boCalculateTargetIndicateSpeed                                                          *
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
static boolean SM__boCalculateTargetIndicateSpeed(void)
{
	boolean boReturn = FALSE;
#ifdef SM_CFG_TARGET_SEPPED_ADJUST_CRUISE
	uint32 d_speed;
#endif
	
	if(0)
	{
		/*Always skip this step*/
	}
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)	
	else if(FALSE == SM_CORE_boCheckSystemErrorStatus(SM_ABS_CAN_MSG_INVALID,&SM__stMainObject))
	{
		SM__stMainObject.u32VaildRealSpeed = SM__stMainObject.u32RealSpeedFromCAN;
		boReturn = TRUE;
	}
#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
	else if(FALSE == SM_CORE_boCheckSystemErrorStatus(SM_PWM_SIGNAL_INVALID,&SM__stMainObject))
	{
		SM__stMainObject.u32VaildRealSpeed = SM__stMainObject.u16RealSpeedFromPWM;
		boReturn = TRUE;
	}
#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
	else
	{
		/*No input is valid*/
		SM__stMainObject.u32VaildRealSpeed = 0u;
		boReturn = FALSE;
	}
	
	

	/*Calculate target indicate speed from formula*/
	SM_CFG_vFormulaOfGetTargetIndicateSpeedFromRealSpeed(&SM__stMainObject);
#ifdef SM_CFG_TARGET_SEPPED_ADJUST_CRUISE
	if(SM_CFG_CRUISE_CFG_ENABLE)
	{
		if((TRUE == SM_CFG_CAN_MSG_CRUISE_VALID) && (TRUE == SM_CFG_CAN_MSG_CRUISE_SET) && (TRUE == SM_CFG_CAN_MSG_CRUISE_SPEED_VALID))
		{
			if(SM_CFG_CAN_MSG_CRUISE_SPEED_VALUE >= (SM__stMainObject.u16TargetIndicateSpeed/100))
			{
				d_speed = SM_CFG_CAN_MSG_CRUISE_SPEED_VALUE - (SM__stMainObject.u16TargetIndicateSpeed/100);
			}
			else 
			{
				d_speed = (SM__stMainObject.u16TargetIndicateSpeed/100) - SM_CFG_CAN_MSG_CRUISE_SPEED_VALUE;
			}
			if(d_speed <= SM_CFG_CAN_MSG_DEFINENT_SPEED)
			{
				SM__stMainObject.u16TargetIndicateSpeed = SM_CFG_CAN_MSG_CRUISE_SPEED_VALUE * 100;
			}
		}
	}
	else if(SM_CFG_ACC_CRUISE_CFG_ENABLE)
	{
		if((TRUE == SM_CFG_CAN_MSG_ACC_CRUISE_VALID) && (TRUE == SM_CFG_CAN_MSG_ACC_CRUISE_SET) && (TRUE == SM_CFG_CAN_MSG_ACC_CRUISE_SPEED_VALID))
		{
			if(SM_CFG_CAN_MSG_ACC_CRUISE_SPEED_VALUE >= (SM__stMainObject.u16TargetIndicateSpeed/100))
			{
				d_speed = SM_CFG_CAN_MSG_ACC_CRUISE_SPEED_VALUE - (SM__stMainObject.u16TargetIndicateSpeed/100);
			}
			else 
			{
				d_speed = (SM__stMainObject.u16TargetIndicateSpeed/100) - SM_CFG_CAN_MSG_ACC_CRUISE_SPEED_VALUE;
			}
			if(d_speed <= SM_CFG_CAN_MSG_DEFINENT_SPEED)
			{
				SM__stMainObject.u16TargetIndicateSpeed = SM_CFG_CAN_MSG_ACC_CRUISE_SPEED_VALUE * 100;
			}
		}
	}
	else 
	{
		//keep target speed;
	}
#endif
	/*Save last indicate speed*/
	SM__stMainObject.u16LastTargetIndicateSpeed = SM__stMainObject.u16TargetIndicateSpeed;

	//Increase climate flag
	if(SM__stMainObject.u16TargetIndicateSpeed > SM__stMainObject.u16LastTargetIndicateSpeed)
	{
		SM__stMainObject.unFunctionFlag.stFuncFlag.IncreaseClimate = 1u;
	}
	else if(SM__stMainObject.u16TargetIndicateSpeed < SM__stMainObject.u16LastTargetIndicateSpeed)
	{
		SM__stMainObject.unFunctionFlag.stFuncFlag.IncreaseClimate = 0u;
	}
	else
	{
		/*Keep previous climate*/
	}

	/* Vehicle Running status */
	//SM__vApp_setVehRunningSts();
	return boReturn;
}
/**********************************************************************************************************
*Function   : SM__vAllInputInvaildProcess                                                                 *
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
static void SM__vAllInputInvaildProcess(void)
{
	SM__stMainObject.u16TargetIndicateSpeed = 0;
	SM__stMainObject.u16CurrentIndicateSpeed = 0;
	SM__stMainObject.u16LastCurrentIndicateSpeed = 0;

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
	/*Ignition off is no damping to sweep pointer so homing immediately*/
	SM__vGaugeDoHoming();
#endif 

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)
	SM__stMainObject.u16LastTargetIndicateSpeed = 0;	
	SM__stMainObject.u16BarTargetStepCounts = 0;
	SM__stMainObject.u16BarCurrentStepCounts = 0;
#endif

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)
	/*Send SBUS message*/
	SM__vSBUSSendMessage();
#endif  
}
/**********************************************************************************************************
*Function   : SM__boDampingHandling                                                                       *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
static boolean SM__boDampingHandling(void)
{
	if(SM__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate == 1u) //1u means need to update current immediately
	{
		SM__stMainObject.u16CurrentIndicateSpeed = SM__stMainObject.u16TargetIndicateSpeed;
		
		SM__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 2u; //2u means update operation is already done
	}
	else
	{	//Full dial use only one damping model
#if (SM_CFG_DAMPING_MODEL == SM_CFG_THREAD_DAMPING_MODEL)
		SM_CORE__u16DampingModel_Thread(&SM__stMainObject.u16TargetIndicateSpeed,\
										&SM__stMainObject.u16CurrentIndicateSpeed,\
										 SM__u16DampingModel_Thread_Parameter); 
#elif(SM_CFG_DAMPING_MODEL == SM_CFG_KX_PLUS_B_DAMPING_MODEL)
		SM_CORE__u16DampingModel_kX_Plus_b(&SM__stMainObject.u16TargetIndicateSpeed,\
										   &SM__stMainObject.u16CurrentIndicateSpeed,\
										    SM__stDampingModel_KXPB_Parameter);
#elif(SM_CFG_DAMPING_MODEL == SM_CFG_PID_DAMPING_MODEL)
		SM_CORE__u16DampingModel_PID(&SM__stMainObject.u16TargetIndicateSpeed,\
									 &SM__stMainObject.u16CurrentIndicateSpeed,\
									  SM__stDampingModel_PID_Parameter);
#elif(SM_CFG_DAMPING_MODEL == SM_CFG_MODEL_FROM_CONFIG_CODE)

		/*Calculate current indicate speed from formula*/
		SM_CFG_vFormulaOfUserDefinedDampingOperation(&SM__stMainObject);

#else //No damping

		SM__stMainObject.u16CurrentIndicateSpeed = SM__stMainObject.u16TargetIndicateSpeed;

#endif	
		/* digital speed hysteresis */
#if(SM_CFG_DIGITAL_SPEED_HYSTERESIS)
		SM__u16TaskCnt++;
		//if(SM__u16TaskCnt % 50)
		if(0)
		{
			//SM__stMainObject.u16LastCurrentIndicateSpeed = SM__stMainObject.u16CurrentIndicateSpeed;
		}		
		else if((SM__stMainObject.u8MenuUnit == SM_CFG_IMPERIAL_UNIT))
		{			
			if((SM__stMainObject.u16CurrentIndicateSpeed*64/103) > ((SM__stMainObject.u16LastCurrentIndicateSpeed*64/103) + (1*SM_CFG_VALUE_FACTOR1)))
			{
				/*Keep previous */
				SM__stMainObject.u16LastCurrentIndicateSpeed = SM__stMainObject.u16CurrentIndicateSpeed;
			}
			else if(((SM__stMainObject.u16CurrentIndicateSpeed*64/103) + (1*SM_CFG_VALUE_FACTOR1)) < (SM__stMainObject.u16LastCurrentIndicateSpeed*64/103))
			{	
				/*Keep previous */
				SM__stMainObject.u16LastCurrentIndicateSpeed = SM__stMainObject.u16CurrentIndicateSpeed;
			}
			else
			{
				//SM__stMainObject.u16CurrentIndicateSpeed = SM__stMainObject.u16LastCurrentIndicateSpeed;
			}
			SM__u16TaskCnt = 0;
			//SM__stMainObject.u16CurrentIndicateSpeed = SM__stMainObject.u16LastCurrentIndicateSpeed;
		}
		else
		{
			
			if(SM__stMainObject.u16CurrentIndicateSpeed > (SM__stMainObject.u16LastCurrentIndicateSpeed + (1*SM_CFG_VALUE_FACTOR1)))
			{
				/*Keep previous */
				SM__stMainObject.u16LastCurrentIndicateSpeed = SM__stMainObject.u16CurrentIndicateSpeed;
			}
			else if((SM__stMainObject.u16CurrentIndicateSpeed + (1*SM_CFG_VALUE_FACTOR1)) < SM__stMainObject.u16LastCurrentIndicateSpeed)
			{	
				/*Keep previous */
				SM__stMainObject.u16LastCurrentIndicateSpeed = SM__stMainObject.u16CurrentIndicateSpeed;
			}
			else
			{
				//SM__stMainObject.u16CurrentIndicateSpeed = SM__stMainObject.u16LastCurrentIndicateSpeed;
			}
			SM__u16TaskCnt = 0;
			//SM__stMainObject.u16CurrentIndicateSpeed = SM__stMainObject.u16LastCurrentIndicateSpeed;
		}

		if(u8PreMenuUnit != SM__stMainObject.u8MenuUnit)
		{
			SM__stMainObject.u16LastCurrentIndicateSpeed = SM__stMainObject.u16CurrentIndicateSpeed;
			u8PreMenuUnit = SM__stMainObject.u8MenuUnit;
		}
		/* if VehSpd = 0km/h, Vehicle Speed display 0 */
		if(SM__stMainObject.u16CurrentIndicateSpeed == SM_MIN_DISPLAY_SPEED)
		{
			SM__stMainObject.u16CurrentIndicateSpeed = 0;
			SM__stMainObject.u16LastCurrentIndicateSpeed = 0;
		}
		else
		{
			SM__stMainObject.u16CurrentIndicateSpeed = SM__stMainObject.u16LastCurrentIndicateSpeed;
		}
		
#endif
	}
	return TRUE;
}
/**********************************************************************************************************
*Function   : SM__vSetGaugeTargetStepCounts                                                               *
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
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
static void SM__vSetGaugeTargetStepCounts(uint16 u16TargetStepCounts)
{
	if(SM_CFG_EOL_MODE_ENABLE||SM_CFG_ETM_MODE_ENABLE||SM_CFG_DIAGNOSIS_MODE_ENABLE)
	{
		
	}	
	else 
	{
		SM__stMainObject.u16GaugeTargetStepCounts = \
		SM_CORE__u16FormatDataAccuracy(SM__stMainObject.u16GaugeMaxMotorStepCounts,\
									   SM__stMainObject.u16GaugeMinMotorStepCounts,\
									   1,0,0,\
									   u16TargetStepCounts);
	}
}
#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : SM__vSetGaugeCurrentStepCounts                                                              *
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
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
static void SM__vSetGaugeCurrentStepCounts(UINT16 u16CurrentStepCounts)
{
	if(SM_CFG_EOL_MODE_ENABLE||SM_CFG_ETM_MODE_ENABLE||SM_CFG_DIAGNOSIS_MODE_ENABLE)
	{
		
	}	
	else 
	{
		SM__stMainObject.u16GaugeCurrentStepCounts = \
		SM_CORE__u16FormatDataAccuracy(SM__stMainObject.u16GaugeMaxMotorStepCounts,\
									   SM__stMainObject.u16GaugeMinMotorStepCounts,\
									   1,0,0,\
									   u16CurrentStepCounts);
	}
}
#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : SM__boCalculateGaugeStepCounts                                                              *
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
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
static boolean SM__boCalculateGaugeStepCounts(void)
{
	//Target indicate speed
	SM__vSetGaugeTargetStepCounts(SM_CORE_u16CalulauteGaugeTableStepCounts((uint16*)&SM__stMainObject.u16GaugeTable,SM__stMainObject.u16TargetIndicateSpeed));

	//Current indicate speed
	SM__vSetGaugeCurrentStepCounts(SM_CORE_u16CalulauteGaugeTableStepCounts((uint16*)&SM__stMainObject.u16GaugeTable,SM__stMainObject.u16CurrentIndicateSpeed));

	return TRUE;
}
#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : SM__vGaugeDoHoming                                                                          *
*                                                                                                         *
*Description: TBD		                                                                                  *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
static void SM__vGaugeDoHoming(void)
{
	SM__vSetGaugeTargetStepCounts(SM__stMainObject.u16GaugeMinMotorStepCounts);
	SM__vSetGaugeCurrentStepCounts(SM__stMainObject.u16GaugeMinMotorStepCounts);
}
#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : SM__boCalculateGaugeTargetStepCountsLimit                                                   *
*                                                                                                         *
*Description: The function is used to calculate the  maximum and minimum step counts of                   *
*   		  speedometer in NVM                                                                          *
*			                                                                                              *
*Parameter	: void	                                                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
static boolean SM__boCalculateGaugeTargetStepCountsLimit(void)
{	
	SM__stMainObject.u16GaugeMaxMotorStepCounts = \
	(SM_CORE_u16CalulauteGaugeTableStepCounts((uint16*)&SM__stMainObject.u16GaugeTable,SM_CFG_VALUE_MAX));

	SM__stMainObject.u16GaugeMinMotorStepCounts = \
	(SM_CORE_u16CalulauteGaugeTableStepCounts((uint16*)&SM__stMainObject.u16GaugeTable,SM_CFG_VALUE_MIN));

	return TRUE;
}
#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : SM__boCheckEEPROMGaugeTableProcess                                                         *
*                                                                                                         *
*Description: TBD		                                                                                  *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if (((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)&&(SM_CFG_GAUGE_TBL_SOURCE == SM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE))
static boolean SM__boCheckEEPROMGaugeTableProcess(void)
{
#if(SM_CFG_DEBUG == TRUE)
	boolean boPrintFlag = FALSE;
#endif 
	boolean boReturn = SM_CORE_boCheckGaugeTableProcess((UINT16*)&SM_CFG_GAUGE_EEPROM_TBL) ;

	if(FALSE == boReturn)
	{	
		SM_CORE_vSetSystemErrorStatus(SM_EEPROM_GAUGE_TBL_ERROR,&SM__stMainObject);
		
#if(SM_CFG_DEBUG == TRUE)
		if(boPrintFlag == FALSE)
		{
			boPrintFlag = TRUE;
printf("\
--Speedometer Module Debug: Configration Error--------------\r\n\
--Function Name : SM__boCheckEEPROMGaugeTableProcess\r\n\
--Error : Gauge table in EEPROM is invalid.\r\n\
------------------------------------------------------------\r\n");
		}
		else
		{
		
		}
#endif // (SM_CFG_DEBUG == TRUE)
	}
	else
	{
#if(SM_CFG_DEBUG == TRUE)
		boPrintFlag = FALSE;
#endif
	}	
	return boReturn;
}
#endif // (((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)&&(SM_CFG_GAUGE_TBL_SOURCE == SM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE))
/**********************************************************************************************************
*Function   : SM__vCheckROMGaugeTableProcess                                                             *
*                                                                                                         *
*Description: TBD		                                                                                  *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
static boolean SM__vCheckROMGaugeTableProcess(void)
{
#if(SM_CFG_DEBUG == TRUE)
	boolean boPrintFlag = FALSE;
#endif
	boolean boReturn = SM_CORE_boCheckGaugeTableProcess((uint16*)&SM__u16GaugeROMTbl) ;

	if	(FALSE == boReturn)
	{
		SM_CORE_vSetSystemErrorStatus(SM_ROM_GAUGE_TBL_ERROR,&SM__stMainObject);
		
#if(SM_CFG_DEBUG == TRUE)
	if(boPrintFlag == FALSE)
		{
			boPrintFlag = TRUE;
printf("\
--Speedometer Module Debug: Configration Error--------------\r\n\
--Function Name : SM__vCheckROMGaugeTableProcess\r\n\
--Error : Gauge table in ROM is invalid.\r\n\
------------------------------------------------------------\r\n");
		}
	else
	{
	
	}
#endif
	}
	else
	{

	}

	return boReturn;
}
#endif // ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : SM__vCopyROMGaugeTableProcess                                                               *
*                                                                                                         *
*Description: TBD		                                                                                  *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
static void SM__vCopyROMGaugeTableProcess(void)
{
	memcpy(&SM__stMainObject.u16GaugeTable[0],&SM__u16GaugeROMTbl[0],sizeof(SM__stMainObject.u16GaugeTable));
	SM__stMainObject.unFunctionFlag.stFuncFlag.GaugeTableSource = 1u;
}
#endif // ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : SM__vCopyEEPROMGaugeTableProcess                                                            *
*                                                                                                         *
*Description: TBD		                                                                                  *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if (((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)&&(SM_CFG_GAUGE_TBL_SOURCE == SM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE))
static void SM__vCopyEEPROMGaugeTableProcess(void)
{
	memcpy(&SM__stMainObject.u16GaugeTable[0],&SM_CFG_GAUGE_EEPROM_TBL[0],sizeof(SM__stMainObject.u16GaugeTable));
	SM__stMainObject.unFunctionFlag.stFuncFlag.GaugeTableSource = 2u;
}
#endif // (((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)&&(SM_CFG_GAUGE_TBL_SOURCE == SM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE))
/**********************************************************************************************************
*Function   : SM__boCalculateBarStepCounts                                                                *
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
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)
static boolean SM__boCalculateBarStepCounts(void)
{
	//Target indicate speed
	if(SM__stMainObject.u16TargetIndicateSpeed >= SM_CFG_VALUE_MAX)
	{
		SM__stMainObject.u16BarTargetStepCounts = (SM_CFG_BAR_DISPLAY_STEPS-1);
	}
#if (SM_CFG_VALUE_MIN > 0)	//Aviod QAC warning
	else if(SM__stMainObject.u16TargetIndicateSpeed <= SM_CFG_VALUE_MIN)
#else			
	else if(SM__stMainObject.u16TargetIndicateSpeed == SM_CFG_VALUE_MIN)
#endif	
	{
		SM__stMainObject.u16BarTargetStepCounts = 0;
	}
	else
	{
		SM__stMainObject.u16BarTargetStepCounts = \
			SM_CORE_u16CalulauteBarTableStepCounts(&SM__stBarROMTbl,\
													SM__stMainObject.unFunctionFlag.stFuncFlag.IncreaseClimate,\
													SM__stMainObject.u16BarTargetStepCounts,\
													SM__stMainObject.u16TargetIndicateSpeed);
	}
	
//Current indicate speed
	if(SM__stMainObject.u16CurrentIndicateSpeed >= SM_CFG_VALUE_MAX)
	{
		SM__stMainObject.u16BarCurrentStepCounts = (SM_CFG_BAR_DISPLAY_STEPS-1);
	}
#if (SM_CFG_VALUE_MIN > 0)	//Aviod QAC warning
	else if(SM__stMainObject.u16CurrentIndicateSpeed <= SM_CFG_VALUE_MIN)
#else			
	else if(SM__stMainObject.u16CurrentIndicateSpeed == SM_CFG_VALUE_MIN)
#endif	
	{
		SM__stMainObject.u16BarCurrentStepCounts = 0;
	}
	else
	{
		SM__stMainObject.u16BarCurrentStepCounts = \
			SM_CORE_u16CalulauteBarTableStepCounts(&SM__stBarROMTbl,\
													SM__stMainObject.unFunctionFlag.stFuncFlag.IncreaseClimate,\
													SM__stMainObject.u16BarCurrentStepCounts,\
													SM__stMainObject.u16CurrentIndicateSpeed);
	}
	
	return TRUE;
}
#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)
/**********************************************************************************************************
*Function   : SM__vSBUSSendMessage                                                                        *
*                                                                                                         *
*Description: TBD		                                                                                  *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)
static void SM__vSBUSSendMessage(void)
{
	IPC_M2S_ClusterAppAPPSpeedo_t ipc_SendSpeedo = {0};
	s_SpeedoInfo_t SpeedoInfo = {0};
	SM__vCANOutputMessage();

	/* Send Other module */
	SpeedoInfo.Msg_missingSts =  Speedo_Msg_missingSts;
	SpeedoInfo.VehSpdVld = Speedo_VehSpdVld;
	SpeedoInfo.IndicateSpeed = (uint16)SM_API_u32GetCurrentIndicateVehicleSpeed(ACCUACY_1KM_B);
	SpeedoInfo.RealSpeed = (uint16)SM_CORE__u32FormatDataAccuracy(SM_CFG_VALUE_MAX,SM_CFG_VALUE_MIN,\
										  (uint16)ACCUACY_1KM_B/100,0,\
										  SM_CFG_SPEED_VALUE_INTERFACE_ROUND_CONFIG,\
										  SM__stMainObject.u32RealSpeedFromCAN);
	SpeedoInfo.RealSpeedBak = (uint16)SM_CORE__u32FormatDataAccuracy(SM_CFG_VALUE_MAX,SM_CFG_VALUE_MIN,\
										  (uint16)ACCUACY_1KM_B/100,0,\
										  SM_CFG_SPEED_VALUE_INTERFACE_ROUND_CONFIG,\
										  SM__stMainObject.u32RealSpeedFromCANBak);
	SpeedoInfo.VehRunSts = SM_API_u8AppVehRunningSts();
	SpeedoInfo.OverSpdWrnFlg = SM_API_u8AppOverSpeedWarningFlg();
	//SpeedoInfo.IndicateSpeedMile = (SM__stMainObject.u16CurrentIndicateSpeed * 64/103/10 + 5) / 10;
	SpeedoInfo.IndicateSpeedMile = (uint16)(((2u * SM__stMainObject.u16CurrentIndicateSpeed * 64u / 103u) + (1u * SM_CFG_VALUE_FACTOR1)) / (2u * SM_CFG_VALUE_FACTOR1));
	if(SpeedoInfo.IndicateSpeedMile > (SM_CFG_VALUE_IMPERIAL_MAX/100))
	{
		SpeedoInfo.IndicateSpeedMile = (uint16)(SM_CFG_VALUE_IMPERIAL_MAX/100);
	}
	SpeedoInfo.RealSpeedMile = (uint16)(SM__stMainObject.u32RealSpeedFromCAN * 64/103) / (10*SM_CFG_VALUE_FACTOR);/* 0.1mph */
	(void)Rte_Write_ppSR_SWCNormal_SpeedoInfo_Element(&SpeedoInfo);
	/* Send IPC */
	SM_API_vGetSpeedoInfo(&ipc_SendSpeedo);

	(void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_SPEEDOMETER, (uint8 *)&ipc_SendSpeedo, (uint16)sizeof(IPC_M2S_ClusterAppAPPSpeedo_t), FALSE);
}
#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)

static void SM__vCANOutputMessage(void)
{
	uint16 u16IP_VehSpdDisp = 0;
	uint16 u16IP_VehSpdDispMile = 0;

	uint8 SG_ABS3_StatusRet = 0;
		
#ifdef GWM_V35_PROJECT_TYPE_B02_SM
	uint16 VehSpdReceived = 0;
    SG_ABS3_StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD, (uint8 *)&VehSpdReceived, (uint8)sizeof(VehSpdReceived));
#elif defined GWM_V35_PROJECT_TYPE_B03_SM
	SG_ABS3 SM_SG_ABS3;
	SG_ABS3_ESP_FD2 SM_SG_ABS3_ESP_FD2;

	if(SM__stMainObject.u8CANType == SM_CFG_ABS3_CAN)
	{
		SG_ABS3_StatusRet = Rte_Read_SG_ABS3_SG_ABS3(&SM_SG_ABS3);
	}
	else if(SM__stMainObject.u8CANType == SM_CFG_ESP_CAN_FD)
	{
		SG_ABS3_StatusRet = Rte_Read_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2(&SM_SG_ABS3_ESP_FD2);
	}
#elif defined GWM_V35_PROJECT_TYPE_P03_SM
	uint16 VehSpdReceived = 0;
	SG_ABS3_StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD, (uint8 *)&VehSpdReceived, (uint8)sizeof(VehSpdReceived));
#elif defined GWM_V35_PROJECT_TYPE_P05_SM
	uint16 VehSpdReceived = 0;
	if(SM__stMainObject.u8CANType == SM_CFG_ABS3_CAN)
	{
		SG_ABS3_StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD_0X265, (uint8 *)&VehSpdReceived, (uint8)sizeof(VehSpdReceived));
	}
	else if(SM__stMainObject.u8CANType == SM_CFG_ESP_CAN_FD)
	{
		SG_ABS3_StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD_0X137, (uint8 *)&VehSpdReceived, (uint8)sizeof(VehSpdReceived));
	}
#elif defined GWM_V35_PROJECT_TYPE_A07_SM
	uint16 VehSpdReceived = 0;
	if(SM__stMainObject.u8CANType == SM_CFG_ABS3_CAN)
	{
		SG_ABS3_StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD, (uint8 *)&VehSpdReceived, (uint8)sizeof(VehSpdReceived));
	}
	else if(SM__stMainObject.u8CANType == SM_CFG_ESP_CAN_FD)
	{
		//V4.1 DEL
	}
#elif defined GWM_V35_PROJECT_TYPE_D01_SM
	uint16 VehSpdReceived = 0;
	SG_ABS3_StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD, (uint8 *)&VehSpdReceived, (uint8)sizeof(VehSpdReceived));
#elif defined GWM_V35_PROJECT_TYPE_D02_SM
	uint16 VehSpdReceived = 0;
	SG_ABS3_StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD, (uint8 *)&VehSpdReceived, (uint8)sizeof(VehSpdReceived));
#elif defined GWM_V35_PROJECT_TYPE_D03_SM
	uint16 VehSpdReceived = 0;
	SG_ABS3_StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD, (uint8 *)&VehSpdReceived, (uint8)sizeof(VehSpdReceived));
#else
#endif

	if(FALSE == SM_CORE_boCheckSystemErrorStatus(SM_IGN_OFF,&SM__stMainObject))
	{
		if (TRUE == GET_CAN_MESSAGE_MISSING_SM(SG_ABS3_StatusRet)) 
		{
			u16IP_VehSpdDisp = 0x0;
			u16IP_VehSpdDispMile = 0x0;	
		}
		else
		{
			if(FALSE == SM_CORE_boCheckSystemErrorStatus(SM_ABS_CAN_MSG_INVALID,&SM__stMainObject))
			{
				u16IP_VehSpdDisp = (uint16)SM_API_u32GetCurrentIndicateVehicleSpeed(ACCUACY_1KM_B);
				u16IP_VehSpdDispMile = (uint16)(((2 * SM__stMainObject.u16CurrentIndicateSpeed * 64 / 103) + (1 * SM_CFG_VALUE_FACTOR1)) / (2 * SM_CFG_VALUE_FACTOR1));
				
				if(u16IP_VehSpdDisp > 0xFF)
				{
					u16IP_VehSpdDisp = 0xFF;
				}
				u16IP_VehSpdDisp = u16IP_VehSpdDisp * 2u;
				
				if(u16IP_VehSpdDispMile > (SM_CFG_VALUE_IMPERIAL_MAX / 100))
				{
					u16IP_VehSpdDispMile = (uint16)((SM_CFG_VALUE_IMPERIAL_MAX) / 100);
				}
			}
			else
			{
				u16IP_VehSpdDisp = 0x1FF;
				u16IP_VehSpdDispMile = 0xFF;
			}	
		}
	}
	else
	{
		u16IP_VehSpdDisp = 0x0;
		u16IP_VehSpdDispMile = 0x0;
	}
	(void)Rte_Write_Sd_CanOutputViaGateway_IP_VehSpdDisp(u16IP_VehSpdDisp);
	(void)Rte_Write_Sd_CanOutputViaGateway_IP_VehSpdUnit(SM__stMainObject.u8MenuUnit);
	(void)Rte_Write_Sd_CanOutputViaGateway_IP_VelSpdDisp_Mile((uint8)u16IP_VehSpdDispMile);

}

/**********************************************************************************************************
*Function   : SM__boSBUSSendOperation                                                                     *
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
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)
static boolean SM__boSBUSSendOperation(void)
{	
	SM__stMainObject.u16SBUSSendCycle = \
	SM_CORE__u16FormatDataAccuracy(SM_CFG_VEHICLE_SPEED_SBUS_MSG_SEND_TIME_CYCLE_MAXIMUM,\
								   1,/*Cycle can not be zero*/\
								   SM_CFG_TIME_TASK_CYCLE,0,(boolean)0,\
								   SM_CFG_VEHICLE_SPEED_SBUS_MSG_SEND_TIME_CYCLE);
	if(SM__stMainObject.u16SBUSSendCycle < 1)
	{
		SM__stMainObject.u16SBUSSendCycle = 1;
	}
	if(SM__stMainObject.stTimer.u16ReservedTick % SM__stMainObject.u16SBUSSendCycle)
	{
		/*Do nothing*/
	}
	else
	{
		SM__stMainObject.stTimer.u16ReservedTick = 0;

		SM__vSBUSSendMessage();
	}

	SM__stMainObject.stTimer.u16ReservedTick ++;
	
	return TRUE;
}
#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)
/**********************************************************************************************************
*Function   : SM__vSystemErrorObjectOperationProcess                                                      *
*                                                                                                         *
*Description: The function is used to check ABS CAN message is received	less than one frame               *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
static void SM__vSystemErrorObjectOperationProcess(void)
{
	SM__stMainObject.u16LastTargetIndicateSpeed = 0 ;
	SM__stMainObject.u16TargetIndicateSpeed = 0 ;
	SM__stMainObject.u16LastCurrentIndicateSpeed = 0;
	SM__stMainObject.u16CurrentIndicateSpeed = 0 ;
	SM__stMainObject.u32VaildRealSpeed = 0 ;

#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
	SM__stMainObject.u32RealSpeedFromCANBak = 0;
	SM__stMainObject.u32RealSpeedFromCAN = 0 ;
#endif 

#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
	SM__stMainObject.u16RealSpeedFromPWM = 0 ;
#endif

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	SM__stMainObject.u16GaugeTargetStepCounts = 0;
	SM__stMainObject.u16GaugeCurrentStepCounts = 0;
#endif

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)
	SM__stMainObject.u16BarTargetStepCounts = 0;
	SM__stMainObject.u16BarCurrentStepCounts = 0;
#endif
	
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)
	/*Send SBUS message*/
	SM__vSBUSSendMessage();
#endif

}

static boolean SM__boVehicleConfig(void)
{
	SM_CFG_vVehicleConfig(&SM__stMainObject);

	return TRUE;
}

uint8 SM_API_u8AppVehRunningSts(void)
{	
	uint16 u16RealSpeedFromCAN = 0;
	
	u16RealSpeedFromCAN = (uint16)(SM__stMainObject.u32RealSpeedFromCAN / SM_CFG_VALUE_FACTOR);
	if(FALSE == SM_CORE_boCheckSystemErrorStatus(SM_ABS_CAN_MSG_INVALID,&SM__stMainObject))
	{
		if(u16RealSpeedFromCAN > 300)
		{
			SM__VehRunningSts = 1;
		}
		else if(u16RealSpeedFromCAN == 0)
		{
			SM__VehRunningSts = 0;
		}
		else
		{
			/* keep previous status */
		}
	}
	else
	{
		SM__VehRunningSts = 0;
	}

	return (SM__VehRunningSts);
}

uint8 SM_API_u8AppVehRunningStsRead(void)
{
	return (SM__VehRunningSts);
}

uint8 SM_API_u8AppOverSpeedWarningFlg(void)
{
	uint16 u16CurrentIndicatedSpeed = 0;
	uint16 u16CurrentIndicatedSpeedMile = 0;
	MenuSetData_t menuSetData;
	(void)Rte_Read_rpSR_SWCNormal_MenuSetData_Element(&menuSetData);
	//u16CurrentIndicatedSpeed = (uint16)((2 * SM__stMainObject.u16CurrentIndicateSpeed + 1 * SM_CFG_VALUE_FACTOR1)/(2 * SM_CFG_VALUE_FACTOR1));
	u16CurrentIndicatedSpeed = (uint16)(((2 * SM__stMainObject.u16CurrentIndicateSpeed) + (1 * SM_CFG_VALUE_FACTOR1))/(2 * SM_CFG_VALUE_FACTOR1));
	//u16CurrentIndicatedSpeed = SM_API_u16GetCurrentIndicateVehicleSpeed(ACCUACY_1KM);
	//u16CurrentIndicatedSpeedMile = (SM__stMainObject.u16CurrentIndicateSpeed * 64/103);
	u16CurrentIndicatedSpeedMile = (uint16)(((2 * SM__stMainObject.u16CurrentIndicateSpeed * 64/103) + (1 * SM_CFG_VALUE_FACTOR1))/(2 * SM_CFG_VALUE_FACTOR1));
	if((menuSetData.OdometerUnit == 0) || (menuSetData.OdometerUnit == 1))
	{
		if(u16CurrentIndicatedSpeed >= SM_OVER_SPEED_ON)
		{
			SM__OverSpdWarningFlg = 1;
		}
		else if(u16CurrentIndicatedSpeed < SM_OVER_SPEED_OFF)
		{
			SM__OverSpdWarningFlg = 0;
		}
		else
		{
		
		}
	}
	else
	{
		if(u16CurrentIndicatedSpeedMile >= 75)
		{
			SM__OverSpdWarningFlg = 1;
		}
		else if(u16CurrentIndicatedSpeedMile < 70)
		{
			SM__OverSpdWarningFlg = 0;
		}
		else
		{
		
		}
	}
	
	return (SM__OverSpdWarningFlg);
}

void SM_API_vGetSpeedoInfo(IPC_M2S_ClusterAppAPPSpeedo_t *stSpeedoinfo)
{
	/* Vehicle speed unit update */ 
	uint32 u32TempData = 0;

	stSpeedoinfo->VehSpdUnit = SM__stMainObject.u8MenuUnit;
	u32TempData = SM_API_u32GetCurrentIndicateVehicleSpeed(ACCUACY_1KM_B) * 10u;
	stSpeedoinfo->VehSpdCalculated = (int32_t)u32TempData;
	
	if(SM_CFG_IMPERIAL_UNIT == stSpeedoinfo->VehSpdUnit)
	{
		u32TempData = (((2u * SM__stMainObject.u16CurrentIndicateSpeed * 64u / 103u) + (1u * SM_CFG_VALUE_FACTOR1)) / (2u * SM_CFG_VALUE_FACTOR1)) * 10u;
		stSpeedoinfo->VehSpdCalculated = (int32_t)u32TempData;
			//(stSpeedoinfo->VehSpdCalculated * 640 / 103 + 5) / 10;
		if(stSpeedoinfo->VehSpdCalculated >= (SM_CFG_VALUE_IMPERIAL_MAX/10))
		{
			u32TempData = SM_CFG_VALUE_IMPERIAL_MAX / 10u;
			stSpeedoinfo->VehSpdCalculated = (int32_t)u32TempData;
		}

	}
	
	stSpeedoinfo->RedDispaly = 0;
	stSpeedoinfo->VehRunningSts = SM_API_u8AppVehRunningStsRead();
	stSpeedoinfo->VehSpdMax = SM__stMainObject.u16VehSpdMax * 10;
	stSpeedoinfo->VehSpdAnalog = (int32_t)SM__stMainObject.u16TargetIndicateSpeed / 1000;
	if(SM_CFG_IMPERIAL_UNIT == stSpeedoinfo->VehSpdUnit)
	{
		stSpeedoinfo->VehSpdAnalog = (int32_t)SM__stMainObject.u16TargetIndicateSpeed * 64 / 103 / 1000;
		if(stSpeedoinfo->VehSpdAnalog >= (SM_CFG_VALUE_IMPERIAL_MAX/10))
		{
			u32TempData = SM_CFG_VALUE_IMPERIAL_MAX / 10u;
			stSpeedoinfo->VehSpdAnalog = (int32_t)u32TempData;
		}

	}
    else
    {
		if(stSpeedoinfo->VehSpdAnalog >= (SM_CFG_VALUE_MAX/10))
		{
			u32TempData = SM_CFG_VALUE_MAX / 10u;
			stSpeedoinfo->VehSpdAnalog = (int32_t)u32TempData;
		}
    }

	stSpeedoinfo->VehSpdReal = (int32_t)SM_CORE__u32FormatDataAccuracy(SM_CFG_VALUE_MAX,SM_CFG_VALUE_MIN,\
										  ((uint16)ACCUACY_1KM_B / 100u), (sint16)FALSE,\
										  SM_CFG_SPEED_VALUE_INTERFACE_ROUND_CONFIG,\
										  SM__stMainObject.u32RealSpeedFromCAN);
}
#define Common_Normal_STOP_SEC_CODE
#include "Common_Normal_MemMap.h" 

/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
