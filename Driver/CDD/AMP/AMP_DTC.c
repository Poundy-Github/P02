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
 * @file:      AMP_DTC.c
 * @author:    Nobo
 * @date:      2020-5-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "AMP_DTC.h"
#include "Ipc_Audio.h"
#include "Logger_Cfg.h"
#include "logger.h"
#include "Rte_AMP.h"
#include "AMP_Normal.h"
#include "Dem_Lcfg.h"

#define AMP_DTCEVENTPASS                                (0u)
#define AMP_DTCEVENTFAIL                                (1u)

#define AMP_DTCENABLE                                   (1u)
#define AMP_DTCNOENABLE                                 (0u)

#define AMP_FL_SHORTACROSS                              (0u)
#define AMP_FL_SHORTTOGND                               (1u)
#define AMP_FL_SHORTTOBAT                               (2u)
#define AMP_FL_OUTPUTCLIP                               (3u)
#define AMP_FR_SHORTACROSS                              (4u)
#define AMP_FR_SHORTTOGND                               (5u)
#define AMP_FR_SHORTTOBAT                               (6u)
#define AMP_FR_OUTPUTCLIP                               (7u)
#define AMP_RL_SHORTACROSS                              (8u)
#define AMP_RL_SHORTTOGND                               (9u)
#define AMP_RL_SHORTTOBAT                               (10u)
#define AMP_RL_OUTPUTCLIP                               (11u)
#define AMP_RR_SHORTACROSS                              (12u)
#define AMP_RR_SHORTTOGND                               (13u)
#define AMP_RR_SHORTTOBAT                               (14u)
#define AMP_RR_OUTPUTCLIP                               (15u)
#define AMP8532_CYCLEDTCNUM                             (16u)


#define AMP_CENTER_SHORTACROSS                          (0u)
#define AMP_CENTER_SHORTTOGND                           (1u)
#define AMP_CENTER_SHORTTOBAT                           (2u)
#define AMP_CENTER_OUTPUTCLIP                           (3u)
#define AMP_WOOFER_SHORTACROSS                          (4u)
#define AMP_WOOFER_SHORTTOGND                           (5u)
#define AMP_WOOFER_SHORTTOBAT                           (6u)
#define AMP_WOOFER_OUTPUTCLIP                           (7u)
#define AMP_AVAS_SHORTACROSS                            (8u)
#define AMP_AVAS_SHORTTOGND                             (9u)
#define AMP_AVAS_SHORTTOBAT                             (10u)
#define AMP_AVAS_OUTPUTCLIP                             (11u)
#define AMP8531_CYCLEDTCNUM                             (12u)


#define AMP_FL_OPEN                                     (0u)
#define AMP_FL_RESISTANCEOUTRANGE                       (1u)
#define AMP_FR_OPEN                                     (2u)
#define AMP_FR_RESISTANCEOUTRANGE                       (3u)
#define AMP_RL_OPEN                                     (4u)
#define AMP_RL_RESISTANCEOUTRANGE                       (5u)
#define AMP_RR_OPEN                                     (6u)
#define AMP_RR_RESISTANCEOUTRANGE                       (7u)
#define AMP8532_EVENTDTCNUM                             (8u)


#define AMP_CENTER_OPEN                                 (0u)
#define AMP_CENTER_RESISTANCEOUTRANGE                   (1u)
#define AMP_WOOFER_OPEN                                 (2u)
#define AMP_WOOFER_RESISTANCEOUTRANGE                   (3u)
#define AMP_AVAS_OPEN                                   (4u)
#define AMP_AVAS_RESISTANCEOUTRANGE                     (5u)
#define AMP8531_EVENTDTCNUM                             (6u)

#define AMP_EOLCHANNEL_OPEN                             (1u)
#define AMP_EOLCHANNEL_SHORTGND                         (2u)
#define AMP_EOLCHANNEL_SHORTBAT                         (3u)
#define AMP_EOLCHANNEL_CONNECT                          (4u)
#define AMP_EOLCHANNEL_SHORTACROSS                      (5u)
#define AMP_EOLNOTSUPPORT                               (0u)

#define AMP_MONITORDTC_REPORTTIME                       (200u)

#define AMPTASKCYCLE                                    (5u)
#define DTCREPORTNONE                                   (2u)
#define DTCREPORTPASSED                                 (0u)
#define DTCREPORTFAILED                                 (1u)

#define DTCFL_OPEN                                       (0u)
#define DTCFL_OUTOFRANGE                                 (1u)
#define DTCFL_SHORTTOGND                                 (2u)
#define DTCFL_SHORTTOBAT                                 (3u)
#define DTCFL_SHORTACROSS                                (4u)
#define DTCFL_CLIP                                       (5u)
#define DTCFR_OPEN                                       (6u)
#define DTCFR_OUTOFRANGE                                 (7u)
#define DTCFR_SHORTTOGND                                 (8u)
#define DTCFR_SHORTTOBAT                                 (9u)
#define DTCFR_SHORTACROSS                                (10u)
#define DTCFR_CLIP                                       (11u)
#define DTCRL_OPEN                                       (12u)
#define DTCRL_OUTOFRANGE                                 (13u)
#define DTCRL_SHORTTOGND                                 (14u)
#define DTCRL_SHORTTOBAT                                 (15u)
#define DTCRL_SHORTACROSS                                (16u)
#define DTCRL_CLIP                                       (17u)
#define DTCRR_OPEN                                       (18u)
#define DTCRR_OUTOFRANGE                                 (19u)
#define DTCRR_SHORTTOGND                                 (20u)
#define DTCRR_SHORTTOBAT                                 (21u)
#define DTCRR_SHORTACROSS                                (22u)
#define DTCRR_CLIP                                       (23u)
#define DTCWOOFER_OPEN                                   (24u)
#define DTCWOOFER_OUTOFRANGE                             (25u)
#define DTCWOOFER_SHORTTOGND                             (26u)
#define DTCWOOFER_SHORTTOBAT                             (27u)
#define DTCWOOFER_SHORTACROSS                            (28u)
#define DTCWOOFER_CLIP                                   (29u)
#define DTCCENTER_OPEN                                   (30u)
#define DTCCENTER_OUTOFRANGE                             (31u)
#define DTCCENTER_SHORTTOGND                             (32u)
#define DTCCENTER_SHORTTOBAT                             (33u)
#define DTCCENTER_SHORTACROSS                            (34u)
#define DTCCENTER_CLIP                                   (35u)
#define DTCAVAS_OPEN                                     (36u)
#define DTCAVAS_OUTOFRANGE                               (37u)
#define DTCAVAS_SHORTTOGND                               (38u)
#define DTCAVAS_SHORTTOBAT                               (39u)
#define DTCAVAS_SHORTACROSS                              (40u)
#define DTCAVAS_CLIP                                     (41u)
#define DTCAMPNUM                                        (42u)

#define DTC_UNDERVOL_VAL								 ((float64)9.0f)
#define DTC_OVERVOL_VAL 								 ((float64)16.0f)



typedef struct {
    uint16 monitorCounter;
    uint16 failedCounter;
    uint16 passedCounter;
}s_EventDebounce_t;

typedef struct {
    uint16 FailThreshold;
    uint16 PassThreshold;
}s_EventDebounceCfg_t;

typedef struct {
    boolean *Active;                                            /* DTC Active*/
    uint8 *eventStatus;                                         /* DTC Status*/
    const s_EventDebounceCfg_t *eventDebounceCfg;               /* DTC PASSED or FAILED Config Time*/
    s_EventDebounce_t *eventDebounce;                           /* DTC Monotor Time */
}s_EventDTC_t;



typedef struct
{
    s_DeviceSts_Type DeviceSts;
    uint8 DeviceState;
}s_DeviceData_Type;

typedef struct
{
    uint8 DeviceDiagResults_1;
    uint8 DeviceDiagResults_2;
    uint8 CH1DiagResults;
    uint8 CH2DiagResults;
    uint8 CH3DiagResults;
    uint8 CH4DiagResults;
}s_IPCDiagResult_Type;


#define AMP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "AMP_MemMap.h"

extern s_AMPClipResult_Type AMPClipResult[DEVICE_NUM];

static s_IPCDiagResult_Type AMPIPCDiagResult[DEVICE_NUM];
static s_IPCDiagResult_Type AMPIPCDiagResultBackup[DEVICE_NUM];
static s_DeviceData_Type IICDeviceData[DEVICE_NUM];
static s_DeviceData_Type IICDeviceDataBackup[DEVICE_NUM];
static s_ChannelData_Type IICChannelData[DEVICE_NUM][CHANNEL_NUM];
static s_ChannelData_Type IICChannelDataBackup[DEVICE_NUM][CHANNEL_NUM];
static uint8 AMP_IPCResponse[DEVICE_NUM] = {AMP_IPCWAITINIT};
static uint8 AMP_IPCACKCunt[DEVICE_NUM] = {0u};
static u_AMPChannelCfg_t AMPDTCCHCfg[DEVICE_NUM];
static boolean DTCActive[DTCAMPNUM]; 
static uint8 AMPDTCEventSts[DTCAMPNUM]; 
static s_EventDebounce_t AMPEventDebounce[DTCAMPNUM];
static e_AMP_SelfCheckResult_t AMP_SelfCheckResult[DEVICE_NUM];
static AVASDTCRet AVASDTCRetData;
static uint32 DTCclrReqCnt;


