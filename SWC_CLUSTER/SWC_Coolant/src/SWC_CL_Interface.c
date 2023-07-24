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
*File Name   : CL_Interface.c                                                                             *
*                                                                                                         *
*Description : Coolant module application interface source file.                                          *
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
#include "SWC_IPC_Application.h"
#include <string.h> /* memcpy */

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_CL_Config.h" 
#include "SWC_CL_Core.h"
#include "SWC_CL_Interface.h"
#include "Rte_Common_Normal.h"
#include "IPC_ClusterApp.h"
/**********************************************************************************************************
*																								          *
*																								          *
*	Coolant Main Object Structure Variable															      *
*																								          *
*																								          *
**********************************************************************************************************/
#define SWC_CL_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_CL_MemMap.h"
extern sint16 g_coolantPointVal[8] = \
{
	400, \
	600, \
	750, \
	1120, \
	1140, \
	1160, \
	1180, \
	1300
};
static CL_CFG_tstMAIN_OBJECT CL__stMainObject ;
static uint8 CL_EngClntTempVldty = 0;
static uint8 CL_EngClntTempRedDisp = 0;
static sint16 l_CL_EngClntTemp_Percent_S16 = 0;
static uint8 l_boReturn_last_U8 = FALSE;
//static IPC_M2S_ClusterAppAPPCoolant_t ToSBUS_CL_Status32 = {0};
static uint8 l_CL_ClusterStateLast_U8 = SYSTEMSTATE_Cluster_OFF;
boolean l_CLDebugLogFlag = FALSE;
#define SWC_CL_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_CL_MemMap.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Coolant Gauge ROM Table Const															              *
*																								          *
*																								          *
**********************************************************************************************************/

#define SWC_CL_START_SEC_CONST_UNSPECIFIED
#include "SWC_CL_MemMap.h"

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)

const uint16 CL__u16GaugeROMTbl[][2] = CL_CFG_GAUGE_ROM_TBL;

#endif 
/**********************************************************************************************************
*																								          *
*																								          *
*	Coolant Bar ROM Table Const           															      *
*																								          *
*																								          *
**********************************************************************************************************/
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)

static const CL_tstBAR_TBL  CL__stBarROMTbl[] = CL_CFG_BAR_ROM_TBL;

#endif 

#define SWC_CL_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_CL_MemMap.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Coolant Common Static Function																          *
*																								          *
*																								          *
**********************************************************************************************************/
#define SWC_CL_START_SEC_CODE
#include "SWC_CL_MemMap.h" 

static boolean CL__boPowerModeCheckProcess(void);

static void CL__vPowerModeIgnitionOffProcess(void);

#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)

static boolean CL__boECM3CANMessageValidCheckProcess(void);

static void CL__vGetRealEngineTemperatureFromCAN(void);

static void CL__vECM3CANMessageInvaildProcess(void);

#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)

#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)

static boolean CL__boADCSignalValidCheckProcess(void);

static void CL__vGetRealEngineTemperatureFromADC(void);

static void CL__vADCSignalInvaildProcess(void);

#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)

static boolean CL__boCalculateTargetIndicateEngineTemperature(void);

static void CL__vAllInputInvaildProcess(void);

static boolean CL__boDampingHandling(void);

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)

static void CL__vSetGaugeTargetStepCounts(uint16 u16TargetStepCounts);

static void CL__vSetGaugeCurrentStepCounts(uint16 u16CurrentStepCounts);

static boolean CL__boCalculateGaugeStepCounts(void);

static boolean CL__boCalculateGaugeTargetStepCountsLimit(void);

static void CL__vGaugeDoHoming(void);

static boolean CL__vCheckROMGaugeTableProcess(void);

static void CL__vCopyROMGaugeTableProcess(void);

#if (CL_CFG_GAUGE_TBL_SOURCE == CL_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
static boolean CL__boCheckEEPROMGaugeTableProcess(void);

static void CL__vCopyEEPROMGaugeTableProcess(void);

#endif //(CL_CFG_GAUGE_TBL_SOURCE == CL_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)

static boolean CL__boCalculateBarStepCounts(void);
#if (CL_CFG_BAR_STEPS_DAMPING != FALSE)
//static uint16 CL__boBarStepCountsDamping(uint16 tar,uint16 cur,uint16 damp);
#endif
#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_SBUS) != FALSE)

static void CL__vSBUSSendMessage(void);

static boolean CL__boSBUSSendOperation(void);

#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_SBUS) != FALSE)

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_TLC) != FALSE)

static boolean CL__vTLCSendMessage(void);

#endif
static void CL__vSystemErrorObjectOperationProcess(void);

static boolean CL__boVehicleConfig(void);

#define SWC_CL_STOP_SEC_CODE
#include "SWC_CL_MemMap.h" 

/**********************************************************************************************************
*																								          *
*																								          *
*	Coolant Custom Static Function																          *
*																								          *
*																								          *
**********************************************************************************************************/


/**********************************************************************************************************
*																								          *
*																								          *
*	Coolant Process Map																				      *
*																								          *
*																								          *
**********************************************************************************************************/

/*************************************************************************************************************************************************************************************************************/
/*ProcessName                Process                                          SucceedEnable      FaildEnable              AfterSucceed                           AfterFaild                         ContinueWhen
                                                                              Status             Status                   Operation                              Operation                          Faild            */
#define SWC_CL_START_SEC_CONST_UNSPECIFIED
#include "SWC_CL_MemMap.h"

static CL_tstPROCESS CL_stTimeTask_ProcessTable[] = {
/*Power Mode */            { CL__boPowerModeCheckProcess ,                    CL_KEEP_PREVIOUS , CL_IGN_OFF ,             CL_DO_NOTHING ,                        CL__vPowerModeIgnitionOffProcess , (boolean)FALSE            },
/*Vehicle configuration */ { CL__boVehicleConfig ,                  		  CL_KEEP_PREVIOUS , CL_KEEP_PREVIOUS ,       CL_DO_NOTHING ,                        CL_DO_NOTHING ,                    (boolean)CL_NOT_CONCERNED },
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/*ECM3 Msg  */             { CL__boECM3CANMessageValidCheckProcess ,           CL_KEEP_PREVIOUS , CL_ECM3_CAN_MSG_INVALID , CL__vGetRealEngineTemperatureFromCAN , CL__vECM3CANMessageInvaildProcess , (boolean)TRUE 			 },
#endif 
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
/*ADC Input */             { CL__boADCSignalValidCheckProcess ,               CL_KEEP_PREVIOUS , CL_ADC_SIGNAL_INVALID ,  CL__vGetRealEngineTemperatureFromADC , CL__vADCSignalInvaildProcess ,     (boolean)TRUE 			 },
#endif 
/*Calculate indicate */    { CL__boCalculateTargetIndicateEngineTemperature , CL_KEEP_PREVIOUS , CL_ALL_INPUT_INVALID ,   CL_DO_NOTHING ,                        CL__vAllInputInvaildProcess ,      (!CL_CFG_INPUT_INVALID_RETURN_TO_ZERO_WITH_NO_DAMPING)},
/*Damping handling */      { CL__boDampingHandling ,                          CL_KEEP_PREVIOUS , CL_KEEP_PREVIOUS ,       CL_DO_NOTHING ,                        CL_DO_NOTHING ,                    (boolean)CL_NOT_CONCERNED },
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
/*Calculate step counts */ { CL__boCalculateGaugeStepCounts ,                 CL_KEEP_PREVIOUS , CL_KEEP_PREVIOUS ,       CL_DO_NOTHING ,                        CL_DO_NOTHING ,                    (boolean)CL_NOT_CONCERNED },
#endif
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)
/*Calculate step counts */ { CL__boCalculateBarStepCounts ,                   CL_KEEP_PREVIOUS , CL_KEEP_PREVIOUS ,       CL_DO_NOTHING ,                        CL_DO_NOTHING ,                    (boolean)CL_NOT_CONCERNED },
#endif
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_SBUS) != FALSE)
/*SBUS send operation */   { CL__boSBUSSendOperation ,                        CL_KEEP_PREVIOUS , CL_KEEP_PREVIOUS ,       CL_DO_NOTHING ,                        CL_DO_NOTHING ,                    (boolean)CL_NOT_CONCERNED },
#endif
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_TLC) != FALSE)
/*SBUS send operation */   { CL__vTLCSendMessage ,						 		CL_KEEP_PREVIOUS , CL_KEEP_PREVIOUS ,		 CL_DO_NOTHING ,						CL_DO_NOTHING , 				   (boolean)CL_NOT_CONCERNED },
#endif

						   { (void *)0,(CL_CFG_enSYSTEM_STATUS)0,(CL_CFG_enSYSTEM_STATUS)0,(void *)0,(void *)0,(boolean)0},\
						   };

