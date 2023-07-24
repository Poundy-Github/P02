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

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/

#include "SWC_Fuel_Single_Process.h"
#include "SWC_Fuel_Api_Process.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	              Type Definition																		  *
*																								          *
*																								          *
**********************************************************************************************************/

//#define FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS           (1u)
#define FUEL_SINGLE_NUM_FUEL_TABLES 					(1u)

/*
#if (FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS == 1)
#undef FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS
#endif
*/

/**********************************************************************************************************
** Define the type of average to use.
** 0 = No Avg, 1 = Moving Average, 2 = Avg w/faults, 3 = Avg w/o faults
**********************************************************************************************************/
#define FUEL_SINGLE_AVG_TYPE    						(0u)

/**********************************************************************************************************
** Set the following to the number of 'errors' that need to occur before
** the fuel data is logged to NVM.
**********************************************************************************************************/
#define FUEL_SINGLE_ERR_CNT                          	(500u)

/**********************************************************************************************************
** Define the following if you want fast fill enabled.  Otherwise, comment
** it out.
**
** This constant will be stored in bit position FAST_FILL_ENABLE_BIT (0x40)
** of 1 byte of NVM called Fuel02OptionsNVM.
**********************************************************************************************************/

#define FUEL_SINGLE_FAST_FILL_ENABLE

#define FUEL_SINGLE_LIMIT_HIGN  						(140u)
#define FUEL_SINGLE_LIMIT_LOW  							(1u)


/**********************************************************************************************************
** Define the following if you want the fast fill recovery filter jam feature enabled.
** Otherwise, comment it out.
**********************************************************************************************************/

#define FUEL_SINGLE_RECOV_FLTR_JAM_ENABLE

/**********************************************************************************************************
** Define the following if you want the Honda fast fill rate check enabled.
** Otherwise, comment it out.
**********************************************************************************************************/
/*#define FUEL03_FFRC_ENABLE*/

/**********************************************************************************************************
** Set the following to 1 if you want the feature enabled, otherwise a 0 will
** disable it.
**********************************************************************************************************/
#define FUEL_SINGLE_FORCE_FILT_JAM                      (0u)

/**********************************************************************************************************
** Define the following if you want hill hold enabled.  Otherwise, comment
** it out.
**********************************************************************************************************/
#define FUEL_SINGLE_HILL_HOLD_ENABLE 

#define FUEL_SINGLE_INIT_DELAY_COUNT_TIME               Fuel_Api_Config_Data_NVM_Pkg_Get_Data(4) * 7 / 10 //(14u)  20*7/10= 1.4s

#define FUEL_SINGLE_INIT_GOOD_SAMPLES_REQUIRED          (10u)

#define FUEL_SINGLE_IGNOFF_SAMPLE_TIME                  (0u)

#define FUEL_SINGLE_IGNON_DELAY_TIME                    Fuel_Api_Config_Data_NVM_Pkg_Get_Data(4) * 3 / 10 //(6u)  20*3/10= 0.6s
 
#define FUEL_SINGLE_KOS_COUNTS                          (50u)

#define FUEL_SINGLE_KOS_CYCLES                          (4u)

#define FUEL_SINGLE_KOS_MIN_SMPLS                       (30u)

/*#define FUEL_SINGLE_MAX_RATE_CHECK_SAMPLES (5)*/

#define FUEL_SINGLE_OPEN_SENDER_LIMIT                   Fuel_Api_Config_Data_NVM_Pkg_Get_Data(1)//(3457u)		/* 1000 ohm */
#define FUEL_SINGLE_OPEN_SENDER_RECOVERY                Fuel_Api_Config_Data_NVM_Pkg_Get_Data(1)//(3457u)		/* 1000 ohm */

#define FUEL_SINGLE_SHORTED_SENDER_LIMIT                Fuel_Api_Config_Data_NVM_Pkg_Get_Data(0)//(218u)		/* 10 ohm */
#define FUEL_SINGLE_SHORTED_SENDER_RECOVERY             Fuel_Api_Config_Data_NVM_Pkg_Get_Data(0)//(218u)		/* 10 ohm */

