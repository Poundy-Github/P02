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
/**
 **********************************************************************************************************************
 * @file:      MissingDTC_Cfg.c
 * @author:    Nobo
 * @date:      2020-9-26
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-9-26
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "MissingDTC_Cfg.h"
#include "Rte_Can_Server.h"
#include "VConfig_Cfg.h"

static boolean GlobalFunction(void);

static uint8 DTC_EnableFunction_C10087(void);
static uint8 DTC_EnableFunction_C12287(void);
static uint8 DTC_EnableFunction_C10187(void);
static uint8 DTC_EnableFunction_C15187(void);
static uint8 DTC_EnableFunction_C24187(void);
static uint8 DTC_EnableFunction_C24287(void);
static uint8 DTC_EnableFunction_D10B87(void);
static uint8 DTC_EnableFunction_D02687(void);
static uint8 DTC_EnableFunction_C14087(void);
static uint8 DTC_EnableFunction_C16487(void);
static uint8 DTC_EnableFunction_C14687(void);
static uint8 DTC_EnableFunction_C13187(void);
static uint8 DTC_EnableFunction_C12887(void);
static uint8 DTC_EnableFunction_C20887(void);
static uint8 DTC_EnableFunction_C19987(void);
static uint8 DTC_EnableFunction_C20087(void);
static uint8 DTC_EnableFunction_C24687(void);
static uint8 DTC_EnableFunction_C24787(void);
static uint8 DTC_EnableFunction_C24387(void);
static uint8 DTC_EnableFunction_C2B387(void);
static uint8 DTC_EnableFunction_C19887(void);
static uint8 DTC_EnableFunction_C12787(void);
static uint8 DTC_EnableFunction_C29387(void);
static uint8 DTC_EnableFunction_C11187(void);
static uint8 DTC_EnableFunction_C1BB87(void);
static uint8 DTC_EnableFunction_D10887(void);
static uint8 DTC_EnableFunction_D10987(void);
static uint8 DTC_EnableFunction_D00487(void);
static uint8 DTC_EnableFunction_C10487(void);
static uint8 DTC_EnableFunction_C14387(void);
static uint8 DTC_EnableFunction_D00987(void);
static uint8 DTC_EnableFunction_C23087(void);
static uint8 DTC_EnableFunction_C15C87(void);
static uint8 DTC_EnableFunction_C11587(void);
static uint8 DTC_EnableFunction_D01587(void);
static uint8 DTC_EnableFunction_C14187(void);
static uint8 DTC_EnableFunction_D02987(void);
static uint8 DTC_EnableFunction_C11487(void);
static uint8 DTC_EnableFunction_C15887(void);
static uint8 DTC_EnableFunction_C23387(void);
static uint8 DTC_EnableFunction_C2B587(void);
static uint8 DTC_EnableFunction_D10687(void);
static uint8 DTC_EnableFunction_C25E87(void);
static uint8 DTC_EnableFunction_D12387(void);

static uint8 DTC_JudgeFunction_C10087(uint8 cfgId);
static uint8 DTC_JudgeFunction_C12287(uint8 cfgId);
static uint8 DTC_JudgeFunction_C10187(uint8 cfgId);
static uint8 DTC_JudgeFunction_C15187(uint8 cfgId);
static uint8 DTC_JudgeFunction_C24187(uint8 cfgId);
static uint8 DTC_JudgeFunction_C24287(uint8 cfgId);
static uint8 DTC_JudgeFunction_D10B87(uint8 cfgId);
static uint8 DTC_JudgeFunction_D02687(uint8 cfgId);
static uint8 DTC_JudgeFunction_C14087(uint8 cfgId);
static uint8 DTC_JudgeFunction_C16487(uint8 cfgId);
static uint8 DTC_JudgeFunction_C14687(uint8 cfgId);
static uint8 DTC_JudgeFunction_C13187(uint8 cfgId);
static uint8 DTC_JudgeFunction_C12887(uint8 cfgId);
static uint8 DTC_JudgeFunction_C20887(uint8 cfgId);
static uint8 DTC_JudgeFunction_C19987(uint8 cfgId);
static uint8 DTC_JudgeFunction_C20087(uint8 cfgId);
static uint8 DTC_JudgeFunction_C24687(uint8 cfgId);
static uint8 DTC_JudgeFunction_C24787(uint8 cfgId);
static uint8 DTC_JudgeFunction_C24387(uint8 cfgId);
static uint8 DTC_JudgeFunction_C2B387(uint8 cfgId);
static uint8 DTC_JudgeFunction_C19887(uint8 cfgId);
static uint8 DTC_JudgeFunction_C12787(uint8 cfgId);
static uint8 DTC_JudgeFunction_C29387(uint8 cfgId);
static uint8 DTC_JudgeFunction_C11187(uint8 cfgId);
static uint8 DTC_JudgeFunction_C1BB87(uint8 cfgId);
static uint8 DTC_JudgeFunction_D10887(uint8 cfgId);
static uint8 DTC_JudgeFunction_D10987(uint8 cfgId);
static uint8 DTC_JudgeFunction_D00487(uint8 cfgId);
static uint8 DTC_JudgeFunction_C10487(uint8 cfgId);
static uint8 DTC_JudgeFunction_C14387(uint8 cfgId);
static uint8 DTC_JudgeFunction_D00987(uint8 cfgId);
static uint8 DTC_JudgeFunction_C23087(uint8 cfgId);
static uint8 DTC_JudgeFunction_C15C87(uint8 cfgId);
static uint8 DTC_JudgeFunction_C11587(uint8 cfgId);
static uint8 DTC_JudgeFunction_D01587(uint8 cfgId);
static uint8 DTC_JudgeFunction_C14187(uint8 cfgId);
static uint8 DTC_JudgeFunction_D02987(uint8 cfgId);
static uint8 DTC_JudgeFunction_C11487(uint8 cfgId);
static uint8 DTC_JudgeFunction_C15887(uint8 cfgId);
static uint8 DTC_JudgeFunction_C23387(uint8 cfgId);
static uint8 DTC_JudgeFunction_C2B587(uint8 cfgId);
static uint8 DTC_JudgeFunction_D10687(uint8 cfgId);
static uint8 DTC_JudgeFunction_C25E87(uint8 cfgId);
static uint8 DTC_JudgeFunction_D12387(uint8 cfgId);

static Std_ReturnType DTC_ReportFunction_C10087(uint8 status);
static Std_ReturnType DTC_ReportFunction_C12287(uint8 status);
static Std_ReturnType DTC_ReportFunction_C10187(uint8 status);
static Std_ReturnType DTC_ReportFunction_C15187(uint8 status);
static Std_ReturnType DTC_ReportFunction_C24187(uint8 status);
static Std_ReturnType DTC_ReportFunction_C24287(uint8 status);
static Std_ReturnType DTC_ReportFunction_D10B87(uint8 status);
static Std_ReturnType DTC_ReportFunction_D02687(uint8 status);
static Std_ReturnType DTC_ReportFunction_C14087(uint8 status);
static Std_ReturnType DTC_ReportFunction_C16487(uint8 status);
static Std_ReturnType DTC_ReportFunction_C14687(uint8 status);
static Std_ReturnType DTC_ReportFunction_C13187(uint8 status);
static Std_ReturnType DTC_ReportFunction_C12887(uint8 status);
static Std_ReturnType DTC_ReportFunction_C20887(uint8 status);
static Std_ReturnType DTC_ReportFunction_C19987(uint8 status);
static Std_ReturnType DTC_ReportFunction_C20087(uint8 status);
static Std_ReturnType DTC_ReportFunction_C24687(uint8 status);
static Std_ReturnType DTC_ReportFunction_C24787(uint8 status);
static Std_ReturnType DTC_ReportFunction_C24387(uint8 status);
static Std_ReturnType DTC_ReportFunction_C2B387(uint8 status);
static Std_ReturnType DTC_ReportFunction_C19887(uint8 status);
static Std_ReturnType DTC_ReportFunction_C12787(uint8 status);
static Std_ReturnType DTC_ReportFunction_C29387(uint8 status);
static Std_ReturnType DTC_ReportFunction_C11187(uint8 status);
static Std_ReturnType DTC_ReportFunction_C1BB87(uint8 status);
static Std_ReturnType DTC_ReportFunction_D10887(uint8 status);
static Std_ReturnType DTC_ReportFunction_D10987(uint8 status);
static Std_ReturnType DTC_ReportFunction_D00487(uint8 status);
static Std_ReturnType DTC_ReportFunction_C10487(uint8 status);
static Std_ReturnType DTC_ReportFunction_C14387(uint8 status);
static Std_ReturnType DTC_ReportFunction_D00987(uint8 status);
static Std_ReturnType DTC_ReportFunction_C23087(uint8 status);
static Std_ReturnType DTC_ReportFunction_C15C87(uint8 status);
static Std_ReturnType DTC_ReportFunction_C11587(uint8 status);
static Std_ReturnType DTC_ReportFunction_D01587(uint8 status);
static Std_ReturnType DTC_ReportFunction_C14187(uint8 status);
static Std_ReturnType DTC_ReportFunction_D02987(uint8 status);
static Std_ReturnType DTC_ReportFunction_C11487(uint8 status);
static Std_ReturnType DTC_ReportFunction_C15887(uint8 status);
static Std_ReturnType DTC_ReportFunction_C23387(uint8 status);
static Std_ReturnType DTC_ReportFunction_C2B587(uint8 status);
static Std_ReturnType DTC_ReportFunction_D10687(uint8 status);
static Std_ReturnType DTC_ReportFunction_C25E87(uint8 status);
static Std_ReturnType DTC_ReportFunction_D12387(uint8 status);

#define Can_Server_START_SEC_CONST_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static const MD_DtcCfg md_dtcCfgs[MD_DTC_NUMBER] =
{
    {DTC_EnableFunction_C10087, DTC_JudgeFunction_C10087, DTC_ReportFunction_C10087, 100u},/*C10087*/
    {DTC_EnableFunction_C12287, DTC_JudgeFunction_C12287, DTC_ReportFunction_C12287, 100u},/*C12287*/
    {DTC_EnableFunction_C10187, DTC_JudgeFunction_C10187, DTC_ReportFunction_C10187, 100u},/*C10187*/
    {DTC_EnableFunction_C15187, DTC_JudgeFunction_C15187, DTC_ReportFunction_C15187, 100u},/*C15187*/
    {DTC_EnableFunction_C24187, DTC_JudgeFunction_C24187, DTC_ReportFunction_C24187, 100u},/*C24187*/
    {DTC_EnableFunction_C24287, DTC_JudgeFunction_C24287, DTC_ReportFunction_C24287, 100u},/*C24287*/
    {DTC_EnableFunction_D10B87, DTC_JudgeFunction_D10B87, DTC_ReportFunction_D10B87, 100u},/*D10B87*/
    {DTC_EnableFunction_D02687, DTC_JudgeFunction_D02687, DTC_ReportFunction_D02687, 100u},/*D02687*/
    {DTC_EnableFunction_C14087, DTC_JudgeFunction_C14087, DTC_ReportFunction_C14087, 100u},/*C14087*/
    {DTC_EnableFunction_C16487, DTC_JudgeFunction_C16487, DTC_ReportFunction_C16487, 100u},/*C16487*/
    {DTC_EnableFunction_C14687, DTC_JudgeFunction_C14687, DTC_ReportFunction_C14687, 100u},/*C14687*/
    {DTC_EnableFunction_C13187, DTC_JudgeFunction_C13187, DTC_ReportFunction_C13187, 100u},/*C13187*/
    {DTC_EnableFunction_C12887, DTC_JudgeFunction_C12887, DTC_ReportFunction_C12887, 100u},/*C12887*/
    {DTC_EnableFunction_C20887, DTC_JudgeFunction_C20887, DTC_ReportFunction_C20887, 100u},/*C20887*/
    {DTC_EnableFunction_C19987, DTC_JudgeFunction_C19987, DTC_ReportFunction_C19987, 100u},/*C19987*/
    {DTC_EnableFunction_C20087, DTC_JudgeFunction_C20087, DTC_ReportFunction_C20087, 100u},/*C20087*/
    {DTC_EnableFunction_C24687, DTC_JudgeFunction_C24687, DTC_ReportFunction_C24687, 100u},/*C24687*/
    {DTC_EnableFunction_C24787, DTC_JudgeFunction_C24787, DTC_ReportFunction_C24787, 100u},/*C24787*/
    {DTC_EnableFunction_C24387, DTC_JudgeFunction_C24387, DTC_ReportFunction_C24387, 100u},/*C24387*/
    {DTC_EnableFunction_C2B387, DTC_JudgeFunction_C2B387, DTC_ReportFunction_C2B387, 100u},/*C2B387*/
    {DTC_EnableFunction_C19887, DTC_JudgeFunction_C19887, DTC_ReportFunction_C19887, 100u},/*C19887*/
    {DTC_EnableFunction_C12787, DTC_JudgeFunction_C12787, DTC_ReportFunction_C12787, 100u},/*C12787*/
    {DTC_EnableFunction_C29387, DTC_JudgeFunction_C29387, DTC_ReportFunction_C29387, 100u},/*C29387*/
    {DTC_EnableFunction_C11187, DTC_JudgeFunction_C11187, DTC_ReportFunction_C11187, 100u},/*C11187*/
    {DTC_EnableFunction_C1BB87, DTC_JudgeFunction_C1BB87, DTC_ReportFunction_C1BB87, 100u},/*C1BB87*/
    {DTC_EnableFunction_D10887, DTC_JudgeFunction_D10887, DTC_ReportFunction_D10887, 100u},/*D10887*/
    {DTC_EnableFunction_D10987, DTC_JudgeFunction_D10987, DTC_ReportFunction_D10987, 100u},/*D10987*/
    {DTC_EnableFunction_D00487, DTC_JudgeFunction_D00487, DTC_ReportFunction_D00487, 100u},/*D00487*/
    {DTC_EnableFunction_C10487, DTC_JudgeFunction_C10487, DTC_ReportFunction_C10487, 100u},/*C10487*/
    {DTC_EnableFunction_C14387, DTC_JudgeFunction_C14387, DTC_ReportFunction_C14387, 100u},/*C14387*/
    {DTC_EnableFunction_D00987, DTC_JudgeFunction_D00987, DTC_ReportFunction_D00987, 100u},/*D00987*/
    {DTC_EnableFunction_C23087, DTC_JudgeFunction_C23087, DTC_ReportFunction_C23087, 100u},/*C23087*/
    {DTC_EnableFunction_C15C87, DTC_JudgeFunction_C15C87, DTC_ReportFunction_C15C87, 100u},/*C15C87*/
    {DTC_EnableFunction_C11587, DTC_JudgeFunction_C11587, DTC_ReportFunction_C11587, 100u},/*C11587*/
    {DTC_EnableFunction_D01587, DTC_JudgeFunction_D01587, DTC_ReportFunction_D01587, 100u},/*D01587*/
    {DTC_EnableFunction_C14187, DTC_JudgeFunction_C14187, DTC_ReportFunction_C14187, 100u},/*C14187*/
    {DTC_EnableFunction_D02987, DTC_JudgeFunction_D02987, DTC_ReportFunction_D02987, 100u},/*D02987*/
    {DTC_EnableFunction_C11487, DTC_JudgeFunction_C11487, DTC_ReportFunction_C11487, 100u},/*C11487*/
    {DTC_EnableFunction_C15887, DTC_JudgeFunction_C15887, DTC_ReportFunction_C15887, 100u},/*C15887*/
    {DTC_EnableFunction_C23387, DTC_JudgeFunction_C23387, DTC_ReportFunction_C23387, 100u},/*C23387*/
    {DTC_EnableFunction_C2B587, DTC_JudgeFunction_C2B587, DTC_ReportFunction_C2B587, 100u},/*C2B587*/
    {DTC_EnableFunction_D10687, DTC_JudgeFunction_D10687, DTC_ReportFunction_D10687, 100u},/*D10687*/
    {DTC_EnableFunction_C25E87, DTC_JudgeFunction_C25E87, DTC_ReportFunction_C25E87, 100u},/*C25E87*/
    {DTC_EnableFunction_D12387, DTC_JudgeFunction_D12387, DTC_ReportFunction_D12387, 100u},/*D12387*/
};

