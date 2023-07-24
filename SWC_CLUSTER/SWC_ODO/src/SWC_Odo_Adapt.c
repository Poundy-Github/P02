/**********************************************************************************************************
*                                                                                                         *
*                          CONFIDENTIAL NOBO CORPORATION                              					  *
*                                                                                                         *
* Copyright @ 2019 - 2021 Nobo Automotive Technologies Co.,Ltd.                                           *
* All Rights Reserved.                                                                                    *
*                                                                                                         *
* Redistribution and use in source and binary forms, with or without                                      *
* modification, are NOT permitted except as agreed by                                                     *
* Nobo Automotive Technologies Co.,Ltd.                                                                   *
*                                                                                                         *
* Unless required by applicable law or agreed to in writing, software                                     *
* distributed under the License is distributed on an "AS IS" BASIS,                                       *
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.                                *
*                                                                                                         *
**********************************************************************************************************/
/**
**  Name:               SWC_Odo_Interface.c
**
**  Description:        Odo moudle interface file to oher.Include init and get Odo data 
**
**  Organization:       
**
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
//#include "VConfig.h"
#include "VConfig_CFG.h"
#include "string.h"
#include "Rte_Common_Normal.h"
#include "SWC_Ipc_Config.h"
#include "IPC_ClusterApp.h"
#include "logger.h"
#include "logger_cfg.h"

#include "Csm_Cfg.h"
#include "CConfig_Cfg.h"
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Odo_Adapt.h"
#include "SWC_Odo_Interface.h"
#include "SWC_Fsrv_Process.h"
#include "SWC_odo_interface_cfg.h"
#include "SWC_odo_pkg.h"

/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/
/**********************************************************************************************************
* Parament                                                                                                *
**********************************************************************************************************/
#define TEST_DATA_FOR_BULID
#ifdef TEST_DATA_FOR_BULID
/**********************************************************************************************************
*                                                                                                         *
*                                                                                                         *
*   Odo test init parament                                                                                *
*                                                                                                         *
*                                                                                                         *
**********************************************************************************************************/
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
// TODO: < REPLACE START >
#define COM_PDU_OK                                      (1u)
#define SWC_ODO_GET_CAN_ID(id)							COM_PDU_OK//Com_GetRxPduStatus(id)
#define SWC_ODO_GET_CAN_SIGNAL(id,dataadr)				do{*dataadr = 0;}while(0);//Com_ReceiveSignal(id,dataadr)
#define SWC_ODO_GET_CONFIGURATION(id,dataadr)			VConfig_GetKindConfig(id,dataadr)
// TODO: < REPLACE END >

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_ODO_START_SEC_VAR_RETENTION
#include "SWC_Odo_MemMap.h"
#if 0
s_OdoBackupValue_t Odo_OdoNvmDataBackup_u32[3] = 
{
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
};

uint8 Odo_OdoNvmDataBackIndex_u8 = 0;

uint8 Odo_OdoNvmDataBackUpFlag_u8 = 0;

uint8 Odo_OdoNvmDataTest_u8[5][4] = 
{
	{0x06, 0x00, 0xff, 0x80},
	{0x06, 0x00, 0xff, 0x80},
	{0x06, 0x00, 0xff, 0x80},
	{0x06, 0x00, 0xff, 0x80},
	{0x06, 0x00, 0xff, 0x80}
};
uint32 Odo_TripNvmDataTest_u32[3] = 
{
	0x80,0x80,0x80
};
	
uint8 Odo_ResetNvmDataTest_u8= 0xFF;
uint8 Odo_ResetNvmNumber_u8= 0x1;


uint32 Odo_FsrvValue_u32 = 5000;

uint32 Odo_FsrvDefaultValue_u32 = 5000;
#endif

#define SWC_ODO_STOP_SEC_VAR_RETENTION
#include "SWC_Odo_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_ODO_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Odo_MemMap.h"
static s_OdoTimerValue_t Odo_TimerTblTest_u32[e_OdoTimerMax];
static s_OdoConfiguration_t OdoConfiguration_s;
static uint8 Odo_ReadSleepTimeFlag_u8;
static uint8 Odo_ClearWriteResultFlag_u8[e_OdoBlock_ODO_NVM_BLOCK_ALL];
static s_OdoWriteCallback_t OdoBlockWriteCallback_s[e_OdoBlock_ODO_NVM_BLOCK_ALL];
/**********************************************************************************************************
* HSM Paramemter                                                                                          *
**********************************************************************************************************/
static uint8 OdoHsmKeyRamData[2][32];
static s_OdoRealDataRam_t OdoHsmRealDataRam_s[ODO_PKG_NUMBER_OF_ODO_SETS];
static uint8 OdoHsmTripDataRam[20];
static uint8 OdoHsmMaintainOdoDataRam[80];
static s_OdoRealDataRam_t OdoHsmEncryptRam_s[ODO_PKG_NUMBER_OF_ODO_SETS];
static s_OdoRealDataRam_t OdoHsmDecryptRam_s;
static e_OdoHsmCrypt_t OdoHsmEncryptRam_Sts;
static e_OdoHsmCrypt_t OdoHsmDecryptRam_Sts;
static uint8 OdoHsmDefaultRam_Flag;
static uint8 OdoHsmEncryptRam_Flag;
static uint8 OdoHsmDecryptRam_Flag;
static e_OdoHSMStatus_t Odo_HsmDefaultStatus;
static uint32 OdoHsmDefaultConstLen;
static uint8 OdoMenoryPrintfCounter;
/**********************************************************************************************************
* END Paramemter                                                                                          *
**********************************************************************************************************/

#define SWC_ODO_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Odo_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_ODO_START_SEC_CONST_UNSPECIFIED
#include "SWC_Odo_MemMap.h"

static const u_NVMBlockOdoAdr_t Odo_NvmBlockTbl[e_OdoBlock_ODO_NVM_BLOCK_ALL] = 
{
	{(uint8 *)Rte_Pim_NvBlockNeed_Block_ODO_1_MirrorBlock(),
	OdoHsmRealDataRam_s[0].OdoRamData,
	OdoHsmEncryptRam_s[0].OdoRamData,
	(const uint8 *)Rte_CData_NvBlockNeed_Block_ODO_1_DefaultValue(),
	16,
	Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_GetErrorStatus,
	Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock,
	&OdoBlockWriteCallback_s[e_OdoBlock_ODO1_NVM_BLOCK]
	},
	/*---------------------------------------------------------------------------*/
	{(uint8 *)Rte_Pim_NvBlockNeed_Block_ODO_2_MirrorBlock(),
	OdoHsmRealDataRam_s[1].OdoRamData,
	OdoHsmEncryptRam_s[1].OdoRamData,
	(const uint8 *)Rte_CData_NvBlockNeed_Block_ODO_2_DefaultValue(),
	16,
	Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_GetErrorStatus,
	Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock,
	&OdoBlockWriteCallback_s[e_OdoBlock_ODO2_NVM_BLOCK]
	},
	/*---------------------------------------------------------------------------*/
	{(uint8 *)Rte_Pim_NvBlockNeed_Block_ODO_3_MirrorBlock(),
	OdoHsmRealDataRam_s[2].OdoRamData,
	OdoHsmEncryptRam_s[2].OdoRamData,
	(const uint8 *)Rte_CData_NvBlockNeed_Block_ODO_3_DefaultValue(),
	16,
	Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_GetErrorStatus,
	Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock,
	&OdoBlockWriteCallback_s[e_OdoBlock_ODO3_NVM_BLOCK]
	},
	/*---------------------------------------------------------------------------*/
	{(uint8 *)Rte_Pim_NvBlockNeed_Block_ODO_4_MirrorBlock(),
	OdoHsmRealDataRam_s[3].OdoRamData,
	OdoHsmEncryptRam_s[3].OdoRamData,
	(const uint8 *)Rte_CData_NvBlockNeed_Block_ODO_4_DefaultValue(),
	16,
	Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_GetErrorStatus,
	Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock,
	&OdoBlockWriteCallback_s[e_OdoBlock_ODO4_NVM_BLOCK]
	},
	/*---------------------------------------------------------------------------*/
	{(uint8 *)Rte_Pim_NvBlockNeed_Block_ODO_5_MirrorBlock(),
	OdoHsmRealDataRam_s[4].OdoRamData,
	OdoHsmEncryptRam_s[4].OdoRamData,
	(const uint8 *)Rte_CData_NvBlockNeed_Block_ODO_5_DefaultValue(),
	16,
	Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_GetErrorStatus,
	Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock,
	&OdoBlockWriteCallback_s[e_OdoBlock_ODO5_NVM_BLOCK]
	},
	/*---------------------------------------------------------------------------*/
	{(uint8 *)Rte_Pim_NvBlockNeed_Block_Trip_MirrorBlock(),
	OdoHsmTripDataRam,
	ODO_DATA_NULL_PTRFUN,
	(const uint8 *)Rte_CData_NvBlockNeed_Block_Trip_DefaultValue(),
	20,
	Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_GetErrorStatus,
	Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock,
	&OdoBlockWriteCallback_s[e_OdoBlock_Trip_NVM_BLOCK]
	},
	/*---------------------------------------------------------------------------*/
	{(uint8 *)Rte_Pim_NvBlockNeed_Block_MaintainOdo_MirrorBlock(),
	OdoHsmMaintainOdoDataRam,
	ODO_DATA_NULL_PTRFUN,
	(const uint8 *)Rte_CData_NvBlockNeed_Block_MaintainOdo_DefaultValue(),
	80,
	Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_GetErrorStatus,
	Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock,
	&OdoBlockWriteCallback_s[e_OdoBlock_Matain_NVM_BLOCK]
	},
};

#define SWC_ODO_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_Odo_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
*                                                                                                         *
*                                                                                                         *
*   Odo test zero init parament                                                                           *
*                                                                                                         *
*                                                                                                         *
**********************************************************************************************************/

/**********************************************************************************************************
* End Parament                                                                                            *
**********************************************************************************************************/
#endif

/**********************************************************************************************************
* Function  start                                                                                         *
**********************************************************************************************************/
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_ODO_START_SEC_CODE
#include "SWC_Odo_MemMap.h" 
/**********************************************************************************************************
*Function   : Odo_RteLocalRamInit                                                                         *
*                                                                                                         *
*Description: Init Hsm data                                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_RteLocalRamInit(void)
{
	Odo_RteHSMInitData();
}

/**********************************************************************************************************
*Function   : Odo_InputPowerAbnrmal                                                                       *
*                                                                                                         *
*Description: ODO get power status                                                                        *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : boolean                                                                                     *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Odo_InputPowerAbnrmal(void)
{
	SystemState_RecordType *power_u8;
	
	power_u8 = Rte_IRead_Common_Normal_100msMainFunction_tiSR_Power_Out_SystemStateOut();
	
	if((VOLTAGE_OUT_NORMAL == power_u8->s_PowerVoltage.state) || (VOLTAGE_OUT_LOWALARM == power_u8->s_PowerVoltage.state) || (VOLTAGE_OUT_HIGHALARM == power_u8->s_PowerVoltage.state))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/**********************************************************************************************************
*Function   : Odo_InputPowerOFF                                                                           *
*                                                                                                         *
*Description: ODO get power status                                                                        *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : boolean                                                                                     *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Odo_InputPowerOFF(void)
{
	SystemState_RecordType *power_u8;
	
	power_u8 = Rte_IRead_Common_Normal_100msMainFunction_tiSR_Power_Out_SystemStateOut();
	if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/**********************************************************************************************************
*Function   : Odo_InputPowerIGN                                                                           *
*                                                                                                         *
*Description: ODO get power status                                                                        *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : boolean                                                                                     *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Odo_InputPowerIGN(void)
{
	SystemState_RecordType *power_u8;
	
	power_u8 = Rte_IRead_Common_Normal_100msMainFunction_tiSR_Power_Out_SystemStateOut();
	if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
/**********************************************************************************************************
*Function   : Odo_TripNvmAddr_Get                                                                         *
*                                                                                                         *
*Description: Trip nvm start address by tirp index,Trip nvm is 4byte data                                 *
*                                                                                                         *
*Parameter  : index_u8:Trip index  ,0 ~ 0xff                                                              *
*                                                                                                         *
*Return     : uint32 *,Data address                                                                       *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint32 * Odo_TripNvmAddr_Get(uint8 Index_u8)
{
	uint32 *trip_ptr;
	trip_ptr = (uint32 *)Odo_NvmBlockTbl[5].Local_Ptr;
	return (&trip_ptr[Index_u8]);
}

/**********************************************************************************************************
*Function   : Odo_OdoNvmAddr_Get                                                                          *
*                                                                                                         *
*Description: Odo nvm start address by odo index,Odo nvm is 4byte data                                    *
*                                                                                                         *
*Parameter  : index_u8:Trip index  ,0 ~ 4                                                                 *
*                                                                                                         *
*Return     : uint8 * first byte address                                                                  *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 * Odo_OdoNvmAddr_Get(uint8 Index_u8)
{
	return Odo_NvmBlockTbl[Index_u8].Local_Ptr;
}
/**********************************************************************************************************
*Function   : Odo_OdoClearAddress_Get                                                                     *
*                                                                                                         *
*Description: Odo clear counter address in nvm,value is decrease when odo is clear                        *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint16 * Odo_OdoClearAddress_Get(void)
{
	u_NVMBlockOdoOther_t *OdoNvm;
	OdoNvm = (u_NVMBlockOdoOther_t *)Odo_NvmBlockTbl[6].Local_Ptr;
	return (&OdoNvm->OdoBlock_t.OdoRest);
}
/**********************************************************************************************************
*Function   : Odo_OdoClearLowAddress_Get                                                                  *
*                                                                                                         *
*Description: Odo low clear counter address in nvm,value is decrease when odo is clear                    *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : uint16                                                                                      *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint16 * Odo_OdoClearLowAddress_Get(void)
{
	u_NVMBlockOdoOther_t *OdoNvm;
	OdoNvm = (u_NVMBlockOdoOther_t *)Odo_NvmBlockTbl[6].Local_Ptr;
	return (&OdoNvm->OdoBlock_t.OdoRestLow);
}
/**********************************************************************************************************
*Function   : Odo_OdoOffsetAddress_Get                                                                    *
*                                                                                                         *
*Description: Odo offset address                                                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : uint32 *                                                                                    *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint64 * Odo_OdoOffsetAddress_Get(void)
{
	u_NVMBlockOdoOther_t *OdoNvm;
	OdoNvm = (u_NVMBlockOdoOther_t *)Odo_NvmBlockTbl[6].Local_Ptr;
	return (&OdoNvm->OdoBlock_t.OdoOffset);
}
/**********************************************************************************************************
*Function   : Odo_OdoOffsetFlgAddress_Get                                                                    *
*                                                                                                         *
*Description: Odo offset address                                                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : uint32 *                                                                                    *
*                                                                                                         *
*Author     : Yin hiuzhu                                                                                *
*                                                                                                         *
*Date       : 2022-03-29                                                                                  *
**********************************************************************************************************/
uint8 * Odo_OdoOffsetFlgAddress_Get(void)
{
	u_NVMBlockOdoOther_t *OdoNvm;
	OdoNvm = (u_NVMBlockOdoOther_t *)Odo_NvmBlockTbl[6].Local_Ptr;
	return (&OdoNvm->OdoBlock_t.OdoOffsetFlg);
}

