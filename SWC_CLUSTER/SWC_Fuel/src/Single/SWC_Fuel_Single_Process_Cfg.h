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

#ifndef FUEL_SINGLE_PROCESS_CFG_H
#define FUEL_SINGLE_PROCESS_CFG_H
/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "SWC_Fuel_Api_Rte_Adapt.h"

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
*																								          *
*																								          *
*	              Type Definition																		  *
*																								          *
*																								          *
**********************************************************************************************************/
#define FUEL_A07_NEW_VHR

#define FUEL_SINGLE_TANK_SIZE_N01 (61u)
#define FUEL_SINGLE_TANK_SIZE_N02 (52u)
#define FUEL_SINGLE_TANK_SIZE_N03 (80u)
#define FUEL_SINGLE_TANK_SIZE_N04 (82u)
#ifndef FUEL_A07_NEW_VHR
#define FUEL_SINGLE_TANK_SIZE_N05 (57u)
#else
#define FUEL_SINGLE_TANK_SIZE_N05 (55u)
#endif
#define FUEL_SINGLE_TANK_SIZE_N07 (100u)
#define FUEL_SINGLE_TANK_SIZE_N08 (85u)
#define FUEL_SINGLE_TANK_SIZE_N09 (128u)

#define FUEL_SINGLE_TANK_DEAD_N01 (5000u)
#define FUEL_SINGLE_TANK_DEAD_N02 (3000u)
#define FUEL_SINGLE_TANK_DEAD_N03 (7000u)
#define FUEL_SINGLE_TANK_DEAD_N04 (6000u)
#ifndef FUEL_A07_NEW_VHR
#define FUEL_SINGLE_TANK_DEAD_N05 (3000u)
#else
#define FUEL_SINGLE_TANK_DEAD_N05 (2960u)
#endif
#define FUEL_SINGLE_TANK_DEAD_N07 (5000u)
#define FUEL_SINGLE_TANK_DEAD_N08 (3400u)
#define FUEL_SINGLE_TANK_DEAD_N09 (6350u)



    /***3¡ê1?¦Ì£¤¨®¨ª??¨°???¨º?¡À¨ª??******************************************************************************/
#define FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N01                    (6u)  
#define FUEL_SINGLE_DISPALY_BAR_TBL_COMMON_N01   \
    {{(uint16)5329    , (uint16)61826     },  /*  table entry     */      \
    {(uint16)5329     , (uint16)0         },  /*  Empty E-5L   0%     */      \
    {(uint16)19187    , (uint16)250       },  /*  1/4     25.0%   */      \
    {(uint16)33045    , (uint16)500       },  /*  2/4     50.0%   */      \
    {(uint16)46903    , (uint16)750       },  /*  3/4     75.0%   */      \
    {(uint16)61826    , (uint16)1000      }}  /*  4/4   F-58L 100.0%*/        \
    /***3¡ê1?¦Ì£¤¨®¨ª???t??¨º?¡À¨ª??******************************************************************************/
#define FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N02                    (6u)  
#define FUEL_SINGLE_DISPALY_BAR_TBL_COMMON_N02   \
    {{(uint16)5329    , (uint16)61826     },  /*  table entry     */      \
    {(uint16)5329     , (uint16)0         },  /*  Empty E-5L   0%     */      \
    {(uint16)19187    , (uint16)250       },  /*  1/4     25.0%   */      \
    {(uint16)33045    , (uint16)500       },  /*  2/4     50.0%   */      \
    {(uint16)46903    , (uint16)750       },  /*  3/4     75.0%   */      \
    {(uint16)61826    , (uint16)1000      }}  /*  4/4   F-58L 100.0%*/        \
    /***3¡ê1?¦Ì£¤¨®¨ª??¨¨y??¨º?¡À¨ª??******************************************************************************/
#define FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N03                    (6u)        
#define FUEL_SINGLE_DISPALY_BAR_TBL_COMMON_N03   \
    {{(uint16)5690 ,     (uint16)61773     },  /*  table entry     */      \
    {(uint16)5690     , (uint16)0         },  /*  Empty  2+1=3L    0%     */      \
    {(uint16)16256    , (uint16)250       },  /*  1/4    16+1=17L  25.0%  */      \
    {(uint16)31699    , (uint16)500       },  /*  2/4    26+4=30L  50.0%  */      \
    {(uint16)47955    , (uint16)750       },  /*  3/4    26+17=43L  75.0% */      \
    {(uint16)61773    , (uint16)1000      }} /*  4/4    28.5+26.5=55L  100.0%    */\
    /***3¡ê1?¦Ì£¤¨®¨ª??????¨º?¡À¨ª??******************************************************************************/
#define FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N04                    (6u) 
#define FUEL_SINGLE_DISPALY_BAR_TBL_COMMON_N04	\
    {{(uint16)4758 ,     (uint16)60266     },  /*  table entry     */      \
    {(uint16)4758     , (uint16)0         },  /*  Empty  2+1=3L    0%     */      \
    {(uint16)15860    , (uint16)250       },  /*  1/4    16+1=17L  25.0%  */      \
    {(uint16)31719    , (uint16)500       },  /*  2/4    26+4=30L  50.0%  */      \
    {(uint16)47579    , (uint16)750       },  /*  3/4    26+17=43L  75.0% */      \
    {(uint16)60266    , (uint16)1000      }} /*  4/4    28.5+26.5=55L  100.0%    */\
     /***3¡ê1?¦Ì£¤¨®¨ª??????¨º?¡À¨ª??******************************************************************************/

#ifndef FUEL_A07_NEW_VHR

