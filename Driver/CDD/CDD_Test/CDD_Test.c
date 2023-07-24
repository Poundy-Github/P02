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
 * @file:      CDD_Test.c
 * @author:    Nobo
 * @date:      2020-5-26
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-26
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include <stdio.h>
#include <string.h>
#include "Adc.h"
#include "CDD_Test.h"

#include "Dio.h"
#include "Port.h"
#include "IoHwAb.h"
#include "IoHwAb_Cfg_RI.h"

#include "HwConfig.h"
#include "RTC.h"
#include "IIC.h"

#include "Gyro.h"
#include "CLI_Commands.h"
#include "GPS_Test.h"
#include "DSP_Test.h"
//#include "RamTst.h"
extern GYRO_Return_t Gyro_GetDeviceId(uint8* pdata);
extern s_PowerOut_t Power_OutDataCurrent;
static uint8 u8Step = 0;
static uint8 u8DumpFlag = 0;





/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void CDD_Test_Init(void)
{
    u8Step = 0;
    u8DumpFlag = 0;
    CLI_Init();
//    GPS_Init();
//    DSP_Init();
//    WachDogEnable();

}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void CDD_Test_DisplayLog(void)
{
#if 0
    static Dio_LevelType levenl=0;
    uint32 voltage;
    uint8 u8Voltage;
    time_t time = 0;
    if ((u8DumpFlag != 0)||(u8Step != 0))
    {
        switch(u8Step++)
        {
            case 0:
                    CDD_TEST_DEBUG("-----------------------------------------------------------");
                    CDD_TEST_DEBUG("CDD Driver               Hex        Other");
                    CDD_TEST_DEBUG("-----------------------------------------------------------");
                    CDD_TEST_DEBUG("VIP_Gyro_INT1            %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_Gyro_INT1)     ,"P0_6");
                    CDD_TEST_DEBUG("VIP_ChargeEN_ODH         %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_ChargeEN_ODH)  ,"P0_9");
                    CDD_TEST_DEBUG("VIP_SI_IDH               %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_SI_IDH)        ,"P1_0");
                    CDD_TEST_DEBUG("VIP_RLIN31_INH           %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_RLIN31_INH)    ,"P1_1");
                    CDD_TEST_DEBUG("VIP_RLIN32_INH           %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_RLIN32_INH)    ,"P1_3");
                    CDD_TEST_DEBUG("VIP_LVI_IDL              %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_LVI_IDL)       ,"P1_9");
                    CDD_TEST_DEBUG("VIP_RTC_INT              %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_RTC_INT)       ,"P1_10");
                    CDD_TEST_DEBUG("VIP_RVC_PWREN            %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_RVC_PWREN)      ,"P2_7");
                    CDD_TEST_DEBUG("VIP_GPS_RST              %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_GPS_RST)      ,"P2_13");
                    CDD_TEST_DEBUG("SOC_VIP_CSIH1_REQ2       %04X       %s",Dio_ReadChannel(DioConf_DioChannel_SOC_VIP_CSIH1_REQ2),"P8_0");
                    CDD_TEST_DEBUG("SOC_VIP_CSIH2_REQ2       %04X       %s",Dio_ReadChannel(DioConf_DioChannel_SOC_VIP_CSIH2_REQ2),"P8_1");
                    CDD_TEST_DEBUG("VIP_SOC_EDL_3V3          %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_SOC_EDL_3V3)   ,"P8_3");
                    CDD_TEST_DEBUG("PMIC_VIP_PSHOLD          %04X       %s",Dio_ReadChannel(DioConf_DioChannel_PMIC_VIP_PSHOLD)   ,"P8_4");
                    CDD_TEST_DEBUG("SOC_VIP_RSTOK            %04X       %s",Dio_ReadChannel(DioConf_DioChannel_SOC_VIP_RSTOK)     ,"P8_5");
                    CDD_TEST_DEBUG("VIP_ON_IDH               %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_ON_IDH)        ,"P8_12");
                    CDD_TEST_DEBUG("Tuner_VIP_debug1         %04X       %s",Dio_ReadChannel(DioConf_DioChannel_Tuner_VIP_debug1)  ,"AP1_14");
                    CDD_TEST_DEBUG("Tuner_VIP_debug2         %04X       %s",Dio_ReadChannel(DioConf_DioChannel_Tuner_VIP_debug2)  ,"AP1_15");
                    CDD_TEST_DEBUG("479XX_VIP_INT_3V3        %04X       %s",Dio_ReadChannel(DioConf_DioChannel_SI479XX_VIP_INT_3V3),"P10_9");
                    break;
           case 1:
                    CDD_TEST_DEBUG("VIP_20098_PG             %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_20098_PG)      ,"P10_13");
                    CDD_TEST_DEBUG("VIP_OPL_IDL              %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_OPL_IDL)       ,"P10_15");
                    CDD_TEST_DEBUG("VIP_BSF_IDL              %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_BSF_IDL)       ,"P11_0");
                    CDD_TEST_DEBUG("DSP_VIP_INT              %04X       %s",Dio_ReadChannel(DioConf_DioChannel_DSP_VIP_INT)       ,"P11_1");
                    CDD_TEST_DEBUG("4624_VIP_INT_3V3         %04X       %s",Dio_ReadChannel(DioConf_DioChannel_SI4624_VIP_INT_3V3),"P11_9");
                    CDD_TEST_DEBUG("SOC_VIP_FAST_BOOT        %04X       %s",Dio_ReadChannel(DioConf_DioChannel_SOC_VIP_FAST_BOOT) ,"P18_0");
                    CDD_TEST_DEBUG("VIP_AMP8532_DIAG1        %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_AMP8532_DIAG1) ,"P18_5");
                    CDD_TEST_DEBUG("VIP_AMP8532_DIAG2        %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_AMP8532_DIAG2) ,"P18_6");
                    CDD_TEST_DEBUG("VIP_AMP8532_DIAG3        %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_AMP8532_DIAG3) ,"P18_7");
                    CDD_TEST_DEBUG("VIP_AMP8531_DIAG1        %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_AMP8531_DIAG1) ,"P18_10");
                    CDD_TEST_DEBUG("VIP_AMP8531_DIAG2        %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_AMP8531_DIAG2) ,"P18_11");
                    CDD_TEST_DEBUG("VIP_AMP8531_DIAG3        %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_AMP8531_DIAG3) ,"P18_12");
                    CDD_TEST_DEBUG("A2B_VIP_INT              %04X       %s",Dio_ReadChannel(DioConf_DioChannel_A2B_VIP_INT)    ,"P19_2");
                    CDD_TEST_DEBUG("SXM_VIP_STBY             %04X       %s",Dio_ReadChannel(DioConf_DioChannel_SXM_VIP_STBY)   ,"P9_2");
                    CDD_TEST_DEBUG("VIP_SOC3                 %04X       %s",Dio_ReadChannel(DioConf_DioChannel_VIP_SOC3)          ,"P9_4");
                    break;
          case 2:   
                    CDD_TEST_DEBUG("VBATT_VIP_DET_ADC        %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VBATT_VIP_DET_ADC,&voltage),voltage),"AP0_0");
                    CDD_TEST_DEBUG("VIP_A1VREF_IAN           %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_A1VREF_IAN,&voltage),voltage),"AP0_1");
                    CDD_TEST_DEBUG("VIP_VREF_Fuel_IAN        %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_VREF_Fuel_IAN,&voltage),voltage),"AP0_2");
                    CDD_TEST_DEBUG("VIP_Fuellevel1_IAN       %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel1_IAN,&voltage),voltage),"AP0_3");
                    CDD_TEST_DEBUG("VIP_Fuellevel2_IAN       %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel2_IAN,&voltage),voltage),"AP0_4");
                    CDD_TEST_DEBUG("VIP_Version_MON1_IAN     %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Version_MON1_IAN,&voltage),voltage),"AP0_5");
                    CDD_TEST_DEBUG("VIP_Version_MON2_IAN     %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Version_MON2_IAN,&voltage),voltage),"AP0_6");
                    CDD_TEST_DEBUG("VIP_BC_IAN               %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN,&voltage),voltage),"AP0_7");
                    CDD_TEST_DEBUG("VIP_ANT1_P_Diag          %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_ANT1_P_Diag,&voltage),voltage),"AP0_8");
                    CDD_TEST_DEBUG("VIP_ANT2_P_Diag          %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_ANT2_P_Diag,&voltage),voltage),"AP0_9");
                    CDD_TEST_DEBUG("GPSANTpwer_VIP_ADsense   %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_GPSANTpwer_VIP_ADsense,&voltage),voltage),"AP0_10"); 
                    CDD_TEST_DEBUG("VIP_TPS7B7701_IAN        %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_TPS7B7701_IAN,&voltage),voltage),"AP0_11");
                    CDD_TEST_DEBUG("VIP_TPS7B7702_IAN1       %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_TPS7B7702_IAN1,&voltage),voltage),"AP0_12");
                    CDD_TEST_DEBUG("VIP_TPS7B7702_IAN2       %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_TPS7B7702_IAN2,&voltage),voltage),"AP0_13");
                    CDD_TEST_DEBUG("MICpwr_VIP_Adsense       %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_MICpwr_VIP_Adsense,&voltage),voltage),"AP0_14");
                    CDD_TEST_DEBUG("VIP_NTC_MON1_IAN         %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_NTC_MON1_IAN,&voltage),voltage),"AP0_15");
                    CDD_TEST_DEBUG("MIC_VIP_SENS1            %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_MIC_VIP_SENS1,&voltage),voltage),"AP1_0");
                    CDD_TEST_DEBUG("MIC_VIP_SENS2            %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_MIC_VIP_SENS2,&voltage),voltage),"AP1_1");
                    CDD_TEST_DEBUG("MIC_VIP_SENS1_N          %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_MIC_VIP_SENS1_N,&voltage),voltage),"AP1_2");
                    CDD_TEST_DEBUG("MIC_VIP_SENS2_N          %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_MIC_VIP_SENS2_N,&voltage),voltage),"AP1_3");
                    CDD_TEST_DEBUG("VIP_NTC_MON2_IAN         %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_NTC_MON2_IAN,&voltage),voltage),"AP1_4");
                    CDD_TEST_DEBUG("VIP_NTC_MON3_IAN         %04X       %s",((void)IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_NTC_MON3_IAN,&voltage),voltage),"AP1_5");
                    CDD_TEST_DEBUG("RTC  Diver               %08X   %s",((void)RTC_GetTime(&time),time),"Adder:0x64");
                    CDD_TEST_DEBUG("Gyro Diver               %04X       %s",((void)Gyro_GetDeviceId(&u8Voltage),u8Voltage),"Adder:0xD6");
                    CDD_TEST_DEBUG("AK7707 Diver             %04X       %s",DSP_GetDeviceIdentification(),"Device ID:0x07");
                    CDD_TEST_DEBUG("Voltage value is: %d   %s",Power_OutDataCurrent.value,"uint 0.01v,");
                    break;
         case 3:
                    levenl = !levenl;                
                    break;
         case 9:    
                    u8Step = 0;
                    if (u8DumpFlag == 2)
                    {
                        u8DumpFlag = 0;
                    }
                    break;
        }
    }
#endif
}




/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Dio_LevelType tWDI_state = 0;
static boolean bWachDogFeedEn = 0;
void WachDogEnable(void)
{
    tWDI_state = 0;
    bWachDogFeedEn = TRUE;
    Port_SetPinDirection(Port_PortGroup08_VIP_WATCHDOG_WDI,PORT_PIN_OUT);
    Dio_WriteChannel(DioConf_DioChannel_VIP_WATCHDOG_WDI,tWDI_state);
    Dio_WriteChannel(DioConf_DioChannel_VIP_WD_enable,STD_LOW);

}

void WachDogDisable(void)
{
    tWDI_state = 0;
    bWachDogFeedEn = FALSE;
    Dio_WriteChannel(DioConf_DioChannel_VIP_WD_enable,STD_HIGH);
    Port_SetPinDirection(Port_PortGroup08_VIP_WATCHDOG_WDI,PORT_PIN_IN);
    Dio_WriteChannel(DioConf_DioChannel_VIP_WATCHDOG_WDI,tWDI_state);
}
void WachDogFeedDis(void)
{
    bWachDogFeedEn = FALSE;
}
void WachDogFeed(void)
{
    if (bWachDogFeedEn)
    {
        // tWDI_state = !tWDI_state;
        if(tWDI_state){
            tWDI_state=0;
        }else{
            tWDI_state=1;
        }
        Dio_WriteChannel(DioConf_DioChannel_VIP_WATCHDOG_WDI,tWDI_state);
    }
}


void CDD_Test_MainFunction(void)
{
//    WachDogFeed();
    // CDD_Test_DisplayLog();
    //GPS_MainFunction();
    CLI_CmdMainFunction();
    
//    DSP_MainFunction();
}