#define Can_Server_STOP_SEC_CONST_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define Can_Server_START_SEC_VAR_INIT_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static MD_Dtc md_dtcs[MD_DTC_NUMBER] = { 0 };

#define Can_Server_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define Can_Server_START_SEC_CONST_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static const MD_MessageCfg md_messageCfgs[MD_MESSAGE_NUMBER] =
{
    {1u, 10u, 9u, 8u},/*ECM1*/
    {2u, 10u, 9u, 8u},/*ECM2*/
    {10u, 10u, 9u, 8u},/*ECM3*/
    {10u, 10u, 9u, 8u},/*ECM11*/
    {100u, 10u, 9u, 3u},/*ECM19*/
    {100u, 10u, 9u, 3u},/*ECM20*/
    {2u, 10u, 9u, 8u},/*ESP1*/
    {2u, 10u, 9u, 8u},/*ESP2*/
    {2u, 10u, 9u, 8u},/*ABS3*/
    {2u, 10u, 9u, 8u},/*ESP_FD2*/
    {1u, 10u, 9u, 8u},/*DCT3*/
    {5u, 10u, 9u, 8u},/*DCT7*/
    {5u, 10u, 9u, 8u},/*DCT_FD4*/
    {5u, 10u, 9u, 8u},/*DCT9*/
    {50u, 10u, 9u, 8u},/*ABM1*/
    {10u, 10u, 9u, 8u},/*HC1*/
    {20u, 10u, 9u, 8u},/*HCM_L1*/
    {20u, 10u, 9u, 8u},/*HCM_R1*/
    {50u, 10u, 9u, 8u},/*PPMI1*/
    {10u, 10u, 9u, 8u},/*HCU_PT4*/
    {2u, 10u, 9u, 8u},/*HCU_PT5*/
    {5u, 10u, 9u, 8u},/*HCU_PT7*/
    {5u, 10u, 9u, 8u},/*HCU_PT8*/
    {5u, 10u, 9u, 8u},/*PEPS2*/
    {20u, 10u, 9u, 8u},/*PEPS4*/
    {5u, 10u, 9u, 8u},/*BCM1*/
    {5u, 10u, 9u, 8u},/*BCM3*/
    {10u, 10u, 9u, 8u},/*BCM8*/
    {10u, 10u, 9u, 8u},/*AC1*/
    {10u, 10u, 9u, 8u},/*AC2*/
    {10u, 10u, 9u, 8u},/*AC4*/
    {10u, 10u, 9u, 8u},/*AC6*/
    {10u, 10u, 9u, 8u},/*AC7*/
    {10u, 10u, 9u, 8u},/*GW_FD1*/
    {2u, 10u, 9u, 8u},/*EPS1*/
    {2u, 10u, 9u, 8u},/*EPS_FD1*/
    {2u, 10u, 9u, 8u},/*EPB1*/
    {10u, 10u, 9u, 8u},/*DSM1*/
    {10u, 10u, 9u, 8u},/*DDCM1*/
    {10u, 10u, 9u, 8u},/*PDCM1*/
    {10u, 10u, 9u, 8u},/*SCM1*/
    {1u, 10u, 9u, 8u},/*RHVSM1*/
    {10u, 10u, 9u, 8u},/*RPAS1*/
    {10u, 10u, 9u, 8u},/*FPAS1*/
    {2u, 10u, 9u, 8u},/*HAP_FD1*/
    {5u, 10u, 9u, 8u},/*HAP_FD2*/
    {10u, 10u, 9u, 8u},/*HAP_FD3*/
    {1u, 10u, 9u, 8u},/*APS3*/
    {1u, 10u, 9u, 8u},/*APS1*/
    {5u, 10u, 9u, 8u},/*HAP2*/
    {5u, 10u, 9u, 8u},/*DMS_FD1*/
    {100u, 10u, 9u, 3u},/*T_Box_FD3*/
    {50u, 10u, 9u, 8u},/*TPMS1*/
    {50u, 10u, 9u, 8u},/*TPMS2*/
    {5u, 10u, 9u, 8u},/*HCU_HC3*/
    {20u, 10u, 9u, 8u},/*HCU_HC6*/
    {100u, 10u, 9u, 3u},/*HCU_HC7*/
    {1u, 10u, 9u, 8u},/*HCU_HC16*/
    {1u, 10u, 9u, 8u},/*BMS4*/
    {10u, 10u, 9u, 8u},/*BMS8*/
    {10u, 10u, 9u, 8u},/*BMS35*/
    {100u, 10u, 9u, 3u},/*BMS22*/
    {100u, 10u, 9u, 3u},/*BMS30*/
    {2u, 10u, 9u, 8u},/*BMS65*/
    {20u, 10u, 9u, 8u},/*OBC2*/
    {5u, 10u, 9u, 8u},/*F_PBox1*/
    {5u, 10u, 9u, 8u},/*R_PBox1*/
    {2u, 10u, 9u, 8u},/*AEB_FD1*/
    {5u, 10u, 9u, 8u},/*AEB_FD2*/
    {10u, 10u, 9u, 8u},/*ACC_FD2*/
    {10u, 10u, 9u, 8u},/*ACC_FD3*/
    {10u, 10u, 9u, 8u},/*ACC_FD4*/
    {5u, 10u, 9u, 8u},/*IFC_FD2*/
    {10u, 10u, 9u, 8u},/*IFC_FD3*/
    {5u, 10u, 9u, 8u},/*IFC_FD5*/
    {5u, 10u, 9u, 8u},/*IFC_FD6*/
    {50u, 10u, 9u, 8u},/*CP1*/
    {10u, 10u, 9u, 8u},/*PLG_1*/
    {2u, 10u, 9u, 8u},/*ELD1*/
    {5u, 10u, 9u, 8u},/*STBS1*/
    {5u, 10u, 9u, 8u},/*Trailer1*/
    {10u, 10u, 9u, 8u},/*WPC1*/
    {2u, 10u, 9u, 8u},/*Haldex1*/
    {20u, 10u, 9u, 8u},/*HUD1*/
    {20u, 10u, 9u, 8u},/*AR_HUD1*/
    {2u, 10u, 9u, 8u},/*RSDS_FD1*/
    {2u, 10u, 9u, 8u},/*CR_FD1*/
    {1u, 10u, 9u, 8u},/*HCU_FD1*/
    {5u, 10u, 9u, 8u},/*CSA3*/
    {2u, 10u, 9u, 8u},/*IBOOSTER_FD2*/
    {1u, 10u, 9u, 8u},/*DHT_FD1*/
    {2u, 10u, 9u, 8u},/*TOD1*/
    {10u, 10u, 9u, 8u},/*DWD1*/
};