#define FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N05                    (6u) 
#define FUEL_SINGLE_DISPALY_BAR_TBL_COMMON_N05	\
            {{(uint16)3422 ,     (uint16)55898     },  /*  table entry     */      \
            {(uint16)3422     , (uint16)0         },  /*  Empty  2+1=3L    0%     */      \
            {(uint16)15971    , (uint16)250       },  /*  1/4    16+1=17L  25.0%  */      \
            {(uint16)30801    , (uint16)500       },  /*  2/4    26+4=30L  50.0%  */      \
            {(uint16)43349    , (uint16)750       },  /*  3/4    26+17=43L  75.0% */      \
            {(uint16)55898    , (uint16)1000      }} /*  4/4    28.5+26.5=55L  100.0%    */\

#else

#define FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N05                    (10u)
#define FUEL_SINGLE_DISPALY_BAR_TBL_COMMON_N05	\
            {{(uint16)3499     , (uint16)60922     },  /*  table entry     */      \
            { (uint16)3499     , (uint16)0         },  /*  Empty  2.96L    0%    */      \
            { (uint16)10416    , (uint16)125       },  /*  1/8    8.81L   12.5%  */      \
            { (uint16)17639    , (uint16)250       },  /*  2/8    14.92L  25.0%  */      \
            { (uint16)24863    , (uint16)375       },  /*  3/8    21.03L  37.5%  */      \
            { (uint16)31684    , (uint16)500       },  /*  4/8    26.8L   50.0%  */      \
            { (uint16)39842    , (uint16)625       },  /*  5/8    33.7L   62.5%  */      \
            { (uint16)45978    , (uint16)750       },  /*  6/8    38.89L  75.0%  */      \
            { (uint16)53651    , (uint16)875       },  /*  7/8    45.38L  87.5%  */      \
            { (uint16)60922    , (uint16)1000      }}  /*  8/8    51.53L  100.0% */      \

#endif


#define FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N07                    (10u) 
#define FUEL_SINGLE_DISPALY_BAR_TBL_COMMON_N07	\
     {{(uint16)3251 ,     (uint16)61773    },  /*  table entry           */\
     {(uint16)3251     , (uint16)0         },  /*  Empty  5L    0%       */\
     {(uint16)11152    , (uint16)125       },  /*  1/8    17.15L  12.5%  */\
     {(uint16)18779    , (uint16)250       },  /*  2/8    28.88L  25.0%  */\
     {(uint16)24644    , (uint16)375       },  /*  3/8    37.90L  37.5%  */\
     {(uint16)32564    , (uint16)500       },  /*  4/8    50.08L  50.0%  */\
     {(uint16)40120    , (uint16)625       },  /*  5/8    61.70L  62.5%  */\
     {(uint16)47702    , (uint16)750       },  /*  6/8    73.36L  75.0%  */\
     {(uint16)55114    , (uint16)875       },  /*  7/8    84.76L  87.5%  */\
     {(uint16)61773    , (uint16)1000      }}  /*  8/8    95.00L  100.0% */\
/*************************************************************************************************************/

#define FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N08                    (10u)
#define FUEL_SINGLE_DISPALY_BAR_TBL_COMMON_N08	\
            {{(uint16)2601 ,     (uint16)61773    },  /*  table entry           */ \
            {(uint16)2601     , (uint16)0         },  /*  Empty  3.40L    0%    */ \
            {(uint16)8927     , (uint16)125       },  /*  1/8    11.67L  12.5%  */ \
            {(uint16)17732    , (uint16)250       },  /*  1/4    23.18L  25.0%  */ \
            {(uint16)24571    , (uint16)375       },  /*  3/8    32.12L  37.5%  */ \
            {(uint16)31839    , (uint16)500       },  /*  2/4    41.62L  50.0%  */ \
            {(uint16)38655    , (uint16)625       },  /*  5/8    50.53L  62.5%  */ \
            {(uint16)47452    , (uint16)750       },  /*  3/4    62.03L  75.0%  */ \
            {(uint16)54299    , (uint16)875       },  /*  7/8    70.98L  87.5%  */ \
            {(uint16)61773    , (uint16)1000      }}  /*  4/4    80.75L  100.0% */ \
/*************************************************************************************************************/
#define FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N09                    (10u) 
#define FUEL_SINGLE_DISPALY_BAR_TBL_COMMON_N09	\
     {{(uint16)3226 ,     (uint16)61651    },  /*  table entry           */\
     {(uint16)3226     , (uint16)0         },  /*  Empty  5L    0%       */\
     {(uint16)10450    , (uint16)125       },  /*  1/8    20.57L  12.5%  */\
     {(uint16)17958    , (uint16)250       },  /*  2/8    35.35L  25.0%  */\
     {(uint16)25232    , (uint16)375       },  /*  3/8    49.67L  37.5%  */\
     {(uint16)32507    , (uint16)500       },  /*  4/8    63.99L  50.0%  */\
     {(uint16)39710    , (uint16)625       },  /*  5/8    78.17L  62.5%  */\
     {(uint16)47112    , (uint16)750       },  /*  6/8    92.74L  75.0%  */\
     {(uint16)54503    , (uint16)875       },  /*  7/8    107.29L 87.5%  */\
     {(uint16)61651    , (uint16)1000      }}  /*  8/8    128.00L 100.0% */\


#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N01          (18u)
      
      /* fuel sensor resistance with 0.1 resolution vs fuel percent*/
#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_N01   \
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
  
#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N02           (18u)
        
        /* fuel sensor resistance with 0.1 resolution vs fuel percent*/
#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_N02    \
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
  
#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N03          (35u)
      
      /* fuel sensor resistance with 0.1 resolution vs fuel percent*/
