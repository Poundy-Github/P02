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
 * @file:      Power_OutMgr.c
 * @author:    Nobo
 * @date:      2020-8-6
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-8-6
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "string.h"
#include "Power_OutMgr.h"
#include "Logger_Cfg.h"
#include "logger.h"
#include "Power_Volt_Monitor.h"
#include "Power_Temp_Monitor.h"
#include "SystemState_Conditon_Element.h"
#include "SystemState_HUD_Condition.h"
#include "SystemState_Console_Condition.h"
#include "SystemState_IVI_Condition.h"
#include "SystemState_Cluster_Condition.h"
#include "SystemState_SP_Condition.h"
#include "IPC_POWER.h"
#include "CanNm.h"                                                     


#define POWER_IPCSENDSUCCESS                                    (0)
#define POWER_IPCSENDRETRY                                      (1u)

#define POWER_TemperatureOverflow                               (254)
#define SMGETMCU                                                (0u)
#define SMGETIVI                                                (1u)
#define SMGETCLUSTER                                            (2u)
#define SMGETHUD                                                (3u)
#define SMGETCONSOLE                                            (4u)
#define SMGETKL15                                               (5u)
#define SMGETNM                                                 (6u)
#define SMGETTEMP                                               (7u)
#define SMGETNUM                                                (8u)



#define POWER_START_SEC_CODE
#include "Power_MemMap.h"

static void POWER_VirtualEventFunc(void);
static void Power_NMOutMgr(void);
static void Power_HUDOutMgr(void);
static void Power_ConsoleOutMgr(void);
static void Power_KL15OutMgr(void);
static void SystemState_VoltageSend(void);
static void Power_IVIOutMgr(void);
static void Power_ClusterOutMgr(void);
static uint8 Power_IPCSts(int32_t IPCResult);
static void SystemState_RteUpdate(void);
static void Power_MCUSMOutMgr(void);

#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"

typedef enum 
{
    OutputState_IVI_OFF,
    OutputState_IVI_STANDBY,
    OutputState_IVI_ON,
    OutputState_IVI_SHUTDOWN,
    OutputState_IVI_REMOTE,
    OutputState_IVI_ON_NORMAL,
    OutputState_IVI_ON_POWER_ERROR,
    OutputState_IVI_ON_POWER_SAVE1,
    OutputState_IVI_ON_POWER_SAVE2,
    OutputState_IVI_ON_LOCAL,
    OutputState_IVI_DEMO,
    OutputState_IVI_AwakeHold,
    OutputState_NUM,
}IVI_OutputState_t;

typedef struct
{
  IVI_OutputState_t IVI_OutputState;
  uint8 IVI_SystemStatus;
}IVI_OutputStateTrans_t;
static const IVI_OutputStateTrans_t IVI_OutStateTrans_Table[OutputState_NUM]=
{
    {OutputState_IVI_OFF             ,SYSTEMSTATE_IVI_OFF},
    {OutputState_IVI_STANDBY         ,SYSTEMSTATE_IVI_STANDBY},
    {OutputState_IVI_ON              ,SYSTEMSTATE_IVI_ON},
    {OutputState_IVI_SHUTDOWN        ,SYSTEMSTATE_IVI_SHUTDOWN},
    {OutputState_IVI_REMOTE          ,SYSTEMSTATE_IVI_REMOTE},
    {OutputState_IVI_DEMO            ,SYSTEMSTATE_IVI_DEMO},
    {OutputState_IVI_AwakeHold       ,SYSTEMSTATE_IVI_AWAKEHOLD},
    {OutputState_IVI_ON_NORMAL       ,SYSTEMSTATE_IVI_ON_NORMAL},
    {OutputState_IVI_ON_POWER_ERROR  ,SYSTEMSTATE_IVI_ON_POWER_ERROR},
    {OutputState_IVI_ON_POWER_SAVE1  ,SYSTEMSTATE_IVI_ON_POWER_SAVE_1},
    {OutputState_IVI_ON_POWER_SAVE2  ,SYSTEMSTATE_IVI_ON_POWER_SAVE_2},
    {OutputState_IVI_ON_LOCAL        ,SYSTEMSTATE_IVI_ON_LOCAL},
};

