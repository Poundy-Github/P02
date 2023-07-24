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
 * @file:      EXT_Power.c
 * @author:    Nobo
 * @date:      2020-6-5
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-6-5
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "Dio.h"
#include "Icu.h"
#include "Mcu.h"
#include "Port.h"
#include "Ext_Power.h"
#include "logger.h"
#include "HwConfig.h"
#include "Misc_Board.h"



/********************************************* public Domain*******************************************/
/* Power mode state define */
#define EXT_POWER_STATUS_INITIAL                   ((uint8) 0U)
#define EXT_POWER_STATUS_POWER_ON                  ((uint8) 1U)
#define EXT_POWER_STATUS_POWER_OFF                 ((uint8) 2U)



/* Power info type define*/
typedef struct
{
    POWER_STATE_t   sPowerState;
    uint16          sPowerSequence;
    uint16          u16ExeCnt;
    uint16          flag;
    uint8           retryCnt;
}Ext_Power_Info;




/********************************************* PMIC define *********************************************/
/* SOC PMIC POWER ON STATE */

#define POWER_PMIC_POWER_UP_DELAY           (0u)
#define POWER_PMIC_POWER_UP_SET_HIGH        (1u)
#define POWER_PMIC_POWER_UP_SET_LOW         (2U)
#define POWER_PMIC_POWER_UP_WAIT_READY      (3U)
#define POWER_PMIC_POWER_UP_END             (4u)

/* SOC PMIC POWER OFF STATE */
#define POWER_PMIC_POWER_DOWN_EXT           (0u)
#define POWER_PMIC_POWER_DOWN_END           (1u)

/* SOC PMIC POWER RESET STATE */
#define POWER_PMIC_POWER_RESET_DISABLE_DISP (0u)
#define POWER_PMIC_POWER_RESET_EXT          (1u)
#define POWER_PMIC_POWER_RESET_WAIT         (2u)
#define POWER_PMIC_POWER_RESET_END          (3u)


/* SOC PMIC REQUEST DEFING */
typedef enum
{
    eSOC_POWER_REQ_POWER_UP=0,
    eSOC_POWER_REQ_POWER_DOWN,
    eSOC_POWER_REQ_RESET,
    eSOC_POWER_REQ_POWER_UP2MINSYS,
    eSOC_POWER_REQ_RESET2MINSYS,
    eSOC_POWER_REQ_ALL,
}SOC_POWER_REQ_t;

/* SOC PMIC REQUEST Remapping */
typedef struct
{
    POWER_STATE_t   state;
    uint16          flag;
}SOC_POWER_ReqMapping_t;

/* Ext_Power_Info.flag defing */
#define POWER_PMIC_REQ_MinSystem            (1u)


/********************************************* Other define *********************************************/
/* SOC PMIC POWER ON STATE */

#define POWER_Other_POWER_UP_SATR             (0u)
#define POWER_Other_POWER_UP_EXT              (1u)
#define POWER_Other_POWER_UP_WAIT             (2u)
#define POWER_Other_POWER_UP_END              (3u)

#define TASK_PERIOD                         5
#define Ms2FunctionPeriodCnt(ms)            (((ms) + TASK_PERIOD - 1)/TASK_PERIOD)

//HW version
static uint8 hwVersionExt;

const static uint16 u16SDARS_RST_DelayTimer = Ms2FunctionPeriodCnt(10);
const static uint16 u16Tuner_DelayTimer =     Ms2FunctionPeriodCnt(20);


/********************************************* static variable ******************************************/
const static uint8 u8RetryCntMax = 3;
const static uint16 u16PMIC_DelayTimer = Ms2FunctionPeriodCnt(25);
const static uint16 u16PMIC_HighTimer = Ms2FunctionPeriodCnt(15);
const static uint16 u16PMIC_WaitTimer = Ms2FunctionPeriodCnt(500);
const static uint16 u16PMIC_ResetWaitTime =  Ms2FunctionPeriodCnt(2000);

static uint8 sPowerBasicState = EXT_POWER_STATUS_INITIAL;


