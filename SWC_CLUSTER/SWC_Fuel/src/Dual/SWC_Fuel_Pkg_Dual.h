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
#ifndef FUEL_PKG_DUAL_H
#define FUEL_PKG_DUAL_H

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
#define FUEL_DUAL_RESET                    	(0u)
#define FUEL_DUAL_KEYON                    	(1u)
#define FUEL_DUAL_KEYOFF                   	(2u)

typedef enum
{
	FUEL_DUAL_DAMP_NONE      = 0,
	FUEL_DUAL_DAMP_FUELLOW   = 1,					
	FUEL_DUAL_DAMP_FUELUP    = 2,		
	FUEL_DUAL_DAMP_FUELDOWN  = 3, 
	FUEL_DUAL_DAMP_IDLE      = 4,
    FUEL_DUAL_DAMP_FASTFILL  = 5       
}FUEL_DUAL_DAMP_TYPE;



typedef struct 
{
	uint8  	fuel_a_err;
	uint8  	fuel_b_err;
}FUEL_DUAL_ERR_STATUS;

#define FUEL_DUAL_PERCENT_FULL_INVALID_BYTE  	(0xFFFF)
#define FUEL_DUAL_PERCENT_FULL_INVALID_WORD  	(0xFF00u)

#define FUEL_DUAL_PERCENT_WARNING 				(1u)
#define FUEL_DUAL_PERCENT_WARNING_DISAPPEAR 	(2u)


#define FUEL_DUAL_ERR_DISP_EN                   (1)

#define FUELE_DUAL_VERSION      (10u) // 1.0

/**********************************************************************************************************
** Bits used with FUEL_DUAL_OPTIONS_NVM.
**********************************************************************************************************/

#define FUEL_DUAL_HILL_HOLD_ENABLE_BIT   		(0x80)
#define FUEL_DUAL_FAST_FILL_ENABLE_BIT   		(0x40)
#define FUEL_DUAL_ZSS_REF_ONLY_BIT       		(0x20)
#define FUEL_DUAL_SENDER_B_ENABLE_BIT    		(0x02)
#define FUEL_DUAL_SADDLE_TANK_SYSTEM_BIT 		(0x01)

#define FUEL_DUAL_TANK_SYSTEM_2SPRUE_BIT 		 (0x80) /*The two injectors are selected by the user*/
#define FUEL_DUAL_TANK_SYSTEM_1SPRUE_BIT 		 (0x04) /*A single injector will feed both tanks simultaneously*/
#define FUEL_DUAL_TANK_SYSTEM_AUX_EN_BIT 		 (0x02)
#define FUEL_DUAL_TANK_SYSTEM_BIT 		         (0x01)


#define SWC_FUEL_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"
    extern uint16 Fuel_Dual_Sender_A_Table_Nvm_Cfg[50][2];
    extern uint16 Fuel_Dual_Sender_B_Table_Nvm_Cfg[50][2];

#define SWC_FUEL_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"


/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_FUEL_START_SEC_CODE
#include "SWC_Fuel_MemMap.h"

/**********************************************************************************************************
*Function   : Fuel_Dual_Pkg_Coldinit                                                                  *
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
void Fuel_Dual_Pkg_KSColdinit(void);
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

void Fuel_Dual_Pkg_Warminit(void);
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

void Fuel_Dual_Pkg_Wakeup(void);


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

void Fuel_Dual_Setup_For_Init(void);

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

void Fuel_Dual_Periodic_Process(uint16 fuel_dual_rada, uint16 fuel_dual_radb, boolean fuel02_jam_filter);


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
#if 0
void Fuel_Dual_Ignoff_Process(uint16 fuel_dual_rada, uint16 fuel_dual_radb);
#endif 
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

void Fuel_Dual_Dtc_Resets(void);

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

void Fuel_Dual_Set_Fuel_Fault(uint16 fuel02_counter);


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

boolean Fuel_Dual_Ignoff_Done_Process( void );

/** 
 * [Fuel_Dual_Pkg_Get_Fuel_Level : description]
 * @Author   shujunhua
 * @DateTime 2021/9/29-13:09:08
 * @param    index                    [description]
 * @return   uint16                   [description]
 */
uint16 Fuel_Dual_Pkg_Get_Fuel_Level(uint8 index);


