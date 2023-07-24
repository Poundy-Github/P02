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
//#include "Com.h"
//#include "VConfig.h"
#include "string.h"
#include "VConfig_CFG.h"
#include "Rte_Common_Normal.h"
#include "IPC_ClusterApp.h"
#include "SWC_IPC_Config.h"
#include "logger_cfg.h"


/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Odo_Interface.h"
#include "SWC_Odo_Interface_Cfg.h"
#include "SWC_Odo_Pkg.h"
#include "SWC_Odo_Adapt.h"
#include "SWC_Fsrv_Process.h"


/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/
/**********************************************************************************************************
* Parament                                                                                                *
**********************************************************************************************************/

/**********************************************************************************************************
*                                                                                                         *
*                                                                                                         *
*   Odo  interface const parament                                                                         *
*                                                                                                         *
*                                                                                                         *
**********************************************************************************************************/
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_ODO_START_SEC_CONST_UNSPECIFIED
#include "SWC_Odo_MemMap.h"

/*Flag of get odo with Uints km/mile*/
/*Modify by Caowenping 20200604*/
//static const boolean Odo_MetricUnits_bool[6] = {FALSE, FALSE, FALSE, TRUE, TRUE, TRUE};

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
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_ODO_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Odo_MemMap.h"

/*Odo value for other funciton,uints km*/
static uint32 Odo_CurrentKmOdo_u32;

/*Odo value for other funciton,uints mile*/
static uint32 Odo_CurrentMileOdo_u32;

/*Odo value for other funciton,uints m*/
static uint32 Odo_CurrentTrip_u32[e_OdoTripMax_enum3];

/*Flag of Diag set ODO, now not use*/
/*static boolean Odo_DiagODOUpdateFlag;*/

/*Counter for input speed or roll counter*/
static uint32 Odo_SpeedAccumulation_u32;

/*Old counter for input speed or roll counter*/
static CanFrameCounterType Odo_OldSpeedAccumulation_u16;

/*Counter for pass time has run;uint m*/
static uint8 Odo_RunCounterFlag_u8;

static uint8 Odo_VinCheckCnt_u8;

static uint8 Odo_VinCheckFlag_u8;

static uint8 Odo_VinCheckFlag_CANOutput_u8;

static uint32 OdoEcmValue; //Modify bug P05-3193

static s_OdoRteGetParament_t OdoRteParament_s;

static uint8 Odo_ValueIsOverLoadFlag_u8;

static boolean Odo_WarnColdInit_Flag;

static e_OdoLocalSetParament_t OdoLocalSetParament_s[2][e_RteOdoSet_All];

#define SWC_ODO_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Odo_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
*                                                                                                         *
*                                                                                                         *
*   Odo test buram parament                                                                               *
*                                                                                                         *
*                                                                                                         *
**********************************************************************************************************/
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
/*Modify by Caowenping 20200604*///static uint32 Odo_TripADataValue_u32 = 0;
/*Modify by Caowenping 20200604*///static uint32 Odo_TripBDataValue_u32 = 0;
/*Counter for pass time has run;uint m*/
#pragma ghs section bss=".buram"
static uint32 Odo_RamFltStart_u32;/*Modify by Caowenping 20200604*/

static sint64 ODO_Reset4HTimeCounter_u64;

static uint8 Odo_IgnOffFlag_u8;

static uint32 Odo_ColdInitFinish_u32;
static uint8 Odo_RunCounter_u8;

/*Always equal to 0xA5, Value other than this indicates error,check ram valid.*/
static uint32 Odo_RamFltEnd_u32;

#pragma ghs section bss=default
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
* End Parament                                                                                            *
**********************************************************************************************************/
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_ODO_START_SEC_CODE
#include "SWC_Odo_MemMap.h"
static void Odo_Api_RteRrobinCheck(void);
static void Odo_Api_NvmWriteCheck(void);
extern void Odo_Api_PkgRrobinTask(void);    // package function

/**********************************************************************************************************
*Function   : Odo_Api_ColdInit                                                                            *
*                                                                                                         *
*Description: KL30_ON call,use for init ram and read ODO e2 parament                                      *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_Api_ColdInit(void)
{
	Odo_RteLocalRamInit();
	OdoRteParament_s.OdoKmValue_u32 = ODO_NVM_ERROR_VALUE;
	OdoRteParament_s.OdoMileValue_u32 = ODO_NVM_ERROR_VALUE;
	(void)Rte_Write_ppSR_SWCNormal_OdoParament_Element(&OdoRteParament_s);
	if(E_OK != Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&Odo_WarnColdInit_Flag))
	{
		Odo_WarnColdInit_Flag = FALSE;
	}
	if((FALSE == Odo_WarnColdInit_Flag) || (0x5A5A5A5A != Odo_ColdInitFinish_u32))
	{
#if 0	//Interface for Trip reset first time KL30_ON
		Odo_Api_ResetTripAll_Set();
#endif
		/*Reset the RAM fault indicators. */
		Odo_RamFltStart_u32	= ODO_RAM_FLTER1_VALID;	//0x55AA55AAul
		Odo_RamFltEnd_u32	= ODO_RAM_FLTER2_VALID;	//0x55AA55AAul
		Odo_CurrentKmOdo_u32 = 0;
		Odo_CurrentMileOdo_u32 = 0;
		Odo_RunCounterFlag_u8 = 0;//FALSE
		Odo_RunCounter_u8 = 0;
		ODO_Reset4HTimeCounter_u64 = 0;
		Odo_VinCheckFlag_u8 = 0;
		Odo_IgnOffFlag_u8 = 0;
		Odo_VinCheckFlag_CANOutput_u8 = 0;
		OdoEcmValue = 0;

		if(e_OdoHSMSts_NvmInitFinish == Odo_Api_DefaultValueCheck())
		{
			Odo_PkgColdInit();

			Odo_PkgResetTrip(0);
			Odo_PkgResetTrip(1);
			Odo_PkgResetTrip(2);
			Fsrv_Api_KSColdInit();
			/*<<- Add cold init start,The flag bit is cleared 
			  at the end of Cold init, if it is not clear, 
			  continue cold initialization next time*/
			Odo_ColdInitFinish_u32 = 0x5A5A5A5A;
		}
	}
	else
	{
		if(e_OdoHSMSts_NvmInitFinish == Odo_Api_DefaultValueCheck())
		{
			Odo_Api_WarmInit();
		}
	}

}
/**********************************************************************************************************
*Function   : Odo_Api_WarmInit                                                                            *
*                                                                                                         *
*Description: Wakeup call once time                                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_Api_WarmInit(void)
{
	/*Call the common init routine*/
	Odo_PkgWarnInit();
	Fsrv_Api_KSWarmInit();
	Odo_VinCheckFlag_u8 = 0;
	Odo_VinCheckFlag_CANOutput_u8 = 0;
	OdoEcmValue = 0;
}

/**********************************************************************************************************
*Function   : Odo_Api_Wakeup                                                                              *
*                                                                                                         *
*Description: Sleep Wake up call,Alltimes not use                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_Api_Wakeup(void)
{
	Odo_RteLocalRamInit();
	/*Sleep Wake up call,Alltimes not use*/
	Odo_Api_WarmInit();
	Fsrv_Api_KSWakeup();
}