#define FUEL_SINGLE_OPEN_SHORT_FAULT_TIME               Fuel_Api_Config_Data_NVM_Pkg_Get_Data(2)//(100u)		/* 10 sec */
#define FUEL_SINGLE_OPEN_SHORT_RECOVERY_TIME            Fuel_Api_Config_Data_NVM_Pkg_Get_Data(3)//(100u)		/* 10 sec */

/*#define FUEL_SINGLE_RATE_CHECK_TIMER_START_VALUE        (10u)*/

#define FUEL_SINGLE_REF_AVG_TYPE                        (4u)

#define FUEL_SINGLE_SMPLS_2_AVG                         (1u)

#define FUEL_SINGLE_ZERO_SPEED_COUNTER                  (73u)   /* was (200u) but changed for testing */

#define FUEL_SINGLE_ZS_COUNTS                           (50u)
#define FUEL_SINGLE_ZS_CYCLES                           (4u)
#define FUEL_SINGLE_ZS_MIN_SMPLS                        (30u)

#define FUEL_SINGLE_ZSS_REF_ONLY

#define FUEL_SINGLE_DELTA_FAST_ADJUST_A                 (0x0000)

#define FUEL_SINGLE_DELTA_FAST_BASE_A                   Fuel_Api_Config_Data_NVM_Pkg_Get_Data(12)//(13971845uL)
#define FUEL_SINGLE_DELTA_FAST_BASE_A_NEG               Fuel_Api_Config_Data_NVM_Pkg_Get_Data(12)//(13971845uL)

/*#define FUEL_SINGLE_DELTA_FAST_BASE_A                   { 90980923uL, 90980923uL, 90980923uL }*/

#define FUEL_SINGLE_DELTA_FAST_CLAMP_A                  (0x00FFFFFFuL) /*(0x00FFFFFFuL) changed for UT */
/*#define FUEL_SINGLE_DELTA_FAST_CLAMP_A                  {0x00F10000uL, 0x00F10000uL, 0x00F10000uL}*/

#define FUEL_SINGLE_DELTA_NORMAL_ADJUST_A               (0u)
/*#define FUEL_SINGLE_DELTA_NORMAL_ADJUST_A               {356, 356, 356 }*/

/*
Damp_run_fuelup	OR Damp_run_fueldown	
unit:L/2S	 
Resolution:0.0001L/2S	
default :0.040L/2S
*/
#define FUEL_SINGLE_DELTA_NORMAL_BASE_A                 Fuel_Api_Config_Data_NVM_Pkg_Get_Data(9)//(139718ul)  /*100ms*/

#define FUEL_SINGLE_DELTA_NORMALUP_BASE_A               Fuel_Api_Config_Data_NVM_Pkg_Get_Data(9)//(139718ul)  /*100ms*/

#define FUEL_SINGLE_DELTA_NORMALDOWN_BASE_A               Fuel_Api_Config_Data_NVM_Pkg_Get_Data(10)//(139718ul)  /*100ms*/


/*
Damp_idle
unit:L/2S	 
Resolution:0.0001L/2S	
default :0.0025L/2S
*/
#define FUEL_SINGLE_DELTA_NORMAL_IDLE_BASE_A            Fuel_Api_Config_Data_NVM_Pkg_Get_Data(13)//(8732ul)
/*
Damp_lowfuel	
unit:L/2S	 
Resolution:0.0001L/2S	
default :0.040L/2S
@20201012 adjust 6 times to slow down
@20201015 recover to default value
@20301022 adjust 3 times to slow down
100% =254*2^8
254*2^8/61 *0.040 /20  =139718 /3 
*/
#define FUEL_SINGLE_DELTA_NEGTIVE_LOW_BASE_A               Fuel_Api_Config_Data_NVM_Pkg_Get_Data(8)//(46572ul) 
/*
Damp_lowfuel	
unit:L/2S	 
Resolution:0.0001L/2S	
default :0.040L/2S
@20201012 adjust 6 times to slow down
@20201015 recover to default value
@20301022 adjust 4 times to slow down
100% =254*2^8
254*2^8/61 *0.040 /20  =139718 /4 
*/
#define FUEL_SINGLE_DELTA_POSTIVE_LOW_BASE_A               Fuel_Api_Config_Data_NVM_Pkg_Get_Data(8)//(34929ul) 

