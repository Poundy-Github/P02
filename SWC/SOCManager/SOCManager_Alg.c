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
 * @file:      SOCManager_Alg.c
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

#include <string.h>

#include "SOCManager_Type.h"
#include "SOCManager_RI.h"
#include "SOCManager_Alg.h"
#include "SOCManager_IPC_Service.h"
#include "Rte_SOCManager.h"



enum{
    eSOCManager_Alg_TimerHandshakeState = 0,
    eSOCManager_Alg_TimerHandlerHeath,
    eSOCManager_Alg_TimerWaitSOC_ON,
    eSOCManager_Alg_TimerWaitSOC_OFF,
    eSOCManager_Alg_TimerWaitSOC_ResetMCUDelay,
    eSOCManager_Alg_TimerCloseAMPDelay,
    eSOCManager_Alg_TimerMcuResetTimeout,
    eSOCManager_Alg_TimerSOCPowerOffReadyTimeout,
    eSOCManager_Alg_TimerSOCShutdown,
    eSOCManager_Alg_TimerLongPress,   
#ifdef PLATFORM_OF_STB_IPC_USED
    eSOCManager_Alg_STB_TimerHandshakeState,
#endif
    eSOCManager_Alg_TimerSeekDwnAndPageLPress,
    eSOCManager_Alg_DiagtominiSystem,
    eSOCManager_Alg_TimerHandlerNumber,
};



typedef struct 
{
    uint32                          u32Timer;
    const uint32                    cu32Timeout;
    const tSOCManager_EventDef_t    ctTimeroutEventMask;
}sSOCManager_Alg_TimerElement_t;






typedef boolean (*tSequenceCallout_t)(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);

typedef struct
{
    tSOCManager_SocStateDef_t   Cmd;
    uint8                       u8SequenceLen;
    const tSequenceCallout_t *  CalloutList;
}sSOCManager_StateTransferSequence;

#define SOCManager_ResetDateilsTrigger              (                                               \
                                                        eSOCManager_RESET_HandshakeMask |           \
                                                        eSOCManager_RESET_SHeathMask    |           \
                                                        eSOCManager_RESET_SOCMask       |           \
                                                        eSOCManager_RESET_OtherMask                 \
                                                    )

#define SOCManager_Reset2MiniSysDateilsTrigger      (                                               \
                                                        eSOCManager_RESET2MiniSys_HandshakeMask |   \
                                                        eSOCManager_RESET2MiniSys_SOCMask       |   \
                                                        eSOCManager_RESET2MiniSys_DiagMask      |   \
                                                        eSOCManager_RESET2MiniSys_SystemMismatchMask \
                                                    )
#define SOCManager_ResetMCUDateilsTrigger           ( eSOCManager_RESETMCU_SOCMask )                // RESTORE FACTORY SETTINGS
#define SOCManager_WarmResetDateilsTrigger          ( eSOCManager_RESET_CombinationsKeyMask )
#define SOCManager_EOLResetDateilsTrigger           ( eSOCManager_EOLKeepDownload_Mask | eSOCManager_SOCKeepDownload_Mask)



