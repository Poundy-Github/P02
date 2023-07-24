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
 * @file:      Misc_Diag.c
 * @author:    Nobo
 * @date:      2020-9-2
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-9-2
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include <stdio.h>
#include <string.h>


#include "Rte_Misc.h"
#include "Dio.h"

#include "IoHwAb.h"
#include "IoHwAb_Cfg_RI.h"
#include "Misc_Diag.h"
#include "logger.h"
#include "RTC.h"
#include "GPS_Test.h"
#include "VConfig_Cfg.h"
#include "Misc_Board.h"
#include "MPQ2022.h"
#include "VariantCfg.h"
#include "VConfig.h"


// task config
#define MISC_MIC_INIT_WAIT                          (10)

#define MIC_VIP_SENSn_POINT_NUM                     (2u)

#define MIC_POSITIVE_NORMAL_MASK                    (0x01u)
#define MIC_POSITIVE_OVERVOLTAGE_MASK               (0x02u)
#define MIC_POSITIVE_LOWVOLTAGE_MASK                (0x04u)
#define MIC_POSITIVE_OPEN_MASK                      (0x08u)
#define MIC_NEGATIVE_NORMAL_MASK                    (0x10u)
#define MIC_NEGATIVE_OVERVOLTAGE_MASK               (0x20u)
#define MIC_NEGATIVE_LOWVOLTAGE_MASK                (0x40u)
#define MIC_NEGATIVE_OPEN_MASK                      (0x80u)

// 4.11.1 Read Radio Antenna Status -AM(FM1)/FM2/DAB/SDARS
#define MISC_DID_TUNER_OPEN                 (0x01)
#define MISC_DID_TUNER_ShortToGND           (0x02)
#define MISC_DID_TUNER_ShortToBAT           (0x03)
#define MISC_DID_TUNER_Connected            (0x04)
#define MISC_DID_TUNER_OverCurrent          (0x05)
#define MISC_DID_TUNER_NReady               (0xFF)


// tuner diag
#define TUNER_OUTPUT_CYCLE                  (10)//10*100ms = 1000ms

#define MISC_DTC_UNDERVOLTAGE_VALUE			((float64)9.0f)//9V
#define MISC_DTC_OVERVOLTAGE_VALUE 			((float64)16.0f)//16V

#define MISC_DTC_SHORTTOBAT_VOLTAGE_VALUE	((float64)12.0f)//short to bat check min voltage was modified to 12V

//misc filter B : when DTC occure , Power On and Off each 500ms
#define MISC_FILTER_B_USED					(STD_ON)
#define MISC_FILTER_B_FAULT_CHECK_CNT		(5)//5 times each 100ms
#define MISC_FILTER_B_POWER_OFF_WAIT		(5)//when power off wait 5*100MS

#define MISC_INFO_PRINTF_CYCLE				(5)//500ms print once if enabled
// Mic channel define
enum
{
    MIC_VIP_SENS1,//this is right MIC , CONN_OPA_MIC_R
    MIC_VIP_SENS2,//this is left MIC ,CONN_OPA_MIC_L
    MIC_VIP_SENS_NUMBER
};

enum
{
    MIC_POSITIVE = 0,
    MIC_NEGATIVE,
    MIC_POINT_NUM,
};

// Mic filter define
enum
{
    MIC_VIP_SENS_Filter_GND=0,
    MIC_VIP_SENS_Filter_BAT,
    MIC_VIP_SENS_Filter_OPEN,
    MIC_VIP_SENS_Filter_NUMBER,
};

typedef enum 
{
    eMic_State_NORMEL=0,
    eMic_State_SHORT_GND,
    eMic_State_SHORT_BAT,
    eMic_State_SHORT_OPEN,
}Misc_Diag_State_t;

// tuner diag type
enum
{
    ANT1_P_Diag=0,
    ANT2_P_Diag,
    ANT_P_Diag_Num
};
enum
{                                       
    SenseState_OpenLoad = 0,           
    SenseState_OverCurrent,            
    SenseState_Short,                   
    SenseState_ShortToBattery,          
    SenseState_Num,
};



// filter info define 

typedef struct
{
    uint32  u32ChangeCounter;
    boolean AdcReady;
//==1 MIC
    //MIC input
    uint32  u32MicSENS[MIC_VIP_SENS_NUMBER];
    uint32  u32MicSENS_N[MIC_VIP_SENS_NUMBER];
    //MIC alg
    uint8   u8MicStateMask[MIC_VIP_SENS_NUMBER];
    boolean bMicFuel[MIC_VIP_SENS_NUMBER][MIC_VIP_SENS_Filter_NUMBER];
    boolean bMicUpdataFuel[MIC_VIP_SENS_NUMBER][MIC_VIP_SENS_Filter_NUMBER];
    //MIC outputs
    uint8   u8MicDidState[MIC_VIP_SENS_NUMBER];
    Dem_EventStatusType eMicDemEvent[MIC_VIP_SENS_NUMBER][MIC_VIP_SENS_Filter_NUMBER];

//==2 GNSS
    //GNSS input
    uint16 GPSSatelliteCount;
    uint32 u32GnssAdc;
    //GNSS alg
    boolean bGnssState[SenseState_Num];
    boolean bGnssUpdataFuel[SenseState_Num];
    //GNSS outputs
    Dem_EventStatusType eGnssDemEvent[SenseState_Num];
	
//==3 TUNER
    //Tuner input
    uint32 u32ANTDiagAdc[ANT_P_Diag_Num];
    //Tuner alg
    boolean bTunerState[ANT_P_Diag_Num][SenseState_Num];
    boolean bTunerUpdataFuel[ANT_P_Diag_Num][SenseState_Num];
    //Tuner outputs
    uint8   u8GlobalTunerState[ANT_P_Diag_Num];
    Dem_EventStatusType eTunerDemEvent[ANT_P_Diag_Num][SenseState_Num];

//==4 RVC
    //RVC input
    uint32  u32RvcAdc;
    //RVC alg
    boolean bRvcState[SenseState_Num];
    boolean bRvcUpdataFuel[SenseState_Num];
    //RVC outputs
    Dem_EventStatusType eRvcDemEvent[SenseState_Num]; 
}Misc_DiagIO_t;
//HW version
static uint8 hwVersion;

// Vconfig
#define b0000          (0x0)
#define b0001          (0x1)
#define b0010          (0x2)
#define b0011          (0x3)
#define b0100          (0x4)
#define b0101          (0x5)
#define b0110          (0x6)
#define b0111          (0x7)
#define b1000          (0x8)
#define b1001          (0x9)
#define b1010          (0xa)
#define b1011          (0xb)
#define b1100          (0xc)
#define b1101          (0xd)
#define b1110          (0xe)
#define b1111          (0xf)


#define MISC_DIAG_FEATURE_TAA00 (b0000)  /* 倒车影像 */
#define MISC_DIAG_FEATURE_TAA10 (b0001)  /* 无倒车影像 */
#define MISC_DIAG_FEATURE_TAA20 (b0010)  /* 倒车影像 */
#define MISC_DIAG_FEATURE_TAA30 (b0011)  /* 倒车影像配静态倒车辅助线 */

#define MISC_DIAG_FEATURE_ZB700 (b0000)  /* 360环视(配置字专用) */
#define MISC_DIAG_FEATURE_ZB710 (b0100)  /* 无360环视 */
#define MISC_DIAG_FEATURE_ZB720 (b0001)  /* 360环视-标清 */
#define MISC_DIAG_FEATURE_ZB730 (b0010)  /* 360环视-高清-独立 */
#define MISC_DIAG_FEATURE_ZB740 (b0011)  /* 360环视-高清-集成 */
#define MISC_DIAG_FEATURE_ZB750 (b0101)  /* 360环视-代客泊车 */

#define MISC_DIAG_FEATURE_KAJ00 (b0000)  /* 前盲区可视系统 */
#define MISC_DIAG_FEATURE_KAJ10 (b0001)  /* 无前盲区可视系统 */





typedef struct
{
    // vconfig                      //   值           特征码             名称
    uint8 u8ReverseVideo;           //   0b000        TAA00           无倒车影像
                                    //   0b001        TAA10           倒车影像
                                    //   0b010        TAA20           倒车影像配静态倒车辅助线
                                    //   0b011        TAA30           倒车影像配动态倒车辅助线
    uint8 u8OMNIVIEW;               //   0b000        ZB700           无360环视
                                    //   0b100        ZB710           360环视-标清
                                    //   0b001        ZB720           360环视-高清-独立
                                    //   0b010        ZB730           360环视-高清-集成
                                    //   0b011        ZB740           360环视-全景融合
    uint8 u8FRT_DeadAngleCamera;    //   0b00         KAJ00           无前盲区可视系统
                                    //   0b01         KAJ10           前盲区可视系统

    // info
    // V35-48570
    boolean bRVC_DTC_EN;
    boolean bGNSS_USED;//sys if not have GNSS mode

    uint32  u32ChangeCounterBack;
    uint32  TunerCnt;
    boolean TunerLock[ANT_P_Diag_Num];
    boolean RVCLock;
    boolean GNSSLock;
	float64 sysVoltage;
}
Misc_DiagSelf_t;

//filterB enum
#if(STD_ON == MISC_FILTER_B_USED)
typedef enum
{
	MISC_FILTER_B_1ST_STATE_CHECK=1,//0 : not allow be used , case 14 order clear eFilterBState as 0 when eFilterBState was power off 
	MISC_FILTER_B_2ND_POWEROFF_WAIT
}Misc_DiagFilterBInfo_e;
#endif

typedef struct
{
	//filterB
	#if(STD_ON == MISC_FILTER_B_USED)
	Misc_DiagFilterBInfo_e eFilterBState;
	uint16 filterBNormalcont;
	uint16 filterBFaultTranscont;
	uint16 filterBFaultcont;
	uint16 filterBWaitcont;
	#endif
	//
    uint8  last_state;
    uint8  state;
    boolean bInit;
    uint16 cont;
}Misc_DiagFilterInfo_t;


typedef struct
{
	//filterB
	#if(STD_ON == MISC_FILTER_B_USED)
	const uint8 u8FilterBEn;
	const Dio_ChannelType ioFilterBPowerEnPin;
	const uint8 u8FilterBPowerOff;
	const uint8 u8FilterBPowerOn;
	boolean *lock;
	#endif
	//
    const uint16 u16NormelFilterCount;
    const uint16 u16FaultFilterCount;
    Misc_DiagFilterInfo_t * info;
}
Misc_DiagFilterConfig_t;


typedef struct 
{
    sint32 TMin_Cfg;
    sint32 TMax_Cfg;
    uint32 MinTimeCfg;
    uint32 MaxTimeCfg;
}
Misc_DiagRetardationConfig_t;

typedef struct
{
    uint32 MinVol;
    uint32 MaxVol;
    uint8  Mask;
}
Misc_VolStateCheckCfg_t;

Misc_DiagSelf_t Misc_DiagSelf;//move to here case arry need use 'lock' variable


// MIC info define

const Misc_VolStateCheckCfg_t Mic_P_PorteVolStateTable[Mic_P_PorteVolStateSize] = {Mic_P_PorteVolStateList};
const Misc_VolStateCheckCfg_t Mic_N_PorteVolStateTable[Mic_N_PorteVolStateSize] = {Mic_N_PorteVolStateList};
boolean bMicLastFuel[MIC_VIP_SENS_NUMBER][MIC_VIP_SENS_Filter_NUMBER] = {0};





