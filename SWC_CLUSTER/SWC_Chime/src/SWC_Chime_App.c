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
**  Name:               SWC_Chime_App.c
**
**  Description:        Chime logical migration file
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
#include "logger.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Chime_App.h"
#include "SWC_Chime_Queue.h"
#include "SWC_Chime_Cfg.h"
#include "SWC_Chime_Process.h"
#include "SWC_Chime_Adapt.h"


/**********************************************************************************************************
* Parament                                                                                                *
**********************************************************************************************************/
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_CHIME_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Chime_MemMap.h"

static s_ChimeLocalData_t ChimeLocalData_s;

static s_ChimeBackData_t ChimeBackData_s;

static  e_ChimeIPCCommand_t ChimeIPCCommand_s;

static s_ChimeAppParameterData_t ChimeAppParameterData_s[e_SoundType_NumberOfChimes];

#ifdef CHIME_SOUND_REQUEST_TEST
e_ChimeIPCCommand_t  Chime_RequestTestT;

uint8  Chime_RequestTestID;
#endif
#define SWC_CHIME_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_Chime_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_CHIME_START_SEC_CONST_UNSPECIFIED
#include "SWC_Chime_MemMap.h"

static const s_ChimeAudioMap_t ChimeAudioMap_s[e_SoundType_NumberOfChimes] = CHIME_AUDIO_MAP_TABLE;
static const uint16 ChimeSeedTimeMap[e_SoundSeed_All] = CHIME_AUDIO_SEED_MAP_TABLE;

#define SWC_CHIME_STOP_SEC_CONST_UNSPECIFIED
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
#ifdef CHIME_SOUND_REQUEST_TEST
void Chime_RequestTestFun(void)
{
	if(Chime_RequestTestID != Chime_RequestTestT.SoundId_u8)
	{
		Chime_RequestTestT.SoundId_u8 = Chime_RequestTestID;
		if(ChimeAudioMap_s[Chime_RequestTestT.SoundId_u8].Repeats_u16 == 255)
		{
			Chime_RequestTestT.RepeatTime_u32 = 0;
		}
		else
		{
			Chime_RequestTestT.RepeatTime_u32 = ChimeAudioMap_s[Chime_RequestTestT.SoundId_u8].Repeats_u16 * ChimeAudioMap_s[Chime_RequestTestT.SoundId_u8].ReptTime_u16;
		}
		Chime_RequestTestT.Operation_u8 = 2;
		Chime_RequestTestT.Soundtrack = 3;
		Chime_RequestTestT.Toggle_u8 ++;
		NW_SIL_TX_Chime_DATA(Chime_RequestTestT);
	}
}
#endif

/**********************************************************************************************************
*Function   : Chime_KSColdInit                                                                            *
*                                                                                                         *
*Description: Chime cold init interface ,need to call by runable                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_KSColdInit(void)
{
	(void)memset((void*)&ChimeLocalData_s,0,sizeof(s_ChimeLocalData_t));
	(void)memset((void*)&ChimeBackData_s,0,sizeof(s_ChimeBackData_t));
	(void)memset((void*)&ChimeIPCCommand_s,0,sizeof(e_ChimeIPCCommand_t));
	(void)memset((void*)&ChimeAppParameterData_s,0,sizeof(s_ChimeOstmData_t));
	Chime_QueueInit();
	Chime_ProcessColdInit();
	Chime_RteAdaptInit();
}

/**********************************************************************************************************
*Function   : Chime_KSWarmInit                                                                            *
*                                                                                                         *
*Description: Chime warm init interface ,need to call by runable                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_KSWarmInit(void)
{
	Chime_KSColdInit();
}

/**********************************************************************************************************
*Function   : Chime_SpeakSound                                                                            *
*                                                                                                         *
*Description: Chime requirement interface call by app                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_SpeakSound(uint8 soundId_u8,uint16 field)
{
	if(FALSE != Chime_Api_FeadbackCheck())
	{
		/*Set sound status to start*/
		ChimeIPCCommand_s.Operation_u8 = (uint8)e_ChimeOperationStart;
		
		/*Set sound start id*/
		ChimeIPCCommand_s.SoundId_u8 = soundId_u8;
		
		ChimeIPCCommand_s.RepeatTime_u32 = Chime_OStmStart(soundId_u8);
		
		/*tick count Self-increasing,for IPC send compare*/
		ChimeIPCCommand_s.Toggle_u8 ++;
		
		/*Set play sound volume*/
		ChimeIPCCommand_s.Volume_u8 = ChimeLocalData_s.Chime.Vol_u8;

		ChimeIPCCommand_s.Soundtrack = field;
		ChimeLocalData_s.Chime.CurChimeField = field;
		/*Set location playing sound id*/;
		ChimeLocalData_s.Chime.LstId_u8 = ChimeLocalData_s.Chime.CurId_u8;
		
		ChimeLocalData_s.Chime.CurId_u8 = soundId_u8;
		
		/*Set feedback status to request feedback*/
		ChimeLocalData_s.Chime.Sts_u8 = (uint8)e_ChimeCallback_Request;

		/*Set request timeout time,if timer is over,need to clear status*/
		Chime_RteAdaptTimerSet(&ChimeLocalData_s.Timeout,CHIME_REQUEST_TIMEOURTTIME);
		
		NW_SIL_TX_Chime_DATA(ChimeIPCCommand_s);

		/*Clear low priority with no recovery sound*/
		Chime_ClearLowOnce(soundId_u8);

		/*Set current playing status*/
		Chime_CoreRelsPalyingSound(soundId_u8,Chime_CoreCheckSound(soundId_u8,e_ChimeQueue_Request));
	}
}

