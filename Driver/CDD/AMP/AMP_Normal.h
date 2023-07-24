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
 * @file:      AMP_Normal.h
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

#ifndef __AMP_NORMAL_H
#define __AMP_NORMAL_H

#include "IPC_Audio.h"
#include "AMP_cfg.h"


typedef struct
{
    boolean IPCSend;
    uint8 ChannelClip[4];
}s_AMPClipResult_Type;


#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"

extern s_AMPClipResult_Type AMPClipResult[DEVICE_NUM];

extern void AMP_NormalInit(uint8 dev_id);
extern Std_ReturnType AMP_NormalMain(uint8 dev_id);
extern Std_ReturnType AMPNormalBuf_Insert(uint8 dev_id, uint8 data);
extern void AMPClipParSet(IPC_S2M_AudioAMPGWMTest_t *par);
extern void AMPGetClipResult(s_AMPClipResult_Type *Data, uint8 dev_id);
extern void AMP_NormalMainLogic(uint8 dev_id);


#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"


#endif

