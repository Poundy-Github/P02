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
/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef FUEL02FLT_H
#define FUEL02FLT_H

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"


/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
*																								          *
*																								          *
*	              Type Definition																		  *
*																								          *
*																								          *
**********************************************************************************************************/
typedef enum
{
	FUEL_MULTIPLE_DAMP_NONE      = 0,
	FUEL_MULTIPLE_DAMP_FUELLOW   = 1,					
	FUEL_MULTIPLE_DAMP_FUELUP    = 2,		
	FUEL_MULTIPLE_DAMP_FUELDOWN  = 3, 
	FUEL_MULTIPLE_DAMP_IDLE      = 4,
    FUEL_MULTIPLE_DAMP_FASTFILL  = 5       
}FUEL_MULTIPLE_DAMP_TYPE;

typedef struct 
{
	uint8  	fuel_a_err;
	uint8  	fuel_b_err;
}FUEL_ERR_STATUS;

#define FUEL_MULTIPLE_PERCENT_FULL_INVALID_BYTE  	(0xFFFF)
#define FUEL_MULTIPLE_PERCENT_FULL_INVALID_WORD  	(0xFF00u)

#define FUEL_MULTIPLE_PERCENT_WARNING 				(1u)
#define FUEL_MULTIPLE_PERCENT_WARNING_DISAPPEAR 	(2u)

#define FUEL_MULTIPLE_TANK_A  						(0u)
#define FUEL_MULTIPLE_TANK_B  						(1u)
#define FUEL_MULTIPLE_ERR_DISP_EN                   (1)

#define FUELE_MULTIPLE_VERSION      (11u) // 1.1

/**********************************************************************************************************
** Bits used with FUEL_MULTIPLE_OPTIONS_NVM.
**********************************************************************************************************/

#define FUEL_MULTIPLE_HILL_HOLD_ENABLE_BIT   		(0x80)
#define FUEL_MULTIPLE_FAST_FILL_ENABLE_BIT   		(0x40)
#define FUEL_MULTIPLE_ZSS_REF_ONLY_BIT       		(0x20)
#define FUEL_MULTIPLE_SENDER_B_ENABLE_BIT    		(0x02)
#define FUEL_MULTIPLE_SADDLE_TANK_SYSTEM_BIT 		(0x01)

#pragma ghs section bss=".buram"  
extern uint16 Fuel_Multiple_Sender_A_Table_Nvm_Cfg[50][2];
extern uint16 Fuel_Multiple_Sender_B_Table_Nvm_Cfg[50][2];
#pragma ghs section bss=default


/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_FUEL_START_SEC_CODE
#include "SWC_Fuel_MemMap.h"