#define SWC_CL_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_CL_MemMap.h"

/*************************************************************************************************************************************************************************************************************/

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

void CL_API_vKSTimeTask(void)
{
#if(CL_CFG_COOLANT_FUNCTION == TRUE)
	if(FALSE == CL_CORE_boCheckSystemErrorStatus(CL_SYS_FAILD,&CL__stMainObject))
	{
		CL_CORE_vProcessControl((void *)CL_stTimeTask_ProcessTable,&CL__stMainObject);
	}
	else
	{
		CL__vSystemErrorObjectOperationProcess();
	}
#endif //(CL_CFG_COOLANT_FUNCTION == TRUE)
}
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
void CL_API_vKSRoundRobinTask(void)
{
#if(CL_CFG_COOLANT_FUNCTION == TRUE)
	
#endif //(CL_CFG_COOLANT_FUNCTION == TRUE)
}
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
void CL_API_vKSColdInit(void)
{
	//Avoid Warning
	CL_CORE_vSetSystemErrorStatus(CL_SYS_DEFAULT,&CL__stMainObject);

	CL_CORE_vClearSystemErrorStatus(CL_SYS_DEFAULT,&CL__stMainObject);

	(void)CL_CORE_boCheckSystemErrorStatus(CL_SYS_DEFAULT,&CL__stMainObject);
	
#if(CL_CFG_COOLANT_FUNCTION == TRUE)
#if(CL_CFG_DEBUG == TRUE)
printf("\
------------------------------------------------------------\r\n\
--Coolant Module Debug Mode Enable--------------------------\r\n\
------------------------------------------------------------\r\n");

	CL_CORE_vCheckModuleConfigration();

#endif

#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) == FALSE)

	CL_CORE_vSetSystemErrorStatus(CL_ECM3_CAN_MSG_INVALID,&CL__stMainObject);
		
#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) == FALSE)

#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) == FALSE)

	CL_CORE_vSetSystemErrorStatus(CL_ADC_SIGNAL_INVALID,&CL__stMainObject);
		
#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) == FALSE)

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
	if (FALSE == CL__vCheckROMGaugeTableProcess())
	{
		CL_CORE_vSetSystemErrorStatus(CL_SYS_FAILD,&CL__stMainObject);
	}
#if (CL_CFG_GAUGE_TBL_SOURCE == CL_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
	else if (TRUE == CL__boCheckEEPROMGaugeTableProcess())
	{	
		CL__vCopyEEPROMGaugeTableProcess();
	}
#endif // (CL_CFG_GAUGE_TBL_SOURCE == CL_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
	else
	{
		CL__vCopyROMGaugeTableProcess();
	}
#endif // ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)
	if (FALSE == CL_CORE_boCheckBarTableProcess(&CL__stBarROMTbl))
	{
		CL_CORE_vSetSystemErrorStatus(CL_SYS_FAILD,&CL__stMainObject);
	}
	else
	{
		/*Bar table check ok*/
	}

#endif // ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)

	if(FALSE == CL_CORE_boCheckSystemErrorStatus(CL_SYS_FAILD,&CL__stMainObject))
	{
		//Function flag control
		CL_CORE_vFlagControl(CL_COLD_INIT,&CL__stMainObject);

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)	
		/*Calculate gauge target step counts limit*/
		(void)CL__boCalculateGaugeTargetStepCountsLimit();
#endif // ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_SBUS) != FALSE)
		/*Send SBUS message*/
		CL__vSBUSSendMessage();
#endif  
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_TLC) != FALSE)
				/*Send SBUS message*/
		(void)CL__vTLCSendMessage();
#endif 

		/*Set count*/
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		CL__stMainObject.stCount.u8ECM3TemperatureValueValidCount = CL_CFG_CAN_MSG_TEMPERATURE_VALID_COUNT_LIMIT;
		CL__stMainObject.stCount.u8ECM3TemperatureStatusValidCount = CL_CFG_CAN_MSG_TEMPERATURE_VALID_COUNT_LIMIT;	
		CL__stMainObject.stCount.u8ECM3TemperatureValueInvalidCount = 0;
		CL__stMainObject.stCount.u8ECM3TemperatureStatusInvalidCount = 0;
		
#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)

		CL__stMainObject.stCount.u8ADCValueInvalidCount = 0;

#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
	}
	else //System Faild,do nothing
	{

	}
	CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 1;
	CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp = 1;
#endif //(CL_CFG_COOLANT_FUNCTION == TRUE)
}
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
void CL_API_vKSWarmInit(void)
{
#if(CL_CFG_COOLANT_FUNCTION == TRUE)

#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) == FALSE)

	CL_CORE_vSetSystemErrorStatus(CL_ECM3_CAN_MSG_INVALID,&CL__stMainObject);
		
#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) == FALSE)

#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) == FALSE)

	CL_CORE_vSetSystemErrorStatus(CL_ADC_SIGNAL_INVALID,&CL__stMainObject);
		
#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) == FALSE)

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
	if (FALSE == CL__vCheckROMGaugeTableProcess())
	{
		CL_CORE_vSetSystemErrorStatus(CL_SYS_FAILD,&CL__stMainObject);
	}
#if (CL_CFG_GAUGE_TBL_SOURCE == CL_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
	else if (TRUE == CL__boCheckEEPROMGaugeTableProcess())
	{	
		CL__vCopyEEPROMGaugeTableProcess();
	}
#endif // (CL_CFG_GAUGE_TBL_SOURCE == CL_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
	else
	{
		CL__vCopyROMGaugeTableProcess();
	}
#endif // ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)

	if(FALSE == CL_CORE_boCheckSystemErrorStatus(CL_SYS_FAILD,&CL__stMainObject))
	{
		//Function flag control
		CL_CORE_vFlagControl(CL_WARM_INIT,&CL__stMainObject);
		
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)	
		/*Calculate gauge target step counts limit*/
		(void)CL__boCalculateGaugeTargetStepCountsLimit();
#endif // ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_SBUS) != FALSE)
		/*Send SBUS message*/
		CL__vSBUSSendMessage();
#endif 
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_TLC) != FALSE)
				/*Send SBUS message*/
		(void)CL__vTLCSendMessage();
#endif 

		/*Set count*/
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		CL__stMainObject.stCount.u8ECM3TemperatureValueValidCount = CL_CFG_CAN_MSG_TEMPERATURE_VALID_COUNT_LIMIT;
		CL__stMainObject.stCount.u8ECM3TemperatureStatusValidCount = CL_CFG_CAN_MSG_TEMPERATURE_VALID_COUNT_LIMIT;	
		CL__stMainObject.stCount.u8ECM3TemperatureValueInvalidCount = 0;
		CL__stMainObject.stCount.u8ECM3TemperatureStatusInvalidCount = 0;
		
#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)

		CL__stMainObject.stCount.u8ADCValueInvalidCount = 0;

#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
	}
	else //System Faild,do nothing
	{

	}
	CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 1;
	CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp = 1;
