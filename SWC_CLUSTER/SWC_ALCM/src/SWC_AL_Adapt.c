
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
*File Name   : SWC_AL_Adapt.c                                                                             *
*                                                                                                         *
*Description :                                                                                            *
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
#include "Dio.h"
#include "Com.h"
#include "IoHwAb_Cfg_RI.h"
#include <string.h>
#include "SWC_AL_Adapt.h"
#include "SWC_IPC_Interface.h"

#define Common_GateWay_START_SEC_VAR_INIT_UNSPECIFIED
#include  "Common_GateWay_MemMap.h"


#define Common_GateWay_STOP_SEC_VAR_INIT_UNSPECIFIED
#include  "Common_GateWay_MemMap.h"


#define Common_GateWay_START_SEC_CODE
#include  "Common_GateWay_MemMap.h"


uint8 FALCM_Adapt_GetVconfig(uint32 CfgID)
{
	VconfigKind_Allbuffers configAdr;
	(void)Rte_Read_Vconfig_GetKindBuffers_AllKinds(configAdr);
	return configAdr[CfgID];
}

uint8 FALCM_Adapt_GetPowerMode_State(void)
{
	SystemState_RecordType Power_State;
	uint8 u8PowerMode = 0;

	(void)memcpy(&Power_State,Rte_IRead_Common_GateWay_5msMainFunction_rpSR_SWCGateWay_Power_Out_SystemStateOut(),sizeof(SystemState_RecordType));
	u8PowerMode = Power_State.ClusterState;

	return u8PowerMode;
}

void FALCM_Adapt_Get_Direction(uint8 *data)
{
	*data = 1;
}


uint8 FALCM_Adapt_GetSig_AEB_VehTrig(uint8 * data)
{
	uint8 result = RTE_E_INVALID;

#if(ALCM_RSIG_AEB_VEHTRIG == ALCM_COMEX)
    uint8 SigValue = 0;
    result = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHTRIG,&SigValue,(uint8)sizeof(SigValue));
    (*data) = SigValue;
#elif (ALCM_RSIG_AEB_VEHTRIG == ALCM_AUTOSAR)
    /* reserved */
#else
    /* Without This Feature */
#endif
	return result;
}


uint8 FALCM_Adapt_GetSig_AEB_PedTrig(uint8 * data)
{
	uint8 result = RTE_E_INVALID;

#if(ALCM_RSIG_AEB_PEDTRIG == ALCM_COMEX)
    uint8 SigValue = 0;
    result = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDTRIG,&SigValue,(uint8)sizeof(SigValue));
    (*data) = SigValue;
#elif (ALCM_RSIG_AEB_PEDTRIG == ALCM_AUTOSAR)
    /* reserved */
#else
    /* Without This Feature */
#endif
	return result;
}


uint8 FALCM_Adapt_GetSig_AEB_JA_Warn(uint8 * data)
{
	uint8 result = RTE_E_INVALID;

#if(ALCM_RSIG_AEB_JA_WARN == ALCM_COMEX)
    uint8 SigValue = 0;
    result = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JA_WARN,&SigValue,(uint8)sizeof(SigValue));
    (*data) = SigValue;
#elif (ALCM_RSIG_AEB_JA_WARN == ALCM_AUTOSAR)
    /* reserved */
#else
    /* Without This Feature */
#endif
	return result;
}


uint8 FALCM_Adapt_GetSig_AEB_JABrkTrig(uint8 * data)
{
	uint8 result = RTE_E_INVALID;

#if(ALCM_RSIG_AEB_JABRKTRIG == ALCM_COMEX)
    uint8 SigValue = 0;
    result = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JABRKTRIG,&SigValue,(uint8)sizeof(SigValue));
    (*data) = SigValue;
#elif (ALCM_RSIG_AEB_JABRKTRIG == ALCM_AUTOSAR)
    /* reserved */
#else
    /* Without This Feature */
#endif
	return result;
}


