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
*Description : Tachometer module application interface head file.                                         *
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
#include "Compiler.h"
#include "Platform_Types.h"
#include "IPC_ClusterApp.h"
#include <string.h> /* memcpy */

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_TM_Config.h"
#include "SWC_TM_Core.h"
#include "SWC_TM_Interface.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Tachometer Main Object Structure Variable															  *
*																								          *
*																								          *
**********************************************************************************************************/
#define SWC_TM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_TM_MemMap.h"

static TM_CFG_tstMAIN_OBJECT TM__stMainObject ;
static uint8 TM__u8EngRunSts;
static uint8 l_TM_Msg_missingSts_last_U8 = 0;
static uint8 l_TM_ClusterStateLast_U8 = SYSTEMSTATE_Cluster_OFF;
boolean l_TMDebugLogFlag = FALSE;
#define SWC_TM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_TM_MemMap.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Tachometer Gauge ROM Table Const															          *
*																								          *
*																								          *
**********************************************************************************************************/
#define SWC_TM_START_SEC_CONST_UNSPECIFIED
#include "SWC_TM_MemMap.h"

#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)

const uint16 TM__u16GaugeROMTbl[][2] = TM_CFG_GAUGE_ROM_TBL;

#endif 
/**********************************************************************************************************
*																								          *
*																								          *
*	Tachometer Bar ROM Table Const            															  *
*																								          *
*																								          *
**********************************************************************************************************/
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)

const TM_tstBAR_TBL  TM__stBarROMTbl[] = TM_CFG_BAR_ROM_TBL;

#endif
/**********************************************************************************************************
*																								          *
*																								          *
*	Speedometer Damping Parameter Const           														  *
*																								          *
*																								          *
**********************************************************************************************************/
#if (TM_CFG_DAMPING_MODEL == TM_CFG_THREAD_DAMPING_MODEL)
	
const uint16 TM__u16DampingModel_Thread_Parameter = TM_CFG_THREAD_DAMPING_MODEL_C;

#elif (TM_CFG_DAMPING_MODEL == TM_CFG_KX_PLUS_B_DAMPING_MODEL)

const TM_CFG_tstDAMPING_MODEL_KXPB_PARAMETER TM__stDampingModel_KXPB_Parameter = {TM_CFG_KXPB_DAMPING_MODEL_K1,\
																				  TM_CFG_KXPB_DAMPING_MODEL_K2,\
																				  TM_CFG_KXPB_DAMPING_MODEL_B};

#elif (TM_CFG_DAMPING_MODEL == TM_CFG_PID_DAMPING_MODEL)

const TM_CFG_tstDAMPING_MODEL_PID_PARAMETER TM__stDampingModel_PID_Parameter = {TM_CFG_PID_DAMPING_MODEL_PREFILTER_RATIO_1,\
																		        TM_CFG_PID_DAMPING_MODEL_PREFILTER_RATIO_2,\
																		        TM_CFG_PID_DAMPING_MODEL_KP1,\
																			    TM_CFG_PID_DAMPING_MODEL_KP2,\
																			    TM_CFG_PID_DAMPING_MODEL_TI1,\
																			    TM_CFG_PID_DAMPING_MODEL_TI2,\
																			    TM_CFG_PID_DAMPING_MODEL_TD1,\
																			    TM_CFG_PID_DAMPING_MODEL_TD2,\
																			    TM_CFG_PID_DAMPING_MODEL_C};
#else

#endif 

#define SWC_TM_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_TM_MemMap.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Tachometer Common Static Function		 														      *
*																								          *
*																								          *
**********************************************************************************************************/
#define SWC_TM_START_SEC_CODE
#include "SWC_TM_MemMap.h" 
#ifdef GWM_V35_PROJECT_TYPE_B02
#define SWC_TM_ADAPT_B02
#elif defined GWM_V35_PROJECT_TYPE_B03
#define SWC_TM_ADAPT_B03
#elif defined GWM_V35_PROJECT_TYPE_P03
#define SWC_TM_ADAPT_P03
#elif defined GWM_V35_PROJECT_TYPE_P05
#define SWC_TM_ADAPT_P05
#else
#define SWC_TM_ADAPT_NULL
#endif 
static boolean TM__boPowerModeCheckProcess(void);

static void TM__vPowerModeIgnitionOffProcess(void);

#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)

static boolean TM__boCANMessageValidCheckProcess(void);

static void TM__vGetEngineSpeedFromCAN(void);

static void TM__vCANMessageInvaildProcess(void);

#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)

#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)

static boolean TM__boPWMSignalValidCheckProcess(void);

static void TM__vGetEngineSpeedFromPWM(void);

static void TM__vPWMSignalInvaildProcess(void);

#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)

static boolean TM__boCalculateTargetEngineSpeed(void);

static void TM__vAllInputInvaildProcess(void);

static boolean TM__boDampingHandling(void);

#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)

static void TM__vSetGaugeTargetStepCounts(uint16 u16TargetStepCounts);

static void TM__vSetGaugeCurrentStepCounts(uint16 u16CurrentStepCounts);

static boolean TM__boCalculateGaugeStepCounts(void);

static boolean TM__boCalculateGaugeTargetStepCountsLimit(void);

static void TM__vGaugeDoHoming(void);

static boolean TM__vCheckROMGaugeTableProcess(void);

static void TM__vCopyROMGaugeTableProcess(void);

#if (TM_CFG_GAUGE_TBL_SOURCE == TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
static boolean TM__boCheckEEPROMGaugeTableProcess(void);

static void TM__vCopyEEPROMGaugeTableProcess(void);

#endif //(TM_CFG_GAUGE_TBL_SOURCE == TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)

#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)

static boolean TM__boCalculateBarStepCounts(void);

#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)

#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_SBUS) != FALSE)

static void TM__vSBUSSendMessage(void);

static boolean TM__boSBUSSendOperation(void);

#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_SBUS) != FALSE)
static boolean TM__boVehicleConfig(void);
static void TM__vSystemErrorObjectOperationProcess(void);
static uint8 TM__vApp_setEngRunSts(void);
#define SWC_TM_STOP_SEC_CODE
#include "SWC_TM_MemMap.h"
/**********************************************************************************************************
*																								          *
*																								          *
*	Tachometer Custom Static Function																      *
*																								          *
*																								          *
**********************************************************************************************************/

//None

/**********************************************************************************************************
*																								          *
*																								          *
*	Tachometer Process Map																				  *
*																								          *
*																								          *
**********************************************************************************************************/

/*************************************************************************************************************************************************************************************************************/
/*ProcessName                Process                                SucceedEnable      FaildEnable              AfterSucceed                 AfterFaild                         ContinueWhen
                                                                    Status             Status                   Operation                    Operation                          Faild       */
#define SWC_TM_START_SEC_CONST_UNSPECIFIED
#include "SWC_TM_MemMap.h"

static TM_tstPROCESS TM_stTimeTask_ProcessTable[] = {
/*Power Mode */            { TM__boPowerModeCheckProcess ,          TM_KEEP_PREVIOUS , TM_IGN_OFF ,             TM_DO_NOTHING ,              TM__vPowerModeIgnitionOffProcess , (boolean)FALSE            },
/*Vehicle configuration */ { TM__boVehicleConfig ,                  TM_KEEP_PREVIOUS , TM_KEEP_PREVIOUS ,       TM_DO_NOTHING ,              TM_DO_NOTHING ,                    TM_NOT_CONCERNED },
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/*CAN Input */             { TM__boCANMessageValidCheckProcess ,    TM_KEEP_PREVIOUS , TM_EMS_CAN_MSG_INVALID , TM__vGetEngineSpeedFromCAN , TM__vCANMessageInvaildProcess ,    (boolean)TRUE             },
#endif 
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
/*PWM Input */			   { TM__boPWMSignalValidCheckProcess ,     TM_KEEP_PREVIOUS , TM_PWM_SIGNAL_INVALID ,  TM__vGetEngineSpeedFromPWM , TM__vPWMSignalInvaildProcess ,     (boolean)TRUE             },
#endif 
/*Calculate indicate */    { TM__boCalculateTargetEngineSpeed ,     TM_KEEP_PREVIOUS , TM_ALL_INPUT_INVALID ,   TM_DO_NOTHING ,              TM__vAllInputInvaildProcess ,      (boolean)FALSE            },
/*Damping handling */      { TM__boDampingHandling ,                TM_KEEP_PREVIOUS , TM_KEEP_PREVIOUS ,       TM_DO_NOTHING ,              TM_DO_NOTHING ,                    TM_NOT_CONCERNED },
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/*Calculate step counts */ { TM__boCalculateGaugeStepCounts ,       TM_KEEP_PREVIOUS , TM_KEEP_PREVIOUS ,       TM_DO_NOTHING ,              TM_DO_NOTHING ,                    TM_NOT_CONCERNED },
#endif
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)
/*Calculate step counts */ { TM__boCalculateBarStepCounts ,         TM_KEEP_PREVIOUS , TM_KEEP_PREVIOUS ,       TM_DO_NOTHING ,              TM_DO_NOTHING ,                    TM_NOT_CONCERNED },
#endif
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_SBUS) != FALSE)
/*SBUS send operation */   { TM__boSBUSSendOperation ,              TM_KEEP_PREVIOUS , TM_KEEP_PREVIOUS ,       TM_DO_NOTHING ,              TM_DO_NOTHING ,                    TM_NOT_CONCERNED },
#endif
						   { (void *)0,(TM_CFG_enSYSTEM_STATUS)0,(TM_CFG_enSYSTEM_STATUS)0,(void *)0,(void *)0,(boolean)0},\
						   };

