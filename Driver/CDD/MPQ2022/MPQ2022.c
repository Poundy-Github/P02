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
 * @file:      MPQ2022.c
 * @author:    Nobo
 * @date:      2021-11-18
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2021-11-18
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/
#include "MPQ2022.h"
#include "Misc_Board.h"
#include "IIC_cfg.h"
#include "logger_cfg.h"
#include "logger.h"
#include "Dio.h"
#include "Misc_Diag.h"
#include <stdio.h>
#include <string.h>

//==
//cycle time(ms) of MPQ2022 state monitor : read voltage and current 
#define MPQ2022_STATE_MONITOR_CYCLE						(1000)
//when handle not on , retry times
#define MPQ2022_HANDLE_RETRY_ENQUEUE_TIMES				(3)
//when toplayer err handle retry times
#define MPQ2022_ERR_HANDLE_RETRY_POWER_ON_OFF_TIMES		(5)
//when MPQ2022 err oucur power on/off delay , must larger than 30ms form FAE
#define MPQ2022_HANDLE_ERR_POWER_ON_OFF_TIMEOUT			(50)
//app middle layer wait handle timeout(ms)
#define MPQ2022_HANDLE_BUSY_WAIT_TIMES					(100)
//app middle layer handle data len
#define MPQ2022_HANDLE_DATA_BUFF_LEN					(5)
//conbime condition if not care :0XFFF -> not care that condition
#define MN_CARE											(0XFFFF)
//==
typedef enum 
{
    eMPS2022_StartUpSeqId_Set_DEV_CTRL_DisOutPut = 0x00,
    eMPS2022_StartUpSeqId_SET_VOUT_1,
    eMPS2022_StartUpSeqId_SET_VOUT_2,
    eMPS2022_StartUpSeqId_SET_IOUT_LIM_1,
    eMPS2022_StartUpSeqId_SET_IOUT_LIM_2,	
    eMPS2022_StartUpSeqId_Set_DEV_CTRL_EnOutPut,
    eMPS2022_StartUpSeqId_MAX
}eMPQ2022StartUpSeqId_t;
typedef enum 
{
    eMPS2022_MonitorSeqId_Get_VOUT_1 = 0x00,
    eMPS2022_MonitorSeqId_Get_VOUT_2,
    eMPS2022_MonitorSeqId_Get_IOUT_1,
    eMPS2022_MonitorSeqId_Get_IOUT_2,
    eMPS2022_MonitorSeqId_MAX
}eMPQ2022MonitorSeqId_t;

//==
typedef enum 
{
    eMPS2022_FilterMask_Nothing = 0x00,
    eMPS2022_FilterMask_Voltage = 0x01,
    eMPS2022_FilterMask_Current = 0x02,
    eMPS2022_FilterMask_OC = 0x04,
    eMPS2022_FilterMask_OV = 0x08,
    eMPS2022_FilterMask_UV = 0x10,
    eMPS2022_FilterMask_STB = 0x20,
    eMPS2022_FilterMask_MAX
}eMPQ2022FilterMask_t;
typedef struct
{
	uint16 vol;//voltage
	uint16 cur;//current
	uint16 oc;//over current
	uint16 ov;//over voltage
	uint16 uv;//under voltage
	uint16 stb;//short to bat
}s_MPQ2022DTCCombineCondition_t;
typedef struct
{
	uint16 voltageMin;
	uint16 voltageMax;//mV
	uint16 currentMin;
	uint16 currentMax;//mA
}s_MPQ2022DeviceMon_t;

//==
typedef enum 
{
    eMPS2022_RegEventMask_Empty = 0x00,//app: event empty
    eMPS2022_RegEventMask_Write= 0x01,//app: event was write
    eMPS2022_RegEventMask_Read = 0x02,//app: event was read
    eMPS2022_RegEventMask_Max
}eMPQ2022RegEventMask_t;
typedef enum 
{
    eMPS2022_EventDealStatus_Idle = 0x00,//app : handle inner status Idle
    eMPS2022_EventDealStatus_Busy,//app : handle inner status Busy
    eMPS2022_EventDealStatus_RxComplete,//app : handle inner status from app RX callback , iic hal return was success
    eMPS2022_EventDealStatus_TxComplete,//app : handle inner status from app TX callback , iic hal return was success
    eMPS2022_EventDealStatus_IICBusError,//app : handle inner status from app TX/RX callback , iic hal return was err
    eMPS2022_EventMask_MAX
}e_MPQ2022RegEventDealStatus_t;//app: middle layer state machine
typedef enum 
{
    eMPS2022_EventDealResult_Ok = 0x00,//app: event deal done
    eMPS2022_EventDealResult_Busy,//app: handle waiting for call back
    eMPS2022_EventDealResult_TimeOut,//app: wait timeout
    eMPS2022_EventDealResult_CRCNotOk,//app: crc check err
    eMPS2022_EventDealResult_WriteReadNotMatch,//app: write read 3 times not match
    eMPS2022_EventDealResult_IICBussErr,//hal: iic bus err
    eMPS2022_EventDealResult_MAX
}e_MPQ2022RegEventDealResult_t;
typedef struct
{
	eMPQ2022RegEventMask_t eventMask;
	uint8 writeData;
	uint8 readData;
}s_MPQ2022RegEventDeal_t;
typedef enum 
{
    eMPS2022_CtrlStatus_Init=0,
    eMPS2022_CtrlStatus_StartUp,
    eMPS2022_CtrlStatus_StateMonitor,
    eMPS2022_CtrlStatus_EventDeal,
    eMPS2022_CtrlStatus_ResultErrDeal,
    eMPS2022_CtrlStatus_MAX
}e_MPQ2022CtrlStatus_t;//app: top layer state machine
typedef enum 
{
    eMPS2022_HandleErrDealStatus_PowerOff=0,
    eMPS2022_HandleErrDealStatus_PowerOff_Wait,
    eMPS2022_HandleErrDealStatus_PowerOn_Wait,
    eMPS2022_HandleErrDealStatus_MAX
}e_MPQ2022CtrlHandleErrDealStatus_t;//app: up layer ERR DEAL state machine
typedef enum 
{
    eMPS2022_WriteReadBackStatus_Write=0,
    eMPS2022_WriteReadBackStatus_WriteDelay,
    eMPS2022_WriteReadBackStatus_Read,
    eMPS2022_WriteReadBackStatus_MAX
}e_MPQ2022CtrlWriteReadBackStatus_t;//app : up layer write and readback check state machine

typedef struct
{
	uint8 init;//init flag
	uint8 startUpDone;
	uint8 eventDealDone;
	e_MPQ2022CtrlStatus_t ctrlSts;
	eMPQ2022StartUpSeqId_t startUpIdx;
	eMPQ2022MonitorSeqId_t stateMonitorIdx;
	s_MPQ2022DeviceRegs_t DeviceRegs;//device regesters
	//event deal
	e_MPQ2022RegEventDealStatus_t eventDealSts;//event deal state machine
	s_MPQ2022RegEventDeal_t regEvent[eMPS2022_REG_DEV_REV_ID_MAX];//each regester event
	uint8 eventData[MPQ2022_HANDLE_DATA_BUFF_LEN];//event data buffer
	uint32 eventStartTick;//event deal start ticks
	uint32 handErrTick;
	uint32 normalStartTick;//normal deal start ticks
	uint32 curTick;//sys ticks
	//
	e_MPQ2022CtrlHandleErrDealStatus_t handleErrDeal;
	uint8 handleErrCnt;
	//
	e_MPQ2022CtrlWriteReadBackStatus_t writeReadBack;
	//
	uint8 resultErrDealCnt;
}s_MPQ2022Ctrl_t;
#define MPQ2022_CtrlDefaultVlu  {\
FALSE,\
FALSE,\
FALSE,\
eMPS2022_CtrlStatus_Init,\
0,\
0,\
MPQ2022_RegDefaultVlu,\
eMPS2022_EventDealStatus_Idle,\
{{eMPS2022_RegEventMask_Empty,0,0}},\
{0,0,0,0},\
0,\
0,\
0,\
0,\
eMPS2022_HandleErrDealStatus_PowerOff,\
0,\
eMPS2022_WriteReadBackStatus_Write,\
0,\
}
static s_MPQ2022Ctrl_t sMPQ2022Ctrl[eMPS2022_MAX]={
	MPQ2022_CtrlDefaultVlu,
	MPQ2022_CtrlDefaultVlu,
	MPQ2022_CtrlDefaultVlu,
};

//==
const static uint8 u8MPQ2022_IIC_DeviceIndex[eMPS2022_MAX]={
	eIIC_DeviceID_MPQ2022_MIC_GNSS,
	eIIC_DeviceID_MPQ2022_ANT1_2,
	eIIC_DeviceID_MPQ2022_RVC
};
static const char * MPQ2022_DeviceName[eMPS2022_MAX] = 
{
	"eMPS2022_MIC_GNSS",
	"eMPS2022_ANT1_2",
	"eMPS2022_RVC",
};
	
const static Dio_ChannelType u8MPQ2022_IIC_DeviceEnPin[eMPS2022_MAX]={
	DioConf_DioChannel_VIP_MIC_POWER_EN_3V3,
	DioConf_DioChannel_VIP_TUNER_ANT_EN_3V3,
	DioConf_DioChannel_VIP_POC_PWREN
};