typedef struct
{
	uint8 nm_outstate;
	uint8 nm_state;
}PM_NM_OutputTrans_t;
static const PM_NM_OutputTrans_t PM_NM_outTrans_Table[5] = 
{
	{NM_OUT_Bussleep    ,NM_STATE_BUS_SLEEP},
	{NM_OUT_Prebussleep ,NM_STATE_PREPARE_BUS_SLEEP},
	{NM_OUT_Normal		,NM_STATE_REPEAT_MESSAGE},
	{NM_OUT_Normal		,NM_STATE_READY_SLEEP},
	{NM_OUT_Normal		,NM_STATE_NORMAL_OPERATION},
};
#define POWER_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Power_MemMap.h"

static SystemState_RecordType SystemState_RteOut;
static uint8 SystemState_IVINoForceResponse;
static uint8 SystemState_QnxCloseResponse;
static Rte_DT_s_PowerOut_t_0 Voltage_PABackup =VOLTAGE_OUT_NORMAL;
static s_TempOut_t Temp_PABackup = {TEMP_NORMAL,(sint16)0};
static SystemState_KL15_PA_t KL15_PABackup = {SYSTEMSTATE_KL15_ON};
static SystemState_HUD_PA_t HUD_PABackup = {SYSTEMSTATE_HUD_OFF};
static uint8 Power_PABackup = 0u;
static SystemState_Console_PA_t Console_PABackup = {SYSTEMSTATE_CONSOLE_OFF};
static s_Systemstate_IVI_PA_t IVI_PABackup = {SYSTEMSTATE_IVI_OFF,1};
static SystemState_Cluster_PA_t Cluster_PABackup;
static uint8 NmSendSts_PABackup = NM_STATE_BUS_SLEEP; 

static IPC_S2M_POWERSystemStateAPP_INFOSM_t PM_VirtualEventcbk[VirtualEvent_NUM] = PM_VirtualEventcbk_INIT_TALBE;

static boolean VoltageIPCSts;
static boolean TempIPCSts;
static boolean KL15IPCSts;
static boolean HUDIPCSts;
static boolean PowerIPCSts;
static boolean ConsoleIPCSts;
static boolean IVIIPCSts;
static boolean ClusterIPCSts;
static boolean NmstateIPCSts;

static uint8 IPCSendTimer;
static uint32 TimerFlg;
static uint8 SOCGet[SMGETNUM];

#define POWER_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Power_MemMap.h"


#define POWER_START_SEC_CODE
#include "Power_MemMap.h"

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
 