/**********************************************************************************************************
*Function   : Fuel_Multiple_Pkg_Coldinit                                                                  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
void Fuel_Multiple_Pkg_KSColdinit(void);
/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

void Fuel_Multiple_Pkg_Warminit(void);
/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

void Fuel_Multiple_Pkg_Wakeup(void);


/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: 	** The following should be called by the product specific fuel routines
				** in FFUEL.C when it is necessary to start a fuel init, i.e. on
				** a transition to RUN or after a high/low battery condition.
				**
				** If desired, the application can call this function whenever the
				** ignition is OFF or ACC, so that when the ignition transitions into
				** RUN the filter code is already primed to perform fuel init.
				**
				** It does not matter how many times this function is called as it
				** is just initializing RAM to begin a fuel init.	                 
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

void Fuel_Multiple_Setup_For_Init(void);

/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: 	** The following should be called by the product specific fuel routines
				** in FFUEL.C on a periodic basis.  Do not call this function unless
				** the filter should be iterated. For example, do not call in ignition
				** OFF or in overvoltage conditions.
				**
				** The period at which this function is called depends on the type of
				** fuel sender input -- network or hardwired.  In the network case,
				** the function should be iterated whenever a new data message is received.
				** In the hardwired case, the function should be iterated at a fixed rate,
				** for example 100ms.
				**
				** The program subsystem engineer should provide requirements for when
				** the filter should be iterated and at what rate.  The rate chosen will
				** affect the values of many of the constants in the .CFG file.
				**
				** The first parameter (rada) in the call is for the SENDER A ratio'd A/D value, and
				** the second (radb) is for SENDER B.  In single sender systems, the SENDER B value is
				** ignored so the application can put any value in there it desires.
				**
				** The third parameter should be TRUE when the cluster is in manufacturing
				** test mode and wants the filter(s) to be jammed with the current A/D
				** value.  This value should be set to FALSE otherwise.	                 
				*                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

void Fuel_Multiple_Periodic_Process(uint16 fuel_multiple_rada, uint16 fuel_multiple_radb, boolean fuel02_jam_filter);


/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: 	** The following should be called by the product specific fuel routines
				** in FFUEL.C on a periodic basis when the ignition switch is off AND
				** key-off fuel A/D sampling is required.  Do not call this function unless
				** samples should be taken. For example, do not call in overvoltage
				** conditions.
				**
				** The period at which this function is called depends on the type of
				** fuel sender input -- network or hardwired.  In the network case,
				** the function should be iterated whenever a new data message is received.
				** However, it is very likely that the network is not active when the
				** ignition switch is off, so this function will not be needed.
				** In the hardwired case, the function should be iterated at a fixed rate,
				** for example 100ms.
				**
				** The program subsystem engineer should provide requirements for when
				** the filter should be iterated and at what rate.  The rate chosen will
				** affect the values of many of the constants in the .CFG file.
				**
				** The first parameter in the call is for the FDM ratio'd A/D value, and
				** the second is for the PFM.  In single sender systems, the PFM value is
				** ignored so the application can put any value in there it desires.
				**
				** The application must continue to call this function (i.e. not go to
				** sleep) in OFF until the keyoff processing is complete.                 
				*                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

void Fuel_Multiple_Ignoff_Process(uint16 fuel_multiple_rada, uint16 fuel_multiple_radb);

/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: 	** This function  will reset  the fault flages and fault timers of Sender A & B.
				** This should be called by product specific diagnostic routine.
				** This  will be excuted only when service $14 command is received by cluster during CAN 
				** dignostics.
				** It will reset fault flags and fault timers regardless fuel sender's fault DTC's 
				** logged or not.                
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

void Fuel_Multiple_Dtc_Resets(void);

/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

void Fuel_Multiple_Set_Fuel_Fault(uint16 fuel02_counter);


/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

boolean Fuel_Multiple_Ignoff_Done_Process( void );

/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: 	** The following should be called to get the percent full value of the
				** sender(s) with and without hysteresis.
				**
				** Typically, the hysteresis value is used to turn on/off the low fuel
				** warning light, and the non-hysteresis value is used for fuel gage
				** position determination and for data for network transmission of the
				** current fuel level.
				**
				** On single sender systems, the function returns the value for a single
				** sender.  On dual sender systems, the function returns the combined value
				** for both senders.
				**
				** These routines do not calculate anything as that is done by the periodic
				** processing routines.  They can be called anytime to get the latest value.
				**
				** The return values are in SCP percent full units, i.e. 0 represents 0%
				** full, and 254 represents 99.60% full.  A value of 255 is used to represent
				** invalid data.  The MSB of the data represents the whole part of the
				** percent full value, and the LSB represents remainder.
				**
				** On single sender systems, the return value is only valid if
				** "Fuel_Multiple_Open_Short_Detected()" is FALSE.  On dual sender systems, the
				** return value will be PERCENT_FULL_INVALID_WORD when a fault is
				** detected.              
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

uint16 Fuel_Multiple_Pkg_Get_Fuel_Level(void);
uint16 Fuel_Multiple_Pkg_Get_Fuel_Level_Hys(void);

/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: 	** The following should be called to get the individual SenderA and SenderB
				** percent full values with or without hysteresis.
				**
				** The description of the above functions apply to these as well.            
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

uint16 Fuel_Multiple_Get_SenderA_PFH(void);
uint16 Fuel_Multiple_Get_SenderA_PF(void);
uint16 Fuel_Multiple_Get_SenderB_PFH(void);
uint16 Fuel_Multiple_Get_SenderB_PF(void);

uint16 Fuel_Multiple_SenderA_Unfilter_Flps( void );
uint16 Fuel_Multiple_SenderB_Unfilter_Flps( void );

/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: 	** The following function returns TRUE when fuel init is finished, FALSE
				** otherwise.
				**
				** Once TRUE, it will remain TRUE until the "Fuel_Multiple_Setup_For_Init()"
				** function is called.           
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

boolean Fuel_Multiple_Init_Finished(void);

/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: 	** The following function returns TRUE if any sender is in fast fill, FALSE
				** otherwise.        
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

boolean Fuel_Multiple_Fastfill_Active(void);
boolean Fuel_Multiple_ForceInit_Active(void);

boolean Fuel_Multiple_SenderA_Fastfill_Active(void);
boolean Fuel_Multiple_SenderB_Fastfill_Active(void);

/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: 	** The following function returns TRUE if a fill is detected, FALSE otherwise.
				**
				** On dual sender systems, both senders are tested for a fill and TRUE is
				** returned if either is TRUE.
				**
				** Once TRUE, it will remain TRUE until the "Fuel_Multiple_Setup_For_Init()"
				** function is called.        
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

boolean Fuel_Multiple_Fill_Detected(void);
boolean Fuel_Multiple_SenderA_Fill_Detected(void);
boolean Fuel_Multiple_SenderB_Fill_Detected(void);


/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: 	** The followings function returns TRUE if a loss is detected, FALSE otherwise.
				**
				** On dual sender systems, both senders are tested for a loss and TRUE is
				** returned if either is TRUE.
				**
				** Once TRUE, it will remain TRUE until the "Fuel_Multiple_Setup_For_Init()"
				** function is called.         
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

boolean Fuel_Multiple_Loss_Detected(void);
boolean Fuel_Multiple_SenderA_Loss_Detected(void);
boolean Fuel_Multiple_SenderB_Loss_Detected(void);


/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: 	** The following function returns TRUE if a fill or loss is detected, FALSE otherwise.
				**
				** On dual sender systems, both senders are tested and TRUE is
				** returned if either is TRUE.
**
** Once TRUE, it will remain TRUE until the "Fuel_Multiple_Setup_For_Init()"
** function is called.        
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

boolean Fuel_Multiple_Loss_Fill_Detected(void);
void Fuel_Multiple_Clear_Fastfill_Flag( void );

/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: 	The saddle type tank must be returned to true in the case of both failures                *
*Parameter	:                               													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Shu junhua                                                                                  *
*                                                                                                         *
*Date		: 2021-04-25                                                                                  *
**********************************************************************************************************/
boolean Fuel_Multiple_Open_Short_Detected(void);
/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: 	For saddle tank, return to true in case of main sensor failure                            *
*Parameter	:                               													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Shu junhua                                                                                  *
*                                                                                                         *
*Date		: 2021-04-25                                                                                  *
**********************************************************************************************************/
boolean Fuel_Multiple_SenderA_Open_Short_Detected(void);
/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: 	For saddle tank, return to true in case of Aux sensor failure                             *
*Parameter	:                               													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Shu junhua                                                                                  *
*                                                                                                         *
*Date		: 2021-04-25                                                                                  *
**********************************************************************************************************/
boolean Fuel_Multiple_SenderB_Open_Short_Detected(void);
boolean Fuel_Multiple_SenderA_Open_Detected(void);
boolean Fuel_Multiple_SenderA_Open_Detected_Dtc(void);
boolean Fuel_Multiple_SenderB_Open_Detected(void);
boolean Fuel_Multiple_SenderB_Open_Detected_Dtc(void);
boolean Fuel_Multiple_SenderA_Short_Detected(void);
boolean Fuel_Multiple_SenderA_Short_Detected_Dtc(void);
boolean Fuel_Multiple_SenderB_Short_Detected(void);
boolean Fuel_Multiple_SenderB_Short_Detected_Dtc(void);
uint16 Fuel_Multiple_SenderA_Ignon_Avg_Flps( void );
uint16 Fuel_Multiple_SenderA_Ignoff_Ref( void );
uint16 Fuel_Multiple_SenderA_Zss_Ref( void );
uint16 Fuel_Multiple_Sender_Zss_Ref( void );
uint8 Fuel_Multiple_SenderA_Ignon_Good_Samples( void );
uint16 Fuel_Multiple_Pkg_SenderA_Rfuel( void );
uint16 Fuel_Multiple_Pkg_SenderA_Rflps( void );
uint16 Fuel_Multiple_SenderB_Ignon_Avg_Flps( void );
uint16 Fuel_Multiple_SenderB_Ignoff_Ref( void );
uint16 Fuel_Multiple_SenderB_Zss_Ref( void );
uint8 Fuel_Multiple_SenderB_Ignon_Good_Samples( void );
uint16 Fuel_Multiple_Pkg_SenderB_Rfuel( void );
uint16 Fuel_Multiple_Pkg_SenderB_Rflps( void );
boolean Fuel_Multiple_Open_Short_Detect_TT(void);
uint8 Fuel_Multiple_SenderA_Status_Dtc(void);
uint8 Fuel_Multiple_SenderB_Status_Dtc(void);


