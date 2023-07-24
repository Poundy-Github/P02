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
 * @file:      IoHwAb_Filter.c
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

#include "IoHwAb_Filter.h"
#include "IoHwAb_Filter_Cfg.h"
#include <string.h>



/**********************************************************************************************************************
 *  CONSTANS & TYPES
 *********************************************************************************************************************/

typedef Std_ReturnType (*FilterFunction)(const cp_SIOFilterHandler pConfig, const THwData NewValue, const p_THwData pFilteredValue);
typedef Std_ReturnType (*GetFunction)(const cp_SIOFilterHandler pVonfig, const p_THwData pValue);

/**********************************************************************************************************************
 *  DECLEAR
 *********************************************************************************************************************/
#define IoHwAb_START_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

static Std_ReturnType MathLib_MoveAvgFilter_Init( SMoveAvgFilter * const pFilterData, uint16 * const pMArrayData, const uint16 MArrayLen, const uint16 InitValue );
static uint16 MathLib_MoveAvgFilter_Apply( SMoveAvgFilter * const pFilterData, const uint16 ValueToFilter );
static Std_ReturnType DigitalInputFilter(const cp_SIOFilterHandler pConfig, const THwData NewValue, const p_THwData pFilteredValue);
static Std_ReturnType PT1Filter(const cp_SIOFilterHandler pConfig, const THwData NewValue, const p_THwData pFilteredValue);
static Std_ReturnType AvgFilter(const cp_SIOFilterHandler pConfig, const THwData NewValue, const p_THwData pFilteredValue);
static Std_ReturnType MedianFilter(const cp_SIOFilterHandler pConfig, const THwData NewValue, const p_THwData pFilteredValue);
static Std_ReturnType PassThroughFilter(const cp_SIOFilterHandler pConfig, const THwData NewValue, const p_THwData pFilteredValue);
static Std_ReturnType AnalogButtonFilter(const cp_SIOFilterHandler pConfig, const THwData NewValue, const p_THwData pFilteredValue);

static Std_ReturnType DigitalInputGet(const cp_SIOFilterHandler pConfig, const p_THwData pValue);
static Std_ReturnType PT1Get(const cp_SIOFilterHandler pConfig, const p_THwData pValue);
static Std_ReturnType AvgGet(const cp_SIOFilterHandler pConfig, const p_THwData pValue);
static Std_ReturnType MedianGet(const cp_SIOFilterHandler pConfig, const p_THwData pValue);
static Std_ReturnType PassThroughGet(const cp_SIOFilterHandler pConfig, const p_THwData pValue);
static Std_ReturnType AnalogButtonGet(const cp_SIOFilterHandler pConfig, const p_THwData pValue);

#define IoHwAb_STOP_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  PRIVATE
 *********************************************************************************************************************/

#define IoHwAb_START_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

IOHWAB_FILTERWRAPPERS_CFG_RAM()

#define IoHwAb_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define IoHwAb_START_SEC_CONST_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

IOHWAB_FILTERWRAPPERS_CFG_ROM()


static const FilterFunction FilterFunctions[eFilterKind_Count] = {DigitalInputFilter, PT1Filter, AvgFilter, MedianFilter, PassThroughFilter, AnalogButtonFilter};
static const GetFunction GetValueFunctions[eFilterKind_Count] = {DigitalInputGet, PT1Get, AvgGet, MedianGet, PassThroughGet, AnalogButtonGet};