/**********************************************************************************************************
*Function   : Chime_StopChime                                                                             *
*                                                                                                         *
*Description: Chime stop interface call by app                                                            *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*           : immFlg_bool: stop immediately flag                                                          *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_StopChime(uint8 soundId_u8,boolean immFlg_bool)
{
	if(FALSE != Chime_Api_FeadbackCheck())
	{
		if(ChimeLocalData_s.Chime.CurId_u8 == soundId_u8)
		{
			/*Set location playing sound id*/;
			ChimeLocalData_s.Chime.LstId_u8 = soundId_u8;

			/*Check if stop chime immediately*/
			if(FALSE != immFlg_bool)
			{
				ChimeIPCCommand_s.Operation_u8 = (uint8)e_ChimeOperationStopImm;
			}
			else
			{
				ChimeIPCCommand_s.Operation_u8 = (uint8)e_ChimeOperationStop;
			}
			/*Stop sound id*/
			ChimeIPCCommand_s.SoundId_u8 = soundId_u8;

			/*tick count Self-increasing,for IPC send compare*/
			ChimeIPCCommand_s.Toggle_u8 ++;
			
			ChimeLocalData_s.Chime.Sts_u8 = (uint8)e_ChimeCallback_Request;

			/*Set request timeout time,if timer is over,need to clear status*/
			Chime_RteAdaptTimerSet(&ChimeLocalData_s.Timeout,2*CHIME_REQUEST_TIMEOURTTIME);

			NW_SIL_TX_Chime_DATA(ChimeIPCCommand_s);

		}
	}
}

/**********************************************************************************************************
*Function   : Chime_StopAll                                                                               *
*                                                                                                         *
*Description: Chime stop interface call by app                                                            *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_StopAll(void)
{
	e_ChimeIPCCommand_t command_s = {0};

	command_s.Operation_u8 = (uint8)e_ChimeOperationStopImm;
	
	command_s.SoundId_u8 = 0xFF;
	
	ChimeLocalData_s.Chime.Sts_u8 = (uint8)e_ChimeCallback_Request;

	Chime_RteAdaptTimerSet(&ChimeLocalData_s.Timeout,2*CHIME_REQUEST_TIMEOURTTIME);

	NW_SIL_TX_Chime_DATA(command_s);
}

/**********************************************************************************************************
*Function   : Chime_ReadState                                                                             *
*                                                                                                         *
*Description: Read current SOC audio status                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_ReadState(void)
{
	e_ChimeIPCCommand_t command_s = {0};

	command_s.Operation_u8 = (uint8)e_ChimeOperationRead;

	ChimeLocalData_s.Chime.Sts_u8 = (uint8)e_ChimeCallback_Request;

	Chime_RteAdaptTimerSet(&ChimeLocalData_s.Timeout,CHIME_REQUEST_TIMEOURTTIME);
	
	NW_SIL_TX_Chime_DATA(command_s);
}

/**********************************************************************************************************
*Function   : Chime_Api_SetVolume_Set                                                                     *
*                                                                                                         *
*Description: Set sound volume                                                                            *
*                                                                                                         *
*Parameter  : volume_u8 : volume 0~100%                                                                   *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_SetVolume_Set(uint8 volume_u8)
{
	e_ChimeIPCCommand_t command_s = {0};
	
	command_s.Operation_u8 = (uint8)e_ChimeOperationSetVol;
	
	ChimeLocalData_s.Chime.Vol_u8 = volume_u8;
	
	NW_SIL_TX_Chime_DATA(command_s);
}

/**********************************************************************************************************
*Function   : Chime_Api_FeadbackCheck                                                                     *
*                                                                                                         *
*Description: Check current soc status,if is no chime or current playing ,app can send requirement        *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : boolean   : TRUE feedback ok, FALSE: nedd to feedback                                       *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
boolean Chime_Api_FeadbackCheck(void)
{
	boolean flag_bool = FALSE;
		
	if((ChimeLocalData_s.Chime.Sts_u8 == e_ChimeCallback_NoChime)
	|| (ChimeLocalData_s.Chime.Sts_u8 == e_ChimeCallback_Playing))
	{
		flag_bool = TRUE;
	}
	return flag_bool;
}

/**********************************************************************************************************
*Function   : Chime_Api_RequestProcess_Set                                                                *
*                                                                                                         *
*Description: Chime process requirement interface, requirement once will play once                        *
*                                                                                                         *
*Parameter  : sound_e     :Request id                                                                     *
*                                                                                                         *
*Return     : e_ChimeReturnStatus_t   : Request back status                                               *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
e_ChimeReturnStatus_t Chime_Api_RequestProcess_Set(uint8 sound_u8,uint16 bit)
{
	e_ChimeReturnStatus_t reqStatus_e = e_ChimeInvalidRequest;
	uint8 curid_u8;
	uint8 curPriority;
	uint8 newPriority = ChimeAudioMap_s[sound_u8].Priority_u8;
	/* Only valid chimes AND Diagnostic Mode is off AND no OV_UV condition */
	if(((e_SoundType_NoChime > sound_u8) && (e_SoundType_IdleMode != sound_u8)) && (FALSE == ChimeLocalData_s.Pwr_u8))
	{
		curid_u8 = Chime_IdleTimeOverCheck(sound_u8);
		curPriority = ChimeAudioMap_s[curid_u8].Priority_u8;
		/*Current now,no chime playing*/
		if(curid_u8 == e_SoundType_IdleMode)
		{
			Chime_CoreRequestSound(sound_u8,bit);
			reqStatus_e = e_ChimeNenOk;
		}
		else if(curPriority > newPriority)
		{
			/*Check if the request sound is edge playing*/
			if((FALSE == SOUND_CHECK_ATTRIBUTE(sound_u8,(uint16)SOUND_PLAY_EDGE)) || (FALSE != SOUND_CHECK_ATTRIBUTE(sound_u8,(uint16)SOUND_BREAK_RECOVER)))
			{
				/*add to playing table*/
				Chime_CoreRequestSound(sound_u8,bit);
				reqStatus_e = e_ChimeNenOk;
			}
			/*Check if the request sound is brake immediately and current playing is stop immediately*/
			else if((FALSE != SOUND_CHECK_ATTRIBUTE(curid_u8,(uint16)SOUND_BREAK_BREAKIMM)) && 
					(FALSE != SOUND_CHECK_ATTRIBUTE(sound_u8,(uint16)SOUND_BREAK_STOPIMM)))
			{
				/*add to playing table*/
				Chime_CoreRequestSound(sound_u8,bit);
				//Chime_SpeakSoundNext(sound_e,curId);
				reqStatus_e = e_ChimeNenOk;
			}
			else
			{
				reqStatus_e = e_ChimeNotActive;
			}
		}
		else if(FALSE == Chime_CoreCheckSound(curid_u8,e_ChimeQueue_Request))
		{
			if((FALSE != SOUND_CHECK_ATTRIBUTE(sound_u8,(uint16)SOUND_BREAK_REQUEST_WITH_SOUND)) && (curid_u8 == sound_u8))
			{
				reqStatus_e = e_ChimeCurrentlyPlaying;
			}
			else
			{
				if((FALSE == SOUND_CHECK_ATTRIBUTE(sound_u8,(uint16)SOUND_PLAY_EDGE)) || (FALSE != SOUND_CHECK_ATTRIBUTE(sound_u8,(uint16)SOUND_BREAK_RECOVER)))
				{
					Chime_CoreRequestSound(sound_u8,bit);
					reqStatus_e = e_ChimeNenOk;
				}
			}
		}
		/*Check if requested sound is same as currently playing*/
		else if(curPriority == newPriority)
		{
			/* It is currently playing */
			if(FALSE != SOUND_CHECK_ATTRIBUTE(sound_u8,(uint16)SOUND_BREAK_BREAKSELF))
			{
				Chime_CoreRequestSound(sound_u8,bit);
				reqStatus_e = e_ChimeNenOk;
			}
			else if(FALSE != SOUND_CHECK_ATTRIBUTE(sound_u8,(uint16)SOUND_BREAK_RECOVER))
			{
				//add to play table
				Chime_CoreRequestSound(sound_u8,bit);
				reqStatus_e = e_ChimeNenOk;
			}
			else
			{
				/*check chime is re active*/
				if(FALSE == Chime_CoreCheckSound(curid_u8,e_ChimeQueue_Request))
				{
					Chime_CoreRequestSound(sound_u8,bit);
				}
				reqStatus_e = e_ChimeCurrentlyPlaying;
			}
		}
		/*Check if requested sound is high priority than currently playing*/
		/*requested sound is low priority than currently playing*/
		else
		{
			if(FALSE != SOUND_CHECK_ATTRIBUTE(sound_u8,(uint16)SOUND_BREAK_RECOVER))
			{
				/*add to playing table*/
				Chime_CoreRequestSound(sound_u8,bit);
				reqStatus_e = e_ChimeNenOk;
			}
			else
			{
				reqStatus_e = e_ChimeLowerPriority;
			}
		}
	}
	else
	{
		reqStatus_e = e_ChimeInvalidRequest; 
	}
	return (reqStatus_e);
}