/**********************************************************************************************************
*Function   : Odo_OdoBackupAddr_Get                                                                       *
*                                                                                                         *
*Description: Odo nvm back up need to remember odo and data,this function get address                     *
*                                                                                                         *
*Parameter  : index_u8:ODO  index  ,0 ~ 2                                                                 *
*                                                                                                         *
*Return     : s_OdoBackupValue_t odo back up struct address                                               *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 * Odo_OdoBackupAddr_Get(uint8 Index_u8)
{
	u_NVMBlockOdoOther_t *OdoNvm;
	OdoNvm = (u_NVMBlockOdoOther_t *)Odo_NvmBlockTbl[6].Local_Ptr;
	return ((uint8 *)(&OdoNvm->OdoBlock_t.BcupDate[Index_u8]));
}

/**********************************************************************************************************
*Function   : Odo_OdoBackupFlag_Get                                                                       *
*                                                                                                         *
*Description: Get odo back up flag,if value is true not need to back up ,if value is 0,need to back up    *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : uint8 address                                                                               *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 * Odo_OdoBackupFlag_Get(void)
{
	u_NVMBlockOdoOther_t *OdoNvm;
	OdoNvm = (u_NVMBlockOdoOther_t *)Odo_NvmBlockTbl[6].Local_Ptr;
	return (&OdoNvm->OdoBlock_t.BcupFlg);
}

/**********************************************************************************************************
*Function   : Odo_OdoBackupIndex_Get                                                                      *
*                                                                                                         *
*Description: Odo nvm back up need to remember odo and data,this is data index                            *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : uint8 *                                                                                     *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 * Odo_OdoBackupIndex_Get(void)
{
	u_NVMBlockOdoOther_t *OdoNvm;
	OdoNvm = (u_NVMBlockOdoOther_t *)Odo_NvmBlockTbl[6].Local_Ptr;
	return (&OdoNvm->OdoBlock_t.BcupIdx);
}

/**********************************************************************************************************
*Function   : Odo_FsrvValueAddr_Get                                                                       *
*                                                                                                         *
*Description: Fsrv nvm value address                                                                      *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : uint32 *                                                                                    *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-07-07                                                                                  *
**********************************************************************************************************/
uint32 * Odo_FsrvValueAddr_Get(void)
{
	u_NVMBlockOdoOther_t *OdoNvm;
	OdoNvm = (u_NVMBlockOdoOther_t *)Odo_NvmBlockTbl[6].Local_Ptr;
	return (&OdoNvm->OdoBlock_t.Fsrv);
}
/**********************************************************************************************************
*Function   : Odo_FsrvDefaultValueAddr_Get                                                                *
*                                                                                                         *
*Description: Fsrv nvm default value address                                                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : uint32 *                                                                                    *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-07-07                                                                                  *
**********************************************************************************************************/
uint16 * Odo_FsrvDefaultValueAddr_Get(void)
{
	u_NVMBlockOdoOther_t *OdoNvm;
	OdoNvm = (u_NVMBlockOdoOther_t *)Odo_NvmBlockTbl[6].Local_Ptr;
	return (&OdoNvm->OdoBlock_t.DefFsrv);
}

/**********************************************************************************************************
*Function   : Odo_GetBlockWriteCallback                                                                   *
*                                                                                                         *
*Description: Block callbback get                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : uint32 *                                                                                    *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-07-07                                                                                  *
**********************************************************************************************************/
s_OdoWriteCallback_t Odo_GetBlockWriteCallback(uint8 index)
{
	s_OdoWriteCallback_t Fun = {ODO_ADAPT_NULL_PTRFUN};
	if(index < e_OdoBlock_ODO_NVM_BLOCK_ALL)
	{
		Fun = OdoBlockWriteCallback_s[index];
	}
	return Fun;
}