static void Power_NMOutMgr(void)
{
    uint8 canNmRet = E_NOT_OK;
    uint8 nmState = NM_STATE_UNINIT;
    uint8 nmMode = NM_STATE_UNINIT;//no use
	int32_t IpcSendResult = -1;
	uint8 PM_APP_SendData[2] = {APP_INFOSM_NM,0};
    IPC_S2M_POWERSystemStateAPP_INFOSM_t NMcbksts_local;
    uint8 i;
    static uint8 NmChange_sendflag = 0;
    canNmRet = CanNm_GetState(0, &nmState, &nmMode);
    NMcbksts_local = Power_NMcbksts_Get();
    
	for (i=0;i<5;i++)
    {
        if((PM_NM_outTrans_Table[i].nm_state == nmState)&&(E_OK == canNmRet))
        {
            PM_APP_SendData[1]  = PM_NM_outTrans_Table[i].nm_outstate;
            nmState = PM_NM_outTrans_Table[i].nm_outstate;
            break;
        }
    }

	if(nmState != NMcbksts_local.value )
	{
		NmChange_sendflag = 1;
	}
    else if(nmState == NMcbksts_local.value)
	{
		NmChange_sendflag = 0;//get soc callback,clear sendflag
	}

    if((FALSE != memcmp(&nmState,&NmSendSts_PABackup,sizeof(nmState)))||\
    	(POWER_IPCSENDRETRY == NmstateIPCSts)||(TRUE == SOCGet[SMGETNM])||\
        ((0u == IPCSendTimer)&&(1 == NmChange_sendflag)))
    	{
	        IpcSendResult = IPC_M2S_POWERPowerInfoAPP_INFOMS_Transmit((IPC_M2S_POWERPowerInfoAPP_INFOMS_t *)(PM_APP_SendData));
	        NmstateIPCSts = (boolean)Power_IPCSts(IpcSendResult);
	        //power_warn("send nm %d %d sendflag:%d",PM_APP_SendData[0],PM_APP_SendData[1],NmChange_sendflag);
			if( POWER_IPCSENDSUCCESS == NmstateIPCSts)
	        {
				SOCGet[SMGETNM] = (uint8)FALSE;
	        }
    	}
    (void)memcpy(&NmSendSts_PABackup,&nmState,sizeof(uint8));
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Power_HUDOutMgr(void)
{
    SystemState_HUD_PA_t HUD_PA = SystemState_HUDSts();

    if((FALSE != memcmp(&HUD_PA,&HUD_PABackup,sizeof(HUD_PA))) ||\
        (POWER_IPCSENDRETRY == HUDIPCSts)||(0u == IPCSendTimer)||(TRUE == SOCGet[SMGETHUD]))
    {
        int32_t IpcSendResult = -1;
        IpcSendResult = IPC_M2S_POWERSystemStateHUDState_Transmit((IPC_M2S_POWERSystemStateHUDState_t *)(void *)(&HUD_PA));
        HUDIPCSts = (boolean)Power_IPCSts(IpcSendResult);
        if(POWER_IPCSENDSUCCESS == IVIIPCSts)
        {
            SOCGet[SMGETHUD] = (uint8)FALSE;
        }
    }
    (void)memcpy(&HUD_PABackup,&HUD_PA,sizeof(HUD_PA));
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Power_ConsoleOutMgr(void)
{
    SystemState_Console_PA_t Console_PA = SystemState_ConsoleSts();
    
    if((FALSE != memcmp(&Console_PA,&Console_PABackup,sizeof(Console_PA))) ||\
        (POWER_IPCSENDRETRY == ConsoleIPCSts)||(0u == IPCSendTimer)||(TRUE == SOCGet[SMGETCONSOLE]))
    {
        int32_t IpcSendResult = -1;
        IpcSendResult = IPC_M2S_POWERSystemStateConsoleState_Transmit((IPC_M2S_POWERSystemStateConsoleState_t *)(void *)(&Console_PA));
        HUDIPCSts = (boolean)Power_IPCSts(IpcSendResult);
        if(POWER_IPCSENDSUCCESS == IVIIPCSts)
        {
            SOCGet[SMGETCONSOLE] = (uint8)FALSE;
        }
    }

    (void)memcpy(&Console_PABackup,&Console_PA,sizeof(Console_PA));
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Power_KL15OutMgr(void)
{
    SystemState_KL15_PA_t KL15_PA = SystemState_KLSts();

    if((FALSE != memcmp(&KL15_PA,&KL15_PABackup,sizeof(KL15_PA))) ||\
        (POWER_IPCSENDRETRY == KL15IPCSts)||(0u == IPCSendTimer)||(TRUE == SOCGet[SMGETKL15]))
    {
        int32_t IpcSendResult = -1;
        IpcSendResult = IPC_M2S_POWERPowerInfoKL15State_Transmit((IPC_M2S_POWERPowerInfoKL15State_t *)(void *)(&KL15_PA));
        KL15IPCSts = (boolean)Power_IPCSts(IpcSendResult);
        if(POWER_IPCSENDSUCCESS == KL15IPCSts)
        {
            SOCGet[SMGETKL15] = (uint8)FALSE;
        }
    }
    (void)memcpy(&KL15_PABackup,&KL15_PA,sizeof(KL15_PA));
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Power_IVIOutMgr(void)
{
    uint8 i;
    s_Systemstate_IVI_PA_t IVI_PA = SystemState_IVISts();
    if(SYSTEMSTATE_IVI_SHUTDOWN == IVI_PA.State)
    {
        IVI_PA.Force = 0u;
    }
    else
    {
        IVI_PA.Force = 1u;
    }
	
    for (i=0;i<OutputState_NUM;i++)
    {
        if(IVI_OutStateTrans_Table[i].IVI_SystemStatus == IVI_PA.State)
        {
            IVI_PA.State = IVI_OutStateTrans_Table[i].IVI_OutputState;
            break;
        }
    }
	
    if((FALSE != memcmp(&IVI_PA,&IVI_PABackup,sizeof(IVI_PA))) ||\
        (POWER_IPCSENDRETRY == IVIIPCSts)||(0u == IPCSendTimer)||(TRUE == SOCGet[SMGETIVI]))
    {
        int32_t IpcSendResult = -1;
        IpcSendResult = IPC_M2S_POWERSystemStateIVI_State_Transmit((IPC_M2S_POWERSystemStateIVI_State_t *)(void *)(&IVI_PA));
        IVIIPCSts = (boolean)Power_IPCSts(IpcSendResult);
        if(POWER_IPCSENDSUCCESS == IVIIPCSts)
        {
            SOCGet[SMGETIVI] = (uint8)FALSE;
        }
        (void)power_verbose("IVI State is %d, Force is %d",IVI_PA.State, IVI_PA.Force);
    }
    (void)memcpy(&IVI_PABackup,&IVI_PA,sizeof(IVI_PA));
}


/***********************************************************************
 * @brief       : MCU SM interface send to SOC 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Power_MCUSMOutMgr(void)
{
    if((FALSE != memcmp(&SystemState_SP_State,&Power_PABackup,sizeof(Power_PABackup))) ||\
        (POWER_IPCSENDRETRY == PowerIPCSts)||(0u == IPCSendTimer)||(TRUE == SOCGet[SMGETMCU]))
    {
        int32_t IpcSendResult = -1;
        IpcSendResult = IPC_M2S_POWERSystemStateMCUState_Transmit((IPC_M2S_POWERSystemStateMCUState_t *)(void *)(&SystemState_SP_State));
        PowerIPCSts = (boolean)Power_IPCSts(IpcSendResult);
        if(POWER_IPCSENDSUCCESS == IVIIPCSts)
        {
            SOCGet[SMGETMCU] = (uint8)FALSE;
        }
        (void)power_verbose("SP State is %d", SystemState_SP_State);
        if(SystemState_SP_State == SYSTEMSTATE_SP_SOCOFF)
        {
            SystemState_QnxCloseResponse = 0;
        }
    }

    (void)memcpy(&Power_PABackup,&SystemState_SP_State,sizeof(Power_PABackup));
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SystemState_VoltageSend(void)
{
    s_PowerOut_t Voltage_PA;
    Rte_DT_s_PowerOut_t_0 voltage_state;
    Voltage_PA = Power_VoltageOutMgr();
	voltage_state = Voltage_PA.state;

    if((FALSE != memcmp(&voltage_state,&Voltage_PABackup,sizeof(Voltage_PABackup)) ||\
        (POWER_IPCSENDRETRY == VoltageIPCSts)||(0u == IPCSendTimer)))
    {
        int32_t IpcSendResult = -1;
        IPC_M2S_POWERPowerInfoVoltategeInfo_t PowerInfo;
        PowerInfo.VoltageState = Voltage_PA.state;
        PowerInfo.VoltageValue = (float)Voltage_PA.value/100;
        IpcSendResult = IPC_M2S_POWERPowerInfoVoltategeInfo_Transmit(&PowerInfo);
        VoltageIPCSts = (boolean)Power_IPCSts(IpcSendResult);
        
     }
        
    (void)memcpy(&Voltage_PABackup,&voltage_state,sizeof(Voltage_PABackup));
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SystemState_TemperatureSend(void)
{
    s_TempOut_t Temp_PA;
    Std_ReturnType ret;
    (void)memset(&Temp_PA,0,sizeof(Temp_PA));
    ret = Power_TempOut(&Temp_PA);
	
    if(FALSE != memcmp(&Temp_PA,&Temp_PABackup,sizeof(Temp_PA)) ||\
        (POWER_IPCSENDRETRY == TempIPCSts)||((0u == IPCSendTimer)||(TRUE == SOCGet[SMGETTEMP]))&&(ret == E_OK))
    {
        int32_t IpcSendResult = -1;
        IPC_M2S_POWERPowerInfoTemperature_t Temperature;
        Temperature.TemperatureState = Temp_PA.State;
        Temperature.Temperature = (float)Temp_PA.Value;
        IpcSendResult = IPC_M2S_POWERPowerInfoTemperature_Transmit(&Temperature);
        TempIPCSts = (boolean)Power_IPCSts(IpcSendResult);
        if(POWER_IPCSENDSUCCESS == TempIPCSts)
        {
            SOCGet[SMGETTEMP] = (uint8)FALSE;
        }
    }
        
    (void)memcpy(&Temp_PABackup,&Temp_PA,sizeof(Temp_PA));
}

/***********************************************************************
 * @brief       : ivi power state change,receive msg. 
 * @param       : 
 * @retval      : 1:ivi init finish
 				  0:ivi not init finish
 ***********************************************************************/
void SystemState_IVINOForceResponseFunc(uint8 * param, uint16 param_len)
{
    IPC_S2M_POWERSystemStateIVI_State_t data ={0};
    IPC_S2M_POWERSystemStateIVI_State_Receive(param,&data,IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_IVI_STATE_LENGTH);
    SystemState_IVINoForceResponse = data.TransferResponse;
    POWER_GET_OSTiCK(&TimerFlg);
    (void)power_warn("[%ld Ms]ivi startup sts:%d",TimerFlg, SystemState_IVINoForceResponse);
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SystemState_QnxCloseResponseFunc(uint8 *param, uint16 param_len)
{
    IPC_S2M_POWERSocManagerQnxResponseMCURequest_t data ={0};
    IPC_S2M_POWERSocManagerQnxResponseMCURequest_Receive(param,&data,IPC_S2M_POWER_SOCMANAGER_MSGSUB_QNXRESPONSEMCUREQUEST_LENGTH);
    SystemState_QnxCloseResponse = data.QnxResponseMCURequest;
    POWER_GET_OSTiCK(&TimerFlg);
    (void)power_warn("[%ld Ms]got Qnxclose resp:%d",TimerFlg, SystemState_QnxCloseResponse);
}
static void POWER_VirtualEventFunc(void)
{
	uint8 i;	
	int32_t IpcSendResult[VirtualEvent_NUM] = {-1,-1,-1,-1};
	static PM_VirtualSendFlag Msg_flagtable[VirtualEvent_NUM] = VirtualSendFlag_INIT_TABLE;
	for(i = 0; i < VirtualEvent_NUM ; i++)
	{
		/*got callback msg*/
		if(i == PM_VirtualEventcbk[i].value)
		{
			Msg_flagtable[i].callbackmsg = PM_CALLBCAKMSG_RECIVE;
			Msg_flagtable[i].isactive = PM_VIRTUAL_ACTIVE;
			PM_VirtualEventcbk[i].value = 0xff;
		}
		if(NO_EVENT == PM_VirtualEventTable[i].PMVirtualEventResult())
		{
			Msg_flagtable[i].immediatesend = PM_FIRSTMSG_NOTSEND;
			Msg_flagtable[i].isactive = PM_VIRTUAL_NOACTIVE;
			Msg_flagtable[i].sendsts = PM_NOSEND;
			Msg_flagtable[i].callbackmsg = PM_CALLBCAKMSG_NOWAIT;
		}
 		else if(((EVENT_OCCUR == PM_VirtualEventTable[i].PMVirtualEventResult())&&
			 (PM_VIRTUAL_NOACTIVE == Msg_flagtable[i].isactive)&&
			 (PM_FIRSTMSG_NOTSEND == Msg_flagtable[i].immediatesend))||\
			 (PM_SENDING == Msg_flagtable[i].sendsts)||\
			 ((PM_CALLBCAKMSG_WAITING == Msg_flagtable[i].callbackmsg)&&\
			 (0u == IPCSendTimer)))
			{
				Msg_flagtable[i].sendsts = PM_SENDING;
				Msg_flagtable[i].callbackmsg = PM_CALLBCAKMSG_WAITING;
				IpcSendResult[i] = IPC_M2S_POWERPowerInfoAPP_INFOMS_Transmit((IPC_M2S_POWERPowerInfoAPP_INFOMS_t *)(PM_VirtualEventTable[i].Virtual_EventMsg));
				//power_warn("virtual  event %d",i);
				if(POWER_IPCSENDSUCCESS == IpcSendResult[i])
				{
					Msg_flagtable[i].sendsts  = PM_NOSEND;
					Msg_flagtable[i].immediatesend	= PM_FIRSTMSG_SENDSUCCESS;
				}
			}
		else
		{
			/*do nothing*/
		}
	}
	
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SystemState_OutMain(void)
{
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();
    if(SYSTEMSTATE_IPCREADY == Systemstate_Condition_element_local.IPCSts)
    {
        IPCSendTimer ++;
        if(200u == IPCSendTimer)
        {
            IPCSendTimer = 0u;
        }
        POWER_VirtualEventFunc();
        Power_NMOutMgr();
        Power_HUDOutMgr();
        Power_ConsoleOutMgr();
        Power_KL15OutMgr();
        SystemState_VoltageSend();
        Power_IVIOutMgr();
        Power_ClusterOutMgr();
        SystemState_TemperatureSend();
        Power_MCUSMOutMgr();
    }
    SystemState_RteUpdate();
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SystemState_OutInit(void)
{
    SystemState_RteOut.ClusterState = SYSTEMSTATE_Cluster_OFF;
    SystemState_RteOut.HUDState = SYSTEMSTATE_HUD_OFF;
    SystemState_RteOut.ConsoleState = SYSTEMSTATE_CONSOLE_OFF;
    SystemState_RteOut.IVIState = SYSTEMSTATE_IVI_OFF;
    SystemState_RteOut.KL15State = SYSTEMSTATE_KL15_OFF;
    SystemState_RteOut.s_PowerVoltage.value = (Rte_DT_SystemState_RecordType_5_1)0;
    SystemState_RteOut.s_PowerVoltage.state = VOLTAGE_OUT_NORMAL;
    SystemState_RteOut.SP_State = SYSTEMSTATE_SP_OFF;
    SystemState_RteOut.s_TempVoltage.temperature = (Rte_DT_SystemState_RecordType_7_1)0;
    SystemState_RteOut.s_TempVoltage.state = TEMP_STATE_INIT;
    SystemState_IVINoForceResponse = 0u;
    SystemState_QnxCloseResponse = 0u;
    IPCSendTimer = 0u;
    Cluster_PABackup = SYSTEMSTATE_Cluster_OFF;
    IVI_PABackup.State = SYSTEMSTATE_IVI_OFF;
    IVI_PABackup.Force = 1;
    Power_PABackup = SYSTEMSTATE_SP_OFF;
	NmSendSts_PABackup = NM_STATE_BUS_SLEEP; 
    
    VoltageIPCSts = (boolean)POWER_IPCSENDSUCCESS;
    TempIPCSts = (boolean)POWER_IPCSENDSUCCESS;
    KL15IPCSts = (boolean)POWER_IPCSENDSUCCESS;
    ClusterIPCSts = (boolean)POWER_IPCSENDSUCCESS;
    IVIIPCSts = (boolean)POWER_IPCSENDSUCCESS;
    PowerIPCSts = (boolean)POWER_IPCSENDSUCCESS;
    
    (void)memset(SOCGet,0,sizeof(SOCGet));
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Power_ClusterOutMgr(void)
{
    SystemState_Cluster_PA_t Cluster_PA = SystemState_ClusterSts();

    if((FALSE != memcmp(&Cluster_PA,&Cluster_PABackup,sizeof(Cluster_PA))) ||\
        (POWER_IPCSENDRETRY == ClusterIPCSts)||(0u == IPCSendTimer)||(TRUE == SOCGet[SMGETCLUSTER]))
    {
        int32_t IpcSendResult = -1;
        IpcSendResult = IPC_M2S_POWERSystemStateClusterState_Transmit((IPC_M2S_POWERSystemStateClusterState_t *)(void *)(&Cluster_PA));
        ClusterIPCSts = (boolean)Power_IPCSts(IpcSendResult);
        power_verbose("Cluster ipc Send %d",Cluster_PA);
        if (Cluster_PABackup != Cluster_PA)
        {
            (void)power_verbose("<Check point> IPC send %d->%d",Cluster_PABackup,Cluster_PA);
        }
        if(POWER_IPCSENDSUCCESS == IVIIPCSts)
        {
            SOCGet[SMGETCLUSTER] = (uint8)FALSE;
        }
    }
    (void)memcpy(&Cluster_PABackup,&Cluster_PA,sizeof(Cluster_PA));
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint8 Power_IPCSts(int32_t IPCResult)
{
    uint8 ret = POWER_IPCSENDSUCCESS;
    if(0u != IPCResult)
    {
        ret  = POWER_IPCSENDRETRY;
    }
    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
uint8 Power_IVIResponse(void)
{
    return SystemState_IVINoForceResponse;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
uint8 Power_QnxCloseResponse(void)
{
    return SystemState_QnxCloseResponse;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SystemState_RteUpdate(void)
{
    s_PowerOut_t Voltage_PA;
    SystemState_KL15_PA_t KL15_PA;
    SystemState_HUD_PA_t HUD_PA;
    SystemState_Console_PA_t Console_PA;
    s_Systemstate_IVI_PA_t IVI_PA;
    SystemState_Cluster_PA_t Cluster_PA;
    s_TempOut_t TempOut_PA;
    KL15_PA = SystemState_KLSts();
    HUD_PA = SystemState_HUDSts();
    Console_PA = SystemState_ConsoleSts();
    IVI_PA = SystemState_IVISts();
    Voltage_PA = Power_VoltageOutMgr();
    Cluster_PA = SystemState_ClusterSts();
    (void)Power_TempOut(&TempOut_PA);

    SystemState_RteOut.KL15State = KL15_PA.State;
    SystemState_RteOut.HUDState = HUD_PA.State;
    SystemState_RteOut.ConsoleState = Console_PA.State;
    SystemState_RteOut.IVIState = IVI_PA.State;
    SystemState_RteOut.s_PowerVoltage.state = Voltage_PA.state;
    SystemState_RteOut.s_PowerVoltage.value = (float64)Voltage_PA.value / 100;
    SystemState_RteOut.ClusterState = Cluster_PA;
    SystemState_RteOut.s_TempVoltage.state = TempOut_PA.State;
    if (TRUE == TempOut_PA.bTempFault)
    {
        SystemState_RteOut.s_TempVoltage.temperature = POWER_TemperatureOverflow;
    }
    else
    {
        SystemState_RteOut.s_TempVoltage.temperature = TempOut_PA.Value;
    }

    SystemState_RteOut.SP_State = SystemState_SP_Sts();
    (void)Rte_Write_ppSR_Power_Out_SystemStateOut(&SystemState_RteOut);
}

/***********************************************************************
 * @brief       : receive FOTA response, if receive FOTAON, reset Timer
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SystemState_FOTASts(uint8 * param, uint16 param_len)
{
    IPC_M2S_POWERPowerInfoFOTAACK_t FOTAACK = {0x1u};
    IPC_S2M_POWERSystemStateFOTASts_t data ={0};
    IPC_S2M_POWERSystemStateFOTASts_Receive(param,&data,IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_FOTASTS_LENGTH);
    IVI_FOTASts(&data.State);
    POWER_GET_OSTiCK(&TimerFlg);
    (void)power_warn("[%ld Ms]MCU got FOTASts data %d", TimerFlg, data.State);
    (void)IPC_M2S_POWERPowerInfoFOTAACK_Transmit(&FOTAACK);
    (void)power_warn("[%ld Ms]MCU Send FOTASts ACK", TimerFlg);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SystemState_GetSMSts(uint8 * param, uint16 param_len)
{
    IPC_S2M_POWERSystemStateGetSMSts_t data ={0};
    IPC_S2M_POWERSystemStateGetSMSts_Receive(param,&data,IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_GETSMSTS_LENGTH);
    SOCGet[data.State] = (uint8)TRUE;
}
IPC_S2M_POWERSystemStateAPP_INFOSM_t* Power_VirtualEventcbk_Get(void)
{
	return (IPC_S2M_POWERSystemStateAPP_INFOSM_t*)PM_VirtualEventcbk;
}


#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"







