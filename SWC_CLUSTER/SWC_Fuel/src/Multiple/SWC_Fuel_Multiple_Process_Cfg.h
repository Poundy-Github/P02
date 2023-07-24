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
#ifndef FUEL_MULTIPLE_CFG
#define FUEL_MULTIPLE_CFG

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
/****old para*****************************************************************************************************/
#define FUEL_MULTIPLE_DISPALY_BAR_TBL_SIZE                  (6u)
#define FUEL_MULTIPLE_DISPALY_BAR_TBL   \
  {{(uint16)3198	, (uint16)58628   	},	/*  table entry 	*/      \
  {(uint16)3197  	, (uint16)0			},  /*  Empty  2+1=3L    0%    	*/		\
  {(uint16)17056 	, (uint16)250	    },  /*  1/4    16+1=17L  25.0%	*/		\
  {(uint16)31978	, (uint16)500	    },  /*  2/4    26+4=30L	 50.0%	*/		\
  {(uint16)45836 	, (uint16)750	    },  /*  3/4    26+17=43L  75.0%	*/		\
  {(uint16)58628	, (uint16)1000	    }}  /*  4/4	   28.5+26.5=55L  100.0%	*/		\


//#define FUEL_MULTIPLE_AD_RESISTOR_TBL_SIZE                    (48u)
//     
//#define FUEL_MULTIPLE_AD_RESISTOR_TBL   \
//  {{(uint16)(117), (uint16)(3456u)},\
//  {(uint16)(117 ) , (uint16)(100)  },\
//  {(uint16)(218 ) , (uint16)(100)  },\
//  {(uint16)(876u), (uint16)(500u)},/*50ohm   34L*/\
//  {(uint16)(956u), (uint16)(560u)},/*56ohm    29L*/\
//  {(uint16)(1044u),(uint16)(630u)},/*63ohm    28.5L*/\
//  {(uint16)(1128u),(uint16)(700u)},/*70ohm    27.5L*/\
//  {(uint16)(1185u),(uint16)(750u)},/*75ohm    27L*/\
//  {(uint16)(1282u),(uint16)(840u)},/*84ohm    26L*/\
//  {(uint16)(1372u),(uint16)(930u)},/*93ohm    25L*/\
//  {(uint16)(1439u),(uint16)(1000u)},/*100ohm    24L*/\
//  {(uint16)(1538u),(uint16)(1110u)},/*111ohm    23L*/\
//  {(uint16)(1629u),(uint16)(1220u)},/*122ohm    22L*/\
//  {(uint16)(1786u),(uint16)(1430u)},/*143ohm    21L*/\
//  {(uint16)(1854u),(uint16)(1530u)},/*153ohm    20L*/\
//  {(uint16)(1918u),(uint16)(1630u)},/*163ohm    19L*/\
//  {(uint16)(1979u),(uint16)(1730u)},/*173ohm    18L*/\
//  {(uint16)(2091u),(uint16)(1930u)},/*193ohm    17L*/\
//  {(uint16)(2142u),(uint16)(2030u)},/*203ohm    16L*/\
//  {(uint16)(2182u),(uint16)(2110u)},/*211ohm    15L*/\
//  {(uint16)(2265u),(uint16)(2290u)},/*229ohm    14L*/\
//  {(uint16)(2299u),(uint16)(2370u)},/*237ohm    13L*/\
//  {(uint16)(2369u),(uint16)(2540u)},/*254ohm    12L*/\
//  {(uint16)(2430u),(uint16)(2700u)},/*270ohm    11L*/\
//  {(uint16)(2458u),(uint16)(2780u)},/*278ohm    10L*/\
//  {(uint16)(2489u),(uint16)(2870u)},/*287ohm    9L*/\
//  {(uint16)(2532u),(uint16)(3000u)},/*300ohm    8L*/\
//  {(uint16)(2560u),(uint16)(3090u)},/*309ohm    7L*/\
//  {(uint16)(2573u),(uint16)(3110u)},/*313ohm    6L*/\
//  {(uint16)(2603u),(uint16)(3230u)},/*323ohm    5L*/\
//  {(uint16)(2626u),(uint16)(3310u)},/*331ohm    4L*/\
//  {(uint16)(2651u),(uint16)(3400u)},/*340ohm    3L*/\
//  {(uint16)(2670u),(uint16)(3470u)},/*347ohm    2L*/\
//  {(uint16)(2678u),(uint16)(3500u)},/*350ohm    1L*/\
//  {(uint16)(2798u),(uint16)(4000u)},/*400ohm    1L*/\
//  {(uint16)(2901u),(uint16)(4500u)},/*450ohm    1L*/\
//  {(uint16)(2987u),(uint16)(5000u)},/*500ohm    1L*/\
//  {(uint16)(3062u),(uint16)(5500u)},/*550ohm    1L*/\
//  {(uint16)(3128u),(uint16)(6000u)},/*600ohm    1L*/\
//  {(uint16)(3186u),(uint16)(6500u)},/*650ohm    1L*/\
//  {(uint16)(3237u),(uint16)(7000u)},/*700ohm    1L*/\
//  {(uint16)(3283u),(uint16)(7500u)},/*750ohm    1L*/\
//  {(uint16)(3324u),(uint16)(8000u)},/*800ohm    1L*/\
//  {(uint16)(3362u),(uint16)(8500u)},/*850ohm    1L*/\
//  {(uint16)(3396u),(uint16)(9000u)},/*900ohm    1L*/\
//  {(uint16)(3426u),(uint16)(9500u)},/*950ohm    1L*/\
//  {(uint16)(3455u),(uint16)(10000u)},/*1000ohm  1L*/\
//  {(uint16)(3456u),(uint16)(10000u)}}\



