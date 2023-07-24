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
 * @file:      SystemState_Conditon_Element.h
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

#ifndef __SYSTEMSTATE_CONDITION_ELEMENT_H_
#define __SYSTEMSTATE_CONDITION_ELEMENT_H_

#include "Rte_Power_Type.h"
#include "Rte_Power.h"
#include "IPC_POWER.h"
#include "SystemState_IVI_Condition.h"


#define SYSTEMSTATE_KL15_OFF                (0u)
#define SYSTEMSTATE_KL15_ON                 (1u)


#define SYSTEMSTATE_SOCOFF_5S                   (1000u)/*1s*/

#define SYSTEMSTATE_TRANP_MODE_OFF              (0u)
#define SYSTEMSTATE_TRANP_MODE_ON               (1u)
#define SYSTEMSTATE_TRANP_MODE_ON_3S            (2u)


#define SYSTEMSTATE_NMNOCOMMUNICATION           (0u)
#define SYSTEMSTATE_NMFULLCOMMUNICATION         (1u)

#define SYSTEMSTATE_VOLNORMAL                   (0u)
#define SYSTEMSTATE_VOLALARM                    (1u)
#define SYSTEMSTATE_VOLSLEEP                    (2u)

#define SYSTEMSTATE_LVPWRSYSERR_UN_TRIGGER      (0u)
#define SYSTEMSTATE_LVPWRSYSERR_TRIGGER         (1u)

#define SYSTEMSTATE_START_PWRSV_LV1_ZERO        (0u)
#define SYSTEMSTATE_START_PWRSV_LV1_ONE         (1u)
#define SYSTEMSTATE_START_PWRSV_LV1_TWO         (2u)
#define SYSTEMSTATE_START_PWRSV_LV1_TWO_180S    (3u)

#define SYSTEMSTATE_NFC_UN_CONNECT              (0u)
#define SYSTEMSTATE_NFC_CONNECT                 (1u)

#define SYSTENSTATE_Timer_3S                    (600u)//3s
#define SYSTENSTATE_Timer_180S                  (36000u)//180s

#define SYSTEMSTATE_TRANP_MODE_OFF              (0u)
#define SYSTEMSTATE_TRANP_MODE_ON               (1u)

#define SYSTEMSTATE_DRIVERDOORCLOSE             (0u)
#define SYSTEMSTATE_DRIVERDOOROPEN              (1u)

#define SYSTEMSTATE_ANTITHEFTSTSCLOSE           (0u)
#define SYSTEMSTATE_ANTITHEFTSTSOPEN            (1u)


#define SYSTEMSTATE_TIMERNORMAL                 (0u)
#define SYSTEMSTATE_TIMEOUT                     (1u)

#define SYSTEMSTATE_HUD_OPEN                    (1u)
#define SYSTEMSTATE_HUD_CLOSE                   (0u)

#define SYSTEMSTATE_SHORTTIME_CLOSE             (0u)
#define SYSTEMSTATE_SHORTTIME_OPEN              (1u)

#define SYSTEMSTATE_DERV                        (0x00)
#define SYSTEMSTATE_GASOLINE                    (0x01)
#define SYSTEMSTATE_CNGANDGASOLINE              (0x02)
#define SYSTEMSTATE_CNG                         (0x07)

#define SYSTEMSTATE_DERVDISABLE                 (0)
#define SYSTEMSTATE_DERVENABLE                  (1)


#define SYSTEMSTATE_IVIRESPONSETIMEOUT          (1000)/*5s*/

#define SYSTEMSTATE_QNXCLOSETIMEOUT             (3000)/*15s, 20210322 change to 15s, xinchongyang asked*/
#define SYSTEMSTATE_CLUSTERRESPONSETIMEOUT      (600)/*3s*/
#define SYSTEMSTATE_IPCOFFMEOUT                 (200)/*1s*/
#define POWER_CDDCLOSETIMEOUT                   (200)/*1s*/
#define SYSTEMSTATE_IPCREADY                    (1u)
#define SYSTEMSTATE_IPCNOREADY                  (0u)

#define LOGTIMERINIT                            (0u)
#define LOGTIMERRUN                             (1u)
#define LOGTIMERTIMEOUT                         (2u)

#define DVRNOREQUEST                            (0u)
#define DVRSOCREQCONNECT                        (1u)
#define DVRTBOXREQENABLE                        (2u)


#define SYSTEMSTATE_EngineANDreadyON                    (1u)
#define SYSTEMSTATE_EngineANDreadyOFF                   (0u)
#define ENGSTATE_CFG                            (0u)
#define HCU_RDYLEMSts_CFG                       (1u)
#define VCU_READYLEDSts_CFG                     (2u)
#define VEHICLE_CFG_NUM                         (15u)
#define PICK                            		(1u)
#define NOT_PICK                       			(0u)

#define APP_INFOMSTYPE_AVRACK                   (4u)
#define DVRHEARTBEAT_TIMEOUT10MIN               (600000u)
#define DVRHEARTBEAT_TIMEOUT                    (0u)
#define DVRHEARTBEAT_NORMAL                     (1u)

