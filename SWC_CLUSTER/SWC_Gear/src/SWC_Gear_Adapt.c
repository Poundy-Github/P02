
/**********************************************************************************************************
*                                                                                                         *
*                          CONFIDENTIAL NOBO CORPORATION                              					  *
*                                                                                                         *
* Copyright @ 2019 - 2021 Nobo Automotive Technologies Co.,Ltd.                                           *
* All Rights Reserved.                                                                                    *
*                                                                                                         *
* Redistribution and use in source and binary forms, with or without                                      *
* modification, are NOT permitted except as agreed by                                                     *
* Nobo Automotive Technologies Co.,Ltd.                                                                   *
*                                                                                                         *
* Unless required by applicable law or agreed to in writing, software                                     *
* distributed under the License is distributed on an "AS IS" BASIS,                                       *
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.                                *
*                                                                                                         *
**********************************************************************************************************/

/**********************************************************************************************************
*File Name   : SWC_Gear_Adapt.c                                                                           *
*                                                                                                         *
*Description : Gear module process function source file.                                                  *
*                                                                                                         *
*Author      : Hu Hai                                                                                     *
*                                                                                                         *
*Platform    : MICROSAR OS                                                                                *
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
#include "Rte_Common_Safety.h"
#include "SWC_Gear_Adapt.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/

#define Common_GateWay_START_SEC_CODE
#include "Common_Safety_MemMap.h"

SystemState_RecordType *GearMdl_Adapt_GetPowerMode(void)
{
	SystemState_RecordType *u8PowerMode;

#if (defined(SWC_GEAR_ADAPT_B03))
	u8PowerMode = Rte_IRead_Common_Safety_10msMainFunction_rpSR_SWCSafety_Power_Out_SystemStateOut();
#elif (defined(SWC_GEAR_ADAPT_B02))
	u8PowerMode = Rte_IRead_Common_Safety_10msMainFunction_rpSR_SWCSafety_Power_Out_SystemStateOut();
#elif (defined(SWC_GEAR_ADAPT_P05))
	u8PowerMode = Rte_IRead_Common_Safety_10msMainFunction_rpSR_SWCSafety_Power_Out_SystemStateOut();
#elif (defined(SWC_GEAR_ADAPT_P03))
	u8PowerMode = Rte_IRead_Common_Safety_10msMainFunction_rpSR_SWCSafety_Power_Out_SystemStateOut();
#elif (defined(SWC_GEAR_ADAPT_A07))
	u8PowerMode = Rte_IRead_Common_Safety_10msMainFunction_rpSR_SWCSafety_Power_Out_SystemStateOut();
#elif (defined(SWC_GEAR_ADAPT_P02))
	u8PowerMode = Rte_IRead_Common_Safety_10msMainFunction_rpSR_SWCSafety_Power_Out_SystemStateOut();
#elif (defined(SWC_GEAR_ADAPT_D01))
	u8PowerMode = Rte_IRead_Common_Safety_10msMainFunction_rpSR_SWCSafety_Power_Out_SystemStateOut();
#elif (defined(SWC_GEAR_ADAPT_D02))
	u8PowerMode = Rte_IRead_Common_Safety_10msMainFunction_rpSR_SWCSafety_Power_Out_SystemStateOut();
#elif (defined(SWC_GEAR_ADAPT_D03))
	u8PowerMode = Rte_IRead_Common_Safety_10msMainFunction_rpSR_SWCSafety_Power_Out_SystemStateOut();
#elif (defined(SWC_GEAR_ADAPT_P01))
	u8PowerMode = Rte_IRead_Common_Safety_10msMainFunction_rpSR_SWCSafety_Power_Out_SystemStateOut();
#endif
	return u8PowerMode;
}

uint8 GearMdl_Adapt_GetCANMessage_7DCT(GR_CFG_SG_DCT7* const MESS_SG_7DCT)
{
	uint8 ret = 0xFFU;

#if (defined(SWC_GEAR_ADAPT_B03))
	SG_DCT7 mess_DCT7 = {0};
	ret = Rte_Read_SG_DCT7_SG_DCT7(&mess_DCT7);
	MESS_SG_7DCT->GR_DrvAutoGearDisp = mess_DCT7.DrvAutoGearDisp;
	MESS_SG_7DCT->GR_DrvGearDispSts = mess_DCT7.DrvGearDispSts_0x235;
	MESS_SG_7DCT->GR_DrvModDisp = mess_DCT7.DrvModDisp_0x235;
	MESS_SG_7DCT->GR_DrvModDispSts = mess_DCT7.DrvModDispSts_0x235;
	MESS_SG_7DCT->GR_DCT_ShftRecom_M = mess_DCT7.DCT_ShftRecom_M;
#elif (defined(SWC_GEAR_ADAPT_B02))
	(void)memset(MESS_SG_7DCT, 0, sizeof(GR_CFG_SG_DCT7));		/* None */