/******* new parameter******************************************************************************************/

#define FUEL_MUTI_TANK_SIZE_N01 (61u)
#define FUEL_MUTI_TANK_SIZE_N02 (61u)
#define FUEL_MUTI_TANK_SIZE_N03 (57u)
#define FUEL_MUTI_TANK_SIZE_N04 (122u)


#define  FUEL_MUTI_Aux_TANK_SIZE_N01  (27u)
#define  FUEL_MUTI_Aux_TANK_SIZE_N02  (27u)
#define  FUEL_MUTI_Aux_TANK_SIZE_N03  (27u)
#define  FUEL_MUTI_Aux_TANK_SIZE_N04  (18u)



#define FUEL_MUTI_TANK_DEAD_N01 (2000u)
#define FUEL_MUTI_TANK_DEAD_N02 (2000u)
#define FUEL_MUTI_TANK_DEAD_N03 (3000u)
#define FUEL_MUTI_TANK_DEAD_N04 (5000u)


    /***常规双油箱一显示表格******************************************************************************/
#define FUEL_Muti_DISPALY_BAR_TBL_SIZE_COMMON_N01                    (6u)  
#define FUEL_Muti_DISPALY_BAR_TBL_COMMON_N01   \
    {{(uint16)3198	, (uint16)58628   	},	/*  table entry 	*/      \
    {(uint16)3197  	, (uint16)0			},  /*  Empty  2+1=3L    0%    	*/		\
    {(uint16)17056 	, (uint16)250	    },  /*  1/4    16+1=17L  25.0%	*/		\
    {(uint16)31978	, (uint16)500	    },  /*  2/4    26+4=30L	 50.0%	*/		\
    {(uint16)45836 	, (uint16)750	    },  /*  3/4    26+17=43L  75.0%	*/		\
    {(uint16)58628	, (uint16)1000	    }}  /*  4/4	   28.5+26.5=55L  100.0%	*/		\
    /***常规双油箱二显示表格******************************************************************************/
#define FUEL_Muti_DISPALY_BAR_TBL_SIZE_COMMON_N02                    (6u)  
#define FUEL_Muti_DISPALY_BAR_TBL_COMMON_N02   \
    {{(uint16)3198	, (uint16)58628   	},	/*  table entry 	*/      \
    {(uint16)3197  	, (uint16)0			},  /*  Empty  2+1=3L    0%    	*/		\
    {(uint16)17056 	, (uint16)250	    },  /*  1/4    16+1=17L  25.0%	*/		\
    {(uint16)31978	, (uint16)500	    },  /*  2/4    26+4=30L	 50.0%	*/		\
    {(uint16)45836 	, (uint16)750	    },  /*  3/4    26+17=43L  75.0%	*/		\
    {(uint16)58628	, (uint16)1000	    }}  /*  4/4	   28.5+26.5=55L  100.0%	*/		\
    /***常规双油箱三显示表格******************************************************************************/
