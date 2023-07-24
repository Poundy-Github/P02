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

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "Rte_Common_Normal.h"
#include "IoHwAb_Cfg_RI.h"
#include "IPC_ClusterApp.h"
#include "CConfig_Cfg.h"
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Fuel_Api_Process.h"

#ifdef FUEL_TANK_MULTIPLE_TYPE_EN
#include "SWC_Fuel_Multiple_Process.h"
#include "SWC_Fuel_Pkg_Multiple.h"
#endif

#ifdef FUEL_TANK_SINGLE_TYPE_EN
#include "SWC_Fuel_Single_Process.h"
#include "SWC_Fuel_Pkg_Single.h"
#endif 

#ifdef FUEL_TANK_DUAL_TYPE_EN
#include "SWC_Fuel_Dual_Process.h"
#include "SWC_Fuel_Pkg_Dual.h"
#endif 

#include "SWC_Fuel_Pkg_Math.h"
#include "SWC_IPC_Config.h"
#include "SWC_TC_Process.h"

#ifdef FUEL_TC_VEHICLE_TEST
extern void vehicle_test (void);
#endif

/**********************************************************************************************************
*																								          *
*																								          *
*	              Type Definition																		  *
*																								          *
*																								          *
**********************************************************************************************************/
#define FUEL_LOG_PERIOD_END_T   (10*20)  // 20s
#define FUEL_LOG_EVENT_END_T    (10*20)  // 20s

#define FUEL_PERIOD_LOG_RECORD_MAX_TIME (10*20)//20S
#define FUEL_PERIOD_LOG_INTRTVAL_TIME  (FUEL_PERIOD_LOG_RECORD_MAX_TIME/10) //2S

#define FUEL_EVENT_SLOW_LOG_RECORD_MAX_TIME (10*120)//120s 
#define FUEL_EVENT_SLOW_LOG_INTRTVAL_TIME  (FUEL_EVENT_SLOW_LOG_RECORD_MAX_TIME/2) // 60s

#define FUEL_EVENT_FAST_LOG_RECORD_MAX_TIME (10*180)//180
#define FUEL_EVENT_FAST_LOG_INTRTVAL_TIME  (FUEL_EVENT_FAST_LOG_RECORD_MAX_TIME/36) // 5s

typedef uint8* (*Fuellogcheck)(void);


#define SWC_FUEL_START_SEC_CONST_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"
/************FUEL  SINGLE  CFG*********************************************************************************************/
/** 
 * [Fuel_Single_Api_Resisitor_Table : The AD value corresponds to the resistance table]
 * @Author   shujunhua
 * @DateTime 2021/5/8-10:02:38
 */
//const uint16 Fuel_Single_Api_Resisitor_Table[FUEL_SINGLE_AD_RESISTOR_TBL_SIZE][2] = FUEL_SINGLE_AD_RESISTOR_TBL;
const uint16 Fuel_Resisitor_Table[FUEL_RESISTOR_TBL_SIZE][2] = FUEL_AD_RESISTOR_TBL;

/** 
 * [Fuel_Single_Display_Table_Common_N01 : SRS-1.6.6.5 Fuel display processing，The pointer indicates the key position of the calibration point definition
                                           Conventional Single Tank ONE]
 * @Author   shujunhua
 * @DateTime 2021/5/8-10:05:12
 */
static const uint16 Fuel_Single_Display_Table_Common_N01[FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N01][2] =FUEL_SINGLE_DISPALY_BAR_TBL_COMMON_N01;
/** 
 * [Fuel_Single_Display_Table_Common_N02 : SRS-1.6.6.5 Fuel display processing，The pointer indicates the key position of the calibration point definition
                                           Conventional Single Tank TWO]
 * @Author   shujunhua
 * @DateTime 2021/5/8-10:06:48
 */
static const uint16 Fuel_Single_Display_Table_Common_N02[FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N02][2] =FUEL_SINGLE_DISPALY_BAR_TBL_COMMON_N02;
/** 
 * [Fuel_Single_Display_Table_Common_N03 : SRS-1.6.6.5 Fuel display processing，The pointer indicates the key position of the calibration point definition
                                           Conventional Single Tank THREE]
 * @Author   shujunhua
 * @DateTime 2021/5/8-10:09:34
 */
static const uint16 Fuel_Single_Display_Table_Common_N03[FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N03][2] =FUEL_SINGLE_DISPALY_BAR_TBL_COMMON_N03;
/** 
 * [Fuel_Single_Display_Table_Common_N04 : SRS-1.6.6.5 Fuel display processing，The pointer indicates the key position of the calibration point definition
                                           Conventional Single Tank FOUR]
 * @Author   shujunhua
 * @DateTime 2021/5/8-10:11:53
 */
static const uint16 Fuel_Single_Display_Table_Common_N04[FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N04][2] =FUEL_SINGLE_DISPALY_BAR_TBL_COMMON_N04;
/** 
 * [Fuel_Single_Display_Table_Common_N05 : SRS-1.6.6.5 Fuel display processing，The pointer indicates the key position of the calibration point definition
                                           Conventional Single Tank FIVE]
 * @Author   shujunhua
 * @DateTime 2021/5/8-10:12:07
 */
static const uint16 Fuel_Single_Display_Table_Common_N05[FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N05][2] =FUEL_SINGLE_DISPALY_BAR_TBL_COMMON_N05;

/*************************************************************************  
 * [Fuel_Single_Display_Table_Common_N05 : SRS-1.6.6.5 Fuel display processing，The pointer indicates the key position of the calibration point definition
                                           Conventional Single Tank FIVE]
 * @Author   GW00227774
 * @DateTime 2021/9/2-11:27:30
 *************************************************************************/
static const uint16 Fuel_Single_Display_Table_Common_N07[FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N07][2] =FUEL_SINGLE_DISPALY_BAR_TBL_COMMON_N07;
/*************************************************************************  
 * [Fuel_Single_Display_Table_Common_N05 : SRS-1.6.6.5 Fuel display processing，The pointer indicates the key position of the calibration point definition
                                           Conventional Single Tank FIVE]
 * @Author   GW00227774
 * @DateTime 2021/9/2-11:27:30
 *************************************************************************/

static const uint16 Fuel_Single_Display_Table_Common_N08[FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N08][2] =FUEL_SINGLE_DISPALY_BAR_TBL_COMMON_N08;
/*************************************************************************  
 * [Fuel_Single_Display_Table_Common_N05 : SRS-1.6.6.5 Fuel display processing，The pointer indicates the key position of the calibration point definition
                                           Conventional Single Tank FIVE]
 * @Author   GW00227774
 * @DateTime 2021/9/2-11:27:30
 *************************************************************************/

static const uint16 Fuel_Single_Display_Table_Common_N09[FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N09][2] =FUEL_SINGLE_DISPALY_BAR_TBL_COMMON_N09;





/** 
 * [FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO1 : description]
 * @Author   shujunhua
 * @DateTime 2021/5/8-10:15:17
 */
static const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO1[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N01][2] =
{
    FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_N01   
};

static const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO2[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N02][2] =
{
    FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_N02   
};

static const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO3[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N03][2] =
{
    FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_N03   
};

static const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO4[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N04][2] =
{
    FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_N04   
};


static const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO5[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N05][2] =
{
    FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_N05   
};

static const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO7[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N07][2] =
{
    FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_N07   
};

static const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO8[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N08][2] =
{
    FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_N08   
};

static const uint16 FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO9[FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N09][2] =
{
    FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_N09   
};




static const uint8 Fuel_Single_Tank_Size_Table[FUEL_VR_COMMMON_SINGLE_MAX]=
{
    0,
    FUEL_SINGLE_TANK_SIZE_N01,
    FUEL_SINGLE_TANK_SIZE_N02,
    FUEL_SINGLE_TANK_SIZE_N03,
    FUEL_SINGLE_TANK_SIZE_N04,
    FUEL_SINGLE_TANK_SIZE_N05,
    FUEL_SINGLE_TANK_SIZE_N07,
    FUEL_SINGLE_TANK_SIZE_N08,
    FUEL_SINGLE_TANK_SIZE_N09,
};

static const uint16 Fuel_Single_Tank_Dead_Table[FUEL_VR_COMMMON_SINGLE_MAX]=
{
    0,
    FUEL_SINGLE_TANK_DEAD_N01,
    FUEL_SINGLE_TANK_DEAD_N02,
    FUEL_SINGLE_TANK_DEAD_N03,
    FUEL_SINGLE_TANK_DEAD_N04,
    FUEL_SINGLE_TANK_DEAD_N05,
    FUEL_SINGLE_TANK_DEAD_N07,
    FUEL_SINGLE_TANK_DEAD_N08,
    FUEL_SINGLE_TANK_DEAD_N09,
};
#ifdef FUEL_TANK_MULTIPLE_TYPE_EN
/************FUEL  MUTI  CFG*********************************************************************************************/
/** 
 * [Fuel_Muti_Display_Table_Common_N01 : Fuel display processing，The pointer indicates the key position of the calibration point definition
                                           Conventional Muti Tank TWO]
 * @Author   shujunhua
 * @DateTime 2021/5/8-14:51:59
 */
static const uint16 Fuel_Muti_Display_Table_Common_N01[FUEL_Muti_DISPALY_BAR_TBL_SIZE_COMMON_N01][2] =FUEL_Muti_DISPALY_BAR_TBL_COMMON_N01;
/** 
 * [Fuel_Muti_Display_Table_Common_N02 : SRS-1.6.6.5 Fuel display processing，The pointer indicates the key position of the calibration point definition
                                           Conventional Muti Tank TWO]
 * @Author   shujunhua
 * @DateTime 2021/5/8-10:06:48
 */
static const uint16 Fuel_Muti_Display_Table_Common_N02[FUEL_Muti_DISPALY_BAR_TBL_SIZE_COMMON_N02][2] =FUEL_Muti_DISPALY_BAR_TBL_COMMON_N02;
/** 
 * [Fuel_Muti_Display_Table_Common_N03 : SRS-1.6.6.5 Fuel display processing，The pointer indicates the key position of the calibration point definition
                                           Conventional Muti Tank THREE]
 * @Author   shujunhua
 * @DateTime 2021/5/8-10:09:34
 */
static const uint16 Fuel_Muti_Display_Table_Common_N03[FUEL_Muti_DISPALY_BAR_TBL_SIZE_COMMON_N03][2] =FUEL_Muti_DISPALY_BAR_TBL_COMMON_N03;

static const uint16 Fuel_Muti_Display_Table_Common_N04[FUEL_Muti_DISPALY_BAR_TBL_SIZE_COMMON_N04][2] =FUEL_Muti_DISPALY_BAR_TBL_COMMON_N04;



static const uint16 FUEL_MUTI_SENDER_A_TABLE_NVM_COMMON_NO1[FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_SIZE_N01][2] =
{
    FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_N01   
};

static const uint16 FUEL_MUTI_SENDER_A_TABLE_NVM_COMMON_NO2[FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_SIZE_N02][2] =
{
    FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_N02   
};

static const uint16 FUEL_MUTI_SENDER_A_TABLE_NVM_COMMON_NO3[FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_SIZE_N03][2] =
{
    FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_N03   
};

static const uint16 FUEL_MUTI_SENDER_A_TABLE_NVM_COMMON_NO4[FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_SIZE_N04][2] =
{
    FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_N04
};


static const uint16 FUEL_MUTI_SENDER_B_TABLE_NVM_COMMON_NO1[FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_SIZE_N01][2] =
{
    FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_N01   
};

static const uint16 FUEL_MUTI_SENDER_B_TABLE_NVM_COMMON_NO2[FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_SIZE_N02][2] =
{
    FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_N02   
};

static const uint16 FUEL_MUTI_SENDER_B_TABLE_NVM_COMMON_NO3[FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_SIZE_N03][2] =
{
    FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_N03   
};

static const uint16 FUEL_MUTI_SENDER_B_TABLE_NVM_COMMON_NO4[FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_SIZE_N04][2] =
{
    FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_N04
};


static const uint8 Fuel_Muti_Tank_Size_Table[FUEL_VR_COMMMON_DUAL_MAX-FUEL_VR_COMMMON_DUAL_NO1]=
{
    FUEL_MUTI_TANK_SIZE_N01,
    FUEL_MUTI_TANK_SIZE_N02,
    FUEL_MUTI_TANK_SIZE_N03,
    FUEL_MUTI_TANK_SIZE_N04,
};

static const uint16 Fuel_Muti_Tank_Dead_Table[FUEL_VR_COMMMON_DUAL_MAX-FUEL_VR_COMMMON_DUAL_NO1]=
{   
    FUEL_MUTI_TANK_DEAD_N01,
    FUEL_MUTI_TANK_DEAD_N02,
    FUEL_MUTI_TANK_DEAD_N03,
    FUEL_MUTI_TANK_DEAD_N04,
};

static const uint8 Fuel_Muti_Tank_Aux_Size_Table[FUEL_VR_COMMMON_DUAL_MAX-FUEL_VR_COMMMON_DUAL_NO1]=
{
    FUEL_MUTI_Aux_TANK_SIZE_N01,
    FUEL_MUTI_Aux_TANK_SIZE_N02,
    FUEL_MUTI_Aux_TANK_SIZE_N03,
    FUEL_MUTI_Aux_TANK_SIZE_N04,
};
#endif 

#ifdef FUEL_TANK_DUAL_TYPE_EN

static const uint16 FUEL_DUAL_SENDER_A_TABLE_NVM_COMMON_NO1[FUEL_DUAL_SENDER_A_AD_TO_PF_TBL_SIZE_N01][2] =
{
    FUEL_DUAL_SENDER_A_AD_TO_PF_TBL_N01
};

static const uint16 FUEL_DUAL_SENDER_B_TABLE_NVM_COMMON_NO1[FUEL_DUAL_SENDER_B_AD_TO_PF_TBL_SIZE_N01][2] =
{
    FUEL_DUAL_SENDER_B_AD_TO_PF_TBL_N01
};

static const uint16 Fuel_Dual_Display_Table_A_N01[FUEL_DUAL_A_DISPALY_BAR_TBL_SIZE_COMMON_N01][2] =FUEL_DUAL_A_DISPALY_BAR_TBL_COMMON_N01;

static const uint16 Fuel_Dual_Display_Table_B_N01[FUEL_DUAL_B_DISPALY_BAR_TBL_SIZE_COMMON_N01][2] =FUEL_DUAL_B_DISPALY_BAR_TBL_COMMON_N01;


static const uint8 Fuel_Dual_Tank_A_Size_Table[FUEL_VR_COMMMON_DUAL_SINGEL_MAX-FUEL_VR_COMMMON_DUAL_SINGEL_N01]=
{
   FUEL_DUAL_TANK_A_SIZE_N01,
};

static const uint8 Fuel_Dual_Tank_B_Size_Table[FUEL_VR_COMMMON_DUAL_SINGEL_MAX-FUEL_VR_COMMMON_DUAL_SINGEL_N01]=
{
    FUEL_DUAL_TANK_B_SIZE_N01,
};

static const uint16 Fuel_Dual_Tank_A_Dead_Table[FUEL_VR_COMMMON_DUAL_SINGEL_MAX-FUEL_VR_COMMMON_DUAL_SINGEL_N01]=
{   
    FUEL_DUAL_TANK_A_DEAD_N01,
};

static const uint16 Fuel_Dual_Tank_B_Dead_Table[FUEL_VR_COMMMON_DUAL_SINGEL_MAX-FUEL_VR_COMMMON_DUAL_SINGEL_N01]=
{   
    FUEL_DUAL_TANK_B_DEAD_N01,
};


#endif 

#define SWC_FUEL_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"


#define SWC_FUEL_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"
/************fuel single para******************************************************************************/
static Fuel_Vhr_CFG_table_t Fuel_Single_Vhr_Display_Cfg_table[FUEL_VR_COMMMON_SINGLE_MAX]=
{ 
   {NULL,0},
   {(void*)Fuel_Single_Display_Table_Common_N01,(uint16)sizeof(Fuel_Single_Display_Table_Common_N01)},
   {(void*)Fuel_Single_Display_Table_Common_N02,(uint16)sizeof(Fuel_Single_Display_Table_Common_N02)},
   {(void*)Fuel_Single_Display_Table_Common_N03,(uint16)sizeof(Fuel_Single_Display_Table_Common_N03)},
   {(void*)Fuel_Single_Display_Table_Common_N04,(uint16)sizeof(Fuel_Single_Display_Table_Common_N04)},
   {(void*)Fuel_Single_Display_Table_Common_N05,(uint16)sizeof(Fuel_Single_Display_Table_Common_N05)},
   {(void*)Fuel_Single_Display_Table_Common_N07,(uint16)sizeof(Fuel_Single_Display_Table_Common_N07)},
   {(void*)Fuel_Single_Display_Table_Common_N08,(uint16)sizeof(Fuel_Single_Display_Table_Common_N08)},
   {(void*)Fuel_Single_Display_Table_Common_N09,(uint16)sizeof(Fuel_Single_Display_Table_Common_N09)},
};

static Fuel_Vhr_CFG_table_t Fuel_Singel_Vhr_Adc_Pf_Cfg_table[FUEL_VR_COMMMON_SINGLE_MAX]=
{ 
   {NULL,0},
   {(void*)FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO1,(uint16)sizeof(FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO1)},
   {(void*)FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO2,(uint16)sizeof(FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO2)},
   {(void*)FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO3,(uint16)sizeof(FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO3)},
   {(void*)FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO4,(uint16)sizeof(FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO4)},
   {(void*)FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO5,(uint16)sizeof(FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO5)},
   {(void*)FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO7,(uint16)sizeof(FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO7)},
   {(void*)FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO8,(uint16)sizeof(FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO8)},
   {(void*)FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO9,(uint16)sizeof(FUEL_SINGLE_SENDER_A_TABLE_NVM_COMMON_NO9)},
};

#ifdef FUEL_TANK_MULTIPLE_TYPE_EN
/************fuel muti para******************************************************************************/

static Fuel_Vhr_CFG_table_t Fuel_Muti_Vhr_Display_Cfg_table[FUEL_VR_COMMMON_DUAL_MAX-FUEL_VR_COMMMON_DUAL_NO1]=
{ 
   {(void*)Fuel_Muti_Display_Table_Common_N01,(uint16)sizeof(Fuel_Muti_Display_Table_Common_N01)},
   {(void*)Fuel_Muti_Display_Table_Common_N02,(uint16)sizeof(Fuel_Muti_Display_Table_Common_N02)},
   {(void*)Fuel_Muti_Display_Table_Common_N03,(uint16)sizeof(Fuel_Muti_Display_Table_Common_N03)},
   {(void*)Fuel_Muti_Display_Table_Common_N04,(uint16)sizeof(Fuel_Muti_Display_Table_Common_N04)},
};


static Fuel_Muti_Vhr_CFG_table_t Fuel_Muti_Vhr_Adc_Pf_Cfg_table[FUEL_VR_COMMMON_DUAL_MAX-FUEL_VR_COMMMON_DUAL_NO1]=
{ 
    {(void*)FUEL_MUTI_SENDER_A_TABLE_NVM_COMMON_NO1,(uint16)sizeof(FUEL_MUTI_SENDER_A_TABLE_NVM_COMMON_NO1),\
    (void*)FUEL_MUTI_SENDER_B_TABLE_NVM_COMMON_NO1,(uint16)sizeof(FUEL_MUTI_SENDER_B_TABLE_NVM_COMMON_NO1)},
    {(void*)FUEL_MUTI_SENDER_A_TABLE_NVM_COMMON_NO2,(uint16)sizeof(FUEL_MUTI_SENDER_A_TABLE_NVM_COMMON_NO2),\
    (void*)FUEL_MUTI_SENDER_B_TABLE_NVM_COMMON_NO2,(uint16)sizeof(FUEL_MUTI_SENDER_B_TABLE_NVM_COMMON_NO2)},
    {(void*)FUEL_MUTI_SENDER_A_TABLE_NVM_COMMON_NO3,(uint16)sizeof(FUEL_MUTI_SENDER_A_TABLE_NVM_COMMON_NO3),\
    (void*)FUEL_MUTI_SENDER_B_TABLE_NVM_COMMON_NO3,(uint16)sizeof(FUEL_MUTI_SENDER_B_TABLE_NVM_COMMON_NO3)},
    {(void*)FUEL_MUTI_SENDER_A_TABLE_NVM_COMMON_NO4,(uint16)sizeof(FUEL_MUTI_SENDER_A_TABLE_NVM_COMMON_NO4),\
    (void*)FUEL_MUTI_SENDER_B_TABLE_NVM_COMMON_NO4,(uint16)sizeof(FUEL_MUTI_SENDER_B_TABLE_NVM_COMMON_NO4)},
};
#endif 

#ifdef FUEL_TANK_DUAL_TYPE_EN
static Fuel_Duti_Vhr_CFG_table_t Fuel_Dual_Vhr_Adc_Pf_Cfg_table[FUEL_VR_COMMMON_DUAL_SINGEL_MAX-FUEL_VR_COMMMON_DUAL_SINGEL_N01]=
{ 
    {(void*)FUEL_DUAL_SENDER_A_TABLE_NVM_COMMON_NO1,(uint16)sizeof(FUEL_DUAL_SENDER_A_TABLE_NVM_COMMON_NO1),\
     (void*)FUEL_DUAL_SENDER_B_TABLE_NVM_COMMON_NO1,(uint16)sizeof(FUEL_DUAL_SENDER_B_TABLE_NVM_COMMON_NO1)},
};

static Fuel_Duti_Vhr_CFG_table_t Fuel_Dual_Vhr_Display_Cfg_table[FUEL_VR_COMMMON_DUAL_SINGEL_MAX-FUEL_VR_COMMMON_DUAL_SINGEL_N01]=
{ 
   {(void*)Fuel_Dual_Display_Table_A_N01,(uint16)sizeof(Fuel_Dual_Display_Table_A_N01),\
   (void*)Fuel_Dual_Display_Table_B_N01, (uint16)sizeof(Fuel_Dual_Display_Table_B_N01)},
};

#endif 
#define SWC_FUEL_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"


/***************************************************************************************/
#define SWC_FUEL_START_SEC_GLOBALB_VAR_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"



static FUEL_MODULE_OUTPUT_DATA_STRUCT Fuel_Module_Output_Parameter = {0};
static FUEL_MODULE_CCONFIG_DATA_NVM_STRUCT Fuel_Module_Cconfig_Data_Nvm = {0};
static IPC_M2S_ClusterAppAPPFUEL_t Fuel_Ipc_Debug_Date = {0};
static Fuel_EventDebounce_t Fuel_EventDebounce_Main;
static Fuel_EventDebounce_t Fuel_EventDebounce_Aux;
static uint32 Fuel_Dtc_Service14_Count=0; 
/*Add it for log */
static uint8 fuel_log_message_type =0;
static uint8 Fule_Log_Init_Date=0;
static Fuel_Log_Period_t Fule_Log_Period_Date ={{0Xffff,0Xffff},{0xff,0xff},{0xff,0xff},{0xff,0xff},{0xff,0xff},0xff};
static Fuel_Log_Event_t  Fule_Log_Event_Date ={{{0Xffff,0Xffff},{0xff,0xff},{0xff,0xff},{0xff,0xff},{0xff,0xff},0xff},{0xff}};
static Fuel_Log_Error_t  Fuel_Log_Error_Date ={0,};
static uint16 Fule_Log_Period_Count=0;
static uint8  Fule_Log_delay_output_Count=20;// 2S
static uint16 Fule_Log_Event_Count=0;
static uint16 Fule_Log_Event_Slow_Count=0;
static boolean Fuel_Api_Log_ColdInit_Flag = FALSE;
static Fuel_Log_CodeInitCfg_t Fuel_Log_CodeInitCfg_Data = { {0xff,0xff},{0xff,0xff},{0xff,0xff},{0xff,0xff},{0xff},{0xff},{0xff},{0xff}};


#define SWC_FUEL_STOP_SEC_GLOBALB_VAR_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"
/***************************************************************************************/


#pragma ghs section bss=".buram"
static Fuel_Lfw_t  Fuel_Lfw_pecent;
static uint8  Fuel_Single_Config_Tank_Size;
static uint16 Fuel_Single_Config_Tank_Dead;
static uint8  Fuel_Muti_Config_Tank_Size;
static uint8  Fuel_Muti_Aux_Config_Tank_Size;

