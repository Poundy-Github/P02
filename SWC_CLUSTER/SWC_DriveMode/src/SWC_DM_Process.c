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
*File Name   : SWC_DM_Process.c                                                                           *
*                                                                                                         *
*Description : Driving Mode module process function source file.                                          *
*                                                                                                         *
*Author      : Li Jian                                                                                    *
*                                                                                                         *
*Platform    : MICROSAR OS                                                    						      *
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

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "stddef.h" /* NULL */
#include <string.h> /* memset */
#include "Rte_Common_Normal.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_DM_Config.h"
#include "SWC_DM_Adapt.h"
#include "SWC_DM_Interface.h"

#include "VConfig.h"
#include "CConfig_Cfg.h"

#define	SWC_DM_DEBUG_ENABLE	(0)
#define	SWC_DM_NotFuel_ENABLE (0)

#define	DM_CCONFIG_ENBALE			(1u)
#define	DM_CCONFIG_DISABLE			(0u)

//EOL Driving mode bit mask and cfg mode
#define DM_CFG_KIND_DRIVING_MODE_NONE		(0)
#define	DM_CFG_KIND_DRIVING_MODE_BITMASK	(0x0Fu)

#define DM_CFG_KIND_DRIVING_MODE_2_NONE		(0)
#define	DM_CFG_KIND_DRIVING_MODE_2_BITMASK	(0x3Fu)
#define	DM_CFG_KIND_DRIVING_MODE_2_INDEX	(0x0F)

#define DM_CFG_KIND_DRIVING_MODE_3_NONE		(0)
#define	DM_CFG_KIND_DRIVING_MODE_3_BITMASK	(0xFFu)
#define	DM_CFG_KIND_DRIVING_MODE_3_INDEX	(0x1E)

// vconfig Byte85 special code value
#define DM_FUEL_VCONFIG_ZQ354	(27)
#define	DM_FUEL_VCONFIG_ZQ357	(26)
#define	DM_FUEL_VCONFIG_ZQ361	(30)
#define	DM_FUEL_VCONFIG_ZQ368	(37)
#define	DM_FUEL_VCONFIG_ZQ370	(38)
#define	DM_FUEL_VCONFIG_ZQ372	(40)

// EOL MOTOR_POSITION CFG
#define	DM_CFG_KIND_MOTOR_POSITION_P2		(0x02)
#define	DM_CFG_KIND_MOTOR_POSITION_P2P4		(0x04)
#define	DM_CFG_KIND_MOTOR_POSITION_PS		(0x05)
#define	DM_CFG_KIND_MOTOR_POSITION_PSP4		(0x06)
#define	DM_CFG_KIND_MOTOR_POSITION_PARA_P2  (0x08)

// EOL FUEL CFG
#define	DM_CFG_KIND_FUEL_HEV				(0x03)
#define	DM_CFG_KIND_FUEL_PHEV				(0x04)
#define	DM_CFG_KIND_FUEL_EV					(0x05)

// swtich sound signal
#define DM_DRVMOD_INVAILD_VALUE (0x3Fu)
#define DM_IMCACT_INVALID_VALUE (0X03u)
#define DM_DRVMOD_NOSOUND_VALUE (0x3Eu)
#define DM_IMCACT_NOSOUND_VALUE (0X00u)
#define DM_API_vSetSwitchSignal(x, y)  DM_API_vSetDrvModSwitchSignal((x), (y))
#define DM_API_vClrSwitchSignal()      DM_API_vSetDrvModSwitchSignal(DM_DRVMOD_INVAILD_VALUE, DM_IMCACT_INVALID_VALUE)

/* Driving mode signal coding value*/
//can signal coding value: IMC_Actv
#define	DM_SIGNAL_IMCACTV_ENBALE			(0x01)
#define	DM_SIGNAL_IMCACTV_DISABLE			(0x00)

//can signal coding value: SystemOperMod
#define	DM_SIGNAL_SYSTEMOPERMOD_4L					(0x06)

//can signal coding value: DrivingModReq_ESP
#define	DM_SIGNAL_DRIVINGMODREQ_ESP_BITMASK			(0x1Fu)
#define	DM_SIGNAL_DRIVINGMODREQ_ESP_4L				(0x09)
#define	DM_SIGNAL_DRIVINGMODREQ_ESP_NORMAL_4L		(0x14)
#define	DM_SIGNAL_DRIVINGMODREQ_ESP_ROCK_4L			(0x15)
#define	DM_SIGNAL_DRIVINGMODREQ_ESP_POTHOLE_4L		(0x16)
#define	DM_SIGNAL_DRIVINGMODREQ_ESP_MUDSAND_4L		(0x17)
#define	DM_SIGNAL_DRIVINGMODREQ_ESP_MOUNTAION_4L	(0x18)
#define	DM_SIGNAL_DRIVINGMODREQ_ESP_WADE4L			(0x1E)
#define	DM_SIGNAL_DRIVINGMODREQ_ESP_INVALID_0x0		(0x00)
#define	DM_SIGNAL_DRIVINGMODREQ_ESP_INVALID_0xB		(0x0B)
#define	DM_SIGNAL_DRIVINGMODREQ_ESP_INVALID_0xF		(0x0F)
#define	DM_SIGNAL_DRIVINGMODREQ_ESP_INVALID_0x11	(0x11)
#define	DM_SIGNAL_DRIVINGMODREQ_ESP_INVALID_0x1F	(0x1F)


//can signal coding value: DrivingModDis
#define	DM_SIGNAL_DRIVINGMODDIS_BITMASK				(0x1Fu)
#define	DM_SIGNAL_DRIVINGMODDIS_STANDARD			(0x0)
#define	DM_SIGNAL_DRIVINGMODDIS_SPORT				(0x01)
#define	DM_SIGNAL_DRIVINGMODDIS_SNOW				(0x02)
#define	DM_SIGNAL_DRIVINGMODDIS_MUD					(0x03)
#define	DM_SIGNAL_DRIVINGMODDIS_SAND				(0x04)
#define	DM_SIGNAL_DRIVINGMODDIS_4L					(0x05)
#define	DM_SIGNAL_DRIVINGMODDIS_ECONOMIC			(0x06)
#define	DM_SIGNAL_DRIVINGMODDIS_UNKOWN				(0x07)
#define	DM_SIGNAL_DRIVINGMODDIS_AUTO				(0x08)
#define	DM_SIGNAL_DRIVINGMODDIS_SPORTPLUS			(0x09)
#define	DM_SIGNAL_DRIVINGMODDIS_OFFROAD				(0x0A)
#define	DM_SIGNAL_DRIVINGMODDIS_STANDARD_2H			(0x0B)
#define	DM_SIGNAL_DRIVINGMODDIS_EXPERT				(0x0C)
#define	DM_SIGNAL_DRIVINGMODDIS_STANDARD_4H			(0x0D)
#define	DM_SIGNAL_DRIVINGMODDIS_FAIL				(0x0E)
#define	DM_SIGNAL_DRIVINGMODDIS_INVALID_0x0F		(0x0F)
#define	DM_SIGNAL_DRIVINGMODDIS_SNOW_4H				(0x10)
#define	DM_SIGNAL_DRIVINGMODDIS_NORMAL_4L			(0x11)
#define	DM_SIGNAL_DRIVINGMODDIS_ROCK_4l				(0x12)
#define	DM_SIGNAL_DRIVINGMODDIS_POTHLE_4L			(0x13)
#define	DM_SIGNAL_DRIVINGMODDIS_MUDSAND_4L			(0x14)
#define	DM_SIGNAL_DRIVINGMODDIS_MOUNTAIN_4L			(0x15)
#define	DM_SIGNAL_DRIVINGMODDIS_TURBO				(0x16)
#define	DM_SIGNAL_DRIVINGMODDIS_RACE				(0x17)
#define	DM_SIGNAL_DRIVINGMODDIS_GRASSGRAVEL			(0x18)
#define	DM_SIGNAL_DRIVINGMODDIS_UNEVENNEX			(0x19)
#define	DM_SIGNAL_DRIVINGMODDIS_WADE_4H				(0x1A)
#define	DM_SIGNAL_DRIVINGMODDIS_WADE_4L				(0x1B)
#define	DM_SIGNAL_DRIVINGMODDIS_2H					(0x1C)
#define	DM_SIGNAL_DRIVINGMODDIS_4H					(0x1D)
#define	DM_SIGNAL_DRIVINGMODDIS_INVALID_0x1E		(0x1E)
#define	DM_SIGNAL_DRIVINGMODDIS_INVALID_0x1F		(0x1F)

//can signal coding value: HCU_DrvMod
#define	DM_SIGNAL_HCUDRVMOD_BITMASK					(0x0Fu)
#define	DM_SIGNAL_HCUDRVMOD_INVALID_0x0A			(0x0A)
#define	DM_SIGNAL_HCUDRVMOD_INVALID_0x0B			(0x0B)
#define	DM_SIGNAL_HCUDRVMOD_INVALID_0x0C			(0x0C)
#define	DM_SIGNAL_HCUDRVMOD_INVALID_0x0D			(0x0D)
#define	DM_SIGNAL_HCUDRVMOD_INVALID_0x0E			(0x0E)
#define	DM_SIGNAL_HCUDRVMOD_INVALID_0x0F			(0x0F)

//can signal coding value: HCU_OperationMod
#define	DM_SIGNAL_HCUOPERMOD_BITMASK				(0x03u)
#define	DM_SIGNAL_HCUOPERMOD_INVALID_0x03			(0x03)

//can signal coding value: HCU_HybMod
#define	DM_SIGNAL_HCUHYBMOD_BITMASK					(0x03u)
#define	DM_SIGNAL_HCUHYBMOD_INVALID_0x02			(0x02)
#define	DM_SIGNAL_HCUHYBMOD_INVALID_0x03			(0x03)

//can signal coding value: HCU_DrvModDisp
#define	DM_SIGNAL_HCUDRVMODDISP_BITMASK				(0x0Fu)
#define	DM_SIGNAL_HCUDRVMODDISP_INVALID_0x08		(0x08)
#define	DM_SIGNAL_HCUDRVMODDISP_INVALID_0x0A		(0x0A)
#define	DM_SIGNAL_HCUDRVMODDISP_INVALID_0x0B		(0x0B)
#define	DM_SIGNAL_HCUDRVMODDISP_INVALID_0x0C		(0x0C)
#define	DM_SIGNAL_HCUDRVMODDISP_INVALID_0x0D		(0x0D)
#define	DM_SIGNAL_HCUDRVMODDISP_INVALID_0x0E		(0x0E)
#define	DM_SIGNAL_HCUDRVMODDISP_INVALID_0x0F		(0x0F)

//can signal coding value: VCU_DrvMod
#define	DM_SIGNAL_VCUDRVMOD_BITMASK					(0x07u)
#define	DM_SIGNAL_VCUDRVMOD_INVALID_0x03			(0x03)
#define	DM_SIGNAL_VCUDRVMOD_INVALID_0x06			(0x06)
#define	DM_SIGNAL_VCUDRVMOD_INVALID_0x07			(0x07)

/*Tips: Due to the change of historical demand, the current four driving modes prefer logical strategy rather
* than associated with vehicle type, fuel and PHEV/HEV; Therefore, the driving mode is the main mode, supplemented
* by the hybrid mode, and the logical process is re planned.
*/

// drive mode type
typedef enum
{
	DM_DRVMOD_NONE = 0,
	DM_DRVMOD_FUEL,
	DM_DRVMOD_HEV_PHEV_PS,
	DM_DRVMOD_PHEV_P2_P2P4,
	DM_DRVMOD_EV,
}FDM_enDrvModType;

// hybrid mode type
typedef enum
{
	DM_HYBMOD_NONE = 0,
	DM_HYBMOD_PHEV_PARAP2,
	DM_HYBMOD_PHEV_PS_PSP4,
}FDM_enHybModType;

// timer ctrl
typedef enum
{
	DM_TIMER_AUTO_SET = 0,
	DM_TIMER_4L_SET,
	DM_TIMER_XMOD_SET,
	DM_TIMER_ALL_CLR,
}FDM_enTimerCtrl;

// warning status clr
typedef enum
{
	DM_FIX_XMODE_CLR = 0,
	DM_FIX_SWMODE_CLR,
	DM_FIX_SEL_SWMODE_CLR,
}FDM_enFixModClr;

typedef enum
{
	BEFOR_LOGIC_PROCESS = 0,
	AFTER_LOGIC_PROCESS,
}FDM_enSignalProcessStage;

typedef struct
{
	uint8 currentValue;
	uint8 previosValue;
	boolean status;
}FDM_tstSignalAttributes;

// var used for fuel logic select
typedef struct
{
	uint8 u8DriveModeType;
	uint8 u8HybModeType;

	uint8 u8FuelDrvModCaseIndex;
	uint8 u8FuelDrvModNumber;

	/*Fuel signal*/
	FDM_tstSignalAttributes strDrivingModDis;
	FDM_tstSignalAttributes strDrivingModReq_ESP;
	FDM_tstSignalAttributes strIMC_Actv;
	FDM_tstSignalAttributes strSystemOperMod;

	/*HEV+PS/PS_P4, PHEV+PS/PS_P4 signal*/
	FDM_tstSignalAttributes strHCU_DrvMod;
	/*PHEV+PS/PS_P4 signal*/
	FDM_tstSignalAttributes strHCU_HybMod;

	/*PHEV+P2/P2_P4 signal*/
	FDM_tstSignalAttributes strHCU_DrvModDisp;
	/*PHEV+PARA_P2 signal*/
	FDM_tstSignalAttributes strHCU_OperationMod;    //tips: R14 HCU_OperationMod signal changes to HCU_HybMod

	/*EV vehicle signal*/
	FDM_tstSignalAttributes strVCU_DrvMod;
}FDM_tstProcessObject;

#define Common_Normal_START_SEC_CONST_UNSPECIFIED
#include  "Common_Normal_MemMap.h"