#define SOCManager_START_SEC_CODE
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static void SOCManager_Alg_SOCMonitorCheckSocResetRequset(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static void SOCManager_Alg_TimerCalculate(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static void SOCManager_Alg_TimerInit(void);
static void SOCManager_Alg_SOCMonitorArbitration(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static void SOCManager_Alg_SOCMonitor(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static boolean  SOCManager_Alg_SOCCloseDevice(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static boolean  SOCManager_Alg_SOCOpenDevice(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static boolean  SOCManager_Alg_SOCPowerDown(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static boolean  SOCManager_Alg_SOCPowerUp(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static boolean SOCManager_Alg_SOCReset(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static boolean SOCManager_Alg_SOCStarResetDelay(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static boolean SOCManager_Alg_SOCResetMCUDelay(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static boolean SOCManager_Alg_MCUReset(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static boolean SOCManager_Alg_SOCWaitPowerReady(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static boolean  SOCManager_Alg_SOCOpenAMP(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static boolean SOCManager_Alg_MCUResetWait(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static boolean SOCManager_Alg_MCUReset2MiniSys(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static boolean SOCManager_Alg_WaitSOCPowerOFFReady(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static boolean SOCManager_Alg_WaitSOCShutdown(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static boolean SOCManager_Alg_WarmReset(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);


static void SOCManager_Alg_SOCStateTransfer(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static void SOCManager_Alg_HandshakeTimeout(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static void SOCManager_Alg_HeathTimeout(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static void SOCManager_Alg_Heath(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static void SOCManager_Alg_Handshake(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static void SOCManager_Alg_SOCMonitorCheckDiagRequset(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static void SOCManager_Alg_CheckSocStartReason(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static void SOCManager_Alg_SocStartReasonAlarm(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static void SOCManager_Alg_CheckCombinationsKey(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static void SOCManager_Alg_CheckLongPressEvent(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static void SOCManager_Alg_HeathSet(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
static void SOCManager_Alg_SeekDwnAndPageLKeyPressEvent(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
extern void TM_Timer1msStartStamp(uint32 * StartStamp);
extern uint8 SOCM_SocReq_Reason;

#define SOCMANAGER_GET_OSTick(X)		TM_Timer1msStartStamp(X)


#ifdef PLATFORM_OF_STB_IPC_USED
static void SOCManager_Alg_STB_Handshake(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context);
#endif

#define SOCManager_STOP_SEC_CODE
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define SOCManager_START_SEC_CONST_UNSPECIFIED
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
static const tSequenceCallout_t  tSocPowerUpSequenceCalloutList[] = 
{
    SOCManager_Alg_SOCPowerUp,
    SOCManager_Alg_SOCWaitPowerReady,
    SOCManager_Alg_SOCOpenDevice,
};

static const tSequenceCallout_t  tSocPowerDownSequenceCalloutList[] = 
{
    SOCManager_Alg_WaitSOCPowerOFFReady,                /* V35-48517 */
    SOCManager_Alg_SOCCloseDevice,
    SOCManager_Alg_WaitSOCShutdown,
    SOCManager_Alg_SOCPowerDown,
    SOCManager_Alg_SOCWaitPowerReady,
};

static const tSequenceCallout_t  tSocResetSequenceCalloutList[] = 
{
    SOCManager_Alg_SOCCloseDevice,
    SOCManager_Alg_SOCReset,
    SOCManager_Alg_SOCWaitPowerReady,
    SOCManager_Alg_SOCOpenDevice,
    SOCManager_Alg_SOCOpenAMP,

};

static const tSequenceCallout_t  tSocDownloadModeSequenceCalloutList[] = 
{
    SOCManager_Alg_SOCCloseDevice,
    SOCManager_Alg_SOCReset,
    SOCManager_Alg_SOCWaitPowerReady,
    SOCManager_Alg_SOCOpenDevice,
//    SOCManager_Alg_SOCOpenAMP,
};
// RESTORE FACTORY SETTINGS
static const tSequenceCallout_t  tSocResetMCUSequenceCalloutList[] = 
{
    SOCManager_Alg_SOCStarResetDelay,
    SOCManager_Alg_SOCResetMCUDelay,
    SOCManager_Alg_MCUReset,
    SOCManager_Alg_MCUResetWait,
};


static const tSequenceCallout_t  tSocReset2MiniSysSequenceCalloutList[] = 
{
    SOCManager_Alg_MCUReset2MiniSys,
    SOCManager_Alg_MCUResetWait,
};

static const tSequenceCallout_t  tWarmResetSequenceCalloutList[] = 
{
    SOCManager_Alg_WarmReset,
    SOCManager_Alg_MCUResetWait,
};



#define SOCManager_StateTransferSequenceRegister(state,list)              {state,sizeof(list)/sizeof(list[0]),&list[0]}
#define SocStateTransferSequenceLsitSize                                  (sizeof(tSocStateTransferSequence)/sizeof(tSocStateTransferSequence[0]))

static const sSOCManager_StateTransferSequence tSocStateTransferSequence[] =
{   
    SOCManager_StateTransferSequenceRegister(eSOCManager_SocState_ON,tSocPowerUpSequenceCalloutList),
    SOCManager_StateTransferSequenceRegister(eSOCManager_SocState_OFF,tSocPowerDownSequenceCalloutList),
    SOCManager_StateTransferSequenceRegister(eSOCManager_SocState_Reset,tSocResetSequenceCalloutList),
    SOCManager_StateTransferSequenceRegister(eSOCManager_SocState_DownloadMode,tSocDownloadModeSequenceCalloutList),
    SOCManager_StateTransferSequenceRegister(eSOCManager_SocState_ResetMCU,tSocResetMCUSequenceCalloutList),
    SOCManager_StateTransferSequenceRegister(eSOCManager_SocState_Reset2MiniSys,tSocReset2MiniSysSequenceCalloutList),
    SOCManager_StateTransferSequenceRegister(eSOCManager_SocState_WarmReset,tWarmResetSequenceCalloutList),
};    


// V35-14714 
static const char * sSOCStartReasonStr[eSOCManager_SOCStartReason_Num]  = 
{
    "Unknown","PowerOn","HandshakeTimeout","HeathTimeout","SocReqReset","Exit Download","Other"
};



#define SOCManager_STOP_SEC_CONST_UNSPECIFIED
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SOCManager_START_SEC_VAR_INIT_UNSPECIFIED
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static sSOCManager_Alg_Context_t SOCManager_Alg_Context;
static sSOCManager_Alg_TimerElement_t sSOCManager_Alg_TimerList[eSOCManager_Alg_TimerHandlerNumber] = 
{
    {0,SOCMANAGER_HANDSHAKE_TIMEOUT,            eSOCManager_Timerout_Handshake},
    {0,SOCMANAGER_HEATH_TIMEOUT,                eSOCManager_Timerout_Heath},
    {0,SOCMANAGER_SOC_ON_TIMEOUT,               eSOCManager_Timerout_WaitSOC_ON},
    {0,SOCMANAGER_SOC_OFF_TIMEOUT,              eSOCManager_Timerout_WaitSOC_OFF},
    {0,SOCMANAGER_SOC_RESETMCUDELAY_TIMEOUT,    eSOCManager_Timerout_WaitSOC_Reset},
    {0,SOCMANAGER_CLOSE_AMP_TIMEOUT,            eSOCManager_Timerout_WaitAMPClose},
    {0,SOCMANAGER_MCURESET_TIMEOUT,             eSOCManager_Timerout_McuReset},
    {0,SOCMANAGER_SOCPOWEROFFREADY_TIMEOUT,     eSOCManager_Timerout_PowerOFFReady},
    {0,SOCMANAGER_SOCSHUTDOWN_TIMEOUT,          eSOCManager_Timerout_SOCShutdown},
    {0,SOCMANAGER_LONGPRESS_TIMEOUT,            eSOCManager_Timerout_LongPress},
#ifdef PLATFORM_OF_STB_IPC_USED
    {0,SOCMANAGER_STB_HANDSHAKE_TIMEOUT,        eSOCManager_Timerout_STB_Handshake},
#endif
    {0,SOCMANAGER_SeekDwnAndPageLPRESS_TIMEOUT, eSOCManager_Timerout_SeekDwnAndPageLLongPress},
    {0,SOCMANAGER_DiagtominiSystem_TIMEOUT, eSOCManager_Timerout_DiagtominiSystem},

};

#define SOCManager_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define SOCManager_TimerStart(Handler)                 do{sSOCManager_Alg_TimerList[Handler].u32Timer = SOC_MANAGE_TASK_PERIOD;}while(0)
#define SOCManager_TimerStop(Handler)                  do{sSOCManager_Alg_TimerList[Handler].u32Timer = 0;}while(0)
#define SOCManager_TimerForward(Handler)               do{sSOCManager_Alg_TimerList[Handler].u32Timer += SOC_MANAGE_TASK_PERIOD;}while(0)
#define SOCManager_TimerIsStarted(Handler)             (sSOCManager_Alg_TimerList[Handler].u32Timer != 0)
#define SOCManager_TimerIsElapsed(Handler)             (sSOCManager_Alg_TimerList[Handler].u32Timer >= sSOCManager_Alg_TimerList[Handler].cu32Timeout)

#define SOCManager_START_SEC_CODE
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SOCManager_AlgInit(void)
{
    memset(&SOCManager_Alg_Context,0,sizeof(SOCManager_Alg_Context));
    SOCManager_Alg_Context.bWaitCombinationsKeyRelease = TRUE;
	#if (STD_ON == DEF_SOCMANAGER_HEATH)
		SOCManager_Alg_Context.bHandShakeTimeoutRestFlag = *Rte_Pim_NvBlockNeed_HealthSwitch_MirrorBlock();
	#endif
	SOCManager_IPC_Service_Init();
    SOCManager_Alg_TimerInit();
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SOCManager_AlgCalculate(sSOCManagerIO_t *io)
{
    SOCManager_Alg_TimerCalculate(io,&SOCManager_Alg_Context);
    
    SOCManager_Alg_SOCMonitorCheckSocResetRequset(io,&SOCManager_Alg_Context);
    SOCManager_Alg_HandshakeTimeout(io,&SOCManager_Alg_Context);
    SOCManager_Alg_HeathTimeout(io,&SOCManager_Alg_Context);
    SOCManager_Alg_SOCMonitorCheckDiagRequset(io,&SOCManager_Alg_Context);
    SOCManager_Alg_CheckCombinationsKey(io,&SOCManager_Alg_Context);
    SOCManager_Alg_CheckLongPressEvent(io,&SOCManager_Alg_Context);
    SOCManager_Alg_SeekDwnAndPageLKeyPressEvent(io,&SOCManager_Alg_Context);

    SOCManager_Alg_SOCMonitorArbitration(io,&SOCManager_Alg_Context);
    SOCManager_Alg_CheckSocStartReason(io,&SOCManager_Alg_Context);
        
    // SOCManager_Alg_SOCMonitor changes the Context->SocState 
    SOCManager_Alg_SOCMonitor(io,&SOCManager_Alg_Context);
    SOCManager_Alg_Handshake(io,&SOCManager_Alg_Context);
#ifdef PLATFORM_OF_STB_IPC_USED
    SOCManager_Alg_STB_Handshake(io,&SOCManager_Alg_Context);
#endif
    SOCManager_Alg_Heath(io,&SOCManager_Alg_Context);
    SOCManager_Alg_SocStartReasonAlarm(io,&SOCManager_Alg_Context);
	SOCManager_Alg_HeathSet(io,&SOCManager_Alg_Context);
    if (io->tSocReqMask & eSOCManager_SocReqDef_QueryVerMask)
    {
        io->tResponse |= eSOCManager_Response_VersionMask;
    }

    io->u8SOCManagerState = SOCManager_Alg_Context.u8SystemState;
    io->bSocFactoryResetReady = SOCManager_Alg_Context.bSocFactoryResetReadyBack;

    
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Alg_TimerCalculate(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    uint8 i;

    for (i=0; i<eSOCManager_Alg_TimerHandlerNumber; i++)
    {

        if (SOCManager_TimerIsStarted(i) == TRUE)
        {
            if (SOCManager_TimerIsElapsed(i) == TRUE)
            {
                SOCManager_TimerStop(i);
                io->tTimeroutEvent |= sSOCManager_Alg_TimerList[i].ctTimeroutEventMask;
            }
            else
            {
                SOCManager_TimerForward(i);
            }
            
        }

    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Alg_TimerInit(void)
{
    uint8 i;
    
    for (i=0; i<eSOCManager_Alg_TimerHandlerNumber; i++)
    {
        sSOCManager_Alg_TimerList[i].u32Timer = 0u;
    }
}
static void SOCManager_Alg_SOCMonitorCheckSocResetRequset(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    if (io->tSocReqMask & eSOCManager_SocReqDef_ResetSocMask)
    {
        io->tResetReq |= eSOCManager_RESET_SOCMask;
    }
    else if (io->tSocReqMask & (eSOCManager_SocReqDef_ResetSoc2MiniSysMask | eSOCManager_SocReqDef_ResetCheckSocMiniOSMask))
    {
        io->tResetReq |= eSOCManager_RESET2MiniSys_SOCMask;
    }
    else if (io->tSocReqMask & eSOCManager_SocReqDef_ResetMCUMask)
    {
        io->tResetReq |= eSOCManager_RESETMCU_SOCMask;
    }
    else if (io->tSocReqMask & eSOCManager_SocReqDef_SystemErrorMask)
    {
        io->tResetReq |= eSOCManager_RESET2MiniSys_SystemMismatchMask;
    }
    else if (io->tSocReqMask & eSOCManager_SocReqDef_DownloadMask)
    {
        io->tResetReq |= eSOCManager_SOCKeepDownload_Mask;
        Context->bSOCRequsetDownload = TRUE;
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Alg_SOCMonitorCheckDiagRequset(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    
	uint8 SOCM_APP_SendData[2] = {APP_INFOSM_DIAG2MINI,0};
	int32_t Socm_sendsts = -1;
	static uint8 SOCM_IpcSendFlag = SOCM_NOSEND;
    static uint8 SOCM_minisendFlag = SOCM_NOSEND;
    if ((io->u16keepDownloadRID == 1u)&&(eSOCManager_SocState_ON == Context->SocState))
    {
        io->tResetReq |= eSOCManager_EOLKeepDownload_Mask;
    }
    else if ((io->u16keepDownloadRID == 2u)&&(eSOCManager_SocState_DownloadMode == Context->SocState))
    {
        io->tResetReq |= eSOCManager_EOLKeepNormal_Mask;
    }

    if((io->bRequset2MiniSystem == TRUE)&&(SOCM_NOSEND == SOCM_minisendFlag))
    {
        SOCManager_TimerStart(eSOCManager_Alg_DiagtominiSystem);
        SOCM_IpcSendFlag = SOCM_SEND;
    }
    
    if(SOCM_SEND == SOCM_IpcSendFlag)
    {		
		Socm_sendsts = IPC_M2S_POWERPowerInfoAPP_INFOMS_Transmit((IPC_M2S_POWERPowerInfoAPP_INFOMS_t*)&SOCM_APP_SendData);
		(void)socmanager_warn("send sig diag to mini");
		SOCM_minisendFlag = SOCM_SEND;
		if(0u == Socm_sendsts)
		{
			SOCM_IpcSendFlag  = SOCM_NOSEND;
		}
    }
	if (io->tTimeroutEvent & eSOCManager_Timerout_DiagtominiSystem)
	{
		io->tResetReq |= eSOCManager_RESET2MiniSys_DiagMask;
	}
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Alg_SOCMonitorArbitration(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    if (eSOCManager_SocState_None == Context->SocState)
    {
        Context->SocState = eSOCManager_SocState_OFF;
        Context->u8SystemState = eSOC_MANAGER_STATE_CLOSE;
    }
    
    if (eSOCManager_SocState_ON == Context->SocState)
    {
        if ((io->u8SystemState == SYSTEMSTATE_SP_SOCOFF)||(io->u8SystemState == SYSTEMSTATE_SP_OFF))
        {
            (void)socmanager_warn("requset soc off , because u8SystemState is %d .",io->u8SystemState);
            io->tSocStateTransfer = eSOCManager_SocState_OFF;
        }
        else if (io->tResetReq != 0u)
        {
            if (io->tResetReq & SOCManager_EOLResetDateilsTrigger)
            {
                (void)socmanager_warn("requset reset soc, because EOL.");
                io->tSocStateTransfer = eSOCManager_SocState_DownloadMode;
            }
            else if (io->tResetReq & SOCManager_ResetMCUDateilsTrigger)
            {
                (void)socmanager_warn("requset reset MCU, because tResetReq is 0x%x",io->tResetReq );
                io->tSocStateTransfer = eSOCManager_SocState_ResetMCU;
            }
            else if (io->tResetReq & SOCManager_Reset2MiniSysDateilsTrigger)
            {
                (void)socmanager_warn("requset reset MCU to Minisystem, because tResetReq is 0x%x",io->tResetReq);
                io->tSocStateTransfer = eSOCManager_SocState_Reset2MiniSys;
            }
            else if (io->tResetReq & SOCManager_ResetDateilsTrigger)
            {
                (void)socmanager_warn("requset reset soc, because tResetReq is 0x%x",io->tResetReq);
                io->tSocStateTransfer = eSOCManager_SocState_Reset;
            }
            else if (io->tResetReq & SOCManager_WarmResetDateilsTrigger)
            {
                (void)socmanager_warn("requset reset mcu, because tResetReq is 0x%x",io->tResetReq);
                io->tSocStateTransfer = eSOCManager_SocState_WarmReset;
            }
        }
    }
    else if (eSOCManager_SocState_OFF == Context->SocState)
    {
        if (io->u8SystemState == SYSTEMSTATE_SP_STANDBY)
        {
            (void)socmanager_warn("requset soc ON , because u8SystemState is 0x%x",io->u8SystemState);
            io->tSocStateTransfer = eSOCManager_SocState_ON;
        }
        else if (io->tResetReq & SOCManager_EOLResetDateilsTrigger)
        {
            (void)socmanager_warn("requset reset soc, because EOL.");
            io->tSocStateTransfer = eSOCManager_SocState_DownloadMode;
        }
        else if (io->tResetReq & eSOCManager_RESET2MiniSys_DiagMask)
        {
            (void)socmanager_warn("requset reset MCU, because tResetReq is 0x%x",io->tResetReq);
            io->tSocStateTransfer = eSOCManager_SocState_Reset2MiniSys;
        }
    }
    else if (eSOCManager_SocState_DownloadMode == Context->SocState)
    {
        if ((boolean)(io->tResetReq & eSOCManager_EOLKeepNormal_Mask)&&(FALSE == Context->bSOCRequsetDownload))
        {
            (void)socmanager_warn("requset soc reset , because tResetReq is 0x%x",io->tResetReq);
            io->tSocStateTransfer = eSOCManager_SocState_Reset;
        }
    }
    else if (eSOCManager_SocState_Transition == Context->SocState)
    {
        if (io->tResetReq != 0)
        {
            (void)socmanager_warn("The reset request(&%d) is invalid because a request is in progress.",io->tResetReq);
        }
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Alg_SOCMonitor(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    if (io->tSocStateTransfer != eSOCManager_SocState_None)
    {
        if (Context->ReqSocStateTransfer != eSOCManager_SocState_None)
        {
            (void)socmanager_err("The state transition is not complete !!!");
        }
        else
        {
            if (io->tSocStateTransfer == Context->SocState)
            {
                (void)socmanager_warn("The request failed because the request state is the same as the current state(%d).",Context->SocState);
            }
            else
            {
                (void)socmanager_info("SOC %d -> Transition",Context->SocState);
                Context->ReqSocStateTransfer = io->tSocStateTransfer;
                Context->u8TransferSequenceStep = 0;
                Context->SocState = eSOCManager_SocState_Transition;
            }
            
        }
    }
    
    if (Context->ReqSocStateTransfer != eSOCManager_SocState_None)
    {
        uint8 i;
        boolean ret = FALSE;
        const sSOCManager_StateTransferSequence * ptr = NULL_PTR;
        
        
        for (i=0;i<SocStateTransferSequenceLsitSize;i++)
        {
            if (tSocStateTransferSequence[i].Cmd == Context->ReqSocStateTransfer)
            {
                ptr = &tSocStateTransferSequence[i];
                break;
            }
        }

        if (i >= SocStateTransferSequenceLsitSize)
        {
            Context->ReqSocStateTransfer = eSOCManager_SocState_None;
            (void)socmanager_err("Requset (%d) unknown !!!",tSocStateTransferSequence[i].Cmd);
        }
        else
        {
            if (ptr->u8SequenceLen < Context->u8TransferSequenceStep)
            {
                (void)socmanager_err("cmd [%d] list(%d) < step(%d) !!!",ptr->Cmd,ptr->u8SequenceLen,Context->u8TransferSequenceStep);
                SOCManager_Alg_SOCStateTransfer(io,Context);
            }
            else if (ptr->CalloutList[Context->u8TransferSequenceStep] == NULL_PTR)
            {
                (void)socmanager_err("callout ptr is null. !!!",tSocStateTransferSequence[i].Cmd);
            }
            else
            {
                ret = ptr->CalloutList[Context->u8TransferSequenceStep](io,Context);
                if (ret == TRUE)
                {
                    Context->u8TransferSequenceStep++;
                    
                    if (ptr->u8SequenceLen <= Context->u8TransferSequenceStep)
                    {
                        
                        SOCManager_Alg_SOCStateTransfer(io,Context);
                    }
                }
            }
        }
    }

}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean  SOCManager_Alg_SOCCloseDevice(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    if (Context->ReqSocStateTransfer != eSOCManager_SocState_OFF)
    {
        io->tAMPDevCtrl = eSOCManager_AMPStateCtrl_Close;
        SOCManager_TimerStart(eSOCManager_Alg_TimerCloseAMPDelay);
        (void)socmanager_warn("[step %d] SOC Close AMP",Context->u8TransferSequenceStep);
    }
    io->bCloseDevice = TRUE;
    io->bResetLoggerIpcStatus = TRUE;
    (void)socmanager_warn("[step %d] SOC Close Device",Context->u8TransferSequenceStep);
    return TRUE;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean  SOCManager_Alg_SOCOpenAMP(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    boolean ret = TRUE;
    if (SOCManager_TimerIsStarted(eSOCManager_Alg_TimerCloseAMPDelay) == FALSE)
    {
        io->tAMPDevCtrl = eSOCManager_AMPStateCtrl_Open;
        (void)socmanager_warn("[step %d] soc Open AMP",Context->u8TransferSequenceStep);
        ret = TRUE;
    }
    else
    {
        (void)socmanager_Verbose("[step %d] Wait AMP Close",Context->u8TransferSequenceStep);
        ret = FALSE;
    }
    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean  SOCManager_Alg_SOCOpenDevice(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    io->bOpenDevice = TRUE;
    socmanager_warn("[step %d] SOC Open Device.",Context->u8TransferSequenceStep);
    return TRUE;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean  SOCManager_Alg_SOCPowerDown(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
 {
    io->tReqPowerState = ePOWER_STATE_POWER_DOWN;
    (void)socmanager_warn("[step %d] SOC Power Down.",Context->u8TransferSequenceStep);
    return TRUE;
 }
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean  SOCManager_Alg_SOCPowerUp(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
 {
    io->tReqPowerState = ePOWER_STATE_POWER_UP;
    (void)socmanager_warn("[step %d] SOC Power Up",Context->u8TransferSequenceStep);
    return TRUE;
 }
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean SOCManager_Alg_SOCReset(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    if (Context->ReqSocStateTransfer == eSOCManager_SocState_Reset)
    {
        io->u8ResetSOCMode = EXT_POWER_RESET;
        (void)socmanager_warn("[step %d] Reset Soc",Context->u8TransferSequenceStep);
    }
    else if (Context->ReqSocStateTransfer == eSOCManager_SocState_DownloadMode)
    {
        io->u8ResetSOCMode = EXT_POWER_RESET2BOOT_SYS;
        (void)socmanager_warn("[step %d] EOL Download MOde.",Context->u8TransferSequenceStep);
    }
    io->bReqResetSoc = TRUE;
    return TRUE;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean SOCManager_Alg_SOCStarResetDelay(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    SOCManager_TimerStart(eSOCManager_Alg_TimerWaitSOC_ResetMCUDelay);
    Context->bSocFactoryResetReadyBack = TRUE;
    (void)socmanager_warn("[step %d] Star Reset Delay.",Context->u8TransferSequenceStep);
    return TRUE;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean SOCManager_Alg_SOCResetMCUDelay(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    boolean ret = FALSE;
    if (io->tTimeroutEvent & eSOCManager_Timerout_WaitSOC_Reset)
    {
        ret = TRUE;
        (void)socmanager_warn("[step %d] eSOCManager_Timerout_WaitSOC_Reset Timeout ",Context->u8TransferSequenceStep);
    }
    else
    {
        if (SOCManager_TimerIsStarted(eSOCManager_Alg_TimerWaitSOC_ResetMCUDelay) == FALSE)
        {
            SOCManager_TimerStart(eSOCManager_Alg_TimerWaitSOC_ResetMCUDelay);
            (void)socmanager_err("eSOCManager_Timerout_WaitSOC_Reset stop!!!");
        }
        else
        {
            (void)socmanager_Verbose("[step %d] Wait Reset MCU",Context->u8TransferSequenceStep);
        }
    }

    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean SOCManager_Alg_MCUReset(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{

    io->bReqResetMCU = TRUE;
	Dio_WriteChannel(DioConf_DioChannel_VIP_ID_EN_ODH, STD_LOW);
	Dio_WriteChannel(DioConf_DioChannel_VIP_CD_EN_ODH, STD_LOW);
	Dio_WriteChannel(DioConf_DioChannel_VIP_PD_EN_ODH, STD_LOW);
	Dio_WriteChannel(DioConf_DioChannel_VIP_HD_EN_ODH, STD_LOW);
    io->tAMPDevCtrl = eSOCManager_AMPStateCtrl_Close;
    if (Context->ReqSocStateTransfer == eSOCManager_SocState_Reset2MiniSys)
    {
        SOCManager_TimerStart(eSOCManager_Alg_TimerMcuResetTimeout);
        (void)socmanager_warn("[step %d] Reset MCU.",Context->u8TransferSequenceStep);
    }
    
    return TRUE;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean SOCManager_Alg_MCUReset2MiniSys(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{

    if(io->tResetReq & eSOCManager_RESET2MiniSys_HandshakeMask)
    {
        io->u8UpdataSOCReqResetFlag = 0xBB;
    }
    else if ((io->tResetReq & eSOCManager_RESET2MiniSys_SOCMask) && (io->tSocReqMask & eSOCManager_SocReqDef_ResetCheckSocMiniOSMask))
    {
        io->u8UpdataSOCReqResetFlag = 0x55;
    }
    else 
    {
        io->u8UpdataSOCReqResetFlag = 0xAA;
    }
    (void)socmanager_warn("[step %d] u8UpdataSOCReqResetFlag is %X.",Context->u8TransferSequenceStep,io->u8UpdataSOCReqResetFlag);
    return SOCManager_Alg_MCUReset( io, Context);

}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean SOCManager_Alg_MCUResetWait(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    boolean ret = FALSE;
    if (SOCManager_TimerIsStarted(eSOCManager_Alg_TimerMcuResetTimeout) == FALSE)
    {
        (void)socmanager_warn("[step %d] Reset Timeout.",Context->u8TransferSequenceStep);
        ret = TRUE;
    }

    return ret;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean SOCManager_Alg_SOCWaitPowerReady(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
 {
    boolean ret = FALSE;
    
    if (io->tPmicState == ePOWER_STATE_IDLE)
    {
        (void)socmanager_warn("[step %d] SOC Power On PMIC Ready.",Context->u8TransferSequenceStep);
        ret = TRUE;
    }
    else
    {
        (void)socmanager_Verbose("[step %d] Wait PMIC Ready.",Context->u8TransferSequenceStep);
    }
    return ret;
 }

 /***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Alg_SOCStateTransfer(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
 {
    

    switch(Context->ReqSocStateTransfer)
    {
        case eSOCManager_SocState_ON:
            Context->u8SystemState = eSOC_MANAGER_STATE_OPNE;
            Context->SocState = Context->ReqSocStateTransfer;
            (void)socmanager_warn("SOC Transition-> %d",Context->ReqSocStateTransfer);
            break;
        case eSOCManager_SocState_OFF:
            Context->u8SystemState = eSOC_MANAGER_STATE_CLOSE;
            Context->SocState = Context->ReqSocStateTransfer;
            (void)socmanager_warn("SOC Transition-> %d",Context->ReqSocStateTransfer);
            break;
        case eSOCManager_SocState_DownloadMode:
            Context->SocState = Context->ReqSocStateTransfer;
            (void)socmanager_warn("SOC Transition-> %d",Context->ReqSocStateTransfer);
            break;
        case eSOCManager_SocState_Reset:
            Context->SocState = eSOCManager_SocState_ON;
            (void)socmanager_warn("SOC Transition-> %d",Context->ReqSocStateTransfer);
            break;
        case eSOCManager_SocState_ResetMCU:
        case eSOCManager_SocState_Reset2MiniSys:
        case eSOCManager_SocState_WarmReset:
            Context->SocState = eSOCManager_SocState_ON;
            (void)socmanager_warn("SOC Transition-> %d",Context->ReqSocStateTransfer);
            break;
        default:
            (void)socmanager_err("Unknown Transfer state :%d!",Context->ReqSocStateTransfer);
            Context->SocState = Context->ReqSocStateTransfer;
            break;
    }
    Context->ReqSocStateTransfer = eSOCManager_SocState_None;
    Context->u8TransferSequenceStep = 0u;
    // V35-14714
    Context->tSocStartReason = Context->tSocStartReasonBack;
 }

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Alg_HandshakeTimeout(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    if (io->tTimeroutEvent & eSOCManager_Timerout_Handshake)
    {
         (void)socmanager_err("Handshake timeout!");
#if (DEF_SOCMANAGER_HEATH == STD_ON)
		if(SOC_INFO_HANDSHAKE_TIMEOUT_RESET_ON == Context->bHandShakeTimeoutRestFlag)
		{
			Context->u8HandshakeTimeoutCnt++;
			if(Context->u8HandshakeTimeoutCnt >= SOCMANAGER_APPHANDSHAKE_CNT_MAX)
			{
				io->bReqResetMCU = TRUE;
				io->u8ReqResetMcuReason = SOCManager_ReqResetReason_SystemErr;
				(void)socmanager_err("Reset MCU, because Handshake timeout (# %d).",Context->u8HandshakeTimeoutCnt);
			}
			else if ((Context->u8HandshakeTimeoutCnt >= SOCMANAGER_HANDSHAKE_CNT_MAX)&&(boolean)(io->u32Upgrade_flag))
			{
				(void)socmanager_err("Reset to MiniSystem, because Handshake timeout (# %d).",Context->u8HandshakeTimeoutCnt);
				io->tResetReq |= eSOCManager_RESET2MiniSys_HandshakeMask;
			}
			else
			{
				(void)socmanager_err("Reset SOC, because Handshake timeout (# %d).",Context->u8HandshakeTimeoutCnt);
				io->tResetReq |= eSOCManager_RESET_HandshakeMask;
			}
    	}
#endif
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Alg_HeathTimeout(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    if (io->tTimeroutEvent & eSOCManager_Timerout_Heath)
    {
        (void)socmanager_err("Heath timeout!");
#if (DEF_SOCMANAGER_HEATH == STD_ON)
    if(SOC_INFO_HANDSHAKE_TIMEOUT_RESET_ON == Context->bHandShakeTimeoutRestFlag)
    {
    	Context->u8HeathTimeoutCnt++;
		if(Context->u8HeathTimeoutCnt >= SOCMANAGER_HEALTH_CNT_MAX)
		{
			io->bReqResetMCU = TRUE;
			io->u8ReqResetMcuReason = SOCManager_ReqResetReason_SystemErr;
			(void)socmanager_err("Reset MCU, because Heath timeout (# %d).",Context->u8HeathTimeoutCnt);
		}
		else
		{
			(void)socmanager_err("Reset to SOC, because Heath timeout.");
			io->tResetReq |= eSOCManager_RESET_SHeathMask;
		}
    }
#endif
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Alg_Heath(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    boolean bTimerActiv;

    bTimerActiv = SOCManager_TimerIsStarted(eSOCManager_Alg_TimerHandlerHeath);

    if (Context->HandshakeState == eSOCManager_HandshakeSucces)
    {
        if ((boolean)(io->tSocReqMask & eSOCManager_SocReqDef_HeathMask)||(bTimerActiv == FALSE))
        {
            SOCManager_TimerStart(eSOCManager_Alg_TimerHandlerHeath);
            
            io->tResponse |= eSOCManager_Response_HeathMask;
        }
    }
    else
    {
        SOCManager_TimerStop(eSOCManager_Alg_TimerHandlerHeath);
    }
}

static void SOCManager_Alg_HeathSet(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    Std_ReturnType returnValue = E_NOT_OK;
	if(io->tSocReqMask & eSOCManager_SocReqDef_HealthSetMask)
	{
		Context->bHandShakeTimeoutRestFlag = io->bHandShakeTimeoutRestFlag;
		//write NVM
		#if (STD_ON == DEF_SOCMANAGER_HEATH)
			 *Rte_Pim_NvBlockNeed_HealthSwitch_MirrorBlock() = Context->bHandShakeTimeoutRestFlag;
			returnValue = Rte_Call_NvMService_AC3_Defs_NvBlockNeed_HealthSwitch_WriteBlock(Rte_Pim_NvBlockNeed_HealthSwitch_MirrorBlock());
			(void)socmanager_warn("Write The Param of HealthSet = %d to NVM , ret = %d",Context->bHandShakeTimeoutRestFlag,returnValue);
		#endif
	}
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Alg_Handshake(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    boolean bTimerActiv;
	uint32 curOsTimer=0;
	uint8 SOCM_IOSts = 0xff;
	static uint8 SOCM_Startcheck = FALSE;

    bTimerActiv = SOCManager_TimerIsStarted(eSOCManager_Alg_TimerHandshakeState);

    if (Context->SocState == eSOCManager_SocState_ON)
    {
		if(io->tTimeroutEvent & eSOCManager_Timerout_WaitSOC_ON)
		{
			SOCM_Startcheck = TRUE;
			//socmanager_warn("waitsocon 500ms");
		}
		if( TRUE == SOCM_Startcheck)
		{
			SOCM_IOSts = Dio_ReadChannel(DioConf_DioChannel_SOC_VIP_FAST_BOOT);
			if((STD_HIGH == SOCM_IOSts)&&(TRUE == bTimerActiv))
			{
				sSOCManager_Alg_TimerList[eSOCManager_Alg_TimerHandshakeState].u32Timer = 45000u;
				socmanager_warn("handshake time -> 15s");
				SOCM_Startcheck = FALSE;
			}
		}
        if (io->tTimeroutEvent & eSOCManager_Timerout_Handshake)
        {
            Context->HandshakeState = eSOCManager_HandshakeErr;
        }
        else if (io->tSocReqMask & eSOCManager_SocReqDef_HandshakeMask)
        {
        	SOCMANAGER_GET_OSTick(&curOsTimer);
			(void)socmanager_warn("[IPC-I]:at %d ms , 1st IPC , Handshake Success\r\n",curOsTimer);
            Context->HandshakeState = eSOCManager_HandshakeSucces;
            Context->u8HandshakeTimeoutCnt = 0;
            io->tResponse |= eSOCManager_Response_HandshakeMask;
            // V35-14714
            Context->bReasonAlarm = TRUE;
        }
        
    }
    else
    {
        Context->HandshakeState = eSOCManager_WaitHandshake;
    }
    
    
    if ((Context->HandshakeState == eSOCManager_WaitHandshake)&&(Context->SocState == eSOCManager_SocState_ON))
    {
        if (bTimerActiv == FALSE)
        {
            SOCManager_TimerStart(eSOCManager_Alg_TimerHandshakeState);
			SOCManager_TimerStart(eSOCManager_Alg_TimerWaitSOC_ON);
			SOCM_Startcheck = FALSE;
        }
    }
    else
    {
        SOCManager_TimerStop(eSOCManager_Alg_TimerHandshakeState);
        SOCManager_TimerStop(eSOCManager_Alg_TimerWaitSOC_ON);
        SOCM_Startcheck = FALSE;
    }
    
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
#ifdef PLATFORM_OF_STB_IPC_USED
static void SOCManager_Alg_STB_Handshake(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    boolean bTimerActiv;
	uint32 curOsTimer=0;

    bTimerActiv = SOCManager_TimerIsStarted(eSOCManager_Alg_STB_TimerHandshakeState);

    if (Context->SocState == eSOCManager_SocState_ON)
    {
        if (io->tTimeroutEvent & eSOCManager_Timerout_STB_Handshake)
        {
            Context->STBHandshakeState = eSOCManager_HandshakeErr;
        }
        else if (io->tSocSTBReqMask & eSOCManager_SocReqDef_STB_HandshakeMask)
        {
        	SOCMANAGER_GET_OSTick(&curOsTimer);
			(void)socmanager_warn("[IPC-STB-I]:at %d ms , 2nd IPC , Handshake Success\r\n",curOsTimer);
            Context->STBHandshakeState = eSOCManager_HandshakeSucces;
            Context->u8STBHandshakeTimeoutCnt = 0;
            io->tSTBResponse |= eSOCManager_Response_STB_HandshakeMask;
            // V35-14714
            Context->bReasonAlarmSTB = TRUE;
        }
        
    }
    else
    {
        Context->STBHandshakeState = eSOCManager_WaitHandshake;
    }
    
    
    if ((Context->STBHandshakeState == eSOCManager_WaitHandshake)&&(Context->SocState == eSOCManager_SocState_ON))
    {
        if (bTimerActiv == FALSE)
        {
            SOCManager_TimerStart(eSOCManager_Alg_STB_TimerHandshakeState);
        }
    }
    else
    {
        SOCManager_TimerStop(eSOCManager_Alg_STB_TimerHandshakeState);
    }
    
}
#endif

/***********************************************************************
 * @brief       : V35-14714
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Alg_CheckSocStartReason(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    if ((eSOCManager_SocState_Reset == io->tSocStateTransfer)&&(eSOCManager_SocState_Transition != Context->SocState))
    {
        if (eSOCManager_SocState_DownloadMode == Context->SocState)
        {
            Context->tSocStartReasonBack = eSOCManager_SOCStartReason_Exit_EOL;
        }
        else if (io->tResetReq & eSOCManager_RESET_HandshakeMask)
        {
            Context->tSocStartReasonBack = eSOCManager_SOCStartReason_HandshakeTimeout;
        }
        else if (io->tResetReq & eSOCManager_RESET_SHeathMask)
        {
            Context->tSocStartReasonBack = eSOCManager_SOCStartReason_HeathTimeout;
        }
        else if (io->tResetReq & eSOCManager_RESET_SOCMask)
        {
            Context->tSocStartReasonBack = eSOCManager_SOCStartReason_SocReqReset;
        }
        else
        {
            Context->tSocStartReasonBack = eSOCManager_SOCStartReason_Other;
        }
    }
    else if ((eSOCManager_SocState_OFF == Context->SocState) && (eSOCManager_SocState_ON == io->tSocStateTransfer))
    {
        Context->tSocStartReasonBack = eSOCManager_SOCStartReason_PowerOn;
    }

}

/***********************************************************************
 * @brief       : V35-14714
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Alg_SocStartReasonAlarm(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    if ((TRUE == Context->bReasonAlarm) && (TRUE == io->bReadLoggerIpcStatus))
    {
        
        if (Context->tSocStartReason < eSOCManager_SOCStartReason_Num)
        {
            (void)socmanager_warn("Soc Start Reason:%s",sSOCStartReasonStr[Context->tSocStartReason]);
            socmanager_warn("Soc Req Reason:%d",SOCM_SocReq_Reason);//http://10.52.245.125:8090/pages/viewpage.action?pageId=53317537
            SOCM_SocReq_Reason = 0;  
        }
        else
        {
            (void)socmanager_warn("Soc Start Reason:%d",Context->tSocStartReason);
        }
        Context->bReasonAlarm = FALSE;
        Context->tSocStartReason = eSOCManager_SOCStartReason_Unknown;
    }
}


/***********************************************************************
 * @brief       : V35-48517
 * @param       : 
 * @retval      : 
 ***********************************************************************/

static boolean SOCManager_Alg_WaitSOCPowerOFFReady(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    boolean ret = FALSE;
    
    if (io->tSocReqMask & eSOCManager_SocReqDef_PowerOFFReadyMask)
    {
        ret = TRUE;
	    socmanager_warn("[step %d] Wait SOC Power Off Ready\r\n",Context->u8TransferSequenceStep);
    }
    else if (io->tTimeroutEvent & eSOCManager_Timerout_PowerOFFReady)
    {
        ret = TRUE;
        (void)socmanager_err("SOC POWER OFF READY TIMEOUT!");
    }
    else if (SOCManager_TimerIsStarted(eSOCManager_Alg_TimerSOCPowerOffReadyTimeout) == FALSE)
    {
        SOCManager_TimerStart(eSOCManager_Alg_TimerSOCPowerOffReadyTimeout);
    }

    return ret;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean SOCManager_Alg_WaitSOCShutdown(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    boolean ret = FALSE;
    
    if (io->tTimeroutEvent & eSOCManager_Timerout_SOCShutdown)
    {
        ret = TRUE;
	(void)socmanager_warn("[step %d] Wait SOC Shutdown",Context->u8TransferSequenceStep);
    }
    else if (SOCManager_TimerIsStarted(eSOCManager_Alg_TimerSOCShutdown) == FALSE)
    {
        SOCManager_TimerStart(eSOCManager_Alg_TimerSOCShutdown);
    }

    return ret;
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean SOCManager_Alg_WarmReset(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    io->bReqResetMCU = TRUE;
	Dio_WriteChannel(DioConf_DioChannel_VIP_ID_EN_ODH, STD_LOW);
	Dio_WriteChannel(DioConf_DioChannel_VIP_CD_EN_ODH, STD_LOW);
	Dio_WriteChannel(DioConf_DioChannel_VIP_PD_EN_ODH, STD_LOW);
	Dio_WriteChannel(DioConf_DioChannel_VIP_HD_EN_ODH, STD_LOW);
    io->tAMPDevCtrl = eSOCManager_AMPStateCtrl_Close;
    io->u8ReqResetMcuReason = SOCManager_ReqResetReason_Warm;
    (void)socmanager_warn("[step %d] Warm(combine key) Reset.",Context->u8TransferSequenceStep);
    
    return TRUE;
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Alg_CheckCombinationsKey(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
	SOCManager_KEY_Mask_t EV_OR_Oil = 0u;

#ifdef SOCM_POWER_IS_EV
    EV_OR_Oil = (SOCManager_KEY_Mask_t)(SOCManager_KEY_AdjVolUpSwtSts_Mask | SOCManager_KEY_PageUpSwtSts_Mask);
#else 
    EV_OR_Oil = (SOCManager_KEY_Mask_t)(SOCManager_KEY_EnterSwtSts_Mmed_Mask | SOCManager_KEY_EnterSwtSts_Mask);
#endif

    if ((0u == io->u16Speed)&&(0u == io->u8Msg_missingSts)&&(1u == io->u8speedvld)&&(eSOCManager_SocState_ON == Context->SocState))
    {
        if (io->tKeyMask == EV_OR_Oil)
        {
            io->bCombinationsKey = TRUE;
        }
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Alg_CheckLongPressEvent(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    boolean btimeStar = FALSE;
	SystemState_RecordType Socm_Sys_Sts;
    btimeStar = SOCManager_TimerIsStarted(eSOCManager_Alg_TimerLongPress);
	Rte_Read_rpSR_Power_Out_SystemStateOut(&Socm_Sys_Sts);

    if (io->bCombinationsKey == FALSE)
    {
        if (btimeStar == TRUE)
        {
            (void)socmanager_info("mcureset Key Release.");
        }
        Context->bWaitCombinationsKeyRelease = FALSE;
        SOCManager_TimerStop(eSOCManager_Alg_TimerLongPress);
    }
    else if (Context->bWaitCombinationsKeyRelease == TRUE)
    {
        SOCManager_TimerStop(eSOCManager_Alg_TimerLongPress);
    }
    else if (io->tTimeroutEvent & eSOCManager_Timerout_LongPress)
    {
        (void)socmanager_warn("mcureset Key Activate.");
        if ((SYSTEMSTATE_IVI_ON_NORMAL == Socm_Sys_Sts.IVIState)||\
        	(SYSTEMSTATE_IVI_ON_LOCAL == Socm_Sys_Sts.IVIState)||\
        	(SYSTEMSTATE_IVI_ON_POWER_ERROR == Socm_Sys_Sts.IVIState)||\
        	(SYSTEMSTATE_IVI_ON_POWER_SAVE_1 == Socm_Sys_Sts.IVIState)||\
			(SYSTEMSTATE_IVI_DEMO == Socm_Sys_Sts.IVIState))
        {
			Context->bWaitCombinationsKeyRelease = TRUE;
        	io->tResetReq |= eSOCManager_RESET_CombinationsKeyMask;
        }
    }
    else if (btimeStar == FALSE)
    {
        (void)socmanager_warn("mcureset Key Pressed.");
        SOCManager_TimerStart(eSOCManager_Alg_TimerLongPress);
    }
    else
    {
        // do nothing;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SOCManager_Alg_SeekDwnAndPageLKeyPressEvent(sSOCManagerIO_t * io,sSOCManager_Alg_Context_t * Context)
{
    boolean EntertimeStar = FALSE;
    boolean SeekDwnAndPageLPress = FALSE;

    if (io->tKeyMask == (SOCManager_KEY_Mask_t)(SOCManager_KEY_SeekDwnSwtSts_Mask | SOCManager_KEY_PageLSwtSts_Mask))
    {
        SeekDwnAndPageLPress = TRUE;
    }

    EntertimeStar = SOCManager_TimerIsStarted(eSOCManager_Alg_TimerSeekDwnAndPageLPress);

    if (SeekDwnAndPageLPress == FALSE)
    {
        if ((EntertimeStar == TRUE) || (Context->bWaitSeekDwnAndPageLRelease == TRUE))
        {
            (void)socmanager_info("SeekDwnAndPageL Key Release.");
        }
        Context->bWaitSeekDwnAndPageLRelease = FALSE;
        SOCManager_TimerStop(eSOCManager_Alg_TimerSeekDwnAndPageLPress);
    }
    else if (Context->bWaitSeekDwnAndPageLRelease == TRUE)
    {
        SOCManager_TimerStop(eSOCManager_Alg_TimerSeekDwnAndPageLPress);
    }
    else if (io->tTimeroutEvent & eSOCManager_Timerout_SeekDwnAndPageLLongPress)
    {
        (void)socmanager_warn("SeekDwnAndPageL Key Activate.");
        Context->bWaitSeekDwnAndPageLRelease = TRUE;
    }
    else if (EntertimeStar == FALSE)
    {
        (void)socmanager_warn("SeekDwnAndPageL Key Pressed.");
        SOCManager_TimerStart(eSOCManager_Alg_TimerSeekDwnAndPageLPress);
    }
    else
    {
        // do nothing;
    }

    if (Context->bWaitSeekDwnAndPageLRelease == TRUE)
    {
        Rte_Write_SeekDwnAndPageLPress_Timeout_Element(TRUE);
    }
    else
    {
        Rte_Write_SeekDwnAndPageLPress_Timeout_Element(FALSE);
    }
	
}


sSOCManager_Alg_Context_t * SOCManager_Alg_Get_Context(void)
{
    return &SOCManager_Alg_Context;
}


#define SOCManager_STOP_SEC_CODE
#include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

