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
 * @file:      Power_Temp_Monitor.c
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

#include "Power_Temp_Monitor.h"
#include "IoHwAb_Cfg_RI.h"
#include "Logger_Cfg.h"
#include "logger.h"
#include "string.h"
#include "Misc_Board.h"

#define TEMP_ENVIRONMENT_INCREASE                               (28)
#define TEMP_INITVALUE                                          (TEMP_ENVIRONMENT_INCREASE)


typedef struct
{
    sint16 Temp;
    uint16 ADC;
}s_Tempureture_Def_t;


typedef struct
{
    sint16  CurTemp;
    uint8   CurState;
    boolean up_changed_flag;   //temp up to other range
    boolean down_changed_flag; //temp down to other range
    uint16  wait_change_time;
    boolean bTempFault;
} Temprature_Record;

typedef struct
{
    sint16 TMin_Cfg;
    sint16 TMax_Cfg;
    uint8 MinTimeCfg;
    uint8 MaxTimeCfg;
} Temp_State_Config_Type;


#define POWER_START_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


static const Temp_State_Config_Type temp_state_range_cfg[] = {\
    {-32768,    -38,    0x50u, 0x50u},\
    {-40,       95,     0x50u, 0x50u},\
    {93,        110,    0x50u, 0x50u},\
    {108,       32767,  0x50u, 0x50u}\

};


/*need -40 ---> 125*/
static const s_Tempureture_Def_t Tempureture_Calibration_List_A1B0[] = {\
    {-40,3896},{-39,3885},{-38,3873},{-37,3862},{-36,3849},{-35,3836},{-34,3823},{-33,3809},{-32,3794},{-31,3779},
    {-30,3763},{-29,3747},{-28,3730},{-27,3712},{-26,3694},{-25,3675},{-24,3656},{-23,3636},{-22,3615},{-21,3594},
    {-20,3572},{-19,3549},{-18,3526},{-17,3502},{-16,3477},{-15,3452},{-14,3426},{-13,3399},{-12,3372},{-11,3344},
    {-10,3315},{-9,3286},{-8,3256},{-7,3225},{-6,3194},{-5,3162},{-4,3130},{-3,3097},{-2,3063},{-1,3029},
    {0,2995},{1,2960},{2,2925},{3,2889},{4,2853},{5,2816},{6,2779},{7,2742},{8,2704},{9,2667},
    {10,2629},{11,2590},{12,2552},{13,2513},{14,2474},{15,2435},{16,2396},{17,2357},{18,2318},{19,2279},
    {20,2240},{21,2202},{22,2163},{23,2124},{24,2086},{25,2048},{26,2009},{27,1971},{28,1934},{29,1896},
    {30,1859},{31,1822},{32,1786},{33,1750},{34,1714},{35,1679},{36,1644},{37,1609},{38,1575},{39,1542},
    {40,1509},{41,1476},{42,1444},{43,1412},{44,1381},{45,1350},{46,1319},{47,1290},{48,1260},{49,1232},
    {50,1203},{51,1175},{52,1148},{53,1121},{54,1095},{55,1070},{56,1044},{57,1020},{58,995},{59,972},
    {60,948},{61,926},{62,904},{63,883},{64,862},{65,841},{66,821},{67,802},{68,783},{69,764},
    {70,746},{71,728},{72,711},{73,694},{74,677},{75,661},{76,645},{77,630},{78,615},{79,600},
    {80,586},{81,572},{82,558},{83,545},{84,532},{85,519},{86,507},{87,495},{88,483},{89,472},
    {90,461},{91,450},{92,439},{93,429},{94,419},{95,409},{96,399},{97,390},{98,381},{99,372},
    {100,363},{101,355},{102,347},{103,339},{104,331},{105,324},{106,316},{107,309},{108,302},{109,295},
    {110,289},{111,282},{112,276},{113,270},{114,264},{115,258},{116,252},{117,246},{118,241},{119,236},
    {120,230},{121,225},{122,221},{123,216},{124,211},{125,207},

};
static const s_Tempureture_Def_t Tempureture_Calibration_List_B1[] = {\
    {-40,3039},{-39,2994},{-38,2948},{-37,2902},{-36,2855},{-35,2807},{-34,2758},{-33,2709},{-32,2660},{-31,2610},
    {-30,2559},{-29,2509},{-28,2458},{-27,2407},{-26,2356},{-25,2305},{-24,2254},{-23,2203},{-22,2152},{-21,2101},
    {-20,2051},{-19,2001},{-18,1952},{-17,1903},{-16,1854},{-15,1806},{-14,1758},{-13,1712},{-12,1665},{-11,1620},
    {-10,1575},{-9,1531},{-8,1487},{-7,1445},{-6,1403},{-5,1362},{-4,1322},{-3,1283},{-2,1245},{-1,1207},
    {0,1171},{1,1135},{2,1100},{3,1067},{4,1034},{5,1002},{6,971},{7,940},{8,911},{9,882},
    {10,854},{11,827},{12,801},{13,775},{14,751},{15,727},{16,704},{17,681},{18,659},{19,638},
    {20,618},{21,598},{22,579},{23,560},{24,542},{25,525},{26,508},{27,492},{28,476},{29,461},
    {30,446},{31,432},{32,418},{33,405},{34,392},{35,380},{36,368},{37,356},{38,345},{39,334},
    {40,324},{41,313},{42,304},{43,294},{44,285},{45,276},{46,268},{47,259},{48,251},{49,244},
    {50,236},{51,229},{52,222},{53,215},{54,209},{55,202},{56,196},{57,190},{58,185},{59,179},
    {60,174},{61,169},{62,164},{63,159},{64,154},{65,150},{66,146},{67,142},{68,138},{69,134},
    {70,130},{71,126},{72,123},{73,119},{74,116},{75,113},{76,110},{77,107},{78,104},{79,101},
    {80,98},{81,95},{82,93},{83,90},{84,88},{85,86},{86,83},{87,81},{88,79},{89,77},
    {90,75},{91,73},{92,71},{93,69},{94,67},{95,66},{96,64},{97,62},{98,61},{99,59},
    {100,58},{101,56},{102,55},{103,54},{104,52},{105,51},{106,50},{107,49},{108,47},{109,46},
    {110,45},{111,44},{112,43},{113,42},{114,41},{115,40},{116,39},{117,38},{118,37},{119,36},
    {120,36},{121,35},{122,34},{123,33},{124,32},{125,32},
};
static const s_Tempureture_Def_t* Tempureture_Calibration_List = NULL_PTR; 
static uint16 TEMP_CALBNUM = 0;
#define POWER_STOP_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h"


