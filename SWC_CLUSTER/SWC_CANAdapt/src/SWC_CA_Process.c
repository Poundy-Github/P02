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
*File Name   : SWC_CA_Process.c                                                                           *
*                                                                                                         *
*Description : CA module Process C file.                                      		                      *
*                                                                                                         *
*Author      : Chen Tuhe                                                                                  *
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

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/


#include "SWC_CA_Config.h"
#include "SWC_CA_Adapt.h"
#include "string.h"

#define SWC_CA_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_CA_MemMap.h"

static CA_CFG_tst_MAINOBJECT CA_stMainObject = {0};
static SWC_CA_CanSignalDataAttribute ctstSWC_CA_CanSignalDataAttribute[(uint8)enCASignalInd_MAXNUM] = {{CA_Invalid, 0}};
#define SWC_CA_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_CA_MemMap.h"


#define SWC_CA_START_SEC_CONST_UNSPECIFIED
#include "SWC_CA_MemMap.h"

static const uint8 u8CACfgSignalLengthIsU8CountsTable[(uint8)enCASignalInd_MAXNUM] = CA_CFG_SignalLengthIsU8Counts_Table;

#define SWC_CA_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_CA_MemMap.h"

#define SWC_CA_START_SEC_GLOBALB_VAR_UNSPECIFIED
#include "SWC_CA_MemMap.h"

static SWC_CA_CanSignalBasisAttribute ctstSWC_CA_CanSignalBasisAttribute[(uint8)enCASignalInd_MAXNUM] = CA_CFG_SIgnalBasisAttributeTable;

#define SWC_CA_STOP_SEC_GLOBALB_VAR_UNSPECIFIED
#include "SWC_CA_MemMap.h"


#define SWC_CA_START_SEC_CODE
#include "SWC_CA_MemMap.h"

static void CA_API_PrintDataArrayLog(const uint8 * const Data ,const uint8 Length)
{
#define IPC_LINE_WORDS_NUMBER  16

	char LogBuffer[IPC_LINE_WORDS_NUMBER * 3 + 1] = {0};
	char NumberBuffer[4] = {0};
	uint8 Index , LogIndex = 0;

	(void)memset(&LogBuffer[0], 0, sizeof(LogBuffer));

	if (Length > 0)
	{
		for(Index = 0u; Index < Length; Index ++)
	    {
	    	(void)memset(&NumberBuffer[0], 0, sizeof(NumberBuffer));
			(void)sprintf(NumberBuffer, "%02X ", Data[Index]);
			(void)strcat(LogBuffer, NumberBuffer);
			LogIndex += 1;

			if ((LogIndex >= IPC_LINE_WORDS_NUMBER) || (Index == (Length -1)))
			{
				(void)SWC_CA_PRINT_SIGNAL_STATE("[CA] %s", LogBuffer);

				(void)memset(&LogBuffer[0], 0, sizeof(LogBuffer));
				LogIndex = 0;
			}
	    }
	}
}

static void vCA_Process_SignalStatusInit(void)
{
	uint8 u8TempSignalID = 0u;
	uint8 u8CAlogAry[30] = {0}; // The maximum number of signals is 30*8. If the number exceeds 30*8 signals, you need to modify the array length
	uint8 u8AryCount = 0u;
	uint8 u8AryBit = 0u;

	for(u8TempSignalID = 0; u8TempSignalID < enCASignalInd_MAXNUM; u8TempSignalID++)
	{
		CA_stMainObject.stCanMsgDataAttribute[u8TempSignalID].enCASignalStatus = enCA_Adapt_Get_SignalStatus(u8TempSignalID);

		u8AryCount = u8TempSignalID / 8;
		u8AryBit = u8TempSignalID % 8;
		u8CAlogAry[u8AryCount] |= (CA_stMainObject.stCanMsgDataAttribute[u8TempSignalID].enCASignalStatus << u8AryBit);
	}

	u8AryCount += 1;
	CA_API_PrintDataArrayLog(u8CAlogAry, u8AryCount);

	return ;
}

static void vCA_Process_SignalHandleInit(void)
{
	uint8 u8TempSignalID = 0u;

	for(u8TempSignalID = 0; u8TempSignalID < enCASignalInd_MAXNUM; u8TempSignalID++)
	{
		CA_stMainObject.stCanMsgDataAttribute[u8TempSignalID].u32CAMsgSignalValue = 0;
	}

	return ;
}


static void vCA_Process_MsgTimeoutInit(void)
{
	uint8 u8TempMsgID = 0u;

	for(u8TempMsgID = 0; u8TempMsgID < enCAMsgInd_MAXNUM; u8TempMsgID++)
	{
		CA_stMainObject.u8CAMsgTimeoutStatus[u8TempMsgID] = 0;
	}

	return ;
}

static void vCA_Process_CanMsgAttributeInit(void)
{
    CA_CFG_tst_MAINOBJECT* Object = &CA_stMainObject;

    Object->stCanMsgDataAttribute = (SWC_CA_CanSignalDataAttribute* )ctstSWC_CA_CanSignalDataAttribute;
    Object->stCanSignalBasisAttribute = (SWC_CA_CanSignalBasisAttribute* )ctstSWC_CA_CanSignalBasisAttribute;

    return ;
}


