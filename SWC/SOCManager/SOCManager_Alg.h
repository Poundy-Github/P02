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
 * @file:      SOCManager_Alg.h
 * @author:    Nobo
 * @date:      2020-10-28
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-10-28
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _SOCMANAGER_ALG_H_
#define _SOCMANAGER_ALG_H_

#include "VariantCfg.h"
#include "Ext_Power.h"
#include "DevConfig.h"

#ifdef DEV_DEBUG_ON
#define DEF_SOCMANAGER_HEATH                            STD_OFF
#else
#define DEF_SOCMANAGER_HEATH                            STD_ON
#endif
#if ((defined GWM_V35_PROJECT_TYPE_ES13) || (defined GWM_V35_PROJECT_TYPE_EC24) || (defined GWM_V35_PROJECT_TYPE_ES24) || (defined GWM_V35_PROJECT_TYPE_D01) ||\
	(defined GWM_V35_PROJECT_TYPE_D02) || (defined GWM_V35_PROJECT_TYPE_D03) || (defined GWM_V35_PROJECT_TYPE_P02) || (defined GWM_V35_PROJECT_TYPE_P09))
#define SOCM_POWER_IS_EV
#endif

#define SOCMANAGER_HANDSHAKE_TIMEOUT                    (60000u)
#define SOCMANAGER_HEATH_TIMEOUT                        (35000u)
#define SOCMANAGER_SOC_ON_TIMEOUT                       (1000u)
#define SOCMANAGER_SOC_OFF_TIMEOUT                      (500u)
#define SOCMANAGER_SOC_RESETMCUDELAY_TIMEOUT            (500u)
#define SOCMANAGER_CLOSE_AMP_TIMEOUT                    (2000u)
#define SOCMANAGER_MCURESET_TIMEOUT                     (10000u)
#define SOCMANAGER_SOCPOWEROFFREADY_TIMEOUT             (200u)
#define SOCMANAGER_SOCSHUTDOWN_TIMEOUT                  (4000u)
#define SOCMANAGER_LONGPRESS_TIMEOUT                    (10000u)
#define SOCMANAGER_SeekDwnAndPageLPRESS_TIMEOUT         (10000u)
#define SOCMANAGER_DiagtominiSystem_TIMEOUT             (15000u)

#ifdef PLATFORM_OF_STB_IPC_USED
#define SOCMANAGER_STB_HANDSHAKE_TIMEOUT                (60000u)
#endif
#define SOCMANAGER_HANDSHAKE_CNT_MAX                    (3u)
#define SOCMANAGER_APPHANDSHAKE_CNT_MAX                 (5u)
#define SOCMANAGER_HEALTH_CNT_MAX                       (5u)



typedef uint16  tSOCManager_EventDef_t;
#define eSOCManager_SocReqDef_HandshakeMask         ((tSOCManager_EventDef_t) 0x01)
#define eSOCManager_SocReqDef_HeathMask             ((tSOCManager_EventDef_t) 0x02)
#define eSOCManager_SocReqDef_ResetMCUMask          ((tSOCManager_EventDef_t) 0x04)
#define eSOCManager_SocReqDef_QueryVerMask          ((tSOCManager_EventDef_t) 0x08)
#define eSOCManager_SocReqDef_ResetSocMask          ((tSOCManager_EventDef_t) 0x10)
#define eSOCManager_SocReqDef_ResetSoc2MiniSysMask  ((tSOCManager_EventDef_t) 0x20)
#define eSOCManager_SocReqDef_SystemErrorMask       ((tSOCManager_EventDef_t) 0x40)     /* Soc runs on the smallest system  */
#define eSOCManager_SocReqDef_ResetCheckSocMiniOSMask   ((tSOCManager_EventDef_t) 0x80)
#define eSOCManager_SocReqDef_PowerOFFReadyMask     ((tSOCManager_EventDef_t) 0x100)
#define eSOCManager_SocReqDef_DownloadMask          ((tSOCManager_EventDef_t) 0x200)
#define eSOCManager_SocReqDef_HealthSetMask         ((tSOCManager_EventDef_t) 0x400)