#endif //(CL_CFG_COOLANT_FUNCTION == TRUE)
}
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
void CL_API_vKSWakeUp(void)
{
	if(FALSE == CL_CORE_boCheckSystemErrorStatus(CL_SYS_FAILD,&CL__stMainObject))
	{
		//Function flag control
		CL_CORE_vFlagControl(CL_WAKE_UP,&CL__stMainObject);
		
	}
	else //System Faild,do nothing
	{

	}
}
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
void CL_API_vKSSleep(void)
{
	if(FALSE == CL_CORE_boCheckSystemErrorStatus(CL_SYS_FAILD,&CL__stMainObject))
	{
		//Function flag control
		CL_CORE_vFlagControl(CL_SLEEP,&CL__stMainObject);
		
	}
	else //System Faild,do nothing
	{

	}
}
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
void CL_API_vKSEnterAbnormalOperation(void)
{
#if(CL_CFG_COOLANT_FUNCTION == TRUE)
	if(FALSE == CL_CORE_boCheckSystemErrorStatus(CL_SYS_FAILD,&CL__stMainObject))
	{
		//Function flag control
		CL_CORE_vFlagControl(CL_ENTER_ABNORMAL,&CL__stMainObject);
		
		/*Clear count*/
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		CL__stMainObject.stCount.u8ECM3TemperatureValueValidCount = CL_CFG_CAN_MSG_TEMPERATURE_VALID_COUNT_LIMIT;
		CL__stMainObject.stCount.u8ECM3TemperatureStatusValidCount = CL_CFG_CAN_MSG_TEMPERATURE_VALID_COUNT_LIMIT;	
		CL__stMainObject.stCount.u8ECM3TemperatureValueInvalidCount = 0;
		CL__stMainObject.stCount.u8ECM3TemperatureStatusInvalidCount = 0;
		
#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)

		CL__stMainObject.stCount.u8ADCValueInvalidCount = 0;

#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
	}
	else //System Faild,do nothing
	{

	}
#endif //(CL_CFG_COOLANT_FUNCTION == TRUE)
}
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
void CL_API_vKSExitAbnormalOperation(void)
{
#if(CL_CFG_COOLANT_FUNCTION == TRUE)
	if(FALSE == CL_CORE_boCheckSystemErrorStatus(CL_SYS_FAILD,&CL__stMainObject))
	{
		//Function flag control
		CL_CORE_vFlagControl(CL_EXIT_ABNORMAL,&CL__stMainObject);

		/*Clear count*/
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		CL__stMainObject.stCount.u8ECM3TemperatureValueValidCount = CL_CFG_CAN_MSG_TEMPERATURE_VALID_COUNT_LIMIT;
		CL__stMainObject.stCount.u8ECM3TemperatureStatusValidCount = CL_CFG_CAN_MSG_TEMPERATURE_VALID_COUNT_LIMIT;	
		CL__stMainObject.stCount.u8ECM3TemperatureValueInvalidCount = 0u;
		CL__stMainObject.stCount.u8ECM3TemperatureStatusInvalidCount = 0u;
		
#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)

		CL__stMainObject.stCount.u8ADCValueInvalidCount = 0;

#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
	}
	else //System Faild,do nothing
	{

	}
#endif //(CL_CFG_COOLANT_FUNCTION == TRUE)
}
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
sint16 CL_API_s16GetRealEngineTemperature(CL_API_enOUTPUT_ACCUACY enAccuacy)
{
	return (CL_CORE__s16FormatDataAccuracy(CL_CFG_REAL_VALUE_MAX,CL_CFG_REAL_VALUE_MIN,\
										  (uint16)enAccuacy,0,\
										  CM_CFG_REAL_TEMPERATRUE_VALUE_INTERFACE_ROUND_CONFIG,\
										  CL__stMainObject.s16RealTemperatureFromCAN));
}
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
uint16 CL_API_u16GetCurrentIndicateEngineTemperature(CL_API_enOUTPUT_ACCUACY enAccuacy)
{
	return ((uint16)CL_CORE__s16FormatDataAccuracy(CL_CFG_REAL_VALUE_MAX,CL_CFG_REAL_VALUE_MIN,\
												  (uint16)enAccuacy,0,\
												  CM_CFG_REAL_TEMPERATRUE_VALUE_INTERFACE_ROUND_CONFIG,\
												  (sint16)CL__stMainObject.u16CurrentIndicateTemperature));
}
/**********************************************************************************************************
*Function   : CL_API_u16GetGaugeParkCounts                                                                *
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
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)	
uint16 CL_API_u16GetGaugeParkCounts(void)
{
	return (CL__stMainObject.u16GaugeMinMotorStepCounts);
}
#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : CL_API_u16GetGaugeMaxCounts                                                                 *
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
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)	
uint16 CL_API_u16GetGaugeMaxCounts(void)
{
	return (CL__stMainObject.u16GaugeMaxMotorStepCounts);
}
#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : CL_API_u16GetGaugeTargetStepCounts                                                          *
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
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)	
uint16 CL_API_u16GetGaugeTargetStepCounts(void)
{
	return (CL__stMainObject.u16GaugeTargetStepCounts);
}
#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)	
/**********************************************************************************************************
*Function   : CL_API_u16GetGaugeCurrentStepCounts                                                         *
*                                                                                                         *
*Description: The function get current step counts for Gauge driver module                                *
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
uint16 CL_API_u16GetGaugeCurrentStepCounts(void)
{
	return (CL__stMainObject.u16GaugeCurrentStepCounts);
}
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
void CL_API_vDiagSetGaugeStatus(CL_CFG_enDIAG_SET_GAUGE_STATUS enStatus)
{
	
}
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
void CL_API_vEOLSetGaugeStepCounts(uint16 u16TargetStepCounts)
{
	CL__stMainObject.u16GaugeTargetStepCounts = u16TargetStepCounts;
	CL__stMainObject.u16GaugeCurrentStepCounts = u16TargetStepCounts;
}
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
uint16 CL_API_u16GetBarTargetStepCounts(void)
{
	return (CL__stMainObject.u16BarTargetStepCounts);
}
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
uint16 CL_API_u16GetBarCurrentStepCounts(void)
{
	return (CL__stMainObject.u16BarCurrentStepCounts);
}
#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)
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
boolean CL_API_boGetCoolantCANMessageInvalidStatus(void)
{
	boolean boReturn ;
	
	if(CL_CORE_boCheckSystemErrorStatus(CL_ECM3_CAN_MSG_INVALID,&CL__stMainObject) == TRUE)
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
*	Coolant Custom Application Interface													              *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*Function   : CL__boPowerModeCheckProcess                                                                 *
*                                                                                                         *
*Description: The function is used to check power mode is ign on which status can coolant work            *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
static boolean CL__boPowerModeCheckProcess(void)
{
	boolean boReturn = FALSE;
	SystemState_RecordType *u8PowerMode;
	u8PowerMode = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
	
	/*Check power off */
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
	if((SYSTEMSTATE_Cluster_ON == u8PowerMode->ClusterState) && (SYSTEMSTATE_Cluster_ON != l_CL_ClusterStateLast_U8))
	{
		l_CLDebugLogFlag = TRUE;
	}
	else
	{
		l_CLDebugLogFlag = FALSE;
	}
	l_CL_ClusterStateLast_U8 = u8PowerMode->ClusterState;
#if 0	
	{
		u32PowerModeStatus |= (uint32)CL_enOFF;
	}
	else
	{
		/*Do nothing but avoid QAC*/
	}
	
	/*Check power on */
	if(CL_CFG_POWER_STATE_IS_RUN)
	{
		u32PowerModeStatus |= (uint32)CL_enRUN;
	}
	else
	{
		/*Do nothing but avoid QAC*/
	}
	
	/*Check power High voltage */
	if(CL_CFG_POWER_STATE_IS_ABNORMAL_VOLTAGE)
	{
		u32PowerModeStatus |= (uint32)CL_enABNORMAL_VOLTAGE;
	}
	else
	{
		/*Do nothing but avoid QAC*/
	}
	
	if(((uint32)CL_enRUN) & u32PowerModeStatus)
	{
		/*Ign on status,so set return to TRUE*/
		boReturn = TRUE;
	}
	else
	{
		boReturn = FALSE;
	}

#if (CL_CFG_IGN_ON_FIRST_INDICATE_WITH_NO_DAMPING == TRUE)
	/*When ignition on, set flag*/
	if((u32PowerModeStatus&CL_enRUN)&&((u32LastPowerModeStatus&CL_enOFF) || (u32PowerModeStatus&CL_enABNORMAL_VOLTAGE)))
	{
		CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 1;
		CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp = 1;
	}
	else if(u32PowerModeStatus&CL_enOFF || u32PowerModeStatus&CL_enABNORMAL_VOLTAGE)
	{
		CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 2;
		CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp = 1;
	}
	else
	{
		//CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 1;
		//CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp = 2;
	}