uint8 FALCM_Adapt_GetSig_FCW_Warn(uint8 * data)
{
	uint8 result = RTE_E_INVALID;

#if(ALCM_RSIG_FCW_WARN == ALCM_COMEX)
    uint8 SigValue = 0;
    result = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_WARN,&SigValue,(uint8)sizeof(SigValue));
    (*data) = SigValue;
#elif (ALCM_RSIG_FCW_WARN == ALCM_AUTOSAR)
    /* reserved */
#else
    /* Without This Feature */
#endif
	return result;
}


uint8 FALCM_Adapt_GetSig_FCTBTrig(uint8 * data)
{
	uint8 result = RTE_E_INVALID;

#if(ALCM_RSIG_FCTBTRIG == ALCM_COMEX)
    uint8 SigValue = 0;
    result = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTBTRIG,&SigValue,(uint8)sizeof(SigValue));
    (*data) = SigValue;
#elif (ALCM_RSIG_FCTBTRIG == ALCM_AUTOSAR)
    /* reserved */
#else
    /* Without This Feature */
#endif
	return result;
}


uint8 FALCM_Adapt_GetSig_FCTA_Warn(uint8 * data)
{
	uint8 result = RTE_E_INVALID;

#if(ALCM_RSIG_FCTA_WARN == ALCM_COMEX)
    uint8 SigValue = 0;
    result = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTA_WARN,&SigValue,(uint8)sizeof(SigValue));
    (*data) = SigValue;
#elif (ALCM_RSIG_FCTA_WARN == ALCM_AUTOSAR)
    /* reserved */
#else
    /* Without This Feature */
#endif
	return result;
}


uint8 FALCM_Adapt_GetSig_BSD_LCA_warningReqRight(uint8 * data)
{
	uint8 result = RTE_E_INVALID;

#if(ALCM_RSIG_LCA_WARNR == ALCM_COMEX)
    uint8 SigValue = 0;
    result = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQRIGHT,&SigValue,(uint8)sizeof(SigValue));
    (*data) = SigValue;
#elif (ALCM_RSIG_LCA_WARNR == ALCM_AUTOSAR)
    /* reserved */
#else
    /* Without This Feature */
#endif
	return result;
}


uint8 FALCM_Adapt_GetSig_BSD_LCA_warningReqleft(uint8 * data)
{
	uint8 result = RTE_E_INVALID;

#if(ALCM_RSIG_LCA_WARNL == ALCM_COMEX)
    uint8 SigValue = 0;
    result = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BSD_LCA_WARNINGREQLEFT,&SigValue,(uint8)sizeof(SigValue));
    (*data) = SigValue;
#elif (ALCM_RSIG_LCA_WARNL == ALCM_AUTOSAR)
    /* reserved */
#else
    /* Without This Feature */
#endif
	return result;
}


uint8 FALCM_Adapt_GetSig_DOW_warningReqRight(uint8 * data)
{
	uint8 result = RTE_E_INVALID;

#if(ALCM_RSIG_DOW_WARNR == ALCM_COMEX)
    uint8 SigValue = 0;
    result = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQRIGHT,&SigValue,(uint8)sizeof(SigValue));
    (*data) = SigValue;
#elif (ALCM_RSIG_DOW_WARNR == ALCM_AUTOSAR)
    /* reserved */
#else
    /* Without This Feature */
#endif
	return result;
}


uint8 FALCM_Adapt_GetSig_DOW_warningReqleft(uint8 * data)
{
	uint8 result = RTE_E_INVALID;

#if(ALCM_RSIG_DOW_WARNL == ALCM_COMEX)
    uint8 SigValue = 0;
    result = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DOW_WARNINGREQLEFT,&SigValue,(uint8)sizeof(SigValue));
    (*data) = SigValue;
#elif (ALCM_RSIG_DOW_WARNL == ALCM_AUTOSAR)
    /* reserved */
#else
    /* Without This Feature */
#endif
	return result;
}


uint8 FALCM_Adapt_GetSig_DrvDoorSts(uint8 * data)
{
	uint8 result = RTE_E_INVALID;

#if(ALCM_RSIG_DRVDOORSTS == ALCM_COMEX)
    uint8 SigValue = 0;
    result = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS,&SigValue,(uint8)sizeof(SigValue));
    (*data) = SigValue;