#define SWC_TM_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_TM_MemMap.h"

/*************************************************************************************************************************************************************************************************************/

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
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#define SWC_TM_START_SEC_CODE
#include "SWC_TM_MemMap.h" 

void TM_API_vKSTimeTask(void)
{
#if(TM_CFG_TACHOMETER_FUNCTION == TRUE)
	if(FALSE == TM_CORE_boCheckSystemErrorStatus(TM_SYS_FAILD,&TM__stMainObject))
	{
		TM_CORE_vProcessControl((void *)TM_stTimeTask_ProcessTable,&TM__stMainObject);
	}
	else
	{
		TM__vSystemErrorObjectOperationProcess();
	}
#endif //(TM_CFG_TACHOMETER_FUNCTION == TRUE)
}
/**********************************************************************************************************
*Function   : TM_API_vKSRoundRobinTask                                                                    *
*                                                                                                         *
*Description: The function is called by DI-kernel at round-robin task list. if it used,can fill  it with  *
*             code.                                                                                       *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
void TM_API_vKSRoundRobinTask(void)
{
#if(TM_CFG_TACHOMETER_FUNCTION == TRUE)
	
#endif //(TM_CFG_TACHOMETER_FUNCTION == TRUE)
}
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
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
void TM_API_vKSColdInit(void)
{
	//Avoid Warning
	TM_CORE_vSetSystemErrorStatus(TM_SYS_DEFAULT,&TM__stMainObject);

	TM_CORE_vClearSystemErrorStatus(TM_SYS_DEFAULT,&TM__stMainObject);

	(void)TM_CORE_boCheckSystemErrorStatus(TM_SYS_DEFAULT,&TM__stMainObject);
	
#if(TM_CFG_TACHOMETER_FUNCTION == TRUE)
#if(TM_CFG_DEBUG == TRUE)
printf("\
------------------------------------------------------------\r\n\
--Tachometer Module Debug Mode Enable-----------------------\r\n\
------------------------------------------------------------\r\n");

	TM_CORE_vCheckModuleConfigration();

#endif

#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) == FALSE)

	TM_CORE_vSetSystemErrorStatus(TM_EMS_CAN_MSG_INVALID,&TM__stMainObject);
		
#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) == FALSE)

#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) == FALSE)

	TM_CORE_vSetSystemErrorStatus(TM_PWM_SIGNAL_INVALID,&TM__stMainObject);
		
#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) == FALSE)

#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	if (FALSE == TM__vCheckROMGaugeTableProcess())
	{
		TM_CORE_vSetSystemErrorStatus(TM_SYS_FAILD,&TM__stMainObject);
	}
#if (TM_CFG_GAUGE_TBL_SOURCE == TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
	else if (TRUE == TM__boCheckEEPROMGaugeTableProcess())
	{	
		TM__vCopyEEPROMGaugeTableProcess();
	}
#endif // (TM_CFG_GAUGE_TBL_SOURCE == TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
	else
	{
		TM__vCopyROMGaugeTableProcess();
	}
#endif // ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)

#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)
	if (FALSE == TM_CORE_boCheckBarTableProcess(&TM__stBarROMTbl))
	{
		TM_CORE_vSetSystemErrorStatus(TM_SYS_FAILD,&TM__stMainObject);
	}
	else
	{
		/*Bar table check ok*/
	}

#endif // ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)

	if(FALSE == TM_CORE_boCheckSystemErrorStatus(TM_SYS_FAILD,&TM__stMainObject))
	{
		//Function flag control
		TM_CORE_vFlagControl(TM_COLD_INIT,&TM__stMainObject);

#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
		/*Calculate gauge target step counts limit*/
		(void)TM__boCalculateGaugeTargetStepCountsLimit();
#endif // ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)

#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_SBUS) != FALSE)
		/*Send SBUS message*/
		TM__vSBUSSendMessage();
#endif  

		/*Clear count*/
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		TM__stMainObject.stCount.u8ECMEngineSpeedValueValidCount = TM_CFG_CAN_MSG_ENGINE_SPEED_VALID_COUNT_LIMIT;
		TM__stMainObject.stCount.u8EMSEngineSpeedStatusValidCount = TM_CFG_CAN_MSG_ENGINE_SPEED_VALID_COUNT_LIMIT;
		TM__stMainObject.stCount.u8ECMEngineSpeedValueInvalidCount = 0;
		TM__stMainObject.stCount.u8EMSEngineSpeedStatusInvalidCount = 0;
		
#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)

		TM__stMainObject.stCount.u8PWMValueInvalidCount = 0;

#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
	}
	else //System Faild,do nothing
	{

	}
