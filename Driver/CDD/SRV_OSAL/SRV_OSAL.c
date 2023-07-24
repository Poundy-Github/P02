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
 * @file:      SRV_OSAL.c
 * @author:    Nobo
 * @date:      2020-4-3
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-4-3
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "SRV_OSAL.h"
#include "SRV_OSAL_RI.h"



#define MAX_U16_TIME    ((uint16)0xFFFF)




/***********************************************************************
 * @brief       : Get system timer 32-bit.
 * @param       : None
 * @retval      : uint32 - The value of the system timer.
 ***********************************************************************/
uint32 SRV_OSAL_Timer32_GetSystemTimer(void)
{
    TickType    SystemTimerL = (TickType)0;
    (void)RI_GetSystemTimer(&SystemTimerL);

    return (uint32)RI_SystemTicksToMs(SystemTimerL);
}


/***********************************************************************
 * @brief       : Start a 32-bit timer.
 * @param       : uint32 * pu32TimerP - Address of the timer to be started.
 * @retval      : None.
 ***********************************************************************/
void SRV_OSAL_Timer32_Start(uint32 * const pu32TimerP)
{
    TickType    SystemTimerL = (TickType)0;
    ASSERT_SRV_OSAL(NULL_PTR != pu32TimerP);

    if(NULL_PTR == pu32TimerP)
    {
        
    }
    else
    {
        (void)RI_GetSystemTimer(&SystemTimerL);

        // Value 0 indicates that the timer is not started and will result in error when checking this timer immediately.
        if((TickType)0 == SystemTimerL)
        {
            SystemTimerL = ~(TickType)0;
        }

        *pu32TimerP = (uint32)SystemTimerL;
    }
}



/***********************************************************************
 * @brief       : Stop a 32-bit timer.
 * @param       : uint32 * pu32TimerP - Address of the timer to be stopped.
 * @retval      : None.
 ***********************************************************************/
void SRV_OSAL_Timer32_Stop(uint32 * const pu32TimerP)
{
    ASSERT_SRV_OSAL(NULL_PTR != pu32TimerP);
    if(NULL_PTR == pu32TimerP)
    {
        
    }
    else
    {
        *pu32TimerP = 0;
    }
}


/***********************************************************************
 * @brief       : Check if the timer is started.
 * @param       : uint32 u32TimerP - The timer to be checked.
 * @retval      : boolean - TRUE if timer is started, otherwise cFalse.
 ***********************************************************************/
boolean SRV_OSAL_Timer32_IsStarted(const uint32 u32TimerP)
{
    return (boolean)((uint32)0 != u32TimerP);
}


/***********************************************************************
 * @brief       : Check if the timer is elapsed.
 * @param       : uint32 u32TimerP   - The timer to be checked.
 *                uint32 u32TimeoutP - Timeout value in [ms].
 * @retval      : boolean - TRUE if timer is elapsed, otherwise cFalse.
 ***********************************************************************/
boolean SRV_OSAL_Timer32_IsElapsed(const uint32 u32TimerP, const uint32 u32TimeoutP)
{
    boolean     bTimerIsElapsedL;
    uint32      u32DelayL;
    TickType    SystemTimerL = (TickType)0;

    if((uint32)0 == u32TimerP)
    {
        bTimerIsElapsedL = TRUE;
    }
    else
    {   
        (void)RI_GetSystemTimer(&SystemTimerL);
        u32DelayL = (uint32)SystemTimerL - u32TimerP;

        bTimerIsElapsedL = (boolean)(u32DelayL >= RI_MsToSystemTicks(u32TimeoutP));
    }

    return bTimerIsElapsedL;
}


/***********************************************************************
 * @brief       : Check the time elapsed for a given timer.
 * @param       : uint32 u32TimerP - The timer whose elapsed time will be returned.
 * @retval      : uint32 - The time in [ms] which has elapsed for the timer.
 ***********************************************************************/
uint32 SRV_OSAL_Timer32_GetElapsedTime(const uint32 u32TimerP)
{
    uint32      u32TimerElapsedTimeL = 0;
    TickType    SystemTimerL = (TickType)0;

    if((uint32)0 == u32TimerP)
    {
        // The function has been called on a timer, which is not started.
    }
    else
    {
        (void)RI_GetSystemTimer(&SystemTimerL);
        u32TimerElapsedTimeL = (uint32)SystemTimerL - u32TimerP;
    }

    return (uint32)RI_SystemTicksToMs(u32TimerElapsedTimeL);
}





