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
*File Name   : SWC_CA_Interface.c                                                                        *
*                                                                                                         *
*Description : CA module Interface C file.                                      		  *
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


#include "SWC_CA_Interface.h"
#include "SWC_CA_Config.h"

#include "SWC_IPC_Interface.h"
#include "IPC_ClusterApp.h"


#define SWC_CA_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_CA_MemMap.h"

static IPC_M2S_ClusterAppCANAdaptCSA3_244_t                   IpcSend_stCA_DATA_CSA3_244_Inf;
static IPC_M2S_ClusterAppCANAdaptEEM1_2A8_t                   IpcSend_stCA_DATA_EEM1_2A8_Inf;
static IPC_M2S_ClusterAppCANAdaptESP2_145_t                   IpcSend_stCA_DATA_ESP2_145_Inf;
static IPC_M2S_ClusterAppCANAdaptESP2_137_t                   IpcSend_stCA_DATA_ESP2_137_Inf;
static IPC_M2S_ClusterAppCANAdaptHUD1_325_t                   IpcSend_stCA_DATA_HUD1_325_Inf;
static IPC_M2S_ClusterAppCANAdaptECM3_371_t                   IpcSend_stCA_DATA_ECM3_371_Inf;
static IPC_M2S_ClusterAppCANAdaptCSA2_A1_t                    IpcSend_stCA_DATA_CSA2_A1_Inf;
static IPC_M2S_ClusterAppCANAdaptECM16_2D4_t                  IpcSend_stCA_DATA_ECM16_2D4_Inf;
static IPC_M2S_ClusterAppCANAdaptAC2_385_t                    IpcSend_stCA_DATA_AC2_385_Inf;
static IPC_M2S_ClusterAppCANAdaptECM_PT6_290_t                IpcSend_stCA_DATA_ECM_PT6_290_Inf;
static IPC_M2S_ClusterAppCANAdaptABM2_245_t                   IpcSend_stCA_DATA_ABM2_245_Inf;
static IPC_M2S_ClusterAppCANAdaptRSDS_FD1_16F_t               IpcSend_stCA_DATA_RSDS_FD1_16F_Inf;
static IPC_M2S_ClusterAppCANAdaptIFC_FD5_19F_t                IpcSend_stCA_DATA_IFC_FD5_19F_Inf;
static IPC_M2S_ClusterAppCANAdaptIFC_FD6_222_t                IpcSend_stCA_DATA_IFC_FD6_222_Inf;
static IPC_M2S_ClusterAppCANAdaptACC_FD2_2AB_t                IpcSend_stCA_DATA_ACC_FD2_2AB_Inf;
static IPC_M2S_ClusterAppCANAdaptIFC_FD2_23D_t                IpcSend_stCA_DATA_IFC_FD2_23D_Inf;
static IPC_M2S_ClusterAppCANAdaptAEB_FD2_227_t                IpcSend_stCA_DATA_AEB_FD2_227_Inf;
static IPC_M2S_ClusterAppCANAdaptCR_FD1_15E_t                 IpcSend_stCA_DATA_CR_FD1_15E_Inf;
static IPC_M2S_ClusterAppCANAdaptIFC_FD3_2CF_t                IpcSend_stCA_DATA_IFC_FD3_2CF_Inf;
static IPC_M2S_ClusterAppCANAdaptACC_FD3_2B4_t                IpcSend_stCA_DATA_ACC_FD3_2B4_Inf;
static IPC_M2S_ClusterAppCANAdaptBCM1_319_t                   IpcSend_stCA_DATA_BCM1_319_Inf;
static IPC_M2S_ClusterAppCANAdaptBCM3_345_t                   IpcSend_stCA_DATA_BCM3_345_Inf;
static IPC_M2S_ClusterAppCANAdaptT_Box_FD10_2F0_t             IpcSend_stCA_DATA_T_Box_FD10_2F0_Inf;
static IPC_M2S_ClusterAppCANAdaptECM24_350_t                  IpcSend_stCA_DATA_ECM24_350_Inf;
static IPC_M2S_ClusterAppCANAdaptBCM12_238_t                  IpcSend_stCA_DATA_BCM12_238_Inf;
static IPC_M2S_ClusterAppCANAdaptF_PBOX1_19B_t                IpcSend_stCA_DATA_F_PBOX1_19B_Inf;
static IPC_M2S_ClusterAppCANAdaptHCM_L2_304_t                 IpcSend_stCA_DATA_HCM_L2_304_Inf;


#define SWC_CA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_CA_MemMap.h"


#define SWC_CA_START_SEC_CODE
#include "SWC_CA_MemMap.h"


static void vCA_Interface_MsgTimeoutStatus_CSA3_244(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.CSA3_244_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_CSA3_244);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_EEM1_2A8(void)
{
	IpcSend_stCA_DATA_EEM1_2A8_Inf.u_EEM1_2A8EEM1_2A8_Inf_t.s_EEM1_2A8_Inf_t.EEM1_2A8_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_EEM1_2A8);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_ESP2_145(void)
{
	IpcSend_stCA_DATA_ESP2_145_Inf.u_ESP2_145ESP2_145_Inf_t.s_ESP2_145_Inf_t.ESP2_145_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_ESP2_145);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_ESP_FD2_137(void)
{
	IpcSend_stCA_DATA_ESP2_137_Inf.u_ESP2_137ESP2_137_Inf_t.s_ESP2_137_Inf_t.ESP2_137_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_ESP_FD2_137);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_HUD1_325(void)
{
	IpcSend_stCA_DATA_HUD1_325_Inf.u_HUD1_325HUD1_325_t.s_HUD1_325_t.HUD1_325_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_HUD1_325);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_ECM3_371(void)
{
	IpcSend_stCA_DATA_ECM3_371_Inf.u_ECM3_371ECM3_371_Inf_t.s_ECM3_371_Inf_t.ECM3_371_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_ECM3_371);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_CSA2_A1(void)
{
	IpcSend_stCA_DATA_CSA2_A1_Inf.u_CSA2_A1CSA2_A1_Inf_t.s_CSA2_A1_Inf_t.CSA2_A1_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_CSA2_A1);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_ECM16_2D4(void)
{
	IpcSend_stCA_DATA_ECM16_2D4_Inf.u_ECM16_2D4ECM16_2D4_Inf_t.s_ECM16_2D4_Inf_t.ECM16_2D4_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_ECM16_2D4);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_AC2_385(void)
{
	IpcSend_stCA_DATA_AC2_385_Inf.u_AC2_385AC2_385_Inf_t.s_AC2_385_Inf_t.AC2_385_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_AC2_385);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_ECM_PT6_290(void)
{
	IpcSend_stCA_DATA_ECM_PT6_290_Inf.u_ECM_PT6_290ECM_PT6_290_Inf_t.s_ECM_PT6_290_Inf_t.ECM_PT6_290_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_ECM_PT6_290);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_ABM2_245(void)
{
	IpcSend_stCA_DATA_ABM2_245_Inf.u_ABM2_245ABM2_245_Inf_t.s_ABM2_245_Inf_t.ABM2_245_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_ABM2_245);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_RSDS_FD1_16F(void)
{
	IpcSend_stCA_DATA_RSDS_FD1_16F_Inf.u_RSDS_FD1_16FRSDS_FD1_16F_Inf_t.s_RSDS_FD1_16F_Inf_t.RSDS_FD1_16F_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_RSDS_FD1_16F);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_IFC_FD5_19F(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.s_IFC_FD5_19F_Inf_1_t.IFC_FD5_19F_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_IFC_FD5_19F);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_IFC_FD6_222(void)
{
	IpcSend_stCA_DATA_IFC_FD6_222_Inf.u_IFC_FD6_222IFC_FD6_222_Inf_t.s_IFC_FD6_222_Inf_t.IFC_FD6_222_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_IFC_FD6_222);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_ACC_FD2_2AB(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.s_ACC_FD2_2AB_Inf_1_t.ACC_FD2_2AB_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_ACC_FD2_2AB);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_IFC_FD2_23D(void)
{
	IpcSend_stCA_DATA_IFC_FD2_23D_Inf.u_IFC_FD2_23DIFC_FD2_23D_Inf_t.s_IFC_FD2_23D_Inf_t.IFC_FD2_23D_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_IFC_FD2_23D);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_AEB_FD2_227(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_t.s_AEB_FD2_227_Inf_t.AEB_FD2_227_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_AEB_FD2_227);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_CR_FD1_15E(void)
{
	IpcSend_stCA_DATA_CR_FD1_15E_Inf.u_CR_FD1_15ECR_FD1_15E_Inf_t.s_CR_FD1_15E_Inf_t.CR_FD1_15E_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_CR_FD1_15E);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_IFC_FD3_2CF(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.IFC_FD3_2CF_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_IFC_FD3_2CF);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_ACC_FD3_2B4(void)
{
	IpcSend_stCA_DATA_ACC_FD3_2B4_Inf.u_ACC_FD3_2B4ACC_FD3_2B4_Inf_t.s_ACC_FD3_2B4_Inf_t.ACC_FD3_2B4_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_ACC_FD3_2B4);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_BCM1_319(void)
{
	IpcSend_stCA_DATA_BCM1_319_Inf.u_BCM1_319BCM1_319_Inf_t.s_BCM1_319_Inf_t.BCM1_319_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_BCM1_319);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_BCM3_345(void)
{
	IpcSend_stCA_DATA_BCM3_345_Inf.u_BCM3_345BCM3_345_Inf_t.s_BCM3_345_Inf_t.BCM3_345_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_BCM3_345);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_T_BOX_FD10_2F0(void)
{
	IpcSend_stCA_DATA_T_Box_FD10_2F0_Inf.u_T_Box_FD10_2F0T_Box_FD10_2F0_Inf_t.s_T_Box_FD10_2F0_Inf_t.T_Box_FD10_2F0_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_T_BOX_FD10_2F0);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_ECM24_350(void)
{
	IpcSend_stCA_DATA_ECM24_350_Inf.u_ECM24_350ECM24_350_Inf_t.s_ECM24_350_Inf_t.ECM24_350_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_ECM24_350);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_BCM12_238(void)
{
	IpcSend_stCA_DATA_BCM12_238_Inf.u_BCM12_238BCM12_238_Inf_t.s_BCM12_238_Inf_t.BCM12_238_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_BCM12_238);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_F_PBOX1_19B(void)
{
	IpcSend_stCA_DATA_F_PBOX1_19B_Inf.u_F_PBOX1_19BF_PBOX1_19B_Inf_t.s_F_PBOX1_19B_Inf_t.F_PBOX1_19B_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_F_PBOX1_19B);

	return ;
}



static void vCA_Interface_MsgTimeoutStatus_HCM_L2_304(void)
{
	IpcSend_stCA_DATA_HCM_L2_304_Inf.u_HCM_L2_304HCM_L2_304_Inf_t.s_HCM_L2_304_Inf_t.HCM_L2_304_MSG_TimeoutFlag = \
      (uint8)u32CA_Process_GetMsgTimeoutStatus(enCAMsgInd_HCM_L2_304);

	return ;
}



static void vCA_Interface_SignalStatus_PageUpSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.PageUpSwtSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_PageUpSwtSts);

	return ;
}



static void vCA_Interface_SignalValue_PageUpSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.PageUpSwtSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_PageUpSwtSts);

	return ;
}



static void vCA_Interface_SignalStatus_PageDwnSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.PageDwnSwtSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_PageDwnSwtSts);

	return ;
}



static void vCA_Interface_SignalValue_PageDwnSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.PageDwnSwtSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_PageDwnSwtSts);

	return ;
}



static void vCA_Interface_SignalStatus_PageLSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.PageLSwtSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_PageLSwtSts);

	return ;
}



static void vCA_Interface_SignalValue_PageLSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.PageLSwtSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_PageLSwtSts);

	return ;
}



static void vCA_Interface_SignalStatus_PageRSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.PageRSwtSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_PageRSwtSts);

	return ;
}



static void vCA_Interface_SignalValue_PageRSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.PageRSwtSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_PageRSwtSts);

	return ;
}



static void vCA_Interface_SignalStatus_EnterSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.EnterSwtSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_EnterSwtSts);

	return ;
}



static void vCA_Interface_SignalValue_EnterSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.EnterSwtSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_EnterSwtSts);

	return ;
}



static void vCA_Interface_SignalStatus_HomeSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.HomeSwtSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_HomeSwtSts);

	return ;
}



static void vCA_Interface_SignalValue_HomeSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.HomeSwtSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_HomeSwtSts);

	return ;
}



static void vCA_Interface_SignalStatus_MenuReturnSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.MenuReturnSwtSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_MenuReturnSwtSts);

	return ;
}



static void vCA_Interface_SignalValue_MenuReturnSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.MenuReturnSwtSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_MenuReturnSwtSts);

	return ;
}



static void vCA_Interface_SignalStatus_CustomSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.CustomSwtSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_CustomSwtSts);

	return ;
}



static void vCA_Interface_SignalValue_CustomSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.CustomSwtSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_CustomSwtSts);

	return ;
}



static void vCA_Interface_SignalStatus_IpMenuSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.IpMenuSwtSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IpMenuSwtSts);

	return ;
}



static void vCA_Interface_SignalValue_IpMenuSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_t.s_CSA3_244_Inf_t.IpMenuSwtSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_IpMenuSwtSts);

	return ;
}



static void vCA_Interface_SignalStatus_AdjVolDwnSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_1_t.s_CSA3_244_Inf_1_t.AdjVolDwnSwtSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_AdjVolDwnSwtSts);

	return ;
}



static void vCA_Interface_SignalValue_AdjVolDwnSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_1_t.s_CSA3_244_Inf_1_t.AdjVolDwnSwtSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_AdjVolDwnSwtSts);

	return ;
}



static void vCA_Interface_SignalStatus_AdjVolUpSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_1_t.s_CSA3_244_Inf_1_t.AdjVolUpSwtSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_AdjVolUpSwtSts);

	return ;
}



static void vCA_Interface_SignalValue_AdjVolUpSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_1_t.s_CSA3_244_Inf_1_t.AdjVolUpSwtSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_AdjVolUpSwtSts);

	return ;
}



static void vCA_Interface_SignalStatus_SeekDwnSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_1_t.s_CSA3_244_Inf_1_t.SeekDwnSwtSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_SeekDwnSwtSts);

	return ;
}



static void vCA_Interface_SignalValue_SeekDwnSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_1_t.s_CSA3_244_Inf_1_t.SeekDwnSwtSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_SeekDwnSwtSts);

	return ;
}



static void vCA_Interface_SignalStatus_SeekUpSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_1_t.s_CSA3_244_Inf_1_t.SeekUpSwtSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_SeekUpSwtSts);

	return ;
}



static void vCA_Interface_SignalValue_SeekUpSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_1_t.s_CSA3_244_Inf_1_t.SeekUpSwtSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_SeekUpSwtSts);

	return ;
}



static void vCA_Interface_SignalStatus_EnterSwtSts_Mmed(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_1_t.s_CSA3_244_Inf_1_t.EnterSwtSts_Mmed_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_EnterSwtSts_Mmed);

	return ;
}