/**********************************************************************************************************
*Function   : Odo_Api_TransIntoNormal                                                                     *
*                                                                                                         *
*Description: Call by power mode change from not normal to normal,init data                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_Api_TransIntoNormal(void)
{
	Odo_OstmTimerStart((uint8)e_OdoTimer5,(uint16)ODO_OSTM_TIMER_5_COUNTER);
	Odo_VinCheckCnt_u8 = 0;
}
/**********************************************************************************************************
*Function   : Odo_Api_OutOfNormal                                                                         *
*                                                                                                         *
*Description: Call by power mode change from normal to other,init data                                    *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_Api_OutOfNormal(void)
{
	/*Call the common init routine*/
	Odo_OstmTimerStop((uint8)e_OdoTimer5);
	Odo_VinCheckCnt_u8 = 0;
}

/**********************************************************************************************************
*Function   : Odo_Api_TimeTask                                                                            *
*                                                                                                         *
*Description: Odo interface time task,For add odo value and trip invalid process                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_Api_TimeTask(void)
{
	uint8 i;
	uint8 Odo_Config;
	boolean TripValid_bool = FALSE;

	if(e_OdoHSMSts_NvmInitFinish != Odo_HSMInitStatus_Get())
	{
		if(e_OdoHSMSts_NvmInitFinish == Odo_Api_DefaultValueCheck())
		{
			if((FALSE == Odo_WarnColdInit_Flag) || (0x5A5A5A5A != Odo_ColdInitFinish_u32))
			{
				Odo_PkgColdInit();
				Odo_PkgResetTrip(0);
				Odo_PkgResetTrip(1);
				Odo_PkgResetTrip(2);
				Fsrv_Api_KSColdInit();
				/*<<- Add cold init start,The flag bit is cleared 
				  at the end of Cold init, if it is not clear, 
				  continue cold initialization next time*/
				Odo_ColdInitFinish_u32 = 0x5A5A5A5A;
			}
			else
			{
				Odo_Api_WarmInit();
			}
		}
		Odo_Api_NvmWriteCheck();
		return;
	}
	else
	{
		if(FALSE != Odo_InputPowerOFF())
		{
			Odo_Api_NvmWriteCheck();
			return;
		}
		else
		{
			(void)Odo_PkgAddCounts(Odo_Api_RunCounter_Get(),ODO_PKG_NORMAL);
		}
	}

	if((FALSE != Odo_InputPowerIGN()) && (FALSE != Odo_InputPowerAbnrmal()))
	{
		if(ODO_OSTM_TIMER_OVER == Odo_OstmTimerCheck((uint8)e_OdoTimer5))
		{
			Odo_VINBackUpCheck();
		}
		else
		{
			if(ODO_OSTM_TIMER_CLEAR == Odo_OstmTimerCheck((uint8)e_OdoTimer5))
			{
				Odo_OstmTimerStart((uint8)e_OdoTimer5,Odo_GetLocalConfig((uint8)e_OdoLocal_ODObackup_DelayTime));
				Odo_VinCheckFlag_u8 = 0;//FALSE
				Odo_VinCheckCnt_u8 = 0;
				Odo_VinCheckFlag_CANOutput_u8 = 0;
			}
			Odo_OstmTimerStop((uint8)e_OdoTimer11);
		}
	}
	else
	{
		Odo_OstmTimerStop((uint8)e_OdoTimer5);
		Odo_OstmTimerStop((uint8)e_OdoTimer11);
		OdoEcmValue = 0;
	}

	for(i = 0; i < e_OdoTripMax_enum3; i++)
	{
		TripValid_bool = Odo_PkgTripOdoValue_Get(&(Odo_CurrentTrip_u32[i]), i, TRUE);
		Odo_Config = (uint8)e_OdoLocal_DrivDataARollovervalue + i;
		if(FALSE == TripValid_bool)
		{
			Odo_CurrentTrip_u32[i] = ODO_TRIP_ERROR_VALUE;
		}
		else if(Odo_CurrentTrip_u32[i] > Odo_GetLocalConfig(Odo_Config))
		{
			Odo_PkgResetTrip(i);
		}
		else
		{
			//do nothing
		}

	}
	Odo_Api_PkgRrobinTask();
	Fsrv_Api_KSRRobinTask();
	Odo_Api_RteRrobinTask();

	if((ODO_NVM_ERROR_VALUE) == OdoRteParament_s.OdoKmValue_u32)
	{
		Odo_OdoMemoryStartPrint(LOGGER_LEVEL_ERR);
	}
	else
	{
		Odo_OdoMemoryStartPrint(LOGGER_LEVEL_VERBOSE);
	}

	#ifdef CHIME_RUNABLE_TIME_TEST
		Chime_RteAdaptRunableOstmCheck(ChimeOstmTimer4);
	#endif
}
/**********************************************************************************************************
*Function   : Odo_Api_IrqTimeTask                                                                         *
*                                                                                                         *
*Description: Odo roll counter add task,allways call by 100ms task,if need call by other task,            *
*             ODO_UPDATE_UNIT need to change                                                              *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_Api_IrqTimeTask(void)
{
	uint32	CanMsgCounter_u32;
	uint32	CanMsgRoll_u32;
	CanFrameCounterType input;
	#ifdef CHIME_RUNABLE_TIME_TEST

	Chime_RteAdaptRunableOstmStart(ChimeOstmTimer4);

	#endif
	/*Modify by Caowenping 20200604*/
	/*Get spped calculate configuration valid*/
	Odo_GetAllConfiguration();
	if((FALSE != Odo_InputPowerIGN()) && (FALSE != Odo_InputPowerAbnrmal()))
	{
		if(ODO_FALSE != Odo_GetSpeedMsgEnable())
		{
			input = Odo_GetSpeedMsgValue();

			if(0xffff == input.Data)
			{
				Odo_RunCounterFlag_u8 = 0;//FALSE
			}
			else
			{
				if(FALSE == Odo_RunCounterFlag_u8)
				{
					Odo_RunCounterFlag_u8 = 1;//TRUE;
					Odo_OldSpeedAccumulation_u16 = input;
				}
				else
				{
					//do nothing
				}

				if(input.Data < Odo_OldSpeedAccumulation_u16.Data)
				{
					CanMsgCounter_u32 = (uint32)input.Data +(uint32)ODO_MESSAGE_MAX_VALUE - (uint32)Odo_OldSpeedAccumulation_u16.Data + 1;
				}
				else
				{
					CanMsgCounter_u32 = (uint32)input.Data - (uint32)Odo_OldSpeedAccumulation_u16.Data;
				}

				if(input.Counter < Odo_OldSpeedAccumulation_u16.Counter)
				{
					CanMsgRoll_u32 = (uint32)input.Counter + (uint32)ODO_MESSAGE_ROLLING_MAX_VALUE - (uint32)Odo_OldSpeedAccumulation_u16.Counter + 1;
				}
				else
				{
					CanMsgRoll_u32 = (uint32)input.Counter - (uint32)Odo_OldSpeedAccumulation_u16.Counter;
				}

				Odo_OldSpeedAccumulation_u16 = input;

				if(CanMsgCounter_u32 > (ODO_MAX_SPEED_INPUT * CanMsgRoll_u32))
				{
					CanMsgCounter_u32 = 0;
				}
				else
				{
					//do nothing
				}

				Odo_SpeedAccumulation_u32 = Odo_SpeedAccumulation_u32 + CanMsgCounter_u32;

				while(Odo_SpeedAccumulation_u32 >= ODO_UPDATE_UNIT)
				{
					/*if more than 0.1m, then l_fodo_1m_count_U32++*/
					Odo_SpeedAccumulation_u32 = Odo_SpeedAccumulation_u32 - ODO_UPDATE_UNIT;

					Odo_RunCounter_u8++;

					if(Odo_RunCounter_u8 >= 255)
					{
						Odo_RunCounter_u8 = 0;
					}
				}
			}
		}
		else
		{
			Odo_RunCounterFlag_u8 = 0;//FALSE;
		}
	}
	else
	{
		Odo_RunCounterFlag_u8 = 0;//FALSE;
		//do nothing
	}
}
/**********************************************************************************************************
*Function   : Odo_Api_RunCounter_Get                                                                      *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : u32                                                                                         *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 Odo_Api_RunCounter_Get(void)
{
	return Odo_RunCounter_u8;
}
/**********************************************************************************************************
*Function   : Odo_Api_Odometer_Get                                                                        *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : Uints_u8  get odo value's uints,reference e_OdoUints_t define                               *
*                                                                                                         *
*Return     : u32                                                                                         *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint32 Odo_Api_Odometer_Get(e_OdoUints_t Units_u8)
{
	uint32 OdoValue_u32;
	uint16 Odo0_1mValue;
	uint64 display;
	if((FALSE == Odo_PkgGetCurrentOdo(&Odo_CurrentKmOdo_u32, TRUE)) || (FALSE == Odo_PkgGetCurrentOdo(&Odo_CurrentMileOdo_u32, FALSE)))
	{
		Odo_CurrentKmOdo_u32 = ODO_NVM_ERROR_VALUE;
		Odo_CurrentMileOdo_u32 = ODO_NVM_ERROR_VALUE;
	}

	OdoValue_u32 = Odo_CurrentKmOdo_u32;
	Odo_PkgGetCurrentOdo0_1M(&Odo0_1mValue);
	if(OdoValue_u32 == ODO_NVM_ERROR_VALUE)
	{
		OdoValue_u32 = (uint32)ODO_NVM_ERROR_VALUE;
	}
	else
	{
		display = (OdoValue_u32 * 10) + ((Odo0_1mValue % 100) / 10);
		if(display > ODO_MAX_DISPLAY_VALUE)
		{
			display = ODO_MAX_DISPLAY_VALUE;
		}
		if(e_OdoUints_mile == Units_u8)
		{
			display /= 10;
			Odo_PkgConvertKmToMi(((uint32 *)&display));
			display /= 100;
			if(display >= 621358)
			{
				display = 621358;
			}
		}
		OdoValue_u32 = (uint32)display;
	}
	return OdoValue_u32;
}

/**********************************************************************************************************
*Function   : Odo_Api_ResetOdo_Set                                                                        *
*                                                                                                         *
*Description: Odo reset interface                                                                         *
*                                                                                                         *
*Parameter  : *CntAddr_u8 ,If the number of resets requires binding times,set times address,              *
*                                                                                                         *
*Return     : boolean                                                                                     *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 Odo_Api_ResetOdo_Set(void)
{
	uint32 reset_remaining;
	uint32 reset_max;
	uint32 cur_odo;
	uint8 clear_result = 0;//FALSE;


	reset_remaining = ((uint32)(*Odo_OdoClearAddress_Get()) * 1000) + (*Odo_OdoClearLowAddress_Get());
	reset_max = Odo_GetLocalConfig((uint8)e_OdoLocal_P_ODO_Reset_Distance) * 1000;
	cur_odo = Odo_Api_Odometer_Get(e_OdoUints_1m);

	if(reset_remaining >= (ODO_CLEAR_VALUE_MAX - reset_max))
	{
		if(0x00 == cur_odo)
		{
			Odo_Api_ResetOdoFlag_Set((uint8)e_OdoBlock_Matain_NVM_BLOCK,(uint8)e_OdoWriteSts_Success);
			clear_result = 0x01;
		}
		else if((reset_remaining - (ODO_CLEAR_VALUE_MAX - reset_max)) >= cur_odo)
		{
			Odo_Api_ResetOdoFlag_Set((uint8)e_OdoBlock_Matain_NVM_BLOCK,(uint8)e_OdoWriteSts_Request);
			clear_result = 0x01;
		}
		else
		{
			Odo_Api_ResetOdoFlag_Set((uint8)e_OdoBlock_Matain_NVM_BLOCK,(uint8)e_OdoWriteSts_OutOfRange);
		}
	}
	else
	{
		Odo_Api_ResetOdoFlag_Set((uint8)e_OdoBlock_Matain_NVM_BLOCK,(uint8)e_OdoWriteSts_OutOfRange);
	}
	return clear_result;
}

/**********************************************************************************************************
*Function   : Odo_Api_ResetOdoTask                                                                        *
*                                                                                                         *
*Description: Odo reset interface task                                                                    *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : boolean                                                                                     *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_Api_ResetOdoTask(void)
{
	uint32 reset_remaining;
	uint32 cur_odo;
	uint16 odo_reset_h;
	uint16 odo_reset_l;
	uint16 fsrvValue_u16 = (uint16)Odo_GetLocalConfig((uint8)e_OdoLocal_Maintenance_distance);

	reset_remaining = ((uint32)(*Odo_OdoClearAddress_Get()) * 1000) + (*Odo_OdoClearLowAddress_Get());
	cur_odo = Odo_Api_Odometer_Get(e_OdoUints_1m);

	if(FALSE != Odo_PkgOdoChangeUp(0, 0xA5))
	{
		if(reset_remaining >= cur_odo)
		{
			odo_reset_h = (uint16)((reset_remaining - cur_odo) / 1000);
			odo_reset_l = (uint16)((reset_remaining - cur_odo) % 1000);
		}
		else
		{
			odo_reset_h = 0;
			odo_reset_l = 0;
		}
		Odo_NvmBoWrite((uint8 *)Odo_OdoClearAddress_Get(),(const uint8 *)(&odo_reset_h),2);
		Odo_NvmBoWrite((uint8 *)Odo_OdoClearLowAddress_Get(),(const uint8 *)(&odo_reset_l),2);
		Odo_Api_ResetTripAll_Set();
		(void)Fsrv_Api_NewMilestone_Set((sint32)fsrvValue_u16);
	}
	else
	{
		Odo_Api_ResetOdoFlag_Set((uint8)e_OdoBlock_Matain_NVM_BLOCK,(uint8)e_OdoWriteSts_Fail);
	}
}
/**********************************************************************************************************
*Function   : Odo_Api_ChangeOdo_Set                                                                       *
*                                                                                                         *
*Description: Odo reset interface,if odo is less than current odo but not zero,return is false            *
*                                                                                                         *
*Parameter  : NewOdo_u32                                                                                  *
*                                                                                                         *
*Return     : odo_value 0.0~999999.0km                                                                    *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Odo_Api_ChangeOdo_Set(uint32 NewOdo_u32,uint8 trip_reset)
{
	s_OdoBackupValue_t CurTime_s = Odo_GetCurrentData();
	boolean WritetFlag_bool = FALSE;
	uint64 OdoOffset;
	uint8 OdoOffsetFlg;

	OdoOffset = *Odo_OdoOffsetAddress_Get();
	OdoOffsetFlg = *Odo_OdoOffsetFlgAddress_Get();

	if( NewOdo_u32 <= ODO_MAX_DISPLAY_VALUE )
	{
		WritetFlag_bool = Odo_PkgOdoChangeUp(NewOdo_u32, 0xA5);
		if ((FALSE != WritetFlag_bool) && (FALSE != trip_reset))
		{
			Odo_Api_ResetTripAll_Set();
			if(NewOdo_u32 > CurTime_s.Curodo)
			{
				OdoOffset = OdoOffset + NewOdo_u32 - CurTime_s.Curodo;
				OdoOffsetFlg = 0; //+
			}
			else
			{
				if(OdoOffset < (CurTime_s.Curodo - NewOdo_u32))
				{
					OdoOffset = CurTime_s.Curodo - NewOdo_u32 - OdoOffset;
					OdoOffsetFlg = 1; //-
				}
			}
			
			(void)Odo_NvmBoWrite((uint8 *)Odo_OdoOffsetAddress_Get(), (const uint8 *)(&OdoOffset), 8u);
			(void)Odo_NvmBoWrite((uint8 *)Odo_OdoOffsetFlgAddress_Get(), (const uint8 *)(&OdoOffsetFlg), 1u);
		}
	}
	else
	{
		//do nothing
	}
	return (WritetFlag_bool);

}

/**********************************************************************************************************
*Function   : Odo_Api_TripValue_Get                                                                       *
*                                                                                                         *
*Description: Get trip value by index                                                                     *
*                                                                                                         *
*Parameter  : TripId_u8:0~e_OdoTripMax_enum3-1, get trip index                                            *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint32 Odo_Api_TripValue_Get(uint8 TripId_u8,e_OdoUints_t Uints_u8)
{
	uint32 OdoValue_u32;
	if(TripId_u8 >= ( (uint8)e_OdoTripMax_enum3) )
	{
		TripId_u8 = 0;
	}
	if(Odo_CurrentTrip_u32[TripId_u8] > ((uint32)ODO_TRIP_ERROR_VALUE))
	{
		OdoValue_u32 = ODO_TRIP_ERROR_VALUE;
	}
	else
	{
		OdoValue_u32 = (Odo_CurrentTrip_u32[TripId_u8]) % 1000000;
		if((e_OdoUints_mile == Uints_u8) && (OdoValue_u32!= ODO_TRIP_ERROR_VALUE))
		{
			Odo_PkgConvertKmToMi(&OdoValue_u32);
		}
		else
		{
			//do nothing
		}
		OdoValue_u32 /= 10;
	}
	return OdoValue_u32;
}

/**********************************************************************************************************
*Function   : Odo_Api_ResetTrip_Set                                                                       *
*                                                                                                         *
*Description: Reset trip value by index                                                                   *
*                                                                                                         *
*Parameter  : TripId_u8:0~e_OdoTripMax_enum3-1, Reset trip index                                          *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_Api_ResetTrip_Set(uint8 TripId_u8)
{
	uint8 temp;
	/*Odometer and Trip Odometer application code shall be levreaged from Nissan X61B IC  */
	for(temp = 0;temp < 3;temp ++)
	{
		if(FALSE != (TripId_u8 & ((uint8)0x01 << temp)))
		{
			Odo_PkgResetTrip(temp);
			if(temp < 2)
			{
				(void)Rte_Call_rpCS_SWCNormal_Reset_TC_Module_Data_WriteData((temp + 1U));
			}
		}
	}

}