#define IoHwAb_STOP_SEC_CONST_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define IoHwAb_START_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************/
/** @brief    Initialization of a moving average filter.*/
/***/
/** @param    pFilterData:    Moving average filter data structure.*/
/** @param    pMArrayData:    Filtered array.*/
/** @param    MArrayLen:      Filtered array length.*/
/** @param    InitValue:      Initial value for the array.*/
/***/
/** @return   Std_ReturnType:   E_OK     - MoveAvgFilter is initialized*/
/**                             E_NOT_OK - MoveAvgFilter is NOT initialized, debug assert fails*/
/*********************************************************************************************************************/
static Std_ReturnType MathLib_MoveAvgFilter_Init( SMoveAvgFilter * const pFilterData, uint16 * const pMArrayData, const uint16 MArrayLen, const uint16 InitValue )
{
    uint16 Ix;
    uint16 * pArray;
    Std_ReturnType Ret;

    if ( (NULL_PTR != pFilterData) && (NULL_PTR != pMArrayData) && (0 < MArrayLen) )
    {
        pFilterData->pMArray = pMArrayData;
        pFilterData->MArrayLen = MArrayLen;
        pFilterData->MArrayPos = 0;

        Ix = 0;
        pArray = pFilterData->pMArray;

        while ( Ix < MArrayLen )
        {
            (*pArray) = InitValue;
            pArray = &pArray[1];
            ++Ix;
        }

        pFilterData->Sum = InitValue * MArrayLen;
        pFilterData->Status = eFilterStatus_Initialized;

        Ret = E_OK;
    }
    else
    {
        Ret = E_NOT_OK;
    }

    return Ret;
}

/**********************************************************************************************************************/
/** @brief    This operation is used to apply a new value to the moving average filter.*/
/***/
/** @param    pFilterData:      Moving average filter data structure.*/
/** @param    ValueToFilter:    The new value to be filtered.*/
/** @param    pOutValue:        The output value after filtering.*/
/***/
/** @return   uint16:   Output value after filtering.*/
/***/
/** Note!   -   In case of invalid pointer (function arguments), debug assert fails and return value is 0*/
/**             If pointer is valid but the filter is not initialized returned value is (pFilterData->Sum / pFilterData->MArrayLen)*/
/**********************************************************************************************************************/
static uint16 MathLib_MoveAvgFilter_Apply( SMoveAvgFilter * const pFilterData, const uint16 ValueToFilter )
{
    uint16 * pArray;
    uint16 OutValue = 0;

    if ( (NULL_PTR != pFilterData) && (NULL_PTR != pFilterData->pMArray) && (0 < pFilterData->MArrayLen) )
    {
        if ( (pFilterData->Status == eFilterStatus_Initialized) || (pFilterData->Status == eFilterStatus_Calculated) )
        {
            /* add new value to sum of numbers in filter*/
            pFilterData->Sum += ValueToFilter;

            pArray = &pFilterData->pMArray[ pFilterData->MArrayPos ];

            /* remove from sum oldest value*/
            pFilterData->Sum -= (*pArray);

            /* add new value*/
            (*pArray) = ValueToFilter;

            /* move to next position in array*/
            pFilterData->MArrayPos++;

            /* if end of array is reached, start from beginning*/
            if ( pFilterData->MArrayPos >= pFilterData->MArrayLen )
            {
                pFilterData->MArrayPos = 0;
				pFilterData->Status = eFilterStatus_Calculated;
            }

        }
        else
        {
        
        }

        /* calculate average value*/
        OutValue = (uint16)( pFilterData->Sum / pFilterData->MArrayLen );
    }
    else
    {
    
    }

    return OutValue;
}

/**********************************************************************************************************************/
/** @brief    Initialization of PT1 filter.*/
/***/
/** @param    pPt1Filter:     PT1 filter data structure.*/
/** @param    DampingConst:   Damping constant which will be set for the filter.*/
/** @param    InitValue:      Initial filtering value.*/
/***/
/** @return   Std_ReturnType:   E_OK     - PT1 filter is initialized*/
/**                             E_NOT_OK - PT1 filter is NOT initialized, debug assert fails*/
/**********************************************************************************************************************/
Std_ReturnType MathLib_PT1Filter_Init( SPt1FilterData * const pPt1Filter, const uint16 DampingConst, const uint16 InitValue )
{
    Std_ReturnType Ret;

    if ( NULL_PTR != pPt1Filter )
    {
        pPt1Filter->OutputValue = InitValue;
        pPt1Filter->Remainder = 0;
        pPt1Filter->DampingTime = DampingConst;
        pPt1Filter->Status = eFilterStatus_Initialized;

        Ret = E_OK;
    }
    else
    {
        Ret = E_NOT_OK;
    }

    return Ret;
}