#define AMP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "AMP_MemMap.h" 




#define AMP_START_SEC_CONST_UNSPECIFIED
#include "AMP_MemMap.h"

static const s_EventDebounceCfg_t AMPEventDebounceCfg[DTCAMPNUM] = {
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*FL Open*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*FL OutofRange*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*FL ShortToGND*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*FL ShortToBAT*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*FL ShortAcross*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*FL Clip*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*FR Open*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*FR OutofRange*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*FR ShortToGND*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*FR ShortToBAT*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*FR ShortAcross*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*FR Clip*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*RL Open*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*RL OutoRLange*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*RL ShortToGND*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*RL ShortToBAT*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*RL ShortAcross*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*RL Clip*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*RR Open*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*RR OutoRRange*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*RR ShortToGND*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*RR ShortToBAT*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*RR ShortAcross*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*RR Clip*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*Woofer Open*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*Woofer OutoWooferange*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*Woofer ShortToGND*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*Woofer ShortToBAT*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*Woofer ShortAcross*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*Woofer Clip*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*Center Open*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*Center OutoCenterange*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*Center ShortToGND*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*Center ShortToBAT*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*Center ShortAcross*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*Center Clip*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*Avas Open*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*Avas OutofRange*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*Avas ShortToGND*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*Avas ShortToBAT*/
    {2000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*Avas ShortAcross*/
    {5000/AMPTASKCYCLE, 1000/AMPTASKCYCLE},/*Avas Clip*/
};

static const s_EventDTC_t EventDTCCfg = {
    DTCActive,
    AMPDTCEventSts,
    AMPEventDebounceCfg,
    AMPEventDebounce,
};





#define AMP_STOP_SEC_CONST_UNSPECIFIED
#include "AMP_MemMap.h"


#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"

static void AMPDTC_FLOpen(void);
static void AMPDTC_FROpen(void);
static void AMPDTC_RLOpen(void);
static void AMPDTC_RROpen(void);
static void AMPDTC_WooferOpen(void);
static void AMPDTC_CenterOpen(void);
static void AMPDTC_AVASOpen(void);

static void AMPDTC_FLOutofRange(void);
static void AMPDTC_FROutofRange(void);
static void AMPDTC_RLOutofRange(void);
static void AMPDTC_RROutofRange(void);
static void AMPDTC_WooferOutofRange(void);
static void AMPDTC_CenterOutofRange(void);
static void AMPDTC_AVASOutofRange(void);

static void AMPDTC_FLShortToGND(void);
static void AMPDTC_FRShortToGND(void);
static void AMPDTC_RLShortToGND(void);
static void AMPDTC_RRShortToGND(void);
static void AMPDTC_WooferShortToGND(void);
static void AMPDTC_CenterShortToGND(void);
static void AMPDTC_AVASShortToGND(void);

static void AMPDTC_FLShortToBAT(void);
static void AMPDTC_FRShortToBAT(void);
static void AMPDTC_RLShortToBAT(void);
static void AMPDTC_RRShortToBAT(void);
static void AMPDTC_WooferShortToBAT(void);
static void AMPDTC_CenterShortToBAT(void);
static void AMPDTC_AVASShortToBAT(void);

static void AMPDTC_FLShortAcross(void);
static void AMPDTC_FRShortAcross(void);
static void AMPDTC_RLShortAcross(void);
static void AMPDTC_RRShortAcross(void);
static void AMPDTC_WooferShortAcross(void);
static void AMPDTC_CenterShortAcross(void);
static void AMPDTC_AVASShortAcross(void);

static void AMPDTC_FLClip(void);
static void AMPDTC_FRClip(void);
static void AMPDTC_RLClip(void);
static void AMPDTC_RRClip(void);
static void AMPDTC_WooferClip(void);
static void AMPDTC_CenterClip(void);
static void AMPDTC_AVASClip(void);

static uint8 AMPDTCClip(uint8 dev_id,uint8 ChannelID);
static boolean AMPDTCOpen(uint8 dev_id,uint8 ChannelID);
static boolean AMPDTCOutofRange(uint8 dev_id,uint8 ChannelID);
static boolean AMPDTCShortAcross(uint8 dev_id,uint8 ChannelID);
static uint8 AMPDTCShortToBAT(uint8 dev_id,uint8 ChannelID);
static uint8 AMPDTCShortToGND(uint8 dev_id,uint8 ChannelID);
static void AMP1_DTCLogic(void);
static void AMP2_DTCLogic(void);
static void AMPDeviceLog(uint8 dev_id);
static void AMPChannelLog(uint8 dev_id,uint8 ChannelID);
static void AMPIPCDDiagResultData(uint8 dev_id, uint8 MonitorType);
static void AMP_IPCCuntLogic(uint8 dev_id);
static uint8 AMPDTCReportDebounce(uint8 errorStatus,uint8 DTCID, const s_EventDTC_t *EventDTC);
static void AMPDTCDebounceClr(uint8 dev_id);


#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"




#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_DTCInit(uint8 dev_id)
{
    uint8 ChannelID;
    uint8 DTCID;

    AMPDTCCHCfg[dev_id] = AMP_ChannelCfg(dev_id);
    AMP_SelfCheckResult[dev_id].AMP_Sts = AMPSELFCHECKSTS_PENDING;
    for(ChannelID = 0u;ChannelID < AMP8532_CHANNEL_NUM;ChannelID ++)
    {
        AMP_SelfCheckResult[dev_id].ACDiagResult[ChannelID] = 0u;
        AMP_SelfCheckResult[dev_id].DCDiagResult[ChannelID] = 0u;
    }
    if(dev_id == DEVICE_AMP1)
    {
        for(DTCID = 0u; DTCID < DTCWOOFER_OPEN; DTCID++)
        {
            DTCActive[DTCID] = TRUE;
            AMPDTCEventSts[DTCID] = DEM_EVENT_STATUS_FAILED;
        }
        (void)memset(&AMPEventDebounce[0],0,sizeof(s_EventDebounce_t)*DTCWOOFER_OPEN);
    }
    if(dev_id == DEVICE_AMP2) 
    {
        for(DTCID = DTCWOOFER_OPEN; DTCID < DTCAMPNUM; DTCID++)
        {
            DTCActive[DTCID] = TRUE;
            AMPDTCEventSts[DTCID] = DEM_EVENT_STATUS_FAILED;
        }
        (void)memset(&AMPEventDebounce[DTCWOOFER_OPEN],0,sizeof(s_EventDebounce_t)*(DTCAMPNUM-DTCWOOFER_OPEN));
		/* 0xFF mean no AVAS channel, for cluster TT function */
        (void)memset(&AVASDTCRetData, 0xFF, sizeof(AVASDTCRet));
    }
	Rte_Read_rpSR_piDiagMonitorReInitFlag_ChangeCounter( &DTCclrReqCnt );
}

/***********************************************************************
 * @brief       : FL Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_FLOpen(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)AMPDTCOpen(DEVICE_AMP1,CHANNEL_FL);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCFL_OPEN,&EventDTCCfg);
    
    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0113_FLOpen_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC FLOpen Report %d",DTCRet);
            EventDTCCfg.Active[DTCFL_OPEN] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : FR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_FROpen(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)AMPDTCOpen(DEVICE_AMP1,CHANNEL_FR);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCFR_OPEN,&EventDTCCfg);
    
    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0213_FROpen_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC FROpen Report %d",DTCRet);
            EventDTCCfg.Active[DTCFR_OPEN] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RL Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_RLOpen(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)AMPDTCOpen(DEVICE_AMP1,CHANNEL_RL);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCRL_OPEN,&EventDTCCfg);
    
    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0313_RLOpen_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC RLOpen Report %d", DTCRet);
            EventDTCCfg.Active[DTCRL_OPEN] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_RROpen(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)AMPDTCOpen(DEVICE_AMP1,CHANNEL_RR);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCRR_OPEN,&EventDTCCfg);
    
    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0413_RROpen_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC RROpen Report %d",DTCRet);
            EventDTCCfg.Active[DTCRR_OPEN] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_WooferOpen(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)(AMPDTCOpen(DEVICE_AMP2,CHANNEL_SW1) || AMPDTCOpen(DEVICE_AMP2,CHANNEL_SW2));
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCWOOFER_OPEN,&EventDTCCfg);
    
    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0613_WooferOpen_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC Woofer Open Report %d",DTCRet);
            EventDTCCfg.Active[DTCWOOFER_OPEN] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_CenterOpen(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)AMPDTCOpen(DEVICE_AMP2,CHANNEL_CENTER);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCCENTER_OPEN,&EventDTCCfg);
    
    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0513_CenterOpen_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC Center Open Report %d",DTCRet);
            EventDTCCfg.Active[DTCCENTER_OPEN] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_AVASOpen(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)AMPDTCOpen(DEVICE_AMP2,CHANNEL_AVAS);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCAVAS_OPEN,&EventDTCCfg);
    
    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Dem_SetEventStatus(DemConf_DemEventParameter_Speaker_AVAS_CircuitOpen,DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC AVAS Open Report %d",DTCRet);
            EventDTCCfg.Active[DTCAVAS_OPEN] = FALSE;
        }
		AVASDTCRetData.Open = DTCRet;
    }
}
    
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_FLOutofRange(void)
{   
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)AMPDTCOutofRange(DEVICE_AMP1,CHANNEL_FL);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCFL_OUTOFRANGE,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A011E_FLResistanceOutRange_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC FLOutofRange Report %d",DTCRet);
            EventDTCCfg.Active[DTCFL_OUTOFRANGE] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_FROutofRange(void)
{         
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)AMPDTCOutofRange(DEVICE_AMP1,CHANNEL_FR);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCFR_OUTOFRANGE,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A021E_FRResistanceOutRange_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC DTCFR_OUTOFRANGE Report %d",DTCRet);
            EventDTCCfg.Active[DTCFR_OUTOFRANGE] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_RLOutofRange(void)
{         
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)AMPDTCOutofRange(DEVICE_AMP1,CHANNEL_RL);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCRL_OUTOFRANGE,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A031E_RLResistanceOutRange_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC RLOutofRange Report %d",DTCRet);
            EventDTCCfg.Active[DTCRL_OUTOFRANGE] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_RROutofRange(void)
{         
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)AMPDTCOutofRange(DEVICE_AMP1,CHANNEL_RR);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCRR_OUTOFRANGE,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A041E_RRResistanceOutRange_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC RROutofRange Report %d",DTCRet);
            EventDTCCfg.Active[DTCRR_OUTOFRANGE] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_WooferOutofRange(void)
{         
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)(AMPDTCOutofRange(DEVICE_AMP2,CHANNEL_SW1) || AMPDTCOutofRange(DEVICE_AMP2,CHANNEL_SW2));
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCWOOFER_OUTOFRANGE,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A061E_WooferResistanceOutRange_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC Woofer OutofRange Report %d",DTCRet);
            EventDTCCfg.Active[DTCWOOFER_OUTOFRANGE] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_CenterOutofRange(void)
{         
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)AMPDTCOutofRange(DEVICE_AMP2,CHANNEL_CENTER);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCCENTER_OUTOFRANGE,&EventDTCCfg);
    
    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A051E_CenterResistanceOutRange_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC Center OutofRange Report %d",DTCRet);
            EventDTCCfg.Active[DTCCENTER_OUTOFRANGE] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_AVASOutofRange(void)
{         
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)AMPDTCOutofRange(DEVICE_AMP2,CHANNEL_AVAS);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCAVAS_OUTOFRANGE,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Dem_SetEventStatus(DemConf_DemEventParameter_Speaker_AVAS_ResistanceOutOfRange,DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC AVAS OutofRange Report %d",DTCRet);
            EventDTCCfg.Active[DTCAVAS_OUTOFRANGE] = FALSE;
        }
		AVASDTCRetData.OutofRange = DTCRet;
    }
}

/***********************************************************************
 * @brief       : FL Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_FLShortToGND(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = AMPDTCShortToGND(DEVICE_AMP1,CHANNEL_FL);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCFL_SHORTTOGND,&EventDTCCfg);
    
    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0111_FLShortToGND_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC FL Short to GND Report %d",DTCRet);
            EventDTCCfg.Active[DTCFL_SHORTTOGND] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : FR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_FRShortToGND(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = AMPDTCShortToGND(DEVICE_AMP1,CHANNEL_FR);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCFR_SHORTTOGND,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0211_FRShortToGND_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC FL Short to GND Report %d",DTCRet);
            EventDTCCfg.Active[DTCFR_SHORTTOGND] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RL Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_RLShortToGND(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = AMPDTCShortToGND(DEVICE_AMP1,CHANNEL_RL);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCRL_SHORTTOGND,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0311_RLShortToGND_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC RL Short to GND Report %d",DTCRet);
            EventDTCCfg.Active[DTCRL_SHORTTOGND] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_RRShortToGND(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = AMPDTCShortToGND(DEVICE_AMP1,CHANNEL_RR);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCRR_SHORTTOGND,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0411_RRShortToGND_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC RR Short to GND Report %d",DTCRet);
            EventDTCCfg.Active[DTCRR_SHORTTOGND] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_WooferShortToGND(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (AMPDTCShortToGND(DEVICE_AMP2,CHANNEL_SW1) || AMPDTCShortToGND(DEVICE_AMP2,CHANNEL_SW2));
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCWOOFER_SHORTTOGND,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0611_WooferShortToGND_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC Woofer Short to GND Report %d",DTCRet);
            EventDTCCfg.Active[DTCWOOFER_SHORTTOGND] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_CenterShortToGND(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = AMPDTCShortToGND(DEVICE_AMP2,CHANNEL_CENTER);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCCENTER_SHORTTOGND,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0511_CneterShortToGND_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC Woofer Short to GND Report %d",DTCRet);
            EventDTCCfg.Active[DTCCENTER_SHORTTOGND] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_AVASShortToGND(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = AMPDTCShortToGND(DEVICE_AMP2,CHANNEL_AVAS);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCAVAS_SHORTTOGND,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Dem_SetEventStatus(DemConf_DemEventParameter_Speaker_AVAS_ShortToGround, DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC AVAS Short to GND Report %d",DTCRet);
            EventDTCCfg.Active[DTCAVAS_SHORTTOGND] = FALSE;
        }
		AVASDTCRetData.ShorttoGND = DTCRet;
    }
}

/***********************************************************************
 * @brief       : FL Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_FLShortToBAT(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = AMPDTCShortToBAT(DEVICE_AMP1,CHANNEL_FL);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCFL_SHORTTOBAT,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0112_FLShorttoBAT_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC FL Short to BAT Report %d",DTCRet);
            EventDTCCfg.Active[DTCAVAS_SHORTTOGND] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : FR Short to Battery DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_FRShortToBAT(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = AMPDTCShortToBAT(DEVICE_AMP1,CHANNEL_FR);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCFR_SHORTTOBAT,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0212_FRShorttoBAT_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC FR Short to BAT Report %d",DTCRet);
            EventDTCCfg.Active[DTCFR_SHORTTOBAT] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RL Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_RLShortToBAT(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = AMPDTCShortToBAT(DEVICE_AMP1,CHANNEL_RL);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCRL_SHORTTOBAT,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0312_RLShorttoBAT_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC RL Short to BAT Report %d",DTCRet);
            EventDTCCfg.Active[DTCRL_SHORTTOBAT] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_RRShortToBAT(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = AMPDTCShortToBAT(DEVICE_AMP1,CHANNEL_RR);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCRR_SHORTTOBAT,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0412_RRShorttoBAT_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC RR Short to BAT Report %d",DTCRet);
            EventDTCCfg.Active[DTCRR_SHORTTOBAT] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_WooferShortToBAT(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (AMPDTCShortToBAT(DEVICE_AMP2,CHANNEL_SW1) || AMPDTCShortToBAT(DEVICE_AMP2,CHANNEL_SW2));
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCWOOFER_SHORTTOBAT,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0612_WooferShorttoBAT_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC Woofer Short to BAT Report %d",DTCRet);
            EventDTCCfg.Active[DTCWOOFER_SHORTTOBAT] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_CenterShortToBAT(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = AMPDTCShortToBAT(DEVICE_AMP2,CHANNEL_CENTER);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCCENTER_SHORTTOBAT,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0512_CenterShorttoBAT_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC Center Short to BAT Report %d",DTCRet);
            EventDTCCfg.Active[DTCCENTER_SHORTTOBAT] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_AVASShortToBAT(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = AMPDTCShortToBAT(DEVICE_AMP2,CHANNEL_AVAS);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCAVAS_SHORTTOBAT,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Dem_SetEventStatus(DemConf_DemEventParameter_Speaker_AVAS_ShortToBattery,DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC AVAS Short to BAT Report %d",DTCRet);
            EventDTCCfg.Active[DTCAVAS_SHORTTOBAT] = FALSE;
        }
		AVASDTCRetData.ShorttoBAT = DTCRet;
    }
}

/***********************************************************************
 * @brief       : FL Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_FLShortAcross(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)AMPDTCShortAcross(DEVICE_AMP1,CHANNEL_FL);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCFL_SHORTACROSS,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0101_FLShortAcross_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC FL ShortAcross Report %d",DTCRet);
            EventDTCCfg.Active[DTCFL_SHORTACROSS] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : FR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_FRShortAcross(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)AMPDTCShortAcross(DEVICE_AMP1,CHANNEL_FR);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCFR_SHORTACROSS,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0201_FRShortAcross_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC FR ShortAcross Report %d",DTCRet);
            EventDTCCfg.Active[DTCFR_SHORTACROSS] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RL Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_RLShortAcross(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)AMPDTCShortAcross(DEVICE_AMP1,CHANNEL_RL);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCRL_SHORTACROSS,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0301_RLShortAcross_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC RL ShortAcross Report %d",DTCRet);
            EventDTCCfg.Active[DTCRL_SHORTACROSS] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_RRShortAcross(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)AMPDTCShortAcross(DEVICE_AMP1,CHANNEL_RR);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCRR_SHORTACROSS,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0401_RRShortAcross_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC RR ShortAcross Report %d",DTCRet);
            EventDTCCfg.Active[DTCRR_SHORTACROSS] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_WooferShortAcross(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)(AMPDTCShortAcross(DEVICE_AMP2,CHANNEL_SW1) || AMPDTCShortAcross(DEVICE_AMP2,CHANNEL_SW2));
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCWOOFER_SHORTACROSS,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0601_WooferShortAcross_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC Woofer ShortAcross Report %d",DTCRet);
            EventDTCCfg.Active[DTCWOOFER_SHORTACROSS] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_CenterShortAcross(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)AMPDTCShortAcross(DEVICE_AMP2,CHANNEL_CENTER);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCCENTER_SHORTACROSS,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0501_CenterShortAcross_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC Center ShortAcross Report %d",DTCRet);
            EventDTCCfg.Active[DTCCENTER_SHORTACROSS] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_AVASShortAcross(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (uint8)AMPDTCShortAcross(DEVICE_AMP2,CHANNEL_AVAS);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCAVAS_SHORTACROSS,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Dem_SetEventStatus(DemConf_DemEventParameter_Speaker_AVAS_ShortAcross,DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC AVAS ShortAcross Report %d",DTCRet);
            EventDTCCfg.Active[DTCAVAS_SHORTACROSS] = FALSE;
        }
		AVASDTCRetData.ShortAcross = DTCRet;
    }
}

/***********************************************************************
 * @brief       : FL Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_FLClip(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = AMPDTCClip(DEVICE_AMP1,CHANNEL_FL);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCFL_CLIP,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0125_FLOutputClip_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC FL Clip Report %d",DTCRet);
            EventDTCCfg.Active[DTCFL_CLIP] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : FR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_FRClip(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = AMPDTCClip(DEVICE_AMP1,CHANNEL_FR);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCFR_CLIP,&EventDTCCfg);
    
    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0225_FROutputClip_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC FR Clip Report %d",DTCRet);
            EventDTCCfg.Active[DTCFR_CLIP] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RL Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_RLClip(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = AMPDTCClip(DEVICE_AMP1,CHANNEL_RL);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCRL_CLIP,&EventDTCCfg);
    
    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0325_RLOutputClip_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC RL Clip Report %d",DTCRet);
            EventDTCCfg.Active[DTCRL_CLIP] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_RRClip(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = AMPDTCClip(DEVICE_AMP1,CHANNEL_RR);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCRR_CLIP,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0425_RROutputClip_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC RR Clip Report %d",DTCRet);
            EventDTCCfg.Active[DTCRR_CLIP] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_WooferClip(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = (AMPDTCClip(DEVICE_AMP2,CHANNEL_SW1) ||AMPDTCClip(DEVICE_AMP2,CHANNEL_SW2));
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCWOOFER_CLIP,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0625_WooferOutputClip_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC Woofer Clip Report %d",DTCRet);
            EventDTCCfg.Active[DTCWOOFER_CLIP] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_CenterClip(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = AMPDTCClip(DEVICE_AMP2,CHANNEL_CENTER);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCCENTER_CLIP,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Rte_Call_DTC9A0525_CenterOutputClip_SetEventStatus(DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC Center Clip Report %d",DTCRet);
            EventDTCCfg.Active[DTCCENTER_CLIP] = FALSE;
        }
    }
}

/***********************************************************************
 * @brief       : RR Open DTC Report Logic
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTC_AVASClip(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    uint8 DTCMonitorSts = AMPDTCClip(DEVICE_AMP2,CHANNEL_AVAS);
    DTCRet = AMPDTCReportDebounce(DTCMonitorSts,DTCAVAS_CLIP,&EventDTCCfg);

    if((DTCREPORTFAILED == DTCRet) || (DTCREPORTPASSED == DTCRet))
    {
        DTCSendRet = Dem_SetEventStatus(DemConf_DemEventParameter_Speaker_AVAS_WaveformLackFidelity,DTCRet);
        if(E_OK == DTCSendRet)
        {
            AMP_DTCLOG("DTC Avas Clip Report %d",DTCRet);
            EventDTCCfg.Active[DTCAVAS_CLIP] = FALSE;
        }
        AVASDTCRetData.Clip = DTCRet;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMPDTC_MainFunc(uint8 dev_id)
{
	uint32 DTCClrReq;
    SystemState_RecordType SysValue;

	/* Clip and other fails report to SOC */
    AMP_NormalIPCLogic(dev_id);

	(void)Rte_Read_AMP_rpSR_Power_Out_SystemStateOut(&SysValue);

	/* When voltage condition is not met, clear debounce count and DTC don't report */
	if( (SysValue.s_PowerVoltage.value >= DTC_UNDERVOL_VAL) && (SysValue.s_PowerVoltage.value <= DTC_OVERVOL_VAL) )
	{
		if(DEVICE_AMP1 == dev_id)
		{
			AMP1_DTCLogic();
		}
		else if(DEVICE_AMP2 == dev_id)
		{
			AMP2_DTCLogic();
		}
	}
	else
	{
		AMPDTCDebounceClr(dev_id);
	}

	/* 14 service, clear DTC debounce count. Each time the 14 service is triggered, the counter + 1 */
	/* when system off to on, DTC module will trigger this service */
	Rte_Read_rpSR_piDiagMonitorReInitFlag_ChangeCounter( &DTCClrReq );
	if( DTCclrReqCnt != DTCClrReq )
	{
		DTCclrReqCnt = DTCClrReq;
		AMPDTCDebounceClr(dev_id);
	}
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMP1_DTCLogic(void)
{
    if(CHANNEL_NONE != AMPDTCCHCfg[DEVICE_AMP1].Channel.CH1)
    {
        if(TRUE == EventDTCCfg.Active[DTCFL_OPEN])
        {
			AMPDTC_FLOpen();
		}
        if(TRUE == EventDTCCfg.Active[DTCFL_OUTOFRANGE])
        {
			AMPDTC_FLOutofRange();
		}
        if(TRUE == EventDTCCfg.Active[DTCFL_SHORTACROSS])
        {
			AMPDTC_FLShortAcross();
		}
        AMPDTC_FLShortToGND();
        AMPDTC_FLShortToBAT();
        AMPDTC_FLClip();
    }
    if(CHANNEL_NONE != AMPDTCCHCfg[DEVICE_AMP1].Channel.CH2)
    {
        if(TRUE == EventDTCCfg.Active[DTCFR_OPEN])
        {
			AMPDTC_FROpen();
		}
        if(TRUE == EventDTCCfg.Active[DTCFR_OUTOFRANGE])
        {
			AMPDTC_FROutofRange();
		}
        if(TRUE == EventDTCCfg.Active[DTCFR_SHORTACROSS])
        {
			AMPDTC_FRShortAcross();
		}
        AMPDTC_FRShortToGND();
        AMPDTC_FRShortToBAT();
        AMPDTC_FRClip();
    }
    if(CHANNEL_NONE != AMPDTCCHCfg[DEVICE_AMP1].Channel.CH3)
    {
        if(TRUE == EventDTCCfg.Active[DTCRL_OPEN])
        {
			AMPDTC_RLOpen();
		}
        if(TRUE == EventDTCCfg.Active[DTCRL_OUTOFRANGE])
        {
			AMPDTC_RLOutofRange();
		}
        if(TRUE == EventDTCCfg.Active[DTCRL_SHORTACROSS])
        {
			AMPDTC_RLShortAcross();
		}
        AMPDTC_RLShortToGND();
        AMPDTC_RLShortToBAT();
        AMPDTC_RLClip();
    }
    if(CHANNEL_NONE != AMPDTCCHCfg[DEVICE_AMP1].Channel.CH4)
    {
        if(TRUE == EventDTCCfg.Active[DTCRR_OPEN])
        {
			AMPDTC_RROpen();
		}
        if(TRUE == EventDTCCfg.Active[DTCRR_OUTOFRANGE])
        {
			AMPDTC_RROutofRange();
		}
        if(TRUE == EventDTCCfg.Active[DTCRR_SHORTACROSS])
        {
			AMPDTC_RRShortAcross();
		}
        AMPDTC_RRShortToGND();
        AMPDTC_RRShortToBAT();
        AMPDTC_RRClip();
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMP2_DTCLogic(void)
{
    if((CHANNEL_NONE != AMPDTCCHCfg[DEVICE_AMP2].Channel.CH1) && (CHANNEL_NONE != AMPDTCCHCfg[DEVICE_AMP2].Channel.CH2))
    {
        if(TRUE == EventDTCCfg.Active[DTCWOOFER_OPEN])
        {
			AMPDTC_WooferOpen();
		}
        if(TRUE == EventDTCCfg.Active[DTCWOOFER_OUTOFRANGE])
        {
			AMPDTC_WooferOutofRange();
		}
        if(TRUE == EventDTCCfg.Active[DTCWOOFER_SHORTACROSS])
        {
			AMPDTC_WooferShortAcross();
        }
        AMPDTC_WooferShortToGND();
        AMPDTC_WooferShortToBAT();
        AMPDTC_WooferClip();
    }
    if(CHANNEL_NONE != AMPDTCCHCfg[DEVICE_AMP2].Channel.CH3)
    {
        if(TRUE == EventDTCCfg.Active[DTCCENTER_OPEN])
        {
			AMPDTC_CenterOpen();
		}
        if(TRUE == EventDTCCfg.Active[DTCCENTER_OUTOFRANGE])
        {
			AMPDTC_CenterOutofRange();
        }
        if(TRUE == EventDTCCfg.Active[DTCCENTER_SHORTACROSS])
        {
			AMPDTC_CenterShortAcross();
		}
        AMPDTC_CenterShortToGND();
        AMPDTC_CenterShortToBAT();
        AMPDTC_CenterClip();
    }
    if(CHANNEL_NONE != AMPDTCCHCfg[DEVICE_AMP2].Channel.CH4)
    {
        if(TRUE == EventDTCCfg.Active[DTCAVAS_OPEN])
        {
			AMPDTC_AVASOpen();
		}
        if(TRUE == EventDTCCfg.Active[DTCAVAS_OUTOFRANGE])
        {
			AMPDTC_AVASOutofRange();
		}
        if(TRUE == EventDTCCfg.Active[DTCAVAS_SHORTACROSS])
        {
			AMPDTC_AVASShortAcross();
        }
        AMPDTC_AVASShortToGND();
        AMPDTC_AVASShortToBAT();
        AMPDTC_AVASClip();
        (void)Rte_Write_AMP_AVASDTCResults_AVASDTC(&AVASDTCRetData);
    }    
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_EOLSpeakerSts(uint8 *ptr, uint8 length)
{
    uint8 SpeakerSts[4] = {0u};

    if(VCONFIG_NONE != AMPDevVCfg)
    {
        uint8 index;

        for(index = 0u;index < 8u;index ++)
        {
            uint8 ret = 0u;
            if(IICChannelData[index / 4][index % 4].ChannelErr.Channel.ShortToGroundDetected)
            {
                ret = AMP_EOLCHANNEL_SHORTGND;
            }
            else if(IICChannelData[index / 4][index % 4].ChannelErr.Channel.ShortToSupplyDetected)
            {
                ret = AMP_EOLCHANNEL_SHORTBAT;
            }
            else if( AMPDTCOpen((uint8)(index/4u), (uint8)(index%4u)) )
            {
                ret = AMP_EOLCHANNEL_OPEN;
            }
            else if( !AMPDTCOutofRange((uint8)(index/4u), (uint8)(index%4u)) )
            {
                ret = AMP_EOLCHANNEL_CONNECT;
            }
            else if( AMPDTCShortAcross((uint8)(index/4u), (uint8)(index%4u)) )
            {
                ret = AMP_EOLCHANNEL_SHORTACROSS;
            }
            
            if(0u == (index % 2u))
            {
                SpeakerSts[index/2] = (ret << 4u);
            }
            else
            {
                SpeakerSts[index/2] += ret;
            }
        }

		/* if not cfg this channel, set channl state 'AMP_EOLNOTSUPPORT' */
		if(CHANNEL_NONE == AMPDTCCHCfg[DEVICE_AMP1].Channel.CH1)
		{
			SpeakerSts[0] &= 0x0Fu;
		}
		if(CHANNEL_NONE == AMPDTCCHCfg[DEVICE_AMP1].Channel.CH2)
		{
			SpeakerSts[0] &= 0xF0u;
		}
		if(CHANNEL_NONE == AMPDTCCHCfg[DEVICE_AMP1].Channel.CH3)
		{
			SpeakerSts[1] &= 0x0Fu;
		}
		if(CHANNEL_NONE == AMPDTCCHCfg[DEVICE_AMP1].Channel.CH4)
		{
			SpeakerSts[1] &= 0xF0u;
		}
		if(CHANNEL_NONE == AMPDTCCHCfg[DEVICE_AMP2].Channel.CH1)
		{
			SpeakerSts[2] &= 0x0Fu;
		}
		if(CHANNEL_NONE == AMPDTCCHCfg[DEVICE_AMP2].Channel.CH2)
		{
			SpeakerSts[2] &= 0xF0u;
		}
		if(CHANNEL_NONE == AMPDTCCHCfg[DEVICE_AMP2].Channel.CH3)
		{
			SpeakerSts[3] &= 0x0Fu;
		}
		if(CHANNEL_NONE == AMPDTCCHCfg[DEVICE_AMP2].Channel.CH4)
		{
			SpeakerSts[3] &= 0xF0u;
		}
    }
    (void)memcpy(ptr,SpeakerSts,length);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
uint8 AMP8532_SelfCheckStsSet(uint8 dev_id,uint8 StsResult)
{
    uint8 ret;
    if(dev_id >= DEVICE_NUM)
    {
        (void)amp_err("Self check Device number error");
        ret = 0u;
    }
    else 
    {
        AMP_SelfCheckResult[dev_id].AMP_Sts = StsResult;
        ret = 1u;
    }
    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
uint8 AMP8532_SelfCheckResult(uint8 dev_id, uint8 CheckType,const I2C_AMPReq_t * I2C_Data)
{
    uint8 ret;
    if(dev_id >= DEVICE_NUM)
    {
        (void)amp_err("Self check Device number error");
        ret = 0u;
    }
    else if(CheckType >= AMPSELFCHECKTYPE_NUM)
    {
        (void)amp_err("Self chenck CheckType error");
        ret = 0u;
    }
    else
    {
        if(AMPSELFCHECKTYPE_DCLOAD == CheckType)
        {
            uint8 ChannelIndex;
            for(ChannelIndex = 0u;ChannelIndex < AMP8532_CHANNEL_NUM;ChannelIndex ++)
            {
                AMP_SelfCheckResult[dev_id].DCDiagResult[ChannelIndex] = I2C_Data->Data[7 + (ChannelIndex * 7)];
				if( AMP_SelfCheckResult[dev_id].DCDiagResult[ChannelIndex] != AMPDCLOADNORMAL )
				{
					(void)amp_warn("AMP%d CH%d DCreg fail = %d",dev_id+1,ChannelIndex,AMP_SelfCheckResult[dev_id].DCDiagResult[ChannelIndex]);
				}
            }
        }
        else if(AMPSELFCHECKTYPE_ACLOAD == CheckType)
        {
            uint8 ChannelIndex;
            for(ChannelIndex = 0u;ChannelIndex < AMP8532_CHANNEL_NUM;ChannelIndex ++)
            {
                AMP_SelfCheckResult[dev_id].ACDiagResult[ChannelIndex] = I2C_Data->Data[7 + (ChannelIndex * 8)];
            }
        }
        else if(AMPSELFCHECKTYPE_NONE == CheckType)
        {
            /* default data*/
        }
        ret = 0u;
    }
    return ret;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
uint8 AMP8532_MonitorResult(uint8 dev_id, uint8 MonitorType,const I2C_AMPReq_t * I2C_Data)
{
    uint8 ret;
    if(dev_id >= DEVICE_NUM)
    {
        (void)amp_err("Period Diag Device number error");
        ret = AMPMONITOR_RESULT_DEVICEINDEXERR;
    }
    else if(MonitorType >= AMPMONITOR_NUM)
    {
        (void)amp_err("Period Diag CheckType error");
        ret = AMPMONITOR_RESULT_DIAGPINERR;
    }
    else
    {
        if(AMPMONITOR_DEVICE == MonitorType)
        {
            IICDeviceData[dev_id].DeviceSts.DevSts1.Data = I2C_Data->Data[5];
            IICDeviceData[dev_id].DeviceSts.DevSts2.Data = I2C_Data->Data[6];
            IICDeviceData[dev_id].DeviceState = I2C_Data->Data[8];
            AMPDeviceLog(dev_id);
            (void)memcpy(&IICDeviceDataBackup[dev_id],&IICDeviceData[dev_id],sizeof(s_DeviceData_Type));
        }
        else if(AMPMONITOR_CHANNEL == MonitorType)
        {
            uint8 ChannelIndex;
            for(ChannelIndex = 0u;ChannelIndex < AMP8532_CHANNEL_NUM;ChannelIndex ++)
            {
                IICChannelData[dev_id][ChannelIndex].Status = I2C_Data->Data[7 + (ChannelIndex * 6)];
                IICChannelData[dev_id][ChannelIndex].ChannelErr.Data = I2C_Data->Data[10 + (ChannelIndex * 6)];
                AMPChannelLog(dev_id,ChannelIndex);
                (void)memcpy(&IICChannelDataBackup[dev_id][ChannelIndex],&IICChannelData[dev_id][ChannelIndex],sizeof(s_ChannelData_Type));
            }
        }
        else if(AMPSELFCHECKTYPE_NONE == MonitorType)
        {
            /* default data*/
        }
        ret = AMPMONITOR_RESULT_NOERR;
    }
    AMPIPCDDiagResultData(dev_id,MonitorType);
    return ret;
}

/***********************************************************************
 * @brief       : N2 LC Monitor
 * @param       : 
 * @retval      : 
 ***********************************************************************/
uint8 AMP8532N2_MonitorResult(uint8 dev_id, uint8 MonitorType,const I2C_AMPReq_t * I2C_Data)
{
    uint8 ret;

    if(dev_id >= DEVICE_NUM)
    {
        (void)amp_err("Period Diag Device number error");
        ret = AMPMONITOR_RESULT_DEVICEINDEXERR;
    }
    else if(MonitorType >= AMPMONITORN2_NUM)
    {
        (void)amp_err("Period Diag CheckType error");
        ret = AMPMONITOR_RESULT_DIAGPINERR;
    }
    else
    {
        if(AMPMONITORN2_DEVICE == MonitorType)
        {
            IICDeviceData[dev_id].DeviceState = I2C_Data->Data[5];
            AMPDeviceLog(dev_id);
            (void)memcpy(&IICDeviceDataBackup[dev_id],&IICDeviceData[dev_id],sizeof(s_DeviceData_Type));
        }
        else if(AMPMONITOR_FAULT == MonitorType)
        {
            IICDeviceData[dev_id].DeviceSts.DevSts1.Data = I2C_Data->Data[5];
			IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.ChargePumpError = (I2C_Data->Data[6] & 0x01u);
			IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.SlaveWaitingForSync = ((I2C_Data->Data[6] >> 1u) & 0x01u);
            AMPDeviceLog(dev_id);
            (void)memcpy(&IICDeviceDataBackup[dev_id],&IICDeviceData[dev_id],sizeof(s_DeviceData_Type));
        }
        else if(AMPMONITOR_AUDIO == MonitorType)
        {
			IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.MissingSCLKEdgeDetected = (I2C_Data->Data[5] & 0x01u);
			IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.MissingFSEdgeDetected = ((I2C_Data->Data[5] >> 1u) & 0x01u);
			IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.FrameErrorDetected = ((I2C_Data->Data[5] >> 2u) & 0x01u);
            AMPDeviceLog(dev_id);
            (void)memcpy(&IICDeviceDataBackup[dev_id],&IICDeviceData[dev_id],sizeof(s_DeviceData_Type));
        }
        else
        {
            /* default data*/
        }
        ret = AMPMONITOR_RESULT_NOERR;
    }
    AMPIPCDDiagResultData(dev_id,AMPMONITOR_DEVICE);

    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDeviceLog(uint8 dev_id)
{
    if(IICDeviceData[dev_id].DeviceState != IICDeviceDataBackup[dev_id].DeviceState)
    {
        (void)amp_info("[AMP%d] Device State Change From %d to %d",dev_id + 1,IICDeviceDataBackup[dev_id].DeviceState,IICDeviceData[dev_id].DeviceState);
    }
    if(IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.AutoMuteActive != IICDeviceDataBackup[dev_id].DeviceSts.DevSts1.DevSts1Bit.AutoMuteActive)
    {
        (void)amp_info("[AMP%d] AutoMuteActive State Change From %d to %d",dev_id + 1,IICDeviceDataBackup[dev_id].DeviceSts.DevSts1.DevSts1Bit.AutoMuteActive,IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.AutoMuteActive);
    }
    if(IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.VDDAUnderVoltageLockoutActive          != IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.VDDAUnderVoltageLockoutActive)
    {
        (void)amp_info("[AMP%d] VDDAUnderVoltageLockoutActive State Change From %d to %d",dev_id + 1,IICDeviceDataBackup[dev_id].DeviceSts.DevSts1.DevSts1Bit.VDDAUnderVoltageLockoutActive,IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.VDDAUnderVoltageLockoutActive);
    }
    if(IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.VDDPUnderVoltageProtectionActive       != IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.VDDPUnderVoltageProtectionActive)
    {
        (void)amp_info("[AMP%d] VDDPUnderVoltageProtectionActive State Change From %d to %d",dev_id + 1,IICDeviceDataBackup[dev_id].DeviceSts.DevSts1.DevSts1Bit.VDDPUnderVoltageProtectionActive,IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.VDDPUnderVoltageProtectionActive);
    }
    if(IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.OverVoltageWarningActive               != IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.OverVoltageWarningActive)
    {
        (void)amp_info("[AMP%d] OverVoltageWarningActive State Change From %d to %d",dev_id + 1,IICDeviceDataBackup[dev_id].DeviceSts.DevSts1.DevSts1Bit.OverVoltageWarningActive,IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.OverVoltageWarningActive);
    }
    if(IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.OverVoltageProtectionActive            != IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.OverVoltageProtectionActive)
    {
        (void)amp_info("[AMP%d] OverVoltageProtectionActive State Change From %d to %d",dev_id + 1,IICDeviceDataBackup[dev_id].DeviceSts.DevSts1.DevSts1Bit.OverVoltageProtectionActive,IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.OverVoltageProtectionActive);
    }
    if(IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.ThermalFoldbackModeActive              != IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.ThermalFoldbackModeActive)
    {
        (void)amp_info("[AMP%d] ThermalFoldbackModeActive State Change From %d to %d",dev_id + 1,IICDeviceDataBackup[dev_id].DeviceSts.DevSts1.DevSts1Bit.ThermalFoldbackModeActive,IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.ThermalFoldbackModeActive);
    }
    if(IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.OverTemperatureWarningActive           != IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.OverTemperatureWarningActive)
    {
        (void)amp_info("[AMP%d] OverTemperatureWarningActive State Change From %d to %d",dev_id + 1,IICDeviceDataBackup[dev_id].DeviceSts.DevSts1.DevSts1Bit.OverTemperatureWarningActive,IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.OverTemperatureWarningActive);
    }
    if(IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.OverTemperatureProtectionActive        != IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.OverTemperatureProtectionActive)
    {
        (void)amp_info("[AMP%d] OverTemperatureProtectionActive State Change From %d to %d",dev_id + 1,IICDeviceDataBackup[dev_id].DeviceSts.DevSts1.DevSts1Bit.OverTemperatureProtectionActive,IICDeviceData[dev_id].DeviceSts.DevSts1.DevSts1Bit.OverTemperatureProtectionActive);
    }
    if(IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.NonVolatileMemoryWriteStatus               != IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.NonVolatileMemoryWriteStatus)
    {
        (void)amp_info("[AMP%d] NonVolatileMemoryWriteStatus State Change From %d to %d",dev_id + 1,IICDeviceDataBackup[dev_id].DeviceSts.DevSts2.DevSts2Bit.NonVolatileMemoryWriteStatus,IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.NonVolatileMemoryWriteStatus);
    }
    if(IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.NonVolatileMemoryReadErrorCorrected        != IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.NonVolatileMemoryReadErrorCorrected)
    {
        (void)amp_info("[AMP%d] NonVolatileMemoryReadErrorCorrected State Change From %d to %d",dev_id + 1,IICDeviceDataBackup[dev_id].DeviceSts.DevSts2.DevSts2Bit.NonVolatileMemoryReadErrorCorrected,IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.NonVolatileMemoryReadErrorCorrected);
    }
    if(IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.NonVolatileMemoryReadErrorNotCorrected     != IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.NonVolatileMemoryReadErrorNotCorrected)
    {
        (void)amp_info("[AMP%d] NonVolatileMemoryReadErrorNotCorrected State Change From %d to %d",dev_id + 1,IICDeviceDataBackup[dev_id].DeviceSts.DevSts2.DevSts2Bit.NonVolatileMemoryReadErrorNotCorrected ,IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.NonVolatileMemoryReadErrorNotCorrected );
    }
    if(IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.FrameErrorDetected                         != IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.FrameErrorDetected)
    {
        (void)amp_info("[AMP%d] FrameErrorDetected State Change From %d to %d",dev_id + 1,IICDeviceDataBackup[dev_id].DeviceSts.DevSts2.DevSts2Bit.FrameErrorDetected,IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.FrameErrorDetected);
    }
    if(IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.MissingFSEdgeDetected                      != IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.MissingFSEdgeDetected)
    {
        (void)amp_info("[AMP%d] MissingFSEdgeDetected State Change From %d to %d",dev_id + 1,IICDeviceDataBackup[dev_id].DeviceSts.DevSts2.DevSts2Bit.MissingFSEdgeDetected,IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.MissingFSEdgeDetected);
    }
    if(IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.SlaveWaitingForSync                        != IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.SlaveWaitingForSync)
    {
        (void)amp_info("[AMP%d] SlaveWaitingForSync State Change From %d to %d",dev_id + 1,IICDeviceDataBackup[dev_id].DeviceSts.DevSts2.DevSts2Bit.SlaveWaitingForSync,IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.SlaveWaitingForSync);
    }
    if(IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.ChargePumpError                            != IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.ChargePumpError)
    {
        (void)amp_info("[AMP%d] ChargePumpError State Change From %d to %d",dev_id + 1,IICDeviceDataBackup[dev_id].DeviceSts.DevSts2.DevSts2Bit.ChargePumpError,IICDeviceData[dev_id].DeviceSts.DevSts2.DevSts2Bit.ChargePumpError);
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPChannelLog(uint8 dev_id,uint8 ChannelID)
{
    if(IICChannelData[dev_id][ChannelID].Status != IICChannelData[dev_id][ChannelID].Status)
    {
        (void)amp_info("[AMP%d][Channel%d] Status Change From %d to %d",dev_id + 1,ChannelID,IICChannelDataBackup[dev_id][ChannelID].Status,IICChannelData[dev_id][ChannelID].Status);
    }
    if(IICChannelData[dev_id][ChannelID].ChannelErr.Channel.CalibrationErrorDetected             != IICChannelDataBackup[dev_id][ChannelID].ChannelErr.Channel.CalibrationErrorDetected)
    {
        (void)amp_info("[AMP%d][Channel%d] CalibrationErrorDetected Change From %d to %d",dev_id + 1,ChannelID,IICChannelDataBackup[dev_id][ChannelID].ChannelErr.Channel.CalibrationErrorDetected,IICChannelData[dev_id][ChannelID].ChannelErr.Channel.CalibrationErrorDetected);
    }
    if(IICChannelData[dev_id][ChannelID].ChannelErr.Channel.OutputDCOffsetDetected               != IICChannelDataBackup[dev_id][ChannelID].ChannelErr.Channel.OutputDCOffsetDetected)
    {
        (void)amp_info("[AMP%d][Channel%d] OutputDCOffsetDetected Change From %d to %d",dev_id + 1,ChannelID,IICChannelDataBackup[dev_id][ChannelID].ChannelErr.Channel.OutputDCOffsetDetected,IICChannelData[dev_id][ChannelID].ChannelErr.Channel.OutputDCOffsetDetected);
    }
    if(IICChannelData[dev_id][ChannelID].ChannelErr.Channel.OutputClipping                       != IICChannelDataBackup[dev_id][ChannelID].ChannelErr.Channel.OutputClipping)
    {
        (void)amp_verbose("[AMP%d][Channel%d] OutputClipping Change From %d to %d",dev_id + 1,ChannelID,IICChannelDataBackup[dev_id][ChannelID].ChannelErr.Channel.OutputClipping,IICChannelData[dev_id][ChannelID].ChannelErr.Channel.OutputClipping);
    }
    if(IICChannelData[dev_id][ChannelID].ChannelErr.Channel.CurrentLimitingActive                != IICChannelDataBackup[dev_id][ChannelID].ChannelErr.Channel.CurrentLimitingActive)
    {
        (void)amp_info("[AMP%d][Channel%d] CurrentLimitingActive Change From %d to %d",dev_id + 1,ChannelID,IICChannelDataBackup[dev_id][ChannelID].ChannelErr.Channel.CurrentLimitingActive,IICChannelData[dev_id][ChannelID].ChannelErr.Channel.CurrentLimitingActive);
    }
    if(IICChannelData[dev_id][ChannelID].ChannelErr.Channel.ShortToGroundDetected                != IICChannelDataBackup[dev_id][ChannelID].ChannelErr.Channel.ShortToGroundDetected)
    {
        (void)amp_info("[AMP%d][Channel%d] ShortToGroundDetected Change From %d to %d",dev_id + 1,ChannelID,IICChannelDataBackup[dev_id][ChannelID].ChannelErr.Channel.ShortToGroundDetected,IICChannelData[dev_id][ChannelID].ChannelErr.Channel.ShortToGroundDetected);
    }
    if(IICChannelData[dev_id][ChannelID].ChannelErr.Channel.ShortToExternalVoltageDetected       != IICChannelDataBackup[dev_id][ChannelID].ChannelErr.Channel.ShortToExternalVoltageDetected)
    {
        (void)amp_info("[AMP%d][Channel%d] ShortToExternalVoltageDetected Change From %d to %d",dev_id + 1,ChannelID,IICChannelDataBackup[dev_id][ChannelID].ChannelErr.Channel.ShortToExternalVoltageDetected,IICChannelData[dev_id][ChannelID].ChannelErr.Channel.ShortToExternalVoltageDetected);
    }
    if(IICChannelData[dev_id][ChannelID].ChannelErr.Channel.ShortToSupplyDetected                != IICChannelDataBackup[dev_id][ChannelID].ChannelErr.Channel.ShortToSupplyDetected)
    {
        (void)amp_info("[AMP%d][Channel%d] ShortToSupplyDetected Change From %d to %d",dev_id + 1,ChannelID,IICChannelDataBackup[dev_id][ChannelID].ChannelErr.Channel.ShortToSupplyDetected,IICChannelData[dev_id][ChannelID].ChannelErr.Channel.ShortToSupplyDetected);
    }
    if(IICChannelData[dev_id][ChannelID].ChannelErr.Channel.ShortAcrossLoadDetected              != IICChannelDataBackup[dev_id][ChannelID].ChannelErr.Channel.ShortAcrossLoadDetected)
    {
        (void)amp_info("[AMP%d][Channel%d] ShortAcrossLoadDetected Change From %d to %d",dev_id + 1,ChannelID,IICChannelDataBackup[dev_id][ChannelID].ChannelErr.Channel.ShortAcrossLoadDetected,IICChannelData[dev_id][ChannelID].ChannelErr.Channel.ShortAcrossLoadDetected);
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPIPCDDiagResultData(uint8 dev_id, uint8 MonitorType)
{
    if(AMPMONITOR_DEVICE == MonitorType)
    {
        AMPIPCDiagResult[dev_id].DeviceDiagResults_1 = IICDeviceData[dev_id].DeviceSts.DevSts1.Data;
        AMPIPCDiagResult[dev_id].DeviceDiagResults_2 = IICDeviceData[dev_id].DeviceSts.DevSts2.Data;
    }
    else if(AMPMONITOR_CHANNEL == MonitorType)
    {
        AMPIPCDiagResult[dev_id].CH1DiagResults = IICChannelData[dev_id][0].ChannelErr.Data;
        AMPIPCDiagResult[dev_id].CH2DiagResults = IICChannelData[dev_id][1].ChannelErr.Data;
        AMPIPCDiagResult[dev_id].CH3DiagResults = IICChannelData[dev_id][2].ChannelErr.Data;
        AMPIPCDiagResult[dev_id].CH4DiagResults = IICChannelData[dev_id][3].ChannelErr.Data;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMPSendAudioStartupResult(void)
{
    /*not need Check, as if lost audio will retry */
    if(VCONFIG_BOTHAMP == AMPDevVCfg)
    {
        IPC_M2S_AudioAMPAmp1StartupDiagResults_t AMP8532_1_Startup_Diag;
        IPC_M2S_AudioAMPAmp2StartupDiagResults_t AMP8532_2_Startup_Diag;
        (void)memcpy(&AMP8532_1_Startup_Diag,&AMP_SelfCheckResult[DEVICE_AMP1],sizeof(e_AMP_SelfCheckResult_t));
        (void)IPC_M2S_AudioAMPAmp1StartupDiagResults_Transmit(&AMP8532_1_Startup_Diag);
        (void)memcpy(&AMP8532_2_Startup_Diag,&AMP_SelfCheckResult[DEVICE_AMP2],sizeof(e_AMP_SelfCheckResult_t));
        (void)IPC_M2S_AudioAMPAmp2StartupDiagResults_Transmit(&AMP8532_2_Startup_Diag);
    }
    else if(VCONFIG_ONLYAMP1 == AMPDevVCfg)
    {
        IPC_M2S_AudioAMPAmp1StartupDiagResults_t AMP8532_1_Startup_Diag;
        (void)memcpy(&AMP8532_1_Startup_Diag,&AMP_SelfCheckResult[DEVICE_AMP1],sizeof(e_AMP_SelfCheckResult_t));
        (void)IPC_M2S_AudioAMPAmp1StartupDiagResults_Transmit(&AMP8532_1_Startup_Diag);
    }
    else if(VCONFIG_ONLYAMP2 == AMPDevVCfg)
    {
        IPC_M2S_AudioAMPAmp2StartupDiagResults_t AMP8532_2_Startup_Diag;
        (void)memcpy(&AMP8532_2_Startup_Diag,&AMP_SelfCheckResult[DEVICE_AMP2],sizeof(e_AMP_SelfCheckResult_t));
        (void)IPC_M2S_AudioAMPAmp2StartupDiagResults_Transmit(&AMP8532_2_Startup_Diag);
    }
	else
	{
		/* do nothing */
	}
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMP_NormalIPCLogic(uint8 dev_id)
{
    if(DEVICE_AMP1 == dev_id)
    {
        AMP_IPCCuntLogic(DEVICE_AMP1);
        if((FALSE != memcmp(&AMPIPCDiagResult[DEVICE_AMP1],&AMPIPCDiagResultBackup[DEVICE_AMP1],sizeof(s_IPCDiagResult_Type))) ||
            (AMP_IPCTIMEOUT == AMP_IPCResponse[DEVICE_AMP1]))
        {
            /* not need check ipc buffer, as wait audio ack */
            
            (void)IPC_M2S_AudioAMPAmp1PeriodDiagResults_Transmit((IPC_M2S_AudioAMPAmp1PeriodDiagResults_t *)(void *)(&AMPIPCDiagResult[DEVICE_AMP1]));
            //AMP_IPCResponse[DEVICE_AMP1] = AMP_IPCTIMEPENDING;
        }
        (void)memcpy(&AMPIPCDiagResultBackup[DEVICE_AMP1],&AMPIPCDiagResult[DEVICE_AMP1],sizeof(s_IPCDiagResult_Type));
    }
    else if(DEVICE_AMP2 == dev_id)
    {
        AMP_IPCCuntLogic(DEVICE_AMP2);
        if((FALSE != memcmp(&AMPIPCDiagResult[DEVICE_AMP2],&AMPIPCDiagResultBackup[DEVICE_AMP2],sizeof(s_IPCDiagResult_Type))) ||
            (AMP_IPCTIMEOUT == AMP_IPCResponse[DEVICE_AMP2]))
        {
            /* not need check ipc buffer, as wait audio ack */
            (void)IPC_M2S_AudioAMPAmp2PeriodDiagResults_Transmit((IPC_M2S_AudioAMPAmp2PeriodDiagResults_t *)(void *)(&AMPIPCDiagResult[DEVICE_AMP2]));
            AMP_IPCResponse[DEVICE_AMP2] = AMP_IPCTIMEPENDING;
        }
        (void)memcpy(&AMPIPCDiagResultBackup[DEVICE_AMP2],&AMPIPCDiagResult[DEVICE_AMP2],sizeof(s_IPCDiagResult_Type));
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMPIPCReceiveACK(uint8 dev_id)
{
    AMP_IPCResponse[dev_id] = AMP_IPCTIMEDONE;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMP_IPCCuntLogic(uint8 dev_id)
{   
    if(AMP_IPCTIMEPENDING == AMP_IPCResponse[dev_id])
    {
        AMP_IPCACKCunt[dev_id] ++;
        if(AMP_IPCACKCunt[dev_id] >= 50)
        {
            AMP_IPCACKCunt[dev_id] = 0u;
            AMP_IPCResponse[DEVICE_AMP1] = AMP_IPCTIMEOUT;
        }
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint8 AMPDTCReportDebounce(uint8 errorStatus,uint8 DTCID, const s_EventDTC_t *EventDTC)
{
    uint8 tEventSts;
    uint8 Ret = DTCREPORTNONE;
    s_EventDebounce_t *tEventDebounce = &EventDTCCfg.eventDebounce[DTCID];
    const s_EventDebounceCfg_t *tEventDebounceCfg = &EventDTCCfg.eventDebounceCfg[DTCID];
    tEventSts = EventDTC->eventStatus[DTCID];
    if(TRUE == errorStatus)
    {
        tEventDebounce->passedCounter = 0;
        tEventDebounce->failedCounter++;
        if(tEventDebounce->failedCounter > tEventDebounceCfg->FailThreshold)
        {
            tEventSts = DEM_EVENT_STATUS_FAILED;
            tEventDebounce->failedCounter = 0;
        }
    }
    else
    {
        tEventDebounce->failedCounter = 0;
        tEventDebounce->passedCounter++;
        if(tEventDebounce->passedCounter > tEventDebounceCfg->PassThreshold)
        {
            tEventSts = DEM_EVENT_STATUS_PASSED;
            tEventDebounce->passedCounter = 0;
        }
    }
    
    if(tEventSts == EventDTC->eventStatus[DTCID])
    {
        tEventDebounce->monitorCounter++;
        if ((DEM_EVENT_STATUS_PASSED == EventDTC->eventStatus[DTCID]) && (tEventDebounce->monitorCounter > tEventDebounceCfg->PassThreshold))
        {
            tEventDebounce->monitorCounter = 0;
            Ret = DTCREPORTPASSED;
            return Ret;
        }
        else if ((DEM_EVENT_STATUS_FAILED == EventDTC->eventStatus[DTCID]) && (tEventDebounce->monitorCounter > tEventDebounceCfg->FailThreshold))
        {
            tEventDebounce->monitorCounter = 0;
            Ret = DTCREPORTFAILED;
            return Ret;
        }
        else
        {
            return Ret;
        }
    }
    else
    {
        if(DEM_EVENT_STATUS_PASSED == tEventSts)
        {
            Ret = DTCREPORTPASSED;
        }   
        else if(DEM_EVENT_STATUS_FAILED == tEventSts)
        {
            Ret = DTCREPORTFAILED;
        }
        EventDTC->eventStatus[DTCID] = tEventSts;
        tEventDebounce->monitorCounter = 0;
        return Ret;
    }
}

/***********************************************************************
 * @brief       : 14 service, Clear All DTC Debounce cnt
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void AMPDTCDebounceClr(uint8 dev_id)
{
    if(dev_id == DEVICE_AMP1)
    {
        (void)memset(&AMPEventDebounce[0],0,sizeof(s_EventDebounce_t)*DTCWOOFER_OPEN);
    }
    else if(dev_id == DEVICE_AMP2) 
    {
        (void)memset(&AMPEventDebounce[DTCWOOFER_OPEN],0,sizeof(s_EventDebounce_t)*(DTCAMPNUM-DTCWOOFER_OPEN));
    }
	else
	{
		/* do nothing */
	}
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint8 AMPDTCClip(uint8 dev_id,uint8 ChannelID)
{
    return AMPClipResult[dev_id].ChannelClip[ChannelID];
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean AMPDTCOpen(uint8 dev_id,uint8 ChannelID)
{
    return(AMPDCLOADOPEN == AMP_SelfCheckResult[dev_id].DCDiagResult[ChannelID]);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean AMPDTCOutofRange(uint8 dev_id,uint8 ChannelID)
{
    return(AMPDCLOADNORMAL != AMP_SelfCheckResult[dev_id].DCDiagResult[ChannelID]);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean AMPDTCShortAcross(uint8 dev_id,uint8 ChannelID)
{
    return(AMPDCLOADSHORTACROSS == AMP_SelfCheckResult[dev_id].DCDiagResult[ChannelID]);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint8 AMPDTCShortToGND(uint8 dev_id,uint8 ChannelID)
{
    return IICChannelData[dev_id][ChannelID].ChannelErr.Channel.ShortToGroundDetected;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint8 AMPDTCShortToBAT(uint8 dev_id,uint8 ChannelID)
{
    return IICChannelData[dev_id][ChannelID].ChannelErr.Channel.ShortToSupplyDetected;
}

/***********************************************************************
 * @brief       : Clear Diag2 Diag Result
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMPClearDiag2Result(uint8 dev_id)
{
    uint8 CHID = 0u;
    for(CHID = 0u; CHID < 4u; CHID++)
    {
        IICChannelData[dev_id][CHID].ChannelErr.Data = 0u;
    }
}

#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"
    
