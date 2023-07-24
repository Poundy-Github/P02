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
 * @file:      Power_Volt_Monitor.c
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

#include "IoHwAb.h"
#include "IoHwAb_Cfg_RI.h"
#include "Power_Volt_Monitor.h"
#include "Icu.h"
#include "string.h"
#include "StateMachine.h"
#include "logger_cfg.h"
#include "logger.h"
#include "Rtm.h"
#include "SystemState_Conditon_Element.h"
#include "CanIf.h"
#include "CanSM.h"

#define POWER_BATT_DIV                          (1090u)
#define POWER_BATT_V_BJT                        (2u)


#define MAX_VOLTAGE_RESOLUTION                  (5000000 / POWER_BATT_DIV)
#define POWER_BATT_ADC                          (4095)
#define T3                                      (0u)
#define T4                                      (1u)
#define T5                                      (2u)
#define T6                                      (3u)/*>24v*/
#define T7                                      (4u)
#define T_Num                                   (5u)
#define SM_DEV_ERROR_DETECT                     (STD_ON)
#define SM_STATEMACHINE_INVALID                 (0xFFu)
#define SM_STATE_ORIGIN                         (0xFFu)
#define SM_VOLTAGE_STATE_MACHINE_NUMBER         (3u)
#define SM_VOLTAGE_TRANSFER_CONDITION_NUMBER    (7u)
#define SM_VOLTAGE_TRANSFER_ELEMENT_NUMBER      (14u)
#define SM_VOLTAGE_TRANSFER_ACTION_NUMBER       (39u)
#define SM_VOLTAGE_FEATURE_CONFIG_VALUE_NUMBER  (14u)
#define SM_VOLTAGE_FEATURE_VALUE_NUMBER         (3u)
#define SM_VOLTAGE_ENTRY_NUMBER                 SM_VOLTAGE_STATE_MACHINE_NUMBER
#define SM_VOLTAGE_TRANSFER_NUMBER              SM_VOLTAGE_STATE_MACHINE_NUMBER
#define SM_VOLTAGE_STAY_NUMBER                  SM_VOLTAGE_STATE_MACHINE_NUMBER
#define T7THRESHOD                              (500u)/*5v*/
#define T6THRESHOD                              (2400u)/*24v*/
#define VOLTAGE20S                              (4000u)/*20s*/
#define VOLTAGE23S                              (4600u)/*23s*/
#define VOLTAGE3S                               (600u)/*3s*/
#define SM_VOLTAGE_STATE_NORMAL                 (0u)
#define SM_VOLTAGE_STATE_HIGH                   (1u)
#define SM_VOLTAGE_STATE_LOW                    (2u)
#define SM_VOLTAGE_HIGH_NORMAL                  (3u)
#define SM_VOLTAGE_HIGH_ALARM                   (4u)
#define SM_VOLTAGE_HIGH_SLEEP                   (5u)
#define SM_VOLTAGE_LOW_NORMAL                   (6u)
#define SM_VOLTAGE_LOW_SLEEP                    (7u)
#define SM_VOLTAGE_STATE_NUMBER                 (8u)
#define VOLTAGE_MAXVOLTAGE                      (6000u)
#define VOLTAGE_CHANGE_THRESHOLD                (5u)

#define DTCREPORTNONE                           (2u)
#define DTCREPORTPASSED                         (0u)
#define DTCREPORTFAILED                         (1u)

#define DTCVOLTAGEHIGH                          (0u)
#define DTCVOLTAGELOW                           (1u)
#define DTCVOLTAGENUM                           (2u)

typedef struct Pw_EventDebounce{
    uint16 monitorCounter;
    uint16 failedCounter;
    uint16 passedCounter;
}s_Pw_EventDebounce_t;

typedef struct Pw_EventDebounceCfg {
    uint16 FailThreshold;
    uint16 PassThreshold;
}s_Pw_EventDebounceCfg_t;

typedef struct{
    uint8 *eventStatus;                                          /* DTC ID*/
    const s_Pw_EventDebounceCfg_t *Pw_EventDebounceCfg_Data;               /* DTC PASSED or FAILED Config Time*/
    s_Pw_EventDebounce_t *Pw_EventDebounce_Data;                           /* DTC Monotor Time */
}s_Pw_EventDTC_t;

typedef struct
{
    uint8 ReportActive;
    uint8 DTCSts;
}s_DTCResult_t;