static uint16 Fuel_Muti_Config_Tank_Dead;
static uint8  Fuel_Dual_A_Config_Tank_Size;
static uint8  Fuel_Dual_B_Config_Tank_Size;
static uint16 Fuel_Dual_A_Config_Tank_Dead;
static uint16 Fuel_Dual_B_Config_Tank_Dead;
GAFUEL_DEBUG 	Fuel_Single_Api_FuelInfo;
static uint32 fuel_cold_init_finish;
#pragma ghs section bss=default
#pragma ghs section bss=".buram"
Fuel_config_t Fuel_Tank_Cfg_Diag;
static FUEL_LOG_SYS_STATUS Fule_log_power_status;
#pragma ghs section bss=default

#define FUEL_SINGLE_TANK_SIZE_CFG   (Fuel_Single_Config_Tank_Size) 
#define FUEL_SINGLE_TANK_DEAD_CFG   (Fuel_Single_Config_Tank_Dead) 

#define FUEL_MUTI_TANK_SIZE_CFG   (Fuel_Muti_Config_Tank_Size) 
#define FUEL_MUTI_AUX_TANK_SIZE_CFG   (Fuel_Muti_Aux_Config_Tank_Size)
#define FUEL_MUTI_TANK_DEAD_CFG   (Fuel_Muti_Config_Tank_Dead) 
#define FUEL_COLD_FINISH_INIT_MASK  ((uint32)0xa5a5a5a5)

#define FUEL_DUAL_TANK_A_SIZE_CFG  Fuel_Dual_A_Config_Tank_Size
#define FUEL_DUAL_TANK_B_SIZE_CFG  Fuel_Dual_B_Config_Tank_Size
#define FUEL_DUAL_TANK_A_DEAD_CFG  Fuel_Dual_A_Config_Tank_Dead
#define FUEL_DUAL_TANK_B_DEAD_CFG  Fuel_Dual_B_Config_Tank_Dead

#ifdef FUEL_TIME_CAL
typedef struct
{
    uint32 time_stamp[2];                  /* execution start/stop time stamps */
    uint32 min_exec_time;                  /* minimum execution time in counts */
    uint32 max_exec_time;                  /* maximum execution time in counts */
    uint32 avg_exec_time;                  /* average execution time in counts */
    uint32 tot_exec_time;                  /* scratch for average calculation */
    uint32 num_samples;                    /* number of executions accounted */
	uint32 exeTime;
    boolean reset_buffer;                  /* reset buffer flag */
} FUEL_EM_BUFFER;

#define FUEL_TEST_TIME  0xffff 

#define FUEL_TASK_END_CALCULATE(current_task_id)\
{    \
\
	TM_TimerElapsed(&FUEL_Task_em_buffer[current_task_id].time_stamp[0],&FUEL_Task_em_buffer[current_task_id].time_stamp[1]);\
\
	FUEL_Task_em_buffer[current_task_id].exeTime = FUEL_Task_em_buffer[current_task_id].time_stamp[1]/10;/*uint : 1us*/\
\
	if(FUEL_Task_em_buffer[current_task_id].max_exec_time < FUEL_Task_em_buffer[current_task_id].exeTime)\
	{\
		FUEL_Task_em_buffer[current_task_id].max_exec_time = FUEL_Task_em_buffer[current_task_id].exeTime;\
	}\
\
	if(FUEL_Task_em_buffer[current_task_id].min_exec_time > FUEL_Task_em_buffer[current_task_id].exeTime)\
	{\
		FUEL_Task_em_buffer[current_task_id].min_exec_time = FUEL_Task_em_buffer[current_task_id].exeTime;\
	}\
\
	if((FUEL_Task_em_buffer[current_task_id].tot_exec_time < (FUEL_TEST_TIME))&&(FALSE == FUEL_Task_em_buffer[current_task_id].reset_buffer))\
	{\
		FUEL_Task_em_buffer[current_task_id].tot_exec_time+= FUEL_Task_em_buffer[current_task_id].exeTime;\
		FUEL_Task_em_buffer[current_task_id].num_samples++;\
	}\
	else\
	{\
		FUEL_Task_em_buffer[current_task_id].avg_exec_time = FUEL_Task_em_buffer[current_task_id].tot_exec_time/FUEL_Task_em_buffer[current_task_id].num_samples;\
		FUEL_Task_em_buffer[current_task_id].tot_exec_time = FUEL_Task_em_buffer[current_task_id].exeTime;\
		FUEL_Task_em_buffer[current_task_id].num_samples = 1;\
		FUEL_Task_em_buffer[current_task_id].reset_buffer = FALSE;\
	}\
	Rte_Exit_ExclusiveArea_Normal(); \
	}\

	
#define FUEL_TASK_BEGIN_CALCULATE(current_task_id)	\
{  Rte_Enter_ExclusiveArea_Normal();\
   TM_TimerStartStamp(&FUEL_Task_em_buffer[current_task_id].time_stamp[0]);\
}\

typedef struct
{
	uint32			 		TimerTick_u32;
	uint8					Status_u8;
}s_fuelOstmData_t;   

typedef struct 
{
	uint32 fuelRunableTimerTest_MAX;
	uint32 fuelRunableTimerTest_MIN;
	uint32 fuelRunableTimerTest_AVG;
	uint32 fuelRunableTimerTest_Index;
	uint64 fuelRunableTimerTest_Alltime;
	uint32 fuelRunableTimerTest_MAXRunTime;
	uint32 fuelRunableTimerTest_AVGRunTime;
	uint32 fuelRunableTimerTest_IndexRunTime;
	uint32 fuelRunableTimerTest_OverTimeTick;
	uint64 fuelRunableTimerTest_AlltimeRunTime;
}s_fuelRunableTimerTest_t;

#define SWC_FUEL_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"

static FUEL_EM_BUFFER FUEL_Task_em_buffer[1];

s_fuelRunableTimerTest_t fuelRunableTimerTest[1];

s_fuelOstmData_t  fuelOstmTickCounter_s[1];

#define SWC_FUEL_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_Fuel_MemMap.h"

#define SWC_FUEL_START_SEC_CODE
#include "SWC_Fuel_MemMap.h"

extern void TM_TimerElapsed(uint32 * StartStamp, uint32 * TimeElapsed);
extern void TM_TimerStartStamp(uint32 * StartStamp);

static void fuel_RteAdaptRunableOstmStart(uint8 index)
{
	uint32 passtime;
	TM_TimerElapsed(&fuelOstmTickCounter_s[index].TimerTick_u32,&passtime);
	TM_TimerStartStamp(&fuelOstmTickCounter_s[index].TimerTick_u32);
	if(passtime > fuelRunableTimerTest[index].fuelRunableTimerTest_MAXRunTime)
	{
		fuelRunableTimerTest[index].fuelRunableTimerTest_MAXRunTime = passtime;
	}
	if((index == 1 && passtime > 200000) || (index == 2 && passtime > 100000))
	{
		fuelRunableTimerTest[index].fuelRunableTimerTest_OverTimeTick ++;
	}
	fuelRunableTimerTest[index].fuelRunableTimerTest_IndexRunTime++;
	fuelRunableTimerTest[index].fuelRunableTimerTest_AlltimeRunTime += passtime;
	fuelRunableTimerTest[index].fuelRunableTimerTest_AVGRunTime = (uint32)(fuelRunableTimerTest[index].fuelRunableTimerTest_AlltimeRunTime/fuelRunableTimerTest[index].fuelRunableTimerTest_Index);
	Rte_Enter_ExclusiveArea_Normal();
}

static fuel_RteAdaptRunableOstmCheck(uint8 index)
{
	uint32 passtime;
	TM_TimerElapsed(&fuelOstmTickCounter_s[index].TimerTick_u32,&passtime);
	TM_TimerStartStamp(&fuelOstmTickCounter_s[index].TimerTick_u32);
	if(passtime > 15000)
	{
		passtime ++;
	}
	if(passtime > fuelRunableTimerTest[index].fuelRunableTimerTest_MAX)
	{
		fuelRunableTimerTest[index].fuelRunableTimerTest_MAX = passtime;
	}
	if(passtime < fuelRunableTimerTest[index].fuelRunableTimerTest_MIN)
	{
		fuelRunableTimerTest[index].fuelRunableTimerTest_MIN = passtime;
	}
	fuelRunableTimerTest[index].fuelRunableTimerTest_Index++;
	fuelRunableTimerTest[index].fuelRunableTimerTest_Alltime += passtime;
	fuelRunableTimerTest[index].fuelRunableTimerTest_AVG = (uint32)(fuelRunableTimerTest[index].fuelRunableTimerTest_Alltime/fuelRunableTimerTest[index].fuelRunableTimerTest_Index);
	Rte_Exit_ExclusiveArea_Normal();
}

#define SWC_FUEL_STOP_SEC_CODE
#include "SWC_Fuel_MemMap.h"

#endif 


#define SWC_FUEL_START_SEC_CODE
#include "SWC_Fuel_MemMap.h"
static void Fuel_log_Task(void);
/** 
 * [Fuel_DiagerrorCallback :Fuel fault code records CS interface callback ]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T17:38:43+0800
 * @param    fuel_type                [description]
 */
static void Fuel_DiagerrorCallback(Fuel_TANK_CFG_ENUM fuel_type)
{
   if(fuel_type ==Fuel_SINGE_TYPE)
   {
       if(FUEL_SENSOR_ERROR_OPEN == Fuel_EventDebounce_Main.eventStatus)
	   {
		   Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR1_OPEN , 1);
		   Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR1_SHORT , 0);
	   }
	   else if(FUEL_SENSOR_ERROR_SHORT == Fuel_EventDebounce_Main.eventStatus)
	   {
		   Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR1_OPEN , 0);
		   Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR1_SHORT , 1);
	   }
	   else
	   {
		   Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR1_OPEN , 0);
		   Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR1_SHORT , 0);
	   }

   }
   else if ((fuel_type==Fuel_MULTI_TYPE) || (fuel_type==Fuel_DUAL_SINGLE_TYPE)) 
   {
     if(FUEL_SENSOR_ERROR_OPEN == Fuel_EventDebounce_Main.eventStatus)
	   {
		   Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR1_OPEN , 1);
		   Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR1_SHORT , 0);
	   }
	   else if(FUEL_SENSOR_ERROR_SHORT == Fuel_EventDebounce_Main.eventStatus)
	   {
		   Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR1_OPEN , 0);
		   Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR1_SHORT , 1);
	   }
	   else
	   {
		   Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR1_OPEN , 0);
		   Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR1_SHORT , 0);
	   }
	   if(FUEL_SENSOR_ERROR_OPEN == Fuel_EventDebounce_Aux.eventStatus)
	   {
		   Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR2_OPEN , 1);
		   Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR2_SHORT , 0);
	   }
	   else if(FUEL_SENSOR_ERROR_SHORT == Fuel_EventDebounce_Aux.eventStatus)
	   {
		   Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR2_OPEN , 0);
		   Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR2_SHORT , 1);
	   }
	   else
	   {
		   Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR2_OPEN , 0);
		   Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR2_SHORT , 0);
	   }

   }
   else 
   {

   }
	

}
/** 
 * [Fuel_errorDebounce : Fuel failure code anti-jiggling processing function]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T17:39:23+0800
 * @param    fuel_type                [	Fuel_TYPE_NONE =0,
                                    	Fuel_SINGE_TYPE	,
                                    	Fuel_MULTI_TYPE	 ,]
 * @param    errorStatus              [ FUEL_SENSOR_ERROR_NONE	=0,
                                    	FUEL_SENSOR_ERROR_OPEN	 ,
                                    	FUEL_SENSOR_ERROR_SHORT	 ,]
 * @param                             [The sensor currently being detected]
 */
static void Fuel_errorDebounce(Fuel_TANK_CFG_ENUM fuel_type,Fuel_Sensor_Error_Enum errorStatus,Fuel_EventDebounce_t *Fuel_EventDebounce )
{
    Fuel_Sensor_Error_Enum tEventSts;
    tEventSts = Fuel_EventDebounce->eventStatus;
    if(FUEL_SENSOR_ERROR_OPEN == errorStatus)
    {
        Fuel_EventDebounce->passedCounter = 0;
		Fuel_EventDebounce->short_failedCounter =0;
        Fuel_EventDebounce->open_failedCounter++;
        if(Fuel_EventDebounce->open_failedCounter > FUEL_EVENT_FAILED_THRSHOLD)
        {
            tEventSts = FUEL_SENSOR_ERROR_OPEN;
            Fuel_EventDebounce->open_failedCounter = 0;
        }
    }
	else if(FUEL_SENSOR_ERROR_SHORT == errorStatus)
    {
        Fuel_EventDebounce->passedCounter = 0;
		Fuel_EventDebounce->open_failedCounter =0;
        Fuel_EventDebounce->short_failedCounter++;
        if(Fuel_EventDebounce->short_failedCounter > FUEL_EVENT_FAILED_THRSHOLD)
        {
            tEventSts = FUEL_SENSOR_ERROR_SHORT;
            Fuel_EventDebounce->short_failedCounter = 0;
        }
    }
    else 
    {
       	Fuel_EventDebounce->open_failedCounter =0;
		Fuel_EventDebounce->short_failedCounter =0;
        Fuel_EventDebounce->passedCounter++;
        if(Fuel_EventDebounce->passedCounter > FUEL_EVENT_PASSED_THRSHOLD)
        {
            tEventSts = FUEL_SENSOR_ERROR_NONE;
            Fuel_EventDebounce->passedCounter = 0;
        }
    }
    if(tEventSts == Fuel_EventDebounce->eventStatus)
    {
        Fuel_EventDebounce->monitorCounter++;
        if (((FUEL_SENSOR_ERROR_NONE == Fuel_EventDebounce->eventStatus )&&(Fuel_EventDebounce->monitorCounter > FUEL_EVENT_PASSED_THRSHOLD))
            ||((FUEL_SENSOR_ERROR_OPEN == Fuel_EventDebounce->eventStatus)&&(Fuel_EventDebounce->monitorCounter > FUEL_EVENT_FAILED_THRSHOLD))
            ||((FUEL_SENSOR_ERROR_SHORT == Fuel_EventDebounce->eventStatus)&&(Fuel_EventDebounce->monitorCounter > FUEL_EVENT_FAILED_THRSHOLD)))
        {
           // Rte_Call_DiagnosticMonitor_XX_SetEventStatus(tEventSts);
            //Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR1_OPEN,)
            Fuel_DiagerrorCallback(fuel_type);
            Fuel_EventDebounce->monitorCounter = 0;
        }
    }
    else
    {
        //Rte_Call_DiagnosticMonitor_XX_SetEventStatus(tEventSts);
        Fuel_EventDebounce->eventStatus = tEventSts;
        Fuel_DiagerrorCallback(fuel_type);
        Fuel_EventDebounce->monitorCounter = 0;
    }
}

   
/** 
 * [Fual_Api_Dtc_Reset : Restart anti-shaking when a $14 fault code cleaning service is detected]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T17:41:29+0800
 * @param    void                     [description]
 */
static void Fual_Api_Dtc_Reset(void)
{
    (void)memset(&Fuel_EventDebounce_Main,0,sizeof(Fuel_EventDebounce_t));
    (void)memset(&Fuel_EventDebounce_Aux,0,sizeof(Fuel_EventDebounce_t));
	
}
/** 
 * [Fuel_DiagnosticMonitorMain_100ms : Fuel DTC code detection task 100ms]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T17:42:18+0800
 * @param    fuel_type                [description]
 * @param    Fuel_EventDebounce_main  [description]
 * @param    Fuel_EventDebounce_aux   [description]
 */
static void Fuel_DiagnosticMonitorMain_100ms(Fuel_TANK_CFG_ENUM fuel_type,Fuel_EventDebounce_t *Fuel_EventDebounce_main,Fuel_EventDebounce_t *Fuel_EventDebounce_aux)
{ 

    #ifdef Rte_Read_rpSR_SWCNormal_DiagMonitorReInitFlag_ChangeCounter
    	uint32 dtc_clear_flag_count=0;
    	(void)Rte_Read_rpSR_SWCNormal_DiagMonitorReInitFlag_ChangeCounter(&dtc_clear_flag_count);
    	if(Fuel_Dtc_Service14_Count!=dtc_clear_flag_count)
    	{
    	  Fuel_Dtc_Service14_Count =dtc_clear_flag_count;
    	  Fual_Api_Dtc_Reset();
    	}    
    #endif


  if(fuel_type ==Fuel_SINGE_TYPE)
  {
    if(Fuel_Api_Get_Fuel_Resisitor_Value(0)>=10000)  // OPEN >=1000  
    {
        Fuel_errorDebounce(fuel_type,FUEL_SENSOR_ERROR_OPEN,Fuel_EventDebounce_main);
    }
	else if (Fuel_Api_Get_Fuel_Resisitor_Value(0)<=100) // Short <=10 
	{ 
		Fuel_errorDebounce(fuel_type,FUEL_SENSOR_ERROR_SHORT,Fuel_EventDebounce_main);
	}
    else
    {
        Fuel_errorDebounce(fuel_type,FUEL_SENSOR_ERROR_NONE,Fuel_EventDebounce_main);
    }
  }
  else if ((fuel_type==Fuel_MULTI_TYPE) || (fuel_type==Fuel_DUAL_SINGLE_TYPE))  
  {
  	  if(Fuel_Api_Get_Fuel_Resisitor_Value(0)>=10000)  // OPEN >=1000  
	  {
		  Fuel_errorDebounce(fuel_type,FUEL_SENSOR_ERROR_OPEN,Fuel_EventDebounce_main);
	  }
	  else if (Fuel_Api_Get_Fuel_Resisitor_Value(0)<=100) // Short <=10 
	  { 
		  Fuel_errorDebounce(fuel_type,FUEL_SENSOR_ERROR_SHORT,Fuel_EventDebounce_main);
	  }
	  else
	  {
		  Fuel_errorDebounce(fuel_type,FUEL_SENSOR_ERROR_NONE,Fuel_EventDebounce_main);
	  }

	if(Fuel_Api_Get_Fuel_Resisitor_Value(1)>=10000)  // OPEN >=1000  
    {
        Fuel_errorDebounce(fuel_type,FUEL_SENSOR_ERROR_OPEN,Fuel_EventDebounce_aux);
    }
	else if (Fuel_Api_Get_Fuel_Resisitor_Value(1)<=100) // Short <=10 
	{ 
		Fuel_errorDebounce(fuel_type,FUEL_SENSOR_ERROR_SHORT,Fuel_EventDebounce_aux);
	}
    else
    {
        Fuel_errorDebounce(fuel_type,FUEL_SENSOR_ERROR_NONE,Fuel_EventDebounce_aux);
    }

  
  }
  else 
  {

  }
}




/** 
 * [Fuel_Api_Abs : Reconstructed absolute value function]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:48:33+0800
 * @param    c                        [description]
 * @return   sint32                   [description]
 */
sint32 Fuel_Api_Abs(sint32 c)
{
	if (c < 0)
	{
	    c = ~(c - (sint32)1);
	}
	return c;
}

/** 
 * [Fuel_Api_ColdInit include fuel module cold and warm init ]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:03:14+0800
 * @param    void                     [description]
 */

void Fuel_Api_ColdInit(void)
{   

    Fuel_Tank_Cfg_Diag =  Fuel_Rte_Api_Get_Fuel_Tank_Cfg();   
 	Fuel_Api_Config_Data_NVM_Init();
   // Fuel_Lfw_pecent.Fuel_lfw_trigger_pecent =Fuel_API_Get_Lfw_Percent().Fuel_lfw_trigger_pecent;
   // Fuel_Lfw_pecent.Fuel_lfw_release_pecent= Fuel_API_Get_Lfw_Percent().Fuel_lfw_release_pecent; 
    Fuel_Lfw_pecent = Fuel_API_Get_Lfw_Percent();
    (void)memset(&Fuel_EventDebounce_Main,0,sizeof(Fuel_EventDebounce_t));
	(void)memset(&Fuel_EventDebounce_Aux,0,sizeof(Fuel_EventDebounce_t));
	if ((FALSE != Fuel_Module_Rte_Coldinit_Warminit_Flag())&&(fuel_cold_init_finish==FUEL_COLD_FINISH_INIT_MASK)) // warm start
    {   
    
        Fuel_Api_WarmInit();
		Fuel_Api_Update_can_publish(Fuel_IP_FuelMainTankR,(uint16)0X00A);
        //   Fuel_Api_Update_can_publish(Fuel_IP_FuelAuxTankR,(uint16)0X00A);
		Fule_log_power_status = FUEL_LOG_SYS_WARM;
    }
	else
    {    
        if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
        {
           #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
                Fuel_Multiple_Api_ColdInit();
                Fuel_Api_Update_can_publish(Fuel_IP_FuelMainTankR,(uint16)0X00A);
                Fuel_Api_Update_can_publish(Fuel_IP_FuelAuxTankR,(uint16)0X00A);
           #endif 
           
			
        }
       
        else if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_SINGLE_MAX))
        {   
            
			
           #ifdef FUEL_TANK_SINGLE_TYPE_EN
           Fuel_Single_Api_KSColdinit();
           Fuel_Api_Update_can_publish(Fuel_IP_FuelMainTankR,(uint16)0X00A);
           #endif 
          
        }
		else if(FUEL_TANK_CFG == FUEL_VR_HIGH_VOLT_SINGLE_NO1)
        {   
        }
        else
        {
          #ifdef FUEL_TANK_DUAL_TYPE_EN
              Fuel_Dual_Api_ColdInit();
              Fuel_Api_Update_can_publish(Fuel_IP_FuelMainTankR,(uint16)0X00A);
              Fuel_Api_Update_can_publish(Fuel_IP_FuelAuxTankR,(uint16)0X00A);
          #endif 
        }
        fuel_cold_init_finish=FUEL_COLD_FINISH_INIT_MASK ;
		Fule_log_power_status = FUEL_LOG_SYS_COLD;
	}		
}
/** 
 * [Fuel_Api_WarmInit : fuel module warm init]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:50:07+0800
 * @param    void                     [description]
 */

void Fuel_Api_WarmInit(void)
{

        if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
        {
        #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
            Fuel_Multiple_Api_WarmInit();
        #endif 
        }
        else if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<=FUEL_SINGLE_DISPALY_TABLE_MAX))
        {
        #ifdef FUEL_TANK_SINGLE_TYPE_EN
            Fuel_Single_Api_KSWarminit();
        #endif 
        }
		else if(FUEL_TANK_CFG == FUEL_VR_HIGH_VOLT_SINGLE_NO1)
        {   
        }
        else
        {
	    #ifdef FUEL_TANK_DUAL_TYPE_EN
            Fuel_Dual_Api_ColdInit();
            #endif
        }
}

/** 
 * [Fuel_Api_Trans_Out_Normal : Power is switched off from normal mode]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:50:01+0800
 * @param    void                     [description]
 */
#if 0
void Fuel_Api_Trans_Out_Normal(void)
{
      if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
        {
            #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
            Fuel_Multiple_Api_Trans_Out_Normal();
            #endif 
           
        }
        else  if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_SINGLE_MAX))
        {  
            
            #ifdef FUEL_TANK_SINGLE_TYPE_EN  
            Fuel_Single_Api_Trans_Outof_Normal();
            #endif 
        }
		else if(FUEL_TANK_CFG == FUEL_VR_HIGH_VOLT_SINGLE_NO1)
        {   
        }
        else
        {
    
        }
}
#endif
/** 
 * [Fuel_Api_Trans_Into_Abnormal : The power supply switches from normal mode to abnormal high and low voltage undervoltage mode]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:49:53+0800
 * @param    void                     [description]
 */

void Fuel_Api_Trans_Into_Abnormal(void)
{
#if 0
	/* Multiple fuel tank */
	if((FUEL_TANK_CFG == 3) || (FUEL_TANK_CFG == 4))
	{
		Fuel_Multiple_Api_Trans_Into_Normal();
	}
	else
	{
		Fuel_Single_Api_Trans_Into_Normal();
	}
#endif     
      if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
        {
           
            #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
             Fuel_Multiple_Api_Trans_Into_Normal();
            #endif 
        }
        else if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_SINGLE_MAX))
        { 
            
            #ifdef FUEL_TANK_SINGLE_TYPE_EN        
            Fuel_Single_Api_Trans_Into_Normal();
            #endif
        }
		else if(FUEL_TANK_CFG == FUEL_VR_HIGH_VOLT_SINGLE_NO1)
        {   
        }
        else
        {
    
        }
}

