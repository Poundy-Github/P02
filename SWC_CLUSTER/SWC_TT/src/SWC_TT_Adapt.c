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
*File Name   : TT_Adapt.c                                                                               *
*                                                                                                         *
*Description : Telltale module logic process source file.                                                 *
*                                                                                                         *
*Author      : Deng Jiangbo                                                                                  *
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

//#include "Rte_Common_Normal.h"
#include "Compiler.h"
#include "Platform_Types.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
//#include "SWC_TT_Config.h"
//#include "SWC_TT_Interface.h"
#ifdef GWM_V35_PROJECT_TYPE_B02
#define SWC_TT_ADAPT_B02
#elif defined GWM_V35_PROJECT_TYPE_B03
#define SWC_TT_ADAPT_B03
#elif defined GWM_V35_PROJECT_TYPE_P03
#define SWC_TT_ADAPT_P03
#elif defined GWM_V35_PROJECT_TYPE_P05
#define SWC_TT_ADAPT_P05
#elif defined GWM_V35_PROJECT_TYPE_A07
#define SWC_TT_ADAPT_A07
#elif defined GWM_V35_PROJECT_TYPE_D01
#define SWC_TT_ADAPT_D01
#elif defined GWM_V35_PROJECT_TYPE_D02
#define SWC_TT_ADAPT_D02
#elif defined GWM_V35_PROJECT_TYPE_D03
#define SWC_TT_ADAPT_D03
#elif defined GWM_V35_PROJECT_TYPE_P02
#define SWC_TT_ADAPT_P02
#elif defined GWM_V35_PROJECT_TYPE_P01
#define SWC_TT_ADAPT_P01




#else
#define SWC_TT_ADAPT_NULL
#endif

#include "Dio.h"
#include "Com.h"
#include "VConfig.h"
#include "IoHwAb_Cfg_RI.h"
#include <string.h>
#include "SWC_TT_Adapt.h"
#include "SWC_TT_MemMap.h"
#include "CConfig_Cfg.h"

#ifdef SWC_TT_ADAPT_B02
#include "ComEx_Cfg.h"
#elif defined SWC_TT_ADAPT_P03
#include "ComEx_Cfg.h"
#elif defined SWC_TT_ADAPT_P05
#include "ComEx_Cfg.h"
#elif defined SWC_TT_ADAPT_A07
#include "ComEx_Cfg.h"
#elif defined SWC_TT_ADAPT_D01
#include "ComEx_Cfg.h"
#elif defined SWC_TT_ADAPT_D02
#include "ComEx_Cfg.h"
#elif defined SWC_TT_ADAPT_D03
#include "ComEx_Cfg.h"
#elif defined SWC_TT_ADAPT_P02
#include "ComEx_Cfg.h"
#elif defined SWC_TT_ADAPT_P01
#include "ComEx_Cfg.h"

#endif


#define TT_ONE_MINUTE_COUNT			(60000/100)
#define TT_15S_TIME_COUNT			(15000/20)
#define TT_15S_Tpms_COUNT			(14800/20)
#define TT_4S_TIME_COUNT			(4000/20)
#define TT_3S_TIME_COUNT			(3000/20)

#define SWC_TT_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_TT_MemMap.h"

static tt_InternalConfigData_t TTConfigData_s;
static uint8 u8EngRunSts;

#define SWC_TT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_TT_MemMap.h"

#define SWC_TT_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_TT_MemMap.h"

static uint8 u8VSG_SwitchSts = 1;

#define SWC_TT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_TT_MemMap.h"

#define SWC_TT_START_SEC_CODE
#include "SWC_TT_MemMap.h"


uint8 FTT_Adapt_GetPowerMode_State(void)
{
	SystemState_RecordType Power_State;
	uint8 u8PowerMode = 0;

	(void)memcpy(&Power_State,Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut(),sizeof(SystemState_RecordType));
	u8PowerMode = Power_State.ClusterState;

	return u8PowerMode;
}

uint8 FTT_Adapt_GetVconfig(uint16 id_u8)
{
	VconfigKind_Allbuffers configAdr;
	(void)Rte_Read_Vconfig_GetKindBuffers_AllKinds(configAdr);

	return (uint8)(configAdr[id_u8]);
}

void FTT_RteAdaptGetAllConfig(void)
{
	CconfigKind_400Bytes u8FTT_CconfigKind_400Bytes;

	if(E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(u8FTT_CconfigKind_400Bytes))
	{
		TTConfigData_s.u8LowFuelDelayTime = (uint8)(CConfig_GetConfig(CCONFIG_KIND_LowOilPressure_telltales_DelayTime,u8FTT_CconfigKind_400Bytes) * 5);
		TTConfigData_s.u8LowFuelCheckTime = (uint8)(CConfig_GetConfig(CCONFIG_KIND_LOW_telltales_CheckTime,u8FTT_CconfigKind_400Bytes) * 5);
		TTConfigData_s.u16EPBlightorflashtime = (uint16)(CConfig_GetConfig(CCONFIG_KIND_EPBRedlamp_lightorflashtime,u8FTT_CconfigKind_400Bytes) * 50);
		TTConfigData_s.u16Tpms_flashtime = (uint16)(CConfig_GetConfig(CCONFIG_KIND_Tpms_flashtime,u8FTT_CconfigKind_400Bytes) * 10);
	}
	else
	{
		TTConfigData_s.u8LowFuelDelayTime = TT_3S_TIME_COUNT;
		TTConfigData_s.u8LowFuelCheckTime = TT_3S_TIME_COUNT;
		TTConfigData_s.u16EPBlightorflashtime = TT_15S_TIME_COUNT;
		TTConfigData_s.u16Tpms_flashtime = TT_ONE_MINUTE_COUNT;
	}
}

uint16 FTT_AdaptGetInternalconfig(tt_InternalConfig_t id_u8)
{
	uint16 u16config = 0xffff;
	switch(id_u8)
	{
		case TTconfigLowFuelDelayTime:
		{
			u16config = (uint16)TTConfigData_s.u8LowFuelDelayTime;
			break;
		}
		case TTconfigLowFuelCheckTime:
		{
			u16config = (uint16)TTConfigData_s.u8LowFuelCheckTime;
			break;
		}
		case TTconfigEPBlightorflashtime:
		{
			u16config = TTConfigData_s.u16EPBlightorflashtime;
			break;
		}
		case TTconfigTpms_flashtime:
		{
			u16config = TTConfigData_s.u16Tpms_flashtime;
			break;
		}
		default:
		{
			u16config = 0xffff;
			break;
		}

	}
	return u16config;
}

TT_SIGNAL_SOURCE TT_Adapt_Signal_Source(void)
{
	uint8 u8Byte83 = 0;
	TT_SIGNAL_SOURCE TT_signal_value = TT_NO_SIGNAL;
	u8Byte83 = FTT_Adapt_GetVconfig(VCONFIG_KIND_PT_CAN_BUS_TYPE);
	if (1 == u8Byte83)
	{
		TT_signal_value = TT_CANFD_SIGNAL;
	}
	else
	{
		TT_signal_value = TT_CAN_SIGNAL;
	}
	return TT_signal_value;
}

TT_DOMAIN_INFO FTT_vDomain_Logic_Process(void)
{
	uint8 u8Byte4 = 0;
	TT_DOMAIN_INFO tt_domain_sts = TT_DOMAIN_CH;
	u8Byte4 = FTT_Adapt_GetVconfig(VCONFIG_KIND_REGIONAL);
	if ((0 == u8Byte4) || (1 == u8Byte4) || (2 == u8Byte4) || (4 == u8Byte4) \
		|| (5 == u8Byte4) || (6 == u8Byte4) || (7 == u8Byte4) || (8 == u8Byte4))
	{
		tt_domain_sts = TT_DOMAIN_CH;
	}
	else if (3 == u8Byte4)
	{
		tt_domain_sts = TT_DOMAIN_US;
	}
	else
	{
		tt_domain_sts = TT_NO_DOMAIN;
	}

	return tt_domain_sts;
}

uint8 FTT_Adapt_GetEngRunSts(void)
{
	s_TachoInfo_t EngineRunningInfo;
	uint16 u16EngineRunningValue = 0;
	uint8 u8EngRunStsPowerMode = 0;

	(void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&EngineRunningInfo);
	u16EngineRunningValue = EngineRunningInfo.EngSpdBak;
	u8EngRunStsPowerMode = FTT_Adapt_GetPowerMode_State();

	if(u16EngineRunningValue >= 400)
	{
		u8EngRunSts = (uint8)Engine_Running;
	}
	else if(u16EngineRunningValue < 200)
	{
		u8EngRunSts = (uint8)Engine_Stop;
	}
	else
	{
		/* keep previous status */
	}

	if(u8EngRunStsPowerMode != SYSTEMSTATE_Cluster_ON)
	{
		u8EngRunSts = (uint8)Engine_Stop;
	}

	return u8EngRunSts;
}

uint8 FTT_Adapt_GetMessage_GentrWarnLmpSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8GentrWarnLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GENTRWARNLMPSTS, &u8GentrWarnLmpSts, (uint8)sizeof(u8GentrWarnLmpSts));
	*data = u8GentrWarnLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_GentrWarnLmpSts_GentrWarnLmpSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8GentrWarnLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GENTRWARNLMPSTS, &u8GentrWarnLmpSts, (uint8)sizeof(u8GentrWarnLmpSts));
	*data = u8GentrWarnLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8GentrWarnLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GENTRWARNLMPSTS, &u8GentrWarnLmpSts, (uint8)sizeof(u8GentrWarnLmpSts));
	*data = u8GentrWarnLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8GentrWarnLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GENTRWARNLMPSTS, &u8GentrWarnLmpSts, (uint8)sizeof(u8GentrWarnLmpSts));
	*data = u8GentrWarnLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8GentrWarnLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GENTRWARNLMPSTS, &u8GentrWarnLmpSts, (uint8)sizeof(u8GentrWarnLmpSts));
	*data = u8GentrWarnLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8GentrWarnLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GENTRWARNLMPSTS, &u8GentrWarnLmpSts, (uint8)sizeof(u8GentrWarnLmpSts));
	*data = u8GentrWarnLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8GentrWarnLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GENTRWARNLMPSTS, &u8GentrWarnLmpSts, (uint8)sizeof(u8GentrWarnLmpSts));
	*data = u8GentrWarnLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8GentrWarnLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GENTRWARNLMPSTS, &u8GentrWarnLmpSts, (uint8)sizeof(u8GentrWarnLmpSts));
	*data = u8GentrWarnLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
		uint8 u8GentrWarnLmpSts = 0;
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GENTRWARNLMPSTS, &u8GentrWarnLmpSts, (uint8)sizeof(u8GentrWarnLmpSts));
		*data = u8GentrWarnLmpSts;
		if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
		{
			result = RTE_E_OK;
		}
#endif

    return result;
}

uint8 FTT_Adapt_GetHW_C2(uint32 *data)
{
	uint8 result = 0xff;
#if (defined(SWC_TT_ADAPT_B02))
	result = Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, data);
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, data);
#elif (defined(SWC_TT_ADAPT_P03))
	result = Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, data);
#elif (defined(SWC_TT_ADAPT_P05))
	result = Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, data);
#elif (defined(SWC_TT_ADAPT_A07))
	result = Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, data);
#elif (defined(SWC_TT_ADAPT_D01))
	result = Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, data);
#elif (defined(SWC_TT_ADAPT_D02))
	result = Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, data);
#elif (defined(SWC_TT_ADAPT_D03))
	result = Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, data);
#elif (defined(SWC_TT_ADAPT_P02))
	result = Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, data);
#elif (defined(SWC_TT_ADAPT_P01))
	result = Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, data);
#endif
    return result;
}

uint8 FTT_Adapt_GetHW_C3(uint8 *data)
{
	uint8 result = 0xff;
#if (defined(SWC_TT_ADAPT_B02))
	result = Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, data);
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, data);
#elif (defined(SWC_TT_ADAPT_P03))
	result = Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, data);
#elif (defined(SWC_TT_ADAPT_P05))
	result = Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, data);
#elif (defined(SWC_TT_ADAPT_A07))
	result = Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, data);
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	result = Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, data);
#elif (defined(SWC_TT_ADAPT_P01))
	result = Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, data);

#endif
    return result;
}

uint8 FTT_Adapt_GetMessage_EngSpdVldty(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8EngSpdVldty = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, &u8EngSpdVldty, (uint8)sizeof(u8EngSpdVldty));
	*data = u8EngSpdVldty;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_ECM1_EngSpdVldty_EngSpdVldty(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8EngSpdVldty = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, &u8EngSpdVldty, (uint8)sizeof(u8EngSpdVldty));
	*data = u8EngSpdVldty;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8EngSpdVldty = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, &u8EngSpdVldty, (uint8)sizeof(u8EngSpdVldty));
	*data = u8EngSpdVldty;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8EngSpdVldty = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, &u8EngSpdVldty, (uint8)sizeof(u8EngSpdVldty));
	*data = u8EngSpdVldty;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8EngSpdVldty = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, &u8EngSpdVldty, (uint8)sizeof(u8EngSpdVldty));
	*data = u8EngSpdVldty;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8EngSpdVldty = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, &u8EngSpdVldty, (uint8)sizeof(u8EngSpdVldty));
	*data = u8EngSpdVldty;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8EngSpdVldty = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, &u8EngSpdVldty, (uint8)sizeof(u8EngSpdVldty));
	*data = u8EngSpdVldty;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8EngSpdVldty = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, &u8EngSpdVldty, (uint8)sizeof(u8EngSpdVldty));
	*data = u8EngSpdVldty;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8EngSpdVldty = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, &u8EngSpdVldty, (uint8)sizeof(u8EngSpdVldty));
	*data = u8EngSpdVldty;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

    return result;
}

uint8 FTT_Adapt_GetMessage_TachoInfo(s_TachoInfo_t *data)
{
	uint8 result = 0xff;
#if (defined(SWC_TT_ADAPT_B02))
	result = Rte_Read_rpSR_SWCNormal_TachoInfo_Element(data);
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_rpSR_SWCNormal_TachoInfo_Element(data);
#elif (defined(SWC_TT_ADAPT_P03))
	result = Rte_Read_rpSR_SWCNormal_TachoInfo_Element(data);
#elif (defined(SWC_TT_ADAPT_P05))
	result = Rte_Read_rpSR_SWCNormal_TachoInfo_Element(data);
#elif (defined(SWC_TT_ADAPT_A07))
	result = Rte_Read_rpSR_SWCNormal_TachoInfo_Element(data);
#elif (defined(SWC_TT_ADAPT_D01))
	result = Rte_Read_rpSR_SWCNormal_TachoInfo_Element(data);
#elif (defined(SWC_TT_ADAPT_D02))
	result = Rte_Read_rpSR_SWCNormal_TachoInfo_Element(data);
#elif (defined(SWC_TT_ADAPT_D03))
	result = Rte_Read_rpSR_SWCNormal_TachoInfo_Element(data);
#elif (defined(SWC_TT_ADAPT_P02))
	result = Rte_Read_rpSR_SWCNormal_TachoInfo_Element(data);
#elif (defined(SWC_TT_ADAPT_P01))
	result = Rte_Read_rpSR_SWCNormal_TachoInfo_Element(data);


#endif
    return result;
}

uint8 FTT_Adapt_GetMessage_MILSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8MILSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MILSTS, &u8MILSts, (uint8)sizeof(u8MILSts));
	*data = u8MILSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_MILSts_MILSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8MILSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MILSTS, &u8MILSts, (uint8)sizeof(u8MILSts));
	*data = u8MILSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8MILSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MILSTS, &u8MILSts, (uint8)sizeof(u8MILSts));
	*data = u8MILSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8MILSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MILSTS, &u8MILSts, (uint8)sizeof(u8MILSts));
	*data = u8MILSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8MILSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MILSTS, &u8MILSts, (uint8)sizeof(u8MILSts));
	*data = u8MILSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8MILSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MILSTS, &u8MILSts, (uint8)sizeof(u8MILSts));
	*data = u8MILSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8MILSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MILSTS, &u8MILSts, (uint8)sizeof(u8MILSts));
	*data = u8MILSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8MILSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MILSTS, &u8MILSts, (uint8)sizeof(u8MILSts));
	*data = u8MILSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8MILSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MILSTS, &u8MILSts, (uint8)sizeof(u8MILSts));
	*data = u8MILSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}
uint8 FTT_Adapt_GetMessage_TRANS_Warning_LAMP(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_P05))
	uint8 u8TRANS_Warning_LAMP = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRANS_WARNING_LAMP, &u8TRANS_Warning_LAMP, (uint8)sizeof(u8TRANS_Warning_LAMP));
	*data = u8TRANS_Warning_LAMP;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	*data = 0;