//FUEL and FUEL CASE4
static const DM_FUEL_enLogicCase u8DMCfg2LogicCaseIndexTable[DM_FUEL_EOL_CFG_MODE_MAXNUM] = DM_FUEL_EOL_CFG_DRVINGMODE2LOGIC;

static const DM_CFG_enTelltaleId u8DisSignal2TelltaleIconTable[DM_SIGNAL_DRIVINGMODDIS_BITMASK+1] = DM_SIGNAL_DIS_2_TT_ICON;

static const DM_CFG_enDrvModId u8DisSignal2WarningTable_DMMode[DM_SIGNAL_DRIVINGMODDIS_BITMASK+1] = DM_SIGNAL_DIS_2_WN_DMMODE;

static const DM_CFG_enDrvModId u8EspSignal2WarningTable_DMSelect[DM_SIGNAL_DRIVINGMODREQ_ESP_BITMASK+1] = DM_SIGNAL_ESP_2_WN_DMSELECT;

static const DM_CFG_enDrvModId u8EspSignal2WarningTable_DMSwitch[DM_SIGNAL_DRIVINGMODREQ_ESP_BITMASK+1] = DM_SIGNAL_ESP_2_WN_DMSWITCH;

static const uint8 u8SignalSwitch_EspReq_Match_Dis[DM_SIGNAL_DRIVINGMODREQ_ESP_BITMASK+1] = DM_SIGNAL_ESP_2_WN_DMSWITCH_TOMODE;


static const DM_Fuel_tstMod2Scr tstFuelMod2Scr = DM_FUEL_DMMODE_2_WN_SCREEN;

//FUEL CASE4
static const DM_Fuel4_tstMod2Scr tstFuel4Mod2Scr = DM_FUEL4_DMMODE_2_WN_SCREEN;


//HEV+PS/PS_P4, PHEV+PS/PS_P4
static const DM_CFG_enTelltaleId u8HcuSignal2TelltaleIconTable[DM_SIGNAL_HCUDRVMOD_BITMASK+1] = DM_SIGNAL_HCU_2_TT_ICON;

static const DM_CFG_enDrvModId u8HcuSignal2WarningTable_DMStart[DM_SIGNAL_HCUDRVMOD_BITMASK+1] = DM_SIGNAL_HCU_2_WN_DMSTART;

static const DM_HEV_tstMod2Scr tstHEVDMStart = DM_DHT_DMSTART_2_WN_SCREEN;

//PHEV+P2/P2_P4
static const DM_CFG_enTelltaleId u8HcuDisp2TelltaleIconTable[DM_SIGNAL_HCUDRVMODDISP_BITMASK+1] = DM_SIGNAL_HCUDISP_2_TT_ICON;

static const DM_CFG_enDrvModId u8HcuDisp2WarningTable_DMStart[DM_SIGNAL_HCUDRVMODDISP_BITMASK+1] = DM_SIGNAL_HCUDISP_2_WN_DMSTART;

static const DM_PHEV_tstMod2Scr tstPHEVDMStart = DM_PHEV_DMSTART_2_WN_SCREEN;

//EV EV+one pedal
static const DM_CFG_enTelltaleId u8VcuDrvMod2TelltaleIconTable[DM_SIGNAL_VCUDRVMOD_BITMASK+1] = DM_SIGNAL_VCUDRVMOD_2_TT_ICON;

static const DM_CFG_enDrvModId u8VcuDrvMod2WarningTable_DMStart[DM_SIGNAL_VCUDRVMOD_BITMASK+1] = DM_SIGNAL_VCUDRVMOD_2_WN_START;

static const DM_EV_tstMod2Scr tstEVDMStart = DM_EV_DRVMOD_2_WN_SCREEN;

//PHEV+PP2 hybrid Mode
static const DM_HMCFG_enTelltaleId u8HcuOperSig2TtIconTabPP2[DM_SIGNAL_HCUOPERMOD_BITMASK+1] = DM_SIGNAL_HCUOPER_2_TT_ICONPP2;

//PEHV+PS/PS_P4 hybrid Mode
static const DM_HMCFG_enTelltaleId u8HcuHybSig2TtIconTabPS[DM_SIGNAL_HCUHYBMOD_BITMASK+1] = DM_SIGNAL_HCUHYB_2_TT_ICONPS;


#define Common_Normal_STOP_SEC_CONST_UNSPECIFIED
#include  "Common_Normal_MemMap.h"


#define Common_Normal_START_SEC_VAR_NOINIT_UNSPECIFIED
#include  "Common_Normal_MemMap.h"

// var for signal value and status
static FDM_tstProcessObject stSignalObject;

static FDM_tstDM_SecondaryTriggerTmrCnt stDM_SecondaryTriggerTmrCnt;

static uint8 u8SecondaryTriggerIMCStepflag = 0;
static uint8 u8SecondaryTrigger4LStepflag = 0;
static uint8 u8SecondaryTriggerXXStepflag = 0;

#define Common_Normal_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include  "Common_Normal_MemMap.h"


#define Common_Normal_START_SEC_CODE
#include  "Common_Normal_MemMap.h"

static boolean FDM_Fuel_GetDrvModType(FDM_tstProcessObject *pstProcessObject);
static boolean FDM_NotFuel_GetDrvModType(FDM_tstProcessObject *pstProcessObject, FDM_enDrvModType enDrvModcase);
static boolean FDM_PHEVPP2_GetHybModType(FDM_tstProcessObject *pstProcessObject);
static boolean FDM_PHEVPS_GetHybModType(FDM_tstProcessObject *pstProcessObject);

static void FDM_Fuel_SignalProcess(FDM_enSignalProcessStage stage, FDM_tstProcessObject *pstProcessObject);
static void FDM_HEVPHEVPS_SignalProcess(FDM_enSignalProcessStage stage, FDM_tstProcessObject *pstProcessObject);
static void FDM_PHEVP2P4_SignalProcess(FDM_enSignalProcessStage stage, FDM_tstProcessObject *pstProcessObject);
static void FDM_EV_SignalProcess(FDM_enSignalProcessStage stage, FDM_tstProcessObject *pstProcessObject);

// drive mode
static void FDM_Fuel_TelltaleDrvModControl(const FDM_tstProcessObject *pstProcessObject);
static void FDM_Fuel_WarningDrvModControl(const FDM_tstProcessObject *pstProcessObject);
static void FDM_HEVPHEVPS_TelltaleDrvModControl(const FDM_tstProcessObject *pstProcessObject);
static void FDM_HEVPHEVPS_WarningDrvModControl(const FDM_tstProcessObject *pstProcessObject);
static void FDM_PHEVP2P4_TelltaleDrvModControl(const FDM_tstProcessObject *pstProcessObject);
static void FDM_PHEVP2P4_WarningDrvModControl(const FDM_tstProcessObject *pstProcessObject);
static void FDM_EV_TelltaleDrvModControl(const FDM_tstProcessObject *pstProcessObject);
static void FDM_EV_WarningDrvModControl(const FDM_tstProcessObject *pstProcessObject);

//fuel drive mode warning: (1) 4L+IMC：case 1,2; 4L: case3,5 (2) case4
static void FDM_Fuel_FirstDisplayProcess_Step1(const FDM_tstProcessObject* pstProcessObject);
static void FDM_Fuel_FirstDisplayProcess_Step2(const FDM_tstProcessObject* pstProcessObject);
static void FDM_Fuel_SecondaryTriggerIMCProcess(const FDM_tstProcessObject* pstProcessObject);
static void FDM_Fuel_SecondaryTrigger4LProcess(const FDM_tstProcessObject* pstProcessObject);
static void FDM_Fuel_SecondaryTriggerXXProcess(const FDM_tstProcessObject* pstProcessObject);
static void FDM_Fuel_Case4WarningDispalyProcess(const FDM_tstProcessObject* pstProcessObject);

static void FDM_Fuel_SecondTrigTimerSet(FDM_enTimerCtrl enTimerSetId);
static void FDM_FixedWarningStatusClr(FDM_enFixModClr enModeClrCase);
static boolean FDM_SetWarningStatus_F1(DM_CFG_enWarningId setWarningId, DM_CFG_enWarningId incompatibleIdStart, DM_CFG_enWarningId incompatibleIdIdEnd);
static void FDM_SetWarningStatus_Arbitration(const FDM_tstProcessObject* pstProcessObject, DM_CFG_enDrvModId enDrvModWarningID);

static void FDM_PHEVPP2_HybModSignalProcess(FDM_enSignalProcessStage stage, FDM_tstProcessObject *pstProcessObject);
static void FDM_PHEVPSP4_HybOperSignalProcess(FDM_enSignalProcessStage stage, FDM_tstProcessObject *pstProcessObject);

// hybrid Mode
static void FDM_PHEVPP2_HybModTelltaleControl(const FDM_tstProcessObject *pstProcessObject);
static void FDM_PHEVPSP4_HybModTelltaleControl(const FDM_tstProcessObject *pstProcessObject);

/**********************************************************************************************************
*Function: FDM_Fuel_GetDrvModType
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: ZJ
*
*Date: 2021-08-13
*
**********************************************************************************************************/
static boolean FDM_Fuel_GetDrvModType(FDM_tstProcessObject *pstProcessObject)
{
	uint8 u8DrvMod_Config_Byte25 = 0;
	uint8 u8DrvMod_Config_Byte52 = 0;
	uint8 u8DrvMod_Config_Byte85 = 0;
	uint8 u8FuelDrvModId = 0;
	boolean ret = FALSE;
	boolean bVCfgEnable = FALSE;
	boolean bModeCheckRet =FALSE;

	u8DrvMod_Config_Byte25 = DM_Adapt_GetVconfig(VCONFIG_KIND_DRIVING_MODE_OPTIONAL);
	u8DrvMod_Config_Byte52 = DM_Adapt_GetVconfig(VCONFIG_KIND_DRIVING_MODE_2);
	u8DrvMod_Config_Byte85 = DM_Adapt_GetVconfig(VCONFIG_KIND_DRIVING_MODE_3);

	if ((u8DrvMod_Config_Byte25 != DM_CFG_KIND_DRIVING_MODE_NONE)
		&& (DM_CFG_KIND_DRIVING_MODE_2_NONE == u8DrvMod_Config_Byte52)
		&& (DM_CFG_KIND_DRIVING_MODE_3_NONE == u8DrvMod_Config_Byte85))
	{
		u8FuelDrvModId = (uint8)(u8DrvMod_Config_Byte25 & DM_CFG_KIND_DRIVING_MODE_BITMASK);
	}
	else if ((DM_CFG_KIND_DRIVING_MODE_NONE == u8DrvMod_Config_Byte25)
		&& (DM_CFG_KIND_DRIVING_MODE_3_NONE == u8DrvMod_Config_Byte85)
		&& (u8DrvMod_Config_Byte52 != DM_CFG_KIND_DRIVING_MODE_2_NONE))
	{
		u8FuelDrvModId = (uint8)(DM_CFG_KIND_DRIVING_MODE_2_INDEX + (u8DrvMod_Config_Byte52 & DM_CFG_KIND_DRIVING_MODE_2_BITMASK));
	}
	else if ((DM_CFG_KIND_DRIVING_MODE_NONE == u8DrvMod_Config_Byte25)
		&& (DM_CFG_KIND_DRIVING_MODE_2_NONE == u8DrvMod_Config_Byte52)
		&& (u8DrvMod_Config_Byte85 != DM_CFG_KIND_DRIVING_MODE_3_NONE))
	{
		u8DrvMod_Config_Byte85 = (uint8)(u8DrvMod_Config_Byte85 & DM_CFG_KIND_DRIVING_MODE_3_BITMASK);

		// Byte85 code value -> Drving Mode
		if (DM_FUEL_VCONFIG_ZQ354 == u8DrvMod_Config_Byte85)
		{
			u8FuelDrvModId = 54;
		}
		else if ((DM_FUEL_VCONFIG_ZQ357 == u8DrvMod_Config_Byte85) || (u8DrvMod_Config_Byte85 >= DM_FUEL_VCONFIG_ZQ361) && \
			(u8DrvMod_Config_Byte85 <= DM_FUEL_VCONFIG_ZQ368))
		{
			u8FuelDrvModId = (uint8)(DM_CFG_KIND_DRIVING_MODE_3_INDEX + u8DrvMod_Config_Byte85 + 1u);
		}
		else if ((DM_FUEL_VCONFIG_ZQ370 == u8DrvMod_Config_Byte85) || (DM_FUEL_VCONFIG_ZQ372 == u8DrvMod_Config_Byte85))
		{
			u8FuelDrvModId = (uint8)(DM_CFG_KIND_DRIVING_MODE_3_INDEX + u8DrvMod_Config_Byte85 + 2u);
		}
		else
		{
			u8FuelDrvModId = (uint8)(DM_CFG_KIND_DRIVING_MODE_3_INDEX + u8DrvMod_Config_Byte85);
		}
	}
	else
	{
		u8FuelDrvModId = DM_FUEL_EOL_CFG_NO_DRVINGMODE;
	}

	if ((u8FuelDrvModId != DM_FUEL_EOL_CFG_NO_DRVINGMODE) && (u8FuelDrvModId <= DM_FUEL_EOL_CFG_MODE_MAXNUM))
	{
		pstProcessObject->u8FuelDrvModCaseIndex = (uint8)u8DMCfg2LogicCaseIndexTable[u8FuelDrvModId-1];

		if ((pstProcessObject->u8FuelDrvModCaseIndex != DM_FUEL_LOGIC_CASE_INVALID)
			&& (pstProcessObject->u8FuelDrvModCaseIndex < DM_FUEL_LOGIC_CASE_MAXNUM))
		{
			bVCfgEnable = TRUE;
			pstProcessObject->u8DriveModeType = (uint8)DM_DRVMOD_FUEL;
		}
		else
		{
			bVCfgEnable = FALSE;
		}
	}
	else
	{
		bVCfgEnable = FALSE;
	}

	bModeCheckRet = DM_Adapt_FuelModeIdCheck(u8FuelDrvModId);
	if (bModeCheckRet)
	{
		pstProcessObject->u8FuelDrvModNumber = u8FuelDrvModId;
	}

	if ((bModeCheckRet) && (bVCfgEnable))
	{
		ret = TRUE;
		DM_API_vSetDrvModVehType(pstProcessObject->u8DriveModeType);
	}
	else
	{
		DM_API_vSetDrvModVehType((uint8)(DM_DRVMOD_NONE));
	}

	return ret;
}

