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
*File Name   : TT_Config.h                                                                                *
*                                                                                                         *
*Description : Telltale module configuration head file.                                                   *
*                                                                                                         *
*Author      : Chao Feng                                                                                  *
*                                                                                                         *
*Platform    : Free Rtos System                                                    						  *
*                                                                                                         *
*Compiler    : Green Hills MULTI IDE                                                                      *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family                                                       *
*                                                                                                         *
*Version     : 1.0.0                                                                                      *
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef TT_CFG_H
#define TT_CFG_H
/**********************************************************************************************************
* External Function Include                                                                               *
* Pay Attention : Do Not Add Any Other Head File Here Without System Standard Head File !!!				  *
**********************************************************************************************************/
/*请注意 : 不要在这个文件内添加任何除系统标准类型定义外的头文件,请在TT_Adapt.h内添加引用!!!*/
#include "Compiler.h"
#include "Platform_Types.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	System Configuration                                                                                  *
*																								          *
*																								          *
**********************************************************************************************************/
/*Define this macro to enable telltale function
此宏定义开关整个报警灯模块的应用功能.通过预编译将给系统的接口内对应逻辑的控制实现开关.
其中,定义为TRUE表示打开功能,FALSE表示关闭功能*/

#define TT_CFG_TELLTALE_FUNCTION		(TRUE)

/*********************************************************************************************************/
/*Define this macro to enable debug mode
此宏定义用于开关报警灯模块的调试功能.通过打开调试功能可以更方便的调试代码,实现如下功能:
1.对一些特定类型定义进行错误检测.在TT_Core.c文件TT_CORE_vCheckModuleConfigration函数中实现.
2.对每个闪烁状态以及每个报警灯的状态结构体添加名称戳,调试打印时便于定位具体灯.
其中,定义为TRUE表示打开功能,FALSE表示关闭功能*/

#define TT_CFG_DEBUG					(FALSE)

/*********************************************************************************************************/
/*This macro to definition represents the period of a cyclic task
此宏定义用于表示报警灯模块主周期任务函数的执行周期,计算时间计数时会用到该宏定义*/

#define TT_CFG_TIME_TASK_CYCLE			(20u)//ms

/**********************************************************************************************************
* Output Mode Configuration																				  *
**********************************************************************************************************/
/***/                                                                                                 /***/
/***/          #define  TT_CFG_OUTPUT_USE_GPIO      0x01                                              /***/
/***/          #define  TT_CFG_OUTPUT_USE_STM       0x02                                              /***/
/***/          #define  TT_CFG_OUTPUT_ON_CAN        0x04                                              /***/
/***/          #define  TT_CFG_OUTPUT_ON_SBUS       0x01                                              /***/
/***/                                                                                                 /***/
/*********************************************************************************************************/
/*此宏定义用于配置不同的报警灯输出方式,此配置可以同时配置多种输出方式.不同配置对应的功能如下:
1.TT_CFG_OUTPUT_USE_GPIO 表示输出方式包括MCU I/O口输出.
2.TT_CFG_OUTPUT_USE_STM  表示输出方式包括串转并芯片输出.
3.TT_CFG_OUTPUT_ON_CAN   表示输出方式包括CAN信号输出.
4.TT_CFG_OUTPUT_ON_SBUS  表示输出方式包括SBUS协议输出.*/

#define TT_CFG_OUTPUT_MODE  ( TT_CFG_OUTPUT_USE_GPIO ) // |

/**********************************************************************************************************
*																								          *
*																								          *
*	Lamp Status Type Definition																			  *
*																								          *
*																								          *
**********************************************************************************************************/
typedef enum
{
	TT_enLAMP_OFF_EDGE = 0,
	TT_enLAMP_OFF      = 1,
	TT_enLAMP_ON_EDGE  = 2,
	TT_enLAMP_ON       = 3
	/*Do not add any other lamp status*/
}TT_enLampStatus;
/*请注意 : 不可以修改这个枚举定义!!!
此枚举定义用于表示报警灯的点亮状态.不同状态对应的意义如下:
1.TT_enLAMP_OFF_EDGE 表示报警灯关闭时下降沿时刻的状态,实际状态处于关闭.此状态为初始默认状态.
2.TT_enLAMP_OFF      表示报警灯关闭时的状态.
3.TT_enLAMP_ON_EDGE  表示报警灯打开时上升沿时刻的状态,实际状态处于打开.
4.TT_enLAMP_ON       表示报警灯打开时的状态.
***********************************************************************************************************
*																										  *
*	|<-			  Lamp Off				->|<-			  Lamp On				 ->|					  *
*	OffEdge								  OnEdge									OffEdge(Loop)		  *
*---------------------------------------------------------------------------------------------------------*

**********************************************************************************************************/
/**********************************************************************************************************
*																								          *
*																								          *
*	Lamp Flash Type Configuration																		  *
*																								          *
*																								          *
**********************************************************************************************************/
typedef enum
{
	TT_enTURN_OFF = 0,
	TT_enTURN_ON,
	TT_enSELF_CHECK,/*can not set in logic process*/
	/*****************************************************************************************************/
	/*Do not delete any status which above this line*/
	/*****************************************************************************************************/
	TT_enFLASH_1_HZ = 3,
	TT_enFLASH_2_HZ,
	TT_enFLASH_4_HZ,
	TT_enFLASH_1_HZ_50,

	//Add new status type here 此处添加新的状态
#if 0//Save reserved telltale 此处保留预留状态
	TT_enFLASH_0_33_HZ,
	TT_enFLASH_HALF_HZ,
	TT_enFLASH_1_HZ_50,
	TT_enFLASH_1_33_HZ,
	TT_enFLASH_2_66_HZ,
	TT_enFLASH_4_HZ,
	TT_enFLASH_5_HZ,
#endif
	/*****************************************************************************************************/
	TT_enSTATUS_TOTAL_NUMBER,
	/*TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER is only include off , on and self check status*/
	TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER = (TT_enSELF_CHECK + 1),
	/*TT_enKEEP_PREVIOUS is always greater than TT_enSTATUS_TOTAL_NUMBER*/
	TT_enKEEP_PREVIOUS = TT_enSTATUS_TOTAL_NUMBER + 1
}TT_CFG_enStatusType;
/*请注意 : 不可以修改以下这几个枚举定义!!!
(1)TT_enTURN_OFF; (2)TT_enTURN_ON; (3)TT_enSELF_CHECK; (4)TT_enSTATUS_TOTAL_NUMBER;
(5)TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER; (6)TT_enKEEP_PREVIOUS;
此枚举定义用于定义和表示报警灯的逻辑闪烁状态,并作为索引使用.可以针对不同项目添加需要的闪烁状态.

添加定义的命名方式: TT_enFLASH + 闪烁频率
Example:
(1)TT_enFLASH_1_HZ       1Hz闪烁逻辑状态

闪烁逻辑状态的定义可以增加或减少,默认固定状态对应的意义如下:
1.TT_enTURN_OFF      表示关闭逻辑状态.
2.TT_enTURN_ON       表示打开逻辑状态.
3.TT_enSELF_CHECK    表示自检逻辑状态.请注意这个状态无法通过应用逻辑设置,而是通过状态机判断设置的.
											此处定义是为了方便状态机索引,以及通过对应接口读取到该状态.
4.TT_enSTATUS_TOTAL_NUMBER    所有逻辑状态数量,用于判断和计算.
5.TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER    默认逻辑状态数量,用于判断和计算.
6.TT_enKEEP_PREVIOUS    表示保持当前的逻辑状态,便于应用逻辑表示和设置;

Tips:
当需添加新的闪烁逻辑状态时,只需在该枚举定义对应的位置上先添加即可生成索引,然后在本文件
宏定义TT_CFG_FLASH_ATTRIBUTE内添加该闪烁对应的参数即可.*/
/**********************************************************************************************************
* Flash Attribute Structure Definition																	  *
**********************************************************************************************************/
typedef struct
{
	uint16 u16CycleCount;
	uint8  u8Offset; /*Range:0-100 Actual:0-100%*/
	uint8  u8Duty;   /*Range:0-100 Actual:0-100%*/
	/*Percentage of rising edge synchonzation . When telltale control attribute set "TT_enON_AT_EDGE_TRIGGER",
	this parameter will be valid. It means telltale will on at rising edge and some time delay , how long this
	time is depend on this parameter.
	Formula : CycleCount * Duty(%) * Parameter(%)*/
	uint8  u8RisingEdgeSyncPercent;   /*Range:0-100 Actual:0-100%*/
	/*Similar to the above*/
	uint8  u8FaillingEdgeSyncPercent; /*Range:0-100 Actual:0-100%*/
}TT_tstFlashAttribute;
/*此结构体定义用于表示闪烁逻辑状态的各项参数,不同参数对应的意义如下:

1.u16CycleCount
表示对应闪烁逻辑状态的周期计数值.当等于该值时计数器清零并循环.
计算方式:

根据频率的计算公式:计数值 = 每秒执行的本模块主周期任务数 / 频率

根剧闪烁周期时长的计算公式:计数值 = 闪烁周期时长 / 每秒执行的本模块主周期任务数

2.u8Offset
表示初始相位百分比.该值为设置对应闪烁逻辑状态的初始计数值.
范围0-100.表示0-100%.在调试模式下会进行错误检测.

计算公式: 初始计数值 = 周期计数值 * 相位百分比

3.u8Duty
表示占空比百分比.该值为设置对应闪烁逻辑状态的占空比值.
范围1-99.表示1-99%,0%等同于关闭,100%等同于常亮.在调试模式下会进行错误检测.

计算公式: 占空比计数值 = 周期计数值 * 占空百分比

4.u8RisingEdgeSyncPercent
表示上升沿同步的百分比值.此配置表示了当报警灯配置了上升沿同步属性
(TT_enON_AT_RISING_EDGE_TRIGGER)时,从上升沿时刻点开始同步的时间范围.即定义了上升沿同步区间.
百分比的起始时间为上升沿时刻.配置为0表示仅在上升沿的时刻同步,配置为100表示任何时刻都会同步,
等同于未配置上升沿同步属性.
范围0-100.表示0-100%.在调试模式下会进行错误检测.
默认配置0%即可,但当需求要求响应时间苛刻且最美观时,可适当调整该配置,例如当一个频率0.66Hz占空比50%的闪烁,
要求最大响应时间为1000ms.其中根据计算每周期点亮时间为750ms,所以该配置为(1000-750)/750 = 33%.
即当一个报警灯状态变为该闪烁时,既能满足最大响应时间,该闪烁的初次点亮时长最小为500ms.避免了快闪.

计算公式: 同步区间计数值 = 周期计数值 * ((1 - 占空百分比) + (占空百分比 * 上升沿同步百分比))

5.u8FaillingEdgeSyncPercent
表示下降沿同步的百分比值.此配置表示了当报警灯配置了下降沿同步属性
(TT_enOFF_AT_FAILLING_EDGE_TRIGGER)时,从下降沿时刻点开始同步的时间范围.即定义了下降沿同步区间.
百分比的起始时间为上升沿时刻,与u8RisingEdgeSyncPercent属性参考起始点相同.
配置为0表示任何时刻都会同步,等同于未配置下降沿同步属性,配置为100表示仅在下降沿的时刻同步.
范围0-100.表示0-100%.在调试模式下会进行错误检测.
默认配置100%即可,但当需求要求响应时间苛刻且最美观时,可适当调整该配置,例如当一个频率0.66Hz占空比50%的闪烁,
要求最大响应时间为500ms.其中根据计算每周期点亮时间为750ms,所以该配置为500/750 = 66%.
即当一个报警灯状态从该闪烁变为熄灭时,既能满足最大响应时间,该闪烁最后一次点亮时长最小为500ms.避免了快闪.

计算公式: 同步区间计数值 = 周期计数值 * ((1 - 占空百分比) + (占空百分比 * 下降沿同步百分比))

***********************************************************************************************************
*	 |<-			  Lamp Off				->|<-			  Lamp On				 ->|				  *
*	 OffEdge								OnEdge									OffEdge(Loop)		  *
*---------------------------------------------------------------------------------------------------------*
*											  |<-	 RisingSync    ->|									  *
*																|<-	 FaillingSync	 ->|				  *
*											  0%                50%                  100%				  *
******************************************************************************************************** */

