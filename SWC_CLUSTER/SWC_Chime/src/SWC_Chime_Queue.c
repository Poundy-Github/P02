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

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Chime_Queue.h"
#include "SWC_Chime_Interface.h"
#include "SWC_Chime_App.h"
#include "SWC_Chime_Cfg.h"
#include "SWC_Chime_Process.h"


/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/
/**********************************************************************************************************
* Parament                                                                                                *
**********************************************************************************************************/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_CHIME_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Chime_MemMap.h"

static uint16 ChimeCoreSoundTbl[e_ChimeQueue_ALl][e_SoundType_NumberOfChimes];

#define SWC_CHIME_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Chime_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_CHIME_START_SEC_CODE
#include "SWC_Chime_MemMap.h" 

/**********************************************************************************************************
*Function   : Chime_QueueInit                                                                             *
*                                                                                                         *
*Description: Init sound palying and release tbl,Call by cold and warm init                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_QueueInit(void)
{
	(void)memset((void*)&ChimeCoreSoundTbl[0],0, sizeof(ChimeCoreSoundTbl));
}

/**********************************************************************************************************
*Function   : Chime_CoreRequestSound                                                                      *
*                                                                                                         *
*Description: App process function requirement sound api                                                  *
*                                                                                                         *
*Parameter  : sound_e:  request enum, request once will playing once                                      *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_CoreRequestSound(uint8 sound_u8,uint16 soundBit)
{
	/*Clear sound playing tbl*/
	ChimeCoreSoundTbl[e_ChimeQueue_Request][sound_u8] |= soundBit;
	ChimeCoreSoundTbl[e_ChimeQueue_Playing][sound_u8] &= ~soundBit;
	ChimeCoreSoundTbl[e_ChimeQueue_Pending][sound_u8] &= ~soundBit;
	Chime_RteAdaptTimerClr(Chime_OStmGetTimer(sound_u8));
}

/**********************************************************************************************************
*Function   : Chime_CoreCancelSound                                                                       *
*                                                                                                         *
*Description: App process function cancel for playing sound                                               *
*                                                                                                         *
*Parameter  : sound_e:  request enum                                                                      *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_CoreCancelSound(uint8 sound_u8,uint16 soundBit)
{
	ChimeCoreSoundTbl[e_ChimeQueue_Request][sound_u8] &= ~soundBit;
	ChimeCoreSoundTbl[e_ChimeQueue_Playing][sound_u8] &= ~soundBit;
	ChimeCoreSoundTbl[e_ChimeQueue_Pending][sound_u8] &= ~soundBit;
	Chime_RteAdaptTimerClr(Chime_OStmGetTimer(sound_u8));
}

/**********************************************************************************************************
*Function   : Chime_CorePendingSound                                                                      *
*                                                                                                         *
*Description: App function requirement for pending    sound                                               *
*                                                                                                         *
*Parameter  : sound_e:  request enum                                                                      *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_CorePendingSound(uint8 sound_u8,uint16 soundBit)
{
	/*Set pending tbl*/
	ChimeCoreSoundTbl[e_ChimeQueue_Pending][sound_u8] |= soundBit;
}

/**********************************************************************************************************
*Function   : Chime_CorePendingSound                                                                      *
*                                                                                                         *
*Description: App function requirement for pending    sound                                               *
*                                                                                                         *
*Parameter  : sound_e:  request enum                                                                      *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_CoreRelsPalyingSound(uint8 sound_u8,uint16 soundBit)
{
	/*Set pending tbl*/
	ChimeCoreSoundTbl[e_ChimeQueue_Playing][sound_u8] |= soundBit;
}

/**********************************************************************************************************
*Function   : Chime_CorePendingSound                                                                      *
*                                                                                                         *
*Description: App function requirement for pending    sound                                               *
*                                                                                                         *
*Parameter  : sound_e:  request enum                                                                      *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_CoreClrPalyingSound(uint8 sound_u8,uint16 soundBit)
{
	/*Set pending tbl*/
	ChimeCoreSoundTbl[e_ChimeQueue_Playing][sound_u8] &= ~soundBit;
}

