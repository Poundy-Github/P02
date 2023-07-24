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

/**********************************************************************************************************
*File Name   : WN_Core.c                                                                                  *
*                                                                                                         *
*Description : Warning module core function source file.                                  		          *
*                                                                                                         *
*Author      : Chao feng                                                                                  *
*                                                                                                         *
*Compiler    : Green Hills  [MULTI IDE 6.1.6]                                                             *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family [RH850/D1M2]                                          *
*                                                                                                         *
*Version     : 1.0.0                                                                                      *
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
//#include "system.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_WN_Config.h"
#include "SWC_WN_Core.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Warning Module Flag Attribute 															              *
*																								          *
*																								          *
**********************************************************************************************************/
#define SWC_WN_START_SEC_CONST_UNSPECIFIED
#include "SWC_WN_MemMap.h"

static const WN_CFG_tstFLAG_ATTRIBUTE WN_CORE_stFlag_Attribute[] = WN_CFG_FLAG_ATTRIBUTE;

#define SWC_WN_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_WN_MemMap.h"
/**********************************************************************************************************
*																								          *
*																								          *
*	Warning Module Core Function							    									      *
*																								          *
*																								          *
**********************************************************************************************************/
#define SWC_WN_START_SEC_CODE
#include "SWC_WN_MemMap.h" 

static void WN__vCheckSpecialCondition(WN_CFG_tstWarningControlStatus *stWarningControlStatus,const WN_CFG_tstWarningAttribute *cstWarningAttribute,const WN_CFG_tstMAIN_OBJECT *cstMainObject);