#elif (defined(SWC_GEAR_ADAPT_P05))
	(void)memset(MESS_SG_7DCT, 0, sizeof(GR_CFG_SG_DCT7));		/* None */
#elif (defined(SWC_GEAR_ADAPT_P03))
	(void)memset(MESS_SG_7DCT, 0, sizeof(GR_CFG_SG_DCT7));		/* None */
#elif (defined(SWC_GEAR_ADAPT_A07))
    ret = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVAUTOGEARDISP, (uint8 *)&(MESS_SG_7DCT->GR_DrvAutoGearDisp), (uint8)sizeof(MESS_SG_7DCT->GR_DrvAutoGearDisp));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVGEARDISPSTS, (uint8 *)&(MESS_SG_7DCT->GR_DrvGearDispSts), (uint8)sizeof(MESS_SG_7DCT->GR_DrvGearDispSts));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISP, (uint8 *)&(MESS_SG_7DCT->GR_DrvModDisp), (uint8)sizeof(MESS_SG_7DCT->GR_DrvModDisp));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISPSTS, (uint8 *)&(MESS_SG_7DCT->GR_DrvModDispSts), (uint8)sizeof(MESS_SG_7DCT->GR_DrvModDispSts));
    (void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTRECOM_M, (uint8 *)&(MESS_SG_7DCT->GR_DCT_ShftRecom_M), (uint8)sizeof(MESS_SG_7DCT->GR_DCT_ShftRecom_M));

	if(ret == COMEX_UPDATE_RECEIVED)
	{
		ret = 0;
	}
#elif (defined(SWC_GEAR_ADAPT_D01))
	(void)memset(MESS_SG_7DCT, 0, sizeof(GR_CFG_SG_DCT7));		/* None */
#elif (defined(SWC_GEAR_ADAPT_D02))
	(void)memset(MESS_SG_7DCT, 0, sizeof(GR_CFG_SG_DCT7));		/* None */
#elif (defined(SWC_GEAR_ADAPT_D03))
	(void)memset(MESS_SG_7DCT, 0, sizeof(GR_CFG_SG_DCT7));		/* None */
#elif (defined(SWC_GEAR_ADAPT_P02))
	(void)memset(MESS_SG_7DCT, 0, sizeof(GR_CFG_SG_DCT7));		/* None */
#elif (defined(SWC_GEAR_ADAPT_P01))
	(void)memset(MESS_SG_7DCT, 0, sizeof(GR_CFG_SG_DCT7));		/* None */
#endif
	return ret;
}

uint32 GearMdl_Adapt_GetE2EPW_DCT7(void)
{
	uint32 ret = 0xFFFFFFFFU;

#if (defined(SWC_GEAR_ADAPT_B03))
	SG_DCT7 strMsg_Dct7 = {0};
	ret = E2EPW_Read_SG_DCT7_SG_DCT7(&strMsg_Dct7);
#elif (defined(SWC_GEAR_ADAPT_B02))
#elif (defined(SWC_GEAR_ADAPT_P05))
#elif (defined(SWC_GEAR_ADAPT_P03))
#elif (defined(SWC_GEAR_ADAPT_A07))
	(void)Rte_Call_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_DCT7, &ret);
#elif (defined(SWC_GEAR_ADAPT_D01))
#elif (defined(SWC_GEAR_ADAPT_D02))
#elif (defined(SWC_GEAR_ADAPT_D03))
#elif (defined(SWC_GEAR_ADAPT_P02))
#elif (defined(SWC_GEAR_ADAPT_P01))
#endif
	return ret;
}

