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
**  Name:               SWC_CHIME_QUEUE.c
**
**  Description:        Chime sound queue control
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
#include "Compiler.h"
#include "Platform_Types.h"
#include "string.h"
#include "Rte_Common_Normal.h"

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Chime_Test.h"
#include "SWC_Chime_App.h"

/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/
typedef struct
{
	uint16 AllTime;
	uint16 MinTime;
}ChimeTestSound_t;
/**********************************************************************************************************
* Parament                                                                                                *
**********************************************************************************************************/


/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_CHIME_START_SEC_CONST_UNSPECIFIED
#include "SWC_Chime_MemMap.h"
static const ChimeTestSound_t ChimeTestSound[e_SoundType_NumberOfChimes] =
{
	{(0),			0},
	{(20),		100},
	{(20),		100},
	{(20),		100},
	{(50),		2000},
	{(255),			100},
	{(255),			100},
	{(255),			100},
	{(255),			250},
	{(255),			250},
	{(255),			333},
	{(255),			333},
	{(255),			333},
	{(255),			500},
	{(255),			500},
	{(255),			666},
	{(255),			666},
	{(255),			666},
	{(3),		1000},
	{(3),		1000},
	{(3),		1000},
	{(3),		1000},
	{(255),			2000},
	{(30),		2000},
	{(255),			2000},
	{(255),			2000},
	{(1),			200},
	{(1),			200},
	{(10),		1000},
	{(255),			1000},
	{(10),		1000},
	{(1),			100},
	{(1),			100},
	{(1),			100},
	{(1),		2000},
	{(1),		2000},
	{(1),		2000},
	{(6),		2000},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
	{(0),			0},
};

#define SWC_CHIME_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_Chime_MemMap.h"


#define SWC_CHIME_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Chime_MemMap.h"

//static e_ChimeIPCCommand_t ChimeTestCommand;
static uint32 ChimeTestTickCounter = 0;
static uint8 ChimeTestTickSts = 0;
//static uint8 ChimeTestLastSound = 0;
static uint8 ChimeTestCurSound = 0;
static uint8 ChimeTestNextSound = 0;
static uint8 ChimeTestCurLoop = 0;
static uint8 ChimeTestNextLoop = 0;
static uint8 ChimeTestFeedBuffer[2] = {0,0};
#define SWC_CHIME_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Chime_MemMap.h"

#define Test_Fun 0U
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/


/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_CHIME_START_SEC_CODE
#include "SWC_Chime_MemMap.h"
void ChimeTestMain(void)
{
	uint32 passtime;
	if(FALSE != ChimeTestTickSts)
	{	
		passtime = Chime_RteTestOstmCheck();
		if(passtime >= ChimeTestSound[ChimeTestCurSound].MinTime)
		{
			if(ChimeTestCurLoop > 0)
			{
				if(ChimeTestCurLoop < 255)
				{
					ChimeTestCurLoop --;
				}
				Chime_RteTestOstmStart();
			}
			else
			{
				if(0 != ChimeTestNextSound)
				{
					ChimeTestCurLoop = ChimeTestNextLoop;
					ChimeTestCurSound = ChimeTestNextSound;
					Chime_RteTestOstmStart();
					ChimeTestNextSound = 0;
				}
				else
				{
					ChimeTestFeedBuffer[0] = 0;
					//ChimeTestFeedBuffer[1] = ChimeTestSound[ChimeTestCurSound].AllTime;
					ChimeTestCurSound = 0;
					Chime_RteTestOstmStop();
					//Chime_Api_Callback_Set(ChimeTestFeedBuffer);
				}
			}
		}
		else
		{
			//wait timer over
		}
	}
}


#if Test_Fun
void ChimeTestCallback(e_ChimeIPCCommand_t in)
{
	switch(in.Operation_u8)
	{
		case 0:
			break; 
		case 1:
			//start
			ChimeTestStartSound(in);
			break;
		case 2:
			//immediately start
			ChimeTestStartImmediately(in);
			break;
		case 3:
			//stop
			ChimeTestStopSound(in);
			break;
		case 4:
			//immediately stop
			ChimeTestStopImmediatel(in);
			break;
		case 5:
			//read
			ChimeTestRead(in);
			break;
		case 6:
			//sound volume
			ChimeTestRead(in);
			break;
		default:
			ChimeTestRead(in);//for modify  MISRA C-2012 Rules you should delete when you use this fuction
			break;
	}
}
#endif

