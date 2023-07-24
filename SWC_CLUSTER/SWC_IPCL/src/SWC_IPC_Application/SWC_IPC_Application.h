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

/***********************************************************************************************************
**
**  Name         : SWC_IPC_Application.h
**
**  Description  :
**
**  Organization :
**
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef SWC_IPC_APP_H
#define SWC_IPC_APP_H

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "Rte_Type.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_IPC_Config.h"


/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* IPC Nvm Structure Definenation                                                                          *
**********************************************************************************************************/
/*Total: 60 bytes*/
typedef struct
{
	uint8 NvmVersion;

	/*Drive Mode Switch*/
    boolean DriveModeStorageSwitch;
	/*Highway Assist Switch*/
	//boolean HighwayAssistSwitch;
	/*Lane Change Assist Switch*/
	//boolean LaneChangeAssistSwitch;

	/*WHUD*/
	boolean WHUDSwitch ;
	boolean DriverDisplaySwitch ;
    boolean NaviDisplaySwitch;
	boolean PhoneDisplaySwitch;
	sint8 DisplayRotationLevel;
	uint8 DisplayHeightLevel;
	uint8 DisplayBacklightSwitch;
	uint8 DisplayBacklightLevel;
	uint8 DisplayTheme;
	uint8 DisplayFramework;
	uint8 DisplayMode;

	/*Transport mode*/
	uint8 u8TranPMode_Sts;

	/* Energy Regeneration Level in non-snow mode */
	uint8 HUT_EgyRecvrySet;
	uint8 DriveMode;
	boolean MultiColorNrFlag;
}SWC_IPC_AppConfigNvmBlock;

/**********************************************************************************************************
* IPC Fuel TC Data Upload Structure Definenation                                                          *
**********************************************************************************************************/

typedef struct
{
	#ifndef SWC_IPC_PROJECT_TYPE_B03
	uint32 FuelDisplayValue;
	uint16 FuelDisplayPercent;
	#else
	uint16 FuelDisplayPercent;
	uint16 FuelDisplayValue;
	#endif
	uint16 FuelSensorRawValueA;
	uint16 FuelSensorRawValueB;
	uint16 AfeDisplay;
	uint16 DteFuelStageConsumption;
	uint16 DteDisplay;
	uint16 DteCalculate;
}SWC_IPC_FuelTCDataUpload;

/**********************************************************************************************************
* IPC Alive Monitor Definenation                                                                          *
**********************************************************************************************************/

typedef enum
{
    SWC_IPC_SAFTY_APP_ALIVE_MONITOR = 0 ,
    SWC_IPC_COMMON_APP_ALIVE_MONITOR ,
    SWC_IPC_WHUD_APP_MONITOR ,
    SWC_IPC_INTERFACE_APP_MONITOR ,
    SWC_IPC_GAUGES_APP_ALIVE_MONITOR,
    SWC_IPC_CHIME_CLIENT_APP_ALIVE_MONITOR,
	SWC_IPC_SOC_HMI_SAFETY_ALIVE_MONITOR,
    SWC_IPC_ALIVE_MONITOR_TOTAL_NUMBER ,
}SWC_IPC_AliveMonitorList;

/**********************************************************************************************************
* IPC Restore Definenation                                                                                *
**********************************************************************************************************/

typedef enum
{
	SWC_IPC_CLEAR_DTC = 0 ,
    SWC_IPC_RESTORE_CAN ,
    SWC_IPC_RESTORE_APP ,
	SWC_IPC_RESTORE_WISDOMCRUISE ,
}SWC_IPC_RestoreTypeList;

/**********************************************************************************************************
* IPC Application Object Structure Definenation                                                           *
**********************************************************************************************************/

