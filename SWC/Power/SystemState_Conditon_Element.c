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
 * @file:      SystemState_Conditon_Element.c
 * @author:    Nobo
 * @date:      2020-7-6
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-7-6
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "SystemState_Conditon_Element.h"
#include "DevConfig.h"
#include "Logger_Cfg.h"
#include "logger.h"
#include "Ipc_If.h"
#include "Power_Temp_Monitor.h"
#include "VConfig.h"
#define  RTE_CORE
#include "Rte_Vconfig.h"

#ifndef POWERUSERTE
#include "Com_Cfg.h"
#include "ComEx_Cfg.h"
#endif

#include "VersionCfg.h"


#define POWER_START_SEC_CODE
#include "Power_MemMap.h"

static void SystemState_SM_NMState(void);
static void SystemState_SM_KL15(void);
static void SystemState_SM_DrvDoorSts(void);
static void SystemState_SM_Voltage(void);
static void SystemState_SM_LvPwrSysErr(void);
static void SystemState_SM_Stat_PwrSv_Lvl(void);
static void SystemStateNFCConnect(void);
static void SystemState_SM_TransP_Mode(void);
static void SystemState_SM_EngineANDReady_State(void);
static void SystemState_SM_AntitheftSts(void);
static void SystemState_SM_HUD_State(void);
static void SystemState_SM_ShortTime_State(void);
static void SystemState_SM_DVR_State(void);
static void SystemState_SM_IPCStatus(void);
static boolean SystemState_SM_DVRHeartBeat(uint8 DVRSOCReqState);

static void Power_LogMain(void);
static void Power_LogInit(void);
static void SystemState_Element_LogFunc(void);
static uint8 SystemState_SM_EngineANDReady_State_Type(void);

#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"




#define POWER_START_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h"
static const SystemState_Cfg_Posi VEHICLE_TYPE_CFG[VEHICLE_CFG_NUM] =
{
	{0x00,0x00,0x00},
	{0x01,0x00,0x00},
	{0x02,0x00,0x00},
	{0x07,0x00,0x00},
	
	{0x00,0x01,0x00},
	{0x01,0x01,0x00},
	{0x02,0x01,0x00},
	{0x07,0x01,0x00},//ECM2 engstate

	{0x04,0x02,0x01},
	{0x04,0x04,0x01},

	{0x03,0x05,0x01},
	{0x03,0x06,0x01},
	{0x04,0x05,0x01},
	{0x04,0x06,0x01},//HCU_RdyLmpSts

	{0x05,0xff,0x02},//VCU_RdyLEDSts reserve
};

static const char * PowerNMStateLog[2] = 
{
    "No Communication",
    "Full Communicaiton",
};

static const char * PowerKL15Log[2] = 
{
    "OFF",
    "ON",
};

static const char * PowerDriverDoorLog[2] = 
{
    "Close",
    "Open",
};
	
static const char * PowerDVRRequest[2] = 
{
    "Disable",
    "Enable",
};

static const char * PowerLvPwrSysErrLog[2] = 
{
    "No Error",
    "Error",
};

static const char * PowerTransPModeLog[3] = 
{
    "NormalMode",
    "TransPMode ON",
    "TransPMode ON 3S",
};

static const char * PowerEngstsReadyLog[2] = 
{
    "EngstateANDreadyOFF",
    "EngstateANDreadyON",
};


static const char *PowerStat_PwrSv_LvlLog[4] = 
{
    "Normal",
    "Level 1",
    "Level 2",
    "Level 2 more than 180s",
};

static const char * PowerHUDStateLog[2] = 
{
    "HUD Open",
    "HUD Close",
};

static const char * PowerAntitheftStsLog[2] = 
{
    "AntitheftSts No Trigger",
    "AntitheftSts Trigger",
};

static const char * PowerNFCStateLog[2] = 
{
    "NFC No Connect",
    "NFC Connect",
};

static const char * PowerVoltageStateLog[3] = 
{
    "Voltage Normal",
    "Voltage HighAlarm",
    "Voltage Sleep",
};

    
#define POWER_STOP_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h"


#define POWER_START_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h"

static const uint16 LogTimerCount[TimerNum] =
{
#define X_MACRO_LOTTIMER(a,b) b,
    LOGTIMERTABLE
#undef X_MACRO_LOTTIMER
};


#define POWER_STOP_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h"


#define POWER_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "POWER_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

static uint8  Stat_PwrSv_LvlBackup;
static uint16 Stat_PwrSv_LvlTimer;
static uint16 SystemState_TranpMode_Counter;
static uint32 PowerLogTimer;
static uint8 TranPMode_StsBackup;
static uint8 PM_KL15_Memorysts;

