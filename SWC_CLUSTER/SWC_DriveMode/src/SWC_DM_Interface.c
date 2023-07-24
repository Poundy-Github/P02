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
*File Name   : SWC_DrvMod_Interface.c                                                                     *
*                                                                                                         *
*Description : Driving Mode module interface function source file.                                        *
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
#include "Std_Types.h"
#include <string.h> /* memset */
#include "Rte_Common_Normal.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_DM_Interface.h"
#include "SWC_DM_Adapt.h"
#include "SWC_DM_Config.h"
#include "IPC_ClusterApp.h"
#include "SWC_IPC_Config.h"

#include "VConfig.h"

#define Common_Normal_START_SEC_VAR_NOINIT_UNSPECIFIED
#include  "Common_Normal_MemMap.h"

static DM_MainObject_t DM_stMainObject;
static IPC_M2S_ClusterAppAPPDriveMode_t ToSBUS_DM_DriveMode;
#define Common_Normal_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include  "Common_Normal_MemMap.h"


#define Common_Normal_START_SEC_VAR_INIT_UNSPECIFIED
#include  "Common_Normal_MemMap.h"

static const DM_DrvModAttr_t DM_stAttrTab[DM_CFG_LOGIC_PROCESS_ITEM] = DM_CFG_LOGIC_PROCESS_ATTRIBUTE;
static boolean boDmAllConfig_Byteflg = FALSE;
//static uint8 *u8DmAllConfig_ByteTemp = NULL;

#define Common_Normal_STOP_SEC_VAR_INIT_UNSPECIFIED
#include  "Common_Normal_MemMap.h"

//static const uint8 DM_u8DrvModId2WrnId[DM_enWN_WarningMaxId] = DM_CFG_ID_DRVMOD_TO_WRN;

#define Common_Normal_START_SEC_GLOBALB_VAR_UNSPECIFIED
#include  "Common_Normal_MemMap.h"

static DM_SwitchSoundSigOut DM_strSignalOut;

#define Common_Normal_STOP_SEC_GLOBALB_VAR_UNSPECIFIED
#include  "Common_Normal_MemMap.h"


#define Common_Normal_START_SEC_CODE
#include  "Common_Normal_MemMap.h"

static boolean DM_IgnOnDelayProcess(void);
static void DM_PowerModeCheck(void);
static void DM_VehicleConfigGet(void);
static void DM_VarInit(void);
static void DM_RTE_WarningAndTelltaleStatusUpdata(void);
static void DM_RTE_SBUSUpdateDriveModeTheme(void);

#if 0
static void DM_Init(void);
#endif



/**********************************************************************************************************
*Function: DM_IgnOnDelayProcess
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
static boolean DM_IgnOnDelayProcess(void)
{
	boolean ret = FALSE;

	// TODO: Maybe system time interface is a good choice
	if (DM_stMainObject.u32IgnDelayTime > 0)
	{
		DM_stMainObject.u32IgnDelayTime--;
	}

	if (DM_stMainObject.u32IgnDelayTime == 0)
	{
		ret = TRUE;
	}

	return ret;
}


/**********************************************************************************************************
*Function: DM_PowerModeCheck
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
static void DM_PowerModeCheck(void)
{
    uint32 u32PowerModeStatus = 0;
	uint32 u32LastPowerModeStatus = DM_stMainObject.unPowerModeStatus.u32PowerModeStatus;
	SystemState_RecordType stSystemState;

	(void) memcpy(&stSystemState, Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut(), sizeof(SystemState_RecordType));

	if((stSystemState.s_PowerVoltage.state == VOLTAGE_OUT_NORMAL) \
		|| (stSystemState.s_PowerVoltage.state == VOLTAGE_OUT_LOWALARM) \
		|| (stSystemState.s_PowerVoltage.state == VOLTAGE_OUT_HIGHALARM))
	{
		if(stSystemState.ClusterState == SYSTEMSTATE_Cluster_STANDBY)
		{
			u32PowerModeStatus = (uint32)DM_enOFF;
		}
		else if(stSystemState.ClusterState == SYSTEMSTATE_Cluster_ON)
		{
			u32PowerModeStatus = (uint32)DM_enRUN;
		}
		else if((stSystemState.ClusterState == SYSTEMSTATE_Cluster_OFF)\
			|| (stSystemState.ClusterState == SYSTEMSTATE_Cluster_SHUTDOWN))
		{
			u32PowerModeStatus = (uint32)DM_enSLEEP;
		}
		else
		{
			/*Do nothing but avoid QAC*/
		}

	}
	else
	{
		u32PowerModeStatus = (uint32)DM_enABNORMAL_VOLTAGE;
	}

	if((u32PowerModeStatus == DM_enABNORMAL_VOLTAGE) && (u32LastPowerModeStatus != DM_enABNORMAL_VOLTAGE))
	{
		DM_stMainObject.u8DrvModStates = STATE_TRANSMIT_IGN_OFF;
	}
	else
	{
		if((u32PowerModeStatus == DM_enRUN) && (u32LastPowerModeStatus != DM_enRUN))
		{
			DM_stMainObject.u8DrvModStates = STATE_TRANSMIT_IGN_ON;
		}
		else if(((u32PowerModeStatus == DM_enOFF) && (u32LastPowerModeStatus != DM_enOFF)))
		{
			DM_stMainObject.u8DrvModStates = STATE_TRANSMIT_IGN_OFF;
		}
		else
		{
			/*Do nothing but avoid QAC*/
		}
	}

	DM_stMainObject.unPowerModeStatus.u32PowerModeStatus = u32PowerModeStatus;

}