/**********************************************************************************************************
*Function   : Odo_GetCommonStatus                                                                         *
*                                                                                                         *
*Description: NVM is good interface                                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : boolean  TRUE: good ;FALSE: Not good                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Odo_GetCommonStatus(void)
{
	return TRUE;
}
/**********************************************************************************************************
*Function   : Odo_NvmBoWriteWithCallback                                                                  *
*                                                                                                         *
*Description: Nvm write interface                                                                         *
*                                                                                                         *
*Parameter  : Tar_u8: nvm target address                                                                  *
*             Cur_u8: write data address                                                                  *
*             size_u8: write length                                                                       *
*             Function: write callback function                                                           *
*Return     : boolean,TRUE:write success FALSE:write failure                                              *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Odo_NvmBoWriteWithCallback(uint8 *Tar_u8,uint8 *Cur_u8, uint8 Size_u8, void (* Function)(boolean Status_u8))
{
	uint8 temp;
	//uint32 WruteLen = 16;
	//s_OdoRealDataRam_t ptr;

	for(temp = 0;temp < e_OdoBlock_ODO_NVM_BLOCK_ALL;temp ++)
	{
		if((Tar_u8 >= Odo_NvmBlockTbl[temp].Local_Ptr) && (Tar_u8 < (Odo_NvmBlockTbl[temp].Local_Ptr + Odo_NvmBlockTbl[temp].Size)))
		{
			(void)memcpy(Tar_u8,Cur_u8,Size_u8);
			Odo_Api_RteNvmWrite_Set(temp,TRUE);
			if(temp < ODO_PKG_NUMBER_OF_ODO_SETS)
			{
				OdoHsmEncryptRam_Flag |= (0x01u << temp);
			}
			Odo_NvmBlockTbl[temp].callback->Process = Function;
			SWC_ODO_INFO_LOG("block d% write request",temp);
			break;
		}
	}
	return TRUE;
}
/**********************************************************************************************************
*Function   : Odo_NvmBoWrite                                                                              *
*                                                                                                         *
*Description: Nvm write interface                                                                         *
*                                                                                                         *
*Parameter  : Tar_u8: nvm target address                                                                  *
*             Cur_u8: write data address                                                                  *
*             size_u8: write length                                                                       *
*                                                                                                         *
*Return     : boolean,TRUE:write success FALSE:write failure                                              *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_NvmBoWrite(uint8 *Tar_u8, const uint8 *Cur_u8, uint8 Size_u8)
{
	uint8 temp;

	for(temp = 0;temp < e_OdoBlock_ODO_NVM_BLOCK_ALL;temp ++)
	{
		if((Tar_u8 >= Odo_NvmBlockTbl[temp].Local_Ptr) && (Tar_u8 < (Odo_NvmBlockTbl[temp].Local_Ptr + Odo_NvmBlockTbl[temp].Size)))
		{
			(void)memcpy(Tar_u8,Cur_u8,Size_u8);
			Odo_Api_RteNvmWrite_Set(temp,TRUE);
			if(temp < ODO_PKG_NUMBER_OF_ODO_SETS)
			{
				OdoHsmEncryptRam_Flag |= (0x01u << temp);
			}
			Odo_NvmBlockTbl[temp].callback->Process = ODO_ADAPT_NULL_PTRFUN;
			SWC_ODO_INFO_LOG("block d% write request",temp);
			break;
		}
	}

}
/**********************************************************************************************************
*Function   : Odo_NvmVolatileWrite                                                                        *
*                                                                                                         *
*Description: Date Zoom out function                                                                      *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Odo_NvmVolatileWrite(uint8 *Tar_u8,uint8 *Cur_u8, uint8 Size_u8)
{
	uint8 temp;
	for(temp = 0;temp < e_OdoBlock_ODO_NVM_BLOCK_ALL;temp ++)
	{
		if((Tar_u8 >= Odo_NvmBlockTbl[temp].Local_Ptr) &&(Tar_u8 < (Odo_NvmBlockTbl[temp].Local_Ptr + Odo_NvmBlockTbl[temp].Size)))
		{
			(void)memcpy(Tar_u8,Cur_u8,Size_u8);
			Odo_Api_RteNvmWrite_Set(temp,TRUE);
			if(temp < ODO_PKG_NUMBER_OF_ODO_SETS)
			{
				OdoHsmEncryptRam_Flag |= (0x01u << temp);
			}
			Odo_NvmBlockTbl[temp].callback->Process = ODO_ADAPT_NULL_PTRFUN;
			SWC_ODO_INFO_LOG("block d% write request",temp);
			break;
		}
	}
	return TRUE;
}
/**********************************************************************************************************
*Function   : KernelReportError                                                                           *
*                                                                                                         *
*Description: Error report to system,right before not use                                                 *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
#if 0
void KernelReportError(uint8 Msg_u8)
{
	//for fix The parameter "Msg_u8" is not used in the function
}
#endif
/**********************************************************************************************************
*Function   : Odo_OstmTimerStart                                                                          *
*                                                                                                         *
*Description: system timer start                                                                          *
*                                                                                                         *
*Parameter  : Index_u8:timer index;   Over_u16: Over time                                                 *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_OstmTimerStart(uint8 Index_u8,uint32 Over_u32)
{
	uint8 status;
	status = Rte_Call_Os_Service_GetCounterValue(&Odo_TimerTblTest_u32[Index_u8].OdoStartTime_u32);
	if(RTE_E_Os_Service_E_OK == status)
	{
		Odo_TimerTblTest_u32[Index_u8].OdoOverTime_u32 = Over_u32;
		Odo_TimerTblTest_u32[Index_u8].OdoStatus = ODO_OSTM_TIMER_RUNING;
	}
	else
	{
		Odo_TimerTblTest_u32[Index_u8].OdoOverTime_u32 = Over_u32;
		Odo_TimerTblTest_u32[Index_u8].OdoStatus = ODO_OSTM_TIMER_START_ERROR;
	}
}
/**********************************************************************************************************
*Function   : Odo_OstmTimerCheck                                                                          *
*                                                                                                         *
*Description: system timer check                                                                          *
*                                                                                                         *
*Parameter  : Index_u8:timer index;                                                                       *
*                                                                                                         *
*Return     : uint8:Timer check status                                                                    *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 Odo_OstmTimerCheck(uint8 Index_u8)
{
	uint8 status;
	uint8 os_sts;
	uint32 passTime;
	uint32 oldTime;
	if(ODO_OSTM_TIMER_CLEAR == Odo_TimerTblTest_u32[Index_u8].OdoStatus)
	{
		status = ODO_OSTM_TIMER_CLEAR;
	}
	else if(ODO_OSTM_TIMER_START_ERROR == Odo_TimerTblTest_u32[Index_u8].OdoStatus)
	{
		Odo_OstmTimerStart(Index_u8,Odo_TimerTblTest_u32[Index_u8].OdoOverTime_u32);
		status = ODO_OSTM_TIMER_START_ERROR;
	}
	else
	{
		oldTime = Odo_TimerTblTest_u32[Index_u8].OdoStartTime_u32;
		os_sts = Rte_Call_Os_Service_GetElapsedValue(&oldTime,&passTime);
		if((RTE_E_Os_Service_E_OK == os_sts) && (passTime >= Odo_TimerTblTest_u32[Index_u8].OdoOverTime_u32))
		{
			status = ODO_OSTM_TIMER_OVER;
		}
		else 
		{
			status = ODO_OSTM_TIMER_RUNING;
		}
	}
	return status;
}
/**********************************************************************************************************
*Function   : Odo_OstmTimerStop                                                                           *
*                                                                                                         *
*Description: system timer stop                                                                           *
*                                                                                                         *
*Parameter  : Index_u8:timer index;                                                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_OstmTimerStop(uint8 Index_u8)
{
	Odo_TimerTblTest_u32[Index_u8].OdoStatus = ODO_OSTM_TIMER_CLEAR;
}

/**********************************************************************************************************
*Function   : Odo_OstmTimerReferenceProcess                                                               *
*                                                                                                         *
*Description: system timer reference                                                                      *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_OstmTimerReferenceProcess(void)
{
	//Ood_OstmTickReference_u64 ++;
}

/**********************************************************************************************************
*Function   : Odo_OdoBackupVinEnalbe_Get                                                                  *
*                                                                                                         *
*Description: Get backup configuration before sop,not need to open                                        *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : boolean TRUE: VIN Backup enable                                                             *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Odo_OdoBackupVinEnalbe_Get(void)
{
	s_OdoConfiguration_t condfig_s = Odo_ApiGetConfiguration();
	uint8 config_u8;
	boolean VinEnable_bool = FALSE;
	
	config_u8 = condfig_s.Vconfig_KIND_ENGINE_CONTROL_UNIT;
	if((config_u8 >= 1) && (config_u8 <= 7))
	{
		VinEnable_bool = TRUE;
	}
	else
	{
		VinEnable_bool = FALSE;
	}
	return VinEnable_bool;
}

/**********************************************************************************************************
*Function   : Odo_OdoBackupVinCfgValue_Get                                                                *
*                                                                                                         *
*Description: Get backup configuration value                                                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : uint8: VIN Backup value                                                                     *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
s_NVMVincfgCompareData_t Odo_OdoBackupVinCfgValue_Get(void)
{
	s_OdoConfiguration_t condfig_s = Odo_ApiGetConfiguration();
	s_NVMVincfgCompareData_t vin;

	(void)memcpy(vin.vincfgC_u8,&condfig_s.Vconfig_Vinconfig[9],sizeof(s_NVMVincfgCompareData_t));
	return vin;
}

/**********************************************************************************************************
*Function   : Odo_VINMessageInputEnable                                                                   *
*                                                                                                         *
*Description: VIN message inable ,if message is missing or never receive return false                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : boolean TRUE: VIN message enable                                                            *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 Odo_VINMessageInputEnable(void)
{
	uint8 vin[8];
	uint8 status;
#if (ODO_PROJECT_TYPE_B02 == 1)
 #ifdef COMEX_SIGNAL_RX_ECM_VIN
	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VIN,vin,(uint8)sizeof(vin)); 
	if((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status))
	{
		status = ODO_TRUE;
	}
	else
	{
		status = ODO_FALSE;
	}
	return status;
 #else
	return ODO_FALSE;
 #endif
#elif(ODO_PROJECT_TYPE_P05 == 1)
 #ifdef COMEX_SIGNAL_RX_ECM_VIN
	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VIN,vin,(uint8)sizeof(vin)); 
	if((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status))
	{
		status = ODO_TRUE;
	}
	else
	{
		status = ODO_FALSE;
	}
	return status;
 #else
	return ODO_FALSE;
 #endif
#elif(ODO_PROJECT_TYPE_P03 == 1)
 #ifdef COMEX_SIGNAL_RX_ECM_VIN
	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VIN,vin,(uint8)sizeof(vin)); 
	if((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status))
	{
		status = ODO_TRUE;
	}
	else
	{
		status = ODO_FALSE;
	}
	return status;
 #else
	return ODO_FALSE;
 #endif
#elif (ODO_PROJECT_TYPE_A07 == 1)
 #ifdef COMEX_SIGNAL_RX_ECM_VIN
		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VIN,vin,(uint8)sizeof(vin)); 
		if((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status))
		{
			status = ODO_TRUE;
		}
		else
		{
			status = ODO_FALSE;
		}
		return status;
 #else
		return ODO_FALSE;
 #endif
 #elif (ODO_PROJECT_TYPE_D01 == 1)
 #ifdef COMEX_SIGNAL_RX_ECM_VIN
		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VIN,vin,(uint8)sizeof(vin)); 
		if((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status))
		{
			status = ODO_TRUE;
		}
		else
		{
			status = ODO_FALSE;
		}
		return status;
 #else
		return ODO_FALSE;
 #endif
  #elif (ODO_PROJECT_TYPE_D02 == 1)
 #ifdef COMEX_SIGNAL_RX_ECM_VIN
		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VIN,vin,(uint8)sizeof(vin)); 
		if((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status))
		{
			status = ODO_TRUE;
		}
		else
		{
			status = ODO_FALSE;
		}
		return status;
 #else
		return ODO_FALSE;
 #endif
  #elif (ODO_PROJECT_TYPE_D03 == 1)
 #ifdef COMEX_SIGNAL_RX_ECM_VIN
		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VIN,vin,(uint8)sizeof(vin)); 
		if((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status))
		{
			status = ODO_TRUE;
		}
		else
		{
			status = ODO_FALSE;
		}
		return status;
 #else
		return ODO_FALSE;
 #endif
  #elif (ODO_PROJECT_TYPE_P02 == 1)
 #ifdef COMEX_SIGNAL_RX_ECM_VIN
		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VIN,vin,(uint8)sizeof(vin)); 
		if((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status))
		{
			status = ODO_TRUE;
		}
		else
		{
			status = ODO_FALSE;
		}
		return status;
 #else
		return ODO_FALSE;
 #endif
  #elif (ODO_PROJECT_TYPE_P01 == 1)
 #ifdef COMEX_SIGNAL_RX_ECM_VIN
		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VIN,vin,(uint8)sizeof(vin)); 
		if((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status))
		{
			status = ODO_TRUE;
		}
		else
		{
			status = ODO_FALSE;
		}
		return status;
 #else
		return ODO_FALSE;
 #endif
#else
 #ifdef Rte_Read_ECM_VIN_ECM19_0x3B5
 	status = Rte_Read_ECM_VIN_ECM19_0x3B5(vin);
	if(RTE_E_OK == status)
	{
		status = ODO_TRUE;
	}
	else
	{
		status = ODO_FALSE;
	}
	return status;
 #else
	return ODO_FALSE;
 #endif
#endif
}

/**********************************************************************************************************
*Function   : Odo_VINMessageInputValue                                                                    *
*                                                                                                         *
*Description: VIN message value                                                                           *
*                                                                                                         *
*Parameter  : void;                                                                                       *
*                                                                                                         *
*Return     : VIN message  value                                                                          *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
s_NVMVincfgCompareData_t Odo_VINMessageInputValue(void)
{
	s_NVMVincfgCompareData_t vin = {0};
#if (ODO_PROJECT_TYPE_B02 == 1)
 #ifdef COMEX_SIGNAL_RX_ECM_VIN
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VIN,vin.vincfgC_u8,(uint8)sizeof(vin));
	return vin;
 #else
	return vin;
 #endif
#elif(ODO_PROJECT_TYPE_P05 == 1u)
 #ifdef COMEX_SIGNAL_RX_ECM_VIN
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VIN,vin.vincfgC_u8,(uint8)sizeof(vin));
	return vin;
 #else
	return vin;
 #endif
#elif(ODO_PROJECT_TYPE_P03 == 1u)
 #ifdef COMEX_SIGNAL_RX_ECM_VIN
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VIN,vin.vincfgC_u8,(uint8)sizeof(vin));
	return vin;
 #else
	return vin;
 #endif
#elif (ODO_PROJECT_TYPE_A07 == 1u)
 #ifdef COMEX_SIGNAL_RX_ECM_VIN
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VIN,vin.vincfgC_u8,(uint8)sizeof(vin));
	return vin;
 #else
	return vin;
 #endif
 #elif (ODO_PROJECT_TYPE_D01 == 1u)
 #ifdef COMEX_SIGNAL_RX_ECM_VIN
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VIN,vin.vincfgC_u8,(uint8)sizeof(vin));
	return vin;
 #else
	return vin;
 #endif
 #elif (ODO_PROJECT_TYPE_D02 == 1u)
 #ifdef COMEX_SIGNAL_RX_ECM_VIN
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VIN,vin.vincfgC_u8,(uint8)sizeof(vin));
	return vin;
 #else
	return vin;
 #endif
 #elif (ODO_PROJECT_TYPE_D03 == 1u)
 #ifdef COMEX_SIGNAL_RX_ECM_VIN
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VIN,vin.vincfgC_u8,(uint8)sizeof(vin));
	return vin;
 #else
	return vin;
 #endif
 #elif (ODO_PROJECT_TYPE_P02 == 1u)
 #ifdef COMEX_SIGNAL_RX_ECM_VIN
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VIN,vin.vincfgC_u8,(uint8)sizeof(vin));
	return vin;
 #else
	return vin;
 #endif
 #elif (ODO_PROJECT_TYPE_P01 == 1u)
 #ifdef COMEX_SIGNAL_RX_ECM_VIN
	(void)Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VIN,vin.vincfgC_u8,(uint8)sizeof(vin));
	return vin;
 #else
	return vin;
 #endif
#else
 #ifdef Rte_Read_ECM_VIN_ECM19_0x3B5
	(void)Rte_Read_ECM_VIN_ECM19_0x3B5(vin.vincfgC_u8);
	return vin;
 #else
	return vin;
 #endif
#endif
}

/**********************************************************************************************************
*Function   : Odo_GetECMOdoValueEnable                                                                    *
*                                                                                                         *
*Description: get odo value                                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : boolean TRUE: ODO message enable                                                            *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 Odo_GetECMOdoValueEnable(void)
{
	ECM_VehDstBackup signal;
	uint8 status;
#if (ODO_PROJECT_TYPE_B02 == 1)
 #ifdef COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP
	
	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
	if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (signal < 0x989680))
	{
		status = ODO_TRUE;
	}
	else
	{
		status = ODO_FALSE;
	}
	return status;
 #else 
	return FALSE;
 #endif
#elif(ODO_PROJECT_TYPE_P05 == 1u)
 #ifdef COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP
	
	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
	if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (signal < 0x989680))
	{
		status = ODO_TRUE;
	}
	else
	{
		status = ODO_FALSE;
	}
	return status;
 #else 
	return FALSE;
 #endif
#elif(ODO_PROJECT_TYPE_P03 == 1u)
 #ifdef COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP
	
	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
	if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (signal < 0x989680))
	{
		status = ODO_TRUE;
	}
	else
	{
		status = ODO_FALSE;
	}
	return status;
 #else 
	return FALSE;
 #endif
#elif(ODO_PROJECT_TYPE_A07 == 1u)
 #ifdef COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP
		
		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
		if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (signal < 0x989680))
		{
			status = ODO_TRUE;
		}
		else
		{
			status = ODO_FALSE;
		}
		return status;
 #else 
		return FALSE;
 #endif
 #elif(ODO_PROJECT_TYPE_D01 == 1u)
 #ifdef COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP
		
		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
		if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (signal < 0x989680))
		{
			status = ODO_TRUE;
		}
		else
		{
			status = ODO_FALSE;
		}
		return status;
 #else 
		return FALSE;
 #endif
  #elif(ODO_PROJECT_TYPE_D02 == 1u)
 #ifdef COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP
		
		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
		if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (signal < 0x989680))
		{
			status = ODO_TRUE;
		}
		else
		{
			status = ODO_FALSE;
		}
		return status;
 #else 
		return FALSE;
 #endif
  #elif(ODO_PROJECT_TYPE_D03 == 1u)
 #ifdef COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP
		
		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
		if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (signal < 0x989680))
		{
			status = ODO_TRUE;
		}
		else
		{
			status = ODO_FALSE;
		}
		return status;
 #else 
		return FALSE;
 #endif
  #elif(ODO_PROJECT_TYPE_P02 == 1u)
 #ifdef COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP
		
		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
		if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (signal < 0x989680))
		{
			status = ODO_TRUE;
		}
		else
		{
			status = ODO_FALSE;
		}
		return status;
 #else 
		return FALSE;
 #endif
 #elif(ODO_PROJECT_TYPE_P01 == 1u)
 #ifdef COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP
		
		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
		if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (signal < 0x989680))
		{
			status = ODO_TRUE;
		}
		else
		{
			status = ODO_FALSE;
		}
		return status;
 #else 
		return FALSE;
 #endif
#else
 #ifdef Rte_Read_ECM_VehDstBackup_ECM_VehDstBackup
	
	status = Rte_Read_ECM_VehDstBackup_ECM_VehDstBackup(&signal);
	if(((status & RTE_E_NEVER_RECEIVED) != RTE_E_NEVER_RECEIVED) && (signal < 0x989680))
	{
		status = ODO_TRUE;
	}
	else
	{
		status = ODO_FALSE;
	}
	return status;
 #else 
	return FALSE;
 #endif
#endif
}

/**********************************************************************************************************
*Function   : Odo_GetECMOdoValue                                                                          *
*                                                                                                         *
*Description: get odo value                                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : ODO message value                                                                           *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint32 Odo_GetECMOdoValue(void)
{
	ECM_VehDstBackup signal;
	uint8 status;
#if (ODO_PROJECT_TYPE_B02 == 1)
 #ifdef COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP
 	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
 	if(((status & RTE_E_NEVER_RECEIVED) != RTE_E_NEVER_RECEIVED) && (signal < 0x989680))
	{
	}
	else
	{
		signal = 0xffffffff;
	}
	return signal;
	#endif
#elif(ODO_PROJECT_TYPE_P05 == 1u)
	#ifdef COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP
 		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
 	return signal;
 	#else 
 	return 0;
	#endif
#elif(ODO_PROJECT_TYPE_P03 == 1u)
	#ifdef COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP
 		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
 	return signal;
 #else 
 	return 0;
 #endif
#elif(ODO_PROJECT_TYPE_A07 == 1u)
	#ifdef COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP
 		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
 	return signal;
 #else 
 	return 0;
 #endif
 #elif(ODO_PROJECT_TYPE_D01 == 1u)
	#ifdef COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP
 		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
 	return signal;
 #else 
 	return 0;
 #endif
 #elif(ODO_PROJECT_TYPE_D02 == 1u)
	#ifdef COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP
 		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
 	return signal;
 #else 
 	return 0;
 #endif
 #elif(ODO_PROJECT_TYPE_D03 == 1u)
	#ifdef COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP
 		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
 	return signal;
 #else 
 	return 0;
 #endif
 #elif(ODO_PROJECT_TYPE_P02 == 1u)
	#ifdef COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP
 		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
 	return signal;
 #else 
 	return 0;
 #endif
 #elif(ODO_PROJECT_TYPE_P01 == 1u)
	#ifdef COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP
 		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
 	return signal;
 #else 
 	return 0;
 #endif
#else
 #ifdef Rte_Read_ECM_VehDstBackup_ECM_VehDstBackup
 	status = Rte_Read_ECM_VehDstBackup_ECM_VehDstBackup(&signal);
 	if(((status & RTE_E_NEVER_RECEIVED) != RTE_E_NEVER_RECEIVED) && (signal < 0x989680))
	{
	}
	else
	{
		signal = 0xffffffff;
	}
 	return signal;
 #else 
 	return FALSE;
 	#endif
#endif
}

/**********************************************************************************************************
*Function   : Odo_GetCurrentData                                                                          *
*                                                                                                         *
*Description: get odo data to backup                                                                      *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : Time and data value struct                                                                  *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
s_OdoBackupValue_t Odo_GetCurrentData(void)
{
	s_OdoBackupValue_t time_s = {0};
	Std_ReturnType readSts; 
	sint64 timetick = 0;
	Std_ReturnType tempodo;
	//fix The right hand operand of a logical operator "||" contains expression "Rte_Call_Common_Normal_IRTC_Service_UTC2PerpetualCalendar(timetick, &time_s.time)" which has persistent side effects
	readSts = Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_UtcTime(&timetick);
	tempodo = Rte_Call_IRTC_Service_UTC2PerpetualCalendar(timetick,&time_s.time);
	if((E_OK != readSts) || (Rte_InitValue_tiSR_Rte_Read_Sd_RTC_Data_UtcTime == timetick ) || (E_OK != tempodo))
	{
		time_s.time.u16Year = 2020;
		time_s.time.u8Month = 0;
		time_s.time.u8Day = 1;
		time_s.time.u8Hour = 0;
		time_s.time.u8Minutes = 0;
		time_s.time.u8Seconds = 0;
	}
	time_s.Curodo = Odo_Api_Odometer_Get(e_OdoUints_1m);
	return time_s;
}

/**********************************************************************************************************
*Function   : Odo_GetSpeedMsgEnable                                                                       *
*                                                                                                         *
*Description: get speed message valid flagh                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : boolean   TRUE:message is valid                                                             *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 Odo_GetSpeedMsgEnable(void)
{
#if (ODO_PROJECT_TYPE_B02 == 1)
	uint16 u16VehOdoInfo;
	uint8 u8VehOdoInfoSts;
	uint8 status = ODO_FALSE;
	uint8 config;
 #ifdef COMEX_SIGNAL_RX_VEHODOINFOSTS
 	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFO,(uint8 *)&u16VehOdoInfo,(uint8)sizeof(u16VehOdoInfo));
 	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFOSTS,&u8VehOdoInfoSts,(uint8)sizeof(u8VehOdoInfoSts));
 	if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (u16VehOdoInfo < 0x3E8) && (u8VehOdoInfoSts == 1))
 	{
 		status = ODO_TRUE;
 	}
 	else 
 	{
 		status = ODO_FALSE;
 	}
 #else
 	status = ODO_FALSE;
 #endif
#elif(ODO_PROJECT_TYPE_P05 == 1u)
	uint16 u16VehOdoInfo;
	uint8 u8VehOdoInfoSts;
	uint8 status = ODO_FALSE;
	uint8 config = 0u;
	s_OdoConfiguration_t condfig_s = Odo_ApiGetConfiguration();
	config =  condfig_s.Vconfig_KIND_PT_CAN_BUS_TYPE;
	/*Get signals from CAN*/
	if(0x00u == config)
	{
	 #ifdef COMEX_SIGNAL_RX_VEHODOINFOSTS_0X265
	 	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFO_0X265,(uint8 *)&u16VehOdoInfo,(uint8)sizeof(u16VehOdoInfo));
	 	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFOSTS_0X265,&u8VehOdoInfoSts,(uint8)sizeof(u8VehOdoInfoSts));
	 	if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (u16VehOdoInfo < 0x3E8) && (u8VehOdoInfoSts == 1))
	 	{
	 		status = ODO_TRUE;
	 	}
	 	else 
	 	{
	 		status = ODO_FALSE;
	 	}
	 #else
	 	status = ODO_FALSE;
	 #endif
	}
	/*Get signals from CANFD*/
	else if(0x01u == config)
	{
	 #ifdef COMEX_SIGNAL_RX_VEHODOINFOSTS_0X137
	 	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFO_0X137,(uint8 *)&u16VehOdoInfo,(uint8)sizeof(u16VehOdoInfo));
	 	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFOSTS_0X137,&u8VehOdoInfoSts,(uint8)sizeof(u8VehOdoInfoSts));
	 	if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (u16VehOdoInfo < 0x3E8) && (u8VehOdoInfoSts == 1))
	 	{
	 		status = ODO_TRUE;
	 	}
	 	else 
	 	{
	 		status = ODO_FALSE;
	 	}
	 #else
	 	status = ODO_FALSE;
	 #endif
	}
	else
	{
		status = ODO_FALSE;
	}	