/**********************************************************************************************************
*Function   : Odo_Api_ResetTripAll_Set                                                                    *
*                                                                                                         *
*Description: Reset all trip value                                                                        *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_Api_ResetTripAll_Set(void)
{
	uint8 i;
 	for(i = 0;i < e_OdoTripMax_enum3; i++)
 	{
		Odo_PkgResetTrip(i);
 	}
	(void)Rte_Call_rpCS_SWCNormal_Reset_TC_Module_Data_WriteData(0);
}

/**********************************************************************************************************
*Function   : Odo_Api_RamCheck_Get                                                                        *
*                                                                                                         *
*Description: Odo Ram check,if needed                                                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Odo_Api_RamCheck_Get(void)
{
	/*Odometer and Trip Odometer application code shall be reused from Nissan X61B IC  */
	boolean OdoRamFlag_bool;
	/*
	** Check the RAM fault indicators scattered throughout the odo RAM.
	*/
	if ((ODO_RAM_FLTER1_VALID != Odo_RamFltStart_u32) || (ODO_RAM_FLTER2_VALID != Odo_RamFltEnd_u32))
	{
		OdoRamFlag_bool = FALSE;
	}
	else
	{
		OdoRamFlag_bool = TRUE;
	}

	return(OdoRamFlag_bool);
}