#endif //(TM_CFG_TACHOMETER_FUNCTION == TRUE)
	TM__u8EngRunSts = 0;
}
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
**Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
void TM_API_vKSWarmInit(void)
{
#if(TM_CFG_TACHOMETER_FUNCTION == TRUE)

#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) == FALSE)

	TM_CORE_vSetSystemErrorStatus(TM_EMS_CAN_MSG_INVALID,&TM__stMainObject);
		
#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) == FALSE)

#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) == FALSE)

	TM_CORE_vSetSystemErrorStatus(TM_PWM_SIGNAL_INVALID,&TM__stMainObject);
		
#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) == FALSE)

#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	if (FALSE == TM__vCheckROMGaugeTableProcess())
	{
		TM_CORE_vSetSystemErrorStatus(TM_SYS_FAILD,&TM__stMainObject);
	}
#if (TM_CFG_GAUGE_TBL_SOURCE == TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
	else if (TRUE == TM__boCheckEEPROMGaugeTableProcess())
	{	
		TM__vCopyEEPROMGaugeTableProcess();
	}
#endif // (TM_CFG_GAUGE_TBL_SOURCE == TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
	else
	{
		TM__vCopyROMGaugeTableProcess();
	}
#endif // ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)

	if(FALSE == TM_CORE_boCheckSystemErrorStatus(TM_SYS_FAILD,&TM__stMainObject))
	{
		//Function flag control
		TM_CORE_vFlagControl(TM_WARM_INIT,&TM__stMainObject);
		
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
		/*Calculate gauge target step counts limit*/
		(void)TM__boCalculateGaugeTargetStepCountsLimit();
#endif // ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)

#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_SBUS) != FALSE)
		/*Send SBUS message*/
		TM__vSBUSSendMessage();
#endif  

		/*Clear count*/
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		TM__stMainObject.stCount.u8ECMEngineSpeedValueValidCount = TM_CFG_CAN_MSG_ENGINE_SPEED_VALID_COUNT_LIMIT;
		TM__stMainObject.stCount.u8EMSEngineSpeedStatusValidCount = TM_CFG_CAN_MSG_ENGINE_SPEED_VALID_COUNT_LIMIT;
		TM__stMainObject.stCount.u8ECMEngineSpeedValueInvalidCount = 0;
		TM__stMainObject.stCount.u8EMSEngineSpeedStatusInvalidCount = 0;
		
#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)

		TM__stMainObject.stCount.u8PWMValueInvalidCount = 0;

#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
	}
	else //System Faild,do nothing
	{

	}
#endif //(TM_CFG_TACHOMETER_FUNCTION == TRUE)
	TM__u8EngRunSts = 0;
}
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
void TM_API_vKSWakeUp(void)
{
	if(FALSE == TM_CORE_boCheckSystemErrorStatus(TM_SYS_FAILD,&TM__stMainObject))
	{
		//Function flag control
		TM_CORE_vFlagControl(TM_WAKE_UP,&TM__stMainObject);
		
	}
	else //System Faild,do nothing
	{

	}
}
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
void TM_API_vKSSleep(void)
{
	if(FALSE == TM_CORE_boCheckSystemErrorStatus(TM_SYS_FAILD,&TM__stMainObject))
	{
		//Function flag control
		TM_CORE_vFlagControl(TM_SLEEP,&TM__stMainObject);
		
	}
	else //System Faild,do nothing
	{

	}
}
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
void TM_API_vKSEnterAbnormalOperation(void)
{
#if(TM_CFG_TACHOMETER_FUNCTION == TRUE)
	if(FALSE == TM_CORE_boCheckSystemErrorStatus(TM_SYS_FAILD,&TM__stMainObject))
	{
		//Function flag control
		TM_CORE_vFlagControl(TM_ENTER_ABNORMAL,&TM__stMainObject);
		
		/*Clear count*/
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		TM__stMainObject.stCount.u8ECMEngineSpeedValueValidCount = TM_CFG_CAN_MSG_ENGINE_SPEED_VALID_COUNT_LIMIT;
		TM__stMainObject.stCount.u8EMSEngineSpeedStatusValidCount = TM_CFG_CAN_MSG_ENGINE_SPEED_VALID_COUNT_LIMIT;
		TM__stMainObject.stCount.u8ECMEngineSpeedValueInvalidCount = 0;
		TM__stMainObject.stCount.u8EMSEngineSpeedStatusInvalidCount = 0;
		
#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)

		TM__stMainObject.stCount.u8PWMValueInvalidCount = 0;

#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
	}
	else //System Faild,do nothing
	{

	}
#endif //(TM_CFG_TACHOMETER_FUNCTION == TRUE)
}
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
void TM_API_vKSExitAbnormalOperation(void)
{
#if(TM_CFG_TACHOMETER_FUNCTION == TRUE)
	if(FALSE == TM_CORE_boCheckSystemErrorStatus(TM_SYS_FAILD,&TM__stMainObject))
	{
		//Function flag control
		TM_CORE_vFlagControl(TM_EXIT_ABNORMAL,&TM__stMainObject);

		/*Clear count*/
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		TM__stMainObject.stCount.u8ECMEngineSpeedValueValidCount = TM_CFG_CAN_MSG_ENGINE_SPEED_VALID_COUNT_LIMIT;
		TM__stMainObject.stCount.u8EMSEngineSpeedStatusValidCount = TM_CFG_CAN_MSG_ENGINE_SPEED_VALID_COUNT_LIMIT;
		TM__stMainObject.stCount.u8ECMEngineSpeedValueInvalidCount = 0;
		TM__stMainObject.stCount.u8EMSEngineSpeedStatusInvalidCount = 0;
		
#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)

		TM__stMainObject.stCount.u8PWMValueInvalidCount = 0;

#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
	}
	else //System Faild,do nothing
	{

	}
#endif //(TM_CFG_TACHOMETER_FUNCTION == TRUE)
}
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
uint16 TM_API_u16GetTargetEngineSpeed(TM_API_enOUTPUT_ACCUACY enAccuacy)
{
	uint16 u16EngineSpeed = 0;
	if(ACCUACY_1RPM == enAccuacy)
	{
		u16EngineSpeed = TM_CORE__u16FormatDataAccuracy(TM_CFG_VALUE_MAX,TM_CFG_VALUE_MIN,\
													   (uint16)ACCUACY_1RPM,0,\
													   TM_CFG_ENGINE_SPEED_VALUE_INTERFACE_ROUND_CONFIG,\
													   TM__stMainObject.u16TargetEngineSpeed);
	}
	else if(ACCUACY_100RPM == enAccuacy)
	{
		u16EngineSpeed = TM_CORE__u16FormatDataAccuracy(TM_CFG_VALUE_MAX,TM_CFG_VALUE_MIN,\
													   (uint16)ACCUACY_100RPM,0,\
													   TM_CFG_ENGINE_SPEED_VALUE_INTERFACE_ROUND_CONFIG,\
													   TM__stMainObject.u16TargetEngineSpeed);
	}
	else
	{
		//Error status
	}	
	return (u16EngineSpeed);
}
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
uint16 TM_API_u16GetCurrentEngineSpeed(TM_API_enOUTPUT_ACCUACY enAccuacy)
{
	uint16 u16EngineSpeed = 0;
	if(ACCUACY_1RPM == enAccuacy)
	{
		u16EngineSpeed = TM_CORE__u16FormatDataAccuracy(TM_CFG_VALUE_MAX,TM_CFG_VALUE_MIN,\
													   (uint16)ACCUACY_1RPM,0,\
													   TM_CFG_ENGINE_SPEED_VALUE_INTERFACE_ROUND_CONFIG,\
													   TM__stMainObject.u16CurrentEngineSpeed);
	}
	else if(ACCUACY_100RPM == enAccuacy)
	{
#if (TM_CFG_LOW_ACCURACY_OUTPUT_USE_ROUND_HYSTERESIS == TRUE)

		u16EngineSpeed = TM_CORE__u16LowAccuaryOutputHysteresis(TM__stMainObject.u16CurrentEngineSpeed,ACCUACY_100RPM);

#else

		u16EngineSpeed = TM_CORE__u16FormatDataAccuracy(TM_CFG_VALUE_MAX,TM_CFG_VALUE_MIN,\
													   (uint16)ACCUACY_100RPM,0,\
													   TM_CFG_ENGINE_SPEED_VALUE_INTERFACE_ROUND_CONFIG,\
													   TM__stMainObject.u16CurrentEngineSpeed);

#endif //(TM_CFG_LOW_ACCURACY_OUTPUT_USE_ROUND_HYSTERESIS == TRUE)
	}
	else
	{
		//Error status
	}
	return (u16EngineSpeed);
}
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
uint16 TM_API_u16GetValidEngineSpeed(TM_API_enOUTPUT_ACCUACY enAccuacy)
{
	uint16 u16EngineSpeed = 0;
	if(ACCUACY_1RPM == enAccuacy)
	{
		u16EngineSpeed = TM_CORE__u16FormatDataAccuracy(TM_CFG_VALUE_MAX,TM_CFG_VALUE_MIN,\
													   (uint16)ACCUACY_1RPM,0,\
													   TM_CFG_ENGINE_SPEED_VALUE_INTERFACE_ROUND_CONFIG,\
													   TM__stMainObject.u16VaildEngineSpeed);
	}
	else if(ACCUACY_100RPM == enAccuacy)
	{
		u16EngineSpeed = TM_CORE__u16FormatDataAccuracy(TM_CFG_VALUE_MAX,TM_CFG_VALUE_MIN,\
													   (uint16)ACCUACY_100RPM,0,\
													   TM_CFG_ENGINE_SPEED_VALUE_INTERFACE_ROUND_CONFIG,\
													   TM__stMainObject.u16VaildEngineSpeed);
	}
	else
	{
		//Error status
	}	
	return (u16EngineSpeed);
}