#elif (ALCM_RSIG_DRVDOORSTS == ALCM_AUTOSAR)
    /* reserved */
#else
    /* Without This Feature */
#endif
	return result;
}


uint8 FALCM_Adapt_GetSig_PassengerDoorSts(uint8 * data)
{
	uint8 result = RTE_E_INVALID;

#if(ALCM_RSIG_PASSENGERDOORSTS == ALCM_COMEX)
    uint8 SigValue = 0;
    result = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS,&SigValue,(uint8)sizeof(SigValue));
    (*data) = SigValue;
#elif (ALCM_RSIG_PASSENGERDOORSTS == ALCM_AUTOSAR)
    /* reserved */
#else
    /* Without This Feature */
#endif
	return result;
}


uint8 FALCM_Adapt_GetSig_LRDoorSts(uint8 * data)
{
	uint8 result = RTE_E_INVALID;

#if(ALCM_RSIG_LRDOORSTS == ALCM_COMEX)
    uint8 SigValue = 0;
    result = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS,&SigValue,(uint8)sizeof(SigValue));
    (*data) = SigValue;
#elif (ALCM_RSIG_LRDOORSTS == ALCM_AUTOSAR)
    /* reserved */
#else
    /* Without This Feature */
#endif
	return result;
}


uint8 FALCM_Adapt_GetSig_RRDoorSts(uint8 * data)
{
	uint8 result = RTE_E_INVALID;

#if(ALCM_RSIG_RRDOORSTS == ALCM_COMEX)
    uint8 SigValue = 0;
    result = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS,&SigValue,(uint8)sizeof(SigValue));
    (*data) = SigValue;
#elif (ALCM_RSIG_RRDOORSTS == ALCM_AUTOSAR)
    /* reserved */
#else
    /* Without This Feature */
#endif
	return result;
}


uint8 FALCM_Adapt_GetSig_ACDrvTemp_ATC(uint8 * data)
{
	uint8 result = RTE_E_INVALID;

#if(ALCM_RSIG_ACDRVTEMP == ALCM_COMEX)
    uint8 SigValue = 0;
    result = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACDRVTEMP_ATC,&SigValue,(uint8)sizeof(SigValue));
    (*data) = SigValue;
#elif (ALCM_RSIG_ACDRVTEMP == ALCM_AUTOSAR)
    /* reserved */
#else
    /* Without This Feature */
#endif
	return result;
}


uint8 FALCM_Adapt_GetSig_ACFrntPasstTemp_ATC(uint8 * data)
{
	uint8 result = RTE_E_INVALID;

#if(ALCM_RSIG_ACFRNTPASSTTEMP == ALCM_COMEX)
    uint8 SigValue = 0;
    result = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACFRNTPASSTTEMP_ATC,&SigValue,(uint8)sizeof(SigValue));
    (*data) = SigValue;
#elif (ALCM_RSIG_ACFRNTPASSTTEMP == ALCM_AUTOSAR)
    /* reserved */
#else
    /* Without This Feature */
#endif
	return result;
}


uint8 FALCM_Adapt_GetSig_L_PM25InDens(uint16 * data)
{
	uint8 result = RTE_E_INVALID;

#if(ALCM_RSIG_PM25INDENS == ALCM_COMEX)
    uint16 SigValue = 0;
    result = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_L_PM25INDENS,&SigValue,(uint8)sizeof(SigValue));
    (*data) = SigValue;
#elif (ALCM_RSIG_PM25INDENS == ALCM_AUTOSAR)
    /* reserved */
#else
    /* Without This Feature */
#endif
	return result;
}

void FALCM_Adapt_GetTxSig_PartitionSwt(uint8* data)
{

#if(ALCM_RTSIG_PARTITIONSWT == ALCM_IPCSIG)
    IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMPartitionSwt, data);
#else
    /* Without This Feature */