#define FUEL_SINGLE_DELTA_NORMAL_CLAMP_A                  (0x00FFFFFFuL)
/*3730.885246 about 3.5L for Keyoff_ref 5S minimum and maximum value difference for reference */
#define FUEL_SINGLE_KO_DELTA_A                            (Fuel_Api_Get_Ref_Delta_A())//(3730) 
/*3730.885246 about 3.5L for ZSS_ref  5S minimum and maximum value difference for reference */
#define FUEL_SINGLE_ZS_DELTA_A                            (Fuel_Api_Get_Ref_Delta_A())//(3730)

/*#define FUEL_SINGLE_LOWER_RATE_CHECK_LIMIT_A            (1u)*/
/*#define FUEL_SINGLE_LOWER_RATE_CHECK_LIMIT_A            { 1, 1, 1 }*/
/* afer init 5L*/
#define FUEL_SINGLE_NEGATIVE_FAST_FILL_DELTA_A            Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17)//(42638) 
#define FUEL_SINGLE_NEGATIVE_LEAK_FAST_FILL_DELTA_A       Fuel_Api_Config_Data_NVM_Pkg_Get_Data(18)//(42638) 

/* init(cold/warm) 5L*/
#define FUEL_SINGLE_NEGATIVE_INIT_FILL_DELTA_A            Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17)//(42638) 
/*#define FUEL_SINGLE_NEGATIVE_INIT_FILL_DELTA_A          { 33, 33, 33 }*/

#define FUEL_SINGLE_PERCENT_FULL_NEGATIVE_HYST            (0u) /*(1)*/
/*#define FUEL_SINGLE_PERCENT_FULL_NEGATIVE_HYST          { 5, 5, 5 }*/

#define FUEL_SINGLE_PERCENT_FULL_POSITIVE_HYST            (0u) /*(2560)*/
/*#define FUEL_SINGLE_PERCENT_FULL_POSITIVE_HYST          { 5, 5, 5 }*/
/* afer init 5329.836066  about 5L   */
#define FUEL_SINGLE_POSITIVE_FAST_FILL_DELTA_A            Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17)//(5329)
/*#define FUEL_SINGLE_POSITIVE_FAST_FILL_DELTA_A          {  33, 33, 33 }*/

/* init(cold/warm) 5329.836066  about 5L*/
#define FUEL_SINGLE_POSITIVE_INIT_FILL_DELTA_A            Fuel_Api_Config_Data_NVM_Pkg_Get_Data(17)//(5329)
/*#define FUEL_SINGLE_POSITIVE_INIT_FILL_DELTA_A          { 18, 18, 18 }*/
/* init(cold/warm) 40L */
#define FUEL_SINGLE_SEC_POS_INIT_FILL_DELTA_A             (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(29))
/*#define FUEL_SINGLE_SEC_POS_INIT_FILL_DELTA_A           { 73, 73, 73 }*/
/* init(cold/warm) 40L */
#define FUEL_SINGLE_SEC_NEG_INIT_FILL_DELTA_A             (Fuel_Api_Config_Data_NVM_Pkg_Get_Data(29))
/*#define FUEL_SINGLE_SEC_NEG_INIT_FILL_DELTA_A           { 73, 73, 73 }*/

#define FUEL_SINGLE_SENDERA_ERROR                         (6u)
/*#define FUEL_SINGLE_SENDERA_ERROR                       { 6, 6, 6}*/

#define FUEL_SINGLE_SENDERA_RC_FILL_DELTA                 (0xFFFF) /*(0xFF)13 means percent is 5% @20201014 Disable*/
/*#define FUEL_SINGLE_SENDERA_RC_FILL_DELTA               { 5, 5, 5 }*/