/**********************************************************************************************************
*Function: FDM_NotFuel_GetDrvModType
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: ZJ
*
*Date: 2021-08-13
*
**********************************************************************************************************/
static boolean FDM_NotFuel_GetDrvModType(FDM_tstProcessObject *pstProcessObject, FDM_enDrvModType enDrvModcase)
{
	uint8 u8FuelConfigByte2 = 0;
	uint8 u8MotorConfigByte30 = 0;
	uint8 u8PHEVHEV_ENABLE = 0;
	boolean ret = FALSE;
	CconfigKind_400Bytes u8FDM_CconfigKind_400Bytes;

	u8FuelConfigByte2 = DM_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
	u8MotorConfigByte30 = DM_Adapt_GetVconfig(VCONFIG_KIND_ELECTROMOTOR_POSITION);

	if(E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(u8FDM_CconfigKind_400Bytes))
	{
		u8PHEVHEV_ENABLE = (uint8)CConfig_GetConfig(CCONFIG_KIND_FD_009_DRIVE_MODE_2WD_ENABLE, u8FDM_CconfigKind_400Bytes);
	}
	else
	{
		u8PHEVHEV_ENABLE = DM_CCONFIG_ENBALE;
	}

	switch(enDrvModcase)
	{
		case DM_DRVMOD_HEV_PHEV_PS :
			if (((DM_CFG_KIND_FUEL_HEV == u8FuelConfigByte2) || (DM_CFG_KIND_FUEL_PHEV == u8FuelConfigByte2)) \
				&& ((DM_CFG_KIND_MOTOR_POSITION_PS == u8MotorConfigByte30) || (DM_CFG_KIND_MOTOR_POSITION_PSP4 == u8MotorConfigByte30)))
			{
				if(DM_CCONFIG_ENBALE == u8PHEVHEV_ENABLE)
				{
					ret = TRUE;
					pstProcessObject->u8DriveModeType = (uint8)DM_DRVMOD_HEV_PHEV_PS;
				}
			}
			break;
		case DM_DRVMOD_PHEV_P2_P2P4 :
			if ((DM_CFG_KIND_FUEL_PHEV == u8FuelConfigByte2) && ((DM_CFG_KIND_MOTOR_POSITION_P2 == u8MotorConfigByte30) \
				|| (DM_CFG_KIND_MOTOR_POSITION_P2P4 == u8MotorConfigByte30)))
			{
				if(DM_CCONFIG_ENBALE == u8PHEVHEV_ENABLE)
				{
					ret = TRUE;
					pstProcessObject->u8DriveModeType = (uint8)DM_DRVMOD_PHEV_P2_P2P4;
				}
			}
			break;
		case DM_DRVMOD_EV :
			if (DM_CFG_KIND_FUEL_EV == u8FuelConfigByte2)
			{
				ret = TRUE;
				pstProcessObject->u8DriveModeType = (uint8)DM_DRVMOD_EV;
			}
			break;
		default :
			ret = FALSE;
			break;
	}

	if (ret == TRUE)
	{
		DM_API_vSetDrvModVehType(pstProcessObject->u8DriveModeType);
	}
	else
	{
		DM_API_vSetDrvModVehType((uint8)(DM_DRVMOD_NONE));
	}

	return ret;
}

/**********************************************************************************************************
*Function: FDM_PHEVPP2_GetHybModType
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: ZJ
*
*Date: 2021-08-13
*
**********************************************************************************************************/
static boolean FDM_PHEVPP2_GetHybModType(FDM_tstProcessObject *pstProcessObject)
{
	uint8 u8FuelConfigByte2 = 0;
	uint8 u8MotorConfigByte30 = 0;
	boolean ret = FALSE;

	u8FuelConfigByte2 = DM_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
	u8MotorConfigByte30 = DM_Adapt_GetVconfig(VCONFIG_KIND_ELECTROMOTOR_POSITION);

	if ((DM_CFG_KIND_FUEL_PHEV == u8FuelConfigByte2) \
		&& (DM_CFG_KIND_MOTOR_POSITION_PARA_P2 == u8MotorConfigByte30))
	{
		ret = TRUE;
		pstProcessObject->u8HybModeType = (uint8)DM_HYBMOD_PHEV_PARAP2;
	}

	return ret;
}

/**********************************************************************************************************
*Function: FDM_PHEVPS_GetHybModType
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: ZJ
*
*Date: 2021-08-13
*
**********************************************************************************************************/
static boolean FDM_PHEVPS_GetHybModType(FDM_tstProcessObject *pstProcessObject)
{
	uint8 u8FuelConfigByte2 = 0;
	uint8 u8MotorConfigByte30 = 0;
	boolean ret = FALSE;

	u8FuelConfigByte2 = DM_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
	u8MotorConfigByte30 = DM_Adapt_GetVconfig(VCONFIG_KIND_ELECTROMOTOR_POSITION);

	if ((DM_CFG_KIND_FUEL_PHEV == u8FuelConfigByte2) && ((DM_CFG_KIND_MOTOR_POSITION_PS == u8MotorConfigByte30) \
		|| (DM_CFG_KIND_MOTOR_POSITION_PSP4 == u8MotorConfigByte30)))
	{
		ret = TRUE;
		pstProcessObject->u8HybModeType = (uint8)DM_HYBMOD_PHEV_PS_PSP4;
	}

	return ret;
}

/**********************************************************************************************************
*Function: FDM_Fuel_SignalProcess
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
static void FDM_Fuel_SignalProcess(FDM_enSignalProcessStage stage, FDM_tstProcessObject *pstProcessObject)
{
	uint8 u8ESP2Received = RTE_E_INVALID;
	uint8 u8ESP_FD2Received = RTE_E_INVALID;
	uint8 u8TOD1Received = RTE_E_INVALID;
	uint8 u8DrivingModDis = 0;
	uint8 u8DrivingModReq_ESP = 0;
	uint8 u8IMC_Actv = 0;
	uint8 u8SystemOperMod = 0;
	uint8 u8CaseIndex = pstProcessObject->u8FuelDrvModCaseIndex;

	uint8 u8ESPSigChangeFlag = 0;
	uint8 u8IMCSigChangeFlag = 0;
	uint8 u8TODSigChangeFlag = 0;

	switch (stage)
	{
		case BEFOR_LOGIC_PROCESS:

			u8ESP2Received = DM_Adapt_GetMessage_DrivingMod(&u8DrivingModDis,&u8DrivingModReq_ESP);
			u8ESP_FD2Received = DM_Adapt_GetMessage_IMC_Actv(&u8IMC_Actv);
			u8TOD1Received = DM_Adapt_GetMessage_SystemOperMod(&u8SystemOperMod);

			if (RTE_E_OK == u8ESP2Received)
			{
				pstProcessObject->strDrivingModDis.currentValue = u8DrivingModDis;
				pstProcessObject->strDrivingModReq_ESP.currentValue = u8DrivingModReq_ESP;

				if (pstProcessObject->strDrivingModDis.previosValue != pstProcessObject->strDrivingModDis.currentValue)
				{
					u8ESPSigChangeFlag = 1;
				}

				if (pstProcessObject->strDrivingModReq_ESP.previosValue != pstProcessObject->strDrivingModReq_ESP.currentValue)
				{
					u8ESPSigChangeFlag = 1;
				}

				// recover from missing status
				if ((FALSE == pstProcessObject->strDrivingModReq_ESP.status) || (FALSE == pstProcessObject->strDrivingModDis.status))
				{
					pstProcessObject->strDrivingModDis.previosValue  = pstProcessObject->strDrivingModDis.currentValue;
					pstProcessObject->strDrivingModReq_ESP.previosValue  = pstProcessObject->strDrivingModReq_ESP.currentValue;
				}
				else
				{
					// do nothing
				}

				pstProcessObject->strDrivingModDis.status = TRUE;
				pstProcessObject->strDrivingModReq_ESP.status = TRUE;
			}
			else
			{
				pstProcessObject->strDrivingModDis.currentValue = pstProcessObject->strDrivingModDis.previosValue;
				pstProcessObject->strDrivingModReq_ESP.currentValue = pstProcessObject->strDrivingModReq_ESP.previosValue;

				// signal missing flag
				pstProcessObject->strDrivingModDis.status = FALSE;
				pstProcessObject->strDrivingModReq_ESP.status = FALSE;
			}


			if (RTE_E_OK != u8TOD1Received)
			{
				pstProcessObject->strSystemOperMod.currentValue = DM_SIGNAL_IMCACTV_ENBALE;
				pstProcessObject->strSystemOperMod.status = FALSE;
			}
			else
			{
				pstProcessObject->strSystemOperMod.currentValue = u8SystemOperMod;

				if (pstProcessObject->strSystemOperMod.previosValue != pstProcessObject->strSystemOperMod.currentValue)
				{
					u8TODSigChangeFlag = 1;
				}

				if (FALSE == pstProcessObject->strSystemOperMod.status)
				{
					pstProcessObject->strSystemOperMod.previosValue = pstProcessObject->strSystemOperMod.currentValue;
				}
				else
				{
					// do nothing
				}

				pstProcessObject->strSystemOperMod.status = TRUE;
			}

			if (RTE_E_OK != u8ESP_FD2Received)
			{
				pstProcessObject->strIMC_Actv.currentValue = pstProcessObject->strIMC_Actv.previosValue;
				pstProcessObject->strIMC_Actv.status = FALSE;
			}
			else
			{
				pstProcessObject->strIMC_Actv.currentValue = u8IMC_Actv;

				if (pstProcessObject->strIMC_Actv.previosValue != pstProcessObject->strIMC_Actv.currentValue)
				{
					u8IMCSigChangeFlag = 1;
				}

				if (FALSE == pstProcessObject->strIMC_Actv.status)
				{
					pstProcessObject->strIMC_Actv.previosValue = pstProcessObject->strIMC_Actv.currentValue;
				}
				else
				{
					// do nothing
				}

				pstProcessObject->strIMC_Actv.status = TRUE;
			}

			if ((TRUE == SWC_DM_LOGOUT_ENBLE) && ((0 != u8ESPSigChangeFlag) \
				|| (0 != u8TODSigChangeFlag) || (0 != u8IMCSigChangeFlag)))
			{
				SWC_DM_PRINT_WARN("DM: DIS = %d, ESP = %d, IMC = %d, TOD1 = %d",\
					pstProcessObject->strDrivingModDis.currentValue,\
					pstProcessObject->strDrivingModReq_ESP.currentValue,\
					pstProcessObject->strIMC_Actv.currentValue,\
					pstProcessObject->strSystemOperMod.currentValue);
			}

			break;
		case AFTER_LOGIC_PROCESS:

			pstProcessObject->strDrivingModDis.previosValue = pstProcessObject->strDrivingModDis.currentValue;
			pstProcessObject->strDrivingModReq_ESP.previosValue = pstProcessObject->strDrivingModReq_ESP.currentValue;
			pstProcessObject->strSystemOperMod.previosValue = pstProcessObject->strSystemOperMod.currentValue;
			pstProcessObject->strIMC_Actv.previosValue = pstProcessObject->strIMC_Actv.currentValue;

			// signal timeout
			if (FALSE != pstProcessObject->strDrivingModReq_ESP.status)
			{
				u8DrivingModReq_ESP = pstProcessObject->strDrivingModReq_ESP.currentValue;
			}
			else
			{
				u8DrivingModReq_ESP = DM_DRVMOD_NOSOUND_VALUE;
			}

			if (FALSE != pstProcessObject->strIMC_Actv.status)
			{
				u8IMC_Actv = pstProcessObject->strIMC_Actv.currentValue;
			}
			else
			{
				u8IMC_Actv = DM_IMCACT_NOSOUND_VALUE;
			}

			if ((DM_FUEL_LOGIC_CASE1 == u8CaseIndex) || (DM_FUEL_LOGIC_CASE2 == u8CaseIndex))
			{
				DM_API_vSetSwitchSignal(u8DrivingModReq_ESP, u8IMC_Actv);
			}
			else
			{
				DM_API_vSetSwitchSignal(u8DrivingModReq_ESP, DM_SIGNAL_IMCACTV_DISABLE);
			}

			break;
		default:
			// do nothing
			break;
	}

}

/**********************************************************************************************************
*Function: FDM_Fuel_SecondTrigTimerSet
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author:
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
static void FDM_Fuel_SecondTrigTimerSet(FDM_enTimerCtrl enTimerSetId)
{
	uint8 u8TimerSet = (uint8)enTimerSetId;
	switch(u8TimerSet)
	{
		case (uint8)DM_TIMER_AUTO_SET :
			stDM_SecondaryTriggerTmrCnt.u16SecondaryTriggerAutoModeTmr = TIME_25_SEC;
			stDM_SecondaryTriggerTmrCnt.u16SecondaryTrigger4LModeTmr = 0u;
			stDM_SecondaryTriggerTmrCnt.u16SecondaryTriggerXXModeTmr = 0u;
			break;
		case (uint8)DM_TIMER_4L_SET :
			stDM_SecondaryTriggerTmrCnt.u16SecondaryTriggerAutoModeTmr = 0u;
			stDM_SecondaryTriggerTmrCnt.u16SecondaryTrigger4LModeTmr = TIME_25_SEC;
			stDM_SecondaryTriggerTmrCnt.u16SecondaryTriggerXXModeTmr = 0u;
			break;
		case (uint8)DM_TIMER_XMOD_SET :
			stDM_SecondaryTriggerTmrCnt.u16SecondaryTriggerAutoModeTmr = 0u;
			stDM_SecondaryTriggerTmrCnt.u16SecondaryTrigger4LModeTmr = 0u;
			stDM_SecondaryTriggerTmrCnt.u16SecondaryTriggerXXModeTmr = TIME_25_SEC;
			break;
		case (uint8)DM_TIMER_ALL_CLR:
			stDM_SecondaryTriggerTmrCnt.u16SecondaryTriggerAutoModeTmr = 0u;
			stDM_SecondaryTriggerTmrCnt.u16SecondaryTrigger4LModeTmr = 0u;
			stDM_SecondaryTriggerTmrCnt.u16SecondaryTriggerXXModeTmr = 0u;
			break;
		default:
			// do nothing
			break;
	}
}

/**********************************************************************************************************
*Function: FDM_Fuel_SecondTrigTimerCount
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author:
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
void FDM_Fuel_SecondTrigTimerCount(void)
{
	if(stDM_SecondaryTriggerTmrCnt.u16SecondaryTriggerAutoModeTmr > 0)
	{
		stDM_SecondaryTriggerTmrCnt.u16SecondaryTriggerAutoModeTmr--;
	}

	if(stDM_SecondaryTriggerTmrCnt.u16SecondaryTrigger4LModeTmr > 0)
	{
		stDM_SecondaryTriggerTmrCnt.u16SecondaryTrigger4LModeTmr--;
	}

	if(stDM_SecondaryTriggerTmrCnt.u16SecondaryTriggerXXModeTmr > 0)
	{
		stDM_SecondaryTriggerTmrCnt.u16SecondaryTriggerXXModeTmr--;
	}

	return;
}

/**********************************************************************************************************
*Function: FDM_FixedWarningStatusClr
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: ZJ
*
*Date: 2021-08-13
*
**********************************************************************************************************/
static void FDM_FixedWarningStatusClr(FDM_enFixModClr enModeClrCase)
{
	uint8 u8ModeId;
	uint8 u8ModeClrStart = 0;
	uint8 u8ModeClrEnd = 0;
	uint8 u8ModeClrCase = (uint8)enModeClrCase;

	switch(u8ModeClrCase)
	{
		case (uint8)DM_FIX_XMODE_CLR :
			u8ModeClrStart = (uint8)DM_FUEL4_SCR_MODE_START;
			u8ModeClrEnd = (uint8)DM_FUEL_SCR_MODE_END;
			break;
		case (uint8)DM_FIX_SWMODE_CLR :
			u8ModeClrStart = (uint8)DM_FUEL_SCR_MODE_SWITCH_START;
			u8ModeClrEnd = (uint8)DM_FUEL_SCR_MODE_SWITCH_END;
			break;
		case (uint8)DM_FIX_SEL_SWMODE_CLR :
			u8ModeClrStart = (uint8)DM_FUEL_SCR_MODE_SELECT_START;
			u8ModeClrEnd = (uint8)DM_FUEL_SCR_MODE_SWITCH_END;
			break;
		default :
			// do nothing
			break;
	}

	if ((u8ModeClrStart == u8ModeClrEnd) && (0 == u8ModeClrEnd))
	{
		return;
	}

	for(u8ModeId = u8ModeClrStart; u8ModeId <= u8ModeClrEnd; u8ModeId++)
	{
		(void)DM_API_vClrDrvModWarningStatus(u8ModeId);
	}

	return;
}