//==from hardware HSIS file
//each MPQ2022 have 2 chanel ,and each chanel have 4 DTC
//1.short to GND voltage sample was at 0.8~1.2v
static const s_MPQ2022DeviceMon_t sMPQ2022_GNSS_Mon[4]={
	{4500	,5500	,0		,7   	},//SenseState_OpenLoad
	{2500   ,5500   ,73     ,113    },//SenseState_OverCurrent
	{0		,500	,MN_CARE,MN_CARE},//SenseState_Short
	{12000  ,MN_CARE,MN_CARE,MN_CARE},//SenseState_ShortToBattery
};
static const s_MPQ2022DeviceMon_t sMPQ2022_ANT1_Mon[4]={
	{8600	,10600	,0		,7   	},//SenseState_OpenLoad
	{4800   ,10600  ,144    ,259    },//SenseState_OverCurrent
	{0		,2000	,MN_CARE,MN_CARE},//SenseState_Short
	{12000  ,MN_CARE,MN_CARE,MN_CARE},//SenseState_ShortToBattery
};
static const s_MPQ2022DeviceMon_t sMPQ2022_ANT2_Mon[4]={
	{8600	,10600	,0		,7   	},//SenseState_OpenLoad
	{4800   ,10600  ,144    ,259    },//SenseState_OverCurrent
	{0		,1000	,MN_CARE,MN_CARE},//SenseState_Short
	{12000  ,MN_CARE,MN_CARE,MN_CARE},//SenseState_ShortToBattery
};
static const s_MPQ2022DeviceMon_t sMPQ2022_RVC_Mon[4]={
	{7400	,9000	,0		,7   	},//SenseState_OpenLoad
	{4100   ,9000   ,221    ,269    },//SenseState_OverCurrent
	{0		,2000	,MN_CARE,MN_CARE},//SenseState_Short
	{12000  ,MN_CARE,MN_CARE,MN_CARE},//SenseState_ShortToBattery
};
static const s_MPQ2022DeviceMon_t * sMPQ2022Mon[eMPS2022_MAX][2]={
	{
		NULL_PTR,
		&sMPQ2022_GNSS_Mon,
	},
	{
		&sMPQ2022_ANT2_Mon,//hardware was chanel 1
		&sMPQ2022_ANT1_Mon,//hardware was chanel 2
	},
	{ 
		&sMPQ2022_RVC_Mon,
		NULL_PTR,
	},
};

//write event trigger
#define MPQ2022_WRITE_TRIGGER(deviceId,regId)		(sMPQ2022Ctrl[deviceId].regEvent[regId].eventMask |= eMPS2022_RegEventMask_Write)
//read event trigger
#define MPQ2022_READ_TRIGGER(deviceId,regId)		(sMPQ2022Ctrl[deviceId].regEvent[regId].eventMask |= eMPS2022_RegEventMask_Read)

//public MIC and GNSS
#define MPQ2022_MIC_GNSS_POWER_CURRENT_BASE(val) 	(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.SET_IOUT_LIM_2.SET_IOUT_LIM_2_BITS.OC_MIN = val)//0:300mA , 1:100mA
#define MPQ2022_MIC_GNSS_POWER_ADC_SAMPLE(val)		(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.ADC_EN = val)
#define MPQ2022_MIC_GNSS_POWER_FAULT_HANDLE(val)	(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.FAULT_HANDLE = val)
//private MIC : use chanel 1
#define MPQ2022_MIC_POWER_VOLTAGE_STEP_SET(val) 	(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.SET_VOUT_1.SET_VOUT_1_BITS.VOUT1_STEP = val)
#define MPQ2022_MIC_POWER_VOLTAGE_SET(val) 			(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.SET_VOUT_1.SET_VOUT_1_BITS.VOUT1_SET = val)
#define MPQ2022_MIC_POWER_CURRENT_SET(val) 			(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.SET_IOUT_LIM_1.SET_IOUT_LIM_1_BITS.IOUT_1_OC_THR = val)
#define MPQ2022_MIC_POWER_OUTPUT_OPEN() 			(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_1_EN = 1)
#define MPQ2022_MIC_POWER_OUTPUT_CLOSE() 			(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_1_EN = 0)
#define MPQ2022_MIC_POWER_VOLTAGE_SAMPLE() 			(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.MON_VOUT_1.MON_VOUT_1_BITS.VOUT1_MON*55)
#define MPQ2022_MIC_POWER_CURRENT_SAMPLE() 			(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.MON_IOUT_1.MON_IOUT_1_BITS.IOUT1_MON*1.2)
#define MPQ2022_MIC_POWER_PG_FLAG()					(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.DEV_STAT.DEV_STAT_BITS.VOUT1_PG)
#define MPQ2022_MIC_POWER_OC_FLAG()					(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.ERR_FLAG_2.ERR_FLAG_2_BITS.LDO_1_OC)
#define MPQ2022_MIC_POWER_OV_FLAG()					(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.ERR_FLAG_1.ERR_FLAG_1_BITS.VOUT_1_OV)
#define MPQ2022_MIC_POWER_UV_FLAG()					(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.ERR_FLAG_1.ERR_FLAG_1_BITS.VOUT_1_UV)
#define MPQ2022_MIC_POWER_STB_FLAG()				(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.ERR_FLAG_1.ERR_FLAG_1_BITS.LDO_1_StB)
//private GNSS : use chanel 2
#define MPQ2022_GNSS_POWER_VOLTAGE_STEP_SET(val) 	(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.SET_VOUT_2.SET_VOUT_2_BITS.VOUT2_STEP = val)
#define MPQ2022_GNSS_POWER_VOLTAGE_SET(val) 		(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.SET_VOUT_2.SET_VOUT_2_BITS.VOUT2_SET = val)
#define MPQ2022_GNSS_POWER_CURRENT_SET(val) 		(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.SET_IOUT_LIM_2.SET_IOUT_LIM_2_BITS.IOUT_2_OC_THR = val)
#define MPQ2022_GNSS_POWER_OUTPUT_OPEN() 			(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_2_EN = 1)
#define MPQ2022_GNSS_POWER_OUTPUT_CLOSE() 			(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_2_EN = 0)
#define MPQ2022_GNSS_POWER_VOLTAGE_SAMPLE() 		(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.MON_VOUT_2.MON_VOUT_2_BITS.VOUT2_MON*55)
#define MPQ2022_GNSS_POWER_CURRENT_SAMPLE() 		(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.MON_IOUT_2.MON_IOUT_2_BITS.IOUT2_MON*1.2)
#define MPQ2022_GNSS_POWER_PG_FLAG()				(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.DEV_STAT.DEV_STAT_BITS.VOUT2_PG)
#define MPQ2022_GNSS_POWER_OC_FLAG()				(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.ERR_FLAG_2.ERR_FLAG_2_BITS.LDO_2_OC)
#define MPQ2022_GNSS_POWER_OV_FLAG()				(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.ERR_FLAG_1.ERR_FLAG_1_BITS.VOUT_2_OV)
#define MPQ2022_GNSS_POWER_UV_FLAG()				(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.ERR_FLAG_1.ERR_FLAG_1_BITS.VOUT_2_UV)
#define MPQ2022_GNSS_POWER_STB_FLAG()				(sMPQ2022Ctrl[eMPS2022_MIC_GNSS].DeviceRegs.ERR_FLAG_1.ERR_FLAG_1_BITS.LDO_2_StB)

//public ANT1 and ANT2
#define MPQ2022_ANT1_2_POWER_CURRENT_BASE(val) 		(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.SET_IOUT_LIM_2.SET_IOUT_LIM_2_BITS.OC_MIN = val)//0:300mA , 1:100mA
#define MPQ2022_ANT1_2_POWER_ADC_SAMPLE(val)		(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.ADC_EN = val)
#define MPQ2022_ANT1_2_POWER_FAULT_HANDLE(val)		(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.FAULT_HANDLE = val)
//private ANT1 : use chanel 2 hardware was exchanged
#define MPQ2022_ANT1_POWER_VOLTAGE_STEP_SET(val) 	(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.SET_VOUT_2.SET_VOUT_2_BITS.VOUT2_STEP = val)
#define MPQ2022_ANT1_POWER_VOLTAGE_SET(val) 		(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.SET_VOUT_2.SET_VOUT_2_BITS.VOUT2_SET = val)
#define MPQ2022_ANT1_POWER_CURRENT_SET(val) 		(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.SET_IOUT_LIM_2.SET_IOUT_LIM_2_BITS.IOUT_2_OC_THR = val)
#define MPQ2022_ANT1_POWER_OUTPUT_OPEN() 			(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_2_EN = 1)
#define MPQ2022_ANT1_POWER_OUTPUT_CLOSE() 			(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_2_EN = 0)
#define MPQ2022_ANT1_POWER_VOLTAGE_SAMPLE() 		(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.MON_VOUT_2.MON_VOUT_2_BITS.VOUT2_MON*55)
#define MPQ2022_ANT1_POWER_CURRENT_SAMPLE() 		(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.MON_IOUT_2.MON_IOUT_2_BITS.IOUT2_MON*1.2)
#define MPQ2022_ANT1_POWER_PG_FLAG()				(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.DEV_STAT.DEV_STAT_BITS.VOUT2_PG)
#define MPQ2022_ANT1_POWER_OC_FLAG()				(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.ERR_FLAG_2.ERR_FLAG_2_BITS.LDO_2_OC)
#define MPQ2022_ANT1_POWER_OV_FLAG()				(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.ERR_FLAG_1.ERR_FLAG_1_BITS.VOUT_2_OV)
#define MPQ2022_ANT1_POWER_UV_FLAG()				(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.ERR_FLAG_1.ERR_FLAG_1_BITS.VOUT_2_UV)
#define MPQ2022_ANT1_POWER_STB_FLAG()				(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.ERR_FLAG_1.ERR_FLAG_1_BITS.LDO_2_StB)
//private ANT2 : use chanel 1 hardware was exchanged
#define MPQ2022_ANT2_POWER_VOLTAGE_STEP_SET(val) 	(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.SET_VOUT_1.SET_VOUT_1_BITS.VOUT1_STEP = val)
#define MPQ2022_ANT2_POWER_VOLTAGE_SET(val) 		(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.SET_VOUT_1.SET_VOUT_1_BITS.VOUT1_SET = val)
#define MPQ2022_ANT2_POWER_CURRENT_SET(val) 		(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.SET_IOUT_LIM_1.SET_IOUT_LIM_1_BITS.IOUT_1_OC_THR = val)
#define MPQ2022_ANT2_POWER_OUTPUT_OPEN() 			(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_1_EN = 1)
#define MPQ2022_ANT2_POWER_OUTPUT_CLOSE() 			(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_1_EN = 0)
#define MPQ2022_ANT2_POWER_VOLTAGE_SAMPLE() 		(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.MON_VOUT_1.MON_VOUT_1_BITS.VOUT1_MON*55)
#define MPQ2022_ANT2_POWER_CURRENT_SAMPLE() 		(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.MON_IOUT_1.MON_IOUT_1_BITS.IOUT1_MON*1.2)
#define MPQ2022_ANT2_POWER_PG_FLAG()				(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.DEV_STAT.DEV_STAT_BITS.VOUT1_PG)
#define MPQ2022_ANT2_POWER_OC_FLAG()				(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.ERR_FLAG_2.ERR_FLAG_2_BITS.LDO_1_OC)
#define MPQ2022_ANT2_POWER_OV_FLAG()				(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.ERR_FLAG_1.ERR_FLAG_1_BITS.VOUT_1_OV)
#define MPQ2022_ANT2_POWER_UV_FLAG()				(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.ERR_FLAG_1.ERR_FLAG_1_BITS.VOUT_1_UV)
#define MPQ2022_ANT2_POWER_STB_FLAG()				(sMPQ2022Ctrl[eMPS2022_ANT1_2].DeviceRegs.ERR_FLAG_1.ERR_FLAG_1_BITS.LDO_1_StB)