uint8 GearMdl_Adapt_GetCANMessage_DCT_FD4(GR_CFG_SG_DCT_FD4* const MESS_SG_DCTFD4)
{
	uint8 ret = 0xFFU;

#if (defined(SWC_GEAR_ADAPT_B03))
	(void)memset(MESS_SG_DCTFD4, 0, sizeof(GR_CFG_SG_DCT_FD4));		/* None */
#elif (defined(SWC_GEAR_ADAPT_B02))
	ret = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVAUTOGEARDISP, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvAutoGearDisp), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvAutoGearDisp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVGEARDISPSTS_0X236, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvGearDispSts), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvGearDispSts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISP_0X236, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvModDisp), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvModDisp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISPSTS_0X236, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvModDispSts), uint8)sizeof(MESS_SG_DCTFD4->GR_DrvModDispSts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTRECOM_M, (uint8 *)&(MESS_SG_DCTFD4->GR_DCT_ShftRecom_M), (uint8)sizeof(MESS_SG_DCTFD4->GR_DCT_ShftRecom_M));

	if(ret == COMEX_UPDATE_RECEIVED)
	{
		ret = 0U;
	}
#elif (defined(SWC_GEAR_ADAPT_P05))
	ret = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVAUTOGEARDISP, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvAutoGearDisp), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvAutoGearDisp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVGEARDISPSTS, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvGearDispSts), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvGearDispSts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISP_0X236, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvModDisp), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvModDisp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISPSTS, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvModDispSts), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvModDispSts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTRECOM_M, (uint8 *)&(MESS_SG_DCTFD4->GR_DCT_ShftRecom_M), (uint8)sizeof(MESS_SG_DCTFD4->GR_DCT_ShftRecom_M));

	if(ret == COMEX_UPDATE_RECEIVED)
	{
		ret = 0U;
	}
#elif (defined(SWC_GEAR_ADAPT_P03))
	ret = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVAUTOGEARDISP, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvAutoGearDisp), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvAutoGearDisp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVGEARDISPSTS, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvGearDispSts), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvGearDispSts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISP, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvModDisp), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvModDisp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISPSTS, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvModDispSts), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvModDispSts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTRECOM_M, (uint8 *)&(MESS_SG_DCTFD4->GR_DCT_ShftRecom_M), (uint8)sizeof(MESS_SG_DCTFD4->GR_DCT_ShftRecom_M));

	if(ret == COMEX_UPDATE_RECEIVED)
	{
		ret = 0U;
	}
#elif (defined(SWC_GEAR_ADAPT_A07))
	(void)memset(MESS_SG_DCTFD4, 0, sizeof(GR_CFG_SG_DCT_FD4));		/* None */
#elif (defined(SWC_GEAR_ADAPT_D01))
	ret = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVAUTOGEARDISP, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvAutoGearDisp), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvAutoGearDisp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVGEARDISPSTS, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvGearDispSts), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvGearDispSts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISP, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvModDisp), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvModDisp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISPSTS, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvModDispSts), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvModDispSts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTRECOM_M, (uint8 *)&(MESS_SG_DCTFD4->GR_DCT_ShftRecom_M), (uint8)sizeof(MESS_SG_DCTFD4->GR_DCT_ShftRecom_M));

	if(ret == COMEX_UPDATE_RECEIVED)
	{
		ret = 0U;
	}
#elif (defined(SWC_GEAR_ADAPT_D02))
	ret = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVAUTOGEARDISP, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvAutoGearDisp), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvAutoGearDisp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVGEARDISPSTS, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvGearDispSts), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvGearDispSts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISP, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvModDisp), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvModDisp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISPSTS, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvModDispSts), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvModDispSts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTRECOM_M, (uint8 *)&(MESS_SG_DCTFD4->GR_DCT_ShftRecom_M), (uint8)sizeof(MESS_SG_DCTFD4->GR_DCT_ShftRecom_M));

	if(ret == COMEX_UPDATE_RECEIVED)
	{
		ret = 0U;
	}

#elif (defined(SWC_GEAR_ADAPT_D03))
	ret = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVAUTOGEARDISP, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvAutoGearDisp), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvAutoGearDisp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVGEARDISPSTS, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvGearDispSts), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvGearDispSts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISP, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvModDisp), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvModDisp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISPSTS, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvModDispSts), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvModDispSts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTRECOM_M, (uint8 *)&(MESS_SG_DCTFD4->GR_DCT_ShftRecom_M), (uint8)sizeof(MESS_SG_DCTFD4->GR_DCT_ShftRecom_M));

	if(ret == COMEX_UPDATE_RECEIVED)
	{
		ret = 0U;
	}