/**********************************************************************************************************
*Function   : Chime_Api_Cancel_Set                                                                        *
*                                                                                                         *
*Description: Chime process cancel interface,                                                             *
*                                                                                                         *
*Parameter  : sound_e     :Request id                                                                     *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_Cancel_Set(uint8 sound_u8)
{
	Chime_CoreCancelSound(sound_u8,0xffff);
}

/**********************************************************************************************************
*Function   : Chime_Api_RequestField_Set                                                                  *
*                                                                                                         *
*Description: Chime field requirement interface                                                           *
*                                                                                                         *
*Parameter  : field     :Request id                                                                       *
*                                                                                                         *
*Return     : e_ChimeReturnStatus_t   : Request back status                                               *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-10-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_RequestField_Set(uint16 Idx_u16,uint16 field)
{
	ChimeAppParameterData_s[Idx_u16].feild_u16 |= field;
}

/**********************************************************************************************************
*Function   : Chime_Api_CancelField_Set                                                                   *
*                                                                                                         *
*Description: Chime field cancel interface                                                                *
*                                                                                                         *
*Parameter  : field     :Request id                                                                       *
*                                                                                                         *
*Return     : e_ChimeReturnStatus_t   : Request back status                                               *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-10-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_CancelField_Set(uint16 Idx_u16,uint16 field)
{
	ChimeAppParameterData_s[Idx_u16].feild_u16 &= ~field;
}

/**********************************************************************************************************
*Function   : Chime_SlowRateTask                                                                          *
*                                                                                                         *
*Description: Chime app slow task,call by ruable,The faster call the better                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_SlowRateTask(void)
{
	uint8 NextSound_u8;
	uint8 curid_u8 =  ChimeLocalData_s.Chime.CurId_u8;
	uint8 curPriority;
	uint8 newPriority;
	uint32 door_time;
	uint32 u32TempData;
#ifdef CHIME_RUNABLE_TIME_TEST
	
	Chime_RteAdaptRunableOstmStart(ChimeOstmTimer3);
#endif

	if((FALSE != Chime_Api_FeadbackCheck()) && (FALSE != Chime_RteChimeSocReady()))
	{
		NextSound_u8 = Chime_CoreNextSound();
		if(e_SoundType_NoChime > NextSound_u8)
		{
			newPriority = ChimeAudioMap_s[NextSound_u8].Priority_u8;
			curPriority = ChimeAudioMap_s[curid_u8].Priority_u8;
			/*Current now ,no sound playing */
			if(e_SoundType_IdleMode == curid_u8)
			{
				if(e_SoundType_IdleMode == Chime_IdleTimeOverCheck(NextSound_u8))
				{
					//The sound bound to the TT is restored after being interrupted by a high priority sound 
					if((FALSE != SOUND_CHECK_ATTRIBUTE(NextSound_u8,(uint16)SOUND_BREAK_REVOVER_WITH_TTFlASH)))
					{
						if(1u ==  chime_api_TTFuc())
						{
							Chime_SpeakSound(NextSound_u8,Chime_GetCurrentSoundField(NextSound_u8));
						}
					}
					else
					{
						/*playing current sound*/
						Chime_SpeakSound(NextSound_u8,Chime_GetCurrentSoundField(NextSound_u8));
					}
				}
			}
			/*New chime is higner priority than current palying*/
			else if(newPriority < curPriority)
			{
				/*Check current playing sound can break by new sound*/
				if(FALSE != SOUND_CHECK_ATTRIBUTE(curid_u8,(uint16)SOUND_BREAK_BREAK))
				{
					if(((FALSE != SOUND_CHECK_ATTRIBUTE(curid_u8,(uint16)SOUND_BREAK_BREAKIMM))
					&& (FALSE != SOUND_CHECK_ATTRIBUTE(NextSound_u8,(uint16)SOUND_BREAK_STOPIMM)))
					|| (FALSE != SOUND_CHECK_ATTRIBUTE(curid_u8,(uint16)SOUND_BREAK_SEED_STOP_IMM)))
					{
						/*Check current playing sound can break by new sound*/
						Chime_StopChime(curid_u8,TRUE);
					}
					else
					{
						/*Check current playing sound can break by new sound*/
						Chime_StopChime(curid_u8,FALSE);
					}
					
				}
				else
				{
					//wait palying over
					if((FALSE == Chime_CoreCheckSound(curid_u8,e_ChimeQueue_Request)) && (FALSE != SOUND_CHECK_ATTRIBUTE(curid_u8,(uint16)SOUND_BREAK_STOP_TIME_CANCEL)))
					{
						Chime_StopChime(curid_u8,SOUND_CHECK_ATTRIBUTE(curid_u8,(uint16)SOUND_BREAK_SEED_STOP_IMM));
					}
				}
			}
			/*Current playing sound is re trigger*/
			else if(newPriority == curPriority)
			{
				/*Check current sound can re playing*/
				if(FALSE != SOUND_CHECK_ATTRIBUTE(curid_u8,(uint16)SOUND_BREAK_BREAKSELF))
				{
					if(e_SoundType_DoorOpen1_5Hz == curid_u8)
					{
						u32TempData = (uint32)(ChimeAudioMap_s[curid_u8].Repeats_u16) * (uint32)(ChimeAudioMap_s[curid_u8].ReptTime_u16);
						//door open just need to start a timer
						door_time = u32TempData + (uint32)(ChimeSeedTimeMap[ChimeAudioMap_s[curid_u8].PlayTyp_e]);
						Chime_CoreRelsPalyingSound(curid_u8,Chime_CoreCheckSound(curid_u8,e_ChimeQueue_Request));
						Chime_RteAdaptTimerSet(&ChimeAppParameterData_s[curid_u8].timer,CHIME_OSTM_TIMER_MAX_COUNTER);
						SWC_ChimeDoorOpenTimerStart(1,0,door_time);
					}
					else
					{
						Chime_StopChime(curid_u8,SOUND_CHECK_ATTRIBUTE(curid_u8,(uint16)SOUND_BREAK_BREAKSELF_IMM));
					}
				}
				else 
				{
					//wait palying over
					if((FALSE == Chime_CoreCheckSound(curid_u8,e_ChimeQueue_Request)) && (FALSE != SOUND_CHECK_ATTRIBUTE(curid_u8,(uint16)SOUND_BREAK_STOP_TIME_CANCEL)))
					{
						Chime_StopChime(curid_u8,SOUND_CHECK_ATTRIBUTE(curid_u8,(uint16)SOUND_BREAK_SEED_STOP_IMM));
					}
				}
			}
			else
			{
				/*New chime is low priority than current palying*/
				/*Check current playing sound is stop*/
				if(FALSE == Chime_CoreCheckSound(curid_u8,e_ChimeQueue_Request))
				{
					/*Judge current palying can stop by signal stop*/
					if((FALSE != SOUND_CHECK_ATTRIBUTE(curid_u8,(uint16)SOUND_BREAK_BREAK)) || (FALSE != SOUND_CHECK_ATTRIBUTE(curid_u8,(uint16)SOUND_BREAK_STOP_TIME_CANCEL)))
					{
						Chime_StopChime(curid_u8,SOUND_CHECK_ATTRIBUTE(curid_u8,(uint16)SOUND_BREAK_SEED_STOP_IMM));
					}
				}
				else
				{
					//wait palying over
				}
			}
		}
		else
		{
			/*No new chime need to play*/
			/*Check current playing sound is stop*/
			if(FALSE == Chime_CoreCheckSound(curid_u8,e_ChimeQueue_Request))
			{
				/*Judge current palying can stop by signal stop*/
				if((FALSE != SOUND_CHECK_ATTRIBUTE(curid_u8,(uint16)SOUND_BREAK_BREAK)) || (FALSE != SOUND_CHECK_ATTRIBUTE(curid_u8,(uint16)SOUND_BREAK_STOP_TIME_CANCEL)))
				{
					Chime_StopChime(curid_u8,SOUND_CHECK_ATTRIBUTE(curid_u8,(uint16)SOUND_BREAK_SEED_STOP_IMM));
				}
			}
			else
			{
				//wait palying over
			}
		}
	}
	else
	{
		//wait feedback
	}