#define FUEL_Muti_DISPALY_BAR_TBL_SIZE_COMMON_N03                    (6u)        
#define FUEL_Muti_DISPALY_BAR_TBL_COMMON_N03   \
    {{(uint16)3198	, (uint16)58628   	},	/*  table entry 	*/      \
    {(uint16)3197  	, (uint16)0			},  /*  Empty  2+1=3L    0%    	*/		\
    {(uint16)17056 	, (uint16)250	    },  /*  1/4    16+1=17L  25.0%	*/		\
    {(uint16)31978	, (uint16)500	    },  /*  2/4    26+4=30L	 50.0%	*/		\
    {(uint16)45836 	, (uint16)750	    },  /*  3/4    26+17=43L  75.0%	*/		\
    {(uint16)58628	, (uint16)1000	    }}  /*  4/4	   28.5+26.5=55L  100.0%	*/		\


/*************************************************************************
 * [FUEL_Muti_DISPALY_BAR_TBL_SIZE_COMMON_N04 : description]
 * @Author   GW00227774
 * @DateTime 2022/3/10-15:45:23
 * @param    11u                      [description]
 *************************************************************************/
#define FUEL_Muti_DISPALY_BAR_TBL_SIZE_COMMON_N04                    (11u)
#define FUEL_Muti_DISPALY_BAR_TBL_COMMON_N04   \
{{(uint16)2655  , (uint16)62151   },  /*  table entry             */ \
{(uint16)2655   , (uint16)0       },  /*  E           5+0=5L      */ \
{(uint16)7648   , (uint16)85      },  /*  Alarm       14.35+0     */ \
{(uint16)10020  , (uint16)125     },  /*  1/8Release  18.8+0      */ \
{(uint16)17482  , (uint16)250     },  /*  2/8         32.8+0      */ \
{(uint16)24869  , (uint16)375     },  /*  3/8         46.66+0     */ \
{(uint16)32491  , (uint16)500     },  /*  4/8         60.96+0     */ \
{(uint16)39841  , (uint16)625     },  /*  5/8         74.75+0     */ \
{(uint16)47446  , (uint16)750     },  /*  6/8         89.02+0     */ \
{(uint16)54802  , (uint16)875     },  /*  7/8         102.82+0    */ \
{(uint16)62151  , (uint16)1000    }}  /*  8/8 F       104+12.61   */ \





/**
 * [FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_SIZE_N01 : (B02/B03/B06 four-wheel-drive model adaption)]
 * @Author   shujunhua
 * @DateTime 2021/5/8-13:16:38
 * @param    32                       [description]
 */
#define FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_SIZE_N01 (32)
#define FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_N01	\
{(uint16)(876u), (uint16)(2678u)},\
{(uint16)(876u), (uint16)(254u*256u)},/*50ohm   34L*/\
{(uint16)(956u), (uint16)(55462u)},/*56ohm      29L*/\
{(uint16)(1044u),(uint16)(54505u)},/*63ohm      28.5L*/\
{(uint16)(1128u),(uint16)(52593u)},/*70ohm      27.5L*/\
{(uint16)(1185u),(uint16)(51637u)},/*75ohm      27L*/\
{(uint16)(1282u),(uint16)(49724u)},/*84ohm      26L*/\
{(uint16)(1372u),(uint16)(47812u)},/*93ohm      25L*/\
{(uint16)(1439u),(uint16)(45899u)},/*100ohm     24L*/\
{(uint16)(1538u),(uint16)(43987u)},/*111ohm     23L*/\
{(uint16)(1629u),(uint16)(42074u)},/*122ohm     22L*/\
{(uint16)(1786u),(uint16)(40162u)},/*143ohm     21L*/\
{(uint16)(1854u),(uint16)(38249u)},/*153ohm     20L*/\
{(uint16)(1918u),(uint16)(36337u)},/*163ohm     19L*/\
{(uint16)(1979u),(uint16)(34424u)},/*173ohm     18L*/\
{(uint16)(2091u),(uint16)(32512u)},/*193ohm     17L*/\
{(uint16)(2142u),(uint16)(30600u)},/*203ohm     16L*/\
{(uint16)(2182u),(uint16)(28687u)},/*211ohm     15L*/\
{(uint16)(2265u),(uint16)(26775u)},/*229ohm     14L*/\
{(uint16)(2299u),(uint16)(24862u)},/*237ohm     13L*/\
{(uint16)(2369u),(uint16)(22950u)},/*254ohm     12L*/\
{(uint16)(2430u),(uint16)(21037u)},/*270ohm     11L*/\
{(uint16)(2458u),(uint16)(19125u)},/*278ohm     10L*/\
{(uint16)(2489u),(uint16)(17212u)},/*287ohm     9L*/\
{(uint16)(2532u),(uint16)(15300u)},/*300ohm     8L*/\
{(uint16)(2560u),(uint16)(13387u)},/*309ohm     7L*/\
{(uint16)(2573u),(uint16)(11478u)},/*313ohm     6L*/\
{(uint16)(2603u),(uint16)(9562u)},/*323ohm      5L*/\
{(uint16)(2626u),(uint16)(7650u)},/*331ohm      4L*/\
{(uint16)(2651u),(uint16)(5737u)},/*340ohm      3L*/\
{(uint16)(2670u),(uint16)(3825u)},/*347ohm      2L*/\
{(uint16)(2678u),(uint16)(3825u)},/*350ohm      2L*/\