//public RVC
#define MPQ2022_RVC_POWER_CURRENT_BASE(val) 		(sMPQ2022Ctrl[eMPS2022_RVC].DeviceRegs.SET_IOUT_LIM_2.SET_IOUT_LIM_2_BITS.OC_MIN = val)//0:300mA , 1:100mA
#define MPQ2022_RVC_POWER_ADC_SAMPLE(val)			(sMPQ2022Ctrl[eMPS2022_RVC].DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.ADC_EN = val)
#define MPQ2022_RVC_POWER_FAULT_HANDLE(val)			(sMPQ2022Ctrl[eMPS2022_RVC].DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.FAULT_HANDLE = val)
//private RVC : use chanel 1
#define MPQ2022_RVC_POWER_VOLTAGE_STEP_SET(val) 	(sMPQ2022Ctrl[eMPS2022_RVC].DeviceRegs.SET_VOUT_1.SET_VOUT_1_BITS.VOUT1_STEP = val)
#define MPQ2022_RVC_POWER_VOLTAGE_SET(val) 			(sMPQ2022Ctrl[eMPS2022_RVC].DeviceRegs.SET_VOUT_1.SET_VOUT_1_BITS.VOUT1_SET = val)
#define MPQ2022_RVC_POWER_CURRENT_SET(val) 			(sMPQ2022Ctrl[eMPS2022_RVC].DeviceRegs.SET_IOUT_LIM_1.SET_IOUT_LIM_1_BITS.IOUT_1_OC_THR = val)
#define MPQ2022_RVC_POWER_OUTPUT_OPEN() 			(sMPQ2022Ctrl[eMPS2022_RVC].DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_1_EN = 1)
#define MPQ2022_RVC_POWER_OUTPUT_CLOSE() 			(sMPQ2022Ctrl[eMPS2022_RVC].DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_1_EN = 0)
#define MPQ2022_RVC_POWER_VOLTAGE_SAMPLE() 			(sMPQ2022Ctrl[eMPS2022_RVC].DeviceRegs.MON_VOUT_1.MON_VOUT_1_BITS.VOUT1_MON*55)
#define MPQ2022_RVC_POWER_CURRENT_SAMPLE() 			(sMPQ2022Ctrl[eMPS2022_RVC].DeviceRegs.MON_IOUT_1.MON_IOUT_1_BITS.IOUT1_MON*1.2)
#define MPQ2022_RVC_POWER_PG_FLAG()					(sMPQ2022Ctrl[eMPS2022_RVC].DeviceRegs.DEV_STAT.DEV_STAT_BITS.VOUT1_PG)
#define MPQ2022_RVC_POWER_OC_FLAG()					(sMPQ2022Ctrl[eMPS2022_RVC].DeviceRegs.ERR_FLAG_2.ERR_FLAG_2_BITS.LDO_1_OC)
#define MPQ2022_RVC_POWER_OV_FLAG()					(sMPQ2022Ctrl[eMPS2022_RVC].DeviceRegs.ERR_FLAG_1.ERR_FLAG_1_BITS.VOUT_1_OV)
#define MPQ2022_RVC_POWER_UV_FLAG()					(sMPQ2022Ctrl[eMPS2022_RVC].DeviceRegs.ERR_FLAG_1.ERR_FLAG_1_BITS.VOUT_1_UV)
#define MPQ2022_RVC_POWER_STB_FLAG()				(sMPQ2022Ctrl[eMPS2022_RVC].DeviceRegs.ERR_FLAG_1.ERR_FLAG_1_BITS.LDO_1_StB)