#if Test_Fun
void ChimeTestStartSound(e_ChimeIPCCommand_t in)
{
	if(ChimeTestCurSound == 0)
	{
		ChimeTestLastSound = ChimeTestCurSound;
		if(ChimeTestCurLoop != 0xff)
		{
			ChimeTestFeedBuffer[1] =  (uint8)(ChimeTestSound[ChimeTestCurSound].AllTime - ChimeTestCurLoop);
		}
		else
		{
			ChimeTestFeedBuffer[1] = 0;
		}
		ChimeTestCurSound = in.SoundId_u8;
		if(in.RepeatTime_u32 != 0)
		{
			ChimeTestCurLoop = (uint8)(in.RepeatTime_u32 / ChimeTestSound[in.SoundId_u8].MinTime);
		}
		else
		{
			ChimeTestCurLoop = 255;
		}
		Chime_RteTestOstmStart();
		ChimeTestNextSound = 0;
		ChimeTestFeedBuffer[0] = in.SoundId_u8;

		//Chime_Api_Callback_Set(ChimeTestFeedBuffer);
	}
	else if(in.SoundId_u8 == ChimeTestCurSound)
	{
		if(ChimeTestCurLoop != 0xff)
		{
			ChimeTestFeedBuffer[1] = (uint8)(ChimeTestSound[ChimeTestCurSound].AllTime - ChimeTestCurLoop);
		}
		else
		{
			ChimeTestFeedBuffer[1] = 0;
		}
		if(in.RepeatTime_u32 != 0)
		{
			ChimeTestCurLoop = (uint8)(in.RepeatTime_u32 / ChimeTestSound[in.SoundId_u8].MinTime);
		}
		else
		{
			ChimeTestCurLoop = 255;
		}
		ChimeTestNextSound = 0;
		ChimeTestFeedBuffer[0] = in.SoundId_u8;
		//Chime_Api_Callback_Set(ChimeTestFeedBuffer);
	}
	else
	{
		ChimeTestCurLoop = 0;
		ChimeTestLastSound = 0;
		ChimeTestNextSound = in.SoundId_u8;
	}
}

void ChimeTestStartImmediately(e_ChimeIPCCommand_t in)
{
	if(ChimeTestCurLoop != 0xff)
	{
		ChimeTestFeedBuffer[1] = (uint8)(ChimeTestSound[ChimeTestCurSound].AllTime - ChimeTestCurLoop);
	}
	else
	{
		ChimeTestFeedBuffer[1] = 0;
	}
	ChimeTestLastSound = ChimeTestCurSound;
	ChimeTestCurSound = in.SoundId_u8;
	if(in.RepeatTime_u32 != 0)
		{
			ChimeTestCurLoop = (uint8)(in.RepeatTime_u32 / ChimeTestSound[in.SoundId_u8].MinTime);
		}
		else
		{
			ChimeTestCurLoop = 255;
		}
	Chime_RteTestOstmStart();
	ChimeTestNextSound = 0;
	ChimeTestFeedBuffer[0] = in.SoundId_u8;
	
	//Chime_Api_Callback_Set(ChimeTestFeedBuffer);
}

void ChimeTestStopSound(e_ChimeIPCCommand_t in)
{

	ChimeTestFeedBuffer[1] = (uint8)(ChimeTestSound[ChimeTestCurSound].AllTime - ChimeTestCurLoop);
	ChimeTestCurLoop = 0;
}
void ChimeTestStopImmediatel(e_ChimeIPCCommand_t in)
{
	if(ChimeTestCurLoop != 0xff)
	{
		ChimeTestFeedBuffer[1] = (uint8)(ChimeTestSound[ChimeTestCurSound].AllTime - ChimeTestCurLoop);
	}
	else
	{
		ChimeTestFeedBuffer[1] = 0;
	}
	ChimeTestLastSound = ChimeTestCurSound;
	ChimeTestFeedBuffer[0] = 0;
	ChimeTestNextSound = 0;
	ChimeTestCurSound = 0;
	Chime_RteTestOstmStop();
	//Chime_Api_Callback_Set(ChimeTestFeedBuffer);
}

void ChimeTestRead(e_ChimeIPCCommand_t in)
{
	
}
void ChimeTestSetVolume(e_ChimeIPCCommand_t in)
{
	
}
#endif
void Chime_RteTestOstmStart(void)
{
	uint8 status;
	status = Rte_Call_Os_Service_GetCounterValue(&ChimeTestTickCounter);
	if(RTE_E_Os_Service_E_OK == status)
	{
		ChimeTestTickSts = 1U;
	}
}

uint32 Chime_RteTestOstmCheck(void)
{
	uint8 sts_u8;
	uint32 pasTime_u32;
	uint32 cureentTime;
	cureentTime = ChimeTestTickCounter;
	if(FALSE == ChimeTestTickSts)
	{
		pasTime_u32 = 0xffffffff;
	}
	else
	{
		sts_u8 = Rte_Call_Os_Service_GetElapsedValue(&cureentTime,&pasTime_u32);
		if(RTE_E_Os_Service_E_OK != sts_u8)
		{
			pasTime_u32 = 0xffffffff;
		}
	}
	return pasTime_u32;
}

void Chime_RteTestOstmStop(void)
{
	ChimeTestTickSts = 0U;
}

#define SWC_CHIME_STOP_SEC_CODE
#include "SWC_Chime_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/
/**********************************************************************************************************
**
**  Revision:      1.0  
**  
**  Author  :      Cao wenping
**
**  Date    :      2020/07/10     Original Version
**
**********************************************************************************************************/

/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/