static void vCA_Interface_SignalValue_EnterSwtSts_Mmed(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_1_t.s_CSA3_244_Inf_1_t.EnterSwtSts_Mmed = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_EnterSwtSts_Mmed);

	return ;
}



static void vCA_Interface_SignalStatus_VRSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_1_t.s_CSA3_244_Inf_1_t.VRSwtSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_VRSwtSts);

	return ;
}



static void vCA_Interface_SignalValue_VRSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_1_t.s_CSA3_244_Inf_1_t.VRSwtSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_VRSwtSts);

	return ;
}



static void vCA_Interface_SignalStatus_MuteSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_1_t.s_CSA3_244_Inf_1_t.MuteSwtSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_MuteSwtSts);

	return ;
}



static void vCA_Interface_SignalValue_MuteSwtSts(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_1_t.s_CSA3_244_Inf_1_t.MuteSwtSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_MuteSwtSts);

	return ;
}



static void vCA_Interface_SignalStatus_CustomSwtSts_Mmed(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_1_t.s_CSA3_244_Inf_1_t.CustomSwtSts_Mmed_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_CustomSwtSts_Mmed);

	return ;
}



static void vCA_Interface_SignalValue_CustomSwtSts_Mmed(void)
{
	IpcSend_stCA_DATA_CSA3_244_Inf.u_CSA3_244CSA3_244_Inf_1_t.s_CSA3_244_Inf_1_t.CustomSwtSts_Mmed = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_CustomSwtSts_Mmed);

	return ;
}



static void vCA_Interface_SignalStatus_Stat_PwrSv_Lvl(void)
{
	IpcSend_stCA_DATA_EEM1_2A8_Inf.u_EEM1_2A8EEM1_2A8_Inf_t.s_EEM1_2A8_Inf_t.Stat_PwrSv_Lvl_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_Stat_PwrSv_Lvl);

	return ;
}



static void vCA_Interface_SignalValue_Stat_PwrSv_Lvl(void)
{
	IpcSend_stCA_DATA_EEM1_2A8_Inf.u_EEM1_2A8EEM1_2A8_Inf_t.s_EEM1_2A8_Inf_t.Stat_PwrSv_Lvl = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_Stat_PwrSv_Lvl);

	return ;
}



static void vCA_Interface_SignalStatus_DrivingModDis_145(void)
{
	IpcSend_stCA_DATA_ESP2_145_Inf.u_ESP2_145ESP2_145_Inf_t.s_ESP2_145_Inf_t.DrivingModDis_145_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_DrivingModDis_0x145);

	return ;
}



static void vCA_Interface_SignalValue_DrivingModDis_145(void)
{
	IpcSend_stCA_DATA_ESP2_145_Inf.u_ESP2_145ESP2_145_Inf_t.s_ESP2_145_Inf_t.DrivingModDis_145 = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_DrivingModDis_0x145);

	return ;
}



static void vCA_Interface_SignalStatus_DrivingModDis_137(void)
{
	IpcSend_stCA_DATA_ESP2_137_Inf.u_ESP2_137ESP2_137_Inf_t.s_ESP2_137_Inf_t.DrivingModDis_137_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_DrivingModDis_0x137);

	return ;
}



static void vCA_Interface_SignalValue_DrivingModDis_137(void)
{
	IpcSend_stCA_DATA_ESP2_137_Inf.u_ESP2_137ESP2_137_Inf_t.s_ESP2_137_Inf_t.DrivingModDis_137 = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_DrivingModDis_0x137);

	return ;
}



static void vCA_Interface_SignalStatus_ESPBrkLmpCtrl_137(void)
{
	IpcSend_stCA_DATA_ESP2_137_Inf.u_ESP2_137ESP2_137_Inf_t.s_ESP2_137_Inf_t.ESPBrkLmpCtrl_137_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ESPBrkLmpCtrl_0x137);

	return ;
}



static void vCA_Interface_SignalValue_ESPBrkLmpCtrl_137(void)
{
	IpcSend_stCA_DATA_ESP2_137_Inf.u_ESP2_137ESP2_137_Inf_t.s_ESP2_137_Inf_t.ESPBrkLmpCtrl_137 = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ESPBrkLmpCtrl_0x137);

	return ;
}



static void vCA_Interface_SignalStatus_HUD_BrightnessLvl(void)
{
	IpcSend_stCA_DATA_HUD1_325_Inf.u_HUD1_325HUD1_325_t.s_HUD1_325_t.HUD_BrightnessLvl_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_HUD_BrightnessLvl);

	return ;
}



static void vCA_Interface_SignalValue_HUD_BrightnessLvl(void)
{
	IpcSend_stCA_DATA_HUD1_325_Inf.u_HUD1_325HUD1_325_t.s_HUD1_325_t.HUD_BrightnessLvl = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_HUD_BrightnessLvl);

	return ;
}



static void vCA_Interface_SignalStatus_HUD_HeightLvl(void)
{
	IpcSend_stCA_DATA_HUD1_325_Inf.u_HUD1_325HUD1_325_t.s_HUD1_325_t.HUD_HeightLvl_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_HUD_HeightLvl);

	return ;
}



static void vCA_Interface_SignalValue_HUD_HeightLvl(void)
{
	IpcSend_stCA_DATA_HUD1_325_Inf.u_HUD1_325HUD1_325_t.s_HUD1_325_t.HUD_HeightLvl = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_HUD_HeightLvl);

	return ;
}



static void vCA_Interface_SignalStatus_HUD_UIMod(void)
{
	IpcSend_stCA_DATA_HUD1_325_Inf.u_HUD1_325HUD1_325_t.s_HUD1_325_t.HUD_UIMod_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_HUD_UIMod);

	return ;
}



static void vCA_Interface_SignalValue_HUD_UIMod(void)
{
	IpcSend_stCA_DATA_HUD1_325_Inf.u_HUD1_325HUD1_325_t.s_HUD1_325_t.HUD_UIMod = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_HUD_UIMod);

	return ;
}



static void vCA_Interface_SignalStatus_HUD_UIModVld(void)
{
	IpcSend_stCA_DATA_HUD1_325_Inf.u_HUD1_325HUD1_325_t.s_HUD1_325_t.HUD_UIModVld_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_HUD_UIModVld);

	return ;
}



static void vCA_Interface_SignalValue_HUD_UIModVld(void)
{
	IpcSend_stCA_DATA_HUD1_325_Inf.u_HUD1_325HUD1_325_t.s_HUD1_325_t.HUD_UIModVld = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_HUD_UIModVld);

	return ;
}



static void vCA_Interface_SignalStatus_HUD_SwtSts(void)
{
	IpcSend_stCA_DATA_HUD1_325_Inf.u_HUD1_325HUD1_325_t.s_HUD1_325_t.HUD_SwtSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_HUD_SwtSts);

	return ;
}



static void vCA_Interface_SignalValue_HUD_SwtSts(void)
{
	IpcSend_stCA_DATA_HUD1_325_Inf.u_HUD1_325HUD1_325_t.s_HUD1_325_t.HUD_SwtSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_HUD_SwtSts);

	return ;
}



static void vCA_Interface_SignalStatus_BaroPressure(void)
{
	IpcSend_stCA_DATA_ECM3_371_Inf.u_ECM3_371ECM3_371_Inf_t.s_ECM3_371_Inf_t.BaroPressure_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_BaroPressure);

	return ;
}



static void vCA_Interface_SignalValue_BaroPressure(void)
{
	IpcSend_stCA_DATA_ECM3_371_Inf.u_ECM3_371ECM3_371_Inf_t.s_ECM3_371_Inf_t.BaroPressure = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_BaroPressure);

	return ;
}



static void vCA_Interface_SignalStatus_SAS_Sts(void)
{
	IpcSend_stCA_DATA_CSA2_A1_Inf.u_CSA2_A1CSA2_A1_Inf_t.s_CSA2_A1_Inf_t.SAS_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_SAS_Sts);

	return ;
}



static void vCA_Interface_SignalValue_SAS_Sts(void)
{
	IpcSend_stCA_DATA_CSA2_A1_Inf.u_CSA2_A1CSA2_A1_Inf_t.s_CSA2_A1_Inf_t.SAS_Sts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_SAS_Sts);

	return ;
}



static void vCA_Interface_SignalStatus_SteerWheelAngSign(void)
{
	IpcSend_stCA_DATA_CSA2_A1_Inf.u_CSA2_A1CSA2_A1_Inf_t.s_CSA2_A1_Inf_t.SteerWheelAngSign_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_SteerWheelAngSign);

	return ;
}



static void vCA_Interface_SignalValue_SteerWheelAngSign(void)
{
	IpcSend_stCA_DATA_CSA2_A1_Inf.u_CSA2_A1CSA2_A1_Inf_t.s_CSA2_A1_Inf_t.SteerWheelAngSign = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_SteerWheelAngSign);

	return ;
}



static void vCA_Interface_SignalStatus_SteerWheelAng(void)
{
	IpcSend_stCA_DATA_CSA2_A1_Inf.u_CSA2_A1CSA2_A1_Inf_t.s_CSA2_A1_Inf_t.SteerWheelAng_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_SteerWheelAng);

	return ;
}



static void vCA_Interface_SignalValue_SteerWheelAng(void)
{
	IpcSend_stCA_DATA_CSA2_A1_Inf.u_CSA2_A1CSA2_A1_Inf_t.s_CSA2_A1_Inf_t.SteerWheelAng = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_SteerWheelAng);

	return ;
}



static void vCA_Interface_SignalStatus_Urea_Level(void)
{
	IpcSend_stCA_DATA_ECM16_2D4_Inf.u_ECM16_2D4ECM16_2D4_Inf_t.s_ECM16_2D4_Inf_t.Urea_Level_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_Urea_Level);

	return ;
}



static void vCA_Interface_SignalValue_Urea_Level(void)
{
	IpcSend_stCA_DATA_ECM16_2D4_Inf.u_ECM16_2D4ECM16_2D4_Inf_t.s_ECM16_2D4_Inf_t.Urea_Level = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_Urea_Level);

	return ;
}



static void vCA_Interface_SignalStatus_SCRSysWarnDisplay(void)
{
	IpcSend_stCA_DATA_ECM16_2D4_Inf.u_ECM16_2D4ECM16_2D4_Inf_t.s_ECM16_2D4_Inf_t.SCRSysWarnDisplay_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_SCRSysWarnDisplay);

	return ;
}



static void vCA_Interface_SignalValue_SCRSysWarnDisplay(void)
{
	IpcSend_stCA_DATA_ECM16_2D4_Inf.u_ECM16_2D4ECM16_2D4_Inf_t.s_ECM16_2D4_Inf_t.SCRSysWarnDisplay = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_SCRSysWarnDisplay);

	return ;
}



static void vCA_Interface_SignalStatus_SCRSysWarnDisplay_B2(void)
{
	IpcSend_stCA_DATA_ECM16_2D4_Inf.u_ECM16_2D4ECM16_2D4_Inf_t.s_ECM16_2D4_Inf_t.SCRSysWarnDisplay_B2_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_SCRSysWarnDisplay_B2);

	return ;
}



static void vCA_Interface_SignalValue_SCRSysWarnDisplay_B2(void)
{
	IpcSend_stCA_DATA_ECM16_2D4_Inf.u_ECM16_2D4ECM16_2D4_Inf_t.s_ECM16_2D4_Inf_t.SCRSysWarnDisplay_B2 = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_SCRSysWarnDisplay_B2);

	return ;
}



static void vCA_Interface_SignalStatus_UreaRemainDist(void)
{
	IpcSend_stCA_DATA_ECM16_2D4_Inf.u_ECM16_2D4ECM16_2D4_Inf_t.s_ECM16_2D4_Inf_t.UreaRemainDist_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_UreaRemainDist);

	return ;
}



static void vCA_Interface_SignalValue_UreaRemainDist(void)
{
	IpcSend_stCA_DATA_ECM16_2D4_Inf.u_ECM16_2D4ECM16_2D4_Inf_t.s_ECM16_2D4_Inf_t.UreaRemainDist = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_UreaRemainDist);

	return ;
}



static void vCA_Interface_SignalStatus_ACAmbTemp(void)
{
	IpcSend_stCA_DATA_AC2_385_Inf.u_AC2_385AC2_385_Inf_t.s_AC2_385_Inf_t.ACAmbTemp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACAmbTemp);

	return ;
}



static void vCA_Interface_SignalValue_ACAmbTemp(void)
{
	IpcSend_stCA_DATA_AC2_385_Inf.u_AC2_385AC2_385_Inf_t.s_AC2_385_Inf_t.ACAmbTemp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACAmbTemp);

	return ;
}



static void vCA_Interface_SignalStatus_TrqPrct(void)
{
	IpcSend_stCA_DATA_ECM_PT6_290_Inf.u_ECM_PT6_290ECM_PT6_290_Inf_t.s_ECM_PT6_290_Inf_t.TrqPrct_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_TrqPrct);

	return ;
}



static void vCA_Interface_SignalValue_TrqPrct(void)
{
	IpcSend_stCA_DATA_ECM_PT6_290_Inf.u_ECM_PT6_290ECM_PT6_290_Inf_t.s_ECM_PT6_290_Inf_t.TrqPrct = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_TrqPrct);

	return ;
}



static void vCA_Interface_SignalStatus_PowerPrct(void)
{
	IpcSend_stCA_DATA_ECM_PT6_290_Inf.u_ECM_PT6_290ECM_PT6_290_Inf_t.s_ECM_PT6_290_Inf_t.PowerPrct_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_PowerPrct);

	return ;
}



static void vCA_Interface_SignalValue_PowerPrct(void)
{
	IpcSend_stCA_DATA_ECM_PT6_290_Inf.u_ECM_PT6_290ECM_PT6_290_Inf_t.s_ECM_PT6_290_Inf_t.PowerPrct = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_PowerPrct);

	return ;
}



static void vCA_Interface_SignalStatus_VehLgtAccelVld(void)
{
	IpcSend_stCA_DATA_ABM2_245_Inf.u_ABM2_245ABM2_245_Inf_t.s_ABM2_245_Inf_t.VehLgtAccelVld_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_VehLgtAccelVld);

	return ;
}



static void vCA_Interface_SignalValue_VehLgtAccelVld(void)
{
	IpcSend_stCA_DATA_ABM2_245_Inf.u_ABM2_245ABM2_245_Inf_t.s_ABM2_245_Inf_t.VehLgtAccelVld = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_VehLgtAccelVld);

	return ;
}



static void vCA_Interface_SignalStatus_VehLatAccelVld(void)
{
	IpcSend_stCA_DATA_ABM2_245_Inf.u_ABM2_245ABM2_245_Inf_t.s_ABM2_245_Inf_t.VehLatAccelVld_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_VehLatAccelVld);

	return ;
}



static void vCA_Interface_SignalValue_VehLatAccelVld(void)
{
	IpcSend_stCA_DATA_ABM2_245_Inf.u_ABM2_245ABM2_245_Inf_t.s_ABM2_245_Inf_t.VehLatAccelVld = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_VehLatAccelVld);

	return ;
}



static void vCA_Interface_SignalStatus_VehLgtAccel(void)
{
	IpcSend_stCA_DATA_ABM2_245_Inf.u_ABM2_245ABM2_245_Inf_t.s_ABM2_245_Inf_t.VehLgtAccel_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_VehLgtAccel);

	return ;
}