#define Can_Server_STOP_SEC_CONST_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Can_Server_START_SEC_VAR_INIT_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static MD_Message md_messages[MD_MESSAGE_NUMBER] = {0};

#define Can_Server_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define Can_Server_START_SEC_CONST_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static const MD_PduCfg md_pduCfgs[MD_PDU_NUMBER] =
{
    {MD_PDU_NO_ID, 0u}, /*NMRange*/
    {MD_PDU_NO_ID, 0u}, /*HUT_Phy_Req_Tp*/
    {MD_PDU_NO_ID, 0u}, /*HUT_Phy_Req_Tp*/
    {MD_PDU_NO_ID, 0u}, /*DiagFuncReq_Tp*/
    {MD_PDU_NO_ID, 0u}, /*DiagFuncReq_Tp*/
    {MD_PDU_NO_ID, 0u}, /*GW_Sync_Req_Sc*/
    {MD_MESSAGE_BMS30, 8u}, /*BMS30*/
    {MD_MESSAGE_T_BOX_FD3, 16u}, /*T_BOX_FD3_Sc*/
    {MD_PDU_NO_ID, 0u}, /*AMP3*/
    {MD_PDU_NO_ID, 0u}, /*AMP2_Sc*/
    {MD_PDU_NO_ID, 0u}, /*AMP1*/
    {MD_MESSAGE_HCU_HC7, 8u}, /*HCU_HC7*/
    {MD_MESSAGE_BMS22, 8u}, /*BMS22*/
    {MD_MESSAGE_ECM20, 8u}, /*ECM20*/
    {MD_MESSAGE_ECM19, 8u}, /*ECM19*/
    {MD_PDU_NO_ID, 0u}, /*BMS66*/
    {MD_MESSAGE_TPMS2, 16u}, /*TPMS2_Sc*/
    {MD_MESSAGE_AC2, 8u}, /*AC2*/
    {MD_MESSAGE_ECM3, 8u}, /*ECM3*/
    {MD_MESSAGE_CP1, 8u}, /*CP1*/
    {MD_PDU_NO_ID, 0u}, /*RWPC1*/
    {MD_MESSAGE_PPMI1, 8u}, /*PPMI1*/
    {MD_PDU_NO_ID, 0u}, /*BMS19*/
    {MD_MESSAGE_ABM1, 16u}, /*ABM1_Sc*/
    {MD_PDU_NO_ID, 0u}, /*ECM24*/
    {MD_PDU_NO_ID, 0u}, /*PPMI_P1*/
    {MD_MESSAGE_BCM3, 16u}, /*BCM3_Sc*/
    {MD_MESSAGE_TPMS1, 16u}, /*TPMS1_Sc*/
    {MD_MESSAGE_HUD1, 8u}, /*HUD1*/
    {MD_MESSAGE_BCM1, 16u}, /*BCM1_Sc*/
    {MD_MESSAGE_HCU_HC6, 8u}, /*HCU_HC6*/
    {MD_PDU_NO_ID, 0u}, /*DOCK1*/
    {MD_PDU_NO_ID, 0u}, /*BCM19*/
    {MD_PDU_NO_ID, 0u}, /*RSDS_FD2*/
    {MD_PDU_NO_ID, 0u}, /*BCM11*/
    {MD_PDU_NO_ID, 0u}, /*ESCL2*/
    {MD_MESSAGE_PEPS4, 8u}, /*PEPS4*/
    {MD_PDU_NO_ID, 0u}, /*AC3*/
    {MD_MESSAGE_HCU_PT4, 8u}, /*HCU_PT4*/
    {MD_MESSAGE_AC6, 8u}, /*AC6*/
    {MD_PDU_NO_ID, 0u}, /*DDCM3*/
    {MD_PDU_NO_ID, 0u}, /*T_Box_FD10*/
    {MD_PDU_NO_ID, 0u}, /*EDC1*/
    {MD_PDU_NO_ID, 0u}, /*ECM16*/
    {MD_MESSAGE_ECM11, 8u}, /*ECM11*/
    {MD_PDU_NO_ID, 0u}, /*AMP4_ANC1*/
    {MD_MESSAGE_AC7, 8u}, /*AC7*/
    {MD_MESSAGE_IFC_FD3, 64u}, /*IFC_FD3*/
    {MD_PDU_NO_ID, 0u}, /*DSC4*/
    {MD_MESSAGE_PDCM1, 8u}, /*PDCM1*/
    {MD_MESSAGE_AC4, 8u}, /*AC4*/
    {MD_MESSAGE_DDCM1, 8u}, /*DDCM1*/
    {MD_MESSAGE_BMS35, 8u}, /*BMS35*/
    {MD_MESSAGE_DSM1, 8u}, /*DSM1*/
    {MD_MESSAGE_GW_FD1, 64u}, /*GW_FD1*/
    {MD_MESSAGE_WPC1, 8u}, /*WPC1*/
    {MD_MESSAGE_DWD1, 8u}, /*DWD1*/
    {MD_MESSAGE_ACC_FD4, 64u}, /*ACC_FD4*/
    {MD_MESSAGE_ACC_FD3, 64u}, /*ACC_FD3*/
    {MD_MESSAGE_ACC_FD2, 64u}, /*ACC_FD2_Sc*/
    {MD_PDU_NO_ID, 0u}, /*EEM1*/
    {MD_PDU_NO_ID, 0u}, /*BCM14*/
    {MD_MESSAGE_BCM8, 8u}, /*BCM8*/
    {MD_MESSAGE_AC1, 8u}, /*AC1*/
    {MD_PDU_NO_ID, 0u}, /*HAP_FD7*/
    {MD_MESSAGE_HAP_FD3, 64u}, /*HAP_FD3*/
    {MD_MESSAGE_PEPS2, 8u}, /*PEPS2*/
    {MD_PDU_NO_ID, 0u}, /*ECM_PT6*/
    {MD_PDU_NO_ID, 0u}, /*BCM7*/
    {MD_PDU_NO_ID, 0u}, /*BCM6*/
    {MD_PDU_NO_ID, 0u}, /*HAP_FD6*/
    {MD_PDU_NO_ID, 0u}, /*ALS1*/
    {MD_MESSAGE_BMS8, 8u}, /*BMS8*/
    {MD_PDU_NO_ID, 0u}, /*AC8*/
    {MD_MESSAGE_HAP_FD2, 64u}, /*HAP_FD2*/
    {MD_MESSAGE_TRAILER1, 8u}, /*Trailer1*/
    {MD_MESSAGE_ECM2, 8u}, /*ECM2*/
    {MD_MESSAGE_HCU_HC3, 8u}, /*HCU_HC3*/
    {MD_PDU_NO_ID, 0u}, /*BLE1*/
    {MD_MESSAGE_TOD1, 8u}, /*TOD1*/
    {MD_MESSAGE_HCU_PT7, 8u}, /*HCU_PT7*/
    {MD_PDU_NO_ID, 0u}, /*ABS2*/
    {MD_PDU_NO_ID, 0u}, /*ABM2*/
    {MD_MESSAGE_CSA3, 8u}, /*CSA3*/
    {MD_PDU_NO_ID, 0u}, /*BCM17*/
    {MD_MESSAGE_IFC_FD2, 64u}, /*IFC_FD2_Sc*/
    {MD_PDU_NO_ID, 0u}, /*BCM12*/
    {MD_MESSAGE_DCT_FD4, 64u}, /*DCT_FD4_Sc*/
    {MD_PDU_NO_ID, 0u}, /*ABS1*/
    {MD_MESSAGE_AEB_FD2, 64u}, /*AEB_FD2_Sc*/
    {MD_MESSAGE_IFC_FD6, 64u}, /*IFC_FD6*/
    {MD_PDU_NO_ID, 0u}, /*DCT5*/
    {MD_PDU_NO_ID, 0u}, /*HCU_HP5*/
    {MD_PDU_NO_ID, 0u}, /*T_BOX_FD9*/
    {MD_PDU_NO_ID, 0u}, /*BLE5*/
    {MD_PDU_NO_ID, 0u}, /*BMS_FD14*/
    {MD_PDU_NO_ID, 0u}, /*HCU_HC8*/
    {MD_PDU_NO_ID, 0u}, /*T_BOX_FD4*/
    {MD_PDU_NO_ID, 0u}, /*DOCK2*/
    {MD_MESSAGE_HCU_PT8, 8u}, /*HCU_PT8*/
    {MD_MESSAGE_IFC_FD5, 64u}, /*IFC_FD5*/
    {MD_MESSAGE_R_PBOX1, 16u}, /*R_PBox1_Sc*/
    {MD_MESSAGE_F_PBOX1, 8u}, /*F_PBox1*/
    {MD_MESSAGE_AEB_FD1, 64u}, /*AEB_FD1*/
    {MD_PDU_NO_ID, 0u}, /*ESP8*/
    {MD_MESSAGE_RSDS_FD1, 64u}, /*RSDS_FD1*/
    {MD_MESSAGE_EPB1, 8u}, /*EPB1*/
    {MD_PDU_NO_ID, 0u}, /*CSA1*/
    {MD_MESSAGE_CR_FD1, 64u}, /*CR_FD1*/
    {MD_MESSAGE_HAP_FD1, 64u}, /*HAP_FD1*/
    {MD_MESSAGE_ELD1, 8u}, /*ELD1*/
    {MD_MESSAGE_BMS65, 8u}, /*BMS65*/
    {MD_MESSAGE_HCU_PT5, 8u}, /*HCU_PT5*/
    {MD_MESSAGE_EPS_FD1, 64u}, /*EPS_FD1*/
    {MD_MESSAGE_ESP_FD2, 64u}, /*ESP_FD2_Sc*/
    {MD_PDU_NO_ID, 0u}, /*EBOOSTER_FD1*/
    {MD_MESSAGE_IBOOSTER_FD2, 64u}, /*Ibooster_FD2*/
    {MD_PDU_NO_ID, 0u}, /*HCU_HP6*/
    {MD_PDU_NO_ID, 0u}, /*ECM_PT7*/
    {MD_MESSAGE_ECM1, 8u}, /*ECM1*/
    {MD_PDU_NO_ID, 0u}, /*IFC1*/
    {MD_PDU_NO_ID, 0u}, /*ECM9*/
    {MD_PDU_NO_ID, 0u}, /*HCU_HP8*/
    {MD_MESSAGE_BMS4, 8u}, /*BMS4*/
    {MD_PDU_NO_ID, 0u}, /*ESP11*/
    {MD_PDU_NO_ID, 0u}, /*P2M3*/
    {MD_PDU_NO_ID, 0u}, /*P2M1*/
    {MD_MESSAGE_DCT3, 8u}, /*DCT3*/
    {MD_PDU_NO_ID, 0u}, /*CSA2*/
    {MD_MESSAGE_HCU_HC16, 8u}, /*HCU_HC16*/
    {MD_PDU_NO_ID, 0u}, /*ECM_PT5*/
    {MD_PDU_NO_ID, 0u}, /*ECM7*/
    {MD_PDU_NO_ID, 0u}, /*ECM4*/
    {MD_MESSAGE_HCU_FD1, 64u}, /*HCU_FD1*/
    {MD_PDU_NO_ID, 0u}, /*T_BOX_FD1_Sc*/

};