#endif //(CL_CFG_IGN_ON_FIRST_INDICATE_WITH_NO_DAMPING == TRUE)
	
	/*Save current power mode status*/
	CL__stMainObject.unPowerModeStatus.u32PowerModeStatus = u32PowerModeStatus;
#endif
	return boReturn;
}
/**********************************************************************************************************
*Function   : CL__vPowerModeIgnitionOffProcess                                                            *
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
static void CL__vPowerModeIgnitionOffProcess(void)
{
	CL__stMainObject.u16LastTargetIndicateTemperature = 0;
	CL__stMainObject.unFunctionFlag.stFuncFlag.IncreaseClimate = 1u;
	
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)	
	CL__stMainObject.s16RealTemperatureFromCAN = 0;
#endif

#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)	
	CL__stMainObject.s16RealTemperatureFromADC = 0;
#endif

	CL__stMainObject.u16TargetIndicateTemperature = 0;
	CL__stMainObject.u16CurrentIndicateTemperature = 0;

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)	
	/*Ignition off is no damping to sweep pointer so homing immediately*/
	CL__vGaugeDoHoming();
#endif 

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)
	CL__stMainObject.u16BarTargetStepCounts = 0;
	CL__stMainObject.u16BarCurrentStepCounts = 0;
#endif

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_SBUS) != FALSE)
	/*Send SBUS message*/
	CL__vSBUSSendMessage();
#endif 
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_TLC) != FALSE)
	/*Send SBUS message*/
	(void)CL__vTLCSendMessage();
#endif 

#if 0 //E315 Project

	TP596_vSetCoolantLedLevel(CL__stMainObject.u16BarCurrentStepCounts);

#endif
}
/**********************************************************************************************************
*Function   : CL__boECM3CANMessageValidCheckProcess                                                        *
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
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
static boolean CL__boECM3CANMessageValidCheckProcess(void)
{
	boolean boReturn = FALSE;
	uint8 u8ECM3Sts_Rte = 0;
	uint8 fl_CL_MSG_MissingStatus = TRUE;
	
#ifdef GWM_V35_PROJECT_TYPE_B02_CL
	u8ECM3Sts_Rte = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPVLDTY, (uint8 *)&CL_EngClntTempVldty, (uint8)sizeof(CL_EngClntTempVldty));
	
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, (uint8 *)&CL_EngClntTempRedDisp, (uint8)sizeof(CL_EngClntTempRedDisp));
#elif defined GWM_V35_PROJECT_TYPE_B03_CL
	u8ECM3Sts_Rte = Rte_Read_EngClntTempVldty_EngClntTempVldty(&CL_EngClntTempVldty);
	
	Rte_Read_EngClntTempWarn_EngClntTempWarn(&CL_EngClntTempRedDisp);
#elif defined GWM_V35_PROJECT_TYPE_P03_CL
	u8ECM3Sts_Rte = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPVLDTY, (uint8 *)&CL_EngClntTempVldty, (uint8)sizeof(CL_EngClntTempVldty));
	
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, (uint8 *)&CL_EngClntTempRedDisp, (uint8)sizeof(CL_EngClntTempRedDisp));
#elif defined GWM_V35_PROJECT_TYPE_P05_CL
	u8ECM3Sts_Rte = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPVLDTY, (uint8 *)&CL_EngClntTempVldty, (uint8)sizeof(CL_EngClntTempVldty));
	
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, (uint8 *)&CL_EngClntTempRedDisp, (uint8)sizeof(CL_EngClntTempRedDisp));
#elif defined GWM_V35_PROJECT_TYPE_A07_CL
	u8ECM3Sts_Rte = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPVLDTY, (uint8 *)&CL_EngClntTempVldty, (uint8)sizeof(CL_EngClntTempVldty));
	
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, (uint8 *)&CL_EngClntTempRedDisp, (uint8)sizeof(CL_EngClntTempRedDisp));
#elif defined GWM_V35_PROJECT_TYPE_D01_CL
	u8ECM3Sts_Rte = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPVLDTY, (uint8 *)&CL_EngClntTempVldty, (uint8)sizeof(CL_EngClntTempVldty));
	
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, (uint8 *)&CL_EngClntTempRedDisp, (uint8)sizeof(CL_EngClntTempRedDisp));
#elif defined GWM_V35_PROJECT_TYPE_D02_CL
	u8ECM3Sts_Rte = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPVLDTY, (uint8 *)&CL_EngClntTempVldty, (uint8)sizeof(CL_EngClntTempVldty));
	
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, (uint8 *)&CL_EngClntTempRedDisp, (uint8)sizeof(CL_EngClntTempRedDisp));
#elif defined GWM_V35_PROJECT_TYPE_D03_CL
	u8ECM3Sts_Rte = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPVLDTY, (uint8 *)&CL_EngClntTempVldty, (uint8)sizeof(CL_EngClntTempVldty));
	
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, (uint8 *)&CL_EngClntTempRedDisp, (uint8)sizeof(CL_EngClntTempRedDisp));
#elif defined GWM_V35_PROJECT_TYPE_P02_CL
	u8ECM3Sts_Rte = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPVLDTY, (uint8 *)&CL_EngClntTempVldty, (uint8)sizeof(CL_EngClntTempVldty));
	
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, (uint8 *)&CL_EngClntTempRedDisp, (uint8)sizeof(CL_EngClntTempRedDisp));
#elif defined GWM_V35_PROJECT_TYPE_P01_CL
	u8ECM3Sts_Rte = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPVLDTY, (uint8 *)&CL_EngClntTempVldty, (uint8)sizeof(CL_EngClntTempVldty));
		
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, (uint8 *)&CL_EngClntTempRedDisp, (uint8)sizeof(CL_EngClntTempRedDisp));
#else
#endif

	CL__stMainObject.uEngClntTempVldty = CL_EngClntTempVldty;
#if 0
#if (CL_CFG_CAN_MSG_VALID_COUNT_PLUS_IN_TIME_TASK == TRUE)

	CL_API_vECM3CANMessageCountProcess();

#endif //(CL_CFG_CAN_MSG_VALID_COUNT_PLUS_IN_TIME_TASK == TRUE)

	//Check msg 
	if(FALSE == CL_CFG_CAN_ECM3_MSG_MISSING(u8ECM3Sts_Rte))
	{
		if((CL__stMainObject.stCount.u8ECM3TemperatureValueValidCount >= CL_CFG_CAN_MSG_TEMPERATURE_VALID_COUNT_LIMIT)&&\
		   (CL__stMainObject.stCount.u8ECM3TemperatureStatusValidCount >= CL_CFG_CAN_MSG_TEMPERATURE_VALID_COUNT_LIMIT))
		{
#if (CL_CFG_INPUT_VALID_FIRST_INDICATE_WITH_NO_DAMPING == TRUE)
			/*Enable first update flag*/
			if(CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate == 0u)
			{
				CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 1u;
			}
			else
			{

			}
			if(CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp == 0u)
			{
				CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp = 1;
			}
			else
			{

			}
			
#endif //(CL_CFG_INPUT_VALID_FIRST_INDICATE_WITH_NO_DAMPING == TRUE)
			CL__stMainObject.unFunctionFlag.stFuncFlag.ECM3ValueInvalidButKeep = 0u;/*0 is disable*/
			boReturn = TRUE;
		}
		else if(((CL__stMainObject.stCount.u8ECM3TemperatureValueValidCount == 0u)&&\
			      (CL__stMainObject.stCount.u8ECM3TemperatureValueInvalidCount < CL_CFG_CAN_MSG_TEMPERATURE_INVALID_COUNT_LIMIT))&&\
			    ((CL__stMainObject.stCount.u8ECM3TemperatureStatusValidCount == 0u)&&\
			    (CL__stMainObject.stCount.u8ECM3TemperatureStatusInvalidCount < CL_CFG_CAN_MSG_TEMPERATURE_INVALID_COUNT_LIMIT)))
		{
			CL__stMainObject.unFunctionFlag.stFuncFlag.ECM3ValueInvalidButKeep = 1u;/*1 is enable*/
			boReturn = TRUE;
		}
		else
		{
			CL__stMainObject.unFunctionFlag.stFuncFlag.ECM3ValueInvalidButKeep = 0u;/*0 is disable*/
			boReturn = FALSE;
		}
	}
	else
	{
		/*Set flag*/
#if (CL_CFG_INPUT_INVALID_RETURN_TO_ZERO_WITH_NO_DAMPING == TRUE)
		CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 0;
		CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp = 0;
#else
		if((CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate == 0)\
		||(CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate == 1))
		{
			CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 2;
		}
		else
		{
			
		}
		if((CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp == 0)\
		||(CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp == 1))
		{
			CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp = 2;
		}
		else
		{
			
		}
#endif //(CL_CFG_INPUT_INVALID_RETURN_TO_ZERO_WITH_NO_DAMPING == FALSE)

		CL__stMainObject.unFunctionFlag.stFuncFlag.ECM3ValueInvalidButKeep = 0u;/*0 is normal*/
		boReturn = FALSE;
	}