#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_EngSVSSig(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8EngSVSSig = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSVSSIG, &u8EngSVSSig, (uint8)sizeof(u8EngSVSSig));
	*data = u8EngSVSSig;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_EngSVSSig_EngSVSSig(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8EngSVSSig = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSVSSIG, &u8EngSVSSig, (uint8)sizeof(u8EngSVSSig));
	*data = u8EngSVSSig;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8EngSVSSig = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSVSSIG, &u8EngSVSSig, (uint8)sizeof(u8EngSVSSig));
	*data = u8EngSVSSig;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8EngSVSSig = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSVSSIG, &u8EngSVSSig, (uint8)sizeof(u8EngSVSSig));
	*data = u8EngSVSSig;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8EngSVSSig = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSVSSIG, &u8EngSVSSig, (uint8)sizeof(u8EngSVSSig));
	*data = u8EngSVSSig;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8EngSVSSig = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSVSSIG, &u8EngSVSSig, (uint8)sizeof(u8EngSVSSig));
	*data = u8EngSVSSig;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8EngSVSSig = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSVSSIG, &u8EngSVSSig, (uint8)sizeof(u8EngSVSSig));
	*data = u8EngSVSSig;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8EngSVSSig = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSVSSIG, &u8EngSVSSig, (uint8)sizeof(u8EngSVSSig));
	*data = u8EngSVSSig;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8EngSVSSig = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSVSSIG, &u8EngSVSSig, (uint8)sizeof(u8EngSVSSig));
	*data = u8EngSVSSig;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_EngClntTempWarn(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8EngClntTempWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, &u8EngClntTempWarn, (uint8)sizeof(u8EngClntTempWarn));
	*data = u8EngClntTempWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_EngClntTempWarn_EngClntTempWarn(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8EngClntTempWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, &u8EngClntTempWarn, (uint8)sizeof(u8EngClntTempWarn));
	*data = u8EngClntTempWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8EngClntTempWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, &u8EngClntTempWarn, (uint8)sizeof(u8EngClntTempWarn));
	*data = u8EngClntTempWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8EngClntTempWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, &u8EngClntTempWarn, (uint8)sizeof(u8EngClntTempWarn));
	*data = u8EngClntTempWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8EngClntTempWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, &u8EngClntTempWarn, (uint8)sizeof(u8EngClntTempWarn));
	*data = u8EngClntTempWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8EngClntTempWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, &u8EngClntTempWarn, (uint8)sizeof(u8EngClntTempWarn));
	*data = u8EngClntTempWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8EngClntTempWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, &u8EngClntTempWarn, (uint8)sizeof(u8EngClntTempWarn));
	*data = u8EngClntTempWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8EngClntTempWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, &u8EngClntTempWarn, (uint8)sizeof(u8EngClntTempWarn));
	*data = u8EngClntTempWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8EngClntTempWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, &u8EngClntTempWarn, (uint8)sizeof(u8EngClntTempWarn));
	*data = u8EngClntTempWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_CruiseCtrlSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8CruiseCtrlSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS, &u8CruiseCtrlSts, (uint8)sizeof(u8CruiseCtrlSts));
	*data = u8CruiseCtrlSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_CruiseCtrlSts_CruiseCtrlSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8CruiseCtrlSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS, &u8CruiseCtrlSts, (uint8)sizeof(u8CruiseCtrlSts));
	*data = u8CruiseCtrlSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8CruiseCtrlSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS, &u8CruiseCtrlSts, (uint8)sizeof(u8CruiseCtrlSts));
	*data = u8CruiseCtrlSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8CruiseCtrlSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS, &u8CruiseCtrlSts, (uint8)sizeof(u8CruiseCtrlSts));
	*data = u8CruiseCtrlSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8CruiseCtrlSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS, &u8CruiseCtrlSts, (uint8)sizeof(u8CruiseCtrlSts));
	*data = u8CruiseCtrlSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8CruiseCtrlSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS, &u8CruiseCtrlSts, (uint8)sizeof(u8CruiseCtrlSts));
	*data = u8CruiseCtrlSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8CruiseCtrlSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS, &u8CruiseCtrlSts, (uint8)sizeof(u8CruiseCtrlSts));
	*data = u8CruiseCtrlSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8CruiseCtrlSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS, &u8CruiseCtrlSts, (uint8)sizeof(u8CruiseCtrlSts));
	*data = u8CruiseCtrlSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8CruiseCtrlSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS, &u8CruiseCtrlSts, (uint8)sizeof(u8CruiseCtrlSts));
	*data = u8CruiseCtrlSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_CruiseCtrlSts_PHEV(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8CruiseCtrlSts_PHEV = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS_PHEV, &u8CruiseCtrlSts_PHEV, (uint8)sizeof(u8CruiseCtrlSts_PHEV));
	*data = u8CruiseCtrlSts_PHEV;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_CruiseCtrlSts_PHEV_CruiseCtrlSts_PHEV(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8CruiseCtrlSts_PHEV = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS_PHEV, &u8CruiseCtrlSts_PHEV, (uint8)sizeof(u8CruiseCtrlSts_PHEV));
	*data = u8CruiseCtrlSts_PHEV;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8CruiseCtrlSts_PHEV = 0;
	// result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS_PHEV, &u8CruiseCtrlSts_PHEV, (uint8)sizeof(u8CruiseCtrlSts_PHEV));
	*data = u8CruiseCtrlSts_PHEV;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8CruiseCtrlSts_PHEV = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS_PHEV, &u8CruiseCtrlSts_PHEV, (uint8)sizeof(u8CruiseCtrlSts_PHEV));
	*data = u8CruiseCtrlSts_PHEV;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8CruiseCtrlSts_PHEV = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS_PHEV, &u8CruiseCtrlSts_PHEV, (uint8)sizeof(u8CruiseCtrlSts_PHEV));
	*data = u8CruiseCtrlSts_PHEV;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8CruiseCtrlSts_PHEV = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS_PHEV, &u8CruiseCtrlSts_PHEV, (uint8)sizeof(u8CruiseCtrlSts_PHEV));
	*data = u8CruiseCtrlSts_PHEV;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8CruiseCtrlSts_PHEV = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS_PHEV, &u8CruiseCtrlSts_PHEV, (uint8)sizeof(u8CruiseCtrlSts_PHEV));
	*data = u8CruiseCtrlSts_PHEV;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8CruiseCtrlSts_PHEV = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS_PHEV, &u8CruiseCtrlSts_PHEV, (uint8)sizeof(u8CruiseCtrlSts_PHEV));
	*data = u8CruiseCtrlSts_PHEV;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_SS_Enable_Lamp(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8SS_Enable_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_ENABLE_LAMP, &u8SS_Enable_Lamp, (uint8)sizeof(u8SS_Enable_Lamp));
	*data = u8SS_Enable_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_SS_Enable_Lamp_SS_Enable_Lamp(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8SS_Enable_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_ENABLE_LAMP, &u8SS_Enable_Lamp, (uint8)sizeof(u8SS_Enable_Lamp));
	*data = u8SS_Enable_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8SS_Enable_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_ENABLE_LAMP, &u8SS_Enable_Lamp, (uint8)sizeof(u8SS_Enable_Lamp));
	*data = u8SS_Enable_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8SS_Enable_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_ENABLE_LAMP, &u8SS_Enable_Lamp, (uint8)sizeof(u8SS_Enable_Lamp));
	*data = u8SS_Enable_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8SS_Enable_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_ENABLE_LAMP, &u8SS_Enable_Lamp, (uint8)sizeof(u8SS_Enable_Lamp));
	*data = u8SS_Enable_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8SS_Enable_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_ENABLE_LAMP, &u8SS_Enable_Lamp, (uint8)sizeof(u8SS_Enable_Lamp));
	*data = u8SS_Enable_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8SS_Enable_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_ENABLE_LAMP, &u8SS_Enable_Lamp, (uint8)sizeof(u8SS_Enable_Lamp));
	*data = u8SS_Enable_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8SS_Enable_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_ENABLE_LAMP, &u8SS_Enable_Lamp, (uint8)sizeof(u8SS_Enable_Lamp));
	*data = u8SS_Enable_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8SS_Enable_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_ENABLE_LAMP, &u8SS_Enable_Lamp, (uint8)sizeof(u8SS_Enable_Lamp));
	*data = u8SS_Enable_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_SS_Fault_Lamp(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8SS_Fault_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_FAULT_LAMP, &u8SS_Fault_Lamp, (uint8)sizeof(u8SS_Fault_Lamp));
	*data = u8SS_Fault_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_SS_Fault_Lamp_SS_Fault_Lamp(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8SS_Fault_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_FAULT_LAMP, &u8SS_Fault_Lamp, (uint8)sizeof(u8SS_Fault_Lamp));
	*data = u8SS_Fault_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8SS_Fault_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_FAULT_LAMP, &u8SS_Fault_Lamp, (uint8)sizeof(u8SS_Fault_Lamp));
	*data = u8SS_Fault_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8SS_Fault_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_FAULT_LAMP, &u8SS_Fault_Lamp, (uint8)sizeof(u8SS_Fault_Lamp));
	*data = u8SS_Fault_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8SS_Fault_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_FAULT_LAMP, &u8SS_Fault_Lamp, (uint8)sizeof(u8SS_Fault_Lamp));
	*data = u8SS_Fault_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8SS_Fault_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_FAULT_LAMP, &u8SS_Fault_Lamp, (uint8)sizeof(u8SS_Fault_Lamp));
	*data = u8SS_Fault_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8SS_Fault_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_FAULT_LAMP, &u8SS_Fault_Lamp, sizeof(u8SS_Fault_Lamp));
	*data = u8SS_Fault_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8SS_Fault_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_FAULT_LAMP, &u8SS_Fault_Lamp, sizeof(u8SS_Fault_Lamp));
	*data = u8SS_Fault_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8SS_Fault_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_FAULT_LAMP, &u8SS_Fault_Lamp, sizeof(u8SS_Fault_Lamp));
	*data = u8SS_Fault_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}			
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8SS_Fault_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_FAULT_LAMP, &u8SS_Fault_Lamp, (uint8)sizeof(u8SS_Fault_Lamp));
	*data = u8SS_Fault_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8SS_Fault_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_FAULT_LAMP, &u8SS_Fault_Lamp, (uint8)sizeof(u8SS_Fault_Lamp));
	*data = u8SS_Fault_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8SS_Fault_Lamp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_FAULT_LAMP, &u8SS_Fault_Lamp, (uint8)sizeof(u8SS_Fault_Lamp));
	*data = u8SS_Fault_Lamp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_TirePressSysFailrIndcn(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8TirePressSysFailrIndcn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TIREPRESSSYSFAILRINDCN, &u8TirePressSysFailrIndcn, (uint8)sizeof(u8TirePressSysFailrIndcn));
	*data = u8TirePressSysFailrIndcn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_TirePressSysFailrIndcn_TirePressSysFailrIndcn(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8TirePressSysFailrIndcn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TIREPRESSSYSFAILRINDCN, &u8TirePressSysFailrIndcn, (uint8)sizeof(u8TirePressSysFailrIndcn));
	*data = u8TirePressSysFailrIndcn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8TirePressSysFailrIndcn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TIREPRESSSYSFAILRINDCN, &u8TirePressSysFailrIndcn, (uint8)sizeof(u8TirePressSysFailrIndcn));
	*data = u8TirePressSysFailrIndcn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8TirePressSysFailrIndcn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TIREPRESSSYSFAILRINDCN, &u8TirePressSysFailrIndcn, (uint8)sizeof(u8TirePressSysFailrIndcn));
	*data = u8TirePressSysFailrIndcn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8TirePressSysFailrIndcn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TIREPRESSSYSFAILRINDCN, &u8TirePressSysFailrIndcn, (uint8)sizeof(u8TirePressSysFailrIndcn));
	*data = u8TirePressSysFailrIndcn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8TirePressSysFailrIndcn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TIREPRESSSYSFAILRINDCN, &u8TirePressSysFailrIndcn, (uint8)sizeof(u8TirePressSysFailrIndcn));
	*data = u8TirePressSysFailrIndcn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8TirePressSysFailrIndcn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TIREPRESSSYSFAILRINDCN, &u8TirePressSysFailrIndcn, (uint8)sizeof(u8TirePressSysFailrIndcn));
	*data = u8TirePressSysFailrIndcn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8TirePressSysFailrIndcn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TIREPRESSSYSFAILRINDCN, &u8TirePressSysFailrIndcn, (uint8)sizeof(u8TirePressSysFailrIndcn));
	*data = u8TirePressSysFailrIndcn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8TirePressSysFailrIndcn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TIREPRESSSYSFAILRINDCN, &u8TirePressSysFailrIndcn, (uint8)sizeof(u8TirePressSysFailrIndcn));
	*data = u8TirePressSysFailrIndcn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_FLTirePressIndSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8FLTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, &u8FLTirePressIndSts, (uint8)sizeof(u8FLTirePressIndSts));
	*data = u8FLTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_FLTirePressIndSts_FLTirePressIndSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8FLTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, &u8FLTirePressIndSts, (uint8)sizeof(u8FLTirePressIndSts));
	*data = u8FLTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8FLTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, &u8FLTirePressIndSts, (uint8)sizeof(u8FLTirePressIndSts));
	*data = u8FLTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8FLTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, &u8FLTirePressIndSts, (uint8)sizeof(u8FLTirePressIndSts));
	*data = u8FLTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8FLTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, &u8FLTirePressIndSts, (uint8)sizeof(u8FLTirePressIndSts));
	*data = u8FLTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8FLTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, &u8FLTirePressIndSts, (uint8)sizeof(u8FLTirePressIndSts));
	*data = u8FLTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8FLTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, &u8FLTirePressIndSts, (uint8)sizeof(u8FLTirePressIndSts));
	*data = u8FLTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8FLTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, &u8FLTirePressIndSts, (uint8)sizeof(u8FLTirePressIndSts));
	*data = u8FLTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8FLTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, &u8FLTirePressIndSts, (uint8)sizeof(u8FLTirePressIndSts));
	*data = u8FLTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_FRTirePressIndSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8FRTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, &u8FRTirePressIndSts, (uint8)sizeof(u8FRTirePressIndSts));
	*data = u8FRTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_FRTirePressIndSts_FRTirePressIndSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8FRTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, &u8FRTirePressIndSts, (uint8)sizeof(u8FRTirePressIndSts));
	*data = u8FRTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8FRTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, &u8FRTirePressIndSts, (uint8)sizeof(u8FRTirePressIndSts));
	*data = u8FRTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8FRTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, &u8FRTirePressIndSts, (uint8)sizeof(u8FRTirePressIndSts));
	*data = u8FRTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8FRTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, &u8FRTirePressIndSts, (uint8)sizeof(u8FRTirePressIndSts));
	*data = u8FRTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8FRTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, &u8FRTirePressIndSts, (uint8)sizeof(u8FRTirePressIndSts));
	*data = u8FRTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8FRTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, &u8FRTirePressIndSts, (uint8)sizeof(u8FRTirePressIndSts));
	*data = u8FRTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8FRTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, &u8FRTirePressIndSts, (uint8)sizeof(u8FRTirePressIndSts));
	*data = u8FRTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
		uint8 u8FRTirePressIndSts = 0;
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, &u8FRTirePressIndSts, (uint8)sizeof(u8FRTirePressIndSts));
		*data = u8FRTirePressIndSts;
		if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
		{
			result = RTE_E_OK;
		}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_RLTirePressIndSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8RLTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, &u8RLTirePressIndSts, (uint8)sizeof(u8RLTirePressIndSts));
	*data = u8RLTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_RLTirePressIndSts_RLTirePressIndSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8RLTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, &u8RLTirePressIndSts, (uint8)sizeof(u8RLTirePressIndSts));
	*data = u8RLTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8RLTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, &u8RLTirePressIndSts, (uint8)sizeof(u8RLTirePressIndSts));
	*data = u8RLTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8RLTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, &u8RLTirePressIndSts, (uint8)sizeof(u8RLTirePressIndSts));
	*data = u8RLTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8RLTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, &u8RLTirePressIndSts, (uint8)sizeof(u8RLTirePressIndSts));
	*data = u8RLTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8RLTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, &u8RLTirePressIndSts, (uint8)sizeof(u8RLTirePressIndSts));
	*data = u8RLTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8RLTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, &u8RLTirePressIndSts, (uint8)sizeof(u8RLTirePressIndSts));
	*data = u8RLTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8RLTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, &u8RLTirePressIndSts, (uint8)sizeof(u8RLTirePressIndSts));
	*data = u8RLTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8RLTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, &u8RLTirePressIndSts, (uint8)sizeof(u8RLTirePressIndSts));
	*data = u8RLTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_RRTirePressIndSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8RRTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, &u8RRTirePressIndSts, (uint8)sizeof(u8RRTirePressIndSts));
	*data = u8RRTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_RRTirePressIndSts_RRTirePressIndSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8RRTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, &u8RRTirePressIndSts, (uint8)sizeof(u8RRTirePressIndSts));
	*data = u8RRTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8RRTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, &u8RRTirePressIndSts, (uint8)sizeof(u8RRTirePressIndSts));
	*data = u8RRTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8RRTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, &u8RRTirePressIndSts, (uint8)sizeof(u8RRTirePressIndSts));
	*data = u8RRTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8RRTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, &u8RRTirePressIndSts, (uint8)sizeof(u8RRTirePressIndSts));
	*data = u8RRTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8RRTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, &u8RRTirePressIndSts, (uint8)sizeof(u8RRTirePressIndSts));
	*data = u8RRTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8RRTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, &u8RRTirePressIndSts, (uint8)sizeof(u8RRTirePressIndSts));
	*data = u8RRTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8RRTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, &u8RRTirePressIndSts, (uint8)sizeof(u8RRTirePressIndSts));
	*data = u8RRTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8RRTirePressIndSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, &u8RRTirePressIndSts, (uint8)sizeof(u8RRTirePressIndSts));
	*data = u8RRTirePressIndSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_FLTireTempSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8FLTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, &u8FLTireTempSts, (uint8)sizeof(u8FLTireTempSts));
	*data = u8FLTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_FLTireTempSts_FLTireTempSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8FLTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, &u8FLTireTempSts, (uint8)sizeof(u8FLTireTempSts));
	*data = u8FLTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8FLTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, &u8FLTireTempSts, (uint8)sizeof(u8FLTireTempSts));
	*data = u8FLTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8FLTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, &u8FLTireTempSts, (uint8)sizeof(u8FLTireTempSts));
	*data = u8FLTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8FLTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, &u8FLTireTempSts, (uint8)sizeof(u8FLTireTempSts));
	*data = u8FLTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8FLTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, &u8FLTireTempSts, (uint8)sizeof(u8FLTireTempSts));
	*data = u8FLTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8FLTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, &u8FLTireTempSts, (uint8)sizeof(u8FLTireTempSts));
	*data = u8FLTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8FLTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, &u8FLTireTempSts, (uint8)sizeof(u8FLTireTempSts));
	*data = u8FLTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8FLTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, &u8FLTireTempSts, (uint8)sizeof(u8FLTireTempSts));
	*data = u8FLTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_FRTireTempSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8FRTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, &u8FRTireTempSts, (uint8)sizeof(u8FRTireTempSts));
	*data = u8FRTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_FRTireTempSts_FRTireTempSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8FRTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, &u8FRTireTempSts, (uint8)sizeof(u8FRTireTempSts));
	*data = u8FRTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8FRTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, &u8FRTireTempSts, (uint8)sizeof(u8FRTireTempSts));
	*data = u8FRTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8FRTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, &u8FRTireTempSts, (uint8)sizeof(u8FRTireTempSts));
	*data = u8FRTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8FRTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, &u8FRTireTempSts, (uint8)sizeof(u8FRTireTempSts));
	*data = u8FRTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8FRTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, &u8FRTireTempSts, (uint8)sizeof(u8FRTireTempSts));
	*data = u8FRTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8FRTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, &u8FRTireTempSts, (uint8)sizeof(u8FRTireTempSts));
	*data = u8FRTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8FRTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, &u8FRTireTempSts, (uint8)sizeof(u8FRTireTempSts));
	*data = u8FRTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8FRTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, &u8FRTireTempSts, (uint8)sizeof(u8FRTireTempSts));
	*data = u8FRTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_RLTireTempSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8RLTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, &u8RLTireTempSts, (uint8)sizeof(u8RLTireTempSts));
	*data = u8RLTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_RLTireTempSts_RLTireTempSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8RLTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, &u8RLTireTempSts, (uint8)sizeof(u8RLTireTempSts));
	*data = u8RLTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8RLTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, &u8RLTireTempSts, (uint8)sizeof(u8RLTireTempSts));
	*data = u8RLTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8RLTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, &u8RLTireTempSts, (uint8)sizeof(u8RLTireTempSts));
	*data = u8RLTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8RLTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, &u8RLTireTempSts, (uint8)sizeof(u8RLTireTempSts));
	*data = u8RLTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8RLTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, &u8RLTireTempSts, (uint8)sizeof(u8RLTireTempSts));
	*data = u8RLTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8RLTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, &u8RLTireTempSts, (uint8)sizeof(u8RLTireTempSts));
	*data = u8RLTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8RLTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, &u8RLTireTempSts, (uint8)sizeof(u8RLTireTempSts));
	*data = u8RLTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8RLTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, &u8RLTireTempSts, (uint8)sizeof(u8RLTireTempSts));
	*data = u8RLTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_RRTireTempSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8RRTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, &u8RRTireTempSts, (uint8)sizeof(u8RRTireTempSts));
	*data = u8RRTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_RRTireTempSts_RRTireTempSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8RRTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, &u8RRTireTempSts, (uint8)sizeof(u8RRTireTempSts));
	*data = u8RRTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8RRTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, &u8RRTireTempSts, (uint8)sizeof(u8RRTireTempSts));
	*data = u8RRTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8RRTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, &u8RRTireTempSts, (uint8)sizeof(u8RRTireTempSts));
	*data = u8RRTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8RRTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, &u8RRTireTempSts, (uint8)sizeof(u8RRTireTempSts));
	*data = u8RRTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8RRTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, &u8RRTireTempSts, (uint8)sizeof(u8RRTireTempSts));
	*data = u8RRTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8RRTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, &u8RRTireTempSts, (uint8)sizeof(u8RRTireTempSts));
	*data = u8RRTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8RRTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, &u8RRTireTempSts, (uint8)sizeof(u8RRTireTempSts));
	*data = u8RRTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8RRTireTempSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, &u8RRTireTempSts, (uint8)sizeof(u8RRTireTempSts));
	*data = u8RRTireTempSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_SG_EPS1(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8EPS_FailSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, &u8EPS_FailSts, (uint8)sizeof(u8EPS_FailSts));
	*data = u8EPS_FailSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_EPS1_FD1 EPS1_FD1;
	SG_EPS1 EPS1;
	if(TT_Adapt_Signal_Source() == TT_CANFD_SIGNAL)
	{
		result = Rte_Read_SG_EPS1_FD1_SG_EPS1_FD1(&EPS1_FD1);
		*data = EPS1_FD1.EPS_FailSts_0x147;
	}
	else
	{
		result = Rte_Read_SG_EPS1_SG_EPS1(&EPS1);
		*data = EPS1.EPS_FailSts_0x168;
	}
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8EPS_FailSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, &u8EPS_FailSts, (uint8)sizeof(u8EPS_FailSts));
	*data = u8EPS_FailSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8EPS_FailSts = 0;
	if(TT_Adapt_Signal_Source() == TT_CANFD_SIGNAL)
	{
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS_0X147, &u8EPS_FailSts, (uint8)sizeof(u8EPS_FailSts));
	}
	else
	{
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS_0X168, &u8EPS_FailSts, (uint8)sizeof(u8EPS_FailSts));
	}

	*data = u8EPS_FailSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8EPS_FailSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, &u8EPS_FailSts, (uint8)sizeof(u8EPS_FailSts));
	*data = u8EPS_FailSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8EPS_FailSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, &u8EPS_FailSts, (uint8)sizeof(u8EPS_FailSts));
	*data = u8EPS_FailSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8EPS_FailSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, &u8EPS_FailSts, (uint8)sizeof(u8EPS_FailSts));
	*data = u8EPS_FailSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8EPS_FailSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, &u8EPS_FailSts, (uint8)sizeof(u8EPS_FailSts));
	*data = u8EPS_FailSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#endif

	return result;
}