/** 
 * [FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_SIZE_N01 : (B02/B03/B06 four-wheel-drive model adaption)]
 * @Author   shujunhua
 * @DateTime 2021/5/8-13:21:12
 * @param    29                       [description]
 */
#define FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_SIZE_N01 (29)
#define FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_N01	\
{(uint16)(875u), (uint16)(2678u)},\
{(uint16)(875u), (uint16)(254u*256u)},/*50ohm   27L*/\
{(uint16)(955u),(uint16)(63820u)},/*56ohm       26.5L*/\
{(uint16)(1043u),(uint16)(61412u)},/*63ohm      25.5L*/\
{(uint16)(1127u),(uint16)(60207u)},/*70ohm      25L*/\
{(uint16)(1195u),(uint16)(57799u)},/*76ohm      24L*/\
{(uint16)(1281u),(uint16)(55391u)},/*84ohm      23L*/\
{(uint16)(1372u),(uint16)(52983u)},/*93ohm      22L*/\
{(uint16)(1538u),(uint16)(50574u)},/*111ohm     21L*/\
{(uint16)(1629u),(uint16)(48166u)},/*122ohm     20L*/\
{(uint16)(1713u),(uint16)(45758u)},/*133ohm     19L*/\
{(uint16)(1854u),(uint16)(43349u)},/*153ohm     18L*/\
{(uint16)(1918u),(uint16)(40941u)},/*163ohm     17L*/\
{(uint16)(1979u),(uint16)(38533u)},/*173ohm     16L*/\
{(uint16)(2091u),(uint16)(36124u)},/*193ohm     15L*/\
{(uint16)(2142u),(uint16)(33716u)},/*203ohm     14L*/\
{(uint16)(2223u),(uint16)(31308u)},/*220ohm     13L*/\
{(uint16)(2299u),(uint16)(28900u)},/*237ohm     12L*/\
{(uint16)(2336u),(uint16)(26491u)},/*246ohm     11L*/\
{(uint16)(2399u),(uint16)(24083u)},/*262ohm     10L*/\
{(uint16)(2430u),(uint16)(21675u)},/*270ohm     9L*/\
{(uint16)(2489u),(uint16)(19266u)},/*287ohm     8L*/\
{(uint16)(2515u),(uint16)(16858u)},/*295ohm     7L*/\
{(uint16)(2544u),(uint16)(14450u)},/*304ohm     6L*/\
{(uint16)(2575u),(uint16)(12041u)},/*314ohm     5L*/\
{(uint16)(2602u),(uint16)(9633u)},/*323ohm      4L*/\
{(uint16)(2626u),(uint16)(7225u)},/*331ohm      3L*/\
{(uint16)(2651u),(uint16)(4817u)},/*340ohm      2L*/\
{(uint16)(2678u),(uint16)(0)},/*340ohm      2L*/\