uint16 Fuel_Dual_Pkg_Get_Fuel_slosh(uint8 index);
/** 
 * [Fuel_Dual_Pkg_Get_Fuel_Level_Hys : description]
 * @Author   shujunhua
 * @DateTime 2021/9/29-13:07:02
 * @param    index                    [description]
 * @return   uint32                   [description]
 */
uint32 Fuel_Dual_Pkg_Get_Fuel_Level_Hys(uint8 index);


void   Fuel_Dual_Pkg_Get_Tank_Config( void );

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

uint16 Fuel_Dual_Get_SenderA_PFH(void);
uint16 Fuel_Dual_Get_SenderA_PF(void);
uint16 Fuel_Dual_Get_SenderB_PFH(void);
uint16 Fuel_Dual_Get_SenderB_PF(void);

uint16 Fuel_Dual_SenderA_Unfilter_Flps( void );
uint16 Fuel_Dual_SenderB_Unfilter_Flps( void );
/** 
 * [Fuel_Dual_Init_Finished : description]
 * @Author   shujunhua
 * @DateTime 2021/9/23-16:48:09
 * @param                             [description]
 * @return   boolean                  [description]
 */
boolean Fuel_Dual_Init_Finished(uint8 index );

/** 
 * [Fuel_Dual_Fastfill_Active : description]
 * @Author   shujunhua
 * @DateTime 2021/9/27-15:43:32
 * @param                             [description]
 * @return   boolean                  [description]
 */
boolean Fuel_Dual_Fastfill_Active(uint8 index );

boolean Fuel_Dual_SenderA_Fastfill_Active(void);
boolean Fuel_Dual_SenderB_Fastfill_Active(void);

/** 
 * [Fuel_Dual_Fill_Detected : description]
 * @Author   shujunhua
 * @DateTime 2021/9/29-11:38:08
 * @param    void                     [description]
 * @return   boolean                  [description]
 */
boolean Fuel_Dual_Fill_Detected(uint8 index);

boolean Fuel_Dual_SenderA_Fill_Detected(void);
boolean Fuel_Dual_SenderB_Fill_Detected(void);


/** 
 * [Fuel_Dual_Loss_Detected : description]
 * @Author   shujunhua
 * @DateTime 2021/9/29-11:46:45
 * @param                             [description]
 * @return   boolean                  [description]
 */
boolean Fuel_Dual_Loss_Detected(uint8 index );

boolean Fuel_Dual_SenderA_Loss_Detected(void);
boolean Fuel_Dual_SenderB_Loss_Detected(void);

/** 
 * [Fuel_Dual_Loss_Fill_Detected : description]
 * @Author   shujunhua
 * @DateTime 2021/9/29-11:41:47
 * @param    index                    [description]
 * @return   boolean                  [description]
 */
boolean Fuel_Dual_Loss_Fill_Detected(uint8 index);

void Fuel_Dual_Clear_Fastfill_Flag( void );