/**********************************************************************************************************
*Function: FDM_Fuel_SecondaryTriggerIMCProcess
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author:
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
static void FDM_Fuel_SecondaryTriggerIMCProcess(const FDM_tstProcessObject* pstProcessObject)
{
	const FDM_tstSignalAttributes *pstSignal_IMC_Actv = &(pstProcessObject->strIMC_Actv);
	const FDM_tstSignalAttributes *pstSignal_DrivingModDis = &(pstProcessObject->strDrivingModDis);

	if((stDM_SecondaryTriggerTmrCnt.u16SecondaryTriggerAutoModeTmr <= TIME_22_SEC)\
		&&(0 != stDM_SecondaryTriggerTmrCnt.u16SecondaryTriggerAutoModeTmr))
	{
		if((DM_SIGNAL_IMCACTV_ENBALE == pstSignal_IMC_Actv->currentValue)\
		&& (DM_SIGNAL_DRIVINGMODDIS_AUTO == pstSignal_DrivingModDis->currentValue))
		{
			if(u8SecondaryTriggerIMCStepflag < 2)
			{
				u8SecondaryTriggerIMCStepflag++; // 40ms
				FDM_FixedWarningStatusClr(DM_FIX_XMODE_CLR);
			}
			else
			{
				u8SecondaryTriggerIMCStepflag = 0;

				FDM_FixedWarningStatusClr(DM_FIX_SWMODE_CLR);
				FDM_SetWarningStatus_Arbitration(pstProcessObject, enDM_IMCMode);
				FDM_Fuel_SecondTrigTimerSet(DM_TIMER_ALL_CLR);
			}
		}
	}

	return ;
}

/**********************************************************************************************************
*Function: FDM_Fuel_SecondaryTrigger4LProcess
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author:
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
static void FDM_Fuel_SecondaryTrigger4LProcess(const FDM_tstProcessObject* pstProcessObject)
{
	const FDM_tstSignalAttributes *pstSignal_DrivingModReq_ESP = &(pstProcessObject->strDrivingModReq_ESP);
	const FDM_tstSignalAttributes *pstSignal_DrivingModDis = &(pstProcessObject->strDrivingModDis);

	uint8 u8WarningStatusId = 0;
	DM_CFG_enDrvModId enWarningStatusId = enDM_WarningInvaildId;

	if((stDM_SecondaryTriggerTmrCnt.u16SecondaryTrigger4LModeTmr <= TIME_22_SEC)\
		&&(0 != stDM_SecondaryTriggerTmrCnt.u16SecondaryTrigger4LModeTmr))
	{
		u8WarningStatusId = u8SignalSwitch_EspReq_Match_Dis[pstSignal_DrivingModReq_ESP->currentValue & DM_SIGNAL_DRIVINGMODREQ_ESP_BITMASK];
		if(u8WarningStatusId == pstSignal_DrivingModDis->currentValue)
		{
			if(u8SecondaryTrigger4LStepflag < 2)
			{
				u8SecondaryTrigger4LStepflag++;
				FDM_FixedWarningStatusClr(DM_FIX_XMODE_CLR);
			}
			else
			{
				u8SecondaryTrigger4LStepflag = 0;
				enWarningStatusId = u8DisSignal2WarningTable_DMMode[pstSignal_DrivingModDis->currentValue & DM_SIGNAL_DRIVINGMODDIS_BITMASK];

				FDM_FixedWarningStatusClr(DM_FIX_SWMODE_CLR);
				FDM_SetWarningStatus_Arbitration(pstProcessObject, enWarningStatusId);
				FDM_Fuel_SecondTrigTimerSet(DM_TIMER_ALL_CLR);
			}
		}
	}

	return ;
}


/**********************************************************************************************************
*Function: FDM_Fuel_SecondaryTriggerXXProcess
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author:
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
static void FDM_Fuel_SecondaryTriggerXXProcess(const FDM_tstProcessObject* pstProcessObject)
{
	const FDM_tstSignalAttributes *pstSignal_DrivingModReq_ESP = &(pstProcessObject->strDrivingModReq_ESP);
	const FDM_tstSignalAttributes *pstSignal_DrivingModDis = &(pstProcessObject->strDrivingModDis);

	uint8 u8WarningStatusId = 0;
	DM_CFG_enDrvModId enWarningStatusId = enDM_WarningInvaildId;

	if((stDM_SecondaryTriggerTmrCnt.u16SecondaryTriggerXXModeTmr <= TIME_22_SEC)\
		&&(0 != stDM_SecondaryTriggerTmrCnt.u16SecondaryTriggerXXModeTmr))
	{
		u8WarningStatusId = u8SignalSwitch_EspReq_Match_Dis[pstSignal_DrivingModReq_ESP->currentValue & DM_SIGNAL_DRIVINGMODREQ_ESP_BITMASK];
		if(u8WarningStatusId == pstSignal_DrivingModDis->currentValue)
		{
			if(u8SecondaryTriggerXXStepflag < 2)
			{
				u8SecondaryTriggerXXStepflag++;
				FDM_FixedWarningStatusClr(DM_FIX_XMODE_CLR);
			}
			else
			{
				u8SecondaryTriggerXXStepflag = 0;
				enWarningStatusId = u8DisSignal2WarningTable_DMMode[pstSignal_DrivingModDis->currentValue & DM_SIGNAL_DRIVINGMODDIS_BITMASK];

				//esp = 0x3 is reserve value shouldn't triggered display again
				if((0x3 == pstSignal_DrivingModReq_ESP->currentValue) && (0x2 == pstSignal_DrivingModDis->currentValue))
				{
					//enWarningStatusId = enDM_WarningInvaildId;
				}
				else
				{
					FDM_FixedWarningStatusClr(DM_FIX_SWMODE_CLR);
					FDM_SetWarningStatus_Arbitration(pstProcessObject, enWarningStatusId);
					FDM_Fuel_SecondTrigTimerSet(DM_TIMER_ALL_CLR);
				}

			}
		}
	}

	return ;
}

/**********************************************************************************************************
*Function: FDM_Fuel_FirstDisplayProcess_Step1
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
static void FDM_Fuel_FirstDisplayProcess_Step1(const FDM_tstProcessObject* pstProcessObject)
{
	const FDM_tstSignalAttributes *pstSignal_IMC_Actv = &(pstProcessObject->strIMC_Actv);
	const FDM_tstSignalAttributes *pstSignal_SystemOperMod = &(pstProcessObject->strSystemOperMod);
	const FDM_tstSignalAttributes *pstSignal_DrivingModReq_ESP = &(pstProcessObject->strDrivingModReq_ESP);
	DM_CFG_enDrvModId enWarningStatusId = enDM_WarningInvaildId;

	if (pstSignal_IMC_Actv->currentValue != pstSignal_IMC_Actv->previosValue)
	{
		if (pstSignal_IMC_Actv->currentValue != DM_SIGNAL_IMCACTV_DISABLE)
		{
			if (pstSignal_SystemOperMod->currentValue != DM_SIGNAL_SYSTEMOPERMOD_4L)
			{
				FDM_SetWarningStatus_Arbitration(pstProcessObject, enDM_AutoSelect);
				FDM_Fuel_SecondTrigTimerSet(DM_TIMER_ALL_CLR);
			}
			else
			{
				FDM_SetWarningStatus_Arbitration(pstProcessObject, enDM_AutoSwitch);
				FDM_Fuel_SecondTrigTimerSet(DM_TIMER_AUTO_SET);
			}
		}
		else
		{
			// esp signal: valid->invalid, clear switch/select mode
			if((DM_SIGNAL_DRIVINGMODREQ_ESP_INVALID_0x0 == pstSignal_DrivingModReq_ESP->currentValue) \
				|| (DM_SIGNAL_DRIVINGMODREQ_ESP_INVALID_0xB == pstSignal_DrivingModReq_ESP->currentValue) \
				|| (DM_SIGNAL_DRIVINGMODREQ_ESP_INVALID_0xF == pstSignal_DrivingModReq_ESP->currentValue) \
				|| (DM_SIGNAL_DRIVINGMODREQ_ESP_INVALID_0x11 == pstSignal_DrivingModReq_ESP->currentValue) \
				|| (DM_SIGNAL_DRIVINGMODREQ_ESP_INVALID_0x1F == pstSignal_DrivingModReq_ESP->currentValue))
			{
				FDM_FixedWarningStatusClr(DM_FIX_SEL_SWMODE_CLR);
			}

			if (DM_SIGNAL_DRIVINGMODREQ_ESP_4L == pstSignal_DrivingModReq_ESP->currentValue)
			{
				FDM_SetWarningStatus_Arbitration(pstProcessObject, enDM_4LSwitch);
				FDM_Fuel_SecondTrigTimerSet(DM_TIMER_4L_SET);
			}
			else
			{
				enWarningStatusId = u8EspSignal2WarningTable_DMSelect[pstSignal_DrivingModReq_ESP->currentValue & DM_SIGNAL_DRIVINGMODREQ_ESP_BITMASK];
				FDM_SetWarningStatus_Arbitration(pstProcessObject, enWarningStatusId);
				FDM_Fuel_SecondTrigTimerSet(DM_TIMER_ALL_CLR);
			}
		}

		FDM_Fuel_SecondaryTriggerIMCProcess(pstProcessObject);
		FDM_Fuel_SecondaryTrigger4LProcess(pstProcessObject);
	}
	else
	{
		FDM_Fuel_FirstDisplayProcess_Step2(pstProcessObject);
	}
}

/**********************************************************************************************************
*Function: FDM_Fuel_FirstDisplayProcess_Step2
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
static void FDM_Fuel_FirstDisplayProcess_Step2(const FDM_tstProcessObject* pstProcessObject)
{
	const FDM_tstSignalAttributes *pstSignal_IMC_Actv = &(pstProcessObject->strIMC_Actv);
	const FDM_tstSignalAttributes *pstSignal_SystemOperMod = &(pstProcessObject->strSystemOperMod);
	const FDM_tstSignalAttributes *pstSignal_DrivingModReq_ESP = &(pstProcessObject->strDrivingModReq_ESP);
	uint8 u8CaseIndex = pstProcessObject->u8FuelDrvModCaseIndex;
	DM_CFG_enDrvModId enWarningStatusId = enDM_WarningInvaildId;
 	uint8 u8ESPChangeFalg = 0;
	//D03 SRS16 Update
 	if ((45 == pstProcessObject->u8FuelDrvModNumber) || (46 == pstProcessObject->u8FuelDrvModNumber))
 	{
 		if((pstSignal_DrivingModReq_ESP->currentValue != pstSignal_DrivingModReq_ESP->previosValue) \
			&& (pstSignal_IMC_Actv->currentValue == DM_SIGNAL_IMCACTV_DISABLE))
 		{
 			u8ESPChangeFalg = 1;
 		}
 	}
	else
	{
		if(pstSignal_DrivingModReq_ESP->currentValue != pstSignal_DrivingModReq_ESP->previosValue)
		{
			u8ESPChangeFalg = 1;
		}
	}


	if (0 != u8ESPChangeFalg)
	{
		// esp signal: valid->invalid, clear switch/select mode
		if((DM_SIGNAL_DRIVINGMODREQ_ESP_INVALID_0x0 == pstSignal_DrivingModReq_ESP->currentValue) \
			|| (DM_SIGNAL_DRIVINGMODREQ_ESP_INVALID_0xB == pstSignal_DrivingModReq_ESP->currentValue) \
			|| (DM_SIGNAL_DRIVINGMODREQ_ESP_INVALID_0xF == pstSignal_DrivingModReq_ESP->currentValue) \
			|| (DM_SIGNAL_DRIVINGMODREQ_ESP_INVALID_0x11 == pstSignal_DrivingModReq_ESP->currentValue) \
			|| (DM_SIGNAL_DRIVINGMODREQ_ESP_INVALID_0x1F == pstSignal_DrivingModReq_ESP->currentValue))
		{
			FDM_FixedWarningStatusClr(DM_FIX_SEL_SWMODE_CLR);
		}

		if (((DM_FUEL_LOGIC_CASE1 == u8CaseIndex) || (DM_FUEL_LOGIC_CASE5 == u8CaseIndex))
			&&	((DM_SIGNAL_DRIVINGMODREQ_ESP_4L == pstSignal_DrivingModReq_ESP->currentValue)
				|| (DM_SIGNAL_DRIVINGMODREQ_ESP_NORMAL_4L == pstSignal_DrivingModReq_ESP->currentValue)
				|| (DM_SIGNAL_DRIVINGMODREQ_ESP_ROCK_4L == pstSignal_DrivingModReq_ESP->currentValue)
				|| (DM_SIGNAL_DRIVINGMODREQ_ESP_POTHOLE_4L == pstSignal_DrivingModReq_ESP->currentValue)
				|| (DM_SIGNAL_DRIVINGMODREQ_ESP_MUDSAND_4L == pstSignal_DrivingModReq_ESP->currentValue)
				|| (DM_SIGNAL_DRIVINGMODREQ_ESP_MOUNTAION_4L == pstSignal_DrivingModReq_ESP->currentValue)
				|| (DM_SIGNAL_DRIVINGMODREQ_ESP_WADE4L == pstSignal_DrivingModReq_ESP->currentValue)))
		{
			if (pstSignal_SystemOperMod->currentValue != DM_SIGNAL_SYSTEMOPERMOD_4L)
			{
				FDM_SetWarningStatus_Arbitration(pstProcessObject, enDM_4LSwitch);
				FDM_Fuel_SecondTrigTimerSet(DM_TIMER_4L_SET);
			}
			else
			{
				enWarningStatusId = u8EspSignal2WarningTable_DMSelect[pstSignal_DrivingModReq_ESP->currentValue & DM_SIGNAL_DRIVINGMODREQ_ESP_BITMASK];
				FDM_SetWarningStatus_Arbitration(pstProcessObject, enWarningStatusId);
				FDM_Fuel_SecondTrigTimerSet(DM_TIMER_ALL_CLR);
			}
		}
		else if (((DM_FUEL_LOGIC_CASE3 == u8CaseIndex) && (DM_SIGNAL_DRIVINGMODREQ_ESP_4L == pstSignal_DrivingModReq_ESP->currentValue)) \
				|| ((DM_FUEL_LOGIC_CASE2 == u8CaseIndex) && ((DM_SIGNAL_DRIVINGMODREQ_ESP_4L == pstSignal_DrivingModReq_ESP->currentValue)
				|| (DM_SIGNAL_DRIVINGMODREQ_ESP_WADE4L == pstSignal_DrivingModReq_ESP->currentValue))))
		{
			FDM_SetWarningStatus_Arbitration(pstProcessObject, enDM_4LSwitch);
			FDM_Fuel_SecondTrigTimerSet(DM_TIMER_4L_SET);
		}
		else
		{
			if (pstSignal_SystemOperMod->currentValue != DM_SIGNAL_SYSTEMOPERMOD_4L)
			{
				if ((DM_FUEL_LOGIC_CASE1 == u8CaseIndex) || (DM_FUEL_LOGIC_CASE2 == u8CaseIndex))
				{
					if (pstSignal_IMC_Actv->currentValue != DM_SIGNAL_IMCACTV_ENBALE)
					{
						enWarningStatusId = u8EspSignal2WarningTable_DMSelect[pstSignal_DrivingModReq_ESP->currentValue & DM_SIGNAL_DRIVINGMODREQ_ESP_BITMASK];
						FDM_SetWarningStatus_Arbitration(pstProcessObject, enWarningStatusId);
					}
					else
					{
						// do nothing
					}

					FDM_Fuel_SecondTrigTimerSet(DM_TIMER_ALL_CLR);
				}
				else if ((DM_FUEL_LOGIC_CASE3 == u8CaseIndex) || (DM_FUEL_LOGIC_CASE5 == u8CaseIndex))
				{
					enWarningStatusId = u8EspSignal2WarningTable_DMSelect[pstSignal_DrivingModReq_ESP->currentValue & DM_SIGNAL_DRIVINGMODREQ_ESP_BITMASK];
					FDM_SetWarningStatus_Arbitration(pstProcessObject, enWarningStatusId);
					FDM_Fuel_SecondTrigTimerSet(DM_TIMER_ALL_CLR);
				}
				else
				{
					// do nothing
				}
			}
			else
			{
				enWarningStatusId = u8EspSignal2WarningTable_DMSwitch[pstSignal_DrivingModReq_ESP->currentValue & DM_SIGNAL_DRIVINGMODREQ_ESP_BITMASK];
				FDM_SetWarningStatus_Arbitration(pstProcessObject, enWarningStatusId);
				FDM_Fuel_SecondTrigTimerSet(DM_TIMER_XMOD_SET);
			}
		}
	}
	else
	{
		// do nothing
	}

	FDM_Fuel_SecondaryTriggerIMCProcess(pstProcessObject);
	FDM_Fuel_SecondaryTrigger4LProcess(pstProcessObject);
	FDM_Fuel_SecondaryTriggerXXProcess(pstProcessObject);
}

/**********************************************************************************************************
*Function: FDM_Fuel_TelltaleDrvModControl
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: ZJ
*
*Date: 2021-08-13
*
**********************************************************************************************************/
static void FDM_Fuel_TelltaleDrvModControl(const FDM_tstProcessObject* pstProcessObject)
{
	DM_CFG_enTelltaleId enTelltaleStatusId = DM_enTT_NONE;

	if ((pstProcessObject->strDrivingModDis.status) || (pstProcessObject->strDrivingModReq_ESP.status))
	{
		enTelltaleStatusId = u8DisSignal2TelltaleIconTable[pstProcessObject->strDrivingModDis.currentValue & DM_SIGNAL_DRIVINGMODDIS_BITMASK];
		(void)DM_API_vSetDrvModTTStatus(enTelltaleStatusId);
	}
	else
	{
		DM_API_vClrDrvModTTStatus();
	}
}