typedef struct
{
	/*Nvm*/
	SWC_IPC_AppConfigNvmBlock AppNvm;
	uint8 NvmBlockSize;
	boolean NvmUpdateSwitch;

	/*Engineer info*/
    uint8 PartNumber[13];
	uint8 MCUVersionNumber[4];
	uint8 ProjectCode[1];
    uint8 HWVersionNumber[15];
    uint8 ProductInfo[20];
	/* VIN Number */
	uint8 VinNumber[17];
	/* Vehicle Mode Info */
	uint8 VehicleMode[20];
	/* CANMatrix Version Info */
	uint8 CANMatrixVersion[19];

	uint16 E2ESwitchTick;
	uint16 SecOcSwitchTick;
	uint8 E2ESwitchValue;
	uint8 E2EWriteValueByEngineer;
    boolean E2ESetFlag;
	uint8 SecOcSwitchValue;
	uint8 SecOcWriteValueByEngineer;
    boolean SecOcSetFlag;

	/*Fuel And TC*/
	uint8 FuelAndTcSwitch;
	SWC_IPC_FuelTCDataUpload FuelAndTcData;
	uint16 FuelAndTcTick;

	/*Power mode*/
	uint16 PowerModeTick;
	uint8 ClusterState;
	uint8 VoltageState;
	boolean IgnOnEvent ;
	boolean IgnOffEvent ;

	/* Power state changed */
	boolean RecordFlag;
	uint8 PowerStateChangedFlag;

	/*Link test*/
	uint16 LinkTestTick;
	uint8 LinkTest;

	/*Cluster safety rolling counter*/
	uint16 ClusterSafetyRcTick;
	uint8 ClusterSafetyRc;

	/*Alive monitor*/
	uint8 AliveMonitorFlag;
	boolean AliveMonitor[SWC_IPC_ALIVE_MONITOR_TOTAL_NUMBER];
	uint16 AliveMonitorTick;

	/*Tx signal trigger*/
	boolean BootDelayTrigger ;
	boolean IgnOnTrigger ;
	boolean IgnOffTrigger ;
	boolean ComWakePhase1Trigger ;
	boolean ComWakePhase2Trigger ;

	/*Network manager*/
	uint8 ComMode ;
	uint16 BootDelayTick ;
	uint16 ComWakePhase1Tick ;
	uint16 ComWakePhase2Tick ;

	/*DTC information */
	uint8 ClearDtcSwitch;
	uint8 ClearDtcRepeatCount;
	uint16 ClearDtcTick ;
	uint16 ReadDtcTick ;
	uint16 ReadDtcGroupMask;
	uint8 DtcInfomation[400];

	/*Restore setting*/
	uint8 RestoreCanSwitch ;
	uint16 RestoreCanPhase ;
	uint16 RestoreCanTick ;
	uint8 RestoreAppSwitch ;
	uint16 RestoreAppPhase ;
	uint16 RestoreAppTick ;
	uint8 RestoreType ;
	uint8 RestoreFlag ;

	/* HUT_IP1 */
	uint8 HUT_IP1_Tick ;
	boolean HUT_IP1_Flag ;
	uint8 u8IP_CurrTheme ;
    uint16 u16IP_FuelAuxTankR ;
    uint16 u16IP_FuelMainTankR ;
    uint16 u16IP_VehSpdDisp ;
	uint8 u8IP_LagueSet ;
    uint8 u8IP_VelSpdDisp_Mile ;

	/* HUT_IP2 */
	boolean HUT_IP2_Flag ;
	uint8 u8IP_ABMWarnLmpFailrSts ;
	IP_ACCErr u8IP_ACCErr ;
	uint8 u8IP_BattChrgLmpSts ;
	uint8 u8IP_DrvSeatBeltWarnLmpFailSts ;
	uint8 u8IP_EngOilPressLowLmpSts ;
	IP_Err u8IP_Err ;
	uint8 u8IP_FuelLvlInfo ;
	uint8 u8IP_FuelLvlLowLmpSts ;
	uint8 u8IP_PassSeatBeltWarnLmpFailSts ;
	IP_VINcompr u8IP_VINcompr ;
	IP_VehSpdUnit u8IP_VehSpdUnit ;
	IP_VehTotDistanceValid u8IP_VehTotDistanceValid ;
	uint32 u32IP_VehTotDistance ;

	/* HUT_IP3 */
	uint8 HUT_IP3_Tick ;
	boolean HUT_IP3_Flag ;
	uint8 u8IP_EBDFailSts ;
	uint8 u8IP_InstFuelConsUnit ;
	uint16 u16IP_AvgFuelCons ;
	uint16 u16IP_InstFuelCons ;
	uint16 u16IP_RemainDistance ;

	/* HUT_IP3 */
	uint8 HUT34_Tick ;

    /* HUT_FD1 */
	uint8 ChairMemPosnSetResult;

	/*ACC FD2*/
	uint8 ACC_FD2_Tick ;

	uint8 DriveMode;

	uint8 u8BeanIDSwitch;
	uint16 u16BeanIDReqPhase;
	uint16 u16BeanIDReqTick;
	uint8 u8BeanIDReqtimes;
	uint8 u8BeanIDInvalidStatus;
	uint8 u8BeanID[21];

	boolean rtcError;

#if (defined SWC_IPC_PROJECT_TYPE_P05)
	uint8 u8IP_FuelAuxLvlInfoVar;
	boolean HUT_IP7_Flag;
	uint8 HUT_IP7_Tick;
#endif

#if (defined SWC_IPC_PROJECT_TYPE_P05)
	uint16 u16IP_AuxRemainDistance;
	boolean HUT_IP4_Flag;
	uint8 HUT_IP4_Tick;
#endif

    uint8 u8SysPowerMod_bk;
    uint8 u8SteerWheelHeatdSts;

	/* Restore wisdom cruise */
	uint8 RestoreWisCruSwitch ;
	uint16 RestoreWisCruPhase ;
	uint16 RestoreWisCruTick ;

	uint8 u8PowerModSigValueBK;

	VconfigKind_Allbuffers VehicleConfig;

#ifdef SWC_IPC_DEBUG
	//uint8 Button;
	//uint8 LastButton;
	uint32 Error;
#endif
}SWC_IPC_AppMsgObject;