#elif(ODO_PROJECT_TYPE_A07 == 1u)
		uint16 u16VehOdoInfo;
		uint8 u8VehOdoInfoSts;
		uint8 status = ODO_FALSE;
		uint8 config = 0u;
		s_OdoConfiguration_t condfig_s = Odo_ApiGetConfiguration();
		config =  condfig_s.Vconfig_KIND_PT_CAN_BUS_TYPE;
		/*Get signals from CAN*/
		if(0x00u == config)
		{
	 #ifdef COMEX_SIGNAL_RX_VEHODOINFOSTS
			status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFO,(uint8 *)&u16VehOdoInfo,(uint8)sizeof(u16VehOdoInfo));
			status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFOSTS,&u8VehOdoInfoSts,(uint8)sizeof(u8VehOdoInfoSts));
			if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (u16VehOdoInfo < 0x3E8) && (u8VehOdoInfoSts == 1))
			{
				status = ODO_TRUE;
			}
			else 
			{
				status = ODO_FALSE;
			}
	 #else
			status = ODO_FALSE;
	 #endif
		}
		/*Get signals from CANFD*/
		else if(0x01u == config)
		{
	 #ifdef COMEX_SIGNAL_RX_VEHODOINFOSTS_0X137
			status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFO_0X137,(uint8 *)&u16VehOdoInfo,(uint8)sizeof(u16VehOdoInfo));
			status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFOSTS_0X137,&u8VehOdoInfoSts,(uint8)sizeof(u8VehOdoInfoSts));
			if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (u16VehOdoInfo < 0x3E8) && (u8VehOdoInfoSts == 1))
			{
				status = ODO_TRUE;
			}
			else 
			{
				status = ODO_FALSE;
			}
	 #else
			status = ODO_FALSE;
	 #endif
		}
		else
		{
			status = ODO_FALSE;
		}	

#elif(ODO_PROJECT_TYPE_P03 == 1u)
	uint16 u16VehOdoInfo;
	uint8 u8VehOdoInfoSts;
	uint8 status = ODO_FALSE;
	uint8 config = 0u;
	s_OdoConfiguration_t condfig_s = Odo_ApiGetConfiguration();
	config =  condfig_s.Vconfig_KIND_PT_CAN_BUS_TYPE;
	/*Get signals from CAN*/
	if(0x00u == config)
	{
	 /*	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFO,(uint8 *)&u16VehOdoInfo,(uint8)sizeof(u16VehOdoInfo));
	 	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFOSTS,&u8VehOdoInfoSts,(uint8)sizeof(u8VehOdoInfoSts));
	 	if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (u16VehOdoInfo < 0x3E8) && (u8VehOdoInfoSts == 1))
	 	{
	 		status = TRUE;
	 	}
	 	else 
	 	{
	 		status = FALSE;
	 	}
	*/
	}
	/*Get signals from CANFD*/
	else if(0x01u == config)
	{
	 	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFO,(uint8 *)&u16VehOdoInfo,(uint8)sizeof(u16VehOdoInfo));
	 	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFOSTS,&u8VehOdoInfoSts,(uint8)sizeof(u8VehOdoInfoSts));
	 	if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (u16VehOdoInfo < 0x3E8) && (u8VehOdoInfoSts == 1))
	 	{
	 		status = ODO_TRUE;
	 	}
	 	else 
	 	{
	 		status = ODO_FALSE;
	 	}
	}
	else
	{
		status = ODO_FALSE;
	}	
#elif (ODO_PROJECT_TYPE_D01 == 1)
		uint16 u16VehOdoInfo;
		uint8 u8VehOdoInfoSts;
		uint8 status = ODO_FALSE;
		uint8 config;
 #ifdef COMEX_SIGNAL_RX_VEHODOINFOSTS
		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFO,(uint8 *)&u16VehOdoInfo,(uint8)sizeof(u16VehOdoInfo));
		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFOSTS,&u8VehOdoInfoSts,(uint8)sizeof(u8VehOdoInfoSts));
		if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (u16VehOdoInfo < 0x3E8) && (u8VehOdoInfoSts == 1))
		{
			status = ODO_TRUE;
		}
		else 
		{
			status = ODO_FALSE;
		}
 #else
		status = ODO_FALSE;
 #endif
#elif (ODO_PROJECT_TYPE_D02 == 1)
			uint16 u16VehOdoInfo;
			uint8 u8VehOdoInfoSts;
			uint8 status = ODO_FALSE;
			uint8 config;
 #ifdef COMEX_SIGNAL_RX_VEHODOINFOSTS
			status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFO,(uint8 *)&u16VehOdoInfo,(uint8)sizeof(u16VehOdoInfo));
			status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFOSTS,&u8VehOdoInfoSts,(uint8)sizeof(u8VehOdoInfoSts));
			if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (u16VehOdoInfo < 0x3E8) && (u8VehOdoInfoSts == 1))
			{
				status = ODO_TRUE;
			}
			else 
			{
				status = ODO_FALSE;
			}
 #else
			status = ODO_FALSE;
 #endif
#elif (ODO_PROJECT_TYPE_D03 == 1)
			uint16 u16VehOdoInfo;
			uint8 u8VehOdoInfoSts;
			uint8 status = ODO_FALSE;
			uint8 config;
 #ifdef COMEX_SIGNAL_RX_VEHODOINFOSTS
			status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFO,(uint8 *)&u16VehOdoInfo,(uint8)sizeof(u16VehOdoInfo));
			status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFOSTS,&u8VehOdoInfoSts,(uint8)sizeof(u8VehOdoInfoSts));
			if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (u16VehOdoInfo < 0x3E8) && (u8VehOdoInfoSts == 1))
			{
				status = ODO_TRUE;
			}
			else 
			{
				status = ODO_FALSE;
			}
 #else
			status = ODO_FALSE;
 #endif
 #elif (ODO_PROJECT_TYPE_P02 == 1)
			uint16 u16VehOdoInfo;
			uint8 u8VehOdoInfoSts;
			uint8 status = ODO_FALSE;
			uint8 config;
 #ifdef COMEX_SIGNAL_RX_VEHODOINFOSTS
			status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFO,(uint8 *)&u16VehOdoInfo,(uint8)sizeof(u16VehOdoInfo));
			status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFOSTS,&u8VehOdoInfoSts,(uint8)sizeof(u8VehOdoInfoSts));
			if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (u16VehOdoInfo < 0x3E8) && (u8VehOdoInfoSts == 1))
			{
				status = ODO_TRUE;
			}
			else 
			{
				status = ODO_FALSE;
			}
 #else
			status = ODO_FALSE;
 #endif
#elif (ODO_PROJECT_TYPE_P01 == 1)
		uint16 u16VehOdoInfo;
		uint8 u8VehOdoInfoSts;
		uint8 status = ODO_FALSE;
		uint8 config;
 #ifdef COMEX_SIGNAL_RX_VEHODOINFOSTS
		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFO,(uint8 *)&u16VehOdoInfo,(uint8)sizeof(u16VehOdoInfo));
		status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHODOINFOSTS,&u8VehOdoInfoSts,(uint8)sizeof(u8VehOdoInfoSts));
		if(((RTE_E_ComEx_E_OK == status) || (RTE_E_ComEx_COMEX_UPDATE_RECEIVED == status)) && (u16VehOdoInfo < 0x3E8) && (u8VehOdoInfoSts == 1))
		{
			status = ODO_TRUE;
		}
		else 
		{
			status = ODO_FALSE;
		}
 #else
		status = ODO_FALSE;
 #endif
#else
 #ifdef Rte_Read_SG_ABS3_SG_ABS3
 	SG_ABS3 signal;
 #endif
 #ifdef Rte_Read_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2
 	SG_ABS3_ESP_FD2 signal1;
 #endif
	uint8 status = ODO_FALSE;
	uint8 config;
	s_OdoConfiguration_t condfig_s = Odo_ApiGetConfiguration();
	config =  condfig_s.Vconfig_KIND_PT_CAN_BUS_TYPE;

 	if(0x00 == config)
 	{
  #ifdef Rte_Read_SG_ABS3_SG_ABS3
  		status = Rte_Read_SG_ABS3_SG_ABS3(&signal);
  		if((RTE_E_OK == status) && (signal.VehOdoInfo_0x265 < 0x3E8) && (signal.VehOdoInfoSts_0x265 == 1))
  		{
  			status = ODO_TRUE;
  		}
  		else 
  		{
  			status = ODO_FALSE;
  		}
  #else
  		status = FALSE;
  #endif
 	}
 	else if(0x01 == config)
 	{
  #ifdef Rte_Read_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2
 		status = Rte_Read_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2(&signal1);
 		if((RTE_E_OK == status) && (signal1.VehOdoInfo_0x137 < 0x3E8) && (signal1.VehOdoInfoSts_0x137 == 1))
 		{
 			status = ODO_TRUE;
 		}
 		else 
 		{
 			status = ODO_FALSE;
 		}
  #else
 		status = ODO_FALSE;
  #endif
 	}
 	else
 	{
 		status = ODO_FALSE;
 	}
#endif
	return status;
}