void vCA_Process_Init(void)
{
	vCA_Adapt_VconfigInit ();
	
	vCA_Adapt_ProIndexCfg();

	vCA_Process_CanMsgAttributeInit();

	vCA_Process_SignalStatusInit();

	vCA_Process_SignalHandleInit();

	vCA_Process_MsgTimeoutInit();


    return ;
}

static void vCA_Process_CACanSignalValueHandle(void)
{
	uint8 u8TempSignalID = 0u;
	uint8 u8TempRet = RTE_E_INVALID;
	uint32 u32TempRecValue = 0u;
	/* Message status flag: This flag is used to prevent the item from being valid
		but not contained in the corresponding item DBC, resulting in an abnormal state */
	uint8 u8CAMsgTimeoutStatusflag[enCAMsgInd_MAXNUM] = {0u};

	for(u8TempSignalID = 0; u8TempSignalID < enCASignalInd_MAXNUM; u8TempSignalID++)
	{

		if(CA_Valid == CA_stMainObject.stCanMsgDataAttribute[u8TempSignalID].enCASignalStatus)
		{
		    if(CA_stMainObject.u16CASignalTick[u8TempSignalID] <= (uint16)CA_stMainObject.stCanSignalBasisAttribute[u8TempSignalID].u8Priority)
		    {
			    u8TempRet = u8CA_Adapt_GetCANSignalValue(&u32TempRecValue, u8TempSignalID, u8CACfgSignalLengthIsU8CountsTable[u8TempSignalID]);

			    if(RTE_E_OK == u8TempRet)
    			{
					/* When a signal in this message can be received normally, the message status flag is set to 1 */
					u8CAMsgTimeoutStatusflag[CA_stMainObject.stCanSignalBasisAttribute[u8TempSignalID].u8MsgIndex] = 1u;

    				CA_stMainObject.u8CAMsgTimeoutStatus[CA_stMainObject.stCanSignalBasisAttribute[u8TempSignalID].u8MsgIndex] = 0u;

					if(u32TempRecValue != CA_stMainObject.stCanMsgDataAttribute[u8TempSignalID].u32CAMsgSignalValue)
					{
						SWC_CA_PRINT_SIGNAL_VALUE("[CA][SigInd:%d VAL:%d]", u8TempSignalID, u32TempRecValue);

						CA_stMainObject.stCanMsgDataAttribute[u8TempSignalID].u32CAMsgSignalValue = u32TempRecValue;
					}
    			}
			    else if(u8CAMsgTimeoutStatusflag[CA_stMainObject.stCanSignalBasisAttribute[u8TempSignalID].u8MsgIndex] != 1u)
    			{
					/* When one of the signals in message is properly received, the branch does not enter */
    				CA_stMainObject.u8CAMsgTimeoutStatus[CA_stMainObject.stCanSignalBasisAttribute[u8TempSignalID].u8MsgIndex] = 1u;
    			}
				else
				{
					;
				}

				if(CA_stMainObject.u8CAMsgTimeoutStatus[CA_stMainObject.stCanSignalBasisAttribute[u8TempSignalID].u8MsgIndex] \
			    != CA_stMainObject.u8CAMsgTimeoutStatusBK[CA_stMainObject.stCanSignalBasisAttribute[u8TempSignalID].u8MsgIndex])
				{
					CA_stMainObject.u8CAMsgTimeoutStatusBK[CA_stMainObject.stCanSignalBasisAttribute[u8TempSignalID].u8MsgIndex] = \
					CA_stMainObject.u8CAMsgTimeoutStatus[CA_stMainObject.stCanSignalBasisAttribute[u8TempSignalID].u8MsgIndex];

					(void)SWC_CA_PRINT_MSG_STATE("[CA][MSGInd:%d STS:%d]", CA_stMainObject.stCanSignalBasisAttribute[u8TempSignalID].u8MsgIndex, CA_stMainObject.u8CAMsgTimeoutStatus[CA_stMainObject.stCanSignalBasisAttribute[u8TempSignalID].u8MsgIndex]);
				}

    			CA_stMainObject.u16CASignalTick[u8TempSignalID] = \
    			    (CA_stMainObject.stCanSignalBasisAttribute[u8TempSignalID].u16Cycle + (uint16)CA_stMainObject.stCanSignalBasisAttribute[u8TempSignalID].u8Priority);
			}
			else
			{
                CA_stMainObject.u16CASignalTick[u8TempSignalID] -= 1u;
			}
		}
		else
		{
			// do nothing
		}
	}

	return ;
}

void vCA_Process_msTassk(void)
{
	vCA_Process_CACanSignalValueHandle();

	return ;
}

uint8 u8CA_Process_GetSignalStatus(enCACFGSIGNALINDEX enSignalID)
{
	return (uint8)(CA_stMainObject.stCanMsgDataAttribute[enSignalID].enCASignalStatus);
}

uint32 u32CA_Process_GetSignalValue(enCACFGSIGNALINDEX enSignalID)
{
	return (CA_stMainObject.stCanMsgDataAttribute[enSignalID].u32CAMsgSignalValue);
}

uint8 u32CA_Process_GetMsgTimeoutStatus(enCACFGMSGINDEX enMsgID)
{
	return (CA_stMainObject.u8CAMsgTimeoutStatus[enMsgID]);
}



#define SWC_CA_STOP_SEC_CODE
#include "SWC_CA_MemMap.h"

/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/


