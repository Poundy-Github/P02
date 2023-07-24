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
*File Name   : SWC_TT_Safety_Adaptor.c                                                                    *
*                                                                                                         *
*Description : Telltale module Adaptor module source file.                                                *
*                                                                                                         *
*Author      : li yafei                                                                                   *
*                                                                                                         *
*Platform    : Free Rtos System                                                                           *
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
#include "SWC_IPC_Application.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_TT_Safety_Adaptor.h"

#include "Dio.h"
#include "Com.h"
#include "VConfig.h"
#include "IoHwAb.h"
#include "IoHwAb_Cfg_RI.h"
#include <string.h> /* memset */
#include "IPC_ClusterApp.h"
#include "Rte_Common_Safety.h"
#include "IPC_SAFETY.h"
//#include "Rte_ComEx.h"

#include "DevConfig.h"
/**********************************************************************************************************
*																										  *
*																										  *
*	Telltale Process Function  Definition																  *
*																										  *
*																										  *
**********************************************************************************************************/
#define Common_Safety_START_SEC_CODE
#include "Common_Safety_MemMap.h"

/**********************************************************************************************************
*Function   : ATT_vDomain_Logic_Process                                                                   *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void                                                                                        *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Handsomefly                                                                                 *
*                                                                                                         *
*Date		: 2021-02-02                                                                                  *
**********************************************************************************************************/
void ATT_vE2E_Message_init(void)
{
	E2EPW_ReadInit_SG_ABS3_SG_ABS3();
	E2EPW_ReadInit_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2();
	E2EPW_ReadInit_SG_ESP1_SG_ESP1();
	E2EPW_ReadInit_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2();
	E2EPW_ReadInit_SG_EPB1_SG_EPB1();
	E2EPW_ReadInit_SG_EPS1_SG_EPS1();
	E2EPW_ReadInit_SG_EPS1_FD1_SG_EPS1_FD1();
	E2EPW_ReadInit_SG_ABM1_SG_ABM1();
	E2EPW_ReadInit_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2();
}
/**********************************************************************************************************
*Function   : ATT_vDomain_Logic_Process                                                                   *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void                                                                                        *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Handsomefly                                                                                 *
*                                                                                                         *
*Date		: 2021-02-02                                                                                  *
**********************************************************************************************************/

ATT_DOMAIN_INFO ATT_vDomain_Logic_Process(void)
{
	uint8 u8Byte4 = 0;
	ATT_DOMAIN_INFO tt_domain_sts = ATT_DOMAIN_CH;
	//static uint8 test_byte4 = 0;
	u8Byte4 = ATT_Adapt_GetVconfig(VCONFIG_KIND_REGIONAL);
	//u8Byte4 = test_byte4;
	if ((0u == u8Byte4) || (1u == u8Byte4) || (2u == u8Byte4) || (4u == u8Byte4) \
		|| (5u == u8Byte4) || (6u == u8Byte4) || (7u == u8Byte4) || (8u == u8Byte4))
	{
		tt_domain_sts = ATT_DOMAIN_CH;
	}
	else if (3u == u8Byte4)
	{
		tt_domain_sts = ATT_DOMAIN_US;
	}
	else
	{
		tt_domain_sts = ATT_NO_DOMAIN;
	}

	return tt_domain_sts;
}

/**********************************************************************************************************
*Function   : ATT_vSignal_Source_Process                                                                  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void                                                                                        *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Handsomefly                                                                                 *
*                                                                                                         *
*Date		: 2021-02-02                                                                                  *
**********************************************************************************************************/

ATT_SIGNAL_SOURCE ATT_vSignal_Source_Process(void)
{
	uint8 u8Byte83 = 0;
	ATT_SIGNAL_SOURCE ATT_signal_value = ATT_NO_SIGNAL;

	// tips: only the project has two signal sources, which can be used when adapting
	u8Byte83 = ATT_Adapt_GetVconfig(VCONFIG_KIND_PT_CAN_BUS_TYPE);
	if (1u == u8Byte83)
	{
		ATT_signal_value = ATT_CANFD_SIGNAL;
	}
	else
	{
		ATT_signal_value = ATT_CAN_SIGNAL;
	}

	return ATT_signal_value;
}
/**********************************************************************************************************
*Function   : ATT_Adapt_GetVconfig                                                                        *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: uint8 id_u8                                                                                 *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Handsomefly                                                                                 *
*                                                                                                         *
*Date		: 2021-02-02                                                                                  *
**********************************************************************************************************/
TT_ADAPT_TYPE ATT_Adapt_GetVconfig(uint16 id_u8)
{
	VconfigKind_Allbuffers configAdr;
	(void)Rte_Read_Vconfig_GetKindBuffers_AllKinds(configAdr);

	return (TT_ADAPT_TYPE)(configAdr[id_u8]);
}