/**********************************************************************************************************
*Function   : Odo_GetSpeedMsgValue                                                                        *
*                                                                                                         *
*Description: get speed message value                                                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : speed in                                                                                    *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
CanFrameCounterType Odo_GetSpeedMsgValue(void)
{
#if (ODO_PROJECT_TYPE_B02 == 1)
	CanFrameCounterType outValue = {0xffff,0xffff};
 #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
 	if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
 	{
 		outValue.Data = 0xffff;
 		outValue.Counter = 0xffff;
 	}
 	else
 	{
 		if(outValue.Data < 0x3E8)
 		{
 			outValue.Data *= 10;
 		}
 		else
 		{
 			outValue.Data = 0xffff;
 			outValue.Counter = 0xffff;
 		}
 	}
 #else
 	outValue.Data = 0xffff;
 	outValue.Counter = 0xffff;
 #endif
#elif(ODO_PROJECT_TYPE_P05 == 1u)
	CanFrameCounterType outValue = {0xffff,0xffff};
	uint8 config = 0u;
	s_OdoConfiguration_t condfig_s = Odo_ApiGetConfiguration();
	config =  condfig_s.Vconfig_KIND_PT_CAN_BUS_TYPE;
	/*Get signals from CAN*/
	if(0x00u == config)
	{
	 #ifdef Rte_Call_CanFrameCounter_Can_ABS3_Counter
	 	if(E_OK != Rte_Call_CanFrameCounter_Can_ABS3_Counter(&outValue))
	 	{
	 		outValue.Data = 0xffff;
	 		outValue.Counter = 0xffff;
	 	}
	 	else
	 	{
	 		if(outValue.Data < 0x3E8)
	 		{
	 			outValue.Data *= 10;
	 		}
	 		else
	 		{
	 			outValue.Data = 0xffff;
	 			outValue.Counter = 0xffff;
	 		}
	 	}
	 #else
	 	outValue.Data = 0xffff;
	 	outValue.Counter = 0xffff;
	 #endif
	}
	/*Get signals from CANFD*/
	else if(0x01u == config)
	{
	 #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
	 	if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
	 	{
	 		outValue.Data = 0xffff;
	 		outValue.Counter = 0xffff;
	 	}
	 	else
	 	{
	 		if(outValue.Data < 0x3E8)
	 		{
	 			outValue.Data *= 10;
	 		}
	 		else
	 		{
	 			outValue.Data = 0xffff;
	 			outValue.Counter = 0xffff;
	 		}
	 	}
	 #else
	 	outValue.Data = 0xffff;
	 	outValue.Counter = 0xffff;
	 #endif
	}
	else
	{
		outValue.Data = 0xffff;
	 	outValue.Counter = 0xffff;
	}	
#elif(ODO_PROJECT_TYPE_A07 == 1u)
	CanFrameCounterType outValue = {0xffff,0xffff};
	uint8 config = 0u;
	s_OdoConfiguration_t condfig_s = Odo_ApiGetConfiguration();
	config =  condfig_s.Vconfig_KIND_PT_CAN_BUS_TYPE;
	/*Get signals from CAN*/
	if(0x00u == config)
	{
	 #ifdef Rte_Call_CanFrameCounter_Can_ABS3_Counter
	 	if(E_OK != Rte_Call_CanFrameCounter_Can_ABS3_Counter(&outValue))
	 	{
	 		outValue.Data = 0xffff;
	 		outValue.Counter = 0xffff;
	 	}
	 	else
	 	{
	 		if(outValue.Data < 0x3E8)
	 		{
	 			outValue.Data *= 10;
	 		}
	 		else
	 		{
	 			outValue.Data = 0xffff;
	 			outValue.Counter = 0xffff;
	 		}
	 	}
	 #else
	 	outValue.Data = 0xffff;
	 	outValue.Counter = 0xffff;
	 #endif
	}
	/*Get signals from CANFD*/
	else if(0x01u == config)
	{
	 #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
	 	if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
	 	{
	 		outValue.Data = 0xffff;
	 		outValue.Counter = 0xffff;
	 	}
	 	else
	 	{
	 		if(outValue.Data < 0x3E8)
	 		{
	 			outValue.Data *= 10;
	 		}
	 		else
	 		{
	 			outValue.Data = 0xffff;
	 			outValue.Counter = 0xffff;
	 		}
	 	}
	 #else
	 	outValue.Data = 0xffff;
	 	outValue.Counter = 0xffff;
	 #endif
	}
	else
	{
		outValue.Data = 0xffff;
	 	outValue.Counter = 0xffff;
	}
#elif(ODO_PROJECT_TYPE_P03 == 1u)
	CanFrameCounterType outValue = {0xffff,0xffff};
	uint8 config = 0u;
	s_OdoConfiguration_t condfig_s = Odo_ApiGetConfiguration();
	config =  condfig_s.Vconfig_KIND_PT_CAN_BUS_TYPE;
	/*Get signals from CAN*/
	if(0x00u == config)
	{
	/* #ifdef Rte_Call_CanFrameCounter_Can_ABS3_Counter
	 	if(E_OK != Rte_Call_CanFrameCounter_Can_ABS3_Counter(&outValue))
	 	{
	 		outValue.Data = 0xffff;
	 		outValue.Counter = 0xffff;
	 	}
	 	else
	 	{
	 		if(outValue.Data < 0x3E8)
	 		{
	 			outValue.Data *= 10;
	 		}
	 		else
	 		{
	 			outValue.Data = 0xffff;
	 			outValue.Counter = 0xffff;
	 		}
	 	}
	 #else
	 	outValue.Data = 0xffff;
	 	outValue.Counter = 0xffff;
	 #endif
	 */
	}
	/*Get signals from CANFD*/
	else if(0x01u == config)
	{
	 #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
	 	if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
	 	{
	 		outValue.Data = 0xffff;
	 		outValue.Counter = 0xffff;
	 	}
	 	else
	 	{
	 		if(outValue.Data < 0x3E8)
	 		{
	 			outValue.Data *= 10;
	 		}
	 		else
	 		{
	 			outValue.Data = 0xffff;
	 			outValue.Counter = 0xffff;
	 		}
	 	}
	 #else
	 	outValue.Data = 0xffff;
	 	outValue.Counter = 0xffff;
	 #endif
	}
	else
	{
		outValue.Data = 0xffff;
	 	outValue.Counter = 0xffff;
	}
#elif (ODO_PROJECT_TYPE_D01 == 1)
		CanFrameCounterType outValue = {0xffff,0xffff};
 #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
		if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
		{
			outValue.Data = 0xffff;
			outValue.Counter = 0xffff;
		}
		else
		{
			if(outValue.Data < 0x3E8)
			{
				outValue.Data *= 10;
			}
			else
			{
				outValue.Data = 0xffff;
				outValue.Counter = 0xffff;
			}
		}
 #else
		outValue.Data = 0xffff;
		outValue.Counter = 0xffff;
 #endif
#elif (ODO_PROJECT_TYPE_D02 == 1)
			CanFrameCounterType outValue = {0xffff,0xffff};
 #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
			if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
			{
				outValue.Data = 0xffff;
				outValue.Counter = 0xffff;
			}
			else
			{
				if(outValue.Data < 0x3E8)
				{
					outValue.Data *= 10;
				}
				else
				{
					outValue.Data = 0xffff;
					outValue.Counter = 0xffff;
				}
			}
 #else
			outValue.Data = 0xffff;
			outValue.Counter = 0xffff;
 #endif
#elif (ODO_PROJECT_TYPE_D03 == 1)
			CanFrameCounterType outValue = {0xffff,0xffff};
 #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
			if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
			{
				outValue.Data = 0xffff;
				outValue.Counter = 0xffff;
			}
			else
			{
				if(outValue.Data < 0x3E8)
				{
					outValue.Data *= 10;
				}
				else
				{
					outValue.Data = 0xffff;
					outValue.Counter = 0xffff;
				}
			}
 #else
			outValue.Data = 0xffff;
			outValue.Counter = 0xffff;
 #endif
#elif (ODO_PROJECT_TYPE_P02 == 1)
			CanFrameCounterType outValue = {0xffff,0xffff};
 #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
			if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
			{
				outValue.Data = 0xffff;
				outValue.Counter = 0xffff;
			}
			else
			{
				if(outValue.Data < 0x3E8)
				{
					outValue.Data *= 10;
				}
				else
				{
					outValue.Data = 0xffff;
					outValue.Counter = 0xffff;
				}
			}
 #else
			outValue.Data = 0xffff;
			outValue.Counter = 0xffff;
 #endif
#elif (ODO_PROJECT_TYPE_P01 == 1)
			CanFrameCounterType outValue = {0xffff,0xffff};
 #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
			if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
			{
				outValue.Data = 0xffff;
				outValue.Counter = 0xffff;
			}
			else
			{
				if(outValue.Data < 0x3E8)
				{
					outValue.Data *= 10;
				}
				else
				{
					outValue.Data = 0xffff;
					outValue.Counter = 0xffff;
				}
			}
 #else
			outValue.Data = 0xffff;
			outValue.Counter = 0xffff;
 #endif
#else
	CanFrameCounterType outValue = {0xffff,0xffff};
	uint8 config;
	s_OdoConfiguration_t condfig_s = Odo_ApiGetConfiguration();
 	
 	config =  condfig_s.Vconfig_KIND_PT_CAN_BUS_TYPE;
 
 	if(0x00 == config)
 	{
  #ifdef Rte_Call_CanFrameCounter_Can_ABS3_Counter
  		if(E_OK != Rte_Call_CanFrameCounter_Can_ABS3_Counter(&outValue))
  		{
  			outValue.Data = 0xffff;
  			outValue.Counter = 0xffff;
  		}
  		else
  		{	if(outValue.Data < 0x3E8)
  			{
  				outValue.Data *= 10;
  			}
  			else
  			{
  				outValue.Data = 0xffff;
  				outValue.Counter = 0xffff;
  			}
  		}
  #else 
  		outValue.Data = 0xffff;
  		outValue.Counter = 0xffff;	
  #endif
 	}
 	else if(0x01 == config)
 	{
  #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
  		if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
  		{
  			outValue.Data = 0xffff;
  			outValue.Counter = 0xffff;
  		}
  		else
  		{
  			if(outValue.Data < 0x3E8)
  			{
  				outValue.Data *= 10;
  			}
  			else
  			{
  				outValue.Data = 0xffff;
  				outValue.Counter = 0xffff;
  			}
  		}
  #else
  		outValue.Data = 0xffff;
  		outValue.Counter = 0xffff;
  #endif
 	}
#endif
	return outValue;

}

uint8 Odo_GetECMOdoBackupSts(void)
{
	ECM_VehDstBackup signal;
	uint8 status;
#if (ODO_PROJECT_TYPE_B02 == 1)
 	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
#elif(ODO_PROJECT_TYPE_P05 == 1u)
 	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
#elif(ODO_PROJECT_TYPE_P03 == 1u)
 	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
#elif(ODO_PROJECT_TYPE_A07 == 1u)
 	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
#elif(ODO_PROJECT_TYPE_D01 == 1u)
 	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
#elif(ODO_PROJECT_TYPE_D02 == 1u)
 	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
 #elif(ODO_PROJECT_TYPE_D03 == 1u)
 	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
#elif(ODO_PROJECT_TYPE_P02 == 1u)
 	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
#elif(ODO_PROJECT_TYPE_P01 == 1u)
	status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_VEHDSTBACKUP,&signal,(uint8)sizeof(signal));
#else
#endif
	return status;
}
/**********************************************************************************************************
*Function   : Odo_NvmWrite                                                                                *
*                                                                                                         *
*Description: Nvm write function                                                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : speed in                                                                                    *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_NvmWrite(uint8 BlkId)
{
	Std_ReturnType Write_return = E_NOT_OK;
	NvM_RequestResultType Blk_type = NVM_REQ_OK;
	Std_ReturnType blk_return = E_NOT_OK;
	
	blk_return = Odo_NvmBlockTbl[BlkId].check(&Blk_type);
	if((E_OK == blk_return) && (NVM_REQ_PENDING != Blk_type))
	{
		if(BlkId < ODO_PKG_NUMBER_OF_ODO_SETS)
		{
			(void)memcpy(Odo_NvmBlockTbl[BlkId].Ram_Ptr,Odo_NvmBlockTbl[BlkId].Enhsm_Ptr,Odo_NvmBlockTbl[BlkId].Size);
		}
		else
		{
			(void)memcpy(Odo_NvmBlockTbl[BlkId].Ram_Ptr,Odo_NvmBlockTbl[BlkId].Local_Ptr,Odo_NvmBlockTbl[BlkId].Size);
		}
		Write_return = Odo_NvmBlockTbl[BlkId].writen(NULL_PTR);
		if(E_OK == Write_return)
		{
			Odo_Api_RteNvmWrite_Set(BlkId,FALSE);
			SWC_ODO_INFO_LOG("block d% write success",BlkId);
		}
	}
}
/**********************************************************************************************************
*Function   : Odo_Api_ResetOdoFlag_Set                                                                    *
*                                                                                                         *
*Description: Set block write flag                                                                        *
*                                                                                                         *
*Parameter  : BlkId:   id need to below max block,control: FALSE :clear TRUE :Set                         *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-05                                                                                  *
**********************************************************************************************************/
void Odo_Api_ResetOdoFlag_Set(uint8 BlkId,uint8 control)
{
	if(BlkId < e_OdoBlock_ODO_NVM_BLOCK_ALL)
	{
		Odo_ClearWriteResultFlag_u8[BlkId] = control;
	}
}

/**********************************************************************************************************
*Function   : Odo_Api_ResetOdoFlag_Get                                                                    *
*                                                                                                         *
*Description: Set block write flag                                                                        *
*                                                                                                         *
*Parameter  : BlkId:   id need to below max block,control: FALSE :clear TRUE :Set                         *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-05                                                                                  *
**********************************************************************************************************/
uint8 Odo_Api_ResetOdoFlag_Get(uint8 BlkId)
{
	uint8 status = (uint8)e_OdoWriteSts_Nuaa;
	if(BlkId < e_OdoBlock_ODO_NVM_BLOCK_ALL)
	{
		status = Odo_ClearWriteResultFlag_u8[BlkId];
	}
	return status;
}

