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
**  Name:               SWC_Odo_Interface.h
**
**  Description:        Odo moudle interface file to other.Include init and get Odo data 
**
**  Organization:       
**
**********************************************************************************************************/
/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef SWC_ODO_ADAPT_H
#define SWC_ODO_ADAPT_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Rte_type.h"

#include "Platform_Types.h"
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* Type of parament                                                                                        *
**********************************************************************************************************/
//#ifndef uint64
//typedef unsigned long long 	uint64;
//#endif
#define SWC_ODO_PRINTF_LEVEL2
//#define SWC_ODO_PRINTF_LEVEL2
//#define SWC_ODO_PRINTF_LEVEL3


#ifdef SWC_ODO_PRINTF_LEVEL1

#define SWC_ODO_INFO_LOG(...)

#define SWC_ODO_WARN_LOG(...)

#define SWC_ODO_ERROR_LOG						vipodo_err

#define SWC_ODO_VERBOSE_LOG						vipodo_verbose

#define SWC_ODO_LEVEL_LOG						vipodo_level

#elif defined SWC_ODO_PRINTF_LEVEL2

#define SWC_ODO_INFO_LOG(...)

#define SWC_ODO_WARN_LOG						vipodo_warn

#define SWC_ODO_ERROR_LOG						vipodo_err

#define SWC_ODO_VERBOSE_LOG						vipodo_verbose

#define SWC_ODO_LEVEL_LOG						vipodo_level

#elif defined SWC_ODO_PRINTF_LEVEL3

#define SWC_ODO_INFO_LOG						vipodo_info

#define SWC_ODO_WARN_LOG						vipodo_warn

#define SWC_ODO_ERROR_LOG						vipodo_err

#define SWC_ODO_VERBOSE_LOG						vipodo_verbose

#define SWC_ODO_LEVEL_LOG						vipodo_level

#else
#define SWC_ODO_INFO_LOG(...)

#define SWC_ODO_WARN_LOG(...)

#define SWC_ODO_ERROR_LOG(...)
#endif

#ifdef GWM_V35_PROJECT_TYPE_B03
	#define ODO_PROJECT_TYPE_B03		1
	#define ODO_PROJECT_TYPE_B02		0
	#define ODO_PROJECT_TYPE_P05		0
	#define ODO_PROJECT_TYPE_B06		0
	#define ODO_PROJECT_TYPE_P03		0
	#define ODO_PROJECT_TYPE_A07		0
	#define ODO_PROJECT_TYPE_D01		0
	#define ODO_PROJECT_TYPE_D02		0
	#define ODO_PROJECT_TYPE_D03		0
	#define ODO_PROJECT_TYPE_P02		0
	#define ODO_PROJECT_TYPE_P01		0
#elif defined GWM_V35_PROJECT_TYPE_B02
	#define ODO_PROJECT_TYPE_B03		0
	#define ODO_PROJECT_TYPE_B02		1
	#define ODO_PROJECT_TYPE_P05		0
	#define ODO_PROJECT_TYPE_B06		0
	#define ODO_PROJECT_TYPE_P03		0
	#define ODO_PROJECT_TYPE_A07		0
	#define ODO_PROJECT_TYPE_D01		0
	#define ODO_PROJECT_TYPE_D02		0
	#define ODO_PROJECT_TYPE_D03		0
	#define ODO_PROJECT_TYPE_P02		0
	#define ODO_PROJECT_TYPE_P01		0
    #include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define ODO_PROJECT_TYPE_B03		0
	#define ODO_PROJECT_TYPE_B02		0
	#define ODO_PROJECT_TYPE_P05		1
	#define ODO_PROJECT_TYPE_B06		0
	#define ODO_PROJECT_TYPE_P03		0
	#define ODO_PROJECT_TYPE_A07		0
	#define ODO_PROJECT_TYPE_D01		0
	#define ODO_PROJECT_TYPE_D02		0
	#define ODO_PROJECT_TYPE_D03		0
	#define ODO_PROJECT_TYPE_P02		0
	#define ODO_PROJECT_TYPE_P01		0
