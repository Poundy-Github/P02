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
*File Name   : SWC_DM_Adapt.c                                                                             *
*                                                                                                         *
*Description : Driving Mode module process function source file.                                          *
*                                                                                                         *
*Author      : Deng Jiangbo                                                                               *
*                                                                                                         *
*Platform    : MICROSAR OS                                                    						      *
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
#include "Compiler.h"
#include "Platform_Types.h"
#include "stddef.h" /* NULL */
#include <string.h> /* memset */
#include "Rte_Common_Normal.h"
#include "SWC_DM_Adapt.h"
#include "VConfig.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
#define SWC_DM_ADAPT_B02
#elif defined GWM_V35_PROJECT_TYPE_B03
#define SWC_DM_ADAPT_B03
#elif defined GWM_V35_PROJECT_TYPE_P03
#define SWC_DM_ADAPT_P03
#elif defined GWM_V35_PROJECT_TYPE_P05
#define SWC_DM_ADAPT_P05
#elif defined GWM_V35_PROJECT_TYPE_A07
#define SWC_DM_ADAPT_A07
#elif defined GWM_V35_PROJECT_TYPE_D01
#define SWC_DM_ADAPT_D01
#elif defined GWM_V35_PROJECT_TYPE_D02
#define SWC_DM_ADAPT_D02
#elif defined GWM_V35_PROJECT_TYPE_D03
#define SWC_DM_ADAPT_D03
#elif defined GWM_V35_PROJECT_TYPE_P02
#define SWC_DM_ADAPT_P02
#elif defined GWM_V35_PROJECT_TYPE_P01
#define SWC_DM_ADAPT_P01

#else
#define SWC_DM_ADAPT_NULL
#endif

#ifdef SWC_DM_ADAPT_B02
#include "ComEx_Cfg.h"
#elif defined SWC_DM_ADAPT_P03
#include "ComEx_Cfg.h"
#elif defined SWC_DM_ADAPT_P05
#include "ComEx_Cfg.h"
#elif defined SWC_DM_ADAPT_A07
#include "ComEx_Cfg.h"
#elif defined SWC_DM_ADAPT_D01
#include "ComEx_Cfg.h"
#elif defined SWC_DM_ADAPT_D02
#include "ComEx_Cfg.h"
#elif defined SWC_DM_ADAPT_D03
#include "ComEx_Cfg.h"
#elif defined SWC_DM_ADAPT_P02
#include "ComEx_Cfg.h"
#elif defined SWC_DM_ADAPT_P01
#include "ComEx_Cfg.h"
#endif

#define Common_Normal_START_SEC_CODE
#include  "Common_Normal_MemMap.h"

uint8 DM_Adapt_GetVconfig(uint16 id_u8)
{
	VconfigKind_Allbuffers configAdr;
	(void)Rte_Read_Vconfig_GetKindBuffers_AllKinds(configAdr);

	return (uint8)(configAdr[id_u8]);
}

DM_SIGNAL_SOURCE DM_Adapt_Signal_Source(void)
{
	uint8 u8Byte83 = 0;
	DM_SIGNAL_SOURCE DM_signal_value = DM_NO_SIGNAL;
	u8Byte83 = DM_Adapt_GetVconfig(VCONFIG_KIND_PT_CAN_BUS_TYPE);
	if (1 == u8Byte83)
	{
		DM_signal_value = DM_CANFD_SIGNAL;
	}
	else
	{
		DM_signal_value = DM_CAN_SIGNAL;
	}
	return DM_signal_value;
}

/* P03 Project: HEV vehicle use fuel logic.
*  B03 Project: HEV logic use fuel configuration byte53.
*  So add the following interface.
*/
uint8 DM_Adapt_FuelLogicPriority(void)
{
	uint8 u8FuelPriority = DM_PRIORITY_1;

	// DM_PRIORITY_1 > DM_PRIORITY_2
#if (defined(SWC_DM_ADAPT_B02))
	u8FuelPriority = DM_PRIORITY_2;
#elif (defined(SWC_DM_ADAPT_B03))
	u8FuelPriority = DM_PRIORITY_2;
#elif (defined(SWC_DM_ADAPT_P05))
#elif (defined(SWC_DM_ADAPT_P03))
#elif (defined(SWC_DM_ADAPT_A07))
	u8FuelPriority = DM_PRIORITY_2;
#elif (defined(SWC_DM_ADAPT_D01))
#elif (defined(SWC_DM_ADAPT_D02))
#elif (defined(SWC_DM_ADAPT_D03))
#elif (defined(SWC_DM_ADAPT_P02))
#endif

	return u8FuelPriority;
}