/** 
 * [Fuel_Api_Get_Warning_Fuel : Provide fuel short circuit and low fuel alarm status]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:49:47+0800
 * @param    void                     [2 - FLASH, 1 - ON, 0 - OFF   ]
 */

uint8 Fuel_Api_Get_Warning_Fuel(void)
{
	/* Multiple fuel tank */
    uint8 result=0;
    
    if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
    {
#ifdef FUEL_TANK_MULTIPLE_TYPE_EN
        result=(uint8)Fuel_Multiple_Api_Get_Warning_Fuel();
#endif 
       
    }
    else if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_SINGLE_MAX))
    {               
#ifdef FUEL_TANK_SINGLE_TYPE_EN    
    result=Fuel_Single_Api_Get_Fuel_Warning();
#endif 
    }
    else if(FUEL_TANK_CFG == FUEL_VR_HIGH_VOLT_SINGLE_NO1)
    {   
    }
    else
    {

    }
           
  return result;
}
/** 
 * [Fuel_Api_Set_Warning_Fuel : SWC-RTE-SR-Update Fuel_Status_Fuel_Status]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:49:35+0800
 * @param    fuel_warning_set_status  [2 - FLASH, 1 - ON, 0 - OFF]
 */

void Fuel_Api_Set_Warning_Fuel(uint8 fuel_warning_set_status)
{
	Fuel_Rte_Api_Set_Warning_Fuel(fuel_warning_set_status);
}
/** 
 * [Fuel_Api_Get_Sensor_Error_Status : Get fuel for malfunction, open circuit or short circuit]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:49:22+0800
 * @param    void                     [description]
 * @return   boolean                  [True:fault]
 */

boolean  Fuel_Api_Get_Sensor_Error_Status(void)
{
    boolean result=FALSE;

    
    if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
    {
    
     #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
         result= Fuel_Multiple_Sensor_Error_Status();   
     #endif 
     
    }
    else if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_SINGLE_MAX))
    { 
    #ifdef FUEL_TANK_SINGLE_TYPE_EN  
        result= Fuel_Single_Api_Get_Error_Status();
    #endif 
        
    }
    else if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_DUAL_SINGEL_N01)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_DUAL_SINGEL_MAX))
    {
    #ifdef FUEL_TANK_DUAL_TYPE_EN  
        result = (Fuel_Dual_Api_Get_Sender_Overrange(FUEL_TANK_A))|(Fuel_Dual_Api_Get_Sender_Overrange(FUEL_TANK_B));
    #endif 

    }
    else if(FUEL_TANK_CFG == FUEL_VR_HIGH_VOLT_SINGLE_NO1)
    { 
        result=FALSE;
    }
    else
    {
        result=FALSE;
    }
    return result;
    
}


boolean  Fuel_Api_Get_SensorAorB_Status_Change(void)
{
    boolean result=FALSE;

    if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
     {
          #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
          result= Fuel_Multiple_Error_Status_Check();      
          #endif   
     }
     else if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_SINGLE_MAX))
     { 
         result= Fuel_Single_Error_Status_Check();
     }
     else
     {
         result=FALSE;
     }
     return result;
}

/** 
 * [Fuel_Api_Get_Fuel_Volume : Calculate the number of fuel litres remaining in the current tank in real time]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T17:44:06+0800
 * @param    void                     [description]
 * @return   uint32                   [Unit:ml]
 */
uint32 Fuel_Api_Get_Fuel_Volume(void)
{   
    uint32 result=0;
    if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
    {
        #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
         result = Fuel_Multiple_Api_Get_Fuel_Volume();
        #endif
       
    }
    else  if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG< FUEL_VR_COMMMON_SINGLE_MAX))
    { 
    #ifdef FUEL_TANK_SINGLE_TYPE_EN  
        result = Fuel_single_Api_Get_Fuel_Volume_VR();
    #endif 
       
    }
    else if(FUEL_TANK_CFG == FUEL_VR_COMMMON_SINGLE_NO2)
    { 
        result=0;
    }
    else if(FUEL_TANK_CFG == FUEL_VR_HIGH_VOLT_SINGLE_NO1)
    { 
        result=0;
    }
    else
    {
        result=0;
    }
    return result;
}
  

/** 
 * [Fuel_Api_update_ipc_rte : Update RTE and IPC communication data ]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T17:45:45+0800
 * @param    void                     [description]
 */
static void Fuel_Api_update_ipc_rte(void)
{   
    IPC_M2S_ClusterAppAPPFUEL_t fuel_ipc;
    (void)memset(&fuel_ipc,0,sizeof(IPC_M2S_ClusterAppAPPFUEL_t));
    #ifdef FUEL_TANK_DUAL_TYPE_EN
    uint8 index = 0;
    #endif

    if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
    {   
        #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
         /*add status for tc_module*/
         Fuel_Module_Output_Parameter.Fuel_Init_Complete_Status = ((Fuel_Api_Get_Finished_Init()==TRUE)?1u:0u);
         Fuel_Module_Output_Parameter.Fuel_Sensor_Error_Status = ( (Fuel_Multiple_Open_Short_Detected()==TRUE)?1u:0u);
         /*add status for tt_module*/
         Fuel_Module_Output_Parameter.Fuel_Warning_Status = Fuel_Multiple_Api_Get_Fuel_Low_Status();
         #ifndef SWC_FUEL_ADAPT_B03
            Fuel_Module_Output_Parameter.Fuel_Level_Display_Value = (uint32)Fuel_Multiple_Api_Get_Rest_Fuel_Volume();
         #else 
            Fuel_Module_Output_Parameter.Fuel_Level_Display_Value = Fuel_Multiple_Api_Get_Rest_Fuel_Volume();
         #endif
         Fuel_Module_Output_Parameter.Fuel_Level_Display_Percent = Fuel_Multiple_Api_Get_Fuel_Percent(); 
         Fuel_Module_Output_Parameter.Fuel_Sensor_Raw_Value_A = Fuel_Api_Get_Fuel_Resisitor_Value(0);
         Fuel_Module_Output_Parameter.Fuel_Sensor_Raw_Value_B = Fuel_Api_Get_Fuel_Resisitor_Value(1);
         Fuel_Module_Output_Parameter.Fuel_Fast_Fill_Status = Fuel_Api_Get_FastFill_Status();
         Fuel_Api_Set_Module_Data(Fuel_Module_Output_Parameter);
     
         /*send fuel data To IPC */
         /*Fixed percentage given to display, otherwise empty oil cannot be displayed*/
         fuel_ipc.TankFuelLevelPercent = Fuel_Multiple_Api_Get_Fuel_Percent(); 
         fuel_ipc.Fuel_Tank_System = ((Fuel_Api_Get_Fuel_Tank_Aux_Enable()==TRUE)?1u:0u);
        if (FALSE!=Fuel_Api_Get_Finished_Init())
        {
            fuel_ipc.Low_fuel_warning = Fuel_Multiple_Api_Get_Fuel_Low_Status();
        }
        else
        {
            fuel_ipc.Low_fuel_warning =0;

        }
            
         fuel_ipc.LFW_Trigger_Ipc=  Fuel_API_Muti_Get_Lfw_Percent_Trigger();
         fuel_ipc.LFW_Release_Ipc=  Fuel_API_Muti_Get_Lfw_Percent_Release();
         fuel_ipc.Tankportposition = FUEL_TANK_PORT_CFG;
         #endif
        
    }
    else if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_SINGLE_MAX))
    {
         #ifdef FUEL_TANK_SINGLE_TYPE_EN
         /*add status for tc_module*/
         Fuel_Module_Output_Parameter.Fuel_Init_Complete_Status = ((Fuel_Api_Get_Finished_Init()==TRUE)?1u:0u);
         Fuel_Module_Output_Parameter.Fuel_Sensor_Error_Status = ((Fuel_Single_Api_Get_Sender_Overrange()==TRUE)?1u:0u);
         /*add status for tt_module*/
         Fuel_Module_Output_Parameter.Fuel_Warning_Status = Fuel_Single_Api_Get_Fuel_Warning();
         #ifndef SWC_FUEL_ADAPT_B03
           Fuel_Module_Output_Parameter.Fuel_Level_Display_Value = Fuel_Single_Api_Get_Fuel_Volume();
         #else
           Fuel_Module_Output_Parameter.Fuel_Level_Display_Value = (uint16)Fuel_Single_Api_Get_Fuel_Volume();
         #endif 
       
         Fuel_Module_Output_Parameter.Fuel_Level_Display_Percent = Fuel_Single_Api_Get_Fuel_hmi_percent(); 
         Fuel_Module_Output_Parameter.Fuel_Sensor_Raw_Value_A = Fuel_Api_Get_Fuel_Resisitor_Value(0);
         Fuel_Module_Output_Parameter.Fuel_Sensor_Raw_Value_B = 0;
         Fuel_Module_Output_Parameter.Fuel_Fast_Fill_Status = Fuel_Api_Get_FastFill_Status();
         Fuel_Api_Set_Module_Data(Fuel_Module_Output_Parameter);
                   
        if (FALSE!=Fuel_Api_Get_Finished_Init())
        {
           fuel_ipc.Low_fuel_warning = Fuel_Single_Api_Get_Fuel_Warning();  
        }
        else
        {
            fuel_ipc.Low_fuel_warning =0;

        }
        /*send fuel data To IPC */
         /*Fixed percentage given to display, otherwise empty oil cannot be displayed*/
        
         fuel_ipc.TankFuelLevelPercent = Fuel_Single_Api_Get_Fuel_hmi_percent(); 
         fuel_ipc.Fuel_Tank_System = ((Fuel_Api_Get_Fuel_Tank_Aux_Enable()==TRUE)?1u:0u);
         fuel_ipc.LFW_Trigger_Ipc=  Fuel_API_Single_Get_Lfw_Percent_Trigger();
         fuel_ipc.LFW_Release_Ipc=  Fuel_API_Single_Get_Lfw_Percent_Release();
         fuel_ipc.Tankportposition = FUEL_TANK_PORT_CFG;
         #endif
    
    }
    else if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_DUAL_SINGEL_N01)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_DUAL_SINGEL_MAX))
    {
         #ifdef FUEL_TANK_DUAL_TYPE_EN
         /*update rte data */
         Fuel_Module_Output_Parameter.Fuel_Init_Complete_Status = ((Fuel_Dual_Init_Finished(FUEL_TANK_A)==TRUE)?1u:0u);
         Fuel_Module_Output_Parameter.Fuel_Init_Complete_Status_Aux = ((Fuel_Dual_Init_Finished(FUEL_TANK_B)==TRUE)?1u:0u);
         
         Fuel_Module_Output_Parameter.Fuel_Sensor_Error_Status = ((Fuel_Dual_Api_Get_Sender_Overrange(FUEL_TANK_A)==TRUE)?1u:0u);
         Fuel_Module_Output_Parameter.Fuel_Sensor_Error_Status_Aux = ((Fuel_Dual_Api_Get_Sender_Overrange(FUEL_TANK_B)==TRUE)?1u:0u);
        
         Fuel_Module_Output_Parameter.Fuel_Warning_Status = Fuel_Dual_Api_Get_Fuel_Low_Status(FUEL_TANK_A);
         Fuel_Module_Output_Parameter.Fuel_Warning_Status_Aux = Fuel_Dual_Api_Get_Fuel_Low_Status(FUEL_TANK_B);
       
         Fuel_Module_Output_Parameter.Fuel_Level_Display_Value = (uint32)Fuel_Dual_Api_Get_Fuel_Volume(FUEL_TANK_A);
         Fuel_Module_Output_Parameter.Fuel_Level_Display_Value_Aux= (uint32)Fuel_Dual_Api_Get_Fuel_Volume(FUEL_TANK_B);
       
         Fuel_Module_Output_Parameter.Fuel_Level_Display_Percent = Fuel_Dual_Api_Get_Fuel_Percent(FUEL_TANK_A);  
         Fuel_Module_Output_Parameter.Fuel_Level_Display_Percent_Aux = Fuel_Dual_Api_Get_Fuel_Percent(FUEL_TANK_B); 
         
         Fuel_Module_Output_Parameter.Fuel_Sensor_Raw_Value_A = Fuel_Api_Get_Fuel_Resisitor_Value(0);
         Fuel_Module_Output_Parameter.Fuel_Sensor_Raw_Value_B = Fuel_Api_Get_Fuel_Resisitor_Value(1);
         
         Fuel_Module_Output_Parameter.Fuel_Fast_Fill_Status = Fuel_Dual_Fastfill_Active(FUEL_TANK_A);
         Fuel_Module_Output_Parameter.Fuel_Fast_Fill_Status_Aux = Fuel_Dual_Fastfill_Active(FUEL_TANK_B);
         Fuel_Module_Output_Parameter.Fuel_Sensor_Switch = Fuel_Api_Rte_Get_Oil_Switch();
         Fuel_Api_Set_Module_Data(Fuel_Module_Output_Parameter);
        /*update ipc data */
        for(index=0;index<FUEL_TANK_SUM;index++)
        {
            if (FALSE!=Fuel_Dual_Init_Finished(index))
            {
               fuel_ipc.Low_fuel_warning_Dual[index] = Fuel_Dual_Api_Get_Fuel_Low_Status(index);
            }
            else
            {
               fuel_ipc.Low_fuel_warning_Dual[index] = 0;
            }

           

          #ifdef FUEL_DUAL_SINGLE_DEBUG 
              fuel_ipc.TankFuelLevelPercent = Fuel_Dual_Api_Get_Fuel_Percent(FUEL_TANK_A);
              fuel_ipc.LFW_Trigger_Ipc= Fuel_API_Get_Lfw_Percent_Trigger(FUEL_TANK_A);
              fuel_ipc.LFW_Release_Ipc=  Fuel_API_Get_Lfw_Percent_Release(FUEL_TANK_A);
              fuel_ipc.Fuel_Tank_System = ((Fuel_Api_Get_Fuel_Tank_Aux_Enable()==TRUE)?1u:0u);

                if (FALSE!=Fuel_Dual_Init_Finished(index))
                {
                    fuel_ipc.Low_fuel_warning = Fuel_Dual_Api_Get_Fuel_Low_Status(index); 
                }
                else
                {
                    fuel_ipc.Low_fuel_warning = 0;
                }
              fuel_ipc.Tankportposition = FUEL_TANK_PORT_CFG; 
          #else
              fuel_ipc.TankFuelLevelPercent_Dual[index] =  Fuel_Dual_Api_Get_Fuel_Percent(index);
              fuel_ipc.LFW_Trigger_Ipc_Dual[index] =  Fuel_API_Get_Lfw_Percent_Trigger(index);
              fuel_ipc.LFW_Release_Ipc_Dual[index] =  Fuel_API_Get_Lfw_Percent_Release(index);   
          #endif 

            
        }
        #endif

    }
    else
    {

    }

     if(sizeof (fuel_ipc) <=sizeof (Fuel_Ipc_Debug_Date))
     {  
        
        (void)memcpy(&Fuel_Ipc_Debug_Date,&fuel_ipc,sizeof (fuel_ipc));
     }
 //    FUEL_MODULE_DEBUG1("Fuel_res=%d fuel_ad=%d fuel_flps=%d  fuel_rfuel=%d fuel_flag=%d",Fuel_Module_Output_Parameter.Fuel_Sensor_Raw_Value_A,Fuel_Api_Get_Fuel_AD_Value(0),Fuel_Multiple_SenderA_Unfilter_Flps(),Fuel_Multiple_Pkg_SenderA_Rfuel(),Fuel_Multiple_Pkg_Filter_Flags_Get(0)) 
  
    (void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_FUEL,(uint8 *)&fuel_ipc,(uint16)sizeof(IPC_M2S_ClusterAppAPPFUEL_t),FALSE);
     
}


/** 
 * [Fuel_Api_tank_cfg_get : Distinguish between single float and double float]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:59:02+0800
 * @param    void                     [ Fuel_TYPE_NONE =0,
                                    	Fuel_SINGE_TYPE	,
                                    	Fuel_MULTI_TYPE	 ,]
 */
Fuel_TANK_CFG_ENUM Fuel_Api_tank_cfg_get(void)
{
    Fuel_TANK_CFG_ENUM Return_fuel_type=Fuel_TYPE_NONE;
    if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
    {
        Return_fuel_type = Fuel_MULTI_TYPE;
    }
    else if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_SINGLE_MAX))
    {
        Return_fuel_type = Fuel_SINGE_TYPE;
    }
    else if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_DUAL_SINGEL_N01)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_DUAL_SINGEL_MAX))
    {
        Return_fuel_type = Fuel_DUAL_SINGLE_TYPE;
    }
    else 
    {
        Return_fuel_type =Fuel_TYPE_NONE;
    }
    return  Return_fuel_type ;
}

/** 
 * [Fuel_API_Get_Tank_Size :Obtain the total volume of a single tank]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:37:33+0800
 * @param    void                     [description]
 * @return   uint8                    [Unit:1L]
 */
uint8 Fuel_API_Single_Get_Tank_Size(void)
{
    uint8 fuel_single_total_volume=FUEL_SINGLE_TANK_SIZE_CFG;
    return fuel_single_total_volume;
}
/** 
 * [Fuel_API_Get_Tank_Dead : Gets the size of the dead oil zone under a single tank]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:48:58+0800
 * @param    void                     [description]
 * @return   uint16                   [Unit:ml]
 */
uint16 Fuel_API_Single_Get_Tank_Dead(void)
{
    uint16 fuel_single_dead_volume =FUEL_SINGLE_TANK_DEAD_CFG;
    return fuel_single_dead_volume;
}
/** 
 * [Fuel_API_Muti_Get_Tank_Size : Obtain the total volume of a muti tank]
 * @Author   shujunhua
 * @DateTime 2021/5/8-16:28:17
 * @param    void                     [description]
 * @return   uint8                    [description]
 */

uint8 Fuel_API_Muti_Get_Tank_Size(void)
{
    uint8 fuel_muti_total_volume=  FUEL_MUTI_TANK_SIZE_CFG ;
    return fuel_muti_total_volume;
}



/** 
 * [Fuel_API_Muti_Get_Tank_Dead : Gets the size of the dead oil zone under a muti tank]
 * @Author   shujunhua
 * @DateTime 2021/5/8-16:28:21
 * @param    void                     [description]
 * @return   uint16                   [description]
 */

uint16 Fuel_API_Muti_Get_Tank_Dead(void)
{
    uint16 fuel_muti_dead_volume=FUEL_MUTI_TANK_DEAD_CFG;
    return fuel_muti_dead_volume;
}
/** 
 * [Fuel_API_Muti_Aux_Get_Tank_Size : Gets  the Aux volume of a muti tank]
 * @Author   shujunhua
 * @DateTime 2021/5/9-9:11:42
 * @param    void                     [description]
 * @return   uint8                    [description]
 */

uint8 Fuel_API_Muti_Aux_Get_Tank_Size(void)
{
    uint8 fuel_aux_volume=FUEL_MUTI_AUX_TANK_SIZE_CFG;
    return fuel_aux_volume;
}

/** 
 * [Fuel_API_Dual_Get_A_Tank_Dead : description]
 * @Author   shujunhua
 * @DateTime 2021/9/27-13:37:43
 * @param    chanel                   [description]
 * @return   uint16                   [description]
 */
uint16 Fuel_API_Dual_Get_Tank_Dead(uint8 index)
{
    uint16 fuel_dead_volume = FUEL_DUAL_TANK_A_DEAD_CFG;
    if(index< FUEL_TANK_SUM)
    {
        if(index == FUEL_TANK_A)
        {
            fuel_dead_volume = FUEL_DUAL_TANK_A_DEAD_CFG;  
        }
        else
        {
            fuel_dead_volume = FUEL_DUAL_TANK_B_DEAD_CFG;
        }
    }
    return fuel_dead_volume;
}
/** 
 * [Fuel_Api_Dual_Get_Tank_Size : description]
 * @Author   shujunhua
 * @DateTime 2021/9/29-13:15:58
 * @param    index                    [description]
 * @return   uint8                    [description]
 */
uint8 Fuel_Api_Dual_Get_Tank_Size(uint8 index)
{
    uint8 fuel_total_volume = FUEL_DUAL_TANK_A_SIZE_CFG;
    if(index< FUEL_TANK_SUM)
    {
        if(index == FUEL_TANK_A)
        {
            fuel_total_volume = FUEL_DUAL_TANK_A_SIZE_CFG;  
        }
        else
        {
            fuel_total_volume = FUEL_DUAL_TANK_B_SIZE_CFG;
        }
    }
    return fuel_total_volume;
}

/** 
 * [Fuel_Api_Tank_Vr_cfg_get : Gets the tank VHR parameters for the current configuration]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:58:42+0800
 * @param    void                     [     FUEL_VR_COMMMON_NONE =0,
                                        	FUEL_VR_COMMMON_SINGLE_NO1,
                                        	FUEL_VR_COMMMON_SINGLE_NO2,
                                        	FUEL_VR_COMMMON_SINGLE_NO3,
                                        	FUEL_VR_COMMMON_SINGLE_NO4,
                                        	FUEL_VR_COMMMON_SINGLE_NO5,
                                            FUEL_VR_COMMMON_SINGLE_MAX,
                                        	FUEL_VR_COMMMON_DUAL_NO1,
                                        	FUEL_VR_COMMMON_DUAL_NO2,
                                        	FUEL_VR_COMMMON_DUAL_NO3,
                                        	FUEL_VR_COMMMON_DUAL_NO4,
                                        	FUEL_VR_HIGH_VOLT_SINGLE_NO1,]
 */
FUEL_VR_TYPE_ENUM Fuel_Api_Tank_Vr_cfg_get(void)
{
    FUEL_VR_TYPE_ENUM fuel_tank_vr_para=FUEL_TANK_CFG;
    return fuel_tank_vr_para;
}

/** 
 * [Fuel_Api_can_ouput_task : FUEL MODULE CAN OUTPUT TASK]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T17:46:06+0800
 * @param    void                     [description]
 */