/**********************************************************************************************************
*Function   : TM_API_u16GetGaugeParkCounts                                                                *
*                                                                                                         *
*Description: The function is used to get park step counts of gauge for call by stepper motor driver      *
*             modules                                                                                     *
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
uint16 TM_API_u16GetGaugeParkCounts(void)
{
	return (TM__stMainObject.u16GaugeMinMotorStepCounts);
}
#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : TM_API_u16GetGaugeMaxCounts                                                                 *
*                                                                                                         *
*Description: The function is used to get max step counts of gauge for call by stepper motor driver       *
*             modules                                                                                     *
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
uint16 TM_API_u16GetGaugeMaxCounts(void)
{
	return (TM__stMainObject.u16GaugeMaxMotorStepCounts);
}
#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : TM_API_u16GetGaugeTargetStepCounts                                                          *
*                                                                                                         *
*Description: The function is used to get target step counts of gauge for call by other modules           *
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
uint16 TM_API_u16GetGaugeTargetStepCounts(void)
{
	return (TM__stMainObject.u16GaugeTargetStepCounts);
}
#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : TM_API_u16GetGaugeCurrentStepCounts                                                         *
*                                                                                                         *
*Description: The function is used to get current step counts of gauge for call by other modules          *
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
uint16 TM_API_u16GetGaugeCurrentStepCounts(void)
{
	return (TM__stMainObject.u16GaugeCurrentStepCounts);
}
#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : TM_API_vDiagSetGaugeStatus                                                                  *
*                                                                                                         *
*Description: The function is used to set gauge status for call by diagnostic module		              *
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
void TM_API_vDiagSetGaugeStatus(TM_CFG_enDIAG_SET_GAUGE_STATUS enStatus)
{
	
}
#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : TM_API_vEOLSetGaugeStepCounts                                                               *
*                                                                                                         *
*Description: The function is used to set step counts of gauge for call by EOL module		              *
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
void TM_API_vEOLSetGaugeStepCounts(UINT16 u16TargetStepCounts)
{
	TM__stMainObject.u16GaugeTargetStepCounts = u16TargetStepCounts;
	TM__stMainObject.u16GaugeCurrentStepCounts = u16TargetStepCounts;
}
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
uint16 TM_API_u16GetBarTargetStepCounts(void)
{
	return (TM__stMainObject.u16BarTargetStepCounts);
}
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
uint16 TM_API_u16GetBarCurrentStepCounts(void)
{
	return (TM__stMainObject.u16BarCurrentStepCounts);
}
#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)	
/**********************************************************************************************************
*Function	: TM_API_vCANMessageCountProcess 															  *
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
void TM_API_vCANMessageCountProcess(void)
{
	uint8 u8EngSpdValid = 0;
	uint8 u8TgtEngSpdValid = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_TM
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_B03_TM
	Rte_Read_EngSpdVldty_EngSpdVldty(&u8EngSpdValid);
	Rte_Read_DCT3_TgtEngSpdIPValid_TgtEngSpdIPValid(&u8TgtEngSpdValid);
#elif defined GWM_V35_PROJECT_TYPE_P03_TM
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_P05_TM
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_A07_TM
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_D01_TM
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_D02_TM
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_D03_TM
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_P02_TM
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_P01_TM
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
#else
#endif
	if(TRUE != u8EngSpdValid)
	{
		TM__stMainObject.stCount.u8ECMEngineSpeedValueInvalidCount ++;
		
		TM__stMainObject.stCount.u8ECMEngineSpeedValueValidCount = 0;
	}
	else
	{
		TM__stMainObject.stCount.u8ECMEngineSpeedValueInvalidCount = 0;
		
		TM__stMainObject.stCount.u8ECMEngineSpeedValueValidCount ++;
	}

	if(TM__stMainObject.stCount.u8ECMEngineSpeedValueInvalidCount >= TM_CFG_CAN_MSG_ENGINE_SPEED_INVALID_COUNT_LIMIT)
	{
		TM__stMainObject.stCount.u8ECMEngineSpeedValueInvalidCount = TM_CFG_CAN_MSG_ENGINE_SPEED_INVALID_COUNT_LIMIT;
	}
	else
	{

	}

	if(TM__stMainObject.stCount.u8ECMEngineSpeedValueValidCount >= TM_CFG_CAN_MSG_ENGINE_SPEED_VALID_COUNT_LIMIT)
	{
		TM__stMainObject.stCount.u8ECMEngineSpeedValueValidCount = TM_CFG_CAN_MSG_ENGINE_SPEED_VALID_COUNT_LIMIT;
	}
	else
	{

	}

	if(FALSE == u8TgtEngSpdValid)
	{
		TM__stMainObject.stCount.u8EMSEngineSpeedStatusInvalidCount ++;
		
		TM__stMainObject.stCount.u8EMSEngineSpeedStatusValidCount = 0;
	}
	else
	{
		TM__stMainObject.stCount.u8EMSEngineSpeedStatusInvalidCount = 0;
		
		TM__stMainObject.stCount.u8EMSEngineSpeedStatusValidCount ++;
	}

	if(TM__stMainObject.stCount.u8EMSEngineSpeedStatusInvalidCount >= TM_CFG_CAN_MSG_ENGINE_SPEED_INVALID_COUNT_LIMIT)
	{
		TM__stMainObject.stCount.u8EMSEngineSpeedStatusInvalidCount = TM_CFG_CAN_MSG_ENGINE_SPEED_INVALID_COUNT_LIMIT;
	}
	else
	{

	}

	if(TM__stMainObject.stCount.u8EMSEngineSpeedStatusValidCount >= TM_CFG_CAN_MSG_ENGINE_SPEED_VALID_COUNT_LIMIT)
	{
		TM__stMainObject.stCount.u8EMSEngineSpeedStatusValidCount = TM_CFG_CAN_MSG_ENGINE_SPEED_VALID_COUNT_LIMIT;
	}
	else
	{

	}
}
#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/**********************************************************************************************************
*Function	: TM_API_boGetCANMessageInvalidStatus   													  *
*																										  *
*Description: TBD																						  *
*																										  *
*Parameter	: void																						  *
*																										  *
*Return 	: BOOL 0 is invalid,1 is valid																  *
*																										  *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if 0
static boolean TM_API_boGetCANMessageInvalidStatus(void)
{
	boolean boReturn ;
	
	if(TM_CORE_boCheckSystemErrorStatus(TM_EMS_CAN_MSG_INVALID,&TM__stMainObject) == TRUE)
	{
		boReturn = FALSE;
	}
	else
	{
		boReturn = TRUE;
	}
	
	return boReturn;
}
#endif
/**********************************************************************************************************
*																								          *
*																								          *
*	Tachometer Custom Application Interface													              *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*Function   : TM__boPowerModeCheckProcess                                                                 *
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
static boolean TM__boPowerModeCheckProcess(void)
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
	if((SYSTEMSTATE_Cluster_ON == u8PowerMode->ClusterState) && (SYSTEMSTATE_Cluster_ON != l_TM_ClusterStateLast_U8))
	{
		l_TMDebugLogFlag = TRUE;
	}
	else
	{
		l_TMDebugLogFlag = FALSE;
	}
	l_TM_ClusterStateLast_U8 = u8PowerMode->ClusterState;
	
	return boReturn;
}
/**********************************************************************************************************
*Function   : TM__vPowerModeIgnitionOffProcess                                                            *
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
static void TM__vPowerModeIgnitionOffProcess(void)
{
	TM__stMainObject.u16LastTargetEngineSpeed = 0;
	TM__stMainObject.u16FilterTargetEngineSpeed = 0;
	TM__stMainObject.u16FilterLastTargetEngineSpeed = 0;
	TM__stMainObject.u16VaildEngineSpeed = 0;
	TM__stMainObject.unFunctionFlag.stFuncFlag.IncreaseClimate = 1u;
	TM__stMainObject.stTimer.u16SBUS_MessageTick = 0;
	TM__stMainObject.u16LastCurrentEngineSpeed = 0;
	
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)	
	//TM__stMainObject.u16EngineSpeedFromCANBak = TM__stMainObject.u16EngineSpeedFromCAN;
	TM__stMainObject.u16EngineSpeedFromCAN = 0;
	TM__stMainObject.u16EngSpdForEngSts = 0;
#endif

#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)	
	TM__stMainObject.u16EngineSpeedFromPWM = 0;
#endif

	TM__stMainObject.u16TargetEngineSpeed = 0;
	TM__stMainObject.u16CurrentEngineSpeed = 0;

#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
	/*Ignition off is no damping to sweep pointer so homing immediately*/
	TM__vGaugeDoHoming();
#endif 

#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)
	TM__stMainObject.u16BarTargetStepCounts = 0;
	TM__stMainObject.u16BarCurrentStepCounts = 0;
#endif

#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_SBUS) != FALSE)
	/*Send SBUS message*/
	TM__vSBUSSendMessage();