#endif
	if(FALSE == (CL_CFG_CAN_ECM3_MSG_MISSING(u8ECM3Sts_Rte)))
	{
		boReturn = TRUE;
		fl_CL_MSG_MissingStatus = FALSE;
	}
	else
	{
		/* do nothing */
	}

	if (TRUE == SWC_CL_LOGOUT_ENBLE)/* CL DEBUG Log Print*/
	{
		/* If Msg Receive Status Change Or Power Status Change*/
		if((fl_CL_MSG_MissingStatus != l_boReturn_last_U8) || (TRUE == l_CLDebugLogFlag))
		{
			if(TRUE == fl_CL_MSG_MissingStatus)/* If MSG missing print 1 */
			{
				SWC_CL_PRINT_WARN("Coolant:MSGMissSts:%d", fl_CL_MSG_MissingStatus);
			}
			else/*If MSG Receive Print 0*/
			{
				SWC_CL_PRINT_WARN("Coolant:MSGMissSts:%d", fl_CL_MSG_MissingStatus);
			}
		}
		else
		{
			/* Do Nothing */
		}
	}

	l_boReturn_last_U8 = fl_CL_MSG_MissingStatus;
	return boReturn;
}
#endif // ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/**********************************************************************************************************
*Function   : CL__vGetRealEngineTemperatureFromCAN                                                        *
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
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
static void CL__vGetRealEngineTemperatureFromCAN(void)
{
#if 0
	if(CL__stMainObject.unFunctionFlag.stFuncFlag.ECM3ValueInvalidButKeep == 0u)
	{
		/*Calculate real temperature from formula*/
		CL_CFG_vFormulaOfGetRealTemperatureFromCANRawValue(&CL__stMainObject);
	}
	else
	{
		/*Keep previous status for this time*/
	}
#endif
	CL_CFG_vFormulaOfGetRealTemperatureFromCANRawValue(&CL__stMainObject);
}
#endif // ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/**********************************************************************************************************
*Function   : CL__vECM3CANMessageInvaildProcess                                                            *
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
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
static void CL__vECM3CANMessageInvaildProcess(void)
{
	CL__stMainObject.s16RealTemperatureFromCAN = 0;
	CL_EngClntTempRedDisp = 0;
}
#endif // ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/**********************************************************************************************************
*Function   : CL__boADCInputValidCheckProcess                                                             *
*                                                                                                         *
*Description: The function is used to check ADC input signal is received normally                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
static boolean CL__boADCSignalValidCheckProcess(void)
{
	boolean boReturn = FALSE;
	/*Invalid count*/
	if(!CL_CFG_ADC_TEMPERATURE_VALUE_VALID)
	{
		CL__stMainObject.stCount.u8ADCValueInvalidCount ++;
		
		/*Avoid Overflow*/
		if(CL__stMainObject.stCount.u8ADCValueInvalidCount >= CL_CFG_ADC_SIGNAL_VALUE_INVALID_COUNT_LIMIT)
		{
			CL__stMainObject.stCount.u8ADCValueInvalidCount = CL_CFG_ADC_SIGNAL_VALUE_INVALID_COUNT_LIMIT;
		}
		else
		{
			
		}
	}
	else
	{
		CL__stMainObject.stCount.u8ADCValueInvalidCount = 0;
	}
	
	//Check msg 
	if(CL_CFG_ADC_STATUS_CHECK_OK && CL_CFG_ADC_TEMPERATURE_VALUE_VALID)
	{
#if (CL_CFG_INPUT_VALID_FIRST_INDICATE_WITH_NO_DAMPING == TRUE)
		/*Enable first update flag*/
		if(CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate == 0u)
		{
			CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 1u;
		}
		else
		{

		}
		if(CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp == 0u)
		{
			CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp = 1u;
		}
		else
		{

		}
#endif //(CL_CFG_INPUT_VALID_FIRST_INDICATE_WITH_NO_DAMPING == TRUE)

		CL__stMainObject.unFunctionFlag.stFuncFlag.ADCValueInvalidButKeep = 0u;/*0 is disable*/
		boReturn = TRUE;
	}
	else if(CL_CFG_ADC_STATUS_CHECK_OK && \
		(!CL_CFG_ADC_TEMPERATURE_VALUE_VALID)&&\
		(CL__stMainObject.stCount.u8ADCValueInvalidCount < CL_CFG_ADC_SIGNAL_VALUE_INVALID_COUNT_LIMIT))
	{
		CL__stMainObject.unFunctionFlag.stFuncFlag.ADCValueInvalidButKeep = 1u;/*1 is enable*/	
		boReturn = TRUE;
   	}
	else
	{
	/*Set flag*/
#if (CL_CFG_INPUT_INVALID_RETURN_TO_ZERO_WITH_NO_DAMPING == TRUE)
		CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 0;
		CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp = 0;
#else
		if((CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate == 0)\
		||(CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate == 1))
		{
			CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 2;
		}
		else
		{
			
		}
		if((CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp == 0)\
		||(CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp == 1))
		{
			CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp = 2;
		}
		else
		{
			
		}
#endif //(CL_CFG_INPUT_INVALID_RETURN_TO_ZERO_WITH_NO_DAMPING == TRUE)

		CL__stMainObject.unFunctionFlag.stFuncFlag.ADCValueInvalidButKeep = 0u;/*0 is disable*/
		boReturn = FALSE;
	}

	return boReturn;
}
#endif // ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
/**********************************************************************************************************
*Function   : CL__vGetRealEngineTemperatureFromADC                                                        *
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
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
static void CL__vGetRealEngineTemperatureFromADC(void)
{
	if(CL__stMainObject.unFunctionFlag.stFuncFlag.ADCValueInvalidButKeep == 0u)
	{
		/*Calculate real temperature from formula*/
		CL_CFG_vFormulaOfGetRealTemperatureFromADCRawValue(&CL__stMainObject);
	}
	else
	{
		/*Keep previous status for this time*/
	}
}
#endif // ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
/**********************************************************************************************************
*Function   : CL__vADCSignalInvaildProcess                                                                *
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
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
static void CL__vADCSignalInvaildProcess(void)
{
	CL__stMainObject.s16RealTemperatureFromADC = 0;
}
#endif // ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
/**********************************************************************************************************
*Function   : CL__boCalculateTargetIndicateEngineTemperature                                              *
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
static boolean CL__boCalculateTargetIndicateEngineTemperature(void)
{
	boolean boReturn = FALSE;
	sint16 s16Tempdata = 0;

#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
    if (FALSE == CL_CORE_boCheckSystemErrorStatus(CL_ECM3_CAN_MSG_INVALID, &CL__stMainObject))
    {
        if (TRUE == CL__stMainObject.uEngClntTempVldty)
        {
            CL__stMainObject.s16ValidRealTemperature = (CL__stMainObject.s16RealTemperatureFromCAN / 10);
            if (CL__stMainObject.s16ValidRealTemperature >= g_coolantPointVal[7])
            {
                l_CL_EngClntTemp_Percent_S16 = 1000;
            }
			else if (CL__stMainObject.s16ValidRealTemperature >= g_coolantPointVal[6])
            {
				s16Tempdata = 875 + ((1000 - 875) * (CL__stMainObject.s16ValidRealTemperature - g_coolantPointVal[6]) / (g_coolantPointVal[7] - g_coolantPointVal[6]));
                l_CL_EngClntTemp_Percent_S16 = s16Tempdata;
            }
            else if (CL__stMainObject.s16ValidRealTemperature >= g_coolantPointVal[5])
            {
				s16Tempdata = 750 + ((875 - 750) * (CL__stMainObject.s16ValidRealTemperature - g_coolantPointVal[5]) / (g_coolantPointVal[6] - g_coolantPointVal[5]));
                l_CL_EngClntTemp_Percent_S16 = s16Tempdata;
            }
			else if (CL__stMainObject.s16ValidRealTemperature >= g_coolantPointVal[4])
            {
				s16Tempdata = 625 + ((750 - 625) * (CL__stMainObject.s16ValidRealTemperature - g_coolantPointVal[4]) / (g_coolantPointVal[5] - g_coolantPointVal[4]));
                l_CL_EngClntTemp_Percent_S16 = s16Tempdata;
            }
            else if (CL__stMainObject.s16ValidRealTemperature >= g_coolantPointVal[3])
            {
				s16Tempdata = 500 + ((625 - 500) * (CL__stMainObject.s16ValidRealTemperature - g_coolantPointVal[3]) / (g_coolantPointVal[4] - g_coolantPointVal[3]));
                l_CL_EngClntTemp_Percent_S16 = s16Tempdata;
            }
            else if (CL__stMainObject.s16ValidRealTemperature >= g_coolantPointVal[2])
            {
                l_CL_EngClntTemp_Percent_S16 = 500;
            }
            else if (CL__stMainObject.s16ValidRealTemperature >= g_coolantPointVal[1])
            {
				s16Tempdata = 250 + ((500 - 250) * (CL__stMainObject.s16ValidRealTemperature - g_coolantPointVal[1]) / (g_coolantPointVal[2] - g_coolantPointVal[1]));
                l_CL_EngClntTemp_Percent_S16 = s16Tempdata;
            }
            else if (CL__stMainObject.s16ValidRealTemperature >= g_coolantPointVal[0])
            {
				s16Tempdata = 0 + ((250 - 0) * (CL__stMainObject.s16ValidRealTemperature - g_coolantPointVal[0]) / (g_coolantPointVal[1] - g_coolantPointVal[0]));
                l_CL_EngClntTemp_Percent_S16 = s16Tempdata;
            }
            else
            {
                l_CL_EngClntTemp_Percent_S16 = 0;
            }
        }
        else
        {
            CL__stMainObject.s16ValidRealTemperature = (sint16)0xFFFF;
            l_CL_EngClntTemp_Percent_S16 = 0;
        }
        boReturn = TRUE;
    }
#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
	else if(FALSE == CL_CORE_boCheckSystemErrorStatus(CL_ADC_SIGNAL_INVALID,&CL__stMainObject))
	{
		CL__stMainObject.s16ValidRealTemperature = CL__stMainObject.s16RealTemperatureFromADC;
		boReturn = TRUE;
	}
#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
	else
	{
		/*No input valid*/
		CL__stMainObject.s16ValidRealTemperature = (sint16)0xFFFF;
        l_CL_EngClntTemp_Percent_S16 = 0;
		boReturn = FALSE;
	}

