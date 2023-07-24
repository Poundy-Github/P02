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
**  Description:        The intent of this code is to provide a configurable fuel filter
** 						algorithm for use in a variety of instrument cluster applications.
** 						Requirements for this code package are detailed in the
** 						Fuel Algorithm Bookshelf Design Specification 
**
**  Organization:       
**
**********************************************************************************************************/

#ifndef FUEL_SINGLE_PROCESS_H
#define FUEL_SINGLE_PROCESS_H
/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/

#include "SWC_Fuel_Single_Process_Cfg.h"


/**********************************************************************************************************
*																								          *
*																								          *
*	              Type Definition																		  *
*																								          *
*																								          *
**********************************************************************************************************/

#define FUEL_SINGLE_FLAG_FASTFILL_NONE                      (0u)
#define FUEL_SINGLE_FLAG_FASTFILL_ON                        (1u)// ign on fastfill, clean when speed > 3
#define FUEL_SINGLE_FLAG_FASTFILL_OFF                       (2u)// ign off fastfill or fastloss, clean when speed > 3
#define FUEL_SINGLE_FLAG_FORCEINIT_ON                       (3u)// cold init and fuel is open or short 

#define FUEL_SINGLE_LFW_Trigger   Fuel_Api_Config_Data_NVM_Pkg_Get_Data(19) /*Added this macro to make fuel alarm handling more intuitive :10L*/
#define FUEL_SINGLE_LFW_Release   Fuel_Api_Config_Data_NVM_Pkg_Get_Data(20) /*Added this macro to make fuel alarm handling more intuitive :13L*/



#pragma ghs section bss = ".buram" /*@20200929 define data to specified BURAM area*/ 
    extern uint16 Fuel_Single_Display_Table_CFG[FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX][2];
#pragma ghs section bss = default


/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_FUEL_START_SEC_CODE
#include "SWC_Fuel_MemMap.h"