#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_N03   \
      {/*min AD ,max AD */(uint16)(875), (uint16)(2685)},\
      { /*50     ohm*/ (uint16)( 875  ), (uint16)( 254u*256u)},  /* 77+3L */ \
      { /*58.4   ohm*/ (uint16)( 989  ), (uint16)( 61773 )},  /* 76  L */ \
      { /*66.4   ohm*/ (uint16)( 1085 ), (uint16)( 60960 )},  /* 75  L */ \
      { /*74.4   ohm*/ (uint16)( 1177 ), (uint16)( 60147 )},  /* 74  L */ \
      { /*82.4   ohm*/ (uint16)( 1267 ), (uint16)( 58522 )},  /* 72  L */ \
      { /*89.9   ohm*/ (uint16)( 1357 ), (uint16)( 56896 )},  /* 70  L */ \
      { /*112.2  ohm*/ (uint16)( 1541 ), (uint16)( 54051 )},  /* 66.5  L */ \
      { /*120    ohm*/ (uint16)( 1619 ), (uint16)( 52426 )},  /* 64.5  L */ \
      { /*127.5  ohm*/ (uint16)( 1676 ), (uint16)( 50800 )},  /* 62.5  L */ \
      { /*134.9  ohm*/ (uint16)( 1733 ), (uint16)( 49581 )},  /* 61  L */ \
      { /*142.5  ohm*/ (uint16)( 1788 ), (uint16)( 47955 )},  /* 59  L */ \
      { /*150.4  ohm*/ (uint16)( 1842 ), (uint16)( 45110 )},  /* 55.5  L */ \
      { /*158.4  ohm*/ (uint16)( 1893 ), (uint16)( 43484 )},  /* 53.5  L */ \
      { /*166.5  ohm*/ (uint16)( 1944 ), (uint16)( 41589 )},  /* 51.5  L */ \
      { /*174.7  ohm*/ (uint16)( 1993 ), (uint16)( 40233 )},  /* 49.5  L */ \
      { /*182.7  ohm*/ (uint16)( 2039 ), (uint16)( 38608 )},  /* 47.5  L */ \
      { /*191    ohm*/ (uint16)( 2089 ), (uint16)( 36982 )},  /* 45.5  L */ \
      { /*199    ohm*/ (uint16)( 2125 ), (uint16)( 34950 )},  /* 43  L */ \
      { /*207.1  ohm*/ (uint16)( 2168 ), (uint16)( 31699 )},  /* 39  L */ \
      { /*216    ohm*/ (uint16)( 2209 ), (uint16)( 29667 )},  /* 36.5  L */ \
      { /*224.7  ohm*/ (uint16)( 2250 ), (uint16)( 28042 )},  /* 34.5  L */ \
      { /*233.4  ohm*/ (uint16)( 2288 ), (uint16)( 26416 )},  /* 32.5  L */ \
      { /*242.1  ohm*/ (uint16)( 2326 ), (uint16)( 24790 )},  /* 30.5  L */ \
      { /*251.1  ohm*/ (uint16)( 2361 ), (uint16)( 23165 )},  /* 28.5  L */ \
      { /*259.5  ohm*/ (uint16)( 2394 ), (uint16)( 21133 )},  /* 25.5  L */ \
      { /*268.2  ohm*/ (uint16)( 2427 ), (uint16)( 19101 )},  /* 23.5  L */ \
      { /*277    ohm*/ (uint16)( 2459 ), (uint16)( 16256 )},  /* 20  L */ \
      { /*287.9  ohm*/ (uint16)( 2496 ), (uint16)( 14224 )},  /* 17.5  L */ \
      { /*298.8  ohm*/ (uint16)( 2532 ), (uint16)( 13005 )},  /* 16  L */ \
      { /*309.6  ohm*/ (uint16)( 2565 ), (uint16)( 10566  )},  /* 13  L */ \
      { /*321.8  ohm*/ (uint16)( 2602 ), (uint16)( 8941  )},  /* 11  L */ \
      { /*334.1  ohm*/ (uint16)( 2638 ), (uint16)( 6909  )},  /* 8.5   L */ \
      { /*346    ohm*/ (uint16)( 2670 ), (uint16)( 5690  )},  /* 7   L */ \
      { /*351.2  ohm*/ (uint16)( 2685 ), (uint16)( 4064  )},  /* 5   L */ \
  
#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N04          (33u)
    
#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_N04	\
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
      { /* 249.9  ohm*/ (uint16)(2354 ), (uint16)(24582 )},  /* 31  L */ \
      { /* 254.9  ohm*/ (uint16)(2374 ), (uint16)(22996 )},  /* 29  L */ \
      { /* 259.9  ohm*/ (uint16)(2393 ), (uint16)(21410 )},  /* 27  L */ \
      { /* 269.6  ohm*/ (uint16)(2431 ), (uint16)(19031 )},  /* 24  L */ \
      { /* 289.6  ohm*/ (uint16)(2500 ), (uint16)(15067 )},  /* 19  L */ \
      { /* 310    ohm*/ (uint16)(2566 ), (uint16)(11102 )},  /* 14  L */ \
      { /* 334.6  ohm*/ (uint16)(2638 ), (uint16)(6344  )},  /* 8  L */ \
      { /* 344.7  ohm*/ (uint16)(2666 ), (uint16)(4758  )},  /* 6  L */ \
      { /* 349.9  ohm*/ (uint16)(2679 ), (uint16)(3965  )},  /* 5  L */ \

#ifndef FUEL_A07_NEW_VHR

#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N05          (25u)
                /* fuel sensor resistance with 0.1 resolution vs fuel percent*/