/***********************************************************************
 * @brief       :MPQ2022_CRC
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint8 MPQ2022_CRC(uint8 *pBuffer,sint16 bufSize)
{
	uint8 crc = 0;
	uint16 i = 0 ;
	if ( bufSize <= 0 )
	{
		return crc;
	}
	while( bufSize-- != 0 )
	{
		for ( i = 0x80; i != 0; i /= 2 )
		{
			if ( (crc & 0x80) != 0)
			{
				crc *= 2;
				crc ^= 0x07;//(x^8+x^2+x+1)
			}
			else
			{
				crc *= 2;
			}
			if ( (*pBuffer & i) != 0 )
			{
				crc ^= 0x07;//(x^8+x^2+x+1)
			}
		}
		pBuffer++;
	}
	return crc;
}
/***********************************************************************
 * @brief       :MPQ2022_Write
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void MPQ2022_Write(eMPQ2022DeviceIndex_t deviceIdx,uint8 regAdd,uint8 *data)
{
	uint8 *u8PData=NULL_PTR;
	if(( deviceIdx < eMPS2022_MAX ) && (FALSE == sMPQ2022Ctrl[deviceIdx].init) && (regAdd <= eMPS2022_REG_DEV_REV_ID_MAX))
	{
		sMPQ2022Ctrl[deviceIdx].regEvent[regAdd].eventMask |= eMPS2022_RegEventMask_Write;
		sMPQ2022Ctrl[deviceIdx].regEvent[regAdd].writeData = *data;
	}
}
/***********************************************************************
 * @brief       :MPQ2022_Read
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void MPQ2022_Read(eMPQ2022DeviceIndex_t deviceIdx,uint8 regAdd,uint8 *data)
{
	uint8 *u8PData=NULL_PTR;
    IIC_Return_t   ret = eIIC_Return_Error;
	if(( deviceIdx < eMPS2022_MAX ) && (TRUE == sMPQ2022Ctrl[deviceIdx].init) && (regAdd <= eMPS2022_REG_DEV_REV_ID_MAX))
	{
		sMPQ2022Ctrl[deviceIdx].regEvent[regAdd].eventMask |= eMPS2022_RegEventMask_Read;
		u8PData = &sMPQ2022Ctrl[deviceIdx].DeviceRegs.DEV_REV.unionData;
		*data = u8PData[regAdd];
	}
}
/***********************************************************************
 * @brief       :MPQ22022_GetCombineConditionVlu
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static s_MPQ2022DTCCombineCondition_t MPQ22022_GetCombineConditionVlu(eMPQ2022DeviceIndex_t deviceIdx,uint8 chanel)
{
	s_MPQ2022DTCCombineCondition_t cc;
	switch(deviceIdx)
	{
		case eMPS2022_MIC_GNSS:
			if(chanel == MPQ2022_MIC_DEVICE_CHANEL_ID)//MIC
			{
				cc.vol = MPQ2022_MIC_POWER_VOLTAGE_SAMPLE();
				cc.cur = MPQ2022_MIC_POWER_CURRENT_SAMPLE();
				cc.oc = MPQ2022_MIC_POWER_OC_FLAG();
				cc.ov = MPQ2022_MIC_POWER_OV_FLAG();
				cc.uv = MPQ2022_MIC_POWER_UV_FLAG();
				cc.stb = MPQ2022_MIC_POWER_STB_FLAG();
			}
			else if(chanel == MPQ2022_GNSS_DEVICE_CHANEL_ID)//GNSS
			{
				cc.vol = MPQ2022_GNSS_POWER_VOLTAGE_SAMPLE();
				cc.cur = MPQ2022_GNSS_POWER_CURRENT_SAMPLE();
				cc.oc = MPQ2022_GNSS_POWER_OC_FLAG();
				cc.ov = MPQ2022_GNSS_POWER_OV_FLAG();
				cc.uv = MPQ2022_GNSS_POWER_UV_FLAG();
				cc.stb = MPQ2022_GNSS_POWER_STB_FLAG();
			}
		break;
		case eMPS2022_ANT1_2:
			if(chanel == MPQ2022_ANT1_DEVICE_CHANEL_ID)//ANT1
			{
				cc.vol = MPQ2022_ANT1_POWER_VOLTAGE_SAMPLE();
				cc.cur = MPQ2022_ANT1_POWER_CURRENT_SAMPLE();
				cc.oc = MPQ2022_ANT1_POWER_OC_FLAG();
				cc.ov = MPQ2022_ANT1_POWER_OV_FLAG();
				cc.uv = MPQ2022_ANT1_POWER_UV_FLAG();
				cc.stb = MPQ2022_ANT1_POWER_STB_FLAG();
			}
			else if(chanel == MPQ2022_ANT2_DEVICE_CHANEL_ID)//ANT2
			{
				cc.vol = MPQ2022_ANT2_POWER_VOLTAGE_SAMPLE();
				cc.cur = MPQ2022_ANT2_POWER_CURRENT_SAMPLE();
				cc.oc = MPQ2022_ANT2_POWER_OC_FLAG();
				cc.ov = MPQ2022_ANT2_POWER_OV_FLAG();
				cc.uv = MPQ2022_ANT2_POWER_UV_FLAG();
				cc.stb = MPQ2022_ANT2_POWER_STB_FLAG();
			}
		break;
		case eMPS2022_RVC:
			if(chanel == MPQ2022_RVC_DEVICE_CHANEL_ID)//RVC
			{
				cc.vol = MPQ2022_RVC_POWER_VOLTAGE_SAMPLE();
				cc.cur = MPQ2022_RVC_POWER_CURRENT_SAMPLE();
				cc.oc = MPQ2022_RVC_POWER_OC_FLAG();
				cc.ov = MPQ2022_RVC_POWER_OV_FLAG();
				cc.uv = MPQ2022_RVC_POWER_UV_FLAG();
				cc.stb = MPQ2022_RVC_POWER_STB_FLAG();
			}
		break;
		default:
		break;
	}
	return cc;
}


uint16 MPQ22022_MIC_V_GET(void)//mv
{
	return MPQ2022_MIC_POWER_VOLTAGE_SAMPLE();
}
uint16 MPQ22022_MIC_I_GET(void)//mA
{
	return MPQ2022_MIC_POWER_CURRENT_SAMPLE();
}
uint16 MPQ22022_GNSS_V_GET(void)//mv
{
	return MPQ2022_GNSS_POWER_VOLTAGE_SAMPLE();
}
uint16 MPQ22022_GNSS_I_GET(void)//mA
{
	return MPQ2022_GNSS_POWER_CURRENT_SAMPLE();
}
uint16 MPQ22022_ANT1_V_GET(void)//mv
{
	return MPQ2022_ANT1_POWER_VOLTAGE_SAMPLE();
}
uint16 MPQ22022_ANT1_I_GET(void)//mA
{
	return MPQ2022_ANT1_POWER_CURRENT_SAMPLE();
}
uint16 MPQ22022_ANT2_V_GET(void)//mv
{
	return MPQ2022_ANT2_POWER_VOLTAGE_SAMPLE();
}
uint16 MPQ22022_ANT2_I_GET(void)//mA
{
	return MPQ2022_ANT2_POWER_CURRENT_SAMPLE();
}
uint16 MPQ22022_RVC_V_GET(void)//mv
{
	return MPQ2022_RVC_POWER_VOLTAGE_SAMPLE();
}
uint16 MPQ22022_RVC_I_GET(void)//mA
{
	return MPQ2022_RVC_POWER_CURRENT_SAMPLE();
}

/***********************************************************************
 * @brief       :MPQ2022_DTCCheck
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean MPQ2022_DTCCheck(eMPQ2022DeviceIndex_t deviceIdx,uint8 chanel ,uint8 stsId)
{
	boolean dtcGen=FALSE;
	uint8 comditionMatched = 0;
	uint8 comditionMask = 0;
	s_MPQ2022DTCCombineCondition_t cc;
	const s_MPQ2022DeviceMon_t *pMPQ2022Mon=NULL_PTR;
	if((deviceIdx < eMPS2022_MAX)&&(chanel < 2)&&( stsId < 4))
	{	
		pMPQ2022Mon = sMPQ2022Mon[deviceIdx][chanel];
		if(NULL_PTR	!= pMPQ2022Mon)
		{
			cc = MPQ22022_GetCombineConditionVlu(deviceIdx,chanel);
			//1.voltage judge min
			if(MN_CARE != pMPQ2022Mon[stsId].voltageMin)
			{
				comditionMask |= 0x01;
				if(cc.vol >= pMPQ2022Mon[stsId].voltageMin)
				{
					comditionMatched |=0x01;
				}
			}
			//2.voltage judge max
			if(MN_CARE != pMPQ2022Mon[stsId].voltageMax)
			{
				comditionMask |= 0x02;
				if(cc.vol <= pMPQ2022Mon[stsId].voltageMax)
				{
					comditionMatched |=0x02;
				}
			}
			//3.current judge min
			if(MN_CARE != pMPQ2022Mon[stsId].currentMin)
			{
				comditionMask |= 0x04;
				if(cc.cur >= pMPQ2022Mon[stsId].currentMin)
				{
					comditionMatched |=0x04;
				}
			}
			//4.current judge max
			if(MN_CARE != pMPQ2022Mon[stsId].currentMax)
			{
				comditionMask |= 0x08;
				if(cc.cur <= pMPQ2022Mon[stsId].currentMax)
				{
					comditionMatched |=0x08;
				}
			}
			//if mask equ match , DTC gen
			if(comditionMask == comditionMatched)
			{
				dtcGen = TRUE;
			}
		}
	}
	return dtcGen;
}
/***********************************************************************
 * @brief       :MPQ2022_MICDTC_Check
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean MPQ2022_MICDTC_Check(uint8 stsId)
{
	return MPQ2022_DTCCheck(MPQ2022_MIC_DEVICE_ID,MPQ2022_MIC_DEVICE_CHANEL_ID,stsId);
}
/***********************************************************************
 * @brief       :MPQ2022_GNSSDTC_Check
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean MPQ2022_GNSSDTC_Check(uint8 stsId)
{
	return MPQ2022_DTCCheck(MPQ2022_GNSS_DEVICE_ID,MPQ2022_GNSS_DEVICE_CHANEL_ID,stsId);
}
/***********************************************************************
 * @brief       :MPQ2022_FMDTC_Check
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean MPQ2022_ANTDTC_Check(uint8 sen,uint8 stsId)
{
	if(sen == 0)
	{
		return MPQ2022_DTCCheck(MPQ2022_ANT1_DEVICE_ID,MPQ2022_ANT1_DEVICE_CHANEL_ID,stsId);
	}
	else
	{
		return MPQ2022_DTCCheck(MPQ2022_ANT2_DEVICE_ID,MPQ2022_ANT2_DEVICE_CHANEL_ID,stsId);
	}
}
/***********************************************************************
 * @brief       :MPQ2022_RVCDTC_Check
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean MPQ2022_RVCDTC_Check(uint8 stsId)
{
	return MPQ2022_DTCCheck(MPQ2022_RVC_DEVICE_ID,MPQ2022_RVC_DEVICE_CHANEL_ID,stsId);
}
/***********************************************************************
 * @brief       : MPQ2022_MICPowerOn/Off
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MPQ2022_MICPowerSet(boolean set)
{
	if(TRUE == set)
	{
		MPQ2022_MIC_POWER_OUTPUT_OPEN();
	}
	else
	{
		MPQ2022_MIC_POWER_OUTPUT_CLOSE();
	}
	MPQ2022_WRITE_TRIGGER(eMPS2022_MIC_GNSS,eMPS2022_REG_ID_DEV_CTRL);
}
/***********************************************************************
 * @brief       : MPQ2022_GNSSPowerOn/Off
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MPQ2022_GNSSPowerSet(boolean set)
{
	if(TRUE == set)
	{
		MPQ2022_GNSS_POWER_OUTPUT_OPEN();
	}
	else
	{
		MPQ2022_GNSS_POWER_OUTPUT_CLOSE();
	}
	MPQ2022_WRITE_TRIGGER(eMPS2022_MIC_GNSS,eMPS2022_REG_ID_DEV_CTRL);
}
/***********************************************************************
 * @brief       : MPQ2022_FM1PowerOn/Off
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MPQ2022_ANT1PowerSet(boolean set)
{
	if(TRUE == set)
	{
		MPQ2022_ANT1_POWER_OUTPUT_OPEN();
	}
	else
	{
		MPQ2022_ANT1_POWER_OUTPUT_CLOSE();
	}
	MPQ2022_WRITE_TRIGGER(eMPS2022_ANT1_2,eMPS2022_REG_ID_DEV_CTRL);
}
/***********************************************************************
 * @brief       : MPQ2022_FM2PowerOn/Off
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MPQ2022_ANT2PowerSet(boolean set)
{
	if(TRUE == set)
	{
		MPQ2022_ANT2_POWER_OUTPUT_OPEN();
	}
	else
	{
		MPQ2022_ANT2_POWER_OUTPUT_CLOSE();
	}
	MPQ2022_WRITE_TRIGGER(eMPS2022_ANT1_2,eMPS2022_REG_ID_DEV_CTRL);
}
/***********************************************************************
 * @brief       : MPQ2022_RVCPowerOn/Off
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MPQ2022_RVCPowerSet(boolean set)
{
	if(TRUE == set)
	{
		MPQ2022_RVC_POWER_OUTPUT_OPEN();
	}
	else
	{
		MPQ2022_RVC_POWER_OUTPUT_CLOSE();
	}
	MPQ2022_WRITE_TRIGGER(eMPS2022_RVC,eMPS2022_REG_ID_DEV_CTRL);
}

/***********************************************************************
 * @brief       :  MPQ2022 init
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MPQ2022Init(eMPQ2022DeviceIndex_t deviceIdx)
{
	s_MPQ2022Ctrl_t *pMPQ2022Ctrl=NULL_PTR;
	if(( deviceIdx < eMPS2022_MAX ) && (FALSE == sMPQ2022Ctrl[deviceIdx].init))
	{
		pMPQ2022Ctrl = &sMPQ2022Ctrl[deviceIdx];
		switch(deviceIdx)
		{
			case eMPS2022_MIC_GNSS://address 0x21
				//public
				MPQ2022_MIC_GNSS_POWER_CURRENT_BASE(1);//LIMIT base = 100mA
				MPQ2022_MIC_GNSS_POWER_ADC_SAMPLE(1);//enable ADC sample
				MPQ2022_MIC_GNSS_POWER_FAULT_HANDLE(1);//0: Latch mode , 1: Hiccup with 100ms blanking time
			
				//private MIC : chanel 1 
				MPQ2022_MIC_POWER_VOLTAGE_STEP_SET(1);//step = 200mV
				MPQ2022_MIC_POWER_VOLTAGE_SET(0x24);//Vout = 1+0.200*0x24=8.2v
				MPQ2022_MIC_POWER_CURRENT_SET(0);//Iout1Limt = base+0*6.25=100mA
				MPQ2022_MIC_POWER_OUTPUT_CLOSE();//close MIC power output

				//private GNSS : chanel 2 
				MPQ2022_GNSS_POWER_VOLTAGE_STEP_SET(1);//step = 200mV
				MPQ2022_GNSS_POWER_VOLTAGE_SET(20);//Vout = 1+ 0.200*20 = 5v
				MPQ2022_GNSS_POWER_CURRENT_SET(2);//Iout1Limt = base+2*6.25=113mA
				MPQ2022_GNSS_POWER_OUTPUT_CLOSE();//close GNSS power output
				//
				pMPQ2022Ctrl->init = TRUE;
			break;
			case eMPS2022_ANT1_2://address 0x22
				//public
				MPQ2022_ANT1_2_POWER_CURRENT_BASE(1);//LIMIT base = 100mA
				MPQ2022_ANT1_2_POWER_ADC_SAMPLE(1);//enable ADC sample
				MPQ2022_ANT1_2_POWER_FAULT_HANDLE(1);//0: Latch mode , 1: Hiccup with 100ms blanking time
				
				//private ANT1 : chanel 1 
				MPQ2022_ANT1_POWER_VOLTAGE_STEP_SET(1);//step = 200mV
				MPQ2022_ANT1_POWER_VOLTAGE_SET(43);//Vout = 1+0.200*43=9.6v
				MPQ2022_ANT1_POWER_CURRENT_SET(25);//Iout1Limt = base+25*6.25=259mA
				MPQ2022_ANT1_POWER_OUTPUT_CLOSE();//close ANT1 power output
				
				//private ANT2 : chanel 2 
				MPQ2022_ANT2_POWER_VOLTAGE_STEP_SET(1);//step = 200mV
				MPQ2022_ANT2_POWER_VOLTAGE_SET(43);//Vout = 1+ 0.200*43 = 9.6v
				MPQ2022_ANT2_POWER_CURRENT_SET(25);//Iout1Limt = base+25*6.25=259mA
				MPQ2022_ANT2_POWER_OUTPUT_CLOSE();//close ANT2 power output
				//
				pMPQ2022Ctrl->init = TRUE;
			break;
			case eMPS2022_RVC://address 0x27
				//public
				MPQ2022_RVC_POWER_CURRENT_BASE(0);//LIMIT base = 300mA
				MPQ2022_RVC_POWER_ADC_SAMPLE(1);//enable ADC sample
				MPQ2022_RVC_POWER_FAULT_HANDLE(1);//0: Latch mode , 1: Hiccup with 100ms blanking time
				
				//private RVC : chanel 1 
				MPQ2022_RVC_POWER_VOLTAGE_STEP_SET(1);//step = 200mV
				MPQ2022_RVC_POWER_VOLTAGE_SET(36);//Vout = 1+0.200*36=8.2v
				MPQ2022_RVC_POWER_CURRENT_SET(16);//Iout1Limt = base+16*6.25=400mA
				MPQ2022_RVC_POWER_OUTPUT_CLOSE();//close RVC power output		
				//
				pMPQ2022Ctrl->init = TRUE;
			break;
			default:
				//doing noting
			break;
		}
	}
}


/***********************************************************************
 * @brief       :  MPQ2022HandleErrDeal
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void MPQ2022HandleErrDeal(eMPQ2022DeviceIndex_t deviceIdx,boolean *dealDone)
{
	//if iic write and read err or timeout , set hardware EN off/on
	s_MPQ2022Ctrl_t *pMPQ2022Ctrl=NULL_PTR;
	if(( deviceIdx < eMPS2022_MAX ) && (dealDone != NULL_PTR))
	{
		*dealDone = FALSE;
		pMPQ2022Ctrl = &sMPQ2022Ctrl[deviceIdx];
		switch(pMPQ2022Ctrl->handleErrDeal)
		{
			case eMPS2022_HandleErrDealStatus_PowerOff:
				misc_err("IICErrorDealStart, device = %s\r\n",MPQ2022_DeviceName[deviceIdx]);
				Dio_WriteChannel(u8MPQ2022_IIC_DeviceEnPin[deviceIdx],STD_LOW);//power off 
				pMPQ2022Ctrl->handErrTick = pMPQ2022Ctrl->curTick;
				pMPQ2022Ctrl->handleErrDeal = eMPS2022_HandleErrDealStatus_PowerOff_Wait;
			break;
			case eMPS2022_HandleErrDealStatus_PowerOff_Wait:
				if(pMPQ2022Ctrl->curTick - pMPQ2022Ctrl->handErrTick >= MPQ2022_HANDLE_ERR_POWER_ON_OFF_TIMEOUT)
				{
					Dio_WriteChannel(u8MPQ2022_IIC_DeviceEnPin[deviceIdx],STD_HIGH);//power on
					pMPQ2022Ctrl->handErrTick = pMPQ2022Ctrl->curTick;
					pMPQ2022Ctrl->handleErrDeal = eMPS2022_HandleErrDealStatus_PowerOn_Wait;
				}
			break;
			case eMPS2022_HandleErrDealStatus_PowerOn_Wait:
				if(pMPQ2022Ctrl->curTick - pMPQ2022Ctrl->handErrTick >= MPQ2022_HANDLE_ERR_POWER_ON_OFF_TIMEOUT)
				{
					pMPQ2022Ctrl->handErrTick = pMPQ2022Ctrl->curTick;
					pMPQ2022Ctrl->handleErrDeal = eMPS2022_HandleErrDealStatus_PowerOff;
					*dealDone = TRUE;
					misc_err("IICErrorDealDone, device = %s\r\n",MPQ2022_DeviceName[deviceIdx]);
				}
			break;
			default:
				pMPQ2022Ctrl->handleErrDeal = eMPS2022_HandleErrDealStatus_PowerOff;
			break;
		}
	}
}

/***********************************************************************
 * @brief       :  MPQ2022HandleDeal
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static e_MPQ2022RegEventDealResult_t MPQ2022HandleDeal(eMPQ2022DeviceIndex_t deviceIdx,boolean wr ,eMPQ2022RegId_t regIdx,uint8 *data)
{
	e_MPQ2022RegEventDealResult_t result=eMPS2022_EventDealResult_Busy;
    IIC_Return_t ret = eIIC_Return_Error;
	uint8 crcBuffer[5];
	uint8 *pData=NULL_PTR;
	s_MPQ2022Ctrl_t *pMPQ2022Ctrl=NULL_PTR;
	if( deviceIdx < eMPS2022_MAX )
	{
		pMPQ2022Ctrl = &sMPQ2022Ctrl[deviceIdx];
		//
		if(TRUE == pMPQ2022Ctrl->init)
		{
			switch(pMPQ2022Ctrl->eventDealSts)
			{
				case eMPS2022_EventDealStatus_Idle://inner status , event deal
					memset(&pMPQ2022Ctrl->eventData[0],0x5a,MPQ2022_HANDLE_DATA_BUFF_LEN);
					if(0 == wr)//write iic
					{
						crcBuffer[0] = tIIC_DeviceCfgTable[u8MPQ2022_IIC_DeviceIndex[deviceIdx]].u16adder;//write
						crcBuffer[1] = regIdx;
						crcBuffer[2] = *data;
						crcBuffer[3] = MPQ2022_CRC(&crcBuffer[0],3);
						//
						pMPQ2022Ctrl->eventData[0] = regIdx;//reg address
						pMPQ2022Ctrl->eventData[1] = *data;//write data
						pMPQ2022Ctrl->eventData[2] = crcBuffer[3];//crc-8
						//
						ret = IIC_QueueTxReq(u8MPQ2022_IIC_DeviceIndex[deviceIdx],&pMPQ2022Ctrl->eventData[0],3);
						if (eIIC_Return_Success == ret)
						{
							pMPQ2022Ctrl->eventStartTick = pMPQ2022Ctrl->curTick;
							pMPQ2022Ctrl->eventDealSts = eMPS2022_EventDealStatus_Busy;
						}
						else
						{
							misc_err("IIC_QueueTxReq Faild, device = %s\r\n",MPQ2022_DeviceName[deviceIdx]);
							pMPQ2022Ctrl->eventDealSts = eMPS2022_EventDealStatus_Idle;
						}
					}
					else
					{
						pMPQ2022Ctrl->eventData[0] = regIdx;//reg address , this pointer was reused as receive
						ret = IIC_QueueRxReq(u8MPQ2022_IIC_DeviceIndex[deviceIdx], &pMPQ2022Ctrl->eventData[0], 1, 2);
						if (eIIC_Return_Success == ret)
						{
							pMPQ2022Ctrl->eventStartTick = pMPQ2022Ctrl->curTick;
							pMPQ2022Ctrl->eventDealSts = eMPS2022_EventDealStatus_Busy;
						}
						else
						{
							misc_err("IIC_QueueRxReq Faild, device = %s\r\n",MPQ2022_DeviceName[deviceIdx]);
							pMPQ2022Ctrl->eventDealSts = eMPS2022_EventDealStatus_Idle;
						}
					}
				break;
					
				case eMPS2022_EventDealStatus_Busy://inner status ,timeout wait
					if(pMPQ2022Ctrl->curTick - pMPQ2022Ctrl->eventStartTick >= MPQ2022_HANDLE_BUSY_WAIT_TIMES)//100ms deal time out
					{
						if(0 == wr)//write iic
						{
							misc_warn("write timeout (%dms), device = %s\r\n",MPQ2022_HANDLE_BUSY_WAIT_TIMES,MPQ2022_DeviceName[deviceIdx]);
						}
						else
						{
							misc_warn("read timeout (%dms), device = %s\r\n",MPQ2022_HANDLE_BUSY_WAIT_TIMES,MPQ2022_DeviceName[deviceIdx]);
						}					
						//timeout deal
						if(pMPQ2022Ctrl->handleErrCnt++ >= MPQ2022_HANDLE_RETRY_ENQUEUE_TIMES)
						{
							pMPQ2022Ctrl->handleErrCnt = 0 ;
							result = eMPS2022_EventDealResult_TimeOut;
						}
						else
						{
							pMPQ2022Ctrl->eventDealSts = eMPS2022_EventDealStatus_Idle;
						}
					}
				break;
					
				case eMPS2022_EventDealStatus_RxComplete://from rx callback status
					crcBuffer[0] = tIIC_DeviceCfgTable[u8MPQ2022_IIC_DeviceIndex[deviceIdx]].u16adder + 1;//read
					crcBuffer[1] = regIdx;
					crcBuffer[2] = pMPQ2022Ctrl->eventData[0];
					crcBuffer[3] = MPQ2022_CRC(&crcBuffer[0],3);
					//====remove IIC RX CRC !!!!!!!!!
					//if(crcBuffer[3] == pMPQ2022Ctrl->eventData[1])
					{
						///pData = &pMPQ2022Ctrl->DeviceRegs.DEV_REV.unionData;
						//pData[regIdx] = pMPQ2022Ctrl->eventData[0];
						*data = pMPQ2022Ctrl->eventData[0];
						//
						pMPQ2022Ctrl->handleErrCnt = 0 ;
						result = eMPS2022_EventDealResult_Ok;
					}
					/*
					else
					{
						misc_warn("iic rx complete, crc err ,device = %s, Id = %d\r\n",MPQ2022_DeviceName[deviceIdx],regIdx);
						//crc err deal , need retry read
						if(pMPQ2022Ctrl->handleErrCnt++ >= MPQ2022_HANDLE_RETRY_ENQUEUE_TIMES)
						{
							result = eMPS2022_EventDealResult_CRCNotOk;
						}
					}
					*/
					//
					pMPQ2022Ctrl->eventDealSts = eMPS2022_EventDealStatus_Idle;
				break;
					
				case eMPS2022_EventDealStatus_TxComplete://from tx callback status
					pMPQ2022Ctrl->handleErrCnt = 0 ;
					result = eMPS2022_EventDealResult_Ok;
					pMPQ2022Ctrl->eventDealSts = eMPS2022_EventDealStatus_Idle;
				break;
				
				case eMPS2022_EventDealStatus_IICBusError://from rx/tx callback , iic deal err
					misc_err("iic deal error, device = %s\r\n",MPQ2022_DeviceName[deviceIdx]);				
					//iic err deal
					if(pMPQ2022Ctrl->handleErrCnt++ >= MPQ2022_HANDLE_RETRY_ENQUEUE_TIMES)
					{
						pMPQ2022Ctrl->handleErrCnt = 0 ;
						result = eMPS2022_EventDealResult_IICBussErr;
					}
					//
					pMPQ2022Ctrl->eventDealSts = eMPS2022_EventDealStatus_Idle;
				break;		
				default:
					pMPQ2022Ctrl->handleErrCnt = 0 ;
					pMPQ2022Ctrl->eventDealSts = eMPS2022_EventDealStatus_Idle;
				break;
			}
		}
	}
	return result;
}
/***********************************************************************
 * @brief       :  MPQ2022_ReadHandle
 * @param       : 
 * @retval      : 
 ***********************************************************************/