/**********************************************************************************************************
*Function   : Odo_GetOdoUnit                                                                              *
*                                                                                                         *
*Description: Get display uints                                                                           *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : TRUE:                                                                                       *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 Odo_GetOdoUnit(void)
{
	MenuSetData_t menuset;
	uint8 config = 0;//(uint8)FALSE;
	//s_OdoConfiguration_t condfig_s = Odo_ApiGetConfiguration();
#ifdef Rte_Read_rpSR_SWCNormal_MenuSetData_Element
	if(E_OK == Rte_Read_rpSR_SWCNormal_MenuSetData_Element(&menuset))
	{
		if((0x02 == menuset.OdometerUnit) || (0x03 == menuset.OdometerUnit))
		{
			config = 1;//(uint8)TRUE;
		}
		else
		{
			config = 0;//(uint8)FALSE;
		}
	}
#else
	config = FALSE;
#endif
	return config;
}
/**********************************************************************************************************
*Function   : Odo_ReadSleepTimer                                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : speed in                                                                                    *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint64 Odo_ReadSleepTimer(void)
{
	sint64 sleepTime;
	uint64 RollCounter = 0;

	if(FALSE == Odo_ReadSleepTimeFlag_u8)
	{
#ifdef Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_SleepDateTime
		if(E_OK == Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_SleepDateTime(&sleepTime))
		{
			if(sleepTime > 0)
			{
				RollCounter = (uint64)sleepTime;
				Odo_ReadSleepTimeFlag_u8 = 1;//(uint8)TRUE;
			}
		}
		else 
		{
			
		}
#else
		RollCounter = 0;
#endif
	}
	else 
	{
		
	}
	return RollCounter;
}

/**********************************************************************************************************
*Function   : Odo_SetCanOutput                                                                            *
*                                                                                                         *
*Description: Set can output function                                                                     *
*                                                                                                         *
*Parameter  : data :value and valid flag                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_SetCanOutput(s_OdoCanOutputData_t data)
{
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_VehTotDistance
	(void)Rte_Write_Sd_CanOutputViaGateway_IP_VehTotDistance(data.OdoValue_u32);
#endif
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_VehTotDistance
	(void)Rte_Write_Sd_CanOutputViaGateway_IP_VehTotDistanceValid(data.ValidFlag_u8);
#endif
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_VehTotDistance
	(void)Rte_Write_Sd_CanOutputViaGateway_IP_VINcompr(data.VinCompr_u8);
#endif

}

/**********************************************************************************************************
*Function   : Odo_HMIResetTcCallback                                                                      *
*                                                                                                         *
*Description: Hmi tc reset function                                                                       *
*                                                                                                         *
*Parameter  : data :clear data                                                                            *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_HMIResetTcCallback(uint8 *data)
{
	uint32 cleardata = 0x02;
	uint8 result = 0;//(uint8)FALSE;
	if(0x11 == *data)
	{
		result = Odo_Api_ParamentSetFunction((uint8)e_RteOdoSet_ResetTrip,&cleardata);
	}
	(void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_TC_CLEAR_RESP,&result,(uint16)sizeof(IPC_M2S_ClusterAppAPPTCClearResult_t),TRUE);
}

/**********************************************************************************************************
*Function   : Odo_GetAllConfiguration                                                                          *
*                                                                                                         *
*Description: Nvm write function                                                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : speed in                                                                                    *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_GetAllConfiguration(void)
{
	VconfigKind_Allbuffers configAdress;
	CconfigKind_400Bytes Lcal_config;
	
	(void) Rte_Read_Vconfig_GetKindBuffers_AllKinds(configAdress);
	
	OdoConfiguration_s.Vconfig_KIND_ENGINE_CONTROL_UNIT = configAdress[VCONFIG_KIND_ENGINE_CONTROL_UNIT];
	OdoConfiguration_s.Vconfig_KIND_TRANSMISSION = configAdress[VCONFIG_KIND_TRANSMISSION];
	OdoConfiguration_s.Vconfig_KIND_CLUSTER_UNIT_SYSTEM = configAdress[VCONFIG_KIND_CLUSTER_UNIT_SYSTEM];
	OdoConfiguration_s.Vconfig_KIND_PT_CAN_BUS_TYPE = configAdress[VCONFIG_KIND_PT_CAN_BUS_TYPE];

	if(E_OK != Rte_Read_Common_Normal_tiSR_VIN_Element(OdoConfiguration_s.Vconfig_Vinconfig))
	{
		(void)memset(&OdoConfiguration_s.Vconfig_Vinconfig,0xff,sizeof(s_NVMVincfgData_t));
	}

	if(E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(Lcal_config))
	{
		OdoConfiguration_s.LConfig_DrivDataARestTime = (uint8)CConfig_GetConfig(CCONFIG_KIND_DrivDataARestTime, Lcal_config);
		OdoConfiguration_s.LConfig_FIXEDDISPLAY_1_ODO_ENABLE = (uint8)CConfig_GetConfig(CCONFIG_KIND_FIXEDDISPLAY_1_ODO_ENABLE, Lcal_config);
		OdoConfiguration_s.LConfig_ODOBACK_ENABLE = (uint8)CConfig_GetConfig(CCONFIG_KIND_P_ODOBACK_ENABLE, Lcal_config);
		OdoConfiguration_s.LConfig_P_ODO_BACK_WARNING_ENABLE = (uint8)CConfig_GetConfig(CCONFIG_KIND_P_ODOBACK_WARNING_ENABLE, Lcal_config);
		OdoConfiguration_s.LConfig_ODOVIN_Check_I_nequality_Time = (uint8)CConfig_GetConfig(CCONFIG_KIND_ODOVIN_CheckInequalityTime, Lcal_config);
		OdoConfiguration_s.LConfig_ODObackup_DelayTime = (uint8)CConfig_GetConfig(CCONFIG_KIND_ODObackup_DelayTime, Lcal_config);
		OdoConfiguration_s.LConfig_Maintenance_distance = (uint32)CConfig_GetConfig(CCONFIG_KIND_Maintenance_distance, Lcal_config);

		OdoConfiguration_s.LConfig_DrivDataARollovervalue = (uint32)CConfig_GetConfig(CCONFIG_KIND_DrivDataARollovervalue, Lcal_config);
		OdoConfiguration_s.LConfig_DrivDataBRollovervalue = (uint32)CConfig_GetConfig(CCONFIG_KIND_DrivDataBRollovervalue, Lcal_config);
		OdoConfiguration_s.LConfig_DrivDataCRollovervalue = 99999;
		OdoConfiguration_s.LConfig_DrivDataADisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_DrivDataADisplayEnable, Lcal_config);
		OdoConfiguration_s.LConfig_DrivDataBDisplayEnable = (uint8)CConfig_GetConfig(CCONFIG_KIND_DrivDataBDisplayEnable, Lcal_config);
		OdoConfiguration_s.LConfig_DrivDataCDisplayEnable = 0;
	}
	else
	{
		OdoConfiguration_s.LConfig_DrivDataARestTime = 24;
		OdoConfiguration_s.LConfig_FIXEDDISPLAY_1_ODO_ENABLE = 1;
		OdoConfiguration_s.LConfig_ODOBACK_ENABLE = 0;
		OdoConfiguration_s.LConfig_P_ODO_BACK_WARNING_ENABLE = 0;
		OdoConfiguration_s.LConfig_ODOVIN_Check_I_nequality_Time = 3;
		OdoConfiguration_s.LConfig_ODObackup_DelayTime = 30;
		OdoConfiguration_s.LConfig_Maintenance_distance = 5000;

		OdoConfiguration_s.LConfig_DrivDataARollovervalue = 99999;
		OdoConfiguration_s.LConfig_DrivDataBRollovervalue = 99999;
		OdoConfiguration_s.LConfig_DrivDataCRollovervalue = 99999;
		OdoConfiguration_s.LConfig_DrivDataADisplayEnable = 1;
		OdoConfiguration_s.LConfig_DrivDataBDisplayEnable = 1;
		OdoConfiguration_s.LConfig_DrivDataCDisplayEnable = 0;
	}
}

/**********************************************************************************************************
*Function   : Odo_ApiGetConfiguration                                                                     *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : speed in                                                                                    *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
s_OdoConfiguration_t Odo_ApiGetConfiguration(void)
{
	return OdoConfiguration_s;
}

/**********************************************************************************************************
*Function   : Odo_GetLocalConfig                                                                          *
*                                                                                                         *
*Description: Nvm write function                                                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : speed in                                                                                    *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint32 Odo_GetLocalConfig(uint8 id_u8)
{
	uint32 Lconfig = 0xffffffff;
	switch(id_u8)
	{
		case (uint8)e_OdoLocal_P_ODO_Reset_Distance:
		{
			Lconfig = 255;
			break;
		}
		case (uint8)e_OdoLocal_FIXEDDISPLAY_1_ODO_ENABLE:
		{
			Lconfig = OdoConfiguration_s.LConfig_FIXEDDISPLAY_1_ODO_ENABLE;
			break;
		}
		case (uint8)e_OdoLocal_ODOBACK_ENABLE:
		{
			Lconfig = OdoConfiguration_s.LConfig_ODOBACK_ENABLE;
			break;
		}
		case (uint8)e_OdoLocal_P_ODO_BACK_WARNING_ENABLE:
		{
			Lconfig = OdoConfiguration_s.LConfig_P_ODO_BACK_WARNING_ENABLE;
			break;
		}
		case (uint8)e_OdoLocal_ODObackup_DelayTime:
		{
			Lconfig = (uint32)OdoConfiguration_s.LConfig_ODObackup_DelayTime * 100UL;
			break;
		}
		case (uint8)e_OdoLocal_ODOVIN_Check_I_nequality_Time:
		{
			Lconfig = OdoConfiguration_s.LConfig_ODOVIN_Check_I_nequality_Time;
			break;
		}
		case (uint8)e_OdoLocal_DrivDataARestTime:
		{
			Lconfig = OdoConfiguration_s.LConfig_DrivDataARestTime;
			break;
		}
		case (uint8)e_OdoLocal_Maintenance_distance:
		{
			Lconfig = OdoConfiguration_s.LConfig_Maintenance_distance;
			break;
		}
		case (uint8)e_OdoLocal_DrivDataARollovervalue:
		{
			Lconfig = (OdoConfiguration_s.LConfig_DrivDataARollovervalue * 10UL) + 9;
			break;
		}
		case (uint8)e_OdoLocal_DrivDataBRollovervalue:
		{
			Lconfig = (OdoConfiguration_s.LConfig_DrivDataBRollovervalue * 10UL) + 9;
			break;
		}
		case (uint8)e_OdoLocal_DrivDataCRollovervalue:
		{
			Lconfig = (OdoConfiguration_s.LConfig_DrivDataCRollovervalue * 10UL) + 9;
			break;
		}
		case (uint8)e_OdoLocal_DrivDataADisplayEnable:
		{
			Lconfig = OdoConfiguration_s.LConfig_DrivDataADisplayEnable;
			break;
		}
		case (uint8)e_OdoLocal_DrivDataBDisplayEnable:
		{
			Lconfig = OdoConfiguration_s.LConfig_DrivDataBDisplayEnable;
			break;
		}
		case (uint8)e_OdoLocal_DrivDataCDisplayEnable:
		{
			Lconfig = OdoConfiguration_s.LConfig_DrivDataCDisplayEnable;
			break;
		}
		default:
		{
			Lconfig = 255;
			break;
		}
	}
	return Lconfig;
}

/**********************************************************************************************************
*Function   : Odo_Api_ParamentGetCsPort                                                                   *
*                                                                                                         *
*Description: Rte runable get cs port                                                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : wait nvm clear                                                                              *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-05                                                                                  *
**********************************************************************************************************/
void Odo_Api_ParamentGetCsPort(uint8 Id,uint8 *data)
{
	uint32 reset_remaining;
	uint64 odo_offset;
	uint8 odo_offsetFlg;
	uint8 inedx_u8;
	uint8 temp;
	uint64 value_u64;
	s_FsrvMaintenceInfo_t fsrv;
	uint64 MaintenceValue_u64;
	switch(Id)
	{
		case (uint8)e_OdoGetParameter_RealOdo:
		{
			odo_offset = *Odo_OdoOffsetAddress_Get();
			odo_offsetFlg = *Odo_OdoOffsetFlgAddress_Get();
			reset_remaining = (uint32)(((*Odo_OdoClearAddress_Get()) * 1000UL) + (*Odo_OdoClearLowAddress_Get()));
			value_u64 = Odo_Api_Odometer_Get(e_OdoUints_1m);
			if(ODO_NVM_ERROR_VALUE != value_u64)
			{
				if(0 == odo_offsetFlg)
				{
					value_u64 = value_u64 + ODO_CLEAR_VALUE_MAX - reset_remaining - odo_offset;
				}
				else
				{
					value_u64 = value_u64 + ODO_CLEAR_VALUE_MAX - reset_remaining + odo_offset;
				}
				//memcpy(data,&value_u64,5);
				data[4] = (uint8)((value_u64 >> (uint8)0u) & (uint8)0xffu);
				data[3] = (uint8)((value_u64 >> (uint8)8u) & (uint8)0xffu);
				data[2] = (uint8)((value_u64 >> (uint8)16u) & (uint8)0xffu);
				data[1] = (uint8)((value_u64 >> (uint8)24u) & (uint8)0xffu);
				data[0] = (uint8)((value_u64 >> (uint8)32u) & (uint8)0xffu);
			}
			else 
			{
				(void)memset(data,0xFF,5);
			}
			break;
		}
		case (uint8)e_OdoGetParameter_Fsrv:
		{
			fsrv = Fsrv_Api_MaintenanceInfo_Get();
			if(fsrv.MaintenceValue_s32 < 0)
			{
				fsrv.MaintenceValue_s32 = 0;
			}
			MaintenceValue_u64 = (uint64)fsrv.MaintenceValue_s32;
			value_u64 = Odo_Api_Odometer_Get(e_OdoUints_1m);
			if(ODO_NVM_ERROR_VALUE != value_u64)
			{
				data[3] = (uint8)((MaintenceValue_u64 >> (uint8)0u) & (uint8)0xffu);
				data[2] = (uint8)((MaintenceValue_u64 >> (uint8)8u) & (uint8)0xffu);
				data[1] = (uint8)((MaintenceValue_u64 >> (uint8)16u) & (uint8)0xffu);
				data[0] = (uint8)((MaintenceValue_u64 >> (uint8)24u) & (uint8)0xffu);
			}
			else
			{
				(void)memset(data,0xFF,4);
			}
			break;
		}
		case (uint8)e_OdoGetParameter_Backup:
		{
			inedx_u8 = *Odo_OdoBackupIndex_Get();
			for(temp = 0;temp < 3;temp ++)
			{
				(void)memcpy(&data[temp * 13],Odo_OdoBackupAddr_Get(inedx_u8),13);
				if(inedx_u8 > 0)
				{
					inedx_u8 --;
				}
				else
				{
					inedx_u8 = 2;
				}
			}
			break;
		}
		case (uint8)e_OdoGetParameter_ResetOdoResult:
		{
			if((uint8)e_OdoWriteSts_Success == Odo_Api_ResetOdoFlag_Get((uint8)e_OdoBlock_Matain_NVM_BLOCK))
			{
				*data = (uint8)e_OdoWriteSts_Success;
				//Odo_Api_ResetOdoFlag_Set((uint8)e_OdoBlock_Matain_NVM_BLOCK,(uint8)e_OdoWriteSts_Nuaa);
			}
			else if((uint8)e_OdoWriteSts_Nuaa == Odo_Api_ResetOdoFlag_Get((uint8)e_OdoBlock_Matain_NVM_BLOCK))
			{
				*data = (uint8)e_OdoWriteSts_Nuaa;
			}
			else if((uint8)e_OdoWriteSts_OutOfRange == Odo_Api_ResetOdoFlag_Get((uint8)e_OdoBlock_Matain_NVM_BLOCK))
			{
				*data = (uint8)e_OdoWriteSts_OutOfRange;
				//Odo_Api_ResetOdoFlag_Set((uint8)e_OdoBlock_Matain_NVM_BLOCK,(uint8)e_OdoWriteSts_Nuaa);
			}
			else if((uint8)e_OdoWriteSts_Fail == Odo_Api_ResetOdoFlag_Get((uint8)e_OdoBlock_Matain_NVM_BLOCK))
			{
				*data = (uint8)e_OdoWriteSts_Fail;
				//Odo_Api_ResetOdoFlag_Set((uint8)e_OdoBlock_Matain_NVM_BLOCK,(uint8)e_OdoWriteSts_Nuaa);
			}
			else
			{
				*data = (uint8)e_OdoWriteSts_Request;
			}
			break;
		}
		default:
		{
			*data = (uint8)e_OdoWriteSts_Request;
			break;
		}
	}
}
/**********************************************************************************************************
* HSM Function                                                                                            *
**********************************************************************************************************/
/**********************************************************************************************************
*Function   : Odo_RteHSMInitData                                                                          *
*                                                                                                         *
*Description: Init Hsm data                                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-8                                                                                  *
**********************************************************************************************************/
void Odo_RteHSMInitData(void)
{
	OdoHsmEncryptRam_Sts = e_OdoHsmStatus_Free;
	OdoHsmDecryptRam_Sts = e_OdoHsmStatus_Free;
	Odo_HsmDefaultStatus = e_OdoHSMSts_NvmDefaultValue;
	OdoMenoryPrintfCounter = 0;
	(void)memcpy(Odo_NvmBlockTbl[e_OdoBlock_Trip_NVM_BLOCK].Local_Ptr,Odo_NvmBlockTbl[e_OdoBlock_Trip_NVM_BLOCK].Ram_Ptr,Odo_NvmBlockTbl[e_OdoBlock_Trip_NVM_BLOCK].Size);
	(void)memcpy(Odo_NvmBlockTbl[e_OdoBlock_Matain_NVM_BLOCK].Local_Ptr,Odo_NvmBlockTbl[e_OdoBlock_Matain_NVM_BLOCK].Ram_Ptr,Odo_NvmBlockTbl[e_OdoBlock_Matain_NVM_BLOCK].Size);
}

