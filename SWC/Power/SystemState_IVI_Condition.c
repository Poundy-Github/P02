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
 * @file:      SystemState_IVI_Condition.c
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

#include "SystemState_IVI_Condition.h"
#include "SystemState_Conditon_Element.h"
#include "Logger_Cfg.h"
#include "logger.h"
#include "Rte_Power.h"
#include "Power_OutMgr.h"
#include "Power_Volt_Monitor.h"
#include "DevConfig.h"
#ifndef POWERUSERTE
#include "Com_Cfg.h"
#include "ComEx_Cfg.h"
#endif

#define SM_IVI_STATE_MACHINE_NUMBER                 (2u)
#define SM_IVI_STATE_NUMBER                         (12u)
#define SM_IVI_TRANSFER_CONDITION_NUMBER            (10u)
#define SM_IVI_TRANSFER_ELEMENT_NUMBER              (50u)
#define SM_IVI_TRANSFER_ACTION_NUMBER               (338u)
#define SM_IVI_FEATURE_CONFIG_VALUE_NUMBER          (138u)
#define SM_IVI_FEATURE_VALUE_NUMBER                 (4u)
#define SM_IVI_ENTRY_NUMBER                         SM_IVI_STATE_MACHINE_NUMBER
#define SM_IVI_TRANSFER_NUMBER                      SM_IVI_STATE_MACHINE_NUMBER
#define SM_IVI_STAY_NUMBER                          SM_IVI_STATE_MACHINE_NUMBER
#define SYSTEMSTATE_KL15_10MIN                      (120000u)/*120000u 1000/5*600   10MIN*/
#define SYSTEMSTATE_KL15_PRETIMEOUT                 (117900u)/*117900u 1000/5*589.5 9MIN49.5S*/
/*APP Type*/
#define APP_INFOSM_LOCAL_STS                        (1u)
#define APP_INFOSM_NM                               (2u)
#define APP_INFOSM_DIAG2MINI                        (3u)
/*APP Value*/
#define SYSTEMSTATE_LOCAL_END	                    (2u)
#define SYSTEMSTATE_LOCAL_CONTINUE                  (1u)
#define SYSTEMSTATE_LOCAL_NO_REC                    (0u)
#define LOCAL_PRETIMEOUT_FLAG                       (1u)
#define SYSTEMSTATE_SHORTTIME_CLOSE                 (0u)
#define SYSTEMSTATE_SHORTTIME_OPEN                  (1u)

#define IVI_NOSEND                       			(0u)
#define IVI_SENDING                       			(1u)

#define IVI_ENTER_IVI_ON                            (0u)
#define IVI_ENTER_STANDBY                           (1u)
#define IVI_UN_ENTER                                (2u)
#define SYSTEMSTATE_IVINM_20S                       (4000)/*20s*/
#define FOTA_ON                                     (1u)
#define FOTA_OFF                                    (0u)
#define FOTA_TIMEOUT                                (480000u)/*40min*/
#define SEEKDWNANDPAGEL_PRESS                        (1)
#define SEEKDWNANDPAGEL_RELEASE                      (0)

#define DEMO_TO_STANDBY                             (0)
#define STANDBY_TO_DEMO                             (1)
#define DEMO_TO_IVION                               (2)

#define REMOTE_NORMALMODE                           (0u)
#define REMOTE_REMOTEMODE                           (1u)

#define REMOTE_TO_STANDBY                           (0u)
#define STANDBY_TO_REMOTE                           (1u)

#define AWAKEHOLD_TO_STANDBY                        (0u)
#define STANDBY_TO_AWAKEHOLD                        (1u)


#define SYSTENSTATE_Timer_500MS                     (100u)/*500ms*/
#define FOTASIGNALENABLE                            (0u)
#define FOTASIGNALDISABLE                           (1u)
#define CANIDCSA3                                   (0x244)
#define CANIDBCM6                                   (0x28C)
#define CANIDBCM11                                  (0x305)
#define CANIDBCM10                                  (0x2E7)
#define CANIDBCM8                                   (0x29F)
#define CANIDSTBS1                                  (0x21F)

typedef uint16                                      Pw_CanIdType;

#pragma ghs startdata
#pragma ghs section bss=".rram_reset_flag"

STATIC uint8 RemoteFlag;
STATIC uint8 FOTAFlag;

#pragma ghs section bss=default
#pragma ghs enddata




#define POWER_START_SEC_CODE
#include "Power_MemMap.h"

static void SM_EntryCallbackIVI(void);
static void SM_TransferCallbackIVI(SM_StateType previous, SM_StateType next);
static void SM_StayCallbackIVI(SM_StateType state);

static void SM_EntryCallbackIVI_ON(void);
static void SM_TransferCallbackIVI_ON(SM_StateType previous, SM_StateType next);
static void SM_StayCallbackIVI_ON(SM_StateType state);

static uint8 SM_ConditionIVI_NM_State(void);
static uint8 SM_ConditionIVI_Voltage_Sts(void);
static uint8 SM_ConditionIVI_Enter_Other_State(void);
static uint8 SM_ConditionIVI_Demo_Condition(void);
static uint8 SM_ConditionIVI_Receive_SOC_Flg(void);
static uint8 SM_ConditionIVI_Enter_Remote(void);
static uint8 SM_ConditionIVI_ONLvPwrSysErr(void);
static uint8 SM_ConditionIVI_ONStat_PwrSv_Lvl(void);
static uint8 SM_ConditionIVI_ONKL15(void);

static uint8 SM_ConditionIVI_Enter_AwakeHold(void);

static void FOTATimerLogic(void);
static void IVIInterKL15StsLogic(void);
static void IVIInterRemoteStsLogic(void);
static void FOTASignalCtrl(uint8 CtrlEnable);
void PM_ClearRemoteflag(void);



#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"


#define POWER_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Power_MemMap.h"

