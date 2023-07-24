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
#ifndef FUEL_PKG_SINGLE_H
#define FUEL_PKG_SINGLE_H

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/

#define SWC_FUEL_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"

extern uint16 Fuel_Single_Sender_A_Table_Nvm_Cfg[50][2];

#define SWC_FUEL_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
typedef enum
{
	e_fuel_damping_None      = 0,
	e_fuel_Damp_lowfuel      = 1,					
	e_fuel_Damp_run_fuelup   = 2,		
	e_fuel_Damp_run_fueldown = 3, 
	e_fuel_Damp_idle         = 4,
    e_fuel_Damp_fast         
}e_fuel_Damp_t;

/**********************************************************************************************************
*																								          *
*																								          *
*	              Type Definition																		  *
*																								          *
*																								          *
**********************************************************************************************************/
#define FUEL03_PERCENT_FULL_INVALID_BYTE                        (0xFFFF)
#define FUEL_SINGLE_PERCENT_FULL_INVALID_WORD                   (0xFF00u)
#define FUEL03_PERCENT_WARNING                                  (1u)
#define FUEL03_WARNING_DISAPPEAR                                (2u)

#define FUEL_SINGLE_HILL_HOLD_ENABLE_BIT                        (0x80)
#define FUEL_SINGLE_FAST_FILL_ENABLE_BIT                        (0x40)
#define FUEL_SINGLE_ZSS_REF_ONLY_BIT                            (0x20)