#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_N05   \
                  {(uint16)889  , (uint16)2680      },  /*  table entry MIN MAX*/   \
                  {(uint16)889  , (uint16)254*256   },  /*  51.13ohm     57L*/         \
                  {(uint16)1011 ,  (uint16)55898     }, /*  61.45ohm   49L*/         \
                  {(uint16)1135 ,  (uint16)53616     }, /*  71.08ohm   47L*/         \
                  {(uint16)1239 ,  (uint16)51335     }, /*  80.966ohm   45L*/         \
                  {(uint16)1422 ,  (uint16)49053     }, /*  98.26ohm   43L*/         \
                  {(uint16)1499 ,  (uint16)46772     }, /*  106.82ohm   41L*/         \
                  {(uint16)1710 ,  (uint16)43349     }, /*  132.65ohm   38L*/         \
                  {(uint16)1769 ,  (uint16)39927     }, /*  140.78ohm   35L*/         \
                  {(uint16)1836 ,  (uint16)38786     }, /*  150.33ohm   34L*/         \
                  {(uint16)1892 , (uint16)36505     },  /*  158.98ohm   32L*/         \
                  {(uint16)2001 , (uint16)34223     },  /*  176.96ohm  30L*/         \
                  {(uint16)2050 , (uint16)31942     },  /*  185.77ohm  28L*/         \
                  {(uint16)2100 , (uint16)30801     },  /*  194.8ohm  27L*/         \
                  {(uint16)2146 , (uint16)29660     },  /*  203.91ohm  26L*/         \
                  {(uint16)2190 , (uint16)26238     },  /*  212.94ohm23L*/         \
                  {(uint16)2231 , (uint16)25097     },  /*  221.59ohm    22L*/         \
                  {(uint16)2270 , (uint16)22815     },  /*  230.29ohm  20L*/         \
                  {(uint16)2347 , (uint16)20534     },  /*  248.71ohm    18L*/         \
                  {(uint16)2383 , (uint16)18252     },  /*  257.74ohm  16L*/         \
                  {(uint16)2451 , (uint16)15971     },  /*  276.05ohm  14L*/         \
                  {(uint16)2504 , (uint16)13689     },  /*  291.48ohm  12L*/         \
                  {(uint16)2558 , (uint16)10267     },  /*  308.49ohm  9L*/         \
                  {(uint16)2617 , (uint16)6845     },   /*  328.26ohm  6L*/         \
                  {(uint16)2680 , (uint16)3422      },  /*  351.1ohm   3L*/         \
        
          /*ï¿½ï¿½?????ï¿½ï¿½?D?ï¿½ï¿½???ï¿½ï¿½?TBL ï¿½ï¿½yï¿½ï¿½?ï¿½ï¿½ï¿½ï¿½3?ï¿½ï¿½??? */

#else
#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N05          (39u)

#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_N05   \
              {(uint16)875    , (uint16)2669   },   /*  table entry MIN MAX*/ \
              {(uint16)875    , (uint16)65024  },   /*  50ohm      55L      */ \
              {(uint16)1004   , (uint16)60922  },   /*  60ohm      51.53L   */ \
              {(uint16)1124   , (uint16)58486  },   /*  70ohm      49.47L   */ \
              {(uint16)1225   , (uint16)56074  },   /*  78.75ohm   47.43L   */ \
              {(uint16)1316   , (uint16)53651  },   /*  87.5ohm    45.38L   */ \
              {(uint16)1402   , (uint16)52646  },   /*  96.25ohm   44.53L   */ \
              {(uint16)1483   , (uint16)51239  },   /*  105ohm     43.34L   */ \
              {(uint16)1559   , (uint16)49820  },   /*  113.75ohm  42.14L   */ \
              {(uint16)1631   , (uint16)48201  },   /*  122.5ohm   40.77L   */ \
              {(uint16)1699   , (uint16)45978  },   /*  131.25ohm  38.89L   */ \
              {(uint16)1763   , (uint16)44346  },   /*  140 ohm    37.51L   */ \
              {(uint16)1843   , (uint16)42094  },   /*  151.5ohm   35.605L  */ \
              {(uint16)1898   , (uint16)39842  },   /*  160ohm     33.7L    */ \
              {(uint16)1960   , (uint16)38612  },   /*  170ohm     32.66L   */ \
              {(uint16)2052   , (uint16)36153  },   /*  186ohm     30.58L   */ \
              {(uint16)2099   , (uint16)33913  },   /*  194.67ohm  28.685L  */ \
              {(uint16)2143   , (uint16)31684  },   /*  203.34ohm  26.8L    */ \
              {(uint16)2186   , (uint16)30053  },   /*  212ohm     25.42L   */ \
              {(uint16)2241   , (uint16)27641  },   /*  224ohm     23.38L   */ \
              {(uint16)2294   , (uint16)24863  },   /*  236ohm     21.03L   */ \
              {(uint16)2344   , (uint16)23887  },   /*  248ohm     20.205L  */ \
              {(uint16)2391   , (uint16)21753  },   /*  260ohm     18.4L    */ \
              {(uint16)2420   , (uint16)19625  },   /*  267.75ohm  16.6L    */ \
              {(uint16)2449   , (uint16)17639  },   /*  275.5ohm   14.92L   */ \
              {(uint16)2476   , (uint16)16853  },   /*  283.25ohm  14.255L  */ \
              {(uint16)2502   , (uint16)15287  },   /*  291ohm     12.93L   */ \
              {(uint16)2522   , (uint16)13986  },   /*  297ohm     11.83L   */ \
              {(uint16)2541   , (uint16)13052  },   /*  303ohm     11.04L   */ \
              {(uint16)2560   , (uint16)11823  },   /*  309ohm     10L      */ \
              {(uint16)2574   , (uint16)10416  },   /*  313.43ohm  8.81L    */ \
              {(uint16)2587   , (uint16)9712   },   /*  317.86ohm  8.215L   */ \
              {(uint16)2601   , (uint16)8725   },   /*  322.29ohm  7.38L    */ \
              {(uint16)2614   , (uint16)7939   },   /*  326.72ohm  6.715L   */ \
              {(uint16)2626   , (uint16)7153   },   /*  331.15ohm  6.05L    */ \
              {(uint16)2638   , (uint16)6479   },   /*  335.57ohm  5.48L    */ \
              {(uint16)2651   , (uint16)5521   },   /*  340ohm     4.67L    */ \
              {(uint16)2660   , (uint16)4493   },   /*  343.33ohm  3.8L     */ \
              {(uint16)2669   , (uint16)3499   },   /*  346.66ohm  2.96L    */ \