/**********************************************************************************************************
*Function   : Odo_Api_DefaultValueCheck                                                                   *
*                                                                                                         *
*Description: Call by power mode change from normal to other,init data                                    *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : e_OdoHSMStatus_t current default status                                                     *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
e_OdoHSMStatus_t Odo_Api_DefaultValueCheck(void)
{
	uint8 temp;

	if (e_OdoHSMSts_NvmDefaultValue == Odo_HsmDefaultStatus)
	{
		OdoHsmDefaultRam_Flag = 0;
		OdoHsmEncryptRam_Flag = 0;
		OdoHsmDecryptRam_Flag = 0;
		for(temp = 0;temp < ODO_PKG_NUMBER_OF_ODO_SETS;temp ++)
		{
			if(E_OK == memcmp(Odo_NvmBlockTbl[temp].Ram_Ptr,Odo_NvmBlockTbl[temp].Default_Ptr,Odo_NvmBlockTbl[temp].Size))
			{
				OdoHsmDefaultRam_Flag |= ((uint8)(0x01u << temp));
			}
		}

		if(0 == OdoHsmDefaultRam_Flag)
		{
			//All block no need to Decrypt
			Odo_HsmDefaultStatus = e_OdoHSMSts_WriteNvmValueOK;
			OdoHsmDecryptRam_Flag = ODO_HSM_NEED_DECRPYT;
			return Odo_HsmDefaultStatus;
		}
		else if(ODO_HSM_NEED_DECRPYT != OdoHsmDefaultRam_Flag)
		{
			Odo_HsmDefaultStatus = e_OdoHSMSts_KeyCompareSame;
			return Odo_HsmDefaultStatus;
		}
		else
		{
			//All block need to Decrypt
			Odo_HsmDefaultStatus = e_OdoHSMSts_GenerateKey; // continue
		}
	}

	if (e_OdoHSMSts_GenerateKey == Odo_HsmDefaultStatus)
	{
		OdoHsmDefaultConstLen = 16;
		(void)Rte_Call_Hsm_Port_TrngGenerate(&OdoHsmKeyRamData[0][0],&OdoHsmDefaultConstLen);
		OdoHsmDefaultConstLen = 16;
		(void)Rte_Call_Hsm_Port_TrngGenerate(&OdoHsmKeyRamData[0][16],&OdoHsmDefaultConstLen);
		OdoHsmDefaultConstLen = 16;
		(void)Rte_Call_HsmKeyM_SetAes128Key(&OdoHsmKeyRamData[0][0],&OdoHsmKeyRamData[0][16],OdoHsmDefaultConstLen);

		Odo_HsmDefaultStatus = e_OdoHSMSts_KeyWaitSave; // continue
	}

	if (e_OdoHSMSts_KeyWaitSave == Odo_HsmDefaultStatus)
	{
		OdoHsmDefaultConstLen = 16;
		(void)Rte_Call_HsmKeyM_GetAes128Key(&OdoHsmKeyRamData[1][0],&OdoHsmKeyRamData[1][16],&OdoHsmDefaultConstLen);

		if(E_OK == memcmp(&OdoHsmKeyRamData[0][0],&OdoHsmKeyRamData[1][0],32))
		{
			Odo_HsmDefaultStatus = e_OdoHSMSts_KeyCompareSame;  // continue
			SWC_ODO_INFO_LOG("Key Saved");
		}
		else
		{
			return Odo_HsmDefaultStatus;	//wait next cycle
		}	
	}

	if (e_OdoHSMSts_KeyCompareSame == Odo_HsmDefaultStatus)
	{
		for(temp = 0;temp < ODO_PKG_NUMBER_OF_ODO_SETS;temp ++)
		{
			if(FALSE != (OdoHsmDefaultRam_Flag & ((uint8)(0x01u << temp))))
			{
				OdoHsmDefaultConstLen = 16;
				Odo_NvmBoWrite(Odo_NvmBlockTbl[temp].Local_Ptr,Odo_NvmBlockTbl[temp].Default_Ptr,(uint8)OdoHsmDefaultConstLen);
			}
		}
		Odo_HsmDefaultStatus = e_OdoHSMSts_SaveNvmValueOK; // continue
	}

	if (e_OdoHSMSts_SaveNvmValueOK == Odo_HsmDefaultStatus)
	{
		if(0x00 == (Odo_Api_RteNvmWrite_Get() & 0x1Fu))
		{
			SWC_ODO_INFO_LOG("Encrypt data saved");
			Odo_HsmDefaultStatus = e_OdoHSMSts_WriteNvmValueOK;
			OdoHsmDecryptRam_Flag = ODO_HSM_NEED_DECRPYT;
		}
		return Odo_HsmDefaultStatus;
	}

	if (e_OdoHSMSts_WriteNvmValueOK == Odo_HsmDefaultStatus)
	{
		if(0x00 == Odo_RteReadNvmData())
		{
			SWC_ODO_INFO_LOG("First time Dncrypt data success");
			Odo_HsmDefaultStatus = e_OdoHSMSts_NvmInitFinish;
		}
		return Odo_HsmDefaultStatus;
	}

	return Odo_HsmDefaultStatus;
}

/**********************************************************************************************************
*Function   : Odo_RteReadNvmData                                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : uint8 : decrypt flag                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 Odo_RteReadNvmData(void)
{
	uint8 temp;
	e_OdoHsmCrypt_t result;
	for(temp = 0;temp < e_OdoBlock_ODO_NVM_BLOCK_ALL;temp ++)
	{
		if(FALSE != (OdoHsmDecryptRam_Flag & (0x01u << temp)))
		{
			result = Odo_HSMDncryptCheck(temp);
			if(e_OdoHsmStatus_Free == result)
			{
				OdoHsmDecryptRam_Flag &= ~(0x01u << temp);
			}
			else if(e_OdoHsmStatus_Error == result)
			{
				(void)SWC_ODO_ERROR_LOG("d% Dncrypt error",temp);
				Odo_HSMDecryptFlag_Clear(e_OdoHsmStatus_Free);
			}
			else
			{
				break;
			}
		}
	}
	return OdoHsmDecryptRam_Flag;
}

/**********************************************************************************************************
*Function   : Odo_RteHsmEncryptData                                                                       *
*                                                                                                         *
*Description: Check data need to encrypt                                                                  *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : uint8 : encrypt flag                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 Odo_RteHsmEncryptData(void)
{
	uint8 temp;
	e_OdoHsmCrypt_t result; 
	for(temp = 0;temp < e_OdoBlock_ODO_NVM_BLOCK_ALL;temp ++)
	{
		if(FALSE != (OdoHsmEncryptRam_Flag & (0x01u << temp)))
		{
			result = Odo_HSMEncryptCheck(temp);
			if(e_OdoHsmStatus_Free == result)
			{
				OdoHsmEncryptRam_Flag &= ~(0x01u << temp);
			}
			else if(e_OdoHsmStatus_Error == result)
			{
				(void)SWC_ODO_ERROR_LOG("d% Encrypt error",temp);
				Odo_HSMEncryptFlag_Clear(e_OdoHsmStatus_Free);
			}
			else
			{
				break;
			}
		}
	}
	return OdoHsmEncryptRam_Flag;
}

/**********************************************************************************************************
*Function   : Odo_HSMEncryptCheck                                                                         *
*                                                                                                         *
*Description: ODO HSM Encrypt function                                                                    *
*                                                                                                         *
*Parameter  : TBD                                                                                         *
*                                                                                                         *
*Return     : e_OdoHsmStatus_t :current status                                                            *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-7                                                                                   *
**********************************************************************************************************/
e_OdoHsmCrypt_t Odo_HSMEncryptCheck(uint8 index)
{
	e_OdoHsmCrypt_t status = OdoHsmEncryptRam_Sts;
	
	OdoHsmDefaultConstLen = 16;
	if(e_OdoHsmStatus_Free == status)
	{
		if(E_OK == Os_Call_Csm_Encrypt(CsmConf_CsmJob_CsmJob_Aes128_Encrypt,7,Odo_NvmBlockTbl[index].Local_Ptr,
						16,
						OdoHsmEncryptRam_s[index].OdoRamData,
						&OdoHsmDefaultConstLen))
		{
			OdoHsmEncryptRam_Sts = e_OdoHsmStatus_Start;
			Odo_OstmTimerStart((uint8)e_OdoTimer9,1000);
		}
		else
		{
			(void)SWC_ODO_ERROR_LOG("d% Encrypt req err",index);
			Odo_OstmTimerStop((uint8)e_OdoTimer9);
			OdoHsmEncryptRam_Sts = e_OdoHsmStatus_Error;
		}
	}
	else if((uint8)e_OdoHsmStatus_Start == status)
	{
		if(ODO_OSTM_TIMER_OVER == Odo_OstmTimerCheck((uint8)e_OdoTimer9))
		{
			Odo_OstmTimerStop((uint8)e_OdoTimer9);
			(void)SWC_ODO_ERROR_LOG("d% Encrypt timeout",index);
			OdoHsmEncryptRam_Sts = e_OdoHsmStatus_Error;
		}
	}
	else if(e_OdoHsmStatus_Success == status)
	{
		Odo_OstmTimerStop((uint8)e_OdoTimer9);
		OdoHsmEncryptRam_Sts = e_OdoHsmStatus_Free;
	}
	else
	{
		Odo_OstmTimerStop((uint8)e_OdoTimer9);
	}
	return OdoHsmEncryptRam_Sts;
}