/**********************************************************************************************************
*Function   : Odo_VINBackUpCheck                                                                          *
*                                                                                                         *
*Description: Odo vin check,if needed                                                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_VINBackUpCheck(void)
{
	uint8 vinnum;
	uint8 status_T11;
	s_NVMVincfgCompareData_t vinfault0 = {{0,0,0,0,0,0,0,0}};
	s_NVMVincfgCompareData_t vinfaultff = {{0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff}};
	s_NVMVincfgCompareData_t vincfg = Odo_OdoBackupVinCfgValue_Get();
	s_NVMVincfgCompareData_t vincan = Odo_VINMessageInputValue();

	vinnum = (uint8)Odo_GetLocalConfig((uint8)e_OdoLocal_ODOVIN_Check_I_nequality_Time);
	//boolean Backup_bool = FALSE;
	if((FALSE != Odo_OdoBackupVinEnalbe_Get()) && (FALSE != Odo_GetLocalConfig((uint8)e_OdoLocal_ODOBACK_ENABLE)))
	{
		if(ODO_FALSE != Odo_GetECMOdoValueEnable()) 
		{
			OdoEcmValue = Odo_GetECMOdoValue();
		}
		else
		{
			//keep last value
		}
		
		if(ODO_FALSE != Odo_VINMessageInputEnable())
		{
			status_T11 = Odo_OstmTimerCheck((uint8)e_OdoTimer11);
			if((ODO_OSTM_TIMER_OVER == status_T11) || (ODO_OSTM_TIMER_CLEAR == status_T11))
			{
				Odo_OstmTimerStart((uint8)e_OdoTimer11,1000);
				if((FALSE == memcmp(vincfg.vincfgC_u8,vincan.vincfgC_u8,sizeof(s_NVMVincfgCompareData_t))) &&\
					(FALSE != memcmp(vincfg.vincfgC_u8,vinfault0.vincfgC_u8,sizeof(s_NVMVincfgCompareData_t))) &&\
					(FALSE != memcmp(vincfg.vincfgC_u8,vinfaultff.vincfgC_u8,sizeof(s_NVMVincfgCompareData_t))))
				{
					Odo_VinCheckCnt_u8 = 0;
					Odo_VinCheckFlag_u8 = 0;//FALSE;
					Odo_VinCheckFlag_CANOutput_u8 = 0;

					if((FALSE == *Odo_OdoBackupFlag_Get()) && (ODO_ECM20_0X3B7_NEVER_RECEIVED != Odo_GetECMOdoBackupSts()))
					{
						Odo_PkgBackupODO();
					}
					else
					{
					}
				}
				else
				{
					if(FALSE != Odo_GetLocalConfig((uint8)e_OdoLocal_P_ODO_BACK_WARNING_ENABLE))
					{
						if(FALSE == Odo_VinCheckFlag_u8)
						{
							if(Odo_VinCheckCnt_u8 < (vinnum - 1))
							{
								Odo_VinCheckCnt_u8 ++;
							}
							else
							{
								Odo_VinCheckCnt_u8 = 0;
								Odo_VinCheckFlag_u8 = 1;//TRUE;
								Odo_VinCheckFlag_CANOutput_u8 = 1;
							}
						}
						else
						{
							Odo_VinCheckCnt_u8 = 0;
						}
					}
					else
					{
						Odo_VinCheckCnt_u8 = 0;
						Odo_VinCheckFlag_u8 = 0;//FALSE;
						Odo_VinCheckFlag_CANOutput_u8 = 0;
					}
				}
			}
		}
		else
		{
			Odo_VinCheckCnt_u8 = 0;
			Odo_VinCheckFlag_u8 = 0;//FALSE;
			Odo_OstmTimerStop((uint8)e_OdoTimer11);
		}
	}
	else
	{
		Odo_VinCheckCnt_u8 = 0;
		Odo_VinCheckFlag_u8 = 0;//FALSE;
		Odo_VinCheckFlag_CANOutput_u8 = 0;
		Odo_OstmTimerStop((uint8)e_OdoTimer11);
		//do nothing
	}
}

/**********************************************************************************************************
*Function   : Odo_Api_VINBackUpError_Get                                                                  *
*                                                                                                         *
*Description: return VIN back up flag                                                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : FALSE: No error,TRUE: Error                                                                 *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 Odo_Api_VINBackUpError_Get(void)
{
	return Odo_VinCheckFlag_u8;
}

/**********************************************************************************************************
*Function   : Odo_PkgBackupODO                                                                            *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_PkgBackupODO(void)
{
	uint16 FsrvValue_u16;
	uint8 backup_u8 = 1;
	s_OdoBackupValue_t CurTime_s = Odo_GetCurrentData();
	s_OdoNVMBackupValue_t backup_nvm;
	uint64 OdoOffset;
	uint8 OdoOffsetFlg;
	FsrvValue_u16 = (uint16)Odo_GetLocalConfig((uint8)e_OdoLocal_Maintenance_distance);

	OdoOffset = *Odo_OdoOffsetAddress_Get();
	OdoOffsetFlg = *Odo_OdoOffsetFlgAddress_Get();
	backup_u8 = 1;

	if((OdoEcmValue <= 9999999)&&((OdoEcmValue * 100) >= CurTime_s.Curodo))
	{
		(void)Odo_NvmBoWrite((uint8 *)Odo_OdoBackupFlag_Get(), (const uint8 *)&backup_u8, 1u);

		if((OdoEcmValue * 100) > CurTime_s.Curodo)
		{
			if(FALSE != Odo_PkgOdoChangeUp((OdoEcmValue * 100u),0xA5))//Modify bug P05-4072
			{
				CurTime_s.TarGet = OdoEcmValue * 100;
			}
			else
			{
				CurTime_s.TarGet = CurTime_s.Curodo;
			}

			if(0 == OdoOffsetFlg)
			{
				OdoOffset = OdoOffset + (OdoEcmValue * 100) - CurTime_s.Curodo;
			}
			else
			{
				if(((OdoEcmValue * 100) - CurTime_s.Curodo) >= OdoOffset)
				{
					OdoOffset = (OdoEcmValue * 100) - CurTime_s.Curodo - OdoOffset;
					OdoOffsetFlg = 0;
				}
				else
				{
					OdoOffset = OdoOffset - ((OdoEcmValue * 100) - CurTime_s.Curodo);
				}
			}
			(void)Odo_NvmBoWrite((uint8 *)Odo_OdoOffsetAddress_Get(), (const uint8 *)(&OdoOffset), 8u);
			(void)Odo_NvmBoWrite((uint8 *)Odo_OdoOffsetFlgAddress_Get(), (const uint8 *)(&OdoOffsetFlg), 1u);
		}
		else
		{
			CurTime_s.TarGet = CurTime_s.Curodo;
		}


		CurTime_s.Curodo = CurTime_s.Curodo / 1000;
		CurTime_s.TarGet = CurTime_s.TarGet / 1000;

		backup_u8 = *Odo_OdoBackupIndex_Get();

		if(backup_u8 < 2)
		{
			backup_u8 ++;
		}
		else
		{
			backup_u8 = 0;
		}

		backup_nvm.year_l = (uint8)(CurTime_s.time.u16Year/100U);
		backup_nvm.year_r = (uint8)(CurTime_s.time.u16Year%100U);
		backup_nvm.month  = (uint8)(CurTime_s.time.u8Month + 1U);
		backup_nvm.day    = CurTime_s.time.u8Day;
		backup_nvm.hour   = CurTime_s.time.u8Hour;
		backup_nvm.minute = CurTime_s.time.u8Minutes;
		backup_nvm.second = CurTime_s.time.u8Seconds;
		backup_nvm.odo_before[0] = (uint8)(CurTime_s.Curodo >> 16);
		backup_nvm.odo_before[1] = (uint8)(CurTime_s.Curodo >> 8);
		backup_nvm.odo_before[2] = (uint8)(CurTime_s.Curodo >> 0);
		backup_nvm.odo_after[0] = (uint8)(CurTime_s.TarGet >> 16);
		backup_nvm.odo_after[1] = (uint8)(CurTime_s.TarGet >> 8);
		backup_nvm.odo_after[2] = (uint8)(CurTime_s.TarGet >> 0);

		(void)Odo_NvmBoWrite((uint8 *)Odo_OdoBackupAddr_Get(backup_u8), (const uint8 *)(&backup_nvm), (uint8)sizeof(s_OdoNVMBackupValue_t));

		(void)Odo_NvmBoWrite((uint8 *)Odo_OdoBackupIndex_Get(), &backup_u8, 1u);

		//FsrvValue_u16 = *Odo_FsrvDefaultValueAddr_Get();

		(void)Fsrv_Api_NewMilestone_Set((sint32)FsrvValue_u16);

		Odo_Api_ResetTripAll_Set();
	}
}
/**********************************************************************************************************
*Function   : Odo_PkgOdoClearValueSet                                                                     *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_PkgOdoClearValueSet(uint16 Newdata)
{
	Odo_NvmBoWrite((uint8 *)Odo_OdoClearAddress_Get(), (const uint8 *)&Newdata, (uint8)sizeof(Newdata));
}

/**********************************************************************************************************
*Function   : Odo_PkgOdoClearVinBackupFlag                                                                *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_PkgOdoClearVinBackupFlag(uint8 num)
{
	Odo_NvmBoWrite((uint8 *)Odo_OdoBackupFlag_Get(), (const uint8 *)&num, (uint8)sizeof(num));
}

/**********************************************************************************************************
*Function   : Odo_Api_ParamentGetFunction                                                                 *
*                                                                                                         *
*Description: Rte get odo message value                                                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : speed in                                                                                    *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_Api_RteRrobinTask(void)
{
	uint8 temp_u8;
	s_FsrvMaintenceInfo_t fsrv_s;
	sint32 MainMile_s32;
	IPC_M2S_ClusterAppAPPOdo_t odo_ipc;
	IPC_M2S_ClusterAppAPPSIA_t sia_ipc;
	s_OdoCanOutputData_t Output;
	uint8 Rte_Config;

	#if 0
	uint8 idtest = 0;
	uint32 datatest = 0;
	uint8 date_test[39];
	Odo_Api_ParamentSetFunction(idtest,&datatest);
	Odo_Api_ParamentGetCsPort(idtest,date_test);
	#endif
	(void)memset(&odo_ipc,0x00,sizeof(odo_ipc));
	(void)memset(&sia_ipc,0x00,sizeof(sia_ipc));
	Odo_Api_RteRrobinCheck();
	/*trip ------------------------------------------------------------------------------*/
	Output.OdoValue_u32 = Odo_Api_Odometer_Get(e_OdoUints_1m)/100;
	OdoRteParament_s.OdoKmValue_u32 = Odo_Api_Odometer_Get(e_OdoUints_1m);
	OdoRteParament_s.OdoMileValue_u32 = Odo_Api_Odometer_Get(e_OdoUints_mile);
	OdoRteParament_s.RunCounter_u8 = Odo_RunCounter_u8;
	for(temp_u8 = 0;temp_u8 < 3;temp_u8 ++)
	{
		Rte_Config = (uint8)e_OdoLocal_DrivDataADisplayEnable + temp_u8;
		if(FALSE != Odo_GetLocalConfig(Rte_Config))
		{
			OdoRteParament_s.TripKmValue_u32[temp_u8] = Odo_Api_TripValue_Get(temp_u8,e_OdoUints_1m);
			OdoRteParament_s.TripMileValue_u32[temp_u8] = Odo_Api_TripValue_Get(temp_u8,e_OdoUints_mile);
		}
		else
		{
			OdoRteParament_s.TripKmValue_u32[temp_u8] = ODO_TRIP_ERROR_VALUE;
			OdoRteParament_s.TripMileValue_u32[temp_u8] = ODO_TRIP_ERROR_VALUE;
		}
	}
	/*fsrv ------------------------------------------------------------------------------*/
	fsrv_s = Fsrv_Api_MaintenanceInfo_Get();
	MainMile_s32 = fsrv_s.MaintenceValue_s32;
	Odo_PkgConvertKmToMi((uint32 *)&MainMile_s32);
	OdoRteParament_s.FsrvMileValue_s32 = MainMile_s32;









	/*end ------------------------------------------------------------------------------*/
	OdoRteParament_s.FsrvKmValue_s32 = fsrv_s.MaintenceValue_s32;
	OdoRteParament_s.FsrvStatus = fsrv_s.Status_u8;
	OdoRteParament_s.RunCounter_u8 = Odo_RunCounter_u8;
	OdoRteParament_s.VinCheckFlag_u8 = Odo_VinCheckFlag_u8;
	Output.VinCompr_u8 = Odo_VinCheckFlag_CANOutput_u8;
	if(ODO_FALSE != Odo_GetSpeedMsgEnable())
	{
		OdoRteParament_s.OdoInputlValid = 0;//FALSE;
	}
	else
	{
		OdoRteParament_s.OdoInputlValid = 1;//TRUE;
	}

	/*ODO ------------------------------------------------------------------------------*/
	if(FALSE == Odo_GetOdoUnit())
	{
		odo_ipc.Value = OdoRteParament_s.OdoKmValue_u32/1000;
		odo_ipc.Uints = 0;
		sia_ipc.Value = OdoRteParament_s.FsrvKmValue_s32;
		sia_ipc.Uints = 0;
	}
	else
	{
		odo_ipc.Value = OdoRteParament_s.OdoMileValue_u32;
		odo_ipc.Uints = 1;
		sia_ipc.Value = OdoRteParament_s.FsrvMileValue_s32;
		sia_ipc.Uints = 1;
	}
	/*Odo valid*/
	if((ODO_NVM_ERROR_VALUE) != OdoRteParament_s.OdoKmValue_u32)
	{
		/*Check max value and input valid*/
		if((FALSE == Odo_ValueIsOverLoadFlag_u8) && (FALSE == OdoRteParament_s.OdoInputlValid) && (FALSE == OdoRteParament_s.VinCheckFlag_u8))
		{
			Output.ValidFlag_u8 = 1;//TRUE;//valid
		}
		else
		{
			Output.ValidFlag_u8 = 0;//FALSE;//Ivalid
		}
		OdoRteParament_s.OdoTripIsaInvalid = 0;//FALSE; //valid
		if(FALSE != Odo_GetLocalConfig((uint8)e_OdoLocal_FIXEDDISPLAY_1_ODO_ENABLE))
		{
			if(FALSE == OdoRteParament_s.VinCheckFlag_u8 )
			{
				odo_ipc.Valid = 0x00;//valid
			}
			else
			{
				odo_ipc.Valid = 0x02;//display ---
			}
		}
		else
		{
			odo_ipc.Valid = 0x03;//No display
		}
		if(FALSE != OdoRteParament_s.VinCheckFlag_u8)
		{
			Output.OdoValue_u32 = 0xFFFFFF;
		}
	}
	else
	{
		Output.ValidFlag_u8 = 0;//FALSE ;//Invalid
		Output.OdoValue_u32 = 0xFFFFFF;
		OdoRteParament_s.OdoTripIsaInvalid = 1;//TRUE; //Invalid
		if(FALSE != Odo_GetLocalConfig((uint8)e_OdoLocal_FIXEDDISPLAY_1_ODO_ENABLE))
		{
			odo_ipc.Valid = 0x01;//Invalid,dislpay error
		}
		else
		{
			odo_ipc.Valid = 0x03;//No display
		}
	}
	sia_ipc.Valid = odo_ipc.Valid;
	Odo_SetCanOutput(Output);
	(void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_ODOMETER,(uint8 *)&odo_ipc,(uint16)sizeof(IPC_M2S_ClusterAppAPPOdo_t),FALSE);

	(void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_SIA,(uint8 *)&sia_ipc,(uint16)sizeof(IPC_M2S_ClusterAppAPPSIA_t),FALSE);

	(void)Rte_Write_ppSR_SWCNormal_OdoParament_Element(&OdoRteParament_s);

}
/**********************************************************************************************************
*Function   : Odo_Api_RteRrobinCheck                                                                      *
*                                                                                                         *
*Description: Rte get check runable judge                                                                 *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : speed in                                                                                    *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
static void Odo_Api_RteRrobinCheck(void)
{
	sint64 timetick;
	sint64 basetick;
	sint64 resettime;
	uint8 readSts;
	uint32 u32TempData = 0;

	/*Get current system ticktime*/
	u32TempData = Odo_GetLocalConfig((uint8)e_OdoLocal_DrivDataARestTime) * ODO_OSTM_TIMER_6_COUNTER;
	resettime = (sint64)u32TempData;
	readSts = Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_UtcTime(&timetick);
	Rte_Enter_ExclusiveArea_Normal();
	basetick = ODO_Reset4HTimeCounter_u64;
	Rte_Exit_ExclusiveArea_Normal();
	if(FALSE != Odo_InputPowerIGN())
	{
		if(TRUE == Odo_IgnOffFlag_u8)
		{
			if((RTE_E_OK == readSts)&&(Rte_InitValue_tiSR_Rte_Read_Sd_RTC_Data_UtcTime != timetick ))
			{
				/*Set Off get ticktime flag to false*/
				Odo_IgnOffFlag_u8 = 0;//FALSE;
				/*if first time task is ING_ON,need to check time pass,but not case base time is zero*/
				if((0 != basetick) && ((timetick - basetick) >= resettime))
				{
					Odo_Api_ResetTrip_Set(1);
					/*IGN_ON reset,Clear base time*/
					Rte_Enter_ExclusiveArea_Normal();
					ODO_Reset4HTimeCounter_u64 = 0;
					Rte_Exit_ExclusiveArea_Normal();
				}
			}
		}

	}
	else
	{
		if(FALSE == Odo_IgnOffFlag_u8)
		{
			if((RTE_E_OK == readSts)&&(Rte_InitValue_tiSR_Rte_Read_Sd_RTC_Data_UtcTime != timetick ))
			{
				/*first time ING_OFF,set base time to tick*/
				Rte_Enter_ExclusiveArea_Normal();
				ODO_Reset4HTimeCounter_u64 = timetick;
				Rte_Exit_ExclusiveArea_Normal();
				Odo_IgnOffFlag_u8 = 1;//TRUE;

			}
		}
		else
		{
			if((RTE_E_OK == readSts)&&(Rte_InitValue_tiSR_Rte_Read_Sd_RTC_Data_UtcTime != timetick ))
			{
				if((timetick - basetick) >= resettime)
				{
					Odo_Api_ResetTrip_Set(1);
					Rte_Enter_ExclusiveArea_Normal();
					ODO_Reset4HTimeCounter_u64 = timetick;
					Rte_Exit_ExclusiveArea_Normal();
				}
			}

		}
	}
	Odo_Api_ParamentSetLocalTask();
	Odo_Api_NvmWriteCheck();
}