#define POWER_START_SEC_CODE
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static void SM_EntryCallbackVoltage(void);
static void SM_EntryCallbackHighM(void);
static void SM_EntryCallbackLowM(void);
static void SM_TransferCallbackVoltage(SM_StateType previous, SM_StateType next);
static void SM_TransferCallbackHighM(SM_StateType previous, SM_StateType next);
static void SM_TransferCallbackLowM(SM_StateType previous, SM_StateType next);
static void SM_StayCallbackVoltage(SM_StateType state);
static void SM_StayCallbackHighM(SM_StateType state);
static void SM_StayCallbackLowM(SM_StateType state);
static uint8 SM_ConditionVoltageT3(void);
static uint8 SM_ConditionVoltageT5(void);
static uint8 SM_ConditionHighMT3(void);
static uint8 SM_ConditionHighMT4(void);
static uint8 SM_ConditionHighMT6(void);
static uint8 SM_ConditionLowMT5(void);
static uint8 SM_ConditionLowMT7(void);
static void Power_VoltageStateUpdate(void);
static boolean Power_Volt_Calculate(void);
static void Power_Volt_Timer_Sts_Loigc(void);
static void VoltageHighDTC(void);
static void VoltageLowDTC(void);
static void VoltageDTCLogic(void);
static uint8 DTCReportDebounce(uint8 errorStatus,uint8 DTCID, const s_Pw_EventDTC_t *EventDTC);
#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define POWER_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

static uint16 Vol_Timer[T_Num];
static uint8 VoltagefeatureValues[SM_VOLTAGE_FEATURE_VALUE_NUMBER];
static SM_StateMachineType VoltagestateMachineDatas[SM_VOLTAGE_STATE_MACHINE_NUMBER];
static SM_Type Sm_Voltage;
static uint8 VoltageStateCurrent;
static s_PowerOut_t Power_OutDataBackup;
s_PowerOut_t Power_OutDataCurrent = {SM_VOLTAGE_STATE_NORMAL,0u};
uint8  Power_EolSleepflag = FALSE;



static uint32 AD_data;
static boolean VoltageInitFlg;
static boolean DTCHighVoltage;
static boolean DTCLowVoltage;
static uint32 TimerFlg;

static uint8 DTCEventSts[DTCVOLTAGENUM] = {0u}; 
static s_Pw_EventDebounce_t Pw_EventDebounce_d[DTCVOLTAGENUM] = {0u};
static s_DTCResult_t     DTCResultData[DTCVOLTAGENUM];
static boolean VoltageInitFlg;
static uint32 Pw_dtcclrreq;

#define POWER_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define POWER_START_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static const SM_Type Sm_VoltageInit = {(SM_StateMachineIdType)SM_STATEMACHINE_INVALID, (SM_SequenceType)SM_SEQUENCE_IDLE,\
										(boolean)FALSE, (boolean)FALSE, (boolean)FALSE, (SM_ConfigType*) NULL_PTR};
static const s_PowerOut_t Power_OutInit = {SM_VOLTAGE_STATE_NORMAL,0u};

static const uint8 VoltagefeatureConfigValues[SM_VOLTAGE_FEATURE_CONFIG_VALUE_NUMBER] =
{
    0xFA,
    0xFD,
    0xF6,
    0x7F,
    0x9F,
    0xAB,
    0xB3,
    0xAD,
    0xAE,
    0xB5,
    0xB6,
    0xF7,
    0xF9,
    0xFA,
};

static const SM_StateType Voltagetargets[SM_VOLTAGE_TRANSFER_ACTION_NUMBER] =
{
    0, 0, 0, 
    1, 1, 1, 
    2, 2, 2, 
    5, 5, 5, 
    5, 5, 5, 
    5, 5, 5, 
    5, 5, 5, 
    4, 4, 5, 
    4, 4, 5, 
    4, 4, 5, 
    3, 3, 5, 
    7, 7, 
    7, 7, 
    6, 7, 
};

static const SM_TransferElementConfigType VoltagetransferElementConfigs[SM_VOLTAGE_TRANSFER_ELEMENT_NUMBER] =
{
    {0, 1, 0, 3},
    {1, 2, 3, 6},
    {2, 3, 6, 9},
    {3, 4, 9, 12},
    {4, 5, 12, 15},
    {5, 6, 15, 18},
    {6, 7, 18, 21},
    {7, 8, 21, 24},
    {8, 9, 24, 27},
    {9, 10, 27, 30},
    {10, 11, 30, 33},
    {11, 12, 33, 35},
    {12, 13, 35, 37},
    {13, 14, 37, 39},
};