/**********************************************************************************************************
*Function   : Fuel_Single_Api_KSColdinit                                                                  *
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

void Fuel_Single_Api_KSColdinit(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Api_KSWarminit                                                                  *
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

void Fuel_Single_Api_KSWarminit(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Api_KSWakeUp                                                                    *
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

void Fuel_Single_Api_KSWakeUp(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Api_Trans_Into_Normal                                                           *
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

void Fuel_Single_Api_Trans_Into_Normal(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Api_Abnormal_Trans_Into_Normal                                                  *
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

void Fuel_Single_Api_Abnormal_Trans_Into_Normal(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Api_Abnormal_Trans_Into_Normal                                                  *
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
#if 0
void Fuel_Single_Api_Trans_Outof_Normal(void);
#endif 


/**********************************************************************************************************
*Function   : Fuel_Single_Api_Chaeck_Sleep                                                                *
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

boolean Fuel_Single_Api_Chaeck_Sleep(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Api_Main_Task                                                                   *
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

void Fuel_Single_Api_Main_Task(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Api_Fastfill_Condition_Met                                                      *
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

boolean Fuel_Single_Api_Fastfill_Condition_Met(void);


/**********************************************************************************************************
*Function   : Fuel_Single_Api_Valid_Condition                                                             *
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

uint8 Fuel_Single_Api_Valid_Condition(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Api_KSDiag_Prolog                                                               *
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

void Fuel_Single_Api_KSDiag_Prolog(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Api_Fuel_Uint_Test                                                              *
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

uint16 Fuel_Single_Api_Fuel_Uint_Test(uint8 *data);

/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Fast_Fill_Speed_Check                                                   *
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

boolean Fuel_Single_Api_Get_Fast_Fill_Speed_Check(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Zss_Speed_Check                                                       	      *
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

boolean Fuel_Single_Zss_Speed_Check(void);


/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Fuel_Level                                                              *
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

uint16 Fuel_Single_Api_Get_Fuel_Level(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Rest_Fuel                                                               *
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

uint16 Fuel_Single_Api_Get_Rest_Fuel(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Fuel_Warning                                                            *
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

extern uint8 Fuel_Single_Api_Get_Fuel_Warning(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Fuel_Low_Status                                                         *
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
extern boolean Fuel_Single_Api_Get_Fuel_Low_Status(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Short_Or_Open                                                           *
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

boolean Fuel_Single_Api_Get_Short_Or_Open(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Short_and_Open                                                           *
*                                                                                                         *
*Description: 0:nomal; 1:short ; 2:open  	                                                                                      *
*                                                                                                         *
*Parameter	:                           														          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: shujunhua                                                                                    *
*                                                                                                         *
*Date		: 2020-09-26                                                                                  *
**********************************************************************************************************/
uint8 Fuel_Single_Api_Get_Short_and_Open(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Refresh_Target_Bar                                                      *
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

void Fuel_Single_Api_Get_Refresh_Target_Bar(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Fast_Fill_Status                                                        *
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

uint8 Fuel_Single_Api_Get_Fast_Fill_Status(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Max_Fuel_Level                                                          *
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

uint16 Fuel_Single_Api_Get_Max_Fuel_Level(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Zss                                                                     *
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
uint16 Fuel_Single_Api_Get_Zss(void);


boolean Fuel_Single_Api_Get_Sender_Short(void);		
/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Sender_Short                                                            *
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

boolean Fuel_Single_Api_Get_Sender_Open(void);		
/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Sender_Overrange                                                        *
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

boolean Fuel_Single_Api_Get_Sender_Overrange(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Fuel_Volume                                                             *
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

uint32 Fuel_Single_Api_Get_Fuel_Volume(void);	
/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Fuel_Resisitor                                                             *
*                                                                                                         *
*Description:                                                                                  *
*                                                                                                         *
*Parameter	:                           														          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: shujunhua                                                                            *
*                                                                                                         *
*Date		: 2020-09-24                                                                                  *
**********************************************************************************************************/

uint16 Fuel_Single_Api_Get_Fuel_Resisitor(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Fuel_Input                                                              *
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

uint16 Fuel_Single_Api_Get_Fuel_Input(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Fuel_Volume_Output                                                      *
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

uint32 Fuel_Single_Api_Get_Fuel_Volume_Output(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Api_Fuel_Debug                                                                  *
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

void Fuel_Single_Api_Fuel_Debug(void);

	
/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Park_Counts                                                             *
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

uint16 Fuel_Single_Api_Get_Park_Counts(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Max_Counts                                                              *
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

uint16 Fuel_Single_Api_Get_Max_Counts(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Abs_Pos                                                                 *
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

void Fuel_Single_Api_Get_Abs_Pos(uint16 pos);

/**********************************************************************************************************
*Function   : Fuel_Single_Api_Set_Uints_Pos                                                               *
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

void Fuel_Single_Api_Set_Uints_Pos(uint16 pos);

/**********************************************************************************************************
*Function   : Fuel_Single_Api_Fuel_Sync_Reday                                                             *
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

boolean Fuel_Single_Api_Fuel_Sync_Reday(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Api_Get_Fuel_hmi_percent                                                        *
*                                                                                                         *
*Description: The percentage calculated from the fuel pack is reprocessed as shown                        *
*                                                                                                         *
*Parameter	:                           														          *
*                                                                                                         *
*Return 	: uint16   10 x magnification                                                                 *
*                                                                                                         *
*Author 	: shujunhua                                                                                   *
*                                                                                                         *
*Date		: 2020-09-28                                                                                  *
**********************************************************************************************************/
uint16 Fuel_Single_Api_Get_Fuel_hmi_percent(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Sensor_Error_Set_Dtc_Status                                                     *
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
void Fuel_Single_Sensor_Error_Set_Dtc_Status(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Get_Fast_Fill_Loss_Status                                                       *
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
uint8 Fuel_Single_Get_Fast_Fill_Loss_Status(void);
/**********************************************************************************************************
*Function   : Fuel_single_Api_Get_Fuel_Volume_VR                                                          *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	:                           														          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-16                                                                                  *
**********************************************************************************************************/
uint32 Fuel_single_Api_Get_Fuel_Volume_VR(void);


boolean Fuel_Single_Api_Get_Error_Status(void);


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


#endif
