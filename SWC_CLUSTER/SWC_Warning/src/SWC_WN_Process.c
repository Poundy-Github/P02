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

/**********************************************************************************************************
*File Name   : WN_Process.c                                                                               *
*                                                                                                         *
*Description : Warning module logic process function source file.                                         *
*                                                                                                         *
*Author      :                                                                                            *
*                                                                                                         *
*Compiler    : Green Hills  [MULTI IDE 6.1.6]                                                             *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family [RH850/D1M2]                                          *
*                                                                                                         *
*Version     : 1.0.0                                                                                      *
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include <string.h>
#include "Compiler.h"
#include "Platform_Types.h"
#include "Com.h"
#include "VConfig.h"
#include "Dio.h"
#include "Rte_Common_Normal.h"
#include "IoHwAb_Cfg_RI.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_WN_Config.h"
#include "SWC_WN_Interface.h"
#include "SWC_WN_MemMap.h"
#include "SWC_WN_Adapt.h"

/**********************************************************************************************************
*                               Macro definitions                                                         *
**********************************************************************************************************/
#define WN_SET(WarningID, StatusID) WN_CFG_vSetWarningStatus(WarningID, (uint8)StatusID, stMainObject)

#define SWC_WN_START_SEC_CODE
#include "SWC_WN_MemMap.h"

#define WN_TASK_TIME 20

#define ELECTRICAL_LOW 0x00
#define ELECTRICAL_HIGH 0x01
#define ELECTRICAL_INVALID 0x02

/**********************************************************************************************************
*                               Private Member                                                            *
**********************************************************************************************************/
#define SWC_WN_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_WN_MemMap.h"
static uint8 m_u8OBC_ConnectSts_pre = 0;
static uint8 m_u8BMS_StsCC2Line_pre = 0;
//static uint8 m_u8LasHdLightSts_PBOX_pre = 0;
static uint8 m_VCU_OPDSt_pre = 0;
//static uint8 m_PreLLasHdLmpSts = 0;
//static uint8 m_PreRLasHdLmpSts = 0;
static uint8 m_PreTSM_Trailer = 0;
static uint8 m_PreAutoLmpSts = 0;

static uint8 PIN_C3_DurationTime = 0;
static uint16 PIN_C4_DurationTime = 0;
static uint8 AcBr_Signal_DurationTime = 0;
static uint8 KL15On_DelayCount = 0;
static boolean KL15On_DelayEndSts = FALSE;
static uint8 PreACAmbTemp_temp = 0;
static WN_CFG_enSTATUS_Common m_enCruiseSpeed = WN_enDISPLAY_OFF;
static WN_CFG_enSTATUS_Common m_enOverSpeedLevel_1_pre = WN_enDISPLAY_OFF;
static WN_CFG_enSTATUS_Common m_enOverSpeedLevel_2_pre = WN_enDISPLAY_OFF;
static WN_CFG_enSTATUS_Common m_enDynamicBatteryLow = WN_enDISPLAY_OFF;
static WN_CFG_enSTATUS_Common m_enOverSpeedWarning = WN_enDISPLAY_OFF;
static WN_CFG_enSTATUS_Common m_enOutTempLow = WN_enDISPLAY_OFF;
//static WN_CFG_enSTATUS_Common m_enLasHdLightOn = WN_enDISPLAY_OFF;
//static WN_CFG_enSTATUS_Common m_enLasHdLightOff = WN_enDISPLAY_OFF;
static WN_CFG_enSTATUS_Common m_enTmsTrailerOn = WN_enDISPLAY_OFF;
static WN_CFG_enSTATUS_Common m_enTmsTrailerOff = WN_enDISPLAY_OFF;
static WN_CFG_enSTATUS_Common m_enAutoLmpStsOn = WN_enDISPLAY_OFF;
static WN_CFG_enSTATUS_Common m_enAutoLmpStsOff = WN_enDISPLAY_OFF;
static WN_CFG_enSTATUS_Common m_enElecShifterFault = WN_enDISPLAY_OFF;
//static WN_CFG_enSTATUS_Common m_enFarBeamOn = WN_enDISPLAY_OFF;
//static WN_CFG_enSTATUS_Common m_enFarBeamOff = WN_enDISPLAY_OFF;
static WN_CFG_enSTATUS_Common m_enFrontTireAlignFinish = WN_enDISPLAY_OFF;
static WN_CFG_enSTATUS_Common m_enNOHExitPlsTake = WN_enDISPLAY_OFF;
static WN_CFG_enSTATUS_Common m_enNOHExit = WN_enDISPLAY_OFF;
static uint8 m_CruiseSpeedData = 0;
static uint8 m_CruiseSpeedDataVld = FALSE;
static uint8 m_CruiseSpeedData_last = 0;
static uint8 m_DrvModeCase = 0;
static uint32 m_PowerModeStatus = 0;
//static uint8 m_LasHdLightSignalInit = FALSE;
static boolean m_OutTempLowInit = FALSE;
static boolean m_TSM_TrailerSignalInit = FALSE;
static boolean m_AutoLmpStsSignalInit = FALSE;
//static uint8 m_LasHdLmpStsSignalInit = FALSE;
static uint16 m_NOH_DistanceToExit = 0;
static uint8 m_ACC_SpeedSetValue = 0;
static uint8 m_V2XFrontRoadData = 0;
static uint8 m_TrailerhookSts_last = 0;
static boolean m_FrontTireAlignFinish_Flag = FALSE;
static uint16 m_UreaRemainDist = 0x0;//R15
static uint8 m_CST_Status_pre = 0;//R15
static uint8 m_PIN_C1_temp_pre = 0;//Log
static uint8 m_PIN_C3_temp_pre = 0;//Log
static uint8 m_PIN_C4_temp_pre = 0;//Log
//上一次超速报警阈值
static uint16 m_Set_Overspeed_Pre = 0;
//上一次单位设置值
static uint8 m_UnitChange_Pre = 0;
static uint16 l_NOH_DistanceToExit = 0;
static uint16 l_NOH_DistanceToExit_last = 0;
static uint8 NOH_Count = 0;
static uint8 NOH_Count1 = 0;
static uint8 l_NOH_SysInfoDisplay_last_U8 = 0;
static uint8 m_PressReliProgsData = 0;
static boolean m_FuelPrepareSoundFlag = FALSE;
/**********************************************************************************************************
*                               Local Configuration                                                       *
**********************************************************************************************************/
static uint16 WN_LowOilPressure_telltales_DelayTime = 0; //uint: 0.1s
static uint16 WN_BrakeFault_DelayTime = 0;               //uint: ms
static uint16 WN_AccelBrakeWrnDelayTime = 0;             //uint: 0.1s
#define SWC_WN_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_WN_MemMap.h"
/**********************************************************************************************************
*                               EOL Configuration                                                     *
**********************************************************************************************************/
void WN_ReadVehCfgProcess(void)
{
    //Hard signal
    uint8 PIN_C1_temp = ELECTRICAL_INVALID;
    uint8 PIN_C3_temp = ELECTRICAL_INVALID;
    uint8 PIN_C4_temp = ELECTRICAL_INVALID;
    m_PowerModeStatus = WN_CFG_vGetPowerModeSts();

    WN_LowOilPressure_telltales_DelayTime = (uint16)WN_GetSingleConfig(WN_enCfg_LowOilPressure_telltales_DelayTime);
    WN_LowOilPressure_telltales_DelayTime = (uint16)(WN_LowOilPressure_telltales_DelayTime * 100u); //uint: ms
    WN_BrakeFault_DelayTime = (uint16)WN_GetSingleConfig(WN_enCfg_BrakeFault_DelayTime);
    WN_AccelBrakeWrnDelayTime = (uint16)WN_GetSingleConfig(WN_enCfg_AccelBrakeWrnDelayTime);
    WN_AccelBrakeWrnDelayTime = (uint16)(WN_AccelBrakeWrnDelayTime * 100u); //uint: ms
    
    if (m_PowerModeStatus == WN_enRUN)
    {
        if (KL15On_DelayCount < (3000 / WN_TASK_TIME))
        {
            KL15On_DelayCount++;
            KL15On_DelayEndSts = FALSE;
        }
        else
        {
            KL15On_DelayEndSts = TRUE;
        }
    }
    else
    {
        KL15On_DelayCount = 0;
        KL15On_DelayEndSts = FALSE;
    }
    
    WN_PIN_C1_IOGet(&PIN_C1_temp);
    WN_PIN_C3_IOGet(&PIN_C3_temp);
    WN_PIN_C4_IOGet(&PIN_C4_temp);

    if(m_PIN_C1_temp_pre != PIN_C1_temp)
    {
        (void)SWC_WN_PRINT_WARN("Security Immobilzer PIN_C1 = %d",PIN_C1_temp);
    }
    if(m_PIN_C3_temp_pre != PIN_C3_temp)
    {
        (void)SWC_WN_PRINT_WARN("Oil pressure low PIN_C3 = %d",PIN_C3_temp);
    }
    if(m_PIN_C4_temp_pre != PIN_C4_temp)
    {
        (void)SWC_WN_PRINT_WARN("Braking system fail PIN_C4 = %d",PIN_C4_temp);
    }

    m_PIN_C1_temp_pre = PIN_C1_temp;
    m_PIN_C3_temp_pre = PIN_C3_temp;
    m_PIN_C4_temp_pre = PIN_C4_temp;
    
}
void WN_CFG_vSetWarningStatus(WN_CFG_enWarningID enWarningID, uint8 u8LogicStatus, WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    if (enWarningID < WN_enWARNING_TOTAL_NUMBER)
    {
        stMainObject->stWarningControlStatus[enWarningID].unStatus.stStatus.LogicType = u8LogicStatus;
    }
    else
    {
        //Do nothing because request warning ID out of bound
    }
}
/**********************************************************************************************************
*                               Warning Process                                                           *
**********************************************************************************************************/
void WN_EngineTempHighProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enEngTmpHigh = WN_enDISPLAY_OFF;

    //Byte42 Bit7-bit3
    uint8 configEngCtrolUnit = 0;

    //ECM3 0x371
    boolean EngClntTempWarn_temp = FALSE;
    uint8 Rte_EngClntTempWarn = RTE_E_INVALID;

    configEngCtrolUnit = (uint8)WN_GetSingleConfig(WN_enCfg_EngCtrolUnit);

    Rte_EngClntTempWarn = WN_EngClntTempWarn_SignalGet(&EngClntTempWarn_temp);

    if ((configEngCtrolUnit == 1) || (configEngCtrolUnit == 2) ||
        (configEngCtrolUnit == 3) || (configEngCtrolUnit == 4) ||
        (configEngCtrolUnit == 5) || (configEngCtrolUnit == 6) ||
        (configEngCtrolUnit == 7))
    {
        if ((RTE_E_OK == Rte_EngClntTempWarn) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_EngClntTempWarn))
        {
            //1.2
            if (EngClntTempWarn_temp == TRUE)
            {
                enEngTmpHigh = WN_enDISPLAY_ON;
            }
        }
    }
    WN_SET(WN_enEngWaterTempHigh, enEngTmpHigh);
}
void WN_TargetCruiseSpeedProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{

    //Byte28 Bit7-bit4
    uint8 configCruiseControl = 0;
    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;

    //ECM2 0x271 20ms
    uint8 CruiseCtrlSts_temp = 0;
    uint8 Rte_CruiseCtrlSts = RTE_E_INVALID;
    uint8 TgtCrsVehSpd_temp = 0;
    uint8 Rte_TgtCrsVehSpd = RTE_E_INVALID;
    //ECM_PT7 0x117 20ms
    uint8 CruiseCtrlSts_PHEV_temp = 0;
    uint8 Rte_CruiseCtrlSts_PHEV = RTE_E_INVALID;
    //VCU_FD1 0x0B5 10ms TBD
    uint8 VCU_CrsCtrlSts_temp = 0;
    uint8 VCU_CrsSpd_temp = 0;
    uint8 Rte_VCU_CrsCtrlSts = RTE_E_INVALID;
    uint8 Rte_VCU_CrsSpd = RTE_E_INVALID;
    uint8 MenuUnit = 0;
    MenuSetData_t MenuSetData_Tmp = {0};

    configCruiseControl = (uint8)WN_GetSingleConfig(WN_enCfg_CruiseControl);
    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);

    Rte_CruiseCtrlSts = WN_CruiseCtrlSts_SignalGet(&CruiseCtrlSts_temp);
    Rte_TgtCrsVehSpd = WN_TgtCrsVehSpd_SignalGet(&TgtCrsVehSpd_temp);
    Rte_CruiseCtrlSts_PHEV = WN_CruiseCtrlSts_PHEV_SignalGet(&CruiseCtrlSts_PHEV_temp);
    Rte_VCU_CrsCtrlSts = WN_VCU_CrsCtrlSts_SignalGet(&VCU_CrsCtrlSts_temp);//R18
    Rte_VCU_CrsSpd = WN_VCU_CrsSpd_SignalGet(&VCU_CrsSpd_temp);//R18
    WN_MenuSetData_APIGet(&MenuSetData_Tmp);
    MenuUnit = MenuSetData_Tmp.OdometerUnit;

    //传统燃油或者P0  1.3
    if ((configCruiseControl == 1) &&
        ((configFuel == 0) || (configFuel == 1) || (configFuel == 2) || (configFuel == 7)))
    {
        if (m_PowerModeStatus == WN_enRUN)
        {
            if ((RTE_E_OK == Rte_CruiseCtrlSts) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_CruiseCtrlSts))
            {
                if (CruiseCtrlSts_temp == 0x01)
                {
                    if ((MenuUnit == 0) || (MenuUnit == 1))
                    {
                        if ((TgtCrsVehSpd_temp >= 1) && (TgtCrsVehSpd_temp <= 240))
                        {
                            if(TgtCrsVehSpd_temp != m_CruiseSpeedData_last)
                            {
                                m_enCruiseSpeed = WN_enDISPLAY_ON;
                                m_CruiseSpeedData = TgtCrsVehSpd_temp;
                            }
                            else
                            {
                                /* do nothing */
                            }
                            m_CruiseSpeedData_last = TgtCrsVehSpd_temp;
                        }
                        else
                        {
                            m_enCruiseSpeed = WN_enDISPLAY_OFF;
                        }
                    }
                    if ((MenuUnit == 2) || (MenuUnit == 3))
                    {
                        if ((TgtCrsVehSpd_temp >= 1) && (TgtCrsVehSpd_temp <= 150))
                        {
                            if(TgtCrsVehSpd_temp != m_CruiseSpeedData_last)
                            {
                                m_enCruiseSpeed = WN_enDISPLAY_ON;
                                m_CruiseSpeedData = TgtCrsVehSpd_temp;
                            }
                            else
                            {
                                /* do nothing */
                            }
                            m_CruiseSpeedData_last = TgtCrsVehSpd_temp;
                        }
                        else
                        {
                            m_enCruiseSpeed = WN_enDISPLAY_OFF;
                        }
                    }
                }
                else
                {
                    m_enCruiseSpeed = WN_enDISPLAY_OFF;
                    m_CruiseSpeedData = 0;
                    m_CruiseSpeedData_last = 0;
                }
            }
            else
            {
                m_enCruiseSpeed = WN_enDISPLAY_OFF;
                m_CruiseSpeedData = 0xFF;
                m_CruiseSpeedData_last = 0;
            }
        }
        else
        {
            m_enCruiseSpeed = WN_enDISPLAY_OFF;
            m_CruiseSpeedData_last = 0;
        }
    }
    //PHEV/HEV+P2/P2+P4/PS/纵置P2 1.4
    if ((configCruiseControl == 1) &&
        (((configFuel == 3) || (configFuel == 4)) && 
        ((configElecPosition == 2) || (configElecPosition == 4) || (configElecPosition == 5) || (configElecPosition == 8))))
    {
        if (m_PowerModeStatus == WN_enRUN)
        {
            if (((RTE_E_OK == Rte_CruiseCtrlSts_PHEV) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_CruiseCtrlSts_PHEV)) && 
                ((RTE_E_OK == Rte_TgtCrsVehSpd) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_TgtCrsVehSpd)))
            {
                if ((CruiseCtrlSts_PHEV_temp == 0x02) || (CruiseCtrlSts_PHEV_temp == 0x03) ||
                    (CruiseCtrlSts_PHEV_temp == 0x04) || (CruiseCtrlSts_PHEV_temp == 0x05) ||
                    (CruiseCtrlSts_PHEV_temp == 0x06) || (CruiseCtrlSts_PHEV_temp == 0x07) ||
                    (CruiseCtrlSts_PHEV_temp == 0x08))
                {
                    if ((MenuUnit == 0) || (MenuUnit == 1))
                    {
                        if ((TgtCrsVehSpd_temp >= 1) && (TgtCrsVehSpd_temp <= 240))
                        {
                            if(TgtCrsVehSpd_temp != m_CruiseSpeedData_last)
                            {
                                m_enCruiseSpeed = WN_enDISPLAY_ON;
                                m_CruiseSpeedData = TgtCrsVehSpd_temp;
                            }
                            else
                            {
                                /* do nothing */
                            }
                            m_CruiseSpeedData_last = TgtCrsVehSpd_temp;
                        }
                        else
                        {
                            m_enCruiseSpeed = WN_enDISPLAY_OFF;
                        }
                    }
                    if ((MenuUnit == 2) || (MenuUnit == 3))
                    {
                        if ((TgtCrsVehSpd_temp >= 1) && (TgtCrsVehSpd_temp <= 150))
                        {
                            if(TgtCrsVehSpd_temp != m_CruiseSpeedData_last)
                            {
                                m_enCruiseSpeed = WN_enDISPLAY_ON;
                                m_CruiseSpeedData = TgtCrsVehSpd_temp;
                            }
                            else
                            {
                                /* do nothing */
                            }
                            m_CruiseSpeedData_last = TgtCrsVehSpd_temp;
                        }
                        else
                        {
                            m_enCruiseSpeed = WN_enDISPLAY_OFF;
                        }
                    }
                }
                else
                {
                    m_enCruiseSpeed = WN_enDISPLAY_OFF;
                    m_CruiseSpeedData = 0;
                    m_CruiseSpeedData_last = 0;
                }
            }
            else
            {
                m_enCruiseSpeed = WN_enDISPLAY_OFF;
                m_CruiseSpeedData = 0xFF;
                m_CruiseSpeedData_last = 0;
            }
        }
        else
        {
            m_enCruiseSpeed = WN_enDISPLAY_OFF;
            m_CruiseSpeedData_last = 0;
        }
    }

    //EV  1.5
    if (((configCruiseControl == 1) || (configCruiseControl == 12)) && (configFuel == 5))
    {
        if ((VCU_CrsCtrlSts_temp == 0x02) && (VCU_CrsSpd_temp <= 0x78))
        {
            m_enCruiseSpeed = WN_enDISPLAY_ON;
            m_CruiseSpeedData = VCU_CrsSpd_temp;
        }
    }

    WN_SET(WN_enTargetCruiseSpeed, m_enCruiseSpeed);
}
void WN_AutoStartStopProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enAutoStartStop = WN_enDISPLAY_OFF;

    //Byte4 Bit1-bit0
    uint8 configIdleStopAndGo = 0;

    //ECM3 0x371
    uint8 SS_Screen_tip_temp = 0;
    uint8 Rte_SS_Screen_tip = RTE_E_INVALID;

    configIdleStopAndGo = (uint8)WN_GetSingleConfig(WN_enCfg_IdleStopAndGo);

    Rte_SS_Screen_tip = WN_SS_Screen_tip_SignalGet(&SS_Screen_tip_temp);

    if (configIdleStopAndGo == 1)
    {
        if ((RTE_E_OK == Rte_SS_Screen_tip) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SS_Screen_tip))
        {
            //1.6
            if (SS_Screen_tip_temp == 0x1)
            {
                enAutoStartStop = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enAutoStartStop, enAutoStartStop);
}
void WN_LowOilPressureProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enLowOilPressure = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enLowOilPressurePIN = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enLowOilPressureCAN = WN_enDISPLAY_OFF;

    //Byte42 Bit7-bit3
    uint8 configEngCtrolUnit = 0;
    //Byte92 Bit1-bit0
    uint8 configLowOilPressInput = 0;

    //发动机运行状态，取自内部转速模块
    uint8 EngRun_Sts = 0;
    s_TachoInfo_t TachoInfo_Tmp = {0};

    //Hard signal
    uint8 PIN_C3 = ELECTRICAL_INVALID;
    //P05 DBC 4.0 add
    uint8 EngOilLowPresWrn_temp = 0;
    uint8 Rte_EngOilLowPresWrn = RTE_E_INVALID;

    configEngCtrolUnit = (uint8)WN_GetSingleConfig(WN_enCfg_EngCtrolUnit);
    configLowOilPressInput = (uint8)WN_GetSingleConfig(WN_enCfg_Eng_oil_display);
	Rte_EngOilLowPresWrn = WN_ECM24_EngOilLowPresWrn_SignalGet(&EngOilLowPresWrn_temp);

    WN_PIN_C3_IOGet(&PIN_C3);

    WN_TachoInfo_APIGet(&TachoInfo_Tmp);
    EngRun_Sts = TachoInfo_Tmp.EngRunSts;

    if ((EngRun_Sts == 0x1) && (PIN_C3 == ELECTRICAL_LOW))
    {
        if ((PIN_C3_DurationTime < (WN_LowOilPressure_telltales_DelayTime / WN_TASK_TIME)))
        {
            PIN_C3_DurationTime++;
        }
    }
    else
    {
        PIN_C3_DurationTime = 0;
    }

    if ((configEngCtrolUnit == 1) || (configEngCtrolUnit == 2) ||
        (configEngCtrolUnit == 3) || (configEngCtrolUnit == 4) ||
        (configEngCtrolUnit == 5) || (configEngCtrolUnit == 6) ||
        (configEngCtrolUnit == 7))
    {
        //1.7
        if ((EngRun_Sts == 0x1) && (PIN_C3 == ELECTRICAL_LOW) &&
            (PIN_C3_DurationTime >= (WN_LowOilPressure_telltales_DelayTime / WN_TASK_TIME)))
        {
            enLowOilPressurePIN = WN_enDISPLAY_ON;
        }
    }
    if (configLowOilPressInput == 1)
    {
		//1.246
		if ((RTE_E_OK == Rte_EngOilLowPresWrn) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_EngOilLowPresWrn))
		{
			if(EngOilLowPresWrn_temp == 1)
	        {
	            enLowOilPressureCAN = WN_enDISPLAY_ON;
	        }
		}
    }
    if ((WN_enDISPLAY_ON == enLowOilPressurePIN) || (WN_enDISPLAY_ON == enLowOilPressureCAN))
    {
        enLowOilPressure = WN_enDISPLAY_ON;
    }

    WN_SET(WN_enLowOilPressure, enLowOilPressure);
}
void WN_StatBattLowProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enTranMode = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enComfortOff = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSavingMode = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enStartUp = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPwrReduce = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enPowerOffAfterThreeMinute = WN_enDISPLAY_OFF;

    //Byte37 Bit3-bit2
    uint8 configElecEnManagement = 0;
	
	//Byte80 Bit7-bit6
	uint8 configCentralModule = 0;

	//Byte123 Bit1-bit0
	uint8 configAutomaticPowerDownControl = 0;

    //EEM1 0x2A8
    boolean TranPMode_Sts_temp = FALSE;
    uint8 LvPwrSysErr_temp = 0;
    uint8 Stat_PwrSv_Lvl_temp = 0;
    uint8 Dyn_PwrSv_Lvl_temp = 0;
    uint8 Rte_EEM1Sts = RTE_E_INVALID;

    configElecEnManagement = (uint8)WN_GetSingleConfig(WN_enCfg_ElecEnManagement);
    configCentralModule = (uint8)WN_GetSingleConfig(WN_enCfg_CentralModule);
	configAutomaticPowerDownControl = (uint8)WN_GetSingleConfig(WN_encfg_AutomaticPowerDownControl);

    Rte_EEM1Sts = WN_TranPMode_Sts_SignalGet(&TranPMode_Sts_temp);
    Rte_EEM1Sts = WN_LvPwrSysErr_SignalGet(&LvPwrSysErr_temp);
    Rte_EEM1Sts = WN_Stat_PwrSv_Lvl_SignalGet(&Stat_PwrSv_Lvl_temp);
    Rte_EEM1Sts = WN_Dyn_PwrSv_Lvl_SignalGet(&Dyn_PwrSv_Lvl_temp);

    if (((configElecEnManagement == 1) || (configElecEnManagement == 2)) && \
		((configCentralModule == 0) || (configCentralModule == 1)))
    {
        if ((RTE_E_OK == Rte_EEM1Sts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_EEM1Sts))
        {
            //1.8
            if (TranPMode_Sts_temp == TRUE)
            {
                enTranMode = WN_enDISPLAY_ON;
            }
            else if ((TranPMode_Sts_temp == FALSE) && (LvPwrSysErr_temp == 0x01))
            {
                enComfortOff = WN_enDISPLAY_ON;
            }
            else if ((TranPMode_Sts_temp == FALSE) && (LvPwrSysErr_temp == 0x00) && (Stat_PwrSv_Lvl_temp == 0x01))
            {
                enSavingMode = WN_enDISPLAY_ON;
            }	         
            else if ((TranPMode_Sts_temp == FALSE) && (LvPwrSysErr_temp == 0x00) && (Stat_PwrSv_Lvl_temp == 0x00) &&
                     ((Dyn_PwrSv_Lvl_temp == 0x04) || (Dyn_PwrSv_Lvl_temp == 0x05)))
            {
                enPwrReduce = WN_enDISPLAY_ON;
            }
            else
            {
            }

			if (configAutomaticPowerDownControl == 0)    
            {
            	//case1
                if ((TranPMode_Sts_temp == FALSE) && (LvPwrSysErr_temp == 0x00) && (Stat_PwrSv_Lvl_temp == 0x02))
	            {
	                enStartUp = WN_enDISPLAY_ON;
	            }
				else
				{
				}
            }
			else if (configAutomaticPowerDownControl == 1)
			{	
				//case2
				if ((TranPMode_Sts_temp == FALSE) && (LvPwrSysErr_temp == 0x00) && (Stat_PwrSv_Lvl_temp == 0x02))
	            {
	                enPowerOffAfterThreeMinute = WN_enDISPLAY_ON;
	            }
				else
				{
				}
			}
			else
			{
			}
        }
    }

    WN_SET(WN_enStatBattLowTranMode, enTranMode);
    WN_SET(WN_enStatBattLowComfortOff, enComfortOff);
    WN_SET(WN_enStatBattLowSavingMode, enSavingMode);
    WN_SET(WN_enStatBattLowStartUp, enStartUp);
    WN_SET(WN_enStatBattLowPwrReduce, enPwrReduce);
	WN_SET(WN_enPowerOffAfterThreeMinute,enPowerOffAfterThreeMinute);
}
void WN_ESPFD2Process(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enHDCLimited = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAutoholdLimited = WN_enDISPLAY_OFF;

    //Byte31 Bit2-bit0
    uint8 configUpDownHill = 0;
    //Byte33 Bit7-bit6
    uint8 configAVH = 0;

    //ESP_FD2 0x137 20ms
    //ESP2 0x145 20ms
    uint8 HDCFault_temp = 0;
    uint8 AVHErrSts_temp = 0;
    uint8 Rte_SG_ESP2_Tmp = RTE_E_INVALID;
    uint8 Rte_SG_ESP2_ESP_FD2_Tmp = RTE_E_INVALID;

    configUpDownHill = (uint8)WN_GetSingleConfig(WN_enCfg_UpDownHill);
    configAVH = (uint8)WN_GetSingleConfig(WN_enCfg_AVH);

    if (EolConfig_Trans_CANFD())
    {
        Rte_SG_ESP2_ESP_FD2_Tmp = WN_HDCFaultFD_SignalGet(&HDCFault_temp);
        Rte_SG_ESP2_ESP_FD2_Tmp = WN_AVHErrStsFD_SignalGet(&AVHErrSts_temp);
    }
    else
    {
        Rte_SG_ESP2_Tmp = WN_HDCFault_SignalGet(&HDCFault_temp);
        Rte_SG_ESP2_Tmp = WN_AVHErrSts_SignalGet(&AVHErrSts_temp);
    }

    if ((RTE_E_OK == Rte_SG_ESP2_Tmp) ||
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ESP2_Tmp) ||
        (RTE_E_OK == Rte_SG_ESP2_ESP_FD2_Tmp) ||
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ESP2_ESP_FD2_Tmp))
    {
        if ((configUpDownHill == 2) || (configUpDownHill == 3))
        {
            //1.9
            if (HDCFault_temp == 0x1)
            {
                enHDCLimited = WN_enDISPLAY_ON;
            }
        }
        if (configAVH == 1)
        {
            //1.10
            if (AVHErrSts_temp == 0x1)
            {
                enAutoholdLimited = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enHDCLimited, enHDCLimited);
    WN_SET(WN_enAutoholdLimited, enAutoholdLimited);
}
void WN_EPBWarningProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enGradientHigh = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enClampForce = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enParkSystem = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enFastenSeatbelt = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enReleaseElecPark = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enReleaseRearELD = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enCalibreHeatTabLimit = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSwitchGearReleaseBrake = WN_enDISPLAY_OFF;
	
    //Byte26 Bit7-bit5
    uint8 configParkingBrake = 0;
    //Byte44 Bit1-bit0
    uint8 configTab = 0;

    //EPB1 0x16B 20ms
    uint8 EPBTextDisp_temp = 0;
    uint8 Rte_SG_EPB1_Tmp = RTE_E_INVALID;

    configParkingBrake = (uint8)WN_GetSingleConfig(WN_enCfg_ParkingBrake);
    configTab = (uint8)WN_GetSingleConfig(WN_enCfg_Tab);

    Rte_SG_EPB1_Tmp = WN_EPBTextDisp_SignalGet(&EPBTextDisp_temp);

    if ((RTE_E_OK == Rte_SG_EPB1_Tmp) ||
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_EPB1_Tmp))
    {
        if (configParkingBrake == 2)
        {
            //1.11
            if (EPBTextDisp_temp == 0x1)
            {
                enGradientHigh = WN_enDISPLAY_ON;
            }
            else if (EPBTextDisp_temp == 0x2)
            {
                enClampForce = WN_enDISPLAY_ON;
            }
            else if (EPBTextDisp_temp == 0x3)
            {
                enParkSystem = WN_enDISPLAY_ON;
            }
            else if (EPBTextDisp_temp == 0x4)
            {
                enFastenSeatbelt = WN_enDISPLAY_ON;
            }
            else if (EPBTextDisp_temp == 0x9)//R12
            {
                enSwitchGearReleaseBrake = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
        if ((configParkingBrake == 2) && (configTab == 1))
        {
            Rte_SG_EPB1_Tmp = WN_EPBTextDispTab_SignalGet(&EPBTextDisp_temp);
            //1.76
            if (EPBTextDisp_temp == 0x7)
            {
                enReleaseElecPark = WN_enDISPLAY_ON;
            }
            else if (EPBTextDisp_temp == 0x8)
            {
                enReleaseRearELD = WN_enDISPLAY_ON;
            }
            else if (EPBTextDisp_temp == 0xA)//R13 change
            {
                enCalibreHeatTabLimit = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
    }

    WN_SET(WN_enGradientHighWarning, enGradientHigh);
    WN_SET(WN_enClampForceWarning, enClampForce);
    WN_SET(WN_enParkSysWarning, enParkSystem);
    WN_SET(WN_enFastenSeatbelt, enFastenSeatbelt);
    WN_SET(WN_enReleaseElecPark, enReleaseElecPark);
    WN_SET(WN_enReleaseRearELD, enReleaseRearELD);
    WN_SET(WN_enCalibreHeatTabLimit, enCalibreHeatTabLimit);
    WN_SET(WN_enSwitchGearReleaseBrake, enSwitchGearReleaseBrake);
	
}
void WN_BrakeSysFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enBrakeSystemFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enBrakeSwitchFault = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;
    //Byte26 Bit4-bit0
    uint8 configABS_EBD = 0;

    //ECM1 0x111 10ms
    uint8 EngSpdVldty_temp = 0;
    uint8 Rte_EngSpdVldty = RTE_E_INVALID;
    //HCU_PT7 0x248 50ms
    boolean HCU_RdyLmpSts_temp = FALSE;
    uint8 Rte_SG_HCU_PT7_Tmp = RTE_E_INVALID;
    //VCU_FD4 0x2D6 TBD
    uint8 VCU_RdyLEDSts_temp = 0;
    //uint8 Rte_VCU_RdyLEDSts = RTE_E_INVALID;
    uint8 fl_BrkFldWarn = 0;//R12 TBD
    //uint8 Rte_BrkFldWarn = RTE_E_INVALID;

    //Hard signal
    uint8 PIN_C4 = ELECTRICAL_INVALID;

    //Shared value
    uint8 EngSpd_Sts = 0;
    s_TachoInfo_t TachoInfo_Tmp = {0};

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);
    configABS_EBD = (uint8)WN_GetSingleConfig(WN_enCfg_ABS_EBD);

    WN_PIN_C4_IOGet(&PIN_C4);

    WN_TachoInfo_APIGet(&TachoInfo_Tmp);
    EngSpd_Sts = TachoInfo_Tmp.EngRunSts;

    Rte_EngSpdVldty = WN_EngSpdVldty_SignalGet(&EngSpdVldty_temp);
    Rte_SG_HCU_PT7_Tmp = WN_HCU_RdyLmpSts_SignalGet(&HCU_RdyLmpSts_temp);
    //Rte_VCU_RdyLEDSts = Rte_Read_Common_Normal_EngSpdVldty_EngSpdVldty(&EngSpdVldty);

    //传统动力燃油
    // P0  1.12
    if((configABS_EBD == 0x00) || (configABS_EBD == 0x01) || (configABS_EBD == 0x02))//ABS/ESP Cfg (R17)
    {
        //case 1
        if ((configFuel == 0) || (configFuel == 1) || (configFuel == 2) || (configFuel == 7))
        {
            if ((EngSpd_Sts == 0x1) && (PIN_C4 == ELECTRICAL_LOW) && (m_PowerModeStatus == WN_enRUN))
            {
                if (PIN_C4_DurationTime < (WN_BrakeFault_DelayTime / WN_TASK_TIME))
                {
                    PIN_C4_DurationTime++;
                }
            }
            else
            {
                PIN_C4_DurationTime = 0;
            }
            if ((RTE_E_OK == Rte_EngSpdVldty) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_EngSpdVldty))
            {
                if ((PIN_C4 == ELECTRICAL_LOW) && (EngSpd_Sts == 0x1) &&
                    (PIN_C4_DurationTime >= (WN_BrakeFault_DelayTime / WN_TASK_TIME)))
                {
                    enBrakeSystemFault = WN_enDISPLAY_ON;
                }
            }
        }

        //PHEV/HEV+P2/P2+P4/PS  1.13
        if (((configFuel == 3) || (configFuel == 4)) && 
            ((configElecPosition == 2) ||  
            (configElecPosition == 3) || 
            (configElecPosition == 4) || 
            (configElecPosition == 5) || 
            (configElecPosition == 6) || 
            (configElecPosition == 8)))
        {
            if ((RTE_E_OK == Rte_SG_HCU_PT7_Tmp) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_HCU_PT7_Tmp))
            {
                if ((HCU_RdyLmpSts_temp == TRUE) && (PIN_C4 == ELECTRICAL_LOW) && (m_PowerModeStatus == WN_enRUN))
                {
                    if (PIN_C4_DurationTime < (WN_BrakeFault_DelayTime / WN_TASK_TIME))
                    {
                        PIN_C4_DurationTime++;
                    }
                }
                else
                {
                    PIN_C4_DurationTime = 0;
                }
                if (PIN_C4_DurationTime >= (WN_BrakeFault_DelayTime / WN_TASK_TIME))
                {
                    enBrakeSystemFault = WN_enDISPLAY_ON;
                }
            }
            else
            {
                PIN_C4_DurationTime = 0;
            }
        }
        //EV  1.14
        if (configFuel == 5)
        {
            if (0)
            {
                if ((VCU_RdyLEDSts_temp == 0x1) && (PIN_C4 == ELECTRICAL_LOW) && (m_PowerModeStatus == WN_enRUN))
                {
                    if (PIN_C4_DurationTime < (WN_BrakeFault_DelayTime / WN_TASK_TIME))
                    {
                        PIN_C4_DurationTime++;
                    }
                }
                else
                {
                    PIN_C4_DurationTime = 0;
                }
                if (PIN_C4_DurationTime >= (WN_BrakeFault_DelayTime / WN_TASK_TIME))
                {
                    enBrakeSystemFault = WN_enDISPLAY_ON;
                }
            }
        }
    }
    if(configABS_EBD == 0x03)//IBC Cfg
    {
        //1.12 case 2
        if ((configFuel == 0) || (configFuel == 1) || (configFuel == 2) || (configFuel == 7))
        {
            if(0)
            {
                if((EngSpdVldty_temp == 1) && (EngSpd_Sts == 0x1))
                {
                    if(fl_BrkFldWarn == 1)
                    {
                        enBrakeSystemFault = WN_enDISPLAY_ON;
                    }
                    else if(fl_BrkFldWarn == 2)
                    {
                        enBrakeSwitchFault = WN_enDISPLAY_ON;
                    }
                    else
                    {}
                }
            }
        }
        //1.13
        if (((configFuel == 3) || (configFuel == 4)) && 
            ((configElecPosition == 2) ||  
            (configElecPosition == 3) || 
            (configElecPosition == 4) || 
            (configElecPosition == 5) || 
            (configElecPosition == 6) || 
            (configElecPosition == 8)))
        {
            if(0)
            {
                if(HCU_RdyLmpSts_temp == 1)
                {
                    if(fl_BrkFldWarn == 1)
                    {
                        enBrakeSystemFault = WN_enDISPLAY_ON;
                    }
                    else if(fl_BrkFldWarn == 2)
                    {
                        enBrakeSwitchFault = WN_enDISPLAY_ON;
                    }
                    else
                    {}
                }
            }
        }
        //1.14
        if (configFuel == 5)
        {
            if(0)
            {
                if(VCU_RdyLEDSts_temp == 1)
                {
                    if(fl_BrkFldWarn == 1)
                    {
                        enBrakeSystemFault = WN_enDISPLAY_ON;
                    }
                    else if(fl_BrkFldWarn == 2)
                    {

                    }
                    else
                    {}
                }
            }
        }
    }

    WN_SET(WN_enBrakeSysFault, enBrakeSystemFault);
    WN_SET(WN_enBrakeSwitchFault, enBrakeSwitchFault);
}
void WN_StepBrakePedalProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enStepBrakePedal = WN_enDISPLAY_OFF;

    //Byte26 Bit7-bit5
    uint8 configParkingBrake = 0;

    //EPB1 0x16B 20ms
    uint8 PressBrakePedalPointOut_temp = 0;
    uint8 Rte_SG_EPB1_Tmp = RTE_E_INVALID;

    configParkingBrake = (uint8)WN_GetSingleConfig(WN_enCfg_ParkingBrake);

    Rte_SG_EPB1_Tmp = WN_PressBrakePedalPointOut_SignalGet(&PressBrakePedalPointOut_temp);

    if (configParkingBrake == 2)
    {
        //1.15
        if ((RTE_E_OK == Rte_SG_EPB1_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_EPB1_Tmp))
        {
            if (PressBrakePedalPointOut_temp == 0x1)
            {
                enStepBrakePedal = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enStepBrakePedal, enStepBrakePedal);
}
void WN_OverSpeedWarningProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{

    //Byte32 Bit4-bit2
    uint8 configSpeedOmeter = 0;

    //超速报警功能开关，从菜单设置获取
    uint8 Overspeed_Enable = 0;
    //显示车速，从档位获取
    uint16 VehicleSpd = 0;
    //车速报警速度，从菜单设置获取
    uint16 Set_Overspeed = 0;
    //迟滞量，根据显示单位设置
    uint8 SpeedHysteresis = 0;
    uint8 MenuUnit = 0;
    s_SpeedoInfo_t SpeedoInfo_Tmp = {0};
    MenuSetData_t MenuSetData_Tmp = {0};

	//单位公英制式切换
	uint8 u8UnitChange = 0;

    configSpeedOmeter = (uint8)WN_GetSingleConfig(WN_enCfg_SpeedOmeter);

    WN_SpeedoInfo_APIGet(&SpeedoInfo_Tmp);
    WN_MenuSetData_APIGet(&MenuSetData_Tmp);
    WN_Overspeed_Enable_APIGet(&Overspeed_Enable);
    WN_Set_Overspeed_APIGet(&Set_Overspeed);
    VehicleSpd = SpeedoInfo_Tmp.IndicateSpeed;
    MenuUnit = MenuSetData_Tmp.OdometerUnit;

    if ((configSpeedOmeter == 2) || (configSpeedOmeter == 4))
    {
        if ((MenuUnit == 2) || (MenuUnit == 3))//mph
        {
            VehicleSpd = SpeedoInfo_Tmp.IndicateSpeedMile;
			u8UnitChange = 0;
        }
        else//kmh
        {
            VehicleSpd = SpeedoInfo_Tmp.IndicateSpeed;
			u8UnitChange = 1;
        }
        //1.62
        SpeedHysteresis = 5;
		if((Set_Overspeed == m_Set_Overspeed_Pre) && (u8UnitChange == m_UnitChange_Pre))
		{
			 if ((1u == Overspeed_Enable) &&
	            (VehicleSpd >= Set_Overspeed))
	        {
	            m_enOverSpeedWarning = WN_enDISPLAY_ON;
	        }
	        if ((VehicleSpd <= (Set_Overspeed - SpeedHysteresis)) || (0u == Overspeed_Enable))
	        {
	            m_enOverSpeedWarning = WN_enDISPLAY_OFF;
	        }
		}
		else//用户调节设置超速报警阈值 
		{
			if((1u == Overspeed_Enable) &&
	            (VehicleSpd >= Set_Overspeed))
			{
				m_enOverSpeedWarning = WN_enDISPLAY_ON;
			}
			else
			{
				m_enOverSpeedWarning = WN_enDISPLAY_OFF;
			}	
			m_Set_Overspeed_Pre = Set_Overspeed;
			m_UnitChange_Pre = u8UnitChange;
   		}	
		
    }

    WN_SET(WN_enOverSpeedSetting, m_enOverSpeedWarning);
}
void WN_OverSpeedAlarmProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enOverSpeedLevel_1 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enOverSpeedLevel_2 = WN_enDISPLAY_OFF;

    //Byte32 Bit4-bit2
    uint8 configSpeedOmeter = 0;

    uint8 enFirstAlarmTrigger = 0;
    uint8 enFirstAlarmRelease = 0;
    uint8 enSecondAlarmTrigger = 0;
    uint8 enSecondAlarmRelease = 0;
    uint16 VehicleSpd = 0;
    uint8 MenuUnit = 0;
    s_SpeedoInfo_t SpeedoInfo_Tmp = {0};
    MenuSetData_t MenuSetData_Tmp = {0};

    configSpeedOmeter = (uint8)WN_GetSingleConfig(WN_enCfg_SpeedOmeter);

    WN_SpeedoInfo_APIGet(&SpeedoInfo_Tmp);
    WN_MenuSetData_APIGet(&MenuSetData_Tmp);
    VehicleSpd = SpeedoInfo_Tmp.IndicateSpeed;
    MenuUnit = MenuSetData_Tmp.OdometerUnit;

    if (configSpeedOmeter == 5)
    {
        //1.16
        if ((MenuUnit == 2) || (MenuUnit == 3))
        {
            enFirstAlarmTrigger = 50;
            enFirstAlarmRelease = 47;
            enSecondAlarmTrigger = 75;
            enSecondAlarmRelease = 70;
            VehicleSpd = SpeedoInfo_Tmp.IndicateSpeedMile;
        }
        else
        {
            enFirstAlarmTrigger = 80;
            enFirstAlarmRelease = 75;
            enSecondAlarmTrigger = 120;
            enSecondAlarmRelease = 115;
            VehicleSpd = SpeedoInfo_Tmp.IndicateSpeed;
        }
        if (VehicleSpd >= enSecondAlarmTrigger)
        {
            enOverSpeedLevel_2 = WN_enDISPLAY_ON;
        }
        else if ((VehicleSpd >= enSecondAlarmRelease) && (VehicleSpd <= enSecondAlarmTrigger))
        {
            if (m_enOverSpeedLevel_2_pre)
            {
                enOverSpeedLevel_2 = WN_enDISPLAY_ON;
            }
            else
            {
                enOverSpeedLevel_1 = WN_enDISPLAY_ON;
            }
        }
        else
        {
            enOverSpeedLevel_2 = WN_enDISPLAY_OFF;
            if (VehicleSpd >= enFirstAlarmTrigger)
            {
                enOverSpeedLevel_1 = WN_enDISPLAY_ON;
            }
            else if ((VehicleSpd >= enFirstAlarmRelease) && (VehicleSpd <= enFirstAlarmTrigger))
            {
                if ((WN_enDISPLAY_ON == m_enOverSpeedLevel_1_pre) || (WN_enDISPLAY_ON == m_enOverSpeedLevel_2_pre))
                {
                    enOverSpeedLevel_1 = WN_enDISPLAY_ON;
                }
                else
                {
                    enOverSpeedLevel_1 = WN_enDISPLAY_OFF;
                }
            }
            else
            {
                enOverSpeedLevel_1 = WN_enDISPLAY_OFF;
            }
        }
        m_enOverSpeedLevel_1_pre = enOverSpeedLevel_1;
        m_enOverSpeedLevel_2_pre = enOverSpeedLevel_2;
    }

    WN_SET(WN_enOverSpeedLevel_1, enOverSpeedLevel_1);
    WN_SET(WN_enOverSpeedLevel_2, enOverSpeedLevel_2);
}
void WN_DoorOpenProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enLFDoorOpen = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRFDoorOpen = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enLRDoorOpen = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRRDoorOpen = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTrunkOpen = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enHoodOpen = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRainDoorOpen = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enOneTrunkBoardOpen = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSplitTrunkBoardOpen = WN_enDISPLAY_OFF;

    //Byte38 Bit5-bit4
    uint8 configSmartJuncBox = 0;
    //Byte4 Bit7-bit6
    uint8 configDriveHandleType = 0;
    //Byte80 Bit7-bit6
    uint8 configCentralModule = 0;
	//Byte41 Bit7-bit4
    uint8 configRainShed = 0;
	//Byte93 Bit2-bit0
    uint8 configTrunkBoard = 0;
    //BCM1 0x319 50ms
    boolean DrvDoorSts_temp = FALSE;
    boolean PassengerDoorSts_temp = FALSE;
    boolean LRDoorSts_temp = FALSE;
    boolean RRDoorSts_temp = FALSE;
    boolean TrunkSts_temp = FALSE;
    uint8 Rte_BCM1Sts = RTE_E_INVALID;
    boolean HoodSts_temp = FALSE;
    uint8 Rte_HoodSts = RTE_E_INVALID;
    boolean HoodSts_F_Pbox_temp = FALSE;
    uint8 Rte_HoodSts_F_Pbox = RTE_E_INVALID;
    boolean TrunkSts_Y_temp = FALSE;
    //BCM13 0x2A7 100ms
    boolean RainshedSts_temp = FALSE;
    uint8 Rte_RainshedSts = RTE_E_INVALID; 
	boolean RainshedSts_FL_temp = FALSE;
    boolean RainshedSts_FR_temp = FALSE;

    configSmartJuncBox = (uint8)WN_GetSingleConfig(WN_enCfg_SmartJuncBox);
	configRainShed = (uint8)WN_GetSingleConfig(WN_encfg_RainShed);
    configDriveHandleType = (uint8)WN_GetSingleConfig(WN_enCfg_DriveHandleType);
    configCentralModule = (uint8)WN_GetSingleConfig(WN_enCfg_CentralModule);
	configTrunkBoard = (uint8)WN_GetSingleConfig(WN_encfg_TrunkBoard);

    Rte_BCM1Sts = WN_DrvDoorSts_SignalGet(&DrvDoorSts_temp);
    Rte_BCM1Sts = WN_PassengerDoorSts_SignalGet(&PassengerDoorSts_temp);
    Rte_BCM1Sts = WN_LRDoorSts_SignalGet(&LRDoorSts_temp);
    Rte_BCM1Sts = WN_RRDoorSts_SignalGet(&RRDoorSts_temp);
    Rte_BCM1Sts = WN_TrunkSts_SignalGet(&TrunkSts_temp);
	Rte_RainshedSts = WN_ECM13_TrunkSts_Y_SignalGet(&TrunkSts_Y_temp);
    //Rte_HoodSts = Rte_Read_Common_Normal_DrvDoorSts_DrvDoorSts(&DrvDoorSts);
    Rte_HoodSts_F_Pbox = WN_HoodSts_F_Pbox_SignalGet(&HoodSts_F_Pbox_temp);
    Rte_RainshedSts = WN_RainshedSts_SignalGet(&RainshedSts_temp);
	Rte_RainshedSts = WN_ECM13_RainshedSts_FL_SignalGet(&RainshedSts_FL_temp);
	Rte_RainshedSts = WN_ECM13_RainshedSts_FR_SignalGet(&RainshedSts_FR_temp);
	
    if ((configSmartJuncBox == 1) || (configCentralModule == 1))
    {
    	if((configTrunkBoard == 0) || (configTrunkBoard == 1) || (configTrunkBoard == 3))//case1、2
    	{
    		 //1.18 
        	if ((RTE_E_OK == Rte_BCM1Sts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_BCM1Sts))
        	{
        		if (configDriveHandleType == 0x00)
	            {
	                enLFDoorOpen = (DrvDoorSts_temp == TRUE) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
	                enRFDoorOpen = (PassengerDoorSts_temp == TRUE) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
	            }
           		 else
            	{
               		enLFDoorOpen = (PassengerDoorSts_temp == TRUE) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
                	enRFDoorOpen = (DrvDoorSts_temp == TRUE) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            	}
	            enLRDoorOpen = (LRDoorSts_temp == TRUE) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
	            enRRDoorOpen = (RRDoorSts_temp == TRUE) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
        	}
			if ((RTE_E_OK == Rte_HoodSts_F_Pbox) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HoodSts_F_Pbox))
			{	
			 	enHoodOpen = (HoodSts_F_Pbox_temp == TRUE) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
			}
    	}

		if (configTrunkBoard == 0u)//无车箱后板：轿车或SUV
		{
			if ((RTE_E_OK == Rte_BCM1Sts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_BCM1Sts))
			{
				enTrunkOpen = (TrunkSts_temp == TRUE) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
			}
		}
		else if(configTrunkBoard == 1) //一体式：D02
		{
			if((RTE_E_OK == Rte_BCM1Sts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_BCM1Sts))
			{
				enOneTrunkBoardOpen = (TrunkSts_temp == TRUE) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
			}
		}
		else if(configTrunkBoard == 3)//分体式：P05
		{
			if((RTE_E_OK == Rte_RainshedSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_RainshedSts)) 
			{
				if((RTE_E_OK == Rte_BCM1Sts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_BCM1Sts))
				{
					if((TrunkSts_Y_temp == TRUE) && (TrunkSts_temp == FALSE))
					{
						enSplitTrunkBoardOpen = WN_enDISPLAY_ON;
					}
				    else if((TrunkSts_temp == TRUE) && (TrunkSts_Y_temp == FALSE))
					{
						enOneTrunkBoardOpen = WN_enDISPLAY_ON;
					}
				}
				else
				{	
					if(TrunkSts_Y_temp == TRUE)
					{
						enSplitTrunkBoardOpen = WN_enDISPLAY_ON;
					}
				}
				
			}
			else
			{
				if((RTE_E_OK == Rte_BCM1Sts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_BCM1Sts))
				{
					if(TrunkSts_temp == TRUE)
					{
						enOneTrunkBoardOpen = WN_enDISPLAY_ON;
					}
				}
				
			}
    	}
		else
		{	
			;/*do nothing*/
		}
		
		 //1.241防雨棚未关闭
        if(configRainShed == 3)//CASE1
        {
        	if ((RTE_E_OK == Rte_RainshedSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_RainshedSts))
	        {
	            enRainDoorOpen = (RainshedSts_temp == TRUE) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
	        }
        }
		else if(configRainShed == 5)//CASE2 
		{
			if((RTE_E_OK == Rte_RainshedSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_RainshedSts))
			{
				enRainDoorOpen = ((RainshedSts_temp == TRUE) || (RainshedSts_FL_temp == TRUE) \
					|| (RainshedSts_FR_temp == TRUE)) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
			}
		}
		else
		{
			;
		}
        
    }
    else if ((configSmartJuncBox == 0) && (configCentralModule == 0))
    {
        //1.17
        //Rte_HoodSts = Rte_Read_Common_Normal_DrvDoorSts_DrvDoorSts(&DrvDoorSts);
        if ((RTE_E_OK == Rte_HoodSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HoodSts))
        {
            if (configDriveHandleType == 0x00)
            {
                enLFDoorOpen = (DrvDoorSts_temp == TRUE) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
                enRFDoorOpen = (PassengerDoorSts_temp == TRUE) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            }
            else
            {
                enLFDoorOpen = (PassengerDoorSts_temp == TRUE) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
                enRFDoorOpen = (DrvDoorSts_temp == TRUE) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            }
            enLRDoorOpen = (LRDoorSts_temp == TRUE) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            enRRDoorOpen = (RRDoorSts_temp == TRUE) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            enTrunkOpen = (TrunkSts_temp == TRUE) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            enHoodOpen = (HoodSts_temp == TRUE) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
        }
    }
    else
    {
    }
	WN_SET(WN_enLFDoorOpen, enLFDoorOpen);
    WN_SET(WN_enRFDoorOpen, enRFDoorOpen);
    WN_SET(WN_enLRDoorOpen, enLRDoorOpen);
    WN_SET(WN_enRRDoorOpen, enRRDoorOpen);
    WN_SET(WN_enTrunkOpen, enTrunkOpen);
    WN_SET(WN_enHoodOpen, enHoodOpen);
    WN_SET(WN_enRainDoorOpen, enRainDoorOpen);
	WN_SET(WN_enOneTrunkBoardOpen, enOneTrunkBoardOpen);
    WN_SET(WN_enSplitTrunkBoardOpen, enSplitTrunkBoardOpen);
}

void WN_RearFogLampFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enRearFogLampFault = WN_enDISPLAY_OFF;

    //Byte38 Bit5-bit4
    uint8 configSmartJuncBox = 0;
    //Byte80 Bit7-bit6
    uint8 configCentralModule = 0;

    //BCM1 0x319 50ms
    uint8 RearFogLmpFailSts_temp = 0;
    //uint8 Rte_RearFogLmpFailSts = RTE_E_INVALID;
    //R_PBox1 0x19C 50ms
    boolean RFogLmpFailSts_R_Pbox_temp = FALSE;
    uint8 Rte_RFogLmpFailSts_R_Pbox = RTE_E_INVALID;

    configSmartJuncBox = (uint8)WN_GetSingleConfig(WN_enCfg_SmartJuncBox);
    configCentralModule = (uint8)WN_GetSingleConfig(WN_enCfg_CentralModule);

    if ((configSmartJuncBox == 1) || (configCentralModule == 1))
    {
        //1.20
        Rte_RFogLmpFailSts_R_Pbox = WN_RFogLmpFailSts_R_Pbox_SignalGet(&RFogLmpFailSts_R_Pbox_temp);
        if ((RTE_E_OK == Rte_RFogLmpFailSts_R_Pbox) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_RFogLmpFailSts_R_Pbox))
        {
            if (RFogLmpFailSts_R_Pbox_temp == TRUE)
            {
                enRearFogLampFault = WN_enDISPLAY_ON;
            }
        }
    }
    else if ((configSmartJuncBox == 0) && (configCentralModule == 0))
    {
        //1.19
        //Com_ReceiveSignal(COM_SINGAL_RX_BCM1_REARFOTLMPFAILSTS, &RearFogLmpFailSts);
        if (0)
        {
            if (RearFogLmpFailSts_temp == 0x1)
            {
                enRearFogLampFault = WN_enDISPLAY_ON;
            }
        }
    }
    else
    {
    }

    WN_SET(WN_enRearFogLampFault, enRearFogLampFault);
}
void WN_PositionLampOnProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enPositionLampOn = WN_enDISPLAY_OFF;

    //Byte38 Bit5-bit4
    uint8 configSmartJuncBox = 0;
    //Byte11 Bit2-bit0
    uint8 configStartSystem = 0;
    //Byte80 Bit7-bit6
    uint8 configCentralModule = 0;

    //BCM1 0x319 50ms
    uint8 PosLmpOutputSts_temp = 0;
    //uint8 Rte_PosLmpOutputSts = RTE_E_INVALID;
    //BCM3 0x345 50ms
    uint8 AutoLampSwsts_temp = 0;
    //uint8 Rte_AutoLampSwsts = RTE_E_INVALID;
    //R_PBox1 0x19C 50ms
    boolean PosnLmpOutpSts_R_Pbox_temp = FALSE;
    uint8 Rte_PosnLmpOutpSts_R_Pbox = RTE_E_INVALID;
    //CSA1 0x165 20ms
    uint8 AutoLmpSwtSts_temp = (uint8)0xFF;
    uint8 Rte_AutoLmpSwtSts = RTE_E_INVALID;
    //BCM1 0x319 50ms
    boolean DrvDoorSts_temp = FALSE;
    uint8 Rte_DrvDoorSts = RTE_E_INVALID;
    //PEPS2 0x295 50ms
    uint8 SysPowerMod_temp = 0;
    uint8 Rte_SysPowerMod = RTE_E_INVALID;
    //BCM17 0x23E 50ms
    uint8 AutoLmpsts_temp = (uint8)0xFF;
    uint8 Rte_AutoLmpsts = RTE_E_INVALID;


    configSmartJuncBox = (uint8)WN_GetSingleConfig(WN_enCfg_SmartJuncBox);
    configCentralModule = (uint8)WN_GetSingleConfig(WN_enCfg_CentralModule);
    configStartSystem = (uint8)WN_GetSingleConfig(WN_enCfg_StartSystem);

    Rte_PosnLmpOutpSts_R_Pbox = WN_PosnLmpOutpSts_R_Pbox_SignalGet(&PosnLmpOutpSts_R_Pbox_temp);
    Rte_DrvDoorSts = WN_DrvDoorSts_SignalGet(&DrvDoorSts_temp);
    Rte_AutoLmpSwtSts = WN_AutoLmpSwtSts_SignalGet(&AutoLmpSwtSts_temp);
    Rte_SysPowerMod = WN_SysPowerMod_SignalGet(&SysPowerMod_temp);
    Rte_AutoLmpsts = WN_AutoLmpsts_SignalGet(&AutoLmpsts_temp);
    if((RTE_E_OK != Rte_AutoLmpSwtSts) && (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN != Rte_AutoLmpSwtSts))
    {
        AutoLmpSwtSts_temp = 0;
    }
    if((RTE_E_OK != Rte_AutoLmpsts) && (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN != Rte_AutoLmpsts))
    {
        AutoLmpsts_temp = 0;
    }

    if ((configSmartJuncBox == 1) || (configCentralModule == 1))
    {
        //1.22
        if (configStartSystem == 0)
        {
            //case1|2|3
            if (((RTE_E_OK == Rte_PosnLmpOutpSts_R_Pbox) ||
                 (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_PosnLmpOutpSts_R_Pbox)) &&
                 ((RTE_E_OK == Rte_AutoLmpSwtSts) ||
                 (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_AutoLmpSwtSts) ||
                 (RTE_E_OK == Rte_AutoLmpsts) ||
                 (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_AutoLmpsts)) &&
                 ((RTE_E_OK == Rte_DrvDoorSts) ||
                 (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_DrvDoorSts)))
            {
                if ((PosnLmpOutpSts_R_Pbox_temp == TRUE) && ((AutoLmpSwtSts_temp == 0x00) && (AutoLmpsts_temp == 0x00)) &&
                    (DrvDoorSts_temp == TRUE))
                {
                    enPositionLampOn = WN_enDISPLAY_ON;
                }
            }
        }
        else if ((configStartSystem == 1) || (configStartSystem == 2) || (configStartSystem == 3))
        {
            if (((RTE_E_OK == Rte_PosnLmpOutpSts_R_Pbox) ||
                 (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_PosnLmpOutpSts_R_Pbox)) &&
                 ((RTE_E_OK == Rte_AutoLmpSwtSts) ||
                 (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_AutoLmpSwtSts) ||
                 (RTE_E_OK == Rte_AutoLmpsts) ||
                 (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_AutoLmpsts)) &&
                 ((RTE_E_OK == Rte_DrvDoorSts) ||
                 (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_DrvDoorSts)) &&
                 ((RTE_E_OK == Rte_SysPowerMod) ||
                 (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SysPowerMod)))
            {
                //case4|5|6
                if ((PosnLmpOutpSts_R_Pbox_temp == TRUE) && ((AutoLmpSwtSts_temp == 0x00) && (AutoLmpsts_temp == 0x00)) &&
                    (DrvDoorSts_temp == TRUE) && (SysPowerMod_temp == 0x00))
                {
                    enPositionLampOn = WN_enDISPLAY_ON;
                }
            }
        }
        else
        {
        }
    }
    else if ((configSmartJuncBox == 0) && (configCentralModule == 0))
    {
        //1.21
        if (0)
        {
            if (configStartSystem == 0)
            {
                if ((PosLmpOutputSts_temp == 0x1) && (AutoLampSwsts_temp == 0x00) &&
                    (DrvDoorSts_temp == 0x01))
                {
                    enPositionLampOn = WN_enDISPLAY_ON;
                }
            }
            else if ((configStartSystem == 1) || (configStartSystem == 2))
            {
                if ((PosLmpOutputSts_temp == 0x1) && (AutoLampSwsts_temp == 0x00) &&
                    (DrvDoorSts_temp == 0x01) && (SysPowerMod_temp == 0x00))
                {
                    enPositionLampOn = WN_enDISPLAY_ON;
                }
            }
            else
            {
            }
        }
    }
    else
    {
    }

    WN_SET(WN_enPositionLampOn, enPositionLampOn);
}
void WN_BrakeLampFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enBrakeLampFault = WN_enDISPLAY_OFF;

    //Byte38 Bit5-bit4
    uint8 configSmartJuncBox = 0;
    //Byte80 Bit7-bit6
    uint8 configCentralModule = 0;

    //TBD
    uint8 BrakeLmpFailSts_temp = 0;
    //uint8 Rte_BrakeLmpFailSts = RTE_E_INVALID;
    //R_PBox1 0x19C 50ms
    uint8 LBrkLmpFailSts_temp = 0;
    uint8 HiPosnBrkLmpFailSts_temp = 0;
    uint8 RBrkLmpFailSts_temp = 0;
    uint8 Rte_R_PBox1Sts = RTE_E_INVALID;

    configSmartJuncBox = (uint8)WN_GetSingleConfig(WN_enCfg_SmartJuncBox);
    configCentralModule = (uint8)WN_GetSingleConfig(WN_enCfg_CentralModule);

    //Com_ReceiveSignal(TBD, &BrakeLmpFailSts);
    Rte_R_PBox1Sts = WN_LBrkLmpFailSts_SignalGet(&LBrkLmpFailSts_temp);
    Rte_R_PBox1Sts = WN_HiPosnBrkLmpFailSts_SignalGet(&HiPosnBrkLmpFailSts_temp);
    Rte_R_PBox1Sts = WN_RBrkLmpFailSts_SignalGet(&RBrkLmpFailSts_temp);

    if ((configSmartJuncBox == 1) || (configCentralModule == 1))
    {
        //1.24
        if ((RTE_E_OK == Rte_R_PBox1Sts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_R_PBox1Sts))
        {
            if ((LBrkLmpFailSts_temp == 0x01) || (HiPosnBrkLmpFailSts_temp == 0x01) ||
                (RBrkLmpFailSts_temp == 0x01))
            {
                enBrakeLampFault = WN_enDISPLAY_ON;
            }
        }
    }
    else if ((configSmartJuncBox == 0) && (configCentralModule == 0))
    {
        //1.23
        if (0)
        {
            if (BrakeLmpFailSts_temp == 0x01)
            {
                enBrakeLampFault = WN_enDISPLAY_ON;
            }
        }
    }
    else
    {
    }

    WN_SET(WN_enBrakeLampFault, enBrakeLampFault);
}
void WN_LicPlateLampFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enLicPlateLampFault = WN_enDISPLAY_OFF;

    //Byte38 Bit5-bit4
    uint8 configSmartJuncBox = 0;
    //Byte80 Bit7-bit6
    uint8 configCentralModule = 0;

    //R_PBox1 0x19C 50ms
    boolean LicPlateLmpFailSts_temp = FALSE;
    uint8 Rte_LicPlateLmpFailSts = RTE_E_INVALID;

    configSmartJuncBox = (uint8)WN_GetSingleConfig(WN_enCfg_SmartJuncBox);
    configCentralModule = (uint8)WN_GetSingleConfig(WN_enCfg_CentralModule);

    Rte_LicPlateLmpFailSts = WN_LicPlateLmpFailSts_SignalGet(&LicPlateLmpFailSts_temp);

    if ((configSmartJuncBox == 1) || (configCentralModule == 1))
    {
        //1.26
        if ((RTE_E_OK == Rte_LicPlateLmpFailSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_LicPlateLmpFailSts))
        {
            if (LicPlateLmpFailSts_temp == TRUE)
            {
                enLicPlateLampFault = WN_enDISPLAY_ON;
            }
        }
    }
    else if ((configSmartJuncBox == 0) && (configCentralModule == 0))
    {
        //TBD  1.25
        /*if(1)
        {
            if(TBD == 0x01)
            {
                enLicPlateLampFault = WN_enDISPLAY_ON;
            }
        }*/
    }
    else
    {
    }

    WN_SET(WN_enLicPlateLampFault, enLicPlateLampFault);
}
void WN_RvsLampFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enRvsLampFault = WN_enDISPLAY_OFF;

    //Byte38 Bit5-bit4
    uint8 configSmartJuncBox = 0;
    //Byte80 Bit7-bit6
    uint8 configCentralModule = 0;

    //R_PBox1 0x19C 50ms
    boolean RvsLmpFailSts_temp = FALSE;
    uint8 Rte_RvsLmpFailSts = RTE_E_INVALID;

    configSmartJuncBox = (uint8)WN_GetSingleConfig(WN_enCfg_SmartJuncBox);
    configCentralModule = (uint8)WN_GetSingleConfig(WN_enCfg_CentralModule);

    Rte_RvsLmpFailSts = WN_RvsLmpFailSts_SignalGet(&RvsLmpFailSts_temp);

    if ((configSmartJuncBox == 1) || (configCentralModule == 1))
    {
        //1.28
        if ((RTE_E_OK == Rte_RvsLmpFailSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_RvsLmpFailSts))
        {
            if (RvsLmpFailSts_temp == TRUE)
            {
                enRvsLampFault = WN_enDISPLAY_ON;
            }
        }
    }
    else if ((configSmartJuncBox == 0) && (configCentralModule == 0))
    {
        //TBD  1.27
        /*(1)
        {
            if(TBD == 0x01)
            {
                enRvsLampFault = WN_enDISPLAY_ON;
            }
        }*/
    }
    else
    {
    }

    WN_SET(WN_enRvsLampFault, enRvsLampFault);
}
void WN_RearPositonLampFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enRearPosnLampFault = WN_enDISPLAY_OFF;

    //Byte38 Bit5-bit4
    uint8 configSmartJuncBox = 0;
    //Byte80 Bit7-bit6
    uint8 configCentralModule = 0;

    //R_PBox1 0x19C 50ms
    boolean LRPosnLmpFailSts_temp = FALSE;
    boolean RRPosnLmpFailSts_temp = FALSE;
    uint8 Rte_R_Pbox1Sts = RTE_E_INVALID;

    configSmartJuncBox = (uint8)WN_GetSingleConfig(WN_enCfg_SmartJuncBox);
    configCentralModule = (uint8)WN_GetSingleConfig(WN_enCfg_CentralModule);

    Rte_R_Pbox1Sts = WN_LRPosnLmpFailSts_SignalGet(&LRPosnLmpFailSts_temp);
    Rte_R_Pbox1Sts = WN_RRPosnLmpFailSts_SignalGet(&RRPosnLmpFailSts_temp);

    if ((configSmartJuncBox == 1) || (configCentralModule == 1))
    {
        //1.29
        if ((RTE_E_OK == Rte_R_Pbox1Sts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_R_Pbox1Sts))
        {
            if ((LRPosnLmpFailSts_temp == TRUE) || (RRPosnLmpFailSts_temp == TRUE))
            {
                enRearPosnLampFault = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enRearPosnLampFault, enRearPosnLampFault);
}
void WN_ParkLampOnProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enParkLampOn = WN_enDISPLAY_OFF;

    //Byte32 Bit1-bit0
    uint8 configParkingLamp = 0;
    //Byte38 Bit5-bit4
    uint8 configSmartJuncBox = 0;
    //Byte80 Bit7-bit6
    uint8 configCentralModule = 0;

    //0x19C
    boolean ParkLmpSts_R_Pbox_temp = FALSE;
    uint8 Rte_ParkLmpSts_R_Pbox = RTE_E_INVALID;

    configSmartJuncBox = (uint8)WN_GetSingleConfig(WN_enCfg_SmartJuncBox);
    configCentralModule = (uint8)WN_GetSingleConfig(WN_enCfg_CentralModule);
    configParkingLamp = (uint8)WN_GetSingleConfig(WN_enCfg_ParkingLamp);

    Rte_ParkLmpSts_R_Pbox = WN_ParkLmpSts_R_Pbox_SignalGet(&ParkLmpSts_R_Pbox_temp);

    if ((configParkingLamp == 1) && ((configSmartJuncBox == 1) || (configCentralModule == 1)))
    {
        //1.30
        if ((RTE_E_OK == Rte_ParkLmpSts_R_Pbox) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_ParkLmpSts_R_Pbox))
        {
            if (ParkLmpSts_R_Pbox_temp == TRUE)
            {
                enParkLampOn = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enParkLampOn, enParkLampOn);
}
void WN_RainLightFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enRainLightFault = WN_enDISPLAY_OFF;

    //Byte36 Bit5-bit4
    uint8 configAutoLightSys = 0;
    //Byte36 Bit3-bit0
    uint8 configFrtWiperSys = 0;

    //BCM1 0x319 50ms
    boolean RLSFailSts_temp = FALSE;
    uint8 Rte_RLSFailSts = RTE_E_INVALID;

    configAutoLightSys = (uint8)WN_GetSingleConfig(WN_enCfg_AutoLightSys);
    configFrtWiperSys = (uint8)WN_GetSingleConfig(WN_enCfg_FrtWiperSys);

    Rte_RLSFailSts = WN_RLSFailSts_SignalGet(&RLSFailSts_temp);

    if ((configAutoLightSys == 1) || (configFrtWiperSys == 2) || (configFrtWiperSys == 3))
    {
        //1.31
        if ((RTE_E_OK == Rte_RLSFailSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_RLSFailSts))
        {
            if (RLSFailSts_temp == TRUE)
            {
                enRainLightFault = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enRainLightFault, enRainLightFault);
}
void WN_DrowsyDriveWarningProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enDrowsyDrvWarning = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDrowsyDrvWarning_1Hz = WN_enDISPLAY_OFF;

    //Byte11 Bit7-bit6
    uint8 configDrowWarnSys = 0;

    //BCM1 0x319 50ms
    uint8 DrowsyDrvDetWarn_temp = 0;
    uint8 Rte_DrowsyDrvDetWarn = RTE_E_INVALID;

    configDrowWarnSys = (uint8)WN_GetSingleConfig(WN_enCfg_DrowWarnSys);

    Rte_DrowsyDrvDetWarn = WN_DrowsyDrvDetWarn_SignalGet(&DrowsyDrvDetWarn_temp);

    if (configDrowWarnSys == 1)
    {
        //1.32
        if ((RTE_E_OK == Rte_DrowsyDrvDetWarn) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_DrowsyDrvDetWarn))
        {
            if (DrowsyDrvDetWarn_temp == 0x1)
            {
                enDrowsyDrvWarning = WN_enDISPLAY_ON;
            }
            else if (DrowsyDrvDetWarn_temp == 0x2)
            {
                enDrowsyDrvWarning_1Hz = WN_enDISPLAY_ON;
            }
            else
            {

            }
        }
    }

    WN_SET(WN_enDrowsyDrvWarning, enDrowsyDrvWarning);
    WN_SET(WN_enDrowsyDrvWarning_1Hz, enDrowsyDrvWarning_1Hz);
}
void WN_TpmsWarningProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enFLTirePressWarning = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enFRTirePressWarning = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRLTirePressWarning = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRRTirePressWarning = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enFLTireTempWarning = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enFRTireTempWarning = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRLTireTempWarning = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRRTireTempWarning = WN_enDISPLAY_OFF;

    //Byte39 Bit4-bit3
    uint8 configTpms = 0;

    //TPMS1 0x341 500ms
    uint8 FLTirePressIndSts_temp = 0;
    uint8 FRTirePressIndSts_temp = 0;
    uint8 RLTirePressIndSts_temp = 0;
    uint8 RRTirePressIndSts_temp = 0;
    uint8 FLTireTempSts_temp = 0;
    uint8 FRTireTempSts_temp = 0;
    uint8 RLTireTempSts_temp = 0;
    uint8 RRTireTempSts_temp = 0;
    uint8 Rte_TPMS1Sts = RTE_E_INVALID;

    configTpms = (uint8)WN_GetSingleConfig(WN_enCfg_Tpms);

    Rte_TPMS1Sts = WN_FLTirePressIndSts_SignalGet(&FLTirePressIndSts_temp);
    Rte_TPMS1Sts = WN_FRTirePressIndSts_SignalGet(&FRTirePressIndSts_temp);
    Rte_TPMS1Sts = WN_RLTirePressIndSts_SignalGet(&RLTirePressIndSts_temp);
    Rte_TPMS1Sts = WN_RRTirePressIndSts_SignalGet(&RRTirePressIndSts_temp);
    Rte_TPMS1Sts = WN_FLTireTempSts_SignalGet(&FLTireTempSts_temp);
    Rte_TPMS1Sts = WN_FRTireTempSts_SignalGet(&FRTireTempSts_temp);
    Rte_TPMS1Sts = WN_RLTireTempSts_SignalGet(&RLTireTempSts_temp);
    Rte_TPMS1Sts = WN_RRTireTempSts_SignalGet(&RRTireTempSts_temp);

    if (configTpms == 1)
    {
        //1.33
        if ((RTE_E_OK == Rte_TPMS1Sts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_TPMS1Sts))
        {
            enFLTirePressWarning = (FLTirePressIndSts_temp == 0x01) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            enFRTirePressWarning = (FRTirePressIndSts_temp == 0x01) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            enRLTirePressWarning = (RLTirePressIndSts_temp == 0x01) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            enRRTirePressWarning = (RRTirePressIndSts_temp == 0x01) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
        }
        //1.34
        if ((RTE_E_OK == Rte_TPMS1Sts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_TPMS1Sts))
        {
            enFLTireTempWarning = (FLTireTempSts_temp == 0x01) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            enFRTireTempWarning = (FRTireTempSts_temp == 0x01) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            enRLTireTempWarning = (RLTireTempSts_temp == 0x01) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            enRRTireTempWarning = (RRTireTempSts_temp == 0x01) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
        }
    }

    WN_SET(WN_enFLTirePressWarning, enFLTirePressWarning);
    WN_SET(WN_enFRTirePressWarning, enFRTirePressWarning);
    WN_SET(WN_enRLTirePressWarning, enRLTirePressWarning);
    WN_SET(WN_enRRTirePressWarning, enRRTirePressWarning);
    WN_SET(WN_enFLTireTempWarning, enFLTireTempWarning);
    WN_SET(WN_enFRTireTempWarning, enFRTireTempWarning);
    WN_SET(WN_enRLTireTempWarning, enRLTireTempWarning);
    WN_SET(WN_enRRTireTempWarning, enRRTireTempWarning);
}
void WN_TakeTheKeyTipProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enTakeTheKeyTip = WN_enDISPLAY_OFF;

    //Byte11 Bit2-bit0
    uint8 configStartSystem = 0;

    //PEPS4 0x302 200/20ms
    boolean WarnKeyInCarWhenExit_temp = FALSE;
    uint8 Rte_WarnKeyInCarWhenExit = RTE_E_INVALID;

    configStartSystem = (uint8)WN_GetSingleConfig(WN_enCfg_StartSystem);

    Rte_WarnKeyInCarWhenExit = WN_WarnKeyInCarWhenExit_SignalGet(&WarnKeyInCarWhenExit_temp);

    if ((configStartSystem == 1) || (configStartSystem == 2) || (configStartSystem == 3))
    {
        //1.35
        if ((RTE_E_OK == Rte_WarnKeyInCarWhenExit) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_WarnKeyInCarWhenExit))
        {
            if (WarnKeyInCarWhenExit_temp == TRUE)
            {
                enTakeTheKeyTip = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enTakeTheKeyTip, enTakeTheKeyTip);
}
void WN_KeyInCarOrNotProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enKeyInCarOrNot = WN_enDISPLAY_OFF;

    //Byte11 Bit2-bit0
    uint8 configStartSystem = 0;

    //PEPS4 0x302 200/20ms
    boolean WarnVldKeyNotFound_temp = FALSE;
    uint8 Rte_WarnVldKeyNotFound = RTE_E_INVALID;

    configStartSystem = (uint8)WN_GetSingleConfig(WN_enCfg_StartSystem);

    Rte_WarnVldKeyNotFound = WN_WarnVldKeyNotFound_SignalGet(&WarnVldKeyNotFound_temp);

    if ((configStartSystem == 1) || (configStartSystem == 2) || (configStartSystem == 3))
    {
        //1.36
        if ((RTE_E_OK == Rte_WarnVldKeyNotFound) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_WarnVldKeyNotFound))
        {
            if (WarnVldKeyNotFound_temp == TRUE)
            {
                enKeyInCarOrNot = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enKeyInCarOrNot, enKeyInCarOrNot);
}
void WN_PEPSStartTipProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enStepBrakeStartGearPN = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enStepClutchStartGearNull = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enStepBrakeStartGearNull = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enStopGearPNSeatbelt = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enStopGearBlankSeatbelt = WN_enDISPLAY_OFF;

    //Byte11 Bit2-bit0
    uint8 configStartSystem = 0;
    //Byte3 Bit7-bit0
    uint8 configTransmission = 0;
    //Byte41 Bit3-bit2
    uint8 configEPark = 0;

    //PEPS4 0x302 200/20ms
    boolean WarnEngStrtNotMeet_temp = FALSE;
    uint8 Rte_WarnEngStrtNotMeet = RTE_E_INVALID;
    uint8 fl_StartModSts = 0;
    uint8 Rte_StartModSts = RTE_E_INVALID;

    configTransmission = (uint8)WN_GetSingleConfig(WN_enCfg_Transmission);
    configStartSystem = (uint8)WN_GetSingleConfig(WN_enCfg_StartSystem);
    configEPark = (uint8)WN_GetSingleConfig(WN_enCfg_EPark);

    Rte_WarnEngStrtNotMeet = WN_WarnEngStrtNotMeet_SignalGet(&WarnEngStrtNotMeet_temp);
    Rte_StartModSts = WN_StartModSts_SignalGet(&fl_StartModSts);

    if ((RTE_E_OK == Rte_WarnEngStrtNotMeet) ||
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_WarnEngStrtNotMeet))
    {
        //DCT CVT AT AMT DHT
        if ((configTransmission == 3) ||
            (configTransmission == 4) ||
            (configTransmission == 5) ||
            (configTransmission == 6) ||
            (configTransmission == 7) ||
            (configTransmission == 8) ||
            (configTransmission == 9) ||
            (configTransmission == 10) ||
            (configTransmission == 11) ||
            (configTransmission == 15) ||
            (configTransmission == 16) ||
            (configTransmission == 17) ||
            (configTransmission == 18) ||
            (configTransmission == 19) ||
            (configTransmission == 38) ||
            (configTransmission == 39) ||
            (configTransmission == 40) ||
            (configTransmission == 41))
        {
            //1.37
            if (WarnEngStrtNotMeet_temp == TRUE)
            {
                if (configStartSystem == 1) //case1
                {
                    enStepBrakeStartGearPN = WN_enDISPLAY_ON;
                }
                if (configStartSystem == 2) //case2
                {
                    enStopGearPNSeatbelt = WN_enDISPLAY_ON;
                }
                if (configStartSystem == 3) //case3
                {
                    if ((RTE_E_OK == Rte_StartModSts) ||
                        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_StartModSts))
                    {
                        if(fl_StartModSts == 0)
                        {
                            enStopGearPNSeatbelt = WN_enDISPLAY_ON;
                        }
                        else if(fl_StartModSts == 1)
                        {
                            enStepBrakeStartGearPN = WN_enDISPLAY_ON;
                        }
                        else
                        {

                        }
                    }
                }
            }
        }
        //单挡减速器
        if (configTransmission == 20)
        {
            //1.39
            if (configStartSystem == 1)
            {
                if (WarnEngStrtNotMeet_temp == TRUE)
                {
                    //无电子p挡
                    if (configEPark == 0)
                    {
                        enStepBrakeStartGearNull = WN_enDISPLAY_ON;
                    }
                    //电子p挡
                    else if ((configEPark == 1) || (configEPark == 2))
                    {
                        enStepBrakeStartGearPN = WN_enDISPLAY_ON;
                    }
                    else
                    {
                    }
                }
            }
            //1.40 TBD
        }
    }
    //MT车型
    if ((configTransmission == 1) ||
        (configTransmission == 2) ||
        (configTransmission == 12) ||
        (configTransmission == 13) ||
        (configTransmission == 14) ||
        (configTransmission == 37))
    {
        Rte_WarnEngStrtNotMeet = WN_WarnEngStrtNotMeetMT_SignalGet(&WarnEngStrtNotMeet_temp);
        //1.38
        if ((RTE_E_OK == Rte_WarnEngStrtNotMeet) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_WarnEngStrtNotMeet))
        {
            if (WarnEngStrtNotMeet_temp == TRUE)
            {
                if (configStartSystem == 1) //case1
                {
                    enStepClutchStartGearNull = WN_enDISPLAY_ON;
                }
                if (configStartSystem == 2) //case2
                {
                    enStopGearBlankSeatbelt = WN_enDISPLAY_ON;
                }
                if (configStartSystem == 3) //case3
                {
                    //Signal StartModSts Delay TBD
                }
            }
        }
    }

    WN_SET(WN_enStepBrakeStartGearPN, enStepBrakeStartGearPN);
    WN_SET(WN_enStepClutchStartGearNull, enStepClutchStartGearNull);
    WN_SET(WN_enStepBrakeStartGearNull, enStepBrakeStartGearNull);
    WN_SET(WN_enStopGearPNSeatbelt, enStopGearPNSeatbelt);
    WN_SET(WN_enStopGearBlankSeatbelt, enStopGearBlankSeatbelt);
}
void WN_PEPSPowerFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enPEPSPowerFault = WN_enDISPLAY_OFF;

    //Byte11 Bit2-bit0
    uint8 configStartSystem = 0;

    //PEPS4 0x302 200/20ms
    boolean PowerRlyFault_temp = FALSE;
    uint8 Rte_PowerRlyFault = RTE_E_INVALID;

    configStartSystem = (uint8)WN_GetSingleConfig(WN_enCfg_StartSystem);

    Rte_PowerRlyFault = WN_PowerRlyFault_SignalGet(&PowerRlyFault_temp);

    if ((configStartSystem == 1) || (configStartSystem == 2) || (configStartSystem == 3))
    {
        //1.41
        if ((RTE_E_OK == Rte_PowerRlyFault) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_PowerRlyFault))
        {
            if (PowerRlyFault_temp == TRUE)
            {
                enPEPSPowerFault = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enPEPSPowerFault, enPEPSPowerFault);
}
void WN_PowerNotInOffProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enPowerNotInOff = WN_enDISPLAY_OFF;

    //Byte11 Bit2-bit0
    uint8 configStartSystem = 0;

    //PEPS4 0x302 200/20ms
    boolean WarnPowerNotInOffPosn_temp = FALSE;
    uint8 Rte_WarnPowerNotInOffPosn = RTE_E_INVALID;

    configStartSystem = (uint8)WN_GetSingleConfig(WN_enCfg_StartSystem);

    Rte_WarnPowerNotInOffPosn = WN_WarnPowerNotInOffPosn_SignalGet(&WarnPowerNotInOffPosn_temp);

    if ((configStartSystem == 1) || (configStartSystem == 2) || (configStartSystem == 3))
    {
        //1.42
        if ((RTE_E_OK == Rte_WarnPowerNotInOffPosn) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_WarnPowerNotInOffPosn))
        {
            if (WarnPowerNotInOffPosn_temp == TRUE)
            {
                enPowerNotInOff = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enPowerNotInOff, enPowerNotInOff);
}
void WN_ElecSteerUnlockFailProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enElecSteerUnlockFail = WN_enDISPLAY_OFF;

    //Byte40 Bit4-bit3
    uint8 configElecSteColumnLock = 0;

    //ESCL2 0x303 200/20ms
    boolean RotSteerWheel_temp = FALSE;
    uint8 Rte_RotSteerWheel = RTE_E_INVALID;

    configElecSteColumnLock = (uint8)WN_GetSingleConfig(WN_enCfg_ElecSteColumnLock);

    Rte_RotSteerWheel = WN_RotSteerWheel_SignalGet(&RotSteerWheel_temp);

    if (configElecSteColumnLock == 1)
    {
        //1.43
        if ((RTE_E_OK == Rte_RotSteerWheel) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_RotSteerWheel))
        {
            if (RotSteerWheel_temp == TRUE)
            {
                enElecSteerUnlockFail = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enElecSteerUnlockFail, enElecSteerUnlockFail);
}
void WN_SeatBeltProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enFirRowLSBR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enFirRowRSBR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSecRowLSBR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSecRowMSBR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSecRowRSBR = WN_enDISPLAY_OFF;

    //Byte32 Bit7-bit5
    uint8 configSeatBelt = 0;
    //Byte4 Bit7-bit6
    uint8 configDriveHandleType = 0;

    //ABM1 0x351 500/10ms
    uint8 DrvSBR_Visual_temp = 0;
    uint8 PassSBR_Visual_temp = 0;
    uint8 SecRowLSBR_Visual_temp = 0;
    uint8 SecRowMidSBR_Visual_temp = 0;
    uint8 SecRowRSBR_Visual_temp = 0;
    uint8 Rte_SG_ABM1_Tmp = RTE_E_INVALID;

    configDriveHandleType = (uint8)WN_GetSingleConfig(WN_enCfg_DriveHandleType);
    configSeatBelt = (uint8)WN_GetSingleConfig(WN_enCfg_SeatBelt);

    Rte_SG_ABM1_Tmp = WN_DrvSBR_Visual_SignalGet(&DrvSBR_Visual_temp);
    Rte_SG_ABM1_Tmp = WN_PassSBR_Visual_SignalGet(&PassSBR_Visual_temp);
    Rte_SG_ABM1_Tmp = WN_SecRowLSBR_Visual_SignalGet(&SecRowLSBR_Visual_temp);
    Rte_SG_ABM1_Tmp = WN_SecRowMidSBR_Visual_SignalGet(&SecRowMidSBR_Visual_temp);
    Rte_SG_ABM1_Tmp = WN_SecRowRSBR_Visual_SignalGet(&SecRowRSBR_Visual_temp);

    if ((RTE_E_OK == Rte_SG_ABM1_Tmp) ||
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ABM1_Tmp))
    {
        //1.44
        if (configSeatBelt == 0)
        {
            if (configDriveHandleType == 0x00)
            {
                enFirRowLSBR = ((DrvSBR_Visual_temp == 0x01) || (DrvSBR_Visual_temp == 0x03)) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            }
            else if (configDriveHandleType == 0x01)
            {
                enFirRowRSBR = ((DrvSBR_Visual_temp == 0x01) || (DrvSBR_Visual_temp == 0x03)) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            }
            else
            {
            }
        }
        else if (configSeatBelt == 1)
        {
            if (configDriveHandleType == 0x00)
            {
                enFirRowLSBR = ((DrvSBR_Visual_temp == 0x01) || (DrvSBR_Visual_temp == 0x03)) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
                enFirRowRSBR = ((PassSBR_Visual_temp == 0x01) || (PassSBR_Visual_temp == 0x03)) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            }
            else if (configDriveHandleType == 0x01)
            {
                enFirRowLSBR = ((PassSBR_Visual_temp == 0x01) || (PassSBR_Visual_temp == 0x03)) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
                enFirRowRSBR = ((DrvSBR_Visual_temp == 0x01) || (DrvSBR_Visual_temp == 0x03)) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            }
            else
            {
            }
        }
        else if (configSeatBelt == 2)
        {
            if (configDriveHandleType == 0x00)
            {
                enFirRowLSBR = ((DrvSBR_Visual_temp == 0x01) || (DrvSBR_Visual_temp == 0x03)) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
                enFirRowRSBR = ((PassSBR_Visual_temp == 0x01) || (PassSBR_Visual_temp == 0x03)) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            }
            else if (configDriveHandleType == 0x01)
            {
                enFirRowLSBR = ((PassSBR_Visual_temp == 0x01) || (PassSBR_Visual_temp == 0x03)) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
                enFirRowRSBR = ((DrvSBR_Visual_temp == 0x01) || (DrvSBR_Visual_temp == 0x03)) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            }
            else
            {
            }
            enSecRowLSBR = ((SecRowLSBR_Visual_temp == 0x01) || (SecRowLSBR_Visual_temp == 0x03)) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            enSecRowMSBR = ((SecRowMidSBR_Visual_temp == 0x01) || (SecRowMidSBR_Visual_temp == 0x03)) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            enSecRowRSBR = ((SecRowRSBR_Visual_temp == 0x01) || (SecRowRSBR_Visual_temp == 0x03)) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
        }
        else
        {
        }
    }

    WN_SET(WN_enFirRowLSeatBelt, enFirRowLSBR);
    WN_SET(WN_enFirRowRSeatBelt, enFirRowRSBR);
    WN_SET(WN_enSecRowLSeatBelt, enSecRowLSBR);
    WN_SET(WN_enSecRowMSeatBelt, enSecRowMSBR);
    WN_SET(WN_enSecRowRSeatBelt, enSecRowRSBR);
}
void WN_TransWarnProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enTransWarnStopCar = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTransWarn = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enLockNGearDisable = WN_enDISPLAY_OFF;

    //Byte3 Bit7-bit0
    uint8 configTransmission = 0;

    //DCT7 0x235 50ms
    //DCT_FD4 0x236 50ms
    uint8 DrvWarnMsg_temp = 0;
    uint8 Rte_SG_DCT7_Tmp = RTE_E_INVALID;
    uint8 Rte_SG_DCT_FD4_Tmp = RTE_E_INVALID;
    //DHT_FD1 0x0C1 10ms
    uint8 TCU_ClutchHotWarning_temp = 0;
    uint8 Rte_SG_DHT_FD1_Tmp = RTE_E_INVALID;
    //DCT9 0x0C6 50ms
    uint8 TCU_Warn_high_temp_temp = 0;
    uint8 Rte_TCU_Warn_high_temp = RTE_E_INVALID;

    configTransmission = (uint8)WN_GetSingleConfig(WN_enCfg_Transmission);
    if (EolConfig_Trans_CANFD())
    {
        Rte_SG_DCT_FD4_Tmp = WN_DrvWarnMsgFD_SignalGet(&DrvWarnMsg_temp);
    }
    else
    {
        Rte_SG_DCT7_Tmp = WN_DrvWarnMsg_SignalGet(&DrvWarnMsg_temp);
    }
    if ((RTE_E_OK == Rte_SG_DCT7_Tmp) ||
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_DCT7_Tmp) ||
        (RTE_E_OK == Rte_SG_DCT_FD4_Tmp) ||
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_DCT_FD4_Tmp))
    {
        //7DCT,7DCT300S-GW,9DCT,9HDCT,9AT,9HAT
        if ((configTransmission == 7) ||
            (configTransmission == 38) ||
            (configTransmission == 15) ||
            (configTransmission == 16) ||
            (configTransmission == 39) ||
            (configTransmission == 40) ||
            (configTransmission == 41))
        {
            //1.45
            if (DrvWarnMsg_temp == 0x1)
            {
                enTransWarnStopCar = WN_enDISPLAY_ON;
            }
            else if (DrvWarnMsg_temp == 0x2)
            {
                enTransWarn = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
        //9AT,9HAT
        if((configTransmission == 39) ||(configTransmission == 40))
        {
            //1.290
            if (DrvWarnMsg_temp == 0x3)
            {
                enLockNGearDisable = WN_enDISPLAY_ON;
            }
        }
    }
    //混联DHT
    if (configTransmission == 19)
    {
        //1.46
        Rte_SG_DHT_FD1_Tmp = WN_TCU_ClutchHotWarning_SignalGet(&TCU_ClutchHotWarning_temp);
        if ((RTE_E_OK == Rte_SG_DHT_FD1_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_DHT_FD1_Tmp))
        {
            if (TCU_ClutchHotWarning_temp == 3)
            {
                enTransWarn = WN_enDISPLAY_ON;
            }
        }
    }
    //8AT
    if (configTransmission == 8)
    {
        Rte_TCU_Warn_high_temp = WN_TCU_Warn_high_temp_SignalGet(&TCU_Warn_high_temp_temp);
        //1.47
        if ((RTE_E_OK == Rte_TCU_Warn_high_temp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_TCU_Warn_high_temp))
        {
            if (TCU_Warn_high_temp_temp == 0x1)
            {
                enTransWarn = WN_enDISPLAY_ON;
            }
        }
    }
    else
    {
    }

    WN_SET(WN_enTransWarnStopCar, enTransWarnStopCar);
    WN_SET(WN_enTransWarning, enTransWarn);
    WN_SET(WN_enLockNGearDisable, enLockNGearDisable);
}
void WN_TransFailProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enTransFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTransLimited = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTransPutInPFailed = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTransReleasePFailed = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPlsPrsBrktoWait = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSelfLearnNotComplete = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enLearnSuccessPlsRelBrk = WN_enDISPLAY_OFF;
    //WN_CFG_enSTATUS_Common enElecShifterFault = WN_enDISPLAY_OFF;

    //Byte3 Bit7-bit0
    uint8 configTransmission = 0;
    //Byte38 Bit7-bit6
    uint8 configSpeedReverse = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;

    //DCT7 0x235 50ms
    //DCT_FD4 0x236 50ms
    uint8 DrvFaiMsg_temp = 0;
    uint8 Rte_SG_DCT7_Tmp = RTE_E_INVALID;
    uint8 Rte_SG_DCT_FD4_Tmp = RTE_E_INVALID;
    uint8 Rte_SG_HCU_HP5_Tmp = RTE_E_INVALID;
    //DHT_FD1 0x0C1 10ms
    uint8 TCU_ErrCategory_temp = 0;
    uint8 Rte_SG_DHT_FD1_Tmp = RTE_E_INVALID;
    //ACM1 0x10C 20ms
    uint8 ACM_Errcagy_temp = 0;
    uint8 Rte_ACM_Errcagy = RTE_E_INVALID;
    //DCT9 0x0C6 50ms
    uint8 TCU_Warn_gearbox_faulty_temp = 0;
    uint8 TCU_Warn_P_faulty_temp = 0;
    uint8 Rte_DCT9 = RTE_E_INVALID;

    configTransmission = (uint8)WN_GetSingleConfig(WN_enCfg_Transmission);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);
    configSpeedReverse = (uint8)WN_GetSingleConfig(WN_enCfg_SpeedReverse);

    if (EolConfig_Trans_CANFD())
    {
        Rte_SG_DCT_FD4_Tmp = WN_DrvFaiMsgFD_SignalGet(&DrvFaiMsg_temp);
    }
    else
    {
        Rte_SG_DCT7_Tmp = WN_DrvFaiMsg_SignalGet(&DrvFaiMsg_temp);
    }
	//7DCT,7DCT300S-GW,9DCT,9HDCT,9AT,9HAT
    if ((configTransmission == 7) ||
        (configTransmission == 38) ||
        (configTransmission == 15) ||
        (configTransmission == 16) ||
        (configTransmission == 39) ||
        (configTransmission == 40) ||
        (configTransmission == 41))
    {  
    	if ((RTE_E_OK == Rte_SG_DCT7_Tmp) ||
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_DCT7_Tmp) ||
        (RTE_E_OK == Rte_SG_DCT_FD4_Tmp) ||
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_DCT_FD4_Tmp))
	    {
            //1.48 case1/case2 common part
            if (DrvFaiMsg_temp == 0x1)
            {
                enTransFault = WN_enDISPLAY_ON;
            }
            else if (DrvFaiMsg_temp == 0xF)
            {
                enTransLimited = WN_enDISPLAY_ON;
            }
            else
            {
            }
	       
	        //9AT,9HAT
	        if(((configTransmission == 39) ||(configTransmission == 40)) && (configSpeedReverse == 1))//R14
	        {
	            //1.291
	            if(DrvFaiMsg_temp == 0x5)
	            {
	                m_enElecShifterFault = WN_enDISPLAY_ON;
	            }
				else
				{
					m_enElecShifterFault = WN_enDISPLAY_OFF;
				}
	        }
	    }
		else
		{
			m_enElecShifterFault = WN_enDISPLAY_OFF;
		}
    }
  
    //混联DHT
    if (configTransmission == 19)
    {
        //1.49
        Rte_SG_DHT_FD1_Tmp = WN_TCU_ErrCategory_SignalGet(&TCU_ErrCategory_temp);
        if ((RTE_E_OK == Rte_SG_DHT_FD1_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_DHT_FD1_Tmp))
        {
            if (((TCU_ErrCategory_temp & 0x02u) == 0x02u) || ((TCU_ErrCategory_temp & 0x04u) == 0x04u))
            {
                enTransLimited = WN_enDISPLAY_ON;
            }
            else
            {}
            if (((TCU_ErrCategory_temp & 0x08u) == 0x08u) || ((TCU_ErrCategory_temp & 0x10u) == 0x10u))
            {
                enTransFault = WN_enDISPLAY_ON;
            }
            else
            {}
        }
    }
    //串联DHT
    if (configTransmission == 18)
    {
        //1.50
        if ((RTE_E_OK == Rte_ACM_Errcagy) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_ACM_Errcagy))
        {
            if ((ACM_Errcagy_temp & 0x01u) == 1u)
            {
                enTransLimited = WN_enDISPLAY_ON;
            }
            else if (((ACM_Errcagy_temp & 0x02u) == 0x02u) || ((ACM_Errcagy_temp & 0x04u) == 0x04u))
            {
                enTransFault = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
    }
    //7DCT,7DCT300S-GW,9DCT,9HDCT,9AT,9HAT,PS,PS+P4
    if (((configSpeedReverse == 1) || (configSpeedReverse == 2))&&        
         ((configElecPosition == 5) || (configElecPosition == 6))) //modify bug P05-5335
    {
        Rte_SG_HCU_HP5_Tmp = WN_DrvFaiMsgHCU_SignalGet(&DrvFaiMsg_temp);
        //1.52
        if ((RTE_E_OK == Rte_SG_HCU_HP5_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_HCU_HP5_Tmp))
        {
            //case3,4
            if (DrvFaiMsg_temp == 0x2)
            {
                enTransPutInPFailed = WN_enDISPLAY_ON;
            }
            else if (DrvFaiMsg_temp == 0x3)
            {
                enTransReleasePFailed = WN_enDISPLAY_ON;
            }
            else if (DrvFaiMsg_temp == 0x4)
            {
                enPlsPrsBrktoWait = WN_enDISPLAY_ON;
            }
            else if (DrvFaiMsg_temp == 0x5)
            {
                enSelfLearnNotComplete = WN_enDISPLAY_ON;
            }
            else if (DrvFaiMsg_temp == 0x6)
            {
                enLearnSuccessPlsRelBrk = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
    }
    else if(((configTransmission == 7) ||
         (configTransmission == 38) ||
         (configTransmission == 15) ||
         (configTransmission == 16) ||
         (configTransmission == 39) ||
         (configTransmission == 40) ||
         (configTransmission == 41)) && (configSpeedReverse == 1))
    {
        if ((RTE_E_OK == Rte_SG_DCT7_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_DCT7_Tmp) ||
            (RTE_E_OK == Rte_SG_DCT_FD4_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_DCT_FD4_Tmp))
        {
            //case1,2
            if (DrvFaiMsg_temp == 0x2)
            {
                enTransPutInPFailed = WN_enDISPLAY_ON;
            }
            else if (DrvFaiMsg_temp == 0x3)
            {
                enTransReleasePFailed = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
    }
    //8AT
    if (configTransmission == 8)
    {
        Rte_DCT9 = WN_TCU_Warn_gearbox_faulty_SignalGet(&TCU_Warn_gearbox_faulty_temp);
        Rte_DCT9 = WN_TCU_Warn_P_faulty_SignalGet(&TCU_Warn_P_faulty_temp);
        if ((RTE_E_OK == Rte_DCT9) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_DCT9))
        {
            //1.51
            if (TCU_Warn_gearbox_faulty_temp == 0x1)
            {
                enTransFault = WN_enDISPLAY_ON;
            }
            //1.53
            if (TCU_Warn_P_faulty_temp == 0x1)
            {
                enTransPutInPFailed = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enTransFault, enTransFault);
    WN_SET(WN_enTransLimited, enTransLimited);
    WN_SET(WN_enTransPutInPFailed, enTransPutInPFailed);
    WN_SET(WN_enTransReleasePFailed, enTransReleasePFailed);
    WN_SET(WN_enPlsPrsBrktoWait, enPlsPrsBrktoWait);
    WN_SET(WN_enSelfLearnNotComplete, enSelfLearnNotComplete);
    WN_SET(WN_enLearnSuccessPlsRelBrk, enLearnSuccessPlsRelBrk);
    WN_SET(WN_enElecShifterFault, m_enElecShifterFault);
}
void WN_ShiftGearTipProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enStepBrake = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPressKey = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enBrakeAndKey = WN_enDISPLAY_OFF;

    //Byte3 Bit7-bit0
    uint8 configTransmission = 0;
    //Byte49 Bit5-bit4
    uint8 configShiftedUnlockKey = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;

    //DCT7 0x235 50ms
    //DCT_FD4 0x236 50ms
    uint8 DCT_PrsBrk_Warn_tmp = 0;
    uint8 Rte_SG_DCT7_Tmp = RTE_E_INVALID;
    uint8 Rte_SG_DCT_FD4_Tmp = RTE_E_INVALID;
    //HCU_HP5 0x201
    uint8 HCU_PrsBrkWarn_temp = 0;
    uint8 Rte_SG_HCU_HP5_Tmp = RTE_E_INVALID;
    //DCT9 0x0C6 50ms
    uint8 TCU_Warn_step_P_temp = 0;
    uint8 TCU_Warn_release_button_temp = 0;
    uint8 Rte_DCT9 = RTE_E_INVALID;

    configTransmission = (uint8)WN_GetSingleConfig(WN_enCfg_Transmission);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);
    configShiftedUnlockKey = (uint8)WN_GetSingleConfig(WN_enCfg_ShiftedUnlockKey);

    //7DCT,7DCT300S-GW,9DCT,9HDCT,9AT,9HAT
    if ((configTransmission == 7) ||
        (configTransmission == 38) ||
        (configTransmission == 15) ||
        (configTransmission == 16) ||
        (configTransmission == 39) ||
        (configTransmission == 40) ||
        (configTransmission == 41))
    {
        if (EolConfig_Trans_CANFD())
        {
            Rte_SG_DCT_FD4_Tmp = WN_DCT_PrsBrk_WarnFD_SignalGet(&DCT_PrsBrk_Warn_tmp);
        }
        else
        {
            Rte_SG_DCT7_Tmp = WN_DCT_PrsBrk_Warn_SignalGet(&DCT_PrsBrk_Warn_tmp);
        }
        if ((RTE_E_OK == Rte_SG_DCT7_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_DCT7_Tmp) ||
            (RTE_E_OK == Rte_SG_DCT_FD4_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_DCT_FD4_Tmp))
        {
            if (configShiftedUnlockKey == 1)
            {
                //1.54
                if (DCT_PrsBrk_Warn_tmp == 0x1)
                {
                    enBrakeAndKey = WN_enDISPLAY_ON;
                }
                else if (DCT_PrsBrk_Warn_tmp == 0x2)
                {
                    enPressKey = WN_enDISPLAY_ON;
                }
                else
                {
                }
            }
            //1.57
            if (DCT_PrsBrk_Warn_tmp == 0x3)
            {
                enStepBrake = WN_enDISPLAY_ON;
            }
        }
    }
    //PS/PS+P4
    if ((configElecPosition == 5) || (configElecPosition == 6))
    {
        Rte_SG_HCU_HP5_Tmp = WN_HCU_PrsBrkWarn_SignalGet(&HCU_PrsBrkWarn_temp);
        if ((RTE_E_OK == Rte_SG_HCU_HP5_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_HCU_HP5_Tmp))
        {
            if (configShiftedUnlockKey == 1)
            {
                //1.55
                if ((HCU_PrsBrkWarn_temp == 0x1) || (HCU_PrsBrkWarn_temp == 0x2))
                {
                    enBrakeAndKey = WN_enDISPLAY_ON;
                }
                else if(HCU_PrsBrkWarn_temp == 3)
                {
                    enStepBrake = WN_enDISPLAY_ON;
                }
            }
            else if(configShiftedUnlockKey == 0)
            {
                if(HCU_PrsBrkWarn_temp == 3)
                {
                    enStepBrake = WN_enDISPLAY_ON;
                }
            }
            else
            {
                /* do nothing */
            }
            //1.58
            if (HCU_PrsBrkWarn_temp == 0x3)
            {
                enStepBrake = WN_enDISPLAY_ON;
            }
        }
    }
    //8AT
    if (configTransmission == 8)
    {
        Rte_DCT9 = WN_TCU_Warn_release_button_SignalGet(&TCU_Warn_release_button_temp);
        Rte_DCT9 = WN_TCU_Warn_step_P_SignalGet(&TCU_Warn_step_P_temp);
        if ((RTE_E_OK == Rte_DCT9) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_DCT9))
        {
            if (configShiftedUnlockKey == 1)
            {
                //1.56
                if ((TCU_Warn_step_P_temp == 0x0) && (TCU_Warn_release_button_temp == 0x1))
                {
                    enPressKey = WN_enDISPLAY_ON;
                }
                else if ((TCU_Warn_step_P_temp == 0x1) && (TCU_Warn_release_button_temp == 0x1))
                {
                    enBrakeAndKey = WN_enDISPLAY_ON;
                }
                else
                {
                }
            }
            //1.59
            if ((TCU_Warn_step_P_temp == 0x1) && (TCU_Warn_release_button_temp == 0x0))
            {
                enStepBrake = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enShiftGearBrakeAndKey, enBrakeAndKey);
    WN_SET(WN_enShiftGearPressKey, enPressKey);
    WN_SET(WN_enShiftGearStepBrake, enStepBrake);
}
void WN_TransTipProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enShiftNotAllowed = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enShiftPStop = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enLockFailureN = WN_enDISPLAY_OFF;

    //Byte3 Bit7-bit0
    uint8 configTransmission = 0;
    //Byte38 Bit7-bit6
    uint8 configSpeedReverse = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;

    //DCT7 0x235 50ms
    //DCT_FD4 0x236 50ms
    uint8 DCT_ShftNotAlwd_Warn_temp = 0;
    uint8 Rte_SG_DCT7_Tmp = RTE_E_INVALID;
    uint8 Rte_SG_DCT_FD4_Tmp = RTE_E_INVALID;

    //HCU_HP5 0x201 50ms
    uint8 HCU_ShftNotAlwd_Warn_temp = 0;
    uint8 Rte_SG_HCU_HP5_Tmp = RTE_E_INVALID;

    uint8 TCU_Shift_not_allowed_Warn_temp = 0;
    uint8 Rte_TCU_Shift_not_allowed_Warn = RTE_E_INVALID;

    configTransmission = (uint8)WN_GetSingleConfig(WN_enCfg_Transmission);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);
    configSpeedReverse = (uint8)WN_GetSingleConfig(WN_enCfg_SpeedReverse);

    //7DCT,7DCT300S-GW,9DCT,9HDCT
    if ((configTransmission == 7) ||
        (configTransmission == 38) ||
        (configTransmission == 15) ||
        (configTransmission == 16) ||
        (configTransmission == 39) ||
        (configTransmission == 40) ||
        (configTransmission == 41))
    {
        if (EolConfig_Trans_CANFD())
        {
            Rte_SG_DCT_FD4_Tmp = WN_DCT_ShftNotAlwd_WarnFD_SignalGet(&DCT_ShftNotAlwd_Warn_temp);
        }
        else
        {
            Rte_SG_DCT7_Tmp = WN_DCT_ShftNotAlwd_Warn_SignalGet(&DCT_ShftNotAlwd_Warn_temp);
        }
        if ((RTE_E_OK == Rte_SG_DCT7_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_DCT7_Tmp) ||
            (RTE_E_OK == Rte_SG_DCT_FD4_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_DCT_FD4_Tmp))
        {
            if (configSpeedReverse == 1)
            {
                //1.60
                if (DCT_ShftNotAlwd_Warn_temp == 0x1)
                {
                    enShiftNotAllowed = WN_enDISPLAY_ON;
                }
                else if (DCT_ShftNotAlwd_Warn_temp == 0x2)
                {
                    enShiftPStop = WN_enDISPLAY_ON;
                }
                //1.63
                else if (DCT_ShftNotAlwd_Warn_temp == 0x3)
                {
                    enLockFailureN = WN_enDISPLAY_ON;
                }
                else
                {
                }
            }
        }
    }
    //PS/PS+P4
    if ((configElecPosition == 5) || (configElecPosition == 6))
    {
        Rte_SG_HCU_HP5_Tmp = WN_HCU_ShftNotAlwd_Warn_SignalGet(&HCU_ShftNotAlwd_Warn_temp);
        if ((RTE_E_OK == Rte_SG_HCU_HP5_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_HCU_HP5_Tmp))
        {
            if ((configSpeedReverse == 1) || (configSpeedReverse == 2))
            {
                //1.60
                if (HCU_ShftNotAlwd_Warn_temp == 0x1)
                {
                    enShiftNotAllowed = WN_enDISPLAY_ON;
                }
                else if (HCU_ShftNotAlwd_Warn_temp == 0x2)
                {
                    enShiftPStop = WN_enDISPLAY_ON;
                }
                //1.63
                else if (HCU_ShftNotAlwd_Warn_temp == 0x3)
                {
                    enLockFailureN = WN_enDISPLAY_ON;
                }
                else
                {
                }
            }
        }
    }
    //8AT
    if (configTransmission == 8)
    {
        //1.61
        Rte_TCU_Shift_not_allowed_Warn = WN_TCU_Shift_not_allowed_Warn_SignalGet(&TCU_Shift_not_allowed_Warn_temp);
        if ((RTE_E_OK == Rte_TCU_Shift_not_allowed_Warn) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_TCU_Shift_not_allowed_Warn))
        {
            if (TCU_Shift_not_allowed_Warn_temp == 0x1)
            {
                enShiftNotAllowed = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enShiftNotAllowed, enShiftNotAllowed);
    WN_SET(WN_enShiftPStop, enShiftPStop);
    WN_SET(WN_enLockFailureN, enLockFailureN);
}
void WN_LimpModeGearProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enLimpModeGearD = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enLimpModeGearP = WN_enDISPLAY_OFF;

    //Byte3 Bit7-bit0
    uint8 configTransmission = 0;

    //DCT9 0x0C6 50ms
    uint8 TCU_Warn_limphome_D_temp = 0;
    uint8 TCU_Warn_limphome_P_temp = 0;
    uint8 Rte_DCT9 = RTE_E_INVALID;

    configTransmission = (uint8)WN_GetSingleConfig(WN_enCfg_Transmission);

    if (configTransmission == 8)
    {
        Rte_DCT9 = WN_TCU_Warn_limphome_D_SignalGet(&TCU_Warn_limphome_D_temp);
        Rte_DCT9 = WN_TCU_Warn_limphome_P_Warn_SignalGet(&TCU_Warn_limphome_P_temp);
        if ((RTE_E_OK == Rte_DCT9) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_DCT9))
        {
            //1.64
            if (TCU_Warn_limphome_D_temp == 0x1)
            {
                enLimpModeGearD = WN_enDISPLAY_ON;
            }
            //1.65
            if (TCU_Warn_limphome_P_temp == 0x1)
            {
                enLimpModeGearP = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enLimpModeGearD, enLimpModeGearD);
    WN_SET(WN_enLimpModeGearP, enLimpModeGearP);
}
void WN_NoticeGearNProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enNoticeGearN = WN_enDISPLAY_OFF;

    //Byte3 Bit7-bit0
    uint8 configTransmission = 0;

    //DCT9 0x0C6 50ms
    uint8 TCU_Warn_gearbox_N_temp = 0;
    uint8 Rte_TCU_Warn_gearbox_N = RTE_E_INVALID;

    configTransmission = (uint8)WN_GetSingleConfig(WN_enCfg_Transmission);

    if (configTransmission == 8)
    {
        //1.66
        Rte_TCU_Warn_gearbox_N = WN_TCU_Warn_gearbox_N_Warn_SignalGet(&TCU_Warn_gearbox_N_temp);
        if ((RTE_E_OK == Rte_TCU_Warn_gearbox_N) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_TCU_Warn_gearbox_N))
        {
            if (TCU_Warn_gearbox_N_temp == 0x1)
            {
                enNoticeGearN = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enNoticeGearN, enNoticeGearN);
}
void WN_ElecShifterFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    //WN_CFG_enSTATUS_Common enElecShifterFault = WN_enDISPLAY_OFF;

    //Byte3 Bit7-bit0
    uint8 configTransmission = 0;

    //DCT9 0x0C6 50ms
    uint8 TCU_Warn_shifter_faulty_temp = 0;
    uint8 Rte_TCU_Warn_shifter_faulty = RTE_E_INVALID;

    configTransmission = (uint8)WN_GetSingleConfig(WN_enCfg_Transmission);

    if (configTransmission == 8)
    {
        //1.67
        Rte_TCU_Warn_shifter_faulty = WN_TCU_Warn_shifter_faulty_Warn_SignalGet(&TCU_Warn_shifter_faulty_temp);
        if ((RTE_E_OK == Rte_TCU_Warn_shifter_faulty) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_TCU_Warn_shifter_faulty))
        {
            if (TCU_Warn_shifter_faulty_temp == 0x1)
            {
                m_enElecShifterFault = WN_enDISPLAY_ON;
            }
			else
			{
				m_enElecShifterFault = WN_enDISPLAY_OFF;
			}
        }
		else
		{
			m_enElecShifterFault = WN_enDISPLAY_OFF;
		}
    }

    WN_SET(WN_enElecShifterFault, m_enElecShifterFault);
}
void WN_PowerSysFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enPowerSysFault = WN_enDISPLAY_OFF;

    //Byte3 Bit7-bit0
    uint8 configTransmission = 0;

    //DCT9 0x0C6 50ms
    uint8 TCU_Warn_drive_faulty_temp = 0;
    uint8 Rte_TCU_Warn_drive_faulty = RTE_E_INVALID;

    configTransmission = (uint8)WN_GetSingleConfig(WN_enCfg_Transmission);

    if (configTransmission == 8)
    {
        //1.68
        Rte_TCU_Warn_drive_faulty = WN_TCU_Warn_drive_faulty_Warn_SignalGet(&TCU_Warn_drive_faulty_temp);
        if ((RTE_E_OK == Rte_TCU_Warn_drive_faulty) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_TCU_Warn_drive_faulty))
        {
            if (TCU_Warn_drive_faulty_temp == 0x1)
            {
                enPowerSysFault = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enPowerSysFault, enPowerSysFault);
}
void WN_GearPWarningProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enGearPNeedStop = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enGearPNotSuitable = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enGearPSelect = WN_enDISPLAY_OFF;

    //Byte3 Bit7-bit0
    uint8 configTransmission = 0;

    //DCT9 0x0C6 50ms
    uint8 TCU_Warn_vehicle_P_temp = 0;
    uint8 TCU_Warn_prohibit_P_temp = 0;
    uint8 TCU_Warn_driver_leaves_car_temp = 0;
    uint8 Rte_DCT9 = RTE_E_INVALID;

    configTransmission = (uint8)WN_GetSingleConfig(WN_enCfg_Transmission);

    if (configTransmission == 8)
    {
        Rte_DCT9 = WN_TCU_Warn_vehicle_P_SignalGet(&TCU_Warn_vehicle_P_temp);
        Rte_DCT9 = WN_TCU_Warn_prohibit_P_SignalGet(&TCU_Warn_prohibit_P_temp);
        Rte_DCT9 = WN_TCU_Warn_driver_leaves_car_SignalGet(&TCU_Warn_driver_leaves_car_temp);
        if ((RTE_E_OK == Rte_DCT9) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_DCT9))
        {
            //1.69
            if (TCU_Warn_vehicle_P_temp == 0x1)
            {
                enGearPNeedStop = WN_enDISPLAY_ON;
            }
            //1.70
            if (TCU_Warn_prohibit_P_temp == 0x1)
            {
                enGearPNotSuitable = WN_enDISPLAY_ON;
            }
            //1.71
            if (TCU_Warn_driver_leaves_car_temp == 0x1)
            {
                enGearPSelect = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enGearPNeedStop, enGearPNeedStop);
    WN_SET(WN_enGearPNotSuitable, enGearPNotSuitable);
    WN_SET(WN_enGearPSelect, enGearPSelect);
}
void WN_4WDSystemWarnProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common en4WDSystemFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common en4WDSystemHeat = WN_enDISPLAY_OFF;

    //Byte30 Bit3-bit0
    uint8 configTransCase = 0;

    //Haldex1 0x251 20ms
    boolean DiagLmpReq_temp = FALSE;
    uint8 Rte_DiagLmpReq = RTE_E_INVALID;
    boolean CouplingThermWarning_temp = FALSE;
    uint8 Rte_CouplingThermWarning = RTE_E_INVALID;

    configTransCase = (uint8)WN_GetSingleConfig(WN_enCfg_TransCase);

    Rte_DiagLmpReq = WN_DiagLmpReq_SignalGet(&DiagLmpReq_temp);
    Rte_CouplingThermWarning = WN_CouplingThermWarning_SignalGet(&CouplingThermWarning_temp);

    if ((configTransCase == 1) || (configTransCase == 2) || (configTransCase == 3) || (configTransCase == 5))
    {
        if ((RTE_E_OK == Rte_DiagLmpReq) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_DiagLmpReq))
        {
            //1.72
            if (DiagLmpReq_temp == TRUE)
            {
                en4WDSystemFault = WN_enDISPLAY_ON;
            }
        }
    }
    if ((configTransCase == 2) || (configTransCase == 3) || (configTransCase == 5))
    {
        if ((RTE_E_OK == Rte_CouplingThermWarning) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_CouplingThermWarning))
        {
            //1.73
            if (CouplingThermWarning_temp == TRUE)
            {
                en4WDSystemHeat = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_en4WDSystemFault, en4WDSystemFault);
    WN_SET(WN_en4WDSystemHeat, en4WDSystemHeat);
}
void WN_FuelLowWarnProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enFuelLowWarn = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte84 Bit7-bit6
    uint8 configAuxFuel = 0;

    //Gauge模块获取
    FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE Fuel_Mode_Data = {0};

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configAuxFuel = (uint8)WN_GetSingleConfig(WN_enCfg_AuxFuel);

    WN_LowFuel_Active_APIGet(&Fuel_Mode_Data);

    if (((configFuel == 0) || (configFuel == 1) || (configFuel == 2) ||
        (configFuel == 3) || (configFuel == 4) || (configFuel == 7)) && (configAuxFuel == 0))
    {
        //1.74
        if ((Fuel_Mode_Data.Fuel_Warning_Status == 0x1) || (Fuel_Mode_Data.Fuel_Warning_Status == 0x3))
        {
            enFuelLowWarn = WN_enDISPLAY_ON;
        }
    }

    WN_SET(WN_enFuelLowWarn, enFuelLowWarn);
}
void WN_ORCruiseActiveProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enORCruiseActive = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enORExperMode = WN_enDISPLAY_OFF;

    //Byte44 Bit1-bit0
    uint8 configTab = 0;
    //Byte25 Bit3-bit2
    uint8 configORCruiseControl = 0;
    //Byte59 Bit3-bit2
    uint8 configOffRoadExpertMode = 0;
    //Byte25 Bit7-bit4
    uint8 configDrvModeOptionnal = 0;
    //Byte52 Bit7-bit2
    uint8 configDrvMode2 = 0;
    //Byte85 Bit7-bit4
    uint8 configDrvMode3 = 0;

    //BCM11 0x305 100ms
    uint8 TAB_SwtShift_Warn_temp = 0;
    uint8 Rte_TAB_SwtShift_Warn = RTE_E_INVALID;
    //ESP8 0x170 20ms
    boolean EspFuncOffSts_mode_temp = FALSE;
    uint8 Rte_EspFuncOffSts_mode = RTE_E_INVALID;

    configTab = (uint8)WN_GetSingleConfig(WN_enCfg_Tab);
    configORCruiseControl = (uint8)WN_GetSingleConfig(WN_enCfg_ORCruiseControl);
    configOffRoadExpertMode = (uint8)WN_GetSingleConfig(WN_enCfg_OffRoadExpertMode);
    configDrvModeOptionnal = (uint8)WN_GetSingleConfig(WN_enCfg_DrvModeOptionnal);
    configDrvMode2 = (uint8)WN_GetSingleConfig(WN_enCfg_DrvMode2);
    configDrvMode3 = (uint8)WN_GetSingleConfig(WN_enCfg_DrvMode3);

    Rte_TAB_SwtShift_Warn = WN_TAB_SwtShift_Warn_SignalGet(&TAB_SwtShift_Warn_temp);
    Rte_EspFuncOffSts_mode = WN_EspFuncOffSts_mode_SignalGet(&EspFuncOffSts_mode_temp);

    if ((configTab == 1) && (configORCruiseControl == 1))
    {
        //1.75
        if ((RTE_E_OK == Rte_TAB_SwtShift_Warn) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_TAB_SwtShift_Warn))
        {
            if (TAB_SwtShift_Warn_temp == 0x1)
            {
                enORCruiseActive = WN_enDISPLAY_ON;
            }
        }
    }
    if (configOffRoadExpertMode == 0)
    {
        //1.140
        if (((configDrvModeOptionnal == 9) || (configDrvModeOptionnal == 10) ||
             (configDrvModeOptionnal == 12) || (configDrvModeOptionnal == 13)) &&
            (configDrvMode2 == 0) &&
            (configDrvMode3 == 0))
        {
            if ((RTE_E_OK == Rte_EspFuncOffSts_mode) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_EspFuncOffSts_mode))
            {
                if (EspFuncOffSts_mode_temp == TRUE)
                {
                    enORExperMode = WN_enDISPLAY_ON;
                }
            }
        }
        else if (((configDrvMode2 == 10) || (configDrvMode2 == 15)) &&
                 (configDrvModeOptionnal == 0) &&
                 (configDrvMode3 == 0))
        {
            if ((RTE_E_OK == Rte_EspFuncOffSts_mode) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_EspFuncOffSts_mode))
            {
                if (EspFuncOffSts_mode_temp == TRUE)
                {
                    enORExperMode = WN_enDISPLAY_ON;
                }
            }
        }
        else if ((configDrvModeOptionnal == 0) && (configDrvMode2 == 0) && \
                 ((configDrvMode3 == 2) || (configDrvMode3 == 11) || \
                 (configDrvMode3 == 12) || (configDrvMode3 == 13) || (configDrvMode3 == 14) || \
                 (configDrvMode3 == 15) || (configDrvMode3 == 16) || (configDrvMode3 == 18) || \
                 (configDrvMode3 == 19) || (configDrvMode3 == 30) || (configDrvMode3 == 31)))
        {
            if ((RTE_E_OK == Rte_EspFuncOffSts_mode) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_EspFuncOffSts_mode))
            {
                if (EspFuncOffSts_mode_temp == TRUE)
                {
                    enORExperMode = WN_enDISPLAY_ON;
                }
            }
        }
        else
        {
        }
    }
    else if (configOffRoadExpertMode == 1)
    {
        if ((RTE_E_OK == Rte_EspFuncOffSts_mode) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_EspFuncOffSts_mode))
        {
            if (EspFuncOffSts_mode_temp == TRUE)
            {
                enORExperMode = WN_enDISPLAY_ON;
            }
        }
    }
    else
    {
    }
    WN_SET(WN_enORCruiseActive, enORCruiseActive);
    WN_SET(WN_enORExperMode, enORExperMode);
}
void WN_ESP8Process(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enCCOTargetSpeed0 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enCCOTargetSpeed1 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enCCOTargetSpeed2 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enCCOTargetSpeed3 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enCCOTargetSpeed4 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enCCOTargetSpeed5 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enCCOTargetSpeed6 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enCCOTargetSpeed7 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enCCOTargetSpeed8 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSlowTargetSpeed0 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSlowTargetSpeed1 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSlowTargetSpeed2 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSlowTargetSpeed3 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSlowTargetSpeed4 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSlowTargetSpeed5 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSlowTargetSpeed6 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSlowTargetSpeed7 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSlowTargetSpeed8 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enReleaseElecParkCCO = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPleaseSlowDown = WN_enDISPLAY_OFF;

    //Byte25 Bit3-bit2
    uint8 configORCruiseControl = 0;

    //ESP8 0x170 20ms
    uint8 CCO_Active_temp = 0;
    uint8 CCO_TgtVel_temp = 0;
    uint8 CCO_Warn_temp = 0;
    uint8 Rte_ESP8Sts = RTE_E_INVALID;

    configORCruiseControl = (uint8)WN_GetSingleConfig(WN_enCfg_ORCruiseControl);

    Rte_ESP8Sts = WN_CCO_Active_SignalGet(&CCO_Active_temp);
    Rte_ESP8Sts = WN_CCO_TgtVel_SignalGet(&CCO_TgtVel_temp);
    Rte_ESP8Sts = WN_CCO_Warn_SignalGet(&CCO_Warn_temp);

    if ((configORCruiseControl == 1) || (configORCruiseControl == 2))
    {
        if ((RTE_E_OK == Rte_ESP8Sts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_ESP8Sts))
        {
            //1.77
            if (CCO_Warn_temp == 0x1)
            {
                enReleaseElecParkCCO = WN_enDISPLAY_ON;
            }
            else if (CCO_Warn_temp == 0x2)
            {
                enPleaseSlowDown = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
        if (configORCruiseControl == 1)
        {
            if ((RTE_E_OK == Rte_ESP8Sts) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_ESP8Sts))
            {
                //1.145
                if ((CCO_Active_temp == 0x1) || (CCO_Active_temp == 0x2))//R14 change
                {
                    if (CCO_TgtVel_temp == 0x0)
                    {
                        enCCOTargetSpeed0 = WN_enDISPLAY_ON;
                    }
                    else if (CCO_TgtVel_temp == 0x1)
                    {
                        enCCOTargetSpeed1 = WN_enDISPLAY_ON;
                    }
                    else if (CCO_TgtVel_temp == 0x2)
                    {
                        enCCOTargetSpeed2 = WN_enDISPLAY_ON;
                    }
                    else if (CCO_TgtVel_temp == 0x3)
                    {
                        enCCOTargetSpeed3 = WN_enDISPLAY_ON;
                    }
                    else if (CCO_TgtVel_temp == 0x4)
                    {
                        enCCOTargetSpeed4 = WN_enDISPLAY_ON;
                    }
                    else if (CCO_TgtVel_temp == 0x5)
                    {
                        enCCOTargetSpeed5 = WN_enDISPLAY_ON;
                    }
                    else if (CCO_TgtVel_temp == 0x6)
                    {
                        enCCOTargetSpeed6 = WN_enDISPLAY_ON;
                    }
                    else if (CCO_TgtVel_temp == 0x7)
                    {
                        enCCOTargetSpeed7 = WN_enDISPLAY_ON;
                    }
                    else if (CCO_TgtVel_temp == 0x8)
                    {
                        enCCOTargetSpeed8 = WN_enDISPLAY_ON;
                    }
                }
            }
        }
        if (configORCruiseControl == 2)
        {
            if ((RTE_E_OK == Rte_ESP8Sts) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_ESP8Sts))
            {
                //1.216
                if (CCO_Active_temp == 0x1)
                {
                    if (CCO_TgtVel_temp == 0x3)
                    {
                        enSlowTargetSpeed0 = WN_enDISPLAY_ON;
                    }
                    else if (CCO_TgtVel_temp == 0x4)
                    {
                        enSlowTargetSpeed1 = WN_enDISPLAY_ON;
                    }
                    else if (CCO_TgtVel_temp == 0x5)
                    {
                        enSlowTargetSpeed2 = WN_enDISPLAY_ON;
                    }
                    else if (CCO_TgtVel_temp == 0x6)
                    {
                        enSlowTargetSpeed3 = WN_enDISPLAY_ON;
                    }
                    else if (CCO_TgtVel_temp == 0x7)
                    {
                        enSlowTargetSpeed4 = WN_enDISPLAY_ON;
                    }
                    else if (CCO_TgtVel_temp == 0x8)
                    {
                        enSlowTargetSpeed5 = WN_enDISPLAY_ON;
                    }
                    else if (CCO_TgtVel_temp == 0x9)
                    {
                        enSlowTargetSpeed6 = WN_enDISPLAY_ON;
                    }
                    else if (CCO_TgtVel_temp == 0xA)
                    {
                        enSlowTargetSpeed7 = WN_enDISPLAY_ON;
                    }
                    else if (CCO_TgtVel_temp == 0xB)
                    {
                        enSlowTargetSpeed8 = WN_enDISPLAY_ON;
                    }
                }
            }
        }
    }

    WN_SET(WN_enCCOTargetSpeed0, enCCOTargetSpeed0);
    WN_SET(WN_enCCOTargetSpeed1, enCCOTargetSpeed1);
    WN_SET(WN_enCCOTargetSpeed2, enCCOTargetSpeed2);
    WN_SET(WN_enCCOTargetSpeed3, enCCOTargetSpeed3);
    WN_SET(WN_enCCOTargetSpeed4, enCCOTargetSpeed4);
    WN_SET(WN_enCCOTargetSpeed5, enCCOTargetSpeed5);
    WN_SET(WN_enCCOTargetSpeed6, enCCOTargetSpeed6);
    WN_SET(WN_enCCOTargetSpeed7, enCCOTargetSpeed7);
    WN_SET(WN_enCCOTargetSpeed8, enCCOTargetSpeed8);
    WN_SET(WN_enSlowTargetSpeed0, enSlowTargetSpeed0);
    WN_SET(WN_enSlowTargetSpeed1, enSlowTargetSpeed1);
    WN_SET(WN_enSlowTargetSpeed2, enSlowTargetSpeed2);
    WN_SET(WN_enSlowTargetSpeed3, enSlowTargetSpeed3);
    WN_SET(WN_enSlowTargetSpeed4, enSlowTargetSpeed4);
    WN_SET(WN_enSlowTargetSpeed5, enSlowTargetSpeed5);
    WN_SET(WN_enSlowTargetSpeed6, enSlowTargetSpeed6);
    WN_SET(WN_enSlowTargetSpeed7, enSlowTargetSpeed7);
    WN_SET(WN_enSlowTargetSpeed8, enSlowTargetSpeed8);
    WN_SET(WN_enReleaseElecParkCCO, enReleaseElecParkCCO);
    WN_SET(WN_enPleaseSlowDown, enPleaseSlowDown);
}
void WN_DynBattLowEVProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enForwardChargeMode = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;

    //BMS_FD1 0x0F2 10ms TBD
    uint16 BMS_SOC = 0;
    uint8 Rte_BMS_SOC = RTE_E_INVALID;
    uint8 f1_VCU_ChrgnSts = 0;
    uint8 Rte_VCU_ChrgnSts = RTE_E_INVALID;
    uint8 f1_OBC_CCLineConnectSts = 0;
    uint8 Rte_OBC_CCLineConnectSts = RTE_E_INVALID;
    uint8 f1_Phone_ChrgnMode = 0;
    uint8 Rte_Phone_ChrgnMode = RTE_E_INVALID;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);

    //Com_ReceiveSignal(COM_SINGAL_RX_BMS_FD1_BMS_SOC, &BMS_SOC);
    Rte_BMS_SOC = WN_BMS_SOC(&BMS_SOC);//R18
    Rte_VCU_ChrgnSts = WN_VCU_ChrgnSts_SignalGet(&f1_VCU_ChrgnSts);//R18
    Rte_OBC_CCLineConnectSts = WN_OBC_CCLineConnectSts_SignalGet(&f1_OBC_CCLineConnectSts);//R18
    Rte_Phone_ChrgnMode = WN_Phone_ChrgnMode(&f1_Phone_ChrgnMode);

    if (configFuel == 5)
    {
        //1.78
        if(((RTE_E_OK == Rte_VCU_ChrgnSts) ||
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_VCU_ChrgnSts)) &&
        ((RTE_E_OK == Rte_BMS_SOC) || 
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_BMS_SOC)))
        {
            if ((BMS_SOC <= 0xFA) && (f1_VCU_ChrgnSts != 0x1)) //<=%25
            {
                m_enDynamicBatteryLow = WN_enDISPLAY_ON;
            }
            else if ((BMS_SOC > 0x10E) || (((BMS_SOC > 0xFA) && (BMS_SOC <= 0x10E)) && (f1_VCU_ChrgnSts != 0x1))) //>%27
            {
                m_enDynamicBatteryLow = WN_enDISPLAY_OFF;
            }
            else if(BMS_SOC > 0x10E)
            {
                m_enDynamicBatteryLow = WN_enDISPLAY_OFF;
            }
            else
            {
            }
        }
        //1.274
        if(((RTE_E_OK == Rte_OBC_CCLineConnectSts) ||
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_OBC_CCLineConnectSts)) &&
        ((RTE_E_OK == Rte_Phone_ChrgnMode) || 
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_Phone_ChrgnMode)))
        {
            if((f1_OBC_CCLineConnectSts == 0x1) && (f1_Phone_ChrgnMode == 0x1))
            {

            }
        }
    }

    WN_SET(WN_enDynBattLowEV, m_enDynamicBatteryLow);
    WN_SET(WN_enForwardChargeMode,enForwardChargeMode);
}
void WN_AdaptiveCruiseControlProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enACCSensorDetectLimited = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enACCCruiseFunFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enACCTakeoverReq = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enACCUnavailable = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enACCHWATakeOver = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enACCHWATakeOver_2Hz = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enACCHWATakeOver_4Hz = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enACCHWATakeAtte = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enACCHWATakeAtte_2Hz = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enACCHWATakeAtte_4Hz = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enACCHWACrossTunnel = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enACCHWABranchRoad = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enACCISLCruiseSpeed = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enACCISLSlowDown = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enACCHWAFuncFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTurnSafeSlow = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enLowSpeedLaneAssistDisable = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enUrgeTurnPlsHoldWheel = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enOverSpeedLaneAssistDisable = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enCarAutoBrakePlsTake = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enCarParkingPlsTake = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enCarUrgeBrakePlsTake = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTJAICAFaultPlsFixCamera = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTJAICAFaultPlsFix = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPlsTakeOver = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPlsTakeOver_2Hz = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPlsTakeOver_4Hz = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTurnGearDownConfirmSpeedAdjustment = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPressCruiseConfirmAdjustment = WN_enDISPLAY_OFF;
		
    //Byte10 Bit3-bit0
    uint8 configFCWAEB = 0;
    //Byte28 Bit7-bit4
    uint8 configCruiseControl = 0;
    //Byte45 Bit7-bit5
    uint8 configHighwayAssist = 0;
    //Byte2 Bit3-bit0
    uint8 configTrafficSign = 0;
    //Byte82 Bit3-bit2
    //uint8 configNOH = 0;//R12 Del NOH Cfg
    //Byte104 Bit3-Bit2
    uint8 configTFV = 0;
    //Byte103 Bit7-Bit5
    uint8 configTFC = 0;
	//Byte113 Bit7-Bit5
	uint8 configCBW = 0;

    //ACC_FD2 0x2AB 100ms
    uint8 ACC_InterSysInfoDisp_temp = 0;
    uint8 ACC_TakeOverReq_temp = 0;
    uint8 TJA_ICA_InterSysInfoDisp_temp = 0;
    uint8 ISL_InterSysInfoDisp_temp = 0;
    uint8 HWA_warning_temp = 0;
    uint8 HWA_InterSysInfoDisp_temp = 0;
    uint8 ALC_InterSysInfoDisp_temp = 0;
    //uint8 ISL_InterSysInfoDisp_ICU1_5 = 0;
    uint8 fl_HWA_WarnInfoDisp = 0;  //IFC_FD3 0x2CF 100ms
    uint8 MRC_TakOver_Req = 0; //IFC_FD3 0x2CF 100ms
    uint8 Rte_SG_ACC3_ACC_FD2_Tmp = RTE_E_INVALID;
    uint8 Rte_SG_ACC4_ACC_FD2_Tmp = RTE_E_INVALID;
    uint8 Rte_SG_ACC8_ACC_FD2_Tmp = RTE_E_INVALID;
    uint8 Rte_MRC_TakOver_Req = RTE_E_INVALID;
    //uint8 Rte_ISL_InterSysInfoDisp_ICU1_5 = RTE_E_INVALID;
    uint8 fl_HWA_TakOver_Trig = 0;
    uint8 fl_HWA_TakOver_Req = 0;
    uint8 Rte_SG_IFC_FD3 = RTE_E_INVALID;
    uint8 fl_HWA_Text_Lib = 0;
    uint8 Rte_HWA_Text_Lib = RTE_E_INVALID;
    uint8 fl_TJA_FollowSts = 0;
    uint8 fl_LaneAvailability = 0;
    uint8 Rte_IFC_FD2 = RTE_E_INVALID;
    uint8 Rte_Request_driveoff = RTE_E_INVALID;
    uint8 f1_Request_driveoff = 0;

    configCruiseControl = (uint8)WN_GetSingleConfig(WN_enCfg_CruiseControl);
    configFCWAEB = (uint8)WN_GetSingleConfig(WN_enCfg_FCWAEB);
    configHighwayAssist = (uint8)WN_GetSingleConfig(WN_enCfg_HighwayAssist);
    configTrafficSign = (uint8)WN_GetSingleConfig(WN_enCfg_TrafficSign);
    configTFV = (uint8)WN_GetSingleConfig(WN_encfg_TFV);
    configTFC = (uint8)WN_GetSingleConfig(WN_encfg_TFC);
    //configNOH = (uint8)WN_GetSingleConfig(WN_enCfg_NOH);//R12 Del NOH Cfg
    configCBW = (uint8)WN_GetSingleConfig(WN_encfg_CBW);//R15

    Rte_SG_ACC4_ACC_FD2_Tmp = WN_ACC_InterSysInfoDisp_SignalGet(&ACC_InterSysInfoDisp_temp);
    Rte_SG_ACC4_ACC_FD2_Tmp = WN_ACC_TakeOverReq_SignalGet(&ACC_TakeOverReq_temp);
    Rte_SG_ACC4_ACC_FD2_Tmp = WN_TJA_ICA_InterSysInfoDisp_SignalGet(&TJA_ICA_InterSysInfoDisp_temp);
    Rte_SG_ACC4_ACC_FD2_Tmp = WN_ISL_InterSysInfoDisp_SignalGet(&ISL_InterSysInfoDisp_temp);
    Rte_SG_ACC8_ACC_FD2_Tmp = WN_HWA_InterSysInfoDisp_SignalGet(&HWA_InterSysInfoDisp_temp);
    Rte_SG_ACC8_ACC_FD2_Tmp = WN_HWA_warning_SignalGet(&HWA_warning_temp);
    Rte_SG_ACC3_ACC_FD2_Tmp = WN_ALC_InterSysInfoDisp_SignalGet(&ALC_InterSysInfoDisp_temp);
    Rte_SG_IFC_FD3 = WN_HWA_WarnInfoDisp_SignalGet(&fl_HWA_WarnInfoDisp);
    Rte_MRC_TakOver_Req = WN_MRC_TakOver_Req_SignalGet(&MRC_TakOver_Req);
    //Rte_ISL_InterSysInfoDisp_ICU1_5 = WN_ISL_InterSysInfoDisp_ICU1_5_SignalGet(&ISL_InterSysInfoDisp_ICU1_5);//R12
    Rte_SG_IFC_FD3 = WN_HWA_TakOver_Trig_SignalGet_ICU1_5(&fl_HWA_TakOver_Trig);
    Rte_SG_IFC_FD3 = WN_HWA_TakOver_Req_SignalGet_ICU1_5(&fl_HWA_TakOver_Req);
    //Rte_HWA_Text_Lib = WN_HWA_Text_Lib_SignalGet(&fl_HWA_Text_Lib);
    Rte_IFC_FD2 = WN_TJA_FollowSts_SignalGet(&fl_TJA_FollowSts);
    //Rte_IFC_FD2 = WN_LaneAvailability_SignalGet(&fl_LaneAvailability);
    Rte_Request_driveoff = WN_Request_driveoff_SignalGet(&f1_Request_driveoff);

    if ((configCruiseControl == 2) || (configCruiseControl == 3) || (configCruiseControl == 8) ||
        (configCruiseControl == 7) || (configCruiseControl == 4) || (configCruiseControl == 9) ||
        (configCruiseControl == 5) || (configCruiseControl == 10) || (configCruiseControl == 11) ||
        (configCruiseControl == 6) || (configFCWAEB == 1) || (configFCWAEB == 2) ||
        (configFCWAEB == 3) || (configFCWAEB == 4) || (configFCWAEB == 5))
    {
        if ((RTE_E_OK == Rte_SG_ACC4_ACC_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ACC4_ACC_FD2_Tmp))
        {
            //1.191
            if (ACC_InterSysInfoDisp_temp == 0x9)
            {
                enACCSensorDetectLimited = WN_enDISPLAY_ON;
            }
        }
    }
    if ((configCruiseControl == 2) || (configCruiseControl == 3) || (configCruiseControl == 8) ||
        (configCruiseControl == 7) || (configCruiseControl == 4) || (configCruiseControl == 9) ||
        (configCruiseControl == 5) || (configCruiseControl == 10) || (configCruiseControl == 11) ||
        (configCruiseControl == 6))
    {
        if ((RTE_E_OK == Rte_SG_ACC4_ACC_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ACC4_ACC_FD2_Tmp))
        {
            //1.198
            if (ACC_TakeOverReq_temp == 0x1)
            {
                enACCTakeoverReq = WN_enDISPLAY_ON;
            }
        }
    }
    if ((configCruiseControl == 2) || (configCruiseControl == 3) || (configCruiseControl == 8) ||
        (configCruiseControl == 7) || (configCruiseControl == 4) || (configCruiseControl == 9) ||
        (configCruiseControl == 5) || (configCruiseControl == 10) || (configCruiseControl == 11) ||
        (configCruiseControl == 6))
    {
        if ((RTE_E_OK == Rte_SG_ACC4_ACC_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ACC4_ACC_FD2_Tmp))
        {
            //1.199
            if (ACC_InterSysInfoDisp_temp == 0x7)
            {
                enACCCruiseFunFault = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
    }
    if ((configCruiseControl == 3) || (configCruiseControl == 8) ||
        (configCruiseControl == 4) || (configCruiseControl == 9) ||
        (configCruiseControl == 5) || (configCruiseControl == 10) ||
        (configCruiseControl == 11) || (configCruiseControl == 6))
    {
        //1.201
        if ((RTE_E_OK == Rte_SG_ACC4_ACC_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ACC4_ACC_FD2_Tmp))
        {
            //ICU1.0/ICU1.5/ICU2.0/ICU3.0 R17
            if((configTFC == 1) || (configTFC == 2) || (configTFC == 3) || (configTFC == 4) || ((configTFC == 0)))
            {
                //case 1、2
                if (TJA_ICA_InterSysInfoDisp_temp == 0x3)
                {
                    enACCUnavailable = WN_enDISPLAY_ON;
                }
                
            }
        }
        if(configTFC == 4)//ICU3.0
        {
            //case 2
            if((RTE_E_OK == Rte_IFC_FD2) || \
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_IFC_FD2))
            {
                if(fl_TJA_FollowSts == 0x1)
                {
                    /* 请注意周边安全 */
                }
            }
        }
        if(5 == configTFC)//ICU1.5H
        {
            //DE07
        }
        //1.202
        if((RTE_E_OK == Rte_Request_driveoff) || \
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_Request_driveoff))
        {
            if(f1_Request_driveoff == 0x1)
            {
                /* 前车已起步 */
            }
            else if (f1_Request_driveoff == 0x2)
            {
                /* 前车已起步，请注意前方道路环境 */
            }
            else if(f1_Request_driveoff == 0x3)
            {
                /* 前车已起步，请保持注意力 */
            }
            else if(f1_Request_driveoff == 0x4)
            {
                /* 前车驶离，请踩油门 */
            }
            else if(f1_Request_driveoff == 0x5)
            {
                /* 请轻踩油门确认起步 */
            }
            else
            {}          
        }
    }
    if (configHighwayAssist == 1)//R12 Del NOH Cfg
    {    
        //1.204
        if((RTE_E_OK == Rte_SG_IFC_FD3) || \
           (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_IFC_FD3))
        {
            if(fl_HWA_WarnInfoDisp == 0x6)//R13
            {
                enTJAICAFaultPlsFixCamera = WN_enDISPLAY_ON;
            }
            else if(fl_HWA_WarnInfoDisp == 0x7)
            {
                enTJAICAFaultPlsFix = WN_enDISPLAY_ON;
            }
            else
            {}
        }
        if ((RTE_E_OK == Rte_SG_ACC8_ACC_FD2_Tmp) || \
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ACC8_ACC_FD2_Tmp))
        {
            if (HWA_InterSysInfoDisp_temp == 0x8)
            {
                enLowSpeedLaneAssistDisable = WN_enDISPLAY_ON;
            }
            else if (HWA_InterSysInfoDisp_temp == 0xC)
            {
                enACCHWACrossTunnel = WN_enDISPLAY_ON;
            }
            else if (HWA_InterSysInfoDisp_temp == 0xD)
            {
                enACCHWABranchRoad = WN_enDISPLAY_ON;
            }
            else if (HWA_InterSysInfoDisp_temp == 0xE)
            {
                enUrgeTurnPlsHoldWheel = WN_enDISPLAY_ON;
            }
            else if (HWA_InterSysInfoDisp_temp == 0xF)
            {
                enOverSpeedLaneAssistDisable = WN_enDISPLAY_ON;
            }
        
            //1.205
            else if ((HWA_InterSysInfoDisp_temp == 0xA) && \
				((configTFC == 1) || (configTFC == 2) || (configTFC == 3) || (configTFC == 0)))//ICU1.0/ICU1.5/ICU2.0 R16/R18
            {
                if (HWA_warning_temp == 0x1)
                {
                    enACCHWATakeOver = WN_enDISPLAY_ON;
                }
                else if (HWA_warning_temp == 0x2)
                {
                    enACCHWATakeOver_2Hz = WN_enDISPLAY_ON;
                }
                else if (HWA_warning_temp == 0x3)
                {
                    enACCHWATakeOver_4Hz = WN_enDISPLAY_ON;
                }
                else
                {
                }
            }
            else
            {}
        }
        if (((RTE_E_OK == Rte_SG_IFC_FD3) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_IFC_FD3)) && \
            ((RTE_E_OK == Rte_SG_ACC8_ACC_FD2_Tmp) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ACC8_ACC_FD2_Tmp)))
        {
        	//1.197 R18
            if(fl_HWA_WarnInfoDisp == 0xD)
            {
                if(HWA_warning_temp == 0x1)
                {
                    enACCHWATakeAtte = WN_enDISPLAY_ON;
                }
                else if (HWA_warning_temp == 0x2)
                {
                    enACCHWATakeAtte_2Hz = WN_enDISPLAY_ON;
                }
                else if (HWA_warning_temp == 0x3)
                {
                    enACCHWATakeAtte_4Hz = WN_enDISPLAY_ON;
                }
                else
                {}
            }
        }
        if ((RTE_E_OK == Rte_SG_ACC8_ACC_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ACC8_ACC_FD2_Tmp))
        {
            if(HWA_InterSysInfoDisp_temp == 0xB)
            {
                if(HWA_warning_temp == 0x1)
                {
                    enACCHWATakeAtte = WN_enDISPLAY_ON;
                }
                else if (HWA_warning_temp == 0x2)
                {
                    enACCHWATakeAtte_2Hz = WN_enDISPLAY_ON;
                }
                else if (HWA_warning_temp == 0x3)
                {
                    enACCHWATakeAtte_4Hz = WN_enDISPLAY_ON;
                }
                else
                {}
            }
        }

        if (((RTE_E_OK == Rte_SG_ACC4_ACC_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ACC4_ACC_FD2_Tmp)) && 
            ((RTE_E_OK == Rte_SG_IFC_FD3) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_IFC_FD3)))
        {
            if((fl_HWA_TakOver_Trig == 0x0) && (fl_HWA_TakOver_Req == 0x2))
            {
                if(HWA_warning_temp == 0x1)
                {
                    enPlsTakeOver = WN_enDISPLAY_ON;
                }
                else if (HWA_warning_temp == 0x2)
                {
                    enPlsTakeOver_2Hz = WN_enDISPLAY_ON;
                }
                else if (HWA_warning_temp == 0x3)
                {
                    enPlsTakeOver_4Hz = WN_enDISPLAY_ON;
                }
                else
                {}
            }
        }
            
    #ifdef GWM_V35_PROJECT_TYPE_D01_ICU3
        if((configHighwayAssist == 1) && (0x4 == configTFC))
        {
            //1.304
            if ((RTE_E_OK == Rte_SG_ACC8_ACC_FD2_Tmp) || \
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ACC8_ACC_FD2_Tmp))
            {
                if (HWA_InterSysInfoDisp_temp == 0xC)
                {
                    enACCHWACrossTunnel = WN_enDISPLAY_ON;
                }
                else if (HWA_InterSysInfoDisp_temp == 0xD)
                {
                    enACCHWABranchRoad = WN_enDISPLAY_ON;
                }
                else if (HWA_InterSysInfoDisp_temp == 0xE)
                {
                    enUrgeTurnPlsHoldWheel = WN_enDISPLAY_ON;
                }
                else if (HWA_InterSysInfoDisp_temp == 0xF)
                {
                    enOverSpeedLaneAssistDisable = WN_enDISPLAY_ON;
                }
                else
                {
                    /* do nothing */
                }
            }
            if((RTE_E_OK == Rte_SG_IFC_FD3) || \
               (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_IFC_FD3))
            {
                if(fl_HWA_WarnInfoDisp == 0x6)//R13
                {
                    enTJAICAFaultPlsFixCamera = WN_enDISPLAY_ON;
                }
                else if(fl_HWA_WarnInfoDisp == 0x7)
                {
                    enTJAICAFaultPlsFix = WN_enDISPLAY_ON;
                }
                else
                {
                    /* do nothing */
                }
            }
            if (((RTE_E_OK == Rte_SG_IFC_FD3) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_IFC_FD3)) && \
                ((RTE_E_OK == Rte_SG_ACC8_ACC_FD2_Tmp) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ACC8_ACC_FD2_Tmp)))
            {
                if(fl_HWA_WarnInfoDisp == 0xD)
                {
                    if(HWA_warning_temp == 0x1)
                    {
                        enACCHWATakeAtte = WN_enDISPLAY_ON;
                    }
                    else if (HWA_warning_temp == 0x2)
                    {
                        enACCHWATakeAtte_2Hz = WN_enDISPLAY_ON;
                    }
                    else if (HWA_warning_temp == 0x3)
                    {
                        enACCHWATakeAtte_4Hz = WN_enDISPLAY_ON;
                    }
                    else
                    {}
                }
            }
            if ((RTE_E_OK == Rte_SG_ACC8_ACC_FD2_Tmp) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ACC8_ACC_FD2_Tmp))
            {
                if(HWA_InterSysInfoDisp_temp == 0xB)
                {
                    if(HWA_warning_temp == 0x1)
                    {
                        enACCHWATakeAtte = WN_enDISPLAY_ON;
                    }
                    else if (HWA_warning_temp == 0x2)
                    {
                        enACCHWATakeAtte_2Hz = WN_enDISPLAY_ON;
                    }
                    else if (HWA_warning_temp == 0x3)
                    {
                        enACCHWATakeAtte_4Hz = WN_enDISPLAY_ON;
                    }
                    else
                    {}
                }
            }
            if (((RTE_E_OK == Rte_SG_ACC4_ACC_FD2_Tmp) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ACC4_ACC_FD2_Tmp)) && 
                ((RTE_E_OK == Rte_SG_IFC_FD3) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_IFC_FD3)))
            {
                if((fl_HWA_TakOver_Trig == 0x0) && (fl_HWA_TakOver_Req == 0x2))
                {
                    if(HWA_warning_temp == 0x1)
                    {
                        enPlsTakeOver = WN_enDISPLAY_ON;
                    }
                    else if (HWA_warning_temp == 0x2)
                    {
                        enPlsTakeOver_2Hz = WN_enDISPLAY_ON;
                    }
                    else if (HWA_warning_temp == 0x3)
                    {
                        enPlsTakeOver_4Hz = WN_enDISPLAY_ON;
                    }
                    else
                    {}
                }
            }

        }
    #else
    #endif
        if ((RTE_E_OK == Rte_SG_ACC3_ACC_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ACC3_ACC_FD2_Tmp))
        {
            //1.206
            if (ALC_InterSysInfoDisp_temp == 1)
            {
                enACCHWAFuncFault = WN_enDISPLAY_ON;
            }
        }
    }
    if(configTFV == 1)//R12
    {
        if ((RTE_E_OK == Rte_MRC_TakOver_Req) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_MRC_TakOver_Req))
        {
            //1.272
            if(MRC_TakOver_Req == 0x1)
            {
                enCarAutoBrakePlsTake = WN_enDISPLAY_ON;
            }
            else if(MRC_TakOver_Req == 0x2)
            {
                enCarParkingPlsTake = WN_enDISPLAY_ON;
            }
            else if(MRC_TakOver_Req == 0x3)
            {
                enCarUrgeBrakePlsTake = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
    }
    if ((configTrafficSign == 3) || (configTrafficSign == 4))
    {
        if ((RTE_E_OK == Rte_SG_ACC4_ACC_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ACC4_ACC_FD2_Tmp))
        {
            //1.203       R18
            if (ISL_InterSysInfoDisp_temp == 0x1)
            {
                if (0x1 == configCBW)
                {
                    enACCISLCruiseSpeed = WN_enDISPLAY_ON;
                }
                else if (0x2 == configCBW)
                {
                    enTurnGearDownConfirmSpeedAdjustment = WN_enDISPLAY_ON;
                }
                else if (0x3 == configCBW)
                {
                    enPressCruiseConfirmAdjustment = WN_enDISPLAY_ON;
                }
                else if (0x4 == configCBW)
                {
                    //TBD
                }
                else
                {
                }
            }
            else if (ISL_InterSysInfoDisp_temp == 0x2)
            {
                enACCISLSlowDown = WN_enDISPLAY_ON;
            }
            else if (ISL_InterSysInfoDisp_temp == 0x3)
            {
                enTurnSafeSlow = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
    }

    WN_SET(WN_enACCSensorDetectLimited, enACCSensorDetectLimited);
    WN_SET(WN_enACCCruiseFunFault, enACCCruiseFunFault);
    WN_SET(WN_enACCTakeOverBrake, enACCTakeoverReq);
    WN_SET(WN_enACCUnavailable, enACCUnavailable);
    WN_SET(WN_enACCHWATakeOver, enACCHWATakeOver);
    WN_SET(WN_enACCHWATakeOver_2Hz, enACCHWATakeOver_2Hz);
    WN_SET(WN_enACCHWATakeOver_4Hz, enACCHWATakeOver_4Hz);
    WN_SET(WN_enACCHWATakeAtte, enACCHWATakeAtte);
    WN_SET(WN_enACCHWATakeAtte_2Hz, enACCHWATakeAtte_2Hz);
    WN_SET(WN_enACCHWATakeAtte_4Hz, enACCHWATakeAtte_4Hz);
    WN_SET(WN_enACCHWACrossTunnel, enACCHWACrossTunnel);
    WN_SET(WN_enACCHWABranchRoad, enACCHWABranchRoad);
    WN_SET(WN_enACCISLCruiseSpeed, enACCISLCruiseSpeed);
    WN_SET(WN_enACCISLSlowDown, enACCISLSlowDown);
    WN_SET(WN_enACCHWAFuncFault, enACCHWAFuncFault);
    WN_SET(WN_enTurnSafeSlow, enTurnSafeSlow);
    WN_SET(WN_enLowSpeedLaneAssistDisable, enLowSpeedLaneAssistDisable);
    WN_SET(WN_enUrgeTurnPlsHoldWheel, enUrgeTurnPlsHoldWheel);
    WN_SET(WN_enOverSpeedLaneAssistDisable, enOverSpeedLaneAssistDisable);
    WN_SET(WN_enCarAutoBrakePlsTake, enCarAutoBrakePlsTake);
    WN_SET(WN_enCarParkingPlsTake, enCarParkingPlsTake);
    WN_SET(WN_enCarUrgeBrakePlsTake, enCarUrgeBrakePlsTake);
    WN_SET(WN_enTJAICAFaultPlsFixCamera, enTJAICAFaultPlsFixCamera);
    WN_SET(WN_enTJAICAFaultPlsFix, enTJAICAFaultPlsFix);
    WN_SET(WN_enPlsTakeOver, enPlsTakeOver);
    WN_SET(WN_enPlsTakeOver_2Hz, enPlsTakeOver_2Hz);
    WN_SET(WN_enPlsTakeOver_4Hz, enPlsTakeOver_4Hz);
	WN_SET(WN_enTurnGearDownConfirmSpeedAdjustment, enTurnGearDownConfirmSpeedAdjustment);
	WN_SET(WN_enPressCruiseConfirmAdjustment, enPressCruiseConfirmAdjustment);
}
void WN_ChargeDevRemovedProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enChargeDevRemoved = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDischargeDeviceRemoved = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;

    //OBC2 0x317 100ms
    uint8 OBC_ConnectSts_temp = 0;
    uint8 Rte_OBC_ConnectSts = RTE_E_INVALID;
    uint8 BMS_StsCC2Line_temp = 0;
    uint8 Rte_BMS_StsCC2Line = RTE_E_INVALID;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);

    Rte_OBC_ConnectSts = WN_OBC_ConnectSts_SignalGet(&OBC_ConnectSts_temp);
    Rte_BMS_StsCC2Line = WN_BMS_StsCC2Line_SignalGet(&BMS_StsCC2Line_temp);

    if ((configFuel == 4) &&
        ((configElecPosition == 2) || (configElecPosition == 4) || (configElecPosition == 5) || 
        (configElecPosition == 6) || ((configElecPosition == 8)))) //PHEV+P2/P2+P4/PS/PS+P4/纵置P2
    {
        //1.80
        //case1    
        if ((RTE_E_OK == Rte_OBC_ConnectSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_OBC_ConnectSts))
        {
            if ((m_u8OBC_ConnectSts_pre == 0x1) && (OBC_ConnectSts_temp == 0x0))
            {
                enChargeDevRemoved = WN_enDISPLAY_ON;
            }
			else if((m_u8OBC_ConnectSts_pre == 0x3) && (OBC_ConnectSts_temp == 0x0))
			{
				enDischargeDeviceRemoved = WN_enDISPLAY_ON;
			}
            m_u8OBC_ConnectSts_pre = OBC_ConnectSts_temp;
        }
        //case2
        if(((RTE_E_OK == Rte_OBC_ConnectSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_OBC_ConnectSts)) && 
            ((RTE_E_OK == Rte_BMS_StsCC2Line) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_BMS_StsCC2Line)))
        {
            if(((m_u8OBC_ConnectSts_pre == 0x1) && (OBC_ConnectSts_temp == 0x0)) || ((m_u8BMS_StsCC2Line_pre == 0x1) && (BMS_StsCC2Line_temp == 0x0)))
            {
                enChargeDevRemoved = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enChargeDevRemoved, enChargeDevRemoved);
    WN_SET(WN_enDischargeDeviceRemoved, enDischargeDeviceRemoved);
}
void WN_HCUPT4Process(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enDynBattLow = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enChargeDevDisconnect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enGearChngP = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enChargeDevConnect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enReadyNoRefuel = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enChargingNoRefuel = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRefuelingNoCharge = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enGearChngPN = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enStopBrakeGearN = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enWashModeActive = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enWashModeSpeed = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enWashModeBatt = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPedalDynBatt = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPedalDynSnow = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enBattTempLowPowerDown = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enBattTempHighPowerDown = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDisconnectChargingDischarging = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;

    //HCU_PT4 0x2FA 100ms
    uint8 HCU_RefuReq_temp = 0;
    boolean HCU_InhbChrgInfo_temp = FALSE;
    uint8 HCU_GearChngPorNTXT_temp = 0;
    boolean HCU_Shift_P_Indcn_temp = FALSE;
    boolean OPDParkWarnReq_temp = FALSE;
    boolean CarWashMode_Sts_temp = FALSE;
    uint8 CarWashMode_StsDisp_temp = 0;
    uint8 HCU_OPDFails_temp = 0;
    boolean HCU_SOCLow_Indcn_temp = FALSE;
    boolean HCU_RemoveChrgLine_Indcn_temp = FALSE;
    boolean HCU_ConnectChrgLine_Indcn_temp = FALSE;
    uint8 HCU_BattPowerRedWarn_temp = 0;
    uint8 Rte_SG_HCU_PT4_Tmp = RTE_E_INVALID;
    uint8 Rte_OPDParkWarnReq = RTE_E_INVALID;
    uint8 Rte_CarWashMode_Sts = RTE_E_INVALID;
    uint8 Rte_CarWashMode_StsDisp = RTE_E_INVALID;
    uint8 Rte_HCU_BattPowerRedWarn = RTE_E_INVALID;
    uint8 Rte_HCU_OPDFails = RTE_E_INVALID;
    uint8 Rte_HCU_GearChngPorNTXT = RTE_E_INVALID;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);

    Rte_SG_HCU_PT4_Tmp = WN_HCU_SOCLow_Indcn_SignalGet(&HCU_SOCLow_Indcn_temp);
    Rte_SG_HCU_PT4_Tmp = WN_HCU_RemoveChrgLine_Indcn_SignalGet(&HCU_RemoveChrgLine_Indcn_temp);
    Rte_SG_HCU_PT4_Tmp = WN_HCU_Shift_P_Indcn_SignalGet(&HCU_Shift_P_Indcn_temp);
    Rte_SG_HCU_PT4_Tmp = WN_HCU_ConnectChrgLine_Indcn_SignalGet(&HCU_ConnectChrgLine_Indcn_temp);
    Rte_SG_HCU_PT4_Tmp = WN_HCU_RefuReq_Indcn_SignalGet(&HCU_RefuReq_temp);
    Rte_SG_HCU_PT4_Tmp = WN_HCU_InhbChrgInfo_SignalGet(&HCU_InhbChrgInfo_temp);
    Rte_OPDParkWarnReq = WN_OPDParkWarnReq_SignalGet(&OPDParkWarnReq_temp);
    Rte_CarWashMode_Sts = WN_CarWashMode_Sts_SignalGet(&CarWashMode_Sts_temp);
    Rte_CarWashMode_StsDisp = WN_CarWashMode_StsDisp_SignalGet(&CarWashMode_StsDisp_temp);
    Rte_HCU_BattPowerRedWarn = WN_HCU_BattPowerRedWarn_SignalGet(&HCU_BattPowerRedWarn_temp);
    Rte_HCU_OPDFails = WN_HCU_OPDFail_SignalGet(&HCU_OPDFails_temp);
    Rte_HCU_GearChngPorNTXT = WN_HCU_GearChngPorNTXT_SignalGet(&HCU_GearChngPorNTXT_temp);

    if ((RTE_E_OK == Rte_SG_HCU_PT4_Tmp) ||
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_HCU_PT4_Tmp))
    {
        if ((configFuel == 4) &&
            ((configElecPosition == 2) || (configElecPosition == 4) || (configElecPosition == 5) || 
            (configElecPosition == 6) || (configElecPosition == 8))) //PHEV+P2/P2+P4/PS/PS+P4/纵置P2
        {
            //1.79
            if (HCU_SOCLow_Indcn_temp == TRUE)
            {
                enDynBattLow = WN_enDISPLAY_ON;
            }
            //1.82
            if (HCU_Shift_P_Indcn_temp == TRUE)
            {
                enGearChngP = WN_enDISPLAY_ON;
            }
            //1.84
            if (HCU_ConnectChrgLine_Indcn_temp == TRUE)
            {
                enChargeDevConnect = WN_enDISPLAY_ON;
            }
        }
        //1.81
        if ((configFuel == 4) &&
            ((configElecPosition == 2) || (configElecPosition == 4) || (configElecPosition == 5) || \
            (configElecPosition == 6))) //PHEV+P2/P2+P4/PS/PS+P4
        {
            //case 1
            if (HCU_RemoveChrgLine_Indcn_temp == TRUE)
            {
                enChargeDevDisconnect = WN_enDISPLAY_ON;
            }
        }
        else if((configFuel == 4) && (configElecPosition == 8))//PHEV+纵置P2
        {
            //case 2
            if (HCU_RemoveChrgLine_Indcn_temp == TRUE)
            {
                enDisconnectChargingDischarging = WN_enDISPLAY_ON;
            }
        }
    }
    if (((configFuel == 0) || (configFuel == 1) || (configFuel == 2) || (configFuel == 7)) && (configElecPosition == 1))
    {
        if ((RTE_E_OK == Rte_HCU_GearChngPorNTXT) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_GearChngPorNTXT))
        {
            //1.83
            if (HCU_GearChngPorNTXT_temp == 0x1)
            {
                enGearChngPN = WN_enDISPLAY_ON;
            }
        }
    }
    if ((configFuel == 4) &&
        ((configElecPosition == 2) || (configElecPosition == 4) || 
        (configElecPosition == 5) || (configElecPosition == 6) || (configElecPosition == 8))) //PHEV+P2/P2+P4/PS/PS+P4/纵置P2
    {
        if ((RTE_E_OK == Rte_SG_HCU_PT4_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_HCU_PT4_Tmp))
        {
            //1.149
            if ((HCU_RefuReq_temp == 0x2) || (HCU_RefuReq_temp == 0x3))
            {
                enReadyNoRefuel = WN_enDISPLAY_ON;
            }
            else if (HCU_RefuReq_temp == 0x4)
            {
                enChargingNoRefuel = WN_enDISPLAY_ON;
            }
            else
            {
            }
            //1.150
            if (HCU_InhbChrgInfo_temp == TRUE)
            {
                enRefuelingNoCharge = WN_enDISPLAY_ON;
            }
        }
    }
    if (((configFuel == 3) && 
        ((configElecPosition == 5) || (configElecPosition == 6))) || //HEV+PS/PS+P4
        (((configFuel == 4) && 
        ((configElecPosition == 2) || (configElecPosition == 4) || (configElecPosition == 5) || (configElecPosition == 6))))) //PHEV+P2/(P2+P4)/PS/PS+P4
    {
        if ((RTE_E_OK == Rte_OPDParkWarnReq) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_OPDParkWarnReq))
        {
            //1.162
            if (OPDParkWarnReq_temp == TRUE)
            {
                enStopBrakeGearN = WN_enDISPLAY_ON;
            }
        }
        if ((RTE_E_OK == Rte_HCU_OPDFails) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_OPDFails))
        {
            //1.168
            if (HCU_OPDFails_temp == 0x1)
            {
                enPedalDynBatt = WN_enDISPLAY_ON;
            }
            if (HCU_OPDFails_temp == 0x2)
            {
                enPedalDynSnow = WN_enDISPLAY_ON;
            }
        }
    }
    if (((configFuel == 3) || (configFuel == 4)) && ((configElecPosition == 5) || (configElecPosition == 6))) //HEV/PHEV+PS/PS+P4
    {
        if (((RTE_E_OK == Rte_CarWashMode_Sts) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_CarWashMode_Sts)) && 
            ((RTE_E_OK == Rte_CarWashMode_StsDisp) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_CarWashMode_StsDisp)))
        {
            //1.163
            if (CarWashMode_Sts_temp == TRUE)
            {
                enWashModeActive = WN_enDISPLAY_ON;
            }
            if ((CarWashMode_Sts_temp == FALSE) && (CarWashMode_StsDisp_temp == 0x1))
            {
                enWashModeSpeed = WN_enDISPLAY_ON;
            }
            if ((CarWashMode_Sts_temp == FALSE) && (CarWashMode_StsDisp_temp == 0x2))
            {
                enWashModeBatt = WN_enDISPLAY_ON;
            }
            
        }
        if ((RTE_E_OK == Rte_HCU_BattPowerRedWarn) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_BattPowerRedWarn))
        {
            //1.221
            if (HCU_BattPowerRedWarn_temp == 0x1)
            {
                enBattTempLowPowerDown = WN_enDISPLAY_ON;
            }
            else if (HCU_BattPowerRedWarn_temp == 0x2)
            {
                enBattTempHighPowerDown = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
    }
    if (((configFuel == 0) || (configFuel == 1) || (configFuel == 2) || (configFuel == 7)) && (configElecPosition == 1))
    {
        if ((RTE_E_OK == Rte_HCU_BattPowerRedWarn) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_BattPowerRedWarn))
        {
            //1.221
            if (HCU_BattPowerRedWarn_temp == 0x1)
            {
                //enBattTempLowPowerDown = WN_enDISPLAY_ON;//R15 delete
            }
            else if (HCU_BattPowerRedWarn_temp == 0x2)
            {
                //enBattTempHighPowerDown = WN_enDISPLAY_ON;//R15 delete
            }
            else
            {
            }
        }
    }

    WN_SET(WN_enDynBattLow, enDynBattLow);
    WN_SET(WN_enChargeDevDisconnect, enChargeDevDisconnect);
    WN_SET(WN_enGearChngP, enGearChngP);
    WN_SET(WN_enChargeDevConnect, enChargeDevConnect);
    WN_SET(WN_enReadyNoRefuel, enReadyNoRefuel);
    WN_SET(WN_enChargingNoRefuel, enChargingNoRefuel);
    WN_SET(WN_enRefuelingNoCharge, enRefuelingNoCharge);
    WN_SET(WN_enGearChngPN, enGearChngPN);
    WN_SET(WN_enStopBrakeGearN, enStopBrakeGearN);
    WN_SET(WN_enWashModeActive, enWashModeActive);
    WN_SET(WN_enWashModeSpeed, enWashModeSpeed);
    WN_SET(WN_enWashModeBatt, enWashModeBatt);
    WN_SET(WN_enPedalDynBatt, enPedalDynBatt);
    WN_SET(WN_enPedalDynSnow, enPedalDynSnow);
    WN_SET(WN_enBattTempLowPowerDown, enBattTempLowPowerDown);
    WN_SET(WN_enBattTempHighPowerDown, enBattTempHighPowerDown);
    WN_SET(WN_enDisconnectChargingDischarging, enDisconnectChargingDischarging);
}
void WN_HCUPT7Process(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enDrvSysFaultRepair = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enHybSysFaultRepair = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enStartingSysFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enFrontAxleSysFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enBSGSysFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enHybSysLimited = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRecoverySysFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRearAxleSysFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enHybSysFault_Stop = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enHybSysUnavailable = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common en12VFaultStop = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common en12VFaultRepair = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;

    //HCU_PT7 0x248 50ms
    boolean HCU_HybSysErr_3_temp = FALSE;
    boolean HCU_HybSysErr_5_temp = FALSE;
    boolean HCU_HybSysErr_6_temp = FALSE;
    boolean HCU_HybSysErr_7_temp = FALSE;
    boolean HCU_HybSysErr_4_temp = FALSE;
    boolean HCU_HybSysErr_1_temp = FALSE;
    boolean HCU_HybSysErr_2_temp = FALSE;
    boolean HCU_HybSysErr_8 = FALSE;    //TBD
    boolean HCU_12VSysErr_1_temp = FALSE;
    boolean HCU_12VSysErr_2_temp = FALSE;
    uint8 Rte_SG_HCU_PT7_Tmp = RTE_E_INVALID;
    uint8 Rte_SG_HCU_PT7_Tmp_P05 = RTE_E_INVALID;
    uint8 Rte_HCU_HybSysErr_4 = RTE_E_INVALID;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);

    Rte_SG_HCU_PT7_Tmp = WN_HCU_HybSysErr_5_SignalGet(&HCU_HybSysErr_5_temp);
	Rte_SG_HCU_PT7_Tmp_P05 = WN_HCU_HybSysErr_5_SignalGet(&HCU_HybSysErr_5_temp);
    Rte_SG_HCU_PT7_Tmp = WN_HCU_HybSysErr_3_SignalGet(&HCU_HybSysErr_3_temp);
    Rte_SG_HCU_PT7_Tmp = WN_HCU_HybSysErr_6_SignalGet(&HCU_HybSysErr_6_temp);
    Rte_SG_HCU_PT7_Tmp = WN_HCU_HybSysErr_7_SignalGet(&HCU_HybSysErr_7_temp);
    Rte_HCU_HybSysErr_4 = WN_HCU_HybSysErr_4_SignalGet(&HCU_HybSysErr_4_temp);
    Rte_SG_HCU_PT7_Tmp = WN_HCU_HybSysErr_1_SignalGet(&HCU_HybSysErr_1_temp);
    Rte_SG_HCU_PT7_Tmp = WN_HCU_HybSysErr_2_SignalGet(&HCU_HybSysErr_2_temp);
    Rte_SG_HCU_PT7_Tmp = WN_HCU_12VSysErr_1_SignalGet(&HCU_12VSysErr_1_temp);
    Rte_SG_HCU_PT7_Tmp = WN_HCU_12VSysErr_2_SignalGet(&HCU_12VSysErr_2_temp);

    if ((RTE_E_OK == Rte_SG_HCU_PT7_Tmp_P05) ||
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_HCU_PT7_Tmp_P05))
    {
        if (HCU_HybSysErr_5_temp == TRUE)
        {
            //1.93
            if (((configFuel == 3) || (configFuel == 4)) && ((configElecPosition == 5) || (configElecPosition == 6))) //HEV/PHEV+PS/PS+P4
            {
                enStartingSysFault = WN_enDISPLAY_ON;
            }
            //1.94
            if (((configFuel == 3) || (configFuel == 4)) && ((configElecPosition == 2) || (configElecPosition == 4) || (configElecPosition == 8))) //HEV/PHEV+P2/(P2+P4)/纵置P2
            {
                enFrontAxleSysFault = WN_enDISPLAY_ON;
            }
            //1.95
            if (((configFuel == 0) || (configFuel == 1) || (configFuel == 2) || (configFuel == 7)) && (configElecPosition == 1))
            {
                enBSGSysFault = WN_enDISPLAY_ON;
            }
        }
    }
    if (((configFuel == 3) && 
        ((configElecPosition == 2) || (configElecPosition == 5) || (configElecPosition == 6) || (configElecPosition == 8))) || //HEV+P2//PS/PS+P4/纵置P2
        ((configFuel == 4) && 
        ((configElecPosition == 2) || (configElecPosition == 4) || (configElecPosition == 5) || (configElecPosition == 6) ||(configElecPosition == 8))) || //PHEV+P2/P2+P4/PS/PS+P4/纵置P2
        (((configFuel == 0) || (configFuel == 1) || (configFuel == 2) || (configFuel == 7)) && (configElecPosition == 1)))
    {
        if ((RTE_E_OK == Rte_SG_HCU_PT7_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_HCU_PT7_Tmp))
        {
            //1.96
            if (HCU_HybSysErr_3_temp == TRUE)
            {
                enHybSysFaultRepair = WN_enDISPLAY_ON;
            }
            //1.97
            if (HCU_HybSysErr_6_temp == TRUE)
            {
                enHybSysLimited = WN_enDISPLAY_ON;
            }
            //1.98
            if (HCU_HybSysErr_7_temp == TRUE)
            {
                enRecoverySysFault = WN_enDISPLAY_ON;
            }
            //1.100
            if (HCU_HybSysErr_1_temp == TRUE)
            {
                enHybSysFault_Stop = WN_enDISPLAY_ON;
            }
            //1.101
            if (HCU_HybSysErr_2_temp == TRUE)
            {
                enHybSysUnavailable = WN_enDISPLAY_ON;
            }
            //1.151
            if (HCU_12VSysErr_1_temp == TRUE)
            {
                en12VFaultStop = WN_enDISPLAY_ON;
            }
            //1.151
            if (HCU_12VSysErr_2_temp == TRUE)
            {
                en12VFaultRepair = WN_enDISPLAY_ON;
            }
        }
    }
    if ((RTE_E_OK == Rte_HCU_HybSysErr_4) ||
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_HybSysErr_4))
    {
        //1.99
        if (((configFuel == 3) || (configFuel == 4)) && ((configElecPosition == 5) || (configElecPosition == 6)))//case 1/2/4/5
        {
            if (HCU_HybSysErr_4_temp == TRUE)
            {
                enDrvSysFaultRepair = WN_enDISPLAY_ON;
            }
        }
        if ((configFuel == 4) && (configElecPosition == 4))//case3
        {
            if (HCU_HybSysErr_4_temp == TRUE)
            {
                enRearAxleSysFault = WN_enDISPLAY_ON;
            }
        }
        if(((configFuel == 3) || (configFuel == 4)) && (configElecPosition == 6))//case4/5
        {
            if(0)
            {
                if(HCU_HybSysErr_8 == 8)//TBD
                {
                    enRearAxleSysFault = WN_enDISPLAY_ON;
                }
            }
        }
    }

    WN_SET(WN_enDrvSysFault_Repair, enDrvSysFaultRepair);
    WN_SET(WN_enHybSysFault_Repair, enHybSysFaultRepair);
    WN_SET(WN_enStartingSysFault, enStartingSysFault);
    WN_SET(WN_enFrontAxleSysFault, enFrontAxleSysFault);
    WN_SET(WN_enBSGSysFault, enBSGSysFault);
    WN_SET(WN_enHybSysLimited, enHybSysLimited);
    WN_SET(WN_enRecoverySysFault, enRecoverySysFault);
    WN_SET(WN_enRearAxleSysFault, enRearAxleSysFault);
    WN_SET(WN_enHybSysFault_Stop, enHybSysFault_Stop);
    WN_SET(WN_enHybSysUnavailable, enHybSysUnavailable);
    WN_SET(WN_en12VFaultStop, en12VFaultStop);
    WN_SET(WN_en12VFaultRepair, en12VFaultRepair);
}
void WN_HCUPT8Process(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enChargePortWarning = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enChargerTempHigh = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPowerBatteryTempHigh = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPowerBatteryTempLow = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enChargerPWReduced = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enChargeDevConnectErr = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enChargerFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enChargeSysFault = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;

    //HCU_PT8 0x1C0 50ms
    boolean HCU_ChrgSysErr_3_temp = FALSE;
    uint8 Rte_HCU_ChrgSysErr_3 = RTE_E_INVALID;
    boolean HCU_ChrgSysErr_4_temp = FALSE;
    uint8 Rte_HCU_ChrgSysErr_4 = RTE_E_INVALID;
    boolean HCU_ChrgSysErr_5_temp = FALSE;
    uint8 Rte_HCU_ChrgSysErr_5 = RTE_E_INVALID;
    boolean HCU_ChrgSysErr_6_temp = FALSE;
    uint8 Rte_HCU_ChrgSysErr_6 = RTE_E_INVALID;
    boolean HCU_ChrgSysErr_7_temp = FALSE;
    uint8 Rte_HCU_ChrgSysErr_7 = RTE_E_INVALID;
    boolean HCU_ChrgSysErr_8_temp = FALSE;
    uint8 Rte_HCU_ChrgSysErr_8 = RTE_E_INVALID;
    boolean HCU_ChrgSysErr_1_temp = FALSE;
    uint8 Rte_HCU_ChrgSysErr_1 = RTE_E_INVALID;
    boolean HCU_ChrgSysErr_2_temp = FALSE;
    uint8 Rte_HCU_ChrgSysErr_2 = RTE_E_INVALID;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);

    Rte_HCU_ChrgSysErr_3 = WN_HCU_ChrgSysErr_3_SignalGet(&HCU_ChrgSysErr_3_temp);
    Rte_HCU_ChrgSysErr_4 = WN_HCU_ChrgSysErr_4_SignalGet(&HCU_ChrgSysErr_4_temp);
    Rte_HCU_ChrgSysErr_5 = WN_HCU_ChrgSysErr_5_SignalGet(&HCU_ChrgSysErr_5_temp);
    Rte_HCU_ChrgSysErr_6 = WN_HCU_ChrgSysErr_6_SignalGet(&HCU_ChrgSysErr_6_temp);
    Rte_HCU_ChrgSysErr_7 = WN_HCU_ChrgSysErr_7_SignalGet(&HCU_ChrgSysErr_7_temp);
    Rte_HCU_ChrgSysErr_8 = WN_HCU_ChrgSysErr_8_SignalGet(&HCU_ChrgSysErr_8_temp);
    Rte_HCU_ChrgSysErr_1 = WN_HCU_ChrgSysErr_1_SignalGet(&HCU_ChrgSysErr_1_temp);
    Rte_HCU_ChrgSysErr_2 = WN_HCU_ChrgSysErr_2_SignalGet(&HCU_ChrgSysErr_2_temp);

    if ((configFuel == 4) &&
        ((configElecPosition == 2) || (configElecPosition == 4) || (configElecPosition == 5) || 
        (configElecPosition == 6) || (configElecPosition == 8))) //PHEV+P2/P2+P4/PS/PS+P4/纵置P2
    { 
        if ((RTE_E_OK == Rte_HCU_ChrgSysErr_3) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_ChrgSysErr_3))
        {
            //1.85
            if (HCU_ChrgSysErr_3_temp == TRUE)
            {
                enChargePortWarning = WN_enDISPLAY_ON;
            }
        }
        if ((RTE_E_OK == Rte_HCU_ChrgSysErr_4) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_ChrgSysErr_4))
        {
            //1.86
            if (HCU_ChrgSysErr_4_temp == TRUE)
            {
                enChargerTempHigh = WN_enDISPLAY_ON;
            }
        }
        if ((RTE_E_OK == Rte_HCU_ChrgSysErr_5) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_ChrgSysErr_5))
        {
            //1.87
            if (HCU_ChrgSysErr_5_temp == TRUE)
            {
                enPowerBatteryTempHigh = WN_enDISPLAY_ON;
            }
        }
        if ((RTE_E_OK == Rte_HCU_ChrgSysErr_6) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_ChrgSysErr_6))
        {
            //1.88
            if (HCU_ChrgSysErr_6_temp == TRUE)
            {
                enPowerBatteryTempLow = WN_enDISPLAY_ON;
            }
        }
        if ((RTE_E_OK == Rte_HCU_ChrgSysErr_7) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_ChrgSysErr_7))
        {
            //1.89
            if (HCU_ChrgSysErr_7_temp == TRUE)
            {
                enChargerPWReduced = WN_enDISPLAY_ON;
            }
        }
        if ((RTE_E_OK == Rte_HCU_ChrgSysErr_8) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_ChrgSysErr_8))
        {
            //1.90
            if (HCU_ChrgSysErr_8_temp == TRUE)
            {
                enChargeDevConnectErr = WN_enDISPLAY_ON;
            }
        }
        if ((RTE_E_OK == Rte_HCU_ChrgSysErr_1) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_ChrgSysErr_1))
        {
            //1.91
            if (HCU_ChrgSysErr_1_temp == TRUE)
            {
                enChargerFault = WN_enDISPLAY_ON;
            }
        }
        if ((RTE_E_OK == Rte_HCU_ChrgSysErr_2) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_ChrgSysErr_2))
        {
            //1.92
            if (HCU_ChrgSysErr_2_temp == TRUE)
            {
                enChargeSysFault = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enChargePortWarning, enChargePortWarning);
    WN_SET(WN_enChargerTempHigh, enChargerTempHigh);
    WN_SET(WN_enDynBattTempHigh, enPowerBatteryTempHigh);
    WN_SET(WN_enDynBattTempLow, enPowerBatteryTempLow);
    WN_SET(WN_enChargerPWReduced, enChargerPWReduced);
    WN_SET(WN_enChargeDevConnectErr, enChargeDevConnectErr);
    WN_SET(WN_enChargerFault, enChargerFault);
    WN_SET(WN_enChargeSysFault, enChargeSysFault);
}
void WN_DynBattSysFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enDynBattSysFault_Repair = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDynBattSysFault_Stop = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPowerSystemLimited = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;

    //BMS4 0x0F1 10ms
    uint8 BMS_ErrCategory_temp = 0;
    uint8 Rte_SG_BMS4_Tmp = RTE_E_INVALID;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);

    Rte_SG_BMS4_Tmp = WN_BMS_ErrCategory_SignalGet(&BMS_ErrCategory_temp);

    //HEV+P2/PS+P4/纵置P2
     if(((configFuel == 0x3)   || (configFuel == 0x4)) && ((configElecPosition == 0x5) ||\
		(configElecPosition == 0x6) || (configElecPosition == 0x8)))//R16 CASE1
    {
        //1.102
        if ((RTE_E_OK == Rte_SG_BMS4_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_BMS4_Tmp))
        {
            if ((BMS_ErrCategory_temp == 0x3) || (BMS_ErrCategory_temp == 0x4))
            {
                enDynBattSysFault_Repair = WN_enDISPLAY_ON;
            }
            else if ((BMS_ErrCategory_temp == 0x5) || (BMS_ErrCategory_temp == 0x6) || (BMS_ErrCategory_temp == 0x7))
            {
                enDynBattSysFault_Stop = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
    }
	else if(((configFuel == 0x3) || (configFuel == 0x4)) && ((configElecPosition == 0x4) || (configElecPosition == 0x2)))//CASE2
	{
		//1.102
        if ((RTE_E_OK == Rte_SG_BMS4_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_BMS4_Tmp))
        {
            if ((BMS_ErrCategory_temp == 0x3) || (BMS_ErrCategory_temp == 0x4))
            {
                enDynBattSysFault_Repair = WN_enDISPLAY_ON;
            }
            else if ((BMS_ErrCategory_temp == 0x5) || (BMS_ErrCategory_temp == 0x6) || (BMS_ErrCategory_temp == 0x7))
            {
                enPowerSystemLimited = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
	}

    WN_SET(WN_enDynBattSysFault_Repair, enDynBattSysFault_Repair);
    WN_SET(WN_enDynBattSysFault_Stop, enDynBattSysFault_Stop);
    WN_SET(WN_enPowerSystemLimited, enPowerSystemLimited);
}
void WN_BeepSysFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enBeepSysFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enVSGFault = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;
    //Byte67 Bit1-bit0
    uint8 configVSGType = 0;

    //VSG1 0x2E1 100ms
    uint8 VSG_Sts_temp = 0;
    uint8 Rte_VSG_Sts = RTE_E_INVALID;
    uint8 Sound_AVAS_temp = 0;
    uint8 Rte_Sound_AVAS = RTE_E_INVALID;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);

    Rte_VSG_Sts = WN_VSG_Sts_SignalGet(&VSG_Sts_temp);
    Rte_Sound_AVAS = WN_Builtin_AVAS_Sts_APIGet(&Sound_AVAS_temp);

    if (configVSGType == 1)
    {
        if ((configFuel == 4) &&
            ((configElecPosition == 2) ||
             (configElecPosition == 4) ||
             (configElecPosition == 5) ||
             (configElecPosition == 6) ||
             (configElecPosition == 8))) //PHEV+P2/P2+P4/PS/PS+P4/纵置P2
        {
            //1.103
            if ((RTE_E_OK == Rte_VSG_Sts) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_VSG_Sts))
            {
                if (VSG_Sts_temp == 0x2)
                {
                    enBeepSysFault = WN_enDISPLAY_ON;
                }
            }
        }
    }
    else if (configVSGType == 2)
    {
        if ((configFuel == 5) || (configFuel == 6))
        {
            //1.223
            if((RTE_E_OK == Rte_Sound_AVAS) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_Sound_AVAS))
            {
                if(Sound_AVAS_temp == 1)
                {
                    enVSGFault = WN_enDISPLAY_ON;
                }
            }
        }
        if (((configFuel == 4) || (configFuel == 0xA))&&
            (configElecPosition == 2)) //PHEV+P2/P2+P4/PS/PS+P4
        {
            //1.222
            if((RTE_E_OK == Rte_Sound_AVAS) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_Sound_AVAS))
            {
                if(Sound_AVAS_temp == 1)
                {
                    enBeepSysFault = WN_enDISPLAY_ON;
                }
            }
        }
    }
    else
    {
    }

    WN_SET(WN_enBeepSysFault, enBeepSysFault);
    WN_SET(WN_enVSGFault, enVSGFault);
}
void WN_CommunicationFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enCommunicationFault = WN_enDISPLAY_OFF;

#if 0
    uint8 SignalTimeoutCount = 0;
    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;

    //HCU_HC3 0x268 50ms
    uint8 HCU_BattLowTemWarn = 0;
    uint8 Rte_HCU_BattLowTemWarn = 0;
    //HCU_HC6 0x314 200ms
    uint8 HCU_ChargSts = 0;
    uint8 Rte_HCU_ChargSts = 0;
    //HCU_HC7 0x3C2 1000ms
    uint8 HCU_EVContnsDistance = 0;
    uint8 Rte_HCU_EVContnsDistance = 0;
    //BMS4 0x0F1 10ms
    uint8 BMS_ErrCategory = 0;
    uint8 Rte_SG_BMS4_Tmp = 0;
    //BMS8 0x285 100ms
    uint8 BMS_BattHeatRunaway = 0;
    uint8 Rte_BMS_BattHeatRunaway = 0;
    //BMS19 0x352 500ms
    boolean BMS_BattKeepTempSts = 0;
    uint8 Rte_BMS_BattKeepTempSts = 0;
    //BMS35 0x2C4 100ms
    uint16 BMS_BattSOC = 0;
    uint8 Rte_BMS_BattSOC = 0;
    //BMS30 0x3F1 1000ms TBD
    uint8 BMS_SOCLowWarn = 0;
    uint8 Rte_BMS_SOCLowWarn = 0;
    //OBC2 0x317 200ms
    uint8 OBC_ConnectSts = 0;
    uint8 Rte_OBC_ConnectSts = 0;
    //VSG1 0x2E1 100ms
    uint8 VSG_Sts = 0;
    uint8 Rte_VSG_Sts = 0;
    //HCU_PT5 0x14A 20ms
    uint8 HCU_DrvMod = 0;
    uint8 Rte_HCU_DrvMod = 0;
    //HCU_PT7 0x248 50ms
    boolean HCU_HybSysErr_5 = 0;
    uint8 Rte_SG_HCU_PT7_Tmp = 0;
    //HCU_PT8 0x1C0 50ms
    boolean HCU_ChrgSysErr_3 = 0;
    uint8 Rte_HCU_ChrgSysErr_3 = 0;
    //HCU_PT4 0x2FA 100ms
    uint8 HCU_SOCLow_Indcn = 0;
    uint8 Rte_SG_HCU_PT4_Tmp = 0;
    //BMS22 0x2BF 1000ms
    uint16 BMS_ChrgDurationTime = 0;
    uint8 Rte_BMS_ChrgDurationTime = 0;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);

    Rte_HCU_BattLowTemWarn = WN_HCU_BattLowTemWarn_SignalGet(&HCU_BattLowTemWarn);
    Rte_HCU_ChargSts = WN_HCU_ChargSts_SignalGet(&HCU_ChargSts);
    Rte_HCU_EVContnsDistance = WN_HCU_EVContnsDistance_SignalGet(&HCU_EVContnsDistance);
    Rte_SG_BMS4_Tmp = WN_BMS_ErrCategory_SignalGet(&BMS_ErrCategory);
    Rte_BMS_BattHeatRunaway = WN_BMS_BattHeatRunaway_SignalGet(&BMS_BattHeatRunaway);
    Rte_BMS_BattKeepTempSts = WN_BMS_BattKeepTempSts_SignalGet(&BMS_BattKeepTempSts);
    Rte_BMS_BattSOC = WN_BMS_BattSOC_SignalGet(&BMS_BattSOC);
    Rte_BMS_SOCLowWarn = WN_BMS_SOCLowWarn_SignalGet(&BMS_SOCLowWarn);
    Rte_OBC_ConnectSts = WN_OBC_ConnectSts_SignalGet(&OBC_ConnectSts);
    Rte_VSG_Sts = WN_VSG_Sts_SignalGet(&VSG_Sts);
    Rte_HCU_DrvMod = WN_HCU_DrvMod_SignalGet(&HCU_DrvMod);
    Rte_SG_HCU_PT7_Tmp = WN_HCU_HybSysErr_5_SignalGet(&HCU_HybSysErr_5);
    Rte_HCU_ChrgSysErr_3 = WN_HCU_ChrgSysErr_3_SignalGet(&HCU_ChrgSysErr_3);
    Rte_SG_HCU_PT4_Tmp = WN_HCU_SOCLow_Indcn_SignalGet(&HCU_SOCLow_Indcn);
    Rte_BMS_ChrgDurationTime = WN_BMS_ChrgDurationTime_SignalGet(&BMS_ChrgDurationTime);

    if (((configFuel == 3) || (configFuel == 4)) && 
        ((configElecPosition == 2) || (configElecPosition == 4) || (configElecPosition == 5)))   //HEV/PHEV+P2/P2+P4/PS
    {
        //1.104
        if ((RTE_E_OK != Rte_HCU_BattLowTemWarn) &&
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN != Rte_HCU_BattLowTemWarn))
        {
            SignalTimeoutCount++;
        }
        if ((RTE_E_OK != Rte_HCU_ChargSts) &&
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN != Rte_HCU_ChargSts))
        {
            SignalTimeoutCount++;
        }
        if ((RTE_E_OK != Rte_HCU_EVContnsDistance) &&
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN != Rte_HCU_EVContnsDistance))
        {
            SignalTimeoutCount++;
        }
        if ((RTE_E_OK != Rte_SG_BMS4_Tmp) &&
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN != Rte_SG_BMS4_Tmp))
        {
            SignalTimeoutCount++;
        }
        if ((RTE_E_OK != Rte_BMS_BattHeatRunaway) &&
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN != Rte_BMS_BattHeatRunaway))
        {
            SignalTimeoutCount++;
        }
        if ((RTE_E_OK != Rte_BMS_BattKeepTempSts) &&
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN != Rte_BMS_BattKeepTempSts))
        {
            SignalTimeoutCount++;
        }
        if ((RTE_E_OK != Rte_BMS_BattSOC) &&
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN != Rte_BMS_BattSOC))
        {
            SignalTimeoutCount++;
        }
        if ((RTE_E_OK != Rte_BMS_SOCLowWarn) &&
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN != Rte_BMS_SOCLowWarn))
        {
            SignalTimeoutCount++;
        }
        if ((RTE_E_OK != Rte_OBC_ConnectSts) &&
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN != Rte_OBC_ConnectSts))
        {
            SignalTimeoutCount++;
        }
        if ((RTE_E_OK != Rte_VSG_Sts) &&
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN != Rte_VSG_Sts))
        {
            SignalTimeoutCount++;
        }
        if ((RTE_E_OK != Rte_HCU_DrvMod) &&
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN != Rte_HCU_DrvMod))
        {
            SignalTimeoutCount++;
        }
        if ((RTE_E_OK != Rte_SG_HCU_PT7_Tmp) &&
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN != Rte_SG_HCU_PT7_Tmp))
        {
            SignalTimeoutCount++;
        }
        if ((RTE_E_OK != Rte_HCU_ChrgSysErr_3) &&
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN != Rte_HCU_ChrgSysErr_3))
        {
            SignalTimeoutCount++;
        }
        if ((RTE_E_OK != Rte_SG_HCU_PT4_Tmp) &&
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN != Rte_SG_HCU_PT4_Tmp))
        {
            SignalTimeoutCount++;
        }
        if ((RTE_E_OK != Rte_BMS_ChrgDurationTime) &&
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN != Rte_BMS_ChrgDurationTime))
        {
            SignalTimeoutCount++;
        }

        if (SignalTimeoutCount >= 3)
        {
            enCommunicationFault = WN_enDISPLAY_ON;
        }
    }
#endif
    WN_SET(WN_enCommunicationFault, enCommunicationFault);
}
void WN_PowerOnGearDriveProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enPowerOnGearDrive = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;

    //HCU_PT7 0x248 50ms
    boolean HCU_RdyLmpSts_temp = FALSE;
    uint8 Rte_SG_HCU_PT7_Tmp = RTE_E_INVALID;

    //VCU_FD4 0x2D6 TBD
    uint8 VCU_RdyLEDSts = 0;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);

    Rte_SG_HCU_PT7_Tmp = WN_HCU_RdyLmpSts_SignalGet(&HCU_RdyLmpSts_temp);

    //HEV+P2/PS/PS+P4/纵置P2
    if (((configFuel == 3) && 
        ((configElecPosition == 2) || (configElecPosition == 5) || (configElecPosition == 6) ||(configElecPosition == 8))) ||
        ((configFuel == 4) && 
        ((configElecPosition == 2)|| (configElecPosition == 4) || (configElecPosition == 5) || 
        (configElecPosition == 6) || (configElecPosition == 8))))//PHEV+P2/P2+P4/PS/PS+P4/纵置P2
    {
        //1.106
        if ((RTE_E_OK == Rte_SG_HCU_PT7_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_HCU_PT7_Tmp))
        {
            if (HCU_RdyLmpSts_temp == TRUE)
            {
                enPowerOnGearDrive = WN_enDISPLAY_ON;
            }
        }
    }
    else if (configFuel == 5)
    {
        //1.105
        if (0)
        {
            if (VCU_RdyLEDSts == 1)
            {
                enPowerOnGearDrive = WN_enDISPLAY_ON;
            }
        }
    }
    else
    {
    }

    WN_SET(WN_enPowerOnGearDrive, enPowerOnGearDrive);
}
void WN_DoNotStepAcAndBrProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enDoNotStepAcAndBr = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;
    //从车速表获取
    uint16 VehSpd_temp = 0;
    //ECM9 0x102 20ms
    uint8 AccelPedlPosnDiagc_temp = 0;
    uint8 Rte_AccelPedlPosnDiagc = RTE_E_INVALID;
    //ECM2 0x271 20ms
    uint8 AccelPedalPosnVldty_temp = 0;
    uint8 Rte_AccelPedalPosnVldty = RTE_E_INVALID;
    //BCM1 0x319 50ms
    uint8 BrkPedalSts_BCM_temp = 0;
    uint8 Rte_BrkPedalSts_BCM = RTE_E_INVALID;
    //ABS3 0x265 20ms
    uint8 VehSpdVld_temp = 0;
    uint8 Rte_SG_ABS3_Tmp = RTE_E_INVALID;
    //ESP_FD2 0x137 20ms
    uint8 Rte_SG_ABS3_ESP_FD2_Tmp = RTE_E_INVALID;
    //HCU_FD1 0x060 10ms
    uint8 HCU_AccelPedalPosn_Diag_temp = 0;
    uint8 Rte_HCU_AccelPedalPosn_Diag = RTE_E_INVALID;
    uint8 HCU_AccelPedalPosn_DiagValid_temp = 0;
    uint8 Rte_HCU_AccelPedalPosn_DiagValid = RTE_E_INVALID;

    s_SpeedoInfo_t SpeedoInfo_Tmp = {0};

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);

    WN_SpeedoInfo_APIGet(&SpeedoInfo_Tmp);
    VehSpd_temp = SpeedoInfo_Tmp.RealSpeed;

    //1.107
    if ((configFuel == 0) || //柴油
        (configFuel == 1) || //汽油
        (configFuel == 2) || //汽油+天然气
        (configFuel == 7))   //天然气
    {
        //配置1
        Rte_BrkPedalSts_BCM = WN_BrkPedalSts_BCM_SignalGet(&BrkPedalSts_BCM_temp);
        Rte_AccelPedlPosnDiagc = WN_AccelPedlPosnDiagc_SignalGet(&AccelPedlPosnDiagc_temp);
        Rte_AccelPedalPosnVldty = WN_AccelPedalPosnVldty_SignalGet(&AccelPedalPosnVldty_temp);
        if (EolConfig_Trans_CANFD())
        {
            Rte_SG_ABS3_ESP_FD2_Tmp = WN_VehSpdVldFD_SignalGet(&VehSpdVld_temp);
        }
        else
        {
            Rte_SG_ABS3_Tmp = WN_VehSpdVld_SignalGet(&VehSpdVld_temp);
        }
        if (((RTE_E_OK == Rte_SG_ABS3_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ABS3_Tmp) ||
            (RTE_E_OK == Rte_SG_ABS3_ESP_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ABS3_ESP_FD2_Tmp)) &&
            ((RTE_E_OK == Rte_BrkPedalSts_BCM) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_BrkPedalSts_BCM)) &&
            ((RTE_E_OK == Rte_AccelPedlPosnDiagc) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_AccelPedlPosnDiagc)) &&
            ((RTE_E_OK == Rte_AccelPedalPosnVldty) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_AccelPedalPosnVldty)))
        {
            if ((VehSpdVld_temp == 0x1) && (VehSpd_temp > 1000) && (BrkPedalSts_BCM_temp == 0x1) &&
                (AccelPedalPosnVldty_temp == 0x1) &&
                ((AccelPedlPosnDiagc_temp >= 0x19) && (AccelPedlPosnDiagc_temp <= 0xFF)))
            {
                if (AcBr_Signal_DurationTime < (WN_AccelBrakeWrnDelayTime / WN_TASK_TIME))
                {
                    AcBr_Signal_DurationTime++;
                }
                else
                {
                    enDoNotStepAcAndBr = WN_enDISPLAY_ON;
                }
            }
            else
            {
                AcBr_Signal_DurationTime = 0;
            }
        }
        else
        {
            AcBr_Signal_DurationTime = 0;
        }
    }
    //HEV+P2/PS/纵置P2
    if (((configFuel == 3) && 
        ((configElecPosition == 2) || (configElecPosition == 5) ||(configElecPosition == 8))) ||
        ((configFuel == 4) && 
        ((configElecPosition == 2)|| (configElecPosition == 4) || (configElecPosition == 5) || (configElecPosition == 8))))//PHEV+P2/P2+P4/PS/纵置P2
    {
        //配置2
        Rte_BrkPedalSts_BCM = WN_BrkPedalSts_BCM_SignalGet(&BrkPedalSts_BCM_temp);
        Rte_HCU_AccelPedalPosn_Diag = WN_HCU_AccelPedalPosn_Diag_SignalGet(&HCU_AccelPedalPosn_Diag_temp);
        Rte_HCU_AccelPedalPosn_DiagValid = WN_HCU_AccelPedalPosn_DiagValid_SignalGet(&HCU_AccelPedalPosn_DiagValid_temp);
        Rte_SG_ABS3_ESP_FD2_Tmp = WN_VehSpdVldFD_SignalGet(&VehSpdVld_temp);
        if (((RTE_E_OK == Rte_SG_ABS3_ESP_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ABS3_ESP_FD2_Tmp)) &&
            ((RTE_E_OK == Rte_BrkPedalSts_BCM) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_BrkPedalSts_BCM)) &&
            ((RTE_E_OK == Rte_HCU_AccelPedalPosn_Diag) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_AccelPedalPosn_Diag)) &&
            ((RTE_E_OK == Rte_HCU_AccelPedalPosn_DiagValid) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_AccelPedalPosn_DiagValid)))
        {
            if ((VehSpdVld_temp == 0x1) && (VehSpd_temp > 1000) && (BrkPedalSts_BCM_temp == 0x1) &&
                (HCU_AccelPedalPosn_DiagValid_temp == 0x1) &&
                ((HCU_AccelPedalPosn_Diag_temp >= 0x19) && (HCU_AccelPedalPosn_Diag_temp <= 0xFF)))
            {
                if (AcBr_Signal_DurationTime < (WN_AccelBrakeWrnDelayTime / WN_TASK_TIME))
                {
                    AcBr_Signal_DurationTime++;
                }
                else
                {
                    enDoNotStepAcAndBr = WN_enDISPLAY_ON;
                }
            }
            else
            {
                AcBr_Signal_DurationTime = 0;
            }
        }
        else
        {
            AcBr_Signal_DurationTime = 0;
        }
    }

    WN_SET(WN_enDoNotStepAcAndBr, enDoNotStepAcAndBr);
}
void WN_EngAuthenFailedProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enEngAuthenFailed = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTransAuthenFailed = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAuthenFailed = WN_enDISPLAY_OFF;

    //Byte11 Bit2-bit0
    uint8 configStartSystem = 0;
    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte3 Bit7-bit0
    uint8 configTransmission = 0;

    //Hard signal
    uint8 PIN_C1 = ELECTRICAL_INVALID;

    //ECM1 0x111 10ms
    uint8 EMS_AuthenResult_temp = 0;
    uint8 Rte_EMS_AuthenResult = RTE_E_INVALID;
    //HCU_PT5 0x14A 20ms
    uint8 HCUImmoAuthRes_temp = 0;
    uint8 Rte_HCUImmoAuthRes = RTE_E_INVALID;
    //VCU5 0x31B 200ms TBD
    //uint8 VCU_AuthPassed = 0;
    //DCT7 0x235 50ms
    //DCT_FD4 0x236 50ms
    uint8 DrvFaiMsg_temp = 0;
    uint8 Rte_SG_DCT7_Tmp = RTE_E_INVALID;
    uint8 Rte_SG_DCT_FD4_Tmp = RTE_E_INVALID;

    configTransmission = (uint8)WN_GetSingleConfig(WN_enCfg_Transmission);
    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configStartSystem = (uint8)WN_GetSingleConfig(WN_enCfg_StartSystem);

    WN_PIN_C1_IOGet(&PIN_C1);

    Rte_EMS_AuthenResult = WN_EMS_AuthenResult_SignalGet(&EMS_AuthenResult_temp);
    Rte_HCUImmoAuthRes = WN_HCUImmoAuthRes_SignalGet(&HCUImmoAuthRes_temp);

    if (EolConfig_Trans_CANFD())
    {
        Rte_SG_DCT_FD4_Tmp = WN_DrvFaiMsgFD_SignalGet(&DrvFaiMsg_temp);
    }
    else
    {
        Rte_SG_DCT7_Tmp = WN_DrvFaiMsg_SignalGet(&DrvFaiMsg_temp);
    }
    if ((configTransmission == 7) ||
        (configTransmission == 38) ||
        (configTransmission == 15) ||
        (configTransmission == 16) ||
        (configTransmission == 41))//R14 change
    {
        if ((RTE_E_OK == Rte_SG_DCT7_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_DCT7_Tmp) ||
            (RTE_E_OK == Rte_SG_DCT_FD4_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_DCT_FD4_Tmp))
        {
            //1.48 only case 1
            if (DrvFaiMsg_temp == 0x4)
            {
                enTransAuthenFailed = WN_enDISPLAY_ON;
            }
        }
    }
    //1.108
    if ((configFuel == 0) || //柴油
        (configFuel == 1) || //汽油
        (configFuel == 2) || //汽油+天然气
        (configFuel == 3) || //HEV
        (configFuel == 4) || //PHEV
        (configFuel == 7))   //天然气
    {
        //case1
        if (configStartSystem == 0)
        {
            enEngAuthenFailed = (PIN_C1 == ELECTRICAL_LOW) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
        }
    }
    if ((configFuel == 0) || //柴油
        (configFuel == 1) || //汽油
        (configFuel == 2) || //汽油+天然气
        (configFuel == 7))   //天然气
    {
        //case2
        if ((configStartSystem == 1) || (configStartSystem == 2) || (configStartSystem == 3))
        {
            if ((RTE_E_OK == Rte_EMS_AuthenResult) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_EMS_AuthenResult))
            {
                enEngAuthenFailed = (EMS_AuthenResult_temp == 0x1) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            }
        }
    }
    else if ((configFuel == 3) || (configFuel == 4)) //HEV/PHEV
    {
        //case3/4
        if ((configStartSystem == 1) || (configStartSystem == 2) || (configStartSystem == 3))
        {
            if ((RTE_E_OK == Rte_HCUImmoAuthRes) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCUImmoAuthRes))
            {
                enEngAuthenFailed = (HCUImmoAuthRes_temp == 0x2) ? WN_enDISPLAY_ON : WN_enDISPLAY_OFF;
            }
        }
    }
    else
    {
    }

    if ((WN_enDISPLAY_ON == enEngAuthenFailed) || (WN_enDISPLAY_ON == enTransAuthenFailed))
    {
        enAuthenFailed = WN_enDISPLAY_ON;
    }

    WN_SET(WN_enTransAuthenFailed, enAuthenFailed);
}
void WN_DrivingModeWarningProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enDM_DBL_EV_Err = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_HSL_EV = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_HSL_SAVE = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_HSL_AWD = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_HSL_SPORT = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_MS_SPORT = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_MS_SPORT_Only = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_HSR_EV = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_HSL_SNOW = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_HSL_MUDDY = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_HSL_SAND = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_HSL_SPORT_P = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_HSL_ECO = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_ENS_EV = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPowerLowEVUnvil = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRearAxSysErr4WDUnvil = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common en4WDEVSaveDisable = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enBattPowerLowEVDisable = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enBattTempLowEVDisable = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common en4LModeEVSaveDisable = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enEVModeBattPowerLow = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;

    //HCU_PT7 0x248
    uint8 HCU_ModSwtFail_temp = 0;
    uint8 Rte_SG_HCU_PT7_Tmp = RTE_E_INVALID;

	//HCU_HP5 0x201 50ms
	uint8 PDCU_EvSave_disl_temp = 0;
	uint8 Rte_PDCU_EvSave_disl = RTE_E_INVALID;
	
    //uint8 HCU_ModSwtFail_0x204 = 0;
    //uint8 Rte_HCU_ModSwtFail_0x204 = RTE_E_INVALID;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);

    Rte_SG_HCU_PT7_Tmp = WN_HCU_ModSwtFail_SignalGet(&HCU_ModSwtFail_temp);
	Rte_PDCU_EvSave_disl = WN_PDCU_EvSave_disl_SignalGet(&PDCU_EvSave_disl_temp);
    //Rte_HCU_ModSwtFail_0x204 = WN_HCU_ModSwtFail_0x204_SignalGet(&HCU_ModSwtFail_0x204);//R15 0x248

    //1.109
    if ((((configFuel == 3) || (configFuel == 4)) && ((configElecPosition == 5) || (configElecPosition == 6))) || //HEV/PHEV+PS/PS+P4
        ((configFuel == 4) && ((configElecPosition == 2) || (configElecPosition == 4))))                          //PHEV+P2/(P2+P4)
    {
        if ((RTE_E_OK == Rte_SG_HCU_PT7_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_HCU_PT7_Tmp))
        {
            if (HCU_ModSwtFail_temp == 0x1)
            {
                enDM_DBL_EV_Err = WN_enDISPLAY_ON;
            }
            else if (HCU_ModSwtFail_temp == 0x2)
            {
                enDM_HSL_EV = WN_enDISPLAY_ON;
            }
            else if (HCU_ModSwtFail_temp == 0x3)
            {
                enDM_HSL_SAVE = WN_enDISPLAY_ON;
            }
            else if (HCU_ModSwtFail_temp == 0x4)
            {
                enDM_HSL_AWD = WN_enDISPLAY_ON;
            }
            else if (HCU_ModSwtFail_temp == 0x5)
            {
                enDM_HSL_SPORT = WN_enDISPLAY_ON;
            }
            else if (HCU_ModSwtFail_temp == 0x6)
            {
                enDM_MS_SPORT = WN_enDISPLAY_ON;
            }
            else if (HCU_ModSwtFail_temp == 0x7)
            {
                enDM_MS_SPORT_Only = WN_enDISPLAY_ON;
            }           
            else if (HCU_ModSwtFail_temp == 0x9)
            {
                enDM_HSL_SNOW = WN_enDISPLAY_ON;
            }
            else if (HCU_ModSwtFail_temp == 0xA)
            {
                enDM_HSL_MUDDY = WN_enDISPLAY_ON;
            }
            else if (HCU_ModSwtFail_temp == 0xB)
            {
                enDM_HSL_SAND = WN_enDISPLAY_ON;
            }
            else if (HCU_ModSwtFail_temp == 0xC)
            {
                enDM_HSL_SPORT_P = WN_enDISPLAY_ON;
            }
            else if (HCU_ModSwtFail_temp == 0xE)
            {
                enDM_ENS_EV = WN_enDISPLAY_ON;
            }
            else
            {
            }

            if (((configFuel == 3) || (configFuel == 4)) && ((configElecPosition == 5) || (configElecPosition == 6))) //HEV/PHEV+PS/PS+P4
            {
                //case3|4|5|6
                if (HCU_ModSwtFail_temp == 0xD)
                {
                    enPowerLowEVUnvil = WN_enDISPLAY_ON;
                }
                else if (HCU_ModSwtFail_temp == 0xF)
                {
                    enRearAxSysErr4WDUnvil = WN_enDISPLAY_ON;
                }
				else if (HCU_ModSwtFail_temp == 0x8)//R15
                {
					enEVModeBattPowerLow = WN_enDISPLAY_ON;
                }
                else
                {
                }
            }
            else
            {
                //case1|2
                if (HCU_ModSwtFail_temp == 0xD)
                {
                    enDM_HSL_ECO = WN_enDISPLAY_ON;
                }
                else if (HCU_ModSwtFail_temp == 0x8)
                {
                    enDM_HSR_EV = WN_enDISPLAY_ON;
                }
            }
        }
    }
    if((configFuel == 4) && ((configElecPosition == 8)))
    {
        //case 7
        if ((RTE_E_OK == Rte_SG_HCU_PT7_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_HCU_PT7_Tmp))//R11
        {
            if (HCU_ModSwtFail_temp == 0x1)
            {
                enDM_DBL_EV_Err = WN_enDISPLAY_ON;
            }
            else if (HCU_ModSwtFail_temp == 0x2)
            {
                enDM_HSL_EV = WN_enDISPLAY_ON;
            }
            else if (HCU_ModSwtFail_temp == 0x3)
            {
                enDM_HSL_SAVE = WN_enDISPLAY_ON;
            }
            else if (HCU_ModSwtFail_temp == 0x8)
            {
                enDM_HSR_EV = WN_enDISPLAY_ON;
            }
            else if (HCU_ModSwtFail_temp == 0xE)
            {
                //enBattPowerLowEVDisable = WN_enDISPLAY_ON;//R15 delete
                enDM_ENS_EV = WN_enDISPLAY_ON;
            }
            else if (HCU_ModSwtFail_temp == 0xF)
            {
                //enBattTempLowEVDisable = WN_enDISPLAY_ON;//R15 delete
            }
            else
            {
                /* du nothing */
            }
        }
			
		if ((RTE_E_OK == Rte_PDCU_EvSave_disl) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_PDCU_EvSave_disl))//R15
        {
	        if(PDCU_EvSave_disl_temp == 1)
	        {
	            en4LModeEVSaveDisable = WN_enDISPLAY_ON;
	        }
        }
    }

    WN_SET(WN_enDM_DBL_EV_Err, enDM_DBL_EV_Err);
    WN_SET(WN_enDM_HSL_EV, enDM_HSL_EV);
    WN_SET(WN_enDM_HSL_SAVE, enDM_HSL_SAVE);
    WN_SET(WN_enDM_HSL_AWD, enDM_HSL_AWD);
    WN_SET(WN_enDM_HSL_SPORT, enDM_HSL_SPORT);
    WN_SET(WN_enDM_MS_SPORT, enDM_MS_SPORT);
    WN_SET(WN_enDM_MS_SPORT_Only, enDM_MS_SPORT_Only);
    WN_SET(WN_enDM_HSR_EV, enDM_HSR_EV);
    WN_SET(WN_enDM_HSL_SNOW, enDM_HSL_SNOW);
    WN_SET(WN_enDM_HSL_MUDDY, enDM_HSL_MUDDY);
    WN_SET(WN_enDM_HSL_SAND, enDM_HSL_SAND);
    WN_SET(WN_enDM_HSL_SPORT_P, enDM_HSL_SPORT_P);
    WN_SET(WN_enDM_HSL_ECO, enDM_HSL_ECO);
    WN_SET(WN_enDM_ENS_EV, enDM_ENS_EV);
    WN_SET(WN_enPowerLowEVUnvil, enPowerLowEVUnvil);
    WN_SET(WN_enRearAxSysErr4WDUnvil, enRearAxSysErr4WDUnvil);
    WN_SET(WN_en4WDEVSaveDisable, en4WDEVSaveDisable);
    WN_SET(WN_enBattPowerLowEVDisable, enBattPowerLowEVDisable);
    WN_SET(WN_enBattTempLowEVDisable, enBattTempLowEVDisable);
    WN_SET(WN_en4LModeEVSaveDisable, en4LModeEVSaveDisable);
	WN_SET(WN_enEVModeBattPowerLow, enEVModeBattPowerLow);
}
void WN_FuelTankSysFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enFuelTankSysFault = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;

    //ECM_PT6 0x290 100ms
    uint8 FTIVFault_temp = 0;
    uint8 Rte_FTIVFault = RTE_E_INVALID;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);

    Rte_FTIVFault = WN_FTIVFault_SignalGet(&FTIVFault_temp);

    if (configFuel == 4)
    {
        //1.110
        if ((RTE_E_OK == Rte_FTIVFault) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_FTIVFault))
        {
            if (FTIVFault_temp == 1)
            {
                enFuelTankSysFault = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enFuelTankSysFault, enFuelTankSysFault);
}
void WN_RaceLanuchWarningProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enRaceLaunchActive = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRaceLaunchTimeout = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRLUnAvail_ESPAVH = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRLUnAvail_ESP = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRLUnAvail_HYB = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSRaceLaunchActive = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enBattLowSRaceLaunUnAvail = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTransHeatSLaunchUnAvail = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSRaceLaunchOverLimit = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enBattLowLaunchUnavil = WN_enDISPLAY_OFF;

    //Byte43 Bit7-bit4
    uint8 configQuickStart = 0;
    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;

    //HCU_FD1 0x290 10ms
    //ECM7 0x084 10ms TBD
    uint8 HCU_RaceLaunchSts_temp = 0;
    uint8 HCU_RaceLaunchAvail_temp = 0;
    uint8 Rte_HCU_FD1Sts = RTE_E_INVALID;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);
    configQuickStart = (uint8)WN_GetSingleConfig(WN_enCfg_QuickStart);

    if ((((configFuel == 3) &&
          ((configElecPosition == 2) || (configElecPosition == 5) || (configElecPosition == 6) || (configElecPosition == 8))) ||//HEV+PS/PS+P4/P2/纵置P2
        ((configFuel == 4) && 
          ((configElecPosition == 2) || (configElecPosition == 4) || (configElecPosition == 5) || (configElecPosition == 6) || (configElecPosition == 8))) || //PHEV+P2/(P2+P4)/PS/PS+P4/纵置P2
         (((configFuel == 0) || (configFuel == 1) || (configFuel == 2) || (configFuel == 7)) && (configElecPosition == 1))) &&
           (configQuickStart == 1))
    {
        //1.111
        if (((configFuel == 0) || (configFuel == 1) || (configFuel == 2) || (configFuel == 7)) && (configElecPosition == 1))
        {
            Rte_HCU_FD1Sts = WN_HCU_RaceLaunchSts_0x84_SignalGet(&HCU_RaceLaunchSts_temp);
            Rte_HCU_FD1Sts = WN_HCU_RaceLaunchAvail_0x84_SignalGet(&HCU_RaceLaunchAvail_temp);
        }
        else
        {
            Rte_HCU_FD1Sts = WN_HCU_RaceLaunchSts_0x60_SignalGet(&HCU_RaceLaunchSts_temp);
            Rte_HCU_FD1Sts = WN_HCU_RaceLaunchAvail_0x60_SignalGet(&HCU_RaceLaunchAvail_temp);
        }
        if ((RTE_E_OK == Rte_HCU_FD1Sts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_FD1Sts))
        {
            //case2-10
            if (HCU_RaceLaunchSts_temp == 0x1)
            {
                enRaceLaunchActive = WN_enDISPLAY_ON;
            }
            else if (HCU_RaceLaunchSts_temp == 0x2)
            {
                enRaceLaunchTimeout = WN_enDISPLAY_ON;
            }
            else
            {
            }
            if (HCU_RaceLaunchAvail_temp == 0x1)
            {
                enRLUnAvail_ESP = WN_enDISPLAY_ON;
            }
            else if (HCU_RaceLaunchAvail_temp == 0x2)
            {
                enRLUnAvail_HYB = WN_enDISPLAY_ON;
            }
            else
            {
            }
            //case4-7
            if (((configFuel == 3) || (configFuel == 4)) && ((configElecPosition == 5) || (configElecPosition == 6))) //HEV/PHEV+PS/PS+P4
            {
                if (HCU_RaceLaunchSts_temp == 0x3)
                {
                    enSRaceLaunchActive = WN_enDISPLAY_ON;
                }
                else if (HCU_RaceLaunchSts_temp == 0x4)
                {
                    enBattLowSRaceLaunUnAvail = WN_enDISPLAY_ON;
                }
                else if (HCU_RaceLaunchSts_temp == 0x5)
                {
                    enTransHeatSLaunchUnAvail = WN_enDISPLAY_ON;
                }
                else if (HCU_RaceLaunchSts_temp == 0x6)
                {
                    enSRaceLaunchOverLimit = WN_enDISPLAY_ON;
                }
                else
                {
                }
                if (HCU_RaceLaunchAvail_temp == 0x3)
                {
                    enBattLowLaunchUnavil = WN_enDISPLAY_ON;
                }
            }
        }
    }

    WN_SET(WN_enRaceLaunchActive, enRaceLaunchActive);
    WN_SET(WN_enRaceLaunchTimeout, enRaceLaunchTimeout);
    WN_SET(WN_enRLUnavaiESPAVH, enRLUnAvail_ESPAVH);
    WN_SET(WN_enRLUnavaiESP, enRLUnAvail_ESP);
    WN_SET(WN_enRLUnavaiHYB, enRLUnAvail_HYB);
    WN_SET(WN_enSRaceLaunchActive, enSRaceLaunchActive);
    WN_SET(WN_enBattLowSRaceLaunUnAvail, enBattLowSRaceLaunUnAvail);
    WN_SET(WN_enTransHeatSLaunchUnAvail, enTransHeatSLaunchUnAvail);
    WN_SET(WN_enSRaceLaunchOverLimit, enSRaceLaunchOverLimit);
    WN_SET(WN_enBattLowLaunchUnavil, enBattLowLaunchUnavil);
}
void WN_RaceModeWarningProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enRaceModeActive = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRaceModeExit = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRaceModeFault = WN_enDISPLAY_OFF;

    //Byte43 Bit7-bit4
    uint8 configQuickStart = 0;
    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte3 Bit7-bit0
    uint8 configTransmission = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;

    //DCT7 0x235 50ms
    //DCT_FD4 0x236 10ms TBD
    uint8 DCT_RaceModeSts_temp = 0;
    uint8 Rte_SG_DCT7_Tmp = RTE_E_INVALID;
    uint8 Rte_SG_DCT_FD4_Tmp = RTE_E_INVALID;

    configTransmission = (uint8)WN_GetSingleConfig(WN_enCfg_Transmission);
    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);
    configQuickStart = (uint8)WN_GetSingleConfig(WN_enCfg_QuickStart);

    if ((configQuickStart == 1) &&
        ((configTransmission == 7) || (configTransmission == 38) || (configTransmission == 15) || (configTransmission == 39) || (configTransmission == 41)) &&
        ((configFuel == 0) || (configFuel == 1) ||
         (configFuel == 2) || (configFuel == 7)) &&
        (configElecPosition == 0))
    {
        //1.112
        if (EolConfig_Trans_CANFD())
        {
            Rte_SG_DCT_FD4_Tmp = WN_DCT_RaceModeStsFD_SignalGet(&DCT_RaceModeSts_temp);
        }
        else
        {
            Rte_SG_DCT7_Tmp = WN_DCT_RaceModeSts_SignalGet(&DCT_RaceModeSts_temp);
        }
        if ((RTE_E_OK == Rte_SG_DCT7_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_DCT7_Tmp) ||
            (RTE_E_OK == Rte_SG_DCT_FD4_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_DCT_FD4_Tmp))
        {
            if (DCT_RaceModeSts_temp == 0x1)
            {
                enRaceModeActive = WN_enDISPLAY_ON;
            }
            else if (DCT_RaceModeSts_temp == 0x2)
            {
                enRaceModeExit = WN_enDISPLAY_ON;
            }
            else if (DCT_RaceModeSts_temp == 0x3)
            {
                enRaceModeFault = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
    }

    WN_SET(WN_enRaceModeActive, enRaceModeActive);
    WN_SET(WN_enRaceModeExit, enRaceModeExit);
    WN_SET(WN_enRaceModeFault, enRaceModeFault);
}
void WN_DriveModeWarningProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enDM_B30_Standard = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_Sport = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_Snow = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_Muddy = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_Sand = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_4L = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_ECO = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_IMC = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_SportPlus = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_OffRoad = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_Expert = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_Rock = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_Pothole = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_MuddySand = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_Mountain = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_Turbo = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_Race = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_GrassGravel = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_Uneven = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_Wade4H = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_Wade4L = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_2H = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_B30_4H = WN_enDISPLAY_OFF;

    WN_CFG_enSTATUS_Common enDM_StandardSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_SportSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_SnowSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_MuddySecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_SandSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_4LSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_ECOSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_IMCSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_SportPlusSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_OffRoadSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_ExpertSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_RockSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_PotholeSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_MuddySandSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_MountainSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_TurboSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_RaceSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_GrassGravelSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_UnevenSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_Wade4HSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_Wade4LSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_2HSecond = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_4HSecond = WN_enDISPLAY_OFF;
    
    WN_CFG_enSTATUS_Common enDM_StandardSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_SportSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_SnowSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_ExpertSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_MuddySelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_SandSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_4LSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_EcoSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_OffRoadSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_SportPlusSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_RockSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_PotholeSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_MuddySandSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_MountainSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_TurboSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_RaceSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_GrassGravelSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_UnevenSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_Wade4HSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_Wade4LSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_2HSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_4HSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_IMCSelect = WN_enDISPLAY_OFF;

    WN_CFG_enSTATUS_Common enDM_StandardDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_SportDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_SnowDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_ExpertDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_MuddyDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_SandDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_4LDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_EcoDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_OffRoadDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_SportPlusDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_RockDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_PotholeDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_MuddySandDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_MountainDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_TurboDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_RaceDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_GrassGravelDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_UnevenDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_Wade4HDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_Wade4LDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_2HDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_4HDPR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_IMCDPR = WN_enDISPLAY_OFF;

    WN_CFG_enSTATUS_Common enDM_PHEV_AutoStart = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_PHEV_EvStart = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_PHEV_SaveStart = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_PHEV_SportStart = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_PHEV_AWDStart = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_PHEV_SnowStart = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_PHEV_MuddyStart = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_PHEV_SandStart = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_PHEV_SportPlusStart = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_PHEV_EcoStart = WN_enDISPLAY_OFF;
    
    WN_CFG_enSTATUS_Common enDM_EV_StandardStart = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_EV_SportStart = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_EV_EcoStart = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_EV_AutoStart = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_EV_SnowStart = WN_enDISPLAY_OFF;

    //Get DrvMode share value
    DM_tstDrvModStatusRecord DM_tstDrvModStatusRecord_Tmp = {0};

    Rte_Read_rpSR_SWCNormal_DrvModStatusRecord_Element(&DM_tstDrvModStatusRecord_Tmp);

    //1.113 Fuel case4
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[0] & 0x01u) != 0u)
    {
        enDM_B30_Standard = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[0] & 0x02u) != 0u)
    {
        enDM_B30_Sport = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[0] & 0x04u) != 0u)
    {
        enDM_B30_Snow = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[0] & 0x08u) != 0u)
    {
        enDM_B30_Muddy = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[0] & 0x10u) != 0u)
    {
        enDM_B30_Sand = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[0] & 0x20u) != 0u)
    {
        enDM_B30_4L = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[0] & 0x40u) != 0u)
    {
        enDM_B30_ECO = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[0] & 0x80u) != 0u)
    {
        enDM_B30_IMC = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[1] & 0x01u) != 0u)
    {
        enDM_B30_SportPlus = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[1] & 0x02u) != 0u)
    {
        enDM_B30_OffRoad = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[1] & 0x04u) != 0u)
    {
        enDM_B30_Expert = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[1] & 0x08u) != 0u)
    {
        enDM_B30_Rock = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[1] & 0x10u) != 0u)
    {
        enDM_B30_Pothole = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[1] & 0x20u) != 0u)
    {
        enDM_B30_MuddySand = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[1] & 0x40u) != 0u)
    {
        enDM_B30_Mountain = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[1] & 0x80u) != 0u)
    {
        enDM_B30_Turbo = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[2] & 0x01u) != 0u)
    {
        enDM_B30_Race = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[2] & 0x02u) != 0u)
    {
        enDM_B30_GrassGravel = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[2] & 0x04u) != 0u)
    {
        enDM_B30_Uneven = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[2] & 0x08u) != 0u)
    {
        enDM_B30_Wade4H = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[2] & 0x10u) != 0u)
    {
        enDM_B30_Wade4L = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[2] & 0x20u) != 0u)
    {
        enDM_B30_2H = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[2] & 0x40u) != 0u)
    {
        enDM_B30_4H = WN_enDISPLAY_ON;
    }
    //Fuel case 1/2/3/5
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[2] & 0x80u) != 0u)
    {
        enDM_StandardSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[3] & 0x01u) != 0u)
    {
        enDM_SportSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[3] & 0x02u) != 0u)
    {
        enDM_SnowSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[3] & 0x04u) != 0u)
    {
        enDM_MuddySecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[3] & 0x08u) != 0u)
    {
        enDM_SandSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[3] & 0x10u) != 0u)
    {
        enDM_4LSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[3] & 0x20u) != 0u)
    {
        enDM_ECOSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[3] & 0x40u) != 0u)
    {
        enDM_IMCSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[3] & 0x80u) != 0u)
    {
        enDM_SportPlusSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[4] & 0x01u) != 0u)
    {
        enDM_OffRoadSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[4] & 0x02u) != 0u)
    {
        enDM_ExpertSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[4] & 0x04u) != 0u)
    {
        enDM_RockSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[4] & 0x08u) != 0u)
    {
        enDM_PotholeSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[4] & 0x10u) != 0u)
    {
        enDM_MuddySandSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[4] & 0x20u) != 0u)
    {
        enDM_MountainSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[4] & 0x40u) != 0u)
    {
        enDM_TurboSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[4] & 0x80u) != 0u)
    {
        enDM_RaceSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[5] & 0x01u) != 0u)
    {
        enDM_GrassGravelSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[5] & 0x02u) != 0u)
    {
        enDM_UnevenSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[5] & 0x04u) != 0u)
    {
        enDM_Wade4HSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[5] & 0x08u) != 0u)
    {
        enDM_Wade4LSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[5] & 0x10u) != 0u)
    {
        enDM_2HSecond = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[5] & 0x20u) != 0u)
    {
        enDM_4HSecond = WN_enDISPLAY_ON;
    }

    
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[5] & 0x40u) != 0u)
    {
        enDM_StandardSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[5] & 0x80u) != 0u)
    {
        enDM_SportSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[6] & 0x01u) != 0u)
    {
        enDM_SnowSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[6] & 0x02u) != 0u)
    {
        enDM_ExpertSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[6] & 0x04u) != 0u)
    {
        enDM_MuddySelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[6] & 0x08u) != 0u)
    {
        enDM_2HSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[6] & 0x10u) != 0u)
    {
        enDM_SandSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[6] & 0x20u) != 0u)
    {
        enDM_4HSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[6] & 0x40u) != 0u)
    {
        enDM_4LSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[6] & 0x80u) != 0u)
    {
        enDM_EcoSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[7] & 0x01u) != 0u)
    {
        enDM_OffRoadSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[7] & 0x02u) != 0u)
    {
        enDM_SportPlusSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[7] & 0x04u) != 0u)
    {
        enDM_RockSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[7] & 0x08u) != 0u)
    {
        enDM_PotholeSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[7] & 0x10u) != 0u)
    {
        enDM_MuddySandSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[7] & 0x20u) != 0u)
    {
        enDM_MountainSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[7] & 0x40u) != 0u)
    {
        enDM_TurboSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[7] & 0x80u) != 0u)
    {
        enDM_RaceSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[8] & 0x01u) != 0u)
    {
        enDM_GrassGravelSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[8] & 0x02u) != 0u)
    {
        enDM_UnevenSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[8] & 0x04u) != 0u)
    {
        enDM_Wade4HSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[8] & 0x08u) != 0u)
    {
        enDM_Wade4LSelect = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[8] & 0x10u) != 0u)
    {
        enDM_IMCSelect = WN_enDISPLAY_ON;
    }
    
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[8] & 0x20u) != 0u)
    {
        enDM_StandardDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[8] & 0x40u) != 0u)
    {
        enDM_SportDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[8] & 0x80u) != 0u)
    {
        enDM_SnowDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[9] & 0x01u) != 0u)
    {
        enDM_ExpertDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[9] & 0x02u) != 0u)
    {
        enDM_MuddyDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[9] & 0x04u) != 0u)
    {
        enDM_2HDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[9] & 0x08u) != 0u)
    {
        enDM_SandDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[9] & 0x10u) != 0u)
    {
        enDM_4HDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[9] & 0x20u) != 0u)
    {
        enDM_4LDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[9] & 0x40u) != 0u)
    {
        enDM_EcoDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[9] & 0x80u) != 0u)
    {
        enDM_OffRoadDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[10] & 0x01u) != 0u)
    {
        enDM_SportPlusDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[10] & 0x02u) != 0u)
    {
        enDM_RockDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[10] & 0x04u) != 0u)
    {
        enDM_PotholeDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[10] & 0x08u) != 0u)
    {
        enDM_MuddySandDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[10] & 0x10u) != 0u)
    {
        enDM_MountainDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[10] & 0x20u) != 0u)
    {
        enDM_TurboDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[10] & 0x40u) != 0u)
    {
        enDM_RaceDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[10] & 0x80u) != 0u)
    {
        enDM_GrassGravelDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[11] & 0x01u) != 0u)
    {
        enDM_UnevenDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[11] & 0x02u) != 0u)
    {
        enDM_Wade4HDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[11] & 0x04u) != 0u)
    {
        enDM_Wade4LDPR = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[11] & 0x08u) != 0u)
    {
        enDM_IMCDPR = WN_enDISPLAY_ON;
    }
    //1.114 PHEV
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[11] & 0x10u) != 0u)
    {
        enDM_PHEV_AutoStart = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[11] & 0x20u) != 0u)
    {
        enDM_PHEV_EvStart = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[11] & 0x40u) != 0u)
    {
        enDM_PHEV_SaveStart = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[11] & 0x80u) != 0u)
    {
        enDM_PHEV_SportStart = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[12] & 0x01u) != 0u)
    {
        enDM_PHEV_AWDStart = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[12] & 0x02u) != 0u)
    {
        enDM_PHEV_SnowStart = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[12] & 0x04u) != 0u)
    {
        enDM_PHEV_MuddyStart = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[12] & 0x08u) != 0u)
    {
        enDM_PHEV_SandStart = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[12] & 0x10u) != 0u)
    {
        enDM_PHEV_SportPlusStart = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[12] & 0x20u) != 0u)
    {
        enDM_PHEV_EcoStart = WN_enDISPLAY_ON;
    }
    //1.115 EV
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[12] & 0x40u) != 0u)
    {
        enDM_EV_StandardStart = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[12] & 0x80u) != 0u)
    {
        enDM_EV_SportStart = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[13] & 0x01u) != 0u)
    {
        enDM_EV_EcoStart = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[13] & 0x02u) != 0u)
    {
        enDM_EV_AutoStart = WN_enDISPLAY_ON;
    }
    if ((DM_tstDrvModStatusRecord_Tmp.WarningStatus[13] & 0x04u) != 0u)
    {
        enDM_EV_SnowStart = WN_enDISPLAY_ON;
    }

    m_DrvModeCase = DM_tstDrvModStatusRecord_Tmp.WarningStatus[14];

    WN_SET(WN_enDM_B30_Standard, enDM_B30_Standard);
    WN_SET(WN_enDM_B30_Sport, enDM_B30_Sport);
    WN_SET(WN_enDM_B30_Snow, enDM_B30_Snow);
    WN_SET(WN_enDM_B30_Muddy, enDM_B30_Muddy);
    WN_SET(WN_enDM_B30_Sand, enDM_B30_Sand);
    WN_SET(WN_enDM_B30_4L, enDM_B30_4L);
    WN_SET(WN_enDM_B30_ECO, enDM_B30_ECO);
    WN_SET(WN_enDM_B30_IMC, enDM_B30_IMC);
    WN_SET(WN_enDM_B30_SportPlus, enDM_B30_SportPlus);
    WN_SET(WN_enDM_B30_OffRoad, enDM_B30_OffRoad);
    WN_SET(WN_enDM_B30_Expert, enDM_B30_Expert);
    WN_SET(WN_enDM_B30_Rock, enDM_B30_Rock);
    WN_SET(WN_enDM_B30_Pothole, enDM_B30_Pothole);
    WN_SET(WN_enDM_B30_MuddySand, enDM_B30_MuddySand);
    WN_SET(WN_enDM_B30_Mountain, enDM_B30_Mountain);
    WN_SET(WN_enDM_B30_Turbo, enDM_B30_Turbo);
    WN_SET(WN_enDM_B30_Race, enDM_B30_Race);
    WN_SET(WN_enDM_B30_GrassGravel, enDM_B30_GrassGravel);
    WN_SET(WN_enDM_B30_Uneven, enDM_B30_Uneven);
    WN_SET(WN_enDM_B30_Wade4H, enDM_B30_Wade4H);
    WN_SET(WN_enDM_B30_Wade4L, enDM_B30_Wade4L);
    WN_SET(WN_enDM_B30_2H, enDM_B30_2H);
    WN_SET(WN_enDM_B30_4H, enDM_B30_4H);

    WN_SET(WN_enDM_StandardSecond, enDM_StandardSecond);
    WN_SET(WN_enDM_SportSecond, enDM_SportSecond);
    WN_SET(WN_enDM_SnowSecond, enDM_SnowSecond);
    WN_SET(WN_enDM_MuddySecond, enDM_MuddySecond);
    WN_SET(WN_enDM_SandSecond, enDM_SandSecond);
    WN_SET(WN_enDM_4LSecond,enDM_4LSecond);
    WN_SET(WN_enDM_ECOSecond, enDM_ECOSecond);
    WN_SET(WN_enDM_IMCSecond, enDM_IMCSecond);
    WN_SET(WN_enDM_SportPlusSecond, enDM_SportPlusSecond);
    WN_SET(WN_enDM_OffRoadSecond, enDM_OffRoadSecond);
    WN_SET(WN_enDM_ExpertSecond, enDM_ExpertSecond);
    WN_SET(WN_enDM_RockSecond, enDM_RockSecond);
    WN_SET(WN_enDM_PotholeSecond, enDM_PotholeSecond);
    WN_SET(WN_enDM_MuddySandSecond, enDM_MuddySandSecond);
    WN_SET(WN_enDM_MountainSecond, enDM_MountainSecond);
    WN_SET(WN_enDM_TurboSecond, enDM_TurboSecond);
    WN_SET(WN_enDM_RaceSecond, enDM_RaceSecond);
    WN_SET(WN_enDM_GrassGravelSecond, enDM_GrassGravelSecond);
    WN_SET(WN_enDM_UnevenSecond, enDM_UnevenSecond);
    WN_SET(WN_enDM_Wade4HSecond, enDM_Wade4HSecond);
    WN_SET(WN_enDM_Wade4LSecond, enDM_Wade4LSecond);
    WN_SET(WN_enDM_2HSecond, enDM_2HSecond);
    WN_SET(WN_enDM_4HSecond, enDM_4HSecond);

    WN_SET(WN_enDM_StandardSelect, enDM_StandardSelect);
    WN_SET(WN_enDM_SportSelect, enDM_SportSelect);
    WN_SET(WN_enDM_SnowSelect, enDM_SnowSelect);
    WN_SET(WN_enDM_ExpertSelect, enDM_ExpertSelect);
    WN_SET(WN_enDM_MuddySelect, enDM_MuddySelect);
    WN_SET(WN_enDM_SandSelect, enDM_SandSelect);
    WN_SET(WN_enDM_4LSelect, enDM_4LSelect);
    WN_SET(WN_enDM_EcoSelect, enDM_EcoSelect);
    WN_SET(WN_enDM_OffRoadSelect, enDM_OffRoadSelect);
    WN_SET(WN_enDM_SportPlusSelect, enDM_SportPlusSelect);
    WN_SET(WN_enDM_RockSelect, enDM_RockSelect);
    WN_SET(WN_enDM_PotholeSelect, enDM_PotholeSelect);
    WN_SET(WN_enDM_MuddySandSelect, enDM_MuddySandSelect);
    WN_SET(WN_enDM_MountainSelect, enDM_MountainSelect);
    WN_SET(WN_enDM_TurboSelect, enDM_TurboSelect);
    WN_SET(WN_enDM_RaceSelect, enDM_RaceSelect);
    WN_SET(WN_enDM_GrassGravelSelect, enDM_GrassGravelSelect);
    WN_SET(WN_enDM_UnevenSelect, enDM_UnevenSelect);
    WN_SET(WN_enDM_Wade4HSelect, enDM_Wade4HSelect);
    WN_SET(WN_enDM_Wade4LSelect, enDM_Wade4LSelect);
    WN_SET(WN_enDM_2HSelect, enDM_2HSelect);
    WN_SET(WN_enDM_4HSelect, enDM_4HSelect);
    WN_SET(WN_enDM_IMCSelect, enDM_IMCSelect);
    
    WN_SET(WN_enDM_StandardDPR, enDM_StandardDPR);
    WN_SET(WN_enDM_SportDPR, enDM_SportDPR);
    WN_SET(WN_enDM_SnowDPR, enDM_SnowDPR);
    WN_SET(WN_enDM_ExpertDPR, enDM_ExpertDPR);
    WN_SET(WN_enDM_MuddyDPR, enDM_MuddyDPR);
    WN_SET(WN_enDM_SandDPR, enDM_SandDPR);
    WN_SET(WN_enDM_4LDPR, enDM_4LDPR);
    WN_SET(WN_enDM_EcoDPR, enDM_EcoDPR);
    WN_SET(WN_enDM_OffRoadDPR, enDM_OffRoadDPR);
    WN_SET(WN_enDM_SportPlusDPR, enDM_SportPlusDPR);
    WN_SET(WN_enDM_RockDPR, enDM_RockDPR);
    WN_SET(WN_enDM_PotholeDPR, enDM_PotholeDPR);
    WN_SET(WN_enDM_MuddySandDPR, enDM_MuddySandDPR);
    WN_SET(WN_enDM_MountainDPR, enDM_MountainDPR);
    WN_SET(WN_enDM_TurboDPR, enDM_TurboDPR);
    WN_SET(WN_enDM_RaceDPR, enDM_RaceDPR);
    WN_SET(WN_enDM_GrassGravelDPR, enDM_GrassGravelDPR);
    WN_SET(WN_enDM_UnevenDPR, enDM_UnevenDPR);
    WN_SET(WN_enDM_Wade4HDPR, enDM_Wade4HDPR);
    WN_SET(WN_enDM_Wade4LDPR, enDM_Wade4LDPR);
    WN_SET(WN_enDM_2HDPR, enDM_2HDPR);
    WN_SET(WN_enDM_4HDPR, enDM_4HDPR);
    WN_SET(WN_enDM_IMCDPR, enDM_IMCDPR);
    
    WN_SET(WN_enDM_PHEV_AutoStart, enDM_PHEV_AutoStart);
    WN_SET(WN_enDM_PHEV_EvStart, enDM_PHEV_EvStart);
    WN_SET(WN_enDM_PHEV_SaveStart, enDM_PHEV_SaveStart);
    WN_SET(WN_enDM_PHEV_SportStart, enDM_PHEV_SportStart);
    WN_SET(WN_enDM_PHEV_AWDStart, enDM_PHEV_AWDStart);
    WN_SET(WN_enDM_PHEV_SnowStart, enDM_PHEV_SnowStart);
    WN_SET(WN_enDM_PHEV_MuddyStart, enDM_PHEV_MuddyStart);
    WN_SET(WN_enDM_PHEV_SandStart, enDM_PHEV_SandStart);
    WN_SET(WN_enDM_PHEV_EcoStart, enDM_PHEV_EcoStart);
    WN_SET(WN_enDM_PHEV_SportPlusStart, enDM_PHEV_SportPlusStart);

    WN_SET(WN_enDM_EV_StandardStart, enDM_EV_StandardStart);
    WN_SET(WN_enDM_EV_SportStart, enDM_EV_SportStart);
    WN_SET(WN_enDM_EV_EcoStart, enDM_EV_EcoStart);
    WN_SET(WN_enDM_EV_SnowStart, enDM_EV_SnowStart);
    WN_SET(WN_enDM_EV_AutoStart, enDM_EV_AutoStart);
}
void WN_SinPedalFuncProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enDM_V51EV_SinPedalStart = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDM_V51EV_SinPedalQuit = WN_enDISPLAY_OFF;

    //Byte53 Bit1-bit0
    uint8 configPedalControlSts = 0;
    //Byte2 Bit7-bit4
    uint8 configFuel = 0;

    //VCU_FD3 0x219 50ms TBD
    uint8 VCU_OPDSt = 0;
    //uint8 Rte_VCU_OPDSt = RTE_E_INVALID;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configPedalControlSts = (uint8)WN_GetSingleConfig(WN_enCfg_PedalControlSts);

    if ((configFuel == 5) && (configPedalControlSts == 1))
    {
        //1.117
        if (0)
        {
            if (VCU_OPDSt == 0x1)
            {
                enDM_V51EV_SinPedalStart = WN_enDISPLAY_ON;
            }
            else if ((m_VCU_OPDSt_pre == 0x1) && (VCU_OPDSt == 0x2))
            {
                enDM_V51EV_SinPedalQuit = WN_enDISPLAY_ON;
            }
        }
        m_VCU_OPDSt_pre = VCU_OPDSt;
    }
    
    WN_SET(WN_enDM_V51EV_SinPedalStart, enDM_V51EV_SinPedalStart);
    WN_SET(WN_enDM_V51EV_SinPedalQuit, enDM_V51EV_SinPedalQuit);
}
void WN_GPFRegenerateProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enGPFRegenerating = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enGPFRegenerate = WN_enDISPLAY_OFF;

    //Byte42 Bit7-bit3
    uint8 configEngCtrolUnit = 0;

    //ECM3 0x371 100ms
    uint8 GPF_Warning_temp = 0;
    uint8 Rte_GPF_Warning = RTE_E_INVALID;

    configEngCtrolUnit = (uint8)WN_GetSingleConfig(WN_enCfg_EngCtrolUnit);

    Rte_GPF_Warning = WN_GPF_Warning_SignalGet(&GPF_Warning_temp);

    if ((configEngCtrolUnit == 1) || (configEngCtrolUnit == 2) || (configEngCtrolUnit == 6))
    {
        //1.118
        if ((RTE_E_OK == Rte_GPF_Warning) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_GPF_Warning))
        {
            if (GPF_Warning_temp == 0x1)
            {
                enGPFRegenerating = WN_enDISPLAY_ON;
            }
            else if (GPF_Warning_temp == 0x2)
            {
                enGPFRegenerate = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
    }

    WN_SET(WN_enGPFRegenerating, enGPFRegenerating);
    WN_SET(WN_enGPFRegenerate, enGPFRegenerate);
}
void WN_OutTemperatureProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{

    //Byte43 Bit1-bit0
    uint8 configOusideTemp = 0;

    //AC2 0x385 100ms
    uint8 ACAmbTemp_temp = 0;
    uint8 Rte_ACAmbTemp = RTE_E_INVALID;

    configOusideTemp = (uint8)WN_GetSingleConfig(WN_enCfg_OusideTemp);

    Rte_ACAmbTemp = WN_ACAmbTemp_SignalGet(&ACAmbTemp_temp);

    if (configOusideTemp == 1)
    {
        //1.119
        if(KL15On_DelayEndSts)
        {
            if ((RTE_E_OK == Rte_ACAmbTemp) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_ACAmbTemp))
            {
                if((ACAmbTemp_temp > 0x56) && (ACAmbTemp_temp < 0x5A))
                {
                    if(PreACAmbTemp_temp <= 0x56)
                    {
                        m_enOutTempLow = WN_enDISPLAY_ON;
                    }
                    else if (PreACAmbTemp_temp >= 0x5A)
                    {
                        m_enOutTempLow = WN_enDISPLAY_OFF;
                    }
                    else
                    {

                    }
                }
                else if (ACAmbTemp_temp <= 0x56) //3摄氏度
                {
                    PreACAmbTemp_temp = ACAmbTemp_temp;
                    m_enOutTempLow = WN_enDISPLAY_ON;
                }
                else if (ACAmbTemp_temp >= 0x5A) //5摄氏度
                {
                    PreACAmbTemp_temp = ACAmbTemp_temp;
                    m_enOutTempLow = WN_enDISPLAY_OFF;
                }
                else
                {
                    /* do nothing */
                }
            }
            else
            {
                m_enOutTempLow = WN_enDISPLAY_OFF;
                m_OutTempLowInit = FALSE;
            }
            if((m_OutTempLowInit == TRUE) && (m_enOutTempLow == WN_enDISPLAY_ON))
            {
                /* do nothing */
            }
            else
            {
                WN_SET(WN_enOutTempLow, m_enOutTempLow);
                if(m_enOutTempLow == WN_enDISPLAY_ON)
                {
                    m_OutTempLowInit = TRUE;
                }
            }
            
        }
        else
        {
            m_OutTempLowInit = FALSE;
        }
    }
    WN_SET(WN_enOutTempLow, m_enOutTempLow);
}
void WN_LasHdLightWarningProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enLasHdLightFault = WN_enDISPLAY_OFF;

    //Byte38 Bit5-bit4
    uint8 configSmartJuncBox = 0;
    //Byte37 Bit7-bit4
    uint8 configHeadLighting = 0;
    //Byte80 Bit7-bit6
    uint8 configCentralModule = 0;

    //F_Pbox1 0x19B 50ms
    boolean LLasHdLmpDiagSig_temp = FALSE;
    boolean RLasHdLmpDiagSig_temp = FALSE;
    boolean LasHdLmpSts_F_PBOX_temp = FALSE;
    uint8 Rte_F_Pbox1Sts = RTE_E_INVALID;

    configSmartJuncBox = (uint8)WN_GetSingleConfig(WN_enCfg_SmartJuncBox);
    configCentralModule = (uint8)WN_GetSingleConfig(WN_enCfg_CentralModule);
    configHeadLighting = (uint8)WN_GetSingleConfig(WN_enCfg_HeadLighting);

    Rte_F_Pbox1Sts = WN_LLasHdLmpDiagSig_SignalGet(&LLasHdLmpDiagSig_temp);
    Rte_F_Pbox1Sts = WN_RLasHdLmpDiagSig_SignalGet(&RLasHdLmpDiagSig_temp);
    Rte_F_Pbox1Sts = WN_LasHdLmpSts_F_PBOX_SignalGet(&LasHdLmpSts_F_PBOX_temp);

    if (((configSmartJuncBox == 1) || (configCentralModule == 1)) && (configHeadLighting == 5))
    {
        /* if (WN_enRUN == m_PowerModeStatus)
        {
            if ((RTE_E_OK == Rte_F_Pbox1Sts) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_F_Pbox1Sts))
            {
                if (m_LasHdLightSignalInit)
                {
                    if (m_u8LasHdLightSts_PBOX_pre == 0 && LasHdLmpSts_F_PBOX_temp == 0x1)
                    {
                        m_enLasHdLightOn = WN_enDISPLAY_ON;
                        m_enLasHdLightOff = WN_enDISPLAY_OFF;
                    }
                    if (m_u8LasHdLightSts_PBOX_pre == 1 && LasHdLmpSts_F_PBOX_temp == 0x0)
                    {
                        m_enLasHdLightOff = WN_enDISPLAY_ON;
                        m_enLasHdLightOn = WN_enDISPLAY_OFF;
                    }
                    m_u8LasHdLightSts_PBOX_pre = LasHdLmpSts_F_PBOX_temp;
                }
                else
                {
                    m_u8LasHdLightSts_PBOX_pre = LasHdLmpSts_F_PBOX_temp;
                    m_LasHdLightSignalInit = TRUE;
                }
            }
            else
            {
                m_enLasHdLightOn = WN_enDISPLAY_OFF;
                m_enLasHdLightOff = WN_enDISPLAY_OFF;
                m_u8LasHdLightSts_PBOX_pre = 0;
                m_LasHdLightSignalInit = FALSE;
            }
        }
        else
        {
            m_enLasHdLightOn = WN_enDISPLAY_OFF;
            m_enLasHdLightOff = WN_enDISPLAY_OFF;
            m_u8LasHdLightSts_PBOX_pre = 0;
            m_LasHdLightSignalInit = FALSE;
        } */

        //1.120
        if ((RTE_E_OK == Rte_F_Pbox1Sts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_F_Pbox1Sts))
        {
            if ((LLasHdLmpDiagSig_temp == TRUE) || (RLasHdLmpDiagSig_temp == TRUE))
            {
                enLasHdLightFault = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enLasHdLightFault, enLasHdLightFault);
    //WN_SET(WN_enLasHdLightOn, m_enLasHdLightOn);
    //WN_SET(WN_enLasHdLightOff, m_enLasHdLightOff);
}
void WN_FarLasHdLightWarningProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enFarBeamFault = WN_enDISPLAY_OFF;

    //Byte59 Bit7-bit6
    uint8 configLongAssHiBeam = 0;

    //HCM_L1 0x308 200ms
    uint8 LLasHdLmpfailSts_temp = 0;
    //uint8 LLasHdLmpSts_temp = 0;
    uint8 Rte_HCM_L1 = RTE_E_INVALID;
    //HCM_R1 0x30D 200ms
    uint8 RLasHdLmpfailSts_temp = 0;
    //uint8 RLasHdLmpSts_temp = 0;
    uint8 Rte_HCM_R1 = RTE_E_INVALID;

    configLongAssHiBeam = (uint8)WN_GetSingleConfig(WN_enCfg_LongAssHiBeam);

    Rte_HCM_L1 = WN_LLasHdLmpfailSts_SignalGet(&LLasHdLmpfailSts_temp);
    //Rte_HCM_L1 = WN_LLasHdLmpSts_SignalGet(&LLasHdLmpSts_temp);
    Rte_HCM_R1 = WN_RLasHdLmpfailSts_SignalGet(&RLasHdLmpfailSts_temp);
    //Rte_HCM_R1 = WN_RLasHdLmpSts_SignalGet(&RLasHdLmpSts_temp);

    if (configLongAssHiBeam == 1)
    {
        //1.122
        if (((RTE_E_OK == Rte_HCM_L1) ||
             (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCM_L1)) &&
            ((RTE_E_OK == Rte_HCM_R1) ||
             (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCM_R1)))
        {
            if ((LLasHdLmpfailSts_temp == 1) || (RLasHdLmpfailSts_temp == 1))
            {
                enFarBeamFault = WN_enDISPLAY_ON;
            }
        }
        /* if (WN_enRUN == m_PowerModeStatus)
        {
            if (((RTE_E_OK == Rte_HCM_L1) ||
                 (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCM_L1)) &&
                ((RTE_E_OK == Rte_HCM_R1) ||
                 (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCM_R1)))
            {
                if (m_LasHdLmpStsSignalInit)
                {
                    if (((m_PreLLasHdLmpSts) == 0 && (LLasHdLmpSts_temp == 0x1)) || ((m_PreRLasHdLmpSts) == 0 && (RLasHdLmpSts_temp == 0x1)))
                    {
                        m_enFarBeamOn = WN_enDISPLAY_ON;
                        m_enFarBeamOff = WN_enDISPLAY_OFF;
                    }
                    if (((m_PreLLasHdLmpSts == 1) || (m_PreRLasHdLmpSts == 1)) && ((LLasHdLmpSts_temp == 0x0) && (RLasHdLmpSts_temp == 0x0)))
                    {
                        m_enFarBeamOff = WN_enDISPLAY_ON;
                        m_enFarBeamOn = WN_enDISPLAY_OFF;
                    }
                }
                else
                {
                    m_LasHdLmpStsSignalInit = TRUE;
                }
                m_PreLLasHdLmpSts = LLasHdLmpSts_temp;
                m_PreRLasHdLmpSts = RLasHdLmpSts_temp;
            }
            else
            {
                m_enFarBeamOn = WN_enDISPLAY_OFF;
                m_enFarBeamOff = WN_enDISPLAY_OFF;
                m_PreLLasHdLmpSts = 0;
                m_PreRLasHdLmpSts = 0;
                m_LasHdLmpStsSignalInit = FALSE;
            }
        }
        else
        {
            m_enFarBeamOn = WN_enDISPLAY_OFF;
            m_enFarBeamOff = WN_enDISPLAY_OFF;
            m_PreLLasHdLmpSts = 0;
            m_PreRLasHdLmpSts = 0;
            m_LasHdLmpStsSignalInit = FALSE;
        } */
    }
    WN_SET(WN_enFarBeamFault, enFarBeamFault);
    //WN_SET(WN_enFarBeamOn, m_enFarBeamOn);
    //WN_SET(WN_enFarBeamOff, m_enFarBeamOff);
}
void WN_PixelHeadlightProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enPHLWideOff = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPHLWideOn = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPHLWideFunOff = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPHLFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPHLCameraFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPHLFunOff = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPHLFunOn = WN_enDISPLAY_OFF;

    //Byte37 Bit7-bit4
    uint8 configHeadLight = 0;

    //FCM1 0x2C5 100ms TBD
    uint8 WideLightOutputReq = 0;
    uint8 CameraFailSts = 0;
    uint8 DLPFuncSts = 0;
    //DMD_L1 0x2C7 100ms TBD
    uint8 LeftDMDDrvFailSts = 0;
    uint8 RightDMDDrvFailSts = 0;
    uint8 LeftAuxDrvFailSts = 0;
    uint8 RightAuxDrvFailSts = 0;

    configHeadLight = (uint8)WN_GetSingleConfig(WN_enCfg_HeadLighting);

    //Com_ReceiveSignal(COM_SINGAL_RX_FCM1_WIDELIGHTOUTPUTREQ, &WideLightOutputReq);
    //Com_ReceiveSignal(COM_SINGAL_RX_FCM1_CAMERAFAILSTS, &CameraFailSts);
    //Com_ReceiveSignal(COM_SINGAL_RX_FCM1_DLPFUNCSTS, &DLPFuncSts);

    if (configHeadLight == 6)
    {
        if (0)
        {
            //1.123
            if (WideLightOutputReq == 0x0)
            {
                enPHLWideOff = WN_enDISPLAY_ON;
            }
            else if (WideLightOutputReq == 0x1)
            {
                enPHLWideOn = WN_enDISPLAY_ON;
            }
            else if (WideLightOutputReq == 0x2)
            {
                enPHLWideFunOff = WN_enDISPLAY_ON;
            }
            else
            {
            }
            //1.124
            if ((LeftDMDDrvFailSts == 0x1) || (RightDMDDrvFailSts == 0x1) ||
                (LeftAuxDrvFailSts == 0x1) || (RightAuxDrvFailSts == 0x1))
            {
                enPHLFault = WN_enDISPLAY_ON;
            }
            //1.125
            if (CameraFailSts == 0x1)
            {
                enPHLCameraFault = WN_enDISPLAY_ON;
            }
            //1.126
            if (DLPFuncSts == 0x1)
            {
                enPHLFunOff = WN_enDISPLAY_ON;
            }
            else if (DLPFuncSts == 0x2)
            {
                enPHLFunOn = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
    }

    WN_SET(WN_enPHLWideOff, enPHLWideOff);
    WN_SET(WN_enPHLWideOn, enPHLWideOn);
    WN_SET(WN_enPHLWideFunOff, enPHLWideFunOff);
    WN_SET(WN_enPHLCameraFault, enPHLCameraFault);
    WN_SET(WN_enPHLFunOff, enPHLFunOff);
    WN_SET(WN_enPHLFunOn, enPHLFunOn);
    WN_SET(WN_enPHLFault, enPHLFault);
}
void WN_ALSSysFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enALSSysFault = WN_enDISPLAY_OFF;

    //Byte9 Bit3-bit0
    uint8 configHeadLampAdjust = 0;

    //HC1 0x287 100ms
    uint8 ALS_FailSts_temp = 0;
    uint8 Rte_SG_HC1_Tmp = RTE_E_INVALID;

    configHeadLampAdjust = (uint8)WN_GetSingleConfig(WN_enCfg_HeadLampAdjust);

    Rte_SG_HC1_Tmp = WN_ALS_FailSts_SignalGet(&ALS_FailSts_temp);

    if (configHeadLampAdjust == 2)
    {
        //1.127
        if ((RTE_E_OK == Rte_SG_HC1_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_HC1_Tmp))
        {
            if (ALS_FailSts_temp == 1)
            {
                enALSSysFault = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enALSSysFault, enALSSysFault);
}
void WN_ALSDrivingSideProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enALSDrivingSide = WN_enDISPLAY_OFF;

    //Byte9 Bit3-bit0
    uint8 configHeadLampAdjust = 0;

    //HC1 0x287 100ms TBD
    uint8 ALSDrvSide_FB = 0;

    configHeadLampAdjust = (uint8)WN_GetSingleConfig(WN_enCfg_HeadLampAdjust);

    //Com_ReceiveSignal(COM_SINGAL_RX_, &FeedbackALSDrivingSide);

    if (configHeadLampAdjust == 2)
    {
        //1.128
        if (0)
        {
            if (ALSDrvSide_FB == 1)
            {
                enALSDrivingSide = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enALSDrivingSide, enALSDrivingSide);
}
void WN_AFSStsProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enAFSSystemFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAFSOn = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAFSOff = WN_enDISPLAY_OFF;

    //Byte60 Bit7-bit5
    uint8 configHeadLampCtrlFunc = 0;
    //Byte59 Bit5-bit4
    uint8 configAFS = 0;

    //TBD
    uint8 AFSstatus = 0;
    //HCM_L1 0x308 200ms
    uint8 LAFSstatus_temp = 0;
    uint8 Rte_LAFSstatus = RTE_E_INVALID;
    //HCM_R1 0x30D 200ms
    uint8 RAFSstatus_temp = 0;
    uint8 Rte_RAFSstatus = RTE_E_INVALID;

    configHeadLampCtrlFunc = (uint8)WN_GetSingleConfig(WN_enCfg_HeadLampCtrlFunc);
    configAFS = (uint8)WN_GetSingleConfig(WN_enCfg_AFS);

    if (configAFS == 1)
    {
        if (configHeadLampCtrlFunc == 1)//case 1
        {
            //1.129
            if (0)
            {
                if (AFSstatus == 0x2)
                {
                    enAFSSystemFault = WN_enDISPLAY_ON;
                }
            }
        }
        else if (configHeadLampCtrlFunc == 2)//case 2
        {
            Rte_LAFSstatus = WN_LAFSstatus_SignalGet(&LAFSstatus_temp);
            Rte_RAFSstatus = WN_RAFSstatus_SignalGet(&RAFSstatus_temp);
            if (((RTE_E_OK == Rte_LAFSstatus) ||
                 (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_LAFSstatus)) ||
                ((RTE_E_OK == Rte_RAFSstatus) ||
                 (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_RAFSstatus)))
            {
                if ((LAFSstatus_temp == 2) || (RAFSstatus_temp == 2))
                {
                    enAFSSystemFault = WN_enDISPLAY_ON;
                }
#if 0
                else if((LAFSstatus_temp == 1) || (RAFSstatus_temp == 1))
                {
                    enAFSOn = WN_enDISPLAY_ON;
                }
                else if((LAFSstatus_temp == 0) && (RAFSstatus_temp == 0))
                {
                    enAFSOff = WN_enDISPLAY_ON;
                }
#endif
                else
                {

                }
            }
        }
        else
        {

        }
    }

    WN_SET(WN_enAFSSystemFault, enAFSSystemFault);
    WN_SET(WN_enAFSOn, enAFSOn);
    WN_SET(WN_enAFSOff, enAFSOff);
}
void WN_AFSDrivingModeProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enAFSDrivingMode = WN_enDISPLAY_OFF;

    //Byte9 Bit3-bit0
    uint8 configHeadLampAdjust = 0;

    //HC1 0x287 100ms TBD
    uint8 FeedbackAFSDrivingSide = 0;

    configHeadLampAdjust = (uint8)WN_GetSingleConfig(WN_enCfg_HeadLampAdjust);

    if (configHeadLampAdjust == 3)
    {
        //1.130
        if (0)
        {
            if (FeedbackAFSDrivingSide == 0x1)
            {
                enAFSDrivingMode = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enAFSDrivingMode, enAFSDrivingMode);
}
void WN_HighBeamSysFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enHighBeamSysFault = WN_enDISPLAY_OFF;

    //Byte33 Bit3-bit0
    uint8 configHeadLampBeamSys = 0;
    //Byte38 Bit5-bit4
    uint8 configSmartJuncBox = 0;
    //Byte60 Bit7-bit5
    uint8 configHeadLampCtrlFunc = 0;
    //Byte80 Bit7-bit6
    uint8 configCentralModule = 0;

    //F_Pbox1 0x19B 50ms
    //HCM_L1 HCM_R1 0x308 0x30D 200ms
    uint8 LLowBeamFailSts_temp = 0;
    uint8 RLowBeamFailSts_temp = 0;
    uint8 LHiBeamFailSts_temp = 0;
    uint8 RHiBeamFailSts_temp = 0;
    uint8 LHeadLmpFailSts_temp = 0;
    uint8 RHeadLmpFailSts_temp = 0;
    uint8 Rte_F_Pbox1Sts = RTE_E_INVALID;
    uint8 Rte_HCM_L1Sts = RTE_E_INVALID;
    uint8 Rte_HCM_R1Sts = RTE_E_INVALID;

    //HC1 0x287 100ms
    uint8 LeftHighBeamFailSts_temp = 0;
    uint8 RightHighBeamFailSts_temp = 0;
    uint8 Rte_SG_HC1_Tmp = RTE_E_INVALID;

    configSmartJuncBox = (uint8)WN_GetSingleConfig(WN_enCfg_SmartJuncBox);
    configCentralModule = (uint8)WN_GetSingleConfig(WN_enCfg_CentralModule);
    configHeadLampBeamSys = (uint8)WN_GetSingleConfig(WN_enCfg_HeadLampBeamSys);
    configHeadLampCtrlFunc = (uint8)WN_GetSingleConfig(WN_enCfg_HeadLampCtrlFunc);

    Rte_F_Pbox1Sts = WN_LLowBeamFailSts_SignalGet(&LLowBeamFailSts_temp);
    Rte_F_Pbox1Sts = WN_RLowBeamFailSts_SignalGet(&RLowBeamFailSts_temp);
    Rte_F_Pbox1Sts = WN_LHiBeamFailSts_SignalGet(&LHiBeamFailSts_temp);
    Rte_F_Pbox1Sts = WN_RHiBeamFailSts_SignalGet(&RHiBeamFailSts_temp);
    Rte_F_Pbox1Sts = WN_LHeadLmpFailSts_SignalGet(&LHeadLmpFailSts_temp);
    Rte_F_Pbox1Sts = WN_RHeadLmpFailSts_SignalGet(&RHeadLmpFailSts_temp);

    Rte_SG_HC1_Tmp = WN_LeftHighBeamFailSts_SignalGet(&LeftHighBeamFailSts_temp);
    Rte_SG_HC1_Tmp = WN_RightHighBeamFailSts_SignalGet(&RightHighBeamFailSts_temp);

    if ((configHeadLampBeamSys == 3) && (configHeadLampCtrlFunc == 2))
    {
        //1.131
        Rte_HCM_L1Sts = WN_LLowBeamFailSts_HCM_SignalGet(&LLowBeamFailSts_temp);
        Rte_HCM_L1Sts = WN_LHiBeamFailSts_HCM_SignalGet(&LHiBeamFailSts_temp);
        Rte_HCM_R1Sts = WN_RLowBeamFailSts_HCM_SignalGet(&RLowBeamFailSts_temp);
        Rte_HCM_R1Sts = WN_RHiBeamFailSts_HCM_SignalGet(&RHiBeamFailSts_temp);
        if (((RTE_E_OK == Rte_HCM_L1Sts) ||
             (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCM_L1Sts)) ||
            ((RTE_E_OK == Rte_HCM_R1Sts) ||
             (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCM_R1Sts)))
        {
            if ((LLowBeamFailSts_temp == 1) || (RLowBeamFailSts_temp == 1) ||
                (LHiBeamFailSts_temp == 1) || (RHiBeamFailSts_temp == 1))
            {
                enHighBeamSysFault = WN_enDISPLAY_ON;
            }
        }
    }


    if ((configHeadLampBeamSys == 3) && (configHeadLampCtrlFunc == 1) && ((configSmartJuncBox == 1) || (configCentralModule == 1)))
    {
        //1.132
        if ((RTE_E_OK == Rte_SG_HC1_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_HC1_Tmp))
        {
            if ((LeftHighBeamFailSts_temp == 1) || (RightHighBeamFailSts_temp == 1))
            {
                enHighBeamSysFault = WN_enDISPLAY_ON;
            }
        }
        if ((RTE_E_OK == Rte_F_Pbox1Sts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_F_Pbox1Sts))
        {
            if ((LLowBeamFailSts_temp == 1) || (RLowBeamFailSts_temp == 1) ||
                (LHeadLmpFailSts_temp == 1) || (RHeadLmpFailSts_temp == 1))
            {
                enHighBeamSysFault = WN_enDISPLAY_ON;
            }
        }
    }
    if (((configHeadLampBeamSys == 0) || (configHeadLampBeamSys == 1) || (configHeadLampBeamSys == 2)) && ((configSmartJuncBox == 1) || (configCentralModule == 1)))
    {
        //1.133
        if ((RTE_E_OK == Rte_F_Pbox1Sts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_F_Pbox1Sts))
        {
            if ((LLowBeamFailSts_temp == 1) || (RLowBeamFailSts_temp == 1) ||
                (LHiBeamFailSts_temp == 1) || (RHiBeamFailSts_temp == 1) ||
                (LHeadLmpFailSts_temp == 1) || (RHeadLmpFailSts_temp == 1))
            {
                enHighBeamSysFault = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enHighBeamSysFault, enHighBeamSysFault);
}
void WN_ESOFDrivingModeProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common en4LEnGearN = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common en4LEnGearDRP = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common en4LExGearN = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common en4LExGearDRP = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common en4LEnClutchStep = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common en4LEnClutchRele = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common en4LExClutchStep = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common en4LExClutchRele = WN_enDISPLAY_OFF;

#if 0
    //Byte30 Bit3-bit0
    uint8 configTransferCase = 0;
    //Byte3 Bit7-bit0
    uint8 configTransmission = 0;

    //BCM11 0x305 100ms TBD
    uint8 m4DrvModSwtReq = 0;
    //T0D1 0x251 20ms TBD
    uint8 SystemOperMode = 0;
    //DCT9 0x0C6 50ms TBD
    uint8 DrvModDisp_temp = 0;
    //ECM10 0x139 20ms TBD
    uint8 ClutBottomSwt = 0;

    configTransmission = (uint8)WN_GetSingleConfig(WN_enCfg_Transmission);
    configTransferCase = (uint8)WN_GetSingleConfig(WN_enCfg_TransCase);

    //Com_ReceiveSignal(COM_SINGAL_RX_, &4DrvModSwtReq);
    //Com_ReceiveSignal(COM_SINGAL_RX_, &SystemOperMode);
    //Com_ReceiveSignal(COM_SINGAL_RX_, &DrvModDisp);
    //Com_ReceiveSignal(COM_SINGAL_RX_, &ClutBottomSwt);
    if (0)
    {
        //1.134 TBD
        if ((configTransmission == 8) && (configTransferCase == 1))
        {
            if (((SystemOperMode == 0x2) || (SystemOperMode == 0x3)) && (m4DrvModSwtReq == 0x6))
            {
                if (DrvModDisp_temp != 0x2)
                {
                    en4LEnGearN = WN_enDISPLAY_ON;
                }
                if (DrvModDisp_temp == 0x2)
                {
                    en4LEnGearDRP = WN_enDISPLAY_ON;
                }
            }
            if (((m4DrvModSwtReq == 0x2) || (m4DrvModSwtReq == 0x3)) && (SystemOperMode == 0x6))
            {
                if (DrvModDisp_temp != 0x2)
                {
                    en4LExGearN = WN_enDISPLAY_ON;
                }
                if (DrvModDisp_temp == 0x2)
                {
                    en4LExGearDRP = WN_enDISPLAY_ON;
                }
            }
        }
        //1.135 TBD
        if (((configTransmission == 2) || (configTransmission == 13)) && (configTransferCase == 1))
        {
            if (((SystemOperMode == 0x2) || (SystemOperMode == 0x3)) && (m4DrvModSwtReq == 0x6))
            {
                if (ClutBottomSwt == 0x0)
                {
                    en4LEnClutchStep = WN_enDISPLAY_ON;
                }
                if (ClutBottomSwt == 0x1)
                {
                    en4LEnClutchRele = WN_enDISPLAY_ON;
                }
            }
            if (((m4DrvModSwtReq == 0x2) || (m4DrvModSwtReq == 0x3)) && (SystemOperMode == 0x6))
            {
                if (ClutBottomSwt == 0x0)
                {
                    en4LExClutchStep = WN_enDISPLAY_ON;
                }
                if (ClutBottomSwt == 0x1)
                {
                    en4LExClutchRele = WN_enDISPLAY_ON;
                }
            }
        }
    }
#endif
    WN_SET(WN_en4LEnGearN, en4LEnGearN);
    WN_SET(WN_en4LEnGearDRP, en4LEnGearDRP);
    WN_SET(WN_en4LExGearN, en4LExGearN);
    WN_SET(WN_en4LExGearDRP, en4LExGearDRP);
    WN_SET(WN_en4LEnClutchStep, en4LEnClutchStep);
    WN_SET(WN_en4LEnClutchRele, en4LEnClutchRele);
    WN_SET(WN_en4LExClutchStep, en4LExClutchStep);
    WN_SET(WN_en4LExClutchRele, en4LExClutchRele);
}
void WN_4LModeSlowProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common en4LModeSlow = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common en4HModeSlow = WN_enDISPLAY_OFF;

    //Byte30 Bit3-bit0
    uint8 configTransCase = 0;

    //T0D1 0x251 20ms
    uint8 SystemOperMod_temp = 0;
    uint8 RTE_SystemOperMod = RTE_E_INVALID;
    //BCM11 0x305 100ms TBD
    uint8 m4DrvModSwtReq = 0;
    //Byte3 Bit7-bit0
    uint8 configTransmission = 0;

    uint16 VehSpd_temp = 0;
    s_SpeedoInfo_t SpeedoInfo_Tmp = {0};

    configTransCase = (uint8)WN_GetSingleConfig(WN_enCfg_TransCase);
    configTransmission = (uint8)WN_GetSingleConfig(WN_enCfg_Transmission);

    WN_SpeedoInfo_APIGet(&SpeedoInfo_Tmp);
    VehSpd_temp = SpeedoInfo_Tmp.IndicateSpeed;
    
    RTE_SystemOperMod = WN_SystemOperMod_SignalGet(&SystemOperMod_temp);

    if ((configTransCase == 3) || (configTransCase == 5))
    {
        if ((RTE_E_OK == RTE_SystemOperMod) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == RTE_SystemOperMod))
        {
            //1.136
            if (SystemOperMod_temp == 0x6)
            {
                if (VehSpd_temp >= 40)
                {
                    en4LModeSlow = WN_enDISPLAY_ON;
                }
            }
        }
    }
    if (configTransCase == 5)
    {
        //1.137
        if ((RTE_E_OK == RTE_SystemOperMod) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == RTE_SystemOperMod))
        {
            if (SystemOperMod_temp == 0x3)
            {
                if (VehSpd_temp >= 80)
                {
                    en4HModeSlow = WN_enDISPLAY_ON;
                }
            }
        }
    }
    //1.138
    if(configTransCase == 1)
    {
        //case 2
        if(configTransmission == 8)
        {
            //case 1
        }
    }

    WN_SET(WN_en4LModeSlow, en4LModeSlow);
    WN_SET(WN_en4HModeSlow, en4HModeSlow);
}
void WN_ModeSwitchFailedProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enModeSwitchFailed = WN_enDISPLAY_OFF;

    //Byte30 Bit3-bit0
    uint8 configTransferCase = 0;

    //T0D1 0x251 20ms
    uint8 ShiftSysStuinLow_temp = 0;
    uint8 RTE_ShiftSysStuinLow = RTE_E_INVALID;

    configTransferCase = (uint8)WN_GetSingleConfig(WN_enCfg_TransCase);

    RTE_ShiftSysStuinLow = WN_ShiftSysStuinLow_SignalGet(&ShiftSysStuinLow_temp);

    if ((configTransferCase == 1) || (configTransferCase == 3) || (configTransferCase == 5))
    {
        if ((RTE_E_OK == RTE_ShiftSysStuinLow) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == RTE_ShiftSysStuinLow))
        {
            //1.139
            if (ShiftSysStuinLow_temp == 0x1)
            {
                enModeSwitchFailed = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enModeSwitchFailed, enModeSwitchFailed);
}
void WN_FuelTankCapWarnProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enFuelTankCapOn = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;

    //ECM_PT6 0x290 100ms
    uint8 FuelTankCapWarning_temp = 0;
    uint8 Rte_FuelTankCapWarning = RTE_E_INVALID;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);

    Rte_FuelTankCapWarning = WN_FuelTankCapWarning_SignalGet(&FuelTankCapWarning_temp);

    if (configFuel == 4)
    {
        //1.141
        if ((RTE_E_OK == Rte_FuelTankCapWarning) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_FuelTankCapWarning))
        {
            if (FuelTankCapWarning_temp == 0x1)
            {
                enFuelTankCapOn = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enFuelTankCapOn, enFuelTankCapOn);
}
void WN_SwitchMudSandProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enSwitchMudSand = WN_enDISPLAY_OFF;
#if 0
    //Byte28 Bit3-bit0
    uint8 configLimitedSlip = 0;

    //ELD1 0x152 20ms
    uint8 RearELDLckSts = 0;
    uint8 Rte_RearELDLckSts = RTE_E_INVALID;

    configLimitedSlip = (uint8)WN_GetSingleConfig(WN_enCfg_LimitedSlip);

    Rte_RearELDLckSts = WN_RearELDLckSts_SignalGet(&RearELDLckSts);

    if ((configLimitedSlip == 3) || (configLimitedSlip == 4))
    {
        //1.142
        if ((RTE_E_OK == Rte_RearELDLckSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_RearELDLckSts))
        {
            if (RearELDLckSts == 0x3)
            {
                enSwitchMudSand = WN_enDISPLAY_ON;
            }
        }
    }
#endif
    WN_SET(WN_enSwitchMudSand, enSwitchMudSand);
}
void WN_WPCPhoneProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enWPCChargeZone = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enWPCTakePhone = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enWPCChargeZoneFront = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enWPCChargeZoneRear = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enWPCChargeZoneRR = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enWPCChargeZoneRL = WN_enDISPLAY_OFF;

    //Byte42 Bit2-bit0
    uint8 configWireless = 0;

    //WPC1 0x2BA 100ms
    uint8 WPC_FaultSts_temp = 0;
    uint8 Rte_WPC_FaultSts = RTE_E_INVALID;
    uint8 WPC_PhoneReminder_temp = 0;
    uint8 Rte_WPC_PhoneReminder = RTE_E_INVALID;
    uint8 RWPC_FaultSts_temp = 0;
    uint8 Rte_RWPC_FaultSts = RTE_E_INVALID;
    uint8 RWPC_L_FaultSts_temp = 0;
    uint8 Rte_RWPC_L_FaultSts = RTE_E_INVALID;
    uint8 WPC_FaultSts_P03_P05 = 0;
    uint8 Rte_WPC_FaultSts_P03_P05 = RTE_E_INVALID;
    uint8 WPC_FaultSts_D01 = 0;
    uint8 Rte_WPC_FaultSts_D01 = RTE_E_INVALID;
    uint8 WPC_FaultSts_D01_D03_P05 = 0;
    uint8 Rte_WPC_FaultSts_D01_D03_P05 = RTE_E_INVALID;

    configWireless = (uint8)WN_GetSingleConfig(WN_enCfg_Wireless);

    Rte_WPC_FaultSts = WN_WPC_FaultSts_SignalGet(&WPC_FaultSts_temp);
    Rte_RWPC_FaultSts = WN_RWPC_FaultSts_SignalGet(&RWPC_FaultSts_temp);
    Rte_RWPC_L_FaultSts = WN_RWPC_L_FaultSts_SignalGet(&RWPC_L_FaultSts_temp);//TBD
    Rte_WPC_PhoneReminder = WN_WPC_PhoneReminder_SignalGet(&WPC_PhoneReminder_temp);

    if ((configWireless == 1) || (configWireless == 3))//R11
    {
        //case 1
        if ((RTE_E_OK == Rte_WPC_FaultSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_WPC_FaultSts))
        {
            //1.143
            if (WPC_FaultSts_temp == 0x1)
            {
                enWPCChargeZone = WN_enDISPLAY_ON;
            }
        }
    }
    if(configWireless == 2)//R12
    {
        //case 2
        Rte_WPC_FaultSts_P03_P05 = WN_WPC_FaultSts_SignalGet_P03_P05(&WPC_FaultSts_P03_P05);
        if((RTE_E_OK == Rte_WPC_FaultSts_P03_P05) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_WPC_FaultSts_P03_P05))
        {
            if(WPC_FaultSts_P03_P05 == 0x1)
            {
             //add for P02 HMI based on P03 2021/10/22
			#ifdef GWM_V35_PROJECT_TYPE_P02
				enWPCChargeZone = WN_enDISPLAY_ON;
			#else
				enWPCChargeZoneFront = WN_enDISPLAY_ON;
			#endif	
            }
        }
        if((RTE_E_OK == Rte_RWPC_FaultSts) || 
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_RWPC_FaultSts))
        {
            if(RWPC_FaultSts_temp == 0x1)
            {
                enWPCChargeZoneRear = WN_enDISPLAY_ON;
            }
        }
    }
    if((configWireless == 5) || (configWireless == 6))//R13 ADD Cfg 6
    {
        //case 3
        Rte_WPC_FaultSts_D01 = WN_WPC_FaultSts_SignalGet_D01(&WPC_FaultSts_D01);
        if((RTE_E_OK == Rte_WPC_FaultSts_D01) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_WPC_FaultSts_D01))
        {
            if(WPC_FaultSts_D01 == 0x1)
            {
                enWPCChargeZoneFront = WN_enDISPLAY_ON;
            }
        }
        if((RTE_E_OK == Rte_RWPC_FaultSts) || 
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_RWPC_FaultSts))
        {
            if(RWPC_FaultSts_temp == 0x1)
            {
                enWPCChargeZoneRR = WN_enDISPLAY_ON;
            }
        }
        if((RTE_E_OK == Rte_RWPC_L_FaultSts) || 
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_RWPC_L_FaultSts))
        {
            if(RWPC_L_FaultSts_temp == 0x1)
            {
                enWPCChargeZoneRL = WN_enDISPLAY_ON;
            }
        }

    }
    if(configWireless == 4)//R13 change
    {
        //case 2
        Rte_WPC_FaultSts_D01_D03_P05 = WN_WPC_FaultSts_SignalGet_D01_D03_P05(&WPC_FaultSts_D01_D03_P05);
        if((RTE_E_OK == Rte_WPC_FaultSts_D01_D03_P05) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_WPC_FaultSts_D01_D03_P05))
        {
            if(WPC_FaultSts_D01_D03_P05 == 0x1)
            {
                enWPCChargeZoneFront = WN_enDISPLAY_ON;
            }
        }
        if((RTE_E_OK == Rte_RWPC_FaultSts) || 
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_RWPC_FaultSts))
        {
            if(RWPC_FaultSts_temp == 0x1)
            {
                enWPCChargeZoneRear = WN_enDISPLAY_ON;
            }
        }
    }

    if ((configWireless == 1) || (configWireless == 2) || (configWireless == 3) || 
        (configWireless == 4) || (configWireless == 5) || (configWireless == 6))//R13 ADD Cfg 6
    {
        if ((RTE_E_OK == Rte_WPC_PhoneReminder) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_WPC_PhoneReminder))
        {
            //1.144
            if (WPC_PhoneReminder_temp == 0x1)
            {
                enWPCTakePhone = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enWPCChargeZone, enWPCChargeZone);
    WN_SET(WN_enWPCTakePhone, enWPCTakePhone);
    WN_SET(WN_enWPCChargeZoneFront, enWPCChargeZoneFront);
    WN_SET(WN_enWPCChargeZoneRear, enWPCChargeZoneRear);
    WN_SET(WN_enWPCChargeZoneRR, enWPCChargeZoneRR);
    WN_SET(WN_enWPCChargeZoneRL, enWPCChargeZoneRL);
}
void WN_4WDSystemDemotionProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common en4WDSystemDemotion = WN_enDISPLAY_OFF;

    //Byte30 Bit3-bit0
    uint8 configTransCase = 0;

    //TOD1 0x251 20ms
    uint8 FuncProtnSts_temp = 0;
    uint8 Rte_FuncProtnSts = RTE_E_INVALID;

    configTransCase = (uint8)WN_GetSingleConfig(WN_enCfg_TransCase);

    Rte_FuncProtnSts = WN_FuncProtnSts_SignalGet(&FuncProtnSts_temp);

    if ((configTransCase == 3) || (configTransCase == 5))
    {
        //1.146
        if ((RTE_E_OK == Rte_FuncProtnSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_FuncProtnSts))
        {
            if (FuncProtnSts_temp == 1)
            {
                en4WDSystemDemotion = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_en4WDSystemDemotion, en4WDSystemDemotion);
}
void WN_DriveSafetyTip1Process(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enDrvAwayCar = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDrvAwayCarStop = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDynBattCutOff = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;

    //BMS_FD10 0x2F6 100ms
    uint8 BMS_BattHeatRunaway_temp = 0;
    uint8 Rte_BMS_BattHeatRunaway = RTE_E_INVALID;
    //uint8 BMS_SafetyCnSts = 0;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);

    Rte_BMS_BattHeatRunaway = WN_BMS_BattHeatRunaway_SignalGet(&BMS_BattHeatRunaway_temp);
    //Com_ReceiveSignal(COM_SINGAL_RX_BMS_FD10_BMS_SAFETYCNSTS, &BMS_SafetyCnSts);

    if (((configFuel == 3) && 
        (((configElecPosition == 2) || (configElecPosition == 8)) || (configElecPosition == 5) || (configElecPosition == 6))) || //HEV+(P2 || 纵置P2)/PS/PS+P4
        ((configFuel == 4) && 
        (((configElecPosition == 2) || (configElecPosition == 8)) || (configElecPosition == 4) || 
        (configElecPosition == 5) || (configElecPosition == 6)))) //PHEV+(P2 || 纵置P2)/P2+P4/PS/PS+P4
    {
        //1.147
        if ((RTE_E_OK == Rte_BMS_BattHeatRunaway) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_BMS_BattHeatRunaway))
        {
            if (BMS_BattHeatRunaway_temp == 0x1)
            {
                enDrvAwayCarStop = WN_enDISPLAY_ON;
            }
            else if (BMS_BattHeatRunaway_temp == 0x2)
            {
                enDrvAwayCar = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
    }
    if (configFuel == 5)
    {
        //1.155
        if (0)
        {
            enDynBattCutOff = WN_enDISPLAY_ON;
        }
    }

    WN_SET(WN_enDrvAwayCar, enDrvAwayCar);
    WN_SET(WN_enDrvAwayCarStop, enDrvAwayCarStop);
    WN_SET(WN_enDynBattCutOff, enDynBattCutOff);
}
void WN_EngPumpFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enEngPumpFault = WN_enDISPLAY_OFF;

    //Byte51 Bit3-bit2
    uint8 configEngWaterPump = 0;

    //ECM11 0x2D3 100ms
    uint8 EWP_ERR_temp = 0;
    uint8 Rte_EWP_ERR = RTE_E_INVALID;

    configEngWaterPump = (uint8)WN_GetSingleConfig(WN_enCfg_EngWaterPump);

    Rte_EWP_ERR = WN_EWP_ERR_SignalGet(&EWP_ERR_temp);

    if (configEngWaterPump == 2)
    {
        //1.148
        if ((RTE_E_OK == Rte_EWP_ERR) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_EWP_ERR))
        {
            if (EWP_ERR_temp == 0x1)
            {
                enEngPumpFault = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enEngPumpFault, enEngPumpFault);
}
void WN_HeatingGunProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enHeatingPlugIn = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enBattTempLowCantStart = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enHeatingComplete = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enCantDriveBatt = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;

    //HCU_HC3 0x268 50ms
    uint8 HCU_BattLowTemWarn_temp = 0;
    uint8 Rte_HCU_BattLowTemWarn = RTE_E_INVALID;
    uint8 HCU_BattLowHeatSts_temp = 0;
    uint8 Rte_HCU_BattLowHeatSts = RTE_E_INVALID;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);

    Rte_HCU_BattLowTemWarn = WN_HCU_BattLowTemWarn_SignalGet(&HCU_BattLowTemWarn_temp);
    Rte_HCU_BattLowHeatSts = WN_HCU_BattLowHeatSts_SignalGet(&HCU_BattLowHeatSts_temp);

    if (((configFuel == 3) &&   //HEV+PS/PS+P4/P2+P4
        ((configElecPosition == 4) || (configElecPosition == 5) || (configElecPosition == 6))) ||
        ((configFuel == 4) &&   //PHEV+P2/P2+P4/PS/PS+P4/纵置P2
        ((configElecPosition == 2) || (configElecPosition == 4) || 
        (configElecPosition == 5) || (configElecPosition == 6) || (configElecPosition == 8))))
    {
        if ((RTE_E_OK == Rte_HCU_BattLowHeatSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_BattLowHeatSts))
        {
            //1.153
            if (HCU_BattLowHeatSts_temp == 0x1)
            {
                enHeatingComplete = WN_enDISPLAY_ON;
            }
        }
    }
    if ((configFuel == 4) &&    //PHEV+P2/纵置P2/P2+P4/PS/PS+P4
        (((configElecPosition == 2) || (configElecPosition == 8)) || 
         (configElecPosition == 4) ||
         (configElecPosition == 5) ||
         (configElecPosition == 6)))
    {
        //case 1/2/3/5
        if ((RTE_E_OK == Rte_HCU_BattLowTemWarn) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_BattLowTemWarn))
        {
            //1.152
            if (HCU_BattLowTemWarn_temp == 0x1)
            {
                enHeatingPlugIn = WN_enDISPLAY_ON;
            }
        }
    }
    if ((configFuel == 3) && ((configElecPosition == 5) || (configElecPosition == 6)))  //HEV+PS/PS+P4
    {
        //case4/6
        if ((RTE_E_OK == Rte_HCU_BattLowTemWarn) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_BattLowTemWarn))
        {
            //1.152
            if (HCU_BattLowTemWarn_temp == 0x1)
            {
                enBattTempLowCantStart = WN_enDISPLAY_ON;
            }
        }
    }
    if (((configFuel == 3) || (configFuel == 4)) && ((configElecPosition == 5) || (configElecPosition == 6)))
    {
        //case3/4/5/6
        if ((RTE_E_OK == Rte_HCU_BattLowTemWarn) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HCU_BattLowTemWarn))
        {
            //1.152
            if (HCU_BattLowTemWarn_temp == 0x2)
            {
                enCantDriveBatt = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enHeatingPlugIn, enHeatingPlugIn);
    WN_SET(WN_enBattTempLowCantStart, enBattTempLowCantStart);
    WN_SET(WN_enHeatingComplete, enHeatingComplete);
    WN_SET(WN_enCantDriveBatt, enCantDriveBatt);
}
void WN_VSGFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enVSGFault = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;

    //VSG1 0x2E1 100ms TBD
    uint8 VSG_OverVoltSts = 0;
    uint8 VSG_UnderVoltSts = 0;
    uint8 VSG_ShortCirctSts = 0;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);

    //Com_ReceiveSignal(COM_SINGAL_RX_VSG1_VSG_OVERVOLTSTS, &VSG_OverVoltSts);
    //Com_ReceiveSignal(COM_SINGAL_RX_VSG1_VSG_UNDERVOLTSTS, &VSG_UnderVoltSts);
    //Com_ReceiveSignal(COM_SINGAL_RX_VSG1_VSG_SHORTCIRCTSTS, &VSG_ShortCirctSts);

    if (configFuel == 5)
    {
        //1.154
        if (0)
        {
            if ((VSG_OverVoltSts == 0x1) ||
                (VSG_UnderVoltSts == 0x1) ||
                (VSG_ShortCirctSts == 0x1))
            {
                enVSGFault = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enVSGFault, enVSGFault);
}
void WN_ElecMachiFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enElecMachiFault = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;

    //MCU_FD1 0x0AE 10ms TBD
    uint8 MCU_SysErrSts = 0;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);

    //Com_ReceiveSignal(COM_SINGAL_RX_MCU_SYSERRSTS, &MCU_SysErrSts);

    if (configFuel == 5)
    {
        //1.156
        if (0)
        {
            if (MCU_SysErrSts == 0x1)
            {
                enElecMachiFault = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enElecMachiFault, enElecMachiFault);
}
void WN_DCDCFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enDCDCFault = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;

    //DCDC_FD1 0x12A 20ms TBD
    uint8 DCDC_FailSts = 0;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);

    //Com_ReceiveSignal(COM_SINGAL_RX_DCDC_FD1_DCDC_FAILSTS, &DCDC_FailSts);

    if (configFuel == 5)
    {
        //1.157
        if (0)
        {
            if ((DCDC_FailSts == 0x2) || (DCDC_FailSts == 0x3))
            {
                enDCDCFault = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enDCDCFault, enDCDCFault);
}
void WN_DynBattFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    //1.158 TBD
    WN_CFG_enSTATUS_Common enDynBattFault = WN_enDISPLAY_OFF;
    //Byte2 Bit7-bit4
    uint8 configFuel = 0;

    //BMS_FD10 0x2F6 100ms TBD
    uint8 BMS_SysErr = 0;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);

    if (configFuel == 5)
    {
        if (0)
        {
            if (BMS_SysErr == 1)
            {
                enDynBattFault = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enDynBattFault, enDynBattFault);
}
void WN_EParkFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enEParkFault = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte41 Bit3-bit2
    uint8 configEPark = 0;

    //E-Park1 0x24F 50ms TBD
    uint8 E_Park_FaultLmpSts = 0;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configEPark = (uint8)WN_GetSingleConfig(WN_enCfg_EPark);

    //Com_ReceiveSignal(COM_SINGAL_RX_E_PARK1_E_PARK_FAULTLMPSTS, &E_Park_FaultLmpSts);

    if ((configFuel == 5) && (configEPark == 1))
    {
        //1.159
        if (0)
        {
            if (E_Park_FaultLmpSts == 0x1)
            {
                enEParkFault = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enEParkFault, enEParkFault);
}
void WN_VCUFD3Process(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enDynSysFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRemoveChargeGun = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRemoveDischrgGun = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enShifterFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enShiftNotAllowEV = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enShiftPFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enShiftPStopEV = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enChargingShift = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enStepBrakeOutP = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enStepBrakeOutN = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enLVBattFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enHVBattSport = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enUnidentifyBatt = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enHVBattAir = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enECOValue = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPedalLimit = WN_enDISPLAY_OFF;
#if 0
    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte60 Bit1-bit0
    uint8 configV2VCharge = 0;
    //Byte63 Bit4-bit3
    uint8 configDisVChargeConnect = 0;

    //VCU_FD3 0x219 50ms TBD
    uint8 VCU_WordDispInfo = 0;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configV2VCharge = (uint8)WN_GetSingleConfig(WN_enCfg_V2VCharge);
    configDisVChargeConnect = (uint8)WN_GetSingleConfig(WN_enCfg_DisVChargeConnect);

    //Com_ReceiveSignal(COM_SINGAL_RX_VCU_FD3_VCU_WORDDISPINFO, &VCU_WordDispInfo);

    if (0)
    {
        if ((configFuel == 5) &&
            ((configV2VCharge == 0) || (configV2VCharge == 1)) &&
            ((configDisVChargeConnect == 0) || (configDisVChargeConnect == 1)))
        {
            //1.160
            if (VCU_WordDispInfo == 0x1)
            {
                enDynSysFault = WN_enDISPLAY_ON;
            }
            else if (VCU_WordDispInfo == 0x2)
            {
                if ((configV2VCharge == 0) && (configDisVChargeConnect == 0)) //无双向充电
                {
                    enRemoveChargeGun = WN_enDISPLAY_ON;
                }
                else //有双向充电
                {
                    enRemoveDischrgGun = WN_enDISPLAY_ON;
                }
            }
            else if (VCU_WordDispInfo == 0x4)
            {
                enShifterFault = WN_enDISPLAY_ON;
            }
            else if (VCU_WordDispInfo == 0x6)
            {
                enShiftPFault = WN_enDISPLAY_ON;
            }
            else if (VCU_WordDispInfo == 0x7)
            {
                enShiftPStopEV = WN_enDISPLAY_ON;
            }
            else if (VCU_WordDispInfo == 0x8)
            {
                enChargingShift = WN_enDISPLAY_ON;
            }
            else if (VCU_WordDispInfo == 0x9)
            {
                enStepBrakeOutP = WN_enDISPLAY_ON;
            }
            else if (VCU_WordDispInfo == 0xA)
            {
                enStepBrakeOutN = WN_enDISPLAY_ON;
            }
            else if (VCU_WordDispInfo == 0xB)
            {
                enLVBattFault = WN_enDISPLAY_ON;
            }
            else if (VCU_WordDispInfo == 0xC)
            {
                enHVBattSport = WN_enDISPLAY_ON;
            }
            else if (VCU_WordDispInfo == 0x13)
            {
                enUnidentifyBatt = WN_enDISPLAY_ON;
            }
            else if (VCU_WordDispInfo == 0xD)
            {
                enHVBattAir = WN_enDISPLAY_ON;
            }
            else if (VCU_WordDispInfo == 0xE)
            {
                enECOValue = WN_enDISPLAY_ON;
            }
            else if (VCU_WordDispInfo == 0xF)
            {
                enPedalLimit = WN_enDISPLAY_ON;
            }
            else if (VCU_WordDispInfo == 0x5)
            {
                enShiftNotAllowEV = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
    }
#endif
    WN_SET(WN_enDynSysFault, enDynSysFault);
    WN_SET(WN_enRemoveChargeGun, enRemoveChargeGun);
    WN_SET(WN_enRemoveDischrgGun, enRemoveDischrgGun);
    WN_SET(WN_enShifterFault, enShifterFault);
    WN_SET(WN_enShiftNotAllowEV, enShiftNotAllowEV);
    WN_SET(WN_enShiftPFault, enShiftPFault);
    WN_SET(WN_enShiftPStopEV, enShiftPStopEV);
    WN_SET(WN_enChargingShift, enChargingShift);
    WN_SET(WN_enStepBrakeOutP, enStepBrakeOutP);
    WN_SET(WN_enStepBrakeOutN, enStepBrakeOutN);
    WN_SET(WN_enLVBattFault, enLVBattFault);
    WN_SET(WN_enHVBattSport, enHVBattSport);
    WN_SET(WN_enUnidentifyBatt, enUnidentifyBatt);
    WN_SET(WN_enHVBattAir, enHVBattAir);
    WN_SET(WN_enECOValue, enECOValue);
    WN_SET(WN_enPedalLimit, enPedalLimit);
}
void WN_HeatManagerFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common HeatManagerFault = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;

    //VCU_FD4 0x2D6 100ms TBD
    uint8 VCU_CoolgCircFlt = 0;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    //Com_ReceiveSignal(COM_SINGAL_RX_VCU_FD4_VCU_COOLGCIRCFLT, &VCU_CoolgCircFlt);

    if (configFuel == 5)
    {
        //1.161
        if (0)
        {
            if (VCU_CoolgCircFlt == 0x1)
            {
                HeatManagerFault = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enHeatManagerFault, HeatManagerFault);
}
void WN_AGSFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enAGSFault = WN_enDISPLAY_OFF;

    //Byte42 Bit7-bit3
    uint8 configEngCtrolUnit = 0;
    //Byte51 Bit1-bit0
    uint8 configAirGrille = 0;

    //ECM3 0x371 100ms TBD
    uint8 AGS_Failure = 0;
    uint8 RTE_AGS_Failure = RTE_E_INVALID;
    //VCU_FD5 0x3AD 1000ms TBD
    //uint8 VCU_AgsFailrFlg = 0;

    configEngCtrolUnit = (uint8)WN_GetSingleConfig(WN_enCfg_EngCtrolUnit);
    configAirGrille = (uint8)WN_GetSingleConfig(WN_enCfg_AirGrille);
	
    RTE_AGS_Failure = WN_AGS_Failure_SignalGet(&AGS_Failure);

    if (((configEngCtrolUnit == 1) || (configEngCtrolUnit == 2) ||
         (configEngCtrolUnit == 3) || (configEngCtrolUnit == 4) ||
         (configEngCtrolUnit == 5) || (configEngCtrolUnit == 6) ||
         (configEngCtrolUnit == 7)) &&
        (configAirGrille == 1))
    {
        //1.165
        if ((RTE_E_OK == RTE_AGS_Failure) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == RTE_AGS_Failure))
        {
            if (AGS_Failure == 0x1)
            {
                enAGSFault = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enAGSFault, enAGSFault);
}
void WN_PPMIFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enPPMIFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSidePPMIErr = WN_enDISPLAY_OFF;

    //Byte81 Bit7-bit4
    uint8 configFrtSeatBelt = 0;
    //Byte81 Bit3-bit0
    uint8 configSidePPMI = 0;

    //PPMI1 0x35B 500ms TBD
    uint8 PPMIErrSts = 0;
    uint8 Rte_PPMIErrSts = RTE_E_INVALID;
    //PPMI1_p TBD
    uint8 PPMIRErrSts = 0;

    //Com_ReceiveSignal(COM_SINGAL_RX_PPMI1_PPMIERRSTS, &PPMIErrSts);
    configFrtSeatBelt = (uint8)WN_GetSingleConfig(WN_enCfg_DriverBelt);
    Rte_PPMIErrSts = WN_PPMIErrSts_SignalGet(&PPMIErrSts);

    if ((configFrtSeatBelt == 1) || (configFrtSeatBelt == 3))
    {
        //1.166
        if ((RTE_E_OK == Rte_PPMIErrSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_PPMIErrSts))
        {
            if (PPMIErrSts == 0x1)
            {
                enPPMIFault = WN_enDISPLAY_ON;
            }
        }
    }

    if ((configSidePPMI == 1) || (configSidePPMI == 3))
    {
        //1.238
        if (0)
        {
            if (PPMIRErrSts == 0x1)
            {
                enSidePPMIErr = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enPPMIFault, enPPMIFault);
    WN_SET(WN_enSidePPMIErr, enSidePPMIErr);
}
void WN_DischargingProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enDischargingV2L = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDischargingV2V = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enChargeGunConnect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enChargeDisGunConnect = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte60 Bit1-bit0
    uint8 configV2VCharge = 0;
    //Byte63 Bit4-bit3
    uint8 configDisVChargeConnect = 0;

    //OBC1 0x316 200ms
    uint8 OBC_ModSts_EV = 0;
    //OBC_FD2 0x31F 100ms TBD
    uint8 OBC_V2VSts = 0;
    uint8 OBC_DchrgconnectSts = 0;
    //BMS_FD10 0x2F6 100ms
    uint8 BMS_DCChrgConnect = 0; //TBD
    //OBC3 0x31F 100ms
    uint8 OBC_CCLineConnectSts = 0;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configV2VCharge = (uint8)WN_GetSingleConfig(WN_enCfg_V2VCharge);
    configDisVChargeConnect = (uint8)WN_GetSingleConfig(WN_enCfg_DisVChargeConnect);

    //Com_ReceiveSignal(COM_SINGAL_RX_OBC1_OBC_MODSTS, &OBC_ModSts);
    //Com_ReceiveSignal(COM_SINGAL_RX_OBC_FD2_OBC_V2VSTS, &OBC_V2VSts);

    if (configFuel == 5)
    {
        if ((configV2VCharge == 0) && (configDisVChargeConnect == 0))
        {
            if (0)
            {
                //1.164
                if ((BMS_DCChrgConnect == 0x1) ||
                    ((OBC_CCLineConnectSts == 0x1) || (OBC_CCLineConnectSts == 0x2)))
                {
                    enChargeGunConnect = WN_enDISPLAY_ON;
                }
            }
        }
        else if (((configV2VCharge == 1) && (configDisVChargeConnect == 0)) ||
                 ((configV2VCharge == 0) && (configDisVChargeConnect == 1)) ||
                 ((configV2VCharge == 1) && (configDisVChargeConnect == 1)))
        {
            if (0)
            {
                //1.164
                if ((BMS_DCChrgConnect == 0x1) ||
                    ((OBC_CCLineConnectSts == 0x1) || (OBC_CCLineConnectSts == 0x2)) ||
                    ((OBC_DchrgconnectSts == 0x1) || (OBC_DchrgconnectSts == 0x2)))
                {
                    enChargeDisGunConnect = WN_enDISPLAY_ON;
                }
            }
        }
        else
        {
        }
        //1.167
        if (0)
        {
            if ((configV2VCharge == 0) && (configDisVChargeConnect == 1))
            {
                if ((OBC_ModSts_EV == 0x0) && (OBC_V2VSts == 0x0))
                {
                    enDischargingV2L = WN_enDISPLAY_ON;
                }
            }
            else if ((configV2VCharge == 1) && (configDisVChargeConnect == 0))
            {
                if ((OBC_ModSts_EV == 0x0) && (OBC_V2VSts == 0x1))
                {
                    enDischargingV2V = WN_enDISPLAY_ON;
                }
            }
            else if ((configV2VCharge == 1) && (configDisVChargeConnect == 1))
            {
                if ((OBC_ModSts_EV == 0x0) && (OBC_V2VSts == 0x0))
                {
                    enDischargingV2L = WN_enDISPLAY_ON;
                }
                else if ((OBC_ModSts_EV == 0x0) && (OBC_V2VSts == 0x1))
                {
                    enDischargingV2V = WN_enDISPLAY_ON;
                }
                else
                {
                }
            }
            else
            {
            }
        }
    }

    WN_SET(WN_enChargeDisGunConnect, enChargeDisGunConnect);
    WN_SET(WN_enChargeGunConnect, enChargeGunConnect);
    WN_SET(WN_enDischargingV2L, enDischargingV2L);
    WN_SET(WN_enDischargingV2V, enDischargingV2V);
}
void WN_DriveSafetyTip2Process(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enDrvConcentrate = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDrvDrowsy = WN_enDISPLAY_OFF;

    //Byte16 Bit1-bit0
    uint8 configVoiceFacial = 0;
    //Byte68 Bit7-bit6
    uint8 configDMSType = 0;

    //DMS_FD1 0x24D 200ms
    uint8 DistrctnLvl_temp = 0;
    uint8 Rte_DistrctnLvl = RTE_E_INVALID;
    uint8 DrowsnsLvl_temp = 0;
    uint8 Rte_DrowsnsLvl = RTE_E_INVALID;

    configVoiceFacial = (uint8)WN_GetSingleConfig(WN_enCfg_VoiceFacial);
    configDMSType = (uint8)WN_GetSingleConfig(WN_enCfg_DMSType);

    Rte_DistrctnLvl = WN_DistrctnLvl_SignalGet(&DistrctnLvl_temp);
    Rte_DrowsnsLvl = WN_DrowsnsLvl_SignalGet(&DrowsnsLvl_temp);

    if (configVoiceFacial == 1)
    {
        if ((configDMSType == 0) || (configDMSType == 1))
        {
            //1.169
            if ((RTE_E_OK == Rte_DistrctnLvl) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_DistrctnLvl))
            {
                if (DistrctnLvl_temp == 0x3)
                {
                    enDrvConcentrate = WN_enDISPLAY_ON;
                }
            }
            //1.170
            if ((RTE_E_OK == Rte_DrowsnsLvl) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_DrowsnsLvl))
            {
                if (DrowsnsLvl_temp == 0x3)
                {
                    enDrvDrowsy = WN_enDISPLAY_ON;
                }
            }
        }
    }

    WN_SET(WN_enDrvConcentrate, enDrvConcentrate);
    WN_SET(WN_enDrvDrowsy, enDrvDrowsy);
}
void WN_FaceTipProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enFaceCancelled = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enFaceNoMatch = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enFaceSuccess = WN_enDISPLAY_OFF;

    //Byte16 Bit1-bit0
    uint8 configVoiceFacial = 0;
    //Byte68 Bit7-bit6
    uint8 configDMSType = 0;

    //DMS_FD1 0x24D 50ms
    uint8 DMSProc_temp = 0;
    uint8 DMSProcResult_temp = 0;
    uint8 DMSProcSts_temp = 0;
    uint8 Rte_DMS_FD1Sts = RTE_E_INVALID;

    configVoiceFacial = (uint8)WN_GetSingleConfig(WN_enCfg_VoiceFacial);
    configDMSType = (uint8)WN_GetSingleConfig(WN_enCfg_DMSType);

    Rte_DMS_FD1Sts = WN_DMSProc_SignalGet(&DMSProc_temp);
    Rte_DMS_FD1Sts = WN_DMSProcResult_SignalGet(&DMSProcResult_temp);
    Rte_DMS_FD1Sts = WN_DMSProcSts_SignalGet(&DMSProcSts_temp);

    if (configVoiceFacial == 1)
    {
        if ((configDMSType == 0) || (configDMSType == 1))
        {
            //1.172
            if ((RTE_E_OK == Rte_DMS_FD1Sts) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_DMS_FD1Sts))
            {
                if ((DMSProc_temp == 0x0) && (DMSProcSts_temp == 0x4))
                {
                    if (DMSProcResult_temp == 0xB)
                    {
                        enFaceCancelled = WN_enDISPLAY_ON;
                    }
                    else if (DMSProcResult_temp == 0x0)
                    {

                        enFaceNoMatch = WN_enDISPLAY_ON;
                    }
                    else if ((DMSProcResult_temp >= 0x1) && ((DMSProcResult_temp <= 0x6)))
                    {
                        enFaceSuccess = WN_enDISPLAY_ON;
                    }
                    else
                    {
                    }
                }
            }
        }
    }

    WN_SET(WN_enFaceCancelled, enFaceCancelled);
    WN_SET(WN_enFaceNoMatch, enFaceNoMatch);
    WN_SET(WN_enFaceSuccess, enFaceSuccess);
}
void WN_4LModeStopProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common en4LModeStop = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPleaseGearN = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common en4LModeEx = WN_enDISPLAY_OFF;

    //Byte25 Bit7-bit4
    uint8 configDrvModeOptionnal = 0;
    //Byte52 Bit7-bit2
    uint8 configDrvMode2 = 0;
    //Byte85 Bit7-bit4
    uint8 configDrvMode3 = 0;

    //ESP2 0x145 20ms
    //ESP_FD2 0x137 20ms
    uint8 Over_Spd_Warn_temp = 0;
    uint8 Shift_N_Warn_temp = 0;
    uint8 u4L_Warn_temp = 0;
    uint8 Rte_ESPSts = RTE_E_INVALID;
    uint8 Rte_ESP_FD2Sts = RTE_E_INVALID;
    uint8 Rte_u4L_Warn = RTE_E_INVALID;

    boolean VehCfgSts = FALSE;

    configDrvModeOptionnal = (uint8)WN_GetSingleConfig(WN_enCfg_DrvModeOptionnal);
    configDrvMode2 = (uint8)WN_GetSingleConfig(WN_enCfg_DrvMode2);
    configDrvMode3 = (uint8)WN_GetSingleConfig(WN_enCfg_DrvMode3);

    //Com_ReceiveSignal(COM_SINGAL_RX_ESP2_4L_WARN, &u4L_Warn);

    if (((configDrvModeOptionnal == 4) || \
         (configDrvModeOptionnal == 5) || \
         (configDrvModeOptionnal == 10) || \
         (configDrvModeOptionnal == 12) || \
         (configDrvModeOptionnal == 13)) && \
        (configDrvMode2 == 0) && \
        (configDrvMode3 == 0))
    {
        VehCfgSts = TRUE;
    }
    else if ((configDrvModeOptionnal == 0) && \
        ((configDrvMode2 == 9) || \
         (configDrvMode2 == 10) || \
         (configDrvMode2 == 12) || \
         (configDrvMode2 == 13) || \
         (configDrvMode2 == 14) || \
         (configDrvMode2 == 15)) && \
        (configDrvMode3 == 0))
    {
        VehCfgSts = TRUE;
    }
    else if ((configDrvModeOptionnal == 0) && (configDrvMode2 == 0) && \
             ((configDrvMode3 == 2) || (configDrvMode3 == 11) || \
             (configDrvMode3 == 12) || (configDrvMode3 == 13) || (configDrvMode3 == 14) || \
             (configDrvMode3 == 15) || (configDrvMode3 == 16) || (configDrvMode3 == 18) || \
             (configDrvMode3 == 19) || (configDrvMode3 == 29) || (configDrvMode3 == 30) || \
             (configDrvMode3 == 31) || (configDrvMode3 == 32) ||(configDrvMode3 == 38)))
    {
        VehCfgSts = TRUE;
    }
    else
    {
        /* do nothing */
    }

    if (VehCfgSts)
    {
        if (EolConfig_Trans_CANFD())
        {
            Rte_ESP_FD2Sts = WN_Over_Spd_Warn_FD_SignalGet(&Over_Spd_Warn_temp);
            Rte_ESP_FD2Sts = WN_Shift_N_Warn_FD_SignalGet(&Shift_N_Warn_temp);
		    Rte_u4L_Warn = WN_FourLWarn_FD_SignalGet(&u4L_Warn_temp);
        }
        else
        {
            Rte_ESPSts = WN_Over_Spd_Warn_SignalGet(&Over_Spd_Warn_temp);
            Rte_ESPSts = WN_Shift_N_Warn_SignalGet(&Shift_N_Warn_temp);
			Rte_u4L_Warn = WN_FourLWarn_SignalGet(&u4L_Warn_temp);
        }
        if ((RTE_E_OK == Rte_ESPSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_ESPSts) ||
            (RTE_E_OK == Rte_ESP_FD2Sts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_ESP_FD2Sts))
        {
            //1.173
            if (Over_Spd_Warn_temp == 0x1)
            {
                en4LModeStop = WN_enDISPLAY_ON;
            }
            //1.174
            if (Shift_N_Warn_temp == 0x1)
            {
                enPleaseGearN = WN_enDISPLAY_ON;
            }
        }
        if((RTE_E_OK == Rte_u4L_Warn) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_u4L_Warn))
        {
            //1.175
            if (u4L_Warn_temp == 0x1)
            {
                en4LModeEx = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_en4LModeStop, en4LModeStop);
    WN_SET(WN_enPleaseGearN, enPleaseGearN);
    WN_SET(WN_en4LModeEx, en4LModeEx);
}
void WN_4LModeEnterProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common en4LModeEn = WN_enDISPLAY_OFF;

    //Byte25 Bit3-bit2
    uint8 configORCruiseControl = 0;

    //BCM11 0x305 100ms TBD
    uint8 CCO_SwtShift_Warn_temp = 0;
    uint8 RTE_CCO_SwtShift_Warn = RTE_E_INVALID;

    configORCruiseControl = (uint8)WN_GetSingleConfig(WN_enCfg_ORCruiseControl);
    RTE_CCO_SwtShift_Warn = WN_CCO_SwtShift_Warn_SignalGet(&CCO_SwtShift_Warn_temp);

    //Com_ReceiveSignal(COM_SINGAL_RX_BCM11_CCO_SWTSHIFT_WARN, &CCO_SwtShift_Warn);

    if (configORCruiseControl == 1)
    {
        //1.176
        if ((RTE_E_OK == RTE_CCO_SwtShift_Warn) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == RTE_CCO_SwtShift_Warn))
        {
            if (CCO_SwtShift_Warn_temp == 0x1)
            {
                en4LModeEn = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_en4LModeEn, en4LModeEn);
}
void WN_4LModeSelectProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common en4LModeSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common en4HModeSelect = WN_enDISPLAY_OFF;

    //Byte25 Bit7-bit4
    uint8 configDrvModeOptionnal = 0;
    //Byte52 Bit7-bit2
    uint8 configDrvMode2 = 0;
    //Byte85 Bit7-Bit0
    uint8 configDrvMode3 = 0;

    //TBD
    uint8 DrivingModShift_Warn = 0;

    configDrvModeOptionnal = (uint8)WN_GetSingleConfig(WN_enCfg_DrvModeOptionnal);
    configDrvMode2 = (uint8)WN_GetSingleConfig(WN_enCfg_DrvMode2);
    configDrvMode3 = (uint8)WN_GetSingleConfig(WN_enCfg_DrvMode3);

    //Com_ReceiveSignal(COM_SINGAL_RX_TBD, &DrivingModShift_Warn);

    if (((configDrvModeOptionnal == 9) && (configDrvMode2 == 0) && (configDrvMode3 == 0)) ||
        ((configDrvModeOptionnal == 0) && (configDrvMode2 == 10) && (configDrvMode3 == 0)))
    {
        //1.177
        if (0)
        {
            if (DrivingModShift_Warn == 0x1)
            {
                en4LModeSelect = WN_enDISPLAY_ON;
            }
            else if (DrivingModShift_Warn == 0x2)
            {
                en4HModeSelect = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
    }

    WN_SET(WN_en4LModeSelect, en4LModeSelect);
    WN_SET(WN_en4HModeSelect, en4HModeSelect);
}
void WN_FuelTipProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enFuelPrepare = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enFuelPrepare_Sound = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enFuelStart = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;

    //ECM_PT6 0x290 100ms
    uint8 PressReliProgs_temp = 0;
    uint8 Rte_PressReliProgs = RTE_E_INVALID;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);

    Rte_PressReliProgs = WN_PressReliProgs_SignalGet(&PressReliProgs_temp);

	if (configFuel == 4)
	{
	    //1.178
	    if ((RTE_E_OK == Rte_PressReliProgs) ||
	        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_PressReliProgs))
	   	{
	   		if (PressReliProgs_temp == 0)
			{
				m_FuelPrepareSoundFlag = TRUE;
				m_PressReliProgsData = 0;
			}
	        else if ((PressReliProgs_temp >= 0x1) && (PressReliProgs_temp <= 0x63))
	        {
	        	if (m_FuelPrepareSoundFlag == TRUE)
	        	{
	            	enFuelPrepare_Sound = WN_enDISPLAY_ON;
	        	}
				else
				{
					enFuelPrepare = WN_enDISPLAY_ON;
				}
				m_PressReliProgsData = PressReliProgs_temp;
	        }
	        else if (PressReliProgs_temp == 0x64)
	        {
	            enFuelStart = WN_enDISPLAY_ON;
				m_FuelPrepareSoundFlag = FALSE;
				m_PressReliProgsData = 0;
	        }
	        else
	        {
	        	m_FuelPrepareSoundFlag = FALSE;
				m_PressReliProgsData = 0;
	        }	
       	}
		else
		{
			if ((m_FuelPrepareSoundFlag == TRUE) && (m_PressReliProgsData == 0))
			{
				//m_FuelPrepareSoundFlag = TRUE;
				//m_PressReliProgsData = 0;
			}
			else
			{
				m_FuelPrepareSoundFlag = FALSE;
				m_PressReliProgsData = 0;
			}
		}
    }

    WN_SET(WN_enFuelPrepare, enFuelPrepare);
    WN_SET(WN_enFuelStart, enFuelStart);
	WN_SET(WN_enFuelPrepare_Sound, enFuelPrepare_Sound);
}
void WN_PlsUpdateCallBattProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enTboxErr = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enEmergencyCallLimited = WN_enDISPLAY_OFF;

    //Byte24 Bit3-bit0
    uint8 configNetService = 0;
    //Byte121 Bit5-bit3
    uint8 configE_CallLimited = 0;
    //T_box3_FD3 0x3E9 1000ms
    uint8 T_Box_SysErrSts_temp = 0;
    uint8 Rte_T_Box_SysErrSts = RTE_E_INVALID;
    //T_box3_FD3 0x56 
    uint8 T_Box_SysErrSts_0x56 = 0;
    uint8 Rte_T_Box_SysErrSts_0x56 = RTE_E_INVALID;

    configNetService = (uint8)WN_GetSingleConfig(WN_enCfg_NetService);
	configE_CallLimited = (uint8)WN_GetSingleConfig(WN_enCfg_E_Call);

    Rte_T_Box_SysErrSts = WN_T_Box_SysErrSts_SignalGet(&T_Box_SysErrSts_temp);//0x3E9
    Rte_T_Box_SysErrSts_0x56 = WN_T_Box_SysErrSts_0x56_SignalGet(&T_Box_SysErrSts_0x56);//0x56

    //1.179
    if(configE_CallLimited == 4)
    {
        //case1
        if ((RTE_E_OK == Rte_T_Box_SysErrSts_0x56) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_T_Box_SysErrSts_0x56))
        {
            if (T_Box_SysErrSts_0x56 == 2)
            {
                enTboxErr = WN_enDISPLAY_ON;
            }
            else if(T_Box_SysErrSts_0x56 == 1)
            {
                enEmergencyCallLimited = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
    }
    else if((configE_CallLimited == 0) || (configE_CallLimited == 1) || (configE_CallLimited == 2) || (configE_CallLimited == 3))
    {
        if((configNetService == 11) || (configNetService == 12) || (configNetService == 13) || (configNetService == 14))
        {
            //case1
            if ((RTE_E_OK == Rte_T_Box_SysErrSts_0x56) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_T_Box_SysErrSts_0x56))
            {
                if (T_Box_SysErrSts_0x56 == 2)
                {
                    enTboxErr = WN_enDISPLAY_ON;
                }
                else if(T_Box_SysErrSts_0x56 == 1)
                {
                    enEmergencyCallLimited = WN_enDISPLAY_ON;
                }
                else
                {
                    /* do nothing */
                }
            }
        }
        else if((configNetService == 1) || (configNetService == 2) || (configNetService == 3) || (configNetService == 10))
        {
            //case2
            if ((RTE_E_OK == Rte_T_Box_SysErrSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_T_Box_SysErrSts))
            {
                if (T_Box_SysErrSts_temp == 2)
                {
                    enTboxErr = WN_enDISPLAY_ON;
                }
                else if(T_Box_SysErrSts_temp == 1)
                {
                    enEmergencyCallLimited = WN_enDISPLAY_ON;
                }
                else
                {
                    /* do nothing */
                }
            }
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }

    WN_SET(WN_enTboxErr, enTboxErr);
    WN_SET(WN_enEmergencyCallLimited, enEmergencyCallLimited);
}
void WN_TSMFuncProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    //Byte26 Bit4-bit0
    //uint8 configABS_EBD = 0;//R15 delete
    //Byte80 Bit1-bit0
    uint8 configTSMFunc = 0;
    //ESP1 0x149 20ms
    //ESP_FD2 0x137 20ms
    uint8 TSM_Trailer_temp = 0;
    uint8 Rte_TSM_Trailer = RTE_E_INVALID;

    //configABS_EBD = (uint8)WN_GetSingleConfig(WN_enCfg_ABS_EBD);
    configTSMFunc = (uint8)WN_GetSingleConfig(WN_enCfg_TSMFunc);

    //1.180
    if (configTSMFunc == 1)
    {
        if (EolConfig_Trans_CANFD())
        {
            Rte_TSM_Trailer = WN_TSM_Trailer_FD_SignalGet(&TSM_Trailer_temp);
        }
        else
        {
            Rte_TSM_Trailer = WN_TSM_Trailer_SignalGet(&TSM_Trailer_temp);
        }

        if (KL15On_DelayEndSts)
        {
            //1.180
            if ((RTE_E_OK == Rte_TSM_Trailer) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_TSM_Trailer))
            {
                if (m_TSM_TrailerSignalInit)
                {
                    if ((m_PreTSM_Trailer == 0) && (TSM_Trailer_temp == 0x1))
                    {
                        m_enTmsTrailerOn = WN_enDISPLAY_ON;
                        m_enTmsTrailerOff = WN_enDISPLAY_OFF;
                    }
                    if ((m_PreTSM_Trailer == 1) && (TSM_Trailer_temp == 0x0))
                    {
                        m_enTmsTrailerOff = WN_enDISPLAY_ON;
                        m_enTmsTrailerOn = WN_enDISPLAY_OFF;
                    }
                    m_PreTSM_Trailer = TSM_Trailer_temp;
                }
                else
                {
                    m_PreTSM_Trailer = TSM_Trailer_temp;
                    m_TSM_TrailerSignalInit = TRUE;
                }
            }
            else
            {
                m_enTmsTrailerOn = WN_enDISPLAY_OFF;
                m_enTmsTrailerOff = WN_enDISPLAY_OFF;
                m_PreTSM_Trailer = 0;
                m_TSM_TrailerSignalInit = FALSE;
            }
        }
        else
        {
            m_enTmsTrailerOn = WN_enDISPLAY_OFF;
            m_enTmsTrailerOff = WN_enDISPLAY_OFF;
            m_PreTSM_Trailer = 0;
            m_TSM_TrailerSignalInit = FALSE;
        }
    }
    
    WN_SET(WN_enTmsTrailerOn, m_enTmsTrailerOn);
    WN_SET(WN_enTmsTrailerOff, m_enTmsTrailerOff);
}
void WN_EngVinMismatchProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enEngVinMismatch = WN_enDISPLAY_OFF;

    //shared value from ODO module
    uint8 EngVinMismatch = 0;
    s_OdoRteGetParament_t ODODataTmp = {0};

    WN_OdoRteGetParament_APIGet(&ODODataTmp);
    EngVinMismatch = ODODataTmp.VinCheckFlag_u8;

    //1.182
    if (EngVinMismatch == 1)
    {
        enEngVinMismatch = WN_enDISPLAY_ON;
    }

    WN_SET(WN_enEngVinMismatch, enEngVinMismatch);
}
void WN_AutoEmergencyBrakeProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enAEBSafeDistance = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAEBFCWWarning = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAEBTrigV = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAEBTrigP = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAEBESPOff = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAEBFCWTrailer = WN_enDISPLAY_OFF;

    //Byte10 Bit3-bit0
    uint8 configForwardCollision = 0;
    //Byte46 Bit7-bit5
    uint8 configAEBJunctionAssist = 0;

    //AEB_FD2 0x227 50ms
    uint8 FCW_Warn_temp = 0;
    uint8 AEB_VehTrig_temp = 0;
    uint8 AEB_PedTrig_temp = 0;
    uint8 FCW_AEB_VehFctSts_temp = 0;
    uint8 Rte_SG_AEB3_AEB_FD2_Tmp = RTE_E_INVALID;

    configForwardCollision = (uint8)WN_GetSingleConfig(WN_enCfg_FCWAEB);
    configAEBJunctionAssist = (uint8)WN_GetSingleConfig(WN_enCfg_AEBJunctionAssist);

    Rte_SG_AEB3_AEB_FD2_Tmp = WN_FCW_Warn_SignalGet(&FCW_Warn_temp);
    //Com_ReceiveSignal(COM_SINGAL_RX_IFC_FD2_CAMERABLOCKAGESTS, &CameraBlockageSts);
    Rte_SG_AEB3_AEB_FD2_Tmp = WN_AEB_VehTrig_SignalGet(&AEB_VehTrig_temp);
    Rte_SG_AEB3_AEB_FD2_Tmp = WN_AEB_PedTrig_SignalGet(&AEB_PedTrig_temp);
    Rte_SG_AEB3_AEB_FD2_Tmp = WN_FCW_AEB_VehFctSts_SignalGet(&FCW_AEB_VehFctSts_temp);

    if ((RTE_E_OK == Rte_SG_AEB3_AEB_FD2_Tmp) ||
        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_AEB3_AEB_FD2_Tmp))
    {
        if ((configForwardCollision == 1) || (configForwardCollision == 2) || (configForwardCollision == 3) ||
            (configForwardCollision == 4) || (configForwardCollision == 5))
        {
            //1.185
            if (FCW_Warn_temp == 0x1)
            {
                enAEBSafeDistance = WN_enDISPLAY_ON;
            }
            //1.184
            else if (FCW_Warn_temp == 0x2)
            {
                enAEBFCWWarning = WN_enDISPLAY_ON;
            }
            else
            {
            }
            //1.186
            if (AEB_VehTrig_temp == 0x1)
            {
                enAEBTrigV = WN_enDISPLAY_ON;
            }
            //1.192
            if (FCW_AEB_VehFctSts_temp == 0x2)
            {
                enAEBFCWTrailer = WN_enDISPLAY_ON;
            }
            //1.183
            else if (FCW_AEB_VehFctSts_temp == 0x3)
            {
                enAEBESPOff = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
        if (configAEBJunctionAssist == 1)
        {
            //1.183
            if (FCW_AEB_VehFctSts_temp == 0x3)
            {
                enAEBESPOff = WN_enDISPLAY_ON;
            }
        }
        if ((configForwardCollision == 4) || (configForwardCollision == 5))
        {
            //1.187
            if (AEB_PedTrig_temp == 0x1)
            {
                enAEBTrigP = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enAEBSafeDistance, enAEBSafeDistance);
    WN_SET(WN_enAEBFCWWarning, enAEBFCWWarning);
    WN_SET(WN_enAEBTrigV, enAEBTrigV);
    WN_SET(WN_enAEBTrigP, enAEBTrigP);
    WN_SET(WN_enAEBESPOff, enAEBESPOff);
    WN_SET(WN_enAEBFCWTrailer, enAEBFCWTrailer);
}
void WN_InterAssistSystemProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enIASTrigV = WN_enDISPLAY_OFF;

    //Byte46 Bit7-bit5
    uint8 configAEBJunctionAssist = 0;

    //AEB_FD2 0x227 50ms
    uint8 AEB_JABrkTrig_temp = 0;
    uint8 Rte_SG_AEB3_AEB_FD2_Tmp = RTE_E_INVALID;

    configAEBJunctionAssist = (uint8)WN_GetSingleConfig(WN_enCfg_AEBJunctionAssist);

    Rte_SG_AEB3_AEB_FD2_Tmp = WN_AEB_JABrkTrig_SignalGet(&AEB_JABrkTrig_temp);

    if (configAEBJunctionAssist == 1)
    {
        if ((RTE_E_OK == Rte_SG_AEB3_AEB_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_AEB3_AEB_FD2_Tmp))
        {
            //1.188
            if (AEB_JABrkTrig_temp == 0x1)
            {
                enIASTrigV = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enIASTrigV, enIASTrigV);
}
void WN_FCTAWarningProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enFCTAUnavai = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enFCTABrakePlease = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enFCTABrakeActive = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enFCTSDectectLimit = WN_enDISPLAY_OFF;

    //Byte45 Bit4-bit2
    uint8 configFCWB = 0;

    //CR_FD1 0x15E 20ms
    uint8 FCTA_Warn_temp = 0;
    uint8 Rte_FCTA_Warn = RTE_E_INVALID;
    uint8 FCTBTrig_temp = 0;
    uint8 Rte_FCTBTrig = RTE_E_INVALID;
    uint8 CR_BliSts_temp = 0;
    uint8 Rte_CR_BliSts = RTE_E_INVALID;
    uint8 FCTA_B_FuncSts_temp = 0;
    uint8 Rte_FCTA_B_FuncSts = RTE_E_INVALID;

    configFCWB = (uint8)WN_GetSingleConfig(WN_enCfg_FCWB);

    Rte_FCTA_Warn = WN_FCTA_Warn_SignalGet(&FCTA_Warn_temp);
    Rte_FCTBTrig = WN_FCTBTrig_SignalGet(&FCTBTrig_temp);
    Rte_CR_BliSts = WN_CR_BliSts_SignalGet(&CR_BliSts_temp);
    Rte_FCTA_B_FuncSts = WN_FCTA_B_FuncSts_SignalGet(&FCTA_B_FuncSts_temp);

    if ((configFCWB == 1) || (configFCWB == 2))
    {
        if ((RTE_E_OK == Rte_FCTA_Warn) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_FCTA_Warn))
        {
            //1.189
            if (FCTA_Warn_temp == 0x1)
            {
                enFCTABrakePlease = WN_enDISPLAY_ON;
            }
        }
        if ((RTE_E_OK == Rte_FCTBTrig) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_FCTBTrig))
        {
            //1.190
            if (FCTBTrig_temp == 0x1)
            {
                enFCTABrakeActive = WN_enDISPLAY_ON;
            }
        }
        if ((RTE_E_OK == Rte_CR_BliSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_CR_BliSts))
        {
            //1.193
            if (CR_BliSts_temp == 0x1)
            {
                enFCTSDectectLimit = WN_enDISPLAY_ON;
            }
        }
        if ((RTE_E_OK == Rte_FCTA_B_FuncSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_FCTA_B_FuncSts))
        {
            //1.194
            if ((FCTA_B_FuncSts_temp == 0x1) || (FCTA_B_FuncSts_temp == 0x2))
            {
                enFCTAUnavai = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enFCTAUnavai, enFCTAUnavai);
    WN_SET(WN_enFCTABrakePlease, enFCTABrakePlease);
    WN_SET(WN_enFCTABrakeActive, enFCTABrakeActive);
    WN_SET(WN_enFCTSDectectLimit, enFCTSDectectLimit);
}
void WN_RearSideAssistSystemProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enRSDSRCWWarning = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRSDSTrailer = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRSDSRLBStart = WN_enDISPLAY_OFF;

    //Byte17 Bit1-bit0
    uint8 configRearCollision = 0;
    //Byte14 Bit7-bit6
    uint8 configLaneChangeAssist = 0;
    //Byte20 Bit7-bit5
    uint8 configPASCTA = 0;

    //RSDS_FD1 0x16F 20ms
    uint8 RSDS_RCW_Trigger_temp = 0;
    uint8 Rte_RSDS_RCW_Trigger = RTE_E_INVALID;
    uint8 RSDS_TrailerSts_temp = 0;
    uint8 Rte_RSDS_TrailerSts = RTE_E_INVALID;
    uint8 RSDS_BrkgTrig_temp = 0;
    uint8 Rte_RSDS_BrkgTrig = RTE_E_INVALID;

    configRearCollision = (uint8)WN_GetSingleConfig(WN_enCfg_RearCollision);
    configLaneChangeAssist = (uint8)WN_GetSingleConfig(WN_enCfg_LaneChangeAssist);
    configPASCTA = (uint8)WN_GetSingleConfig(WN_enCfg_PASCTA);

    Rte_RSDS_RCW_Trigger = WN_RSDS_RCW_Trigger_SignalGet(&RSDS_RCW_Trigger_temp);
    Rte_RSDS_TrailerSts = WN_RSDS_TrailerSts_SignalGet(&RSDS_TrailerSts_temp);
    Rte_RSDS_BrkgTrig = WN_RSDS_BrkgTrig_SignalGet(&RSDS_BrkgTrig_temp);

    if (configLaneChangeAssist == 1)
    {
        if ((RTE_E_OK == Rte_RSDS_TrailerSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_RSDS_TrailerSts))
        {
            //1.195
            if (RSDS_TrailerSts_temp == 0x1)
            {
                enRSDSTrailer = WN_enDISPLAY_ON;
            }
        }
    }
    if ((configPASCTA == 4) || (configPASCTA == 5))
    {
        if ((RTE_E_OK == Rte_RSDS_BrkgTrig) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_RSDS_BrkgTrig))
        {
            //1.196
            if (RSDS_BrkgTrig_temp == 0x1)
            {
                enRSDSRLBStart = WN_enDISPLAY_ON;
            }
        }
    }
    if (configRearCollision == 1)
    {
        if ((RTE_E_OK == Rte_RSDS_RCW_Trigger) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_RSDS_RCW_Trigger))
        {
            //1.197
            if ((RSDS_RCW_Trigger_temp == 0x1) || (RSDS_RCW_Trigger_temp == 0x2))
            {
                enRSDSRCWWarning = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enRSDSRCWWarning, enRSDSRCWWarning);
    WN_SET(WN_enRSDSTrailer, enRSDSTrailer);
    WN_SET(WN_enRSDSRLBStart, enRSDSRLBStart);
}
void WN_TrafficSignFaultProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enTrafficSignFault = WN_enDISPLAY_OFF;

    //Byte2 Bit3-bit0
    uint8 configTSR = 0;

    //IFC_FD3 0x2CF 100ms
    uint8 TSRSts_temp = 0;
    uint8 Rte_TSRSts = RTE_E_INVALID;

    configTSR = (uint8)WN_GetSingleConfig(WN_enCfg_TrafficSign);

    Rte_TSRSts = WN_TSRSts_SignalGet(&TSRSts_temp);

    if ((configTSR == 1) || (configTSR == 2) || (configTSR == 3) || (configTSR == 4))//R13 ADD Cfg4
    {
        //1.211
        if ((RTE_E_OK == Rte_TSRSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_TSRSts))
        {
            if (TSRSts_temp == 0x4)
            {
                enTrafficSignFault = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enTrafficSignFault, enTrafficSignFault);
}
void WN_IntelligentForwardSystemProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enIFCSCalibrating = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enIFCSDectectLimited = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enIFCLKAFunLimited = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enIFCHoldWheel_1Hz = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enIFCHoldWheel_2Hz = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enIFCHoldWheel_3Hz = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enIFCHoldWheel_4Hz = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enIFCAESTrig = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enIFCAESFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enIFCESSTrig = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enIFCESSFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enIFCTakeOver = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enIFCExitPlsControl = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPlsCtrlWheel = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enIFCLKAFuncOn = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSmartCruiseEmerBrake = WN_enDISPLAY_OFF;

    //Byte12 Bit3-bit0
    uint8 configLDWLKA = 0;
    //Byte45 Bit1-bit0
    uint8 configEvasiveSteering = 0;
    //Byte46 Bit4-bit3
    uint8 configEmergencySteering = 0;
    //Byte103 bit7-bit5
    uint8 configTFC = 0;

    //IFC_FD2 0x23D 50ms
    uint8 IFCCalibrationSts_temp = 0;
    uint8 CameraBlockageSts_temp = 0;
    uint8 LSSErrSts_temp = 0;
    uint8 IFC_Handsoffwarn_temp = 0;
    uint8 ESSSts_temp = 0;
    uint8 ESSErrSts_temp = 0;
    uint8 ESSintervention_temp = 0;
    uint8 AESSts_temp = 0;
    uint8 AESErrSts_temp = 0;
    uint8 AESintervention_temp = 0;
    uint8 LCKStsIndcr_temp = 0;
    uint8 ELKMainState_temp = 0;
    uint8 Rte_SG_IFC4_IFC_FD2_Tmp = RTE_E_INVALID;
    uint8 Rte_SG_IFC3_IFC_FD2_Tmp = RTE_E_INVALID;
    uint8 IntelligentEvaActSts_temp = 0;

    configLDWLKA = (uint8)WN_GetSingleConfig(WN_enCfg_LDWLKA);
    configEvasiveSteering = (uint8)WN_GetSingleConfig(WN_enCfg_EvasiveSteering);
    configEmergencySteering = (uint8)WN_GetSingleConfig(WN_enCfg_EmergencySteering);
    configTFC = (uint8)WN_GetSingleConfig(WN_encfg_TFC);

    Rte_SG_IFC4_IFC_FD2_Tmp = WN_IntelligentEvaActSts_SignalGet(&IntelligentEvaActSts_temp);
    Rte_SG_IFC4_IFC_FD2_Tmp = WN_IFCCalibrationSts_SignalGet(&IFCCalibrationSts_temp);
    Rte_SG_IFC4_IFC_FD2_Tmp = WN_CameraBlockageSts_SignalGet(&CameraBlockageSts_temp);
    Rte_SG_IFC4_IFC_FD2_Tmp = WN_LSSErrSts_SignalGet(&LSSErrSts_temp);
    Rte_SG_IFC4_IFC_FD2_Tmp = WN_IFC_Handsoffwarn_SignalGet(&IFC_Handsoffwarn_temp);
    Rte_SG_IFC3_IFC_FD2_Tmp = WN_AESSts_SignalGet(&AESSts_temp);
    Rte_SG_IFC3_IFC_FD2_Tmp = WN_AESErrSts_SignalGet(&AESErrSts_temp);
    Rte_SG_IFC4_IFC_FD2_Tmp = WN_AESintervention_SignalGet(&AESintervention_temp);
    Rte_SG_IFC3_IFC_FD2_Tmp = WN_ESSSts_SignalGet(&ESSSts_temp);
    Rte_SG_IFC3_IFC_FD2_Tmp = WN_ESSErrSts_SignalGet(&ESSErrSts_temp);
    Rte_SG_IFC4_IFC_FD2_Tmp = WN_ESSintervention_SignalGet(&ESSintervention_temp);
    Rte_SG_IFC4_IFC_FD2_Tmp = WN_LCKStsIndcr_SignalGet(&LCKStsIndcr_temp);
    Rte_SG_IFC4_IFC_FD2_Tmp = WN_ELKMainState_SignalGet(&ELKMainState_temp);

    if ((configLDWLKA == 1) || (configLDWLKA == 2) || (configLDWLKA == 3) || (configLDWLKA == 4) || \
        (configLDWLKA == 5) || (configLDWLKA == 6) || (configLDWLKA == 7) || (configLDWLKA == 8) || \
        (configLDWLKA == 9) || (configLDWLKA == 10) || (configLDWLKA == 11) || (configLDWLKA == 12) || (configLDWLKA == 13))//R14 change
    {
        if((configTFC == 0) || (configTFC == 1) || (configTFC == 2) || (configTFC == 3) || (configTFC == 4))
        {
            if((RTE_E_OK == Rte_SG_IFC4_IFC_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_IFC4_IFC_FD2_Tmp))
            {
                if((0x1 == IntelligentEvaActSts_temp) || (0x2 == IntelligentEvaActSts_temp))
                {
                    //安全避让
                }
            }
            else
            {}
        }

        if ((RTE_E_OK == Rte_SG_IFC4_IFC_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_IFC4_IFC_FD2_Tmp))
        {
            //1.207
            if (LSSErrSts_temp == 4)
            {
                enIFCLKAFunLimited = WN_enDISPLAY_ON;
            }
        }
    
        if ((RTE_E_OK == Rte_SG_IFC4_IFC_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_IFC4_IFC_FD2_Tmp))
        {
            //1.208
            if (CameraBlockageSts_temp == 0x1)
            {
                enIFCSDectectLimited = WN_enDISPLAY_ON;
            }
            //1.209
            if (IFCCalibrationSts_temp == 0x1)
            {
                enIFCSCalibrating = WN_enDISPLAY_ON;
            }
            //1.210
            if (IFC_Handsoffwarn_temp == 0x1)
            {
                enIFCHoldWheel_1Hz = WN_enDISPLAY_ON;
            }
            else if (IFC_Handsoffwarn_temp == 0x2)
            {
                enIFCHoldWheel_2Hz = WN_enDISPLAY_ON;
            }
            else if (IFC_Handsoffwarn_temp == 0x3)
            {
                enIFCHoldWheel_3Hz = WN_enDISPLAY_ON;
            }
            else if (IFC_Handsoffwarn_temp == 0x4)
            {
                enIFCHoldWheel_4Hz = WN_enDISPLAY_ON;
            }
            else if (IFC_Handsoffwarn_temp == 0x5)
            {
                enIFCTakeOver = WN_enDISPLAY_ON;
            }
            else if (IFC_Handsoffwarn_temp == 0x6)
            {
                enPlsCtrlWheel = WN_enDISPLAY_ON;
            }
            else if(IFC_Handsoffwarn_temp == 0x7)
            {
                enSmartCruiseEmerBrake = WN_enDISPLAY_ON;
            }
            else
            {
            }
            //1.218
            if (LCKStsIndcr_temp == 0x2)
            {
                enIFCExitPlsControl = WN_enDISPLAY_ON;
            }
        }    
        //1.269
        if ((RTE_E_OK == Rte_SG_IFC4_IFC_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_IFC4_IFC_FD2_Tmp))
        {
            if((ELKMainState_temp == 3) || (ELKMainState_temp == 4) || (ELKMainState_temp == 5))
            {
                enIFCLKAFuncOn = WN_enDISPLAY_ON;
            }
        }
    }
    if (configEvasiveSteering == 1)
    {
        if (((RTE_E_OK == Rte_SG_IFC4_IFC_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_IFC4_IFC_FD2_Tmp)) &&
            ((RTE_E_OK == Rte_SG_IFC3_IFC_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_IFC3_IFC_FD2_Tmp)))
        {
            //1.212
            if ((AESSts_temp == 0x1) && (AESErrSts_temp == 0x1))
            {
                enIFCAESFault = WN_enDISPLAY_ON;
            }
            if ((AESSts_temp == 0x1) && (AESErrSts_temp == 0x0) &&
                ((AESintervention_temp == 0x1) || (AESintervention_temp == 0x2)))
            {
                enIFCAESTrig = WN_enDISPLAY_ON;
            }
        }
    }
    if (configEmergencySteering == 1)
    {
        if (((RTE_E_OK == Rte_SG_IFC4_IFC_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_IFC4_IFC_FD2_Tmp)) &&
            ((RTE_E_OK == Rte_SG_IFC3_IFC_FD2_Tmp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_IFC3_IFC_FD2_Tmp)))
        {
            //1.213
            if ((ESSSts_temp == 0x1) && (ESSErrSts_temp == 0x1))
            {
                enIFCESSFault = WN_enDISPLAY_ON;
            }
            if ((ESSSts_temp == 0x1) && (ESSErrSts_temp == 0x0) &&
                ((ESSintervention_temp == 0x1) || (ESSintervention_temp == 0x2)))
            {
                enIFCESSTrig = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enIFCSCalibrating, enIFCSCalibrating);
    WN_SET(WN_enIFCSDectectLimited, enIFCSDectectLimited);
    WN_SET(WN_enIFCLKAFunLimited, enIFCLKAFunLimited);
    WN_SET(WN_enIFCHoldWheel_1Hz, enIFCHoldWheel_1Hz);
    WN_SET(WN_enIFCHoldWheel_2Hz, enIFCHoldWheel_2Hz);
    WN_SET(WN_enIFCHoldWheel_3Hz, enIFCHoldWheel_3Hz);
    WN_SET(WN_enIFCHoldWheel_4Hz, enIFCHoldWheel_4Hz);
    WN_SET(WN_enIFCAESTrig, enIFCAESTrig);
    WN_SET(WN_enIFCAESFault, enIFCAESFault);
    WN_SET(WN_enIFCESSTrig, enIFCESSTrig);
    WN_SET(WN_enIFCESSFault, enIFCESSFault);
    WN_SET(WN_enIFCTakeOver, enIFCTakeOver);
    WN_SET(WN_enIFCExitPlsControl, enIFCExitPlsControl);
    WN_SET(WN_enPlsCtrlWheel, enPlsCtrlWheel);
    WN_SET(WN_enIFCLKAFuncOn, enIFCLKAFuncOn);
    WN_SET(WN_enSmartCruiseouteEmergencyBrake, enSmartCruiseEmerBrake);
}

void WN_ARHUDStsProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enARHUDFault = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enARHUDOverheat = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enARHUDLightLimit = WN_enDISPLAY_OFF;

    //Byte12 Bit3-bit0
    uint8 configARHUD = 0;

    //HUD1 0x31E 200ms TBD
    uint8 AR_HUD_fault = 0;

    configARHUD = (uint8)WN_GetSingleConfig(WN_enCfg_ARHUD);

    if (configARHUD == 2)
    {
        //1.217
        if (0)
        {
            if (AR_HUD_fault == 0x1)
            {
                enARHUDFault = WN_enDISPLAY_ON;
            }
            else if (AR_HUD_fault == 0x2)
            {
                enARHUDLightLimit = WN_enDISPLAY_ON;
            }
            else if (AR_HUD_fault == 0x3)
            {
                enARHUDOverheat = WN_enDISPLAY_ON;
            }
            else
            {}
        }
    }

    WN_SET(WN_enARHUDFault, enARHUDFault);
    WN_SET(WN_enARHUDOverheat, enARHUDOverheat);
    WN_SET(WN_enARHUDLightLimit, enARHUDLightLimit);
}

void WN_SuspensionFuncProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enSuspensionLimit = WN_enDISPLAY_OFF;

    //Byte56 Bit7-bit5
    uint8 configDamper = 0;

    //EDC1 0x2D9 100ms TBD
    uint8 WarnLmpReq_temp = 0;
    uint8 RTE_WarnLmpReq = RTE_E_INVALID;
    boolean SuspensionFuncEnable_Flag = FALSE;

/* if the items without this warning function, will not enter the signal missing processing logic to trigger the alarm */
#ifdef GWM_V35_PROJECT_TYPE_P03
    SuspensionFuncEnable_Flag = TRUE;
#elif defined GWM_V35_PROJECT_TYPE_D01
    SuspensionFuncEnable_Flag = TRUE;
#elif defined GWM_V35_PROJECT_TYPE_D02
    SuspensionFuncEnable_Flag = TRUE;
#elif defined GWM_V35_PROJECT_TYPE_D03
    SuspensionFuncEnable_Flag = TRUE;
#else
    SuspensionFuncEnable_Flag = FALSE;
#endif

    if(TRUE == SuspensionFuncEnable_Flag)
    {
        configDamper = (uint8)WN_GetSingleConfig(WN_enCfg_Damper);
        RTE_WarnLmpReq = WN_WarnLmpReq_SignalGet(&WarnLmpReq_temp);

        if (configDamper == 2)
        {
            //1.237
            if ((RTE_E_OK == RTE_WarnLmpReq) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == RTE_WarnLmpReq))
            {
                if (WarnLmpReq_temp == 0x1)
                {
                    enSuspensionLimit = WN_enDISPLAY_ON;
                }
            }
            else
            {
                enSuspensionLimit = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enSuspensionLimit, enSuspensionLimit);
}

void WN_FrontTireProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enFrontTireTurnRight = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enFrontTireTurnLeft = WN_enDISPLAY_OFF;

    //Byte80 Bit3-bit2
    uint8 configFrontWheelBack = 0;

    //EPS1 0x168 20ms
    //EPS_FD1 0x147 20ms
    uint8 SteerCorrnRmn_temp = 0;
    uint8 Rte_SteerCorrnRmn = RTE_E_INVALID;

    configFrontWheelBack = (uint8)WN_GetSingleConfig(WN_enCfg_FrontWheelBack);

    if (configFrontWheelBack == 1)
    {
        if(EolConfig_Trans_CANFD())
        {
            Rte_SteerCorrnRmn = WN_SteerCorrnRmn_FD_SignalGet(&SteerCorrnRmn_temp);
        }
        else
        {
            Rte_SteerCorrnRmn = WN_SteerCorrnRmn_SignalGet(&SteerCorrnRmn_temp);
        }
        //1.235
        if (m_PowerModeStatus == WN_enRUN)
        {
            if ((RTE_E_OK == Rte_SteerCorrnRmn) ||
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SteerCorrnRmn))
            {
                
                if (SteerCorrnRmn_temp == 0x1)
                {
                    if(TRUE != m_FrontTireAlignFinish_Flag)
                    {
                        m_enFrontTireAlignFinish = WN_enDISPLAY_ON;
                    }
                }
                else if (SteerCorrnRmn_temp == 0x2)
                {
                    enFrontTireTurnRight = WN_enDISPLAY_ON;
                    m_enFrontTireAlignFinish = WN_enDISPLAY_OFF;
                    m_FrontTireAlignFinish_Flag = FALSE;
                }
                else if (SteerCorrnRmn_temp == 0x3)
                {
                    enFrontTireTurnLeft = WN_enDISPLAY_ON;
                    m_enFrontTireAlignFinish = WN_enDISPLAY_OFF;
                    m_FrontTireAlignFinish_Flag = FALSE;
                }
                else
                {
                    m_enFrontTireAlignFinish = WN_enDISPLAY_OFF;
                    m_FrontTireAlignFinish_Flag = FALSE;
                }
            }
            else
            {
                m_enFrontTireAlignFinish = WN_enDISPLAY_OFF;
                m_FrontTireAlignFinish_Flag = TRUE;
            }
        }
        else if(m_PowerModeStatus == WN_enOFF)
        {
            m_FrontTireAlignFinish_Flag = FALSE;
            m_enFrontTireAlignFinish = WN_enDISPLAY_OFF;
        }
        else
        {

        }
    }

    WN_SET(WN_enFrontTireAlignFinish, m_enFrontTireAlignFinish);
    WN_SET(WN_enFrontTireTurnRight, enFrontTireTurnRight);
    WN_SET(WN_enFrontTireTurnLeft, enFrontTireTurnLeft);
}

void WN_DPFWarningProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enPlsStartSelfClean = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPlsStartCarSlowly = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDPFCleaning = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSelfCleanComplete = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enCatcherSeriouslyBlocked = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;

    //ECM16 0x2D4 100ms
    uint8 DPF_Warning_temp = 0;
    uint8 Rte_DPF_Warning = RTE_E_INVALID;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);

    Rte_DPF_Warning = WN_DPF_Warning_SignalGet(&DPF_Warning_temp);

    if (configFuel == 0)
    {
        //1.234
        if ((RTE_E_OK == Rte_DPF_Warning) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_DPF_Warning))
        {
            if (DPF_Warning_temp == 0x1)
            {
                enPlsStartSelfClean = WN_enDISPLAY_ON;
            }
            else if (DPF_Warning_temp == 0x2)
            {
                enPlsStartCarSlowly = WN_enDISPLAY_ON;
            }
            else if (DPF_Warning_temp == 0x3)
            {
                enDPFCleaning = WN_enDISPLAY_ON;
            }
            else if (DPF_Warning_temp == 0x4)
            {
                enSelfCleanComplete = WN_enDISPLAY_ON;
            }
            else if(DPF_Warning_temp == 0x5)
            {
                enCatcherSeriouslyBlocked = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
    }

    WN_SET(WN_enPlsStartSelfClean, enPlsStartSelfClean);
    WN_SET(WN_enPlsStartCarSlowly, enPlsStartCarSlowly);
    WN_SET(WN_enDPFCleaning, enDPFCleaning);
    WN_SET(WN_enSelfCleanComplete, enSelfCleanComplete);
    WN_SET(WN_enCatcherSeriouslyBlocked, enCatcherSeriouslyBlocked);
}

void WN_UreaFuncProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enUreaLow = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enUreaVeryLow = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enUreaTankEmpty = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enUreaUnqualifyPlsCheck = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enUreaUnqualifyOver50km = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enUreaFillStopPlsReFill = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enUreaFillStopOver50km = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enUreaSysDisableEng = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enUreaSysErrPlsCheck = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enUreaSysErrOver50km = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enUreaSysErrRestartErr = WN_enDISPLAY_OFF;

	WN_CFG_enSTATUS_Common enUreaInsCantStartAfter = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enUreaInsSeriouslyCantStartAfter = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enUreaEmptyCantStartNext = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enUreaEmptyCantStart = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enUreaUnqualifyCantStartAfter = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enUreaUnqualifyCantStartNext = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enUreaUnqualifyCantStart = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enUreaFillStopCantStartAfter = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enUreaFillStopCantStartNext = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enUreaFillStopCantStart = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enConsumDeviatCantStartAfter = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enConsumDeviatCantStartNext = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enConsumDeviatCantStart = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte31 Bit7-bit3
    uint8 configEMissionLevel = 0;

    //ECM16 0x2D4 100ms
    uint8 SCRSysWarnDisplay_temp = 0;
    uint8 Rte_SCRSysWarnDisplay = RTE_E_INVALID;
	uint8 SCRSysWarnDisplay_B2_temp = 0;//R15
	uint16 UreaRemainDist_temp = 0;
    uint8 Rte_SG_ECM16_temp = RTE_E_INVALID;
	
    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configEMissionLevel = (uint8)WN_GetSingleConfig(WN_enCfg_EMissionLevel);

    Rte_SCRSysWarnDisplay = WN_SCRSysWarnDisplay_SignalGet(&SCRSysWarnDisplay_temp);
	Rte_SG_ECM16_temp = WN_UreaRemainDist_SignalGet(&UreaRemainDist_temp);
	Rte_SG_ECM16_temp = WN_SCRSysWarnDisplay_B2_SignalGet(&SCRSysWarnDisplay_B2_temp);

	
    if ((configFuel == 0) && ((configEMissionLevel == 5) ||
        (configEMissionLevel == 6) ||
        (configEMissionLevel == 7) ||
        (configEMissionLevel == 8)))
    {
        //1.233 CASE1
        if ((RTE_E_OK == Rte_SCRSysWarnDisplay) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SCRSysWarnDisplay))
        {
            if (SCRSysWarnDisplay_temp == 0x1)
            {
                enUreaLow = WN_enDISPLAY_ON;
            }
            else if (SCRSysWarnDisplay_temp == 0x2)
            {
                enUreaVeryLow = WN_enDISPLAY_ON;
            }
            else if (SCRSysWarnDisplay_temp == 0x3)
            {
                enUreaTankEmpty = WN_enDISPLAY_ON;
            }
            else if (SCRSysWarnDisplay_temp == 0x4)
            {
                enUreaUnqualifyPlsCheck = WN_enDISPLAY_ON;
            }
            else if (SCRSysWarnDisplay_temp == 0x5)
            {
                enUreaUnqualifyOver50km = WN_enDISPLAY_ON;
            }
            else if (SCRSysWarnDisplay_temp == 0x6)
            {
                enUreaFillStopPlsReFill = WN_enDISPLAY_ON;
            }
            else if (SCRSysWarnDisplay_temp == 0x7)
            {
                enUreaFillStopOver50km = WN_enDISPLAY_ON;
            }
            else if (SCRSysWarnDisplay_temp == 0x8)
            {
                enUreaSysDisableEng = WN_enDISPLAY_ON;
            }
            else if (SCRSysWarnDisplay_temp == 0x9)
            {
                enUreaSysErrPlsCheck = WN_enDISPLAY_ON;
            }
            else if (SCRSysWarnDisplay_temp == 0xA)
            {
                enUreaSysErrOver50km = WN_enDISPLAY_ON;
            }
            else if (SCRSysWarnDisplay_temp == 0xB)
            {
                enUreaSysErrRestartErr = WN_enDISPLAY_ON;
            }
            else
            {
            }
        }
    }
	else if ((configFuel == 0) && ((configEMissionLevel == 0x9) || (configEMissionLevel == 0xA)))
	{
		//1.233 CASE2
		if ((RTE_E_OK == Rte_SG_ECM16_temp) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SG_ECM16_temp)) 
        {
            if (SCRSysWarnDisplay_B2_temp == 0x3)
            {
                enUreaEmptyCantStartNext = WN_enDISPLAY_ON;
            }
            else if (SCRSysWarnDisplay_B2_temp == 0x4)
            {
                enUreaEmptyCantStart = WN_enDISPLAY_ON;
            }
            else if (SCRSysWarnDisplay_B2_temp == 0x6)
            {
                enUreaUnqualifyCantStartNext = WN_enDISPLAY_ON;
            }
            else if (SCRSysWarnDisplay_B2_temp == 0x7)
            {
                enUreaUnqualifyCantStart = WN_enDISPLAY_ON;
            }
            else if (SCRSysWarnDisplay_B2_temp == 0x9)
            {
                enUreaFillStopCantStartNext = WN_enDISPLAY_ON;
            }
            else if (SCRSysWarnDisplay_B2_temp == 0xA)
            {
                enUreaFillStopCantStart = WN_enDISPLAY_ON;
            }
            else if (SCRSysWarnDisplay_B2_temp == 0xC)
            {
                enConsumDeviatCantStartNext = WN_enDISPLAY_ON;
            }
            else if (SCRSysWarnDisplay_B2_temp == 0xD)
            {
                enConsumDeviatCantStart = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
            if(0xFFF >= UreaRemainDist_temp)
            {
                if (SCRSysWarnDisplay_B2_temp == 0x1)
                {
                    enUreaInsCantStartAfter = WN_enDISPLAY_ON;
                }
                else if (SCRSysWarnDisplay_B2_temp == 0x2)
                {
                    enUreaInsSeriouslyCantStartAfter = WN_enDISPLAY_ON;
                }
                else if (SCRSysWarnDisplay_B2_temp == 0x5)
                {
                    enUreaUnqualifyCantStartAfter = WN_enDISPLAY_ON;
                }
                else if (SCRSysWarnDisplay_B2_temp == 0x8)
                {
                    enUreaFillStopCantStartAfter = WN_enDISPLAY_ON;
                }
                else if (SCRSysWarnDisplay_B2_temp == 0xB)
                {
                    enConsumDeviatCantStartAfter = WN_enDISPLAY_ON;
                }
                else
                {
                    /* do nothing */
                }
                m_UreaRemainDist = UreaRemainDist_temp;
            }
        }
		else
		{
			//m_UreaRemainDist = 0xFFFF;
		}
	
	}
	

    WN_SET(WN_enUreaLow, enUreaLow);
    WN_SET(WN_enUreaVeryLow, enUreaVeryLow);
    WN_SET(WN_enUreaTankEmpty, enUreaTankEmpty);
    WN_SET(WN_enUreaUnqualifyPlsCheck, enUreaUnqualifyPlsCheck);
    WN_SET(WN_enUreaUnqualifyOver50km, enUreaUnqualifyOver50km);
    WN_SET(WN_enUreaFillStopPlsReFill, enUreaFillStopPlsReFill);
    WN_SET(WN_enUreaFillStopOver50km, enUreaFillStopOver50km);
    WN_SET(WN_enUreaSysDisableEng, enUreaSysDisableEng);
    WN_SET(WN_enUreaSysErrPlsCheck, enUreaSysErrPlsCheck);
    WN_SET(WN_enUreaSysErrOver50km, enUreaSysErrOver50km);
    WN_SET(WN_enUreaSysErrRestartErr, enUreaSysErrRestartErr);

	WN_SET(WN_enUreaInsCantStartAfter, enUreaInsCantStartAfter);
	WN_SET(WN_enUreaInsSeriouslyCantStartAfter, enUreaInsSeriouslyCantStartAfter);
	WN_SET(WN_enUreaEmptyCantStartNext, enUreaEmptyCantStartNext);
	WN_SET(WN_enUreaEmptyCantStart, enUreaEmptyCantStart);
	WN_SET(WN_enUreaUnqualifyCantStartAfter, enUreaUnqualifyCantStartAfter);
	WN_SET(WN_enUreaUnqualifyCantStartNext, enUreaUnqualifyCantStartNext);
	WN_SET(WN_enUreaUnqualifyCantStart, enUreaUnqualifyCantStart);
	WN_SET(WN_enUreaFillStopCantStartAfter, enUreaFillStopCantStartAfter);
	WN_SET(WN_enUreaFillStopCantStartNext, enUreaFillStopCantStartNext);
	WN_SET(WN_enUreaFillStopCantStart, enUreaFillStopCantStart);
	WN_SET(WN_enConsumDeviatCantStartAfter, enConsumDeviatCantStartAfter);
	WN_SET(WN_enConsumDeviatCantStartNext, enConsumDeviatCantStartNext);
	WN_SET(WN_enConsumDeviatCantStart, enConsumDeviatCantStart);
}

void WN_AntiVirusFuncProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enRayAntiVirusWarn = WN_enDISPLAY_OFF;

    //Byte84 Bit3-bit2
    uint8 configUltravioletLamp = 0;

    //BCM12 0x238 50ms
    uint8 UVCAntiVirusFdbk_temp = 0;
    uint8 Rte_UVCAntiVirusFdbk = RTE_E_INVALID;

    configUltravioletLamp = (uint8)WN_GetSingleConfig(WN_enCfg_UltravioletLamp);

    Rte_UVCAntiVirusFdbk = WN_UVCAntiVirusFdbk_SignalGet(&UVCAntiVirusFdbk_temp);

    if (configUltravioletLamp == 1)
    {
        //1.243
        if ((RTE_E_OK == Rte_UVCAntiVirusFdbk) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_UVCAntiVirusFdbk))
        {
            if ((UVCAntiVirusFdbk_temp == 0x1) || (UVCAntiVirusFdbk_temp == 0x4))
            {
                enRayAntiVirusWarn = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enRayAntiVirusWarn, enRayAntiVirusWarn);
}

void WN_AntennaLostProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enAntennaLostErr = WN_enDISPLAY_OFF;

    //Byte80 Bit7-bit6
    uint8 configCentralModule = 0;

    //PEPS4 0x302 20ms TBD
    uint8 AntLostFlg_temp = 0;
    uint8 Rte_AntLostFlg = RTE_E_INVALID;

    configCentralModule = (uint8)WN_GetSingleConfig(WN_enCfg_CentralModule);
	Rte_AntLostFlg = WN_AntLostFlg_SignalGet(&AntLostFlg_temp);

    if (configCentralModule == 1)
    {
        //1.245
         if ((RTE_E_OK == Rte_AntLostFlg) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_AntLostFlg))
        {
            if (AntLostFlg_temp == 0x1)
            {
                enAntennaLostErr = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enAntennaLostErr, enAntennaLostErr);
}

void WN_OilBoxStatusProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enMainTankLow = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enMainTankLowPlsSwitch = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAuxTankLow = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAuxTankLowPlsSwitch = WN_enDISPLAY_OFF;

    //Byte84 Bit7-bit6
    uint8 configAuxFuel = 0;

    //ECM16 0x2D4 100ms TBD
    uint8 fl_OilBoxSplySts_U8 = 0;
    uint8 Rte_OilBoxSplySts = RTE_E_INVALID;
    uint8 LowFuel_Active = 0;
    uint8 AuxLowFuel_Active = 0;
    //Gauge模块获取
    FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE Fuel_Mode_Data = {0};

    configAuxFuel = (uint8)WN_GetSingleConfig(WN_enCfg_AuxFuel);
    Rte_OilBoxSplySts = WN_OilBoxSplySts_SignalGet(&fl_OilBoxSplySts_U8);
    WN_LowFuel_Active_APIGet(&Fuel_Mode_Data);
    LowFuel_Active = Fuel_Mode_Data.Fuel_Warning_Status;
    AuxLowFuel_Active = Fuel_Mode_Data.Fuel_Warning_Status_Aux;

    if (configAuxFuel == 1)
    {
        //1.239
        if ((RTE_E_OK == Rte_OilBoxSplySts) || \
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_OilBoxSplySts))
        {
            if (fl_OilBoxSplySts_U8 == 0x0)
            {
                if((LowFuel_Active == 1) && (AuxLowFuel_Active == 0))
                {
                    enMainTankLowPlsSwitch = WN_enDISPLAY_ON;
                }
                else if((LowFuel_Active == 1) && (AuxLowFuel_Active == 1))
                {
                    enMainTankLow = WN_enDISPLAY_ON;
                }
                else
                {

                }
            }
            else if (fl_OilBoxSplySts_U8 == 0x1)
            {
                if((LowFuel_Active == 0) && (AuxLowFuel_Active == 1))
                {
                    enAuxTankLowPlsSwitch = WN_enDISPLAY_ON;
                }
                else if((LowFuel_Active == 1) && (AuxLowFuel_Active == 1))
                {
                    enAuxTankLow = WN_enDISPLAY_ON;
                }
                else
                {

                }
            }
            else
            {

            }
        }
    }

    WN_SET(WN_enMainTankLow, enMainTankLow);
    WN_SET(WN_enMainTankLowPlsSwitch, enMainTankLowPlsSwitch);
    WN_SET(WN_enAuxTankLow, enAuxTankLow);
    WN_SET(WN_enAuxTankLowPlsSwitch, enAuxTankLowPlsSwitch);
}

void WN_ERCFuncProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enOverSpeedERCSysOn = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enERCSysLimit = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enERCSysErr = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enERCSysDisable = WN_enDISPLAY_OFF;

    //Byte98 Bit2-Bit0
    uint8 configGAGSts = 0;

    uint8 fl_BarConnSts = 0;
    uint8 Rte_BarConnSts = RTE_E_INVALID;

    configGAGSts = (uint8)WN_GetSingleConfig(WN_enCfg_GAG);
    //configGAGSts = 1;
    Rte_BarConnSts = WN_ECM24_BarConnSts_SignalGet(&fl_BarConnSts);//R13

    if (configGAGSts == 2)
    {
        //1.242
        if ((RTE_E_OK == Rte_BarConnSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_BarConnSts))
        {
            if(fl_BarConnSts == 0x4)
            {
                enERCSysLimit = WN_enDISPLAY_ON;
            }
            else if(fl_BarConnSts == 0x5)
            {
                enERCSysErr = WN_enDISPLAY_ON;
            }
            else if(fl_BarConnSts == 0x6)
            {
                enERCSysDisable = WN_enDISPLAY_ON;
            }
            else
            {

            }
        }
    }

    WN_SET(WN_enOverSpeedERCSysOn, enOverSpeedERCSysOn);
    WN_SET(WN_enERCSysLimit, enERCSysLimit);
    WN_SET(WN_enERCSysErr, enERCSysErr);
    WN_SET(WN_enERCSysDisable, enERCSysDisable);
}

void WN_TurnAssistFuncProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enTurnAssistFuncLimit = WN_enDISPLAY_OFF;

    //Byte25 Bit1-bit0
    uint8 configSteeringSys = 0;

    //ESP1 0x168 20ms
    //EPS_FD1 0x147 20ms
    uint8 EPS_FailSts_temp = 0;
    uint8 Rte_EPS_FailSts = RTE_E_INVALID;

    configSteeringSys = (uint8)WN_GetSingleConfig(WN_enCfg_SteeringSys);

    if (configSteeringSys == 1)//R18
    {
        if(EolConfig_Trans_CANFD())
        {
            Rte_EPS_FailSts = WN_EPS_FailSts_FD_SignalGet(&EPS_FailSts_temp);
        }
        else
        {
            Rte_EPS_FailSts = WN_EPS_FailSts_SignalGet(&EPS_FailSts_temp);
        }
        //1.248
        if ((RTE_E_OK == Rte_EPS_FailSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_EPS_FailSts))
        {
            if (EPS_FailSts_temp == 0x2)
            {
                enTurnAssistFuncLimit = WN_enDISPLAY_ON;
            }
        }
    }

    WN_SET(WN_enTurnAssistFuncLimit, enTurnAssistFuncLimit);
}

void WN_OffroadThmProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enOffroadThmSts = WN_enDISPLAY_OFF;

    //Byte86 Bit7-bit6 
    uint8 configOffroadThm = 0;

    //ECM11 2D3
    uint8 ECM_OffroadThmSts = 0;
    uint8 Rte_ECM_OffroadThmSts = RTE_E_INVALID;

	configOffroadThm = (uint8)WN_GetSingleConfig(WN_encfg_OffroadThm);
	Rte_ECM_OffroadThmSts = WN_ECM_OffroadThmSts_SignalGet(&ECM_OffroadThmSts);
    if (configOffroadThm == 1)
    {
        //1.265
        if ((RTE_E_OK == Rte_ECM_OffroadThmSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_ECM_OffroadThmSts))
        {
            if (ECM_OffroadThmSts == 0x1)
            {
                enOffroadThmSts = WN_enDISPLAY_ON;
            }
        }
    }
    WN_SET(WN_enOffroadThmSts, enOffroadThmSts);
}

void WN_WadeModeFuncProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enPlsExitWadeMode = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enWadeModePlsSlow = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enWadeModePlsCare = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPlsPressBrakeTest = WN_enDISPLAY_OFF;

    //Byte25 Bit7-bit4
    uint8 configDrvModeOptionnal = 0;
    //Byte52 Bit7-bit2
    uint8 configDrvMode2 = 0;
    //Byte85 Bit7-bit0
    uint8 configDrvMode3 = 0;

    //TBD TBD TBD TBD
    uint8 Wade_SW_warn = 0;
    uint8 Rte_Wade_SW_warn = RTE_E_INVALID;
    uint8 WadeModeWarn = 0;
    uint8 Rte_WadeModeWarn = RTE_E_INVALID;
    boolean VehCfgSts = FALSE;

    configDrvModeOptionnal = (uint8)WN_GetSingleConfig(WN_enCfg_DrvModeOptionnal);
    configDrvMode2 = (uint8)WN_GetSingleConfig(WN_enCfg_DrvMode2);
    configDrvMode3 = (uint8)WN_GetSingleConfig(WN_enCfg_DrvMode3);

    Rte_Wade_SW_warn = WN_Wade_SW_warn_SignalGet(&Wade_SW_warn);
    Rte_WadeModeWarn = WN_WadeModeWarn_SignalGet(&WadeModeWarn);
    if(((configDrvMode2 == 15) && (configDrvModeOptionnal == 0) && (configDrvMode3 == 0)) || 
    ((configDrvModeOptionnal == 0) && (configDrvMode2 == 0) && ((configDrvMode3 == 11) || (configDrvMode3 == 12) ||
    (configDrvMode3 == 15) || (configDrvMode3 == 16) || (configDrvMode3 == 18) || (configDrvMode3 == 31))))

    {
        VehCfgSts = TRUE;
    }
    else
    {
        /* do nothing */
    }
    if(VehCfgSts == TRUE)
    {
        //1.267
        if ((RTE_E_OK == Rte_Wade_SW_warn) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_Wade_SW_warn))
        {
            if (Wade_SW_warn == 0x1)
            {
                enPlsExitWadeMode = WN_enDISPLAY_ON;
            }
        }
        if((RTE_E_OK == Rte_WadeModeWarn) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_WadeModeWarn))
        {
            if (WadeModeWarn == 0x1)
            {
                enWadeModePlsSlow = WN_enDISPLAY_ON;
            }
            else if (WadeModeWarn == 0x2)
            {
                enWadeModePlsCare = WN_enDISPLAY_ON;
            }
            else if(WadeModeWarn == 0x3)//R11
            {
                enPlsPressBrakeTest = WN_enDISPLAY_ON;
            }
            else
            {}
        }
    }

    WN_SET(WN_enPlsExitWadeMode, enPlsExitWadeMode);
    WN_SET(WN_enWadeModePlsSlow, enWadeModePlsSlow);
    WN_SET(WN_enWadeModePlsCare, enWadeModePlsCare);
    WN_SET(WN_enPlsPressBrakeTest, enPlsPressBrakeTest);
}

void WN_AutoLampStsProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    //BCM17 0x23E 50ms
    uint8 AutoLmpsts_temp = 0;
    uint8 Rte_AutoLmpsts = RTE_E_INVALID;

    Rte_AutoLmpsts = WN_AutoLmpsts_SignalGet(&AutoLmpsts_temp);

    if (WN_enRUN == m_PowerModeStatus)
    {
        //1.268
        if ((RTE_E_OK == Rte_AutoLmpsts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_AutoLmpsts))
        {
            if (m_AutoLmpStsSignalInit)
            {
                if ((m_PreAutoLmpSts == 0) && (AutoLmpsts_temp == 0x1))
                {
                    m_enAutoLmpStsOn = WN_enDISPLAY_ON;
                    m_enAutoLmpStsOff = WN_enDISPLAY_OFF;
                }
                if ((m_PreAutoLmpSts == 1) && (AutoLmpsts_temp == 0x0))
                {
                    m_enAutoLmpStsOff = WN_enDISPLAY_ON;
                    m_enAutoLmpStsOn = WN_enDISPLAY_OFF;
                }
                m_PreAutoLmpSts = AutoLmpsts_temp;
            }
            else
            {
                m_PreAutoLmpSts = AutoLmpsts_temp;
                m_AutoLmpStsSignalInit = TRUE;
            }
        }
        else
        {
            m_enAutoLmpStsOn = WN_enDISPLAY_OFF;
            m_enAutoLmpStsOff = WN_enDISPLAY_OFF;
            m_PreAutoLmpSts = 0;
            m_AutoLmpStsSignalInit = FALSE;
        }
    }
    else
    {
        m_enAutoLmpStsOn = WN_enDISPLAY_OFF;
        m_enAutoLmpStsOff = WN_enDISPLAY_OFF;
        m_PreAutoLmpSts = 0;
        m_AutoLmpStsSignalInit = FALSE;
    }

    WN_SET(WN_enAutoLmpStsOn, m_enAutoLmpStsOn);
    WN_SET(WN_enAutoLmpStsOff, m_enAutoLmpStsOff);
}

void WN_NOHProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    uint8 NOH_SysInfoDisplay = 0;
    uint16 NOH_DistToExit = 0;
    uint8 Rte_ACC_FD3 = RTE_E_INVALID;
    uint8 NOH_WarnInfoDisplay = 0;
    uint8 Rte_NOH_WarnInfoDisplay = RTE_E_INVALID;
    uint8 ACC_SpdSetValue_temp = 0;
    uint8 Rte_ACC_SpdSetValue = RTE_E_INVALID;
    //Byte82 Bit3-Bit2
    uint8 configNOH_TEV = 0;
    //Byte103 Bit7-Bit5
    uint8 configTFC = 0;
    uint8 fl_VehUnit_U8 = 0;
    MenuSetData_t MenuSetData_Tmp = {0};

    WN_CFG_enSTATUS_Common enAutoNaviStart = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAutoNaviEnd = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enNOHFinishExit = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enOverSpeedNOHExit = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDriveIntoHighSpeed = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enDriveIntoRamp = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enNOHFailPlsFix = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enNOHFailPlsGearP = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enMoveRampFailPlsHand = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enMoveMainFailPlsHand = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTurnFailPlsHand = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTollGateFailPlsHand = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRoundaboutFailPlsHand = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRePlanLanes = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPlsHandChangeLanes = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enNOHSetAccSpeed = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enNOHIsResumed = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enMargeWatchOutFOrCarsComing = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSlowingDownForDischarge = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enNOExitedTakeSteeringWheel = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enLaneLineNotClearDriveCarefully = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enComingOutMainRoad = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enApproachingRamp = WN_enDISPLAY_OFF;

    configNOH_TEV = (uint8)WN_GetSingleConfig(WN_enCfg_NOH);
    Rte_ACC_FD3 = WN_NOH_SysInfoDisplay_SignalGet(&NOH_SysInfoDisplay);
    Rte_ACC_FD3 = WN_NOH_DistToExit_SignalGet(&NOH_DistToExit);
    Rte_NOH_WarnInfoDisplay = WN_NOH_WarnInfoDisplay_SignalGet(&NOH_WarnInfoDisplay);
    Rte_ACC_SpdSetValue = WN_ACC_SpdSetValue_SignalGet(&ACC_SpdSetValue_temp);
    configTFC = (uint8)WN_GetSingleConfig(WN_encfg_TFC);
    WN_MenuSetData_APIGet(&MenuSetData_Tmp);
    fl_VehUnit_U8 = MenuSetData_Tmp.OdometerUnit;

    if ((fl_VehUnit_U8 == 2) || (fl_VehUnit_U8 == 3)) // mph
    {
        fl_VehUnit_U8 = 0;
    }
    else // kmh
    {
        fl_VehUnit_U8 = 1;
    }

    if ((m_PowerModeStatus == WN_enOFF) || ((9 != l_NOH_SysInfoDisplay_last_U8) && (9 == NOH_SysInfoDisplay)))
    {
        l_NOH_DistanceToExit = 0;
        l_NOH_DistanceToExit_last = 0;
        NOH_Count = 0;
        NOH_Count1 = 0;
    }

    if(configNOH_TEV == 1)
    {
        //1.247
        if ((RTE_E_OK == Rte_ACC_FD3) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_ACC_FD3))
        {
            if((configTFC == 1) || (configTFC == 2) || (configTFC == 3) || (configTFC == 0))//ICU1.0/ICU1.5/ICU2.0 R16
            {
                //case 1
                if(NOH_SysInfoDisplay == 0x1)
                {
                    enAutoNaviStart = WN_enDISPLAY_ON;
                }
                else if(NOH_SysInfoDisplay == 0xA)
                {
                    enAutoNaviEnd = WN_enDISPLAY_ON;
                }
                else if(NOH_SysInfoDisplay == 0xB)
                {
                    enNOHFinishExit = WN_enDISPLAY_ON;
                }
                else if(NOH_SysInfoDisplay == 0xD)
                {
                    enOverSpeedNOHExit = WN_enDISPLAY_ON;
                }
                else if(NOH_SysInfoDisplay == 0xE)
                {
                    enDriveIntoHighSpeed = WN_enDISPLAY_ON;
                }
                else if(NOH_SysInfoDisplay == 0xF)
                {
                    enDriveIntoRamp = WN_enDISPLAY_ON;
                }
                else
                {
                    /* do nothing */
                }

                if((NOH_SysInfoDisplay == 0x9) && 
                        ((2000 == NOH_DistToExit) || (1000 == NOH_DistToExit) || (500 == NOH_DistToExit)))
                {
                    l_NOH_DistanceToExit = NOH_DistToExit;
                    if(l_NOH_DistanceToExit != l_NOH_DistanceToExit_last)
                    {
                        m_enNOHExit = WN_enDISPLAY_ON;
                        m_NOH_DistanceToExit = NOH_DistToExit;
                        l_NOH_DistanceToExit_last = l_NOH_DistanceToExit;
                    }
                }
                else
                {
                    m_enNOHExit = WN_enDISPLAY_OFF;
                }

                if((NOH_SysInfoDisplay == 0x9) && ((200 == NOH_DistToExit) || (100 >= NOH_DistToExit)))
                {
                    if(200 == NOH_DistToExit)
                    {
                        if(NOH_Count < 1)
                        {
                            m_enNOHExitPlsTake = WN_enDISPLAY_ON;
                            m_NOH_DistanceToExit = NOH_DistToExit;
                            NOH_Count++;
                        }
                    }
                    else if(100 >= NOH_DistToExit)
                    {
                        if(NOH_Count1 < 1)
                        {
                            m_enNOHExitPlsTake = WN_enDISPLAY_ON;
                            m_NOH_DistanceToExit = NOH_DistToExit;
                            NOH_Count1++;
                        }
                    }
                    else
                    {
                        m_enNOHExitPlsTake = WN_enDISPLAY_OFF;
                    }
                }
                else
                {
                    m_enNOHExitPlsTake = WN_enDISPLAY_OFF;
                }

                if((RTE_E_OK == Rte_ACC_SpdSetValue) ||
                    (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_ACC_SpdSetValue))//R11
                {
                    if((NOH_SysInfoDisplay == 0xC) && (ACC_SpdSetValue_temp <= 0xFE))
                    {
                        enNOHSetAccSpeed = WN_enDISPLAY_ON;
                        m_ACC_SpeedSetValue = ACC_SpdSetValue_temp;
                    }
                    else
                    {
                        m_ACC_SpeedSetValue = 0x0;
                    }
                }
            }
            else if(configTFC == 4)//ICU3.0
            {
                //case 2
                if(NOH_SysInfoDisplay == 0x1)
                {
                    enAutoNaviStart = WN_enDISPLAY_ON;
                }
                else if(NOH_SysInfoDisplay == 0xA)
                {
                    enAutoNaviEnd = WN_enDISPLAY_ON;
                }
                else if(NOH_SysInfoDisplay == 0xB)
                {
                    enNOHFinishExit = WN_enDISPLAY_ON;
                }
                else if(NOH_SysInfoDisplay == 0xD)
                {
                	enOverSpeedNOHExit = WN_enDISPLAY_ON;
                }
                else if(NOH_SysInfoDisplay == 0xE)
                {
                    enDriveIntoHighSpeed = WN_enDISPLAY_ON;
                }
                else if(NOH_SysInfoDisplay == 0xF)
                {
                    if((2000 == NOH_DistToExit) || (1000 == NOH_DistToExit) || (500 == NOH_DistToExit))
                    {
                    	enApproachingRamp = WN_enDISPLAY_ON;//XX 米后即将进入匝道                                         
                    }
                    else
                    {
                        
                    }
                }
                else
                {}
                
                if((NOH_SysInfoDisplay == 0x9) && 
                        ((2000 == NOH_DistToExit) || (1000 == NOH_DistToExit) || (500 == NOH_DistToExit)))
                {
                    l_NOH_DistanceToExit = NOH_DistToExit;
                    if(l_NOH_DistanceToExit != l_NOH_DistanceToExit_last)
                    {
                        m_enNOHExit = WN_enDISPLAY_ON;//XX公里后将退出NOH
                        m_NOH_DistanceToExit = NOH_DistToExit;
                        l_NOH_DistanceToExit_last = l_NOH_DistanceToExit;
                    }
                }
                else
                {
                    m_enNOHExit = WN_enDISPLAY_OFF;
                }

                if((NOH_SysInfoDisplay == 0x9) && ((200 == NOH_DistToExit) || (100 >= NOH_DistToExit)))
                {
                    if(200 == NOH_DistToExit)
                    {
                        if(NOH_Count < 1)
                        {
                            m_enNOHExitPlsTake = WN_enDISPLAY_ON;//请准备接管，XX米后NOH将退出
                            m_NOH_DistanceToExit = NOH_DistToExit;
                            NOH_Count++;
                        }
                    }
                    else if(100 >= NOH_DistToExit)
                    {
                        if(NOH_Count1 < 1)
                        {
                            m_enNOHExitPlsTake = WN_enDISPLAY_ON;//请准备接管，XX米后NOH将退出
                            m_NOH_DistanceToExit = NOH_DistToExit;
                            NOH_Count1++;
                        }
                    }
                    else
                    {
                        m_enNOHExitPlsTake = WN_enDISPLAY_OFF;
                    }
                }
                else
                {
                    // = WN_enDISPLAY_OFF;
                }

                if((RTE_E_OK == Rte_ACC_SpdSetValue) ||
                    (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_ACC_SpdSetValue))//R17
                {
                    if((NOH_SysInfoDisplay == 0xC) && (ACC_SpdSetValue_temp <= 0xFE))
                    {
                        enNOHSetAccSpeed = WN_enDISPLAY_ON;//巡航车速设为XXkm/h
                        m_ACC_SpeedSetValue = ACC_SpdSetValue_temp;
                    }
                    else
                    {
                        m_ACC_SpeedSetValue = 0x0;
                    }
                }
            }
            else if(configTFC == 0x5)//ICU1.5H
            {}
        }
        else
        {
            m_NOH_DistanceToExit = 0xFFFF;
            l_NOH_DistanceToExit = 0;
            l_NOH_DistanceToExit_last = 0;
            NOH_Count = 0;
            NOH_Count1 = 0;
            m_enNOHExit = WN_enDISPLAY_OFF;
            m_enNOHExitPlsTake = WN_enDISPLAY_OFF;
        }
        //1.273
        if ((RTE_E_OK == Rte_NOH_WarnInfoDisplay) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_NOH_WarnInfoDisplay))
        {
            if((configTFC == 1) || (configTFC == 2) || (configTFC == 3) || (configTFC == 0))//ICU1.0/ICU1.5/ICU2.0 R16
            {
                //case 1
                if(NOH_WarnInfoDisplay == 0x1)
                {
                    enNOHFailPlsFix = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0x2)
                {
                    enNOHFailPlsGearP = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0x3)
                {
                    enMoveRampFailPlsHand = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0x4)
                {
                    enMoveMainFailPlsHand = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0x5)
                {
                    enTurnFailPlsHand = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0x6)
                {
                    enTollGateFailPlsHand = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0x7)
                {
                    enRoundaboutFailPlsHand = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0x8)
                {
                    enRePlanLanes = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0x9)
                {
                    enPlsHandChangeLanes = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0xA)
                {
                    enNOHIsResumed = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0xB)
                {
                    enMargeWatchOutFOrCarsComing = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0xC)
                {
                    enSlowingDownForDischarge = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0xD)
                {
                    enNOExitedTakeSteeringWheel = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0xE)
                {
                    enLaneLineNotClearDriveCarefully = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0xF)
                {
                    enComingOutMainRoad = WN_enDISPLAY_ON;
                }
                else
                {

                }
            }
            else if(configTFC == 4)//ICU3.0
            {
                //case 2
                if(NOH_WarnInfoDisplay == 0x1)
                {
                    enNOHFailPlsFix = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0x2)
                {
                    enNOHFailPlsGearP = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0x3)
                {
                    enMoveRampFailPlsHand = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0x4)
                {
                    enMoveMainFailPlsHand = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0x5)
                {
                    enTurnFailPlsHand = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0x6)
                {
                    enTollGateFailPlsHand = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0x7)
                {
                    enRoundaboutFailPlsHand = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0x8)
                {
                    enRePlanLanes = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0x9)
                {
                    enPlsHandChangeLanes = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0xA)
                {
                    enNOHIsResumed = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0xB)
                {
                    enMargeWatchOutFOrCarsComing = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0xC)
                {
                    enSlowingDownForDischarge = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0xD)
                {
                    enNOExitedTakeSteeringWheel = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0xE)
                {
                    enLaneLineNotClearDriveCarefully = WN_enDISPLAY_ON;
                }
                else if(NOH_WarnInfoDisplay == 0xF)
                {
                    // = WN_enDISPLAY_ON;
                }
                else
                {

                }
            }
        }
        else
        {
            
        }
    }
    l_NOH_SysInfoDisplay_last_U8 = NOH_SysInfoDisplay;

    WN_SET(WN_enAutoNaviStart, enAutoNaviStart);
    WN_SET(WN_enNOHExit, m_enNOHExit);
    WN_SET(WN_enAutoNaviEnd, enAutoNaviEnd);
    WN_SET(WN_enNOHFinishExit, enNOHFinishExit);
    WN_SET(WN_enOverSpeedNOHExit, enOverSpeedNOHExit);
    WN_SET(WN_enDriveIntoHighSpeed, enDriveIntoHighSpeed);
    WN_SET(WN_enDriveIntoRamp, enDriveIntoRamp);
    WN_SET(WN_enNOHExitPlsTake, m_enNOHExitPlsTake);
    WN_SET(WN_enNOHFailPlsFix, enNOHFailPlsFix);
    WN_SET(WN_enNOHFailPlsGearP, enNOHFailPlsGearP);
    WN_SET(WN_enMoveRampFailPlsHand, enMoveRampFailPlsHand);
    WN_SET(WN_enMoveMainFailPlsHand, enMoveMainFailPlsHand);
    WN_SET(WN_enTurnFailPlsHand, enTurnFailPlsHand);
    WN_SET(WN_enTollGateFailPlsHand, enTollGateFailPlsHand);
    WN_SET(WN_enRoundaboutFailPlsHand, enRoundaboutFailPlsHand);
    WN_SET(WN_enRePlanLanes, enRePlanLanes);
    WN_SET(WN_enPlsHandChangeLanes, enPlsHandChangeLanes);
    WN_SET(WN_enNOHSetAccSpeed, enNOHSetAccSpeed);
    WN_SET(WN_enNOHIsResumed, enNOHIsResumed);
    WN_SET(WN_enMargeWatchOutFOrCarsComing, enMargeWatchOutFOrCarsComing);
    WN_SET(WN_enSlowingDownForDischarge, enSlowingDownForDischarge);
    WN_SET(WN_enNOExitedTakeSteeringWheel, enNOExitedTakeSteeringWheel);
    WN_SET(WN_enLaneLineNotClearDriveCarefully, enLaneLineNotClearDriveCarefully);
    WN_SET(WN_enComingOutMainRoad, enComingOutMainRoad);
	WN_SET(WN_enApproachingRamp, enApproachingRamp);
}

void WN_V2VProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enV2XCarDistance = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XBackCarLeft = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XBackCarRight = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XBackCarTwoSide = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XLeftLine = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XRightLine = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XFrontCarAEB = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XSideCarTwoSide = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XSideCarRight = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XSideCarLeft = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XFaceCar = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XLeaveCar = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XLeaveFireCar = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XLeaveAmbulance = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XLeavePolice = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XLeaveEngCar = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XFrontCarUnContron = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XBackCarUnContron = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XAroundCarUnContron = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XPeopleRight = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XPeopleMid = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XPeopleLeft = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XReverseLine = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XRoadBlockLever1 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XRoadBlockLever2 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XRoadBlockLever3 = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XRoadBlock = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XFrontCarAttention = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XFrontCarAttentionLeft = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enV2XFrontCarAttentionRight = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAttentionWaterRoad = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAttentionLowlyingRoad = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAttentionWetRoad = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAttentionSharpTurn = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enNoteRoadFailure = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enNoteUnevenRoad = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAttentionDangerousRoad = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAwareDebrisFlow = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enNoteBridge = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAttentionTunnel = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAwareFire = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enNoteFallingRock = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enNoteIcyRoad = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enNoteCrosswindRoad = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enEmbankmentRoad = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enNoteContinuousSharpTurn = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enNoteRoadNarrows = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enNoteIncomingTraffic = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enNotedamgeRoadFacities = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAwareScatteredObject = WN_enDISPLAY_OFF;
	
    //Byte84 Bit1-bit0 
    uint8 configV2X = 0;
	
    uint8 V2X_FCW = 0;
    uint8 Rte_V2X_FCW = RTE_E_INVALID;
    uint8 V2X_BSW = 0;
    uint8 Rte_V2X_BSW = RTE_E_INVALID;
    uint8 V2X_LCW = 0;
    uint8 Rte_V2X_LCW = RTE_E_INVALID;
    uint8 V2X_EBW = 0;
    uint8 Rte_V2X_EBW = RTE_E_INVALID;
    uint8 V2X_ICW = 0;
    uint8 Rte_V2X_ICW = RTE_E_INVALID;
    uint8 V2X_LTA = 0;
    uint8 Rte_V2X_LTA = RTE_E_INVALID;
    uint8 V2X_AVW = 0;
    uint8 Rte_V2X_AVW = RTE_E_INVALID;
    uint8 V2X_EVW = 0;
    uint8 Rte_V2X_EVW = RTE_E_INVALID;
    uint8 V2X_CLW = 0;
    uint8 Rte_V2X_CLW = RTE_E_INVALID;
    uint8 V2X_VRUCW = 0;
    uint8 Rte_V2X_VRUCW = RTE_E_INVALID;
    uint8 V2X_DNPW = 0;
    uint8 Rte_V2X_DNPW = RTE_E_INVALID;
    uint8 V2X_HLW = 0;
    uint8 Rte_V2X_HLW = RTE_E_INVALID;
    uint8 V2X_TJW = 0;
    uint8 Rte_V2X_TJW = RTE_E_INVALID;

    configV2X = (uint8)WN_GetSingleConfig(WN_enCfg_V2X);
    Rte_V2X_FCW = WN_V2X_FCW_SignalGet(&V2X_FCW);
    Rte_V2X_BSW = WN_V2X_BSW_SignalGet(&V2X_BSW);
    Rte_V2X_LCW = WN_V2X_LCW_SignalGet(&V2X_LCW);
    Rte_V2X_EBW = WN_V2X_EBW_SignalGet(&V2X_EBW);
    Rte_V2X_ICW = WN_V2X_ICW_SignalGet(&V2X_ICW);
    Rte_V2X_LTA = WN_V2X_LTA_SignalGet(&V2X_LTA);
    Rte_V2X_AVW = WN_V2X_AVW_SignalGet(&V2X_AVW);
    Rte_V2X_EVW = WN_V2X_EVW_SignalGet(&V2X_EVW);
    Rte_V2X_CLW = WN_V2X_CLW_SignalGet(&V2X_CLW);
    Rte_V2X_VRUCW = WN_V2X_VRUCW_SignalGet(&V2X_VRUCW);
    Rte_V2X_DNPW = WN_V2X_DNPW_SignalGet(&V2X_DNPW);
    Rte_V2X_HLW = WN_V2X_HLW_SignalGet(&V2X_HLW);
    Rte_V2X_TJW = WN_V2X_TJW_SignalGet(&V2X_TJW);

    if(configV2X == 1)
    {
        //1.250
        if((RTE_E_OK == Rte_V2X_FCW) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_V2X_FCW))
        {
            if(V2X_FCW == 0x1)
            {
                enV2XCarDistance = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            /* do nothing */
        }
        //1.251
        if((RTE_E_OK == Rte_V2X_BSW) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_V2X_BSW))
        {
            if(V2X_BSW == 0x1)
            {
                enV2XBackCarLeft = WN_enDISPLAY_ON;
            }
            else if(V2X_BSW == 0x2)
            {
                enV2XBackCarRight = WN_enDISPLAY_ON;
            }
            else if(V2X_BSW == 0x3)
            {
                enV2XBackCarTwoSide = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            /* do nothing */
        }
        //1.252
        if((RTE_E_OK == Rte_V2X_LCW) || 
          (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_V2X_LCW))
        {
            if(V2X_LCW == 0x1)
            {
                enV2XLeftLine = WN_enDISPLAY_ON;
            }
            else if(V2X_LCW == 0x2)
            {
                enV2XRightLine = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            /* do nothing */
        }
        //1.253
        if((RTE_E_OK == Rte_V2X_EBW) || 
          (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_V2X_EBW))
        {
            if(V2X_EBW == 0x1)
            {
                enV2XFrontCarAEB = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            /* do nothing */
        }
        //1.254
        if((RTE_E_OK == Rte_V2X_ICW) || 
          (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_V2X_ICW))
        {
            if(V2X_ICW == 0x1)
            {
                enV2XSideCarLeft = WN_enDISPLAY_ON;
            }
            else if(V2X_ICW == 0x2)
            {
                enV2XSideCarRight = WN_enDISPLAY_ON;
            }
            else if(V2X_ICW == 0x3)
            {
                enV2XSideCarTwoSide = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            /* do nothing */
        }
        //1.255
        if((RTE_E_OK == Rte_V2X_LTA) || 
          (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_V2X_LTA))
        {
            if(V2X_LTA == 0x1)
            {
                enV2XFaceCar = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            /* do nothing */
        }
        //1.256
        if((RTE_E_OK == Rte_V2X_AVW) || 
          (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_V2X_AVW))
        {
            if(V2X_AVW == 0x1)
            {
                enV2XFrontCarAttentionLeft = WN_enDISPLAY_ON;
            }
            else if(V2X_AVW == 0x2)
            {
                enV2XFrontCarAttention = WN_enDISPLAY_ON;
            }
            else if(V2X_AVW == 0x3)
            {
                enV2XFrontCarAttentionRight = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            /* do nothing */
        }
        //1.257
        if((RTE_E_OK == Rte_V2X_EVW) || 
          (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_V2X_EVW))
        {
            if(V2X_EVW == 0x1)
            {
                enV2XLeaveCar = WN_enDISPLAY_ON;
            }
            else if(V2X_EVW == 0x2)
            {
                enV2XLeaveFireCar = WN_enDISPLAY_ON;
            }
            else if(V2X_EVW == 0x3)
            {
                enV2XLeaveAmbulance = WN_enDISPLAY_ON; 
            }
            else if(V2X_EVW == 0x4)
            {
                enV2XLeavePolice  = WN_enDISPLAY_ON;
            }
            else if(V2X_EVW == 0x5)
            {
                enV2XLeaveEngCar  = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
             /* do nothing */
        }
        //1.258
        if((RTE_E_OK == Rte_V2X_CLW) || 
          (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_V2X_CLW))
        {
            if(V2X_CLW == 0x1)
            {
                enV2XFrontCarUnContron = WN_enDISPLAY_ON;
            }
            else if(V2X_CLW == 0x2)
            {
                enV2XBackCarUnContron = WN_enDISPLAY_ON;
            }
            else if(V2X_CLW == 0x3)
            {
                enV2XAroundCarUnContron = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            /* do nothing */
        }
        //1.259
        if((RTE_E_OK == Rte_V2X_VRUCW) || 
          (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_V2X_VRUCW))
        {
            if(V2X_VRUCW == 0x1)
            {
                enV2XPeopleLeft = WN_enDISPLAY_ON;
            }
            else if(V2X_VRUCW == 0x2)
            {
                enV2XPeopleMid = WN_enDISPLAY_ON;
            }
            else if(V2X_VRUCW == 0x3)
            {
                enV2XPeopleRight = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            /* do nothing */
        }
        //1.261
        if((RTE_E_OK == Rte_V2X_DNPW) || 
          (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_V2X_DNPW))
        {
            if(V2X_DNPW == 1)
            {
                enV2XReverseLine = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            /* do nothing */
        }
        //1.262
        if((RTE_E_OK == Rte_V2X_HLW) || 
          (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_V2X_HLW))
        {
            if(V2X_HLW == 0x1)
            {
                enAttentionWaterRoad = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0x1;
            }
            else if(V2X_HLW == 0x2)
            {
                enAttentionLowlyingRoad = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0x2;
            }
            else if(V2X_HLW == 0x3)
            {
                enAttentionWetRoad = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0x3;
            }
            else if(V2X_HLW == 0x4)
            {
                enAttentionSharpTurn = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0x4;
            }
            else if(V2X_HLW == 0x5)
            {
                enNoteRoadFailure = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0x5;
            }
            else if(V2X_HLW == 0x6)
            {
                enNoteUnevenRoad = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0x6;
            }
            else if(V2X_HLW == 0x7)
            {
                enAttentionDangerousRoad = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0x7;
            }
            else if(V2X_HLW == 0x8)
            {
                enAwareDebrisFlow = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0x8;
            }
            else if(V2X_HLW == 0x9)
            {
                enNoteBridge = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0x9;
            }
            else if(V2X_HLW == 0xA)
            {
                enAttentionTunnel = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0xA;
            }
            else if(V2X_HLW == 0xB)
            {
                enAwareFire = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0xB;
            }
            else if(V2X_HLW == 0xC)
            {
                enNoteFallingRock = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0xC;
            }
            else if(V2X_HLW == 0xD)
            {
                enNoteIcyRoad = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0xD;
            }
            else if(V2X_HLW == 0xE)
            {
                enNoteCrosswindRoad = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0xE;
            }
            else if(V2X_HLW == 0xF)
            {
                enEmbankmentRoad = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0xF;
            }
            else if(V2X_HLW == 0x10)
            {
                enNoteContinuousSharpTurn = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0x10;
            }
            else if(V2X_HLW == 0x11)
            {
                enNoteRoadNarrows = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0x11;
            }
            else if(V2X_HLW == 0x12)
            {
                enNoteIncomingTraffic = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0x12;
            }
            else if(V2X_HLW == 0x13)
            {
                enNotedamgeRoadFacities = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0x13;
            }
            else if(V2X_HLW == 0x14)
            {
                enAwareScatteredObject = WN_enDISPLAY_ON;
                m_V2XFrontRoadData = 0x14;
            }
            else
            {
                m_V2XFrontRoadData = 0x0;
            }
        }
        else
        {
            m_V2XFrontRoadData = 0x0;
        }
        //1.264
        if((RTE_E_OK == Rte_V2X_TJW) || 
          (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_V2X_TJW))
        {
            if(V2X_TJW == 0x1)
            {
                enV2XRoadBlockLever1 = WN_enDISPLAY_ON;
            }
            else if(V2X_TJW == 0x2)
            {
                enV2XRoadBlockLever2 = WN_enDISPLAY_ON;
            }
            else if(V2X_TJW == 0x3)
            {
                enV2XRoadBlockLever3 = WN_enDISPLAY_ON;
            }
            else if(V2X_TJW == 0x4)
            {
                enV2XRoadBlock = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }
    WN_SET(WN_enV2XCarDistance, enV2XCarDistance);
    WN_SET(WN_enV2XBackCarLeft, enV2XBackCarLeft);
    WN_SET(WN_enV2XBackCarRight, enV2XBackCarRight);
    WN_SET(WN_enV2XBackCarTwoSide, enV2XBackCarTwoSide);
    WN_SET(WN_enV2XLeftLine, enV2XLeftLine);
    WN_SET(WN_enV2XRightLine, enV2XRightLine);
    WN_SET(WN_enV2XFrontCarAEB, enV2XFrontCarAEB);
    WN_SET(WN_enV2XSideCarTwoSide, enV2XSideCarTwoSide);
    WN_SET(WN_enV2XSideCarRight, enV2XSideCarRight);
    WN_SET(WN_enV2XSideCarLeft, enV2XSideCarLeft);
    WN_SET(WN_enV2XFaceCar, enV2XFaceCar);
    WN_SET(WN_enV2XLeaveCar, enV2XLeaveCar);
    WN_SET(WN_enV2XLeaveFireCar, enV2XLeaveFireCar);
    WN_SET(WN_enV2XLeaveAmbulance, enV2XLeaveAmbulance);
    WN_SET(WN_enV2XLeavePolice, enV2XLeavePolice);
    WN_SET(WN_enV2XLeaveEngCar, enV2XLeaveEngCar);
    WN_SET(WN_enV2XFrontCarUnContron, enV2XFrontCarUnContron);
    WN_SET(WN_enV2XBackCarUnContron, enV2XBackCarUnContron);
    WN_SET(WN_enV2XAroundCarUnContron, enV2XAroundCarUnContron);
    WN_SET(WN_enV2XPeopleRight, enV2XPeopleRight);
    WN_SET(WN_enV2XPeopleMid, enV2XPeopleMid);
    WN_SET(WN_enV2XPeopleLeft, enV2XPeopleLeft);
    WN_SET(WN_enV2XReverseLine, enV2XReverseLine);
    WN_SET(WN_enV2XRoadBlockLever1, enV2XRoadBlockLever1);
    WN_SET(WN_enV2XRoadBlockLever2, enV2XRoadBlockLever2);
    WN_SET(WN_enV2XRoadBlockLever3, enV2XRoadBlockLever3);
    WN_SET(WN_enV2XRoadBlock, enV2XRoadBlock);
    WN_SET(WN_enV2XFrontCarAttention, enV2XFrontCarAttention);
    WN_SET(WN_enV2XFrontCarAttentionLeft, enV2XFrontCarAttentionLeft);
    WN_SET(WN_enV2XFrontCarAttentionRight, enV2XFrontCarAttentionRight);
    WN_SET(WN_enAttentionWaterRoad, enAttentionWaterRoad);
    WN_SET(WN_enAttentionLowlyingRoad, enAttentionLowlyingRoad);
    WN_SET(WN_enAttentionWetRoad, enAttentionWetRoad);
    WN_SET(WN_enAttentionSharpTurn, enAttentionSharpTurn);
    WN_SET(WN_enNoteRoadFailure, enNoteRoadFailure);
    WN_SET(WN_enNoteUnevenRoad, enNoteUnevenRoad);
    WN_SET(WN_enAttentionDangerousRoad, enAttentionDangerousRoad);
    WN_SET(WN_enAwareDebrisFlow, enAwareDebrisFlow);
    WN_SET(WN_enNoteBridge, enNoteBridge);
    WN_SET(WN_enAttentionTunnel, enAttentionTunnel);
    WN_SET(WN_enAwareFire, enAwareFire);
    WN_SET(WN_enNoteFallingRock, enNoteFallingRock);
    WN_SET(WN_enNoteIcyRoad, enNoteIcyRoad);
    WN_SET(WN_enNoteCrosswindRoad, enNoteCrosswindRoad);
    WN_SET(WN_enEmbankmentRoad, enEmbankmentRoad);
    WN_SET(WN_enNoteContinuousSharpTurn, enNoteContinuousSharpTurn);
    WN_SET(WN_enNoteRoadNarrows, enNoteRoadNarrows);
    WN_SET(WN_enNoteIncomingTraffic, enNoteIncomingTraffic);
    WN_SET(WN_enNotedamgeRoadFacities, enNotedamgeRoadFacities);
    WN_SET(WN_enAwareScatteredObject, enAwareScatteredObject);
    
}

void WN_ClutOvrHeatdProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enClutchOverheat = WN_enDISPLAY_OFF;
    
    //TBD
    uint8 ECM_ClutovrheatdSts = 0;
    uint8 Rte_ECM_ClutovrheatdSts = RTE_E_INVALID;
    //Byte3 Bit7-bit0
	uint8 configTransmission = 0;
	
    configTransmission = (uint8)WN_GetSingleConfig(WN_enCfg_Transmission);
    Rte_ECM_ClutovrheatdSts = WN_ECM_ClutovrheatdSts_SignalGet(&ECM_ClutovrheatdSts);//TBD
	//Modify bug P05-4770
    if((configTransmission == 0x1) || (configTransmission == 0xC) || (configTransmission == 0x2)\
		|| (configTransmission == 0xD) || (configTransmission == 0x25) || (configTransmission == 0xE))
    {
        //1.270
        if((RTE_E_OK == Rte_ECM_ClutovrheatdSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_ECM_ClutovrheatdSts))
        {
            if(ECM_ClutovrheatdSts == 0x1)
            {
                enClutchOverheat = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }
    WN_SET(WN_enClutchOverheat, enClutchOverheat);
}

void WN_Oillevel_alarm(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enOilLeverLow = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enOilLeverHigh = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enOilLeverFault = WN_enDISPLAY_OFF;
    
    //Byte98 Bit5-Bit3
    uint8 en_cfg_EngOil_level = 0;
    uint8 fl_EngOilLvlWrn = 0;
    uint8 Rte_EngOilLvlWrn = RTE_E_INVALID;

    en_cfg_EngOil_level = (uint8)WN_GetSingleConfig(WN_encfg_OilLevel);
    Rte_EngOilLvlWrn = WN_EngOilLvlWrn_SignalGet(&fl_EngOilLvlWrn);//TBD

    //1.288
    if((en_cfg_EngOil_level == 1) || (en_cfg_EngOil_level == 2) || (en_cfg_EngOil_level == 3))//R12
    {
        if((RTE_E_OK == Rte_EngOilLvlWrn) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_EngOilLvlWrn))
        {
            if(fl_EngOilLvlWrn == 0x1)
            {
                enOilLeverLow = WN_enDISPLAY_ON;
            }
            else if(fl_EngOilLvlWrn == 0x2)
            {
                enOilLeverHigh = WN_enDISPLAY_ON;
            }
            else if(fl_EngOilLvlWrn == 0x3)
            {
                enOilLeverFault = WN_enDISPLAY_ON;
            }
            else
            {}
        }
    }
    WN_SET(WN_enOilLeverLow, enOilLeverLow);
    WN_SET(WN_enOilLeverHigh, enOilLeverHigh);
    WN_SET(WN_enOilLeverFault, enOilLeverFault);
}

void WN_Active_sulphur_removal( WN_CFG_tstMAIN_OBJECT *stMainObject )
{
	WN_CFG_enSTATUS_Common enCatalystSuHigh = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enSuClearing = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enSuClearDown = WN_enDISPLAY_OFF;
    //Byte2 Bit7-bit4
    uint8 en_cfg_Fuel_type = 0;
    uint8 fl_LNT_Warning = 0;
    uint8 Rte_LNT_Warning = RTE_E_INVALID;

    en_cfg_Fuel_type = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    Rte_LNT_Warning = WN_LNT_Warning_SignalGet(&fl_LNT_Warning);//TBD

    if(en_cfg_Fuel_type == 0)
    {
        //1.289
        if((RTE_E_OK == Rte_LNT_Warning) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_LNT_Warning))
        {
            if(fl_LNT_Warning == 1)
            {
                enCatalystSuHigh = WN_enDISPLAY_ON;
            }
            else if(fl_LNT_Warning == 2)
            {
                enSuClearing = WN_enDISPLAY_ON;
            }
            else if(fl_LNT_Warning == 3)
            {
                enSuClearDown = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
    }
    WN_SET(WN_enCatalystSuHigh, enCatalystSuHigh);
    WN_SET(WN_enSuClearing, enSuClearing);
    WN_SET(WN_enSuClearDown, enSuClearDown);
}

void HWA_Process( WN_CFG_tstMAIN_OBJECT *stMainObject )
{
    WN_CFG_enSTATUS_Common enMoveRampFailHandWheel = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enMoveRampFailHandWheel_2Hz = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enMoveRampFailPlsTake = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enMoveMainFailHandWheel = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enMoveMainFailPlsTake = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enMoveMainFailPlsTake_2Hz = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enMoveMainFailPlsTake_4Hz = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTurnFailPlsHandWheel = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTurnFailPlsTake = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTurnFailPlsTake_2Hz = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTurnFailPlsTake_4Hz = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTollGateFailPlsHandWheel = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTollGateFailPlsTake = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTollGateFailPlsTake_2Hz = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enTollGateFailPlsTake_4Hz = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRoundaboutFailPlsHandWheel = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRoundaboutFailPlsTake = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRoundaboutFailPlsTake_2Hz = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRoundaboutFailPlsTake_4Hz = WN_enDISPLAY_OFF;
    //WN_CFG_enSTATUS_Common enTJAICAFaultPlsFixCamera = WN_enDISPLAY_OFF;
    //WN_CFG_enSTATUS_Common enTJAICAFaultPlsFix = WN_enDISPLAY_OFF;
    //Byte45 bit7-bit5
    uint8 fl_configHighwayAssist_U8 = 0;
    //Byte82 Bit3-Bit2
    //uint8 fl_configNOH_U8 = 0;
    uint8 fl_HWA_InterSysInfoDisp_ICU1_5 = 0;
    //uint8 Rte_HWA_InterSysInfoDisp_ICU1_5 = RTE_E_INVALID;
    uint8 fl_HWA_warning_ICU1_5 = 0;
    uint8 Rte_HWA_warning_ICU1_5 = RTE_E_INVALID;
    uint8 fl_HWA_WarnInfoDisp_ICU1_5 = 0;
    //uint8 Rte_HWA_WarnInfoDisp_ICU1_5 = RTE_E_INVALID;
    uint8 fl_HWA_TakOver_Trig_ICU1_5 = 0;
    uint8 Rte_IFC_FD3 = RTE_E_INVALID;
    uint8 fl_HWA_TakOver_Req_ICU1_5 = 0;
    uint8 f1_configTFC = 0;
    uint8 f1_HWA_WarnInfoDisp_ICU1_5 = 0;
    uint8 Rte_ACC_FD2 = RTE_E_INVALID;

    fl_configHighwayAssist_U8 = (uint8)WN_GetSingleConfig(WN_enCfg_HighwayAssist);
    f1_configTFC = (uint8)WN_GetSingleConfig(WN_encfg_TFC);
    //fl_configNOH_U8 = (uint8)WN_GetSingleConfig(WN_enCfg_NOH);

    Rte_ACC_FD2 = WN_HWA_InterSysInfoDisp_SignalGet_ICU1_5(&fl_HWA_InterSysInfoDisp_ICU1_5);
    Rte_ACC_FD2 = WN_HWA_warning_SignalGet_ICU1_5(&fl_HWA_warning_ICU1_5);
    //Rte_HWA_WarnInfoDisp_ICU1_5 = WN_HWA_WarnInfoDisp_SignalGet_ICU1_5(&fl_HWA_WarnInfoDisp_ICU1_5);
    Rte_IFC_FD3 = WN_HWA_TakOver_Trig_SignalGet_ICU1_5(&fl_HWA_TakOver_Trig_ICU1_5);
    Rte_IFC_FD3 = WN_HWA_TakOver_Req_SignalGet_ICU1_5(&fl_HWA_TakOver_Req_ICU1_5);
    Rte_IFC_FD3 = WN_HWA_WarnInfoDisp_SignalGet_ICU1_5(&f1_HWA_WarnInfoDisp_ICU1_5);

    //1.297
    if(fl_configHighwayAssist_U8 == 1)//R16
    {
        if(((RTE_E_OK == Rte_ACC_FD2) || \
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_ACC_FD2)) && \
            ((RTE_E_OK == Rte_IFC_FD3) || \
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_IFC_FD3)))
        {
            if(fl_HWA_TakOver_Trig_ICU1_5 == 0x1)
            {
                if((fl_HWA_TakOver_Req_ICU1_5 == 0x1) && (fl_HWA_warning_ICU1_5 == 0x1))
                {
                    enMoveRampFailHandWheel = WN_enDISPLAY_ON;
                }
                if((fl_HWA_TakOver_Req_ICU1_5 == 0x1) && (fl_HWA_warning_ICU1_5 == 0x2))
                {
                    enMoveRampFailHandWheel_2Hz = WN_enDISPLAY_ON;
                }
                if((fl_HWA_TakOver_Req_ICU1_5 == 0x2) && (fl_HWA_warning_ICU1_5 == 0x3))
                {
                    enMoveRampFailPlsTake = WN_enDISPLAY_ON;
                }
            }
            else if(fl_HWA_TakOver_Trig_ICU1_5 == 0x2)
            {
                if((fl_HWA_TakOver_Req_ICU1_5 == 0x1) && (fl_HWA_warning_ICU1_5 == 0x1))
                {
                    enMoveMainFailHandWheel = WN_enDISPLAY_ON;
                }
                if(fl_HWA_TakOver_Req_ICU1_5 == 0x2)
                {
                    if(fl_HWA_warning_ICU1_5 == 0x1)
                    {
                        enMoveMainFailPlsTake = WN_enDISPLAY_ON;
                    }
                    else if(fl_HWA_warning_ICU1_5 == 0x2)
                    {
                        enMoveMainFailPlsTake_2Hz = WN_enDISPLAY_ON;
                    }
                    else if(fl_HWA_warning_ICU1_5 == 0x3)
                    {
                        enMoveMainFailPlsTake_4Hz = WN_enDISPLAY_ON;
                    }
                }
            }
            else if(fl_HWA_TakOver_Trig_ICU1_5 == 0x3)
            {
                if((fl_HWA_TakOver_Req_ICU1_5 == 0x1) && (fl_HWA_warning_ICU1_5 == 0x1))
                {
                    enTurnFailPlsHandWheel = WN_enDISPLAY_ON;
                }
                if(fl_HWA_TakOver_Req_ICU1_5 == 0x2)
                {
                    if(fl_HWA_warning_ICU1_5 == 0x1)
                    {
                        enTurnFailPlsTake = WN_enDISPLAY_ON;
                    }
                    else if(fl_HWA_warning_ICU1_5 == 0x2)
                    {
                        enTurnFailPlsTake_2Hz = WN_enDISPLAY_ON;
                    }
                    else if(fl_HWA_warning_ICU1_5 == 0x3)
                    {
                        enTurnFailPlsTake_4Hz = WN_enDISPLAY_ON;
                    }
                    else
                    {}
                }
            }
            else if(fl_HWA_TakOver_Trig_ICU1_5 == 0x4)
            {
                if((fl_HWA_TakOver_Req_ICU1_5 == 0x1) && (fl_HWA_warning_ICU1_5 == 0x1))
                {
                    enTollGateFailPlsHandWheel = WN_enDISPLAY_ON;
                }
                if(fl_HWA_TakOver_Req_ICU1_5 == 0x2)
                {
                    if(fl_HWA_warning_ICU1_5 == 0x1)
                    {
                        enTollGateFailPlsTake = WN_enDISPLAY_ON;
                    }
                    else if(fl_HWA_warning_ICU1_5 == 0x2)
                    {
                        enTollGateFailPlsTake_2Hz = WN_enDISPLAY_ON;
                    }
                    else if(fl_HWA_warning_ICU1_5 == 0x3)
                    {
                        enTollGateFailPlsTake_4Hz = WN_enDISPLAY_ON;
                    }
                    else
                    {}
                }
            }
            else if(fl_HWA_TakOver_Trig_ICU1_5 == 0x5)
            {
                if((fl_HWA_TakOver_Req_ICU1_5 == 0x1) && (fl_HWA_warning_ICU1_5 == 0x1))
                {
                    enRoundaboutFailPlsHandWheel = WN_enDISPLAY_ON;
                }
                if(fl_HWA_TakOver_Req_ICU1_5 == 0x2)
                {
                    if(fl_HWA_warning_ICU1_5 == 0x1)
                    {
                        enRoundaboutFailPlsTake = WN_enDISPLAY_ON;
                    }
                    else if(fl_HWA_warning_ICU1_5 == 0x2)
                    {
                        enRoundaboutFailPlsTake_2Hz = WN_enDISPLAY_ON;
                    }
                    else if(fl_HWA_warning_ICU1_5 == 0x3)
                    {
                        enRoundaboutFailPlsTake_4Hz = WN_enDISPLAY_ON;
                    }
                    else
                    {}
                }
            }
            else if((f1_HWA_WarnInfoDisp_ICU1_5 == 0xD) || (fl_HWA_InterSysInfoDisp_ICU1_5 == 0xB))
            {
                if(fl_HWA_warning_ICU1_5 == 0x1)
                {
                    /* 请目视前方 */
                }
                else if(fl_HWA_warning_ICU1_5 == 0x2)
                {
                    /* 请目视前方 */
                }
                else if(fl_HWA_warning_ICU1_5 == 0x3)
                {
                    /* 请目视前方 */
                }
                else
                {}
            }
            else if((fl_HWA_TakOver_Trig_ICU1_5 == 0x0) && (fl_HWA_TakOver_Req_ICU1_5 == 0x2))
            {
                if(fl_HWA_warning_ICU1_5 == 0x1)
                {
                    /* 请立即接管 */
                }
                else if(fl_HWA_warning_ICU1_5 == 0x2)
                {
                    /* 请立即接管 */
                }
                else if(fl_HWA_warning_ICU1_5 == 0x3)
                {
                    /* 请立即接管 */
                }
                else
                {}
            }
            else
            {}
        }

    }
#ifdef GWM_V35_PROJECT_TYPE_D01
    else if((fl_configHighwayAssist_U8 == 1) && (0x4 == f1_configTFC))
    {
        //1.304
        if(((RTE_E_OK == Rte_IFC_FD3) || \
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_IFC_FD3)) && \
            ((RTE_E_OK == Rte_HWA_warning_ICU1_5) || \
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_HWA_warning_ICU1_5)))
        {
            if(fl_HWA_TakOver_Trig_ICU1_5 == 0x1)
            {
                if((fl_HWA_TakOver_Req_ICU1_5 == 0x1) && (fl_HWA_warning_ICU1_5 == 0x1))
                {
                    enMoveRampFailHandWheel = WN_enDISPLAY_ON;
                }
                if((fl_HWA_TakOver_Req_ICU1_5 == 0x1) && (fl_HWA_warning_ICU1_5 == 0x2))
                {
                    enMoveRampFailHandWheel_2Hz = WN_enDISPLAY_ON;
                }
                if((fl_HWA_TakOver_Req_ICU1_5 == 0x2) && (fl_HWA_warning_ICU1_5 == 0x3))
                {
                    enMoveRampFailPlsTake = WN_enDISPLAY_ON;
                }
            }
            else if(fl_HWA_TakOver_Trig_ICU1_5 == 0x2)
            {
                if((fl_HWA_TakOver_Req_ICU1_5 == 0x1) && (fl_HWA_warning_ICU1_5 == 0x1))
                {
                    enMoveMainFailHandWheel = WN_enDISPLAY_ON;
                }
                if(fl_HWA_TakOver_Req_ICU1_5 == 0x2)
                {
                    if(fl_HWA_warning_ICU1_5 == 0x1)
                    {
                        enMoveMainFailPlsTake = WN_enDISPLAY_ON;
                    }
                    else if(fl_HWA_warning_ICU1_5 == 0x2)
                    {
                        enMoveMainFailPlsTake_2Hz = WN_enDISPLAY_ON;
                    }
                    else if(fl_HWA_warning_ICU1_5 == 0x3)
                    {
                        enMoveMainFailPlsTake_4Hz = WN_enDISPLAY_ON;
                    }
                }
            }
            else if(fl_HWA_TakOver_Trig_ICU1_5 == 0x3)
            {
                if((fl_HWA_TakOver_Req_ICU1_5 == 0x1) && (fl_HWA_warning_ICU1_5 == 0x1))
                {
                    enTurnFailPlsHandWheel = WN_enDISPLAY_ON;
                }
                if(fl_HWA_TakOver_Req_ICU1_5 == 0x2)
                {
                    if(fl_HWA_warning_ICU1_5 == 0x1)
                    {
                        enTurnFailPlsTake = WN_enDISPLAY_ON;
                    }
                    else if(fl_HWA_warning_ICU1_5 == 0x2)
                    {
                        enTurnFailPlsTake_2Hz = WN_enDISPLAY_ON;
                    }
                    else if(fl_HWA_warning_ICU1_5 == 0x3)
                    {
                        enTurnFailPlsTake_4Hz = WN_enDISPLAY_ON;
                    }
                    else
                    {}
                }
            }
            else if(fl_HWA_TakOver_Trig_ICU1_5 == 0x4)
            {
                if((fl_HWA_TakOver_Req_ICU1_5 == 0x1) && (fl_HWA_warning_ICU1_5 == 0x1))
                {
                    enTollGateFailPlsHandWheel = WN_enDISPLAY_ON;
                }
                if(fl_HWA_TakOver_Req_ICU1_5 == 0x2)
                {
                    if(fl_HWA_warning_ICU1_5 == 0x1)
                    {
                        enTollGateFailPlsTake = WN_enDISPLAY_ON;
                    }
                    else if(fl_HWA_warning_ICU1_5 == 0x2)
                    {
                        enTollGateFailPlsTake_2Hz = WN_enDISPLAY_ON;
                    }
                    else if(fl_HWA_warning_ICU1_5 == 0x3)
                    {
                        enTollGateFailPlsTake_4Hz = WN_enDISPLAY_ON;
                    }
                    else
                    {}
                }
            }
            else if(fl_HWA_TakOver_Trig_ICU1_5 == 0x5)
            {
                if((fl_HWA_TakOver_Req_ICU1_5 == 0x1) && (fl_HWA_warning_ICU1_5 == 0x1))
                {
                    enRoundaboutFailPlsHandWheel = WN_enDISPLAY_ON;
                }
                if(fl_HWA_TakOver_Req_ICU1_5 == 0x2)
                {
                    if(fl_HWA_warning_ICU1_5 == 0x1)
                    {
                        enRoundaboutFailPlsTake = WN_enDISPLAY_ON;
                    }
                    else if(fl_HWA_warning_ICU1_5 == 0x2)
                    {
                        enRoundaboutFailPlsTake_2Hz = WN_enDISPLAY_ON;
                    }
                    else if(fl_HWA_warning_ICU1_5 == 0x3)
                    {
                        enRoundaboutFailPlsTake_4Hz = WN_enDISPLAY_ON;
                    }
                    else
                    {}
                }
            }
            else
            {}
        }
    }
#else
#endif

    WN_SET(WN_enMoveRampFailHandWheel, enMoveRampFailHandWheel);
    WN_SET(WN_enMoveRampFailHandWheel_2Hz, enMoveRampFailHandWheel_2Hz);
    WN_SET(WN_enMoveRampFailPlsTake, enMoveRampFailPlsTake);
    WN_SET(WN_enMoveMainFailHandWheel, enMoveMainFailHandWheel);
    WN_SET(WN_enMoveMainFailPlsTake, enMoveMainFailPlsTake);
    WN_SET(WN_enMoveMainFailPlsTake_2Hz, enMoveMainFailPlsTake_2Hz);
    WN_SET(WN_enMoveMainFailPlsTake_4Hz, enMoveMainFailPlsTake_4Hz);
    WN_SET(WN_enTurnFailPlsHandWheel, enTurnFailPlsHandWheel);
    WN_SET(WN_enTurnFailPlsTake, enTurnFailPlsTake);
    WN_SET(WN_enTurnFailPlsTake_2Hz, enTurnFailPlsTake_2Hz);
    WN_SET(WN_enTurnFailPlsTake_4Hz, enTurnFailPlsTake_4Hz);
    WN_SET(WN_enTollGateFailPlsHandWheel, enTollGateFailPlsHandWheel);
    WN_SET(WN_enTollGateFailPlsTake, enTollGateFailPlsTake);
    WN_SET(WN_enTollGateFailPlsTake_2Hz, enTollGateFailPlsTake_2Hz);
    WN_SET(WN_enTollGateFailPlsTake_4Hz, enTollGateFailPlsTake_4Hz);
    WN_SET(WN_enRoundaboutFailPlsHandWheel, enRoundaboutFailPlsHandWheel);
    WN_SET(WN_enRoundaboutFailPlsTake, enRoundaboutFailPlsTake);
    WN_SET(WN_enRoundaboutFailPlsTake_2Hz, enRoundaboutFailPlsTake_2Hz);
    WN_SET(WN_enRoundaboutFailPlsTake_4Hz, enRoundaboutFailPlsTake_4Hz);
}

void WN_FourWheel_Drive_Locked( WN_CFG_tstMAIN_OBJECT *stMainObject )
{
	WN_CFG_enSTATUS_Common enExcessiveSpeedFourWheelDrive = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enFourWheelDriveSystem = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enCurrentTerrainCannotUnlocked = WN_enDISPLAY_OFF;
    //Byte30 Bit3-bit0
    uint8 en_cfg_EAE_type = 0;

    uint8 fl_AutoShiftSts = 0;
    uint8 Rte_AutoShiftSts = RTE_E_INVALID;
    uint8 fl_MidELDLckSwtReq = 0;
    uint8 Rte_MidELDLckSwtReq = RTE_E_INVALID;
    uint8 fl_SystemOperMod = 0;
    uint8 Rte_SystemOperMod = RTE_E_INVALID;

    en_cfg_EAE_type = (uint8)WN_GetSingleConfig(WN_enCfg_EAE);
    Rte_AutoShiftSts = WN_AutoShiftSts_SignalGet(&fl_AutoShiftSts);
    Rte_MidELDLckSwtReq = WN_MidELDLckSwtReq_SignalGet(&fl_MidELDLckSwtReq);
    Rte_SystemOperMod = WN_SystemOperMod_SignalGet(&fl_SystemOperMod);

    if(en_cfg_EAE_type == 5)
    {
        //1.301
        if((RTE_E_OK == Rte_AutoShiftSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_AutoShiftSts))
        {
            if(fl_AutoShiftSts == 1)
            {
                enExcessiveSpeedFourWheelDrive = WN_enDISPLAY_ON;
            }
            else if(fl_AutoShiftSts == 2)
            {
                enFourWheelDriveSystem = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
        //1.380
        if(((RTE_E_OK == Rte_MidELDLckSwtReq) || \
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_MidELDLckSwtReq)) && \
            ((RTE_E_OK == Rte_SystemOperMod) || \
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SystemOperMod)))
        {
            if(((fl_SystemOperMod == 0x3) || (fl_SystemOperMod == 0x6)) && (fl_MidELDLckSwtReq == 0x1))
            {
                enCurrentTerrainCannotUnlocked = WN_enDISPLAY_ON;
            }
        }
    }
    WN_SET(WN_enExcessiveSpeedFourWheelDrive, enExcessiveSpeedFourWheelDrive);
    WN_SET(WN_enFourWheelDriveSystem, enFourWheelDriveSystem);
    WN_SET(WN_enCurrentTerrainCannotUnlocked, enCurrentTerrainCannotUnlocked);
}

void WN_Navigation_Speed_Down( WN_CFG_tstMAIN_OBJECT *stMainObject )
{
	WN_CFG_enSTATUS_Common enNavigationSlowDownActive = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enPlsPayAttentionToSlowDown = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enSpeedLimitForward60kmPerHour = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSpeedLimitForward70kmPerHour = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enSPeedLimitForward80kmPerHour = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enSpeedLimitForward90kmPerHour = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSpeedLimitForward100kmPerHour = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enSpeedLimitForward110kmPerHour = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enSpeedLimitForward120kmPerHour = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enCurrentlyExceedNavigationLimit = WN_enDISPLAY_OFF;
    //Byte110 Bit3-bit2
    uint8 en_cfg_VDH_type = 0;
    //Byte103 Bit7-bit5
    uint8 en_cfg_TFC_type = 0;

    uint8 fl_NavDecActive = 0;
    uint8 Rte_NavDecActive = RTE_E_INVALID;

    en_cfg_VDH_type = (uint8)WN_GetSingleConfig(WN_encfg_VDH);
    en_cfg_TFC_type = (uint8)WN_GetSingleConfig(WN_encfg_TFC);
    Rte_NavDecActive = WN_Navigation_Speed_Down_SignalGet(&fl_NavDecActive);

    if ((en_cfg_VDH_type == 1) && ((en_cfg_TFC_type == 1) || (en_cfg_TFC_type == 2) || (en_cfg_TFC_type == 3)))
    {
        //1.302
        if((RTE_E_OK == Rte_NavDecActive) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_NavDecActive))
        {
            if(fl_NavDecActive == 1)
            {
                enNavigationSlowDownActive = WN_enDISPLAY_ON;
            }
            else if(fl_NavDecActive == 2)
            {
                enPlsPayAttentionToSlowDown = WN_enDISPLAY_ON;
            }
            else if(fl_NavDecActive == 3)
            {
                enSpeedLimitForward60kmPerHour = WN_enDISPLAY_ON;
            }
            else if(fl_NavDecActive == 4)
            {
                enSpeedLimitForward70kmPerHour = WN_enDISPLAY_ON;
            }
            else if(fl_NavDecActive == 5)
            {
                enSPeedLimitForward80kmPerHour = WN_enDISPLAY_ON;
            }
            else if(fl_NavDecActive == 6)
            {
                enSpeedLimitForward90kmPerHour = WN_enDISPLAY_ON;
            }
            else if(fl_NavDecActive == 7)
            {
                enSpeedLimitForward100kmPerHour = WN_enDISPLAY_ON;
            }
            else if(fl_NavDecActive == 8)
            {
                enSpeedLimitForward110kmPerHour = WN_enDISPLAY_ON;
            }
            else if(fl_NavDecActive == 9)
            {
                enSpeedLimitForward120kmPerHour = WN_enDISPLAY_ON;
            }
            else if(fl_NavDecActive == 'A')
            {
                enCurrentlyExceedNavigationLimit = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
    }
    WN_SET(WN_enNavigationSlowDownActive, enNavigationSlowDownActive);
    WN_SET(WN_enPlsPayAttentionToSlowDown, enPlsPayAttentionToSlowDown);
    WN_SET(WN_enSpeedLimitForward60kmPerHour, enSpeedLimitForward60kmPerHour);
    WN_SET(WN_enSpeedLimitForward70kmPerHour, enSpeedLimitForward70kmPerHour);
    WN_SET(WN_enSPeedLimitForward80kmPerHour, enSPeedLimitForward80kmPerHour);
    WN_SET(WN_enSpeedLimitForward90kmPerHour, enSpeedLimitForward90kmPerHour);
    WN_SET(WN_enSpeedLimitForward100kmPerHour, enSpeedLimitForward100kmPerHour);
    WN_SET(WN_enSpeedLimitForward110kmPerHour, enSpeedLimitForward110kmPerHour);
    WN_SET(WN_enSpeedLimitForward120kmPerHour, enSpeedLimitForward120kmPerHour);
    WN_SET(WN_enCurrentlyExceedNavigationLimit, enCurrentlyExceedNavigationLimit);
}

void WN_Electric_Charging_Prompt( WN_CFG_tstMAIN_OBJECT *stMainObject )
{
	WN_CFG_enSTATUS_Common enQuickChargeFlapOpenPicture = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSlowFillingFlapOpenPicture = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSlowFillingFlapNotClosed = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enQuickChargeFlapNotClosed = WN_enDISPLAY_OFF;
    
    //Byte111 Bit7-bit6
    uint8 en_cfg_ChargingFlap_type = 0;

    uint8 fl_FastChrgnLidSts = 0;
    uint8 Rte_FastChrgnLidSts = RTE_E_INVALID;
    uint8 fl_SlowChrgnLidSts = 0;
    uint8 Rte_SlowChrgnLidSts = RTE_E_INVALID;
    uint8 fl_FastChrgnLidAlarm = 0;
    uint8 Rte_FastChrgnLidAlarm = RTE_E_INVALID;
    uint8 fl_SlowChrgnLidAlarm = 0;
    uint8 Rte_SlowChrgnLidAlarm = RTE_E_INVALID;

    en_cfg_ChargingFlap_type = (uint8)WN_GetSingleConfig(WN_enCfg_ChargingFlap);
    Rte_FastChrgnLidSts = WN_FastChrgnLidSts_SignalGet(&fl_FastChrgnLidSts);
    Rte_SlowChrgnLidSts = WN_SlowChrgnLidSts_SignalGet(&fl_SlowChrgnLidSts);
    Rte_FastChrgnLidAlarm = WN_FastChrgnLidAlarm_SignalGet(&fl_FastChrgnLidAlarm);
    Rte_SlowChrgnLidAlarm = WN_SlowChrgnLidAlarm_SignalGet(&fl_SlowChrgnLidAlarm);


    if(en_cfg_ChargingFlap_type == 2)
    {
        //1.303
        if((RTE_E_OK == Rte_FastChrgnLidSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_FastChrgnLidSts))
        {
            if(fl_FastChrgnLidSts == 1)
            {
                enQuickChargeFlapOpenPicture = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
        if((RTE_E_OK == Rte_SlowChrgnLidSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SlowChrgnLidSts))
        {
            if(fl_SlowChrgnLidSts == 1)
            {
                enSlowFillingFlapOpenPicture = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
        if((RTE_E_OK == Rte_FastChrgnLidAlarm) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_FastChrgnLidAlarm))
        {
            if(fl_FastChrgnLidAlarm == 1)
            {
                enSlowFillingFlapNotClosed = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
        if((RTE_E_OK == Rte_SlowChrgnLidAlarm) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_SlowChrgnLidAlarm))
        {
            if(fl_SlowChrgnLidAlarm == 1)
            {
                enQuickChargeFlapNotClosed = WN_enDISPLAY_ON;
            }
            else
            {
                /* do nothing */
            }
        }
    }
    WN_SET(WN_enQuickChargeFlapOpenPicture, enQuickChargeFlapOpenPicture);
    WN_SET(WN_enSlowFillingFlapOpenPicture, enSlowFillingFlapOpenPicture);
    WN_SET(WN_enSlowFillingFlapNotClosed, enSlowFillingFlapNotClosed);
    WN_SET(WN_enQuickChargeFlapNotClosed, enQuickChargeFlapNotClosed);
}

void Energy_recovery_Process( WN_CFG_tstMAIN_OBJECT *stMainObject )
{
    WN_CFG_enSTATUS_Common enSysFailACCDisable = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enACCPowerDisable = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enHWAACCPowerDisable = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enESPACCPowerDisable = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enACCPowerExit = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enAcceleratorPowen = WN_enDISPLAY_OFF;
    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;
    //Byte3 Bit7—bit0
    //uint8 configTransmission = 0;
    uint8 fl_PDCU_AvailabilityOfARF = 0;//TBD
    uint8 Rte_PDCU_AvailabilityOfARF = RTE_E_INVALID;
    uint8 fl_PDCU_lossenPedalPrompt = 0;//TBD
    uint8 Rte_PDCU_lossenPedalPrompt = RTE_E_INVALID;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);
    //configTransmission = (uint8)WN_GetSingleConfig(WN_enCfg_Transmission);
    Rte_PDCU_AvailabilityOfARF = WN_HCU_HP5_AvailabilityOfARF_SignalGet(&fl_PDCU_AvailabilityOfARF);
    Rte_PDCU_lossenPedalPrompt = WN_HCU_HP5_lossenPedalPrompt_SignalGet(&fl_PDCU_lossenPedalPrompt);

    //1.282
    if(((configFuel == 4) || (configFuel == 3)) && 
        (configElecPosition == 8)  )
    {
        if((RTE_E_OK == Rte_PDCU_AvailabilityOfARF) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_PDCU_AvailabilityOfARF))
        {
            if(fl_PDCU_AvailabilityOfARF == 0x1)
            {
                enSysFailACCDisable = WN_enDISPLAY_ON;
            }
            else if(fl_PDCU_AvailabilityOfARF == 0x2)
            {
                enACCPowerDisable = WN_enDISPLAY_ON;
            }
            else if(fl_PDCU_AvailabilityOfARF == 0x3)
            {
                enHWAACCPowerDisable = WN_enDISPLAY_ON;
            }
            else if(fl_PDCU_AvailabilityOfARF == 0x4)
            {
                enESPACCPowerDisable = WN_enDISPLAY_ON;
            }
            else if(fl_PDCU_AvailabilityOfARF == 0x5)
            {
                enACCPowerExit = WN_enDISPLAY_ON;
            }
            else
            {}
        }
        if((RTE_E_OK == Rte_PDCU_lossenPedalPrompt) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_PDCU_lossenPedalPrompt))
        {
            if(fl_PDCU_lossenPedalPrompt == 0x1)
            {
                enAcceleratorPowen = WN_enDISPLAY_ON;
            }
        }
    }
    WN_SET(WN_enSysFailACCDisable, enSysFailACCDisable);
    WN_SET(WN_enACCPowerDisable, enACCPowerDisable);
    WN_SET(WN_enHWAACCPowerDisable, enHWAACCPowerDisable);
    WN_SET(WN_enESPACCPowerDisable, enESPACCPowerDisable);
    WN_SET(WN_enACCPowerExit, enACCPowerExit);
    WN_SET(WN_enAcceleratorPowen, enAcceleratorPowen);
}

void Air_Suspension_Process( WN_CFG_tstMAIN_OBJECT *stMainObject )//R12
{
    WN_CFG_enSTATUS_Common enNormalHeightSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSuitHeightSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enORHeight1Select = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enORHeight2Select = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSuspensionExtend = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSuspensionLockHeight = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enBackShaftHeightSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSuitHeightModeSelect = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSuspensionTrailer = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSuspensionLimitRise = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enKickBackShaft = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSuspensionLimitTrans = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSuspensionRise = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enCarHighPlsSlow = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSuspensionFuncLimit = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSuspensionFuncFault = WN_enDISPLAY_OFF;
//R13
    WN_CFG_enSTATUS_Common enBattLowStartEng = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSuspensionCoolDown = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enHeightModeDisable = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPlsCloseDoorRise = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enRiseModeSusLimit = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSuspensionTimeLimit = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enOverSpeedHeightDisable = WN_enDISPLAY_OFF;
    
    uint8 fl_TarLvlChg = 0;
    uint8 Rte_TarLvlChg = RTE_E_INVALID;
    uint8 fl_RearLvlSts = 0;
    uint8 Rte_RearLvlSts = RTE_E_INVALID;
    uint8 fl_AutoEasyAcsSts = 0;
    uint8 Rte_AutoEasyAcsSts = RTE_E_INVALID;
    uint8 fl_TrailerSts_VDC = 0;
    uint8 Rte_TrailerSts_VDC = RTE_E_INVALID;
    uint8 fl_JackModeSts = 0;
    uint8 Rte_JackModeSts = RTE_E_INVALID;
    uint8 fl_RearLvlKickModeSts = 0;
    uint8 Rte_RearLvlKickModeSts = RTE_E_INVALID;
    uint8 fl_LvlCtrlVehMode = 0;
    uint8 Rte_LvlCtrlVehMode = RTE_E_INVALID;
    uint8 fl_LvlCtrlRmn = 0;
    uint8 Rte_LvlCtrlRmn = RTE_E_INVALID;
    uint8 fl_LvlCtrlWarnLmpReq = 0;
    uint8 Rte_LvlCtrlWarnLmpReq = RTE_E_INVALID;
    uint8 fl_LvlCtrlRestrcn1 = 0;
    uint8 Rte_LvlCtrlRestrcn1 = RTE_E_INVALID;
    uint8 fl_LvlCtrlRestrcn2 = 0;
    uint8 Rte_LvlCtrlRestrcn2 = RTE_E_INVALID;
    uint8 fl_LvlCtrlRestrcn3 = 0;
    uint8 Rte_LvlCtrlRestrcn3 = RTE_E_INVALID;
    uint8 fl_LvlCtrlRestrcn4 = 0;
    uint8 Rte_LvlCtrlRestrcn4 = RTE_E_INVALID;
    uint8 fl_LvlCtrlRestrcn5 = 0;
    uint8 Rte_LvlCtrlRestrcn5 = RTE_E_INVALID;
    uint8 fl_LvlCtrlRestrcn6 = 0;
    uint8 Rte_LvlCtrlRestrcn6 = RTE_E_INVALID;
    uint8 fl_LvlCtrlRestrcn7 = 0;
    uint8 Rte_LvlCtrlRestrcn7 = RTE_E_INVALID;
    
    //Byte 108 Bit Bit3-Bit0 
    uint8 configGAC = 0;

    configGAC = (uint8)WN_GetSingleConfig(WN_enCfg_GAC);
    Rte_TarLvlChg = WN_TarLvlChg_SignalGet(&fl_TarLvlChg);
    Rte_RearLvlSts = WN_RearLvlSts_SignalGet(&fl_RearLvlSts);
    Rte_AutoEasyAcsSts = WN_AutoEasyAcsSts_SignalGet(&fl_AutoEasyAcsSts);
    Rte_TrailerSts_VDC = WN_TrailerSts_VDC_SignalGet(&fl_TrailerSts_VDC);
    Rte_JackModeSts = WN_JackModeSts_SignalGet(&fl_JackModeSts);
    Rte_RearLvlKickModeSts = WN_RearLvlKickModeSts_SignalGet(&fl_RearLvlKickModeSts);
    Rte_LvlCtrlVehMode = WN_LvlCtrlVehMode_SignalGet(&fl_LvlCtrlVehMode);
    Rte_LvlCtrlRmn = WN_LvlCtrlRmn_SignalGet(&fl_LvlCtrlRmn);//TBD
    Rte_LvlCtrlWarnLmpReq = WN_LvlCtrlWarnLmpReq_SignalGet(&fl_LvlCtrlWarnLmpReq);
    Rte_LvlCtrlRestrcn1 = WN_LvlCtrlRestrcn1_SignalGet(&fl_LvlCtrlRestrcn1);//TBD
    Rte_LvlCtrlRestrcn2 = WN_LvlCtrlRestrcn2_SignalGet(&fl_LvlCtrlRestrcn2);//TBD
    Rte_LvlCtrlRestrcn3 = WN_LvlCtrlRestrcn3_SignalGet(&fl_LvlCtrlRestrcn3);//TBD
    Rte_LvlCtrlRestrcn4 = WN_LvlCtrlRestrcn4_SignalGet(&fl_LvlCtrlRestrcn4);//TBD
    Rte_LvlCtrlRestrcn5 = WN_LvlCtrlRestrcn5_SignalGet(&fl_LvlCtrlRestrcn5);//TBD
    Rte_LvlCtrlRestrcn6 = WN_LvlCtrlRestrcn6_SignalGet(&fl_LvlCtrlRestrcn6);//TBD
    Rte_LvlCtrlRestrcn7 = WN_LvlCtrlRestrcn7_SignalGet(&fl_LvlCtrlRestrcn7);//TBD
    
    if(configGAC == 5)
    {
        //1.283
        if((RTE_E_OK == Rte_TarLvlChg) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_TarLvlChg))
        {
            if(fl_TarLvlChg == 0x0)
            {
                enNormalHeightSelect = WN_enDISPLAY_ON;
            }
            else if(fl_TarLvlChg == 0x1) 
            {
                enSuitHeightSelect = WN_enDISPLAY_ON;
            }
            else if(fl_TarLvlChg == 0x3)
            {
                enORHeight1Select = WN_enDISPLAY_ON;
            }
            else if(fl_TarLvlChg == 0x4)
            {
                enORHeight2Select = WN_enDISPLAY_ON;
            }
            else if(fl_TarLvlChg == 0x5)
            {
                enSuspensionExtend = WN_enDISPLAY_ON;
            }
            else if(fl_TarLvlChg == 0x6)
            {
                enSuspensionLockHeight = WN_enDISPLAY_ON;
            }
            else
            {}
        }
        if((RTE_E_OK == Rte_RearLvlSts) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_RearLvlSts))
        {
            if(fl_RearLvlSts == 0x1)
            {
                enBackShaftHeightSelect = WN_enDISPLAY_ON;
            }
            else
            {}
        }
        if((RTE_E_OK == Rte_AutoEasyAcsSts) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_AutoEasyAcsSts))
        {
            if(fl_AutoEasyAcsSts == 0x1)
            {
                enSuitHeightModeSelect = WN_enDISPLAY_ON;
            }
            else
            {}
        }
        if((RTE_E_OK == Rte_TrailerSts_VDC) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_TrailerSts_VDC))
        {

            if(fl_TrailerSts_VDC == 0x1)
            {
                enSuspensionTrailer = WN_enDISPLAY_ON;
            }
            else
            {}
        }
        if((RTE_E_OK == Rte_JackModeSts) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_JackModeSts))
        {
            if(fl_JackModeSts == 0x1)
            {
                enSuspensionLimitRise = WN_enDISPLAY_ON;
            }
            else
            {}
        }
        if((RTE_E_OK == Rte_RearLvlKickModeSts) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_RearLvlKickModeSts))
        {
            if(fl_RearLvlKickModeSts == 0x1)
            {
                enKickBackShaft = WN_enDISPLAY_ON;
            }
            else
            {}
        }
        if((RTE_E_OK == Rte_LvlCtrlVehMode) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_LvlCtrlVehMode))
        {
            if(fl_LvlCtrlVehMode == 0x1)
            {
                enSuspensionLimitTrans = WN_enDISPLAY_ON;
            }
            else
            {}
        }
        if((RTE_E_OK == Rte_LvlCtrlRmn) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_LvlCtrlRmn))
        {
            if(fl_LvlCtrlRmn == 0x1)
            {
                enSuspensionRise = WN_enDISPLAY_ON;
            }
            else if(fl_LvlCtrlRmn == 0x2)
            {
                enCarHighPlsSlow = WN_enDISPLAY_ON;
            }
            else
            {}
        }
        //1.284
        if((RTE_E_OK == Rte_LvlCtrlRestrcn1) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_LvlCtrlRestrcn1))
        {
            if(fl_LvlCtrlRestrcn1 == 0x1)
            {
                enBattLowStartEng = WN_enDISPLAY_ON;
            }
        }
        if((RTE_E_OK == Rte_LvlCtrlRestrcn2) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_LvlCtrlRestrcn2))
        {
            if(fl_LvlCtrlRestrcn2 == 0x1)
            {
                enSuspensionCoolDown = WN_enDISPLAY_ON;
            }
        }
        if((RTE_E_OK == Rte_LvlCtrlRestrcn3) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_LvlCtrlRestrcn3))
        {
            if(fl_LvlCtrlRestrcn3 == 0x1)
            {
                enHeightModeDisable = WN_enDISPLAY_ON;
            }
        }
        if((RTE_E_OK == Rte_LvlCtrlRestrcn4) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_LvlCtrlRestrcn4))
        {
            if(fl_LvlCtrlRestrcn4 == 0x1)
            {
                enPlsCloseDoorRise = WN_enDISPLAY_ON;
            }
        }
        if((RTE_E_OK == Rte_LvlCtrlRestrcn5) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_LvlCtrlRestrcn5))
        {
            if(fl_LvlCtrlRestrcn5 == 0x1)
            {
                enRiseModeSusLimit = WN_enDISPLAY_ON;
            }
        }
        if((RTE_E_OK == Rte_LvlCtrlRestrcn6) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_LvlCtrlRestrcn6))
        {
            if(fl_LvlCtrlRestrcn6 == 0x1)
            {
                enSuspensionTimeLimit = WN_enDISPLAY_ON;
            }
        }
        if((RTE_E_OK == Rte_LvlCtrlRestrcn7) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_LvlCtrlRestrcn7))
        {
            if(fl_LvlCtrlRestrcn7 == 0x1)
            {
                enOverSpeedHeightDisable = WN_enDISPLAY_ON;
            }
        }
        //1.285
        if((RTE_E_OK == Rte_LvlCtrlWarnLmpReq) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_LvlCtrlWarnLmpReq))
        {
            if(fl_LvlCtrlWarnLmpReq == 0x1)
            {
                enSuspensionFuncLimit = WN_enDISPLAY_ON;
            }
            else if(fl_LvlCtrlWarnLmpReq == 0x2)
            {
                enSuspensionFuncFault = WN_enDISPLAY_ON;
            }
            else
            {}
        }
    }

    WN_SET(WN_enNormalHeightSelect, enNormalHeightSelect);
    WN_SET(WN_enSuitHeightSelect, enSuitHeightSelect);
    WN_SET(WN_enORHeight1Select, enORHeight1Select);
    WN_SET(WN_enORHeight2Select, enORHeight2Select);
    WN_SET(WN_enSuspensionExtend, enSuspensionExtend);
    WN_SET(WN_enSuspensionLockHeight, enSuspensionLockHeight);
    WN_SET(WN_enBackShaftHeightSelect, enBackShaftHeightSelect);
    WN_SET(WN_enSuitHeightModeSelect, enSuitHeightModeSelect);
    WN_SET(WN_enSuspensionTrailer, enSuspensionTrailer);
    WN_SET(WN_enSuspensionLimitRise, enSuspensionLimitRise);
    WN_SET(WN_enKickBackShaft, enKickBackShaft);
    WN_SET(WN_enSuspensionLimitTrans, enSuspensionLimitTrans);
    WN_SET(WN_enSuspensionRise, enSuspensionRise);
    WN_SET(WN_enCarHighPlsSlow, enCarHighPlsSlow);
    WN_SET(WN_enSuspensionFuncLimit, enSuspensionFuncLimit);
    WN_SET(WN_enSuspensionFuncFault, enSuspensionFuncFault);
	WN_SET(WN_enBattLowStartEng, enBattLowStartEng);
    WN_SET(WN_enSuspensionCoolDown, enSuspensionCoolDown);
    WN_SET(WN_enHeightModeDisable, enHeightModeDisable);
    WN_SET(WN_enPlsCloseDoorRise, enPlsCloseDoorRise);
    WN_SET(WN_enRiseModeSusLimit, enRiseModeSusLimit);
    WN_SET(WN_enSuspensionTimeLimit, enSuspensionTimeLimit);
    WN_SET(WN_enOverSpeedHeightDisable, enOverSpeedHeightDisable);
    
}

void VMDR_Function_Process(WN_CFG_tstMAIN_OBJECT *stMainObject )//R12
{
    WN_CFG_enSTATUS_Common enLifeDetectClose = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enLifeDetectFault = WN_enDISPLAY_OFF;
    //Byte90 Bit1-Bit0
    uint8 configTCY = 0;
    uint8 fl_VMDR_FctnSts = 0;
    uint8 Rte_VMDR_FctnSts = RTE_E_INVALID;

    configTCY = (uint8)WN_GetSingleConfig(WN_encfg_TCY);
    Rte_VMDR_FctnSts = WN_VMDR_FctnSts_SignalGet(&fl_VMDR_FctnSts);//TBD

    if(configTCY == 1)
    {
        if((RTE_E_OK == Rte_VMDR_FctnSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_VMDR_FctnSts))
        {
            if(fl_VMDR_FctnSts == 0x2)//1.295
            {
                enLifeDetectClose = WN_enDISPLAY_ON;
            }
            else if(fl_VMDR_FctnSts == 0x3)//1.296
            {
                enLifeDetectFault = WN_enDISPLAY_ON;
            }
        }
        else
        {

		#ifdef GWM_V35_PROJECT_TYPE_D01
			//do nothing
		#else
            //1.296 R17: If KL15 ON and Message missing, trigger the warning
            if(m_PowerModeStatus == ((uint32)WN_enRUN))
            {
                enLifeDetectFault = WN_enDISPLAY_ON;
            }
		#endif
        }
		
    }
    WN_SET(WN_enLifeDetectClose, enLifeDetectClose);
    WN_SET(WN_enLifeDetectFault, enLifeDetectFault);
}

void TrailerHook_Function_Process(WN_CFG_tstMAIN_OBJECT *stMainObject )//R13
{
    WN_CFG_enSTATUS_Common enHookLock = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enHookUnlock = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enHookPowerOn = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enSwitchParkSts = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPlsCloseHook = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enPlsCheckHookSts = WN_enDISPLAY_OFF;
    WN_CFG_enSTATUS_Common enHookFaultPlsCheck = WN_enDISPLAY_OFF;

    //Byte23 Bit7-Bit5
    uint8 configKAT = 0;
    uint8 fl_TrailerhookSts = 0;
    uint8 Rte_TrailerhookSts = RTE_E_INVALID;
    uint8 fl_TrailerSts = 0;
    uint8 Rte_TrailerSts = RTE_E_INVALID;
    uint8 fl_TrailerhookFltSt = 0;
    uint8 Rte_TrailerhookFltSt = RTE_E_INVALID;
    uint8 fl_VehicleParkRemind = 0;
    uint8 Rte_VehicleParkRemind = RTE_E_INVALID;
    uint8 fl_TrailerhookClsRemind = 0;
    uint8 Rte_TrailerhookClsRemind = RTE_E_INVALID;
    uint8 fl_TrailerConnectRemind = 0;
    uint8 Rte_TrailerConnectRemind = RTE_E_INVALID;

    configKAT = (uint8)WN_GetSingleConfig(WN_encfg_KAT);
    Rte_TrailerhookSts = WN_TrailerhookSts_SignalGet(&fl_TrailerhookSts);//TBD
    Rte_TrailerSts = WN_TrailerSts_SignalGet(&fl_TrailerSts);
    Rte_TrailerhookFltSt = WN_TrailerhookFltSt_SignalGet(&fl_TrailerhookFltSt);//TBD
    Rte_VehicleParkRemind = WN_VehicleParkRemind_SignalGet(&fl_VehicleParkRemind);//TBD
    Rte_TrailerhookClsRemind = WN_TrailerhookClsRemind_SignalGet(&fl_TrailerhookClsRemind);//TBD
    Rte_TrailerConnectRemind = WN_TrailerConnectRemind_SignalGet(&fl_TrailerConnectRemind);//TBD

    if((configKAT == 2) || (configKAT == 4) || (configKAT == 5) || (configKAT == 6))
    {
        //1.276
        if((RTE_E_OK == Rte_TrailerhookSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_TrailerhookSts))
        {
            if((m_TrailerhookSts_last == 0x1) && (fl_TrailerhookSts == 0x00))
            {
                enHookLock = WN_enDISPLAY_ON;
            }
            else if((m_TrailerhookSts_last == 0x0) && (fl_TrailerhookSts == 0x01))
            {
                enHookUnlock = WN_enDISPLAY_ON;
            }
            else
            {}
        }

        //1.277
        if((RTE_E_OK == Rte_TrailerSts) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_TrailerSts))
        {
            if(fl_TrailerSts == 0x1)
            {
                enHookPowerOn = WN_enDISPLAY_ON;
            }
        }

        //1.278
        if((RTE_E_OK == Rte_TrailerhookFltSt) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_TrailerhookFltSt))
        {
            if(fl_TrailerhookFltSt == 0x1)
            {
                enHookFaultPlsCheck = WN_enDISPLAY_ON;
            }
        }

        //1.279
        if((RTE_E_OK == Rte_VehicleParkRemind) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_VehicleParkRemind))
        {
            if(fl_VehicleParkRemind == 0x1)
            {
                enSwitchParkSts = WN_enDISPLAY_ON;
            }
        }

        //1.280
        if((RTE_E_OK == Rte_TrailerhookClsRemind) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_TrailerhookClsRemind))
        {
            if(fl_TrailerhookClsRemind == 0x1)
            {
                enPlsCloseHook = WN_enDISPLAY_ON;
            }
        }

        //1.281
        if((RTE_E_OK == Rte_TrailerConnectRemind) ||
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_TrailerConnectRemind))
        {
            if(fl_TrailerConnectRemind == 0x1)
            {
                enPlsCheckHookSts = WN_enDISPLAY_ON;
            }
        }
    }
    m_TrailerhookSts_last = fl_TrailerhookSts;

    WN_SET(WN_enHookLock, enHookLock);
    WN_SET(WN_enHookUnlock, enHookUnlock);
    WN_SET(WN_enHookPowerOn, enHookPowerOn);
    WN_SET(WN_enHookFaultPlsCheck, enHookFaultPlsCheck);
    WN_SET(WN_enSwitchParkSts, enSwitchParkSts);
    WN_SET(WN_enPlsCloseHook, enPlsCloseHook);
    WN_SET(WN_enPlsCheckHookSts, enPlsCheckHookSts);
}

void WshngLiquid_Function_Process(WN_CFG_tstMAIN_OBJECT *stMainObject)//R15
{
	WN_CFG_enSTATUS_Common enWshngLiquidNotEnough = WN_enDISPLAY_OFF;

	//Byte119 Bit1-Bit0
    uint8 configWashingLiquidLevelAlarm = 0;
    //Byte80 Bit7-bit6
    uint8 configCentralModule = 0;
	//BCM19 0x30F TBD
	uint8 fl_WshngLiquidLvlWarn = 0;
    uint8 Rte_WshngLiquidLvlWarn = RTE_E_INVALID;
		
	configWashingLiquidLevelAlarm = (uint8)WN_GetSingleConfig(WN_encfg_WashingLiquidLevelAlarm);
    configCentralModule = (uint8)WN_GetSingleConfig(WN_enCfg_CentralModule);
	
	Rte_WshngLiquidLvlWarn = WN_WshngLiquidLvlWarn_SignalGet(&fl_WshngLiquidLvlWarn);//TBD

	if ((configWashingLiquidLevelAlarm == 1) && (configCentralModule == 1))
	{
		//1.306
		if ((RTE_E_OK == Rte_WshngLiquidLvlWarn) || \
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_WshngLiquidLvlWarn))
		{
			if (0x1 == fl_WshngLiquidLvlWarn)
			{
				enWshngLiquidNotEnough = WN_enDISPLAY_ON;
			}

		}
	}
	
    WN_SET(WN_enWshngLiquidNotEnough, enWshngLiquidNotEnough);
}

void CST_Function_Process(WN_CFG_tstMAIN_OBJECT *stMainObject)//R15
{
	WN_CFG_enSTATUS_Common enCSTActive = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enCSTClosed = WN_enDISPLAY_OFF;

	//Byte122 Bit7-Bit-6
    uint8 configComfortableStop = 0;

	//IBC_FD1 0x12E 20ms
	uint8 fl_CST_Status = 0;
    uint8 Rte_CST_Status = RTE_E_INVALID;
	
    configComfortableStop = (uint8)WN_GetSingleConfig(WN_encfg_ComfortableStop);
	Rte_CST_Status = WN_CST_Status_SignalGet(&fl_CST_Status);

	if (configComfortableStop == 1)
	{
		//1.307
		if ((RTE_E_OK == Rte_CST_Status) || \
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_CST_Status))
		{
			if ((0 == m_CST_Status_pre) && ((0x1 == fl_CST_Status) || (0x2 == fl_CST_Status)))
			{
				enCSTActive = WN_enDISPLAY_ON;
				enCSTClosed = WN_enDISPLAY_OFF;
			}
			else if (((0x1 == m_CST_Status_pre) || (0x2 == m_CST_Status_pre)) && (0x0 == fl_CST_Status))
			{
				enCSTActive = WN_enDISPLAY_OFF;
				enCSTClosed = WN_enDISPLAY_ON; 
			}
			else
			{
                /* do nothing */
			}
			
			m_CST_Status_pre = fl_CST_Status;
		}
		else
		{
			m_CST_Status_pre = 0;
		}
	}
	
    WN_SET(WN_enCSTActive, enCSTActive);
	WN_SET(WN_enCSTClosed, enCSTClosed);
}

void OBD_Charge_Function_Process(WN_CFG_tstMAIN_OBJECT *stMainObject )//R15
{
	WN_CFG_enSTATUS_Common enConnectedDischarging = WN_enDISPLAY_OFF;
	WN_CFG_enSTATUS_Common enConnectedNoDischarge = WN_enDISPLAY_OFF;

	//Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte30 Bit7-bit4
    uint8 configElecPosition = 0;

	//OBC2 0x317 200ms 
	uint8 fl_OBC_ConnectSts = 0;
    uint8 Rte_OBC_ConnectSts = RTE_E_INVALID;
	//OBC1 0x316 200ms 
	uint8 fl_OBC_ModSts = 0;
    uint8 Rte_OBC_ModSts = RTE_E_INVALID;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);
    configElecPosition = (uint8)WN_GetSingleConfig(WN_enCfg_ElecPosition);

	Rte_OBC_ConnectSts = WN_OBC_ConnectSts_SignalGet(&fl_OBC_ConnectSts);
	Rte_OBC_ModSts = WN_OBC_ModSts_SignalGet(&fl_OBC_ModSts);
	
#ifdef GWM_V35_PROJECT_TYPE_D01
	if ((0x4 == configFuel) && (0x8 == configElecPosition))
	{
	//1.313
		if (((RTE_E_OK == Rte_OBC_ConnectSts) || \
	        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_OBC_ConnectSts)) && \
	        ((RTE_E_OK == Rte_OBC_ModSts) || \
	        (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_OBC_ModSts)))
		{
			if (0x3 == fl_OBC_ConnectSts)
			{
				if (0x0 == fl_OBC_ModSts)
				{
					enConnectedDischarging = WN_enDISPLAY_ON;
				}
				else if ((fl_OBC_ModSts >= 0x1) && (fl_OBC_ModSts <= 0xC))
				{
					enConnectedNoDischarge = WN_enDISPLAY_ON; 
				}
				else
            	{}
			}
		
		}

	}
#else
	if ((0x4 == configFuel) && ((0x5 == configElecPosition) || (0x6 == configElecPosition)))
	{
		//1.308
		if (((RTE_E_OK == Rte_OBC_ConnectSts) || \
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_OBC_ConnectSts)) && \
            ((RTE_E_OK == Rte_OBC_ModSts) || \
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_OBC_ModSts)))
		{
			if (0x3 == fl_OBC_ConnectSts)
			{
				if (0x0 == fl_OBC_ModSts)
				{
					enConnectedDischarging = WN_enDISPLAY_ON;
				}
				else if ((fl_OBC_ModSts >= 0x1) && (fl_OBC_ModSts <= 0xC))
				{
					enConnectedNoDischarge = WN_enDISPLAY_ON; 
				}
				else
            	{}
			}
			
		}

	}
#endif
	
    WN_SET(WN_enConnectedDischarging, enConnectedDischarging);
	WN_SET(WN_enConnectedNoDischarge,enConnectedNoDischarge);
}

void Electricity_Unlock_Function_Process(WN_CFG_tstMAIN_OBJECT *stMainObject )//R17
{
	WN_CFG_enSTATUS_Common enPleaseReadUserManual = WN_enDISPLAY_OFF;

	//Byte80 Bit7-bit6
    uint8 configCentralModule = 0;
    //TBD
    uint8 configTFA = 0;
	//TBD
	uint8 fl_PowerRelsOverSpdWarn_U8 = 0;
    uint8 Rte_PowerRelsOverSpdWarn_U8 = 0;

    configCentralModule = (uint8)WN_GetSingleConfig(WN_enCfg_CentralModule);
	Rte_PowerRelsOverSpdWarn_U8 = WN_PowerRelsOverSpdWarn_SignalGet(&fl_PowerRelsOverSpdWarn_U8);

	if ((1 == configCentralModule) && (1 == configTFA))
	{
		//1.315
		if ((RTE_E_OK == Rte_PowerRelsOverSpdWarn_U8) || \
            (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_PowerRelsOverSpdWarn_U8))
		{
			if (0x1 == fl_PowerRelsOverSpdWarn_U8)
			{
				enPleaseReadUserManual = WN_enDISPLAY_ON;
			}
		}

	}
	
    WN_SET(WN_enPleaseReadUserManual, enPleaseReadUserManual);
}

void Charger_Status_Prormpt(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    WN_CFG_enSTATUS_Common enChargerFailure = WN_enDISPLAY_OFF;

    //Byte2 Bit7-bit4
    uint8 configFuel = 0;
    //Byte4 Bit5-bit2
    uint8 configRegional = 0;

    //OBC_FD1 0x316 20ms
    uint8 f1_OBC_ModSts_EV = 0;
    uint8 Rte_OBC_ModSts_EV = RTE_E_INVALID;
    //OBC_FD2 0x31F 100ms
    uint8 f1_OBC_CCLineConnectSts = 0;
    uint8 Rte_OBC_CCLineConnectSts = RTE_E_INVALID;
    //EVCC1 0x310 200ms
    uint8 f1_EVCC_PPLineSts = 0;
    uint8 Rte_EVCC_PPLineSts = RTE_E_INVALID;

    configFuel = (uint8)WN_GetSingleConfig(WN_enCfg_Fuel);

    Rte_OBC_ModSts_EV = WN_OBC_ModSts_EV_SignalGet(&f1_OBC_ModSts_EV);
    Rte_OBC_CCLineConnectSts = WN_OBC_CCLineConnectSts_SignalGet(&f1_OBC_CCLineConnectSts);
    Rte_EVCC_PPLineSts = WN_EVCC_PPLineSts_SignalGet(&f1_EVCC_PPLineSts);

    if(configFuel == 5)
    {
        
        if(configRegional == 0)
        {
                //1.312    case1
            if (((RTE_E_OK == Rte_OBC_CCLineConnectSts) || \
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_OBC_CCLineConnectSts)) && \
                ((RTE_E_OK == Rte_OBC_ModSts_EV) || \
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_OBC_ModSts_EV)))
            {
                if(((0x1 == f1_OBC_CCLineConnectSts) || (0x2 == f1_OBC_CCLineConnectSts) || (0x3 == f1_OBC_CCLineConnectSts)) && (0x8 == f1_OBC_ModSts_EV))
                {
                    enChargerFailure = WN_enDISPLAY_ON;
                }
                else
                {
                    enChargerFailure = WN_enDISPLAY_OFF;
                }
            }
        }       
        else
        {   //case2
            if (((RTE_E_OK == Rte_EVCC_PPLineSts) || \
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_EVCC_PPLineSts)) && \
                ((RTE_E_OK == Rte_OBC_ModSts_EV) || \
                (RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN == Rte_OBC_ModSts_EV)))
            {
                if(((0x1 == f1_EVCC_PPLineSts) || (0x3 == f1_EVCC_PPLineSts)) && (0x8 == f1_OBC_ModSts_EV))
                {
                    enChargerFailure = WN_enDISPLAY_ON;
                }
                else
                {
                    enChargerFailure = WN_enDISPLAY_OFF;
                }
            }
        }
    }

    WN_SET(WN_enChargerFailure, enChargerFailure);
}

uint8 WN_CFG_vGetCruiseSpeed(void)
{
    return m_CruiseSpeedData;
}
uint8 WN_CFG_vGetCruiseSpeedVld(void)
{
    return m_CruiseSpeedDataVld;
}
uint8 WN_CFG_vGetDrvModeCase(void)
{
    return m_DrvModeCase;
}
uint16 WN_CFG_vGetNOH_DistToExit(void)
{
    return m_NOH_DistanceToExit;
}

uint8 WN_CFG_vGetACC_SpdSetValue(void)//R11
{
    return m_ACC_SpeedSetValue;
}

uint8 WN_CFG_vGetV2XFrontRoadData(void)//R11
{
    return m_V2XFrontRoadData;
}

uint16 WN_CFG_vGetUreaRemainDistData(void)//R15
{
	return m_UreaRemainDist;
}

uint8 WN_CFG_vGetWN_PressReliProgsData(void)
{
	return m_PressReliProgsData;
}


/**********************************************************************************************************
*Function   : WN_TEST_enFlashTestProcess                                                                  *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : (WN_CFG_enStatusType)Warning current logic status                                           *
*                                                                                                         *
*Author     :                                                                                             *
*                                                                                                         *
*Date       :                                                                                             *
**********************************************************************************************************/
#if (WN_CFG_DEBUG == TRUE)
void WN_TEST_vTestProcess(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    boolean boRunningFlag = FALSE;
    uint8 enIndex = 0;

    if (boRunningFlag)
    {
        //Do nothing because this process is already running
    }
    else
    {
        boRunningFlag = TRUE;

#if 0
        if( WN_CFG_TEST_MSG_HAS_RECEIVED && WN_CFG_TEST_MSG_NOT_MISSING )
        {
        }
        else
        {
        }
        for(enIndex = 0 ; enIndex<WN_enWARNING_TOTAL_NUMBER ; enIndex++)
        {
            WN_SET(enIndex,WN_enFLASH_2_HZ);
        }
#endif
        boRunningFlag = FALSE;
    }
}
#endif //(WN_CFG_DEBUG == TRUE)

#define SWC_WN_STOP_SEC_CODE
#include "SWC_WN_MemMap.h"

/**********************************************************************************************************
*  End Of File                                                                                            *
**********************************************************************************************************/