#define TEMPTABLE\
    X_MACRO_TEMP(TEMP_MCU, RI_IoHwAb_AIn_PinInCfg_VIP_NTC_MON1_IAN,"TEMP_MCU")\
    X_MACRO_TEMP(TEMP_AMP1,RI_IoHwAb_AIn_PinInCfg_VIP_NTC_MON2_IAN,"TEMP_AMP1")\
    X_MACRO_TEMP(TEMP_AMP2,RI_IoHwAb_AIn_PinInCfg_VIP_NTC_MON3_IAN,"TEMP_AMP2")\


typedef enum
{
#define X_MACRO_TEMP(a,b,c) a,
    TEMPTABLE
#undef X_MACRO_TEMP
    TEMPAD_NUM = 3,
}e_TempEnum_t;

#define POWER_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Power_MemMap.h" 


static sint16 temperatureData[] = {TEMP_INITVALUE,TEMP_INITVALUE,TEMP_INITVALUE};
static Temprature_Record temperature_inside;
static Std_ReturnType IO_RetBackup[] = {E_OK,E_OK,E_OK};
static Std_ReturnType IO_Ret[] = {E_OK,E_OK,E_OK};
static boolean bTempIsFault[TEMPAD_NUM];
static uint8 TempState;
#ifdef APM_TEMP_TEST
sint16 CurrentTemp = 40;
#endif
#define POWER_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Power_MemMap.h" 


