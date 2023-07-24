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

/***********************************************************************************************************
**
**  Name         : SWC_IPC_Application.c
**
**  Description  :
**
**  Organization :
**
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "Rte_Common_GateWay.h"
#include "Ipc_if.h"
#include "VConfig_Cfg.h"

/* Ipc protocal generate file*/
#include "IPC_ClusterApp.h"
#include "IPC_IVIApp.h"
#include "IPC_Engineer.h"
#include "IPC_HUD.h"
#include "IPC_SAFETY.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_IPC_Application.h"
#include "SWC_IPC_Interface.h"
#include "SWC_IPC_CANMatrix.h"
#include "SWC_IPC_CANRepeater.h"

/* E2e config file*/
#if (defined SWC_IPC_PROJECT_TYPE_B02)
#include "E2EPW_Common_GateWay_SG_HUT_IP2_SG_HUT_IP2_tx.h"
#elif (defined SWC_IPC_PROJECT_TYPE_B03)
#include "E2EPW_Common_GateWay_SG_HUT_IP2_SG_HUT_IP2_tx.h"
#include "E2EPW_Common_GateWay_SG_DMS2_DMS_FD1_SG_DMS2_DMS_FD1_tx.h"
#include "E2EPW_Common_GateWay_SG_DMS3_DMS_FD1_SG_DMS3_DMS_FD1_tx.h"
#include "E2EPW_Common_GateWay_SG_DMS5_DMS_FD1_SG_DMS5_DMS_FD1_tx.h"
#include "E2EPW_Common_GateWay_SG_DMS6_DMS_FD1_SG_DMS6_DMS_FD1_tx.h"
#elif (defined SWC_IPC_PROJECT_TYPE_P05)
#include "E2EPW_Common_GateWay_SG_IP2_SG_IP2_tx.h"
#endif
#include "E2EPW_Common_GateWay_SG_HUT32_SG_HUT32_tx.h"
#include "E2EPW_Common_GateWay_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2_rx.h"
#include "E2EPW_Common_GateWay_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2_rx.h"
#include "E2EPW_Common_GateWay_SG_ACC6_ACC_FD2_SG_ACC6_ACC_FD2_rx.h"
#include "E2EPW_Common_GateWay_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2_rx.h"
#include "E2EPW_Common_GateWay_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2_rx.h"

/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_IPC_NW_START_SEC_CODE
#include "SWC_IPC_NW_MemMap.h"

/**********************************************************************************************************
* Static Function Defination                                                                              *
**********************************************************************************************************/
static uint8 IPC_GetCountryProcess(SWC_IPC_AppMsgObject * Object );

static void IPC_IGNACCToOFFCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object);
static void IPC_IGNONToOFFCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object);
static void IPC_IGNCrankToOFFCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object);
static void IPC_IGNInvalidToOFFCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object);

static void IPC_IGNOFFToONCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object);
static void IPC_IGNACCToONCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object);
static void IPC_IGNCrankToONCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object);
static void IPC_IGNInvalidToONCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object);

static void IPC_IGNOFFToCrankCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object);
static void IPC_IGNACCToCrankCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object);
static void IPC_IGNInvalidToCrankCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object);

#define SWC_IPC_NW_STOP_SEC_CODE
#include "SWC_IPC_NW_MemMap.h"
/**********************************************************************************************************
*                                                                                    					  *
**********************************************************************************************************/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_IPC_NW_START_SEC_CONST_UNSPECIFIED
#include "SWC_IPC_NW_MemMap.h"

static const s_IPCPowerModeTbl_t IPCPowerModeHandleTbl[(uint8)IGN_TotalNum][(uint8)IGN_TotalNum] =
{
			   /* IGN_Invalid,                                 		IGN_OFF,                                 	IGN_ACC,                                 	IGN_ON,                                 IGN_Crank, */
/* IGN_Invalid */ {{SWC_IPC_NULL},                                	{SWC_IPC_NULL}, 			                {SWC_IPC_NULL},                            	{SWC_IPC_NULL},                         {SWC_IPC_NULL}},
/* IGN_OFF */     {{IPC_IGNInvalidToOFFCanSignalOutput_Handle},   	{SWC_IPC_NULL}, 			                {IPC_IGNACCToOFFCanSignalOutput_Handle},   	{IPC_IGNONToOFFCanSignalOutput_Handle}, {IPC_IGNCrankToOFFCanSignalOutput_Handle}},
/* IGN_ACC */     {{SWC_IPC_NULL},                                	{SWC_IPC_NULL},                            	{SWC_IPC_NULL}, 		                    {SWC_IPC_NULL},                         {SWC_IPC_NULL}},
/* IGN_ON */      {{IPC_IGNInvalidToONCanSignalOutput_Handle},    	{IPC_IGNOFFToONCanSignalOutput_Handle},    	{IPC_IGNACCToONCanSignalOutput_Handle},    	{SWC_IPC_NULL}, 		                {IPC_IGNCrankToONCanSignalOutput_Handle}},
/* IGN_Crank */   {{IPC_IGNInvalidToCrankCanSignalOutput_Handle}, 	{IPC_IGNOFFToCrankCanSignalOutput_Handle}, 	{IPC_IGNACCToCrankCanSignalOutput_Handle}, 	{SWC_IPC_NULL},                         {SWC_IPC_NULL}},
};


#define SWC_IPC_NW_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_IPC_NW_MemMap.h"
/**********************************************************************************************************
*                                                                                						  *
**********************************************************************************************************/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_IPC_NW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_IPC_NW_MemMap.h"

static SWC_IPC_AppMsgObject SWC_IPC__AppMsgObject = {0} ;

#define SWC_IPC_NW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_IPC_NW_MemMap.h"
/**********************************************************************************************************
*                                                                                   					  *
**********************************************************************************************************/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_IPC_NW_START_SEC_CODE
#include "SWC_IPC_NW_MemMap.h"

/**********************************************************************************************************
* Static Function Defination                                                                              *
**********************************************************************************************************/

static void IPC_AppObjectInit(SWC_IPC_AppMsgObject * Object);

static void IPC_AppNvmBlockInit(SWC_IPC_AppMsgObject * Object);

static void IPC_E2eMsgInit(SWC_IPC_AppMsgObject * Object);

static void IPC_AppNvmBlockPeriodicUpdate(SWC_IPC_AppMsgObject * Object);

static void IPC_AppMsgPeriodicUpdate(SWC_IPC_AppMsgObject * Object);

static void IPC_ClusterFuelAndTcDataUpdate(SWC_IPC_AppMsgObject * Object);

static void IPC_ClusterTxCanSignalUpdate(SWC_IPC_AppMsgObject * Object);

static void IPC_LinkTestUpdate(SWC_IPC_AppMsgObject * Object);

static void IPC_ClusterSafetyRollingCounterUpdate(SWC_IPC_AppMsgObject * Object);

static void IPC_WhudNvmConfigUpload(SWC_IPC_AppMsgObject * Object);

static void IPC_WhudNvmConfigUpdate(SWC_IPC_AppMsgObject * Object);

static void IPC_DriveModeStorageSwitchUpload(SWC_IPC_AppMsgObject * Object);

static void IPC_MenuSettingUpload(SWC_IPC_AppMsgObject * Object);

static void IPC_ControlDTCMonitor(SWC_IPC_AppMsgObject * Object);

static void IPC_ReadDTCInfo(uint8 GroupIndex , SWC_IPC_AppMsgObject * Object);

static void IPC_RestoreTxCanSignalPhase1(SWC_IPC_AppMsgObject * Object);

static void IPC_RestoreTxCanSignalPhase2(SWC_IPC_AppMsgObject * Object);

static void IPC_TxCanSignalInit(SWC_IPC_AppMsgObject * Object);

static void IPC_OS_TxCanSignalInit(SWC_IPC_AppMsgObject * Object);

static void IPC_RestoreAppNvmConfig(SWC_IPC_AppMsgObject * Object);

static void IPC_ComWakePhase1CanSignalOutput(SWC_IPC_AppMsgObject * Object);

static void IPC_ComWakePhase2CanSignalOutput(SWC_IPC_AppMsgObject * Object);

static void IPC_IgnOnCanSignalOutput(SWC_IPC_AppMsgObject * Object);

static void IPC_IgnOffCanSignalOutput(SWC_IPC_AppMsgObject * Object);

static void IPC_IGNOFFToONCanSignalOutput(SWC_IPC_AppMsgObject * Object);

static void IPC_IGNCrankToONCanSignalOutput(SWC_IPC_AppMsgObject * Object);

static void IPC_IGNOFFToCrankCanSignalOutput(SWC_IPC_AppMsgObject * Object);

static void IPC_OS_RestoreTxCanSignalPhase1(SWC_IPC_AppMsgObject * Object);

static void IPC_OS_RestoreTxCanSignalPhase2(SWC_IPC_AppMsgObject * Object);

static void IPC_OS_ComWakePhase1CanSignalOutput(SWC_IPC_AppMsgObject * Object);

static void IPC_OS_ComWakePhase2CanSignalOutput(SWC_IPC_AppMsgObject * Object);

static void IPC_OS_IgnOnCanSignalOutput(SWC_IPC_AppMsgObject * Object);

static void IPC_OS_IgnOffCanSignalOutput(SWC_IPC_AppMsgObject * Object);

static void IPC_OS_IGNOFFToONCanSignalOutput(SWC_IPC_AppMsgObject * Object);

static void IPC_OS_IGNCrankToONCanSignalOutput(SWC_IPC_AppMsgObject * Object);

static void IPC_OS_IGNOFFToCrankCanSignalOutput(SWC_IPC_AppMsgObject * Object);

static void IPC_RestoreWisdomCruise(SWC_IPC_AppMsgObject * Object);

static void IPC_OS_RestoreWisdomCruise(SWC_IPC_AppMsgObject * Object);

//static void IPC_VehicleControlDriveModeOutput(SWC_IPC_AppMsgObject * Object);

static void IPC_SpecialTxCanSignalOperation(SWC_IPC_AppMsgObject * Object);

static void IPC_E2EAndSecOcSwitchStatusProcess(SWC_IPC_AppMsgObject * Object);

static void IPC_AppAliveMonitor(SWC_IPC_AppMsgObject * Object);

static void IPC_RestoreDataMonitor(SWC_IPC_AppMsgObject * Object);

static void IPC_RestoreAppDataMonitor(SWC_IPC_AppMsgObject * Object);

static void IPC_RestoreCanDataMonitor(SWC_IPC_AppMsgObject * Object);

static void IPC_BeanIDCanDataMonitor(SWC_IPC_AppMsgObject * Object);

static void IPC_SetTxCanSignalToApp(SWC_IPC_AppMsgObject * Object);


#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P03)\
 || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)// || (defined SWC_IPC_PROJECT_TYPE_A07)
static void IPC_DriveModSwitchMonitor(SWC_IPC_AppMsgObject * Object);
#endif

#ifdef SWC_IPC_DEBUG

static void IPC_Test(SWC_IPC_AppMsgObject * const Object);

static void IPC_AppMonitor(SWC_IPC_AppMsgObject * const Object);

static void IPC_API_PrintDataArrayDEBUGLog(const uint8 * const Data ,const uint32 Length);

#endif
/**********************************************************************************************************
*Function   : IPC_ApplicationInit                                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-17                                                                                  *
**********************************************************************************************************/
void IPC_ApplicationInit(void)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;

	IPC_AppObjectInit(Object);

	IPC_AppNvmBlockInit(Object);

	IPC_E2eMsgInit(Object);
}
/**********************************************************************************************************
*Function   : IPC_ApplicationTask                                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-17                                                                                  *
**********************************************************************************************************/
void IPC_ApplicationTask(void)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;

	IPC_AppMsgPeriodicUpdate(Object);

	IPC_AppNvmBlockPeriodicUpdate(Object);

#ifdef SWC_IPC_DEBUG

	IPC_AppMonitor(Object);

	IPC_Test(Object);

#endif
}

/**********************************************************************************************************
*Function   : IPC_AppObjectInit                                                                           *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-31                                                                                  *
**********************************************************************************************************/
static void IPC_AppObjectInit(SWC_IPC_AppMsgObject * Object)
{
#if 0
	uint8 ReadResult = E_NOT_OK;
#endif

	/*Clear object ram data.*/
	(void)memset(Object, 0, sizeof(SWC_IPC_AppMsgObject));

	/*Calculate nvm size*/
	Object->NvmBlockSize = (uint8)SWC_IPC_MIN(sizeof(SWC_IPC_AppConfigNvmBlock), SWC_IPC_CONFIG_NVM_SIZE);
#if 0
	/*SecOc switch*/
	Rte_Call_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation(sizeof(Object->SecOcSwitchValue), &Object->SecOcSwitchValue, &ReadResult);

	if (E_OK != ReadResult)
	{
		SWC_IPC_PRINT_ERROR("SecOc switch init failed!");
	}

	/*E2e switch*/
	Rte_Call_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation(sizeof(Object->E2ESwitchValue), &Object->E2ESwitchValue, &ReadResult);

	if (E_OK != ReadResult)
	{
		SWC_IPC_PRINT_ERROR("E2E switch init failed!");
	}

#endif

	if (E_OK == Rte_Read_Vconfig_GetKindBuffers_AllKinds(Object->VehicleConfig))
    {
		SWC_IPC_PRINT_DEBUG("Vconfig was successfully obtained during initialization!");
	}
	else
	{
		SWC_IPC_PRINT_DEBUG("Failed to get Vconfig during initialization!");
	}

	/*Set trigger*/
	Object->BootDelayTrigger = TRUE;
}

/**********************************************************************************************************
*Function   : IPC_AppNvmBlockInit                                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-08                                                                                  *
**********************************************************************************************************/
static void IPC_AppNvmBlockInit(SWC_IPC_AppMsgObject * Object)
{
	Object->NvmUpdateSwitch = FALSE;

	(void)memcpy((void *)(&(Object->AppNvm)),
	        (void *)Rte_Pim_NvBlockNeed_Block_IPC_Config_Data_MirrorBlock(),
	        Object->NvmBlockSize);

	if (Object->AppNvm.NvmVersion != SWC_IPC_APP_CONFIG_NVM_VERSION)
	{
		SWC_IPC_PRINT_WARNING("App nvm block last version: %d , current version: %d. Version updated! Restore app nvm block!",
			                  Object->AppNvm.NvmVersion,SWC_IPC_APP_CONFIG_NVM_VERSION);

		(void)memset(&Object->AppNvm, 0, Object->NvmBlockSize);

		Object->AppNvm.NvmVersion = SWC_IPC_APP_CONFIG_NVM_VERSION;

		(void)memcpy((void *)Rte_Pim_NvBlockNeed_Block_IPC_Config_Data_MirrorBlock(),
			   (void *)(&(Object->AppNvm)),
			   Object->NvmBlockSize);

		IPC_RestoreAppNvmConfig(Object);

		if (E_OK != Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock(NULL_PTR))
		{
			/*Clear mirror buffer*/
			(void)memset(Rte_Pim_NvBlockNeed_Block_IPC_Config_Data_MirrorBlock(), 0, Object->NvmBlockSize);

			SWC_IPC_PRINT_ERROR("App nvm mirror block update failed!");
		}
		else
		{
			SWC_IPC_PRINT_WARNING("App nvm mirror block update success!");
		}
	}
	else
	{
		SWC_IPC_PRINT_WARNING("App nvm block init success , version:%d",Object->AppNvm.NvmVersion);
	}

	Object->NvmUpdateSwitch = TRUE;
}
/**********************************************************************************************************
*Function   : IPC_E2eMsgInit                                                                              *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-16                                                                                  *
**********************************************************************************************************/
static void IPC_E2eMsgInit(SWC_IPC_AppMsgObject * Object)
{
	(void)Object;
	E2EPW_ReadInit_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2();
	E2EPW_ReadInit_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2();
	E2EPW_ReadInit_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2();
	E2EPW_ReadInit_SG_ACC6_ACC_FD2_SG_ACC6_ACC_FD2();
	E2EPW_ReadInit_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2();

	#if (defined SWC_IPC_PROJECT_TYPE_B02)
	E2EPW_WriteInit_SG_HUT_IP2_SG_HUT_IP2();
	#elif (defined SWC_IPC_PROJECT_TYPE_B03)
	E2EPW_WriteInit_SG_HUT_IP2_SG_HUT_IP2();
	E2EPW_WriteInit_SG_DMS2_DMS_FD1_SG_DMS2_DMS_FD1();
	E2EPW_WriteInit_SG_DMS3_DMS_FD1_SG_DMS3_DMS_FD1();
	E2EPW_WriteInit_SG_DMS5_DMS_FD1_SG_DMS5_DMS_FD1();
	E2EPW_WriteInit_SG_DMS6_DMS_FD1_SG_DMS6_DMS_FD1();
	#elif (defined SWC_IPC_PROJECT_TYPE_P05)
	E2EPW_WriteInit_SG_IP2_SG_IP2();
	#endif

	E2EPW_WriteInit_SG_HUT32_SG_HUT32();
}
/**********************************************************************************************************
*Function   : IPC_APPMsgPeriodicUpdate                                                                    *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-08                                                                                  *
**********************************************************************************************************/
static void IPC_AppMsgPeriodicUpdate(SWC_IPC_AppMsgObject * Object)
{
	IPC_AppAliveMonitor(Object);

	IPC_LinkTestUpdate(Object);

	IPC_ClusterSafetyRollingCounterUpdate(Object);

	IPC_ClusterTxCanSignalUpdate(Object);

	IPC_SpecialTxCanSignalOperation(Object);

	IPC_ClusterFuelAndTcDataUpdate(Object);

	IPC_ControlDTCMonitor(Object);

	IPC_RestoreDataMonitor(Object);

	IPC_BeanIDCanDataMonitor(Object);

	IPC_E2EAndSecOcSwitchStatusProcess(Object);

	IPC_SetTxCanSignalToApp(Object);

	#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P03)\
	 || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)// || (defined SWC_IPC_PROJECT_TYPE_A07)
	IPC_DriveModSwitchMonitor(Object);
	#endif
}

/**********************************************************************************************************
*Function   : IPC_AppNvmBlockPeriodicUpdate                                                               *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-08                                                                                  *
**********************************************************************************************************/
static void IPC_AppNvmBlockPeriodicUpdate(SWC_IPC_AppMsgObject * Object)
{
	NvM_RequestResultType NVMErrorStatus = NVM_REQ_OK;

	if (FALSE != Object->NvmUpdateSwitch)
	{
		if (E_OK == Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_GetErrorStatus(&NVMErrorStatus))
		{
			if (NVMErrorStatus != NVM_REQ_PENDING)
			{
				/*Avoid ipc driver cdd interrupt.*/
				Rte_Enter_ExclusiveArea();

				if (FALSE != memcmp(Rte_Pim_NvBlockNeed_Block_IPC_Config_Data_MirrorBlock(),
					                &(Object->AppNvm),
					                Object->NvmBlockSize))
				{
					(void)memcpy((void *)Rte_Pim_NvBlockNeed_Block_IPC_Config_Data_MirrorBlock(),
						   (void *)(&(Object->AppNvm)),
						   Object->NvmBlockSize);

					Rte_Exit_ExclusiveArea();

					if (E_OK != Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock(NULL_PTR))
					{
						/*Clear mirror buffer*/
						(void)memset(Rte_Pim_NvBlockNeed_Block_IPC_Config_Data_MirrorBlock(),0,Object->NvmBlockSize);

						SWC_IPC_PRINT_ERROR("App nvm mirror block update failed!");
					}
					else
					{
						SWC_IPC_PRINT_WARNING("App nvm mirror block update success!");
					}
				}
				else
				{
					Rte_Exit_ExclusiveArea();
				}
			}
		}
	}
}
/**********************************************************************************************************
*Function   : IPC_API_ControlAppNvmSwitch                                                                 *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : uint8 Switch                                                                                *
*                                                                                                         *
*Return     : uint8                                                                                       *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-03                                                                                  *
**********************************************************************************************************/
boolean IPC_API_ControlAppNvmSwitch(const boolean Switch)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	NvM_RequestResultType NvmErrorStatus = NVM_REQ_OK;
	boolean ReturnSwitch = Switch;

	if (Object->NvmUpdateSwitch != Switch)
	{
		/*On -> Off */
		if (FALSE == Switch)
		{
			if (RTE_E_OK == Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_GetErrorStatus(&NvmErrorStatus))
			{
				if (NvmErrorStatus != NVM_REQ_PENDING)
				{
					ReturnSwitch = FALSE;
					Object->NvmUpdateSwitch = FALSE;
					SWC_IPC_PRINT_WARNING("App nvm block update switch off!");
				}
				else
				{
					ReturnSwitch = TRUE;
				}
			}
			else
			{
				ReturnSwitch = TRUE;
			}

		}
		/*Off -> On */
		else
		{
			ReturnSwitch = TRUE;
			Object->NvmUpdateSwitch = TRUE;
			SWC_IPC_PRINT_WARNING("App nvm block update switch on!");
		}
	}
	else
	{
		ReturnSwitch = Object->NvmUpdateSwitch;
	}
	return ReturnSwitch;
}
/**********************************************************************************************************
*Function   : IPC_API_RestoreNvmTxCanSignal                                                               *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-15                                                                                  *
**********************************************************************************************************/
void IPC_API_RestoreNvmTxCanSignal(void)
{
	uint8 CountryFlag = 0U;
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	CountryFlag = IPC_GetCountryProcess(Object);

	if(2U == CountryFlag)
	{
		IPC_OS_RestoreTxCanSignalPhase1(Object);
		IPC_OS_RestoreTxCanSignalPhase2(Object);
	}
	else
	{
		IPC_RestoreTxCanSignalPhase1(Object);
		IPC_RestoreTxCanSignalPhase2(Object);
	}


}

/**********************************************************************************************************
*Function   : IPC_TxCanSignalInit                                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-22                                                                                  *
**********************************************************************************************************/
static void IPC_TxCanSignalInit(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[1];
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;

	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();

	if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
	{
		/* 车道辅助 : 紧急车道保持 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if (((4 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (5 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (8 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (9 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (11 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (13 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA]))
		 && (0 != Object->VehicleConfig[VCONFIG_KIND_REGIONAL]))  /* 国外 */
		{
            Data[0] = 1; /*0x1:On*/
		    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_ELKSwtReq, Data);
		}
		#endif

		/* 侧后辅助系统 : 并线辅助 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
		 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_LANE_CHANGE_ASSIST])
		  && (0 != Object->VehicleConfig[VCONFIG_KIND_REGIONAL]))
		{
            /* 国外 */
            Data[0] = 1; /*0x1:On*/
		    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_LCASwtReq, Data);
		}
		#endif

		/* 交通标志信息 : 交通标志识别 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
		 || (2 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
		 || (4 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING]))
		 && (0 != Object->VehicleConfig[VCONFIG_KIND_REGIONAL]))
		{
            /* 国外 */
            Data[0] = 1; /*0x1:On*/
		    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_TSRSwtReq, Data);
		}
		#endif

		/* 交叉路口辅助 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_AEB_JUNCTION_ASSIST])
		{
			Data[0] = 1; /*0x1:On*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_JASwtReq, Data);
		}

		/* 行人安全辅助系统 */
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		 || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
		{
			Data[0] = 1; /*0x1:On*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_PedSwtReq, Data);
		}

		/* 碰撞安全辅助系统制动 */
		if ((3 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		  || (4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		  || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
		{
			Data[0] = 1; /*0x1:On*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_VehSwtReq, Data);
		}

		/* 方向盘助力模式 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_SYSTEM])
		{
			Data[0] = 3; /*0x3:NO Hut Control*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
		}

		/* 外后视镜倒车模式 KAG*/
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]) || (5 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]))
		{
			/*get tx signal */
			IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_OrvmPosnEnaSts, Data);
			if (0 == Data[0])
			{
				Data[0] = 2;  /* 0x2:Bothsideenable */
				IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_OrvmPosnEnaSts, Data);
			}
		}

		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P03)\
 	     || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) \
 	     || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P01)// || (defined SWC_IPC_PROJECT_TYPE_A07)
		if (((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
	       && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
		  || ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
		   && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
		{
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, &Object->AppNvm.HUT_EgyRecvrySet);
		}
		#endif

		/* 主驾座椅记忆 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03)\
		 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
		 	(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
		 	(defined SWC_IPC_PROJECT_TYPE_P01)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (4 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (6 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (7 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (8 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
		{
			if ((1 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE])|| (5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE]))
			{
				/*Save signal to temp*/
				IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, &Object->ChairMemPosnSetResult);
			}
		}
		#endif

		/* 主驾驶座椅按摩设置 按摩模式 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
		{
			IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgModSet, Data);
			if (0 == Data[0])
			{
				Data[0] = 1;  /* 0x1:Wave Mode */
				IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgModSet, Data);
			}
			else
			{
				// do nothing
			}
		}
		else
		{
			Data[0] = 0;  /* 0x0:No Action */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgModSet, Data);
		}
		#endif

		/* 副驾驶座椅按摩设置 按摩模式 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
		{
			IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgModSet, Data);
			if (0 == Data[0])
			{
				Data[0] = 1;  /* 0x1:Wave Mode */
				IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgModSet, Data);
			}
			else
			{
				// do nothing
			}
		}
		else
		{
			Data[0] = 0;  /* 0x0:No Action */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgModSet, Data);
		}
		#endif

		/* 后排左侧座椅按摩设置 ZV2+ZS9 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
		{
			IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgModSet, Data);
			if (0 == Data[0])
			{
				Data[0] = 1;  /* 0x1:Wave Mode */
				IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgModSet, Data);
			}
			else
			{
				// do nothing
			}
		}
		else
		{
			Data[0] = 0;  /* 0x0:No Action */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgModSet, Data);
		}
		#endif

		/* 后排右侧座椅按摩设置 ZV3+ZS9 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
		{
			IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgModSet, Data);
			if (0 == Data[0])
			{
				Data[0] = 1;  /* 0x1:Wave Mode */
				IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgModSet, Data);
			}
			else
			{
				// do nothing
			}
		}
		else
		{
			Data[0] = 0;  /* 0x0:No Action */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgModSet, Data);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01)
		if(((6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP])) &&\
			(FALSE == Object->AppNvm.MultiColorNrFlag))
		{
			Object->AppNvm.MultiColorNrFlag = TRUE;
			/* 面发光氛围灯流水灯设置 */
			Data[0] = 0;  /* 0X0：OFF */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_ALCMFloSwt, Data);
			/* 面发光氛围灯颜色选择 */
			Data[0] = 2;  /* 0X2：极光白 */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet_OLE, Data);
			/* 面发光氛围灯多色彩静态模式 */
			Data[0] = 0;  /* 0X2：OFF */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt_OLE, Data);
			/* 面发光氛围灯多色彩动态模式 */
			Data[0] = 0;  /* 0x0:DynModOFF */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet_OLE, Data);
			/* 面发光氛围灯呼吸灯设置 */
			Data[0] = 0;  /* 0X0：OFF */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt_OLE, Data);
			/* 面发光氛围灯流水灯设置 */
			Data[0] = 3;  /* 0x3:极光白 */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr1, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr2, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr3, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr4, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr5, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr6, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr7, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr8, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr9, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr10, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr11, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr12, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr13, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr14, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr15, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr16, Data);
		}
		#endif

		/* 储运模式 : TranPMode_Req*/
		Data[0] = Object->AppNvm.u8TranPMode_Sts;
		IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_TranPMode_Req, Data);

		/*智能启停*/
		/* Add for CR-536. If there is a new project that does not have this signal involved in compilation, then the project macro needs to be added */
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_SMART_START_STOP_SWITCH_MEMORY_SETTING])
			|| (2 == Object->VehicleConfig[VCONFIG_KIND_SMART_START_STOP_SWITCH_MEMORY_SETTING]))
		{
			// nothing to do
		}
		else
		{
			Data[0] = 0; /*0x0:Off*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SSSSet_HUT, Data);
		}
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Vehicle control can signal wake up init phase read vehicle config faild!");
	}

	SWC_IPC_PRINT_INFO("Vehicle control can signal wake up init phase work start!");
}


/**********************************************************************************************************
*Function   : IPC_OS_TxCanSignalInit                                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-22                                                                                  *
**********************************************************************************************************/
static void IPC_OS_TxCanSignalInit(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[1];
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;

	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();

	if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
	{
		/* 车道辅助 : 紧急车道保持 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if (((4 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (5 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (8 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (9 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (11 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (13 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA]))
		 && (0 != Object->VehicleConfig[VCONFIG_KIND_REGIONAL]))  /* 国外 */
		{
            Data[0] = 1; /*0x1:On*/
		    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_ELKSwtReq, Data);
		}
		#endif

		/* 侧后辅助系统 : 并线辅助 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
		 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_LANE_CHANGE_ASSIST])
		  && (0 != Object->VehicleConfig[VCONFIG_KIND_REGIONAL]))
		{
            /* 国外 */
            Data[0] = 1; /*0x1:On*/
		    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_LCASwtReq, Data);
		}
		#endif

		/* 交通标志信息 : 交通标志识别 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
		 || (2 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
		 || (4 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING]))
		 && (0 != Object->VehicleConfig[VCONFIG_KIND_REGIONAL]))
		{
            /* 国外 */
            Data[0] = 1; /*0x1:On*/
		    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_TSRSwtReq, Data);
		}
		#endif

		/* 交叉路口辅助 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_AEB_JUNCTION_ASSIST])
		{
			Data[0] = 1; /*0x1:On*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_JASwtReq, Data);
		}

		/* 行人安全辅助系统 */
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		 || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
		{
			Data[0] = 1; /*0x1:On*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_PedSwtReq, Data);
		}

		/* 碰撞安全辅助系统制动 */
		if ((3 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		  || (4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		  || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
		{
			Data[0] = 1; /*0x1:On*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_VehSwtReq, Data);
		}

		/* 方向盘助力模式 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_SYSTEM])
		{
			Data[0] = 3; /*0x3:NO Hut Control*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
		}

		/* 外后视镜倒车模式 KAG*/
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]) || (5 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]))
		{
			/*get tx signal */
			IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_OrvmPosnEnaSts, Data);
			if (0 == Data[0])
			{
				Data[0] = 2;  /* 0x2:Bothsideenable */
				IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_OrvmPosnEnaSts, Data);
			}
		}

		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P03)\
 	     || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) \
 	     || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P01)// || (defined SWC_IPC_PROJECT_TYPE_A07)
		if (((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
	       && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
		  || ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
		   && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
		{
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, &Object->AppNvm.HUT_EgyRecvrySet);
		}
		#endif

		/* 主驾座椅记忆 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03)\
		 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
		 	(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
		 	(defined SWC_IPC_PROJECT_TYPE_P01)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (4 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (6 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (7 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (8 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
		{
			if ((1 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE])|| (5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE]))
			{
				/*Save signal to temp*/
				IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, &Object->ChairMemPosnSetResult);
			}
		}
		#endif

		/* 主驾驶座椅按摩设置 按摩模式 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
		{
			IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgModSet, Data);
			if (0 == Data[0])
			{
				Data[0] = 1;  /* 0x1:Wave Mode */
				IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgModSet, Data);
			}
			else
			{
				// do nothing
			}
		}
		else
		{
			Data[0] = 0;  /* 0x0:No Action */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgModSet, Data);
		}
		#endif

		/* 副驾驶座椅按摩设置 按摩模式 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
		{
			IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgModSet, Data);
			if (0 == Data[0])
			{
				Data[0] = 1;  /* 0x1:Wave Mode */
				IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgModSet, Data);
			}
			else
			{
				// do nothing
			}
		}
		else
		{
			Data[0] = 0;  /* 0x0:No Action */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgModSet, Data);
		}
		#endif

		/* 后排左侧座椅按摩设置 ZV2+ZS9 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
		{
			IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgModSet, Data);
			if (0 == Data[0])
			{
				Data[0] = 1;  /* 0x1:Wave Mode */
				IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgModSet, Data);
			}
			else
			{
				// do nothing
			}
		}
		else
		{
			Data[0] = 0;  /* 0x0:No Action */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgModSet, Data);
		}
		#endif

		/* 后排右侧座椅按摩设置 ZV3+ZS9 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
		{
			IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgModSet, Data);
			if (0 == Data[0])
			{
				Data[0] = 1;  /* 0x1:Wave Mode */
				IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgModSet, Data);
			}
			else
			{
				// do nothing
			}
		}
		else
		{
			Data[0] = 0;  /* 0x0:No Action */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgModSet, Data);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01)
		if(((6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP])) &&\
			(FALSE == Object->AppNvm.MultiColorNrFlag))
		{
			Object->AppNvm.MultiColorNrFlag = TRUE;
			/* 面发光氛围灯流水灯设置 */
			Data[0] = 0;  /* 0X0：OFF */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_ALCMFloSwt, Data);
			/* 面发光氛围灯颜色选择 */
			Data[0] = 2;  /* 0X2：极光白 */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet_OLE, Data);
			/* 面发光氛围灯多色彩静态模式 */
			Data[0] = 0;  /* 0X2：OFF */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt_OLE, Data);
			/* 面发光氛围灯多色彩动态模式 */
			Data[0] = 0;  /* 0x0:DynModOFF */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet_OLE, Data);
			/* 面发光氛围灯呼吸灯设置 */
			Data[0] = 0;  /* 0X0：OFF */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt_OLE, Data);
			/* 面发光氛围灯流水灯设置 */
			Data[0] = 3;  /* 0x3:极光白 */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr1, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr2, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr3, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr4, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr5, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr6, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr7, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr8, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr9, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr10, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr11, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr12, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr13, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr14, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr15, Data);
			Data[0] = 0;  /* 0x0:No command */
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr16, Data);
		}
		#endif

		/* 储运模式 : TranPMode_Req*/
		Data[0] = Object->AppNvm.u8TranPMode_Sts;
		IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_TranPMode_Req, Data);

		/*智能启停*/
		/* Add for CR-536. If there is a new project that does not have this signal involved in compilation, then the project macro needs to be added */
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_SMART_START_STOP_SWITCH_MEMORY_SETTING])
			|| (2 == Object->VehicleConfig[VCONFIG_KIND_SMART_START_STOP_SWITCH_MEMORY_SETTING]))
		{
			// nothing to do
		}
		else
		{
			Data[0] = 0; /*0x0:Off*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SSSSet_HUT, Data);
		}
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Vehicle control can signal wake up init phase read vehicle config faild!");
	}

	SWC_IPC_PRINT_INFO("Vehicle control can signal wake up init phase work start!");
}

/**********************************************************************************************************
*Function   : IPC_RestoreWisdomCruise                                                                     *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :                                                                                             *
*                                                                                                         *
*Date       : 2021-08-20                                                                                  *
**********************************************************************************************************/
static void IPC_RestoreWisdomCruise(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[1];
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;

	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();
	if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
	{
		/* 智慧巡航系统 : 拨杆变道辅助 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02)  || (defined SWC_IPC_PROJECT_TYPE_P01)
        if ((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			((1 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]) || \
			(2 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER])))
        {
            Data[0] = 1; /*0x1:ON*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SwtReq, Data);
        }
        else
        {
            Data[0] = 0; /*0x0:Off*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SwtReq, Data);
        }
		#endif

		/* 智慧巡航系统 : 自动变道辅助 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
        if (0 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST])
        {
            Data[0] = 0; /*0x0:Off*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALC_SwtReq, Data);
        }
		else if((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			((1 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]) || \
			(2 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER])))
		{
			Data[0] = 0; /*0x0:Off*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALC_SwtReq, Data);
		}
        else
        {
            Data[0] = 0; /*0x0:Off*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALC_SwtReq, Data);
        }
		#endif

		/* 智慧巡航系统 : 自动变道辅助灵敏度 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P01)
        if (0 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST])
        {
			Data[0] = 0; /*0x0:Normal*/
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SnvtySet, Data);
        }
		else if((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			(1 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]))
		{
			Data[0] = 0; /*0x0:Normal*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SnvtySet, Data);
		}
        else
        {
			Data[0] = 0; /*0x0:Normal*/
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SnvtySet, Data);
        }
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P01)
		/* 智慧巡航系统：自动导航辅助 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_NAVIGATION_ON_HIGHWAYPILOT])
		{
			Data[0] = 0;  /* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NOH_Swt_Req, Data);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03)
		/* 智慧巡航系统：意图确认 */
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			(2 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]))
		{
			Data[0] = 0;  /* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LaneChngCfmSwt, Data);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) //|| (defined SWC_IPC_PROJECT_TYPE_P01)
		/* 智慧巡航系统：智能调速 */
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			(2 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]))
		{
			Data[0] = 0;  /* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoSpdSetSwt, Data);
		}
		#endif
	}
	else
	{
		/* 智慧巡航系统 : 拨杆变道辅助 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
        Data[0] = 0; /*0x0:Off*/
		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SwtReq, Data);
		#endif

		/* 智慧巡航系统 : 自动变道辅助 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
        Data[0] = 0; /*0x0:Off*/
		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALC_SwtReq, Data);
		#endif

		/* 智慧巡航系统 : 自动变道辅助灵敏度 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P01)
		Data[0] = 0; /*0x0:Normal*/
        IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SnvtySet, Data);
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P01)
		/* 智慧巡航系统：自动导航辅助 */
		Data[0] = 0;  /* 0x0:OFF */
		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NOH_Swt_Req, Data);
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03)
		/* 智慧巡航系统：意图确认 */
		Data[0] = 0;  /* 0x0:OFF */
		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LaneChngCfmSwt, Data);
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) //|| (defined SWC_IPC_PROJECT_TYPE_P01)
		/* 智慧巡航系统：智能调速 */
		Data[0] = 0;  /* 0x0:OFF */
		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoSpdSetSwt, Data);
		#endif
	}

	return ;
}

/**********************************************************************************************************
*Function   : IPC_OS_RestoreWisdomCruise                                                                     *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :                                                                                             *
*                                                                                                         *
*Date       : 2021-08-20                                                                                  *
**********************************************************************************************************/
static void IPC_OS_RestoreWisdomCruise(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[1];
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;

	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();
	if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
	{
		/* 智慧巡航系统 : 拨杆变道辅助 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02)  || (defined SWC_IPC_PROJECT_TYPE_P01)
        if ((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			((1 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]) || \
			(2 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER])))
        {
            Data[0] = 1; /*0x1:ON*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SwtReq, Data);
        }
        else
        {
            Data[0] = 0; /*0x0:Off*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SwtReq, Data);
        }
		#endif

		/* 智慧巡航系统 : 自动变道辅助 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
        if (0 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST])
        {
            Data[0] = 0; /*0x0:Off*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALC_SwtReq, Data);
        }
		else if((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			((1 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]) || \
			(2 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER])))
		{
			Data[0] = 0; /*0x0:Off*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALC_SwtReq, Data);
		}
        else
        {
            Data[0] = 0; /*0x0:Off*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALC_SwtReq, Data);
        }
		#endif

		/* 智慧巡航系统 : 自动变道辅助灵敏度 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P01)
        if (0 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST])
        {
			Data[0] = 0; /*0x0:Normal*/
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SnvtySet, Data);
        }
		else if((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			(1 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]))
		{
			Data[0] = 0; /*0x0:Normal*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SnvtySet, Data);
		}
        else
        {
			Data[0] = 0; /*0x0:Normal*/
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SnvtySet, Data);
        }
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P01)
		/* 智慧巡航系统：自动导航辅助 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_NAVIGATION_ON_HIGHWAYPILOT])
		{
			Data[0] = 0;  /* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NOH_Swt_Req, Data);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) //|| (defined SWC_IPC_PROJECT_TYPE_P01)
		/* 智慧巡航系统：意图确认 */
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			(2 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]))
		{
			Data[0] = 0;  /* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LaneChngCfmSwt, Data);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) //|| (defined SWC_IPC_PROJECT_TYPE_P01)
		/* 智慧巡航系统：智能调速 */
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			(2 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]))
		{
			Data[0] = 0;  /* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoSpdSetSwt, Data);
		}
		#endif
	}
	else
	{
		/* 智慧巡航系统 : 拨杆变道辅助 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
        Data[0] = 0; /*0x0:Off*/
		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SwtReq, Data);
		#endif

		/* 智慧巡航系统 : 自动变道辅助 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
        Data[0] = 0; /*0x0:Off*/
		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALC_SwtReq, Data);
		#endif

		/* 智慧巡航系统 : 自动变道辅助灵敏度 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P01)
		Data[0] = 0; /*0x0:Normal*/
        IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SnvtySet, Data);
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P01)
		/* 智慧巡航系统：自动导航辅助 */
		Data[0] = 0;  /* 0x0:OFF */
		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NOH_Swt_Req, Data);
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) //|| (defined SWC_IPC_PROJECT_TYPE_P01)
		/* 智慧巡航系统：意图确认 */
		Data[0] = 0;  /* 0x0:OFF */
		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LaneChngCfmSwt, Data);
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) //|| (defined SWC_IPC_PROJECT_TYPE_P01)
		/* 智慧巡航系统：智能调速 */
		Data[0] = 0;  /* 0x0:OFF */
		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoSpdSetSwt, Data);
		#endif
	}

	return ;
}

/**********************************************************************************************************
*Function   : IPC_RestoreTxCanSignalPhase1                                                                *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-01                                                                                  *
**********************************************************************************************************/
static void IPC_RestoreTxCanSignalPhase1(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[1];
	//VconfigKind_Allbuffers Object->VehicleConfig;
	(void)Object;

	if (E_OK == Rte_Read_Vconfig_GetKindBuffers_AllKinds(Object->VehicleConfig))
    {
	    if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
    	{
    		(void)SWC_IPC_PRINT_DEBUG("%s", __FUNCTION__);
    		/*智能启停*/
    		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_D01) ||\
    			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
    			(defined SWC_IPC_PROJECT_TYPE_D03)
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_SMART_START_STOP_SWITCH_MEMORY_SETTING])
    		 || (2 == Object->VehicleConfig[VCONFIG_KIND_SMART_START_STOP_SWITCH_MEMORY_SETTING]))
    		{
    			Data[0] = 1; /*0x1:On*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SSSSet_HUT, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SSSSet_HUT, Data);
    		}
    		#endif

    		/* 疲劳驾驶 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03) || \
				(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_P02)
    	    if (1 == Object->VehicleConfig[VCONFIG_KIND_DROWSINESS_WARNING_SYSTEM])
    		{
    			Data[0] = 1;  /*0x1:On*/
    	        IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDrowsnsDetnSet, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDrowsnsDetnSet, Data);
    		}
    		#endif

    		/* 驾驶模式选择 */
    		/* 燃油(DAA) VCONFIG_KIND_FUEL */
    		/* 电机位置(CBA) VCONFIG_KIND_ELECTROMOTOR_POSITION */
    		/* 驾驶模式信号可选(ZF3) VCONFIG_KIND_DRIVING_MODE_SIGNAL_SELECT */
    		/* 驾驶模式配置字(ZA5) VCONFIG_KIND_DRIVING_MODE_OPTIONAL */
    		/* 驾驶模式配置字(ZG2) 与ZA5为互斥关系 若同时配置为真 取ZG2配置 VCONFIG_KIND_DRIVING_MODE_2 */
    		/* 驾驶模式配置字(ZQ3) VCONFIG_KIND_DRIVING_MODE_3 */
    		/* 驾驶模式记忆配置字(ZG3) VCONFIG_KIND_MEMORY_OF_DRIVING_MODE */

    		/* ESP主控的驾驶模式 */
    		if ((0 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    		||  (1 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    		|| ((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    		&&  (1 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
    		{
    			/* HUT驾驶模式软开关(中控屏) */
    			if (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_SIGNAL_SELECT])
    			{
    				#ifdef SWC_IPC_PROJECT_TYPE_B02
    				{
    					/* 驾驶模式18 ZG220 */
    					/* 驾驶模式36 ZQ336 */
    					/* 驾驶模式33 ZQ325 */
    					if ((3 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_2])
    					 || (6 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_3])
    					 || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_3]))
    					{
    						Data[0] = 0; /*0x0:Standard/Normal*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    					}
    					else
    					{
    						Data[0] = 0; /*0x0:Standard/Normal*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    					}
    				}
    				#elif defined SWC_IPC_PROJECT_TYPE_B03
    				{
    					/* 驾驶模式2  ZA520 */
    					/* 驾驶模式39 ZQ339 */
    					/* 驾驶模式37 ZQ337 */
    					if ((7 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_3])
    					 || (9 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_3])
    					 || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_OPTIONAL]))
    					{
    						Data[0] = 0; /*0x0:Standard/Normal*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    					}
    					else
    					{
    						Data[0] = 0; /*0x0:Standard/Normal*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    					}
    				}
    				#elif defined SWC_IPC_PROJECT_TYPE_A07
    				{
    					/* 驾驶模式2  ZA520 */
    					/* 驾驶模式39 ZQ339 */
    					/* 驾驶模式37 ZQ337 */
    					if (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_OPTIONAL])
    					{
    						Data[0] = 0; /*0x0:Standard/Normal*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    					}
    					else
    					{
    						Data[0] = 0; /*0x0:Standard/Normal*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    					}
    				}
    				#elif defined SWC_IPC_PROJECT_TYPE_P05
    				{
    					/* 驾驶模式25 ZG275 */
    					/* DO NOTHING */
    				}
    				#endif
    			}
    			else
    			{
    				#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    				Data[0] = 0; /*0x0:Standard/Normal*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    				#endif
    			}
    		}
    		else if (((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    		       && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
    			  || ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    			   && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
    		{
    			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    			Data[0] = 0; /*0x0:Standard/Normal*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    			#endif

    			/* HCU主控的驾驶模式(无驾驶模式记忆开关) */
    			if (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_SIGNAL_SELECT])
    			{
    				/* HUT驾驶模式软开关(中控屏) */
    				#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_D02)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    				{
    					if (0 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_2])
    					{
    						Data[0] = 0; /*0x0:Auto/Normal*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_DrvModReq, Data);
    					}
    					else
    					{
    						Data[0] = 0; /*0x0:Auto/Normal*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_DrvModReq, Data);
    					}
    				}
    				#endif
    			}
    			else
    			{
    				#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_D02)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    				Data[0] = 0; /*0x0:Auto/Normal*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_DrvModReq, Data);
    				#endif
    			}
    		}
    		else
    		{
    			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    			Data[0] = 0; /*0x0:Standard/Normal*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    			#endif

    			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_D02)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    			Data[0] = 0; /*0x0:Standard/Normal*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_DrvModReq, Data);
    			#endif

    			SWC_IPC_PRINT_WARNING("No correct configuration for drive mode were detected");
    		}

    		/* 方向盘助力模式 */
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_SYSTEM])
    		{
    			Data[0] = 0; /*0x0:Comfort Mode*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 3; /*0x3:NO Hut Control*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    		}

    		/* 无线充电开关 */
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_WIRELESS_POWER_CHARGER]) ||
    			(2 == Object->VehicleConfig[VCONFIG_KIND_WIRELESS_POWER_CHARGER]) ||
				(3 == Object->VehicleConfig[VCONFIG_KIND_WIRELESS_POWER_CHARGER]) ||
				(4 == Object->VehicleConfig[VCONFIG_KIND_WIRELESS_POWER_CHARGER]) ||
				(5 == Object->VehicleConfig[VCONFIG_KIND_WIRELESS_POWER_CHARGER]))
    		{
    			Data[0] = 3; /*0x3:Open*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WPC_SwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 2; /*0x2:Close*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WPC_SwtReq, Data);
    		}

    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    		 || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		if(2 == Object->VehicleConfig[VCONFIG_KIND_WIRELESS_POWER_CHARGER])
    		{
    			Data[0] = 3; /*0x3:Open*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RWPC_SwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 2; /*0x2:Close*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RWPC_SwtReq, Data);
    		}
    		#endif

    		/* WHUD */
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_HEAD_UP_DISPLAY])
    		{
    			Data[0] = 2; /*0x2:On*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_SwtReq, Data);
    			Data[0] = SWC_WHUD_DEFAULT_BACKLIGHT_LEVEL; /*0x5:亮度调节*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_BrightnessLvlSwt, Data);
    			Data[0] = SWC_WHUD_DEFAULT_HIGHT_LEVEL; /*0xB:高度调节*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_HeightLvlSwt, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:No Action*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_SwtReq, Data);
    			Data[0] = 0; /*0x0:No action*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_BrightnessLvlSwt, Data);
    			Data[0] = 0; /*0x0:No action*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_HeightLvlSwt, Data);
    		}

    		/* 主驾驶座椅按摩设置 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		if (((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]))
		     && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgLvlSet, Data);
    			Data[0] = 1; /*0x1:Wave Mode*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgModSet, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgLvlSet, Data);
    			Data[0] = 0; /*0x0:No Action*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgModSet, Data);
    		}
    		#endif

    		/* 主驾驶座椅腰托设置 */
    		#if 0 //SWC_IPC_PROJECT_TYPE_B03
    	    if (((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WAIST_SUPPORTER]) ||
                (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WAIST_SUPPORTER])) &&
                (2 == Object->VehicleConfig[VCONFIG_KIND_WAIST_SUPPORTER_SWITCH_TYPE]))
    	    {
    			Data[0] = 0; /*0x0:NO Action*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatSupportPosnSwt, Data);
    	    }
    	    else
    	    {
    			Data[0] = 0; /*0x0:NO Action*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatSupportPosnSwt, Data);
    	    }
    		#endif

    		/* 主驾座椅记忆 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03)\
    		 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
    		 	(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		if (((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (4 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (6 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (7 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (8 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
    		  && ((1 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE])
			  || (5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE])))
    		{
    			Data[0] = 0; /*0x0:No Command*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSet, Data);
    			Data[0] = 0; /*0x0:FactoryDefault*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, Data);
    		}
    		else
    	  	{
    			Data[0] = 0; /*0x0:No Command*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSet, Data);
    			Data[0] = 0; /*0x0:FactoryDefault*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, Data);
    	  	}
    		#endif

    		/* 座椅非个性化设置 PAA ZM2*/
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03)\
    		 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
    		 	(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		if (((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (4 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (6 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (7 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (8 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
    		  && ((4 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE])
    		   || (5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE])))
    		{
    			Data[0] = 0; /*0x0:No Command*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetSwt, Data);
    		}
    		else
    	  	{
    			Data[0] = 0; /*0x0:No Command*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetSwt, Data);
    	  	}
    		#endif

    		/* 后背门感应开启 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)\
    			|| (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)
    		if (3 == Object->VehicleConfig[VCONFIG_KIND_RR_DOOR_OPENING])/*3:感应式电动后背门*/
    		{
    			Data[0] = 1; /*0x1:On*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HFASwtSts, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HFASwtSts, Data);
    		}
    		#endif

    		/* 后背门开启高度 */
    		//ZY0 Byte 100  bit 1-0
    		#if (defined SWC_IPC_PROJECT_TYPE_A07)
    		/*1：有后背门高度调节虚拟开关*/
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_TAILGATE_ADJ_VIRTUAL_SW])
    		{
    			Data[0] = 1; /*0x1:level1*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PLG_HeightSet, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:user define*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PLG_HeightSet, Data);
    		}
    		#endif

    		/* 碰撞安全辅助系统制动 */
    		if ((3 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
    		  || (4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
    		  || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
    		{
    			Data[0] = 1; /*0x1:On*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_VehSwtReq, Data);

    			/* 紧急转向辅助 */
    			if (1 == Object->VehicleConfig[VCONFIG_KIND_EMERGENCY__STEERING_SUPPORT])
    			{
    				Data[0] = 0; /*0x0:Off*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_VehSwtReq, Data);
    			}
    			else
    			{
    				Data[0] = 0; /*0x0:Off*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_VehSwtReq, Data);
    			}
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_VehSwtReq, Data);
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_VehSwtReq, Data);
    		}

    		/* 交叉路口辅助 */
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_AEB_JUNCTION_ASSIST])
    		{
    			Data[0] = 1; /*0x1:On*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_JASwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_JASwtReq, Data);
    		}

    		/* 前横穿侧向警告 */
			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK])
    		 || (2 == Object->VehicleConfig[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK]))
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCTASwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCTASwtReq, Data);
    		}
			#endif

    		/* 前横穿侧向制动 */
			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		if (2 == Object->VehicleConfig[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK])
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCTABrkSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCTABrkSwtReq, Data);
    		}
			#endif

    		/*前碰撞预警灵敏度*/
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
    		 || (4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
    		 || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
    		{
    			Data[0] = 0; /*0x0:Normal*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCW_SnvtySet, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Normal*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCW_SnvtySet, Data);
    		}

    		/* Automatic emergency steering */
    		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    		 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_AUTO_EVASIVE_STEERING])
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AESSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AESSwtReq, Data);
    		}
    		#endif

    		/* 车道辅助功能 */
    		if ((1 <= Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 && (13 >= Object->VehicleConfig[VCONFIG_KIND_LDW_LKA]))
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LSSSwtReq, Data);

    			/* 预警灵敏度 */
    			Data[0] = 0; /*0x0:Normal*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IFC_SnvtySet, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LSSSwtReq, Data);

    			Data[0] = 0; /*0x0:Normal*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IFC_SnvtySet, Data);
    		}

    		/* 车道辅助 : 预警辅助 */
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (2 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
			 || (4 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (7 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (8 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (9 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (10 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (11 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA]))
    		{
    			Data[0] = 1; /*0x0:On*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LDWSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LDWSwtReq, Data);
    		}

    		/* 车道辅助 : 保持辅助 */
    		if ((2 <= Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 && (13 >= Object->VehicleConfig[VCONFIG_KIND_LDW_LKA]))
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LKASwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LKASwtReq, Data);
    		}

    		#if 0
    		/* 车道辅助 : 居中辅助 */
    		if ((3 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (4 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (5 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (6 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (7 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (8 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA]))
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCKSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCKSwtReq, Data);
    		}
    		#endif

    		/* 车道辅助 : 紧急车道保持 */
    		if ((4 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (5 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (8 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
			 || (9 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
			 || (11 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
			 || (13 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA]))
    		{
                if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
                {
                    /* 国内 */
                    Data[0] = 0; /*0x0:Off*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ELKSwtReq, Data);
                }
                else
                {
                    /* 国外 */
    				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
                    Data[0] = 1; /*0x1:On*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ELKSwtReq, Data);
    				#endif
                }
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ELKSwtReq, Data);
    		}

    		/* 车道辅助 : 智慧躲闪 */
    		if ((7 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (8 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
			 || (10 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
			 || (11 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA]))
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IntelligentEvaSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IntelligentEvaSwtReq, Data);
    		}

    		/* 车道辅助 : 预警方式 */
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_HAPTIC_REMINDER_OF_ENHANCED_ASSIET_SYSTEMS])
    		{
    			Data[0] = 0; /*0x0:Voice*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LSSWarnFormSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Voice*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LSSWarnFormSwtReq, Data);
    		}

    		/* 侧后辅助系统 : 并线辅助 */
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_LANE_CHANGE_ASSIST])
    		{
                if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
                {
                    /* 国内 */
                    Data[0] = 0; /*0x0:Off*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCASwtReq, Data);
                }
                else
                {
                    /* 国外 */
    				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
                    Data[0] = 1; /*0x1:On*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCASwtReq, Data);
    				#endif
                }
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCASwtReq, Data);
    		}

    		/* 侧后辅助系统 :       开门预警 */
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_DR_OPEN_WARNING])
    		{
                if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
                {
                    /* 国内 */
                    Data[0] = 0; /*0x0:Off*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DOWSwtReq, Data);
                }
                else
                {
                    /* 国外 */
    				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
                    Data[0] = 1; /*0x1:On*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DOWSwtReq, Data);
    				#endif
                }
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DOWSwtReq, Data);
    		}

    		/* 侧后辅助系统 :       后碰撞预警 */
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_REAR_COLLISION_WARNING])
    		{
                if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
                {
                    /* 国内 */
                    Data[0] = 0; /*0x0:Off*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCWSwtReq, Data);
                }
                else
                {
                    /* 国外 */
    				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
                    Data[0] = 1; /*0x1:On*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCWSwtReq, Data);
    				#endif
                }
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCWSwtReq, Data);
    		}

    		/* 侧后辅助系统 : 倒车侧向警告 */
    		if ((2 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA])
             || (4 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA]))
    		{
    			if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
                {
                    /* 国内 */
                    Data[0] = 0; /*0x0:Off*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTASwtReq, Data);
                }
                else
                {
                    /* 国外 */
    				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
                    Data[0] = 1; /*0x1:On*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTASwtReq, Data);
    				#endif
                }
    		}
            else
            {
                Data[0] = 0; /*0x0:Off*/
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTASwtReq, Data);
            }

    		/* 侧后辅助系统 : 倒车侧向制动 */
    		if (4 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA])
    	 	{
                if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
                {
                    /* 国内 */
                    Data[0] = 0; /*0x0:Off*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTABrkSwtReq, Data);
                }
                else
                {
                    /* 国外 */
    				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
                    Data[0] = 1; /*0x1:On*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTABrkSwtReq, Data);
    				#endif
                }
    	 	}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTABrkSwtReq, Data);
    		}

    		/* 交通标志信息 : 交通标志识别 */
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
    		 || (2 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
    		 || (4 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING]))
    		{
                if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
                {
                    /* 国内 */
                    Data[0] = 0; /*0x0:Off*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSRSwtReq, Data);
                }
                else
                {
                    /* 国外 */
    				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
                    Data[0] = 1; /*0x1:On*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSRSwtReq, Data);
    				#endif
                }
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSRSwtReq, Data);
    		}

    		/* 交通标志信息 : 超速报警 */
    		if ((2 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING]))
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSRWarnSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSRWarnSwtReq, Data);
    		}

    		/* 交通标志信息 : 巡航车速限制 */
    		if ((3 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
    		 || (4 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING]))
    		{
                Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ISLSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ISLSwtReq, Data);
    		}

    		/* 交通标志信息 : 超速报警灵敏度 */
    		if ((2 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING]))
    		{
    			Data[0] = 0x0F; /*0x0:0km/h*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSR_SnvtySet, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSR_SnvtySet, Data);
    		}

			#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02)
			/* 交通标志信息 : 导航降速 */
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_NAVIGATION_SLOWDOWN])
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NavDecSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NavDecSwtReq, Data);
    		}
			#endif

    		/* 灯光控制 : 照我回家延时时间设置 */
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_HEAD_LAMP_AUTO_OFF])
    		{
    			Data[0] = 1; /*0x1:30seconds*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FolwMeHomeDlyTimSet, Data);
    		}
    		else
            {
                Data[0] = 0; /*0x0:0seconds*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FolwMeHomeDlyTimSet, Data);
            }

    		/* 灯光控制 : 运动模式灯光设置 */
    		// #if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		//  || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_D03)
			#if 0
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_SPORTS_MODE_LIGHTING_PROMPT_S_REPEATER])
    		{
    			Data[0] = 1; /*0x1:Flashing&Light*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SportModLightSet, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:OFF*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SportModLightSet, Data);
    		}
    		#endif

    		/* 泊车控制 : 前向泊车辅助系统功能 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
				(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		{
    			if (((3 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    			 || (4 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    			 || (5 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		     || (6 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
				 || (7 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
    		     || (0 != Object->VehicleConfig[VCONFIG_KIND_FRONT_SENSOR]))
    			{
    				/* HAP ECU PAS ECU */
    				/* HAP_FD3 CANFD 0x298, High priority */
    				/* FPAS1 CAN 0x26D */
    				if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_HAP_FD3, SWC_IPC_NULL))
    				{
    					#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P03)
    					IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FPAS_AutoModSts, Data);
    					#else
    					IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FPAS_AutoModSts_0x298 , Data);
    					#endif
    					/*Target: On*/
    					if (0 == Data[0]) /*0x0:Off*/
    					{
    						Data[0] = 1; /*0x1:Request*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FPAS_AutoModSwt, Data);
    					}
    				}
    				#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    				else if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_FPAS1, SWC_IPC_NULL))
    				{
    					IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FPAS_AutoModSts_0x26D , Data);
    					/*Target: On*/
    					if (0 == Data[0]) /*0x0:Off*/
    					{
    						Data[0] = 1; /*0x1:Request*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FPAS_AutoModSwt, Data);
    					}
    				}
    				#endif
    				else
    				{
    					Data[0] = 0; /*0x0:No Request*/
    					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FPAS_AutoModSwt, Data);
    				}
    			}
    			else
    			{
    				Data[0] = 0; /*0x0:No Request*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FPAS_AutoModSwt, Data);
    			}
    		}
    		#endif

    		/* 泊车控制 : 自动紧急制动系统功能 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
				(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
				(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		if (((3 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (4 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (5 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    	     || (6 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
			 || (7 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
    	     || (0 != Object->VehicleConfig[VCONFIG_KIND_REAR_PAS_SENSOR]))
    		{
    			/* HAP ECU */
    			/* HAP_FD3 CANFD 0x298, High priority */
    			/* RPAS1 CAN 0x26E */
    			if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_HAP_FD3, SWC_IPC_NULL))
    			{
    				#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P03)\
    				 || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
					 	(defined SWC_IPC_PROJECT_TYPE_P02)
    				IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MEB_EnableSts, Data);
    				#else
    				IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MEB_EnableSts_0x298, Data);
    				#endif
    				if (0 == Data[0])
    				{
    					Data[0] = 1; /*0x1:Request*/
    					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MEBSwtSet, Data);
    				}
    			}
    			#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    			else if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_RPAS1, SWC_IPC_NULL))
    			{
    				IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MEB_EnableSts_0x26E , Data);
    				if (0 == Data[0])
    				{
    					Data[0] = 1; /*0x1:Request*/
    					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MEBSwtSet, Data);
    				}
    			}
    			#endif
    			else
    			{
    				Data[0] = 0; /*0x0:No Request*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MEBSwtSet, Data);
    			}
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:No Request*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MEBSwtSet, Data);
    		}
    		#endif

    		/* 360环视 : 侧翼保护功能 */
    		if ((3 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (4 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (5 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    	     || (6 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
			 || (7 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
    		{
    			/*HAP ECU*/
    			if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_HAP_FD3,SWC_IPC_NULL))
    			{
					#if (defined SWC_IPC_PROJECT_TYPE_A07)
					IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SDWActiveSts_0x298, Data);
					#else
    				IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SDWActiveSts, Data);
					#endif
    				if (0 == Data[0])
    				{
    					Data[0] = 1; /*0x1:Request*/
    					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SDWSwtSet, Data);
    				}
    			}
    		}
    		else
    	 	{
    			Data[0] = 0; /*0x0:No Request*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SDWSwtSet, Data);
    	 	}

    		/* 360环视 : 自动转向 */
    		if ((3 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (4 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (5 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (6 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
			 || (7 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (0 != Object->VehicleConfig[VCONFIG_KIND_OMNIVIEW_SYSTEM]))
    		{
    			/*HAP ECU*/
    			if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_HAP_FD2,SWC_IPC_NULL))
    			{
    				IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoAVMSwtSet_Sts, Data);
    				if (0 == Data[0])
    				{
    					Data[0] = 1; /*0x1:Request*/
    					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoAVMSwSet_Cmd, Data);
    				}
    			}
    		}
    		else
    	 	{
    			Data[0] = 0; /*0x0:No Request*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoAVMSwSet_Cmd, Data);
    	 	}

    		/* 360环视 */
    		if ((0 != Object->VehicleConfig[VCONFIG_KIND_OMNIVIEW_SYSTEM])
    		|| (0 != Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
    		{
    			/* 360环视 : 环视退出车速值设置 */
    			Data[0] = 1; /*0x1:15km/h*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PASExitSpdSwt, Data);

    			#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || \
				(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    			/* 360环视 : 道路标定 */
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LaneCalActvtCmd, Data);

    			/* 360环视 : 恢复出厂标定 */
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SwToFieldCalRstCmd, Data);
    			#endif

    			/* 360环视 : 手动开启环视 */
    			Data[0] = 1; /*0x1:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PASSwtReq_VR, Data);
    		}
    		else
            {
            	/* 360环视 : 环视退出车速值设置 */
                Data[0] = 0; /*0x0:No command*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PASExitSpdSwt, Data);

    			#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || \
				(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    			/* 360环视 : 道路标定 */
                Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LaneCalActvtCmd, Data);

    			/* 360环视 : 恢复出厂标定 */
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SwToFieldCalRstCmd, Data);
    			#endif

    			/* 360环视 : 手动开启环视 */
    			Data[0] = 0; /*0x0:No action*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PASSwtReq_VR, Data);
            }

			/* D档低速开启360环视 */
			#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
			if(1 == Object->VehicleConfig[VCONFIG_KIND_OMNIVIEW_AUTO_TURN_ON_AT_LOW_SPEED])
			{
				Data[0] = 1; /*0x1:Open*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AVMAutoSet, Data);
			}
			else
			{
				Data[0] = 0; /*0x0:Disable*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AVMAutoSet, Data);
			}
			#endif

    		/* 门锁设置 : 超级锁设置 */
    		#if 0
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_SUPER_LOCK])
    		{
    			Data[0] = 1;  /*0x1:OFF*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SuperLockSet, Data);
    		}
    		else
            {
                Data[0] = 0;  /*0x0:No action*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SuperLockSet, Data);
            }
    		#endif

    		/* Parking lights */
    		#if (defined SWC_IPC_PROJECT_TYPE_P02) //|| (defined SWC_IPC_PROJECT_TYPE_D01)
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_PARKING_LAMP])
    		{
    			Data[0] = 1; /*0x1:On*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ParkLmpSet, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ParkLmpSet, Data);
    		}
    		#endif

    		/* ESP */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		{
    			if (1 == Object->VehicleConfig[VCONFIG_KIND_ESP_SWITCH_TYPE])
    			{
    				Data[0] = 0;/*0x0:Not Pressed*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_ESPFuncOffSwtSts, Data);
    			}
    			else
    			{
    				Data[0] = 1;/*0x1:Pressed*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_ESPFuncOffSwtSts, Data);
    			}
    		}
    		#endif

    		/* 行人安全辅助系统 */
    		if ((4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
    		 || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
    		{
    			Data[0] = 1; /*0x1:On*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_PedSwtReq, Data);

    			/* 紧急转向辅助 */
    			if (1 == Object->VehicleConfig[VCONFIG_KIND_EMERGENCY__STEERING_SUPPORT])
    			{
    				Data[0] = 0; /*0x0:Off*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_PedSwtReq, Data);
    			}
    			else
    			{
    				Data[0] = 0; /*0x0:Off*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_PedSwtReq, Data);
    			}
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_PedSwtReq, Data);
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_PedSwtReq, Data);
    		}

    		/* 外后视镜倒车模式 KAG*/
    		if ((4 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]) || (5 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]))
    		{
    			Data[0] = 2;  /* 0x2:Bothsideenable */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_OrvmPosnEnaSts, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_OrvmPosnEnaSts, Data);
    		}

    		/* 外后视镜角度调节 KAG*/
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05)\
    			|| (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		if ((0 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    		 ||	(1 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    	     || (2 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    	     || (3 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    	     || (4 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]))
    		{
    			Data[0] = 0;  /* 0x0:Mir_Swt_Idle */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ORVMLensAdjmt_HUT, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0:Mir_Swt_Idle */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ORVMLensAdjmt_HUT, Data);
    		}
    		#endif

    		/* 洗车拖车模式激活 CBA */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03)
    		// || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P03)
    		if (((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    	       && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
    		  || ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    		   && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
    		{
    			Data[0] = 0;  /* 0x0:CarWashModeOFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_CarWashMode_Req, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0:CarWashModeOFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_CarWashMode_Req, Data);
    		}
    		#endif

    		/* 涉水模式 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03)\
    		 || (defined SWC_IPC_PROJECT_TYPE_D01)|| (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		if (((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    	       && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
    		  || ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    		   && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
    		{
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_WadeModeSet, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_WadeModeSet, Data);
    		}
    		#endif

    		/* Save 模式下充电阈值设置(ForPHEV) DAA CBA */
    		/* DAA:VCONFIG_KIND_FUEL */
    		/* CBA:VCONFIG_KIND_ELECTROMOTOR_POSITION */
			#if 0
    		// #if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) //#ifdef SWC_IPC_PROJECT_TYPE_P03
    		if ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    		 && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
    		{
    			Data[0] = 4;  /* 0x4:50% */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattSOCLimSaveMod, Data);
    		}
    		else
    		{
    			Data[0] = 4;  /* 0x4:50% */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattSOCLimSaveMod, Data);
    		}
    		#endif

    		/* 能量回收等级设置 */
    		/* HAJ:VCONFIG_KIND_BRAKING_ENERGY_RECOVERY */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P03)\
     	    	|| (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)\
				|| (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P05) // || (defined SWC_IPC_PROJECT_TYPE_A07)
    		if (((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    	       && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
    		  || ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    		   && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
    		{
    			Data[0] = 1;  /* 0x1:Normal */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, Data);
    		}
    		else
    		{
    			Data[0] = 1;  /* 0x1:Normal */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, Data);
    		}
    		#endif

    		/* 氛围灯 */
			/* SAQ60:轮廓；SAQ70:面发光；SAQ80:面发光； */
			/* ZK100：无音乐律动；ZK110：ALCM/CEM解析音乐律动；ZK120：主机解析 */
			/* ZK200：无分区联动（智能联动）；ZK210：有分区联动（智能联动）； */
			/* ZQ600：无氛围灯分区开关；ZQ610：有氛围灯分区开关 */
    		/* 氛围灯及背景光(SAQ):VCONFIG_KIND_MOOD_LAMP */
    		/* 多色律动氛围灯音频解析方式(ZK1):VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP */
    		/* 氛围灯分区功能(ZK2):VCONFIG_KIND_MOOD_LAMP_PARTITION */
			/* 氛围灯分区点亮开关控制(ZQ6):VCONFIG_KIND_AMBIENT_LIGHT_CONTROL */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		if((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))
    		{
    			/* 氛围灯总开关 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMMasterSwt, Data);
    			/* 氛围灯亮度 */
				#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
					(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
					(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
    			Data[0] = 5;  /* 0x5:50 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMLightLvlSet, Data);
				#endif
    		}
    		else
    		{
    			/* 氛围灯总开关 */
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMMasterSwt, Data);
    			/* 氛围灯亮度 */
				#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
					(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
					(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
    			Data[0] = 5;  /* 0x5:50 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMLightLvlSet, Data);
				#endif
    		}
    		#endif

			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
				(defined SWC_IPC_PROJECT_TYPE_D03) //|| (defined SWC_IPC_PROJECT_TYPE_A07)
			if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP])))
    		{
    			/* 轮廓氛围灯颜色选择 */
    			Data[0] = 2;  /* 0x2:极光白 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet, Data);
    			/* 轮廓氛围灯多色彩静态 */
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt, Data);
    			/* 轮廓氛围灯多色彩动态 */
    			Data[0] = 0;  /* 0x0:DynModOFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet, Data);
    		}
    		else
    		{
    			/* 轮廓氛围灯颜色选择 */
    			Data[0] = 2;  /* 0x2:极光白 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet, Data);
    			/* 轮廓氛围灯多色彩静态 */
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt, Data);
    			/* 轮廓氛围灯多色彩动态 */
    			Data[0] = 0;  /* 0x0:DynModOFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet, Data);
    		}
    		#endif

			#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) \
				//|| (defined SWC_IPC_PROJECT_TYPE_A07)
    		if((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))
    		{
				/* 轮廓氛围灯呼吸灯 */
				Data[0] = 0;  /* 0X0：OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt, Data);
			}
			else
			{
				/* 轮廓氛围灯呼吸灯 */
				Data[0] = 0;  /* 0X0：OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt, Data);
			}
			#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) ||\
				(defined SWC_IPC_PROJECT_TYPE_D01)
    		if((6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))
    		{
    			/* 面发光氛围灯流水灯设置 */
    			Data[0] = 0;  /* 0X0：OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMFloSwt, Data);
    			/* 面发光氛围灯颜色选择 */
    			Data[0] = 2;  /* 0X2：极光白 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet_OLE, Data);
    			/* 面发光氛围灯多色彩静态模式 */
    			Data[0] = 0;  /* 0X2：OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt_OLE, Data);
    			/* 面发光氛围灯多色彩动态模式 */
    			Data[0] = 0;  /* 0x0:DynModOFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet_OLE, Data);
    			/* 面发光氛围灯呼吸灯设置 */
				Data[0] = 0;  /* 0X0：OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt_OLE, Data);
    			/* 面发光氛围灯流水灯设置 */
    			Data[0] = 3;  /* 0x3:极光白 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr1, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr2, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr3, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr4, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr5, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr6, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr7, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr8, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr9, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr10, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr11, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr12, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr13, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr14, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr15, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr16, Data);
    		}
    		else
    		{
				Object->AppNvm.MultiColorNrFlag = FALSE;
    			/* 面发光氛围灯流水灯设置 */
    			Data[0] = 0;  /* 0X0：OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMFloSwt, Data);
    			/* 面发光氛围灯颜色选择 */
    			Data[0] = 2;  /* 0X2：极光白 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet_OLE, Data);
    			/* 面发光氛围灯多色彩静态模式 */
    			Data[0] = 0;  /* 0X2：OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt_OLE, Data);
    			/* 面发光氛围灯多色彩动态模式 */
    			Data[0] = 0;  /* 0x0:DynModOFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet_OLE, Data);
    			/* 面发光氛围灯呼吸灯设置 */
				Data[0] = 0;  /* 0X0：OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt_OLE, Data);
    			/* 面发光氛围灯流水灯设置 */
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr1, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr2, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr3, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr4, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr5, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr6, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr7, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr8, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr9, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr10, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr11, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr12, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr13, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr14, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr15, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr16, Data);
    		}
    		#endif
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02) //|| (defined SWC_IPC_PROJECT_TYPE_A07)
    		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
    		 && ((1 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP]) || (2 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP])))
    		{
    			/* 轮廓氛围灯音乐律动 */
    			Data[0] = 1;  /* 0x1:On */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMRhmSwt, Data);
				Data[0] = 0x65;  /* 0x65:Noaction */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq0, Data);
				Data[0] = 0x65;  /* 0x65:Noaction */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq1, Data);
				Data[0] = 0x65;  /* 0x65:Noaction */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq2, Data);
				Data[0] = 0x65;  /* 0x65:Noaction */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq3, Data);
				Data[0] = 0x65;  /* 0x65:Noaction */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq4, Data);
				Data[0] = 0x65;  /* 0x65:Noaction */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq5, Data);
				Data[0] = 0x65;  /* 0x65:Noaction */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq6, Data);
    		}
    		else
    		{
    			/* 轮廓氛围灯音乐律动 */
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMRhmSwt, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq0, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq1, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq2, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq3, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq4, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq5, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq6, Data);
    		}
    		#endif

			#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) ||\
				(defined SWC_IPC_PROJECT_TYPE_D01)
			if(((6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
    		 && ((1 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP]) || (2 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP])))
    		{
				/* 面发光氛围灯音乐随动 */
				Data[0] = 1;  /* 0x1:On */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMRhmSwt_OLE, Data);
				Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq0, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq1, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq2, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq3, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq4, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq5, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq6, Data);
			}
			else
			{
				/* 面发光氛围灯音乐随动 */
				Data[0] = 1;  /* 0x1:On */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMRhmSwt_OLE, Data);
				Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq0, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq1, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq2, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq3, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq4, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq5, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq6, Data);
			}
			#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
    		 && (1 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP_PARTITION]))
    		{
    			/* 氛围灯联动:联动开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMPartitionSwt, Data);
    		}
    		else
    		{
    			/* 氛围灯联动:联动开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMPartitionSwt, Data);
    		}
    		#endif

			#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
				(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
    		 && (1 == Object->VehicleConfig[VCONFIG_KIND_AMBIENT_LIGHT_CONTROL]))
    		{
    			/* 分区开关:左侧仪表板氛围灯开关 */
    			Data[0] = 1;  /* 0X1： ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LeftPanelALCMSwt, Data);
    			/* 分区开关：右侧仪表板氛围灯开关 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RightPanelALCMSwt, Data);
    			/* 分区开关：主驾氛围灯开关 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDoorALCMSwt, Data);
    			/* 分区开关：副驾氛围灯开关 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassDoorALCMSwt, Data);
    			/* 分区开关：左后门氛围灯开关 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LRDoorALCMSwt, Data);
    			/* 分区开关：右后门氛围灯开关 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRDoorALCMSwt, Data);
    			/* 分区开关：脚窝氛围灯开关 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FootALCMSwt, Data);
    			/* 分区开关：顶棚氛围灯开关 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofALCMSwt, Data);
    		}
    		else
    		{
    			/* 分区开关:左侧仪表板氛围灯开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LeftPanelALCMSwt, Data);
    			/* 分区开关:右侧仪表板氛围灯开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RightPanelALCMSwt, Data);
    			/* 分区开关:主驾门氛围灯开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDoorALCMSwt, Data);
    			/* 分区开关:副驾门氛围灯开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassDoorALCMSwt, Data);
    			/* 分区开关:左后门氛围灯开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LRDoorALCMSwt, Data);
    			/* 分区开关:右后门氛围灯开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRDoorALCMSwt, Data);
    			/* 分区开关:脚窝灯开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FootALCMSwt, Data);
    			/* 分区开关:顶棚氛围灯开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofALCMSwt, Data);
    		}
    		#endif

			/* 音乐灯光秀：设置开关 */
			#if (defined SWC_IPC_PROJECT_TYPE_B02)
			if(1 == Object->VehicleConfig[VCONFIG_KIND_MUSIC__LIGHT_SHOW])
    		{
				Data[0] = 1;  /* 0x1:OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicLightShowSet, Data);
			}
			else
			{
				Data[0] = 1;  /* 0x1:OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicLightShowSet, Data);
			}
			#endif

    		/* 解闭锁提示 */
		    #if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				(defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
				(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		if(1 == Object->VehicleConfig[VCONFIG_KIND_BLOCKING_PROMPT_TYPE])
    		{
    			Data[0] = 2;  /* 0x2:LightOnly */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockPromptFunSet, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0:Light&Horn */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockPromptFunSet, Data);
    		}
    		#endif

    		/* 蓝牙泊车 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		if ((4 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (5 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (6 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 	 || (7 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
    		{
    			/* 蓝牙泊入自动闭锁 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPAEntryLockSet, Data);
    			/* 蓝牙泊出自动解锁 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPALvngUnlockSet, Data);
    		}
    		else
    		{
    			/* 蓝牙泊入自动闭锁 */
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPAEntryLockSet, Data);
    			/* 蓝牙泊出自动解锁 */
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPALvngUnlockSet, Data);
    		}
    		#endif

    		/* 解锁模式 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
				(defined SWC_IPC_PROJECT_TYPE_P02)
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_DOOR_UNLOCK_MODE])
    		{
    			Data[0] = 0;/*0x0:All Door*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DoorUnlockModSet, Data);
    		}
    		else
    		{
    			Data[0] = 0;/*0x0:All Door*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DoorUnlockModSet, Data);
    		}
    		#endif

    		/* DST */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
    			(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_DYNAMIC_STEERING_TORQUE])
    		{
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DSTSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DSTSwtReq, Data);
    		}
    		#endif

    		/* 驾驶模式开关记忆：硬开关 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03)\
    		 || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) \
    		 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_B02)
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_MEMORY_OF_DRIVING_MODE])
    		 && (1 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_SIGNAL_SELECT]))
    		{
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvgModeMemReq, Data);
    		}
    		else
    		{
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvgModeMemReq, Data);
    		}
    		#endif

    		/* 副驾驶座椅按摩设置 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		if (((1 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]))
		     && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
    		{
    			/* 按摩强度 */
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgLvlSet, Data);
    			/* 按摩模式 */
    			Data[0] = 1;/* 0x1:Wave Mode */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgModSet, Data);
    		}
    		else
    		{
    			/* 按摩强度 */
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgLvlSet, Data);
    			/* 按摩模式 */
    			Data[0] = 0;/* 0x0:No Action */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgModSet, Data);
    		}
    		#endif

    		/* 主动进入解锁 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
    			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D02)
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM]))
    		{
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryUnlockSet, Data);
    		}
    		else
    		{
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryUnlockSet, Data);
    		}
    		#endif

    		/* 主动离开闭锁 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
    			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D02)
    		if ((2 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM]))
    		{
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryLockSet, Data);
    		}
    		else
    		{
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryLockSet, Data);
    		}
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)\
    		 || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)\
			 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P05)
    		/* 无感车控：天窗/遮阳帘 */
    		if ((2 == Object->VehicleConfig[VCONFIG_KIND_SUN_ROOF_SHADE_SWITCH_TYPE])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_SUN_ROOF_SHADE_SWITCH_TYPE]))
    		{
    			/* 天窗 */
    			Data[0] = 0;/* 0x0:No action */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SunRoofSwtReq_VR, Data);
    			/* 遮阳帘 */
    			Data[0] = 0;/* 0x0:No action */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SunShadeSwtReq_VR, Data);
    		}
    		else
    		{
    			/* 天窗 */
    			Data[0] = 0;/* 0x0:No action */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SunRoofSwtReq_VR, Data);
    			/* 遮阳帘 */
    			Data[0] = 0;/* 0x0:No action */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SunShadeSwtReq_VR, Data);
    		}
    		#endif

    		/* 无感车控：主驾6向调节 */
    		/* 前排座椅调节开关类型 ZP1(VCONFIG_KIND_FRT_SEAT__ADJ_SWITCH_TYPE) */
    		/* 驾驶员座椅 PAA(VCONFIG_KIND_DRIVER_SEAT) */
    		/* 副驾驶座椅 PAB(VCONFIG_KIND_PASSENGER_SEAT) */
    		/* 驾驶员座椅坐垫侧翼调节 PCJ(VCONFIG_KIND_DRIVER_SEAT_CUSHION_FLANK) */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		if (((2 == Object->VehicleConfig[VCONFIG_KIND_FRT_SEAT__ADJ_SWITCH_TYPE])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_FRT_SEAT__ADJ_SWITCH_TYPE]))
    		 && ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		 || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
    		 && ((0 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_CUSHION_FLANK])
    		 || (1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_CUSHION_FLANK])))
    		{
    			Data[0] = 0;/* 0x0:Seat_Swt_Idle */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatAdjmt_HUT, Data);
    		}
    		else
    		{
    			Data[0] = 0;/* 0x0:Seat_Swt_Idle */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatAdjmt_HUT, Data);
    		}
    		#endif

    		/* 无感车控：外后视镜折叠 */
    		/* 外后视镜 KAG(VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR) */
    		/* 后视镜折叠虚拟开关控制 ZP3(VCONFIG_KIND_OSRVM_FOLD_VIRTUAL_SW_CONTROL) */
    		// #if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05)
            #if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B02)  || (defined SWC_IPC_PROJECT_TYPE_P03)\
    			|| (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		if (((1 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    		 || (2 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    		 || (4 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]))
    		 && (1 == Object->VehicleConfig[VCONFIG_KIND_OSRVM_FOLD_VIRTUAL_SW_CONTROL]))
    		{
    			Data[0] = 0;/* 0x0:None */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ORVMFoldSwt_HUT, Data);
    		}
    		else
    		{
    			Data[0] = 0;/* 0x0:None */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ORVMFoldSwt_HUT, Data);
    		}
    		#endif

    		/* 越野模式：专家模式 */
    		/* 项目代码 AAA(VCONFIG_KIND_PROJECT_CODE) */
    		/* 变速器 EAA(VCONFIG_KIND_TRANSMISSION) */
    		/* 减震器 GAD(VCONFIG_KIND_DAMPER) */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05)
    		if (0x45u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
				#if 0
				Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
				#endif
    			/* 转向模式 / 方向盘助力模式 */
    			if ((0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT]) || (1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_SYSTEM]))
    			{
    				Data[0] = 0;/* 0x0: 舒适 */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3:NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			/* ESC设置 */
    			Data[0] = 0;/* 0x0: ALL_ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    		}
    		else
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			/* ESC设置 */
    			Data[0] = 2;/* 0x2: ALL_OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    		}
    		#elif (defined SWC_IPC_PROJECT_TYPE_P03)
    		if ((0x47u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]) || (0x48u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]) \
    		||  (0x49u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]))
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* 转向模式 */
    			if ((0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT]) || (1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_SYSTEM]))
    			{
    				Data[0] = 0;/* 0x0: 舒适 */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3:NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			/* ESC设置 */
    			Data[0] = 0;/* 0x0: ALL_ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
					((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
    			{
    				Data[0] = 1;/* 0x1: Comfort */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3: NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    		}
    		else
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* ESC设置 */
    			Data[0] = 2;/* 0x2: ALL_OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			Data[0] = 3;/* 0x3: NO Hut Control */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    		}
    		#elif (defined SWC_IPC_PROJECT_TYPE_P02)
    		if (0x34u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* 转向模式 */
    			if ((0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT]) || (1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_SYSTEM]))
    			{
    				Data[0] = 0;/* 0x0: 舒适 */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3:NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			/* ESC设置 */
    			Data[0] = 0;/* 0x0: ALL_ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
					((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
    			{
    				Data[0] = 1;/* 0x1: Comfort */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3: NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    		}
    		else
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* ESC设置 */
    			Data[0] = 2;/* 0x2: ALL_OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			Data[0] = 3;/* 0x3: NO Hut Control */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    		}
    		#elif (defined SWC_IPC_PROJECT_TYPE_D01)
    		if (0x37u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* 转向模式 */
    			if ((0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT]) || (1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_SYSTEM]))
    			{
    				Data[0] = 0;/* 0x0: 舒适 */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3:NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			/* ESC设置 */
    			Data[0] = 0;/* 0x0: ALL_ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
					((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
    			{
    				Data[0] = 1;/* 0x1: Comfort */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3: NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    		}
    		else
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* ESC设置 */
    			Data[0] = 2;/* 0x2: ALL_OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			Data[0] = 3;/* 0x3: NO Hut Control */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    		}
    		#elif (defined SWC_IPC_PROJECT_TYPE_D02)
    		if (0x5Cu == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* 转向模式 */
    			if ((0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT]) || (1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_SYSTEM]))
    			{
    				Data[0] = 0;/* 0x0: 舒适 */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3:NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			/* ESC设置 */
    			Data[0] = 0;/* 0x0: ALL_ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
					((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
    			{
    				Data[0] = 1;/* 0x1: Comfort */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3: NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    		}
    		else
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* ESC设置 */
    			Data[0] = 2;/* 0x2: ALL_OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			Data[0] = 3;/* 0x3: NO Hut Control */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    		}
    		#elif (defined SWC_IPC_PROJECT_TYPE_D03)
    		if (0x5Eu == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* 转向模式 */
    			if ((0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT]) || (1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_SYSTEM]))
    			{
    				Data[0] = 0;/* 0x0: 舒适 */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3:NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			/* ESC设置 */
    			Data[0] = 0;/* 0x0: ALL_ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
					((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
    			{
    				Data[0] = 1;/* 0x1: Comfort */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3: NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    		}
    		else
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* ESC设置 */
    			Data[0] = 2;/* 0x2: ALL_OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			Data[0] = 3;/* 0x3: NO Hut Control */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    		}
    		#endif

    		/* 货箱照明设置(皮卡) */
    		#if defined SWC_IPC_PROJECT_TYPE_P05
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_DECK_LAMP])
    		{
    			/* 货箱灯开关设置 */
    			Data[0] = 1;  /* 0x1:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FreightLmptSwt, Data);
    			/* 货厢灯自动开启功能 */
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FreightLmpAutoSet, Data);
    		}
    		else
    		{
    			/* 货箱灯开关设置 */
    			Data[0] = 0;  /* 0x0:no action */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FreightLmptSwt, Data);
    			/* 货厢灯自动开启功能 */
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FreightLmpAutoSet, Data);
    		}
    		#endif

    		/* 后风挡小窗电动调节 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05)// || (defined SWC_IPC_PROJECT_TYPE_D02)
    		if (2 == Object->VehicleConfig[VCONFIG_KIND_RR_SLIDING_WINDOW])
    		{
    			Data[0] = 0;  /* 0x0:No Action */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RWinSwtReq_TC, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0:No Action */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RWinSwtReq_TC, Data);
    		}
    		#endif

    		/* 主副油箱供油控制 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05)
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_AUXILIARY_FUEL_TANK])
    		{
    			Data[0] = 0;  /* 0x0:主油箱 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_OilBoxSplyReq, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0:主油箱 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_OilBoxSplyReq, Data);
    		}
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    		if ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL]) || (8 == Object->VehicleConfig[VCONFIG_KIND_FUEL]))
    		{
    			Data[0] = 0;  /* 0x0:100% 动力电池充电百分比 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattSOCLim, Data);
    		}
    		else
    		{
    			Data[0] = 6;  /* 0x6:No Action 动力电池充电百分比 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattSOCLim, Data);
    		}
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    		if (((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL]) || (8 == Object->VehicleConfig[VCONFIG_KIND_FUEL])) \
    		 && (0 != Object->VehicleConfig[VCONFIG_KIND_BATTERY_TEMPERATURE_KEEP_WITH_GUN]))
    		{
    			Data[0] = 2;  /* 0x2:Off 电池包插抢保温开关 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattKeepTemp, Data);
    		}
    		else
    		{
    			Data[0] = 2;  /* 0x2:Off 电池包插抢保温开关 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattKeepTemp, Data);
    		}
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    		if (((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL]) || (8 == Object->VehicleConfig[VCONFIG_KIND_FUEL])) \
    		 && (1 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_HEAT_PRESERVATION_FUNCTION_OF_BATTERY_PACK]))
    		{
    			Data[0] = 2;  /* 0x2:Off 电池包主动保温开关 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_IntelBattTempMagSet, Data);
    		}
    		else
    		{
    			Data[0] = 2;  /* 0x2:Off 电池包主动保温开关 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_IntelBattTempMagSet, Data);
    		}
    		#endif

    		/* 方向盘未回正提醒功能开关 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			    (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		if(1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_WHEEL_BACK_REMINDER])
    		{
    			Data[0] = 1;  /*0x1:ON*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerCorrnReq, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /*0x0:OFF*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerCorrnReq, Data);
    		}
    		#endif

    		/* 越野热管理模式:越野热管理模式开关 */
    		#ifdef SWC_IPC_PROJECT_TYPE_P05
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_OFF_ROAD_THERMAL_MANAGEMENT_MODE])
    		{
    			Data[0] = 0;  /* 0x0:off */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_OffroadThmSts, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0:off */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_OffroadThmSts, Data);
    		}
    		#endif

    		/* 方向盘加热：开关 */
    		if(1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_HEATING])
    		{
    			Data[0] = 1;  /*0x1:No request*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerWheelHeatSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /*0x0:No action*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerWheelHeatSwtReq, Data);
    		}

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07) // || (defined SWC_IPC_PROJECT_TYPE_P02)
    		if(1 == Object->VehicleConfig[VCONFIG_KIND_HEADLAMP_VIRTUAL_SW])
    		{
    			/* 大灯切换：位置灯开关 */
    			Data[0] = 0;  /*0x0:OFF*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PosnLmpSwtSts_HUT, Data);
    			/* 大灯切换：近光灯开关开关 */
    			Data[0] = 0;  /*0x0:OFF*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LowBeamSwtSts_HUT, Data);
    			/* 大灯切换：自动大灯开关 */
    			Data[0] = 1;  /*0x1:Auto*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoLmpSwtSts_HUT, Data);
    		}
    		else
    		{
    			/* 大灯切换：位置灯开关 */
    			Data[0] = 0;  /*0x0:OFF*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PosnLmpSwtSts_HUT, Data);
    			/* 大灯切换：近光灯开关开关 */
    			Data[0] = 0;  /*0x0:OFF*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LowBeamSwtSts_HUT, Data);
    			/* 大灯切换：自动大灯开关 */
    			Data[0] = 0;  /*0x0:NonAuto*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoLmpSwtSts_HUT, Data);
    		}
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)// || (defined SWC_IPC_PROJECT_TYPE_P02)
    		if((1 == Object->VehicleConfig[VCONFIG_KIND_VIRTUAL_SW_FOR_REAR_FOG_LAMP]) && (1 == VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE))
    		{
    			/* 后雾灯：后雾灯开关信号 */
    			Data[0] = 0;  /*0x0:OFF*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearFogLmpSwtSts_HUT, Data);
    		}
    		else
    		{
    			/* 后雾灯：后雾灯开关信号 */
    			Data[0] = 0;  /*0x0:OFF*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearFogLmpSwtSts_HUT, Data);
    		}
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_A07)
    		/* 自动驻车 */
    		if((2 == Object->VehicleConfig[VCONFIG_KIND_AVH_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_AVH_SWITCH_TYPE])) // ZW2
    		{
				if(1 == Object->VehicleConfig[VCONFIG_KIND_FUEL]) //汽油
				{
					if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_ESP2, SWC_IPC_NULL))
					{
						#if (defined COMEX_SIGNAL_RX_AVHSTS)
						IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AVHSts, Data);
						#elif (defined COMEX_SIGNAL_RX_AVHSTS_0X145)
						IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AVHSts_0x145, Data);
						#endif
						if ((1 == Data[0]) || (2 == Data[0]))
						{
							Data[0] = 1; /*0x1:Request*/
							IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_AVHSwitchSts, Data);
						}
					}
				}
				// else if(3 == Object->VehicleConfig[VCONFIG_KIND_FUEL]) //HEV
				// {
				// 	if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_ESP_FD2, SWC_IPC_NULL))
				// 	{
				// 		IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AVHSts_0x137, Data);
				// 		if ((1 == Data[0]) || (2 == Data[0]))
				// 		{
				// 			Data[0] = 1; /*0x1:Request*/
				// 			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_AVHSwitchSts, Data);
				// 		}
				// 	}
				// }
				else
				{
					;
				}
    		}
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		/* 电子驻车 */
    		if((2 == Object->VehicleConfig[VCONFIG_KIND_EPB_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_EPB_SWITCH_TYPE])) // ZW3
    		{
    			Data[0] = 2;  /*0x2:Apply*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EPB_SwtPosn, Data);
    		}
    		else
    		{
    			Data[0] = 1;  /*0x1:Release*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EPB_SwtPosn, Data);
    		}
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_A07) // (defined SWC_IPC_PROJECT_TYPE_B02)
    		/* 按键虚拟开关：拨片换挡 */
    		if(1 == Object->VehicleConfig[VCONFIG_KIND_VIRTUAL_SW_FOR_STRG_WHL_HANDLE_SHIFT])
    		{
    			Data[0] = 0;  /*0x01:Shift peddle request*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_TGSSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /*0x00:No shift peddle request*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_TGSSwtReq, Data);
    		}
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_A07)
    		/* 陡坡缓降(下坡辅助) */
    		//Config: ZW4  Byte 97 bit 4-2
    		if((2 == Object->VehicleConfig[VCONFIG_KIND_HDC_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_HDC_SWITCH_TYPE])) // ZW2
    		{
				if(1 == Object->VehicleConfig[VCONFIG_KIND_FUEL]) //汽油
				{
					if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_ESP2, SWC_IPC_NULL))
    				{
						#if (defined COMEX_SIGNAL_RX_HDCCTRL)
						IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HDCCtrl, Data);
						#elif (defined COMEX_SIGNAL_RX_HDCCTRL_0X145)
						IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HDCCtrl_0x145, Data);
						#endif
						if ((1 == Data[0]) || (2 == Data[0]))
						{
							Data[0] = 1; /*0x1:Request*/
							IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_HDCSwitchCtrl, Data);
						}
    				}
				}
				// else if(3 == Object->VehicleConfig[VCONFIG_KIND_FUEL]) //HEV
				// {
				// 	if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_ESP_FD2, SWC_IPC_NULL))
    			// 	{
				// 		IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HDCCtrl_0x137, Data);
				// 		if ((1 == Data[0]) || (2 == Data[0]))
				// 		{
				// 			Data[0] = 1; /*0x1:Request*/
				// 			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_HDCSwitchCtrl, Data);
				// 		}
    			// 	}
				// }
				else
				{
					;
				}
    		}
    		#endif

			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
			/* 雨刮间歇档位 / 灵敏度调节 */
			if (1 == Object->VehicleConfig[VCONFIG_KIND_WIPER_INTERMITTENT_LEVEL_VIRTUAL_SW])
			{
				Data[0] = 2;  /*0x2:Sensitivity 3,R_650Ω*/
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSSensitivityReq_HUT, Data);
			}
			else
			{
				Data[0] = 0;  /*0x0:Sensitivity 1,R_0Ω_Slow*/
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSSensitivityReq_HUT, Data);
			}
			#endif

			#if (defined SWC_IPC_PROJECT_TYPE_P03)
			/* 副驾座椅非个性化记忆 副驾非个性化记忆软开关设置 */
			if (1 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MEMORY_ASSISTANT])
			{
				Data[0] = 0;  /* 0x0:no action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetSwt_Pass, Data);
			}
			else
			{
				Data[0] = 0;  /* 0x0:no action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetSwt_Pass, Data);
			}
			#endif

			#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D02)
			/* 副驾座椅非个性化记忆 副驾座椅迎宾 */
			if (1 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_SEAT_WELCOME_FUNCTION])
			{
				Data[0] = 1;  /* 0x1:Enable */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_Pass, Data);
			}
			else
			{
				Data[0] = 0;  /* 0x0:Disable */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_Pass, Data);
			}
			#endif

			/* 后排左侧座椅按摩设置 ZV2+ZS9 */
			#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
				(defined SWC_IPC_PROJECT_TYPE_D02)
			if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]))
		     && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
			{
				/* 按摩强度 */
				Data[0] = 0;/* 0x0:OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgLvlSet, Data);
				/* 按摩模式 */
				Data[0] = 1;/* 0x1:Wave Mode */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgModSet, Data);
			}
			else
			{
				/* 按摩强度 */
				Data[0] = 0;/* 0x0:OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgLvlSet, Data);
				/* 按摩模式 */
				Data[0] = 0;/* 0x0:No action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgModSet, Data);
			}
			#endif

			/* 后排右侧座椅按摩设置 ZV3+ZS9 */
			#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) \
			|| (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_D02)
			if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]))
			 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
			{
				/* 按摩强度 */
				Data[0] = 0;/* 0x0:OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgLvlSet, Data);
				/* 按摩模式 */
				Data[0] = 1;/* 0x1:Wave Mode */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgModSet, Data);
			}
			else
			{
				/* 按摩强度 */
				Data[0] = 0;/* 0x0:OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgLvlSet, Data);
				/* 按摩模式 */
				Data[0] = 0;/* 0x0:No action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgModSet, Data);
			}
			#endif

    		/* 前排座椅迎宾 PAA*/
    		if ((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		 || (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
    		{
    			Data[0] = 1;	/* 0x1:Enable */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna, Data);
    		}
    		else
    		{
    			Data[0] = 0;	/* 0x0:Disable */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna, Data);
    		}

    		/* 座椅设置:后排座椅迎宾 */
    		#ifdef SWC_IPC_PROJECT_TYPE_P05
    		if(1 == Object->VehicleConfig[VCONFIG_KIND_2ND_ROW_SEAT_WELCOME_FUNCTION])
    		{
    			Data[0] = 1;  /*0x1:Enable*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_SecRow, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /*0x0:Disable*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_SecRow, Data);
    		}
    		#endif
    		/* 外后视镜自动折叠 */
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    	     || (2 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    	     || (3 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    	     || (4 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]))
    		{
    			Data[0] = 1;  /*0x1:Manual*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearviewFoldModSet, Data);
    		}
    		else
    		{
    			Data[0] = 1;  /*0x1:Manual*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearviewFoldModSet, Data);
    		}

    		/* 车速关窗 && 闭锁关窗 */
    		/* MAE:VCONFIG_KIND_DRIVER_WINDOW_OPERATING */
    		/* MAF:VCONFIG_KIND_PASSENGER_WINDOW_OPERATING */
    		/* MAG:VCONFIG_KIND_RR_1ST_WINDOW_OPERATING */
    		/* ZC0:VCONFIG_KIND_DOOR_MODULE_TYPE */
    		/* 天窗控制器(ZC3):VCONFIG_KIND_SUN_ROOF_CONTROLLER */
			/* ZP9:VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
				(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		/* 车速关窗 */
    		if (((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]))
    	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]))
    	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]))
    		 && (1 == Object->VehicleConfig[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE]))
    		{
    			Data[0] = 0;  /* 0x0：Close */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ClsWinSpdSet, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0：Close */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ClsWinSpdSet, Data);
    		}

    		/* 闭锁关窗 */
    		if (((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]))
    	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]))
    	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]))
    		 && (1 == Object->VehicleConfig[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE])
			 && ((1 == Object->VehicleConfig[VCONFIG_KIND_DOOR_MODULE_TYPE]) || (2 == Object->VehicleConfig[VCONFIG_KIND_DOOR_MODULE_TYPE])))
    		{
    			Data[0] = 0;  /* 0x0：Close */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWinSet, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0：Close */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWinSet, Data);
    		}
    		#endif

    		/* 电动侧踏 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
				(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		if (6 == Object->VehicleConfig[VCONFIG_KIND_SIDE_STEP])
    		{
    			/* 电动侧踏开关 */
    			Data[0] = 1;/* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ElecSideSteppingSysSet, Data);
    			/* 特殊模式开关 */
    			Data[0] = 1;/* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AllTerrainDislSet, Data);
    			/* 车顶模式开关 */
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofModSet, Data);
    		}
    		else
    		{
    			/* 电动侧踏开关 */
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ElecSideSteppingSysSet, Data);
    			/* 特殊模式开关 */
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AllTerrainDislSet, Data);
    			/* 车顶模式开关 */
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofModSet, Data);
    		}
    		#endif

			/* 启动模式 */
			#if (defined SWC_IPC_PROJECT_TYPE_A07)
			if (3 == Object->VehicleConfig[VCONFIG_KIND_STARTING_SYSTEM])
			{
				Data[0] = 2;  /* 0x2:One click start */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_StartModSet, Data);
			}
			else
			{
				Data[0] = 0;  /* 0x0:no action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_StartModSet, Data);
			}
			#endif

			/* 空调加热开关 */
			#if (defined SWC_IPC_PROJECT_TYPE_A07)
			if ((5 == Object->VehicleConfig[VCONFIG_KIND_FUEL]) && ((0 == Object->VehicleConfig[VCONFIG_KIND_A_C_SYSTEM]) ||\
			(2 == Object->VehicleConfig[VCONFIG_KIND_A_C_SYSTEM])))
			{
				Data[0] = 0;  /* 0x0:no action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACEAHReq_VR, Data);
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACEAHReq_TC, Data);
			}
			else
			{
				Data[0] = 0;  /* 0x0:no action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACEAHReq_VR, Data);
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACEAHReq_TC, Data);
			}
			#endif

			/* 后排左右侧座椅 一键躺倒 */
			#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)
			if (((4 == Object->VehicleConfig[VCONFIG_KIND_SEAT_CONTROL_MODULE]) || (5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_CONTROL_MODULE]) ||\
			(6 == Object->VehicleConfig[VCONFIG_KIND_SEAT_CONTROL_MODULE])) && (1 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_SEAT_FAST_SET]))
			{
				Data[0] = 0;  /* 0x0:no action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearSeatLieFlatOneBtn, Data);
			}
			else
			{
				Data[0] = 0;  /* 0x0:no action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearSeatLieFlatOneBtn, Data);
			}
			#endif

			/* 车窗短升短降 */
			#if (defined SWC_IPC_PROJECT_TYPE_P05)
			if (1 == Object->VehicleConfig[VCONFIG_KIND_WINDOW_SHORT_LIFT_DROP_FUNCTION])
			{
				Data[0] = 1;  /* 0x1:Open */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WinShortUpShortDownSet, Data);
			}
			else
			{
				Data[0] = 0;  /* 0x0:no action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WinShortUpShortDownSet, Data);
			}
			#endif

			/* 空调自干燥 */
			#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
			if (1 == Object->VehicleConfig[VCONFIG_KIND_A_C_SELF_DRYING])
			{
				Data[0] = 0; //0x0:Off
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoDryingSwt, Data);
			}
			else
			{
				Data[0] = 0; //0x0:Off
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoDryingSwt, Data);
			}
			#endif

			/* 生命体征监测 */
			#if (defined SWC_IPC_PROJECT_TYPE_P02)
			if (1 == Object->VehicleConfig[VCONFIG_KIND_CHILD_PRESENCE_DETECTION])
			{
				/* 临时关闭开关 */
				Data[0] = 0x1; /* 0x1:Disable */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_VMDRTmpMonFctnSet, Data);
				/* 延迟报警 */
				Data[0] = 0x1; /* 0x1:Disable */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_VMDRInitAlarmDlySet, Data);
			}
			#endif
    	}
	    else
    	{
    		/*智能启停*/
    		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_D01) ||\
    			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
    			(defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SSSSet_HUT, Data);
    		#endif

    		/* 疲劳驾驶 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03) || \
				(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		Data[0] = 0;  /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDrowsnsDetnSet, Data);
    		#endif

    		/* 驾驶模式 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 0; /*0x0:Standard/Normal*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_D02)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 0; /*0x0:Standard/Normal*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_DrvModReq, Data);
    		#endif

    		/* 外后视镜倒车模式 KAG*/
    		Data[0] = 0;  /* 0x2:Bothsideenable */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_OrvmPosnEnaSts, Data);

    		/* 外后视镜角度调节 KAG*/
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05)\
    			|| (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 0;  /* 0x0:Mir_Swt_Idle */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ORVMLensAdjmt_HUT, Data);
    		#endif

    		/* 洗车拖车模式激活 CBA */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03)
    		// || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P03)
    		Data[0] = 0;  /* 0x0:CarWashModeOFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_CarWashMode_Req, Data);
    		#endif

    		/* 涉水模式 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03)\
    		 || (defined SWC_IPC_PROJECT_TYPE_D01)|| (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		Data[0] = 0;  /* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_WadeModeSet, Data);
    		#endif

    		/* Save 模式下充电阈值设置(ForPHEV) DAA CBA */
			#if 0
    		// #if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 4;  /* 0x4:50% */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattSOCLimSaveMod, Data);
    		#endif

    		/* 能量回收等级设置 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P03)\
             || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) \
             || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P05) // || (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 1;  /* 0x1:Normal */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, Data);
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		/* 氛围灯总开关 */
    		Data[0] = 0;  /* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMMasterSwt, Data);
    		/* 氛围灯亮度 */
    		Data[0] = 5;  /* 0x5:50 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMLightLvlSet, Data);
    		/* 轮廓氛围灯颜色选择 */
			#if (!defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 2;  /* 0x2:极光白 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet, Data);
    		/* 轮廓氛围灯多色彩静态 */
    		Data[0] = 0;  /* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt, Data);
    		/* 轮廓氛围灯多色彩动态 */
    		Data[0] = 0;  /* 0x0:DynModOFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet, Data);
			#endif
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) \
				 // || (defined  SWC_IPC_PROJECT_TYPE_A07)
    		/* 轮廓氛围灯呼吸灯 */
    		Data[0] = 0;  /* 0X0：OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt, Data);
			#endif

			#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) \
				 || (defined  SWC_IPC_PROJECT_TYPE_A07)
    		/* 面发光氛围灯流水灯设置 */
    		Data[0] = 0;  /* 0X0：OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMFloSwt, Data);
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) ||\
				(defined SWC_IPC_PROJECT_TYPE_D01)
			Object->AppNvm.MultiColorNrFlag = FALSE;
    		Data[0] = 2;  /* 0X2：极光白 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet_OLE, Data);
    		/* 面发光氛围灯多色彩静态模式 */
    		Data[0] = 0;  /* 0X2：OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt_OLE, Data);
    		/* 面发光氛围灯多色彩动态模式 */
    		Data[0] = 0;  /* 0x0:DynModOFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet_OLE, Data);
    		/* 面发光氛围灯呼吸灯设置 */
			Data[0] = 0;  /* 0X0：OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt_OLE, Data);
    		/* 面发光氛围灯流水灯设置 */
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr1, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr2, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr3, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr4, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr5, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr6, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr7, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr8, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr9, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr10, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr11, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr12, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr13, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr14, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr15, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr16, Data);
    		#endif
    		#endif
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
    			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
				(defined SWC_IPC_PROJECT_TYPE_D03)
    		/* 轮廓氛围灯音乐律动 */
    		Data[0] = 0;  /* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMRhmSwt, Data);
			#endif
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) ||\
				(defined SWC_IPC_PROJECT_TYPE_D01)
    		/* 面发光氛围灯音乐随动 */
    		Data[0] = 1;  /* 0x1:On */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMRhmSwt_OLE, Data);
    		#endif
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 0x65;  /* 0x65:Noaction */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq0, Data);
    		Data[0] = 0x65;  /* 0x65:Noaction */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq1, Data);
    		Data[0] = 0x65;  /* 0x65:Noaction */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq2, Data);
    		Data[0] = 0x65;  /* 0x65:Noaction */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq3, Data);
    		Data[0] = 0x65;  /* 0x65:Noaction */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq4, Data);
    		Data[0] = 0x65;  /* 0x65:Noaction */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq5, Data);
    		Data[0] = 0x65;  /* 0x65:Noaction */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq6, Data);
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		/* 氛围灯联动:联动开关 */
    		Data[0] = 0;  /* 0X0： OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMPartitionSwt, Data);
    		#endif
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
				(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		/* 分区开关:左侧仪表板氛围灯开关 */
    		Data[0] = 0;  /* 0X0： OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LeftPanelALCMSwt, Data);
    		/* 分区开关:右侧仪表板氛围灯开关 */
    		Data[0] = 0;  /* 0X0： OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RightPanelALCMSwt, Data);
    		/* 分区开关:主驾门氛围灯开关 */
    		Data[0] = 0;  /* 0X0： OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDoorALCMSwt, Data);
    		/* 分区开关:副驾门氛围灯开关 */
    		Data[0] = 0;  /* 0X0： OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassDoorALCMSwt, Data);
    		/* 分区开关:左后门氛围灯开关 */
    		Data[0] = 0;  /* 0X0： OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LRDoorALCMSwt, Data);
    		/* 分区开关:右后门氛围灯开关 */
    		Data[0] = 0;  /* 0X0： OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRDoorALCMSwt, Data);
    		/* 分区开关:脚窝灯开关 */
    		Data[0] = 0;  /* 0X0： OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FootALCMSwt, Data);
    		/* 分区开关:顶棚氛围灯开关 */
    		Data[0] = 0;  /* 0X0： OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofALCMSwt, Data);
    		#endif

			/* 音乐灯光秀：设置开关 */
			#if (defined SWC_IPC_PROJECT_TYPE_B02)
			Data[0] = 1;  /* 0x1:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicLightShowSet, Data);
			#endif

    		/* 解闭锁提示 */
		    #if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				(defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
				(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 0;  /* 0x0:Horn&Light */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockPromptFunSet, Data);
    		#endif

    		/* 蓝牙泊车 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		/* 蓝牙泊入自动闭锁 */
    		Data[0] = 0;  /* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPAEntryLockSet, Data);
    		/* 蓝牙泊出自动解锁 */
    		Data[0] = 0;  /* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPALvngUnlockSet, Data);
    		#endif

    		/* 方向盘助力模式 */
    		Data[0] = 3; /*0x3:NO Hut Control*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);

    		/* 无线充电开关 */
    		Data[0] = 2; /*0x2:Close*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WPC_SwtReq, Data);

    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    		 || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		Data[0] = 2; /*0x2:Close*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RWPC_SwtReq, Data);
    		#endif

    		/* WHUD */
    		Data[0] = 0; /*0x0:No Action*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_SwtReq, Data);
    		Data[0] = 0; /*0x0:No action*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_BrightnessLvlSwt, Data);
    		Data[0] = 0; /*0x0:No action*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_HeightLvlSwt, Data);

    		/* 主驾驶座椅按摩设置 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgLvlSet, Data);
    		Data[0] = 0; /*0x0:No Action*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgModSet, Data);
    		#endif

    		/* 主驾驶座椅腰托设置 */
    		#if 0 // SWC_IPC_PROJECT_TYPE_B03
    		Data[0] = 0;/*0x0:No Action*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatSupportPosnSwt, Data);
    		#endif

    		/* 主驾座椅记忆 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03)\
    		 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
    		 	(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 0; /*0x0:No Command*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSet, Data);
    		Data[0] = 0; /*0x0:FactoryDefault*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, Data);
    		#endif

    		/* 后背门感应开启 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)\
    			|| (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HFASwtSts, Data);
    		#endif

    		/* 后背门开启高度 */
    		#if (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 0; /*0x0:*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PLG_HeightSet, Data);
    		#endif

    		/* 行人安全辅助系统 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_PedSwtReq, Data);
    		/* 行人安全辅助系统紧急转向辅助 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_PedSwtReq, Data);

    		/* 碰撞安全辅助系统制动 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_VehSwtReq, Data);
    		/* 碰撞安全辅助系统紧急转向辅助 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_VehSwtReq, Data);

    		/* 交叉路口辅助 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_JASwtReq, Data);

    		/* 前横穿侧向警告 */
			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCTASwtReq, Data);
			#endif

    		/* 前横穿侧向制动 */
			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCTABrkSwtReq, Data);
			#endif

    		/* 前碰撞预警灵敏度 */
    		Data[0] = 0; /*0x0:Normal*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCW_SnvtySet, Data);

    		/* 自动紧急转向辅助 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    		 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AESSwtReq, Data);
    		#endif

    		/* 车道辅助功能 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LSSSwtReq, Data);

    		/* 车道辅助 : 预警辅助 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LDWSwtReq, Data);

    		/* 车道辅助 : 保持辅助 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LKASwtReq, Data);

    		#if 0
    		/* 车道辅助 : 居中辅助 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCKSwtReq, Data);
    		#endif

    		/* 车道辅助 : 紧急车道保持 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ELKSwtReq, Data);

    		/* 车道辅助 : 智慧躲闪 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IntelligentEvaSwtReq, Data);

    		/* 车道辅助 : 预警方式 */
    		Data[0] = 0; /*0x0:Voice*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LSSWarnFormSwtReq, Data);

    		/* 预警灵敏度 */
    		Data[0] = 0; /*0x0:Normal*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IFC_SnvtySet, Data);

    		/* 侧后辅助系统 : 并线辅助 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCASwtReq, Data);

    		/* 侧后辅助系统 :       开门预警 */
            Data[0] = 0; /*0x0:Off*/
    	    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DOWSwtReq, Data);

    		/* 侧后辅助系统 :       后碰撞预警 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCWSwtReq, Data);

    		/* 侧后辅助系统 : 倒车侧向警告 */
            Data[0] = 0; /*0x0:Off*/
    	    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTASwtReq, Data);

    		/* 侧后辅助系统 : 倒车侧向制动 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTABrkSwtReq, Data);

    		/* 交通标志信息 : 交通标志识别 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSRSwtReq, Data);

    		/* 交通标志信息 : 超速报警 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSRWarnSwtReq, Data);

    		/* 交通标志信息 : 巡航车速限制 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ISLSwtReq, Data);

    		/* 交通标志信息 : 超速报警灵敏度 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSR_SnvtySet, Data);

			#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02)
			/* 交通标志信息 : 导航降速 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NavDecSwtReq, Data);
			#endif

    		/* 灯光控制 : 照我回家延时时间设置*/
    		Data[0] = 0; /*0x0:0seconds*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FolwMeHomeDlyTimSet, Data);

    		/* 灯光控制 : 运动模式灯光设置 */
    		// #if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		//  || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_D03)
			#if 0
    		Data[0] = 0; /*0x0:OFF*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SportModLightSet, Data);
    		#endif

    		/* 360环视 : 环视退出车速值设置 */
            Data[0] = 0; /*0x0:No command*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PASExitSpdSwt, Data);

    		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || \
				(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		/* 360环视 : 道路标定 */
            Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LaneCalActvtCmd, Data);

    		/* 360环视 : 恢复出厂标定 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SwToFieldCalRstCmd, Data);
    		#endif

    		/* 360环视 : 手动开启环视 */
    		Data[0] = 0; /*0x0:No action*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PASSwtReq_VR, Data);

			/* D档低速开启360环视 */
			#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
			Data[0] = 0; /*0x0:Disable*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AVMAutoSet, Data);
			#endif

    		/* 门锁设置 : 超级锁设置 */
    		#if 0
            Data[0] = 0;  /*0x0:No action*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SuperLockSet, Data);
    		#endif

    		/* Parking lights */
    		#if (defined SWC_IPC_PROJECT_TYPE_P02) //|| (defined SWC_IPC_PROJECT_TYPE_D01)
    		Data[0] = 1; /*0x1:On*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ParkLmpSet, Data);
    		#endif

    		/* ESP */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		{
    			Data[0] = 1;/*0x0:Pressed*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_ESPFuncOffSwtSts, Data);
    		}
    		#endif

    		/* 解锁模式 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P05)  || (defined SWC_IPC_PROJECT_TYPE_P03) || \
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02)
    		Data[0] = 0;/*0x0:All Door*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DoorUnlockModSet, Data);
    		#endif

    		/* 360环视 : 自动转向 */
    		Data[0] = 0; /*0x0:No Request*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoAVMSwSet_Cmd, Data);

    		/* DST */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
    			(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DSTSwtReq, Data);
    		#endif

    		/* 驾驶模式开关记忆：硬开关 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03)\
    		 || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) \
    		|| (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_B02)
    		Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvgModeMemReq, Data);
    		#endif

    		/* 副驾驶座椅按摩设置 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		/* 按摩强度 */
    		Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgLvlSet, Data);
    		/* 按摩模式 */
    		Data[0] = 0;/* 0x0:No Action */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgModSet, Data);
    		#endif

    		/* 座椅非个性化设置 PAA ZM2*/
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03)\
    		 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
    		 	(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 0; /*0x0:No Command*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetSwt, Data);
    		#endif

    		/* 主动进入解锁 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
    			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D02)
    		Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryUnlockSet, Data);
    		#endif

    		/* 主动离开闭锁 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
    			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D02)
    		Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryLockSet, Data);
    		#endif

    		/* 无感车控：天窗/遮阳帘 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)\
    		 || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)\
			 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P05)
    		/* 天窗 */
    		Data[0] = 0;/* 0x0:No action */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SunRoofSwtReq_VR, Data);
    		/* 遮阳帘 */
    		Data[0] = 0;/* 0x0:No action */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SunShadeSwtReq_VR, Data);
    		#endif

    		/* 无感车控：主驾6向调节 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 0;/* 0x0:Seat_Swt_Idle */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatAdjmt_HUT, Data);
    		#endif

    		/* 无感车控：外后视镜折叠 */
    		/* 外后视镜 KAG(VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR) */
    		/* 后视镜折叠虚拟开关控制 ZP3(VCONFIG_KIND_OSRVM_FOLD_VIRTUAL_SW_CONTROL) */
    		// #if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05)
            #if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B02)  || (defined SWC_IPC_PROJECT_TYPE_P03)\
    			|| (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 0;/* 0x0:None */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ORVMFoldSwt_HUT, Data);
    		#endif

    		/* 越野模式：专家模式 */
    		/* 项目代码 AAA(VCONFIG_KIND_PROJECT_CODE) */
    		/* 变速器 EAA(VCONFIG_KIND_TRANSMISSION) */
    		/* 减震器 GAD(VCONFIG_KIND_DAMPER) */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02)\
    		 || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		/* 自定义界面 */
    		Data[0] = 0;/* 0x0:Not active */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    		/* 四驱模式 */
    		Data[0] = 0;/* 0x0:2H */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    		/* 驱动模式 */
    		Data[0] = 0;/* 0x0: 舒适 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    		Data[0] = 0;/* 0x0: 舒适 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);

    		#if (!defined SWC_IPC_PROJECT_TYPE_P05)
    		Data[0] = 0;/* 0x0: 舒适 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    		#endif

    		/* ESC设置 */
    		Data[0] = 2;/* 0x2: ALL_OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);

			#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) ||\
				(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 3;/* 0x3: NO Hut Control */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    		#endif

    		#endif

    		/* 货箱照明设置(皮卡) */
    		#if defined SWC_IPC_PROJECT_TYPE_P05
    		/* 货箱灯开关设置 */
    		Data[0] = 0;  /* 0x0:no action */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FreightLmptSwt, Data);
    		/* 货厢灯自动开启功能 */
    		Data[0] = 0;  /* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FreightLmpAutoSet, Data);
    		#endif

    		/* 后风挡小窗电动调节 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05)// || (defined SWC_IPC_PROJECT_TYPE_D02)
    		Data[0] = 0;  /* 0x0:No Action */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RWinSwtReq_TC, Data);
    		#endif

    		/* 主副油箱供油控制 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05)
    		Data[0] = 0;  /* 0x0:主油箱 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_OilBoxSplyReq, Data);
    		#endif

			#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
				// || (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 6;  /* 0x6:No Action 动力电池充电百分比 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattSOCLim, Data);
			#endif

			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 2;  /* 0x2:Off 电池包插抢保温开关 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattKeepTemp, Data);
			#endif

			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 2;  /* 0x2:Off 电池包主动保温开关 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_IntelBattTempMagSet, Data);
    		#endif

    		/* 方向盘未回正提醒功能开关 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			    (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 0;  /*0x0:OFF*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerCorrnReq, Data);
    		#endif

    		/* 越野热管理模式:越野热管理模式开关 */
    		#ifdef SWC_IPC_PROJECT_TYPE_P05
    		Data[0] = 0;  /* 0x0:off */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_OffroadThmSts, Data);
    		#endif

    		/* 方向盘加热：开关 */
    		Data[0] = 0;  /*0x0:No action*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerWheelHeatSwtReq, Data);

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)// || (defined SWC_IPC_PROJECT_TYPE_P02)
    		/* 大灯切换：位置灯开关 */
    		Data[0] = 0;  /*0x0:OFF*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PosnLmpSwtSts_HUT, Data);
    		/* 大灯切换：近光灯开关开关 */
    		Data[0] = 0;  /*0x0:OFF*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LowBeamSwtSts_HUT, Data);
    		/* 大灯切换：自动大灯开关 */
    		Data[0] = 0;  /*0x0:NonAuto*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoLmpSwtSts_HUT, Data);
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)// || (defined SWC_IPC_PROJECT_TYPE_P02)
    		/* 后雾灯：后雾灯开关信号 */
    		Data[0] = 0;  /*0x0:OFF*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearFogLmpSwtSts_HUT, Data);
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		/* 电子驻车 */
    		Data[0] = 1;  /*0x1:Release*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EPB_SwtPosn, Data);
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_A07) // (defined SWC_IPC_PROJECT_TYPE_B02)
    		/* 按键虚拟开关：拨片换挡 */
    		Data[0] = 0;  /*0x00:No shift peddle request*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_TGSSwtReq, Data);
    		#endif

			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
			/* 雨刮间歇档位 / 灵敏度调节 */
			Data[0] = 0;  /*0x0:Sensitivity 1,R_0Ω_Slow*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSSensitivityReq_HUT, Data);
			#endif

			#if (defined SWC_IPC_PROJECT_TYPE_P03)
			/* 副驾座椅非个性化记忆 副驾非个性化记忆软开关设置 */
			Data[0] = 0;  /* 0x0:no action */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetSwt_Pass, Data);
			#endif

			#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D02)
			/* 副驾座椅非个性化记忆 副驾座椅迎宾 */
			Data[0] = 0;  /* 0x0:Disable */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_Pass, Data);
			#endif

			#if (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D01)
				// || (defined SWC_IPC_PROJECT_TYPE_P02) P02 can signle miss
			/*舒适制动*/
			Data[0] = 0;  /* 0x0:关闭 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_CSTSwt, Data);
			#endif

			#if (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D01)
			/*悬架升高请求*/
			Data[0] = 0;  /* 0x0:disable */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SuspLiftReq, Data);
			#endif

			/* 后排左侧座椅按摩设置 */
			#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
				(defined SWC_IPC_PROJECT_TYPE_D02)
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgLvlSet, Data);
			/* 按摩模式 */
			Data[0] = 0;/* 0x0:No action */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgModSet, Data);
			#endif

			/* 后排右侧座椅按摩设置 */
			#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) \
			|| (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_D02)
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgLvlSet, Data);
			/* 按摩模式 */
			Data[0] = 0;/* 0x0:No action */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgModSet, Data);
			#endif


    		/* 前排座椅迎宾 PAA*/
    		Data[0] = 0;	/* 0x0:Disable */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna, Data);

    		/* 座椅设置:后排座椅迎宾 */
    		#ifdef SWC_IPC_PROJECT_TYPE_P05
    		Data[0] = 0;  /*0x0:Disable*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_SecRow, Data);
    		#endif

    		/* 外后视镜自动折叠 */
    		Data[0] = 1;  /*0x1:Manual*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearviewFoldModSet, Data);

    		/* 车速关窗 && 闭锁关窗 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
				(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		Data[0] = 0;  /* 0x0：Close */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ClsWinSpdSet, Data);
    		Data[0] = 0;  /* 0x0：Close */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWinSet, Data);
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
				(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		/* 电动侧踏开关 */
    		Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ElecSideSteppingSysSet, Data);
    		/* 特殊模式开关 */
    		Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AllTerrainDislSet, Data);
    		/* 车顶模式开关 */
    		Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofModSet, Data);
    		#endif

			/* 启动模式 */
			#if (defined SWC_IPC_PROJECT_TYPE_A07)
			Data[0] = 0;  /* 0x0:no action */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_StartModSet, Data);
			#endif

			/* 空调加热开关 */
			#if (defined SWC_IPC_PROJECT_TYPE_A07)
			Data[0] = 0;  /* 0x0:no action */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACEAHReq_VR, Data);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACEAHReq_TC, Data);
			#endif

			/* 后排左右侧座椅 一键躺倒 */
			#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)
			Data[0] = 0;  /* 0x0:no action */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearSeatLieFlatOneBtn, Data);
			#endif

			/* 车窗短升短降 */
			#if (defined SWC_IPC_PROJECT_TYPE_P05)
			Data[0] = 0;  /* 0x0:no action */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WinShortUpShortDownSet, Data);
			#endif

			/* 空调自干燥 */
    		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
			Data[0] = 0; //0x0:Off
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoDryingSwt, Data);
    		#endif

			/* 生命体征监测 */
			#if (defined SWC_IPC_PROJECT_TYPE_P02)
			/* 临时关闭开关 */
			Data[0] = 0x1; /* 0x1:Disable */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_VMDRTmpMonFctnSet, Data);
			/* 延迟报警 */
			Data[0] = 0x1; /* 0x1:Disable */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_VMDRInitAlarmDlySet, Data);
			#endif

    		SWC_IPC_PRINT_ERROR("Restore can signal value phase 1 read vehicle config faild!");
    	}
    }

	Data[0] = 2;/*0x2:15km/h*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SpdAutoLockModSet, Data);
	Data[0] = 2;/*0x2:ON*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FlaoutUnlockSet, Data);

	/* 前雨刮 */
	Data[0] = 2;  /*0x2:long time 800ms*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoWshWipSet, Data);

	/* 灯光控制 : 节电延时时间设置 */
	Data[0] = 1;  /*0x1:5minutes*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BattSaveDelayTimeSet, Data);

	/* 灯光控制 : 顶灯延时时间设置 */
	Data[0] = 1;  /*0x1:10seconds*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DomeLmpDlyTimSet, Data);

	/* 灯光控制 : 寻车功能模式设置 */
	Data[0] = 0;  /*0x0:Horn&Light*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SeekVehSet, Data);

	/* 灯光控制 : 主动迎宾设置 */
	Data[0] = 2;  /*0x2:ON*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ApproachLampSet, Data);

	/* 前排空调显示：前排空调 HMI 显示控制 */
	#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
		(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) // All projects are supported, but currently only P03 and P05 have signals
	Data[0] = 0;  /* 0x0:No action */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACFrntHMIDis_TC, Data);
	#endif

	/* 前排/后排空调显示：前排/后排空调 HMI 显示控制 */
    #if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
		(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) // All projects are supported, but currently only P03 and P05 have signals
    Data[0] = 0;  /* 0x0:No display */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FrntRearACDispSts, Data);
    #endif

	/* 后排空调显示：后排空调 HMI 显示控制 */
	#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
		(defined SWC_IPC_PROJECT_TYPE_P02)
	Data[0] = 0;  /* 0x0:No action */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACRearHMIDis_TC, Data);
	#endif

	/* 空调加热开关 */
    #if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07) // All projects are supported, but currently only B02、B03 and A07 have signals
	Data[0] = 0;  /* 0x0:No action */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACEAHReq_TC, Data);
    #endif

    #if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)\
     || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    /* Fragrance type selection: Fragrance function switch */
    Data[0] = 1;  /* 0x1:Disable */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACFGAEnaReq_TC, Data);
    /* Fragrance type selection: Fragrance function channel selection */
    Data[0] = 0;  /* 0x0:No action */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACFGAChanTyp_TC, Data);
    /* Fragrance concentration selection */
    Data[0] = 0;  /* 0x0:No action */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACFGALvlReq_TC, Data);
    #endif

     #if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) \
     || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    /* 副驾驶侧座椅调节 */
    Data[0] = 0;  /* 0x0:Seat_Swt_Idle */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatAdjmtSwt_HUT, Data);
    #endif

    #if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
		(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    /* DWD功能开关 */
    Data[0] = 0;  /* 0x0:OFF */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DWD_WorkCmd, Data);
    #endif

	#if (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
		(defined SWC_IPC_PROJECT_TYPE_D03)
    /* 电量储备：目标电量设置 */
    Data[0] = 0;  /* 0x0:OFF */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_TgtSOCSet, Data);
    #endif

	#if (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
		(defined SWC_IPC_PROJECT_TYPE_D03)
    /* 电量储备：电量储备开关 */
    Data[0] = 0;  /* 0x0:OFF */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_HybFctnReq, Data);
    #endif

	/* 动力模式选择（PHEV） */
	#if (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
		(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P05)
	Data[0] = 1;  /* 0x1:HEV */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_HybModReq, Data);
	#endif

	/* 制动模式选择 */
	#if (defined SWC_IPC_PROJECT_TYPE_P03)
	Data[0] = 0;  /* 0x0: Normal */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BrkPedFeelSelect, Data);
	#endif

	/* 远近光自动切换 */
	#if (defined SWC_IPC_PROJECT_TYPE_B02 ) //|| (defined SWC_IPC_PROJECT_TYPE_A07) // || (defined SWC_IPC_PROJECT_TYPE_P02)
	Data[0] = 0;  /* 0x0: OFF */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoHiLowBeamSwtSts_HUT, Data);
	#endif

	/* 预测能量管理 */
	/* 自适应能量回收 */
	#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
		(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P05)
	Data[0] = 1;  /* 0x1: OFF */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ARFSwtReq, Data);
	#endif
	/* 智能电量管理 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01)
	Data[0] = 1;  /* 0x1: OFF */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SOCMngmntSwtReq, Data);
	#endif
	/* 自适应发动机启停 */
	#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
		(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P05)
	Data[0] = 1;  /* 0x1: OFF */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ASFCSwtReq, Data);
	#endif
	/* 自适应换挡 */
	#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
		(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P05)
	Data[0] = 1;  /* 0x1: OFF */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AGSSwtReq, Data);
	#endif

	/* 空气悬架模式选择软开关 */
	/* 自动便捷进出模式 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
	Data[0] = 0;  /*0x0:*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoEasyAcsReq, Data);
	#endif
	/* 举升模式 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
	Data[0] = 0;  /*0x0:*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_JackModeReq, Data);
	#endif
	/* 拖车模式 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
	Data[0] = 0;  /*0x0:*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TrailerModeReq, Data);
	#endif
	/* 脚踢开启后轴装载模式 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01)
	Data[0] = 0;  /*0x0:*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearLvlKickModReq, Data);
	#endif

	/* 洞穴时间闹钟提醒 模式座椅设置 */
	#if (defined SWC_IPC_PROJECT_TYPE_P03)
	Data[0] = 0;  /* 0x0:No_action */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairRestSetSwt, Data);
	#endif

	/* 洞穴时间闹钟提醒 模式应用状态 */
	#if (defined SWC_IPC_PROJECT_TYPE_P03)
	Data[0] = 0;  /* 0x0:No_action */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AppModeFB, Data);
	#endif

	/* 洗车模式开关 */
	#if (defined SWC_IPC_PROJECT_TYPE_A07)
	Data[0] = 0;  //0x0:OFF
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_CarWashModeReq, Data);
	#endif

	/* 模拟声浪 联动开关状态 */
	#if (defined SWC_IPC_PROJECT_TYPE_D03)
	Data[0] = 0;  /* 0x0:关闭 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IESS_MdlSwtReq, Data);
	#endif

	/* 智能温控 */
	#if (defined SWC_IPC_PROJECT_TYPE_A07)
	/* 温控区间设置 */
	Data[0] = 0;  /* 0x0:-10℃ */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_InCarTempMinSet, Data);
	Data[0] = 0x3C;  /* 0x3C:50℃ */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_InCarTempMaxSet, Data);
	/* 智能空调 */
	Data[0] = 0;  /* 0x0:off */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SmtACSwt, Data);
	/* 智能座椅通风加热 */
	Data[0] = 0;  /* 0x0:off */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SmtSeatSwt, Data);
	/* 智能方向盘加热 */
	Data[0] = 0;  /* 0x0:off */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SmtCsaSwt, Data);
	#endif

	if (0x01 == Object->RestoreType)
    {
        /* 按键背光只在恢复出厂时进行重置 */
        Data[0] = 4;/*0x4:等级5*/
        IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BackgroundLightLvlSet, Data);
    }

	/* 时钟背光设定值（中控补偿值） */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
	Data[0] = 5;  /* 0x5:ZERO */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BriCmp, Data);
	#endif

	IPC_RestoreWisdomCruise(Object);

	SWC_IPC_PRINT_INFO("Restore can signal value phase 1 work start!");
}

/**********************************************************************************************************
*Function   : IPC_OS_RestoreTxCanSignalPhase1                                                             *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : XU                                                                                          *
*                                                                                                         *
*Date       : 2022-02-15                                                                                  *
**********************************************************************************************************/
static void IPC_OS_RestoreTxCanSignalPhase1(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[1];
	//VconfigKind_Allbuffers Object->VehicleConfig;
	(void)Object;

	if (E_OK == Rte_Read_Vconfig_GetKindBuffers_AllKinds(Object->VehicleConfig))
    {
	    if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
    	{
    		(void)SWC_IPC_PRINT_DEBUG("%s", __FUNCTION__);
    		/*智能启停*/
    		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_D01) ||\
    			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
    			(defined SWC_IPC_PROJECT_TYPE_D03)
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_SMART_START_STOP_SWITCH_MEMORY_SETTING])
    		 || (2 == Object->VehicleConfig[VCONFIG_KIND_SMART_START_STOP_SWITCH_MEMORY_SETTING]))
    		{
    			Data[0] = 1; /*0x1:On*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SSSSet_HUT, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SSSSet_HUT, Data);
    		}
    		#endif

    		/* 疲劳驾驶 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || \
				(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
    	    if (1 == Object->VehicleConfig[VCONFIG_KIND_DROWSINESS_WARNING_SYSTEM])
    		{
    			Data[0] = 1;  /*0x1:On*/
    	        IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDrowsnsDetnSet, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDrowsnsDetnSet, Data);
    		}
    		#endif

    		/* 驾驶模式选择 */
    		/* 燃油(DAA) VCONFIG_KIND_FUEL */
    		/* 电机位置(CBA) VCONFIG_KIND_ELECTROMOTOR_POSITION */
    		/* 驾驶模式信号可选(ZF3) VCONFIG_KIND_DRIVING_MODE_SIGNAL_SELECT */
    		/* 驾驶模式配置字(ZA5) VCONFIG_KIND_DRIVING_MODE_OPTIONAL */
    		/* 驾驶模式配置字(ZG2) 与ZA5为互斥关系 若同时配置为真 取ZG2配置 VCONFIG_KIND_DRIVING_MODE_2 */
    		/* 驾驶模式配置字(ZQ3) VCONFIG_KIND_DRIVING_MODE_3 */
    		/* 驾驶模式记忆配置字(ZG3) VCONFIG_KIND_MEMORY_OF_DRIVING_MODE */

    		/* ESP主控的驾驶模式 */
    		if ((0 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    		||  (1 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    		|| ((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    		&&  (1 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
    		{
    			/* HUT驾驶模式软开关(中控屏) */
    			if (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_SIGNAL_SELECT])
    			{
    				#ifdef SWC_IPC_PROJECT_TYPE_B02
    				{
    					/* 驾驶模式18 ZG220 */
    					/* 驾驶模式36 ZQ336 */
    					/* 驾驶模式33 ZQ325 */
    					if ((3 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_2])
    					 || (6 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_3])
    					 || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_3]))
    					{
    						Data[0] = 0; /*0x0:Standard/Normal*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    					}
    					else
    					{
    						Data[0] = 0; /*0x0:Standard/Normal*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    					}
    				}
    				#elif defined SWC_IPC_PROJECT_TYPE_B03
    				{
    					/* 驾驶模式2  ZA520 */
    					/* 驾驶模式39 ZQ339 */
    					/* 驾驶模式37 ZQ337 */
    					if ((7 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_3])
    					 || (9 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_3])
    					 || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_OPTIONAL]))
    					{
    						Data[0] = 0; /*0x0:Standard/Normal*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    					}
    					else
    					{
    						Data[0] = 0; /*0x0:Standard/Normal*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    					}
    				}
    				#elif defined SWC_IPC_PROJECT_TYPE_A07
    				{
    					/* 驾驶模式2  ZA520 */
    					/* 驾驶模式39 ZQ339 */
    					/* 驾驶模式37 ZQ337 */
    					if (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_OPTIONAL])
    					{
    						Data[0] = 0; /*0x0:Standard/Normal*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    					}
    					else
    					{
    						Data[0] = 0; /*0x0:Standard/Normal*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    					}
    				}
    				#elif defined SWC_IPC_PROJECT_TYPE_P05
    				{
    					/* 驾驶模式25 ZG275 */
    					/* DO NOTHING */
    				}
    				#endif
    			}
    			else
    			{
    				#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    				Data[0] = 0; /*0x0:Standard/Normal*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    				#endif
    			}
    		}
    		else if (((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    		       && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
    			  || ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    			   && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
    		{
    			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    			Data[0] = 0; /*0x0:Standard/Normal*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    			#endif

    			/* HCU主控的驾驶模式(无驾驶模式记忆开关) */
    			if (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_SIGNAL_SELECT])
    			{
    				/* HUT驾驶模式软开关(中控屏) */
    				#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_D02)\
						|| (defined SWC_IPC_PROJECT_TYPE_P01)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    				{
    					if (0 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_2])
    					{
    						Data[0] = 0; /*0x0:Auto/Normal*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_DrvModReq, Data);
    					}
    					else
    					{
    						Data[0] = 0; /*0x0:Auto/Normal*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_DrvModReq, Data);
    					}
    				}
    				#endif
    			}
    			else
    			{
    				#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_D02) \
						|| (defined SWC_IPC_PROJECT_TYPE_P01)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    				Data[0] = 0; /*0x0:Auto/Normal*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_DrvModReq, Data);
    				#endif
    			}
    		}
    		else
    		{
    			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    			Data[0] = 0; /*0x0:Standard/Normal*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    			#endif

    			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_D02)\
					|| (defined SWC_IPC_PROJECT_TYPE_P01)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    			Data[0] = 0; /*0x0:Standard/Normal*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_DrvModReq, Data);
    			#endif

    			SWC_IPC_PRINT_WARNING("No correct configuration for drive mode were detected");
    		}

    		/* 方向盘助力模式 */
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_SYSTEM])
    		{
    			Data[0] = 0; /*0x0:Comfort Mode*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 3; /*0x3:NO Hut Control*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    		}

    		/* 无线充电开关 */
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_WIRELESS_POWER_CHARGER]) ||
    			(2 == Object->VehicleConfig[VCONFIG_KIND_WIRELESS_POWER_CHARGER]) ||
				(3 == Object->VehicleConfig[VCONFIG_KIND_WIRELESS_POWER_CHARGER]) ||
				(4 == Object->VehicleConfig[VCONFIG_KIND_WIRELESS_POWER_CHARGER]) ||
				(5 == Object->VehicleConfig[VCONFIG_KIND_WIRELESS_POWER_CHARGER]))
    		{
    			Data[0] = 3; /*0x3:Open*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WPC_SwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 2; /*0x2:Close*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WPC_SwtReq, Data);
    		}

    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    		 || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
    		if(2 == Object->VehicleConfig[VCONFIG_KIND_WIRELESS_POWER_CHARGER])
    		{
    			Data[0] = 3; /*0x3:Open*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RWPC_SwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 2; /*0x2:Close*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RWPC_SwtReq, Data);
    		}
    		#endif

    		/* WHUD */
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_HEAD_UP_DISPLAY])
    		{
    			Data[0] = 2; /*0x2:On*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_SwtReq, Data);
    			Data[0] = SWC_WHUD_DEFAULT_BACKLIGHT_LEVEL; /*0x5:亮度调节*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_BrightnessLvlSwt, Data);
    			Data[0] = SWC_WHUD_DEFAULT_HIGHT_LEVEL; /*0xB:高度调节*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_HeightLvlSwt, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:No Action*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_SwtReq, Data);
    			Data[0] = 0; /*0x0:No action*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_BrightnessLvlSwt, Data);
    			Data[0] = 0; /*0x0:No action*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_HeightLvlSwt, Data);
    		}

    		/* 主驾驶座椅按摩设置 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
    			(defined SWC_IPC_PROJECT_TYPE_P01)
    		if (((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]))
		     && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgLvlSet, Data);
    			Data[0] = 1; /*0x1:Wave Mode*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgModSet, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgLvlSet, Data);
    			Data[0] = 0; /*0x0:No Action*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgModSet, Data);
    		}
    		#endif

    		/* 主驾驶座椅腰托设置 */
    		#if 0 //SWC_IPC_PROJECT_TYPE_B03
    	    if (((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WAIST_SUPPORTER]) ||
                (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WAIST_SUPPORTER])) &&
                (2 == Object->VehicleConfig[VCONFIG_KIND_WAIST_SUPPORTER_SWITCH_TYPE]))
    	    {
    			Data[0] = 0; /*0x0:NO Action*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatSupportPosnSwt, Data);
    	    }
    	    else
    	    {
    			Data[0] = 0; /*0x0:NO Action*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatSupportPosnSwt, Data);
    	    }
    		#endif

    		/* 主驾座椅记忆 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03)\
    		 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
    		 	(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
    		 	(defined SWC_IPC_PROJECT_TYPE_P01)
    		if (((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (4 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (6 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (7 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (8 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
    		  && ((1 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE])
			  || (5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE])))
    		{
    			Data[0] = 0; /*0x0:No Command*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSet, Data);
    			Data[0] = 0; /*0x0:FactoryDefault*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, Data);
    		}
    		else
    	  	{
    			Data[0] = 0; /*0x0:No Command*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSet, Data);
    			Data[0] = 0; /*0x0:FactoryDefault*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, Data);
    	  	}
    		#endif

    		/* 座椅非个性化设置 PAA ZM2*/
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03)\
    		 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
    		 	(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
    		 	(defined SWC_IPC_PROJECT_TYPE_P01)
    		if (((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (4 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (6 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (7 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		  || (8 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
    		  && ((4 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE])
    		   || (5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE])))
    		{
    			Data[0] = 0; /*0x0:No Command*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetSwt, Data);
    		}
    		else
    	  	{
    			Data[0] = 0; /*0x0:No Command*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetSwt, Data);
    	  	}
    		#endif

    		/* 后背门感应开启 */
    		#if (defined SWC_IPC_PROJECT_TYPE_A07)
    		if (3 == Object->VehicleConfig[VCONFIG_KIND_RR_DOOR_OPENING])/*3:感应式电动后背门*/
    		{
    			Data[0] = 1; /*0x1:On*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HFASwtSts, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HFASwtSts, Data);
    		}
    		#endif

    		/* 后背门开启高度 */
    		//ZY0 Byte 100  bit 1-0
    		#if (defined SWC_IPC_PROJECT_TYPE_A07)
    		/*1：有后背门高度调节虚拟开关*/
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_TAILGATE_ADJ_VIRTUAL_SW])
    		{
    			Data[0] = 1; /*0x1:level1*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PLG_HeightSet, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:user define*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PLG_HeightSet, Data);
    		}
    		#endif

    		/* 碰撞安全辅助系统制动 */
    		if ((3 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
    		  || (4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
    		  || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
    		{
    			Data[0] = 1; /*0x1:On*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_VehSwtReq, Data);

    			/* 紧急转向辅助 */
    			if (1 == Object->VehicleConfig[VCONFIG_KIND_EMERGENCY__STEERING_SUPPORT])
    			{
    				Data[0] = 0; /*0x0:Off*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_VehSwtReq, Data);
    			}
    			else
    			{
    				Data[0] = 0; /*0x0:Off*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_VehSwtReq, Data);
    			}
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_VehSwtReq, Data);
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_VehSwtReq, Data);
    		}

    		/* 交叉路口辅助 */
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_AEB_JUNCTION_ASSIST])
    		{
    			Data[0] = 1; /*0x1:On*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_JASwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_JASwtReq, Data);
    		}

    		/* 前横穿侧向警告 */
			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK])
    		 || (2 == Object->VehicleConfig[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK]))
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCTASwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCTASwtReq, Data);
    		}
			#endif

    		/* 前横穿侧向制动 */
			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		if (2 == Object->VehicleConfig[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK])
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCTABrkSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCTABrkSwtReq, Data);
    		}
			#endif

    		/*前碰撞预警灵敏度*/
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
    		 || (4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
    		 || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
    		{
    			Data[0] = 0; /*0x0:Normal*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCW_SnvtySet, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Normal*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCW_SnvtySet, Data);
    		}

    		/* Automatic emergency steering */
    		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_P01)\
    		 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_AUTO_EVASIVE_STEERING])
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AESSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AESSwtReq, Data);
    		}
    		#endif

    		/* 车道辅助功能 */
    		if ((1 <= Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 && (13 >= Object->VehicleConfig[VCONFIG_KIND_LDW_LKA]))
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LSSSwtReq, Data);

    			/* 预警灵敏度 */
    			Data[0] = 0; /*0x0:Normal*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IFC_SnvtySet, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LSSSwtReq, Data);

    			Data[0] = 0; /*0x0:Normal*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IFC_SnvtySet, Data);
    		}

    		/* 车道辅助 : 预警辅助 */
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (2 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
			 || (4 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (7 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (8 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (9 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (10 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (11 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA]))
    		{
    			Data[0] = 1; /*0x0:On*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LDWSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LDWSwtReq, Data);
    		}

    		/* 车道辅助 : 保持辅助 */
    		if ((2 <= Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 && (13 >= Object->VehicleConfig[VCONFIG_KIND_LDW_LKA]))
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LKASwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LKASwtReq, Data);
    		}

    		#if 0
    		/* 车道辅助 : 居中辅助 */
    		if ((3 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (4 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (5 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (6 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (7 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (8 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA]))
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCKSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCKSwtReq, Data);
    		}
    		#endif

    		/* 车道辅助 : 紧急车道保持 */
    		if ((4 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (5 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (8 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
			 || (9 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
			 || (11 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
			 || (13 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA]))
    		{
                if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
                {
                    /* 国内 */
                    Data[0] = 0; /*0x0:Off*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ELKSwtReq, Data);
                }
                else
                {
                    /* 国外 */
    				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
                    Data[0] = 1; /*0x1:On*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ELKSwtReq, Data);
    				#endif
                }
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ELKSwtReq, Data);
    		}

    		/* 车道辅助 : 智慧躲闪 */
    		if ((7 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
    		 || (8 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
			 || (10 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
			 || (11 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA]))
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IntelligentEvaSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IntelligentEvaSwtReq, Data);
    		}

    		/* 车道辅助 : 预警方式 */
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_HAPTIC_REMINDER_OF_ENHANCED_ASSIET_SYSTEMS])
    		{
    			Data[0] = 0; /*0x0:Voice*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LSSWarnFormSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Voice*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LSSWarnFormSwtReq, Data);
    		}

    		/* 侧后辅助系统 : 并线辅助 */
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_LANE_CHANGE_ASSIST])
    		{
                if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
                {
                    /* 国内 */
                    Data[0] = 0; /*0x0:Off*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCASwtReq, Data);
                }
                else
                {
                    /* 国外 */
    				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
                    Data[0] = 1; /*0x1:On*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCASwtReq, Data);
    				#endif
                }
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCASwtReq, Data);
    		}

    		/* 侧后辅助系统 :       开门预警 */
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_DR_OPEN_WARNING])
    		{
                if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
                {
                    /* 国内 */
                    Data[0] = 0; /*0x0:Off*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DOWSwtReq, Data);
                }
                else
                {
                    /* 国外 */
    				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
                    Data[0] = 1; /*0x1:On*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DOWSwtReq, Data);
    				#endif
                }
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DOWSwtReq, Data);
    		}

    		/* 侧后辅助系统 :       后碰撞预警 */
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_REAR_COLLISION_WARNING])
    		{
                if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
                {
                    /* 国内 */
                    Data[0] = 0; /*0x0:Off*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCWSwtReq, Data);
                }
                else
                {
                    /* 国外 */
    				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
                    Data[0] = 1; /*0x1:On*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCWSwtReq, Data);
    				#endif
                }
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCWSwtReq, Data);
    		}

    		/* 侧后辅助系统 : 倒车侧向警告 */
    		if ((2 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA])
             || (4 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA]))
    		{
    			if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
                {
                    /* 国内 */
                    Data[0] = 0; /*0x0:Off*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTASwtReq, Data);
                }
                else
                {
                    /* 国外 */
    				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
                    Data[0] = 1; /*0x1:On*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTASwtReq, Data);
    				#endif
                }
    		}
            else
            {
                Data[0] = 0; /*0x0:Off*/
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTASwtReq, Data);
            }

    		/* 侧后辅助系统 : 倒车侧向制动 */
    		if (4 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA])
    	 	{
                if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
                {
                    /* 国内 */
                    Data[0] = 0; /*0x0:Off*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTABrkSwtReq, Data);
                }
                else
                {
                    /* 国外 */
    				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
                    Data[0] = 1; /*0x1:On*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTABrkSwtReq, Data);
    				#endif
                }
    	 	}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTABrkSwtReq, Data);
    		}

    		/* 交通标志信息 : 交通标志识别 */
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
    		 || (2 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
    		 || (4 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING]))
    		{
                if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
                {
                    /* 国内 */
                    Data[0] = 0; /*0x0:Off*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSRSwtReq, Data);
                }
                else
                {
                    /* 国外 */
    				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
                    Data[0] = 1; /*0x1:On*/
    			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSRSwtReq, Data);
    				#endif
                }
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSRSwtReq, Data);
    		}

    		/* 交通标志信息 : 超速报警 */
    		if ((2 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING]))
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSRWarnSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSRWarnSwtReq, Data);
    		}

    		/* 交通标志信息 : 巡航车速限制 */
    		if ((3 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
    		 || (4 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING]))
    		{
                Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ISLSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ISLSwtReq, Data);
    		}

    		/* 交通标志信息 : 超速报警灵敏度 */
    		if ((2 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING]))
    		{
    			Data[0] = 0x0F; /*0x0:0km/h*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSR_SnvtySet, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSR_SnvtySet, Data);
    		}

			#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02)
			/* 交通标志信息 : 导航降速 */
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_NAVIGATION_SLOWDOWN])
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NavDecSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NavDecSwtReq, Data);
    		}
			#endif

    		/* 灯光控制 : 照我回家延时时间设置 */
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_HEAD_LAMP_AUTO_OFF])
    		{
    			Data[0] = 1; /*0x1:30seconds*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FolwMeHomeDlyTimSet, Data);
    		}
    		else
            {
                Data[0] = 0; /*0x0:0seconds*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FolwMeHomeDlyTimSet, Data);
            }

    		/* 灯光控制 : 运动模式灯光设置 */
    		// #if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		//  || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_D03)
			#if 0
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_SPORTS_MODE_LIGHTING_PROMPT_S_REPEATER])
    		{
    			Data[0] = 1; /*0x1:Flashing&Light*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SportModLightSet, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:OFF*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SportModLightSet, Data);
    		}
    		#endif

    		/* 泊车控制 : 前向泊车辅助系统功能 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || \
				(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P01)
    		{
    			if (((3 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    			 || (4 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    			 || (5 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		     || (6 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
				 || (7 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
    		     || (0 != Object->VehicleConfig[VCONFIG_KIND_FRONT_SENSOR]))
    			{
    				/* HAP ECU PAS ECU */
    				/* HAP_FD3 CANFD 0x298, High priority */
    				/* FPAS1 CAN 0x26D */
    				if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_HAP_FD3, SWC_IPC_NULL))
    				{
    					#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03)|| \
							(defined SWC_IPC_PROJECT_TYPE_P01)
    					IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FPAS_AutoModSts, Data);
    					#else
    					IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FPAS_AutoModSts_0x298 , Data);
    					#endif
    					/*Target: On*/
    					if (0 == Data[0]) /*0x0:Off*/
    					{
    						Data[0] = 1; /*0x1:Request*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FPAS_AutoModSwt, Data);
    					}
    				}
    				#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    				else if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_FPAS1, SWC_IPC_NULL))
    				{
    					IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FPAS_AutoModSts_0x26D , Data);
    					/*Target: On*/
    					if (0 == Data[0]) /*0x0:Off*/
    					{
    						Data[0] = 1; /*0x1:Request*/
    						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FPAS_AutoModSwt, Data);
    					}
    				}
    				#endif
    				else
    				{
    					Data[0] = 0; /*0x0:No Request*/
    					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FPAS_AutoModSwt, Data);
    				}
    			}
    			else
    			{
    				Data[0] = 0; /*0x0:No Request*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FPAS_AutoModSwt, Data);
    			}
    		}
    		#endif

    		/* 泊车控制 : 自动紧急制动系统功能 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || \
				(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
				(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
				(defined SWC_IPC_PROJECT_TYPE_P01)
    		if (((3 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (4 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (5 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    	     || (6 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
			 || (7 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
    	     || (0 != Object->VehicleConfig[VCONFIG_KIND_REAR_PAS_SENSOR]))
    		{
    			/* HAP ECU */
    			/* HAP_FD3 CANFD 0x298, High priority */
    			/* RPAS1 CAN 0x26E */
    			if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_HAP_FD3, SWC_IPC_NULL))
    			{
    				#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03)\
    				 || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
					 	(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
    				IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MEB_EnableSts, Data);
    				#else
    				IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MEB_EnableSts_0x298, Data);
    				#endif
    				if (0 == Data[0])
    				{
    					Data[0] = 1; /*0x1:Request*/
    					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MEBSwtSet, Data);
    				}
    			}
    			#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    			else if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_RPAS1, SWC_IPC_NULL))
    			{
    				IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MEB_EnableSts_0x26E , Data);
    				if (0 == Data[0])
    				{
    					Data[0] = 1; /*0x1:Request*/
    					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MEBSwtSet, Data);
    				}
    			}
    			#endif
    			else
    			{
    				Data[0] = 0; /*0x0:No Request*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MEBSwtSet, Data);
    			}
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:No Request*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MEBSwtSet, Data);
    		}
    		#endif

    		/* 360环视 : 侧翼保护功能 */
    		if ((3 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (4 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (5 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    	     || (6 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
			 || (7 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
    		{
    			/*HAP ECU*/
    			if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_HAP_FD3,SWC_IPC_NULL))
    			{
					#if (defined SWC_IPC_PROJECT_TYPE_A07)
					IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SDWActiveSts_0x298, Data);
					#else
    				IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SDWActiveSts, Data);
					#endif
    				if (0 == Data[0])
    				{
    					Data[0] = 1; /*0x1:Request*/
    					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SDWSwtSet, Data);
    				}
    			}
    		}
    		else
    	 	{
    			Data[0] = 0; /*0x0:No Request*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SDWSwtSet, Data);
    	 	}

    		/* 360环视 : 自动转向 */
    		if ((3 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (4 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (5 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (6 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
			 || (7 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (0 != Object->VehicleConfig[VCONFIG_KIND_OMNIVIEW_SYSTEM]))
    		{
    			/*HAP ECU*/
    			if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_HAP_FD2,SWC_IPC_NULL))
    			{
    				IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoAVMSwtSet_Sts, Data);
    				if (0 == Data[0])
    				{
    					Data[0] = 1; /*0x1:Request*/
    					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoAVMSwSet_Cmd, Data);
    				}
    			}
    		}
    		else
    	 	{
    			Data[0] = 0; /*0x0:No Request*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoAVMSwSet_Cmd, Data);
    	 	}

    		/* 360环视 */
    		if ((0 != Object->VehicleConfig[VCONFIG_KIND_OMNIVIEW_SYSTEM])
    		|| (0 != Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
    		{
    			/* 360环视 : 环视退出车速值设置 */
    			Data[0] = 1; /*0x1:15km/h*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PASExitSpdSwt, Data);

    			#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || \
				(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    			/* 360环视 : 道路标定 */
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LaneCalActvtCmd, Data);

    			/* 360环视 : 恢复出厂标定 */
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SwToFieldCalRstCmd, Data);
    			#endif

    			/* 360环视 : 手动开启环视 */
    			Data[0] = 1; /*0x1:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PASSwtReq_VR, Data);
    		}
    		else
            {
            	/* 360环视 : 环视退出车速值设置 */
                Data[0] = 0; /*0x0:No command*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PASExitSpdSwt, Data);

    			#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || \
				(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    			/* 360环视 : 道路标定 */
                Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LaneCalActvtCmd, Data);

    			/* 360环视 : 恢复出厂标定 */
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SwToFieldCalRstCmd, Data);
    			#endif

    			/* 360环视 : 手动开启环视 */
    			Data[0] = 0; /*0x0:No action*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PASSwtReq_VR, Data);
            }

			/* D档低速开启360环视 */
			#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
			if(1 == Object->VehicleConfig[VCONFIG_KIND_OMNIVIEW_AUTO_TURN_ON_AT_LOW_SPEED])
			{
				Data[0] = 1; /*0x1:Open*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AVMAutoSet, Data);
			}
			else
			{
				Data[0] = 0; /*0x0:Disable*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AVMAutoSet, Data);
			}
			#endif

    		/* 门锁设置 : 超级锁设置 */
    		#if 0
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_SUPER_LOCK])
    		{
    			Data[0] = 1;  /*0x1:OFF*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SuperLockSet, Data);
    		}
    		else
            {
                Data[0] = 0;  /*0x0:No action*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SuperLockSet, Data);
            }
    		#endif

    		/* Parking lights */
    		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) ||\
				(defined SWC_IPC_PROJECT_TYPE_P05)
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_PARKING_LAMP])
    		{
    			Data[0] = 1; /*0x1:On*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ParkLmpSet, Data);
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ParkLmpSet, Data);
    		}
    		#endif

    		/* ESP */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		{
    			if (1 == Object->VehicleConfig[VCONFIG_KIND_ESP_SWITCH_TYPE])
    			{
    				Data[0] = 0;/*0x0:Not Pressed*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_ESPFuncOffSwtSts, Data);
    			}
    			else
    			{
    				Data[0] = 1;/*0x1:Pressed*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_ESPFuncOffSwtSts, Data);
    			}
    		}
    		#endif

    		/* 行人安全辅助系统 */
    		if ((4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
    		 || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
    		{
    			Data[0] = 1; /*0x1:On*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_PedSwtReq, Data);

    			/* 紧急转向辅助 */
    			if (1 == Object->VehicleConfig[VCONFIG_KIND_EMERGENCY__STEERING_SUPPORT])
    			{
    				Data[0] = 0; /*0x0:Off*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_PedSwtReq, Data);
    			}
    			else
    			{
    				Data[0] = 0; /*0x0:Off*/
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_PedSwtReq, Data);
    			}
    		}
    		else
    		{
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_PedSwtReq, Data);
    			Data[0] = 0; /*0x0:Off*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_PedSwtReq, Data);
    		}

    		/* 外后视镜倒车模式 KAG*/
    		if ((4 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]) || (5 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]))
    		{
    			Data[0] = 2;  /* 0x2:Bothsideenable */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_OrvmPosnEnaSts, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_OrvmPosnEnaSts, Data);
    		}

    		/* 外后视镜角度调节 KAG*/
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05)\
    			|| (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) ||\
				 (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		if ((0 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    		 ||	(1 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    	     || (2 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    	     || (3 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    	     || (4 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]))
    		{
    			Data[0] = 0;  /* 0x0:Mir_Swt_Idle */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ORVMLensAdjmt_HUT, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0:Mir_Swt_Idle */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ORVMLensAdjmt_HUT, Data);
    		}
    		#endif

    		/* 洗车拖车模式激活 CBA */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03)
    		// || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P03)
    		if (((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    	       && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
    		  || ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    		   && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
    		{
    			Data[0] = 0;  /* 0x0:CarWashModeOFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_CarWashMode_Req, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0:CarWashModeOFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_CarWashMode_Req, Data);
    		}
    		#endif

    		/* 涉水模式 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03)\
    		 || (defined SWC_IPC_PROJECT_TYPE_D01)|| (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		if (((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    	       && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
    		  || ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    		   && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
    		{
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_WadeModeSet, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_WadeModeSet, Data);
    		}
    		#endif

    		/* Save 模式下充电阈值设置(ForPHEV) DAA CBA */
    		/* DAA:VCONFIG_KIND_FUEL */
    		/* CBA:VCONFIG_KIND_ELECTROMOTOR_POSITION */
			#if 0
    		// #if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) //#ifdef SWC_IPC_PROJECT_TYPE_P03
    		if ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    		 && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
    		{
    			Data[0] = 4;  /* 0x4:50% */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattSOCLimSaveMod, Data);
    		}
    		else
    		{
    			Data[0] = 4;  /* 0x4:50% */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattSOCLimSaveMod, Data);
    		}
    		#endif

    		/* 能量回收等级设置 */
    		/* HAJ:VCONFIG_KIND_BRAKING_ENERGY_RECOVERY */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P03)\
     	    	|| (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)\
				|| (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    		if (((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    	       && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
    		  || ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
    		   && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
    		{
    			Data[0] = 1;  /* 0x1:Normal */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, Data);
    		}
    		else
    		{
    			Data[0] = 1;  /* 0x1:Normal */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, Data);
    		}
    		#endif

    		/* 氛围灯 */
			/* SAQ60:轮廓；SAQ70:面发光；SAQ80:面发光； */
			/* ZK100：无音乐律动；ZK110：ALCM/CEM解析音乐律动；ZK120：主机解析 */
			/* ZK200：无分区联动（智能联动）；ZK210：有分区联动（智能联动）； */
			/* ZQ600：无氛围灯分区开关；ZQ610：有氛围灯分区开关 */
    		/* 氛围灯及背景光(SAQ):VCONFIG_KIND_MOOD_LAMP */
    		/* 多色律动氛围灯音频解析方式(ZK1):VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP */
    		/* 氛围灯分区功能(ZK2):VCONFIG_KIND_MOOD_LAMP_PARTITION */
			/* 氛围灯分区点亮开关控制(ZQ6):VCONFIG_KIND_AMBIENT_LIGHT_CONTROL */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
    		if((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))
    		{
    			/* 氛围灯总开关 */
				#if(!defined SWC_IPC_PROJECT_TYPE_P01)
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMMasterSwt, Data);
				#endif

    			/* 氛围灯亮度 */
				#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
					(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
					(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
    			Data[0] = 5;  /* 0x5:50 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMLightLvlSet, Data);
				#endif
    		}
    		else
    		{
    			/* 氛围灯总开关 */
				#if(!defined SWC_IPC_PROJECT_TYPE_P01)
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMMasterSwt, Data);
				#endif
    			/* 氛围灯亮度 */
				#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
					(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
					(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
    			Data[0] = 5;  /* 0x5:50 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMLightLvlSet, Data);
				#endif
    		}
    		#endif

			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
				(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)//|| (defined SWC_IPC_PROJECT_TYPE_A07)
			if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP])))
    		{
    			/* 轮廓氛围灯颜色选择 */
    			Data[0] = 2;  /* 0x2:极光白 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet, Data);
    			/* 轮廓氛围灯多色彩静态 */
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt, Data);
    			/* 轮廓氛围灯多色彩动态 */
    			Data[0] = 0;  /* 0x0:DynModOFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet, Data);
    		}
    		else
    		{
    			/* 轮廓氛围灯颜色选择 */
    			Data[0] = 2;  /* 0x2:极光白 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet, Data);
    			/* 轮廓氛围灯多色彩静态 */
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt, Data);
    			/* 轮廓氛围灯多色彩动态 */
    			Data[0] = 0;  /* 0x0:DynModOFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet, Data);
    		}
    		#endif

			#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) \
				// ||(defined SWC_IPC_PROJECT_TYPE_A07)
    		if((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))
    		{
				/* 轮廓氛围灯呼吸灯 */
				Data[0] = 0;  /* 0X0：OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt, Data);
			}
			else
			{
				/* 轮廓氛围灯呼吸灯 */
				Data[0] = 0;  /* 0X0：OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt, Data);
			}
			#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) ||\
				(defined SWC_IPC_PROJECT_TYPE_D01)
    		if((6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))
    		{
    			/* 面发光氛围灯流水灯设置 */
    			Data[0] = 0;  /* 0X0：OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMFloSwt, Data);
    			/* 面发光氛围灯颜色选择 */
    			Data[0] = 2;  /* 0X2：极光白 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet_OLE, Data);
    			/* 面发光氛围灯多色彩静态模式 */
    			Data[0] = 0;  /* 0X2：OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt_OLE, Data);
    			/* 面发光氛围灯多色彩动态模式 */
    			Data[0] = 0;  /* 0x0:DynModOFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet_OLE, Data);
    			/* 面发光氛围灯呼吸灯设置 */
				Data[0] = 0;  /* 0X0：OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt_OLE, Data);
    			/* 面发光氛围灯流水灯设置 */
    			Data[0] = 3;  /* 0x3:极光白 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr1, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr2, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr3, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr4, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr5, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr6, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr7, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr8, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr9, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr10, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr11, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr12, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr13, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr14, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr15, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr16, Data);
    		}
    		else
    		{
				Object->AppNvm.MultiColorNrFlag = FALSE;
    			/* 面发光氛围灯流水灯设置 */
    			Data[0] = 0;  /* 0X0：OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMFloSwt, Data);
    			/* 面发光氛围灯颜色选择 */
    			Data[0] = 2;  /* 0X2：极光白 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet_OLE, Data);
    			/* 面发光氛围灯多色彩静态模式 */
    			Data[0] = 0;  /* 0X2：OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt_OLE, Data);
    			/* 面发光氛围灯多色彩动态模式 */
    			Data[0] = 0;  /* 0x0:DynModOFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet_OLE, Data);
    			/* 面发光氛围灯呼吸灯设置 */
				Data[0] = 0;  /* 0X0：OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt_OLE, Data);
    			/* 面发光氛围灯流水灯设置 */
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr1, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr2, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr3, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr4, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr5, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr6, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr7, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr8, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr9, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr10, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr11, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr12, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr13, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr14, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr15, Data);
    			Data[0] = 0;  /* 0x0:No command */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr16, Data);
    		}
    		#endif
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) //|| (defined SWC_IPC_PROJECT_TYPE_A07)
    		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
    		 && ((1 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP]) || (2 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP])))
    		{
    			/* 轮廓氛围灯音乐律动 */
    			Data[0] = 1;  /* 0x1:On */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMRhmSwt, Data);

				#if (!defined SWC_IPC_PROJECT_TYPE_P01)
				Data[0] = 0x65;  /* 0x65:Noaction */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq0, Data);
				Data[0] = 0x65;  /* 0x65:Noaction */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq1, Data);
				Data[0] = 0x65;  /* 0x65:Noaction */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq2, Data);
				Data[0] = 0x65;  /* 0x65:Noaction */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq3, Data);
				Data[0] = 0x65;  /* 0x65:Noaction */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq4, Data);
				Data[0] = 0x65;  /* 0x65:Noaction */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq5, Data);
				Data[0] = 0x65;  /* 0x65:Noaction */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq6, Data);
				#endif
    		}
    		else
    		{
    			/* 轮廓氛围灯音乐律动 */
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMRhmSwt, Data);
				#if (!defined SWC_IPC_PROJECT_TYPE_P01)
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq0, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq1, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq2, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq3, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq4, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq5, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq6, Data);
				#endif
    		}
    		#endif

			#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) ||\
				(defined SWC_IPC_PROJECT_TYPE_D01)
			if(((6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
    		 && ((1 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP]) || (2 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP])))
    		{
				/* 面发光氛围灯音乐随动 */
				Data[0] = 1;  /* 0x1:On */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMRhmSwt_OLE, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq0, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq1, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq2, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq3, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq4, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq5, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq6, Data);
			}
			else
			{
				/* 面发光氛围灯音乐随动 */
				Data[0] = 1;  /* 0x1:On */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMRhmSwt_OLE, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq0, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq1, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq2, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq3, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq4, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq5, Data);
    			Data[0] = 0x65;  /* 0x65:Noaction */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq6, Data);
			}
			#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
    		 && (1 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP_PARTITION]))
    		{
    			/* 氛围灯联动:联动开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMPartitionSwt, Data);
    		}
    		else
    		{
    			/* 氛围灯联动:联动开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMPartitionSwt, Data);
    		}
    		#endif

			#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
				(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
    		 && (1 == Object->VehicleConfig[VCONFIG_KIND_AMBIENT_LIGHT_CONTROL]))
    		{
    			/* 分区开关:左侧仪表板氛围灯开关 */
    			Data[0] = 1;  /* 0X1： ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LeftPanelALCMSwt, Data);
    			/* 分区开关：右侧仪表板氛围灯开关 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RightPanelALCMSwt, Data);
    			/* 分区开关：主驾氛围灯开关 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDoorALCMSwt, Data);
    			/* 分区开关：副驾氛围灯开关 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassDoorALCMSwt, Data);
    			/* 分区开关：左后门氛围灯开关 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LRDoorALCMSwt, Data);
    			/* 分区开关：右后门氛围灯开关 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRDoorALCMSwt, Data);
    			/* 分区开关：脚窝氛围灯开关 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FootALCMSwt, Data);
    			/* 分区开关：顶棚氛围灯开关 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofALCMSwt, Data);
    		}
    		else
    		{
    			/* 分区开关:左侧仪表板氛围灯开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LeftPanelALCMSwt, Data);
    			/* 分区开关:右侧仪表板氛围灯开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RightPanelALCMSwt, Data);
    			/* 分区开关:主驾门氛围灯开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDoorALCMSwt, Data);
    			/* 分区开关:副驾门氛围灯开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassDoorALCMSwt, Data);
    			/* 分区开关:左后门氛围灯开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LRDoorALCMSwt, Data);
    			/* 分区开关:右后门氛围灯开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRDoorALCMSwt, Data);
    			/* 分区开关:脚窝灯开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FootALCMSwt, Data);
    			/* 分区开关:顶棚氛围灯开关 */
    			Data[0] = 0;  /* 0X0： OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofALCMSwt, Data);
    		}
    		#endif

			/* 音乐灯光秀：设置开关 */
			#if (defined SWC_IPC_PROJECT_TYPE_B02)
			if(1 == Object->VehicleConfig[VCONFIG_KIND_MUSIC__LIGHT_SHOW])
    		{
				Data[0] = 1;  /* 0x1:OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicLightShowSet, Data);
			}
			else
			{
				Data[0] = 1;  /* 0x1:OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicLightShowSet, Data);
			}
			#endif

    		/* 解闭锁提示 */
		    #if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				(defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		if(1 == Object->VehicleConfig[VCONFIG_KIND_BLOCKING_PROMPT_TYPE])
    		{
    			Data[0] = 2;  /* 0x2:LightOnly */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockPromptFunSet, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0:Light&Horn */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockPromptFunSet, Data);
    		}
    		#endif

    		/* 蓝牙泊车 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P01)
    		if ((4 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (5 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
    		 || (6 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 	 || (7 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
    		{
    			/* 蓝牙泊入自动闭锁 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPAEntryLockSet, Data);
    			/* 蓝牙泊出自动解锁 */
    			Data[0] = 1;  /* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPALvngUnlockSet, Data);
    		}
    		else
    		{
    			/* 蓝牙泊入自动闭锁 */
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPAEntryLockSet, Data);
    			/* 蓝牙泊出自动解锁 */
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPALvngUnlockSet, Data);
    		}
    		#endif

    		/* 解锁模式 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_DOOR_UNLOCK_MODE])
    		{
    			Data[0] = 0;/*0x0:All Door*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DoorUnlockModSet, Data);
    		}
    		else
    		{
    			Data[0] = 0;/*0x0:All Door*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DoorUnlockModSet, Data);
    		}
    		#endif

    		/* DST */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
    			(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_DYNAMIC_STEERING_TORQUE])
    		{
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DSTSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DSTSwtReq, Data);
    		}
    		#endif

    		/* 驾驶模式开关记忆：硬开关 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P01) \
    		 || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) \
    		 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_B02)
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_MEMORY_OF_DRIVING_MODE])
    		 && (1 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_SIGNAL_SELECT]))
    		{
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvgModeMemReq, Data);
    		}
    		else
    		{
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvgModeMemReq, Data);
    		}
    		#endif

    		/* 副驾驶座椅按摩设置 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
    			(defined SWC_IPC_PROJECT_TYPE_P01)
    		if (((1 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]))
		     && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
    		{
    			/* 按摩强度 */
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgLvlSet, Data);
    			/* 按摩模式 */
    			Data[0] = 1;/* 0x1:Wave Mode */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgModSet, Data);
    		}
    		else
    		{
    			/* 按摩强度 */
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgLvlSet, Data);
    			/* 按摩模式 */
    			Data[0] = 0;/* 0x0:No Action */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgModSet, Data);
    		}
    		#endif

    		/* 主动进入解锁 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
    			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D02)
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM]))
    		{
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryUnlockSet, Data);
    		}
    		else
    		{
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryUnlockSet, Data);
    		}
    		#endif

    		/* 主动离开闭锁 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
    			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || (defined SWC_IPC_PROJECT_TYPE_D02)
    		if ((2 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM]))
    		{
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryLockSet, Data);
    		}
    		else
    		{
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryLockSet, Data);
    		}
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)\
    		 || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)\
			 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P01)
    		/* 无感车控：天窗/遮阳帘 */
    		if ((2 == Object->VehicleConfig[VCONFIG_KIND_SUN_ROOF_SHADE_SWITCH_TYPE])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_SUN_ROOF_SHADE_SWITCH_TYPE]))
    		{
    			/* 天窗 */
    			Data[0] = 0;/* 0x0:No action */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SunRoofSwtReq_VR, Data);
    			/* 遮阳帘 */
    			Data[0] = 0;/* 0x0:No action */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SunShadeSwtReq_VR, Data);
    		}
    		else
    		{
    			/* 天窗 */
    			Data[0] = 0;/* 0x0:No action */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SunRoofSwtReq_VR, Data);
    			/* 遮阳帘 */
    			Data[0] = 0;/* 0x0:No action */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SunShadeSwtReq_VR, Data);
    		}
    		#endif

    		/* 无感车控：主驾6向调节 */
    		/* 前排座椅调节开关类型 ZP1(VCONFIG_KIND_FRT_SEAT__ADJ_SWITCH_TYPE) */
    		/* 驾驶员座椅 PAA(VCONFIG_KIND_DRIVER_SEAT) */
    		/* 副驾驶座椅 PAB(VCONFIG_KIND_PASSENGER_SEAT) */
    		/* 驾驶员座椅坐垫侧翼调节 PCJ(VCONFIG_KIND_DRIVER_SEAT_CUSHION_FLANK) */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		if (((2 == Object->VehicleConfig[VCONFIG_KIND_FRT_SEAT__ADJ_SWITCH_TYPE])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_FRT_SEAT__ADJ_SWITCH_TYPE]))
    		 && ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		 || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
    		 && ((0 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_CUSHION_FLANK])
    		 || (1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_CUSHION_FLANK])))
    		{
    			Data[0] = 0;/* 0x0:Seat_Swt_Idle */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatAdjmt_HUT, Data);
    		}
    		else
    		{
    			Data[0] = 0;/* 0x0:Seat_Swt_Idle */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatAdjmt_HUT, Data);
    		}
    		#endif

    		/* 无感车控：外后视镜折叠 */
    		/* 外后视镜 KAG(VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR) */
    		/* 后视镜折叠虚拟开关控制 ZP3(VCONFIG_KIND_OSRVM_FOLD_VIRTUAL_SW_CONTROL) */
    		// #if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05)
            #if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B02)  || (defined SWC_IPC_PROJECT_TYPE_P03)\
    			|| (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		if (((1 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    		 || (2 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    		 || (3 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    		 || (4 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]))
    		 && (1 == Object->VehicleConfig[VCONFIG_KIND_OSRVM_FOLD_VIRTUAL_SW_CONTROL]))
    		{
    			Data[0] = 0;/* 0x0:None */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ORVMFoldSwt_HUT, Data);
    		}
    		else
    		{
    			Data[0] = 0;/* 0x0:None */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ORVMFoldSwt_HUT, Data);
    		}
    		#endif

    		/* 越野模式：专家模式 */
    		/* 项目代码 AAA(VCONFIG_KIND_PROJECT_CODE) */
    		/* 变速器 EAA(VCONFIG_KIND_TRANSMISSION) */
    		/* 减震器 GAD(VCONFIG_KIND_DAMPER) */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05)
    		if (0x45u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
				#if 0
				Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
				#endif
    			/* 转向模式 / 方向盘助力模式 */
    			if ((0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT]) || (1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_SYSTEM]))
    			{
    				Data[0] = 0;/* 0x0: 舒适 */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3:NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			/* ESC设置 */
    			Data[0] = 0;/* 0x0: ALL_ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    		}
    		else
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			/* ESC设置 */
    			Data[0] = 2;/* 0x2: ALL_OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    		}
    		#elif (defined SWC_IPC_PROJECT_TYPE_P03)
    		if ((0x47u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]) || (0x48u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]) \
    		||  (0x49u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]))
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* 转向模式 */
    			if ((0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT]) || (1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_SYSTEM]))
    			{
    				Data[0] = 0;/* 0x0: 舒适 */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3:NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			/* ESC设置 */
    			Data[0] = 0;/* 0x0: ALL_ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
					((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
    			{
    				Data[0] = 1;/* 0x1: Comfort */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3: NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    		}
    		else
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* ESC设置 */
    			Data[0] = 2;/* 0x2: ALL_OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			Data[0] = 3;/* 0x3: NO Hut Control */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    		}
    		#elif (defined SWC_IPC_PROJECT_TYPE_P02)
    		if (0x34u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* 转向模式 */
    			if ((0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT]) || (1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_SYSTEM]))
    			{
    				Data[0] = 0;/* 0x0: 舒适 */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3:NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			/* ESC设置 */
    			Data[0] = 0;/* 0x0: ALL_ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
					((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
    			{
    				Data[0] = 1;/* 0x1: Comfort */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3: NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    		}
    		else
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* ESC设置 */
    			Data[0] = 2;/* 0x2: ALL_OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			Data[0] = 3;/* 0x3: NO Hut Control */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    		}
    		#elif (defined SWC_IPC_PROJECT_TYPE_D01)
    		if (0x37u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* 转向模式 */
    			if ((0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT]) || (1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_SYSTEM]))
    			{
    				Data[0] = 0;/* 0x0: 舒适 */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3:NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			/* ESC设置 */
    			Data[0] = 0;/* 0x0: ALL_ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
					((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
    			{
    				Data[0] = 1;/* 0x1: Comfort */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3: NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    		}
    		else
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* ESC设置 */
    			Data[0] = 2;/* 0x2: ALL_OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			Data[0] = 3;/* 0x3: NO Hut Control */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    		}
    		#elif (defined SWC_IPC_PROJECT_TYPE_D02)
    		if (0x5Cu == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* 转向模式 */
    			if ((0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT]) || (1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_SYSTEM]))
    			{
    				Data[0] = 0;/* 0x0: 舒适 */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3:NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			/* ESC设置 */
    			Data[0] = 0;/* 0x0: ALL_ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
					((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
    			{
    				Data[0] = 1;/* 0x1: Comfort */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3: NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    		}
    		else
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* ESC设置 */
    			Data[0] = 2;/* 0x2: ALL_OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			Data[0] = 3;/* 0x3: NO Hut Control */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    		}
    		#elif (defined SWC_IPC_PROJECT_TYPE_D03)
    		if (0x5Eu == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* 转向模式 */
    			if ((0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT]) || (1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_SYSTEM]))
    			{
    				Data[0] = 0;/* 0x0: 舒适 */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3:NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			/* ESC设置 */
    			Data[0] = 0;/* 0x0: ALL_ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
					((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
    			{
    				Data[0] = 1;/* 0x1: Comfort */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3: NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    		}
    		else
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    			/* ESC设置 */
    			Data[0] = 2;/* 0x2: ALL_OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			Data[0] = 3;/* 0x3: NO Hut Control */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    		}
			#elif (defined SWC_IPC_PROJECT_TYPE_P01)
    		if ( (0x2Bu == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]) || (0x2Cu == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]) || \
				(0x4Eu == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]) || (0x0u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]))
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
    			//Data[0] = 0;/* 0x0: 舒适 */
    			//IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data); //信号缺失
    			/* 转向模式 */
    			if ((0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT]) || (1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_SYSTEM]))
    			{
    				Data[0] = 0;/* 0x0: 舒适 */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3:NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);
    			}
    			/* ESC设置 */
    			Data[0] = 0;/* 0x0: ALL_ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
					((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
					(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
    			{
    				Data[0] = 1;/* 0x1: Comfort */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    			else
    			{
    				Data[0] = 3;/* 0x3: NO Hut Control */
    				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    			}
    		}
    		else
    		{
    			/* 自定义界面 */
    			Data[0] = 0;/* 0x0:Not active */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    			/* 四驱模式 */
    			Data[0] = 0;/* 0x0:2H */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    			/* 驱动模式 */
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);
				#if(!defined SWC_IPC_PROJECT_TYPE_P01)
    			Data[0] = 0;/* 0x0: 舒适 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
				#endif
    			/* ESC设置 */
    			Data[0] = 2;/* 0x2: ALL_OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);
    			/* 悬架设置 */
    			Data[0] = 3;/* 0x3: NO Hut Control */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    		}
    		#endif

    		/* 货箱照明设置(皮卡) */
    		#if defined SWC_IPC_PROJECT_TYPE_P05
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_DECK_LAMP])
    		{
    			/* 货箱灯开关设置 */
    			Data[0] = 1;  /* 0x1:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FreightLmptSwt, Data);
    			/* 货厢灯自动开启功能 */
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FreightLmpAutoSet, Data);
    		}
    		else
    		{
    			/* 货箱灯开关设置 */
    			Data[0] = 0;  /* 0x0:no action */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FreightLmptSwt, Data);
    			/* 货厢灯自动开启功能 */
    			Data[0] = 0;  /* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FreightLmpAutoSet, Data);
    		}
    		#endif

    		/* 后风挡小窗电动调节 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05)// || (defined SWC_IPC_PROJECT_TYPE_D02)
    		if (2 == Object->VehicleConfig[VCONFIG_KIND_RR_SLIDING_WINDOW])
    		{
    			Data[0] = 0;  /* 0x0:No Action */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RWinSwtReq_TC, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0:No Action */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RWinSwtReq_TC, Data);
    		}
    		#endif

    		/* 主副油箱供油控制 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05)
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_AUXILIARY_FUEL_TANK])
    		{
    			Data[0] = 0;  /* 0x0:主油箱 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_OilBoxSplyReq, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0:主油箱 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_OilBoxSplyReq, Data);
    		}
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    		if ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL]) || (8 == Object->VehicleConfig[VCONFIG_KIND_FUEL]))
    		{
    			Data[0] = 0;  /* 0x0:100% 动力电池充电百分比 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattSOCLim, Data);
    		}
    		else
    		{
    			Data[0] = 6;  /* 0x6:No Action 动力电池充电百分比 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattSOCLim, Data);
    		}
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    		if (((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL]) || (8 == Object->VehicleConfig[VCONFIG_KIND_FUEL])) \
    		 && (0 != Object->VehicleConfig[VCONFIG_KIND_BATTERY_TEMPERATURE_KEEP_WITH_GUN]))
    		{
    			Data[0] = 2;  /* 0x2:Off 电池包插抢保温开关 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattKeepTemp, Data);
    		}
    		else
    		{
    			Data[0] = 2;  /* 0x2:Off 电池包插抢保温开关 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattKeepTemp, Data);
    		}
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    		if (((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL]) || (8 == Object->VehicleConfig[VCONFIG_KIND_FUEL])) \
    		 && (1 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_HEAT_PRESERVATION_FUNCTION_OF_BATTERY_PACK]))
    		{
    			Data[0] = 2;  /* 0x2:Off 电池包主动保温开关 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_IntelBattTempMagSet, Data);
    		}
    		else
    		{
    			Data[0] = 2;  /* 0x2:Off 电池包主动保温开关 */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_IntelBattTempMagSet, Data);
    		}
    		#endif

    		/* 方向盘未回正提醒功能开关 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P01)
    		if(1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_WHEEL_BACK_REMINDER])
    		{
    			Data[0] = 1;  /*0x1:ON*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerCorrnReq, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /*0x0:OFF*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerCorrnReq, Data);
    		}
    		#endif

    		/* 越野热管理模式:越野热管理模式开关 */
    		#ifdef SWC_IPC_PROJECT_TYPE_P05
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_OFF_ROAD_THERMAL_MANAGEMENT_MODE])
    		{
    			Data[0] = 0;  /* 0x0:off */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_OffroadThmSts, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0:off */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_OffroadThmSts, Data);
    		}
    		#endif

    		/* 方向盘加热：开关 */
    		if(1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_HEATING])
    		{
    			Data[0] = 1;  /*0x1:No request*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerWheelHeatSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /*0x0:No action*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerWheelHeatSwtReq, Data);
    		}

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07) // || (defined SWC_IPC_PROJECT_TYPE_P02)
    		if(1 == Object->VehicleConfig[VCONFIG_KIND_HEADLAMP_VIRTUAL_SW])
    		{
    			/* 大灯切换：位置灯开关 */
    			Data[0] = 0;  /*0x0:OFF*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PosnLmpSwtSts_HUT, Data);
    			/* 大灯切换：近光灯开关开关 */
    			Data[0] = 0;  /*0x0:OFF*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LowBeamSwtSts_HUT, Data);
    			/* 大灯切换：自动大灯开关 */
    			Data[0] = 1;  /*0x1:Auto*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoLmpSwtSts_HUT, Data);
    		}
    		else
    		{
    			/* 大灯切换：位置灯开关 */
    			Data[0] = 0;  /*0x0:OFF*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PosnLmpSwtSts_HUT, Data);
    			/* 大灯切换：近光灯开关开关 */
    			Data[0] = 0;  /*0x0:OFF*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LowBeamSwtSts_HUT, Data);
    			/* 大灯切换：自动大灯开关 */
    			Data[0] = 0;  /*0x0:NonAuto*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoLmpSwtSts_HUT, Data);
    		}
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)// || (defined SWC_IPC_PROJECT_TYPE_P02)
    		if((1 == Object->VehicleConfig[VCONFIG_KIND_VIRTUAL_SW_FOR_REAR_FOG_LAMP]) && (1 == VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE))
    		{
    			/* 后雾灯：后雾灯开关信号 */
    			Data[0] = 0;  /*0x0:OFF*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearFogLmpSwtSts_HUT, Data);
    		}
    		else
    		{
    			/* 后雾灯：后雾灯开关信号 */
    			Data[0] = 0;  /*0x0:OFF*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearFogLmpSwtSts_HUT, Data);
    		}
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_A07)
    		/* 自动驻车 */
    		if((2 == Object->VehicleConfig[VCONFIG_KIND_AVH_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_AVH_SWITCH_TYPE])) // ZW2
    		{
				if(1 == Object->VehicleConfig[VCONFIG_KIND_FUEL]) //汽油
				{
					if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_ESP2, SWC_IPC_NULL))
					{
						#if (defined COMEX_SIGNAL_RX_AVHSTS)
						IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AVHSts, Data);
						#elif (defined COMEX_SIGNAL_RX_AVHSTS_0X145)
						IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AVHSts_0x145, Data);
						#endif
						if ((1 == Data[0]) || (2 == Data[0]))
						{
							Data[0] = 1; /*0x1:Request*/
							IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_AVHSwitchSts, Data);
						}
					}
				}
				// else if(3 == Object->VehicleConfig[VCONFIG_KIND_FUEL]) //HEV
				// {
				// 	if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_ESP_FD2, SWC_IPC_NULL))
				// 	{
				// 		IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AVHSts_0x137, Data);
				// 		if ((1 == Data[0]) || (2 == Data[0]))
				// 		{
				// 			Data[0] = 1; /*0x1:Request*/
				// 			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_AVHSwitchSts, Data);
				// 		}
				// 	}
				// }
				else
				{
					;
				}
    		}
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		/* 电子驻车 */
    		if((2 == Object->VehicleConfig[VCONFIG_KIND_EPB_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_EPB_SWITCH_TYPE])) // ZW3
    		{
    			Data[0] = 2;  /*0x2:Apply*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EPB_SwtPosn, Data);
    		}
    		else
    		{
    			Data[0] = 1;  /*0x1:Release*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EPB_SwtPosn, Data);
    		}
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_A07) // (defined SWC_IPC_PROJECT_TYPE_B02)
    		/* 按键虚拟开关：拨片换挡 */
    		if(1 == Object->VehicleConfig[VCONFIG_KIND_VIRTUAL_SW_FOR_STRG_WHL_HANDLE_SHIFT])
    		{
    			Data[0] = 0;  /*0x01:Shift peddle request*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_TGSSwtReq, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /*0x00:No shift peddle request*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_TGSSwtReq, Data);
    		}
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_A07)
    		/* 陡坡缓降(下坡辅助) */
    		//Config: ZW4  Byte 97 bit 4-2
    		if((2 == Object->VehicleConfig[VCONFIG_KIND_HDC_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_HDC_SWITCH_TYPE])) // ZW2
    		{
				if(1 == Object->VehicleConfig[VCONFIG_KIND_FUEL]) //汽油
				{
					if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_ESP2, SWC_IPC_NULL))
    				{
						#if (defined COMEX_SIGNAL_RX_HDCCTRL)
						IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HDCCtrl, Data);
						#elif (defined COMEX_SIGNAL_RX_HDCCTRL_0X145)
						IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HDCCtrl_0x145, Data);
						#endif
						if ((1 == Data[0]) || (2 == Data[0]))
						{
							Data[0] = 1; /*0x1:Request*/
							IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_HDCSwitchCtrl, Data);
						}
    				}
				}
				// else if(3 == Object->VehicleConfig[VCONFIG_KIND_FUEL]) //HEV
				// {
				// 	if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_ESP_FD2, SWC_IPC_NULL))
    			// 	{
				// 		IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HDCCtrl_0x137, Data);
				// 		if ((1 == Data[0]) || (2 == Data[0]))
				// 		{
				// 			Data[0] = 1; /*0x1:Request*/
				// 			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_HDCSwitchCtrl, Data);
				// 		}
    			// 	}
				// }
				else
				{
					;
				}
    		}
    		#endif

			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
			/* 雨刮间歇档位 / 灵敏度调节 */
			if (1 == Object->VehicleConfig[VCONFIG_KIND_WIPER_INTERMITTENT_LEVEL_VIRTUAL_SW])
			{
				Data[0] = 2;  /*0x2:Sensitivity 3,R_650Ω*/
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSSensitivityReq_HUT, Data);
			}
			else
			{
				Data[0] = 0;  /*0x0:Sensitivity 1,R_0Ω_Slow*/
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSSensitivityReq_HUT, Data);
			}
			#endif

			#if (defined SWC_IPC_PROJECT_TYPE_P03)
			/* 副驾座椅非个性化记忆 副驾非个性化记忆软开关设置 */
			if (1 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MEMORY_ASSISTANT])
			{
				Data[0] = 0;  /* 0x0:no action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetSwt_Pass, Data);
			}
			else
			{
				Data[0] = 0;  /* 0x0:no action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetSwt_Pass, Data);
			}
			#endif

			#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D02) //|| (defined SWC_IPC_PROJECT_TYPE_P01)
			/* 副驾座椅非个性化记忆 副驾座椅迎宾 */
			if (1 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_SEAT_WELCOME_FUNCTION])
			{
				Data[0] = 1;  /* 0x1:Enable */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_Pass, Data);
			}
			else
			{
				Data[0] = 0;  /* 0x0:Disable */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_Pass, Data);
			}
			#endif

			/* 后排左侧座椅按摩设置 ZV2+ZS9 */
			#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || (defined SWC_IPC_PROJECT_TYPE_D02)
			if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]))
		     && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
			{
				/* 按摩强度 */
				Data[0] = 0;/* 0x0:OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgLvlSet, Data);
				/* 按摩模式 */
				Data[0] = 1;/* 0x1:Wave Mode */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgModSet, Data);
			}
			else
			{
				/* 按摩强度 */
				Data[0] = 0;/* 0x0:OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgLvlSet, Data);
				/* 按摩模式 */
				Data[0] = 0;/* 0x0:No action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgModSet, Data);
			}
			#endif

			/* 后排右侧座椅按摩设置 ZV3+ZS9 */
			#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) \
			|| (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D02) \
			|| (defined SWC_IPC_PROJECT_TYPE_P01)
			if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]))
			 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
			{
				/* 按摩强度 */
				Data[0] = 0;/* 0x0:OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgLvlSet, Data);
				/* 按摩模式 */
				Data[0] = 1;/* 0x1:Wave Mode */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgModSet, Data);
			}
			else
			{
				/* 按摩强度 */
				Data[0] = 0;/* 0x0:OFF */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgLvlSet, Data);
				/* 按摩模式 */
				Data[0] = 0;/* 0x0:No action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgModSet, Data);
			}
			#endif

    		/* 前排座椅迎宾 PAA*/
    		if ((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
    		 || (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
    		{
    			Data[0] = 1;	/* 0x1:Enable */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna, Data);
    		}
    		else
    		{
    			Data[0] = 0;	/* 0x0:Disable */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna, Data);
    		}

    		/* 座椅设置:后排座椅迎宾 */
    		#ifdef SWC_IPC_PROJECT_TYPE_P05
    		if(1 == Object->VehicleConfig[VCONFIG_KIND_2ND_ROW_SEAT_WELCOME_FUNCTION])
    		{
    			Data[0] = 1;  /*0x1:Enable*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_SecRow, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /*0x0:Disable*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_SecRow, Data);
    		}
    		#endif
    		/* 外后视镜自动折叠 */
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    	     || (2 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    	     || (3 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
    	     || (4 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]))
    		{
    			Data[0] = 1;  /*0x1:Manual*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearviewFoldModSet, Data);
    		}
    		else
    		{
    			Data[0] = 1;  /*0x1:Manual*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearviewFoldModSet, Data);
    		}

    		/* 车速关窗 && 闭锁关窗 */
    		/* MAE:VCONFIG_KIND_DRIVER_WINDOW_OPERATING */
    		/* MAF:VCONFIG_KIND_PASSENGER_WINDOW_OPERATING */
    		/* MAG:VCONFIG_KIND_RR_1ST_WINDOW_OPERATING */
    		/* ZC0:VCONFIG_KIND_DOOR_MODULE_TYPE */
    		/* 天窗控制器(ZC3):VCONFIG_KIND_SUN_ROOF_CONTROLLER */
			/* ZP9:VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
				(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
    		/* 车速关窗 */
    		if (((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]))
    	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]))
    	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]))
    		 && (1 == Object->VehicleConfig[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE]))
    		{
    			Data[0] = 0;  /* 0x0：Close */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ClsWinSpdSet, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0：Close */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ClsWinSpdSet, Data);
    		}

    		/* 闭锁关窗 */
    		if (((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]))
    	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]))
    	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]))
    		 && (1 == Object->VehicleConfig[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE])
			 && ((1 == Object->VehicleConfig[VCONFIG_KIND_DOOR_MODULE_TYPE]) || (2 == Object->VehicleConfig[VCONFIG_KIND_DOOR_MODULE_TYPE])))
    		{
    			Data[0] = 0;  /* 0x0：Close */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWinSet, Data);
    		}
    		else
    		{
    			Data[0] = 0;  /* 0x0：Close */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWinSet, Data);
    		}
    		#endif

    		/* 电动侧踏 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
				(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
				(defined SWC_IPC_PROJECT_TYPE_P01)
    		if (6 == Object->VehicleConfig[VCONFIG_KIND_SIDE_STEP])
    		{
    			/* 电动侧踏开关 */
    			Data[0] = 1;/* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ElecSideSteppingSysSet, Data);
    			/* 特殊模式开关 */
    			Data[0] = 1;/* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AllTerrainDislSet, Data);
    			/* 车顶模式开关 */
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofModSet, Data);
    		}
    		else
    		{
    			/* 电动侧踏开关 */
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ElecSideSteppingSysSet, Data);
    			/* 特殊模式开关 */
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AllTerrainDislSet, Data);
    			/* 车顶模式开关 */
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofModSet, Data);
    		}
    		#endif

			/* 启动模式 */
			#if (defined SWC_IPC_PROJECT_TYPE_A07)
			if (3 == Object->VehicleConfig[VCONFIG_KIND_STARTING_SYSTEM])
			{
				Data[0] = 2;  /* 0x2:One click start */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_StartModSet, Data);
			}
			else
			{
				Data[0] = 0;  /* 0x0:no action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_StartModSet, Data);
			}
			#endif

			/* 空调加热开关 */
			#if (defined SWC_IPC_PROJECT_TYPE_A07)
			if ((5 == Object->VehicleConfig[VCONFIG_KIND_FUEL]) && ((0 == Object->VehicleConfig[VCONFIG_KIND_A_C_SYSTEM]) ||\
			(2 == Object->VehicleConfig[VCONFIG_KIND_A_C_SYSTEM])))
			{
				Data[0] = 0;  /* 0x0:no action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACEAHReq_VR, Data);
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACEAHReq_TC, Data);
			}
			else
			{
				Data[0] = 0;  /* 0x0:no action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACEAHReq_VR, Data);
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACEAHReq_TC, Data);
			}
			#endif

			/* 后排左右侧座椅 一键躺倒 */
			#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)
			if (((4 == Object->VehicleConfig[VCONFIG_KIND_SEAT_CONTROL_MODULE]) || (5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_CONTROL_MODULE]) ||\
			(6 == Object->VehicleConfig[VCONFIG_KIND_SEAT_CONTROL_MODULE])) && (1 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_SEAT_FAST_SET]))
			{
				Data[0] = 0;  /* 0x0:no action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearSeatLieFlatOneBtn, Data);
			}
			else
			{
				Data[0] = 0;  /* 0x0:no action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearSeatLieFlatOneBtn, Data);
			}
			#endif

			/* 车窗短升短降 */
			#if (defined SWC_IPC_PROJECT_TYPE_P05)
			if (1 == Object->VehicleConfig[VCONFIG_KIND_WINDOW_SHORT_LIFT_DROP_FUNCTION])
			{
				Data[0] = 1;  /* 0x1:Open */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WinShortUpShortDownSet, Data);
			}
			else
			{
				Data[0] = 0;  /* 0x0:no action */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WinShortUpShortDownSet, Data);
			}
			#endif

			/* 空调自干燥 */
			#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
			if (1 == Object->VehicleConfig[VCONFIG_KIND_A_C_SELF_DRYING])
			{
				Data[0] = 0;  /* 0x0:off */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoDryingSwt, Data);
			}
			else
			{
				Data[0] = 0;  /* 0x0:off */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoDryingSwt, Data);
			}
			#endif

			/* 生命体征监测 */
			#if (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) ||\
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
			if (1 == Object->VehicleConfig[VCONFIG_KIND_CHILD_PRESENCE_DETECTION])
			{
				/* 临时关闭开关 */
				Data[0] = 0x1; /* 0x1:Disable */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_VMDRTmpMonFctnSet, Data);
				/* 延迟报警 */
				Data[0] = 0x1; /* 0x1:Disable */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_VMDRInitAlarmDlySet, Data);
			}
			#endif

    	}
	    else
    	{
    		/*智能启停*/
    		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_D01) ||\
    			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
    			(defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SSSSet_HUT, Data);
    		#endif

    		/* 疲劳驾驶 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || \
				(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
    		Data[0] = 0;  /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDrowsnsDetnSet, Data);
    		#endif

    		/* 驾驶模式 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 0; /*0x0:Standard/Normal*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_D02)\
				|| (defined SWC_IPC_PROJECT_TYPE_P01)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 0; /*0x0:Standard/Normal*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_DrvModReq, Data);
    		#endif

    		/* 外后视镜倒车模式 KAG*/
    		Data[0] = 0;  /* 0x2:Bothsideenable */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_OrvmPosnEnaSts, Data);

    		/* 外后视镜角度调节 KAG*/
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05)\
    			|| (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) ||\
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 0;  /* 0x0:Mir_Swt_Idle */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ORVMLensAdjmt_HUT, Data);
    		#endif

    		/* 洗车拖车模式激活 CBA */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03)
    		// || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P03)
    		Data[0] = 0;  /* 0x0:CarWashModeOFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_CarWashMode_Req, Data);
    		#endif

    		/* 涉水模式 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03)\
    		 || (defined SWC_IPC_PROJECT_TYPE_D01)|| (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		Data[0] = 0;  /* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_WadeModeSet, Data);
    		#endif

    		/* Save 模式下充电阈值设置(ForPHEV) DAA CBA */
			#if 0
    		// #if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 4;  /* 0x4:50% */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattSOCLimSaveMod, Data);
    		#endif

    		/* 能量回收等级设置 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P03)\
             || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) \
             || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 1;  /* 0x1:Normal */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, Data);
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		/* 氛围灯总开关 */
			#if(!defined SWC_IPC_PROJECT_TYPE_P01)
    		Data[0] = 0;  /* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMMasterSwt, Data);
			#endif
    		/* 氛围灯亮度 */
    		Data[0] = 5;  /* 0x5:50 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMLightLvlSet, Data);
			#if (!defined SWC_IPC_PROJECT_TYPE_A07)
    		/* 轮廓氛围灯颜色选择 */
    		Data[0] = 2;  /* 0x2:极光白 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet, Data);
    		/* 轮廓氛围灯多色彩静态 */
    		Data[0] = 0;  /* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt, Data);
    		/* 轮廓氛围灯多色彩动态 */
    		Data[0] = 0;  /* 0x0:DynModOFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet, Data);
			#endif
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)
    		/* 轮廓氛围灯呼吸灯 */
    		Data[0] = 0;  /* 0X0：OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt, Data);
			#endif

			#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)\
				//|| (defined SWC_IPC_PROJECT_TYPE_P01) P01缺少信号
    		/* 面发光氛围灯流水灯设置 */
    		Data[0] = 0;  /* 0X0：OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMFloSwt, Data);
			#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) ||\
				(defined SWC_IPC_PROJECT_TYPE_D01)
			Object->AppNvm.MultiColorNrFlag = FALSE;
    		Data[0] = 2;  /* 0X2：极光白 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet_OLE, Data);
    		/* 面发光氛围灯多色彩静态模式 */
    		Data[0] = 0;  /* 0X2：OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt_OLE, Data);
    		/* 面发光氛围灯多色彩动态模式 */
    		Data[0] = 0;  /* 0x0:DynModOFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet_OLE, Data);
    		/* 面发光氛围灯呼吸灯设置 */
			Data[0] = 0;  /* 0X0：OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt_OLE, Data);
    		/* 面发光氛围灯流水灯设置 */
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr1, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr2, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr3, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr4, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr5, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr6, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr7, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr8, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr9, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr10, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr11, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr12, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr13, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr14, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr15, Data);
    		Data[0] = 0;  /* 0x0:No command */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr16, Data);
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
    			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		/* 轮廓氛围灯音乐律动 */
    		Data[0] = 0;  /* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMRhmSwt, Data);
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) ||\
				(defined SWC_IPC_PROJECT_TYPE_D01)
    		/* 面发光氛围灯音乐随动 */
    		Data[0] = 1;  /* 0x1:On */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMRhmSwt_OLE, Data);
    		#endif
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02) //|| (defined SWC_IPC_PROJECT_TYPE_A07)
			#if (!defined SWC_IPC_PROJECT_TYPE_P01) //P01信号缺失
	    		Data[0] = 0x65;  /* 0x65:Noaction */
	    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq0, Data);
	    		Data[0] = 0x65;  /* 0x65:Noaction */
	    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq1, Data);
	    		Data[0] = 0x65;  /* 0x65:Noaction */
	    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq2, Data);
	    		Data[0] = 0x65;  /* 0x65:Noaction */
	    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq3, Data);
	    		Data[0] = 0x65;  /* 0x65:Noaction */
	    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq4, Data);
	    		Data[0] = 0x65;  /* 0x65:Noaction */
	    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq5, Data);
	    		Data[0] = 0x65;  /* 0x65:Noaction */
	    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicFrq6, Data);
			#endif
    		#endif
    		#endif
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		/* 氛围灯联动:联动开关 */
    		Data[0] = 0;  /* 0X0： OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMPartitionSwt, Data);
    		#endif
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
				(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		/* 分区开关:左侧仪表板氛围灯开关 */
    		Data[0] = 0;  /* 0X0： OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LeftPanelALCMSwt, Data);
    		/* 分区开关:右侧仪表板氛围灯开关 */
    		Data[0] = 0;  /* 0X0： OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RightPanelALCMSwt, Data);
    		/* 分区开关:主驾门氛围灯开关 */
    		Data[0] = 0;  /* 0X0： OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDoorALCMSwt, Data);
    		/* 分区开关:副驾门氛围灯开关 */
    		Data[0] = 0;  /* 0X0： OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassDoorALCMSwt, Data);
    		/* 分区开关:左后门氛围灯开关 */
    		Data[0] = 0;  /* 0X0： OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LRDoorALCMSwt, Data);
    		/* 分区开关:右后门氛围灯开关 */
    		Data[0] = 0;  /* 0X0： OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRDoorALCMSwt, Data);
    		/* 分区开关:脚窝灯开关 */
    		Data[0] = 0;  /* 0X0： OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FootALCMSwt, Data);
    		/* 分区开关:顶棚氛围灯开关 */
    		Data[0] = 0;  /* 0X0： OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofALCMSwt, Data);
    		#endif

			/* 音乐灯光秀：设置开关 */
			#if (defined SWC_IPC_PROJECT_TYPE_B02)
			Data[0] = 1;  /* 0x1:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MusicLightShowSet, Data);
			#endif

    		/* 解闭锁提示 */
		    #if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				(defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 0;  /* 0x0:Horn&Light */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockPromptFunSet, Data);
    		#endif

    		/* 蓝牙泊车 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
    		/* 蓝牙泊入自动闭锁 */
    		Data[0] = 0;  /* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPAEntryLockSet, Data);
    		/* 蓝牙泊出自动解锁 */
    		Data[0] = 0;  /* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPALvngUnlockSet, Data);
    		#endif

    		/* 方向盘助力模式 */
    		Data[0] = 3; /*0x3:NO Hut Control*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, Data);

    		/* 无线充电开关 */
    		Data[0] = 2; /*0x2:Close*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WPC_SwtReq, Data);

    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    		 || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
    		Data[0] = 2; /*0x2:Close*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RWPC_SwtReq, Data);
    		#endif

    		/* WHUD */
    		Data[0] = 0; /*0x0:No Action*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_SwtReq, Data);
    		Data[0] = 0; /*0x0:No action*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_BrightnessLvlSwt, Data);
    		Data[0] = 0; /*0x0:No action*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_HeightLvlSwt, Data);

    		/* 主驾驶座椅按摩设置 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
    			(defined SWC_IPC_PROJECT_TYPE_P01)
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgLvlSet, Data);
    		Data[0] = 0; /*0x0:No Action*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgModSet, Data);
    		#endif

    		/* 主驾驶座椅腰托设置 */
    		#if 0 // SWC_IPC_PROJECT_TYPE_B03
    		Data[0] = 0;/*0x0:No Action*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatSupportPosnSwt, Data);
    		#endif

    		/* 主驾座椅记忆 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03)\
    		 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
    		 	(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
    		 	(defined SWC_IPC_PROJECT_TYPE_P01)
    		Data[0] = 0; /*0x0:No Command*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSet, Data);
    		Data[0] = 0; /*0x0:FactoryDefault*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, Data);
    		#endif

    		/* 后背门感应开启 */
    		#if (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HFASwtSts, Data);
    		#endif

    		/* 后背门开启高度 */
    		#if (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 0; /*0x0:*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PLG_HeightSet, Data);
    		#endif

    		/* 行人安全辅助系统 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_PedSwtReq, Data);
    		/* 行人安全辅助系统紧急转向辅助 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_PedSwtReq, Data);

    		/* 碰撞安全辅助系统制动 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_VehSwtReq, Data);
    		/* 碰撞安全辅助系统紧急转向辅助 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_VehSwtReq, Data);

    		/* 交叉路口辅助 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_JASwtReq, Data);

    		/* 前横穿侧向警告 */
			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P02) ||  (defined SWC_IPC_PROJECT_TYPE_P01) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCTASwtReq, Data);
			#endif

    		/* 前横穿侧向制动 */
			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P02) ||  (defined SWC_IPC_PROJECT_TYPE_P01) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCTABrkSwtReq, Data);
			#endif

    		/* 前碰撞预警灵敏度 */
    		Data[0] = 0; /*0x0:Normal*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCW_SnvtySet, Data);

    		/* 自动紧急转向辅助 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P01) || (defined SWC_IPC_PROJECT_TYPE_D01)\
    		 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AESSwtReq, Data);
    		#endif

    		/* 车道辅助功能 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LSSSwtReq, Data);

    		/* 车道辅助 : 预警辅助 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LDWSwtReq, Data);

    		/* 车道辅助 : 保持辅助 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LKASwtReq, Data);

    		#if 0
    		/* 车道辅助 : 居中辅助 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCKSwtReq, Data);
    		#endif

    		/* 车道辅助 : 紧急车道保持 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ELKSwtReq, Data);

    		/* 车道辅助 : 智慧躲闪 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IntelligentEvaSwtReq, Data);

    		/* 车道辅助 : 预警方式 */
    		Data[0] = 0; /*0x0:Voice*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LSSWarnFormSwtReq, Data);

    		/* 预警灵敏度 */
    		Data[0] = 0; /*0x0:Normal*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IFC_SnvtySet, Data);

    		/* 侧后辅助系统 : 并线辅助 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCASwtReq, Data);

    		/* 侧后辅助系统 :       开门预警 */
            Data[0] = 0; /*0x0:Off*/
    	    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DOWSwtReq, Data);

    		/* 侧后辅助系统 :       后碰撞预警 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCWSwtReq, Data);

    		/* 侧后辅助系统 : 倒车侧向警告 */
            Data[0] = 0; /*0x0:Off*/
    	    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTASwtReq, Data);

    		/* 侧后辅助系统 : 倒车侧向制动 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTABrkSwtReq, Data);

    		/* 交通标志信息 : 交通标志识别 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSRSwtReq, Data);

    		/* 交通标志信息 : 超速报警 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSRWarnSwtReq, Data);

    		/* 交通标志信息 : 巡航车速限制 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ISLSwtReq, Data);

    		/* 交通标志信息 : 超速报警灵敏度 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSR_SnvtySet, Data);

			#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02)
			/* 交通标志信息 : 导航降速 */
			Data[0] = 0; /*0x0:Off*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NavDecSwtReq, Data);
			#endif

    		/* 灯光控制 : 照我回家延时时间设置*/
    		Data[0] = 0; /*0x0:0seconds*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FolwMeHomeDlyTimSet, Data);

    		/* 灯光控制 : 运动模式灯光设置 */
    		// #if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		//  || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_D03)
			#if 0
    		Data[0] = 0; /*0x0:OFF*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SportModLightSet, Data);
    		#endif

    		/* 360环视 : 环视退出车速值设置 */
            Data[0] = 0; /*0x0:No command*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PASExitSpdSwt, Data);

    		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || \
				(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		/* 360环视 : 道路标定 */
            Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LaneCalActvtCmd, Data);

    		/* 360环视 : 恢复出厂标定 */
    		Data[0] = 0; /*0x0:Off*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SwToFieldCalRstCmd, Data);
    		#endif

    		/* 360环视 : 手动开启环视 */
    		Data[0] = 0; /*0x0:No action*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PASSwtReq_VR, Data);

			/* D档低速开启360环视 */
			#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
			Data[0] = 0; /*0x0:Disable*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AVMAutoSet, Data);
			#endif

    		/* 门锁设置 : 超级锁设置 */
    		#if 0
            Data[0] = 0;  /*0x0:No action*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SuperLockSet, Data);
    		#endif

    		/* Parking lights */
    		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) ||\
				(defined SWC_IPC_PROJECT_TYPE_P05)
    		Data[0] = 1; /*0x1:On*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ParkLmpSet, Data);
    		#endif

    		/* ESP */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		{
    			Data[0] = 1;/*0x0:Pressed*/
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_ESPFuncOffSwtSts, Data);
    		}
    		#endif

    		/* 解锁模式 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P05)  || (defined SWC_IPC_PROJECT_TYPE_P03) || \
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
    		Data[0] = 0;/*0x0:All Door*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DoorUnlockModSet, Data);
    		#endif

    		/* 360环视 : 自动转向 */
    		Data[0] = 0; /*0x0:No Request*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoAVMSwSet_Cmd, Data);

    		/* DST */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
    			(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DSTSwtReq, Data);
    		#endif

    		/* 驾驶模式开关记忆：硬开关 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P01) \
    		 || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) \
    		|| (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_B02)
    		Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvgModeMemReq, Data);
    		#endif

    		/* 副驾驶座椅按摩设置 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
    			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
    			(defined SWC_IPC_PROJECT_TYPE_P01)
    		/* 按摩强度 */
    		Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgLvlSet, Data);
    		/* 按摩模式 */
    		Data[0] = 0;/* 0x0:No Action */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgModSet, Data);
    		#endif

    		/* 座椅非个性化设置 PAA ZM2*/
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03)\
    		 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
    		 	(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
    		 	(defined SWC_IPC_PROJECT_TYPE_P01)
    		Data[0] = 0; /*0x0:No Command*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetSwt, Data);
    		#endif

    		/* 主动进入解锁 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
    			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D02)
    		Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryUnlockSet, Data);
    		#endif

    		/* 主动离开闭锁 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
    			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || (defined SWC_IPC_PROJECT_TYPE_D02)
    		Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryLockSet, Data);
    		#endif

    		/* 无感车控：天窗/遮阳帘 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)\
    		 || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)\
			 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P01)
    		/* 天窗 */
    		Data[0] = 0;/* 0x0:No action */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SunRoofSwtReq_VR, Data);
    		/* 遮阳帘 */
    		Data[0] = 0;/* 0x0:No action */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SunShadeSwtReq_VR, Data);
    		#endif

    		/* 无感车控：主驾6向调节 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 0;/* 0x0:Seat_Swt_Idle */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatAdjmt_HUT, Data);
    		#endif

    		/* 无感车控：外后视镜折叠 */
    		/* 外后视镜 KAG(VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR) */
    		/* 后视镜折叠虚拟开关控制 ZP3(VCONFIG_KIND_OSRVM_FOLD_VIRTUAL_SW_CONTROL) */
    		// #if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05)
            #if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B02)  || (defined SWC_IPC_PROJECT_TYPE_P03)\
    			|| (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 0;/* 0x0:None */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ORVMFoldSwt_HUT, Data);
    		#endif

    		/* 越野模式：专家模式 */
    		/* 项目代码 AAA(VCONFIG_KIND_PROJECT_CODE) */
    		/* 变速器 EAA(VCONFIG_KIND_TRANSMISSION) */
    		/* 减震器 GAD(VCONFIG_KIND_DAMPER) */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02)\
    		 || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)\
    		 || (defined SWC_IPC_PROJECT_TYPE_P01)
    		/* 自定义界面 */
    		Data[0] = 0;/* 0x0:Not active */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data);
    		/* 四驱模式 */
    		Data[0] = 0;/* 0x0:2H */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, Data);
    		/* 驱动模式 */
    		Data[0] = 0;/* 0x0: 舒适 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, Data);
    		Data[0] = 0;/* 0x0: 舒适 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, Data);

    		#if (!defined SWC_IPC_PROJECT_TYPE_P05) && (!defined SWC_IPC_PROJECT_TYPE_P01)
    		Data[0] = 0;/* 0x0: 舒适 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_HCU, Data);
    		#endif

    		/* ESC设置 */
    		Data[0] = 2;/* 0x2: ALL_OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, Data);

			#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) ||\
				(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P01)
    		Data[0] = 3;/* 0x3: NO Hut Control */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
    		#endif

    		#endif

    		/* 货箱照明设置(皮卡) */
    		#if defined SWC_IPC_PROJECT_TYPE_P05
    		/* 货箱灯开关设置 */
    		Data[0] = 0;  /* 0x0:no action */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FreightLmptSwt, Data);
    		/* 货厢灯自动开启功能 */
    		Data[0] = 0;  /* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FreightLmpAutoSet, Data);
    		#endif

    		/* 后风挡小窗电动调节 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05)// || (defined SWC_IPC_PROJECT_TYPE_D02)
    		Data[0] = 0;  /* 0x0:No Action */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RWinSwtReq_TC, Data);
    		#endif

    		/* 主副油箱供油控制 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05)
    		Data[0] = 0;  /* 0x0:主油箱 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_OilBoxSplyReq, Data);
    		#endif

			#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
				// || (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 6;  /* 0x6:No Action 动力电池充电百分比 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattSOCLim, Data);
			#endif

			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 2;  /* 0x2:Off 电池包插抢保温开关 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattKeepTemp, Data);
			#endif

			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P02)// || (defined SWC_IPC_PROJECT_TYPE_A07)
    		Data[0] = 2;  /* 0x2:Off 电池包主动保温开关 */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_IntelBattTempMagSet, Data);
    		#endif

    		/* 方向盘未回正提醒功能开关 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
				(defined SWC_IPC_PROJECT_TYPE_P01)
    		Data[0] = 0;  /*0x0:OFF*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerCorrnReq, Data);
    		#endif

    		/* 越野热管理模式:越野热管理模式开关 */
    		#ifdef SWC_IPC_PROJECT_TYPE_P05
    		Data[0] = 0;  /* 0x0:off */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_OffroadThmSts, Data);
    		#endif

    		/* 方向盘加热：开关 */
    		Data[0] = 0;  /*0x0:No action*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerWheelHeatSwtReq, Data);

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)// || (defined SWC_IPC_PROJECT_TYPE_P02)
    		/* 大灯切换：位置灯开关 */
    		Data[0] = 0;  /*0x0:OFF*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PosnLmpSwtSts_HUT, Data);
    		/* 大灯切换：近光灯开关开关 */
    		Data[0] = 0;  /*0x0:OFF*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LowBeamSwtSts_HUT, Data);
    		/* 大灯切换：自动大灯开关 */
    		Data[0] = 0;  /*0x0:NonAuto*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoLmpSwtSts_HUT, Data);
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)// || (defined SWC_IPC_PROJECT_TYPE_P02)
    		/* 后雾灯：后雾灯开关信号 */
    		Data[0] = 0;  /*0x0:OFF*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearFogLmpSwtSts_HUT, Data);
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
    		/* 电子驻车 */
    		Data[0] = 1;  /*0x1:Release*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EPB_SwtPosn, Data);
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_A07) // (defined SWC_IPC_PROJECT_TYPE_B02)
    		/* 按键虚拟开关：拨片换挡 */
    		Data[0] = 0;  /*0x00:No shift peddle request*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_TGSSwtReq, Data);
    		#endif

			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
			/* 雨刮间歇档位 / 灵敏度调节 */
			Data[0] = 0;  /*0x0:Sensitivity 1,R_0Ω_Slow*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSSensitivityReq_HUT, Data);
			#endif

			#if (defined SWC_IPC_PROJECT_TYPE_P03)
			/* 副驾座椅非个性化记忆 副驾非个性化记忆软开关设置 */
			Data[0] = 0;  /* 0x0:no action */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetSwt_Pass, Data);
			#endif

			#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D02)//|| (defined SWC_IPC_PROJECT_TYPE_P01)
			/* 副驾座椅非个性化记忆 副驾座椅迎宾 */
			Data[0] = 0;  /* 0x0:Disable */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_Pass, Data);
			#endif

			#if (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D01)
				// || (defined SWC_IPC_PROJECT_TYPE_P02) P02 can signle miss
			/*舒适制动*/
			Data[0] = 0;  /* 0x0:关闭 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_CSTSwt, Data);
			#endif

			#if (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D01)
			/*悬架升高请求*/
			Data[0] = 0;  /* 0x0:disable */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SuspLiftReq, Data);
			#endif

			/* 后排左侧座椅按摩设置 */
			#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
				(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || (defined SWC_IPC_PROJECT_TYPE_D02)
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgLvlSet, Data);
			/* 按摩模式 */
			Data[0] = 0;/* 0x0:No action */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgModSet, Data);
			#endif

			/* 后排右侧座椅按摩设置 */
			#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) \
			|| (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D02) \
			|| (defined SWC_IPC_PROJECT_TYPE_P01)
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgLvlSet, Data);
			/* 按摩模式 */
			Data[0] = 0;/* 0x0:No action */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgModSet, Data);
			#endif


    		/* 前排座椅迎宾 PAA*/
    		Data[0] = 0;	/* 0x0:Disable */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna, Data);

    		/* 座椅设置:后排座椅迎宾 */
    		#ifdef SWC_IPC_PROJECT_TYPE_P05
    		Data[0] = 0;  /*0x0:Disable*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_SecRow, Data);
    		#endif

    		/* 外后视镜自动折叠 */
    		Data[0] = 1;  /*0x1:Manual*/
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearviewFoldModSet, Data);

    		/* 车速关窗 && 闭锁关窗 */
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
				(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
    		Data[0] = 0;  /* 0x0：Close */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ClsWinSpdSet, Data);
    		Data[0] = 0;  /* 0x0：Close */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWinSet, Data);
    		#endif

    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
				(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
				(defined SWC_IPC_PROJECT_TYPE_P01)
    		/* 电动侧踏开关 */
    		Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ElecSideSteppingSysSet, Data);
    		/* 特殊模式开关 */
    		Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AllTerrainDislSet, Data);
    		/* 车顶模式开关 */
    		Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofModSet, Data);
    		#endif

			/* 启动模式 */
			#if (defined SWC_IPC_PROJECT_TYPE_A07)
			Data[0] = 0;  /* 0x0:no action */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_StartModSet, Data);
			#endif

			/* 空调加热开关 */
			#if (defined SWC_IPC_PROJECT_TYPE_A07)
			Data[0] = 0;  /* 0x0:no action */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACEAHReq_VR, Data);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACEAHReq_TC, Data);
			#endif

			/* 后排左右侧座椅 一键躺倒 */
			#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)
			Data[0] = 0;  /* 0x0:no action */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearSeatLieFlatOneBtn, Data);
			#endif

			/* 车窗短升短降 */
			#if (defined SWC_IPC_PROJECT_TYPE_P05)
			Data[0] = 0;  /* 0x0:no action */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WinShortUpShortDownSet, Data);
			#endif

			/* 空调自干燥 */
			#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
			Data[0] = 0;  /* 0x0:off */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoDryingSwt, Data);
			#endif

			/* 生命体征监测 */
			#if (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) ||\
				(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
			/* 临时关闭开关 */
			Data[0] = 0x1; /* 0x1:Disable */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_VMDRTmpMonFctnSet, Data);
			/* 延迟报警 */
			Data[0] = 0x1; /* 0x1:Disable */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_VMDRInitAlarmDlySet, Data);
			#endif

    		SWC_IPC_PRINT_ERROR("Restore can signal value phase 1 read vehicle config faild!");
    	}
    }

	Data[0] = 2;/*0x2:15km/h*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SpdAutoLockModSet, Data);
	Data[0] = 2;/*0x2:ON*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FlaoutUnlockSet, Data);

	/* 前雨刮 */
	Data[0] = 2;  /*0x2:long time 800ms*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoWshWipSet, Data);

	/* 灯光控制 : 节电延时时间设置 */
	Data[0] = 1;  /*0x1:5minutes*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BattSaveDelayTimeSet, Data);

	/* 灯光控制 : 顶灯延时时间设置 */
	Data[0] = 1;  /*0x1:10seconds*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DomeLmpDlyTimSet, Data);

	/* 灯光控制 : 寻车功能模式设置 */
	Data[0] = 0;  /*0x0:Horn&Light*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SeekVehSet, Data);

	/* 灯光控制 : 主动迎宾设置 */
	Data[0] = 2;  /*0x2:ON*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ApproachLampSet, Data);

	/* 前排空调显示：前排空调 HMI 显示控制 */
	#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
		(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
		(defined SWC_IPC_PROJECT_TYPE_P01)// All projects are supported, but currently only P03 and P05 have signals
	Data[0] = 0;  /* 0x0:No action */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACFrntHMIDis_TC, Data);
	#endif

	/* 前排/后排空调显示：前排/后排空调 HMI 显示控制 */
    #if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
		(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
		(defined SWC_IPC_PROJECT_TYPE_P01)// All projects are supported, but currently only P03 and P05 have signals
    Data[0] = 0;  /* 0x0:No display */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FrntRearACDispSts, Data);
    #endif

	/* 后排空调显示：后排空调 HMI 显示控制 */
	#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
		(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
	Data[0] = 0;  /* 0x0:No action */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACRearHMIDis_TC, Data);
	#endif

	/* 空调加热开关 */
    #if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07) // All projects are supported, but currently only B02、B03 and A07 have signals
	Data[0] = 0;  /* 0x0:No action */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACEAHReq_TC, Data);
    #endif

    #if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)\
     || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
    /* Fragrance type selection: Fragrance function switch */
    Data[0] = 1;  /* 0x1:Disable */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACFGAEnaReq_TC, Data);
    /* Fragrance type selection: Fragrance function channel selection */
    Data[0] = 0;  /* 0x0:No action */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACFGAChanTyp_TC, Data);
    /* Fragrance concentration selection */
    Data[0] = 0;  /* 0x0:No action */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACFGALvlReq_TC, Data);
    #endif

     #if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) \
     || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    /* 副驾驶侧座椅调节 */
    Data[0] = 0;  /* 0x0:Seat_Swt_Idle */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatAdjmtSwt_HUT, Data);
    #endif

    #if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
		(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    /* DWD功能开关 */
    Data[0] = 0;  /* 0x0:OFF */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DWD_WorkCmd, Data);
    #endif

	#if (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
		(defined SWC_IPC_PROJECT_TYPE_D03)
    /* 电量储备：目标电量设置 */
    Data[0] = 0;  /* 0x0:OFF */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_TgtSOCSet, Data);
    #endif

	#if (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
		(defined SWC_IPC_PROJECT_TYPE_D03)
    /* 电量储备：电量储备开关 */
    Data[0] = 0;  /* 0x0:OFF */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_HybFctnReq, Data);
    #endif

	/* 动力模式选择（PHEV） */
	#if (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
		(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P01)
	Data[0] = 1;  /* 0x1:HEV */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_HybModReq, Data);
	#endif

	/* 制动模式选择 */
	#if (defined SWC_IPC_PROJECT_TYPE_P03)
	Data[0] = 0;  /* 0x0: Normal */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BrkPedFeelSelect, Data);
	#endif

	/* 远近光自动切换 */
	#if (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_B02) // || (defined SWC_IPC_PROJECT_TYPE_P02)
	Data[0] = 0;  /* 0x0: OFF */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoHiLowBeamSwtSts_HUT, Data);
	#endif

	/* 预测能量管理 */
	/* 自适应能量回收 */
	#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
		(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
	Data[0] = 1;  /* 0x1: OFF */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ARFSwtReq, Data);
	#endif
	/* 智能电量管理 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_P01)
	Data[0] = 1;  /* 0x1: OFF */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SOCMngmntSwtReq, Data);
	#endif
	/* 自适应发动机启停 */
	#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
		(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) ||(defined SWC_IPC_PROJECT_TYPE_P01)
	Data[0] = 1;  /* 0x1: OFF */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ASFCSwtReq, Data);
	#endif
	/* 自适应换挡 */
	#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
		(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
	Data[0] = 1;  /* 0x1: OFF */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AGSSwtReq, Data);
	#endif

	/* 空气悬架模式选择软开关 */
	/* 自动便捷进出模式 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
	Data[0] = 0;  /*0x0:*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoEasyAcsReq, Data);
	#endif
	/* 举升模式 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
	Data[0] = 0;  /*0x0:*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_JackModeReq, Data);
	#endif
	/* 拖车模式 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
	Data[0] = 0;  /*0x0:*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TrailerModeReq, Data);
	#endif
	/* 脚踢开启后轴装载模式 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01)
	Data[0] = 0;  /*0x0:*/
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearLvlKickModReq, Data);
	#endif

	/* 洞穴时间闹钟提醒 模式座椅设置 */
	#if (defined SWC_IPC_PROJECT_TYPE_P03)
	Data[0] = 0;  /* 0x0:No_action */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairRestSetSwt, Data);
	#endif

	/* 洞穴时间闹钟提醒 模式应用状态 */
	#if (defined SWC_IPC_PROJECT_TYPE_P03)
	Data[0] = 0;  /* 0x0:No_action */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AppModeFB, Data);
	#endif

	/* 洗车模式开关 */
	#if (defined SWC_IPC_PROJECT_TYPE_A07)
	Data[0] = 0;  // 0x0:OFF
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_CarWashModeReq, Data);
	#endif

	/* 模拟声浪 联动开关状态 */
	#if (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P01)
	Data[0] = 0;  /* 0x0:关闭 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IESS_MdlSwtReq, Data);
	#endif

	/* 智能温控 */
	#if (defined SWC_IPC_PROJECT_TYPE_A07)
	/* 温控区间设置 */
	Data[0] = 0;  /* 0x0:-10℃ */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_InCarTempMinSet, Data);
	Data[0] = 0x3C;  /* 0x3C:50℃ */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_InCarTempMaxSet, Data);
	/* 智能空调 */
	Data[0] = 0;  /* 0x0:off */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SmtACSwt, Data);
	/* 智能座椅通风加热 */
	Data[0] = 0;  /* 0x0:off */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SmtSeatSwt, Data);
	/* 智能方向盘加热 */
	Data[0] = 0;  /* 0x0:off */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SmtCsaSwt, Data);
	#endif

	if (0x01 == Object->RestoreType)
    {
        /* 按键背光只在恢复出厂时进行重置 */
        Data[0] = 4;/*0x4:等级5*/
        IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BackgroundLightLvlSet, Data);
    }

	/* 时钟背光设定值（中控补偿值） */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
	Data[0] = 5;  /* 0x5:ZERO */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BriCmp, Data);
	#endif

	IPC_OS_RestoreWisdomCruise(Object);

	SWC_IPC_PRINT_INFO("Restore can signal value phase 1 work start!");
}

/**********************************************************************************************************
*Function   : IPC_RestoreTxCanSignalPhase2                                                                *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-24                                                                                  *
**********************************************************************************************************/
static void IPC_RestoreTxCanSignalPhase2(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[1];
	//VconfigKind_Allbuffers Object->VehicleConfig;
	(void)Object;

	if (E_OK == Rte_Read_Vconfig_GetKindBuffers_AllKinds(Object->VehicleConfig))
    {
	    if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
    	{
    	    (void)SWC_IPC_PRINT_DEBUG("%s", __FUNCTION__);

    		/* 随速天窗 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03)
    		if(1 == Object->VehicleConfig[VCONFIG_KIND_SPEED__SENSING_SUNROOF_SWITCH])
    		{
        		Data[0] = 0;	/* 0x0:OFF */
        		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SrSpdCtrlSwt, Data);
    		}
    		else
    		{
                Data[0] = 0;	/* 0x0:OFF */
        		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SrSpdCtrlSwt, Data);
    		}
    		#endif

    		/* 紧急制动     配置字TBD*/
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
				(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		if(1 == Object->VehicleConfig[VCONFIG_KIND_ESS_SYSTEM])
    		{
    			Data[0] = 1;/* 0x1:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ABSLmpSet, Data);
    		}
    		else
    		{
    			Data[0] = 0;/* 0x0:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ABSLmpSet, Data);
    		}
    		#endif

    		/* 智能安全带 减少安全带松弛量(主驾) */
    		#if (defined SWC_IPC_PROJECT_TYPE_D03) // || (defined SWC_IPC_PROJECT_TYPE_D01)
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]))
    		{
    			Data[0] = 2;  /* 0x2:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIBSRSwtSet, Data);
    		}
    		else
    		{
    			Data[0] = 1;  /* 0x1:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIBSRSwtSet, Data);
            }
    		#endif

			/* 智能安全带 减少安全带松弛量(副驾) */
    		#if (defined SWC_IPC_PROJECT_TYPE_P03) \
			//|| (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_BELT]))
			{
    			Data[0] = 2;  /* 0x2:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMI_P_BSR_SwtSet, Data);
    		}
    		else
    		{
    			Data[0] = 1;  /* 0x1:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMI_P_BSR_SwtSet, Data);
            }
    		#endif

			/* 智能安全带 安全带震动提醒 */
    		#if (defined SWC_IPC_PROJECT_TYPE_D03) // || (defined SWC_IPC_PROJECT_TYPE_D01)
    		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]))
    		{
    			Data[0] = 2;  /* 0x2:ON */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIHWSwtSet, Data);
    		}
    		else
    		{
    			Data[0] = 1;  /* 0x1:OFF */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIHWSwtSet, Data);
            }
    		#endif

			#ifdef SWC_IPC_PROJECT_TYPE_B02
    	    if((1 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION]) || (2 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION]) || (3 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION]))
    	    {
        	    /* 迎宾灯光秀：灯光秀总开关 */
                Data[0] = 2;  /* 0x2:ON */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WelLightMainSwt, Data);

                if(1 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION])
                {
                     /* 迎宾灯光秀：解锁灯光秀 */
                    Data[0] = 0x3;  /* 0x3:on */
                    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_UnlockWelLightSwt, Data);
                    /* 迎宾灯光秀：闭锁灯光秀 */
                    Data[0] = 0;  /*0x0:No action*/
                    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWelLightSwt, Data);

                }
                else if(2 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION])
                {
                    /* 迎宾灯光秀：解锁灯光秀 */
                    Data[0] = 0;  /*0x0:No action*/
                    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_UnlockWelLightSwt, Data);
                    /* 迎宾灯光秀：闭锁灯光秀 */
                    Data[0] = 0x3;  /* 0x3:on */
                    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWelLightSwt, Data);

                }
                else
                {
                     /* 迎宾灯光秀：解锁灯光秀 */
                    Data[0] = 0x3;  /* 0x3:on */
                    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_UnlockWelLightSwt, Data);
                    /* 迎宾灯光秀：闭锁灯光秀 */
                    Data[0] = 0x3;  /* 0x3:on */
                    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWelLightSwt, Data);

                }
            }
            else
            {
        	    /* 迎宾灯光秀：灯光秀总开关 */
                Data[0] = 0;  /* 0x0:No action */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WelLightMainSwt, Data);
                /* 迎宾灯光秀：解锁灯光秀 */
                Data[0] = 0;  /* 0x0:No action */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_UnlockWelLightSwt, Data);
                /* 迎宾灯光秀：闭锁灯光秀 */
                Data[0] = 0;  /* 0x0:No action */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWelLightSwt, Data);
            }

            /* 迎宾灯光秀：展车灯光秀 */
            if(1 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_EXHIBITION_HALL_MODE])
            {
                Data[0] = 1;  /* 0x1:OFF */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LightShowSwt, Data);
            }
            else
            {
                Data[0] = 0;  /* 0x0:No action */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LightShowSwt, Data);
            }
            #endif

			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P03)
			/* 迎宾灯光秀：接近灯光秀 */
            if(1 == Object->VehicleConfig[VCONFIG_KIND_CLOSE_TO_LIGHTING_FUNCTION])
            {
                Data[0] = 2;  /* 0x2:Animation mode1(on) */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ApprLightSwt, Data);

            }
            else
            {
                Data[0] = 0;  /* 0x0:No action */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ApprLightSwt, Data);
            }
			#endif
    	}
	    else
    	{
    		/* 随速天窗 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03)
    		Data[0] = 0;	/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SrSpdCtrlSwt, Data);
    		#endif

    		/* 紧急制动     配置字TBD*/
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
				(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    		Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ABSLmpSet, Data);
    		#endif

    		/* 智能安全带 减少安全带松弛量(主驾) */
    		#if (defined SWC_IPC_PROJECT_TYPE_D03) //|| (defined SWC_IPC_PROJECT_TYPE_D03)
			Data[0] = 1;  /* 0x1:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIBSRSwtSet, Data);
    		#endif

			/* 智能安全带 减少安全带松弛量(副驾) */
    		#if (defined SWC_IPC_PROJECT_TYPE_P03)
			// || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
			Data[0] = 1;  /* 0x1:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMI_P_BSR_SwtSet, Data);
    		#endif

			/* 智能安全带 安全带震动提醒 */
    		#if (defined SWC_IPC_PROJECT_TYPE_D03) //|| (defined SWC_IPC_PROJECT_TYPE_D01)
			Data[0] = 1;  /* 0x1:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIHWSwtSet, Data);
    		#endif

			#ifdef SWC_IPC_PROJECT_TYPE_B02
    	    /* 迎宾灯光秀：灯光秀总开关 */
            Data[0] = 0;  /*0x0:No action*/
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WelLightMainSwt, Data);
            /* 迎宾灯光秀：解锁灯光秀 */
            Data[0] = 0;  /*0x0:No action*/
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_UnlockWelLightSwt, Data);
            /* 迎宾灯光秀：闭锁灯光秀 */
            Data[0] = 0;  /*0x0:No action*/
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWelLightSwt, Data);
            /* 迎宾灯光秀：展车灯光秀 */
            Data[0] = 0;  /*0x0:No action*/
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LightShowSwt, Data);
            #endif

			#if (defined SWC_IPC_PROJECT_TYPE_B02)
			/* 迎宾灯光秀：接近灯光秀 */
            Data[0] = 0;  /*0x0:No action*/
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ApprLightSwt, Data);
			#endif

    		SWC_IPC_PRINT_ERROR("Restore can signal value phase 2 read vehicle config faild!");
    	}
    }
}

 /**********************************************************************************************************
 *Function	 : IPC_OS_RestoreTxCanSignalPhase2 															   *
 *																										   *
 *Description:																							   *
 *																										   *
 *Parameter  : SWC_IPC_AppMsgObject * Object															   *
 *																										   *
 *Return	 : void 																					   *
 *																										   *
 *Author	 : XU																				           *
 *																										   *
 *Date		 : 2022-02-15																				   *
 **********************************************************************************************************/
 static void IPC_OS_RestoreTxCanSignalPhase2(SWC_IPC_AppMsgObject * Object)
 {
	 uint8 Data[1];
	 //VconfigKind_Allbuffers Object->VehicleConfig;
	 (void)Object;

	 if (E_OK == Rte_Read_Vconfig_GetKindBuffers_AllKinds(Object->VehicleConfig))
	 {
		 if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
		 {
			 (void)SWC_IPC_PRINT_DEBUG("%s", __FUNCTION__);

			 /* 随速天窗 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03)
			 if(1 == Object->VehicleConfig[VCONFIG_KIND_SPEED__SENSING_SUNROOF_SWITCH])
			 {
				 Data[0] = 0;	 /* 0x0:OFF */
				 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SrSpdCtrlSwt, Data);
			 }
			 else
			 {
				 Data[0] = 0;	 /* 0x0:OFF */
				 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SrSpdCtrlSwt, Data);
			 }
    		#endif

			 /* 紧急制动	 配置字TBD*/
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				 (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
				 (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
			 if(1 == Object->VehicleConfig[VCONFIG_KIND_ESS_SYSTEM])
			 {
				 Data[0] = 1;/* 0x1:ON */
				 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ABSLmpSet, Data);
			 }
			 else
			 {
				 Data[0] = 0;/* 0x0:OFF */
				 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ABSLmpSet, Data);
			 }
    		#endif

			 /* 智能安全带 减少安全带松弛量(主驾) */
    		#if (defined SWC_IPC_PROJECT_TYPE_D01)  || (defined SWC_IPC_PROJECT_TYPE_D03)
			 if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]))
			 {
				 Data[0] = 2;  /* 0x2:ON */
				 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIBSRSwtSet, Data);
			 }
			 else
			 {
				 Data[0] = 1;  /* 0x1:OFF */
				 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIBSRSwtSet, Data);
			 }
    		#endif

			 /* 智能安全带 减少安全带松弛量(副驾) */
    		#if (defined SWC_IPC_PROJECT_TYPE_P03) \
			 //|| (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
			 if ((1 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_BELT]))
			 {
				 Data[0] = 2;  /* 0x2:ON */
				 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMI_P_BSR_SwtSet, Data);
			 }
			 else
			 {
				 Data[0] = 1;  /* 0x1:OFF */
				 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMI_P_BSR_SwtSet, Data);
			 }
    		#endif

			 /* 智能安全带 安全带震动提醒 */
    		#if (defined SWC_IPC_PROJECT_TYPE_D01)  || (defined SWC_IPC_PROJECT_TYPE_D03)
			 if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]))
			 {
				 Data[0] = 2;  /* 0x2:ON */
				 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIHWSwtSet, Data);
			 }
			 else
			 {
				 Data[0] = 1;  /* 0x1:OFF */
				 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIHWSwtSet, Data);
			 }
    		#endif

			#ifdef SWC_IPC_PROJECT_TYPE_B02
			 if((1 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION]) || (2 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION]) || (3 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION]))
			 {
				 /* 迎宾灯光秀：灯光秀总开关 */
				 Data[0] = 2;  /* 0x2:ON */
				 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WelLightMainSwt, Data);

				 if(1 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION])
				 {
					  /* 迎宾灯光秀：解锁灯光秀 */
					 Data[0] = 0x3;  /* 0x3:on */
					 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_UnlockWelLightSwt, Data);
					 /* 迎宾灯光秀：闭锁灯光秀 */
					 Data[0] = 0;  /*0x0:No action*/
					 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWelLightSwt, Data);

				 }
				 else if(2 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION])
				 {
					 /* 迎宾灯光秀：解锁灯光秀 */
					 Data[0] = 0;  /*0x0:No action*/
					 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_UnlockWelLightSwt, Data);
					 /* 迎宾灯光秀：闭锁灯光秀 */
					 Data[0] = 0x3;  /* 0x3:on */
					 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWelLightSwt, Data);

				 }
				 else
				 {
					  /* 迎宾灯光秀：解锁灯光秀 */
					 Data[0] = 0x3;  /* 0x3:on */
					 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_UnlockWelLightSwt, Data);
					 /* 迎宾灯光秀：闭锁灯光秀 */
					 Data[0] = 0x3;  /* 0x3:on */
					 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWelLightSwt, Data);

				 }
			 }
			 else
			 {
				 /* 迎宾灯光秀：灯光秀总开关 */
				 Data[0] = 0;  /* 0x0:No action */
				 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WelLightMainSwt, Data);
				 /* 迎宾灯光秀：解锁灯光秀 */
				 Data[0] = 0;  /* 0x0:No action */
				 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_UnlockWelLightSwt, Data);
				 /* 迎宾灯光秀：闭锁灯光秀 */
				 Data[0] = 0;  /* 0x0:No action */
				 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWelLightSwt, Data);
			 }

			 /* 迎宾灯光秀：展车灯光秀 */
			 if(1 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_EXHIBITION_HALL_MODE])
			 {
				 Data[0] = 1;  /* 0x1:OFF */
				 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LightShowSwt, Data);
			 }
			 else
			 {
				 Data[0] = 0;  /* 0x0:No action */
				 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LightShowSwt, Data);
			 }
            #endif

			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P03)
			 /* 迎宾灯光秀：接近灯光秀 */
			 if(1 == Object->VehicleConfig[VCONFIG_KIND_CLOSE_TO_LIGHTING_FUNCTION])
			 {
				 Data[0] = 2;  /* 0x2:Animation mode1(on) */
				 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ApprLightSwt, Data);

			 }
			 else
			 {
				 Data[0] = 0;  /* 0x0:No action */
				 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ApprLightSwt, Data);
			 }
			#endif
		 }
		 else
		 {
			 /* 随速天窗 */
    		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03)
			 Data[0] = 0;	 /* 0x0:OFF */
			 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SrSpdCtrlSwt, Data);
    		#endif

			 /* 紧急制动	 配置字TBD*/
    		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
				 (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
				 (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
			 Data[0] = 0;/* 0x0:OFF */
			 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ABSLmpSet, Data);
    		#endif

			 /* 智能安全带 减少安全带松弛量(主驾) */
    		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03)
			 Data[0] = 1;  /* 0x1:OFF */
			 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIBSRSwtSet, Data);
    		#endif

			 /* 智能安全带 减少安全带松弛量(副驾) */
    		#if (defined SWC_IPC_PROJECT_TYPE_P03)
			 // || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
			 Data[0] = 1;  /* 0x1:OFF */
			 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMI_P_BSR_SwtSet, Data);
    		#endif

			 /* 智能安全带 安全带震动提醒 */
    		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03)
			 Data[0] = 1;  /* 0x1:OFF */
			 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIHWSwtSet, Data);
    		#endif

			#ifdef SWC_IPC_PROJECT_TYPE_B02
			 /* 迎宾灯光秀：灯光秀总开关 */
			 Data[0] = 0;  /*0x0:No action*/
			 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WelLightMainSwt, Data);
			 /* 迎宾灯光秀：解锁灯光秀 */
			 Data[0] = 0;  /*0x0:No action*/
			 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_UnlockWelLightSwt, Data);
			 /* 迎宾灯光秀：闭锁灯光秀 */
			 Data[0] = 0;  /*0x0:No action*/
			 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWelLightSwt, Data);
			 /* 迎宾灯光秀：展车灯光秀 */
			 Data[0] = 0;  /*0x0:No action*/
			 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LightShowSwt, Data);
            #endif

			#if (defined SWC_IPC_PROJECT_TYPE_B02)
			 /* 迎宾灯光秀：接近灯光秀 */
			 Data[0] = 0;  /*0x0:No action*/
			 IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ApprLightSwt, Data);
			#endif

			 SWC_IPC_PRINT_ERROR("Restore can signal value phase 2 read vehicle config faild!");
		 }
	 }
 }


#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P03)\
 || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) \
 || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) //|| (defined SWC_IPC_PROJECT_TYPE_P05)// || (defined SWC_IPC_PROJECT_TYPE_A07)
static void IPC_DriveModSwitchMonitor(SWC_IPC_AppMsgObject * Object)
{
	uint8 DrvMod = 0;
	uint8 Sig_DrivingModReq_ESP = 0;
	uint8 EgyRecvrySet = 0;
	uint8 Data[4] = {0};

	if ((5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]) &&\
		((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL]) || (4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])))
	{
		/*RE3000*/
		IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_DrvModReq, &DrvMod);
		IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, &EgyRecvrySet);

		if (0xA != DrvMod)
		{
			if ((0x05 == DrvMod) && (0x05 != Object->DriveMode))
			{
				/* Other mode switch to snow mode */
				if (0 == EgyRecvrySet)
				{
					Data[0] = 2;
					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, Data);
				}
				else
				{
					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, SWC_IPC_NULL);
				}
			}
			else if ((0x05 != DrvMod) && (0x05 == Object->DriveMode))
			{
				/* Snow mode switch to other mode */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, &Object->AppNvm.HUT_EgyRecvrySet);
			}
			else
			{
				/*do nothing*/
			}

			if (0x05 != DrvMod)
			{
				if (Object->AppNvm.HUT_EgyRecvrySet != EgyRecvrySet)
				{
					Object->AppNvm.HUT_EgyRecvrySet = EgyRecvrySet ;
				}
			}

			Object->DriveMode = DrvMod;
		}
		else
		{
			if(0x05 != Object->DriveMode)
			{
				if (Object->AppNvm.HUT_EgyRecvrySet != EgyRecvrySet)
				{
					Object->AppNvm.HUT_EgyRecvrySet = EgyRecvrySet ;
				}
			}
		}
	}
	else if((8 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]) &&\
		((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL]) || (4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])))
	{
		/*纵置P2*/
		#if (!defined SWC_IPC_PROJECT_TYPE_P01) && (!defined SWC_IPC_PROJECT_TYPE_P03)
		IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_ESP, &Sig_DrivingModReq_ESP);
		#endif
		IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, &EgyRecvrySet);

		if (((0x01 == Object->DriveMode) || (0x02 == Object->DriveMode) || (0x0A == Object->DriveMode)) &&\
			((0x03 == Sig_DrivingModReq_ESP) || (0x0C == Sig_DrivingModReq_ESP) || (0x13 == Sig_DrivingModReq_ESP) || \
			(0x05 == Sig_DrivingModReq_ESP) || (0x07 == Sig_DrivingModReq_ESP) || (0x1D == Sig_DrivingModReq_ESP)))
		{
			/* 标准、经济、运动模式下 --> 雪地、泥地、沙地、Wade_4H */
			if (0 == Object->AppNvm.HUT_EgyRecvrySet)
			{
				Data[0] = 2;
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, Data);
			}
			else
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, &Object->AppNvm.HUT_EgyRecvrySet);
			}
		}
		else if (((0x01 == Object->DriveMode) || (0x02 == Object->DriveMode) || (0x0A == Object->DriveMode) || \
				(0x03 == Object->DriveMode) || (0x0C == Object->DriveMode) || (0x13 == Object->DriveMode) || \
				(0x05 == Object->DriveMode) || (0x07 == Object->DriveMode) || (0x1D == Object->DriveMode)) &&\
				((0x09 == Sig_DrivingModReq_ESP) || (0x15 == Sig_DrivingModReq_ESP)))
		{
			/* 标准、经济、运动、雪地、泥地、沙地、Wade_4H --> 4L、Rock 4L */
			Data[0] = 2;
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, Data);
		}
		else if (((0x03 == Sig_DrivingModReq_ESP) || (0x0C == Sig_DrivingModReq_ESP) || (0x13 == Sig_DrivingModReq_ESP) ||\
				(0x1D == Sig_DrivingModReq_ESP) || (0x05 == Sig_DrivingModReq_ESP) || (0x07 == Sig_DrivingModReq_ESP)) &&\
				((0x09 == Object->DriveMode) || (0x15 == Object->DriveMode)))
		{
			/* 4L、Rock 4L --> 雪地、泥地、沙地、Wade_4H */
			if (0 == Object->AppNvm.HUT_EgyRecvrySet)
			{
				Data[0] = 2;
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, Data);
			}
			else
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, &Object->AppNvm.HUT_EgyRecvrySet);
			}
		}
		else if(((0x01 != Object->DriveMode) && (0x02 != Object->DriveMode) && (0x0A != Object->DriveMode)) &&\
		((0x01 == Sig_DrivingModReq_ESP) || (0x02 == Sig_DrivingModReq_ESP) || (0x0A == Sig_DrivingModReq_ESP)))
		{
			/* 其它模式 --> 标准、经济、运动模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, &Object->AppNvm.HUT_EgyRecvrySet);
		}
		else
		{
			/*do nothing*/
		}

		if((0x01 == Sig_DrivingModReq_ESP) || (0x02 == Sig_DrivingModReq_ESP) || (0x0A == Sig_DrivingModReq_ESP))
		{
			Object->AppNvm.HUT_EgyRecvrySet = EgyRecvrySet ;
		}

		Object->DriveMode = Sig_DrivingModReq_ESP;
	}
	else if(5 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
	{
		/*EV*/
		/* 预留 */
	}
	else
	{

	}
}
#endif

/**********************************************************************************************************
*Function   : IPC_VehicleControlDriveModeOutput                                                            *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-28                                                                                  *
**********************************************************************************************************/
#if 0
static void IPC_VehicleControlDriveModeOutput(SWC_IPC_AppMsgObject * Object)
{
	uint8 DriveMode = 0 , MatchFlag;
	uint8* Object->VehicleConfig = SWC_IPC_NULL;
	uint8 Object->VehicleConfigIndex , ConfigIndex , Index;
	uint8 DriveModeConfigMatrix[] =
		{3, /*Total Config Number*/
		   0,0, /*No drive mode config*/
		   2,4, /*ZA520 - B03*/
	    		0x0, /*0x0:Standard/Normal*/
				0x1, /*0x1:Snow*/
				0x3, /*0x3:Economic*/
				0x4, /*0x4:Sport*/
		   8,6, /*ZA572 - B03*/
	    		0x0, /*0x0:Standard/Normal*/
				0x1, /*0x1:Snow*/
				0x3, /*0x3:Economic*/
				0x4, /*0x4:Sport*/
				0xD, /*0xD:Sand*/
				0x2, /*0x2:Off-Road*/
		 };

	Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();

	if (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_SIGNAL_SELECT])
	{
		if (1 == Object->VehicleConfig[VCONFIG_KIND_MEMORY_OF_DRIVING_MODE])
		{
			IPC_API_GetTxCanSignal(SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, &DriveMode);

			ConfigIndex = 1;
			MatchFlag = FALSE;
			for(Object->VehicleConfigIndex = 0; Object->VehicleConfigIndex < DriveModeConfigMatrix[0] ; Object->VehicleConfigIndex ++)
			{
				if (Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_OPTIONAL] == DriveModeConfigMatrix[ConfigIndex])
				{
					for (Index = 0 ; Index < DriveModeConfigMatrix[ConfigIndex + 1] ; Index++)
					{
						if (DriveMode == DriveModeConfigMatrix[ConfigIndex + 2 + Index])
						{
							MatchFlag = TRUE;
							break;
						}
					}
					break;
				}

				ConfigIndex += (2 + DriveModeConfigMatrix[ConfigIndex + 1]);
			}
			if (MatchFlag == FALSE)
			{
				DriveMode = 0; /*0x0:Standard/Normal*/
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, &DriveMode);
			}
			else
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, SWC_IPC_NULL);
			}
		}
		else
		{
			DriveMode = 0; /*0x0:Standard/Normal*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, &DriveMode);
		}
	}
}
#endif
/**********************************************************************************************************
*Function   : IPC_ComWakePhase1CanSignalOutput                                                            *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-28                                                                                  *
**********************************************************************************************************/
static void IPC_ComWakePhase1CanSignalOutput(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[1];
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;

	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();

    (void)SWC_IPC_PRINT_DEBUG("%s", __FUNCTION__);
	if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
	{
		/* 疲劳驾驶 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03) || \
			(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_P02)
	    if (1 == Object->VehicleConfig[VCONFIG_KIND_DROWSINESS_WARNING_SYSTEM])
		{
	        IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDrowsnsDetnSet, SWC_IPC_NULL);
		}
		#endif

		/* 主驾驶座椅按摩设置 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
		{
			Data[0] = 0; /*0x0:Off*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgLvlSet, Data);
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		/* 主驾座椅记忆 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03)\
		 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
		 	(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (4 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (6 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (7 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (8 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
		{
			if ((1 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE]) || \
				(5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE]))
			{
				Data[0] = 0; /*0x0:No Command*/
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSet, Data);
				Data[0] = 0; /*0x0:FactoryDefault*/
				IPC_API_SetTxCanSignalNotStore((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, Data);
			}
		}
		#endif

		/* 外后视镜倒车模式 KAG*/
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]) || (5 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]))
		{
			IPC_API_SetTxCanSignalNotStore((uint32)SWC_IPC_CAN_SIGNAL_OrvmPosnEnaSts, SWC_IPC_NULL);
		}

		/* 灯光控制 : 照我回家延时时间设置*/
		if (1 == Object->VehicleConfig[VCONFIG_KIND_HEAD_LAMP_AUTO_OFF])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FolwMeHomeDlyTimSet, SWC_IPC_NULL);
		}

		/* 灯光控制 : 运动模式灯光设置 */
		// #if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_A07)
		//  || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_D03)
		#if 0
		if (1 == Object->VehicleConfig[VCONFIG_KIND_SPORTS_MODE_LIGHTING_PROMPT_S_REPEATER])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SportModLightSet, SWC_IPC_NULL);
		}
		#endif

		/* Parking lights */
		#if (defined SWC_IPC_PROJECT_TYPE_P02) //|| (defined SWC_IPC_PROJECT_TYPE_D01)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_PARKING_LAMP])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ParkLmpSet, SWC_IPC_NULL);
		}
		#endif

		/* 360环视 : 环视退出车速值设置 */
		if ((0 != Object->VehicleConfig[VCONFIG_KIND_OMNIVIEW_SYSTEM]) || (0 != Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PASExitSpdSwt, SWC_IPC_NULL);
		}

		/* D档低速开启360环视 */
		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_OMNIVIEW_AUTO_TURN_ON_AT_LOW_SPEED])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AVMAutoSet, SWC_IPC_NULL);
		}
		#endif

		/* 解闭锁提示 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_BLOCKING_PROMPT_TYPE])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockPromptFunSet, SWC_IPC_NULL);
		}
		#endif

		/* 蓝牙泊车 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 || (5 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 || (6 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 || (7 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
		{
			/* 蓝牙泊入自动闭锁 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPAEntryLockSet, SWC_IPC_NULL);
			/* 蓝牙泊出自动解锁 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPALvngUnlockSet, SWC_IPC_NULL);
		}
		#endif

		/* 解锁模式 */
		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_DOOR_UNLOCK_MODE])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DoorUnlockModSet, SWC_IPC_NULL);
		}
		#endif

		/* 紧急制动     配置字TBD*/
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_ESS_SYSTEM])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ABSLmpSet, SWC_IPC_NULL);
		}
		#endif

		/* 副驾驶座椅按摩设置 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
		{
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgLvlSet, Data);
			/* 按摩模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		/* 主动进入解锁 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryUnlockSet, SWC_IPC_NULL);
		}
		#endif

		/* 主动离开闭锁 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if ((2 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryLockSet, SWC_IPC_NULL);
		}
		#endif

		/* 氛围灯 */
		/* SAQ60:轮廓；SAQ70:面发光；SAQ80:面发光； */
		/* ZK100：无音乐律动；ZK110：ALCM/CEM解析音乐律动；ZK120：主机解析 */
		/* ZK200：无分区联动（智能联动）；ZK210：有分区联动（智能联动）； */
		/* ZQ600：无氛围灯分区开关；ZQ610：有氛围灯分区开关 */
		/* 氛围灯及背景光(SAQ):VCONFIG_KIND_MOOD_LAMP */
		/* 多色律动氛围灯音频解析方式(ZK1):VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP */
		/* 氛围灯分区功能(ZK2):VCONFIG_KIND_MOOD_LAMP_PARTITION */
		/* 氛围灯分区点亮开关控制(ZQ6):VCONFIG_KIND_AMBIENT_LIGHT_CONTROL */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03)// || (defined SWC_IPC_PROJECT_TYPE_A07)
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP])))
		{
			/* 轮廓氛围灯颜色选择 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet, SWC_IPC_NULL);
			/* 轮廓氛围灯多色彩静态 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt, SWC_IPC_NULL);
			/* 轮廓氛围灯多色彩动态 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) \
			// ||(defined SWC_IPC_PROJECT_TYPE_A07)
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP])))
		{
			/* 轮廓氛围灯呼吸灯 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01)
		if(((6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP])))
		{
			/* 面发光氛围灯流水灯设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMFloSwt, SWC_IPC_NULL);

			/* 面发光氛围灯颜色选择 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet_OLE, SWC_IPC_NULL);
			/* 面发光氛围灯多色彩静态模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt_OLE, SWC_IPC_NULL);
			/* 面发光氛围灯多色彩动态模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet_OLE, SWC_IPC_NULL);
			/* 面发光氛围灯呼吸灯设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt_OLE, SWC_IPC_NULL);
			/* 面发光氛围灯流水灯设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr1, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr2, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr3, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr4, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr5, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr6, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr7, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr8, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr9, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr10, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr11, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr12, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr13, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr14, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr15, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr16, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03)
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
		 && ((1 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP]) || (2 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP])))
		{
			/* 轮廓氛围灯音乐律动 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMRhmSwt, SWC_IPC_NULL);
		}
		#endif

		/* 货箱照明设置(皮卡) */
		#if defined SWC_IPC_PROJECT_TYPE_P05
		if (1 == Object->VehicleConfig[VCONFIG_KIND_DECK_LAMP])
		{
			/* 货厢灯自动开启功能 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FreightLmpAutoSet, SWC_IPC_NULL);
		}
		#endif

		/* 方向盘加热：开关 */
		if(1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_HEATING])
		{
			Data[0] = 1;  /*0x1:No request*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerWheelHeatSwtReq, Data);
		}

		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
			&& (1 == Object->VehicleConfig[VCONFIG_KIND_AMBIENT_LIGHT_CONTROL]))
		{
			/* 分区开关:左侧仪表板氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LeftPanelALCMSwt, SWC_IPC_NULL);
			/* 分区开关：右侧仪表板氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RightPanelALCMSwt, SWC_IPC_NULL);
			/* 分区开关：主驾氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：副驾氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：左后门氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LRDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：右后门氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：脚窝氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FootALCMSwt, SWC_IPC_NULL);
			/* 分区开关：顶棚氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofALCMSwt, SWC_IPC_NULL);
		}
		#endif

		/* 后排左侧座椅按摩设置 ZV2+ZS9 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
		{
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgLvlSet, Data);
			/* 按摩模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		/* 后排右侧座椅按摩设置 ZV3+ZS9 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
		{
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgLvlSet, Data);
			/* 按摩模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
		/* 雨刮间歇档位 / 灵敏度调节 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_WIPER_INTERMITTENT_LEVEL_VIRTUAL_SW])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSSensitivityReq_HUT, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D02)
		/* 副驾座椅非个性化记忆 副驾座椅迎宾 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_SEAT_WELCOME_FUNCTION])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_Pass, SWC_IPC_NULL);
		}
		#endif

		/* 前排座椅迎宾 PAA*/
		if ((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
			|| (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna, SWC_IPC_NULL);
		}

		/* 座椅设置:后排座椅迎宾 */
		#if(defined SWC_IPC_PROJECT_TYPE_P05)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_2ND_ROW_SEAT_WELCOME_FUNCTION])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_SecRow, SWC_IPC_NULL);
		}
		#endif

  		/* 外后视镜自动折叠 */
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
	     || (2 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
	     || (3 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
	     || (4 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearviewFoldModSet, SWC_IPC_NULL);
		}

		/* 电动侧踏 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if (6 == Object->VehicleConfig[VCONFIG_KIND_SIDE_STEP])
		{
			/* 电动侧踏开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ElecSideSteppingSysSet, SWC_IPC_NULL);
			/* 特殊模式开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AllTerrainDislSet, SWC_IPC_NULL);
			/* 车顶模式开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofModSet, SWC_IPC_NULL);
		}
		#endif

		/* 车速关窗 && 闭锁关窗 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		/* 车速关窗 */
		if (((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]))
	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]))
	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]))
		 && (1 == Object->VehicleConfig[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ClsWinSpdSet, SWC_IPC_NULL);
		}

		/* 闭锁关窗 */
		if (((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]))
    	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]))
    	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]))
    		 && (1 == Object->VehicleConfig[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE])
			 && ((1 == Object->VehicleConfig[VCONFIG_KIND_DOOR_MODULE_TYPE]) || (2 == Object->VehicleConfig[VCONFIG_KIND_DOOR_MODULE_TYPE])))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWinSet, SWC_IPC_NULL);
		}
		#endif

		/* 后排左右侧座椅 一键躺倒 */
		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if (((4 == Object->VehicleConfig[VCONFIG_KIND_SEAT_CONTROL_MODULE]) || (5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_CONTROL_MODULE]) ||\
		(6 == Object->VehicleConfig[VCONFIG_KIND_SEAT_CONTROL_MODULE])) && (1 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_SEAT_FAST_SET]))
		{
			Data[0] = 0;  /* 0x0:no action */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearSeatLieFlatOneBtn, Data);
		}
		#endif

		/* 车窗短升短降 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_WINDOW_SHORT_LIFT_DROP_FUNCTION])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WinShortUpShortDownSet, SWC_IPC_NULL);
		}
		#endif

		/* 方向盘未回正提醒功能开关 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_WHEEL_BACK_REMINDER])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerCorrnReq, SWC_IPC_NULL);
		}
		#endif

	}
	else
	{
		SWC_IPC_PRINT_ERROR("Vehicle control can signal wake up phase 1 read vehicle config faild!");
	}

	/* 门锁设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SpdAutoLockModSet, SWC_IPC_NULL);
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FlaoutUnlockSet, SWC_IPC_NULL);

	/* 前雨刮 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoWshWipSet, SWC_IPC_NULL);

	/* 灯光控制 : 节电延时时间设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BattSaveDelayTimeSet, SWC_IPC_NULL);

	/* 灯光控制 : 顶灯延时时间设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DomeLmpDlyTimSet, SWC_IPC_NULL);

	/* 灯光控制 : 寻车功能模式设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SeekVehSet, SWC_IPC_NULL);

	/* 灯光控制 : 主动迎宾设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ApproachLampSet, SWC_IPC_NULL);

	/* 按键背光 */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BackgroundLightLvlSet, SWC_IPC_NULL);

	/* 储运模式 : TranPMode_Req*/
	Data[0] = Object->AppNvm.u8TranPMode_Sts;
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TranPMode_Req, Data);

	/* 智能温控 */
	#if (defined SWC_IPC_PROJECT_TYPE_A07)
	/* 温控区间设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_InCarTempMinSet, SWC_IPC_NULL);
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_InCarTempMaxSet, SWC_IPC_NULL);
	/* 智能空调 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SmtACSwt, SWC_IPC_NULL);
	/* 智能座椅通风加热 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SmtSeatSwt, SWC_IPC_NULL);
	/* 智能方向盘加热 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SmtCsaSwt, SWC_IPC_NULL);
	#endif

	/* 时钟背光设定值（中控补偿值） */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BriCmp, SWC_IPC_NULL);
	#endif

	SWC_IPC_PRINT_INFO("Vehicle control can signal wake up phase 1 work start!");
}

/**********************************************************************************************************
*Function   : IPC_OS_ComWakePhase1CanSignalOutput                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : XU                                                                                   		  *
*                                                                                                         *
*Date       : 2022-02-15                                                                                  *
**********************************************************************************************************/
static void IPC_OS_ComWakePhase1CanSignalOutput(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[1];
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;

	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();

    (void)SWC_IPC_PRINT_DEBUG("%s", __FUNCTION__);
	if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
	{
		/* 疲劳驾驶 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || \
			(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
	    if (1 == Object->VehicleConfig[VCONFIG_KIND_DROWSINESS_WARNING_SYSTEM])
		{
	        IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDrowsnsDetnSet, SWC_IPC_NULL);
		}
		#endif

		/* 主驾驶座椅按摩设置 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P01)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
		{
			Data[0] = 0; /*0x0:Off*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgLvlSet, Data);
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		/* 主驾座椅记忆 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03)\
		 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
		 	(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
		 	(defined SWC_IPC_PROJECT_TYPE_P01)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (4 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (6 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (7 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (8 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
		{
			if ((1 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE]) || \
				(5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE]))
			{
				Data[0] = 0; /*0x0:No Command*/
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSet, Data);
				Data[0] = 0; /*0x0:FactoryDefault*/
				IPC_API_SetTxCanSignalNotStore((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, Data);
			}
		}
		#endif

		/* 外后视镜倒车模式 KAG*/
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]) || (5 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]))
		{
			IPC_API_SetTxCanSignalNotStore((uint32)SWC_IPC_CAN_SIGNAL_OrvmPosnEnaSts, SWC_IPC_NULL);
		}

		/* 灯光控制 : 照我回家延时时间设置*/
		if (1 == Object->VehicleConfig[VCONFIG_KIND_HEAD_LAMP_AUTO_OFF])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FolwMeHomeDlyTimSet, SWC_IPC_NULL);
		}

		/* 灯光控制 : 运动模式灯光设置 */
		// #if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_A07)
		//  || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_D03)
		#if 0
		if (1 == Object->VehicleConfig[VCONFIG_KIND_SPORTS_MODE_LIGHTING_PROMPT_S_REPEATER])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SportModLightSet, SWC_IPC_NULL);
		}
		#endif

		/* Parking lights */
		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) ||\
			(defined SWC_IPC_PROJECT_TYPE_P05)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_PARKING_LAMP])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ParkLmpSet, SWC_IPC_NULL);
		}
		#endif

		/* 360环视 : 环视退出车速值设置 */
		if ((0 != Object->VehicleConfig[VCONFIG_KIND_OMNIVIEW_SYSTEM]) || (0 != Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PASExitSpdSwt, SWC_IPC_NULL);
		}

		/* D档低速开启360环视 */
		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_OMNIVIEW_AUTO_TURN_ON_AT_LOW_SPEED])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AVMAutoSet, SWC_IPC_NULL);
		}
		#endif

		/* 解闭锁提示 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_BLOCKING_PROMPT_TYPE])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockPromptFunSet, SWC_IPC_NULL);
		}
		#endif

		/* 蓝牙泊车 */
		#if (defined SWC_IPC_PROJECT_TYPE_P01)
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 || (5 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 || (6 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 || (7 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
		{
			/* 蓝牙泊入自动闭锁 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPAEntryLockSet, SWC_IPC_NULL);
			/* 蓝牙泊出自动解锁 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPALvngUnlockSet, SWC_IPC_NULL);
		}
		#endif

		/* 解锁模式 */
		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_DOOR_UNLOCK_MODE])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DoorUnlockModSet, SWC_IPC_NULL);
		}
		#endif

		/* 紧急制动     配置字TBD*/
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_ESS_SYSTEM])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ABSLmpSet, SWC_IPC_NULL);
		}
		#endif

		/* 副驾驶座椅按摩设置 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
			(defined SWC_IPC_PROJECT_TYPE_P01)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
		{
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgLvlSet, Data);
			/* 按摩模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		/* 主动进入解锁 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryUnlockSet, SWC_IPC_NULL);
		}
		#endif

		/* 主动离开闭锁 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if ((2 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryLockSet, SWC_IPC_NULL);
		}
		#endif

		/* 氛围灯 */
		/* SAQ60:轮廓；SAQ70:面发光；SAQ80:面发光； */
		/* ZK100：无音乐律动；ZK110：ALCM/CEM解析音乐律动；ZK120：主机解析 */
		/* ZK200：无分区联动（智能联动）；ZK210：有分区联动（智能联动）； */
		/* ZQ600：无氛围灯分区开关；ZQ610：有氛围灯分区开关 */
		/* 氛围灯及背景光(SAQ):VCONFIG_KIND_MOOD_LAMP */
		/* 多色律动氛围灯音频解析方式(ZK1):VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP */
		/* 氛围灯分区功能(ZK2):VCONFIG_KIND_MOOD_LAMP_PARTITION */
		/* 氛围灯分区点亮开关控制(ZQ6):VCONFIG_KIND_AMBIENT_LIGHT_CONTROL */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)//|| (defined SWC_IPC_PROJECT_TYPE_A07)
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP])))
		{
			/* 轮廓氛围灯颜色选择 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet, SWC_IPC_NULL);
			/* 轮廓氛围灯多色彩静态 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt, SWC_IPC_NULL);
			/* 轮廓氛围灯多色彩动态 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) \
			// || (defined SWC_IPC_PROJECT_TYPE_A07)
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP])))
		{
			/* 轮廓氛围灯呼吸灯 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01)
		if(((6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP])))
		{
			/* 面发光氛围灯流水灯设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMFloSwt, SWC_IPC_NULL);

			/* 面发光氛围灯颜色选择 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet_OLE, SWC_IPC_NULL);
			/* 面发光氛围灯多色彩静态模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt_OLE, SWC_IPC_NULL);
			/* 面发光氛围灯多色彩动态模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet_OLE, SWC_IPC_NULL);
			/* 面发光氛围灯呼吸灯设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt_OLE, SWC_IPC_NULL);
			/* 面发光氛围灯流水灯设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr1, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr2, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr3, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr4, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr5, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr6, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr7, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr8, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr9, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr10, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr11, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr12, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr13, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr14, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr15, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr16, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
		 && ((1 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP]) || (2 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP])))
		{
			/* 轮廓氛围灯音乐律动 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMRhmSwt, SWC_IPC_NULL);
		}
		#endif

		/* 货箱照明设置(皮卡) */
		#if defined SWC_IPC_PROJECT_TYPE_P05
		if (1 == Object->VehicleConfig[VCONFIG_KIND_DECK_LAMP])
		{
			/* 货厢灯自动开启功能 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FreightLmpAutoSet, SWC_IPC_NULL);
		}
		#endif

		/* 方向盘加热：开关 */
		if(1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_HEATING])
		{
			Data[0] = 1;  /*0x1:No request*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerWheelHeatSwtReq, Data);
		}

		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
			&& (1 == Object->VehicleConfig[VCONFIG_KIND_AMBIENT_LIGHT_CONTROL]))
		{
			/* 分区开关:左侧仪表板氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LeftPanelALCMSwt, SWC_IPC_NULL);
			/* 分区开关：右侧仪表板氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RightPanelALCMSwt, SWC_IPC_NULL);
			/* 分区开关：主驾氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：副驾氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：左后门氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LRDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：右后门氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：脚窝氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FootALCMSwt, SWC_IPC_NULL);
			/* 分区开关：顶棚氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofALCMSwt, SWC_IPC_NULL);
		}
		#endif

		/* 后排左侧座椅按摩设置 ZV2+ZS9 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
		{
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgLvlSet, Data);
			/* 按摩模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		/* 后排右侧座椅按摩设置 ZV3+ZS9 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_P01)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
		{
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgLvlSet, Data);
			/* 按摩模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
		/* 雨刮间歇档位 / 灵敏度调节 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_WIPER_INTERMITTENT_LEVEL_VIRTUAL_SW])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSSensitivityReq_HUT, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03)//|| (defined SWC_IPC_PROJECT_TYPE_P01) || (defined SWC_IPC_PROJECT_TYPE_D02)
		/* 副驾座椅非个性化记忆 副驾座椅迎宾 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_SEAT_WELCOME_FUNCTION])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_Pass, SWC_IPC_NULL);
		}
		#endif

		/* 前排座椅迎宾 PAA*/
		if ((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
			|| (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna, SWC_IPC_NULL);
		}

		/* 座椅设置:后排座椅迎宾 */
		#if(defined SWC_IPC_PROJECT_TYPE_P05)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_2ND_ROW_SEAT_WELCOME_FUNCTION])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_SecRow, SWC_IPC_NULL);
		}
		#endif

  		/* 外后视镜自动折叠 */
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
	     || (2 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
	     || (3 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
	     || (4 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearviewFoldModSet, SWC_IPC_NULL);
		}

		/* 电动侧踏 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_P01)
		if (6 == Object->VehicleConfig[VCONFIG_KIND_SIDE_STEP])
		{
			/* 电动侧踏开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ElecSideSteppingSysSet, SWC_IPC_NULL);
			/* 特殊模式开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AllTerrainDislSet, SWC_IPC_NULL);
			/* 车顶模式开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofModSet, SWC_IPC_NULL);
		}
		#endif

		/* 车速关窗 && 闭锁关窗 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
		/* 车速关窗 */
		if (((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]))
	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]))
	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]))
		 && (1 == Object->VehicleConfig[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ClsWinSpdSet, SWC_IPC_NULL);
		}

		/* 闭锁关窗 */
		if (((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]))
    	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]))
    	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]))
    		 && (1 == Object->VehicleConfig[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE])
			 && ((1 == Object->VehicleConfig[VCONFIG_KIND_DOOR_MODULE_TYPE]) || (2 == Object->VehicleConfig[VCONFIG_KIND_DOOR_MODULE_TYPE])))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWinSet, SWC_IPC_NULL);
		}
		#endif

		/* 后排左右侧座椅 一键躺倒 */
		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if (((4 == Object->VehicleConfig[VCONFIG_KIND_SEAT_CONTROL_MODULE]) || (5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_CONTROL_MODULE]) ||\
		(6 == Object->VehicleConfig[VCONFIG_KIND_SEAT_CONTROL_MODULE])) && (1 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_SEAT_FAST_SET]))
		{
			Data[0] = 0;  /* 0x0:no action */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearSeatLieFlatOneBtn, Data);
		}
		#endif

		/* 车窗短升短降 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_WINDOW_SHORT_LIFT_DROP_FUNCTION])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WinShortUpShortDownSet, SWC_IPC_NULL);
		}
		#endif

		/* 方向盘未回正提醒功能开关 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_WHEEL_BACK_REMINDER])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerCorrnReq, SWC_IPC_NULL);
		}
		#endif

	}
	else
	{
		SWC_IPC_PRINT_ERROR("Vehicle control can signal wake up phase 1 read vehicle config faild!");
	}

	/* 门锁设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SpdAutoLockModSet, SWC_IPC_NULL);
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FlaoutUnlockSet, SWC_IPC_NULL);

	/* 前雨刮 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoWshWipSet, SWC_IPC_NULL);

	/* 灯光控制 : 节电延时时间设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BattSaveDelayTimeSet, SWC_IPC_NULL);

	/* 灯光控制 : 顶灯延时时间设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DomeLmpDlyTimSet, SWC_IPC_NULL);

	/* 灯光控制 : 寻车功能模式设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SeekVehSet, SWC_IPC_NULL);

	/* 灯光控制 : 主动迎宾设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ApproachLampSet, SWC_IPC_NULL);

	/* 按键背光 */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BackgroundLightLvlSet, SWC_IPC_NULL);

	/* 储运模式 : TranPMode_Req*/
	Data[0] = Object->AppNvm.u8TranPMode_Sts;
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TranPMode_Req, Data);

	/* 智能温控 */
	#if (defined SWC_IPC_PROJECT_TYPE_A07)
	/* 温控区间设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_InCarTempMinSet, SWC_IPC_NULL);
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_InCarTempMaxSet, SWC_IPC_NULL);
	/* 智能空调 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SmtACSwt, SWC_IPC_NULL);
	/* 智能座椅通风加热 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SmtSeatSwt, SWC_IPC_NULL);
	/* 智能方向盘加热 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SmtCsaSwt, SWC_IPC_NULL);
	#endif

	/* 时钟背光设定值（中控补偿值） */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BriCmp, SWC_IPC_NULL);
	#endif

	SWC_IPC_PRINT_INFO("Vehicle control can signal wake up phase 1 work start!");
}

/**********************************************************************************************************
*Function   : IPC_ComWakePhase2CanSignalOutput                                                            *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-28                                                                                  *
**********************************************************************************************************/
static void IPC_ComWakePhase2CanSignalOutput(SWC_IPC_AppMsgObject * Object)
{
    uint8 Data[1];
    //uint8* Object->VehicleConfig = SWC_IPC_NULL;

	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();

    (void)SWC_IPC_PRINT_DEBUG("%s", __FUNCTION__);
    if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
    {
        /* 主驾座椅记忆 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03)\
		 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
		 	(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (4 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (6 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (7 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (8 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
		  && ((1 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE])
		  || (5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE])))
		{
			if (0 != Object->ChairMemPosnSetResult)
            {
				Data[0] = 2; /* 0x2:BringUpTheAccout */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSet, Data);
				/* Send saved userID */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, &Object->ChairMemPosnSetResult);
			}
		}
		#endif

		/* 随速天窗 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_SPEED__SENSING_SUNROOF_SWITCH])
		{
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SrSpdCtrlSwt, SWC_IPC_NULL);
		}
		#endif

		/* 智能安全带 减少安全带松弛量(主驾) */
		#if (defined SWC_IPC_PROJECT_TYPE_D03) //|| (defined SWC_IPC_PROJECT_TYPE_D01)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIBSRSwtSet, SWC_IPC_NULL);
		}
		#endif

		/* 智能安全带 减少安全带松弛量(副驾) */
		#if (defined SWC_IPC_PROJECT_TYPE_P03)
		// || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_BELT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMI_P_BSR_SwtSet, SWC_IPC_NULL);
		}
		#endif

		/* 智能安全带 安全带震动提醒 */
		#if (defined SWC_IPC_PROJECT_TYPE_D03) //|| (defined SWC_IPC_PROJECT_TYPE_D01)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIHWSwtSet, SWC_IPC_NULL);
        }
		#endif

		#if(defined SWC_IPC_PROJECT_TYPE_B02)
	    if((1 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION]) || (2 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION]) || (3 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION]))
	    {
    	    /* 迎宾灯光秀：灯光秀总开关 */
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WelLightMainSwt, SWC_IPC_NULL);

            if(1 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION])
            {
                 /* 迎宾灯光秀：解锁灯光秀 */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_UnlockWelLightSwt, SWC_IPC_NULL);

            }
            else if(2 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION])
            {
                /* 迎宾灯光秀：闭锁灯光秀 */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWelLightSwt, SWC_IPC_NULL);

            }
            else
            {
                 /* 迎宾灯光秀：解锁灯光秀 */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_UnlockWelLightSwt, SWC_IPC_NULL);
                /* 迎宾灯光秀：闭锁灯光秀 */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWelLightSwt, SWC_IPC_NULL);

            }
        }
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P03)
        /* 迎宾灯光秀：接近灯光秀 */
        if(1 == Object->VehicleConfig[VCONFIG_KIND_CLOSE_TO_LIGHTING_FUNCTION])
        {
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ApprLightSwt, SWC_IPC_NULL);

        }
        #endif
    }
    else
    {
        SWC_IPC_PRINT_ERROR("Vehicle control can signal wake up phase 2 read vehicle config faild!");
    }

	SWC_IPC_PRINT_INFO("Vehicle control can signal wake up phase 2 work start!");
}


/**********************************************************************************************************
*Function   : IPC_OS_ComWakePhase2CanSignalOutput                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : XU                                                                                          *
*                                                                                                         *
*Date       : 2022-02-15                                                                                  *
**********************************************************************************************************/
static void IPC_OS_ComWakePhase2CanSignalOutput(SWC_IPC_AppMsgObject * Object)
{
    uint8 Data[1];
    //uint8* Object->VehicleConfig = SWC_IPC_NULL;

	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();

    (void)SWC_IPC_PRINT_DEBUG("%s", __FUNCTION__);
    if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
    {
        /* 主驾座椅记忆 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03)\
		 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
		 	(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
		 	(defined SWC_IPC_PROJECT_TYPE_P01)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (4 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (6 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (7 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (8 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
		  && ((1 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE])
		  || (5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE])))
		{
			if (0 != Object->ChairMemPosnSetResult)
            {
				Data[0] = 2; /* 0x2:BringUpTheAccout */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSet, Data);
				/* Send saved userID */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, &Object->ChairMemPosnSetResult);
			}
		}
		#endif

		/* 随速天窗 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_SPEED__SENSING_SUNROOF_SWITCH])
		{
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SrSpdCtrlSwt, SWC_IPC_NULL);
		}
		#endif

		/* 智能安全带 减少安全带松弛量(主驾) */
		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIBSRSwtSet, SWC_IPC_NULL);
		}
		#endif

		/* 智能安全带 减少安全带松弛量(副驾) */
		#if (defined SWC_IPC_PROJECT_TYPE_P03)
		// || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_BELT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMI_P_BSR_SwtSet, SWC_IPC_NULL);
		}
		#endif

		/* 智能安全带 安全带震动提醒 */
		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIHWSwtSet, SWC_IPC_NULL);
        }
		#endif

		#if(defined SWC_IPC_PROJECT_TYPE_B02)
	    if((1 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION]) || (2 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION]) || (3 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION]))
	    {
    	    /* 迎宾灯光秀：灯光秀总开关 */
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WelLightMainSwt, SWC_IPC_NULL);

            if(1 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION])
            {
                 /* 迎宾灯光秀：解锁灯光秀 */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_UnlockWelLightSwt, SWC_IPC_NULL);

            }
            else if(2 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION])
            {
                /* 迎宾灯光秀：闭锁灯光秀 */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWelLightSwt, SWC_IPC_NULL);

            }
            else
            {
                 /* 迎宾灯光秀：解锁灯光秀 */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_UnlockWelLightSwt, SWC_IPC_NULL);
                /* 迎宾灯光秀：闭锁灯光秀 */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWelLightSwt, SWC_IPC_NULL);

            }
        }
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P03)
        /* 迎宾灯光秀：接近灯光秀 */
        if(1 == Object->VehicleConfig[VCONFIG_KIND_CLOSE_TO_LIGHTING_FUNCTION])
        {
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ApprLightSwt, SWC_IPC_NULL);

        }
        #endif
    }
    else
    {
        SWC_IPC_PRINT_ERROR("Vehicle control can signal wake up phase 2 read vehicle config faild!");
    }

	SWC_IPC_PRINT_INFO("Vehicle control can signal wake up phase 2 work start!");
}

/**********************************************************************************************************
*Function   : IPC_IgnOnCanSignalOutput                                                                    *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-01                                                                                  *
**********************************************************************************************************/
static void IPC_IgnOnCanSignalOutput(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[1];
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;

	(void)Object;

	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();

    (void)SWC_IPC_PRINT_DEBUG("%s", __FUNCTION__);
	if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
	{
		/* 智能启停 */
		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_D01) ||\
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
			(defined SWC_IPC_PROJECT_TYPE_D03)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_SMART_START_STOP_SWITCH_MEMORY_SETTING])
		{
			/*0x1:On*/
			Data[0] = 1;
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SSSSet_HUT, Data);
		}
		else if (2 == Object->VehicleConfig[VCONFIG_KIND_SMART_START_STOP_SWITCH_MEMORY_SETTING])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SSSSet_HUT, SWC_IPC_NULL);
		}
		else
		{

		}
		#endif

		/* 疲劳驾驶 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03) || \
			(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_P02)
	    if (1 == Object->VehicleConfig[VCONFIG_KIND_DROWSINESS_WARNING_SYSTEM])
		{
	        IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDrowsnsDetnSet, SWC_IPC_NULL);
		}
		#endif

		/* 驾驶模式记忆 */
		if ((0 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
		||  (1 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
		|| ((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
		&&  (1 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
		{
			/* ESP主控的驾驶模式 有驾驶模式记忆开关 */
			if (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_SIGNAL_SELECT])
			{
				/* HUT驾驶模式软开关(中控屏) */
				if (1 == Object->VehicleConfig[VCONFIG_KIND_MEMORY_OF_DRIVING_MODE])
				{
					#ifdef SWC_IPC_PROJECT_TYPE_B02
					{
						IPC_API_GetTxCanSignal(SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
						if (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_2])
						{
							/* ZG220 - B02 驾驶模式18 */
							/* 标准、运动、经济、雪地、智能全地形 */
							if ((0x0 == Data[0])  /* 0x0:Standard/Normal */
							 || (0x1 == Data[0])  /* 0x1:Snow */
							 || (0x3 == Data[0])  /* 0x3:Economic */
							 || (0x4 == Data[0])  /* 0x4:Sport */
							 || (0x9 == Data[0])) /* 智能全地形 */
							{
								if (1 == Object->AppNvm.DriveModeStorageSwitch)
								{
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, SWC_IPC_NULL);
								}
								else
								{
									Data[0] = 0; /*0x0:Standard/Normal*/
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
								}
							}
							else
							{
								Data[0] = 0; /*0x0:Standard/Normal*/
								IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
							}
						}
						else if (6 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_3])
						{
							/* 驾驶模式36 ZQ336 */
							/* 驾驶模式36：标准、运动、经济、雪地、狂暴模式、智能全地形 */
							if ((0x0 == Data[0])  /* 0x0:标准 */
							 || (0x1 == Data[0])  /* 0x1:雪地 */
							 || (0x3 == Data[0])  /* 0x3:经济 */
							 || (0x4 == Data[0])  /* 0x4:运动 */
							 || (0x6 == Data[0])  /* 0x6:狂暴模式 */
							 || (0x9 == Data[0])) /* 智能全地形 */
							{
								if (1 == Object->AppNvm.DriveModeStorageSwitch)
								{
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, SWC_IPC_NULL);
								}
								else
								{
									Data[0] = 0; /*0x0:Standard/Normal*/
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
								}
							}
							else
							{
								Data[0] = 0; /*0x0:Standard/Normal*/
								IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
							}
						}
						else if (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_3])
						{
							/* 驾驶模式33 ZQ325 */
							/* 驾驶模式33：标准、运动、经济、雪地、沙地、越野、狂暴模式、智能全地形 */
							if ((0x0 == Data[0])  /* 0x0:标准 */
							 || (0x1 == Data[0])  /* 0x1:雪地 */
							 || (0x3 == Data[0])  /* 0x3:经济 */
							 || (0x4 == Data[0])  /* 0x4:运动 */
							 || (0x6 == Data[0])  /* 0x6:狂暴模式 */
							 || (0x9 == Data[0])  /* 智能全地形 */
							 || (0xD == Data[0])  /* 沙地 */
							 || (0x2 == Data[0])) /* 越野 */
							{
								if (1 == Object->AppNvm.DriveModeStorageSwitch)
								{
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, SWC_IPC_NULL);
								}
								else
								{
									Data[0] = 0; /*0x0:Standard/Normal*/
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
								}
							}
							else
							{
								Data[0] = 0; /*0x0:Standard/Normal*/
								IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
							}
						}
						else
						{
							/* No drive mode config. */
						}
					}
					#elif defined SWC_IPC_PROJECT_TYPE_B03
					{
						IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
						if (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_OPTIONAL])
						{
							/*ZA520 - B03*/
							/* 驾驶模式2：标准、经济、运动、雪地 */
							if ((0x0 == Data[0])  /*0x0:Standard/Normal*/
							|| (0x1 == Data[0])  /*0x1:Snow*/
							|| (0x3 == Data[0])  /*0x3:Economic*/
							|| (0x4 == Data[0])) /*0x4:Sport*/
							{
								if (1 == Object->AppNvm.DriveModeStorageSwitch)
								{
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, SWC_IPC_NULL);
								}
								else
								{
									Data[0] = 0; /*0x0:Standard/Normal*/
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
								}
							}
							else
							{
								Data[0] = 0; /*0x0:Standard/Normal*/
								IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
							}
						}
						else if (9 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_3])
						{
							/* 驾驶模式39 ZQ339 */
							/* 驾驶模式39：标准、运动、经济、雪地、赛道模式 */
							if ((0x0 == Data[0])  /*0x0:Standard/Normal*/
							|| (0x1 == Data[0])  /*0x1:Snow*/
							|| (0x3 == Data[0])  /*0x3:Economic*/
							|| (0x4 == Data[0])  /*0x4:Sport*/
							|| (0xE == Data[0]))  /*0xE:赛道模式*/
							{
								if (1 == Object->AppNvm.DriveModeStorageSwitch)
								{
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, SWC_IPC_NULL);
								}
								else
								{
									Data[0] = 0; /*0x0:Standard/Normal*/
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
								}
							}
							else
							{
								Data[0] = 0; /*0x0:Standard/Normal*/
								IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
							}
						}
						else if (7 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_3])
						{
							/* 驾驶模式37 ZQ337 */
							/* 驾驶模式37：标准、运动、经济、雪地、沙地、越野、赛道模式 */
							if ((0x0 == Data[0])  /*0x0:Standard/Normal*/
							|| (0x1 == Data[0])  /*0x1:Snow*/
							|| (0x3 == Data[0])  /*0x3:Economic*/
							|| (0x4 == Data[0])  /*0x4:Sport*/
							|| (0xE == Data[0])  /*0xE:赛道模式*/
							|| (0xD == Data[0])  /* 沙地 */
							|| (0x2 == Data[0])) /* 越野 */
							{
								if (1 == Object->AppNvm.DriveModeStorageSwitch)
								{
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, SWC_IPC_NULL);
								}
								else
								{
									Data[0] = 0; /*0x0:Standard/Normal*/
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
								}
							}
							else
							{
								Data[0] = 0; /*0x0:Standard/Normal*/
								IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
							}
						}
						else
						{
							/* No drive mode config. */
						}
					}
					#elif (defined SWC_IPC_PROJECT_TYPE_A07)
					{
						IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
						if (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_OPTIONAL])
						{
							/*ZA520 - B03*/
							/* 驾驶模式2：标准、经济、运动、雪地 */
							if ((0x0 == Data[0])  /*0x0:Standard/Normal*/
							|| (0x1 == Data[0])  /*0x1:Snow*/
							|| (0x3 == Data[0])  /*0x3:Economic*/
							|| (0x4 == Data[0])) /*0x4:Sport*/
							{
								if (1 == Object->AppNvm.DriveModeStorageSwitch)
								{
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, SWC_IPC_NULL);
								}
								else
								{
									Data[0] = 0; /*0x0:Standard/Normal*/
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
								}
							}
							else
							{
								Data[0] = 0; /*0x0:Standard/Normal*/
								IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
							}
						}
						else
						{
							/* No drive mode config. */
						}
					}
					#endif
				}
				else
				{
					#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)
					Data[0] = 0; /*0x0:Standard/Normal*/
					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
					#endif
				}
			}
		}
		else if (((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
		       && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
		      || ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
		       && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
		{
			/* HCU主控的驾驶模式(无驾驶模式记忆开关) 仅B02支持该模式 */
			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03)// || (defined SWC_IPC_PROJECT_TYPE_A07)
			{
				if (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_SIGNAL_SELECT])
				{
					/* HUT驾驶模式软开关(中控屏) */
					if (0 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_2])
					{
						/*No drive mode config.*/
						Data[0] = 0; /*0x0:Auto/Normal*/
						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_DrvModReq, Data);
					}
					else
					{
						Data[0] = 0; /*0x0:Auto/Normal*/
						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_DrvModReq, Data);
					}
				}
			}
			#endif
		}
		else
		{

		}

		/* 主驾驶座椅按摩设置 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
		{
			Data[0] = 0; /*0x0:Off*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgLvlSet, Data);
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		/* 后背门感应开启 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)\
    		|| (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if (3 == Object->VehicleConfig[VCONFIG_KIND_RR_DOOR_OPENING])/*3:感应式电动后背门*/
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HFASwtSts, SWC_IPC_NULL);
		}
		#endif

		/* 灯光控制 : 照我回家延时时间设置*/
		if (1 == Object->VehicleConfig[VCONFIG_KIND_HEAD_LAMP_AUTO_OFF])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FolwMeHomeDlyTimSet, SWC_IPC_NULL);
		}

		/* 灯光控制 : 运动模式灯光设置 */
		// #if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_A07)
		//  || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_D03)
		#if 0
		if (1 == Object->VehicleConfig[VCONFIG_KIND_SPORTS_MODE_LIGHTING_PROMPT_S_REPEATER])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SportModLightSet, SWC_IPC_NULL);
		}
		#endif

		/* 侧后辅助系统 : 并线辅助 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
		 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_LANE_CHANGE_ASSIST])
		  && (0 != Object->VehicleConfig[VCONFIG_KIND_REGIONAL]))  /* 国外 */
		{
            Data[0] = 1; /*0x1:On*/
		    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCASwtReq, Data);
		}
		#endif

		/* 车道辅助 : 紧急车道保持 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if (((4 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (5 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (8 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (9 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (11 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (13 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA]))
		 && (0 != Object->VehicleConfig[VCONFIG_KIND_REGIONAL]))  /* 国外 */
		{
            Data[0] = 1; /*0x1:On*/
		    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ELKSwtReq, Data);
		}
		#endif

		/* 交通标志信息 : 交通标志识别 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
		 || (2 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
		 || (4 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING]))
		 && (0 != Object->VehicleConfig[VCONFIG_KIND_REGIONAL])) /* 国外 */
		{
            Data[0] = 1; /*0x1:On*/
		    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSRSwtReq, Data);
        }
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)// || (defined SWC_IPC_PROJECT_TYPE_P02)
		/* 后雾灯：后雾灯开关信号 */
		if((1 == Object->VehicleConfig[VCONFIG_KIND_VIRTUAL_SW_FOR_REAR_FOG_LAMP]) && (1 == VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE))
		{
			Data[0] = 0;  /*0x0:OFF*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearFogLmpSwtSts_HUT, Data);
		}
		#endif

		/* Parking lights */
		#if (defined SWC_IPC_PROJECT_TYPE_P02) //|| (defined SWC_IPC_PROJECT_TYPE_D01)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_PARKING_LAMP])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ParkLmpSet, SWC_IPC_NULL);
		}
		#endif

		/* 360环视 : 环视退出车速值设置 */
		if ((0 != Object->VehicleConfig[VCONFIG_KIND_OMNIVIEW_SYSTEM]) || (0 != Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PASExitSpdSwt, SWC_IPC_NULL);
		}

		/* D档低速开启360环视 */
		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_OMNIVIEW_AUTO_TURN_ON_AT_LOW_SPEED])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AVMAutoSet, SWC_IPC_NULL);
		}
		#endif

		/* 外后视镜自动折叠 */
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
	     || (2 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
	     || (3 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
	     || (4 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearviewFoldModSet, SWC_IPC_NULL);
		}

		/* ESP */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_ESP_SWITCH_TYPE])
		{
			Data[0] = 0;/*0x0:Not Pressed*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_ESPFuncOffSwtSts, Data);
		}
		#endif

		/* 外后视镜倒车模式 KAG*/
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]) || (5 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_OrvmPosnEnaSts, SWC_IPC_NULL);
		}
		/* Save 模式下充电阈值设置(ForPHEV) DAA CBA */
		/* DAA:VCONFIG_KIND_FUEL */
		/* CBA:VCONFIG_KIND_ELECTROMOTOR_POSITION */
		#if 0
		// #if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) //#ifdef SWC_IPC_PROJECT_TYPE_P03
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
		 && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattSOCLimSaveMod, SWC_IPC_NULL);
		}
		#endif

		/* 能量回收等级设置 */
		/* HAJ:VCONFIG_KIND_BRAKING_ENERGY_RECOVERY */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P03)\
         || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) \
         || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P05)// || (defined SWC_IPC_PROJECT_TYPE_A07)
		if (((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
	       && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
		  || ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
		   && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
		{
			Data[0] = Object->AppNvm.HUT_EgyRecvrySet;  /* Get memory value */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, Data);
		}
		#endif

		/* 氛围灯 */
		/* SAQ60:轮廓；SAQ70:面发光；SAQ80:面发光； */
		/* ZK100：无音乐律动；ZK110：ALCM/CEM解析音乐律动；ZK120：主机解析 */
		/* ZK200：无分区联动（智能联动）；ZK210：有分区联动（智能联动）； */
		/* ZQ600：无氛围灯分区开关；ZQ610：有氛围灯分区开关 */
		/* 氛围灯及背景光(SAQ):VCONFIG_KIND_MOOD_LAMP */
		/* 多色律动氛围灯音频解析方式(ZK1):VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP */
		/* 氛围灯分区功能(ZK2):VCONFIG_KIND_MOOD_LAMP_PARTITION */
		/* 氛围灯分区点亮开关控制(ZQ6):VCONFIG_KIND_AMBIENT_LIGHT_CONTROL */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_A07)
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP])))
		{
			/* 氛围灯总开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMMasterSwt, SWC_IPC_NULL);
			/* 氛围灯亮度 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMLightLvlSet, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02)  || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03)//|| (defined SWC_IPC_PROJECT_TYPE_A07)
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP])))
		{
			 //D系列 信号缺失
			/* 轮廓氛围灯颜色选择 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet, SWC_IPC_NULL);
			/* 轮廓氛围灯多色彩静态 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt, SWC_IPC_NULL);
			/* 轮廓氛围灯多色彩动态 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) \
			// || (defined SWC_IPC_PROJECT_TYPE_A07 )
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP])))
		{
			/* 轮廓氛围灯呼吸灯 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01)
		if(((6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP])))
		{
			/* 面发光氛围灯流水灯设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMFloSwt, SWC_IPC_NULL);
			/* 面发光氛围灯颜色选择 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet_OLE, SWC_IPC_NULL);
			/* 面发光氛围灯多色彩静态模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt_OLE, SWC_IPC_NULL);
			/* 面发光氛围灯多色彩动态模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet_OLE, SWC_IPC_NULL);
			/* 面发光氛围灯呼吸灯设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt_OLE, SWC_IPC_NULL);
			/* 面发光氛围灯流水灯设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr1, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr2, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr3, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr4, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr5, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr6, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr7, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr8, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr9, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr10, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr11, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr12, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr13, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr14, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr15, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr16, SWC_IPC_NULL);
		}
		#endif
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03)
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP]) || (1 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP])))
		{
			/* 轮廓氛围灯音乐律动 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMRhmSwt, SWC_IPC_NULL);
		}
		#endif
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)
		if(((6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP]) || (1 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP])))
		{
			/* 面发光氛围灯音乐随动 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMRhmSwt_OLE, SWC_IPC_NULL);
		}
		#endif
		#if (defined SWC_IPC_PROJECT_TYPE_P05)|| (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
		 && (1 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP_PARTITION]))
		{
			/* 氛围灯联动:联动开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMPartitionSwt, SWC_IPC_NULL);
		}
		#endif

		/* 解闭锁提示 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_BLOCKING_PROMPT_TYPE])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockPromptFunSet, SWC_IPC_NULL);
		}
		#endif

		/* 蓝牙泊车 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 || (5 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 || (6 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 || (7 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
		{
			/* 蓝牙泊入自动闭锁 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPAEntryLockSet, SWC_IPC_NULL);
			/* 蓝牙泊出自动解锁 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPALvngUnlockSet, SWC_IPC_NULL);
		}
		#endif

		/* 解锁模式 */
		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_DOOR_UNLOCK_MODE])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DoorUnlockModSet, SWC_IPC_NULL);
		}
		#endif

		/* 电动侧踏 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if (6 == Object->VehicleConfig[VCONFIG_KIND_SIDE_STEP])
		{
			/* 电动侧踏开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ElecSideSteppingSysSet, SWC_IPC_NULL);
			/* 特殊模式开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AllTerrainDislSet, SWC_IPC_NULL);
			/* 车顶模式开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofModSet, SWC_IPC_NULL);
		}
		#endif

		/* 洗车拖车模式激活 CBA */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03)\
		// || (defined SWC_IPC_PROJECT_TYPE_A07)
		if (((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
	       && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
		  || ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
		   && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
		{
			Data[0] = 0;  /* 0x0:CarWashModeOFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_CarWashMode_Req, Data);
		}
		#endif

		/* 驾驶模式开关记忆：硬开关 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03)\
		 || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)|| (defined SWC_IPC_PROJECT_TYPE_P02)\
		 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D01)|| (defined SWC_IPC_PROJECT_TYPE_B02)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_MEMORY_OF_DRIVING_MODE])
		 && (1 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_SIGNAL_SELECT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvgModeMemReq, SWC_IPC_NULL);
		}
		#endif

		/* 副驾驶座椅按摩设置 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
		{
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgLvlSet, Data);
			/* 按摩模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		/* 主动进入解锁 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryUnlockSet, SWC_IPC_NULL);
		}
		#endif

		/* 主动离开闭锁 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if ((2 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryLockSet, SWC_IPC_NULL);
		}
		#endif

		/* 侧后辅助系统 :       开门预警 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_DR_OPEN_WARNING])
		{
            if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
            {
                /* 国内 */
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DOWSwtReq, SWC_IPC_NULL);
            }
            else
            {
                /* 国外 */
				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DOWSwtReq, SWC_IPC_NULL);
				#endif
            }
		}

		/* 侧后辅助系统 :       后碰撞预警 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_REAR_COLLISION_WARNING])
		{
            if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
            {
                /* 国内 */
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCWSwtReq, SWC_IPC_NULL);
            }
            else
            {
                /* 国外 */
				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCWSwtReq, SWC_IPC_NULL);
				#endif
            }
		}

		/* 侧后辅助系统 : 倒车侧向警告 */
		if ((2 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA])
		 || (4 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA]))
		{
			if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
			{
				/* 国内 */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTASwtReq, SWC_IPC_NULL);
			}
			else
			{
				/* 国外 */
				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTASwtReq, SWC_IPC_NULL);
				#endif
			}
		}

		/* 侧后辅助系统 : 倒车侧向制动 */
		if (4 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA])
	 	{
            if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
            {
                /* 国内 */
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTABrkSwtReq, SWC_IPC_NULL);
            }
            else
            {
                /* 国外 */
				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTABrkSwtReq, SWC_IPC_NULL);
				#endif
            }
	 	}

		/* 越野模式：专家模式 */
		/* 项目代码 AAA(VCONFIG_KIND_PROJECT_CODE) */
		/* 变速器 EAA(VCONFIG_KIND_TRANSMISSION) */
		/* 减震器 GAD(VCONFIG_KIND_DAMPER) */
		#if (defined SWC_IPC_PROJECT_TYPE_P05)
		if (0x45u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
		{
			/* 自定义界面 */
			/* Data[0] = 0; 0x0:Not active */
			/* IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data); */
			/* 四驱模式 */
			Data[0] = 0;/* 0x0:2H */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, SWC_IPC_NULL);
			/* 驱动模式 */
			Data[0] = 0;/* 0x0: 舒适 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, SWC_IPC_NULL);
			Data[0] = 0;/* 0x0: 舒适 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, SWC_IPC_NULL);
			/* 转向模式 */
			if (0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, SWC_IPC_NULL);
			}
			/* ESC设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, SWC_IPC_NULL);
		}
		#elif (defined SWC_IPC_PROJECT_TYPE_P03)
		if ((0x47u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]) || (0x48u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]) \
		||  (0x49u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]))
		{
			/* 自定义界面 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, SWC_IPC_NULL);
			/* 四驱模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, SWC_IPC_NULL);
			/* 驱动模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, SWC_IPC_NULL);
			/* 转向模式 */
			if (0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, SWC_IPC_NULL);
			}
			/* ESC设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, SWC_IPC_NULL);

			/* 越野模式：专家模式-悬架设置 */
			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
				((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
			{
				Data[0] = 1;/* 0x1: Comfort */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
			}
		}
		#elif (defined SWC_IPC_PROJECT_TYPE_P02)
		if (0x34u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
		{
			/* 自定义界面 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, SWC_IPC_NULL);
			/* 四驱模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, SWC_IPC_NULL);
			/* 驱动模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, SWC_IPC_NULL);
			/* 转向模式 */
			if (0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, SWC_IPC_NULL);
			}
			/* ESC设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, SWC_IPC_NULL);

			/* 越野模式：专家模式-悬架设置 */
			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
				((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
			{
				Data[0] = 1;/* 0x1: Comfort */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
			}
		}
		#elif (defined SWC_IPC_PROJECT_TYPE_D01)
		if (0x37u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
		{
			/* 自定义界面 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, SWC_IPC_NULL);
			/* 四驱模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, SWC_IPC_NULL);
			/* 驱动模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, SWC_IPC_NULL);
			/* 转向模式 */
			if (0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, SWC_IPC_NULL);
			}
			/* ESC设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, SWC_IPC_NULL);

			/* 越野模式：专家模式-悬架设置 */
			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
				((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
			{
				Data[0] = 1;/* 0x1: Comfort */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
			}
		}
		#elif (defined SWC_IPC_PROJECT_TYPE_D02)
		if (0x5Cu == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
		{
			/* 自定义界面 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, SWC_IPC_NULL);
			/* 四驱模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, SWC_IPC_NULL);
			/* 驱动模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, SWC_IPC_NULL);
			/* 转向模式 */
			if (0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, SWC_IPC_NULL);
			}
			/* ESC设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, SWC_IPC_NULL);

			/* 越野模式：专家模式-悬架设置 */
			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
				((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
			{
				Data[0] = 1;/* 0x1: Comfort */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
			}
		}
		#elif (defined SWC_IPC_PROJECT_TYPE_D03)
		if (0x5Eu == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
		{
			/* 自定义界面 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, SWC_IPC_NULL);
			/* 四驱模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, SWC_IPC_NULL);
			/* 驱动模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, SWC_IPC_NULL);
			/* 转向模式 */
			if (0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, SWC_IPC_NULL);
			}
			/* ESC设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, SWC_IPC_NULL);

			/* 越野模式：专家模式-悬架设置 */
			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
				((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
			{
				Data[0] = 1;/* 0x1: Comfort */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
			}
		}
		#endif

		/* 货箱照明设置(皮卡) */
		#if defined SWC_IPC_PROJECT_TYPE_P05
		if (1 == Object->VehicleConfig[VCONFIG_KIND_DECK_LAMP])
		{
			/* 货厢灯自动开启功能 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FreightLmpAutoSet, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07) // || (defined SWC_IPC_PROJECT_TYPE_P02)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_HEADLAMP_VIRTUAL_SW])
		{
			/* 大灯切换：位置灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PosnLmpSwtSts_HUT, SWC_IPC_NULL);
			/* 大灯切换：近光灯开关开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LowBeamSwtSts_HUT, SWC_IPC_NULL);
			/* 大灯切换：自动大灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoLmpSwtSts_HUT, SWC_IPC_NULL);
		}
		#endif

	    #ifdef SWC_IPC_PROJECT_TYPE_B02
	    if((1 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION]) || (2 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION]) || (3 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION]))
	    {
    	    /* 迎宾灯光秀：灯光秀总开关 */
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WelLightMainSwt, SWC_IPC_NULL);

            if(1 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION])
            {
                 /* 迎宾灯光秀：解锁灯光秀 */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_UnlockWelLightSwt, SWC_IPC_NULL);

            }
            else if(2 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION])
            {
                /* 迎宾灯光秀：闭锁灯光秀 */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWelLightSwt, SWC_IPC_NULL);

            }
            else
            {
                 /* 迎宾灯光秀：解锁灯光秀 */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_UnlockWelLightSwt, SWC_IPC_NULL);
                /* 迎宾灯光秀：闭锁灯光秀 */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWelLightSwt, SWC_IPC_NULL);

            }
        }
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P03)
        /* 迎宾灯光秀：接近灯光秀 */
        if(1 == Object->VehicleConfig[VCONFIG_KIND_CLOSE_TO_LIGHTING_FUNCTION])
        {
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ApprLightSwt, SWC_IPC_NULL);

        }
        #endif

		/* 交叉路口辅助 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_AEB_JUNCTION_ASSIST])
		{
			Data[0] = 1; /*0x1:On*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_JASwtReq, Data);
		}

		/* 行人安全辅助系统 */
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		 || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
		{
			Data[0] = 1; /*0x1:On*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_PedSwtReq, Data);

			/* 紧急转向辅助 */
			if (1 == Object->VehicleConfig[VCONFIG_KIND_EMERGENCY__STEERING_SUPPORT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_PedSwtReq, SWC_IPC_NULL);
			}
		}

		/* 碰撞安全辅助系统制动 */
		if ((3 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		  || (4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		  || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
		{
			Data[0] = 1; /*0x1:On*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_VehSwtReq, Data);

			/* 紧急转向辅助 */
			if (1 == Object->VehicleConfig[VCONFIG_KIND_EMERGENCY__STEERING_SUPPORT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_VehSwtReq, SWC_IPC_NULL);
			}
		}

		/* 前横穿侧向警告 */
	  	#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
		(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
		(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK])
		 || (2 == Object->VehicleConfig[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCTASwtReq, SWC_IPC_NULL);
		}
		#endif

		/* 前横穿侧向制动 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
		(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
		(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (2 == Object->VehicleConfig[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCTABrkSwtReq, SWC_IPC_NULL);
		}
		#endif

		/* DST */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_DYNAMIC_STEERING_TORQUE])
		{
			Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DSTSwtReq, Data);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_A07) // (defined SWC_IPC_PROJECT_TYPE_B02)
		/* 按键虚拟开关：拨片换挡 */
		if(1 == Object->VehicleConfig[VCONFIG_KIND_VIRTUAL_SW_FOR_STRG_WHL_HANDLE_SHIFT])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_TGSSwtReq, SWC_IPC_NULL);
		}
		#endif

		/* 方向盘未回正提醒功能开关 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_WHEEL_BACK_REMINDER])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerCorrnReq, SWC_IPC_NULL);
		}
		#endif

		/* 前排座椅迎宾 PAA*/
		if ((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		|| (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna, SWC_IPC_NULL);
		}

		/* 座椅设置:后排座椅迎宾 */
		#ifdef SWC_IPC_PROJECT_TYPE_P05
		if(1 == Object->VehicleConfig[VCONFIG_KIND_2ND_ROW_SEAT_WELCOME_FUNCTION])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_SecRow, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if((1 == Object->VehicleConfig[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE])\
			&& ((6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
			&& (2 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP])\
			&& (1 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP_PARTITION])\
			&& (1 == Object->VehicleConfig[VCONFIG_KIND_AMBIENT_LIGHT_CONTROL]))
		{
			/* 分区开关:左侧仪表板氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LeftPanelALCMSwt, SWC_IPC_NULL);
			/* 分区开关：右侧仪表板氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RightPanelALCMSwt, SWC_IPC_NULL);
			/* 分区开关：主驾氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：副驾氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：左后门氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LRDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：右后门氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：脚窝氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FootALCMSwt, SWC_IPC_NULL);
			/* 分区开关：顶棚氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofALCMSwt, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
		/* 雨刮间歇档位 / 灵敏度调节 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_WIPER_INTERMITTENT_LEVEL_VIRTUAL_SW])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSSensitivityReq_HUT, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D02)
		/* 副驾座椅非个性化记忆 副驾座椅迎宾 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_SEAT_WELCOME_FUNCTION])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_Pass, SWC_IPC_NULL);
		}
		#endif

		/* 后排左侧座椅按摩设置 ZV2+ZS9 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
		{
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgLvlSet, Data);
			/* 按摩模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		/* 后排右侧座椅按摩设置 ZV3+ZS9 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
		{
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgLvlSet, Data);
			/* 按摩模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		/* 涉水模式 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03)\
			|| (defined SWC_IPC_PROJECT_TYPE_D01)|| (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if (((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
			&& (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
			|| ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
			&& (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
		{
			Data[0] = 0;  /* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_WadeModeSet, Data);
		}
		#endif

		/* 后排左右侧座椅 一键躺倒 */
		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if (((4 == Object->VehicleConfig[VCONFIG_KIND_SEAT_CONTROL_MODULE]) || (5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_CONTROL_MODULE]) ||\
		(6 == Object->VehicleConfig[VCONFIG_KIND_SEAT_CONTROL_MODULE])) && (1 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_SEAT_FAST_SET]))
		{
			Data[0] = 0;  /* 0x0:no action */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearSeatLieFlatOneBtn, Data);
		}
		#endif

		/* 车窗短升短降 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_WINDOW_SHORT_LIFT_DROP_FUNCTION])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WinShortUpShortDownSet, SWC_IPC_NULL);
		}
		#endif

		/* 空调自干燥 */
		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_A_C_SELF_DRYING])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoDryingSwt, SWC_IPC_NULL);
		}
		#endif

		/* 自然风 */
		#if (defined SWC_IPC_PROJECT_TYPE_D03)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_AC_NATURAL_WIND])
		{
			/* 自然风模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NaturalWindModReq, SWC_IPC_NULL);
			/* 自然风下限值 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NaturalWindUpLimit, SWC_IPC_NULL);
			/* 自然风上限值 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NaturalWindLowLimit, SWC_IPC_NULL);
			/* 风量变化间隔时间 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NaturalWindPeriod, SWC_IPC_NULL);
		}
		#endif

		/* 生命体征监测 */
		#if (defined SWC_IPC_PROJECT_TYPE_P02)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_CHILD_PRESENCE_DETECTION])
		{
			/* 临时关闭开关 */
			Data[0] = 0x1; /* 0x1:Disable */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_VMDRTmpMonFctnSet, Data);
			/* 延迟报警 */
			Data[0] = 0x1; /* 0x1:Disable */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_VMDRInitAlarmDlySet, Data);
		}
		#endif
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Vehicle control can signal ignition on phase read vehicle config faild!");
	}

	/* 门锁设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SpdAutoLockModSet, SWC_IPC_NULL);
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FlaoutUnlockSet, SWC_IPC_NULL);

	/* 前雨刮 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoWshWipSet, SWC_IPC_NULL);

	/* 灯光控制 : 节电延时时间设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BattSaveDelayTimeSet, SWC_IPC_NULL);

	/* 灯光控制 : 顶灯延时时间设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DomeLmpDlyTimSet, SWC_IPC_NULL);

	/* 灯光控制 : 寻车功能模式设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SeekVehSet, SWC_IPC_NULL);

	/* 灯光控制 : 主动迎宾设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ApproachLampSet, SWC_IPC_NULL);

    #if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)\
     || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
    /* 香氛种类选择: 香氛功能开关 */
    Data[0] = 0;  /* 0x0:No action */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACFGAEnaReq_TC, Data);
    /* 香氛种类选择: 香氛功能通道选择 */
    Data[0] = 0;  /* 0x0:No action */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACFGAChanTyp_TC, Data);
    /* 香氛浓度选择 */
    Data[0] = 0;  /* 0x0:No action */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACFGALvlReq_TC, Data);
    #endif

	/* 动力模式选择（PHEV） */
	#if (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
		(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P05)
	Data[0] = 0;  /* 0x0:No request */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_HybModReq, Data);
	#endif

	/* 空气悬架模式选择软开关 */
	/* 自动便捷进出模式 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoEasyAcsReq, SWC_IPC_NULL);
	#endif
	/* 举升模式 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_JackModeReq, SWC_IPC_NULL);
	#endif
	/* 拖车模式 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TrailerModeReq, SWC_IPC_NULL);
	#endif
	/* 脚踢开启后轴装载模式 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01)
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearLvlKickModReq, SWC_IPC_NULL);
	#endif

	/* 驾驶模式语音控制 */
	#if (defined SWC_IPC_PROJECT_TYPE_P03) //|| (defined SWC_IPC_PROJECT_TYPE_A07)
	Data[0] = 0xF;  /* 0xF: Invalid Value */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_VR, Data);
	#endif

	/* 洗车模式开关 */
	#if (defined SWC_IPC_PROJECT_TYPE_A07)
	Data[0] = 0;  // 0x0:OFF
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_CarWashModeReq, Data);
	#endif

	/* 智能温控 */
	#if (defined SWC_IPC_PROJECT_TYPE_A07)
	/* 温控区间设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_InCarTempMinSet, SWC_IPC_NULL);
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_InCarTempMaxSet, SWC_IPC_NULL);
	/* 智能空调 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SmtACSwt, SWC_IPC_NULL);
	/* 智能座椅通风加热 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SmtSeatSwt, SWC_IPC_NULL);
	/* 智能方向盘加热 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SmtCsaSwt, SWC_IPC_NULL);
	#endif

	/* 时钟背光设定值（中控补偿值） */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BriCmp, SWC_IPC_NULL);
	#endif


	/* 按键背光 */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BackgroundLightLvlSet, SWC_IPC_NULL);

	SWC_IPC_PRINT_INFO("Vehicle control can signal ignition on phase work start!");
}

/**********************************************************************************************************
*Function   : IPC_OS_IgnOnCanSignalOutput                                                                 *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : XU                                                                                          *
*                                                                                                         *
*Date       : 2022-02-15                                                                                  *
**********************************************************************************************************/
static void IPC_OS_IgnOnCanSignalOutput(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[1];
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;

	(void)Object;

	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();

    (void)SWC_IPC_PRINT_DEBUG("%s", __FUNCTION__);
	if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
	{
		/* 智能启停 */
		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_D01) ||\
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
			(defined SWC_IPC_PROJECT_TYPE_D03)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_SMART_START_STOP_SWITCH_MEMORY_SETTING])
		{
			/*0x1:On*/
			Data[0] = 1;
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SSSSet_HUT, Data);
		}
		else if (2 == Object->VehicleConfig[VCONFIG_KIND_SMART_START_STOP_SWITCH_MEMORY_SETTING])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SSSSet_HUT, SWC_IPC_NULL);
		}
		else
		{

		}
		#endif

		/* 疲劳驾驶 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || \
			(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
	    if (1 == Object->VehicleConfig[VCONFIG_KIND_DROWSINESS_WARNING_SYSTEM])
		{
	        IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDrowsnsDetnSet, SWC_IPC_NULL);
		}
		#endif

		/* 驾驶模式记忆 */
		if ((0 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
		||  (1 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
		|| ((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
		&&  (1 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
		{
			/* ESP主控的驾驶模式 有驾驶模式记忆开关 */
			if (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_SIGNAL_SELECT])
			{
				/* HUT驾驶模式软开关(中控屏) */
				if (1 == Object->VehicleConfig[VCONFIG_KIND_MEMORY_OF_DRIVING_MODE])
				{
					#ifdef SWC_IPC_PROJECT_TYPE_B02
					{
						IPC_API_GetTxCanSignal(SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
						if (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_2])
						{
							/* ZG220 - B02 驾驶模式18 */
							/* 标准、运动、经济、雪地、智能全地形 */
							if ((0x0 == Data[0])  /* 0x0:Standard/Normal */
							 || (0x1 == Data[0])  /* 0x1:Snow */
							 || (0x3 == Data[0])  /* 0x3:Economic */
							 || (0x4 == Data[0])  /* 0x4:Sport */
							 || (0x9 == Data[0])) /* 智能全地形 */
							{
								if (1 == Object->AppNvm.DriveModeStorageSwitch)
								{
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, SWC_IPC_NULL);
								}
								else
								{
									Data[0] = 0; /*0x0:Standard/Normal*/
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
								}
							}
							else
							{
								Data[0] = 0; /*0x0:Standard/Normal*/
								IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
							}
						}
						else if (6 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_3])
						{
							/* 驾驶模式36 ZQ336 */
							/* 驾驶模式36：标准、运动、经济、雪地、狂暴模式、智能全地形 */
							if ((0x0 == Data[0])  /* 0x0:标准 */
							 || (0x1 == Data[0])  /* 0x1:雪地 */
							 || (0x3 == Data[0])  /* 0x3:经济 */
							 || (0x4 == Data[0])  /* 0x4:运动 */
							 || (0x6 == Data[0])  /* 0x6:狂暴模式 */
							 || (0x9 == Data[0])) /* 智能全地形 */
							{
								if (1 == Object->AppNvm.DriveModeStorageSwitch)
								{
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, SWC_IPC_NULL);
								}
								else
								{
									Data[0] = 0; /*0x0:Standard/Normal*/
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
								}
							}
							else
							{
								Data[0] = 0; /*0x0:Standard/Normal*/
								IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
							}
						}
						else if (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_3])
						{
							/* 驾驶模式33 ZQ325 */
							/* 驾驶模式33：标准、运动、经济、雪地、沙地、越野、狂暴模式、智能全地形 */
							if ((0x0 == Data[0])  /* 0x0:标准 */
							 || (0x1 == Data[0])  /* 0x1:雪地 */
							 || (0x3 == Data[0])  /* 0x3:经济 */
							 || (0x4 == Data[0])  /* 0x4:运动 */
							 || (0x6 == Data[0])  /* 0x6:狂暴模式 */
							 || (0x9 == Data[0])  /* 智能全地形 */
							 || (0xD == Data[0])  /* 沙地 */
							 || (0x2 == Data[0])) /* 越野 */
							{
								if (1 == Object->AppNvm.DriveModeStorageSwitch)
								{
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, SWC_IPC_NULL);
								}
								else
								{
									Data[0] = 0; /*0x0:Standard/Normal*/
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
								}
							}
							else
							{
								Data[0] = 0; /*0x0:Standard/Normal*/
								IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
							}
						}
						else
						{
							/* No drive mode config. */
						}
					}
					#elif defined SWC_IPC_PROJECT_TYPE_B03
					{
						IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
						if (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_OPTIONAL])
						{
							/*ZA520 - B03*/
							/* 驾驶模式2：标准、经济、运动、雪地 */
							if ((0x0 == Data[0])  /*0x0:Standard/Normal*/
							|| (0x1 == Data[0])  /*0x1:Snow*/
							|| (0x3 == Data[0])  /*0x3:Economic*/
							|| (0x4 == Data[0])) /*0x4:Sport*/
							{
								if (1 == Object->AppNvm.DriveModeStorageSwitch)
								{
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, SWC_IPC_NULL);
								}
								else
								{
									Data[0] = 0; /*0x0:Standard/Normal*/
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
								}
							}
							else
							{
								Data[0] = 0; /*0x0:Standard/Normal*/
								IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
							}
						}
						else if (9 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_3])
						{
							/* 驾驶模式39 ZQ339 */
							/* 驾驶模式39：标准、运动、经济、雪地、赛道模式 */
							if ((0x0 == Data[0])  /*0x0:Standard/Normal*/
							|| (0x1 == Data[0])  /*0x1:Snow*/
							|| (0x3 == Data[0])  /*0x3:Economic*/
							|| (0x4 == Data[0])  /*0x4:Sport*/
							|| (0xE == Data[0]))  /*0xE:赛道模式*/
							{
								if (1 == Object->AppNvm.DriveModeStorageSwitch)
								{
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, SWC_IPC_NULL);
								}
								else
								{
									Data[0] = 0; /*0x0:Standard/Normal*/
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
								}
							}
							else
							{
								Data[0] = 0; /*0x0:Standard/Normal*/
								IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
							}
						}
						else if (7 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_3])
						{
							/* 驾驶模式37 ZQ337 */
							/* 驾驶模式37：标准、运动、经济、雪地、沙地、越野、赛道模式 */
							if ((0x0 == Data[0])  /*0x0:Standard/Normal*/
							|| (0x1 == Data[0])  /*0x1:Snow*/
							|| (0x3 == Data[0])  /*0x3:Economic*/
							|| (0x4 == Data[0])  /*0x4:Sport*/
							|| (0xE == Data[0])  /*0xE:赛道模式*/
							|| (0xD == Data[0])  /* 沙地 */
							|| (0x2 == Data[0])) /* 越野 */
							{
								if (1 == Object->AppNvm.DriveModeStorageSwitch)
								{
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, SWC_IPC_NULL);
								}
								else
								{
									Data[0] = 0; /*0x0:Standard/Normal*/
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
								}
							}
							else
							{
								Data[0] = 0; /*0x0:Standard/Normal*/
								IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
							}
						}
						else
						{
							/* No drive mode config. */
						}
					}
					#elif (defined SWC_IPC_PROJECT_TYPE_A07)
					{
						IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
						if (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_OPTIONAL])
						{
							/*ZA520 - B03*/
							/* 驾驶模式2：标准、经济、运动、雪地 */
							if ((0x0 == Data[0])  /*0x0:Standard/Normal*/
							|| (0x1 == Data[0])  /*0x1:Snow*/
							|| (0x3 == Data[0])  /*0x3:Economic*/
							|| (0x4 == Data[0])) /*0x4:Sport*/
							{
								if (1 == Object->AppNvm.DriveModeStorageSwitch)
								{
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, SWC_IPC_NULL);
								}
								else
								{
									Data[0] = 0; /*0x0:Standard/Normal*/
									IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
								}
							}
							else
							{
								Data[0] = 0; /*0x0:Standard/Normal*/
								IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
							}
						}
						else
						{
							/* No drive mode config. */
						}
					}
					#endif
				}
				else
				{
					#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)
					Data[0] = 0; /*0x0:Standard/Normal*/
					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_HUT, Data);
					#endif
				}
			}
		}
		else if (((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
		       && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
		      || ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
		       && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
		{
			/* HCU主控的驾驶模式(无驾驶模式记忆开关) 仅B02支持该模式 */
			#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03)// || (defined SWC_IPC_PROJECT_TYPE_A07)
			{
				if (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_SIGNAL_SELECT])
				{
					/* HUT驾驶模式软开关(中控屏) */
					if (0 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_2])
					{
						/*No drive mode config.*/
						Data[0] = 0; /*0x0:Auto/Normal*/
						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_DrvModReq, Data);
					}
					else
					{
						Data[0] = 0; /*0x0:Auto/Normal*/
						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_DrvModReq, Data);
					}
				}
			}
			#endif
		}
		else
		{

		}

		/* 主驾驶座椅按摩设置 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P01)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
		{
			Data[0] = 0; /*0x0:Off*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgLvlSet, Data);
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		/* 后背门感应开启 */
		#if (defined SWC_IPC_PROJECT_TYPE_A07)
		if (3 == Object->VehicleConfig[VCONFIG_KIND_RR_DOOR_OPENING])/*3:感应式电动后背门*/
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HFASwtSts, SWC_IPC_NULL);
		}
		#endif

		/* 灯光控制 : 照我回家延时时间设置*/
		if (1 == Object->VehicleConfig[VCONFIG_KIND_HEAD_LAMP_AUTO_OFF])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FolwMeHomeDlyTimSet, SWC_IPC_NULL);
		}

		/* 灯光控制 : 运动模式灯光设置 */
		// #if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_A07)
		//  || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_D03)
		#if 0
		if (1 == Object->VehicleConfig[VCONFIG_KIND_SPORTS_MODE_LIGHTING_PROMPT_S_REPEATER])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SportModLightSet, SWC_IPC_NULL);
		}
		#endif

		/* 侧后辅助系统 : 并线辅助 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
		 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_LANE_CHANGE_ASSIST])
		  && (0 != Object->VehicleConfig[VCONFIG_KIND_REGIONAL]))  /* 国外 */
		{
            Data[0] = 1; /*0x1:On*/
		    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCASwtReq, Data);
		}
		#endif

		/* 车道辅助 : 紧急车道保持 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if (((4 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (5 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (8 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (9 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (11 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA])
		 || (13 == Object->VehicleConfig[VCONFIG_KIND_LDW_LKA]))
		 && (0 != Object->VehicleConfig[VCONFIG_KIND_REGIONAL]))  /* 国外 */
		{
            Data[0] = 1; /*0x1:On*/
		    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ELKSwtReq, Data);
		}
		#endif

		/* 交通标志信息 : 交通标志识别 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
		 || (2 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING])
		 || (4 == Object->VehicleConfig[VCONFIG_KIND_TRAFFIC_SIGN_WARNING]))
		 && (0 != Object->VehicleConfig[VCONFIG_KIND_REGIONAL])) /* 国外 */
		{
            Data[0] = 1; /*0x1:On*/
		    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TSRSwtReq, Data);
        }
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)// || (defined SWC_IPC_PROJECT_TYPE_P02)
		/* 后雾灯：后雾灯开关信号 */
		if((1 == Object->VehicleConfig[VCONFIG_KIND_VIRTUAL_SW_FOR_REAR_FOG_LAMP]) && (1 == VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE))
		{
			Data[0] = 0;  /*0x0:OFF*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearFogLmpSwtSts_HUT, Data);
		}
		#endif

		/* Parking lights */
		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) ||\
			(defined SWC_IPC_PROJECT_TYPE_P05)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_PARKING_LAMP])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ParkLmpSet, SWC_IPC_NULL);
		}
		#endif

		/* 360环视 : 环视退出车速值设置 */
		if ((0 != Object->VehicleConfig[VCONFIG_KIND_OMNIVIEW_SYSTEM]) || (0 != Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PASExitSpdSwt, SWC_IPC_NULL);
		}

		/* D档低速开启360环视 */
		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_OMNIVIEW_AUTO_TURN_ON_AT_LOW_SPEED])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AVMAutoSet, SWC_IPC_NULL);
		}
		#endif

		/* 外后视镜自动折叠 */
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
	     || (2 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
	     || (3 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR])
	     || (4 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearviewFoldModSet, SWC_IPC_NULL);
		}

		/* ESP */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_ESP_SWITCH_TYPE])
		{
			Data[0] = 0;/*0x0:Not Pressed*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_ESPFuncOffSwtSts, Data);
		}
		#endif

		/* 外后视镜倒车模式 KAG*/
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]) || (5 == Object->VehicleConfig[VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_OrvmPosnEnaSts, SWC_IPC_NULL);
		}
		/* Save 模式下充电阈值设置(ForPHEV) DAA CBA */
		/* DAA:VCONFIG_KIND_FUEL */
		/* CBA:VCONFIG_KIND_ELECTROMOTOR_POSITION */
		#if 0
		// #if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) //#ifdef SWC_IPC_PROJECT_TYPE_P03
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
		 && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BattSOCLimSaveMod, SWC_IPC_NULL);
		}
		#endif

		/* 能量回收等级设置 */
		/* HAJ:VCONFIG_KIND_BRAKING_ENERGY_RECOVERY */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P03)\
         || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)// || (defined SWC_IPC_PROJECT_TYPE_A07)
		if (((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
	       && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
		  || ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
		   && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
		{
			Data[0] = Object->AppNvm.HUT_EgyRecvrySet;  /* Get memory value */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_EgyRecvrySet, Data);
		}
		#endif

		/* 氛围灯 */
		/* SAQ60:轮廓；SAQ70:面发光；SAQ80:面发光； */
		/* ZK100：无音乐律动；ZK110：ALCM/CEM解析音乐律动；ZK120：主机解析 */
		/* ZK200：无分区联动（智能联动）；ZK210：有分区联动（智能联动）； */
		/* ZQ600：无氛围灯分区开关；ZQ610：有氛围灯分区开关 */
		/* 氛围灯及背景光(SAQ):VCONFIG_KIND_MOOD_LAMP */
		/* 多色律动氛围灯音频解析方式(ZK1):VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP */
		/* 氛围灯分区功能(ZK2):VCONFIG_KIND_MOOD_LAMP_PARTITION */
		/* 氛围灯分区点亮开关控制(ZQ6):VCONFIG_KIND_AMBIENT_LIGHT_CONTROL */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P01)
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP])))
		{
			/* 氛围灯总开关 */
			#if(!defined SWC_IPC_PROJECT_TYPE_P01)
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMMasterSwt, SWC_IPC_NULL);
			#endif
			/* 氛围灯亮度 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMLightLvlSet, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)//|| (defined SWC_IPC_PROJECT_TYPE_A07)
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP])))
		{
			 //D系列 信号缺失
			/* 轮廓氛围灯颜色选择 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet, SWC_IPC_NULL);
			/* 轮廓氛围灯多色彩静态 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt, SWC_IPC_NULL);
			/* 轮廓氛围灯多色彩动态 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) \
			// || (defined SWC_IPC_PROJECT_TYPE_A07 )
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP])))
		{
			/* 轮廓氛围灯呼吸灯 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01)
		if(((6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP])))
		{
			/* 面发光氛围灯流水灯设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMFloSwt, SWC_IPC_NULL);
			/* 面发光氛围灯颜色选择 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMClrSet_OLE, SWC_IPC_NULL);
			/* 面发光氛围灯多色彩静态模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMStatSwt_OLE, SWC_IPC_NULL);
			/* 面发光氛围灯多色彩动态模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMDynModSet_OLE, SWC_IPC_NULL);
			/* 面发光氛围灯呼吸灯设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMBreSwt_OLE, SWC_IPC_NULL);
			/* 面发光氛围灯流水灯设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr1, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr2, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr3, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr4, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr5, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr6, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr7, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr8, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr9, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr10, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr11, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr12, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr13, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr14, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr15, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_MultiColorNr16, SWC_IPC_NULL);
		}
		#endif
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP]) || (1 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP])))
		{
			/* 轮廓氛围灯音乐律动 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMRhmSwt, SWC_IPC_NULL);
		}
		#endif
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)
		if(((6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP]) || (1 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP])))
		{
			/* 面发光氛围灯音乐随动 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMRhmSwt_OLE, SWC_IPC_NULL);
		}
		#endif
		#if (defined SWC_IPC_PROJECT_TYPE_P05)|| (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
		 && (1 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP_PARTITION]))
		{
			/* 氛围灯联动:联动开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMPartitionSwt, SWC_IPC_NULL);
		}
		#endif

		/* 解闭锁提示 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_BLOCKING_PROMPT_TYPE])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockPromptFunSet, SWC_IPC_NULL);
		}
		#endif

		/* 蓝牙泊车 */
		#if (defined SWC_IPC_PROJECT_TYPE_P01)
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 || (5 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 || (6 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 || (7 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
		{
			/* 蓝牙泊入自动闭锁 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPAEntryLockSet, SWC_IPC_NULL);
			/* 蓝牙泊出自动解锁 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPALvngUnlockSet, SWC_IPC_NULL);
		}
		#endif

		/* 解锁模式 */
		#if (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_DOOR_UNLOCK_MODE])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DoorUnlockModSet, SWC_IPC_NULL);
		}
		#endif

		/* 电动侧踏 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_P01)
		if (6 == Object->VehicleConfig[VCONFIG_KIND_SIDE_STEP])
		{
			/* 电动侧踏开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ElecSideSteppingSysSet, SWC_IPC_NULL);
			/* 特殊模式开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AllTerrainDislSet, SWC_IPC_NULL);
			/* 车顶模式开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofModSet, SWC_IPC_NULL);
		}
		#endif

		/* 洗车拖车模式激活 CBA */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03)\
		// || (defined SWC_IPC_PROJECT_TYPE_A07)
		if (((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
	       && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
		  || ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
		   && (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
		{
			Data[0] = 0;  /* 0x0:CarWashModeOFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_CarWashMode_Req, Data);
		}
		#endif

		/* 驾驶模式开关记忆：硬开关 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P01) \
		 || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_A07)|| (defined SWC_IPC_PROJECT_TYPE_P02)\
		 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D01)|| (defined SWC_IPC_PROJECT_TYPE_B02)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_MEMORY_OF_DRIVING_MODE])
		 && (1 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_SIGNAL_SELECT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvgModeMemReq, SWC_IPC_NULL);
		}
		#endif

		/* 副驾驶座椅按摩设置 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
			(defined SWC_IPC_PROJECT_TYPE_P01)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
		{
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgLvlSet, Data);
			/* 按摩模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		/* 主动进入解锁 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryUnlockSet, SWC_IPC_NULL);
		}
		#endif

		/* 主动离开闭锁 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if ((2 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryLockSet, SWC_IPC_NULL);
		}
		#endif

		/* 侧后辅助系统 :       开门预警 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_DR_OPEN_WARNING])
		{
            if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
            {
                /* 国内 */
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DOWSwtReq, SWC_IPC_NULL);
            }
            else
            {
                /* 国外 */
				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DOWSwtReq, SWC_IPC_NULL);
				#endif
            }
		}

		/* 侧后辅助系统 :       后碰撞预警 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_REAR_COLLISION_WARNING])
		{
            if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
            {
                /* 国内 */
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCWSwtReq, SWC_IPC_NULL);
            }
            else
            {
                /* 国外 */
				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCWSwtReq, SWC_IPC_NULL);
				#endif
            }
		}

		/* 侧后辅助系统 : 倒车侧向警告 */
		if ((2 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA])
		 || (4 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA]))
		{
			if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
			{
				/* 国内 */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTASwtReq, SWC_IPC_NULL);
			}
			else
			{
				/* 国外 */
				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTASwtReq, SWC_IPC_NULL);
				#endif
			}
		}

		/* 侧后辅助系统 : 倒车侧向制动 */
		if (4 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA])
	 	{
            if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
            {
                /* 国内 */
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTABrkSwtReq, SWC_IPC_NULL);
            }
            else
            {
                /* 国外 */
				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTABrkSwtReq, SWC_IPC_NULL);
				#endif
            }
	 	}

		/* 越野模式：专家模式 */
		/* 项目代码 AAA(VCONFIG_KIND_PROJECT_CODE) */
		/* 变速器 EAA(VCONFIG_KIND_TRANSMISSION) */
		/* 减震器 GAD(VCONFIG_KIND_DAMPER) */
		#if (defined SWC_IPC_PROJECT_TYPE_P05)
		if (0x45u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
		{
			/* 自定义界面 */
			/* Data[0] = 0; 0x0:Not active */
			/* IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, Data); */
			/* 四驱模式 */
			Data[0] = 0;/* 0x0:2H */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, SWC_IPC_NULL);
			/* 驱动模式 */
			Data[0] = 0;/* 0x0: 舒适 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, SWC_IPC_NULL);
			Data[0] = 0;/* 0x0: 舒适 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, SWC_IPC_NULL);
			/* 转向模式 */
			if (0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, SWC_IPC_NULL);
			}
			/* ESC设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, SWC_IPC_NULL);
		}
		#elif (defined SWC_IPC_PROJECT_TYPE_P03)
		if ((0x47u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]) || (0x48u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]) \
		||  (0x49u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]))
		{
			/* 自定义界面 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, SWC_IPC_NULL);
			/* 四驱模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, SWC_IPC_NULL);
			/* 驱动模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, SWC_IPC_NULL);
			/* 转向模式 */
			if (0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, SWC_IPC_NULL);
			}
			/* ESC设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, SWC_IPC_NULL);

			/* 越野模式：专家模式-悬架设置 */
			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
				((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
			{
				Data[0] = 1;/* 0x1: Comfort */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
			}
		}
		#elif (defined SWC_IPC_PROJECT_TYPE_P02)
		if (0x34u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
		{
			/* 自定义界面 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, SWC_IPC_NULL);
			/* 四驱模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, SWC_IPC_NULL);
			/* 驱动模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, SWC_IPC_NULL);
			/* 转向模式 */
			if (0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, SWC_IPC_NULL);
			}
			/* ESC设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, SWC_IPC_NULL);

			/* 越野模式：专家模式-悬架设置 */
			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
				((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
			{
				Data[0] = 1;/* 0x1: Comfort */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
			}
		}
		#elif (defined SWC_IPC_PROJECT_TYPE_D01)
		if (0x37u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
		{
			/* 自定义界面 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, SWC_IPC_NULL);
			/* 四驱模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, SWC_IPC_NULL);
			/* 驱动模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, SWC_IPC_NULL);
			/* 转向模式 */
			if (0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, SWC_IPC_NULL);
			}
			/* ESC设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, SWC_IPC_NULL);

			/* 越野模式：专家模式-悬架设置 */
			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
				((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
			{
				Data[0] = 1;/* 0x1: Comfort */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
			}
		}
		#elif (defined SWC_IPC_PROJECT_TYPE_D02)
		if (0x5Cu == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
		{
			/* 自定义界面 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, SWC_IPC_NULL);
			/* 四驱模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, SWC_IPC_NULL);
			/* 驱动模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, SWC_IPC_NULL);
			/* 转向模式 */
			if (0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, SWC_IPC_NULL);
			}
			/* ESC设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, SWC_IPC_NULL);

			/* 越野模式：专家模式-悬架设置 */
			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
				((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
			{
				Data[0] = 1;/* 0x1: Comfort */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
			}
		}
		#elif (defined SWC_IPC_PROJECT_TYPE_D03)
		if (0x5Eu == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])
		{
			/* 自定义界面 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, SWC_IPC_NULL);
			/* 四驱模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, SWC_IPC_NULL);
			/* 驱动模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, SWC_IPC_NULL);
			/* 转向模式 */
			if (0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, SWC_IPC_NULL);
			}
			/* ESC设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, SWC_IPC_NULL);

			/* 越野模式：专家模式-悬架设置 */
			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
				((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
			{
				Data[0] = 1;/* 0x1: Comfort */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
			}
		}
		#elif (defined SWC_IPC_PROJECT_TYPE_P01)
		if ( (0x0u == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE])  || (0x4Eu == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]) ||\
			(0x2Bu == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]) || (0x2Cu == Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE]))
		{
			/* 自定义界面 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModSwtReq_HUT, SWC_IPC_NULL);
			/* 四驱模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TOD, SWC_IPC_NULL);
			/* 驱动模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ECM, SWC_IPC_NULL);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_TCU, SWC_IPC_NULL);
			/* 转向模式 */
			if (0x01u == Object->VehicleConfig[VCONFIG_KIND_SREERING_MODE_OF_EXPERT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_EPSSteerModSwtReq, SWC_IPC_NULL);
			}
			/* ESC设置 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExpertModReq_HUT_ESP, SWC_IPC_NULL);

			/* 越野模式：专家模式-悬架设置 */
			if ((2 == Object->VehicleConfig[VCONFIG_KIND_DAMPER]) && \
				((1 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(2 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION]) ||\
				(3 == Object->VehicleConfig[VCONFIG_KIND_SUSPENSION_MODE_CONFIGURATION_INFORMATION])))
			{
				Data[0] = 1;/* 0x1: Comfort */
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DampgDrvModeReq, Data);
			}
		}
		#endif

		/* 货箱照明设置(皮卡) */
		#if defined SWC_IPC_PROJECT_TYPE_P05
		if (1 == Object->VehicleConfig[VCONFIG_KIND_DECK_LAMP])
		{
			/* 货厢灯自动开启功能 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FreightLmpAutoSet, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07) // || (defined SWC_IPC_PROJECT_TYPE_P02)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_HEADLAMP_VIRTUAL_SW])
		{
			/* 大灯切换：位置灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PosnLmpSwtSts_HUT, SWC_IPC_NULL);
			/* 大灯切换：近光灯开关开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LowBeamSwtSts_HUT, SWC_IPC_NULL);
			/* 大灯切换：自动大灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoLmpSwtSts_HUT, SWC_IPC_NULL);
		}
		#endif

	    #ifdef SWC_IPC_PROJECT_TYPE_B02
	    if((1 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION]) || (2 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION]) || (3 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION]))
	    {
    	    /* 迎宾灯光秀：灯光秀总开关 */
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WelLightMainSwt, SWC_IPC_NULL);

            if(1 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION])
            {
                 /* 迎宾灯光秀：解锁灯光秀 */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_UnlockWelLightSwt, SWC_IPC_NULL);

            }
            else if(2 == Object->VehicleConfig[VCONFIG_KIND_LIGHTING_SHOW_FUNCTION])
            {
                /* 迎宾灯光秀：闭锁灯光秀 */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWelLightSwt, SWC_IPC_NULL);

            }
            else
            {
                 /* 迎宾灯光秀：解锁灯光秀 */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_UnlockWelLightSwt, SWC_IPC_NULL);
                /* 迎宾灯光秀：闭锁灯光秀 */
                IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWelLightSwt, SWC_IPC_NULL);

            }
        }
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P03)
        /* 迎宾灯光秀：接近灯光秀 */
        if(1 == Object->VehicleConfig[VCONFIG_KIND_CLOSE_TO_LIGHTING_FUNCTION])
        {
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ApprLightSwt, SWC_IPC_NULL);

        }
        #endif

		/* 交叉路口辅助 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_AEB_JUNCTION_ASSIST])
		{
			Data[0] = 1; /*0x1:On*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_JASwtReq, Data);
		}

		/* 行人安全辅助系统 */
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		 || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
		{
			Data[0] = 1; /*0x1:On*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_PedSwtReq, Data);

			/* 紧急转向辅助 */
			if (1 == Object->VehicleConfig[VCONFIG_KIND_EMERGENCY__STEERING_SUPPORT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_PedSwtReq, SWC_IPC_NULL);
			}
		}

		/* 碰撞安全辅助系统制动 */
		if ((3 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		  || (4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		  || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
		{
			Data[0] = 1; /*0x1:On*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_VehSwtReq, Data);

			/* 紧急转向辅助 */
			if (1 == Object->VehicleConfig[VCONFIG_KIND_EMERGENCY__STEERING_SUPPORT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_VehSwtReq, SWC_IPC_NULL);
			}
		}

		/* 前横穿侧向警告 */
	  	#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
		(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
		(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK])
		 || (2 == Object->VehicleConfig[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCTASwtReq, SWC_IPC_NULL);
		}
		#endif

		/* 前横穿侧向制动 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
		(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P02) ||  (defined SWC_IPC_PROJECT_TYPE_P01) ||\
		(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (2 == Object->VehicleConfig[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCTABrkSwtReq, SWC_IPC_NULL);
		}
		#endif

		/* DST */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_DYNAMIC_STEERING_TORQUE])
		{
			Data[0] = 0;/* 0x0:OFF */
    		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DSTSwtReq, Data);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_A07) // (defined SWC_IPC_PROJECT_TYPE_B02)
		/* 按键虚拟开关：拨片换挡 */
		if(1 == Object->VehicleConfig[VCONFIG_KIND_VIRTUAL_SW_FOR_STRG_WHL_HANDLE_SHIFT])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_TGSSwtReq, SWC_IPC_NULL);
		}
		#endif

		/* 方向盘未回正提醒功能开关 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P01)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_STEERING_WHEEL_BACK_REMINDER])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerCorrnReq, SWC_IPC_NULL);
		}
		#endif

		/* 前排座椅迎宾 PAA*/
		if ((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		|| (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna, SWC_IPC_NULL);
		}

		/* 座椅设置:后排座椅迎宾 */
		#ifdef SWC_IPC_PROJECT_TYPE_P05
		if(1 == Object->VehicleConfig[VCONFIG_KIND_2ND_ROW_SEAT_WELCOME_FUNCTION])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_SecRow, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if((1 == Object->VehicleConfig[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE])\
			&& ((6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
			&& (2 == Object->VehicleConfig[VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP])\
			&& (1 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP_PARTITION])\
			&& (1 == Object->VehicleConfig[VCONFIG_KIND_AMBIENT_LIGHT_CONTROL]))
		{
			/* 分区开关:左侧仪表板氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LeftPanelALCMSwt, SWC_IPC_NULL);
			/* 分区开关：右侧仪表板氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RightPanelALCMSwt, SWC_IPC_NULL);
			/* 分区开关：主驾氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：副驾氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：左后门氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LRDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：右后门氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：脚窝氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FootALCMSwt, SWC_IPC_NULL);
			/* 分区开关：顶棚氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofALCMSwt, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
		/* 雨刮间歇档位 / 灵敏度调节 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_WIPER_INTERMITTENT_LEVEL_VIRTUAL_SW])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSSensitivityReq_HUT, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D02)//|| (defined SWC_IPC_PROJECT_TYPE_P01)
		/* 副驾座椅非个性化记忆 副驾座椅迎宾 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_SEAT_WELCOME_FUNCTION])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnEna_Pass, SWC_IPC_NULL);
		}
		#endif

		/* 后排左侧座椅按摩设置 ZV2+ZS9 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
		{
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgLvlSet, Data);
			/* 按摩模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		/* 后排右侧座椅按摩设置 ZV3+ZS9 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_P01)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
		{
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgLvlSet, Data);
			/* 按摩模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		/* 涉水模式 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03)\
			|| (defined SWC_IPC_PROJECT_TYPE_D01)|| (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if (((3 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
			&& (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION]))
			|| ((4 == Object->VehicleConfig[VCONFIG_KIND_FUEL])
			&& (5 == Object->VehicleConfig[VCONFIG_KIND_ELECTROMOTOR_POSITION])))
		{
			Data[0] = 0;  /* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_WadeModeSet, Data);
		}
		#endif

		/* 后排左右侧座椅 一键躺倒 */
		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if (((4 == Object->VehicleConfig[VCONFIG_KIND_SEAT_CONTROL_MODULE]) || (5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_CONTROL_MODULE]) ||\
		(6 == Object->VehicleConfig[VCONFIG_KIND_SEAT_CONTROL_MODULE])) && (1 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_SEAT_FAST_SET]))
		{
			Data[0] = 0;  /* 0x0:no action */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearSeatLieFlatOneBtn, Data);
		}
		#endif

		/* 车窗短升短降 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_WINDOW_SHORT_LIFT_DROP_FUNCTION])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WinShortUpShortDownSet, SWC_IPC_NULL);
		}
		#endif

		/* 空调自干燥 */
		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_A_C_SELF_DRYING])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoDryingSwt, SWC_IPC_NULL);
		}
		#endif

		/* 自然风 */
		#if (defined SWC_IPC_PROJECT_TYPE_D03)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_AC_NATURAL_WIND])
		{
			/* 自然风模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NaturalWindModReq, SWC_IPC_NULL);
			/* 自然风下限值 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NaturalWindUpLimit, SWC_IPC_NULL);
			/* 自然风上限值 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NaturalWindLowLimit, SWC_IPC_NULL);
			/* 风量变化间隔时间 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NaturalWindPeriod, SWC_IPC_NULL);
		}
		#endif

		/* 生命体征监测 */
		#if (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_CHILD_PRESENCE_DETECTION])
		{
			/* 临时关闭开关 */
			Data[0] = 0x1; /* 0x1:Disable */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_VMDRTmpMonFctnSet, Data);
			/* 延迟报警 */
			Data[0] = 0x1; /* 0x1:Disable */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_VMDRInitAlarmDlySet, Data);
		}
		#endif
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Vehicle control can signal ignition on phase read vehicle config faild!");
	}

	/* 门锁设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SpdAutoLockModSet, SWC_IPC_NULL);
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FlaoutUnlockSet, SWC_IPC_NULL);

	/* 前雨刮 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoWshWipSet, SWC_IPC_NULL);

	/* 灯光控制 : 节电延时时间设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BattSaveDelayTimeSet, SWC_IPC_NULL);

	/* 灯光控制 : 顶灯延时时间设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DomeLmpDlyTimSet, SWC_IPC_NULL);

	/* 灯光控制 : 寻车功能模式设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SeekVehSet, SWC_IPC_NULL);

	/* 灯光控制 : 主动迎宾设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ApproachLampSet, SWC_IPC_NULL);

    #if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)\
     || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
    /* 香氛种类选择: 香氛功能开关 */
    Data[0] = 0;  /* 0x0:No action */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACFGAEnaReq_TC, Data);
    /* 香氛种类选择: 香氛功能通道选择 */
    Data[0] = 0;  /* 0x0:No action */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACFGAChanTyp_TC, Data);
    /* 香氛浓度选择 */
    Data[0] = 0;  /* 0x0:No action */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ACFGALvlReq_TC, Data);
    #endif

	/* 动力模式选择（PHEV） */
	#if (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
		(defined SWC_IPC_PROJECT_TYPE_D03)
	Data[0] = 0;  /* 0x0:No request */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_HybModReq, Data);
	#endif

	/* 空气悬架模式选择软开关 */
	/* 自动便捷进出模式 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoEasyAcsReq, SWC_IPC_NULL);
	#endif
	/* 举升模式 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_JackModeReq, SWC_IPC_NULL);
	#endif
	/* 拖车模式 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TrailerModeReq, SWC_IPC_NULL);
	#endif
	/* 脚踢开启后轴装载模式 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01)
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RearLvlKickModReq, SWC_IPC_NULL);
	#endif

	/* 驾驶模式语音控制 */
	#if (defined SWC_IPC_PROJECT_TYPE_P03) //|| (defined SWC_IPC_PROJECT_TYPE_A07)
	Data[0] = 0xF;  /* 0xF: Invalid Value */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrivingModReq_VR, Data);
	#endif

	/* 洗车模式开关 */
	#if (defined SWC_IPC_PROJECT_TYPE_A07)
	Data[0] = 0;  // 0x0:OFF
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_CarWashModeReq, Data);
	#endif

	/* 智能温控 */
	#if (defined SWC_IPC_PROJECT_TYPE_A07)
	/* 温控区间设置 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_InCarTempMinSet, SWC_IPC_NULL);
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_InCarTempMaxSet, SWC_IPC_NULL);
	/* 智能空调 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SmtACSwt, SWC_IPC_NULL);
	/* 智能座椅通风加热 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SmtSeatSwt, SWC_IPC_NULL);
	/* 智能方向盘加热 */
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SmtCsaSwt, SWC_IPC_NULL);
	#endif

	/* 时钟背光设定值（中控补偿值） */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
	IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BriCmp, SWC_IPC_NULL);
	#endif


	/* 按键背光 */
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BackgroundLightLvlSet, SWC_IPC_NULL);

	SWC_IPC_PRINT_INFO("Vehicle control can signal ignition on phase work start!");
}

/**********************************************************************************************************
*Function   : IPC_IgnOffCanSignalOutput                                                                   *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-01                                                                                  *
**********************************************************************************************************/
static void IPC_IgnOffCanSignalOutput(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[1];
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;
	(void)Object;

	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();

    (void)SWC_IPC_PRINT_DEBUG("%s", __FUNCTION__);
	if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
	{
		/* 行人安全辅助系统 */
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		 || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
		{
			Data[0] = 1; /*0x1:On*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_PedSwtReq, Data);

			/* 紧急转向辅助 */
			if (1 == Object->VehicleConfig[VCONFIG_KIND_EMERGENCY__STEERING_SUPPORT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_PedSwtReq, SWC_IPC_NULL);
			}
		}

		/* 碰撞安全辅助系统制动 */
		if ((3 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		  || (4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		  || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
		{
			Data[0] = 1; /*0x1:On*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_VehSwtReq, Data);

			/* 紧急转向辅助 */
			if (1 == Object->VehicleConfig[VCONFIG_KIND_EMERGENCY__STEERING_SUPPORT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_VehSwtReq, SWC_IPC_NULL);
			}
		}

		/* 交叉路口辅助 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_AEB_JUNCTION_ASSIST])
		{
			Data[0] = 1; /*0x1:On*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_JASwtReq, Data);
		}

		/* 前碰撞预警灵敏度 */
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		 || (4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		 || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCW_SnvtySet, SWC_IPC_NULL);
		}

		/* 自动紧急转向辅助 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01)\
		 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_AUTO_EVASIVE_STEERING])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AESSwtReq, SWC_IPC_NULL);
		}
		#endif

		/* 侧后辅助系统 : 并线辅助 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_LANE_CHANGE_ASSIST])
		{
			if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
            {
                /* 国内 */
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCASwtReq, SWC_IPC_NULL);
            }
            else
            {
                /* 国外 */
				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
                Data[0] = 1; /*0x1:On*/
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCASwtReq, Data);
				#endif
            }
		}

		/* 侧后辅助系统 :       开门预警 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_DR_OPEN_WARNING])
		{
            if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
            {
                /* 国内 */
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DOWSwtReq, SWC_IPC_NULL);
            }
            else
            {
                /* 国外 */
				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DOWSwtReq, SWC_IPC_NULL);
				#endif
            }
		}

		/* 侧后辅助系统 :       后碰撞预警 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_REAR_COLLISION_WARNING])
		{
            if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
            {
                /* 国内 */
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCWSwtReq, SWC_IPC_NULL);
            }
            else
            {
                /* 国外 */
				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCWSwtReq, SWC_IPC_NULL);
				#endif
            }
		}

		/* 侧后辅助系统 : 倒车侧向警告 */
		if ((2 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA])
		 || (4 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA]))
		{
			if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
			{
				/* 国内 */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTASwtReq, SWC_IPC_NULL);
			}
			else
			{
				/* 国外 */
				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTASwtReq, SWC_IPC_NULL);
				#endif
			}
		}

		/* 侧后辅助系统 : 倒车侧向制动 */
		if (4 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA])
	 	{
            if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
            {
                /* 国内 */
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTABrkSwtReq, SWC_IPC_NULL);
            }
            else
            {
                /* 国外 */
				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTABrkSwtReq, SWC_IPC_NULL);
				#endif
            }
	 	}

		/* 智慧巡航系统 : 自动变道辅助 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02)
        if ((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			((1 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]) || \
			(2 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER])))
        {
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SwtReq, SWC_IPC_NULL);
        }
		#endif

		/* 智慧巡航系统 : 变道超车提醒 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02)
        if (0 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST])
        {
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALC_SwtReq, SWC_IPC_NULL);
        }
		else if((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			((1 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]) || \
			(2 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER])))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALC_SwtReq, SWC_IPC_NULL);
		}
		#endif

        /* 智慧巡航系统 : 变道超车提醒灵敏度 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_B03)
		if (0 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST])
        {
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SnvtySet, SWC_IPC_NULL);
        }
		else if((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			(1 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]))
		{
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SnvtySet, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		/* 智慧巡航系统：自动导航辅助 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_NAVIGATION_ON_HIGHWAYPILOT])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NOH_Swt_Req, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03)
		/* 智慧巡航系统：意图确认 */
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			(2 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LaneChngCfmSwt, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		/* 智慧巡航系统：智能调速 */
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			(2 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoSpdSetSwt, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
		 && (1 == Object->VehicleConfig[VCONFIG_KIND_AMBIENT_LIGHT_CONTROL]))
		{
			/* 分区开关:左侧仪表板氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LeftPanelALCMSwt, SWC_IPC_NULL);
			/* 分区开关：右侧仪表板氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RightPanelALCMSwt, SWC_IPC_NULL);
			/* 分区开关：主驾氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：副驾氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：左后门氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LRDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：右后门氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：脚窝氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FootALCMSwt, SWC_IPC_NULL);
			/* 分区开关：顶棚氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofALCMSwt, SWC_IPC_NULL);
		}
		#endif

		/* 空调自干燥 */
		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_A_C_SELF_DRYING])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoDryingSwt, SWC_IPC_NULL);
		}
		#endif

	}
	else
	{
		SWC_IPC_PRINT_ERROR("Vehicle control can signal ignition off phase read vehicle config faild!");
	}

	SWC_IPC_PRINT_INFO("Vehicle control can signal ignition off phase work start!");
}

/**********************************************************************************************************
*Function   : IPC_OS_IgnOffCanSignalOutput                                                                *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : XU                                                                                          *
*                                                                                                         *
*Date       : 2022-02-15                                                                                  *
**********************************************************************************************************/
static void IPC_OS_IgnOffCanSignalOutput(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[1];
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;
	(void)Object;

	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();

    (void)SWC_IPC_PRINT_DEBUG("%s", __FUNCTION__);
	if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
	{
		/* 行人安全辅助系统 */
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		 || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
		{
			Data[0] = 1; /*0x1:On*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_PedSwtReq, Data);

			/* 紧急转向辅助 */
			if (1 == Object->VehicleConfig[VCONFIG_KIND_EMERGENCY__STEERING_SUPPORT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_PedSwtReq, SWC_IPC_NULL);
			}
		}

		/* 碰撞安全辅助系统制动 */
		if ((3 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		  || (4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		  || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
		{
			Data[0] = 1; /*0x1:On*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_VehSwtReq, Data);

			/* 紧急转向辅助 */
			if (1 == Object->VehicleConfig[VCONFIG_KIND_EMERGENCY__STEERING_SUPPORT])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ESS_VehSwtReq, SWC_IPC_NULL);
			}
		}

		/* 交叉路口辅助 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_AEB_JUNCTION_ASSIST])
		{
			Data[0] = 1; /*0x1:On*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AEB_JASwtReq, Data);
		}

		/* 前碰撞预警灵敏度 */
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		 || (4 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING])
		 || (5 == Object->VehicleConfig[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FCW_SnvtySet, SWC_IPC_NULL);
		}

		/* 自动紧急转向辅助 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_P01)\
		 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_AUTO_EVASIVE_STEERING])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AESSwtReq, SWC_IPC_NULL);
		}
		#endif

		/* 侧后辅助系统 : 并线辅助 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_LANE_CHANGE_ASSIST])
		{
			if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
            {
                /* 国内 */
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCASwtReq, SWC_IPC_NULL);
            }
            else
            {
                /* 国外 */
				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
                Data[0] = 1; /*0x1:On*/
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCASwtReq, Data);
				#endif
            }
		}

		/* 侧后辅助系统 :       开门预警 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_DR_OPEN_WARNING])
		{
            if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
            {
                /* 国内 */
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DOWSwtReq, SWC_IPC_NULL);
            }
            else
            {
                /* 国外 */
				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DOWSwtReq, SWC_IPC_NULL);
				#endif
            }
		}

		/* 侧后辅助系统 :       后碰撞预警 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_REAR_COLLISION_WARNING])
		{
            if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
            {
                /* 国内 */
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCWSwtReq, SWC_IPC_NULL);
            }
            else
            {
                /* 国外 */
				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCWSwtReq, SWC_IPC_NULL);
				#endif
            }
		}

		/* 侧后辅助系统 : 倒车侧向警告 */
		if ((2 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA])
		 || (4 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA]))
		{
			if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
			{
				/* 国内 */
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTASwtReq, SWC_IPC_NULL);
			}
			else
			{
				/* 国外 */
				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTASwtReq, SWC_IPC_NULL);
				#endif
			}
		}

		/* 侧后辅助系统 : 倒车侧向制动 */
		if (4 == Object->VehicleConfig[VCONFIG_KIND_PAS_CTA])
	 	{
            if (0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
            {
                /* 国内 */
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTABrkSwtReq, SWC_IPC_NULL);
            }
            else
            {
                /* 国外 */
				#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01)\
				 || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
			    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RCTABrkSwtReq, SWC_IPC_NULL);
				#endif
            }
	 	}

		/* 智慧巡航系统 : 自动变道辅助 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
        if ((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			((1 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]) || \
			(2 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER])))
        {
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SwtReq, SWC_IPC_NULL);
        }
		#endif

		/* 智慧巡航系统 : 变道超车提醒 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
        if (0 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST])
        {
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALC_SwtReq, SWC_IPC_NULL);
        }
		else if((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			((1 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]) || \
			(2 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER])))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALC_SwtReq, SWC_IPC_NULL);
		}
		#endif

        /* 智慧巡航系统 : 变道超车提醒灵敏度 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P01)
		if (0 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST])
        {
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SnvtySet, SWC_IPC_NULL);
        }
		else if((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			(1 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]))
		{
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HWA_SnvtySet, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P01)
		/* 智慧巡航系统：自动导航辅助 */
		if (1 == Object->VehicleConfig[VCONFIG_KIND_NAVIGATION_ON_HIGHWAYPILOT])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NOH_Swt_Req, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) //|| (defined SWC_IPC_PROJECT_TYPE_P01)
		/* 智慧巡航系统：意图确认 */
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			(2 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LaneChngCfmSwt, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) //|| (defined SWC_IPC_PROJECT_TYPE_P01)
		/* 智慧巡航系统：智能调速 */
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST]) && \
			(2 == Object->VehicleConfig[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoSpdSetSwt, SWC_IPC_NULL);
		}
		#endif

		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if(((5 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (6 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]) || (7 == Object->VehicleConfig[VCONFIG_KIND_MOOD_LAMP]))\
		 && (1 == Object->VehicleConfig[VCONFIG_KIND_AMBIENT_LIGHT_CONTROL]))
		{
			/* 分区开关:左侧仪表板氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LeftPanelALCMSwt, SWC_IPC_NULL);
			/* 分区开关：右侧仪表板氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RightPanelALCMSwt, SWC_IPC_NULL);
			/* 分区开关：主驾氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：副驾氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：左后门氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LRDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：右后门氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRDoorALCMSwt, SWC_IPC_NULL);
			/* 分区开关：脚窝氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FootALCMSwt, SWC_IPC_NULL);
			/* 分区开关：顶棚氛围灯开关 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RoofALCMSwt, SWC_IPC_NULL);
		}
		#endif

		/* 空调自干燥 */
		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_A_C_SELF_DRYING])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_AutoDryingSwt, SWC_IPC_NULL);
		}
		#endif
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Vehicle control can signal ignition off phase read vehicle config faild!");
	}

	SWC_IPC_PRINT_INFO("Vehicle control can signal ignition off phase work start!");
}

/**********************************************************************************************************
*Function   : IPC_PowerModeCanSignalOutputHandle                                                          *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Chen Tuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-08-25                                                                                  *
**********************************************************************************************************/
static void IPC_PowerModeCanSignalOutputHandle(SWC_IPC_AppMsgObject * Object)
{
	uint8 u8rteSysPowerMod, u8rteSysPowerModVld, u8SysPowerMod;
	boolean boSysPowerModVld;

	u8rteSysPowerMod    = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD,    (uint8*)&u8SysPowerMod,    (uint8)sizeof(u8SysPowerMod));
	u8rteSysPowerModVld = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMODVLD, (uint8*)&boSysPowerModVld, (uint8)sizeof(boSysPowerModVld));

	if(((RTE_E_OK == u8rteSysPowerMod) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == u8rteSysPowerMod))\
	&& ((RTE_E_OK == u8rteSysPowerModVld) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == u8rteSysPowerModVld)) && (1 == boSysPowerModVld))
	{
		u8SysPowerMod += 1;
	}
	else
	{
		u8SysPowerMod = (uint8)IGN_Invalid;
	}

	if(u8SysPowerMod != Object->u8PowerModSigValueBK)
	{
		if(SWC_IPC_NULL != IPCPowerModeHandleTbl[u8SysPowerMod][Object->u8PowerModSigValueBK].PowerModeStateChangeHandle)
		{
			 IPCPowerModeHandleTbl[u8SysPowerMod][Object->u8PowerModSigValueBK].PowerModeStateChangeHandle(Object);
		}
		else
		{
			// This power switch does not need to be done.
		}

		Object->u8PowerModSigValueBK = u8SysPowerMod;
	}
	else
	{
		// Same power mode. Nothing to do.
	}

	return ;
}
/**********************************************************************************************************
*Function   : IPC_IGNACCToOFFCanSignalOutput_Handle                                                       *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Chen Tuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-08-25                                                                                  *
**********************************************************************************************************/
static void IPC_IGNACCToOFFCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object)
{
	uint8 CountryFlag = 0;
	CountryFlag = IPC_GetCountryProcess(Object);
	if(2U == CountryFlag)
	{
		IPC_OS_IgnOffCanSignalOutput(Object);
	}
	else
	{
		IPC_IgnOffCanSignalOutput(Object);
	}

	return ;
}
/**********************************************************************************************************
*Function   : IPC_IGNONToOFFCanSignalOutput_Handle                                                        *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Chen Tuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-08-25                                                                                  *
**********************************************************************************************************/
static void IPC_IGNONToOFFCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object)
{

	uint8 CountryFlag = 0;
	CountryFlag = IPC_GetCountryProcess(Object);
	if(2U == CountryFlag)
	{
		IPC_OS_IgnOffCanSignalOutput(Object);
	}
	else
	{
		IPC_IgnOffCanSignalOutput(Object);
	}

	return ;
}
/**********************************************************************************************************
*Function   : IPC_IGNCrankToOFFCanSignalOutput_Handle                                                     *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Chen Tuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-08-25                                                                                  *
**********************************************************************************************************/
static void IPC_IGNCrankToOFFCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object)
{

	uint8 CountryFlag = 0;
	CountryFlag = IPC_GetCountryProcess(Object);
	if(2U == CountryFlag)
	{
		IPC_OS_IgnOffCanSignalOutput(Object);
	}
	else
	{
		IPC_IgnOffCanSignalOutput(Object);
	}

	return ;
}
/**********************************************************************************************************
*Function   : IPC_IGNInvalidToOFFCanSignalOutput_Handle                                                   *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Chen Tuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-08-25                                                                                  *
**********************************************************************************************************/
static void IPC_IGNInvalidToOFFCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object)
{

	uint8 CountryFlag = 0;
	CountryFlag = IPC_GetCountryProcess(Object);
	if(2U == CountryFlag)
	{
		IPC_OS_IgnOffCanSignalOutput(Object);
	}
	else
	{
		IPC_IgnOffCanSignalOutput(Object);
	}

	return ;
}

/**********************************************************************************************************
*Function   : IPC_IGNOFFToONCanSignalOutput                                                               *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : XU                                                                                          *
*                                                                                                         *
*Date       : 2022-02-15                                                                                  *
**********************************************************************************************************/
static void IPC_IGNOFFToONCanSignalOutput(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[1];
	uint8 signalData = 0;
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;

	(void)SWC_IPC_PRINT_DEBUG("%s", __FUNCTION__);
	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();
	if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
	{
		/* 智能安全带 减少安全带松弛量(主驾) */
	#if (defined SWC_IPC_PROJECT_TYPE_D03) // || (defined SWC_IPC_PROJECT_TYPE_D01)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIBSRSwtSet, SWC_IPC_NULL);
		}
	#endif

		/* 智能安全带 减少安全带松弛量(副驾) */
	#if (defined SWC_IPC_PROJECT_TYPE_P03)
		// || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_BELT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMI_P_BSR_SwtSet, SWC_IPC_NULL);
		}
	#endif

		/* 智能安全带 安全带震动提醒 */
	#if (defined SWC_IPC_PROJECT_TYPE_D03) //|| (defined SWC_IPC_PROJECT_TYPE_D01)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIHWSwtSet, SWC_IPC_NULL);
		}
	#endif

		/* 车速关窗 && 闭锁关窗 */
	#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		/* 车速关窗 */
		if (((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]))
		 && ((3 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]))
		 && ((3 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]))
		 && (1 == Object->VehicleConfig[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ClsWinSpdSet, SWC_IPC_NULL);
		}

		/* 闭锁关窗 */
		if (((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]))
			 && ((3 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]))
			 && ((3 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]))
			 && (1 == Object->VehicleConfig[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE])
			 && ((1 == Object->VehicleConfig[VCONFIG_KIND_DOOR_MODULE_TYPE]) || (2 == Object->VehicleConfig[VCONFIG_KIND_DOOR_MODULE_TYPE])))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWinSet, SWC_IPC_NULL);
		}
	#endif

		/* 随速天窗 */
	#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_SPEED__SENSING_SUNROOF_SWITCH])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SrSpdCtrlSwt, SWC_IPC_NULL);
		}
	#endif

		/* 紧急制动 */
	#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_ESS_SYSTEM])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ABSLmpSet, SWC_IPC_NULL);
		}
	#endif

		/* 主驾座椅记忆 */
	#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03)\
		 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (4 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (6 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (7 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (8 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
		{
			if ((1 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE])|| (5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE]))
			{
				IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, &signalData);
				if (0 != signalData)
				{
					Data[0] = 2; /*0x2:Bring Up The Account*/
					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSet, Data);
					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, SWC_IPC_NULL);
				}
			}
		}
	#endif
	}

}

/**********************************************************************************************************
*Function   : IPC_OS_IGNOFFToONCanSignalOutput                                                            *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : XU                                                                                          *
*                                                                                                         *
*Date       : 2022-02-15                                                                                  *
**********************************************************************************************************/
static void IPC_OS_IGNOFFToONCanSignalOutput(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[1];
	uint8 signalData = 0;
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;

	(void)SWC_IPC_PRINT_DEBUG("%s", __FUNCTION__);
	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();
	if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
	{
		/* 智能安全带 减少安全带松弛量(主驾) */
	#if (defined SWC_IPC_PROJECT_TYPE_D01)  || (defined SWC_IPC_PROJECT_TYPE_D03)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIBSRSwtSet, SWC_IPC_NULL);
		}
	#endif

		/* 智能安全带 减少安全带松弛量(副驾) */
	#if (defined SWC_IPC_PROJECT_TYPE_P03)
		// || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_BELT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMI_P_BSR_SwtSet, SWC_IPC_NULL);
		}
	#endif

		/* 智能安全带 安全带震动提醒 */
	#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIHWSwtSet, SWC_IPC_NULL);
		}
	#endif

		/* 车速关窗 && 闭锁关窗 */
	#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
		/* 车速关窗 */
		if (((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]))
		 && ((3 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]))
		 && ((3 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]))
		 && (1 == Object->VehicleConfig[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ClsWinSpdSet, SWC_IPC_NULL);
		}

		/* 闭锁关窗 */
		if (((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]))
			 && ((3 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]))
			 && ((3 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]))
			 && (1 == Object->VehicleConfig[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE])
			 && ((1 == Object->VehicleConfig[VCONFIG_KIND_DOOR_MODULE_TYPE]) || (2 == Object->VehicleConfig[VCONFIG_KIND_DOOR_MODULE_TYPE])))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWinSet, SWC_IPC_NULL);
		}
	#endif

		/* 随速天窗 */
	#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_SPEED__SENSING_SUNROOF_SWITCH])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SrSpdCtrlSwt, SWC_IPC_NULL);
		}
	#endif

		/* 紧急制动 */
	#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_ESS_SYSTEM])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ABSLmpSet, SWC_IPC_NULL);
		}
	#endif

		/* 主驾座椅记忆 */
	#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03)\
		 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P01)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (4 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (6 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (7 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (8 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
		{
			if ((1 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE])|| (5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE]))
			{
				IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, &signalData);
				if (0 != signalData)
				{
					Data[0] = 2; /*0x2:Bring Up The Account*/
					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSet, Data);
					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, SWC_IPC_NULL);
				}
			}
		}
	#endif

	}

}

/**********************************************************************************************************
*Function   : IPC_IGNOFFToONCanSignalOutput_Handle                                                        *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Chen Tuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-08-25                                                                                  *
**********************************************************************************************************/
static void IPC_IGNOFFToONCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object)
{
	uint8 CountryFlag = 0;
	CountryFlag = IPC_GetCountryProcess(Object);
	if(2U == CountryFlag)
	{
		IPC_OS_IgnOnCanSignalOutput(Object);
		IPC_OS_IGNOFFToONCanSignalOutput(Object);
	}
	else
	{
		IPC_IgnOnCanSignalOutput(Object);
		IPC_IGNOFFToONCanSignalOutput(Object);
	}

	return ;
}
/**********************************************************************************************************
*Function   : IPC_IGNACCToONCanSignalOutput_Handle                                                        *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Chen Tuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-08-25                                                                                  *
**********************************************************************************************************/
static void IPC_IGNACCToONCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object)
{
	uint8 CountryFlag = 0;
	CountryFlag = IPC_GetCountryProcess(Object);
	if(2U == CountryFlag)
	{
		IPC_OS_IgnOnCanSignalOutput(Object);
	}
	else
	{
		IPC_IgnOnCanSignalOutput(Object);
	}

	return ;
}

/**********************************************************************************************************
*Function   : IPC_IGNCrankToONCanSignalOutput                                                             *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : XU                                                                                          *
*                                                                                                         *
*Date       : 2022-02-15                                                                                  *
**********************************************************************************************************/
static void IPC_IGNCrankToONCanSignalOutput(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[1];
	uint8 signalData = 0;
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;
	(void)Object;

	(void)SWC_IPC_PRINT_DEBUG("%s", __FUNCTION__);

	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();
	if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
	{
		/* 解闭锁提示 */
	#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_BLOCKING_PROMPT_TYPE])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockPromptFunSet, SWC_IPC_NULL);
		}
	#endif

		/* 主动进入解锁 */
	#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryUnlockSet, SWC_IPC_NULL);
		}
	#endif

		/* 主动离开闭锁 */
	#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if ((2 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryLockSet, SWC_IPC_NULL);
		}
	#endif

		/* 蓝牙泊车 */
	#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 || (5 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 || (6 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 || (7 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
		{
			/* 蓝牙泊入自动闭锁 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPAEntryLockSet, SWC_IPC_NULL);
			/* 蓝牙泊出自动解锁 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPALvngUnlockSet, SWC_IPC_NULL);
		}
	#endif

		/* 货箱照明设置(皮卡) */
	#if defined SWC_IPC_PROJECT_TYPE_P05
		if (1 == Object->VehicleConfig[VCONFIG_KIND_DECK_LAMP])
		{
			/* 货厢灯自动开启功能 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FreightLmpAutoSet, SWC_IPC_NULL);
		}
	#endif

		/* 主驾座椅记忆 */
	#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03)\
		 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
		 	(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (4 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (6 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (7 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (8 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
		{
			if ((1 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE])|| (5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE]))
			{
				IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, &signalData);
				if (0 != signalData)
				{
					Data[0] = 2; /*0x2:Bring Up The Account*/
					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSet, Data);
					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, SWC_IPC_NULL);
				}
			}
		}
	#endif

		/* 车窗短升短降 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_WINDOW_SHORT_LIFT_DROP_FUNCTION])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WinShortUpShortDownSet, SWC_IPC_NULL);
		}
		#endif

		/* 主驾驶座椅按摩设置 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P01)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
		{
			Data[0] = 0; /*0x0:Off*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgLvlSet, Data);
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif


		/* 副驾驶座椅按摩设置 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
			(defined SWC_IPC_PROJECT_TYPE_P01)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
		{
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgLvlSet, Data);
			/* 按摩模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		/* 后排左侧座椅按摩设置 ZV2+ZS9 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
		{
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgLvlSet, Data);
			/* 按摩模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		/* 后排右侧座椅按摩设置 ZV3+ZS9 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_P01)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
		{
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgLvlSet, Data);
			/* 按摩模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif
	}

}

/**********************************************************************************************************
*Function   : IPC_OS_IGNCrankToONCanSignalOutput                                                          *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : XU                                                                                          *
*                                                                                                         *
*Date       : 2022-02-15                                                                                  *
**********************************************************************************************************/
static void IPC_OS_IGNCrankToONCanSignalOutput(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[1];
	uint8 signalData = 0;
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;
	(void)Object;

	(void)SWC_IPC_PRINT_DEBUG("%s", __FUNCTION__);

	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();
	if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
	{
		/* 解闭锁提示 */
	#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if(1 == Object->VehicleConfig[VCONFIG_KIND_BLOCKING_PROMPT_TYPE])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockPromptFunSet, SWC_IPC_NULL);
		}
	#endif

		/* 主动进入解锁 */
	#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryUnlockSet, SWC_IPC_NULL);
		}
	#endif

		/* 主动离开闭锁 */
	#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_B02) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01) || (defined SWC_IPC_PROJECT_TYPE_D02)
		if ((2 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM])
		 || (3 == Object->VehicleConfig[VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ActvEntryLockSet, SWC_IPC_NULL);
		}
	#endif

		/* 蓝牙泊车 */
	#if (defined SWC_IPC_PROJECT_TYPE_P01)
		if ((4 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 || (5 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 || (6 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM])
		 || (7 == Object->VehicleConfig[VCONFIG_KIND_AUTO_PARKING_SYSTEM]))
		{
			/* 蓝牙泊入自动闭锁 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPAEntryLockSet, SWC_IPC_NULL);
			/* 蓝牙泊出自动解锁 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_BTAPALvngUnlockSet, SWC_IPC_NULL);
		}
	#endif

		/* 货箱照明设置(皮卡) */
	#if defined SWC_IPC_PROJECT_TYPE_P05
		if (1 == Object->VehicleConfig[VCONFIG_KIND_DECK_LAMP])
		{
			/* 货厢灯自动开启功能 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FreightLmpAutoSet, SWC_IPC_NULL);
		}
	#endif

		/* 主驾座椅记忆 */
	#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_B03)\
		 || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
		 	(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
		 	(defined SWC_IPC_PROJECT_TYPE_P01)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (4 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (5 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (6 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (7 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT])
		  || (8 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT]))
		{
			if ((1 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE])|| (5 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MEMORY_TYPE]))
			{
				IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, &signalData);
				if (0 != signalData)
				{
					Data[0] = 2; /*0x2:Bring Up The Account*/
					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSet, Data);
					IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ChairMemPosnSetResult, SWC_IPC_NULL);
				}
			}
		}
	#endif

		/* 车窗短升短降 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05)
		if (1 == Object->VehicleConfig[VCONFIG_KIND_WINDOW_SHORT_LIFT_DROP_FUNCTION])
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_WinShortUpShortDownSet, SWC_IPC_NULL);
		}
		#endif

		/* 主驾驶座椅按摩设置 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || \
			(defined SWC_IPC_PROJECT_TYPE_P01)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
		{
			Data[0] = 0; /*0x0:Off*/
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgLvlSet, Data);
            IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif


		/* 副驾驶座椅按摩设置 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) ||\
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) ||\
			(defined SWC_IPC_PROJECT_TYPE_P01)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE])))
		{
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgLvlSet, Data);
			/* 按摩模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		/* 后排左侧座椅按摩设置 ZV2+ZS9 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P01) || \
			(defined SWC_IPC_PROJECT_TYPE_D02)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
		{
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgLvlSet, Data);
			/* 按摩模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RLSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif

		/* 后排右侧座椅按摩设置 ZV3+ZS9 */
		#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02) || \
			(defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_P01)
		if (((1 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]) || (2 == Object->VehicleConfig[VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN]))
		 && ((2 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE]) || (3 == Object->VehicleConfig[VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE])))
		{
			/* 按摩强度 */
			Data[0] = 0;/* 0x0:OFF */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgLvlSet, Data);
			/* 按摩模式 */
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRSeatMassgModSet, SWC_IPC_NULL);
		}
		#endif
	}

}

/**********************************************************************************************************
*Function   : IPC_IGNCrankToONCanSignalOutput_Handle                                                      *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Chen Tuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-08-25                                                                                  *
**********************************************************************************************************/
static void IPC_IGNCrankToONCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object)
{
	uint8 CountryFlag = 0;
	CountryFlag = IPC_GetCountryProcess(Object);
	if(2U == CountryFlag)
	{
		IPC_OS_IGNCrankToONCanSignalOutput(Object);
	}
	else
	{
		IPC_IGNCrankToONCanSignalOutput(Object);
	}

	return ;
}
/**********************************************************************************************************
*Function   : IPC_IGNInvalidToONCanSignalOutput_Handle                                                    *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Chen Tuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-08-25                                                                                  *
**********************************************************************************************************/
static void IPC_IGNInvalidToONCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object)
{

	IPC_IGNOFFToONCanSignalOutput_Handle(Object);

	return ;
}

/**********************************************************************************************************
*Function   : IPC_IGNOFFToCrankCanSignalOutput                                                             *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : XU                                                                                          *
*                                                                                                         *
*Date       : 2022-02-15                                                                                  *
**********************************************************************************************************/
static void IPC_IGNOFFToCrankCanSignalOutput(SWC_IPC_AppMsgObject * Object)
{
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;

	(void)SWC_IPC_PRINT_DEBUG("%s", __FUNCTION__);
	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();
	if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
	{
		/* 智能安全带 减少安全带松弛量(主驾) */
		#if (defined SWC_IPC_PROJECT_TYPE_D03)	//|| (defined SWC_IPC_PROJECT_TYPE_D01)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIBSRSwtSet, SWC_IPC_NULL);
		}
		#endif

		/* 智能安全带 减少安全带松弛量(副驾) */
		#if (defined SWC_IPC_PROJECT_TYPE_P03)
		// || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_BELT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMI_P_BSR_SwtSet, SWC_IPC_NULL);
		}
		#endif

		/* 智能安全带 安全带震动提醒 */
		#if (defined SWC_IPC_PROJECT_TYPE_D03) //|| (defined SWC_IPC_PROJECT_TYPE_D01)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIHWSwtSet, SWC_IPC_NULL);
		}
		#endif

		/* 车速关窗 && 闭锁关窗 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
		/* 车速关窗 */
		if (((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]))
	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]))
	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]))
		 && (1 == Object->VehicleConfig[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ClsWinSpdSet, SWC_IPC_NULL);
		}

		/* 闭锁关窗 */
		if (((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]))
    	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]))
    	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]))
    		 && (1 == Object->VehicleConfig[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE])
			 && ((1 == Object->VehicleConfig[VCONFIG_KIND_DOOR_MODULE_TYPE]) || (2 == Object->VehicleConfig[VCONFIG_KIND_DOOR_MODULE_TYPE])))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWinSet, SWC_IPC_NULL);
		}
		#endif

		/* 随速天窗 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03)
			if(1 == Object->VehicleConfig[VCONFIG_KIND_SPEED__SENSING_SUNROOF_SWITCH])
			{
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SrSpdCtrlSwt, SWC_IPC_NULL);
			}
		#endif

		/* 紧急制动 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02)
			if(1 == Object->VehicleConfig[VCONFIG_KIND_ESS_SYSTEM])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ABSLmpSet, SWC_IPC_NULL);
			}
		#endif

	}
	return ;
}

/**********************************************************************************************************
*Function   : IPC_OS_IGNOFFToCrankCanSignalOutput                                                             *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : XU                                                                                          *
*                                                                                                         *
*Date       : 2022-02-15                                                                                  *
**********************************************************************************************************/
static void IPC_OS_IGNOFFToCrankCanSignalOutput(SWC_IPC_AppMsgObject * Object)
{
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;

	(void)SWC_IPC_PRINT_DEBUG("%s", __FUNCTION__);
	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();
	if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
	{
		/* 智能安全带 减少安全带松弛量(主驾) */
		#if (defined SWC_IPC_PROJECT_TYPE_D01)	|| (defined SWC_IPC_PROJECT_TYPE_D03)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIBSRSwtSet, SWC_IPC_NULL);
		}
		#endif

		/* 智能安全带 减少安全带松弛量(副驾) */
		#if (defined SWC_IPC_PROJECT_TYPE_P03)
		// || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_FRONT_PASSENGER_BELT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMI_P_BSR_SwtSet, SWC_IPC_NULL);
		}
		#endif

		/* 智能安全带 安全带震动提醒 */
		#if (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D03)
		if ((1 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_BELT]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PPMIHWSwtSet, SWC_IPC_NULL);
		}
		#endif

		/* 车速关窗 && 闭锁关窗 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
		/* 车速关窗 */
		if (((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]))
	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]))
	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]))
		 && (1 == Object->VehicleConfig[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE]))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ClsWinSpdSet, SWC_IPC_NULL);
		}

		/* 闭锁关窗 */
		if (((2 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]) || (3 == Object->VehicleConfig[VCONFIG_KIND_DRIVER_WINDOW_OPERATING]))
    	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_PASSENGER_WINDOW_OPERATING]))
    	     && ((3 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]) || (4 == Object->VehicleConfig[VCONFIG_KIND_RR_1ST_WINDOW_OPERATING]))
    		 && (1 == Object->VehicleConfig[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE])
			 && ((1 == Object->VehicleConfig[VCONFIG_KIND_DOOR_MODULE_TYPE]) || (2 == Object->VehicleConfig[VCONFIG_KIND_DOOR_MODULE_TYPE])))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LockWinSet, SWC_IPC_NULL);
		}
		#endif

		/* 随速天窗 */
		#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03)
			if(1 == Object->VehicleConfig[VCONFIG_KIND_SPEED__SENSING_SUNROOF_SWITCH])
			{
    			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SrSpdCtrlSwt, SWC_IPC_NULL);
			}
		#endif

		/* 紧急制动 */
		#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
			(defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) || \
			(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
			if(1 == Object->VehicleConfig[VCONFIG_KIND_ESS_SYSTEM])
			{
				IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ABSLmpSet, SWC_IPC_NULL);
			}
		#endif

	}
	return ;
}


/**********************************************************************************************************
*Function   : IPC_IGNOFFToCrankCanSignalOutput_Handle                                                     *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Chen Tuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-08-25                                                                                  *
**********************************************************************************************************/
static void IPC_IGNOFFToCrankCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object)
{

	uint8 CountryFlag = 0;
	CountryFlag = IPC_GetCountryProcess(Object);
	if(2U == CountryFlag)
	{
		IPC_OS_IgnOnCanSignalOutput(Object);
		IPC_OS_IGNOFFToCrankCanSignalOutput(Object);
	}
	else
	{
		IPC_IgnOnCanSignalOutput(Object);
		IPC_IGNOFFToCrankCanSignalOutput(Object);
	}

	return ;
}
/**********************************************************************************************************
*Function   : IPC_IGNACCToCrankCanSignalOutput_Handle                                                     *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Chen Tuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-08-25                                                                                  *
**********************************************************************************************************/
static void IPC_IGNACCToCrankCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object)
{
	uint8 CountryFlag = 0;
	CountryFlag = IPC_GetCountryProcess(Object);
	if(2U == CountryFlag)
	{
		IPC_OS_IgnOnCanSignalOutput(Object);
	}
	else
	{
		IPC_IgnOnCanSignalOutput(Object);
	}

	return ;
}
/**********************************************************************************************************
*Function   : IPC_IGNInvalidToCrankCanSignalOutput_Handle                                                 *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Chen Tuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-08-25                                                                                  *
**********************************************************************************************************/
static void IPC_IGNInvalidToCrankCanSignalOutput_Handle(SWC_IPC_AppMsgObject * Object)
{
	IPC_IGNOFFToCrankCanSignalOutput_Handle(Object);

	return ;
}
/**********************************************************************************************************
*Function   : IPC_SpecialTxCanSignalOperation                                                             *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-01                                                                                  *
**********************************************************************************************************/
static void IPC_SpecialTxCanSignalOperation(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[4] = {0};
    uint8 u8SysPowerMod = 0;
	boolean boSysPowerModVld = FALSE;
    uint8 u8rteSysPowerMod = RTE_E_INVALID;
	uint8 u8rteSysPowerModVld = RTE_E_INVALID;
	uint8 u8SteerWheelHeatSwtReqTemp = 0;
	uint8 u8SteerWheelHeatSwtReqRec = 0;
	uint8 CountryFlag = 0;
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;
	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();
	/*---------------------------------------------------------------------------------------------------*/

	CountryFlag = IPC_GetCountryProcess(Object);
	/*Boot delay */
	#define IPC_TX_BOOT_DELAY (1000u/SWC_IPC_APPLICATION_TASK_CYCLE)
	if ((boolean)FALSE != Object->BootDelayTrigger)
	{
		if(2U == CountryFlag)
		{
			IPC_OS_TxCanSignalInit(Object);
		}
		else
		{
			IPC_TxCanSignalInit(Object);
		}

		/*Clear boot trigger*/
		Object->BootDelayTrigger = FALSE;
	}
	else
	{

	}
	/*---------------------------------------------------------------------------------------------------*/
	/*Com manager status */
	/* Data[0] : Current com status*/
	if (Object->RestoreCanSwitch == (uint8)SWC_IPC_CLEAR)
	{
		if (E_OK == Rte_Call_ComM_UserRequest_GetCurrentComMode(&Data[0]))
		{
			if (((uint8)COMM_NO_COMMUNICATION != Data[0]) && ((uint8)COMM_NO_COMMUNICATION == Object->ComMode))
			{
				Object->ComWakePhase1Trigger = TRUE;
				Object->ComWakePhase2Trigger = TRUE;
			}

			if(Data[0] != Object->ComMode)
			{
				Object->ComMode = Data[0];
			}
		}
	}
	else
	{/*Restore function is running , avoid or stop trigger com awake list*/
		Object->ComWakePhase1Trigger = FALSE;
		Object->ComWakePhase2Trigger = FALSE;
	}
	/*---------------------------------------------------------------------------------------------------*/
	/*Cluster power status */
	if (Object->RestoreCanSwitch == (uint8)SWC_IPC_CLEAR)
	{
		/*Cluster power mode changed , send event signal*/
		if ((boolean)FALSE != Object->IgnOnEvent)
		{
			Object->IgnOnTrigger = TRUE;
		}
		else if ((boolean)FALSE != Object->IgnOffEvent)
		{
			Object->IgnOffTrigger = TRUE;
		}
		else
		{
			/*Do nothing*/
		}
	}
	else
	{/*Restore function is running , avoid or stop trigger ign on/off list*/
		Object->IgnOnTrigger = FALSE;
		Object->IgnOffTrigger = FALSE;
	}
	/*---------------------------------------------------------------------------------------------------*/
	if ((boolean)FALSE == Object->BootDelayTrigger)
	{
		/*Network wake phase 1 delay*/
		#define IPC_NETWORK_WAKE_PHASE_1_DELAY (1000u/SWC_IPC_APPLICATION_TASK_CYCLE)
		if (FALSE != Object->ComWakePhase1Trigger)
		{
			if (Object->ComWakePhase1Tick >= IPC_NETWORK_WAKE_PHASE_1_DELAY)
			{
				if(2U == CountryFlag)
				{
					IPC_OS_ComWakePhase1CanSignalOutput(Object);
				}
				else
				{
					IPC_ComWakePhase1CanSignalOutput(Object);
				}

				Object->ComWakePhase1Trigger = FALSE;
				Object->ComWakePhase1Tick = 0;
			}
			else
			{
				Object->ComWakePhase1Tick ++;
			}
		}
		else
		{
			Object->ComWakePhase1Tick = 0;
		}

		/*Network wake phase 2 delay*/
		#define IPC_NETWORK_WAKE_PHASE_2_DELAY (6000u/SWC_IPC_APPLICATION_TASK_CYCLE)
		if (FALSE != Object->ComWakePhase2Trigger)
		{
			if (Object->ComWakePhase2Tick >= IPC_NETWORK_WAKE_PHASE_2_DELAY)
			{
				if(2U == CountryFlag)
				{
					IPC_OS_ComWakePhase2CanSignalOutput(Object);
				}
				else
				{
					IPC_ComWakePhase2CanSignalOutput(Object);
				}


				Object->ComWakePhase2Trigger = FALSE;
				Object->ComWakePhase2Tick = 0;
			}
			else
			{
				Object->ComWakePhase2Tick ++;
			}
		}
		else
		{
			Object->ComWakePhase2Tick = 0;
		}
	/*---------------------------------------------------------------------------------------------------*/
		/*Ign on / off */
		if (FALSE != Object->IgnOnTrigger)
		{
			//IPC_IgnOnCanSignalOutput(Object);

			Object->IgnOnTrigger = FALSE;
			Object->IgnOffTrigger = FALSE;
			// Object->ComWakePhase1Trigger = FALSE;
			// Object->ComWakePhase2Trigger = FALSE;
		}
		else if (FALSE != Object->IgnOffTrigger)
		{
			//IPC_IgnOffCanSignalOutput(Object);

			Object->IgnOnTrigger = FALSE;
			Object->IgnOffTrigger = FALSE;
			Object->ComWakePhase1Trigger = FALSE;
			Object->ComWakePhase2Trigger = FALSE;
		}
		else
		{

		}

		IPC_PowerModeCanSignalOutputHandle(Object);
	}
	/*---------------------------------------------------------------------------------------------------*/
	/*
		EEM1 : TranPMode_Sts + TranPMode_Req
	*/
	if ((uint8)RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_EEM1,SWC_IPC_NULL))
	{
		IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_TranPMode_Sts , Data);
		Object->AppNvm.u8TranPMode_Sts = Data[0];
	}
	/*---------------------------------------------------------------------------------------------------*/
	/* 方向盘加热：开关 */
	if(1u == Object->VehicleConfig[VCONFIG_KIND_STEERING_HEATING])
	{
		u8rteSysPowerMod    = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD,    &u8SysPowerMod,    (uint8)sizeof(u8SysPowerMod));
	    u8rteSysPowerModVld = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMODVLD, &boSysPowerModVld, (uint8)sizeof(boSysPowerModVld));
	    if(((RTE_E_OK == u8rteSysPowerMod) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == u8rteSysPowerMod))\
	    && ((RTE_E_OK == u8rteSysPowerModVld) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == u8rteSysPowerModVld)) && (1 == boSysPowerModVld))
	    {
			if(3u == u8SysPowerMod)
			{
				IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerWheelHeatdSts, (uint8 *)&u8SteerWheelHeatSwtReqRec);
				if(1u == u8SteerWheelHeatSwtReqRec)
				{
					Object->u8SteerWheelHeatdSts = u8SteerWheelHeatSwtReqRec;
				}
			}
			else if(2u == u8SysPowerMod)
			{
				if(Object->u8SysPowerMod_bk != u8SysPowerMod)
				{
					if(1u == Object->u8SteerWheelHeatdSts)
					{
						u8SteerWheelHeatSwtReqTemp = 2;
						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_SteerWheelHeatSwtReq, &u8SteerWheelHeatSwtReqTemp);

						Object->u8SteerWheelHeatdSts = 0;
					}
					else
					{
						// do nothing
					}
				}
			}
			else
			{
				// do nothing
			}
	    }
	    else
	    {
			// do nothing
	    }
	    Object->u8SysPowerMod_bk = u8SysPowerMod;
    }

    /*---------------------------------------------------------------------------------------------------*/
}
/**********************************************************************************************************
*Function   : IPC_API_ClusterPowerOperation                                                                   *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-16                                                                                  *
**********************************************************************************************************/
void IPC_API_ClusterPowerOperation(void)
{
#define IPC_CLUSTER_POWER_UPDATE_CYCLE (1000u/SWC_IPC_APPLICATION_TASK_CYCLE)

	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	SystemState_RecordType *PowerMode;
	IPC_M2S_ClusterAppSystemCLUSTERPOWER_t PowerState = {0};

	PowerMode = Rte_IRead_Common_GateWay_5msMainFunction_rpSR_SWCGateWay_Power_Out_SystemStateOut();

	/*Check ign event*/
	if ((SYSTEMSTATE_Cluster_ON == PowerMode->ClusterState)
	 && (SYSTEMSTATE_Cluster_ON != Object->ClusterState))
	{
		Object->IgnOnEvent = TRUE;
		Object->IgnOffEvent = FALSE;
	}
	else if ((SYSTEMSTATE_Cluster_ON != PowerMode->ClusterState)
		  && (SYSTEMSTATE_Cluster_ON == Object->ClusterState))
	{
		Object->IgnOnEvent = FALSE;
		Object->IgnOffEvent = TRUE;

		(void)SWC_IPC_PRINT_DEBUG("[CL-Power]:ON->OFF");
		PowerState.PowerChangedFlag = (uint8)1;
		PowerState.ClusterState = PowerMode->ClusterState;
		PowerState.VoltageState = PowerMode->s_PowerVoltage.state;
		Object->PowerStateChangedFlag = PowerState.PowerChangedFlag;

		/*Update cluster power mode to soc*/
		IPC_API_SetAppMsgBuffer((uint8)M2S_CLUSTER_POWER,
								(uint8 *)&PowerState,
								(uint16)sizeof(IPC_M2S_ClusterAppSystemCLUSTERPOWER_t));
	}
	else
	{
		Object->IgnOnEvent = FALSE;
		Object->IgnOffEvent = FALSE;
	}

	if (SYSTEMSTATE_Cluster_SHUTDOWN == PowerMode->ClusterState)
	{
		PowerState.PowerChangedFlag = (uint8)0;
		PowerState.ClusterState = PowerMode->ClusterState;
		PowerState.VoltageState = PowerMode->s_PowerVoltage.state;
		Object->PowerStateChangedFlag = PowerState.PowerChangedFlag;

		/*Update cluster power mode to soc*/
		IPC_API_SetAppMsgBuffer((uint8)M2S_CLUSTER_POWER,
		                   	   (uint8 *)&PowerState,
		                   	   (uint16)sizeof(IPC_M2S_ClusterAppSystemCLUSTERPOWER_t));
	}
	else
	{
		/* do nothing */
	}

	/*Check power changed*/
	if ((PowerMode->ClusterState != Object->ClusterState)
	 || (PowerMode->s_PowerVoltage.state != Object->VoltageState))
	{
		PowerState.ClusterState = PowerMode->ClusterState;
		PowerState.VoltageState = PowerMode->s_PowerVoltage.state;
		PowerState.PowerChangedFlag = Object->PowerStateChangedFlag;

		(void)SWC_IPC_PRINT_DEBUG("[CL-CS]:pre:%d,curr:%d", Object->ClusterState, PowerMode->ClusterState);
		(void)SWC_IPC_PRINT_DEBUG("[CL-PV]:pre:%d,curr:%d", Object->VoltageState, PowerMode->s_PowerVoltage.state);

		/*Update cluster power mode to soc*/
		IPC_API_AppMsgTransmit((uint8)M2S_CLUSTER_POWER,
			                   (uint8 *)&PowerState,
			                   (uint16)sizeof(IPC_M2S_ClusterAppSystemCLUSTERPOWER_t), TRUE);

		Object->ClusterState = PowerMode->ClusterState;
		Object->VoltageState = PowerMode->s_PowerVoltage.state;
		/*Clear tick*/
		Object->PowerModeTick = IPC_CLUSTER_POWER_UPDATE_CYCLE;
	}
	else if (Object->PowerModeTick == 0)
	{
		PowerState.ClusterState = Object->ClusterState;
		PowerState.VoltageState = Object->VoltageState;
		PowerState.PowerChangedFlag = Object->PowerStateChangedFlag;

		IPC_API_AppMsgTransmit((uint8)M2S_CLUSTER_POWER,
			                   (uint8 *)&PowerState,
			                   (uint16)sizeof(IPC_M2S_ClusterAppSystemCLUSTERPOWER_t), TRUE);
		/*Clear tick*/
		Object->PowerModeTick = IPC_CLUSTER_POWER_UPDATE_CYCLE;
	}
	else
	{
		Object->PowerModeTick -= 1;
	}

}
/**********************************************************************************************************
*Function   : IPC_ClusterTxCanSignalUpdate                                                                *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-09                                                                                  *
**********************************************************************************************************/
static void IPC_ClusterTxCanSignalUpdate(SWC_IPC_AppMsgObject * Object)
{
#if (defined SWC_IPC_PROJECT_TYPE_B03)
	SG_ACC7_ACC_FD2 ACC7_ACC_FD2_Data = {0};
	SG_ACC3_ACC_FD2 ACC3_ACC_FD2_Data = {0};
	SG_ACC4_ACC_FD2 ACC4_ACC_FD2_Data = {0};
	SG_ACC6_ACC_FD2 ACC6_ACC_FD2_Data = {0};
	SG_ACC8_ACC_FD2 ACC8_ACC_FD2_Data = {0};
#endif
	uint8 MsgBuffer[64] = {0};
	uint8 E2ESwitch = 0;
	uint32 ACC7_E2EStatus = 0;
	uint32 ACC3_E2EStatus = 0;
	uint32 ACC4_E2EStatus = 0;
	uint32 ACC6_E2EStatus = 0;
	uint32 ACC8_E2EStatus = 0;
	uint8 ACC_Status = RTE_E_INVALID;
    //uint8* Object->VehicleConfig = SWC_IPC_NULL;
	#ifndef SWC_IPC_PROJECT_TYPE_B03
    uint8 ACC_FD2_Status = E_NOT_OK;
	#endif

	//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();

	/*Update transmit can message by call rte interface .*/
	(void)IPC_API_SetTxCanMsg((uint32)SWC_IPC_CAN_MSG_HUT34 , SWC_IPC_NULL);

	/*Update transmit can message by call rte interface .*/
#define IPC_TX_MSG_HUT_IP1_CYCLE (100u/SWC_IPC_APPLICATION_TASK_CYCLE)

	if (0u == Object->HUT_IP1_Tick)
	{
		#if (defined SWC_IPC_PROJECT_TYPE_B03)
		(void)IPC_API_SetTxCanMsg((uint32)SWC_IPC_CAN_MSG_HUT_IP1 , SWC_IPC_NULL);
		#else
		(void)IPC_API_SetTxCanMsg((uint32)SWC_IPC_CAN_MSG_IP1 , SWC_IPC_NULL);
		#endif

		Object->HUT_IP1_Tick = IPC_TX_MSG_HUT_IP1_CYCLE;
	}
	else
	{
		Object->HUT_IP1_Tick -- ;
	}

	/* Message HUT_IP2 rte call in can service module by rte cs interface , because HUT_IP2 is e2e message.*/

#define IPC_TX_MSG_HUT_IP3_CYCLE (500u/SWC_IPC_APPLICATION_TASK_CYCLE)

	if (0u == Object->HUT_IP3_Tick)
	{
		#if (defined SWC_IPC_PROJECT_TYPE_B03)
		(void)IPC_API_SetTxCanMsg((uint32)SWC_IPC_CAN_MSG_HUT_IP3 , SWC_IPC_NULL);
		#else
		(void)IPC_API_SetTxCanMsg((uint32)SWC_IPC_CAN_MSG_IP3 , SWC_IPC_NULL);
		#endif

		Object->HUT_IP3_Tick = IPC_TX_MSG_HUT_IP3_CYCLE;
	}
	else
	{
		Object->HUT_IP3_Tick --;
	}

#if (defined SWC_IPC_PROJECT_TYPE_P05)
#define IPC_TX_MSG_HUT_IP7_CYCLE (50u/SWC_IPC_APPLICATION_TASK_CYCLE)

	if (0u == Object->HUT_IP7_Tick)
	{
		(void)IPC_API_SetTxCanMsg((uint32)SWC_IPC_CAN_MSG_IP7 , SWC_IPC_NULL);

		Object->HUT_IP7_Tick = IPC_TX_MSG_HUT_IP7_CYCLE;
	}
	else
	{
		Object->HUT_IP7_Tick --;
	}
#endif

#if (defined SWC_IPC_PROJECT_TYPE_P05)
#define IPC_TX_MSG_HUT_IP4_CYCLE (500u/SWC_IPC_APPLICATION_TASK_CYCLE)

	if (0u == Object->HUT_IP4_Tick)
	{
		(void)IPC_API_SetTxCanMsg((uint32)SWC_IPC_CAN_MSG_IP4 , SWC_IPC_NULL);

		Object->HUT_IP4_Tick = IPC_TX_MSG_HUT_IP4_CYCLE;
	}
	else
	{
		Object->HUT_IP4_Tick --;
	}
#endif

#define IPC_TX_MSG_ACC_FD2_CYCLE ((100u/SWC_IPC_APPLICATION_TASK_CYCLE)/2)	/*Half msg periodic cycle*/
	if (0u == Object->ACC_FD2_Tick)
	{
		/*
			HUT_IP2 : IP_ACCErr
		*/
		(void)Rte_Read_piSR_E2ESwitchChangeTrigger_Element(&E2ESwitch);

		if ((uint8)SYSTEMSTATE_Cluster_ON == Object->ClusterState)
		{
			#ifndef SWC_IPC_PROJECT_TYPE_B03
            ACC_FD2_Status = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_FD2_0X2AB,
														 							  &MsgBuffer[0], (uint8)sizeof(MsgBuffer) - 8);

			if (((uint8)RTE_E_ComEx_COMEX_UPDATE_RECEIVED == ACC_FD2_Status) || ((uint8)RTE_E_ComEx_E_OK == ACC_FD2_Status))
            {
                ACC_Status = RTE_E_OK;
            }
			else
			{
				ACC_Status = RTE_E_INVALID;
			}
			#else
			if ((RTE_E_OK == Rte_Read_ACC_FD2_0x2AB_ACC_FD2_0x2AB(MsgBuffer)) && (RTE_E_OK == Rte_Read_ACC_FD3_0x2B4_ACC_FD3_0x2B4(MsgBuffer)))
			{
				ACC_Status = RTE_E_OK;
			}
			else
			{
				ACC_Status = RTE_E_INVALID;
			}
			#endif

			if ((uint8)0 == E2ESwitch)
			{
				if (RTE_E_OK == ACC_Status)
				{
					Object->u8IP_ACCErr = FALSE;
				}
				else
				{
					Object->u8IP_ACCErr = TRUE;
				}
			}
			else
			{
#define ACC_FD2_E2E_OK    			(((uint32)0<<31)|(((uint32)E2E_P01STATUS_OK & (uint32)0x7F)<<24)|((uint32)E2E_E_OK<<16)|((uint32)RTE_E_OK<<8)|(E2E_E_OK))
#define ACC_FD2_E2E_INITIAL   		(((uint32)0<<31)|(((uint32)E2E_P01STATUS_INITIAL & (uint32)0x7F)<<24)|((uint32)E2E_E_OK<<16)|((uint32)RTE_E_OK<<8)|(E2E_E_OK))
#define ACC_FD2_E2E_OK_SOME_LOST   	(((uint32)0<<31)|(((uint32)E2E_P01STATUS_OKSOMELOST & (uint32)0x7F)<<24)|((uint32)E2E_E_OK<<16)|((uint32)RTE_E_OK<<8)|(E2E_E_OK))

#define ACC_FD2_E2E_NO_NEW_DATA   	(((uint32)0<<31)|(((uint32)E2E_P01STATUS_NONEWDATA & (uint32)0x7F)<<24)|((uint32)E2E_E_OK<<16)|((uint32)RTE_E_OK<<8)|(E2E_E_OK))
#define ACC_FD2_E2E_SYNC   			(((uint32)0<<31)|(((uint32)E2E_P01STATUS_SYNC & (uint32)0x7F)<<24)|((uint32)E2E_E_OK<<16)|((uint32)RTE_E_OK<<8)|(E2E_E_OK))

				#ifndef SWC_IPC_PROJECT_TYPE_B03
				(void)Rte_Call_rpCS_SWCGateWay_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ACC7_ACC_FD2, &ACC7_E2EStatus);
				(void)Rte_Call_rpCS_SWCGateWay_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ACC3_ACC_FD2, &ACC3_E2EStatus);
				(void)Rte_Call_rpCS_SWCGateWay_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ACC4_ACC_FD2, &ACC4_E2EStatus);
				(void)Rte_Call_rpCS_SWCGateWay_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ACC6_ACC_FD2, &ACC6_E2EStatus);
				(void)Rte_Call_rpCS_SWCGateWay_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ACC8_ACC_FD2, &ACC8_E2EStatus);
				#else
				ACC7_E2EStatus = E2EPW_Read_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2(&ACC7_ACC_FD2_Data);
				ACC3_E2EStatus = E2EPW_Read_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2(&ACC3_ACC_FD2_Data);
				ACC4_E2EStatus = E2EPW_Read_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2(&ACC4_ACC_FD2_Data);
				ACC6_E2EStatus = E2EPW_Read_SG_ACC6_ACC_FD2_SG_ACC6_ACC_FD2(&ACC6_ACC_FD2_Data);
				ACC8_E2EStatus = E2EPW_Read_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2(&ACC8_ACC_FD2_Data);
				#endif

                if (1u == Object->VehicleConfig[VCONFIG_KIND_HIGHWAY_ASSIST])
                {
                    if (((ACC_FD2_E2E_OK == ACC7_E2EStatus) || (ACC_FD2_E2E_INITIAL == ACC7_E2EStatus))
                    && ((ACC_FD2_E2E_OK == ACC3_E2EStatus) || (ACC_FD2_E2E_INITIAL == ACC3_E2EStatus))
                    && ((ACC_FD2_E2E_OK == ACC4_E2EStatus) || (ACC_FD2_E2E_INITIAL == ACC4_E2EStatus))
                    && ((ACC_FD2_E2E_OK == ACC6_E2EStatus) || (ACC_FD2_E2E_INITIAL == ACC6_E2EStatus))
                    && ((ACC_FD2_E2E_OK == ACC8_E2EStatus) || (ACC_FD2_E2E_INITIAL == ACC8_E2EStatus))
                    && (RTE_E_OK == ACC_Status))
                    {
                        /*0x0:No Error*/
                        Object->u8IP_ACCErr = FALSE;
                    }
                    else if (((ACC_FD2_E2E_NO_NEW_DATA == ACC7_E2EStatus) || (ACC_FD2_E2E_SYNC == ACC7_E2EStatus) || (ACC_FD2_E2E_OK_SOME_LOST == ACC7_E2EStatus))
                        && ((ACC_FD2_E2E_NO_NEW_DATA == ACC3_E2EStatus) || (ACC_FD2_E2E_SYNC == ACC3_E2EStatus) || (ACC_FD2_E2E_OK_SOME_LOST == ACC3_E2EStatus))
                        && ((ACC_FD2_E2E_NO_NEW_DATA == ACC4_E2EStatus) || (ACC_FD2_E2E_SYNC == ACC4_E2EStatus) || (ACC_FD2_E2E_OK_SOME_LOST == ACC4_E2EStatus))
                        && ((ACC_FD2_E2E_NO_NEW_DATA == ACC6_E2EStatus) || (ACC_FD2_E2E_SYNC == ACC6_E2EStatus) || (ACC_FD2_E2E_OK_SOME_LOST == ACC6_E2EStatus))
                        && ((ACC_FD2_E2E_NO_NEW_DATA == ACC8_E2EStatus) || (ACC_FD2_E2E_SYNC == ACC8_E2EStatus) || (ACC_FD2_E2E_OK_SOME_LOST == ACC8_E2EStatus))
                        && (RTE_E_OK == ACC_Status))
                    {
                        /* Keep previous*/
                    }
                    else
                    {
                        /*0x1:Error*/
                        Object->u8IP_ACCErr = TRUE;
                    }
                }
                else
                {
                    if (((ACC_FD2_E2E_OK == ACC7_E2EStatus) || (ACC_FD2_E2E_INITIAL == ACC7_E2EStatus))
                    && ((ACC_FD2_E2E_OK == ACC3_E2EStatus) || (ACC_FD2_E2E_INITIAL == ACC3_E2EStatus))
                    && ((ACC_FD2_E2E_OK == ACC4_E2EStatus) || (ACC_FD2_E2E_INITIAL == ACC4_E2EStatus))
                    && ((ACC_FD2_E2E_OK == ACC6_E2EStatus) || (ACC_FD2_E2E_INITIAL == ACC6_E2EStatus))
                    && (RTE_E_OK == ACC_Status))
                    {
                        /*0x0:No Error*/
                        Object->u8IP_ACCErr = FALSE;
                    }
                    else if (((ACC_FD2_E2E_NO_NEW_DATA == ACC7_E2EStatus) || (ACC_FD2_E2E_SYNC == ACC7_E2EStatus) || (ACC_FD2_E2E_OK_SOME_LOST == ACC7_E2EStatus))
                        && ((ACC_FD2_E2E_NO_NEW_DATA == ACC3_E2EStatus) || (ACC_FD2_E2E_SYNC == ACC3_E2EStatus) || (ACC_FD2_E2E_OK_SOME_LOST == ACC3_E2EStatus))
                        && ((ACC_FD2_E2E_NO_NEW_DATA == ACC4_E2EStatus) || (ACC_FD2_E2E_SYNC == ACC4_E2EStatus) || (ACC_FD2_E2E_OK_SOME_LOST == ACC4_E2EStatus))
                        && ((ACC_FD2_E2E_NO_NEW_DATA == ACC6_E2EStatus) || (ACC_FD2_E2E_SYNC == ACC6_E2EStatus) || (ACC_FD2_E2E_OK_SOME_LOST == ACC6_E2EStatus))
                        && (RTE_E_OK == ACC_Status))
                    {
                        /* Keep previous*/
                    }
                    else
                    {
                        /*0x1:Error*/
                        Object->u8IP_ACCErr = TRUE;
                    }
                }
			}
		}
		else
		{
			Object->u8IP_ACCErr = FALSE;
		}

		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_ACCErr,(uint8*)&Object->u8IP_ACCErr);

		Object->ACC_FD2_Tick = IPC_TX_MSG_ACC_FD2_CYCLE;
	}
	else
	{
		Object->ACC_FD2_Tick -- ;
	}
}
/**********************************************************************************************************
*Function   : IPC_API_TxCanMsgCallback_HUT_IP1                                                            *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint8 *Date                                                                           *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-22                                                                                  *
**********************************************************************************************************/
#ifndef SWC_IPC_PROJECT_TYPE_B03
Std_ReturnType IPC_API_TxCanMsgCallback_HUT_IP1(void)
#else
Std_ReturnType IPC_API_TxCanMsgCallback_HUT_IP1(const uint8 *Data)
#endif
{
	Std_ReturnType RteReturn = RTE_E_OK;
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	uint16 Temp = 0 ;
	uint8 TempData[4] = {0};

	if (RTE_E_OK == Rte_Read_Rc_CanOutputViaGateway_IP_VehSpdDisp(&Temp))
	{
		if ((Temp != Object->u16IP_VehSpdDisp) || (FALSE == Object->HUT_IP1_Flag))
		{
			/*	moto u8 -> 16bit */
			IPC_API_FormatSignalToArray((uint32)SWC_IPC_CAN_SIGNAL_IP_VehSpdDisp,(uint64)Temp,TempData);

			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_VehSpdDisp,TempData);

			Object->u16IP_VehSpdDisp = Temp;
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	if (RTE_E_OK == Rte_Read_Rc_CanOutputViaGateway_IP_CurrTheme(TempData))
	{
		if ((TempData[0] != Object->u8IP_CurrTheme) || (FALSE == Object->HUT_IP1_Flag))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_CurrTheme,TempData);

			Object->u8IP_CurrTheme = TempData[0];
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	if (RTE_E_OK == Rte_Read_Rc_CanOutputViaGateway_IP_FuelMainTankR(&Temp))
	{
		if ((Temp != Object->u16IP_FuelMainTankR) || (FALSE == Object->HUT_IP1_Flag))
		{
			/*  moto u8 -> 10bit */
			IPC_API_FormatSignalToArray((uint32)SWC_IPC_CAN_SIGNAL_IP_FuelMainTankR,(uint64)Temp,TempData);

			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_FuelMainTankR,TempData);

			Object->u16IP_FuelMainTankR = Temp;
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	if (RTE_E_OK == Rte_Read_Rc_CanOutputViaGateway_IP_FuelAuxTankR(&Temp))
	{
		if ((Temp != Object->u16IP_FuelAuxTankR) || (FALSE == Object->HUT_IP1_Flag))
		{
			/* moto u8 -> 10bit */
			IPC_API_FormatSignalToArray((uint32)SWC_IPC_CAN_SIGNAL_IP_FuelAuxTankR,(uint64)Temp,TempData);

			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_FuelAuxTankR,TempData);

			Object->u16IP_FuelAuxTankR = Temp;
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	#if (!defined SWC_IPC_PROJECT_TYPE_D01) && (!defined SWC_IPC_PROJECT_TYPE_D02) && (!defined SWC_IPC_PROJECT_TYPE_D03)
	if (RTE_E_OK == Rte_Read_Rc_CanOutputViaGateway_IP_LagueSet(TempData))
	{
		if ((TempData[0] != Object->u8IP_LagueSet) || (FALSE == Object->HUT_IP1_Flag))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_LagueSet,TempData);

			Object->u8IP_LagueSet = TempData[0];
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}
	#endif

	if (RTE_E_OK == Rte_Read_Rc_CanOutputViaGateway_IP_VelSpdDisp_Mile(TempData))
	{
		if ((TempData[0] != Object->u8IP_VelSpdDisp_Mile) || (FALSE == Object->HUT_IP1_Flag))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_VelSpdDisp_Mile,TempData);

			Object->u8IP_VelSpdDisp_Mile = TempData[0];
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

#if (defined SWC_IPC_PROJECT_TYPE_B03)
	if (RTE_E_OK != Rte_Write_HUT_IP1_0x293_HUT_IP1_0x293(Data))
	{
		RteReturn = RTE_E_INVALID;
	}
	else
	{
		Object->HUT_IP1_Flag = TRUE;
	}
#else
	if (RTE_E_OK == RteReturn)
	{
		Object->HUT_IP1_Flag = TRUE;
	}
	else
	{
		Object->HUT_IP1_Flag = FALSE;
	}
#endif

	return RteReturn;
}

/**********************************************************************************************************
*Function   : IPC_API_TxCanMsgCallback_HUT_IP7                                                            *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                           *
*                                                                                                         *
*Return     : Std_ReturnType                                                                                        *
*                                                                                                         *
*Author     : ChenTuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-10-11                                                                                  *
**********************************************************************************************************/
#ifdef SWC_IPC_PROJECT_TYPE_P05
Std_ReturnType IPC_API_TxCanMsgCallback_HUT_IP7(void)
{
	Std_ReturnType RteReturn = RTE_E_OK;
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	uint8 Temp = 0 ;

	if (RTE_E_OK == Rte_Read_rpSR_SWCGateWay_IP_FuelAuxLvlInfo_IP_FuelAuxLvlInfo(&Temp))
	{
		if ((Temp != Object->u8IP_FuelAuxLvlInfoVar) || (FALSE == Object->HUT_IP7_Flag))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_FuelAuxLvlInfo, &Temp);

			Object->u8IP_FuelAuxLvlInfoVar = Temp;
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	if (RTE_E_OK == RteReturn)
	{
		Object->HUT_IP7_Flag = TRUE;
	}
	else
	{
		Object->HUT_IP7_Flag = FALSE;
	}

	return RteReturn;
}
#endif

/**********************************************************************************************************
*Function   : IPC_API_TxCanMsgCallback_HUT_IP4                                                            *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                           *
*                                                                                                         *
*Return     : Std_ReturnType                                                                                        *
*                                                                                                         *
*Author     :                                                                                    *
*                                                                                                         *
*Date       : 2022-02-23                                                                                  *
**********************************************************************************************************/
#ifdef SWC_IPC_PROJECT_TYPE_P05
Std_ReturnType IPC_API_TxCanMsgCallback_HUT_IP4(void)
{
	Std_ReturnType RteReturn = RTE_E_OK;
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	uint16 u16Temp = 0 ;
	uint8 Temp[4] = 0 ;

	if (RTE_E_OK == Rte_Read_rpSR_SWCGateWay_IP_AuxRemainDistance_IP_AuxRemainDistance(&u16Temp))
	{
		if ((u16Temp != Object->u16IP_AuxRemainDistance) || (FALSE == Object->HUT_IP4_Flag))
		{
			/*	moto u8 -> 16bit */
			IPC_API_FormatSignalToArray((uint32)SWC_IPC_CAN_SIGNAL_IP_AuxRemainDistance,(uint64)u16Temp,Temp);

			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_AuxRemainDistance, Temp);

			Object->u16IP_AuxRemainDistance = u16Temp;
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	if (RTE_E_OK == RteReturn)
	{
		Object->HUT_IP4_Flag = TRUE;
	}
	else
	{
		Object->HUT_IP4_Flag = FALSE;
	}

	return RteReturn;
}
#endif

/**********************************************************************************************************
*Function   : IPC_API_TxCanMsgCallback_HUT_IP2_E2E                                                        *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint8 *Date                                                                           *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-21                                                                                  *
**********************************************************************************************************/
#ifndef SWC_IPC_PROJECT_TYPE_B03
Std_ReturnType IPC_API_TxCanMsgCallback_HUT_IP2_E2E(void)
#else
Std_ReturnType IPC_API_TxCanMsgCallback_HUT_IP2_E2E(const uint8 *Data)
#endif
{
	Std_ReturnType RteReturn = RTE_E_OK;
#if (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_B03) || (defined SWC_IPC_PROJECT_TYPE_P03) || \
	(defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) || \
	(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P01)
	SG_HUT_IP2 HUT_IP2_Data = {0};
#elif (defined SWC_IPC_PROJECT_TYPE_P05)
	SG_IP2 HUT_IP2_Data = {0};
#endif
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;

	uint8 TempData[4] = {0};

	if (RTE_E_OK == Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_VehTotDistance(&HUT_IP2_Data.IP_VehTotDistance))
	{
		if ((HUT_IP2_Data.IP_VehTotDistance != Object->u32IP_VehTotDistance) || (FALSE == Object->HUT_IP2_Flag))
		{
			/* moto u8 -> 24bit*/
			IPC_API_FormatSignalToArray((uint32)SWC_IPC_CAN_SIGNAL_IP_VehTotDistance,(uint64)HUT_IP2_Data.IP_VehTotDistance,TempData);

			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_VehTotDistance,TempData);

			#ifndef SWC_IPC_PROJECT_TYPE_B03
			(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_IP_VEHTOTDISTANCE,
														   (uint8 *)&HUT_IP2_Data.IP_VehTotDistance,
														    (uint8)sizeof(HUT_IP2_Data.IP_VehTotDistance));
			#endif

			Object->u32IP_VehTotDistance = HUT_IP2_Data.IP_VehTotDistance;
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	if (RTE_E_OK == Rte_Read_Common_GateWay_Rc_CanOutputViaGateway_IP_FuelLvlInfo(&HUT_IP2_Data.IP_FuelLvlInfo))
	{
		if ((HUT_IP2_Data.IP_FuelLvlInfo != Object->u8IP_FuelLvlInfo) || (FALSE == Object->HUT_IP2_Flag))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_FuelLvlInfo,&HUT_IP2_Data.IP_FuelLvlInfo);
			#ifndef SWC_IPC_PROJECT_TYPE_B03
			(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_IP_FUELLVLINFO,
														   (uint8 *)&HUT_IP2_Data.IP_FuelLvlInfo,
														    (uint8)sizeof(HUT_IP2_Data.IP_FuelLvlInfo));
			#endif
			Object->u8IP_FuelLvlInfo = HUT_IP2_Data.IP_FuelLvlInfo;
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	HUT_IP2_Data.IP_ACCErr = Object->u8IP_ACCErr;
    #ifndef SWC_IPC_PROJECT_TYPE_B03
    (void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_IP_ACCERR,
                                                    (uint8 *)&HUT_IP2_Data.IP_ACCErr,
                                                    (uint8)sizeof(HUT_IP2_Data.IP_ACCErr));

    #endif

	if (RTE_E_OK == Rte_Read_Rc_CanOutputViaGateway_IP_VehTotDistanceValid((uint8 *)&HUT_IP2_Data.IP_VehTotDistanceValid))
	{
		if ((HUT_IP2_Data.IP_VehTotDistanceValid != Object->u8IP_VehTotDistanceValid) || (FALSE == Object->HUT_IP2_Flag))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_VehTotDistanceValid,&HUT_IP2_Data.IP_VehTotDistanceValid);
			#ifndef SWC_IPC_PROJECT_TYPE_B03
			(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_IP_VEHTOTDISTANCEVALID,
														   (uint8 *)&HUT_IP2_Data.IP_VehTotDistanceValid,
														    (uint8)sizeof(HUT_IP2_Data.IP_VehTotDistanceValid));

			#endif
			Object->u8IP_VehTotDistanceValid = HUT_IP2_Data.IP_VehTotDistanceValid;
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	if (RTE_E_OK == Rte_Read_Rc_CanOutputViaGateway_IP_FuelLvlLowLmpSts(&HUT_IP2_Data.IP_FuelLvlLowLmpSts))
	{
		if ((HUT_IP2_Data.IP_FuelLvlLowLmpSts != Object->u8IP_FuelLvlLowLmpSts) || (FALSE == Object->HUT_IP2_Flag))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_FuelLvlLowLmpSts,&HUT_IP2_Data.IP_FuelLvlLowLmpSts);
			#ifndef SWC_IPC_PROJECT_TYPE_B03
			(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_IP_FUELLVLLOWLMPSTS,
														   (uint8 *)&HUT_IP2_Data.IP_FuelLvlLowLmpSts,
														    (uint8)sizeof(HUT_IP2_Data.IP_FuelLvlLowLmpSts));
			#endif
			Object->u8IP_FuelLvlLowLmpSts = HUT_IP2_Data.IP_FuelLvlLowLmpSts;
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	if (RTE_E_OK == Rte_Read_Rc_CanOutputViaGateway_IP_BattChrgLmpSts(&HUT_IP2_Data.IP_BattChrgLmpSts))
	{
		if ((HUT_IP2_Data.IP_BattChrgLmpSts != Object->u8IP_BattChrgLmpSts) || (FALSE == Object->HUT_IP2_Flag))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_BattChrgLmpSts,&HUT_IP2_Data.IP_BattChrgLmpSts);
			#ifndef SWC_IPC_PROJECT_TYPE_B03
			(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_IP_BATTCHRGLMPSTS,
														   (uint8 *)&HUT_IP2_Data.IP_BattChrgLmpSts,
														    (uint8)sizeof(HUT_IP2_Data.IP_BattChrgLmpSts));
			#endif
			Object->u8IP_BattChrgLmpSts = HUT_IP2_Data.IP_BattChrgLmpSts;
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	if (RTE_E_OK == Rte_Read_Rc_CanOutputViaGateway_IP_EngOilPressLowLmpSts(&HUT_IP2_Data.IP_EngOilPressLowLmpSts))
	{
		if ((HUT_IP2_Data.IP_EngOilPressLowLmpSts != Object->u8IP_EngOilPressLowLmpSts) || (FALSE == Object->HUT_IP2_Flag))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_EngOilPressLowLmpSts,&HUT_IP2_Data.IP_EngOilPressLowLmpSts);
			#ifndef SWC_IPC_PROJECT_TYPE_B03
			(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_IP_ENGOILPRESSLOWLMPSTS,
														   (uint8 *)&HUT_IP2_Data.IP_EngOilPressLowLmpSts,
														    (uint8)sizeof(HUT_IP2_Data.IP_EngOilPressLowLmpSts));
			#endif
			Object->u8IP_EngOilPressLowLmpSts = HUT_IP2_Data.IP_EngOilPressLowLmpSts;
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	#if (!defined SWC_IPC_PROJECT_TYPE_P03)
	if (RTE_E_OK == Rte_Read_rpSR_SWCGateWay_CanOutput_IP_ABMWarnLmpFailrSts_Element(&HUT_IP2_Data.IP_ABMWarnLmpFailrSts))
	#endif
	{
		if ((HUT_IP2_Data.IP_ABMWarnLmpFailrSts != Object->u8IP_ABMWarnLmpFailrSts) || (FALSE == Object->HUT_IP2_Flag))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_ABMWarnLmpFailrSts,&HUT_IP2_Data.IP_ABMWarnLmpFailrSts);
			#ifndef SWC_IPC_PROJECT_TYPE_B03
			(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_IP_ABMWARNLMPFAILRSTS,
														   (uint8 *)&HUT_IP2_Data.IP_ABMWarnLmpFailrSts,
														    (uint8)sizeof(HUT_IP2_Data.IP_ABMWarnLmpFailrSts));
			#endif
			Object->u8IP_ABMWarnLmpFailrSts = HUT_IP2_Data.IP_ABMWarnLmpFailrSts;
		}
	}
	#if (!defined SWC_IPC_PROJECT_TYPE_P03)
	else
	{
		RteReturn = RTE_E_INVALID;
	}
	#endif

	if (RTE_E_OK == Rte_Read_Rc_CanOutputViaGateway_IP_VehSpdUnit((uint8 *)&HUT_IP2_Data.IP_VehSpdUnit))
	{
		if ((HUT_IP2_Data.IP_VehSpdUnit != Object->u8IP_VehSpdUnit) || (FALSE == Object->HUT_IP2_Flag))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_VehSpdUnit,&HUT_IP2_Data.IP_VehSpdUnit);
			#ifndef SWC_IPC_PROJECT_TYPE_B03
			(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_IP_VEHSPDUNIT,
														   (uint8 *)&HUT_IP2_Data.IP_VehSpdUnit,
														    (uint8)sizeof(HUT_IP2_Data.IP_VehSpdUnit));
			#endif
			Object->u8IP_VehSpdUnit = HUT_IP2_Data.IP_VehSpdUnit;
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	/*
		HUT_IP2 : IP_Err
	*/
	/* Data[1] : Tx Data*/

	if(Object->ClusterState == SYSTEMSTATE_Cluster_ON)
	{
		(void)Rte_Read_rpSR_SWCGateWay_DtcInfoForIPErrorStatus_Element(&TempData[0]);

	    if (FALSE != TempData[0])
	    {
	        /*0x1:Error*/
	        HUT_IP2_Data.IP_Err = TRUE;
	    }
	    else
	    {
	        /*0x0:No Error*/
	        HUT_IP2_Data.IP_Err = FALSE;
	    }
	}
	else
	{
		HUT_IP2_Data.IP_Err = FALSE;
	}

	if ((HUT_IP2_Data.IP_Err != Object->u8IP_Err) || (FALSE == Object->HUT_IP2_Flag))
	{
		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_Err, &HUT_IP2_Data.IP_Err);
		#ifndef SWC_IPC_PROJECT_TYPE_B03
		(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_IP_ERR,
														   (uint8 *)&HUT_IP2_Data.IP_Err,
														    (uint8)sizeof(HUT_IP2_Data.IP_Err));
		#endif
		Object->u8IP_Err = HUT_IP2_Data.IP_Err;
	}


	if (RTE_E_OK == Rte_Read_Rc_CanOutputViaGateway_IP_DrvSeatBeltWarnLmpFailSts(&HUT_IP2_Data.IP_DrvSeatBeltWarnLmpFailSts))
	{
		if ((HUT_IP2_Data.IP_DrvSeatBeltWarnLmpFailSts != Object->u8IP_DrvSeatBeltWarnLmpFailSts) || (FALSE == Object->HUT_IP2_Flag))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_DrvSeatBeltWarnLmpFailSts,&HUT_IP2_Data.IP_DrvSeatBeltWarnLmpFailSts);
			#ifndef SWC_IPC_PROJECT_TYPE_B03
			(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_IP_DRVSEATBELTWARNLMPFAILSTS,
														   (uint8 *)&HUT_IP2_Data.IP_DrvSeatBeltWarnLmpFailSts,
														    (uint8)sizeof(HUT_IP2_Data.IP_DrvSeatBeltWarnLmpFailSts));
			#endif
			Object->u8IP_DrvSeatBeltWarnLmpFailSts = HUT_IP2_Data.IP_DrvSeatBeltWarnLmpFailSts;
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	if (RTE_E_OK == Rte_Read_Rc_CanOutputViaGateway_IP_PassSeatBeltWarnLmpFailSts(&HUT_IP2_Data.IP_PassSeatBeltWarnLmpFailSts))
	{
		if ((HUT_IP2_Data.IP_PassSeatBeltWarnLmpFailSts != Object->u8IP_PassSeatBeltWarnLmpFailSts) || (FALSE == Object->HUT_IP2_Flag))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_PassSeatBeltWarnLmpFailSts,&HUT_IP2_Data.IP_PassSeatBeltWarnLmpFailSts);
			#ifndef SWC_IPC_PROJECT_TYPE_B03
			(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_IP_PASSSEATBELTWARNLMPFAILSTS,
														   (uint8 *)&HUT_IP2_Data.IP_PassSeatBeltWarnLmpFailSts,
														    (uint8)sizeof(HUT_IP2_Data.IP_PassSeatBeltWarnLmpFailSts));
			#endif
			Object->u8IP_PassSeatBeltWarnLmpFailSts = HUT_IP2_Data.IP_PassSeatBeltWarnLmpFailSts;
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	if (RTE_E_OK == Rte_Read_Rc_CanOutputViaGateway_IP_VINcompr((uint8 *)&HUT_IP2_Data.IP_VINcompr))
	{
		if ((HUT_IP2_Data.IP_VINcompr != Object->u8IP_VINcompr) || (FALSE == Object->HUT_IP2_Flag))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_VINcompr,&HUT_IP2_Data.IP_VINcompr);
			#ifndef SWC_IPC_PROJECT_TYPE_B03
			(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_IP_VINCOMPR,
														   (uint8 *)&HUT_IP2_Data.IP_VINcompr,
														    (uint8)sizeof(HUT_IP2_Data.IP_VINcompr));
			#endif
			Object->u8IP_VINcompr = HUT_IP2_Data.IP_VINcompr;
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

#define HUT_IP2_E2E_OK    ((0<<24)|(E2E_E_OK<<16)|(RTE_E_OK<<8)|(E2E_E_OK))

#if (defined SWC_IPC_PROJECT_TYPE_B03)
	if (HUT_IP2_E2E_OK != E2EPW_Write_SG_HUT_IP2_SG_HUT_IP2(&HUT_IP2_Data))
	{
		RteReturn = RTE_E_INVALID;
	}
	else
	{
		Object->HUT_IP2_Flag = TRUE;
	}
#else
	if (RTE_E_OK == RteReturn)
	{
		Object->HUT_IP2_Flag = TRUE;
	}
	else
	{
		Object->HUT_IP2_Flag = FALSE;
	}
#endif

	return RteReturn;
}
/**********************************************************************************************************
*Function   : IPC_API_TxCanMsgCallback_HUT_IP3                                                            *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint8 *Date                                                                           *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-22                                                                                  *
**********************************************************************************************************/
#ifndef SWC_IPC_PROJECT_TYPE_B03
Std_ReturnType IPC_API_TxCanMsgCallback_HUT_IP3(void)
#else
Std_ReturnType IPC_API_TxCanMsgCallback_HUT_IP3(const uint8 *Data)
#endif
{
	Std_ReturnType RteReturn = RTE_E_OK;
	/*HUT_IP3*/
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	uint32 Temp = 0 ;
	uint8 TempData[4] = {0};

	if (RTE_E_OK == Rte_Read_Rc_CanOutputViaGateway_IP_RemainDistance(&Temp))
	{
		if ((Temp != Object->u16IP_RemainDistance) || (FALSE == Object->HUT_IP3_Flag))
		{
			/* moto u8 -> 12bit*/
			IPC_API_FormatSignalToArray((uint32)SWC_IPC_CAN_SIGNAL_IP_RemainDistance,(uint64)Temp,TempData);

			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_RemainDistance,TempData);
			// #ifdef SWC_IPC_PROJECT_TYPE_B02
			// (void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_IP_REMAINDISTANCE,
			// 											   (uint8 *)&TempData[0],
			// 											    sizeof(Object->u16IP_RemainDistance));
			// #endif
			Object->u16IP_RemainDistance = (uint16)Temp;
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	if (RTE_E_OK == Rte_Read_Rc_CanOutputViaGateway_IP_InstFuelConsUnit(TempData))
	{
		if ((TempData[0] != Object->u8IP_InstFuelConsUnit) || (FALSE == Object->HUT_IP3_Flag))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_InstFuelConsUnit,TempData);
			// #ifdef SWC_IPC_PROJECT_TYPE_B02
			// (void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_IP_INSTFUELCONSUNIT,
			// 											   (uint8 *)&TempData[0],
			// 											    sizeof(Object->u8IP_InstFuelConsUnit));
			// #endif
			Object->u8IP_InstFuelConsUnit = TempData[0];
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	if (RTE_E_OK == Rte_Read_Rc_CanOutout_IP_EBDFailSts_IP_EBDFailSts(TempData))
	{
		if ((TempData[0] != Object->u8IP_EBDFailSts) || (FALSE == Object->HUT_IP3_Flag))
		{
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_EBDFailSts,TempData);
			// #ifdef SWC_IPC_PROJECT_TYPE_B02
			// (void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_IP_EBDFAILSTS,
			// 											   (uint8 *)&TempData[0],
			// 											    sizeof(Object->u8IP_EBDFailSts));
			// #endif
			Object->u8IP_EBDFailSts = TempData[0];
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	if (RTE_E_OK == Rte_Read_Rc_CanOutputViaGateway_IP_AvgFuelCons(&Temp))
	{
		if ((Temp != Object->u16IP_AvgFuelCons) || (FALSE == Object->HUT_IP3_Flag))
		{
			IPC_API_FormatSignalToArray((uint32)SWC_IPC_CAN_SIGNAL_IP_AvgFuelCons,(uint64)Temp,TempData);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_AvgFuelCons,TempData);
			// #ifdef SWC_IPC_PROJECT_TYPE_B02
			// (void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_IP_AVGFUELCONS,
			// 											   (uint8 *)&TempData[0],
			// 											    sizeof(Object->u16IP_AvgFuelCons));
			// #endif
			Object->u16IP_AvgFuelCons = (uint8)Temp;
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

	if (RTE_E_OK == Rte_Read_Rc_CanOutputViaGateway_IP_InstFuelCons(&Temp))
	{
		if ((Temp != Object->u16IP_InstFuelCons) || (FALSE == Object->HUT_IP3_Flag))
		{
			IPC_API_FormatSignalToArray((uint32)SWC_IPC_CAN_SIGNAL_IP_InstFuelCons,(uint64)Temp,TempData);
			IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_IP_InstFuelCons,TempData);
			// #ifdef SWC_IPC_PROJECT_TYPE_B02
			// (void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_IP_INSTFUELCONS,
			// 											   (uint8 *)&TempData[0],
			// 											    sizeof(Object->u16IP_InstFuelCons));
			// #endif
			Object->u16IP_InstFuelCons = (uint8)Temp;
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

#if (defined SWC_IPC_PROJECT_TYPE_B03)
	if (RTE_E_OK != Rte_Write_HUT_IP3_0x34A_HUT_IP3_0x34A(Data))
	{
		RteReturn = RTE_E_INVALID;
	}
	else
	{
		Object->HUT_IP3_Flag = TRUE;
	}
#else
	if (RTE_E_OK == RteReturn)
	{
		Object->HUT_IP3_Flag = TRUE;
	}
	else
	{
		Object->HUT_IP3_Flag = FALSE;
	}
#endif

	return RteReturn;
}
/**********************************************************************************************************
*Function   : IPC_API_TxCanMsgCallback_HUT_IP34                                                            *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint8 *Date                                                                           *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-22                                                                                  *
**********************************************************************************************************/
#ifndef SWC_IPC_PROJECT_TYPE_B03
Std_ReturnType IPC_API_TxCanMsgCallback_HUT34(void)
#else
Std_ReturnType IPC_API_TxCanMsgCallback_HUT34(const uint8 *Data)
#endif
{
	Std_ReturnType RteReturn = RTE_E_OK;
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	sint64 UTCTime = 0;
	DateTimeType_t DataTime;
	uint8 u8_TimeIndcn = 0u;
	uint32 u32_TotalSeconds = 0u;
	uint8 u8_Year_Left = 0u;
	uint8 u8_Year_Right = 0u;

	UTCTime = Rte_IRead_Common_GateWay_5msMainFunction_rpSR_SWCGateWay_ReceiveRTCTime_UtcTime();
	if (UTCTime != -1L)
	{
		if (FALSE == Object->rtcError)
		{
			(void)SWC_IPC_PRINT_DEBUG("Get rtc success, UTCTime = %d", UTCTime);
			Object->rtcError = TRUE;
		}

		if (RTE_E_OK == Rte_Call_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar(UTCTime,&DataTime))
		{
			/*0: 24H format ,  1:12H format. note:default always is 24H format*/
			if(DataTime.u8TimeMode == 0x00u)
			{
				u32_TotalSeconds = (DataTime.u8Hour * 3600u) + (DataTime.u8Minutes * 60u) + (DataTime.u8Seconds);
				/*When time >= 12 o'clock*/
				if(u32_TotalSeconds >= 43200u)
				{
					/*PM*/
					u8_TimeIndcn = 0x01u;
				}
				else
				{
					/*AM*/
					u8_TimeIndcn = 0x00u;
				}
			}
			else
			{
				/*do nothing*/
			}
			/*Get ten digit number of u16Year*/
			u8_Year_Left = (uint8)((DataTime.u16Year%100u)/10u);
			/*Get single digit number of u16Year*/
			u8_Year_Right = (uint8)(DataTime.u16Year%10u);
			/*Months accumulate from 0*/
			DataTime.u8Month = DataTime.u8Month + 1u;

			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_Time_Second,&DataTime.u8Seconds);
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_Time_Minutes,&DataTime.u8Minutes);
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_Time_Hour,&DataTime.u8Hour);
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_Time_Day,&DataTime.u8Day);
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_Time_Month,&DataTime.u8Month);
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_TimeMod,&DataTime.u8TimeMode);
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_TimeIndcn,&u8_TimeIndcn);
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_Time_Year_Left,&u8_Year_Left);
			IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_Time_Year_Right,&u8_Year_Right);
		}
	}
	else
	{
		RteReturn = RTE_E_INVALID;
	}

#if (defined SWC_IPC_PROJECT_TYPE_B03)
	if (RTE_E_OK != Rte_Write_HUT34_0x370_HUT34_0x370(Data))
	{
		RteReturn = RTE_E_INVALID;
	}
	else
	{
		//do nothing
	}
#endif
	return RteReturn;
}



/**********************************************************************************************************
*Function   : IPC_API_TxCanMsgCallback_HUT32_E2E                                                          *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint8 *Date                                                                           *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-12-01                                                                                  *
**********************************************************************************************************/
#ifndef SWC_IPC_PROJECT_TYPE_B03
Std_ReturnType IPC_API_TxCanMsgCallback_HUT32_E2E(void)
#else
Std_ReturnType IPC_API_TxCanMsgCallback_HUT32_E2E(const uint8 *Data)
#endif
{
	Std_ReturnType RteReturn = RTE_E_OK;
	/*HUT32*/
	// SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	SG_HUT32 HUT32Data = {0};
	uint8 TempData[2] = {0};
	#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02)
	uint8 HUT32_P2P_PrkgDirSwtReq = 0U;
	#endif

	#if (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
	uint8 HUT32_LCMode_Swt_Req = 0u;
	uint8 HUT32_RainMode_Swt_Req = 0u;
	#endif

	#if (defined SWC_IPC_PROJECT_TYPE_P02)|| (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) \
		|| (defined SWC_IPC_PROJECT_TYPE_D03)
	uint8 HUT32_NavDecSwtReq = 0u;
	#endif

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ContnPrkgReq, &HUT32Data.ContnPrkgReq);
    #ifndef SWC_IPC_PROJECT_TYPE_B03
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_CONTNPRKGREQ,
														   (uint8 *)&HUT32Data.ContnPrkgReq,
														    (uint8)sizeof(HUT32Data.ContnPrkgReq));
    #endif

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ContnPrkgReqValid, &HUT32Data.ContnPrkgReqValid);
    #ifndef SWC_IPC_PROJECT_TYPE_B03
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_CONTNPRKGREQVALID,
														   (uint8 *)&HUT32Data.ContnPrkgReqValid,
														    (uint8)sizeof(HUT32Data.ContnPrkgReqValid));
    #endif

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DetVideoLost, &HUT32Data.DetVideoLost);
    #ifndef SWC_IPC_PROJECT_TYPE_B03
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_DETVIDEOLOST,
														   (uint8 *)&HUT32Data.DetVideoLost,
														    (uint8)sizeof(HUT32Data.DetVideoLost));
    #endif

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PrkStraightContinueReq_HUT, &HUT32Data.PrkStraightContinueReq_HUT);
    #ifndef SWC_IPC_PROJECT_TYPE_B03
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_PRKSTRAIGHTCONTINUEREQ_HUT,
														   (uint8 *)&HUT32Data.PrkStraightContinueReq_HUT,
														    (uint8)sizeof(HUT32Data.PrkStraightContinueReq_HUT));
    #endif

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PrkStraightModSel_HUT, &HUT32Data.PrkStraightModSel_HUT);
    #ifndef SWC_IPC_PROJECT_TYPE_B03
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_PRKSTRAIGHTMODSEL_HUT,
														   (uint8 *)&HUT32Data.PrkStraightModSel_HUT,
														    (uint8)sizeof(HUT32Data.PrkStraightModSel_HUT));
    #endif

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PrkStraightStrtReq_HUT, &HUT32Data.PrkStraightStrtReq_HUT);
    #ifndef SWC_IPC_PROJECT_TYPE_B03
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_PRKSTRAIGHTSTRTREQ_HUT,
														   (uint8 *)&HUT32Data.PrkStraightStrtReq_HUT,
														    (uint8)sizeof(HUT32Data.PrkStraightStrtReq_HUT));
    #endif

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PrkStraightSts_HUT, &HUT32Data.PrkStraightSts_HUT);
    #ifndef SWC_IPC_PROJECT_TYPE_B03
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_PRKSTRAIGHTSTS_HUT,
														   (uint8 *)&HUT32Data.PrkStraightSts_HUT,
														    (uint8)sizeof(HUT32Data.PrkStraightSts_HUT));
    #endif

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PrkStraightSuspendOrFinishReq_HUT, &HUT32Data.PrkStraightSuspendOrFinishReq_HUT);
    #ifndef SWC_IPC_PROJECT_TYPE_B03
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_PRKSTRAIGHTSUSPENDORFINISHREQ_HUT,
														   (uint8 *)&HUT32Data.PrkStraightSuspendOrFinishReq_HUT,
														    (uint8)sizeof(HUT32Data.PrkStraightSuspendOrFinishReq_HUT));
    #endif

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PrkStraightSwtReq_HUT, &HUT32Data.PrkStraightSwtReq_HUT);
    #ifndef SWC_IPC_PROJECT_TYPE_B03
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_PRKSTRAIGHTSWTREQ_HUT,
														   (uint8 *)&HUT32Data.PrkStraightSwtReq_HUT,
														    (uint8)sizeof(HUT32Data.PrkStraightSwtReq_HUT));
    #endif

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PrkStraightVehStrtReq_HUT_Valid, &HUT32Data.PrkStraightVehStrtReq_HUT_Valid);
    #ifndef SWC_IPC_PROJECT_TYPE_B03
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_PRKSTRAIGHTVEHSTRTREQ_HUT_VALID,
															   (uint8 *)&HUT32Data.PrkStraightVehStrtReq_HUT_Valid,
																(uint8)sizeof(HUT32Data.PrkStraightVehStrtReq_HUT_Valid));
    #endif

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PrkgCtrlModReq, &HUT32Data.PrkgCtrlModReq);
    #ifndef SWC_IPC_PROJECT_TYPE_B03
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_PRKGCTRLMODREQ,
														   (uint8 *)&HUT32Data.PrkgCtrlModReq,
														    (uint8)sizeof(HUT32Data.PrkgCtrlModReq));
    #endif

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PrkgCtrlModReqValid, &HUT32Data.PrkgCtrlModReqValid);
    #ifndef SWC_IPC_PROJECT_TYPE_B03
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_PRKGCTRLMODREQVALID,
														   (uint8 *)&HUT32Data.PrkgCtrlModReqValid,
														    (uint8)sizeof(HUT32Data.PrkgCtrlModReqValid));
    #endif

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ScrnOpSts, &HUT32Data.ScrnOpSts);
    #ifndef SWC_IPC_PROJECT_TYPE_B03
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_SCRNOPSTS,
															   (uint8 *)&HUT32Data.ScrnOpSts,
																(uint8)sizeof(HUT32Data.ScrnOpSts));
    #endif

	#if (defined SWC_IPC_PROJECT_TYPE_B03)
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_VolLampDispSts, &HUT32Data.VolLampDispSts);
	#elif (defined SWC_IPC_PROJECT_TYPE_B02) || (defined SWC_IPC_PROJECT_TYPE_A07)
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_VolLampDispSts, &HUT32Data.VolLampDispSts);
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_VOLLAMPDISPSTS,
														   (uint8 *)&HUT32Data.VolLampDispSts,
														    (uint8)sizeof(HUT32Data.VolLampDispSts));
	#endif

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_XLvl, &TempData[0]);
	HUT32Data.XLvl = (uint16)(((uint16)TempData[0] << (uint16)8) | ((uint16)TempData[1]));
    #ifndef SWC_IPC_PROJECT_TYPE_B03
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_XLVL,
														   (uint8 *)&HUT32Data.XLvl,
														    (uint8)sizeof(HUT32Data.XLvl));
    #endif

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_YLvl, &TempData[0]);
	HUT32Data.YLvl = (uint16)(((uint16)TempData[0] << (uint16)8) | ((uint16)TempData[1]));
    #ifndef SWC_IPC_PROJECT_TYPE_B03
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_YLVL,
														   (uint8 *)&HUT32Data.YLvl,
														    (uint8)sizeof(HUT32Data.YLvl));
    #endif

 	#if (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P02)
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LCMode_Swt_Req, &HUT32_LCMode_Swt_Req);
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_LCMODE_SWT_REQ,
														   (uint8 *)&HUT32_LCMode_Swt_Req,
														    (uint8)sizeof(HUT32_LCMode_Swt_Req));

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RainMode_Swt_Req, &HUT32_RainMode_Swt_Req);
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_RAINMODE_SWT_REQ,
														   (uint8 *)&HUT32_RainMode_Swt_Req,
														    (uint8)sizeof(HUT32_RainMode_Swt_Req));
    #endif

	#if (defined SWC_IPC_PROJECT_TYPE_P05) || (defined SWC_IPC_PROJECT_TYPE_P02)
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_P2P_PrkgDirSwtReq, &HUT32_P2P_PrkgDirSwtReq);
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_P2P_PRKGDIRSWTREQ,
														   (uint8 *)&HUT32_P2P_PrkgDirSwtReq,
														    (uint8)sizeof(HUT32_P2P_PrkgDirSwtReq));
	#endif

	#if (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02) \
		|| (defined SWC_IPC_PROJECT_TYPE_D03)
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_NavDecSwtReq, &HUT32_NavDecSwtReq);
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_NAVDECSWTREQ,
														   (uint8 *)&HUT32_NavDecSwtReq,
														    (uint8)sizeof(HUT32_NavDecSwtReq));
	#endif

#ifdef SWC_IPC_PROJECT_TYPE_B03
#define HUT32_E2E_OK    ((0<<24)|(E2E_E_OK<<16)|(RTE_E_OK<<8)|(E2E_E_OK))
	if (HUT32_E2E_OK != E2EPW_Write_SG_HUT32_SG_HUT32(&HUT32Data))
	{
		RteReturn = RTE_E_INVALID;
	}
#endif

	return RteReturn;
}

/**********************************************************************************************************
*Function   : IPC_API_TxCanMsgCallback_DMS_FD1_E2E                                                        *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Huangcy                                                                                     *
*                                                                                                         *
*Date       : 2021-07-02                                                                                  *
**********************************************************************************************************/
#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)  || \
	(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
void IPC_API_TxCanMsgCallback_DMS_FD1_E2E(void)
{
	/* The following signals do not belong to E2E*/
	uint8 DMS_FD1_DrowsnsLvl;
	uint8 DMS_FD1_DrowsnsLvlQlty;
	uint8 DMS_FD1_ExprsnSts;
	uint8 DMS_FD1_GenderSts;
	uint8 DMS_FD1_GenderStsQlty;
	uint16 DMS_FD1_GazePosnX;
	uint16 DMS_FD1_GazePosnY;
	uint16 DMS_FD1_GazePosnZ;
	uint8 DMS_FD1_GazePosnX_CONVER[2];
	uint8 DMS_FD1_GazePosnY_CONVER[2];
	uint8 DMS_FD1_GazePosnZ_CONVER[2];

	uint8 DMS6_DMS_FD1_DrvBehvSts;
	uint8 DMS6_DMS_FD1_LEyeOpenSts;
	uint8 DMS6_DMS_FD1_LEyeOpenStsQlty;
	uint8 DMS6_DMS_FD1_REyeOpenSts;
	uint8 DMS6_DMS_FD1_REyeOpenStsQlty;
	uint8 DMS6_DMS_FD1_RobustGazeYawAng;
	uint8 DMS6_DMS_FD1_RobustGazePitchAng;
	uint8 DMS6_DMS_FD1_RobustGazeAngQlty;

	uint8 DMS5_DMS_FD1_DMSSts;
	uint8 DMS5_DMS_FD1_HeadDetn;
	uint8 DMS5_DMS_FD1_HeadYawAng;
	uint8 DMS5_DMS_FD1_HeadPitchAng;
	uint8 DMS5_DMS_FD1_HeadRollAng;
	uint8 DMS5_DMS_FD1_HeadRotAngQlty;

	uint16 DMS3_DMS_FD1_HeadPosnX;
	uint16 DMS3_DMS_FD1_HeadPosnY;
	uint16 DMS3_DMS_FD1_HeadPosnZ;
	uint8 DMS3_DMS_FD1_HeadPosnX_CONVER[2];
	uint8 DMS3_DMS_FD1_HeadPosnY_CONVER[2];
	uint8 DMS3_DMS_FD1_HeadPosnZ_CONVER[2];
	uint8 DMS3_DMS_FD1_HeadPosQlty;

	uint8 DMS2_DMS_FD1_DistrctnLvl_ACC;
	uint8 DMS2_DMS_FD1_DistrctnLvlQlty_ACC;
	uint8 DMS2_DMS_FD1_DrowsnsLvl_ACC;
	uint8 DMS2_DMS_FD1_DrowsnsLvlQlty_ACC;

	/* adapt signals which do not belong to E2E */
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrowsnsLvl, &DMS_FD1_DrowsnsLvl);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrowsnsLvlQlty, &DMS_FD1_DrowsnsLvlQlty);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ExprsnSts, &DMS_FD1_ExprsnSts);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_GenderSts, &DMS_FD1_GenderSts);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_GenderStsQlty, &DMS_FD1_GenderStsQlty);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_GazePosnX, &DMS_FD1_GazePosnX_CONVER);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_GazePosnY, &DMS_FD1_GazePosnY_CONVER);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_GazePosnZ, &DMS_FD1_GazePosnZ_CONVER);
	DMS_FD1_GazePosnX = (uint16)((DMS_FD1_GazePosnX_CONVER[0] << 8) | (DMS_FD1_GazePosnX_CONVER[1]));
	DMS_FD1_GazePosnY = (uint16)((DMS_FD1_GazePosnY_CONVER[0] << 8) | (DMS_FD1_GazePosnY_CONVER[1]));
	DMS_FD1_GazePosnZ = (uint16)((DMS_FD1_GazePosnZ_CONVER[0] << 8) | (DMS_FD1_GazePosnZ_CONVER[1]));

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvBehvSts, &DMS6_DMS_FD1_DrvBehvSts);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LEyeOpenSts, &DMS6_DMS_FD1_LEyeOpenSts);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LEyeOpenStsQlty, &DMS6_DMS_FD1_LEyeOpenStsQlty);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_REyeOpenSts, &DMS6_DMS_FD1_REyeOpenSts);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_REyeOpenStsQlty, &DMS6_DMS_FD1_REyeOpenStsQlty);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RobustGazeYawAng, &DMS6_DMS_FD1_RobustGazeYawAng);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RobustGazePitchAng, &DMS6_DMS_FD1_RobustGazePitchAng);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RobustGazeAngQlty, &DMS6_DMS_FD1_RobustGazeAngQlty);

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DMSSts, &DMS5_DMS_FD1_DMSSts);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HeadDetn, &DMS5_DMS_FD1_HeadDetn);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HeadYawAng, &DMS5_DMS_FD1_HeadYawAng);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HeadPitchAng, &DMS5_DMS_FD1_HeadPitchAng);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HeadRollAng, &DMS5_DMS_FD1_HeadRollAng);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HeadRotAngQlty, &DMS5_DMS_FD1_HeadRotAngQlty);

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HeadPosnX, &DMS3_DMS_FD1_HeadPosnX_CONVER);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HeadPosnY, &DMS3_DMS_FD1_HeadPosnY_CONVER);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HeadPosnZ, &DMS3_DMS_FD1_HeadPosnZ_CONVER);
	DMS3_DMS_FD1_HeadPosnX = (uint16)((DMS3_DMS_FD1_HeadPosnX_CONVER[0] << 8) | (DMS3_DMS_FD1_HeadPosnX_CONVER[1]));
	DMS3_DMS_FD1_HeadPosnY = (uint16)((DMS3_DMS_FD1_HeadPosnY_CONVER[0] << 8) | (DMS3_DMS_FD1_HeadPosnY_CONVER[1]));
	DMS3_DMS_FD1_HeadPosnZ = (uint16)((DMS3_DMS_FD1_HeadPosnZ_CONVER[0] << 8) | (DMS3_DMS_FD1_HeadPosnZ_CONVER[1]));
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HeadPosQlty, &DMS3_DMS_FD1_HeadPosQlty);

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DistrctnLvl_ACC, &DMS2_DMS_FD1_DistrctnLvl_ACC);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DistrctnLvlQlty_ACC, &DMS2_DMS_FD1_DistrctnLvlQlty_ACC);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrowsnsLvl_ACC, &DMS2_DMS_FD1_DrowsnsLvl_ACC);
	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrowsnsLvlQlty_ACC, &DMS2_DMS_FD1_DrowsnsLvlQlty_ACC);


	/* The following signals do not belong to E2E */
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_DROWSNSLVL,
														   (uint8 *)&DMS_FD1_DrowsnsLvl,
														    sizeof(DMS_FD1_DrowsnsLvl));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_GAZEPOSNX,
														   (uint8 *)&DMS_FD1_GazePosnX,
														    sizeof(DMS_FD1_GazePosnX));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_GAZEPOSNY,
														   (uint8 *)&DMS_FD1_GazePosnY,
														    sizeof(DMS_FD1_GazePosnY));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_GAZEPOSNZ,
														   (uint8 *)&DMS_FD1_GazePosnZ,
														    sizeof(DMS_FD1_GazePosnZ));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_EXPRSNSTS,
														   (uint8 *)&DMS_FD1_ExprsnSts,
														    sizeof(DMS_FD1_ExprsnSts));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_GENDERSTSQLTY,
														   (uint8 *)&DMS_FD1_GenderStsQlty,
														    sizeof(DMS_FD1_GenderStsQlty));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_GENDERSTS,
														   (uint8 *)&DMS_FD1_GenderSts,
														    sizeof(DMS_FD1_GenderSts));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_DROWSNSLVLQLTY,
														   (uint8 *)&DMS_FD1_DrowsnsLvlQlty,
														    sizeof(DMS_FD1_DrowsnsLvlQlty));

	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_DRVBEHVSTS,
														   (uint8 *)&DMS6_DMS_FD1_DrvBehvSts,
														   	sizeof(DMS6_DMS_FD1_DrvBehvSts));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_LEYEOPENSTS,
														   (uint8 *)&DMS6_DMS_FD1_LEyeOpenSts,
														   	sizeof(DMS6_DMS_FD1_LEyeOpenSts));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_LEYEOPENSTSQLTY,
														   (uint8 *)&DMS6_DMS_FD1_LEyeOpenStsQlty,
														   	sizeof(DMS6_DMS_FD1_LEyeOpenStsQlty));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_REYEOPENSTS,
														   (uint8 *)&DMS6_DMS_FD1_REyeOpenSts,
														   	sizeof(DMS6_DMS_FD1_REyeOpenSts));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_REYEOPENSTSQLTY,
														   (uint8 *)&DMS6_DMS_FD1_REyeOpenStsQlty,
														   	sizeof(DMS6_DMS_FD1_REyeOpenStsQlty));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_ROBUSTGAZEYAWANG,
														   (uint8 *)&DMS6_DMS_FD1_RobustGazeYawAng,
														   	sizeof(DMS6_DMS_FD1_RobustGazeYawAng));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_ROBUSTGAZEPITCHANG,
														   (uint8 *)&DMS6_DMS_FD1_RobustGazePitchAng,
														   	sizeof(DMS6_DMS_FD1_RobustGazePitchAng));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_ROBUSTGAZEANGQLTY,
														   (uint8 *)&DMS6_DMS_FD1_RobustGazeAngQlty,
														   	sizeof(DMS6_DMS_FD1_RobustGazeAngQlty));

	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_DMSSTS,
														   (uint8 *)&DMS5_DMS_FD1_DMSSts,
														   	sizeof(DMS5_DMS_FD1_DMSSts));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_HEADDETN,
														   (uint8 *)&DMS5_DMS_FD1_HeadDetn,
														   	sizeof(DMS5_DMS_FD1_HeadDetn));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_HEADYAWANG,
														   (uint8 *)&DMS5_DMS_FD1_HeadYawAng,
														   	sizeof(DMS5_DMS_FD1_HeadYawAng));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_HEADPITCHANG,
														   (uint8 *)&DMS5_DMS_FD1_HeadPitchAng,
														   	sizeof(DMS5_DMS_FD1_HeadPitchAng));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_HEADROLLANG,
														   (uint8 *)&DMS5_DMS_FD1_HeadRollAng,
														   	sizeof(DMS5_DMS_FD1_HeadRollAng));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_HEADROTANGQLTY,
														   (uint8 *)&DMS5_DMS_FD1_HeadRotAngQlty,
														   	sizeof(DMS5_DMS_FD1_HeadRotAngQlty));

	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_HEADPOSNX,
														   (uint8 *)&DMS3_DMS_FD1_HeadPosnX,
														   	sizeof(DMS3_DMS_FD1_HeadPosnX));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_HEADPOSNY,
														   (uint8 *)&DMS3_DMS_FD1_HeadPosnY,
														   	sizeof(DMS3_DMS_FD1_HeadPosnY));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_HEADPOSNZ,
														   (uint8 *)&DMS3_DMS_FD1_HeadPosnZ,
														   	sizeof(DMS3_DMS_FD1_HeadPosnZ));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_HEADPOSQLTY,
														   (uint8 *)&DMS3_DMS_FD1_HeadPosQlty,
														   	sizeof(DMS3_DMS_FD1_HeadPosQlty));

	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_DISTRCTNLVL_ACC,
														   (uint8 *)&DMS2_DMS_FD1_DistrctnLvl_ACC,
														   	sizeof(DMS2_DMS_FD1_DistrctnLvl_ACC));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_DISTRCTNLVLQLTY_ACC,
														   (uint8 *)&DMS2_DMS_FD1_DistrctnLvlQlty_ACC,
														   	sizeof(DMS2_DMS_FD1_DistrctnLvlQlty_ACC));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_DROWSNSLVL_ACC,
														   (uint8 *)&DMS2_DMS_FD1_DrowsnsLvl_ACC,
														   	sizeof(DMS2_DMS_FD1_DrowsnsLvl_ACC));
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(COMEX_SIGNAL_TX_DROWSNSLVLQLTY_ACC,
														   (uint8 *)&DMS2_DMS_FD1_DrowsnsLvlQlty_ACC,
														   	sizeof(DMS2_DMS_FD1_DrowsnsLvlQlty_ACC));
}
#endif

/**********************************************************************************************************
*Function   : IPC_ClusterFuelTCDataUpdate                                                                 *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-16                                                                                  *
**********************************************************************************************************/
static void IPC_ClusterFuelAndTcDataUpdate(SWC_IPC_AppMsgObject * Object)
{
#define IPC_CLUSTER_FUEL_TC_DATA_UPDATE_CYCLE (500u/SWC_IPC_APPLICATION_TASK_CYCLE)
	FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE *FuelData;
	TC_MODULE_OUTPUT_DATA_STRUCT_RTE *TcData;
	SWC_IPC_FuelTCDataUpload FuelAndTcData;
	IPC_M2S_EngineerIVIReadInfoResponse_t MsgBuffer;

	if (FALSE != Object->FuelAndTcSwitch)
	{
		if (Object->FuelAndTcTick == 0)
		{
			FuelData = Rte_IRead_Common_GateWay_5msMainFunction_rpSR_SWCGateWay_Fuel_Set_Module_Data_Element();
			TcData = Rte_IRead_Common_GateWay_5msMainFunction_rpSR_SWCGateWay_TC_Module_Output_Data_Element();

			FuelAndTcData.FuelDisplayPercent = (uint16)FuelData->Fuel_Level_Display_Percent;
			#ifndef SWC_IPC_PROJECT_TYPE_B03
			FuelAndTcData.FuelDisplayValue = FuelData->Fuel_Level_Display_Value;
			#else
			FuelAndTcData.FuelDisplayValue = (uint16)FuelData->Fuel_Level_Display_Value;
			#endif
			FuelAndTcData.FuelSensorRawValueA = (uint16)FuelData->Fuel_Sensor_Raw_Value_A;
			FuelAndTcData.FuelSensorRawValueB = (uint16)FuelData->Fuel_Sensor_Raw_Value_B;
			FuelAndTcData.AfeDisplay = (uint16)TcData->u16AFE_2st_Display_Output_Data;
			FuelAndTcData.DteFuelStageConsumption = (uint16)TcData->u8DTE_Fuel_Stage_Consumption;
			FuelAndTcData.DteDisplay = (uint16)TcData->u16DTE_Display_Output_Data;
			FuelAndTcData.DteCalculate = (uint16)TcData->u16DTE_Calculate_Output_Data;

			if ((FALSE != memcmp(&FuelAndTcData , &Object->FuelAndTcData , sizeof(SWC_IPC_FuelTCDataUpload)))
				|| (Object->FuelAndTcTick == 0))
			{
				(void)memset(&MsgBuffer , 0 , sizeof(IPC_M2S_EngineerIVIReadInfoResponse_t));
				MsgBuffer.ModuleId = 0x1;
				MsgBuffer.InfoId = 0xEA15;
				#ifndef SWC_IPC_PROJECT_TYPE_B03
				MsgBuffer.DataLength = 0x12u;
				#else
				MsgBuffer.DataLength = sizeof(SWC_IPC_FuelTCDataUpload);
				#endif
				MsgBuffer.Result = 0;
				(void)memcpy(&MsgBuffer.Data , (uint8 *)&FuelAndTcData, sizeof(SWC_IPC_FuelTCDataUpload));

				IPC_API_AppMsgTransmit((uint8)M2S_READ_ENGINEER_INFO_RESP,
									(uint8 *)&MsgBuffer,
									(uint16)sizeof(IPC_M2S_EngineerIVIReadInfoResponse_t), TRUE);
				Object->FuelAndTcData = FuelAndTcData;
				Object->FuelAndTcTick = IPC_CLUSTER_FUEL_TC_DATA_UPDATE_CYCLE;
			}
		}
		else
		{
			Object->FuelAndTcTick -=1 ;
		}
	}
	else
	{
		Object->FuelAndTcTick = 0;
	}
}
/**********************************************************************************************************
*Function   : IPC_LinkTestUpdate                                                                          *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-16                                                                                  *
**********************************************************************************************************/
static void IPC_LinkTestUpdate(SWC_IPC_AppMsgObject * Object)
{
	IPC_M2S_ClusterAppSystemIPCDebugTest_t LinkTestMsg;
#define IPC_LINK_TEST_CYCLE (1000u/SWC_IPC_APPLICATION_TASK_CYCLE)

	if (Object->LinkTestTick == 0)
	{
		if (0u == Object->LinkTest)
		{
			Object->LinkTest = 1u;
		}
		else
		{
			Object->LinkTest = 0u;
		}

		LinkTestMsg.Status = Object->LinkTest;

		IPC_API_AppMsgTransmit((uint8)M2S_IPC_LINK_TEST,(uint8 *)&LinkTestMsg,(uint16)sizeof(LinkTestMsg),TRUE);

		Object->LinkTestTick = IPC_LINK_TEST_CYCLE;
	}
	else
	{
		Object->LinkTestTick -= 1 ;
	}
}
/**********************************************************************************************************
*Function   : IPC_ClusterSafetyRollingCounterUpdate                                                       *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-05                                                                                  *
**********************************************************************************************************/
static void IPC_ClusterSafetyRollingCounterUpdate(SWC_IPC_AppMsgObject * Object)
{
	IPC_M2S_SAFETYMANAGEMENTSafetyAlive_t RcMsg;
#define IPC_CLUSTER_SAFETY_ALIVE_CYCLE (100u/SWC_IPC_APPLICATION_TASK_CYCLE)

	if (Object->ClusterSafetyRcTick == 0)
	{
		RcMsg.RollingCounter = Object->ClusterSafetyRc;

		IPC_API_AppMsgTransmit((uint8)M2S_SAFETY_APP_RC,(uint8 *)&RcMsg,(uint16)sizeof(RcMsg),TRUE);

		Object->ClusterSafetyRc ++;

		Object->ClusterSafetyRcTick = IPC_CLUSTER_SAFETY_ALIVE_CYCLE;
	}
	else
	{
		Object->ClusterSafetyRcTick -=1 ;
	}
}
/**********************************************************************************************************
*Function   : IPC_ControlDTCMonitor                                                                       *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-16                                                                                  *
**********************************************************************************************************/
static void IPC_ControlDTCMonitor(SWC_IPC_AppMsgObject * Object)
{
	uint8 Result = 0;
	/*---------------------------------------------------------------------------------------------------*/
	/*
		Clear DTC Information
	*/
#define IPC_CLEAR_DTC_OK		    (0x0)
#define IPC_CLEAR_DTC_PENDING	    (0x1)
#define IPC_CLEAR_DTC_ERROR		    (0x2)
#define IPC_CLEAR_DTC_DEFAULT	    (0xF)

#define CLEAR_DTC_ERROR_REPEAT_TIME	(0x3)
#define IPC_RESTORE_CAN_TIME_OUT_DELAY (30000u/SWC_IPC_APPLICATION_TASK_CYCLE)

	if (SWC_IPC_TRIGGERED == Object->ClearDtcSwitch)
	{
		(void)Rte_Call_rpCS_AppClearDTCInfo_AppClearDTCInfo((uint8)0, &Result);

		Object->ClearDtcTick = 0;

		SWC_IPC_PRINT_INFO("Clear DTC information work start!");

		Object->ClearDtcSwitch = SWC_IPC_RUNNING;
	}
	else if (SWC_IPC_RUNNING == Object->ClearDtcSwitch)
	{
		(void)Rte_Call_rpCS_AppClearDTCInfo_AppClearDTCInfo((uint8)1, &Result);

		if (IPC_CLEAR_DTC_OK == Result)
		{
			Object->ClearDtcSwitch = SWC_IPC_DONE;
		}
		else if (IPC_CLEAR_DTC_ERROR == Result)
		{
			if (Object->ClearDtcRepeatCount <= CLEAR_DTC_ERROR_REPEAT_TIME)
			{
				Object->ClearDtcRepeatCount ++;
				SWC_IPC_PRINT_ERROR("Clear DTC information error! retry counts:%d , spend time:%dms",
					                Object->ClearDtcRepeatCount,Object->ClearDtcTick);

				Object->ClearDtcSwitch = SWC_IPC_TRIGGERED;
			}
			else
			{
				SWC_IPC_PRINT_ERROR("Clear DTC information error! process abandon! retry counts:%d , spend time:%dms",
					                Object->ClearDtcRepeatCount,Object->ClearDtcTick);
				Object->ClearDtcRepeatCount = 0;
				Object->ClearDtcTick = 0;
				Object->ClearDtcSwitch = SWC_IPC_CLEAR;
			}
		}
		else if (IPC_CLEAR_DTC_PENDING == Result)
		{
			/*Keep previous*/
		}
		else
		{
			Object->ClearDtcRepeatCount = 0;
			Object->ClearDtcTick = 0;
			SWC_IPC_PRINT_ERROR("Clear DTC information return error! Result = %d",Result);
			Object->ClearDtcSwitch = SWC_IPC_CLEAR;
		}

		if (Object->ClearDtcTick >= IPC_RESTORE_CAN_TIME_OUT_DELAY)
		{
			Object->ClearDtcRepeatCount = 0;
			Object->ClearDtcTick = 0;

			SWC_IPC_PRINT_ERROR("Clear DTC information work timeout! process abandon!");
			Object->ClearDtcSwitch = SWC_IPC_CLEAR;
		}
		else
		{
			Object->ClearDtcTick ++;
		}
	}
	else if (SWC_IPC_DONE == Object->ClearDtcSwitch)
	{
		SWC_IPC_PRINT_INFO("Clear DTC information work done! Spend time: %dms",Object->ClearDtcTick * SWC_IPC_APPLICATION_TASK_CYCLE);

		/*Clear dtc switch when it done in next task cycle*/
		Object->ClearDtcRepeatCount = 0;
		Object->ClearDtcTick = 0;
		Object->ClearDtcSwitch = SWC_IPC_CLEAR;
		}
	else
	{
		Object->ClearDtcRepeatCount = 0;
		Object->ClearDtcTick = 0;
		Object->ClearDtcSwitch = SWC_IPC_CLEAR;
	}

	/*---------------------------------------------------------------------------------------------------*/
	/*
		Read DTC Information
	*/
#define IPC_READ_DTC_INFORMATION_REPEAT_CYCLE (2000u/SWC_IPC_APPLICATION_TASK_CYCLE)

	if (Object->ReadDtcGroupMask != 0)
	{
		if (Object->ReadDtcTick >= IPC_READ_DTC_INFORMATION_REPEAT_CYCLE)
		{
			Object->ReadDtcGroupMask = 0;
			Object->ReadDtcTick = 0;
			SWC_IPC_PRINT_WARNING("Read DTC information group interval timeout! refresh DTC information!");
		}
		else
		{
			Object->ReadDtcTick +=1 ;
		}
	}
	else
	{
		Object->ReadDtcTick = 0;
	}
	/*---------------------------------------------------------------------------------------------------*/
}
/**********************************************************************************************************
*Function   : IPC_ReadDTCInfo                                                                             *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-16                                                                                  *
**********************************************************************************************************/
static void IPC_ReadDTCInfo(uint8 GroupIndex , SWC_IPC_AppMsgObject * Object)
{
	if (GroupIndex < (sizeof(Object->DtcInfomation)/100))
	{
		if ((0 == Object->ReadDtcGroupMask) || (0 != (((uint16)((uint16)2 << (uint16)GroupIndex)) & Object->ReadDtcGroupMask)))
		{
			Rte_Call_rpCS_AppReadDtcInfomation_AppReadDtcInformation(Object->DtcInfomation);
			/*Clear mask*/
			Object->ReadDtcGroupMask = 0;
		}

		Object->ReadDtcGroupMask |= (uint16)((uint16)2 << (uint16)GroupIndex);
	}
}

/**********************************************************************************************************
*Function   : IPC_API_ReadDriveModeSwitchCallback                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-08                                                                                  *
**********************************************************************************************************/
void IPC_API_ReadEngineerInfoCallback(uint8 *Data)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	IPC_S2M_EngineerIVIReadInfoRequest_t *Req = (IPC_S2M_EngineerIVIReadInfoRequest_t *)Data;
	IPC_M2S_EngineerIVIReadInfoResponse_t Resp;
	uint8* Source = SWC_IPC_NULL;
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;

	SWC_IPC_PRINT_INFO("Read engineer information request from ivi-hal: ModuleId = %d , InfoId = 0x%X",
		               Req->ModuleId, Req->InfoId);

	Resp.ModuleId = Req->ModuleId;
	Resp.InfoId = Req->InfoId;
	Resp.DataLength = 0;
	Resp.Result = 1; /*Default , 1 is read faild*/
	(void)memset(Resp.Data , 0 , sizeof(Resp.Data));

	if (0x01 == Req->ModuleId)
	{
		switch (Req->InfoId)
		{
			case 0xEA01:/* Part number */
				{
					SWC_IPC_PRINT_INFO("0xEA01 = Part number");
					(void)Rte_Read_EOL_PartNumber_0xF187_PartNumber_0xF187(Object->PartNumber);
					Source = Object->PartNumber;
					Resp.DataLength = (uint16)sizeof(Object->PartNumber);
				}
				break;
			case 0xEA06:/* HW version */
				{
					SWC_IPC_PRINT_INFO("0xEA06 = Hw version");
					(void)Rte_Read_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193(Object->HWVersionNumber);
					Source = Object->HWVersionNumber;
					Resp.DataLength = (uint16)sizeof(Object->HWVersionNumber);
				}
				break;
			case 0xEA07:/* Product Data */
				{
					SWC_IPC_PRINT_INFO("0xEA07 = Product data");
					(void)Rte_Read_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C(Object->ProductInfo);
					Source = &(Object->ProductInfo[10]);
					Resp.DataLength = (uint16)6;
				}
				break;
			case 0xEA08:/* MCU version */
				{
					SWC_IPC_PRINT_INFO("0xEA08 = MCU version");
					(void)Rte_Read_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01(Object->MCUVersionNumber);
					Source = Object->MCUVersionNumber;
					Resp.DataLength = (uint16)sizeof(Object->MCUVersionNumber);
				}
				break;
			case 0xEA09:/* Project code */
				{
					SWC_IPC_PRINT_INFO("0xEA09 = Project code");
					//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();

					if (Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
					{
						Object->ProjectCode[0] = Object->VehicleConfig[VCONFIG_KIND_PROJECT_CODE];
					    Source = Object->ProjectCode;
						Resp.DataLength = (uint16)sizeof(Object->ProjectCode);
					}
					else
					{
						SWC_IPC_PRINT_ERROR("Vehicle config data is invalid!");
					}
				}
				break;
			case 0xEA02:/* Serial Number */
				{
					SWC_IPC_PRINT_INFO("0xEA02 = Serial number");
					(void)Rte_Read_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C(Object->ProductInfo);
					Source = &(Object->ProductInfo[0]);
					Resp.DataLength = (uint16)20;
				}
				break;
			case 0xEA0A:/* Read First 100Bytes of DTC Information */
				{
					SWC_IPC_PRINT_INFO("0xEA0A = DTC information group - 1 (0-99)");
					IPC_ReadDTCInfo(0,Object);
					Source = &(Object->DtcInfomation[0]);
					Resp.DataLength = (uint16)100;
				}
				break;
			case 0xEA0B:/* Read Second 100Bytes of DTC Information */
				{
					SWC_IPC_PRINT_INFO("0xEA0B = DTC information group - 2 (100-199)");
					IPC_ReadDTCInfo(1,Object);
					Source = &(Object->DtcInfomation[100]);
					Resp.DataLength = (uint16)100;
				}
				break;
			case 0xEA0C:/* Read Third 100Bytes of DTC Information */
				{
					SWC_IPC_PRINT_INFO("0xEA0C = DTC information group - 3 (200-299)");
					IPC_ReadDTCInfo(2,Object);
					Source = &(Object->DtcInfomation[200]);
					Resp.DataLength = (uint16)100;
				}
				break;
			case 0xEA0D:/* Read Fourth 100Bytes of DTC Information */
				{
					SWC_IPC_PRINT_INFO("0xEA0D = DTC information group - 4 (300-399)");
					IPC_ReadDTCInfo(3,Object);
					Source = &(Object->DtcInfomation[300]);
					Resp.DataLength = (uint16)100;
				}
				break;
			case 0xEA16:/* Vehicle Mode Info */
				{
					SWC_IPC_PRINT_INFO("0xEA16 = Vehicle mode information");
					(void)Rte_Call_rpCS_GetVehicleModeInfo_Data(Object->VehicleMode);
					Source = Object->VehicleMode;
					Resp.DataLength = (uint16)sizeof(Object->VehicleMode);
				}
				break;
			case 0xEA17:/* CAN Matrix Version Info */
				{
					SWC_IPC_PRINT_INFO("0xEA17 = CAN matrix version information");
					(void)Rte_Call_rpCS_GetCANMatrixVersionInfo_Data(Object->CANMatrixVersion);
					Source = Object->CANMatrixVersion;
					Resp.DataLength = (uint16)sizeof(Object->CANMatrixVersion);
				}
				break;
			case 0xEA18:/* Get SecOC Switch Status */
				{
					SWC_IPC_PRINT_INFO("0xEA1B = E2e switch");
					Source = &(Object->SecOcSwitchValue);
					Resp.DataLength = (uint16)sizeof(Object->SecOcSwitchValue);
				}
				break;
			case 0xEA1A:/* Get E2E Switch Status */
				{
					SWC_IPC_PRINT_INFO("0xEA19 = SecOC switch");
					Source = &(Object->E2ESwitchValue);
					Resp.DataLength = (uint16)sizeof(Object->E2ESwitchValue);
				}
				break;

			default:
				{
					SWC_IPC_PRINT_ERROR("Unknown InfoId!");
				}
				break;
		}
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Unknown ModuleId!");
	}
	if (SWC_IPC_NULL != Source)
	{
		Resp.Result = 0; /*0 is read success*/
		(void)memcpy(Resp.Data , Source , Resp.DataLength);

		#ifdef SWC_IPC_APP_BUFFER_PRINT_SWITCH
			IPC_API_PrintDataArrayLog(Resp.Data , Resp.DataLength);
		#endif
	}
	/*Send respond*/
	IPC_API_AppMsgTransmit((uint8)M2S_READ_ENGINEER_INFO_RESP, (uint8 *)&Resp, (uint16)sizeof(Resp), TRUE);
}

/**********************************************************************************************************
*Function   : IPC_API_WriteEngineerInfoCallback                                                           *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-08                                                                                  *
**********************************************************************************************************/
void IPC_API_WriteEngineerInfoCallback(uint8 *Data)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	IPC_S2M_EngineerIVISetParaRequest_t *Req = (IPC_S2M_EngineerIVISetParaRequest_t *)Data;
	IPC_M2S_EngineerIVISetParaResponse_t Resp;
	// uint8* Target = SWC_IPC_NULL;

	SWC_IPC_PRINT_INFO("Write engineer information request from ivi-hal: ModuleId = %d , InfoId = 0x%X , Length = %d",
		               Req->ModuleId, Req->InfoId,Req->DataLength);

#ifdef SWC_IPC_APP_BUFFER_PRINT_SWITCH
	IPC_API_PrintDataArrayLog(Req->Data , Req->DataLength);
#endif

	Resp.ModuleId = Req->ModuleId;
	Resp.InfoId = Req->InfoId;
	Resp.Result = 1; /*Default , 1 is write faild*/

	switch (Req->ModuleId)
	{
		case 0x01:
		{
			switch (Req->InfoId)
			{
				case 0xEA01:/* Part number */
					{
						SWC_IPC_PRINT_WARNING("0xEA01 = Part number , This data cannot be written!");
						Resp.Result = 1; /*1 is write faild*/
					}
					break;
				case 0xEA06:/* HW version */
					{
						SWC_IPC_PRINT_WARNING("0xEA06 = Hw version , This data cannot be written!");
						Resp.Result = 1; /*1 is write faild*/
					}
					break;
				case 0xEA07:/* Product Data */
					{
						SWC_IPC_PRINT_WARNING("0xEA07 = Product data , This data cannot be written!");
						Resp.Result = 1; /*1 is write faild*/
					}
					break;
				case 0xEA08:/* MCU version */
					{
						SWC_IPC_PRINT_WARNING("0xEA08 = MCU version , This data cannot be written!");
						Resp.Result = 1; /*1 is write faild*/
					}
					break;
				case 0xEA09:/* Project code */
					{
						SWC_IPC_PRINT_WARNING("0xEA09 = Project code , This data cannot be written!");
						Resp.Result = 1; /*1 is write faild*/
					}
					break;
				case 0xEA02:/* Serial Number */
					{
						SWC_IPC_PRINT_WARNING("0xEA02 = Serial number , This data cannot be written!");
						Resp.Result = 1; /*1 is write faild*/
					}
					break;
				case 0xEA0A:/* Read First 100Bytes of DTC Information */
					{
						SWC_IPC_PRINT_WARNING("0xEA0A = DTC information group - 1 (0-99) , This data cannot be written!");
						Resp.Result = 1; /*1 is write faild*/
					}
					break;
				case 0xEA0B:/* Read Second 100Bytes of DTC Information */
					{
						SWC_IPC_PRINT_WARNING("0xEA0A = DTC information group - 2 (100-199) , This data cannot be written!");
						Resp.Result = 1; /*1 is write faild*/
					}
					break;
				case 0xEA0C:/* Read Third 100Bytes of DTC Information */
					{
						SWC_IPC_PRINT_WARNING("0xEA0A = DTC information group - 3 (200-299) , This data cannot be written!");
						Resp.Result = 1; /*1 is write faild*/
					}
					break;
				case 0xEA0D:/* Read Fourth 100Bytes of DTC Information */
					{
						SWC_IPC_PRINT_WARNING("0xEA0A = DTC information group - 4 (300-399) , This data cannot be written!");
						Resp.Result = 1; /*1 is write faild*/
					}
					break;
				case 0xEA16:/* Vehicle Mode Info */
					{
						SWC_IPC_PRINT_WARNING("0xEA16 = Vehicle mode information , This data cannot be written!");
						Resp.Result = 1; /*1 is write faild*/
					}
					break;
				case 0xEA17:/* CAN Matrix Version Info */
					{
						SWC_IPC_PRINT_WARNING("0xEA17 = CAN matrix version information , This data cannot be written!");
						Resp.Result = 1; /*1 is write faild*/
					}
					break;
				case 0xEA15:
					{
						SWC_IPC_PRINT_INFO("0xEA15 = Fuel and Tc update switch");
						Object->FuelAndTcSwitch = Req->Data[0];
						Resp.Result = 0;
					}
					break;
				case 0xEA14:/* Clear DTC information */
					{
						SWC_IPC_PRINT_INFO("0xEA14 = Clear DTC information");
						if (Object->ClearDtcSwitch == SWC_IPC_CLEAR)
						{
							Object->ClearDtcSwitch = SWC_IPC_TRIGGERED;
						}
						Resp.Result = 0;
					}
					break;
				case 0xEA19:/* Set SecOC Switch Status */
					{
						(void)SWC_IPC_PRINT_DEBUG("0xEA19 = SecOC switch");
                        Object->SecOcWriteValueByEngineer = Req->Data[0];
                        Object->SecOcSetFlag = TRUE;
                        Resp.Result = 0;
					}
					break;
				case 0xEA1B:/* Set E2E Switch Status */
					{
						(void)SWC_IPC_PRINT_DEBUG("0xEA1B = E2e switch");
                        Object->E2EWriteValueByEngineer = Req->Data[0];
                        Object->E2ESetFlag = TRUE;
                        Resp.Result = 0;
					}
					break;

				default:
					{
						SWC_IPC_PRINT_ERROR("Unknown InfoId!");
						Resp.Result = 1; /*1 is write faild*/
					}
					break;
			}
		}
		break;
		default:
		{
			SWC_IPC_PRINT_ERROR("Unknown ModuleId!");
			Resp.Result = 1; /*1 is write faild*/
		}
		break;
	}

	/*Send respond*/
	IPC_API_AppMsgTransmit((uint8)M2S_SET_ENGINEER_PARA_RESP, (uint8 *)&Resp, (uint16)sizeof(Resp), TRUE);
}

/**********************************************************************************************************
*Function   : IPC_API_ReadCommonInfoCallback                                                           *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Data                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-08                                                                                  *
**********************************************************************************************************/
void IPC_API_ReadCommonInfoCallback(uint8 *Data)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	IPC_S2M_IVIAppInfoReadSettingSignalReq_t *Req = (IPC_S2M_IVIAppInfoReadSettingSignalReq_t *)Data;
	IPC_M2S_IVIAppInfoReadSettingSignalResp_t Resp;

	SWC_IPC_PRINT_INFO("Read common information request from ivi-hal: ClientId = %d , ModuleId = %d , InfoId = 0x%X",
		               Req->ClientID,Req->ModuleID, Req->InfoID);

	Resp.ClientID = Req->ClientID;
	Resp.ModuleID = Req->ModuleID;
	Resp.InfoID = Req->InfoID;
	Resp.DataLength = 0;

	(void)memset(&Resp.Data[0], 0, sizeof(Resp.Data));

	if (0x01 == Req->ModuleID)
	{
		if (0xFA41 == Req->InfoID)			/* DriveModeStorageSwitch */
		{
			Resp.DataLength = 1;
			(void)memcpy(&Resp.Data[0], &Object->AppNvm.DriveModeStorageSwitch, Resp.DataLength);

			(void)SWC_IPC_PRINT_DEBUG("[HAL]0xFA41 = %d", Resp.Data[0]);
		}
		else if (0xEA02 == Req->InfoID)		/* SN Number */
		{
			(void)Rte_Read_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C(Object->ProductInfo);
			Resp.DataLength = 20;
			(void)memcpy(&Resp.Data[0], &Object->ProductInfo[0], Resp.DataLength);

			SWC_IPC_PRINT_INFO("0xEA02 = SN number");
		}
		else if (0xEA03 == Req->InfoID)		/* VIN Number */
		{
			(void)Rte_Call_rpCS_SWCGateWay_GetVinNumber_Operation(&Object->VinNumber[0]);
			Resp.DataLength = 17;
			(void)memcpy(&Resp.Data[0], &Object->VinNumber[0], Resp.DataLength);

			(void)SWC_IPC_PRINT_DEBUG("0xEA03 = VIN number");
			#ifdef SWC_IPC_DEBUG
				IPC_API_PrintDataArrayDEBUGLog(&Object->VinNumber[0], Resp.DataLength);
			#endif
		}
		else if (0xEA16 == Req->InfoID)		/* Vehicle Mode Info */
		{
			(void)Rte_Call_rpCS_GetVehicleModeInfo_Data(Object->VehicleMode);
			Resp.DataLength = 20;
			(void)memcpy(&Resp.Data[0], &Object->VehicleMode[0], Resp.DataLength);

			SWC_IPC_PRINT_INFO("0xEA16 = Vehicle mode info");
		}
		else
		{
			SWC_IPC_PRINT_ERROR("Unknown InfoId!");
		}
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Unknown ModuleId!");
	}

#ifdef SWC_IPC_APP_BUFFER_PRINT_SWITCH
	if (Resp.DataLength > 0)
	{
		IPC_API_PrintDataArrayLog(Resp.Data , Resp.DataLength);
	}
#endif

	IPC_API_AppMsgTransmit((uint8)M2S_READ_SETTING_RESP, (uint8 *)&Resp, (uint16)sizeof(Resp), TRUE);
}

/**********************************************************************************************************
*Function   : IPC_API_WriteCommonInfoCallback                                                             *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Data                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-08                                                                                  *
**********************************************************************************************************/
void IPC_API_WriteCommonInfoCallback(uint8 *Data)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	IPC_S2M_IVIAppInfoSetSettingSignalReq_t *Req = (IPC_S2M_IVIAppInfoSetSettingSignalReq_t *)Data;
	IPC_M2S_IVIAppInfoSetSettingSignalResp_t Resp;
    EnergyInfoIdDataType EnergyInfoIdData = {0};
	//uint8* Object->VehicleConfig = SWC_IPC_NULL;
	//VconfigKind_Allbuffers Object->VehicleConfig;

	SWC_IPC_PRINT_INFO("Write common information request from ivi-hal: ClientId = %d , ModuleId = %d , InfoId = 0x%X",
		               Req->ClientID,Req->ModuleID, Req->InfoID);

#ifdef SWC_IPC_APP_BUFFER_PRINT_SWITCH
	IPC_API_PrintDataArrayLog(Req->Data , Req->DataLength);
#endif

	Resp.ClientID = Req->ClientID;
	Resp.ModuleID = Req->ModuleID;
	Resp.InfoID = Req->InfoID;
	Resp.Result = 1;		/* 1 is failed, default value */
	Resp.DataLength = 0;
	(void)memset(&Resp.Data[0], 0, sizeof(Resp.Data));

	if (0x01 == Req->ModuleID)
	{
		if (0xFA41 == Req->InfoID)
		{
			SWC_IPC_PRINT_INFO("0xFA41 = Drive mode storage switch");

			Resp.DataLength = 1;
			(void)memcpy(&Resp.Data[0], &Req->Data[0], Resp.DataLength);
			(void)memcpy(&Object->AppNvm.DriveModeStorageSwitch, &Req->Data[0], Resp.DataLength);
			Resp.Result = 0;
			//if(E_OK == Rte_Read_Vconfig_GetKindBuffers_AllKinds(Object->VehicleConfig))
			{
				//Object->VehicleConfig = Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();
				if (Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
				{
					/* 驾驶模式开关记忆：硬开关 */
					if ((1 == Object->VehicleConfig[VCONFIG_KIND_MEMORY_OF_DRIVING_MODE])
					&& (1 == Object->VehicleConfig[VCONFIG_KIND_DRIVING_MODE_SIGNAL_SELECT]))
					{
						IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvgModeMemReq, &Req->Data[0]);
					}
					else
					{
						(void)SWC_IPC_PRINT_DEBUG("Cant send DrvgModeMemReq because drvgModeMemReq config error!");
					}
				}
				else
				{
					(void)SWC_IPC_PRINT_DEBUG("Vehicle config data is invalid!");
				}
			}
		}
		else if (0xEA02 == Req->InfoID)
		{
			SWC_IPC_PRINT_INFO("0xEA02 = SN number , This data cannot be written!");
		}
		else if (0xEA03 == Req->InfoID)		/* VIN Number */
		{
			SWC_IPC_PRINT_INFO("0xEA03 = VIN number , This data cannot be written!");
		}
		else if (0xEA16 == Req->InfoID)		/* Vehicle Mode Info */
		{
			SWC_IPC_PRINT_INFO("0xEA16 = Vehicle mode info , This data cannot be written!");
		}
        else if (0xFB01 == Req->InfoID)		/* Activate the energy management message switch */
		{
            Resp.DataLength = 1;
			(void)memcpy(&Resp.Data[0], &Req->Data[0], Resp.DataLength);
			Resp.Result = 0;

            EnergyInfoIdData.ModuleId = Req->ModuleID;
            EnergyInfoIdData.ClientId = Req->ClientID;
            (void)Rte_Write_ppSR_SWCGateWay_EnergyInfoId_Data(&EnergyInfoIdData);
            (void)Rte_Call_rpCS_SWCGateWay_TC_EnergyInfo_Operation(TC_ENERGY_PER_1KM, &Req->Data[0]);
			(void)SWC_IPC_PRINT_DEBUG("0xFB01 switch = %d", Req->Data[0]);
		}
        else if (0xFB02 == Req->InfoID)		/* ivi-hal receive the energy message response */
		{
            (void)Rte_Call_rpCS_SWCGateWay_TC_EnergyInfo_Operation(TC_ENERGY_RESP, &Req->Data[4]);
			(void)SWC_IPC_PRINT_DEBUG("0xFB02 response = %d", Req->Data[4]);
		}
		else
		{
			SWC_IPC_PRINT_ERROR("Unknown InfoId!");
		}
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Unknown ModuleId!");
	}

    if (0xFB02 != Req->InfoID)
    {
        IPC_API_AppMsgTransmit((uint8)M2S_SET_SETTING_RESP, (uint8 *)&Resp, (uint16)sizeof(Resp), TRUE);
    }
    else
    {
        SWC_IPC_PRINT_INFO("0xFB02 = ivi-hal receive the energy message response, Do not upload response here!");
    }
}

/**********************************************************************************************************
*Function   : IPC_E2EAndSecOcSwitchStatusProcess                                                          *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Object                                                              					  	  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-08                                                                                  *
**********************************************************************************************************/
static void IPC_E2EAndSecOcSwitchStatusProcess(SWC_IPC_AppMsgObject *Object)
{
	uint8 ReadResult = E_NOT_OK;
	uint8 E2ESwitchValue = 0;
	uint8 SecOcSwitchValue = 0;
	IPC_M2S_EngineerIVIReadInfoResponse_t MsgBuffer;

#define IPC_E2E_SECOC_CYCLE (100u / SWC_IPC_APPLICATION_TASK_CYCLE)

	if (Object->SecOcSwitchTick == 0)
	{
		(void)Rte_Call_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation((uint8)sizeof(Object->SecOcSwitchValue), &SecOcSwitchValue, &ReadResult);

		if (E_OK == ReadResult)
		{
			if (SecOcSwitchValue != Object->SecOcSwitchValue)
			{
				(void)memset(&MsgBuffer, 0, sizeof(IPC_M2S_EngineerIVIReadInfoResponse_t));
				MsgBuffer.ModuleId = 0x1;
				MsgBuffer.InfoId = 0xEA18;
				MsgBuffer.DataLength = (uint16)sizeof(SecOcSwitchValue);
				MsgBuffer.Result = 0;
				(void)memcpy(&MsgBuffer.Data, &SecOcSwitchValue, sizeof(SecOcSwitchValue));

				IPC_API_AppMsgTransmit((uint8)M2S_READ_ENGINEER_INFO_RESP,
									   (uint8 *)&MsgBuffer,
									   (uint16)sizeof(IPC_M2S_EngineerIVIReadInfoResponse_t), TRUE);
				Object->SecOcSwitchValue = SecOcSwitchValue;
				SWC_IPC_PRINT_INFO("SecOC switch is changed! value = %d",SecOcSwitchValue);
			}
			Object->SecOcSwitchTick = IPC_E2E_SECOC_CYCLE;
		}
	}
	else
	{
		Object->SecOcSwitchTick -= 1;
	}

	if (Object->E2ESwitchTick == 0)
	{
		(void)Rte_Call_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation((uint8)sizeof(Object->E2ESwitchValue), &E2ESwitchValue, &ReadResult);

		if (E_OK == ReadResult)
		{
			if (E2ESwitchValue != Object->E2ESwitchValue)
			{
				(void)memset(&MsgBuffer, 0, sizeof(IPC_M2S_EngineerIVIReadInfoResponse_t));
				MsgBuffer.ModuleId = 0x1;
				MsgBuffer.InfoId = 0xEA1A;
				MsgBuffer.DataLength = (uint16)sizeof(E2ESwitchValue);
				MsgBuffer.Result = 0;
				(void)memcpy(&MsgBuffer.Data, &E2ESwitchValue, sizeof(E2ESwitchValue));

				IPC_API_AppMsgTransmit((uint8)M2S_READ_ENGINEER_INFO_RESP,
									   (uint8 *)&MsgBuffer,
									   (uint16)sizeof(IPC_M2S_EngineerIVIReadInfoResponse_t), TRUE);
				Object->E2ESwitchValue = E2ESwitchValue;
				SWC_IPC_PRINT_INFO("E2e switch is changed! value = %d",E2ESwitchValue);
			}
			Object->E2ESwitchTick = IPC_E2E_SECOC_CYCLE;
		}
	}
	else
	{
		Object->E2ESwitchTick -= 1;
	}

	if (FALSE != Object->SecOcSetFlag)
    {
        if (Object->SecOcSwitchValue != Object->SecOcWriteValueByEngineer)
        {
            uint8 WriteResult = E_NOT_OK;
            (void)Rte_Call_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation((uint8)sizeof(Object->SecOcSwitchValue), &Object->SecOcWriteValueByEngineer, &WriteResult);
            if (E_OK == WriteResult)
            {
                Object->SecOcSwitchValue = Object->SecOcWriteValueByEngineer;
                Object->SecOcSetFlag = FALSE;
                (void)SWC_IPC_PRINT_DEBUG("SecOc write value = %d", Object->SecOcWriteValueByEngineer);
            }
        }
    }

    if (FALSE != Object->E2ESetFlag)
    {
        if (Object->E2ESwitchValue != Object->E2EWriteValueByEngineer)
        {
            uint8 WriteResult = E_NOT_OK;
            (void)Rte_Call_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation((uint8)sizeof(Object->E2ESwitchValue), &Object->E2EWriteValueByEngineer, &WriteResult);
            if (E_OK == WriteResult)
            {
                Object->E2ESwitchValue = Object->E2EWriteValueByEngineer;
                Object->E2ESetFlag = FALSE;
                (void)SWC_IPC_PRINT_DEBUG("E2E write value = %d", Object->E2EWriteValueByEngineer);
            }
        }
    }
}

/**********************************************************************************************************
*Function   : IPC_AppAliveMonitor                                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Object                                                              					  	  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-08                                                                                  *
**********************************************************************************************************/
static void IPC_AppAliveMonitor(SWC_IPC_AppMsgObject * Object)
{
	IPC_M2S_SAFETYAPPSafetyAppMsgUploaded_t SaftyResp;
	IPC_M2S_ClusterAppSystemCommonAppMsgUploaded_t CommonResp;
	IPC_M2S_HUDCommonAliveMonitorMsgUploaded_t WhudResp;
	IPC_M2S_ClusterAppSystemInterfaceAppMsgUploaded_t InterfaceResp;
	IPC_M2S_ClusterAppSystemGaugeMsgUploaded_t GaugesResq;

	if (FALSE != Object->AliveMonitor[SWC_IPC_SAFTY_APP_ALIVE_MONITOR])
	{
		if ((FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_TELLTALE))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_SAFTY_TELLTALE))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_GEAR))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_INTERNAL_CONFIG_UPLOAD))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CLUSTER_POWER))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_SPEEDOMETER))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_TACHOMETER))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_COOLANT))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_APP_VCONFIG))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_DRIVE_MODE_RESP)))
		{
			Object->AliveMonitor[SWC_IPC_SAFTY_APP_ALIVE_MONITOR] = FALSE;
			SaftyResp.Status = 0xBB;
			IPC_API_AppMsgTransmit((uint8)M2S_SAFETY_APP_MSG_UPLOADED, (uint8 *)&SaftyResp, (uint16)sizeof(SaftyResp), TRUE);

			SWC_IPC_SET_BIT(Object->AliveMonitorFlag , SWC_IPC_SAFTY_APP_ALIVE_MONITOR);

			SWC_IPC_PRINT_INFO("Cluster safty app alive msg upload requested!");
		}
	}

	if (FALSE != Object->AliveMonitor[SWC_IPC_COMMON_APP_ALIVE_MONITOR])
	{
		if ((FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_WARNING))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_ODOMETER))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_SIA))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_TPMS))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_FUEL))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_TRIP_COMPUTER))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_SET_MENU_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_INTERNAL_CONFIG_UPLOAD))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CLUSTER_POWER))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_GEAR))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_SPEEDOMETER))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_DRIVE_MODE_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_MENU_THEME_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_CSA3_244_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_EEM1_2A8_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_CSA2_A1_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_RSDS_FD1_16F_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_IFC_FD5_19F_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_IFC_FD6_222_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_ACC_FD2_2AB_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_IFC_FD2_23D_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_AEB_FD2_227_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_CR_FD1_15E_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_IFC_FD3_2CF_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_ACC_FD3_2B4_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_BCM1_319_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_BCM3_345_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_T_Box_FD10_2F0_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_BCM12_238_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_F_PBOX1_19B_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_HCM_L2_304_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_ESP1_149_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_ESP2_145_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_ESP2_137_RESP)))
		{
			Object->AliveMonitor[SWC_IPC_COMMON_APP_ALIVE_MONITOR] = FALSE;
			CommonResp.Status = 0xBB;
			IPC_API_AppMsgTransmit((uint8)M2S_COMMON_APP_MSG_UPLOADED, (uint8 *)&CommonResp, (uint16)sizeof(CommonResp), TRUE);

			SWC_IPC_SET_BIT(Object->AliveMonitorFlag , SWC_IPC_COMMON_APP_ALIVE_MONITOR);

			SWC_IPC_PRINT_INFO("Cluster common app alive msg upload requested!");
		}
	}

	if (FALSE != Object->AliveMonitor[SWC_IPC_WHUD_APP_MONITOR])
	{
		if ((FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_WHUD_NVM_CONFIG_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_TELLTALE))
			/*&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_SAFTY_TELLTALE))*/
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_WARNING))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CLUSTER_POWER))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_DRIVE_MODE_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_HUD1_325_RESP)))
		{
			Object->AliveMonitor[SWC_IPC_WHUD_APP_MONITOR] = FALSE;
			WhudResp.Status = 0xBB;
			IPC_API_AppMsgTransmit((uint8)M2S_WHUD_MSG_UPLOADED, (uint8 *)&WhudResp, (uint16)sizeof(WhudResp), TRUE);

			SWC_IPC_SET_BIT(Object->AliveMonitorFlag , SWC_IPC_WHUD_APP_MONITOR);

			SWC_IPC_PRINT_INFO("Whud alive msg upload requested!");
		}
	}

	if (FALSE != Object->AliveMonitor[SWC_IPC_INTERFACE_APP_MONITOR])
	{
		if ((FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_TPMS))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_SIA))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_ODOMETER))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_TRIP_COMPUTER))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_WARNING))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_SET_MENU_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_FUEL))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_INTERNAL_CONFIG_UPLOAD))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_SAFTY_TELLTALE))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_TELLTALE))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_ECM3_371_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_CSA2_A1_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_ECM16_2D4_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_AC2_385_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_ECM_PT6_290_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_ABM2_245_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CA_ECM24_350_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_SET_OffroadInfo_RESP))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_NEWENERGY))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_NEWENERGY_EV)))
		{
			Object->AliveMonitor[SWC_IPC_INTERFACE_APP_MONITOR] = FALSE;
			InterfaceResp.Status = 0xBB;
			IPC_API_AppMsgTransmit((uint8)M2S_INTERFACE_UPLOADED, (uint8 *)&InterfaceResp, (uint16)sizeof(InterfaceResp), TRUE);

			SWC_IPC_SET_BIT(Object->AliveMonitorFlag , SWC_IPC_INTERFACE_APP_MONITOR);

			SWC_IPC_PRINT_INFO("Interface App alive msg upload requested!");
		}
	}

	if (FALSE != Object->AliveMonitor[SWC_IPC_GAUGES_APP_ALIVE_MONITOR])
	{
		if ((FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_CLUSTER_POWER))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_TACHOMETER))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_COOLANT))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_SPEEDOMETER))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_NEWENERGY))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_NEWENERGY_EV))
			&& (FALSE == IPC_API_CheckRepeatStatus((uint8)M2S_TRIP_COMPUTER)))
		{
			Object->AliveMonitor[SWC_IPC_GAUGES_APP_ALIVE_MONITOR] = FALSE;
			GaugesResq.Status = 0xBB;
			IPC_API_AppMsgTransmit((uint8)M2S_GAUGES_UPLOADED, (uint8 *)&GaugesResq, (uint16)sizeof(GaugesResq), TRUE);

			SWC_IPC_SET_BIT(Object->AliveMonitorFlag , SWC_IPC_GAUGES_APP_ALIVE_MONITOR);

			SWC_IPC_PRINT_INFO("Gauges alive msg upload requested!");
		}
	}

	if (FALSE != Object->AliveMonitor[SWC_IPC_CHIME_CLIENT_APP_ALIVE_MONITOR])
	{
		Object->AliveMonitor[SWC_IPC_CHIME_CLIENT_APP_ALIVE_MONITOR] = FALSE;
		SWC_IPC_SET_BIT(Object->AliveMonitorFlag , SWC_IPC_CHIME_CLIENT_APP_ALIVE_MONITOR);

		SWC_IPC_PRINT_INFO("Chime client set bit executed!");
	}

	if (FALSE != Object->AliveMonitor[SWC_IPC_SOC_HMI_SAFETY_ALIVE_MONITOR])
	{
		Object->AliveMonitor[SWC_IPC_SOC_HMI_SAFETY_ALIVE_MONITOR] = FALSE;
		SWC_IPC_SET_BIT(Object->AliveMonitorFlag , SWC_IPC_SOC_HMI_SAFETY_ALIVE_MONITOR);

		SWC_IPC_PRINT_INFO("Hmi Safety set bit executed!");
	}

	(void)Rte_Write_Common_GateWay_SocReadyFlag_Element(Object->AliveMonitorFlag);
}

/**********************************************************************************************************
*Function   : IPC_API_ChimeClientAliveCallback                                                           *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Data                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-08                                                                                  *
**********************************************************************************************************/
void IPC_API_ChimeClientAliveCallback(uint8 *Data)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	IPC_S2M_ClusterAppClusterSocChimeClientAlive_t *Req = (IPC_S2M_ClusterAppClusterSocChimeClientAlive_t *)Data;

	if (0xAA == Req->AliveTick)
	{
		if (FALSE == Object->AliveMonitor[SWC_IPC_CHIME_CLIENT_APP_ALIVE_MONITOR])
		{
			Object->AliveMonitor[SWC_IPC_CHIME_CLIENT_APP_ALIVE_MONITOR] = TRUE;
		}

		SWC_IPC_PRINT_INFO("Cluster chime client alive request from qnx-cluster!");
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Invalid cluster chime client alive request from qnx-cluster! Value = %d",Req->AliveTick);
	}
}

/**********************************************************************************************************
*Function   : IPC_API_GaugesAliveCallback                                                           *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Data                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-08                                                                                  *
**********************************************************************************************************/
void IPC_API_GaugesAliveCallback(uint8 *Data)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	IPC_S2M_ClusterAppClusterSocGaugesAlive_t *Req = (IPC_S2M_ClusterAppClusterSocGaugesAlive_t *)Data;

	if (0xAA == Req->AliveTick)
	{
		if (FALSE == Object->AliveMonitor[SWC_IPC_GAUGES_APP_ALIVE_MONITOR])
		{
			IPC_API_AppMsgTransmit((uint8)M2S_CLUSTER_POWER, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_TACHOMETER, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_SPEEDOMETER, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_COOLANT, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_TRIP_COMPUTER,SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_NEWENERGY, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_NEWENERGY_EV, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			Object->AliveMonitor[SWC_IPC_GAUGES_APP_ALIVE_MONITOR] = TRUE;
		}

		SWC_IPC_PRINT_INFO("Cluster gauges alive request from qnx-cluster!");
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Invalid cluster gauges alive request from qnx-cluster! Value = %d",Req->AliveTick);
	}
}

/**********************************************************************************************************
*Function   : IPC_API_GetSafetyAppAliveCallback                                                           *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Data                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-08                                                                                  *
**********************************************************************************************************/
void IPC_API_GetSafetyAppAliveCallback(uint8 *Data)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	IPC_S2M_SAFETYAPPSafetyAppAlive_t *Req = (IPC_S2M_SAFETYAPPSafetyAppAlive_t *)Data;

	if (0xAA == Req->AliveTick)
	{
		if (FALSE == Object->AliveMonitor[SWC_IPC_SAFTY_APP_ALIVE_MONITOR])
		{
			IPC_API_AppMsgTransmit((uint8)M2S_APP_VCONFIG, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CLUSTER_POWER, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_GEAR, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_INTERNAL_CONFIG_UPLOAD, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_SAFTY_TELLTALE, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_TELLTALE, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_SPEEDOMETER, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_TACHOMETER, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_COOLANT, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_DRIVE_MODE_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);

			Object->AliveMonitor[SWC_IPC_SAFTY_APP_ALIVE_MONITOR] = TRUE;
		}

		SWC_IPC_PRINT_INFO("Cluster safty app alive request from qnx-cluster!");
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Invalid cluster safty app alive request from qnx-cluster! Value = %d",Req->AliveTick);
	}
}
/**********************************************************************************************************
*Function   : IPC_API_GetSocHMISafetyAliveCallback                                                        *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Data                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : DylanZhao                                                                                   *
*                                                                                                         *
*Date       : 2021-08-04                                                                                  *
**********************************************************************************************************/
void IPC_API_GetSocHMISafetyAliveCallback(uint8 *Data)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	IPC_S2M_ClusterAppClusterSocHMISafety_t *Req = (IPC_S2M_ClusterAppClusterSocHMISafety_t *)Data;

	if (0xAA == Req->AliveTick)
	{
		if (FALSE == Object->AliveMonitor[SWC_IPC_SOC_HMI_SAFETY_ALIVE_MONITOR])
		{
			Object->AliveMonitor[SWC_IPC_SOC_HMI_SAFETY_ALIVE_MONITOR] = TRUE;
		}

		SWC_IPC_PRINT_INFO("Hmi Safety client alive request from qnx-cluster!");
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Invalid Hmi Safety client alive request from qnx-cluster! Value = %d",Req->AliveTick);
	}
}
/**********************************************************************************************************
*Function   : IPC_API_GetCommonAppAliveCallback                                                           *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Data                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-08                                                                                  *
**********************************************************************************************************/
void IPC_API_GetCommonAppAliveCallback(uint8 *Data)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	IPC_S2M_ClusterAppClusterSocCommonAppAlive_t *Req = (IPC_S2M_ClusterAppClusterSocCommonAppAlive_t *)Data;

	if (0xAA == Req->AliveTick)
	{
		if (FALSE == Object->AliveMonitor[SWC_IPC_COMMON_APP_ALIVE_MONITOR])
		{
			IPC_API_AppMsgTransmit((uint8)M2S_CLUSTER_POWER, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_MenuSettingUpload(Object);
			IPC_API_AppMsgTransmit((uint8)M2S_INTERNAL_CONFIG_UPLOAD, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_WARNING, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_TPMS, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_ODOMETER, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_SIA, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_FUEL, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_TRIP_COMPUTER, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_GEAR, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_SPEEDOMETER, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_DRIVE_MODE_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_MENU_THEME_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);

			IPC_API_AppMsgTransmit((uint8)M2S_CA_ESP2_145_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_ESP2_137_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_CSA3_244_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_EEM1_2A8_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_CSA2_A1_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_RSDS_FD1_16F_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_IFC_FD5_19F_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_IFC_FD6_222_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_ACC_FD2_2AB_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_IFC_FD2_23D_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_AEB_FD2_227_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_CR_FD1_15E_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);

			IPC_API_AppMsgTransmit((uint8)M2S_CA_IFC_FD3_2CF_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_ACC_FD3_2B4_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_BCM1_319_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_BCM3_345_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
            IPC_API_AppMsgTransmit((uint8)M2S_CA_T_Box_FD10_2F0_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
            IPC_API_AppMsgTransmit((uint8)M2S_CA_BCM12_238_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_F_PBOX1_19B_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_HCM_L2_304_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_ESP1_149_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);

			Object->AliveMonitor[SWC_IPC_COMMON_APP_ALIVE_MONITOR] = TRUE;
		}
		SWC_IPC_PRINT_INFO("Cluster common app alive request from qnx-cluster!");
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Invalid cluster common app alive request from qnx-cluster! Value = %d",Req->AliveTick);
	}
}
/**********************************************************************************************************
*Function   : IPC_MenuSettingUpload                                                                       *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-15                                                                                  *
**********************************************************************************************************/
static void IPC_MenuSettingUpload(SWC_IPC_AppMsgObject * Object)
{
	IPC_M2S_ClusterAppAPPMenuSetting_t MenuResp;
	MenuSetData_t MenuData;
	(void)Object;

	/*Menu set*/
	(void)Rte_Read_rpSR_SWCGateWay_MenuSetData_Element(&MenuData);

	MenuResp.Sd_NaviLimitSpeed = MenuData.NaviLimitSpeed ;
	MenuResp.Sd_OverSpeedEnable = MenuData.OverSpeedEnable ;
	MenuResp.Sd_Language = MenuData.Language ;
	MenuResp.Sd_ClusterTheme = MenuData.ClusterTheme ;
	MenuResp.Sd_OdometerUnit = MenuData.OdometerUnit ;
	MenuResp.Sd_TemperatureUnit = MenuData.TemperatureUnit ;
	MenuResp.Sd_TirePressureUnit = MenuData.TirePressureUnit ;
	MenuResp.Sd_TripComputerId = MenuData.TripComputerId ;
	MenuResp.Sd_InteractiveCarId = MenuData.InteractiveCarId ;
	MenuResp.Sd_DrivingModeMemorySwitch = MenuData.DrivingModeMemorySwitch ;
	MenuResp.Sd_TimeUnit = MenuData.TimeUnit ;
	MenuResp.Sd_HighwayAssistSwitch = MenuData.HighwayAssistSwitch ;
	MenuResp.Sd_LaneChangeAssistSwitch = MenuData.LaneChangeAssistSwitch ;
	MenuResp.Sd_SunriseSunset_Mode = MenuData.Cluster_Sunrise_Sunset_Mode;
	MenuResp.Sd_Auto_Mode = MenuData.Cluster_Auto_Mode;
	MenuResp.Sd_DrvgModeMemReq = MenuData.DrvgModeMemReq;
	MenuResp.Sd_DrvingModReqHUT = MenuData.DrvingModReq_HUT;
	MenuResp.Sd_DataSyncFlg = MenuData.DataSyncFlag;
	#if (!defined SWC_IPC_PROJECT_TYPE_P03)
	MenuResp.Sd_AtmosphereLampLinkageSwt_Sts = MenuData.AtmosphereLampLinkageSwt_Sts;
	MenuResp.Sd_SimSoundWaveLinkageSwt_Sts = MenuData.SimSoundWaveLinkageSwt_Sts;
	#endif

	IPC_API_AppMsgTransmit((uint8)M2S_SET_MENU_RESP, (uint8 *)&MenuResp, (uint16)sizeof(MenuResp), TRUE);

	SWC_IPC_PRINT_INFO("Cluster menu setting msg upload requested!");
}
/**********************************************************************************************************
*Function   : IPC_API_GetWhudAliveCallback                                                                *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Data                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-15                                                                                  *
**********************************************************************************************************/
void IPC_API_GetWhudAliveCallback(uint8 *Data)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	IPC_S2M_HUDCommonAliveMsg_t *Req = (IPC_S2M_HUDCommonAliveMsg_t *)Data;
	// IPC_M2S_HUDCommonNvmConfigResponse_t Resp;

	if (0xAA == Req->Tick)
	{
		if (FALSE == Object->AliveMonitor[SWC_IPC_WHUD_APP_MONITOR])
		{
			IPC_API_AppMsgTransmit((uint8)M2S_CLUSTER_POWER, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_WhudNvmConfigUpdate(Object);
			IPC_WhudNvmConfigUpload(Object);
			IPC_API_AppMsgTransmit((uint8)M2S_TELLTALE, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_WARNING, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_DRIVE_MODE_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_HUD1_325_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);

			Object->AliveMonitor[SWC_IPC_WHUD_APP_MONITOR] = TRUE;
		}
		SWC_IPC_PRINT_INFO("Whud alive request from qnx-whud!");
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Invalid whud alive request from qnx-whud! Value = %d",Req->Tick);
	}
}
/**********************************************************************************************************
*Function   : IPC_API_GetWhudNvmConfigCallback                                                            *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Data                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-15                                                                                  *
**********************************************************************************************************/
void IPC_API_GetWhudNvmConfigCallback(uint8 *Data)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	IPC_S2M_HUDCommonNvmConfigRequset_t *Req = (IPC_S2M_HUDCommonNvmConfigRequset_t *)Data;
	// IPC_M2S_HUDCommonNvmConfigResponse_t Resp;

	if (0x1 == Req->Request)
	{
		IPC_WhudNvmConfigUpdate(Object);

		IPC_WhudNvmConfigUpload(Object);

		SWC_IPC_PRINT_INFO("Get whud config request from qnx-whud!");
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Invalid get whud config request from qnx-whud! Value = %d",Req->Request);
	}
}

/**********************************************************************************************************
*Function   : IPC_API_WhudNvmSetWithIdCallback                                                            *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Data                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Dylanzhao                                                                                   *
*                                                                                                         *
*Date       : 2021-7-5                                                                                    *
**********************************************************************************************************/
void IPC_API_WhudNvmSetWithIdCallback(uint8 *Data)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	IPC_S2M_HUDCommonWhudNvmSet_t *Req = (IPC_S2M_HUDCommonWhudNvmSet_t *)Data;

	switch (Req->Id)
	{
		case (uint8)Enum_WHUDSwitch:
			{
				/* do nothing */
			}
			break;

		case (uint8)Enum_DriverDisplaySwitch:
			{
				Object->AppNvm.DriverDisplaySwitch = (boolean)Req->Value;
			}
			break;

		case (uint8)Enum_NaviDisplaySwitch:
			{
				Object->AppNvm.NaviDisplaySwitch = (boolean)Req->Value;
			}
			break;

		case (uint8)Enum_PhoneDisplaySwitch:
			{
				Object->AppNvm.PhoneDisplaySwitch = (boolean)Req->Value;
			}
			break;

		case (uint8)Enum_DisplayRotationLevel:
			{
				Object->AppNvm.DisplayRotationLevel = (sint8)Req->Value;
			}
			break;

		case (uint8)Enum_DisplayHeightLevel:
			{
				/* do nothing */
			}
			break;

		case (uint8)Enum_DisplayBacklightSwitch:
			{
				/* do nothing */
			}
			break;

		case (uint8)Enum_DisplayBacklightLevel:
			{
				/* do nothing */
			}
			break;

		case (uint8)Enum_DisplayTheme:
			{
				Object->AppNvm.DisplayTheme = (uint8)Req->Value;
			}
			break;

		case (uint8)Enum_DisplayFramework:
			{
				/* do nothing */
			}
			break;

		case (uint8)Enum_DisplayMode:
			{
				Object->AppNvm.DisplayMode = (uint8)Req->Value;
			}
			break;

		case (uint8)Enum_DriveMode:
			{
				Object->AppNvm.DriveMode = (uint8)Req->Value;
			}
			break;

		default:
			break;
	}

	SWC_IPC_PRINT_INFO("Set whud config request from qnx-whud!");
	IPC_WhudNvmConfigUpdate(Object);
	IPC_WhudNvmConfigUpload(Object);
}

/**********************************************************************************************************
*Function   : IPC_API_SetWhudNvmConfigCallback                                                            *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Data                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-15                                                                                  *
**********************************************************************************************************/
void IPC_API_SetWhudNvmConfigCallback(uint8 *Data)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	IPC_S2M_HUDCommonSetNvmConfig_t *Req = (IPC_S2M_HUDCommonSetNvmConfig_t *)Data;
	// IPC_M2S_HUDCommonNvmConfigResponse_t Resp;

	//Object->AppNvm.WHUDSwitch = Req->WHUDSwitch;
	Object->AppNvm.DriverDisplaySwitch = (boolean)Req->DriverDisplaySwitch;
	Object->AppNvm.NaviDisplaySwitch = (boolean)Req->NaviDisplaySwitch;
	Object->AppNvm.PhoneDisplaySwitch = (boolean)Req->PhoneDisplaySwitch;
	Object->AppNvm.DisplayRotationLevel = (sint8)Req->DisplayRotationLevel;
	//Object->AppNvm.DisplayHeightLevel = Req->DisplayHeightLevel;
	//Object->AppNvm.DisplayBacklightSwitch = Req->DisplayBacklightSwitch;
	//Object->AppNvm.DisplayBacklightLevel = Req->DisplayBacklightLevel;
	Object->AppNvm.DisplayTheme = (uint8)Req->DisplayTheme;
	Object->AppNvm.DisplayMode = (uint8)Req->DisplayMode;
	//Object->AppNvm.DisplayFramework = Req->DisplayFramework;

	SWC_IPC_PRINT_INFO("Set whud config request from qnx-whud!");

	IPC_WhudNvmConfigUpdate(Object);

	IPC_WhudNvmConfigUpload(Object);
}
/**********************************************************************************************************
*Function   : IPC_API_GetWhudNvmConfigCallback                                                            *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-15                                                                                  *
**********************************************************************************************************/
static void IPC_WhudNvmConfigUpload(SWC_IPC_AppMsgObject * Object)
{
	IPC_M2S_HUDCommonNvmConfigResponse_t Resp;

	Resp.WHUDSwitch = (uint8)Object->AppNvm.WHUDSwitch;
	Resp.DriverDisplaySwitch = (uint8)Object->AppNvm.DriverDisplaySwitch;
	Resp.NaviDisplaySwitch = (uint8)Object->AppNvm.NaviDisplaySwitch;
	Resp.PhoneDisplaySwitch = (uint8)Object->AppNvm.PhoneDisplaySwitch;
	Resp.DisplayRotationLevel = (uint8)Object->AppNvm.DisplayRotationLevel;
	Resp.DisplayHeightLevel = (uint8)Object->AppNvm.DisplayHeightLevel;
	Resp.DisplayBacklightSwitch = (uint8)Object->AppNvm.DisplayBacklightSwitch;
	Resp.DisplayBacklightLevel = (uint8)Object->AppNvm.DisplayBacklightLevel;
	Resp.DisplayTheme = (uint8)Object->AppNvm.DisplayTheme;
	Resp.DisplayFramework = (uint8)Object->AppNvm.DisplayFramework;
	Resp.DisplayMode = (uint8)Object->AppNvm.DisplayMode;
	Resp.DriveMode = (uint8)Object->AppNvm.DriveMode;

	IPC_API_AppMsgTransmit((uint8)M2S_WHUD_NVM_CONFIG_RESP, (uint8 *)&Resp, (uint16)sizeof(Resp), TRUE);

	SWC_IPC_PRINT_INFO("Whud config msg upload requested!");
}
/**********************************************************************************************************
*Function   : IPC_WhudNvmConfigUpdate                                                                     *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-23                                                                                  *
**********************************************************************************************************/
static void IPC_WhudNvmConfigUpdate(SWC_IPC_AppMsgObject * Object)
{
	uint8 Data[2] = {0};

	/* Data[0] : Rx Data Buffer*/
	#if( !(defined SWC_IPC_PROJECT_TYPE_P01))
	if (RTE_E_OK == IPC_API_GetRxCanMsg((uint32)SWC_IPC_CAN_MSG_HUD1,SWC_IPC_NULL))
	{
		#define CanSignal_HUD_SwtSts Data[0]
		IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_SwtSts,&CanSignal_HUD_SwtSts);
		if (1 == CanSignal_HUD_SwtSts)
		{
			Object->AppNvm.WHUDSwitch = TRUE;
			Object->AppNvm.DisplayBacklightSwitch = (uint8)1;
		}
		else
		{
			Object->AppNvm.WHUDSwitch = FALSE;
			Object->AppNvm.DisplayBacklightSwitch = (uint8)0;
		}

		#define CanSignal_HUD_BrightnessLvl Data[0]
		IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_BrightnessLvl,&CanSignal_HUD_BrightnessLvl);
		/*0x0 - 0x8 : Valid*/
		if (CanSignal_HUD_BrightnessLvl <= 0x8)
		{
			Object->AppNvm.DisplayBacklightLevel = CanSignal_HUD_BrightnessLvl;
		}
		else
		{
			/*Reserved*/
			Object->AppNvm.DisplayBacklightLevel = 0x9;
		}

		#define CanSignal_HUD_HeightLvl Data[0]
		IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_HeightLvl,&CanSignal_HUD_HeightLvl);
		/*0x0 - 0x14 : Valid*/
		if (CanSignal_HUD_HeightLvl <= 0x14)
		{
			Object->AppNvm.DisplayHeightLevel = CanSignal_HUD_HeightLvl;
		}
		else
		{
			/*Reserved*/
			Object->AppNvm.DisplayHeightLevel = 0x15;
		}

		#define CanSignal_HUD_UIModVld Data[0]
		#define CanSignal_HUD_UIMod Data[1]
		IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_UIModVld,&CanSignal_HUD_UIModVld);
		IPC_API_GetRxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUD_UIMod,&CanSignal_HUD_UIMod);

		/*0x1 : Valid*/
		if (0x1 == CanSignal_HUD_UIModVld)
		{
			/*0x0 : Normal */
			if (0 == CanSignal_HUD_UIMod)
			{
				if ((Object->AppNvm.DriverDisplaySwitch == FALSE)
				&& (Object->AppNvm.NaviDisplaySwitch == FALSE)
				&& (Object->AppNvm.PhoneDisplaySwitch == FALSE))
				{
					Object->AppNvm.DisplayFramework = 1;/*0x1 : Concise Mode */
				}
				else
				{
					Object->AppNvm.DisplayFramework = 0;/*0x0 : Normal Mode */
				}
			}
			/*0x1 : Dot Matrix Mode */
			else if (1 == CanSignal_HUD_UIMod)
			{
				Object->AppNvm.DisplayFramework = 2;/*0x2 : Calibration Mode */
			}
			else
			{
				/*Keep previous beacuse UIMod is invalid*/
			}
		}
		else
		{
			/*Keep previous beacuse UIModVld is invalid*/
		}
	}
	else
	{
		Object->AppNvm.WHUDSwitch = FALSE;
	}
	#endif
}
/**********************************************************************************************************
*Function   : IPC_DriveModeStorageSwitchUpload                                                            *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Huangchangyu                                                                                *
*                                                                                                         *
*Date       : 2021-06-18                                                                                  *
**********************************************************************************************************/
static void IPC_DriveModeStorageSwitchUpload(SWC_IPC_AppMsgObject * Object)
{
	IPC_M2S_IVIAppInfoReadSettingSignalResp_t Resp_t;

	/*Set Driving Mode value*/
	Resp_t.ClientID = 1;
	Resp_t.ModuleID = 1;
	Resp_t.InfoID = 0xFA41;
	(void)memset(&Resp_t.Data[0], 0, sizeof(Resp_t.Data));
	Resp_t.DataLength = 1;
	(void)memcpy(&Resp_t.Data[0], &Object->AppNvm.DriveModeStorageSwitch, Resp_t.DataLength);

	/*clear restore Driving Mode Default value*/
	IPC_API_AppMsgTransmit((uint8)M2S_READ_SETTING_RESP, (uint8 *)&Resp_t, (uint16)sizeof(Resp_t), TRUE);
}

/**********************************************************************************************************
*Function   : IPC_RestoreAppNvmConfig                                                            *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-15                                                                                  *
**********************************************************************************************************/
static void IPC_RestoreAppNvmConfig(SWC_IPC_AppMsgObject * Object)
{
	//VconfigKind_Allbuffers Object->VehicleConfig;

	//if (E_OK == Rte_Read_Vconfig_GetKindBuffers_AllKinds(Object->VehicleConfig))
    {

	    if (0 != Object->VehicleConfig[VCONFIG_KIND_INIT_FLAG])
    	{
    		if (1 == Object->VehicleConfig[VCONFIG_KIND_HEAD_UP_DISPLAY])
    		{
    			Object->AppNvm.WHUDSwitch = TRUE;
    		}
    		else
    		{
    			Object->AppNvm.WHUDSwitch = FALSE;
    		}
    	}
	    else
    	{
    		Object->AppNvm.WHUDSwitch = FALSE;

    	}
    }

	Object->AppNvm.DriverDisplaySwitch = TRUE;
	Object->AppNvm.NaviDisplaySwitch = TRUE;
	Object->AppNvm.PhoneDisplaySwitch = TRUE;
	Object->AppNvm.DisplayRotationLevel = SWC_WHUD_DEFAULT_ROTATION_LEVEL;
	Object->AppNvm.DisplayHeightLevel = SWC_WHUD_DEFAULT_HIGHT_LEVEL;
	Object->AppNvm.DisplayBacklightSwitch = 0; /*预留*/
	Object->AppNvm.DisplayBacklightLevel = SWC_WHUD_DEFAULT_BACKLIGHT_LEVEL;
	Object->AppNvm.DisplayTheme = 0;
	Object->AppNvm.DisplayFramework = 0;
	Object->AppNvm.DisplayMode = 1;
	Object->AppNvm.HUT_EgyRecvrySet = 1;

	Object->AppNvm.DriveModeStorageSwitch = FALSE;
	Object->AppNvm.DriveMode = 0;

	SWC_IPC_PRINT_INFO("Restore app nvm config work start!");
}

/**********************************************************************************************************
*Function   : IPC_API_SetRestoreSettingCallback                                                           *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Data                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-12                                                                                  *
**********************************************************************************************************/
void IPC_API_SetRestoreSettingCallback(uint8 *Data)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	IPC_S2M_InfraMiscRestoreFactorySettingRequset_t *Req = (IPC_S2M_InfraMiscRestoreFactorySettingRequset_t *)Data;

	/*Restore Factory Setting*/
	if (0x01 == Req->Request)
	{
		SWC_IPC_PRINT_INFO("Restore factory setting request from qnx-infrastructure!");

		if (Object->ClearDtcSwitch == SWC_IPC_CLEAR)
		{
			Object->ClearDtcSwitch = SWC_IPC_TRIGGERED;
		}

		if (Object->RestoreCanSwitch == SWC_IPC_CLEAR)
		{
			Object->RestoreCanSwitch = SWC_IPC_TRIGGERED;
		}

		if (Object->RestoreAppSwitch == SWC_IPC_CLEAR)
		{
			Object->RestoreAppSwitch = SWC_IPC_TRIGGERED;
		}

		Object->RestoreType = Req->Request; /*Restore factory setting*/

		SWC_IPC_CLEAR_BIT(Object->RestoreFlag , SWC_IPC_CLEAR_DTC);
		SWC_IPC_CLEAR_BIT(Object->RestoreFlag , SWC_IPC_RESTORE_CAN);
		SWC_IPC_CLEAR_BIT(Object->RestoreFlag , SWC_IPC_RESTORE_APP);
	}
	/*Restore Vehicle Setting*/
	else if (0x02 == Req->Request)
	{
		SWC_IPC_PRINT_INFO("Restore vehicle setting request from qnx-infrastructure!");

		if (Object->RestoreCanSwitch == SWC_IPC_CLEAR)
		{
			Object->RestoreCanSwitch = SWC_IPC_TRIGGERED;
		}

		if (Object->RestoreAppSwitch == SWC_IPC_CLEAR)
		{
			Object->RestoreAppSwitch = SWC_IPC_TRIGGERED;
		}

		Object->RestoreType = Req->Request; /*Restore vehicle setting*/

		SWC_IPC_CLEAR_BIT(Object->RestoreFlag , SWC_IPC_RESTORE_CAN);
		SWC_IPC_CLEAR_BIT(Object->RestoreFlag , SWC_IPC_RESTORE_APP);
	}
	/* Restore wisdom cruise */
	else if (0x03 == Req->Request)
	{
		SWC_IPC_PRINT_INFO("Restore wisdom cruise request from qnx-infrastructure!");

		if (Object->RestoreWisCruSwitch == SWC_IPC_CLEAR)
		{
			Object->RestoreWisCruSwitch = SWC_IPC_TRIGGERED;
		}

		Object->RestoreType = Req->Request; /*Restore wisdom cruise*/

		SWC_IPC_CLEAR_BIT(Object->RestoreFlag , SWC_IPC_RESTORE_WISDOMCRUISE);
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Invalid restore setting request from qnx-infrastructure!");
	}
}

/**********************************************************************************************************
*Function   : IPC_API_ReadSerialNumberCallback                                                            *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Data                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-16                                                                                  *
**********************************************************************************************************/
void IPC_API_ReadSerialNumberCallback(uint8 *Data)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	IPC_S2M_InfraMiscReadSerialNumberRequest_t *Req = (IPC_S2M_InfraMiscReadSerialNumberRequest_t *)Data;
	IPC_M2S_InfraMiscReadSerialNumberResponse_t Resp;

	(void)memset(&Resp, 0, sizeof(IPC_M2S_InfraMiscReadSerialNumberResponse_t));

	/*Request read serial number*/
	if (0x01 == Req->Request)
	{
		(void)Rte_Read_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C(Object->ProductInfo);
		Resp.DataLength = 20;
		(void)memcpy(&Resp.Data[0], &Object->ProductInfo[0], Resp.DataLength);

		/*Send respond*/
		IPC_API_AppMsgTransmit((uint8)M2S_READ_SERIAL_NUMBER_RESP, (uint8 *)&Resp, (uint16)sizeof(Resp), TRUE);

		SWC_IPC_PRINT_INFO("Read serial number request from qnx-infrastructure!");
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Invalid read serial number request from qnx-infrastructure! Request = %d",Req->Request);
	}
}

/**********************************************************************************************************
*Function   : IPC_API_ReadVINNumberCallback                                                            *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Data                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-16                                                                                  *
**********************************************************************************************************/
void IPC_API_ReadVINNumberCallback(uint8 *Data)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	IPC_S2M_InfraMiscReadVINNumberRequest_t *Req = (IPC_S2M_InfraMiscReadVINNumberRequest_t *)Data;
	IPC_M2S_InfraMiscReadVINNumberResponse_t Resp;

	(void)memset(&Resp, 0, sizeof(IPC_M2S_InfraMiscReadVINNumberResponse_t));

	/*Request read vin number*/
	if (0x01 == Req->Request)
	{
		Rte_Call_rpCS_SWCGateWay_GetVinNumber_Operation(&Object->VinNumber[0]);
		Resp.DataLength = 17;
		(void)memcpy(&Resp.Data[0], &Object->VinNumber[0], Resp.DataLength);

		/*Send respond*/
		IPC_API_AppMsgTransmit((uint8)M2S_READ_VIN_NUMBER_RESP, (uint8 *)&Resp, (uint16)sizeof(Resp), TRUE);

		(void)SWC_IPC_PRINT_DEBUG("Read vin number request from qnx-infrastructure!");
		#ifdef SWC_IPC_DEBUG
			IPC_API_PrintDataArrayDEBUGLog(&Object->VinNumber[0], Resp.DataLength);
		#endif
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Invalid read Vin number request from qnx-infrastructure! Request = %d",Req->Request);
	}
}



/**********************************************************************************************************
*Function   : IPC_API_WriteGaugesValueCallback                                                            *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Data                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-12-17                                                                                  *
**********************************************************************************************************/
void IPC_API_WriteGaugesValueCallback(uint8 *Data)
{
	IPC_S2M_ClusterAppClusterSocGauges_t *Req = (IPC_S2M_ClusterAppClusterSocGauges_t *)Data;

	(void)Rte_Write_ppSR_SWCGateWay_S2M_Information_SpeedValue(Req->VehicleSpeed);
	(void)Rte_Write_ppSR_SWCGateWay_S2M_Information_TachoValue(Req->EngineSpeed);

	SWC_IPC_PRINT_INFO("Write gauges value request from qnx-cluster!");
}

/**********************************************************************************************************
*Function   : IPC_API_GetInterfaceAppAliveCallback                                                        *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Data                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : DylanZhao                                                                                   *
*                                                                                                         *
*Date       : 2021-1-25                                                                                   *
**********************************************************************************************************/
void IPC_API_GetInterfaceAppAliveCallback(uint8 *Data)
{
	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	IPC_S2M_ClusterAppClusterSocInterfaceAppAlive_t *Req = (IPC_S2M_ClusterAppClusterSocInterfaceAppAlive_t *)Data;

	if (0xAA == Req->AliveTick)
	{
		if (FALSE == Object->AliveMonitor[SWC_IPC_INTERFACE_APP_MONITOR])
		{
			IPC_API_AppMsgTransmit((uint8)M2S_TPMS, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_SIA, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_ODOMETER, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_TRIP_COMPUTER, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_WARNING, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_FUEL, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_INTERNAL_CONFIG_UPLOAD, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_SAFTY_TELLTALE, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_TELLTALE, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);

			IPC_API_AppMsgTransmit((uint8)M2S_SET_OffroadInfo_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_NEWENERGY, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_NEWENERGY_EV, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_MenuSettingUpload(Object);

			IPC_API_AppMsgTransmit((uint8)M2S_CA_ECM3_371_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_CSA2_A1_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_ECM16_2D4_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_AC2_385_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_ECM_PT6_290_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_ABM2_245_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);
			IPC_API_AppMsgTransmit((uint8)M2S_CA_ECM24_350_RESP, SWC_IPC_NULL, SWC_IPC_NONE, TRUE);

			Object->AliveMonitor[SWC_IPC_INTERFACE_APP_MONITOR] = TRUE;
		}
		SWC_IPC_PRINT_INFO("Interface alive request from qnx-Interface!");
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Invalid Interface alive request from qnx-Interface! Value = %d",Req->AliveTick);
	}
}

/**********************************************************************************************************
*Function   : IPC_API_SetBeanIDReqCallback                                                           	  *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Data                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Chen Tuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-6-25                                                                                  *
**********************************************************************************************************/
void IPC_API_SetBeanIDReqCallback(uint8 *Data)
{
#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P05)\
 || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01)|| (defined SWC_IPC_PROJECT_TYPE_D02)|| \
 (defined SWC_IPC_PROJECT_TYPE_D03)

	SWC_IPC_AppMsgObject * Object = &SWC_IPC__AppMsgObject;
	IPC_S2M_InfraMiscReadBeanIDRequest_t *Req = (IPC_S2M_InfraMiscReadBeanIDRequest_t *)Data;

	/*BeanID request*/
	if (0x01 == Req->Request)
	{
		SWC_IPC_PRINT_INFO("BeanID request from qnx-infrastructure!");

		if (Object->u8BeanIDSwitch == SWC_IPC_CLEAR)
		{
			Object->u8BeanIDSwitch = SWC_IPC_TRIGGERED;
		}
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Invalid BeanID request request from qnx-infrastructure!");
	}
#endif
}

/**********************************************************************************************************
*Function   : IPC_API_SetAVASSwitchStatusCallback                                                           	  *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Data                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wang Naige                                                                                   *
*                                                                                                         *
*Date       : 2021-8-10                                                                                  *
**********************************************************************************************************/
void IPC_API_SetAVASSwitchStatusCallback(uint8 *Data)
{
#if ((defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_D01) ||\
	(defined SWC_IPC_PROJECT_TYPE_D02) || (defined SWC_IPC_PROJECT_TYPE_D03))

	IPC_S2M_InfraMiscSetAVASSwitchStatus_t *Req = (IPC_S2M_InfraMiscSetAVASSwitchStatus_t *)Data;

	Rte_Call_rpCS_SWCGateway_SetAVASSwitchSt_Operation(&Req->Switch);
#endif
}


/**********************************************************************************************************
*Function   : IPC_RestoreCanMonitor                                                                       *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Object                                                              					  	  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-03                                                                                  *
**********************************************************************************************************/
static void IPC_RestoreCanDataMonitor(SWC_IPC_AppMsgObject * Object)
{
	uint8 CountryFlag = 0U;
#define IPC_RESTORE_CAN_PHASE_1_DELAY (6000u/SWC_IPC_APPLICATION_TASK_CYCLE)
#define IPC_RESTORE_CAN_PHASE_2_DELAY (7000u/SWC_IPC_APPLICATION_TASK_CYCLE)
#define IPC_RESTORE_CAN_TIME_OUT_DELAY (30000u/SWC_IPC_APPLICATION_TASK_CYCLE)

	/*
	        |<-            Phase 1           ->|<-            Phase 2           ->|<-   Phase 3   ->|
    Start ->|<- Restore Can Nvm And Send Msg   |                                  |
                      Wait Nvm Block Updated ->|<-  Restore Can Nvm And Send Msg  |
                                                                                  |<- Finish
	*/
	CountryFlag = IPC_GetCountryProcess( Object);
	/*Restore can*/
	if (SWC_IPC_TRIGGERED == Object->RestoreCanSwitch)
	{
		SWC_IPC_PRINT_INFO("Restore tx can signal work start!");

		SWC_IPC_PRINT_INFO("Restore tx can signal phase 1 work start!");

		/*Can Signal*/
		if(2u == CountryFlag)
		{
			IPC_OS_RestoreTxCanSignalPhase1(Object);
		}
		else
		{
			IPC_RestoreTxCanSignalPhase1(Object);
		}

		Object->RestoreCanTick = 0;
		Object->RestoreCanPhase = 1;

		Object->RestoreCanSwitch = SWC_IPC_RUNNING;
	}
	else if (SWC_IPC_RUNNING == Object->RestoreCanSwitch)
	{
		if ((Object->RestoreCanTick >= IPC_RESTORE_CAN_PHASE_1_DELAY)
		 && (Object->RestoreCanPhase == 1))
		{
			SWC_IPC_PRINT_INFO("Restore tx can signal phase 2 work start!");

			if(2u == CountryFlag)
			{
				IPC_OS_RestoreTxCanSignalPhase2(Object);
			}
			else
			{
				IPC_RestoreTxCanSignalPhase2(Object);
			}


			Object->RestoreCanPhase = 2;
		}

		if ((Object->RestoreCanTick >= IPC_RESTORE_CAN_PHASE_2_DELAY)
		&& (Object->RestoreCanPhase == 2))
		{
			SWC_IPC_PRINT_INFO("Restore tx can signal phase 2 work done!");

			Object->RestoreCanPhase = 3;
		}

		if ((FALSE == IPC_API_ControlCanNvmSwitch(FALSE))
		 && (Object->RestoreCanPhase >= 3))
		{
			SWC_IPC_PRINT_INFO("Restore tx can nvm signal work done!");

			/*Current switch status is match target . Nvm write is done .*/
			Object->RestoreCanSwitch = SWC_IPC_DONE;
		}

		if (Object->RestoreCanTick >= IPC_RESTORE_CAN_TIME_OUT_DELAY)
		{
			/*State machine process timeout!*/
			SWC_IPC_PRINT_ERROR("Restore tx can setting faild!");

			Object->RestoreCanPhase = 0;
			Object->RestoreCanTick = 0;
			Object->RestoreCanSwitch = SWC_IPC_CLEAR;
		}
		else
		{
			Object->RestoreCanTick ++;
		}
	}
	else if (SWC_IPC_DONE == Object->RestoreCanSwitch)
	{
		if (TRUE == IPC_API_ControlCanNvmSwitch(TRUE))
		{
			SWC_IPC_PRINT_INFO("Restore tx can signal success! Spend time: %dms",Object->RestoreCanTick * SWC_IPC_APPLICATION_TASK_CYCLE);

			Object->RestoreCanPhase = 0;
			Object->RestoreCanTick = 0;
			Object->RestoreCanSwitch = SWC_IPC_CLEAR;
		}
	}
	else
	{
		Object->RestoreCanPhase = 0;
		Object->RestoreCanTick = 0;
		Object->RestoreCanSwitch = SWC_IPC_CLEAR;
	}
}

/**********************************************************************************************************
*Function   : IPC_RestoreCanMonitor                                                                       *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Object                                                              					  	  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-03                                                                                  *
**********************************************************************************************************/
static void IPC_RestoreWisdomCruiseDataMonitor(SWC_IPC_AppMsgObject * Object)
{
#define IPC_RESTORE_WISDOMCRUISE_PHASE_1_DELAY     (1000u/SWC_IPC_APPLICATION_TASK_CYCLE)
#define IPC_RESTORE_WISDOMCRUISE_TIME_OUT_DELAY    (10000u/SWC_IPC_APPLICATION_TASK_CYCLE)

	/* Restore CruiseData */
	if (SWC_IPC_TRIGGERED == Object->RestoreWisCruSwitch)
	{
		SWC_IPC_PRINT_INFO("Restore 3 work start!");

		/* Wisdom Cruise Can Signal */
		if(2u == IPC_GetCountryProcess(Object))
		{
			IPC_OS_RestoreWisdomCruise(Object);
		}
		else
		{
			IPC_RestoreWisdomCruise(Object);
		}

		Object->RestoreWisCruTick = 0;
		Object->RestoreWisCruPhase = 1;

		Object->RestoreWisCruSwitch = SWC_IPC_RUNNING;
	}
	else if (SWC_IPC_RUNNING == Object->RestoreWisCruSwitch)
	{
		if ((Object->RestoreWisCruTick >= IPC_RESTORE_WISDOMCRUISE_PHASE_1_DELAY)
		&& (Object->RestoreWisCruPhase == 1))
		{
			Object->RestoreWisCruPhase = 2;
		}

		if ((FALSE == IPC_API_ControlCanNvmSwitch(FALSE))
		 && (Object->RestoreWisCruPhase >= 2))
		{
			/*Current switch status is match target . Nvm write is done .*/
			Object->RestoreWisCruSwitch = SWC_IPC_DONE;
		}

		if (Object->RestoreWisCruTick >= IPC_RESTORE_WISDOMCRUISE_TIME_OUT_DELAY)
		{
			/*State machine process timeout!*/
			SWC_IPC_PRINT_ERROR("Restore 3 faild!");

			Object->RestoreWisCruPhase = 0;
			Object->RestoreWisCruTick = 0;
			Object->RestoreWisCruSwitch = SWC_IPC_CLEAR;
		}
		else
		{
			Object->RestoreWisCruTick ++;
		}
	}
	else if (SWC_IPC_DONE == Object->RestoreWisCruSwitch)
	{
		if (TRUE == IPC_API_ControlCanNvmSwitch(TRUE))
		{
			SWC_IPC_PRINT_INFO("Restore 3 success!Time: %dms",Object->RestoreWisCruTick * SWC_IPC_APPLICATION_TASK_CYCLE);

			Object->RestoreWisCruPhase = 0;
			Object->RestoreWisCruTick = 0;
			Object->RestoreWisCruSwitch = SWC_IPC_CLEAR;
		}
	}
	else
	{
		Object->RestoreWisCruPhase = 0;
		Object->RestoreWisCruTick = 0;
		Object->RestoreWisCruSwitch = SWC_IPC_CLEAR;
	}
}

/**********************************************************************************************************
*Function   : IPC_SetTxCanSignalToApp                                                                     *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Object                                                              					  	  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Wang Naige                                                                                  *
*                                                                                                         *
*Date       : 2021-11-18                                                                                  *
**********************************************************************************************************/
static void IPC_SetTxCanSignalToApp(SWC_IPC_AppMsgObject * Object)
{
#if (!defined SWC_IPC_PROJECT_TYPE_A07)
	uint8 data = 0;

	(void)Object;

	IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DVRRemtCnSts, &data);
	(void)Rte_Write_AWakeHold_DVRRemtCnSts(data);
#endif
}

/**********************************************************************************************************
*Function   : IPC_BeanIDCanDataMonitor                                                                    *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Object                                                              					  	  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Chen Tuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-6-25                                                                                  *
**********************************************************************************************************/
static void IPC_BeanIDCanDataMonitor(SWC_IPC_AppMsgObject * Object)
{
#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_A07) || (defined SWC_IPC_PROJECT_TYPE_P05) \
	|| (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_D01)|| (defined SWC_IPC_PROJECT_TYPE_D02)|| \
	(defined SWC_IPC_PROJECT_TYPE_D03)

#define IPC_BEANIDREQ_CAN_PHASE_1_DELAY (2000u/SWC_IPC_APPLICATION_TASK_CYCLE)
#define IPC_BEANIDREQ_CAN_TIME_OUT_DELAY (10000u/SWC_IPC_APPLICATION_TASK_CYCLE)

#define SWC_IPC_BEANIDREQ_REPEAT_TIMES   0x3u

#define SWC_IPC_ValidIDBytesNumber  0x7u

#define SWC_IPC_FRAMEPHASE1          	 0x1u
#define SWC_IPC_FRAMEPHASE2          	 0x2u
#define SWC_IPC_FRAMEPHASE3          	 0x3u
#define SWC_IPC_FRAMEINVAILD          	 0xFFu


    IPC_M2S_InfraMiscReadBeanIDResponse_t stIPC_M2S_InfraMiscReadBeanIDResp = {0};

	uint8 u8Data[1];

	uint8 u8BeanID[8];
	uint8 u8Ret;


	if (SWC_IPC_TRIGGERED == Object->u8BeanIDSwitch)
	{
		(void)SWC_IPC_PRINT_DEBUG("BeanID Request work start!");

		u8Data[0] = 0x1; /* 0x1:Requests */
		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BeanIDReq, u8Data);

		Object->u16BeanIDReqTick = 0;
		Object->u16BeanIDReqPhase = 1;
		Object->u8BeanIDInvalidStatus = 0u;

		(void)memset(&Object->u8BeanID[0],0,sizeof(Object->u8BeanID));

		Object->u8BeanIDSwitch = SWC_IPC_RUNNING;
	}
	else if (SWC_IPC_RUNNING == Object->u8BeanIDSwitch)
	{
		if (Object->u16BeanIDReqTick <= IPC_BEANIDREQ_CAN_PHASE_1_DELAY)
		{
			if(Object->u16BeanIDReqPhase == 1)
			{

				/*Can Signal*/
				u8Ret = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BLE_BEANID, (uint8 *)&u8BeanID[0], (uint8)sizeof(u8BeanID));

				if((RTE_E_OK == u8Ret) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == u8Ret))
				{

					if(SWC_IPC_FRAMEPHASE1 == u8BeanID[0])
					{
						(void)memcpy(&Object->u8BeanID[0] , &u8BeanID[1] , SWC_IPC_ValidIDBytesNumber );
						Object->u16BeanIDReqPhase = 2;
					}
				}
			}

			if(Object->u16BeanIDReqPhase == 2)
			{

				/*Can Signal*/
				u8Ret = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BLE_BEANID, (uint8 *)&u8BeanID[0], (uint8)sizeof(u8BeanID));
				if((RTE_E_OK == u8Ret) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == u8Ret))
				{

					if(SWC_IPC_FRAMEPHASE2 == u8BeanID[0])
					{
						(void)memcpy(&Object->u8BeanID[7] , &u8BeanID[1] , SWC_IPC_ValidIDBytesNumber );
						Object->u16BeanIDReqPhase = 3;
					}
				}
			}

			if(Object->u16BeanIDReqPhase == 3)
			{
				/*Can Signal*/
				u8Ret = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BLE_BEANID,(uint8 *)&u8BeanID[0], (uint8)sizeof(u8BeanID));
				if((RTE_E_OK == u8Ret) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == u8Ret))
				{

					if(SWC_IPC_FRAMEPHASE3 == u8BeanID[0])
					{
						(void)memcpy(&Object->u8BeanID[14] , &u8BeanID[1] , SWC_IPC_ValidIDBytesNumber );
						Object->u8BeanIDSwitch = SWC_IPC_DONE;
					}
				}
			}
		}
		else
		{
			if(Object->u8BeanIDReqtimes <= 1)
			{
				Object->u8BeanIDReqtimes++;
				if(SWC_IPC_DONE != Object->u8BeanIDSwitch)
				{
					Object->u8BeanIDSwitch = SWC_IPC_TRIGGERED;
				}
			}
			else
			{
				if(SWC_IPC_DONE != Object->u8BeanIDSwitch)
				{
					SWC_IPC_PRINT_ERROR("BeanID Request faild!");

					Object->u8BeanIDSwitch = SWC_IPC_DONE;

					Object->u8BeanIDInvalidStatus = 1u;
				}
			}
		}

		if (Object->u16BeanIDReqTick >= IPC_BEANIDREQ_CAN_TIME_OUT_DELAY)
		{
			/*State machine process timeout!*/
			SWC_IPC_PRINT_ERROR("BeanID Request faild!");

			Object->u16BeanIDReqPhase = 0;
			Object->u16BeanIDReqTick = 0;
			Object->u8BeanIDReqtimes = 0;
			Object->u8BeanIDInvalidStatus = 0u;
			(void)memset(&Object->u8BeanID[0],0,sizeof(Object->u8BeanID));

			Object->u8BeanIDSwitch = SWC_IPC_CLEAR;
		}
		else
		{
			Object->u16BeanIDReqTick ++;
		}
	}
	else if (SWC_IPC_DONE == Object->u8BeanIDSwitch)
	{
	     stIPC_M2S_InfraMiscReadBeanIDResp.Status = (uint8)Object->u8BeanIDInvalidStatus;

	    if((uint8)1 == Object->u8BeanIDInvalidStatus)
	    {
	        stIPC_M2S_InfraMiscReadBeanIDResp.DataLength = 0;
	    }
	    else
	    {
            (void)memcpy(&stIPC_M2S_InfraMiscReadBeanIDResp.Data[0] , &Object->u8BeanID[0] , sizeof(Object->u8BeanID));
	        stIPC_M2S_InfraMiscReadBeanIDResp.DataLength = (uint16)sizeof(Object->u8BeanID);
	    }

		/*Send respond*/
		IPC_API_AppMsgTransmit((uint8)M2S_ReadBeanID_RESP, (uint8 *)&stIPC_M2S_InfraMiscReadBeanIDResp, (uint16)sizeof(stIPC_M2S_InfraMiscReadBeanIDResp), TRUE);

		#ifdef SWC_IPC_DEBUG
		IPC_API_PrintDataArrayLog(&Object->u8BeanID[0] , sizeof(Object->u8BeanID));
		#endif

		u8Data[0] = 0x2; /* 0x2:Clear data */
		IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_HUT_BeanIDReq, u8Data);

		SWC_IPC_PRINT_INFO("BeanID Request end of the process!");

		Object->u16BeanIDReqPhase = 0;
		Object->u16BeanIDReqTick = 0;
		Object->u8BeanIDReqtimes = 0;
		Object->u8BeanIDInvalidStatus = 0u;
		(void)memset(&Object->u8BeanID[0],0,sizeof(Object->u8BeanID));

		Object->u8BeanIDSwitch = SWC_IPC_CLEAR;

	}
	else
	{
		Object->u16BeanIDReqPhase = 0;
		Object->u16BeanIDReqTick = 0;
		Object->u8BeanIDReqtimes = 0;
		Object->u8BeanIDInvalidStatus = 0u;
		(void)memset(&Object->u8BeanID[0],0,sizeof(Object->u8BeanID));

		Object->u8BeanIDSwitch = SWC_IPC_CLEAR;
	}

#endif
}


/**********************************************************************************************************
*Function   : IPC_RestoreAppMonitor                                                                       *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Object                                                              					  	  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-03                                                                                  *
**********************************************************************************************************/
static void IPC_RestoreAppDataMonitor(SWC_IPC_AppMsgObject * Object)
{
#define IPC_RESTORE_APP_PHASE_1_DELAY (1000u/SWC_IPC_APPLICATION_TASK_CYCLE)
#define IPC_RESTORE_APP_PHASE_2_DELAY (2000u/SWC_IPC_APPLICATION_TASK_CYCLE)
#define IPC_RESTORE_APP_TIME_OUT_DELAY (30000u/SWC_IPC_APPLICATION_TASK_CYCLE)

	/*
	        |<-      Phase 1     ->|<-        Phase 2       ->|<-   Phase 3   ->|
    Start ->|<- Restore App Nvm    |                          |
          Wait Nvm Block Updated ->|<- Update Whud Config     |
                                                              |<- Finish
	*/
	if (SWC_IPC_TRIGGERED == Object->RestoreAppSwitch)
	{
		SWC_IPC_PRINT_INFO("Restore app setting work start!");

		IPC_RestoreAppNvmConfig(Object);

		Object->RestoreAppTick = 0;
		Object->RestoreAppPhase = 1;
		Object->RestoreAppSwitch = SWC_IPC_RUNNING;
	}
	else if (SWC_IPC_RUNNING == Object->RestoreAppSwitch)
	{
		if ((Object->RestoreAppTick >= IPC_RESTORE_APP_PHASE_1_DELAY)
		 && (Object->RestoreAppPhase == 1))
		{
			/*WHUD*/
			IPC_WhudNvmConfigUpdate(Object);
			IPC_WhudNvmConfigUpload(Object);

			/*DriveModeStorageSwitch*/
			IPC_DriveModeStorageSwitchUpload(Object);
			Object->RestoreAppPhase = 2;
		}

		if ((Object->RestoreAppTick >= IPC_RESTORE_APP_PHASE_2_DELAY)
		&& (Object->RestoreAppPhase == 2))
		{
			Object->RestoreAppPhase = 3;
		}

		if ((FALSE == IPC_API_ControlAppNvmSwitch(FALSE))
		 && (Object->RestoreAppPhase >= 3))
		{
			SWC_IPC_PRINT_INFO("Restore app nvm work done!");
			/*Current switch status is match target . Nvm write is done .*/
			Object->RestoreAppSwitch = SWC_IPC_DONE;
		}

		if (Object->RestoreAppTick >= IPC_RESTORE_APP_TIME_OUT_DELAY)
		{
			/*State machine process timeout!*/
			SWC_IPC_PRINT_ERROR("Restore app setting faild!");
			Object->RestoreAppPhase = 0;
			Object->RestoreAppTick = 0;
			Object->RestoreAppSwitch = SWC_IPC_CLEAR;
		}
		else
		{
			Object->RestoreAppTick ++;
		}
	}
	else if (SWC_IPC_DONE == Object->RestoreAppSwitch)
	{
		if (TRUE == IPC_API_ControlAppNvmSwitch(TRUE))
		{
			SWC_IPC_PRINT_INFO("Restore app setting success! Spend time: %dms",Object->RestoreAppTick * SWC_IPC_APPLICATION_TASK_CYCLE);

			Object->RestoreAppPhase = 0;
			Object->RestoreAppTick = 0;
			Object->RestoreAppSwitch = SWC_IPC_CLEAR;
		}
	}
	else
	{
		Object->RestoreAppPhase = 0;
		Object->RestoreAppTick = 0;
		Object->RestoreAppSwitch = SWC_IPC_CLEAR;
	}
}

/**********************************************************************************************************
*Function   : IPC_RestoreDataMonitor                                                                      *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : Object                                                              					  	  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-02                                                                                  *
**********************************************************************************************************/
static void IPC_RestoreDataMonitor(SWC_IPC_AppMsgObject * Object)
{
	IPC_M2S_InfraMiscRestoreFactorySettingResponse_t Resp;

	/*Sub monitor */
	IPC_RestoreCanDataMonitor(Object);

	IPC_RestoreAppDataMonitor(Object);

	IPC_RestoreWisdomCruiseDataMonitor(Object);

	/*Set flag*/
	if (SWC_IPC_DONE == Object->ClearDtcSwitch)
	{
		SWC_IPC_SET_BIT(Object->RestoreFlag , (uint8)SWC_IPC_CLEAR_DTC); /*Bit0*/
	}

	if (SWC_IPC_DONE == Object->RestoreCanSwitch)
	{
		SWC_IPC_SET_BIT(Object->RestoreFlag , (uint8)SWC_IPC_RESTORE_CAN); /*Bit1*/
	}

	if (SWC_IPC_DONE == Object->RestoreAppSwitch)
	{
		SWC_IPC_SET_BIT(Object->RestoreFlag , (uint8)SWC_IPC_RESTORE_APP); /*Bit2*/
	}

	if (SWC_IPC_DONE == Object->RestoreWisCruSwitch)
	{
		SWC_IPC_SET_BIT(Object->RestoreFlag , (uint8)SWC_IPC_RESTORE_WISDOMCRUISE); /*Bit3*/
	}

	/*Restore factory setting*/
	if (0x01 == Object->RestoreType)
	{
		if ((SWC_IPC_TEST_BIT (Object->RestoreFlag , (uint8)SWC_IPC_CLEAR_DTC))
		 && (SWC_IPC_TEST_BIT (Object->RestoreFlag , (uint8)SWC_IPC_RESTORE_CAN))
		 && (SWC_IPC_TEST_BIT (Object->RestoreFlag , (uint8)SWC_IPC_RESTORE_APP)))
		{
			/*Restore success*/
			Resp.Response = Object->RestoreType;
			IPC_API_AppMsgTransmit((uint8)M2S_RESTORE_FACTORY_RESP, (uint8 *)&Resp, (uint16)sizeof(Resp), TRUE);
			/*Clear restore type*/
			Object->RestoreType = 0;
			/*Clear restore flag*/
			SWC_IPC_CLEAR_BIT(Object->RestoreFlag , (uint8)SWC_IPC_CLEAR_DTC);
			SWC_IPC_CLEAR_BIT(Object->RestoreFlag , (uint8)SWC_IPC_RESTORE_CAN);
			SWC_IPC_CLEAR_BIT(Object->RestoreFlag , (uint8)SWC_IPC_RESTORE_APP);

			SWC_IPC_PRINT_INFO("Restore factory setting success!");
		}
	}
	else if (0x02 == Object->RestoreType)
	{
		if ((SWC_IPC_TEST_BIT (Object->RestoreFlag , (uint8)SWC_IPC_RESTORE_CAN))
		 && (SWC_IPC_TEST_BIT (Object->RestoreFlag , (uint8)SWC_IPC_RESTORE_APP)))
		{
			/*Restore success*/

			Resp.Response = Object->RestoreType;
			IPC_API_AppMsgTransmit((uint8)M2S_RESTORE_FACTORY_RESP, (uint8 *)&Resp, (uint16)sizeof(Resp), TRUE);
			/*Clear restore type*/
			Object->RestoreType = 0;
			/*Clear restore flag*/
			SWC_IPC_CLEAR_BIT(Object->RestoreFlag , (uint8)SWC_IPC_RESTORE_CAN);
			SWC_IPC_CLEAR_BIT(Object->RestoreFlag , (uint8)SWC_IPC_RESTORE_APP);

			SWC_IPC_PRINT_INFO("Restore vehicle setting success!");
		}
	}
	else if (0x03 == Object->RestoreType)
	{
		if (SWC_IPC_TEST_BIT (Object->RestoreFlag , (uint8)SWC_IPC_RESTORE_WISDOMCRUISE))
		{
			/*Restore success*/

			Resp.Response = Object->RestoreType;
			IPC_API_AppMsgTransmit((uint8)M2S_RESTORE_FACTORY_RESP, (uint8 *)&Resp, (uint16)sizeof(Resp), TRUE);
			/*Clear restore type*/
			Object->RestoreType = 0;
			/*Clear restore flag*/
			SWC_IPC_CLEAR_BIT(Object->RestoreFlag , (uint8)SWC_IPC_RESTORE_WISDOMCRUISE);

			SWC_IPC_PRINT_INFO("Restore wisdom cruise success!");
		}
	}
	else
	{

	}
}


/**********************************************************************************************************
*Function   : IPC_GetCountryProcess                                                                   	  *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * Object                                               				  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     :Xu                                                                                    		  *
*                                                                                                         *
*Date       : 2022-01-21                                                                                  *
**********************************************************************************************************/
static uint8 IPC_GetCountryProcess(SWC_IPC_AppMsgObject * Object )
{
	uint8 CountryVehicleFlag = 0U;

	if(0x0 == Object->VehicleConfig[VCONFIG_KIND_REGIONAL])
	{
		CountryVehicleFlag = 1U; /* 国内 */
	}
	else if((Object->VehicleConfig[VCONFIG_KIND_REGIONAL] > 0x0) && (Object->VehicleConfig[VCONFIG_KIND_REGIONAL] <= 0x8 ))
	{
		CountryVehicleFlag = 2U; /* 国外 */
	}
	else
	{
		CountryVehicleFlag = 3U; /* 无效配置 */
	}

	return CountryVehicleFlag;
}

/**********************************************************************************************************
*Function   : IPC_API_PrintDataArrayLog                                                                   *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint8 * const Data ,const uint32 Length                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-12-29                                                                                  *
**********************************************************************************************************/
#ifdef SWC_IPC_DEBUG
void IPC_API_PrintDataArrayLog(const uint8 * const Data ,const uint32 Length)
{
#define IPC_LINE_WORDS_NUMBER  16

	char LogBuffer[IPC_LINE_WORDS_NUMBER * 3 + 1] = {0};
	char NumberBuffer[4] = {0};
	uint8 Index , LogIndex = 0;

	(void)memset(&LogBuffer[0], 0, sizeof(LogBuffer));

	if (Length > 0)
	{
		for(Index = 0u; Index < Length; Index ++)
	    {
	    	(void)memset(&NumberBuffer[0], 0, sizeof(NumberBuffer));
			(void)sprintf(NumberBuffer, "%02X ", Data[Index]);
			(void)strcat(LogBuffer, NumberBuffer);
			LogIndex += 1;

			if ((LogIndex >= IPC_LINE_WORDS_NUMBER) || (Index == (Length -1)))
			{
				(void)SWC_IPC_PRINT_VERBOSE("%s", LogBuffer);

				(void)memset(&LogBuffer[0], 0, sizeof(LogBuffer));
				LogIndex = 0;
			}
	    }
	}
}
#endif
/**********************************************************************************************************
*Function   : IPC_API_PrintDataArrayDEBUGLog                                                              *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint8 * const Data ,const uint32 Length                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Chen Tuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-12-13                                                                                  *
**********************************************************************************************************/
#ifdef SWC_IPC_DEBUG
static void IPC_API_PrintDataArrayDEBUGLog(const uint8 * const Data ,const uint32 Length)
{
#define IPC_LINE_WORDS_NUMBER  16

	char LogBuffer[IPC_LINE_WORDS_NUMBER * 3 + 1] = {0};
	char NumberBuffer[4] = {0};
	uint8 Index , LogIndex = 0;

	(void)memset(&LogBuffer[0], 0, sizeof(LogBuffer));

	if (Length > 0)
	{
		for(Index = 0u; Index < Length; Index ++)
	    {
	    	(void)memset(&NumberBuffer[0], 0, sizeof(NumberBuffer));
			(void)sprintf(NumberBuffer, "%02X ", Data[Index]);
			(void)strcat(LogBuffer, NumberBuffer);
			LogIndex += 1;

			if ((LogIndex >= IPC_LINE_WORDS_NUMBER) || (Index == (Length -1)))
			{
				(void)SWC_IPC_PRINT_DEBUG("%s", LogBuffer);

				(void)memset(&LogBuffer[0], 0, sizeof(LogBuffer));
				LogIndex = 0;
			}
	    }
	}
}
#endif
/**********************************************************************************************************
*Function   : IPC_Test                                                                                    *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * const Object                                                         *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-15                                                                                  *
**********************************************************************************************************/
#ifdef SWC_IPC_DEBUG
static void IPC_Test(SWC_IPC_AppMsgObject * const Object)
{
	(void)Object;
#if 0
	uint8 Data[4] = {0};

	if (Object->Button != Object->LastButton)
	{
		if (Object->RestoreAppSwitch == SWC_IPC_CLEAR)
		{
			Object->RestoreAppSwitch = SWC_IPC_TRIGGERED;
		}
	}
	Object->LastButton = Object->Button;
#endif
}
#endif

/**********************************************************************************************************
*Function   : IPC_AppMonitor                                                                              *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_AppMsgObject * const Object                                                         *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-08                                                                                  *
**********************************************************************************************************/
#ifdef SWC_IPC_DEBUG
static void IPC_AppMonitor(SWC_IPC_AppMsgObject * const Object)
{
	/*Check nvm block size */
	if (SWC_IPC_CONFIG_NVM_SIZE < sizeof(Object->AppNvm))
	{
		if (!(boolean)SWC_IPC_TEST_BIT(Object->Error, (uint32)SWC_IPC_ERROR_NVM_SIZE_DEFINE_WRONG))
		{
			SWC_IPC_PRINT_ERROR("App nvm block size is check error!");

			SWC_IPC_SET_BIT(Object->Error, (uint32)SWC_IPC_ERROR_NVM_SIZE_DEFINE_WRONG);
		}
	}
}
#endif
#define SWC_IPC_NW_STOP_SEC_CODE
#include "SWC_IPC_NW_MemMap.h"
/**********************************************************************************************************
*                                                                                    					  *
**********************************************************************************************************/

/**********************************************************************************************************
**
**  Revision : 2.0
**
**  Author   : HenryChan , Cao Wenping
**
**  Date     : 2020/07/10  1.0    Original Version.    Cao Wenping
**             2020/08/06  2.0    Firmwork Update.     HenryChan
**
**********************************************************************************************************/

/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/
