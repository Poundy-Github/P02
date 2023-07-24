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
#ifndef FUEL_DUAL_PROCESS_H
#define FUEL_DUAL_PROCESS_H


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
#include "SWC_Fuel_Dual_Process_Cfg.h"
#pragma ghs section bss=".buram"   
   
    extern uint16 Fuel_Dual_Display_Table_A_CFG[12][2];
    extern uint16 Fuel_Dual_Display_Table_B_CFG[12][2];

#pragma ghs section bss=default

/**********************************************************************************************************
*																								          *
*																								          *
*	              Type Definition																		  *
*																								          *
*																								          *
**********************************************************************************************************/

#define FUEL_DUAL_FLAG_FASTFILL_NONE                      (0u)
#define FUEL_DUAL_FLAG_FASTFILL_ON                        (1u)// ign on fastfill, clean when speed > 1
#define FUEL_DUAL_FLAG_FASTFILL_OFF                       (2u)// ign off fastfill or fastloss, clean when speed > 1
#define FUEL_DUAL_FLAG_FASTFILL_ERR                       (3u)// ign off fastfill or fastloss, clean when speed > 1
/*@2021/01/29:Discuss the key points with the system or take the original alarm point, 
  E point dead oil area special treatment */
#define FUEL_DUAL_A_LFW_Trigger   (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Lfw_Trigger_a)) 
#define FUEL_DUAL_A_LFW_Release   (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Lfw_Release_a)) 
#define FUEL_DUAL_B_LFW_Trigger   (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Lfw_Trigger_b)) 
#define FUEL_DUAL_B_LFW_Release   (Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_Lfw_Release_b))




#define SWC_FUEL_START_SEC_CONST_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"

//extern const uint16 Fuel_Dual_Api_Resisitor_Table[FUEL_DUAL_AD_RESISTOR_TBL_SIZE][2];

#define SWC_FUEL_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"


/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_FUEL_START_SEC_CODE
#include "SWC_Fuel_MemMap.h"

/**********************************************************************************************************
*Function   : Fuel_Dual_Api_ColdInit                                                             	  *
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
extern void Fuel_Dual_Api_ColdInit(void);
/**********************************************************************************************************
*Function   : Fuel_Dual_Api_WarmInit                                                             	  *
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
extern void Fuel_Dual_Api_WarmInit(void);
/**********************************************************************************************************
*Function   : Fuel_Dual_Api_Wakeup                                                               	  *
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

extern void Fuel_Dual_Api_Wakeup(void);

/**********************************************************************************************************
*Function   : Fuel_Dual_Api_Main_Task                                                             	  *
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

extern void Fuel_Dual_Api_Main_Task(void);

/**********************************************************************************************************
*Function   : Fuel_Dual_Api_Sleep_Check                                                            	  *
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

extern boolean Fuel_Dual_Api_Sleep_Check(void);
/**********************************************************************************************************
*Function   : Fuel_Dual_Api_Trans_Out_Normal                                                    	  *
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

//extern void Fuel_Dual_Api_Trans_Out_Normal(void);
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

extern void Fuel_Dual_Api_Trans_Into_Abnormal(void);
/**********************************************************************************************************
*Function   : Fuel_Dual_Api_Trans_Into_Normal                                                   	  *
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

extern void Fuel_Dual_Api_Trans_Into_Normal(void);
/**********************************************************************************************************
*Function   : Fuel_Dual_Zero_Speed_Check                                                          	  *
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
extern boolean Fuel_Dual_Zero_Speed_Check(void);
/**********************************************************************************************************
*Function   : Fuel_Dual_Zss_Speed_Check                                                       	      *
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
boolean Fuel_Dual_Zss_Speed_Check(void);

/**********************************************************************************************************
*Function   : Fuel_Dual_Bar_Process                                                              	  *
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
//void Fuel_Dual_Bar_Process(void);
/**********************************************************************************************************
*Function   : Fuel_Dual_Raise_Process                                                             	  *
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

//void Fuel_Dual_Raise_Process(void);
/**********************************************************************************************************
*Function   : Fuel_Dual_Get_Current_Fuel_Value                                                   	  *
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

uint8 Fuel_Dual_Get_Current_Fuel_Value(void);
/**********************************************************************************************************
*Function   : Fuel_Dual_Get_Target_Fuel_Value                                                      	  *
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

uint8 Fuel_Dual_Get_Target_Fuel_Value(void);
/**********************************************************************************************************
*Function   : Fuel_Dual_Init_Sweep                                                              	  *
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

void Fuel_Dual_Init_Sweep(void);


/**********************************************************************************************************
*Function   : Fuel_Dual_Debug                                                                    	  *
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

void Fuel_Dual_Debug(void);
/** 
 * [Fuel_Dual_Refresh_Target_Bar : description]
 * @Author   shujunhua
 * @DateTime 2021/9/29-13:18:07
 * @param    void                     [description]
 */