#elif defined GWM_V35_PROJECT_TYPE_B06
	#define ODO_PROJECT_TYPE_B03		0
	#define ODO_PROJECT_TYPE_B02		0
	#define ODO_PROJECT_TYPE_P05		0
	#define ODO_PROJECT_TYPE_B06		1
	#define ODO_PROJECT_TYPE_P03		0
	#define ODO_PROJECT_TYPE_A07		0
	#define ODO_PROJECT_TYPE_D01		0
	#define ODO_PROJECT_TYPE_D02		0
	#define ODO_PROJECT_TYPE_D03		0
	#define ODO_PROJECT_TYPE_P02		0
	#define ODO_PROJECT_TYPE_P01		0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define ODO_PROJECT_TYPE_B03		0
	#define ODO_PROJECT_TYPE_B02		0
	#define ODO_PROJECT_TYPE_P05		0
	#define ODO_PROJECT_TYPE_B06		0
	#define ODO_PROJECT_TYPE_P03		1
	#define ODO_PROJECT_TYPE_A07		0
	#define ODO_PROJECT_TYPE_D01		0
	#define ODO_PROJECT_TYPE_D02		0
	#define ODO_PROJECT_TYPE_D03		0
	#define ODO_PROJECT_TYPE_P02		0
	#define ODO_PROJECT_TYPE_P01		0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define ODO_PROJECT_TYPE_B03		0
	#define ODO_PROJECT_TYPE_B02		0
	#define ODO_PROJECT_TYPE_P05		0
	#define ODO_PROJECT_TYPE_B06		0
	#define ODO_PROJECT_TYPE_P03		0
	#define ODO_PROJECT_TYPE_A07		1
	#define ODO_PROJECT_TYPE_D01		0
	#define ODO_PROJECT_TYPE_D02		0
	#define ODO_PROJECT_TYPE_D03		0
	#define ODO_PROJECT_TYPE_P02		0
	#define ODO_PROJECT_TYPE_P01		0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define ODO_PROJECT_TYPE_B03		0
	#define ODO_PROJECT_TYPE_B02		0
	#define ODO_PROJECT_TYPE_P05		0
	#define ODO_PROJECT_TYPE_B06		0
	#define ODO_PROJECT_TYPE_P03		0
	#define ODO_PROJECT_TYPE_A07		0
	#define ODO_PROJECT_TYPE_D01		1
	#define ODO_PROJECT_TYPE_D02		0
	#define ODO_PROJECT_TYPE_D03		0
	#define ODO_PROJECT_TYPE_P02		0
	#define ODO_PROJECT_TYPE_P01		0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define ODO_PROJECT_TYPE_B03		0
	#define ODO_PROJECT_TYPE_B02		0
	#define ODO_PROJECT_TYPE_P05		0
	#define ODO_PROJECT_TYPE_B06		0
	#define ODO_PROJECT_TYPE_P03		0
	#define ODO_PROJECT_TYPE_A07		0
	#define ODO_PROJECT_TYPE_D01		0
	#define ODO_PROJECT_TYPE_D02		1
	#define ODO_PROJECT_TYPE_D03		0
	#define ODO_PROJECT_TYPE_P02		0
	#define ODO_PROJECT_TYPE_P01		0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define ODO_PROJECT_TYPE_B03		0
	#define ODO_PROJECT_TYPE_B02		0
	#define ODO_PROJECT_TYPE_P05		0
	#define ODO_PROJECT_TYPE_B06		0
	#define ODO_PROJECT_TYPE_P03		0
	#define ODO_PROJECT_TYPE_A07		0
	#define ODO_PROJECT_TYPE_D01		0
	#define ODO_PROJECT_TYPE_D02		0
	#define ODO_PROJECT_TYPE_D03		1
	#define ODO_PROJECT_TYPE_P02		0
	#define ODO_PROJECT_TYPE_P01		0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define ODO_PROJECT_TYPE_B03		0
	#define ODO_PROJECT_TYPE_B02		0
	#define ODO_PROJECT_TYPE_P05		0
	#define ODO_PROJECT_TYPE_B06		0
	#define ODO_PROJECT_TYPE_P03		0
	#define ODO_PROJECT_TYPE_A07		0
	#define ODO_PROJECT_TYPE_D01		0
	#define ODO_PROJECT_TYPE_D02		0
	#define ODO_PROJECT_TYPE_D03		0
	#define ODO_PROJECT_TYPE_P02		1
	#define ODO_PROJECT_TYPE_P01		0