static Ext_Power_Info sPowerPMICHandle =  {ePOWER_STATE_INITIAL,0};
static Ext_Power_Info sPowerOtherHandle = {ePOWER_STATE_INITIAL,0};
static Std_ReturnType EXT_Power_PMICReq(SOC_POWER_REQ_t req);


static const SOC_POWER_ReqMapping_t cPowerReq2StateMapTable[eSOC_POWER_REQ_ALL] =
{
    {ePOWER_STATE_POWER_UP,  0,                       },/*eSOC_POWER_REQ_POWER_UP=0,*/
    {ePOWER_STATE_POWER_DOWN,0,                       },/*eSOC_POWER_REQ_POWER_DOWN,*/
    {ePOWER_STATE_RESET,     0,                       },/*eSOC_POWER_REQ_RESET,*/
    {ePOWER_STATE_POWER_UP,  POWER_PMIC_REQ_MinSystem,},/*eSOC_POWER_REQ_POWER_UP2MINSYS,*/
    {ePOWER_STATE_RESET,     POWER_PMIC_REQ_MinSystem,},/*eSOC_POWER_REQ_RESET2MINSYS,*/
};




void EXT_Power_GotoSleep(void)
{
    uint8 ver = 0;


    (void)Misc_Board_GetHwVersion(&ver);
    Port_Init(PortConfig_Sleep);

    if (eMiscBoard_Version_A1 == ver)
    {
        // Disabled WD
        Dio_WriteChannel(DioConf_DioChannel_VIP_WD_enable,STD_HIGH);
        Dio_WriteChannel(DioConf_DioChannel_VIP_GPS_RST,STD_HIGH);
    }
    
    Icu_EnableNotification(IcuConf_IcuChannel_VIP_CAN0_RXD);
    Icu_EnableNotification(IcuConf_IcuChannel_VIP_CAN1_RXD);
    Icu_EnableNotification(IcuConf_IcuChannel_VIP_CAN3_RXD);
    Icu_EnableNotification(IcuConf_IcuChannel_VIP_RLIN31_RXD);
    Icu_EnableNotification(IcuConf_IcuChannel_VIP_RLIN32_RXD);

    Icu_EnableNotification(IcuConf_IcuChannel_VIP_SI_IDH);
    Icu_EnableNotification(IcuConf_IcuChannel_VIP_RLIN31_INH);
    Icu_EnableNotification(IcuConf_IcuChannel_VIP_RLIN32_INH);
    Icu_EnableNotification(IcuConf_IcuChannel_VIP_LVI_IDL);
}


