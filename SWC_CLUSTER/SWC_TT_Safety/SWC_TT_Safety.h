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
*File Name   : SWC_TT_SAFETY.h                                                                            *
*                                                                                                         *
*Description : SAFETY TELLTALE application head file.                                                     *
*                                                                                                         *
*Author      : liyafei                                                                                    *
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
#ifndef TT_SAFETY_H
#define TT_SAFETY_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
//#include "system.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
//#include "SWC_SM_Config.h"

/**********************************************************************************************************
*	Output Application Interface Accuary                                                                  *
**********************************************************************************************************/

#include "Std_Types.h"
#include "Platform_Types.h"
#include "Compiler.h"
#include "logger.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#ifdef GWM_V35_PROJECT_TYPE_B02 
	#define SWC_TT_SAFETY_PROJECT_TYPE_B02
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define SWC_TT_SAFETY_PROJECT_TYPE_B03
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define SWC_TT_SAFETY_PROJECT_TYPE_P03
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define SWC_TT_SAFETY_PROJECT_TYPE_P05
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define SWC_TT_SAFETY_PROJECT_TYPE_A07
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define SWC_TT_SAFETY_PROJECT_TYPE_D01
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define SWC_TT_SAFETY_PROJECT_TYPE_D02
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define SWC_TT_SAFETY_PROJECT_TYPE_D03
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define SWC_TT_SAFETY_PROJECT_TYPE_P02
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define SWC_TT_SAFETY_PROJECT_TYPE_P01
#else
	#error  project type is invalid !!
#endif

// STT LOG
#define SWC_STT_LOGOUT_ENBLE TRUE
#define SWC_STT_PRINT_WARN   fuel_warn

/*****************************************************************************
*                                 Type Decleration                           *
*----------------------------------------------------------------------------*
* Decleration of type shall be accompanied by a comment that explains the    *
* purpose and usage of the type.                                             *
******************************************************************************/

typedef enum
{
	STT_FUN_INACTIVE = 0,
	STT_FUN_ACTIVE,
	STT_FUN_STANDBY,
	STT_FUN_RESERVE,
	STT_FUN_FAILURE
}STT_FUN_ENUM;

typedef enum
{
  STT_NO_DOMAIN,
  STT_DOMAIN_CH,
  STT_DOMAIN_US
}STT_DOMAIN_INFO;
/*此枚举定义用于表示Byte4决定的地域划分配置,不同数据对应的意义如下:
  1.TT_NO_DOMAIN        地域错误
  2.TT_DOMAIN_CH        国内（地域划分目前只有两种，一种是国内，欧洲等，另外一种是北美，只有北美和其他地域不同，因此非北美的统称为国内）
  3.TT_DOMAIN_US        北美*/

typedef enum
{
	STT_LDW_STS = 1,
	STT_LKA_STS,
	STT_LCK_STS
}STT_LDW_FUN_ENUM;

typedef enum
{
	STT_EPB_UNDEFINED = 0,
	STT_EPB_NO_ERROR,
	STT_EPB_ERROR,
	STT_EPB_DIAG
}STT_EPB_FUN_ENUM;

typedef enum
{
	STT_PBF_INSTRUMENT_DISPLAY = (uint8)3,
	STT_PBF_RANGE_LIMITED,
	STT_PBF_PRECHARGE_LOCKED,
	STT_PBF_DELAYED_OPEN,
	STT_PBF_EMERGENCY_OPEN
}STT_PBF_FUN_ENUM;

typedef enum
{
	STT_EBD_UNDEFINED = 0,
	STT_EBD_ABS_ESP,
	STT_EBD_IBC
}STT_ABS_EBD_CONFIG;