e_MPQ2022RegEventDealResult_t MPQ2022_ReadHandle(eMPQ2022DeviceIndex_t deviceIdx,eMPQ2022RegId_t regIdx,uint8 *data)
{
	//if read not complete , it will read again
	return MPQ2022HandleDeal(deviceIdx,1,regIdx,data);
}
/***********************************************************************
 * @brief       :  MPQ2022_WriteHandle
 * @param       : 
 * @retval      : 
 ***********************************************************************/
e_MPQ2022RegEventDealResult_t MPQ2022_WriteHandle(eMPQ2022DeviceIndex_t deviceIdx,eMPQ2022RegId_t regIdx,uint8 *data)
{
	//if write not complete , it will write again
	return MPQ2022HandleDeal(deviceIdx,0,regIdx,data);
}
/***********************************************************************
 * @brief       :  MPQ2022_WriteAndReadBackHandle
 * @param       : 
 * @retval      : 
 ***********************************************************************/
e_MPQ2022RegEventDealResult_t MPQ2022_WriteAndReadBackHandle(eMPQ2022DeviceIndex_t deviceIdx,eMPQ2022RegId_t regIdx,uint8 *data)
{
	//if write not complete , it will write again
	e_MPQ2022RegEventDealResult_t result = eMPS2022_EventDealResult_Busy;
	e_MPQ2022RegEventDealResult_t ret = eMPS2022_EventDealResult_Busy;
	s_MPQ2022Ctrl_t *pMPQ2022Ctrl=NULL_PTR;
	uint8 *pData=NULL_PTR;
	static uint8 writeReadData=0;
	if( deviceIdx < eMPS2022_MAX )
	{
		pMPQ2022Ctrl = &sMPQ2022Ctrl[deviceIdx];
		switch(pMPQ2022Ctrl->writeReadBack)
		{
			case eMPS2022_WriteReadBackStatus_Write:
				ret = MPQ2022_WriteHandle(deviceIdx,regIdx,data);
				if(eMPS2022_EventDealResult_Ok == ret)//write
				{
					pMPQ2022Ctrl->writeReadBack = eMPS2022_WriteReadBackStatus_Read;
				}
				else//TimeOut or CRC not match or IIC BUS err , how to deal , up deal ???? .....
				{
					result = ret;
					pMPQ2022Ctrl->writeReadBack = eMPS2022_WriteReadBackStatus_Write;
				}
			break;
			case eMPS2022_WriteReadBackStatus_Read:
				ret = MPQ2022_ReadHandle(deviceIdx,regIdx,&writeReadData);
				if(eMPS2022_EventDealResult_Ok == ret)//write
				{
					if(writeReadData == *data)//write equ read
					{
						result = eMPS2022_EventDealResult_Ok;
					}
					else//crc ok but write date not match read
					{
						//when 3 time write not match read , how to do ?????????????????, 
						misc_err("iic write not match read : device = %s\r\n",MPQ2022_DeviceName[deviceIdx]);
						result = eMPS2022_EventDealResult_WriteReadNotMatch;
					}
					pMPQ2022Ctrl->writeReadBack = eMPS2022_WriteReadBackStatus_Write;
				}
				else if(eMPS2022_EventDealResult_Busy != ret)//wait TimeOut or CRC not match or IIC BUS err , how to deal , up deal ???? .....
				{
					result = ret;
					pMPQ2022Ctrl->writeReadBack = eMPS2022_WriteReadBackStatus_Write;
				}
			break;
			default:
				pMPQ2022Ctrl->writeReadBack = eMPS2022_WriteReadBackStatus_Write;
			break;
		}
	}
	return result;
}
/***********************************************************************
 * @brief       :  MPQ2022_StartUpDeal
 * @param       : 
 * @retval      : 
 ***********************************************************************/