/** 
 * [FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_SIZE_N02 : (No model adaption currently)]
 * @Author   shujunhua
 * @DateTime 2021/5/8-13:20:45
 * @param    32                       [description]
 */
#define FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_SIZE_N02 (32)
#define FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_N02	\
{(uint16)(876u), (uint16)(2678u)},\
{(uint16)(876u), (uint16)(254u*256u)},/*50ohm   34L*/\
{(uint16)(956u), (uint16)(55462u)},/*56ohm      29L*/\
{(uint16)(1044u),(uint16)(54505u)},/*63ohm      28.5L*/\
{(uint16)(1128u),(uint16)(52593u)},/*70ohm      27.5L*/\
{(uint16)(1185u),(uint16)(51637u)},/*75ohm      27L*/\
{(uint16)(1282u),(uint16)(49724u)},/*84ohm      26L*/\
{(uint16)(1372u),(uint16)(47812u)},/*93ohm      25L*/\
{(uint16)(1439u),(uint16)(45899u)},/*100ohm     24L*/\
{(uint16)(1538u),(uint16)(43987u)},/*111ohm     23L*/\
{(uint16)(1629u),(uint16)(42074u)},/*122ohm     22L*/\
{(uint16)(1786u),(uint16)(40162u)},/*143ohm     21L*/\
{(uint16)(1854u),(uint16)(38249u)},/*153ohm     20L*/\
{(uint16)(1918u),(uint16)(36337u)},/*163ohm     19L*/\
{(uint16)(1979u),(uint16)(34424u)},/*173ohm     18L*/\
{(uint16)(2091u),(uint16)(32512u)},/*193ohm     17L*/\
{(uint16)(2142u),(uint16)(30600u)},/*203ohm     16L*/\
{(uint16)(2182u),(uint16)(28687u)},/*211ohm     15L*/\
{(uint16)(2265u),(uint16)(26775u)},/*229ohm     14L*/\
{(uint16)(2299u),(uint16)(24862u)},/*237ohm     13L*/\
{(uint16)(2369u),(uint16)(22950u)},/*254ohm     12L*/\
{(uint16)(2430u),(uint16)(21037u)},/*270ohm     11L*/\
{(uint16)(2458u),(uint16)(19125u)},/*278ohm     10L*/\
{(uint16)(2489u),(uint16)(17212u)},/*287ohm     9L*/\
{(uint16)(2532u),(uint16)(15300u)},/*300ohm     8L*/\
{(uint16)(2560u),(uint16)(13387u)},/*309ohm     7L*/\
{(uint16)(2573u),(uint16)(11478u)},/*313ohm     6L*/\
{(uint16)(2603u),(uint16)(9562u)},/*323ohm      5L*/\
{(uint16)(2626u),(uint16)(7650u)},/*331ohm      4L*/\
{(uint16)(2651u),(uint16)(5737u)},/*340ohm      3L*/\
{(uint16)(2670u),(uint16)(3825u)},/*347ohm      2L*/\
{(uint16)(2678u),(uint16)(3825u)},/*350ohm      2L*/\

/** 
 * [FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_SIZE_N02 : (No model adaption currently)]
 * @Author   shujunhua
 * @DateTime 2021/5/8-13:21:01
 * @param    29                       [description]
 */