/*safety TT status*/
typedef enum
{
    TT_enTURN_OFF = 0,
    TT_enTURN_ON,
    /*****************************************************************************************************/
    /*Do not delete any status which above this line*/
    /*****************************************************************************************************/
    TT_enFLASH_1_HZ,
    TT_enFLASH_2_HZ,
    TT_enFLASH_4_HZ,
    TT_enFLASH_1_HZ_50,

//Add new status type here 此处添加新的状态
//Save reserved telltale 此处保留预留状态
#if 0
TT_enFLASH_0_33_HZ,
TT_enFLASH_HALF_HZ,
TT_enFLASH_1_HZ_50,
TT_enFLASH_1_33_HZ,
TT_enFLASH_2_66_HZ,
TT_enFLASH_4_HZ,
TT_enFLASH_5_HZ,
#endif

    TT_enSTATUS_TOTAL_NUMBER,
    /*TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER is only include off , on and self check status*/
    //TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER = (TT_enSELF_CHECK + 1),
    /*TT_enKEEP_PREVIOUS is always greater than TT_enSTATUS_TOTAL_NUMBER*/
    TT_enKEEP_PREVIOUS = TT_enSTATUS_TOTAL_NUMBER + 1
}TT_Safety_CFG_enStatType;

/* safety TT table*/
typedef enum
{
    enSTT_ABS_Fault_CH = 1,     //ABS故障Ch
    enSTT_ABS_Fault_US,         //ABS故障US
    enSTT_ESP_Enable,           //电子稳定系统工作
    enSTT_ESP_Disable,          //电子稳定系统关闭
    enSTT_EPB_Fault_CH,         //电动驻车故障CHINA
    enSTT_EPB_Fault_US,         //电动驻车故障US
    enSTT_BreakError_CH,        //制动系统故障CHINA
    enSTT_BreakError_US,        //制动系统故障US
    enSTT_EPS_Red_Error,        //电动助力转向持续性故障
    enSTT_EPS_Yellow_Error,     //电动助力转向短暂性性故障
    enSTT_ABM_Error,            //安全气囊报警
    enSTT_FCW_Error,            //前方碰撞故障
    enSTT_FCW_Enable,           //前方碰撞使能
    enSTT_PBF_Red,              //动力电池故障红灯
    enSTT_PBF_Yellow,           //动力电池故障黄灯
    enSTT_HEV_Yellow,           //混合动力系统故障黄灯
    enSTT_HEV_Red,              //混合动力系统故障红灯
    enSTT_TPF,                  //12V电源故障
    enSTT_Power_Reduction,      //降功率报警指示灯
    enSTT_EPark,                //E-park指示灯
    enSTT_DC_Alert,             //DC/DC报警灯
    enSTT_Motor_Failure,        //电机故障
    enSTT_FCW_Off,              //前方碰撞OFF指示灯

// tips: add new TT here
    TT_SAFETY_TOTAL_NUMBER
}TT_SAFETY_enTelltaleID;

/*CAN message enum*/
typedef enum
{
    STT_enABS3_ESPFD2,    // ABS故障 & 制动系统故障
    STT_enESP1_ESFD2,     // 电子稳定系统-工作&关闭
    STT_enEPB1,           // 电动驻车故障
    STT_enEPS1_EPSFD1,    // 电动助力转向故障-红色&黄色
    STT_enABM1,           // 安全气囊故障
    //STT_enAEBFD2,       // 前方碰撞-关闭&工作&故障
    STT_enBMS4,           // 动力电池故障红色&黄色
    STT_enHCUPT7,         // 混合动力系统故障 & 12V电源故障
    STT_enEPARK1,         // E-park指示灯
    STT_enDCDCFD1,        // DC/DC报警灯
    //STT_enMCUFD1,       // 电机故障

// tips: add new CAN message here, used for E2E
    STT_enCANNUM_MAX
}STT_CAN_E2E_STS;