/**********************************************************************************************************
*																								          *
*																								          *
*	Flash Attribute Configuration																		  *
*																								          *
*																								          *
**********************************************************************************************************/
/**********************************************************************************************************
* Lamp Flash Type Configuration																			  *
**********************************************************************************************************/

#define TT_CFG_FLASH_COUNT_FACTOR        (1000/TT_CFG_TIME_TASK_CYCLE)
#define FTT_CFG_SelfcheckReport_COUNT	(6)
#define FTT_CFG_SelfcheckReport_COUNT2	(6)

/*此宏定义用于快捷计算闪烁逻辑状态的周期计数值.*/
/*********************************************************************************************************/
/* FlashTypeName                  CycleCount        Frequency  Offset Duty  RisingEdge  FaillingEdge
*																			SyncPercent  SyncPercent  */
#define TT_CFG_FLASH_ATTRIBUTE  {\
/*TT_enFLASH_1_HZ*/   {((uint16)1000/TT_CFG_TIME_TASK_CYCLE    ),(0),  (50), (0),      (100)},\
/*TT_enFLASH_2_HZ*/   {((uint16)1000/TT_CFG_TIME_TASK_CYCLE/2  ),(0),  (50), (0),      (100)},\
/*TT_enFLASH_4_HZ*/   {((uint16)1000/TT_CFG_TIME_TASK_CYCLE/4  ),(0), (50), (0),       (100)},\
/*TT_enFLASH_1_HZ_50*/{((uint16)1000/TT_CFG_TIME_TASK_CYCLE    ),(50),  (50), (0),      (100)},\
}