typedef enum
{
	Enum_WHUDSwitch = 0,
    Enum_DriverDisplaySwitch = 1,
    Enum_NaviDisplaySwitch = 2,
    Enum_PhoneDisplaySwitch = 3,
    Enum_DisplayRotationLevel = 4,
    Enum_DisplayHeightLevel = 5,
    Enum_DisplayBacklightSwitch = 6,
    Enum_DisplayBacklightLevel = 7,
    Enum_DisplayTheme = 8,
    Enum_DisplayFramework = 9,
    Enum_DisplayMode = 10,
    Enum_DriveMode = 11,
}SWC_IPC_WhudNvmSetWithId;

typedef enum
{
IGN_Invalid = 0,
IGN_OFF,
IGN_ACC,
IGN_ON,
IGN_Crank,

IGN_TotalNum,
}en_IPCPowerMode_t;

typedef struct
{
	void (*PowerModeStateChangeHandle)	(SWC_IPC_AppMsgObject * Object);
}s_IPCPowerModeTbl_t;

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_IPC_NW_START_SEC_CODE
#include "SWC_IPC_NW_MemMap.h"


#define SWC_IPC_NW_STOP_SEC_CODE
#include "SWC_IPC_NW_MemMap.h"
/**********************************************************************************************************
*                                                                                                         *
**********************************************************************************************************/
#endif

/**********************************************************************************************************
**
**  Revision : 2.0
**
**  Author   : HenryChan , Cao Wenping
**
**  Date     : 2020/07/10  1.0    Original Version.    Cao Wenping
**             2020/08/06  2.0    Firmwork Update.     HenryChan
**
**********************************************************************************************************/

/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/