/********************************************* PMIC FUNCTION *********************************************/

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void EXT_Power_PMICPowerUp(void)
{
    Dio_ChannelType PSHOLD;
    PSHOLD = Dio_ReadChannel(DioConf_DioChannel_PMIC_VIP_PSHOLD);
    switch (sPowerPMICHandle.sPowerSequence)
    {
        case POWER_PMIC_POWER_UP_DELAY:
        	Dio_WriteChannel(DioConf_DioChannel_VIP_ID_EN_ODH, STD_HIGH);
			Dio_WriteChannel(DioConf_DioChannel_VIP_CD_EN_ODH, STD_HIGH);
			Dio_WriteChannel(DioConf_DioChannel_VIP_PD_EN_ODH, STD_HIGH);
			Dio_WriteChannel(DioConf_DioChannel_VIP_HD_EN_ODH, STD_HIGH);
            Dio_WriteChannel(DioConf_DioChannel_VIP_PMIC_KPD, STD_LOW);
            Dio_WriteChannel(DioConf_DioChannel_VIP_PMIC_CBL, STD_LOW);
            Dio_WriteChannel(DioConf_DioChannel_VIP_20098_EN, STD_HIGH);
            Dio_WriteChannel(DioConf_DioChannel_VIP_REVERSE_IRQ, STD_HIGH);
            sPowerPMICHandle.sPowerSequence = POWER_PMIC_POWER_UP_SET_HIGH;
            sPowerPMICHandle.u16ExeCnt = 0;
            break;

        case POWER_PMIC_POWER_UP_SET_HIGH:
            sPowerPMICHandle.u16ExeCnt++;

            if (sPowerPMICHandle.u16ExeCnt >= u16PMIC_DelayTimer)
            {
                sPowerPMICHandle.u16ExeCnt = 0u;
                sPowerPMICHandle.sPowerSequence = POWER_PMIC_POWER_UP_SET_LOW;
                Dio_WriteChannel(DioConf_DioChannel_VIP_PMIC_KPD, STD_HIGH);
                Dio_WriteChannel(DioConf_DioChannel_VIP_PMIC_CBL, STD_HIGH);
            }

            break;

        case POWER_PMIC_POWER_UP_SET_LOW:
            sPowerPMICHandle.u16ExeCnt++;

            if (sPowerPMICHandle.u16ExeCnt >= u16PMIC_HighTimer)
            {
                sPowerPMICHandle.sPowerSequence = POWER_PMIC_POWER_UP_WAIT_READY;
                sPowerPMICHandle.u16ExeCnt = 0u;
                Dio_WriteChannel(DioConf_DioChannel_VIP_PMIC_KPD, STD_LOW);
                Dio_WriteChannel(DioConf_DioChannel_VIP_PMIC_CBL, STD_LOW);
            }
            break;
        case POWER_PMIC_POWER_UP_WAIT_READY:
            if (STD_LOW == PSHOLD)
            {
                sPowerPMICHandle.u16ExeCnt++;
                if (sPowerPMICHandle.u16ExeCnt >= u16PMIC_WaitTimer)
                {
                    sPowerPMICHandle.retryCnt++;
                    sPowerPMICHandle.u16ExeCnt = 0u;
                    if (sPowerPMICHandle.retryCnt >= u8RetryCntMax)
                    {
                sPowerPMICHandle.sPowerSequence = POWER_PMIC_POWER_UP_END;
                        sys_err("PMIC retry timeout !!! ");
                    }
                    else
                    {
                        Dio_WriteChannel(DioConf_DioChannel_VIP_PMIC_KPD, STD_LOW);
                        Dio_WriteChannel(DioConf_DioChannel_VIP_PMIC_CBL, STD_LOW);
                        Dio_WriteChannel(DioConf_DioChannel_VIP_20098_EN, STD_LOW);
                        sPowerPMICHandle.sPowerSequence = POWER_PMIC_POWER_UP_DELAY;
                        sys_warn("PSHOLD timeout !!! ");
                    }
                }
            }
            else
            {
                sPowerPMICHandle.sPowerSequence = POWER_PMIC_POWER_UP_END;
                sPowerPMICHandle.u16ExeCnt = 0u;
                sPowerPMICHandle.retryCnt = 0u;
            }
            break;
        case POWER_PMIC_POWER_UP_END:
            Icu_EnableNotification(IcuConf_IcuChannel_SOC_VIP_CSIH1_CS);
            Icu_EnableEdgeDetection(IcuConf_IcuChannel_SOC_VIP_CSIH1_CS);
            Icu_EnableNotification(IcuConf_IcuChannel_SOC_VIP_CSIH2_CS);
            Icu_EnableEdgeDetection(IcuConf_IcuChannel_SOC_VIP_CSIH2_CS);
            Icu_EnableNotification(IcuConf_IcuChannel_SOC_VIP_CSIH1_REQ2);
            Icu_EnableEdgeDetection(IcuConf_IcuChannel_SOC_VIP_CSIH1_REQ2);
            Icu_EnableNotification(IcuConf_IcuChannel_SOC_VIP_CSIH2_REQ2);
            Icu_EnableEdgeDetection(IcuConf_IcuChannel_SOC_VIP_CSIH2_REQ2);
            sPowerPMICHandle.sPowerState = ePOWER_STATE_IDLE;
            break;

        default:

            /* Do nothing */
            break;
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void EXT_Power_PMICPowerDown(void)
{

    Dio_WriteChannel(DioConf_DioChannel_VIP_PMIC_KPD, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_PMIC_CBL, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_20098_EN, STD_LOW);
    
    sPowerPMICHandle.sPowerSequence = POWER_PMIC_POWER_DOWN_END;
    sPowerPMICHandle.sPowerState = ePOWER_STATE_IDLE;
    sPowerPMICHandle.retryCnt = 0u;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void EXT_Power_PMICReset(void)
{
    switch (sPowerPMICHandle.sPowerSequence)
    {
        case POWER_PMIC_POWER_RESET_DISABLE_DISP:
            Dio_WriteChannel(DioConf_DioChannel_VIP_ID_EN_ODH, STD_LOW);
            Dio_WriteChannel(DioConf_DioChannel_VIP_CD_EN_ODH, STD_LOW);
            Dio_WriteChannel(DioConf_DioChannel_VIP_PD_EN_ODH, STD_LOW);
            Dio_WriteChannel(DioConf_DioChannel_VIP_HD_EN_ODH, STD_LOW);
            sPowerPMICHandle.sPowerSequence = POWER_PMIC_POWER_RESET_EXT;
            break;

        case POWER_PMIC_POWER_RESET_EXT:
            Dio_WriteChannel(DioConf_DioChannel_VIP_PMIC_KPD, STD_LOW);
            Dio_WriteChannel(DioConf_DioChannel_VIP_PMIC_CBL, STD_LOW);
            Dio_WriteChannel(DioConf_DioChannel_VIP_20098_EN, STD_LOW);
            if (sPowerPMICHandle.flag & POWER_PMIC_REQ_MinSystem)
            {
                Dio_WriteChannel(DioConf_DioChannel_VIP_SOC_EDL_3V3, STD_HIGH);
            }
            else 
            {
                Dio_WriteChannel(DioConf_DioChannel_VIP_SOC_EDL_3V3, STD_LOW);
            }
            sPowerPMICHandle.u16ExeCnt = 0u;
            sPowerPMICHandle.retryCnt = 0u;
            sPowerPMICHandle.sPowerSequence = POWER_PMIC_POWER_RESET_WAIT;
            break;

        case POWER_PMIC_POWER_RESET_WAIT:
            sPowerPMICHandle.u16ExeCnt++;

            if (sPowerPMICHandle.u16ExeCnt > u16PMIC_ResetWaitTime)
            {
                sPowerPMICHandle.sPowerSequence = POWER_PMIC_POWER_RESET_END;
            }
            
            break;

        case POWER_PMIC_POWER_RESET_END:
            (void)EXT_Power_PMICReq(eSOC_POWER_REQ_POWER_UP);
            break;

        default:
            /* Do nothing */
            break;
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void EXT_Power_PMICManagement(void)
{
    switch (sPowerPMICHandle.sPowerState)
    {
        case ePOWER_STATE_INITIAL:
        case ePOWER_STATE_IDLE:
            /* Do Nothing */
            break;

        case ePOWER_STATE_POWER_UP:
            EXT_Power_PMICPowerUp();
            break;

        case ePOWER_STATE_POWER_DOWN:
            EXT_Power_PMICPowerDown();
            break;

        case ePOWER_STATE_RESET:
            EXT_Power_PMICReset();
            break;

        default:
			/* Do nothing */
            break;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType EXT_Power_PMICReq(SOC_POWER_REQ_t req)
{
    Std_ReturnType ret = E_NOT_OK;

    if (req < eSOC_POWER_REQ_ALL)
    {
        sPowerPMICHandle.u16ExeCnt = 0;
        sPowerPMICHandle.sPowerSequence = 0;
        sPowerPMICHandle.sPowerState = cPowerReq2StateMapTable[req].state;
        sPowerPMICHandle.flag = cPowerReq2StateMapTable[req].flag;
        ret = E_OK;
    }

    return ret;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
Std_ReturnType EXT_Power_ReqSocReset(uint8 minSystem)
{
    Std_ReturnType ret = E_NOT_OK;

    if ((sPowerPMICHandle.sPowerState == ePOWER_STATE_IDLE) && (sPowerBasicState == EXT_POWER_STATUS_POWER_ON))
    {
        if (minSystem == 0)
        {
            ret = EXT_Power_PMICReq(eSOC_POWER_REQ_RESET);
        }
        else 
        {
            ret = EXT_Power_PMICReq(eSOC_POWER_REQ_RESET2MINSYS);
        }
	    ret = E_OK;
    }
    return ret;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
Std_ReturnType EXT_Power_ReqSocPowerState(POWER_STATE_t state)
{
    Std_ReturnType ret = E_NOT_OK;

    sPowerPMICHandle.u16ExeCnt = 0;
    sPowerPMICHandle.sPowerSequence = 0;
    sPowerPMICHandle.sPowerState = state;
    sPowerPMICHandle.flag = 0;
    ret = E_OK;


    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void EXT_Power_ReadPmicState(POWER_STATE_t * state)
{
    *state = sPowerPMICHandle.sPowerState;
}


/********************************************* Other FUNCTION *********************************************/


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void EXT_Power_OtherPowerUp(void)
{

    if (sPowerOtherHandle.sPowerSequence == POWER_Other_POWER_UP_SATR)
    {
        Dio_WriteChannel(DioConf_DioChannel_VIP_VG1V8_M_EN, STD_HIGH);
        Dio_WriteChannel(DioConf_DioChannel_VIP_VG1V2_EN, STD_HIGH);
        Dio_WriteChannel(DioConf_DioChannel_VIP_ETN_2_5V_EN, STD_HIGH);
        Dio_WriteChannel(DioConf_DioChannel_VIP_TUNER_ANT_EN_3V3, STD_HIGH);
        Dio_WriteChannel(DioConf_DioChannel_VIP_POC_PWREN, STD_HIGH);
        Dio_WriteChannel(DioConf_DioChannel_VIP_RVC_PWREN, STD_HIGH);

        sPowerOtherHandle.sPowerSequence = POWER_Other_POWER_UP_EXT;
        sPowerOtherHandle.u16ExeCnt =0;
    }
    else if (sPowerOtherHandle.sPowerSequence == POWER_Other_POWER_UP_EXT)
    {
        Dio_WriteChannel(DioConf_DioChannel_VIP_47961_RST_3V3, STD_LOW);
        Dio_WriteChannel(DioConf_DioChannel_VIP_479XX_RST_3V3, STD_LOW);
        Dio_WriteChannel(DioConf_DioChannel_VIP_4624_RST_3V3, STD_LOW);
        Dio_WriteChannel(DioConf_DioChannel_VIP_469X_RST_3V3, STD_LOW);
        
        Dio_WriteChannel(DioConf_DioChannel_VIP_ADC_M_REST, STD_HIGH);
        Dio_WriteChannel(DioConf_DioChannel_VIP_SDARS_SHDN_3V3, STD_HIGH);
        Dio_WriteChannel(DioConf_DioChannel_VIP_ETN_1V_PWR_EN, STD_HIGH);
        Dio_WriteChannel(DioConf_DioChannel_VIP_MIC_POWER_EN_3V3, STD_HIGH);
        Dio_WriteChannel(DioConf_DioChannel_VIP_A2BPWR_EN, STD_HIGH);
        Dio_WriteChannel(DioConf_DioChannel_VIP_GPSANT_POWER_EN_3V3, STD_HIGH);
        Dio_WriteChannel(DioConf_DioChannel_VIP_SWITCH_SPI_EN, STD_HIGH);

        sPowerOtherHandle.sPowerSequence = POWER_Other_POWER_UP_WAIT;
    }
    else if (sPowerOtherHandle.sPowerSequence == POWER_Other_POWER_UP_WAIT)
    {
        sPowerOtherHandle.u16ExeCnt++;
        if (sPowerOtherHandle.u16ExeCnt == u16SDARS_RST_DelayTimer)
        {
             Dio_WriteChannel(DioConf_DioChannel_VIP_SDARS_RST_3V3, STD_HIGH);
        }
        else if (sPowerOtherHandle.u16ExeCnt == u16Tuner_DelayTimer)
        {
            Dio_WriteChannel(DioConf_DioChannel_VIP_47961_RST_3V3, STD_HIGH);
            Dio_WriteChannel(DioConf_DioChannel_VIP_479XX_RST_3V3, STD_HIGH);
            Dio_WriteChannel(DioConf_DioChannel_VIP_4624_RST_3V3, STD_HIGH);
            Dio_WriteChannel(DioConf_DioChannel_VIP_469X_RST_3V3, STD_HIGH);
            Dio_WriteChannel(DioConf_DioChannel_VIP_DSP_REST_3V3, STD_HIGH);
            sPowerOtherHandle.sPowerSequence = POWER_Other_POWER_UP_END;
        }
		else
		{
        }
    }
    else
    {
        sPowerOtherHandle.sPowerState = ePOWER_STATE_IDLE;
    }
    
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void EXT_Power_OtherManagement(void)
{
    if (sPowerOtherHandle.sPowerState == ePOWER_STATE_POWER_UP)
    {
        EXT_Power_OtherPowerUp();
    }
}


/********************************************* Basic FUNCTION *********************************************/


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void EXT_Power_BasicPowerUp(void)
{
    Dio_WriteChannel(DioConf_DioChannel_VIP_47961_RST_3V3, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_VIP_479XX_RST_3V3, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_VIP_4624_RST_3V3, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_VIP_469X_RST_3V3, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_VIP_VG3V3_VIP_EN, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_VIP_PWR_VG3V3_M_EN, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_VIP_PWR_VG5V_M_EN, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_VIP_PWR_VGBOOST_EN, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_VIP_ETN_0_9V_EN, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_VIP_PWR_VG10V_EN, STD_HIGH);

    Dio_WriteChannel(DioConf_DioChannel_VBATT_VIP_DET_EN_3V3, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_VIP_ID_EN_ODH, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_VIP_CD_EN_ODH, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_VIP_PD_EN_ODH, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_VIP_GPS_RST, STD_HIGH);

    Dio_WriteChannel(DioConf_DioChannel_VIP_HD_EN_ODH, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_VIP_ChargeEN_ODH, STD_HIGH);

    sPowerBasicState = EXT_POWER_STATUS_POWER_ON;
    sPowerOtherHandle.u16ExeCnt = 0;
    sPowerOtherHandle.sPowerSequence = 0;
    sPowerOtherHandle.sPowerState = ePOWER_STATE_POWER_UP;
//    EXT_Power_PMICReq(eSOC_POWER_REQ_POWER_UP);
}

/***********************************************************************
 * @brief       : EXT_USBWasFastCharge
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean EXT_USBWasFastCharge(void)
{
	boolean ret = FALSE;
	if((eMiscBoard_Version_C2 == hwVersionExt)||(eMiscBoard_Version_C4 == hwVersionExt))
	{
		ret = TRUE;
	}
	return ret;
}
/***********************************************************************
 * @brief       : EXT_USBWasLowCharge
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean EXT_USBWasLowCharge(void)
{
	boolean ret = FALSE;
	if((eMiscBoard_Version_C3 == hwVersionExt)||(eMiscBoard_Version_C5 == hwVersionExt))
	{
		ret = TRUE;
	}
	return ret;
}

Std_ReturnType EXT_Power_USBCtrl(void)
{
    Std_ReturnType ret = E_NOT_OK;	
	ret = Misc_Board_GetHwVersion(&hwVersionExt);
	if(E_OK == ret)
	{
		//VIP_USB1_EN modified to here
		//1.HW HSIS need USB1_EN on 23ms then enable Ctrl1/2
		//2.EXT_Power_Management call each 5*7=35ms , so this logic implication  case '1'
		Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_EN, DIO_HIGH_LEVEL_OUTPUT);
	
		//VIP_USB1_CTRL1 and VIP_USB1_CTRL2 need special deal
		if(TRUE == EXT_USBWasLowCharge())
		{
			//at version C3 , this PIN need set as input , used for  VIP_USB1_FAULT2_N check from Power IC MAX25400GTC/V
			//this pin default cfg was output
			Port_SetPinDirection(Port_PortGroup20_VIP_USB1_CTRL1,PORT_PIN_IN);
			
			//at version C3 , this VIP_USB1_CTRL1 need set as input , used for	VIP_USB1_FAULT2_N check from Power IC MAX25400GTC/V
			Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_CTRL2, DIO_HIGH_LEVEL_OUTPUT);
		}
		else if(TRUE == EXT_USBWasFastCharge())
		{
			//at version C2 , this PIN need set as output , used for EN for Power IC MPQ4228 
			Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_CTRL1, DIO_HIGH_LEVEL_OUTPUT);
			Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_CTRL2, DIO_LOW_LEVEL_OUTPUT);
		}
		else
		{
			Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_CTRL1, DIO_HIGH_LEVEL_OUTPUT);
			Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_CTRL2, DIO_HIGH_LEVEL_OUTPUT);
		}	
	}
	return ret;
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void EXT_Power_BasicPowerDown(void)
{
    sPowerBasicState = EXT_POWER_STATUS_POWER_OFF;
    Dio_WriteChannel(DioConf_DioChannel_VIP_POC_PWREN, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_RVC_PWREN, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_DSP_REST_3V3, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_47961_RST_3V3, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_479XX_RST_3V3, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_4624_RST_3V3, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_469X_RST_3V3, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_ETN_2_5V_EN, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_ADC_M_REST, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_AMP8531_EN, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_AMP8532_EN, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_SDARS_SHDN_3V3, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_ETN_1V_PWR_EN, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_MIC_POWER_EN_3V3, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_A2BPWR_EN, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_GPSANT_POWER_EN_3V3, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_SDARS_RST_3V3, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_VG1V8_M_EN, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_VG1V2_EN, STD_LOW);

    Dio_WriteChannel(DioConf_DioChannel_VIP_20098_EN, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_PWR_VG10V_EN, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_PWR_VG3V3_M_EN, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_PWR_VG5V_M_EN, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_PWR_VGBOOST_EN, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_ETN_0_9V_EN, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_EN, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_ID_EN_ODH, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_CD_EN_ODH, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_PD_EN_ODH, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_REVERSE_IRQ, STD_LOW);
	//VIP_USB1_CTRL1 and VIP_USB1_CTRL2 need special deal
	if(TRUE == EXT_USBWasLowCharge())
	{
		//at version C3 , this VIP_USB1_CTRL1 set as input , used for  VIP_USB1_FAULT2_N check from Power IC MAX25400GTC/V
		//VIP_USB1_CTRL1 don't modifeid at here
		Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_CTRL2, STD_LOW);
	}
	else if(TRUE == EXT_USBWasFastCharge())
	{
		//at version C2 , this PIN need set as output , used for EN for Power IC MPQ4228 
		Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_CTRL1, STD_LOW);
	    Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_CTRL2, STD_LOW);
	}
	else
	{
    	Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_CTRL1, STD_LOW);
	    Dio_WriteChannel(DioConf_DioChannel_VIP_USB1_CTRL2, STD_LOW);
	}
    Dio_WriteChannel(DioConf_DioChannel_VBATT_VIP_DET_EN_3V3, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_TUNER_ANT_EN_3V3, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_VG3V3_VIP_EN, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_ChargeEN_ODH, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_VIP_HD_EN_ODH, STD_LOW);

    EXT_Power_GotoSleep();
    
}




/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void EXT_Power_Management(void)
{
	static uint8 u8BasicPowerUpPatch = FALSE;
    if (sPowerBasicState == EXT_POWER_STATUS_INITIAL)
    {
        EXT_Power_BasicPowerUp();
    }
    else
    {
    	//case ADC Vref need DioConf_DioChannel_VIP_PWR_VG5V_M_EN set high first
    	if(FALSE == u8BasicPowerUpPatch)
    	{
			if(E_OK == EXT_Power_USBCtrl())
			{
				u8BasicPowerUpPatch = TRUE;
			}
		}

		EXT_Power_PMICManagement();
        EXT_Power_OtherManagement();
    }
}