uint8 FTT_Adapt_GetMessage_LSSFuncSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8LSSFuncSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSFUNCSTS, &u8LSSFuncSts, (uint8)sizeof(u8LSSFuncSts));
	*data = u8LSSFuncSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_IFC4_IFC_FD2 IFC4_IFC_FD2;
	result = Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(&IFC4_IFC_FD2);
	*data = IFC4_IFC_FD2.LSSFuncSts;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8LSSFuncSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSFUNCSTS, &u8LSSFuncSts, (uint8)sizeof(u8LSSFuncSts));
	*data = u8LSSFuncSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8LSSFuncSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSFUNCSTS, &u8LSSFuncSts, (uint8)sizeof(u8LSSFuncSts));
	*data = u8LSSFuncSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8LSSFuncSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSFUNCSTS, &u8LSSFuncSts, (uint8)sizeof(u8LSSFuncSts));
	*data = u8LSSFuncSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8LSSFuncSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSFUNCSTS, &u8LSSFuncSts, (uint8)sizeof(u8LSSFuncSts));
	*data = u8LSSFuncSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8LSSFuncSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSFUNCSTS, &u8LSSFuncSts, (uint8)sizeof(u8LSSFuncSts));
	*data = u8LSSFuncSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8LSSFuncSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSFUNCSTS, &u8LSSFuncSts, (uint8)sizeof(u8LSSFuncSts));
	*data = u8LSSFuncSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8LSSFuncSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSFUNCSTS, &u8LSSFuncSts, (uint8)sizeof(u8LSSFuncSts));
	*data = u8LSSFuncSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8LSSFuncSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSFUNCSTS, &u8LSSFuncSts, (uint8)sizeof(u8LSSFuncSts));
	*data = u8LSSFuncSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_LSSErrSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8LSSErrSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSERRSTS, &u8LSSErrSts, (uint8)sizeof(u8LSSErrSts));
	*data = u8LSSErrSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_IFC4_IFC_FD2 IFC4_IFC_FD2;
	result = Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(&IFC4_IFC_FD2);
	*data = IFC4_IFC_FD2.LSSErrSts;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8LSSErrSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSERRSTS, &u8LSSErrSts, (uint8)sizeof(u8LSSErrSts));
	*data = u8LSSErrSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8LSSErrSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSERRSTS, &u8LSSErrSts, (uint8)sizeof(u8LSSErrSts));
	*data = u8LSSErrSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8LSSErrSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSERRSTS, &u8LSSErrSts, (uint8)sizeof(u8LSSErrSts));
	*data = u8LSSErrSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8LSSErrSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSERRSTS, &u8LSSErrSts, (uint8)sizeof(u8LSSErrSts));
	*data = u8LSSErrSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8LSSErrSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSERRSTS, &u8LSSErrSts, (uint8)sizeof(u8LSSErrSts));
	*data = u8LSSErrSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8LSSErrSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSERRSTS, &u8LSSErrSts, (uint8)sizeof(u8LSSErrSts));
	*data = u8LSSErrSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8LSSErrSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSERRSTS, &u8LSSErrSts, (uint8)sizeof(u8LSSErrSts));
	*data = u8LSSErrSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8LSSErrSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSERRSTS, &u8LSSErrSts, (uint8)sizeof(u8LSSErrSts));
	*data = u8LSSErrSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}


#endif

	return result;
}


uint8 FTT_Adapt_GetMessage_IFCCalibrationSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8IFCCalibrationSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFCCALIBRATIONSTS, &u8IFCCalibrationSts, (uint8)sizeof(u8IFCCalibrationSts));
	*data = u8IFCCalibrationSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_IFC4_IFC_FD2 IFC4_IFC_FD2;
	result = Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(&IFC4_IFC_FD2);
	*data = IFC4_IFC_FD2.IFCCalibrationSts;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8IFCCalibrationSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFCCALIBRATIONSTS, &u8IFCCalibrationSts, (uint8)sizeof(u8IFCCalibrationSts));
	*data = u8IFCCalibrationSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8IFCCalibrationSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFCCALIBRATIONSTS, &u8IFCCalibrationSts, (uint8)sizeof(u8IFCCalibrationSts));
	*data = u8IFCCalibrationSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8IFCCalibrationSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFCCALIBRATIONSTS, &u8IFCCalibrationSts, (uint8)sizeof(u8IFCCalibrationSts));
	*data = u8IFCCalibrationSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8IFCCalibrationSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFCCALIBRATIONSTS, &u8IFCCalibrationSts, (uint8)sizeof(u8IFCCalibrationSts));
	*data = u8IFCCalibrationSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8IFCCalibrationSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFCCALIBRATIONSTS, &u8IFCCalibrationSts, (uint8)sizeof(u8IFCCalibrationSts));
	*data = u8IFCCalibrationSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8IFCCalibrationSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFCCALIBRATIONSTS, &u8IFCCalibrationSts, (uint8)sizeof(u8IFCCalibrationSts));
	*data = u8IFCCalibrationSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8IFCCalibrationSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFCCALIBRATIONSTS, &u8IFCCalibrationSts, (uint8)sizeof(u8IFCCalibrationSts));
	*data = u8IFCCalibrationSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8IFCCalibrationSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFCCALIBRATIONSTS, &u8IFCCalibrationSts, (uint8)sizeof(u8IFCCalibrationSts));
	*data = u8IFCCalibrationSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}


uint8 FTT_Adapt_GetMessage_CameraBlockageSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8CameraBlockageSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CAMERABLOCKAGESTS, &u8CameraBlockageSts, (uint8)sizeof(u8CameraBlockageSts));
	*data = u8CameraBlockageSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_IFC4_IFC_FD2 IFC4_IFC_FD2;
	result = Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(&IFC4_IFC_FD2);
	*data = IFC4_IFC_FD2.CameraBlockageSts ? 1u : 0u;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8CameraBlockageSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CAMERABLOCKAGESTS, &u8CameraBlockageSts, (uint8)sizeof(u8CameraBlockageSts));
	*data = u8CameraBlockageSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8CameraBlockageSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CAMERABLOCKAGESTS, &u8CameraBlockageSts, (uint8)sizeof(u8CameraBlockageSts));
	*data = u8CameraBlockageSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8CameraBlockageSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CAMERABLOCKAGESTS, &u8CameraBlockageSts, (uint8)sizeof(u8CameraBlockageSts));
	*data = u8CameraBlockageSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8CameraBlockageSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CAMERABLOCKAGESTS, &u8CameraBlockageSts, (uint8)sizeof(u8CameraBlockageSts));
	*data = u8CameraBlockageSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8CameraBlockageSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CAMERABLOCKAGESTS, &u8CameraBlockageSts, (uint8)sizeof(u8CameraBlockageSts));
	*data = u8CameraBlockageSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8CameraBlockageSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CAMERABLOCKAGESTS, &u8CameraBlockageSts, (uint8)sizeof(u8CameraBlockageSts));
	*data = u8CameraBlockageSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8CameraBlockageSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CAMERABLOCKAGESTS, &u8CameraBlockageSts, (uint8)sizeof(u8CameraBlockageSts));
	*data = u8CameraBlockageSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8CameraBlockageSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CAMERABLOCKAGESTS, &u8CameraBlockageSts, (uint8)sizeof(u8CameraBlockageSts));
	*data = u8CameraBlockageSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}


uint8 FTT_Adapt_GetMessage_BMS4_PBF(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8BMS_ErrCategory = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, &u8BMS_ErrCategory, (uint8)sizeof(u8BMS_ErrCategory));
	*data = u8BMS_ErrCategory;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_BMS4 SG_BMS4_PBF;
	result = Rte_Read_SG_BMS4_SG_BMS4(&SG_BMS4_PBF);
	*data = SG_BMS4_PBF.BMS_ErrCategory;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8BMS_ErrCategory = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, &u8BMS_ErrCategory, (uint8)sizeof(u8BMS_ErrCategory));
	*data = u8BMS_ErrCategory;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8BMS_ErrCategory = 0;
	// result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, &u8BMS_ErrCategory, (uint8)sizeof(u8BMS_ErrCategory));
	*data = u8BMS_ErrCategory;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8BMS_ErrCategory = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, &u8BMS_ErrCategory, (uint8)sizeof(u8BMS_ErrCategory));
	*data = u8BMS_ErrCategory;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8BMS_ErrCategory = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, &u8BMS_ErrCategory, (uint8)sizeof(u8BMS_ErrCategory));
	*data = u8BMS_ErrCategory;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8BMS_ErrCategory = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, &u8BMS_ErrCategory, (uint8)sizeof(u8BMS_ErrCategory));
	*data = u8BMS_ErrCategory;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8BMS_ErrCategory = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, &u8BMS_ErrCategory, (uint8)sizeof(u8BMS_ErrCategory));
	*data = u8BMS_ErrCategory;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_AVHSts(uint8 *data_s,uint8 *data_t)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8AVHErrSts = 0;
	uint8 u8AVHSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, &u8AVHErrSts, (uint8)sizeof(u8AVHErrSts));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHSTS, &u8AVHSts, (uint8)sizeof(u8AVHSts));
	*data_s = u8AVHErrSts;
	*data_t = u8AVHSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8AVHErrSts = 0;
	uint8 u8AVHSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, &u8AVHErrSts, (uint8)sizeof(u8AVHErrSts));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHSTS, &u8AVHSts, (uint8)sizeof(u8AVHSts));
	*data_s = u8AVHErrSts;
	*data_t = u8AVHSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_ESP2 ESP2;
	SG_ESP2_ESP_FD2 ESP_FD2;
	if(TT_Adapt_Signal_Source() == TT_CANFD_SIGNAL)
	{
		result = Rte_Read_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2(&ESP_FD2);
		*data_s = ESP_FD2.AVHErrSts_0x137;
		*data_t = ESP_FD2.AVHSts_0x137;
	}
	else
	{
		result = Rte_Read_SG_ESP2_SG_ESP2(&ESP2);
		*data_s = ESP2.AVHErrSts_0x145;
		*data_t = ESP2.AVHSts_0x145;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8AVHErrSts = 0;
	uint8 u8AVHSts = 0;
	if(TT_Adapt_Signal_Source() == TT_CANFD_SIGNAL)
	{
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS_0X137, &u8AVHErrSts, (uint8)sizeof(u8AVHErrSts));
		(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHSTS_0X137, &u8AVHSts, (uint8)sizeof(u8AVHSts));
	}
	else
	{
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS_0X145, &u8AVHErrSts, (uint8)sizeof(u8AVHErrSts));
		(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHSTS_0X145, &u8AVHSts, (uint8)sizeof(u8AVHSts));
	}

	*data_s = u8AVHErrSts;
	*data_t = u8AVHSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8AVHErrSts = 0;
	uint8 u8AVHSts = 0;
	// if(TT_Adapt_Signal_Source() == TT_CANFD_SIGNAL)
	// {
	// 	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS_0X137, &u8AVHErrSts, (uint8)sizeof(u8AVHErrSts));
	// 	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHSTS_0X137, &u8AVHSts, (uint8)sizeof(u8AVHSts));
	// }
	// else
	{
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, &u8AVHErrSts, (uint8)sizeof(u8AVHErrSts));
		(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHSTS, &u8AVHSts, (uint8)sizeof(u8AVHSts));
	}

	*data_s = u8AVHErrSts;
	*data_t = u8AVHSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8AVHErrSts = 0;
	uint8 u8AVHSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, &u8AVHErrSts, (uint8)sizeof(u8AVHErrSts));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHSTS, &u8AVHSts, (uint8)sizeof(u8AVHSts));
	*data_s = u8AVHErrSts;
	*data_t = u8AVHSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8AVHErrSts = 0;
	uint8 u8AVHSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, &u8AVHErrSts, (uint8)sizeof(u8AVHErrSts));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHSTS, &u8AVHSts, (uint8)sizeof(u8AVHSts));
	*data_s = u8AVHErrSts;
	*data_t = u8AVHSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8AVHErrSts = 0;
	uint8 u8AVHSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, &u8AVHErrSts, (uint8)sizeof(u8AVHErrSts));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHSTS, &u8AVHSts, (uint8)sizeof(u8AVHSts));
	*data_s = u8AVHErrSts;
	*data_t = u8AVHSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8AVHErrSts = 0;
	uint8 u8AVHSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, &u8AVHErrSts, (uint8)sizeof(u8AVHErrSts));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHSTS, &u8AVHSts, (uint8)sizeof(u8AVHSts));
	*data_s = u8AVHErrSts;
	*data_t = u8AVHSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
		uint8 u8AVHErrSts = 0;
		uint8 u8AVHSts = 0;
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, &u8AVHErrSts, (uint8)sizeof(u8AVHErrSts));
		(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHSTS, &u8AVHSts, (uint8)sizeof(u8AVHSts));
		*data_s = u8AVHErrSts;
		*data_t = u8AVHSts;
		if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
		{
			result = RTE_E_OK;
		}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_HDCSts(uint8 *data_s,uint8 *data_t)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8HDCFault  = 0;
	uint8 u8HDCCtrl = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT, &u8HDCFault, (uint8)sizeof(u8HDCFault));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCCTRL, &u8HDCCtrl, (uint8)sizeof(u8HDCCtrl));
	*data_s = u8HDCFault;
	*data_t = u8HDCCtrl;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8HDCFault  = 0;
	uint8 u8HDCCtrl = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT, &u8HDCFault, (uint8)sizeof(u8HDCFault));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCCTRL, &u8HDCCtrl, (uint8)sizeof(u8HDCCtrl));
	*data_s = u8HDCFault;
	*data_t = u8HDCCtrl;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_ESP2 ESP2;
	SG_ESP2_ESP_FD2 ESP_FD2;
	if(TT_Adapt_Signal_Source() == TT_CANFD_SIGNAL)
	{
		result = Rte_Read_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2(&ESP_FD2);
		*data_s = ESP_FD2.HDCFault_0x137;
		*data_t = ESP_FD2.HDCCtrl_0x137;
	}
	else
	{
		result = Rte_Read_SG_ESP2_SG_ESP2(&ESP2);
		*data_s = ESP2.HDCFault_0x145;
		*data_t = ESP2.HDCCtrl_0x145;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8HDCFault  = 0;
	uint8 u8HDCCtrl = 0;
	if(TT_Adapt_Signal_Source() == TT_CANFD_SIGNAL)
	{
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT_0X137, &u8HDCFault, (uint8)sizeof(u8HDCFault));
		(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCCTRL_0X137, &u8HDCCtrl, (uint8)sizeof(u8HDCCtrl));
	}
	else
	{
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT_0X145, &u8HDCFault, (uint8)sizeof(u8HDCFault));
		(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCCTRL_0X145, &u8HDCCtrl, (uint8)sizeof(u8HDCCtrl));
	}

	*data_s = u8HDCFault;
	*data_t = u8HDCCtrl;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8HDCFault  = 0;
	uint8 u8HDCCtrl = 0;
	// if(TT_Adapt_Signal_Source() == TT_CANFD_SIGNAL)
	// {
	// 	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT_0X137, &u8HDCFault, (uint8)sizeof(u8HDCFault));
	// 	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCCTRL_0X137, &u8HDCCtrl, (uint8)sizeof(u8HDCCtrl));
	// }
	// else
	{
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT, &u8HDCFault, (uint8)sizeof(u8HDCFault));
		(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCCTRL, &u8HDCCtrl, (uint8)sizeof(u8HDCCtrl));
	}

	*data_s = u8HDCFault;
	*data_t = u8HDCCtrl;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8HDCFault  = 0;
	uint8 u8HDCCtrl = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT, &u8HDCFault, (uint8)sizeof(u8HDCFault));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCCTRL, &u8HDCCtrl, (uint8)sizeof(u8HDCCtrl));
	*data_s = u8HDCFault;
	*data_t = u8HDCCtrl;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8HDCFault  = 0;
	uint8 u8HDCCtrl = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT, &u8HDCFault, (uint8)sizeof(u8HDCFault));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCCTRL, &u8HDCCtrl, (uint8)sizeof(u8HDCCtrl));
	*data_s = u8HDCFault;
	*data_t = u8HDCCtrl;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8HDCFault  = 0;
	uint8 u8HDCCtrl = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT, &u8HDCFault, (uint8)sizeof(u8HDCFault));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCCTRL, &u8HDCCtrl, (uint8)sizeof(u8HDCCtrl));
	*data_s = u8HDCFault;
	*data_t = u8HDCCtrl;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8HDCFault  = 0;
	uint8 u8HDCCtrl = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT, &u8HDCFault, (uint8)sizeof(u8HDCFault));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCCTRL, &u8HDCCtrl, (uint8)sizeof(u8HDCCtrl));
	*data_s = u8HDCFault;
	*data_t = u8HDCCtrl;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
		uint8 u8HDCFault  = 0;
		uint8 u8HDCCtrl = 0;
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT, &u8HDCFault, (uint8)sizeof(u8HDCFault));
		(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCCTRL, &u8HDCCtrl, (uint8)sizeof(u8HDCCtrl));
		*data_s = u8HDCFault;
		*data_t = u8HDCCtrl;
		if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
		{
			result = RTE_E_OK;
		}
