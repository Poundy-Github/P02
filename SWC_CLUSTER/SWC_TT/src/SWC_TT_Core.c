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
*File Name   : TT_Core.c                                                                                  *
*                                                                                                         *
*Description : Telltale module core function source file.                                                 *
*                                                                                                         *
*Author      : Chao Feng                                                                                  *
*                                                                                                         *
*Platform    : Free Rtos System                                                    						  *
*                                                                                                         *
*Compiler    : Green Hills MULTI IDE                                                                      *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family                                                       *
*                                                                                                         *
*Version     : 1.0.0                                                                                      *
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_TT_Core.h"
/**********************************************************************************************************
*																								          *
*																								          *
*	Telltale Module Flag Attribute 															              *
*																								          *
*																								          *
**********************************************************************************************************/
#define SWC_TT_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_TT_MemMap.h"

static boolean boTTRunningFlag = FALSE;

#define SWC_TT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_TT_MemMap.h"


#define SWC_TT_START_SEC_CONST_UNSPECIFIED
#include "SWC_TT_MemMap.h"

static const TT_tstFlagAttribute TT_CORE_stFlag_Attribute[] = TT_CFG_FLAG_ATTRIBUTE;

#define SWC_TT_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_TT_MemMap.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Telltale Module Core Function							    									      *
*																								          *
*																								          *
**********************************************************************************************************/
#define SWC_TT_START_SEC_CODE
#include "SWC_TT_MemMap.h"

static void TT__vCheckLogicProcessReturnValid(TT_tstTelltaleControlStatus *stTelltaleControlStatus , TT_tstMainObject *stMainObject);

static void TT__vCheckSpecialCondition(TT_tstTelltaleControlStatus *stTelltaleControlStatus,const TT_tstTelltaleAttribute *cstTelltaleAttribute,const TT_tstMainObject *cstMainObject);

// void TT__vCheckPowerModeCondition(TT_tstTelltaleControlStatus *stTelltaleControlStatus,const TT_tstTelltaleAttribute *cstTelltaleAttribute,TT_tstMainObject *cstMainObject);

static void TT__vCheckAndSetKeepLightStatus(TT_tstTelltaleControlStatus *stTelltaleControlStatus,const TT_tstTelltaleAttribute *cstTelltaleAttribute,const TT_tstMainObject *cstMainObject);

static void TT__vCheckAndClearKeepLightStatus(TT_tstTelltaleControlStatus *stTelltaleControlStatus,const TT_tstTelltaleAttribute *cstTelltaleAttribute,TT_tstMainObject *stMainObject);

static void TT__vGetLightStatusFromLogicStatus(TT_tstTelltaleControlStatus *stTelltaleControlStatus,/*const TT_tstTelltaleAttribute *cstTelltaleAttribute,*/const TT_tstMainObject *cstMainObject);

static void TT__vLampLightOffProcess(TT_tstTelltaleControlStatus *stTelltaleControlStatus,const TT_tstTelltaleAttribute *cstTelltaleAttribute,TT_tstMainObject *stMainObject);

static void TT__vLampLightOffEdgeProcess(/*TT_tstTelltaleControlStatus *stTelltaleControlStatus,*/const TT_tstTelltaleAttribute *cstTelltaleAttribute,TT_tstMainObject *stMainObject);

static void TT__vLampLightOnProcess(TT_tstTelltaleControlStatus *stTelltaleControlStatus,const TT_tstTelltaleAttribute *cstTelltaleAttribute,TT_tstMainObject *stMainObject);

static void TT__vLampLightOnEdgeProcess(TT_tstTelltaleControlStatus *stTelltaleControlStatus,const TT_tstTelltaleAttribute *cstTelltaleAttribute,TT_tstMainObject *stMainObject);

static void TT__vLampLightCountIncreaseProcess(TT_tstTelltaleControlStatus *stTelltaleControlStatus,const TT_tstTelltaleAttribute *cstTelltaleAttribute);

static void TT__vLightOnHockProcess(const TT_tstTelltaleAttribute *cstTelltaleAttribute);

static void TT__vLightOffHockProcess(const TT_tstTelltaleAttribute *cstTelltaleAttribute);