#endif
}
void FALCM_Adapt_GetTxSig_MasterSwt(uint8* data)
{

#if(ALCM_RTSIG_MASTERSWT == ALCM_IPCSIG)
    IPC_API_GetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_ALCMMasterSwt, data);
#else
    /* Without This Feature */
#endif
}

void FALCM_Adapt_SetSig_DrvDoorALCMFlashFreq(uint8 data)
{

#if(ALCM_SSIG_DRVDOORALCMFLASHFREQ == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_DrvDoorALCMFlashFreq, &data);
#elif (ALCM_SSIG_DRVDOORALCMFLASHFREQ == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_DRVDOORALCMFLASHFREQ == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDoorALCMFlashFreq, &data);
#else
    /* Without This Feature */
#endif

}


void FALCM_Adapt_SetSig_PassDoorALCMFlashFreq(uint8 data)
{

#if(ALCM_SSIG_PASSDOORALCMFLASHFREQ == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_PassDoorALCMFlashFreq, &data);
#elif (ALCM_SSIG_PASSDOORALCMFLASHFREQ == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_PASSDOORALCMFLASHFREQ == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassDoorALCMFlashFreq, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_LeftPanelALCMFlashFreq(uint8 data)
{

#if(ALCM_SSIG_LEFTPANELALCMFLASHFREQ == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_LeftPanelALCMFlashFreq, &data);
#elif (ALCM_SSIG_LEFTPANELALCMFLASHFREQ == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_LEFTPANELALCMFLASHFREQ == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LeftPanelALCMFlashFreq, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_RightPanelALCMFlashFreq(uint8 data)
{

#if(ALCM_SSIG_RIGHTPANELALCMFLASHFREQ == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_RightPanelALCMFlashFreq, &data);
#elif (ALCM_SSIG_RIGHTPANELALCMFLASHFREQ == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_RIGHTPANELALCMFLASHFREQ == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RightPanelALCMFlashFreq, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_LRDoorALCMFlashFreq(uint8 data)
{

#if(ALCM_SSIG_LRDOORALCMFLASHFREQ == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_LRDoorALCMFlashFreq, &data);
#elif (ALCM_SSIG_LRDOORALCMFLASHFREQ == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_LRDOORALCMFLASHFREQ == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LRDoorALCMFlashFreq, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_RRDoorALCMFlashFreq(uint8 data)
{

#if(ALCM_SSIG_RRDOORALCMFLASHFREQ == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_RRDoorALCMFlashFreq, &data);
#elif (ALCM_SSIG_RRDOORALCMFLASHFREQ == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_RRDOORALCMFLASHFREQ == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRDoorALCMFlashFreq, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_FootALCMFlashFreq(uint8 data)
{

#if(ALCM_SSIG_FOOTALCMFLASHFREQ == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_FootALCMFlashFreq, &data);
#elif (ALCM_SSIG_FOOTALCMFLASHFREQ == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_FOOTALCMFLASHFREQ == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FootALCMFlashFreq, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_DrvDoorALCMClrSet(uint8 data)
{

#if(ALCM_SSIG_DRVDOORALCMCLRSET == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_DrvDoorALCMClrSet, &data);
#elif (ALCM_SSIG_DRVDOORALCMCLRSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_DRVDOORALCMCLRSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDoorALCMClrSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_PassDoorALCMClrSet(uint8 data)
{

#if(ALCM_SSIG_PASSDOORALCMCLRSET == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_PassDoorALCMClrSet, &data);
#elif (ALCM_SSIG_PASSDOORALCMCLRSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_PASSDOORALCMCLRSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassDoorALCMClrSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_LeftPanelALCMClrSet(uint8 data)
{

#if(ALCM_SSIG_LEFTPANELALCMCLRSET == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_LeftPanelALCMClrSet, &data);
#elif (ALCM_SSIG_LEFTPANELALCMCLRSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_LEFTPANELALCMCLRSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LeftPanelALCMClrSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_RightPanelALCMClrSet(uint8 data)
{

#if(ALCM_SSIG_RIGHTPANELALCMCLRSET == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_RightPanelALCMClrSet, &data);
#elif (ALCM_SSIG_RIGHTPANELALCMCLRSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_RIGHTPANELALCMCLRSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RightPanelALCMClrSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_LRDoorALCMClrSet(uint8 data)
{

#if(ALCM_SSIG_LRDOORALCMCLRSET == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_LRDoorALCMClrSet, &data);
#elif (ALCM_SSIG_LRDOORALCMCLRSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_LRDOORALCMCLRSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LRDoorALCMClrSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_RRDoorALCMClrSet(uint8 data)
{

#if(ALCM_SSIG_RRDOORALCMCLRSET == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_RRDoorALCMClrSet, &data);
#elif (ALCM_SSIG_RRDOORALCMCLRSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_RRDOORALCMCLRSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRDoorALCMClrSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_FootALCMClrSet(uint8 data)
{

#if(ALCM_SSIG_FOOTALCMCLRSET == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_FootALCMClrSet, &data);
#elif (ALCM_SSIG_FOOTALCMCLRSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_FOOTALCMCLRSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FootALCMClrSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_DrvDoorALCMLightLvlSet(uint8 data)
{

#if(ALCM_SSIG_DRVDOORALCMLIGHTLVLSET == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_DrvDoorALCMLightLvlSet, &data);
#elif (ALCM_SSIG_DRVDOORALCMLIGHTLVLSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_DRVDOORALCMLIGHTLVLSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_DrvDoorALCMLightLvlSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_PassDoorALCMLightLvlSet(uint8 data)
{

#if(ALCM_SSIG_PASSDOORALCMLIGHTLVLSET == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_PassDoorALCMLightLvlSet, &data);
#elif (ALCM_SSIG_PASSDOORALCMLIGHTLVLSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_PASSDOORALCMLIGHTLVLSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_PassDoorALCMLightLvlSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_LeftPanelALCMLightLvlSet(uint8 data)
{

#if(ALCM_SSIG_LEFTPANELALCMLIGHTLVLSET == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_LeftPanelALCMLightLvlSet, &data);
#elif (ALCM_SSIG_LEFTPANELALCMLIGHTLVLSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_LEFTPANELALCMLIGHTLVLSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LeftPanelALCMLightLvlSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_RightPanelALCMLightLvlSet(uint8 data)
{

#if(ALCM_SSIG_RIGHTPANELALCMLIGHTLVLSET == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_RightPanelALCMLightLvlSet, &data);
#elif (ALCM_SSIG_RIGHTPANELALCMLIGHTLVLSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_RIGHTPANELALCMLIGHTLVLSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RightPanelALCMLightLvlSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_LRDoorALCMLightLvlSet(uint8 data)
{

#if(ALCM_SSIG_LRDOORALCMLIGHTLVLSET == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_LRDoorALCMLightLvlSet, &data);
#elif (ALCM_SSIG_LRDOORALCMLIGHTLVLSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_LRDOORALCMLIGHTLVLSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_LRDoorALCMLightLvlSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_RRDoorALCMLightLvlSet(uint8 data)
{

#if(ALCM_SSIG_RRDOORALCMLIGHTLVLSET == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_RRDoorALCMLightLvlSet, &data);
#elif (ALCM_SSIG_RRDOORALCMLIGHTLVLSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_RRDOORALCMLIGHTLVLSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_RRDoorALCMLightLvlSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSig_FootALCMLightLvlSet(uint8 data)
{

#if(ALCM_SSIG_FOOTALCMLIGHTLVLSET == ALCM_COMEX)
    (void)Rte_Call_CNA_SignalSet_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_FootALCMLightLvlSet, &data);
#elif (ALCM_SSIG_FOOTALCMLIGHTLVLSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_FOOTALCMLIGHTLVLSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignal((uint32)SWC_IPC_CAN_SIGNAL_FootALCMLightLvlSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_DrvDoorALCMFlashFreq(uint8 data)
{

#if(ALCM_SSIG_DRVDOORALCMFLASHFREQ == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_DrvDoorALCMFlashFreq, &data);
#elif (ALCM_SSIG_DRVDOORALCMFLASHFREQ == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_DRVDOORALCMFLASHFREQ == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_DrvDoorALCMFlashFreq, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_PassDoorALCMFlashFreq(uint8 data)
{

#if(ALCM_SSIG_PASSDOORALCMFLASHFREQ == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_PassDoorALCMFlashFreq, &data);
#elif (ALCM_SSIG_PASSDOORALCMFLASHFREQ == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_PASSDOORALCMFLASHFREQ == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_PassDoorALCMFlashFreq, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_LeftPanelALCMFlashFreq(uint8 data)
{

#if(ALCM_SSIG_LEFTPANELALCMFLASHFREQ == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_LeftPanelALCMFlashFreq, &data);
#elif (ALCM_SSIG_LEFTPANELALCMFLASHFREQ == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_LEFTPANELALCMFLASHFREQ == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_LeftPanelALCMFlashFreq, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_RightPanelALCMFlashFreq(uint8 data)
{

#if(ALCM_SSIG_RIGHTPANELALCMFLASHFREQ == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_RightPanelALCMFlashFreq, &data);
#elif (ALCM_SSIG_RIGHTPANELALCMFLASHFREQ == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_RIGHTPANELALCMFLASHFREQ == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_RightPanelALCMFlashFreq, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_LRDoorALCMFlashFreq(uint8 data)
{

#if(ALCM_SSIG_LRDOORALCMFLASHFREQ == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_LRDoorALCMFlashFreq, &data);
#elif (ALCM_SSIG_LRDOORALCMFLASHFREQ == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_LRDOORALCMFLASHFREQ == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_LRDoorALCMFlashFreq, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_RRDoorALCMFlashFreq(uint8 data)
{

#if(ALCM_SSIG_RRDOORALCMFLASHFREQ == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_RRDoorALCMFlashFreq, &data);
#elif (ALCM_SSIG_RRDOORALCMFLASHFREQ == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_RRDOORALCMFLASHFREQ == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_RRDoorALCMFlashFreq, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_FootALCMFlashFreq(uint8 data)
{

#if(ALCM_SSIG_FOOTALCMFLASHFREQ == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_FootALCMFlashFreq, &data);
#elif (ALCM_SSIG_FOOTALCMFLASHFREQ == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_FOOTALCMFLASHFREQ == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_FootALCMFlashFreq, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_DrvDoorALCMClrSet(uint8 data)
{

#if(ALCM_SSIG_DRVDOORALCMCLRSET == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_DrvDoorALCMClrSet, &data);
#elif (ALCM_SSIG_DRVDOORALCMCLRSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_DRVDOORALCMCLRSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_DrvDoorALCMClrSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_PassDoorALCMClrSet(uint8 data)
{

#if(ALCM_SSIG_PASSDOORALCMCLRSET == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_PassDoorALCMClrSet, &data);
#elif (ALCM_SSIG_PASSDOORALCMCLRSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_PASSDOORALCMCLRSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_PassDoorALCMClrSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_LeftPanelALCMClrSet(uint8 data)
{

#if(ALCM_SSIG_LEFTPANELALCMCLRSET == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_LeftPanelALCMClrSet, &data);
#elif (ALCM_SSIG_LEFTPANELALCMCLRSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_LEFTPANELALCMCLRSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_LeftPanelALCMClrSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_RightPanelALCMClrSet(uint8 data)
{

#if(ALCM_SSIG_RIGHTPANELALCMCLRSET == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_RightPanelALCMClrSet, &data);
#elif (ALCM_SSIG_RIGHTPANELALCMCLRSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_RIGHTPANELALCMCLRSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_RightPanelALCMClrSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_LRDoorALCMClrSet(uint8 data)
{

#if(ALCM_SSIG_LRDOORALCMCLRSET == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_LRDoorALCMClrSet, &data);
#elif (ALCM_SSIG_LRDOORALCMCLRSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_LRDOORALCMCLRSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_LRDoorALCMClrSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_RRDoorALCMClrSet(uint8 data)
{

#if(ALCM_SSIG_RRDOORALCMCLRSET == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_RRDoorALCMClrSet, &data);
#elif (ALCM_SSIG_RRDOORALCMCLRSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_RRDOORALCMCLRSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_RRDoorALCMClrSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_FootALCMClrSet(uint8 data)
{

#if(ALCM_SSIG_FOOTALCMCLRSET == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_FootALCMClrSet, &data);
#elif (ALCM_SSIG_FOOTALCMCLRSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_FOOTALCMCLRSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_FootALCMClrSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_DrvDoorALCMLightLvlSet(uint8 data)
{

#if(ALCM_SSIG_DRVDOORALCMLIGHTLVLSET == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_DrvDoorALCMLightLvlSet, &data);
#elif (ALCM_SSIG_DRVDOORALCMLIGHTLVLSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_DRVDOORALCMLIGHTLVLSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_DrvDoorALCMLightLvlSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_PassDoorALCMLightLvlSet(uint8 data)
{

#if(ALCM_SSIG_PASSDOORALCMLIGHTLVLSET == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_PassDoorALCMLightLvlSet, &data);
#elif (ALCM_SSIG_PASSDOORALCMLIGHTLVLSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_PASSDOORALCMLIGHTLVLSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_PassDoorALCMLightLvlSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_LeftPanelALCMLightLvlSet(uint8 data)
{

#if(ALCM_SSIG_LEFTPANELALCMLIGHTLVLSET == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_LeftPanelALCMLightLvlSet, &data);
#elif (ALCM_SSIG_LEFTPANELALCMLIGHTLVLSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_LEFTPANELALCMLIGHTLVLSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_LeftPanelALCMLightLvlSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_RightPanelALCMLightLvlSet(uint8 data)
{

#if(ALCM_SSIG_RIGHTPANELALCMLIGHTLVLSET == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_RightPanelALCMLightLvlSet, &data);
#elif (ALCM_SSIG_RIGHTPANELALCMLIGHTLVLSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_RIGHTPANELALCMLIGHTLVLSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_RightPanelALCMLightLvlSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_LRDoorALCMLightLvlSet(uint8 data)
{

#if(ALCM_SSIG_LRDOORALCMLIGHTLVLSET == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_LRDoorALCMLightLvlSet, &data);
#elif (ALCM_SSIG_LRDOORALCMLIGHTLVLSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_LRDOORALCMLIGHTLVLSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_LRDoorALCMLightLvlSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_RRDoorALCMLightLvlSet(uint8 data)
{

#if(ALCM_SSIG_RRDOORALCMLIGHTLVLSET == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_RRDoorALCMLightLvlSet, &data);
#elif (ALCM_SSIG_RRDOORALCMLIGHTLVLSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_RRDOORALCMLIGHTLVLSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_RRDoorALCMLightLvlSet, &data);
#else
    /* Without This Feature */
#endif
}


void FALCM_Adapt_SetSigBuffer_FootALCMLightLvlSet(uint8 data)
{

#if(ALCM_SSIG_FOOTALCMLIGHTLVLSET == ALCM_COMEX)
    (void)Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation((uint16)SWC_IPC_EVENT_CAN_SIGNAL_FootALCMLightLvlSet, &data);
#elif (ALCM_SSIG_FOOTALCMLIGHTLVLSET == ALCM_AUTOSAR)
    /* reserved */
#elif (ALCM_SSIG_FOOTALCMLIGHTLVLSET == ALCM_IPCSIG)
    IPC_API_SetTxCanSignalBuffer((uint32)SWC_IPC_CAN_SIGNAL_FootALCMLightLvlSet, &data);
#else
    /* Without This Feature */
#endif
}


#define Common_GateWay_STOP_SEC_CODE
#include  "Common_GateWay_MemMap.h"