static void Fuel_Api_can_ouput_task(void)
{  
    uint16 Fuel_main_res=0;
    uint16 Fuel_aux_res=0;
    Fuel_TANK_CFG_ENUM Fuel_tank_sys = Fuel_Api_tank_cfg_get();

    if(FALSE == Fuel_Api_Get_Power_Mode_State())
    {
        
        if(Fuel_tank_sys != Fuel_DUAL_SINGLE_TYPE) 
        {
            Fuel_Api_Update_can_publish(Fuel_IP_FuelLvlInfo,(uint8)0xFF);
        }
        else
        {
            Fuel_Api_Update_can_publish(Fuel_IP_FuelLvlInfo,(uint8)0xFF); 
            Fuel_Api_Update_can_publish(Fuel_IP_FuelLvlInfoAux,(uint8)0xFF); 
          
        }
        Fuel_Api_Update_can_publish(Fuel_IP_FuelLvlLowLmpSts,(uint8)0);
        if((Fuel_tank_sys==Fuel_MULTI_TYPE) || (Fuel_tank_sys==Fuel_DUAL_SINGLE_TYPE))
        {
            Fuel_Api_Update_can_publish(Fuel_IP_FuelMainTankR,(uint16)0XA);
            Fuel_Api_Update_can_publish(Fuel_IP_FuelAuxTankR,0XA);	
        }
        else
        {
            Fuel_Api_Update_can_publish(Fuel_IP_FuelMainTankR,(uint16)0XA);
            Fuel_Api_Update_can_publish(Fuel_IP_FuelAuxTankR,0X0A);	
        }
    }
    else
    {

        if ((Fuel_Api_Get_Sensor_Error_Status() == FALSE))
        {     
            if(Fuel_tank_sys != Fuel_DUAL_SINGLE_TYPE) 
            {
                Fuel_Api_Update_can_publish(Fuel_IP_FuelLvlInfo,(uint8)(Fuel_Api_Get_Fuel_Volume()/1000));  
            }
            else
            {   
                #ifdef FUEL_TANK_DUAL_TYPE_EN  
                Fuel_Api_Update_can_publish(Fuel_IP_FuelLvlInfo,(uint8)(Fuel_Dual_Api_Get_Fuel_Volume_VR(FUEL_TANK_A)/1000));  
                Fuel_Api_Update_can_publish(Fuel_IP_FuelLvlInfoAux,(uint8)(Fuel_Dual_Api_Get_Fuel_Volume_VR(FUEL_TANK_B)/1000));  
                #endif 
            }
            	
            if((Fuel_tank_sys==Fuel_MULTI_TYPE) || (Fuel_tank_sys==Fuel_DUAL_SINGLE_TYPE))
            {	
                if(Fuel_Api_Get_Fuel_Resisitor_Value(0)>=10000)
                {
                    Fuel_main_res = 1000;
                } 
                else
                {
                    Fuel_main_res = (uint16)(Fuel_Api_Get_Fuel_Resisitor_Value(0u)/10u);
                }
                if(Fuel_Api_Get_Fuel_Resisitor_Value(1)>=10000)
                {
                    Fuel_aux_res = 1000;
                } 
                else
                {
                    Fuel_aux_res = (uint16)(Fuel_Api_Get_Fuel_Resisitor_Value(1u)/10u);
                }  
                Fuel_Api_Update_can_publish(Fuel_IP_FuelMainTankR,(uint16)Fuel_main_res);
                Fuel_Api_Update_can_publish(Fuel_IP_FuelAuxTankR, (uint16)Fuel_aux_res);
            }
            else
            {
                if(Fuel_Api_Get_Fuel_Resisitor_Value(0)>=10000)
                {
                    Fuel_main_res = 1000;
                } 
                else
                {
                    Fuel_main_res = (uint16)(Fuel_Api_Get_Fuel_Resisitor_Value(0u)/10u);
                }
                Fuel_Api_Update_can_publish(Fuel_IP_FuelMainTankR,(uint16)(Fuel_main_res));
                Fuel_Api_Update_can_publish(Fuel_IP_FuelAuxTankR,0X0A);
            }


        }
        else 
    	{
            
            if(Fuel_tank_sys != Fuel_DUAL_SINGLE_TYPE) 
            {
                Fuel_Api_Update_can_publish(Fuel_IP_FuelLvlInfo,(uint8)0xff);   
            }
            else
            {   
//                Fuel_Api_Update_can_publish(Fuel_IP_FuelLvlInfo,(uint8)0xff);
//                Fuel_Api_Update_can_publish(Fuel_IP_FuelLvlInfoAux,(uint8)0xff);
            }

            if((Fuel_tank_sys==Fuel_MULTI_TYPE) )
            {
#ifdef FUEL_TANK_MULTIPLE_TYPE_EN
                if((Fuel_Multiple_SenderA_Short_Detected_Dtc())&&(Fuel_Multiple_SenderA_Short_Sample_Dtc()))
                {
                    Fuel_Api_Update_can_publish(Fuel_IP_FuelMainTankR,(uint16)0X0);

                }
                else if ((Fuel_Multiple_SenderA_Open_Detected_Dtc())&&(Fuel_Multiple_SenderA_Open_Sample_Dtc()))
                {
                    Fuel_Api_Update_can_publish(Fuel_IP_FuelMainTankR,(uint16)0X3FF);

                }
                else
                {
                    if(Fuel_Api_Get_Fuel_Resisitor_Value(0)>=10000)
                    {
                        Fuel_main_res = 1000;
                    } 
                    else if (Fuel_Api_Get_Fuel_Resisitor_Value(0)<=100)
                    {
                        Fuel_main_res = 10;
                    }
                    else
                    {
                        Fuel_main_res = (uint16)(Fuel_Api_Get_Fuel_Resisitor_Value(0u)/10u);
                    }

                    Fuel_Api_Update_can_publish(Fuel_IP_FuelMainTankR,(uint16)Fuel_main_res);
                }
                if((Fuel_Multiple_SenderB_Short_Detected_Dtc())&&(Fuel_Multiple_SenderB_Short_Sample_Dtc()))
                {
                    Fuel_Api_Update_can_publish(Fuel_IP_FuelAuxTankR,(uint16)0X0);
                }
                else if ((Fuel_Multiple_SenderB_Open_Detected_Dtc())&&(Fuel_Multiple_SenderB_Open_Sample_Dtc()))
                {
                    Fuel_Api_Update_can_publish(Fuel_IP_FuelAuxTankR,(uint16)0X3FF);
                }
                else
                {
                    if(Fuel_Api_Get_Fuel_Resisitor_Value(1)>=10000)
                    {
                        Fuel_aux_res = 1000;
                    } 
                    else if (Fuel_Api_Get_Fuel_Resisitor_Value(1)<=100)
                    {
                        Fuel_aux_res = 10;
                    }
                    else
                    {
                        Fuel_aux_res = (uint16)(Fuel_Api_Get_Fuel_Resisitor_Value(1u)/10u);
                    } 
                    Fuel_Api_Update_can_publish(Fuel_IP_FuelAuxTankR, (uint16)Fuel_aux_res);
                }
#endif     
            }
            else if ( Fuel_tank_sys==Fuel_DUAL_SINGLE_TYPE)
            {
#ifdef FUEL_TANK_DUAL_TYPE_EN
                if((Fuel_Dual_SenderA_Short_Detected_Dtc())&&(Fuel_Dual_SenderA_Short_Sample_Dtc()))
                {
                    Fuel_Api_Update_can_publish(Fuel_IP_FuelMainTankR,(uint16)0X0);
                    Fuel_Api_Update_can_publish(Fuel_IP_FuelLvlInfo,(uint8)0xff);
                }
                else if ((Fuel_Dual_SenderA_Open_Detected_Dtc())&&(Fuel_Dual_SenderA_Open_Sample_Dtc()))
                {
                    Fuel_Api_Update_can_publish(Fuel_IP_FuelMainTankR,(uint16)0X3FF);
                    Fuel_Api_Update_can_publish(Fuel_IP_FuelLvlInfo,(uint8)0xff); 
                }
                else
                {
                    if(Fuel_Api_Get_Fuel_Resisitor_Value(0)>=10000)
                    {
                        Fuel_main_res = 1000;
                    } 
                    else if (Fuel_Api_Get_Fuel_Resisitor_Value(0)<=100)
                    {
                        Fuel_main_res = 10;
                    }
                    else
                    {
                        Fuel_main_res = (uint16)(Fuel_Api_Get_Fuel_Resisitor_Value(0u)/10u);
                    }

                    Fuel_Api_Update_can_publish(Fuel_IP_FuelMainTankR,(uint16)Fuel_main_res);
                    Fuel_Api_Update_can_publish(Fuel_IP_FuelLvlInfo,(uint8)(Fuel_Dual_Api_Get_Fuel_Volume_VR(FUEL_TANK_A)/1000));  
                }
                if((Fuel_Dual_SenderB_Short_Detected_Dtc())&&(Fuel_Dual_SenderB_Short_Sample_Dtc()))
                {
                    Fuel_Api_Update_can_publish(Fuel_IP_FuelAuxTankR,(uint16)0X0);
                     Fuel_Api_Update_can_publish(Fuel_IP_FuelLvlInfoAux,(uint8)0xff);
                }
                else if ((Fuel_Dual_SenderB_Open_Detected_Dtc())&&(Fuel_Dual_SenderB_Open_Sample_Dtc()))
                {
                    Fuel_Api_Update_can_publish(Fuel_IP_FuelAuxTankR,(uint16)0X3FF);
                    Fuel_Api_Update_can_publish(Fuel_IP_FuelLvlInfoAux,(uint8)0xff);
                }
                else
                {
                    if(Fuel_Api_Get_Fuel_Resisitor_Value(1)>=10000)
                    {
                        Fuel_aux_res = 1000;
                    }
                    else if (Fuel_Api_Get_Fuel_Resisitor_Value(1)<=100)
                    {
                        Fuel_aux_res = 10;
                    }
                    else
                    {
                        Fuel_aux_res = (uint16)(Fuel_Api_Get_Fuel_Resisitor_Value(1u)/10u);
                    }
                    Fuel_Api_Update_can_publish(Fuel_IP_FuelAuxTankR, (uint16)Fuel_aux_res);
                    Fuel_Api_Update_can_publish(Fuel_IP_FuelLvlInfoAux,(uint8)(Fuel_Dual_Api_Get_Fuel_Volume_VR(FUEL_TANK_B)/1000));
                }
#endif     

            }
            else
            {

#ifdef FUEL_TANK_SINGLE_TYPE_EN

                if((Fuel_Single_Pkg_SenderA_Open_Detected_Dtc())&&(Fuel_Single_Pkg_SenderA_Open_Sample_Dtc()))
                {
                    Fuel_Api_Update_can_publish(Fuel_IP_FuelMainTankR,(uint16)0X3FF);
                }
                else if((Fuel_Single_Pkg_SenderA_Short_Detected_Dtc())&&(Fuel_Single_Pkg_SenderA_Short_Sample_Dtc()))
                {
                    Fuel_Api_Update_can_publish(Fuel_IP_FuelMainTankR,(uint16)0X0);
                }
                else
                {

                    if(Fuel_Api_Get_Fuel_Resisitor_Value(0)>=10000)
                    {
                        Fuel_main_res = 1000;
                    }
                    else if (Fuel_Api_Get_Fuel_Resisitor_Value(0)<=100)
                    {
                        Fuel_main_res = 10;
                    }
                    else
                    {
                        Fuel_main_res = (uint16)(Fuel_Api_Get_Fuel_Resisitor_Value(0u)/10u);
                    }
                    Fuel_Api_Update_can_publish(Fuel_IP_FuelMainTankR,(uint16)Fuel_main_res);

                }

#endif
            }
       }
    }
}

/**
 * [Fuel_Api_Main_Task : Fuel cycle 100ms main task]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:50:18+0800
 * @param    void                     [description]
 */
void Fuel_Api_Main_Task(void)
{
	#ifdef FUEL_TC_VEHICLE_TEST
	static uint8 time_500ms;
	#endif
	if(FALSE != Fuel_Rte_Api_Get_Power_Mode_State_Is_Sleep())
	{
		/* sleep do nothing */
        Fule_log_power_status = FUEL_LOG_SYS_SLEEP;
	}
	else
	{   
        /* Multiple fuel tank */
		 if ((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
		{
            #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
                Fuel_Multiple_Api_Main_Task(); /*Saddle type fuel tank*/
            #endif 
			
		}
		else if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_SINGLE_MAX))
		{              
            #ifdef FUEL_TANK_SINGLE_TYPE_EN
                Fuel_Single_Api_Main_Task(); /*Single tank*/
            #endif 			
		}
        else
        {  
            #ifdef FUEL_TANK_DUAL_TYPE_EN 
                Fuel_Dual_Api_Main_Task(); 
            #endif 
             
        }
#ifdef FUEL_TIME_CAL
        FUEL_Task_em_buffer[0].min_exec_time=3000;	   
        fuel_RteAdaptRunableOstmStart(0);
#endif       

		Fuel_Api_update_ipc_rte();
		Fuel_Api_can_ouput_task();
		if(FALSE != Fuel_Api_Get_Power_Mode_State())
		{	
            /*Fuel DTC code handling */
			Fuel_DiagnosticMonitorMain_100ms(Fuel_Api_tank_cfg_get(),&Fuel_EventDebounce_Main,&Fuel_EventDebounce_Aux);
		}
        else
        {
            /*Restore shake control when underpressure is restored*/
            (void)memset(&Fuel_EventDebounce_Main,0,sizeof(Fuel_EventDebounce_t));
            (void)memset(&Fuel_EventDebounce_Aux,0,sizeof(Fuel_EventDebounce_t));
        }
     
		#ifdef FUEL_TIME_CAL
	  		//  FUEL_TASK_END_CALCULATE(0) ;
	  		fuel_RteAdaptRunableOstmCheck(0);
		#endif 
		#ifdef FUEL_TC_VEHICLE_TEST
			vehicle_test();
		#endif
		//}
		Fuel_log_Task();
		
	}


}
/** 
 * [Fuel_Api_Get_Finished_Init : Key ON completion of fuel initialization process]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:50:25+0800
 * @param    void                     [description]
 * @return   boolean                  [True:complete init]
 */

boolean Fuel_Api_Get_Finished_Init(void)
{	
	boolean fuel_finished_init_temp = FALSE;

    if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
    {
     #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
         fuel_finished_init_temp = Fuel_Multiple_Init_Finished();
     #endif       
    }
    else  if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG< FUEL_VR_COMMMON_SINGLE_MAX))
    { 
    #ifdef FUEL_TANK_SINGLE_TYPE_EN     
    fuel_finished_init_temp = Fuel_Single_Api_Fuel_Sync_Reday();
    #endif 
       
    }
    else if(FUEL_TANK_CFG == FUEL_VR_HIGH_VOLT_SINGLE_NO1)
    {  
    
    }
    else
    {

    }   
	return fuel_finished_init_temp;
}
/** 
 * [Fuel_Api_Get_FastFill_Status : Fuel fast mode,eg fill or loss or fault]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:50:31+0800
 * @param    void                     [description]
 * @return   uint8                    [description]
 */

uint8 Fuel_Api_Get_FastFill_Status(void)
{
	uint8 fuel_fastfill_status_temp = 0;

    if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
    {
     #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
         fuel_fastfill_status_temp = Fuel_Multiple_Api_Get_Fast_Fill_Status();
     #endif        
    }
    else  if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_SINGLE_MAX))
    { 
     #ifdef FUEL_TANK_SINGLE_TYPE_EN        
         fuel_fastfill_status_temp = Fuel_Single_Api_Get_Fast_Fill_Status();
     #endif 
        
    }
    else if(FUEL_TANK_CFG == FUEL_VR_HIGH_VOLT_SINGLE_NO1)
    {  
    
    }
    else
    {

    }   
	return fuel_fastfill_status_temp;
}
/** 
 * [Fuel_Api_Get_VehRunning_State : speed >= 0.2km/h exit fastfill mode]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T14:26:16+0800
 * @param    void                     [description]
 * @return   uint8                    [0：SPD>0.2 ]
 */
uint8 Fuel_Api_Get_VehRunning_State (void)
{
	uint8 vehrunning_status_temp = 0;	
	vehrunning_status_temp = Fuel_Rte_Api_Get_VehRunning_State();	
	return vehrunning_status_temp;	
}
/** 
 * [Fuel_Api_Get_VehHalt_State : Check SPD<=1KM/H]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T14:31:26+0800
 * @param    void                     [description]
 * @return   uint8                    [0:SPD<=1KM/H]
 */
uint8 Fuel_Api_Get_VehHalt_State (void)
{
	uint8 vehrunning_status_temp = 0;	
	vehrunning_status_temp = Fuel_Rte_Api_Get_VehHalt_State();	
	return vehrunning_status_temp;	
}

/** 
 * [Fuel_Api_Get_EngSpd_State : Check EngSpd �?400rpm]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T14:32:11+0800
 * @param    void                     [description]
 * @return   uint8                    [1:EngSpd �?400rpm]
 */
uint8 Fuel_Api_Get_EngSpd_State (void)
{
	uint8 engine_run_status = 0;
	engine_run_status = Fuel_Rte_Api_Get_EngSpd_State();
	return engine_run_status;
}

/** 
 * [Fuel_Api_Get_Power_Mode_State : Get IGN ON Status]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T14:38:07+0800
 * @param    void                     [description]
 * @return   uint8                    [1:IGN ON ]
 */
uint8 Fuel_Api_Get_Power_Mode_State (void)
{
	uint8 fuel_power_mode;
	fuel_power_mode = Fuel_Rte_Api_Get_Power_Mode_State();
	return fuel_power_mode;
}

/** 
 * [Fuel_Api_Get_Voltage_Mode_State : Check - 6.5 V <=V batt <=19V]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T15:01:07+0800
 * @param    void                     [description]
 * @return   uint8                    [1�?.5 V <=V batt <=19V]
 */
uint8 Fuel_Api_Get_Voltage_Mode_State (void)
{
	uint8 fuel_voltage_state;
	fuel_voltage_state = Fuel_Rte_Api_Get_Voltage_Mode_State();
	return fuel_voltage_state;
}

/** 
 * [Fuel_Api_Get_Fuel_AD_Value : Obtain the AD value of two sensors,The accuracy of AD is 12 bits]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:51:24+0800
 * @param    fuel_ad_channel          [0:main sensor;1:aux sensor]
 * @return   uint16                   [Invalid :0XFFFF]
 */

uint16 Fuel_Api_Get_Fuel_AD_Value (uint8 fuel_ad_channel)
{
	uint16 fuel_ad_temp;	
	#ifdef FUEL_TIME_CAL
//	Rte_Exit_ExclusiveArea_Normal();
	#endif 
   fuel_ad_temp = Fuel_Rte_Api_Get_Fuel_AD_Value(fuel_ad_channel);
	#ifdef FUEL_TIME_CAL
  //  Rte_Enter_ExclusiveArea_Normal();
	#endif 
	return (fuel_ad_temp);
}
/** 
 * [Fuel_Api_Get_Fuel_Resisitor_Value : Obtain the Resisitor value,factot:10 eg100=10Ω ]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:51:35+0800
 * @param    fuel_ad_channel          [0:main sensor;1:aux sensor]
 * @return   uint16                   [Invalid :0XFFFF open or short]
 */

uint16 Fuel_Api_Get_Fuel_Resisitor_Value(uint8 fuel_ad_channel)
{
    
	uint16 fuel_resisitor_temp=0;
    if(fuel_ad_channel<2)
    {
        fuel_resisitor_temp = LinearInterpolateWord((void *)&Fuel_Resisitor_Table[0][0], Fuel_Api_Get_Fuel_AD_Value(fuel_ad_channel));
    }
	return (fuel_resisitor_temp);
}

uint16 Fuel_Api_Get_Fuel_Resisitor_Diag(uint8 fuel_ad_channel)
{
	uint16 fuel_resisitor_temp;
	if(fuel_ad_channel==0)
    {
    fuel_resisitor_temp=Fuel_Module_Output_Parameter.Fuel_Sensor_Raw_Value_A;
    }
    else
    {
    fuel_resisitor_temp=Fuel_Module_Output_Parameter.Fuel_Sensor_Raw_Value_B;
    }
	return (fuel_resisitor_temp);
}

/** 
 * [Fuel_Api_Get_Fuel_Tank_Aux_Cfg : Gets whether a relief tank configuration is available]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T15:51:44+0800
 * @param    void                     [description]
 * @return   boolean                  [TRUE:Enable]
 */
boolean Fuel_Api_Get_Fuel_Tank_Aux_Enable (void)
{
	boolean result=FALSE;	
    if (FALSE==Fuel_Tank_Cfg_Diag.Fuel_Vehicle_Config_ViceTank)
    {
        result=FALSE;	
    }
    else
    {
        result=TRUE;	
    }
	return (result);
}
/** 
 * [Fuel_Api_Set_Module_Data : Update fuel RTE data]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:52:12+0800
 * @param    fuel_set_module_data     [description]
 */

void Fuel_Api_Set_Module_Data(FUEL_MODULE_OUTPUT_DATA_STRUCT fuel_set_module_data)
{
	Fuel_Rte_Api_Set_Module_Data(fuel_set_module_data);
}
/** 
 * [Fuel_Api_Current_Module_Status :  For $22 -DID-FDC5 Current fuel module status]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T16:11:18+0800
 * @param    void                     [description]
 * @return   uint8                    [description]
 */
uint8 Fuel_Api_Current_Module_Status(void)
{
	uint8 fuel_module_status = 0;
    if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
    {  
    
    #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
        if(FALSE == Fuel_Api_Get_Power_Mode_State())
        {
            fuel_module_status = 0;
        }
        else if((FALSE != Fuel_Multiple_Loss_Fill_Detected()) && (FALSE == Fuel_Multiple_SenderA_Fastfill_Active()))
        {
            fuel_module_status = 1;
        }
        else if(FALSE != Fuel_Multiple_SenderA_Fastfill_Active())
        {
            fuel_module_status = 2;
        }
        else
        {
            fuel_module_status = 3;
        }    

    #endif 
        
    }
    else  if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_SINGLE_MAX))
    { 
        #ifdef FUEL_TANK_SINGLE_TYPE_EN   
        if(FALSE == Fuel_Api_Get_Power_Mode_State())
        {
        	fuel_module_status = 0;
        }
        else if((FALSE != Fuel_Single_Pkg_Fill_Loss_Detected()) && (FALSE == Fuel_Single_Pkg_Fastfill_Active()))
        {
        	fuel_module_status = 1;
        }
        else if(FALSE != Fuel_Single_Pkg_Fastfill_Active())
        {
        	fuel_module_status = 2;
        }
        else
        {
        	fuel_module_status = 3;
        }
        #endif 
       
    }
    else if(FUEL_TANK_CFG == FUEL_VR_HIGH_VOLT_SINGLE_NO1)
    {  
    
    }
    else
    {

    }   
	return fuel_module_status;
}
/** 
 * [Fuel_Api_Current_Module_Ref_Fuel_Level : For $22 -DID-FDC5 Current fuel reference value]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:52:52+0800
 * @param    void                     [description]
 * @return   uint8                    [Unit:1L]
 */

uint8 Fuel_Api_Current_Module_Ref_Fuel_Level(void)
{
	uint8 fuel_module_status = 0;
	uint32 fuel_module_calc_temp = 0;
    if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
    {         
        #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
        if(0xFFFF != Fuel_Multiple_Sender_Zss_Ref())
        {
        fuel_module_calc_temp = ((uint32)Fuel_Multiple_Sender_Zss_Ref() * Fuel_API_Muti_Get_Tank_Size())/((uint32)254*256);
        fuel_module_status = (uint8)(fuel_module_calc_temp & 0xFFu);
        }
        else if(0xFFFF != Fuel_Multiple_SenderA_Ignoff_Ref())
        {
        fuel_module_calc_temp = ((uint32)Fuel_Multiple_SenderA_Ignoff_Ref() * Fuel_API_Muti_Get_Tank_Size())/((uint32)254*256);
        fuel_module_status = (uint8)(fuel_module_calc_temp & 0xFFu);
        }
        else
        {
        fuel_module_status = 0;
        }
        #endif        
    }
    else if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_SINGLE_MAX))
    { 
    
      #ifdef FUEL_TANK_SINGLE_TYPE_EN
        if(0xFFFF != Fuel_Single_Pkg_SenderA_Zss_Ref())
        {
           fuel_module_calc_temp = ((uint32)Fuel_Single_Pkg_SenderA_Zss_Ref() * Fuel_API_Single_Get_Tank_Size())/((uint32)254*256);
           fuel_module_status = (uint8)(fuel_module_calc_temp & 0xFFu);
        }
        else if(0xFFFF != Fuel_Single_Pkg_SenderA_Ignoff_Ref())
        {
           fuel_module_calc_temp = ((uint32)Fuel_Single_Pkg_SenderA_Ignoff_Ref() * Fuel_API_Single_Get_Tank_Size())/((uint32)254*256);
           fuel_module_status = (uint8)(fuel_module_calc_temp & 0xFFu);
        }
        else
        {
           fuel_module_status = 0;
        }
       #endif      
    }        
    else if(FUEL_TANK_CFG == FUEL_VR_HIGH_VOLT_SINGLE_NO1)
    {  
    
    }
    else
    {

    }   
	return fuel_module_status;
}
/** 
 * [Fuel_Api_Module_Flps_Fuel_Level : For $22 -DID-FDC5 Current Main_fuel Real-time sampling value]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:53:06+0800
 * @param    void                     [description]
 * @return   uint8                    [Unit:1L]
 */

uint8 Fuel_Api_Module_Flps_Fuel_Level(void)
{
    uint32 fuel_flps_temp = 0;
    uint8 Fual_Tank_Value=0;
    #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
    uint8 Fual_Tank_Main_Value=0;
    #endif
    Fual_Tank_Value =Fuel_API_Single_Get_Tank_Size();  
	
   // Fual_Tank_Aux_Value = Fuel_API_Muti_Aux_Get_Tank_Size;
    if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
    {       
     #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
        Fual_Tank_Main_Value =  Fuel_API_Muti_Get_Tank_Size() - Fuel_API_Muti_Aux_Get_Tank_Size() ;
        fuel_flps_temp = Fuel_Multiple_SenderA_Unfilter_Flps();
        fuel_flps_temp = (fuel_flps_temp * (Fual_Tank_Main_Value))/((uint32)254*256);
     #endif        
    }
    else if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_SINGLE_MAX))
    { 
    #ifdef FUEL_TANK_SINGLE_TYPE_EN
        fuel_flps_temp = Fuel_Single_Pkg_SenderA_Ref_Flps();
		fuel_flps_temp = (fuel_flps_temp * Fual_Tank_Value)/((uint32)254*256);
    #endif
        
    }
    else if(FUEL_TANK_CFG == FUEL_VR_HIGH_VOLT_SINGLE_NO1)
    {  
    
    }
    else
    {

    }
	return ((uint8)fuel_flps_temp);
}
/** 
 * [Fuel_Api_Module_Flps_Aux_Fuel_Level : For $22 -DID-FDC5 Current Aux_fuel Real-time sampling value]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:53:17+0800
 * @param    void                     [description]
 * @return   uint8                    [Unit:1L]
 */