boolean DM_Adapt_FuelModeIdCheck(uint8 u8ModeId)
{
	boolean result = FALSE;

#if (defined(SWC_DM_ADAPT_B02))
	if((u8ModeId != 36) && (u8ModeId != 18) && (u8ModeId != 33))
	{
		result = FALSE;
	}
	else
	{
		result = TRUE;
	}
#elif (defined(SWC_DM_ADAPT_B03))
	if((u8ModeId != 2) && (u8ModeId != 37) && (u8ModeId != 39))
	{
		result = FALSE;
	}
	else
	{
		result = TRUE;
	}
#elif (defined(SWC_DM_ADAPT_P05))
	if((u8ModeId != 1) && (u8ModeId != 5) && (u8ModeId != 32) && (u8ModeId != 43) && (u8ModeId != 70))
	{
		result = FALSE;
	}
	else
	{
		result = TRUE;
	}
#elif (defined(SWC_DM_ADAPT_P03))
	if((u8ModeId != 27) && (u8ModeId != 30) && (u8ModeId != 44) && (u8ModeId != 49) \
		&& (u8ModeId != 48) && (u8ModeId != 59) && (u8ModeId != 61) && (u8ModeId != 62) \
		&& (u8ModeId != 63))
	{
		result = FALSE;
	}
	else
	{
		result = TRUE;
	}
#elif (defined(SWC_DM_ADAPT_A07))
	if(u8ModeId != 2)
	{
		result = FALSE;
	}
	else
	{
		result = TRUE;
	}
#elif (defined(SWC_DM_ADAPT_D01))
	if((u8ModeId != 30) && (u8ModeId != 48))
	{
		result = FALSE;
	}
	else
	{
		result = TRUE;
	}
#elif (defined(SWC_DM_ADAPT_D02))
	if((u8ModeId != 30) && (u8ModeId != 48))
	{
		result = FALSE;
	}
	else
	{
		result = TRUE;
	}
#elif (defined(SWC_DM_ADAPT_D03))
	if((u8ModeId != 45) && (u8ModeId != 46))
	{
		result = FALSE;
	}
	else
	{
		result = TRUE;
	}
#elif (defined(SWC_DM_ADAPT_P02))
	if((u8ModeId != 30) && (u8ModeId != 49) && (u8ModeId != 62) && (u8ModeId != 73))
	{
		result = FALSE;
	}
	else
	{
		result = TRUE;
	}
#elif (defined(SWC_DM_ADAPT_P01))
	if((u8ModeId != 2) && (u8ModeId != 4) && (u8ModeId != 9))
	{
		result = FALSE;
	}
	else
	{
		result = TRUE;
	}

#endif
	return result;
}

uint8 DM_Adapt_GetMessage_DrivingMod(uint8 *data_s,uint8 *data_t)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_DM_ADAPT_B02))
	uint8 u8DrivingModDis = 0;
	uint8 u8DrivingModReq_ESP = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODDIS, &u8DrivingModDis, (uint8)sizeof(u8DrivingModDis));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODREQ_ESP, &u8DrivingModReq_ESP, (uint8)sizeof(u8DrivingModReq_ESP));
	*data_s = u8DrivingModDis;
	*data_t = u8DrivingModReq_ESP;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_B03))
	SG_ESP2 stMessageEsp2Value = {0};
	// SG_ESP2_ESP_FD2 stMessageESP_FD2Value = {0};

	result = Rte_Read_Common_Normal_SG_ESP2_SG_ESP2(&stMessageEsp2Value);
	*data_s = stMessageEsp2Value.DrivingModDis;
	*data_t = stMessageEsp2Value.DrivingModReq_ESP;