/**********************************************************************************************************
*Function: FDM_Fuel_Case4WarningDispalyProcess
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
static void FDM_Fuel_Case4WarningDispalyProcess(const FDM_tstProcessObject* pstProcessObject)
{
	const FDM_tstSignalAttributes *pstSignalDrivingModDis = &(pstProcessObject->strDrivingModDis);

	DM_CFG_enDrvModId enWarningStatusId = enDM_WarningInvaildId;
	DM_CFG_enDrvModId enWarningStatusPreId = enDM_WarningInvaildId;

	if (pstSignalDrivingModDis->currentValue != pstSignalDrivingModDis->previosValue)
	{
		if ((DM_SIGNAL_DRIVINGMODDIS_FAIL == pstSignalDrivingModDis->previosValue)
			|| (DM_SIGNAL_DRIVINGMODDIS_UNKOWN == pstSignalDrivingModDis->previosValue)
			|| (DM_SIGNAL_DRIVINGMODDIS_INVALID_0x0F == pstSignalDrivingModDis->previosValue)
			|| ((pstSignalDrivingModDis->previosValue >= DM_SIGNAL_DRIVINGMODDIS_INVALID_0x1E)
				&& (pstSignalDrivingModDis->previosValue <= DM_SIGNAL_DRIVINGMODDIS_INVALID_0x1F)))
		{
			// do nothing
		}
		else if ((DM_SIGNAL_DRIVINGMODDIS_FAIL == pstSignalDrivingModDis->currentValue)
			|| (DM_SIGNAL_DRIVINGMODDIS_UNKOWN == pstSignalDrivingModDis->currentValue)
			|| (DM_SIGNAL_DRIVINGMODDIS_INVALID_0x0F == pstSignalDrivingModDis->currentValue)
			|| ((pstSignalDrivingModDis->currentValue >= DM_SIGNAL_DRIVINGMODDIS_INVALID_0x1E)
				&& (pstSignalDrivingModDis->currentValue <= DM_SIGNAL_DRIVINGMODDIS_INVALID_0x1F)))
		{
			// Clear all drving mode warning
      		DM_API_vClrAllDrvModWarningStatus();
		}
		else
		{
			enWarningStatusId = u8DisSignal2WarningTable_DMMode[pstSignalDrivingModDis->currentValue & DM_SIGNAL_DRIVINGMODDIS_BITMASK];
			enWarningStatusPreId = u8DisSignal2WarningTable_DMMode[pstSignalDrivingModDis->previosValue & DM_SIGNAL_DRIVINGMODDIS_BITMASK];
			if(enWarningStatusId != enWarningStatusPreId)
			{
				FDM_SetWarningStatus_Arbitration(pstProcessObject, enWarningStatusId);
			}
		}
	}
	else
	{
		// do nothing, wait status change
	}
}

/**********************************************************************************************************
*Function: FDM_Fuel_WarningDrvModControl
*
*Description: TBD
*
*Parameter: pstProcessObject
*
*Return: void
*
*Author: ZJ
*
*Date: 2012-08-13
*
**********************************************************************************************************/
static void FDM_Fuel_WarningDrvModControl(const FDM_tstProcessObject *pstProcessObject)
{
	uint8 u8CaseIndex = pstProcessObject->u8FuelDrvModCaseIndex;

	if ((pstProcessObject->strDrivingModDis.status) || (pstProcessObject->strDrivingModReq_ESP.status))
	{
		if ((DM_FUEL_LOGIC_CASE1 == u8CaseIndex) || (DM_FUEL_LOGIC_CASE2 == u8CaseIndex))
		{
			FDM_Fuel_FirstDisplayProcess_Step1(pstProcessObject);
		}
		else if ((DM_FUEL_LOGIC_CASE3 == u8CaseIndex) || (DM_FUEL_LOGIC_CASE5 == u8CaseIndex))
		{
			FDM_Fuel_FirstDisplayProcess_Step2(pstProcessObject);
		}
		else if (DM_FUEL_LOGIC_CASE4 == u8CaseIndex)
		{
			FDM_Fuel_Case4WarningDispalyProcess(pstProcessObject);
		}
		else
		{
			// do nothing
		}
	}
	else
	{
		// signal timeout, clear timer
		FDM_Fuel_SecondTrigTimerSet(DM_TIMER_ALL_CLR);
		DM_API_vClrAllDrvModWarningStatus();
	}
}

/**********************************************************************************************************
*Function: FDM_Fuel_IsFuelVehicle
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 2020-08-12
*
**********************************************************************************************************/

#ifdef GWM_V35_PROJECT_TYPE_B02
	#define FDM_FUEL_ENABLE  1
	#define FDM_PHEVPP2_HYBMOD_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define FDM_FUEL_ENABLE  1
	#define FDM_PHEVPP2_HYBMOD_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define FDM_FUEL_ENABLE  1
	#define FDM_PHEVPP2_HYBMOD_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define FDM_FUEL_ENABLE  1
	#define FDM_PHEVPP2_HYBMOD_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define FDM_FUEL_ENABLE  1
	#define FDM_PHEVPP2_HYBMOD_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define FDM_FUEL_ENABLE  1
	#define FDM_PHEVPP2_HYBMOD_ENABLE 1
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define FDM_FUEL_ENABLE  1
	#define FDM_PHEVPP2_HYBMOD_ENABLE 1
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define FDM_FUEL_ENABLE  1
	#define FDM_PHEVPP2_HYBMOD_ENABLE 1
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define FDM_FUEL_ENABLE  1
	#define FDM_PHEVPP2_HYBMOD_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define FDM_FUEL_ENABLE  1
	#define FDM_PHEVPP2_HYBMOD_ENABLE 0
#else
	#define FDM_FUEL_ENABLE  0
#endif

boolean FDM_Fuel_IsFuelVehicle(void)
{
	boolean ret = FALSE;
	boolean bDrvModEnable = FALSE;
	boolean bHybModEnable = FALSE;
	FDM_tstProcessObject *pstProcessObject = &stSignalObject;

	// PHEV+PP2 HybMod & Fuel DrvMod
	// Tips: The two modes coexist and are displayed independently.
	bDrvModEnable = FDM_Fuel_GetDrvModType(pstProcessObject);
	bHybModEnable = FDM_PHEVPP2_GetHybModType(pstProcessObject);
	if ((bDrvModEnable) && (1 == FDM_FUEL_ENABLE))
	{
		bDrvModEnable = TRUE;
	}

	if ((bHybModEnable) && (1 == FDM_PHEVPP2_HYBMOD_ENABLE))
	{
		bHybModEnable = TRUE;
	}

	if ((bDrvModEnable) || (bHybModEnable))
	{
		ret = TRUE;
	}

#if SWC_DM_DEBUG_ENABLE
	ret = TRUE;
	pstProcessObject->u8DriveModeType = DM_DRVMOD_FUEL;
	pstProcessObject->u8FuelDrvModCaseIndex = DM_FUEL_LOGIC_CASE4;
#endif

	return ret;
}