/**********************************************************************************************************
*Function   : ATT_GetMessage_E2E_ABS_Sts                                                                  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: uint8 id_u8                                                                                 *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Handsomefly                                                                                 *
*                                                                                                         *
*Date		: 2021-02-02                                                                                  *
**********************************************************************************************************/
TT_ADAPT_TYPE ATT_GetMessage_E2E_ABS_Sts(uint32 *E2Ests)
{
    uint8 result = 0xff;
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
	SG_ABS3 ATT_ABS3;
	SG_ABS3_ESP_FD2 ATT_ESP_FD2;
    if (ATT_vSignal_Source_Process() == ATT_CANFD_SIGNAL)
    {
        *E2Ests = E2EPW_Read_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2(&ATT_ESP_FD2);
    }
    else
    {
        *E2Ests = E2EPW_Read_SG_ABS3_SG_ABS3(&ATT_ABS3);
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABS3_ESP_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABS3_ESP_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
    if (ATT_vSignal_Source_Process() == ATT_CANFD_SIGNAL)
    {
        (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABS3_ESP_FD2, E2Ests);
    }
    else
    {
        (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABS3, E2Ests);
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABS3, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABS3_ESP_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABS3_ESP_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABS3_ESP_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABS3_ESP_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABS3_ESP_FD2, E2Ests);
#else
#endif
    return result;
}

TT_ADAPT_TYPE ATT_GetMessage_E2E_ESP_Sts(uint32 *E2Ests)
{
    uint8 result = 0xff;
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
	SG_ESP1 ATT_ESP1;
	SG_ESP1_ESP_FD2 ATT_ESP_FD1;
    if (ATT_vSignal_Source_Process() == ATT_CANFD_SIGNAL)
    {
        *E2Ests = E2EPW_Read_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2(&ATT_ESP_FD1);
    }
    else
    {
        *E2Ests = E2EPW_Read_SG_ESP1_SG_ESP1(&ATT_ESP1);
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ESP1_ESP_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ESP1_ESP_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
    if (ATT_vSignal_Source_Process() == ATT_CANFD_SIGNAL)
    {
        (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ESP1_ESP_FD2, E2Ests);
    }
    else
    {
        (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ESP1, E2Ests);
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ESP1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ESP1_ESP_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ESP1_ESP_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ESP1_ESP_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ESP1_ESP_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ESP1_ESP_FD2, E2Ests);
#else
#endif
    return result;
}

TT_ADAPT_TYPE ATT_GetMessage_E2E_EPB_Sts(uint32 *E2Ests)
{
    uint8 result = 0xff;
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
    SG_EPB1 ATT_EPB1;
    *E2Ests = E2EPW_Read_SG_EPB1_SG_EPB1(&ATT_EPB1);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
    (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPB1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
    (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPB1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
    (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPB1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
    (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPB1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPB1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPB1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPB1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPB1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPB1, E2Ests);
#else
#endif
    return result;
}

TT_ADAPT_TYPE ATT_GetMessage_E2E_EPS_Sts(uint32 *E2Ests)
{
    uint8 result = 0xff;
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
	SG_EPS1 ATT_EPS1;
	SG_EPS1_FD1 ATT_EPS1_FD1;
    if (ATT_vSignal_Source_Process() == ATT_CANFD_SIGNAL)
    {
        *E2Ests = E2EPW_Read_SG_EPS1_FD1_SG_EPS1_FD1(&ATT_EPS1_FD1);
    }
    else
    {
        *E2Ests = E2EPW_Read_SG_EPS1_SG_EPS1(&ATT_EPS1);
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPS_FD1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPS_FD1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
    if (ATT_vSignal_Source_Process() == ATT_CANFD_SIGNAL)
    {
        (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPS_FD1, E2Ests);
    }
    else
    {
        (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPS1, E2Ests);
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPS1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPS_FD1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPS_FD1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPS_FD1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPS_FD1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_EPS_FD1, E2Ests);
#else
#endif
    return result;
}

TT_ADAPT_TYPE ATT_GetMessage_E2E_ABM_Sts(uint32 *E2Ests)
{
    uint8 result = 0xff;
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
    SG_ABM1 ATT_ABM1;
    *E2Ests = E2EPW_Read_SG_ABM1_SG_ABM1(&ATT_ABM1);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
    (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABM1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
    (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABM1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
    (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABM1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
    (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABM1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABM1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABM1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABM1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABM1, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_ABM1, E2Ests);
#else
#endif
    return result;
}

TT_ADAPT_TYPE ATT_GetMessage_E2E_AEB3_FD_Sts(uint32 *E2Ests)
{
    uint8 result = 0xff;
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
    SG_AEB3_AEB_FD2 ATT_AEB3_FD2;
    *E2Ests = E2EPW_Read_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2(&ATT_AEB3_FD2);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
    (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_AEB3_AEB_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
    (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_AEB3_AEB_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
    (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_AEB3_AEB_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
    (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_AEB3_AEB_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_AEB3_AEB_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_AEB3_AEB_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_AEB3_AEB_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_AEB3_AEB_FD2, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_AEB3_AEB_FD2, E2Ests);
#else
#endif
    return result;
}

TT_ADAPT_TYPE ATT_GetMessage_E2E_SG_BMS4_Sts(uint32 *E2Ests)
{
    uint8 result = 0xff;
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
    SG_BMS4 ATT_SG_BMS4;
    *E2Ests = E2EPW_Read_SG_BMS4_SG_BMS4(&ATT_SG_BMS4);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
    (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_BMS4, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
    (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_BMS4, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_BMS4, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
	*E2Ests = E2E_OK;//A07 PHEV/HEV cancel
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_BMS4, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_BMS4, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_BMS4, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	//(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_BMS4, E2Ests);
    *E2Ests = E2E_OK;
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_BMS4, E2Ests);
#else
#endif
    return result;
}

TT_ADAPT_TYPE ATT_GetMessage_E2E_HCU_PT7_Sts(uint32 *E2Ests)
{
    uint8 result = 0xff;
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
    SG_HCU_PT7 ATT_HCU_PT7;
    *E2Ests = E2EPW_Read_SG_HCU_PT7_SG_HCU_PT7(&ATT_HCU_PT7);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
    (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_HCU_PT7, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
    (void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_HCU_PT7, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_HCU_PT7, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
	*E2Ests = E2E_OK;//A07 PHEV/HEV cancel
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_HCU_PT7, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_HCU_PT7, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_HCU_PT7, E2Ests);
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	//(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_HCU_PT7, E2Ests);
    *E2Ests = E2E_OK;
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
	(void)Rte_Call_Common_Safety_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_HCU_PT7, E2Ests);
#else
#endif
    return result;
}

TT_ADAPT_TYPE ATT_GetMessage_ABS_Sts(uint8 *data)
{
    uint8 result = RTE_E_INVALID;
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
	SG_ABS3 ATT_ABS3;
	SG_ABS3_ESP_FD2 ATT_ESP_FD2;
#else
    uint8 u8ABSFailsts = 0;
#endif
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
    if (ATT_vSignal_Source_Process() == ATT_CANFD_SIGNAL)
    {
        result = Rte_Read_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2(&ATT_ESP_FD2);
        *data = ATT_ESP_FD2.ABSFailSts_0x137 ? 1u : 0u;
    }
    else
    {
        result = Rte_Read_SG_ABS3_SG_ABS3(&ATT_ABS3);
        *data = ATT_ABS3.ABSFailSts_0x265 ? 1u : 0u;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ABSFAILSTS, &u8ABSFailsts, (uint8)sizeof(u8ABSFailsts));
	*data = u8ABSFailsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ABSFAILSTS, &u8ABSFailsts, (uint8)sizeof(u8ABSFailsts));
	*data = u8ABSFailsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
    if (ATT_vSignal_Source_Process() == ATT_CANFD_SIGNAL)
    {
        result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ABSFAILSTS_0X137, &u8ABSFailsts, (uint8)sizeof(u8ABSFailsts));
        *data = u8ABSFailsts;
    }
    else
    {
        result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ABSFAILSTS_0X265, &u8ABSFailsts, (uint8)sizeof(u8ABSFailsts));
        *data = u8ABSFailsts;
    }

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ABSFAILSTS, &u8ABSFailsts, (uint8)sizeof(u8ABSFailsts));
	*data = u8ABSFailsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ABSFAILSTS,&u8ABSFailsts,(uint8)sizeof(u8ABSFailsts));
	*data = u8ABSFailsts;

	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ABSFAILSTS, &u8ABSFailsts, (uint8)sizeof(u8ABSFailsts));
    *data = u8ABSFailsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ABSFAILSTS, &u8ABSFailsts, (uint8)sizeof(u8ABSFailsts));
    *data = u8ABSFailsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ABSFAILSTS, &u8ABSFailsts, (uint8)sizeof(u8ABSFailsts));
	*data = u8ABSFailsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ABSFAILSTS,&u8ABSFailsts,(uint8)sizeof(u8ABSFailsts));
	*data = u8ABSFailsts;

	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#else
#endif
    return result;
}

TT_ADAPT_TYPE ATT_GetMessage_ESP_Enable_Sts(uint8 *data_f, uint8 *data_s)
{
    uint8 result = RTE_E_INVALID;
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
	SG_ESP1 ATT_ESP1;
	SG_ESP1_ESP_FD2 ATT_ESP_FD1;
#else
	uint8 u8ESPFailsts = 0;
	uint8 u8ESPActvinfolmp = 0;
#endif
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
    if (ATT_vSignal_Source_Process() == ATT_CANFD_SIGNAL)
    {
        result = Rte_Read_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2(&ATT_ESP_FD1);
        *data_f = ATT_ESP_FD1.ESPFailSts_0x137 ? 1u : 0u;
        *data_s = ATT_ESP_FD1.ESPActvInfoLmp_0x137 ? 1u : 0u;
    }
    else
    {
        result = Rte_Read_SG_ESP1_SG_ESP1(&ATT_ESP1);
        *data_f = ATT_ESP1.ESPFailSts_0x149 ? 1u : 0u;
        *data_s = ATT_ESP1.ESPActvInfoLmp_0x149 ? 1u : 0u;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFAILSTS, &u8ESPFailsts, (uint8)sizeof(u8ESPFailsts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPACTVINFOLMP, &u8ESPActvinfolmp, (uint8)sizeof(u8ESPActvinfolmp));
	*data_f = u8ESPFailsts;
	*data_s = u8ESPActvinfolmp;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFAILSTS, &u8ESPFailsts, (uint8)sizeof(u8ESPFailsts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPACTVINFOLMP, &u8ESPActvinfolmp, (uint8)sizeof(u8ESPActvinfolmp));
	*data_f = u8ESPFailsts;
	*data_s = u8ESPActvinfolmp;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
    if (ATT_vSignal_Source_Process() == ATT_CANFD_SIGNAL)
    {
        result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFAILSTS_0X137, &u8ESPFailsts, (uint8)sizeof(u8ESPFailsts));
        (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPACTVINFOLMP_0X137, &u8ESPActvinfolmp, (uint8)sizeof(u8ESPActvinfolmp));
        *data_f = u8ESPFailsts;
        *data_s = u8ESPActvinfolmp;
    }
    else
    {
        result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFAILSTS_0X149, &u8ESPFailsts, (uint8)sizeof(u8ESPFailsts));
        (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPACTVINFOLMP_0X149, &u8ESPActvinfolmp, (uint8)sizeof(u8ESPActvinfolmp));
        *data_f = u8ESPFailsts;
        *data_s = u8ESPActvinfolmp;
    }

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFAILSTS, &u8ESPFailsts, (uint8)sizeof(u8ESPFailsts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPACTVINFOLMP, &u8ESPActvinfolmp, (uint8)sizeof(u8ESPActvinfolmp));
	*data_f = u8ESPFailsts;
	*data_s = u8ESPActvinfolmp;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFAILSTS, &u8ESPFailsts, (uint8)sizeof(u8ESPFailsts));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPACTVINFOLMP, &u8ESPActvinfolmp, (uint8)sizeof(u8ESPActvinfolmp));
    *data_f = u8ESPFailsts;
    *data_s = u8ESPActvinfolmp;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFAILSTS, &u8ESPFailsts, (uint8)sizeof(u8ESPFailsts));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPACTVINFOLMP, &u8ESPActvinfolmp, (uint8)sizeof(u8ESPActvinfolmp));
    *data_f = u8ESPFailsts;
    *data_s = u8ESPActvinfolmp;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFAILSTS, &u8ESPFailsts, (uint8)sizeof(u8ESPFailsts));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPACTVINFOLMP, &u8ESPActvinfolmp, (uint8)sizeof(u8ESPActvinfolmp));
    *data_f = u8ESPFailsts;
    *data_s = u8ESPActvinfolmp;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFAILSTS, &u8ESPFailsts, (uint8)sizeof(u8ESPFailsts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPACTVINFOLMP, &u8ESPActvinfolmp, (uint8)sizeof(u8ESPActvinfolmp));
	*data_f = u8ESPFailsts;
	*data_s = u8ESPActvinfolmp;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFAILSTS, &u8ESPFailsts, (uint8)sizeof(u8ESPFailsts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPACTVINFOLMP, &u8ESPActvinfolmp, (uint8)sizeof(u8ESPActvinfolmp));
	*data_f = u8ESPFailsts;
	*data_s = u8ESPActvinfolmp;


	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#else