#endif
	
}
/**********************************************************************************************************
*Function   : TM__boCANMessageValidCheckProcess                                                           *
*                                                                                                         *
*Description: The function is used to check EMS CAN message is received	normally                          *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
static boolean TM__boCANMessageValidCheckProcess(void)
{
	boolean boReturn = FALSE;
	uint8 u8EngSpdValid = 0;
	uint8 u8TgtEngSpdValid = 0;
	uint16 u8EngSpdForIP = 0;
	
	uint8 u8ECM1StatusRet = 0;
	uint8 u8DCT3StatusRet = 0;
	uint8 u8ECM11StatusRet = 0;
	boolean TM_MSG_MissingStatus = TRUE;

#ifdef GWM_V35_PROJECT_TYPE_B02_TM
	u8ECM1StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	u8ECM11StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u8EngSpdForIP, (uint8)sizeof(u8EngSpdForIP));
	u8DCT3StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_B03_TM
	u8ECM1StatusRet = Rte_Read_EngSpdVldty_EngSpdVldty(&u8EngSpdValid);
	u8ECM11StatusRet = Rte_Read_EngSpd_ForIP_EngSpd_ForIP(&u8EngSpdForIP);
	u8DCT3StatusRet = Rte_Read_DCT3_TgtEngSpdIPValid_TgtEngSpdIPValid(&u8TgtEngSpdValid);
#elif defined GWM_V35_PROJECT_TYPE_P03_TM
	u8ECM1StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	u8ECM11StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u8EngSpdForIP, (uint8)sizeof(u8EngSpdForIP));
	u8DCT3StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_P05_TM
	u8ECM1StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	u8ECM11StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u8EngSpdForIP, (uint8)sizeof(u8EngSpdForIP));
	u8DCT3StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_A07_TM
	u8ECM1StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	u8ECM11StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u8EngSpdForIP, (uint8)sizeof(u8EngSpdForIP));
	u8DCT3StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_D01_TM
	u8ECM1StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	u8ECM11StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u8EngSpdForIP, (uint8)sizeof(u8EngSpdForIP));
	u8DCT3StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_D02_TM
	u8ECM1StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	u8ECM11StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u8EngSpdForIP, (uint8)sizeof(u8EngSpdForIP));
	u8DCT3StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_D03_TM
	u8ECM1StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	u8ECM11StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u8EngSpdForIP, (uint8)sizeof(u8EngSpdForIP));
	u8DCT3StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_P02_TM
	u8ECM1StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	u8ECM11StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u8EngSpdForIP, (uint8)sizeof(u8EngSpdForIP));
	u8DCT3StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));
#elif defined GWM_V35_PROJECT_TYPE_P01_TM
	u8ECM1StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	u8ECM11StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u8EngSpdForIP, (uint8)sizeof(u8EngSpdForIP));
	u8DCT3StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTENGSPDIPVALID, (uint8 *)&u8TgtEngSpdValid, (uint8)sizeof(u8TgtEngSpdValid));

#else
#endif
#if (TM_CFG_CAN_MSG_VALID_COUNT_PLUS_IN_TIME_TASK == TRUE)
	
	//TM_API_vCANMessageCountProcess();

#endif //(TM_CFG_CAN_MSG_VALID_COUNT_PLUS_IN_TIME_TASK == TRUE)

	//Check msg 
	if(TM_CFG_GASOLINE_TYPE == TM__stMainObject.stVConfig.u8FuelType)
	{
		if(((TRUE != TM_CFG_CAN_ECM1_MSG_MISSING(u8ECM1StatusRet)) &&\
		(TRUE != TM_CFG_CAN_ECM11_MSG_MISSING(u8ECM11StatusRet)) &&\
		(TRUE == u8EngSpdValid)) \
		|| ((TRUE != TM_CFG_CAN_DCT3_MSG_MISSING(u8DCT3StatusRet))  && \
		(TRUE == u8TgtEngSpdValid) && \
		(TM__stMainObject.stVConfig.boFastRespondFlg == TM_CFG_FAST_RESPOND)))
		{
			/*Enable first update flag*/
			if(TM__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate == 0u)
			{
				TM__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 1u;
			}
			else
			{
			
			}
			TM__stMainObject.unFunctionFlag.stFuncFlag.EMSValueInvalidButKeep = 0u;/*0 is disable*/
			boReturn = TRUE;
			TM_MSG_MissingStatus = FALSE;
		
			#if 0
			if((TM__stMainObject.stCount.u8EMSEngineSpeedStatusValidCount >= TM_CFG_CAN_MSG_ENGINE_SPEED_VALID_COUNT_LIMIT)\
			|| (TM__stMainObject.stCount.u8ECMEngineSpeedValueValidCount >= TM_CFG_CAN_MSG_ENGINE_SPEED_VALID_COUNT_LIMIT))
			{

				/*Enable first update flag*/
				if(TM__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate == 0u)
				{
					TM__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 1u;
				}
				else
				{

				}
				TM__stMainObject.unFunctionFlag.stFuncFlag.EMSValueInvalidButKeep = 0u;/*0 is disable*/
				boReturn = TRUE;
			}
			else if(((TM__stMainObject.stCount.u8EMSEngineSpeedStatusValidCount == 0u)\
				&&(TM__stMainObject.stCount.u8EMSEngineSpeedStatusInvalidCount < TM_CFG_CAN_MSG_ENGINE_SPEED_INVALID_COUNT_LIMIT)\
				&&(TM__stMainObject.stVConfig.boFastRespondFlg == TM_CFG_FAST_RESPOND))\
				||((TM__stMainObject.stCount.u8ECMEngineSpeedValueValidCount == 0u)\
					&&(TM__stMainObject.stCount.u8ECMEngineSpeedValueInvalidCount < TM_CFG_CAN_MSG_ENGINE_SPEED_INVALID_COUNT_LIMIT)))
			{
				TM__stMainObject.unFunctionFlag.stFuncFlag.EMSValueInvalidButKeep = 1u;/*1 is enable*/
				boReturn = TRUE;
			}
			else
			{
				TM__stMainObject.unFunctionFlag.stFuncFlag.EMSValueInvalidButKeep = 0u;/*0 is disable*/
				boReturn = FALSE;
			}	
			#endif
		}
		else
		{
			TM__stMainObject.unFunctionFlag.stFuncFlag.EMSValueInvalidButKeep = 0u;/*0 is normal*/
			boReturn = FALSE;
			TM_MSG_MissingStatus = TRUE;
		}
	}
	else if(TM_CFG_DIESEL_TYPE == TM__stMainObject.stVConfig.u8FuelType)
	{
		if(((TRUE != TM_CFG_CAN_ECM1_MSG_MISSING(u8ECM1StatusRet)) &&\
		(TRUE == u8EngSpdValid)) \
		|| ((TRUE != TM_CFG_CAN_DCT3_MSG_MISSING(u8DCT3StatusRet))  && \
		(TRUE == u8TgtEngSpdValid) && \
		(TM__stMainObject.stVConfig.boFastRespondFlg == TM_CFG_FAST_RESPOND)))
		{
			/*Enable first update flag*/
			if(TM__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate == 0u)
			{
				TM__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 1u;
			}
			else
			{
			
			}
			TM__stMainObject.unFunctionFlag.stFuncFlag.EMSValueInvalidButKeep = 0u;/*0 is disable*/
			boReturn = TRUE;
			TM_MSG_MissingStatus = FALSE;
		}
		else
		{
			TM__stMainObject.unFunctionFlag.stFuncFlag.EMSValueInvalidButKeep = 0u;/*0 is normal*/
			boReturn = FALSE;
			TM_MSG_MissingStatus = TRUE;
		}
	}
	else
	{
		TM__stMainObject.unFunctionFlag.stFuncFlag.EMSValueInvalidButKeep = 0u;/*0 is normal*/
		boReturn = FALSE;
	}
	/* Tachometer Debug Log Print */
	if (TRUE == SWC_TM_LOGOUT_ENBLE)
	{
		/* If Msg Receive Status Change Or Power Status Change*/
		if((l_TM_Msg_missingSts_last_U8 != TM_MSG_MissingStatus) || (TRUE == l_TMDebugLogFlag))
		{
			if(TRUE == TM_MSG_MissingStatus)/* If MSG missing print 1 */
			{
				SWC_TM_PRINT_WARN("Tachom:MSGMissSts:%d", TM_MSG_MissingStatus);
			}
			else/*If MSG Receive Print 0*/
			{
				SWC_TM_PRINT_WARN("Tachom:MSGMissSts:%d", TM_MSG_MissingStatus);
			}
		}
	}
	l_TM_Msg_missingSts_last_U8 = TM_MSG_MissingStatus;
	return boReturn;
}
#endif // ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/**********************************************************************************************************
*Function   : TM__vGetEngineSpeedFromCAN                                                                  *
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
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
static void TM__vGetEngineSpeedFromCAN(void)
{
	if(TM__stMainObject.unFunctionFlag.stFuncFlag.EMSValueInvalidButKeep == 0u)
	{
		/*Calculate current engine speed from formula*/
		TM_CFG_vFormulaOfGetEngineSpeedFromCANRawValue(&TM__stMainObject);
	}
	else
	{
		/*Keep previous status for this time*/
	}
}
#endif // ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/**********************************************************************************************************
*Function   : TM__vCANMessageInvaildProcess                                                               *
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
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
static void TM__vCANMessageInvaildProcess(void)
{
	TM__stMainObject.u16EngineSpeedFromCAN = 0;
	TM__stMainObject.u16EngineSpeedFromCANBak = 0;
	TM__stMainObject.u16EngSpdForEngSts = 0;
	TM__stMainObject.u16LastCurrentEngineSpeed = 0;
}
#endif // ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/**********************************************************************************************************
*Function   : TM__boPWMInputValidCheckProcess                                                             *
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
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
static boolean TM__boPWMSignalValidCheckProcess(void)
{
	boolean boReturn = FALSE;
	/*Invalid count*/
	if(!TM_CFG_PWM_ENGINE_SPEED_VALUE_VALID)
	{
		TM__stMainObject.stCount.u8PWMValueInvalidCount ++;
		
		/*Avoid Overflow*/
		if(TM__stMainObject.stCount.u8PWMValueInvalidCount >= TM_CFG_PWM_SIGNAL_VALUE_INVALID_COUNT_LIMIT)
		{
			TM__stMainObject.stCount.u8PWMValueInvalidCount = TM_CFG_PWM_SIGNAL_VALUE_INVALID_COUNT_LIMIT;
		}
		else
		{
			
		}
	}
	else
	{
		TM__stMainObject.stCount.u8PWMValueInvalidCount = 0;
	}
	
	//Check msg 
	if(TM_CFG_PWM_STATUS_CHECK_OK && TM_CFG_PWM_ENGINE_SPEED_VALUE_VALID)
	{
		/*Enable first update flag*/
		if(TM__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate == 0u)
		{
			TM__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 1u;
		}
		else
		{

		}
		TM__stMainObject.unFunctionFlag.stFuncFlag.PWMValueInvalidButKeep = 0u;/*0 is disable*/
		boReturn = TRUE;
	}
	else if(TM_CFG_PWM_STATUS_CHECK_OK && \
		(!TM_CFG_PWM_ENGINE_SPEED_VALUE_VALID)&&\
		(TM__stMainObject.stCount.u8PWMValueInvalidCount < TM_CFG_PWM_SIGNAL_VALUE_INVALID_COUNT_LIMIT))
	{
		TM__stMainObject.unFunctionFlag.stFuncFlag.PWMValueInvalidButKeep = 1u;/*1 is enable*/	
		boReturn = TRUE;
   	}
	else
	{
		TM__stMainObject.unFunctionFlag.stFuncFlag.PWMValueInvalidButKeep = 0u;/*0 is disable*/
		boReturn = FALSE;
	}
	
	return boReturn;
}
#endif // ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
/**********************************************************************************************************
*Function   : TM__vGetEngineSpeedFromPWM                                                                  *
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
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
static void TM__vGetEngineSpeedFromPWM(void)
{
	if(TM__stMainObject.unFunctionFlag.stFuncFlag.PWMValueInvalidButKeep == 0u)
	{
		/*Calculate current engine speed from formula*/
		TM_CFG_vFormulaOfGetEngineSpeedFromPWMRawValue(&TM__stMainObject);
	}
	else
	{
		/*Keep previous status for this time*/
	}
}
#endif // ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
/**********************************************************************************************************
*Function   : TM__vPWMSignalInvaildProcess                                                                *
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
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
static void TM__vPWMSignalInvaildProcess(void)
{
	TM__stMainObject.u16EngineSpeedFromPWM = 0;	
}
#endif // ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
/**********************************************************************************************************
*Function   : TM__boCalculateTargetEngineSpeed                                                            *
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
static boolean TM__boCalculateTargetEngineSpeed(void)
{	
	boolean boReturn = FALSE;

	if(0)
	{
		/*Always skip this step*/
	}
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
	else if(FALSE == TM_CORE_boCheckSystemErrorStatus(TM_EMS_CAN_MSG_INVALID,&TM__stMainObject))
	{
		TM__stMainObject.u16VaildEngineSpeed = TM__stMainObject.u16EngineSpeedFromCAN;
		boReturn = TRUE;
	}
#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
	else if(FALSE == TM_CORE_boCheckSystemErrorStatus(TM_PWM_SIGNAL_INVALID,&TM__stMainObject))
	{
		TM__stMainObject.u16VaildEngineSpeed = TM__stMainObject.u16EngineSpeedFromPWM;
		boReturn = TRUE;
	}
