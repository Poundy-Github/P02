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
#ifndef SWC_ODO_INTERFACE_H
#define SWC_ODO_INTERFACE_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "Rte_Type.h"
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* Type of parament                                                                                        *
**********************************************************************************************************/
typedef enum
{
	e_OdoTrip1_enum0 = 0,
	e_OdoTrip2_enum1,
	e_OdoTrip2_enum2,
	e_OdoTripMax_enum3,
}e_OdoTripNumber_t;
	
typedef enum
{
	e_OdoUints_1m = 1,
	e_OdoUints_mile,
}e_OdoUints_t;


typedef enum
{
	e_RteOdoSet_ResetOdo = 1,
	e_RteOdoSet_ChangeOdo,
	e_RteOdoSet_ResetTrip,
	e_RteOdoSet_ResetTripAll,
	e_RteOdoSet_NewFsrv,
	e_RteOdoSet_DefFsrv,
	e_RteOdoSet_NewDefFsrv,
	e_RteOdoSet_SetNewOdoReset,
	e_RteOdoSet_ClearBackUpFlag,
	e_RteOdoSet_ChangeTripBaseOnOdo,
	e_RteOdoSet_ConstWriteOdo,
	e_RteOdoSet_All,
}e_OdoRteSetParament_t;

typedef struct
{
	uint8 ClearFlag_u8;
	uint32 ClearData;
}e_OdoLocalSetParament_t;


/**********************************************************************************************************
* define of parament                                                                                      *
**********************************************************************************************************/
/*This macro defines value for ODO RAM Fault 1 Infidcator*/
#define ODO_RAM_FLTER1_VALID 												(0x55AA55AAUL)

/*This macro defines value for ODO RAM Fault 2 Infidcator*/
#define ODO_RAM_FLTER2_VALID 												(0xAA55AA55UL)

/*ODO NVM error value*/
#define ODO_NVM_ERROR_VALUE 												(0xFFFFFF01UL)

/*TRIP ODO NVM error value*/
#define ODO_TRIP_ERROR_VALUE 												(0xFFFFFF00UL)

/*For MISRA C-2012 Rules */
#define ODO_TRUE                                                            (1U)
#define ODO_FALSE 															(0U)
#define ODO_ECM20_0X3B7_NEVER_RECEIVED										(6U)
/**********************************************************************************************************
* start of Function                                                                                       *
**********************************************************************************************************/
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_ODO_START_SEC_CODE
#include "SWC_Odo_MemMap.h" 

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
void Odo_Api_ColdInit(void);

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
void Odo_Api_WarmInit(void);

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
void Odo_Api_Wakeup(void);

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
void Odo_Api_TransIntoNormal(void);

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
void Odo_Api_OutOfNormal(void);

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
void Odo_Api_TimeTask(void);

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
void Odo_Api_IrqTimeTask(void);

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
uint8 Odo_Api_RunCounter_Get(void);

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
uint32 Odo_Api_Odometer_Get(e_OdoUints_t Units_u8);

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
uint8 Odo_Api_ResetOdo_Set(void);
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
void Odo_Api_ResetOdoTask(void);

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
boolean Odo_Api_ChangeOdo_Set(uint32 NewOdo_u32,uint8 trip_reset);

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
uint32 Odo_Api_TripValue_Get(uint8 TripId_u8,e_OdoUints_t Uints_u8);

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
void Odo_Api_ResetTrip_Set(uint8 TripId_u8);

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
void Odo_Api_ResetTripAll_Set(void);

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
boolean Odo_Api_RamCheck_Get(void);

/**********************************************************************************************************
*Function   : Odo_Api_PkgRrobinTask                                                                       *
*                                                                                                         *
*Description: ODO Package function,need to call by task,No time limit                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
//void Odo_Api_PkgRrobinTask(void);

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
void Odo_VINBackUpCheck(void);

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
uint8 Odo_Api_VINBackUpError_Get(void);

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
void Odo_PkgBackupODO(void);
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
void Odo_PkgOdoClearValueSet(uint16 Newdata);

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
void Odo_PkgOdoClearVinBackupFlag(uint8 num);

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
void Odo_Api_RteRrobinTask(void);

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
void Odo_Api_ParamentGetFunction(s_OdoRteGetParament_t *data);

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
uint8 Odo_Api_ParamentSetFunction(uint8 SetId,uint32 *data);

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
void Odo_Api_RteNvmWrite_Set(uint8 BlkId,boolean control);
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
void Odo_Api_ParamentSetLocalTask(void);

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
uint32 Odo_Api_RteNvmWrite_Get(void);

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
void ODO_callback(sint64 pre_time,sint64 now_time);

/**********************************************************************************************************
**
**  Revision:      1.0  
**  
**  Author  :      Cao wenping
**
**  Date    :      2020/06/02     Original Version
**
**********************************************************************************************************/
#define SWC_ODO_STOP_SEC_CODE
#include "SWC_Odo_MemMap.h" 
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/
 
#endif