#endif
    return result;
}

TT_ADAPT_TYPE ATT_GetMessage_ESP_Disable_Sts(uint8 *data)
{
    uint8 result = RTE_E_INVALID;
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
#else
    uint8 u8ESPFuncoffsts = 0;
#endif
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
	SG_ESP1 ATT_ESP1;
	SG_ESP1_ESP_FD2 ATT_ESP_FD1;
    if (ATT_vSignal_Source_Process() == ATT_CANFD_SIGNAL)
    {
        result = Rte_Read_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2(&ATT_ESP_FD1);
        *data = ATT_ESP_FD1.ESPFuncOffSts_0x137 ? 1u : 0u;
    }
    else
    {
        result = Rte_Read_SG_ESP1_SG_ESP1(&ATT_ESP1);
        *data = ATT_ESP1.ESPFuncOffSts_0x149 ? 1u : 0u;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFUNCOFFSTS, &u8ESPFuncoffsts, (uint8)sizeof(u8ESPFuncoffsts));
	*data = u8ESPFuncoffsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFUNCOFFSTS, &u8ESPFuncoffsts, (uint8)sizeof(u8ESPFuncoffsts));
	*data = u8ESPFuncoffsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
    if (ATT_vSignal_Source_Process() == ATT_CANFD_SIGNAL)
    {
        result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFUNCOFFSTS_0X137, &u8ESPFuncoffsts, (uint8)sizeof(u8ESPFuncoffsts));
        *data = u8ESPFuncoffsts;
    }
    else
    {
        result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFUNCOFFSTS_0X149, &u8ESPFuncoffsts, (uint8)sizeof(u8ESPFuncoffsts));
        *data = u8ESPFuncoffsts;
    }

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFUNCOFFSTS, &u8ESPFuncoffsts, (uint8)sizeof(u8ESPFuncoffsts));
	*data = u8ESPFuncoffsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFUNCOFFSTS, &u8ESPFuncoffsts, (uint8)sizeof(u8ESPFuncoffsts));
    *data = u8ESPFuncoffsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFUNCOFFSTS, &u8ESPFuncoffsts,(uint8)sizeof(u8ESPFuncoffsts));
    *data = u8ESPFuncoffsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFUNCOFFSTS, &u8ESPFuncoffsts, (uint8)sizeof(u8ESPFuncoffsts));
    *data = u8ESPFuncoffsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFUNCOFFSTS, &u8ESPFuncoffsts, (uint8)sizeof(u8ESPFuncoffsts));
	*data = u8ESPFuncoffsts;

	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFUNCOFFSTS, &u8ESPFuncoffsts, (uint8)sizeof(u8ESPFuncoffsts));
	*data = u8ESPFuncoffsts;

	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#else