/**********************************************************************************************************
*Function   : WN_CORE_vProcessControl                                                                     *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-11                                                                                  *
**********************************************************************************************************/
void WN_CORE_vProcessControl(void *stProcessTable, WN_CFG_tstMAIN_OBJECT* stMainObject)
{
    boolean boExitProcessButton = FALSE;
    boolean boProcessCodeRespond = FALSE;
    WN_tstPROCESS *TablePtr;

    TablePtr = (WN_tstPROCESS *)stProcessTable;

    while ((WN_DO_NOTHING != *TablePtr->boptrProcess) &&
           (FALSE == boExitProcessButton))
    {
        boProcessCodeRespond = (*TablePtr->boptrProcess)();

        if (boProcessCodeRespond == TRUE)
        {
            if (WN_KEEP_PREVIOUS != TablePtr->u32SucceedEnableStatus)
            {
                stMainObject->unSystemErrorStatus.u32SystemErrorStatus |= (uint8)TablePtr->u32SucceedEnableStatus;
            }
            else
            {
                
            }
            if (WN_KEEP_PREVIOUS != TablePtr->u32FaildEnableStatus)
            {
                stMainObject->unSystemErrorStatus.u32SystemErrorStatus &= (~(uint8)TablePtr->u32FaildEnableStatus);
            }
            else
            {
                
            }

            if (WN_DO_NOTHING != *TablePtr->vptrAfterSucceedOperation)
            {
                (void)(*TablePtr->vptrAfterSucceedOperation)();
            }
            else
            {
                
            }
        }
        else
        {
            if (WN_KEEP_PREVIOUS != TablePtr->u32FaildEnableStatus)
            {
                stMainObject->unSystemErrorStatus.u32SystemErrorStatus |= (uint32)(TablePtr->u32FaildEnableStatus);
            }
            else
            {
                
            }
            if (WN_KEEP_PREVIOUS != TablePtr->u32SucceedEnableStatus)
            {
                stMainObject->unSystemErrorStatus.u32SystemErrorStatus &= (~(uint32)(TablePtr->u32SucceedEnableStatus));
            }
            else
            {
                
            }

            if (WN_DO_NOTHING != *TablePtr->vptrAfterFaildOperation)
            {
                (void)(*TablePtr->vptrAfterFaildOperation)();
            }
            else
            {
                
            }

            if (FALSE == TablePtr->boContinueWhenFaild)
            {
                boExitProcessButton = TRUE;
            }
            else
            {
                
            }
        }
        ++TablePtr;
    }
}
/**********************************************************************************************************
*Function   : WN_CORE_vFlagControl                                                                        *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-11                                                                                  *
**********************************************************************************************************/
void WN_CORE_vFlagControl(WN_CFG_enFLAG_PROCESS_STAGE enFlagOperationOrder, WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    uint8 u8Index = 0;
    boolean boExitProcessButton = FALSE;
    uint8 u32SetValueTemp = 0u;
    uint32 u32MaskTemp = 0u;

    while (((WN_CORE_stFlag_Attribute[u8Index].u8FlagBitIndex + WN_CORE_stFlag_Attribute[u8Index].u8FlagBitLength) < 32) &&
           (WN_CORE_stFlag_Attribute[u8Index].u8FlagBitLength > 0) &&
           (u8Index < 3) &&
           (FALSE == boExitProcessButton))
    {
        if (enFlagOperationOrder == WN_COLD_INIT)
        {
            u32SetValueTemp = WN_CORE_stFlag_Attribute[u8Index].u8ColdInitSetValue;
        }
        else if (enFlagOperationOrder == WN_WARM_INIT)
        {
            u32SetValueTemp = WN_CORE_stFlag_Attribute[u8Index].u8WarmInitSetValue;
        }
        else if (enFlagOperationOrder == WN_WAKE_UP)
        {
            u32SetValueTemp = WN_CORE_stFlag_Attribute[u8Index].u8WakeUpSetValue;
        }
        else if (enFlagOperationOrder == WN_SLEEP)
        {
            u32SetValueTemp = WN_CORE_stFlag_Attribute[u8Index].u8SleepSetValue;
        }
        else if (enFlagOperationOrder == WN_ENTER_ABNORMAL)
        {
            u32SetValueTemp = WN_CORE_stFlag_Attribute[u8Index].u8EnterAbnormalSetValue;
        }
        else if (enFlagOperationOrder == WN_EXIT_ABNORMAL)
        {
            u32SetValueTemp = WN_CORE_stFlag_Attribute[u8Index].u8ExitAbnormalSetValue;
        }
        else
        {
            u32SetValueTemp = 0;
        }

        if (u32SetValueTemp != WN_FLAG_PREVIOUS)
        {
#if (WN_CFG_DEBUG == TRUE) //Check flag set value
            if (8 < WN_CORE_stFlag_Attribute[u8Index].u8FlagBitLength)
            {
                printf("\
--Warning Module Debug: Configration Error-----------------\r\n\
--Function Name : WN_CORE_vFlagControl\r\n\
--Error : Flag Bit length is oversize.Max value is 8.\r\n\
--Flag index : %d\r\n\
--Order enum index : %d\r\n\
------------------------------------------------------------\r\n",
                       u8Index, enFlagOperationOrder);
            }
            else
            {
            }

            if (((1 << WN_CORE_stFlag_Attribute[u8Index].u8FlagBitLength) - 1) < u32SetValueTemp)
            {
                printf("\
--Warning Module Debug: Configration Error-----------------\r\n\
--Function Name : WN_CORE_vFlagControl\r\n\
--Error : Flag set value is oversize.\r\n\
--Flag index : %d\r\n\
--Order enum index : %d\r\n\
------------------------------------------------------------\r\n",
                       u8Index, enFlagOperationOrder);
            }
            else
            {
            }
#endif
            if (8 >= WN_CORE_stFlag_Attribute[u8Index].u8FlagBitLength)
            {
                u32MaskTemp = (uint32)(((1u << WN_CORE_stFlag_Attribute[u8Index].u8FlagBitLength) - 1u) << WN_CORE_stFlag_Attribute[u8Index].u8FlagBitIndex);

                u32SetValueTemp = (u32SetValueTemp << WN_CORE_stFlag_Attribute[u8Index].u8FlagBitIndex);

                //Set value
                stMainObject->unFunctionFlag.u32FuncFlag &= (~u32MaskTemp);
                stMainObject->unFunctionFlag.u32FuncFlag |= (u32SetValueTemp);
            }
            else
            {
            }
        }
        else
        {
        }
        u8Index++;
    }
}
/**********************************************************************************************************
*Function   : WN_CORE_vSetSystemErrorStatus                                                               *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-11                                                                                  *
**********************************************************************************************************/
void WN_CORE_vSetSystemErrorStatus(WN_CFG_enSYSTEM_STATUS enStatus, WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    if (enStatus == WN_SYSTEM_DEFAULT)
    {
        stMainObject->unSystemErrorStatus.u32SystemErrorStatus = (uint32)WN_SYSTEM_DEFAULT;
    }
    else
    {
        stMainObject->unSystemErrorStatus.u32SystemErrorStatus |= (uint32)enStatus;
    }
}
/**********************************************************************************************************
*Function   : WN_CORE_vClearSystemErrorStatus                                                             *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-11                                                                                  *
**********************************************************************************************************/
void WN_CORE_vClearSystemErrorStatus(WN_CFG_enSYSTEM_STATUS enStatus, WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    if ((enStatus == WN_SYSTEM_DEFAULT) || (enStatus == WN_SYSTEM_RUNNING))
    {
        //Clear nothing
    }
    else
    {
        stMainObject->unSystemErrorStatus.u32SystemErrorStatus &= (~(uint32)enStatus);
    }
}
/**********************************************************************************************************
*Function   : WN_CORE_boCheckSystemErrorStatus                                                            *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-11                                                                                  *
**********************************************************************************************************/
boolean WN_CORE_boCheckSystemErrorStatus(WN_CFG_enSYSTEM_STATUS enStatus, WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    boolean boReturn = FALSE;
    if ((enStatus == WN_SYSTEM_DEFAULT) || (enStatus == WN_SYSTEM_RUNNING))
    {
        //Check nothing so return FALSE
    }
    else if ((stMainObject->unSystemErrorStatus.u32SystemErrorStatus & (uint32)enStatus) != FALSE)
    {
        boReturn = TRUE;
    }
    else
    {
    }
    return boReturn;
}
/**********************************************************************************************************
*Function   : WN_CORE_vCheckModuleConfigration                                                            *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-11                                                                                  *
**********************************************************************************************************/
#if (WN_CFG_DEBUG == TRUE) //Check module configration is valid
void WN_CORE_vCheckModuleConfigration(void)
{

#if (WN_CFG_TIME_TASK_CYCLE > 0)
#else
    printf("\
--Warning Module Debug: Configration Error-----------------\r\n\
--Function Name : WN_CORE_vCheckModuleConfigration\r\n\
--Error : WN_CFG_TIME_TASK_CYCLE set value is invalid.\r\n\
------------------------------------------------------------\r\n");
#endif

#if ((WN_CFG_TIMER_MODE_CONFIG == WN_CFG_TIMER_USE_TASK_CYCLE) || (WN_CFG_TIMER_MODE_CONFIG == WN_CFG_TIMER_USE_SYSTEM_TIMER))
#else
    printf("\
--Warning Module Debug: Configration Error-----------------\r\n\
--Function Name : WN_CORE_vCheckModuleConfigration\r\n\
--Error : WN_CFG_TIMER_MODE_CONFIG set value is invalid.\r\n\
------------------------------------------------------------\r\n");
#endif


   
}
#endif //(WN_CFG_DEBUG == TRUE)
/**********************************************************************************************************
*Function   : WN_CORE_vDebugModeOperation                                                                 *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-11                                                                                  *
**********************************************************************************************************/
#if (WN_CFG_DEBUG == TRUE)
void WN_CORE_vDebugModeOperation(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
	uint16 u8Index;

	/*Save telltall name when system in debug mode*/
	for(u8Index=0; u8Index < WN_enWARNING_TOTAL_NUMBER; u8Index++)
    {
    	stMainObject->stWarningControlStatus[u8Index].enWarningName = (WN_CFG_enWarningID)u8Index;
    }
}
#endif //(WN_CFG_DEBUG == TRUE)
/**********************************************************************************************************
*Function   : TT_CORE_vTelltaleExternalControlEnable                                                      *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-07-04                                                                                  *
**********************************************************************************************************/
void WN_CORE_vWarningExternalControlEnable(WN_CFG_enWarningID enWarningID,WN_CFG_tstMAIN_OBJECT *stMainObject)
{
	if (enWarningID < WN_enWARNING_TOTAL_NUMBER)
    {
		stMainObject->stWarningControlStatus[enWarningID].unStatus.stStatus.ExternalControlStatus = 1;
    }
    else
    {
        /*Do nothing because request telltale ID out bound */
    }
}
/**********************************************************************************************************
*Function   : WN_CORE_vWarningExternalControlDisable                                                     *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-07-04                                                                                  *
**********************************************************************************************************/
void WN_CORE_vWarningExternalControlDisable(WN_CFG_enWarningID enWarningID,WN_CFG_tstMAIN_OBJECT *stMainObject)
{
	if (enWarningID < WN_enWARNING_TOTAL_NUMBER)
    {
		stMainObject->stWarningControlStatus[enWarningID].unStatus.stStatus.ExternalControlStatus = 0;
    }
    else
    {
        /*Do nothing because request telltale ID out bound */
    }
}
/**********************************************************************************************************
*Function   : WN_CORE_vWarningExternalControlDisable                                                     *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-07-04                                                                                  *
**********************************************************************************************************/
boolean WN_CORE_boGetWarningExternalControlStatus(WN_CFG_enWarningID enWarningID,WN_CFG_tstMAIN_OBJECT *stMainObject)
{
	boolean boReturn;
	if (enWarningID < WN_enWARNING_TOTAL_NUMBER)
    {
		if(stMainObject->stWarningControlStatus[enWarningID].unStatus.stStatus.ExternalControlStatus)
		{
			boReturn = TRUE;
		}
		else
		{
			boReturn = FALSE;
		}
    }
    else
    {
        boReturn = FALSE;
    }
	return boReturn;
}
/**********************************************************************************************************
*Function   : WN_CORE_vCalculateDelayTimerMaxCount                                                        *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_CORE_vCalculateDelayTimerMaxCount(const WN_CFG_tstWarningAttribute *cstWarningAttribute, WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    uint16 u8Index = 0;

#if (WN_CFG_TIMER_MODE_CONFIG == WN_CFG_TIMER_USE_TASK_CYCLE)

    const uint8 u8Factor = WN_CFG_TIME_TASK_CYCLE;

#elif (WN_CFG_TIMER_MODE_CONFIG == WN_CFG_TIMER_USE_SYSTEM_TIMER)

    const uint8 u8Factor = 1;

#endif //(WN_CFG_TIMER_MODE_CONFIG)

    /*Clear max count*/
    stMainObject->stCount.u16IgnitionOnResponseDelayMaxTickCount = 0;
    stMainObject->stCount.u16ExitAbnormalResponseDelayMaxTickCount = 0;

    for (u8Index = 0; u8Index < WN_enWARNING_TOTAL_NUMBER; u8Index++)
    {
        /*If count value greater than u16IgnitionOnResponseDelayMaxTickCount ,set to this value*/
        if ((cstWarningAttribute[u8Index].u16IgnOnResponseDelayTime / u8Factor) > stMainObject->stCount.u16IgnitionOnResponseDelayMaxTickCount)
        {
            stMainObject->stCount.u16IgnitionOnResponseDelayMaxTickCount = (cstWarningAttribute[u8Index].u16IgnOnResponseDelayTime / u8Factor);
        }
        else
        {
            /*Do nothing but avoid QAC warning*/
        }
#if 0
        /*If count value greater than u16ExitAbnormalResponseDelayMaxTickCount ,set to this value*/
        if ((cstWarningAttribute[u8Index].u16ExitAbnormalResponseDelayTime / u8Factor) > stMainObject->stCount.u16ExitAbnormalResponseDelayMaxTickCount)
        {
            stMainObject->stCount.u16ExitAbnormalResponseDelayMaxTickCount = (cstWarningAttribute[u8Index].u16ExitAbnormalResponseDelayTime / u8Factor);
        }
        else
        {
            /*Do nothing but avoid QAC warning*/
        }
#endif
    }
}
/**********************************************************************************************************
*Function   : WN_CORE_vCheckResponseDelayStatus                                                           *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_CORE_vCheckResponseDelayStatus(const WN_CFG_tstWarningAttribute *cstWarningAttribute, WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    uint16 u8Index = 0;
    uint32 u32WNPowerModeStatus = 0;
#if (WN_CFG_TIMER_MODE_CONFIG == WN_CFG_TIMER_USE_TASK_CYCLE)

    const uint8 u8Factor = WN_CFG_TIME_TASK_CYCLE;
    const uint16 u16TickPlus = 1;

#elif (WN_CFG_TIMER_MODE_CONFIG == WN_CFG_TIMER_USE_SYSTEM_TIMER)

    const uint8 u8Factor = 1;
    uint16 u16TickPlus = WN_CFG_GET_DELAY_TIMER_RUNNING_TIME();

#endif //(WN_CFG_TIMER_MODE_CONFIG)
    u32WNPowerModeStatus = WN_CFG_vGetPowerModeSts();
    if (u16TickPlus)
    {
        for (u8Index = 0; u8Index < WN_enWARNING_TOTAL_NUMBER; u8Index++)
        {
            /*If tick value less than u16IgnOnResponseDelayTime , set u8IgnitionOnResponseDelayStatus to 1*/
            if ((stMainObject->stTimer.u16IgnitionOnResponseDelayTick * u8Factor) < cstWarningAttribute[u8Index].u16IgnOnResponseDelayTime)
            {
                stMainObject->stWarningControlStatus[u8Index].unStatus.stStatus.IgnitionOnResponseDelayStatus = 1;
            }
            else
            {
                stMainObject->stWarningControlStatus[u8Index].unStatus.stStatus.IgnitionOnResponseDelayStatus = 0;
            }

