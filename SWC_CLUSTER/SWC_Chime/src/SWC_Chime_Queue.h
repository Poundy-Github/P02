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
**  Name:               SWC_Chime_Queue.h
**
**  Description:        SWC chime queue message set and get interface
**
**  Organization:       
**
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef SWC_CHIME_QUEUE_H
#define SWC_CHIME_QUEUE_H

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Chime_Interface.h"

/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/
/**********************************************************************************************************
* Parament                                                                                                *
**********************************************************************************************************/
typedef enum
{
	e_ChimeQueue_Start = -1,
	e_ChimeQueue_Request,
	e_ChimeQueue_Playing,
	//e_ChimeQueue_FirstDisplay,
	//e_ChimeQueue_Release,
	e_ChimeQueue_Pending,
	e_ChimeQueue_ALl,
}e_ChimeQueueTable_t;
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
void Chime_QueueInit(void);

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
void Chime_CoreRequestSound(uint8 sound_u8,uint16 soundBit);

/**********************************************************************************************************
*Function   : Chime_CorePendingSound                                                                      *
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
void Chime_CorePendingSound(uint8 sound_u8,uint16 soundBit);

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
void Chime_CoreCancelSound(uint8 sound_u8,uint16 soundBit);

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
void Chime_CorePendingSound(uint8 sound_u8,uint16 soundBit);
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
void Chime_CoreRelsPalyingSound(uint8 sound_u8,uint16 soundBit);

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
void Chime_CoreClrPalyingSound(uint8 sound_u8,uint16 soundBit);

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
void Chime_CoreRlsRequestSound(uint8 sound_u8,uint16 soundBit);

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
void Chime_CoreReleaseSound(uint8 sound_u8);

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
void Chime_CoreFreeReleaseSound(uint8 sound_u8,uint16 soundBit);

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
uint8 Chime_CoreNextSound(void);

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
uint16 Chime_CoreCheckSound(uint8 id_u8,e_ChimeQueueTable_t tbl_e);

#define SWC_CHIME_STOP_SEC_CODE
#include "SWC_Chime_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

#endif

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

