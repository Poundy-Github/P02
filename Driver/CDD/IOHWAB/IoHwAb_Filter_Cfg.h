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
/**
 **********************************************************************************************************************
 * @file:      IoHwAb_Filter_Cfg.h
 * @author:    Nobo
 * @date:      2020-5-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _IOHWAB_FILTER_CFG_H_
#define _IOHWAB_FILTER_CFG_H_

#define IOHWAB_MAX_FILTER_COUNT        69 
/**********************************************************************************************************************
 *  CONSTANS & TYPES
 *********************************************************************************************************************/

/*     Define RAM struct used for the filters - contexts.
      One filter instance uses one context.
      For every kind of filter RAM structs are put in array.*/
  
#define IOHWAB_FILTERWRAPPERS_CFG_RAM() \
/* digital */ \
static SIODigitalInputCxt DigitalInputCxt[49] = { \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
    {/*Count =*/ 0, /*FilteredValue =*/ 0}, \
}; \
/* pass through */ \
static SIOPassThroughCxt PassThroughCxt[1] = {\
    {/*FilteredValue =*/ 0}, \
}; \
/* Avg arrays */ \
static uint16 AvgArray0[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray1[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray2[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray3[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray4[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray5[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray6[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray7[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray8[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray9[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray10[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray11[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray12[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray13[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray14[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray15[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray16[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray17[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray18[5]; /* size is tha same as Count in AvgCfg */ \
static uint16 AvgArray19[5]; /* size is tha same as Count in AvgCfg */ \
static SIOAvgCxt AvgCxt[20] = { \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray0}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray1}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray2}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray3}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray4}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray5}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray6}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray7}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray8}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray9}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray10}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray11}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray12}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray13}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray14}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray15}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray16}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray17}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray18}, \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, NULL, 0, 0, 0}, /*pArrayData =*/ AvgArray19}, \
}; \
/* Median arrays */ \
static THwData MedianArray0[1]; /* size is the same as Count in MedianCfg */  \
static SIOMedianCxt MedianCxt[1] = { \
    {/*FilteredValue =*/ 0, /*pArrayData =*/ MedianArray0, /*Next =*/ 0}, \
};  \
/* Median temp array for sort */ \
static THwData MedianTemp[1]; /* size is the max Count in all MedianCfg */ \
/* PT1 */ \
static SIOPT1Cxt PT1Cxt[1] = { \
    {/*FilteredValue =*/ 0, /*FilterData =*/ {0, 0, 0, 0}}, \
}; \
/* button */ \
static SIOAnButtonCxt ABtnCtx[1] = { \
     {/*Count =*/ 0, /*LastValue*/ 0, /*FilteredValue =*/ 0}, \
}; \

/*     Define ROM struct used for the filters - configuration.
       More then one filter can use one and the same configuration.
    For every kind of filter ROM structs are put in array.
    For every filter instance in context index in array is specified.
    Define every filter as "const CIoHwAb_Filter".
    Put filter in array of filters "Filters" - needed for corerct filter initialization.
    @arg EFilterKind - kind of filter.
    @arg CfgIx - Index in array with configurations of this kind of filter.
    @arg CxtIx - Index in array with contexts of this kind of filter.
    @arg Next - pointer to next element in filter chain.*/

#define IOHWAB_FILTERWRAPPERS_CFG_ROM() \
/* Configs and Contexts */ \
static const SIODigitalInputCfg DigitalInputCfg[3] = { \
    {/*Count =*/ 3, /*InitValue =*/ 0}, \
    {/*Count =*/ 5, /*InitValue =*/ 1}, \
    {/*Count =*/ 10, /*InitValue =*/ 0}, \
}; \
static const SIOAvgCfg AvgCfg[2] = { \
    {/*Count =*/ 5, /*InitValue =*/ 0}, \
    {/*Count =*/ 5, /*InitValue =*/ 0}, \
}; \
static const SIOPT1Cfg PT1Cfg[2] = { \
    {/*DampingTime =*/ 5, /*InitValue =*/ 0}, \
    {/*DampingTime =*/ 10, /*InitValue =*/ 0}, \
}; \
static const SIOPassThroughCfg PassThroughCfg[2] = { \
    {/*InitValue =*/ 0}, \
    {/*InitValue =*/ 1}, \
}; \
static const SIOMedianCfg MedianCfg[2] = { \
    {/*Count =*/ 5, /*InitValue =*/ 0}, \
    {/*Count =*/ 10, /*InitValue =*/ 0}, \
}; \
static const SIOAnButtonCfg ABtnCfg[1] = { \
    { \
        /*InitValue =*/ 0, \
        { \
            /*AdcMax[0]*/ 0, \
            /*AdcMax[1]*/ 0, \
            /*AdcMax[2]*/ 0, \
            /*AdcMax[3]*/ 0, \
            /*AdcMax[4]*/ 0, \
            /*AdcMax[5]*/ 0, \
            /*AdcMax[6]*/ 0, \
        }, \
        { \
            /*AdcMin[0]*/ 0, \
            /*AdcMin[1]*/ 0, \
            /*AdcMin[2]*/ 0, \
            /*AdcMin[3]*/ 0, \
            /*AdcMin[4]*/ 0, \
            /*AdcMin[5]*/ 0, \
            /*AdcMin[6]*/ 0, \
        }, \
        /*AdcCount*/ 0, \
        /*FilterCount*/ 0 \
    } \
}; \
  \
/* Filters */ \
const SIOFilterHandler Filters[IOHWAB_MAX_FILTER_COUNT] = { \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/0}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/1}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/2}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/3}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/4}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/5}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/6}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/7}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/8}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/9}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/10}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/11}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/12}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/13}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/14}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/1, /*CxtIx =*/15}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/16}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/17}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/18}, \
    {/*EFilterKind =*/eFilterKind_Avg, /*CfgIx =*/0, /*CxtIx =*/19}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/0}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/1}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/2}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/1, /*CxtIx =*/3}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/4}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/5}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/6}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/7}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/8}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/9}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/10}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/11}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/12}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/13}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/14}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/15}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/16}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/17}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/18}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/19}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/20}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/21}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/22}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/23}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/24}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/2, /*CxtIx =*/25}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/26}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/27}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/1, /*CxtIx =*/28}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/29}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/30}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/31}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/32}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/33}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/34}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/35}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/36}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/37}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/38}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/39}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/40}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/41}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/42}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/43}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/44}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/45}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/46}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/1, /*CxtIx =*/47}, \
    {/*EFilterKind =*/eFilterKind_DigitalInput, /*CfgIx =*/0, /*CxtIx =*/48}, \
}; \

#endif /* ifndef _IOHWAB_FILTER_CFG_H_ */