static SM_StateMachineType IVIstateMachineDatas[SM_IVI_STATE_MACHINE_NUMBER];
static uint8 IVIfeatureValues[SM_IVI_FEATURE_VALUE_NUMBER];
static s_Systemstate_IVI_PA_t SystemState_IVI_PA;
static SM_Type Sm_IVI;
static uint32 SystemState_IVIResponseTimer;
//static uint8 SystemState_IVIResponseTimerSts;
static uint32 SystemState_KL15Off10MinTimer;
static uint8 SystemState_KL15Off10MinTimerSts;
static uint16 SystemState_IVINM20STimer;
static uint32 TimerFlg;
static uint8 FOTASts;
static uint32 FOTATimer;
static uint8  IVIInterKL15Sts;
static uint8 IVIInterKL15StsBackup;
static uint8 SysPowerModBackup;
static uint8 SysPowerModVldBackup;
static IPC_S2M_POWERSystemStateAPP_INFOSM_t QNXReqExitAwakeHoldFlg;
static uint8 RemoteModStsBackup;

static uint16  SystemState_RemoteMode_Counter;
static boolean KL15ON_OnceFlag;
static uint8 SYSIVIlocal_timersts;
static IPC_S2M_POWERSystemStateAPP_INFOSM_t PM_NMcbksts;
#define POWER_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define POWER_START_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h"

static const SM_Type Sm_IVIInit = {SM_STATEMACHINE_INVALID, SM_SEQUENCE_IDLE, (boolean)FALSE, (boolean)FALSE, (boolean)FALSE, NULL_PTR};
static const s_Systemstate_IVI_PA_t IVI_PAInit = {SYSTEMSTATE_IVI_OFF,1};

static const uint8 IVIfeatureConfigValues[SM_IVI_FEATURE_CONFIG_VALUE_NUMBER] =
{
	0xFD, 0xFB, 0xFF, 
	0xFD, 0xFD, 0xFF, 
	0xDB, 0xFB, 0xFF, 
	0xDB, 0xFD, 0xFF, 
	0xEB, 0xFD, 0xFF, 
	0xEB, 0xFB, 0xFF, 
	0xB3, 0xD3, 0xFE, 
	0xB3, 0xD3, 0xFD, 
	0xB3, 0xB3, 0xFE, 
	0xB3, 0xB3, 0xFD, 
	0xB3, 0x73, 0xFF, 
	0xB3, 0xCB, 0xFE, 
	0xB3, 0xAB, 0xFE, 
	0xB3, 0xCB, 0xFD, 
	0xB3, 0xAB, 0xFD, 
	0xB3, 0x6B, 0xFF, 
	0x73, 0xD3, 0xFE, 
	0x73, 0xD3, 0xFD, 
	0x73, 0xB3, 0xFE, 
	0x73, 0xB3, 0xFD, 
	0x73, 0x73, 0xFF, 
	0x73, 0xCB, 0xFD, 
	0x73, 0xAB, 0xFD, 
	0x73, 0xCB, 0xFE, 
	0x73, 0xAB, 0xFE, 
	0x73, 0x6B, 0xFF, 
	0xF6, 0xF3, 0xFF, 
	0xF6, 0xEB, 0xFF, 
	0xEE, 0xFB, 0xFF, 
	0xDE, 0xFB, 0xFF, 
	0xF6, 0xF5, 0xFF, 
	0xF6, 0xED, 0xFF, 
	0xEE, 0xFD, 0xFF, 
	0xDE, 0xFD, 0xFF, 
	0xF3, 0xD2, 0xFE, 
	0xF3, 0xB2, 0xFE, 
	0xF3, 0xD2, 0xFD, 
	0xF3, 0xB2, 0xFD, 
	0xF3, 0x72, 0xFF, 
	0xF3, 0xCA, 0xFE, 
	0xF3, 0xAA, 0xFE, 
	0xF3, 0xCA, 0xFD, 
	0xF3, 0xAA, 0xFD, 
	0xF3, 0x6A, 0xFF, 
	0xFD, 
	0xDE, 
	0xEE, 
	0xF6, 
	0xBA, 
	0x7A, 
};

static const SM_StateType IVItargets[SM_IVI_TRANSFER_ACTION_NUMBER] =
{
	0, 3, 1, 0, 3, 1, 1, 
	0, 3, 1, 3, 3, 1, 1, 
	0, 3, 1, 0, 3, 1, 1, 
	0, 3, 1, 3, 3, 1, 1, 
	1, 1, 1, 3, 1, 1, 1, 
	1, 1, 1, 0, 1, 1, 1, 
	1, 2, 2, 0, 2, 1, 1, 
	1, 2, 2, 0, 2, 1, 6, 
	1, 2, 2, 0, 2, 5, 1, 
	1, 2, 2, 0, 2, 5, 6, 
	1, 2, 2, 0, 2, 2, 1, 
	1, 4, 2, 3, 4, 1, 1, 
	1, 4, 2, 3, 4, 5, 1, 
	1, 4, 2, 3, 4, 1, 6, 
	1, 4, 2, 3, 4, 5, 6, 
	1, 4, 2, 3, 4, 2, 1, 
	1, 1, 1, 3, 1, 1, 1, 
	1, 6, 1, 3, 1, 1, 6, 
	1, 5, 1, 3, 1, 5, 1, 
	1, 5, 1, 3, 1, 5, 6, 
	1, 1, 1, 3, 1, 2, 1, 
	1, 4, 4, 3, 4, 1, 6, 
	1, 4, 4, 3, 4, 5, 6, 
	1, 4, 4, 3, 4, 1, 1, 
	1, 4, 4, 3, 4, 5, 1, 
	1, 4, 4, 3, 4, 2, 1, 
	0, 1, 1, 0, 1, 1, 1, 
	0, 4, 1, 0, 4, 1, 1, 
	0, 1, 1, 0, 1, 1, 1, 
	0, 3, 1, 0, 3, 1, 1, 
	0, 1, 1, 3, 1, 1, 1, 
	0, 4, 1, 3, 4, 1, 1, 
	0, 1, 1, 3, 1, 1, 1, 
	0, 3, 1, 3, 3, 1, 1, 
	1, 1, 2, 0, 1, 1, 1, 
	1, 5, 2, 0, 1, 5, 1, 
	1, 6, 2, 0, 1, 1, 6, 
	1, 5, 2, 0, 1, 5, 6, 
	1, 1, 2, 0, 1, 2, 1, 
	1, 4, 1, 0, 4, 1, 1, 
	1, 4, 1, 0, 4, 5, 1, 
	1, 4, 1, 0, 4, 1, 6, 
	1, 4, 1, 0, 4, 5, 6, 
	1, 4, 1, 0, 4, 2, 1, 
	8, 8, 8, 8, 8, 
	10, 10, 10, 10, 10, 
	9, 9, 9, 10, 9, 
	9, 9, 9, 9, 9, 
	7, 7, 7, 7, 7, 
	11, 11, 11, 11, 11, 


};