#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
	else
	{
		/*No input valid*/
		TM__stMainObject.u16VaildEngineSpeed = 0u;
		boReturn = FALSE;
	}

	/*Save last indicate engine speed*/
	TM__stMainObject.u16LastTargetEngineSpeed = TM__stMainObject.u16TargetEngineSpeed;

	/*Calculate target indicate engine speed from formula*/
	TM_CFG_vFormulaOfGetTargetIndicateEngineSpeedFromRealEngineSpeed(&TM__stMainObject);
	
	//Increase climate flag
	if(TM__stMainObject.u16TargetEngineSpeed > TM__stMainObject.u16LastTargetEngineSpeed)
	{
		TM__stMainObject.unFunctionFlag.stFuncFlag.IncreaseClimate = 1u;
	}
	else if(TM__stMainObject.u16TargetEngineSpeed < TM__stMainObject.u16LastTargetEngineSpeed)
	{
		TM__stMainObject.unFunctionFlag.stFuncFlag.IncreaseClimate = 0u;
	}
	else
	{
		/*Keep previous climate*/
	}

	/* Engine Running status */
	(void)TM__vApp_setEngRunSts();
	return boReturn;
}
/**********************************************************************************************************
*Function   : TM__vAllInputInvaildProcess                                                                 *
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
static void TM__vAllInputInvaildProcess(void)
{
	TM__stMainObject.u16TargetEngineSpeed = 0;
	TM__stMainObject.u16CurrentEngineSpeed = 0;
	TM__stMainObject.u16FilterTargetEngineSpeed = 0;
	TM__stMainObject.u16FilterLastTargetEngineSpeed = 0;
	TM__stMainObject.u16VaildEngineSpeed = 0;
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
	/*Ignition off is no damping to sweep pointer so homing immediately*/
	TM__vGaugeDoHoming();
#endif 

#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)
	TM__stMainObject.u16LastTargetEngineSpeed = 0;
	TM__stMainObject.u16BarTargetStepCounts = 0;
	TM__stMainObject.u16BarCurrentStepCounts = 0;
#endif

#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_SBUS) != FALSE)
	/*Send SBUS message*/
	TM__vSBUSSendMessage();
#endif  
}
/**********************************************************************************************************
*Function   : TM__boDampingHandling                                                                       *
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
static boolean TM__boDampingHandling(void)
{
#if (TM_CFG_ANTI_DITHER_MODE != TM_CFG_NO_ANTI_DITHER_MODE)

	TM_CFG_vEnterOrExitAntiDitherMode(&TM__stMainObject);

#endif //(TM_CFG_ANTI_DITHER_MODE != TM_CFG_NO_ANTI_DITHER_MODE)
	
	if(TM__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate == 1u) //1u means need to update current immediately
	{
		TM__stMainObject.u16CurrentEngineSpeed = TM__stMainObject.u16TargetEngineSpeed;
		TM__stMainObject.u16FilterTargetEngineSpeed = TM__stMainObject.u16TargetEngineSpeed;
		TM__stMainObject.u16FilterLastTargetEngineSpeed = TM__stMainObject.u16TargetEngineSpeed;
		TM__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 2u; //2u means update operation is already done
	}
#if (TM_CFG_ANTI_DITHER_MODE != TM_CFG_NO_ANTI_DITHER_MODE)
	else if(TM__stMainObject.unFunctionFlag.stFuncFlag.AntiDither == 1u)
	{	//Full dial use only one damping model

#if (TM_CFG_ANTI_DITHER_MODE == TM_CFG_THREAD_ANTI_DITHER_MODEL)
		TM_CORE__u16DampingModel_Thread(&TM__stMainObject.u16TargetEngineSpeed,&TM__stMainObject.u16CurrentEngineSpeed,\
										TM_CFG_ANTI_DITHER_DAMPING_MODEL_C(TM__stMainObject.u16AntiDitherModeHighLimit,\
																		   TM__stMainObject.u16AntiDitherModeLowLimit,\
																		   TM__stMainObject.u16AntiDitherModeDampingTime));
#elif (TM_CFG_ANTI_DITHER_MODE == TM_CFG_ANTI_DITHER_MODEL_FROM_CONFIG_CODE)
		TM_CFG_vFormulaOfUserDefinedAntiDitherDampingOperation(&TM__stMainObject);
#else

#endif // (TM_CFG_ANTI_DITHER_MODE == TM_CFG_THREAD_ANTI_DITHER_MODEL)


	}
#endif // (TM_CFG_ANTI_DITHER_MODE != TM_CFG_NO_ANTI_DITHER_MODE)
	else
	{
#if (TM_CFG_DAMPING_MODEL == TM_CFG_THREAD_DAMPING_MODEL)
		TM_CORE__u16DampingModel_Thread(&TM__stMainObject.u16TargetEngineSpeed,\
									    &TM__stMainObject.u16CurrentEngineSpeed,\
										TM__u16DampingModel_Thread_Parameter); 
#elif(TM_CFG_DAMPING_MODEL == TM_CFG_KX_PLUS_B_DAMPING_MODEL)
		TM_CORE__u16DampingModel_kX_Plus_b(&TM__stMainObject.u16TargetEngineSpeed,\
										   &TM__stMainObject.u16CurrentEngineSpeed,\
										   TM__stDampingModel_KXPB_Parameter);
#elif(TM_CFG_DAMPING_MODEL == TM_CFG_PID_DAMPING_MODEL)
		TM_CORE__u16DampingModel_PID(&TM__stMainObject.u16TargetEngineSpeed,\
									 &TM__stMainObject.u16CurrentEngineSpeed,\
									 TM__stDampingModel_PID_Parameter);
#elif(TM_CFG_DAMPING_MODEL == TM_CFG_MODEL_FROM_CONFIG_CODE)

		/*Calculate current engine speed from formula*/
		TM_CFG_vFormulaOfUserDefinedDampingOperation(&TM__stMainObject);

#else //No damping

		TM__stMainObject.u16CurrentEngineSpeed = TM__stMainObject.u16TargetEngineSpeed;
		TM__stMainObject.u16FilterTargetEngineSpeed = TM__stMainObject.u16TargetEngineSpeed;
		TM__stMainObject.u16FilterLastTargetEngineSpeed = TM__stMainObject.u16TargetEngineSpeed;


#endif	//(TM_CFG_DAMPING_MODEL == TM_CFG_KX_PLUS_B_DAMPING_MODEL)
	}

#if(SM_CFG_DIGITAL_RPM_HYSTERESIS)
	if(TM__stMainObject.u16CurrentEngineSpeed > (TM__stMainObject.u16LastCurrentEngineSpeed + TM_CFG_DIGITAL_RPM_HYSTERESIS))
	{
		/*Keep previous */
		TM__stMainObject.u16LastCurrentEngineSpeed = TM__stMainObject.u16CurrentEngineSpeed;
	}
	else if((TM__stMainObject.u16CurrentEngineSpeed + TM_CFG_DIGITAL_RPM_HYSTERESIS) < TM__stMainObject.u16LastCurrentEngineSpeed)
	{	
		/*Keep previous */
		TM__stMainObject.u16LastCurrentEngineSpeed = TM__stMainObject.u16CurrentEngineSpeed;
	}
	else
	{
	}
	TM__stMainObject.u16CurrentEngineSpeed = TM__stMainObject.u16LastCurrentEngineSpeed;
			