#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_CDPActv(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8CDPActv = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV, &u8CDPActv, (uint8)sizeof(u8CDPActv));
	*data = u8CDPActv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8CDPActv = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV, &u8CDPActv, (uint8)sizeof(u8CDPActv));
	*data = u8CDPActv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_ESP2 ESP2;
	SG_ESP2_ESP_FD2 ESP_FD2;
	if(TT_Adapt_Signal_Source() == TT_CANFD_SIGNAL)
	{
		result = Rte_Read_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2(&ESP_FD2);
		*data = ESP_FD2.CDPActv_0x137 ? 1u : 0u;
	}
	else
	{
		result = Rte_Read_SG_ESP2_SG_ESP2(&ESP2);
		*data = ESP2.CDPActv_0x145 ? 1u : 0u;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8CDPActv = 0;
	if(TT_Adapt_Signal_Source() == TT_CANFD_SIGNAL)
	{
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV_0X137, &u8CDPActv, (uint8)sizeof(u8CDPActv));
	}
	else
	{
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV_0X145, &u8CDPActv, (uint8)sizeof(u8CDPActv));
	}

	*data = u8CDPActv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8CDPActv = 0;
	// if(TT_Adapt_Signal_Source() == TT_CANFD_SIGNAL)
	// {
	// 	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV_0X137, &u8CDPActv, (uint8)sizeof(u8CDPActv));
	// }
	// else
	{
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV, &u8CDPActv, (uint8)sizeof(u8CDPActv));
	}

	*data = u8CDPActv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8CDPActv = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV, &u8CDPActv, (uint8)sizeof(u8CDPActv));
	*data = u8CDPActv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8CDPActv = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV, &u8CDPActv, (uint8)sizeof(u8CDPActv));
	*data = u8CDPActv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8CDPActv = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV, &u8CDPActv, (uint8)sizeof(u8CDPActv));
	*data = u8CDPActv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8CDPActv = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV, &u8CDPActv, (uint8)sizeof(u8CDPActv));
	*data = u8CDPActv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8CDPActv = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CDPACTV, &u8CDPActv, (uint8)sizeof(u8CDPActv));
	*data = u8CDPActv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_EPBRedLmpSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8EPBRedLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBREDLMPSTS, &u8EPBRedLmpSts, (uint8)sizeof(u8EPBRedLmpSts));
	*data = u8EPBRedLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_EPB1 EPB1;
	result = Rte_Read_SG_EPB1_SG_EPB1(&EPB1);
	*data = EPB1.EPBRedLmpSts;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8EPBRedLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBREDLMPSTS, &u8EPBRedLmpSts, (uint8)sizeof(u8EPBRedLmpSts));
	*data = u8EPBRedLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8EPBRedLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBREDLMPSTS, &u8EPBRedLmpSts, (uint8)sizeof(u8EPBRedLmpSts));
	*data = u8EPBRedLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8EPBRedLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBREDLMPSTS, &u8EPBRedLmpSts, (uint8)sizeof(u8EPBRedLmpSts));
	*data = u8EPBRedLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8EPBRedLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBREDLMPSTS, &u8EPBRedLmpSts, (uint8)sizeof(u8EPBRedLmpSts));
	*data = u8EPBRedLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8EPBRedLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBREDLMPSTS, &u8EPBRedLmpSts, (uint8)sizeof(u8EPBRedLmpSts));
	*data = u8EPBRedLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8EPBRedLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBREDLMPSTS, &u8EPBRedLmpSts, (uint8)sizeof(u8EPBRedLmpSts));
	*data = u8EPBRedLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8EPBRedLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBREDLMPSTS, &u8EPBRedLmpSts, (uint8)sizeof(u8EPBRedLmpSts));
	*data = u8EPBRedLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8EPBRedLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBREDLMPSTS, &u8EPBRedLmpSts, (uint8)sizeof(u8EPBRedLmpSts));
	*data = u8EPBRedLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_FFogLmpSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8FFogLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FFOGLMPSTS_F_PBOX, &u8FFogLmpSts, (uint8)sizeof(u8FFogLmpSts));
	*data = u8FFogLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_FFogLmpSts_F_Pbox_FFogLmpSts_F_Pbox(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8FFogLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FFOGLMPSTS_F_PBOX, &u8FFogLmpSts, (uint8)sizeof(u8FFogLmpSts));
	*data = u8FFogLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8FFogLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FFOGLMPSTS_F_PBOX, &u8FFogLmpSts, (uint8)sizeof(u8FFogLmpSts));
	*data = u8FFogLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8FFogLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FFOGLMPSTS_F_PBOX, &u8FFogLmpSts, (uint8)sizeof(u8FFogLmpSts));
	*data = u8FFogLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8FFogLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FFOGLMPSTS_F_PBOX, &u8FFogLmpSts, (uint8)sizeof(u8FFogLmpSts));
	*data = u8FFogLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8FFogLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FFOGLMPSTS_F_PBOX, &u8FFogLmpSts, (uint8)sizeof(u8FFogLmpSts));
	*data = u8FFogLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8FFogLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FFOGLMPSTS_F_PBOX, &u8FFogLmpSts, (uint8)sizeof(u8FFogLmpSts));
	*data = u8FFogLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
		uint8 u8FFogLmpSts = 0;
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FFOGLMPSTS_F_PBOX, &u8FFogLmpSts, (uint8)sizeof(u8FFogLmpSts));
		*data = u8FFogLmpSts;
		if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
		{
			result = RTE_E_OK;
		}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_RFogLmpSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8RFogLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RFOGLMPSTS_R_PBOX, &u8RFogLmpSts, (uint8)sizeof(u8RFogLmpSts));
	*data = u8RFogLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_RFogLmpSts_R_Pbox_RFogLmpSts_R_Pbox(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8RFogLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RFOGLMPSTS_R_PBOX, &u8RFogLmpSts, (uint8)sizeof(u8RFogLmpSts));
	*data = u8RFogLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8RFogLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RFOGLMPSTS_R_PBOX, &u8RFogLmpSts, (uint8)sizeof(u8RFogLmpSts));
	*data = u8RFogLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8RFogLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RFOGLMPSTS_R_PBOX, &u8RFogLmpSts, (uint8)sizeof(u8RFogLmpSts));
	*data = u8RFogLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8RFogLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RFOGLMPSTS_R_PBOX, &u8RFogLmpSts, (uint8)sizeof(u8RFogLmpSts));
	*data = u8RFogLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8RFogLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RFOGLMPSTS_R_PBOX, &u8RFogLmpSts, (uint8)sizeof(u8RFogLmpSts));
	*data = u8RFogLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8RFogLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RFOGLMPSTS_R_PBOX, &u8RFogLmpSts, (uint8)sizeof(u8RFogLmpSts));
	*data = u8RFogLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8RFogLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RFOGLMPSTS_R_PBOX, &u8RFogLmpSts, (uint8)sizeof(u8RFogLmpSts));
	*data = u8RFogLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8RFogLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RFOGLMPSTS_R_PBOX, &u8RFogLmpSts, (uint8)sizeof(u8RFogLmpSts));
	*data = u8RFogLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_RHiBeamSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8RHiBeamSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHIBEAMSTS, &u8RHiBeamSts, (uint8)sizeof(u8RHiBeamSts));
	*data = u8RHiBeamSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8RHiBeamSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHIBEAMSTS, &u8RHiBeamSts, (uint8)sizeof(u8RHiBeamSts));
	*data = u8RHiBeamSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8RHiBeamSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHIBEAMSTS, &u8RHiBeamSts, (uint8)sizeof(u8RHiBeamSts));
	*data = u8RHiBeamSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	*data = 0;

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_LHiBeamSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8LHiBeamSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHIBEAMSTS, &u8LHiBeamSts, (uint8)sizeof(u8LHiBeamSts));
	*data = u8LHiBeamSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8LHiBeamSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHIBEAMSTS, &u8LHiBeamSts, (uint8)sizeof(u8LHiBeamSts));
	*data = u8LHiBeamSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8LHiBeamSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHIBEAMSTS, &u8LHiBeamSts, (uint8)sizeof(u8LHiBeamSts));
	*data = u8LHiBeamSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8LHiBeamSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHIBEAMSTS, &u8LHiBeamSts, (uint8)sizeof(u8LHiBeamSts));
	*data = u8LHiBeamSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	*data = 0;


#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_HighBeamSts_HC(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B03))
	SG_HC1 HC1;
	result = Rte_Read_SG_HC1_SG_HC1(&HC1);
	*data = HC1.HighBeamSts_HC ? 1u : 0u;
#elif (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	*data = 0;

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_HiBeamSts_F_PBOX(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8HiBeamSts_F_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIBEAMSTS_F_PBOX, &u8HiBeamSts_F_PBOX, (uint8)sizeof(u8HiBeamSts_F_PBOX));
	*data = u8HiBeamSts_F_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_HiBeamSts_F_Pbox_HiBeamSts_F_Pbox(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8HiBeamSts_F_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIBEAMSTS_F_PBOX, &u8HiBeamSts_F_PBOX, (uint8)sizeof(u8HiBeamSts_F_PBOX));
	*data = u8HiBeamSts_F_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8HiBeamSts_F_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIBEAMSTS_F_PBOX, &u8HiBeamSts_F_PBOX, (uint8)sizeof(u8HiBeamSts_F_PBOX));
	*data = u8HiBeamSts_F_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8HiBeamSts_F_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIBEAMSTS_F_PBOX, &u8HiBeamSts_F_PBOX, (uint8)sizeof(u8HiBeamSts_F_PBOX));
	*data = u8HiBeamSts_F_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8HiBeamSts_F_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIBEAMSTS_F_PBOX, &u8HiBeamSts_F_PBOX, (uint8)sizeof(u8HiBeamSts_F_PBOX));
	*data = u8HiBeamSts_F_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8HiBeamSts_F_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIBEAMSTS_F_PBOX, &u8HiBeamSts_F_PBOX, (uint8)sizeof(u8HiBeamSts_F_PBOX));
	*data = u8HiBeamSts_F_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8HiBeamSts_F_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIBEAMSTS_F_PBOX, &u8HiBeamSts_F_PBOX, (uint8)sizeof(u8HiBeamSts_F_PBOX));
	*data = u8HiBeamSts_F_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8HiBeamSts_F_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIBEAMSTS_F_PBOX, &u8HiBeamSts_F_PBOX, (uint8)sizeof(u8HiBeamSts_F_PBOX));
	*data = u8HiBeamSts_F_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8HiBeamSts_F_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIBEAMSTS_F_PBOX, &u8HiBeamSts_F_PBOX, (uint8)sizeof(u8HiBeamSts_F_PBOX));
	*data = u8HiBeamSts_F_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}
#if 0
uint8 FTT_Adapt_GetMessage_HighBeamSts_FCM(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8HiBeamSts_FCM = 0;
	//result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIBEAMOUTPUTSTS_FCM, &u8HiBeamSts_FCM, (uint8)sizeof(u8HiBeamSts_FCM));
	*data = u8HiBeamSts_FCM;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#endif

	return result;
}
#endif

uint8 FTT_Adapt_GetMessage_LTurnLmpSts_R_PBOX(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8LTurnLmpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LTURNLMPSTS_R_PBOX, &u8LTurnLmpSts_R_PBOX, (uint8)sizeof(u8LTurnLmpSts_R_PBOX));
	*data = u8LTurnLmpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_LTurnLmpSts_R_Pbox_LTurnLmpSts_R_Pbox(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8LTurnLmpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LTURNLMPSTS_R_PBOX, &u8LTurnLmpSts_R_PBOX, (uint8)sizeof(u8LTurnLmpSts_R_PBOX));
	*data = u8LTurnLmpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8LTurnLmpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LTURNLMPSTS_R_PBOX, &u8LTurnLmpSts_R_PBOX, (uint8)sizeof(u8LTurnLmpSts_R_PBOX));
	*data = u8LTurnLmpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8LTurnLmpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LTURNLMPSTS_R_PBOX, &u8LTurnLmpSts_R_PBOX, (uint8)sizeof(u8LTurnLmpSts_R_PBOX));
	*data = u8LTurnLmpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8LTurnLmpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LTURNLMPSTS_R_PBOX, &u8LTurnLmpSts_R_PBOX, (uint8)sizeof(u8LTurnLmpSts_R_PBOX));
	*data = u8LTurnLmpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8LTurnLmpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LTURNLMPSTS_R_PBOX, &u8LTurnLmpSts_R_PBOX, (uint8)sizeof(u8LTurnLmpSts_R_PBOX));
	*data = u8LTurnLmpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8LTurnLmpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LTURNLMPSTS_R_PBOX, &u8LTurnLmpSts_R_PBOX, (uint8)sizeof(u8LTurnLmpSts_R_PBOX));
	*data = u8LTurnLmpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8LTurnLmpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LTURNLMPSTS_R_PBOX, &u8LTurnLmpSts_R_PBOX, (uint8)sizeof(u8LTurnLmpSts_R_PBOX));
	*data = u8LTurnLmpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8LTurnLmpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LTURNLMPSTS_R_PBOX, &u8LTurnLmpSts_R_PBOX, (uint8)sizeof(u8LTurnLmpSts_R_PBOX));
	*data = u8LTurnLmpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_RTurnLmpSts_R_PBOX(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8RTurnLmpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RTURNLMPSTS_R_PBOX, &u8RTurnLmpSts_R_PBOX, (uint8)sizeof(u8RTurnLmpSts_R_PBOX));
	*data = u8RTurnLmpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_RTurnLmpSts_R_Pbox_RTurnLmpSts_R_Pbox(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8RTurnLmpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RTURNLMPSTS_R_PBOX, &u8RTurnLmpSts_R_PBOX, (uint8)sizeof(u8RTurnLmpSts_R_PBOX));
	*data = u8RTurnLmpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8RTurnLmpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RTURNLMPSTS_R_PBOX, &u8RTurnLmpSts_R_PBOX, (uint8)sizeof(u8RTurnLmpSts_R_PBOX));
	*data = u8RTurnLmpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8RTurnLmpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RTURNLMPSTS_R_PBOX, &u8RTurnLmpSts_R_PBOX, (uint8)sizeof(u8RTurnLmpSts_R_PBOX));
	*data = u8RTurnLmpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8RTurnLmpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RTURNLMPSTS_R_PBOX, &u8RTurnLmpSts_R_PBOX, (uint8)sizeof(u8RTurnLmpSts_R_PBOX));
	*data = u8RTurnLmpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8RTurnLmpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RTURNLMPSTS_R_PBOX, &u8RTurnLmpSts_R_PBOX, (uint8)sizeof(u8RTurnLmpSts_R_PBOX));
	*data = u8RTurnLmpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8RTurnLmpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RTURNLMPSTS_R_PBOX, &u8RTurnLmpSts_R_PBOX, (uint8)sizeof(u8RTurnLmpSts_R_PBOX));
	*data = u8RTurnLmpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8RTurnLmpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RTURNLMPSTS_R_PBOX, &u8RTurnLmpSts_R_PBOX, (uint8)sizeof(u8RTurnLmpSts_R_PBOX));
	*data = u8RTurnLmpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8RTurnLmpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RTURNLMPSTS_R_PBOX, &u8RTurnLmpSts_R_PBOX, (uint8)sizeof(u8RTurnLmpSts_R_PBOX));
	*data = u8RTurnLmpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_PosnLmpOutpSts_R_PBOX(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8PosnLmpOutpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POSNLMPOUTPSTS_R_PBOX, &u8PosnLmpOutpSts_R_PBOX, (uint8)sizeof(u8PosnLmpOutpSts_R_PBOX));
	*data = u8PosnLmpOutpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_PosnLmpOutpSts_R_Pbox_PosnLmpOutpSts_R_Pbox(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8PosnLmpOutpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POSNLMPOUTPSTS_R_PBOX, &u8PosnLmpOutpSts_R_PBOX, (uint8)sizeof(u8PosnLmpOutpSts_R_PBOX));
	*data = u8PosnLmpOutpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8PosnLmpOutpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POSNLMPOUTPSTS_R_PBOX, &u8PosnLmpOutpSts_R_PBOX, (uint8)sizeof(u8PosnLmpOutpSts_R_PBOX));
	*data = u8PosnLmpOutpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8PosnLmpOutpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POSNLMPOUTPSTS_R_PBOX, &u8PosnLmpOutpSts_R_PBOX, (uint8)sizeof(u8PosnLmpOutpSts_R_PBOX));
	*data = u8PosnLmpOutpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8PosnLmpOutpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POSNLMPOUTPSTS_R_PBOX, &u8PosnLmpOutpSts_R_PBOX, (uint8)sizeof(u8PosnLmpOutpSts_R_PBOX));
	*data = u8PosnLmpOutpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8PosnLmpOutpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POSNLMPOUTPSTS_R_PBOX, &u8PosnLmpOutpSts_R_PBOX, (uint8)sizeof(u8PosnLmpOutpSts_R_PBOX));
	*data = u8PosnLmpOutpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8PosnLmpOutpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POSNLMPOUTPSTS_R_PBOX, &u8PosnLmpOutpSts_R_PBOX, (uint8)sizeof(u8PosnLmpOutpSts_R_PBOX));
	*data = u8PosnLmpOutpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8PosnLmpOutpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POSNLMPOUTPSTS_R_PBOX, &u8PosnLmpOutpSts_R_PBOX, (uint8)sizeof(u8PosnLmpOutpSts_R_PBOX));
	*data = u8PosnLmpOutpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8PosnLmpOutpSts_R_PBOX = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POSNLMPOUTPSTS_R_PBOX, &u8PosnLmpOutpSts_R_PBOX, (uint8)sizeof(u8PosnLmpOutpSts_R_PBOX));
	*data = u8PosnLmpOutpSts_R_PBOX;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_TrailerSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_TrailerSts_TrailerSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8TrailerSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRAILERSTS, &u8TrailerSts, (uint8)sizeof(u8TrailerSts));
	*data = u8TrailerSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8TrailerSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRAILERSTS, &u8TrailerSts, (uint8)sizeof(u8TrailerSts));
	*data = u8TrailerSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8TrailerSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRAILERSTS, &u8TrailerSts, (uint8)sizeof(u8TrailerSts));
	*data = u8TrailerSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8TrailerSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRAILERSTS, &u8TrailerSts, (uint8)sizeof(u8TrailerSts));
	*data = u8TrailerSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8TrailerSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRAILERSTS, &u8TrailerSts, (uint8)sizeof(u8TrailerSts));
	*data = u8TrailerSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8TrailerSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRAILERSTS, &u8TrailerSts, (uint8)sizeof(u8TrailerSts));
	*data = u8TrailerSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	*data = 0;

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_DrvDoorSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8DrvDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, &u8DrvDoorSts, (uint8)sizeof(u8DrvDoorSts));
	*data = u8DrvDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_DrvDoorSts_DrvDoorSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8DrvDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, &u8DrvDoorSts, (uint8)sizeof(u8DrvDoorSts));
	*data = u8DrvDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8DrvDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, &u8DrvDoorSts, (uint8)sizeof(u8DrvDoorSts));
	*data = u8DrvDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8DrvDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, &u8DrvDoorSts, (uint8)sizeof(u8DrvDoorSts));
	*data = u8DrvDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8DrvDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, &u8DrvDoorSts, (uint8)sizeof(u8DrvDoorSts));
	*data = u8DrvDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8DrvDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, &u8DrvDoorSts, (uint8)sizeof(u8DrvDoorSts));
	*data = u8DrvDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8DrvDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, &u8DrvDoorSts, (uint8)sizeof(u8DrvDoorSts));
	*data = u8DrvDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8DrvDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, &u8DrvDoorSts, (uint8)sizeof(u8DrvDoorSts));
	*data = u8DrvDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8DrvDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, &u8DrvDoorSts, (uint8)sizeof(u8DrvDoorSts));
	*data = u8DrvDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_HoodSts_F_Pbox(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8HoodSts_F_Pbox = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOODSTS_F_PBOX, &u8HoodSts_F_Pbox, (uint8)sizeof(u8HoodSts_F_Pbox));
	*data = u8HoodSts_F_Pbox;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_HoodSts_F_Pbox_HoodSts_F_Pbox(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8HoodSts_F_Pbox = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOODSTS_F_PBOX, &u8HoodSts_F_Pbox, (uint8)sizeof(u8HoodSts_F_Pbox));
	*data = u8HoodSts_F_Pbox;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8HoodSts_F_Pbox = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOODSTS_F_PBOX, &u8HoodSts_F_Pbox, (uint8)sizeof(u8HoodSts_F_Pbox));
	*data = u8HoodSts_F_Pbox;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8HoodSts_F_Pbox = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOODSTS_F_PBOX, &u8HoodSts_F_Pbox, (uint8)sizeof(u8HoodSts_F_Pbox));
	*data = u8HoodSts_F_Pbox;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8HoodSts_F_Pbox = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOODSTS_F_PBOX, &u8HoodSts_F_Pbox, (uint8)sizeof(u8HoodSts_F_Pbox));
	*data = u8HoodSts_F_Pbox;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8HoodSts_F_Pbox = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOODSTS_F_PBOX, &u8HoodSts_F_Pbox, (uint8)sizeof(u8HoodSts_F_Pbox));
	*data = u8HoodSts_F_Pbox;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8HoodSts_F_Pbox = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOODSTS_F_PBOX, &u8HoodSts_F_Pbox, (uint8)sizeof(u8HoodSts_F_Pbox));
	*data = u8HoodSts_F_Pbox;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8HoodSts_F_Pbox = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOODSTS_F_PBOX, &u8HoodSts_F_Pbox, (uint8)sizeof(u8HoodSts_F_Pbox));
	*data = u8HoodSts_F_Pbox;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8HoodSts_F_Pbox = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOODSTS_F_PBOX, &u8HoodSts_F_Pbox, (uint8)sizeof(u8HoodSts_F_Pbox));
	*data = u8HoodSts_F_Pbox;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_PassengerDoorSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8PassengerDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS, &u8PassengerDoorSts, (uint8)sizeof(u8PassengerDoorSts));
	*data = u8PassengerDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_PassengerDoorSts_PassengerDoorSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8PassengerDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS, &u8PassengerDoorSts, (uint8)sizeof(u8PassengerDoorSts));
	*data = u8PassengerDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8PassengerDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS, &u8PassengerDoorSts, (uint8)sizeof(u8PassengerDoorSts));
	*data = u8PassengerDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8PassengerDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS, &u8PassengerDoorSts, (uint8)sizeof(u8PassengerDoorSts));
	*data = u8PassengerDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8PassengerDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS, &u8PassengerDoorSts, (uint8)sizeof(u8PassengerDoorSts));
	*data = u8PassengerDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8PassengerDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS, &u8PassengerDoorSts, (uint8)sizeof(u8PassengerDoorSts));
	*data = u8PassengerDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8PassengerDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS, &u8PassengerDoorSts, (uint8)sizeof(u8PassengerDoorSts));
	*data = u8PassengerDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8PassengerDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS, &u8PassengerDoorSts, (uint8)sizeof(u8PassengerDoorSts));
	*data = u8PassengerDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8PassengerDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS, &u8PassengerDoorSts, (uint8)sizeof(u8PassengerDoorSts));
	*data = u8PassengerDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_LRDoorSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8LRDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS, &u8LRDoorSts, (uint8)sizeof(u8LRDoorSts));
	*data = u8LRDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_LRDoorSts_LRDoorSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8LRDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS, &u8LRDoorSts, (uint8)sizeof(u8LRDoorSts));
	*data = u8LRDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8LRDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS, &u8LRDoorSts, (uint8)sizeof(u8LRDoorSts));
	*data = u8LRDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8LRDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS, &u8LRDoorSts, (uint8)sizeof(u8LRDoorSts));
	*data = u8LRDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8LRDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS, &u8LRDoorSts, (uint8)sizeof(u8LRDoorSts));
	*data = u8LRDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8LRDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS, &u8LRDoorSts, (uint8)sizeof(u8LRDoorSts));
	*data = u8LRDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8LRDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS, &u8LRDoorSts, (uint8)sizeof(u8LRDoorSts));
	*data = u8LRDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8LRDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS, &u8LRDoorSts, (uint8)sizeof(u8LRDoorSts));
	*data = u8LRDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8LRDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS, &u8LRDoorSts, (uint8)sizeof(u8LRDoorSts));
	*data = u8LRDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_RRDoorSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8RRDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS, &u8RRDoorSts, (uint8)sizeof(u8RRDoorSts));
	*data = u8RRDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_RRDoorSts_RRDoorSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8RRDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS, &u8RRDoorSts, (uint8)sizeof(u8RRDoorSts));
	*data = u8RRDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8RRDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS, &u8RRDoorSts, (uint8)sizeof(u8RRDoorSts));
	*data = u8RRDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8RRDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS, &u8RRDoorSts, (uint8)sizeof(u8RRDoorSts));
	*data = u8RRDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8RRDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS, &u8RRDoorSts, (uint8)sizeof(u8RRDoorSts));
	*data = u8RRDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8RRDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS, &u8RRDoorSts, (uint8)sizeof(u8RRDoorSts));
	*data = u8RRDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8RRDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS, &u8RRDoorSts, (uint8)sizeof(u8RRDoorSts));
	*data = u8RRDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8RRDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS, &u8RRDoorSts, (uint8)sizeof(u8RRDoorSts));
	*data = u8RRDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8RRDoorSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS, &u8RRDoorSts, (uint8)sizeof(u8RRDoorSts));
	*data = u8RRDoorSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_TrunkSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8TrunkSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS, &u8TrunkSts, (uint8)sizeof(u8TrunkSts));
	*data = u8TrunkSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_TrunkSts_TrunkSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8TrunkSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS, &u8TrunkSts, (uint8)sizeof(u8TrunkSts));
	*data = u8TrunkSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8TrunkSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS, &u8TrunkSts, (uint8)sizeof(u8TrunkSts));
	*data = u8TrunkSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8TrunkSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS, &u8TrunkSts, (uint8)sizeof(u8TrunkSts));
	*data = u8TrunkSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8TrunkSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS, &u8TrunkSts, (uint8)sizeof(u8TrunkSts));
	*data = u8TrunkSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8TrunkSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS, &u8TrunkSts, (uint8)sizeof(u8TrunkSts));
	*data = u8TrunkSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8TrunkSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS, &u8TrunkSts, (uint8)sizeof(u8TrunkSts));
	*data = u8TrunkSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8TrunkSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS, &u8TrunkSts, (uint8)sizeof(u8TrunkSts));
	*data = u8TrunkSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8TrunkSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS, &u8TrunkSts, (uint8)sizeof(u8TrunkSts));
	*data = u8TrunkSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_DrvSBR_Visual(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8DrvSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVSBR_VISUAL, &u8DrvSBR_Visual, (uint8)sizeof(u8DrvSBR_Visual));
	*data = u8DrvSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_ABM1 ABM1;
	result = Rte_Read_SG_ABM1_SG_ABM1(&ABM1);
	*data = ABM1.DrvSBR_Visual;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8DrvSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVSBR_VISUAL, &u8DrvSBR_Visual, (uint8)sizeof(u8DrvSBR_Visual));
	*data = u8DrvSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8DrvSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVSBR_VISUAL, &u8DrvSBR_Visual, (uint8)sizeof(u8DrvSBR_Visual));
	*data = u8DrvSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8DrvSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVSBR_VISUAL, &u8DrvSBR_Visual, (uint8)sizeof(u8DrvSBR_Visual));
	*data = u8DrvSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8DrvSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVSBR_VISUAL, &u8DrvSBR_Visual, (uint8)sizeof(u8DrvSBR_Visual));
	*data = u8DrvSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8DrvSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVSBR_VISUAL, &u8DrvSBR_Visual, (uint8)sizeof(u8DrvSBR_Visual));
	*data = u8DrvSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8DrvSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVSBR_VISUAL, &u8DrvSBR_Visual, (uint8)sizeof(u8DrvSBR_Visual));
	*data = u8DrvSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8DrvSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVSBR_VISUAL, &u8DrvSBR_Visual, (uint8)sizeof(u8DrvSBR_Visual));
	*data = u8DrvSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8DrvSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVSBR_VISUAL, &u8DrvSBR_Visual, (uint8)sizeof(u8DrvSBR_Visual));
	*data = u8DrvSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_PassSBR_Visual(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8PassSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSSBR_VISUAL, &u8PassSBR_Visual, (uint8)sizeof(u8PassSBR_Visual));
	*data = u8PassSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_ABM1 ABM1;
	result = Rte_Read_SG_ABM1_SG_ABM1(&ABM1);
	*data = ABM1.PassSBR_Visual;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8PassSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSSBR_VISUAL, &u8PassSBR_Visual, (uint8)sizeof(u8PassSBR_Visual));
	*data = u8PassSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8PassSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSSBR_VISUAL, &u8PassSBR_Visual, (uint8)sizeof(u8PassSBR_Visual));
	*data = u8PassSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8PassSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSSBR_VISUAL, &u8PassSBR_Visual, (uint8)sizeof(u8PassSBR_Visual));
	*data = u8PassSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8PassSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSSBR_VISUAL, &u8PassSBR_Visual, (uint8)sizeof(u8PassSBR_Visual));
	*data = u8PassSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8PassSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSSBR_VISUAL, &u8PassSBR_Visual, (uint8)sizeof(u8PassSBR_Visual));
	*data = u8PassSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8PassSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSSBR_VISUAL, &u8PassSBR_Visual, (uint8)sizeof(u8PassSBR_Visual));
	*data = u8PassSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8PassSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSSBR_VISUAL, &u8PassSBR_Visual, (uint8)sizeof(u8PassSBR_Visual));
	*data = u8PassSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8PassSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSSBR_VISUAL, &u8PassSBR_Visual, (uint8)sizeof(u8PassSBR_Visual));
	*data = u8PassSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}