/**********************************************************************************************************
*Function   : ODO_callback                                                                      		  *
*                                                                                                         *
*Description: when rte time Sync,get boforeSyncTime and afterSyncTime                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     :                                                                                    		  *
*                                                                                                         *
*Author     : Wangtingting                                                                                *
*                                                                                                         *
*Date       : 2021-06-10                                                                                  *
**********************************************************************************************************/


void ODO_callback(sint64 pre_time,sint64 now_time)
{
	if(FALSE == Odo_InputPowerIGN())
	{
		/*if flag is not set ,means base time not set*/
		if(FALSE != Odo_IgnOffFlag_u8)
		{
			ODO_Reset4HTimeCounter_u64 = ODO_Reset4HTimeCounter_u64 + now_time - pre_time;

		}
	}
}


/**********************************************************************************************************
*Function   : Odo_Api_ParamentGetFunction                                                                 *
*                                                                                                         *
*Description: Rte get odo message value                                                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : speed in                                                                                    *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
static void Odo_Api_NvmWriteCheck(void)
{
	uint8 temp;
	if(0x00 == (Odo_RteHsmEncryptData() & (uint8)0x1F))
	{
		for(temp = 0;temp < e_OdoBlock_ODO_NVM_BLOCK_ALL;temp ++)
		{
			if(FALSE != (OdoRteParament_s.NvmBlockWriteFlag & ((uint32)0x01 << temp)))
			{
				Odo_NvmWrite(temp);
			}
		}
	}
}

/**********************************************************************************************************
*Function   : Odo_Api_ParamentGetFunction                                                                 *
*                                                                                                         *
*Description: Rte get odo message value                                                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : speed in                                                                                    *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Odo_Api_ParamentGetFunction(s_OdoRteGetParament_t *data)
{
	(void)memcpy(data,&OdoRteParament_s,sizeof(s_OdoRteGetParament_t));
}

/**********************************************************************************************************
*Function   : Odo_Api_ParamentSetFunction                                                                 *
*                                                                                                         *
*Description: Rte runable clear cs port                                                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : wait nvm clear                                                                              *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-05                                                                                  *
**********************************************************************************************************/
uint8 Odo_Api_ParamentSetFunction(uint8 SetId,uint32 *data)
{
	uint8 result_u8 = 0;//FALSE;
	Rte_Enter_ExclusiveArea_Normal();
	switch(SetId)
	{
		case (uint8)e_RteOdoSet_ResetOdo:
			result_u8= Odo_Api_ResetOdo_Set();
			if(0x01 == result_u8)
			{
				OdoLocalSetParament_s[0][SetId].ClearFlag_u8= 1;//TRUE;
			}
			if(0x00 != result_u8)
			{
				result_u8 = 1;//TRUE;
			}
			break;
		case (uint8)e_RteOdoSet_ResetTrip:
			OdoLocalSetParament_s[0][SetId].ClearFlag_u8= 1;//TRUE;
			OdoLocalSetParament_s[0][SetId].ClearData = *data;
			result_u8 = 1;//TRUE;
			break;
		case (uint8)e_RteOdoSet_ResetTripAll:
			OdoLocalSetParament_s[0][SetId].ClearFlag_u8= 1;//TRUE;
			result_u8 = 1;//TRUE;
			break;
		case (uint8)e_RteOdoSet_NewFsrv:
			if(*data <= 65535)
			{
				result_u8 = 1;//TRUE;
				OdoLocalSetParament_s[0][SetId].ClearFlag_u8= 1;//TRUE;
				OdoLocalSetParament_s[0][SetId].ClearData = *data;
			}
			break;
		case (uint8)e_RteOdoSet_DefFsrv:
			if((uint32)*Odo_FsrvDefaultValueAddr_Get() <= 65535)
			{
				OdoLocalSetParament_s[0][SetId].ClearFlag_u8= 1;//TRUE;
				OdoLocalSetParament_s[0][SetId].ClearData = (uint32)*Odo_FsrvDefaultValueAddr_Get();
			}
			break;
		case (uint8)e_RteOdoSet_NewDefFsrv:
			OdoLocalSetParament_s[0][SetId].ClearFlag_u8= 1;//TRUE;
			OdoLocalSetParament_s[0][SetId].ClearData  = *data;
			break;
		case (uint8)e_RteOdoSet_ClearBackUpFlag:
			OdoLocalSetParament_s[0][SetId].ClearFlag_u8= 1;//TRUE;
			result_u8 = 1;//TRUE;
			break;
		case (uint8)e_RteOdoSet_ChangeTripBaseOnOdo:
			OdoLocalSetParament_s[0][SetId].ClearFlag_u8= 1;//TRUE;
			OdoLocalSetParament_s[0][SetId].ClearData  = *data;
			result_u8 = 1;//TRUE;
			break;
		case (uint8)e_RteOdoSet_ConstWriteOdo:
			if(0x3B9ACA00 > (uint32)*data)
			{
				OdoLocalSetParament_s[0][SetId].ClearFlag_u8= 1;//TRUE;
				OdoLocalSetParament_s[0][SetId].ClearData  = *data;
				result_u8 = 1;//TRUE;
			}
			break;
 		default: result_u8 = 0;//FALSE;
			break;
	}
	Rte_Exit_ExclusiveArea_Normal();
	return result_u8;
}
/**********************************************************************************************************
*Function   : Odo_Api_ParamentSetLocalTask                                                                *
*                                                                                                         *
*Description: Rte runable clear local task                                                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2021-01-015                                                                                 *
**********************************************************************************************************/
void Odo_Api_ParamentSetLocalTask(void)
{
	Rte_Enter_ExclusiveArea_Normal();
	(void)memcpy(&OdoLocalSetParament_s[1],&OdoLocalSetParament_s[0],sizeof(e_OdoLocalSetParament_t));
	(void)memset(&OdoLocalSetParament_s[0],0,sizeof(e_OdoLocalSetParament_t));
	Rte_Exit_ExclusiveArea_Normal();
	if(FALSE != OdoLocalSetParament_s[0][e_RteOdoSet_ResetOdo].ClearFlag_u8)
	{
		OdoLocalSetParament_s[0][e_RteOdoSet_ResetOdo].ClearFlag_u8 = 0;//FALSE;
		Odo_Api_ResetOdoTask();
	}
	if(FALSE != OdoLocalSetParament_s[0][e_RteOdoSet_ResetTrip].ClearFlag_u8)
	{
		OdoLocalSetParament_s[0][e_RteOdoSet_ResetTrip].ClearFlag_u8 = 0;//FALSE;
		Odo_Api_ResetTrip_Set((uint8)OdoLocalSetParament_s[0][e_RteOdoSet_ResetTrip].ClearData);
	}
	if(FALSE != OdoLocalSetParament_s[0][e_RteOdoSet_ResetTripAll].ClearFlag_u8)
	{
		OdoLocalSetParament_s[0][e_RteOdoSet_ResetTripAll].ClearFlag_u8 = 0;//FALSE;
		Odo_Api_ResetTripAll_Set();
	}
	if(FALSE != OdoLocalSetParament_s[0][e_RteOdoSet_NewFsrv].ClearFlag_u8)
	{
		OdoLocalSetParament_s[0][e_RteOdoSet_NewFsrv].ClearFlag_u8 = 0;//FALSE;
		(void)Fsrv_Api_NewMilestone_Set((sint32)OdoLocalSetParament_s[0][e_RteOdoSet_NewFsrv].ClearData);
	}
	if(FALSE != OdoLocalSetParament_s[0][e_RteOdoSet_DefFsrv].ClearFlag_u8)
	{
		OdoLocalSetParament_s[0][e_RteOdoSet_DefFsrv].ClearFlag_u8 = 0;//FALSE;
		(void)Fsrv_Api_NewMilestone_Set((sint32)OdoLocalSetParament_s[0][e_RteOdoSet_DefFsrv].ClearData);
	}
	if(FALSE != OdoLocalSetParament_s[0][e_RteOdoSet_NewDefFsrv].ClearFlag_u8)
	{
		OdoLocalSetParament_s[0][e_RteOdoSet_NewDefFsrv].ClearFlag_u8 = 0;//FALSE;
		(void)Fsrv_Api_DefaultMilestone_Set((uint16)OdoLocalSetParament_s[0][e_RteOdoSet_NewDefFsrv].ClearData);
	}
	if(FALSE != OdoLocalSetParament_s[0][e_RteOdoSet_ClearBackUpFlag].ClearFlag_u8)
	{
		OdoLocalSetParament_s[0][e_RteOdoSet_ClearBackUpFlag].ClearFlag_u8 = 0;//FALSE;
		Odo_PkgOdoClearVinBackupFlag((uint8)OdoLocalSetParament_s[0][e_RteOdoSet_ClearBackUpFlag].ClearData);
	}
	if(FALSE != OdoLocalSetParament_s[0][e_RteOdoSet_ChangeTripBaseOnOdo].ClearFlag_u8)
	{
		OdoLocalSetParament_s[0][e_RteOdoSet_ChangeTripBaseOnOdo].ClearFlag_u8 = 0;//FALSE;
		//(void)Odo_Api_ChangeOdo_Set(OdoLocalSetParament_s[0][e_RteOdoSet_ChangeTripBaseOnOdo].ClearData,0);//FALSE
	}
	if(FALSE != OdoLocalSetParament_s[0][e_RteOdoSet_ConstWriteOdo].ClearFlag_u8)
	{
		OdoLocalSetParament_s[0][e_RteOdoSet_ConstWriteOdo].ClearFlag_u8 = 0;//FALSE;
		(void)Odo_Api_ChangeOdo_Set(OdoLocalSetParament_s[0][e_RteOdoSet_ConstWriteOdo].ClearData,1);//FALSE
	}

}

/**********************************************************************************************************
*Function   : Odo_Api_RteNvmWrite_Set                                                                     *
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
void Odo_Api_RteNvmWrite_Set(uint8 BlkId,boolean control)
{
	if(FALSE != control)
	{
		OdoRteParament_s.NvmBlockWriteFlag |= ((uint32)0x01 << BlkId);
	}
	else
	{
		OdoRteParament_s.NvmBlockWriteFlag &= ~((uint32)0x01 << BlkId);
	}
}

/**********************************************************************************************************
*Function   : Odo_Api_RteNvmWrite_Get                                                                     *
*                                                                                                         *
*Description: Set block get   flag                                                                        *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : uint32                                                                                      *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-05                                                                                  *
**********************************************************************************************************/
uint32 Odo_Api_RteNvmWrite_Get(void)
{
	return OdoRteParament_s.NvmBlockWriteFlag;
}

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