/**********************************************************************************************************
*Function: DM_VehicleConfigGet
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
static void DM_VehicleConfigGet(void)
{
	uint8 i = 0;
	boolean ret = FALSE;
	uint8 u8FuelPriority = DM_PRIORITY_1;

	// Vehicle type select
 	DM_stMainObject.u8VehicleIndex = DM_CFG_LOGIC_PROCESS_INVAILD_ITEM;

	u8FuelPriority = DM_Adapt_FuelLogicPriority();
	if (DM_PRIORITY_1 == u8FuelPriority)
	{
		for(i = 0; i < DM_CFG_LOGIC_PROCESS_ITEM; i++)
		{
			if (DM_stAttrTab[i].VehicleInfoGet != NULL)
			{
				ret = DM_stAttrTab[i].VehicleInfoGet();
				if (ret != FALSE)
				{
					DM_stMainObject.u8VehicleIndex = i;
					break;
				}
			}
		}
	}
	else
	{
		for(i = DM_CFG_LOGIC_PROCESS_ITEM; i > 0; i--)
		{
			if (DM_stAttrTab[i - 1].VehicleInfoGet != NULL)
			{
				ret = DM_stAttrTab[i - 1].VehicleInfoGet();
				if (ret != FALSE)
				{
					DM_stMainObject.u8VehicleIndex = i - 1u;
					break;
				}
			}
		}
	}

	// Driving Mode enable or not
	if ((DM_stMainObject.u8VehicleIndex != DM_CFG_LOGIC_PROCESS_INVAILD_ITEM)
		&& (DM_stMainObject.u8VehicleIndex < DM_CFG_LOGIC_PROCESS_ITEM))
	{
		DM_stMainObject.u8DrvModEnable = TRUE;
	}
	else
	{
		DM_stMainObject.u8DrvModEnable = FALSE;
	}
}


/**********************************************************************************************************
*Function: DM_VarInit
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
static void DM_VarInit(void)
{
	DM_stMainObject.unPowerModeStatus.u32PowerModeStatus = (uint32)DM_enOFF;
	DM_stMainObject.u8DrvModStates = STATE_LOGIC_IDLE;
}

#if 0
/**********************************************************************************************************
*Function: DM_Init
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
static void DM_Init(void)
{
	DM_VehicleConfigGet();
	DM_VarInit();
}
#endif

/**********************************************************************************************************
*Function: DM_API_vKSColdInit
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
void DM_API_vKSColdInit(void)
{
	(void) memset((void*)&DM_stMainObject, 0, sizeof(DM_stMainObject));
	DM_VarInit();
}


/**********************************************************************************************************
*Function: DM_API_vKSWarmInit
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
void DM_API_vKSWarmInit(void)
{
	DM_VarInit();
}

/**********************************************************************************************************
*Function: DM_API_vDrvModeAppTimeTask
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
void DM_API_vDrvModeAppTimeTask(void)
{
	uint8 states = STATE_LOGIC_IDLE;
	boolean ret = FALSE;
	uint8 u8CfgData[5] = {0};

	//u8DmAllConfig_ByteTemp = Rte_IRead_Common_Normal_10msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes();
	if(!boDmAllConfig_Byteflg)
	{
		if(DM_Adapt_GetVconfig(VCONFIG_KIND_INIT_FLAG) != 0)
		{
			boDmAllConfig_Byteflg = TRUE;
			DM_VehicleConfigGet();

			if (TRUE == SWC_DM_LOGOUT_ENBLE)
			{
				u8CfgData[0] = DM_Adapt_GetVconfig(VCONFIG_KIND_DRIVING_MODE_OPTIONAL);
				u8CfgData[1] = DM_Adapt_GetVconfig(VCONFIG_KIND_DRIVING_MODE_2);
				u8CfgData[2] = DM_Adapt_GetVconfig(VCONFIG_KIND_DRIVING_MODE_3);
				u8CfgData[3] = DM_Adapt_GetVconfig(VCONFIG_KIND_FUEL);
				u8CfgData[4] = DM_Adapt_GetVconfig(VCONFIG_KIND_ELECTROMOTOR_POSITION);
				SWC_DM_PRINT_WARN("DM: Mode1:%d, Mode2:%d, Mode3:%d, FCFG:%d, MCFG:%d",u8CfgData[0], u8CfgData[1],\
					u8CfgData[2], u8CfgData[3], u8CfgData[4]);
			}
		}
	}

	if (((DM_stMainObject.u8DrvModEnable != TRUE) || (DM_CFG_LOGIC_PROCESS_INVAILD_ITEM == DM_stMainObject.u8VehicleIndex))\
		|| (boDmAllConfig_Byteflg != TRUE))
	{
		// driving mode disable or vehicle config error, do nothing
		return;
	}

	DM_PowerModeCheck();

	states = DM_stMainObject.u8DrvModStates;
	switch(states)
	{
		case STATE_TRANSMIT_IGN_ON:
			if (DM_stAttrTab[DM_stMainObject.u8VehicleIndex].TransIntoNormal != NULL)
			{
				ret = DM_stAttrTab[DM_stMainObject.u8VehicleIndex].TransIntoNormal();
			}
			else
			{
				// if no function need to call, go to next states
				ret = TRUE;
			}

			if (ret)
			{
				if (DM_stAttrTab[DM_stMainObject.u8VehicleIndex].IgnOnDelayTmrGetFun != NULL)
				{
					(void) (DM_stAttrTab[DM_stMainObject.u8VehicleIndex].IgnOnDelayTmrGetFun(&(DM_stMainObject.u32IgnDelayTime)));
				}
				else
				{
					// default delay time is 3 second
					DM_stMainObject.u32IgnDelayTime = TIME_3_SEC;
				}
				DM_stMainObject.u8DrvModFixedControlStatus = (uint8)DM_enTT_TelltaleMaxId;
				DM_stMainObject.u8DrvModStates = STATE_IGNON_DELAY_PROCESS;
			}
			else
			{
				// wait until ign on deal complete
			}
			break;
		case STATE_IGNON_DELAY_PROCESS:
			ret = DM_IgnOnDelayProcess();

			if (ret)
			{
				DM_stMainObject.u8DrvModStates = STATE_LOGIC_FIRST_PROCESS;
			}
			else
			{
				// wait until 3s reached
			}

			break;
		case STATE_LOGIC_FIRST_PROCESS:
			if (DM_stAttrTab[DM_stMainObject.u8VehicleIndex].FirstLogicProcess != NULL)
			{
				ret = DM_stAttrTab[DM_stMainObject.u8VehicleIndex].FirstLogicProcess();
			}
			else
			{
				ret = TRUE;
			}

			if (ret)
			{
				DM_stMainObject.u8DrvModStates = STATE_LOGIC_GENERAL_PROCESS;
			}
			else
			{
				// do nothing
			}
			break;
		case STATE_LOGIC_GENERAL_PROCESS:
			if (DM_stAttrTab[DM_stMainObject.u8VehicleIndex].GeneralLogicProcess != NULL)
			{
				(void)DM_stAttrTab[DM_stMainObject.u8VehicleIndex].GeneralLogicProcess();
			}
			else
			{
				// Do nothing but avoid QAC
			}
			break;
		case STATE_TRANSMIT_IGN_OFF:
			if (DM_stAttrTab[DM_stMainObject.u8VehicleIndex].TransExitNormal != NULL)
			{
				ret = DM_stAttrTab[DM_stMainObject.u8VehicleIndex].TransExitNormal();
			}
			else
			{
				// if no function need to call, go to next states
				ret = TRUE;
			}

			if (ret)
			{
				DM_stMainObject.u8DrvModStates = STATE_LOGIC_IDLE;
			}
			else
			{
				// do nothing, wait until ign off deal complete
			}
			break;
		case STATE_LOGIC_IDLE:
			//do nothing, wait ign on
			break;
		default:
			// Static compilation: if the default clause is empty, comments must be added.
			break;

	}

	FDM_Fuel_SecondTrigTimerCount();

	DM_RTE_WarningAndTelltaleStatusUpdata();
	DM_RTE_SBUSUpdateDriveModeTheme();
}


/**********************************************************************************************************
*Function: DM_API_vSetDrvModWarningStatus
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
Std_ReturnType DM_API_vSetDrvModWarningStatus(DM_CFG_enWarningId enDrvModWarningID)
{
	uint8 ret = E_NOT_OK;
	uint8 u8BytePosition = 0;
	uint8 u8BitPosition = 0;

	if (enDrvModWarningID >= DM_enWN_WarningMaxId)
	{
		ret = E_NOT_OK;
	}
	else
	{
		u8BytePosition = (uint8)((uint16)enDrvModWarningID / 8u);
		u8BitPosition = (uint8)((uint16)enDrvModWarningID % 8u);
		DM_stMainObject.u8DrvModWarningControlStatus[u8BytePosition] |=  (uint8)(1u << u8BitPosition);
		ret = E_OK;
	}

	return ret;
}

/**********************************************************************************************************
*Function: DM_API_vClrDrvModWarningStatus
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
Std_ReturnType DM_API_vClrDrvModWarningStatus(uint8 u8DrvModWarningID)
{
	uint8 ret = E_NOT_OK;
	uint8 u8BytePosition = 0;
	uint8 u8BitPosition = 0;

	if (u8DrvModWarningID >= DM_enWN_WarningMaxId)
	{
		ret = E_NOT_OK;
	}
	else
	{
		u8BytePosition = (uint8)(u8DrvModWarningID / 8u);
		u8BitPosition = (uint8)(u8DrvModWarningID % 8u);
		DM_stMainObject.u8DrvModWarningControlStatus[u8BytePosition] &=  ~((uint8)(1u << u8BitPosition));
		ret = E_OK;
	}

	return ret;
}

#if 0
/**********************************************************************************************************
*Function: DM_API_vGetDrvModWarningStatus
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
Std_ReturnType DM_API_GetDrvModWarningStatus(DM_CFG_enWarningId enDrvModWarningID, uint8* warningID, uint8* status)
{
	uint8 ret = E_NOT_OK;
	uint8 i = 0;
	uint8 u8BytePosition = 0;
	uint8 u8BitPosition = 0;

	if (enDrvModWarningID >= DM_enWN_WarningMaxId)
	{
		ret = E_NOT_OK;
	}
	else
	{
		u8BytePosition = enDrvModWarningID/8;
		u8BitPosition = enDrvModWarningID%8;
		*warningID = DM_u8DrvModId2WrnId[enDrvModWarningID];
		*status = (DM_stMainObject.u8DrvModWarningControlStatus[u8BytePosition] >> u8BitPosition) & 0x01;
		ret = E_OK;
	}

	return ret;
}
#endif


/**********************************************************************************************************
*Function: DM_API_vClrAllDrvModWarningStatus
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
void DM_API_vClrAllDrvModWarningStatus(void)
{
	uint8 i = 0;

	for (i = 0; i < (DM_WARNING_CONTROL_SATAUS_BYTE_NUM - 1); i++)
	{
		DM_stMainObject.u8DrvModWarningControlStatus[i] = 0;
	}
}


/**********************************************************************************************************
*Function: DM_API_vSetDrvModFixedStatus
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
Std_ReturnType DM_API_vSetDrvModTTStatus(DM_CFG_enTelltaleId enDrvModTelltaleID)
{
	uint8 ret = E_NOT_OK;

	if (enDrvModTelltaleID >= DM_enTT_TelltaleMaxId)
	{
		ret = E_NOT_OK;
	}
	else
	{
		DM_stMainObject.u8DrvModFixedControlStatus = (uint8)enDrvModTelltaleID;
		ret = E_OK;
	}

	return ret;
}

/**********************************************************************************************************
*Function: DM_API_vSetDrvModAuxStatus
*
*Description: aux prompt, set drive mode config id
*
*Parameter: uint8
*
*Return: void
*
*Author: xxx
*
*Date: 20XX-XX-XX
*
**********************************************************************************************************/
void DM_API_vSetDrvModAuxStatus(uint8 u8DrvModConfigid)
{
	DM_stMainObject.u8DrvModWarningControlStatus[14] = u8DrvModConfigid;
}