#elif (defined(SWC_GEAR_ADAPT_P02))
	ret = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVAUTOGEARDISP, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvAutoGearDisp), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvAutoGearDisp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVGEARDISPSTS, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvGearDispSts), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvGearDispSts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISP, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvModDisp), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvModDisp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISPSTS, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvModDispSts), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvModDispSts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTRECOM_M, (uint8 *)&(MESS_SG_DCTFD4->GR_DCT_ShftRecom_M), (uint8)sizeof(MESS_SG_DCTFD4->GR_DCT_ShftRecom_M));

	if(ret == COMEX_UPDATE_RECEIVED)
	{
		ret = 0U;
	}
#elif (defined(SWC_GEAR_ADAPT_P01))
	ret = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVAUTOGEARDISP, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvAutoGearDisp), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvAutoGearDisp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVGEARDISPSTS, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvGearDispSts), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvGearDispSts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISP, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvModDisp), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvModDisp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISPSTS, (uint8 *)&(MESS_SG_DCTFD4->GR_DrvModDispSts), (uint8)sizeof(MESS_SG_DCTFD4->GR_DrvModDispSts));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTRECOM_M, (uint8 *)&(MESS_SG_DCTFD4->GR_DCT_ShftRecom_M), (uint8)sizeof(MESS_SG_DCTFD4->GR_DCT_ShftRecom_M));

	if(ret == COMEX_UPDATE_RECEIVED)
	{
		ret = 0U;
	}
#endif
	return ret;
}

uint32 GearMdl_Adapt_GetE2EPW_DCT_FD4(void)
{
	uint32 ret = 0xFFFFFFFFU;

#if (defined(SWC_GEAR_ADAPT_B03))
#elif (defined(SWC_GEAR_ADAPT_B02))
	(void)Rte_Call_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_DCT_FD4, &ret);
#elif (defined(SWC_GEAR_ADAPT_P05))
    (void)Rte_Call_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_DCT_FD4, &ret);
#elif (defined(SWC_GEAR_ADAPT_P03))
    (void)Rte_Call_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_DCT_FD4, &ret);
#elif (defined(SWC_GEAR_ADAPT_A07))
#elif (defined(SWC_GEAR_ADAPT_D01))
    (void)Rte_Call_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_DCT_FD4, &ret);
#elif (defined(SWC_GEAR_ADAPT_D02))
    (void)Rte_Call_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_DCT_FD4, &ret);
#elif (defined(SWC_GEAR_ADAPT_D03))
    (void)Rte_Call_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_DCT_FD4, &ret);
#elif (defined(SWC_GEAR_ADAPT_P02))
    (void)Rte_Call_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_DCT_FD4, &ret);
#elif (defined(SWC_GEAR_ADAPT_P01))
	(void)Rte_Call_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_DCT_FD4, &ret);
#endif
	return ret;
}

uint8 GearMdl_Adapt_GetCANMessage_9DCT(GR_CFG_DCT9* const MESS_SG_DCT9)
{
	uint8 ret = 0xFFU;

#if (defined(SWC_GEAR_ADAPT_B03))
	(void)memset(MESS_SG_DCT9, 0, sizeof(GR_CFG_DCT9));		/* None */
#elif (defined(SWC_GEAR_ADAPT_B02))
	(void)memset(MESS_SG_DCT9, 0, sizeof(GR_CFG_DCT9));		/* None */
#elif (defined(SWC_GEAR_ADAPT_P05))
	ret = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISP_0XC6, (uint8*)&(MESS_SG_DCT9->GR_DrvModDisp), (uint8)sizeof(MESS_SG_DCT9->GR_DrvModDisp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_GEAR_FLASHING, (uint8*)&(MESS_SG_DCT9->GR_TCUGearFlashing), (uint8)sizeof(MESS_SG_DCT9->GR_TCUGearFlashing));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DISPLAYGEAR, (uint8*)&(MESS_SG_DCT9->GR_DisplayGear), (uint8)sizeof(MESS_SG_DCT9->GR_DisplayGear));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SHIFTRECOMMEND_M, (uint8*)&(MESS_SG_DCT9->GR_ShftRecom_M), (uint8)sizeof(MESS_SG_DCT9->GR_ShftRecom_M));

	if(ret == COMEX_UPDATE_RECEIVED)
	{
		ret = 0U;
	}
#elif (defined(SWC_GEAR_ADAPT_P03))
	(void)memset(MESS_SG_DCT9, 0, sizeof(GR_CFG_DCT9));		/* None */
#elif (defined(SWC_GEAR_ADAPT_A07))
	(void)memset(MESS_SG_DCT9, 0, sizeof(GR_CFG_DCT9));		/* None */