uint8 Fuel_Api_Module_Flps_Aux_Fuel_Level(void)
{
	uint32 fuel_flps_temp = 0;
    #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
    uint8 fuel_aux_volume=Fuel_API_Muti_Aux_Get_Tank_Size();
    #endif 
    if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
    {   
     #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
         fuel_flps_temp = Fuel_Multiple_SenderB_Unfilter_Flps();
         fuel_flps_temp = (fuel_flps_temp *fuel_aux_volume )/((uint32)254*256);    
     #endif       
    }
    else
    {

    }
	return ((uint8)fuel_flps_temp);
}
/** 
 * [Fuel_Api_Module_Fuel_Level_Volum_Read : For $22 -DID-FDC5 Current fuel Volum]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:53:31+0800
 * @param    void                     [description]
 * @return   uint8                    [Unit:1L]
 */
uint8 Fuel_Api_Module_Fuel_Level_Volum_Read(void)
{
	uint8 fuel_volum_temp = 0;
    if ((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
    {  
     #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
         fuel_volum_temp = (uint8)(Fuel_Multiple_Api_Get_Fuel_Volume()/1000u);
     #endif         
    }
    else if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_SINGLE_MAX))
    { 
    #ifdef FUEL_TANK_SINGLE_TYPE_EN
        fuel_volum_temp = (uint8)(Fuel_Api_Get_Fuel_Volume()/1000);//Fuel_Single_Api_FuelInfo.fuel_volume/1000;
    #endif 
        
    }
    else if(FUEL_TANK_CFG == FUEL_VR_HIGH_VOLT_SINGLE_NO1)
    {  
    
    }
    else
    {

    }
	return ((uint8)fuel_volum_temp);
}
/** 
 * [Fuel_Api_Module_Fast_Fill_Loss_Status : For $22 -DID-FDC5 Current fuel Refueling mark]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:53:48+0800
 * @param    void                     [description]
 * @return   uint8                    [0: Non-refueling mode
                                       1: refueling mode
                                       2: Oil spill mode    ]
 */
uint8 Fuel_Api_Module_Fast_Fill_Loss_Status(void)
{
	uint8 fuel_fast_fill_loss_temp = 0;

    if ((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
    {  
     #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
         fuel_fast_fill_loss_temp = Fuel_Multiple_Get_Fast_Fill_Loss_Status();    
     #endif       
    }
    else  if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_SINGLE_MAX))
    {     
   
     #ifdef FUEL_TANK_SINGLE_TYPE_EN
         fuel_fast_fill_loss_temp = Fuel_Single_Get_Fast_Fill_Loss_Status();    
     #endif 
       
    }
    else if(FUEL_TANK_CFG == FUEL_VR_HIGH_VOLT_SINGLE_NO1)
    {  
    
    }
    else
    {

    }
	return ((uint8)fuel_fast_fill_loss_temp);		
}


/** 
 * [Fuel_Api_Config_Data_NVM_Init :Fuel module Cconfig init]
 * @Author   shujunhua
 * @DateTime 2021/5/5-19:04:59
 * @param    void                     [description]
 */
void Fuel_Api_Config_Data_NVM_Init(void)
{
	CconfigKind_400Bytes Lcal_config_data;
    
	boolean Lcal_config_status = FALSE;
    
	//uint64 calc_temp;
    
    FUEL_VR_TYPE_ENUM Fuel_VHR_Enum_Cfg=FUEL_VR_COMMMON_NONE ;


    Fuel_Vhr_CFG_table_t *p  = Fuel_Single_Vhr_Display_Cfg_table;
    Fuel_Vhr_CFG_table_t *pf = Fuel_Singel_Vhr_Adc_Pf_Cfg_table;
    #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
    Fuel_Vhr_CFG_table_t *p_muti       = Fuel_Muti_Vhr_Display_Cfg_table; 
    Fuel_Muti_Vhr_CFG_table_t *pf_muti = Fuel_Muti_Vhr_Adc_Pf_Cfg_table;
    #endif
   // 

    #ifdef FUEL_TANK_DUAL_TYPE_EN
        Fuel_Duti_Vhr_CFG_table_t *pf_dual = Fuel_Dual_Vhr_Adc_Pf_Cfg_table;
        Fuel_Duti_Vhr_CFG_table_t *p_dual =  Fuel_Dual_Vhr_Display_Cfg_table;
    #endif

    Fuel_VHR_Enum_Cfg =FUEL_TANK_CFG ;

    Lcal_config_status = Fuel_Rte_Api_Get_Cconfig_Cfg(Lcal_config_data);
    Fuel_Api_Log_ColdInit_Flag = FALSE;

    if (((Fuel_VHR_Enum_Cfg <FUEL_VR_COMMMON_SINGLE_MAX)&&(p[Fuel_VHR_Enum_Cfg].table!=NULL)&&\
        (p[Fuel_VHR_Enum_Cfg].table_size< sizeof(Fuel_Single_Display_Table_CFG))))
    {

        (void) memcpy(Fuel_Single_Display_Table_CFG,p[Fuel_VHR_Enum_Cfg].table,p[Fuel_VHR_Enum_Cfg].table_size);
        Fuel_Single_Config_Tank_Size = Fuel_Single_Tank_Size_Table [Fuel_VHR_Enum_Cfg];
        Fuel_Single_Config_Tank_Dead = Fuel_Single_Tank_Dead_Table [Fuel_VHR_Enum_Cfg];

     //   (void) memcpy(Fuel_Single_Sender_A_Table_Nvm_Cfg,pf[Fuel_VHR_Enum_Cfg].table,pf[Fuel_VHR_Enum_Cfg].table_size);   

    }
    else
    {
     //TODO: ERROR FUEL TABLE NEED TO CONFIG
    }

    /* All single float tank systems*/
    if (((Fuel_VHR_Enum_Cfg <FUEL_VR_COMMMON_SINGLE_MAX)&&(pf[Fuel_VHR_Enum_Cfg].table!=NULL)&&\
        (pf[Fuel_VHR_Enum_Cfg].table_size< sizeof(Fuel_Single_Sender_A_Table_Nvm_Cfg))))
    {

      //  (void) memcpy(Fuel_Single_Display_Table_CFG,p[Fuel_VHR_Enum_Cfg].table,p[Fuel_VHR_Enum_Cfg].table_size);

        (void) memcpy(Fuel_Single_Sender_A_Table_Nvm_Cfg,pf[Fuel_VHR_Enum_Cfg].table,pf[Fuel_VHR_Enum_Cfg].table_size);   

    }
    else
    {
      //TODO: ERROR FUEL TABLE NEED TO CONFIG
    }

    /* All dual float tank systems, not dual tanks, are saddle type tanks*/
#ifdef FUEL_TANK_MULTIPLE_TYPE_EN

    if (((Fuel_VHR_Enum_Cfg <FUEL_VR_COMMMON_DUAL_MAX)&&(Fuel_VHR_Enum_Cfg >=FUEL_VR_COMMMON_DUAL_NO1)\
        &&(p_muti[ (uint8)Fuel_VHR_Enum_Cfg- (uint8)FUEL_VR_COMMMON_DUAL_NO1].table!=NULL)&&\
        (p_muti[ (uint8)Fuel_VHR_Enum_Cfg - (uint8)FUEL_VR_COMMMON_DUAL_NO1].table_size< sizeof(Fuel_Muti_Display_Table_CFG))))
       {
            Fuel_Muti_Config_Tank_Size = Fuel_Muti_Tank_Size_Table [ (uint8)Fuel_VHR_Enum_Cfg - (uint8)FUEL_VR_COMMMON_DUAL_NO1];
            Fuel_Muti_Aux_Config_Tank_Size = Fuel_Muti_Tank_Aux_Size_Table[ (uint8)Fuel_VHR_Enum_Cfg - (uint8)FUEL_VR_COMMMON_DUAL_NO1];
            Fuel_Muti_Config_Tank_Dead = Fuel_Muti_Tank_Dead_Table [ (uint8)Fuel_VHR_Enum_Cfg- (uint8)FUEL_VR_COMMMON_DUAL_NO1];
           (void) memcpy(Fuel_Muti_Display_Table_CFG,p_muti[ (uint8)Fuel_VHR_Enum_Cfg- (uint8)FUEL_VR_COMMMON_DUAL_NO1].table,p_muti[ (uint8)Fuel_VHR_Enum_Cfg - (uint8)FUEL_VR_COMMMON_DUAL_NO1].table_size); 
            
       }
       else 
       {
        //TODO: ERROR FUEL TABLE NEED TO CONFIG
       }


    
    if (((Fuel_VHR_Enum_Cfg <FUEL_VR_COMMMON_DUAL_MAX)&&(Fuel_VHR_Enum_Cfg >=FUEL_VR_COMMMON_DUAL_NO1)&&\
        (pf_muti[ (uint8)Fuel_VHR_Enum_Cfg- (uint8)FUEL_VR_COMMMON_DUAL_NO1].table_a!=NULL)&&\
        (pf_muti[ (uint8)Fuel_VHR_Enum_Cfg-  (uint8)FUEL_VR_COMMMON_DUAL_NO1].table_b!=NULL)&&\
        (pf_muti[(uint8)Fuel_VHR_Enum_Cfg-(uint8)FUEL_VR_COMMMON_DUAL_NO1].table_size_a< sizeof(Fuel_Multiple_Sender_A_Table_Nvm_Cfg))&&\
        (pf_muti[(uint8)Fuel_VHR_Enum_Cfg-(uint8)FUEL_VR_COMMMON_DUAL_NO1].table_size_b< sizeof(Fuel_Multiple_Sender_B_Table_Nvm_Cfg))))
    {
            
        (void) memcpy(Fuel_Multiple_Sender_A_Table_Nvm_Cfg,pf_muti[(uint8)Fuel_VHR_Enum_Cfg-(uint8)FUEL_VR_COMMMON_DUAL_NO1].table_a,pf_muti[(uint8)Fuel_VHR_Enum_Cfg-(uint8)FUEL_VR_COMMMON_DUAL_NO1].table_size_a);   
        (void) memcpy(Fuel_Multiple_Sender_B_Table_Nvm_Cfg,pf_muti[(uint8)Fuel_VHR_Enum_Cfg-(uint8)FUEL_VR_COMMMON_DUAL_NO1].table_b,pf_muti[(uint8)Fuel_VHR_Enum_Cfg-(uint8)FUEL_VR_COMMMON_DUAL_NO1].table_size_b);   
    }
    else 
    {
     //TODO: ERROR FUEL TABLE NEED TO CONFIG
    }
#endif 

   #ifdef FUEL_TANK_DUAL_TYPE_EN

    if (((Fuel_VHR_Enum_Cfg <FUEL_VR_COMMMON_DUAL_SINGEL_MAX)&&(Fuel_VHR_Enum_Cfg >=FUEL_VR_COMMMON_DUAL_SINGEL_N01)&&\
        (pf_dual[ (uint8)Fuel_VHR_Enum_Cfg- (uint8)FUEL_VR_COMMMON_DUAL_SINGEL_N01].table_a!=NULL)&&\
        (pf_dual[ (uint8)Fuel_VHR_Enum_Cfg-  (uint8)FUEL_VR_COMMMON_DUAL_SINGEL_N01].table_b!=NULL)&&\
        (pf_dual[(uint8)Fuel_VHR_Enum_Cfg-(uint8)FUEL_VR_COMMMON_DUAL_SINGEL_N01].table_size_a< sizeof(Fuel_Dual_Sender_A_Table_Nvm_Cfg))&&\
        (pf_dual[(uint8)Fuel_VHR_Enum_Cfg-(uint8)FUEL_VR_COMMMON_DUAL_SINGEL_N01].table_size_b< sizeof(Fuel_Dual_Sender_B_Table_Nvm_Cfg))))
    {

        Fuel_Dual_A_Config_Tank_Size =  Fuel_Dual_Tank_A_Size_Table[Fuel_VHR_Enum_Cfg - FUEL_VR_COMMMON_DUAL_SINGEL_N01];
        Fuel_Dual_B_Config_Tank_Size =  Fuel_Dual_Tank_B_Size_Table[Fuel_VHR_Enum_Cfg - FUEL_VR_COMMMON_DUAL_SINGEL_N01];
        Fuel_Dual_A_Config_Tank_Dead =  Fuel_Dual_Tank_A_Dead_Table[Fuel_VHR_Enum_Cfg - FUEL_VR_COMMMON_DUAL_SINGEL_N01];
        Fuel_Dual_B_Config_Tank_Dead =  Fuel_Dual_Tank_B_Dead_Table[Fuel_VHR_Enum_Cfg - FUEL_VR_COMMMON_DUAL_SINGEL_N01];

        (void) memcpy(Fuel_Dual_Sender_A_Table_Nvm_Cfg,pf_dual[(uint8)Fuel_VHR_Enum_Cfg-(uint8)FUEL_VR_COMMMON_DUAL_SINGEL_N01].table_a,pf_dual[(uint8)Fuel_VHR_Enum_Cfg-(uint8)FUEL_VR_COMMMON_DUAL_SINGEL_N01].table_size_a);
        (void) memcpy(Fuel_Dual_Sender_B_Table_Nvm_Cfg,pf_dual[(uint8)Fuel_VHR_Enum_Cfg-(uint8)FUEL_VR_COMMMON_DUAL_SINGEL_N01].table_b,pf_dual[(uint8)Fuel_VHR_Enum_Cfg-(uint8)FUEL_VR_COMMMON_DUAL_SINGEL_N01].table_size_b);
    }
    else
    {
     //TODO: ERROR FUEL TABLE NEED TO CONFIG
    }


    if (((Fuel_VHR_Enum_Cfg <FUEL_VR_COMMMON_DUAL_SINGEL_MAX)&&(Fuel_VHR_Enum_Cfg >=FUEL_VR_COMMMON_DUAL_SINGEL_N01)&&\
            (p_dual[ (uint8)Fuel_VHR_Enum_Cfg- (uint8)FUEL_VR_COMMMON_DUAL_SINGEL_N01].table_a!=NULL)&&\
            (p_dual[ (uint8)Fuel_VHR_Enum_Cfg-  (uint8)FUEL_VR_COMMMON_DUAL_SINGEL_N01].table_b!=NULL)&&\
            (p_dual[(uint8)Fuel_VHR_Enum_Cfg-(uint8)FUEL_VR_COMMMON_DUAL_SINGEL_N01].table_size_a< sizeof(Fuel_Dual_Display_Table_A_CFG))&&\
            (p_dual[(uint8)Fuel_VHR_Enum_Cfg-(uint8)FUEL_VR_COMMMON_DUAL_SINGEL_N01].table_size_b< sizeof(Fuel_Dual_Display_Table_B_CFG))))
    {
          
        (void) memcpy(Fuel_Dual_Display_Table_A_CFG,p_dual[(uint8)Fuel_VHR_Enum_Cfg-(uint8)FUEL_VR_COMMMON_DUAL_SINGEL_N01].table_a,p_dual[(uint8)Fuel_VHR_Enum_Cfg-(uint8)FUEL_VR_COMMMON_DUAL_SINGEL_N01].table_size_a);
        (void) memcpy(Fuel_Dual_Display_Table_B_CFG,p_dual[(uint8)Fuel_VHR_Enum_Cfg-(uint8)FUEL_VR_COMMMON_DUAL_SINGEL_N01].table_b,p_dual[(uint8)Fuel_VHR_Enum_Cfg-(uint8)FUEL_VR_COMMMON_DUAL_SINGEL_N01].table_size_b);
    }
    else
    {
     //TODO: ERROR FUEL TABLE NEED TO CONFIG
    }




 #endif



	if(FALSE != Lcal_config_status)
	{
		Fuel_Module_Cconfig_Data_Nvm.Error_Gasoline_Low_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Error_Gasoline_Low ,Lcal_config_data);//((uint16)Lcal_config_data[25] << 8) + (uint16)Lcal_config_data[24];
		Fuel_Module_Cconfig_Data_Nvm.Error_Gasoline_High_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Error_Gasoline_High ,Lcal_config_data);//((uint16)Lcal_config_data[27] << 8) + (uint16)Lcal_config_data[26];
		Fuel_Module_Cconfig_Data_Nvm.Error_Detect_Time_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Error_Detect_Time ,Lcal_config_data);//((uint16)Lcal_config_data[29] << 8) + (uint16)Lcal_config_data[28];
		Fuel_Module_Cconfig_Data_Nvm.Error_Recover_Time_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Error_Recover_Time ,Lcal_config_data);//((uint16)Lcal_config_data[31] << 8) + (uint16)Lcal_config_data[30];
		
		Fuel_Module_Cconfig_Data_Nvm.Refuel_Delaytime_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Refuel_Delaytime ,Lcal_config_data);//((uint16)Lcal_config_data[33] << 8) + (uint16)Lcal_config_data[32];
		Fuel_Module_Cconfig_Data_Nvm.Ref_Time_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Ref_Time ,Lcal_config_data);//((uint16)Lcal_config_data[35] << 8) + (uint16)Lcal_config_data[34];
		Fuel_Module_Cconfig_Data_Nvm.Refuel_Speed_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Refuel_Speed ,Lcal_config_data);//((uint16)Lcal_config_data[37] << 8) + (uint16)Lcal_config_data[36];
		Fuel_Module_Cconfig_Data_Nvm.Halt_Speed_Time_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Halt_Speed ,Lcal_config_data);//(uint16)Lcal_config_data[38];
		
		Fuel_Module_Cconfig_Data_Nvm.Damp_lowfuel_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Damp_lowfuel ,Lcal_config_data);//((uint16)Lcal_config_data[40] << 8) + (uint16)Lcal_config_data[39];
		Fuel_Module_Cconfig_Data_Nvm.Damp_run_fuelup_NvmInit = (uint16)Fuel_Api_Rte_Get_Damp_run_fuelup();//((uint16)Lcal_config_data[42] << 8) + (uint16)Lcal_config_data[41];
		Fuel_Module_Cconfig_Data_Nvm.Damp_run_fueldown_NvmInit = (uint16)Fuel_Api_Rte_Get_Damp_run_fueldown();//((uint16)Lcal_config_data[44] << 8) + (uint16)Lcal_config_data[43];
        /*
         Refuel_Conf_Time_NvmInit history ((uint16)Lcal_config_data[46] << 8) + (uint16)Lcal_config_data[45];
        20210301 for cconfig v1.5 update*/
		Fuel_Module_Cconfig_Data_Nvm.Refuel_Conf_Time_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Refuel_Conf_Time ,Lcal_config_data);//((uint16)Lcal_config_data[47] << 8) + (uint16)Lcal_config_data[46];
         /*
         RefuelDamping2_NvmInit history (uint16)Lcal_config_data[47];
        s20210301 for cconfig v1.5 update*/
		Fuel_Module_Cconfig_Data_Nvm.RefuelDamping2_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_RefuelDamping2 ,Lcal_config_data);//(uint16)Lcal_config_data[48];
        /*
         Damp_idle_NvmInit  history ((uint16)Lcal_config_data[49] << 8) + (uint16)Lcal_config_data[48]
        20210301 for cconfig v1.5 update*/ 
		Fuel_Module_Cconfig_Data_Nvm.Damp_idle_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Damp_idle ,Lcal_config_data);//((uint16)Lcal_config_data[50] << 8) + (uint16)Lcal_config_data[49];
		/*
         Low_Fuel_detect_time_NvmInit  ((uint16)Lcal_config_data[51] << 8) + (uint16)Lcal_config_data[50];
        20210304 for cconfig v1.5 update*/
		Fuel_Module_Cconfig_Data_Nvm.Low_Fuel_detect_time_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_LowFueldetecttime ,Lcal_config_data);//((uint16)Lcal_config_data[52] << 8) + (uint16)Lcal_config_data[51];
        /*
         Low_Fuel_detect_time_NvmInit  ((uint16)Lcal_config_data[53] << 8) + (uint16)Lcal_config_data[52];
        20210304 for cconfig v1.5 update*/
		Fuel_Module_Cconfig_Data_Nvm.Low_Fuel_release_time_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_LowFuelReleasetime ,Lcal_config_data);//((uint16)Lcal_config_data[54] << 8) + (uint16)Lcal_config_data[53];
        /*
         Low_Fuel_detect_time_NvmInit ((uint16)Lcal_config_data[55] << 8) + (uint16)Lcal_config_data[54];
        20210304 for cconfig v1.5 update*/
		Fuel_Module_Cconfig_Data_Nvm.IFC_Avg_Conf_Time_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_IFC_Avg_Conf_Time ,Lcal_config_data);//((uint16)Lcal_config_data[56] << 8) + (uint16)Lcal_config_data[55];

        if(FUEL_TANK_CFG == FUEL_VR_COMMMON_DUAL_NO1)/*Config3  B03 4WD*/
        { 
            /*20210304 for cconfig v1.5 update*/
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Refuel_Trigger3 ,Lcal_config_data);//((uint16)Lcal_config_data[74] << 8) + (uint16)Lcal_config_data[73];
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Exception_Volume3 ,Lcal_config_data);//((uint16)Lcal_config_data[76] << 8) + (uint16)Lcal_config_data[75];
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_LFW_Trigger3 ,Lcal_config_data);//((uint16)Lcal_config_data[78] << 8) + (uint16)Lcal_config_data[77];
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_LFW_Release3 ,Lcal_config_data);//((uint16)Lcal_config_data[80] << 8) + (uint16)Lcal_config_data[79];
        }
        else if(FUEL_TANK_CFG == FUEL_VR_COMMMON_DUAL_NO2)  /*Config5 V71 FUEL AND HEV*/
        {   
            /*20210304 for cconfig v1.5 update*/
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Refuel_Trigger5 ,Lcal_config_data);//((uint16)Lcal_config_data[20] << 8) +(uint16)Lcal_config_data[19];
            Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Exception_Volume5 ,Lcal_config_data);//((uint16)Lcal_config_data[22] << 8) + (uint16)Lcal_config_data[21];
            Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_LFW_Trigger5 ,Lcal_config_data);//((uint16)Lcal_config_data[24] << 8) + (uint16)Lcal_config_data[23];
            Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_LFW_Release5 ,Lcal_config_data);//((uint16)Lcal_config_data[26] << 8) + (uint16)Lcal_config_data[25];   
        }
        else if(FUEL_TANK_CFG == FUEL_VR_COMMMON_DUAL_NO3)  /*A08*/
        {   
            /*20210304 for cconfig v1.5 update*/
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit =30 ;
            //(uint16)Lcal_config_data[19];
            Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
            //(uint16)Lcal_config_data[21];
            Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit =90;
            //(uint16)Lcal_config_data[23];
            Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit =120;
            //(uint16)Lcal_config_data[25];   
        }
        else if(FUEL_TANK_CFG == FUEL_VR_COMMMON_DUAL_NO4)  /*D03 overseas*/
        {
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit =60;
            Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
            Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit =143;
            Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit =188;
        }
        else if(FUEL_TANK_CFG == FUEL_VR_COMMMON_SINGLE_NO1) /*Config2 V61*/
        {   
           
          
           /*20210304 for cconfig v1.5 update*/
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Refuel_Trigger2 ,Lcal_config_data);//((uint16)Lcal_config_data[66] << 8) + (uint16)Lcal_config_data[65];
            Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Exception_Volume2 ,Lcal_config_data);//((uint16)Lcal_config_data[68] << 8) + (uint16)Lcal_config_data[67];
            Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_LFW_Trigger2 ,Lcal_config_data);//((uint16)Lcal_config_data[70] << 8) + (uint16)Lcal_config_data[69];
            Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_LFW_Release2 ,Lcal_config_data);//((uint16)Lcal_config_data[72] << 8) + (uint16)Lcal_config_data[71];
        
        }
        else if(FUEL_TANK_CFG == FUEL_VR_COMMMON_SINGLE_NO2) /*Config1 V51HEV*/
        {   
        
          
         /*20210304 for cconfig v1.5 update*/
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Refuel_Trigger1 ,Lcal_config_data);//((uint16)Lcal_config_data[58] << 8) + (uint16)Lcal_config_data[57];
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Exception_Volume1 ,Lcal_config_data);//((uint16)Lcal_config_data[60] << 8) + (uint16)Lcal_config_data[59];
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit =(uint16)CConfig_GetConfig (CCONFIG_KIND_LFW_Trigger1 ,Lcal_config_data);// ((uint16)Lcal_config_data[62] << 8) + (uint16)Lcal_config_data[61];
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_LFW_Release1 ,Lcal_config_data);//((uint16)Lcal_config_data[64] << 8) + (uint16)Lcal_config_data[63];
            
        }
        else if (FUEL_TANK_CFG == FUEL_VR_COMMMON_SINGLE_NO3)
        {
           
         // TBD need to add for P03 and P05 diesel
             Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Refuel_Trigger6 ,Lcal_config_data);//((uint16)Lcal_config_data[58] << 8) + (uint16)Lcal_config_data[57];
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = (uint16)CConfig_GetConfig(CCONFIG_KIND_Exception_Volume6 ,Lcal_config_data);//((uint16)Lcal_config_data[60] << 8) + (uint16)Lcal_config_data[59];
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit =(uint16)CConfig_GetConfig (CCONFIG_KIND_LFW_Trigger6 ,Lcal_config_data);// ((uint16)Lcal_config_data[62] << 8) + \(uint16)Lcal_config_data[61];
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_LFW_Release6 ,Lcal_config_data);//((uint16)Lcal_config_data[64] << 8) + (uint16)Lcal_config_data[63];
        }
        else if (FUEL_TANK_CFG == FUEL_VR_COMMMON_SINGLE_NO4)
        {
         // TBD need to add for P03 and P05  gasoline
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Refuel_Trigger7 ,Lcal_config_data);//((uint16)Lcal_config_data[58] << 8) + (uint16)Lcal_config_data[57];
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = (uint16)CConfig_GetConfig(CCONFIG_KIND_Exception_Volume7 ,Lcal_config_data);//((uint16)Lcal_config_data[60] << 8) + (uint16)Lcal_config_data[59];
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit =(uint16)CConfig_GetConfig (CCONFIG_KIND_LFW_Trigger7 ,Lcal_config_data);// ((uint16)Lcal_config_data[62] << 8) + (uint16)Lcal_config_data[61];
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_LFW_Release7 ,Lcal_config_data);//((uint16)Lcal_config_data[64] << 8) + (uint16)Lcal_config_data[63];
        }
        else if (FUEL_TANK_CFG == FUEL_VR_COMMMON_SINGLE_NO5)
        {
         // TBD need to add for P03 and P05
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = 50;
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = 90;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = 120; 
        }
        else if (FUEL_TANK_CFG == FUEL_VR_COMMMON_SINGLE_NO7)
        {
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = 60;
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = 142;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = 172; 
        }
        else if (FUEL_TANK_CFG == FUEL_VR_COMMMON_SINGLE_NO8)
        {
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = 60;
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = 117;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = 146; 
        }
        else if (FUEL_TANK_CFG == FUEL_VR_COMMMON_SINGLE_NO9)
        {
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = 60;
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = 145;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = 172; 
        }
		 else if((Fuel_VHR_Enum_Cfg>=FUEL_VR_COMMMON_DUAL_SINGEL_N01) &&(Fuel_VHR_Enum_Cfg<FUEL_VR_COMMMON_DUAL_SINGEL_MAX))
        {
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_Dual_NvmInit[FUEL_TANK_A] = 50;
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_Dual_NvmInit[FUEL_TANK_A] = 755;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_Dual_NvmInit[FUEL_TANK_A] = 90;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_Dual_NvmInit[FUEL_TANK_A] = 120; 

            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_Dual_NvmInit[FUEL_TANK_B] = 50;
            Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_Dual_NvmInit[FUEL_TANK_B] = 755;
            Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_Dual_NvmInit[FUEL_TANK_B] = 90;
            Fuel_Module_Cconfig_Data_Nvm.LFW_Release_Dual_NvmInit[FUEL_TANK_B] = 120; 

        }
        else if(FUEL_TANK_CFG == FUEL_VR_HIGH_VOLT_SINGLE_NO1) /*Config4 V71 PHEV*/
        {   
            /*20210304 for cconfig v1.5 update*/
            
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Refuel_Trigger4 ,Lcal_config_data);//((uint16)Lcal_config_data[12] << 8) + (uint16)Lcal_config_data[11];
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = (uint16)CConfig_GetConfig(CCONFIG_KIND_Exception_Volume4 ,Lcal_config_data);//((uint16)Lcal_config_data[14] << 8) + (uint16)Lcal_config_data[13];
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_LFW_Trigger4 ,Lcal_config_data);// ((uint16)Lcal_config_data[16] << 8) + (uint16)Lcal_config_data[15];
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_LFW_Release4 ,Lcal_config_data);//((uint16)Lcal_config_data[18] << 8) + (uint16)Lcal_config_data[17];
        }
        else
        {
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_Refuel_Trigger2 ,Lcal_config_data);//((uint16)Lcal_config_data[65] << 8) + (uint16)Lcal_config_data[64];
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = (uint16)CConfig_GetConfig(CCONFIG_KIND_Exception_Volume2 ,Lcal_config_data);//((uint16)Lcal_config_data[67] << 8) + (uint16)Lcal_config_data[66];
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_LFW_Trigger2 ,Lcal_config_data);//((uint16)Lcal_config_data[69] << 8) + (uint16)Lcal_config_data[68];
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = (uint16)CConfig_GetConfig (CCONFIG_KIND_LFW_Release2 ,Lcal_config_data);//((uint16)Lcal_config_data[71] << 8) + (uint16)Lcal_config_data[70];
    
        }
	}
	else
	{
		Fuel_Module_Cconfig_Data_Nvm.Error_Gasoline_Low_NvmInit = 10;
		Fuel_Module_Cconfig_Data_Nvm.Error_Gasoline_High_NvmInit = 1000;
		Fuel_Module_Cconfig_Data_Nvm.Error_Detect_Time_NvmInit = 100;
		Fuel_Module_Cconfig_Data_Nvm.Error_Recover_Time_NvmInit = 100;
		
		Fuel_Module_Cconfig_Data_Nvm.Refuel_Delaytime_NvmInit = 20;
		Fuel_Module_Cconfig_Data_Nvm.Ref_Time_NvmInit = 60;
		Fuel_Module_Cconfig_Data_Nvm.Refuel_Speed_NvmInit = 2;
		Fuel_Module_Cconfig_Data_Nvm.Halt_Speed_Time_NvmInit = 0;
		
		Fuel_Module_Cconfig_Data_Nvm.Damp_lowfuel_NvmInit = 400;
		Fuel_Module_Cconfig_Data_Nvm.Damp_run_fuelup_NvmInit = Fuel_Api_Rte_Get_Damp_run_fuelup();
		Fuel_Module_Cconfig_Data_Nvm.Damp_run_fueldown_NvmInit = Fuel_Api_Rte_Get_Damp_run_fueldown();
		Fuel_Module_Cconfig_Data_Nvm.Refuel_Conf_Time_NvmInit = 30;		
		Fuel_Module_Cconfig_Data_Nvm.RefuelDamping2_NvmInit = 50;
		Fuel_Module_Cconfig_Data_Nvm.Damp_idle_NvmInit = 25;
		
		Fuel_Module_Cconfig_Data_Nvm.Low_Fuel_detect_time_NvmInit = 200;
		Fuel_Module_Cconfig_Data_Nvm.Low_Fuel_release_time_NvmInit = 200;
		Fuel_Module_Cconfig_Data_Nvm.IFC_Avg_Conf_Time_NvmInit = 100;
        if(FUEL_TANK_CFG == FUEL_VR_COMMMON_DUAL_NO1) /*Config3  B03 4WD*/
        { 
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = 50;
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = 100;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = 130;
        }
        else if(FUEL_TANK_CFG == FUEL_VR_COMMMON_DUAL_NO2)  /*Config5 V71 FUEL AND HEV*/
        { 
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = 50;
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = 100;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = 130;   
        }
        else if(FUEL_TANK_CFG == FUEL_VR_COMMMON_DUAL_NO3)  /*A08*/
        {   
            /*20210304 for cconfig v1.5 update*/
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit =30 ;
            //(uint16)Lcal_config_data[19];
            Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
            //(uint16)Lcal_config_data[21];
            Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit =90;
            //(uint16)Lcal_config_data[23];
            Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit =120;
            //(uint16)Lcal_config_data[25];   
        }
        else if(FUEL_TANK_CFG == FUEL_VR_COMMMON_DUAL_NO4)  /*D03 overseas*/
        {
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit =60;
            Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
            Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit =143;
            Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit =188;
        }
        else if(FUEL_TANK_CFG == FUEL_VR_COMMMON_SINGLE_NO1) /*Config2 V61*/
        {   
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = 50;
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = 100;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = 130;
        }
        else if(FUEL_TANK_CFG == FUEL_VR_COMMMON_SINGLE_NO2)  /*Config1 V51HEV*/
        {   
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = 50;
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = 90;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = 120;    
        }
        else if (FUEL_TANK_CFG == FUEL_VR_COMMMON_SINGLE_NO3)
        {
         // TBD need to add for P03 and P05
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = 50;
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = 110;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = 160; 
        }
        else if (FUEL_TANK_CFG == FUEL_VR_COMMMON_SINGLE_NO4)
        {
         // TBD need to add for P03 and P05
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = 50;
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = 140;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = 170; 
        }
        else if (FUEL_TANK_CFG == FUEL_VR_COMMMON_SINGLE_NO5)
        {
           // A07
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = 50;
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = 90;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = 120; 
        }
        else if (FUEL_TANK_CFG == FUEL_VR_COMMMON_SINGLE_NO7)
        {
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = 60;
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = 142;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = 172; 
        }
        else if (FUEL_TANK_CFG == FUEL_VR_COMMMON_SINGLE_NO8)
        {
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = 60;
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = 117;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = 146; 
        }
        else if (FUEL_TANK_CFG == FUEL_VR_COMMMON_SINGLE_NO9)
        {
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = 60;
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = 145;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = 172; 
        }
		 else if((Fuel_VHR_Enum_Cfg>=FUEL_VR_COMMMON_DUAL_SINGEL_N01) &&(Fuel_VHR_Enum_Cfg<FUEL_VR_COMMMON_DUAL_SINGEL_MAX))
        {
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_Dual_NvmInit[FUEL_TANK_A] = 50;
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_Dual_NvmInit[FUEL_TANK_A] = 755;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_Dual_NvmInit[FUEL_TANK_A] = 90;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_Dual_NvmInit[FUEL_TANK_A] = 120; 

            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_Dual_NvmInit[FUEL_TANK_B] = 50;
            Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_Dual_NvmInit[FUEL_TANK_B] = 755;
            Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_Dual_NvmInit[FUEL_TANK_B] = 90;
            Fuel_Module_Cconfig_Data_Nvm.LFW_Release_Dual_NvmInit[FUEL_TANK_B] = 120; 

        }
        else if(FUEL_TANK_CFG == FUEL_VR_HIGH_VOLT_SINGLE_NO1) /*Config4 V71 PHEV*/
        {   
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = 50;
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = 100;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = 130;
        }
        else
        {
            Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit = 50;
			Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit = 755;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit = 100;
			Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit = 130; 
        }
	}
    Fuel_Api_Log_ColdInit_Flag = TRUE ;
}

