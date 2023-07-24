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
 * @file:      AMP_StartUp.h
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

#ifndef AMP_STARTUP_H
#define AMP_STARTUP_H



#include "AMP_Cfg.h"

#define AMPTIMER_PINENABLEWAIT                                           (1500)/*150ms*/
#define AMPTIMER_BOOTENABLEWAIT                                          (200)/*20ms*/
#define AMPTIMER_CHANNELENABLE_WAIT                                      (1000)/*100ms*/
#define AMPTIMER_SETDIAGWAIT                                             (3000)/*300ms*/
#define AMP8532_START_RETRY_COUNTER    		    (3u)

#define AMP853X_HWVERSIONMajor_N2       		(0x02u)
#define AMP853X_HWVERSIONMajor_N3       		(0x03u)


typedef enum
{
    SCLK_Wait_Connect_Clock = 0u,
    SCLK_Wait_Check,
    SCLK_Wait_Done,
    SCLK_Wait_Err,
}Startup_SCLK_Wait_t;



typedef uint8 AMP_ID_INFOR_t[6];



#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"

extern void AMP_StartUpInit(uint8 dev_id);
extern boolean Get_AMP_Infor(uint8 amp_id, AMP_ID_INFOR_t * ptr);
extern uint8 Get_AMP_HWVer(uint8 dev_id);
extern void AMP_StartupMainLogic(uint8 dev_id);

#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"

#endif