/**********************************************************************************************************
*Function: FDM_Fuel_DelayTimeGet
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_Fuel_DelayTimeGet(uint32* time)
{
	*time = TIME_100_MS * 30u;    // default delay 3s

	return TRUE;
}


/**********************************************************************************************************
*Function: FDM_Fuel_TransIntoNormal
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_Fuel_TransIntoNormal(void)
{
	FDM_tstProcessObject *pstProcessObject = &stSignalObject;

	(void) memset(&(pstProcessObject->strDrivingModDis), 0, sizeof(FDM_tstSignalAttributes));
	(void) memset(&(pstProcessObject->strDrivingModReq_ESP), 0, sizeof(FDM_tstSignalAttributes));
	(void) memset(&(pstProcessObject->strIMC_Actv), 0, sizeof(FDM_tstSignalAttributes));
	(void) memset(&(pstProcessObject->strSystemOperMod), 0, sizeof(FDM_tstSignalAttributes));
	(void) memset(&(pstProcessObject->strHCU_OperationMod), 0, sizeof(FDM_tstSignalAttributes));

	DM_API_vClrDrvModTTStatus();
	DM_API_vClrAllDrvModWarningStatus();
	DM_API_vClrHybridModTTStatus();
	DM_API_vClrSwitchSignal();

	return TRUE;
}


/**********************************************************************************************************
*Function: FDM_Fuel_TransExitNormal
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_Fuel_TransExitNormal(void)
{
	DM_API_vClrDrvModTTStatus();
	DM_API_vClrAllDrvModWarningStatus();
	DM_API_vClrHybridModTTStatus();
	return TRUE;
}


/**********************************************************************************************************
*Function: FDM_Fuel_FirstLogicProcess
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_Fuel_FirstLogicProcess(void)
{
	FDM_tstProcessObject *pstProcessObject = &stSignalObject;

	FDM_Fuel_SignalProcess(BEFOR_LOGIC_PROCESS, pstProcessObject);
	FDM_PHEVPP2_HybModSignalProcess(BEFOR_LOGIC_PROCESS, pstProcessObject);

	if (DM_DRVMOD_FUEL == pstProcessObject->u8DriveModeType)
	{
		FDM_Fuel_TelltaleDrvModControl(pstProcessObject);
	}

	if (DM_HYBMOD_PHEV_PARAP2 == pstProcessObject->u8HybModeType)
	{
		FDM_PHEVPP2_HybModTelltaleControl(pstProcessObject);
	}

	FDM_Fuel_SignalProcess(AFTER_LOGIC_PROCESS, pstProcessObject);
	FDM_PHEVPP2_HybModSignalProcess(AFTER_LOGIC_PROCESS, pstProcessObject);

	return TRUE;
}


/**********************************************************************************************************
*Function: FDM_Fuel_GeneralLogicProcess
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_Fuel_GeneralLogicProcess(void)
{
	FDM_tstProcessObject *pstProcessObject = &stSignalObject;

	FDM_Fuel_SignalProcess(BEFOR_LOGIC_PROCESS, pstProcessObject);
	FDM_PHEVPP2_HybModSignalProcess(BEFOR_LOGIC_PROCESS, pstProcessObject);

	if (DM_DRVMOD_FUEL == pstProcessObject->u8DriveModeType)
	{
		// aux prompt, set drive mode config id
		DM_API_vSetDrvModAuxStatus(pstProcessObject->u8FuelDrvModNumber);

		FDM_Fuel_TelltaleDrvModControl(pstProcessObject);
		FDM_Fuel_WarningDrvModControl(pstProcessObject);
	}

	if (DM_HYBMOD_PHEV_PARAP2 == pstProcessObject->u8HybModeType)
	{
		FDM_PHEVPP2_HybModTelltaleControl(pstProcessObject);
	}

	FDM_Fuel_SignalProcess(AFTER_LOGIC_PROCESS, pstProcessObject);
	FDM_PHEVPP2_HybModSignalProcess(AFTER_LOGIC_PROCESS, pstProcessObject);

	return TRUE;
}

/**********************************************************************************************************
*Function: FDM_HEVPHEVPS_SignalProcess
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
static void FDM_HEVPHEVPS_SignalProcess(FDM_enSignalProcessStage stage, FDM_tstProcessObject *pstProcessObject)
{
	uint8 u8HCU_DrvModValue = 0;
	uint8 u8HCU_PT5Received = RTE_E_INVALID;
	FDM_tstSignalAttributes *pstSignal_HCU_DrvMod = &(pstProcessObject->strHCU_DrvMod);

	switch (stage)
	{
		case BEFOR_LOGIC_PROCESS:

			u8HCU_PT5Received = DM_Adapt_GetMessage_HCU_DrvMod(&u8HCU_DrvModValue);
			if (RTE_E_OK == u8HCU_PT5Received)
			{
				pstSignal_HCU_DrvMod->currentValue = u8HCU_DrvModValue;

				if (TRUE == SWC_DM_LOGOUT_ENBLE)
				{
					if (pstSignal_HCU_DrvMod->previosValue != pstSignal_HCU_DrvMod->currentValue)
					{
						SWC_DM_PRINT_WARN("DM: DrvMod = %d",pstSignal_HCU_DrvMod->currentValue);
					}
				}

				if (FALSE == pstSignal_HCU_DrvMod->status)
				{
					pstSignal_HCU_DrvMod->previosValue = pstSignal_HCU_DrvMod->currentValue;
				}
				else
				{
					// do nothing
				}
				pstSignal_HCU_DrvMod->status = TRUE;
			}
			else
			{
				pstSignal_HCU_DrvMod->previosValue = pstSignal_HCU_DrvMod->currentValue;
				pstSignal_HCU_DrvMod->status = FALSE;
			}

			break;
		case AFTER_LOGIC_PROCESS:
			pstSignal_HCU_DrvMod->previosValue = pstSignal_HCU_DrvMod->currentValue;

			if (FALSE != pstSignal_HCU_DrvMod->status)
			{
				u8HCU_DrvModValue = pstSignal_HCU_DrvMod->currentValue;
			}
			else
			{
				u8HCU_DrvModValue = DM_DRVMOD_NOSOUND_VALUE;
			}

			DM_API_vSetSwitchSignal(u8HCU_DrvModValue, DM_IMCACT_INVALID_VALUE);
			break;
		default:
			// do nothing
			break;
	}
}

/**********************************************************************************************************
*Function: FDM_HEVPHEVPS_TelltaleDrvModControl
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: ZJ
*
*Date: 2021-08-13
*
**********************************************************************************************************/
static void FDM_HEVPHEVPS_TelltaleDrvModControl(const FDM_tstProcessObject *pstProcessObject)
{
	DM_CFG_enTelltaleId enTelltaleStatusId = DM_enTT_NONE;

	if (pstProcessObject->strHCU_DrvMod.status)
	{
		enTelltaleStatusId = u8HcuSignal2TelltaleIconTable[pstProcessObject->strHCU_DrvMod.currentValue & DM_SIGNAL_HCUDRVMOD_BITMASK];
		(void)DM_API_vSetDrvModTTStatus(enTelltaleStatusId);
	}
	else
	{
		DM_API_vClrDrvModTTStatus();
	}
}

/**********************************************************************************************************
*Function: FDM_HEVPHEVPS_WarningDrvModControl
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: ZJ
*
*Date: 2021-08-13
*
**********************************************************************************************************/
static void FDM_HEVPHEVPS_WarningDrvModControl(const FDM_tstProcessObject *pstProcessObject)
{
	DM_CFG_enDrvModId enWarningStatusId = enDM_WarningInvaildId;

	if (pstProcessObject->strHCU_DrvMod.status)
	{
		if (pstProcessObject->strHCU_DrvMod.currentValue != pstProcessObject->strHCU_DrvMod.previosValue)
		{
			if ((pstProcessObject->strHCU_DrvMod.previosValue >= DM_SIGNAL_HCUDRVMOD_INVALID_0x0A)
				&& (pstProcessObject->strHCU_DrvMod.previosValue <= DM_SIGNAL_HCUDRVMOD_INVALID_0x0F))
			{

			}
			else if ((pstProcessObject->strHCU_DrvMod.currentValue >= DM_SIGNAL_HCUDRVMOD_INVALID_0x0A)
				&& (pstProcessObject->strHCU_DrvMod.currentValue <= DM_SIGNAL_HCUDRVMOD_INVALID_0x0F))
			{
				// Clear all drving mode warning
				DM_API_vClrAllDrvModWarningStatus();
			}
			else
			{
				enWarningStatusId = u8HcuSignal2WarningTable_DMStart[pstProcessObject->strHCU_DrvMod.currentValue & DM_SIGNAL_HCUDRVMOD_BITMASK];
				FDM_SetWarningStatus_Arbitration(pstProcessObject, enWarningStatusId);
			}
		}
		else
		{
			// do nothing, wait status change
		}
	}
	else
	{
		DM_API_vClrAllDrvModWarningStatus();
	}
}

/**********************************************************************************************************
*Function: FDM_HEVDHT_IsHEVDHTVehicle
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/

#ifdef GWM_V35_PROJECT_TYPE_B02
	#define FDM_HEVPHEVPS_ENABLE  1
	#define FDM_PHEVPS_HYBMOD_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define FDM_HEVPHEVPS_ENABLE  1
	#define FDM_PHEVPS_HYBMOD_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define FDM_HEVPHEVPS_ENABLE  0
	#define FDM_PHEVPS_HYBMOD_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define FDM_HEVPHEVPS_ENABLE  0
	#define FDM_PHEVPS_HYBMOD_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define FDM_HEVPHEVPS_ENABLE  1
	#define FDM_PHEVPS_HYBMOD_ENABLE 1
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define FDM_HEVPHEVPS_ENABLE  0
	#define FDM_PHEVPS_HYBMOD_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define FDM_HEVPHEVPS_ENABLE  0
	#define FDM_PHEVPS_HYBMOD_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define FDM_HEVPHEVPS_ENABLE  0
	#define FDM_PHEVPS_HYBMOD_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define FDM_HEVPHEVPS_ENABLE  0
	#define FDM_PHEVPS_HYBMOD_ENABLE 0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define FDM_HEVPHEVPS_ENABLE  0
	#define FDM_PHEVPS_HYBMOD_ENABLE 0
#else
	#define FDM_HEVPHEVPS_ENABLE  0
#endif

boolean FDM_HEVPHEVPS_IsHEVDHTVehicle(void)
{
	FDM_tstProcessObject *pstProcessObject = &stSignalObject;
	boolean ret = FALSE;
	boolean bDrvModEnable = FALSE;
	boolean bHybModEnable = FALSE;

	bDrvModEnable = FDM_NotFuel_GetDrvModType(pstProcessObject, DM_DRVMOD_HEV_PHEV_PS);
	bHybModEnable = FDM_PHEVPS_GetHybModType(pstProcessObject);
	if ((bDrvModEnable) && (1 == FDM_HEVPHEVPS_ENABLE))
	{
		bDrvModEnable = TRUE;
	}

	if ((bHybModEnable) && (1 == FDM_PHEVPS_HYBMOD_ENABLE))
	{
		bHybModEnable = TRUE;
	}

	if ((bDrvModEnable) || (bHybModEnable))
	{
		ret = TRUE;
	}

#if SWC_DM_NotFuel_ENABLE
	ret = FALSE;
#endif

	return ret;
}

/**********************************************************************************************************
*Function: FDM_HEVDHT_DelayTimeGet
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_HEVPHEVPS_DelayTimeGet(uint32* time)
{
	*time = TIME_100_MS * 30u;    // default delay 3s

	return TRUE;
}

/**********************************************************************************************************
*Function: FDM_HEVDHT_TransIntoNormal
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_HEVPHEVPS_TransIntoNormal(void)
{
	FDM_tstProcessObject *pstProcessObject = &stSignalObject;

	(void) memset(&(pstProcessObject->strHCU_DrvMod), 0, sizeof(FDM_tstSignalAttributes));
	(void) memset(&(pstProcessObject->strHCU_HybMod), 0, sizeof(FDM_tstSignalAttributes));

	DM_API_vClrDrvModTTStatus();
	DM_API_vClrAllDrvModWarningStatus();
	DM_API_vClrHybridModTTStatus();
	DM_API_vClrSwitchSignal();

	return TRUE;
}

/**********************************************************************************************************
*Function: FDM_HEVDHT_TransExitNormal
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_HEVPHEVPS_TransExitNormal(void)
{
	DM_API_vClrDrvModTTStatus();
	DM_API_vClrAllDrvModWarningStatus();
	DM_API_vClrHybridModTTStatus();
	return TRUE;
}

/**********************************************************************************************************
*Function: FDM_HEVDHT_FirstLogicProcess
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_HEVPHEVPS_FirstLogicProcess(void)
{
	FDM_tstProcessObject *pstProcessObject = &stSignalObject;

	FDM_HEVPHEVPS_SignalProcess(BEFOR_LOGIC_PROCESS, pstProcessObject);
	FDM_PHEVPSP4_HybOperSignalProcess(BEFOR_LOGIC_PROCESS, pstProcessObject);

	FDM_HEVPHEVPS_TelltaleDrvModControl(pstProcessObject);

	if (DM_HYBMOD_PHEV_PS_PSP4 == pstProcessObject->u8HybModeType)
	{
		FDM_PHEVPSP4_HybModTelltaleControl(pstProcessObject);
	}

	FDM_HEVPHEVPS_SignalProcess(AFTER_LOGIC_PROCESS, pstProcessObject);
	FDM_PHEVPSP4_HybOperSignalProcess(AFTER_LOGIC_PROCESS, pstProcessObject);

	return TRUE;
}

/**********************************************************************************************************
*Function: FDM_HEVDHT_GeneralLogicProcess
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_HEVPHEVPS_GeneralLogicProcess(void)
{
	FDM_tstProcessObject *pstProcessObject = &stSignalObject;

	FDM_HEVPHEVPS_SignalProcess(BEFOR_LOGIC_PROCESS, pstProcessObject);
	FDM_PHEVPSP4_HybOperSignalProcess(BEFOR_LOGIC_PROCESS, pstProcessObject);

	FDM_HEVPHEVPS_TelltaleDrvModControl(pstProcessObject);
	FDM_HEVPHEVPS_WarningDrvModControl(pstProcessObject);

	if (DM_HYBMOD_PHEV_PS_PSP4 == pstProcessObject->u8HybModeType)
	{
		FDM_PHEVPSP4_HybModTelltaleControl(pstProcessObject);
	}

	FDM_HEVPHEVPS_SignalProcess(AFTER_LOGIC_PROCESS, pstProcessObject);
	FDM_PHEVPSP4_HybOperSignalProcess(BEFOR_LOGIC_PROCESS, pstProcessObject);

	return TRUE;
}

/**********************************************************************************************************
*Function: FDM_PHEVP2P4_SignalProcess
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
static void FDM_PHEVP2P4_SignalProcess(FDM_enSignalProcessStage stage, FDM_tstProcessObject *pstProcessObject)
{
	uint8 u8HCU_DrvModDisp = 0;
	uint8 u8HCU_PT8Received = RTE_E_INVALID;
	FDM_tstSignalAttributes *pstSignal_HCU_DrvModDisp = &(pstProcessObject->strHCU_DrvModDisp);

	switch (stage)
	{
		case BEFOR_LOGIC_PROCESS:
			u8HCU_PT8Received = DM_Adapt_GetMessage_HCU_DrvModDisp(&u8HCU_DrvModDisp);
			if (RTE_E_OK != u8HCU_PT8Received)
			{
				pstSignal_HCU_DrvModDisp->currentValue = pstSignal_HCU_DrvModDisp->previosValue;
				pstSignal_HCU_DrvModDisp->status = FALSE;
			}
			else
			{
				pstSignal_HCU_DrvModDisp->currentValue = u8HCU_DrvModDisp;

				if (TRUE == SWC_DM_LOGOUT_ENBLE)
				{
					if (pstSignal_HCU_DrvModDisp->previosValue != pstSignal_HCU_DrvModDisp->currentValue)
					{
						SWC_DM_PRINT_WARN("DM: DrvModDisp = %d",pstSignal_HCU_DrvModDisp->currentValue);
					}
				}

				if (FALSE == pstSignal_HCU_DrvModDisp->status)
				{
					pstSignal_HCU_DrvModDisp->previosValue = pstSignal_HCU_DrvModDisp->currentValue;
				}
				else
				{
					// do nothing
				}

				pstSignal_HCU_DrvModDisp->status = TRUE;
			}

			break;
		case AFTER_LOGIC_PROCESS:
			pstSignal_HCU_DrvModDisp->previosValue = pstSignal_HCU_DrvModDisp->currentValue;

			if (FALSE != pstSignal_HCU_DrvModDisp->status)
			{
				u8HCU_DrvModDisp = pstSignal_HCU_DrvModDisp->currentValue;
			}
			else
			{
				u8HCU_DrvModDisp = DM_DRVMOD_NOSOUND_VALUE;
			}

			DM_API_vSetSwitchSignal(u8HCU_DrvModDisp, DM_IMCACT_INVALID_VALUE);
			break;
		default:
			// do nothing
			break;
	}
}

/**********************************************************************************************************
*Function: FDM_HEVPHEVPS_TelltaleDrvModControl
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: ZJ
*
*Date: 2021-08-13
*
**********************************************************************************************************/
static void FDM_PHEVP2P4_TelltaleDrvModControl(const FDM_tstProcessObject *pstProcessObject)
{
	DM_CFG_enTelltaleId enTelltaleStatusId = DM_enTT_NONE;

	if (pstProcessObject->strHCU_DrvModDisp.status)
	{
		enTelltaleStatusId = u8HcuDisp2TelltaleIconTable[pstProcessObject->strHCU_DrvModDisp.currentValue & DM_SIGNAL_HCUDRVMODDISP_BITMASK];
		(void)DM_API_vSetDrvModTTStatus(enTelltaleStatusId);
	}
	else
	{
		DM_API_vClrDrvModTTStatus();
	}
}