#if 0
            /*If tick value less than u16ExitAbnormalResponseDelayTime , set u8ExitAbnormalDelayStatus to 1*/
            if ((stMainObject->stTimer.u16ExitAbnormalResponseDelayDelayTick * u8Factor) < cstWarningAttribute[u8Index].u16ExitAbnormalResponseDelayTime)
            {
                stMainObject->stWarningControlStatus[u8Index].unStatus.stStatus.ExitAbnormalDelayStatus = 1;
            }
            else
            {
                stMainObject->stWarningControlStatus[u8Index].unStatus.stStatus.ExitAbnormalDelayStatus = 0;
            }
#endif
        }

        if (u32WNPowerModeStatus == WN_enRUN)
        {
            /*Time Tick Plus*/
            if (stMainObject->stTimer.u16IgnitionOnResponseDelayTick <= stMainObject->stCount.u16IgnitionOnResponseDelayMaxTickCount)
            {
                stMainObject->stTimer.u16IgnitionOnResponseDelayTick += u16TickPlus;
            }
            else
            {
                /*Do nothing but avoid QAC warning*/
            }
        }
        else
        {
            stMainObject->stTimer.u16IgnitionOnResponseDelayTick = 0;
        }
#if 0
        if (stMainObject->stTimer.u16ExitAbnormalResponseDelayDelayTick <= stMainObject->stCount.u16ExitAbnormalResponseDelayMaxTickCount)
        {
            stMainObject->stTimer.u16ExitAbnormalResponseDelayDelayTick += u16TickPlus;
        }
        else
        {
            /*Do nothing but avoid QAC warning*/
        }