#endif
	return TRUE;
}
/**********************************************************************************************************
*Function   : TM__vSetGaugeTargetStepCounts                                                               *
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
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
static void TM__vSetGaugeTargetStepCounts(UINT16 u16TargetStepCounts)
{
	if(TM_CFG_EOL_MODE_ENABLE||TM_CFG_ETM_MODE_ENABLE||TM_CFG_DIAGNOSIS_MODE_ENABLE)
	{
		
	}	
	else 
	{
		TM__stMainObject.u16GaugeTargetStepCounts = \
		TM_CORE__u16FormatDataAccuracy(TM__stMainObject.u16GaugeMaxMotorStepCounts,\
									   TM__stMainObject.u16GaugeMinMotorStepCounts,\
									   1,0,0,\
									   u16TargetStepCounts);
	}
}
#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : TM__vSetGaugeCurrentStepCounts                                                              *
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
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
static void TM__vSetGaugeCurrentStepCounts(UINT16 u16CurrentStepCounts)
{
	if(TM_CFG_EOL_MODE_ENABLE||TM_CFG_ETM_MODE_ENABLE||TM_CFG_DIAGNOSIS_MODE_ENABLE)
	{
		
	}	
	else 
	{
		TM__stMainObject.u16GaugeCurrentStepCounts = \
		TM_CORE__u16FormatDataAccuracy(TM__stMainObject.u16GaugeMaxMotorStepCounts,\
									   TM__stMainObject.u16GaugeMinMotorStepCounts,\
									   1,0,0,\
									   u16CurrentStepCounts);
	}
}
#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : TM__boCalculateGaugeStepCounts                                                              *
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
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
static boolean TM__boCalculateGaugeStepCounts(void)
{	
	//Target indicate speed
	TM__vSetGaugeTargetStepCounts(TM_CORE_u16CalulauteGaugeTableStepCounts((uint16*)&TM__stMainObject.u16GaugeTable,TM__stMainObject.u16TargetEngineSpeed));

	//Current indicate speed
	TM__vSetGaugeCurrentStepCounts(TM_CORE_u16CalulauteGaugeTableStepCounts((uint16*)&TM__stMainObject.u16GaugeTable,TM__stMainObject.u16CurrentEngineSpeed));

	return TRUE;
}
#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : TM__vGaugeDoHoming                                                                          *
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
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
static void TM__vGaugeDoHoming(void)
{
	TM__vSetGaugeTargetStepCounts(TM__stMainObject.u16GaugeMinMotorStepCounts);
	TM__vSetGaugeCurrentStepCounts(TM__stMainObject.u16GaugeMinMotorStepCounts);
}
#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : TM__boCalculateGaugeTargetStepCountsLimit                                                   *
*                                                                                                         *
*Description: The function is used to calculate the  maximum and minimum step counts of tachometer in NVM *
*			                                                                                              *
*Parameter	: void	                                                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
static boolean TM__boCalculateGaugeTargetStepCountsLimit(void)
{	
	TM__stMainObject.u16GaugeMaxMotorStepCounts = \
	(TM_CORE_u16CalulauteGaugeTableStepCounts((uint16*)&TM__stMainObject.u16GaugeTable,TM_CFG_VALUE_MAX));

	TM__stMainObject.u16GaugeMinMotorStepCounts = \
	(TM_CORE_u16CalulauteGaugeTableStepCounts((uint16*)&TM__stMainObject.u16GaugeTable,TM_CFG_VALUE_MIN));

	return TRUE;
}
#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : TM__boCheckEEPROMGaugeTableProcess                                                         *
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
#if (((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)&&(TM_CFG_GAUGE_TBL_SOURCE == TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE))
static boolean TM__boCheckEEPROMGaugeTableProcess(void)
{
#if(TM_CFG_DEBUG == TRUE)
	boolean boPrintFlag = FALSE;
#endif 
	boolean boReturn = TM_CORE_boCheckGaugeTableProcess((uint16*)&TM_CFG_GAUGE_EEPROM_TBL) ;

	if(FALSE == boReturn)
	{	
		TM_CORE_vSetSystemErrorStatus(TM_EEPROM_GAUGE_TBL_ERROR,&TM__stMainObject);
		
#if(TM_CFG_DEBUG == TRUE)
		if(boPrintFlag == FALSE)
		{
			boPrintFlag = TRUE;
printf("\
--Tachometer Module Debug: Configration Error---------------\r\n\
--Function Name : TM__boCheckEEPROMGaugeTableProcess\r\n\
--Error : Gauge table in EEPROM is invalid.\r\n\
------------------------------------------------------------\r\n");
		}
		else
		{
		
		}
#endif // (TM_CFG_DEBUG == TRUE)
	}
	else
	{
#if(TM_CFG_DEBUG == TRUE)
		boPrintFlag = FALSE;
#endif
	}	
	return boReturn;
}
#endif // (((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)&&(TM_CFG_GAUGE_TBL_SOURCE == TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE))
/**********************************************************************************************************
*Function   : TM__vCheckROMGaugeTableProcess                                                             *
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
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
static boolean TM__vCheckROMGaugeTableProcess(void)
{
#if(TM_CFG_DEBUG == TRUE)
	boolean boPrintFlag = FALSE;
#endif
	boolean boReturn = TM_CORE_boCheckGaugeTableProcess((uint16*)&TM__u16GaugeROMTbl) ;

	if	(FALSE == boReturn)
	{
		TM_CORE_vSetSystemErrorStatus(TM_ROM_GAUGE_TBL_ERROR,&TM__stMainObject);
		
#if(TM_CFG_DEBUG == TRUE)
	if(boPrintFlag == FALSE)
		{
			boPrintFlag = TRUE;
printf("\
--Tachometer Module Debug: Configration Error---------------\r\n\
--Function Name : TM__vCheckROMGaugeTableProcess\r\n\
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
#endif // ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : TM__vCopyROMGaugeTableProcess                                                               *
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
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
static void TM__vCopyROMGaugeTableProcess(void)
{
	memcpy(&TM__stMainObject.u16GaugeTable[0],&TM__u16GaugeROMTbl[0],sizeof(TM__stMainObject.u16GaugeTable));
	TM__stMainObject.unFunctionFlag.stFuncFlag.GaugeTableSource = 1u;
}
#endif // ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : TM__vCopyEEPROMGaugeTableProcess                                                            *
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
#if (((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)&&(TM_CFG_GAUGE_TBL_SOURCE == TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE))
static void TM__vCopyEEPROMGaugeTableProcess(void)
{
	memcpy(&TM__stMainObject.u16GaugeTable[0],&TM_CFG_GAUGE_EEPROM_TBL[0],sizeof(TM__stMainObject.u16GaugeTable));
	TM__stMainObject.unFunctionFlag.stFuncFlag.GaugeTableSource = 2u;
}
#endif // (((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)&&(TM_CFG_GAUGE_TBL_SOURCE == TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE))
/**********************************************************************************************************
*Function   : TM__boCalculateBarStepCounts                                                                *
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
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)
static boolean TM__boCalculateBarStepCounts(void)
{
//Target indicate speed
	if(TM__stMainObject.u16TargetEngineSpeed >= TM_CFG_VALUE_MAX)
	{
		TM__stMainObject.u16BarTargetStepCounts = (TM_CFG_BAR_DISPLAY_STEPS-1);
	}
#if (TM_CFG_VALUE_MIN > 0)	//Aviod QAC warning
	else if(TM__stMainObject.u16TargetEngineSpeed <= TM_CFG_VALUE_MIN)
#else			
	else if(TM__stMainObject.u16TargetEngineSpeed == TM_CFG_VALUE_MIN)
#endif	
	{
		TM__stMainObject.u16BarTargetStepCounts = 0;
	}
	else
	{
		TM__stMainObject.u16BarTargetStepCounts = \
			TM_CORE_u16CalulauteBarTableStepCounts(&TM__stBarROMTbl,\
													TM__stMainObject.unFunctionFlag.stFuncFlag.IncreaseClimate,\
													TM__stMainObject.u16BarTargetStepCounts,\
													TM__stMainObject.u16TargetEngineSpeed);
	}
	
//Current indicate speed
	if(TM__stMainObject.u16CurrentEngineSpeed >= TM_CFG_VALUE_MAX)
	{
		TM__stMainObject.u16BarCurrentStepCounts = (TM_CFG_BAR_DISPLAY_STEPS-1);
	}
#if (TM_CFG_VALUE_MIN > 0)	//Aviod QAC warning
	else if(TM__stMainObject.u16CurrentEngineSpeed <= TM_CFG_VALUE_MIN)
#else			
	else if(TM__stMainObject.u16CurrentEngineSpeed == TM_CFG_VALUE_MIN)
#endif	
	{
		TM__stMainObject.u16BarCurrentStepCounts = 0;
	}
	else
	{
		TM__stMainObject.u16BarCurrentStepCounts = \
			TM_CORE_u16CalulauteBarTableStepCounts(&TM__stBarROMTbl,\
													TM__stMainObject.unFunctionFlag.stFuncFlag.IncreaseClimate,\
													TM__stMainObject.u16BarCurrentStepCounts,\
													TM__stMainObject.u16CurrentEngineSpeed);
	}
	
	return TRUE;
}
#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)
/**********************************************************************************************************
*Function   : TM__boSBUSSendOperation                                                                     *
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
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_SBUS) != FALSE)
static void TM__vSBUSSendMessage(void)
{
	uint16 u16TempData = 0;
	s_TachoInfo_t TachoInfo = {0};
    IPC_M2S_ClusterAppAPPTacho_t  Ipc_SendTacho = {0};
	/* Send TC,TT */
	TachoInfo.EngSpd = TM_API_u16GetValidEngineSpeed(ACCUACY_1RPM);
	TachoInfo.EngRunSts = TM__vApp_setEngRunSts();
	TachoInfo.TimeOutFlag = TM_API_u8GetECMMsgStatus();
	TachoInfo.EngSpdBak = TM_CORE__u16FormatDataAccuracy(TM_CFG_VALUE_MAX,TM_CFG_VALUE_MIN,\
													   (uint16)ACCUACY_1RPM,0,\
													   TM_CFG_ENGINE_SPEED_VALUE_INTERFACE_ROUND_CONFIG,\
													   TM__stMainObject.u16EngineSpeedFromCANBak);
	(void)Rte_Write_ppSR_SWCNormal_TachoInfo_Element(&TachoInfo);
	u16TempData = TM_API_u16GetCurrentEngineSpeed(ACCUACY_100RPM) * 100u;
    Ipc_SendTacho.EngSpdCalculated = (sint32)u16TempData;
    Ipc_SendTacho.EngSpdMax = (int32_t)TM_API_u16GetTachoMaxValue();
    Ipc_SendTacho.RedDispaly = TM_API_u16GetTachoRedZone();
    Ipc_SendTacho.EngRunningSts = TM__vApp_setEngRunSts();
    Ipc_SendTacho.RedZoneThreshold = (int32_t)TM_API_u16GetTachoRedZoneThreshold();
    Ipc_SendTacho.EngSpdAnalog = (sint32)TM_API_u16GetCurrentEngineSpeed(ACCUACY_1RPM);
	Ipc_SendTacho.EngSpdReal = (sint32)TM_API_u16GetValidEngineSpeed(ACCUACY_1RPM);
	(void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_TACHOMETER,(uint8 *)&Ipc_SendTacho,(uint16)sizeof(IPC_M2S_ClusterAppAPPTacho_t),FALSE);
}
#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_SBUS) != FALSE)
/**********************************************************************************************************
*Function   : TM__boSBUSSendOperation                                                                     *
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
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_SBUS) != FALSE)
static boolean TM__boSBUSSendOperation(void)
{
	TM__stMainObject.u16SBUSSendCycle = \
	TM_CORE__u16FormatDataAccuracy(TM_CFG_ENGINE_SPEED_SBUS_MSG_SEND_TIME_CYCLE_MAXIMUM,\
								   1,/*Cycle can not be zero*/\
								   TM_CFG_TIME_TASK_CYCLE,0,(boolean)0,\
								   TM_CFG_ENGINE_SPEED_SBUS_MSG_SEND_TIME_CYCLE);
	if(TM__stMainObject.u16SBUSSendCycle < 1)
	{
		TM__stMainObject.u16SBUSSendCycle = 1;
	}
	if(TM__stMainObject.stTimer.u16SBUS_MessageTick % TM__stMainObject.u16SBUSSendCycle)
	{
		/*Do nothing*/
	}
	else
	{
		TM__stMainObject.stTimer.u16SBUS_MessageTick = 0;

		TM__vSBUSSendMessage();
	}

	TM__stMainObject.stTimer.u16SBUS_MessageTick ++;


	return TRUE;
}
#endif //((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_SBUS) != FALSE)