static void vCA_Interface_SignalValue_VehLgtAccel(void)
{
	IpcSend_stCA_DATA_ABM2_245_Inf.u_ABM2_245ABM2_245_Inf_t.s_ABM2_245_Inf_t.VehLgtAccel = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_VehLgtAccel);

	return ;
}



static void vCA_Interface_SignalStatus_VehLatAccel(void)
{
	IpcSend_stCA_DATA_ABM2_245_Inf.u_ABM2_245ABM2_245_Inf_t.s_ABM2_245_Inf_t.VehLatAccel_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_VehLatAccel);

	return ;
}



static void vCA_Interface_SignalValue_VehLatAccel(void)
{
	IpcSend_stCA_DATA_ABM2_245_Inf.u_ABM2_245ABM2_245_Inf_t.s_ABM2_245_Inf_t.VehLatAccel = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_VehLatAccel);

	return ;
}



static void vCA_Interface_SignalStatus_BSD_LCA_warningReqRight(void)
{
	IpcSend_stCA_DATA_RSDS_FD1_16F_Inf.u_RSDS_FD1_16FRSDS_FD1_16F_Inf_t.s_RSDS_FD1_16F_Inf_t.BSD_LCA_warningReqRight_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_BSD_LCA_warningReqRight);

	return ;
}



static void vCA_Interface_SignalValue_BSD_LCA_warningReqRight(void)
{
	IpcSend_stCA_DATA_RSDS_FD1_16F_Inf.u_RSDS_FD1_16FRSDS_FD1_16F_Inf_t.s_RSDS_FD1_16F_Inf_t.BSD_LCA_warningReqRight = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_BSD_LCA_warningReqRight);

	return ;
}



static void vCA_Interface_SignalStatus_BSD_LCA_warningReqleft(void)
{
	IpcSend_stCA_DATA_RSDS_FD1_16F_Inf.u_RSDS_FD1_16FRSDS_FD1_16F_Inf_t.s_RSDS_FD1_16F_Inf_t.BSD_LCA_warningReqleft_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_BSD_LCA_warningReqleft);

	return ;
}



static void vCA_Interface_SignalValue_BSD_LCA_warningReqleft(void)
{
	IpcSend_stCA_DATA_RSDS_FD1_16F_Inf.u_RSDS_FD1_16FRSDS_FD1_16F_Inf_t.s_RSDS_FD1_16F_Inf_t.BSD_LCA_warningReqleft = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_BSD_LCA_warningReqleft);

	return ;
}



static void vCA_Interface_SignalStatus_DOW_warningReqRight(void)
{
	IpcSend_stCA_DATA_RSDS_FD1_16F_Inf.u_RSDS_FD1_16FRSDS_FD1_16F_Inf_t.s_RSDS_FD1_16F_Inf_t.DOW_warningReqRight_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_DOW_warningReqRight);

	return ;
}



static void vCA_Interface_SignalValue_DOW_warningReqRight(void)
{
	IpcSend_stCA_DATA_RSDS_FD1_16F_Inf.u_RSDS_FD1_16FRSDS_FD1_16F_Inf_t.s_RSDS_FD1_16F_Inf_t.DOW_warningReqRight = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_DOW_warningReqRight);

	return ;
}



static void vCA_Interface_SignalStatus_DOW_warningReqleft(void)
{
	IpcSend_stCA_DATA_RSDS_FD1_16F_Inf.u_RSDS_FD1_16FRSDS_FD1_16F_Inf_t.s_RSDS_FD1_16F_Inf_t.DOW_warningReqleft_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_DOW_warningReqleft);

	return ;
}



static void vCA_Interface_SignalValue_DOW_warningReqleft(void)
{
	IpcSend_stCA_DATA_RSDS_FD1_16F_Inf.u_RSDS_FD1_16FRSDS_FD1_16F_Inf_t.s_RSDS_FD1_16F_Inf_t.DOW_warningReqleft = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_DOW_warningReqleft);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line01_Type(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.s_IFC_FD5_19F_Inf_1_t.IFC_Line01_Type_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line01_Type);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line01_Type(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.s_IFC_FD5_19F_Inf_1_t.IFC_Line01_Type = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line01_Type);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line02_Type(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.s_IFC_FD5_19F_Inf_1_t.IFC_Line02_Type_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line02_Type);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line02_Type(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.s_IFC_FD5_19F_Inf_1_t.IFC_Line02_Type = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line02_Type);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line03_Type(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.s_IFC_FD5_19F_Inf_1_t.IFC_Line03_Type_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line03_Type);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line03_Type(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.s_IFC_FD5_19F_Inf_1_t.IFC_Line03_Type = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line03_Type);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line04_Type(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.s_IFC_FD5_19F_Inf_1_t.IFC_Line04_Type_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line04_Type);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line04_Type(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.s_IFC_FD5_19F_Inf_1_t.IFC_Line04_Type = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line04_Type);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Roadedge01_Type(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.s_IFC_FD5_19F_Inf_1_t.IFC_Roadedge01_Type_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Roadedge01_Type);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Roadedge01_Type(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.s_IFC_FD5_19F_Inf_1_t.IFC_Roadedge01_Type = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Roadedge01_Type);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Roadedge02_Type(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.s_IFC_FD5_19F_Inf_1_t.IFC_Roadedge02_Type_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Roadedge02_Type);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Roadedge02_Type(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t.s_IFC_FD5_19F_Inf_1_t.IFC_Roadedge02_Type = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Roadedge02_Type);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line01_Dy(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_2_t.s_IFC_FD5_19F_Inf_2_t.IFC_Line01_Dy_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line01_Dy);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line01_Dy(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_2_t.s_IFC_FD5_19F_Inf_2_t.IFC_Line01_Dy = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line01_Dy);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line01_Curv(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_2_t.s_IFC_FD5_19F_Inf_2_t.IFC_Line01_Curv_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line01_Curv);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line01_Curv(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_2_t.s_IFC_FD5_19F_Inf_2_t.IFC_Line01_Curv = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line01_Curv);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line02_Dy(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_3_t.s_IFC_FD5_19F_Inf_3_t.IFC_Line02_Dy_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line02_Dy);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line02_Dy(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_3_t.s_IFC_FD5_19F_Inf_3_t.IFC_Line02_Dy = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line02_Dy);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line02_Curv(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_3_t.s_IFC_FD5_19F_Inf_3_t.IFC_Line02_Curv_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line02_Curv);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line02_Curv(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_3_t.s_IFC_FD5_19F_Inf_3_t.IFC_Line02_Curv = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line02_Curv);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line03_Dy(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_4_t.s_IFC_FD5_19F_Inf_4_t.IFC_Line03_Dy_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line03_Dy);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line03_Dy(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_4_t.s_IFC_FD5_19F_Inf_4_t.IFC_Line03_Dy = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line03_Dy);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line03_Curv(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_4_t.s_IFC_FD5_19F_Inf_4_t.IFC_Line03_Curv_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line03_Curv);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line03_Curv(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_4_t.s_IFC_FD5_19F_Inf_4_t.IFC_Line03_Curv = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line03_Curv);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line04_Dy(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_5_t.s_IFC_FD5_19F_Inf_5_t.IFC_Line04_Dy_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line04_Dy);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line04_Dy(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_5_t.s_IFC_FD5_19F_Inf_5_t.IFC_Line04_Dy = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line04_Dy);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line04_Curv(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_5_t.s_IFC_FD5_19F_Inf_5_t.IFC_Line04_Curv_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line04_Curv);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line04_Curv(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_5_t.s_IFC_FD5_19F_Inf_5_t.IFC_Line04_Curv = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line04_Curv);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Roadedge01_Dy(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_6_t.s_IFC_FD5_19F_Inf_6_t.IFC_Roadedge01_Dy_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Roadedge01_Dy);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Roadedge01_Dy(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_6_t.s_IFC_FD5_19F_Inf_6_t.IFC_Roadedge01_Dy = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Roadedge01_Dy);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Roadedge01_Curv(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_6_t.s_IFC_FD5_19F_Inf_6_t.IFC_Roadedge01_Curv_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Roadedge01_Curv);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Roadedge01_Curv(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_6_t.s_IFC_FD5_19F_Inf_6_t.IFC_Roadedge01_Curv = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Roadedge01_Curv);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Roadedge02_Dy(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_7_t.s_IFC_FD5_19F_Inf_7_t.IFC_Roadedge02_Dy_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Roadedge02_Dy);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Roadedge02_Dy(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_7_t.s_IFC_FD5_19F_Inf_7_t.IFC_Roadedge02_Dy = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Roadedge02_Dy);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Roadedge02_Curv(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_7_t.s_IFC_FD5_19F_Inf_7_t.IFC_Roadedge02_Curv_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Roadedge02_Curv);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Roadedge02_Curv(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_7_t.s_IFC_FD5_19F_Inf_7_t.IFC_Roadedge02_Curv = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Roadedge02_Curv);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line01_CurvChange(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.s_IFC_FD5_19F_Inf_8_t.IFC_Line01_CurvChange_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line01_CurvChange);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line01_CurvChange(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.s_IFC_FD5_19F_Inf_8_t.IFC_Line01_CurvChange = \
		(uint32)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line01_CurvChange);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line02_CurvChange(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.s_IFC_FD5_19F_Inf_8_t.IFC_Line02_CurvChange_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line02_CurvChange);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line02_CurvChange(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.s_IFC_FD5_19F_Inf_8_t.IFC_Line02_CurvChange = \
		(uint32)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line02_CurvChange);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line03_CurvChange(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.s_IFC_FD5_19F_Inf_8_t.IFC_Line03_CurvChange_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line03_CurvChange);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line03_CurvChange(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t.s_IFC_FD5_19F_Inf_8_t.IFC_Line03_CurvChange = \
		(uint32)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line03_CurvChange);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line04_CurvChange(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.s_IFC_FD5_19F_Inf_9_t.IFC_Line04_CurvChange_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line04_CurvChange);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line04_CurvChange(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.s_IFC_FD5_19F_Inf_9_t.IFC_Line04_CurvChange = \
		(uint32)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line04_CurvChange);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Roadedge01_CurvChange(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.s_IFC_FD5_19F_Inf_9_t.IFC_Roadedge01_CurvChange_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Roadedge01_CurvChange);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Roadedge01_CurvChange(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.s_IFC_FD5_19F_Inf_9_t.IFC_Roadedge01_CurvChange = \
		(uint32)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Roadedge01_CurvChange);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Roadedge02_CurvChange(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.s_IFC_FD5_19F_Inf_9_t.IFC_Roadedge02_CurvChange_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Roadedge02_CurvChange);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Roadedge02_CurvChange(void)
{
	IpcSend_stCA_DATA_IFC_FD5_19F_Inf.u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t.s_IFC_FD5_19F_Inf_9_t.IFC_Roadedge02_CurvChange = \
		(uint32)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Roadedge02_CurvChange);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line01_HeadingAngle(void)
{
	IpcSend_stCA_DATA_IFC_FD6_222_Inf.u_IFC_FD6_222IFC_FD6_222_Inf_t.s_IFC_FD6_222_Inf_t.IFC_Line01_HeadingAngle_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line01_HeadingAngle);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line01_HeadingAngle(void)
{
	IpcSend_stCA_DATA_IFC_FD6_222_Inf.u_IFC_FD6_222IFC_FD6_222_Inf_t.s_IFC_FD6_222_Inf_t.IFC_Line01_HeadingAngle = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line01_HeadingAngle);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line02_HeadingAngle(void)
{
	IpcSend_stCA_DATA_IFC_FD6_222_Inf.u_IFC_FD6_222IFC_FD6_222_Inf_t.s_IFC_FD6_222_Inf_t.IFC_Line02_HeadingAngle_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line02_HeadingAngle);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line02_HeadingAngle(void)
{
	IpcSend_stCA_DATA_IFC_FD6_222_Inf.u_IFC_FD6_222IFC_FD6_222_Inf_t.s_IFC_FD6_222_Inf_t.IFC_Line02_HeadingAngle = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line02_HeadingAngle);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line03_HeadingAngle(void)
{
	IpcSend_stCA_DATA_IFC_FD6_222_Inf.u_IFC_FD6_222IFC_FD6_222_Inf_t.s_IFC_FD6_222_Inf_t.IFC_Line03_HeadingAngle_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line03_HeadingAngle);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line03_HeadingAngle(void)
{
	IpcSend_stCA_DATA_IFC_FD6_222_Inf.u_IFC_FD6_222IFC_FD6_222_Inf_t.s_IFC_FD6_222_Inf_t.IFC_Line03_HeadingAngle = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line03_HeadingAngle);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line04_HeadingAngle(void)
{
	IpcSend_stCA_DATA_IFC_FD6_222_Inf.u_IFC_FD6_222IFC_FD6_222_Inf_t.s_IFC_FD6_222_Inf_t.IFC_Line04_HeadingAngle_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line04_HeadingAngle);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line04_HeadingAngle(void)
{
	IpcSend_stCA_DATA_IFC_FD6_222_Inf.u_IFC_FD6_222IFC_FD6_222_Inf_t.s_IFC_FD6_222_Inf_t.IFC_Line04_HeadingAngle = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line04_HeadingAngle);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Roadedge01_HeadingAngle(void)
{
	IpcSend_stCA_DATA_IFC_FD6_222_Inf.u_IFC_FD6_222IFC_FD6_222_Inf_t.s_IFC_FD6_222_Inf_t.IFC_Roadedge01_HeadingAngle_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Roadedge01_HeadingAngle);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Roadedge01_HeadingAngle(void)
{
	IpcSend_stCA_DATA_IFC_FD6_222_Inf.u_IFC_FD6_222IFC_FD6_222_Inf_t.s_IFC_FD6_222_Inf_t.IFC_Roadedge01_HeadingAngle = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Roadedge01_HeadingAngle);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Roadedge02_HeadingAngle(void)
{
	IpcSend_stCA_DATA_IFC_FD6_222_Inf.u_IFC_FD6_222IFC_FD6_222_Inf_t.s_IFC_FD6_222_Inf_t.IFC_Roadedge02_HeadingAngle_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Roadedge02_HeadingAngle);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Roadedge02_HeadingAngle(void)
{
	IpcSend_stCA_DATA_IFC_FD6_222_Inf.u_IFC_FD6_222IFC_FD6_222_Inf_t.s_IFC_FD6_222_Inf_t.IFC_Roadedge02_HeadingAngle = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Roadedge02_HeadingAngle);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_PotentialTgtTyp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.s_ACC_FD2_2AB_Inf_1_t.ACC_PotentialTgtTyp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_PotentialTgtTyp);

	return ;
}



static void vCA_Interface_SignalValue_ACC_PotentialTgtTyp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.s_ACC_FD2_2AB_Inf_1_t.ACC_PotentialTgtTyp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_PotentialTgtTyp);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_PotentialTgtDy(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.s_ACC_FD2_2AB_Inf_1_t.ACC_PotentialTgtDy_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_PotentialTgtDy);

	return ;
}