/**********************************************************************************************************
*Function   : Odo_HSMDncryptCheck                                                                         *
*                                                                                                         *
*Description: ODO HSM Decrypt function                                                                    *
*                                                                                                         *
*Parameter  : TBD                                                                                         *
*                                                                                                         *
*Return     : e_OdoHsmStatus_t :current status                                                            *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-7                                                                                   *
**********************************************************************************************************/
e_OdoHsmCrypt_t Odo_HSMDncryptCheck(uint8 index)
{
	e_OdoHsmCrypt_t status = OdoHsmDecryptRam_Sts;

	OdoHsmDefaultConstLen = 16;
	if(e_OdoHsmStatus_Free == status)
	{
		if(E_OK == Os_Call_Csm_Decrypt(CsmConf_CsmJob_CsmJob_Aes128_Decrypt,7,Odo_NvmBlockTbl[index].Ram_Ptr,
						16,
						OdoHsmDecryptRam_s.OdoRamData,
						&OdoHsmDefaultConstLen))
		{
			OdoHsmDecryptRam_Sts = e_OdoHsmStatus_Start;
			Odo_OstmTimerStart((uint8)e_OdoTimer10,1000);
		}
		else
		{
			Odo_OstmTimerStop((uint8)e_OdoTimer10);
			(void)SWC_ODO_ERROR_LOG("d% Dncrypt req err",index);
			OdoHsmDecryptRam_Sts = e_OdoHsmStatus_Error;
		}
	}
	else if(e_OdoHsmStatus_Start == status)
	{
		if(ODO_OSTM_TIMER_OVER == Odo_OstmTimerCheck((uint8)e_OdoTimer10))
		{
			Odo_OstmTimerStop((uint8)e_OdoTimer10);
			(void)SWC_ODO_ERROR_LOG("d% Dncrypt timeout",index);
			OdoHsmDecryptRam_Sts = e_OdoHsmStatus_Error;
		}
	}
	else if(e_OdoHsmStatus_Success == status)
	{
		Odo_OstmTimerStop((uint8)e_OdoTimer10);
		(void)memcpy(Odo_NvmBlockTbl[index].Local_Ptr,OdoHsmDecryptRam_s.OdoRamData,16);
		OdoHsmDecryptRam_Sts = e_OdoHsmStatus_Free;
	}
	else
	{
		Odo_OstmTimerStop((uint8)e_OdoTimer10);
	}
	return OdoHsmDecryptRam_Sts;
}

/**********************************************************************************************************
*Function   : Odo_HSMEncryptFlag_Clear                                                                    *
*                                                                                                         *
*Description: Flag set status                                                                             *
*                                                                                                         *
*Parameter  : Sts : Set status                                                                            *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-7                                                                                   *
**********************************************************************************************************/
void Odo_HSMEncryptFlag_Clear(e_OdoHsmCrypt_t Sts)
{
	OdoHsmEncryptRam_Sts = Sts;
}

/**********************************************************************************************************
*Function   : Odo_HSMEncryptFlag_Get                                                                      *
*                                                                                                         *
*Description: Flag get status                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : status                                                                                      *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-7                                                                                   *
**********************************************************************************************************/
e_OdoHsmCrypt_t Odo_HSMEncryptFlag_Get(void)
{
	return OdoHsmEncryptRam_Sts;
}

/**********************************************************************************************************
*Function   : Odo_HSMDecryptFlag_Clear                                                                    *
*                                                                                                         *
*Description: Flag set status                                                                             *
*                                                                                                         *
*Parameter  : Sts : Set status                                                                            *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-7                                                                                   *
**********************************************************************************************************/
void Odo_HSMDecryptFlag_Clear(e_OdoHsmCrypt_t Sts)
{
	OdoHsmDecryptRam_Sts = Sts;
}

/**********************************************************************************************************
*Function   : Odo_HSMDecryptFlag_Get                                                                      *
*                                                                                                         *
*Description: Flag get status                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : status                                                                                      *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-7                                                                                   *
**********************************************************************************************************/
e_OdoHsmCrypt_t Odo_HSMDecryptFlag_Get(void)
{
	return OdoHsmDecryptRam_Sts;
}

/**********************************************************************************************************
*Function   : Odo_HSMInitStatus_Get                                                                       *
*                                                                                                         *
*Description: Flag set status                                                                             *
*                                                                                                         *
*Parameter  : Sts : Set status                                                                            *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-7                                                                                   *
**********************************************************************************************************/
e_OdoHSMStatus_t Odo_HSMInitStatus_Get(void)
{
	return Odo_HsmDefaultStatus;
}

/**********************************************************************************************************
*Function   : Odo_OdoMemoryPrint                                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : TBD                                                                                         *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-7                                                                                   *
**********************************************************************************************************/
void Odo_OdoMemoryPrint(uint8 funIndex,uint8 level)
{
	char LogBuffer[20 * 3 + 1] = {0};
	char NumberBuffer[4] = {0};
	uint8 Bindex, Index, LogIndex = 0;
	s_OdoRteGetParament_t OdoMemData;
	switch(funIndex)
	{
		case 0:
		{
			Odo_Api_ParamentGetFunction(&OdoMemData);
			(void)SWC_ODO_LEVEL_LOG(level,"OdoKmValue:%d,%d",OdoMemData.OdoKmValue_u32,OdoMemData.OdoMileValue_u32);
			(void)SWC_ODO_LEVEL_LOG(level,"Trip1KmValue:%d,%d",OdoMemData.TripKmValue_u32[0],OdoMemData.TripMileValue_u32[0]);
			(void)SWC_ODO_LEVEL_LOG(level,"Trip2KmValue:%d,%d",OdoMemData.TripKmValue_u32[1],OdoMemData.TripMileValue_u32[1]);
			(void)SWC_ODO_LEVEL_LOG(level,"FsrvKmValue:%d,%d",OdoMemData.FsrvKmValue_s32,OdoMemData.FsrvMileValue_s32);
			(void)SWC_ODO_LEVEL_LOG(level,"Invalid:%d",OdoMemData.OdoTripIsaInvalid);
			(void)SWC_ODO_LEVEL_LOG(level,"WriteFlag:%d",OdoMemData.NvmBlockWriteFlag);
			(void)SWC_ODO_LEVEL_LOG(level,"ClearData:%d",OdoMemData.ClearData_u32);
			(void)SWC_ODO_LEVEL_LOG(level,"FsrvStatus:%d",OdoMemData.FsrvStatus);
			(void)SWC_ODO_LEVEL_LOG(level,"RunCounter:%d",OdoMemData.RunCounter_u8);
			(void)SWC_ODO_LEVEL_LOG(level,"VinCheckFlag:%d",OdoMemData.VinCheckFlag_u8);
			(void)SWC_ODO_LEVEL_LOG(level,"ClearFlag:%d",OdoMemData.ClearFlag_u8);
			break;
		}
		case 1:
		{
			(void)SWC_ODO_LEVEL_LOG(level,"ODO nvm maping data:");
			for(Bindex = 0;Bindex < 5;Bindex ++)
			{
				for(Index = 0u; Index < 16; Index ++)
				{
					(void)memset(NumberBuffer,(sint32)0x0u,sizeof(NumberBuffer));
					(void)sprintf(NumberBuffer, "%02X ", Odo_NvmBlockTbl[Bindex].Ram_Ptr[Index]);
					(void)strcat(LogBuffer,NumberBuffer);
					LogIndex += 1;	
				}
				(void)SWC_ODO_LEVEL_LOG(level,"block%d:%s",Bindex,LogBuffer);
				(void)memset(LogBuffer,(sint32)0x0u,sizeof(LogBuffer));
				LogIndex = 0;
			}
			break;
		}
		case 2:
		{
			(void)SWC_ODO_LEVEL_LOG(level,"ODO Encrypt data:");
			for(Bindex = 0;Bindex < 5;Bindex ++)
			{
				for(Index = 0u; Index < 16; Index ++)
				{
					(void)memset(NumberBuffer,(sint32)0x0u,sizeof(NumberBuffer));
					(void)sprintf(NumberBuffer, "%02X ", Odo_NvmBlockTbl[Bindex].Enhsm_Ptr[Index]);
					(void)strcat(LogBuffer,NumberBuffer);
					LogIndex += 1;	
				}
				(void)SWC_ODO_LEVEL_LOG(level,"block%d:%s",Bindex,LogBuffer);
				(void)memset(LogBuffer,(sint32)0x0u,sizeof(LogBuffer));
				LogIndex = 0;
			}
			break;
		}
		case 3:
		{
			(void)SWC_ODO_LEVEL_LOG(level,"ODO local real data:");
			for(Bindex = 0;Bindex < 5;Bindex ++)
			{
				for(Index = 0u; Index < 16; Index ++)
				{
					(void)memset(NumberBuffer,(sint32)0x0u,sizeof(NumberBuffer));
					(void)sprintf(NumberBuffer, "%02X ", Odo_NvmBlockTbl[Bindex].Local_Ptr[Index]);
					(void)strcat(LogBuffer,NumberBuffer);
					LogIndex += 1;	
				}
				(void)SWC_ODO_LEVEL_LOG(level,"block%d:%s",Bindex,LogBuffer);
				(void)memset(LogBuffer,(sint32)0x0u,sizeof(LogBuffer));
				LogIndex = 0;
			}
			break;
		}
		case 4:
		{
			(void)SWC_ODO_LEVEL_LOG(level,"Trip nvm data:");
			for(Index = 0u; Index < 20; Index ++)
			{
				(void)memset(NumberBuffer,(sint32)0x0u,sizeof(NumberBuffer));
				(void)sprintf(NumberBuffer, "%02X ", Odo_NvmBlockTbl[5].Ram_Ptr[Index]);
				(void)strcat(LogBuffer,NumberBuffer);
				LogIndex += 1;	
			}
			(void)SWC_ODO_LEVEL_LOG(level,"%s",LogBuffer);
			(void)memset(LogBuffer,(sint32)0x0u,sizeof(LogBuffer));
			LogIndex = 0;
			(void)SWC_ODO_LEVEL_LOG(level,"Trip Local data:");
			for(Index = 0u; Index < 20; Index ++)
			{
				(void)memset(NumberBuffer,(sint32)0x0u,sizeof(NumberBuffer));
				(void)sprintf(NumberBuffer, "%02X ", Odo_NvmBlockTbl[5].Local_Ptr[Index]);
				(void)strcat(LogBuffer,NumberBuffer);
				LogIndex += 1;	
			}
			(void)SWC_ODO_LEVEL_LOG(level,"%s",LogBuffer);
			(void)memset(LogBuffer,(sint32)0x0u,sizeof(LogBuffer));

			break;
		}
		case 5:
		{
			(void)SWC_ODO_LEVEL_LOG(level,"Maintain nvm data:");
			for(Bindex = 0;Bindex < 4;Bindex ++)
			{
				for(Index = 0u; Index < 20; Index ++)
				{
					(void)memset(NumberBuffer,(sint32)0x0u,sizeof(NumberBuffer));
					(void)sprintf(NumberBuffer, "%02X ", Odo_NvmBlockTbl[6].Ram_Ptr[(Bindex * 20) + Index]);
					(void)strcat(LogBuffer,NumberBuffer);
					LogIndex += 1;	
				}
				(void)SWC_ODO_LEVEL_LOG(level,"%s",LogBuffer);
				(void)memset(LogBuffer,(sint32)0x0u,sizeof(LogBuffer));
				LogIndex = 0;
			}
			break;
		}
		case 6:
		{
			(void)SWC_ODO_LEVEL_LOG(level,"Maintain local data:");
			for(Bindex = 0;Bindex < 4;Bindex ++)
			{
				for(Index = 0u; Index < 20; Index ++)
				{
					(void)memset(NumberBuffer,(sint32)0x0u,sizeof(NumberBuffer));
					(void)sprintf(NumberBuffer, "%02X ", Odo_NvmBlockTbl[6].Ram_Ptr[(Bindex * 20) + Index]);
					(void)strcat(LogBuffer,NumberBuffer);
					LogIndex += 1;	
				}
				(void)SWC_ODO_LEVEL_LOG(level,"%s",LogBuffer);
				(void)memset(LogBuffer,(sint32)0x0u,sizeof(LogBuffer));
				LogIndex = 0;
			}
			break;
		}
		default:
		{
			// do nothing
			break;
		}
	}
}

/**********************************************************************************************************
*Function   : Odo_OdoMemoryStartPrint                                                                     *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : uint8                                                                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-7                                                                                   *
**********************************************************************************************************/
void Odo_OdoMemoryStartPrint(uint8 level)
{
	uint8 timerSts = Odo_OstmTimerCheck((uint8)e_OdoTimer12);
	
	if(ODO_OSTM_TIMER_OVER == timerSts)
	{
		Odo_OstmTimerStop((uint8)e_OdoTimer12);
		Odo_OdoMemoryPrint(OdoMenoryPrintfCounter,level);
		if((OdoMenoryPrintfCounter ++) >= 7)
		{
			OdoMenoryPrintfCounter = 0;
		}
	}
	else
	{
		if(ODO_OSTM_TIMER_RUNING != timerSts)
		{
			Odo_OstmTimerStart((uint8)e_OdoTimer12,1000);
		}
	}
}

/**********************************************************************************************************
* END Function                                                                                            *
**********************************************************************************************************/

#define SWC_ODO_STOP_SEC_CODE
#include "SWC_Odo_MemMap.h" 
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
**
**  Revision:      1.0  
**  
**  Author  :      Cao wenping
**
**  Date    :      2020/06/02     Original Version
**
**********************************************************************************************************/

/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/


