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
*File Name   : AL_Process.c                                                                               *
*                                                                                                         *
*Description : Ambient Light module logic process source file.                                            *
*                                                                                                         *
*Author      :                                                                                            *
*                                                                                                         *
*Platform    : Free Rtos System                                                    						  *
*                                                                                                         *
*Compiler    : Green Hills MULTI IDE                                                                      *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family                                                       *
*                                                                                                         *
*Version     : 1.0.0                                                                                      *
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/


/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "stddef.h" /* NULL */
#include <string.h> /* memset */

#include "SWC_AL_Interface.h"
#include "SWC_AL_Adapt.h"
#include "SWC_AL_Core.h"
#include "SWC_AL_Process.h"


#define Common_GateWay_START_SEC_VAR_INIT_UNSPECIFIED
#include  "Common_GateWay_MemMap.h"

static AL_SignalList_t  ALCM_SigGroup_St = {0};
//static uint8 Pre_Direction_U8 = 0;
static uint8 Flag_PM25Pollution_U8 = 0;

#define Common_GateWay_STOP_SEC_VAR_INIT_UNSPECIFIED
#include  "Common_GateWay_MemMap.h"

#define Common_GateWay_START_SEC_CODE
#include  "Common_GateWay_MemMap.h"

static void ALCM_GetSignalProcess(void);