#ifdef CHIME_RUNABLE_TIME_TEST
	Chime_RteAdaptRunableOstmCheck(ChimeOstmTimer3);
	
#endif

}

/**********************************************************************************************************
*Function   : Chime_Api_Callback_Set                                                                      *
*                                                                                                         *
*Description: Chime callback api,call by IPC callback                                                     *
*                                                                                                         *
*Parameter  : data_u8  ：Receive data first address                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_Callback_Set(s_IPCChimeCallback_t data_s)
{
	boolean Pause_bool = FALSE;
	ChimeBackData_s.Chime.Id_u8 = data_s.CurId;
	ChimeBackData_s.Chime.repeat_u8 = data_s.LastRepeat;

	if((ChimeLocalData_s.Chime.Sts_u8 == (uint8)e_ChimeCallback_Request)
	|| (ChimeLocalData_s.Chime.Sts_u8 == (uint8)e_ChimeCallback_Playing))
	{
		/*Callback sound is playing*/
		if(ChimeBackData_s.Chime.Id_u8 == ChimeLocalData_s.Chime.CurId_u8)
		{
			/*Set current status to Playing*/
			ChimeLocalData_s.Chime.Sts_u8 = (uint8)e_ChimeCallback_Playing;
		}
		/*Callback: sound is playing over*/
		else if(((uint8)e_SoundType_IdleMode == ChimeBackData_s.Chime.Id_u8) || (0xff ==ChimeBackData_s.Chime.Id_u8))
		{
			if(ChimeLocalData_s.Chime.LstId_u8 != (uint8)e_SoundType_IdleMode)
			{
				Pause_bool = Chime_OStmPause(ChimeLocalData_s.Chime.LstId_u8,ChimeBackData_s.Chime.repeat_u8);
			}
			/*Clear callback status*/
			ChimeLocalData_s.Chime.Sts_u8 = (uint8)e_ChimeCallback_NoChime;
			if(FALSE == Pause_bool)
			{
				Chime_RteAdaptTimerSet(&ChimeLocalData_s.Chime.delay,ChimeAudioMap_s[ChimeLocalData_s.Chime.CurId_u8].Shield_u16);
				ChimeLocalData_s.Chime.DelayId_u8 = ChimeLocalData_s.Chime.CurId_u8;
				Chime_CoreReleaseSound(ChimeLocalData_s.Chime.CurId_u8);
			}
			/*Release current playing status*/
			Chime_IntervalTimeProcess(ChimeLocalData_s.Chime.CurId_u8);
			/*Clear current playing id*/
			ChimeLocalData_s.Chime.CurId_u8 = (uint8)e_SoundType_IdleMode;
		}
		else
		{
			/*Playing ID is error,stop all sound*/
			Chime_StopAll();
		}
		Chime_RteAdaptTimerClr(&ChimeLocalData_s.Timeout);
		
	}
	else
	{
		if(0xff != ChimeBackData_s.Chime.Id_u8)
		{
			ChimeLocalData_s.Chime.CurId_u8 = ChimeBackData_s.Chime.Id_u8;
			ChimeLocalData_s.Chime.Sts_u8 = (uint8)e_ChimeCallback_Playing;
			Chime_RteAdaptTimerClr(&ChimeAppParameterData_s[ChimeBackData_s.Chime.Id_u8].timer);
			(void)Chime_OStmStart(ChimeLocalData_s.Chime.CurId_u8);
		}
		else
		{
			ChimeLocalData_s.Chime.CurId_u8 =(uint8) e_SoundType_IdleMode;
			ChimeLocalData_s.Chime.Sts_u8 = (uint8)e_ChimeCallback_NoChime;
		}
	}
}
/**********************************************************************************************************
*Function   : Chime_ClearLowOnce                                                                          *
*                                                                                                         *
*Description: when high priority eage sound is playing,clear low eage sound                               *
*                                                                                                         *
*Parameter  : ChimeId_u8  ：Chime id                                                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
uint16 Chime_GetCurrentSoundField(uint8 ChimeId_u8)
{
	uint32 center = Chime_RteAdaptGetLconfig((uint8)ChimeVconfigCENTER_SPEAKKER);
	uint16 position_value = 0;
	position_value = ~((uint16)CHIME_RSDS_POSITION_CENTER);
	if(FALSE != Chime_RteAdaptGetLconfig((uint8)ChimeLconfigAllFieldEnable))
	{
		if(ChimeAppParameterData_s[ChimeId_u8].feild_u16 != CHIME_RSDS_POSITION_ALL)
		{
			if(FALSE == center)
			{
				return (ChimeAppParameterData_s[ChimeId_u8].feild_u16 & position_value);
			}
			else
			{
				return ChimeAppParameterData_s[ChimeId_u8].feild_u16;
			}
		}
		else
		{
			return CHIME_RSDS_POSITION_NULL;
		}
	}
	else
	{
		return CHIME_RSDS_POSITION_NULL;
	}
}

/**********************************************************************************************************
*Function   : Chime_IdleTimeOverCheck                                                                     *
*                                                                                                         *
*Description: check next chime if need to play while idle time                                            *
*                                                                                                         *
*Parameter  : ChimeId_u8  ：Chime id                                                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
uint8 Chime_IdleTimeOverCheck(uint8 NexId)
{
	uint8 exchangeId;
	if((CHIME_OSTM_TIMER_CLEAR == ChimeLocalData_s.Chime.Inteval.Status_u8) || 
	((ChimeAudioMap_s[NexId].Priority_u8 <= ChimeAudioMap_s[ChimeLocalData_s.Chime.IntevalId_u8].Priority_u8)
	&& (FALSE != SOUND_CHECK_ATTRIBUTE(ChimeLocalData_s.Chime.IntevalId_u8,(uint8)SOUND_BREAK_BREAK))
	&& (FALSE != SOUND_CHECK_ATTRIBUTE(ChimeLocalData_s.Chime.IntevalId_u8,(uint8)SOUND_BREAK_BREAKIMM))
	&& (FALSE != SOUND_CHECK_ATTRIBUTE(NexId,(uint8)SOUND_BREAK_STOPIMM))))
	{
		Chime_RteAdaptTimerClr(&ChimeLocalData_s.Chime.Inteval);
		ChimeLocalData_s.Chime.IntevalId_u8 = (uint8)e_SoundType_IdleMode;
		if((CHIME_OSTM_TIMER_CLEAR == ChimeLocalData_s.Chime.delay.Status_u8) || 
			(ChimeAudioMap_s[NexId].Priority_u8 <= ChimeAudioMap_s[ChimeLocalData_s.Chime.DelayId_u8].Priority_u8))
		{
			exchangeId = ChimeLocalData_s.Chime.CurId_u8;
			Chime_RteAdaptTimerClr(&ChimeLocalData_s.Chime.delay);
			ChimeLocalData_s.Chime.DelayId_u8 = (uint8)e_SoundType_IdleMode;
		}
		else
		{
			exchangeId = ChimeLocalData_s.Chime.DelayId_u8;
			
		}
	}
	else
	{
		exchangeId = ChimeLocalData_s.Chime.IntevalId_u8;
	}
	return exchangeId;
}
/**********************************************************************************************************
*Function   : Chime_ClearLowOnce                                                                          *
*                                                                                                         *
*Description: when high priority eage sound is playing,clear low eage sound                               *
*                                                                                                         *
*Parameter  : ChimeId_u8  ：Chime id                                                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_ClearLowOnce(uint8 ChimeId_u8)
{	
	uint8 temp;
	for(temp = (uint8)e_SoundType_IdleMode;temp < (uint8)e_SoundType_NumberOfChimes;temp ++)
	{
		if((FALSE != Chime_CoreCheckSound(temp,e_ChimeQueue_Request)) && (FALSE == SOUND_CHECK_ATTRIBUTE(temp,(uint8)SOUND_BREAK_RECOVER)))
		{
			if(ChimeAudioMap_s[temp].Priority_u8 > ChimeAudioMap_s[ChimeId_u8].Priority_u8)
			{
				Chime_CoreCancelSound(temp,0xffff);
			}
		}
	}
}
/**********************************************************************************************************
*Function   : Chime_GetBreakStatus                                                                        *
*                                                                                                         *
*Description: Get sound attributes of soundid                                                             *
*                                                                                                         *
*Parameter  : id_u8  ：sound id                                                                            *
*           bit_u16  ：bit                                                                                 *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
boolean Chime_GetBreakStatus(uint8 id_u8,uint16 bit_u16)
{
	boolean result;
	result = SOUND_CHECK_ATTRIBUTE(id_u8,bit_u16);
	return result;
}

/**********************************************************************************************************
*Function   : Chime_GetCurrentSound                                                                       *
*                                                                                                         *
*Description: Current playing sound get                                                                   *
*                                                                                                         *
*Parameter  : ChimeId_u8 :chime id                                                                        *
*                                                                                                         *
*Return     : e_SoundTypeList_t : sound id                                                                *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
s_ChimeLocalSound_t Chime_GetCurrentSoundSts(void)
{
	return (ChimeLocalData_s.Chime);
}

/**********************************************************************************************************
*Chime app timer                                                                                          *
*                                                                                                         *
**********************************************************************************************************/
/**********************************************************************************************************
*Function   : Chime_IntervalTimeProcess                                                                   *
*                                                                                                         *
*Description: Interval time process                                                                       *
*                                                                                                         *
*Parameter  : id_u8 :chime id                                                                             *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_IntervalTimeProcess(uint8 id_u8)
{
	//Cancel idle time,check in SOC Chime server
	uint16 passtime = 0;
	#if 0
	if(e_SoundFreq_0HZ != ChimeAudioMap_s[id_u8].Freq_e)
	{
		if(ChimeAudioMap_s[id_u8].ReptTime_u16 > ChimeSeedTimeMap[ChimeAudioMap_s[id_u8].PlayTyp_e])
		{
			passtime = ChimeAudioMap_s[id_u8].ReptTime_u16 - (uint16)ChimeSeedTimeMap[ChimeAudioMap_s[id_u8].PlayTyp_e];
		}
		else
		{
			passtime = 0;
		}
	}
	#endif
	passtime = 0;
	ChimeLocalData_s.Chime.IntevalId_u8 = id_u8;
	Chime_RteAdaptTimerSet(&ChimeLocalData_s.Chime.Inteval,passtime);

}

/**********************************************************************************************************
*Function   : Chime_HandleRepeats                                                                         *
*                                                                                                         *
*Description: Chime timer tick subtraction process                                                        *
*                                                                                                         *
*Parameter  : passtime  ：time passing counter,base on OSTM counter or task cycle                          *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_HandleRepeats(uint32 passtime)
{
	uint8 temp;
	for(temp = (uint8)e_SoundType_IdleMode;temp < (uint8)e_SoundType_NoChime;temp ++)
	{
		if((FALSE == SOUND_CHECK_ATTRIBUTE(temp,(uint8)SOUND_BREAK_RECOVER_PENDING)) && (FALSE != SOUND_CHECK_ATTRIBUTE(temp,(uint8)SOUND_BREAK_RECOVER)))
		{
			/*Check each timer status*/
			if(CHIME_OSTM_TIMER_OVER == Chime_RteAdaptTimerPass(&ChimeAppParameterData_s[temp].timer,passtime))
			{
				ChimeAppParameterData_s[temp].repeat_u16 = 0;
				/*if timer is over,clear backstage sound*/
				Chime_CoreReleaseSound(temp);
				Chime_RteAdaptTimerClr(&ChimeAppParameterData_s[temp].timer);
			}
		}
	}
	if(CHIME_OSTM_TIMER_OVER == Chime_RteAdaptTimerPass(&ChimeLocalData_s.Chime.delay,passtime))
	{
		Chime_RteAdaptTimerClr(&ChimeLocalData_s.Chime.delay);
	}
	if(CHIME_OSTM_TIMER_OVER == Chime_RteAdaptTimerPass(&ChimeLocalData_s.Chime.Inteval,passtime))
	{
		Chime_RteAdaptTimerClr(&ChimeLocalData_s.Chime.Inteval);
	}
	if(CHIME_OSTM_TIMER_OVER == Chime_RteAdaptTimerPass(&ChimeLocalData_s.Timeout,passtime))
	{
		(void)SWC_CHIME_ERROR_LOG("Audio callback timeout status = %d",ChimeLocalData_s.Chime.Sts_u8);
		ChimeLocalData_s.Chime.Sts_u8 = (uint8)e_ChimeCallback_NoChime;
		Chime_CoreClrPalyingSound(ChimeLocalData_s.Chime.CurId_u8,0xffff);
		ChimeLocalData_s.Chime.CurId_u8 = (uint8)e_SoundType_IdleMode;
		Chime_RteAdaptTimerClr(&ChimeLocalData_s.Timeout);
	}
}