#ifdef PLATFORM_OF_STB_IPC_USED
#define eSOCManager_SocReqDef_STB_HandshakeMask     ((tSOCManager_EventDef_t) 0x001)
#define eSOCManager_SocReqDef_STB_HeathMask         ((tSOCManager_EventDef_t) 0x002)
#endif

// TIME EVNET DEF
#define eSOCManager_Timerout_Handshake              ((tSOCManager_EventDef_t) 0x01)
#define eSOCManager_Timerout_Heath                  ((tSOCManager_EventDef_t) 0x02)
#define eSOCManager_Timerout_WaitSOC_ON             ((tSOCManager_EventDef_t) 0x04)
#define eSOCManager_Timerout_WaitSOC_OFF            ((tSOCManager_EventDef_t) 0x08)
#define eSOCManager_Timerout_WaitSOC_Reset          ((tSOCManager_EventDef_t) 0x10)
#define eSOCManager_Timerout_WaitAMPClose           ((tSOCManager_EventDef_t) 0x20)
#define eSOCManager_Timerout_McuReset               ((tSOCManager_EventDef_t) 0x40)
#define eSOCManager_Timerout_PowerOFFReady          ((tSOCManager_EventDef_t) 0x80)
#define eSOCManager_Timerout_SOCShutdown            ((tSOCManager_EventDef_t) 0x100)
#define eSOCManager_Timerout_LongPress              ((tSOCManager_EventDef_t) 0x200)
#define eSOCManager_Timerout_STB_Handshake          ((tSOCManager_EventDef_t) 0x400)
#define eSOCManager_Timerout_SeekDwnAndPageLLongPress  ((tSOCManager_EventDef_t) 0x800)
#define eSOCManager_Timerout_DiagtominiSystem       ((tSOCManager_EventDef_t) 0x1000)


// IPC Response Def
#define eSOCManager_Response_HandshakeMask          ((tSOCManager_EventDef_t) 0x01)
#define eSOCManager_Response_VersionMask            ((tSOCManager_EventDef_t) 0x02)
#define eSOCManager_Response_HeathMask              ((tSOCManager_EventDef_t) 0x04)

#ifdef PLATFORM_OF_STB_IPC_USED
#define eSOCManager_Response_STB_HandshakeMask      ((tSOCManager_EventDef_t) 0x01)
#define eSOCManager_Response_STB_HeathMask          ((tSOCManager_EventDef_t) 0x02)
#endif

// SOC RESET type define
typedef uint16 tSOCManager_ResetSrcDef;
#define eSOCManager_RESET_HandshakeMask             ((tSOCManager_ResetSrcDef) 0x0001)
#define eSOCManager_RESET_SHeathMask                ((tSOCManager_ResetSrcDef) 0x0002)
#define eSOCManager_RESET_SOCMask                   ((tSOCManager_ResetSrcDef) 0x0004)
#define eSOCManager_RESET_OtherMask                 ((tSOCManager_ResetSrcDef) 0x0008)

#define eSOCManager_EOLKeepDownload_Mask            ((tSOCManager_ResetSrcDef) 0x0010)
#define eSOCManager_EOLKeepNormal_Mask              ((tSOCManager_ResetSrcDef) 0x0020)
#define eSOCManager_SOCKeepDownload_Mask            ((tSOCManager_ResetSrcDef) 0x0040)


#define eSOCManager_RESET2MiniSys_HandshakeMask     ((tSOCManager_ResetSrcDef) 0x0100)
#define eSOCManager_RESET2MiniSys_SOCMask           ((tSOCManager_ResetSrcDef) 0x0200)
#define eSOCManager_RESET2MiniSys_DiagMask          ((tSOCManager_ResetSrcDef) 0x0400)
#define eSOCManager_RESET2MiniSys_SystemMismatchMask    ((tSOCManager_ResetSrcDef) 0x0800)

#define eSOCManager_RESETMCU_SOCMask                ((tSOCManager_ResetSrcDef) 0x1000)  //RESTORE FACTORY SETTINGS

#define eSOCManager_RESET_CombinationsKeyMask       ((tSOCManager_ResetSrcDef) 0x2000)  