static boolean bMis_IsInit = FALSE;
static uint8 u8InitCnt=0;
static uint8 MicDidState[MIC_VIP_SENS_NUMBER]={MISC_DIDPOSITIVE_RESPONSE_CONNECTED,MISC_DIDPOSITIVE_RESPONSE_CONNECTED};
static uint8 TunerDidState[ANT_P_Diag_Num]={MISC_DID_TUNER_NReady,MISC_DID_TUNER_NReady};
//MIC
static Misc_DiagFilterInfo_t sMicFilterInfo[MIC_VIP_SENS_NUMBER][MIC_VIP_SENS_Filter_NUMBER] = {0};
static const Misc_DiagFilterConfig_t sMicFilterConfig[MIC_VIP_SENS_NUMBER][MIC_VIP_SENS_Filter_NUMBER] = 
{
#if(STD_ON == MISC_FILTER_B_USED)
    {
        {FALSE,DioConf_DioChannel_VIP_MIC_POWER_EN_3V3,STD_LOW,STD_HIGH,NULL_PTR,/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&sMicFilterInfo[MIC_VIP_SENS1][MIC_VIP_SENS_Filter_GND]},
        {FALSE,DioConf_DioChannel_VIP_MIC_POWER_EN_3V3,STD_LOW,STD_HIGH,NULL_PTR,/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&sMicFilterInfo[MIC_VIP_SENS1][MIC_VIP_SENS_Filter_BAT]},
        {FALSE,DioConf_DioChannel_VIP_MIC_POWER_EN_3V3,STD_LOW,STD_HIGH,NULL_PTR,/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&sMicFilterInfo[MIC_VIP_SENS1][MIC_VIP_SENS_Filter_OPEN]},
    },
    {
        {FALSE,DioConf_DioChannel_VIP_MIC_POWER_EN_3V3,STD_LOW,STD_HIGH,NULL_PTR,/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&sMicFilterInfo[MIC_VIP_SENS2][MIC_VIP_SENS_Filter_GND]},
        {FALSE,DioConf_DioChannel_VIP_MIC_POWER_EN_3V3,STD_LOW,STD_HIGH,NULL_PTR,/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&sMicFilterInfo[MIC_VIP_SENS2][MIC_VIP_SENS_Filter_BAT]},
        {FALSE,DioConf_DioChannel_VIP_MIC_POWER_EN_3V3,STD_LOW,STD_HIGH,NULL_PTR,/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&sMicFilterInfo[MIC_VIP_SENS2][MIC_VIP_SENS_Filter_OPEN]},
    }
#else
    {
        {/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&sMicFilterInfo[MIC_VIP_SENS1][MIC_VIP_SENS_Filter_GND]},
        {/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&sMicFilterInfo[MIC_VIP_SENS1][MIC_VIP_SENS_Filter_BAT]},
        {/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&sMicFilterInfo[MIC_VIP_SENS1][MIC_VIP_SENS_Filter_OPEN]},
    },
    {
        {/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&sMicFilterInfo[MIC_VIP_SENS2][MIC_VIP_SENS_Filter_GND]},
        {/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&sMicFilterInfo[MIC_VIP_SENS2][MIC_VIP_SENS_Filter_BAT]},
        {/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&sMicFilterInfo[MIC_VIP_SENS2][MIC_VIP_SENS_Filter_OPEN]},
    }

#endif
};
//TUNER
Misc_DiagFilterInfo_t TunerFilterInfo[ANT_P_Diag_Num][SenseState_Num] = {0};
static const Misc_DiagFilterConfig_t TunerRetardationConfig[ANT_P_Diag_Num][SenseState_Num] = 
{
#if(STD_ON == MISC_FILTER_B_USED)
    {
         {TRUE,DioConf_DioChannel_VIP_TUNER_ANT_EN_3V3,STD_LOW,STD_HIGH,&Misc_DiagSelf.TunerLock[ANT1_P_Diag],/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&TunerFilterInfo[ANT1_P_Diag][SenseState_OpenLoad]},
         {TRUE,DioConf_DioChannel_VIP_TUNER_ANT_EN_3V3,STD_LOW,STD_HIGH,&Misc_DiagSelf.TunerLock[ANT1_P_Diag],/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&TunerFilterInfo[ANT1_P_Diag][SenseState_OverCurrent]},
         {TRUE,DioConf_DioChannel_VIP_TUNER_ANT_EN_3V3,STD_LOW,STD_HIGH,&Misc_DiagSelf.TunerLock[ANT1_P_Diag],/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&TunerFilterInfo[ANT1_P_Diag][SenseState_Short]},
         {TRUE,DioConf_DioChannel_VIP_TUNER_ANT_EN_3V3,STD_LOW,STD_HIGH,&Misc_DiagSelf.TunerLock[ANT1_P_Diag],/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&TunerFilterInfo[ANT1_P_Diag][SenseState_ShortToBattery]},
    },
    {
         {TRUE,DioConf_DioChannel_VIP_TUNER_ANT_EN_3V3,STD_LOW,STD_HIGH,&Misc_DiagSelf.TunerLock[ANT2_P_Diag],/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&TunerFilterInfo[ANT2_P_Diag][SenseState_OpenLoad]},
         {TRUE,DioConf_DioChannel_VIP_TUNER_ANT_EN_3V3,STD_LOW,STD_HIGH,&Misc_DiagSelf.TunerLock[ANT2_P_Diag],/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&TunerFilterInfo[ANT2_P_Diag][SenseState_OverCurrent]},
         {TRUE,DioConf_DioChannel_VIP_TUNER_ANT_EN_3V3,STD_LOW,STD_HIGH,&Misc_DiagSelf.TunerLock[ANT2_P_Diag],/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&TunerFilterInfo[ANT2_P_Diag][SenseState_Short]},
         {TRUE,DioConf_DioChannel_VIP_TUNER_ANT_EN_3V3,STD_LOW,STD_HIGH,&Misc_DiagSelf.TunerLock[ANT2_P_Diag],/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&TunerFilterInfo[ANT2_P_Diag][SenseState_ShortToBattery]},
    }
#else
    {
         {/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&TunerFilterInfo[ANT1_P_Diag][SenseState_OpenLoad]},
         {/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&TunerFilterInfo[ANT1_P_Diag][SenseState_OverCurrent]},
         {/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&TunerFilterInfo[ANT1_P_Diag][SenseState_Short]},
         {/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&TunerFilterInfo[ANT1_P_Diag][SenseState_ShortToBattery]},
    },
    {
         {/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&TunerFilterInfo[ANT2_P_Diag][SenseState_OpenLoad]},
         {/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&TunerFilterInfo[ANT2_P_Diag][SenseState_OverCurrent]},
         {/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&TunerFilterInfo[ANT2_P_Diag][SenseState_Short]},
         {/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&TunerFilterInfo[ANT2_P_Diag][SenseState_ShortToBattery]},
    }
#endif
};
//RVC
Misc_DiagFilterInfo_t RVCFilterInfo[SenseState_Num] = {0};
static const Misc_DiagFilterConfig_t RVCRetardationConfig[SenseState_Num] = 
{
#if(STD_ON == MISC_FILTER_B_USED)
    {TRUE,DioConf_DioChannel_VIP_POC_PWREN,STD_LOW,STD_HIGH,&Misc_DiagSelf.RVCLock,/*NORMEL.FilterCount*/20,/*.FilterCount*/20,&RVCFilterInfo[SenseState_OpenLoad]},
    {TRUE,DioConf_DioChannel_VIP_POC_PWREN,STD_LOW,STD_HIGH,&Misc_DiagSelf.RVCLock,/*NORMEL.FilterCount*/20,/*.FilterCount*/20,&RVCFilterInfo[SenseState_OverCurrent]},
    {TRUE,DioConf_DioChannel_VIP_POC_PWREN,STD_LOW,STD_HIGH,&Misc_DiagSelf.RVCLock,/*NORMEL.FilterCount*/20,/*.FilterCount*/20,&RVCFilterInfo[SenseState_Short]},
    {TRUE,DioConf_DioChannel_VIP_POC_PWREN,STD_LOW,STD_HIGH,&Misc_DiagSelf.RVCLock,/*NORMEL.FilterCount*/20,/*.FilterCount*/20,&RVCFilterInfo[SenseState_ShortToBattery]},
#else
    {/*NORMEL.FilterCount*/20,/*.FilterCount*/20,&RVCFilterInfo[SenseState_OpenLoad]},
    {/*NORMEL.FilterCount*/20,/*.FilterCount*/20,&RVCFilterInfo[SenseState_OverCurrent]},
    {/*NORMEL.FilterCount*/20,/*.FilterCount*/20,&RVCFilterInfo[SenseState_Short]},
    {/*NORMEL.FilterCount*/20,/*.FilterCount*/20,&RVCFilterInfo[SenseState_ShortToBattery]},
#endif
};
//GNSS
Misc_DiagFilterInfo_t GNSSFilterInfo[SenseState_Num] = {0};
static const Misc_DiagFilterConfig_t GNSSRetardationConfig[SenseState_Num] = 
{
#if(STD_ON == MISC_FILTER_B_USED)
    {TRUE,DioConf_DioChannel_VIP_GPSANT_POWER_EN_3V3,STD_LOW,STD_HIGH,&Misc_DiagSelf.GNSSLock,/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&GNSSFilterInfo[SenseState_OpenLoad]},
    {TRUE,DioConf_DioChannel_VIP_GPSANT_POWER_EN_3V3,STD_LOW,STD_HIGH,&Misc_DiagSelf.GNSSLock,/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&GNSSFilterInfo[SenseState_OverCurrent]},
    {TRUE,DioConf_DioChannel_VIP_GPSANT_POWER_EN_3V3,STD_LOW,STD_HIGH,&Misc_DiagSelf.GNSSLock,/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&GNSSFilterInfo[SenseState_Short]},
    {TRUE,DioConf_DioChannel_VIP_GPSANT_POWER_EN_3V3,STD_LOW,STD_HIGH,&Misc_DiagSelf.GNSSLock,/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&GNSSFilterInfo[SenseState_ShortToBattery]},
#else
    {/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&GNSSFilterInfo[SenseState_OpenLoad]},
    {/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&GNSSFilterInfo[SenseState_OverCurrent]},
    {/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&GNSSFilterInfo[SenseState_Short]},
    {/*NORMEL.FilterCount*/10,/*.FilterCount*/50,&GNSSFilterInfo[SenseState_ShortToBattery]},

#endif
};


typedef struct
{
    uint32 min;
    uint32 max;
}Misc_Diag_cfg_t;

//Paragraphing hardware was ±2% so software need dilatation
const Misc_Diag_cfg_t Misc_TunerParagraphing[SenseState_Num ] = 
{
    {0,50},     // [0    , 37   , 50  ] OpenLoad
    {1071,1930},// [1071 , 1474 , 1930] OverCurrent
    {1956,2178},// [2006 , 2088 , 2128] Short ±50
    {2499,2700} // [2549 , 2621 , 2650] ShortToBattery ±50
    
};

const Misc_Diag_cfg_t Misc_RVCParagraphing[SenseState_Num] = 
{
    {0,50},     // [0    , 37   , 50  ] OpenLoad
    {1647,2006},// [1647 , 1936 , 2006] OverCurrent
    {2006,2170},// [2006 , 2088 , 2128] Short +50
    {2499,2700} // [2549 , 2621 , 2650] ShortToBattery ±50
};
	