/**********************************************************************************************************
*Function   : TT_CORE_vProcessControl                                                                     *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (void) *stProcessTable																	  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vProcessControl(const TT_tstPROCESS *stProcessTable, TT_tstMainObject *stMainObject)
{
    boolean boExitProcessButton = FALSE;
    boolean boProcessCodeRespond = FALSE;
    const TT_tstPROCESS *TablePtr;

    TablePtr = stProcessTable;

    while ((TT_DO_NOTHING != *TablePtr->boptrProcess) &&
           (FALSE == boExitProcessButton))
    {
        boProcessCodeRespond = (*TablePtr->boptrProcess)();

        if (boProcessCodeRespond == TRUE)
        {
            if (TT_KEEP_PREVIOUS != TablePtr->u32SucceedEnableStatus)
            {
                stMainObject->unSystemStatus.u32SystemStatus |= (uint32)(TablePtr->u32SucceedEnableStatus);
            }
            else
            {

            }
            if (TT_KEEP_PREVIOUS != TablePtr->u32FaildEnableStatus)
            {
                stMainObject->unSystemStatus.u32SystemStatus &= ~((uint32)(TablePtr->u32FaildEnableStatus));
            }
            else
            {

            }

            if (TT_DO_NOTHING != *TablePtr->vptrAfterSucceedOperation)
            {
                (void)(*TablePtr->vptrAfterSucceedOperation)();
            }
            else
            {

            }
        }
        else
        {
            if (TT_KEEP_PREVIOUS != TablePtr->u32FaildEnableStatus)
            {
                stMainObject->unSystemStatus.u32SystemStatus |= (uint32)(TablePtr->u32FaildEnableStatus);
            }
            else
            {

            }
            if (TT_KEEP_PREVIOUS != TablePtr->u32SucceedEnableStatus)
            {
                stMainObject->unSystemStatus.u32SystemStatus &= ~((uint32)(TablePtr->u32SucceedEnableStatus));
            }
            else
            {

            }

            if (TT_DO_NOTHING != *TablePtr->vptrAfterFaildOperation)
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
*Function   : TT_CORE_vFlagControl                                                                        *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (TT_enFlagProcessStage) enFlagOperationOrder												  *
*             (TT_tstMainObject*) stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vFlagControl(TT_enFlagProcessStage enFlagOperationOrder, TT_tstMainObject *stMainObject)
{
    uint8 u8Index = 0;
    boolean boExitProcessButton = FALSE;
    uint32 u32SetValueTemp = 0u;
    uint32 u32MaskTemp = 0u;

    while (((TT_CORE_stFlag_Attribute[u8Index].u8FlagBitIndex + TT_CORE_stFlag_Attribute[u8Index].u8FlagBitLength) < 32) &&
           (TT_CORE_stFlag_Attribute[u8Index].u8FlagBitLength > 0) &&
           (u8Index < 6) &&
           (FALSE == boExitProcessButton))
    {
        if (enFlagOperationOrder == TT_COLD_INIT)
        {
            u32SetValueTemp = (uint32)TT_CORE_stFlag_Attribute[u8Index].u8ColdInitSetValue;
        }
        else if (enFlagOperationOrder == TT_WARM_INIT)
        {
            u32SetValueTemp = (uint32)TT_CORE_stFlag_Attribute[u8Index].u8WarmInitSetValue;
        }
        else if (enFlagOperationOrder == TT_WAKE_UP)
        {
            u32SetValueTemp = (uint32)TT_CORE_stFlag_Attribute[u8Index].u8WakeUpSetValue;
        }
        else if (enFlagOperationOrder == TT_SLEEP)
        {
            u32SetValueTemp = (uint32)TT_CORE_stFlag_Attribute[u8Index].u8SleepSetValue;
        }
        else if (enFlagOperationOrder == TT_ENTER_ABNORMAL)
        {
            u32SetValueTemp = (uint32)TT_CORE_stFlag_Attribute[u8Index].u8EnterAbnormalSetValue;
        }
        else if (enFlagOperationOrder == TT_EXIT_ABNORMAL)
        {
            u32SetValueTemp = (uint32)TT_CORE_stFlag_Attribute[u8Index].u8ExitAbnormalSetValue;
        }
        else
        {
            u32SetValueTemp = 0;
        }

        if (u32SetValueTemp != (uint32)TT_FLAG_PREVIOUS)
        {
#if (TT_CFG_DEBUG == TRUE) //Check flag set value
            if (8 < TT_CORE_stFlag_Attribute[u8Index].u8FlagBitLength)
            {
#if 0
                printf("\
--Telltale Module Debug: Configration Error-----------------\r\n\
--Function Name : TT_CORE_vFlagControl\r\n\
--Error : Flag Bit length is oversize.Max value is 8.\r\n\
--Flag index : %d\r\n\
--Order enum index : %d\r\n\
------------------------------------------------------------\r\n",
                       u8Index, enFlagOperationOrder);
#endif
            }
            else
            {
            }

            if (((1 << TT_CORE_stFlag_Attribute[u8Index].u8FlagBitLength) - 1) < u32SetValueTemp)
            {
		#if 0
                printf("\
--Telltale Module Debug: Configration Error-----------------\r\n\
--Function Name : TT_CORE_vFlagControl\r\n\
--Error : Flag set value is oversize.\r\n\
--Flag index : %d\r\n\
--Order enum index : %d\r\n\
------------------------------------------------------------\r\n",
                       u8Index, enFlagOperationOrder);
		#endif
            }
            else
            {
            }
#endif
            if (8 >= TT_CORE_stFlag_Attribute[u8Index].u8FlagBitLength)
            {
                uint8 u8BitLen = TT_CORE_stFlag_Attribute[u8Index].u8FlagBitLength;
                uint8 u8BitIndex = TT_CORE_stFlag_Attribute[u8Index].u8FlagBitIndex;

                u32MaskTemp = ((uint32)1u << u8BitLen);
                u32MaskTemp = u32MaskTemp -1u;
                u32MaskTemp = u32MaskTemp << u8BitIndex;

                //u32MaskTemp = (uint32)(((1u << TT_CORE_stFlag_Attribute[u8Index].u8FlagBitLength) - 1u) << TT_CORE_stFlag_Attribute[u8Index].u8FlagBitIndex);

                u32SetValueTemp = (u32SetValueTemp << TT_CORE_stFlag_Attribute[u8Index].u8FlagBitIndex);

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
*Function   : TT_CORE_vSetSystemStatus                                                                    *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (TT_enSystemStatus) enStatus																  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vSetSystemStatus(TT_enSystemStatus enStatus, TT_tstMainObject *stMainObject)
{
    if (enStatus == TT_SYSTEM_DEFAULT)
    {
        stMainObject->unSystemStatus.u32SystemStatus = (uint32)TT_SYSTEM_DEFAULT;
    }
    else
    {
        stMainObject->unSystemStatus.u32SystemStatus |= (uint32)enStatus;
    }
}
/**********************************************************************************************************
*Function   : TT_CORE_vClearSystemStatus                                                                  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (TT_enSystemStatus) enStatus																  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vClearSystemStatus(TT_enSystemStatus enStatus, TT_tstMainObject *stMainObject)
{
    if (enStatus == TT_SYSTEM_DEFAULT)
    {
        //Clear nothing
    }
    else
    {
        stMainObject->unSystemStatus.u32SystemStatus &= ~((uint32)enStatus);
    }
}
/**********************************************************************************************************
*Function   : TT_CORE_boCheckSystemStatus                                                                 *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (TT_enSystemStatus) enStatus																  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_CORE_boCheckSystemStatus(TT_enSystemStatus enStatus, TT_tstMainObject *stMainObject)
{
    boolean boReturn = FALSE;
    if (enStatus == TT_SYSTEM_DEFAULT)
    {
        //Check nothing so return False
    }
    else if ((stMainObject->unSystemStatus.u32SystemStatus & (uint32)enStatus) != FALSE)
    {
        boReturn = TRUE;
    }
    else
    {
    }
    return boReturn;
}
/**********************************************************************************************************
*Function   : TT_CORE_vCheckModuleConfigration                                                            *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if (TT_CFG_DEBUG == TRUE) //Check module configration is valid
void TT_CORE_vCheckModuleConfigration(void)
{
    #if 0
    boolean boResult = 0;
    uint8 u8Index = 0;
    TT_tstFlashAttribute stFlashAttribute[TT_enSTATUS_TOTAL_NUMBER - TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER] = TT_CFG_FLASH_ATTRIBUTE;
    TT_tstTelltaleAttribute stTelltaleAttribute[TT_enTELLTALE_TOTAL_NUMBER] = TT_CFG_TELLTALE_CONTROL_ATTRIBUTE;
    TT_tstLogicProcessAttribute stLogicProcessAttribute[] = {TT_CFG_LOGIC_PROCESS_ATTRIBUTE
															{TT_DO_NOTHING,(TT_enLogicProcessMode)TT_NULL}};

#if (TT_CFG_TIME_TASK_CYCLE > 0)
#else
    printf("\
--Telltale Module Debug: Configration Error-----------------\r\n\
--Function Name : TT_CORE_vCheckModuleConfigration\r\n\
--Error : TT_CFG_TIME_TASK_CYCLE set value is invalid.\r\n\
------------------------------------------------------------\r\n");
#endif

#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_USE_GPIO) | (TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_USE_STM) | (TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_SBUS))
#else
    printf("\
--Telltale Module Debug: Configration Error-----------------\r\n\
--Function Name : TT_CORE_vCheckModuleConfigration\r\n\
--Error : TT_CFG_OUTPUT_MODE set value is invalid.\r\n\
------------------------------------------------------------\r\n");
#endif

    if (TT_enSTATUS_TOTAL_NUMBER > 16)/*16bit Length*/
    {
        printf("\
--Telltale Module Debug: Configration Error-----------------\r\n\
--Function Name : TT_CORE_vCheckModuleConfigration\r\n\
--Error : TT_enSTATUS_TOTAL_NUMBER value is over size.\r\n\
------------------------------------------------------------\r\n");
    }
    else
    {
    }

    if (TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER <= TT_enSTATUS_TOTAL_NUMBER)
    {
        for (u8Index = 0; u8Index < TT_enSTATUS_TOTAL_NUMBER - TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER; u8Index++)
        {
        	if (stFlashAttribute[u8Index].u8Offset > 100)
            {
                printf("\
--Telltale Module Debug: Configration Error-----------------\r\n\
--Function Name : TT_CORE_vCheckModuleConfigration\r\n\
--Error : Offset percent set value is more than 100(100%).\r\n\
--Flash index : %d\r\n\
------------------------------------------------------------\r\n",
                       u8Index);
            }
            else
            {
            }

            if (stFlashAttribute[u8Index].u8Duty >= 100)
            {
                printf("\
--Telltale Module Debug: Configration Error-----------------\r\n\
--Function Name : TT_CORE_vCheckModuleConfigration\r\n\
--Error : Flash status duty set value is equal or more than 100(100%).\r\n\
--Flash index : %d\r\n\
------------------------------------------------------------\r\n",
                       u8Index);
            }
            else if (stFlashAttribute[u8Index].u8Duty == 0)
            {
                printf("\
--Telltale Module Debug: Configration Error-----------------\r\n\
--Function Name : TT_CORE_vCheckModuleConfigration\r\n\
--Error : Flash status duty set value is equal 0(0%).\r\n\
--Flash index : %d\r\n\
------------------------------------------------------------\r\n",
                       u8Index);
            }

			if (stFlashAttribute[u8Index].u8RisingEdgeSyncPercent > 100)
            {
                printf("\
--Telltale Module Debug: Configration Error-----------------\r\n\
--Function Name : TT_CORE_vCheckModuleConfigration\r\n\
--Error : Rising edge synchronous percent set value is more than 100(100%).\r\n\
--Flash index : %d\r\n\
------------------------------------------------------------\r\n",
                       u8Index);
            }
            else
            {
            }

			if (stFlashAttribute[u8Index].u8FaillingEdgeSyncPercent > 100)
            {
                printf("\
--Telltale Module Debug: Configration Error-----------------\r\n\
--Function Name : TT_CORE_vCheckModuleConfigration\r\n\
--Error : Failling edge synchronous percent set value is more than 100(100%).\r\n\
--Flash index : %d\r\n\
------------------------------------------------------------\r\n",
                       u8Index);
            }
            else
            {
            }

			if (stFlashAttribute[u8Index].u16CycleCount < 10)
            {
                printf("\
--Telltale Module Debug: Configration Error-----------------\r\n\
--Function Name : TT_CORE_vCheckModuleConfigration\r\n\
--Error : Flash status set frequency is too high.\r\n\
--Commont :Under the current time task setting , setting too high\
           frequence leads to too low accurary.\
--Flash index : %d\r\n\
------------------------------------------------------------\r\n",
                       u8Index);
            }
            else
            {
            }
        }
    }
    else
    {
        printf("\
--Telltale Module Debug: Configration Error-----------------\r\n\
--Function Name : TT_CORE_vCheckModuleConfigration\r\n\
--Error : TT_enSTATUS_TOTAL_NUMBER value is invalid.\r\n\
------------------------------------------------------------\r\n");
    }

	u8Index = 0;
	while(TT_DO_NOTHING != stLogicProcessAttribute[u8Index].vptrTelltaleLogicOperation)
	{
		if (!((stLogicProcessAttribute[u8Index].u32LogicProcessMode & TT_enINTERFACE) |
              (stLogicProcessAttribute[u8Index].u32LogicProcessMode & TT_enTIME_TASK) |
              (stLogicProcessAttribute[u8Index].u32LogicProcessMode & TT_enROBIN_TASK)))
        {
        	printf("\
--Telltale Module Debug: Configration Error-----------------\r\n\
--Function Name : TT_CORE_vCheckModuleConfigration\r\n\
--Error : Telltall logic process mode value is invalid.\r\n\
--Telltale index : %d\r\n\
------------------------------------------------------------\r\n",
                       u8Index);
        }
        else
        {

        }
		u8Index++;
	}

    if (TT_enSTATUS_TOTAL_NUMBER < 16)
    {
        for (u8Index = 0; u8Index < TT_enTELLTALE_TOTAL_NUMBER; u8Index++)
        {
            boResult = FALSE;

            if (((TT_enGPIO_POSITIVE_OUTPUT & stTelltaleAttribute[u8Index].u32OutputMode))\
				&& ((TT_enGPIO_NEGATIVE_OUTPUT & stTelltaleAttribute[u8Index].u32OutputMode)\
				|| (TT_enSTM_POSITIVE_OUTPUT & stTelltaleAttribute[u8Index].u32OutputMode)\
				||(TT_enSTM_NEGATIVE_OUTPUT & stTelltaleAttribute[u8Index].u32OutputMode)))
            {
                boResult = FALSE;
            }
            else if (((TT_enGPIO_NEGATIVE_OUTPUT & stTelltaleAttribute[u8Index].u32OutputMode))\
				&& ((TT_enGPIO_POSITIVE_OUTPUT & stTelltaleAttribute[u8Index].u32OutputMode)\
				|| (TT_enSTM_POSITIVE_OUTPUT & stTelltaleAttribute[u8Index].u32OutputMode)\
				||(TT_enSTM_NEGATIVE_OUTPUT & stTelltaleAttribute[u8Index].u32OutputMode)))
			{
                boResult = FALSE;
            }
            else if (((TT_enSTM_POSITIVE_OUTPUT & stTelltaleAttribute[u8Index].u32OutputMode))\
				&& ((TT_enGPIO_POSITIVE_OUTPUT & stTelltaleAttribute[u8Index].u32OutputMode)\
				|| (TT_enGPIO_NEGATIVE_OUTPUT & stTelltaleAttribute[u8Index].u32OutputMode)\
				||(TT_enSTM_NEGATIVE_OUTPUT & stTelltaleAttribute[u8Index].u32OutputMode)))
			{
                boResult = FALSE;
            }
            else if (((TT_enSTM_NEGATIVE_OUTPUT & stTelltaleAttribute[u8Index].u32OutputMode))\
				&& ((TT_enGPIO_POSITIVE_OUTPUT & stTelltaleAttribute[u8Index].u32OutputMode)\
				|| (TT_enGPIO_NEGATIVE_OUTPUT & stTelltaleAttribute[u8Index].u32OutputMode)\
				||(TT_enSTM_POSITIVE_OUTPUT & stTelltaleAttribute[u8Index].u32OutputMode)))
			{
                boResult = FALSE;
            }
            else
            {
                boResult = TRUE;
            }

            if (boResult)
            {
                /*No error*/
            }
            else
            {
                printf("\
--Telltale Module Debug: Configration Error-----------------\r\n\
--Function Name : TT_CORE_vCheckModuleConfigration\r\n\
--Error : Telltall output mode value is invalid.\r\n\
--Telltale index : %d\r\n\
------------------------------------------------------------\r\n",
                       u8Index);
            }
        }
    }
    else
    {
        printf("\
--Telltale Module Debug: Configration Error-----------------\r\n\
--Function Name : TT_CORE_vCheckModuleConfigration\r\n\
--Error : TT_enTELLTALE_TOTAL_NUMBER value is over size.\r\n\
------------------------------------------------------------\r\n");
    }
    #endif
}
#endif //(TT_CFG_DEBUG == TRUE)
/**********************************************************************************************************
*Function   : TT_CORE_vDebugModeOperation                                                                 *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: (TT_tstMainObject) *stMainObject                                                            *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if (TT_CFG_DEBUG == TRUE)
void TT_CORE_vDebugModeOperation(TT_tstMainObject *stMainObject)
{
	uint8 u8Index;
	/*Save flash name when system in debug mode*/
	for(u8Index=0; u8Index < TT_enSTATUS_TOTAL_NUMBER; u8Index++)
    {
		stMainObject->stFlashControlStatus[u8Index].enFlashName = (TT_CFG_enStatusType)(u8Index + TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER);
    }

	/*Save telltall name when system in debug mode*/
	for(u8Index=0; u8Index < TT_enTELLTALE_TOTAL_NUMBER; u8Index++)
    {
    	stMainObject->stTelltaleControlStatus[u8Index].enTelltaleName = (TT_CFG_enTelltaleID)u8Index;
    }
}
#endif //(TT_CFG_DEBUG == TRUE)
/**********************************************************************************************************
*Function   : TT_CORE_u8GetTelltaleLogicStatus                                                            *
*                                                                                                         *
*Description: The function is used to get telltale flash status .                                         *
*			                                                                                              *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID                                                          *
*                                                                                                         *
*Return 	: Flash status type                                                                           *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
TT_CFG_enStatusType TT_CORE_u8GetTelltaleLogicStatus(TT_CFG_enTelltaleID enTelltaleID,TT_tstMainObject *stMainObject)
{
	TT_CFG_enStatusType enReturn;

	enReturn = (enTelltaleID < TT_enTELLTALE_TOTAL_NUMBER) ? stMainObject->stTelltaleControlStatus[enTelltaleID].unStatus.stStatus.LogicType : TT_enTURN_OFF;

	return(enReturn);
}
/**********************************************************************************************************
*Function   : TT_CORE_u8GetTelltaleResultLogicStatus                                                      *
*                                                                                                         *
*Description: The function is used to get result telltale flash status .                                  *
*			                                                                                              *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID                                                          *
*                                                                                                         *
*Return 	: Flash status type                                                                           *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
TT_CFG_enStatusType TT_CORE_u8GetTelltaleResultLogicStatus(TT_CFG_enTelltaleID enTelltaleID,TT_tstMainObject *stMainObject)
{
	TT_CFG_enStatusType enReturn;

	enReturn = (enTelltaleID < TT_enTELLTALE_TOTAL_NUMBER) ? stMainObject->stTelltaleControlStatus[enTelltaleID].unStatus.stStatus.ResultLogicType : TT_enTURN_OFF;

	return(enReturn);
}
/**********************************************************************************************************
*Function   : TT_CORE_u8GetTelltaleExternaLogiclStatus                                                    *
*                                                                                                         *
*Description: The function is used to get telltale flash status by external control .                     *
*			                                                                                              *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID                                                          *
*                                                                                                         *
*Return 	: Flash status type                                                                           *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
TT_CFG_enStatusType TT_CORE_u8GetTelltaleExternalLogicStatus(TT_CFG_enTelltaleID enTelltaleID,TT_tstMainObject *stMainObject)
{
	TT_CFG_enStatusType enReturn;

	enReturn = (enTelltaleID < TT_enTELLTALE_TOTAL_NUMBER) ? stMainObject->stTelltaleControlStatus[enTelltaleID].unStatus.stStatus.ExternalLogicType : TT_enTURN_OFF;

	return(enReturn);
}
/**********************************************************************************************************
*Function   : TT_CORE_enGetLampStatus                                                                     *
*                                                                                                         *
*Description: The function is used to get current lamp status of telltale                                 *
*			                                                                                              *
*Parameter	: (TT_CFG_enTelltaleID) u8TelltaleID                                                          *
*                                                                                                         *
*Return 	: TT_enLampStatus                                                                             *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
TT_enLampStatus TT_CORE_enGetLampStatus(TT_CFG_enTelltaleID enTelltaleID,TT_tstMainObject *stMainObject)
{
    TT_enLampStatus enReturn;

	enReturn = (enTelltaleID < TT_enTELLTALE_TOTAL_NUMBER) ? stMainObject->stTelltaleControlStatus[enTelltaleID].unStatus.stStatus.LightType : TT_enLAMP_OFF_EDGE;

    return (enReturn);
}
/**********************************************************************************************************
*Function   : TT_CORE_boGetLampOnOffStatus                                                                *
*                                                                                                         *
*Description: The function is used to get current lamp status of telltale                                 *
*			                                                                                              *
*Parameter	: (UINT8) u8TelltaleID	                                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_CORE_boGetLampOnOffStatus(TT_CFG_enTelltaleID enTelltaleID,TT_tstMainObject *stMainObject)
{
    TT_enLampStatus enLampStatusTemp;
    boolean boReturn;

    enLampStatusTemp = TT_CORE_enGetLampStatus(enTelltaleID,stMainObject);

	boReturn = ((TT_enLAMP_ON == enLampStatusTemp)||(TT_enLAMP_ON_EDGE == enLampStatusTemp)) ? TRUE : FALSE;

    return (boReturn);
}
/**********************************************************************************************************
*Function   : TT_CORE_enGetFlashTypeStatus                                                                *
*                                                                                                         *
*Description: The function is used to get current lamp status of flash type                               *
*			                                                                                              *
*Parameter	: (TT_CFG_enStatusType) u8TelltaleID	                                                      *
*                                                                                                         *
*Return 	: TT_enLampStatus                                                                             *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
TT_enLampStatus TT_CORE_enGetFlashTypeStatus(TT_CFG_enStatusType enStatusTypeID,TT_tstMainObject *stMainObject)
{
    TT_enLampStatus enReturn;

    if(TT_enTURN_OFF == enStatusTypeID)
    {
        enReturn = TT_enLAMP_OFF;
    }
    else if(TT_enTURN_ON == enStatusTypeID)
    {
        enReturn = TT_enLAMP_ON;
    }
    else if(TT_enSELF_CHECK == enStatusTypeID)
    {
        enReturn = TT_enLAMP_ON;
    }
    else if(enStatusTypeID < TT_enSTATUS_TOTAL_NUMBER)
    {
        enReturn = stMainObject->stFlashControlStatus[(uint8)enStatusTypeID - (uint8)TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER].unStatus.stStatus.LightType;
    }
    else
    {
        /*Do nothing because request status ID out of bound */
        enReturn = TT_enLAMP_OFF;
    }
    return(enReturn);
}
/**********************************************************************************************************
*Function   : TT_CORE_boGetFlashTypeOnOffStatus                                                           *
*                                                                                                         *
*Description: The function is used to get current lamp status of flash type                               *
*			                                                                                              *
*Parameter	: (TT_CFG_enStatusType) u8TelltaleID	                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_CORE_boGetFlashTypeOnOffStatus(TT_CFG_enStatusType u8StatusTypeID,TT_tstMainObject *stMainObject)
{
    TT_enLampStatus enLampStatusTemp;
    boolean boReturn;

    enLampStatusTemp = TT_CORE_enGetFlashTypeStatus(u8StatusTypeID,stMainObject);

	boReturn = ((TT_enLAMP_ON == enLampStatusTemp)||(TT_enLAMP_ON_EDGE == enLampStatusTemp)) ? TRUE : FALSE;

    return (boReturn);
}
/**********************************************************************************************************
*Function   : TT_API_u8GetTelltaleLightCountStatus                                                        *
*                                                                                                         *
*Description: The function is used to get current telltale light count status .                           *
*			                                                                                              *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID                                                          *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_CORE_boGetTelltaleFlashFinishStatus(TT_CFG_enTelltaleID enTelltaleID,const TT_tstTelltaleAttribute *cstTelltaleAttribute,TT_tstMainObject *stMainObject)
{
	boolean boReturn;

	if(enTelltaleID < TT_enTELLTALE_TOTAL_NUMBER)
	{
		if(stMainObject->stTelltaleControlStatus[enTelltaleID].u8CurrentLightCount \
		  >= cstTelltaleAttribute[enTelltaleID].u8LightCountLimit)
		{
			boReturn = TRUE;/*Flash is finish*/
		}
		else
		{
			boReturn = FALSE;
		}
	}
	else
	{
		/*Return default value because request telltale ID out of bound */
		boReturn = FALSE;
	}
	return(boReturn);
}
/**********************************************************************************************************
*Function   : TT_CORE_vStopTelltaleSelfCheck                                                              *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID														  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vStopTelltaleSelfCheck(uint8 enTelltaleID, TT_tstMainObject *stMainObject)
{
    if (enTelltaleID < TT_enTELLTALE_TOTAL_NUMBER)
    {
        stMainObject->stTelltaleControlStatus[enTelltaleID].u16SelfCheckTimeTick = stMainObject->stTelltaleControlStatus[enTelltaleID].u16SelfCheckFinishTickCount;
    }
    else
    {
        /*Do nothing because request telltale ID out bound */
    }
}
/**********************************************************************************************************
*Function   : TT_CORE_vStopAllTelltaleSelfCheck                                                           *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vStopAllTelltaleSelfCheck(TT_tstMainObject *stMainObject)
{
	uint8 enIndex = 0;

	for (enIndex = 0; enIndex < TT_enTELLTALE_TOTAL_NUMBER; enIndex++)
	{
		TT_CORE_vStopTelltaleSelfCheck(enIndex, stMainObject);
	}
}
/**********************************************************************************************************
*Function   : TT_CORE_vRestartTelltaleSelfCheck                                                           *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID														  *
*             (TT_tstMainObject) *stMainObject															  *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vRestartTelltaleSelfCheck(uint8 enTelltaleID,TT_tstMainObject *stMainObject)
{
    if (enTelltaleID < TT_enTELLTALE_TOTAL_NUMBER)
    {
        stMainObject->stTelltaleControlStatus[enTelltaleID].u16SelfCheckTimeTick = 0;
    }
    else
    {
        /*Do nothing because request telltale ID out bound */
    }
}
/**********************************************************************************************************
*Function   : TT_CORE_vRestartAllTelltaleSelfCheck                                                        *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vRestartAllTelltaleSelfCheck(TT_tstMainObject *stMainObject)
{
    uint8 enIndex = 0;

    for (enIndex = 0; enIndex < TT_enTELLTALE_TOTAL_NUMBER; enIndex++)
    {
        TT_CORE_vRestartTelltaleSelfCheck(enIndex,stMainObject);
    }
}
/**********************************************************************************************************
*Function   : TT_CORE_vSetTelltaleSelfCheckTime                                                           *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID														  *
*             (UINT16) u16Time																			  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vSetTelltaleSelfCheckTime(TT_CFG_enTelltaleID enTelltaleID, const uint16 u16Time, TT_tstMainObject *stMainObject)
{
    const uint16 u16SetMaxTick = u16Time / TT_CFG_TIME_TASK_CYCLE;

    if (enTelltaleID < TT_enTELLTALE_TOTAL_NUMBER)
    {
        /*Avoid prove out status change*/
        if ((stMainObject->stTelltaleControlStatus[enTelltaleID].u16SelfCheckTimeTick >= stMainObject->stTelltaleControlStatus[enTelltaleID].u16SelfCheckFinishTickCount) \
		&& (stMainObject->stTelltaleControlStatus[enTelltaleID].u16SelfCheckTimeTick < u16SetMaxTick))
        {
            stMainObject->stTelltaleControlStatus[enTelltaleID].u16SelfCheckTimeTick = u16SetMaxTick;
        }
        else
        {
            /*Do nothing but but Avoid QAC warning */
        }
		stMainObject->stTelltaleControlStatus[enTelltaleID].u16SelfCheckFinishTickCount = u16SetMaxTick;
    }
    else
    {
        /*Do nothing because request telltale ID out bound */
    }
}
/**********************************************************************************************************
*Function   : TT_CORE_vSetTelltaleSelfCheckTime                                                            *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID														  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if 0
uint16 TT_CORE_u16GetTelltaleSelfCheckRunningTime(TT_CFG_enTelltaleID enTelltaleID,TT_tstMainObject *stMainObject)
{
	uint16 u16RunningTime = 0;

	if (enTelltaleID < TT_enTELLTALE_TOTAL_NUMBER)
	{
		/*Avoid prove out status change*/
		if (stMainObject->stTelltaleControlStatus[enTelltaleID].u16SelfCheckTimeTick <= stMainObject->stTelltaleControlStatus[enTelltaleID].u16SelfCheckFinishTickCount)
		{
			u16RunningTime = stMainObject->stTelltaleControlStatus[enTelltaleID].u16SelfCheckTimeTick ;
		}
		else
		{
			u16RunningTime = stMainObject->stTelltaleControlStatus[enTelltaleID].u16SelfCheckFinishTickCount ;
		}
	}
	else
	{
		/*Do nothing because request telltale ID out bound */
	}

	u16RunningTime = u16RunningTime / TT_CFG_TIME_TASK_CYCLE;

	return u16RunningTime;
}
#endif
/**********************************************************************************************************
*Function   : TT_CORE_vRestartAllTelltaleIgnOnResponseDelayStatus                                         *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vRestartAllTelltaleIgnOnResponseDelayStatus(TT_tstMainObject *stMainObject)
{
    uint8 enIndex = 0;

    for (enIndex = 0; enIndex < TT_enTELLTALE_TOTAL_NUMBER; enIndex++)
    {
        stMainObject->stTelltaleControlStatus[enIndex].u16IgnOnDelayTimeTick = 0;
    }
}
/**********************************************************************************************************
*Function	: TT_CORE_vSetTelltaleExternalControlStatus													  *
*																										  *
*Description: TBD																						  *
*																										  *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID														  *
*             (TT_CFG_enStatusType) enLogicStatus														  *
*             (TT_tstMainObject) *stMainObject															  *
*																										  *
*Return 	: void																						  *
*																										  *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vSetTelltaleExternalControlStatus(uint8 enTelltaleID,TT_CFG_enStatusType enLogicStatus,TT_tstMainObject* stMainObject)
{
	if((enTelltaleID < TT_enTELLTALE_TOTAL_NUMBER)\
	&&(enLogicStatus < TT_enSTATUS_TOTAL_NUMBER)\
	&&(enLogicStatus != TT_enSELF_CHECK))
	{
		stMainObject->stTelltaleControlStatus[enTelltaleID].unStatus.stStatus.ExternalLogicType = enLogicStatus;
	}
	else
	{
		/*Do nothing because request telltale ID or set logic status index out of bound */
	}
}
/**********************************************************************************************************
*Function   : TT_CORE_vTelltaleExternalControlEnable                                                      *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID														  *
*             (TT_tstMainObject) *stMainObject															  *
*																										  *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vTelltaleExternalControlEnable(uint8 enTelltaleID,TT_tstMainObject *stMainObject)
{
	if (enTelltaleID < TT_enTELLTALE_TOTAL_NUMBER)
    {
		stMainObject->stTelltaleControlStatus[enTelltaleID].unStatus.stStatus.ExternalControlStatus = 1;
    }
    else
    {
        /*Do nothing because request telltale ID out bound */
    }
}
/**********************************************************************************************************
*Function   : TT_CORE_vTelltaleExternalControlDisable                                                     *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID														  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vTelltaleExternalControlDisable(TT_CFG_enTelltaleID enTelltaleID,TT_tstMainObject *stMainObject)
{
	if (enTelltaleID < TT_enTELLTALE_TOTAL_NUMBER)
    {
		stMainObject->stTelltaleControlStatus[enTelltaleID].unStatus.stStatus.ExternalControlStatus = 0;
		stMainObject->stTelltaleControlStatus[enTelltaleID].unStatus.stStatus.ExternalLogicType = TT_enTURN_OFF;
    }
    else
    {
        /*Do nothing because request telltale ID out bound */
    }
}
/**********************************************************************************************************
*Function   : TT_CORE_vTelltaleExternalControlDisable                                                     *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_CFG_enTelltaleID) enTelltaleID														  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_CORE_boGetTelltaleExternalControlStatus(TT_CFG_enTelltaleID enTelltaleID,TT_tstMainObject *stMainObject)
{
	boolean boReturn;
	if (enTelltaleID < TT_enTELLTALE_TOTAL_NUMBER)
    {
		if(stMainObject->stTelltaleControlStatus[enTelltaleID].unStatus.stStatus.ExternalControlStatus)
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
*Function   : TT_CORE_vCalculateDelayTimerMaxCount                                                        *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleAttribute) *cstTelltaleAttribute											  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vCalculateDelayTimerMaxCount(const TT_tstTelltaleAttribute *cstTelltaleAttribute, TT_tstMainObject *stMainObject)
{
    uint8 u8Index = 0;

    const uint8 u8Factor = TT_CFG_TIME_TASK_CYCLE;

    /*Clear max count*/
    stMainObject->stCount.u16ExitAbnormalResponseDelayMaxTickCount = 0;

    for (u8Index = 0; u8Index < TT_enTELLTALE_TOTAL_NUMBER; u8Index++)
    {

#if (TT_CFG_DEBUG ==TRUE)
		if(u8Index == enFTT_LowFuelPress)
		{
			u8Index = u8Index;
		}
#endif //(TT_CFG_DEBUG ==TRUE)

        /*If count value greater than u16ExitAbnormalResponseDelayMaxTickCount ,set to this value*/
        if (cstTelltaleAttribute[u8Index].u16ExitAbnormalResponseDelayTime > (stMainObject->stCount.u16ExitAbnormalResponseDelayMaxTickCount * u8Factor))
        {
            stMainObject->stCount.u16ExitAbnormalResponseDelayMaxTickCount = (cstTelltaleAttribute[u8Index].u16ExitAbnormalResponseDelayTime / u8Factor);
        }
        else
        {
            /*Do nothing but avoid QAC warning*/
        }
        /*Set every telltale this parameter*/
        stMainObject->stTelltaleControlStatus[u8Index].u16SelfCheckFinishTickCount = (cstTelltaleAttribute[u8Index].u16SelfCheckTime / u8Factor);
    }
}
/**********************************************************************************************************
*Function   : TT_CORE_vCheckResponseDelayStatus                                                           *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleAttribute) *cstTelltaleAttribute											  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vCheckResponseDelayStatus (const TT_tstTelltaleAttribute *cstTelltaleAttribute, TT_tstMainObject *stMainObject)
{
	uint8 u8Factor = TT_CFG_TIME_TASK_CYCLE;
	uint8 u8Index = 0;

	/*Clear the global self check flag*/
	//stMainObject->unFunctionFlag.stFuncFlag.GlobalSelfCheckFlag = 0;

	for (u8Index = 0; u8Index < TT_enTELLTALE_TOTAL_NUMBER; u8Index++)
    {
    	/*If tick value less than u16ExitAbnormalResponseDelayTime , set u8ExitAbnormalDelayStatus to 1*/
        if ((stMainObject->stTelltaleControlStatus[u8Index].u16IgnOnDelayTimeTick * u8Factor) < cstTelltaleAttribute[u8Index].u16IgnOnResponseDelayTime)
        {
            stMainObject->stTelltaleControlStatus[u8Index].unStatus.stStatus.IgnitionOnResponseDelayStatus = 1;
        }
        else
        {
            stMainObject->stTelltaleControlStatus[u8Index].unStatus.stStatus.IgnitionOnResponseDelayStatus = 0;
        }

        /*If tick value less than u16ExitAbnormalResponseDelayTime , set u8ExitAbnormalDelayStatus to 1*/
        if ((stMainObject->stTimer.u16ExitAbnormalResponseDelayDelayTick * u8Factor) < cstTelltaleAttribute[u8Index].u16ExitAbnormalResponseDelayTime)
        {
            stMainObject->stTelltaleControlStatus[u8Index].unStatus.stStatus.ExitAbnormalDelayStatus = 1;
        }
        else
        {
            stMainObject->stTelltaleControlStatus[u8Index].unStatus.stStatus.ExitAbnormalDelayStatus = 0;
        }


	 #if 0
        /*If tick value less than u16ProveOutTime , set u8ProveOutStatus to 1*/
        if ((stMainObject->stTelltaleControlStatus[u8Index].u16SelfCheckTimeTick) < stMainObject->stTelltaleControlStatus[u8Index].u16SelfCheckFinishTickCount)
        {
        	/*Set the global self check flag*/
			stMainObject->unFunctionFlag.stFuncFlag.GlobalSelfCheckFlag = 1;

            stMainObject->stTelltaleControlStatus[u8Index].unStatus.stStatus.SelfCheckStatus = 1;
        }
        else
        {
            stMainObject->stTelltaleControlStatus[u8Index].unStatus.stStatus.SelfCheckStatus = 0;
        }
   	 #endif

         /*If tick value less than u16ProveOutTime , set u8ProveOutStatus to 1*/
        if (stMainObject->stTelltaleControlStatus[u8Index].u16SelfCheckFinishTickCount)
        {
        	/*Set the global self check flag*/
			stMainObject->unFunctionFlag.stFuncFlag.GlobalSelfCheckFlag = 1;

            stMainObject->stTelltaleControlStatus[u8Index].unStatus.stStatus.SelfCheckStatus = 1;
        }
        else
        {
            stMainObject->stTelltaleControlStatus[u8Index].unStatus.stStatus.SelfCheckStatus = 0;
        }

    }
	#if 0
	for (u8Index = 0; u8Index < TT_enTELLTALE_TOTAL_NUMBER; u8Index++)
	{
    	if((cstTelltaleAttribute->u32ControlAttribute & TT_enIGN_ON_RESPONSE_DELAY_START_AFTER_ALL_SELF_CHECK_FINISH)\
		 &&(stMainObject->unFunctionFlag.stFuncFlag.GlobalSelfCheckFlag))
		{
			stMainObject->stTelltaleControlStatus[u8Index].unStatus.stStatus.IgnitionOnResponseDelayStatus = 1;
		}
		/*If tick value less than u16IgnOnResponseDelayTime , set u8IgnitionOnResponseDelayStatus to 1*/
        else if ((stMainObject->stTelltaleControlStatus[u8Index].u16IgnOnDelayTimeTick * u8Factor) < cstTelltaleAttribute[u8Index].u16IgnOnResponseDelayTime)
        {
            stMainObject->stTelltaleControlStatus[u8Index].unStatus.stStatus.IgnitionOnResponseDelayStatus = 1;
        }
        else
        {
            stMainObject->stTelltaleControlStatus[u8Index].unStatus.stStatus.IgnitionOnResponseDelayStatus = 0;
        }
	}
	#endif
}
/**********************************************************************************************************
*Function   : TT_CORE_vResponseDelayStatusTickPlus                                                        *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vResponseDelayStatusTickPlus(const TT_tstTelltaleAttribute *cstTelltaleAttribute,TT_tstMainObject *stMainObject)
{
	const uint16 u16TickPlus = 1;
	uint8 u8Factor = TT_CFG_TIME_TASK_CYCLE;
	uint8 u8Index = 0;

	for (u8Index = 0; u8Index < TT_enTELLTALE_TOTAL_NUMBER; u8Index++)
    {
		/*Self check time tick plus*/
        if (stMainObject->stTelltaleControlStatus[u8Index].u16SelfCheckTimeTick < stMainObject->stTelltaleControlStatus[u8Index].u16SelfCheckFinishTickCount)
        {
            stMainObject->stTelltaleControlStatus[u8Index].u16SelfCheckTimeTick += u16TickPlus;
        }
        else
        {
            /*Do nothing but avoid QAC warning*/
        }

		if (stMainObject->unPowerModeStatus.u32PowerModeStatus == TT_enRUN)
		{
			if ((stMainObject->stTelltaleControlStatus[u8Index].u16IgnOnDelayTimeTick * u8Factor) < cstTelltaleAttribute[u8Index].u16IgnOnResponseDelayTime)
		    {
		        stMainObject->stTelltaleControlStatus[u8Index].u16IgnOnDelayTimeTick += u16TickPlus;
		    }
		    else
		    {
		        /*Do nothing but avoid QAC warning*/
		    }
		}
		else
		{
			stMainObject->stTelltaleControlStatus[u8Index].u16IgnOnDelayTimeTick = 150;		// 3000ms
		}
		#if 0
		/*Ign on delay time tick plus*/
        if((cstTelltaleAttribute->u32ControlAttribute & TT_enIGN_ON_RESPONSE_DELAY_START_AFTER_ALL_SELF_CHECK_FINISH)\
		 &&(stMainObject->unFunctionFlag.stFuncFlag.GlobalSelfCheckFlag))
		{
			/*Delay when self check is finished.*/
			stMainObject->stTelltaleControlStatus[u8Index].u16IgnOnDelayTimeTick = 0;
		}
	    else if ((stMainObject->stTelltaleControlStatus[u8Index].u16IgnOnDelayTimeTick * u8Factor) < cstTelltaleAttribute->u16IgnOnResponseDelayTime )
	    {
	        stMainObject->stTelltaleControlStatus[u8Index].u16IgnOnDelayTimeTick += u16TickPlus;
	    }
	    else
	    {
	        /*Do nothing but avoid QAC warning*/
	    }
		#endif
    }

	/*Exit abnormal response time tick plus*/
    if (stMainObject->stTimer.u16ExitAbnormalResponseDelayDelayTick < stMainObject->stCount.u16ExitAbnormalResponseDelayMaxTickCount)
    {
        stMainObject->stTimer.u16ExitAbnormalResponseDelayDelayTick += u16TickPlus;
    }
    else
    {
        /*Do nothing but avoid QAC warning*/
    }

}
/**********************************************************************************************************
*Function   : TT_CORE_vSetFlashStatusOffset                                                               *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleAttribute) *cstTelltaleAttribute											  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vSetFlashStatusOffset(const TT_tstFlashAttribute *cstFlashAttribute, TT_tstMainObject *stMainObject)
{
    uint8 u8Index = 0;
	if (TT_enSTATUS_TOTAL_NUMBER > TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER)
    {
        for (u8Index = 0; u8Index < ((uint8)TT_enSTATUS_TOTAL_NUMBER - (uint8)TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER); u8Index++)
        {
			stMainObject->stTimer.u16FlashTimeTick[u8Index] = \
			(uint16)((uint32)cstFlashAttribute[u8Index].u16CycleCount * (uint32)cstFlashAttribute[u8Index].u8Offset / 100);

            stMainObject->stTimer.u16FlashTimeTick[u8Index] %= cstFlashAttribute[u8Index].u16CycleCount;
        }
	}
}
/**********************************************************************************************************
*Function   : TT_CORE_vCalculateFlashReferenceStatus                                                      *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleAttribute) *cstTelltaleAttribute											  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vCalculateFlashReferenceStatus(const TT_tstFlashAttribute *cstFlashAttribute, TT_tstMainObject *stMainObject)
{
	uint16 u16TickCountTemp = 0;
    uint16 u16LampOffCountTemp = 0;
    uint16 u16LampOnCountTemp = 0;
    uint16 u16RisingEdgeSyncCountTemp = 0;
    uint16 u16FaillingEdgeSyncCountTemp = 0;
    uint8 u8Index = 0;
    TT_enLampStatus enLampStatusTemp = TT_enLAMP_OFF_EDGE;
	/*modify by fchao in 20200512 for QAC
    TT_enLampStatus enLastLampStatusTemp = (TT_enLampStatus)0;
	*/

    if (TT_enSTATUS_TOTAL_NUMBER > TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER)
    {
        for (u8Index = 0; u8Index < ((uint8)TT_enSTATUS_TOTAL_NUMBER - (uint8)TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER); u8Index++)
        {
            /*Save last flash light status to temporary variable*/
            /*modify by fchao in 20200512 for QAC
            enLastLampStatusTemp = stMainObject->stFlashControlStatus[u8Index].unStatus.stStatus.LightType;
			*/
			u16TickCountTemp = stMainObject->stTimer.u16FlashTimeTick[u8Index] % cstFlashAttribute[u8Index].u16CycleCount;
			u16LampOnCountTemp = (uint16)((uint32)cstFlashAttribute[u8Index].u16CycleCount * (uint32)cstFlashAttribute[u8Index].u8Duty / 100);
            u16LampOffCountTemp = cstFlashAttribute[u8Index].u16CycleCount - u16LampOnCountTemp;
            u16RisingEdgeSyncCountTemp = u16LampOffCountTemp + (uint16)((uint32)u16LampOnCountTemp * (uint32)cstFlashAttribute[u8Index].u8RisingEdgeSyncPercent / 100);
            u16FaillingEdgeSyncCountTemp = u16LampOffCountTemp + (uint16)((uint32)u16LampOnCountTemp * (uint32)cstFlashAttribute[u8Index].u8FaillingEdgeSyncPercent / 100);

/*********************************************************************************************************/
/* Calculate formula :
     |<-               LampOff              ->|<-               LampOn               ->|
   OffEdge                                  OnEdge                                  OffEdge(Loop)
     *----------------------------------------*----------------------------------------*
                                              |<-    RisingSync    ->|
                                                              |<-    FaillingSync    ->|
                                              0%                 50%                  100%
*/
/*********************************************************************************************************/
            if (u16TickCountTemp == 0)
            {
                enLampStatusTemp = TT_enLAMP_OFF_EDGE;
            }
            else if (u16TickCountTemp < u16LampOffCountTemp)
            {
                enLampStatusTemp = TT_enLAMP_OFF;
            }
            else if (u16TickCountTemp == u16LampOffCountTemp)
            {
                enLampStatusTemp = TT_enLAMP_ON_EDGE;
            }
            else
            {
                enLampStatusTemp = TT_enLAMP_ON;
            }

            /*Save current flash light status to main object*/
            stMainObject->stFlashControlStatus[u8Index].unStatus.stStatus.LightType = enLampStatusTemp;

			stMainObject->stFlashControlStatus[u8Index].unStatus.stStatus.RisingEdgeSync = \
				(u16TickCountTemp <= u16RisingEdgeSyncCountTemp) ? 1u:0u;

			stMainObject->stFlashControlStatus[u8Index].unStatus.stStatus.FaillingEdgeSync = \
				(u16TickCountTemp <= u16FaillingEdgeSyncCountTemp) ? 1u:0u;
		}
    }
    else
    {
        /*Do nothing because no flash status is define*/
    }
}
/**********************************************************************************************************
*Function   : TT_CORE_vFlashReferenceTickPlus                                                             *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleAttribute) *cstTelltaleAttribute											  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vFlashReferenceTickPlus(const TT_tstFlashAttribute *cstFlashAttribute, TT_tstMainObject *stMainObject)
{
	uint8 u8Index = 0;

	if (TT_enSTATUS_TOTAL_NUMBER > TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER)
	{
	    for (u8Index = 0; u8Index < ((uint8)TT_enSTATUS_TOTAL_NUMBER - (uint8)TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER); u8Index++)
	    {
			stMainObject->stTimer.u16FlashTimeTick[u8Index] += 1;

			stMainObject->stTimer.u16FlashTimeTick[u8Index] %= cstFlashAttribute[u8Index].u16CycleCount;
	   }
	}
	else
	{
	   /*Do nothing because no flash status is define or time is no running*/
	}
}
/**********************************************************************************************************
*Function   : TT_CORE_vTelltaleTableLogicProcess                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (void) *vptrTelltaleLogicOperation														  *
*             (TT_tstLogicProcessAttribute) *cstLogicProcessAttribute									  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vSingleLogicProcess(void *vptrTelltaleLogicOperation,const TT_tstLogicProcessAttribute *cstLogicProcessAttribute, TT_tstMainObject *stMainObject)
{
	uint8 u8Index = 0;

	while(TT_DO_NOTHING != cstLogicProcessAttribute[u8Index].vptrTelltaleLogicOperation)
	{
		if ((vptrTelltaleLogicOperation == cstLogicProcessAttribute[u8Index].vptrTelltaleLogicOperation)\
			&&(0 != ((uint32)TT_enINTERFACE & cstLogicProcessAttribute[u8Index].u32LogicProcessMode)))
        {
			(void)cstLogicProcessAttribute[u8Index].vptrTelltaleLogicOperation(stMainObject);
		}
		 else
	    {
	        /*Parameter is not match current process mode,so do not running this process */
	    }
		u8Index++;
	}
}
/**********************************************************************************************************
*Function   : TT_CORE_vTelltaleTableLogicProcess                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_enLogicProcessMode) enLogicProcessMode												  *
*             (TT_tstLogicProcessAttribute) *cstLogicProcessAttribute									  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vTelltaleTableLogicProcess(TT_enLogicProcessMode enLogicProcessMode,const TT_tstLogicProcessAttribute *cstLogicProcessAttribute, TT_tstMainObject *stMainObject)
{
    uint8 u8Index = 0;
    if ((TT_enTIME_TASK == enLogicProcessMode) || (TT_enROBIN_TASK == enLogicProcessMode))
    {
	    while(TT_DO_NOTHING != cstLogicProcessAttribute[u8Index].vptrTelltaleLogicOperation)
		{
			if((uint32)enLogicProcessMode == TT_enTIME_TASK)
			{
				if((TT_NOT_CONCERNED == cstLogicProcessAttribute[u8Index].u16TimeTaskModeLoopFactor)\
				 ||( cstLogicProcessAttribute[u8Index].u16TimeTaskModeLoopOffset == (stMainObject->stCount.u32TimeTaskLoopRateTickCount  % cstLogicProcessAttribute[u8Index].u16TimeTaskModeLoopFactor)))
				{
					(void)cstLogicProcessAttribute[u8Index].vptrTelltaleLogicOperation(stMainObject);
				}
				else
				{
					/*Skip running process this time*/
				}
			}
			else if ((uint32)enLogicProcessMode & cstLogicProcessAttribute[u8Index].u32LogicProcessMode)
			{
				(void)cstLogicProcessAttribute[u8Index].vptrTelltaleLogicOperation(stMainObject);
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
*Function   : TT_CORE_vSingleTelltaleLightControl                                                         *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleControlStatus) stTelltaleControlStatus										  *
*             (TT_tstTelltaleAttribute) *cstTelltaleAttribute											  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vSingleTelltaleLightControl(TT_tstTelltaleControlStatus *stTelltaleControlStatus, const TT_tstTelltaleAttribute *cstTelltaleAttribute, TT_tstMainObject *stMainObject)
{
	/*If Control process is running , then quit this time .Avoid run this function in interrupt when this function is already running*/
	if (boTTRunningFlag)
    {
        return;
    }
    else
    {
        boTTRunningFlag = TRUE;
    }

	/*Check logic process status valid*/
	TT__vCheckLogicProcessReturnValid(stTelltaleControlStatus,stMainObject);

	/*Check special condition such as prove out etc*/
    TT__vCheckSpecialCondition(stTelltaleControlStatus,cstTelltaleAttribute,stMainObject);

	/*Logic status changed*/
	if (stTelltaleControlStatus->unStatus.stStatus.LastLogicType \
	 != stTelltaleControlStatus->unStatus.stStatus.ResultLogicType)
	{
		/*If logic status changed ,then check and set KeepLightStatus*/
		TT__vCheckAndSetKeepLightStatus(stTelltaleControlStatus,cstTelltaleAttribute,stMainObject);

	    /*Clear current count when logic status changed*/
	    stTelltaleControlStatus->u8CurrentLightCount = 0;
	}
	else
	{
	    /*Do nothing but avoid QAC warning*/
	}

    /*Check KeepLightStatus clear state .If last flash type is light off , so clear flag*/
    TT__vCheckAndClearKeepLightStatus(stTelltaleControlStatus,cstTelltaleAttribute,stMainObject);

    /*According to the logic status change of lamp light status*/
    TT__vGetLightStatusFromLogicStatus(stTelltaleControlStatus,/*cstTelltaleAttribute,*/stMainObject);

    /*Lamp status changed*/
    if (stTelltaleControlStatus->unStatus.stStatus.LightType \
	 != stTelltaleControlStatus->unStatus.stStatus.LastLightType)
    {
        if (TT_enLAMP_OFF_EDGE == stTelltaleControlStatus->unStatus.stStatus.LightType)
        {
            TT__vLampLightOffEdgeProcess(/*stTelltaleControlStatus,*/cstTelltaleAttribute,stMainObject);
        }
        else if (TT_enLAMP_ON == stTelltaleControlStatus->unStatus.stStatus.LightType)
        {
        	TT__vLampLightOnProcess(stTelltaleControlStatus,cstTelltaleAttribute,stMainObject);
        }
        else if (TT_enLAMP_ON_EDGE == stTelltaleControlStatus->unStatus.stStatus.LightType)
        {
            TT__vLampLightOnEdgeProcess(stTelltaleControlStatus,cstTelltaleAttribute,stMainObject);
        }
        else /*TT_enLAMP_OFF*/
        {
            TT__vLampLightOffProcess(stTelltaleControlStatus,cstTelltaleAttribute,stMainObject);
        }

        /*Save current lamp status to last lamp status*/
        stTelltaleControlStatus->unStatus.stStatus.LastLightType = \
        stTelltaleControlStatus->unStatus.stStatus.LightType;

        /*Save last status type when keep light flag is clear*/
        if (0 == stTelltaleControlStatus->unStatus.stStatus.KeepLightStatus)
        {
            stTelltaleControlStatus->unStatus.stStatus.LastLogicType = \
			stTelltaleControlStatus->unStatus.stStatus.ResultLogicType;
        }
        else
        {
        	/*Do nothing but avoid QAC warning*/
        }
    }
    else
    {
        /*Do nothing but avoid QAC warning*/
    }
    boTTRunningFlag = FALSE;
}
/**********************************************************************************************************
*Function   : TT__vCheckLogicProcessReturnValid                                                           *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleControlStatus) stTelltaleControlStatus										  *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static void TT__vCheckLogicProcessReturnValid(TT_tstTelltaleControlStatus *stTelltaleControlStatus , TT_tstMainObject *stMainObject)
{
	/*Handling of process return value is error */
	if (TT_enSELF_CHECK == stTelltaleControlStatus->unStatus.stStatus.LogicType)
    {
        stTelltaleControlStatus->unStatus.stStatus.LogicType= TT_enTURN_ON;
        /*TT_enSELF_CHECK status can not set in logic process .
          If set in error process , then set error status named TT_LOGIC_PROCESS_RETURN_VALUE_ERROR*/
        TT_CORE_vSetSystemStatus(TT_LOGIC_PROCESS_RETURN_VALUE_ERROR, stMainObject);
    }
    else if (TT_enSTATUS_TOTAL_NUMBER <= stTelltaleControlStatus->unStatus.stStatus.LogicType)
    {
        stTelltaleControlStatus->unStatus.stStatus.LogicType = TT_enTURN_OFF;
        /*Current status can not define in config . Avoid array out of bound .
          If set to error value , then set error status named TT_LOGIC_PROCESS_RETURN_VALUE_ERROR*/
        TT_CORE_vSetSystemStatus(TT_LOGIC_PROCESS_RETURN_VALUE_ERROR, stMainObject);
    }
    else
    {
        /*Clear error status if system need*/
        /*TT_CORE_vClearSystemStatus(TT_LOGIC_PROCESS_RETURN_VALUE_ERROR,stMainObject);*/
    }
}
/**********************************************************************************************************
*Function   : TT__vCheckSpecialCondition                                                                  *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleControlStatus) *stTelltaleControlStatus                                      *
*             (TT_tstTelltaleAttribute) *cstTelltaleAttribute                                             *
*             (TT_tstMainObject) *cstMainObject                                                           *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static void TT__vCheckSpecialCondition(TT_tstTelltaleControlStatus *stTelltaleControlStatus,const TT_tstTelltaleAttribute *cstTelltaleAttribute,const TT_tstMainObject *cstMainObject)
{
	/*Check extern contol process*/
	if(stTelltaleControlStatus->unStatus.stStatus.ExternalControlStatus)
	{
		/*Let telltale external control interface set the telltale status*/
	}
	/*Check current configration mode process*/
	else if(0 == cstTelltaleAttribute->u8StaticConfiguration)
	{
        /*Current static switch is off,so turn off the telltale*/
        stTelltaleControlStatus->unStatus.stStatus.ResultLogicType = TT_enTURN_OFF;
	}
	else if(0 == stTelltaleControlStatus->unStatus.stStatus.DynamicConfigration)
	{
        /*Current dynamic switch is off,so turn off the telltale*/
        stTelltaleControlStatus->unStatus.stStatus.ResultLogicType = TT_enTURN_OFF;
	}
	/*Check current power mode process*/
    else if (0 == ((cstTelltaleAttribute->u32WorkPowerMode) & cstMainObject->unPowerModeStatus.u32PowerModeStatus))
    {
        /*Current power mode is not support , so turn off the telltale*/
        stTelltaleControlStatus->unStatus.stStatus.ResultLogicType = TT_enTURN_OFF;
    }
    #if 0
    /*Check self check status process*/
    else if (stTelltaleControlStatus->unStatus.stStatus.SelfCheckStatus)
    {
        /*Current self check status is enable , so set status to prove out .
		  Logic status can set to TT_enSELF_CHECK only in this process , */
        stTelltaleControlStatus->unStatus.stStatus.ResultLogicType = TT_enSELF_CHECK;
    }
    #endif
    /*Check ignition on response delay status process*/
    else if (stTelltaleControlStatus->unStatus.stStatus.IgnitionOnResponseDelayStatus)
    {
        if (0 != (cstTelltaleAttribute->u32ControlAttribute & (uint32)TT_enIGN_ON_RESPONSE_DELAY_KEEP_PREVIOUSLY))
        {
            stTelltaleControlStatus->unStatus.stStatus.ResultLogicType = stTelltaleControlStatus->unStatus.stStatus.LastLogicType;
        }
        else
        {
            stTelltaleControlStatus->unStatus.stStatus.ResultLogicType = TT_enTURN_OFF;
        }
    }
    /*Check exit abnormal delay status process*/
    else if (stTelltaleControlStatus->unStatus.stStatus.ExitAbnormalDelayStatus)
    {
        /*Always keep previous status*/
		stTelltaleControlStatus->unStatus.stStatus.ResultLogicType = stTelltaleControlStatus->unStatus.stStatus.LastLogicType;
    }
    else
    {
		/*Save logic status to result logic status*/
		stTelltaleControlStatus->unStatus.stStatus.ResultLogicType = stTelltaleControlStatus->unStatus.stStatus.LogicType;
    }
}