#elif defined GWM_V35_PROJECT_TYPE_P01
	#define ODO_PROJECT_TYPE_B03		0
	#define ODO_PROJECT_TYPE_B02		0
	#define ODO_PROJECT_TYPE_P05		0
	#define ODO_PROJECT_TYPE_B06		0
	#define ODO_PROJECT_TYPE_P03		0
	#define ODO_PROJECT_TYPE_A07		0
	#define ODO_PROJECT_TYPE_D01		0
	#define ODO_PROJECT_TYPE_D02		0
	#define ODO_PROJECT_TYPE_D03		0
	#define ODO_PROJECT_TYPE_P02		0
	#define ODO_PROJECT_TYPE_P01		1
#else
	#error "No Project defined"
#endif


typedef enum
{
	e_OdoTimer1 = 0,
	e_OdoTimer2,
	e_OdoTimer3,
	e_OdoTimer4,
	e_OdoTimer5,
	e_OdoTimer6,
	e_OdoTimer7,
	e_OdoTimer8,
	e_OdoTimer9,
	e_OdoTimer10,
	e_OdoTimer11,
	e_OdoTimer12,
	e_OdoTimerMax,
}e_OdoTimerNumber_t;

typedef enum
{
	e_OdoBlock_ODO1_NVM_BLOCK = 0,
	e_OdoBlock_ODO2_NVM_BLOCK,
	e_OdoBlock_ODO3_NVM_BLOCK,
	e_OdoBlock_ODO4_NVM_BLOCK,
	e_OdoBlock_ODO5_NVM_BLOCK,
	e_OdoBlock_Trip_NVM_BLOCK,
	e_OdoBlock_Matain_NVM_BLOCK,
	e_OdoBlock_ODO_NVM_BLOCK_ALL,
}e_OdoBlockNumber_t;

typedef enum
{
	e_OdoWriteSts_Nuaa = 0,
	e_OdoWriteSts_Success,
	e_OdoWriteSts_OutOfRange,
	e_OdoWriteSts_Fail,
	e_OdoWriteSts_Request,
	e_OdoWriteSts_All,
}e_OdoBlockWriteSts_t;

typedef enum
{
	e_OdoGetParameter_RealOdo = 1,
	e_OdoGetParameter_Fsrv,
	e_OdoGetParameter_Backup,
	e_OdoGetParameter_ResetOdoResult,
	e_OdoGetParameter_Max,
}e_OdoGetParameter_t;

typedef enum
{
	e_OdoHsmStatus_Free = 0,
	e_OdoHsmStatus_Start,
	e_OdoHsmStatus_Success,
	e_OdoHsmStatus_CpyData,
	e_OdoHsmStatus_Error,
	e_OdoHsmStatus_Max,
}e_OdoHsmCrypt_t;
	

#define ODO_OSTM_TIMER_CLEAR 				(0u)
#define ODO_OSTM_TIMER_OVER					(2u)
#define ODO_OSTM_TIMER_RUNING				(4u)
#define ODO_OSTM_TIMER_START_ERROR			(8u)

#define ODO_ADAPT_NULL_PTRFUN				((void *)0u)
#define ODO_DATA_NULL_PTRFUN				((uint8 *)0u)

typedef enum
{
	e_OdoHSMSts_NvmDefaultValue = 0,
	e_OdoHSMSts_GenerateKey,
	e_OdoHSMSts_KeyWaitSave,
	e_OdoHSMSts_KeyCompareSame,
	e_OdoHSMSts_SaveNvmValueOK,
	e_OdoHSMSts_WriteNvmValueOK,
	e_OdoHSMSts_NvmInitFinish,
	e_OdoHSMSts_Max,
}e_OdoHSMStatus_t;
	
#define ODO_HSM_READ_STATUS					(FALSE)
#define ODO_HSM_SET_STATUS					(TRUE)
#define ODO_HSM_NEED_DECRPYT				(0x1F)

typedef struct
{
	void (*Process)(boolean Status_u8);
}s_OdoWriteCallback_t;


typedef struct
{
	uint32 OdoStartTime_u32;
	uint32 OdoOverTime_u32;
	uint16 OdoStatus;
}s_OdoTimerValue_t;


typedef struct
{
	DateTimeType_t time;
	uint32 Curodo;
	uint32 TarGet;
}s_OdoBackupValue_t;