static void vCA_Interface_SignalValue_ACC_PotentialTgtDy(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.s_ACC_FD2_2AB_Inf_1_t.ACC_PotentialTgtDy = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_PotentialTgtDy);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_PotentialTgtHeading(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.s_ACC_FD2_2AB_Inf_1_t.ACC_PotentialTgtHeading_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_PotentialTgtHeading);

	return ;
}



static void vCA_Interface_SignalValue_ACC_PotentialTgtHeading(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.s_ACC_FD2_2AB_Inf_1_t.ACC_PotentialTgtHeading = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_PotentialTgtHeading);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_PotentialTgtDetn(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.s_ACC_FD2_2AB_Inf_1_t.ACC_PotentialTgtDetn_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_PotentialTgtDetn);

	return ;
}



static void vCA_Interface_SignalValue_ACC_PotentialTgtDetn(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t.s_ACC_FD2_2AB_Inf_1_t.ACC_PotentialTgtDetn = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_PotentialTgtDetn);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_RlvTgtTyp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.s_ACC_FD2_2AB_Inf_2_t.ACC_RlvTgtTyp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_RlvTgtTyp);

	return ;
}



static void vCA_Interface_SignalValue_ACC_RlvTgtTyp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.s_ACC_FD2_2AB_Inf_2_t.ACC_RlvTgtTyp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_RlvTgtTyp);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_RlvTgtDy(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.s_ACC_FD2_2AB_Inf_2_t.ACC_RlvTgtDy_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_RlvTgtDy);

	return ;
}



static void vCA_Interface_SignalValue_ACC_RlvTgtDy(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.s_ACC_FD2_2AB_Inf_2_t.ACC_RlvTgtDy = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_RlvTgtDy);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_RlvTgtHeading(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.s_ACC_FD2_2AB_Inf_2_t.ACC_RlvTgtHeading_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_RlvTgtHeading);

	return ;
}



static void vCA_Interface_SignalValue_ACC_RlvTgtHeading(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.s_ACC_FD2_2AB_Inf_2_t.ACC_RlvTgtHeading = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_RlvTgtHeading);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_RlvTgtDetn(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.s_ACC_FD2_2AB_Inf_2_t.ACC_RlvTgtDetn_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_RlvTgtDetn);

	return ;
}



static void vCA_Interface_SignalValue_ACC_RlvTgtDetn(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t.s_ACC_FD2_2AB_Inf_2_t.ACC_RlvTgtDetn = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_RlvTgtDetn);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_LeTgtTyp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.s_ACC_FD2_2AB_Inf_3_t.ACC_LeTgtTyp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_LeTgtTyp);

	return ;
}



static void vCA_Interface_SignalValue_ACC_LeTgtTyp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.s_ACC_FD2_2AB_Inf_3_t.ACC_LeTgtTyp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_LeTgtTyp);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_LeTgtDy(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.s_ACC_FD2_2AB_Inf_3_t.ACC_LeTgtDy_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_LeTgtDy);

	return ;
}



static void vCA_Interface_SignalValue_ACC_LeTgtDy(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.s_ACC_FD2_2AB_Inf_3_t.ACC_LeTgtDy = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_LeTgtDy);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_LeTgtHeading(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.s_ACC_FD2_2AB_Inf_3_t.ACC_LeTgtHeading_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_LeTgtHeading);

	return ;
}



static void vCA_Interface_SignalValue_ACC_LeTgtHeading(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.s_ACC_FD2_2AB_Inf_3_t.ACC_LeTgtHeading = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_LeTgtHeading);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_LeTargrtDection(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.s_ACC_FD2_2AB_Inf_3_t.ACC_LeTargrtDection_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_LeTargrtDection);

	return ;
}



static void vCA_Interface_SignalValue_ACC_LeTargrtDection(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t.s_ACC_FD2_2AB_Inf_3_t.ACC_LeTargrtDection = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_LeTargrtDection);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_RiTgtTyp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.s_ACC_FD2_2AB_Inf_4_t.ACC_RiTgtTyp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_RiTgtTyp);

	return ;
}



static void vCA_Interface_SignalValue_ACC_RiTgtTyp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.s_ACC_FD2_2AB_Inf_4_t.ACC_RiTgtTyp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_RiTgtTyp);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_RiTgtDy(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.s_ACC_FD2_2AB_Inf_4_t.ACC_RiTgtDy_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_RiTgtDy);

	return ;
}



static void vCA_Interface_SignalValue_ACC_RiTgtDy(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.s_ACC_FD2_2AB_Inf_4_t.ACC_RiTgtDy = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_RiTgtDy);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_RiTgtHeading(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.s_ACC_FD2_2AB_Inf_4_t.ACC_RiTgtHeading_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_RiTgtHeading);

	return ;
}



static void vCA_Interface_SignalValue_ACC_RiTgtHeading(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.s_ACC_FD2_2AB_Inf_4_t.ACC_RiTgtHeading = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_RiTgtHeading);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_RiTargrtDetn(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.s_ACC_FD2_2AB_Inf_4_t.ACC_RiTargrtDetn_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_RiTargrtDetn);

	return ;
}



static void vCA_Interface_SignalValue_ACC_RiTargrtDetn(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t.s_ACC_FD2_2AB_Inf_4_t.ACC_RiTargrtDetn = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_RiTargrtDetn);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_LeTgt_02_Typ(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.s_ACC_FD2_2AB_Inf_5_t.ACC_LeTgt_02_Typ_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_LeTgt_02_Typ);

	return ;
}



static void vCA_Interface_SignalValue_ACC_LeTgt_02_Typ(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.s_ACC_FD2_2AB_Inf_5_t.ACC_LeTgt_02_Typ = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_LeTgt_02_Typ);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_LeTgt_02_Dy(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.s_ACC_FD2_2AB_Inf_5_t.ACC_LeTgt_02_Dy_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_LeTgt_02_Dy);

	return ;
}



static void vCA_Interface_SignalValue_ACC_LeTgt_02_Dy(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.s_ACC_FD2_2AB_Inf_5_t.ACC_LeTgt_02_Dy = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_LeTgt_02_Dy);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_LeTargrt_02_Detn(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.s_ACC_FD2_2AB_Inf_5_t.ACC_LeTargrt_02_Detn_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_LeTargrt_02_Detn);

	return ;
}



static void vCA_Interface_SignalValue_ACC_LeTargrt_02_Detn(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.s_ACC_FD2_2AB_Inf_5_t.ACC_LeTargrt_02_Detn = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_LeTargrt_02_Detn);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_RiTgt_02_Typ(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.s_ACC_FD2_2AB_Inf_5_t.ACC_RiTgt_02_Typ_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_RiTgt_02_Typ);

	return ;
}



static void vCA_Interface_SignalValue_ACC_RiTgt_02_Typ(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.s_ACC_FD2_2AB_Inf_5_t.ACC_RiTgt_02_Typ = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_RiTgt_02_Typ);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_RiTgt_02_Dy(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.s_ACC_FD2_2AB_Inf_5_t.ACC_RiTgt_02_Dy_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_RiTgt_02_Dy);

	return ;
}



static void vCA_Interface_SignalValue_ACC_RiTgt_02_Dy(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t.s_ACC_FD2_2AB_Inf_5_t.ACC_RiTgt_02_Dy = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_RiTgt_02_Dy);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_RiTargrt_02_Detn(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.s_ACC_FD2_2AB_Inf_6_t.ACC_RiTargrt_02_Detn_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_RiTargrt_02_Detn);

	return ;
}



static void vCA_Interface_SignalValue_ACC_RiTargrt_02_Detn(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.s_ACC_FD2_2AB_Inf_6_t.ACC_RiTargrt_02_Detn = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_RiTargrt_02_Detn);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_ModDisp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.s_ACC_FD2_2AB_Inf_6_t.ACC_ModDisp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_ModDisp);

	return ;
}



static void vCA_Interface_SignalValue_ACC_ModDisp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.s_ACC_FD2_2AB_Inf_6_t.ACC_ModDisp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_ModDisp);

	return ;
}



static void vCA_Interface_SignalStatus_TJA_ICA_ModDisp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.s_ACC_FD2_2AB_Inf_6_t.TJA_ICA_ModDisp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_TJA_ICA_ModDisp);

	return ;
}



static void vCA_Interface_SignalValue_TJA_ICA_ModDisp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.s_ACC_FD2_2AB_Inf_6_t.TJA_ICA_ModDisp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_TJA_ICA_ModDisp);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_TgtObjBarDisp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.s_ACC_FD2_2AB_Inf_6_t.ACC_TgtObjBarDisp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_TgtObjBarDisp);

	return ;
}



static void vCA_Interface_SignalValue_ACC_TgtObjBarDisp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.s_ACC_FD2_2AB_Inf_6_t.ACC_TgtObjBarDisp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_TgtObjBarDisp);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_FctSts(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.s_ACC_FD2_2AB_Inf_6_t.ACC_FctSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_FctSts);

	return ;
}



static void vCA_Interface_SignalValue_ACC_FctSts(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.s_ACC_FD2_2AB_Inf_6_t.ACC_FctSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_FctSts);

	return ;
}



static void vCA_Interface_SignalStatus_HWA_InterSysInfoDisp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.s_ACC_FD2_2AB_Inf_6_t.HWA_InterSysInfoDisp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_HWA_InterSysInfoDisp);

	return ;
}



static void vCA_Interface_SignalValue_HWA_InterSysInfoDisp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t.s_ACC_FD2_2AB_Inf_6_t.HWA_InterSysInfoDisp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_HWA_InterSysInfoDisp);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_InterSysInfoDisp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.s_ACC_FD2_2AB_Inf_7_t.ACC_InterSysInfoDisp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_InterSysInfoDisp);

	return ;
}



static void vCA_Interface_SignalValue_ACC_InterSysInfoDisp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.s_ACC_FD2_2AB_Inf_7_t.ACC_InterSysInfoDisp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_InterSysInfoDisp);

	return ;
}



static void vCA_Interface_SignalStatus_TJA_ICA_InterSysInfoDisp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.s_ACC_FD2_2AB_Inf_7_t.TJA_ICA_InterSysInfoDisp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_TJA_ICA_InterSysInfoDisp);

	return ;
}



static void vCA_Interface_SignalValue_TJA_ICA_InterSysInfoDisp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.s_ACC_FD2_2AB_Inf_7_t.TJA_ICA_InterSysInfoDisp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_TJA_ICA_InterSysInfoDisp);

	return ;
}



static void vCA_Interface_SignalStatus_Request_driveoff(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.s_ACC_FD2_2AB_Inf_7_t.Request_driveoff_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_Request_driveoff);

	return ;
}



static void vCA_Interface_SignalValue_Request_driveoff(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.s_ACC_FD2_2AB_Inf_7_t.Request_driveoff = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_Request_driveoff);

	return ;
}



static void vCA_Interface_SignalStatus_HWA_ModDisp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.s_ACC_FD2_2AB_Inf_7_t.HWA_ModDisp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_HWA_ModDisp);

	return ;
}



static void vCA_Interface_SignalValue_HWA_ModDisp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.s_ACC_FD2_2AB_Inf_7_t.HWA_ModDisp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_HWA_ModDisp);

	return ;
}



static void vCA_Interface_SignalStatus_HWA_LaneChange(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.s_ACC_FD2_2AB_Inf_7_t.HWA_LaneChange_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_HWA_LaneChange);

	return ;
}



static void vCA_Interface_SignalValue_HWA_LaneChange(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.s_ACC_FD2_2AB_Inf_7_t.HWA_LaneChange = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_HWA_LaneChange);

	return ;
}



static void vCA_Interface_SignalStatus_HWA_LaneChangeReq(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.s_ACC_FD2_2AB_Inf_7_t.HWA_LaneChangeReq_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_HWA_LaneChangeReq);

	return ;
}



static void vCA_Interface_SignalValue_HWA_LaneChangeReq(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t.s_ACC_FD2_2AB_Inf_7_t.HWA_LaneChangeReq = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_HWA_LaneChangeReq);

	return ;
}



static void vCA_Interface_SignalStatus_HWA_Resp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.s_ACC_FD2_2AB_Inf_8_t.HWA_Resp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_HWA_Resp);

	return ;
}



static void vCA_Interface_SignalValue_HWA_Resp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.s_ACC_FD2_2AB_Inf_8_t.HWA_Resp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_HWA_Resp);

	return ;
}



static void vCA_Interface_SignalStatus_ALC_Resp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.s_ACC_FD2_2AB_Inf_8_t.ALC_Resp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ALC_Resp);

	return ;
}



static void vCA_Interface_SignalValue_ALC_Resp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.s_ACC_FD2_2AB_Inf_8_t.ALC_Resp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ALC_Resp);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_EgoStatus(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.s_ACC_FD2_2AB_Inf_8_t.ACC_EgoStatus_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_EgoStatus);

	return ;
}



static void vCA_Interface_SignalValue_ACC_EgoStatus(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.s_ACC_FD2_2AB_Inf_8_t.ACC_EgoStatus = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_EgoStatus);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_SpdSetValue(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.s_ACC_FD2_2AB_Inf_8_t.ACC_SpdSetValue_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_SpdSetValue);

	return ;
}



static void vCA_Interface_SignalValue_ACC_SpdSetValue(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.s_ACC_FD2_2AB_Inf_8_t.ACC_SpdSetValue = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_SpdSetValue);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_TimeGapSet(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.s_ACC_FD2_2AB_Inf_8_t.ACC_TimeGapSet_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_TimeGapSet);

	return ;
}



static void vCA_Interface_SignalValue_ACC_TimeGapSet(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.s_ACC_FD2_2AB_Inf_8_t.ACC_TimeGapSet = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_TimeGapSet);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_PotentialTgtDx(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.s_ACC_FD2_2AB_Inf_8_t.ACC_PotentialTgtDx_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_PotentialTgtDx);

	return ;
}



static void vCA_Interface_SignalValue_ACC_PotentialTgtDx(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.s_ACC_FD2_2AB_Inf_8_t.ACC_PotentialTgtDx = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_ACC_PotentialTgtDx);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_RlvTgtDx(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.s_ACC_FD2_2AB_Inf_8_t.ACC_RlvTgtDx_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_RlvTgtDx);

	return ;
}



static void vCA_Interface_SignalValue_ACC_RlvTgtDx(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.s_ACC_FD2_2AB_Inf_8_t.ACC_RlvTgtDx = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_ACC_RlvTgtDx);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_LeTgtDx(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.s_ACC_FD2_2AB_Inf_8_t.ACC_LeTgtDx_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_LeTgtDx);

	return ;
}



static void vCA_Interface_SignalValue_ACC_LeTgtDx(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.s_ACC_FD2_2AB_Inf_8_t.ACC_LeTgtDx = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_ACC_LeTgtDx);

	return ;
}



static void vCA_Interface_SignalStatus_ISL_InterSysInfoDisp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.s_ACC_FD2_2AB_Inf_8_t.ISL_InterSysInfoDisp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ISL_InterSysInfoDisp);

	return ;
}



static void vCA_Interface_SignalValue_ISL_InterSysInfoDisp(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t.s_ACC_FD2_2AB_Inf_8_t.ISL_InterSysInfoDisp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ISL_InterSysInfoDisp);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_RiTgtDx(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.s_ACC_FD2_2AB_Inf_9_t.ACC_RiTgtDx_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_RiTgtDx);

	return ;
}