const Misc_Diag_cfg_t Misc_GnssParagraphing[SenseState_Num] = 
{
    {0,50},     // [0    , 37   , 50  ] OpenLoad
    {546,840},  // [546  , 596  , 840 ] OverCurrent
    {2006,2170},// [2006 , 2088 , 2128] Short +50
    {2499,2700} // [2549 , 2621 , 2650] ShortToBattery ±50
};

//log
static const char * DtcMicLog[MIC_VIP_SENS_NUMBER][MIC_VIP_SENS_Filter_NUMBER] = 
{
    {
        "B13F511-Mic #1 short to GND",
        "B13F512-Mic #1 short to BAT",
        "B13F513-Mic #1 open",
    },
    {
        "B13F611-Mic #2 short to GND",
        "B13F612-Mic #2 short to BAT",
        "B13F613-Mic #2 open",
     }
};
static const char * DtcTunerLog[ANT_P_Diag_Num][SenseState_Num] = 
{
    {
		"B1A1013-Tuner1 OpenLoad",
		"B1A1019-Tuner1 OverCurrent",
		"B1A1011-Tuner1 ShortToGND",
		"B1A1012-Tuner1 ShortToBattery",
    },
    {
		"B1A1113-Tuner2 OpenLoad",
		"B1A1119-Tuner2 OverCurrent",
		"B1A1111-Tuner2 ShortToGND",
		"B1A1112-Tuner2 ShortToBattery",
     }
};
static const char * DtcRvcLog[SenseState_Num] = 
{
    "B110013-Rvc OpenLoad",
    "B110087-Rvc OverCurrent",
    "B110011-Rvc ShortToGND",
    "B110012-Rvc ShortToBattery",
};
static const char * DtcGnssLog[SenseState_Num] = 
{
    "B1A0813-Gnss OpenLoad",
    "B1A0819-Gnss OverCurrent",
    "B1A0811-Gnss ShortToGND",
    "B1A0812-Gnss ShortToBattery",
};

#define DISPLAY_CTRL_PIN_NUMBER     (4u)
#define DISPLAY_CTRL_EN             (STD_HIGH)
#define DISPLAY_CTRL_DIS            (STD_LOW)

typedef struct
{
    uint8 u8Offset;
    uint8 u8Mask;
    Dio_ChannelType tDisplayCtrlPin;
}Display_Info_t;
static const Display_Info_t cDisplayCtrlTable[DISPLAY_CTRL_PIN_NUMBER] = 
{
    {0,0x10,DioConf_DioChannel_VIP_ID_EN_ODH},
    {0,0x01,DioConf_DioChannel_VIP_CD_EN_ODH},
    {1,0x10,DioConf_DioChannel_VIP_HD_EN_ODH},
    {1,0x01,DioConf_DioChannel_VIP_PD_EN_ODH},
};

// 3.4.2 Read WatchDog Counter
// 3.4.3 Read Reset Information
#define RESET_INFOMATION_UNINIT                 (0)
#define RESET_INFOMATION_CHECK_SOURCE           (1)
#define RESET_INFOMATION_WAIT_WRITE             (2)
#define RESET_INFOMATION_DONE                   (3)

#define RESET_INFOMATION_RECORD_NUMBER          (10)


typedef struct{
    uint8 Time[4];
    uint8 Reason[2];
}Misc_ResetRecord_t;

typedef struct
{
    uint8 ResetTimes;
    uint16 WatchDogCounter;
    Misc_ResetRecord_t Record[RESET_INFOMATION_RECORD_NUMBER];
}Misc_NvmResetInfomation_t;

static Misc_NvmResetInfomation_t Misc_NvmResetInfomation = {0};
static uint8 ReasetRecordExecuteState =RESET_INFOMATION_UNINIT;


//Misc_DiagSelf_t Misc_DiagSelf;
static boolean bMiscLogPrintf = FALSE;


static boolean Misc_Diag_Filter_Signal(const Misc_DiagFilterConfig_t * config,uint8 vol);
static uint8 Misc_Diag_MicCheckPoint(const Misc_VolStateCheckCfg_t * cfg,uint32 Vol,sint8 size);
static void Misc_Diag_Alg(Misc_DiagIO_t * io);
static void Misc_Diag_CheckFault(Misc_DiagIO_t * io,uint8 sens);
static void Misc_Diag_CheckSensAD(Misc_DiagIO_t * io,uint8 sens);
static void Misc_Diag_MicFilter(Misc_DiagIO_t * io,uint8 sens);
static void Misc_Diag_In(Misc_DiagIO_t * io);
static void Misc_Diag_Out(Misc_DiagIO_t * io);
static void Misc_Diag_MicCheckDemEvent(Misc_DiagIO_t * io,uint8 sens);
static void Misc_Diag_MicCheckDidState(Misc_DiagIO_t * io,uint8 sens);
static void Misc_Diag_WriteResetRecordToRam(void);
static void Misc_Diag_ResetRecordTask(void);
static void Misc_Diag_WriteResetSourc(void);
static void Misc_Diag_CheckResetSourc(void);
static void Misc_Diag_ReadResetRecord(void);

static void Misc_Diag_CheckANTDiag(Misc_DiagIO_t * io,uint8 sens);
static void Misc_Diag_TunerFilter(Misc_DiagIO_t * io,uint8 sens);
static void Misc_Diag_TunerCheckDemEvent(Misc_DiagIO_t * io,uint8 sens);
static void Misc_Diag_TunerCheckLock(Misc_DiagIO_t * io);
static void Misc_Diag_TunerCheckDidState(Misc_DiagIO_t * io,uint8 sens);

static void Misc_Diag_CheckRVCDiag(Misc_DiagIO_t * io);
static void Misc_Diag_RVCFilter(Misc_DiagIO_t * io);
static void Misc_Diag_RVCCheckDemEvent(Misc_DiagIO_t * io);
static void Misc_Diag_RVCCheckLock(Misc_DiagIO_t * io);
static void Misc_Diag_GNSSCheckLock(Misc_DiagIO_t * io);
static void Misc_Diag_WriteTunerDid(void);
static void Misc_Diag_CheckChangeCounter(Misc_DiagIO_t * io);
static void Misc_Diag_InitDtcState(void);

static void Misc_Diag_CheckGnssDiag(Misc_DiagIO_t * io);
static void Misc_Diag_GNSSFilter(Misc_DiagIO_t * io);
static void Misc_Diag_GNSSCheckDemEvent(Misc_DiagIO_t * io);


//static void Misc_Diag_FilterCntClear(void);
static void Misc_Diag_FilterStateClear(void);
static void Misc_Diag_MIC_BAT_CheckFault(Misc_DiagIO_t * io);
static void Misc_PreConditon1_NotMatch_ClearInnerState(void);
static void Misc_PreConditon2_NotMatch_ClearInnerState(void);

#define CHECK_MIC_DEM(SENS,Filter,fun)      \
    do\
    {\
        if (sMicFilterInfo[SENS][Filter].bInit == TRUE)\
        {\
            fun(io->eMicDemEvent[SENS][Filter]);\
        }\
    }while(0)

#define CHECK_TUNER_DEM(SENS,Filter,fun)      \
    do\
    {\
        if (TunerFilterInfo[SENS][Filter].bInit == TRUE)\
        {\
            fun(io->eTunerDemEvent[SENS][Filter]);\
        }\
    }while(0)

#define CHECK_RVC_DEM(Filter,fun)      \
    do\
    {\
        if (RVCFilterInfo[Filter].bInit == TRUE)\
        {\
            fun(io->eRvcDemEvent[Filter]);\
        }\
    }while(0)
	
#define CHECK_GNSS_DEM(Filter,fun)      \
    do\
    {\
        if (GNSSFilterInfo[Filter].bInit == TRUE)\
        {\
            fun(io->eGnssDemEvent[Filter]);\
        }\
    }while(0)


/***********************************************************************
 * @brief       : Misc_PowerWasMPQ2022
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean Misc_PowerWasMPQ2022(void)
{
	boolean ret = FALSE;
	if((eMiscBoard_Version_C4 == hwVersion)||(eMiscBoard_Version_C5 == hwVersion))
	{
		ret = TRUE;
	}
	return ret;
}
/***********************************************************************
 * @brief       : MISC_SYSRVCWasUsed
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean MISC_SYSRVCWasUsed(void)
{
	return Misc_DiagSelf.bRVC_DTC_EN;
}
/***********************************************************************
 * @brief       : MISC_SYSGNSSWasUsed
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean MISC_SYSGNSSWasUsed(void)
{
	return Misc_DiagSelf.bGNSS_USED;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Misc_Diag_Init(void)
{
    NvM_RequestResultType RequestResult=0;
    Std_ReturnType ret;
	boolean b_GNSS_MODULE_TYPE_IS_ZP720 = TRUE;

    
    bMis_IsInit = FALSE;
    u8InitCnt=0;

    ret = Rte_Call_NvMService_AC3_Defs_NvBlockNeed_ResetInfomation_GetErrorStatus(&RequestResult);

    
    if (ret != E_OK)
    {
        memset(&Misc_NvmResetInfomation,0,sizeof(Misc_NvmResetInfomation));
        Misc_Diag_WriteResetRecordToRam();
        ReasetRecordExecuteState = RESET_INFOMATION_WAIT_WRITE;
    }
    else
    {
        Misc_Diag_ReadResetRecord();
    }
    Misc_Diag_CheckResetSourc();
    
    memset(&MicDidState,(uint8)MISC_DIDPOSITIVE_RESPONSE_CONNECTED,sizeof(MicDidState));
    memset(&sMicFilterInfo,0,sizeof(sMicFilterInfo));
    memset(&Misc_DiagSelf,0,sizeof(Misc_DiagSelf));
    // V35-48570
    ret = Rte_Call_rcCS_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(VCONFIG_KIND_REVERSE_VIDEO,&Misc_DiagSelf.u8ReverseVideo);
    ret |= Rte_Call_rcCS_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION,&Misc_DiagSelf.u8OMNIVIEW);
    ret |= Rte_Call_rcCS_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(VCONFIG_KIND_FRT_DEAD_ANGLE_SYSTEM,&Misc_DiagSelf.u8FRT_DeadAngleCamera);

    // V35-48570
    if (ret == E_NOT_OK)
    {
        misc_err("Vconfig interface error.");
    }
    else
    {
		Misc_DiagSelf.bRVC_DTC_EN = FALSE;
		//uptate this logic from:SRS-R14(GWM V3.5-203-001DT01 ECU Level Diagnostic Requirement-HUT(GWMLAN)s_V3.5 - 20210222_Nobo V2.5-20210929)
		if((MISC_DIAG_FEATURE_ZB740 == Misc_DiagSelf.u8OMNIVIEW)||(MISC_DIAG_FEATURE_ZB750 == Misc_DiagSelf.u8OMNIVIEW))
		{
			//extern AVM
		}else if(MISC_DIAG_FEATURE_ZB730 == Misc_DiagSelf.u8OMNIVIEW)
		{
			//inner AVM
		}else if((MISC_DIAG_FEATURE_KAJ10 == Misc_DiagSelf.u8FRT_DeadAngleCamera) &&
				  ((MISC_DIAG_FEATURE_TAA10 == Misc_DiagSelf.u8ReverseVideo)
	                ||(MISC_DIAG_FEATURE_TAA20 == Misc_DiagSelf.u8ReverseVideo)
	                ||(MISC_DIAG_FEATURE_TAA30 == Misc_DiagSelf.u8ReverseVideo)))
		{
			//SVC+RVC
			//Misc_DiagSelf.bRVC_DTC_EN = TRUE; //remove this logic , only RVC need PowerOn RVC and it's DTC
		}else if(MISC_DIAG_FEATURE_KAJ10 == Misc_DiagSelf.u8FRT_DeadAngleCamera)
		{
			//only SVC
		}else if((MISC_DIAG_FEATURE_TAA10 == Misc_DiagSelf.u8ReverseVideo)
	                ||(MISC_DIAG_FEATURE_TAA20 == Misc_DiagSelf.u8ReverseVideo)
	                ||(MISC_DIAG_FEATURE_TAA30 == Misc_DiagSelf.u8ReverseVideo))
		{
			//only RVC
			Misc_DiagSelf.bRVC_DTC_EN = TRUE;
		}

		//GNSS used : ====== special judge which was first excute ... cause MPQ2022.C need this flag
		#ifdef PLATFOEM_OF_GNSS_USED
			b_GNSS_MODULE_TYPE_IS_ZP720=((vconfig_config.kindDatas[VCONFIG_KIND_GNSS_MODULE_TYPE].configGet == 0x2) ? TRUE : FALSE);
			if(TRUE == b_GNSS_MODULE_TYPE_IS_ZP720)
			{				
				Misc_DiagSelf.bGNSS_USED = TRUE;
			}
		#else
		    misc_warn("CurSys GNSS Moudle Not Used !");
		#endif	

	/*
        if ((MISC_DIAG_FEATURE_ZB740 != Misc_DiagSelf.u8OMNIVIEW)
            &&(MISC_DIAG_FEATURE_ZB730 != Misc_DiagSelf.u8OMNIVIEW)
            &&(MISC_DIAG_FEATURE_KAJ10 != Misc_DiagSelf.u8FRT_DeadAngleCamera)
            &&((MISC_DIAG_FEATURE_TAA10 == Misc_DiagSelf.u8ReverseVideo)
                ||(MISC_DIAG_FEATURE_TAA20 == Misc_DiagSelf.u8ReverseVideo)
                ||(MISC_DIAG_FEATURE_TAA30 == Misc_DiagSelf.u8ReverseVideo))
           )
        {
            Misc_DiagSelf.bRVC_DTC_EN = TRUE;
        }
   */
    }
    misc_warn("Vconfig: ZB7:%d,KAJ:%d,TAA:%d, DTC EN = %d, GNSS_EN = %d",
        Misc_DiagSelf.u8OMNIVIEW,
        Misc_DiagSelf.u8FRT_DeadAngleCamera,
        Misc_DiagSelf.u8ReverseVideo,
        Misc_DiagSelf.bRVC_DTC_EN,
        Misc_DiagSelf.bGNSS_USED);
}






