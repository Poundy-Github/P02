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
 * @file:      AMP_ShutDown.h
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

#ifndef AMP_SHUTDOWN_H
#define AMP_SHUTDOWN_H


#include "Std_Types.h"



#define AMPTIMER_CHANNELDIASBLE                                             (1500)/*150ms*/
#define AMPSHUTDOWN_RETRYMAX                                                (3u)


typedef enum
{
    Shutdown_SW_Mute = 0,
    Shutdown_Channel_Disable,
    Shutdown_DisalbeClock,
    Shutdown_Err,
    Shutdown_Done,
}Shutdown_State_t;


#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"


extern void AMP_ShutDownInit(void);
extern void AMP_Emergency_Shutdown(void);
extern void PowerCtrl_AMPShutDown(void);
extern Std_ReturnType AMP_ShutDownMainLogic(uint8 dev_id);
extern void AMP_EmergencyShutdownOneDevice(uint8 dev_id);


#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"


#endif