static void vCA_Interface_SignalValue_ACC_RiTgtDx(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.s_ACC_FD2_2AB_Inf_9_t.ACC_RiTgtDx = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_ACC_RiTgtDx);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_LeTgt_02_Dx(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.s_ACC_FD2_2AB_Inf_9_t.ACC_LeTgt_02_Dx_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_LeTgt_02_Dx);

	return ;
}



static void vCA_Interface_SignalValue_ACC_LeTgt_02_Dx(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.s_ACC_FD2_2AB_Inf_9_t.ACC_LeTgt_02_Dx = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_ACC_LeTgt_02_Dx);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_RiTgt_02_Dx(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.s_ACC_FD2_2AB_Inf_9_t.ACC_RiTgt_02_Dx_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_RiTgt_02_Dx);

	return ;
}



static void vCA_Interface_SignalValue_ACC_RiTgt_02_Dx(void)
{
	IpcSend_stCA_DATA_ACC_FD2_2AB_Inf.u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t.s_ACC_FD2_2AB_Inf_9_t.ACC_RiTgt_02_Dx = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_ACC_RiTgt_02_Dx);

	return ;
}



static void vCA_Interface_SignalStatus_LSSIntervention(void)
{
	IpcSend_stCA_DATA_IFC_FD2_23D_Inf.u_IFC_FD2_23DIFC_FD2_23D_Inf_t.s_IFC_FD2_23D_Inf_t.LSSIntervention_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_LSSIntervention);

	return ;
}



static void vCA_Interface_SignalValue_LSSIntervention(void)
{
	IpcSend_stCA_DATA_IFC_FD2_23D_Inf.u_IFC_FD2_23DIFC_FD2_23D_Inf_t.s_IFC_FD2_23D_Inf_t.LSSIntervention = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_LSSIntervention);

	return ;
}



static void vCA_Interface_SignalStatus_TJA_FollowSts(void)
{
	IpcSend_stCA_DATA_IFC_FD2_23D_Inf.u_IFC_FD2_23DIFC_FD2_23D_Inf_t.s_IFC_FD2_23D_Inf_t.TJA_FollowSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_TJA_FollowSts);

	return ;
}



static void vCA_Interface_SignalValue_TJA_FollowSts(void)
{
	IpcSend_stCA_DATA_IFC_FD2_23D_Inf.u_IFC_FD2_23DIFC_FD2_23D_Inf_t.s_IFC_FD2_23D_Inf_t.TJA_FollowSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_TJA_FollowSts);

	return ;
}



static void vCA_Interface_SignalStatus_IntelligentEvaActSts(void)
{
	IpcSend_stCA_DATA_IFC_FD2_23D_Inf.u_IFC_FD2_23DIFC_FD2_23D_Inf_t.s_IFC_FD2_23D_Inf_t.IntelligentEvaActSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IntelligentEvaActSts);

	return ;
}



static void vCA_Interface_SignalValue_IntelligentEvaActSts(void)
{
	IpcSend_stCA_DATA_IFC_FD2_23D_Inf.u_IFC_FD2_23DIFC_FD2_23D_Inf_t.s_IFC_FD2_23D_Inf_t.IntelligentEvaActSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_IntelligentEvaActSts);

	return ;
}



static void vCA_Interface_SignalStatus_LaneAvailability(void)
{
	IpcSend_stCA_DATA_IFC_FD2_23D_Inf.u_IFC_FD2_23DIFC_FD2_23D_Inf_t.s_IFC_FD2_23D_Inf_t.LaneAvailability_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_LaneAvailability);

	return ;
}



static void vCA_Interface_SignalValue_LaneAvailability(void)
{
	IpcSend_stCA_DATA_IFC_FD2_23D_Inf.u_IFC_FD2_23DIFC_FD2_23D_Inf_t.s_IFC_FD2_23D_Inf_t.LaneAvailability = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_LaneAvailability);

	return ;
}



static void vCA_Interface_SignalStatus_FCW_Warn(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_t.s_AEB_FD2_227_Inf_t.FCW_Warn_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_FCW_Warn);

	return ;
}



static void vCA_Interface_SignalValue_FCW_Warn(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_t.s_AEB_FD2_227_Inf_t.FCW_Warn = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_FCW_Warn);

	return ;
}



static void vCA_Interface_SignalStatus_AEB_VehTrig(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_t.s_AEB_FD2_227_Inf_t.AEB_VehTrig_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_AEB_VehTrig);

	return ;
}



static void vCA_Interface_SignalValue_AEB_VehTrig(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_t.s_AEB_FD2_227_Inf_t.AEB_VehTrig = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_AEB_VehTrig);

	return ;
}



static void vCA_Interface_SignalStatus_AEB_PedTrig(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_t.s_AEB_FD2_227_Inf_t.AEB_PedTrig_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_AEB_PedTrig);

	return ;
}



static void vCA_Interface_SignalValue_AEB_PedTrig(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_t.s_AEB_FD2_227_Inf_t.AEB_PedTrig = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_AEB_PedTrig);

	return ;
}



static void vCA_Interface_SignalStatus_AEB_JABrkTrig(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_t.s_AEB_FD2_227_Inf_t.AEB_JABrkTrig_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_AEB_JABrkTrig);

	return ;
}



static void vCA_Interface_SignalValue_AEB_JABrkTrig(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_t.s_AEB_FD2_227_Inf_t.AEB_JABrkTrig = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_AEB_JABrkTrig);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_RiTgt_03_Typ(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_t.s_AEB_FD2_227_Inf_t.ACC_RiTgt_03_Typ_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_RiTgt_03_Typ);

	return ;
}



static void vCA_Interface_SignalValue_ACC_RiTgt_03_Typ(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_t.s_AEB_FD2_227_Inf_t.ACC_RiTgt_03_Typ = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_RiTgt_03_Typ);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_RiTargrt_03_Detn(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_t.s_AEB_FD2_227_Inf_t.ACC_RiTargrt_03_Detn_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_RiTargrt_03_Detn);

	return ;
}



static void vCA_Interface_SignalValue_ACC_RiTargrt_03_Detn(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_t.s_AEB_FD2_227_Inf_t.ACC_RiTargrt_03_Detn = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_RiTargrt_03_Detn);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_RiTgt_03_Dx(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_t.s_AEB_FD2_227_Inf_t.ACC_RiTgt_03_Dx_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_RiTgt_03_Dx);

	return ;
}



static void vCA_Interface_SignalValue_ACC_RiTgt_03_Dx(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_t.s_AEB_FD2_227_Inf_t.ACC_RiTgt_03_Dx = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_ACC_RiTgt_03_Dx);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_LeTgt_03_Typ(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_t.s_AEB_FD2_227_Inf_t.ACC_LeTgt_03_Typ_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_LeTgt_03_Typ);

	return ;
}



static void vCA_Interface_SignalValue_ACC_LeTgt_03_Typ(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_t.s_AEB_FD2_227_Inf_t.ACC_LeTgt_03_Typ = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_LeTgt_03_Typ);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_RiTgt_03_Dy(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_2_t.s_AEB_FD2_227_Inf_2_t.ACC_RiTgt_03_Dy_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_RiTgt_03_Dy);

	return ;
}



static void vCA_Interface_SignalValue_ACC_RiTgt_03_Dy(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_2_t.s_AEB_FD2_227_Inf_2_t.ACC_RiTgt_03_Dy = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_RiTgt_03_Dy);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_LeTargrt_03_Detn(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_2_t.s_AEB_FD2_227_Inf_2_t.ACC_LeTargrt_03_Detn_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_LeTargrt_03_Detn);

	return ;
}



static void vCA_Interface_SignalValue_ACC_LeTargrt_03_Detn(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_2_t.s_AEB_FD2_227_Inf_2_t.ACC_LeTargrt_03_Detn = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_LeTargrt_03_Detn);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_LeTgt_03_Dx(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_2_t.s_AEB_FD2_227_Inf_2_t.ACC_LeTgt_03_Dx_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_LeTgt_03_Dx);

	return ;
}



static void vCA_Interface_SignalValue_ACC_LeTgt_03_Dx(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_2_t.s_AEB_FD2_227_Inf_2_t.ACC_LeTgt_03_Dx = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_ACC_LeTgt_03_Dx);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_PotentialTgt_02_Dx(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_2_t.s_AEB_FD2_227_Inf_2_t.ACC_PotentialTgt_02_Dx_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_PotentialTgt_02_Dx);

	return ;
}



static void vCA_Interface_SignalValue_ACC_PotentialTgt_02_Dx(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_2_t.s_AEB_FD2_227_Inf_2_t.ACC_PotentialTgt_02_Dx = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_ACC_PotentialTgt_02_Dx);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_LeTgt_03_Dy(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_3_t.s_AEB_FD2_227_Inf_3_t.ACC_LeTgt_03_Dy_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_LeTgt_03_Dy);

	return ;
}



static void vCA_Interface_SignalValue_ACC_LeTgt_03_Dy(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_3_t.s_AEB_FD2_227_Inf_3_t.ACC_LeTgt_03_Dy = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_LeTgt_03_Dy);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_PotentialTgt_02_Heading(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_3_t.s_AEB_FD2_227_Inf_3_t.ACC_PotentialTgt_02_Heading_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_PotentialTgt_02_Heading);

	return ;
}



static void vCA_Interface_SignalValue_ACC_PotentialTgt_02_Heading(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_3_t.s_AEB_FD2_227_Inf_3_t.ACC_PotentialTgt_02_Heading = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_PotentialTgt_02_Heading);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_PotentialTgt_02_Typ(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_3_t.s_AEB_FD2_227_Inf_3_t.ACC_PotentialTgt_02_Typ_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_PotentialTgt_02_Typ);

	return ;
}



static void vCA_Interface_SignalValue_ACC_PotentialTgt_02_Typ(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_3_t.s_AEB_FD2_227_Inf_3_t.ACC_PotentialTgt_02_Typ = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_PotentialTgt_02_Typ);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_PotentialTgt_02_Detn(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_3_t.s_AEB_FD2_227_Inf_3_t.ACC_PotentialTgt_02_Detn_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_PotentialTgt_02_Detn);

	return ;
}



static void vCA_Interface_SignalValue_ACC_PotentialTgt_02_Detn(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_3_t.s_AEB_FD2_227_Inf_3_t.ACC_PotentialTgt_02_Detn = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_PotentialTgt_02_Detn);

	return ;
}



static void vCA_Interface_SignalStatus_ACC_PotentialTgt_02_Dy(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_3_t.s_AEB_FD2_227_Inf_3_t.ACC_PotentialTgt_02_Dy_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_ACC_PotentialTgt_02_Dy);

	return ;
}



static void vCA_Interface_SignalValue_ACC_PotentialTgt_02_Dy(void)
{
	IpcSend_stCA_DATA_AEB_FD2_227_Inf.u_AEB_FD2_227AEB_FD2_227_Inf_3_t.s_AEB_FD2_227_Inf_3_t.ACC_PotentialTgt_02_Dy = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_ACC_PotentialTgt_02_Dy);

	return ;
}



static void vCA_Interface_SignalStatus_FCTA_Warn(void)
{
	IpcSend_stCA_DATA_CR_FD1_15E_Inf.u_CR_FD1_15ECR_FD1_15E_Inf_t.s_CR_FD1_15E_Inf_t.FCTA_Warn_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_FCTA_Warn);

	return ;
}



static void vCA_Interface_SignalValue_FCTA_Warn(void)
{
	IpcSend_stCA_DATA_CR_FD1_15E_Inf.u_CR_FD1_15ECR_FD1_15E_Inf_t.s_CR_FD1_15E_Inf_t.FCTA_Warn = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_FCTA_Warn);

	return ;
}



static void vCA_Interface_SignalStatus_FCTBTrig(void)
{
	IpcSend_stCA_DATA_CR_FD1_15E_Inf.u_CR_FD1_15ECR_FD1_15E_Inf_t.s_CR_FD1_15E_Inf_t.FCTBTrig_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_FCTBTrig);

	return ;
}



static void vCA_Interface_SignalValue_FCTBTrig(void)
{
	IpcSend_stCA_DATA_CR_FD1_15E_Inf.u_CR_FD1_15ECR_FD1_15E_Inf_t.s_CR_FD1_15E_Inf_t.FCTBTrig = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_FCTBTrig);

	return ;
}



static void vCA_Interface_SignalStatus_IDC_L2_TurnLightReq(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.IDC_L2_TurnLightReq_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IDC_L2_TurnLightReq);

	return ;
}



static void vCA_Interface_SignalValue_IDC_L2_TurnLightReq(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.IDC_L2_TurnLightReq = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_IDC_L2_TurnLightReq);

	return ;
}



static void vCA_Interface_SignalStatus_HWA_WarnInfoDisp(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.HWA_WarnInfoDisp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_HWA_WarnInfoDisp);

	return ;
}



static void vCA_Interface_SignalValue_HWA_WarnInfoDisp(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.HWA_WarnInfoDisp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_HWA_WarnInfoDisp);

	return ;
}



static void vCA_Interface_SignalStatus_MRC_InterSysInfoDisp(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.MRC_InterSysInfoDisp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_MRC_InterSysInfoDisp);

	return ;
}



static void vCA_Interface_SignalValue_MRC_InterSysInfoDisp(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.MRC_InterSysInfoDisp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_MRC_InterSysInfoDisp);

	return ;
}



static void vCA_Interface_SignalStatus_HWA_ALC_Trig(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.HWA_ALC_Trig_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_HWA_ALC_Trig);

	return ;
}



static void vCA_Interface_SignalValue_HWA_ALC_Trig(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.HWA_ALC_Trig = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_HWA_ALC_Trig);

	return ;
}



static void vCA_Interface_SignalStatus_Stop_Mark_Detn(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.Stop_Mark_Detn_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_Stop_Mark_Detn);

	return ;
}



static void vCA_Interface_SignalValue_Stop_Mark_Detn(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.Stop_Mark_Detn = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_Stop_Mark_Detn);

	return ;
}



static void vCA_Interface_SignalStatus_Stop_Mark_Dx(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.Stop_Mark_Dx_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_Stop_Mark_Dx);

	return ;
}



static void vCA_Interface_SignalValue_Stop_Mark_Dx(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.Stop_Mark_Dx = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_Stop_Mark_Dx);

	return ;
}



static void vCA_Interface_SignalStatus_Zebra_Mark_Detn(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.Zebra_Mark_Detn_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_Zebra_Mark_Detn);

	return ;
}



static void vCA_Interface_SignalValue_Zebra_Mark_Detn(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.Zebra_Mark_Detn = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_Zebra_Mark_Detn);

	return ;
}



static void vCA_Interface_SignalStatus_Zebra_Mark_Dx(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.Zebra_Mark_Dx_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_Zebra_Mark_Dx);

	return ;
}



static void vCA_Interface_SignalValue_Zebra_Mark_Dx(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.Zebra_Mark_Dx = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_Zebra_Mark_Dx);

	return ;
}



static void vCA_Interface_SignalStatus_Grid_Mark_Detn(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.Grid_Mark_Detn_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_Grid_Mark_Detn);

	return ;
}