extern s_PowerOut_t Power_OutDataCurrent;
static Systemstate_Condition_element_t Systemstate_Condition_element;
static Systemstate_Condition_element_t Systemstate_Condition_elementPre;
static uint32 TimerFlg = 0u;

#define POWER_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "POWER_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define POWER_START_SEC_CODE
#include "Power_MemMap.h"


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SystemState_ElementInit(void)
{
    Stat_PwrSv_LvlBackup = 0u;
    Stat_PwrSv_LvlTimer = 0u;
    SystemState_TranpMode_Counter = 0u;
    Systemstate_Condition_element.HUD_State = SYSTEMSTATE_HUD_OPEN;
    Systemstate_Condition_elementPre.HUD_State = SYSTEMSTATE_HUD_OPEN;
    TranPMode_StsBackup = 0x0u;
	Power_LogInit();
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SystemState_ElementFunc(void)
{
    Power_LogMain();
    SystemState_SM_IPCStatus();
    SystemState_SM_NMState();
    SystemState_SM_KL15();
    SystemState_SM_DrvDoorSts();
    SystemState_SM_Voltage();
    SystemState_SM_LvPwrSysErr();
    SystemState_SM_Stat_PwrSv_Lvl();
    SystemStateNFCConnect();
    SystemState_SM_TransP_Mode();
	SystemState_SM_EngineANDReady_State();
    SystemState_SM_AntitheftSts();
    SystemState_SM_HUD_State();
	SystemState_SM_ShortTime_State();
	SystemState_SM_DVR_State();
    SystemState_Element_LogFunc();
    (void)memcpy(&Systemstate_Condition_elementPre,&Systemstate_Condition_element,sizeof(Systemstate_Condition_element));
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean SystemState_SM_DVRHeartBeat(uint8 DVRSOCReqState)
{
    uint8 HeartbeatCounter;
    static uint8 HeartbeatCounterOld;
    static uint32 HeartbeatTimeoutFlg;
    uint32 CurrntTime;
    uint8 DVRRequestACK[2] ={APP_INFOMSTYPE_AVRACK,0};
    static boolean DVRHeartBeatFlg;
    (void)Rte_Read_AwakeHlod_Heartbeat_counter(&HeartbeatCounter);

    if(HeartbeatCounter != HeartbeatCounterOld)
    {
        DVRRequestACK[1] = DVRSOCReqState;
        (void)IPC_M2S_POWERPowerInfoAPP_INFOMS_Transmit((IPC_M2S_POWERPowerInfoAPP_INFOMS_t*)&DVRRequestACK);
        POWER_GET_OSTiCK(&HeartbeatTimeoutFlg);
        DVRHeartBeatFlg = DVRHEARTBEAT_NORMAL;
        HeartbeatCounterOld = HeartbeatCounter;
    }
    if(DVRSOCREQCONNECT == DVRSOCReqState)
    {
        POWER_GET_OSTiCK(&CurrntTime);
        if((CurrntTime - HeartbeatTimeoutFlg) > DVRHEARTBEAT_TIMEOUT10MIN)
        {
            DVRHeartBeatFlg = DVRHEARTBEAT_TIMEOUT;
            HeartbeatTimeoutFlg = CurrntTime;
            (void)power_warn("DVR Heartbeat timeout");
        }
    }
    return DVRHeartBeatFlg;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SystemState_SM_DVR_State(void)
{
    uint8 DVRTboxRequest_Local;
    uint8 DVRSOCreqConnectState;
    uint8 FuelCfg = 0xFF;//set initial value
    IPC_S2M_POWERSystemStateAPP_INFOSM_t QNXReqFlg;
    static boolean DVRPrintFlg;
    boolean DVRHeartBeatSt;
    (void)ComEx_ReceiveSignal(COMEX_SIGNAL_RX_T_BOX_REMTVIDEOMONRENAREQ_APP, &DVRTboxRequest_Local, 1);
    (void)Rte_Read_AWakeHold_DVRRemtCnSts(&DVRSOCreqConnectState);
    (void)VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(3,&FuelCfg);

    DVRHeartBeatSt = SystemState_SM_DVRHeartBeat(DVRSOCreqConnectState);
    QNXReqFlg = Power_QNXReqFlg_Get();

    if (((DVRSOCREQCONNECT == DVRSOCreqConnectState)&&(DVRHEARTBEAT_NORMAL == DVRHeartBeatSt))||\
    (DVRTBOXREQENABLE == DVRTboxRequest_Local))
    {
        if (0 == DVRPrintFlg)
        {
            if (DVRSOCREQCONNECT == DVRSOCreqConnectState)
            {
                (void)power_warn("DVR SOC req and cfg %d",FuelCfg);
            }
            else
            {
                (void)power_warn("DVR Tbox req and cfg %d",FuelCfg);
            }
            DVRPrintFlg = 1;
        }
        if (((FuelCfg == SYSTEMSTATE_DERV)||(FuelCfg == SYSTEMSTATE_GASOLINE)||\
        (FuelCfg == SYSTEMSTATE_CNGANDGASOLINE)||(FuelCfg == SYSTEMSTATE_CNG))&&(NOREQUEST == QNXReqFlg.value))
        {
            Systemstate_Condition_element.DVRRequset = SYSTEMSTATE_DERVENABLE;
        }
        else
        {
            Systemstate_Condition_element.DVRRequset = SYSTEMSTATE_DERVDISABLE;
        }
    }
    else
    {
        Systemstate_Condition_element.DVRRequset = SYSTEMSTATE_DERVDISABLE;
        DVRPrintFlg = 0;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SystemState_SM_ShortTime_State(void)
{
	boolean IVI_ShortTimeSts = SYSTEMSTATE_SHORTTIME_CLOSE;
#ifdef POWER_USE_ES13_SHORT_TIME
	(void)Rte_Read_Power_ClutoPow_HUT28_ShortTime_Element(&IVI_ShortTimeSts);
#else 
	IVI_ShortTimeSts = SYSTEMSTATE_SHORTTIME_CLOSE;
#endif

	Systemstate_Condition_element.ShortTime = IVI_ShortTimeSts;

}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
uint8 SystemState_TimerKernel(uint32 * timer, uint32 timeout)
{
    if ((*timer > 0) && (*timer < timeout))
    {
        (*timer) ++;
    }

    if (*timer >= timeout)
    {
        return SYSTEMSTATE_TIMEOUT;
    }
    else 
    {
        return SYSTEMSTATE_TIMERNORMAL;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SystemState_SM_NMState(void)
{
    uint8 ComMode = COMM_NO_COMMUNICATION;

#ifdef DEV_DEBUG_ON
    ComMode = COMM_FULL_COMMUNICATION;
#else
    (void)ComM_GetCurrentComMode(0, &ComMode);
#endif

    if (COMM_NO_COMMUNICATION == ComMode)
    {
        Systemstate_Condition_element.NMState = SYSTEMSTATE_NMNOCOMMUNICATION;
    }
    else 
    {
        Systemstate_Condition_element.NMState = SYSTEMSTATE_NMFULLCOMMUNICATION;
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SystemState_SM_KL15(void)
{
    uint8 retSysPowerMod = RTE_E_NEVER_RECEIVED;
    uint8 SysPowerMod_local = 0u;
	uint8 retSysPowerModVld = RTE_E_NEVER_RECEIVED;
    uint8 SysPowerModVld_local = 0u;
    static uint8 logflag = 1u;
    boolean retVal = TRUE ;
#ifdef POWERUSERTE
    retSysPowerMod = Rte_Read_SysPowerMod_SysPowerMod(&SysPowerMod_local);
	retSysPowerModVld = Rte_Read_SysPowerModVld_SysPowerModVld(&SysPowerModVld_local);
#else
    retSysPowerMod = ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD, &SysPowerMod_local, 1);
    retSysPowerModVld = ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMODVLD, &SysPowerModVld_local, 1);
    retVal = Com_IsRxPduGrpActive(COMEX_PDU_RX_PEPS2);
#endif

    if ((FALSE == (SIGNAL_NORMAL(retSysPowerMod)))||(FALSE == retVal))
    {
        SysPowerMod_local = 0u;
    }
    if (FALSE == (SIGNAL_NORMAL(retSysPowerModVld)))
    {
        SysPowerModVld_local = 0u;
        if(0 == logflag)
        {
        	(void)power_warn("SysPowerMod timeout");
        	logflag = 1;
        }
        
    }
    else
    {
		logflag = 0;
    }
	if(PM_KL15_Memorysts!=SysPowerMod_local)
	{
		(void)power_warn("KL15:%d",SysPowerMod_local);
	}
	PM_KL15_Memorysts = SysPowerMod_local;

#ifdef DEV_DEBUG_ON
    SysPowerMod_local = 2u;
	SysPowerModVld_local = 1u ;

#endif

    if(((1u == SysPowerMod_local) || (2u == SysPowerMod_local) || (3u == SysPowerMod_local))&&(1 == SysPowerModVld_local ))
    {
        Systemstate_Condition_element.KL15 = SYSTEMSTATE_KL15_ON;
    }
    else 
    {
        Systemstate_Condition_element.KL15 = SYSTEMSTATE_KL15_OFF;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SystemState_SM_Voltage(void)
{
    uint8 Power_TempetureFlg    = Power_TempStateTempFlg();

    if ((VOLTAGE_OUT_LOWSLEEP == Power_OutDataCurrent.state) || (VOLTAGE_OUT_HIGHSLEEP == Power_OutDataCurrent.state)||\
        (POWER_TEMP_ABNORMAL == Power_TempetureFlg))
    {
        Systemstate_Condition_element.Voltage_State = SYSTEMSTATE_VOLSLEEP;
    }
    else if (VOLTAGE_OUT_HIGHALARM == Power_OutDataCurrent.state)
    {
        Systemstate_Condition_element.Voltage_State = SYSTEMSTATE_VOLALARM;
    }
    else 
    {
        Systemstate_Condition_element.Voltage_State = SYSTEMSTATE_VOLNORMAL;
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SystemState_SM_LvPwrSysErr(void)
{
    uint8 retLvPwrSysErr = RTE_E_NEVER_RECEIVED;
    uint8 LvPwrSysErr_local = 0u;
    static uint8 logflag = 1u;

#ifdef POWERUSERTE
    retLvPwrSysErr = Rte_Read_LvPwrSysErr_LvPwrSysErr(&LvPwrSysErr_local);
#else
    retLvPwrSysErr = ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVPWRSYSERR, &LvPwrSysErr_local, 1);
#endif
    if (FALSE == (SIGNAL_NORMAL(retLvPwrSysErr)))
    {
        LvPwrSysErr_local = 0u;
        if(0 == logflag)
        {
        	(void)power_warn("LvPwrSysErr timeout");
        	logflag = 1;
        }
    }
    else
    {
		logflag = 0;
    }

    if (0x1u == LvPwrSysErr_local)
    {
        Systemstate_Condition_element.LvPwrSysErr_e = SYSTEMSTATE_LVPWRSYSERR_TRIGGER;
    }
    else 
    {
        Systemstate_Condition_element.LvPwrSysErr_e = SYSTEMSTATE_LVPWRSYSERR_UN_TRIGGER;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SystemState_SM_Stat_PwrSv_Lvl(void) 
{
    uint8 retStat_PwrSv_Lvl = RTE_E_NEVER_RECEIVED;
    uint8 Stat_PwrSv_Lvl_local = 0u;
    static uint8 logflag = 1u;
#ifdef POWERUSERTE
    retStat_PwrSv_Lvl = Rte_Read_Stat_PwrSv_Lvl_Stat_PwrSv_Lvl(&Stat_PwrSv_Lvl_local);
#else
    retStat_PwrSv_Lvl = ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STAT_PWRSV_LVL, &Stat_PwrSv_Lvl_local, 1);
#endif


    if (FALSE == (SIGNAL_NORMAL(retStat_PwrSv_Lvl)))
    {
        Stat_PwrSv_Lvl_local = 0u;
        if(0 == logflag)
        {
        	(void)power_warn("Stat_PwrSv_Lvl timeout");
        	logflag = 1;
        }
    }
    else
    {
		logflag = 0;
    }

    if ((TRUE == (SIGNAL_NORMAL(retStat_PwrSv_Lvl))) && (Stat_PwrSv_Lvl_local > 2u))
    {
        Stat_PwrSv_Lvl_local = 0u;
    }



    if (2u == Stat_PwrSv_Lvl_local)
    {
        if (2u == Stat_PwrSv_LvlBackup)
        {
            if (Stat_PwrSv_LvlTimer < SYSTENSTATE_Timer_180S)
            {
                Stat_PwrSv_LvlTimer++;
            }

            if (SYSTENSTATE_Timer_180S == Stat_PwrSv_LvlTimer)
            {
                Systemstate_Condition_element.Stat_PwrSv_Lvl_e = SYSTEMSTATE_START_PWRSV_LV1_TWO_180S;
            }
            else 
            {
                Systemstate_Condition_element.Stat_PwrSv_Lvl_e = SYSTEMSTATE_START_PWRSV_LV1_TWO;
            }
        }
        else 
        {
            Systemstate_Condition_element.Stat_PwrSv_Lvl_e = SYSTEMSTATE_START_PWRSV_LV1_TWO;
        }
    }
    else 
    {
        Systemstate_Condition_element.Stat_PwrSv_Lvl_e = Stat_PwrSv_Lvl_local;
        Stat_PwrSv_LvlTimer = 0u;
    }
    Stat_PwrSv_LvlBackup = Stat_PwrSv_Lvl_local;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SystemState_SM_DrvDoorSts(void)
{
    uint8 retDrvDoorSts = RTE_E_NEVER_RECEIVED;
    uint8 DrvDoorSts_local = 0u;
	static uint8 logflag = 1u;

#ifdef POWERUSERTE
        retDrvDoorSts = Rte_Read_DrvDoorSts_DrvDoorSts(&DrvDoorSts_local);
#else
        retDrvDoorSts = ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, &DrvDoorSts_local, 1);
#endif


    if (FALSE == (SIGNAL_NORMAL(retDrvDoorSts)))
    {
        DrvDoorSts_local = 0u;
        if(0 == logflag)
        {
        	(void)power_warn("DrvDoorSts timeout");
        	logflag = 1;
        }
    }
    else
    {
		logflag = 0;
    }

    if (1u == DrvDoorSts_local)
    {
        Systemstate_Condition_element.DriverDoor = SYSTEMSTATE_DRIVERDOOROPEN;
    }
    else 
    {
        Systemstate_Condition_element.DriverDoor = SYSTEMSTATE_DRIVERDOORCLOSE;
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SystemState_SM_AntitheftSts(void)
{
    uint8 retAntitheftSts = RTE_E_NEVER_RECEIVED;
    uint8 AntitheftSts_local = 0u;
	static uint8 logflag = 1u;
#ifdef POWERUSERTE
    retAntitheftSts = Rte_Read_AntitheftSts_AntitheftSts(&AntitheftSts_local); 
#else
    retAntitheftSts = ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ANTITHEFTSTS, &AntitheftSts_local, 1);
#endif


    if (FALSE == (SIGNAL_NORMAL(retAntitheftSts)))
    {
        AntitheftSts_local = 0u;
        if(0 == logflag)
        {
        	(void)power_warn("AntitheftSts timeout");
        	logflag = 1;
        }
    }
    else
    {
		logflag = 0;
    }

    if ((1u == AntitheftSts_local) || (2u == AntitheftSts_local) || (3u == AntitheftSts_local))
    {
        Systemstate_Condition_element.AntitheftSts_e = SYSTEMSTATE_ANTITHEFTSTSOPEN;
    }
    else 
    {
        Systemstate_Condition_element.AntitheftSts_e = SYSTEMSTATE_ANTITHEFTSTSCLOSE;
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SystemStateNFCConnect(void)
{
    uint8 retNFCState = RTE_E_NEVER_RECEIVED;
    uint8 NFCState = 0u;

    //retNFCState = Rte_Read_NFCState_NFCState(&NFCState); 
    if (FALSE == (SIGNAL_NORMAL(retNFCState)))
    {
        NFCState = 0u;
    }

    Systemstate_Condition_element.NFC_State = NFCState;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SystemState_SM_TransP_Mode(void)
{
    uint8 retTranPMode_Sts = RTE_E_NEVER_RECEIVED;
    uint8 TranPMode_Sts_local = 0u;
	static uint8 logflag = 1u;

#ifdef POWERUSERTE
    retTranPMode_Sts = Rte_Read_TranPMode_Sts_TranPMode_Sts(&TranPMode_Sts_local);
#else
    retTranPMode_Sts = ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRANPMODE_STS, &TranPMode_Sts_local, 1);
#endif
    if (FALSE == (SIGNAL_NORMAL(retTranPMode_Sts)))
    {
    	TranPMode_Sts_local = 0x0u;
        if(0 == logflag)
        {
        	(void)power_warn("TranPMode_Sts timeout");
        	logflag = 1;
        }
    }
    else
    {
		logflag = 0;
    }

    if ((TRUE == SIGNAL_NORMAL(retTranPMode_Sts)) && (0x1u == TranPMode_Sts_local))
    {
        TranPMode_Sts_local = 0x1u;
        if(0x0u == TranPMode_StsBackup)
        {
            POWER_GET_OSTiCK(&TimerFlg);
            (void)power_warn("[%ld]TranPMode normal->TranPMode",TimerFlg);
        }
    }
    else 
    {
        TranPMode_Sts_local = 0x0u;
        if(0x1u == TranPMode_StsBackup)
        {
            POWER_GET_OSTiCK(&TimerFlg);
            (void)power_warn("[%ld]TranPMode TranPMode->normal",TimerFlg);
        }
    }
    TranPMode_StsBackup = TranPMode_Sts_local;
    if (0x0u == TranPMode_Sts_local)
    {
        Systemstate_Condition_element.TransPMode = SYSTEMSTATE_TRANP_MODE_OFF;
        SystemState_TranpMode_Counter = 0u;
    }
    else /* 0x1u == TranPMode_Sts */
    {
        if (SystemState_TranpMode_Counter < SYSTENSTATE_Timer_3S)
        {
            SystemState_TranpMode_Counter++;
			Systemstate_Condition_element.TransPMode = SYSTEMSTATE_TRANP_MODE_ON;
        }
        if (SYSTENSTATE_Timer_3S == SystemState_TranpMode_Counter)
        {
            Systemstate_Condition_element.TransPMode = SYSTEMSTATE_TRANP_MODE_ON_3S;
        }
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint8 SystemState_SM_EngineANDReady_State_Type(void)
{
	uint8 fuel_cfg;
	uint8 motor_posi_cfg;
	uint8 ret_fuel_cfg;
	uint8 ret_motor_posi_cfg;
	uint8 i;
	uint8 vehicle_cfg = ENGSTATE_CFG;
	ret_fuel_cfg =  VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(3,&fuel_cfg);
	ret_motor_posi_cfg = VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(69,&motor_posi_cfg);
#if(VCONFIG_DEV_ERROR_DETECT == STD_ON) 
	if((ret_fuel_cfg == E_NOT_OK )||(ret_motor_posi_cfg == E_NOT_OK))
		{
		    return vehicle_cfg;
		}
#endif
	for(i = 0;i<VEHICLE_CFG_NUM;i++)
	{
		if((fuel_cfg == VEHICLE_TYPE_CFG[i].fuel_cfg_byte)&&
		  (motor_posi_cfg == (motor_posi_cfg & VEHICLE_TYPE_CFG[i].motorposi_cfg_byte)))
		    {
				vehicle_cfg = VEHICLE_TYPE_CFG[i].vehicle_type;
				break;	
		    }
	}
	return vehicle_cfg;

 	}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SystemState_SM_EngineANDReady_State(void)
{
    uint8 retengine_Sts = RTE_E_NEVER_RECEIVED;
    uint8 engine_Sts = 0u;
    uint8 HCU_retreadysts = RTE_E_NEVER_RECEIVED;
	static uint8 logflageng = 1u;
	static uint8 logflaghcu = 1u;
	static uint8 logflagVCU = 1u;
	#ifdef POWERUSERTE
    SG_HCU_PT7 SG_HCU_PT7_MES;
	#endif
    uint8 VCU_retreadysts = RTE_E_NEVER_RECEIVED;
    uint8 VCU_ready_Sts = 0u;
    uint8 Vehicle_cfg = 0u;
	uint8 HCU_ready_Sts = 0;
#ifdef POWERUSERTE
    retengine_Sts = Rte_Read_EngState_EngState(&engine_Sts);
    HCU_retreadysts = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&SG_HCU_PT7_MES);//b03 only fuel
    HCU_ready_Sts = (uint8)SG_HCU_PT7_MES.HCU_RdyLmpSts;
	//VCU_retreadysts = Rte_Read_HUD_SwtSts_HUD_SwtSts(&VCU_ready_Sts);//reserve
#else
    #ifdef POWER_USE_ENGSTATE
    retengine_Sts = ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSTATE, &engine_Sts, 1);
    #endif
	#ifdef POWER_USE_ENGSTATE_271
	retengine_Sts = ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSTATE_0X271, &engine_Sts, 1);
	#endif
	#ifdef POWER_USE_HCU_RDY
	HCU_retreadysts = ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS, &HCU_ready_Sts, 1);
	#endif
	#ifdef POWER_USE_EV
    VCU_retreadysts = ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VCU_RDYLEDSTS, &VCU_ready_Sts, 1);	
	#endif
#endif

    if (FALSE == (SIGNAL_NORMAL(retengine_Sts)))
    {
    	engine_Sts = 0x0u;
        if(0 == logflageng)
        {
        	(void)power_warn("engine_Sts timeout");
        	logflageng = 1;
        }
    }
    else
    {
    
		logflageng = 0;
    }
    if (FALSE == (SIGNAL_NORMAL(HCU_retreadysts)))
    {
    	HCU_ready_Sts = 0x0u;
        if(0 == logflaghcu)
        {
        	(void)power_warn("HCU_ready_Sts timeout");
        	logflaghcu = 1;
        }
    }
    else
    {
		logflaghcu = 0;
    }
	
    if (FALSE == (SIGNAL_NORMAL(VCU_retreadysts)))
    {
    	VCU_ready_Sts = 0x0u;
        if(0 == logflagVCU)
        {
        	(void)power_warn("VCU_ready_Sts timeout");
        	logflagVCU = 1;
        }
    }
    else
    {
		logflagVCU = 0;
    }

	Vehicle_cfg = SystemState_SM_EngineANDReady_State_Type();
	
	if(Vehicle_cfg == ENGSTATE_CFG)
	{
		if((engine_Sts == 1)||(engine_Sts == 2)||(engine_Sts == 3))
		{
			Systemstate_Condition_element.engstsready_sts = SYSTEMSTATE_EngineANDreadyON;
		}
		else if(engine_Sts == 0)
		{
		    Systemstate_Condition_element.engstsready_sts = SYSTEMSTATE_EngineANDreadyOFF;
		}
	}
	else if(Vehicle_cfg == HCU_RDYLEMSts_CFG)
	{
		if( HCU_ready_Sts== 1)
		{
			Systemstate_Condition_element.engstsready_sts = SYSTEMSTATE_EngineANDreadyON;
		}
		else if(HCU_ready_Sts == 0)
		{
			Systemstate_Condition_element.engstsready_sts = SYSTEMSTATE_EngineANDreadyOFF;
		}
	}
	else if(Vehicle_cfg == VCU_READYLEDSts_CFG)
	{
		if(VCU_ready_Sts == 1)
		{
			Systemstate_Condition_element.engstsready_sts = SYSTEMSTATE_EngineANDreadyON;
		}
		else if(VCU_ready_Sts == 0)
		{
			Systemstate_Condition_element.engstsready_sts = SYSTEMSTATE_EngineANDreadyOFF;
		}
	}
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SystemState_SM_HUD_State(void)
{
    uint8 retHUD_SwtSts = RTE_E_NEVER_RECEIVED;
    uint8 HUD_SwtSts_local = 1u;
	static uint8 logflag = 1u;

#ifdef POWERUSERTE
    retHUD_SwtSts = Rte_Read_HUD_SwtSts_HUD_SwtSts(&HUD_SwtSts_local);
#else
	#ifdef POWER_USE_HUD_SWTSTS
    //retHUD_SwtSts = ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HUD_SWTSTS, &HUD_SwtSts_local, 1);
    #endif
#endif

    if (FALSE == (SIGNAL_NORMAL(retHUD_SwtSts)))
    {
    	HUD_SwtSts_local = 0x0u;
        if(0 == logflag)
        {
        	(void)power_warn("HUD_SwtSts timeout");
        	logflag = 1;
        }
    }
    else
    {
		logflag = 0;
    }

    if (TRUE == (SIGNAL_NORMAL(retHUD_SwtSts)))
    {
        if (0x1u == HUD_SwtSts_local)
        {
            Systemstate_Condition_element.HUD_State = SYSTEMSTATE_HUD_OPEN;
        }
        else if (0x0u == HUD_SwtSts_local)
        {
            Systemstate_Condition_element.HUD_State = SYSTEMSTATE_HUD_CLOSE;
        }
        else 
        {
            /* keep previous value */
        }
    }
    else 
    {
        /* keep previous value */
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SystemState_SM_IPCStatus(void)
{
    e_IPC_StateType_t IpcSts;
    IpcSts = IPC_GetIPCStateType();

    if(IPC_CONN_READY == IpcSts)
    {
        Systemstate_Condition_element.IPCSts = SYSTEMSTATE_IPCREADY;
    }
    else
    {
        Systemstate_Condition_element.IPCSts = SYSTEMSTATE_IPCNOREADY;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SystemState_Element_LogFunc(void)
{
    if(memcmp(&Systemstate_Condition_element,&Systemstate_Condition_elementPre,sizeof(Systemstate_Condition_element)))
    {
        if(Systemstate_Condition_element.NMState!= Systemstate_Condition_elementPre.NMState)
        {
            POWER_GET_OSTiCK(&TimerFlg);
            (void)power_warn("[%ld]NetWork %s->%s \r\n",TimerFlg,PowerNMStateLog[Systemstate_Condition_elementPre.NMState],PowerNMStateLog[Systemstate_Condition_element.NMState]);
        }
        
        if(Systemstate_Condition_element.KL15 != Systemstate_Condition_elementPre.KL15)
		{
            (void)power_warn("Sig KL15 State %s->%s \r\n",PowerKL15Log[Systemstate_Condition_elementPre.KL15],PowerKL15Log[Systemstate_Condition_element.KL15]);
		}
        if(Systemstate_Condition_element.DriverDoor!= Systemstate_Condition_elementPre.DriverDoor)
		{
            (void)power_warn("Sig Driver Door %s->%s \r\n",PowerDriverDoorLog[Systemstate_Condition_elementPre.DriverDoor],PowerDriverDoorLog[Systemstate_Condition_element.DriverDoor]);
		}
        if(Systemstate_Condition_element.AntitheftSts_e != Systemstate_Condition_elementPre.AntitheftSts_e)
		{
            (void)power_warn("Sig AntitheftSts %s->%s \r\n",PowerAntitheftStsLog[Systemstate_Condition_elementPre.AntitheftSts_e],PowerAntitheftStsLog[Systemstate_Condition_element.AntitheftSts_e]);
		}
        if(Systemstate_Condition_element.Stat_PwrSv_Lvl_e != Systemstate_Condition_elementPre.Stat_PwrSv_Lvl_e)
		{
            (void)power_warn("Sig Stat_PwrSv_Lv1 %s->%s \r\n",PowerStat_PwrSv_LvlLog[Systemstate_Condition_elementPre.Stat_PwrSv_Lvl_e],PowerStat_PwrSv_LvlLog[Systemstate_Condition_element.Stat_PwrSv_Lvl_e]);
		}
        if(Systemstate_Condition_element.LvPwrSysErr_e != Systemstate_Condition_elementPre.LvPwrSysErr_e)
		{
            (void)power_warn("Sig LvPwrSysErr %s->%s \r\n",PowerLvPwrSysErrLog[Systemstate_Condition_elementPre.LvPwrSysErr_e],PowerLvPwrSysErrLog[Systemstate_Condition_element.LvPwrSysErr_e]);
		}
        if(Systemstate_Condition_element.TransPMode != Systemstate_Condition_elementPre.TransPMode)
        {
            POWER_GET_OSTiCK(&TimerFlg);
            (void)power_warn("[%ld]Sig Transport %s->%s \r\n",TimerFlg,PowerTransPModeLog[Systemstate_Condition_elementPre.TransPMode],PowerTransPModeLog[Systemstate_Condition_element.TransPMode]);
        }
        if(Systemstate_Condition_element.engstsready_sts != Systemstate_Condition_elementPre.engstsready_sts)
        {
            (void)power_warn("Sig engstsready_sts %s->%s \r\n",PowerEngstsReadyLog[Systemstate_Condition_elementPre.engstsready_sts],PowerEngstsReadyLog[Systemstate_Condition_element.engstsready_sts]);
        }

        if(Systemstate_Condition_element.HUD_State != Systemstate_Condition_elementPre.HUD_State)
		{
            (void)power_warn("HUD_State %s->%s \r\n",PowerHUDStateLog[Systemstate_Condition_elementPre.HUD_State],PowerHUDStateLog[Systemstate_Condition_element.HUD_State]);
		}
        if(Systemstate_Condition_element.NFC_State != Systemstate_Condition_elementPre.NFC_State)
		{
            (void)power_warn("NFC_State %s->%s \r\n",PowerNFCStateLog[Systemstate_Condition_elementPre.NFC_State],PowerNFCStateLog[Systemstate_Condition_element.NFC_State]);
		}
        if(Systemstate_Condition_element.Voltage_State != Systemstate_Condition_elementPre.Voltage_State)
        {
            POWER_GET_OSTiCK(&TimerFlg);
            (void)power_warn("[%ld]Voltage_State %s->%s \r\n",TimerFlg,PowerVoltageStateLog[Systemstate_Condition_elementPre.Voltage_State],PowerVoltageStateLog[Systemstate_Condition_element.Voltage_State]);
        }
        if(Systemstate_Condition_element.ShortTime != Systemstate_Condition_elementPre.ShortTime)
		{
            (void)power_warn("ShortTime State %s->%s \r\n",PowerDriverDoorLog[Systemstate_Condition_elementPre.ShortTime],PowerDriverDoorLog[Systemstate_Condition_element.ShortTime]);
		}
        if(Systemstate_Condition_element.DVRRequset != Systemstate_Condition_elementPre.DVRRequset)
		{
            (void)power_warn("DVRRequset State %s->%s \r\n",PowerDVRRequest[Systemstate_Condition_elementPre.DVRRequset],PowerDVRRequest[Systemstate_Condition_element.DVRRequset]);
		}
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
SystemState_KL15_PA_t SystemState_KLSts(void)
{
    SystemState_KL15_PA_t SystemState_KL15_PA;
    SystemState_KL15_PA.State = Systemstate_Condition_element.KL15;
    
    return SystemState_KL15_PA;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
Systemstate_Condition_element_t Systemstate_Condition_elementFunc(void)
{
    return Systemstate_Condition_element;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Power_LogInit(void)
{
    PowerLogTimer = 0u;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Power_LogMain(void)
{
    PowerLogTimer ++;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
uint8 PowerLogStsFunc(e_TimerEnum_t cfg)
{
    uint8 ret = LOGTIMERINIT;

    if(0u == (PowerLogTimer % LogTimerCount[cfg]))
    {
        ret = LOGTIMERTIMEOUT;
    }
    else
    {
        ret = LOGTIMERRUN;
    }
    return ret;
}

#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"