#endif
    return result;
}

TT_ADAPT_TYPE ATT_GetMessage_EPB_Sts(uint8 *data)
{
    uint8 result = RTE_E_INVALID;
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
    SG_EPB1 ATT_EPB1;
#else
    uint8 u8EPBErrsts = 0;
#endif
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
    result = Rte_Read_SG_EPB1_SG_EPB1(&ATT_EPB1);
    *data = ATT_EPB1.EPBErrSts;
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBERRSTS, &u8EPBErrsts, (uint8)sizeof(u8EPBErrsts));
    *data = u8EPBErrsts;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBERRSTS, &u8EPBErrsts, (uint8)sizeof(u8EPBErrsts));
    *data = u8EPBErrsts;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBERRSTS, &u8EPBErrsts, (uint8)sizeof(u8EPBErrsts));
    *data = u8EPBErrsts;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBERRSTS, &u8EPBErrsts, (uint8)sizeof(u8EPBErrsts));
    *data = u8EPBErrsts;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBERRSTS, &u8EPBErrsts, (uint8)sizeof(u8EPBErrsts));
    *data = u8EPBErrsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBERRSTS, &u8EPBErrsts, (uint8)sizeof(u8EPBErrsts));
    *data = u8EPBErrsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBERRSTS, &u8EPBErrsts, (uint8)sizeof(u8EPBErrsts));
    *data = u8EPBErrsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBERRSTS, &u8EPBErrsts, (uint8)sizeof(u8EPBErrsts));
    *data = u8EPBErrsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBERRSTS, &u8EPBErrsts, (uint8)sizeof(u8EPBErrsts));
	*data = u8EPBErrsts;

	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#else