static void vCA_Interface_SignalValue_Grid_Mark_Detn(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.Grid_Mark_Detn = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_Grid_Mark_Detn);

	return ;
}



static void vCA_Interface_SignalStatus_Grid_Mark_Dx(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.Grid_Mark_Dx_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_Grid_Mark_Dx);

	return ;
}



static void vCA_Interface_SignalValue_Grid_Mark_Dx(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.Grid_Mark_Dx = \
		(uint16)u32CA_Process_GetSignalValue(enCASignalInd_Grid_Mark_Dx);

	return ;
}



static void vCA_Interface_SignalStatus_HWA_InhibitWarn(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.HWA_InhibitWarn_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_HWA_InhibitWarn);

	return ;
}



static void vCA_Interface_SignalValue_HWA_InhibitWarn(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.HWA_InhibitWarn = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_HWA_InhibitWarn);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line01_Source(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.IFC_Line01_Source_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line01_Source);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line01_Source(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.IFC_Line01_Source = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line01_Source);

	return ;
}



static void vCA_Interface_SignalStatus_IFC_Line02_Source(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.IFC_Line02_Source_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_IFC_Line02_Source);

	return ;
}



static void vCA_Interface_SignalValue_IFC_Line02_Source(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t.s_IFC_FD3_2CF_Inf_t.IFC_Line02_Source = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_IFC_Line02_Source);

	return ;
}



static void vCA_Interface_SignalStatus_TSRSpdLim(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_1_t.s_IFC_FD3_2CF_Inf_1_t.TSRSpdLim_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_TSRSpdLim);

	return ;
}



static void vCA_Interface_SignalValue_TSRSpdLim(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_1_t.s_IFC_FD3_2CF_Inf_1_t.TSRSpdLim = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_TSRSpdLim);

	return ;
}



static void vCA_Interface_SignalStatus_HWA_TakOver_Req(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_1_t.s_IFC_FD3_2CF_Inf_1_t.HWA_TakOver_Req_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_HWA_TakOver_Req);

	return ;
}



static void vCA_Interface_SignalValue_HWA_TakOver_Req(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_1_t.s_IFC_FD3_2CF_Inf_1_t.HWA_TakOver_Req = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_HWA_TakOver_Req);

	return ;
}



static void vCA_Interface_SignalStatus_AutoSpdSetSwt_Resp(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_1_t.s_IFC_FD3_2CF_Inf_1_t.AutoSpdSetSwt_Resp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_AutoSpdSetSwt_Resp);

	return ;
}



static void vCA_Interface_SignalValue_AutoSpdSetSwt_Resp(void)
{
	IpcSend_stCA_DATA_IFC_FD3_2CF_Inf.u_IFC_FD3_2CFIFC_FD3_2CF_Inf_1_t.s_IFC_FD3_2CF_Inf_1_t.AutoSpdSetSwt_Resp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_AutoSpdSetSwt_Resp);

	return ;
}



static void vCA_Interface_SignalStatus_NOH_Sts(void)
{
	IpcSend_stCA_DATA_ACC_FD3_2B4_Inf.u_ACC_FD3_2B4ACC_FD3_2B4_Inf_t.s_ACC_FD3_2B4_Inf_t.NOH_Sts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_NOH_Sts);

	return ;
}



static void vCA_Interface_SignalValue_NOH_Sts(void)
{
	IpcSend_stCA_DATA_ACC_FD3_2B4_Inf.u_ACC_FD3_2B4ACC_FD3_2B4_Inf_t.s_ACC_FD3_2B4_Inf_t.NOH_Sts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_NOH_Sts);

	return ;
}



static void vCA_Interface_SignalStatus_NOH_SysInfoDisplay(void)
{
	IpcSend_stCA_DATA_ACC_FD3_2B4_Inf.u_ACC_FD3_2B4ACC_FD3_2B4_Inf_t.s_ACC_FD3_2B4_Inf_t.NOH_SysInfoDisplay_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_NOH_SysInfoDisplay);

	return ;
}



static void vCA_Interface_SignalValue_NOH_SysInfoDisplay(void)
{
	IpcSend_stCA_DATA_ACC_FD3_2B4_Inf.u_ACC_FD3_2B4ACC_FD3_2B4_Inf_t.s_ACC_FD3_2B4_Inf_t.NOH_SysInfoDisplay = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_NOH_SysInfoDisplay);

	return ;
}



static void vCA_Interface_SignalStatus_DrvDoorSts(void)
{
	IpcSend_stCA_DATA_BCM1_319_Inf.u_BCM1_319BCM1_319_Inf_t.s_BCM1_319_Inf_t.DrvDoorSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_DrvDoorSts);

	return ;
}



static void vCA_Interface_SignalValue_DrvDoorSts(void)
{
	IpcSend_stCA_DATA_BCM1_319_Inf.u_BCM1_319BCM1_319_Inf_t.s_BCM1_319_Inf_t.DrvDoorSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_DrvDoorSts);

	return ;
}



static void vCA_Interface_SignalStatus_BrkPedalSts_BCM(void)
{
	IpcSend_stCA_DATA_BCM1_319_Inf.u_BCM1_319BCM1_319_Inf_t.s_BCM1_319_Inf_t.BrkPedalSts_BCM_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_BrkPedalSts_BCM);

	return ;
}



static void vCA_Interface_SignalValue_BrkPedalSts_BCM(void)
{
	IpcSend_stCA_DATA_BCM1_319_Inf.u_BCM1_319BCM1_319_Inf_t.s_BCM1_319_Inf_t.BrkPedalSts_BCM = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_BrkPedalSts_BCM);

	return ;
}



static void vCA_Interface_SignalStatus_DrvDoorLockSts(void)
{
	IpcSend_stCA_DATA_BCM3_345_Inf.u_BCM3_345BCM3_345_Inf_t.s_BCM3_345_Inf_t.DrvDoorLockSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_DrvDoorLockSts);

	return ;
}



static void vCA_Interface_SignalValue_DrvDoorLockSts(void)
{
	IpcSend_stCA_DATA_BCM3_345_Inf.u_BCM3_345BCM3_345_Inf_t.s_BCM3_345_Inf_t.DrvDoorLockSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_DrvDoorLockSts);

	return ;
}



static void vCA_Interface_SignalStatus_V2X_RLVW(void)
{
	IpcSend_stCA_DATA_T_Box_FD10_2F0_Inf.u_T_Box_FD10_2F0T_Box_FD10_2F0_Inf_t.s_T_Box_FD10_2F0_Inf_t.V2X_RLVW_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_V2X_RLVW);

	return ;
}



static void vCA_Interface_SignalValue_V2X_RLVW(void)
{
	IpcSend_stCA_DATA_T_Box_FD10_2F0_Inf.u_T_Box_FD10_2F0T_Box_FD10_2F0_Inf_t.s_T_Box_FD10_2F0_Inf_t.V2X_RLVW = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_V2X_RLVW);

	return ;
}



static void vCA_Interface_SignalStatus_EngOilPres(void)
{
	IpcSend_stCA_DATA_ECM24_350_Inf.u_ECM24_350ECM24_350_Inf_t.s_ECM24_350_Inf_t.EngOilPres_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_EngOilPres);

	return ;
}



static void vCA_Interface_SignalValue_EngOilPres(void)
{
	IpcSend_stCA_DATA_ECM24_350_Inf.u_ECM24_350ECM24_350_Inf_t.s_ECM24_350_Inf_t.EngOilPres = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_EngOilPres);

	return ;
}



static void vCA_Interface_SignalStatus_EngOilTemp(void)
{
	IpcSend_stCA_DATA_ECM24_350_Inf.u_ECM24_350ECM24_350_Inf_t.s_ECM24_350_Inf_t.EngOilTemp_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_EngOilTemp);

	return ;
}



static void vCA_Interface_SignalValue_EngOilTemp(void)
{
	IpcSend_stCA_DATA_ECM24_350_Inf.u_ECM24_350ECM24_350_Inf_t.s_ECM24_350_Inf_t.EngOilTemp = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_EngOilTemp);

	return ;
}



static void vCA_Interface_SignalStatus_SrPosn_VR_APP(void)
{
	IpcSend_stCA_DATA_BCM12_238_Inf.u_BCM12_238BCM12_238_Inf_t.s_BCM12_238_Inf_t.SrPosn_VR_APP_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_SrPosn_VR_APP);

	return ;
}



static void vCA_Interface_SignalValue_SrPosn_VR_APP(void)
{
	IpcSend_stCA_DATA_BCM12_238_Inf.u_BCM12_238BCM12_238_Inf_t.s_BCM12_238_Inf_t.SrPosn_VR_APP = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_SrPosn_VR_APP);

	return ;
}



static void vCA_Interface_SignalStatus_LowBeamSts_F_PBOX(void)
{
	IpcSend_stCA_DATA_F_PBOX1_19B_Inf.u_F_PBOX1_19BF_PBOX1_19B_Inf_t.s_F_PBOX1_19B_Inf_t.LowBeamSts_F_PBOX_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_LowBeamSts_F_PBOX);

	return ;
}



static void vCA_Interface_SignalValue_LowBeamSts_F_PBOX(void)
{
	IpcSend_stCA_DATA_F_PBOX1_19B_Inf.u_F_PBOX1_19BF_PBOX1_19B_Inf_t.s_F_PBOX1_19B_Inf_t.LowBeamSts_F_PBOX = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_LowBeamSts_F_PBOX);

	return ;
}



static void vCA_Interface_SignalStatus_LeftLightShowSts(void)
{
	IpcSend_stCA_DATA_HCM_L2_304_Inf.u_HCM_L2_304HCM_L2_304_Inf_t.s_HCM_L2_304_Inf_t.LeftLightShowSts_Sts_Flag = \
		(uint8)u8CA_Process_GetSignalStatus(enCASignalInd_LeftLightShowSts);

	return ;
}



static void vCA_Interface_SignalValue_LeftLightShowSts(void)
{
	IpcSend_stCA_DATA_HCM_L2_304_Inf.u_HCM_L2_304HCM_L2_304_Inf_t.s_HCM_L2_304_Inf_t.LeftLightShowSts = \
		(uint8)u32CA_Process_GetSignalValue(enCASignalInd_LeftLightShowSts);

	return ;
}



static void vCA_Interface_MsgCSA3_244ValueUpdate(void)
{
    vCA_Interface_SignalStatus_PageUpSwtSts();
    vCA_Interface_SignalValue_PageUpSwtSts();
    vCA_Interface_SignalStatus_PageDwnSwtSts();
    vCA_Interface_SignalValue_PageDwnSwtSts();
    vCA_Interface_SignalStatus_PageLSwtSts();
    vCA_Interface_SignalValue_PageLSwtSts();
    vCA_Interface_SignalStatus_PageRSwtSts();
    vCA_Interface_SignalValue_PageRSwtSts();
    vCA_Interface_SignalStatus_EnterSwtSts();
    vCA_Interface_SignalValue_EnterSwtSts();
    vCA_Interface_SignalStatus_HomeSwtSts();
    vCA_Interface_SignalValue_HomeSwtSts();
    vCA_Interface_SignalStatus_MenuReturnSwtSts();
    vCA_Interface_SignalValue_MenuReturnSwtSts();
    vCA_Interface_SignalStatus_CustomSwtSts();
    vCA_Interface_SignalValue_CustomSwtSts();
    vCA_Interface_SignalStatus_IpMenuSwtSts();
    vCA_Interface_SignalValue_IpMenuSwtSts();
    vCA_Interface_SignalStatus_AdjVolDwnSwtSts();
    vCA_Interface_SignalValue_AdjVolDwnSwtSts();
    vCA_Interface_SignalStatus_AdjVolUpSwtSts();
    vCA_Interface_SignalValue_AdjVolUpSwtSts();
    vCA_Interface_SignalStatus_SeekDwnSwtSts();
    vCA_Interface_SignalValue_SeekDwnSwtSts();
    vCA_Interface_SignalStatus_SeekUpSwtSts();
    vCA_Interface_SignalValue_SeekUpSwtSts();
    vCA_Interface_SignalStatus_EnterSwtSts_Mmed();
    vCA_Interface_SignalValue_EnterSwtSts_Mmed();
    vCA_Interface_SignalStatus_VRSwtSts();
    vCA_Interface_SignalValue_VRSwtSts();
    vCA_Interface_SignalStatus_MuteSwtSts();
    vCA_Interface_SignalValue_MuteSwtSts();
    vCA_Interface_SignalStatus_CustomSwtSts_Mmed();
    vCA_Interface_SignalValue_CustomSwtSts_Mmed();


	return ;
}


static void vCA_Interface_MsgEEM1_2A8ValueUpdate(void)
{
    vCA_Interface_SignalStatus_Stat_PwrSv_Lvl();
    vCA_Interface_SignalValue_Stat_PwrSv_Lvl();


	return ;
}


static void vCA_Interface_MsgESP2_145ValueUpdate(void)
{
    vCA_Interface_SignalStatus_DrivingModDis_145();
    vCA_Interface_SignalValue_DrivingModDis_145();


	return ;
}


static void vCA_Interface_MsgESP_FD2_137ValueUpdate(void)
{
    vCA_Interface_SignalStatus_DrivingModDis_137();
    vCA_Interface_SignalValue_DrivingModDis_137();
    vCA_Interface_SignalStatus_ESPBrkLmpCtrl_137();
    vCA_Interface_SignalValue_ESPBrkLmpCtrl_137();


	return ;
}


static void vCA_Interface_MsgHUD1_325ValueUpdate(void)
{
    vCA_Interface_SignalStatus_HUD_BrightnessLvl();
    vCA_Interface_SignalValue_HUD_BrightnessLvl();
    vCA_Interface_SignalStatus_HUD_HeightLvl();
    vCA_Interface_SignalValue_HUD_HeightLvl();
    vCA_Interface_SignalStatus_HUD_UIMod();
    vCA_Interface_SignalValue_HUD_UIMod();
    vCA_Interface_SignalStatus_HUD_UIModVld();
    vCA_Interface_SignalValue_HUD_UIModVld();
    vCA_Interface_SignalStatus_HUD_SwtSts();
    vCA_Interface_SignalValue_HUD_SwtSts();


	return ;
}


static void vCA_Interface_MsgECM3_371ValueUpdate(void)
{
    vCA_Interface_SignalStatus_BaroPressure();
    vCA_Interface_SignalValue_BaroPressure();


	return ;
}


static void vCA_Interface_MsgCSA2_A1ValueUpdate(void)
{
    vCA_Interface_SignalStatus_SAS_Sts();
    vCA_Interface_SignalValue_SAS_Sts();
    vCA_Interface_SignalStatus_SteerWheelAngSign();
    vCA_Interface_SignalValue_SteerWheelAngSign();
    vCA_Interface_SignalStatus_SteerWheelAng();
    vCA_Interface_SignalValue_SteerWheelAng();


	return ;
}


static void vCA_Interface_MsgECM16_2D4ValueUpdate(void)
{
    vCA_Interface_SignalStatus_Urea_Level();
    vCA_Interface_SignalValue_Urea_Level();
    vCA_Interface_SignalStatus_SCRSysWarnDisplay();
    vCA_Interface_SignalValue_SCRSysWarnDisplay();
    vCA_Interface_SignalStatus_SCRSysWarnDisplay_B2();
    vCA_Interface_SignalValue_SCRSysWarnDisplay_B2();
    vCA_Interface_SignalStatus_UreaRemainDist();
    vCA_Interface_SignalValue_UreaRemainDist();


	return ;
}