/**********************************************************************************************************
*Function   : LinearInterpolateWord                                                                       *
*                                                                                                         *
*Description: 	** The following functions return TRUE if an open/short is detected for the
				** debounce time on the respective sender.      
*                                                                                                         *
*Parameter	: (uint16 *table, uint16 lookupVal)													          *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/

boolean Fuel_Dual_SenderA_Open_Short_Detected(void);
boolean Fuel_Dual_SenderB_Open_Short_Detected(void);
boolean Fuel_Dual_SenderA_Open_Detected(void);
boolean Fuel_Dual_SenderB_Open_Detected(void);
boolean Fuel_Dual_SenderA_Short_Detected(void);
boolean Fuel_Dual_SenderB_Short_Detected(void);

uint16 Fuel_Dual_SenderA_Ignon_Avg_Flps( void );
uint16 Fuel_Dual_SenderA_Ignoff_Ref( void );
uint16 Fuel_Dual_SenderA_Zss_Ref( void );
uint16 Fuel_Dual_Sender_Zss_Ref( void );
uint8 Fuel_Dual_SenderA_Ignon_Good_Samples( void );
uint16 Fuel_Dual_Pkg_SenderA_Rfuel( void );
uint16 Fuel_Dual_Pkg_SenderA_Rflps( void );

uint16 Fuel_Dual_SenderB_Ignon_Avg_Flps( void );
uint16 Fuel_Dual_SenderB_Ignoff_Ref( void );
uint16 Fuel_Dual_SenderB_Zss_Ref( void );
uint8 Fuel_Dual_SenderB_Ignon_Good_Samples( void );
uint16 Fuel_Dual_Pkg_SenderB_Rfuel( void );
uint16 Fuel_Dual_Pkg_SenderB_Rflps( void );
boolean Fuel_Dual_Open_Short_Detect_TT(void);

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

void Fuel_Dual_Network_Message_Missing(void);

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

uint8 Fuel_Dual_SenderA_KO_ConvSample( void );
uint8 Fuel_Dual_SenderA_ZS_ConvSample( void );
uint8 Fuel_Dual_SenderB_KO_ConvSample( void );
uint8 Fuel_Dual_SenderB_ZS_ConvSample( void );

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

uint16 Fuel_Dual_Get_CANFLPS_A( uint16 radin );
uint16 Fuel_Dual_Get_CANFLPS_B( uint16 radin );
/**********************************************************************************************************
*Function	: Fuel_Dual_Pkg_Damp_Mode_Get   														  *
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
FUEL_DUAL_DAMP_TYPE Fuel_Dual_Pkg_Damp_Mode_Get(uint8 fuel_index);
 /**********************************************************************************************************
 *Function	 : Fuel_Dual_Pkg_Damp_Value_Get															   *
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
 uint32 Fuel_Dual_Pkg_Damp_Value_Get(uint8 fuel_index);
 /**********************************************************************************************************
 *Function	 : Fuel_Dual_Pkg_Filter_Flags_Get													       *
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
 uint8 Fuel_Dual_Pkg_Filter_Flags_Get(uint8 fuel_index);
 /**********************************************************************************************************
 *Function	 : Fuel_Dual_Pkg_Filter_Moreflags_Get   												   *
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
 uint8 Fuel_Dual_Pkg_Filter_Moreflags_Get(uint8 fuel_index);
/**********************************************************************************************************
*Function	: Fuel_Dual_Pkg_Get_UpOrDown_falg														  *
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
uint8 Fuel_Dual_Pkg_Get_UpOrDown_falg(void);


boolean Fuel_Dual_Error_Status_Check(void);
boolean Fuel_Dual_Error_Status_Low_Fastfill(void);
boolean Fuel_Dual_Pkg_Get_Aux_Tank_Enable(void);
boolean Fuel_Dual_Fastfill_Active_Main(void);
boolean Fuel_Dual_Fastfill_Active_Aux(void);
boolean Fuel_Dual_Error_Status_Low_Fastfill_Main(void);
boolean Fuel_Dual_Error_Status_Low_Fastfill_Aux(void);

/** 
 * [Fuel_Dual_Pkg_Ignoff_Process : The two sensors are handled independently]
 * @Author   shujunhua
 * @DateTime 2021/9/6-14:55:34
 * @param    fuel_dual_rada           [description]
 * @param    fuel_dual_sender         [description]
 */
void Fuel_Dual_Pkg_Ignoff_Handle(uint16 fuel_dual_rada,uint8 fuel_chanel);
/** 
 * [Fuel_Dual_Setup_Koc : when product ign off handle ]
 * @Author   shujunhua
 * @DateTime 2021/9/6-14:33:39
 * @param                             [description]
 */

void Fuel_Dual_Setup_Koc( void );
/** 
 * [Fuel_Dual_Sender_Open_Short_Detected : description]
 * @Author   shujunhua
 * @DateTime 2021/10/8-10:27:21
 * @param    index                    [description]
 * @return   boolean                  [description]
 */
boolean Fuel_Dual_Sender_Open_Short_Detected (uint8 index);

boolean Fuel_Dual_SenderA_Open_Sample_Dtc(void);
boolean Fuel_Dual_SenderA_Open_Detected_Dtc(void);
boolean Fuel_Dual_SenderA_Short_Sample_Dtc(void);
boolean Fuel_Dual_SenderA_Short_Detected_Dtc(void);
uint8 Fuel_Dual_SenderA_Status_Dtc(void);

boolean Fuel_Dual_SenderB_Open_Sample_Dtc(void);
boolean Fuel_Dual_SenderB_Open_Detected_Dtc(void);
boolean Fuel_Dual_SenderB_Short_Sample_Dtc(void);
boolean Fuel_Dual_SenderB_Short_Detected_Dtc(void);
uint8 Fuel_Dual_SenderB_Status_Dtc(void);


extern uint8 Fuel_Dual_State;
extern uint8 Fuel_Dual_Ign_Status;

#define SWC_FUEL_STOP_SEC_CODE
#include "SWC_Fuel_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
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