/**********************************************************************************************************
*Function   : Chime_OStmStart                                                                             *
*                                                                                                         *
*Description: Chime timer start function,call by sound start playing                                      *
*                                                                                                         *
*Parameter  : ChimeId_u8  ：sound id                                                                       *
*                                                                                                         *
*Return     : uint16 : Repeat times                                                                       *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
uint32 Chime_OStmStart(uint8 ChimeId_u8)
{
	uint32 straTtime;
	uint32 Intertime;
	uint32 TempTime;
	s_ChimeAppParameterData_t *timePtr;
	timePtr = &ChimeAppParameterData_s[ChimeId_u8];
	
	switch(timePtr->timer.Status_u8)
	{
		case CHIME_OSTM_TIMER_CLEAR:
		{
			if(ChimeAudioMap_s[ChimeId_u8].Repeats_u16 != 0xff)
			{
				timePtr->repeat_u16 = ChimeAudioMap_s[ChimeId_u8].Repeats_u16;
				straTtime = (uint32)timePtr->repeat_u16 * ChimeAudioMap_s[ChimeId_u8].ReptTime_u16;
			}
			else
			{
				timePtr->repeat_u16 = 0;
				straTtime = CHIME_OSTM_TIMER_MAX_COUNTER;
			}
			Intertime = straTtime;
			if((FALSE != SOUND_CHECK_ATTRIBUTE(ChimeId_u8,(uint8)SOUND_BREAK_RECOVER)) && (FALSE == SOUND_CHECK_ATTRIBUTE(ChimeId_u8,(uint8)SOUND_BREAK_RECOVER_PENDING)))
			{
				if(timePtr->repeat_u16 != 0)
				{
					TempTime = ((uint32)(timePtr->repeat_u16) - 1U) * (uint32)(ChimeAudioMap_s[ChimeId_u8].ReptTime_u16);
					Intertime = TempTime + (uint32) ChimeSeedTimeMap[ChimeAudioMap_s[ChimeId_u8].PlayTyp_e];
					//Intertime = (uint32)((timePtr->repeat_u16 - 1) * ChimeAudioMap_s[ChimeId_u8].ReptTime_u16 + ChimeSeedTimeMap[ChimeAudioMap_s[ChimeId_u8].PlayTyp_e]);
				}
			}
			if(e_SoundType_DoorOpen1_5Hz == ChimeId_u8)
			{
				SWC_ChimeDoorOpenTimerStart(1,0,Intertime);
				straTtime = CHIME_OSTM_TIMER_MAX_COUNTER;
				Intertime = straTtime;
			}
			Chime_RteAdaptTimerSet(&timePtr->timer,Intertime);
			straTtime = timePtr->repeat_u16;
			break;
		}
		case CHIME_OSTM_TIMER_RUNING:
		case CHIME_OSTM_TIMER_PENNDING:
		{
			if(ChimeAudioMap_s[ChimeId_u8].Repeats_u16 != 0xff)
			{
				if((timePtr->timer.TimerTick_u32 % ChimeAudioMap_s[ChimeId_u8].ReptTime_u16) > 0)
				{
					timePtr->repeat_u16 = (uint16)(timePtr->timer.TimerTick_u32 / (uint32)(ChimeAudioMap_s[ChimeId_u8].ReptTime_u16)) + 1u;
				}
				else
				{
					timePtr->repeat_u16 = (uint16)(timePtr->timer.TimerTick_u32 / (uint32)(ChimeAudioMap_s[ChimeId_u8].ReptTime_u16));
				}
				straTtime = (uint32)timePtr->repeat_u16 * ChimeAudioMap_s[ChimeId_u8].ReptTime_u16;
			}
			else
			{
				timePtr->repeat_u16 = 0;
				straTtime = CHIME_OSTM_TIMER_MAX_COUNTER;
			}
			Intertime = straTtime;
			if((FALSE != SOUND_CHECK_ATTRIBUTE(ChimeId_u8,(uint8)SOUND_BREAK_RECOVER)) && (FALSE == SOUND_CHECK_ATTRIBUTE(ChimeId_u8,(uint8)SOUND_BREAK_RECOVER_PENDING)))
			{
				if(timePtr->repeat_u16 != 0)
				{
					Intertime = (((uint32)timePtr->repeat_u16 - 1) * ChimeAudioMap_s[ChimeId_u8].ReptTime_u16) + ChimeSeedTimeMap[ChimeAudioMap_s[ChimeId_u8].PlayTyp_e];
				}
			}
			if(e_SoundType_DoorOpen1_5Hz == ChimeId_u8)
			{
				SWC_ChimeDoorOpenTimerStart(1,0,Intertime);
				straTtime = CHIME_OSTM_TIMER_MAX_COUNTER;
				Intertime = straTtime;
			}
			Chime_RteAdaptTimerSet(&timePtr->timer,Intertime);
			straTtime = timePtr->repeat_u16;
			break;
		}
		default:
		{
			straTtime = ChimeAudioMap_s[ChimeId_u8].ReptTime_u16;
			straTtime = timePtr->repeat_u16;
			break;
		}
	}
	if(CHIME_OSTM_TIMER_MAX_COUNTER == straTtime)
	{
		straTtime = 0;
	}
	return straTtime;
}

/**********************************************************************************************************
*Function   : Chime_OStmCheck                                                                             *
*                                                                                                         *
*Description: Chime timer check function,call by task function                                            *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_OStmCheck(void)
{
	uint32 passTime = 0;
	uint32 baseTime,deltime;
	baseTime = ChimeLocalData_s.OstmCnt_u32;
	if(RTE_E_Os_Service_E_OK != Rte_Call_Os_Service_GetElapsedValue(&baseTime,&passTime))
	{
	
	}
	else 
	{
		if(FALSE == ChimeLocalData_s.OstmCntStart_u8)
		{
			ChimeLocalData_s.OstmCnt_u32 = baseTime;
			ChimeLocalData_s.OstmCntOld_u32 = baseTime;
			ChimeLocalData_s.OstmCntStart_u8 = 1U;
		}
		else
		{
			deltime = passTime - ChimeLocalData_s.OstmCntOld_u32;
			ChimeLocalData_s.OstmCntOld_u32 = passTime;
			Chime_HandleRepeats(deltime);
			SWC_ChimeProcessTimerCheck(deltime);
		}
	}
}

/**********************************************************************************************************
*Function   : Chime_OStmPause                                                                             *
*                                                                                                         *
*Description: Chime timer pause function,call by sound break by higher priority sound                     *
*                                                                                                         *
*Parameter  : ChimeId_u8 :current playing chime id                                                        *
*             immFlg_bool:break immediately flag                                                          *
*Return     : e_ChimeOperationStatus_t : break status                                                     *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
boolean Chime_OStmPause(uint8 ChimeId_u8,uint8 Repeat_u8)
{
	boolean Pause_bool = FALSE;
	s_ChimeAppParameterData_t *timePtr;
	timePtr = &ChimeAppParameterData_s[ChimeId_u8];
	
	if((Repeat_u8 < timePtr->repeat_u16) || (ChimeAudioMap_s[ChimeId_u8].Repeats_u16 == 0xff))
	{
		if(FALSE != SOUND_CHECK_ATTRIBUTE(ChimeId_u8,(uint16)SOUND_BREAK_RECOVER))
		{
			if(FALSE != SOUND_CHECK_ATTRIBUTE(ChimeId_u8,(uint16)SOUND_BREAK_RECOVER_PENDING))
			{
				if(ChimeAudioMap_s[ChimeId_u8].Repeats_u16 == 0xff)
				{
					timePtr->repeat_u16 = 0;
					timePtr->timer.TimerTick_u32 = CHIME_OSTM_TIMER_MAX_COUNTER;
				}
				else
				{
					timePtr->repeat_u16 -= Repeat_u8;
					timePtr->timer.TimerTick_u32 = (uint32)timePtr->repeat_u16 * ChimeAudioMap_s[ChimeId_u8].ReptTime_u16;
				}
				Chime_RteAdaptTimerPending(&timePtr->timer);
			}
			else
			{
				if(ChimeAudioMap_s[ChimeId_u8].Repeats_u16 == 0xff)
				{
					timePtr->repeat_u16 = 0;
					timePtr->timer.TimerTick_u32 = CHIME_OSTM_TIMER_MAX_COUNTER;
				}
				Chime_CorePendingSound(ChimeId_u8,Chime_CoreCheckSound(ChimeId_u8,e_ChimeQueue_Playing));
			}
			Chime_CoreClrPalyingSound(ChimeId_u8,0xffff);
			Pause_bool = TRUE;
		}
		else
		{
			Chime_CoreReleaseSound(ChimeId_u8);
		}
	}
	else
	{
		Chime_CoreReleaseSound(ChimeId_u8);
	}
	return Pause_bool;
}
/**********************************************************************************************************
*Function   : Chime_OStmPause                                                                             *
*                                                                                                         *
*Description: Chime timer pause function,call by sound break by higher priority sound                     *
*                                                                                                         *
*Parameter  : Id_u8 :Timer id                                                                             *
*                                                                                                         *
*Return     : s_ChimeOstmData_t : Timer ptr                                                               *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
s_ChimeOstmData_t *Chime_OStmGetTimer(uint8 Id_u8)
{
	return (&ChimeAppParameterData_s[Id_u8].timer);
}

/**********************************************************************************************************
*Function   : Chime_AudioConfigGet                                                                        *
*                                                                                                         *
*Description: Chime config get function                                                                   *
*                                                                                                         *
*Parameter  : Id_u8 :chime id                                                                             *
*                                                                                                         *
*Return     : s_ChimeAudioMap_t : configuration ptr                                                       *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-21                                                                                  *
**********************************************************************************************************/
s_ChimeAudioMap_t Chime_AudioConfigGet(uint8 Id_u8)
{
	return (ChimeAudioMap_s[Id_u8]);
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
**  Date    :      2020/08/10     Original Version
**
**********************************************************************************************************/

/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/