/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: 	** Call the following function if the fuel A/D input comes from a network and
				** the message containing the data is missing.  It is only necessary to call
				** this once when the message is first declared missing.
				**
				** It is the applications responsibility to log any DTCs for missing messages
				** that may be required.          
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

void Fuel_Multiple_Network_Message_Missing(void);

/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: 	** Various PID and diagnostic mode functions.  Some functions are
				** not present if the .CFG file configures them out.      
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

uint8 Fuel_Multiple_SenderA_KO_ConvSample( void );
uint8 Fuel_Multiple_SenderA_ZS_ConvSample( void );
uint8 Fuel_Multiple_SenderB_KO_ConvSample( void );
uint8 Fuel_Multiple_SenderB_ZS_ConvSample( void );

/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: 	** Use the following to get the CANFLPS value from the table contained
				** in the config file. Note that you must pass the fuel_single_rad value.        
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

uint16 Fuel_Multiple_Get_CANFLPS_A( uint16 radin );
uint16 Fuel_Multiple_Get_CANFLPS_B( uint16 radin );
/**********************************************************************************************************
*Function	: Fuel_Multiple_Pkg_Damp_Mode_Get   														  *
*																										  *
*Description: TBD																						  *
*																										  *
*Parameter	: TBD                   			 														  *
*																										  *
*Return 	: void																						  *
*																										  *
*Author 	: Chao Feng 																				  *
*																										  *
*Date		: 2020-06-12																				  *
**********************************************************************************************************/
FUEL_MULTIPLE_DAMP_TYPE Fuel_Multiple_Pkg_Damp_Mode_Get(uint8 fuel_index);
 /**********************************************************************************************************
 *Function	 : Fuel_Multiple_Pkg_Damp_Value_Get															   *
 *																										   *
 *Description: TBD																						   *
 *																										   *
 *Parameter  : TBD																						   *
 *																										   *
 *Return	 : void 																					   *
 *																										   *
 *Author	 : Chao Feng																				   *
 *																										   *
 *Date		 : 2020-06-12																				   *
 **********************************************************************************************************/
 uint32 Fuel_Multiple_Pkg_Damp_Value_Get(uint8 fuel_index);
 /**********************************************************************************************************
 *Function	 : Fuel_Multiple_Pkg_Filter_Flags_Get													       *
 *																										   *
 *Description: TBD																						   *
 *																										   *
 *Parameter  : TBD																						   *
 *																										   *
 *Return	 : void 																					   *
 *																										   *
 *Author	 : Chao Feng																				   *
 *																										   *
 *Date		 : 2020-06-12																				   *
 **********************************************************************************************************/
 uint8 Fuel_Multiple_Pkg_Filter_Flags_Get(uint8 fuel_index);
 /**********************************************************************************************************
 *Function	 : Fuel_Multiple_Pkg_Filter_Moreflags_Get   												   *
 *																										   *
 *Description: TBD																						   *
 *																										   *
 *Parameter  : TBD																						   *
 *																										   *
 *Return	 : void 																					   *
 *																										   *
 *Author	 : Chao Feng																				   *
 *																										   *
 *Date		 : 2020-06-12																				   *
 **********************************************************************************************************/
 uint8 Fuel_Multiple_Pkg_Filter_Moreflags_Get(uint8 fuel_index);
/**********************************************************************************************************
*Function	: Fuel_Multiple_Pkg_Get_UpOrDown_falg														  *
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
uint8 Fuel_Multiple_Pkg_Get_UpOrDown_falg(void);


boolean Fuel_Multiple_Error_Status_Check(void);
boolean Fuel_Multiple_Error_Status_Low_Fastfill(void);

boolean Fuel_Multiple_SenderA_Open_Short_Detected_Dtc(void);
boolean Fuel_Multiple_SenderA_Open_Sample_Dtc(void);
boolean Fuel_Multiple_SenderA_Short_Sample_Dtc(void);

boolean Fuel_Multiple_SenderB_Open_Short_Detected_Dtc(void);
boolean Fuel_Multiple_SenderB_Open_Sample_Dtc(void);
boolean Fuel_Multiple_SenderB_Short_Sample_Dtc(void);

boolean Fuel_Multiple_Sensor_Error_Status_Dtc(void);
uint8 Fuel_Muti_Pkg_Get_Log_Init_Err_Flag(void);
void  Fuel_Muti_Pkg_Set_Log_Init_Err_Flag(uint8 value);

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