/** 
 * [Fuel_Api_Config_Data_NVM_Pkg_Get_Data : Fuel module Cconfig init for Key policy parameters]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T17:04:48+0800
 * @param    data_index               [See the configuration table for details]
 * @return   uint32                   [description]
 */



uint32 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(uint8 data_index)
{
	uint32 data_config_temp = 0u;
    uint16 u16exception_Volume_NvmInit = 400u;

	if(0u == data_index)
	{
		/* Error_Gasoline_Low_NvmInit */
		data_config_temp = (uint32)Fuel_Module_Cconfig_Data_Nvm.Error_Gasoline_Low_NvmInit * 10;
	}
	else if(1u == data_index)
	{
		/* Error_Gasoline_High_NvmInit */
		data_config_temp = (uint32)Fuel_Module_Cconfig_Data_Nvm.Error_Gasoline_High_NvmInit * 10;
	}
	else if(2u == data_index)
	{
		/* Error_Detect_Time_NvmInit */
		data_config_temp = (uint32)Fuel_Module_Cconfig_Data_Nvm.Error_Detect_Time_NvmInit;
	}
	else if(3u == data_index)
	{
		/* Error_Recover_Time_NvmInit */
		data_config_temp = (uint32)Fuel_Module_Cconfig_Data_Nvm.Error_Recover_Time_NvmInit;
	}
	else if(4u == data_index)
	{
		/* Refuel_Delaytime_NvmInit */
		data_config_temp = (uint32)Fuel_Module_Cconfig_Data_Nvm.Refuel_Delaytime_NvmInit;
	}
	else if(5u == data_index)
	{
		/* Ref_Time_NvmInit */
	 	/* not used because need complex calculate strategy */
		data_config_temp = (uint32)Fuel_Module_Cconfig_Data_Nvm.Ref_Time_NvmInit;
	}
	else if(6u == data_index)
	{
		/* Refuel_Speed_NvmInit */
		data_config_temp = (uint32)Fuel_Module_Cconfig_Data_Nvm.Refuel_Speed_NvmInit;
	}
	else if(7u == data_index)
	{
		/* Halt_Speed_Time_NvmInit */
		/* not used because used Refuel_Speed_NvmInit condition */
		data_config_temp = (uint32)Fuel_Module_Cconfig_Data_Nvm.Halt_Speed_Time_NvmInit;
	}
	else if(8u == data_index)
	{
		/* Damp_lowfuel_NvmInit */
		/* Tank: 61L  10000: 1/0.0001L/2S  20: 2S=20 *100ms   total:254*2^24 */
        if((Fuel_Module_Cconfig_Data_Nvm.Damp_lowfuel_NvmInit!=0u)&&(Fuel_API_Single_Get_Tank_Size()!=0u))
        {
		    data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)10000 * 2 * 10 *Fuel_API_Single_Get_Tank_Size())/(uint64)Fuel_Module_Cconfig_Data_Nvm.Damp_lowfuel_NvmInit));
        }
        else
        {
         // Need to print ERR 
        }
	}
	else if(9u == data_index)
	{
		/* Damp_run_fuelup_NvmInit */
		/* Tank: 61L  10000: 1/0.0001L/2S  20: 2S=20 *100ms   total:254*2^24 */
        if((Fuel_API_Single_Get_Tank_Size()!=0u)&&(Fuel_Module_Cconfig_Data_Nvm.Damp_run_fuelup_NvmInit!=0u))
        {
		    data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)10000 * 2 * 10 *Fuel_API_Single_Get_Tank_Size())/(uint64)Fuel_Module_Cconfig_Data_Nvm.Damp_run_fuelup_NvmInit));
        }
	}
	else if(10u == data_index)
	{
		/* Damp_run_fueldown_NvmInit */
		/* Tank: 61L  10000: 1/0.0001L/2S  20: 2S=20 *100ms   total:254*2^24 */
        if((Fuel_API_Single_Get_Tank_Size()!=0u)&&(Fuel_Module_Cconfig_Data_Nvm.Damp_run_fueldown_NvmInit!=0))
        {
		    data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)10000 * 2 * 10 *Fuel_API_Single_Get_Tank_Size())/(uint64)Fuel_Module_Cconfig_Data_Nvm.Damp_run_fueldown_NvmInit));
        }
        else
        {

        }
	}
	else if(11u == data_index)
	{
		/* Refuel_Conf_Time_NvmInit */
		data_config_temp = (uint32)Fuel_Module_Cconfig_Data_Nvm.Refuel_Conf_Time_NvmInit;
	}
	else if(12u == data_index)
	{
		/* RefuelDamping2_NvmInit */
        if((Fuel_Module_Cconfig_Data_Nvm.RefuelDamping2_NvmInit !=0u)&&(Fuel_API_Single_Get_Tank_Size()!=0u))
        {
		    data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)Fuel_Module_Cconfig_Data_Nvm.RefuelDamping2_NvmInit * 10 *Fuel_API_Single_Get_Tank_Size())/(uint64)100));
        }
	}
	else if(13u == data_index)
	{
		/* Damp_idle_NvmInit */
        if ((Fuel_API_Single_Get_Tank_Size()!=0u)&&(Fuel_Module_Cconfig_Data_Nvm.Damp_idle_NvmInit!=0u))
		{
		data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)10000 * 2 * 10 *Fuel_API_Single_Get_Tank_Size())/(uint64)Fuel_Module_Cconfig_Data_Nvm.Damp_idle_NvmInit));
        }
        else 
        {
        // ERROR 
        }
    }
	else if(14u == data_index)
	{
		/* Low_Fuel_detect_time_NvmInit */
		data_config_temp = (uint32)Fuel_Module_Cconfig_Data_Nvm.Low_Fuel_detect_time_NvmInit;
	}
	else if(15u == data_index)
	{
		/* Low_Fuel_release_time_NvmInit */
		data_config_temp = (uint32)Fuel_Module_Cconfig_Data_Nvm.Low_Fuel_release_time_NvmInit;
	}	
	else if(16u == data_index)
	{
		/* IFC_Avg_Conf_Time_NvmInit */
		/* not used because this data in TC module */
		data_config_temp = (uint32)Fuel_Module_Cconfig_Data_Nvm.IFC_Avg_Conf_Time_NvmInit;
	}
	else if(17u == data_index)
	{
		/* Refuel_Trigger_NvmInit */
        if(Fuel_API_Single_Get_Tank_Size()!=0u)
        {
		    data_config_temp = (uint32)(((uint64)Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit * 254 * 256)/((uint64)Fuel_API_Single_Get_Tank_Size() * 10));

        }
	}
	else if(18u == data_index)
	{
		/* Exception_Volume_NvmInit */
        if(Fuel_API_Single_Get_Tank_Size()!=0u)
        {
            data_config_temp = (uint32)(((uint64)Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit * 254 * 256)/((uint64)Fuel_API_Single_Get_Tank_Size() * 10));
            if(data_config_temp>=65024uL)
            {
                data_config_temp=65024uL;
            }
        }
	}
	else if(19u == data_index)
	{
		/* LFW_Trigger_NvmInit */
		data_config_temp = (uint32)Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit * 100;
	}
	else if(20u == data_index)
	{
		/* LFW_Release_NvmInit */
		data_config_temp = (uint32)Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit * 100;
	}
    else if (21u == data_index)
    {
    /*for main fuel */
           // data_config_temp = (uint32)( ((uint64)254 * ((uint64)1 << 24))/ (((uint64)Fuel_Module_Cconfig_Data_Nvm.RefuelDamping2_NvmInit * 10 *37)/(uint64)100));
       // 0.5s/1L  

        if( (Fuel_Module_Cconfig_Data_Nvm.RefuelDamping2_NvmInit !=0u)&&(Fuel_API_Muti_Get_Tank_Size()!=0u))
        {
            data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)Fuel_Module_Cconfig_Data_Nvm.RefuelDamping2_NvmInit * 10 *Fuel_API_Muti_Get_Tank_Size())/(uint64)100));
        }
    }
    else if (22u == data_index)
    {
     /*for aux fuel */
        if( (Fuel_Module_Cconfig_Data_Nvm.RefuelDamping2_NvmInit !=0u)&&(Fuel_API_Muti_Get_Tank_Size()!=0u))
         {
             data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)Fuel_Module_Cconfig_Data_Nvm.RefuelDamping2_NvmInit * 10 *Fuel_API_Muti_Get_Tank_Size())/(uint64)100));
         }
    }
    else if(23u == data_index)
	{
		/* Damp_lowfuel_NvmInit */
		/* Tank: 61L  10000: 1/0.0001L/2S  20: 2S=20 *100ms   total:254*2^24 */
        if( (Fuel_Module_Cconfig_Data_Nvm.Damp_lowfuel_NvmInit !=0u)&&(Fuel_API_Muti_Get_Tank_Size()!=0u))
        {
            data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)10000 * 2 * 10 *Fuel_API_Muti_Get_Tank_Size())/(uint64)Fuel_Module_Cconfig_Data_Nvm.Damp_lowfuel_NvmInit));
        }
	}
	else if(24u== data_index)
	{
		/* Damp_run_fuelup_NvmInit */
		/* Tank: 61L  10000: 1/0.0001L/2S  20: 2S=20 *100ms   total:254*2^24 */
        if( (Fuel_Module_Cconfig_Data_Nvm.Damp_run_fuelup_NvmInit !=0u)&&(Fuel_API_Muti_Get_Tank_Size()!=0u))
        {
		    data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)10000 * 2 * 10 *Fuel_API_Muti_Get_Tank_Size())/(uint64)Fuel_Module_Cconfig_Data_Nvm.Damp_run_fuelup_NvmInit));
        }
	}
	else if(25u == data_index)
	{
		/* Damp_run_fueldown_NvmInit */
		/* Tank: 61L  10000: 1/0.0001L/2S  20: 2S=20 *100ms   total:254*2^24 */
        if( (Fuel_Module_Cconfig_Data_Nvm.Damp_run_fueldown_NvmInit !=0u)&&(Fuel_API_Muti_Get_Tank_Size()!=0u))
        {
		    data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)10000 * 2 * 10 *Fuel_API_Muti_Get_Tank_Size())/(uint64)Fuel_Module_Cconfig_Data_Nvm.Damp_run_fueldown_NvmInit));
        }
    }
    else if(26u == data_index)
	{
		/* Damp_idle_NvmInit */
        if( (Fuel_Module_Cconfig_Data_Nvm.Damp_idle_NvmInit !=0u)&&(Fuel_API_Muti_Get_Tank_Size()!=0u))
        {
            data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)10000 * 2 * 10 *Fuel_API_Muti_Get_Tank_Size())/(uint64)Fuel_Module_Cconfig_Data_Nvm.Damp_idle_NvmInit));
        }
	}
     /*for muti fuel*/
    else if(27u == data_index)
	{
		/* Refuel_Trigger_NvmInit */
        if(Fuel_API_Muti_Get_Tank_Size()!=0u)
        {
            data_config_temp = (uint32)(((uint64)Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit * 254 * 256)/((uint64)Fuel_API_Muti_Get_Tank_Size() * 10));
        }
	}
    /*for muti fuel*/
	else if(28u == data_index)
	{
		/* Exception_Volume_NvmInit */
        if(Fuel_API_Muti_Get_Tank_Size()!=0u)
        {
		    data_config_temp = (uint32)(((uint64)Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit * 254 * 256)/((uint64)Fuel_API_Muti_Get_Tank_Size() * 10));
             if(data_config_temp>=65024uL)
            {
                data_config_temp=65024uL;
            }
        }
	}
    /*for single fuel*/
    else if(29u == data_index)
	{
		/* Exception_Volume_NvmInit */
        u16exception_Volume_NvmInit = 400u;
		if(Fuel_API_Single_Get_Tank_Size()!=0u)
        {
            data_config_temp = (uint32)(((uint64)u16exception_Volume_NvmInit * 254 * 256)/((uint64)Fuel_API_Single_Get_Tank_Size() * 10));
            if(data_config_temp>=65024uL)
            {
                data_config_temp=65024uL;
            }
        }
	}
    /*for muti fuel*/
    else if(30u == data_index)
	{
		/* Exception_Volume_NvmInit */
        u16exception_Volume_NvmInit = 400u;
        if(Fuel_API_Muti_Get_Tank_Size()!=0u)
        {
            data_config_temp = (uint32)(((uint64)u16exception_Volume_NvmInit * 254 * 256)/((uint64)Fuel_API_Muti_Get_Tank_Size() * 10));
            if(data_config_temp>=65024uL)
            {
                data_config_temp=65024uL;
            }
        }
	}
	else
	{
		/* Error index */
	}
	return data_config_temp;
}