#define FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_SIZE_N02 (29)
#define FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_N02	\
{(uint16)(875u), (uint16)(2678u)},\
{(uint16)(875u), (uint16)(254u*256u)},/*50ohm   27L*/\
{(uint16)(955u),(uint16)(63820u)},/*56ohm       26.5L*/\
{(uint16)(1043u),(uint16)(61412u)},/*63ohm      25.5L*/\
{(uint16)(1127u),(uint16)(60207u)},/*70ohm      25L*/\
{(uint16)(1195u),(uint16)(57799u)},/*76ohm      24L*/\
{(uint16)(1281u),(uint16)(55391u)},/*84ohm      23L*/\
{(uint16)(1372u),(uint16)(52983u)},/*93ohm      22L*/\
{(uint16)(1538u),(uint16)(50574u)},/*111ohm     21L*/\
{(uint16)(1629u),(uint16)(48166u)},/*122ohm     20L*/\
{(uint16)(1713u),(uint16)(45758u)},/*133ohm     19L*/\
{(uint16)(1854u),(uint16)(43349u)},/*153ohm     18L*/\
{(uint16)(1918u),(uint16)(40941u)},/*163ohm     17L*/\
{(uint16)(1979u),(uint16)(38533u)},/*173ohm     16L*/\
{(uint16)(2091u),(uint16)(36124u)},/*193ohm     15L*/\
{(uint16)(2142u),(uint16)(33716u)},/*203ohm     14L*/\
{(uint16)(2223u),(uint16)(31308u)},/*220ohm     13L*/\
{(uint16)(2299u),(uint16)(28900u)},/*237ohm     12L*/\
{(uint16)(2336u),(uint16)(26491u)},/*246ohm     11L*/\
{(uint16)(2399u),(uint16)(24083u)},/*262ohm     10L*/\
{(uint16)(2430u),(uint16)(21675u)},/*270ohm     9L*/\
{(uint16)(2489u),(uint16)(19266u)},/*287ohm     8L*/\
{(uint16)(2515u),(uint16)(16858u)},/*295ohm     7L*/\
{(uint16)(2544u),(uint16)(14450u)},/*304ohm     6L*/\
{(uint16)(2575u),(uint16)(12041u)},/*314ohm     5L*/\
{(uint16)(2602u),(uint16)(9633u)},/*323ohm      4L*/\
{(uint16)(2626u),(uint16)(7225u)},/*331ohm      3L*/\
{(uint16)(2651u),(uint16)(4817u)},/*340ohm      2L*/\
{(uint16)(2678u),(uint16)(0)},/*340ohm      2L*/\

/** 
 * [FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_SIZE_N03 : (A08 four-wheel-drive model adaption)]
 * @Author   shujunhua
 * @DateTime 2021/5/8-13:19:52
 * @param    32                       [description]
 */
#define FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_SIZE_N03 (32)
#define FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_N03	\
{(uint16)(876u), (uint16)(2678u)},\
{(uint16)(876u), (uint16)(254u*256u)},/*50ohm   34L*/\
{(uint16)(956u), (uint16)(55462u)},/*56ohm      29L*/\
{(uint16)(1044u),(uint16)(54505u)},/*63ohm      28.5L*/\
{(uint16)(1128u),(uint16)(52593u)},/*70ohm      27.5L*/\
{(uint16)(1185u),(uint16)(51637u)},/*75ohm      27L*/\
{(uint16)(1282u),(uint16)(49724u)},/*84ohm      26L*/\
{(uint16)(1372u),(uint16)(47812u)},/*93ohm      25L*/\
{(uint16)(1439u),(uint16)(45899u)},/*100ohm     24L*/\
{(uint16)(1538u),(uint16)(43987u)},/*111ohm     23L*/\
{(uint16)(1629u),(uint16)(42074u)},/*122ohm     22L*/\
{(uint16)(1786u),(uint16)(40162u)},/*143ohm     21L*/\
{(uint16)(1854u),(uint16)(38249u)},/*153ohm     20L*/\
{(uint16)(1918u),(uint16)(36337u)},/*163ohm     19L*/\
{(uint16)(1979u),(uint16)(34424u)},/*173ohm     18L*/\
{(uint16)(2091u),(uint16)(32512u)},/*193ohm     17L*/\
{(uint16)(2142u),(uint16)(30600u)},/*203ohm     16L*/\
{(uint16)(2182u),(uint16)(28687u)},/*211ohm     15L*/\
{(uint16)(2265u),(uint16)(26775u)},/*229ohm     14L*/\
{(uint16)(2299u),(uint16)(24862u)},/*237ohm     13L*/\
{(uint16)(2369u),(uint16)(22950u)},/*254ohm     12L*/\
{(uint16)(2430u),(uint16)(21037u)},/*270ohm     11L*/\
{(uint16)(2458u),(uint16)(19125u)},/*278ohm     10L*/\
{(uint16)(2489u),(uint16)(17212u)},/*287ohm     9L*/\
{(uint16)(2532u),(uint16)(15300u)},/*300ohm     8L*/\
{(uint16)(2560u),(uint16)(13387u)},/*309ohm     7L*/\
{(uint16)(2573u),(uint16)(11478u)},/*313ohm     6L*/\
{(uint16)(2603u),(uint16)(9562u)},/*323ohm      5L*/\
{(uint16)(2626u),(uint16)(7650u)},/*331ohm      4L*/\
{(uint16)(2651u),(uint16)(5737u)},/*340ohm      3L*/\
{(uint16)(2670u),(uint16)(3825u)},/*347ohm      2L*/\
{(uint16)(2678u),(uint16)(3825u)},/*350ohm      2L*/\