#if 0
	CL__stMainObject.u16LastTargetIndicateTemperature = CL__stMainObject.u16TargetIndicateTemperature;

	/*Calculate indicate temperature from formula*/
	CL_CFG_vFormulaOfGetTargetIndicateTemperatureFromRealTemperature(&CL__stMainObject);

	//Increase climate flag
	if(CL__stMainObject.u16TargetIndicateTemperature > CL__stMainObject.u16LastTargetIndicateTemperature)
	{
		CL__stMainObject.unFunctionFlag.stFuncFlag.IncreaseClimate = 1u;
	}
	else if(CL__stMainObject.u16TargetIndicateTemperature < CL__stMainObject.u16LastTargetIndicateTemperature)
	{
		CL__stMainObject.unFunctionFlag.stFuncFlag.IncreaseClimate = 0u;
	}
	else
	{
		/*Keep previous climate*/
	}
#endif
	return boReturn;
}
/**********************************************************************************************************
*Function   : CL__vAllInputInvaildProcess                                                                 *
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
static void CL__vAllInputInvaildProcess(void)
{
#if (CL_CFG_INPUT_INVALID_RETURN_TO_ZERO_WITH_NO_DAMPING == TRUE)
	CL__stMainObject.u16TargetIndicateTemperature = 0;
	CL__stMainObject.u16CurrentIndicateTemperature = 0;

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)	
	/*Ignition off is no damping to sweep pointer so homing immediately*/
	CL__vGaugeDoHoming();
#endif 

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)
	CL__stMainObject.u16LastTargetIndicateTemperature = 0;
	CL__stMainObject.u16BarTargetStepCounts = 0;
	CL__stMainObject.u16BarCurrentStepCounts = 0;
	#if 0 /*E315 Project*/
	TP596_vSetCoolantLedLevel(CL__stMainObject.u16BarCurrentStepCounts);
	#endif
#endif

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_SBUS) != FALSE)
	/*Send SBUS message*/
	CL__vSBUSSendMessage();
#endif
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_TLC) != FALSE)
	/*Send SBUS message*/
	(void)CL__vTLCSendMessage();
#endif

#endif //(CL_CFG_INPUT_INVALID_RETURN_TO_ZERO_WITH_NO_DAMPING == TRUE)
}
/**********************************************************************************************************
*Function   : CL__boDampingHandling                                                                       *
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
static boolean CL__boDampingHandling(void)
{
#if 0
	uint16 u16IndicationMinimum = 0;
	uint16 u16IndicationMaximum = 0;

	if(CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate == 1u) //1u means need to update current immediately
	{
		CL__stMainObject.u16CurrentIndicateTemperature = CL__stMainObject.u16TargetIndicateTemperature;
		
		CL__stMainObject.unFunctionFlag.stFuncFlag.FirstUpdate = 2u; //2u means update operation is already done
	}
	else 
	{	//Full dial use only one damping model
#if (CL_CFG_DAMPING_MODEL == CL_CFG_THREAD_DAMPING_MODEL)
		CL_CORE__u16DampingModel_Thread(&CL__stMainObject.u16TargetIndicateTemperature,&CL__stMainObject.u16CurrentIndicateTemperature,\
										 CL_CFG_THREAD_DAMPING_MODEL_PARAMETER_DEFAULT_VALUE); 
#elif(CL_CFG_DAMPING_MODEL == CL_CFG_KX_PLUS_B_DAMPING_MODEL)
		CL_CORE__u16DampingModel_kX_Plus_b(&CL__stMainObject.u16TargetIndicateTemperature,&CL__stMainObject.u16CurrentIndicateTemperature,\
											CL_CFG_KXPB_DAMPING_MODEL_PARAMETER_K1_DEFAULT_VALUE,\
											CL_CFG_KXPB_DAMPING_MODEL_PARAMETER_K2_DEFAULT_VALUE,\
											CL_CFG_KXPB_DAMPING_MODEL_PARAMETER_B_DEFAULT_VALUE);
#elif(CL_CFG_DAMPING_MODEL == CL_CFG_MODEL_FROM_CONFIG_CODE)

		/*Calculate current indicate speed from formula*/
		CL_CFG_vFormulaOfUserDefinedDampingOperation(&CL__stMainObject);

#else //No damping
		CL__stMainObject.u16CurrentIndicateTemperature = CL__stMainObject.u16TargetIndicateTemperature;
#endif
	}

	if((CL__stMainObject.u16TargetIndicateTemperature >= CL_CFG_GAUGE_MIN)&&\
	   (CL__stMainObject.u16TargetIndicateTemperature <= CL_CFG_GAUGE_MAX))
	{
		CL__stMainObject.u16CurrentIndicateTemperature = (uint16)\
		CL_CORE__s16FormatDataAccuracy(CL_CFG_GAUGE_MAX,CL_CFG_GAUGE_MIN,\
									   1,0,0,\
									  (sint16)CL__stMainObject.u16CurrentIndicateTemperature);
	}
	else
	{

	}

	/*Damping only work in gauge indication range*/
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)

	u16IndicationMinimum = CL_CFG_GAUGE_MIN;
	
	u16IndicationMaximum = CL_CFG_GAUGE_MAX;