/**********************************************************************************************************
*Function: DM_API_vClrDrvModFixedStatus
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
void DM_API_vClrDrvModTTStatus(void)
{
	DM_stMainObject.u8DrvModFixedControlStatus = (uint8)DM_enTT_NONE;
}

#if 0
/**********************************************************************************************************
*Function: DM_API_vGetDrvModFixedStatus
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
Std_ReturnType DM_API_GetDrvModTTStatus(uint8* pTelltaleValue)
{
	*pTelltaleValue = DM_stMainObject.u8DrvModFixedControlStatus;
	return E_OK;
}
#endif

/**********************************************************************************************************
*Function: DM_API_vSetHybridModTTStatus
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: xxx
*
*Date: 2021-08-12
*
**********************************************************************************************************/
Std_ReturnType DM_API_vSetHybridModTTStatus(DM_HMCFG_enTelltaleId enHybModTelltaleID)
{
	uint8 ret = E_NOT_OK;

	if (enHybModTelltaleID >= DM_enTT_HMTelltaleMaxId)
	{
		ret = E_NOT_OK;
	}
	else
	{
		DM_stMainObject.u8HybridModControlStatus = (uint8)enHybModTelltaleID;
		ret = E_OK;
	}

	return ret;
}

/**********************************************************************************************************
*Function: DM_API_vClrHybridModTTStatus
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: xxx
*
*Date: 2021-08-12
*
**********************************************************************************************************/
void DM_API_vClrHybridModTTStatus(void)
{
	DM_stMainObject.u8HybridModControlStatus = (uint8)DM_enTT_HMNONE;
}