//Add new flash attribute here 此处添加新的闪烁属性
#if 0 /*Save reserved flash type*/
/*TT_enFLASH_0_33_HZ*/{((UINT16)1000/TT_CFG_TIME_TASK_CYCLE*3  ), (5000), (0),    (0), (10000)},\
/*TT_enFLASH_HALF_HZ*/{((UINT16)1000/TT_CFG_TIME_TASK_CYCLE*2  ), (5000), (0),    (0), (10000)},\
/*TT_enFLASH_1_HZ_1*/ {((UINT16)1000/TT_CFG_TIME_TASK_CYCLE    ), (5000), (5000), (0), (10000)},\
/*TT_enFLASH_1_33_HZ*/{((UINT16)1000/TT_CFG_TIME_TASK_CYCLE*3/4), (5000), (0),    (0), (10000)},\
/*TT_enFLASH_2_66_HZ*/{((UINT16)1000/TT_CFG_TIME_TASK_CYCLE*3/8), (5000), (0),    (0), (10000)},\
/*TT_enFLASH_4_HZ*/   {((UINT16)1000/TT_CFG_TIME_TASK_CYCLE/4  ), (5000), (0),    (0), (10000)},\
/*TT_enFLASH_5_HZ*/   {((UINT16)1000/TT_CFG_TIME_TASK_CYCLE/5  ), (5000), (0),    (0), (10000)},
#endif
/*此宏定义用于配置参照闪烁状态属性参数,根据具体项目需求定义.*/
/**********************************************************************************************************
* Flash Status Structure Definition																		  *
**********************************************************************************************************/
typedef struct
{
#if (TT_CFG_DEBUG == TRUE)
	TT_CFG_enStatusType enFlashName; /*Enable at debug mode*/
#endif
	union
	{
		uint8 u8Status[1];
		struct
		{
			TT_enLampStatus LightType     :2 ; /*TT_enLampStatus*/
			uint8 RisingEdgeSync          :1 ; /*0x1:TRUE or 0x0:FALSE*/
			uint8 FaillingEdgeSync        :1 ; /*0x1:TRUE or 0x0:FALSE*/
			uint8 Reserved                :3 ;
		}stStatus;
	}unStatus;
}TT_tstFlashControlStatus;
/*此结构体定义用于表示客观参考闪烁状态的状态参数,不同参数对应的意义如下:
1.enFlashName       闪烁名称,当调试模式时开启,方便调试确认该闪烁的名称.
2.LightType         点亮熄灭状态,类型为TT_enLampStatus.
3.RisingEdgeSync    点亮上升沿同步标志位,有效时该标志位为1,否则为0.
4.FaillingEdgeSync  熄灭下降沿同步标志位,有效时该标志位为1,否则为0.
5.Reserved          可根据项目添加针对每个闪烁状态的独立标志位.*/
/**********************************************************************************************************
*																										  *
*																										  *
*	Telltale Type Configuration																			  *
*																										  *
*																										  *
**********************************************************************************************************/
typedef enum
{
	enFTT_EngineSysFault = 0,    //发动机系统故障
	enFTT_EngineFix,            //发动机维修
	enFTT_CruiseControl,        //定速巡航
	enFTT_EngineHighTemp,       //发动机水温高
	enFTT_ACC_Enable,           //自适应巡航工作
	enFTT_ACC_Disable,          //自适应巡航未工作
	enFTT_ACC_Fault,            //自适应巡航故障
	enFTT_TJA_Enable,           //智能巡航工作
	enFTT_TJA_Disable,          //智能巡航未工作
	enFTT_TJA_Fault,            //智能巡航故障
	enFTT_SS_Enable,            //智能启停工作
	enFTT_SS_Fault,             //智能启停故障
	enFTT_BatteryCharge,        //蓄电池充放电
	enFTT_LowFuelPress,         //机油压力低
	enFTT_AutoPark_Enable,      //自动驻车工作
	enFTT_AutoPark_Fault,       //自动驻车故障
	enFTT_ABS_Fault_CH,         //ABS故障Ch
	enFTT_ABS_Fault_US,         //ABS故障US
	enFTT_ESP_Enable,           //电子稳定系统工作
	enFTT_ESP_Disable,          //电子稳定系统关闭
	enFTT_HSD,                  //陡降指示灯
	enFTT_EPB_Enable_CH,        //电动驻车报警CHINA
	enFTT_EPB_Enable_US,        //电动驻车报警US
	enFTT_EPB_Fault_CH,         //电动驻车故障CHINA
	enFTT_EPB_Fault_US,         //电动驻车故障US
	enFTT_DPB_Enable_CH,        //动态驻车报警CHINA
	enFTT_DPB_Enable_US,        //动态驻车故障US
	enFTT_BreakError_CH,        //制动系统故障CHINA
	enFTT_BreakError_US,        //制动系统故障US
	enFTT_Ibooster_Yellow_CH,   //Ibooster指示灯黄色CHINA
	enFTT_Ibooster_Red_CH,      //Ibooster指示灯红色CHINA
	enFTT_Ibooster_Yellow_US,   //Ibooster指示灯黄色US
	enFTT_Ibooster_Red_US,      //Ibooster指示灯红色US
	enFTT_120KMH,               //120KM/H超速报警
	enFTT_TSR_Speed_Limit,      //TSR限速标志
	enFTT_TSR_Traffic_Sign,     //TSR道路标识
	enFTT_Front_Fog,            //前雾灯
	enFTT_Rear_Fog,             //后雾灯
	enFTT_High_Beam,            //远光灯
	enFTT_Turn_Left,            //左转向灯
	enFTT_Turn_Right,           //右转向灯
	enFTT_Position,             //位置灯
	enFTT_LightSwitch,          //灯光总开关
	enFTT_Trailer,              //拖车转向灯
	enFTT_DoorOpen,             //门开报警
	enFTT_TPMS,                 //胎压报警
	enFTT_EPS_Yellow_Error,     //电动助力转向短暂性性故障
	enFTT_EPS_Red_Error,        //电动助力转向持续性故障
	enFTT_ABM_Error,            //安全气囊报警
	enFTT_Seat_Belt,            //安全带未系
	enFTT_Trans_OverHeat,       //变速器过热
	enFTT_Auto_Yellow,          //自动远光灯黄色
	enFTT_Auto_Green,           //自动远光灯绿色
	enFTT_LowFuel,              //低燃油报警
	enFTT_FCW_Enable,           //前方碰撞报警
	enFTT_FCW_Error,            //前方碰撞故障
	enFTT_LDW_Enable,           //LDW工作
	enFTT_LDW_Error,            //LDW故障
	enFTT_LKA_Enable,           //LKA工作
	enFTT_LKA_Error,            //LKA故障
	enFTT_LCK_Enable,           //LCK工作
	enFTT_LCK_Error,            //LCK故障
	enFTT_Ready_Light,          //READY指示灯
	enFTT_EV_Indicator,         //EV指示灯
	enFTT_PBF_Yellow,           //动力电池故障黄灯
	enFTT_PBF_Red,         		//动力电池故障红灯
	enFTT_HEV_Yellow,           //混合动力系统故障黄灯
	enFTT_HEV_Red,              //混合动力系统故障红灯
	enFTT_TPF,                  //12V电源故障
	enFTT_Charging_Green,       //充电指示绿灯
	enFTT_Charging_Red,         //充电指示红灯
	enFTT_Charging_E_Yellow,    //充电系统轻微故障
	enFTT_Charging_E_Red,       //充电系统严重故障
	enFTT_Secondary_Warning,    //次要报警
	enFTT_Major_Warning,        //重要报警
	enFTT_Power_Reduction,      //降功率报警指示灯
	enFTT_Parking,              //驻车指示灯
	enFTT_RBS,                  //制动能量回收
	enFTT_Engine_Warmup,        //发动机预热
	enFTT_BrakePad_Worn,        //刹车片磨损
	enFTT_CCO_Active,           //CCO功能激活
	enFTT_CCO_Standby,          //CCO功能待机
	enFTT_CCO_Inactive,         //CCO功能故障
	enFTT_FEDL_Active,          //前桥电子差速工作
	enFTT_FEDL_Inactive,        //前桥电子差速故障
	enFTT_REDL_Active,          //后桥电子差速工作
	enFTT_REDL_Inactive,        //后桥电子差速故障
	enFTT_HSAP_Standby,         //高速单车道自动驾驶待激活
	enFTT_HSAP_Active,          //高速单车道自动驾驶激活
	enFTT_HSAP_Error,           //高速单车道自动驾驶故障
	enFTT_HSAS_Switch,          //高速自动变道辅助开关
	enFTT_HSAS_Active,          //高速自动变道激活
	enFTT_HSAS_Standby,         //高速自动变道待激活
	enFTT_HSAS_Error,           //高速自动变道故障
	enFTT_AUX,                  //并线辅助
	enFTT_RSW,                  //倒车侧向警告
	enFTT_SAS_Error,            //侧后辅助系统故障
	enFTT_SAS_Limit,            //侧后辅助系统受限
	enFTT_Steer_Assit_Open,     //转向辅助开启
	enFTT_Steer_Assit_Work,     //转向辅助工作
	enFTT_Steer_Assit_Error,    //转向辅助故障
	enFTT_EPark,                //E-park指示灯
	enFTT_DC_Alert,             //DC/DC报警灯
	enFTT_Sound_Reminder_Red,   //声音提示系统红灯
	enFTT_Sound_Reminder_Yellow,//声音提示系统黄灯
	enFTT_Motor_Failure,        //电机故障
	enFTT_BatteryPack_Charge,   //电池组充电
	enFTT_Battery_Off,          //蓄电池切断
	enFTT_Low_Battery,          //动力电池低电量
	enFTT_RSCA_Off,             //RSCA OF
	enFTT_2H_Indicator,         //2H指示灯
	enFTT_4H_Indicator,         //4H指示灯
	enFTT_4L_Indicator,         //4L指示灯
	enFTT_Single_Pedal,         //单踏板
	enFTT_Low_Battery_White,    //动力电池低电量白灯 R17:已删除
	enFTT_OilWaterSeparation,   //油水分离指示灯
	enFTT_Adblue,               //尿素指示灯
	enFTT_V2X_GLOSA,            //V2X绿波车速引导
	enFTT_V2X_SpeedLimit,       //V2X限速预警
	enFTT_V2X_TrafficSign,      //V2X车内标牌
	enFTT_V2X_RLight1,          //V2X交通信号灯:车道1红色
	enFTT_V2X_YLight1,          //V2X交通信号灯:车道1黄色
	enFTT_V2X_GLight1,          //V2X交通信号灯:车道1绿色
	enFTT_V2X_RLight2,          //V2X交通信号灯:车道2红色
	enFTT_V2X_YLight2,          //V2X交通信号灯:车道2黄色
	enFTT_V2X_GLight2,          //V2X交通信号灯:车道2绿色
	enFTT_V2X_RLight3,          //V2X交通信号灯:车道3红色
	enFTT_V2X_YLight3,          //V2X交通信号灯:车道3黄色
	enFTT_V2X_GLight3,          //V2X交通信号灯:车道3绿色
	enFTT_V2X_RLight4,          //V2X交通信号灯:车道4红色
	enFTT_V2X_YLight4,          //V2X交通信号灯:车道4黄色
	enFTT_V2X_GLight4,          //V2X交通信号灯:车道4绿色
	enFTT_V2X_RLight5,          //V2X交通信号灯:车道5红色
	enFTT_V2X_YLight5,          //V2X交通信号灯:车道5黄色
	enFTT_V2X_GLight5,          //V2X交通信号灯:车道5绿色
	enFTT_V2X_RLight6,          //V2X交通信号灯:车道6红色
	enFTT_V2X_YLight6,          //V2X交通信号灯:车道6黄色
	enFTT_V2X_GLight6,          //V2X交通信号灯:车道6绿色
	enFTT_V2X_RLight7,          //V2X交通信号灯:车道7红色
	enFTT_V2X_YLight7,          //V2X交通信号灯:车道7黄色
	enFTT_V2X_GLight7,          //V2X交通信号灯:车道7绿色
	enFTT_AirSus_Red,           //空气悬架系统故障指示灯红灯
	enFTT_AirSus_Yellow,        //空气悬架系统故障指示灯黄灯
	enFTT_CDLL_Green,          //中央差速锁指示灯状态颜色：绿色
	enFTT_CDLL_Yellow,			//中央差速锁指示灯状态颜色：黄色
	//Add new telltale id here 此处添加新的报警灯索引
	TT_enTELLTALE_TOTAL_NUMBER
}TT_CFG_enTelltaleID;

/**************************************************************************************/
/*A07自检播报功能*/
#define FTT_CFG_SelfcheckReport_LIST \
{								\
/* self check */				\
	enFTT_EngineFix,			\
	enFTT_EngineHighTemp,		\
	enFTT_Ibooster_Yellow_CH,	\
	enFTT_Ibooster_Red_CH,		\
	enFTT_Ibooster_Yellow_US,	\
	enFTT_Ibooster_Red_US,		\
	enFTT_TPMS,					\
}

#define FTT_CFG_SelfcheckReport_LIST2 \
{								\
/* no self check*/				\
	enFTT_LDW_Error,			\
	enFTT_LKA_Error,			\
	enFTT_LCK_Error,			\
	enFTT_SAS_Error,			\
	enFTT_SAS_Limit,			\
	enFTT_Steer_Assit_Error,	\
	enFTT_SS_Fault,				\
}

//enFTT_EngineSysFault,    //发动机系统故障 单独判断
//enFTT_LowFuelPress,      //机油压力低 单独判断
//enFTT_Trans_OverHeat,    //变速器过热 单独判断

#if 0/*Save reserved telltale*/