/**********************************************************************************************************************/
/** @brief    This operation is used to apply a new value to the PT1 filter.*/
/**           F(T) : Filter output at the time t = T*/
/**           R(T-1) : Rest of the integer division (modulo ..) that was memorized at the occurrence of the last (t = T-1) calculation*/
/**           N(T) : New current input value of the filter*/
/**           W : Weight of the PT1 filter*/
/**           TAU : Relax time (parameter of the PT1 filter)*/
/**           Algorithm :  F(T) = (  W*F(T-1) + N(T) + R(T-1)  )  /  (W + 1)*/
/**           W must be chosen so that  TAU = W * CallPeriodOfTheAlgorithm*/
/***/
/** @param    pPt1Filter:     PT1 filter data structure.*/
/** @param    ValueToFilter:  The new value which must be filtered.*/
/***/
/** @return   uint16:   Output value after filtering.*/
/***/
/** Note!   -   In case of invalid pointer, debug assert fails and return value is 0.*/
/**             If pointer is valid but the filter is not initialized returned value is not changed.*/
/**********************************************************************************************************************/
uint16 MathLib_PT1Filter_Apply( SPt1FilterData * const pPt1Filter, const uint16 ValueToFilter )
{
    uint32 Temp;
    uint32 Time;
    uint16 OutValue = 0;

    if ( NULL_PTR != pPt1Filter )
    {
        if ( (pPt1Filter->Status == eFilterStatus_Initialized) || (pPt1Filter->Status == eFilterStatus_Calculated) )
        {
            Time = (uint32)pPt1Filter->DampingTime;

            Temp = (uint32)pPt1Filter->OutputValue * Time;

            Temp += (uint32)ValueToFilter + (uint32)(pPt1Filter->Remainder);

            ++Time;

            pPt1Filter->OutputValue = (uint16)(Temp / Time);

            OutValue = pPt1Filter->OutputValue;

            pPt1Filter->Remainder = (uint16)(Temp % Time);

            pPt1Filter->Status = eFilterStatus_Calculated;
        }
        else
        {
            OutValue = pPt1Filter->OutputValue;
        }
    }
    else
    {

    }

    return OutValue;
}

/**********************************************************************************************************************/
/** @brief  Digital Input filter - filter on consecutive identical values*/
/***/
/** @arg    pConfig       : [In] Pointer to Filter Config*/
/** @arg    NewValue      : [In] New value to add to filter*/
/** @arg    pFilteredValue: [Out] Filtered value*/
/***/
/** @return E_OK:           Succeed*/
/**<br>     E_NOT_OK:       Failed*/
/**********************************************************************************************************************/
static Std_ReturnType DigitalInputFilter(const cp_SIOFilterHandler pConfig, const THwData NewValue, const p_THwData pFilteredValue)
{
    Std_ReturnType Ret = E_NOT_OK;
	/*new value == filtered value*/
    if (DigitalInputCxt[pConfig->CxtIx].FilteredValue == NewValue)
    {
    	/*reset debouce cnt*/
        DigitalInputCxt[pConfig->CxtIx].Count = 0U;
		Ret = E_OK;
    }
    else/*new value != filtered value*/
    {
        if (DigitalInputCxt[pConfig->CxtIx].Count < DigitalInputCfg[pConfig->CfgIx].FilterCount)
        {
        	/*debouncing*/
            DigitalInputCxt[pConfig->CxtIx].Count++;
        }
        else
        {
            DigitalInputCxt[pConfig->CxtIx].FilteredValue = NewValue;
			Ret = E_OK;
        }
    }
    *pFilteredValue = DigitalInputCxt[pConfig->CxtIx].FilteredValue;
    return Ret;
}