static boolean TM__boVehicleConfig(void)
{
	TM_CFG_vVehicleConfig(&TM__stMainObject);

	return TRUE;
}
/**********************************************************************************************************
*Function   : TM__vSystemErrorObjectOperationProcess                                                      *
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
static void TM__vSystemErrorObjectOperationProcess(void)
{
	TM__stMainObject.u16LastTargetEngineSpeed = 0;
	TM__stMainObject.u16TargetEngineSpeed = 0 ;
	TM__stMainObject.u16CurrentEngineSpeed = 0 ;
	TM__stMainObject.u16VaildEngineSpeed = 0 ;
	TM__stMainObject.u16FilterTargetEngineSpeed = 0;
	TM__stMainObject.u16FilterLastTargetEngineSpeed = 0;
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
	TM__stMainObject.u16EngineSpeedFromCANBak = 0;
	TM__stMainObject.u16EngineSpeedFromCAN = 0;
	TM__stMainObject.u16EngSpdForEngSts = 0;
#endif 
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
	TM__stMainObject.u16EngineSpeedFromPWM = 0 ;
#endif

#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	TM__stMainObject.u16GaugeTargetStepCounts = 0;
	TM__stMainObject.u16GaugeCurrentStepCounts = 0;
#endif

#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)
	TM__stMainObject.u16BarTargetStepCounts = 0;
	TM__stMainObject.u16BarCurrentStepCounts = 0;
#endif
	
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_SBUS) != FALSE)
	/*Send SBUS message*/
	TM__vSBUSSendMessage();
#endif
}

static uint8 TM__vApp_setEngRunSts(void)
{
	#if 0
	uint8 u8ECM1StatusRet = 0;
	uint8 u8ECM11StatusRet = 0;
	uint8 u8EngSpdValid = 0;
	uint16 u8EngSpdForIP = 0;
	u8ECM1StatusRet = TM_CFG_CAN_ECM1_ENGSPD_INVALID(&u8EngSpdValid);
	u8ECM11StatusRet = TM_CFG_CAN_ECM11_ENGSPD_FORIP(&u8EngSpdForIP);
	if((TRUE == TM_CFG_CAN_ECM1_MSG_MISSING(u8ECM1StatusRet)) \
		|| (TRUE == TM_CFG_CAN_ECM11_MSG_MISSING(u8ECM11StatusRet)))/*missing*/
	{
		TM__u8EngRunSts = ENGINE_STOP;	
	}
	else 
	{
		if(FALSE == TM_CORE_boCheckSystemErrorStatus(TM_EMS_CAN_MSG_INVALID,&TM__stMainObject))
		{
			if(TM__stMainObject.u16EngineSpeedFromCAN >= 400)
			{
				TM__u8EngRunSts = ENGINE_RUNNING;
			}
			else if(TM__stMainObject.u16EngineSpeedFromCAN < 200)
			{
				TM__u8EngRunSts = ENGINE_STOP;
			}
			else
			{
				/* keep previous status */
			}
		}
		else
		{
			TM__u8EngRunSts = ENGINE_STOP;
		}
	}
	#endif
	if(TM__stMainObject.u16EngSpdForEngSts >= 400)
	{
		TM__u8EngRunSts = (uint8)ENGINE_RUNNING;
	}
	else if(TM__stMainObject.u16EngSpdForEngSts < 200)
	{
		TM__u8EngRunSts = (uint8)ENGINE_STOP;
	}
	else
	{
		/* keep previous status */
	}

	return TM__u8EngRunSts;
}

uint8 TM_API_u8GetECMMsgStatus(void)
{	
	uint8 u8TimeOutFlg = 0;
	uint8 u8EngSpdValid = 0;	
	uint16 u8EngSpdForIP = 0;
	
	uint8 u8ECM1StatusRet = 0;	
	uint8 u8ECM11StatusRet = 0;
	
#ifdef GWM_V35_PROJECT_TYPE_B02_TM
	u8ECM1StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	u8ECM11StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u8EngSpdForIP, (uint8)sizeof(u8EngSpdForIP));
#elif defined GWM_V35_PROJECT_TYPE_B03_TM
	u8ECM1StatusRet = Rte_Read_EngSpdVldty_EngSpdVldty(&u8EngSpdValid);
	u8ECM11StatusRet = Rte_Read_EngSpd_ForIP_EngSpd_ForIP(&u8EngSpdForIP);
#elif defined GWM_V35_PROJECT_TYPE_P03_TM
	u8ECM1StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	u8ECM11StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u8EngSpdForIP, (uint8)sizeof(u8EngSpdForIP));
#elif defined GWM_V35_PROJECT_TYPE_P05_TM
	u8ECM1StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	u8ECM11StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u8EngSpdForIP, (uint8)sizeof(u8EngSpdForIP));
#elif defined GWM_V35_PROJECT_TYPE_A07_TM
	u8ECM1StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	u8ECM11StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u8EngSpdForIP, (uint8)sizeof(u8EngSpdForIP));
#elif defined GWM_V35_PROJECT_TYPE_D01_TM
	u8ECM1StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	u8ECM11StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u8EngSpdForIP, (uint8)sizeof(u8EngSpdForIP));
#elif defined GWM_V35_PROJECT_TYPE_D02_TM
	u8ECM1StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	u8ECM11StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u8EngSpdForIP, (uint8)sizeof(u8EngSpdForIP));
#elif defined GWM_V35_PROJECT_TYPE_D03_TM
	u8ECM1StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	u8ECM11StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u8EngSpdForIP, (uint8)sizeof(u8EngSpdForIP));
#elif defined GWM_V35_PROJECT_TYPE_P02_TM
	u8ECM1StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	u8ECM11StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u8EngSpdForIP, (uint8)sizeof(u8EngSpdForIP));
#elif defined GWM_V35_PROJECT_TYPE_P01_TM
	u8ECM1StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)&u8EngSpdValid, (uint8)sizeof(u8EngSpdValid));
	u8ECM11StatusRet = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)&u8EngSpdForIP, (uint8)sizeof(u8EngSpdForIP));
#else
#endif
	if(TM_CFG_GASOLINE_TYPE == TM__stMainObject.stVConfig.u8FuelType)
	{
		if((TRUE != TM_CFG_CAN_ECM1_MSG_MISSING(u8ECM1StatusRet)) &&\
		   (TRUE != TM_CFG_CAN_ECM11_MSG_MISSING(u8ECM11StatusRet)))
		{
			u8TimeOutFlg = 1;
		}
		else
		{
			u8TimeOutFlg = 0;
		}
	}
	else if(TM_CFG_DIESEL_TYPE == TM__stMainObject.stVConfig.u8FuelType)
	{
		if(TRUE != TM_CFG_CAN_ECM1_MSG_MISSING(u8ECM1StatusRet)) 
		{
			u8TimeOutFlg = 1;
		}
		else
		{
			u8TimeOutFlg = 0;
		}
	}
	else
	{

	}

	return u8TimeOutFlg;
}

uint16 TM_API_u16GetTachoMaxValue(void)
{
	return (TM__stMainObject.stVConfig.u16TachoValueMax);
}

uint16 TM_API_u16GetTachoRedZoneThreshold(void)
{
	return (TM__stMainObject.stVConfig.u16RedZoneThreshold);
}

uint8 TM_API_u16GetTachoRedZone(void)
{
	uint8 u8Ret = 0;
	uint16 u16EngineSpeed = 0;
	u16EngineSpeed = TM_API_u16GetCurrentEngineSpeed(ACCUACY_100RPM) * 100u;
    if (TM__stMainObject.stVConfig.u16RedZoneThreshold <= u16EngineSpeed)
    {
        u8Ret = 1;
    }
    else
    {
        u8Ret = 0;
    }

	return u8Ret;
}

#define SWC_TM_STOP_SEC_CODE
#include "SWC_TM_MemMap.h" 

/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