/***********************************************************************
 * @brief       : Get system timer 16-bit.
 * @param       : None.
 * @retval      : uint16 - The value of the system timer.
 ***********************************************************************/
uint16 SRV_OSAL_Timer16_GetSystemTimer(void)
{
    TickType    SystemTimerL = (TickType)0;

    (void)RI_GetSystemTimer(&SystemTimerL);

    return (uint16)RI_SystemTicksToMs(SystemTimerL);
}



/***********************************************************************
 * @brief       : Start a 16-bit timer.
 * @param       : uint16 * pu16TimerP - Address of the timer to be started.
 * @retval      : None.
 ***********************************************************************/
void SRV_OSAL_Timer16_Start(uint16 * const pu16TimerP)
{
    TickType    SystemTimerL = (TickType)0;
    uint16      u16TimerL;
    ASSERT_SRV_OSAL(NULL_PTR != pu16TimerP);
    
    if(NULL_PTR == pu16TimerP)
    {
        
    }
    else
    {
        (void)RI_GetSystemTimer(&SystemTimerL);
        u16TimerL = (uint16)SystemTimerL;

        // Value 0 indicates that the timer is not started and will result in error when checking this timer immediately.
        if((uint16)0 == u16TimerL)
        {
            u16TimerL = MAX_U16_TIME;
        }

        *pu16TimerP = u16TimerL;
    }
}


/***********************************************************************
 * @brief       : Stop a 16-bit timer.
 * @param       : uint16 * pu16TimerP - Address of the timer to be stopped.
 * @retval      : None.
 ***********************************************************************/
void SRV_OSAL_Timer16_Stop(uint16 * const pu16TimerP)
{
    ASSERT_SRV_OSAL(NULL_PTR != pu16TimerP);
    
    if(NULL_PTR == pu16TimerP)
    {
        
    }
    else
    {
        *pu16TimerP = 0;
    }
}



/***********************************************************************
 * @brief       : Check if the timer is started.
 * @param       : uint16 u16TimerP - The timer to be checked.
 * @retval      : boolean - TRUE if timer is started, otherwise cFalse.
 ***********************************************************************/
boolean SRV_OSAL_Timer16_IsStarted(const uint16 u16TimerP)
{
    return (boolean)((uint16)0 != u16TimerP);
}


/***********************************************************************
 * @brief       : Check if the timer is elapsed.
 * @param       : uint16 u16TimerP   - The timer to be checked.
 *                uint16 u16TimeoutP - Timeout value in [ms].
 * @retval      : boolean - TRUE if timer is elapsed, otherwise cFalse.
 ***********************************************************************/
boolean SRV_OSAL_Timer16_IsElapsed(const uint16 u16TimerP, const uint16 u16TimeoutP)
{
    boolean     bTimerIsElapsedL;
    uint16      u16DelayL;
    TickType    SystemTimerL = (TickType)0;
    
    if((uint16)0 == u16TimerP)
    {
        bTimerIsElapsedL = TRUE;
    }
    else
    {   
        (void)RI_GetSystemTimer(&SystemTimerL);
        u16DelayL = (uint16)((uint16)SystemTimerL - u16TimerP);
                
        bTimerIsElapsedL = (boolean)(u16DelayL >= RI_MsToSystemTicks(u16TimeoutP));
    }
    
    return bTimerIsElapsedL;
}


/***********************************************************************
 * @brief       : Check the time elapsed for a given timer.
 * @param       : uint16 u16TimerP - The timer whose elapsed time will be returned.
 * @retval      : uint16 - The time in [ms] which has elapsed for the timer.
 ***********************************************************************/
uint16 SRV_OSAL_Timer16_GetElapsedTime(const uint16 u16TimerP)
{
    uint16      u16TimerElapsedTimeL = 0;
    TickType    SystemTimerL = (TickType)0;
    
    if((uint16)0 == u16TimerP)
    {
        // The function has been called on a timer, which is not started.
    }
    else
    {
        (void)RI_GetSystemTimer(&SystemTimerL);

        u16TimerElapsedTimeL = (uint16)((uint16)SystemTimerL - u16TimerP);
        
    }
    
    return (uint16)RI_SystemTicksToMs(u16TimerElapsedTimeL);
}