/**********************************************************************************************************
*Function: FDM_PHEVP2P4_WarningDrvModControl
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: ZJ
*
*Date: 2021-08-13
*
**********************************************************************************************************/
static void FDM_PHEVP2P4_WarningDrvModControl(const FDM_tstProcessObject *pstProcessObject)
{
	DM_CFG_enDrvModId enWarningStatusId = enDM_WarningInvaildId;
	if (pstProcessObject->strHCU_DrvModDisp.status)
	{
		if (pstProcessObject->strHCU_DrvModDisp.currentValue != pstProcessObject->strHCU_DrvModDisp.previosValue)
		{
			if ((DM_SIGNAL_HCUDRVMODDISP_INVALID_0x08 == pstProcessObject->strHCU_DrvModDisp.previosValue)
				|| ((pstProcessObject->strHCU_DrvModDisp.previosValue >= DM_SIGNAL_HCUDRVMODDISP_INVALID_0x0A)
				&& (pstProcessObject->strHCU_DrvModDisp.previosValue <= DM_SIGNAL_HCUDRVMODDISP_INVALID_0x0F)))
			{

			}
			else if ((DM_SIGNAL_HCUDRVMODDISP_INVALID_0x08 == pstProcessObject->strHCU_DrvModDisp.currentValue)
				|| ((pstProcessObject->strHCU_DrvModDisp.currentValue >= DM_SIGNAL_HCUDRVMODDISP_INVALID_0x0A)
				&& (pstProcessObject->strHCU_DrvModDisp.currentValue <= DM_SIGNAL_HCUDRVMODDISP_INVALID_0x0F)))
			{
				// Clear all drving mode warning
				DM_API_vClrAllDrvModWarningStatus();
			}
			else
			{
				enWarningStatusId = u8HcuDisp2WarningTable_DMStart[pstProcessObject->strHCU_DrvModDisp.currentValue & DM_SIGNAL_HCUDRVMODDISP_BITMASK];
				FDM_SetWarningStatus_Arbitration(pstProcessObject, enWarningStatusId);
			}
		}
		else
		{
			// do nothing, wait status change
		}
	}
	else
	{
		DM_API_vClrAllDrvModWarningStatus();
	}
}

/**********************************************************************************************************
*Function: FDM_PHEVP2_IsPHEVP2Vehicle
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define FDM_PHEVP2P4_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define FDM_PHEVP2P4_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define FDM_PHEVP2P4_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define FDM_PHEVP2P4_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define FDM_PHEVP2P4_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define FDM_PHEVP2P4_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define FDM_PHEVP2P4_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define FDM_PHEVP2P4_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define FDM_PHEVP2P4_ENABLE  0
#else
	#define FDM_PHEVP2P4_ENABLE  0
#endif

boolean FDM_PHEVP2P4_IsPHEVP2Vehicle(void)
{
	FDM_tstProcessObject *pstProcessObject = &stSignalObject;
	boolean ret = FALSE;

	ret = FDM_NotFuel_GetDrvModType(pstProcessObject, DM_DRVMOD_PHEV_P2_P2P4);
	if (0 == FDM_PHEVP2P4_ENABLE)
	{
		ret = FALSE;
	}

#if SWC_DM_NotFuel_ENABLE
	ret = FALSE;
#endif

	return ret;
}

/**********************************************************************************************************
*Function: FDM_PHEVP2_DelayTimeGet
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_PHEVP2P4_DelayTimeGet(uint32* time)
{
	uint32 u32CfgTimeData = 0u;
	CconfigKind_400Bytes u8FDM_CconfigKind_400Bytes;

	if(E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(u8FDM_CconfigKind_400Bytes))
	{
		u32CfgTimeData = (uint32)CConfig_GetConfig(CCONFIG_KIND_DriveModeShieldTime, u8FDM_CconfigKind_400Bytes);
	}
	else
	{
		u32CfgTimeData = 30u;
	}

	*time = TIME_100_MS * u32CfgTimeData;        // default delay 3s

	return TRUE;
}

/**********************************************************************************************************
*Function: FDM_PHEVP2_TransIntoNormal
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_PHEVP2P4_TransIntoNormal(void)
{
	FDM_tstProcessObject *pstProcessObject = &stSignalObject;

	(void) memset(&(pstProcessObject->strHCU_DrvModDisp), 0, sizeof(FDM_tstSignalAttributes));
	DM_API_vClrDrvModTTStatus();
	DM_API_vClrAllDrvModWarningStatus();
	DM_API_vClrSwitchSignal();

	return TRUE;
}

/**********************************************************************************************************
*Function: FDM_PHEVP2_TransExitNormal
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_PHEVP2P4_TransExitNormal(void)
{
	DM_API_vClrDrvModTTStatus();
	DM_API_vClrAllDrvModWarningStatus();
	return TRUE;
}

/**********************************************************************************************************
*Function: FDM_PHEVP2_FirstLogicProcess
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_PHEVP2P4_FirstLogicProcess(void)
{
	FDM_tstProcessObject *pstProcessObject = &stSignalObject;

	FDM_PHEVP2P4_SignalProcess(BEFOR_LOGIC_PROCESS, pstProcessObject);

	FDM_PHEVP2P4_TelltaleDrvModControl(pstProcessObject);

	FDM_PHEVP2P4_SignalProcess(AFTER_LOGIC_PROCESS, pstProcessObject);

	return TRUE;
}

/**********************************************************************************************************
*Function: FDM_PHEVP2_GeneralLogicProcess
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_PHEVP2P4_GeneralLogicProcess(void)
{
	FDM_tstProcessObject *pstProcessObject = &stSignalObject;

	FDM_PHEVP2P4_SignalProcess(BEFOR_LOGIC_PROCESS, pstProcessObject);

	FDM_PHEVP2P4_TelltaleDrvModControl(pstProcessObject);
	FDM_PHEVP2P4_WarningDrvModControl(pstProcessObject);

	FDM_PHEVP2P4_SignalProcess(AFTER_LOGIC_PROCESS, pstProcessObject);

	return TRUE;
}

/**********************************************************************************************************
*Function: FDM_EV_SignalProcess
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
static void FDM_EV_SignalProcess(FDM_enSignalProcessStage stage, FDM_tstProcessObject *pstProcessObject)
{
	uint8 u8VCU_DrvMod = 0;
	FDM_tstSignalAttributes *pstSignal_VCU_DrvMod = &(pstProcessObject->strVCU_DrvMod);

	switch (stage)
	{
		case BEFOR_LOGIC_PROCESS:
			if (TRUE /* VCU_DrvMod missing */)
			{
				//stSignalObject.strVCU_DrvMod.currentValue = stSignalObject.strVCU_DrvMod.previosValue;
				pstSignal_VCU_DrvMod->status = FALSE;
			}
			else
			{
				//stSignalObject.strVCU_DrvMod.currentValue = RTE_interface;

				// recover from signal missing
				if (FALSE == pstSignal_VCU_DrvMod->status)
				{
					pstSignal_VCU_DrvMod->previosValue = pstSignal_VCU_DrvMod->currentValue;
				}
				else
				{
					// do nothing
				}

				pstSignal_VCU_DrvMod->status = TRUE;
			}
			break;
		case AFTER_LOGIC_PROCESS:
			pstSignal_VCU_DrvMod->previosValue = pstSignal_VCU_DrvMod->currentValue;

			if (FALSE != pstSignal_VCU_DrvMod->status)
			{
				u8VCU_DrvMod = pstSignal_VCU_DrvMod->currentValue;
			}
			else
			{
				u8VCU_DrvMod = DM_DRVMOD_NOSOUND_VALUE;
			}

			DM_API_vSetSwitchSignal(u8VCU_DrvMod, DM_IMCACT_INVALID_VALUE);
			break;
		default:
			// do nothing
			break;
		}
}