#define FUEL_SINGLE_SENDERA_RC_FILL_THRESHOLD             (0xFFFF) /* (192*256) =44L.@20201014 Disable */
/* 56496.2623 about 53L*/
#define FUEL_SINGLE_SENDERA_RC_FILL_FULL                  (56496) 
/*#define FUEL_SINGLE_SENDERA_RC_FILL_THRESHOLD           { 240, 240, 240 }*/

/*#define FUEL_SINGLE_SENDERA_WEIGHT                      (128u)*/
/*#define FUEL_SINGLE_SENDERA_WEIGHT                      { 128, 128, 128 }*/

#define FUEL_SINGLE_SLOSH_FILTER_EMPTY_PRELOAD_A          (0x00000000uL)
/*#define FUEL_SINGLE_SLOSH_FILTER_EMPTY_PRELOAD_A        {0x0C000000uL, 0x0C000000uL, 0x0C000000uL }*/

/*#define FUEL_SINGLE_UPPER_RATE_CHECK_LIMIT_A             (20u)*/
/*#define FUEL_SINGLE_UPPER_RATE_CHECK_LIMIT_A            { 20, 20, 20 }*/


/*#define FUEL_SINGLE_INDEX_TABLE   \
  {  1, 0  }, \
  {  2, 1  }, \
  {  4, 2  }, \
  {  8, 3  }, \
  { 16, 4  }
*/

#ifndef FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS


