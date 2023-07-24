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
**  Name:               SWC_Fsrv_Process.c
**
**  Description:        fsrv moudle interface file to other.Include init and get isa data 
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
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Fsrv_Process.h"
#include "SWC_Odo_Interface.h"
#include "SWC_Odo_Adapt.h"

/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* Internal function declare                                                                               *
**********************************************************************************************************/
/**********************************************************************************************************
* Parament                                                                                                *
**********************************************************************************************************/
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_ODO_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Odo_MemMap.h"

static uint32 Fsrv_NvmMilestone_u32;

static s_FsrvMaintenceInfo_t Fsrv_MaintenceInfo_s;

#define SWC_ODO_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Odo_MemMap.h"
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

/**********************************************************************************************************
*Function   : Fsrv_Api_KSColdInit                                                                         *
*                                                                                                         *
*Description: KL30_ON call,use for init ram                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-07-7                                                                                   *
**********************************************************************************************************/
void Fsrv_Api_KSColdInit(void)
{
	Fsrv_Api_KSWarmInit();
}

/**********************************************************************************************************
*Function   : Fsrv_Api_KSWarmInit                                                                         *
*                                                                                                         *
*Description: KL30_ON call,use for init ram                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-07-7                                                                                   *
**********************************************************************************************************/
void Fsrv_Api_KSWarmInit(void)
{	
	/*Set value to fault value*/
	Fsrv_MaintenceInfo_s.MaintenceValue_s32 = FSRV_MILESTONE_INVALID_VALUE;
	/*Set warning status to normal*/
	Fsrv_MaintenceInfo_s.Status_u8 = MAINTANCE_SERVICE_NROMAL;
}

/**********************************************************************************************************
*Function   : Fsrv_Api_KSWakeup                                                                           *
*                                                                                                         *
*Description: KL30_ON call,use for init ram                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-07-7                                                                                   *
**********************************************************************************************************/
void Fsrv_Api_KSWakeup(void)
{
	Fsrv_Api_KSWarmInit();
}

/**********************************************************************************************************
*Function   : Fsrv_Api_KSRRobinTask                                                                       *
*                                                                                                         *
*Description: system time task call , for judge fsrv warning                                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void Fsrv_Api_KSRRobinTask(void)
{
	uint32 VehicleOdo_u32; 
	uint32 MainValueDelta_u32; 

	/* get current odo value for compare with the next maintain servcie milestone */
	VehicleOdo_u32 = Odo_Api_Odometer_Get(e_OdoUints_1m)/1000;

	/* get nvm mile stone value*/
	Fsrv_NvmMilestone_u32 = *Odo_FsrvValueAddr_Get();

	/* if odo is more than mile stone value,set distance to 0*/
	if(VehicleOdo_u32 < Fsrv_NvmMilestone_u32)
	{
		/* if odo is less than mile stone value,calculate delta*/
		MainValueDelta_u32 = Fsrv_NvmMilestone_u32 - VehicleOdo_u32;
		Fsrv_MaintenceInfo_s.MaintenceValue_s32 = (sint32)MainValueDelta_u32;
	}
	else 
	{
		Fsrv_MaintenceInfo_s.MaintenceValue_s32 = (sint32)Fsrv_NvmMilestone_u32 - (sint32)VehicleOdo_u32;
		MainValueDelta_u32 = 0;
	}
	/*judge power status*/
	if((FALSE != Odo_InputPowerIGN()) && (FALSE != Odo_InputPowerAbnrmal()))
	{
		/*delta value is less than level2 warning*/
		if(MainValueDelta_u32 <= FSRV_WARNING_SERVICE_SHOLD)
		{
			Fsrv_MaintenceInfo_s.Status_u8=MAINTANCE_SERVICE_PLEASE;
		}
		/*delta value is less than level1 warning*/
		//else if(MainValueDelta_u32 <= FSRV_WARNING_STAND_SHOLD)
		//{
		//	Fsrv_MaintenceInfo_s.Status_u8=MAINTANCE_SERVICE_PLEASE;
		//}
		else 
		{
			/*set no warning*/
			Fsrv_MaintenceInfo_s.Status_u8=MAINTANCE_SERVICE_NROMAL;
		}
	}
	else
	{
		/*power invalid set no warning*/
		Fsrv_MaintenceInfo_s.Status_u8=MAINTANCE_SERVICE_NROMAL;
	}
}


/**********************************************************************************************************
*Function   : boolean Fsrv_Api_NewMilestone_Set(uint16 NewValue_u16)                                      *
*                                                                                                         *
*Description: call by other function if need to set new mile stone                                        *
*                                                                                                         *
*Parameter  : uint16  NewValue_u16 ,new mile stone value ,it need to be more than 0                       *
*                                                                                                         *
*Return     : TRUE:set value sucess,FALSE: set value fault                                                *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Fsrv_Api_NewMilestone_Set(sint32 NewValue_s32)
{
	uint32 VehicleOdo_u32;
	uint32 NewMilstone_u32;
	boolean result = FALSE;

	/* get odo value*/
	VehicleOdo_u32 = Odo_Api_Odometer_Get(e_OdoUints_1m)/1000u;
	/* calculate next mile stone value*/
	NewMilstone_u32 = (uint32)NewValue_s32 + VehicleOdo_u32;
	
	/* update to new milestone for service */
	if(NewValue_s32 <= 65535)
	{
		if(*Odo_FsrvValueAddr_Get() != NewMilstone_u32)
		{
			Odo_NvmBoWrite((uint8 *)Odo_FsrvValueAddr_Get(),(const uint8 *)(&NewMilstone_u32),(uint8)sizeof(NewMilstone_u32));
		}
		result = TRUE;
	}
	else 
	{

	}
	return result;
}

/**********************************************************************************************************
*Function   : boolean Fsrv_Api_DefaultMilestone_Set(uint16 NewValue_u16)                                  *
*                                                                                                         *
*Description: call by other function if need to set new default mile stone ,and reset mile stone          *
*                                                                                                         *
*Parameter  : uint16  NewValue_u16 ,new mile stone value ,it need to be more than 0                       *
*                                                                                                         *
*Return     : TRUE:set value sucess,FALSE: set value fault                                                *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean Fsrv_Api_DefaultMilestone_Set(uint16 NewValue_u16)
{
	if(*Odo_FsrvDefaultValueAddr_Get() != NewValue_u16)
	{
		Odo_NvmBoWrite((uint8 *)Odo_FsrvDefaultValueAddr_Get(),(const uint8 *)(&NewValue_u16),(uint8)sizeof(NewValue_u16));
	}
	else 
	{
		
	}
	(void)Fsrv_Api_NewMilestone_Set(Fsrv_MaintenceInfo_s.MaintenceValue_s32);
	return TRUE;
}

/**********************************************************************************************************
*Function   : Fsrv_Api_MaintenanceInfo_Get                                                                *
*                                                                                                         *
*Description: Frsv inoformation get                                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : Fsrv_MaintenceInfo_s.Status_u8,warning status.MaintenceValue_s32: mile stone value          *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
s_FsrvMaintenceInfo_t Fsrv_Api_MaintenanceInfo_Get(void)
{
	return Fsrv_MaintenceInfo_s;
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
**  Date    :      2020/07/07     Original Version
**
**********************************************************************************************************/

/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/