#endif

#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N07          (34u)
      
#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_N07	\
        {(uint16)(874), (uint16)(2678u)},\
        { /* 50     ohm*/ (uint16)(874  ), (uint16)(65024 )},  /* 100.00 L */ \
        { /* 64.3   ohm*/ (uint16)(1058 ), (uint16)(61773 )},  /* 95.00  L */ \
        { /* 71.4   ohm*/ (uint16)(1142 ), (uint16)(59910 )},  /* 92.14  L */ \
        { /* 78.6   ohm*/ (uint16)(1222 ), (uint16)(58421 )},  /* 89.85  L */ \
        { /* 85.7   ohm*/ (uint16)(1297 ), (uint16)(56870 )},  /* 87.46  L */ \
        { /* 92.9   ohm*/ (uint16)(1369 ), (uint16)(55114 )},  /* 84.76  L */ \
        { /* 100    ohm*/ (uint16)(1437 ), (uint16)(53463 )},  /* 82.22  L */ \
        { /* 110    ohm*/ (uint16)(1527 ), (uint16)(51616 )},  /* 79.64  L */ \
        { /* 120    ohm*/ (uint16)(1611 ), (uint16)(49922 )},  /* 76.78  L */ \
        { /* 130    ohm*/ (uint16)(1690 ), (uint16)(47702 )},  /* 73.36  L */ \
        { /* 140    ohm*/ (uint16)(1764 ), (uint16)(46158 )},  /* 70.99  L */ \
        { /* 150    ohm*/ (uint16)(1832 ), (uint16)(44090 )},  /* 67.81  L */ \
        { /* 157.1  ohm*/ (uint16)(1880 ), (uint16)(42022 )},  /* 64.63  L */ \
        { /* 164.3  ohm*/ (uint16)(1925 ), (uint16)(40120 )},  /* 61.70  L */ \
        { /* 171.4  ohm*/ (uint16)(1968 ), (uint16)(38225 )},  /* 58.79  L */ \
        { /* 178.6  ohm*/ (uint16)(2010 ), (uint16)(36511)},   /* 56.15  L */ \
        { /* 185.7  ohm*/ (uint16)(2050 ), (uint16)(34453 )},  /* 52.99  L */ \
        { /* 192.9  ohm*/ (uint16)(2089 ), (uint16)(32564 )},  /* 50.08  L */ \
        { /* 200    ohm*/ (uint16)(2127 ), (uint16)(30675 )},  /* 47.18  L */ \
        { /* 208.3  ohm*/ (uint16)(2167 ), (uint16)(28526 )},  /* 43.87  L */ \
        { /* 216.7  ohm*/ (uint16)(2209 ), (uint16)(26718 )},  /* 41.09  L */ \
        { /* 225    ohm*/ (uint16)(2245 ), (uint16)(24644 )},  /* 37.90  L */ \
        { /* 233.3  ohm*/ (uint16)(2282 ), (uint16)(22914 )},  /* 35.24  L */ \
        { /* 241.7  ohm*/ (uint16)(2318 ), (uint16)(20668 )},  /* 31.79  L */ \
        { /* 250    ohm*/ (uint16)(2352 ), (uint16)(18779 )},  /* 28.88  L */ \
        { /* 260    ohm*/ (uint16)(2391 ), (uint16)(16916 )},  /* 26.01  L */ \
        { /* 270    ohm*/ (uint16)(2428 ), (uint16)(14913 )},  /* 22.94  L */ \
        { /* 280    ohm*/ (uint16)(2465 ), (uint16)(13265 )},  /* 20.40  L */ \
        { /* 290    ohm*/ (uint16)(2499 ), (uint16)(11152 )},  /* 17.15  L */ \
        { /* 300    ohm*/ (uint16)(2532 ), (uint16)(9240 )},   /* 14.21  L */ \
        { /* 320    ohm*/ (uint16)(2593 ), (uint16)(6018 )},   /* 9.25   L */ \
        { /* 330    ohm*/ (uint16)(2623 ), (uint16)(4299 )},   /* 6.61   L */ \
        { /* 350    ohm*/ (uint16)(2678 ), (uint16)(3251 )},   /* 5.00   L */ \
       

#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N08          (30u)
          