uint8 FTT_Adapt_GetMessage_SecRowLSBR_Visual(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8SecRowLSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWLSBR_VISUAL, &u8SecRowLSBR_Visual, (uint8)sizeof(u8SecRowLSBR_Visual));
	*data = u8SecRowLSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_ABM1 ABM1;

	result = Rte_Read_SG_ABM1_SG_ABM1(&ABM1);
	*data = ABM1.SecRowLSBR_Visual;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8SecRowLSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWLSBR_VISUAL, &u8SecRowLSBR_Visual, (uint8)sizeof(u8SecRowLSBR_Visual));
	*data = u8SecRowLSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8SecRowLSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWLSBR_VISUAL, &u8SecRowLSBR_Visual, (uint8)sizeof(u8SecRowLSBR_Visual));
	*data = u8SecRowLSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8SecRowLSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWLSBR_VISUAL, &u8SecRowLSBR_Visual, (uint8)sizeof(u8SecRowLSBR_Visual));
	*data = u8SecRowLSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8SecRowLSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWLSBR_VISUAL, &u8SecRowLSBR_Visual, (uint8)sizeof(u8SecRowLSBR_Visual));
	*data = u8SecRowLSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8SecRowLSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWLSBR_VISUAL, &u8SecRowLSBR_Visual, (uint8)sizeof(u8SecRowLSBR_Visual));
	*data = u8SecRowLSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8SecRowLSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWLSBR_VISUAL, &u8SecRowLSBR_Visual, (uint8)sizeof(u8SecRowLSBR_Visual));
	*data = u8SecRowLSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8SecRowLSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWLSBR_VISUAL, &u8SecRowLSBR_Visual, (uint8)sizeof(u8SecRowLSBR_Visual));
	*data = u8SecRowLSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8SecRowLSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWLSBR_VISUAL, &u8SecRowLSBR_Visual, (uint8)sizeof(u8SecRowLSBR_Visual));
	*data = u8SecRowLSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}


uint8 FTT_Adapt_GetMessage_SecRowMidSBR_Visual(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8SecRowMidSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWMIDSBR_VISUAL, &u8SecRowMidSBR_Visual, (uint8)sizeof(u8SecRowMidSBR_Visual));
	*data = u8SecRowMidSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_ABM1 ABM1;

	result = Rte_Read_SG_ABM1_SG_ABM1(&ABM1);
	*data = ABM1.SecRowMidSBR_Visual;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8SecRowMidSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWMIDSBR_VISUAL, &u8SecRowMidSBR_Visual, (uint8)sizeof(u8SecRowMidSBR_Visual));
	*data = u8SecRowMidSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8SecRowMidSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWMIDSBR_VISUAL, &u8SecRowMidSBR_Visual, (uint8)sizeof(u8SecRowMidSBR_Visual));
	*data = u8SecRowMidSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8SecRowMidSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWMIDSBR_VISUAL, &u8SecRowMidSBR_Visual, (uint8)sizeof(u8SecRowMidSBR_Visual));
	*data = u8SecRowMidSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8SecRowMidSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWMIDSBR_VISUAL, &u8SecRowMidSBR_Visual, (uint8)sizeof(u8SecRowMidSBR_Visual));
	*data = u8SecRowMidSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8SecRowMidSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWMIDSBR_VISUAL, &u8SecRowMidSBR_Visual, (uint8)sizeof(u8SecRowMidSBR_Visual));
	*data = u8SecRowMidSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8SecRowMidSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWMIDSBR_VISUAL, &u8SecRowMidSBR_Visual, (uint8)sizeof(u8SecRowMidSBR_Visual));
	*data = u8SecRowMidSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8SecRowMidSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWMIDSBR_VISUAL, &u8SecRowMidSBR_Visual, (uint8)sizeof(u8SecRowMidSBR_Visual));
	*data = u8SecRowMidSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8SecRowMidSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWMIDSBR_VISUAL, &u8SecRowMidSBR_Visual, (uint8)sizeof(u8SecRowMidSBR_Visual));
	*data = u8SecRowMidSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}


uint8 FTT_Adapt_GetMessage_SecRowRSBR_Visual(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8SecRowRSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWRSBR_VISUAL, &u8SecRowRSBR_Visual, (uint8)sizeof(u8SecRowRSBR_Visual));
	*data = u8SecRowRSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_ABM1 ABM1;
	result = Rte_Read_SG_ABM1_SG_ABM1(&ABM1);
	*data = ABM1.SecRowRSBR_Visual;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8SecRowRSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWRSBR_VISUAL, &u8SecRowRSBR_Visual, (uint8)sizeof(u8SecRowRSBR_Visual));
	*data = u8SecRowRSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8SecRowRSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWRSBR_VISUAL, &u8SecRowRSBR_Visual, (uint8)sizeof(u8SecRowRSBR_Visual));
	*data = u8SecRowRSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8SecRowRSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWRSBR_VISUAL, &u8SecRowRSBR_Visual, (uint8)sizeof(u8SecRowRSBR_Visual));
	*data = u8SecRowRSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8SecRowRSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWRSBR_VISUAL, &u8SecRowRSBR_Visual, (uint8)sizeof(u8SecRowRSBR_Visual));
	*data = u8SecRowRSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8SecRowRSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWRSBR_VISUAL, &u8SecRowRSBR_Visual, (uint8)sizeof(u8SecRowRSBR_Visual));
	*data = u8SecRowRSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8SecRowRSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWRSBR_VISUAL, &u8SecRowRSBR_Visual, (uint8)sizeof(u8SecRowRSBR_Visual));
	*data = u8SecRowRSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8SecRowRSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWRSBR_VISUAL, &u8SecRowRSBR_Visual, (uint8)sizeof(u8SecRowRSBR_Visual));
	*data = u8SecRowRSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8SecRowRSBR_Visual = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWRSBR_VISUAL, &u8SecRowRSBR_Visual, (uint8)sizeof(u8SecRowRSBR_Visual));
	*data = u8SecRowRSBR_Visual;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}


uint8 FTT_Adapt_GetMessage_DrvWarnMsg(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B03))
	if(TT_Adapt_Signal_Source() == TT_CAN_SIGNAL)
	{
		SG_DCT7 DCT7;
		result = Rte_Read_SG_DCT7_SG_DCT7(&DCT7);
		*data = DCT7.DrvWarnMsg;
	}
	else
	{
		result = RTE_E_INVALID;
		*data = 0;
	}
#elif (defined(SWC_TT_ADAPT_B02))
	uint8 u8DrvWarnMsg = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, &u8DrvWarnMsg, (uint8)sizeof(u8DrvWarnMsg));
	*data = u8DrvWarnMsg;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8DrvWarnMsg = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, &u8DrvWarnMsg, (uint8)sizeof(u8DrvWarnMsg));
	*data = u8DrvWarnMsg;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8DrvWarnMsg = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, &u8DrvWarnMsg, (uint8)sizeof(u8DrvWarnMsg));
	*data = u8DrvWarnMsg;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8DrvWarnMsg = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, &u8DrvWarnMsg, (uint8)sizeof(u8DrvWarnMsg));
	*data = u8DrvWarnMsg;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8DrvWarnMsg = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, &u8DrvWarnMsg, (uint8)sizeof(u8DrvWarnMsg));
	*data = u8DrvWarnMsg;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8DrvWarnMsg = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, &u8DrvWarnMsg, (uint8)sizeof(u8DrvWarnMsg));
	*data = u8DrvWarnMsg;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8DrvWarnMsg = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, &u8DrvWarnMsg, (uint8)sizeof(u8DrvWarnMsg));
	*data = u8DrvWarnMsg;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8DrvWarnMsg = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, &u8DrvWarnMsg, (uint8)sizeof(u8DrvWarnMsg));
	*data = u8DrvWarnMsg;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8DrvWarnMsg = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, &u8DrvWarnMsg, (uint8)sizeof(u8DrvWarnMsg));
	*data = u8DrvWarnMsg;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_ClutchHotWarning(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8ClutchHotWarning = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_CLUTCHHOTWARNING, &u8ClutchHotWarning, (uint8)sizeof(u8ClutchHotWarning));
	*data = u8ClutchHotWarning;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_DHT_FD1 SG_DHT_FD1_Trans;
	result = Rte_Read_SG_DHT_FD1_SG_DHT_FD1(&SG_DHT_FD1_Trans);
	*data = SG_DHT_FD1_Trans.TCU_ClutchHotWarning;
#elif (defined(SWC_TT_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8ClutchHotWarning = 0;
	// result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_CLUTCHHOTWARNING, &u8ClutchHotWarning, (uint8)sizeof(u8ClutchHotWarning));
	*data = u8ClutchHotWarning;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	*data = 0;


#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_Warn_high_temp(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_P05))
	uint8 u8Warn_high_temp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_WARN_HIGH_TEMP, &u8Warn_high_temp, (uint8)sizeof(u8Warn_high_temp));
	*data = u8Warn_high_temp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	*data = 0;

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_HiLowBeamSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8HiLowBeamSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HILOWBEAMSTS, &u8HiLowBeamSts, (uint8)sizeof(u8HiLowBeamSts));
	*data = u8HiLowBeamSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_HiLowBeamSts_HiLowBeamSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8HiLowBeamSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HILOWBEAMSTS, &u8HiLowBeamSts, (uint8)sizeof(u8HiLowBeamSts));
	*data = u8HiLowBeamSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8HiLowBeamSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HILOWBEAMSTS, &u8HiLowBeamSts, (uint8)sizeof(u8HiLowBeamSts));
	*data = u8HiLowBeamSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8HiLowBeamSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HILOWBEAMSTS, &u8HiLowBeamSts, (uint8)sizeof(u8HiLowBeamSts));
	*data = u8HiLowBeamSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8HiLowBeamSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HILOWBEAMSTS, &u8HiLowBeamSts, (uint8)sizeof(u8HiLowBeamSts));
	*data = u8HiLowBeamSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8HiLowBeamSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HILOWBEAMSTS, &u8HiLowBeamSts, (uint8)sizeof(u8HiLowBeamSts));
	*data = u8HiLowBeamSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8HiLowBeamSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HILOWBEAMSTS, &u8HiLowBeamSts, (uint8)sizeof(u8HiLowBeamSts));
	*data = u8HiLowBeamSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8HiLowBeamSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HILOWBEAMSTS, &u8HiLowBeamSts, (uint8)sizeof(u8HiLowBeamSts));
	*data = u8HiLowBeamSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8HiLowBeamSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HILOWBEAMSTS, &u8HiLowBeamSts, (uint8)sizeof(u8HiLowBeamSts));
	*data = u8HiLowBeamSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_ADBstatus(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B03))
	SG_HC1 HC1;
	result = Rte_Read_SG_HC1_SG_HC1(&HC1);
	*data = HC1.ADBstatus;
#elif (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	*data = 0;

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_LADBstatus(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8LADBstatus = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LADBSTATUS, &u8LADBstatus, (uint8)sizeof(u8LADBstatus));
	*data = u8LADBstatus;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8LADBstatus = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LADBSTATUS, &u8LADBstatus, (uint8)sizeof(u8LADBstatus));
	*data = u8LADBstatus;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	*data = 0;

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_RADBstatus(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8RADBstatus = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RADBSTATUS, &u8RADBstatus, (uint8)sizeof(u8RADBstatus));
	*data = u8RADBstatus;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8RADBstatus = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RADBSTATUS, &u8RADBstatus, (uint8)sizeof(u8RADBstatus));
	*data = u8RADBstatus;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	*data = 0;

#endif

	return result;
}

uint8 FTT_Adapt_GetFuelModule_Data(FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	result = Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(data);
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(data);
#elif (defined(SWC_TT_ADAPT_P03))
	result = Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(data);
#elif (defined(SWC_TT_ADAPT_P05))
	result = Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(data);
#elif (defined(SWC_TT_ADAPT_A07))
	result = Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(data);
#elif (defined(SWC_TT_ADAPT_D01))
	result = Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(data);
#elif (defined(SWC_TT_ADAPT_D02))
	result = Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(data);
#elif (defined(SWC_TT_ADAPT_D03))
	result = Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(data);
#elif (defined(SWC_TT_ADAPT_P02))
	result = Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(data);
#elif (defined(SWC_TT_ADAPT_P01))
	result = Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(data);

#endif
	return result;
}