#endif
    return result;
}

TT_ADAPT_TYPE ATT_GetMessage_Break_Erro_Sts(uint8 *data)
{
    uint8 result = RTE_E_INVALID;
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
	SG_ABS3 ATT_ABS3;
	SG_ABS3_ESP_FD2 ATT_ESP_FD2;
#else
    uint8 u8EBDFailsts = 0;
#endif
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
    if (ATT_vSignal_Source_Process() == ATT_CANFD_SIGNAL)
    {
        result = Rte_Read_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2(&ATT_ESP_FD2);
        *data = ATT_ESP_FD2.EBDFailSts_0x137 ? 1u : 0u;
    }
    else
    {
        result = Rte_Read_SG_ABS3_SG_ABS3(&ATT_ABS3);
        *data = ATT_ABS3.EBDFailSts_0x265 ? 1u : 0u;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EBDFAILSTS, &u8EBDFailsts, (uint8)sizeof(u8EBDFailsts));
	*data = u8EBDFailsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EBDFAILSTS, &u8EBDFailsts, (uint8)sizeof(u8EBDFailsts));
	*data = u8EBDFailsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
    if (ATT_vSignal_Source_Process() == ATT_CANFD_SIGNAL)
    {
        result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EBDFAILSTS_0X137, &u8EBDFailsts, (uint8)sizeof(u8EBDFailsts));
        *data = u8EBDFailsts;
    }
    else
    {
        result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EBDFAILSTS_0X265, &u8EBDFailsts, (uint8)sizeof(u8EBDFailsts));
        *data = u8EBDFailsts;
    }

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EBDFAILSTS, &u8EBDFailsts, (uint8)sizeof(u8EBDFailsts));
	*data = u8EBDFailsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
    *data = 0;//TBD
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
    *data = 0;//TBD
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
    *data = 0;//TBD
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EBDFAILSTS, &u8EBDFailsts, (uint8)sizeof(u8EBDFailsts));
	*data = u8EBDFailsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
		result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EBDFAILSTS, &u8EBDFailsts, (uint8)sizeof(u8EBDFailsts));
		*data = u8EBDFailsts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#endif
    return result;
}