#elif (defined(SWC_GEAR_ADAPT_D01))
	(void)memset(MESS_SG_DCT9, 0, sizeof(GR_CFG_DCT9));		/* None */
#elif (defined(SWC_GEAR_ADAPT_D02))
	(void)memset(MESS_SG_DCT9, 0, sizeof(GR_CFG_DCT9));		/* None */
#elif (defined(SWC_GEAR_ADAPT_D03))
	(void)memset(MESS_SG_DCT9, 0, sizeof(GR_CFG_DCT9));		/* None */
#elif (defined(SWC_GEAR_ADAPT_P02))
	(void)memset(MESS_SG_DCT9, 0, sizeof(GR_CFG_DCT9));		/* None */
#elif (defined(SWC_GEAR_ADAPT_P01))
    (void)memset(MESS_SG_DCT9, 0, sizeof(GR_CFG_DCT9));		/* None */
#endif
	return ret;
}

uint32 GearMdl_Adapt_GetE2EPW_DCT9(void)
{
	uint32 ret = 0xFFFFFFFFU;

#if ((defined(SWC_GEAR_ADAPT_B03)))
#elif (defined(SWC_GEAR_ADAPT_B02))
#elif (defined(SWC_GEAR_ADAPT_P05))
	//(void)Rte_Call_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_DCT9,&ret);
	ret = 0U;	//E2E_OK
#elif (defined(SWC_GEAR_ADAPT_P03))
#elif (defined(SWC_GEAR_ADAPT_A07))
#elif (defined(SWC_GEAR_ADAPT_D01))
#elif (defined(SWC_GEAR_ADAPT_D02))
#elif (defined(SWC_GEAR_ADAPT_D03))
#elif (defined(SWC_GEAR_ADAPT_P02))
#elif (defined(SWC_GEAR_ADAPT_P01))
	ret = 0U;	//E2E_OK
#endif
	return ret;
}

uint8 GearMdl_Adapt_GetCANMessage_HCU_HP5(GR_CFG_SG_HCU_HP5* const MESS_SG_HP5)
{
	uint8 ret = 0xFFU;

#if (defined(SWC_GEAR_ADAPT_B03))
	SG_HCU_HP5 GR_SG_HCU_HP5 = {0};
	ret = Rte_Read_SG_HCU_HP5_SG_HCU_HP5(&GR_SG_HCU_HP5);
	MESS_SG_HP5->GR_DrvModDisp = GR_SG_HCU_HP5.DrvModDisp_0x201;
	MESS_SG_HP5->GR_DrvModDispSts = GR_SG_HCU_HP5.DrvModDispSts_0x201;
#elif (defined(SWC_GEAR_ADAPT_B02))
	ret = Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISP_0X201, (uint8 *)&(MESS_SG_HP5->GR_DrvModDisp), (uint8)sizeof(MESS_SG_HP5->GR_DrvModDisp));
	(void)Rte_Call_rpCS_SWCSafety_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVMODDISPSTS_0X201, (uint8 *)&(MESS_SG_HP5->GR_DrvModDispSts), (uint8)sizeof(MESS_SG_HP5->GR_DrvModDispSts));

	if(ret == COMEX_UPDATE_RECEIVED)
	{
		ret = 0U;
	}
#elif (defined(SWC_GEAR_ADAPT_P05))
	(void)memset(MESS_SG_HP5, 0, sizeof(GR_CFG_SG_HCU_HP5));		/* None */
#elif (defined(SWC_GEAR_ADAPT_P03))
	(void)memset(MESS_SG_HP5, 0, sizeof(GR_CFG_SG_HCU_HP5));		/* None */
#elif (defined(SWC_GEAR_ADAPT_A07))
	//DBC V4.1 DEL

	if(ret == COMEX_UPDATE_RECEIVED)
	{
		ret = 0U;
	}
#elif (defined(SWC_GEAR_ADAPT_D01))
	(void)memset(MESS_SG_HP5, 0, sizeof(GR_CFG_SG_HCU_HP5));		/* None */
#elif (defined(SWC_GEAR_ADAPT_D02))
	(void)memset(MESS_SG_HP5, 0, sizeof(GR_CFG_SG_HCU_HP5));		/* None */
#elif (defined(SWC_GEAR_ADAPT_D03))
	(void)memset(MESS_SG_HP5, 0, sizeof(GR_CFG_SG_HCU_HP5));		/* None */
#elif (defined(SWC_GEAR_ADAPT_P02))
	(void)memset(MESS_SG_HP5, 0, sizeof(GR_CFG_SG_HCU_HP5));		/* None */