uint8 FTT_Adapt_GetSelfChecksts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	result = Rte_Read_tiSR_SWC_TT_SelfCheck_Element(data);
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_tiSR_SWC_TT_SelfCheck_Element(data);
#elif (defined(SWC_TT_ADAPT_P03))
	result = Rte_Read_tiSR_SWC_TT_SelfCheck_Element(data);
#elif (defined(SWC_TT_ADAPT_P05))
	result = Rte_Read_tiSR_SWC_TT_SelfCheck_Element(data);
#elif (defined(SWC_TT_ADAPT_A07))
	result = Rte_Read_tiSR_SWC_TT_SelfCheck_Element(data);
#elif (defined(SWC_TT_ADAPT_D01))
	result = Rte_Read_tiSR_SWC_TT_SelfCheck_Element(data);
#elif (defined(SWC_TT_ADAPT_D02))
	result = Rte_Read_tiSR_SWC_TT_SelfCheck_Element(data);
#elif (defined(SWC_TT_ADAPT_D03))
	result = Rte_Read_tiSR_SWC_TT_SelfCheck_Element(data);
#elif (defined(SWC_TT_ADAPT_P02))
	result = Rte_Read_tiSR_SWC_TT_SelfCheck_Element(data);

#endif
	return result;
}


uint8 FTT_Adapt_GetMessage_RdyLmpSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8RdyLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS, &u8RdyLmpSts, (uint8)sizeof(u8RdyLmpSts));
	*data = u8RdyLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_HCU_PT7 SG_HCU_PT7_READY;
	result = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&SG_HCU_PT7_READY);
	*data = SG_HCU_PT7_READY.HCU_RdyLmpSts ? 1u : 0u;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8RdyLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS, &u8RdyLmpSts, (uint8)sizeof(u8RdyLmpSts));
	*data = u8RdyLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8RdyLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS, &u8RdyLmpSts, (uint8)sizeof(u8RdyLmpSts));
	*data = u8RdyLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8RdyLmpSts = 0;
	// result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS, &u8RdyLmpSts, (uint8)sizeof(u8RdyLmpSts));
	*data = u8RdyLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8RdyLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS, &u8RdyLmpSts, (uint8)sizeof(u8RdyLmpSts));
	*data = u8RdyLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8RdyLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS, &u8RdyLmpSts, (uint8)sizeof(u8RdyLmpSts));
	*data = u8RdyLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8RdyLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS, &u8RdyLmpSts, (uint8)sizeof(u8RdyLmpSts));
	*data = u8RdyLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8RdyLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS, &u8RdyLmpSts, (uint8)sizeof(u8RdyLmpSts));
	*data = u8RdyLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8RdyLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS, &u8RdyLmpSts, (uint8)sizeof(u8RdyLmpSts));
	*data = u8RdyLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_EVLmpSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8EVLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVLMPSTS, &u8EVLmpSts, (uint8)sizeof(u8EVLmpSts));
	*data = u8EVLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_HCU_EVLmpSts_HCU_EVLmpSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8EVLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVLMPSTS, &u8EVLmpSts, (uint8)sizeof(u8EVLmpSts));
	*data = u8EVLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8EVLmpSts = 0;
	// result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVLMPSTS, &u8EVLmpSts, (uint8)sizeof(u8EVLmpSts));
	*data = u8EVLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8EVLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVLMPSTS, &u8EVLmpSts, (uint8)sizeof(u8EVLmpSts));
	*data = u8EVLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8EVLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVLMPSTS, &u8EVLmpSts, (uint8)sizeof(u8EVLmpSts));
	*data = u8EVLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8EVLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVLMPSTS, &u8EVLmpSts, (uint8)sizeof(u8EVLmpSts));
	*data = u8EVLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8EVLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVLMPSTS, &u8EVLmpSts, (uint8)sizeof(u8EVLmpSts));
	*data = u8EVLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8EVLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVLMPSTS, &u8EVLmpSts, (uint8)sizeof(u8EVLmpSts));
	*data = u8EVLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_ChrgSysLmpSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8ChrgSysLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSLMPSTS, &u8ChrgSysLmpSts, (uint8)sizeof(u8ChrgSysLmpSts));
	*data = u8ChrgSysLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_HCU_ChrgSysLmpSts_HCU_ChrgSysLmpSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8ChrgSysLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSLMPSTS, &u8ChrgSysLmpSts, (uint8)sizeof(u8ChrgSysLmpSts));
	*data = u8ChrgSysLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8ChrgSysLmpSts = 0;
	// result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSLMPSTS, &u8ChrgSysLmpSts, (uint8)sizeof(u8ChrgSysLmpSts));
	*data = u8ChrgSysLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8ChrgSysLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSLMPSTS, &u8ChrgSysLmpSts, (uint8)sizeof(u8ChrgSysLmpSts));
	*data = u8ChrgSysLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8ChrgSysLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSLMPSTS, &u8ChrgSysLmpSts, (uint8)sizeof(u8ChrgSysLmpSts));
	*data = u8ChrgSysLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8ChrgSysLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSLMPSTS, &u8ChrgSysLmpSts, (uint8)sizeof(u8ChrgSysLmpSts));
	*data = u8ChrgSysLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	*data = 0;

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_PowerRedWarnLmpCmd(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8PowerRedWarnLmpCmd = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_POWERREDWARNLMPCMD, &u8PowerRedWarnLmpCmd, (uint8)sizeof(u8PowerRedWarnLmpCmd));
	*data = u8PowerRedWarnLmpCmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_HCU_PT7 SG_HCU_PT7_Power;
	result = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&SG_HCU_PT7_Power);
	*data = SG_HCU_PT7_Power.HCU_PowerRedWarnLmpCmd ? 1u : 0u;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8PowerRedWarnLmpCmd = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_POWERREDWARNLMPCMD, &u8PowerRedWarnLmpCmd, (uint8)sizeof(u8PowerRedWarnLmpCmd));
	*data = u8PowerRedWarnLmpCmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8PowerRedWarnLmpCmd = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_POWERREDWARNLMPCMD, &u8PowerRedWarnLmpCmd, (uint8)sizeof(u8PowerRedWarnLmpCmd));
	*data = u8PowerRedWarnLmpCmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8PowerRedWarnLmpCmd = 0;
	// result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_POWERREDWARNLMPCMD, &u8PowerRedWarnLmpCmd, (uint8)sizeof(u8PowerRedWarnLmpCmd));
	*data = u8PowerRedWarnLmpCmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8PowerRedWarnLmpCmd = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_POWERREDWARNLMPCMD, &u8PowerRedWarnLmpCmd, (uint8)sizeof(u8PowerRedWarnLmpCmd));
	*data = u8PowerRedWarnLmpCmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8PowerRedWarnLmpCmd = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_POWERREDWARNLMPCMD, &u8PowerRedWarnLmpCmd, (uint8)sizeof(u8PowerRedWarnLmpCmd));
	*data = u8PowerRedWarnLmpCmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8PowerRedWarnLmpCmd = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_POWERREDWARNLMPCMD, &u8PowerRedWarnLmpCmd, (uint8)sizeof(u8PowerRedWarnLmpCmd));
	*data = u8PowerRedWarnLmpCmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8PowerRedWarnLmpCmd = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_POWERREDWARNLMPCMD, &u8PowerRedWarnLmpCmd, (uint8)sizeof(u8PowerRedWarnLmpCmd));
	*data = u8PowerRedWarnLmpCmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8PowerRedWarnLmpCmd = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_POWERREDWARNLMPCMD, &u8PowerRedWarnLmpCmd, (uint8)sizeof(u8PowerRedWarnLmpCmd));
	*data = u8PowerRedWarnLmpCmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_ParkLmpSts_R_Pbox(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8ParkLmpSts_R_Pbox = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PARKLMPSTS_R_PBOX, &u8ParkLmpSts_R_Pbox, (uint8)sizeof(u8ParkLmpSts_R_Pbox));
	*data = u8ParkLmpSts_R_Pbox;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_ParkLmpSts_R_Pbox_ParkLmpSts_R_Pbox(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8ParkLmpSts_R_Pbox = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PARKLMPSTS_R_PBOX, &u8ParkLmpSts_R_Pbox, (uint8)sizeof(u8ParkLmpSts_R_Pbox));
	*data = u8ParkLmpSts_R_Pbox;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8ParkLmpSts_R_Pbox = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PARKLMPSTS_R_PBOX, &u8ParkLmpSts_R_Pbox, (uint8)sizeof(u8ParkLmpSts_R_Pbox));
	*data = u8ParkLmpSts_R_Pbox;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8ParkLmpSts_R_Pbox = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PARKLMPSTS_R_PBOX, &u8ParkLmpSts_R_Pbox, (uint8)sizeof(u8ParkLmpSts_R_Pbox));
	*data = u8ParkLmpSts_R_Pbox;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8ParkLmpSts_R_Pbox = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PARKLMPSTS_R_PBOX, &u8ParkLmpSts_R_Pbox, (uint8)sizeof(u8ParkLmpSts_R_Pbox));
	*data = u8ParkLmpSts_R_Pbox;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8ParkLmpSts_R_Pbox = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PARKLMPSTS_R_PBOX, &u8ParkLmpSts_R_Pbox, (uint8)sizeof(u8ParkLmpSts_R_Pbox));
	*data = u8ParkLmpSts_R_Pbox;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8ParkLmpSts_R_Pbox = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PARKLMPSTS_R_PBOX, &u8ParkLmpSts_R_Pbox, (uint8)sizeof(u8ParkLmpSts_R_Pbox));
	*data = u8ParkLmpSts_R_Pbox;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8ParkLmpSts_R_Pbox = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PARKLMPSTS_R_PBOX, &u8ParkLmpSts_R_Pbox, (uint8)sizeof(u8ParkLmpSts_R_Pbox));
	*data = u8ParkLmpSts_R_Pbox;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8ParkLmpSts_R_Pbox = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PARKLMPSTS_R_PBOX, &u8ParkLmpSts_R_Pbox, (uint8)sizeof(u8ParkLmpSts_R_Pbox));
	*data = u8ParkLmpSts_R_Pbox;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

// case2: PHEV/HEV ESP10 0x0D8
uint8 FTT_Adapt_GetMessage_ESP_TgtRcprtnTrqSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8TgtRcprtnTrqSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTRCPRTNTRQSTS, &u8TgtRcprtnTrqSts, (uint8)sizeof(u8TgtRcprtnTrqSts));
	*data = u8TgtRcprtnTrqSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_TgtRcprtnTrqSts_TgtRcprtnTrqSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8TgtRcprtnTrqSts = 0;
	// result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTRCPRTNTRQSTS, &u8TgtRcprtnTrqSts, (uint8)sizeof(u8TgtRcprtnTrqSts));
	*data = u8TgtRcprtnTrqSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8TgtRcprtnTrqSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTRCPRTNTRQSTS_0XD8, &u8TgtRcprtnTrqSts, (uint8)sizeof(u8TgtRcprtnTrqSts));
	*data = u8TgtRcprtnTrqSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8TgtRcprtnTrqSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTRCPRTNTRQSTS_0XD8, &u8TgtRcprtnTrqSts, (uint8)sizeof(u8TgtRcprtnTrqSts));
	*data = u8TgtRcprtnTrqSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8TgtRcprtnTrqSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTRCPRTNTRQSTS_0XD8, &u8TgtRcprtnTrqSts, (uint8)sizeof(u8TgtRcprtnTrqSts));
	*data = u8TgtRcprtnTrqSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8TgtRcprtnTrqSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTRCPRTNTRQSTS, &u8TgtRcprtnTrqSts, (uint8)sizeof(u8TgtRcprtnTrqSts));
	*data = u8TgtRcprtnTrqSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

// case1: P0 HCU_HC16 0x09E
uint8 FTT_Adapt_GetMessage_HCU_TgtRcprtnTrqSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8TgtRcprtnTrqSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTRCPRTNTRQSTS, &u8TgtRcprtnTrqSts, (uint8)sizeof(u8TgtRcprtnTrqSts));
	*data = u8TgtRcprtnTrqSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8TgtRcprtnTrqSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTRCPRTNTRQSTS, &u8TgtRcprtnTrqSts, (uint8)sizeof(u8TgtRcprtnTrqSts));
	*data = u8TgtRcprtnTrqSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8TgtRcprtnTrqSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTRCPRTNTRQSTS_0X9E, &u8TgtRcprtnTrqSts, (uint8)sizeof(u8TgtRcprtnTrqSts));
	*data = u8TgtRcprtnTrqSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8TgtRcprtnTrqSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTRCPRTNTRQSTS_0X9E, &u8TgtRcprtnTrqSts, (uint8)sizeof(u8TgtRcprtnTrqSts));
	*data = u8TgtRcprtnTrqSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8TgtRcprtnTrqSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTRCPRTNTRQSTS_0X9E, &u8TgtRcprtnTrqSts, (uint8)sizeof(u8TgtRcprtnTrqSts));
	*data = u8TgtRcprtnTrqSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8TgtRcprtnTrqSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTRCPRTNTRQSTS, &u8TgtRcprtnTrqSts, (uint8)sizeof(u8TgtRcprtnTrqSts));
	*data = u8TgtRcprtnTrqSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8TgtRcprtnTrqSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTRCPRTNTRQSTS, &u8TgtRcprtnTrqSts, (uint8)sizeof(u8TgtRcprtnTrqSts));
	*data = u8TgtRcprtnTrqSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