/**********************************************************************************************************************/
/** @brief  pass through*/
/***/
/** @arg    pConfig       : [In] Pointer to Filter Config*/
/** @arg    NewValue      : [In] New value to add to filter*/
/** @arg    pFilteredValue: [Out] Filtered value*/
/***/
/** @return E_OK:           Succeed*/
/**<br>     E_NOT_OK:       Failed*/
/**********************************************************************************************************************/
static Std_ReturnType PassThroughFilter(const cp_SIOFilterHandler pConfig, const THwData NewValue, const p_THwData pFilteredValue)
{
    //PassThroughCxt[pConfig->CxtIx].FilteredValue = NewValue;
    
    // no filtering
    *pFilteredValue = NewValue;
    return E_OK;
}

/**********************************************************************************************************************/
/** @brief  Avg through*/
/***/
/** @arg    pConfig       : [In] Pointer to Filter Config*/
/** @arg    NewValue      : [In] New value to add to filter*/
/** @arg    pFilteredValue: [Out] Filtered value*/
/***/
/** @return E_OK:           Succeed*/
/**<br>     E_NOT_OK:       Failed*/
/**********************************************************************************************************************/
static Std_ReturnType AvgFilter(const cp_SIOFilterHandler pConfig, const THwData NewValue, const p_THwData pFilteredValue)
{
    Std_ReturnType Ret = E_NOT_OK;

    AvgCxt[pConfig->CxtIx].FilteredValue = MathLib_MoveAvgFilter_Apply(&AvgCxt[pConfig->CxtIx].FilterData, (uint16)NewValue);
    
    if (eFilterStatus_Calculated == AvgCxt[pConfig->CxtIx].FilterData.Status)
    {
        Ret = E_OK;
    }
    else
    {
        AvgCxt[pConfig->CxtIx].FilteredValue = AvgCfg[pConfig->CfgIx].InitValue;
    }

    *pFilteredValue = AvgCxt[pConfig->CxtIx].FilteredValue;
    return Ret;
}

/**********************************************************************************************************************/
/** @brief  median through*/
/***/
/** @arg    pConfig       : [In] Pointer to Filter Config*/
/** @arg    NewValue      : [In] New value to add to filter*/
/** @arg    pFilteredValue: [Out] Filtered value*/
/***/
/** @return E_OK:           Succeed*/
/**<br>     E_NOT_OK:       Failed*/
/**********************************************************************************************************************/
static Std_ReturnType MedianFilter(const cp_SIOFilterHandler pConfig, const THwData NewValue, const p_THwData pFilteredValue)
{
    uint16 i;
    uint16 j;
    uint16 k;
    
    /* Store new data*/
    MedianCxt[pConfig->CxtIx].pArrayData[MedianCxt[pConfig->CxtIx].Next] = NewValue;
    
    /* Next available element*/
    MedianCxt[pConfig->CxtIx].Next++;

    if (MedianCxt[pConfig->CxtIx].Next >= MedianCfg[pConfig->CfgIx].Count)
    {
        MedianCxt[pConfig->CxtIx].Next = 0U;
    }
    
    MedianTemp[0] = MedianCxt[pConfig->CxtIx].pArrayData[0];
    
    for (i = 1U; i < MedianCfg[pConfig->CfgIx].Count; i ++)
    {
        for (j = 0U; (j < i) && (MedianTemp[j] < MedianCxt[pConfig->CxtIx].pArrayData[i]); j ++)
        {
        }
        
        for (k = i - j; k > 0; k --)
        {   
            MedianTemp[k + j] = MedianTemp[k + j - 1];
        }
        
        MedianTemp[j] = MedianCxt[pConfig->CxtIx].pArrayData[i];
    }
    
    MedianCxt[pConfig->CxtIx].FilteredValue = MedianTemp[MedianCfg[pConfig->CfgIx].Count / 2];
    
    *pFilteredValue = MedianCxt[pConfig->CxtIx].FilteredValue;
    return E_OK;
}