#define Can_Server_STOP_SEC_CONST_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define Can_Server_START_SEC_VAR_INIT_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static uint8 vConfigData[400] = {0};

#define Can_Server_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define Can_Server_START_SEC_CONST_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

const MD_Cfg md_cfg =
{
    MD_GlobalEnableFuncntion,
    2u,
    MD_DTC_NUMBER,
    md_dtcCfgs,
    md_dtcs,
    MD_MESSAGE_NUMBER,
    md_messageCfgs,
    md_messages,
    MD_PDU_NUMBER,
    md_pduCfgs,
    sizeof(vConfigData),
    vConfigData
};

#define Can_Server_STOP_SEC_CONST_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define Can_Server_START_SEC_VAR_INIT_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

MD_Data md_data = {FALSE};

#define Can_Server_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define Can_Server_START_SEC_CODE
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static uint8 DTC_EnableFunction_C10087(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == MD_VCONFIG_BETWEEN(VCONFIG_KIND_ENGINE_CONTROL_UNIT, 0x01u, 0x07u))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_ECM1);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_ECM2);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_ECM3);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_ECM11);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C10087(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;

    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL4(MD_MESSAGE_ECM1, MD_MESSAGE_ECM2, MD_MESSAGE_ECM3, MD_MESSAGE_ECM11, ret);
        break;

        default:
        break;
    }

    return ret;
}