typedef struct
{
	uint8 hour;
	uint8 minute;
	uint8 second;
	uint8 year_l;
	uint8 year_r;
	uint8 month;
	uint8 day;
	uint8 odo_before[3];
	uint8 odo_after[3];
	uint8 reserved[3];
}s_OdoNVMBackupValue_t;

typedef union
{
	uint8 NvmData[80];
	struct
	{
		s_OdoNVMBackupValue_t BcupDate[3];
		uint8 BcupIdx;
		uint8 BcupFlg;
		uint16 OdoRest;
		uint32 Fsrv;
		uint16 DefFsrv;
		uint16 OdoRestLow;
		uint64 OdoOffset;
		uint8 OdoOffsetFlg;
		uint8 Reserved[15];
	}OdoBlock_t;
}u_NVMBlockOdoOther_t;

typedef struct
{
	uint8 *Ram_Ptr;
	uint8 *Local_Ptr;
	uint8 *Enhsm_Ptr;
	const uint8 *Default_Ptr;
	uint8 Size;
	uint8 (*check)(uint8 *arg);
	uint8 (*writen)(const void *fun);
	s_OdoWriteCallback_t *callback;
}u_NVMBlockOdoAdr_t;

typedef struct
{
	uint8 OdoRamData[16];
}s_OdoRealDataRam_t;

typedef struct
{
	uint8 vincfg_u8[17];
}s_NVMVincfgData_t;

typedef struct
{
	uint8 rollCnt;
	uint16 meterValue;
}s_OdoCanMessageInput_t;

typedef struct
{
	uint8 vincfgC_u8[8];
}s_NVMVincfgCompareData_t;

typedef struct
{
	uint32 OdoValue_u32;
	uint8 ValidFlag_u8;
	uint8 VinCompr_u8;
}s_OdoCanOutputData_t;

typedef enum
{
	e_OdoLocal_P_ODO_Reset_Distance = 0,
	e_OdoLocal_FIXEDDISPLAY_1_ODO_ENABLE,
	e_OdoLocal_ODOBACK_ENABLE,
	e_OdoLocal_P_ODO_BACK_WARNING_ENABLE,
	e_OdoLocal_ODObackup_DelayTime,
	e_OdoLocal_ODOVIN_Check_I_nequality_Time,
	e_OdoLocal_DrivDataARestTime,
	e_OdoLocal_Maintenance_distance,
	e_OdoLocal_DrivDataARollovervalue,
	e_OdoLocal_DrivDataBRollovervalue,
	e_OdoLocal_DrivDataCRollovervalue,
	e_OdoLocal_DrivDataADisplayEnable,
	e_OdoLocal_DrivDataBDisplayEnable,
	e_OdoLocal_DrivDataCDisplayEnable,
	e_OdoLocal_Max,
}e_OdoLocalConfig_t;

typedef struct
{
	uint8 Vconfig_KIND_ENGINE_CONTROL_UNIT;
	uint8 Vconfig_KIND_TRANSMISSION;
	uint8 Vconfig_KIND_CLUSTER_UNIT_SYSTEM;
	uint8 Vconfig_KIND_PT_CAN_BUS_TYPE;

	A_17Bytes Vconfig_Vinconfig;

//Local config
	uint8 LConfig_DrivDataARestTime;
	uint8 LConfig_FIXEDDISPLAY_1_ODO_ENABLE;
	uint8 LConfig_ODOBACK_ENABLE;
	uint8 LConfig_P_ODO_BACK_WARNING_ENABLE;
	uint8 LConfig_ODOVIN_Check_I_nequality_Time;
	uint8 LConfig_ODObackup_DelayTime;
	uint32 LConfig_Maintenance_distance;
	uint32 LConfig_DrivDataARollovervalue;
	uint32 LConfig_DrivDataBRollovervalue;
	uint32 LConfig_DrivDataCRollovervalue;
	uint8 LConfig_DrivDataADisplayEnable;
	uint8 LConfig_DrivDataBDisplayEnable;
	uint8 LConfig_DrivDataCDisplayEnable;

}s_OdoConfiguration_t;