#if 0
  #if  (defined(SWC_FUEL_ADAPT_B03)) 
  #define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE          (18u)
        
        /* fuel sensor resistance with 0.1 resolution vs fuel percent*/
  #define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL   \
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
  
  #elif (defined(SWC_FUEL_ADAPT_B02)) 
  
  #define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE          (18u)
          
          /* fuel sensor resistance with 0.1 resolution vs fuel percent*/
  #define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL   \
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
  
  
  #elif (defined(SWC_FUEL_ADAPT_P03)) 
  
  #define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE          (33u)
        
        /* fuel sensor resistance with 0.1 resolution vs fuel percent*/
  #define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL   \
        {/*min AD ,max AD */(uint16)(977), (uint16)(2685)},\
        { /*50     ohm*/ (uint16)( 977  ), (uint16)( 254u*256u)},  /* 77+3L */ \
        { /*58.4   ohm*/ (uint16)( 989  ), (uint16)( 61773 )},  /* 76  L */ \
        { /*82.5   ohm*/ (uint16)( 1267 ), (uint16)( 57709 )},  /* 71  L */ \
        { /*89.9   ohm*/ (uint16)( 1357 ), (uint16)( 56896 )},  /* 70  L */ \
        { /*112.2  ohm*/ (uint16)( 1541 ), (uint16)( 54458 )},  /* 67  L */ \
        { /*120    ohm*/ (uint16)( 1619 ), (uint16)( 52832 )},  /* 65  L */ \
        { /*127.5  ohm*/ (uint16)( 1676 ), (uint16)( 50394 )},  /* 62  L */ \
        { /*134.9  ohm*/ (uint16)( 1733 ), (uint16)( 49581 )},  /* 61  L */ \
        { /*142.5  ohm*/ (uint16)( 1788 ), (uint16)( 46330 )},  /* 57  L */ \
        { /*150.4  ohm*/ (uint16)( 1842 ), (uint16)( 44704 )},  /* 55  L */ \
        { /*158.4  ohm*/ (uint16)( 1893 ), (uint16)( 43078 )},  /* 53  L */ \
        { /*166.5  ohm*/ (uint16)( 1944 ), (uint16)( 41453 )},  /* 51  L */ \
        { /*174.7  ohm*/ (uint16)( 1993 ), (uint16)( 39827 )},  /* 49  L */ \
        { /*182.7  ohm*/ (uint16)( 2039 ), (uint16)( 38202 )},  /* 47  L */ \
        { /*191    ohm*/ (uint16)( 2089 ), (uint16)( 36576 )},  /* 45  L */ \
        { /*199    ohm*/ (uint16)( 2125 ), (uint16)( 34138 )},  /* 42  L */ \
        { /*207.1  ohm*/ (uint16)( 2168 ), (uint16)( 30886 )},  /* 38  L */ \
        { /*216    ohm*/ (uint16)( 2209 ), (uint16)( 29261 )},  /* 36  L */ \
        { /*224.7  ohm*/ (uint16)( 2250 ), (uint16)( 27635 )},  /* 34  L */ \
        { /*233.4  ohm*/ (uint16)( 2288 ), (uint16)( 26010 )},  /* 32  L */ \
        { /*242.1  ohm*/ (uint16)( 2326 ), (uint16)( 24384 )},  /* 30  L */ \
        { /*251.1  ohm*/ (uint16)( 2361 ), (uint16)( 22758 )},  /* 28  L */ \
        { /*259.5  ohm*/ (uint16)( 2394 ), (uint16)( 20320 )},  /* 25  L */ \
        { /*268.2  ohm*/ (uint16)( 2427 ), (uint16)( 18694 )},  /* 23  L */ \
        { /*277    ohm*/ (uint16)( 2459 ), (uint16)( 15443 )},  /* 19  L */ \
        { /*287.9  ohm*/ (uint16)( 2496 ), (uint16)( 13818 )},  /* 17  L */ \
        { /*298.8  ohm*/ (uint16)( 2532 ), (uint16)( 12192 )},  /* 15  L */ \
        { /*309.6  ohm*/ (uint16)( 2565 ), (uint16)( 9754  )},  /* 12  L */ \
        { /*321.9  ohm*/ (uint16)( 2603 ), (uint16)( 8128  )},  /* 10  L */ \
        { /*334.1  ohm*/ (uint16)( 2638 ), (uint16)( 6502  )},  /* 8   L */ \
        { /*346    ohm*/ (uint16)( 2670 ), (uint16)( 4877  )},  /* 6   L */ \
        { /*351.2  ohm*/ (uint16)( 2685 ), (uint16)( 4064  )},  /* 5   L */ \
  
  #elif (defined(SWC_FUEL_ADAPT_P05)) 
  
  #define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE          (33u)
  
  #define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL	\
        {(uint16)(881), (uint16)(2679u)},\
        { /* 50.3   ohm*/ (uint16)(881  ), (uint16)(65024 )},  /* 82  L */ \
        { /* 60.8   ohm*/ (uint16)(1018 ), (uint16)(63438 )},  /* 80  L */ \
        { /* 67     ohm*/ (uint16)(1104 ), (uint16)(62645 )},  /* 79  L */ \
        { /* 75.7   ohm*/ (uint16)(1194 ), (uint16)(61852 )},  /* 78  L */ \
        { /* 85.4   ohm*/ (uint16)(1298 ), (uint16)(61059 )},  /* 77  L */ \
        { /* 90.2   ohm*/ (uint16)(1346 ), (uint16)(60266 )},  /* 76  L */ \
        { /* 100.1  ohm*/ (uint16)(1442 ), (uint16)(59473 )},  /* 75  L */ \
        { /* 110.1  ohm*/ (uint16)(1532 ), (uint16)(57887 )},  /* 73  L */ \
        { /* 120    ohm*/ (uint16)(1613 ), (uint16)(57094 )},  /* 72  L */ \
        { /* 130    ohm*/ (uint16)(1691 ), (uint16)(54715 )},  /* 69  L */ \
        { /* 140    ohm*/ (uint16)(1766 ), (uint16)(53129 )},  /* 67  L */ \
        { /* 150    ohm*/ (uint16)(1835 ), (uint16)(51543 )},  /* 65  L */ \
        { /* 154.2  ohm*/ (uint16)(1864 ), (uint16)(49957 )},  /* 63  L */ \
        { /* 166.6  ohm*/ (uint16)(1942 ), (uint16)(46786 )},  /* 59  L */ \
        { /* 174.9  ohm*/ (uint16)(1992 ), (uint16)(44407 )},  /* 56  L */ \
        { /* 183.2  ohm*/ (uint16)(2039 ), (uint16)(42028 )},  /* 53  L */ \
        { /* 191.8  ohm*/ (uint16)(2086 ), (uint16)(39649 )},  /* 50  L */ \
        { /* 200.1  ohm*/ (uint16)(2133 ), (uint16)(37270 )},  /* 47  L */ \
        { /* 208.3  ohm*/ (uint16)(2171 ), (uint16)(34891 )},  /* 44  L */ \
        { /* 216.8  ohm*/ (uint16)(2211 ), (uint16)(32512 )},  /* 41  L */ \
        { /* 229.2  ohm*/ (uint16)(2268 ), (uint16)(29340 )},  /* 37  L */ \
        { /* 237.6  ohm*/ (uint16)(2303 ), (uint16)(26961 )},  /* 34  L */ \
        { /* 241.7  ohm*/ (uint16)(2321 ), (uint16)(26168 )},  /* 33  L */ \
        { /* 249.9  ohm*/ (uint16)(2354 ), (uint16)(23789 )},  /* 30  L */ \
        { /* 254.9  ohm*/ (uint16)(2374 ), (uint16)(22996 )},  /* 29  L */ \
        { /* 259.9  ohm*/ (uint16)(2393 ), (uint16)(21410 )},  /* 27  L */ \
        { /* 269.6  ohm*/ (uint16)(2431 ), (uint16)(19031 )},  /* 24  L */ \
        { /* 289.6  ohm*/ (uint16)(2500 ), (uint16)(15067 )},  /* 19  L */ \
        { /* 310    ohm*/ (uint16)(2566 ), (uint16)(11102 )},  /* 14  L */ \
        { /* 334.6  ohm*/ (uint16)(2638 ), (uint16)(6344  )},  /* 8  L */ \
        { /* 344.7  ohm*/ (uint16)(2666 ), (uint16)(4758  )},  /* 6  L */ \
        { /* 349.9  ohm*/ (uint16)(2679 ), (uint16)(3965  )},  /* 5  L */ \
  
  #elif (defined(SWC_FUEL_ADAPT_A07)) 
  #define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE          (18u)
          
          /* fuel sensor resistance with 0.1 resolution vs fuel percent*/
  #define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL   \
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
  
  #endif 