#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_N08	\
      {(uint16)(878), (uint16)(2678u)},\
                  { /* 50.0   ohm*/ (uint16)(878 ), (uint16)(65024 )},  /* 85.00 L */ \
                  { /* 100.0  ohm*/ (uint16)(1437 ), (uint16)(61773 )},  /* 80.75 L */ \
                  { /* 110.0  ohm*/ (uint16)(1527 ), (uint16)(60866 )},  /* 79.57 L */ \
                  { /* 120.0  ohm*/ (uint16)(1610 ), (uint16)(58892 )},  /* 76.99 L */ \
                  { /* 130.0  ohm*/ (uint16)(1689 ), (uint16)(56502 )},  /* 73.86 L */ \
                  { /* 140.0  ohm*/ (uint16)(1762 ), (uint16)(54299 )},  /* 70.98 L */ \
                  { /* 150.0  ohm*/ (uint16)(1832 ), (uint16)(52088 )},  /* 68.09 L */ \
                  { /* 157.1  ohm*/ (uint16)(1880 ), (uint16)(49671 )},  /* 64.83 L */ \
                  { /* 164.3  ohm*/ (uint16)(1925 ), (uint16)(47452 )},  /* 62.03 L */ \
                  { /* 171.4  ohm*/ (uint16)(1969 ), (uint16)(45249 )},  /* 59.15 L */ \
                  { /* 178.6  ohm*/ (uint16)(2010 ), (uint16)(43245 )},  /* 56.53 L */ \
                  { /* 185.7  ohm*/ (uint16)(2050 ), (uint16)(40850 )},  /* 53.40 L */ \
                  { /* 192.9  ohm*/ (uint16)(2089 ), (uint16)(38655 )},  /* 50.53 L */ \
                  { /* 200.0  ohm*/ (uint16)(2127 ), (uint16)(36452 )},  /* 47.65 L */ \
                  { /* 208.3  ohm*/ (uint16)(2168 ), (uint16)(34046 )},  /* 44.51 L */ \
                  { /* 216.7  ohm*/ (uint16)(2208 ), (uint16)(31839 )},  /* 41.62 L */ \
                  { /* 225.0  ohm*/ (uint16)(2246 ), (uint16)(29617 )},  /* 38.72 L */ \
                  { /* 233.3  ohm*/ (uint16)(2282 ), (uint16)(27394 )},  /* 35.81 L */ \
                  { /* 241.7  ohm*/ (uint16)(2317 ), (uint16)(24571 )},  /* 32.12 L */ \
                  { /* 250.0  ohm*/ (uint16)(2352 ), (uint16)(22751 )},  /* 29.74 L */ \
                  { /* 260.0  ohm*/ (uint16)(2390 ), (uint16)(20337 )},  /* 26.59 L */ \
                  { /* 270.0  ohm*/ (uint16)(2429 ), (uint16)(17732 )},  /* 23.18 L */ \
                  { /* 280.0  ohm*/ (uint16)(2463 ), (uint16)(15950 )},  /* 20.85 L */ \
                  { /* 290.0  ohm*/ (uint16)(2498 ), (uint16)(13609 )},  /* 17.79 L */ \
                  { /* 300.0  ohm*/ (uint16)(2532 ), (uint16)(11146 )},  /* 14.57 L */ \
                  { /* 310.0  ohm*/ (uint16)(2563 ), (uint16)(8927  )},  /* 11.67 L */ \
                  { /* 320.0  ohm*/ (uint16)(2592 ), (uint16)(7321  )},  /* 9.57 L */ \
                  { /* 330.0  ohm*/ (uint16)(2622 ), (uint16)(5279  )},  /* 6.90 L */ \
                  { /* 350.0  ohm*/ (uint16)(2678 ), (uint16)(2601  )},  /* 3.40 L */ \


#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_SIZE_N09          (37u)
        
#define FUEL_SINGLE_SENDER_A_AD_TO_PF_TBL_N09	\
      {(uint16)(874), (uint16)(2678u)},\
		{ /* 50    ohm*/ (uint16)(874 ),  (uint16)(65024 )},  /* 128 L */\
		{ /* 65    ohm*/ (uint16)(1066 ), (uint16)(61651 )},  /* 121.36L*/ \
		{ /* 71.43 ohm*/ (uint16)(1142 ), (uint16)(59700 )},  /* 117.52L*/ \
		{ /* 77.86 ohm*/ (uint16)(1214 ), (uint16)(57739 )},  /* 113.66L*/ \
		{ /* 81.07 ohm*/ (uint16)(1247 ), (uint16)(56708 )},  /* 111.63L*/ \
		{ /* 87.5  ohm*/ (uint16)(1315 ), (uint16)(54503 )},  /* 107.29L*/ \
		{ /* 98.21 ohm*/ (uint16)(1420 ), (uint16)(52400 )},  /* 103.15L*/ \
		{ /* 103.75ohm*/ (uint16)(1470 ), (uint16)(51394 )},  /* 101.17L*/ \
		{ /* 108.93ohm*/ (uint16)(1518 ), (uint16)(50368 )},  /* 99.15L */ \
		{ /* 114.29ohm*/ (uint16)(1564 ), (uint16)(49332 )},  /* 97.11L */ \
		{ /* 125   ohm*/ (uint16)(1651 ), (uint16)(47112 )},  /* 92.74L */ \
		{ /* 137.5 ohm*/ (uint16)(1745 ), (uint16)(44668 )},  /* 87.93L */ \
		{ /* 143.75ohm*/ (uint16)(1789 ), (uint16)(43459 )},  /* 85.55L */ \
		{ /* 150   ohm*/ (uint16)(1832 ), (uint16)(42240 )},  /* 83.15L */ \
		{ /* 162.5 ohm*/ (uint16)(1914 ), (uint16)(39710 )},  /* 78.17L */ \
		{ /* 175   ohm*/ (uint16)(1990 ), (uint16)(37318 )},  /* 73.46L */ \
		{ /* 181.25ohm*/ (uint16)(2025 ), (uint16)(36165 )},  /* 71.19L */ \
		{ /* 187.5 ohm*/ (uint16)(2060 ), (uint16)(35001 )},  /* 68.90L */ \
		{ /* 200   ohm*/ (uint16)(2126 ), (uint16)(32507 )},  /* 63.99L */ \
		{ /* 212.5 ohm*/ (uint16)(2190 ), (uint16)(30028 )},  /* 59.11L */ \
		{ /* 218.75ohm*/ (uint16)(2218 ), (uint16)(28870 )},  /* 56.83L */ \
		{ /* 225   ohm*/ (uint16)(2247 ), (uint16)(27711 )},  /* 54.55L */ \
		{ /* 237.5 ohm*/ (uint16)(2301 ), (uint16)(25232 )},  /* 49.67L */ \
		{ /* 250   ohm*/ (uint16)(2351 ), (uint16)(22728 )},  /* 44.74L */ \
		{ /* 256.25ohm*/ (uint16)(2376 ), (uint16)(21560 )},  /* 42.44L */ \
		{ /* 262.5 ohm*/ (uint16)(2401 ), (uint16)(20396 )},  /* 40.15L */ \
		{ /* 275   ohm*/ (uint16)(2447 ), (uint16)(17958 )},  /* 35.35L */ \
		{ /* 287.5 ohm*/ (uint16)(2490 ), (uint16)(15423 )},  /* 30.36L */ \
		{ /* 297.35ohm*/ (uint16)(2512 ), (uint16)(14229 )},  /* 28.01L */ \
		{ /* 300   ohm*/ (uint16)(2531 ), (uint16)(13056 )},  /* 25.70L */ \
		{ /* 312.5 ohm*/ (uint16)(2570 ), (uint16)(10450 )},  /* 20.57L */ \
		{ /* 320   ohm*/ (uint16)(2594 ), (uint16)(8712 )},   /* 17.15L */ \
		{ /* 327.5 ohm*/ (uint16)(2616 ), (uint16)(7351 )},   /* 14.47L */ \
		{ /* 335   ohm*/ (uint16)(2638 ), (uint16)(6187 )},   /* 12.18L */ \
		{ /* 342.5 ohm*/ (uint16)(2657 ), (uint16)(5192 )},   /* 10.22L */ \
		{ /* 350   ohm*/ (uint16)(2678 ), (uint16)(3226 )},   /* 6.35L  */ \
      