/**********************************************************************************************************************/
/** @brief  PT1 through*/
/***/
/** @arg    pConfig       : [In] Pointer to Filter Config*/
/** @arg    NewValue      : [In] New value to add to filter*/
/** @arg    pFilteredValue: [Out] Filtered value*/
/***/
/** @return E_OK:           Succeed*/
/**<br>     E_NOT_OK:       Failed*/
/**********************************************************************************************************************/
static Std_ReturnType PT1Filter(const cp_SIOFilterHandler pConfig, const THwData NewValue, const p_THwData pFilteredValue)
{
    Std_ReturnType Ret = E_NOT_OK;

    PT1Cxt[pConfig->CxtIx].FilteredValue = MathLib_PT1Filter_Apply(&PT1Cxt[pConfig->CxtIx].FilterData, (uint16)NewValue);
    
    if (eFilterStatus_Calculated == PT1Cxt[pConfig->CxtIx].FilterData.Status)
    {
        Ret = E_OK;
    }
    else
    {
        PT1Cxt[pConfig->CxtIx].FilteredValue = PT1Cfg[pConfig->CfgIx].InitValue;
    }

    *pFilteredValue = PT1Cxt[pConfig->CxtIx].FilteredValue;
    return Ret;
}


/**********************************************************************************************************************/
/** @brief  Analog Button filter - Recognize which button is pressed on analog input*/
/***/
/** @arg    pConfig       : [In] Pointer to Filter Config*/
/** @arg    NewValue      : [In] New value to add to filter*/
/** @arg    pFilteredValue: [Out] Filtered value*/
/***/
/** @return E_OK:           Succeed*/
/**<br>     E_NOT_OK:       Failed*/
/**********************************************************************************************************************/
static Std_ReturnType AnalogButtonFilter(const cp_SIOFilterHandler pConfig, const THwData NewValue, const p_THwData pFilteredValue)
{
	THwData temp_button;	
    Std_ReturnType Ret = E_NOT_OK;
	sint32 Idx = ABtnCfg[pConfig->CfgIx].AdcCount - 1 ;
	for( ; Idx >= 0; Idx--)
	{
		if( (NewValue < ABtnCfg[pConfig->CfgIx].AdcMax[Idx] ) && (NewValue > ABtnCfg[pConfig->CfgIx].AdcMin[Idx]) )
		{
			temp_button = (Idx + 1);  // There are 6 buttons plus not pressed state

			break;
		}
		else
		{
			temp_button = 0;
		}
	}
    if (ABtnCtx[pConfig->CxtIx].LastValue == temp_button)/*new value == Last value*/
    {
        if (ABtnCtx[pConfig->CxtIx].Count < ABtnCfg[pConfig->CfgIx].FilterCount)
        {
            ABtnCtx[pConfig->CxtIx].Count++;
        }
        else
        {
            ABtnCtx[pConfig->CxtIx].FilteredValue = temp_button;
			Ret = E_OK;
        }
    }
    else/*new value != Last value*/
    {
        if (ABtnCtx[pConfig->CxtIx].Count > 0)
        {
            ABtnCtx[pConfig->CxtIx].Count--;

		}
		if(0 == ABtnCtx[pConfig->CxtIx].Count)
		{
			ABtnCtx[pConfig->CxtIx].FilteredValue = 0;

		}

		ABtnCtx[pConfig->CxtIx].LastValue = temp_button;
	}
    *pFilteredValue = ABtnCtx[pConfig->CxtIx].FilteredValue;
    return Ret;
}



/**********************************************************************************************************************/
/** @brief  DigitalInputGet*/
/***/
/** @arg    pConfig: [In] Pointer to Filter Config*/
/** @arg    pValue : [Out] Filtered value*/
/***/
/** @return E_OK:           Succeed*/
/**<br>     E_NOT_OK:       Failed*/
/**********************************************************************************************************************/
static Std_ReturnType DigitalInputGet(const cp_SIOFilterHandler pConfig, const p_THwData pValue)
{

    *pValue = DigitalInputCxt[pConfig->CxtIx].FilteredValue;
    return E_OK;
}

