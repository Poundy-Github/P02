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
*File Name   : SWC_CA_Adapt.c                                                                        *
*                                                                                                         *
*Description : CA module Adapt C file.                                      		  *
*                                                                                                         *
*Author      : Chen Tuhe                                                                              *
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

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/

#include "SWC_CA_Adapt.h"


#define SWC_CA_START_SEC_CONST_UNSPECIFIED
#include "SWC_CA_MemMap.h"

static const CA_CFG_u8SignalStatus enCACfgSignalStatusTable[(uint8)enCASignalInd_MAXNUM][(uint8)CA_CFG_Pro_MAXNUM] = CA_CFG_Signal_Status_Table;
static const uint16 u16CACfgSignalList[(uint8)enCASignalInd_MAXNUM] = CA_CFG_Signal_List;

#define SWC_CA_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_CA_MemMap.h"


#define SWC_CA_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_CA_MemMap.h"


#define SWC_CA_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_CA_MemMap.h"


#define SWC_CA_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_CA_MemMap.h"

static CA_CANAdaptAttr_t CA_stCANAdaptAttr = {0};

#define SWC_CA_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_CA_MemMap.h"


#define SWC_CA_START_SEC_CODE
#include "SWC_CA_MemMap.h"

void vCA_Adapt_VconfigInit(void)
{
	if (E_OK == Rte_Read_Vconfig_GetKindBuffers_AllKinds(CA_stCANAdaptAttr.VehicleConfig))
	{
		// Read Vconfig success,do nothing
	}
	else
	{
		// Read Vconfig fail,do nothing
	}

	return ;
}

void vCA_Adapt_ProIndexCfg(void)
{
	#ifdef SWC_CA_ADAPT_B02
	CA_stCANAdaptAttr.enProIndex = CA_CFG_Pro_B02;
	#elif defined SWC_CA_ADAPT_B03
	CA_stCANAdaptAttr.enProIndex = CA_CFG_Pro_B03;
	#elif defined SWC_CA_ADAPT_P03
	CA_stCANAdaptAttr.enProIndex = CA_CFG_Pro_P03;
	#elif defined SWC_CA_ADAPT_P05
	CA_stCANAdaptAttr.enProIndex = CA_CFG_Pro_P05;
	#elif defined SWC_CA_ADAPT_A07
	CA_stCANAdaptAttr.enProIndex = CA_CFG_Pro_A07;
	#elif defined SWC_CA_ADAPT_D01
	CA_stCANAdaptAttr.enProIndex = CA_CFG_Pro_D01;
	#elif defined SWC_CA_ADAPT_D02
	CA_stCANAdaptAttr.enProIndex = CA_CFG_Pro_D02;
	#elif defined SWC_CA_ADAPT_D03
	CA_stCANAdaptAttr.enProIndex = CA_CFG_Pro_D03;
	#elif defined SWC_CA_ADAPT_P02
	CA_stCANAdaptAttr.enProIndex = CA_CFG_Pro_P02;
	#else
		// do nothing
	#endif

	return ;
}

CA_CFG_u8SignalStatus enCA_Adapt_Get_SignalStatus(uint8 u8signalID)
{
	CA_CFG_u8SignalStatus enTempStatus = CA_Valid;

	if(CA_Invalid == enCACfgSignalStatusTable[u8signalID][CA_stCANAdaptAttr.enProIndex])
	{
		enTempStatus = CA_Invalid;
	}

	return enTempStatus;
}

uint8 u8CA_Adapt_GetCANSignalValue(uint32 *u32SigValue, uint8 u8CACfgSignalInd, uint8 u8DataSize)
{
	uint8 u8ret = RTE_E_INVALID;

	uint32 u32TempSigValue = 0u;

	if((CACANSignalRTENUM_ProDBCIsNotIncluded != (uint16)u16CACfgSignalList[u8CACfgSignalInd]) && (u8CACfgSignalInd <= (uint8)enCASignalInd_MAXNUM))
	{
		#if (defined(SWC_CA_ADAPT_B02))
		u8ret = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(u16CACfgSignalList[u8CACfgSignalInd], (uint8 *)&u32TempSigValue, u8DataSize);
		*u32SigValue = u32TempSigValue;

		if (u8ret == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
		{
		    u8ret = RTE_E_OK;
		}
		#elif (defined(SWC_CA_ADAPT_B03))
		(void) u32SigValue;
		(void) u8CACfgSignalInd;
		(void) u8DataSize;
		(void) u8ret;
		(void) u32TempSigValue;

		#elif (defined(SWC_CA_ADAPT_P03))

		u8ret = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(u16CACfgSignalList[u8CACfgSignalInd], (uint8 *)&u32TempSigValue, u8DataSize);
		*u32SigValue = u32TempSigValue;

		if (u8ret == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
		{
		    u8ret = RTE_E_OK;
		}
		#elif (defined(SWC_CA_ADAPT_P05))
		if(((uint8)enCASignalInd_DrivingModDis_0x137 == u8CACfgSignalInd) && (PTCANType_CAN == CA_stCANAdaptAttr.VehicleConfig[VCONFIG_KIND_PT_CAN_BUS_TYPE]))
		{
			u8ret = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(u16CACfgSignalList[u8CACfgSignalInd - 1], (uint8 *)&u32TempSigValue, u8DataSize);
		}
		else
		{
			u8ret = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(u16CACfgSignalList[u8CACfgSignalInd], (uint8 *)&u32TempSigValue, u8DataSize);
		}

		*u32SigValue = u32TempSigValue;

		if (u8ret == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
		{
		    u8ret = RTE_E_OK;
		}
		#elif (defined(SWC_CA_ADAPT_A07))
		u8ret = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(u16CACfgSignalList[u8CACfgSignalInd], (uint8 *)&u32TempSigValue, u8DataSize);
		*u32SigValue = u32TempSigValue;

		if (u8ret == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
		{
		    u8ret = RTE_E_OK;
		}
		#elif (defined(SWC_CA_ADAPT_D01))
		u8ret = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(u16CACfgSignalList[u8CACfgSignalInd], (uint8 *)&u32TempSigValue, u8DataSize);
		*u32SigValue = u32TempSigValue;

		if (u8ret == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
		{
		    u8ret = RTE_E_OK;
		}
		#elif (defined(SWC_CA_ADAPT_D02))
		u8ret = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(u16CACfgSignalList[u8CACfgSignalInd], (uint8 *)&u32TempSigValue, u8DataSize);
		*u32SigValue = u32TempSigValue;

		if (u8ret == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
		{
		    u8ret = RTE_E_OK;
		}
		#elif (defined(SWC_CA_ADAPT_D03))
		u8ret = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(u16CACfgSignalList[u8CACfgSignalInd], (uint8 *)&u32TempSigValue, u8DataSize);
		*u32SigValue = u32TempSigValue;

		if (u8ret == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
		{
		    u8ret = RTE_E_OK;
		}
		#elif (defined(SWC_CA_ADAPT_P02))
		u8ret = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(u16CACfgSignalList[u8CACfgSignalInd], (uint8 *)&u32TempSigValue, u8DataSize);
		*u32SigValue = u32TempSigValue;

		if (u8ret == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
		{
		    u8ret = RTE_E_OK;
		}
		#endif

	}
	else
	{
		/* The project DBC does not contain this signal or Signal index error. */
	}

	return u8ret;
}


#define SWC_CA_STOP_SEC_CODE
#include "SWC_CA_MemMap.h"

/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/