/**********************************************************************************************************
*Function: DM_API_vSetDrvModSignal
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: xxx
*
*Date: 2022-01-08
*
**********************************************************************************************************/
void DM_API_vSetDrvModSwitchSignal(uint8 u8DrvMod, uint8 u8IMCActv)
{
	DM_strSignalOut.u8DrvModSigValue = u8DrvMod;
	DM_strSignalOut.u8IMCActvSigValue = u8IMCActv;
}

/**********************************************************************************************************
*Function: DM_API_vSetDrvModVehType
*
*Description: TBD
*
*Parameter: TBD
*
*Return: TBD
*
*Author: xxx
*
*Date: 2022-01-08
*
**********************************************************************************************************/
void DM_API_vSetDrvModVehType(uint8 u8VehType)
{
	DM_strSignalOut.u8DrvModVehType = u8VehType;
}

static void DM_RTE_WarningAndTelltaleStatusUpdata(void)
{

	DM_tstDrvModStatusRecord stDrvModStatusRecordBuff = {0};

	stDrvModStatusRecordBuff.TelltaleStatus = DM_stMainObject.u8DrvModFixedControlStatus;

	(void) memset(stDrvModStatusRecordBuff.WarningStatus, 0, sizeof(stDrvModStatusRecordBuff.WarningStatus)/sizeof(uint8));
	if (DM_WARNING_CONTROL_SATAUS_BYTE_NUM <= 15)
	{
		(void) memcpy(stDrvModStatusRecordBuff.WarningStatus, DM_stMainObject.u8DrvModWarningControlStatus, sizeof(DM_stMainObject.u8DrvModWarningControlStatus)/sizeof(uint8));
	}

	(void) Rte_Write_ppSR_SWCNormal_DrvModStatusRecord_Element(&stDrvModStatusRecordBuff);

}