#elif (defined(SWC_GEAR_ADAPT_P01))
	(void)memset(MESS_SG_HP5, 0, sizeof(GR_CFG_SG_HCU_HP5));		/* None */
#endif
	return ret;
}

uint32 GearMdl_Adapt_GetE2EPW_HCU_HP5(void)
{
	uint32 ret = 0xFFFFFFFFU;

#if ((defined(SWC_GEAR_ADAPT_B03)))
	SG_HCU_HP5 strMsg_HcuHp5 = {0};
	ret = E2EPW_Read_SG_HCU_HP5_SG_HCU_HP5(&strMsg_HcuHp5);
#elif (defined(SWC_GEAR_ADAPT_B02))
	(void)Rte_Call_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_HCU_HP5,&ret);
#elif (defined(SWC_GEAR_ADAPT_P05))
#elif (defined(SWC_GEAR_ADAPT_P03))
#elif (defined(SWC_GEAR_ADAPT_A07))
	//(void)Rte_Call_rpCS_SWCSafety_ComEx_GetRxE2EStatus(COMEX_SIGNALGROUP_RX_HCU_HP5,&ret);
	ret = 0U;	//E2E_OK
#elif (defined(SWC_GEAR_ADAPT_D01))
#elif (defined(SWC_GEAR_ADAPT_D02))
#elif (defined(SWC_GEAR_ADAPT_D03))
#elif (defined(SWC_GEAR_ADAPT_P02))
#elif (defined(SWC_GEAR_ADAPT_P01))
#endif
	return ret;
}

uint8 GearMdl_Adapt_GetCANMessaage_ECM10(GR_CFG_ECM10* const MESS_SG_ECM10)
{
	uint8 ret = 0xFFU;
#if ((defined(SWC_GEAR_ADAPT_B03)))
	(void)memset(MESS_SG_ECM10, 0, sizeof(GR_CFG_ECM10));		/* None */
#elif (defined(SWC_GEAR_ADAPT_B02))
	(void)memset(MESS_SG_ECM10, 0, sizeof(GR_CFG_ECM10));		/* None */
#elif (defined(SWC_GEAR_ADAPT_P05))
	// ret = ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTEARUP,&(MESS_SG_ECM10->TgtgearUp), (uint8)sizeof(MESS_SG_ECM10->TgtgearUp));
	// (void)ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTEARDOWN,&(MESS_SG_ECM10->TgtgearDown), (uint8)sizeof(MESS_SG_ECM10->TgtgearDown));

	// if(ret == COMEX_UPDATE_RECEIVED)
	// {
	// 	ret = 0U;
	// }
	(void)memset(MESS_SG_ECM10, 0, sizeof(GR_CFG_ECM10));
#elif (defined(SWC_GEAR_ADAPT_P03))
	(void)memset(MESS_SG_ECM10, 0, sizeof(GR_CFG_ECM10));		/* None */
#elif (defined(SWC_GEAR_ADAPT_A07))
	(void)memset(MESS_SG_ECM10, 0, sizeof(GR_CFG_ECM10));		/* None */
#elif (defined(SWC_GEAR_ADAPT_D01))
	(void)memset(MESS_SG_ECM10, 0, sizeof(GR_CFG_ECM10));		/* None */
#elif (defined(SWC_GEAR_ADAPT_D02))
	(void)memset(MESS_SG_ECM10, 0, sizeof(GR_CFG_ECM10));		/* None */
#elif (defined(SWC_GEAR_ADAPT_D03))
	(void)memset(MESS_SG_ECM10, 0, sizeof(GR_CFG_ECM10));		/* None */
#elif (defined(SWC_GEAR_ADAPT_P02))
	(void)memset(MESS_SG_ECM10, 0, sizeof(GR_CFG_ECM10));		/* None */
#elif (defined(SWC_GEAR_ADAPT_P01))
	(void)memset(MESS_SG_ECM10, 0, sizeof(GR_CFG_ECM10));		/* None */
#endif
	return ret;
}

void GearMdl_Adapt_E2EPW_AllReadInit(void)
{

#if ((defined(SWC_GEAR_ADAPT_B03)))
	E2EPW_ReadInit_SG_DCT7_SG_DCT7();
	E2EPW_ReadInit_SG_HCU_HP5_SG_HCU_HP5();
#else
	// do nothing
#endif

}

#define Common_GateWay_STOP_SEC_CODE
#include "Common_Safety_MemMap.h"