/** 
 * [Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual : description]
 * @Author   shujunhua
 * @DateTime 2021/10/8-14:45:55
 * @param    data_index               [description]
 * @return   uint32                   [description]         
 */

uint32 Fuel_Api_Config_Data_NVM_Pkg_Get_Data_Dual(Fuel_TANK_C_CONFIG_ENUM data_index)
{  
    uint32 data_config_temp=0;
    

    switch (data_index) 
    {    
        
        case Fuel_Lfw_Trigger_a   : 
             data_config_temp = (uint32)Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_Dual_NvmInit[FUEL_TANK_A] * 100; break;
        case Fuel_Lfw_Release_a  : 
             data_config_temp = (uint32)Fuel_Module_Cconfig_Data_Nvm.LFW_Release_Dual_NvmInit[FUEL_TANK_A] * 100; break;
        case Fuel_Lfw_Trigger_b   : 
		     data_config_temp = (uint32)Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_Dual_NvmInit[FUEL_TANK_B] * 100; break;
        case Fuel_Lfw_Release_b  : 
             data_config_temp = (uint32)Fuel_Module_Cconfig_Data_Nvm.LFW_Release_Dual_NvmInit[FUEL_TANK_B] * 100; break;     
        case Fuel_Error_Gasoline_Low   : 
            data_config_temp =0; break;
        case Fuel_Error_Gasoline_High  : 
            data_config_temp =0; break;
        case Fuel_Error_Detect_Time    : 
            data_config_temp =0; break;
        case Fuel_Error_Recover_Time   : 
            data_config_temp =0; break;
        case Fuel_Refuel_Delaytime     : 
            data_config_temp =0; break;
        case Fuel_Ref_Time             : 
            data_config_temp =0; break;
        case Fuel_Refuel_Speed         : 
            data_config_temp =0; break;
        case Fuel_Halt_Speed           : 
            data_config_temp =0; break;
        case Fuel_Damp_lowfuel_a       : 
            if((Fuel_Module_Cconfig_Data_Nvm.Damp_lowfuel_NvmInit!=0)&&(Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_A)!=0))
            {
    		    data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)10000 * 2 * 10 *Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_A))/(uint64)Fuel_Module_Cconfig_Data_Nvm.Damp_lowfuel_NvmInit));
            }
            break;
        case Fuel_Damp_lowfuel_b       : 
            if((Fuel_Module_Cconfig_Data_Nvm.Damp_lowfuel_NvmInit!=0)&&(Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_B)!=0))
            {
    		    data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)10000 * 2 * 10 *Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_B))/(uint64)Fuel_Module_Cconfig_Data_Nvm.Damp_lowfuel_NvmInit));
            }
            break; 
        case Fuel_Damp_run_fuelup_a    : 
            if((Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_A)!=0)&&(Fuel_Module_Cconfig_Data_Nvm.Damp_run_fuelup_NvmInit!=0))
            {
                data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)10000 * 2 * 10 *Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_A))/(uint64)Fuel_Module_Cconfig_Data_Nvm.Damp_run_fuelup_NvmInit));
            }
            break;
        case Fuel_Damp_run_fueldown_a  : 
            if((Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_A)!=0)&&(Fuel_Module_Cconfig_Data_Nvm.Damp_run_fuelup_NvmInit!=0))
            {
                data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)10000 * 2 * 10 *Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_A))/(uint64)Fuel_Module_Cconfig_Data_Nvm.Damp_run_fueldown_NvmInit));
            }
            break;
        case Fuel_Damp_run_fuelup_b    : 
            if((Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_B)!=0)&&(Fuel_Module_Cconfig_Data_Nvm.Damp_run_fuelup_NvmInit!=0))
            {
                data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)10000 * 2 * 10 *Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_B))/(uint64)Fuel_Module_Cconfig_Data_Nvm.Damp_run_fuelup_NvmInit));
            }
            break;
        case Fuel_Damp_run_fueldown_b  : 
            if((Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_B)!=0)&&(Fuel_Module_Cconfig_Data_Nvm.Damp_run_fuelup_NvmInit!=0))
            {
                data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)10000 * 2 * 10 *Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_B))/(uint64)Fuel_Module_Cconfig_Data_Nvm.Damp_run_fueldown_NvmInit));
            }
            break;
        case Fuel_Fuel_Distime         : 
            data_config_temp =0; break;
        case Fuel_Refuel_Conf_Time     : 
            data_config_temp =0; break;
        case Fuel_RefuelDamping2_a       : 
               /* Dual sys A-RefuelDamping2_NvmInit: Very low damping for on-gear refueling */
            if((Fuel_Module_Cconfig_Data_Nvm.RefuelDamping2_NvmInit !=0)&&(Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_A)!=0))
            {
    		    data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)Fuel_Module_Cconfig_Data_Nvm.RefuelDamping2_NvmInit * 10 *Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_A))/(uint64)100));
            }
            break;
        case Fuel_RefuelDamping2_b       : 
               /* Dual sys A-RefuelDamping2_NvmInit: Very low damping for on-gear refueling */
            if((Fuel_Module_Cconfig_Data_Nvm.RefuelDamping2_NvmInit !=0)&&(Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_B)!=0))
            {
    		    data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)Fuel_Module_Cconfig_Data_Nvm.RefuelDamping2_NvmInit * 10 *Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_B))/(uint64)100));
            }
            break;    
        case Fuel_Damp_idle_a            : 
            if ((Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_A)!=0)&&(Fuel_Module_Cconfig_Data_Nvm.Damp_idle_NvmInit!=0))
    		{
    		    data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)10000 * 2 * 10 *Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_A))/(uint64)Fuel_Module_Cconfig_Data_Nvm.Damp_idle_NvmInit));
            } 
            break;
        case Fuel_Damp_idle_b            : 
            if ((Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_B)!=0)&&(Fuel_Module_Cconfig_Data_Nvm.Damp_idle_NvmInit!=0))
    		{
    		    data_config_temp = (uint32)(((uint64)254 * ((uint64)1 << 24))/(((uint64)10000 * 2 * 10 *Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_B))/(uint64)Fuel_Module_Cconfig_Data_Nvm.Damp_idle_NvmInit));
            } 
            break;
        case Fuel_Low_Fueldetecttime :
            data_config_temp =0; break;
        case Fuel_LowFuelReleasetime: 
            data_config_temp =0; break;
        case Fuel_IFC_Avg_Conf_Time   :
            data_config_temp =0; break;
        case Fuel_Refuel_Trigger_a  :
            /* Refuel_Trigger_NvmInit */
            if(Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_A)!=0)
            {
    		    data_config_temp = (uint32)(((uint64)Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_Dual_NvmInit[FUEL_TANK_A] * 254 * 256)/((uint64)Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_A)* 10));

            }
            break;
        case Fuel_Refuel_Trigger_b  :
            if(Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_B)!=0)
            {
    		    data_config_temp = (uint32)(((uint64)Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_Dual_NvmInit[FUEL_TANK_B] * 254 * 256)/((uint64)Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_B)* 10));
            }
            break;
        case Fuel_Exception_Volume_a  :
            /* Refuel_Trigger_NvmInit */
            if(Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_A)!=0)
            {
                 data_config_temp = (uint32)(((uint64)Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_Dual_NvmInit[FUEL_TANK_A] * 254 * 256)/((uint64)Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_A) * 10));
            }
            break;
        case Fuel_Exception_Volume_b  :
             if(Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_B)!=0)
            {
                data_config_temp = (uint32)(((uint64)Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_Dual_NvmInit[FUEL_TANK_B] * 254 * 256)/((uint64)Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_B) * 10));
            }
            break;
        default: data_config_temp =0;break;

    }

    return data_config_temp;




}

/** 
 * [Fuel_api_u16_memset : Refactoring the memset function to implement 16-bit memory assignment]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:59:06+0800
 * @param    s                        [The object to which a pointer or array is assigned]
 * @param    c                        [The value that we're going to assign]
 * @param    count                    [The byte length of the assignment object]
 */
void *Fuel_api_u16_memset(void *s, uint16 c, uint32 count)
{
    uint16 *xs = (uint16 *)s;
    while (count--)
    {
        *xs = c;
        xs++;
    }
    return s;
}
/** 
 * [Fuel_API_Get_Lfw_Percent : Calculate the percentage of trigger and Release points for each type of tank,eg 100=10%]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:59:14+0800
 * @param    void                     [description]
 */
Fuel_Lfw_t  Fuel_API_Get_Lfw_Percent(void)
{   
    uint32 temp=0;
    Fuel_Lfw_t  LFW_temp={{0},{0}};
    uint8 Fual_Tank_Value=0;
    #ifdef FUEL_TANK_DUAL_TYPE_EN
    uint8 fuel_tank_vr_cfg= Fuel_Dual_Api_Get_Tank_Config();
    #endif
#ifdef FUEL_TANK_MULTIPLE_TYPE_EN
    uint8 Fual_Muti_Tank_Value= Fuel_API_Muti_Get_Tank_Size();
    if ((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
    {

        temp=FUEL_MULTIPLE_LFW_Trigger ;
        temp *=256*254;
        temp/=Fual_Muti_Tank_Value*1000;
        LFW_temp.Fuel_lfw_trigger_pecent [FUEL_TANK_A]= LinearInterpolateWord((uint16*)&Fuel_Muti_Display_Table_CFG[0][0],(uint16)temp);

        temp=FUEL_MULTIPLE_LFW_Release ;
        temp *=256*254;
        temp/=Fual_Muti_Tank_Value*1000;
        LFW_temp.Fuel_lfw_release_pecent [FUEL_TANK_A]= LinearInterpolateWord((uint16*)&Fuel_Muti_Display_Table_CFG[0][0],(uint16)temp);

    }
#endif 

#ifdef FUEL_TANK_SINGLE_TYPE_EN
   Fual_Tank_Value=Fuel_API_Single_Get_Tank_Size();  

    if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG <FUEL_VR_COMMMON_SINGLE_MAX))
    {         

        temp=FUEL_SINGLE_LFW_Trigger ;
        temp *=256*254;
        if(Fual_Tank_Value!=0)
        {
            temp/=Fual_Tank_Value*1000;
            LFW_temp.Fuel_lfw_trigger_pecent [FUEL_TANK_A] = LinearInterpolateWord((uint16*)&Fuel_Single_Display_Table_CFG[0][0],(uint16)temp);
        }

        temp=FUEL_SINGLE_LFW_Release ;
        temp *=256*254;
        if(Fual_Tank_Value!=0) 
        {
            temp/=Fual_Tank_Value*1000;
            LFW_temp.Fuel_lfw_release_pecent [FUEL_TANK_A] = LinearInterpolateWord((uint16*)&Fuel_Single_Display_Table_CFG[0][0],(uint16)temp);
        }

    }
 #endif      


 #ifdef FUEL_TANK_DUAL_TYPE_EN
   
    if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_DUAL_SINGEL_N01)&&(FUEL_TANK_CFG <FUEL_VR_COMMMON_DUAL_SINGEL_MAX))
    {   
            
        Fual_Tank_Value = Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_A);
        temp=FUEL_DUAL_A_LFW_Trigger ;
        temp *=256*254;
        temp/=Fual_Tank_Value*1000;
        LFW_temp.Fuel_lfw_trigger_pecent [FUEL_TANK_A] = LinearInterpolateWord((void *)&Fuel_Dual_Display_Table_A_CFG[0][0],(uint16)temp);

        temp=FUEL_DUAL_A_LFW_Release ;
        temp *=256*254;
        temp/=Fual_Tank_Value*1000;
        LFW_temp.Fuel_lfw_release_pecent  [FUEL_TANK_A]= LinearInterpolateWord((void *)&Fuel_Dual_Display_Table_A_CFG[0][0],(uint16)temp);


        Fual_Tank_Value = Fuel_Api_Dual_Get_Tank_Size(FUEL_TANK_B);
        temp=FUEL_DUAL_B_LFW_Trigger ;
        temp *=256*254;
        temp/=Fual_Tank_Value*1000;
        LFW_temp.Fuel_lfw_trigger_pecent [FUEL_TANK_B] = LinearInterpolateWord((void *)&Fuel_Dual_Display_Table_B_CFG[0][0],(uint16)temp);

        temp=FUEL_DUAL_B_LFW_Release ;
        temp *=256*254;
        temp/=Fual_Tank_Value*1000;
        LFW_temp.Fuel_lfw_release_pecent  [FUEL_TANK_B]= LinearInterpolateWord((void *)&Fuel_Dual_Display_Table_B_CFG[0][0],(uint16)temp);
    }
 #endif      
    return  LFW_temp;
  
}
/** 
 * [Fuel_API_Get_Lfw_Percent_Trigger : Calculate the percentage of trigger points for each type of tank,eg 100=10%]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:47:49+0800
 * @param    void                     [description]
 * @return   uint16                   [description]
 */
/** 
 * [Fuel_API_Get_Lfw_Percent_Trigger : description]
 * @Author   shujunhua
 * @DateTime 2021/9/27-16:38:25
 * @param    index                    [description]
 * @return   uint16                   [description]
 */
uint16 Fuel_API_Get_Lfw_Percent_Trigger(uint8 index)
{ 
  uint16 fuel=0;
  if(index<FUEL_TANK_SUM)
  {
      fuel =  Fuel_Lfw_pecent.Fuel_lfw_trigger_pecent[index];
  }
  else
  {
  }
  return fuel;
}

/** 
 * [Fuel_API_Single_Get_Lfw_Percent_Trigger : description]
 * @Author   shujunhua
 * @DateTime 2021/9/29-11:27:03
 * @param    void                     [description]
 * @return   uint16                   [description]
 */
uint16 Fuel_API_Single_Get_Lfw_Percent_Trigger(void)
{
    uint16 Trigger=0;

    Trigger =  Fuel_API_Get_Lfw_Percent_Trigger (FUEL_TANK_A);
    return Trigger;
}

/** 
 * [Fuel_API_Muti_Get_Lfw_Percent_Trigger : description]
 * @Author   shujunhua
 * @DateTime 2021/9/29-11:27:08
 * @param    void                     [description]
 * @return   uint16                   [description]
 */
uint16 Fuel_API_Muti_Get_Lfw_Percent_Trigger(void)
{
    uint16 Trigger=0;

    Trigger =  Fuel_API_Get_Lfw_Percent_Trigger (FUEL_TANK_A);
    return Trigger;
}


/** 
 * [Fuel_API_Get_Lfw_Percent_Release :Calculate the percentage of Release points for each type of tank,eg 100=10%]
 * @Author   shujunhua
 * @DateTime 2021/5/4-T16:34:21+0800
 * @param    void                     [description]
 * @return   uint16                   [description]
 */
/** 
 * [Fuel_API_Get_Lfw_Percent_Release : description]
 * @Author   shujunhua
 * @DateTime 2021/9/27-16:44:57
 * @param    index                    [description]
 * @return   uint16                   [description]
 */
uint16 Fuel_API_Get_Lfw_Percent_Release(uint8 index)
{
  uint16 fuel=0;
  if(index<FUEL_TANK_SUM)
  {
      fuel =  Fuel_Lfw_pecent.Fuel_lfw_release_pecent[index];
  }
  else
  {
  }
  return fuel;
}
/** 
 * [Fuel_API_Single_Get_Lfw_Percent_Release : description]
 * @Author   shujunhua
 * @DateTime 2021/9/29-11:27:40
 * @param    void                     [description]
 * @return   uint16                   [description]
 */
uint16 Fuel_API_Single_Get_Lfw_Percent_Release(void)
{
    uint16 Release=0;
    
    Release =  Fuel_API_Get_Lfw_Percent_Release (FUEL_TANK_A);
    return Release;
}
/**
 * [Fuel_API_Muti_Get_Lfw_Percent_Release : description]
 * @Author   shujunhua
 * @DateTime 2021/9/29-11:27:44
 * @param    void                     [description]
 * @return   uint16                   [description]
 */
uint16 Fuel_API_Muti_Get_Lfw_Percent_Release(void)
{
    uint16 Release=0;
    
    Release =  Fuel_API_Get_Lfw_Percent_Release (FUEL_TANK_A);
    return Release;
}





uint16 Fuel_Api_Get_Ref_Delta_A(void)
{
    return Fuel_Api_Rte_Get_Ref_Delta_A();
}

/** 
 * [Fuel_Api_Percent2Volume : In liters]
 * @Author   shujunhua
 * @DateTime 2021/11/23-20:19:31
 * @param    percent                  [description]
 * @param    fuel_size                [description]
 * @return   uint8                    [description]
 */
static uint8 Fuel_Api_Percent2Volume(uint16 percent,uint16 fuel_size)
{
    uint32 result=0;
    result = fuel_size*percent;
    result*=100;
    result/=254;
    result/=256;
    result/=100;
    return (uint8)result;
}
/** 
 * [Fuel_Api_log_Upadta_Dynamic_set : description]
 * @Author   shujunhua
 * @DateTime 2021/11/22-13:24:45
 * @param    time_count               [Provides the timer instance]
 * @param    fre                      [Interval time]
 * @param    time_end                 [Record maximum time]
 * @return   boolean                  [Updates are triggered periodically]
 */
static boolean Fuel_Api_log_Upadta_Dynamic_set (uint16 *time_count,uint16 fre,uint16 time_end)
{
    boolean update =FALSE;
    if((*time_count!=0)&&(time_count!=NULL)&&(time_end!=0))
    {
        if(fre!=0)
        {
            if(((((*time_count)%fre)==0)||((*time_count)==1)))
            {
                update= TRUE;
            }
        }
        (*time_count)--;
    }
    else
    {
        update= FALSE;
    }
    return update;
}


static uint8 Fuel_Api_Log_get_init_data(void)
{
    uint8 fault_Flag = 0;

    if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
    {
        #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
        fault_Flag = Fuel_Muti_Pkg_Get_Log_Init_Err_Flag();
        #endif
    }
    else if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_SINGLE_MAX))
    {
        #ifdef FUEL_TANK_SINGLE_TYPE_EN
        fault_Flag = Fuel_Single_Pkg_Get_Log_Init_Err_Flag();
        #endif
    }
    else
    {
        fault_Flag = 0; // CFG ERR
    }
    return fault_Flag;
}

static Fuel_Log_CodeInitCfg_t Fuel_Api_Log_get_CodeInit_data(void)
{
    uint16 u16temp= 0;
    Fuel_Log_CodeInitCfg_t Fuel_Log_CodeInitCfg_Data_Temp = { {0xff,0xff},{0xff,0xff},{0xff,0xff},{0xff,0xff},{0xff},{0xff},{0xff},{0xff}};

    if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
    {
        #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
        u16temp = Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit;
        Fuel_Log_CodeInitCfg_Data_Temp.Fuel_log_refuel_size[0] = (uint8)u16temp;
        u16temp = Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit/10u;
        Fuel_Log_CodeInitCfg_Data_Temp.Fuel_log_exception_size[0] = (uint8)u16temp;
        u16temp = (Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit/10u);
        Fuel_Log_CodeInitCfg_Data_Temp.Fuel_log_trigger[0] = (uint8)u16temp;
        u16temp = (Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit/10u);
        Fuel_Log_CodeInitCfg_Data_Temp.Fuel_log_release[0] = (uint8)u16temp;
        //Fuel_Log_CodeInitCfg_Data_Temp.Fuel_log_refuel_size[1] = Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit;
        //Fuel_Log_CodeInitCfg_Data_Temp.Fuel_log_exception_size[1] = Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit;
        //Fuel_Log_CodeInitCfg_Data_Temp.Fuel_log_trigger[1] = Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit;
       // Fuel_Log_CodeInitCfg_Data_Temp.Fuel_log_release[1] = Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit;
        #endif
    }
    else if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_SINGLE_MAX))
    {
        #ifdef FUEL_TANK_SINGLE_TYPE_EN
        u16temp = Fuel_Module_Cconfig_Data_Nvm.Refuel_Trigger_NvmInit;
        Fuel_Log_CodeInitCfg_Data_Temp.Fuel_log_refuel_size[0] = (uint8)u16temp;
        u16temp = Fuel_Module_Cconfig_Data_Nvm.Exception_Volume_NvmInit/10u;
        Fuel_Log_CodeInitCfg_Data_Temp.Fuel_log_exception_size[0] = (uint8)u16temp;
        u16temp = (Fuel_Module_Cconfig_Data_Nvm.LFW_Trigger_NvmInit/10u);
        Fuel_Log_CodeInitCfg_Data_Temp.Fuel_log_trigger[0] = (uint8)u16temp;
        u16temp = (Fuel_Module_Cconfig_Data_Nvm.LFW_Release_NvmInit/10u);
        Fuel_Log_CodeInitCfg_Data_Temp.Fuel_log_release[0] = (uint8)u16temp;
        #endif
    }
    else{
    }

    Fuel_Log_CodeInitCfg_Data_Temp.Fuel_log_tank_type = (uint8)FUEL_TANK_CFG;

    #ifdef FUEL_TANK_SINGLE_TYPE_EN
    Fuel_Log_CodeInitCfg_Data_Temp.Fuel_log_version_single = FUELE_SINGLE_VERSION;
    #endif
    #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
    Fuel_Log_CodeInitCfg_Data_Temp.Fuel_log_version_multiple = FUELE_MULTIPLE_VERSION;
    #endif
    #ifdef FUEL_TANK_DUAL_TYPE_EN
    Fuel_Log_CodeInitCfg_Data_Temp.Fuel_log_version_dual = FUELE_DUAL_VERSION;
    #endif

    return Fuel_Log_CodeInitCfg_Data_Temp;
}