/*SOC->MCU：all TT, used for CRC*/
typedef enum
{
    TT_enUnkown,
    TT_enEngineSysFault,       //发动机系统故障
    TT_enEngineFix,            //发动机维修
    TT_enCruiseControl,        //定速巡航
    TT_enEngineHighTemp,       //发动机水温高
    TT_enTJA_Enable,           //智能巡航工作
    TT_enACC_Enable,           //自适应巡航工作
    TT_enTJA_Disable,          //智能巡航未工作
    TT_enACC_Disable,          //自适应巡航未工作
    TT_enTJA_Fault,            //智能巡航故障
    TT_enACC_Fault,            //自适应巡航故障
    TT_enSS_Enable,            //智能启停工作
    TT_enSS_Fault,             //智能启停故障
    TT_enBatteryCharge,        //蓄电池充放电
    TT_enLowFuelPress,         //机油压力低
    TT_enAutoPark_Enable,      //自动驻车工作
    TT_enAutoPark_Fault,       //自动驻车故障
    TT_enABS_Fault_CH,         //ABS故障Ch 0xeb75 0x49FA 0x6dbb
    TT_enABS_Fault_US,         //ABS故障US 0xb80b 0xAF13 0xbbda
    TT_enESP_Enable,           //电子稳定系统工作 0x8e72 0x4EEC 0x0e30
    TT_enESP_Disable,          //电子稳定系统关闭 0x90b9 0xD851 0x40ca
    TT_enHSD,                  //陡降指示灯
    TT_enEPB_Enable_CH,        //电动驻车报警CHINA
    TT_enEPB_Enable_US,        //电动驻车报警US
    TT_enEPB_Fault_CH,         //电动驻车故障CHINA 0x1bb5 0x19C3 0x1795
    TT_enEPB_Fault_US,         //电动驻车故障US 0xc607 0x03CB 0xa120
    TT_enDPB_Enable_CH,        //动态驻车报警CHINA
    TT_enDPB_Enable_US,        //动态驻车故障US
    TT_enIbooster_Yellow_CH,   //Ibooster指示灯黄色CHINA
    TT_enIbooster_Yellow_US,   //Ibooster指示灯黄色US
    TT_enIbooster_Red_CH,      //Ibooster指示灯红色CHINA
    TT_enIbooster_Red_US,      //Ibooster指示灯红色US
    TT_enBreakError_CH,        //制动系统故障CHINA 0x6c09 0xF10F 0xdfdf
    TT_enBreakError_US,        //制动系统故障US 0xcbae 0xA4A1 0x5638
    TT_en120KMH,               //120KM/H超速报警
    TT_enFront_Fog,            //前雾灯
    TT_enRear_Fog,             //后雾灯
    TT_enHigh_Beam,            //远光灯
    TT_enTurn_Left,            //左转向灯
    TT_enTurn_Right,           //右转向灯
    TT_enPosition,             //位置灯
    TT_enLightSwitch,          //灯光总开关
    TT_enTrailer,              //拖车转向灯
    TT_enDoorOpen,             //门开报警
    TT_enTPMS,                 //胎压报警
    TT_enEPS_Yellow_Error,     //电动助力转向故障黄灯 0x40bd
    TT_enEPS_Red_Error,        //电动助力转向故障红灯 0x6946 0xB4A6 0x6897
    TT_enABM_Error,            //安全气囊报警 0x422b 0x0499 0xc4a2
    TT_enSeat_Belt,            //安全带未系
    TT_enTrans_OverHeat,       //变速器过热
    TT_enAuto_Green,           //自动远光灯绿色
    TT_enAuto_Yellow,          //自动远光灯黄色
    TT_enLowFuel,              //低燃油报警
    TT_enFCW_Enable,           //前方碰撞报警
    TT_enFCW_Error,            //前方碰撞故障 0xf1d5 0x9BAB 0xb177
    TT_enLDW_Enable,           //LDW工作
    TT_enLDW_Error,            //LDW故障
    TT_enLKA_Enable,           //LKA工作
    TT_enLKA_Error,            //LKA故障
    TT_enLCK_Enable,           //LCK工作
    TT_enLCK_Error,            //LCK故障
    TT_enReady_Light,          //READY指示灯
    TT_enEV_Indicator,         //EV指示灯
    TT_enPBF_Yellow,           //动力电池故障黄灯 0x6b51
    TT_enPBF_Red,              //动力电池故障红灯  0x0035 0x499D 0x3185
    TT_enHEV_Yellow,           //混合动力系统故障黄灯 0xd20a 0x650D 0xe0eb
    TT_enHEV_Red,              //混合动力系统故障红灯 0xb341 0xF73E 0xf223
    TT_enTPF,                  //12V电源故障 0x3587 0xF935 0x5347
    TT_enCharging_Green,       //充电指示绿灯
    TT_enCharging_Red,         //充电指示红灯
    TT_enCharging_E_Yellow,    //充电系统轻微故障
    TT_enCharging_E_Red,       //充电系统严重故障
    TT_enSecondary_Warning,    //次要报警
    TT_enMajor_Warning,        //重要报警
    TT_enPower_Reduction,      //降功率报警指示灯
    TT_enParking,              //驻车指示灯 0xe018 0x63D2 0xc457
    TT_enRBS,                  //制动能量回收
    TT_enEngine_Warmup,        //发动机预热(TBD)
    TT_enBrakePad_Worn,        //刹车片磨损
    TT_enCCO_Active,           //CCO功能激活
    TT_enCCO_Standby,          //CCO功能待机
    TT_enCCO_Inactive,         //CCO功能故障
    TT_enFEDL_Active,          //前桥电子差速工作
    TT_enFEDL_Inactive,        //前桥电子差速故障
    TT_enREDL_Active,          //后桥电子差速工作
    TT_enREDL_Inactive,        //后桥电子差速故障
    TT_enHSAP_Standby,         //高速单车道自动驾驶待激活
    TT_enHSAP_Active,          //高速单车道自动驾驶激活
    TT_enHSAP_Error,           //高速单车道自动驾驶故障
    TT_enHSAS_Switch,          //高速自动变道辅助开关
    TT_enHSAS_Active,          //高速自动变道激活
    TT_enHSAS_Standby,         //高速自动变道待激活
    TT_enHSAS_Error,           //高速自动变道故障
    TT_enAUX,                  //并线辅助
    TT_enRSW,                  //倒车侧向警告
    TT_enSAS_Error,            //侧后辅助系统故障
    TT_enSAS_Limit,            //侧后辅助系统受限
    TT_enSteer_Assit_Open,     //转向辅助开启
    TT_enSteer_Assit_Work,     //转向辅助工作
    TT_enSteer_Assit_Error,    //转向辅助故障
    TT_enEPark,                //E-park指示灯
    TT_enDC_Alert,             //DC/DC报警灯  0x3587 0xF935 0x5347
    TT_enSound_Reminder_Red,   //声音提示系统红灯
    TT_enSound_Reminder_Yellow,//声音提示系统黄灯
    TT_enMotor_Failure,        //电机故障 0xbbcb 0xD501 0x71c0
    TT_enBatteryPack_Charge,   //电池组充电
    TT_enBattery_Off,          //蓄电池切断
    TT_enLow_Battery,          //动力电池低电量
    TT_enRSCA_Off,             //RSCA OFF
    TT_en2H_Indicator,         //2H指示灯
    TT_en4H_Indicator,         //4H指示灯
    TT_en4L_Indicator,         //4L指示灯
    TT_enSingle_Pedal,         //单踏板
    TT_enTSR_Speed_Limit,      //TSR限速标志
    TT_enTSR_Traffic_Sign,     //TSR道路标识
    TT_enDrive_Mode,           //DriverMode

    TT_enTELLTALE_TOTAL_NUMBER
}TT_enCrcTelltaleID;