/*APP Type*/
#define APP_INFOSM_LOCAL_STS                        (1u)
#define APP_INFOSM_NM                               (2u)
#define APP_INFOSM_DIAG2MINI                        (3u)
/*APP Value*/
#define SYSTEMSTATE_LOCAL_END	                    (2u)
#define SYSTEMSTATE_LOCAL_CONTINUE                  (1u)
#define SYSTEMSTATE_LOCAL_NO_REC                    (0u)
#define LOCAL_PRETIMEOUT_FLAG                       (1u)

#define SOCM_NOSEND                       			(0u)
#define SOCM_SEND                       			(1u)


typedef enum
{
    eSOCManager_SocState_None = 0,
    eSOCManager_SocState_ON,
    eSOCManager_SocState_OFF,
    eSOCManager_SocState_Reset,
    eSOCManager_SocState_DownloadMode,
    eSOCManager_SocState_ResetMCU,
    eSOCManager_SocState_Reset2MiniSys,
    eSOCManager_SocState_WarmReset,
    eSOCManager_SocState_Transition,
}tSOCManager_SocStateDef_t;

typedef uint8 tSOCManager_AMPStateCtrl_t;
#define eSOCManager_AMPStateCtrl_None           ((tSOCManager_AMPStateCtrl_t) 0)
#define eSOCManager_AMPStateCtrl_Open           ((tSOCManager_AMPStateCtrl_t) 1)
#define eSOCManager_AMPStateCtrl_Close          ((tSOCManager_AMPStateCtrl_t) 2)

typedef enum
{
    eSOCManager_SOCStartReason_Unknown = 0,
    eSOCManager_SOCStartReason_PowerOn,
    eSOCManager_SOCStartReason_HandshakeTimeout,
    eSOCManager_SOCStartReason_HeathTimeout,
    eSOCManager_SOCStartReason_SocReqReset,
    eSOCManager_SOCStartReason_Exit_EOL,
    eSOCManager_SOCStartReason_Other,
    eSOCManager_SOCStartReason_Num,
}tSOCManager_SOCStartReason_t;

typedef uint16 SOCManager_KEY_Mask_t;
#define SOCManager_KEY_AdjVolDwnSwtSts_Mask       ((SOCManager_KEY_Mask_t) 0x01)
#define SOCManager_KEY_AdjVolUpSwtSts_Mask        ((SOCManager_KEY_Mask_t) 0x02)
#define SOCManager_KEY_CustomSwtSts_Mask          ((SOCManager_KEY_Mask_t) 0x04)
#define SOCManager_KEY_CustomSwtSts_Mmed_Mask     ((SOCManager_KEY_Mask_t) 0x08)
#define SOCManager_KEY_EnterSwtSts_Mask           ((SOCManager_KEY_Mask_t) 0x10)
#define SOCManager_KEY_EnterSwtSts_Mmed_Mask      ((SOCManager_KEY_Mask_t) 0x20)
#define SOCManager_KEY_HomeSwtSts_Mask            ((SOCManager_KEY_Mask_t) 0x40)
#define SOCManager_KEY_MenuReturnSwtSts_Mask      ((SOCManager_KEY_Mask_t) 0x80)
#define SOCManager_KEY_MuteSwtSts_Mask            ((SOCManager_KEY_Mask_t) 0x100)
#define SOCManager_KEY_PageDwnSwtSts_Mask         ((SOCManager_KEY_Mask_t) 0x200)
#define SOCManager_KEY_PageLSwtSts_Mask           ((SOCManager_KEY_Mask_t) 0x400)
#define SOCManager_KEY_PageRSwtSts_Mask           ((SOCManager_KEY_Mask_t) 0x800)
#define SOCManager_KEY_PageUpSwtSts_Mask          ((SOCManager_KEY_Mask_t) 0x1000)
#define SOCManager_KEY_SeekDwnSwtSts_Mask         ((SOCManager_KEY_Mask_t) 0x2000)
#define SOCManager_KEY_SeekUpSwtSts_Mask          ((SOCManager_KEY_Mask_t) 0x4000)
#define SOCManager_KEY_VRSwtSts_Mask              ((SOCManager_KEY_Mask_t) 0x8000)


#define SOCManager_Upgrade_EN                   ((uint32) 1)

#define SOCManager_ReqResetReason_Other           (0x00)
#define SOCManager_ReqResetReason_Warm            (0x01)
#define SOCManager_ReqResetReason_SystemErr       (0x02)