static uint8 DTC_EnableFunction_C12287(void)
{
    uint8 ret = MD_DTC_DISABLE;
    
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_SERVICE_BRAKE, 0x02u) && \
                MD_VCONFIG_EQUAL1(VCONFIG_KIND_PT_CAN_BUS_TYPE, 0x00u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_ESP1);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_ESP2);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_ABS3);
        ret = MD_DTC_ENABLE_CFG0;
    }
    else if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_SERVICE_BRAKE, 0x02u) && \
                     MD_VCONFIG_EQUAL1(VCONFIG_KIND_PT_CAN_BUS_TYPE, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_ESP_FD2);
        ret = MD_DTC_ENABLE_CFG1;
    }
    else
    {
        /* nothing */
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C12287(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;

    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL3(MD_MESSAGE_ESP1, MD_MESSAGE_ESP2, MD_MESSAGE_ABS3, ret);
        break;

        case MD_DTC_ENABLE_CFG1:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_ESP_FD2, ret);
        break;

        default:
        break;
    }

    return ret;
}

static uint8 DTC_EnableFunction_C10187(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL5(VCONFIG_KIND_TRANSMISSION, 0x07u, 0x26u,0x29u,0x0fu,0x10u) && \
                MD_VCONFIG_EQUAL1(VCONFIG_KIND_PT_CAN_BUS_TYPE, 0x00u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_DCT3);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_DCT7);
        ret = MD_DTC_ENABLE_CFG0;
    }
    else if(TRUE == (MD_VCONFIG_EQUAL5(VCONFIG_KIND_TRANSMISSION, 0x07u, 0x26u,0x29u,0x0fu,0x10u) && \
                MD_VCONFIG_EQUAL1(VCONFIG_KIND_PT_CAN_BUS_TYPE, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_DCT3);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_DCT_FD4);
        ret = MD_DTC_ENABLE_CFG1;
    }
    else if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_TRANSMISSION, 0x13u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_DHT_FD1); 
        ret = MD_DTC_ENABLE_CFG2;
    }
    else if(TRUE == (MD_VCONFIG_EQUAL2(VCONFIG_KIND_TRANSMISSION, 0x27u,0x28u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_DCT_FD4); 
        ret = MD_DTC_ENABLE_CFG3;   
    }
    else if (TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_TRANSMISSION, 0x08u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_DCT9); 
        ret = MD_DTC_ENABLE_CFG4;
    }
    else
    {
        /* do nothing */
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C10187(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;

    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL2(MD_MESSAGE_DCT3, MD_MESSAGE_DCT7, ret);
        break;

        case MD_DTC_ENABLE_CFG1:
        MD_DTC_JUDGE_GENERAL2(MD_MESSAGE_DCT3, MD_MESSAGE_DCT_FD4, ret);
        break;

        case MD_DTC_ENABLE_CFG2:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_DHT_FD1, ret);
        break;

        case MD_DTC_ENABLE_CFG3:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_DCT_FD4, ret);
        break;
        
        case MD_DTC_ENABLE_CFG4:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_DCT9, ret);
        break;

        default:
        break;
    }

    return ret;
}