/**********************************************************************************************************
* start of Function                                                                                       *
**********************************************************************************************************/
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_ODO_START_SEC_CODE
#include "SWC_Odo_MemMap.h" 
void Odo_RteLocalRamInit(void);
boolean Odo_InputPowerAbnrmal(void);
boolean Odo_InputPowerOFF(void);
boolean Odo_InputPowerIGN(void);
uint32 * Odo_TripNvmAddr_Get(uint8 Index_u8);
uint8 * Odo_OdoNvmAddr_Get(uint8 Index_u8);
uint16 * Odo_OdoClearAddress_Get(void);
uint16 * Odo_OdoClearLowAddress_Get(void);
uint64 * Odo_OdoOffsetAddress_Get(void);
uint8 * Odo_OdoOffsetFlgAddress_Get(void);
uint8 * Odo_OdoBackupAddr_Get(uint8 Index_u8);
uint8 * Odo_OdoBackupFlag_Get(void);
uint8 * Odo_OdoBackupIndex_Get(void);
uint32 * Odo_FsrvValueAddr_Get(void);
uint16 * Odo_FsrvDefaultValueAddr_Get(void);
boolean Odo_GetCommonStatus(void);
boolean Odo_NvmBoWriteWithCallback(uint8 *Tar_u8,uint8 *Cur_u8, uint8 Size_u8, void (* Function)(boolean Status_u8));
void Odo_NvmBoWrite(uint8 *Tar_u8,const uint8 *Cur_u8, uint8 Size_u8);
boolean Odo_NvmVolatileWrite(uint8 *Tar_u8,uint8 *Cur_u8, uint8 Size_u8);
//void KernelReportError(uint8 Msg_u8);
void Odo_OstmTimerStart(uint8 Index_u8,uint32 Over_u32);
uint8 Odo_OstmTimerCheck(uint8 Index_u8);
void Odo_OstmTimerStop(uint8 Index_u8);
boolean Odo_OdoBackupVinEnalbe_Get(void);
s_NVMVincfgCompareData_t Odo_OdoBackupVinCfgValue_Get(void);
uint8 Odo_VINMessageInputEnable(void);
s_NVMVincfgCompareData_t Odo_VINMessageInputValue(void);
uint8 Odo_GetECMOdoValueEnable(void);
uint32 Odo_GetECMOdoValue(void);
s_OdoBackupValue_t Odo_GetCurrentData(void);
uint8 Odo_GetSpeedMsgEnable(void);
CanFrameCounterType Odo_GetSpeedMsgValue(void);
void Odo_OstmTimerReferenceProcess(void);
void Odo_NvmWrite(uint8 BlkId);
void Odo_Api_ResetOdoFlag_Set(uint8 BlkId,uint8 control);
uint8 Odo_Api_ResetOdoFlag_Get(uint8 BlkId);
uint8 Odo_GetOdoUnit(void);
uint64 Odo_ReadSleepTimer(void);
void Odo_SetCanOutput(s_OdoCanOutputData_t data);
void Odo_HMIResetTcCallback(uint8 *data);
void Odo_GetAllConfiguration(void);
s_OdoConfiguration_t Odo_ApiGetConfiguration(void);
uint32 Odo_GetLocalConfig(uint8 id_u8);
void Odo_Api_ParamentGetCsPort(uint8 Id,uint8 *data);
s_OdoWriteCallback_t Odo_GetBlockWriteCallback(uint8 index);
void Odo_RteHSMInitData(void);
e_OdoHSMStatus_t Odo_Api_DefaultValueCheck(void);
uint8 Odo_RteReadNvmData(void);
uint8 Odo_RteHsmEncryptData(void);
e_OdoHsmCrypt_t Odo_HSMEncryptCheck(uint8 index);
e_OdoHsmCrypt_t Odo_HSMDncryptCheck(uint8 index);
void Odo_HSMEncryptFlag_Clear(e_OdoHsmCrypt_t Sts);
e_OdoHsmCrypt_t Odo_HSMEncryptFlag_Get(void);
void Odo_HSMDecryptFlag_Clear(e_OdoHsmCrypt_t Sts);
e_OdoHsmCrypt_t Odo_HSMDecryptFlag_Get(void);
e_OdoHSMStatus_t Odo_HSMInitStatus_Get(void);
void Odo_OdoMemoryPrint(uint8 funIndex,uint8 level);
void Odo_OdoMemoryStartPrint(uint8 level);
uint8 Odo_GetECMOdoBackupSts(void);
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

#endif