/** 
 * [FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_SIZE_N03 : (A08 four-wheel-drive model adaption)]
 * @Author   shujunhua
 * @DateTime 2021/5/8-13:20:30
 * @param    29                       [description]
 */
#define FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_SIZE_N03 (29)
#define FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_N03	\
{(uint16)(875u), (uint16)(2678u)},\
{(uint16)(875u), (uint16)(254u*256u)},/*50ohm   27L*/\
{(uint16)(955u),(uint16)(63820u)},/*56ohm       26.5L*/\
{(uint16)(1043u),(uint16)(61412u)},/*63ohm      25.5L*/\
{(uint16)(1127u),(uint16)(60207u)},/*70ohm      25L*/\
{(uint16)(1195u),(uint16)(57799u)},/*76ohm      24L*/\
{(uint16)(1281u),(uint16)(55391u)},/*84ohm      23L*/\
{(uint16)(1372u),(uint16)(52983u)},/*93ohm      22L*/\
{(uint16)(1538u),(uint16)(50574u)},/*111ohm     21L*/\
{(uint16)(1629u),(uint16)(48166u)},/*122ohm     20L*/\
{(uint16)(1713u),(uint16)(45758u)},/*133ohm     19L*/\
{(uint16)(1854u),(uint16)(43349u)},/*153ohm     18L*/\
{(uint16)(1918u),(uint16)(40941u)},/*163ohm     17L*/\
{(uint16)(1979u),(uint16)(38533u)},/*173ohm     16L*/\
{(uint16)(2091u),(uint16)(36124u)},/*193ohm     15L*/\
{(uint16)(2142u),(uint16)(33716u)},/*203ohm     14L*/\
{(uint16)(2223u),(uint16)(31308u)},/*220ohm     13L*/\
{(uint16)(2299u),(uint16)(28900u)},/*237ohm     12L*/\
{(uint16)(2336u),(uint16)(26491u)},/*246ohm     11L*/\
{(uint16)(2399u),(uint16)(24083u)},/*262ohm     10L*/\
{(uint16)(2430u),(uint16)(21675u)},/*270ohm     9L*/\
{(uint16)(2489u),(uint16)(19266u)},/*287ohm     8L*/\
{(uint16)(2515u),(uint16)(16858u)},/*295ohm     7L*/\
{(uint16)(2544u),(uint16)(14450u)},/*304ohm     6L*/\
{(uint16)(2575u),(uint16)(12041u)},/*314ohm     5L*/\
{(uint16)(2602u),(uint16)(9633u)},/*323ohm      4L*/\
{(uint16)(2626u),(uint16)(7225u)},/*331ohm      3L*/\
{(uint16)(2651u),(uint16)(4817u)},/*340ohm      2L*/\
{(uint16)(2678u),(uint16)(0)},/*340ohm      2L*/\


/*************************************************************************
 * [FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_SIZE_N04 : description]
 * @Author   GW00227774
 * @DateTime 2022/3/10-15:52:39
 * @param    23                       [description]
 *************************************************************************/