static const SM_TransferElementConfigType IVItransferElementConfigs[SM_IVI_TRANSFER_ELEMENT_NUMBER] =
{
	{0, 3, 0, 7},
	{3, 6, 7, 14},
	{6, 9, 14, 21},
	{9, 12, 21, 28},
	{12, 15, 28, 35},
	{15, 18, 35, 42},
	{18, 21, 42, 49},
	{21, 24, 49, 56},
	{24, 27, 56, 63},
	{27, 30, 63, 70},
	{30, 33, 70, 77},
	{33, 36, 77, 84},
	{36, 39, 84, 91},
	{39, 42, 91, 98},
	{42, 45, 98, 105},
	{45, 48, 105, 112},
	{48, 51, 112, 119},
	{51, 54, 119, 126},
	{54, 57, 126, 133},
	{57, 60, 133, 140},
	{60, 63, 140, 147},
	{63, 66, 147, 154},
	{66, 69, 154, 161},
	{69, 72, 161, 168},
	{72, 75, 168, 175},
	{75, 78, 175, 182},
	{78, 81, 182, 189},
	{81, 84, 189, 196},
	{84, 87, 196, 203},
	{87, 90, 203, 210},
	{90, 93, 210, 217},
	{93, 96, 217, 224},
	{96, 99, 224, 231},
	{99, 102, 231, 238},
	{102, 105, 238, 245},
	{105, 108, 245, 252},
	{108, 111, 252, 259},
	{111, 114, 259, 266},
	{114, 117, 266, 273},
	{117, 120, 273, 280},
	{120, 123, 280, 287},
	{123, 126, 287, 294},
	{126, 129, 294, 301},
	{129, 132, 301, 308},
	{132, 133, 308, 313},
	{133, 134, 313, 318},
	{134, 135, 318, 323},
	{135, 136, 323, 328},
	{136, 137, 328, 333},
	{137, 138, 333, 338},


};

static const SM_TransferConditionConfigType IVItransferConditionConfigs[SM_IVI_TRANSFER_CONDITION_NUMBER] =
{
	{0, 0, 3},
	{1, 3, 6},
	{2, 6, 9},
	{3, 9, 11},
	{4, 11, 13},
	{5, 13, 16},
	{6, 16, 18},
	{7, 0, 2},
	{8, 2, 6},
	{9, 6, 8},


};

static const SM_StateConfigType IVIstateConfigs[SM_IVI_STATE_NUMBER] =
{
    {"IVI_OFF", 0xFF},
    {"IVI_STANDBY", 0xFF},
    {"IVI_ON", 0x01},
    {"IVI_ShutDown", 0xFF},
    {"IVI_Remote", 0xFF},
    {"IVI_DEMO", 0xFF},
    {"IVI_AwakeHold", 0xFF},
    {"IVION_Normal", 0xFF},
    {"IVION_PW_Err", 0xFF},
    {"IVION_PW_S1", 0xFF},
    {"IVION_PW_S2", 0xFF},
    {"IVION_Local", 0xFF},

};

static const SM_StateMachineConfigType IVIstateMachineConfigs[SM_IVI_STATE_MACHINE_NUMBER] =
{
    {(boolean)TRUE, 0, 7, 0, 7, 0, 44, 0, 3, 0, 0, 0},
    {(boolean)FALSE, 7, 12, 7, 10, 44, 50, 3, 4, 1, 1, 1},

};


static const SM_TransferConditionType IVItransferConditions[SM_IVI_TRANSFER_CONDITION_NUMBER] =
{  
    SM_ConditionIVI_NM_State,
    SM_ConditionIVI_Voltage_Sts,
    SM_ConditionIVI_Enter_Other_State,
    SM_ConditionIVI_Receive_SOC_Flg,
    SM_ConditionIVI_Enter_Remote,
    SM_ConditionIVI_Demo_Condition,
    SM_ConditionIVI_Enter_AwakeHold,
    SM_ConditionIVI_ONLvPwrSysErr,
    SM_ConditionIVI_ONStat_PwrSv_Lvl,
    SM_ConditionIVI_ONKL15,
};

static const SM_EntryCallbackType IVIentrys[SM_IVI_ENTRY_NUMBER] =
{
    SM_EntryCallbackIVI,
    SM_EntryCallbackIVI_ON,
};

static const SM_TransferCallbackType IVItransfers[SM_IVI_TRANSFER_NUMBER] =
{
    SM_TransferCallbackIVI,
    SM_TransferCallbackIVI_ON,
};

static const SM_StayCallbackType IVIstays[SM_IVI_STAY_NUMBER] =
{
    SM_StayCallbackIVI,
    SM_StayCallbackIVI_ON,
};

static const SM_ConfigType sm_IVI_config =
{
    SM_IVI_STATE_MACHINE_NUMBER,
    IVIstateMachineConfigs,
    IVIstateMachineDatas,
    SM_IVI_TRANSFER_ELEMENT_NUMBER,
    IVItransferElementConfigs,
    SM_IVI_TRANSFER_CONDITION_NUMBER,
    IVItransferConditionConfigs,
    SM_IVI_TRANSFER_ACTION_NUMBER,
    IVItargets,
    SM_IVI_FEATURE_CONFIG_VALUE_NUMBER,
    IVIfeatureConfigValues,
    SM_IVI_FEATURE_VALUE_NUMBER,
    IVIfeatureValues,
    SM_IVI_STATE_NUMBER,
    IVIstateConfigs,
    SM_IVI_TRANSFER_CONDITION_NUMBER,
    IVItransferConditions,
    SM_IVI_ENTRY_NUMBER,
    IVIentrys,
    SM_IVI_TRANSFER_NUMBER,
    IVItransfers,
    SM_IVI_STAY_NUMBER,
    IVIstays
};