#endif 



#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE1          (19u)

#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL1   \
  {(uint16)875	, (uint16)2678		},	/*  table entry MIN MAX*/   \
  {(uint16)875	, (uint16)254*256	},  /*  50ohm     59L*/			\
  {(uint16)963 ,  (uint16)63921     },  /*  56.5ohm   58L*/	  	    \
  {(uint16)1198	, (uint16)59513  	},  /*  76.1ohm   54L*/			\
  {(uint16)1460	, (uint16)55105  	},  /*  102.2ohm  50L*/		    \
  {(uint16)1627	, (uint16)50697 	},  /*  121.7ohm  46L*/			\
  {(uint16)1726	, (uint16)47390 	},  /*  134.8ohm  43L*/		    \
  {(uint16)1863 , (uint16)42982 	},  /*  154.3ohm  39L*/			\
  {(uint16)1984	, (uint16)38574 	},  /*  173.9ohm  35L*/		    \
  {(uint16)2059 , (uint16)35267  	},  /*  187ohm    32L*/		    \
  {(uint16)2159 , (uint16)31961     },  /*  206.5ohm  29L*/    	    \
  {(uint16)2223 , (uint16)28655	    },  /*  219.6ohm  26L*/		    \
  {(uint16)2308 , (uint16)25348	    },  /*  239.1ohm  23L*/ 		\
  {(uint16)2362 , (uint16)22042	    },  /*  252.2ohm  20L*/ 	    \
  {(uint16)2436 , (uint16)18736	    },  /*  271.7ohm  17L*/ 	    \
  {(uint16)2482 , (uint16)15429	    },  /*  284.8ohm  14L*/ 	    \
  {(uint16)2504 , (uint16)14327 	},  /*  291.3ohm  13L*/ 	    \
  {(uint16)2567 , (uint16)11021 	},	/*  310.9ohm  10L*/         \
  {(uint16)2678 , (uint16)5510		},	/*  350ohm     5L*/			\