static void vCA_Interface_MsgAC2_385ValueUpdate(void)
{
    vCA_Interface_SignalStatus_ACAmbTemp();
    vCA_Interface_SignalValue_ACAmbTemp();


	return ;
}


static void vCA_Interface_MsgECM_PT6_290ValueUpdate(void)
{
    vCA_Interface_SignalStatus_TrqPrct();
    vCA_Interface_SignalValue_TrqPrct();
    vCA_Interface_SignalStatus_PowerPrct();
    vCA_Interface_SignalValue_PowerPrct();


	return ;
}


static void vCA_Interface_MsgABM2_245ValueUpdate(void)
{
    vCA_Interface_SignalStatus_VehLgtAccelVld();
    vCA_Interface_SignalValue_VehLgtAccelVld();
    vCA_Interface_SignalStatus_VehLatAccelVld();
    vCA_Interface_SignalValue_VehLatAccelVld();
    vCA_Interface_SignalStatus_VehLgtAccel();
    vCA_Interface_SignalValue_VehLgtAccel();
    vCA_Interface_SignalStatus_VehLatAccel();
    vCA_Interface_SignalValue_VehLatAccel();


	return ;
}


static void vCA_Interface_MsgRSDS_FD1_16FValueUpdate(void)
{
    vCA_Interface_SignalStatus_BSD_LCA_warningReqRight();
    vCA_Interface_SignalValue_BSD_LCA_warningReqRight();
    vCA_Interface_SignalStatus_BSD_LCA_warningReqleft();
    vCA_Interface_SignalValue_BSD_LCA_warningReqleft();
    vCA_Interface_SignalStatus_DOW_warningReqRight();
    vCA_Interface_SignalValue_DOW_warningReqRight();
    vCA_Interface_SignalStatus_DOW_warningReqleft();
    vCA_Interface_SignalValue_DOW_warningReqleft();


	return ;
}


static void vCA_Interface_MsgIFC_FD5_19FValueUpdate(void)
{
    vCA_Interface_SignalStatus_IFC_Line01_Type();
    vCA_Interface_SignalValue_IFC_Line01_Type();
    vCA_Interface_SignalStatus_IFC_Line02_Type();
    vCA_Interface_SignalValue_IFC_Line02_Type();
    vCA_Interface_SignalStatus_IFC_Line03_Type();
    vCA_Interface_SignalValue_IFC_Line03_Type();
    vCA_Interface_SignalStatus_IFC_Line04_Type();
    vCA_Interface_SignalValue_IFC_Line04_Type();
    vCA_Interface_SignalStatus_IFC_Roadedge01_Type();
    vCA_Interface_SignalValue_IFC_Roadedge01_Type();
    vCA_Interface_SignalStatus_IFC_Roadedge02_Type();
    vCA_Interface_SignalValue_IFC_Roadedge02_Type();
    vCA_Interface_SignalStatus_IFC_Line01_Dy();
    vCA_Interface_SignalValue_IFC_Line01_Dy();
    vCA_Interface_SignalStatus_IFC_Line01_Curv();
    vCA_Interface_SignalValue_IFC_Line01_Curv();
    vCA_Interface_SignalStatus_IFC_Line02_Dy();
    vCA_Interface_SignalValue_IFC_Line02_Dy();
    vCA_Interface_SignalStatus_IFC_Line02_Curv();
    vCA_Interface_SignalValue_IFC_Line02_Curv();
    vCA_Interface_SignalStatus_IFC_Line03_Dy();
    vCA_Interface_SignalValue_IFC_Line03_Dy();
    vCA_Interface_SignalStatus_IFC_Line03_Curv();
    vCA_Interface_SignalValue_IFC_Line03_Curv();
    vCA_Interface_SignalStatus_IFC_Line04_Dy();
    vCA_Interface_SignalValue_IFC_Line04_Dy();
    vCA_Interface_SignalStatus_IFC_Line04_Curv();
    vCA_Interface_SignalValue_IFC_Line04_Curv();
    vCA_Interface_SignalStatus_IFC_Roadedge01_Dy();
    vCA_Interface_SignalValue_IFC_Roadedge01_Dy();
    vCA_Interface_SignalStatus_IFC_Roadedge01_Curv();
    vCA_Interface_SignalValue_IFC_Roadedge01_Curv();
    vCA_Interface_SignalStatus_IFC_Roadedge02_Dy();
    vCA_Interface_SignalValue_IFC_Roadedge02_Dy();
    vCA_Interface_SignalStatus_IFC_Roadedge02_Curv();
    vCA_Interface_SignalValue_IFC_Roadedge02_Curv();
    vCA_Interface_SignalStatus_IFC_Line01_CurvChange();
    vCA_Interface_SignalValue_IFC_Line01_CurvChange();
    vCA_Interface_SignalStatus_IFC_Line02_CurvChange();
    vCA_Interface_SignalValue_IFC_Line02_CurvChange();
    vCA_Interface_SignalStatus_IFC_Line03_CurvChange();
    vCA_Interface_SignalValue_IFC_Line03_CurvChange();
    vCA_Interface_SignalStatus_IFC_Line04_CurvChange();
    vCA_Interface_SignalValue_IFC_Line04_CurvChange();
    vCA_Interface_SignalStatus_IFC_Roadedge01_CurvChange();
    vCA_Interface_SignalValue_IFC_Roadedge01_CurvChange();
    vCA_Interface_SignalStatus_IFC_Roadedge02_CurvChange();
    vCA_Interface_SignalValue_IFC_Roadedge02_CurvChange();


	return ;
}


static void vCA_Interface_MsgIFC_FD6_222ValueUpdate(void)
{
    vCA_Interface_SignalStatus_IFC_Line01_HeadingAngle();
    vCA_Interface_SignalValue_IFC_Line01_HeadingAngle();
    vCA_Interface_SignalStatus_IFC_Line02_HeadingAngle();
    vCA_Interface_SignalValue_IFC_Line02_HeadingAngle();
    vCA_Interface_SignalStatus_IFC_Line03_HeadingAngle();
    vCA_Interface_SignalValue_IFC_Line03_HeadingAngle();
    vCA_Interface_SignalStatus_IFC_Line04_HeadingAngle();
    vCA_Interface_SignalValue_IFC_Line04_HeadingAngle();
    vCA_Interface_SignalStatus_IFC_Roadedge01_HeadingAngle();
    vCA_Interface_SignalValue_IFC_Roadedge01_HeadingAngle();
    vCA_Interface_SignalStatus_IFC_Roadedge02_HeadingAngle();
    vCA_Interface_SignalValue_IFC_Roadedge02_HeadingAngle();


	return ;
}


static void vCA_Interface_MsgACC_FD2_2ABValueUpdate(void)
{
    vCA_Interface_SignalStatus_ACC_PotentialTgtTyp();
    vCA_Interface_SignalValue_ACC_PotentialTgtTyp();
    vCA_Interface_SignalStatus_ACC_PotentialTgtDy();
    vCA_Interface_SignalValue_ACC_PotentialTgtDy();
    vCA_Interface_SignalStatus_ACC_PotentialTgtHeading();
    vCA_Interface_SignalValue_ACC_PotentialTgtHeading();
    vCA_Interface_SignalStatus_ACC_PotentialTgtDetn();
    vCA_Interface_SignalValue_ACC_PotentialTgtDetn();
    vCA_Interface_SignalStatus_ACC_RlvTgtTyp();
    vCA_Interface_SignalValue_ACC_RlvTgtTyp();
    vCA_Interface_SignalStatus_ACC_RlvTgtDy();
    vCA_Interface_SignalValue_ACC_RlvTgtDy();
    vCA_Interface_SignalStatus_ACC_RlvTgtHeading();
    vCA_Interface_SignalValue_ACC_RlvTgtHeading();
    vCA_Interface_SignalStatus_ACC_RlvTgtDetn();
    vCA_Interface_SignalValue_ACC_RlvTgtDetn();
    vCA_Interface_SignalStatus_ACC_LeTgtTyp();
    vCA_Interface_SignalValue_ACC_LeTgtTyp();
    vCA_Interface_SignalStatus_ACC_LeTgtDy();
    vCA_Interface_SignalValue_ACC_LeTgtDy();
    vCA_Interface_SignalStatus_ACC_LeTgtHeading();
    vCA_Interface_SignalValue_ACC_LeTgtHeading();
    vCA_Interface_SignalStatus_ACC_LeTargrtDection();
    vCA_Interface_SignalValue_ACC_LeTargrtDection();
    vCA_Interface_SignalStatus_ACC_RiTgtTyp();
    vCA_Interface_SignalValue_ACC_RiTgtTyp();
    vCA_Interface_SignalStatus_ACC_RiTgtDy();
    vCA_Interface_SignalValue_ACC_RiTgtDy();
    vCA_Interface_SignalStatus_ACC_RiTgtHeading();
    vCA_Interface_SignalValue_ACC_RiTgtHeading();
    vCA_Interface_SignalStatus_ACC_RiTargrtDetn();
    vCA_Interface_SignalValue_ACC_RiTargrtDetn();
    vCA_Interface_SignalStatus_ACC_LeTgt_02_Typ();
    vCA_Interface_SignalValue_ACC_LeTgt_02_Typ();
    vCA_Interface_SignalStatus_ACC_LeTgt_02_Dy();
    vCA_Interface_SignalValue_ACC_LeTgt_02_Dy();
    vCA_Interface_SignalStatus_ACC_LeTargrt_02_Detn();
    vCA_Interface_SignalValue_ACC_LeTargrt_02_Detn();
    vCA_Interface_SignalStatus_ACC_RiTgt_02_Typ();
    vCA_Interface_SignalValue_ACC_RiTgt_02_Typ();
    vCA_Interface_SignalStatus_ACC_RiTgt_02_Dy();
    vCA_Interface_SignalValue_ACC_RiTgt_02_Dy();
    vCA_Interface_SignalStatus_ACC_RiTargrt_02_Detn();
    vCA_Interface_SignalValue_ACC_RiTargrt_02_Detn();
    vCA_Interface_SignalStatus_ACC_ModDisp();
    vCA_Interface_SignalValue_ACC_ModDisp();
    vCA_Interface_SignalStatus_TJA_ICA_ModDisp();
    vCA_Interface_SignalValue_TJA_ICA_ModDisp();
    vCA_Interface_SignalStatus_ACC_TgtObjBarDisp();
    vCA_Interface_SignalValue_ACC_TgtObjBarDisp();
    vCA_Interface_SignalStatus_ACC_FctSts();
    vCA_Interface_SignalValue_ACC_FctSts();
    vCA_Interface_SignalStatus_HWA_InterSysInfoDisp();
    vCA_Interface_SignalValue_HWA_InterSysInfoDisp();
    vCA_Interface_SignalStatus_ACC_InterSysInfoDisp();
    vCA_Interface_SignalValue_ACC_InterSysInfoDisp();
    vCA_Interface_SignalStatus_TJA_ICA_InterSysInfoDisp();
    vCA_Interface_SignalValue_TJA_ICA_InterSysInfoDisp();
    vCA_Interface_SignalStatus_Request_driveoff();
    vCA_Interface_SignalValue_Request_driveoff();
    vCA_Interface_SignalStatus_HWA_ModDisp();
    vCA_Interface_SignalValue_HWA_ModDisp();
    vCA_Interface_SignalStatus_HWA_LaneChange();
    vCA_Interface_SignalValue_HWA_LaneChange();
    vCA_Interface_SignalStatus_HWA_LaneChangeReq();
    vCA_Interface_SignalValue_HWA_LaneChangeReq();
    vCA_Interface_SignalStatus_HWA_Resp();
    vCA_Interface_SignalValue_HWA_Resp();
    vCA_Interface_SignalStatus_ALC_Resp();
    vCA_Interface_SignalValue_ALC_Resp();
    vCA_Interface_SignalStatus_ACC_EgoStatus();
    vCA_Interface_SignalValue_ACC_EgoStatus();
    vCA_Interface_SignalStatus_ACC_SpdSetValue();
    vCA_Interface_SignalValue_ACC_SpdSetValue();
    vCA_Interface_SignalStatus_ACC_TimeGapSet();
    vCA_Interface_SignalValue_ACC_TimeGapSet();
    vCA_Interface_SignalStatus_ACC_PotentialTgtDx();
    vCA_Interface_SignalValue_ACC_PotentialTgtDx();
    vCA_Interface_SignalStatus_ACC_RlvTgtDx();
    vCA_Interface_SignalValue_ACC_RlvTgtDx();
    vCA_Interface_SignalStatus_ACC_LeTgtDx();
    vCA_Interface_SignalValue_ACC_LeTgtDx();
    vCA_Interface_SignalStatus_ISL_InterSysInfoDisp();
    vCA_Interface_SignalValue_ISL_InterSysInfoDisp();
    vCA_Interface_SignalStatus_ACC_RiTgtDx();
    vCA_Interface_SignalValue_ACC_RiTgtDx();
    vCA_Interface_SignalStatus_ACC_LeTgt_02_Dx();
    vCA_Interface_SignalValue_ACC_LeTgt_02_Dx();
    vCA_Interface_SignalStatus_ACC_RiTgt_02_Dx();
    vCA_Interface_SignalValue_ACC_RiTgt_02_Dx();


	return ;
}


static void vCA_Interface_MsgIFC_FD2_23DValueUpdate(void)
{
    vCA_Interface_SignalStatus_LSSIntervention();
    vCA_Interface_SignalValue_LSSIntervention();
    vCA_Interface_SignalStatus_TJA_FollowSts();
    vCA_Interface_SignalValue_TJA_FollowSts();
    vCA_Interface_SignalStatus_IntelligentEvaActSts();
    vCA_Interface_SignalValue_IntelligentEvaActSts();
    vCA_Interface_SignalStatus_LaneAvailability();
    vCA_Interface_SignalValue_LaneAvailability();


	return ;
}