e_MPQ2022RegEventDealResult_t MPQ2022_StartUpDeal(eMPQ2022DeviceIndex_t deviceIdx,boolean *dealDone)
{
	e_MPQ2022RegEventDealResult_t result = eMPS2022_EventDealResult_Busy;
	s_MPQ2022Ctrl_t *pMPQ2022Ctrl=NULL_PTR;
	uint8 *pData=NULL_PTR;
	if(( deviceIdx < eMPS2022_MAX ) && (dealDone != NULL_PTR))
	{
		pMPQ2022Ctrl = &sMPQ2022Ctrl[deviceIdx];
		pData = &pMPQ2022Ctrl->DeviceRegs.DEV_REV.unionData;//first offset
		//
		switch(pMPQ2022Ctrl->startUpIdx)
		{
			case eMPS2022_StartUpSeqId_Set_DEV_CTRL_DisOutPut://write eMPS2022_REG_ID_DEV_CTRL ; disable LDO output
				pMPQ2022Ctrl->DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_1_EN = 0;//disable LDO output
				pMPQ2022Ctrl->DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_2_EN = 0;//disable LDO output
				result = MPQ2022_WriteAndReadBackHandle(deviceIdx,eMPS2022_REG_ID_DEV_CTRL,&pData[eMPS2022_REG_ID_DEV_CTRL]);
				if(eMPS2022_EventDealResult_Ok == result)
				{
					pMPQ2022Ctrl->startUpIdx = eMPS2022_StartUpSeqId_SET_VOUT_1;
				}
			break;
			case eMPS2022_StartUpSeqId_SET_VOUT_1://write eMPS2022_REG_ID_SET_VOUT_1
				result = MPQ2022_WriteAndReadBackHandle(deviceIdx,eMPS2022_REG_ID_SET_VOUT_1,&pData[eMPS2022_REG_ID_SET_VOUT_1]);
				if(eMPS2022_EventDealResult_Ok == result)
				{
					pMPQ2022Ctrl->startUpIdx = eMPS2022_StartUpSeqId_SET_VOUT_2;
				}
			break;	
			case eMPS2022_StartUpSeqId_SET_VOUT_2://write eMPS2022_REG_ID_SET_VOUT_2
				result = MPQ2022_WriteAndReadBackHandle(deviceIdx,eMPS2022_REG_ID_SET_VOUT_2,&pData[eMPS2022_REG_ID_SET_VOUT_2]);
				if(eMPS2022_EventDealResult_Ok == result)
				{
					pMPQ2022Ctrl->startUpIdx = eMPS2022_StartUpSeqId_SET_IOUT_LIM_1;
				}
			break;
			case eMPS2022_StartUpSeqId_SET_IOUT_LIM_1://write eMPS2022_REG_ID_SET_IOUT_LIM_1
				result = MPQ2022_WriteAndReadBackHandle(deviceIdx,eMPS2022_REG_ID_SET_IOUT_LIM_1,&pData[eMPS2022_REG_ID_SET_IOUT_LIM_1]);
				if(eMPS2022_EventDealResult_Ok == result)
				{
					pMPQ2022Ctrl->startUpIdx = eMPS2022_StartUpSeqId_SET_IOUT_LIM_2;
				}
			break;
			case eMPS2022_StartUpSeqId_SET_IOUT_LIM_2://write eMPS2022_REG_ID_SET_IOUT_LIM_2
				result = MPQ2022_WriteAndReadBackHandle(deviceIdx,eMPS2022_REG_ID_SET_IOUT_LIM_2,&pData[eMPS2022_REG_ID_SET_IOUT_LIM_2]);
				if(eMPS2022_EventDealResult_Ok == result)
				{
					pMPQ2022Ctrl->startUpIdx = eMPS2022_StartUpSeqId_Set_DEV_CTRL_EnOutPut;
				}
			break;
			case eMPS2022_StartUpSeqId_Set_DEV_CTRL_EnOutPut://write eMPS2022_REG_ID_DEV_CTRL ; enable LDO output
				if(eMPS2022_MIC_GNSS == deviceIdx)//address 0x21
				{
					//MIC POWER
					pMPQ2022Ctrl->DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_1_EN = 1;//enable LDO output		
					if(TRUE == MISC_SYSGNSSWasUsed())
					{
						//GNSS POWER
						pMPQ2022Ctrl->DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_2_EN = 1;//enable LDO output
					}
				}else if(eMPS2022_ANT1_2 == deviceIdx)//address 0x22
				{
					//special : cause hardware name exchanged , 'FM1' was chanel 2 ; 'FM2' was channel 1 
					//FM2 POWER
					//pMPQ2022Ctrl->DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_1_EN = 1;//enable LDO output
					//FM1 POWER
					pMPQ2022Ctrl->DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_2_EN = 1;//enable LDO output
				}else if(eMPS2022_RVC == deviceIdx)//address 0x27
				{
					if(TRUE == MISC_SYSRVCWasUsed())
					{
						//RVC POWER
						pMPQ2022Ctrl->DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_1_EN = 1;//enable LDO output		
					}
					//RESERVED
					//pMPQ2022Ctrl->DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_2_EN = 1;//enable LDO output
				}
				else
				{
					//doing noting
				}
				//
				//pMPQ2022Ctrl->DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_1_EN = 1;//enable LDO output
				//pMPQ2022Ctrl->DeviceRegs.DEV_CTRL.DEV_CTRL_BITS.LDO_2_EN = 1;//enbale LDO output
				//
				result = MPQ2022_WriteAndReadBackHandle(deviceIdx,eMPS2022_REG_ID_DEV_CTRL,&pData[eMPS2022_REG_ID_DEV_CTRL]);
				if(eMPS2022_EventDealResult_Ok == result)
				{
					pMPQ2022Ctrl->startUpIdx = eMPS2022_StartUpSeqId_Set_DEV_CTRL_DisOutPut;
					*dealDone = TRUE;
				}
			break;		
			default:
				pMPQ2022Ctrl->startUpIdx = eMPS2022_StartUpSeqId_Set_DEV_CTRL_DisOutPut ;
			break;
		}	
	}
	return result;
}
/***********************************************************************
 * @brief       :  MPQ2022_StateMonitor
 * @param       : 
 * @retval      : 
 ***********************************************************************/