/**********************************************************************************************************
*Function: FDM_EV_TelltaleDrvModControl
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
static void FDM_EV_TelltaleDrvModControl(const FDM_tstProcessObject *pstProcessObject)
{
	const FDM_tstSignalAttributes *pstSignal_VCU_DrvMod = &(pstProcessObject->strVCU_DrvMod);
	DM_CFG_enTelltaleId enTelltaleStatusId = DM_enTT_NONE;

	if (pstSignal_VCU_DrvMod->status)
	{
		enTelltaleStatusId = u8VcuDrvMod2TelltaleIconTable[pstSignal_VCU_DrvMod->currentValue & DM_SIGNAL_VCUDRVMOD_BITMASK];
		(void) DM_API_vSetDrvModTTStatus(enTelltaleStatusId);
	}
	else
	{
		DM_API_vClrDrvModTTStatus();
	}
}

/**********************************************************************************************************
*Function: FDM_EV_WarningDrvModControl
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
static void FDM_EV_WarningDrvModControl(const FDM_tstProcessObject *pstProcessObject)
{
	const FDM_tstSignalAttributes *pstSignal_VCU_DrvMod = &(pstProcessObject->strVCU_DrvMod);
	DM_CFG_enDrvModId enWarningStatusId = enDM_WarningInvaildId;

	if (pstSignal_VCU_DrvMod->status)
	{
		if (pstSignal_VCU_DrvMod->currentValue != pstSignal_VCU_DrvMod->previosValue)
		{
			enWarningStatusId = u8VcuDrvMod2WarningTable_DMStart[pstSignal_VCU_DrvMod->currentValue & DM_SIGNAL_VCUDRVMOD_BITMASK];
			FDM_SetWarningStatus_Arbitration(pstProcessObject, enWarningStatusId);
		}
		else
		{
			// do nothing
		}
	}
	else
	{
		DM_API_vClrAllDrvModWarningStatus();
	}
}

/**********************************************************************************************************
*Function: FDM_EV_IsEVVehicle
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02
	#define FDM_EV_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_B03
	#define FDM_EV_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define FDM_EV_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define FDM_EV_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define FDM_EV_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define FDM_EV_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define FDM_EV_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define FDM_EV_ENABLE  0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define FDM_EV_ENABLE  0
#else
	#define FDM_EV_ENABLE  0
#endif

boolean FDM_EV_IsEVVehicle(void)
{
	FDM_tstProcessObject *pstProcessObject = &stSignalObject;
	boolean ret = FALSE;

	ret = FDM_NotFuel_GetDrvModType(pstProcessObject, DM_DRVMOD_EV);
	if(0 == FDM_EV_ENABLE)
	{
		ret = FALSE;
	}

#if SWC_DM_NotFuel_ENABLE
	ret = FALSE;
#endif

	return ret;
}

/**********************************************************************************************************
*Function: FDM_EV_DelayTimeGet
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_EV_DelayTimeGet(uint32* time)
{
	*time = TIME_100_MS * 0u;

	return TRUE;
}

/**********************************************************************************************************
*Function: FDM_EV_TransIntoNormal
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_EV_TransIntoNormal(void)
{
	FDM_tstProcessObject *pstProcessObject = &stSignalObject;
	uint8 u8PreVCUDrvModValue = 0;

	// record the last signal VCU_DrvMod
	u8PreVCUDrvModValue = pstProcessObject->strVCU_DrvMod.currentValue;
	(void) memset(&(pstProcessObject->strVCU_DrvMod), 0, sizeof(FDM_tstSignalAttributes));
	pstProcessObject->strVCU_DrvMod.previosValue = u8PreVCUDrvModValue;
	pstProcessObject->strVCU_DrvMod.status = TRUE;

	DM_API_vClrDrvModTTStatus();
	DM_API_vClrAllDrvModWarningStatus();
	DM_API_vClrSwitchSignal();

	return TRUE;
}

/**********************************************************************************************************
*Function: FDM_EV_TransExitNormal
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_EV_TransExitNormal(void)
{
	DM_API_vClrDrvModTTStatus();
	DM_API_vClrAllDrvModWarningStatus();
	return TRUE;
}


/**********************************************************************************************************
*Function: FDM_EV_FirstLogicProcess
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_EV_FirstLogicProcess(void)
{
	FDM_tstProcessObject *pstProcessObject = &stSignalObject;

	FDM_EV_SignalProcess(BEFOR_LOGIC_PROCESS, pstProcessObject);

	FDM_EV_TelltaleDrvModControl(pstProcessObject);
	FDM_EV_WarningDrvModControl(pstProcessObject);

	FDM_EV_SignalProcess(AFTER_LOGIC_PROCESS, pstProcessObject);

	return TRUE;
}


/**********************************************************************************************************
*Function: FDM_EV_GeneralLogicProcess
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
boolean FDM_EV_GeneralLogicProcess(void)
{
	FDM_tstProcessObject *pstProcessObject = &stSignalObject;

	FDM_EV_SignalProcess(BEFOR_LOGIC_PROCESS, pstProcessObject);

	FDM_EV_TelltaleDrvModControl(pstProcessObject);
	FDM_EV_WarningDrvModControl(pstProcessObject);

	FDM_EV_SignalProcess(AFTER_LOGIC_PROCESS, pstProcessObject);

	return TRUE;
}

/**********************************************************************************************************
*Function: FDM_SetWarningStatus_F1
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
static boolean FDM_SetWarningStatus_F1(DM_CFG_enWarningId setWarningId, DM_CFG_enWarningId incompatibleIdStart, DM_CFG_enWarningId incompatibleIdIdEnd)
{
	// assert(incompatibleIdIdEnd >= incompatibleIdStart);
	boolean ret = FALSE;
	uint8 u8WarningIndex = 0;

	if (DM_enWN_WarningInvaildId == setWarningId)
	{
		ret = FALSE;
	}
	else
	{
		if((setWarningId >= DM_enWN_FUEL_StandardSelect) && (setWarningId <= DM_enWN_FUEL_AutoModeSwitch))
		{
			FDM_FixedWarningStatusClr(DM_FIX_SEL_SWMODE_CLR);
		}
		else
		{
			for(u8WarningIndex = (uint8)incompatibleIdStart; u8WarningIndex <= incompatibleIdIdEnd; u8WarningIndex++)
			{
				if (setWarningId != u8WarningIndex)
				{
					(void) DM_API_vClrDrvModWarningStatus(u8WarningIndex);
				}
			}
		}
		(void) DM_API_vSetDrvModWarningStatus(setWarningId);

		ret = TRUE;
	}

	return ret;
}

/**********************************************************************************************************
*Function: FDM_SetWarningStatus_Arbitration
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: Li Jian
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
static void FDM_SetWarningStatus_Arbitration(const FDM_tstProcessObject* pstProcessObject, DM_CFG_enDrvModId enDrvModWarningID)
{
	DM_CFG_enWarningId enWarningScreenId = DM_enWN_WarningInvaildId;
	uint8 u8DrvModType = pstProcessObject->u8DriveModeType;
	uint8 u8CaseIndex = pstProcessObject->u8FuelDrvModCaseIndex;

	switch(u8DrvModType)
	{
		case (uint8)DM_DRVMOD_FUEL:
			if (DM_FUEL_LOGIC_CASE4 == u8CaseIndex)
			{
				if ((enDrvModWarningID >= tstFuel4Mod2Scr.ModStartIndex) && (enDrvModWarningID <= tstFuel4Mod2Scr.ModEndIndex))
				{
					// Find the screen class
					enWarningScreenId = tstFuel4Mod2Scr.Mod2ScrTab[(uint8)enDrvModWarningID - (uint8)tstFuel4Mod2Scr.ModStartIndex];
					(void) FDM_SetWarningStatus_F1(enWarningScreenId, tstFuel4Mod2Scr.ModScrStartIndex, tstFuel4Mod2Scr.ModScrEndIndex);
				}
				else
				{
					// error, will never do this statment
				}
			}
			else
			{
				if ((enDrvModWarningID >= tstFuelMod2Scr.ModStartIndex) && (enDrvModWarningID <= tstFuelMod2Scr.ModEndIndex))
				{
					enWarningScreenId = tstFuelMod2Scr.Mod2ScrTab[(uint8)enDrvModWarningID - (uint8)tstFuelMod2Scr.ModStartIndex];
					(void) FDM_SetWarningStatus_F1(enWarningScreenId, tstFuelMod2Scr.ModScrStartIndex, tstFuelMod2Scr.ModScrEndIndex);
				}
				else if ((enDrvModWarningID >= tstFuelMod2Scr.ModSelectStartIndex) && (enDrvModWarningID <= tstFuelMod2Scr.ModSelectEndIndex))
				{
					enWarningScreenId = tstFuelMod2Scr.ModSelect2ScrTab[(uint8)enDrvModWarningID - (uint8)tstFuelMod2Scr.ModSelectStartIndex];
					(void) FDM_SetWarningStatus_F1(enWarningScreenId, tstFuelMod2Scr.ModSelectScrStartIndex, tstFuelMod2Scr.ModSelectScrEndIndex);
				}
				else if ((enDrvModWarningID >= tstFuelMod2Scr.ModSwitchStartIndex) && (enDrvModWarningID <= tstFuelMod2Scr.ModSwitchEndIndex))
				{
					enWarningScreenId = tstFuelMod2Scr.ModSwitch2ScrTab[(uint8)enDrvModWarningID - (uint8)tstFuelMod2Scr.ModSwitchStartIndex];
					(void) FDM_SetWarningStatus_F1(enWarningScreenId, tstFuelMod2Scr.ModSwitchScrStartIndex, tstFuelMod2Scr.ModSwitchScrEndIndex);
				}
				else
				{
					// do nothing
				}
			}

			break;
		case (uint8)DM_DRVMOD_HEV_PHEV_PS:
			if ((enDrvModWarningID >= tstHEVDMStart.ModStartIndex) && (enDrvModWarningID <= tstHEVDMStart.ModEndIndex))
			{
				enWarningScreenId = tstHEVDMStart.Mod2ScrTab[(uint8)enDrvModWarningID - (uint8)tstHEVDMStart.ModStartIndex];
				(void) FDM_SetWarningStatus_F1(enWarningScreenId, tstHEVDMStart.ModScrStartIndex, tstHEVDMStart.ModScrEndIndex);
			}
			else
			{
				// do nothing
			}

			break;
		case (uint8)DM_DRVMOD_PHEV_P2_P2P4:
			if ((enDrvModWarningID >= tstPHEVDMStart.ModStartIndex) && (enDrvModWarningID <= tstPHEVDMStart.ModEndIndex))
			{
				enWarningScreenId = tstPHEVDMStart.Mod2ScrTab[(uint8)enDrvModWarningID - (uint8)tstPHEVDMStart.ModStartIndex];
				(void) FDM_SetWarningStatus_F1(enWarningScreenId, tstPHEVDMStart.ModScrStartIndex, tstPHEVDMStart.ModScrEndIndex);
			}
			else
			{
				// do nothing
			}

			break;
		case (uint8)DM_DRVMOD_EV:
			if ((enDrvModWarningID >= tstEVDMStart.ModStartIndex) && (enDrvModWarningID <= tstEVDMStart.ModEndIndex))
			{
				enWarningScreenId = tstEVDMStart.Mod2ScrTab[(uint8)enDrvModWarningID - (uint8)tstEVDMStart.ModStartIndex];
				(void) FDM_SetWarningStatus_F1(enWarningScreenId, tstEVDMStart.ModScrStartIndex, tstEVDMStart.ModScrEndIndex);
			}
			else
			{
				// do nothing
			}

			break;
		default:
			// do nothing
			break;
	}
}

/**********************************************************************************************************
*Function: FDM_PHEVPP2_HybModSignalProcess
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: ZJ
*
*Date: 2021-08-13
*
**********************************************************************************************************/
static void FDM_PHEVPP2_HybModSignalProcess(FDM_enSignalProcessStage stage, FDM_tstProcessObject *pstProcessObject)
{
	uint8 u8HCU_HybOper = 0;
	uint8 u8HCU_HybReceived = RTE_E_INVALID;
	FDM_tstSignalAttributes *pstSignal_HCU_Oper = &(pstProcessObject->strHCU_OperationMod);

	switch (stage)
	{
		case BEFOR_LOGIC_PROCESS:
			u8HCU_HybReceived = DM_Adapt_GetMessage_HCU_HybMod(&u8HCU_HybOper);
			if (RTE_E_OK != u8HCU_HybReceived)
			{
				pstSignal_HCU_Oper->currentValue = pstSignal_HCU_Oper->previosValue;
				pstSignal_HCU_Oper->status = FALSE;
			}
			else
			{
				pstSignal_HCU_Oper->currentValue = u8HCU_HybOper;

				if (FALSE == pstSignal_HCU_Oper->status)
				{
					pstSignal_HCU_Oper->previosValue = pstSignal_HCU_Oper->currentValue;
				}
				else
				{
					// do nothing
				}

				pstSignal_HCU_Oper->status = TRUE;
			}

			break;
		case AFTER_LOGIC_PROCESS:
			pstSignal_HCU_Oper->previosValue = pstSignal_HCU_Oper->currentValue;
			break;
		default:
			// do nothing
			break;
	}
}

/**********************************************************************************************************
*Function: FDM_PHEVPSP4_HybOperSignalProcess
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: ZJ
*
*Date: 2021-08-13
*
**********************************************************************************************************/
static void FDM_PHEVPSP4_HybOperSignalProcess(FDM_enSignalProcessStage stage, FDM_tstProcessObject *pstProcessObject)
{
	uint8 u8HCU_HybMod = 0;
	uint8 u8HCU_HybReceived = RTE_E_INVALID;
	FDM_tstSignalAttributes *pstSignal_HCU_HybMod = &(pstProcessObject->strHCU_HybMod);

	switch (stage)
	{
		case BEFOR_LOGIC_PROCESS:
			u8HCU_HybReceived = DM_Adapt_GetMessage_HCU_HybMod(&u8HCU_HybMod);
			if (RTE_E_OK != u8HCU_HybReceived)
			{
				pstSignal_HCU_HybMod->currentValue = pstSignal_HCU_HybMod->previosValue;
				pstSignal_HCU_HybMod->status = FALSE;
			}
			else
			{
				pstSignal_HCU_HybMod->currentValue = u8HCU_HybMod;

				if (FALSE == pstSignal_HCU_HybMod->status)
				{
					pstSignal_HCU_HybMod->previosValue = pstSignal_HCU_HybMod->currentValue;
				}
				else
				{
					// do nothing
				}

				pstSignal_HCU_HybMod->status = TRUE;
			}

			break;
		case AFTER_LOGIC_PROCESS:
			pstSignal_HCU_HybMod->previosValue = pstSignal_HCU_HybMod->currentValue;
			break;
		default:
			// do nothing
			break;
	}
}

/**********************************************************************************************************
*Function: FDM_PHEVPP2_HybModTelltaleControl
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: ZJ
*
*Date: 2021-08-13
*
**********************************************************************************************************/
static void FDM_PHEVPP2_HybModTelltaleControl(const FDM_tstProcessObject *pstProcessObject)
{
	DM_HMCFG_enTelltaleId enTelltaleStatusId = DM_enTT_HMNONE;

	if (pstProcessObject->strHCU_OperationMod.status)
	{
		enTelltaleStatusId = u8HcuOperSig2TtIconTabPP2[pstProcessObject->strHCU_OperationMod.currentValue & DM_SIGNAL_HCUOPERMOD_BITMASK];
		(void)DM_API_vSetHybridModTTStatus(enTelltaleStatusId);
	}
	else
	{
		DM_API_vClrHybridModTTStatus();
	}
}

/**********************************************************************************************************
*Function: FDM_PHEVPSP4_HybModTelltaleControl
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: ZJ
*
*Date: 2021-08-13
*
**********************************************************************************************************/
static void FDM_PHEVPSP4_HybModTelltaleControl(const FDM_tstProcessObject *pstProcessObject)
{
	DM_HMCFG_enTelltaleId enTelltaleStatusId = DM_enTT_HMNONE;

	if (pstProcessObject->strHCU_HybMod.status)
	{
		enTelltaleStatusId = u8HcuHybSig2TtIconTabPS[pstProcessObject->strHCU_HybMod.currentValue & DM_SIGNAL_HCUHYBMOD_BITMASK];
		(void)DM_API_vSetHybridModTTStatus(enTelltaleStatusId);
	}
	else
	{
		DM_API_vClrHybridModTTStatus();
	}
}

#define Common_Normal_STOP_SEC_CODE
#include  "Common_Normal_MemMap.h"