static void DM_RTE_SBUSUpdateDriveModeTheme(void)
{
	uint8 u8DrivingModeValue_temp = 0;
	uint8 u8HybridModeValue_temp = 0;
	uint8 u8DriveModePowerMode = 0;
	SystemState_RecordType Power_State;

	(void) memcpy(&Power_State,Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut(),sizeof(SystemState_RecordType));
	u8DriveModePowerMode = Power_State.ClusterState;
	u8DrivingModeValue_temp = DM_stMainObject.u8DrvModFixedControlStatus;
	u8HybridModeValue_temp = DM_stMainObject.u8HybridModControlStatus;

	if (u8DriveModePowerMode == SYSTEMSTATE_Cluster_ON)
	{
		ToSBUS_DM_DriveMode.u_DriveModeu8DriveMode_data_t.s_u8DriveMode_data_t.DriveMode_Data = (u8DrivingModeValue_temp > 0) ? 1u : 0u;
		ToSBUS_DM_DriveMode.u_DriveModeu8DriveMode_data_t.s_u8DriveMode_data_t.DriveMode_Value = u8DrivingModeValue_temp;
		ToSBUS_DM_DriveMode.u_DriveModeu8DriveMode_data_t.s_u8DriveMode_data_t.HybridMode_Data = (u8HybridModeValue_temp > 0) ? 1u : 0u;
		ToSBUS_DM_DriveMode.u_DriveModeu8DriveMode_data_t.s_u8DriveMode_data_t.HybridMde_Value = u8HybridModeValue_temp;
	}
	else
	{
		ToSBUS_DM_DriveMode.u_DriveModeu8DriveMode_data_t.s_u8DriveMode_data_t.DriveMode_Data = 0;
		ToSBUS_DM_DriveMode.u_DriveModeu8DriveMode_data_t.s_u8DriveMode_data_t.HybridMode_Data = 0;
	}
	ToSBUS_DM_DriveMode.u_DriveModeu8DriveMode_data_t.s_u8DriveMode_data_t.DriveMode_Data_selfcheck = 0;
	ToSBUS_DM_DriveMode.u_DriveModeu8DriveMode_data_t.s_u8DriveMode_data_t.HybridMode_Data_selfcheck = 0;

	ToSBUS_DM_DriveMode.u_DriveModeu8DriveMode_data_t.s_u8DriveMode_data_t.DrvModSignal_Value = DM_strSignalOut.u8DrvModSigValue;
	ToSBUS_DM_DriveMode.u_DriveModeu8DriveMode_data_t.s_u8DriveMode_data_t.IMCActvSignal_Value = DM_strSignalOut.u8IMCActvSigValue;
	ToSBUS_DM_DriveMode.u_DriveModeu8DriveMode_data_t.s_u8DriveMode_data_t.DrvModVehType = DM_strSignalOut.u8DrvModVehType;

    (void) Rte_Call_IPC_Send_IPC_Send((uint8)M2S_DRIVE_MODE_RESP,(uint8*)&ToSBUS_DM_DriveMode,(uint16)sizeof(IPC_M2S_ClusterAppAPPDriveMode_t),FALSE);
}

#define Common_Normal_STOP_SEC_CODE
#include  "Common_Normal_MemMap.h"