#define POWER_START_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h"

static const uint8 TempPinCfg[TEMPAD_NUM] =
{
#define X_MACRO_TEMP(a,b,c) b,
    TEMPTABLE
#undef X_MACRO_TEMP
};


static const char * TEMPLog[TEMPAD_NUM] = 
{
#define X_MACRO_TEMP(a,b,c) c,
        TEMPTABLE
#undef X_MACRO_TEMP
};

static const char *TempStateLog[TEMP_STATE_NUM] = 
{
    "Low Sleep",
    "Normal",
    "High Protect",
    "High Sleep",
};

#define POWER_STOP_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h"



#define POWER_START_SEC_CODE
#include "Power_MemMap.h"

static void PowerTempStateHandle(Temprature_Record *Temp, const Temp_State_Config_Type *table);
static sint16 Power_TempCalculate(const uint32 TempADC);
static void Power_TempColltect(void);
static boolean Power_TempCheckTempIsFault(const uint32 TempADC);
static uint16 binarysearch(const s_Tempureture_Def_t *table, uint16 input, uint16 size);
Std_ReturnType Power_TempGetHwVersion(void);

#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"


#define POWER_START_SEC_CODE
#include "Power_MemMap.h"


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
extern void Power_TempInit(void)
{
    temperature_inside.CurState = (uint8)TEMP_NORMAL;
    temperature_inside.CurTemp = TEMP_INITVALUE;
    temperature_inside.up_changed_flag = FALSE;
    temperature_inside.down_changed_flag = FALSE;
    temperature_inside.wait_change_time = 0;
    TempState = POWER_TEMP_NORMAL;
}

/**
 * @brief 
 * 
 * @return Std_ReturnType 
 */

