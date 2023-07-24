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

#ifndef SWC_CHIME_TEST_H
#define SWC_CHIME_TEST_H

#include "Compiler.h"
#include "Platform_Types.h"
#include "string.h"
#include "SWC_Chime_App.h"

#define SWC_CHIME_START_SEC_CODE
#include "SWC_Chime_MemMap.h"

void ChimeTestMain(void);
#if 0
void ChimeTestCallback(e_ChimeIPCCommand_t in);

void ChimeTestStartSound(e_ChimeIPCCommand_t in);

void ChimeTestStartImmediately(e_ChimeIPCCommand_t in);

void ChimeTestStopSound(e_ChimeIPCCommand_t in);

void ChimeTestStopImmediatel(e_ChimeIPCCommand_t in);

void ChimeTestRead(e_ChimeIPCCommand_t in);

void ChimeTestSetVolume(e_ChimeIPCCommand_t in);
#endif
void Chime_RteTestOstmStart(void);

uint32 Chime_RteTestOstmCheck(void);

void Chime_RteTestOstmStop(void);

#define SWC_CHIME_STOP_SEC_CODE
#include "SWC_Chime_MemMap.h"

#endif