#define POWER_STOP_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h"



#define POWER_START_SEC_CODE 
#include "Power_MemMap.h"


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SM_EntryCallbackIVI(void)
{
    SM_StateCurrentSet(&Sm_IVI,SYSTEMSTATE_IVI_OFF);
    //power_info("State machine IVI entry\r\n");
    SystemState_IVI_PA.State = SYSTEMSTATE_IVI_OFF;
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SM_TransferCallbackIVI(SM_StateType previous, SM_StateType next)
{
    const char *previousName;
    const char *nextName;
    
    if (SYSTEMSTATE_IVI_SHUTDOWN == next)
    {
        if(0u != SystemState_IVIResponseTimer)
        {
            power_err("SystemState_IVIResponseTimer not clear");
        }
        SystemState_IVIResponseTimer++;
        SystemState_IVINM20STimer = 0u;
    }
    else if ((SYSTEMSTATE_IVI_STANDBY == previous) && (SYSTEMSTATE_IVI_ON == next))
    {
        ComM_RequestComMode(0, 2);
        power_warn("Power request NM");
    }
    else if ((SYSTEMSTATE_IVI_STANDBY == previous) && (SYSTEMSTATE_IVI_DEMO == next))
    {
        ComM_RequestComMode(0, 2);
        power_warn("Power request NM");
    }
    else if ((SYSTEMSTATE_IVI_STANDBY == previous) && (SYSTEMSTATE_IVI_AWAKEHOLD == next))
    {
        ComM_RequestComMode(0, 2);
        power_warn("Power request NM");
    }
    else if ((SYSTEMSTATE_IVI_ON == previous) && (SYSTEMSTATE_IVI_STANDBY == next))
    {                      
        ComM_RequestComMode(0, 0);
        power_warn("Power Release request NM");
        SystemState_KL15Off10MinTimer = 0u;
    }
    else if ((SYSTEMSTATE_IVI_DEMO == previous) && (SYSTEMSTATE_IVI_STANDBY == next))
    {
        ComM_RequestComMode(0, 0);
        power_warn("Power release request NM");
    }
    else if ((SYSTEMSTATE_IVI_AWAKEHOLD == previous) && (SYSTEMSTATE_IVI_STANDBY == next))
    {
        ComM_RequestComMode(0, 0);
        power_warn("Power release request NM");
    }

#if 0
    if(SYSTEMSTATE_IVI_REMOTE == previous)
    {
        RemoteFlag = 0u;
    }
#endif   
    if(SYSTEMSTATE_IVI_REMOTE != next) 
    {
        FOTAFlag = 0u;
    }

    if(SYSTEMSTATE_IVI_REMOTE == next)
    {
        if(1 == FOTAFlag)
        {
            ComM_RequestComMode(0, 2);
            power_warn("IVI->Remote&FOTAFlag:1,req NM");
        }
        else
        {
            ComM_RequestComMode(0, 0);/*release network*/
        }
    }
    
    SystemState_IVI_PA.State = next;

    (void)SM_StateNameGet(&Sm_IVI, previous, &previousName);
    (void)SM_StateNameGet(&Sm_IVI, next, &nextName);
    
    POWER_GET_OSTiCK(&TimerFlg);
    power_warn("SM %s->%s",previousName, nextName);
    power_warn("IVI trans reasonID:%d",IVIstateMachineDatas[0].transferElement);
}




/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SM_StayCallbackIVI(SM_StateType state)
{
    if(LOGTIMERTIMEOUT == PowerLogStsFunc(TIMER1S))
    {
        const char *Name;
        (void)SM_StateNameGet(&Sm_IVI, state, &Name);
        power_verbose("IVI SM Stay in %s",Name);
    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SM_EntryCallbackIVI_ON(void)
{
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();

    if(KL15ON == IVIInterKL15Sts)  
    {
        SystemState_IVI_PA.State = SYSTEMSTATE_IVI_ON_NORMAL;
    }
    else
    {
        SystemState_IVI_PA.State = SYSTEMSTATE_IVI_ON_LOCAL;
    }
    if(SYSTEMSTATE_LVPWRSYSERR_TRIGGER == Systemstate_Condition_element_local.LvPwrSysErr_e)
	{
        SystemState_IVI_PA.State = SYSTEMSTATE_IVI_ON_POWER_ERROR;
	}
    else if((SYSTEMSTATE_START_PWRSV_LV1_ONE == Systemstate_Condition_element_local.Stat_PwrSv_Lvl_e)\
    ||(SYSTEMSTATE_START_PWRSV_LV1_TWO == Systemstate_Condition_element_local.Stat_PwrSv_Lvl_e))
	{
        SystemState_IVI_PA.State = SYSTEMSTATE_IVI_ON_POWER_SAVE_1;
	}
	else if(SYSTEMSTATE_START_PWRSV_LV1_TWO_180S == Systemstate_Condition_element_local.Stat_PwrSv_Lvl_e)
	{
        SystemState_IVI_PA.State = SYSTEMSTATE_IVI_ON_POWER_SAVE_2;
	}
	else
	{
		/*do nothing*/
	}
	
	power_warn("entry IVI_ON %s \r\n",IVIstateConfigs[SystemState_IVI_PA.State]);
	SM_StateCurrentSet(&Sm_IVI,SystemState_IVI_PA.State);

}




/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SM_TransferCallbackIVI_ON(SM_StateType previous, SM_StateType next)

{
    const char *    previousName;
    const char *    nextName;
    if (KL15OFF == IVIInterKL15Sts)
    {
        if (0u == SystemState_KL15Off10MinTimer)
        {
            SystemState_KL15Off10MinTimer++;
        }
    }
    else if (KL15ON == IVIInterKL15Sts)
    {
        SystemState_KL15Off10MinTimer = 0u;
    }

    SystemState_IVI_PA.State = next;

    
    (void)SM_StateNameGet(&Sm_IVI, previous, &previousName);
    (void)SM_StateNameGet(&Sm_IVI, next, &nextName);
    
    POWER_GET_OSTiCK(&TimerFlg);
    power_warn("SM %s->%s", previousName, nextName);
    power_warn("IVI_ON trans reasonID:%d",IVIstateMachineDatas[1].transferElement);
}




/***********************************************************************
 * @brief       : IVI_PretimeoutFlag 1£º9min49.5s timeout event
 *				  IVI_sendsts:0:IPC_ERR_NONE.Send success 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SM_StayCallbackIVI_ON(SM_StateType state)
{
	uint8 IVI_PretimeoutFlag[2] ={APP_INFOSM_LOCAL_STS,LOCAL_PRETIMEOUT_FLAG};
	int32_t IVI_sendsts = 0u;
	static uint8 IVI_Localtimersendflag = IVI_NOSEND;
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();

    if (KL15OFF == IVIInterKL15Sts)
    {
        if(SYSTEMSTATE_SHORTTIME_OPEN == Systemstate_Condition_element_local.ShortTime)
        {
            SystemState_KL15Off10MinTimer = 0u;
        }
        else if (0u == SystemState_KL15Off10MinTimer)
        {
            SystemState_KL15Off10MinTimer++;
        }
        else if(SYSTEMSTATE_LOCAL_CONTINUE == SYSIVIlocal_timersts)
        {
			SystemState_KL15Off10MinTimer = 0u;
			SYSIVIlocal_timersts = SYSTEMSTATE_LOCAL_NO_REC;
        }
        else if(SYSTEMSTATE_LOCAL_END == SYSIVIlocal_timersts)
        {
			SystemState_KL15Off10MinTimer = SYSTEMSTATE_KL15_10MIN;
			SYSIVIlocal_timersts = SYSTEMSTATE_LOCAL_NO_REC;
        }
        else
        {
			/*do nothing*/
        }
    }
    else if (KL15ON == IVIInterKL15Sts)
    {
        SystemState_KL15Off10MinTimer = 0u;
    }
    if(SYSTEMSTATE_KL15_PRETIMEOUT == SystemState_KL15Off10MinTimer)
    {
    	power_warn("local send 9min50s flag");
    	IVI_Localtimersendflag = IVI_SENDING;
    }
    if(IVI_SENDING == IVI_Localtimersendflag)
    {		
		IVI_sendsts = IPC_M2S_POWERPowerInfoAPP_INFOMS_Transmit((IPC_M2S_POWERPowerInfoAPP_INFOMS_t*)&IVI_PretimeoutFlag);
		if(0u == IVI_sendsts)
		{
			IVI_Localtimersendflag  = IVI_NOSEND;
		}
    }
    if(LOGTIMERTIMEOUT == PowerLogStsFunc(TIMER2S))
    {
        const char *Name;
        (void)SM_StateNameGet(&Sm_IVI, state, &Name);
        power_verbose("IVI_ON SM Stay in %s",Name);
    }
}