#define NOREQUEST                               (0u)



#if (defined GWM_V35_PROJECT_TYPE_B03)
#define POWERUSERTE
#endif

#if (defined GWM_V35_PROJECT_TYPE_A08)
#define POWER_USE_ENGSTATE_271
#endif

#if((!defined GWM_V35_PROJECT_TYPE_ES13) && (!defined GWM_V35_PROJECT_TYPE_A08) && (!defined GWM_V35_PROJECT_TYPE_EC24) && (!defined GWM_V35_PROJECT_TYPE_ES24))
#define POWER_USE_ENGSTATE
#endif
#if ((!defined GWM_V35_PROJECT_TYPE_A08) && (!defined GWM_V35_PROJECT_TYPE_B16) && (!defined GWM_V35_PROJECT_TYPE_ES13) && (!defined GWM_V35_PROJECT_TYPE_EC24) && (!defined GWM_V35_PROJECT_TYPE_ES24)&& (!defined GWM_V35_PROJECT_TYPE_A07))
#define POWER_USE_HCU_RDY
#endif
#if ((!defined GWM_V35_PROJECT_TYPE_A08) && (!defined GWM_V35_PROJECT_TYPE_B16) && (!defined GWM_V35_PROJECT_TYPE_ES13)&&(!defined GWM_V35_PROJECT_TYPE_D01)&&(!defined GWM_V35_PROJECT_TYPE_D02)&&(!defined GWM_V35_PROJECT_TYPE_D03)&&(!defined GWM_V35_PROJECT_TYPE_ES24)&&(!defined GWM_V35_PROJECT_TYPE_P01))
#define POWER_USE_HUD_SWTSTS
#endif
#if ((defined GWM_V35_PROJECT_TYPE_ES13) || (defined GWM_V35_PROJECT_TYPE_EC24) || (defined GWM_V35_PROJECT_TYPE_ES24))
#define POWER_USE_EV
#endif

#if ((defined GWM_V35_PROJECT_TYPE_ES13) || (defined GWM_V35_PROJECT_TYPE_EC24))
#define POWER_USE_ES13_SHORT_TIME
#endif



#ifndef POWERUSERTE
#define SIGNAL_NORMAL(X)    ((X == COMEX_UPDATE_RECEIVED)||(X == E_OK))
#else
#define SIGNAL_NORMAL(X)    (((X & RTE_E_MAX_AGE_EXCEEDED) != RTE_E_MAX_AGE_EXCEEDED) && ((X & RTE_E_NEVER_RECEIVED) != RTE_E_NEVER_RECEIVED) && ((X & RTE_E_COM_STOPPED) != RTE_E_COM_STOPPED))
#endif




#define POWER_GET_OSTiCK(X)                     TM_Timer1msStartStamp(X) 
extern FUNC(void, TM_CODE)TM_Timer1msStartStamp(P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) StartStamp);



typedef uint8 SystemState_QnxCloseRequest_t;

typedef struct
{
    uint8 State;
}SystemState_KL15_PA_t;

typedef struct 
{
    uint8 KL15;
    uint8 NMState;
    uint8 TransPMode;
    uint8 LvPwrSysErr_e;
    uint8 HUD_State;
    uint8 Voltage_State;
    uint8 NFC_State;
    uint8 Stat_PwrSv_Lvl_e;
    uint8 DriverDoor;
    uint8 AntitheftSts_e;
    uint8 IPCSts;
	uint8 engstsready_sts;
	boolean ShortTime;
	boolean DVRRequset;
} Systemstate_Condition_element_t;

typedef struct
{
	uint8 fuel_cfg_byte;
	uint8 motorposi_cfg_byte;
	uint8 vehicle_type;
}SystemState_Cfg_Posi;

#define LOGTIMERTABLE\
    X_MACRO_LOTTIMER(TIMER100MS,20)\
    X_MACRO_LOTTIMER(TIMER200MS,40)\
    X_MACRO_LOTTIMER(TIMER500MS,100)\
    X_MACRO_LOTTIMER(TIMER1S,   200)\
    X_MACRO_LOTTIMER(TIMER2S,   400)\
    X_MACRO_LOTTIMER(TIMER5S,   1000)\
    X_MACRO_LOTTIMER(TIMER10S,  2000)\




typedef enum
{
#define X_MACRO_LOTTIMER(a,b) a,
    LOGTIMERTABLE
#undef X_MACRO_LOTTIMER
    TimerNum
}e_TimerEnum_t;







#define POWER_START_SEC_CODE
#include "Power_MemMap.h"


extern void SystemState_ElementInit(void);
extern void SystemState_ElementFunc(void);
extern SystemState_KL15_PA_t SystemState_KLSts(void);
extern Systemstate_Condition_element_t Systemstate_Condition_elementFunc(void);
extern uint8 SystemState_TimerKernel(uint32 *timer, uint32 timeout);
extern uint8 PowerLogStsFunc(e_TimerEnum_t cfg);



#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"





#endif

