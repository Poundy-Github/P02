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
**  Name:               SWC_Fuel_Pkg_Math.c
**
**  Description:        Implentation module for linear interpolation software.
**                     See comments below for more details.
**
** Organization:       
**
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef FFUEL_H
#define FFUEL_H

#ifndef FFUEL_C
#define EXTERN  extern
#else
#define EXTERN
#endif

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Fuel_Multiple_Process_Cfg.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	              Type Definition																		  *
*																								          *
*																								          *
**********************************************************************************************************/

#define FUEL_MULTIPLE_FLAG_FASTFILL_NONE                      (0u)
#define FUEL_MULTIPLE_FLAG_FASTFILL_ON                        (1u)// ign on fastfill, clean when speed > 1
#define FUEL_MULTIPLE_FLAG_FASTFILL_OFF                       (2u)// ign off fastfill or fastloss, clean when speed > 1
#define FUEL_MULTIPLE_FLAG_FASTFILL_ERR                       (3u)// ign off fastfill or fastloss, clean when speed > 1
#define FUEL_MULTIPLE_FLAG_FORCEINIT_ON                       (4u)// 

/*@2021/01/29:Discuss the key points with the system or take the original alarm point, 
  E point dead oil area special treatment */
#define FUEL_MULTIPLE_LFW_Trigger   (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(19)) /*Added this macro to make fuel alarm handling more intuitive :10L*/
#define FUEL_MULTIPLE_LFW_Release   (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(20)) /*Added this macro to make fuel alarm handling more intuitive :13L*/

#pragma ghs section bss=".buram" 
extern uint16 Fuel_Muti_Display_Table_CFG[FUEL_MUTI_DISPALY_BAR_TBL_SIZE_COMMON_MAX][2];
#pragma ghs section bss=default

#define SWC_FUEL_START_SEC_CONST_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"

extern const uint16 Fuel_Multiple_Display_Table_U16[FUEL_MULTIPLE_DISPALY_BAR_TBL_SIZE][2];
//extern const uint16 Fuel_Multiple_Api_Resisitor_Table[FUEL_MULTIPLE_AD_RESISTOR_TBL_SIZE][2];

#define SWC_FUEL_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"


/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_FUEL_START_SEC_CODE
#include "SWC_Fuel_MemMap.h"

/**********************************************************************************************************
*Function   : Fuel_Multiple_Api_ColdInit                                                             	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
extern void Fuel_Multiple_Api_ColdInit(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Api_WarmInit                                                             	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
extern void Fuel_Multiple_Api_WarmInit(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Api_Wakeup                                                               	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

extern void Fuel_Multiple_Api_Wakeup(void);

/**********************************************************************************************************
*Function   : Fuel_Multiple_Api_Main_Task                                                             	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

extern void Fuel_Multiple_Api_Main_Task(void);

/**********************************************************************************************************
*Function   : Fuel_Multiple_Api_Sleep_Check                                                            	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

extern boolean Fuel_Multiple_Api_Sleep_Check(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Api_Trans_Out_Normal                                                    	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

extern void Fuel_Multiple_Api_Trans_Out_Normal(void);
/**********************************************************************************************************
*Function   : Fuel_Api_Trans_Into_Abnormal                                                          	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

extern void Fuel_Multiple_Api_Trans_Into_Abnormal(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Api_Trans_Into_Normal                                                   	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

extern void Fuel_Multiple_Api_Trans_Into_Normal(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Zero_Speed_Check                                                          	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
extern boolean Fuel_Multiple_Zero_Speed_Check(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Zss_Speed_Check                                                       	      *
*                                                                                                         *
*Description: Obtain the reference value of oil to judge the speed                                        *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Shu junhua                                                                                  *
*                                                                                                         *
*Date		: 2021-01-29  add description                                                                 *
**********************************************************************************************************/
boolean Fuel_Multiple_Zss_Speed_Check(void);

/**********************************************************************************************************
*Function   : Fuel_Multiple_Bar_Process                                                              	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
void Fuel_Multiple_Bar_Process(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Raise_Process                                                             	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

void Fuel_Multiple_Raise_Process(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Get_Current_Fuel_Value                                                   	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

uint8 Fuel_Multiple_Get_Current_Fuel_Value(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Get_Target_Fuel_Value                                                      	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

uint8 Fuel_Multiple_Get_Target_Fuel_Value(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Init_Sweep                                                              	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

void Fuel_Multiple_Init_Sweep(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Disp_Bar_Process                                                           	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

void Fuel_Multiple_Disp_Bar_Process(uint8 Fuel_Bar_Value);

/**********************************************************************************************************
*Function   : Fuel_Multiple_Debug                                                                    	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

void Fuel_Multiple_Debug(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Refresh_Target_Bar                                                         	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

void Fuel_Multiple_Refresh_Target_Bar(void);

/**********************************************************************************************************
*Function   : Fuel_Multiple_Api_Get_Rest_Fuel_Volume                                                 	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

extern uint16 Fuel_Multiple_Api_Get_Rest_Fuel_Volume(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Api_Get_Warning_Fuel                                                    	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

extern boolean Fuel_Multiple_Api_Get_Warning_Fuel(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Sensor_Error_Status                                                       	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

extern boolean Fuel_Multiple_Sensor_Error_Status(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_boProveOut_Check                                                          	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

extern boolean Fuel_Multiple_boProveOut_Check(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Api_Get_Fuel_Level                                                         	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

extern uint16 Fuel_Multiple_Api_Get_Fuel_Level(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Damping_Fuel                                                               	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

extern void Fuel_Multiple_Damping_Fuel(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Api_Get_Fuel_Percent                                                       	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

extern uint16 Fuel_Multiple_Api_Get_Fuel_Percent(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Api_Get_Fast_Fill_Status                                                      *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	:                           														          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 Fuel_Multiple_Api_Get_Fast_Fill_Status(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Api_Get_Fuel_Low_Status                                                       *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	:                           														          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 Fuel_Multiple_Api_Get_Fuel_Low_Status(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Api_Get_Fuel_Volume                                                           *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	:                           														          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-03                                                                                  *
**********************************************************************************************************/
uint16 Fuel_Multiple_Api_Get_Fuel_Volume(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Sensor_Error_Set_Dtc_Status                                                   *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	:                           														          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-03                                                                                  *
**********************************************************************************************************/
void Fuel_Multiple_Sensor_Error_Set_Dtc_Status(void);
/**********************************************************************************************************
*Function   : Fuel_Multiple_Get_Fast_Fill_Loss_Status                                                     *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	:                           														          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-03                                                                                  *
**********************************************************************************************************/
uint8 Fuel_Multiple_Get_Fast_Fill_Loss_Status(void);
/** 
 * [Fuel_Multiple_Api_Sensor_OpenShort_Get : description]
 * @Author   shujunhua
 * @DateTime 2021/10/10-13:49:50
 * @param    index                    [description]
 * @return   uint8                    [description]
 */
uint8 Fuel_Multiple_Api_Sensor_OpenShort_Get(uint8 index);

#define SWC_FUEL_STOP_SEC_CODE
#include "SWC_Fuel_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
**
**  Revision:      1.0  
**
**  2020/06/02     Original Version
**
**********************************************************************************************************/

/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/

#undef EXTERN
#endif