#elif (defined(SWC_DM_ADAPT_P05))
	uint8 u8DrivingModDis = 0;
	uint8 u8DrivingModReq_ESP = 0;

	if(DM_Adapt_Signal_Source() == DM_CANFD_SIGNAL)
	{
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODDIS_0X137, &u8DrivingModDis, (uint8)sizeof(u8DrivingModDis));
		(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODREQ_ESP_0X137, &u8DrivingModReq_ESP, (uint8)sizeof(u8DrivingModReq_ESP));
		*data_s = u8DrivingModDis;
		*data_t = u8DrivingModReq_ESP;
	}
	else
	{
		result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODDIS_0X145, &u8DrivingModDis, (uint8)sizeof(u8DrivingModDis));
		(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODREQ_ESP_0X145, &u8DrivingModReq_ESP, (uint8)sizeof(u8DrivingModReq_ESP));
		*data_s = u8DrivingModDis;
		*data_t = u8DrivingModReq_ESP;
	}
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_P03))
	uint8 u8DrivingModDis = 0;
	uint8 u8DrivingModReq_ESP = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODDIS, &u8DrivingModDis, (uint8)sizeof(u8DrivingModDis));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODREQ_ESP, &u8DrivingModReq_ESP, (uint8)sizeof(u8DrivingModReq_ESP));
	*data_s = u8DrivingModDis;
	*data_t = u8DrivingModReq_ESP;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_A07))
	uint8 u8DrivingModDis = 0;
	uint8 u8DrivingModReq_ESP = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODDIS, &u8DrivingModDis, (uint8)sizeof(u8DrivingModDis));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODREQ_ESP, &u8DrivingModReq_ESP, (uint8)sizeof(u8DrivingModReq_ESP));
	*data_s = u8DrivingModDis;
	*data_t = u8DrivingModReq_ESP;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_D01))
	uint8 u8DrivingModDis = 0;
	uint8 u8DrivingModReq_ESP = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODDIS, &u8DrivingModDis, (uint8)sizeof(u8DrivingModDis));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODREQ_ESP, &u8DrivingModReq_ESP, (uint8)sizeof(u8DrivingModReq_ESP));
	*data_s = u8DrivingModDis;
	*data_t = u8DrivingModReq_ESP;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_D02))
	uint8 u8DrivingModDis = 0;
	uint8 u8DrivingModReq_ESP = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODDIS, &u8DrivingModDis, (uint8)sizeof(u8DrivingModDis));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODREQ_ESP, &u8DrivingModReq_ESP, (uint8)sizeof(u8DrivingModReq_ESP));
	*data_s = u8DrivingModDis;
	*data_t = u8DrivingModReq_ESP;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_D03))
	uint8 u8DrivingModDis = 0;
	uint8 u8DrivingModReq_ESP = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODDIS, &u8DrivingModDis, (uint8)sizeof(u8DrivingModDis));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODREQ_ESP, &u8DrivingModReq_ESP, (uint8)sizeof(u8DrivingModReq_ESP));
	*data_s = u8DrivingModDis;
	*data_t = u8DrivingModReq_ESP;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_P02))
	uint8 u8DrivingModDis = 0;
	uint8 u8DrivingModReq_ESP = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODDIS, &u8DrivingModDis, (uint8)sizeof(u8DrivingModDis));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODREQ_ESP, &u8DrivingModReq_ESP, (uint8)sizeof(u8DrivingModReq_ESP));
	*data_s = u8DrivingModDis;
	*data_t = u8DrivingModReq_ESP;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_P01))
	uint8 u8DrivingModDis = 0;
	uint8 u8DrivingModReq_ESP = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODDIS, &u8DrivingModDis, (uint8)sizeof(u8DrivingModDis));
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODREQ_ESP, &u8DrivingModReq_ESP, (uint8)sizeof(u8DrivingModReq_ESP));
	*data_s = u8DrivingModDis;
	*data_t = u8DrivingModReq_ESP;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}


uint8 DM_Adapt_GetMessage_HCU_DrvMod(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_DM_ADAPT_B02))
	uint8 u8HCU_DrvMod = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_DRVMOD, &u8HCU_DrvMod, (uint8)sizeof(u8HCU_DrvMod));
	*data = u8HCU_DrvMod;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_B03))
	result = Rte_Read_HCU_DrvMod_HCU_DrvMod(data);
#elif (defined(SWC_DM_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_A07))
	uint8 u8HCU_DrvMod = 0;

	// result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_DRVMOD, &u8HCU_DrvMod, (uint8)sizeof(u8HCU_DrvMod));
	*data = u8HCU_DrvMod;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_P01))
	*data = 0;
#else
	*data = 0;
#endif

	return result;
}

uint8 DM_Adapt_GetMessage_HCU_DrvModDisp(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_DM_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_P03))
	uint8 u8HCU_DrvModDisp = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_DRVMODDISP, &u8HCU_DrvModDisp, (uint8)sizeof(u8HCU_DrvModDisp));
	*data = u8HCU_DrvModDisp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_P01))
	*data = 0;
#else
	*data = 0;
#endif

	return result;
}

#if 0
uint8 DM_Adapt_GetSelfChecksts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;
#if (defined(SWC_DM_ADAPT_B02))
	result = Rte_Read_tiSR_SWC_TT_SelfCheck_Element(data);