// case3: PHEV/HEV EBooster_FD1 0x12D
uint8 FTT_Adapt_GetMessage_EB_TgtRcprtnTrqSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8TgtRcprtnTrqSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EB_TGTRCPRTNTRQSTS, &u8TgtRcprtnTrqSts, (uint8)sizeof(u8TgtRcprtnTrqSts));
	*data = u8TgtRcprtnTrqSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8TgtRcprtnTrqSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EB_TGTRCPRTNTRQSTS, &u8TgtRcprtnTrqSts, (uint8)sizeof(u8TgtRcprtnTrqSts));
	*data = u8TgtRcprtnTrqSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	*data = 0;

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_GlowPlugLmpCmd(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_P05))
	uint8 u8GlowPlugLmpCmd = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GLOWPLUGLMPCMD, &u8GlowPlugLmpCmd, (uint8)sizeof(u8GlowPlugLmpCmd));
	*data = u8GlowPlugLmpCmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8GlowPlugLmpCmd = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GLOWPLUGLMPCMD, &u8GlowPlugLmpCmd, (uint8)sizeof(u8GlowPlugLmpCmd));
	*data = u8GlowPlugLmpCmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8GlowPlugLmpCmd = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GLOWPLUGLMPCMD, &u8GlowPlugLmpCmd, (uint8)sizeof(u8GlowPlugLmpCmd));
	*data = u8GlowPlugLmpCmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_CCO_Active(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_CCO_Active_CCO_Active(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8CCO_Active = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_ACTIVE, &u8CCO_Active, (uint8)sizeof(u8CCO_Active));
	*data = u8CCO_Active;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8CCO_Active = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_ACTIVE, &u8CCO_Active, (uint8)sizeof(u8CCO_Active));
	*data = u8CCO_Active;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8CCO_Active = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_ACTIVE, &u8CCO_Active, (uint8)sizeof(u8CCO_Active));
	*data = u8CCO_Active;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8CCO_Active = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_ACTIVE, &u8CCO_Active, (uint8)sizeof(u8CCO_Active));
	*data = u8CCO_Active;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8CCO_Active = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_ACTIVE, &u8CCO_Active, (uint8)sizeof(u8CCO_Active));
	*data = u8CCO_Active;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8CCO_Active = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_ACTIVE, &u8CCO_Active, (uint8)sizeof(u8CCO_Active));
	*data = u8CCO_Active;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8CCO_Active = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_ACTIVE, &u8CCO_Active, (uint8)sizeof(u8CCO_Active));
	*data = u8CCO_Active;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_RearELDLckSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_P05))
	uint8 u8RearELDLckSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARELDLCKSTS, &u8RearELDLckSts, (uint8)sizeof(u8RearELDLckSts));
	*data = u8RearELDLckSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_RearELDLckSts_RearELDLckSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8RearELDLckSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARELDLCKSTS, &u8RearELDLckSts, (uint8)sizeof(u8RearELDLckSts));
	*data = u8RearELDLckSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8RearELDLckSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARELDLCKSTS, &u8RearELDLckSts, (uint8)sizeof(u8RearELDLckSts));
	*data = u8RearELDLckSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8RearELDLckSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARELDLCKSTS, &u8RearELDLckSts, (uint8)sizeof(u8RearELDLckSts));
	*data = u8RearELDLckSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8RearELDLckSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARELDLCKSTS, &u8RearELDLckSts, (uint8)sizeof(u8RearELDLckSts));
	*data = u8RearELDLckSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8RearELDLckSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARELDLCKSTS, &u8RearELDLckSts, (uint8)sizeof(u8RearELDLckSts));
	*data = u8RearELDLckSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8RearELDLckSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARELDLCKSTS, &u8RearELDLckSts, (uint8)sizeof(u8RearELDLckSts));
	*data = u8RearELDLckSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_FrntELDLckSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_P05))
	uint8 u8FrntELDLckSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRNTELDLCKSTS, &u8FrntELDLckSts, (uint8)sizeof(u8FrntELDLckSts));
	*data = u8FrntELDLckSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8FrntELDLckSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRNTELDLCKSTS, &u8FrntELDLckSts, (uint8)sizeof(u8FrntELDLckSts));
	*data = u8FrntELDLckSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8FrntELDLckSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRNTELDLCKSTS, &u8FrntELDLckSts, (uint8)sizeof(u8FrntELDLckSts));
	*data = u8FrntELDLckSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8FrntELDLckSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRNTELDLCKSTS, &u8FrntELDLckSts, (uint8)sizeof(u8FrntELDLckSts));
	*data = u8FrntELDLckSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8FrntELDLckSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRNTELDLCKSTS, &u8FrntELDLckSts, (uint8)sizeof(u8FrntELDLckSts));
	*data = u8FrntELDLckSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8FrntELDLckSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRNTELDLCKSTS, &u8FrntELDLckSts, (uint8)sizeof(u8FrntELDLckSts));
	*data = u8FrntELDLckSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8FrntELDLckSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRNTELDLCKSTS, &u8FrntELDLckSts, (uint8)sizeof(u8FrntELDLckSts));
	*data = u8FrntELDLckSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_RSDS_CTA_Actv(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8RSDS_CTA_Actv = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_CTA_ACTV, &u8RSDS_CTA_Actv, (uint8)sizeof(u8RSDS_CTA_Actv));
	*data = u8RSDS_CTA_Actv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_RSDS_CTA_Actv_RSDS_CTA_Actv(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8RSDS_CTA_Actv = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_CTA_ACTV, &u8RSDS_CTA_Actv, (uint8)sizeof(u8RSDS_CTA_Actv));
	*data = u8RSDS_CTA_Actv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8RSDS_CTA_Actv = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_CTA_ACTV, &u8RSDS_CTA_Actv, (uint8)sizeof(u8RSDS_CTA_Actv));
	*data = u8RSDS_CTA_Actv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8RSDS_CTA_Actv = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_CTA_ACTV, &u8RSDS_CTA_Actv, (uint8)sizeof(u8RSDS_CTA_Actv));
	*data = u8RSDS_CTA_Actv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8RSDS_CTA_Actv = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_CTA_ACTV, &u8RSDS_CTA_Actv, (uint8)sizeof(u8RSDS_CTA_Actv));
	*data = u8RSDS_CTA_Actv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8RSDS_CTA_Actv = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_CTA_ACTV, &u8RSDS_CTA_Actv, (uint8)sizeof(u8RSDS_CTA_Actv));
	*data = u8RSDS_CTA_Actv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8RSDS_CTA_Actv = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_CTA_ACTV, &u8RSDS_CTA_Actv, (uint8)sizeof(u8RSDS_CTA_Actv));
	*data = u8RSDS_CTA_Actv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8RSDS_CTA_Actv = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_CTA_ACTV, &u8RSDS_CTA_Actv, (uint8)sizeof(u8RSDS_CTA_Actv));
	*data = u8RSDS_CTA_Actv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8RSDS_CTA_Actv = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_CTA_ACTV, &u8RSDS_CTA_Actv, (uint8)sizeof(u8RSDS_CTA_Actv));
	*data = u8RSDS_CTA_Actv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_RSDS_LCAResp(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8RSDS_LCAResp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_LCARESP, &u8RSDS_LCAResp, (uint8)sizeof(u8RSDS_LCAResp));
	*data = u8RSDS_LCAResp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_RSDS_LCAResp_RSDS_LCAResp(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8RSDS_LCAResp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_LCARESP, &u8RSDS_LCAResp, (uint8)sizeof(u8RSDS_LCAResp));
	*data = u8RSDS_LCAResp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8RSDS_LCAResp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_LCARESP, &u8RSDS_LCAResp, (uint8)sizeof(u8RSDS_LCAResp));
	*data = u8RSDS_LCAResp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8RSDS_LCAResp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_LCARESP, &u8RSDS_LCAResp, (uint8)sizeof(u8RSDS_LCAResp));
	*data = u8RSDS_LCAResp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8RSDS_LCAResp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_LCARESP, &u8RSDS_LCAResp, (uint8)sizeof(u8RSDS_LCAResp));
	*data = u8RSDS_LCAResp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8RSDS_LCAResp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_LCARESP, &u8RSDS_LCAResp, (uint8)sizeof(u8RSDS_LCAResp));
	*data = u8RSDS_LCAResp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8RSDS_LCAResp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_LCARESP, &u8RSDS_LCAResp, (uint8)sizeof(u8RSDS_LCAResp));
	*data = u8RSDS_LCAResp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8RSDS_LCAResp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_LCARESP, &u8RSDS_LCAResp, (uint8)sizeof(u8RSDS_LCAResp));
	*data = u8RSDS_LCAResp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8RSDS_LCAResp = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_LCARESP, &u8RSDS_LCAResp, (uint8)sizeof(u8RSDS_LCAResp));
	*data = u8RSDS_LCAResp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_RSDS_ErrSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8RSDS_ErrSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_ERRSTS, &u8RSDS_ErrSts, (uint8)sizeof(u8RSDS_ErrSts));
	*data = u8RSDS_ErrSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_RSDS_ErrSts_RSDS_ErrSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8RSDS_ErrSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_ERRSTS, &u8RSDS_ErrSts, (uint8)sizeof(u8RSDS_ErrSts));
	*data = u8RSDS_ErrSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8RSDS_ErrSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_ERRSTS, &u8RSDS_ErrSts, (uint8)sizeof(u8RSDS_ErrSts));
	*data = u8RSDS_ErrSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8RSDS_ErrSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_ERRSTS, &u8RSDS_ErrSts, (uint8)sizeof(u8RSDS_ErrSts));
	*data = u8RSDS_ErrSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8RSDS_ErrSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_ERRSTS, &u8RSDS_ErrSts, (uint8)sizeof(u8RSDS_ErrSts));
	*data = u8RSDS_ErrSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8RSDS_ErrSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_ERRSTS, &u8RSDS_ErrSts, (uint8)sizeof(u8RSDS_ErrSts));
	*data = u8RSDS_ErrSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8RSDS_ErrSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_ERRSTS, &u8RSDS_ErrSts, (uint8)sizeof(u8RSDS_ErrSts));
	*data = u8RSDS_ErrSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8RSDS_ErrSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_ERRSTS, &u8RSDS_ErrSts, (uint8)sizeof(u8RSDS_ErrSts));
	*data = u8RSDS_ErrSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8RSDS_ErrSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_ERRSTS, &u8RSDS_ErrSts, (uint8)sizeof(u8RSDS_ErrSts));
	*data = u8RSDS_ErrSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_RemoteModSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8RemoteModSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REMOTEMODSTS, &u8RemoteModSts, (uint8)sizeof(u8RemoteModSts));
	*data = u8RemoteModSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_RemoteModSts_RemoteModSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8RemoteModSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REMOTEMODSTS, &u8RemoteModSts, (uint8)sizeof(u8RemoteModSts));
	*data = u8RemoteModSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8RemoteModSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REMOTEMODSTS, &u8RemoteModSts, (uint8)sizeof(u8RemoteModSts));
	*data = u8RemoteModSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8RemoteModSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REMOTEMODSTS, &u8RemoteModSts, (uint8)sizeof(u8RemoteModSts));
	*data = u8RemoteModSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8RemoteModSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REMOTEMODSTS, &u8RemoteModSts, (uint8)sizeof(u8RemoteModSts));
	*data = u8RemoteModSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8RemoteModSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REMOTEMODSTS, &u8RemoteModSts, (uint8)sizeof(u8RemoteModSts));
	*data = u8RemoteModSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8RemoteModSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REMOTEMODSTS, &u8RemoteModSts, (uint8)sizeof(u8RemoteModSts));
	*data = u8RemoteModSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8RemoteModSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REMOTEMODSTS, &u8RemoteModSts, (uint8)sizeof(u8RemoteModSts));
	*data = u8RemoteModSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8RemoteModSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REMOTEMODSTS, &u8RemoteModSts, (uint8)sizeof(u8RemoteModSts));
	*data = u8RemoteModSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_RSDS_BliSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8RSDS_BliSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_BLISTS, &u8RSDS_BliSts, (uint8)sizeof(u8RSDS_BliSts));
	*data = u8RSDS_BliSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_RSDS_BliSts_RSDS_BliSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8RSDS_BliSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_BLISTS, &u8RSDS_BliSts, (uint8)sizeof(u8RSDS_BliSts));
	*data = u8RSDS_BliSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8RSDS_BliSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_BLISTS, &u8RSDS_BliSts, (uint8)sizeof(u8RSDS_BliSts));
	*data = u8RSDS_BliSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8RSDS_BliSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_BLISTS, &u8RSDS_BliSts, (uint8)sizeof(u8RSDS_BliSts));
	*data = u8RSDS_BliSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8RSDS_BliSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_BLISTS, &u8RSDS_BliSts, (uint8)sizeof(u8RSDS_BliSts));
	*data = u8RSDS_BliSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8RSDS_BliSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_BLISTS, &u8RSDS_BliSts, (uint8)sizeof(u8RSDS_BliSts));
	*data = u8RSDS_BliSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8RSDS_BliSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_BLISTS, &u8RSDS_BliSts, (uint8)sizeof(u8RSDS_BliSts));
	*data = u8RSDS_BliSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8RSDS_BliSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_BLISTS, &u8RSDS_BliSts, (uint8)sizeof(u8RSDS_BliSts));
	*data = u8RSDS_BliSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8RSDS_BliSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_BLISTS, &u8RSDS_BliSts, (uint8)sizeof(u8RSDS_BliSts));
	*data = u8RSDS_BliSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_KL30BRelaySts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8KL30BRelaySts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_KL30BRELAYSTS, &u8KL30BRelaySts, (uint8)sizeof(u8KL30BRelaySts));
	*data = u8KL30BRelaySts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_KL30BRelaySts_KL30BRelaySts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8KL30BRelaySts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_KL30BRELAYSTS, &u8KL30BRelaySts, (uint8)sizeof(u8KL30BRelaySts));
	*data = u8KL30BRelaySts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8KL30BRelaySts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_KL30BRELAYSTS, &u8KL30BRelaySts, (uint8)sizeof(u8KL30BRelaySts));
	*data = u8KL30BRelaySts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8KL30BRelaySts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_KL30BRELAYSTS, &u8KL30BRelaySts, (uint8)sizeof(u8KL30BRelaySts));
	*data = u8KL30BRelaySts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8KL30BRelaySts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_KL30BRELAYSTS, &u8KL30BRelaySts, (uint8)sizeof(u8KL30BRelaySts));
	*data = u8KL30BRelaySts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8KL30BRelaySts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_KL30BRELAYSTS, &u8KL30BRelaySts, (uint8)sizeof(u8KL30BRelaySts));
	*data = u8KL30BRelaySts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8KL30BRelaySts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_KL30BRELAYSTS, &u8KL30BRelaySts, (uint8)sizeof(u8KL30BRelaySts));
	*data = u8KL30BRelaySts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8KL30BRelaySts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_KL30BRELAYSTS, &u8KL30BRelaySts, (uint8)sizeof(u8KL30BRelaySts));
	*data = u8KL30BRelaySts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8KL30BRelaySts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_KL30BRELAYSTS, &u8KL30BRelaySts, (uint8)sizeof(u8KL30BRelaySts));
	*data = u8KL30BRelaySts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_TAB_Sts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8TAB_Sts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TAB_STS, &u8TAB_Sts, (uint8)sizeof(u8TAB_Sts));
	*data = u8TAB_Sts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	if(TT_Adapt_Signal_Source() == TT_CAN_SIGNAL)
	{
		SG_ESP2 ESP2;
		result = Rte_Read_SG_ESP2_SG_ESP2(&ESP2);
		*data = ESP2.TAB_Sts;
	}
	else
	{
		result = RTE_E_INVALID;
		*data = 0;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8TAB_Sts = 0;
	if(TT_Adapt_Signal_Source() == TT_CANFD_SIGNAL)
	{
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TAB_STS_0X137, &u8TAB_Sts, (uint8)sizeof(u8TAB_Sts));
	}
	else
	{
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TAB_STS_0X145, &u8TAB_Sts, (uint8)sizeof(u8TAB_Sts));
	}

	*data = u8TAB_Sts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8TAB_Sts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TAB_STS, &u8TAB_Sts, (uint8)sizeof(u8TAB_Sts));
	*data = u8TAB_Sts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8TAB_Sts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TAB_STS, &u8TAB_Sts, (uint8)sizeof(u8TAB_Sts));
	*data = u8TAB_Sts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8TAB_Sts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TAB_STS, &u8TAB_Sts, (uint8)sizeof(u8TAB_Sts));
	*data = u8TAB_Sts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8TAB_Sts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TAB_STS, &u8TAB_Sts, (uint8)sizeof(u8TAB_Sts));
	*data = u8TAB_Sts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8TAB_Sts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TAB_STS, &u8TAB_Sts, (uint8)sizeof(u8TAB_Sts));
	*data = u8TAB_Sts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8TAB_Sts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TAB_STS, &u8TAB_Sts, (uint8)sizeof(u8TAB_Sts));
	*data = u8TAB_Sts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif
	return result;
}

void FTT_Api_TTCallback(uint8 *data)
{
	u8VSG_SwitchSts = *data;
}

uint8 FTT_Adapt_GetMessage_Builtin_VSG_Sts(uint8 *data)
{
#if (defined(SWC_TT_ADAPT_B02))
	*data = 0;
	//TBD
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
	//TBD
#elif (defined(SWC_TT_ADAPT_P03))
	*data = 0;
	//TBD
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	AVASDTCRet strAVASDTCRte;
	uint8 u8VsgPowerSts = 0;
	uint8 u8VSG_Sts = 0;    // tt off

	u8VsgPowerSts = FTT_Adapt_GetPowerMode_State();
	if(u8VsgPowerSts != SYSTEMSTATE_Cluster_ON)
	{
		u8VSG_SwitchSts = 1;
	}

	if (1 == u8VSG_SwitchSts)
	{
		u8VSG_Sts = 0;    // switch on: tt off
	}
	else if (0 == u8VSG_SwitchSts)
	{
		u8VSG_Sts = 1;    // switch off: yellow on
	}
	else
	{
		u8VSG_Sts = 0;
	}

	(void)Rte_Read_AVASDTCResults_AVASDTC(&strAVASDTCRte);
	if ((1 == strAVASDTCRte.Open) || (1 == strAVASDTCRte.ShortAcross) \
		|| (1 == strAVASDTCRte.ShorttoGND) || (1 == strAVASDTCRte.ShorttoBAT) \
		|| (1 == strAVASDTCRte.OutofRange) || (1 == strAVASDTCRte.Clip))
	{
		u8VSG_Sts = 2;    // AVAS failure: red on
	}
	*data = u8VSG_Sts;
#elif (defined(SWC_TT_ADAPT_D01))
	AVASDTCRet strAVASDTCRte;
	uint8 u8VsgPowerSts = 0;
	uint8 u8VSG_Sts = 0;    // tt off

	u8VsgPowerSts = FTT_Adapt_GetPowerMode_State();
	if(u8VsgPowerSts != SYSTEMSTATE_Cluster_ON)
	{
		u8VSG_SwitchSts = 1;
	}

	if (1 == u8VSG_SwitchSts)
	{
		u8VSG_Sts = 0;    // switch on: tt off
	}
	else if (0 == u8VSG_SwitchSts)
	{
		u8VSG_Sts = 1;    // switch off: yellow on
	}
	else
	{
		u8VSG_Sts = 0;
	}

	(void)Rte_Read_AVASDTCResults_AVASDTC(&strAVASDTCRte);
	if ((1 == strAVASDTCRte.Open) || (1 == strAVASDTCRte.ShortAcross) \
		|| (1 == strAVASDTCRte.ShorttoGND) || (1 == strAVASDTCRte.ShorttoBAT) \
		|| (1 == strAVASDTCRte.OutofRange) || (1 == strAVASDTCRte.Clip))
	{
		u8VSG_Sts = 2;    // AVAS failure: red on
	}
	*data = u8VSG_Sts;
#elif (defined(SWC_TT_ADAPT_D02))
	AVASDTCRet strAVASDTCRte;
	uint8 u8VsgPowerSts = 0;
	uint8 u8VSG_Sts = 0;    // tt off

	u8VsgPowerSts = FTT_Adapt_GetPowerMode_State();
	if(u8VsgPowerSts != SYSTEMSTATE_Cluster_ON)
	{
		u8VSG_SwitchSts = 1;
	}

	if (1 == u8VSG_SwitchSts)
	{
		u8VSG_Sts = 0;    // switch on: tt off
	}
	else if (0 == u8VSG_SwitchSts)
	{
		u8VSG_Sts = 1;    // switch off: yellow on
	}
	else
	{
		u8VSG_Sts = 0;
	}

	(void)Rte_Read_AVASDTCResults_AVASDTC(&strAVASDTCRte);
	if ((1 == strAVASDTCRte.Open) || (1 == strAVASDTCRte.ShortAcross) \
		|| (1 == strAVASDTCRte.ShorttoGND) || (1 == strAVASDTCRte.ShorttoBAT) \
		|| (1 == strAVASDTCRte.OutofRange) || (1 == strAVASDTCRte.Clip))
	{
		u8VSG_Sts = 2;    // AVAS failure: red on
	}
	*data = u8VSG_Sts;
#elif (defined(SWC_TT_ADAPT_D03))
	AVASDTCRet strAVASDTCRte;
	uint8 u8VsgPowerSts = 0;
	uint8 u8VSG_Sts = 0;    // tt off

	u8VsgPowerSts = FTT_Adapt_GetPowerMode_State();
	if(u8VsgPowerSts != SYSTEMSTATE_Cluster_ON)
	{
		u8VSG_SwitchSts = 1;
	}

	if (1 == u8VSG_SwitchSts)
	{
		u8VSG_Sts = 0;    // switch on: tt off
	}
	else if (0 == u8VSG_SwitchSts)
	{
		u8VSG_Sts = 1;    // switch off: yellow on
	}
	else
	{
		u8VSG_Sts = 0;
	}

	(void)Rte_Read_AVASDTCResults_AVASDTC(&strAVASDTCRte);
	if ((1 == strAVASDTCRte.Open) || (1 == strAVASDTCRte.ShortAcross) \
		|| (1 == strAVASDTCRte.ShorttoGND) || (1 == strAVASDTCRte.ShorttoBAT) \
		|| (1 == strAVASDTCRte.OutofRange) || (1 == strAVASDTCRte.Clip))
	{
		u8VSG_Sts = 2;    // AVAS failure: red on
	}
	*data = u8VSG_Sts;
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	*data = 0;

#endif
	return RTE_E_OK;
}

uint8 FTT_Adapt_GetMessage_SOCLowWarn(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8SOCLowWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_SOCLOWWARN, &u8SOCLowWarn, (uint8)sizeof(u8SOCLowWarn));
	*data = u8SOCLowWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_BMS_SOCLowWarn_BMS_SOCLowWarn(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8SOCLowWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_SOCLOWWARN, &u8SOCLowWarn, (uint8)sizeof(u8SOCLowWarn));
	*data = u8SOCLowWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8SOCLowWarn = 0;
	// result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_SOCLOWWARN, &u8SOCLowWarn, (uint8)sizeof(u8SOCLowWarn));
	*data = u8SOCLowWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8SOCLowWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_SOCLOWWARN, &u8SOCLowWarn, (uint8)sizeof(u8SOCLowWarn));
	*data = u8SOCLowWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8SOCLowWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_SOCLOWWARN, &u8SOCLowWarn, (uint8)sizeof(u8SOCLowWarn));
	*data = u8SOCLowWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8SOCLowWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_SOCLOWWARN, &u8SOCLowWarn, (uint8)sizeof(u8SOCLowWarn));
	*data = u8SOCLowWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
		*data = 0;

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_OPDLmpSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8OPDLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_OPDLMPSTS, &u8OPDLmpSts, (uint8)sizeof(u8OPDLmpSts));
	*data = u8OPDLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	SG_HCU_PT7 SG_HCU_PT7_Single;
	result = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&SG_HCU_PT7_Single);
	*data = SG_HCU_PT7_Single.HCU_OPDLmpSts ? 1u : 0u;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8OPDLmpSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_OPDLMPSTS, &u8OPDLmpSts, (uint8)sizeof(u8OPDLmpSts));
	*data = u8OPDLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8OPDLmpSts = 0;
	// result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_OPDLMPSTS, &u8OPDLmpSts, (uint8)sizeof(u8OPDLmpSts));
	*data = u8OPDLmpSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
		*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
		*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
		*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
		*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
			*data = 0;


#endif
	return result;
}

uint8 FTT_Adapt_GetOverSpdWrnFlg(uint8 *data)
{
	s_SpeedoInfo_t SpeedoInfo;
	uint8 result = 0xff;
#if (defined(SWC_TT_ADAPT_B02))
	result = Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&SpeedoInfo);
	*data = SpeedoInfo.OverSpdWrnFlg;
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&SpeedoInfo);
	*data = SpeedoInfo.OverSpdWrnFlg;
#elif (defined(SWC_TT_ADAPT_P03))
	result = Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&SpeedoInfo);
	*data = SpeedoInfo.OverSpdWrnFlg;
#elif (defined(SWC_TT_ADAPT_P05))
	result = Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&SpeedoInfo);
	*data = SpeedoInfo.OverSpdWrnFlg;
#elif (defined(SWC_TT_ADAPT_A07))
	result = Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&SpeedoInfo);
	*data = SpeedoInfo.OverSpdWrnFlg;
#elif (defined(SWC_TT_ADAPT_D01))
	result = Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&SpeedoInfo);
	*data = SpeedoInfo.OverSpdWrnFlg;
#elif (defined(SWC_TT_ADAPT_D02))
	result = Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&SpeedoInfo);
	*data = SpeedoInfo.OverSpdWrnFlg;
#elif (defined(SWC_TT_ADAPT_D03))
	result = Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&SpeedoInfo);
	*data = SpeedoInfo.OverSpdWrnFlg;
#elif (defined(SWC_TT_ADAPT_P02))
	result = Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&SpeedoInfo);
	*data = SpeedoInfo.OverSpdWrnFlg;
#elif (defined(SWC_TT_ADAPT_P01))
	result = Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&SpeedoInfo);
	*data = SpeedoInfo.OverSpdWrnFlg;