static uint8 DTC_EnableFunction_C15187(void)
{
    MD_MESSAGE_SET_ENABLED(MD_MESSAGE_ABM1);
    return MD_DTC_ENABLE_CFG0;
}

static uint8 DTC_JudgeFunction_C15187(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;

    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_ABM1, ret);
        break;

        default:
        break;
    }

    return ret;
}

static uint8 DTC_EnableFunction_C24187(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_HEADLAMP_CONTROL_FUNCTION, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HC1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    else if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_HEADLAMP_CONTROL_FUNCTION, 0x02u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HCM_L1);
        ret = MD_DTC_ENABLE_CFG1;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C24187(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_HC1, ret);
        break;

        case MD_DTC_ENABLE_CFG1:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_HCM_L1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C24287(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_HEADLAMP_CONTROL_FUNCTION, 0x02u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HCM_R1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C24287(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_HCM_R1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_D10B87(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_FRT_SEAT_BELT, 0x08u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_PPMI1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_D10B87(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_PPMI1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_D02687(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL3(VCONFIG_KIND_ELECTROMOTOR_POSITION, 0x02u, 0x04u, 0x05u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HCU_PT4);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HCU_PT5);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HCU_PT7);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HCU_PT8);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HCU_FD1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_D02687(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL5(MD_MESSAGE_HCU_PT4, MD_MESSAGE_HCU_PT5, MD_MESSAGE_HCU_PT7, MD_MESSAGE_HCU_PT8, MD_MESSAGE_HCU_FD1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C14087(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL2(VCONFIG_KIND_STARTING_SYSTEM, 0x01u, 0x02u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_PEPS2);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_BCM1);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_BCM3);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_BCM8);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C14087(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL4(MD_MESSAGE_PEPS2, MD_MESSAGE_BCM1, MD_MESSAGE_BCM3, MD_MESSAGE_BCM8, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C16487(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_BETWEEN(VCONFIG_KIND_AIR_CONDITIONER, 0x02u, 0x04u) &&
                MD_VCONFIG_NOT_EQUAL(VCONFIG_KIND_FRAGRANCE_SYSTEM, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_AC1);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_AC2);
        ret = MD_DTC_ENABLE_CFG0;
    }
    else if(TRUE == (MD_VCONFIG_BETWEEN(VCONFIG_KIND_AIR_CONDITIONER, 0x02u, 0x04u) &&
                     MD_VCONFIG_EQUAL1(VCONFIG_KIND_FRAGRANCE_SYSTEM, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_AC1);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_AC2);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_AC4);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_AC6);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_AC7);
        ret = MD_DTC_ENABLE_CFG1;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C16487(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL2(MD_MESSAGE_AC1, MD_MESSAGE_AC2, ret);
        break;

        case MD_DTC_ENABLE_CFG1:
        MD_DTC_JUDGE_GENERAL5(MD_MESSAGE_AC1, MD_MESSAGE_AC2, MD_MESSAGE_AC4, MD_MESSAGE_AC6, MD_MESSAGE_AC7, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C14687(void)
{
    MD_MESSAGE_SET_ENABLED(MD_MESSAGE_GW_FD1);
    return MD_DTC_ENABLE_CFG0;
}

static uint8 DTC_JudgeFunction_C14687(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_GW_FD1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C13187(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_STEERING_SYSTEM, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_EPS1);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_EPS_FD1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    else
    {
        /* do nothing */
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C13187(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        if(
           (md_cfg.messages[MD_MESSAGE_EPS1].status    == MD_MESSAGE_STATUS_MISSING_CONFIRM)
        && (md_cfg.messages[MD_MESSAGE_EPS_FD1].status == MD_MESSAGE_STATUS_MISSING_CONFIRM)
        )
        {
            ret = MD_DTC_JUDGE_RESULT_FAILED;
        }
        else if(
           (md_cfg.messages[MD_MESSAGE_EPS1].status    == MD_MESSAGE_STATUS_OK_CONFIRM)
        || (md_cfg.messages[MD_MESSAGE_EPS_FD1].status == MD_MESSAGE_STATUS_OK_CONFIRM)
        )
        {
            ret = MD_DTC_JUDGE_RESULT_PASSED;
        }
        else
        {
            ret = MD_DTC_JUDGE_RESULT_NOT_READY;
        }
        
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C12887(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_PARKING_BRAKE, 0x02u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_EPB1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C12887(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_EPB1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C20887(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_BETWEEN(VCONFIG_KIND_DRIVER_SEAT, 0x01u, 0x06u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_DSM1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C20887(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_DSM1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C19987(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_DOOR_MODULE_TYPE, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_DDCM1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C19987(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_DDCM1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C20087(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_DOOR_MODULE_TYPE, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_PDCM1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C20087(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_PDCM1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C24687(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_BETWEEN(VCONFIG_KIND_DRIVER_SEAT, 0x01u, 0x06u) &&
                 MD_VCONFIG_EQUAL1(VCONFIG_KIND_FRT_SEAT__HEATING_LEVEL_TYPE, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_SCM1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C24687(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_SCM1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C24787(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_SEAT_HEATING, 0x02u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_RHVSM1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C24787(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_RHVSM1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C24387(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_BETWEEN(VCONFIG_KIND_AUTO_PARKING_SYSTEM, 0x02u, 0x06u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_RPAS1);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_FPAS1);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HAP_FD1);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HAP_FD2);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HAP_FD3);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_APS3);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_APS1);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HAP2);
        ret = MD_DTC_ENABLE_CFG0;
    }
    else if(TRUE == (MD_VCONFIG_BETWEEN(VCONFIG_KIND_FRONT_SENSOR, 0x01u, 0x04u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_RPAS1);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_FPAS1);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HAP_FD3);
        ret = MD_DTC_ENABLE_CFG1;
    }
    else if(TRUE == (MD_VCONFIG_BETWEEN(VCONFIG_KIND_REAR_PAS_SENSOR, 0x01u, 0x04u) &&
                     MD_VCONFIG_EQUAL1(VCONFIG_KIND_FRONT_SENSOR, 0x00u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_RPAS1);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HAP_FD3);
        ret = MD_DTC_ENABLE_CFG2;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C24387(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        if((md_cfg.messages[MD_MESSAGE_RPAS1].status == MD_MESSAGE_STATUS_MISSING_CONFIRM)   &&
           (md_cfg.messages[MD_MESSAGE_FPAS1].status == MD_MESSAGE_STATUS_MISSING_CONFIRM)   &&
           (md_cfg.messages[MD_MESSAGE_HAP_FD1].status == MD_MESSAGE_STATUS_MISSING_CONFIRM) &&
           (md_cfg.messages[MD_MESSAGE_HAP_FD2].status == MD_MESSAGE_STATUS_MISSING_CONFIRM) &&
           (md_cfg.messages[MD_MESSAGE_HAP_FD3].status == MD_MESSAGE_STATUS_MISSING_CONFIRM) &&
           (md_cfg.messages[MD_MESSAGE_APS3].status == MD_MESSAGE_STATUS_MISSING_CONFIRM)    &&
           (md_cfg.messages[MD_MESSAGE_APS1].status == MD_MESSAGE_STATUS_MISSING_CONFIRM)    &&
           (md_cfg.messages[MD_MESSAGE_HAP2].status == MD_MESSAGE_STATUS_MISSING_CONFIRM))
        {
            ret = MD_DTC_JUDGE_RESULT_FAILED;
        }
        else if((md_cfg.messages[MD_MESSAGE_RPAS1].status == MD_MESSAGE_STATUS_OK_CONFIRM)   ||
                (md_cfg.messages[MD_MESSAGE_FPAS1].status == MD_MESSAGE_STATUS_OK_CONFIRM)   ||
                (md_cfg.messages[MD_MESSAGE_HAP_FD1].status == MD_MESSAGE_STATUS_OK_CONFIRM) ||
                (md_cfg.messages[MD_MESSAGE_HAP_FD2].status == MD_MESSAGE_STATUS_OK_CONFIRM) ||
                (md_cfg.messages[MD_MESSAGE_HAP_FD3].status == MD_MESSAGE_STATUS_OK_CONFIRM) ||
                (md_cfg.messages[MD_MESSAGE_APS3].status == MD_MESSAGE_STATUS_OK_CONFIRM)    ||
                (md_cfg.messages[MD_MESSAGE_APS1].status == MD_MESSAGE_STATUS_OK_CONFIRM)    ||
                (md_cfg.messages[MD_MESSAGE_HAP2].status == MD_MESSAGE_STATUS_OK_CONFIRM))
        {
            ret = MD_DTC_JUDGE_RESULT_PASSED;
        }
        else
        {
            ret = MD_DTC_JUDGE_RESULT_NOT_READY;
        }
        break;

        case MD_DTC_ENABLE_CFG1:
        if((md_cfg.messages[MD_MESSAGE_RPAS1].status == MD_MESSAGE_STATUS_MISSING_CONFIRM)   &&
           (md_cfg.messages[MD_MESSAGE_FPAS1].status == MD_MESSAGE_STATUS_MISSING_CONFIRM)   &&
           (md_cfg.messages[MD_MESSAGE_HAP_FD3].status == MD_MESSAGE_STATUS_MISSING_CONFIRM))
        {
            ret = MD_DTC_JUDGE_RESULT_FAILED;
        }
        else if((md_cfg.messages[MD_MESSAGE_RPAS1].status == MD_MESSAGE_STATUS_OK_CONFIRM)   ||
                (md_cfg.messages[MD_MESSAGE_FPAS1].status == MD_MESSAGE_STATUS_OK_CONFIRM)   ||
                (md_cfg.messages[MD_MESSAGE_HAP_FD3].status == MD_MESSAGE_STATUS_OK_CONFIRM))
        {
            ret = MD_DTC_JUDGE_RESULT_PASSED;
        }
        else
        {
            ret = MD_DTC_JUDGE_RESULT_NOT_READY;
        }
        break;

        case MD_DTC_ENABLE_CFG2:
        if((md_cfg.messages[MD_MESSAGE_RPAS1].status == MD_MESSAGE_STATUS_MISSING_CONFIRM)   &&
           (md_cfg.messages[MD_MESSAGE_HAP_FD3].status == MD_MESSAGE_STATUS_MISSING_CONFIRM))
        {
            ret = MD_DTC_JUDGE_RESULT_FAILED;
        }
        else if((md_cfg.messages[MD_MESSAGE_RPAS1].status == MD_MESSAGE_STATUS_OK_CONFIRM)   ||
                (md_cfg.messages[MD_MESSAGE_HAP_FD3].status == MD_MESSAGE_STATUS_OK_CONFIRM))
        {
            ret = MD_DTC_JUDGE_RESULT_PASSED;
        }
        else
        {
            ret = MD_DTC_JUDGE_RESULT_NOT_READY;
        }
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C2B387(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_DMS_TYPE, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_DMS_FD1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C2B387(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_DMS_FD1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C19887(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL2(VCONFIG_KIND_INTELLIGENT_NETWORK_SERVICE, 0x01u, 0x0Au)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_T_BOX_FD3);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C19887(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_T_BOX_FD3, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C12787(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_TPMS, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_TPMS1);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_TPMS2);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C12787(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL2(MD_MESSAGE_TPMS1, MD_MESSAGE_TPMS2, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C29387(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL2(VCONFIG_KIND_FUEL, 0x04u, 0x0Au)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HCU_HC3);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HCU_HC6);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HCU_HC7);
        ret = MD_DTC_ENABLE_CFG0;
    }
    else if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_ELECTROMOTOR_POSITION, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HCU_HC16);
        ret = MD_DTC_ENABLE_CFG1;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C29387(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL3(MD_MESSAGE_HCU_HC3, MD_MESSAGE_HCU_HC6, MD_MESSAGE_HCU_HC7, ret);
        break;

        case MD_DTC_ENABLE_CFG1:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_HCU_HC16, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C11187(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if((TRUE == (MD_VCONFIG_EQUAL3(VCONFIG_KIND_ELECTROMOTOR_POSITION, 0x02u, 0x04u, 0x05u))) &&
        (TRUE != (MD_VCONFIG_EQUAL2(VCONFIG_KIND_FUEL, 0x04u, 0x0Au))))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_BMS4);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_BMS8);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_BMS35);
        ret = MD_DTC_ENABLE_CFG0;
    }
    else if((TRUE == (MD_VCONFIG_EQUAL3(VCONFIG_KIND_ELECTROMOTOR_POSITION, 0x02u, 0x04u, 0x05u))) &&
            (TRUE == (MD_VCONFIG_EQUAL2(VCONFIG_KIND_FUEL, 0x04u, 0x0Au))))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_BMS4);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_BMS8);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_BMS35);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_BMS22);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_BMS30);
        ret = MD_DTC_ENABLE_CFG1;
    }
    else if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_ELECTROMOTOR_POSITION, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_BMS4);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_BMS65);
        ret = MD_DTC_ENABLE_CFG2;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C11187(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL3(MD_MESSAGE_BMS4, MD_MESSAGE_BMS8, MD_MESSAGE_BMS35, ret);
        break;

        case MD_DTC_ENABLE_CFG1:
        MD_DTC_JUDGE_GENERAL5(MD_MESSAGE_BMS4, MD_MESSAGE_BMS8, MD_MESSAGE_BMS35,MD_MESSAGE_BMS22, MD_MESSAGE_BMS30, ret);
        break;

        case MD_DTC_ENABLE_CFG2:
        MD_DTC_JUDGE_GENERAL2(MD_MESSAGE_BMS4, MD_MESSAGE_BMS65, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C1BB87(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL2(VCONFIG_KIND_FUEL, 0x04u, 0x0Au)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_OBC2);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C1BB87(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_OBC2, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_D10887(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_SMART_JUNCTION_BOX, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_F_PBOX1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_D10887(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_F_PBOX1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_D10987(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_SMART_JUNCTION_BOX, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_R_PBOX1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_D10987(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_R_PBOX1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_D00487(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION, 0x03u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HAP_FD1);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HAP_FD2);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HAP_FD3);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_D00487(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL3(MD_MESSAGE_HAP_FD1, MD_MESSAGE_HAP_FD2, MD_MESSAGE_HAP_FD3, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C10487(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_NOT_EQUAL(VCONFIG_KIND_HIGHWAY_ASSIST, 0x01u) &&
                MD_VCONFIG_EQUAL1(VCONFIG_KIND_ACC_SENSOR_CONTROL_MODULE, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_AEB_FD1);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_AEB_FD2);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_ACC_FD2);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_ACC_FD3);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_ACC_FD4);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C10487(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL5(MD_MESSAGE_AEB_FD1, MD_MESSAGE_AEB_FD2, MD_MESSAGE_ACC_FD2, MD_MESSAGE_ACC_FD3, MD_MESSAGE_ACC_FD4, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C14387(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_NOT_EQUAL(VCONFIG_KIND_HIGHWAY_ASSIST, 0x01u) &&
                MD_VCONFIG_EQUAL1(VCONFIG_KIND_INTELLIGENT_FRONT_CAMERA, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_IFC_FD2);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_IFC_FD3);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_IFC_FD5);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_IFC_FD6);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C14387(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL4(MD_MESSAGE_IFC_FD2, MD_MESSAGE_IFC_FD3, MD_MESSAGE_IFC_FD5, MD_MESSAGE_IFC_FD6, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_D00987(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_SIDE_STEP, 0x06u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_CP1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_D00987(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_CP1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C23087(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL2(VCONFIG_KIND_RR_DOOR_OPENING, 0x02u, 0x03u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_PLG_1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C23087(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_PLG_1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C15C87(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_HIGHWAY_ASSIST, 0x01u)))
    {
        
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_AEB_FD1);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_AEB_FD2);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_IFC_FD2);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_IFC_FD3);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_IFC_FD5);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_IFC_FD6);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_ACC_FD2);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_ACC_FD3);
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_ACC_FD4);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C15C87(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL9(MD_MESSAGE_AEB_FD1, MD_MESSAGE_AEB_FD2, MD_MESSAGE_IFC_FD2, MD_MESSAGE_IFC_FD3, MD_MESSAGE_IFC_FD5, MD_MESSAGE_IFC_FD6, MD_MESSAGE_ACC_FD2, MD_MESSAGE_ACC_FD3, MD_MESSAGE_ACC_FD4, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C11587(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_BETWEEN(VCONFIG_KIND_LIMITED_SLIP_DIFFERRENTIAL, 0x02u, 0x04u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_ELD1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C11587(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_ELD1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_D01587(void)
{
    return MD_DTC_DISABLE;
}

static uint8 DTC_JudgeFunction_D01587(uint8 cfgId)
{
    return MD_DTC_JUDGE_RESULT_FAILED;
}

static uint8 DTC_EnableFunction_C14187(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL4(VCONFIG_KIND_TRAILING_HOOK, 0x02u, 0x04u, 0x05u, 0x06u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_TRAILER1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C14187(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_TRAILER1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_D02987(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL2(VCONFIG_KIND_WIRELESS_POWER_CHARGER, 0x01u, 0x02u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_WPC1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_D02987(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_WPC1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C11487(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL4(VCONFIG_KIND_TRANSFER_CASE, 0x01u, 0x02u, 0x03u, 0x05u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_TOD1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C11487(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_TOD1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C15887(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL2(VCONFIG_KIND_HEAD_UP_DISPLAY, 0x01u, 0x03u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_HUD1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    else if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_HEAD_UP_DISPLAY, 0x02u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_AR_HUD1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C15887(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_HUD1, ret);
        break;

        case MD_DTC_ENABLE_CFG1:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_AR_HUD1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C23387(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_LANE_CHANGE_ASSIST, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_RSDS_FD1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C23387(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_RSDS_FD1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C2B587(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL2(VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK, 0x01u, 0x02u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_CR_FD1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C2B587(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_CR_FD1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_D10687(void)
{
    MD_MESSAGE_SET_ENABLED(MD_MESSAGE_CSA3);
    return MD_DTC_ENABLE_CFG0;
}

static uint8 DTC_JudgeFunction_D10687(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_CSA3, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_C25E87(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_TYPE_OF_BOOSTER_BRAKE_PUMP, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_IBOOSTER_FD2);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return ret;
}

static uint8 DTC_JudgeFunction_C25E87(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
        MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_IBOOSTER_FD2, ret);
        break;

        default:
        break;
    }
    return ret;
}

static uint8 DTC_EnableFunction_D12387(void)
{
    uint8 ret = MD_DTC_DISABLE;
    if(TRUE == (MD_VCONFIG_EQUAL1(VCONFIG_KIND_WATER_DEPTH_DETECTION, 0x01u)))
    {
        MD_MESSAGE_SET_ENABLED(MD_MESSAGE_DWD1);
        ret = MD_DTC_ENABLE_CFG0;
    }
    return 0;
}

static uint8 DTC_JudgeFunction_D12387(uint8 cfgId)
{
    uint8 ret = MD_DTC_JUDGE_RESULT_FAILED;
    switch(cfgId)
    {
        case MD_DTC_ENABLE_CFG0:
            MD_DTC_JUDGE_GENERAL1(MD_MESSAGE_DWD1, ret);
        break;

        default:
        break;
    }
    return ret;
}

static Std_ReturnType DTC_ReportFunction_C10087(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_Missing_Engine_Control_0xC10087_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C12287(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingElectricalStableProgram_0xC12287_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C10187(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingTransmissionControlUntilPTCAN_0xC10187_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C15187(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingAirbagModule_0xC15187_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C24187(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingControlerHeadlamp_0xC24187_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C24287(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingRightHeadlampControlModule_0xC24287_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_D10B87(uint8 status) 
{
    return Rte_Call_DiagnosticMonitor_MissingPrePretensionerMechatronicIntegrated_0xD10B87_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_D02687(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_PTCAN_0xD02687_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C14087(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingElecRegionControlSystemBody_0xC14087_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C16487(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingAC_AirConditionRearFrontControlPanel_0xC16487_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C14687(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingGateway_0xC14687_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C13187(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingElectricPowerSteeringSystem_0xC13187_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C12887(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingElectricParkBrakecontroller_0xC12887_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C20887(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingDriverSeatMemorymodule_0xC20887_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C19987(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingDriverDoorControlModule_0xC19987_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C20087(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingPassengerDoorControlModule_0xC20087_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C24687(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_missingSeatControlModule_0xC24687_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C24787(uint8 status)
{
    return E_NOT_OK;
}

static Std_ReturnType DTC_ReportFunction_C24387(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingParkingAssistanceSystem_0xC24387_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C2B387(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingDriverMonitoringSystem_0xC2B387_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C19887(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingTelematicsControlBox_0xC19887_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C12787(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingTyrePressureMonitoringSystem_0xC12787_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C29387(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingHybridVehicleControlUnitVehiclecontrolunit_HCCAN_0xC29387_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C11187(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingBatteryManagementSystem_0xC11187_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C1BB87(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingOnboardcharger_0xC1BB87_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_D10887(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingFrontPowerBox_0xD10887_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_D10987(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingRearPowerBox_0xD10987_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_D00487(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingAroundViewMonitoringSystem_0xD00487_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C10487(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_missingAdaptiveCruiseControlsystemRadarControlModule_0xC10487_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C14387(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingIntelligentForwardViewCamera_0xC14387_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_D00987(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingControllerPedal_0xD00987_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C23087(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingPowerLiftGatemodule_0xC23087_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C15C87(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingIntelligentDrivingController_Level2_0xC15C87_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C11587(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingElectronicGerodisc_0xC11587_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_D01587(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingScreenTouchButtonSwitchController_0xD01587_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C14187(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingTrailer_0xC14187_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_D02987(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingWirelessPowerCharger_0xD02987_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C11487(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingNextrac_0xC11487_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C15887(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingHeadUpDisplay_0xC15887_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C23387(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingRightRearSideDetectionSystem_0xC23387_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C2B587(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_missingRightCornerRadar_0xC2B587_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_D10687(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingCombinationSwitchAssembly_0xD10687_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_C25E87(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingIbooster_0xC25E87_SetEventStatus(status);
}

static Std_ReturnType DTC_ReportFunction_D12387(uint8 status)
{
    return Rte_Call_DiagnosticMonitor_MissingDepthOfWaterDetectionModule_0xD12387_SetEventStatus(status);
}

#define Can_Server_STOP_SEC_CODE
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