/**********************************************************************************************************************/
/** @brief  DigitalInputGet*/
/**/
/** @arg    pConfig: [In] Pointer to Filter Config*/
/** @arg    pValue : [Out] Filtered value*/
/***/
/** @return E_OK:           Succeed*/
/**<br>     E_NOT_OK:       Failed*/
/**********************************************************************************************************************/
static Std_ReturnType AvgGet(const cp_SIOFilterHandler pConfig, const p_THwData pValue)
{

    *pValue = AvgCxt[pConfig->CxtIx].FilteredValue;
    return E_OK;
}

/**********************************************************************************************************************/
/** @brief  medianInputGet*/
/**/
/** @arg    pConfig: [In] Pointer to Filter Config*/
/** @arg    pValue : [Out] Filtered value*/
/**/
/** @return E_OK:           Succeed*/
/**<br>     E_NOT_OK:       Failed*/
/**********************************************************************************************************************/
static Std_ReturnType MedianGet(const cp_SIOFilterHandler pConfig, const p_THwData pValue)
{

    *pValue = MedianCxt[pConfig->CxtIx].FilteredValue;
    return E_OK;
}

/**********************************************************************************************************************/
/** @brief  PT1 InputGet*/
/***/
/** @arg    pConfig: [In] Pointer to Filter Config*/
/** @arg    pValue : [Out] Filtered value*/
/***/
/** @return E_OK:          Succeed*/
/**<br>     E_NOT_OK:       Failed*/
/**********************************************************************************************************************/
static Std_ReturnType PT1Get(const cp_SIOFilterHandler pConfig, const p_THwData pValue)
{

    *pValue = PT1Cxt[pConfig->CxtIx].FilteredValue;
    return E_OK;
}

/**********************************************************************************************************************/
/** @brief  Ppass through Get*/
/**/
/** @arg    pConfig: [In] Pointer to Filter Config*/
/** @arg    pValue : [Out] Filtered value*/
/***/
/** @return E_OK:           Succeed*/
/**<br>     E_NOT_OK:       Failed*/
/**********************************************************************************************************************/
static Std_ReturnType PassThroughGet(const cp_SIOFilterHandler pConfig, const p_THwData pValue)
{

    *pValue = PassThroughCxt[pConfig->CxtIx].FilteredValue;
    return E_OK;
}

/**********************************************************************************************************************/
/** @brief  analog button Get*/
/***/
/** @arg    pConfig: [In] Pointer to Filter Config*/
/** @arg    pValue : [Out] Filtered value*/
/***/
/** @return E_OK:           Succeed*/
/**<br>     E_NOT_OK:       Failed*/
/**********************************************************************************************************************/
static Std_ReturnType AnalogButtonGet(const cp_SIOFilterHandler pConfig, const p_THwData pValue)
{

    *pValue = ABtnCtx[pConfig->CxtIx].FilteredValue;
    return E_OK;
}


/**********************************************************************************************************************
 *  PUBLIC
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * CIoHwAb_Input_Convert
 **********************************************************************************************************************/
/*! \brief      Convert HW value ot Applciation one
 *  \return     void
 **********************************************************************************************************************/

uint32 CIoHwAb_Input_Convert(const IOHWAB_CFG_STR pInput, const THwData FilteredRawValue)
{
    return (uint32)(((FilteredRawValue + pInput.Offset) * pInput.ResolutionMultiplier) / pInput.ResolutionDivisor);
}
/**********************************************************************************************************************
 * CIoHwAb_Output_Convert
 **********************************************************************************************************************/
/*! \brief      Convert HW value ot Applciation one
 *  \return     void
 **********************************************************************************************************************/

uint32 CIoHwAb_Output_Convert(const IOHWAB_CFG_STR pOutput, const THwData NewAppValue)
{
    return (uint32)(((NewAppValue * pOutput.ResolutionDivisor) / pOutput.ResolutionMultiplier )) - pOutput.Offset;
}