/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
                0:NoCOMLess20S
                1:NOCOMMore20S
                2:Full Communication
***********************************************************************/
static uint8 SM_ConditionIVI_NM_State(void)
{
    uint8 ret = 1u;

    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();

    if(SYSTEMSTATE_NMNOCOMMUNICATION == Systemstate_Condition_element_local.NMState)
    {
        if(SystemState_IVINM20STimer < SYSTEMSTATE_IVINM_20S)
        {   
            SystemState_IVINM20STimer ++;
        }

        if(SYSTEMSTATE_IVINM_20S == SystemState_IVINM20STimer)
        {
            ret = 1u;
        }
        else
        {
            ret = 0u;
        }
    }
    else
    {
        SystemState_IVINM20STimer = 0u;
        ret = 2u;
    }
    return ret;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint8 SM_ConditionIVI_Voltage_Sts(void)
{
    
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();
    return Systemstate_Condition_element_local.Voltage_State;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
                0: Standby
                1: awakehold
 ***********************************************************************/
static uint8 SM_ConditionIVI_Enter_AwakeHold(void)
{
    static uint8 ret = AWAKEHOLD_TO_STANDBY;
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();

if((SYSTEMSTATE_DERVENABLE == Systemstate_Condition_element_local.DVRRequset)&&\
	(SYSTEMSTATE_ANTITHEFTSTSOPEN == Systemstate_Condition_element_local.AntitheftSts_e))
{
	ret = STANDBY_TO_AWAKEHOLD;
}
else 
{
	ret = AWAKEHOLD_TO_STANDBY;
}
	
return ret;
	
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
                0: IVI ON
                1: Standby
 ***********************************************************************/
static uint8 SM_ConditionIVI_Enter_Other_State(void)
{

    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();

        if (((SYSTEMSTATE_TRANP_MODE_OFF == Systemstate_Condition_element_local.TransPMode)&&\
        (((KL15ON == IVIInterKL15Sts) &&(REMOTE_TO_STANDBY == RemoteFlag)) ||\
        (SYSTEMSTATE_NFC_CONNECT == Systemstate_Condition_element_local.NFC_State)))||\
        (((SYSTEMSTATE_TRANP_MODE_ON == Systemstate_Condition_element_local.TransPMode)||\
        (SYSTEMSTATE_TRANP_MODE_ON_3S == Systemstate_Condition_element_local.TransPMode))&&\
        ( SYSTEMSTATE_EngineANDreadyON == Systemstate_Condition_element_local.engstsready_sts)))
	    {
	        return IVI_ENTER_IVI_ON;
	    }
    else if (((SYSTEMSTATE_SHORTTIME_CLOSE == Systemstate_Condition_element_local.ShortTime)&&\
        (KL15OFF == IVIInterKL15Sts) &&((SYSTEMSTATE_DRIVERDOOROPEN == Systemstate_Condition_element_local.DriverDoor) ||\
        (SYSTEMSTATE_ANTITHEFTSTSOPEN == Systemstate_Condition_element_local.AntitheftSts_e) ||\
        (SYSTEMSTATE_TIMEOUT == SystemState_KL15Off10MinTimerSts))) ||\
        ((SYSTEMSTATE_TRANP_MODE_ON_3S == Systemstate_Condition_element_local.TransPMode)&&\
        (SYSTEMSTATE_EngineANDreadyOFF == Systemstate_Condition_element_local.engstsready_sts)) ||\
        (STANDBY_TO_REMOTE == RemoteFlag))
    {
        return IVI_ENTER_STANDBY; 
    }
    else 
    {
        return IVI_UN_ENTER;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
                0: DEMO_TO_STANDBYON 
                1: STANDBY_TO_DEMO 
                2: DEMO_TO_IVION 
 ***********************************************************************/
static uint8 SM_ConditionIVI_Demo_Condition(void)
{
    static uint8 ret = DEMO_TO_STANDBY;
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();
    s_Systemstate_IVI_PA_t IVI_State = SystemState_IVISts();
    boolean SeekDwnAndPageLPress = SEEKDWNANDPAGEL_RELEASE;
    static uint8 KeyStateMemory = SEEKDWNANDPAGEL_RELEASE;
    Rte_Read_SeekDwnAndPageLPress_Timeout_Element(&SeekDwnAndPageLPress);

    if(((KeyStateMemory != SeekDwnAndPageLPress)&&\
    (SYSTEMSTATE_IVI_DEMO == IVI_State.State)&&\
    (SEEKDWNANDPAGEL_PRESS == SeekDwnAndPageLPress))||\
    (SYSTEMSTATE_ANTITHEFTSTSOPEN == Systemstate_Condition_element_local.AntitheftSts_e))
    {
      ret= DEMO_TO_STANDBY;
    }
    else if ((KeyStateMemory != SeekDwnAndPageLPress)&&\
    (SEEKDWNANDPAGEL_PRESS == SeekDwnAndPageLPress)&&\
    (SYSTEMSTATE_IVI_STANDBY == IVI_State.State)&&\
    (SYSTEMSTATE_TRANP_MODE_OFF == Systemstate_Condition_element_local.TransPMode)&&\
    (SYSTEMSTATE_ANTITHEFTSTSCLOSE == Systemstate_Condition_element_local.AntitheftSts_e))
    {
      ret= STANDBY_TO_DEMO;
    }
    else if((SYSTEMSTATE_IVI_DEMO == IVI_State.State)&&\
    ((KL15ON == IVIInterKL15Sts)||\
    (SYSTEMSTATE_NFC_CONNECT == Systemstate_Condition_element_local.NFC_State)||\
    (SYSTEMSTATE_START_PWRSV_LV1_ZERO != Systemstate_Condition_element_local.Stat_PwrSv_Lvl_e)))
    {
    ret = DEMO_TO_IVION;
    }
    else
    {
      /*do nothing*/
    }

    KeyStateMemory = SeekDwnAndPageLPress;
    return ret;
}


/***********************************************************************
 * @brief       : timeout or receive ipc response
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint8 SM_ConditionIVI_Receive_SOC_Flg(void)
{
    #if 0
    uint8 SystemState_IVINoForceResponse = Power_IVIResponse();
    Systemstate_Condition_element_t Systemstate_Condition_element = Systemstate_Condition_elementFunc();
    if((SYSTEMSTATE_TIMEOUT == SystemState_IVIResponseTimerSts)||\
        (1u == SystemState_IVINoForceResponse))
    {
        SystemState_IVIResponseTimer = 0u;
        if(SYSTEMSTATE_TIMEOUT == SystemState_IVIResponseTimerSts)
        {
            power_info("IVI ShutDown request more than %d ms, so Force OFF",5 * SYSTEMSTATE_IVIRESPONSETIMEOUT);
        }

        if(1u == SystemState_IVINoForceResponse)
        {
            power_info("Power receive IVI ShutDown Response, so Change IVI State from ShutDown to OFF");
        }
        
        return 1u;
    }
    else 
    {
        return 0u;
    }
    #endif
    return 1u;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
                0: RemotetoStandby
                1: StandbytoRemote
                2: No_Change:no use, only return 1,0
 ***********************************************************************/
static uint8 SM_ConditionIVI_Enter_Remote(void) 
{
	return  RemoteFlag;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
                0: Zero
                1: One
 ***********************************************************************/
static uint8 SM_ConditionIVI_ONLvPwrSysErr(void)
{
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();
    return Systemstate_Condition_element_local.LvPwrSysErr_e;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
                0: Zero
                1: One
                2: Less than 180s
                3: >= 180s
 ***********************************************************************/
static uint8 SM_ConditionIVI_ONStat_PwrSv_Lvl(void)
{
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();
    return Systemstate_Condition_element_local.Stat_PwrSv_Lvl_e;
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
                0: KL15 ON
                1: KL15 OFF
 ***********************************************************************/
static uint8 SM_ConditionIVI_ONKL15(void)
{
    if(KL15ON == IVIInterKL15Sts)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SystemState_IVIInit(void)
{
    memset(IVIstateMachineDatas,0,sizeof(SM_StateMachineType)*SM_IVI_STATE_MACHINE_NUMBER);
    memset(IVIfeatureValues,0,SM_IVI_FEATURE_VALUE_NUMBER);
    SystemState_IVI_PA = IVI_PAInit;
    Sm_IVI = Sm_IVIInit;
    SystemState_KL15Off10MinTimer = 0u;
    SystemState_KL15Off10MinTimerSts = SYSTEMSTATE_TIMERNORMAL;
    SystemState_IVIResponseTimer = 0u;
//    SystemState_IVIResponseTimerSts = SYSTEMSTATE_TIMERNORMAL;
    SystemState_IVINM20STimer = 0u;
    FOTASts = FOTA_OFF;
    FOTATimer = 0u;
    IVIInterKL15Sts = KL15OFF;
    IVIInterKL15StsBackup = KL15OFF;
    RemoteModStsBackup = REMOTE_NORMALMODE;
    SystemState_RemoteMode_Counter = 0u;
    KL15ON_OnceFlag = FALSE;
    SM_Init(&Sm_IVI,&sm_IVI_config);
    SysPowerModBackup = 0;
    power_warn("RemoteFlag = %d", RemoteFlag);
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
s_Systemstate_IVI_PA_t SystemState_IVISts(void)
{
    return SystemState_IVI_PA;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SystemState_IVI_MainFunc(void)
{
//    SystemState_IVIResponseTimerSts = SystemState_TimerKernel(&SystemState_IVIResponseTimer,SYSTEMSTATE_IVIRESPONSETIMEOUT);
    SystemState_KL15Off10MinTimerSts = SystemState_TimerKernel(&SystemState_KL15Off10MinTimer,SYSTEMSTATE_KL15_10MIN);
    FOTATimerLogic();
    IVIInterKL15StsLogic();
    IVIInterRemoteStsLogic();
    SM_MainFunction(&Sm_IVI);
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SystemState_IVIEnableSet(boolean Enabled)
{
    SM_EnabledSet(&Sm_IVI, Enabled);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
extern void IVI_FOTASts(uint8 *FOTAReceive)
{
    if(0x1u == *FOTAReceive)
    {
        FOTASts = FOTA_ON;
        FOTATimer = 0u;
        FOTAFlag = 1u;
        FOTATimer ++;
        FOTASignalCtrl(FOTASIGNALDISABLE);
    }
    else if(0x0u == *FOTAReceive)
    {
        FOTASts = FOTA_OFF;
        FOTAFlag = 0u;
        FOTATimer = 0u;
        FOTASignalCtrl(FOTASIGNALENABLE);
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
uint8  Power_FotaSts_Get(void)
{
	return FOTASts;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void FOTATimerLogic(void)
{
    if(FOTATimer > 0u)
    {
        if(FOTA_ON == FOTASts)
        {
            FOTATimer ++;
            if(FOTATimer >= FOTA_TIMEOUT)
            {
                FOTASts = FOTA_OFF;
                FOTAFlag = 0u;
                FOTATimer = 0u;
                FOTASignalCtrl(FOTASIGNALENABLE);
            }
        }
        else
        {
            power_err("FOTA Timer Status timeout");
        }
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void IVIInterKL15StsLogic(void)
{
#ifdef DEV_DEBUG_ON
    IVIInterKL15Sts = KL15ON;
    KL15ON_OnceFlag = TRUE;
#else
    uint8 retSysPowerMod = RTE_E_NEVER_RECEIVED;
    uint8 SysPowerMod_local = 0u;
	uint8 retSysPowerModVld_local = RTE_E_NEVER_RECEIVED;
    uint8 SysPowerModVld = 0u;
    uint8 retVal =TRUE ;
	static uint8 IVIInterKL15StsCrank = 0u;
    IVIInterKL15StsBackup = IVIInterKL15StsCrank;//dont move 

#ifdef POWERUSERTE
    retSysPowerMod = Rte_Read_SysPowerMod_SysPowerMod(&SysPowerMod_local);
	retSysPowerModVld_local = Rte_Read_SysPowerModVld_SysPowerModVld(&SysPowerModVld);

#else
    retSysPowerMod = ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD, &SysPowerMod_local, 1);
	retSysPowerModVld_local = ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMODVLD, &SysPowerModVld, 1);
    retVal = Com_IsRxPduGrpActive(COMEX_PDU_RX_PEPS2);
#endif

    if ((FALSE == (SIGNAL_NORMAL(retSysPowerMod)))||(FALSE == retVal))
    {
        if((SYSTEMSTATE_IVI_REMOTE == SystemState_IVI_PA.State)\
       	 ||((VOLTAGE_OUT_NORMAL!= Power_OutDataCurrent.state)&&(STANDBY_TO_REMOTE == RemoteFlag)))
		{
			SysPowerMod_local = SysPowerModBackup;
		}
		else 
		{
			SysPowerMod_local = 0u;
		}
        //power_info("Signal SysPowerMod abnormal, return data is %d",retSysPowerMod);
    }
	
    if ((FALSE == SIGNAL_NORMAL(retSysPowerModVld_local)))
    {
        if((SYSTEMSTATE_IVI_REMOTE == SystemState_IVI_PA.State)\
       	 ||((VOLTAGE_OUT_NORMAL!= Power_OutDataCurrent.state)&&(STANDBY_TO_REMOTE == RemoteFlag)))
		{
			SysPowerModVld = SysPowerModVldBackup;
		}
		else 
		{
			SysPowerModVld = 0u;
		}
    }
    
    SysPowerModBackup = SysPowerMod_local;
    SysPowerModVldBackup = SysPowerModVld;
    if ((((1u == SysPowerMod_local) || (2u == SysPowerMod_local) || (3u == SysPowerMod_local))&&(1 == SysPowerModVld))|| (FOTA_ON == FOTASts))
    {
        IVIInterKL15Sts = KL15ON;
		IVIInterKL15StsCrank = SysPowerMod_local;
		if((((1u == SysPowerMod_local) || (2u == SysPowerMod_local))&&(1 == SysPowerModVld))|| (FOTA_ON == FOTASts))
		{
            KL15ON_OnceFlag = TRUE;
		}
    }
    else 
    {
        IVIInterKL15Sts = KL15OFF;
		IVIInterKL15StsCrank == 0u;
    }
    

#endif
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void IVIInterRemoteStsLogic(void)
{
    uint8 retRemoteModSts = RTE_E_NEVER_RECEIVED;
    uint8 SignalRemoteModSts = 0u;
    Systemstate_Condition_element_t Systemstate_Condition_element_local = Systemstate_Condition_elementFunc();

#ifdef POWERUSERTE
    retRemoteModSts = Rte_Read_RemoteModSts_RemoteModSts(&SignalRemoteModSts);
#else
    retRemoteModSts = ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REMOTEMODSTS, &SignalRemoteModSts, 1);
#endif

    if ((!SIGNAL_NORMAL(retRemoteModSts)))
    {
        if((SYSTEMSTATE_IVI_REMOTE == SystemState_IVI_PA.State)\
       	 ||((VOLTAGE_OUT_NORMAL!= Power_OutDataCurrent.state)&&(STANDBY_TO_REMOTE == RemoteFlag)))
        {
            SignalRemoteModSts = 0x01u;
        }
    }

    if(RemoteModStsBackup != SignalRemoteModSts)
    {
        if(REMOTE_REMOTEMODE == SignalRemoteModSts)/* normal to remote*/
        {
            power_warn("RemoteModSts normal->Remote");
        }
        if(REMOTE_NORMALMODE == SignalRemoteModSts)/* remote to normal*/
        {
            power_warn("RemoteModSts Remote->normal");
        }
    }

	/* Enter remote mode */
	if ((REMOTE_REMOTEMODE == SignalRemoteModSts) && (FALSE == KL15ON_OnceFlag)\
	&&(SYSTEMSTATE_NMFULLCOMMUNICATION == Systemstate_Condition_element_local.NMState))
	{
		RemoteFlag = STANDBY_TO_REMOTE;
		SystemState_RemoteMode_Counter = 0u;
	}
	else
	{
		if(RemoteModStsBackup != SignalRemoteModSts)
		{
			if(REMOTE_NORMALMODE == SignalRemoteModSts)
			{
				SystemState_RemoteMode_Counter = SYSTENSTATE_Timer_500MS;
			}
			else
			{
				SystemState_RemoteMode_Counter = 0u;
			}
		}
	 /* exit remote mode */
		if(SystemState_RemoteMode_Counter > 0u)
		{
			SystemState_RemoteMode_Counter --;
			
			if(SystemState_RemoteMode_Counter == 0u)
			{
				RemoteFlag = REMOTE_TO_STANDBY;
			}
		}

	}
	if((KL15OFF == IVIInterKL15Sts) && ((1 == IVIInterKL15StsBackup)||(2 == IVIInterKL15StsBackup)))    /*power mode don't exit remote mode when last kl15 state is crank.*/
	{
		RemoteFlag = REMOTE_TO_STANDBY;
		SystemState_RemoteMode_Counter = 0u;
	}
	
	RemoteModStsBackup = SignalRemoteModSts;

}
/***********************************************************************
 * @retval      : this api is for voltage abnormal sleep,
 				  than nm sleep ,clear remoteflag
 ***********************************************************************/
void PM_ClearRemoteflag(void)
{
	RemoteFlag = REMOTE_NORMALMODE;
}

/***********************************************************************
 * @retval      :Clear the KL15OnceFlg when power shutdown
 				  
 ***********************************************************************/
void PM_ClearKL5Onceflag(void)
{
	KL15ON_OnceFlag = FALSE;
}

/***********************************************************************
 * @brief       : FOTA ON some signal not transport
 * @param       : 
                0x0: FOTASIGNALENABLE
                0x1: FOTASIGNALDISABLE
 * @retval      : 
 ***********************************************************************/
static void FOTASignalCtrl(uint8 CtrlEnable)
{
    Com_IPduEnableHandle(CANIDCSA3,  (boolean)CtrlEnable);
    Com_IPduEnableHandle(CANIDBCM6,  (boolean)CtrlEnable);
    Com_IPduEnableHandle(CANIDBCM11, (boolean)CtrlEnable);
    Com_IPduEnableHandle(CANIDBCM10, (boolean)CtrlEnable);
    Com_IPduEnableHandle(CANIDBCM8,  (boolean)CtrlEnable);
    Com_IPduEnableHandle(CANIDSTBS1, (boolean)CtrlEnable);
    if(FOTASIGNALDISABLE == CtrlEnable)
    {
        power_debug("FOTA:on,disable Sig ");
    }
    else
    {
        power_debug("FOTA:off,Ensable Sig");
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void SystemState_APP_INFOSM(uint8 * param, uint16 param_len)
{
    IPC_S2M_POWERSystemStateAPP_INFOSM_t data ={0};
    IPC_S2M_POWERSystemStateAPP_INFOSM_t *VirtualEventcbk_Local;
    VirtualEventcbk_Local = Power_VirtualEventcbk_Get();
    IPC_S2M_POWERSystemStateAPP_INFOSM_Receive(param,&data,IPC_S2M_POWER_SYSTEMSTATE_MSGSUB_APP_INFOSM_LENGTH);
    power_warn("get APP type%d value%d ",data.type,data.value);
    if(APP_INFOSM_LOCAL_STS == data.type)
    {
    	SYSIVIlocal_timersts = (uint8)data.value;
    }
    else if(APP_INFOSM_NM == data.type)
    {
		PM_NMcbksts.type = data.type;
		PM_NMcbksts.value = data.value;
    }
    else if(APP_INFOSM_VIRTUALEVENT == data.type)
    {
		VirtualEventcbk_Local[data.value].type = data.type;
		VirtualEventcbk_Local[data.value].value = data.value;
    }
    else if(APP_INFOSM_AWAKEHOLDOUTFLG == data.type)
    {
        QNXReqExitAwakeHoldFlg.value = data.value;
        QNXReqExitAwakeHoldFlg.type = data.type;
    }	
    else
    {
		/*do nothing*/
    }
	
}
IPC_S2M_POWERSystemStateAPP_INFOSM_t Power_NMcbksts_Get(void)
{
	return PM_NMcbksts;
}

IPC_S2M_POWERSystemStateAPP_INFOSM_t Power_QNXReqFlg_Get(void)
{
	return QNXReqExitAwakeHoldFlg;
}

#define POWER_STOP_SEC_CODE 
#include "Power_MemMap.h"