typedef struct
{
    boolean SelfCheckSts;
    uint8 Safety_TT_Data;
}SAFETY_TT_ST;

typedef struct
{
  uint8 Safety_TT_E2E_Flag;
} SAFETY_TT_E2E_FLAG;

typedef struct
{
    uint8 u8VcfgInit;
    uint8 u8Byte4_Domain;
    uint8 u8Byte26_Service;
    uint8 u8Byte26_Parking;
    uint8 u8Byte25_Steering;
    uint8 u8Byte10_FCW;
    uint8 u8Byte46_Junction;
    uint8 u8Byte2_Fuel;
    uint8 u8Byte30_Electro;
    uint8 u8Byte41_Epark0;
} SAFETY_TT_CFG;

typedef struct
{
	uint8 TT_ID;
	uint32 CRC_Value;
}TT_SAFETY_CRC_t;

/**************************************************************************************/
/*A07自检播报功能*/
#define STT_CFG_SelfcheckReport_COUNT    (13u)
#define STT_CFG_SelfcheckReport_LIST    \
{    \
    enSTT_ABS_Fault_CH,     \
    enSTT_ABS_Fault_US,     \
    enSTT_ESP_Enable,       \
    enSTT_EPB_Fault_CH,     \
    enSTT_EPB_Fault_US,     \
    enSTT_BreakError_CH,    \
    enSTT_BreakError_US,    \
    enSTT_EPS_Red_Error,    \
    enSTT_EPS_Yellow_Error, \
    enSTT_ABM_Error,        \
    enSTT_FCW_Error,        \
    enSTT_PBF_Red,          \
    enSTT_PBF_Yellow,       \
}