#define FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_SIZE_N04 (23)
#define FUEL_MUTI_SENDER_A_AD_TO_PF_TBL_N04 \
{(uint16)(875u), (uint16)(2677u)},\
{(uint16)(875u), (uint16)(254u*256u)}, /*50ohm        104L*/\
{(uint16)(1059u),(uint16)(64286u)},    /*64.3ohm   102.82L*/\
{(uint16)(1143u),(uint16)(63461u)},    /*71.44ohm   101.5L*/\
{(uint16)(1298u),(uint16)(61598u)},    /*85.71ohm   98.52L*/\
{(uint16)(1438u),(uint16)(59403u)},    /*99.99ohm   95.01L*/\
{(uint16)(1564u),(uint16)(57015u)},    /*114.26ohm  91.19L*/\
{(uint16)(1622u),(uint16)(55658u)},    /*121.4ohm   89.02L*/\
{(uint16)(1731u),(uint16)(52857u)},    /*135.67ohm  84.54L*/\
{(uint16)(1832u),(uint16)(49912u)},    /*149.93ohm  79.83L*/\
{(uint16)(1919u),(uint16)(46736u)},    /*164.2ohm   74.75L*/\
{(uint16)(2010u),(uint16)(43347u)},    /*178.52ohm  69.33L*/\
{(uint16)(2127u),(uint16)(38114u)},    /*200ohm     60.96L*/\
{(uint16)(2230u),(uint16)(32787u)},    /*221.42ohm  52.44L*/\
{(uint16)(2293u),(uint16)(29173u)},    /*235.7ohm   46.66L*/\
{(uint16)(2380u),(uint16)(23996u)},    /*257.12ohm  38.38L*/\
{(uint16)(2434u),(uint16)(20508u)},    /*271.4ohm    32.8L*/\
{(uint16)(2484u),(uint16)(16894u)},    /*285.68ohm  27.02L*/\
{(uint16)(2554u),(uint16)(11754u)},    /*307.1ohm    18.8L*/\
{(uint16)(2577u),(uint16)(10354u)},    /*314.2ohm   16.56L*/\
{(uint16)(2597u),(uint16)(8972u)},     /*321.4ohm   14.35L*/\
{(uint16)(2639u),(uint16)(5821u)},     /*335.7ohm    9.31L*/\
{(uint16)(2677u),(uint16)(3126u)},     /*350ohm      4.98L*/\
/*************************************************************************
 * [FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_SIZE_N04 : description]
 * @Author   GW00227774
 * @DateTime 2022/3/10-15:52:46
 * @param    14                       [description]
 *************************************************************************/
#define FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_SIZE_N04 (14)
#define FUEL_MUTI_SENDER_B_AD_TO_PF_TBL_N04 \
{(uint16)(875u), (uint16)(2677u)},\
{(uint16)(875u), (uint16)(254u*256u)}, /*50ohm  18.3L    */\
{(uint16)(1181u),(uint16)(57618u)},    /*75ohm  15.95L   */\
{(uint16)(1437u),(uint16)(50177u)},    /*100ohm 13.89L   */\
{(uint16)(1650u),(uint16)(42663u)},    /*125ohm 10.9L    */\
{(uint16)(1833u),(uint16)(36486u)},    /*150ohm 10.1L    */\
{(uint16)(1989u),(uint16)(29622u)},    /*175ohm 8.2L     */\
{(uint16)(2126u),(uint16)(23951u)},    /*200ohm 6.63L    */\
{(uint16)(2245u),(uint16)(18532u)},    /*225ohm 5.13L    */\
{(uint16)(2351u),(uint16)(13908u)},    /*250ohm 3.85L    */\
{(uint16)(2446u),(uint16)(9212u)},     /*275ohm 2.55L    */\
{(uint16)(2531u),(uint16)(5888u)},     /*300ohm 1.63L    */\
{(uint16)(2608u),(uint16)(33901u)},    /*325ohm 1.08L    */\
{(uint16)(2677u),(uint16)(0u)},        /*350ohm 0L       */\


#define FUEL_MULTIPLE_MAX_TANK_SIZE                         ((uint16)600)    /*56L*/


#define FUEL_MULTIPLE_IGN_ACTIVE_POSITION()  TRUE// modify by fchao in 20200601 GPIO_nIGNITION_DBNC_IS_ACTIVE()

#define FUEL_MULTIPLE_ALL_SYNC_READY()                      (Fuel_Multiple_Init_Finished()!= 0)

#define FUEL_MULTIPLE_FILTER_BYPASS()                       (FALSE) // modify by fchao in 20200601 (EOL_FuelDampOff_WorkEnable())(dld_eol_live_mode_active())

#ifndef FUEL_MUTI_DISPALY_BAR_TBL_SIZE_COMMON_MAX
#define  FUEL_MUTI_DISPALY_BAR_TBL_SIZE_COMMON_MAX  12
#else 
  #error FUEL_MUTI_DISPALY_BAR_TBL_SIZE_COMMON_MAX must be greater than zero !
#endif	

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