#elif
#if (FUEL_SINGLE_SCEM_NUMBER_OF_FUEL_TANKS>1)
#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE           (20u)
#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL   \
{ \
  {   9u*256u, 254u*256u      }, /* Min/max */  \
  {   9u*256u, 246u*256u      }, /* Short Threshold */  \
  {  22u*256u, 233u*256u      }, /* Full */     \
  {  36u*256u, 219u*256u      },                \
  {  49u*256u, 206u*256u      },                \
  {  62u*256u, 193u*256u      },                \
  {  75u*256u, 180u*256u      }, /* 3/4 */      \
  {  87u*256u, 168u*256u      },                \
  {  99u*256u, 156u*256u      },                \
  { 110u*256u, 145u*256u      },                \
  { 121u*256u, 134u*256u      }, /* 1/2 */      \
  { 138u*256u, 117u*256u      },                \
  { 153u*256u, 102u*256u      },                \
  { 163u*256u,  87u*256u      },                \
  { 182u*256u,  73u*256u      }, /* 1/4 */      \
  { 190u*256u,  65u*256u      },                \
  { 199u*256u,  56u*256u      }, /* 1/8 */      \
  { 219u*256u,  36u*256u      },                \
  { 243u*256u,  12u*256u      }, /* Empty */    \
  { 254u*256u,   0u*256u      }  /* Open Threshold */ \
}, \
{ \
  {   9u*256u, 254u*256u      }, /* Min/max */  \
  {   9u*256u, 246u*256u      }, /* Short Threshold */  \
  {  22u*256u, 233u*256u      }, /* Full */     \
  {  36u*256u, 219u*256u      },                \
  {  49u*256u, 206u*256u      },                \
  {  62u*256u, 193u*256u      },                \
  {  75u*256u, 180u*256u      }, /* 3/4 */      \
  {  87u*256u, 168u*256u      },                \
  {  99u*256u, 156u*256u      },                \
  { 110u*256u, 145u*256u      },                \
  { 121u*256u, 134u*256u      }, /* 1/2 */      \
  { 138u*256u, 117u*256u      },                \
  { 153u*256u, 102u*256u      },                \
  { 163u*256u,  87u*256u      },                \
  { 182u*256u,  73u*256u      }, /* 1/4 */      \
  { 190u*256u,  65u*256u      },                \
  { 199u*256u,  56u*256u      }, /* 1/8 */      \
  { 219u*256u,  36u*256u      },                \
  { 243u*256u,  12u*256u      }, /* Empty */    \
  { 254u*256u,   0u*256u      }  /* Open Threshold */ \
}, \
{ \
  {   9u*256u, 254u*256u      }, /* Min/max */  \
  {   9u*256u, 246u*256u      }, /* Short Threshold */  \
  {  22u*256u, 233u*256u      }, /* Full */     \
  {  36u*256u, 219u*256u      },                \
  {  49u*256u, 206u*256u      },                \
  {  62u*256u, 193u*256u      },                \
  {  75u*256u, 180u*256u      }, /* 3/4 */      \
  {  87u*256u, 168u*256u      },                \
  {  99u*256u, 156u*256u      },                \
  { 110u*256u, 145u*256u      },                \
  { 121u*256u, 134u*256u      }, /* 1/2 */      \
  { 138u*256u, 117u*256u      },                \
  { 153u*256u, 102u*256u      },                \
  { 163u*256u,  87u*256u      },                \
  { 182u*256u,  73u*256u      }, /* 1/4 */      \
  { 190u*256u,  65u*256u      },                \
  { 199u*256u,  56u*256u      }, /* 1/8 */      \
  { 219u*256u,  36u*256u      },                \
  { 243u*256u,  12u*256u      }, /* Empty */    \
  { 254u*256u,   0u*256u      }  /* Open Threshold */ \
}
#endif
#endif