/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Misc_Diag_Task(void)
{
    Misc_DiagIO_t sMicIO;
    Std_ReturnType ret = E_NOT_OK;	

    memset(&sMicIO,0,sizeof(sMicIO));
    
    if (bMis_IsInit == FALSE)
    {
        if (u8InitCnt++ >= MISC_MIC_INIT_WAIT)
        {
            u8InitCnt = 0;
            bMis_IsInit = TRUE;
        }
    }
    else
    {
		ret = Misc_Board_GetHwVersion(&hwVersion);
		if(E_OK == ret)
		{
	        Misc_Diag_In(&sMicIO);
	        Misc_Diag_Alg(&sMicIO);
	        Misc_Diag_Out(&sMicIO);
		}
    }
    
    Misc_Diag_ResetRecordTask();
}




/***********************************************************************
 * @brief       : 3.4.3 Read Reset Information
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Misc_Diag_EOL_0xFDE2_EOL_ReadResetInformation(uint8 * arg)
{
    arg[0] = Misc_NvmResetInfomation.ResetTimes;
    memcpy(&arg[1],&Misc_NvmResetInfomation.Record,60);
    misc_verbose("Did FDE2:%04x ... ",Misc_NvmResetInfomation.ResetTimes);
}



/***********************************************************************
 * @brief       : 3.4.2 Read WatchDog      
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Misc_Diag_EOL_0xFDE1_EOL_ReadWatchDogCnt(uint8 * arg)
{
    arg[0] = (uint8)(Misc_NvmResetInfomation.WatchDogCounter>>8);
    arg[1] = (uint8)(Misc_NvmResetInfomation.WatchDogCounter&0xFF);
    misc_verbose("Did FDE1:%04x",Misc_NvmResetInfomation.WatchDogCounter);
}

/***********************************************************************
 * @brief       : 4.11.2 Read Microphone Status
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Misc_Diag_EOL_0xFDD1_EOL_ReadMICStatus(uint8 * arg)
{
    if (arg != NULL_PTR)
    {
    #if 0
        arg[MIC_VIP_SENS1] = MicDidState[MIC_VIP_SENS1];
        arg[MIC_VIP_SENS2] = MicDidState[MIC_VIP_SENS2];
	#else
        arg[MIC_VIP_SENS1] = MicDidState[MIC_VIP_SENS2];
        arg[MIC_VIP_SENS2] = MicDidState[MIC_VIP_SENS1];
	#endif
        misc_verbose("Did FDD1:%02x %02x",arg[MIC_VIP_SENS1],arg[MIC_VIP_SENS2]);
    }
}



/***********************************************************************
 * @brief       : 4.11.20 Values for Display Enabling Set
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Misc_Diag_EOL_0xFDD9_EOL_WriteValueForDispalyEnable(uint8 *arg)
{
    uint8 i;
    uint8 msg;
    if (arg != NULL_PTR)
    {
        for (i=0; i<DISPLAY_CTRL_PIN_NUMBER; i++)
        {
            msg = arg[cDisplayCtrlTable[i].u8Offset];
            if (msg & cDisplayCtrlTable[i].u8Mask)
            {
                Dio_WriteChannel(cDisplayCtrlTable[i].tDisplayCtrlPin,DISPLAY_CTRL_EN);
            }
            else
            {
                Dio_WriteChannel(cDisplayCtrlTable[i].tDisplayCtrlPin,DISPLAY_CTRL_DIS);
            }
        }
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void printfMiscAdcInfo(Misc_DiagIO_t * io)
{
	misc_warn("sysVoltage=%.1fv,adcVlu:%d, %d, %d, %d, %d, %d, %d, %d\r"
	,Misc_DiagSelf.sysVoltage
	,io->u32MicSENS[MIC_VIP_SENS1]
	,io->u32MicSENS[MIC_VIP_SENS2]
	,io->u32MicSENS_N[MIC_VIP_SENS1]
	,io->u32MicSENS_N[MIC_VIP_SENS2]
	,io->u32ANTDiagAdc[ANT1_P_Diag]
	,io->u32ANTDiagAdc[ANT2_P_Diag]
	,io->u32RvcAdc
	,io->u32GnssAdc
	);
	
	if(TRUE == Misc_PowerWasMPQ2022())
	{
		misc_warn("MIC:%d %d,GNSS:%d %d,ANT1:%d %d,ANT2:%d %d,RVC:%d %d\r"
		,MPQ22022_MIC_V_GET(),MPQ22022_MIC_I_GET()
		,MPQ22022_GNSS_V_GET(),MPQ22022_GNSS_I_GET()
		,MPQ22022_ANT1_V_GET(),MPQ22022_ANT1_I_GET()
		,MPQ22022_ANT2_V_GET(),MPQ22022_ANT2_I_GET()
		,MPQ22022_RVC_V_GET(),MPQ22022_RVC_I_GET()
		);
	}
}
/***********************************************************************
 * @brief       : printf MISC info
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Misc_AdcPrintfTriger(boolean setVlu)
{
	bMiscLogPrintf = setVlu;
}

static void Misc_Diag_In(Misc_DiagIO_t * io)
{
    Std_ReturnType ret = (Std_ReturnType)0;
	static uint8 printfCnt = 0;
    //#ifndef GWM_V35_PROJECT_TYPE_A07
    (void)Rte_Read_rpSR_piDiagMonitorReInitFlag_ChangeCounter(&io->u32ChangeCounter);
    //#endif
    // MIC
    ret |= IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_MIC_VIP_SENS1,&io->u32MicSENS[MIC_VIP_SENS1]);
    ret |= IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_MIC_VIP_SENS2,&io->u32MicSENS[MIC_VIP_SENS2]);
    ret |= IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_MIC_VIP_SENS1_N,&io->u32MicSENS_N[MIC_VIP_SENS1]);
    ret |= IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_MIC_VIP_SENS2_N,&io->u32MicSENS_N[MIC_VIP_SENS2]);
	
    if(FALSE == Misc_PowerWasMPQ2022())
    {
	    // TUNER
	    ret |= IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_ANT1_P_Diag,&io->u32ANTDiagAdc[ANT1_P_Diag]);
	    ret |= IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_ANT2_P_Diag,&io->u32ANTDiagAdc[ANT2_P_Diag]);

	    // RVC
	    ret |= IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_TPS7B7701_IAN,&io->u32RvcAdc);

		// GNSS
	    ret |= IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_GPSANTpwer_VIP_ADsense,&io->u32GnssAdc);
    }
	//fresh result
	io->AdcReady = ((ret != (Std_ReturnType)0) ? FALSE : TRUE);

    // GNSS-info
    GPS_GetGPSSatelliteCount(&io->GPSSatelliteCount);

	if((TRUE == bMiscLogPrintf)&&((printfCnt++%MISC_INFO_PRINTF_CYCLE)==0))
	{
		printfMiscAdcInfo(io);
	}
}

/***********************************************************************
 * @brief       : 
 * 1.use [adc_vlu] to alg out : [io->xxx_state] or [io->xxx_mask]
 * 2.use [io->xxx_state] , [io->xxx_mask] , [Contex->xxx_state] to alg out : [Contex->xxx_state] and [io->xxx_UpdataFuel]
 * 3.use [Contex->xxx_state] to alg out : [io->xxx_DemEvent]
 * 4.use [Contex->xxx_state] to write SWC_DID
 * 5.use [io->xxx_UpdataFuel] to write SWC_DEM
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_Alg(Misc_DiagIO_t * io)
{
    uint8 i;
	SystemState_RecordType SysValue;

	(void)Rte_Read_tiSR_Power_Out_SystemStateOut(&SysValue);
	Misc_DiagSelf.sysVoltage = SysValue.s_PowerVoltage.value;
	// When voltage condition is not met, clear debounce count and DTC don't report
	if( (SysValue.s_PowerVoltage.value < MISC_DTC_UNDERVOLTAGE_VALUE) || (SysValue.s_PowerVoltage.value > MISC_DTC_OVERVOLTAGE_VALUE) )
	{
		 Misc_PreConditon1_NotMatch_ClearInnerState();
    }

	
	// When voltage low than MISC_DTC_SHORTTOBAT_VOLTAGE_VALUE ,clear filter state to make DTC don't report
	if(SysValue.s_PowerVoltage.value < MISC_DTC_SHORTTOBAT_VOLTAGE_VALUE)
	{
		 Misc_PreConditon2_NotMatch_ClearInnerState();
    }
	

	// When EOL event of clear all DIAG
	Misc_Diag_CheckChangeCounter(io);

	// When ADC sample normal
    if (io->AdcReady != FALSE)
    {
        //========1st MIC
        for (i=0; i<MIC_VIP_SENS_NUMBER; i++)
        {
        	//1 use adc caculate fault
            Misc_Diag_CheckSensAD(io,i);
            Misc_Diag_CheckFault(io,i);
			//2 use fault caculate comtex.state and fault update state
            Misc_Diag_MicFilter(io,i);
			//3 use comtex.state caculate DEM and DID state
            Misc_Diag_MicCheckDemEvent(io,i);
            Misc_Diag_MicCheckDidState(io,i); 
        }

        //========2nd TUNER
#if(STD_ON != MISC_FILTER_B_USED)//if use filterB ,remove this logic , and lock ctrl at filterB
		if (Misc_DiagSelf.TunerLock == FALSE)
#endif
		{
	        for (i=0; i<ANT_P_Diag_Num; i++)
	        {
				//1 use adc caculate fault
	            Misc_Diag_CheckANTDiag(io,i);
				//2 use fault caculate comtex.state and fault update state
	            Misc_Diag_TunerFilter(io,i);
				//3 use comtex.state caculate DEM and DID state
	            Misc_Diag_TunerCheckDemEvent(io,i);
	            Misc_Diag_TunerCheckDidState(io,i);
	        }
		}

        //========3rd RVC
		if(TRUE == MISC_SYSRVCWasUsed())
		{
#if(STD_ON != MISC_FILTER_B_USED)//if use filterB ,remove this logic , and lock ctrl at filterB
	        if (Misc_DiagSelf.RVCLock == FALSE)
#endif
			{
				//1 use adc caculate fault
	            Misc_Diag_CheckRVCDiag(io);
				//2 use fault caculate comtex.state and fault update state
	            Misc_Diag_RVCFilter(io);
				//3 use comtex.state caculate DEM and DID state
		        Misc_Diag_RVCCheckDemEvent(io);
	        }
		}
		
		//========4th GNSS
		
		if(TRUE == MISC_SYSGNSSWasUsed())
		{
#if(STD_ON != MISC_FILTER_B_USED)//if use filterB ,remove this logic , and lock ctrl at filterB
        if (Misc_DiagSelf.GNSSLock == FALSE)
#endif
			{
				//1 use adc caculate fault
				Misc_Diag_CheckGnssDiag(io);
				//2 use fault caculate comtex.state and fault update state
				Misc_Diag_GNSSFilter(io);
				//3 use comtex.state caculate DEM and DID state
				Misc_Diag_GNSSCheckDemEvent(io);
	        }
		}
    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_Out(Misc_DiagIO_t * io)
{
	uint8 i,j;
	//if ADC not ready not output DTC
	if (io->AdcReady != FALSE)
	{
		//========1st : MIC - WriteDTC , WriteDID , PrintfLog
		CHECK_MIC_DEM(MIC_VIP_SENS1,MIC_VIP_SENS_Filter_OPEN,Rte_Call_DiagnosticMonitor_Mic_1_open_SetEventStatus        );
		CHECK_MIC_DEM(MIC_VIP_SENS1,MIC_VIP_SENS_Filter_BAT ,Rte_Call_DiagnosticMonitor_Mic_1_short_to_BAT_SetEventStatus);
		CHECK_MIC_DEM(MIC_VIP_SENS1,MIC_VIP_SENS_Filter_GND ,Rte_Call_DiagnosticMonitor_Mic_1_short_to_GND_SetEventStatus);
		CHECK_MIC_DEM(MIC_VIP_SENS2,MIC_VIP_SENS_Filter_OPEN,Rte_Call_DiagnosticMonitor_Mic_2_open_SetEventStatus        );
		CHECK_MIC_DEM(MIC_VIP_SENS2,MIC_VIP_SENS_Filter_BAT ,Rte_Call_DiagnosticMonitor_Mic_2_short_to_BAT_SetEventStatus);
		CHECK_MIC_DEM(MIC_VIP_SENS2,MIC_VIP_SENS_Filter_GND ,Rte_Call_DiagnosticMonitor_Mic_2_short_to_GND_SetEventStatus);
        MicDidState[MIC_VIP_SENS1] = io->u8MicDidState[MIC_VIP_SENS1];
        MicDidState[MIC_VIP_SENS2] = io->u8MicDidState[MIC_VIP_SENS2];    
		for (i=0; i<MIC_VIP_SENS_NUMBER;i++)
		{
			for (j=0; j<MIC_VIP_SENS_Filter_NUMBER;j++)
			{
				if((TRUE == io->bMicUpdataFuel[i][j]) && (TRUE == io->bMicFuel[i][j]))
				{
					dtc_err(DtcMicLog[i][j]);//err state changed printf
					printfMiscAdcInfo(io);
				}
			}
		} 
//        dtc_Verbose("Mic_1 DTC state :%d,%d,%d",io->eMicDemEvent[MIC_VIP_SENS1][MIC_VIP_SENS_Filter_OPEN],
//                                     io->eMicDemEvent[MIC_VIP_SENS1][MIC_VIP_SENS_Filter_BAT],
//                                     io->eMicDemEvent[MIC_VIP_SENS1][MIC_VIP_SENS_Filter_GND]);
//        dtc_Verbose("Mic_2 DTC state:%d,%d,%d",io->eMicDemEvent[MIC_VIP_SENS2][MIC_VIP_SENS_Filter_OPEN],
//                                     io->eMicDemEvent[MIC_VIP_SENS2][MIC_VIP_SENS_Filter_BAT],
//                                     io->eMicDemEvent[MIC_VIP_SENS2][MIC_VIP_SENS_Filter_GND]);

		//========2nd : TUNER - WriteDTC , WriteDID , PrintfLog , CheckLock
#if(STD_ON != MISC_FILTER_B_USED)//if use filterB , remove this logic
		if(FALSE == Misc_DiagSelf.TunerLock)
#endif
		{
			CHECK_TUNER_DEM(ANT1_P_Diag,SenseState_OpenLoad 	 ,Rte_Call_DiagnosticMonitor_FM1_OpenCircuit_SetEventStatus   );
			CHECK_TUNER_DEM(ANT1_P_Diag,SenseState_OverCurrent	 ,Rte_Call_DiagnosticMonitor_FM1_OverCurrent_SetEventStatus   );
			CHECK_TUNER_DEM(ANT1_P_Diag,SenseState_ShortToBattery,Rte_Call_DiagnosticMonitor_FM1_ShortToBattary_SetEventStatus);
			CHECK_TUNER_DEM(ANT1_P_Diag,SenseState_Short		 ,Rte_Call_DiagnosticMonitor_FM1_ShortToGround_SetEventStatus );
			Misc_Diag_WriteTunerDid();
			for (i=0; i<ANT_P_Diag_Num;i++)
	        {
	           for (j=0; j<SenseState_Num;j++)
	           {
					if((TRUE == io->bTunerUpdataFuel[i][j])&&(TRUE == io->bTunerState[i][j]))
					{
						dtc_err(DtcTunerLog[i][j]);//err state changed printf
						printfMiscAdcInfo(io);
					}
	           }
	        } 
		}
		
#if(STD_ON != MISC_FILTER_B_USED)
		Misc_Diag_TunerCheckLock(io);
#endif
//		dtc_Verbose("Tuner DTC state: %d,%d,%d,%d",
//			  io->eTunerDemEvent[ANT1_P_Diag][SenseState_OpenLoad],
//			  io->eTunerDemEvent[ANT1_P_Diag][SenseState_OverCurrent],
//			  io->eTunerDemEvent[ANT1_P_Diag][SenseState_ShortToBattery],
//			  io->eTunerDemEvent[ANT1_P_Diag][SenseState_Short]);
		
		//========3rd : RVC - WriteDTC , WriteDID , PrintfLog , CheckLock
	    if (TRUE == Misc_DiagSelf.bRVC_DTC_EN)
	    {
#if(STD_ON != MISC_FILTER_B_USED)//if use filterB , remove this logic
			if(FALSE == Misc_DiagSelf.RVCLock)
#endif
			{
				CHECK_RVC_DEM(SenseState_OpenLoad,	   Rte_Call_DiagnosticMonitor_RVC_CameraOpenCircuit_SetEventStatus);
				CHECK_RVC_DEM(SenseState_ShortToBattery,Rte_Call_DiagnosticMonitor_RVC_CamerShortToBattery_SetEventStatus);
				CHECK_RVC_DEM(SenseState_Short,		   Rte_Call_DiagnosticMonitor_RVC_CameraShortToGround_SetEventStatus);
				for (j=0; j<SenseState_Num;j++)
				{
					if((TRUE == io->bRvcUpdataFuel[j])&&(TRUE == io->bRvcState[j]))
					{
					    dtc_err(DtcRvcLog[j]);//err state changed printf
						printfMiscAdcInfo(io);
					}
				}
			}
#if(STD_ON != MISC_FILTER_B_USED)
			Misc_Diag_RVCCheckLock(io);
#endif
		}		
//			dtc_Verbose("Rvc DTC state: %d,%d,%d",io->eRvcDemEvent[SenseState_OpenLoad],
//											   io->eRvcDemEvent[SenseState_ShortToBattery],
//											   io->eRvcDemEvent[SenseState_Short]);
		//========4th : GNSS - WriteDTC , WriteDID , PrintfLog , CheckLock
		#ifdef PLT_DFCT_MISC_DTC_OF_GPS
			Rte_Write_EOL_ReadGPSSatelliteCount_GPSSatelliteCount((uint8)io->GPSSatelliteCount);
#if(STD_ON != MISC_FILTER_B_USED)//if use filterB , remove this logic
			if(FALSE == Misc_DiagSelf.GNSSLock)
#endif
			{
				CHECK_GNSS_DEM(SenseState_OpenLoad,		 Rte_Call_DiagnosticMonitor_GNSS_OpenCircuit_SetEventStatus);
				CHECK_GNSS_DEM(SenseState_OverCurrent,	 Rte_Call_DiagnosticMonitor_GNSS_OverCurrent_SetEventStatus);
				CHECK_GNSS_DEM(SenseState_ShortToBattery,Rte_Call_DiagnosticMonitor_GNSS_ShortToBattary_SetEventStatus);
				CHECK_GNSS_DEM(SenseState_Short, 		 Rte_Call_DiagnosticMonitor_GNSS_ShortToGround_SetEventStatus);
				for (j=0; j<SenseState_Num;j++)
				{
				    if((TRUE == io->bGnssUpdataFuel[j])&&(TRUE == io->bGnssState[j]))
				    {
						dtc_err(DtcGnssLog[j]);//err state changed printf
						printfMiscAdcInfo(io);
					}
				}
			}
#if(STD_ON != MISC_FILTER_B_USED)
			Misc_Diag_GNSSCheckLock(io);
#endif
//			dtc_Verbose("Gnss DTC state: %d,%d,%d,%d",
//				  io->eGnssDemEvent[SenseState_OpenLoad],
//				  io->eGnssDemEvent[SenseState_OverCurrent],
//				  io->eGnssDemEvent[SenseState_ShortToBattery],
//				  io->eGnssDemEvent[SenseState_Short]);
		#endif	
    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint8 Misc_Diag_MicCheckPoint(const Misc_VolStateCheckCfg_t * cfg,uint32 Vol,sint8 size)
{ 
    uint8 mask = 0;
    sint16 i;

    for(i=0; i < size; i++)
    {
        if ((cfg[i].MinVol <= Vol)&&(cfg[i].MaxVol >= Vol))
        {
            mask = cfg[i].Mask;
            break;
        }
    }
    
    return mask;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_CheckSensAD(Misc_DiagIO_t * io,uint8 sens)
{
    uint8 mask = 0;

    mask = Misc_Diag_MicCheckPoint(Mic_P_PorteVolStateTable,io->u32MicSENS[sens],Mic_P_PorteVolStateSize);
    io->u8MicStateMask[sens] = mask;
    
    mask = Misc_Diag_MicCheckPoint(Mic_N_PorteVolStateTable,io->u32MicSENS_N[sens],Mic_N_PorteVolStateSize);
    io->u8MicStateMask[sens] = io->u8MicStateMask[sens] | mask;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_CheckFault(Misc_DiagIO_t * io,uint8 sens)
{
    if (io->u8MicStateMask[sens] == (MIC_POSITIVE_OPEN_MASK|MIC_NEGATIVE_LOWVOLTAGE_MASK))//P=Open & N=Gnd
    {
        io->bMicFuel[sens][MIC_VIP_SENS_Filter_OPEN] = TRUE;//open
        io->bMicFuel[sens][MIC_VIP_SENS_Filter_GND] = FALSE;
        io->bMicFuel[sens][MIC_VIP_SENS_Filter_BAT] = FALSE;
    }
    else if (io->u8MicStateMask[sens] == (MIC_POSITIVE_NORMAL_MASK|MIC_NEGATIVE_NORMAL_MASK))//P=Normal & N=Normal
    {
        io->bMicFuel[sens][MIC_VIP_SENS_Filter_OPEN] = FALSE;
        io->bMicFuel[sens][MIC_VIP_SENS_Filter_GND] =  FALSE;
        io->bMicFuel[sens][MIC_VIP_SENS_Filter_BAT] =  FALSE;
    }
    else if (io->u8MicStateMask[sens] == (MIC_POSITIVE_LOWVOLTAGE_MASK|MIC_NEGATIVE_LOWVOLTAGE_MASK))//P=Gnd & N=Gnd
    {
		io->bMicFuel[sens][MIC_VIP_SENS_Filter_OPEN] = FALSE;
		io->bMicFuel[sens][MIC_VIP_SENS_Filter_GND] = TRUE;//gnd
		io->bMicFuel[sens][MIC_VIP_SENS_Filter_BAT] = FALSE;
	}
	else if ((io->u8MicStateMask[sens] & (MIC_POSITIVE_OVERVOLTAGE_MASK|MIC_NEGATIVE_OVERVOLTAGE_MASK)) != 0 )//P=Bat or N=Bat
	{
		io->bMicFuel[sens][MIC_VIP_SENS_Filter_OPEN] = FALSE;
		io->bMicFuel[sens][MIC_VIP_SENS_Filter_GND] = FALSE;
		io->bMicFuel[sens][MIC_VIP_SENS_Filter_BAT] = TRUE;//bat
	}
	else
	{
		// keep last state.
		io->bMicFuel[sens][MIC_VIP_SENS_Filter_OPEN] = bMicLastFuel[sens][MIC_VIP_SENS_Filter_OPEN];
		io->bMicFuel[sens][MIC_VIP_SENS_Filter_GND]  = bMicLastFuel[sens][MIC_VIP_SENS_Filter_GND];
		io->bMicFuel[sens][MIC_VIP_SENS_Filter_BAT]  = bMicLastFuel[sens][MIC_VIP_SENS_Filter_BAT];
	}
    bMicLastFuel[sens][MIC_VIP_SENS_Filter_OPEN] = io->bMicFuel[sens][MIC_VIP_SENS_Filter_OPEN];
    bMicLastFuel[sens][MIC_VIP_SENS_Filter_GND] =  io->bMicFuel[sens][MIC_VIP_SENS_Filter_GND];
    bMicLastFuel[sens][MIC_VIP_SENS_Filter_BAT] =  io->bMicFuel[sens][MIC_VIP_SENS_Filter_BAT];
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_MIC_BAT_CheckFault(Misc_DiagIO_t * io)
{
	uint8 releaseChanel = MIC_VIP_SENS1;
	uint32  adcMinus = 0 ;
	if((sMicFilterInfo[MIC_VIP_SENS1][MIC_VIP_SENS_Filter_BAT].state == TRUE) &&
		(sMicFilterInfo[MIC_VIP_SENS2][MIC_VIP_SENS_Filter_BAT].state == TRUE))
	{
		if(io->u32MicSENS[MIC_VIP_SENS1] >= io->u32MicSENS[MIC_VIP_SENS2])
		{
			releaseChanel = MIC_VIP_SENS2;
			adcMinus = io->u32MicSENS[MIC_VIP_SENS1] - io->u32MicSENS[MIC_VIP_SENS2];
		}
		else
		{
			releaseChanel = MIC_VIP_SENS1;
			adcMinus = io->u32MicSENS[MIC_VIP_SENS2] - io->u32MicSENS[MIC_VIP_SENS1];
		}
		if( adcMinus >= MIC_BAT_ALL_OCCURE_MAX_MINUS_VLU)
		{
			//clear this chanel BAT DTC ,cause affect by the other
			memset(&sMicFilterInfo[releaseChanel][MIC_VIP_SENS_Filter_BAT],0,sizeof(Misc_DiagFilterInfo_t));
			io->bMicUpdataFuel[releaseChanel][MIC_VIP_SENS_Filter_BAT] = FALSE;
		}
	}
	
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_MicFilter(Misc_DiagIO_t * io,uint8 sens)
{
    io->bMicUpdataFuel[sens][MIC_VIP_SENS_Filter_GND] = Misc_Diag_Filter_Signal(&sMicFilterConfig[sens][MIC_VIP_SENS_Filter_GND],(uint8)io->bMicFuel[sens][MIC_VIP_SENS_Filter_GND]);
    io->bMicUpdataFuel[sens][MIC_VIP_SENS_Filter_BAT] = Misc_Diag_Filter_Signal(&sMicFilterConfig[sens][MIC_VIP_SENS_Filter_BAT],(uint8)io->bMicFuel[sens][MIC_VIP_SENS_Filter_BAT]);
    io->bMicUpdataFuel[sens][MIC_VIP_SENS_Filter_OPEN] = Misc_Diag_Filter_Signal(&sMicFilterConfig[sens][MIC_VIP_SENS_Filter_OPEN],(uint8)io->bMicFuel[sens][MIC_VIP_SENS_Filter_OPEN]);
	//
	Misc_Diag_MIC_BAT_CheckFault(io);
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_FilterStateClear(void)
{
	//clear inner state
	uint8 i=0;
	for(i=0;i<MIC_VIP_SENS_NUMBER;i++)
	{
	    memset(&sMicFilterInfo[i][SenseState_ShortToBattery],0,sizeof(Misc_DiagFilterInfo_t));
	    memset(&bMicLastFuel[i][MIC_VIP_SENS_Filter_BAT],0,1);
	}
    
    memset(&TunerFilterInfo[SenseState_ShortToBattery],0,sizeof(Misc_DiagFilterInfo_t));
    memset(&RVCFilterInfo[SenseState_ShortToBattery],0,sizeof(Misc_DiagFilterInfo_t));

    memset(&GNSSFilterInfo[SenseState_ShortToBattery],0,sizeof(Misc_DiagFilterInfo_t));

}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean Misc_Diag_FilterA_Signal(const Misc_DiagFilterConfig_t * config,uint8 vol)
{
    boolean bUpdata = FALSE;
    uint16 FilterCount;
    if ((config->info->state != vol)||(config->info->bInit != TRUE))
    {
		config->info->cont++;
		if(vol == TRUE)
		{
			FilterCount = config->u16FaultFilterCount;
		}
		else
		{
			FilterCount = config->u16NormelFilterCount;
		}
		
		if (config->info->cont >= FilterCount)
		{
			config->info->last_state = config->info->state;
			config->info->state = vol;
			config->info->bInit = TRUE;
			bUpdata = TRUE;
		}
    }
	else
	{
		config->info->cont = 0 ;
	}
    return bUpdata;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean Misc_Diag_FilterB_Signal(const Misc_DiagFilterConfig_t * config,uint8 vol)
{
    boolean bUpdata = FALSE;
	
	switch(config->info->eFilterBState)
	{
		case MISC_FILTER_B_1ST_STATE_CHECK://check state was Nomal or Fault
			//if locked cause by some or other DTC , the other DTC not fresh , and pending 500ms
			if(*config->lock != TRUE)
			{
				if(FALSE == vol)//fault not appear
				{
					//avoid DTC appear alternately , clear Fault trans and total cnt
					config->info->filterBFaultTranscont=0;
					config->info->filterBFaultcont = 0;
					//normal cnt deal
					if(++config->info->filterBNormalcont >= config->u16NormelFilterCount)
					{
						config->info->state = vol;
						config->info->bInit = TRUE;
						config->info->filterBNormalcont = 0 ;
	 				}
				}
				else//fault appear
				{
					//avoid DTC appear alternately , clear Normal cnt
					config->info->filterBNormalcont = 0;
					//falut cnt deal
					if(++config->info->filterBFaultTranscont >= MISC_FILTER_B_FAULT_CHECK_CNT)
					{
						//add Fault total cnt 
						config->info->filterBFaultcont += config->info->filterBFaultTranscont;
						config->info->filterBFaultTranscont = 0 ;
						//if lager harf fault cnt , error occure
						if(config->info->filterBFaultcont >= (MISC_FILTER_B_FAULT_CHECK_CNT*config->u16FaultFilterCount/(MISC_FILTER_B_FAULT_CHECK_CNT+MISC_FILTER_B_POWER_OFF_WAIT)))
						{
							config->info->filterBFaultcont  = (MISC_FILTER_B_FAULT_CHECK_CNT*config->u16FaultFilterCount/(MISC_FILTER_B_FAULT_CHECK_CNT+MISC_FILTER_B_POWER_OFF_WAIT));//hold error
	 						config->info->state = vol;
							config->info->bInit = TRUE;
						}
						//power off
						Dio_WriteChannel(config->ioFilterBPowerEnPin,config->u8FilterBPowerOff);
						*config->lock = TRUE;
						config->info->filterBWaitcont = 0 ;
						//
						config->info->eFilterBState = MISC_FILTER_B_2ND_POWEROFF_WAIT;
	 				}
					
				}
				//if state changed output once
				if(config->info->last_state != config->info->state)
				{
					config->info->last_state = config->info->state;
					bUpdata = TRUE;
				}
			}
		break;
		case MISC_FILTER_B_2ND_POWEROFF_WAIT://when Power off , all DTC check will be pending 500ms , then Power on
			if(++config->info->filterBWaitcont >= MISC_FILTER_B_POWER_OFF_WAIT)
			{
				Dio_WriteChannel(config->ioFilterBPowerEnPin,config->u8FilterBPowerOn);
				*config->lock = FALSE;
				//
				config->info->eFilterBState = MISC_FILTER_B_1ST_STATE_CHECK;
			}
		break;
		default:
			Dio_WriteChannel(config->ioFilterBPowerEnPin,config->u8FilterBPowerOn);//avoid power off and checkout was normal
			*config->lock = FALSE;
			//
			config->info->eFilterBState = MISC_FILTER_B_1ST_STATE_CHECK;
		break;
	
	}
	
    return bUpdata;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean Misc_Diag_Filter_Signal(const Misc_DiagFilterConfig_t * config,uint8 vol)
{
    boolean bUpdata = FALSE;
    uint16 FilterCount;
	
#if(STD_ON != MISC_FILTER_B_USED)
	bUpdata = Misc_Diag_FilterA_Signal(config,vol);
#else
	if(FALSE == config->u8FilterBEn)//old filter , filterB not used
	{
		bUpdata = Misc_Diag_FilterA_Signal(config,vol);
	}
	else if(TRUE == config->u8FilterBEn)//filterB used , add filter for : FM/RVC/GNSS of ShortToBat, ShortToGnd, OpenLoad, OverCurrent
	{
		if(FALSE == Misc_PowerWasMPQ2022())
		{
			bUpdata = Misc_Diag_FilterB_Signal(config,vol);
		}
		else
		{
			bUpdata = Misc_Diag_FilterA_Signal(config,vol);
		}
	}
#endif
	
    return bUpdata;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_MicCheckDemEvent(Misc_DiagIO_t * io,uint8 sens)
{
    uint8 i;

    for (i=0; i<MIC_VIP_SENS_Filter_NUMBER;i++)
    {
        if (sMicFilterInfo[sens][i].state == TRUE)
        {
            io->eMicDemEvent[sens][i] = DEM_EVENT_STATUS_FAILED;
        }
        else
        {
            io->eMicDemEvent[sens][i] = DEM_EVENT_STATUS_PASSED;
        }
        
    }
}
static void Misc_Diag_MicCheckDidState(Misc_DiagIO_t * io,uint8 sens)
{
    if (sMicFilterInfo[sens][MIC_VIP_SENS_Filter_OPEN].state)
    {
        io->u8MicDidState[sens] = MISC_DIDPOSITIVE_RESPONSE_OPEN;
    }
    else if (sMicFilterInfo[sens][MIC_VIP_SENS_Filter_GND].state)
    {
        io->u8MicDidState[sens] = MISC_DIDPOSITIVE_RESPONSE_GND;
    }
    else if (sMicFilterInfo[sens][MIC_VIP_SENS_Filter_BAT].state)
    {
        io->u8MicDidState[sens] = MISC_DIDPOSITIVE_RESPONSE_BAT;
    }
    else
    {
        io->u8MicDidState[sens] = MISC_DIDPOSITIVE_RESPONSE_CONNECTED;
    }
}

/***********************************************************************
 * @brief       : 4.11.1 Read Radio Antenna Status -AM(FM1)/FM2/DAB/SDARS
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_TunerCheckDidState(Misc_DiagIO_t * io,uint8 sens)
{
    if (TunerFilterInfo[sens][SenseState_OpenLoad].bInit 
        && TunerFilterInfo[sens][SenseState_Short].bInit
        && TunerFilterInfo[sens][SenseState_ShortToBattery].bInit
        && TunerFilterInfo[sens][SenseState_OverCurrent].bInit
        ) 
    {
        if (TunerFilterInfo[sens][SenseState_OpenLoad].state != FALSE)
        {
            TunerDidState[sens] = MISC_DID_TUNER_OPEN;
        }
        else if (TunerFilterInfo[sens][SenseState_Short].state != FALSE)
        {
            TunerDidState[sens] = MISC_DID_TUNER_ShortToGND;
        }
        else if (TunerFilterInfo[sens][SenseState_ShortToBattery].state != FALSE)
        {
            TunerDidState[sens] = MISC_DID_TUNER_ShortToBAT;
        }
        else if (TunerFilterInfo[sens][SenseState_OverCurrent].state != FALSE)
        {
            TunerDidState[sens] = MISC_DID_TUNER_OverCurrent;
        }
        else if (io->u8GlobalTunerState[sens] >= SenseState_Num)
        {
            TunerDidState[sens] = MISC_DID_TUNER_Connected;
        }
    }
    else
    {
        TunerDidState[sens] = MISC_DID_TUNER_NReady;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_WriteResetRecordToRam(void)
{
    uint8 *prt;
    prt = Rte_Pim_NvBlockNeed_ResetInfomation_MirrorBlock();
    memcpy(prt,&Misc_NvmResetInfomation,sizeof(NvmResetInformation_t));
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_ReadResetRecord(void)
{
    uint8 *prt;
    prt = Rte_Pim_NvBlockNeed_ResetInfomation_MirrorBlock();
    memcpy(&Misc_NvmResetInfomation,prt,sizeof(NvmResetInformation_t));
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_CheckResetSourc(void)
{
    reset_type reset = 0;
    RTC_Return_t rte;
    time_t time;
    Misc_ResetRecord_t Record;
    
    
    (void)Rte_Read_Rc_ResetReason_ResetSource(&reset);

    if (reset != McuRstRsnConfIso)
    {
        rte = RTC_GetTime(&time);
        
        if (rte == eRTC_Return_Seccess)
        {
            uint8 i;
            Record.Time[0] = ((uint8 *)(&time))[3];
            Record.Time[1] = ((uint8 *)(&time))[2];
            Record.Time[2] = ((uint8 *)(&time))[1];
            Record.Time[3] = ((uint8 *)(&time))[0];
            Record.Reason[0] =  0;
            Record.Reason[1] =  reset;
            Rte_Enter_ExclusiveArea_Misc();

            for (i=0;i<RESET_INFOMATION_RECORD_NUMBER-1;i++)
            {
                memcpy(&Misc_NvmResetInfomation.Record[RESET_INFOMATION_RECORD_NUMBER-i-1],
                       &Misc_NvmResetInfomation.Record[RESET_INFOMATION_RECORD_NUMBER-i-2],
                       sizeof(Misc_ResetRecord_t));
            }

            memcpy(&Misc_NvmResetInfomation.Record[0],
                    &Record,
                    sizeof(Misc_ResetRecord_t));
            Misc_NvmResetInfomation.ResetTimes++;
            if ((reset == McuRstRsnConfWdta0) || (reset == McuRstRsnConfWdta1))
            {
                Misc_NvmResetInfomation.WatchDogCounter++;
            }
            Rte_Exit_ExclusiveArea_Misc();
            Misc_Diag_WriteResetRecordToRam();
            ReasetRecordExecuteState = RESET_INFOMATION_WAIT_WRITE;
        }
        else
        {
            ReasetRecordExecuteState = RESET_INFOMATION_CHECK_SOURCE;
        }
    }
    else
    {
        if (ReasetRecordExecuteState != RESET_INFOMATION_WAIT_WRITE)
        {
            ReasetRecordExecuteState = RESET_INFOMATION_DONE;
        }
    }
    
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_WriteResetSourc(void)
{
    Std_ReturnType returnValue = E_NOT_OK;
    returnValue = Rte_Call_NvMService_AC3_Defs_NvBlockNeed_ResetInfomation_WriteBlock(NULL_PTR);
    if (returnValue == E_OK)
    {
        ReasetRecordExecuteState = RESET_INFOMATION_DONE;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_ResetRecordTask(void)
{
    switch(ReasetRecordExecuteState)
    {
        case RESET_INFOMATION_CHECK_SOURCE:
            Misc_Diag_CheckResetSourc();
            break;
        case RESET_INFOMATION_WAIT_WRITE:
            Misc_Diag_WriteResetSourc();
            break;
        default:
			/* nothing to do */
            break;
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_CheckANTDiag(Misc_DiagIO_t * io,uint8 sens)
{
    uint8 i;
    
    for (i = 0; i<SenseState_Num; i++)
    {
		if(FALSE == Misc_PowerWasMPQ2022())
		{
	        if (
	            (io->u32ANTDiagAdc[sens] <= Misc_TunerParagraphing[i].max)&&
	            (io->u32ANTDiagAdc[sens] >= Misc_TunerParagraphing[i].min)
	            )
	        {
	            io->bTunerState[sens][i] = TRUE;
	            
	            break;
	        }
		}
		else
		{
			if(TRUE == MPQ2022_ANTDTC_Check(sens,i))
			{
				io->bTunerState[sens][i] = TRUE;
				
				break;
			}
		}

    }
    io->u8GlobalTunerState[sens] = i;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_CheckRVCDiag(Misc_DiagIO_t * io)
{
    uint8 i;
    
    for (i = 0; i<SenseState_Num; i++)
    {
		if(FALSE == Misc_PowerWasMPQ2022())
		{
	        if (
	            (io->u32RvcAdc <= Misc_RVCParagraphing[i].max)&&
	            (io->u32RvcAdc >= Misc_RVCParagraphing[i].min)
	            )
	        {
	            io->bRvcState[i] = TRUE;
	            break;
	        }
		}
		else
		{
			if(TRUE == MPQ2022_RVCDTC_Check(i))
			{
	            io->bRvcState[i] = TRUE;
	            break;
			}
		}
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_CheckGnssDiag(Misc_DiagIO_t * io)
{
    uint8 i;
    
    for (i = 0; i<SenseState_Num; i++)
    {
		if(FALSE == Misc_PowerWasMPQ2022())
		{
		    if (
		        (io->u32GnssAdc <= Misc_GnssParagraphing[i].max)&&
		        (io->u32GnssAdc >= Misc_GnssParagraphing[i].min)
		        )
		    {
		        io->bGnssState[i] = TRUE;
		        break;
		    }
		}
		else
		{
			if(TRUE == MPQ2022_GNSSDTC_Check(i))
			{
				io->bGnssState[i] = TRUE;
				break;
			}
		}
    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_TunerFilter(Misc_DiagIO_t * io,uint8 sens)
{
    uint8 i;
    for (i = 0; i<SenseState_Num; i++)
    {		
        io->bTunerUpdataFuel[sens][i] = Misc_Diag_Filter_Signal(&TunerRetardationConfig[sens][i],(uint8)io->bTunerState[sens][i]);
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_RVCFilter(Misc_DiagIO_t * io)
{
    uint8 i;
    for (i = 0; i<SenseState_Num; i++)
    {
        io->bRvcUpdataFuel[i] = Misc_Diag_Filter_Signal(&RVCRetardationConfig[i],(uint8)io->bRvcState[i]);
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_GNSSFilter(Misc_DiagIO_t * io)
{
    uint8 i;
    for (i = 0; i<SenseState_Num; i++)
    {
        io->bGnssUpdataFuel[i] = Misc_Diag_Filter_Signal(&GNSSRetardationConfig[i],(uint8)io->bGnssState[i]);
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_TunerCheckDemEvent(Misc_DiagIO_t * io,uint8 sens)
{
    uint8 i;
    for (i=0; i<SenseState_Num;i++)
    {
        if (TunerFilterInfo[sens][i].state == TRUE)
        {
            io->eTunerDemEvent[sens][i] = DEM_EVENT_STATUS_FAILED;
        }
        else
        {
            io->eTunerDemEvent[sens][i] = DEM_EVENT_STATUS_PASSED;
        }
        
    }

}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_RVCCheckDemEvent(Misc_DiagIO_t * io)
{
    uint8 i;
    for (i=0; i<SenseState_Num;i++)
    {
        if (RVCFilterInfo[i].state == TRUE)
        {
            io->eRvcDemEvent[i] = DEM_EVENT_STATUS_FAILED;
        }
        else
        {
            io->eRvcDemEvent[i] = DEM_EVENT_STATUS_PASSED;
        }
        
    }

}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_GNSSCheckDemEvent(Misc_DiagIO_t * io)
{
    uint8 i;
    for (i=0; i<SenseState_Num;i++)
    {
        if (GNSSFilterInfo[i].state == TRUE)
        {
            io->eGnssDemEvent[i] = DEM_EVENT_STATUS_FAILED;
        }
        else
        {
            io->eGnssDemEvent[i] = DEM_EVENT_STATUS_PASSED;
        }
        
    }

}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_TunerCheckLock(Misc_DiagIO_t * io)
{
	static uint8 u8PowerOffDelayCnt[ANT_P_Diag_Num]={0,0} ;
	static boolean bTunerErrOccur[ANT_P_Diag_Num] = {FALSE,FALSE};
	uint8 i = ANT1_P_Diag;//hardware only have ANT1
	for(;i<ANT_P_Diag_Num;i++)
	{
		if(FALSE == bTunerErrOccur[i])
		{
			//except SenseState_OpenLoad , check other status
			if ((io->bTunerState[i][SenseState_ShortToBattery] == TRUE) && (TunerFilterInfo[i][SenseState_ShortToBattery].state == TRUE))
			{
				bTunerErrOccur[i] = TRUE;
			}
			else if ((io->bTunerState[i][SenseState_Short] == TRUE) && (TunerFilterInfo[i][SenseState_Short].state == TRUE))
			{
				bTunerErrOccur[i] = TRUE;
			}
			else if ((io->bTunerState[i][SenseState_OverCurrent] == TRUE) && (TunerFilterInfo[i][SenseState_OverCurrent].state == TRUE))
			{
				bTunerErrOccur[i] = TRUE;
			}
			//
			if(TRUE == bTunerErrOccur[i])
			{
				u8PowerOffDelayCnt[i] = 0;
				Misc_DiagSelf.TunerLock[i] = TRUE;
				Dio_WriteChannel(DioConf_DioChannel_VIP_TUNER_ANT_EN_3V3,STD_LOW);
				//
				misc_warn("[MISC-I]ErrOccur,TunerEnSetLow,TunerLock=%d\r\n",Misc_DiagSelf.TunerLock[i]);
				printfMiscAdcInfo(io);
			}
		}
		else
		{
			if(u8PowerOffDelayCnt[i]++ >= MISC_DIAG_TUNER_POWEROFF_DELAY_CNT)
			{
				bTunerErrOccur[i] = FALSE;
				u8PowerOffDelayCnt[i] = 0;
				Misc_DiagSelf.TunerLock[i] = FALSE;
		        Dio_WriteChannel(DioConf_DioChannel_VIP_TUNER_ANT_EN_3V3,STD_HIGH);
				//
				memset(&TunerFilterInfo[i],0,sizeof(TunerFilterInfo[i]));
				misc_warn("[MISC-I]ErrRelease,TunerEnSetHigh,TunerLock=%d\r\n",Misc_DiagSelf.TunerLock[i]);
				printfMiscAdcInfo(io);
			}
		}
	}
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_RVCCheckLock(Misc_DiagIO_t * io)
{
	static uint8 u8PowerOffDelayCnt=0;
	static boolean bRVCErrOccur = FALSE;

	if(FALSE == bRVCErrOccur)
	{
		//except SenseState_OpenLoad , check other status
		if ((io->bRvcState[SenseState_ShortToBattery] == TRUE) && (RVCFilterInfo[SenseState_ShortToBattery].state == TRUE))
		{
			bRVCErrOccur = TRUE;
		}
		else if ((io->bRvcState[SenseState_Short] == TRUE) && (RVCFilterInfo[SenseState_Short].state == TRUE))
		{
			bRVCErrOccur = TRUE;
		}
		else if ((io->bRvcState[SenseState_OverCurrent] == TRUE) && (RVCFilterInfo[SenseState_OverCurrent].state == TRUE))
		{
			bRVCErrOccur = TRUE;
		}
		//
		if(TRUE == bRVCErrOccur)
		{
			u8PowerOffDelayCnt = 0;
			Misc_DiagSelf.RVCLock = TRUE;
			Dio_WriteChannel(DioConf_DioChannel_VIP_POC_PWREN,STD_LOW);
			//
			misc_warn("[MISC-I]ErrOccur,RVCEnSetLow,RVCLock=%d\r\n",Misc_DiagSelf.RVCLock);
			printfMiscAdcInfo(io);
		}
	}
	else
	{
		if(u8PowerOffDelayCnt++ >= MISC_DIAG_RVC_POWEROFF_DELAY_CNT)
		{
			bRVCErrOccur = FALSE;
			u8PowerOffDelayCnt = 0;
			Misc_DiagSelf.RVCLock = FALSE;
	        Dio_WriteChannel(DioConf_DioChannel_VIP_POC_PWREN,STD_HIGH);
			//
			memset(&RVCFilterInfo,0,sizeof(RVCFilterInfo));
			misc_warn("[MISC-I]ErrRelease,RVCEnSetHigh,RVCLock=%d\r\n",Misc_DiagSelf.RVCLock);
			printfMiscAdcInfo(io);
		}
	}
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_GNSSCheckLock(Misc_DiagIO_t * io)
{
	static uint8 u8PowerOffDelayCnt=0;
	static boolean bGNSSErrOccur = FALSE;

	if(FALSE == bGNSSErrOccur)
	{
		//except SenseState_OpenLoad , check other status
		if ((io->bGnssState[SenseState_ShortToBattery] == TRUE) && (GNSSFilterInfo[SenseState_ShortToBattery].state == TRUE))
		{
			bGNSSErrOccur = TRUE;
		}
		else if ((io->bGnssState[SenseState_Short] == TRUE) && (GNSSFilterInfo[SenseState_Short].state == TRUE))
		{
			bGNSSErrOccur = TRUE;
		}
		else if ((io->bGnssState[SenseState_OverCurrent] == TRUE) && (GNSSFilterInfo[SenseState_OverCurrent].state == TRUE))
		{
			bGNSSErrOccur = TRUE;
		}
		//
		if(TRUE == bGNSSErrOccur)
		{		
			u8PowerOffDelayCnt = 0;
			Misc_DiagSelf.GNSSLock = TRUE;
			Dio_WriteChannel(DioConf_DioChannel_VIP_GPSANT_POWER_EN_3V3,STD_LOW);
			//
	        misc_warn("[MISC-I]ErrOccur,GNSSEnSetLow,GNSSLock=%d\r\n",Misc_DiagSelf.GNSSLock);
			printfMiscAdcInfo(io);
		}
	}
	else
	{
		if(u8PowerOffDelayCnt++ >= MISC_DIAG_GNSS_POWEROFF_DELAY_CNT)
		{
			bGNSSErrOccur = FALSE;
			u8PowerOffDelayCnt = 0;
			Misc_DiagSelf.GNSSLock = FALSE;
	        Dio_WriteChannel(DioConf_DioChannel_VIP_GPSANT_POWER_EN_3V3,STD_HIGH);
			//
			memset(&GNSSFilterInfo,0,sizeof(GNSSFilterInfo));
			misc_warn("[MISC-I]ErrRelease,GNSSEnSetHigh,GNSSLock=%d\r\n",Misc_DiagSelf.GNSSLock);
			printfMiscAdcInfo(io);
		}
	}
}
/***********************************************************************
 * @brief       : 4.11.1 Read Radio Antenna Status -AM(FM1)/FM2/DAB/SDARS
 * @param       : 
 * @retval      : 
 ***********************************************************************/

static void Misc_Diag_WriteTunerDid(void)
{
    uint8 buffer[3];
    buffer[0] = TunerDidState[ANT1_P_Diag];
    buffer[1] = 0;
    buffer[2] = 0;
    (void)Rte_Write_Misc_EOL_RadioAntennaStatus_0xFDD0_RadioAntennaStatus_0xFDD0(buffer);
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_CheckChangeCounter(Misc_DiagIO_t * io)
{
    if (io->u32ChangeCounter != Misc_DiagSelf.u32ChangeCounterBack)
    {
        misc_info("Init Dtc State,because ChangeCounter(0x%X) != ChangeCounterBack(0x%X)",
            io->u32ChangeCounter,Misc_DiagSelf.u32ChangeCounterBack);
        Misc_DiagSelf.u32ChangeCounterBack = io->u32ChangeCounter;
        Misc_Diag_InitDtcState();
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_Diag_InitDtcState(void)
{
	//clear DID
    memset(&MicDidState,(uint8)MISC_DIDPOSITIVE_RESPONSE_CONNECTED,sizeof(MicDidState));
    memset(&TunerDidState,(uint8)MISC_DIDPOSITIVE_RESPONSE_CONNECTED,sizeof(TunerDidState));

	//clear inner state
    memset(&sMicFilterInfo,0,sizeof(sMicFilterInfo));
    memset(&bMicLastFuel,0,sizeof(bMicLastFuel));
    
    memset(&TunerFilterInfo,0,sizeof(TunerFilterInfo));
    memset(&RVCFilterInfo,0,sizeof(RVCFilterInfo));

    memset(&GNSSFilterInfo,0,sizeof(GNSSFilterInfo));

    Misc_DiagSelf.TunerCnt = 0;
}

/***********************************************************************
 * @brief       : precondition1 was When voltage out of  (9v ~ 16v) condition,
                  clear all inner variable , to make DTC don't report
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_PreConditon1_NotMatch_ClearInnerState(void)
{
	//clear DID
    memset(&MicDidState,(uint8)MISC_DIDPOSITIVE_RESPONSE_CONNECTED,sizeof(MicDidState));
    memset(&TunerDidState,(uint8)MISC_DIDPOSITIVE_RESPONSE_CONNECTED,sizeof(TunerDidState));

	//clear FM all-DTC inner state
    memset(&TunerFilterInfo,0,sizeof(TunerFilterInfo));
	
	//clear MIC all-DTC inner state
    memset(&sMicFilterInfo,0,sizeof(sMicFilterInfo));
    memset(&bMicLastFuel,0,sizeof(bMicLastFuel));
	
	//clear GPS all-DTC inner state
    memset(&GNSSFilterInfo,0,sizeof(GNSSFilterInfo));
}

/***********************************************************************
 * @brief       : precondition2 was When voltage low than 12v 
                  clear BAT inner variable , to make DTC don't report
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Misc_PreConditon2_NotMatch_ClearInnerState(void)
{
	uint8 i=0;
	//clear FM BAT-DTC inner state
	for(i=ANT1_P_Diag;i<ANT_P_Diag_Num;i++)
	{
	    memset(&TunerFilterInfo[i][SenseState_ShortToBattery],0,sizeof(Misc_DiagFilterInfo_t));
	}

	//clear MIC BAT-DTC inner state
	for(i=0;i<MIC_VIP_SENS_NUMBER;i++)
	{
	    memset(&sMicFilterInfo[i][MIC_VIP_SENS_Filter_BAT],0,sizeof(Misc_DiagFilterInfo_t));
	    memset(&bMicLastFuel[i][MIC_VIP_SENS_Filter_BAT],0,1);
	}
	
	//clear GPS BAT-DTC inner state
    memset(&GNSSFilterInfo[SenseState_ShortToBattery],0,sizeof(Misc_DiagFilterInfo_t));
	
	//clear RVC BAT-DTC inner state
    memset(&RVCFilterInfo[SenseState_ShortToBattery],0,sizeof(Misc_DiagFilterInfo_t));
}