TT_ADAPT_TYPE ATT_GetMessage_EPS_Sts(uint8 *data)
{
    uint8 result = RTE_E_INVALID;
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
	SG_EPS1 ATT_EPS1;
	SG_EPS1_FD1 ATT_EPS1_FD1;
#else
    uint8 u8EPSFailsts = 0;
#endif
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
    if (ATT_vSignal_Source_Process() == ATT_CANFD_SIGNAL)
    {
        result = Rte_Read_SG_EPS1_FD1_SG_EPS1_FD1(&ATT_EPS1_FD1);
        *data = (uint8)ATT_EPS1_FD1.EPS_FailSts_0x147;
    }
    else
    {
        result = Rte_Read_SG_EPS1_SG_EPS1(&ATT_EPS1);
        *data = (uint8)ATT_EPS1.EPS_FailSts_0x168;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, &u8EPSFailsts, sizeof(u8EPSFailsts));
	*data = u8EPSFailsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, &u8EPSFailsts, sizeof(u8EPSFailsts));
	*data = u8EPSFailsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
    if (ATT_vSignal_Source_Process() == ATT_CANFD_SIGNAL)
    {
        result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS_0X147, &u8EPSFailsts, (uint8)sizeof(u8EPSFailsts));
        *data = u8EPSFailsts;
    }
    else
    {
        result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS_0X168, &u8EPSFailsts, (uint8)sizeof(u8EPSFailsts));
        *data = u8EPSFailsts;
    }

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, &u8EPSFailsts, (uint8)sizeof(u8EPSFailsts));
	*data = u8EPSFailsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, &u8EPSFailsts, (uint8)sizeof(u8EPSFailsts));
    *data = u8EPSFailsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, &u8EPSFailsts, (uint8)sizeof(u8EPSFailsts));
    *data = u8EPSFailsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, &u8EPSFailsts, (uint8)sizeof(u8EPSFailsts));
    *data = u8EPSFailsts;

    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, &u8EPSFailsts, (uint8)sizeof(u8EPSFailsts));
	*data = u8EPSFailsts;

	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, &u8EPSFailsts, (uint8)sizeof(u8EPSFailsts));
	*data = u8EPSFailsts;

	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#else
#endif
    return result;
}

TT_ADAPT_TYPE ATT_GetMessage_ABM_Sts(uint8 *data)
{
    uint8 result = RTE_E_INVALID;
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
    SG_ABM1 ATT_ABM1;
#else
	uint8 u8ABMFaillmpcmd = 0;
#endif
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
    result = Rte_Read_SG_ABM1_SG_ABM1(&ATT_ABM1);
    *data = ATT_ABM1.AirbFailLmpCmd ? 1u : 0u;
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AIRBFAILLMPCMD, &u8ABMFaillmpcmd, (uint8)sizeof(u8ABMFaillmpcmd));
    *data = u8ABMFaillmpcmd;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AIRBFAILLMPCMD, &u8ABMFaillmpcmd, (uint8)sizeof(u8ABMFaillmpcmd));
    *data = u8ABMFaillmpcmd;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AIRBFAILLMPCMD, &u8ABMFaillmpcmd, (uint8)sizeof(u8ABMFaillmpcmd));
    *data = u8ABMFaillmpcmd;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AIRBFAILLMPCMD, &u8ABMFaillmpcmd, (uint8)sizeof(u8ABMFaillmpcmd));
    *data = u8ABMFaillmpcmd;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AIRBFAILLMPCMD, &u8ABMFaillmpcmd, (uint8)sizeof(u8ABMFaillmpcmd));
    *data = u8ABMFaillmpcmd;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AIRBFAILLMPCMD, &u8ABMFaillmpcmd, (uint8)sizeof(u8ABMFaillmpcmd));
    *data = u8ABMFaillmpcmd;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AIRBFAILLMPCMD, &u8ABMFaillmpcmd, (uint8)sizeof(u8ABMFaillmpcmd));
    *data = u8ABMFaillmpcmd;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AIRBFAILLMPCMD, &u8ABMFaillmpcmd, (uint8)sizeof(u8ABMFaillmpcmd));
	*data = u8ABMFaillmpcmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AIRBFAILLMPCMD, &u8ABMFaillmpcmd, (uint8)sizeof(u8ABMFaillmpcmd));
	*data = u8ABMFaillmpcmd;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#else
#endif
    return result;
}