#define   FUEL_SINGLE_DISPALY_TABLE_MAX  FUEL_VR_COMMMON_SINGLE_MAX
#define   FUEL_VR_COMMMON_SINGLE_MAX_NO  (FUEL_SINGLE_DISPALY_TABLE_MAX)


#ifndef FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX
#define  FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX  24
#else 
  #error FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX must be greater than zero !
#endif
  
  
#if ( (FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N01*2) > FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX)
    #error FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX must be greater than 2*FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N01 !
#endif

#if ( (FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N02*2) > FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX)
    #error FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX must be greater than 2*FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N02 !
#endif

#if ( (FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N03*2) > FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX)
    #error FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX must be greater than 2*FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N03 !
#endif

#if ( (FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N04*2) > FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX)
    #error FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX must be greater than 2*FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N04 !
#endif

#if ( (FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N05*2) > FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX)
    #error FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX must be greater than 2*FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N05 !
#endif

#if ( (FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N07*2) > FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX)
    #error FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX must be greater than 2*FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N07 !
#endif

#if ( (FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N08*2) > FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX)
    #error FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX must be greater than 2*FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N08 !
#endif

#if ( (FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N09*2) > FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX)
    #error FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_MAX must be greater than 2*FUEL_SINGLE_DISPALY_BAR_TBL_SIZE_COMMON_N09 !
#endif








#define FUEL_SINGLE_AD_RESISTOR_TBL_SIZE                    (48u)
/*@20200923:
  Two new parameters are added for detecting short circuit
  and open circuit data in road test*/      
#define FUEL_SINGLE_AD_RESISTOR_TBL   \
  {{(uint16)(117), (uint16)(3456u)},\
  {(uint16)(117 ) , (uint16)(100)  },\
  {(uint16)(218 ) , (uint16)(100)  },\
  {(uint16)(876u), (uint16)(500u)},/*50ohm   34L*/\
  {(uint16)(956u), (uint16)(560u)},/*56ohm    29L*/\
  {(uint16)(1044u),(uint16)(630u)},/*63ohm    28.5L*/\
  {(uint16)(1128u),(uint16)(700u)},/*70ohm    27.5L*/\
  {(uint16)(1185u),(uint16)(750u)},/*75ohm    27L*/\
  {(uint16)(1282u),(uint16)(840u)},/*84ohm    26L*/\
  {(uint16)(1372u),(uint16)(930u)},/*93ohm    25L*/\
  {(uint16)(1439u),(uint16)(1000u)},/*100ohm    24L*/\
  {(uint16)(1538u),(uint16)(1110u)},/*111ohm    23L*/\
  {(uint16)(1629u),(uint16)(1220u)},/*122ohm    22L*/\
  {(uint16)(1786u),(uint16)(1430u)},/*143ohm    21L*/\
  {(uint16)(1854u),(uint16)(1530u)},/*153ohm    20L*/\
  {(uint16)(1918u),(uint16)(1630u)},/*163ohm    19L*/\
  {(uint16)(1979u),(uint16)(1730u)},/*173ohm    18L*/\
  {(uint16)(2091u),(uint16)(1930u)},/*193ohm    17L*/\
  {(uint16)(2142u),(uint16)(2030u)},/*203ohm    16L*/\
  {(uint16)(2182u),(uint16)(2110u)},/*211ohm    15L*/\
  {(uint16)(2265u),(uint16)(2290u)},/*229ohm    14L*/\
  {(uint16)(2299u),(uint16)(2370u)},/*237ohm    13L*/\
  {(uint16)(2369u),(uint16)(2540u)},/*254ohm    12L*/\
  {(uint16)(2430u),(uint16)(2700u)},/*270ohm    11L*/\
  {(uint16)(2458u),(uint16)(2780u)},/*278ohm    10L*/\
  {(uint16)(2489u),(uint16)(2870u)},/*287ohm    9L*/\
  {(uint16)(2532u),(uint16)(3000u)},/*300ohm    8L*/\
  {(uint16)(2560u),(uint16)(3090u)},/*309ohm    7L*/\
  {(uint16)(2573u),(uint16)(3130u)},/*313ohm    6L*/\
  {(uint16)(2603u),(uint16)(3230u)},/*323ohm    5L*/\
  {(uint16)(2626u),(uint16)(3310u)},/*331ohm    4L*/\
  {(uint16)(2651u),(uint16)(3400u)},/*340ohm    3L*/\
  {(uint16)(2670u),(uint16)(3470u)},/*347ohm    2L*/\
  {(uint16)(2678u),(uint16)(3500u)},/*350ohm    1L*/\
  {(uint16)(2798u),(uint16)(4000u)},/*400ohm    1L*/\
  {(uint16)(2901u),(uint16)(4500u)},/*450ohm    1L*/\
  {(uint16)(2987u),(uint16)(5000u)},/*500ohm    1L*/\
  {(uint16)(3062u),(uint16)(5500u)},/*550ohm    1L*/\
  {(uint16)(3128u),(uint16)(6000u)},/*600ohm    1L*/\
  {(uint16)(3186u),(uint16)(6500u)},/*650ohm    1L*/\
  {(uint16)(3237u),(uint16)(7000u)},/*700ohm    1L*/\
  {(uint16)(3283u),(uint16)(7500u)},/*750ohm    1L*/\
  {(uint16)(3324u),(uint16)(8000u)},/*800ohm    1L*/\
  {(uint16)(3362u),(uint16)(8500u)},/*850ohm    1L*/\
  {(uint16)(3396u),(uint16)(9000u)},/*900ohm    1L*/\
  {(uint16)(3426u),(uint16)(9500u)},/*950ohm    1L*/\
  {(uint16)(3455u),(uint16)(10000)},/*1000ohm  1L*/\
  {(uint16)(3456u),(uint16)(65535u)}}\