#define FUELE_SINGLE_VERSION      (12u) // 1.2

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_FUEL_START_SEC_CODE
#include "SWC_Fuel_MemMap.h"

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_KSColdInit                                                                  *
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
void Fuel_Single_Pkg_KSColdInit(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_KSWarmInit                                                                  *
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

void Fuel_Single_Pkg_KSWarmInit(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_KSWakeup                                                                    *
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

void Fuel_Single_Pkg_KSWakeup(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Setup_For_Init                                                              *
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

void Fuel_Single_Pkg_Setup_For_Init(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Periodic_Process                                                            *
*                                                                                                         *
*Description:  This function handles fuel inits and normal/fast mode filtering of the fuel sender(s).     *
*                                                                                                         *
*Parameter	:                           														          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

void Fuel_Single_Pkg_Periodic_Process(uint16 Fuel_Single_rada, boolean fuel_single_jam_filter);

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Fastfill_Flag_Clear                                                         *
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


void Fuel_Single_Pkg_Fastfill_Flag_Clear(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Ignoff_Process                                                              *
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

void Fuel_Single_Pkg_Ignoff_Process(uint16 Fuel_Single_rada);
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Ignoff_Process_Done                                                         *
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

boolean Fuel_Single_Pkg_Ignoff_Process_Done( void );

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Clear_Dtcs_Resets                                                           *
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

void Fuel_Single_Pkg_Clear_Dtcs_Resets(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Get_Fuel_Level                                                              *
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

uint16 Fuel_Single_Pkg_Get_Fuel_Level(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Get_Fuel_Level_Hys                                                          *
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

uint16 Fuel_Single_Pkg_Get_Fuel_Level_Hys(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Get_Zss                                                                     *
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

uint16 Fuel_Single_Pkg_Get_Zss(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Get_SenderA_PFH                                                             *
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

uint16 Fuel_Single_Pkg_Get_SenderA_PFH(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Set_SenderA_PFH                                                             *
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

void Fuel_Single_Pkg_Set_SenderA_PFH(uint32 temp);
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Set_SenderA_PF                                                              *
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

void Fuel_Single_Pkg_Set_SenderA_PF(uint32 temp);

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Get_SenderA_PF                                                              *
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
uint16 Fuel_Single_Pkg_Get_SenderA_PF(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Get_SenderA_Unfilter_Flps                                                   *
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

uint16 Fuel_Single_Pkg_Get_SenderA_Unfilter_Flps( void );
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Get_SenderA_Lowspeed_Counter                                                *
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
uint16 Fuel_Single_Pkg_Get_SenderA_Lowspeed_Counter( void );
#endif 
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Rad_To_Flps                                                                 *
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

uint16 Fuel_Single_Pkg_Rad_To_Flps( uint16 fuel_single_rad);

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Init_Finished                                                               *
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

boolean Fuel_Single_Pkg_Init_Finished(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Fastfill_Active                                                             *
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
boolean Fuel_Single_Pkg_Fastfill_Active(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_ForceInit_Active                                                             *
*                                                                                                         *
*Description: fuel cold init when open or short                                                           *
*                                                                                                         *
*Parameter	:                           														          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Shujunhua                                                                                   *
*                                                                                                         *
*Date		: 2021-02-23                                                                                  *
**********************************************************************************************************/
boolean Fuel_Single_Pkg_ForceInit_Active(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_SenderA_Fastfill_Active                                                     *
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

boolean Fuel_Single_Pkg_SenderA_Fastfill_Active(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Fill_Detected_Func                                                          *
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

boolean Fuel_Single_Pkg_Fill_Detected_Func(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_SenderA_Fill_Detected                                                       *
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

boolean Fuel_Single_Pkg_SenderA_Fill_Detected(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Loss_Detected_Func                                                          *
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

boolean Fuel_Single_Pkg_Loss_Detected_Func(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_SenderA_Loss_Detected                                                       *
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

boolean Fuel_Single_Pkg_SenderA_Loss_Detected(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Fill_Loss_Detected                                                          *
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

boolean Fuel_Single_Pkg_Fill_Loss_Detected(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Open_Short_Detected                                                         *
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

boolean Fuel_Single_Pkg_Open_Short_Detected(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_SenderA_Open_Short_Detected                                                 *
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

boolean Fuel_Single_Pkg_SenderA_Open_Short_Detected(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_SenderA_Open_Detected                                                       *
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

boolean Fuel_Single_Pkg_SenderA_Open_Detected(void);
boolean Fuel_Single_Pkg_SenderA_Open_Detected_Dtc(void);


/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_SenderA_Short_Detected                                                      *
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

boolean Fuel_Single_Pkg_SenderA_Short_Detected(void);
boolean Fuel_Single_Pkg_SenderA_Short_Detected_Dtc(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Network_Message_Missing                                                     *
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

void Fuel_Single_Pkg_Network_Message_Missing(void);

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Diag_SlefTest                                                               *
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
void Fuel_Single_Pkg_Diag_SlefTest(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Diag_Epilog                                                                 *
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

void Fuel_Single_Pkg_Diag_Epilog(void);
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_Get_Can_Flps                                                                *
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

uint16 Fuel_Single_Pkg_Get_Can_Flps( uint16 radin );

/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_SenderA_Ignon_Avgflps                                                       *
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

uint16 Fuel_Single_Pkg_SenderA_Ignon_Avgflps( void );
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_SenderA_Ignoff_Ref                                                          *
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

uint16 Fuel_Single_Pkg_SenderA_Ignoff_Ref( void );
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_SenderA_Zss_Ref                                                             *
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

uint16 Fuel_Single_Pkg_SenderA_Zss_Ref( void );
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_SenderA_Ignon_Good_Sample                                                   *
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

uint8 Fuel_Single_Pkg_SenderA_Ignon_Good_Sample( void );
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_SenderA_ConvSample                                                          *
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

uint8 Fuel_Single_Pkg_SenderA_ConvSample( void );
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_SenderA_Ref_Fuel                                                            *
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

uint16 Fuel_Single_Pkg_SenderA_Ref_Fuel( void );
/**********************************************************************************************************
*Function   : Fuel_Single_Pkg_SenderA_Ref_Flps                                                            *
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

uint16 Fuel_Single_Pkg_SenderA_Ref_Flps( void );
e_fuel_Damp_t Fuel_Single_Pkg_damp_mode_get(void);
uint32 Fuel_Single_Pkg_damp_value_get(void);
uint8 Fuel_Single_Pkg_filter_flags_get(void);
uint8 Fuel_Single_Pkg_filter_moreflags_get(void);
/**********************************************************************************************************
*Function	: Fuel_Single_Pkg_Get_UpOrDown_falg				     										  *
*																										  *
*Description: TBD																						  *
*																										  *
*Parameter	: (uint16 *table, uint16 lookupVal) 														  *
*																										  *
*Return 	: void																						  *
*																										  *
*Author 	: Chao Feng 																				  *
*																										  *
*Date		: 2020-06-12																				  *
**********************************************************************************************************/
uint8 Fuel_Single_Pkg_Get_UpOrDown_falg(void);
uint8 Fuel_Single_Pkg_SenderA_Status_Dtc(void);
boolean Fuel_Single_Pkg_SenderA_Open_Short_Detected_Dtc(void);
boolean Fuel_Single_Pkg_SenderA_Open_Sample_Dtc(void);
boolean Fuel_Single_Pkg_SenderA_Short_Sample_Dtc(void);
/** 
 * [Fuel_Single_Error_Status_Check : for TC Module CS interface when kl15 on ]
 * @Author   shujunhua
 * @DateTime 2021/5/17-19:28:21
 * @param    void                     [description]
 * @return   boolean                  [description]
 */
boolean Fuel_Single_Error_Status_Check(void);
/*************************************************************************  
 * [Fuel_Single_Get_ABOVE : description]
 * @Author   GW00227774
 * @DateTime 2021/9/19-16:48:51
 * @param    void                         
 *[description]  :if the sample  is above the slosh filter value and return TRUE else return FALSE 
 *************************************************************************/
boolean Fuel_Single_Get_Above_Status(void);
/*************************************************************************  
 * [Fuel_Single_Get_Below_Status : description]
 * @Author   GW00227774
 * @DateTime 2021/9/19-16:55:17
 * @param    void                     
 *[description] :if the sample  is below the slosh filter value.return TRUE else return FALSE 
 *************************************************************************/
boolean Fuel_Single_Get_Below_Status(void);
uint8 Fuel_Single_Pkg_Get_Log_Init_Err_Flag(void);
void Fuel_Single_Pkg_Set_Log_Init_Err_Flag(uint8 value);
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