static const SM_TransferConditionConfigType VoltagetransferConditionConfigs[SM_VOLTAGE_TRANSFER_CONDITION_NUMBER] =
{
    {0, 0, 2},
    {1, 2, 4},
    {2, 0, 3},
    {3, 3, 6},
    {4, 6, 8},
    {5, 0, 2},
    {6, 2, 4},
};

static const SM_StateConfigType VoltagestateConfigs[SM_VOLTAGE_STATE_NUMBER] =
{
    {"VOLT Normal", 0xFF},
    {"VOLT High", 0x01},
    {"VOLT Low", 0x02},
    {"HIGH Normal", 0xFF},
    {"HIGH Alarm", 0xFF},
    {"HIGH Sleep", 0xFF},
    {"LOW Normal", 0xFF},
    {"LOW Sleep", 0xFF},
};

static const SM_StateMachineConfigType VoltagestateMachineConfigs[SM_VOLTAGE_STATE_MACHINE_NUMBER] =
{
    {(boolean)TRUE, 0, 3, 0, 2, 0, 3, 0, 1, 0, 0, 0},
    {(boolean)FALSE, 3, 6, 2, 5, 3, 11, 1, 2, 1, 1, 1},
    {(boolean)FALSE, 6, 8, 5, 7, 11, 14, 2, 3, 2, 2, 2},
};


static const SM_TransferConditionType VoltagetransferConditions[SM_VOLTAGE_TRANSFER_CONDITION_NUMBER] =
{
    SM_ConditionVoltageT3, 
    SM_ConditionVoltageT5, 
    SM_ConditionHighMT3, 
    SM_ConditionHighMT4, 
    SM_ConditionHighMT6, 
    SM_ConditionLowMT5, 
    SM_ConditionLowMT7, 
};


static const SM_EntryCallbackType Voltageentrys[SM_VOLTAGE_ENTRY_NUMBER] =
{
    SM_EntryCallbackVoltage, 
    SM_EntryCallbackHighM, 
    SM_EntryCallbackLowM, 
};


static const SM_TransferCallbackType Voltagetransfers[SM_VOLTAGE_TRANSFER_NUMBER] =
{
    SM_TransferCallbackVoltage, 
    SM_TransferCallbackHighM, 
    SM_TransferCallbackLowM, 
};


static const SM_StayCallbackType Voltagestays[SM_VOLTAGE_STAY_NUMBER] =
{
    SM_StayCallbackVoltage, 
    SM_StayCallbackHighM, 
    SM_StayCallbackLowM, 
};


static const SM_ConfigType sm_Voltage_config =
{
    SM_VOLTAGE_STATE_MACHINE_NUMBER, 
    VoltagestateMachineConfigs, 
    VoltagestateMachineDatas, 
    SM_VOLTAGE_TRANSFER_ELEMENT_NUMBER, 
    VoltagetransferElementConfigs, 
    SM_VOLTAGE_TRANSFER_CONDITION_NUMBER, 
    VoltagetransferConditionConfigs, 
    SM_VOLTAGE_TRANSFER_ACTION_NUMBER, 
    Voltagetargets, 
    SM_VOLTAGE_FEATURE_CONFIG_VALUE_NUMBER, 
    VoltagefeatureConfigValues, 
    SM_VOLTAGE_FEATURE_VALUE_NUMBER, 
    VoltagefeatureValues, 
    SM_VOLTAGE_STATE_NUMBER, 
    VoltagestateConfigs, 
    SM_VOLTAGE_TRANSFER_CONDITION_NUMBER, 
    VoltagetransferConditions, 
    SM_VOLTAGE_ENTRY_NUMBER, 
    Voltageentrys, 
    SM_VOLTAGE_TRANSFER_NUMBER, 
    Voltagetransfers, 
    SM_VOLTAGE_STAY_NUMBER, 
    Voltagestays
};


static const s_Pw_EventDebounceCfg_t Pw_EventDebounceCfg_Data[DTCVOLTAGENUM] = {
    {10000/5,1000/5},
    {10000/5,1000/5},
};

static const s_Pw_EventDTC_t Pw_EventDTCCfg = {
    DTCEventSts,
    Pw_EventDebounceCfg_Data,
    Pw_EventDebounce_d,
};