#elif ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)

	u16IndicationMinimum = CL_CFG_BAR_MIN;
	
	u16IndicationMaximum = CL_CFG_BAR_MAX;

#endif //CL_CFG_OUTPUT_MODE

	if((CL__stMainObject.u16CurrentIndicateTemperature <= u16IndicationMinimum)\
	 &&(CL__stMainObject.u16TargetIndicateTemperature > u16IndicationMinimum))
	{
		CL__stMainObject.u16CurrentIndicateTemperature = u16IndicationMinimum;
	}
	else if((CL__stMainObject.u16CurrentIndicateTemperature > u16IndicationMaximum)\
	 &&(CL__stMainObject.u16TargetIndicateTemperature < u16IndicationMaximum))
	{
		CL__stMainObject.u16CurrentIndicateTemperature = u16IndicationMaximum;
	}
	else
	{

	}

#endif
	return TRUE;
}
/**********************************************************************************************************
*Function   : CL__vSetGaugeTargetStepCounts                                                               *
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
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
static void CL__vSetGaugeTargetStepCounts(uint16 u16TargetStepCounts)
{
	if(CL_CFG_EOL_MODE_ENABLE||CL_CFG_ETM_MODE_ENABLE||CL_CFG_DIAGNOSIS_MODE_ENABLE)
	{
		
	}	
	else 
	{
		CL__stMainObject.u16GaugeTargetStepCounts = (uint16)\
		CL_CORE__s16FormatDataAccuracy(CL__stMainObject.u16GaugeMaxMotorStepCounts,\
									   CL__stMainObject.u16GaugeMinMotorStepCounts,\
									   1,0,0,\
									   (sint16)u16TargetStepCounts);
	}
}
#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : CL__vSetGaugeCurrentStepCounts                                                              *
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
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
static void CL__vSetGaugeCurrentStepCounts(uint16 u16CurrentStepCounts)
{
	if(CL_CFG_EOL_MODE_ENABLE||CL_CFG_ETM_MODE_ENABLE||CL_CFG_DIAGNOSIS_MODE_ENABLE)
	{
		
	}	
	else 
	{
		CL__stMainObject.u16GaugeCurrentStepCounts = (uint16)\
		CL_CORE__s16FormatDataAccuracy(CL__stMainObject.u16GaugeMaxMotorStepCounts,\
									   CL__stMainObject.u16GaugeMinMotorStepCounts,\
									   1,0,0,\
									   (sint16)u16CurrentStepCounts);
	}
}
#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : CL__boCalculateGaugeStepCounts                                                              *
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
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
static boolean CL__boCalculateGaugeStepCounts(void)
{
	//Gauge target step counts
	CL__vSetGaugeTargetStepCounts(CL_CORE_u16CalulauteGaugeTableStepCounts((uint16*)&CL__stMainObject.u16GaugeTable,CL__stMainObject.u16TargetIndicateTemperature)); 
	
	//Gauge current step counts
	CL__vSetGaugeCurrentStepCounts(CL_CORE_u16CalulauteGaugeTableStepCounts((uint16*)&CL__stMainObject.u16GaugeTable,CL__stMainObject.u16CurrentIndicateTemperature));

	return TRUE;
}
#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : CL__vGaugeDoHoming                                                                          *
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
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
static void CL__vGaugeDoHoming(void)
{
	CL__vSetGaugeTargetStepCounts(CL__stMainObject.u16GaugeMinMotorStepCounts);
	CL__vSetGaugeCurrentStepCounts(CL__stMainObject.u16GaugeMinMotorStepCounts);
}
#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : CL__boCalculateGaugeTargetStepCountsLimit                                                   *
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
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
static boolean CL__boCalculateGaugeTargetStepCountsLimit(void)
{	
	CL__stMainObject.u16GaugeMaxMotorStepCounts = \
	(CL_CORE_u16CalulauteGaugeTableStepCounts((uint16*)&CL__stMainObject.u16GaugeTable,CL_CFG_GAUGE_MAX));

	CL__stMainObject.u16GaugeMinMotorStepCounts = \
	(CL_CORE_u16CalulauteGaugeTableStepCounts((uint16*)&CL__stMainObject.u16GaugeTable,CL_CFG_GAUGE_MIN));

	return TRUE;
}
#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : CL__boCheckEEPROMGaugeTableProcess                                                         *
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
#if (((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)&&(CL_CFG_GAUGE_TBL_SOURCE == CL_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE))
static boolean CL__boCheckEEPROMGaugeTableProcess(void)
{
#if(CL_CFG_DEBUG == TRUE) 

	boolean boPrintFlag = FALSE;

#endif 
	boolean boReturn = CL_CORE_boCheckGaugeTableProcess((uint16*)&CL_CFG_GAUGE_EEPROM_TBL) ;

	if(FALSE == boReturn)
	{	
		CL_CORE_vSetSystemErrorStatus(CL_EEPROM_GAUGE_TBL_ERROR,&CL__stMainObject);
		
#if(CL_CFG_DEBUG == TRUE)
		if(boPrintFlag == FALSE)
		{
			boPrintFlag = TRUE;
printf("\
--Coolant Module Debug: Configration Error------------------\r\n\
--Function Name : CL__boCheckEEPROMGaugeTableProcess\r\n\
--Error : Gauge table in EEPROM is invalid.\r\n\
------------------------------------------------------------\r\n");
		}
		else
		{
		
		}
#endif // (CL_CFG_DEBUG == TRUE)
	}
	else
	{
#if(CL_CFG_DEBUG == TRUE)
		boPrintFlag = FALSE;
#endif
	}	
	return boReturn;
}
#endif // (((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)&&(CL_CFG_GAUGE_TBL_SOURCE == CL_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE))
/**********************************************************************************************************
*Function   : CL__vCheckROMGaugeTableProcess                                                             *
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
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
static boolean CL__vCheckROMGaugeTableProcess(void)
{
#if(CL_CFG_DEBUG == TRUE)

	boolean boPrintFlag = FALSE;	

#endif
	boolean boReturn = CL_CORE_boCheckGaugeTableProcess((uint16*)&CL__u16GaugeROMTbl) ;

	if	(FALSE == boReturn)
	{
		CL_CORE_vSetSystemErrorStatus(CL_ROM_GAUGE_TBL_ERROR,&CL__stMainObject);
		
#if(CL_CFG_DEBUG == TRUE)
	if(boPrintFlag == FALSE)
		{
			boPrintFlag = TRUE;
printf("\
--Coolant Module Debug: Configration Error------------------\r\n\
--Function Name : CL__vCheckROMGaugeTableProcess\r\n\
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
#endif // ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : CL__vCopyROMGaugeTableProcess                                                               *
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
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
static void CL__vCopyROMGaugeTableProcess(void)
{
	memcpy(&CL__stMainObject.u16GaugeTable[0],&CL__u16GaugeROMTbl[0],sizeof(CL__stMainObject.u16GaugeTable));
	CL__stMainObject.unFunctionFlag.stFuncFlag.GaugeTableSource = 1u;
}
#endif // ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
/**********************************************************************************************************
*Function   : CL__vCopyEEPROMGaugeTableProcess                                                            *
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
#if (((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)&&(CL_CFG_GAUGE_TBL_SOURCE == CL_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE))
static void CL__vCopyEEPROMGaugeTableProcess(void)
{
	memcpy(&CL__stMainObject.u16GaugeTable[0],&CL_CFG_GAUGE_EEPROM_TBL[0],sizeof(CL__stMainObject.u16GaugeTable));
	CL__stMainObject.unFunctionFlag.stFuncFlag.GaugeTableSource = 2u;
}
#endif // (((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)&&(CL_CFG_GAUGE_TBL_SOURCE == CL_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE))
/**********************************************************************************************************
*Function   : CL__boCalculateBarStepCounts                                                                *
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
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)
static boolean CL__boCalculateBarStepCounts(void)
{
#if 0
	uint16 tar_step;
#if (CL_CFG_BAR_STEPS_DAMPING != FALSE)
	uint16 damping;
#endif
//Target indicate speed
	if(CL__stMainObject.u16TargetIndicateTemperature>= CL_CFG_BAR_MAX)
	{
		CL__stMainObject.u16BarTargetStepCounts = (CL_CFG_BAR_DISPLAY_STEPS-1);
	}
#if (CL_CFG_BAR_MIN > 0)	//Aviod QAC warning
	else if(CL__stMainObject.u16TargetIndicateTemperature <= CL_CFG_BAR_MIN)
#else			
	else if(CL__stMainObject.u16TargetIndicateTemperature == CL_CFG_BAR_MIN)
#endif	
	{
		CL__stMainObject.u16BarTargetStepCounts = 0;
	}
	else
	{
		CL__stMainObject.u16BarTargetStepCounts = \
			CL_CORE_u16CalulauteBarTableStepCounts(&CL__stBarROMTbl,\
													CL__stMainObject.unFunctionFlag.stFuncFlag.IncreaseClimate,\
													CL__stMainObject.u16BarTargetStepCounts,\
													CL__stMainObject.u16TargetIndicateTemperature);
	}
	
//Current indicate speed
	if(CL__stMainObject.u16CurrentIndicateTemperature >= CL_CFG_BAR_MAX)
	{
		tar_step = CL_CFG_BAR_DISPLAY_STEPS-1;
	}
#if (CL_CFG_BAR_MIN > 0)	//Aviod QAC warning
	else if(CL__stMainObject.u16CurrentIndicateTemperature <= CL_CFG_BAR_MIN)
#else			
	else if(CL__stMainObject.u16CurrentIndicateTemperature == CL_CFG_BAR_MIN)
#endif	
	{
		tar_step = 0;
	}
	else
	{
		tar_step = CL_CORE_u16CalulauteBarTableStepCounts(&CL__stBarROMTbl,\
															CL__stMainObject.unFunctionFlag.stFuncFlag.IncreaseClimate,\
															CL__stMainObject.u16BarTargetStepCounts,\
															CL__stMainObject.u16CurrentIndicateTemperature);
	}
#if (CL_CFG_BAR_STEPS_DAMPING != FALSE)
	if(1 == CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp)
	{
		CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp = 2;
		damping = 0;
	}
	else if(3 == CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp)
	{	
		if(CL_CFG_SRART_PRECHECK)
		{
			damping = CL_CFG_STEP_COUNTS_QUICKDAMPING_PARAMETER_DEFAULT_VALUE;
			if(tar_step == CL__stMainObject.u16BarCurrentStepCounts)
			{
				CL__stMainObject.unFunctionFlag.stFuncFlag.StepUpdateNoDamp = 2;
			}
		}
		else 
		{
			damping = 0xffff;
		}
	}
	else 
	{
		damping = CL_CFG_STEP_COUNTS_DAMPING_PARAMETER_DEFAULT_VALUE;
	}
	CL__stMainObject.u16BarCurrentStepCounts = CL__boBarStepCountsDamping(tar_step,\
																		CL__stMainObject.u16BarCurrentStepCounts,\
																		damping);
#else
	CL__stMainObject.u16BarCurrentStepCounts = tar_step;
#endif
#if 0 /*E315 Project*/
	TP596_vSetCoolantLedLevel(CL__stMainObject.u16BarCurrentStepCounts);