e_MPQ2022RegEventDealResult_t MPQ2022_StateMonitor(eMPQ2022DeviceIndex_t deviceIdx,boolean *dealDone)
{
	e_MPQ2022RegEventDealResult_t result = eMPS2022_EventDealResult_Busy;
	s_MPQ2022Ctrl_t *pMPQ2022Ctrl=NULL_PTR;
	uint8 *pData=NULL_PTR;
	if(( deviceIdx < eMPS2022_MAX ) && (dealDone != NULL_PTR))
	{
		pMPQ2022Ctrl = &sMPQ2022Ctrl[deviceIdx];
		pData = &pMPQ2022Ctrl->DeviceRegs.DEV_REV.unionData;//first offset
		//
		switch(pMPQ2022Ctrl->stateMonitorIdx)
		{
			case eMPS2022_MonitorSeqId_Get_VOUT_1://read eMPS2022_REG_ID_MON_VOUT_1
				result = MPQ2022_ReadHandle(deviceIdx,eMPS2022_REG_ID_MON_VOUT_1,&pData[eMPS2022_REG_ID_MON_VOUT_1]);
				if(eMPS2022_EventDealResult_Ok == result)
				{
					pMPQ2022Ctrl->stateMonitorIdx = eMPS2022_MonitorSeqId_Get_VOUT_2;
				}
			break;
			case eMPS2022_MonitorSeqId_Get_VOUT_2://read eMPS2022_REG_ID_MON_VOUT_2
				result = MPQ2022_ReadHandle(deviceIdx,eMPS2022_REG_ID_MON_VOUT_2,&pData[eMPS2022_REG_ID_MON_VOUT_2]);
				if(eMPS2022_EventDealResult_Ok == result)
				{
					pMPQ2022Ctrl->stateMonitorIdx = eMPS2022_MonitorSeqId_Get_IOUT_1;
				}
			break;			
			case eMPS2022_MonitorSeqId_Get_IOUT_1://read eMPS2022_REG_ID_MON_IOUT_1
				result = MPQ2022_ReadHandle(deviceIdx,eMPS2022_REG_ID_MON_IOUT_1,&pData[eMPS2022_REG_ID_MON_IOUT_1]);
				if(eMPS2022_EventDealResult_Ok == result)
				{
					pMPQ2022Ctrl->stateMonitorIdx = eMPS2022_MonitorSeqId_Get_IOUT_2;
				}
			break;
			case eMPS2022_MonitorSeqId_Get_IOUT_2://read eMPS2022_REG_ID_MON_IOUT_2
				result = MPQ2022_ReadHandle(deviceIdx,eMPS2022_REG_ID_MON_IOUT_2,&pData[eMPS2022_REG_ID_MON_IOUT_2]);
				if(eMPS2022_EventDealResult_Ok == result)
				{
					pMPQ2022Ctrl->stateMonitorIdx = eMPS2022_MonitorSeqId_Get_VOUT_1;
					*dealDone = TRUE;
				}
			break;
			default:
				pMPQ2022Ctrl->stateMonitorIdx = eMPS2022_MonitorSeqId_Get_VOUT_1 ;
			break;
		}
	}
	return result;
}
/***********************************************************************
 * @brief       :  MPQ2022_EventDeal
 * @param       : 
 * @retval      : 
 ***********************************************************************/
e_MPQ2022RegEventDealResult_t MPQ2022_EventDeal(eMPQ2022DeviceIndex_t deviceIdx,boolean *dealDone)
{
	e_MPQ2022RegEventDealResult_t result = eMPS2022_EventDealResult_Busy;
	s_MPQ2022Ctrl_t *pMPQ2022Ctrl=NULL_PTR;
	uint8 *pData=NULL_PTR,i=0;
	if(( deviceIdx < eMPS2022_MAX ) && (dealDone != NULL_PTR))
	{
		pMPQ2022Ctrl = &sMPQ2022Ctrl[deviceIdx];
		pData = &pMPQ2022Ctrl->DeviceRegs.DEV_REV.unionData;//first offset
		//fresh all event
		for(i=0;i<eMPS2022_REG_DEV_REV_ID_MAX;i++)
		{
			if((pMPQ2022Ctrl->regEvent[i].eventMask & eMPS2022_RegEventMask_Write) != 0)//event write
			{
				result = MPQ2022_WriteAndReadBackHandle(deviceIdx,i,&pData[i]);
				if(eMPS2022_EventDealResult_Ok == result)
				{
					pMPQ2022Ctrl->regEvent[i].eventMask &= (~eMPS2022_RegEventMask_Write);
				}
				else
				{
					break;//continue MPQ2022_WriteHandle
				}
			}else if((pMPQ2022Ctrl->regEvent[i].eventMask & eMPS2022_RegEventMask_Read) != 0)//event read
			{
				result = MPQ2022_ReadHandle(deviceIdx,i,&pData[i]);
				if(eMPS2022_EventDealResult_Ok == result)
				{
					pMPQ2022Ctrl->regEvent[i].eventMask &= (~eMPS2022_RegEventMask_Read);
				}
				else
				{
					break;//continue MPQ2022_ReadHandle
				}
			}
		}
		if(i >= eMPS2022_REG_DEV_REV_ID_MAX)
		{
			*dealDone = TRUE;
			pMPQ2022Ctrl->eventDealDone = TRUE;
		}
		else
		{
			pMPQ2022Ctrl->eventDealDone = FALSE;
		}
	}
	return result;
}