#define FUEL_SINGLE_CANFLPS_SIZE                         (16u)
#define FUEL_SINGLE_CAN_FLPS   \
  {  12u*256u, 255u*256u      }, /* Min/max */  \
  {  12u*256u, 255u*256u      }, /* Short   */  \
  {  24u*256u, 251u*256u      }, /* F Stop  */  \
  {  35u*256u, 242u*256u      }, /* F       */  \
  {  66u*256u, 185u*256u      }, /* 3/4     */  \
  { 110u*256u, 127u*256u      }, /* 1/2     */  \
  { 158u*256u,  70u*256u      }, /* 1/4     */  \
  { 226u*256u,  12u*256u      }, /* E       */  \
  { 241u*256u,   3u*256u      }, /* E Stop  */  \
  { 254u*256u,   1u*256u      },                \
  { 255u*256u,   0u*256u      }, /* Open    */  \
  { 255u*256u, 255u*256u      }, /* Extra   */  \
  { 255u*256u, 255u*256u      }, /* Extra   */  \
  { 255u*256u, 255u*256u      }, /* Extra   */  \
  { 255u*256u, 255u*256u      }, /* Extra   */  \
  { 255u*256u, 255u*256u      }  /* Extra   */


/*#define FUEL_SINGLE_LOG_INIT_ERRORS_TO_NVM*/

/*#define FUEL_SINGLE_LOG_FAULT_RECORD_SIZE                (5u)*/

/*#define FUEL_SINGLE_RAM_LOG_FAULT_RECORD_SIZE            (5u)*/

#define FUEL_SINGLE_AVG_VOL_INVALID_TIME                 (0u)

#define FUEL_SINGLE_FILTER_RES                           (1u)

#define FUEL_SINGLE_MIN_FAST_FILL_TIME                   Fuel_Api_Config_Data_NVM_Pkg_Get_Data(11)//(30u)   /* enter fastfill 3 sec  */

/*#define FUEL_SINGLE_GET_FUEL_SCEM()                      (f_scem_get_fuel_scem_byte())*/

#define FUEL_SINGLE_FAST_FILL_MET_MACRO()                (Fuel_Single_Api_Get_Fast_Fill_Speed_Check())

/**********************************************************************************************************
*Description: Obtain the reference value of oil to judge the speed                                        *
**********************************************************************************************************/
#define FUEL_SINGLE_ZSS_MET_MACRO()                      (Fuel_Single_Zss_Speed_Check())

#define FUEL_SINGLE_FUEL_LOW_STATUS()                	 (Fuel_Single_Api_Get_Fuel_Low_Status())

#define FUEL_SINGLE_ENGINE_RUNNING_STATUS()              (Fuel_Api_Get_EngSpd_State())

#define FUEL_SINGLE_POWER_MODE_MACRO()                   ((boolean)FALSE)

#define FUEL_SINGLE_VALID_CONDITION()                    ((boolean)TRUE)

#define FUEL_SINGLE_LOW_VOLTAGE()                          (FALSE)

#define FUEL_SINGLE_IFC_AVG_RATE()                        (Fuel_Rte_Api_Get_IFC_10S_Rate())


/*#define FUEL_SINGLE_NEED_DTC_LOGGING*/

#define FUEL_SINGLE_DTC_LOGGING_ACTIVE()                 ((boolean)0)

#define FUEL_SINGLE_LOG_FUEL_SENDER_CKT_OPEN()    
#define FUEL_SINGLE_CLR_FUEL_SENDER_CKT_OPEN()    

#define FUEL_SINGLE_LOG_FUEL_SENDER_CKT_SHORT()   
#define FUEL_SINGLE_CLR_FUEL_SENDER_CKT_SHORT()   

/*#define FUEL_SINGLE_NEED_DIAG_SELF_TEST*/
/*#define FUEL_SINGLE_GET_LEVEL_SENDER_A() */

/*#define FUEL_SINGLE_NEED_DIAG_EPILOG*/


// TRUE:Enable fuel leaking fun; FALSE:Disable fuel leaking fun
#define FUEL_SINGLE_LEAKING_ENABLE  (1)

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