#define POWER_STOP_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



#define POWER_START_SEC_CODE
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SM_EntryCallbackVoltage(void)
{
    SM_StateCurrentSet(&Sm_Voltage, SM_VOLTAGE_STATE_NORMAL);
    //power_warn("SM Voltage entry SM_VOLTAGE_STATE_NORMAL!!");
    VoltageStateCurrent = SM_VOLTAGE_STATE_NORMAL;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SM_EntryCallbackHighM(void)
{
    SM_StateCurrentSet(&Sm_Voltage, SM_VOLTAGE_HIGH_NORMAL);
    //power_warn("SM Voltage entry SM_VOLTAGE_STATE_HIGH!!");
    VoltageStateCurrent = SM_VOLTAGE_HIGH_NORMAL;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SM_EntryCallbackLowM(void)
{
    SM_StateCurrentSet(&Sm_Voltage, SM_VOLTAGE_LOW_NORMAL);
    //power_warn("SM Voltage entry SM_VOLTAGE_STATE_LOW!!");
    VoltageStateCurrent = SM_VOLTAGE_LOW_NORMAL;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SM_TransferCallbackVoltage(SM_StateType previous, SM_StateType next)
{
    const char *previousName;
    const char *nextName;

    (void)SM_StateNameGet(&Sm_Voltage, previous, &previousName);
    (void)SM_StateNameGet(&Sm_Voltage, next, &nextName);
    
    POWER_GET_OSTiCK(&TimerFlg);
    power_warn("[%ld Ms]SM Voltage %s->%s\r\n", TimerFlg, previousName, nextName);
    
    if(TRUE == VoltageInitFlg)
    {
        power_warn("Power Voltage ADC:%d",AD_data);
        power_warn("Power Voltage value:%d/100V",Power_OutDataCurrent.value);
    }
    VoltageStateCurrent = next;

}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SM_TransferCallbackHighM(SM_StateType previous, SM_StateType next)
{
    const char *previousName;
    const char *nextName;

    (void)SM_StateNameGet(&Sm_Voltage, previous, &previousName);
    (void)SM_StateNameGet(&Sm_Voltage, next, &nextName);
    
    POWER_GET_OSTiCK(&TimerFlg);

    if(SM_VOLTAGE_HIGH_SLEEP == next)
	{
		(void)CanIf_SetPduMode( CanSM_GetControllerIdOfChannelConfig( 0x00 ), CANIF_SET_TX_OFFLINE );
		power_warn("high tx disable");
	}

    power_warn("[%ld Ms]SM VoltageHigh %s->%s\r\n", TimerFlg,previousName, nextName);
    power_warn("Power Voltage ADC:%d",AD_data);
    power_warn("Power Voltage value:%d/100V",Power_OutDataCurrent.value);

    VoltageStateCurrent = next;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void SM_TransferCallbackLowM(SM_StateType previous, SM_StateType next)
{
    const char *previousName;
    const char *nextName;

    (void)SM_StateNameGet(&Sm_Voltage, previous, &previousName);
    (void)SM_StateNameGet(&Sm_Voltage, next, &nextName);
    
    POWER_GET_OSTiCK(&TimerFlg);
    
    if(SM_VOLTAGE_LOW_SLEEP == next)
	{
		(void)CanIf_SetPduMode( CanSM_GetControllerIdOfChannelConfig( 0x00 ), CANIF_SET_TX_OFFLINE );
		power_warn("low tx disable");
	}

    power_warn("[%ld Ms]SM VoltageLow %s->%s\r\n", TimerFlg, previousName, nextName);
    power_warn("Power Voltage ADC:%d",AD_data);
    power_warn("Power Voltage value:%d/100V",Power_OutDataCurrent.value);

    VoltageStateCurrent = next;

}


static void SM_StayCallbackVoltage(SM_StateType state)
{
}


static void SM_StayCallbackHighM(SM_StateType state)
{
}



static void SM_StayCallbackLowM(SM_StateType state)
{
}




/*
    0: NO startup
    1: startup
*/
static uint8 SM_ConditionVoltageT3(void)
{
    uint8 ret = 0;

    if ((Vol_Timer[T3] > 0u) || (Vol_Timer[T4] > 0u) || (Vol_Timer[T6] > 0u))
    {
        ret = 1u;
    }

    return ret;
}


/*
    0: NO startup
    1: startup
*/
static uint8 SM_ConditionVoltageT5(void)
{
    uint8 ret = 0;

    if ((Vol_Timer[T5] > 0u) || (Vol_Timer[T7] > 0u))
    {
        ret = 1u;
    }

    return ret;
}


/*
    0: 0-20S
    1: 20-23S
    2: >23
*/
static uint8 SM_ConditionHighMT3(void)
{
    uint8 ret = 0;

    if (Vol_Timer[T3] > VOLTAGE23S)
    {
        ret = 2u;
    }
    else if (Vol_Timer[T3] > VOLTAGE20S)
    {
        ret = 1u;
    }
    else if (Vol_Timer[T3] > 0u)
    {
        ret = 0u;
    }
    return ret;
}


/*
    2: > 3s
    1: 0-3s
    0: 0
*/
static uint8 SM_ConditionHighMT4(void)
{
    uint8 ret = 0;

    if (Vol_Timer[T4] > VOLTAGE3S)
    {
        ret = 2u;
    }
    else if (Vol_Timer[T4] > 0u)
    {
        ret = 1u;
    }

    return ret;
}


/*add 10ms delay*/
static uint8 SM_ConditionHighMT6(void)
{
    uint8 ret = 0;
    /*add 10ms delay for EMC Test*/
    if (Vol_Timer[T6] > 2u) /*24v*/
    {
        ret = 1;
    }

    return ret;
}


/*
* @brief   :   Get T5 state
* @retval  :   0: (0,20s]
* @retval  :   1: >20s
*/
static uint8 SM_ConditionLowMT5(void)
{
    uint8 ret = 0;
    if (Vol_Timer[T5] > VOLTAGE20S)
    {
        ret = 1u;
    }

    return ret;
}


/*
* @brief   :   Get T7 state(less than 5v)
* @retval  :   0: no
* @retval  :   1: yes
*/
static uint8 SM_ConditionLowMT7(void)
{
    uint8 ret = 0u;

    if (Vol_Timer[T7] > 0u)
    {
        ret = 1;
    }

    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Power_Volt_Init(void)
{
    uint8 Index;
    VoltageInitFlg = FALSE;
    memset(&Vol_Timer[0], 0, sizeof(uint16) *T_Num);
    memset(VoltagefeatureValues,0,SM_VOLTAGE_FEATURE_VALUE_NUMBER);
    memset(VoltagestateMachineDatas,0,sizeof(SM_StateMachineType) * SM_VOLTAGE_STATE_MACHINE_NUMBER);
    Sm_Voltage = Sm_VoltageInit;
    VoltageStateCurrent = SM_VOLTAGE_STATE_NORMAL;
    DTCHighVoltage = FALSE;
    DTCLowVoltage = FALSE;
    Power_OutDataCurrent = Power_OutInit;
    Power_OutDataBackup = Power_OutInit;
    AD_data = 0x0u;                     /*0--4095*/
    for(Index = 0u;Index <DTCVOLTAGENUM;Index ++)
    {
        DTCResultData[Index].ReportActive = (uint8)FALSE;
        DTCResultData[Index].DTCSts = DTCREPORTNONE;
    }

    SM_Init(&Sm_Voltage, &sm_Voltage_config);
    VoltageInitFlg = TRUE;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void POWER_IsrLVI_IDL(void)
{
    Rtm_Start(RtmConf_RtmMeasurementPoint_Interrupt_Callout);
    if (/*level low,lvi happens*/ ICU_LOW == Icu_GetInputLevel(IcuConf_IcuChannel_VIP_LVI_IDL))
    {
        Rte_Write_Power_Request_PowerModeEmergencySleep_requestedMode(BswMReqSleepEmergency);
    }
    else /*level hign ,lvi wakeup*/
    {
        EcuM_CheckWakeup(ECUM_WKSOURCE_LVI);
        Rte_Write_Power_Request_PowerModeEmergencySleep_requestedMode(BswMReqNone);
    }

    Rtm_Stop(RtmConf_RtmMeasurementPoint_Interrupt_Callout);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Power_Volt_Mgr(void)
{
    boolean Volt_Calculate_ret = FALSE;
    
    Volt_Calculate_ret  = Power_Volt_Calculate();

    if (TRUE == Volt_Calculate_ret)
    {
        if (FALSE == Sm_Voltage.enabled)
        {
            SM_EnabledSet(&Sm_Voltage, TRUE);
        }
        (void)Power_Volt_Timer_Sts_Loigc();
        SM_MainFunction(&Sm_Voltage);
    }
    else 
    {
        Power_OutDataCurrent.state = VOLTAGE_OUT_NORMAL;
        Power_OutDataCurrent.value = VOLTAGE_MAXVOLTAGE;
    }

    VoltageDTCLogic();
    Power_VoltageStateUpdate();
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean Power_Volt_Calculate(void)
{
    boolean ret = FALSE;
#ifdef VOLTAGECALCULATETEST
    uint8 LogRet = LOGTIMERINIT;
#endif
    Std_ReturnType IO_Ret = E_NOT_OK;
    uint32 VoltageTemp = 0u;
    IO_Ret = Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VBATT_VIP_DET_ADC, &AD_data);
    if (E_OK == IO_Ret)
    {
        ret = TRUE;
        VoltageTemp = POWER_BATT_V_BJT + ((AD_data * MAX_VOLTAGE_RESOLUTION)/ POWER_BATT_ADC);
        if (VoltageTemp > VOLTAGE_MAXVOLTAGE)
        {
            VoltageTemp = VOLTAGE_MAXVOLTAGE;
            power_err("Power voltage calculate error, more than max!! \r\n");
        }
    }
    else 
    {
        VoltageTemp = VOLTAGE_MAXVOLTAGE;
    }

    if(((Power_OutDataCurrent.value + VOLTAGE_CHANGE_THRESHOLD) < VoltageTemp) ||\
        ((Power_OutDataCurrent.value - VOLTAGE_CHANGE_THRESHOLD) > VoltageTemp))
    {
        Power_OutDataCurrent.value =(uint16)VoltageTemp;
    }

    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Power_Volt_Timer_Sts_Loigc(void)
{
    uint8 Timer_ID;
    if (Power_OutDataCurrent.value <= POWER_VOLTAGE_NORMAL_MAX)
    {
        if((Vol_Timer[T3] > VOLTAGE23S) ||(Vol_Timer[T4] > VOLTAGE3S))
        {
            /* keep timing until reset */
        }
        else
        {
            Vol_Timer[T4]       = 0u;
			Vol_Timer[T3]		= 0u;


        }
    }
    if (Power_OutDataCurrent.value > POWER_VOLTAGE_NORMAL_MIN)
    {
        if(Vol_Timer[T5] > VOLTAGE20S)
        {
            /* keep timing until reset */
        }
        else
        {
            Vol_Timer[T5]       = 0u;

        }
    }

    for (Timer_ID = T3; Timer_ID <= T7; Timer_ID++)
    {
        if (Vol_Timer[Timer_ID] > 0u)
        {
            if (Vol_Timer[Timer_ID] < 0xFFFF)
            {
                Vol_Timer[Timer_ID] ++;
            }
        }
    }

    if (((Power_OutDataCurrent.value > POWER_VOLTAGE_LOW_SLEEP) && (Power_OutDataCurrent.value <= POWER_VOLTAGE_NORMAL_MIN)) &&
         (Power_OutDataBackup.value > POWER_VOLTAGE_NORMAL_MIN))
    {
        Vol_Timer[T5] ++;
    }
    else if (((Power_OutDataCurrent.value > POWER_VOLTAGE_HIGH_ALARM) && (Power_OutDataCurrent.value <= POWER_VOLTAGE_HIGH_SLEEP)) &&
         (Power_OutDataBackup.value <= POWER_VOLTAGE_HIGH_ALARM))
    {
        Vol_Timer[T4] ++;
    }
    else if (((Power_OutDataCurrent.value > POWER_VOLTAGE_NORMAL_MAX) && (Power_OutDataCurrent.value <= POWER_VOLTAGE_HIGH_ALARM)) &&
         (Power_OutDataBackup.value <= POWER_VOLTAGE_NORMAL_MAX))
    {
        Vol_Timer[T3] ++;
    }
    else if ((Power_OutDataCurrent.value > POWER_VOLTAGE_HIGH_SLEEP) && (Power_OutDataBackup.value <= POWER_VOLTAGE_HIGH_SLEEP))
    {
        Vol_Timer[T6] ++;
    }
    else if ((Power_OutDataCurrent.value < POWER_VOLTAGE_LOW_SLEEP) && (Power_OutDataBackup.value >= POWER_VOLTAGE_LOW_SLEEP))
    {
        Vol_Timer[T7] ++;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Power_VoltageStateUpdate(void)
{
    switch (VoltageStateCurrent)
    {
        case SM_VOLTAGE_STATE_NORMAL:
        case SM_VOLTAGE_HIGH_NORMAL:
            Power_OutDataCurrent.state = VOLTAGE_OUT_NORMAL;
            break;

        case SM_VOLTAGE_LOW_SLEEP:
            Power_OutDataCurrent.state = VOLTAGE_OUT_LOWSLEEP;
            break;

        case SM_VOLTAGE_HIGH_ALARM:
            Power_OutDataCurrent.state = VOLTAGE_OUT_HIGHALARM;
            break;

        case SM_VOLTAGE_HIGH_SLEEP:
            Power_OutDataCurrent.state = VOLTAGE_OUT_HIGHSLEEP;
            break;
        case SM_VOLTAGE_LOW_NORMAL:
            Power_OutDataCurrent.state = VOLTAGE_OUT_LOWALARM;
            break;
        default:
            power_err("Voltage output invalid state!!");
            break;
    }
    memcpy(&Power_OutDataBackup,&Power_OutDataCurrent,sizeof(Power_OutDataCurrent));
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
s_PowerOut_t Power_VoltageOutMgr(void)
{
    return Power_OutDataCurrent;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
uint8 Power_VoltageStateFlg(void)
{
    uint8 ret = POWER_VOLTAGE_NORMAL;
    if((Power_OutDataCurrent.value <= POWER_VOLTAGE_NORMAL_MAX)&&\
        (Power_OutDataCurrent.value > POWER_VOLTAGE_LOW_RECOVER))
    {
        ret = POWER_VOLTAGE_NORMAL;
    }
    else
    {
        ret = POWER_VOLTAGE_ABNORMAL;
    }
    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
uint8 Power_VoltageRecoverFlg(void)
{
    uint8 ret = POWER_VOLTAGE_NORMAL;
    if((Power_OutDataCurrent.value <= POWER_VOLTAGE_NORMAL_MAX)&&\
        (Power_OutDataCurrent.value > POWER_VOLTAGE_LOW_RECOVER))
    {
        ret = POWER_VOLTAGE_NORMAL;
    }
    else
    {
        ret = POWER_VOLTAGE_ABNORMAL;
    }
    return ret;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void VoltageDTCLogic(void)
{
    VoltageHighDTC();
    VoltageLowDTC();
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void VoltageHighDTC(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    if(Power_OutDataCurrent.value > 1600)
    {
        DTCHighVoltage = TRUE;
    }
    else if(Power_OutDataCurrent.value < 1500)
    {
        DTCHighVoltage = FALSE;
    }

    DTCRet = DTCReportDebounce((uint8)DTCHighVoltage,DTCVOLTAGEHIGH,&Pw_EventDTCCfg);

    if(DTCRet != DTCREPORTNONE)
    {
        DTCResultData[DTCVOLTAGEHIGH].DTCSts = DTCRet;
        DTCResultData[DTCVOLTAGEHIGH].ReportActive = (uint8)TRUE;
    }

    if(TRUE == DTCResultData[DTCVOLTAGEHIGH].ReportActive)
    {
        DTCSendRet = Rte_Call_DTCD10017_OverVoltage_SetEventStatus(DTCResultData[DTCVOLTAGEHIGH].DTCSts);
        if(E_OK == DTCSendRet)
        {
            DTCResultData[DTCVOLTAGEHIGH].ReportActive = (uint8)FALSE;
            power_verbose("Over Voltage report %d",DTCResultData[DTCVOLTAGEHIGH].DTCSts);
        }
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void VoltageLowDTC(void)
{
    Std_ReturnType DTCSendRet;
    uint8 DTCRet = DTCREPORTNONE;
    if(Power_OutDataCurrent.value < 900)
    {
        DTCLowVoltage = TRUE;
    }
    else if(Power_OutDataCurrent.value > 1000)
    {
        DTCLowVoltage = FALSE;
    }

    DTCRet = DTCReportDebounce((uint8)DTCLowVoltage,DTCVOLTAGELOW,&Pw_EventDTCCfg);

    if(DTCRet != DTCREPORTNONE)
    {
        DTCResultData[DTCVOLTAGELOW].DTCSts = DTCRet;
        DTCResultData[DTCVOLTAGELOW].ReportActive = (uint8)TRUE;
    }

    if(TRUE == DTCResultData[DTCVOLTAGELOW].ReportActive)
    {
        DTCSendRet = Rte_Call_DTCD10016_UnderVoltage_SetEventStatus(DTCResultData[DTCVOLTAGELOW].DTCSts);
        if(E_OK == DTCSendRet)
        {
            DTCResultData[DTCVOLTAGELOW].ReportActive = (uint8)FALSE;
            power_verbose("Under Voltage report %d",DTCResultData[DTCVOLTAGELOW].DTCSts);
        }
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint8 DTCReportDebounce(uint8 errorStatus,uint8 DTCID, const s_Pw_EventDTC_t *EventDTC)
{
    uint8 tEventSts;
    uint8 Ret = DTCREPORTNONE;
    s_Pw_EventDebounce_t *Pw_EventDebounce_local = &Pw_EventDTCCfg.Pw_EventDebounce_Data[DTCID];
    const s_Pw_EventDebounceCfg_t *Pw_EventDebounceCfg_local = &Pw_EventDTCCfg.Pw_EventDebounceCfg_Data[DTCID];
    uint32 Pw_DtcClearFlag;

	/* 14 service, clear DTC debounce count. Each time the 14 service is triggered, the counter + 1 */
	Rte_Read_rpSR_piDiagMonitorReInitFlag_ChangeCounter(&Pw_DtcClearFlag);
	if( Pw_dtcclrreq != Pw_DtcClearFlag )
	{
		Pw_dtcclrreq = Pw_DtcClearFlag;
		memset((void*)Pw_EventDebounce_d,0,sizeof(s_Pw_EventDebounce_t)*DTCVOLTAGENUM);
	}

    tEventSts = EventDTC->eventStatus[DTCID];
    if(TRUE == errorStatus)
    {
        Pw_EventDebounce_local->passedCounter = 0;
        Pw_EventDebounce_local->failedCounter++;
        if(Pw_EventDebounce_local->failedCounter > Pw_EventDebounceCfg_local->FailThreshold)
        {
            tEventSts = DEM_EVENT_STATUS_FAILED;
            Pw_EventDebounce_local->failedCounter = 0;
        }
    }
    else
    {
        Pw_EventDebounce_local->failedCounter = 0;
        Pw_EventDebounce_local->passedCounter++;
        if(Pw_EventDebounce_local->passedCounter > Pw_EventDebounceCfg_local->PassThreshold)
        {
            tEventSts = DEM_EVENT_STATUS_PASSED;
            Pw_EventDebounce_local->passedCounter = 0;
        }
    }
    
    if(tEventSts == EventDTC->eventStatus[DTCID])
    {
        Pw_EventDebounce_local->monitorCounter++;
        if ((DEM_EVENT_STATUS_PASSED == EventDTC->eventStatus[DTCID]) && (Pw_EventDebounce_local->monitorCounter > Pw_EventDebounceCfg_local->PassThreshold))
        {
            Pw_EventDebounce_local->monitorCounter = 0;
            Ret = DTCREPORTPASSED;
            return Ret;
        }
        else if ((DEM_EVENT_STATUS_FAILED == EventDTC->eventStatus[DTCID]) && (Pw_EventDebounce_local->monitorCounter > Pw_EventDebounceCfg_local->FailThreshold))
        {
            Pw_EventDebounce_local->monitorCounter = 0;
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
        Pw_EventDebounce_local->monitorCounter = 0;
        return Ret;
    }
    

}

uint8 PM_VoltageShutdownEventCheck(void)
{
	if(POWER_VOLTAGEEVENT_LOWENTER >= Power_OutDataCurrent.value)
	{
		return EVENT_OCCUR;
	}
	else
	{
		return NO_EVENT;
	}
}

uint8 PM_VoltageEnableEventCheck(void)
{
	if(POWER_VOLTAGEEVENT_LOWEXIT < Power_OutDataCurrent.value)
	{
		return EVENT_OCCUR;
	}
	else
	{
		return NO_EVENT;
	}
}
/*EOL DID:BE12: equal to voltage >24 , mcu will sleep in 5s.
		 		test device shall stop all can msg(nm and app) sending in 4s after BE12*/
void PM_EOL_FastSleep(void)
{
	Vol_Timer[T6] ++;
	Power_EolSleepflag = TRUE;
	power_warn("eol fast sleep");
}
#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"