static void vCA_Interface_MsgAEB_FD2_227ValueUpdate(void)
{
    vCA_Interface_SignalStatus_FCW_Warn();
    vCA_Interface_SignalValue_FCW_Warn();
    vCA_Interface_SignalStatus_AEB_VehTrig();
    vCA_Interface_SignalValue_AEB_VehTrig();
    vCA_Interface_SignalStatus_AEB_PedTrig();
    vCA_Interface_SignalValue_AEB_PedTrig();
    vCA_Interface_SignalStatus_AEB_JABrkTrig();
    vCA_Interface_SignalValue_AEB_JABrkTrig();
    vCA_Interface_SignalStatus_ACC_RiTgt_03_Typ();
    vCA_Interface_SignalValue_ACC_RiTgt_03_Typ();
    vCA_Interface_SignalStatus_ACC_RiTargrt_03_Detn();
    vCA_Interface_SignalValue_ACC_RiTargrt_03_Detn();
    vCA_Interface_SignalStatus_ACC_RiTgt_03_Dx();
    vCA_Interface_SignalValue_ACC_RiTgt_03_Dx();
    vCA_Interface_SignalStatus_ACC_LeTgt_03_Typ();
    vCA_Interface_SignalValue_ACC_LeTgt_03_Typ();
    vCA_Interface_SignalStatus_ACC_RiTgt_03_Dy();
    vCA_Interface_SignalValue_ACC_RiTgt_03_Dy();
    vCA_Interface_SignalStatus_ACC_LeTargrt_03_Detn();
    vCA_Interface_SignalValue_ACC_LeTargrt_03_Detn();
    vCA_Interface_SignalStatus_ACC_LeTgt_03_Dx();
    vCA_Interface_SignalValue_ACC_LeTgt_03_Dx();
    vCA_Interface_SignalStatus_ACC_PotentialTgt_02_Dx();
    vCA_Interface_SignalValue_ACC_PotentialTgt_02_Dx();
    vCA_Interface_SignalStatus_ACC_LeTgt_03_Dy();
    vCA_Interface_SignalValue_ACC_LeTgt_03_Dy();
    vCA_Interface_SignalStatus_ACC_PotentialTgt_02_Heading();
    vCA_Interface_SignalValue_ACC_PotentialTgt_02_Heading();
    vCA_Interface_SignalStatus_ACC_PotentialTgt_02_Typ();
    vCA_Interface_SignalValue_ACC_PotentialTgt_02_Typ();
    vCA_Interface_SignalStatus_ACC_PotentialTgt_02_Detn();
    vCA_Interface_SignalValue_ACC_PotentialTgt_02_Detn();
    vCA_Interface_SignalStatus_ACC_PotentialTgt_02_Dy();
    vCA_Interface_SignalValue_ACC_PotentialTgt_02_Dy();


	return ;
}


static void vCA_Interface_MsgCR_FD1_15EValueUpdate(void)
{
    vCA_Interface_SignalStatus_FCTA_Warn();
    vCA_Interface_SignalValue_FCTA_Warn();
    vCA_Interface_SignalStatus_FCTBTrig();
    vCA_Interface_SignalValue_FCTBTrig();


	return ;
}


static void vCA_Interface_MsgIFC_FD3_2CFValueUpdate(void)
{
    vCA_Interface_SignalStatus_IDC_L2_TurnLightReq();
    vCA_Interface_SignalValue_IDC_L2_TurnLightReq();
    vCA_Interface_SignalStatus_HWA_WarnInfoDisp();
    vCA_Interface_SignalValue_HWA_WarnInfoDisp();
    vCA_Interface_SignalStatus_MRC_InterSysInfoDisp();
    vCA_Interface_SignalValue_MRC_InterSysInfoDisp();
    vCA_Interface_SignalStatus_HWA_ALC_Trig();
    vCA_Interface_SignalValue_HWA_ALC_Trig();
    vCA_Interface_SignalStatus_Stop_Mark_Detn();
    vCA_Interface_SignalValue_Stop_Mark_Detn();
    vCA_Interface_SignalStatus_Stop_Mark_Dx();
    vCA_Interface_SignalValue_Stop_Mark_Dx();
    vCA_Interface_SignalStatus_Zebra_Mark_Detn();
    vCA_Interface_SignalValue_Zebra_Mark_Detn();
    vCA_Interface_SignalStatus_Zebra_Mark_Dx();
    vCA_Interface_SignalValue_Zebra_Mark_Dx();
    vCA_Interface_SignalStatus_Grid_Mark_Detn();
    vCA_Interface_SignalValue_Grid_Mark_Detn();
    vCA_Interface_SignalStatus_Grid_Mark_Dx();
    vCA_Interface_SignalValue_Grid_Mark_Dx();
    vCA_Interface_SignalStatus_HWA_InhibitWarn();
    vCA_Interface_SignalValue_HWA_InhibitWarn();
    vCA_Interface_SignalStatus_IFC_Line01_Source();
    vCA_Interface_SignalValue_IFC_Line01_Source();
    vCA_Interface_SignalStatus_IFC_Line02_Source();
    vCA_Interface_SignalValue_IFC_Line02_Source();
    vCA_Interface_SignalStatus_TSRSpdLim();
    vCA_Interface_SignalValue_TSRSpdLim();
    vCA_Interface_SignalStatus_HWA_TakOver_Req();
    vCA_Interface_SignalValue_HWA_TakOver_Req();
    vCA_Interface_SignalStatus_AutoSpdSetSwt_Resp();
    vCA_Interface_SignalValue_AutoSpdSetSwt_Resp();


	return ;
}


static void vCA_Interface_MsgACC_FD3_2B4ValueUpdate(void)
{
    vCA_Interface_SignalStatus_NOH_Sts();
    vCA_Interface_SignalValue_NOH_Sts();
    vCA_Interface_SignalStatus_NOH_SysInfoDisplay();
    vCA_Interface_SignalValue_NOH_SysInfoDisplay();


	return ;
}


static void vCA_Interface_MsgBCM1_319ValueUpdate(void)
{
    vCA_Interface_SignalStatus_DrvDoorSts();
    vCA_Interface_SignalValue_DrvDoorSts();
    vCA_Interface_SignalStatus_BrkPedalSts_BCM();
    vCA_Interface_SignalValue_BrkPedalSts_BCM();


	return ;
}


static void vCA_Interface_MsgBCM3_345ValueUpdate(void)
{
    vCA_Interface_SignalStatus_DrvDoorLockSts();
    vCA_Interface_SignalValue_DrvDoorLockSts();


	return ;
}


static void vCA_Interface_MsgT_BOX_FD10_2F0ValueUpdate(void)
{
    vCA_Interface_SignalStatus_V2X_RLVW();
    vCA_Interface_SignalValue_V2X_RLVW();


	return ;
}


static void vCA_Interface_MsgECM24_350ValueUpdate(void)
{
    vCA_Interface_SignalStatus_EngOilPres();
    vCA_Interface_SignalValue_EngOilPres();
    vCA_Interface_SignalStatus_EngOilTemp();
    vCA_Interface_SignalValue_EngOilTemp();


	return ;
}


static void vCA_Interface_MsgBCM12_238ValueUpdate(void)
{
    vCA_Interface_SignalStatus_SrPosn_VR_APP();
    vCA_Interface_SignalValue_SrPosn_VR_APP();


	return ;
}


static void vCA_Interface_MsgF_PBOX1_19BValueUpdate(void)
{
    vCA_Interface_SignalStatus_LowBeamSts_F_PBOX();
    vCA_Interface_SignalValue_LowBeamSts_F_PBOX();


	return ;
}


static void vCA_Interface_MsgHCM_L2_304ValueUpdate(void)
{
    vCA_Interface_SignalStatus_LeftLightShowSts();
    vCA_Interface_SignalValue_LeftLightShowSts();


	return ;
}

static void vCA_Interface_AllMsgTimeoutFlagUpdate(void)
{
    vCA_Interface_MsgTimeoutStatus_CSA3_244();
    vCA_Interface_MsgTimeoutStatus_EEM1_2A8();
    vCA_Interface_MsgTimeoutStatus_ESP2_145();
    vCA_Interface_MsgTimeoutStatus_ESP_FD2_137();
    vCA_Interface_MsgTimeoutStatus_HUD1_325();
    vCA_Interface_MsgTimeoutStatus_ECM3_371();
    vCA_Interface_MsgTimeoutStatus_CSA2_A1();
    vCA_Interface_MsgTimeoutStatus_ECM16_2D4();
    vCA_Interface_MsgTimeoutStatus_AC2_385();
    vCA_Interface_MsgTimeoutStatus_ECM_PT6_290();
    vCA_Interface_MsgTimeoutStatus_ABM2_245();
    vCA_Interface_MsgTimeoutStatus_RSDS_FD1_16F();
    vCA_Interface_MsgTimeoutStatus_IFC_FD5_19F();
    vCA_Interface_MsgTimeoutStatus_IFC_FD6_222();
    vCA_Interface_MsgTimeoutStatus_ACC_FD2_2AB();
    vCA_Interface_MsgTimeoutStatus_IFC_FD2_23D();
    vCA_Interface_MsgTimeoutStatus_AEB_FD2_227();
    vCA_Interface_MsgTimeoutStatus_CR_FD1_15E();
    vCA_Interface_MsgTimeoutStatus_IFC_FD3_2CF();
    vCA_Interface_MsgTimeoutStatus_ACC_FD3_2B4();
    vCA_Interface_MsgTimeoutStatus_BCM1_319();
    vCA_Interface_MsgTimeoutStatus_BCM3_345();
    vCA_Interface_MsgTimeoutStatus_T_BOX_FD10_2F0();
    vCA_Interface_MsgTimeoutStatus_ECM24_350();
    vCA_Interface_MsgTimeoutStatus_BCM12_238();
    vCA_Interface_MsgTimeoutStatus_F_PBOX1_19B();
    vCA_Interface_MsgTimeoutStatus_HCM_L2_304();

    
	return ;
}
static void vCA_Interface_AllMsgValueUpdate(void)
{
    vCA_Interface_MsgCSA3_244ValueUpdate();
    vCA_Interface_MsgEEM1_2A8ValueUpdate();
    vCA_Interface_MsgESP2_145ValueUpdate();
    vCA_Interface_MsgESP_FD2_137ValueUpdate();
    vCA_Interface_MsgHUD1_325ValueUpdate();
    vCA_Interface_MsgECM3_371ValueUpdate();
    vCA_Interface_MsgCSA2_A1ValueUpdate();
    vCA_Interface_MsgECM16_2D4ValueUpdate();
    vCA_Interface_MsgAC2_385ValueUpdate();
    vCA_Interface_MsgECM_PT6_290ValueUpdate();
    vCA_Interface_MsgABM2_245ValueUpdate();
    vCA_Interface_MsgRSDS_FD1_16FValueUpdate();
    vCA_Interface_MsgIFC_FD5_19FValueUpdate();
    vCA_Interface_MsgIFC_FD6_222ValueUpdate();
    vCA_Interface_MsgACC_FD2_2ABValueUpdate();
    vCA_Interface_MsgIFC_FD2_23DValueUpdate();
    vCA_Interface_MsgAEB_FD2_227ValueUpdate();
    vCA_Interface_MsgCR_FD1_15EValueUpdate();
    vCA_Interface_MsgIFC_FD3_2CFValueUpdate();
    vCA_Interface_MsgACC_FD3_2B4ValueUpdate();
    vCA_Interface_MsgBCM1_319ValueUpdate();
    vCA_Interface_MsgBCM3_345ValueUpdate();
    vCA_Interface_MsgT_BOX_FD10_2F0ValueUpdate();
    vCA_Interface_MsgECM24_350ValueUpdate();
    vCA_Interface_MsgBCM12_238ValueUpdate();
    vCA_Interface_MsgF_PBOX1_19BValueUpdate();
    vCA_Interface_MsgHCM_L2_304ValueUpdate();


	return ;
}

void vCA_Interface_msTask(void)
{
	vCA_Interface_AllMsgTimeoutFlagUpdate();
	vCA_Interface_AllMsgValueUpdate();

    IPC_API_AppMsgTransmit((uint8)M2S_CA_CSA3_244_RESP,(uint8 *)&IpcSend_stCA_DATA_CSA3_244_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptCSA3_244_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_EEM1_2A8_RESP,(uint8 *)&IpcSend_stCA_DATA_EEM1_2A8_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptEEM1_2A8_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_ESP2_145_RESP,(uint8 *)&IpcSend_stCA_DATA_ESP2_145_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptESP2_145_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_ESP2_137_RESP,(uint8 *)&IpcSend_stCA_DATA_ESP2_137_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptESP2_137_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_HUD1_325_RESP,(uint8 *)&IpcSend_stCA_DATA_HUD1_325_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptHUD1_325_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_ECM3_371_RESP,(uint8 *)&IpcSend_stCA_DATA_ECM3_371_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptECM3_371_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_CSA2_A1_RESP,(uint8 *)&IpcSend_stCA_DATA_CSA2_A1_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptCSA2_A1_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_ECM16_2D4_RESP,(uint8 *)&IpcSend_stCA_DATA_ECM16_2D4_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptECM16_2D4_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_AC2_385_RESP,(uint8 *)&IpcSend_stCA_DATA_AC2_385_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptAC2_385_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_ECM_PT6_290_RESP,(uint8 *)&IpcSend_stCA_DATA_ECM_PT6_290_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptECM_PT6_290_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_ABM2_245_RESP,(uint8 *)&IpcSend_stCA_DATA_ABM2_245_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptABM2_245_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_RSDS_FD1_16F_RESP,(uint8 *)&IpcSend_stCA_DATA_RSDS_FD1_16F_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptRSDS_FD1_16F_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_IFC_FD5_19F_RESP,(uint8 *)&IpcSend_stCA_DATA_IFC_FD5_19F_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptIFC_FD5_19F_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_IFC_FD6_222_RESP,(uint8 *)&IpcSend_stCA_DATA_IFC_FD6_222_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptIFC_FD6_222_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_ACC_FD2_2AB_RESP,(uint8 *)&IpcSend_stCA_DATA_ACC_FD2_2AB_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptACC_FD2_2AB_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_IFC_FD2_23D_RESP,(uint8 *)&IpcSend_stCA_DATA_IFC_FD2_23D_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptIFC_FD2_23D_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_AEB_FD2_227_RESP,(uint8 *)&IpcSend_stCA_DATA_AEB_FD2_227_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptAEB_FD2_227_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_CR_FD1_15E_RESP,(uint8 *)&IpcSend_stCA_DATA_CR_FD1_15E_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptCR_FD1_15E_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_IFC_FD3_2CF_RESP,(uint8 *)&IpcSend_stCA_DATA_IFC_FD3_2CF_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptIFC_FD3_2CF_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_ACC_FD3_2B4_RESP,(uint8 *)&IpcSend_stCA_DATA_ACC_FD3_2B4_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptACC_FD3_2B4_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_BCM1_319_RESP,(uint8 *)&IpcSend_stCA_DATA_BCM1_319_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptBCM1_319_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_BCM3_345_RESP,(uint8 *)&IpcSend_stCA_DATA_BCM3_345_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptBCM3_345_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_T_Box_FD10_2F0_RESP,(uint8 *)&IpcSend_stCA_DATA_T_Box_FD10_2F0_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptT_Box_FD10_2F0_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_ECM24_350_RESP,(uint8 *)&IpcSend_stCA_DATA_ECM24_350_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptECM24_350_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_BCM12_238_RESP,(uint8 *)&IpcSend_stCA_DATA_BCM12_238_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptBCM12_238_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_F_PBOX1_19B_RESP,(uint8 *)&IpcSend_stCA_DATA_F_PBOX1_19B_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptF_PBOX1_19B_t),FALSE);
    IPC_API_AppMsgTransmit((uint8)M2S_CA_HCM_L2_304_RESP,(uint8 *)&IpcSend_stCA_DATA_HCM_L2_304_Inf,(uint16)sizeof(IPC_M2S_ClusterAppCANAdaptHCM_L2_304_t),FALSE);


	return ;
}



#define SWC_CA_STOP_SEC_CODE
#include "SWC_CA_MemMap.h"

/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/