/**********************************************************************************************************************
 * IoHwAb_FiltersWrapper_ApplyFilter
 **********************************************************************************************************************/
/*! \brief      the function to call filter according to the filter cfg
 *  \return     void
 **********************************************************************************************************************/
Std_ReturnType IoHwAb_FiltersWrapper_ApplyFilter(const uint8 FilterConfig, const THwData NewValue, const p_THwData pFilteredValue)
{
    Std_ReturnType Ret = E_OK;
	SIOFilterHandler pConfig = Filters[FilterConfig];
	
    if (pConfig.Kind < (EFilterKind)eFilterKind_Count)
    {
        Ret = FilterFunctions[pConfig.Kind](&pConfig, NewValue, pFilteredValue);
    }
    else
    {
        Ret = E_NOT_OK;
    }
    
    return Ret;
}

/**********************************************************************************************************************
 * IoHwAb_FiltersWrapper_GetValue
 **********************************************************************************************************************/
/*! \brief      the function to get value from filter
 *  \return     void
 **********************************************************************************************************************/
Std_ReturnType IoHwAb_FiltersWrapper_GetValue(const cp_SIOFilterHandler pConfig, const p_THwData pValue)
{
    Std_ReturnType Ret= E_OK;

    if (pConfig->Kind < (EFilterKind)eFilterKind_Count)
    {
        GetValueFunctions[pConfig->Kind](pConfig, pValue);
    }
    else
    {
        Ret = E_NOT_OK;
    }
    
    return Ret;
}

/**********************************************************************************************************************
 * IoHwAb_FiltersWrapper_Init
 **********************************************************************************************************************/
/*! \brief      the function to init filter values
 *  \return     void
 **********************************************************************************************************************/
void IoHwAb_FiltersWrapper_Init(void)
{
    uint16 Index;
    uint16 DataIndex;
    
    for (Index = 0U; Index < (sizeof(Filters) / sizeof (SIOFilterHandler)); Index++)
    {
        switch (Filters[Index].Kind)
        {
            case eFilterKind_DigitalInput:
                DigitalInputCxt[Filters[Index].CxtIx].FilteredValue = DigitalInputCfg[Filters[Index].CfgIx].InitValue;
                DigitalInputCxt[Filters[Index].CxtIx].Count = 0U;
                break;
            
            case eFilterKind_PT1:
                (void)MathLib_PT1Filter_Init(&PT1Cxt[Filters[Index].CxtIx].FilterData, PT1Cfg[Filters[Index].CfgIx].DampingTime, (uint16)PT1Cfg[Filters[Index].CfgIx].InitValue);
                break;

            case eFilterKind_Avg:
                (void)MathLib_MoveAvgFilter_Init(&AvgCxt[Filters[Index].CxtIx].FilterData, AvgCxt[Filters[Index].CxtIx].pArrayData, AvgCfg[Filters[Index].CfgIx].Count, (uint16)AvgCfg[Filters[Index].CfgIx].InitValue);
                break;

            case eFilterKind_Median:
                MedianCxt[Filters[Index].CxtIx].FilteredValue = MedianCfg[Filters[Index].CfgIx].InitValue;
                MedianCxt[Filters[Index].CxtIx].Next = 0U;
            
                for (DataIndex = 0U; DataIndex < MedianCfg[Filters[Index].CfgIx].Count; DataIndex ++)
                {
                    MedianCxt[Filters[Index].CxtIx].pArrayData[DataIndex] = MedianCfg[Filters[Index].CfgIx].InitValue;
                }
                break;
            
            case eFilterKind_PassThrough:
                PassThroughCxt[Filters[Index].CxtIx].FilteredValue = PassThroughCfg[Filters[Index].CfgIx].InitValue;
                break;

            case eFilterKind_AnalogBtn:
            	ABtnCtx[Filters[Index].CxtIx].FilteredValue = ABtnCfg[Filters[Index].CfgIx].InitValue;
                break;

            default:
                /* nothing to do */
                break;
        }
    }
}


#define IoHwAb_STOP_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