void Fuel_Dual_Refresh_Target_Bar(void);



/**********************************************************************************************************
*Function   : Fuel_Dual_Api_Get_Warning_Fuel                                                    	  *
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

//extern boolean Fuel_Dual_Api_Get_Warning_Fuel(void);

/**********************************************************************************************************
*Function   : Fuel_Dual_boProveOut_Check                                                          	  *
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

//extern boolean Fuel_Dual_boProveOut_Check(void);
/**********************************************************************************************************
*Function   : Fuel_Dual_Api_Get_Fuel_Level                                                         	  *
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

//extern uint16 Fuel_Dual_Api_Get_Fuel_Level(void);
/**********************************************************************************************************
*Function   : Fuel_Dual_Damping_Fuel                                                               	  *
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

/** 
 * [Fuel_Dual_Api_Get_Fuel_Percent : description]
 * @Author   shujunhua
 * @DateTime 2021/9/21-9:37:59
 * @param                             [description]
 * @return   uint16                   [description]
 */
uint16 Fuel_Dual_Api_Get_Fuel_Percent(uint8 index );

/** 
 * [Fuel_Dual_Api_Get_Fast_Fill_Status : description]
 * @Author   shujunhua
 * @DateTime 2021/9/29-11:37:13
 * @param                             [description]
 * @return   uint8                    [description]
 */
uint8 Fuel_Dual_Api_Get_Fast_Fill_Status(uint8 index );
/** 
 * [Fuel_Dual_Api_Get_Fuel_Low_Status : description]
 * @Author   shujunhua
 * @DateTime 2021/9/20-14:57:47
 * @param    void                     [description]
 * @return   uint8                    [description]
 */
uint8 Fuel_Dual_Api_Get_Fuel_Low_Status(uint8 index);


/** 
 * [Fuel_Dual_Api_Get_Fuel_Volume : description]
 * @Author   shujunhua
 * @DateTime 2021/9/19-15:15:02
 * @param    chanel                   [description]
 * @return   uint32                   [description]
 */
uint32 Fuel_Dual_Api_Get_Fuel_Volume(uint8 chanel);

/**********************************************************************************************************
*Function   : Fuel_Dual_Sensor_Error_Set_Dtc_Status                                                   *
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
void Fuel_Dual_Sensor_Error_Set_Dtc_Status(void);
/**********************************************************************************************************
*Function   : Fuel_Dual_Get_Fast_Fill_Loss_Status                                                     *
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
uint8 Fuel_Dual_Get_Fast_Fill_Loss_Status(void);
boolean Fuel_Dual_Fastfill_Active_Main(void);

/** 
 * [Fuel_Dual_Api_Get_Sender_Overrange : description]
 * @Author   shujunhua
 * @DateTime 2021/10/9-17:08:07
 * @param    index                    [description]
 * @return   boolean                  [description]
 */
boolean Fuel_Dual_Api_Get_Sender_Overrange(uint8 index);
/** 
 * [Fuel_Dual_Api_Get_Fuel_Volume_VR : description]
 * @Author   shujunhua
 * @DateTime 2021/10/9-19:06:24
 * @param    index                    [description]
 * @return   uint32                   [description]
 */
uint32 Fuel_Dual_Api_Get_Fuel_Volume_VR(uint8 index);
/** 
 * [Fuel_Dual_Api_Sensor_OpenShort_Get : description]
 * @Author   shujunhua
 * @DateTime 2021/10/10-13:53:08
 * @param    index                    [description]
 * @return   uint8                    [description]
 */
uint8 Fuel_Dual_Api_Sensor_OpenShort_Get(uint8 index);

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

#undef EXTERN
#endif