#define FUEL_SINGLE_MAX_TANK_SIZE ((uint16)TC_TANK_SIZE_NVM)    /*56L*/

#define FUEL_SINGLE_IGN_ACTIVE_POSITION()                   (GPIO_nIGNITION_DBNC_IS_ACTIVE())

#define FUEL_SINGLE_HIGH_VOLT_SHUTDOWN() TRUE//LOW_OR_HIGH_VOLTAGE_SHUTDOWN()

#define FUEL_SINGLE_LOW_VOLT_SHUTDOWN()                     (1 == 0)  /* Make this FALSE */

#define FUEL_SINGLE_HIGH_VOLT_PENDING()                     (1 == 0)  /* Make this FALSE */

#define FUEL_SINGLE_OVERRIDE_ACTIVE()                       (KernelInDiagnosticsMode())

/*
** #define FUEL_SINGLE_INPUT_IS_FROM_NETWORK
*/

/*
** #define FUEL_SINGLE_MSG_NEVER_RXD()
*/

/*
** #define FUEL_SINGLE_MSG_MISSING()
*/

/*
** #define FUEL_SINGLE_MSG_INVALID()
*/

#define FUEL_SINGLE_PARK_POSITION()                         (0u)  //modify by fchao in 20200610  (FuelTableNVM[1][1])

//#define FUEL_SINGLE_ALL_SYNC_READY()                        (ga_sync_all_sync_ready() != 0)
#define FUEL_SINGLE_ALL_SYNC_READY()                        (Fuel_Single_Pkg_Init_Finished()!= 0)//modified by dandan

#define FUEL_SINGLE_FILTER_BYPASS()                         (0)// modify by fchao in 20200610 (EOL_API_boGetFuelDampingOffControlWorkEnableStatus())

#define FUEL_SINGLE_EXECUTION_RATE_IN_MS                    (100u)


/*	#define GA_FUEL_USE_FORD_FF_STRATEGY	*/

#define FUEL_SINGLE_IGN_MODE_RUN()             
#define FUEL_SINGLE_AUTO_TRANS_SELECT()                     (1 == 0)
#define FUEL_SINGLE_GEAR_SELECT_PARK()                      (1 == 0)
#define FUEL_SINGLE_GEAR_SELECT_NEUTRAL()                   (1 == 0)
#define FUEL_SINGLE_GEAR_SELECT_MSG_MISSING()               (1 == 0)
#define FUEL_SINGLE_GEAR_SELECT_MSG_INVALID()               (1 == 0)
#define FUEL_SINGLE_GEAR_SELECT_MSG_UNKNOWN()               (1 == 0)
#define FUEL_SINGLE_VEH_SPEED_MSG_MISSING()                 (1 == 0)
#define FUEL_SINGLE_VEH_SPEED_MSG_INVALID()                 (1 == 0)
#define FUEL_SINGLE_VEH_SPEED_DATA_UNKNOWN()                (1 == 0)
#define FUEL_SINGLE_VEH_SPEED_MSG_NEVER_RECVD()             (1 == 0)
#define FUEL_SINGLE_VEHICLE_SPEED_2KPH                      ((uint16)0x00D8)
#define FUEL_SINGLE_GET_VEHICLE_SPEED()                     (1 == 0)
#define FUEL_SINGLE_ENG_SPEED_MSG_MISSING()                 (1 == 0)
#define FUEL_SINGLE_ENG_SPEED_MSG_INVALID()                 (1 == 0)
#define FUEL_SINGLE_ENG_SPEED_DATA_UNKNOWN()                (1 == 0)
#define FUEL_SINGLE_GET_ENG_SPEED()                         (1 == 0)

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