static Fuel_Log_Period_t Fuel_Api_Log_get_Period_data(void)
{
    Fuel_Log_Period_t  Fule_Log_Period_Date_Temp={{0Xffff,0Xffff},{0xff,0xff},{0xff,0xff},{0xff,0xff},{0xff,0xff},0xff};
    uint8 fuel_singel_total_size =  Fuel_API_Single_Get_Tank_Size();
    uint16 u16temp= 0;
    #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
    uint8 fuel_aux_size = Fuel_API_Muti_Aux_Get_Tank_Size();
    uint8 fuel_main_size= 0;
    uint8 fuel_muti_total_size = Fuel_API_Muti_Get_Tank_Size();
    uint16 u16Fuel_Multiple_SenderA_Unfilter_Flps = Fuel_Multiple_SenderA_Unfilter_Flps();
    uint16 u16Fuel_Multiple_SenderB_Unfilter_Flps = Fuel_Multiple_SenderB_Unfilter_Flps();
    uint16 u16Fuel_Multiple_SenderA_Ignon_Avg_Flps = Fuel_Multiple_SenderA_Ignon_Avg_Flps();
    uint16 u16Fuel_Multiple_SenderB_Ignon_Avg_Flps =Fuel_Multiple_SenderB_Ignon_Avg_Flps();
    uint16 u16Fuel_Multiple_SenderA_Zss_Ref = Fuel_Multiple_SenderA_Zss_Ref();
    uint16 u16Fuel_Multiple_SenderB_Zss_Ref = Fuel_Multiple_SenderB_Zss_Ref();
    uint16 ui6Fuel_Multiple_SenderA_Ignoff_Ref = Fuel_Multiple_SenderA_Ignoff_Ref();
    uint16 u16Fuel_Multiple_SenderB_Ignoff_Ref = Fuel_Multiple_SenderB_Ignoff_Ref();
    if(fuel_muti_total_size>=fuel_aux_size)
    {
        fuel_main_size = fuel_muti_total_size - fuel_aux_size  ;
    }
    #endif
    if((FUEL_TANK_CFG >= FUEL_VR_COMMMON_DUAL_NO1)&&(FUEL_TANK_CFG < FUEL_VR_COMMMON_DUAL_MAX))
    {
        #ifdef FUEL_TANK_MULTIPLE_TYPE_EN
         if((0XFFFF!=u16Fuel_Multiple_SenderA_Unfilter_Flps)||(0XFFFF!=u16Fuel_Multiple_SenderB_Unfilter_Flps))
         {
             Fule_Log_Period_Date_Temp.Fuel_Log_period_fips[0]= Fuel_Api_Percent2Volume(u16Fuel_Multiple_SenderA_Unfilter_Flps,fuel_main_size) ;
             Fule_Log_Period_Date_Temp.Fuel_Log_period_fips[1]= Fuel_Api_Percent2Volume(u16Fuel_Multiple_SenderB_Unfilter_Flps,fuel_aux_size) ;
         }
         if((0XFFFF!=u16Fuel_Multiple_SenderA_Ignon_Avg_Flps)||(0XFFFF!=u16Fuel_Multiple_SenderB_Ignon_Avg_Flps))
         {
             Fule_Log_Period_Date_Temp.Fuel_Log_period_keyon[0]= Fuel_Api_Percent2Volume(u16Fuel_Multiple_SenderA_Ignon_Avg_Flps,fuel_main_size) ;
             Fule_Log_Period_Date_Temp.Fuel_Log_period_keyon[1]= Fuel_Api_Percent2Volume(u16Fuel_Multiple_SenderB_Ignon_Avg_Flps,fuel_aux_size) ;
         }
         u16temp = (Fuel_Multiple_Api_Get_Fuel_Percent()/10u);
         Fule_Log_Period_Date_Temp.Fuel_Log_period_percent=(uint8)u16temp;
         if((0XFFFF!=u16Fuel_Multiple_SenderA_Zss_Ref)||(0XFFFF != u16Fuel_Multiple_SenderB_Zss_Ref))
         {
             Fule_Log_Period_Date_Temp.Fuel_Log_period_ignonref[0]= Fuel_Api_Percent2Volume(u16Fuel_Multiple_SenderA_Zss_Ref,fuel_main_size) ;
             Fule_Log_Period_Date_Temp.Fuel_Log_period_ignonref[1]= Fuel_Api_Percent2Volume(u16Fuel_Multiple_SenderB_Zss_Ref,fuel_aux_size) ;
         }
          if((0XFFFF!=ui6Fuel_Multiple_SenderA_Ignoff_Ref)||(0XFFFF!=u16Fuel_Multiple_SenderB_Ignoff_Ref))
         {
             Fule_Log_Period_Date_Temp.Fuel_Log_period_ignoffref[0]= Fuel_Api_Percent2Volume(ui6Fuel_Multiple_SenderA_Ignoff_Ref,fuel_main_size) ;
             Fule_Log_Period_Date_Temp.Fuel_Log_period_ignoffref[1]= Fuel_Api_Percent2Volume(u16Fuel_Multiple_SenderB_Ignoff_Ref,fuel_aux_size) ;
         }

         Fule_Log_Period_Date_Temp.Fuel_Log_period_res[0]= Fuel_Api_Get_Fuel_Resisitor_Value(0)/10u;
         Fule_Log_Period_Date_Temp.Fuel_Log_period_res[1]= Fuel_Api_Get_Fuel_Resisitor_Value(1)/10u;
        #endif
    }
    else if((FUEL_TANK_CFG >=FUEL_VR_COMMMON_SINGLE_NO1)&&(FUEL_TANK_CFG<FUEL_VR_COMMMON_SINGLE_MAX))
    {
        #ifdef FUEL_TANK_SINGLE_TYPE_EN
         if(0XFFFF!=Fuel_Single_Pkg_SenderA_Ref_Flps())
         {
             Fule_Log_Period_Date_Temp.Fuel_Log_period_fips[0]= Fuel_Api_Percent2Volume(Fuel_Single_Pkg_SenderA_Ref_Flps(),fuel_singel_total_size) ;
           //Fule_Log_Period_Date_Temp.Fuel_Log_period_fips[1]= Fuel_Api_Percent2Volume(Fuel_Multiple_SenderB_Unfilter_Flps(),24) ; 
         }
         if(0XFFFF!=Fuel_Single_Pkg_SenderA_Ignon_Avgflps())
         {
             Fule_Log_Period_Date_Temp.Fuel_Log_period_keyon[0]= Fuel_Api_Percent2Volume(Fuel_Single_Pkg_SenderA_Ignon_Avgflps(),fuel_singel_total_size) ;
             //Fule_Log_Period_Date_Temp.Fuel_Log_period_keyon[1]= Fuel_Api_Percent2Volume(Fuel_Multiple_SenderB_Ignon_Avg_Flps(),24) ; 
         }
         u16temp = (Fuel_Single_Api_Get_Fuel_hmi_percent()/10u);
         Fule_Log_Period_Date_Temp.Fuel_Log_period_percent=(uint8)u16temp;
         if(0XFFFF!=Fuel_Single_Pkg_Get_Zss())
         {
             Fule_Log_Period_Date_Temp.Fuel_Log_period_ignonref[0]= Fuel_Api_Percent2Volume(Fuel_Single_Pkg_Get_Zss(),fuel_singel_total_size) ;
            // Fule_Log_Period_Date_Temp.Fuel_Log_period_ignonref[1]= Fuel_Api_Percent2Volume(Fuel_Multiple_SenderB_Zss_Ref(),24) ;
         }
          if(0XFFFF!=Fuel_Single_Pkg_SenderA_Ignoff_Ref())
         {
             Fule_Log_Period_Date_Temp.Fuel_Log_period_ignoffref[0]= Fuel_Api_Percent2Volume(Fuel_Single_Pkg_SenderA_Ignoff_Ref(),fuel_singel_total_size) ;
            // Fule_Log_Period_Date_Temp.Fuel_Log_period_ignoffref[1]= Fuel_Api_Percent2Volume(Fuel_Multiple_SenderB_Ignoff_Ref(),24) ;
         }

         Fule_Log_Period_Date_Temp.Fuel_Log_period_res[0]= (Fuel_Api_Get_Fuel_Resisitor_Value(0)/10u);
        // Fule_Log_Period_Date_Temp.Fuel_Log_period_res[1]= Fuel_Api_Get_Fuel_Resisitor_Value(1)/10;
       #endif

    }
    else
    {
    }

    return Fule_Log_Period_Date_Temp;
}


static Fuel_Log_Event_t Fuel_Api_Log_get_Event_data(void)
{
    uint8 fault_Flag =0;

    Fuel_Log_Event_t  Fule_Log_Event_Date_Temp ={{{0Xffff,0Xffff},{0xff,0xff},{0xff,0xff},{0xff,0xff},{0xff,0xff},0xff},{0xff}};
    fault_Flag = Fuel_Api_Log_get_init_data();

    Fule_Log_Event_Date_Temp.Fuel_log_event_key_data = Fuel_Api_Log_get_Period_data();

    if(FUEL_TESTBIT(fault_Flag,FUEL_LOG_ERROR_IGN_OFF_FASTFILL | FUEL_LOG_ERROR_IGN_ON_FASTFILL))
    {
        Fule_Log_Event_Date_Temp.Fuel_log_event_Fast = 1;
    }
    else
    {
        Fule_Log_Event_Date_Temp.Fuel_log_event_Fast = 0;
    }

    return Fule_Log_Event_Date_Temp;
}



static Fuel_Log_Error_t Fuel_Api_Log_get_Error_data(void)
{
    uint8 fault_Flag =0;

    Fuel_Log_Error_t  Fule_Log_Error_Date_Temp;

    fault_Flag = Fuel_Api_Log_get_init_data();

    if(FUEL_TESTBIT(fault_Flag,FUEL_LOG_ERROR_TOLERANT_FAULT))
    {
        Fule_Log_Error_Date_Temp.Fuel_Log_Error_referr =1;
    }
    else
    {
        Fule_Log_Error_Date_Temp.Fuel_Log_Error_referr = 0;
    }

    if(FUEL_TESTBIT(fault_Flag,FUEL_LOG_ERROR_SAMPLE_KEYON))
    {
         Fule_Log_Error_Date_Temp.Fuel_Log_Error_keyonerr =1;
    }
    else
    {
        Fule_Log_Error_Date_Temp.Fuel_Log_Error_keyonerr = 0;
    }

    if(Fuel_Api_Get_Sensor_Error_Status())
    {
        Fule_Log_Error_Date_Temp.Fuel_Log_Error_Sensor_Err=1;
    }
    else
    {
        Fule_Log_Error_Date_Temp.Fuel_Log_Error_Sensor_Err=0;
    }


    Fule_Log_Error_Date_Temp.Fuel_Log_Error_snapshot = Fuel_Api_Log_get_Period_data();
    return Fule_Log_Error_Date_Temp;
}

#define FUEL_LOG_CODE_IINIY_CFG_Data   \
    Fuel_Log_CodeInitCfg_Data.Fuel_log_refuel_size[0],\
    Fuel_Log_CodeInitCfg_Data.Fuel_log_exception_size[0],\
    Fuel_Log_CodeInitCfg_Data.Fuel_log_trigger[0],\
    Fuel_Log_CodeInitCfg_Data.Fuel_log_release[0],\
    Fuel_Log_CodeInitCfg_Data.Fuel_log_tank_type,\
    Fuel_Log_CodeInitCfg_Data.Fuel_log_version_single,\
    Fuel_Log_CodeInitCfg_Data.Fuel_log_version_multiple,\
    Fuel_Log_CodeInitCfg_Data.Fuel_log_version_dual

static uint8* Fuel_Log_Init_Check(void)
{
    uint8 fault_Flag = 0;

    uint8 temp = Fule_Log_Init_Date;

    Fuel_Log_CodeInitCfg_t  CodeInitTemp = Fuel_Api_Log_get_CodeInit_data();

    fault_Flag = Fuel_Api_Log_get_init_data();

    if(FUEL_TESTBIT(fault_Flag,FUEL_LOG_ERROR_TOLERANT_FAULT|FUEL_LOG_ERROR_SAMPLE_KEYON|FUEL_LOG_ERROR_IGN_OFF_FASTFILL|FUEL_LOG_ERROR_IGN_ON_FASTFILL))
    {
        Fule_Log_Init_Date = fault_Flag;
    }
    else
    {
        Fule_Log_Init_Date =0;
    }

    if(temp!=Fule_Log_Init_Date)
    {
        FUEL_SETBIT(fuel_log_message_type,FUEL_LOG_INIT_BIT);
    }

    if( TRUE  == Fuel_Api_Log_ColdInit_Flag)
    {
        Fuel_Api_Log_ColdInit_Flag = FALSE;
        Fuel_Log_CodeInitCfg_Data = CodeInitTemp;
        FUEL_SETBIT(fuel_log_message_type,FUEL_LOG_CODE_INIT_BIT);
    }

    return &fuel_log_message_type;

}



#define FUEL_LOG_PERIOD_DATA   \
    Fule_Log_Period_Date.Fuel_Log_period_res[0],\
    Fule_Log_Period_Date.Fuel_Log_period_ignonref[0],\
    Fule_Log_Period_Date.Fuel_Log_period_ignoffref[0],\
    Fule_Log_Period_Date.Fuel_Log_period_keyon[0],\
    Fule_Log_Period_Date.Fuel_Log_period_fips[0],\
    Fule_Log_Period_Date.Fuel_Log_period_res[1],\
    Fule_Log_Period_Date.Fuel_Log_period_ignonref[1],\
    Fule_Log_Period_Date.Fuel_Log_period_ignoffref[1],\
    Fule_Log_Period_Date.Fuel_Log_period_keyon[1],\
    Fule_Log_Period_Date.Fuel_Log_period_fips[1], \
    Fule_Log_Period_Date.Fuel_Log_period_percent



/** 
 * [Fuel_Log_Period_Check : check power on/off print 2S/20S]
 * @Author   shujunhua
 * @DateTime 2021/11/22-10:16:28
 * @param    void                     [description]
 * @return   uint8                    [description]
 */

static uint8* Fuel_Log_Period_Check(void)
{
     //add logic
     Fuel_Log_Period_t temp= Fuel_Api_Log_get_Period_data();
     FUEL_LOG_SYS_STATUS power_temp = Fule_log_power_status;
     if(FALSE != Fuel_Api_Get_Power_Mode_State())
     {
         Fule_log_power_status = FUEL_LOG_SYS_IGN_ON;
     }
     else
     {
         Fule_log_power_status = FUEL_LOG_SYS_IGN_OFF;
     }

     if(power_temp != Fule_log_power_status)
     {
        Fule_Log_Period_Count = FUEL_LOG_PERIOD_END_T ;
     }

     if(TRUE== Fuel_Api_log_Upadta_Dynamic_set(&Fule_Log_Period_Count,FUEL_PERIOD_LOG_INTRTVAL_TIME,FUEL_PERIOD_LOG_RECORD_MAX_TIME))
     {
        if(memcmp(&Fule_Log_Period_Date,&temp,sizeof(Fule_Log_Period_Date)))
        {
            Fule_Log_Period_Date = temp ;
            FUEL_SETBIT(fuel_log_message_type,FUEL_LOG_PERIOD_BIT);
        }
     }
//     if(Fule_Log_Period_Count!=0)
//     {
//        if(((Fule_Log_Period_Count%20)==0)||(Fule_Log_Period_Count==1))
//        {
//            Fule_Log_Period_Date =Fuel_Api_Log_get_Period_data();
//            if(memcmp(&Fule_Log_Period_Date,&temp,sizeof(Fule_Log_Period_Date)))
//            {
//                FUEL_SETBIT(fuel_log_message_type,FUEL_LOG_PERIOD_BIT);
//            }
//        }
//         Fule_Log_Period_Count--;
//     }

    return &fuel_log_message_type;
}

/** 
 * [Fuel_Log_Event_Check :check refueling events]
 * @Author   shujunhua
 * @DateTime 2021/11/22-10:15:01
 * @param    void                     [description]
 * @return   uint8                    [description]
 */

#define FUEL_LOG_EVENT_DATA \
    Fule_Log_Event_Date.Fuel_log_event_key_data.Fuel_Log_period_res[0],\
    Fule_Log_Event_Date.Fuel_log_event_key_data.Fuel_Log_period_ignonref[0],\
    Fule_Log_Event_Date.Fuel_log_event_key_data.Fuel_Log_period_ignoffref[0],\
    Fule_Log_Event_Date.Fuel_log_event_key_data.Fuel_Log_period_keyon[0],\
    Fule_Log_Event_Date.Fuel_log_event_key_data.Fuel_Log_period_fips[0],\
    Fule_Log_Event_Date.Fuel_log_event_key_data.Fuel_Log_period_res[1],\
    Fule_Log_Event_Date.Fuel_log_event_key_data.Fuel_Log_period_ignonref[1],\
    Fule_Log_Event_Date.Fuel_log_event_key_data.Fuel_Log_period_ignoffref[1],\
    Fule_Log_Event_Date.Fuel_log_event_key_data.Fuel_Log_period_keyon[1],\
    Fule_Log_Event_Date.Fuel_log_event_key_data.Fuel_Log_period_fips[1], \
    Fule_Log_Event_Date.Fuel_log_event_key_data.Fuel_Log_period_percent,\
    Fule_Log_Event_Date.Fuel_log_event_Fast

static uint8* Fuel_Log_Event_Check(void)
{
    Fuel_Log_Event_t temp;
    //uint8 spd = Fuel_Api_Get_VehRunning_State();
    temp =  Fuel_Api_Log_get_Event_data();

    /*Only recognized refueling events are recorded */
   if(temp.Fuel_log_event_Fast==1)
   {
       if(temp.Fuel_log_event_Fast!=Fule_Log_Event_Date.Fuel_log_event_Fast)
       {
           Fule_Log_Event_Date.Fuel_log_event_Fast = temp.Fuel_log_event_Fast ;
           Fule_Log_Event_Count = FUEL_EVENT_FAST_LOG_RECORD_MAX_TIME ;
       }

       if(( Fule_Log_Event_Count ==0)&&(Fule_Log_Event_Slow_Count==0))
       {
           Fule_Log_Event_Slow_Count = FUEL_EVENT_SLOW_LOG_RECORD_MAX_TIME;
       }
   }
   else
   {
       Fule_Log_Event_Date.Fuel_log_event_Fast =0 ;
       Fule_Log_Event_Slow_Count =0; 
       Fule_Log_Event_Count =0;
   }

    if(TRUE== Fuel_Api_log_Upadta_Dynamic_set(&Fule_Log_Event_Count,FUEL_EVENT_FAST_LOG_INTRTVAL_TIME,FUEL_EVENT_FAST_LOG_RECORD_MAX_TIME))
    {
        if(memcmp(&Fule_Log_Event_Date,&temp,sizeof(Fule_Log_Event_Date)))
        {
            Fule_Log_Event_Date = temp;
            FUEL_SETBIT(fuel_log_message_type,FUEL_LOG_EVENT_FAST_BIT);
        }

    }
    else if(TRUE== Fuel_Api_log_Upadta_Dynamic_set(&Fule_Log_Event_Slow_Count,FUEL_EVENT_SLOW_LOG_INTRTVAL_TIME,FUEL_EVENT_SLOW_LOG_RECORD_MAX_TIME))
    {
        if(memcmp(&Fule_Log_Event_Date,&temp,sizeof(Fule_Log_Event_Date)))
        {
            Fule_Log_Event_Date = temp;
            FUEL_SETBIT(fuel_log_message_type,FUEL_LOG_EVENT_SLOW_BIT);
        }
    }

    return &fuel_log_message_type;
}


#define FUEL_LOG_ERROR_DATA   \
        Fuel_Log_Error_Date.Fuel_Log_Error_Sensor_Err,\
        Fuel_Log_Error_Date.Fuel_Log_Error_keyonerr,\
        Fuel_Log_Error_Date.Fuel_Log_Error_referr

#define FUEL_LOG_ERROR_SNAPSHOT_DATA   \
    Fuel_Log_Error_Date.Fuel_Log_Error_snapshot.Fuel_Log_period_res[0],\
    Fuel_Log_Error_Date.Fuel_Log_Error_snapshot.Fuel_Log_period_ignonref[0],\
    Fuel_Log_Error_Date.Fuel_Log_Error_snapshot.Fuel_Log_period_ignoffref[0],\
    Fuel_Log_Error_Date.Fuel_Log_Error_snapshot.Fuel_Log_period_keyon[0],\
    Fuel_Log_Error_Date.Fuel_Log_Error_snapshot.Fuel_Log_period_fips[0],\
    Fuel_Log_Error_Date.Fuel_Log_Error_snapshot.Fuel_Log_period_res[1],\
    Fuel_Log_Error_Date.Fuel_Log_Error_snapshot.Fuel_Log_period_ignonref[1],\
    Fuel_Log_Error_Date.Fuel_Log_Error_snapshot.Fuel_Log_period_ignoffref[1],\
    Fuel_Log_Error_Date.Fuel_Log_Error_snapshot.Fuel_Log_period_keyon[1],\
    Fuel_Log_Error_Date.Fuel_Log_Error_snapshot.Fuel_Log_period_fips[1], \
    Fuel_Log_Error_Date.Fuel_Log_Error_snapshot.Fuel_Log_period_percent

/**
 * [Fuel_Log_Error_Check : check fault:sensor error/keyon error/ref error]
 * @Author   shujunhua
 * @DateTime 2021/11/22-10:15:33
 * @param    void                     [description]
 * @return   uint8                    [description]
 */
static uint8* Fuel_Log_Error_Check(void)
{
    uint8 update=0;

    Fuel_Log_Error_t Fuel_Log_Error_Date_Temp ;

    Fuel_Log_Error_Date_Temp = Fuel_Api_Log_get_Error_data();
    Fuel_Log_Error_Date.Fuel_Log_Error_snapshot = Fuel_Log_Error_Date_Temp.Fuel_Log_Error_snapshot;

    if(Fuel_Log_Error_Date_Temp.Fuel_Log_Error_Sensor_Err!= Fuel_Log_Error_Date.Fuel_Log_Error_Sensor_Err)
    {
        Fuel_Log_Error_Date.Fuel_Log_Error_Sensor_Err = Fuel_Log_Error_Date_Temp.Fuel_Log_Error_Sensor_Err;
        update =1 ;
    }

    if(Fuel_Log_Error_Date_Temp.Fuel_Log_Error_keyonerr!= Fuel_Log_Error_Date.Fuel_Log_Error_keyonerr)
    {
        Fuel_Log_Error_Date.Fuel_Log_Error_keyonerr = Fuel_Log_Error_Date_Temp.Fuel_Log_Error_keyonerr;
        update =2 ;
    }

    if(Fuel_Log_Error_Date_Temp.Fuel_Log_Error_referr!= Fuel_Log_Error_Date.Fuel_Log_Error_referr)
    {
        Fuel_Log_Error_Date.Fuel_Log_Error_referr = Fuel_Log_Error_Date_Temp.Fuel_Log_Error_referr;
        update =3 ;
    }

    if(update!=0)
    {
        FUEL_SETBIT(fuel_log_message_type,FUEL_LOG_ERROR_BIT);
    }

    return &fuel_log_message_type;
}


/**
 * [FuelLogcheklist : log task check list]
 * @Author   shujunhua
 * @DateTime 2021/11/20-13:03:18
 */
static const Fuellogcheck FuelLogcheklist[Fuel_LOG_TASK_MAX] =
{
    Fuel_Log_Init_Check,
    Fuel_Log_Event_Check,
    Fuel_Log_Period_Check,
    Fuel_Log_Error_Check
};



static void Fuel_log_trace_snapshot(uint8 *type)
{
    FUEL_LOG_SYS_STATUS power_temp = Fule_log_power_status;
    if (Fule_Log_delay_output_Count!=0)
    {
        Fule_Log_delay_output_Count--;
    }
    if(0u == Fule_Log_delay_output_Count)
    {
        if(FUEL_TESTBIT(*type,FUEL_LOG_INIT_BIT))
        {
            FUEL_CLEARBIT(*type,FUEL_LOG_INIT_BIT);
            (void)FUEL_MODULE_WARN("init=%d",Fule_Log_Init_Date);
        }

        if(FUEL_TESTBIT(*type,FUEL_LOG_CODE_INIT_BIT))
        {
            FUEL_CLEARBIT(*type,FUEL_LOG_CODE_INIT_BIT);
            (void)FUEL_MODULE_WARN("initCode=%d,%d,%d,%d,%d,V%d,V%d,V%d",FUEL_LOG_CODE_IINIY_CFG_Data);
        }

//        if(FUEL_TESTBIT(*type,FUEL_LOG_EVENT_BIT))
//        {
//
//            FUEL_MODULE_WARN("Fuel_Fast=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",FUEL_LOG_EVENT_DATA)
//            FUEL_CLEARBIT(*type,FUEL_LOG_EVENT_BIT);
//
//        }

        if(FUEL_TESTBIT(*type,FUEL_LOG_EVENT_FAST_BIT))
        {
            (void)FUEL_MODULE_WARN("FAST=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",FUEL_LOG_EVENT_DATA);
            FUEL_CLEARBIT(*type,FUEL_LOG_EVENT_FAST_BIT);
            // print event log
        }

        if(FUEL_TESTBIT(*type,FUEL_LOG_EVENT_SLOW_BIT))
        {
            (void)FUEL_MODULE_WARN("SLOW=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",FUEL_LOG_EVENT_DATA);
            FUEL_CLEARBIT(*type,FUEL_LOG_EVENT_SLOW_BIT);
        // print event log
        }

        if(FUEL_TESTBIT(*type,FUEL_LOG_PERIOD_BIT))
        {
            FUEL_CLEARBIT(*type,FUEL_LOG_PERIOD_BIT);
            if(power_temp==FUEL_LOG_SYS_IGN_ON)
            {
                (void)FUEL_MODULE_WARN("PerOn=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",FUEL_LOG_PERIOD_DATA);
            }
            else
            {
                (void)FUEL_MODULE_WARN("PerOff=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",FUEL_LOG_PERIOD_DATA);
            }
            // print period log
        }


        if(FUEL_TESTBIT(*type,FUEL_LOG_ERROR_BIT))
        {
            (void)FUEL_MODULE_ERROR("Err=%d,%d,%d",FUEL_LOG_ERROR_DATA);
            (void)FUEL_MODULE_ERROR("ErrD=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",FUEL_LOG_ERROR_SNAPSHOT_DATA);
            FUEL_CLEARBIT(*type,FUEL_LOG_ERROR_BIT);
        }
    }

}

static void Fuel_log_Task(void)
{
    uint16 i=  (uint16)Fuel_LOG_TASK_INIT;
    uint16 fuel_log_task_max = sizeof(FuelLogcheklist)/sizeof(Fuellogcheck);
    for(i=(uint16)Fuel_LOG_TASK_INIT;i<fuel_log_task_max;i++)
    {
        Fuel_log_trace_snapshot((FuelLogcheklist[i]()));
    }
}



#define SWC_FUEL_STOP_SEC_CODE
#include "SWC_Fuel_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
**
**  Revision:   1.0  
**
**  2020/06/02     Original Version
**
**********************************************************************************************************/

/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/