#elif (defined(SWC_DM_ADAPT_B03))
	result = Rte_Read_tiSR_SWC_TT_SelfCheck_Element(data);
#elif (defined(SWC_DM_ADAPT_P03))
	result = Rte_Read_tiSR_SWC_TT_SelfCheck_Element(data);
#elif (defined(SWC_DM_ADAPT_P05))
	result = Rte_Read_tiSR_SWC_TT_SelfCheck_Element(data);
#endif
	return result;
}
#endif

uint8 DM_Adapt_GetMessage_IMC_Actv(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_DM_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_P03))
	uint8 u8IMC_Actv = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IMC_ACTV, &u8IMC_Actv, (uint8)sizeof(u8IMC_Actv));
	*data = u8IMC_Actv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_D01))
	uint8 u8IMC_Actv = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IMC_ACTV, &u8IMC_Actv, (uint8)sizeof(u8IMC_Actv));
	*data = u8IMC_Actv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_D02))
	uint8 u8IMC_Actv = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IMC_ACTV, &u8IMC_Actv, (uint8)sizeof(u8IMC_Actv));
	*data = u8IMC_Actv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_D03))
	uint8 u8IMC_Actv = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IMC_ACTV, &u8IMC_Actv, (uint8)sizeof(u8IMC_Actv));
	*data = u8IMC_Actv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_P02))
	uint8 u8IMC_Actv = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IMC_ACTV, &u8IMC_Actv, (uint8)sizeof(u8IMC_Actv));
	*data = u8IMC_Actv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_P01))
	uint8 u8IMC_Actv = 0;

	//result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IMC_ACTV, &u8IMC_Actv, (uint8)sizeof(u8IMC_Actv));
	*data = u8IMC_Actv;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#endif
	return result;

}

uint8 DM_Adapt_GetMessage_SystemOperMod(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_DM_ADAPT_P05))
	uint8 u8SystemOperMod = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD, &u8SystemOperMod, (uint8)sizeof(u8SystemOperMod));
	*data = u8SystemOperMod;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_P03))
	uint8 u8SystemOperMod = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD, &u8SystemOperMod, (uint8)sizeof(u8SystemOperMod));
	*data = u8SystemOperMod;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_D01))
	uint8 u8SystemOperMod = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD, &u8SystemOperMod, (uint8)sizeof(u8SystemOperMod));
	*data = u8SystemOperMod;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_D02))
	uint8 u8SystemOperMod = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD, &u8SystemOperMod, (uint8)sizeof(u8SystemOperMod));
	*data = u8SystemOperMod;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_D03))
	uint8 u8SystemOperMod = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD, &u8SystemOperMod, (uint8)sizeof(u8SystemOperMod));
	*data = u8SystemOperMod;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_P02))
	uint8 u8SystemOperMod = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD, &u8SystemOperMod, (uint8)sizeof(u8SystemOperMod));
	*data = u8SystemOperMod;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_P01))
	uint8 u8SystemOperMod = 0;

	//result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD, &u8SystemOperMod, (uint8)sizeof(u8SystemOperMod));
	*data = u8SystemOperMod;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif
	return result;
}

uint8 DM_Adapt_GetMessage_HCU_HybMod(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_DM_ADAPT_B02))
	uint8 u8HCU_HybMod = 0;

	//result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBMOD, &u8HCU_HybMod, (uint8)sizeof(u8HCU_HybMod));
	*data = u8HCU_HybMod;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_A07))
	uint8 u8HCU_HybMod = 0;

	// result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBMOD, &u8HCU_HybMod, (uint8)sizeof(u8HCU_HybMod));
	*data = u8HCU_HybMod;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_D01))
	uint8 u8HCU_HybMod = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBMOD, &u8HCU_HybMod, (uint8)sizeof(u8HCU_HybMod));
	*data = u8HCU_HybMod;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_D02))
	uint8 u8HCU_HybMod = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBMOD, &u8HCU_HybMod, (uint8)sizeof(u8HCU_HybMod));
	*data = u8HCU_HybMod;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_D03))
	uint8 u8HCU_HybMod = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBMOD, &u8HCU_HybMod, (uint8)sizeof(u8HCU_HybMod));
	*data = u8HCU_HybMod;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_DM_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_DM_ADAPT_P01))
	*data = 0;
#endif

	return result;
}

#define Common_Normal_STOP_SEC_CODE
#include  "Common_Normal_MemMap.h"