#ifdef GWM_V35_PROJECT_TYPE_B02
#define SEFETY_TT_CFG_CRC_TABLE	\
{		       /* Safety TT crc  */\
			 0x0000, \
/* 0*/	 	 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 1*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6dbb,0xbbda,0x0e30,0x40ca, \
/* 2*/		 0x0000,0x0000,0x0000,0x1795,0xa120,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 3*/		 0x0000,0xdfdf,0x5638,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 4*/		 0x0000,0x0000,0x0000,0x0000,0x40bd,0x6897,0xc4a2,0x0000,0x0000,0x0000, \
/* 5*/		 0x0000,0x0000,0x0000,0xb177,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 6*/		 0x0000,0x0000,0x6b51,0x3185,0xe0eb,0xf223,0x5347,0x0000,0x0000,0x0000, \
/* 7*/		 0x0000,0x0000,0x0000,0x0000,0xc457,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 8*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 9*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 10*/		 0x5347,0x0000,0x0000,0x71c0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
			 0x0000,0x0000,0x0000,0x0000,0x0000 \
}
#elif defined GWM_V35_PROJECT_TYPE_B03
#define SEFETY_TT_CFG_CRC_TABLE	\
{		       /* Safety TT crc  */\
			 0x0000, \
/* 0*/	 	 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 1*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6dbb,0xbbda,0x0e30,0x40ca, \
/* 2*/		 0x0000,0x0000,0x0000,0x1795,0xa120,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 3*/		 0x0000,0xdfdf,0x5638,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 4*/		 0x0000,0x0000,0x0000,0x0000,0x40bd,0x6897,0xc4a2,0x0000,0x0000,0x0000, \
/* 5*/		 0x0000,0x0000,0x0000,0xb177,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 6*/		 0x0000,0x0000,0x6b51,0x3185,0xe0eb,0xf223,0x5347,0x0000,0x0000,0x0000, \
/* 7*/		 0x0000,0x0000,0x0000,0x0000,0x41f9,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 8*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 9*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 10*/		 0x5347,0x0000,0x0000,0x71c0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
			 0x0000,0x0000,0x0000,0x0000,0x0000 \
}
#elif defined GWM_V35_PROJECT_TYPE_P03
#define SEFETY_TT_CFG_CRC_TABLE	\
{		       /* Safety TT crc  */\
			 0x0000, \
/* 0*/	 	 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 1*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x5021,0x0a88,0x1552,0xda69, \
/* 2*/		 0x0000,0x0000,0x0000,0x4f61,0xd898,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 3*/		 0x0000,0x0ffc,0x88d1,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 4*/		 0x0000,0x0000,0x0000,0x0000,0x6338,0x13af,0xb4cc,0x0000,0x0000,0x0000, \
/* 5*/		 0x0000,0x0000,0x8733,0xb177,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 6*/		 0x0000,0x0000,0x1276,0x4894,0x4ca6,0x1e0c,0x5566,0x0000,0x0000,0x0000, \
/* 7*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 8*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 9*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xf917, \
/* 10*/		 0x5566,0x0000,0x0000,0x71c0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
			 0x0000,0x0000,0x0000,0x0000,0x0000 \
}
#elif defined GWM_V35_PROJECT_TYPE_P05
#define SEFETY_TT_CFG_CRC_TABLE	\
{		       /* Safety TT crc  */\
			 0x0000, \
/* 0*/	 	 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 1*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x5021,0x0a88,0x1552,0xda69, \
/* 2*/		 0x0000,0x0000,0x0000,0x4f61,0xd898,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 3*/		 0x0000,0x7981,0x88d1,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 4*/		 0x0000,0x0000,0x0000,0x0000,0x6338,0x13af,0x0d7c,0x0000,0x0000,0x0000, \
/* 5*/		 0x0000,0x0000,0x8F3D,0xb177,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 6*/		 0x0000,0x0000,0x1276,0x4894,0x4ca6,0x1e0c,0x5566,0x0000,0x0000,0x0000, \
/* 7*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 8*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 9*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xf917, \
/* 10*/		 0x5566,0x0000,0x0000,0x71c0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
			 0x0000,0x0000,0x0000,0x0000,0x0000 \
}
#elif defined GWM_V35_PROJECT_TYPE_A07
#define SEFETY_TT_CFG_CRC_TABLE	\
{		       /* Safety TT crc  */\
			 0x0000, \
/* 0*/	 	 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 1*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x5021,0x0a88,0x1552,0xda69, \
/* 2*/		 0x0000,0x0000,0x0000,0x4f61,0x2c5d,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 3*/		 0x0000,0x0ffc,0x88d1,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 4*/		 0x0000,0x0000,0x0000,0x0000,0x6338,0x13af,0xb4cc,0x0000,0x0000,0x0000, \
/* 5*/		 0x0000,0x0000,0x8F3D,0xb177,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 6*/		 0x0000,0x0000,0x1276,0x4894,0x4ca6,0x1e0c,0x5566,0x0000,0x0000,0x0000, \
/* 7*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 8*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 9*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xf917, \
/* 10*/		 0x5566,0x0000,0x0000,0x71c0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
			 0x0000,0x0000,0x0000,0x0000,0x0000 \
}
#elif defined GWM_V35_PROJECT_TYPE_D01
#define SEFETY_TT_CFG_CRC_TABLE	\
{		       /* Safety TT crc  */\
			 0x0000, \
/* 0*/	 	 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 1*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6dbb,0xbbda,0x0e30,0x40ca, \
/* 2*/		 0x0000,0x0000,0x0000,0x1795,0xa120,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 3*/		 0x0000,0xdfdf,0x5638,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 4*/		 0x0000,0x0000,0x0000,0x0000,0x6705,0x6897,0xc4a2,0x0000,0x0000,0x0000, \
/* 5*/		 0x0000,0x0000,0x8733,0xb177,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 6*/		 0x0000,0x0000,0x4397,0x3185,0x5D06,0xf223,0x95F9,0x0000,0x0000,0x0000, \
/* 7*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 8*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 9*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xf917, \
/* 10*/		 0x5347,0x0000,0x0000,0x71c0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
			 0x0000,0x0000,0x0000,0x0000,0x0000 \
}
#elif defined GWM_V35_PROJECT_TYPE_D02
#define SEFETY_TT_CFG_CRC_TABLE	\
{		       /* Safety TT crc  */\
			 0x0000, \
/* 0*/	 	 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 1*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6dbb,0xbbda,0x0e30,0x40ca, \
/* 2*/		 0x0000,0x0000,0x0000,0x1795,0xa120,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 3*/		 0x0000,0xdfdf,0x5638,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 4*/		 0x0000,0x0000,0x0000,0x0000,0x6705,0x6897,0xc4a2,0x0000,0x0000,0x0000, \
/* 5*/		 0x0000,0x0000,0x8733,0xb177,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 6*/		 0x0000,0x0000,0x4397,0x3185,0x5D06,0xf223,0x95F9,0x0000,0x0000,0x0000, \
/* 7*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 8*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 9*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xf917, \
/* 10*/		 0x5347,0x0000,0x0000,0x71c0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
			 0x0000,0x0000,0x0000,0x0000,0x0000 \
}
#elif defined GWM_V35_PROJECT_TYPE_D03
#define SEFETY_TT_CFG_CRC_TABLE	\
{		       /* Safety TT crc  */\
			 0x0000, \
/* 0*/	 	 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 1*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6dbb,0xbbda,0x1552,0xda69, \
/* 2*/		 0x0000,0x0000,0x0000,0x1795,0xa120,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 3*/		 0x0000,0xdfdf,0x5638,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 4*/		 0x0000,0x0000,0x0000,0x0000,0xa865,0xda3e,0x0d7c,0x0000,0x0000,0x0000, \
/* 5*/		 0x0000,0x0000,0x8733,0xb177,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 6*/		 0x0000,0x0000,0x90d5,0x37ab,0x4ca6,0x1e0c,0x5347,0x0000,0x0000,0x0000, \
/* 7*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 8*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 9*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xf917, \
/* 10*/		 0x5347,0x0000,0x0000,0x71c0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
			 0x0000,0x0000,0x0000,0x0000,0x0000 \
}
#elif defined GWM_V35_PROJECT_TYPE_P02
#define SEFETY_TT_CFG_CRC_TABLE	\
{		       /* Safety TT crc  */\
			 0x0000, \
/* 0*/	 	 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 1*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6dbb,0xbbda,0x0e30,0x40ca, \
/* 2*/		 0x0000,0x0000,0x0000,0x1795,0xa120,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 3*/		 0x0000,0xdfdf,0x5638,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 4*/		 0x0000,0x0000,0x0000,0x0000,0x6705,0x6897,0xc4a2,0x0000,0x0000,0x0000, \
/* 5*/		 0x0000,0x0000,0x8733,0xb177,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 6*/		 0x0000,0x0000,0x4397,0x3185,0x5D06,0xf223,0x95F9,0x0000,0x0000,0x0000, \
/* 7*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 8*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 9*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xf917, \
/* 10*/		 0x5347,0x0000,0x0000,0x71c0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
			 0x0000,0x0000,0x0000,0x0000,0x0000 \
}
#elif defined GWM_V35_PROJECT_TYPE_P01
#define SEFETY_TT_CFG_CRC_TABLE	\
{		       /* Safety TT crc  */\
			 0x0000, \
/* 0*/	 	 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 1*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x6dbb,0xbbda,0x0e30,0x40ca, \
/* 2*/		 0x0000,0x0000,0x0000,0x1795,0xa120,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 3*/		 0x0000,0xdfdf,0x5638,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 4*/		 0x0000,0x0000,0x0000,0x0000,0x6705,0x6897,0xc4a2,0x0000,0x0000,0x0000, \
/* 5*/		 0x0000,0x0000,0x8733,0xb177,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 6*/		 0x0000,0x0000,0x4397,0x3185,0x5D06,0xf223,0x95F9,0x0000,0x0000,0x0000, \
/* 7*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 8*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
/* 9*/		 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xf917, \
/* 10*/		 0x5347,0x0000,0x0000,0x71c0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, \
			 0x0000,0x0000,0x0000,0x0000,0x0000 \
}

#endif
/*****************************************************************************
*                                 Global Function Prototypes                 *
******************************************************************************/

#define Common_Safety_START_SEC_CODE
#include "Common_Safety_MemMap.h"

FUNC(void, RTE_CODE) IPC_API_ReceiveSafetyTTCRCCallback(uint8 *data);

extern void STT_Function_Safety_TimeTask(void);
extern void STT_Function_Safety_Init(void);
extern void TT_Api_Get_TTSelfCheck_Sts(const uint8 *data);
extern void STT_TTErrorCallback(const uint8 *data);
extern void STT_Function_Safety_PreOff_Logic(void);

#define Common_Safety_STOP_SEC_CODE
#include "Common_Safety_MemMap.h"


#endif
/**********************************************************************************************************
*  End Of File                                                                                            *
**********************************************************************************************************/