/**********************************************************************************************************
*Function   : TT__vCheckPowerModeCondition                                                                  *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleControlStatus) *stTelltaleControlStatus                                      *
*             (TT_tstTelltaleAttribute) *cstTelltaleAttribute                                             *
*             (TT_tstMainObject) *cstMainObject                                                           *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT__vCheckPowerModeCondition(TT_tstTelltaleControlStatus *stTelltaleControlStatus,const TT_tstTelltaleAttribute *cstTelltaleAttribute/*,TT_tstMainObject *cstMainObject*/)
{

	/*Check current power mode process*/
    //if (!((cstTelltaleAttribute->u32WorkPowerMode) & cstMainObject->unPowerModeStatus.u32PowerModeStatus))
    if (0 == ((cstTelltaleAttribute->u32WorkPowerMode) & (uint32)TT_enOFF))
    {
        /*Current power mode is not support , so turn off the telltale*/
        stTelltaleControlStatus->unStatus.stStatus.ResultLogicType = TT_enTURN_OFF;
    }

}
/**********************************************************************************************************
*Function   : TT__vCheckAndSetKeepLightStatus                                                             *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleControlStatus) *stTelltaleControlStatus                                      *
*             (TT_tstTelltaleAttribute) *cstTelltaleAttribute                                             *
*             (const TT_tstMainObject) *cstMainObject                                                     *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static void TT__vCheckAndSetKeepLightStatus(TT_tstTelltaleControlStatus *stTelltaleControlStatus,const TT_tstTelltaleAttribute *cstTelltaleAttribute,const TT_tstMainObject *cstMainObject)
{
	/*This condition happens from one flash status to anothers and the attribute is configured*/
	if ((0 != (cstTelltaleAttribute->u32ControlAttribute & (uint32)TT_enKEEP_FLASH_STATUS_UNTIL_CURRENT_CYCLE_END))
	  &&(stTelltaleControlStatus->unStatus.stStatus.LastLogicType >= TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER)
	  &&(stTelltaleControlStatus->unStatus.stStatus.ResultLogicType >= TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER)
	  &&(0 != (cstMainObject->stFlashControlStatus[(uint8)(stTelltaleControlStatus->unStatus.stStatus.LastLogicType) - (uint8)TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER].unStatus.stStatus.FaillingEdgeSync)))
    {
        /*Set keep light status*/
        stTelltaleControlStatus->unStatus.stStatus.KeepLightStatus = 1u;
    }
	/*This condition happens from one flash status to logic off or on status and the attribute is configured*/
    else if ((0 != (cstTelltaleAttribute->u32ControlAttribute & (uint32)TT_enOFF_AT_FAILLING_EDGE_TRIGGER))\
	&& (stTelltaleControlStatus->unStatus.stStatus.LastLogicType >= TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER)\
	&& ((stTelltaleControlStatus->unStatus.stStatus.ResultLogicType == TT_enTURN_OFF)\
	  ||(stTelltaleControlStatus->unStatus.stStatus.ResultLogicType == TT_enTURN_ON))\
	&& (0 != (cstMainObject->stFlashControlStatus[(uint8)(stTelltaleControlStatus->unStatus.stStatus.LastLogicType) - (uint8)TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER].unStatus.stStatus.FaillingEdgeSync)))
    {
        /*Set keep light status*/
        stTelltaleControlStatus->unStatus.stStatus.KeepLightStatus = 1u;
    }
    else
    {
    	/*Do nothing but avoid QAC warning*/
    }
}
/**********************************************************************************************************
*Function   : TT__vCheckAndClearKeepLightStatus                                                           *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleControlStatus) *stTelltaleControlStatus                                      *
*             (TT_tstTelltaleAttribute) *cstTelltaleAttribute                                             *
*             (TT_tstMainObject) *cstMainObject                                                           *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static void TT__vCheckAndClearKeepLightStatus(TT_tstTelltaleControlStatus *stTelltaleControlStatus,const TT_tstTelltaleAttribute *cstTelltaleAttribute,TT_tstMainObject *stMainObject)
{
	if(stTelltaleControlStatus->unStatus.stStatus.KeepLightStatus)
	{
		/*Special condition always clear keep flash status flag */
		if((1 == stTelltaleControlStatus->unStatus.stStatus.ExternalControlStatus)\
		||(0 == cstTelltaleAttribute->u8StaticConfiguration)\
		||(0 == stTelltaleControlStatus->unStatus.stStatus.DynamicConfigration)\
		||(0 == ((cstTelltaleAttribute->u32WorkPowerMode) & stMainObject->unPowerModeStatus.u32PowerModeStatus))\
		||(1 == stTelltaleControlStatus->unStatus.stStatus.SelfCheckStatus)\
		||(1 == stTelltaleControlStatus->unStatus.stStatus.IgnitionOnResponseDelayStatus)\
		||(1 == stTelltaleControlStatus->unStatus.stStatus.ExitAbnormalDelayStatus))
		{
			/*Clear keep flash status flag */
			stTelltaleControlStatus->unStatus.stStatus.KeepLightStatus = 0;
		}
		/*This condition happens from one flash status to anothers*/
		else if((stTelltaleControlStatus->unStatus.stStatus.LastLogicType >= TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER)\
			&&(stTelltaleControlStatus->unStatus.stStatus.ResultLogicType >= TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER)\
			&&(0 != (cstTelltaleAttribute->u32ControlAttribute & (uint32)TT_enKEEP_FLASH_STATUS_UNTIL_CURRENT_CYCLE_END))\
			&&((TT_enLAMP_ON_EDGE == stMainObject->stFlashControlStatus[(uint8)(stTelltaleControlStatus->unStatus.stStatus.LastLogicType) - (uint8)TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER].unStatus.stStatus.LightType)\
			||(TT_enLAMP_OFF_EDGE == stMainObject->stFlashControlStatus[(uint8)(stTelltaleControlStatus->unStatus.stStatus.ResultLogicType) - (uint8)TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER].unStatus.stStatus.LightType)))
		{
			/*When current flash cyele is full ended or the status of transiton is just beginning ,
			  then clear keep flash status flag */
        	stTelltaleControlStatus->unStatus.stStatus.KeepLightStatus = 0;
		}
		/*This condition happens from one flash status to logic off or on status*/
		else if((stTelltaleControlStatus->unStatus.stStatus.LastLogicType >= TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER)\
			&&((stTelltaleControlStatus->unStatus.stStatus.ResultLogicType == TT_enTURN_OFF)\
			 ||(stTelltaleControlStatus->unStatus.stStatus.ResultLogicType == TT_enTURN_ON))\
			&&(0 != (cstTelltaleAttribute->u32ControlAttribute & (uint32)TT_enOFF_AT_FAILLING_EDGE_TRIGGER))\
			&&(TT_enLAMP_ON_EDGE == stMainObject->stFlashControlStatus[(uint8)(stTelltaleControlStatus->unStatus.stStatus.LastLogicType) - (uint8)TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER].unStatus.stStatus.LightType))
		{
			/*When current flash cyele is full ended ,then clear keep flash status flag */
        	stTelltaleControlStatus->unStatus.stStatus.KeepLightStatus = 0;
		}
		else if((0 == (cstTelltaleAttribute->u32ControlAttribute & (uint32)TT_enOFF_AT_FAILLING_EDGE_TRIGGER))\
			  &&(0 == (cstTelltaleAttribute->u32ControlAttribute & (uint32)TT_enKEEP_FLASH_STATUS_UNTIL_CURRENT_CYCLE_END)))
		{
			stTelltaleControlStatus->unStatus.stStatus.KeepLightStatus = 0;
			/*Keep flash status can not set in enable status because any valid attribute is not configured.
			If set in error process , then set error status named TT_KEEP_LIGHT_STATUS_FLAG_ERROR*/
			TT_CORE_vSetSystemStatus(TT_KEEP_LIGHT_STATUS_FLAG_ERROR,stMainObject);
		}
		else
		{
			/*Keep the flag enable*/
		}
	}
	else
	{
		/*Do nothing because flag is clear*/
	}
}
/**********************************************************************************************************
*Function   : TT__vGetLightStatusFromLogicStatus                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleControlStatus) *stTelltaleControlStatus                                      *
*             (TT_tstTelltaleAttribute) *cstTelltaleAttribute                                             *
 *             (TT_tstMainObject) *cstMainObject                                                          *
 *                                                                                                        *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static void TT__vGetLightStatusFromLogicStatus(TT_tstTelltaleControlStatus *stTelltaleControlStatus,/*const TT_tstTelltaleAttribute *cstTelltaleAttribute,*/const TT_tstMainObject *cstMainObject)
{
	TT_CFG_enStatusType enTargetLogicType = TT_enTURN_OFF;
	/*Calculate target logic type*/
	if(stTelltaleControlStatus->unStatus.stStatus.ExternalControlStatus)
	{
		enTargetLogicType = stTelltaleControlStatus->unStatus.stStatus.ExternalLogicType;
	}
	else if((1 == (stTelltaleControlStatus->unStatus.stStatus.KeepLightStatus))\
	&&(stTelltaleControlStatus->unStatus.stStatus.LastLogicType >= TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER))
	{
		/*Condition of keep previous logic type*/
		enTargetLogicType = stTelltaleControlStatus->unStatus.stStatus.LastLogicType;
	}
	else
	{
		/*Normal condition*/
		enTargetLogicType = stTelltaleControlStatus->unStatus.stStatus.ResultLogicType;
	}

	if (enTargetLogicType == TT_enTURN_OFF)
    {
        if ((TT_enLAMP_OFF != stTelltaleControlStatus->unStatus.stStatus.LastLightType ) \
		&& (TT_enLAMP_OFF_EDGE != stTelltaleControlStatus->unStatus.stStatus.LastLightType ))
        {
            stTelltaleControlStatus->unStatus.stStatus.LightType  = TT_enLAMP_OFF_EDGE;
        }
        else
        {
            stTelltaleControlStatus->unStatus.stStatus.LightType  = TT_enLAMP_OFF;
        }
    }
    else if ((enTargetLogicType  == TT_enTURN_ON) || (enTargetLogicType == TT_enSELF_CHECK))
    {
        if ((TT_enLAMP_ON != stTelltaleControlStatus->unStatus.stStatus.LastLightType ) \
		&& (TT_enLAMP_ON_EDGE != stTelltaleControlStatus->unStatus.stStatus.LastLightType ))
        {
            stTelltaleControlStatus->unStatus.stStatus.LightType  = TT_enLAMP_ON_EDGE;
        }
        else
        {
            stTelltaleControlStatus->unStatus.stStatus.LightType  = TT_enLAMP_ON;
        }
    }
	/*Logic status is flash */
    else
    {
        stTelltaleControlStatus->unStatus.stStatus.LightType = \
        cstMainObject->stFlashControlStatus[(uint8)enTargetLogicType - (uint8)TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER].unStatus.stStatus.LightType;
    }
}
/**********************************************************************************************************
*Function   : TT__vLampLightOffProcess                                                                    *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleControlStatus) *stTelltaleControlStatus                                      *
*             (TT_tstTelltaleAttribute) *cstTelltaleAttribute                                             *
*             (TT_tstMainObject) *stMainObject                                                            *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static void TT__vLampLightOffProcess(TT_tstTelltaleControlStatus *stTelltaleControlStatus,const TT_tstTelltaleAttribute *cstTelltaleAttribute,TT_tstMainObject *stMainObject)
{
	/*Output control*/
    TT_CORE_vSetTelltaleLightStatus(/*FALSE ,*/ cstTelltaleAttribute, stMainObject);

    if (TT_enLAMP_OFF_EDGE != stTelltaleControlStatus->unStatus.stStatus.LastLightType)
    {
		/*if hook is not null ,then run hook*/
		TT__vLightOffHockProcess(cstTelltaleAttribute);
    }
    else
    {
        /*Do nothing but avoid QAC warning*/
    }
}
/**********************************************************************************************************
*Function   : TT__vLampLightOffEdgeProcess                                                                *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleControlStatus) *stTelltaleControlStatus                                      *
*             (TT_tstTelltaleAttribute) *cstTelltaleAttribute                                             *
*             (TT_tstMainObject) *stMainObject                                                            *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static void TT__vLampLightOffEdgeProcess(/*TT_tstTelltaleControlStatus *stTelltaleControlStatus,*/const TT_tstTelltaleAttribute *cstTelltaleAttribute,TT_tstMainObject *stMainObject)
{
	/*Output control*/
    TT_CORE_vSetTelltaleLightStatus(/*FALSE ,*/ cstTelltaleAttribute, stMainObject);

    /*if hook is not null ,then run hook*/
	TT__vLightOffHockProcess(cstTelltaleAttribute);
}
/**********************************************************************************************************
*Function   : TT__vLampLightOnProcess                                                                     *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleControlStatus) *stTelltaleControlStatus                                      *
*             (TT_tstTelltaleAttribute) *cstTelltaleAttribute                                             *
*             (TT_tstMainObject) *stMainObject                                                            *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static void TT__vLampLightOnProcess(TT_tstTelltaleControlStatus *stTelltaleControlStatus,const TT_tstTelltaleAttribute *cstTelltaleAttribute,TT_tstMainObject *stMainObject)
{
	if (stTelltaleControlStatus->u8CurrentLightCount < cstTelltaleAttribute->u8LightCountLimit)
    {
        if (0 != (cstTelltaleAttribute->u32ControlAttribute & (uint32)TT_enON_AT_RISING_EDGE_TRIGGER))
        {
            if (0 != (stMainObject->stFlashControlStatus[(uint8)(stTelltaleControlStatus->unStatus.stStatus.ResultLogicType) - (uint8)TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER].unStatus.stStatus.RisingEdgeSync))
            {
                /*Output control*/
                TT_CORE_vSetTelltaleLightStatus(/*TRUE,*/ cstTelltaleAttribute, stMainObject);

                /*Check condition: TT_enLAMP_ON_EDGE -> TT_enLAMP_ON*/
                if (TT_enLAMP_ON_EDGE != stTelltaleControlStatus->unStatus.stStatus.LastLightType)
                {
                    /*Light count increase*/
					TT__vLampLightCountIncreaseProcess(stTelltaleControlStatus,cstTelltaleAttribute);

                    /*if hook is not null ,then run hook*/
					TT__vLightOnHockProcess(cstTelltaleAttribute);
                }
                else
                {
                    /*Do not increase the u8CurrentLightCount value because the count is already plused this flash cycle*/
                }
            }
            else
            {
                /*Do nothing because attribute determines that only light on at the rising edge or sync flag is 1*/
            }
        }
        else
        {
            /*Output control*/
            TT_CORE_vSetTelltaleLightStatus(/*TRUE,*/ cstTelltaleAttribute, stMainObject);

            /*Check condition: TT_enLAMP_ON_EDGE -> TT_enLAMP_ON*/
            if (TT_enLAMP_ON_EDGE != stTelltaleControlStatus->unStatus.stStatus.LastLightType)
            {
                /*Light count increase*/
				TT__vLampLightCountIncreaseProcess(stTelltaleControlStatus,cstTelltaleAttribute);

                /*if hook is not null ,then run hook*/
				TT__vLightOnHockProcess(cstTelltaleAttribute);
            }
            else
            {
                /*Do not set the LightCountPlus flag because the count is already plused this flash cycle*/
            }
        }
    }
    else
    {
        /*Current light count is greater than count limit , so do not turn on the light*/
    }
}
/**********************************************************************************************************
*Function   : TT__vLampLightOnEdgeProcess                                                                 *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleControlStatus) *stTelltaleControlStatus                                      *
*             (TT_tstTelltaleAttribute) *cstTelltaleAttribute                                             *
*             (TT_tstMainObject) *stMainObject                                                            *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static void TT__vLampLightOnEdgeProcess(TT_tstTelltaleControlStatus *stTelltaleControlStatus,const TT_tstTelltaleAttribute *cstTelltaleAttribute,TT_tstMainObject *stMainObject)
{
	if (stTelltaleControlStatus->u8CurrentLightCount < cstTelltaleAttribute->u8LightCountLimit)
	{
		/*Output control*/
		TT_CORE_vSetTelltaleLightStatus(/*TRUE,*/ cstTelltaleAttribute, stMainObject);

		/*Light count increase*/
		TT__vLampLightCountIncreaseProcess(stTelltaleControlStatus,cstTelltaleAttribute);

		/*if hook is not null ,then run hook*/
		TT__vLightOnHockProcess(cstTelltaleAttribute);
	}
	else
	{
		/*Current light count is greater than count limit , so do not turn on the light*/
	}
}
/**********************************************************************************************************
*Function   : TT__vLampLightCountIncreaseProcess                                                          *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleControlStatus) *stTelltaleControlStatus                                      *
*             (TT_tstTelltaleAttribute) *cstTelltaleAttribute                                             *
*             (TT_tstMainObject) *stMainObject                                                            *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static void TT__vLampLightCountIncreaseProcess(TT_tstTelltaleControlStatus *stTelltaleControlStatus,const TT_tstTelltaleAttribute *cstTelltaleAttribute)
{
	/*Light count increase*/
	if ((TT_CONTINUOUS != cstTelltaleAttribute->u8LightCountLimit) &&
	(cstTelltaleAttribute->u8LightCountLimit >= stTelltaleControlStatus->u8CurrentLightCount) &&
	(TT_enSELF_CHECK != stTelltaleControlStatus->unStatus.stStatus.ResultLogicType))
	{
		stTelltaleControlStatus->u8CurrentLightCount++;
	}
	else
	{
		/*Do nothing but avoid QAC warning*/
	}
}
/**********************************************************************************************************
*Function   : TT__vLightOnHockProcess                                                                     *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleAttribute) *cstTelltaleAttribute                                             *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static void TT__vLightOnHockProcess(const TT_tstTelltaleAttribute *cstTelltaleAttribute)
{
	/*if hook is not null ,then run hook*/
	if (TT_DO_NOTHING != cstTelltaleAttribute->vptrLampOnOperation)
	{
		/*Run lamp off hook function*/
		cstTelltaleAttribute->vptrLampOnOperation();
	}
	else
	{
	    /*Do nothing but avoid QAC warning*/
	}
}
/**********************************************************************************************************
*Function   : TT__vLightOffHockProcess                                                                    *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstTelltaleAttribute) *cstTelltaleAttribute                                             *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static void TT__vLightOffHockProcess(const TT_tstTelltaleAttribute *cstTelltaleAttribute)
{
	/*if hook is not null ,then run hook*/
	if (TT_DO_NOTHING != cstTelltaleAttribute->vptrLampOffOperation)
	{
		/*Run lamp off hook function*/
		cstTelltaleAttribute->vptrLampOffOperation();
	}
	else
	{
		/*Do nothing but avoid QAC warning*/
	}
}
/**********************************************************************************************************
*Function   : TT_CORE_vSetTelltaleLightStatus                                                             *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (BOOL) boSwitchStatus                                                                       *
*             (TT_tstTelltaleAttribute) cstTelltaleAttribute                                              *
*             (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_CORE_vSetTelltaleLightStatus(/*boolean boSwitchStatus,*/const TT_tstTelltaleAttribute *cstTelltaleAttribute, TT_tstMainObject *stMainObject)
{
    if (TT_enNULL_OUTPUT_MODE == cstTelltaleAttribute->u32OutputMode)
    {
        /*Do nothing*/
    }
#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_USE_GPIO) != FALSE)
    /*GPIO control*/
    else if (0 != ((uint32)TT_enGPIO_POSITIVE_OUTPUT & cstTelltaleAttribute->u32OutputMode))
    {
    	/* modify by fchao in 20200512
    	boSwitchStatus ? TT_CFG_GPIO_CONTROL_LEVEL_UP(cstTelltaleAttribute->u32OutputParameter):TT_CFG_GPIO_CONTROL_LEVEL_DOWN(cstTelltaleAttribute->u32OutputParameter);
    	*/
    }
    else if (0 != ((uint32)TT_enGPIO_NEGATIVE_OUTPUT & cstTelltaleAttribute->u32OutputMode))
    {
    	/* modify by fchao in 20200512
        boSwitchStatus ? TT_CFG_GPIO_CONTROL_LEVEL_DOWN(cstTelltaleAttribute->u32OutputParameter):TT_CFG_GPIO_CONTROL_LEVEL_UP(cstTelltaleAttribute->u32OutputParameter);
        */
    }
#endif //((TT_CFG_OUTPUT_MODE&TT_CFG_OUTPUT_USE_GPIO) != FALSE)
#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_USE_STM) != FALSE)
    /*STM control*/
    else if (TT_enSTM_POSITIVE_OUTPUT & cstTelltaleAttribute->u32OutputMode)
	{
		/* modify by fchao in 20200512
        boSwitchStatus ? TT_CFG_STM_CONTROL_LEVEL_UP(cstTelltaleAttribute->u32OutputParameter):TT_CFG_STM_CONTROL_LEVEL_DOWN(cstTelltaleAttribute->u32OutputParameter);
        */
    }
    else if (TT_enSTM_NEGATIVE_OUTPUT & cstTelltaleAttribute->u32OutputMode)
	{
		/* modify by fchao in 20200512
        boSwitchStatus ? TT_CFG_STM_CONTROL_LEVEL_DOWN(cstTelltaleAttribute->u32OutputParameter):TT_CFG_STM_CONTROL_LEVEL_UP(cstTelltaleAttribute->u32OutputParameter);
        */
    }
#endif //((TT_CFG_OUTPUT_MODE&TT_CFG_OUTPUT_USE_STM) != FALSE)
	else
    {
        /*Do nothing but avoid QAC warning*/
    }

#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_CAN) != FALSE)
    if (TT_enCAN_OUTPUT & cstTelltaleAttribute->u32OutputMode)
    {
        /*Set update flag*/
        stMainObject->unFunctionFlag.stFuncFlag.CANUpdateFlag = 1u;
    }
	else
	{
		/*Do nothing because output mode is invalid*/
	}
#endif //((TT_CFG_OUTPUT_MODE&TT_CFG_OUTPUT_ON_CAN) != FALSE)
#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_SBUS) != FALSE)
    if (0 != ((uint32)TT_enSBUS_OUTPUT & cstTelltaleAttribute->u32OutputMode))
    {
        /*Set update flag*/
        stMainObject->unFunctionFlag.stFuncFlag.SBUSUpdateFlag = 1u;
    }
	else
	{
		 /*Do nothing but avoid QAC warning*/
	}
#endif //((TT_CFG_OUTPUT_MODE&TT_CFG_OUTPUT_ON_SBUS) != FALSE)
}
/**********************************************************************************************************
*Function   : TT__vTimeTaskLoopRollingCount                                                               *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_tstMainObject) *stMainObject															  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT__vTimeTaskLoopRollingCount(TT_tstMainObject *stMainObject)
{
	if (stMainObject->stCount.u32TimeTaskLoopRateTickCount < 0xFFFFFFFFuL)
	{
		stMainObject->stCount.u32TimeTaskLoopRateTickCount ++ ;
	}
	else
	{
		stMainObject->stCount.u32TimeTaskLoopRateTickCount = 0;
	}
}

#define SWC_TT_STOP_SEC_CODE
#include "SWC_TT_MemMap.h"

/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