#endif
    }
    else
    {
    	/*Do nothing but avoid QAC warning*/
    }
}
/**********************************************************************************************************
*Function   : WN_CORE_vWarningTableLogicProcess                                                           *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_CORE_vSingleLogicProcess(void* vptrWarningLogicOperation,const WN_CFG_tstLogicProcessAttribute *cstLogicProcessAttribute, WN_CFG_tstMAIN_OBJECT *stMainObject)
{
	uint16 u8Index = 0;

	while(WN_DO_NOTHING != cstLogicProcessAttribute[u8Index].vptrWarningLogicOperation)
	{
		if ((vptrWarningLogicOperation == cstLogicProcessAttribute[u8Index].vptrWarningLogicOperation)\
			&&(0 != (uint32)WN_enINTERFACE & cstLogicProcessAttribute[u8Index].u32LogicProcessMode))
        {
			(void)cstLogicProcessAttribute[u8Index].vptrWarningLogicOperation(stMainObject);
		}
		 else
	    {
	        /*Parameter is not match current process mode,so do not running this process */
	    }
		u8Index++;
	}
}
/**********************************************************************************************************
*Function   : WN_CORE_vWarningTableLogicProcess                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_CORE_vWarningTableLogicProcess(WN_CFG_enLogicProcessMode enLogicProcessMode,const WN_CFG_tstLogicProcessAttribute *cstLogicProcessAttribute, WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    uint16 u8Index = 0;

    if ((WN_enTIME_TASK == enLogicProcessMode) || (WN_enROBIN_TASK == enLogicProcessMode))
    {
	    while(WN_DO_NOTHING != cstLogicProcessAttribute[u8Index].vptrWarningLogicOperation)
		{
			if ((uint32)enLogicProcessMode & cstLogicProcessAttribute[u8Index].u32LogicProcessMode)
            {
				if( cstLogicProcessAttribute[u8Index].u16TimeTaskModeLoopOffset == (stMainObject->stCount.u32TimeTaskLoopRateTickCount  % cstLogicProcessAttribute[u8Index].u16TimeTaskModeLoopFactor))
                {
                    (void)cstLogicProcessAttribute[u8Index].vptrWarningLogicOperation(stMainObject);
                }
            }
			 else
		    {
		        /*Parameter is not match current process mode,so do not running this process */
		    }
			u8Index++;
		}
    }
    else
    {
        /*Input parameter is error ,so do nothing*/
    }
}
/**********************************************************************************************************
*Function   : WN_CORE_vSingleWarningControl                                                               *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_CORE_vSingleWarningControl(WN_CFG_tstWarningControlStatus *stWarningControlStatus, const WN_CFG_tstWarningAttribute *cstWarningAttribute, WN_CFG_tstMAIN_OBJECT *stMainObject)
{
    boolean boRunningFlag = FALSE;
	
	/*If Control process is running , then quit this time .Avoid run this function in interrupt when this function is already running*/
	if (boRunningFlag)
    {
        return;
    }
    else
    {
        boRunningFlag = TRUE;
    }

	/*Check external contol condition*/
	if(0 == stWarningControlStatus->unStatus.stStatus.ExternalControlStatus)
	{
		/*Save logic status to result logic status*/
        stWarningControlStatus->unStatus.stStatus.ResultLogicType = \
        stWarningControlStatus->unStatus.stStatus.LogicType;
	}
	else
	{
		/*Let telltale external control interface set the result logic status*/
	}

	/*Check special condition such as ignition on response delay status etc*/
    WN__vCheckSpecialCondition(stWarningControlStatus,cstWarningAttribute,stMainObject);

    /*Save current status type to last*/
    stWarningControlStatus->unStatus.stStatus.LastLogicType = \
	stWarningControlStatus->unStatus.stStatus.ResultLogicType;

    boRunningFlag = FALSE;
}
/**********************************************************************************************************
*Function   : WN__vCheckSpecialCondition                                                                  *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: WN_CFG_tstWarningControlStatus *stWarningControlStatus                                      *
*             const WN_CFG_tstWarningAttribute *cstWarningAttribute                                       *
*             const WN_CFG_tstMAIN_OBJECT *cstMainObject                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: HenryChan                                                                                   *
*                                                                                                         *
*Date		: 2018-07-02                                                                                  *
**********************************************************************************************************/
static void WN__vCheckSpecialCondition(WN_CFG_tstWarningControlStatus *stWarningControlStatus,const WN_CFG_tstWarningAttribute *cstWarningAttribute,const WN_CFG_tstMAIN_OBJECT *cstMainObject)
{	
	/*Check extern contol process*/
	if(stWarningControlStatus->unStatus.stStatus.ExternalControlStatus)
	{
		/*Let telltale external control interface set the warning status*/
	}
	/*Check current configration mode process*/
	else if(0 == cstWarningAttribute->u8ConfigurationSwitch)
	{
        /*Current switch is off,so set the warning to default value*/
        stWarningControlStatus->unStatus.stStatus.ResultLogicType = WN_DEFAULT_STATUS;
	}
	/*Check current power mode process*/
    else if (0 == ((cstWarningAttribute->u32WorkPowerMode) & cstMainObject->unPowerModeStatus.u32PowerModeStatus))
    {
    	if(cstMainObject->unPowerModeStatus.u32PowerModeStatus == WN_enABNORMAL_VOLTAGE)
    	{
			;
		}
		else
		{
        	/*Current power mode is not support , so set the warning to default value*/
        	stWarningControlStatus->unStatus.stStatus.ResultLogicType = WN_DEFAULT_STATUS;
		}
    }
    /*Check ignition on response delay status process*/
    else if (stWarningControlStatus->unStatus.stStatus.IgnitionOnResponseDelayStatus)
    {
        /*Always keep previous status*/
		stWarningControlStatus->unStatus.stStatus.ResultLogicType = WN_DEFAULT_STATUS;
    }
    /*Check exit abnormal delay status process*/
#if 0
    else if (stWarningControlStatus->unStatus.stStatus.ExitAbnormalDelayStatus)
    {
        /*Always keep previous status*/
		stWarningControlStatus->unStatus.stStatus.ResultLogicType = stWarningControlStatus->unStatus.stStatus.LastLogicType;
    }
#endif
    else
    {
        /*Do nothing because already saved the logic status*/
    }
}

/**********************************************************************************************************
*Function   : WN__vTimeTaskLoopRollingCount                                                               *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (WN_CFG_tstMAIN_OBJECT) *stMainObject										    		      *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void WN__vTimeTaskLoopRollingCount(WN_CFG_tstMAIN_OBJECT *stMainObject)
{
	if (stMainObject->stCount.u32TimeTaskLoopRateTickCount < 0xFFFFFFFFul)
	{
		stMainObject->stCount.u32TimeTaskLoopRateTickCount ++ ;
	}
	else
	{
		stMainObject->stCount.u32TimeTaskLoopRateTickCount = 0;
	}
}
#define SWC_WN_STOP_SEC_CODE
#include "SWC_WN_MemMap.h" 

/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