/***********************************************************************
 * @brief       :  MPQ2022_AllStartUpDone
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean MPQ2022_AllStartUpDone(void)
{
	boolean ret = FALSE;
	eMPQ2022DeviceIndex_t deviceIdx = eMPS2022_MIC_GNSS;
	s_MPQ2022Ctrl_t *pMPQ2022Ctrl=NULL_PTR;
	//
	for(;deviceIdx < eMPS2022_MAX;deviceIdx++)
	{
		pMPQ2022Ctrl = &sMPQ2022Ctrl[deviceIdx];
		if(FALSE == pMPQ2022Ctrl->startUpDone)
		{
			break;
		}
	}
	if(deviceIdx >= eMPS2022_MAX)
	{
		ret = TRUE;
	}
	return ret;
}
/***********************************************************************
 * @brief       :  MPQ2022_AllEventDealDone
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean MPQ2022_AllEventDealDone(void)
{
	boolean ret = FALSE;
	eMPQ2022DeviceIndex_t deviceIdx = eMPS2022_MIC_GNSS;
	s_MPQ2022Ctrl_t *pMPQ2022Ctrl=NULL_PTR;
	//
	for(;deviceIdx < eMPS2022_MAX;deviceIdx++)
	{
		pMPQ2022Ctrl = &sMPQ2022Ctrl[deviceIdx];
		if(FALSE == pMPQ2022Ctrl->eventDealDone)
		{
			break;
		}
	}
	if(deviceIdx >= eMPS2022_MAX)
	{
		ret = TRUE;
	}
	return ret;
}


/***********************************************************************
 * @brief       :  MPQ2022_MainFunction
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MPQ2022_MainFunction(eMPQ2022DeviceIndex_t deviceIdx)
{
	e_MPQ2022RegEventDealResult_t result = eMPS2022_EventDealResult_Busy;
	boolean dealDone = FALSE;
	s_MPQ2022Ctrl_t *pMPQ2022Ctrl=NULL_PTR;
    Std_ReturnType ret = E_NOT_OK;	
	if( deviceIdx < eMPS2022_MAX )
	{
		pMPQ2022Ctrl = &sMPQ2022Ctrl[deviceIdx];
		//
		MPQ2022_GET_OSTick(&pMPQ2022Ctrl->curTick);//get sys current tick
		//
		switch(pMPQ2022Ctrl->ctrlSts)
		{
			case eMPS2022_CtrlStatus_Init:
				MPQ2022Init(deviceIdx);
				pMPQ2022Ctrl->startUpIdx = eMPS2022_StartUpSeqId_Set_DEV_CTRL_DisOutPut ;
				pMPQ2022Ctrl->ctrlSts = eMPS2022_CtrlStatus_StartUp;
				//
				//misc_warn("MPQ2022 init done ! device = %s\r\n",MPQ2022_DeviceName[deviceIdx]);
			break;
			case eMPS2022_CtrlStatus_StartUp:
				result = MPQ2022_StartUpDeal(deviceIdx,&dealDone);
				if(TRUE == dealDone)
				{
					pMPQ2022Ctrl->resultErrDealCnt = 0;//clear 
					pMPQ2022Ctrl->startUpDone = TRUE;
					pMPQ2022Ctrl->stateMonitorIdx = eMPS2022_MonitorSeqId_Get_VOUT_1;
					pMPQ2022Ctrl->ctrlSts = eMPS2022_CtrlStatus_StateMonitor;
					//
					misc_warn("MPQ2022 startup done ! device = %s\r\n",MPQ2022_DeviceName[deviceIdx]);
				}
				else//err deal:app wait timeout , app crc check err , app write read 3 times not match ,IIC bus err , 
				{
					switch(result)
					{
						case eMPS2022_EventDealResult_TimeOut://app: wait timeout
						case eMPS2022_EventDealResult_IICBussErr://hal: iic bus err
						case eMPS2022_EventDealResult_CRCNotOk://app: crc check err
						case eMPS2022_EventDealResult_WriteReadNotMatch://app: write read 3 times not match
							pMPQ2022Ctrl->ctrlSts = eMPS2022_CtrlStatus_ResultErrDeal;
							pMPQ2022Ctrl->handleErrDeal = eMPS2022_HandleErrDealStatus_PowerOff;
						break;
						default:
						break;
					}
				}
			break;
			case eMPS2022_CtrlStatus_StateMonitor:
				if((pMPQ2022Ctrl->curTick - pMPQ2022Ctrl->normalStartTick) >= MPQ2022_STATE_MONITOR_CYCLE)
				{
					result = MPQ2022_StateMonitor(deviceIdx,&dealDone);
					if(TRUE == dealDone)
					{
						pMPQ2022Ctrl->normalStartTick = pMPQ2022Ctrl->curTick;
						pMPQ2022Ctrl->ctrlSts = eMPS2022_CtrlStatus_EventDeal;
					}
					else//err deal:
					{
						switch(result)
						{
							case eMPS2022_EventDealResult_TimeOut:
							case eMPS2022_EventDealResult_IICBussErr:
							case eMPS2022_EventDealResult_CRCNotOk:
							case eMPS2022_EventDealResult_WriteReadNotMatch:
								pMPQ2022Ctrl->ctrlSts = eMPS2022_CtrlStatus_ResultErrDeal;
								pMPQ2022Ctrl->handleErrDeal = eMPS2022_HandleErrDealStatus_PowerOff;
							break;
							default:
							break;
						}
					}
				}
			break;
			case eMPS2022_CtrlStatus_EventDeal:
				result = MPQ2022_EventDeal(deviceIdx,&dealDone);
				if(TRUE == dealDone)
				{
					pMPQ2022Ctrl->stateMonitorIdx = eMPS2022_MonitorSeqId_Get_VOUT_1;
					pMPQ2022Ctrl->ctrlSts = eMPS2022_CtrlStatus_StateMonitor;
				}
				else//err deal:
				{
					switch(result)
					{
						case eMPS2022_EventDealResult_TimeOut:
						case eMPS2022_EventDealResult_IICBussErr:
						case eMPS2022_EventDealResult_CRCNotOk:
						case eMPS2022_EventDealResult_WriteReadNotMatch:
							pMPQ2022Ctrl->ctrlSts = eMPS2022_CtrlStatus_ResultErrDeal;
							pMPQ2022Ctrl->handleErrDeal = eMPS2022_HandleErrDealStatus_PowerOff;
						break;
						default:
						break;
					}
				}			
			break;
			case eMPS2022_CtrlStatus_ResultErrDeal:
				//special:when retry MPQ2022_ERR_HANDLE_RETRY_POWER_ON_OFF_TIMES this sys will stay here ......
				if(pMPQ2022Ctrl->resultErrDealCnt <= MPQ2022_ERR_HANDLE_RETRY_POWER_ON_OFF_TIMES)
				{
					MPQ2022HandleErrDeal(deviceIdx,&dealDone);
					if(TRUE == dealDone)
					{
						pMPQ2022Ctrl->resultErrDealCnt++;
						pMPQ2022Ctrl->init = FALSE;
						pMPQ2022Ctrl->startUpDone = FALSE;
						pMPQ2022Ctrl->eventDealDone = FALSE;
						pMPQ2022Ctrl->ctrlSts = eMPS2022_CtrlStatus_Init;
					}
				}
			break;
			default :
				pMPQ2022Ctrl->ctrlSts = eMPS2022_CtrlStatus_Init;
			break;
		}
	}
}
/***********************************************************************
 * @brief       :  MPQ2022 IIC RX Callback
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MPQ2022_Rx_Callback(eMPQ2022DeviceIndex_t deviceIdx)
{
	if( deviceIdx < eMPS2022_MAX )
	{
		sMPQ2022Ctrl[deviceIdx].eventDealSts = eMPS2022_EventDealStatus_RxComplete;
	}
}
/***********************************************************************
 * @brief       :  MPQ2022 IIC RX Err Callback
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MPQ2022_RxErr_Callback(eMPQ2022DeviceIndex_t deviceIdx)
{
	if( deviceIdx < eMPS2022_MAX )
	{
		sMPQ2022Ctrl[deviceIdx].eventDealSts = eMPS2022_EventDealStatus_IICBusError;
	}
}
/***********************************************************************
 * @brief       :  MPQ2022 IIC TX Callback
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MPQ2022_Tx_Callback(eMPQ2022DeviceIndex_t deviceIdx)
{
	if( deviceIdx < eMPS2022_MAX )
	{
		sMPQ2022Ctrl[deviceIdx].eventDealSts = eMPS2022_EventDealStatus_TxComplete;
	}
}
/***********************************************************************
 * @brief       :  MPQ2022 IIC TX ERR Callback
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void MPQ2022_TxErr_Callback(eMPQ2022DeviceIndex_t deviceIdx)
{
	if( deviceIdx < eMPS2022_MAX )
	{
		sMPQ2022Ctrl[deviceIdx].eventDealSts = eMPS2022_EventDealStatus_IICBusError;
	}
}
void MPQ2022_MIC_GNSS_I2CTx_Callback(IIC_ResultStatus_t state)
{
	if(eIIC_ResultStatus_Error == state)
	{
		MPQ2022_TxErr_Callback(eMPS2022_MIC_GNSS);
	}
	else if(eIIC_ResultStatus_Success == state)
	{
		MPQ2022_Tx_Callback(eMPS2022_MIC_GNSS);
	}
}
void MPQ2022_MIC_GNSS_I2CRx_Callback(IIC_ResultStatus_t state, const uint8 * p_data, uint16 size)
{
	if(eIIC_ResultStatus_Error == state)
	{
		MPQ2022_RxErr_Callback(eMPS2022_MIC_GNSS);
	}
	else if(eIIC_ResultStatus_Success == state)
	{
		MPQ2022_Rx_Callback(eMPS2022_MIC_GNSS);
	}
}
void MPQ2022_ANT1_2_I2CTx_Callback(IIC_ResultStatus_t state)
{
	if(eIIC_ResultStatus_Error == state)
	{
		MPQ2022_TxErr_Callback(eMPS2022_ANT1_2);
	}
	else if(eIIC_ResultStatus_Success == state)
	{
		MPQ2022_Tx_Callback(eMPS2022_ANT1_2);
	}
}
void MPQ2022_ANT1_2_I2CRx_Callback(IIC_ResultStatus_t state, const uint8 * p_data, uint16 size)
{
	if(eIIC_ResultStatus_Error == state)
	{
		MPQ2022_RxErr_Callback(eMPS2022_ANT1_2);
	}
	else if(eIIC_ResultStatus_Success == state)
	{
		MPQ2022_Rx_Callback(eMPS2022_ANT1_2);
	}
}
void MPQ2022_RVC_I2CTx_Callback(IIC_ResultStatus_t state)
{
	if(eIIC_ResultStatus_Error == state)
	{
		MPQ2022_TxErr_Callback(eMPS2022_RVC);
	}
	else if(eIIC_ResultStatus_Success == state)
	{
		MPQ2022_Tx_Callback(eMPS2022_RVC);
	}
}
void MPQ2022_RVC_I2CRx_Callback(IIC_ResultStatus_t state, const uint8 * p_data, uint16 size)
{
	if(eIIC_ResultStatus_Error == state)
	{
		MPQ2022_RxErr_Callback(eMPS2022_RVC);
	}
	else if(eIIC_ResultStatus_Success == state)
	{
		MPQ2022_Rx_Callback(eMPS2022_RVC);
	}
}