#endif
/*请注意 : 不可以修改以下这几个枚举定义!!!
(1)TT_enTELLTALE_TOTAL_NUMBER;
此枚举定义用于定义和表示报警灯,并作为索引使用.可以针对不同项目添加需要的报警灯.

添加定义的命名方式: TT_en + 报警灯名称
Example:
(1)TT_enFuelLowWarning   燃油低报警灯
(2)TT_enFrontFogLight    前雾灯报警灯

报警灯的定义可以增加或减少,默认固定的状态对应的意义如下:
1.TT_enTELLTALE_TOTAL_NUMBER    所有报警灯数量,用于判断和计算.*/
/**********************************************************************************************************
* Telltale Work Mode Definition																			  *
**********************************************************************************************************/
typedef enum
{
	TT_enNULL_POWER_MODE = 0x0000,
	TT_enOFF = 0x0001,
	TT_enRUN = 0x0002,
	TT_enABNORMAL = 0x0004,
	TT_enSLEEP = 0x0008,
}TT_enWorkPowerMode;
/*此宏定义用于表示报警灯的工作状态,注意此处的工作状态稍微有别于整车电源状态和仪表电源状态.
该工作状态抽象表示的是报警灯不同的工作状态模式.在大部分的项目里这些工作状态由仪表电源状态决定.
所以可以约等同于仪表状态,但是可以针对项目做微调,如一般认为电源状态为关时报警灯工作状态为OFF模式,
但特殊情况下当背光有阻尼的完全关闭同加上电源状态为关时才认为工作状态为OFF模式.这样实际作用是为了美观而
使报警灯工作状态改变与背光熄灭同步.
此处也可以针对项目配置特殊的工作状态实现特殊的功能需求.
该定义需赋值为非互斥定义,同时配置单个报警灯表示同时支持多个状态下的工作.不配置报警灯为关闭.*/
/**********************************************************************************************************
* Telltale Control Attribute Definition 																  *
**********************************************************************************************************/
typedef enum
{
	TT_enNULL_ATTRIBUTE = 0x0000,
	/* Lamp on at a new flash cycle with delay ,so it always turn on at lamp on edge or synchonzation flag is 1 */
	TT_enON_AT_RISING_EDGE_TRIGGER = 0x0001,
	/* Lamp will not turn off even telltale logic is off , it will keep current status until this flash
		cycle is at lamp off edge or synchonzation flag is 1 */
	TT_enOFF_AT_FAILLING_EDGE_TRIGGER = 0x0002,
	/* When logic status from one flash type change to anther ,
		lamp will keep last flash cycle lamp status until that flash cycle is at lamp off edge or sync flag is 1 */
	TT_enKEEP_FLASH_STATUS_UNTIL_CURRENT_CYCLE_END = 0x0004,
	/* Telltale will keep previously when it work in ignition on response delay status , default logic is turn off*/
	TT_enIGN_ON_RESPONSE_DELAY_KEEP_PREVIOUSLY = 0x0008,
	/* Telltale will keep ign on response delay status until all telltale self check is finish ,
		then it begin start counting time*/
	TT_enIGN_ON_RESPONSE_DELAY_START_AFTER_ALL_SELF_CHECK_FINISH = 0x0010,
}TT_enControlAttribute;
/*请注意 : 不可以修改这个枚举定义!!!
此枚举定义用于表示报警灯的控制属性状态.不同属性对应的意义如下:

1.TT_enNULL_ATTRIBUTE
表示报警灯无任何特殊的控制属性,控制时按照默认逻辑处理.

2.TT_enON_AT_RISING_EDGE_TRIGGER
表示该报警灯在关闭切换到闪烁状态准备点亮时,第一个点亮周期会参考该闪烁的点亮上升沿同步参数.
如果该闪烁仅在上升沿时刻同步(0%),配置该控制属性后当状态从熄灭到闪烁点亮时,总是会完整的点亮整个闪烁周期.
一般报警灯存在闪烁状态时才需要考虑配置该属性.
注意配置该属性会影响响应时间,可以调整对应闪烁的参数来满足需求的响应时间.

3.TT_enOFF_AT_FAILLING_EDGE_TRIGGER
表示该报警灯在闪烁状态切换到关闭准备熄灭时,最后一个点亮周期会参考该闪烁的熄灭下降沿同步参数.
如果该闪烁仅在下降沿时刻同步(100%),配置该控制属性后当状态从闪烁点亮到熄灭时,总是会完整的亮完整个闪烁周期再熄灭.
一般报警灯存在闪烁状态时才需要考虑配置该属性.
注意配置该属性后会影响响应时间,可以调整对应闪烁的上升沿同步百分比参数来实现需求的响应时间.

4.TT_enKEEP_FLASH_STATUS_UNTIL_CURRENT_CYCLE_END
表示该报警灯在一种闪烁状态切换到另一种闪烁状态时,先前闪烁状态的熄灭会参考该闪烁的熄灭下降沿同步参数,
转变后的闪烁状态会参考该闪烁的点亮上升沿同步参数.当完整的闪烁完前一种闪烁状态的最后点亮周期后再切换到
新的闪烁状态,切换间隔的熄灭状态至少保持两者最短的熄灭时间,并且切换到的闪烁状态的第一次点亮周期也是完整的.
一般报警灯存在多种闪烁状态时才需要考虑配置该属性.
注意配置该属性后会影响响应时间,可以调整对应闪烁的下降沿同步百分比参数来实现需求的响应时间.

5.TT_enIGN_ON_RESPONSE_DELAY_KEEP_PREVIOUSLY
表示该报警灯在处于开点火延时状态时,状态为保持先前状态.报警灯处于开点火延时时默认为关闭状态.
这个属性用于可以同时工作在OFF状态和RUN状态的报警灯,在切换时刻点保持先前逻辑状态.
一般报警灯存在多种工作状态时才需要考虑配置该属性.

6.T_enIGN_ON_RESPONSE_DELAY_START_AFTER_ALL_SELF_CHECK_FINISH
表示该报警灯的开点火延时状态的开始计时条件是所有灯自检状态的结束,即在所有灯自检状态结束后才会开始开点火延时
这个配置用于当自检为亮几秒灭几秒的需求.当自检时间动态改变时开点火延时状态也会跟随结束时刻动态开始计时.

这些属性不为互斥配置,可以同时配置多个属性来实现功能.
这些控制属性的增减需要修改TT_Core.h代码来实现功能.*/
/**********************************************************************************************************
* Telltale Output Mode Definition																		  *
**********************************************************************************************************/
typedef enum
{
	TT_enNULL_OUTPUT_MODE = 0x0000,
	TT_enGPIO_POSITIVE_OUTPUT = 0x0001,
	TT_enGPIO_NEGATIVE_OUTPUT = 0x0002,
	TT_enSTM_POSITIVE_OUTPUT = 0x0004,
	TT_enSTM_NEGATIVE_OUTPUT = 0x0008,
	TT_enSBUS_OUTPUT = 0x0010,
	TT_enCAN_OUTPUT = 0x0020,
	TT_enHMI_OUTPUT = 0x0040,
}TT_enLampOutputMode;
/*请注意 : 不可以修改这个枚举定义!!!
此枚举定义用于表示报警灯的输出方式属性.不同方式对应的意义如下:

1.TT_enNULL_OUTPUT_MODE
表示报警灯无任何输出,无控制的外设或通信输出.

2.TT_enGPIO_POSITIVE_OUTPUT
表示报警灯输出方式为控制MCU I/O口.逻辑为正逻辑.

3.TT_enGPIO_NEGATIVE_OUTPUT
表示报警灯输出方式为控制MCU I/O口.逻辑为负逻辑.

4.TT_enSTM_POSITIVE_OUTPUT
表示报警灯输出方式为控制串转并芯片.逻辑为正逻辑.

5.TT_enSTM_NEGATIVE_OUTPUT
表示报警灯输出方式为控制串转并芯片.逻辑为负逻辑.

6.TT_enSBUS_OUTPUT
表示报警灯输出方式为SBUS通信方式.需在TT_Core.h文件TT__boSBUSTaskOperation函数内实现信号适配.

7.TT_enCAN_OUTPUT
表示报警灯输出方式为CAN通信方式.需在TT_Core.h文件TT__boCANOutputTaskOperation函数内实现信号适配.

8.TT_enHMI_OUTPUT
表示报警灯输出方式为内部直接传输通信方式.需在TT_Core.h文件TT__boHMIOutputTaskOperation函数内实现信号适配.

这些属性中GPIO和STM为互斥配置,共用u32OutputParameter作为接口数入参数,其他参数可以同时配置多个属性来实现功能.
这些控制属性的增减需要修改TT_Core.h代码来实现功能.*/
/**********************************************************************************************************
* Telltale Attribute Structure Definition 																  *
**********************************************************************************************************/
typedef void (*ptrLampOnOffOperation)(void);
typedef struct
{
	uint32				   u32WorkPowerMode;
	uint32				   u32ControlAttribute;
	uint32				   u32OutputMode;
	uint32				   u32OutputParameter;
	uint16				   u16IgnOnResponseDelayTime;
	uint16				   u16ExitAbnormalResponseDelayTime;
	uint16				   u16SelfCheckTime;
	uint8				   u8LightCountLimit;
	uint8				   u8StaticConfiguration;
	ptrLampOnOffOperation  vptrLampOnOperation;
	ptrLampOnOffOperation  vptrLampOffOperation;
}TT_tstTelltaleAttribute;
/*此结构体定义用于表示报警灯的各项属性参数,不同参数对应的意义如下:
1.u32WorkPowerMode       报警灯工作模式属性,涉及模式的定义在本模块,一般参考电源状态.
	Example:  TT_D1|TT_D2   表示报警灯工作在D1和D2模式下.
2.u32ControlAttribute    报警灯控制属性,支持的属性由TT_enControlAttribute枚举定义.具体说明参见该定义.
3.u32OutputMode          报警灯输出方式属性,支持的属性由TT_enLampOutputMode枚举定义.具体说明参见该定义.
4.u32OutputParameter     报警灯输出参数属性,当输出方式属性配置为GPIO或STM时作为调用接口的参数.
													其他输出配置可以忽略该参数.
请注意 : 不要在当前文件中引用定义该参数的头文件,请在TT_Adapt.h文件内添加具体引用!!!
5.u16IgnOnResponseDelayTime         报警灯开点火延时响应时间.单位为ms.
6.u16ExitAbnormalResponseDelayTime  报警灯退出异常模式延时响应时间.单位为ms.
7.u16SelfCheckTime                  报警灯自检时间.单位为ms.
8.u8LightCountLimit      报警灯切换到闪烁逻辑时的闪烁次数.这个计数会在当前闪烁切换到其他状态时清零.
													范围0-254.0xFF表示连续闪烁没有次数上限.
9.u8StaticConfiguration  报警灯静态开关.此开关为TRUE时报警灯功能正常,为FALSE时功能关闭,且无法在线开启.
10.vptrLampOnOperation   报警灯开时钩子函数配置.当报警灯每次点亮时调用该函数.该函数类型为ptrLampOnOffOperation.
11.vptrLampOffOperation  报警灯关时钩子函数配置.当报警灯每次熄灭时调用该函数.该函数类型为ptrLampOnOffOperation.
这些属性决定了报警灯的一般配置,针对项目需求对该配置进行修改.*/
/**********************************************************************************************************
*																								          *
*																								          *
*	Telltale Attribute Configuration																	  *
*																								          *
*																								          *
**********************************************************************************************************/
/**********************************************************************************************************
* Telltale Work Mode Attribute Definition																  *
**********************************************************************************************************/
#define TT_D1              (uint32)TT_enRUN
#define TT_D2              (uint32)TT_enOFF
#define TT_D3              (uint32)TT_enABNORMAL
/**********************************************************************************************************
* Telltale Control Attribute Definition																	  *
**********************************************************************************************************/
#define NULL_ABT           (uint32)TT_enNULL_ATTRIBUTE
#define RET                (uint32)TT_enON_AT_RISING_EDGE_TRIGGER
#define FET                (uint32)TT_enOFF_AT_FAILLING_EDGE_TRIGGER
#define KFS                (uint32)TT_enKEEP_FLASH_STATUS_UNTIL_CURRENT_CYCLE_END
#define RDKP               (uint32)TT_enIGN_ON_RESPONSE_DELAY_KEEP_PREVIOUSLY
#define RDASC              (uint32)TT_enIGN_ON_RESPONSE_DELAY_START_AFTER_ALL_SELF_CHECK_FINISH
/**********************************************************************************************************
* Telltale Output Attribute Definition																	  *
**********************************************************************************************************/
#define NULL_OP            (uint32)TT_enNULL_OUTPUT_MODE
#define GPIO_P             (uint32)TT_enGPIO_POSITIVE_OUTPUT
#define GPIO_N             (uint32)TT_enGPIO_NEGATIVE_OUTPUT
#define STM_P              (uint32)TT_enSTM_POSITIVE_OUTPUT
#define STM_N              (uint32)TT_enSTM_NEGATIVE_OUTPUT
#define SBUS               (uint32)TT_enSBUS_OUTPUT
#define CAN                (uint32)TT_enCAN_OUTPUT
#define HMI                (uint32)TT_enHMI_OUTPUT
/**********************************************************************************************************
* Telltale Other Attribute Definition																	  *
**********************************************************************************************************/
#define TT_NULL            (0)
#define TT_DO_NOTHING      (void *)0
#define TT_NOT_CONCERNED   (TRUE)
#define TT_TimeTask100ms	(0x5)
#define TT_TimeTask50ms		(0x2)
#define TT_TimeTask500ms	(0x19)
#define TT_CONTINUOUS      (0xFF)
/*********************************************************************************************************/
/* TelltaleName                     WorkPower       Attribute    Output    Output       IgnOnResponse   ExitAbnormal       SelfCheck     LightCount     Configuration     LampOn     LampOff
*									Mode            Mode         Mode      Parameter    DelayTime       ResponseDelayTime  Time          Limit          Switch            Hock       Hock      */
#define TT_CFG_TELLTALE_CONTROL_ATTRIBUTE  {\
/*enFTT_EngineSysFault*/          { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_EngineFix*/               { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_CruiseControl*/           { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_EngineHighTemp*/          { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_ACC_Enable*/              { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_ACC_Disable*/             { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_ACC_Fault*/	              { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_TJA_Enable*/              { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_TJA_Disable*/             { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_TJA_Fault*/               { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_SS_Enable*/               { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_SS_Fault*/                { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_BatteryCharge*/           { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_LowFuelPress*/            { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_AutoPark_Enable*/         { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_AutoPark_Fault*/          { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_ABS_Fault_CH*/            { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_ABS_Fault_US*/            { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_ESP_Enable*/              { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_ESP_Disable*/             { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_HSD*/                     { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_EPB_Enable_CH*/           { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_EPB_Enable_US*/           { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_EPB_Fault_CH*/            { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_EPB_Fault_US*/            { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_DPB_Enable_CH*/           { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_DPB_Enable_US*/           { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_BreakError_CH*/           { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_BreakError_US*/           { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Ibooster_Yellow_CH*/      { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Ibooster_Red_CH*/         { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Ibooster_Yellow_US*/      { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Ibooster_Red_US*/         { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_120KMH*/                  { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_TSR_Speed_Limit*/         { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_TSR_Traffic_Sign*/        { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Front_Fog*/               { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Rear_Fog*/                { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_High_Beam*/               { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Turn_Left*/               { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Turn_Right*/              { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Position*/                { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_LightSwitch*/             { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Trailer*/                 { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_DoorOpen*/                { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_TPMS*/                    { TT_D1 ,			 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_EPS_Yellow_Error*/        { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_EPS_Red_Error*/           { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_ABM_Error*/               { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Seat_Belt*/               { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Trans_OverHeat*/          { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Auto_Yellow*/             { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Auto_Green*/              { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_LowFuel*/                 { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000, 	TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_FCW_Enable*/              { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_FCW_Error*/               { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_LDW_Enable*/              { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_LDW_Error*/               { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_LKA_Enable*/              { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_LKA_Error*/               { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_LCK_Enable*/              { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0, 	  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_LCK_Error*/               { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Ready_Light*/             { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_EV_Indicator*/            { TT_D1 ,		     NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_PBF_Yellow*/              { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_PBF_Red*/                 { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000,  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_HEV_Yellow*/              { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_HEV_Red*/                 { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000,  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_TPF*/                     { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000,  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Charging_Green*/          { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Charging_Red*/            { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Charging_E_Yellow*/       { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Charging_E_Red*/          { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Secondary_Warning*/       { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Major_Warning*/           { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Power_Reduction*/         { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000,  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Parking*/                 { TT_D2 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_RBS*/                     { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000,  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Engine_Warmup*/           { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000,  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_BrakePad_Worn*/           { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_CCO_Active*/              { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_CCO_Standby*/             { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_CCO_Inactive*/            { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_FEDL_Active*/             { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_FEDL_Inactive*/           { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_REDL_Active*/             { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_REDL_Inactive*/           { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_HSAP_Standby*/            { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_HSAP_Active*/             { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_HSAP_Error*/              { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_HSAS_Switch*/             { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_HSAS_Active*/             { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_HSAS_Standby*/            { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_HSAS_Error*/              { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_AUX*/                     { TT_D1|TT_D2 ,  NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_RSW*/                     { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_SAS_Error*/               { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_SAS_Limit*/               { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Steer_Assit_Open*/        { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Steer_Assit_Work*/        { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Steer_Assit_Error*/       { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_EPark*/                   { TT_D1|TT_D2 ,	 NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_DC_Alert*/                { TT_D1 ,	 	   NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000,  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Sound_Reminder_Red*/      { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Sound_Reminder_Yellow*/   { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Motor_Failure*/           { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000,  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_BatteryPack_Charge*/      { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Battery_Off*/             { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)3000,  TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Low_Battery*/             { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 ,    (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_RSCA_Off*/                { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 , (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_2H_Indicator*/            { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 , (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_4H_Indicator*/            { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 , (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_4L_Indicator*/            { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)3000 , (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Single_Pedal*/            { TT_D1 ,	       NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 , (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Low_Battery_White*/       { TT_D1 ,	 	   NULL_ABT,	   SBUS , 		TT_NULL,			(uint16)0 , (uint16)0 ,   (uint16)0,     TT_CONTINUOUS , TRUE ,  TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_OilWaterSeparation*/      { TT_D1,		   NULL_ABT,	   SBUS ,		TT_NULL,			(uint16)0 ,    (uint16)0 ,	 (uint16)3000,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_Adblue*/                  { TT_D1,		   NULL_ABT,	   SBUS ,		TT_NULL,			(uint16)0 ,    (uint16)0 ,	 (uint16)3000,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_GLOSA*/               { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_SpeedLimit*/          { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_TrafficSign*/         { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_RLight1*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_YLight1*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_GLight1*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_RLight2*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_YLight2*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_GLight2*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_RLight3*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_YLight3*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_GLight3*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_RLight4*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_YLight4*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_GLight4*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_RLight5*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_YLight5*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_GLight5*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_RLight6*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_YLight6*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_GLight6*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_RLight7*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_YLight7*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_V2X_GLight7*/             { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_AirSus_Red*/              { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_AirSus_Yellow*/           { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,	 (uint16)0,	TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_CDLL_Green*/			  { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,   (uint16)0, TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
/*enFTT_CDLL_Yellow*/			  { TT_D1,         NULL_ABT,     SBUS ,     TT_NULL,      (uint16)3000,    (uint16)0 ,   (uint16)0, TT_CONTINUOUS , TRUE ,	TT_DO_NOTHING , TT_DO_NOTHING },\
}



//Add new telltale attribute configuration here 此处添加新的报警灯属性配置
#if 0/*Save reserved telltale attribute configuration */



#endif
/*此宏定义用于配置报警灯属性参数,根据具体项目需求配置.*/
/**********************************************************************************************************
* Telltale Control Status Structure Definition 															  *
**********************************************************************************************************/
typedef struct
{
#if (TT_CFG_DEBUG == TRUE)
	TT_CFG_enTelltaleID enTelltaleName;
#endif
	union
	{
		uint8 u8Status[5];
		struct
		{
			TT_CFG_enStatusType ResultLogicType     :4 ; /*16bit Length*/
			TT_CFG_enStatusType LogicType           :4 ; /*16bit Length*/
			TT_CFG_enStatusType ExternalLogicType   :4 ; /*16bit Length*/
			TT_CFG_enStatusType LastLogicType       :4 ; /*16bit Length*/
			TT_enLampStatus LightType               :2 ;
			TT_enLampStatus LastLightType           :2 ;
			uint8 ExternalControlStatus             :1 ; /*0x1:TRUE or 0x0:FALSE*/
			uint8 KeepLightStatus                   :1 ; /*0x1:TRUE or 0x0:FALSE*/
			uint8 IgnitionOnResponseDelayStatus     :1 ; /*0x1:TRUE or 0x0:FALSE*/
			uint8 ExitAbnormalDelayStatus           :1 ; /*0x1:TRUE or 0x0:FALSE*/
			uint8 SelfCheckStatus                   :1 ; /*0x1:TRUE or 0x0:FALSE*/
			uint8 DynamicConfigration               :1 ; /*0x1:TRUE or 0x0:FALSE*/
			uint8 DidConfigEnable                   :1 ;/*0x1:TRUE or 0x0:FALSE*/
			uint8 Vehselfchecksts                   :1 ;/*0x1:TRUE or 0x0:FALSE*/
			uint32 Reserved                         :13 ;
		}stStatus;
	}unStatus;
	uint8  u8CurrentLightCount;
	uint16 u16SelfCheckFinishTickCount;
	uint16 u16SelfCheckTimeTick;
	uint16 u16IgnOnDelayTimeTick;
}TT_tstTelltaleControlStatus;
/*此结构体定义用于表示报警灯的当前控制状态,不同参数对应的意义如下:
1.enTelltaleName     报警灯名称,当调试模式时开启,方便调试确认该报警灯的名称.
2.LogicType          当前逻辑函数设置的逻辑状态.在TT_Process.c文件内实现对应的逻辑函数.
3.ResultLogicType    经过状态机处理后的最终逻辑状态.该状态决定了报警灯最终有效逻辑状态.
4.ExternalLogicType  外部控制的逻辑状态.当报警灯外部控制标志位ExternalControlStatus有效时决定该报警灯显示状态.
5.LastLogicType      上一次有效处理后的逻辑状态.用于保持前次状态即KeepLightStatus有效时做参考用.
6.LightType          点亮熄灭状态.用于控制灯最终的显示状态.
7.LastLightType      上一次有效的点亮熄灭状态.用于在上升沿点亮或下降沿熄灭时保持前一次状态时做参考用.
8.ExternalControlStatus          外部控制标志位,如网络诊断可以通过使能这个标志位决定控制权.
								 并通过对ExternalLogicType赋值来对报警灯进行逻辑控制.
9.KeepLightStatus                保持前一次逻辑状态标志位.有效时会保持当前逻辑状态直到切换的条件满足.
10.IgnitionOnResponseDelayStatus 开点火延时响应标志位.有效时该报警灯处于开点火延时状态.具体状态由配置属性决定.
11.ExitAbnormalDelayStatus       退出异常延时响应标志位.有效时报警灯处于退出异常延时状态.此时报警灯关闭.
12.SelfCheckStatus               自检状态标志位.有效时报警灯处于自检状态.此时报警灯开启.
13.DynamicConfigration           动态开关标志位,有效时工作报警灯功能正常,无效时报警灯关闭.
								 如网络诊断配置可以设置这个标志位从而决定报警灯功能的开关.
13.1 DidConfigEnable             the did config status of each TT.
14.Reserved                      可根据项目添加针对每个报警灯的独立标志位.
15.u8CurrentLightCount           当前的闪烁次数.用于记录当前闪烁状态的次数.
16.u16SelfCheckFinishTickCount   自检结束的目标计数值.用于判断自检状态是否结束.也可以通过设定该值修改自检时间总厂.
17.u16SelfCheckTimeTick          自检时间的计数值.用于记录当前自检状态的时长.可以通过设定该值重置自检状态.
18.u16IgnOnDelayTimeTick         开点火延时响应时间的计数值.用于记录当前开点火延时响应状态的时长.
								 可以通过设定该值重置延时响应状态.*/
/**********************************************************************************************************
* Other function Configuration 																			  *
**********************************************************************************************************/
//用于定义针对项目的其他配置参数









/**********************************************************************************************************
* Telltale System Status Type Definition																  *
**********************************************************************************************************/
typedef enum
{
/*Normal Status*/
	TT_SYSTEM_DEFAULT = 0x0000u,


/*Abnormal Status*/
	TT_SYSTEM_FAILD = 0x0010u,
	TT_EEPROM_CONFIG_ERROR = 0x0020u,
	TT_POWER_MODE_ERROR = 0x0040u,
	TT_CAN_INPUT_ERROR = 0x0080u,
	TT_LOGIC_PROCESS_RETURN_VALUE_ERROR = 0x0100u,
	TT_KEEP_LIGHT_STATUS_FLAG_ERROR = 0x0200u,

	TT_KEEP_PREVIOUS = 0xFFFF
}TT_enSystemStatus;
/*此枚举定义用于表示报警灯模块的系统状态,分为正常状态和异常状态,不同参数对应的意义如下:
正常状态:
1.TT_SYSTEM_DEFAULT  默认系统状态.报警灯模块初始化后的状态.当系统状态unSystemErrorStatus
等于该值时表示报警灯模块工作正常.
正常状态预留最多四个状态供针对项目需求的添加.位置为0-3bit.

异常状态:
1.TT_SYSTEM_FAILD
	表示系统失效.模块出现不可逆的错误时置位的状态.当出现此错误状态后模块应用层功能关闭,关闭前会恢复到默认状态.
	该错误产生过后便置位保存,直到下次重新初始化模块.
2.TT_EEPROM_CONFIG_ERROR  表示获取到EEPROM存取器中数据有错误.该错误产生的条件需要针对项目需求添加.
	该错误产生过后便置位保存,错误恢复后该状态位不恢复用于记录.
3.TT_POWER_MODE_ERROR
	表示获取到的电源状态有错误.默认产生条件是未获取到有效电源状态时记录该错误.条件可针对项目需求添加.
	该错误产生过后便置位保存,错误恢复后该状态位不恢复用于记录.
4.TT_CAN_INPUT_ERROR
	表示CAN输入信号有错误.该错误产生的条件需要针对项目需求添加.
	该错误产生过后便置位保存,错误恢复后该状态位不恢复用于记录.
5.TT_LOGIC_PROCESS_RETURN_VALUE_ERROR
	表示运行报警灯逻辑处理状态机时获取到的逻辑状态LogicType有错误.如获取到当前状态为自检TT_enSELF_CHECK,
	而自检状态是无法通过在TT_Process.c文件内的项目应用逻辑判断函数设置的.该错误产生条件需在TT_Core.h内添加.
	该错误产生过后便置位保存,错误恢复后该状态位不恢复用于记录.
6.TT_KEEP_LIGHT_STATUS_FLAG_ERROR
	表示保持报警灯其中之一的逻辑状态状态标志位KeepLightStatus有错误.该报警灯如无控制属性
	TT_enOFF_AT_FAILLING_EDGE_TRIGGER或TT_enKEEP_FLASH_STATUS_UNTIL_CURRENT_CYCLE_END时,标志位是不会置位
	有效的.如置位说明有错误.该错误产生过后便置位保存,错误恢复后该状态位不恢复用于记录.
	异常状态预留最多二十八个状态供针对项目需求的添加.位置为4-31bit.

设置系统标志位的方法:
在TT_Process.c文件内使用宏定义:
(1)TT_SET_SYSTEM (2)TT_CLEAR_SYSTEM (3)TT_CHECK_SYSTEM
请注意:尽量少在TT_Process.c文件内项目应用逻辑判断函数中内操作系统状态.
在TT_Interface.c文件内使用函数定义:
(1)TT_CORE_vSetSystemStatus (2)TT_CORE_vClearSystemStatus (3)TT_CORE_boCheckSystemStatus*/
/**********************************************************************************************************
*																								          *
*																								          *
*	Main Object Structure Definition																	  *
*																								          *
*																								          *
**********************************************************************************************************/
typedef struct
{
	/*****************************************************************************************************/
	/*System Status*/
	/*****************************************************************************************************/
	union
	{
		uint32 u32SystemStatus; /*The systemus of Telltale function*/
		struct
		{
			uint32 NormalStatusReserved     :4 ;

			uint32 SystemFaild              :1 ;
			uint32 EEPROMConfigError        :1 ;
			uint32 PowerModeError           :1 ;
			uint32 CANInputError            :1 ;
			uint32 LogicProcessReturnError  :1 ;
			uint32 KeepLightStatusFlagError :1 ;

			uint32 Reserved                 :24;
		}stSystemStatus;
	}unSystemStatus;
	/*****************************************************************************************************/
	/*Basic Function*/
	/******************************************************************************************************/
	union
	{
		uint32 u32PowerModeStatus; /*The status of power mode*/
		struct
		{
			uint32 TT_Off                   :1 ;
			uint32 TT_Run                   :1 ;
			uint32 TT_AbnormalVoltage       :1 ;
			uint32 Reserved                 :29;
		}stPowerModeStatus;
	}unPowerModeStatus;
	/*The control status of flash*/
	TT_tstFlashControlStatus stFlashControlStatus[TT_enSTATUS_TOTAL_NUMBER - TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER];
	/*The control status of telltale*/
	TT_tstTelltaleControlStatus stTelltaleControlStatus[TT_enTELLTALE_TOTAL_NUMBER];
	/******************************************************************************************************/
	/*Output On CAN*/
	/******************************************************************************************************/
#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_CAN) != FALSE)
	uint32 u32CANMessage;                 /*The CAN message*/
#endif
	/******************************************************************************************************/
	/*Output On SBUS*/
	/******************************************************************************************************/
#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_SBUS) != FALSE)
	uint32 u32SBUSMessage[5];                /*The SBUS message*/
#endif
	/******************************************************************************************************/
	/*Other Function*/
	/******************************************************************************************************/



	/******************************************************************************************************/
	/*Count Function*/
	/******************************************************************************************************/
	struct
	{
		uint16 u16ExitAbnormalResponseDelayMaxTickCount;
		/*Logic processing rate when running at time task count */
		uint32 u32TimeTaskLoopRateTickCount;
	}stCount;
	/******************************************************************************************************/
	/*Timer Function*/
	/******************************************************************************************************/
	struct
	{
		uint16 u16FlashTimeTick[TT_enSTATUS_TOTAL_NUMBER - TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER];
		uint16 u16ExitAbnormalResponseDelayDelayTick;
	}stTimer;
	/******************************************************************************************************/
	union
	{
		uint32 u32FuncFlag;                       /*the flag of Telltale function*/
		struct
		{
			uint32 CANUpdateFlag            :1;   /*CAN update flag ,1 means need to update ,0 means do nothing */
			uint32 SBUSUpdateFlag           :1;   /*SBUS update flag ,1 means need to update ,0 means do nothing */
			uint32 GlobalSelfCheckFlag      :1;   /*Global self check flag ,1 means at least one lamp is in self check mode ,0 means isn't */
			/******************************************************************************************************/
			uint32 FrontPassengerStatus 	:1;   /*Front passenger status flag ,1 means vehicle has front passenger ,0 means hasn't */
			uint32 AnyPowerModeToRunFlag 	:1;   /*Any power mode to run flag ,1 means enter run mode right now ,0 means condition not match */


			//Add new flag here 此处添加新的标志位配置
			uint32 Reserved                 :27;  /*Reserved bitfileds*/
		}stFuncFlag;
	}unFunctionFlag;
}TT_tstMainObject;
/*此结构体定义用于表示报警灯模块的所有的状态和数据,不同数据对应的意义如下:
1.unSystemErrorStatus
该数据用于记录保存系统状态标志位,错误状态由枚举TT_enSystemStatus定义.添加新的错误状态后需补充此联合体.
2.unPowerModeStatus
该数据用于记录模块的工作状态,模块工作状态一般由系统电源状态决定.
3.stFlashControlStatus
该数据用于存储参考闪烁状态的状态数据.数组元素数量由支持的闪烁逻辑状态总数量决定.
4.stTelltaleControlStatus
该数据用于存储报警灯的状态数据.数组元素数量由报警灯总数量决定.
5/6.u32CANMessage/u32SBUSMessage
当输出方式有CAN输出或SBUS输出时该数据用于存储发送的报文临时数据.
7.stCount
该数据组用于存储模块内的计数数据.可根据项目需求添加.
(1)u16ExitAbnormalResponseDelayMaxTickCount  该数据为退出异常状态延时响应的最大时间计数值.
(2)u32TimeTaskLoopRateTickCount  该数据为判断周期任务执行的次数计数.
8.stTimer
该数据组用于存储模块内的计时数据.可根据项目需求添加.
(1)u16FlashTimeTick  该数据为客观参照闪烁状态的时间计数值,用于判断灯点亮熄灭状态的计数值.
(2)u16ExitAbnormalResponseDelayDelayTick  该数据为退出异常状态延时响应的时间计数值,用于判断报警灯是否处于该状态.
9.unFunctionFlag
该数据组用于存储模块内的标志位数据.可根据项目需求添加.
(1)/(2) CANUpdateFlag/SBUSUpdateFlag 该数据有效时表示CAN输出或SBUS输出的报文有更新,需要发送数据.
(3)GlobalSelfCheckFlag 该数据有效时表示报警灯有至少一个还处于自检状态.
最大支持长度总量为32bit的标志位,单个标志位最大长度为8bit.*/
/**********************************************************************************************************
*																								          *
*																								          *
*	Flag Attribute Configuration																		  *
*																								          *
*																								          *
**********************************************************************************************************/
/**********************************************************************************************************
* Flag Operation Type Definition 																		  *
**********************************************************************************************************/
typedef enum
{
	TT_FLAG_DEFAULT  = 0x00,
	TT_FLAG_ONE = 0x01,
	TT_FLAG_PREVIOUS = 0xFF
}TT_enFlagOperation;
/*此枚举定义用于表示报警灯模块的基本操作,不同操作对应的意义如下:
1.TT_FLAG_DEFAULT  标志位默认值,系统初始化后默认值为0.
2.TT_FLAG_PREVIOUS 标志位保持前一次的值,略过此特定系统时间点的赋值操作.*/

/**********************************************************************************************************
* Flag Structure Definition																				  *
**********************************************************************************************************/
typedef struct
{
	uint8  u8FlagBitIndex;
	uint8  u8FlagBitLength;
	TT_enFlagOperation  u8ColdInitSetValue;
	TT_enFlagOperation  u8WarmInitSetValue;
	TT_enFlagOperation  u8WakeUpSetValue;
	TT_enFlagOperation  u8SleepSetValue;
	TT_enFlagOperation  u8EnterAbnormalSetValue;
	TT_enFlagOperation  u8ExitAbnormalSetValue;
}TT_tstFlagAttribute;
/* 此结构体定义用于表示报警灯模块的标志位配置参数,不同数据对应的意义如下:
1.u8FlagBitIndex          标志位起始Bit位置.
2.u8FlagBitLength         标志位Bit长度.
3.u8ColdInitSetValue      冷启动时设置的值.
4.u8WarmInitSetValue      热启动时设置的值.
5.u8WakeUpSetValue        唤醒时设置的值.
6.u8SleepSetValue         睡眠时设置的值.
7.u8EnterAbnormalSetValue 进入异常状态时设置的值.
8.u8ExitAbnormalSetValue  退出异常状态时设置的值.
该数据表示了对标志位数据组unFunctionFlag中的标志位数据在不同特定系统时间点的赋值操作
将标志位的赋值放在表格内管理有利于设计时考虑特定时间点的状态赋值,如异常状态的恢复默认赋值 */

typedef struct
{
	uint8  u8TSR_Speed_Limit_Value;
	uint8  u8TSR_Road_Sign;
}TT_TSR_Info;
/*This struct defines Traffic Road Sign Info:
1.u8TSR_Speed_Limit_Value         Speed limit sign.
2.u8TSR_Road_Sign                 Road sign recognition.*/

#define TT_V2X_LANENUM    (8u)
typedef struct
{
	uint8 u8V2X_GuideSpeed;
	uint8 u8V2X_SpeedLimit;
	uint8 u8V2X_TrafficSign;
	uint8 u8V2X_VehPosition;
	uint16 u8V2X_LightTime[TT_V2X_LANENUM];
}TT_V2X_Info;
/*V2X报警灯相关数据
1.绿波引导车速
2.限速车速
3.交通标识
4.当前车辆所在车道位置
5.所有车道信号灯倒计时
*/
/**********************************************************************************************************
* Flag Stage Type Definition 																			  *
**********************************************************************************************************/
typedef enum
{
	TT_COLD_INIT ,
	TT_WARM_INIT ,
	TT_WAKE_UP ,
	TT_SLEEP ,
	TT_ENTER_ABNORMAL,
	TT_EXIT_ABNORMAL
}TT_enFlagProcessStage;
/*此枚举定义用于表示特定的系统时间节点定义,不同数据对应的意义如下:
1.u8ColdInitSetValue      模块冷启动时.
2.u8WarmInitSetValue      模块热启动时.
3.u8WakeUpSetValue        模块唤醒时.
4.u8SleepSetValue         模块睡眠时.
5.u8EnterAbnormalSetValue 模块进入异常状态时.
6.u8ExitAbnormalSetValue  模块退出异常状态时.*/

/**********************************************************************************************************
*																										  *
*																										  *
*	Flag Attribute Configuration																		  *
*																										  *
*																										  *
**********************************************************************************************************/
/*FlagName							FlagBit  FlagBit  SetValueWhen		 SetValueWhen		SetValueWhen	   SetValueWhen 	  SetValueWhen		 SetValueWhen
									Index	 Length   ColdInit			 WarmInit			WakeUp			   Sleep			  EnterAbnormal 	 ExitAbnormal  */
#define TT_CFG_FLAG_ATTRIBUTE   {\
/*CAN update flag*/ 			{	  0 ,	   1,	  TT_FLAG_DEFAULT ,   TT_FLAG_DEFAULT , TT_FLAG_PREVIOUS , TT_FLAG_PREVIOUS , TT_FLAG_PREVIOUS , TT_FLAG_PREVIOUS},\
/*SBUS update flag*/			{	  1 ,	   1,	  TT_FLAG_DEFAULT ,   TT_FLAG_DEFAULT , TT_FLAG_PREVIOUS , TT_FLAG_PREVIOUS , TT_FLAG_PREVIOUS , TT_FLAG_PREVIOUS},\
/*Global self check flag*/		{	  2 ,	   1,	  TT_FLAG_DEFAULT ,   TT_FLAG_DEFAULT , TT_FLAG_PREVIOUS , TT_FLAG_PREVIOUS , TT_FLAG_PREVIOUS , TT_FLAG_PREVIOUS},\
/*Front passenger status flag*/ {	  3 ,	   1,	  TT_FLAG_DEFAULT ,   TT_FLAG_DEFAULT , TT_FLAG_PREVIOUS , TT_FLAG_PREVIOUS , TT_FLAG_PREVIOUS , TT_FLAG_PREVIOUS},\
/*AnyPowerModeToRunFlag*/ 		{	  4 ,	   1,	  TT_FLAG_ONE ,   	  TT_FLAG_ONE ,     TT_FLAG_PREVIOUS , TT_FLAG_PREVIOUS , TT_FLAG_PREVIOUS , TT_FLAG_PREVIOUS},\
								{	  32 , 	   0, 	  TT_FLAG_DEFAULT ,   TT_FLAG_DEFAULT , TT_FLAG_DEFAULT  , TT_FLAG_DEFAULT  , TT_FLAG_DEFAULT  , TT_FLAG_DEFAULT },\
								}


//Add new flag configuration here. 此处添加新的标志位赋值配置
/*此宏定义用于配置模块标志位,根据具体项目需求定义.*/
/**********************************************************************************************************
*																										  *
*																										  *
*	Function Configuration																				  *
*																										  *
*																										  *
**********************************************************************************************************/
/**********************************************************************************************************
* Test Process Function Configuration																	  *
**********************************************************************************************************/
#define SWC_TT_START_SEC_CODE
#include "SWC_TT_MemMap.h"

#if (TT_CFG_DEBUG == TRUE)
void TT_TEST_vFlashTestProcess(TT_tstMainObject* stMainObject);
void TT_TEST_vOnCountPlus(void);
void TT_TEST_vOffCountPlus(void);
#endif
/*此处存放TT_Process.c文件内的测试函数*/
/**********************************************************************************************************
* Process Function Configuration 																		  *
**********************************************************************************************************/
void FTT_vBatteryCharge_Process(TT_tstMainObject* stMainObject);
void FTT_vLowFuelPress_Process(TT_tstMainObject* stMainObject);
void FTT_vEngine_System_Error_Process(TT_tstMainObject* stMainObject);
void FTT_vEngine_Fix_Process(TT_tstMainObject* stMainObject);
void FTT_vEngine_High_Temp_Process(TT_tstMainObject* stMainObject);
void FTT_vCruise_Control_Process(TT_tstMainObject* stMainObject);
void FTT_vSS_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vTPMS_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vLDW_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vLKA_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vLCK_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vAuto_Park_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vHSD_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vEPB_Enable_Process(TT_tstMainObject* stMainObject);
void FTT_vDPB_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vIboost_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_v120KMH_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vTSR_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vFront_Fog_Process(TT_tstMainObject* stMainObject);
void FTT_vRear_Fog_Process(TT_tstMainObject* stMainObject);
void FTT_vHigh_Beam_Process(TT_tstMainObject* stMainObject);
void FTT_vTurn_Left_Process(TT_tstMainObject* stMainObject);
void FTT_vTurn_Right_Process(TT_tstMainObject* stMainObject);
void FTT_vPosition_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vLight_Switch_Process(TT_tstMainObject* stMainObject);
void FTT_vTrailer_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vDoor_Open_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vSeat_Belt_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vTransmission_Over_Heat_Process(TT_tstMainObject* stMainObject);
void FTT_vAuto_Light_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vLow_Fuel_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vREADY_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vEV_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vCharge_Status_Process(TT_tstMainObject* stMainObject);
void FTT_vPower_Reduce_Process(TT_tstMainObject* stMainObject);
void FTT_vParking_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vRBS_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vEngine_Warmup_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vCCO_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vFEDL_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vREDL_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vAUX_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vRSW_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vSAS_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vSteer_Assit_Process(TT_tstMainObject* stMainObject);
void FTT_vSound_Reminder_Process(TT_tstMainObject* stMainObject);
void FTT_vBatteryPack_Charge_Process(TT_tstMainObject* stMainObject);
void FTT_vBattery_Off_Process(TT_tstMainObject* stMainObject);
void FTT_vLow_Battery_Process(TT_tstMainObject* stMainObject);
void FTT_vRSCA_OFF_Process(TT_tstMainObject* stMainObject);
void FTT_v2H4H4L_Handle_Process(TT_tstMainObject* stMainObject);
void FTT_vSingle_Pedal_Process(TT_tstMainObject* stMainObject);
extern void ETC_get_TSR_tt_inf(TT_TSR_Info *pf_tsr_tt_inf);

uint8 Get_vSAS_Handle_Status(void);
void FTT_vOilWaterSeparation_Process(TT_tstMainObject* stMainObject);
void FTT_vAdblue_Process(TT_tstMainObject* stMainObject);

void FTT_V2XGuideSpeed_Process(TT_tstMainObject* stMainObject);
void FTT_V2XSpeedLimit_Process(TT_tstMainObject* stMainObject);
void FTT_V2XTrafficSign_Process(TT_tstMainObject* stMainObject);
void FTT_V2XTrafficLight_Process(TT_tstMainObject* stMainObject);
extern void Get_V2X_TT_Info(TT_V2X_Info *pf_v2x_tt_info);
void FTT_AirSuspension_Process(TT_tstMainObject* stMainObject);
void FTT_CentralDiffLockLight_Process(TT_tstMainObject* stMainObject);
// tips: add new telltale before the log output
void FTT_TT_Process_LogOutput(TT_tstMainObject* stMainObject);

#define SWC_TT_STOP_SEC_CODE
#include "SWC_TT_MemMap.h"


/*Add Logic Process here 添加新的逻辑处理函数声明*/
/*此处存放TT_Process.c文件内的逻辑处理函数的声明.
函数声明格式: void TT_vProcess(TT_tstMainObject* stMainObject);
添加声明的命名方式: TT_v + 逻辑处理名称 + Process
Example:
(1)TT_vFogLightProcess               雾灯逻辑处理函数
(2)TT_vDirectionIndicationProcess    转向灯逻辑处理函数
Tips: 尽量将相同信号组或者功能相似的报警灯放在一个逻辑处理函数内.如左右转向灯,前后雾灯,刹车灯等.*/
/**********************************************************************************************************
* Logic Process Mode Type Definition																	  *
**********************************************************************************************************/
typedef enum
{
		TT_enINTERFACE = 0x01,/*Run in interrupt always set this attribute*/
		TT_enTIME_TASK = 0x02,
		TT_enROBIN_TASK = 0x04,
}TT_enLogicProcessMode;
/*此枚举定义用于表示逻辑处理函数的处理模式,不同模式对应的意义如下:
1.TT_enINTERFACE
在接口中运行处理函数.可调用TT_Interface.h文件TT_API_vSingleTelltaleControl函数实现运行该逻辑处理函数.
例如网络信号的接收钩子可调用该函数,实现逻辑接收后立马实现逻辑处理.
2.TT_enTIME_TASK
在定时周期任务中运行处理函数.具体调用周期和顺序由参数u16TimeTaskModeLoopFactor和u16TimeTaskModeLoopOffset决定.
3.TT_enROBIN_TASK
在填空轮循任务中运行处理函数.具体调用时机由系统决定.一般情况下该任务执行时机为空闲时填空执行.
不同任务处理模式决定了逻辑函数的执行时机,但是具体输出的逻辑执行由报警灯主任务状态机决定.
一般逻辑任务的执行时间略小于输入信号的输入周期即可,保证每个输入信号均能做对应的逻辑处理.
也可由输出接口的需求响应时间决定,保证输出状态达到设计时效需求.
逻辑处理函数若不配置对应的处理模式,将无法在对应时机执行*/
/**********************************************************************************************************
* Logic Process Mode Structure Definition																  *
**********************************************************************************************************/
typedef void(*ptrTelltaleLogicOperation)(TT_tstMainObject* stMainObject);
typedef struct
{
	ptrTelltaleLogicOperation vptrTelltaleLogicOperation;
	uint32                    u32LogicProcessMode;
	uint16                    u16TimeTaskModeLoopFactor;
	uint16                    u16TimeTaskModeLoopOffset;
}TT_tstLogicProcessAttribute;
/*此结构体定义用于表示逻辑处理函数的处理参数,不同参数对应的意义如下:
1.vptrTelltaleLogicOperation
逻辑处理函数的指针.
2.u32LogicProcessMode
逻辑处理函数处理模式,由TT_enLogicProcessMode定义.
3.u16TimeTaskModeLoopFactor
逻辑处理函数处于定时周期任务时,执行时机的的主任务周期倍数.
当该值为2且主任务周期为20ms时,每40ms执行一次该逻辑处理函数.
4.u16TimeTaskModeLoopOffset
逻辑处理函数处于定时周期任务时,执行时机的初始时机相位.
可以通过配置该值决定执行第一次逻辑处理任务的时机.*/
/*********************************************************************************************************/
#define TT_IF  (uint32)TT_enINTERFACE
#define TT_TT  (uint32)TT_enTIME_TASK
#define TT_RT  (uint32)TT_enROBIN_TASK
/*********************************************************************************************************/
/*     TelltaleLogicProcess             LogicProcess  TimeTaskMode        TimeTaskMode
						 Function                      Mode         RunFactor          RunOffset */
#define TT_CFG_LOGIC_PROCESS_ATTRIBUTE  {\
	{ FTT_vBatteryCharge_Process ,         TT_TT ,  (uint16)TT_TimeTask100ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vLowFuelPress_Process ,          TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vEngine_System_Error_Process ,   TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vEngine_Fix_Process ,            TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vEngine_High_Temp_Process ,      TT_TT ,  (uint16)TT_TimeTask100ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vCruise_Control_Process ,        TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vSS_Handle_Process ,             TT_TT ,  (uint16)TT_TimeTask100ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vTPMS_Handle_Process ,           TT_TT ,  (uint16)TT_TimeTask100ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vLDW_Handle_Process ,            TT_TT ,  (uint16)TT_TimeTask50ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vLKA_Handle_Process ,            TT_TT ,  (uint16)TT_TimeTask50ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vLCK_Handle_Process ,            TT_TT ,  (uint16)TT_TimeTask50ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vAuto_Park_Handle_Process ,      TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vHSD_Handle_Process ,            TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vEPB_Enable_Process ,            TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vDPB_Handle_Process ,            TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vIboost_Handle_Process ,         TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_v120KMH_Handle_Process ,         TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vTSR_Handle_Process ,            TT_TT ,  (uint16)TT_TimeTask100ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vFront_Fog_Process ,             TT_TT ,  (uint16)TT_TimeTask50ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vRear_Fog_Process ,              TT_TT ,  (uint16)TT_TimeTask50ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vHigh_Beam_Process ,             TT_TT ,  (uint16)TT_TimeTask50ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vTurn_Left_Process ,             TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vTurn_Right_Process ,            TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vPosition_Handle_Process ,       TT_TT ,  (uint16)TT_TimeTask50ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vLight_Switch_Process ,          TT_TT ,  (uint16)TT_TimeTask50ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vTrailer_Handle_Process ,        TT_TT ,  (uint16)TT_TimeTask50ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vDoor_Open_Handle_Process ,      TT_TT ,  (uint16)TT_TimeTask50ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vSeat_Belt_Handle_Process ,      TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vTransmission_Over_Heat_Process ,TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vAuto_Light_Handle_Process ,     TT_TT ,  (uint16)TT_TimeTask50ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vLow_Fuel_Handle_Process ,       TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vREADY_Handle_Process ,          TT_TT ,  (uint16)TT_TimeTask50ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vEV_Handle_Process ,             TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vCharge_Status_Process ,         TT_TT ,  (uint16)TT_TimeTask50ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vPower_Reduce_Process ,          TT_TT ,  (uint16)TT_TimeTask50ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vParking_Handle_Process ,        TT_TT ,  (uint16)TT_TimeTask50ms , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vRBS_Handle_Process ,            TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vEngine_Warmup_Handle_Process ,  TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vCCO_Handle_Process ,            TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vFEDL_Handle_Process ,           TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vREDL_Handle_Process ,           TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vAUX_Handle_Process ,            TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vRSW_Handle_Process ,            TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vSAS_Handle_Process ,            TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vSteer_Assit_Process ,           TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vSound_Reminder_Process ,        TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vBatteryPack_Charge_Process ,    TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vBattery_Off_Process ,           TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vLow_Battery_Process ,           TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vRSCA_OFF_Process ,              TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_v2H4H4L_Handle_Process ,         TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vSingle_Pedal_Process ,          TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vOilWaterSeparation_Process ,    TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_vAdblue_Process ,                TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_V2XGuideSpeed_Process ,          TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_V2XSpeedLimit_Process ,          TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_V2XTrafficSign_Process ,         TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_V2XTrafficLight_Process ,        TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_AirSuspension_Process ,          TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_CentralDiffLockLight_Process ,   TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ FTT_TT_Process_LogOutput ,           TT_TT ,  (uint16)TT_NOT_CONCERNED , (uint16)TT_NOT_CONCERNED   },\
	{ (void *)0 ,                          TT_TT ,  (uint16)TT_NULL ,          (uint16)TT_NULL  },\
	}


/*Add Logic Process here 添加逻辑处理函数*/
#if 0/*Save reserved telltale process*/

	{ TT_TEST_vFlashTestProcess,		   ROBIN_TASK },\

#endif
/*此宏定义用于配置逻辑处理函数的参数,根据具体项目需求定义.*/
/*********************************************************************************************************/





#endif //TT_CFG_H
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