#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_TSRSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8TSRSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS, &u8TSRSts, (uint8)sizeof(u8TSRSts));
	*data = u8TSRSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_TSRSts_TSRSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8TSRSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS, &u8TSRSts, (uint8)sizeof(u8TSRSts));
	*data = u8TSRSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8TSRSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS, &u8TSRSts, (uint8)sizeof(u8TSRSts));
	*data = u8TSRSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8TSRSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS, &u8TSRSts, (uint8)sizeof(u8TSRSts));
	*data = u8TSRSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8TSRSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS, &u8TSRSts, (uint8)sizeof(u8TSRSts));
	*data = u8TSRSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8TSRSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS, &u8TSRSts, (uint8)sizeof(u8TSRSts));
	*data = u8TSRSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8TSRSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS, &u8TSRSts, (uint8)sizeof(u8TSRSts));
	*data = u8TSRSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8TSRSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS, &u8TSRSts, (uint8)sizeof(u8TSRSts));
	*data = u8TSRSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8TSRSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS, &u8TSRSts, (uint8)sizeof(u8TSRSts));
	*data = u8TSRSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_TSRSpdLimSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8TSRSpdLimSts = 0 ;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMSTS, &u8TSRSpdLimSts, (uint8)sizeof(u8TSRSpdLimSts));
	*data = u8TSRSpdLimSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_TSRSpdLimSts_TSRSpdLimSts(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8TSRSpdLimSts = 0 ;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMSTS, &u8TSRSpdLimSts, (uint8)sizeof(u8TSRSpdLimSts));
	*data = u8TSRSpdLimSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8TSRSpdLimSts = 0 ;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMSTS, &u8TSRSpdLimSts, (uint8)sizeof(u8TSRSpdLimSts));
	*data = u8TSRSpdLimSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8TSRSpdLimSts = 0 ;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMSTS, &u8TSRSpdLimSts, (uint8)sizeof(u8TSRSpdLimSts));
	*data = u8TSRSpdLimSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8TSRSpdLimSts = 0 ;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMSTS, &u8TSRSpdLimSts, (uint8)sizeof(u8TSRSpdLimSts));
	*data = u8TSRSpdLimSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8TSRSpdLimSts = 0 ;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMSTS, &u8TSRSpdLimSts, (uint8)sizeof(u8TSRSpdLimSts));
	*data = u8TSRSpdLimSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8TSRSpdLimSts = 0 ;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMSTS, &u8TSRSpdLimSts, (uint8)sizeof(u8TSRSpdLimSts));
	*data = u8TSRSpdLimSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8TSRSpdLimSts = 0 ;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMSTS, &u8TSRSpdLimSts, (uint8)sizeof(u8TSRSpdLimSts));
	*data = u8TSRSpdLimSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8TSRSpdLimSts = 0 ;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMSTS, &u8TSRSpdLimSts, (uint8)sizeof(u8TSRSpdLimSts));
	*data = u8TSRSpdLimSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_TSRSpdLim(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8TSRSpdLim = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIM, &u8TSRSpdLim, (uint8)sizeof(u8TSRSpdLim));
	*data = u8TSRSpdLim;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_TSRSpdLim_TSRSpdLim(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8TSRSpdLim = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIM, &u8TSRSpdLim, (uint8)sizeof(u8TSRSpdLim));
	*data = u8TSRSpdLim;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8TSRSpdLim = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIM, &u8TSRSpdLim, (uint8)sizeof(u8TSRSpdLim));
	*data = u8TSRSpdLim;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8TSRSpdLim = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIM, &u8TSRSpdLim, (uint8)sizeof(u8TSRSpdLim));
	*data = u8TSRSpdLim;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8TSRSpdLim = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIM, &u8TSRSpdLim, (uint8)sizeof(u8TSRSpdLim));
	*data = u8TSRSpdLim;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8TSRSpdLim = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIM, &u8TSRSpdLim, (uint8)sizeof(u8TSRSpdLim));
	*data = u8TSRSpdLim;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8TSRSpdLim = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIM, &u8TSRSpdLim, (uint8)sizeof(u8TSRSpdLim));
	*data = u8TSRSpdLim;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8TSRSpdLim = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIM, &u8TSRSpdLim, (uint8)sizeof(u8TSRSpdLim));
	*data = u8TSRSpdLim;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8TSRSpdLim = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIM, &u8TSRSpdLim, (uint8)sizeof(u8TSRSpdLim));
	*data = u8TSRSpdLim;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_TSRSpdLimWarn(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8TSRSpdLimWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMWARN, &u8TSRSpdLimWarn, (uint8)sizeof(u8TSRSpdLimWarn));
	*data = u8TSRSpdLimWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_TSRSpdLimWarn_TSRSpdLimWarn(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8TSRSpdLimWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMWARN, &u8TSRSpdLimWarn, (uint8)sizeof(u8TSRSpdLimWarn));
	*data = u8TSRSpdLimWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8TSRSpdLimWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMWARN, &u8TSRSpdLimWarn, (uint8)sizeof(u8TSRSpdLimWarn));
	*data = u8TSRSpdLimWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8TSRSpdLimWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMWARN, &u8TSRSpdLimWarn, (uint8)sizeof(u8TSRSpdLimWarn));
	*data = u8TSRSpdLimWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8TSRSpdLimWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMWARN, &u8TSRSpdLimWarn, (uint8)sizeof(u8TSRSpdLimWarn));
	*data = u8TSRSpdLimWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8TSRSpdLimWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMWARN, &u8TSRSpdLimWarn, (uint8)sizeof(u8TSRSpdLimWarn));
	*data = u8TSRSpdLimWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8TSRSpdLimWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMWARN, &u8TSRSpdLimWarn, (uint8)sizeof(u8TSRSpdLimWarn));
	*data = u8TSRSpdLimWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8TSRSpdLimWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMWARN, &u8TSRSpdLimWarn, (uint8)sizeof(u8TSRSpdLimWarn));
	*data = u8TSRSpdLimWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8TSRSpdLimWarn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSPDLIMWARN, &u8TSRSpdLimWarn, (uint8)sizeof(u8TSRSpdLimWarn));
	*data = u8TSRSpdLimWarn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_TSRTrfcSignVal(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8TSRTrfcSignVal = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRTRFCSIGNVAL, &u8TSRTrfcSignVal, (uint8)sizeof(u8TSRTrfcSignVal));
	*data = u8TSRTrfcSignVal;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_TSRTrfcSignVal_TSRTrfcSignVal(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8TSRTrfcSignVal = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRTRFCSIGNVAL, &u8TSRTrfcSignVal, (uint8)sizeof(u8TSRTrfcSignVal));
	*data = u8TSRTrfcSignVal;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8TSRTrfcSignVal = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRTRFCSIGNVAL, &u8TSRTrfcSignVal, (uint8)sizeof(u8TSRTrfcSignVal));
	*data = u8TSRTrfcSignVal;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8TSRTrfcSignVal = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRTRFCSIGNVAL, &u8TSRTrfcSignVal, (uint8)sizeof(u8TSRTrfcSignVal));
	*data = u8TSRTrfcSignVal;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8TSRTrfcSignVal = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRTRFCSIGNVAL, &u8TSRTrfcSignVal, (uint8)sizeof(u8TSRTrfcSignVal));
	*data = u8TSRTrfcSignVal;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8TSRTrfcSignVal = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRTRFCSIGNVAL, &u8TSRTrfcSignVal, (uint8)sizeof(u8TSRTrfcSignVal));
	*data = u8TSRTrfcSignVal;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8TSRTrfcSignVal = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRTRFCSIGNVAL, &u8TSRTrfcSignVal, (uint8)sizeof(u8TSRTrfcSignVal));
	*data = u8TSRTrfcSignVal;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8TSRTrfcSignVal = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRTRFCSIGNVAL, &u8TSRTrfcSignVal, (uint8)sizeof(u8TSRTrfcSignVal));
	*data = u8TSRTrfcSignVal;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8TSRTrfcSignVal = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRTRFCSIGNVAL, &u8TSRTrfcSignVal, (uint8)sizeof(u8TSRTrfcSignVal));
	*data = u8TSRTrfcSignVal;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_WIFSensorFailSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_P05))
	uint8 u8WIFSensorFailSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WIFSENSORFAILSTS, &u8WIFSensorFailSts, (uint8)sizeof(u8WIFSensorFailSts));
	*data = u8WIFSensorFailSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8WIFSensorFailSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WIFSENSORFAILSTS, &u8WIFSensorFailSts, (uint8)sizeof(u8WIFSensorFailSts));
	*data = u8WIFSensorFailSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8WIFSensorFailSts = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WIFSENSORFAILSTS, &u8WIFSensorFailSts, (uint8)sizeof(u8WIFSensorFailSts));
	*data = u8WIFSensorFailSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}


#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_WIFFullLmpCmd(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_P05))
	uint8 u8WIFFullLmpCmd = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WIFFULLLMPCMD, &u8WIFFullLmpCmd, (uint8)sizeof(u8WIFFullLmpCmd));
	*data = u8WIFFullLmpCmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8WIFFullLmpCmd = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WIFFULLLMPCMD, &u8WIFFullLmpCmd, (uint8)sizeof(u8WIFFullLmpCmd));
	*data = u8WIFFullLmpCmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8WIFFullLmpCmd = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WIFFULLLMPCMD, &u8WIFFullLmpCmd, (uint8)sizeof(u8WIFFullLmpCmd));
	*data = u8WIFFullLmpCmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_UreaLampCmd(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_P05))
	uint8 u8UreaLampCmd = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_UREALAMPCMD, &u8UreaLampCmd, (uint8)sizeof(u8UreaLampCmd));
	*data = u8UreaLampCmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8UreaLampCmd = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_UREALAMPCMD, &u8UreaLampCmd, (uint8)sizeof(u8UreaLampCmd));
	*data = u8UreaLampCmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8UreaLampCmd = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_UREALAMPCMD, &u8UreaLampCmd, (uint8)sizeof(u8UreaLampCmd));
	*data = u8UreaLampCmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_ESP_HMI_WarningOn(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8ESP_HMI_WarningOn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESP_HMI_WARNINGON, &u8ESP_HMI_WarningOn, (uint8)sizeof(u8ESP_HMI_WarningOn));
	*data = u8ESP_HMI_WarningOn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_ESP_HMI_WarningOn_ESP_HMI_WarningOn(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8ESP_HMI_WarningOn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESP_HMI_WARNINGON, &u8ESP_HMI_WarningOn, (uint8)sizeof(u8ESP_HMI_WarningOn));
	*data = u8ESP_HMI_WarningOn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8ESP_HMI_WarningOn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESP_HMI_WARNINGON, &u8ESP_HMI_WarningOn, (uint8)sizeof(u8ESP_HMI_WarningOn));
	*data = u8ESP_HMI_WarningOn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8ESP_HMI_WarningOn = 0;
	// result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESP_HMI_WARNINGON, &u8ESP_HMI_WarningOn, (uint8)sizeof(u8ESP_HMI_WarningOn));
	*data = u8ESP_HMI_WarningOn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8ESP_HMI_WarningOn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESP_HMI_WARNINGON, &u8ESP_HMI_WarningOn, (uint8)sizeof(u8ESP_HMI_WarningOn));
	*data = u8ESP_HMI_WarningOn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8ESP_HMI_WarningOn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESP_HMI_WARNINGON, &u8ESP_HMI_WarningOn, (uint8)sizeof(u8ESP_HMI_WarningOn));
	*data = u8ESP_HMI_WarningOn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_IB_Warn(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	uint8 u8IB_Warn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IB_WARN, &u8IB_Warn, (uint8)sizeof(u8IB_Warn));
	*data = u8IB_Warn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_B03))
	result = Rte_Read_IB_Warn_IB_Warn(data);
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8IB_Warn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IB_WARN, &u8IB_Warn, (uint8)sizeof(u8IB_Warn));
	*data = u8IB_Warn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8IB_Warn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IB_WARN, &u8IB_Warn, (uint8)sizeof(u8IB_Warn));
	*data = u8IB_Warn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	uint8 u8IB_Warn = 0;
	// result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IB_WARN, &u8IB_Warn, (uint8)sizeof(u8IB_Warn));
	*data = u8IB_Warn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8IB_Warn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IB_WARN, &u8IB_Warn, (uint8)sizeof(u8IB_Warn));
	*data = u8IB_Warn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	uint8 u8IB_Warn = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IB_WARN, &u8IB_Warn, (uint8)sizeof(u8IB_Warn));
	*data = u8IB_Warn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_V2XGLOSA(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
		*data = 0;

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_V2XSLW(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8V2XSLW = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_SLW, &u8V2XSLW, (uint8)sizeof(u8V2XSLW));
	*data = u8V2XSLW;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8V2XSLW = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_SLW, &u8V2XSLW, (uint8)sizeof(u8V2XSLW));
	*data = u8V2XSLW;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8V2XSLW = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_SLW, &u8V2XSLW, (uint8)sizeof(u8V2XSLW));
	*data = u8V2XSLW;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8V2XSLW = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_SLW, &u8V2XSLW, (uint8)sizeof(u8V2XSLW));
	*data = u8V2XSLW;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	*data = 0;

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_V2XIVSW(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8V2XIVSW = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_IVSW, &u8V2XIVSW, (uint8)sizeof(u8V2XIVSW));
	*data = u8V2XIVSW;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8V2XSLW = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_IVSW, &u8V2XSLW, (uint8)sizeof(u8V2XSLW));
	*data = u8V2XSLW;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8V2XSLW = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_IVSW, &u8V2XSLW, (uint8)sizeof(u8V2XSLW));
	*data = u8V2XSLW;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8V2XSLW = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_IVSW, &u8V2XSLW, (uint8)sizeof(u8V2XSLW));
	*data = u8V2XSLW;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	*data = 0;

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_V2XSLXL(uint8 u8LaneNum, uint8 *data_type, uint8 *data_color, uint16 *data_time)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TT_ADAPT_B02))
	if ((u8LaneNum > 8) || (0 == u8LaneNum))
	{
		result = RTE_E_INVALID;
	}

	*data_type = 0;
	*data_color = 0;
	*data_time = 0;
#elif (defined(SWC_TT_ADAPT_B03))
	if ((u8LaneNum > 8) || (0 == u8LaneNum))
	{
		result = RTE_E_INVALID;
	}

	*data_type = 0;
	*data_color = 0;
	*data_time = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	if ((u8LaneNum > 8) || (0 == u8LaneNum))
	{
		result = RTE_E_INVALID;
	}

	*data_type = 0;
	*data_color = 0;
	*data_time = 0;
#elif (defined(SWC_TT_ADAPT_P05))
	if ((u8LaneNum > 8) || (0 == u8LaneNum))
	{
		result = RTE_E_INVALID;
	}

	*data_type = 0;
	*data_color = 0;
	*data_time = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	if ((u8LaneNum > 8) || (0 == u8LaneNum))
	{
		result = RTE_E_INVALID;
	}

	*data_type = 0;
	*data_color = 0;
	*data_time = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	if ((u8LaneNum > 8) || (0 == u8LaneNum))
	{
		result = RTE_E_INVALID;
	}

	*data_type = 0;
	*data_color = 0;
	*data_time = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	if ((u8LaneNum > 8) || (0 == u8LaneNum))
	{
		result = RTE_E_INVALID;
	}

	*data_type = 0;
	*data_color = 0;
	*data_time = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	if ((u8LaneNum > 8) || (0 == u8LaneNum))
	{
		result = RTE_E_INVALID;
	}

	*data_type = 0;
	*data_color = 0;
	*data_time = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	if ((u8LaneNum > 8) || (0 == u8LaneNum))
	{
		result = RTE_E_INVALID;
	}

	*data_type = 0;
	*data_color = 0;
	*data_time = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	if ((u8LaneNum > 8) || (0 == u8LaneNum))
	{
		result = RTE_E_INVALID;
	}

	*data_type = 0;
	*data_color = 0;
	*data_time = 0;

#endif

	return result;
}

uint8 FTT_Adapt_GetMessage_V2XSLV(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	*data = 0;

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_LvlCtrlWarnLmpReq(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8LvlCtrlWarnLmpReq = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLWARNLMPREQ, &u8LvlCtrlWarnLmpReq, (uint8)sizeof(u8LvlCtrlWarnLmpReq));
	*data = u8LvlCtrlWarnLmpReq;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8LvlCtrlWarnLmpReq = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLWARNLMPREQ, &u8LvlCtrlWarnLmpReq, (uint8)sizeof(u8LvlCtrlWarnLmpReq));
	*data = u8LvlCtrlWarnLmpReq;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8LvlCtrlWarnLmpReq = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLWARNLMPREQ, &u8LvlCtrlWarnLmpReq, (uint8)sizeof(u8LvlCtrlWarnLmpReq));
	*data = u8LvlCtrlWarnLmpReq;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8LvlCtrlWarnLmpReq = 0;

	//result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLWARNLMPREQ, &u8LvlCtrlWarnLmpReq, (uint8)sizeof(u8LvlCtrlWarnLmpReq));
	*data = u8LvlCtrlWarnLmpReq;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
	*data = 0;

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_RSCAOFFSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8RSCAOFF_Sts = 0;

	//result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSCAOFFSTS, &u8RSCAOFF_Sts, (uint8)sizeof(u8RSCAOFF_Sts));
	*data = u8RSCAOFF_Sts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8RSCAOFF_Sts = 0;

	//result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSCAOFFSTS, &u8RSCAOFF_Sts, (uint8)sizeof(u8RSCAOFF_Sts));
	*data = u8RSCAOFF_Sts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
		*data = 0;

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_TrunkSts_Y(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8TrunkSts_Y = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS_Y, &u8TrunkSts_Y, (uint8)sizeof(u8TrunkSts_Y));
	*data = u8TrunkSts_Y;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8TrunkSts_Y = 0;
	//result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS_Y, &u8TrunkSts_Y, (uint8)sizeof(u8TrunkSts_Y));
	*data = u8TrunkSts_Y;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
	*data = 0;

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_CentralDiffLockLightSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8SystemOperMod = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD, &u8SystemOperMod, (uint8)sizeof(u8SystemOperMod));
	*data = u8SystemOperMod;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8SystemOperMod = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD, &u8SystemOperMod, (uint8)sizeof(u8SystemOperMod));
	*data = u8SystemOperMod;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8SystemOperMod = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD, &u8SystemOperMod, (uint8)sizeof(u8SystemOperMod));
	*data = u8SystemOperMod;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P01))
		*data = 0;

#endif
	return result;
}

uint8 FTT_Adapt_GetMessage_EngOilLowPresWrn(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TT_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_P03))
	uint8 u8EngOilLowPresWrn = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLOWPRESWRN, &u8EngOilLowPresWrn, (uint8)sizeof(u8EngOilLowPresWrn));
	*data = u8EngOilLowPresWrn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P05))
	uint8 u8EngOilLowPresWrn = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLOWPRESWRN, &u8EngOilLowPresWrn, (uint8)sizeof(u8EngOilLowPresWrn));
	*data = u8EngOilLowPresWrn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TT_ADAPT_D01))
	uint8 u8EngOilLowPresWrn = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLOWPRESWRN, &u8EngOilLowPresWrn, (uint8)sizeof(u8EngOilLowPresWrn));
	*data = u8EngOilLowPresWrn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D02))
	uint8 u8EngOilLowPresWrn = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLOWPRESWRN, &u8EngOilLowPresWrn, (uint8)sizeof(u8EngOilLowPresWrn));
	*data = u8EngOilLowPresWrn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_D03))
	uint8 u8EngOilLowPresWrn = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLOWPRESWRN, &u8EngOilLowPresWrn, (uint8)sizeof(u8EngOilLowPresWrn));
	*data = u8EngOilLowPresWrn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P02))
	uint8 u8EngOilLowPresWrn = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLOWPRESWRN, &u8EngOilLowPresWrn, (uint8)sizeof(u8EngOilLowPresWrn));
	*data = u8EngOilLowPresWrn;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TT_ADAPT_P01))
		*data = 0;

#endif
	return result;
}

#define SWC_TT_STOP_SEC_CODE
#include "SWC_TT_MemMap.h"