/**********************************************************************************************************
*Function   : Chime_CoreRlsPendingSound                                                                   *
*                                                                                                         *
*Description: App function requirement for re playing sound                                               *
*                                                                                                         *
*Parameter  : sound_e:  request enum                                                                      *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_CoreRlsRequestSound(uint8 sound_u8,uint16 soundBit)
{
	ChimeCoreSoundTbl[e_ChimeQueue_Request][sound_u8] &= ~soundBit;
}

/**********************************************************************************************************
*Function   : Chime_CoreReleaseSound                                                                      *
*                                                                                                         *
*Description: App  function release sound                                                                 *
*                                                                                                         *
*Parameter  : sound_e:  request enum                                                                      *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_CoreReleaseSound(uint8 sound_u8)
{
	/*Set release tbl*/
	ChimeCoreSoundTbl[e_ChimeQueue_Request][sound_u8] &= ~ChimeCoreSoundTbl[e_ChimeQueue_Playing][sound_u8];
	ChimeCoreSoundTbl[e_ChimeQueue_Request][sound_u8] &= ~ChimeCoreSoundTbl[e_ChimeQueue_Pending][sound_u8];
	ChimeCoreSoundTbl[e_ChimeQueue_Playing][sound_u8] = 0;
	ChimeCoreSoundTbl[e_ChimeQueue_Pending][sound_u8] = 0;
	/*Clear timer status*/
	//Chime_OStmControl(sound_e,e_OstmStatus_Clear);

	if(sound_u8 == e_SoundType_India80Speed1Hz)
	{
		SWC_ChimeOverspeedIndia80Timer(1U);
	}
#if 0
	/*cancel by system SRS_1.8_20210228*/

	else if(sound_u8 == e_SoundType_CruiseActOnce)
	{
		SWC_ChimeACC_TJA_ICA_ActiveTimer(TRUE);
	}
	else if(sound_u8 == e_SoundType_CruiseDownOnce)
	{
		SWC_ChimeACC_TJA_ICA_DownTimer(TRUE);
	}
	else if(sound_u8 == e_SoundType_CruiseStartOnce)
	{
		SWC_ChimeACC_TJA_ICA_StartTimer(TRUE);
	}
#endif
	else
	{
	}
}

/**********************************************************************************************************
*Function   : Chime_CoreReleaseSound                                                                      *
*                                                                                                         *
*Description: App  function release sound                                                                 *
*                                                                                                         *
*Parameter  : sound_e:  request enum                                                                      *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_CoreFreeReleaseSound(uint8 sound_u8,uint16 soundBit)
{
	/*Set release tbl*/
	ChimeCoreSoundTbl[e_ChimeQueue_Playing][sound_u8] &= ~soundBit;
	/*Clear timer status*/
	Chime_RteAdaptTimerClr(Chime_OStmGetTimer(sound_u8));
	/*Clear timer status*/
}

/**********************************************************************************************************
*Function   : Chime_CoreNextSound                                                                         *
*                                                                                                         *
*Description: Find next sound id with no release                                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : e_SoundTypeList_t  :Sound ID                                                                *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
uint8 Chime_CoreNextSound(void)
{
	uint8 temp_u8;
	for(temp_u8 = (uint8)e_SoundType_IdleMode; temp_u8 < e_SoundType_NoChime;temp_u8 ++)
	{
		/*Find highest priority sound with no release*/
		if(FALSE != (ChimeCoreSoundTbl[e_ChimeQueue_Request][temp_u8] & (~(ChimeCoreSoundTbl[e_ChimeQueue_Playing][temp_u8]))))
		{
			break;
		}
	}
	return (temp_u8);
}

/**********************************************************************************************************
*Function   : Chime_CoreCheckSound                                                                        *
*                                                                                                         *
*Description: Check current sound is  tigger                                                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : e_SoundTypeList_t  :Sound ID                                                                *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
uint16 Chime_CoreCheckSound(uint8 id_u8,e_ChimeQueueTable_t tbl_e)
{
	/*Check current sound is tigger*/
	return ChimeCoreSoundTbl[tbl_e][id_u8];
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