static void ALCM_GetSignalProcess(void)
{
	ALCM_SigGroup_St.ALCM_AEB_VehTrig.CurrentSigStat = FALCM_Adapt_GetSig_AEB_VehTrig(&ALCM_SigGroup_St.ALCM_AEB_VehTrig.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_AEB_PedTrig.CurrentSigStat = FALCM_Adapt_GetSig_AEB_PedTrig(&ALCM_SigGroup_St.ALCM_AEB_PedTrig.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_AEB_JA_Warn.CurrentSigStat = FALCM_Adapt_GetSig_AEB_JA_Warn(&ALCM_SigGroup_St.ALCM_AEB_JA_Warn.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.CurrentSigStat = FALCM_Adapt_GetSig_AEB_JABrkTrig(&ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_FCW_Warn.CurrentSigStat = FALCM_Adapt_GetSig_FCW_Warn(&ALCM_SigGroup_St.ALCM_FCW_Warn.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_FCTBTrig.CurrentSigStat = FALCM_Adapt_GetSig_FCTBTrig(&ALCM_SigGroup_St.ALCM_FCTBTrig.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_FCTA_Warn.CurrentSigStat = FALCM_Adapt_GetSig_FCTA_Warn(&ALCM_SigGroup_St.ALCM_FCTA_Warn.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_LCA_WarnR.CurrentSigStat = FALCM_Adapt_GetSig_BSD_LCA_warningReqRight(&ALCM_SigGroup_St.ALCM_LCA_WarnR.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_LCA_WarnL.CurrentSigStat = FALCM_Adapt_GetSig_BSD_LCA_warningReqleft(&ALCM_SigGroup_St.ALCM_LCA_WarnL.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_DOW_WarnR.CurrentSigStat = FALCM_Adapt_GetSig_DOW_warningReqRight(&ALCM_SigGroup_St.ALCM_DOW_WarnR.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_DOW_WarnL.CurrentSigStat = FALCM_Adapt_GetSig_DOW_warningReqleft(&ALCM_SigGroup_St.ALCM_DOW_WarnL.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_DrvDoorSts.CurrentSigStat = FALCM_Adapt_GetSig_DrvDoorSts(&ALCM_SigGroup_St.ALCM_DrvDoorSts.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_PassengerDoorSts.CurrentSigStat = FALCM_Adapt_GetSig_PassengerDoorSts(&ALCM_SigGroup_St.ALCM_PassengerDoorSts.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_LRDoorSts.CurrentSigStat = FALCM_Adapt_GetSig_LRDoorSts(&ALCM_SigGroup_St.ALCM_LRDoorSts.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_RRDoorSts.CurrentSigStat = FALCM_Adapt_GetSig_RRDoorSts(&ALCM_SigGroup_St.ALCM_RRDoorSts.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_ACDrvTemp.CurrentSigStat = FALCM_Adapt_GetSig_ACDrvTemp_ATC(&ALCM_SigGroup_St.ALCM_ACDrvTemp.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_ACFrntPasstTemp.CurrentSigStat = FALCM_Adapt_GetSig_ACFrntPasstTemp_ATC(&ALCM_SigGroup_St.ALCM_ACFrntPasstTemp.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_PM25InDens.CurrentSigStat = FALCM_Adapt_GetSig_L_PM25InDens(&ALCM_SigGroup_St.ALCM_PM25InDens.CurrentSigValue);
}

void ALCM_GetConfigProcess(AL_EventRunningObject_t *runObject)
{
	// AL_ConfigList_t *AlcmConfig = runObject->AlcmConfig;
	AL_EventRunningObject_t *eventRunningObject = (AL_EventRunningObject_t*)runObject;
	uint8 InputConfig = 0;
	VconfigKind_Allbuffers ConfigAdr;

	(void)Rte_Read_Vconfig_GetKindBuffers_AllKinds(ConfigAdr);

	InputConfig = 0;
	InputConfig = ConfigAdr[VCONFIG_KIND_INIT_FLAG];
	eventRunningObject->AlcmConfig.Cfg_NvmInitflag = InputConfig;

	InputConfig = 0;
	InputConfig = ConfigAdr[VCONFIG_KIND_MOOD_LAMP_PARTITION];
	eventRunningObject->AlcmConfig.Cfg_MLPConfig = InputConfig;

	InputConfig = 0;
	InputConfig = ConfigAdr[VCONFIG_KIND_DRIVE_HANDLE_TYPE];
	if(1 == InputConfig)
	{
		eventRunningObject->AlcmConfig.Cfg_LeftDriverDoor = 1;
	}
	else
	{
		eventRunningObject->AlcmConfig.Cfg_LeftDriverDoor = 0;
	}

	InputConfig = 0;
	InputConfig = ConfigAdr[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING];
	if(0 != InputConfig)
	{
		eventRunningObject->AlcmConfig.Cfg_AEBVehicleEnable = 1;
		if((0x4 == InputConfig) || (0x5 == InputConfig))
		{
			eventRunningObject->AlcmConfig.Cfg_AEBPedestrianEnable = 1;
		}
		else
		{
			eventRunningObject->AlcmConfig.Cfg_AEBPedestrianEnable = 0;
		}

		if((0 < InputConfig) && (6 > InputConfig))
		{
			eventRunningObject->AlcmConfig.Cfg_FCWEnable = 1;
		}
		else
		{
			eventRunningObject->AlcmConfig.Cfg_FCWEnable = 0;
		}
	}
	else
	{
		eventRunningObject->AlcmConfig.Cfg_AEBVehicleEnable = 0;
		eventRunningObject->AlcmConfig.Cfg_AEBPedestrianEnable = 0;
	}

	InputConfig = 0;
	InputConfig = ConfigAdr[VCONFIG_KIND_AEB_JUNCTION_ASSIST];
	if(1 == InputConfig)
	{
		eventRunningObject->AlcmConfig.Cfg_AEBJABrkEnable = 1;
	}
	else
	{
		eventRunningObject->AlcmConfig.Cfg_AEBJABrkEnable = 0;
	}

	InputConfig = 0;
	InputConfig = ConfigAdr[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK];
	if((1 == InputConfig) || (2 == InputConfig))
	{
		eventRunningObject->AlcmConfig.Cfg_FCTEnable = 1;
	}
	else
	{
		eventRunningObject->AlcmConfig.Cfg_FCTEnable = 0;
	}

	InputConfig = 0;
	InputConfig = ConfigAdr[VCONFIG_KIND_LANE_CHANGE_ASSIST];
	eventRunningObject->AlcmConfig.Cfg_LCAEnable = InputConfig;
	eventRunningObject->AlcmConfig.Cfg_DOWEnable = InputConfig;

	InputConfig = 0;
	InputConfig = ConfigAdr[VCONFIG_KIND_AIR_CONDITIONER];
	if(3 == InputConfig)
	{
		eventRunningObject->AlcmConfig.Cfg_AirCondition = AL_SINGLE_AIRCONDITION;
	}
	else if(((4 <= InputConfig) && (8 >= InputConfig)) || ((11 <= InputConfig) && (19 >= InputConfig)))
	{
		eventRunningObject->AlcmConfig.Cfg_AirCondition = AL_DOUBLE_AIRCONDITION;
	}
	else
	{
		eventRunningObject->AlcmConfig.Cfg_AirCondition = 0;
	}

	InputConfig = 0;
	InputConfig = ConfigAdr[VCONFIG_KIND_AIR_PURIFIER];
	if((2 == InputConfig) || (3 == InputConfig) || (5 == InputConfig) || (7 == InputConfig))
	{
		eventRunningObject->AlcmConfig.Cfg_PM25Enable = 1;
	}
	else
	{
		eventRunningObject->AlcmConfig.Cfg_PM25Enable = 0;
	}

	(void)SWC_IPC_PRINT_DEBUG("AlcmCfg:%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
						runObject->AlcmConfig.Cfg_NvmInitflag,
						runObject->AlcmConfig.Cfg_MLPConfig,
						runObject->AlcmConfig.Cfg_LeftDriverDoor,
						runObject->AlcmConfig.Cfg_AEBVehicleEnable,
						runObject->AlcmConfig.Cfg_AEBPedestrianEnable,
						runObject->AlcmConfig.Cfg_AEBJABrkEnable,
						runObject->AlcmConfig.Cfg_FCWEnable,
						runObject->AlcmConfig.Cfg_FCTEnable,
						runObject->AlcmConfig.Cfg_LCAEnable,
						runObject->AlcmConfig.Cfg_DOWEnable,
						runObject->AlcmConfig.Cfg_AirCondition,
						runObject->AlcmConfig.Cfg_PM25Enable);
}

void ALCM_AppCommonProcess(const AL_EventRunningObject_t * const runObject)
{
	(void)runObject;
	ALCM_GetSignalProcess();
}

void AL_TransExitNormal(const AL_EventRunningObject_t * const runObject)
{
	AL_OutputValueGet_NONE((uint8*)runObject);
	/* When KL15 OFF or b_ALCMPartitionSwt = 0, below signal = 0 */
	ALCM_SigGroup_St.ALCM_AEB_VehTrig.CurrentSigValue = 0;
	ALCM_SigGroup_St.ALCM_AEB_PedTrig.CurrentSigValue = 0;
	ALCM_SigGroup_St.ALCM_AEB_JA_Warn.CurrentSigValue = 0;
	ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.CurrentSigValue = 0;
	ALCM_SigGroup_St.ALCM_FCW_Warn.CurrentSigValue = 0;
	ALCM_SigGroup_St.ALCM_FCTBTrig.CurrentSigValue = 0;
	ALCM_SigGroup_St.ALCM_FCTA_Warn.CurrentSigValue = 0;
	ALCM_SigGroup_St.ALCM_LCA_WarnR.CurrentSigValue = 0;
	ALCM_SigGroup_St.ALCM_LCA_WarnL.CurrentSigValue = 0;
	ALCM_SigGroup_St.ALCM_DOW_WarnR.CurrentSigValue = 0;
	ALCM_SigGroup_St.ALCM_DOW_WarnL.CurrentSigValue = 0;
	ALCM_SigGroup_St.ALCM_DrvDoorSts.CurrentSigValue = 0;
	ALCM_SigGroup_St.ALCM_PassengerDoorSts.CurrentSigValue = 0;
	ALCM_SigGroup_St.ALCM_LRDoorSts.CurrentSigValue = 0;
	ALCM_SigGroup_St.ALCM_RRDoorSts.CurrentSigValue = 0;
	Flag_PM25Pollution_U8 = 0;
	ALCM_SigGroup_St.ALCM_AEB_VehTrig.PreSigValue = 0;
	ALCM_SigGroup_St.ALCM_AEB_PedTrig.PreSigValue = 0;
	ALCM_SigGroup_St.ALCM_AEB_JA_Warn.PreSigValue = 0;
	ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.PreSigValue = 0;
	ALCM_SigGroup_St.ALCM_FCTBTrig.PreSigValue = 0;
	ALCM_SigGroup_St.ALCM_FCTA_Warn.PreSigValue = 0;
	ALCM_SigGroup_St.ALCM_LCA_WarnR.PreSigValue = 0;
	ALCM_SigGroup_St.ALCM_LCA_WarnL.PreSigValue = 0;
	ALCM_SigGroup_St.ALCM_DOW_WarnR.PreSigValue = 0;
	ALCM_SigGroup_St.ALCM_DOW_WarnL.PreSigValue = 0;
	ALCM_SigGroup_St.ALCM_DrvDoorSts.PreSigValue = 0;
	ALCM_SigGroup_St.ALCM_PassengerDoorSts.PreSigValue = 0;
	ALCM_SigGroup_St.ALCM_LRDoorSts.PreSigValue = 0;
	ALCM_SigGroup_St.ALCM_RRDoorSts.PreSigValue = 0;
	ALCM_SigGroup_St.ALCM_FCW_Warn.PreSigValue = 0;
}

void AL_TransIntoNormal(const AL_EventRunningObject_t * const runObject)
{
	(void)runObject;
	ALCM_SigGroup_St.ALCM_ACDrvTemp.CurrentSigStat = FALCM_Adapt_GetSig_ACDrvTemp_ATC(&ALCM_SigGroup_St.ALCM_ACDrvTemp.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_ACFrntPasstTemp.CurrentSigStat = FALCM_Adapt_GetSig_ACFrntPasstTemp_ATC(&ALCM_SigGroup_St.ALCM_ACFrntPasstTemp.CurrentSigValue);
	ALCM_SigGroup_St.ALCM_ACDrvTemp.PreSigValue = ALCM_SigGroup_St.ALCM_ACDrvTemp.CurrentSigValue;
	ALCM_SigGroup_St.ALCM_ACFrntPasstTemp.PreSigValue = ALCM_SigGroup_St.ALCM_ACFrntPasstTemp.CurrentSigValue;
}


void AL_InputProcess_AEB(uint8 *runObject)
{
	AL_EventRunningObject_t *eventRunningObject = (AL_EventRunningObject_t*)runObject;
	/* Signal missing process */
	if (GET_CAN_MESSAGE_MISSING(ALCM_SigGroup_St.ALCM_AEB_VehTrig.CurrentSigStat))
	{
		ALCM_SigGroup_St.ALCM_AEB_VehTrig.CurrentSigValue = 0;
		ALCM_SigGroup_St.ALCM_AEB_PedTrig.CurrentSigValue = 0;
		ALCM_SigGroup_St.ALCM_AEB_JA_Warn.CurrentSigValue = 0;
		ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.CurrentSigValue = 0;
		ALCM_SigGroup_St.ALCM_FCW_Warn.CurrentSigValue = 0;
	}
	else
	{
		;/*do nothing*/
	}

	if((0 == eventRunningObject->AlcmConfig.Cfg_AEBVehicleEnable) && \
		(0 == eventRunningObject->AlcmConfig.Cfg_AEBPedestrianEnable) && \
		(0 == eventRunningObject->AlcmConfig.Cfg_AEBJABrkEnable))
	{
		/* AEB Ambient Light  disable */
		//ALCM_EventClr(LINKAGE_EVENT_AEB);
	}
	else
	{
		if ( \
			((1 == eventRunningObject->AlcmConfig.Cfg_AEBVehicleEnable) && ((1 == ALCM_SigGroup_St.ALCM_AEB_VehTrig.CurrentSigValue) && (0 == ALCM_SigGroup_St.ALCM_AEB_VehTrig.PreSigValue))) || \
			((1 == eventRunningObject->AlcmConfig.Cfg_AEBPedestrianEnable) && ((1 == ALCM_SigGroup_St.ALCM_AEB_PedTrig.CurrentSigValue) && (0 == ALCM_SigGroup_St.ALCM_AEB_PedTrig.PreSigValue))) || \
			((1 == eventRunningObject->AlcmConfig.Cfg_AEBJABrkEnable) && (((1 == ALCM_SigGroup_St.ALCM_AEB_JA_Warn.CurrentSigValue) || (2 == ALCM_SigGroup_St.ALCM_AEB_JA_Warn.CurrentSigValue)) && ((1 != ALCM_SigGroup_St.ALCM_AEB_JA_Warn.PreSigValue) && (2 != ALCM_SigGroup_St.ALCM_AEB_JA_Warn.PreSigValue)))) || \
			((1 == eventRunningObject->AlcmConfig.Cfg_AEBJABrkEnable) && (((1 == ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.CurrentSigValue) || (2 == ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.CurrentSigValue)) && ((1 != ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.PreSigValue) && (2 != ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.PreSigValue)))) \
			)
		{
			/* AEB Warning Enable */
			vipAl_info("AEB Ambient Light Enable ------------------------------------ ");
			ALCM_EventSet(LINKAGE_EVENT_AEB);
		}
		else if(
			(	((1 == eventRunningObject->AlcmConfig.Cfg_AEBVehicleEnable) && ((0 == ALCM_SigGroup_St.ALCM_AEB_VehTrig.CurrentSigValue) && (1 == ALCM_SigGroup_St.ALCM_AEB_VehTrig.PreSigValue))) && \
				((0 == eventRunningObject->AlcmConfig.Cfg_AEBPedestrianEnable) || (0 == ALCM_SigGroup_St.ALCM_AEB_PedTrig.CurrentSigValue)) && \
				((0 == eventRunningObject->AlcmConfig.Cfg_AEBJABrkEnable) || ((0 == ALCM_SigGroup_St.ALCM_AEB_JA_Warn.CurrentSigValue) || (3 == ALCM_SigGroup_St.ALCM_AEB_JA_Warn.CurrentSigValue))) &&\
				((0 == eventRunningObject->AlcmConfig.Cfg_AEBJABrkEnable) || ((0 == ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.CurrentSigValue) || (3 == ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.CurrentSigValue)))\
			) || \
			(	((0 == eventRunningObject->AlcmConfig.Cfg_AEBVehicleEnable) || (0 == ALCM_SigGroup_St.ALCM_AEB_VehTrig.CurrentSigValue)) && \
				((1 == eventRunningObject->AlcmConfig.Cfg_AEBPedestrianEnable) && ((0 == ALCM_SigGroup_St.ALCM_AEB_PedTrig.CurrentSigValue) && (1 == ALCM_SigGroup_St.ALCM_AEB_PedTrig.PreSigValue))) && \
				((0 == eventRunningObject->AlcmConfig.Cfg_AEBJABrkEnable) || ((0 == ALCM_SigGroup_St.ALCM_AEB_JA_Warn.CurrentSigValue) || (3 == ALCM_SigGroup_St.ALCM_AEB_JA_Warn.CurrentSigValue))) &&\
				((0 == eventRunningObject->AlcmConfig.Cfg_AEBJABrkEnable) || ((0 == ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.CurrentSigValue) || (3 == ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.CurrentSigValue)))\
			) || \
			(	((0 == eventRunningObject->AlcmConfig.Cfg_AEBVehicleEnable) || (0 == ALCM_SigGroup_St.ALCM_AEB_VehTrig.CurrentSigValue)) && \
				((0 == eventRunningObject->AlcmConfig.Cfg_AEBPedestrianEnable) || (0 == ALCM_SigGroup_St.ALCM_AEB_PedTrig.CurrentSigValue)) && \
				((1 == eventRunningObject->AlcmConfig.Cfg_AEBJABrkEnable) && (((0 == ALCM_SigGroup_St.ALCM_AEB_JA_Warn.CurrentSigValue) || (3 == ALCM_SigGroup_St.ALCM_AEB_JA_Warn.CurrentSigValue)) && ((0 != ALCM_SigGroup_St.ALCM_AEB_JA_Warn.PreSigValue) && (3 != ALCM_SigGroup_St.ALCM_AEB_JA_Warn.PreSigValue)))) && \
				((0 == eventRunningObject->AlcmConfig.Cfg_AEBJABrkEnable) || ((0 == ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.CurrentSigValue) || (3 == ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.CurrentSigValue)))\
			) || \
			(	((0 == eventRunningObject->AlcmConfig.Cfg_AEBVehicleEnable) || (0 == ALCM_SigGroup_St.ALCM_AEB_VehTrig.CurrentSigValue)) && \
				((0 == eventRunningObject->AlcmConfig.Cfg_AEBPedestrianEnable) || (0 == ALCM_SigGroup_St.ALCM_AEB_PedTrig.CurrentSigValue)) && \
				((0 == eventRunningObject->AlcmConfig.Cfg_AEBJABrkEnable) || ((0 == ALCM_SigGroup_St.ALCM_AEB_JA_Warn.CurrentSigValue) || (3 == ALCM_SigGroup_St.ALCM_AEB_JA_Warn.CurrentSigValue))) &&\
				((1 == eventRunningObject->AlcmConfig.Cfg_AEBJABrkEnable) && (((0 == ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.CurrentSigValue) || (3 == ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.CurrentSigValue)) && ((0 != ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.PreSigValue) && (3 != ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.PreSigValue))))\
			) || \
			(	((1 == eventRunningObject->AlcmConfig.Cfg_AEBVehicleEnable) && ((0 == ALCM_SigGroup_St.ALCM_AEB_VehTrig.CurrentSigValue) && (1 == ALCM_SigGroup_St.ALCM_AEB_VehTrig.PreSigValue))) && \
				((1 == eventRunningObject->AlcmConfig.Cfg_AEBPedestrianEnable) && ((0 == ALCM_SigGroup_St.ALCM_AEB_PedTrig.CurrentSigValue) && (1 == ALCM_SigGroup_St.ALCM_AEB_PedTrig.PreSigValue))) && \
				((1 == eventRunningObject->AlcmConfig.Cfg_AEBJABrkEnable) && (((0 == ALCM_SigGroup_St.ALCM_AEB_JA_Warn.CurrentSigValue) || (3 == ALCM_SigGroup_St.ALCM_AEB_JA_Warn.CurrentSigValue)) && ((0 != ALCM_SigGroup_St.ALCM_AEB_JA_Warn.PreSigValue) && (3 != ALCM_SigGroup_St.ALCM_AEB_JA_Warn.PreSigValue)))) && \
				((1 == eventRunningObject->AlcmConfig.Cfg_AEBJABrkEnable) && (((0 == ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.CurrentSigValue) || (3 == ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.CurrentSigValue)) && ((0 != ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.PreSigValue) && (3 != ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.PreSigValue))))\
			))
		{
			/*  AEB Warning Disable   */
			vipAl_info("AEB Ambient Light Disable ------------------------------------");
			ALCM_EventClr(LINKAGE_EVENT_AEB);
		}
		else
		{
			; /* do nothing */
		}
	}
	ALCM_SigGroup_St.ALCM_AEB_VehTrig.PreSigValue = ALCM_SigGroup_St.ALCM_AEB_VehTrig.CurrentSigValue;
	ALCM_SigGroup_St.ALCM_AEB_PedTrig.PreSigValue = ALCM_SigGroup_St.ALCM_AEB_PedTrig.CurrentSigValue;
	ALCM_SigGroup_St.ALCM_AEB_JA_Warn.PreSigValue = ALCM_SigGroup_St.ALCM_AEB_JA_Warn.CurrentSigValue;
	ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.PreSigValue = ALCM_SigGroup_St.ALCM_AEB_JABrkTrig.CurrentSigValue;
	//ALCM_TestCase1();
}

void AL_InputProcess_FCW(uint8 *runObject)
{
	AL_EventRunningObject_t *eventRunningObject = (AL_EventRunningObject_t*)runObject;
	/* Signal missing process */
	if(GET_CAN_MESSAGE_MISSING(ALCM_SigGroup_St.ALCM_FCW_Warn.CurrentSigStat))
	{
		ALCM_SigGroup_St.ALCM_FCW_Warn.CurrentSigValue = 0;
	}
	else
	{
		;/*do nothing*/
	}

	if(1 == eventRunningObject->AlcmConfig.Cfg_FCWEnable)
	{
		if(((1 == ALCM_SigGroup_St.ALCM_FCW_Warn.CurrentSigValue) || (2 == ALCM_SigGroup_St.ALCM_FCW_Warn.CurrentSigValue) || (3 == ALCM_SigGroup_St.ALCM_FCW_Warn.CurrentSigValue)) && (0 == ALCM_SigGroup_St.ALCM_FCW_Warn.PreSigValue))
		{
			/* FCW Warning Enable */
			vipAl_info("FCW Ambient Light Enable ------------------------------------");
			ALCM_EventSet(LINKAGE_EVENT_FCW);
		}
		else if(((1 == ALCM_SigGroup_St.ALCM_FCW_Warn.PreSigValue) || (2 == ALCM_SigGroup_St.ALCM_FCW_Warn.PreSigValue) || (3 == ALCM_SigGroup_St.ALCM_FCW_Warn.PreSigValue)) && (0 == ALCM_SigGroup_St.ALCM_FCW_Warn.CurrentSigValue))
		{
			/* FCW Warning Disable  */
			vipAl_info("FCW Ambient Light Diaable ------------------------------------");
			ALCM_EventClr(LINKAGE_EVENT_FCW);
		}
		else
		{
			;
		}
	}
	else
	{
		/* FCW  linkage  Disable */
		//ALCM_EventClr(LINKAGE_EVENT_FCW);
	}

	ALCM_SigGroup_St.ALCM_FCW_Warn.PreSigValue = ALCM_SigGroup_St.ALCM_FCW_Warn.CurrentSigValue;
}
void AL_InputProcess_FCT(uint8 *runObject)
{
	AL_EventRunningObject_t *eventRunningObject = (AL_EventRunningObject_t*)runObject;
	/* Signal missing process */
	if(GET_CAN_MESSAGE_MISSING(ALCM_SigGroup_St.ALCM_FCTBTrig.CurrentSigStat))
	{
		ALCM_SigGroup_St.ALCM_FCTBTrig.CurrentSigValue = 0;
		ALCM_SigGroup_St.ALCM_FCTA_Warn.CurrentSigValue = 0;
	}
	else
	{
		;/*do nothing*/
	}

	if(1 == eventRunningObject->AlcmConfig.Cfg_FCTEnable)
	{
		if(((1 == ALCM_SigGroup_St.ALCM_FCTBTrig.CurrentSigValue) && (0 == ALCM_SigGroup_St.ALCM_FCTBTrig.PreSigValue)) || \
			((1 == ALCM_SigGroup_St.ALCM_FCTA_Warn.CurrentSigValue) && (0 == ALCM_SigGroup_St.ALCM_FCTA_Warn.PreSigValue)))
		{
			/* FCT  linkage Enable */
			vipAl_info("FCT Ambient Light Enable ------------------------------------");
			ALCM_EventSet(LINKAGE_EVENT_FCT);
		}
		else if(
			((0 == ALCM_SigGroup_St.ALCM_FCTBTrig.CurrentSigValue) && ((0 == ALCM_SigGroup_St.ALCM_FCTA_Warn.CurrentSigValue) && (1 == ALCM_SigGroup_St.ALCM_FCTA_Warn.PreSigValue))) || \
			((0 == ALCM_SigGroup_St.ALCM_FCTA_Warn.CurrentSigValue) && ((0 == ALCM_SigGroup_St.ALCM_FCTBTrig.CurrentSigValue) && (1 == ALCM_SigGroup_St.ALCM_FCTBTrig.PreSigValue))) || \
			(((0 == ALCM_SigGroup_St.ALCM_FCTBTrig.CurrentSigValue) && (1 == ALCM_SigGroup_St.ALCM_FCTBTrig.PreSigValue)) && ((0 == ALCM_SigGroup_St.ALCM_FCTA_Warn.CurrentSigValue) && (1 == ALCM_SigGroup_St.ALCM_FCTA_Warn.PreSigValue))) \
		)
		{
			/* FCT  linkage Disable */
			vipAl_info("FCT Ambient Light Disable ------------------------------------");
			ALCM_EventClr(LINKAGE_EVENT_FCT);
		}
		else
		{
			;
		}
	}
	else
	{
		/* FCTA/FCTB Ambient Light Disable */
		//ALCM_EventClr(LINKAGE_EVENT_FCT);
	}

	ALCM_SigGroup_St.ALCM_FCTBTrig.PreSigValue = ALCM_SigGroup_St.ALCM_FCTBTrig.CurrentSigValue;
	ALCM_SigGroup_St.ALCM_FCTA_Warn.PreSigValue = ALCM_SigGroup_St.ALCM_FCTA_Warn.CurrentSigValue;
}
void AL_InputProcess_LCA(uint8 *runObject)
{
	AL_EventRunningObject_t *eventRunningObject = (AL_EventRunningObject_t*)runObject;
	/* Signal missing process */
	if(GET_CAN_MESSAGE_MISSING(ALCM_SigGroup_St.ALCM_LCA_WarnR.CurrentSigStat))
	{
		ALCM_SigGroup_St.ALCM_LCA_WarnR.CurrentSigValue = 0;
		ALCM_SigGroup_St.ALCM_LCA_WarnL.CurrentSigValue = 0;
	}
	else
	{
		;/*do nothing*/
	}

	if(1 == eventRunningObject->AlcmConfig.Cfg_LCAEnable)
	{
		if(((1 == ALCM_SigGroup_St.ALCM_LCA_WarnR.CurrentSigValue) || (2 == ALCM_SigGroup_St.ALCM_LCA_WarnR.CurrentSigValue)) && ((3 == ALCM_SigGroup_St.ALCM_LCA_WarnR.PreSigValue) || (0 == ALCM_SigGroup_St.ALCM_LCA_WarnR.PreSigValue)))
		{
			/* Right LCA Warning Enable */
			vipAl_info("LCA Right Ambient Light Enable ------------------------------------");
			ALCM_EventSet(LINKAGE_EVENT_LCA_RIGHT);
		}
		else if(((1 == ALCM_SigGroup_St.ALCM_LCA_WarnR.PreSigValue) || (2 == ALCM_SigGroup_St.ALCM_LCA_WarnR.PreSigValue)) && ((3 == ALCM_SigGroup_St.ALCM_LCA_WarnR.CurrentSigValue) || (0 == ALCM_SigGroup_St.ALCM_LCA_WarnR.CurrentSigValue)))
		{
			/* Right LCA Warning Disable */
			vipAl_info("LCA Right Ambient Light Disable ------------------------------------");
			ALCM_EventClr(LINKAGE_EVENT_LCA_RIGHT);
		}
		else
		{
			;
		}

		if(((1 == ALCM_SigGroup_St.ALCM_LCA_WarnL.CurrentSigValue) || (2 == ALCM_SigGroup_St.ALCM_LCA_WarnL.CurrentSigValue)) && ((3 == ALCM_SigGroup_St.ALCM_LCA_WarnL.PreSigValue) || (0 == ALCM_SigGroup_St.ALCM_LCA_WarnL.PreSigValue)))
		{
			/* lEFT LCA Warning Enable */
			vipAl_info("LCA Lift Ambient Light Enable ------------------------------------");
			ALCM_EventSet(LINKAGE_EVENT_LCA_LEFT);
		}
		else if(((1 == ALCM_SigGroup_St.ALCM_LCA_WarnL.PreSigValue) || (2 == ALCM_SigGroup_St.ALCM_LCA_WarnL.PreSigValue)) && ((3 == ALCM_SigGroup_St.ALCM_LCA_WarnL.CurrentSigValue) || (0 == ALCM_SigGroup_St.ALCM_LCA_WarnL.CurrentSigValue)))
		{
			/* lEFT LCA Warning Disable */
			vipAl_info("LCA Lift Ambient Light Disable ------------------------------------");
			ALCM_EventClr(LINKAGE_EVENT_LCA_LEFT);
		}
		else
		{
			;
		}
	}
	else
	{
		/* LCA  linkage  Disable */
		//ALCM_EventClr(LINKAGE_EVENT_LCA_LEFT);
		//ALCM_EventClr(LINKAGE_EVENT_LCA_RIGHT);
	}

	ALCM_SigGroup_St.ALCM_LCA_WarnR.PreSigValue = ALCM_SigGroup_St.ALCM_LCA_WarnR.CurrentSigValue;
	ALCM_SigGroup_St.ALCM_LCA_WarnL.PreSigValue = ALCM_SigGroup_St.ALCM_LCA_WarnL.CurrentSigValue;
}
void AL_InputProcess_DOW(uint8 *runObject)
{
	AL_EventRunningObject_t *eventRunningObject = (AL_EventRunningObject_t*)runObject;
	/* Signal missing process */
	if(GET_CAN_MESSAGE_MISSING(ALCM_SigGroup_St.ALCM_DOW_WarnR.CurrentSigStat))
	{
		ALCM_SigGroup_St.ALCM_DOW_WarnR.CurrentSigValue = 0;
		ALCM_SigGroup_St.ALCM_DOW_WarnL.CurrentSigValue = 0;
	}
	else
	{
		;/*do nothing*/
	}

	if(1 == eventRunningObject->AlcmConfig.Cfg_DOWEnable)
	{
		if(((1 == ALCM_SigGroup_St.ALCM_DOW_WarnR.CurrentSigValue) || (2 == ALCM_SigGroup_St.ALCM_DOW_WarnR.CurrentSigValue)) && ((3 == ALCM_SigGroup_St.ALCM_DOW_WarnR.PreSigValue) || (0 == ALCM_SigGroup_St.ALCM_DOW_WarnR.PreSigValue)))
		{
			/* Right DOW Warning Enable */
			vipAl_info("DOW Right Ambient Light Enable ------------------------------------");
			ALCM_EventSet(LINKAGE_EVENT_DOW_RIGHT);
		}
		else if(((1 == ALCM_SigGroup_St.ALCM_DOW_WarnR.PreSigValue) || (2 == ALCM_SigGroup_St.ALCM_DOW_WarnR.PreSigValue)) && ((3 == ALCM_SigGroup_St.ALCM_DOW_WarnR.CurrentSigValue) || (0 == ALCM_SigGroup_St.ALCM_DOW_WarnR.CurrentSigValue)))
		{
			/* Right DOW Warning Disable */
			vipAl_info("DOW Right Ambient Light Disable ------------------------------------");
			ALCM_EventClr(LINKAGE_EVENT_DOW_RIGHT);
		}
		else
		{
			;
		}

		if(((1 == ALCM_SigGroup_St.ALCM_DOW_WarnL.CurrentSigValue) || (2 == ALCM_SigGroup_St.ALCM_DOW_WarnL.CurrentSigValue)) && ((3 == ALCM_SigGroup_St.ALCM_DOW_WarnL.PreSigValue) || (0 == ALCM_SigGroup_St.ALCM_DOW_WarnL.PreSigValue)))
		{
			/* Left DOW Warning Enable */
			vipAl_info("DOW Lift Ambient Light Enable ------------------------------------");
			ALCM_EventSet(LINKAGE_EVENT_DOW_LEFT);
		}
		else if(((1 == ALCM_SigGroup_St.ALCM_DOW_WarnL.PreSigValue) || (2 == ALCM_SigGroup_St.ALCM_DOW_WarnL.PreSigValue)) && ((3 == ALCM_SigGroup_St.ALCM_DOW_WarnL.CurrentSigValue) || (0 == ALCM_SigGroup_St.ALCM_DOW_WarnL.CurrentSigValue)))
		{
			/* Left DOW Warning Disable */
			vipAl_info("DOW Lift Ambient Light Disable ------------------------------------");
			ALCM_EventClr(LINKAGE_EVENT_DOW_LEFT);
		}
		else
		{
			;
		}
	}
	else
	{
		/* DOW  linkage  Disable */
		//ALCM_EventClr(LINKAGE_EVENT_DOW_LEFT);
		//ALCM_EventClr(LINKAGE_EVENT_DOW_RIGHT);
	}

	ALCM_SigGroup_St.ALCM_DOW_WarnR.PreSigValue = ALCM_SigGroup_St.ALCM_DOW_WarnR.CurrentSigValue;
	ALCM_SigGroup_St.ALCM_DOW_WarnL.PreSigValue = ALCM_SigGroup_St.ALCM_DOW_WarnL.CurrentSigValue;
}
void AL_InputProcess_DOOR(uint8 *runObject)
{
	(void)runObject;
	/* Signal missing process */
	if(GET_CAN_MESSAGE_MISSING(ALCM_SigGroup_St.ALCM_DrvDoorSts.CurrentSigStat))
	{
		ALCM_SigGroup_St.ALCM_DrvDoorSts.CurrentSigValue = 0;
		ALCM_SigGroup_St.ALCM_PassengerDoorSts.CurrentSigValue = 0;
		ALCM_SigGroup_St.ALCM_LRDoorSts.CurrentSigValue = 0;
		ALCM_SigGroup_St.ALCM_RRDoorSts.CurrentSigValue = 0;
	}
	else
	{
		;/*do nothing*/
	}

	if((1 == ALCM_SigGroup_St.ALCM_DrvDoorSts.CurrentSigValue) && (0 == ALCM_SigGroup_St.ALCM_DrvDoorSts.PreSigValue))
	{
		/* Driver Door open  linkage Enable */
		vipAl_info("Driver Door Open Ambient Light ------------------------------------");
		ALCM_EventSet(LINKAGE_EVENT_DOOR_OPEN_DRIVE);
	}
	else if((1 == ALCM_SigGroup_St.ALCM_DrvDoorSts.PreSigValue) && (0 == ALCM_SigGroup_St.ALCM_DrvDoorSts.CurrentSigValue))
	{
		/* Driver Door close linkage Disable */
		vipAl_info("Driver Door CLose Ambient Light ------------------------------------");
		ALCM_EventClr(LINKAGE_EVENT_DOOR_OPEN_DRIVE);
	}
	else
	{
		;
	}

	if((1 == ALCM_SigGroup_St.ALCM_PassengerDoorSts.CurrentSigValue) && (0 == ALCM_SigGroup_St.ALCM_PassengerDoorSts.PreSigValue))
	{
		/* Passenger Door open  linkage Enable */
		vipAl_info("Passenger Door Open Ambient Light ------------------------------------");
		ALCM_EventSet(LINKAGE_EVENT_DOOR_OPEN_PASSENGER);
	}
	else if((1 == ALCM_SigGroup_St.ALCM_PassengerDoorSts.PreSigValue) && (0 == ALCM_SigGroup_St.ALCM_PassengerDoorSts.CurrentSigValue))
	{
		/* Passenger Door Close linkage Disable */
		vipAl_info("Passenger Door CLose Ambient Light ------------------------------------");
		ALCM_EventClr(LINKAGE_EVENT_DOOR_OPEN_PASSENGER);
	}
	else
	{
		;
	}

	if((1 == ALCM_SigGroup_St.ALCM_LRDoorSts.CurrentSigValue) && (0 == ALCM_SigGroup_St.ALCM_LRDoorSts.PreSigValue))
	{
		/* Left Rear Door open  linkage Enable */
		vipAl_info("Left Rear Door Open Ambient Light ------------------------------------");
		ALCM_EventSet(LINKAGE_EVENT_DOOR_OPEN_LR);
	}
	else if((1 == ALCM_SigGroup_St.ALCM_LRDoorSts.PreSigValue) && (0 == ALCM_SigGroup_St.ALCM_LRDoorSts.CurrentSigValue))
	{
		/* Left Rear Door open  linkage Disable */
		vipAl_info("Left Rear  Door CLose Ambient Light ------------------------------------");
		ALCM_EventClr(LINKAGE_EVENT_DOOR_OPEN_LR);
	}
	else
	{
		;
	}

	if((1 == ALCM_SigGroup_St.ALCM_RRDoorSts.CurrentSigValue) && (0 == ALCM_SigGroup_St.ALCM_RRDoorSts.PreSigValue))
	{
		/* Right Rear Door open  linkage Enable */
		vipAl_info("Right Rear  Door Open Ambient Light ------------------------------------");
		ALCM_EventSet(LINKAGE_EVENT_DOOR_OPEN_RR);
	}
	else if((1 == ALCM_SigGroup_St.ALCM_RRDoorSts.PreSigValue) && (0 == ALCM_SigGroup_St.ALCM_RRDoorSts.CurrentSigValue))
	{
		/* Right Rear Door open  linkage Disable */
		vipAl_info("Right Rear  Door CLose Ambient Light ------------------------------------");
		ALCM_EventClr(LINKAGE_EVENT_DOOR_OPEN_RR);
	}
	else
	{
		;
	}

	ALCM_SigGroup_St.ALCM_DrvDoorSts.PreSigValue = ALCM_SigGroup_St.ALCM_DrvDoorSts.CurrentSigValue;
	ALCM_SigGroup_St.ALCM_PassengerDoorSts.PreSigValue = ALCM_SigGroup_St.ALCM_PassengerDoorSts.CurrentSigValue;
	ALCM_SigGroup_St.ALCM_LRDoorSts.PreSigValue = ALCM_SigGroup_St.ALCM_LRDoorSts.CurrentSigValue;
	ALCM_SigGroup_St.ALCM_RRDoorSts.PreSigValue = ALCM_SigGroup_St.ALCM_RRDoorSts.CurrentSigValue;
}

void AL_InputProcess_TBD(uint8 *runObject)
{
	(void)runObject;
#if 0
	AL_EventRunningObject_t *eventRunningObject = (AL_EventRunningObject_t*)runObject;
	uint8 Direction_U8 = 0;

	FALCM_Adapt_Get_Direction(&Direction_U8);

	if((1 == Direction_U8) && (1 != Pre_Direction_U8))
	{
		/* 左侧转向  linkage Enable */
		vipAl_info("Left Turn Ambient Light Enable ------------------------------------");
		ALCM_EventSet(LINKAGE_EVENT_TBD_TURN_LEFT);
	}
	else if((1 == Pre_Direction_U8) && (1 != Direction_U8))
	{
		/* 左侧转向Disable  linkage Disable */
		vipAl_info("Left Turn Ambient Light Disable ------------------------------------");
		ALCM_EventClr(LINKAGE_EVENT_TBD_TURN_LEFT);
	}
	else
	{
		;
	}

	if((2 == Direction_U8) && (2 != Pre_Direction_U8))
	{
		/* 右侧转向  linkage Enable */
		vipAl_info("Right Turn Ambient Light Enable ------------------------------------");
		ALCM_EventSet(LINKAGE_EVENT_TBD_TURN_RIGHT);
	}
	else if((2 == Pre_Direction_U8) && (2 != Direction_U8))
	{
		/* 右侧转向Disable  linkage Disable */
		vipAl_info("Right Turn Ambient Light Disable ------------------------------------");
		ALCM_EventClr(LINKAGE_EVENT_TBD_TURN_RIGHT);
	}
	else
	{
		;
	}

	Pre_Direction_U8 = Direction_U8;
#endif
}

void AL_InputProcess_ACTEMP(uint8 *runObject)
{
	AL_EventRunningObject_t *eventRunningObject = (AL_EventRunningObject_t*)runObject;

	if(AL_SINGLE_AIRCONDITION == eventRunningObject->AlcmConfig.Cfg_AirCondition)	//Single Air condition
	{
		if(GET_CAN_MESSAGE_MISSING(ALCM_SigGroup_St.ALCM_ACDrvTemp.CurrentSigStat))
		{
			;/* Signal missing process, Do not send temperature regulating linkage and do not send temperature linkage relief signal.*/
		}
		else
		{
			if(((0 <= ALCM_SigGroup_St.ALCM_ACDrvTemp.PreSigValue) && (0x20 >= ALCM_SigGroup_St.ALCM_ACDrvTemp.PreSigValue)) && \
				((0 <= ALCM_SigGroup_St.ALCM_ACDrvTemp.CurrentSigValue) && (0x20 >= ALCM_SigGroup_St.ALCM_ACDrvTemp.CurrentSigValue)))
			{
				if(ALCM_SigGroup_St.ALCM_ACDrvTemp.CurrentSigValue > ALCM_SigGroup_St.ALCM_ACDrvTemp.PreSigValue)
				{
					/* Single Air Temp Up */
					vipAl_info("Single Air Temp Up ------------------------------------");
					ALCM_EventSet(LINKAGE_EVENT_DRVTEMP_UP);
					ALCM_EventSet(LINKAGE_EVENT_PASSTTEMP_UP);
				}
				else if(ALCM_SigGroup_St.ALCM_ACDrvTemp.CurrentSigValue < ALCM_SigGroup_St.ALCM_ACDrvTemp.PreSigValue)
				{
					/* Single Air Temp Down */
					vipAl_info("Single Air Temp Down ------------------------------------");
					ALCM_EventSet(LINKAGE_EVENT_DRVTEMP_DOWN);
					ALCM_EventSet(LINKAGE_EVENT_PASSTTEMP_DOWN);
				}
				else
				{
					;
				}
			}
			else
			{
				;
			}

			ALCM_SigGroup_St.ALCM_ACDrvTemp.PreSigValue = ALCM_SigGroup_St.ALCM_ACDrvTemp.CurrentSigValue;
			ALCM_SigGroup_St.ALCM_ACFrntPasstTemp.PreSigValue = ALCM_SigGroup_St.ALCM_ACFrntPasstTemp.CurrentSigValue;
		}
	}
	else if(AL_DOUBLE_AIRCONDITION == eventRunningObject->AlcmConfig.Cfg_AirCondition)	//Double Air condition
	{
		if(GET_CAN_MESSAGE_MISSING(ALCM_SigGroup_St.ALCM_ACDrvTemp.CurrentSigStat))
		{
			;/* Signal missing process, Do not send temperature regulating linkage and do not send temperature linkage relief signal.*/
		}
		else
		{
			if(((0 <= ALCM_SigGroup_St.ALCM_ACDrvTemp.PreSigValue) && (0x20 >= ALCM_SigGroup_St.ALCM_ACDrvTemp.PreSigValue)) && \
				((0 <= ALCM_SigGroup_St.ALCM_ACDrvTemp.CurrentSigValue) && (0x20 >= ALCM_SigGroup_St.ALCM_ACDrvTemp.CurrentSigValue)))
			{
				if(ALCM_SigGroup_St.ALCM_ACDrvTemp.CurrentSigValue > ALCM_SigGroup_St.ALCM_ACDrvTemp.PreSigValue)
				{
					/* Driver Air Temp Up */
					vipAl_info("Driver Air Temp Up ------------------------------------");
					ALCM_EventSet(LINKAGE_EVENT_DRVTEMP_UP);
				}
				else if(ALCM_SigGroup_St.ALCM_ACDrvTemp.CurrentSigValue < ALCM_SigGroup_St.ALCM_ACDrvTemp.PreSigValue)
				{
					/* Driver Air Temp Down */
					vipAl_info("Driver Air Temp Down ------------------------------------");
					ALCM_EventSet(LINKAGE_EVENT_DRVTEMP_DOWN);
				}
				else
				{
					;
				}
			}
			else
			{
				;
			}

			if(((0 <= ALCM_SigGroup_St.ALCM_ACFrntPasstTemp.PreSigValue) && (0x20 >= ALCM_SigGroup_St.ALCM_ACFrntPasstTemp.PreSigValue)) && \
				((0 <= ALCM_SigGroup_St.ALCM_ACFrntPasstTemp.CurrentSigValue) && (0x20 >= ALCM_SigGroup_St.ALCM_ACFrntPasstTemp.CurrentSigValue)))
			{
				if(ALCM_SigGroup_St.ALCM_ACFrntPasstTemp.CurrentSigValue > ALCM_SigGroup_St.ALCM_ACFrntPasstTemp.PreSigValue)
				{
					/* Passenger Air Temp Up */
					vipAl_info("Passenger Air Temp Up ------------------------------------");
					ALCM_EventSet(LINKAGE_EVENT_PASSTTEMP_UP);
				}
				else if(ALCM_SigGroup_St.ALCM_ACFrntPasstTemp.CurrentSigValue < ALCM_SigGroup_St.ALCM_ACFrntPasstTemp.PreSigValue)
				{
					/* Passenger Air Temp Down */
					vipAl_info("Passenger Air Temp Down ------------------------------------");
					ALCM_EventSet(LINKAGE_EVENT_PASSTTEMP_DOWN);
				}
				else
				{
					;
				}
			}
			else
			{
				;
			}

			ALCM_SigGroup_St.ALCM_ACDrvTemp.PreSigValue = ALCM_SigGroup_St.ALCM_ACDrvTemp.CurrentSigValue;
			ALCM_SigGroup_St.ALCM_ACFrntPasstTemp.PreSigValue = ALCM_SigGroup_St.ALCM_ACFrntPasstTemp.CurrentSigValue;
		}
	}
	else
	{
		/* Air condition Ambient Light  Disable */
		//ALCM_EventClr(LINKAGE_EVENT_DRVTEMP_UP);
		//ALCM_EventClr(LINKAGE_EVENT_DRVTEMP_DOWN);
		//ALCM_EventClr(LINKAGE_EVENT_PASSTTEMP_UP);
		//ALCM_EventClr(LINKAGE_EVENT_PASSTTEMP_DOWN);
	}

}

void AL_InputProcess_PM25(uint8 *runObject)
{
	AL_EventRunningObject_t *eventRunningObject = (AL_EventRunningObject_t*)runObject;

	if(1 == eventRunningObject->AlcmConfig.Cfg_PM25Enable)
	{
		if(GET_CAN_MESSAGE_MISSING(ALCM_SigGroup_St.ALCM_PM25InDens.CurrentSigStat))
		{
			/* Signal missing process ,send PM2.5 linkage release signal*/
			ALCM_EventClr(LINKAGE_EVENT_PM25_POLLUTION_LOW);
			ALCM_EventClr(LINKAGE_EVENT_PM25_POLLUTION_MID);
			ALCM_EventClr(LINKAGE_EVENT_PM25_POLLUTION_HIGH);
			ALCM_EventClr(LINKAGE_EVENT_PM25_POLLUTION_SERIOUS);
			Flag_PM25Pollution_U8 = AL_PM25_POLLUTION_CLEAR;
		}
		else
		{
			if(((75 < ALCM_SigGroup_St.ALCM_PM25InDens.CurrentSigValue) && (115 >= ALCM_SigGroup_St.ALCM_PM25InDens.CurrentSigValue)) && \
				((AL_PM25_POLLUTION_LOW != Flag_PM25Pollution_U8)))
			{
				/* PM2.5 Pollution Low Ambient Light Enable */
				vipAl_info("PM2.5 Pollution Low Ambient Light Enable ------------------------------------");
				ALCM_EventSet(LINKAGE_EVENT_PM25_POLLUTION_LOW);
				Flag_PM25Pollution_U8 = AL_PM25_POLLUTION_LOW;
			}
			else if(((115 < ALCM_SigGroup_St.ALCM_PM25InDens.CurrentSigValue) && (150 >= ALCM_SigGroup_St.ALCM_PM25InDens.CurrentSigValue)) && \
				((AL_PM25_POLLUTION_MID != Flag_PM25Pollution_U8)))
			{
				/* PM2.5 Pollution Middle Ambient Light Enable */
				vipAl_info("PM2.5 Pollution Middle Ambient Light Enable ------------------------------------");
				ALCM_EventSet(LINKAGE_EVENT_PM25_POLLUTION_MID);
				Flag_PM25Pollution_U8 = AL_PM25_POLLUTION_MID;
			}
			else if(((150 < ALCM_SigGroup_St.ALCM_PM25InDens.CurrentSigValue) && (250 >= ALCM_SigGroup_St.ALCM_PM25InDens.CurrentSigValue)) && \
				((AL_PM25_POLLUTION_HIGH != Flag_PM25Pollution_U8)))
			{
				/* PM2.5 Pollution High Ambient Light Enable */
				vipAl_info("PM2.5 Pollution High Ambient Light Enable ------------------------------------");
				ALCM_EventSet(LINKAGE_EVENT_PM25_POLLUTION_HIGH);
				Flag_PM25Pollution_U8 = AL_PM25_POLLUTION_HIGH;
			}
			else if(((250 < ALCM_SigGroup_St.ALCM_PM25InDens.CurrentSigValue) && (999 >= ALCM_SigGroup_St.ALCM_PM25InDens.CurrentSigValue)) && \
				((AL_PM25_POLLUTION_SERIOUS != Flag_PM25Pollution_U8)))
			{
				/* PM2.5 Pollution Serious Ambient Light Enable */
				vipAl_info("PM2.5 Pollution Serious Ambient Light Enable ------------------------------------");
				ALCM_EventSet(LINKAGE_EVENT_PM25_POLLUTION_SERIOUS);
				Flag_PM25Pollution_U8 = AL_PM25_POLLUTION_SERIOUS;
			}
			else
			{
				if((75 < ALCM_SigGroup_St.ALCM_PM25InDens.CurrentSigValue) && (999 >= ALCM_SigGroup_St.ALCM_PM25InDens.CurrentSigValue))
				{
					;
				}
				else
				{
					ALCM_EventClr(LINKAGE_EVENT_PM25_POLLUTION_LOW);
					ALCM_EventClr(LINKAGE_EVENT_PM25_POLLUTION_MID);
					ALCM_EventClr(LINKAGE_EVENT_PM25_POLLUTION_HIGH);
					ALCM_EventClr(LINKAGE_EVENT_PM25_POLLUTION_SERIOUS);
					Flag_PM25Pollution_U8 = AL_PM25_POLLUTION_CLEAR;
				}
			}
		}
	}
	else
	{
		/* PM2.5  linkage Disable */
		//ALCM_EventClr(LINKAGE_EVENT_PM25_POLLUTION_LOW);
		//ALCM_EventClr(LINKAGE_EVENT_PM25_POLLUTION_MID);
		//ALCM_EventClr(LINKAGE_EVENT_PM25_POLLUTION_HIGH);
		//ALCM_EventClr(LINKAGE_EVENT_PM25_POLLUTION_SERIOUS);
	}
}

void AL_OutputValueGet_AEB(uint8 *runObject)
{
	AL_EventRunningObject_t *eventRunningObject = (AL_EventRunningObject_t*)runObject;
	const AL_EventAttribute_t * const eventAttribute = eventRunningObject->eventAttributePtr;
	uint8 i = 0;
	CanSignalValue_t canSignalValue;
	uint8 signalIndex = 0;
	uint8 linkageAreaNumber = 4;
	uint8 linkageAreaValue[4] = {0, 1, 2, 3};

	vipAl_info("AEB Event process");

	ALCM_OutputValueInit(&canSignalValue);

	for (i = 0; i < linkageAreaNumber; i++)
	{
		signalIndex = linkageAreaValue[i];

		CAN_SIGNAL_VALUE_SET(signalIndex, LINKAGE_EVENT_AEB);
	}

	ALCM_CanSignalOutput(&canSignalValue);

	//ALCM_SetRunningFuncAndEvent(runObject);
}

void AL_OutputValueGet_FCW(uint8 *runObject)
{
	AL_EventRunningObject_t *eventRunningObject = (AL_EventRunningObject_t*)runObject;
	const AL_EventAttribute_t * const eventAttribute = eventRunningObject->eventAttributePtr;
	uint8 i = 0;
	CanSignalValue_t canSignalValue;
	uint8 signalIndex = 0;
	uint8 linkageAreaNumber = 4;
	uint8 linkageAreaValue[4] = {0, 1, 2, 3};

	vipAl_info("FCW Event process");

	ALCM_OutputValueInit(&canSignalValue);

	for (i = 0; i < linkageAreaNumber; i++)
	{
		signalIndex = linkageAreaValue[i];

		CAN_SIGNAL_VALUE_SET(signalIndex, LINKAGE_EVENT_FCW);
	}

	ALCM_CanSignalOutput(&canSignalValue);

	//ALCM_SetRunningFuncAndEvent(runObject);
}

void AL_OutputValueGet_FCT(uint8 *runObject)
{
	AL_EventRunningObject_t *eventRunningObject = (AL_EventRunningObject_t*)runObject;
	const AL_EventAttribute_t * const eventAttribute = eventRunningObject->eventAttributePtr;
	uint8 i = 0;
	CanSignalValue_t canSignalValue;
	uint8 signalIndex = 0;
	uint8 linkageAreaNumber = 4;
	uint8 linkageAreaValue[4] = {0, 1, 2, 3};

	vipAl_info("FCT Event process");

	ALCM_OutputValueInit(&canSignalValue);

	for (i = 0; i < linkageAreaNumber; i++)
	{
		signalIndex = linkageAreaValue[i];

		CAN_SIGNAL_VALUE_SET(signalIndex, LINKAGE_EVENT_FCT);
	}

	ALCM_CanSignalOutput(&canSignalValue);
	//ALCM_SetRunningFuncAndEvent(runObject);
}

void AL_OutputValueGet_LCA(uint8 *runObject)
{
	AL_EventRunningObject_t *eventRunningObject = (AL_EventRunningObject_t*)runObject;
	const AL_EventAttribute_t * const eventAttribute = eventRunningObject->eventAttributePtr;
	uint8 i = 0;
	CanSignalValue_t canSignalValue;

	uint8 leftDriverDoor = 0;
	uint8 eventIndex = 0;

	uint8 signalIndex = 0;
	uint8 linkageAreaNumber = 2;
	uint8 linkageAreaValue[2][2][2] = {{{0, 2},{1, 3}},{{1, 2},{0, 3}}};

	vipAl_info("LCA Event process");

	ALCM_OutputValueInit(&canSignalValue);

	leftDriverDoor = eventRunningObject->AlcmConfig.Cfg_LeftDriverDoor;

	if (eventRunningObject->aboutToRunEventId[0] == LINKAGE_EVENT_LCA_LEFT)
	{
		eventIndex = 0;
		for (i = 0; i < linkageAreaNumber; i++)
		{
			signalIndex = linkageAreaValue[leftDriverDoor][eventIndex][i];
			CAN_SIGNAL_VALUE_SET(signalIndex, LINKAGE_EVENT_LCA_LEFT);
		}
	}

	if (eventRunningObject->aboutToRunEventId[1] == LINKAGE_EVENT_LCA_RIGHT)
	{
		eventIndex = 1;
		for (i = 0; i < linkageAreaNumber; i++)
		{
			signalIndex = linkageAreaValue[leftDriverDoor][eventIndex][i];
			CAN_SIGNAL_VALUE_SET(signalIndex, LINKAGE_EVENT_LCA_RIGHT);
		}
	}

	if (eventRunningObject->aboutToRunFunc == eventRunningObject->runningFunc)
	{
		if (eventRunningObject->aboutToRunEventId[0] == eventRunningObject->runningEventId[0])
		{
			eventIndex = 0;
			for (i = 0; i < linkageAreaNumber; i++)
			{
				signalIndex = linkageAreaValue[leftDriverDoor][eventIndex][i];
				CAN_SIGNAL_VALUE_KEEP(signalIndex);
			}
		}

		if (eventRunningObject->aboutToRunEventId[1] == eventRunningObject->runningEventId[1])
		{
			eventIndex = 1;
			for (i = 0; i < linkageAreaNumber; i++)
			{
				signalIndex = linkageAreaValue[leftDriverDoor][eventIndex][i];
				CAN_SIGNAL_VALUE_KEEP(signalIndex);
			}
		}
	}

	ALCM_CanSignalOutput(&canSignalValue);

	//ALCM_SetRunningFuncAndEvent(runObject);
}

void AL_OutputValueGet_DOW(uint8 *runObject)
{
	AL_EventRunningObject_t *eventRunningObject = (AL_EventRunningObject_t*)runObject;
	const AL_EventAttribute_t * const eventAttribute = eventRunningObject->eventAttributePtr;
	uint8 i = 0;
	CanSignalValue_t canSignalValue;

	uint8 leftDriverDoor = 0;
	uint8 eventIndex = 0;
	uint8 signalIndex = 0;
	uint8 linkageAreaNumber = 2;
	uint8 linkageAreaValue[2][2][2] = {{{0, 4},{1, 5}},{{1, 4}, {0, 5}}};

	vipAl_info("DOW Event process");

	ALCM_OutputValueInit(&canSignalValue);

	leftDriverDoor = eventRunningObject->AlcmConfig.Cfg_LeftDriverDoor;

	if (eventRunningObject->aboutToRunEventId[0] == LINKAGE_EVENT_DOW_LEFT)
	{
		eventIndex = 0;
		for (i = 0; i < linkageAreaNumber; i++)
		{
			signalIndex = linkageAreaValue[leftDriverDoor][eventIndex][i];
			CAN_SIGNAL_VALUE_SET(signalIndex, LINKAGE_EVENT_DOW_LEFT);
		}
	}

	if (eventRunningObject->aboutToRunEventId[1] == LINKAGE_EVENT_DOW_RIGHT)
	{
		eventIndex = 1;
		for (i = 0; i < linkageAreaNumber; i++)
		{
			signalIndex = linkageAreaValue[leftDriverDoor][eventIndex][i];
			CAN_SIGNAL_VALUE_SET(signalIndex, LINKAGE_EVENT_DOW_RIGHT);
		}
	}


	if (eventRunningObject->aboutToRunFunc == eventRunningObject->runningFunc)
	{
		if (eventRunningObject->aboutToRunEventId[0] == eventRunningObject->runningEventId[0])
		{
			eventIndex = 0;
			for (i = 0; i < linkageAreaNumber; i++)
			{
				signalIndex = linkageAreaValue[leftDriverDoor][eventIndex][i];
				CAN_SIGNAL_VALUE_KEEP(signalIndex);
			}
		}

		if (eventRunningObject->aboutToRunEventId[1] == eventRunningObject->runningEventId[1])
		{
			eventIndex = 1;
			for (i = 0; i < linkageAreaNumber; i++)
			{
				signalIndex = linkageAreaValue[leftDriverDoor][eventIndex][i];
				CAN_SIGNAL_VALUE_KEEP(signalIndex);
			}
		}
	}

	ALCM_CanSignalOutput(&canSignalValue);

	//ALCM_SetRunningFuncAndEvent(runObject);
}
void AL_OutputValueGet_DOOR(uint8 *runObject)
{
	AL_EventRunningObject_t *eventRunningObject = (AL_EventRunningObject_t*)runObject;
	const AL_EventAttribute_t * const eventAttribute = eventRunningObject->eventAttributePtr;
	CanSignalValue_t canSignalValue;
	uint8 eventIndex = 0;
	uint8 signalIndex = 0;
	uint8 linkageAreaValue[4] = {0, 1, 4, 5};

	vipAl_info("DOOR Event process");

	ALCM_OutputValueInit(&canSignalValue);

	if (eventRunningObject->aboutToRunEventId[0] == LINKAGE_EVENT_DOOR_OPEN_DRIVE)
	{
		eventIndex = 0;
		signalIndex = linkageAreaValue[eventIndex];
		CAN_SIGNAL_VALUE_SET(signalIndex, LINKAGE_EVENT_DOOR_OPEN_DRIVE);
	}

	if (eventRunningObject->aboutToRunEventId[1] == LINKAGE_EVENT_DOOR_OPEN_PASSENGER)
	{
		eventIndex = 1;
		signalIndex = linkageAreaValue[eventIndex];
		CAN_SIGNAL_VALUE_SET(signalIndex, LINKAGE_EVENT_DOOR_OPEN_PASSENGER);
	}

	if (eventRunningObject->aboutToRunEventId[2] == LINKAGE_EVENT_DOOR_OPEN_LR)
	{
		eventIndex = 2;
		signalIndex = linkageAreaValue[eventIndex];
		CAN_SIGNAL_VALUE_SET(signalIndex, LINKAGE_EVENT_DOOR_OPEN_LR);
	}

	if (eventRunningObject->aboutToRunEventId[3] == LINKAGE_EVENT_DOOR_OPEN_RR)
	{
		eventIndex = 3;
		signalIndex = linkageAreaValue[eventIndex];
		CAN_SIGNAL_VALUE_SET(signalIndex, LINKAGE_EVENT_DOOR_OPEN_RR);
	}

	if (eventRunningObject->aboutToRunFunc == eventRunningObject->runningFunc)
	{
		if (eventRunningObject->aboutToRunEventId[0] == eventRunningObject->runningEventId[0])
		{
			eventIndex = 0;
			signalIndex = linkageAreaValue[eventIndex];
			CAN_SIGNAL_VALUE_KEEP(signalIndex);
		}

		if (eventRunningObject->aboutToRunEventId[1] == eventRunningObject->runningEventId[1])
		{
			eventIndex = 1;
			signalIndex = linkageAreaValue[eventIndex];
			CAN_SIGNAL_VALUE_KEEP(signalIndex);
		}

		if (eventRunningObject->aboutToRunEventId[2] == eventRunningObject->runningEventId[2])
		{
			eventIndex = 2;
			signalIndex = linkageAreaValue[eventIndex];
			CAN_SIGNAL_VALUE_KEEP(signalIndex);
		}

		if (eventRunningObject->aboutToRunEventId[3] == eventRunningObject->runningEventId[3])
		{
			eventIndex = 3;
			signalIndex = linkageAreaValue[eventIndex];
			CAN_SIGNAL_VALUE_KEEP(signalIndex);
		}
	}

	ALCM_CanSignalOutput(&canSignalValue);

	//ALCM_SetRunningFuncAndEvent(runObject);
}
void AL_OutputValueGet_TBD(uint8 *runObject)
{
	(void)runObject;
	vipAl_info("TBD Event process");
}
void AL_OutputValueGet_ACTEMP(uint8 *runObject)
{
	AL_EventRunningObject_t *eventRunningObject = (AL_EventRunningObject_t*)runObject;
	const AL_EventAttribute_t * const eventAttribute = eventRunningObject->eventAttributePtr;
	uint8 eventSlotNumber = eventRunningObject->funcAttributePtr[LINKAGE_FUNCTION_ACTEMP].eventSlotNumber;
	uint8 index = 0;
	uint8 AreaSeleltIndex = 0;
	CanSignalValue_t canSignalValue;
	uint8 eventIndex = 0;
	uint8 signalIndex = 0;
	uint8 leftDrv = 0;
	uint8 linkageAreaValue[2][2][2] = {{{0, 2}, {1, 3}}, {{0, 3}, {1, 2}}};
	uint8 linkageEventValue[2][2] = {{LINKAGE_EVENT_DRVTEMP_UP, LINKAGE_EVENT_DRVTEMP_DOWN}, {LINKAGE_EVENT_PASSTTEMP_UP, LINKAGE_EVENT_PASSTTEMP_DOWN}};

	vipAl_info("ACTEMP Event process");

	ALCM_OutputValueInit(&canSignalValue);

	leftDrv = eventRunningObject->AlcmConfig.Cfg_LeftDriverDoor;

	for (index = 0; index < eventSlotNumber; index++)
	{
		if ((eventRunningObject->aboutToRunEventId[index] != eventRunningObject->runningEventId[index])
			&& (eventRunningObject->aboutToRunEventId[index] != LINKAGE_EVENT_ID_INVALID))
		{
			eventRunningObject->runningEventTimeRemain[index] = 200;
			vipAl_info("ACTEMP Event process, id = %d", eventRunningObject->aboutToRunEventId[index]);
		}

		if (eventRunningObject->aboutToRunEventId[index] != eventRunningObject->runningEventId[index])
		{
			if (eventRunningObject->aboutToRunEventId[index] == LINKAGE_EVENT_ID_INVALID)
			{
				for (AreaSeleltIndex = 0; AreaSeleltIndex < 2; AreaSeleltIndex++)
				{
					signalIndex = linkageAreaValue[leftDrv][index][AreaSeleltIndex];
					canSignalValue.freq[signalIndex] = LINKAGE_SIGNAL_FREQ_OFF;
					canSignalValue.color[signalIndex] = LINKAGE_SIGNAL_COLOR_NOACTION;
					canSignalValue.lightLevel[signalIndex] = LINKAGE_SIGNAL_LIGHTLVL_NOACTION;
				}
			}
			else if (eventRunningObject->aboutToRunEventId[index] == linkageEventValue[index][0])
			{
				eventIndex = linkageEventValue[index][0];
				for (AreaSeleltIndex = 0; AreaSeleltIndex < 2; AreaSeleltIndex++)
				{
					signalIndex = linkageAreaValue[leftDrv][index][AreaSeleltIndex];
					CAN_SIGNAL_VALUE_SET(signalIndex, eventIndex);
				}
			}
			else if (eventRunningObject->aboutToRunEventId[index] == linkageEventValue[index][1])
			{
				eventIndex = linkageEventValue[index][1];
				for (AreaSeleltIndex = 0; AreaSeleltIndex < 2; AreaSeleltIndex++)
				{
					signalIndex = linkageAreaValue[leftDrv][index][AreaSeleltIndex];
					CAN_SIGNAL_VALUE_SET(signalIndex, eventIndex);
				}
			}
			else
			{
				// do nothing
			}
		}

		if ((eventRunningObject->aboutToRunEventId[index] == eventRunningObject->runningEventId[index])
			&& (eventRunningObject->aboutToRunEventId[index] != LINKAGE_EVENT_ID_INVALID))
		{
			for (AreaSeleltIndex = 0; AreaSeleltIndex < 2; AreaSeleltIndex++)
			{
				signalIndex = linkageAreaValue[leftDrv][index][AreaSeleltIndex];
				canSignalValue.freq[signalIndex] = LINKAGE_SIGNAL_FREQ_NOACTION;
				canSignalValue.color[signalIndex] = eventRunningObject->runningSignalValue.color[signalIndex];
				canSignalValue.lightLevel[signalIndex] = eventRunningObject->runningSignalValue.lightLevel[signalIndex];
			}
		}
	}


	ALCM_CanSignalOutput(&canSignalValue);
}

void AL_OutputValueGet_PM25(uint8 *runObject)
{
	AL_EventRunningObject_t *eventRunningObject = (AL_EventRunningObject_t*)runObject;
	const AL_EventAttribute_t * const eventAttribute = eventRunningObject->eventAttributePtr;
	uint8 i = 0;
	CanSignalValue_t canSignalValue;
	uint8 signalIndex = 0;
	uint8 linkageAreaNumber = 7;
	uint8 linkageAreaValue[7] = {0, 1, 2, 3, 4, 5, 6};

	vipAl_info("PM25 Event process");

	ALCM_OutputValueInit(&canSignalValue);

	if (eventRunningObject->aboutToRunEventId[0] == LINKAGE_EVENT_PM25_POLLUTION_LOW)
	{
		eventRunningObject->runningEventTimeRemain[0] = EVENT_ATTRIBUT_TIMEOUT_3S;
		for (i = 0; i < linkageAreaNumber; i++)
		{
			signalIndex = linkageAreaValue[i];
			CAN_SIGNAL_VALUE_SET(signalIndex, LINKAGE_EVENT_PM25_POLLUTION_LOW);
		}
	}
	else if (eventRunningObject->aboutToRunEventId[0] == LINKAGE_EVENT_PM25_POLLUTION_MID)
	{
		eventRunningObject->runningEventTimeRemain[0] = EVENT_ATTRIBUT_TIMEOUT_3S;
		for (i = 0; i < linkageAreaNumber; i++)
		{
			signalIndex = linkageAreaValue[i];
			CAN_SIGNAL_VALUE_SET(signalIndex, LINKAGE_EVENT_PM25_POLLUTION_MID);
		}
	}
	else if (eventRunningObject->aboutToRunEventId[0] == LINKAGE_EVENT_PM25_POLLUTION_HIGH)
	{
		eventRunningObject->runningEventTimeRemain[0] = EVENT_ATTRIBUT_TIMEOUT_3S;
		for (i = 0; i < linkageAreaNumber; i++)
		{
			signalIndex = linkageAreaValue[i];
			CAN_SIGNAL_VALUE_SET(signalIndex, LINKAGE_EVENT_PM25_POLLUTION_HIGH);
		}
	}
	else if (eventRunningObject->aboutToRunEventId[0] == LINKAGE_EVENT_PM25_POLLUTION_SERIOUS)
	{
		for (i = 0; i < linkageAreaNumber; i++)
		{
			signalIndex = linkageAreaValue[i];
			CAN_SIGNAL_VALUE_SET(signalIndex, LINKAGE_EVENT_PM25_POLLUTION_SERIOUS);
		}
	}
	else
	{
		// do nothing
	}

	ALCM_CanSignalOutput(&canSignalValue);

	//ALCM_SetRunningFuncAndEvent(runObject);
}

void AL_OutputValueGet_NONE(uint8 *runObject)
{
	CanSignalValue_t canSignalValue;
	(void)runObject;

	vipAl_info("NONE Event process");

	ALCM_OutputValueInit(&canSignalValue);

	ALCM_CanSignalOutput(&canSignalValue);

	//ALCM_SetRunningFuncAndEvent(runObject);
}


#define Common_GateWay_STOP_SEC_CODE
#include  "Common_GateWay_MemMap.h"