Std_ReturnType Power_TempGetHwVersion(void)
{
    uint8 ver = 0;
    Std_ReturnType ret ;
    if(Tempureture_Calibration_List == NULL_PTR)
    {
        ret = Misc_Board_GetHwVersion(&ver);
        if(ret==E_OK)
        {
            if(ver<eMiscBoard_Version_B1)
            {
                Tempureture_Calibration_List=Tempureture_Calibration_List_A1B0;
                TEMP_CALBNUM = sizeof(Tempureture_Calibration_List_A1B0)/sizeof(s_Tempureture_Def_t);
                //power_warn("Tempeture  Board Version not B1\r\n");//delete,use Misc_Board_CheckHwVersion()
            }
            else
            {
                Tempureture_Calibration_List=Tempureture_Calibration_List_B1;
                TEMP_CALBNUM = sizeof(Tempureture_Calibration_List_B1)/sizeof(s_Tempureture_Def_t);
                //power_warn("Tempeture  Board Version B1\r\n");
            }
        }
        else
        {
            ret = E_NOT_OK;
        }
        
    }
    else
    {
        ret = E_OK;
    }
    
    return ret;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Power_TempMonitor(void)
{
    Std_ReturnType ret ;
    ret = Power_TempGetHwVersion();
    if(ret == E_OK)
    {
        Power_TempColltect();
    
        if(E_OK == IO_Ret[TEMP_MCU])
        {
            PowerTempStateHandle(&temperature_inside, temp_state_range_cfg);
        }
        else
        {
            /* keep Init value */
            
        }
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
extern Std_ReturnType Power_TempOut(s_TempOut_t *ptr)
{
    Std_ReturnType ret = E_OK;
    if(E_NOT_OK == IO_Ret[TEMP_MCU])
    {
        ptr->State = (uint8)TEMP_STATE_INIT;
        ptr->Value = 0;
        ptr->bTempFault = (boolean)0;
        ret = E_NOT_OK;
    }
    else
    {
        ptr->State = temperature_inside.CurState;
        ptr->Value = temperature_inside.CurTemp;
        ptr->bTempFault = temperature_inside.bTempFault;
    }
    return ret;
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : real time update Flg
 ***********************************************************************/
extern uint8 Power_TempStateRTUFlg(void)
{
    uint8 ret = POWER_TEMP_NORMAL;
    if((temperature_inside.CurState != TEMP_LOW_SLEEP)&&\
       (temperature_inside.CurState != TEMP_HIGH_SLEEP))
    {
        ret = POWER_TEMP_NORMAL;
    }
    else
    {
        ret = POWER_TEMP_ABNORMAL;
    }
    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : Not real time update Flg
 ***********************************************************************/
extern uint8 Power_TempStateTempFlg(void)
{
    if(POWER_TEMP_ABNORMAL != TempState)
    {
        if((temperature_inside.CurState != TEMP_LOW_SLEEP)&&\
           (temperature_inside.CurState != TEMP_HIGH_SLEEP))
        {
            TempState = POWER_TEMP_NORMAL;
        }
        else
        {
            TempState = POWER_TEMP_ABNORMAL;
        }
    }
    return TempState;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Power_TempColltect(void)
{
    uint8 index;

    for(index = 0u; index < TEMPAD_NUM; index ++)
    {
        uint32 ADC_Data = (uint32)0u;
        boolean TempIsFault = FALSE;
        
        IO_Ret[index] = IoHwAb_GetVoltage(TempPinCfg[index],&ADC_Data);
        
        if(E_OK == IO_Ret[index])
        {
            TempIsFault = Power_TempCheckTempIsFault(ADC_Data);
            
            
            if (TempIsFault == FALSE)
            {
                temperatureData[index] = Power_TempCalculate(ADC_Data);

                if(E_NOT_OK == IO_RetBackup[index])
                {
                    power_verbose("Tempeture %S is Change from no Ready to Ready !",TEMPLog[index]);
                }
            }
            else
            {
                power_verbose("senser %d is fault! (# %d)",index,ADC_Data);
            }
            
            bTempIsFault[index] = TempIsFault;
        }
        else
        {
            if(E_OK == IO_RetBackup[index])
            {
                power_verbose("Tempeture %s is not ready!",TEMPLog[index]);
            }
        }
    }
    memcpy(IO_RetBackup,IO_Ret,sizeof(IO_Ret));
    #ifdef APM_TEMP_TEST
    temperature_inside.CurTemp = CurrentTemp;
    #else
    temperature_inside.CurTemp = temperatureData[TEMP_MCU];
    #endif

    temperature_inside.bTempFault = bTempIsFault[TEMP_MCU];
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void PowerTempStateHandle(Temprature_Record *Temp, const Temp_State_Config_Type *table)
{
    uint8 StateTemp;
    uint8 StateIndex;
	sint16 Table_Tmax_Cfg;
	sint16 Table_Tmin_Cfg;
	sint16 tempCurTemp;
	tempCurTemp = Temp->CurTemp;
    StateTemp = Temp->CurState;
    Table_Tmax_Cfg = table[StateTemp].TMax_Cfg;
	Table_Tmin_Cfg = table[StateTemp].TMin_Cfg;
    if (tempCurTemp >= Table_Tmax_Cfg)
    {
        for (StateIndex = StateTemp; StateIndex < (uint8)TEMP_STATE_NUM; StateIndex++)
        {

            if ((tempCurTemp >= table[StateIndex].TMin_Cfg) &&\
                (tempCurTemp < table[StateIndex].TMax_Cfg))
            {
                break;
            }
        }
        /*greater than max thread, deal as high over state*/
        if (StateIndex >= TEMP_STATE_NUM) 
        {
            StateIndex =(uint8) TEMP_HIGH_SLEEP;
        }
        Temp->down_changed_flag = FALSE; 
        if (Temp->up_changed_flag == FALSE)
        {
            Temp->up_changed_flag = TRUE;
            Temp->wait_change_time = table[StateTemp].MaxTimeCfg;
        }

        StateTemp = StateIndex;
    }
    else if (tempCurTemp <= Table_Tmin_Cfg)
    {
        for (StateIndex = StateTemp; StateIndex < (uint8)TEMP_STATE_NUM; StateIndex--)
        {
            if ((tempCurTemp > table[StateIndex].TMin_Cfg) &&
                (tempCurTemp <= table[StateIndex].TMax_Cfg))
            {
                break;
            }
        }

        Temp->up_changed_flag = FALSE;
        if (Temp->down_changed_flag == FALSE)
        {
            Temp->down_changed_flag = TRUE;
            Temp->wait_change_time = table[StateIndex].MinTimeCfg;
        }

        StateTemp = StateIndex;
    }
    else
    {
        Temp->up_changed_flag = FALSE;
        Temp->down_changed_flag = FALSE;
    }

    if (Temp->wait_change_time >= 0u)
    {
        Temp->wait_change_time--;
    }

    if ((Temp->CurState != StateTemp) && (0x0u == Temp->wait_change_time))
    {
        power_warn("Environment temp %s->%s",TempStateLog[Temp->CurState],TempStateLog[StateTemp]);
        Temp->CurState = StateTemp;

        
    }
}

/*****************************************************************************
 *
 * Function:    binarysearch
 *
 * Description: Find the temperature corresponding to the AD value  in temp table
 *
 * Invocation:  
 *
 * Parameter:   temperature and adc  table ,ad value ,table size
 *
 * Return:      temperature
 *
 ******************************************************************************/
static uint16 binarysearch(const s_Tempureture_Def_t *table, uint16 input, uint16 size) 
{ 
    uint16 left,right,middle; 
    left = 0u;
    right = size-1u;

   	if(NULL_PTR == table)
   	{
   	    return 0;
   	}
    /* if the input value is out of low range cailbration, return low range invalid value index */
    if(input > table[left + 1].ADC)
    {
        return (left);
    }
    else
    {
        while(left <= right)
        {
            if(left == (right - 1))
           {
                middle = right;
            }
            else
            {
                middle = ((uint16)left+(uint16)right)/(uint16)2;
            }
            if((input < table[middle-1].ADC) 
               && (input >= table[middle].ADC))
            {
                return  middle;
            }
            else if(input == table[middle-1].ADC)
            {
                return  middle - 1u;
            }
            else
            {
                /* Added to avoid QAC Warning */
            }
            if(input > table[middle].ADC)
            {
                right = middle-1u;
            }
            else
            {
                left = middle+1u;
            }
        }
        middle = 0;
        return middle;
    }
} 


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static sint16 Power_TempCalculate(const uint32 TempADC)
{
    sint16 ret = 0;
    uint16 Temp = 0u;
    if(Tempureture_Calibration_List != NULL_PTR)
    {
        Temp = binarysearch(Tempureture_Calibration_List,(uint16)TempADC,TEMP_CALBNUM);
        ret = Tempureture_Calibration_List[Temp].Temp;
    }
    
    return ret;
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean Power_TempCheckTempIsFault(const uint32 TempADC)
{
    boolean ret = FALSE;
    
    if(Tempureture_Calibration_List != NULL_PTR)
    {
        if ((TempADC > Tempureture_Calibration_List[0].ADC)||(TempADC < Tempureture_Calibration_List[TEMP_CALBNUM - 1].ADC))
        {
            ret = TRUE;
        }
    }

    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      :physical value -40 ~ 125,offset -40,send data 0 - 165
 ***********************************************************************/
void Power_TempEOL_Get_MCUAMP_Temperature(EOL_Struct_3Element *arg)
{
    uint8 Index;
    uint8 TempeData[TEMPAD_NUM];
    memcpy((void*)TempeData,(void*)temperatureData,(uint32)TEMPAD_NUM);
    for(Index = 0u;Index < TEMPAD_NUM;Index ++)
    {
        if (TRUE == bTempIsFault[Index])
        {
            TempeData[Index] = 0xFEu;
        }
        else if(E_OK == IO_Ret[Index])
        {
            TempeData[Index] = ((uint8)temperatureData[Index]  + (uint8)40);
        }
        else
        {
            TempeData[Index] = 0xFFu;
        }
    }
    memcpy((void*)arg,(void*)TempeData,(uint32)TEMPAD_NUM);
}



#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"