TT_ADAPT_TYPE ATT_GetMessage_FCW_Sts(uint8 *data_f, uint8 *data_s, uint8 *data_d, uint8 *data_l)
{
    uint8 result = RTE_E_INVALID;
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
	SG_AEB3_AEB_FD2 ATT_AEB3_FD2;
	SG_AEB2_AEB_FD2 ATT_AEB2_FD2;

#else
	uint8 u8AEBVehResp = 0;
    uint8 u8AEBPedResp = 0;
    uint8 u8AEBJAResp = 0;
    uint8 u8AEBVehFctSts = 0;
#endif
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
    result = Rte_Read_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2(&ATT_AEB3_FD2);
    (void)Rte_Read_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2(&ATT_AEB2_FD2);
    *data_f = (uint8)ATT_AEB3_FD2.FCW_AEB_VehFctSts;
    *data_s = ATT_AEB2_FD2.AEB_VehResp ? 1u : 0u;
    *data_d = ATT_AEB2_FD2.AEB_PedResp ? 1u : 0u;
    *data_l = ATT_AEB2_FD2.AEB_JA_Resp ? 1u : 0u;
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_AEB_VEHFCTSTS, &u8AEBVehFctSts, (uint8)sizeof(u8AEBVehFctSts));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHRESP, &u8AEBVehResp, (uint8)sizeof(u8AEBVehResp));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDRESP, &u8AEBPedResp, (uint8)sizeof(u8AEBPedResp));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JA_RESP, &u8AEBJAResp, (uint8)sizeof(u8AEBJAResp));
    *data_f = u8AEBVehFctSts;
    *data_s = u8AEBVehResp;
    *data_d = u8AEBPedResp;
    *data_l = u8AEBJAResp;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_AEB_VEHFCTSTS, &u8AEBVehFctSts, (uint8)sizeof(u8AEBVehFctSts));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHRESP, &u8AEBVehResp, (uint8)sizeof(u8AEBVehResp));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDRESP, &u8AEBPedResp, (uint8)sizeof(u8AEBPedResp));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JA_RESP, &u8AEBJAResp, (uint8)sizeof(u8AEBJAResp));
    *data_f = u8AEBVehFctSts;
    *data_s = u8AEBVehResp;
    *data_d = u8AEBPedResp;
    *data_l = u8AEBJAResp;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_AEB_VEHFCTSTS, &u8AEBVehFctSts, (uint8)sizeof(u8AEBVehFctSts));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHRESP, &u8AEBVehResp, (uint8)sizeof(u8AEBVehResp));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDRESP, &u8AEBPedResp, (uint8)sizeof(u8AEBPedResp));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JA_RESP, &u8AEBJAResp, (uint8)sizeof(u8AEBJAResp));
    *data_f = u8AEBVehFctSts;
    *data_s = u8AEBVehResp;
    *data_d = u8AEBPedResp;
    *data_l = u8AEBJAResp;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_AEB_VEHFCTSTS, &u8AEBVehFctSts, (uint8)sizeof(u8AEBVehFctSts));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHRESP, &u8AEBVehResp, (uint8)sizeof(u8AEBVehResp));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDRESP, &u8AEBPedResp, (uint8)sizeof(u8AEBPedResp));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JA_RESP, &u8AEBJAResp, (uint8)sizeof(u8AEBJAResp));
    *data_f = u8AEBVehFctSts;
    *data_s = u8AEBVehResp;
    *data_d = u8AEBPedResp;
    *data_l = u8AEBJAResp;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_AEB_VEHFCTSTS, &u8AEBVehFctSts, (uint8)sizeof(u8AEBVehFctSts));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHRESP, &u8AEBVehResp, (uint8)sizeof(u8AEBVehResp));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDRESP, &u8AEBPedResp, (uint8)sizeof(u8AEBPedResp));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JA_RESP, &u8AEBJAResp, (uint8)sizeof(u8AEBJAResp));
    *data_f = u8AEBVehFctSts;
    *data_s = u8AEBVehResp;
    *data_d = u8AEBPedResp;
    *data_l = u8AEBJAResp;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_AEB_VEHFCTSTS, &u8AEBVehFctSts, (uint8)sizeof(u8AEBVehFctSts));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHRESP, &u8AEBVehResp, (uint8)sizeof(u8AEBVehResp));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDRESP, &u8AEBPedResp, (uint8)sizeof(u8AEBPedResp));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JA_RESP, &u8AEBJAResp, (uint8)sizeof(u8AEBJAResp));
    *data_f = u8AEBVehFctSts;
    *data_s = u8AEBVehResp;
    *data_d = u8AEBPedResp;
    *data_l = u8AEBJAResp;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_AEB_VEHFCTSTS, &u8AEBVehFctSts, (uint8)sizeof(u8AEBVehFctSts));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHRESP, &u8AEBVehResp, (uint8)sizeof(u8AEBVehResp));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDRESP, &u8AEBPedResp, (uint8)sizeof(u8AEBPedResp));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JA_RESP, &u8AEBJAResp, (uint8)sizeof(u8AEBJAResp));
    *data_f = u8AEBVehFctSts;
    *data_s = u8AEBVehResp;
    *data_d = u8AEBPedResp;
    *data_l = u8AEBJAResp;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_AEB_VEHFCTSTS, &u8AEBVehFctSts, (uint8)sizeof(u8AEBVehFctSts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHRESP, &u8AEBVehResp, (uint8)sizeof(u8AEBVehResp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDRESP, &u8AEBPedResp, (uint8)sizeof(u8AEBPedResp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JA_RESP, &u8AEBJAResp, (uint8)sizeof(u8AEBJAResp));
	*data_f = u8AEBVehFctSts;
	*data_s = u8AEBVehResp;
	*data_d = u8AEBPedResp;
	*data_l = u8AEBJAResp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_AEB_VEHFCTSTS, &u8AEBVehFctSts, (uint8)sizeof(u8AEBVehFctSts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHRESP, &u8AEBVehResp, (uint8)sizeof(u8AEBVehResp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDRESP, &u8AEBPedResp, (uint8)sizeof(u8AEBPedResp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JA_RESP, &u8AEBJAResp, (uint8)sizeof(u8AEBJAResp));
	*data_f = u8AEBVehFctSts;
	*data_s = u8AEBVehResp;
	*data_d = u8AEBPedResp;
	*data_l = u8AEBJAResp;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#else
#endif
    return result;
}

TT_ADAPT_TYPE ATT_GetMessage_PBF_Sts(uint8 *data)
{
    uint8 result = RTE_E_INVALID;
#if defined (SWC_TT_SAFETY_PROJECT_TYPE_B03) || defined (SWC_TT_SAFETY_PROJECT_TYPE_P05)
#else
	uint8 PBFErrcategory = 0;
#endif
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
    SG_BMS4 ATT_BMS4_PBFRed;
    result = Rte_Read_SG_BMS4_SG_BMS4(&ATT_BMS4_PBFRed);
    *data = ATT_BMS4_PBFRed.BMS_ErrCategory;
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, &PBFErrcategory, (uint8)sizeof(PBFErrcategory));
    *data = PBFErrcategory;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, &PBFErrcategory, (uint8)sizeof(PBFErrcategory));
    *data = PBFErrcategory;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
    *data = 0u;
	result = RTE_E_OK;
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
    // result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, &PBFErrcategory, (uint8)sizeof(PBFErrcategory));
    *data = PBFErrcategory;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, &PBFErrcategory, (uint8)sizeof(PBFErrcategory));
    *data = PBFErrcategory;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, &PBFErrcategory, (uint8)sizeof(PBFErrcategory));
    *data = PBFErrcategory;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, &PBFErrcategory, (uint8)sizeof(PBFErrcategory));
    *data = PBFErrcategory;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, &PBFErrcategory, (uint8)sizeof(PBFErrcategory));
	*data = PBFErrcategory;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, &PBFErrcategory, (uint8)sizeof(PBFErrcategory));
	*data = PBFErrcategory;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#else