typedef struct
{
    // input
    tSOCManager_EventDef_t      tSocReqMask;
#ifdef PLATFORM_OF_STB_IPC_USED
    tSOCManager_EventDef_t      tSocSTBReqMask;
#endif
    tSOCManager_EventDef_t      tTimeroutEvent;
    POWER_STATE_t               tPmicState;
    uint32                      u32Upgrade_flag;
    uint16                      u16keepDownloadRID;
    uint8                       u8HwVersion;
    uint8                       u8SystemState;
    boolean                     bRequset2MiniSystem;
    uint8                       u8heathResp;
    // V35-14714 Output the reason why the SoC is started
    boolean                     bReadLoggerIpcStatus;
    uint8 						u8speedvld;
    uint16                      u16Speed;
    uint8                       u8Msg_missingSts;
    SOCManager_KEY_Mask_t       tKeyMask;
    uint8                     	bHandShakeTimeoutRestFlag;
    
    // alg
    tSOCManager_EventDef_t       tResponse;
#ifdef PLATFORM_OF_STB_IPC_USED
    tSOCManager_EventDef_t       tSTBResponse;
#endif
    tSOCManager_ResetSrcDef      tResetReq;
    tSOCManager_SocStateDef_t    tSocStateTransfer;
    boolean                      bCombinationsKey;

    // output
    POWER_STATE_t               tReqPowerState;
    tSOCManager_AMPStateCtrl_t  tAMPDevCtrl;
    uint8                       u8UpdataSOCReqResetFlag;
    uint8                       u8ResetSOCMode;   /*EXT_POWER_RESET: normal reset soc; EXT_POWER_RESET2BOOT_SYS: reset soc to boot*/
    uint8                       u8SOCManagerState;
    boolean                     bCloseDevice;
    boolean                     bOpenDevice;
    boolean                     bReqResetMCU;
    boolean                     bReqResetSoc;
    boolean                     bSocFactoryResetReady;
    // V35-14714 Output the reason why the Soc is started
    boolean                     bResetLoggerIpcStatus;

    uint8                       u8ReqResetMcuReason;  // 0. SOC REQ RESET.
                                                      // 1. Warm Reset. combo key
                                                      // 2. SYSTEM ERR RESET

}sSOCManagerIO_t;


typedef uint8 tSOCManager_HandshakeState_t;
#define eSOCManager_WaitHandshake           ((tSOCManager_HandshakeState_t) 0)
#define eSOCManager_HandshakeSucces         ((tSOCManager_HandshakeState_t) 1)
#define eSOCManager_HandshakeErr            ((tSOCManager_HandshakeState_t) 2)


typedef struct 
{
    tSOCManager_SocStateDef_t    SocState;
    tSOCManager_SocStateDef_t    ReqSocStateTransfer;
    uint8                        u8TransferSequenceStep;
#ifdef PLATFORM_OF_STB_IPC_USED
    tSOCManager_HandshakeState_t STBHandshakeState;
    uint8                        u8STBHandshakeTimeoutCnt;	
#endif
    tSOCManager_HandshakeState_t HandshakeState;
    uint8                        u8HandshakeTimeoutCnt;
    uint8                        u8HeathTimeoutCnt;
    uint8                        u8SystemState;         // Use of power module
    boolean                      bSocFactoryResetReadyBack;

    // V35-14714 Output the reason why the SoC is started
    tSOCManager_SOCStartReason_t tSocStartReason;      // After uploading, clear to zero
    tSOCManager_SOCStartReason_t tSocStartReasonBack;
    boolean                      bReasonAlarm;
#ifdef PLATFORM_OF_STB_IPC_USED
    boolean                      bReasonAlarmSTB;
#endif
    boolean                      bWaitCombinationsKeyRelease;
    boolean                      bWaitSeekDwnAndPageLRelease;
    boolean                      bSOCRequsetDownload;
    uint8						 bHandShakeTimeoutRestFlag; 
}sSOCManager_Alg_Context_t;



void SOCManager_AlgInit(void);
void SOCManager_AlgCalculate(sSOCManagerIO_t *io);


#endif /* ifndef _SOCMANAGER_ALG_H_.2020-10-28 10:24:21 GW00188879 */
