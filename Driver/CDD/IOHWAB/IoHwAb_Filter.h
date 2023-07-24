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
 * @file:      IoHwAb_Filter.h
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

#ifndef _IOHWAB_FILTER_H_
#define _IOHWAB_FILTER_H_

#include "IoHwAb_common.h"

/**********************************************************************************************************************
 *  CONSTANS & TYPES
 *********************************************************************************************************************/
typedef unsigned int THwData;
typedef THwData *p_THwData;



typedef SIOFilterHandler * p_SIOFilterHandler;
typedef SIOFilterHandler const * cp_SIOFilterHandler;

typedef enum EFilterStatus
{
    eFilterStatus_NOT_OK,
    eFilterStatus_Initialized,
    eFilterStatus_Calculated
} EFilterStatus;

typedef struct SMoveAvgFilter
{
    uint32 Sum;
    uint16 * pMArray;
    uint16 MArrayLen;
    uint16 MArrayPos;
    EFilterStatus Status;
} SMoveAvgFilter;

typedef struct SPt1FilterData
{
    uint16 DampingTime;
    uint16 OutputValue;
    uint16 Remainder;
    EFilterStatus Status;
} SPt1FilterData;

#define eFilterKind_DigitalInput    0	/*Filter input value for consecutive identical values*/ 
#define eFilterKind_PT1             1	/*PT1 filter*/
#define eFilterKind_Avg             2	/*Average of last values*/
#define eFilterKind_Median          3	/*Median of last values*/
#define eFilterKind_PassThrough     4	/*Do nothing*/
#define eFilterKind_AnalogBtn       5	/*analog button filter*/
#define eFilterKind_Count           6	/*max filter kind*/

/********************************digital input filter************************************/
/* DigitalInput filter context*/
typedef struct SIODigitalInputCxt
{
    THwData Count; /* Consecutive count of last values different from FilteredValue*/
    THwData FilteredValue; /* Filtered value*/
} SIODigitalInputCxt;

/* DigitalInput filter configuration*/
typedef struct SIODigitalInputCfg
{
    uint8 FilterCount; /* Number of identical consecutive values needed to output this value to filtered value*/
    THwData InitValue; /* Init value*/
} SIODigitalInputCfg;

/********************************pass through filter************************************/

/* PassThrough filter context*/
typedef struct SIOPassThroughCxt
{
    THwData FilteredValue; /* Filtered value*/
} SIOPassThroughCxt;

/* PassThrough filter configuration*/
typedef struct SIOPassThroughCfg
{
    THwData InitValue; /* Init value*/
} SIOPassThroughCfg;

/********************************avg filter************************************/
typedef struct SIOAvgCxt
{
    THwData FilteredValue; /* Filtered value*/
    SMoveAvgFilter FilterData; /* FilterData structure*/
    uint16 *pArrayData;/* pointer to array that contains values*/
} SIOAvgCxt;

/* Average filter configuration*/
typedef struct SIOAvgCfg
{
    uint16 Count; /* Number of elements in average*/
    THwData InitValue; /* Init value*/
} SIOAvgCfg;

/********************************median filter************************************/

typedef struct SIOMedianCxt
{
    THwData FilteredValue; /* Filtered value*/
    THwData *pArrayData; /* pointer to array that contains last values*/
    uint16 Next; /* Next element in ring buffer*/
} SIOMedianCxt;

/* Median filter configuration*/
typedef struct SIOMedianCfg
{
    uint8 Count;
    THwData InitValue; /* Init value*/
} SIOMedianCfg;

/********************************PT1 filter************************************/

typedef struct SIOPT1Cxt
{
    THwData FilteredValue; /* Filtered value*/
    SPt1FilterData FilterData; /* PT1 filter data - see MathLib for more details*/
} SIOPT1Cxt;

/* PT1 filter configuration*/
typedef struct SIOPT1Cfg
{
    uint16 DampingTime; /* Damping time*/
    THwData InitValue; /* Init value*/
} SIOPT1Cfg;

/********************************anolog button filter************************************/

/* Analog button filter configuration*/
typedef struct SIOAnButtonCfg
{
    THwData InitValue; /* Init value*/
	uint16 AdcMax[7]; /* Max Adc value for band, 6 bands plus off*/
	uint16 AdcMin[7]; /* Min Adc value for band, 6 bands plus off*/
	uint8  AdcCount;  /* Count of Adc Max and AdcMin elements*/
	uint8  FilterCount;  /* Number of identical consecutive values needed to output this value to filtered value*/
} SIOAnButtonCfg;

/* Analog Button filter context*/
typedef struct SIOAnButtonCxt
{
    THwData Count; /* Consecutive count of last values different from FilteredValue*/	
    THwData LastValue; /* Last Filtered value*/
    THwData FilteredValue; ///< Filtered value
} SIOAnButtonCxt;


/**********************************************************************************************************************
 *  DECLARE
 *********************************************************************************************************************/
#define IoHwAb_START_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern uint32 CIoHwAb_Input_Convert(const IOHWAB_CFG_STR pInput, const THwData FilteredRawValue);
extern uint32 CIoHwAb_Output_Convert(const IOHWAB_CFG_STR pOutput, const THwData NewAppValue);
extern Std_ReturnType IoHwAb_FiltersWrapper_ApplyFilter(const uint8 pConfig, const THwData NewValue, const p_THwData pFilteredValue);
extern Std_ReturnType IoHwAb_FiltersWrapper_GetValue(const cp_SIOFilterHandler pConfig, const p_THwData pValue);
extern void IoHwAb_FiltersWrapper_Init(void);

#define IoHwAb_STOP_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* ifndef _IOHWAB_FILTER_H_ */