#endif
#endif

	return TRUE;
}
#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)
/**********************************************************************************************************
*Function   : CL__boSBUSSendOperation                                                                     *
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
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_SBUS) != FALSE)
static void CL__vSBUSSendMessage(void)
{		
	IPC_M2S_ClusterAppAPPCoolant_t ipc_sendCoolant = {0};

	ipc_sendCoolant.EngCoolantTemp = (sint32)l_CL_EngClntTemp_Percent_S16;
	ipc_sendCoolant.EngCoolantTempPhysValue = CL__stMainObject.s16ValidRealTemperature;
    if((sint16)0xFFFF == CL__stMainObject.s16ValidRealTemperature)
    {
        CL_EngClntTempRedDisp = 0;
		ipc_sendCoolant.EngCoolantTempPhysValue = 0xFFFF;
    }
	ipc_sendCoolant.RedDispaly = CL_EngClntTempRedDisp;
	ipc_sendCoolant.RedZoneThreshold = 0;

	(void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_COOLANT,(uint8 *)&ipc_sendCoolant,(uint16)sizeof(IPC_M2S_ClusterAppAPPCoolant_t),FALSE);
	//IPC_M2S_ClusterAppAPPCoolant_Transmit(&ipc_sendCoolant);
}
#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_SBUS) != FALSE)
/**********************************************************************************************************
*Function   : CL__vTLCSendMessage                                                                     *
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
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_TLC) != FALSE)
static boolean CL__vTLCSendMessage(void)
{
	/* modify by fchao in 20200519
	if(CL__stMainObject.u16BarCurrentStepCounts >= (CL_CFG_BAR_DISPLAY_STEPS - 1))
	{
		TLC59116_TempSegmentSet((CL_CFG_BAR_DISPLAY_STEPS - 1),TRUE);
	}
	else 
	{
		TLC59116_TempSegmentSet((CL__stMainObject.u16BarCurrentStepCounts),FALSE);
	}
	*/
	return TRUE;
}
#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_TLC) != FALSE)

/**********************************************************************************************************
*Function   : CL__boSBUSSendOperation                                                                     *
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
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_SBUS) != FALSE)
static boolean CL__boSBUSSendOperation(void)
{
	CL__vSBUSSendMessage();
#if 0
	CL__stMainObject.u16SBUSSendCycle = (uint16)\
	CL_CORE__s16FormatDataAccuracy(CL_CFG_TEMPERATURE_SBUS_MSG_SEND_TIME_CYCLE_MAXIMUM,\
								   1,/*Cycle can not be zero*/\
								   CL_CFG_TIME_TASK_CYCLE,0,0,\
								   CL_CFG_TEMPERATURE_SBUS_MSG_SEND_TIME_CYCLE);
	if(CL__stMainObject.u16SBUSSendCycle < 1)
	{
		CL__stMainObject.u16SBUSSendCycle = 1;
	}
	if(CL__stMainObject.stTimer.u16SBUS_MessageTick % CL__stMainObject.u16SBUSSendCycle)
	{
		/*Do nothing*/
	}
	else
	{
		CL__stMainObject.stTimer.u16SBUS_MessageTick = 0;

		CL__vSBUSSendMessage();
	}

	CL__stMainObject.stTimer.u16SBUS_MessageTick ++;
#endif
	return TRUE;
}
#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_SBUS) != FALSE)
/**********************************************************************************************************
*Function   : CL__vSystemErrorObjectOperationProcess                                                      *
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
static void CL__vSystemErrorObjectOperationProcess(void)
{
	CL__stMainObject.u16LastTargetIndicateTemperature = 0 ;
	CL__stMainObject.u16TargetIndicateTemperature = 0 ;
	CL__stMainObject.u16CurrentIndicateTemperature = 0 ;
	CL__stMainObject.s16ValidRealTemperature = 0 ;

#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
	CL__stMainObject.s16RealTemperatureFromCAN = 0 ;
#endif 
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
	CL__stMainObject.s16RealTemperatureFromADC = 0 ;
#endif

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
	CL__stMainObject.u16GaugeTargetStepCounts = 0;
	CL__stMainObject.u16GaugeCurrentStepCounts = 0;
#endif

#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)
	CL__stMainObject.u16BarTargetStepCounts = 0;
	CL__stMainObject.u16BarCurrentStepCounts = 0;
#endif
	
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_SBUS) != FALSE)
	/*Send SBUS message*/
	CL__vSBUSSendMessage();
#endif
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_TLC) != FALSE)
	/*Send SBUS message*/
	(void)CL__vTLCSendMessage();
#endif
}

static boolean CL__boVehicleConfig(void)
{
	CL_CFG_vVehicleConfig(&CL__stMainObject);

	return TRUE;
}

#define SWC_CL_STOP_SEC_CODE
#include "SWC_CL_MemMap.h" 

/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