#endif
    return result;
}

TT_ADAPT_TYPE ATT_GetMessage_HEV_Sts(uint8 *data)
{
    uint8 result = RTE_E_INVALID;
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
#else
    uint8 HEVHybsys = 0;
#endif
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
    SG_HCU_PT7 ATT_HCU_PT7_HEV;
    result = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&ATT_HCU_PT7_HEV);
    *data = ATT_HCU_PT7_HEV.HCU_HybSysErrLmpSts;
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERRLMPSTS, &HEVHybsys, (uint8)sizeof(HEVHybsys));
    *data = HEVHybsys;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERRLMPSTS, &HEVHybsys, (uint8)sizeof(HEVHybsys));
    *data = HEVHybsys;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERRLMPSTS, &HEVHybsys, (uint8)sizeof(HEVHybsys));
    *data = HEVHybsys;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
    // result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERRLMPSTS, &HEVHybsys, (uint8)sizeof(HEVHybsys));
    *data = HEVHybsys;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERRLMPSTS, &HEVHybsys, (uint8)sizeof(HEVHybsys));
    *data = HEVHybsys;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERRLMPSTS, &HEVHybsys, (uint8)sizeof(HEVHybsys));
    *data = HEVHybsys;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERRLMPSTS, &HEVHybsys, (uint8)sizeof(HEVHybsys));
    *data = HEVHybsys;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERRLMPSTS, &HEVHybsys, (uint8)sizeof(HEVHybsys));
	*data = HEVHybsys;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERRLMPSTS, &HEVHybsys, (uint8)sizeof(HEVHybsys));
	*data = HEVHybsys;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#else
#endif
    return result;
}

TT_ADAPT_TYPE ATT_GetMessage_TPF_Sts(uint8 *data)
{
    uint8 result = RTE_E_INVALID;
#if defined (SWC_TT_SAFETY_PROJECT_TYPE_B03) || defined (SWC_TT_SAFETY_PROJECT_TYPE_P05)
#else
    uint8 u8TPFSyserrlmpsts = 0;
#endif
#if defined SWC_TT_SAFETY_PROJECT_TYPE_B03
    SG_HCU_PT7 ATT_HCU_PT7_TPF;
    result = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&ATT_HCU_PT7_TPF);
    *data = ATT_HCU_PT7_TPF.HCU_12VSysErrLmpSts ? 1u : 0u;
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_B02
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERRLMPSTS, &u8TPFSyserrlmpsts, (uint8)sizeof(u8TPFSyserrlmpsts));
    *data = u8TPFSyserrlmpsts;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P03
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERRLMPSTS, &u8TPFSyserrlmpsts, (uint8)sizeof(u8TPFSyserrlmpsts));
    *data = u8TPFSyserrlmpsts;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P05
	*data = 0u;
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_A07
    // result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERRLMPSTS, &u8TPFSyserrlmpsts, (uint8)sizeof(u8TPFSyserrlmpsts));
    *data = u8TPFSyserrlmpsts;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D01
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERRLMPSTS, &u8TPFSyserrlmpsts, (uint8)sizeof(u8TPFSyserrlmpsts));
    *data = u8TPFSyserrlmpsts;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D02
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERRLMPSTS, &u8TPFSyserrlmpsts, (uint8)sizeof(u8TPFSyserrlmpsts));
    *data = u8TPFSyserrlmpsts;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_D03
    result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERRLMPSTS, &u8TPFSyserrlmpsts, (uint8)sizeof(u8TPFSyserrlmpsts));
    *data = u8TPFSyserrlmpsts;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P02
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERRLMPSTS, &u8TPFSyserrlmpsts, (uint8)sizeof(u8TPFSyserrlmpsts));
	*data = u8TPFSyserrlmpsts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif defined SWC_TT_SAFETY_PROJECT_TYPE_P01
	result = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERRLMPSTS, &u8TPFSyserrlmpsts, (uint8)sizeof(u8TPFSyserrlmpsts));
	*data = u8TPFSyserrlmpsts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#else
#endif
    return result;
}


#define Common_Safety_STOP_SEC_CODE
#include "Common_Safety_MemMap.h"

/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
