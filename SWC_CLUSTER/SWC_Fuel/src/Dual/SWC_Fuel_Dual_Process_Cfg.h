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
#ifndef FUEL_DUAL_CFG
#define FUEL_DUAL_CFG

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

#define FUEL_DUAL_DISPALY_BAR_TBL_SIZE                  (6u)
#define FUEL_DUAL_DISPALY_TBL_SIZE                      (6u)
#define FUEL_DUAL_NUM_FUEL_DISPALY_TBL                  (1U)

  


#define FUEL_DUAL_TANK_A_SIZE_N01 (61u)
#define FUEL_DUAL_TANK_B_SIZE_N01 (61u)
      
#define FUEL_DUAL_TANK_A_DEAD_N01 (2000u)        
#define FUEL_DUAL_TANK_B_DEAD_N01 (2000u)



#define FUEL_DUAL_A_DISPALY_BAR_TBL_SIZE_COMMON_N01                    (6u)  
#define FUEL_DUAL_A_DISPALY_BAR_TBL_COMMON_N01   \
    {{(uint16)5329    , (uint16)61826     },  /*  table entry     */      \
    {(uint16)5329     , (uint16)0         },  /*  Empty E-5L   0%     */      \
    {(uint16)19187    , (uint16)250       },  /*  1/4     25.0%   */      \
    {(uint16)33045    , (uint16)500       },  /*  2/4     50.0%   */      \
    {(uint16)46903    , (uint16)750       },  /*  3/4     75.0%   */      \
    {(uint16)61826    , (uint16)1000      }}  /*  4/4   F-58L 100.0%*/        \

#define FUEL_DUAL_B_DISPALY_BAR_TBL_SIZE_COMMON_N01                    (6u)  
#define FUEL_DUAL_B_DISPALY_BAR_TBL_COMMON_N01   \
    {{(uint16)5329    , (uint16)61826     },  /*  table entry     */      \
    {(uint16)5329     , (uint16)0         },  /*  Empty E-5L   0%     */      \
    {(uint16)19187    , (uint16)250       },  /*  1/4     25.0%   */      \
    {(uint16)33045    , (uint16)500       },  /*  2/4     50.0%   */      \
    {(uint16)46903    , (uint16)750       },  /*  3/4     75.0%   */      \
    {(uint16)61826    , (uint16)1000      }}  /*  4/4   F-58L 100.0%*/        \



#define FUEL_DUAL_SENDER_A_AD_TO_PF_TBL_SIZE_N01 (18)
#define FUEL_DUAL_SENDER_A_AD_TO_PF_TBL_N01	\
{(uint16)875  , (uint16)2678      },  /*  table entry MIN MAX*/   \
{(uint16)875  , (uint16)254*256   },  /*  50ohm     61L*/         \
{(uint16)963 ,  (uint16)61826     },  /*  56.5ohm   58L*/         \
{(uint16)1197 , (uint16)57562     },  /*  76.1ohm   54L*/         \
{(uint16)1461 , (uint16)52232     },  /*  102.2ohm  49L*/         \
{(uint16)1628 , (uint16)47968     },  /*  159.6ohm  45L*/         \
{(uint16)1677 , (uint16)46903     },  /*  128.3ohm  44L*/         \
{(uint16)1775 , (uint16)43704     },  /*  141.3ohm  41L*/         \
{(uint16)1947 , (uint16)38375     },  /*  167.4.3ohm36L*/         \
{(uint16)2060 , (uint16)34110     },  /*  187ohm    32L*/         \
{(uint16)2095 , (uint16)33045     },  /*  193.5ohm  31L*/         \
{(uint16)2193 , (uint16)28782     },  /*  213ohm    27L*/         \
{(uint16)2310 , (uint16)23451     },  /*  239.1ohm  22L*/         \
{(uint16)2414 , (uint16)19187     },  /*  265.2ohm  18L*/         \
{(uint16)2461 , (uint16)15989     },  /*  278.3ohm  15L*/         \
{(uint16)2504 , (uint16)13858     },  /*  291.3ohm  13L*/         \
{(uint16)2567 , (uint16)10659     },  /*  310.9ohm  10L*/         \
{(uint16)2678 , (uint16)5329      },  /*  350ohm     5L*/         \



#define FUEL_DUAL_SENDER_B_AD_TO_PF_TBL_SIZE_N01 (18)
#define FUEL_DUAL_SENDER_B_AD_TO_PF_TBL_N01	\
{(uint16)875  , (uint16)2678      },  /*  table entry MIN MAX*/   \
{(uint16)875  , (uint16)254*256   },  /*  50ohm     61L*/         \
{(uint16)963 ,  (uint16)61826     },  /*  56.5ohm   58L*/         \
{(uint16)1197 , (uint16)57562     },  /*  76.1ohm   54L*/         \
{(uint16)1461 , (uint16)52232     },  /*  102.2ohm  49L*/         \
{(uint16)1628 , (uint16)47968     },  /*  159.6ohm  45L*/         \
{(uint16)1677 , (uint16)46903     },  /*  128.3ohm  44L*/         \
{(uint16)1775 , (uint16)43704     },  /*  141.3ohm  41L*/         \
{(uint16)1947 , (uint16)38375     },  /*  167.4.3ohm36L*/         \
{(uint16)2060 , (uint16)34110     },  /*  187ohm    32L*/         \
{(uint16)2095 , (uint16)33045     },  /*  193.5ohm  31L*/         \
{(uint16)2193 , (uint16)28782     },  /*  213ohm    27L*/         \
{(uint16)2310 , (uint16)23451     },  /*  239.1ohm  22L*/         \
{(uint16)2414 , (uint16)19187     },  /*  265.2ohm  18L*/         \
{(uint16)2461 , (uint16)15989     },  /*  278.3ohm  15L*/         \
{(uint16)2504 , (uint16)13858     },  /*  291.3ohm  13L*/         \
{(uint16)2567 , (uint16)10659     },  /*  310.9ohm  10L*/         \
{(uint16)2678 , (uint16)5329      },  /*  350ohm     5L*/         \




#define FUEL_DUAL_MAX_TANK_SIZE                         ((uint16)600)    /*56L*/


#define FUEL_DUAL_IGN_ACTIVE_POSITION()  TRUE// modify by fchao in 20200601 GPIO_nIGNITION_DBNC_IS_ACTIVE()

//#define FUEL_DUAL_ALL_SYNC_READY()                      (Fuel_Dual_Init_Finished()!= 0)

#define FUEL_DUAL_FILTER_BYPASS()                       (FALSE) // modify by fchao in 20200601 (EOL_FuelDampOff_WorkEnable())/*(dld_eol_live_mode_active())*/

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
